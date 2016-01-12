#! /usr/bin/env python
import sys
import re
from functools import partial

defines_output_filename = "include/pints-polyfill-defines.h.auto"
defines_header_filename = "generator/pints-polyfill-defines.h.head"
defines_footer_filename = "generator/pints-polyfill-defines.h.foot"
funcs_output_filename   = "include/pints-polyfill-funcs.h.auto"
funcs_header_filename   = "generator/pints-polyfill-funcs.h.head"
funcs_footer_filename   = "generator/pints-polyfill-funcs.h.foot"

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
    return MAX_LENGTH / self.size >= i and i > 0

INT    = Type("i", "int32_t", 4, "%i")
LONG   = Type("l", "int64_t", 8, "%lli")
FLOAT  = Type("f", "float",   4, "%f")
DOUBLE = Type("d", "double",  8, "%lf")

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

def iln2(i):
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
    (?P<second_size>\')?                          # second size
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
  ) | (?:
    \{\{\{  (?P<eval> [^{}]+) \}\}\}              # eval
  )
""", re.VERBOSE)
re_n = re.compile(r"%n")
def expand_type_pattern(_input, type1 = None, size1 = 1, type2 = None, size2 = None, force = 0):
  expand_first = True
  if type2 is None:
    type2 = type1
  if size2 is None:
    size2 = size1
  if type1 is None and type2 is None:
    return _input
  global type_pattern
  def callback(m, type1, i, type2, j, force):
    expand_first = type1 is not None
    if not expand_first or i is None:
      i = 1
    global type_pattern
    global re_n
    s = ""
    regular, loop, condition, evalstr = m.group("regular", "loop", "condition", "eval")
    if regular is not None:
      second_size, second_type, plus, minus, fixed, type_modifier, size_modifier, pattern = m.group("second_size", "second_type", "plus", "minus", "fixed", "type_modifier", "size_modifier", "pattern")
      if second_size is not None:
        i = j
      if second_type is not None:
        type1 = type2
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
      if type_modifier is 'i':
        type1 = type1.int_type
      if type_modifier is 'f':
        type1 = type1.float_type
      if size_modifier is "x32":
        type1 = type1.dword_type
      if size_modifier is "x64":
        type1 = type1.qword_type

      """ Pattern matching """
      if pattern is 'm':
        return type1.permutation_type(i)
      if pattern is 'M':
        return type1.mask(i)
      if pattern is 't':
        return type1.underlying_type
      if pattern is 'p':
        return type1.suffix
      if pattern is 'P':
        return type1.name(i)
      if (pattern is 'T' and force >= 0) or (pattern is 'I' and force > 0):
        return type1.name(i)
      if (pattern is 'I' and force <= 0) or (pattern is 'T' and force < 0):
        return type1.intern_name(i)
      if pattern is 'N':
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
      b = eval(tob,   {"ln2" : iln2}, {"type1": type1, "type2": type2});
      if fromb is None or fromb is "":
        a = b
        b += 1
      else:
        a = eval(fromb, {"ln2" : iln2}, {"type1": type1, "type2": type2});
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
    elif evalstr is not None:
      evalstr = type_pattern.sub(partial(callback, type1 = type1, i = i, type2 = type2, j = j, force = force), evalstr)
      if not expand_first:
        return "".join(["{{{", evalstr, "}}}"])
      return str(eval(evalstr, {"ln2" : iln2}, {"type1": type1, "type2": type2}))
    return m.group(0)

  return type_pattern.sub(partial(callback, type1 = type1, i = size1, type2 = type2, j = size2, force = force), _input)
def is_valid_type_pattern(_input, type1 = None, size1 = 1, type2 = None, size2 = None):
  if type1 is None:
    return False
  if type2 is None:
    type2 = type1
  if size2 is None:
    size2 = size1
  global type_pattern
  for m in type_pattern.finditer(_input):
    t = type1
    k = size1
    regular, loop, condition = m.group("regular", "loop", "condition")
    if regular is not None:
      second_size, second_type, plus, minus, fixed, type_modifier, size_modifier, pattern = m.group("second_size", "second_type", "plus", "minus", "fixed", "type_modifier", "size_modifier", "pattern")
      if second_size is not None:
        k = size2
      if second_type is not None:
        t = type2
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

      if not t.is_valid(k):
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


def remove_empty_lines(s, prefix = "", suffix = "", oneline_prefix = None, oneline_suffix = None, sep = "\n", joinstr = None):
  if oneline_prefix is None:
    oneline_prefix = prefix
  if oneline_suffix is None:
    oneline_suffix = suffix
  if joinstr is None:
    joinstr = sep
  lines = [line for line in s.split(sep) if line.strip() != ""]
  if len(lines) > 1:
    return prefix + joinstr.join(lines) + suffix
  if len(lines) is 1:
    return oneline_prefix + "".join(lines) + oneline_suffix
  return ""


class NotSame:
  def __init__(self, initset):
    self.initset = initset
  def __contains__(self, el):
    a, b = (0, 0)
    try:
      a, b = el
    except Exception:
      pass
    return a is not b and ((a in self.initset and b in self.initset) or el in self.initset)

def IsSame(l):
  def __init__(self, initset):
    self.initset = initset
  def __contains__(self, el):
    a, b = (0, 0)
    try:
      a, b = el
    except Exception:
      pass
    return a is b and (a in self.initset or el in self.initset)


class Macro:
  def __init__(self, name, args, definition, types = TYPES, sizes = SIZES, cond = ""):
    self.name = name
    self.args = args
    self.definition = remove_empty_lines(definition, joinstr=" \\\n  ", prefix="\\\n  ", oneline_prefix="")
    self.types = types
    self.sizes = sizes
    self.cond = cond
    self.full = " ".join([self.name, self.args, self.definition, "%$$", self.cond or "True", "$$"])
  def pre_expand_type(self, type2, size2):
    cond = expand_type_pattern(self.cond, type1 = None, size1 = None, type2 = type2, size2 = size2)
    name = expand_type_pattern(self.name, type1 = None, size1 = None, type2 = type2, size2 = size2)
    args = expand_type_pattern(self.args, type1 = None, size1 = None, type2 = type2, size2 = size2)
    definition = expand_type_pattern(self.definition, type1 = None, size1 = None, type2 = type2, size2 = size2)
    m = Macro(name = name, args = args, definition = definition, types = self.types, sizes = self.sizes, cond = cond)
    m.definition = definition
    return m
  def is_valid(self, type1, size1, type2 = None, size2 = None):
    if type2 is None:
      type2 = type1
    if size2 is None:
      size2 = size1
    return is_valid_type_pattern(self.full, type1 = type1, size1 = size1, type2 = type2, size2 = size2) and \
        ((type1 in self.types and type2 in self.types) or (type1,type2) in self.types) and ((size1 in self.sizes and size2 in self.sizes) or (size1,size2) in self.sizes)
  def is_macro(self):
    return True
  def is_func(self):
    return False
  def undefine(self, type1, size1, type2 = None, size2 = None):
    if type2 is None:
      type2 = type1
    if size2 is None:
      size2 = size1
    if not self.is_valid(type1 = type1, size1 = size1, type2 = type2, size2 = size2):
      return ""
    return "#undef " + expand_type_pattern(self.name, type1 = type1, size1 = size1, type2 = type2, size2 = size2) + "\n"
  def define(self, type1, size1, type2 = None, size2 = None):
    if type2 is None:
      type2 = type1
    if size2 is None:
      size2 = size1
    if not self.is_valid(type1 = type1, size1 = size1, type2 = type2, size2 = size2):
      return ""
    line = "".join([self.name, "(", self.args, ") ", self.definition, "\n"])
    return "#define " + expand_type_pattern(line, type1 = type1, size1 = size1, type2 = type2, size2 = size2)
  def declare(self, type1, size1, type2 = None, size2 = None):
    return ""
  def body(self, type1, size1, type2 = None, size2 = None):
    return ""
  def __str__(self):
    return "".join(["#define ", self.name, "(", self.args, ") ", self.definition])

class Function:
  def __init__(self, rettype, name, args, definition, types = TYPES, sizes = SIZES, prefix = "__", macro = True, force = 0, cond = ""):
    self.rettype = rettype
    self.name = name
    self.args = args
    self.definition = remove_empty_lines(definition, prefix="\n", suffix="\n", oneline_prefix=" ", oneline_suffix=" ")
    self.types = types
    self.sizes = sizes
    self.prefix = prefix
    self.macro = macro
    self.cond = cond
    self.full = " ".join([self.rettype, self.name, self.args, self.definition, self.prefix, "%$$", self.cond or "True", "$$"])
    self.force = force
  def pre_expand_type(self, type2, size2):
    cond = expand_type_pattern(self.cond, type1 = None, size1 = None, type2 = type2, size2 = size2)
    rettype = expand_type_pattern(self.rettype, type1 = None, size1 = None, type2 = type2, size2 = size2)
    name = expand_type_pattern(self.name, type1 = None, size1 = None, type2 = type2, size2 = size2)
    args = expand_type_pattern(self.args, type1 = None, size1 = None, type2 = type2, size2 = size2)
    definition = expand_type_pattern(self.definition, type1 = None, size1 = None, type2 = type2, size2 = size2)
    return Function(rettype = rettype, name = name, args = args, definition = definition, types = self.types, sizes = self.sizes, prefix = self.prefix, macro = self.prefix, force = self.force, cond = self)
  def is_valid(self, type1, size1, type2 = None, size2 = None):
    if type2 is None:
      type2 = type1
    if size2 is None:
      size2 = size1
    return is_valid_type_pattern(self.full, type1, size1, type2, size2) and ((type1 in self.types and type2 in self.types) or (type1,type2) in self.types) and ((size1 in self.sizes and size2 in self.sizes) or (size1,size2) in self.sizes)
  def is_macro(self):
    return False
  def is_func(self):
    return True
  def undefine(self, type1, size1, type2 = None, size2 = None):
    if not self.macro:
      return ""
    if type2 is None:
      type2 = type1
    if size2 is None:
      size2 = size1
    if not self.is_valid(type1 = type1, size1 = size1, type2 = type2, size2 = size2):
      return ""
    return "#undef " + expand_type_pattern(self.name, type1 = type1, size1 = size1, type2 = type2, size2 = size2, force = self.force) + "\n"
  def define(self, type1, size1, type2 = None, size2 = None):
    if not self.macro:
      return ""
    if type2 is None:
      type2 = type1
    if size2 is None:
      size2 = size1
    if not self.is_valid(type1 = type1, size1 = size1, type2 = type2, size2 = size2):
      return ""
    line = "".join([self.name, " ", self.prefix, self.name, "\n"])
    return "#define " + expand_type_pattern(line, type1 = type1, size1 = size1, type2 = type2, size2 = size2, force = self.force)
  def declare(self, type1, size1, type2 = None, size2 = None):
    if type2 is None:
      type2 = type1
    if size2 is None:
      size2 = size1
    if not self.is_valid(type1 = type1, size1 = size1, type2 = type2, size2 = size2):
      return ""
    line = "".join(["inline ", self.rettype, " ", self.prefix, self.name, "(", self.args, ");\n"])
    return expand_type_pattern(line, type1 = type1, size1 = size1, type2 = type2, size2 = size2, force = self.force);
  def body(self, type1, size1, type2 = None, size2 = None):
    if type2 is None:
      type2 = type1
    if size2 is None:
      size2 = size1
    if not self.is_valid(type1 = type1, size1 = size1, type2 = type2, size2 = size2):
      return ""
    full_def = "".join(["inline ", self.rettype, " ", self.prefix, self.name, "(", self.args, ") {", self.definition, "}\n"])
    return expand_type_pattern(full_def, type1 = type1, size1 = size1, type2 = type2, size2 = size2, force = self.force)
  def __str__(self):
    return "".join([self.rettype, " ", self.prefix, self.name, "(", self.args, ") {", self.definition, "}"])

rm_type_pattern = re.compile(r"%(?P<second>\'?)(?:(?P<plus>\++)|(?P<minus>\-+))?(?P<pattern>[if]?(?:x32|x64)?[mMtpPTIN]\'?) ?")
add_get_hilo = re.compile(r"(\s*)([^,\s]+)(?=,|$)")
def TrivialRecursion(f, args = None):
  if args is None:
    args = rm_type_pattern.sub("", f.args)
  def callback(m):
    second, plus, minus, pattern = m.group("second", "plus", "minus", "pattern")
    i = 0
    if plus is not None:
      i = len(plus)
    elif minus is not None:
      i = -len(minus)
    i -= 1
    s = ""
    if i > 0:
      s = "+" * i
    elif i < 0:
      s = "-" * (-i)
    return "".join(["%", second, s, pattern])
  sizes = recursive_sizes(max(f.sizes))
  name = f.name
  if f.is_func and not f.macro:
    name = f.prefix + f.name
  name = rm_type_pattern.sub(callback, name)
  low_args = add_get_hilo.sub(r"\1%-P_get_low_%P(\2)", args)
  high_args = add_get_hilo.sub(r"\1%-P_get_high_%P(\2)", args)
  line = "".join(["%P_merge_%-P(", name, "(", low_args, "), ", name, "(", high_args, "))"])
  return Macro(f.name, args, line, types = f.types, sizes = sizes, cond = f.cond)

class ContentWrapper:
  def __init__(self, definition, with_macro = False, sizes = SIZES, types = TYPES, declare = "", undef = "", cond = ""):
    self.definition = remove_empty_lines(definition, suffix="\n")
    self.with_macro = with_macro
    self.sizes = sizes
    self.types = types
    self.cond = cond
  def pre_expand_type(self, type2, size2):
    cond = expand_type_pattern(self.cond, type1 = None, size1 = None, type2 = type2, size2 = size2)
    definition = expand_type_pattern(self.definition, type1 = None, size1 = None, type2 = type2, size2 = size2)
    return ContentWrapper(definition = definition, types = self.types, sizes = self.sizes, with_macro = self.with_macro, cond = cond)
  def is_valid(self, type1, size1, type2 = None, size2 = None):
    if type2 is None:
      type2 = type1
    if size2 is None:
      size2 = size1
    return is_valid_type_pattern(self.definition + " %$$" + self.cond or "True" + "$$", type1, size1, type2, size2) and ((type1 in self.types and type2 in self.types) or (type1,type2) in self.types) and ((size1 in self.sizes and size2 in self.sizes) or (size1,size2) in self.sizes)
  def is_macro(self):
    return False
  def is_func(self):
    return False
  def undefine(self, type1, size1, type2 = None, size2 = None):
    return ""
  def define(self, type1, size1, type2 = None, size2 = None):
    if not self.with_macro:
      return ""
    if type2 is None:
      type2 = type1
    if size2 is None:
      size2 = size1
    if not self.is_valid(type1 = type1, size1 = size1, type2 = type2, size2 = size2):
      return ""
    return expand_type_pattern(self.definition, type1 = type1, size1 = size1, type2 = type2, size2 = size2)
  def declare(self, type1, size1, type2 = None, size2 = None):
    return ""
  def body(self, type1, size1, type2 = None, size2 = None):
    if self.with_macro:
      return ""
    if type2 is None:
      type2 = type1
    if size2 is None:
      size2 = size1
    if not self.is_valid(type1 = type1, size1 = size1, type2 = type2, size2 = size2):
      return ""
    return expand_type_pattern(self.definition, type1 = type1, size1 = size1, type2 = type2, size2 = size2)
  def __str__(self):
    return self.definition

class RawContent:
  def __init__(self, definition = "", macro = "", declare = "", undef = ""):
    self.definition = remove_empty_lines(definition, suffix="\n", oneline_suffix="")
    self.macro = remove_empty_lines(macro, suffix="\n", oneline_suffix="")
    self.declaration = remove_empty_lines(declare, suffix="\n", oneline_suffix="")
    self.undef = remove_empty_lines(undef, suffix="\n", oneline_suffix="")
  def is_valid(self, type1, size1, type2 = None, size2 = None):
    return True
  def is_macro(self):
    return False
  def is_func(self):
    return False
  def undefine(self, type1 = None, size1 = None, type2 = None, size2 = None):
    return self.undef
  def define(self, type1 = None, size1 = None, type2 = None, size2 = None):
    return self.macro
  def declare(self, type1 = None, size1 = None, type2 = None, size2 = None):
    return self.declaration
  def body(self, type1 = None, size1 = None, type2 = None, size2 = None):
    return self.definition
  def __str__(self):
    return "".join([self.undef, self.macro, self.declare, self.definition])



""" Functions with Initializers """
EQ    = Function("%I", "%P_eq",   "%I a, %I b", "%I r = { i: -(a.v == b.v) }; return r;", sizes = [1])
NEQ   = Function("%I", "%P_neq",  "%I a, %I b", "%I r = { i: -(a.v != b.v) }; return r;", sizes = [1])
GT    = Function("%I", "%P_gt",   "%I a, %I b", "%I r = { i: -(a.v >  b.v) }; return r;", sizes = [1])
GEQ   = Function("%I", "%P_geq",  "%I a, %I b", "%I r = { i: -(a.v >= b.v) }; return r;", sizes = [1])
LT    = Function("%I", "%P_lt",   "%I a, %I b", "%I r = { i: -(a.v <  b.v) }; return r;", sizes = [1])
LEQ   = Function("%I", "%P_leq",  "%I a, %I b", "%I r = { i: -(a.v <= b.v) }; return r;", sizes = [1])
AND   = Function("%I", "%P_and",  "%I a, %I b", "%I r = { i: a.i & b.i }; return r;", sizes = [1])
OR    = Function("%I", "%P_or",   "%I a, %I b", "%I r = { i: a.i | b.i }; return r;", sizes = [1])
XOR   = Function("%I", "%P_xor",  "%I a, %I b", "%I r = { i: a.i ^ b.i }; return r;", sizes = [1])
ADD   = Function("%I", "%P_add",  "%I a, %I b", "%I r = { v: a.v + b.v }; return r;", sizes = [1])
SUB   = Function("%I", "%P_sub",  "%I a, %I b", "%I r = { v: a.v - b.v }; return r;", sizes = [1])
MUL   = Function("%I", "%P_mul",  "%I a, %I b", "%I r = { v: a.v * b.v }; return r;", sizes = [1])
DIV   = Function("%I", "%P_div",  "%I a, %I b", "%I r = { v: a.v / b.v }; return r;", sizes = [1])
SQRTf = Function("%I", "%P_sqrt", "%I a",       "%I r = { v: sqrt(a.v) }; return r;", sizes = [1], types = FLOATS)
SQRTi = Macro("%P_sqrt", "a", "%P_cvt_%fP(%P_sqrt(%fP_cvt_%P(a)))", types = INTEGERS)
LOAD  = Function("%I",   "%P_load",  "const %t *p", "%I r = { v: *p }; return r;", sizes = [1])
STORE = Function("void", "%P_store", "%t *p, %I a", "*p = a.v;", sizes = [1])
SET = Function("%T", "%P_set", "%t a", "return %P_load(&a);", sizes = [1])
LOADU   = Macro("%P_loadu",  "p",    "%P_load(p)", sizes = [1])
STORU   = Macro("%P_storeu", "p, a", "%P_store((p), (a))", sizes = [1])
LOAD1   = Macro("%P_load1",  "p", "%P_set1(*(p))", sizes = [1])
STOR1   = Macro("%P_store1", "p, a", "(*p = s%p_cvt_%P(a))", sizes = [1])
SET1    = Macro("%P_set1", "v", "%P_set(%$$0:%N$(v)$, $$)", sizes = [1])
EQr   = TrivialRecursion(EQ)
NEQr  = TrivialRecursion(NEQ)
GTr   = TrivialRecursion(GT)
GEQr  = TrivialRecursion(GEQ)
LTr   = TrivialRecursion(LT)
LEQr  = TrivialRecursion(LEQ)
ANDr  = TrivialRecursion(AND)
ORr   = TrivialRecursion(OR)
XORr  = TrivialRecursion(XOR)
ADDr  = TrivialRecursion(ADD)
SUBr  = TrivialRecursion(SUB)
MULr  = TrivialRecursion(MUL)
DIVr  = TrivialRecursion(DIV)
SQRTr = TrivialRecursion(SQRTf)
LOADr = Function("%T", "%P_load",  "const %t *p",
  r"return %P_merge_%-P(%-P_load(p), %-P_load(p+%-N));", sizes = recursive_sizes(1))
STORr = Function("void", "%P_store", "%t *p, %T a",
  r"%-P_store(p, %-P_get_low_%P(a)); %-P_store(p+%-N, %-P_get_high_%P(a));", sizes = recursive_sizes(1))
SETr = Macro("%P_set", "%$$0:%N$a%n$, $$", "%P_merge_%-P(%-P_set(%$$0:%-N$(a%n)$, $$), %-P_set(%$$%-N:%N$(a%n)$, $$))")
LOADUr  = Function("%T", "%P_loadu",  "const %t *p",
  r"return %P_merge_%-P(%-P_loadu(p), %-P_loadu(p+%-N));", sizes = recursive_sizes(1))
STORUr  = Function("void", "%P_storeu", "%t *p, %T a",
  r"%-P_storeu(p, %-P_get_low_%P(a)); %-P_storeu(p+%-N, %-P_get_high_%P(a));", sizes = recursive_sizes(1))
LOAD1r  = Function("%T", "%P_load1",  "const %t *p", "%-T a = %-P_load1(p); return %P_merge_%-P(a, a);", sizes = recursive_sizes(1))
STOR1r  = Function("void", "%P_store1", "%t *p, %T a", "%-P_store1(p, %-P_get_low_%P(a));", sizes = recursive_sizes(1))
SET1r   = Function("%T", "%P_set1", "%t v", "%-T a = %-P_set1(v); return %P_merge_%-P(a, a);", sizes = recursive_sizes(1))




""" Functions """
LOADUc = Function("%T", "%P_loadu", "const %t *p", r"""
  int i;
  PINTS_ALIGNED_ARRAY(%t, v, %N, %N*sizeof(%t));
  for (i = 0; i < %N; ++i) v[i] = p[i];
  return %P_load(v);
""", prefix = "compatible_", macro = False)
STORUc = Function("void", "%P_storeu", "%t *p, %P a", r"""
  int i;
  PINTS_ALIGNED_ARRAY(%t, v, %N, %N*sizeof(%t));
  %P_store(v, a);
  for (i = 0; i < %N; ++i) p[i] = v[i];
""", prefix = "compatible_", macro = False)
GETHI = Function("%-T", "%-P_get_high_%P", "%I a", "return a.b;")
GETLOc = Function("%-T", "%-P_get_low_%P", "%T a", r"""
  int i;
  PINTS_ALIGNED_ARRAY(%t, v, %N, %N*sizeof(%t));
  %P_store(v, a);
  return %-P_load(v);
""", prefix = "compatible_", macro = False)
GETHIc = Function("%-T", "%-P_get_high_%P", "%T a", r"""
  int i;
  PINTS_ALIGNED_ARRAY(%t, v, %N, %N*sizeof(%t));
  %P_store(v, a);
  return %-P_load(v+%-N);
""", prefix = "compatible_", macro = False)
MERGEc = Function("%T", "%P_merge_%-P", "%-T low, %-T high", r"""
  int i;
  PINTS_ALIGNED_ARRAY(%t, v, %N, %N*sizeof(%t));
  %-P_store(v, low);
  %-P_store(v + %-N, high);
  return %P_load(v);
""", prefix = "compatible_", macro = False)
rFPRINT = Function("void", "%P_rfprint", "void *f, %T a", r"""
  int i, comma = 0;
  PINTS_ALIGNED_ARRAY(%t, v, %N, %N*sizeof(%t));
  %P_store(v, a);
  for (i = 0; i < %N; ++i) {
    if (comma) fprintf(f, "\t");
    comma = 1;
    fprintf(f, "{{{type1.form}}}", v[{{{%N-1}}}-i]);
  }
""")
FPRINT = Function("void", "%P_fprint", "void *f, %T a", r"""
  int i, comma = 0;
  PINTS_ALIGNED_ARRAY(%t, v, %N, %N*sizeof(%t));
  %P_store(v, a);
  for (i = 0; i < %N; ++i) {
    if (comma) fprintf(f, "\t");
    comma = 1;
    fprintf(f, "{{{type1.form}}}", v[i]);
  }
""")

MERGEname = "%P_merge{{{%N/%'N'}}}_%'P"
MERGEargs = "%$$0:%N/%'N'$a%n$, $$"
MERGEbody = "%P_merge2_%-P(%-P_merge%$$%-N/%'N'$%n$$_%'P(%$$0:%-N/%'N'$a%n$, $$), %-P_merge%$$%-N/%'N'$%n$$_%'P(%$$%-N/%'N':%N/%'N'$a%n$, $$))"
rMERGEname = "%P_rmerge{{{%N/%'N'}}}_%'P"
rMERGEargs = "%$$%N/%'N':0$a%n$, $$"
rMERGEbody = "%P_merge{{{%N/%'N'}}}_%'P(%$$0:%N/%'N'$a%n$, $$)"
def generate_merges():
  Merge = Macro(MERGEname, MERGEargs, MERGEbody, cond = "%N >= %N/%'N' and %-N > %'N'")
  rMerge = Macro(rMERGEname, rMERGEargs, rMERGEbody, cond = "%N >= %N/%'N' and %N > %'N'")
  def pre_expand(f, i):
    return f.pre_expand_type(FLOAT, i)
  merges = [Function("%I", "%P_merge2_%-P", "%-T low, %-T high", "%I r = { a: low, b: high }; return r;")]
  merges += [pre_expand(Merge, i) for i in SIZES]
  merges += [pre_expand(rMerge, i) for i in SIZES]
  return merges


inhSHUFFLEname = "%P_hshuffle{{{%N/%'N'}}}x%'N'"
inhSHUFFLEargs = "a, b, rule"
inhSHUFFLEbody = "%P_merge2_%-P(%-P_hshuffle{{{%N/%'N'}}}x%'-N'(%-P_get_low_%P(a), %-P_get_low_%P(b), (rule)), %-P_hshuffle{{{%N/%'N'}}}x%'-N'(%-P_get_high_%P(a), %-P_get_high_%P(b), (rule)))"
inPERMUTEname = "%P_permute{{{%N/%'N'}}}x%'N'"
inPERMUTEargs = "a, rule"
inPERMUTEbody = "%P_hshuffle{{{%N/%'N'}}}x%'N'((a), (a), (rule))"
infSHUFFLEname = "%P_fshuffle{{{%N/%'N'}}}x%'N'"
infSHUFFLEargs = "a, b, rule, mask"
infSHUFFLEbody = "%P_blend(%P_permute{{{%N/%'N'}}}x%'N'((a), (rule)), %P_permute{{{%N/%'N'}}}x%'N'((b), (rule)), (mask))"

outhSHUFFLEname = "%P_hshuffle%'N'"
outhSHUFFLEargs = "a, b, rule"
outhSHUFFLEbody = r"""%P_merge_%-P(
  %-P_fshuffle%'-N'(
    %-P_get_low_%P(a), %-P_get_high_%P(a),
    %$$0:%'-N'$((((rule) >> {{{%n*ln2(%'N')}}}) & {{{%'-N'-1}}}) << {{{%n*ln2(%'-N')}}})$|$$,
    %$$0:%'-N'$((((rule) >> {{{%n*ln2(%'N')+ln2(%'-N')}}}) & {{{%'-N'-1}}}) << %n)$|$$),
  %-P_fshuffle%'-N'(
    %-P_get_low_%P(b), %-P_get_high_%P(b),
    %$$0:%'-N'$((((rule) >> {{{%'-N'*ln2(%'N')+%n*ln2(%'N')}}}) & {{{%'-N'-1}}}) << {{{%n*ln2(%'-N')}}})$|$$,
    %$$0:%'-N'$((((rule) >> {{{%'-N'*ln2(%'N')+%n*ln2(%'N')+ln2(%'-N')}}}) & {{{%'-N'-1}}}) << %n)$|$$)
  )
"""
outPERMUTEname = "%P_permute%'N'"
outPERMUTEargs = "a, rule"
outPERMUTEbody = "%P_hshuffle%'N'((a), (a), (rule))"
outfSHUFFLEname = "%P_fshuffle%'N'"
outfSHUFFLEargs = "a, b, rule, mask"
outfSHUFFLEbody = "%P_blend%'N'(%P_permute%'N'((a), (rule)), %P_permute%'N'((b), (rule)), (mask))"
def generate_shuffles():
  shuffles = []
  inhSHUFFLE = Macro(inhSHUFFLEname, inhSHUFFLEargs, inhSHUFFLEbody, cond = "%N > %'N'")
  inPERMUTE  = Macro(inPERMUTEname,  inPERMUTEargs,  inPERMUTEbody,  cond = "%N > %'N'")
  infSHUFFLE = Macro(infSHUFFLEname, infSHUFFLEargs, infSHUFFLEbody, cond = "%N > %'N'")
  outhSHUFFLE = Macro(outhSHUFFLEname, outhSHUFFLEargs, outhSHUFFLEbody, cond = "%N >= %'N'")
  outPERMUTE  = Macro(outPERMUTEname,  outPERMUTEargs,  outPERMUTEbody,  cond = "%N >= %'N'")
  outfSHUFFLE = Macro(outfSHUFFLEname, outfSHUFFLEargs, outfSHUFFLEbody, cond = "%N >= %'N'")
  def pre_expand(f, i):
    return f.pre_expand_type(FLOAT, i)
  shuffles += [pre_expand(outhSHUFFLE, i) for i in SIZES if i > 2]
  shuffles += [pre_expand(outPERMUTE,  i) for i in SIZES if i is not 1]
  shuffles += [pre_expand(outfSHUFFLE, i) for i in SIZES if i is not 1]
  shuffles += [
      Macro("%P_hshuffle%Nx1", "a, b, rule", "%P_hshuffle%N((a), (b), (rule))", sizes = recursive_sizes(1)),
      Macro("%P_permute%Nx1", "a, b, rule", "%P_permute%N((a), (b), (rule))", sizes = recursive_sizes(1)),
      Macro("%P_fshuffle%Nx1", "a, b, rule", "%P_fshuffle%N((a), (b), (rule))", sizes = recursive_sizes(1))
  ]
  shuffles += [pre_expand(inhSHUFFLE, i) for i in SIZES if i is not 1]
  shuffles += [pre_expand(inPERMUTE,  i) for i in SIZES if i is not 1]
  shuffles += [pre_expand(infSHUFFLE, i) for i in SIZES if i is not 1]
  return shuffles
HSHUFFLE2 = Macro("%P_hshuffle2", "a, b, rule", "%P_merge_%-P(%-P_get_hilo_%P((a), (rule) & 1), %-P_get_hilo_%P((b), ((rule) >> 1) & 1))")
HSHUFFL = Macro("%P_hshuffle", "a, b, rule", "%P_hshuffle%N((a), (b), (rule))", sizes = recursive_sizes(1))
PERMUTE = Macro("%P_permute", "a, rule", "%P_permute%N((a), (rule))", sizes = recursive_sizes(1))
FSHUFFL = Macro("%P_fshuffle", "a, b, rule, mask", "%P_fshuffle%N((a), (b), (rule), (mask))", sizes = recursive_sizes(1))

BLEND1 = Macro("%P_blend1", "a, b, mask", "((mask&1) ? (b) : (a))")
#BLENDr = Macro("%P_blend", "a, b, mask", "%P_merge_%-P(%-P_blend(%-P_get_low_%P(a), %-P_get_low_%P(b), (mask) & {{{%N-1}}}), %-P_blend(%-P_get_low_%P(a), %-P_get_low_%P(b), ((mask) & {{{%N-1}}}) >> {{{ln2(%N)}}}))", sizes = recursive_sizes(1))

inBLENDname = "%P_blend{{{%N/%'N'}}}x%'N'"
inBLENDargs = "a, b, mask"
#inBLENDbody = "%P_merge2_%-P(%P_blend{{{%n/%'N'}}}x%'-N'(%-P_get_low_%P(a), %-P_get_low_%P(b), (mask), %P_blend{{{%n/%'N'}}}x%'-N'(%-P_get_high_%P(a), %-P_get_high_%P(b), (mask))"
inBLENDbody = "%P_blend{{{%+N/%'N'}}}x%'-N'((a), (b), (mask) | ((mask) << {{{%N/%'N'}}}))"

outBLENDname = "%P_blend%'N'"
outBLENDargs = "a, b, mask"
outBLENDbody = "%P_merge2_%-P(%-P_blend%'-N'(%-P_get_low_%P(a), %-P_get_low_%P(b), (mask) & {{{(1<<%'-N')-1}}}), %-P_blend%'-N'(%-P_get_high_%P(a), %-P_get_high_%P(b), ((mask) >> %'-N') & {{{(1<<%'-N')-1}}}))"
def generate_blends():
  blends = [BLEND1]
  outBLEND = Macro(outBLENDname, outBLENDargs, outBLENDbody, cond = "%N >= %'N'")
  inBLENDN = Macro(inBLENDname,  inBLENDargs,  inBLENDbody,  cond = "%N >= %'N'")
  blends += [outBLEND.pre_expand_type(FLOAT, i) for i in SIZES if i is not 1]
  blends += [
     Macro("%P_blend",      "a, b, mask", "%P_blend%N((a), (b), (mask))"),
     Macro("%P_blend%Nx1",  "a, b, mask", "%P_blend%N((a), (b), (mask))")
  ]
  blends += [inBLENDN.pre_expand_type(FLOAT, i) for i in SIZES if i is not 1]
  return blends






""" Macros """
#MAND    = Macro("%M_and", "a, b", "%M_cvt_%P(%P_and(%P_cvt_%M(a), %P_cvt_%M(b)))")
#MOR     = Macro("%M_or",  "a, b", "%M_cvt_%P(%P_or(%P_cvt_%M(a), %P_cvt_%M(b)))")
#MXOR    = Macro("%M_xor", "a, b", "%M_cvt_%P(%P_xor(%P_cvt_%M(a), %P_cvt_%M(b)))")
ZEROS   = Macro("%P_zeros", "", "%P_set1(0)")
ZERO    = Macro("%P_zero", "", "%P_zeros()")
ONE     = Macro("%P_one", "", "%P_set1(1)")
ONES    = Macro("%P_ones", "", "%P_cast_%iP(%iP_set1(-1))")
NOT     = Macro("%P_not", "a", "%P_xor((a), %P_ones())")
NAND    = Macro("%P_nand", "a, b", "%P_not(%P_and((a), (b)))")
NOR     = Macro("%P_nor",  "a, b", "%P_not(%P_or((a), (b)))")
NXOR    = Macro("%P_nxor", "a, b", "%P_not(%P_xor((a), (b)))")
ANDNOT  = Macro("%P_andnot", "a, b", "%P_and((a), %P_not(b))")
ORNOT   = Macro("%P_ornot", "a, b", "%P_or((a), %P_not(b))")
rSET    = Macro("%P_rset", "%$$%N:0$a%n$, $$", "%P_set(%$$0:%N$(a%n)$, $$)")
GETLO   = Macro("%-P_get_low_%P", "a", "%-P_cast_%P(a)")
MERGE   = Macro("%P_merge_%-P", "low, high", "%P_merge2_%-P((low), (high))")
rMERGE  = Macro("%P_rmerge_%-P", "high, low", "%P_merge_%-P((low), (high))")
rMERGEc = Macro("compatible_%P_rmerge_%-P", "high, low", "%P_rmerge_%-P((high), (low))")
SETLO   = Macro("%P_set_low_%-P",  "src, low",  "%P_merge_%-P((low), %-P_get_high_%P(src))")
SETHI   = Macro("%P_set_high_%-P", "src, high", "%P_merge_%-P(%-P_get_low_%P(src), (high))")
SETHILO = Macro("%P_set_hilo_%-P", "src, hilo, high", "((high) ? %P_set_high_%-P((src), (hilo)) : %P_set_low_%-P((src), (hilo)))")
GETHILO = Macro("%-P_get_hilo_%P", "src, high", "((high) ? %-P_get_high_%P(src) : %-P_get_low_%P(src))")
NEG     = Macro("%P_neg",    "a", "%P_sub(%P_zero(), (a))")
FMADD   = Macro("%P_fmadd",  "a, b, acc", "%P_add(%P_mul((a), (b)), (acc))")
FMSUB   = Macro("%P_fmsub",  "a, b, acc", "%P_sub(%P_mul((a), (b)), (acc))")
FNMADD  = Macro("%P_fnmadd", "a, b, acc", "%P_sub((acc), %P_mul((a), (b)))")
FNMSUB  = Macro("%P_fnmsub", "a, b, acc", "%P_sub(%P_neg(acc), %P_mul((a), (b)))")
RCP     = Macro("%P_rcp",    "a", "%P_div(%P_one(), (a))")
FRCP    = Macro("%P_frcp",   "a", "%P_rcp(a)")
RSQRT   = Macro("%P_rsqrt",  "a", "%P_rcp(%P_sqrt(a))")
FRSQRT  = Macro("%P_frsqrt", "a", "%P_rsqrt(a)")
PRINT   = Macro("%P_print",  "a", "%P_fprint(stdout, a)")
rPRINT  = Macro("%P_rprint", "a", "%P_rfprint(stdout, a)")

BUILTINS = [
  LOAD, LOADr, LOADU, LOADUr, LOADUc, LOAD1, LOAD1r, STORE, STORr, STORU, STORUr, STORUc, STOR1, STOR1r,
  SET, SETr, rSET, SET1, SET1r, ZEROS, ONES, ZERO, ONE
  ] + generate_merges() + [
  GETLO, GETLOc, GETHI, GETHIc, GETHILO,
  SETLO, SETHI, SETHILO, MERGE, rMERGE, MERGEc, rMERGEc] + generate_blends() + [
  HSHUFFLE2] + generate_shuffles() + [HSHUFFL, PERMUTE, FSHUFFL,
  EQ, EQr, NEQ, NEQr, GT, GTr, GEQ, GEQr, LT, LTr, LEQ, LEQr,
  AND, ANDr, OR, ORr, XOR, XORr, NOT, NAND, NOR, NXOR, ANDNOT, ORNOT,
  #ALL_ZEROS, ALL_ONES,
  #mAND, mANDr, mOR, mORr, mXOR, mXORr, #mNOT, mNAND, mNOR, mNXOR, mANDNOT, mORNOT,
  #mALL_ZEROS, mALL_ONES,
  ADD, ADDr, SUB, SUBr, MUL, MULr, DIV, DIVr, SQRTf, SQRTr, SQRTi,
  NEG, RCP, FRCP, RSQRT, FRSQRT,
  FMADD, FMSUB, FNMADD, FNMSUB,
  FPRINT, rFPRINT, PRINT, rPRINT
]

UNION_INTERN = ContentWrapper(r"""
union __%P {
  %t v;
  %it i;
};
""", sizes = [1])
STRUCT_INTERN = ContentWrapper(r"struct __%P { %-T a, b; };", sizes = [ i for i in SIZES if i > 1 ])
TYPES_INTERN  = ContentWrapper(r"#define %T %I", with_macro = True)
MASK          = ContentWrapper(r"#define %M %iP", with_macro = True)
INTERNALS = [ UNION_INTERN, STRUCT_INTERN, TYPES_INTERN, MASK ]



CVTs = remove_empty_lines(r"""
inline %t __s%p_cvt_%P(%T a) {
  int i;
  %t s%P;
  %P_store(&s%P, a);
  return s%P;
}
""")
CVT = remove_empty_lines(r"""
inline %T __%P_cvt_%P'(%T' a) {
  int i;
  %t s%P;
  %t' s%P';
  %P'_store(&s%P', a);
  s%P = s%P';
  return %P_load(&s%P);
}
""")
CVTi    = "#define %P_cvt_%P(a) (a)"
CVTr    = "#define %P_cvt_%P'(a) %P_merge_%-P(%-P_cvt_%-P'(%-P'_get_low_%P'(a)), %-P_cvt_%-P'(%-P'_get_high_%P'(a)))"
CVTsr   = "#define s%p_cvt_%'P'(a) s%p_cvt_v1%p(v1%p_cvt_%'P'(a))"
CVTup   = "#define %P_cvt_%'P'(a) %P_cast_%'P(%'P_cvt_%'P'(a))"
CVTdown = "#define %P_cvt_%'P'(a) %P_cvt_%P'(%P'_cast_%'P'(a))"
CVTMl   = "#define %M_cvt_%P(a) %iP_cast_%P(a)"
CVTMr   = "#define %P_cvt_%M(a) %P_cast_%iP(a)"
def generate_cvts():
  macro = []
  undef = []
  declare = []
  definition = []
  def generate_cvt(type1, size1, type2, size2):
    if not type1.is_valid(size1) or not type2.is_valid(size2):
      return ([],[],[],[])
    f = lambda a: map(lambda s: expand_type_pattern(s, type1 = type1, size1 = size1, type2 = type2, size2 = size2), a)
    macro = []#macro = ["#define %P_cvt_%'P' __%P_cvt_%'P'"]
    undef = ["#undef %P_cvt_%'P'"]
    declare = []
    definition = []
    if size1 is 1:
      undef.append("#undef s%p_cvt_%'P'")
    if type1 is type2 and size1 is size2:
      macro.append(CVTi)
      macro.append(CVTMl)
      macro.append(CVTMr)
      if size1 is 1:
        macro.append("#define s%p_cvt_%'P' __s%p_cvt_%'P'")
        declare.append("inline %t __s%p_cvt_%P(%T a);")
        definition.append(CVTs)
    else:
      if type1 is not type2 or size2 is not 1:
        macro.append(CVTsr)
      if size1 is 1 and size2 is 1:
        macro.append("#define %P_cvt_%'P' __%P_cvt_%'P'")
        declare.append("inline %T __%P_cvt_%P'(%T' a);")
        definition.append(CVT)
      elif size1 < size2:
        macro.append(CVTdown)
      elif size1 is size2:
        macro.append(CVTr)
      else:
        macro.append(CVTup)
    return (f(macro), f(undef), f(declare), f(definition))
  for size1 in SIZES:
    for type1 in TYPES:
      for size2 in SIZES:
        for type2 in TYPES:
          tup = generate_cvt(type1, size1, type2, size2)
          macro += tup[0]
          undef += tup[1]
          declare += tup[2]
          definition += tup[3]
  return RawContent(macro = "\n".join(macro), undef = "\n".join(undef), declare = "\n".join(declare), definition = "\n".join(definition))

CASTm = "#define %P_cast_%'P' __%P_cast_%'P'"
CASTi = "#define %P_cast_%P(a) (a)"
CASTidown = remove_empty_lines(r"""
inline %T __%P_cast_%'P(%'I a) { return a.a; }
""")
CASTiup = remove_empty_lines(r"""
inline %I __%P_cast_%'P(%'T a) { %I r = { a: a }; return r; }
""")
CASTx = "#define %P_cast_%'P'(a) (*((%T*)(&a)))"
CASTiupr = "#define %P_cast_%'P(a) %P_cast_%-P(%-P_cast_%'P(a))"
CASTidownr = "#define %P_cast_%'P(a) %P_cast_%'-P(%'-P_cast_%'P(a))"
CASTup = "#define %P_cast_%'P'(a) %P_cast_%'P(%'P_cast_%'P'(a))"
CASTdown = "#define %P_cast_%'P'(a) %P_cast_%P'(%P'_cast_%'P'(a))"
CASTupr = "#define %P_cast_%'P'(a) %P_cast_%-P(%-P_cast_%'P(%'P_cast_%'P'(a)))"
CASTdownr = "#define %P_cast_%'P'(a) %P_cast_%P'(%P'_cast_%'-P'(%'-P'_cast_%'P'(a)))"
CASTM = "#define %M_cast_%'M'(a) %iP_cvt_%'iP'(a)"
def generate_casts():
  macro = []
  undef = []
  declare = []
  definition = []
  def generate_cast(type1, size1, type2, size2):
    if not type1.is_valid(size1) or not type2.is_valid(size2):
      return ([],[],[],[])
    f = lambda a: map(lambda s: expand_type_pattern(s, type1 = type1, size1 = size1, type2 = type2, size2 = size2), a)
    macro = [CASTM]
    undef = ["#undef %P_cast_%'P'"]
    declare = []
    definition = []
    length1 = size1 * type1.size
    length2 = size2 * type2.size
    if type1 is type2:
      if size1 is size2:
        macro.append(CASTi)
      elif size1 is size2 * 2:
        macro.append(CASTm)
        declare.append("inline %I __%P_cast_%'P(%'T a);")
        definition.append(CASTiup)
      elif size1 > size2:
        macro.append(CASTiupr)
      elif size1 is size2 / 2:
        macro.append(CASTm)
        declare.append("inline %T __%P_cast_%'P(%'I a);")
        definition.append(CASTidown)
      else:
        macro.append(CASTidownr)
    elif length1 is length2:
      macro.append(CASTx)
    elif length1 is length2 * 2:
      macro.append(CASTup)
    elif length1 > length2:
      macro.append(CASTupr)
    elif length1 is length2 / 2:
      macro.append(CASTdown)
    else:
      macro.append(CASTdownr)
    return (f(macro), f(undef), f(declare), f(definition))
  for size1 in SIZES:
    for type1 in TYPES:
      for size2 in SIZES:
        for type2 in TYPES:
          tup = generate_cast(type1, size1, type2, size2)
          macro += tup[0]
          undef += tup[1]
          declare += tup[2]
          definition += tup[3]
  return RawContent(macro = "\n".join(macro), undef = "\n".join(undef), declare = "\n".join(declare), definition = "\n".join(definition))

RAW = [generate_casts(), generate_cvts()]

def append_file(output, filename):
  with open(filename, "r") as f:
    output.write(f.read())

def create_defines_file():
  with open(defines_output_filename, "w") as output:
    append_file(output, defines_header_filename)
    output.write("\n\n// Internals structures\n\n")
    for f in INTERNALS:
      for size in SIZES:
        for t in TYPES:
          output.write(f.define(type1 = t, size1 = size))
      output.write("\n")
    output.write("\n\n// Casts ans Conversions\n\n")
    for raw in RAW:
      output.write(raw.define())
      output.write("\n")
    output.write("\n\n// Builtins\n\n")
    for f in BUILTINS:
      for size in SIZES:
        for t in TYPES:
          output.write(f.define(type1 = t, size1 = size))
      output.write("\n")
    append_file(output, defines_footer_filename)

def create_funcs_file():
  with open(funcs_output_filename, "w") as output:
    append_file(output, funcs_header_filename)
    output.write("\n\n// Internals structures\n\n")
    for f in INTERNALS:
      for size in SIZES:
        for t in TYPES:
          output.write(f.body(type1 = t, size1 = size))
      output.write("\n")
    output.write("\n\n// Casts ans Conversions declarations\n\n")
    for raw in RAW:
      output.write(raw.declare())
      output.write("\n")
    output.write("\n\n// Builtins declarations\n\n")
    for f in BUILTINS:
      for size in SIZES:
        for t in TYPES:
          output.write(f.declare(type1 = t, size1 = size))
      output.write("\n")
    output.write("\n\n// Casts ans Conversions implementations\n\n")
    for raw in RAW:
      output.write(raw.body())
      output.write("\n")
    output.write("\n\n// Builtins implementations\n\n")
    for f in BUILTINS:
      for size in SIZES:
        for t in TYPES:
          output.write(f.body(type1 = t, size1 = size))
      output.write("\n")
    append_file(output, funcs_footer_filename)

create_defines_file()
create_funcs_file()
