#! /usr/bin/env python

import os
import re
from functools import partial
from jinja2 import Environment, FileSystemLoader
env = Environment(loader=FileSystemLoader(["generator/templates", "generator/templates-bases"]), autoescape=False, trim_blocks=True, line_statement_prefix="##")


MAX_LENGTH_B = 512
MAX_LENGTH = MAX_LENGTH_B / 8
MAX_LENGTH_DWORD = MAX_LENGTH / 4

class Type:
  def __init__(self, suffix, underlying_type, size, form):
    self.suffix = suffix
    self.underlying_type = underlying_type
    self.size = size
    self.int_type = self
    self.float_type = self
    self.dword_type = self
    self.qword_type = self
    self.form = form

  def union_name(self, i = 1):
    return "union __v" + str(i) + self.suffix

  def struct_name(self, i = 1):
    return "struct __v" + str(i) + self.suffix

  def intern_name(self, i = 1):
    if i is 1:
      return self.union_name(i)
    return self.struct_name(i)

  def name(self, i = 1):
    return "v" + str(i) + self.suffix

  def mask(self, i =  1):
    return "m" + str(i) + self.suffix

  def permutation_type(self, i = 1):
    a = {1: 8, 2: 8, 4: 8, 8: 32, 16: 64 }
    return "uint" + str(a.get(i, 64)) + "_t"

  def is_int(self):
    return self.int_type is self

  def is_float(self):
    return self.float_type is self

  def is_dword(self):
    return self.size is 4

  def is_qword(self):
    return self.size is 8

  def is_valid(self, i = 1):
    return self.size > 0 and MAX_LENGTH / self.size >= i and i > 0

INT    = Type("i", "int32_t", 4, "%i")
LONG   = Type("l", "int64_t", 8, "%lli")
FLOAT  = Type("f", "float",   4, "%f")
DOUBLE = Type("d", "double",  8, "%lf")
VOID   = Type("",  "", 0, "")

INT.float_type  = FLOAT
LONG.float_type = DOUBLE
FLOAT.int_type  = INT
DOUBLE.int_type = LONG

INT.qword_type = LONG
LONG.dword_type = INT
FLOAT.qword_type = DOUBLE
DOUBLE.dword_type = FLOAT

TYPES    = [DOUBLE, FLOAT, INT, LONG]
INTEGERS = [ t for t in TYPES if t.is_int()   ]
FLOATS   = [ t for t in TYPES if t.is_float() ]
DWORDS   = [ t for t in TYPES if t.is_dword() ]
QWORDS   = [ t for t in TYPES if t.is_qword() ]

def generate_powers(p = 1):
  a = []
  while p <= MAX_LENGTH_DWORD:
    a.append(p)
    p = p << 1
  return a

def ln2(i):
  n = 0
  while i > 1:
    n += 1
    i = i / 2
  return n

SIZES = generate_powers()

def recursive_sizes(i = 1):
  return [ p for p in SIZES if p > i ]

type_pattern = re.compile(r"""
  %(?P<regular>                                   # regular pattern
    (?:  (?P<second_size> \' )                    # second size
      |  (?P<complement> \^ ) )?                  # complementary size
    (?:(?P<plus>  \++  ) | (?P<minus>  \-+  )     # additional plus or minus
      | (?P<fixed>  \d+  )  )?                    # Fixed size
    (?P<type_modifier>  [if]  )?                  # type modifier
    (?:  x  (?P<size_modifier>  32 | 64  ))?      # size modifier
    (?P<pattern>[mMtpPTIN])                      # pattern: Mask, underlying type, letter, Prefix, Type name, Intern type, Size
    (?P<second_type>\')?                          # second type
  ) | %(?P<loop>                                  # loop pattern
    \$\$                                          # delimiter
      (?:(?P<from> [^:$]+ )\:)?(?P<to> [^:$]+ )   # bounds
    \$                                            # delimiter
      (?P<body>  [^$]+  )                         # pattern
    (?: \$                                        # delimiter
      (?P<join>  [^$]+  )                         # join pattern
    )?                                            # end of join pattern
    \$\$                                          # delimiter
  ) | %(?:
    \$\$ (?P<condition> [^$]+ ) \$\$              # condition
  )
""", re.VERBOSE)
re_n = re.compile(r"%n")
def expand_type_pattern(_input, type1 = None, size1 = 1, type2 = None, size2 = None, force = 0):
  expand_first = True
  global type_pattern
  def callback(m, type1, i, type2, j, force):
    expand_first = type1 is not None or type2 is None
    global type_pattern
    global re_n
    s = ""
    regular, loop, condition = m.group("regular", "loop", "condition")
    if regular is not None:
      second_size, second_type, compl, plus, minus, fixed, type_modifier, size_modifier, pattern = m.group("second_size", "second_type", "complement", "plus", "minus", "fixed", "type_modifier", "size_modifier", "pattern")
      if second_size is not None:
        i = j
      if second_type is not None:
        type1 = type2
      if compl is not None:
        if i is not None and j is not None:
          i /= j
        else:
          i = None
      if i is None:
        i = 0
      if type1 is None:
        type1 = VOID
      """ Increase or decrease i """
      if plus is not None:
        i = i << len(plus)
      if minus is not None:
        i = i >> len(minus)
      if fixed is not None:
        i = int(fixed)

      if not expand_first:
        if second_size is not None and second_type is None:
          return "".join(["%", str(i), type_modifier or "", size_modifier or "", pattern])
        if second_type is not None and second_size is None:
          return "".join(["%", plus or "", minus or "", fixed or "", type2.is_int() and "i" or "f", type2.is_dword() and "x32" or "x64", pattern])
        if second_type is None and second_size is None:
          return m.group(0)
      """ Apply type modifier """
      if type_modifier == 'i':
        type1 = type1.int_type
      if type_modifier == 'f':
        type1 = type1.float_type
      if size_modifier == "x32":
        type1 = type1.dword_type
      if size_modifier == "x64":
        type1 = type1.qword_type

      """ Pattern matching """
      if pattern == 'm':
        return type1.permutation_type(i)
      if pattern == 'M':
        return type1.mask(i)
      if pattern == 't':
        return type1.underlying_type
      if pattern == 'p':
        return type1.suffix
      if pattern == 'P':
        return type1.name(i)
      if (pattern == 'T' and force >= 0) or (pattern == 'I' and force > 0):
        return type1.name(i)
      if (pattern == 'I' and force <= 0) or (pattern == 'T' and force < 0):
        return type1.intern_name(i)
      if pattern == 'N':
        return str(i)
    elif loop is not None:
      fromb, tob, body, joinstr = m.group("from", "to", "body", "join")
      joinstr = type_pattern.sub(partial(callback, type1 = type1, i = i, type2 = type2, j = j, force = force), joinstr or "")
      fromb   = type_pattern.sub(partial(callback, type1 = type1, i = i, type2 = type2, j = j, force = force), fromb or "")
      tob     = type_pattern.sub(partial(callback, type1 = type1, i = i, type2 = type2, j = j, force = force), tob)
      if not expand_first:
        body    = type_pattern.sub(partial(callback, type1 = type1, i = i, type2 = type2, j = j, force = force), body)
        return "".join(["%$$", fromb or "", fromb and ":" or "", tob, "$", body, joinstr and "$" or "", joinstr or "", "$$"])

      incr = 1
      b = eval(tob,   {"ln2" : ln2}, {"type1": type1, "type2": type2});
      if fromb is None or fromb is "":
        a = b
        b += 1
      else:
        a = eval(fromb, {"ln2" : ln2}, {"type1": type1, "type2": type2});
      if a > b:
        a -= 1
        b -= 1
        incr = -1
      r = range(a, b, incr)
      return joinstr.join([type_pattern.sub(partial(callback, type1 = type1, i = i, type2 = type2, j = j, force = force), re_n.sub(str(k), body)) for k in r])
    elif condition is not None:
      if not expand_first:
        condition = type_pattern.sub(partial(callback, type1 = type1, i = i, type2 = type2, j = j, force = force), condition)
        return "".join(["%$$", condition, "$$"])
      return ""
    return m.group(0)

  s =type_pattern.sub(partial(callback, type1 = type1, i = size1, type2 = type2, j = size2, force = force), _input)
  return s
def is_valid_type_pattern(_input, type1 = None, size1 = 1, type2 = None, size2 = None):
  global type_pattern
  for m in type_pattern.finditer(_input):
    t = type1
    k = size1
    regular, loop, condition = m.group("regular", "loop", "condition")
    if regular is not None:
      second_size, second_type, compl, plus, minus, fixed, type_modifier, size_modifier, pattern = m.group("second_size", "second_type", "complement", "plus", "minus", "fixed", "type_modifier", "size_modifier", "pattern")
      if compl is not None:
        if size1 is not None and size2 is not None:
          k = size1 / size2
        else:
          i = None
      if second_size is not None:
        k = size2
      if second_type is not None:
        t = type2
      if k is None:
        k = 0
      if t is None:
        t = VOID
      """ Increase or decrease i """
      if plus is not None:
        k = k << len(plus)
      if minus is not None:
        k = k >> len(minus)
      if fixed is not None:
        k = int(fixed)

      """ Apply type modifier """
      if type_modifier is 'i':
        t = t.int_type
      if type_modifier is 'f':
        t = t.float_type
      if size_modifier is "x32":
        t = t.dword_type
      if size_modifier is "x64":
        t = t.qword_type

      if pattern in ["M", "P", "T", "I"]:
        if not t.is_valid(k):
          return False
      if pattern in ["m", "N"]:
        if k not in SIZES:
          return False
    elif loop is not None:
      fromb, tob, body, joinstr = m.group("from", "to", "body", "join")
      if not is_valid_type_pattern(" ".join([fromb or "", tob, body, joinstr or ""]), type1 = type1, size1 = size1, type2 = type2, size2 = size2):
        return False
    elif condition is not None:
      if not is_valid_type_pattern(condition, type1 = type1, size1 = size1, type2 = type2, size2 = size2):
        return False
      condition = expand_type_pattern(condition, type1 = type1, size1 = size1, type2 = type2, size2 = size2)
      if not eval(condition):
        return False
  return True


args_name = re.compile(r"(?P<space>\s?)(?P<type>[^,$]*[^\w%$])\b(?P<name>[a-zA-Z_][\w%]*)(?=$|,|\$)")
def remove_args_type(s):
  return args_name.sub(lambda m: m.group("name"), s)

def recursive_args(s, hilo):
  def callback(match, hilo):
    arg_type = match.group("type").strip()
    arg_name = match.group("name")
    space = match.group("space") or ""
    m = type_pattern.match(arg_type)
    if m is None:
      return space + arg_name
    second_size, second_type, compl, plus, minus, fixed, type_modifier, size_modifier, pattern = m.group("second_size", "second_type", "complement", "plus", "minus", "fixed", "type_modifier", "size_modifier", "pattern")
    if pattern is None:
      return space + arg_name
    sign = "-"
    if len(plus or "") > 0:
      sign = "+" * (len(plus)-1)
    elif minus is not None:
      sign = "-" * (len(minus)+1)
    elif fixed is not None:
      sign = str(int(fixed) >> 1)
    prefix = "".join(["%", second_size or "", compl or "", plus or "", minus or "", fixed or "", type_modifier or "", size_modifier or ""])
    suffix = second_type or ""
    lowprefix = "".join(["%", second_size or "", compl or "", sign, type_modifier or "", size_modifier or ""])
    if pattern == 'T':
      return "".join([space, lowprefix, "P", suffix, "_get_", hilo, "_", prefix, "P", suffix, "(", arg_name, ")"])
    if pattern == 'M':
      return "".join([space, lowprefix, "M", suffix, "_get_", hilo, "_", prefix, "M", suffix, "(", arg_name, ")"])
    return space + arg_name
  return args_name.sub(partial(callback, hilo = hilo), s)

def smaller(s):
  def callback(m):
    second_size, second_type, compl, plus, minus, fixed, type_modifier, size_modifier, pattern = m.group("second_size", "second_type", "complement", "plus", "minus", "fixed", "type_modifier", "size_modifier", "pattern")
    if pattern is None:
      return m.group(0)
    sign = "-"
    if len(plus or "") > 0:
      sign = "+" * (len(plus)-1)
    elif minus is not None:
      sign = "-" * (len(minus)+1)
    elif fixed is not None:
      sign = str(int(fixed) >> 1)
    return "".join(["%", second_size or "", compl or "", sign, type_modifier or "", size_modifier or "", pattern, second_type or ""])
  return type_pattern.sub(callback, s)

def filter_force(s, force = 0):
  if force == 0:
    return s
  def callback(m, force):
    second_size, second_type, compl, plus, minus, fixed, type_modifier, size_modifier, pattern = m.group("second_size", "second_type", "complement", "plus", "minus", "fixed", "type_modifier", "size_modifier", "pattern")
    if pattern is None:
      return m.group(0)
    if force < 0 and pattern == "T":
      pattern = "I"
    elif force > 0 and pattern == "I":
      pattern = "T"
    return "".join(["%", second_size or "", compl or "", plus or "", minus or "", fixed or "", type_modifier or "", size_modifier or "", pattern, second_type or ""])

  return type_pattern.sub(partial(callback, force = force), s)
    


def expand_filter(s, sizes, types, force = 0):
  type1 = None
  type2 = None
  if len(types) > 0:
    type1 = types[-1]
    type2 = types[0]
  size1 = None
  size2 = None
  if len(sizes) > 0:
    size1 = sizes[-1]
    size2 = sizes[0]
  return expand_type_pattern(s, type1 = type1, size1 = size1, type2 = type2, size2 = size2, force = force)

def expand_valid(s, sizes, types):
  type1 = None
  type2 = None
  if len(types) > 0:
    type1 = types[-1]
    type2 = types[0]
  size1 = None
  size2 = None
  if len(sizes) > 0:
    size1 = sizes[-1]
    size2 = sizes[0]
  return is_valid_type_pattern(s, type1 = type1, size1 = size1, type2 = type2, size2 = size2)

def macro_filter(s):
  lines = [line for line in s.split("\n") if line.strip() != ""]
  return " \\\n".join(lines) + "\n"


class Func:
  def __init__(self, rettype, name, args, prefix = "__"):
    self._rettype = rettype or ""
    self._name = name or ""
    self._args = args or ""
    self._prefix = prefix or "__"
  def ret(self):
    return self._rettype
  def name(self):
    return self._name
  def pname(self):
    return self._prefix + self._name
  def args(self):
    return self._args
  def args_name(self):
    return remove_args_type(self._args)
  def low_args(self):
    return recursive_args(self._args, "low")
  def high_args(self):
    return recursive_args(self._args, "high")
  def define_p(self):
    return "".join(["#define ", self._name, "(", self.args_name(), ") "])
  def define(self):
    return "".join(["#define ", self._name, " ", self._prefix, self._name])
  def undef(self):
    return "".join(["#undef ", self._name])
  def signature(self):
    return "".join(["static inline ", self._rettype, " ", self._prefix, self._name, "(", self._args, ")"])
  def signature_nop(self):
    return "".join([self._rettype, " ", self._name, "(", self._args, ")"])
  def declare(self):
    return self.signature() + ";"
  def declare_nop(self):
    return self.signature_nop() + ";"
  def __call__(*varargs, **kwargs):
    return Func.__new__(*varargs, **kwargs)

def int_s(i):
  for s in [8, 16, 32, 64]:
    if i >= s:
      return s
  return 64

def int_t(i):
  return "int_fast" + str(int_s(i)) + "_t"

def uint_t(i):
  return "uint_fast" + str(int_s(i)) + "_t"


env.filters["expand_filter"] = expand_filter
env.filters["expand_force"] = filter_force
env.filters["macro"] = macro_filter
env.filters["noprint"] = lambda s: ""

_size1 = None
_size2 = None
_type1 = None
_type2 = None


variables = {}
def size1():
  global _size1
  return _size1
def size2():
  global _size2
  return _size2
def type1():
  global _type1
  return _type1
def type2():
  global _type2
  return _type2
def updateSizesTypes(sizes, types):
  global variables
  global _size1
  global _size2
  global _type1
  global _type2
  if len(sizes) == 0:
    _size1 = None
    _size2 = None
  else:
    _size1 = sizes[-1]
    _size2 = sizes[0]
  if len(types) == 0:
    _type1 = None
    _type2 = None
  else:
    _type1 = types[-1]
    _type2 = types[0]

env.globals.update({"max" : max, "min" : min, "str": str, "int": int})
env.globals.update(globals())
env.globals.update(locals())

re_files = re.compile(r"(.*)\.jinja")
template_dir = "generator/templates"

for d, e, files in os.walk(template_dir):
  d = re.sub(template_dir + "/?", "", d or ".") or "."
  for f in files:
    m = re_files.match(f)
    f = d + "/" + f
    f2 = re.sub(re_files, lambda m: m.group(1), f)
    if m:
      with open(f2, "w") as output:
        output.write(env.get_template(f).render({"FILE" : f2}))

