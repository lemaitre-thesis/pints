#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <regex>

const int MAX_REGISTERb_SIZE = 512;
const int MAX_REGISTER_SIZE = MAX_REGISTERb_SIZE / 8;

const char* output_filename1 = "include/psimd-polyfill-defines.h.auto";
const char* header_filename1 = "generator/psimd-polyfill-defines.h.head";
const char* footer_filename1 = "generator/psimd-polyfill-defines.h.foot";
const char* output_filename2 = "include/psimd-polyfill-funcs.h.auto";
const char* header_filename2 = "generator/psimd-polyfill-funcs.h.head";
const char* footer_filename2 = "generator/psimd-polyfill-funcs.h.foot";

struct Type {
  const char  letter;
  const char* name;
  const int   size;
  const Type* inttype;
  const char* format;
  std::string union_name(int i = 1) const {
    std::stringstream ss;
    ss << "union __v" << i << letter;
    return ss.str();
  }
  std::string struct_name(int i = 1) const {
    std::stringstream ss;
    ss << "struct __v" << i << letter;
    return ss.str();
  }
  std::string intern_name(int i = 1) const {
    if (i == 1) {
      return union_name(i);
    }
    return struct_name(i);
  }
  std::string prefix(int i = 1) const {
    std::stringstream ss;
    ss << "v" << i << letter;
    return ss.str();
  }
  bool is_valid(int i) const {
    return i >= 1 && i <= MAX_REGISTER_SIZE / size;
  }
};


const Type INT     = {letter: 'i', name: "int32_t", size: 4, inttype: &INT,  format: "%i"};
const Type LONG    = {letter: 'l', name: "int64_t", size: 8, inttype: &LONG, format: "%lli"};
const Type FLOAT   = {letter: 'f', name: "float  ", size: 4, inttype: &INT,  format: "%f"};
const Type DOUBLE  = {letter: 'd', name: "double ", size: 8, inttype: &LONG, format: "%lf"};
const Type TYPES[] = {DOUBLE, FLOAT, INT, LONG};
const Type TYPES32[] = {FLOAT, INT};
const Type TYPES64[] = {DOUBLE, LONG};
const int  SIZES[] = {1, 2, 4, 8, 16}; // size of 1 is different
const int NB_TYPES = 4;
const int NB_SIZES = 6;

std::string expand_type_pattern(std::string s, Type t, int i) {
  std::stringstream si, sim, sip;
  si << i; sim << i /2; sip << i*2;
  s = std::regex_replace(s, std::regex("%[+-]?it"), t.inttype->name);
  s = std::regex_replace(s, std::regex("%[+-]?t"), t.name);
  s = std::regex_replace(s, std::regex("%[+-]?if"), t.inttype->format);
  s = std::regex_replace(s, std::regex("%[+-]?f"), t.format);
  s = std::regex_replace(s, std::regex("%iT"), t.inttype->intern_name(i));
  s = std::regex_replace(s, std::regex("%T"), t.intern_name(i));
  s = std::regex_replace(s, std::regex("%iP"), t.inttype->prefix(i));
  s = std::regex_replace(s, std::regex("%P"), t.prefix(i));
  s = std::regex_replace(s, std::regex("%i?N"), si.str());

  s = std::regex_replace(s, std::regex("%-iT"), t.inttype->intern_name(i/2));
  s = std::regex_replace(s, std::regex("%-T"), t.intern_name(i/2));
  s = std::regex_replace(s, std::regex("%-iP"), t.inttype->prefix(i/2));
  s = std::regex_replace(s, std::regex("%-P"), t.prefix(i/2));
  s = std::regex_replace(s, std::regex("%-i?N"), sim.str());

  s = std::regex_replace(s, std::regex("%[+]iT"), t.inttype->intern_name(i*2));
  s = std::regex_replace(s, std::regex("%[+]T"), t.intern_name(i*2));
  s = std::regex_replace(s, std::regex("%[+]iP"), t.inttype->prefix(i*2));
  s = std::regex_replace(s, std::regex("%[+]P"), t.prefix(i*2));
  s = std::regex_replace(s, std::regex("%[+]i?N"), sip.str());
  return s;
}

std::string expand_type_pattern_general(std::string s, Type t, int i) {
  std::stringstream si, sim, sip;
  si << i; sim << i /2; sip << i*2;
  s = std::regex_replace(s, std::regex("%[+-]?it"), t.inttype->name);
  s = std::regex_replace(s, std::regex("%[+-]?t"), t.name);
  s = std::regex_replace(s, std::regex("%[+-]?if"), t.inttype->format);
  s = std::regex_replace(s, std::regex("%[+-]?f"), t.format);
  s = std::regex_replace(s, std::regex("%i[PT]"), t.inttype->prefix(i));
  s = std::regex_replace(s, std::regex("%[PT]"), t.prefix(i));
  s = std::regex_replace(s, std::regex("%i?N"), si.str());

  s = std::regex_replace(s, std::regex("%-i[PT]"), t.inttype->prefix(i/2));
  s = std::regex_replace(s, std::regex("%-[PT]"), t.prefix(i/2));
  s = std::regex_replace(s, std::regex("%-i?N"), sim.str());

  s = std::regex_replace(s, std::regex("%[+]i[PT]"), t.inttype->prefix(i*2));
  s = std::regex_replace(s, std::regex("%[+][PT]"), t.prefix(i*2));
  s = std::regex_replace(s, std::regex("%[+]i?N"), sip.str());
  return s;
}

struct Arg {
  const char* typen;
  const char* name;
  std::string type(Type t, int i = 1) const {
    return expand_type_pattern(typen, t, i);
  }
  std::string str(Type t, int i = 1) const {
    return type(t, i) + " " + name;
  }
};
typedef std::vector<Arg> Args;
struct Function {
  const char* rettype;
  const char* name;
  const Args args;
  const char* def;
  const char* widenrule = "";
  bool is_valid(const Type t, int i) const {
    if (!t.is_valid(i)) return false;
    std::string full = std::string() + rettype + " " + def + " " + name;
    for (const Arg arg : args) full += std::string(" ") + arg.typen;
    if (std::regex_search(full, std::regex("%[+]")) && !t.is_valid(i*2)) return false;
    if (std::regex_search(full, std::regex("%-")) && !t.is_valid(i/2)) return false;
    return true;
  }
  void print_def(std::ostream& output, Type t) const {
    if (!t.is_valid(1)) return;
    output << "inline " << expand_type_pattern(rettype, t, 1) << " __" << t.prefix() << "_" << expand_type_pattern(name, t, 1) << "(";
    bool comma = false;
    for (const Arg arg : args) {
      if (comma) output << ", ";
      comma = true;
      output << arg.str(t);
    }
    output << ") { " << expand_type_pattern(def, t, 1) << " }\n";
  }
  void print_wider(std::ostream& output, Type t, int to) const {
    if (!t.is_valid(to)) return;
    if (!widenrule) return;
    auto expand = (widenrule[0] == 0 || !std::regex_search(widenrule, std::regex("%[+-]?i?T"))) ? expand_type_pattern_general : expand_type_pattern;
    int from = to/2;
    output << "inline " << expand(rettype, t, to) << " __" << t.prefix(to) << "_" << expand(name, t, to) << "(";
    bool comma = false;
    for (const Arg arg : args) {
      if (comma) output << ", ";
      comma = true;
      output << expand(arg.typen, t, to) << " " << arg.name;//arg.str(t, to);
    }
    if (widenrule[0] != 0) {
      output << ") { " << expand(widenrule, t, to) << " };\n";
      return;
    }
    output << ") { return " << t.prefix(to) << "_merge_" << t.prefix(from) << "(";
    output << t.prefix(from) << "_" << expand(name, t, to/2) << "(";
    comma = false;
    for (const Arg arg : args) {
      if (comma) output << ", ";
      comma = true;
      if (std::string(arg.typen) == "%T" || std::string(arg.typen) == "%P") {
        output << t.prefix(from) << "_get_low_" << t.prefix(to) << "(" << arg.name << ")";
      } else {
        output << arg.name;
      }
    }
    output << "), ";
    output << t.prefix(from) << "_" << expand(name, t, to/2) << "(";
    comma = false;
    for (const Arg arg : args) {
      if (comma) output << ", ";
      comma = true;
      if (std::string(arg.typen) == "%T" || std::string(arg.typen) == "%P") {
        output << t.prefix(from) << "_get_high_" << t.prefix(to) << "(" << arg.name << ")";
      } else {
        output << arg.name;
      }
    }
    output << ")";
    output << "); }\n";
  }
  void print_declaration(std::ostream& output, Type t, int i) const {
    if (!t.is_valid(i)) return;
    auto expand = (i != 1 && (widenrule[0] == 0 || !std::regex_search(widenrule, std::regex("%[+-]?i?T")))) ? expand_type_pattern_general : expand_type_pattern;
    output << "inline " << expand(rettype, t, i) << " __" << t.prefix(i) << "_" << expand(name, t, i) << "(";
    bool comma = false;
    for (const Arg arg : args) {
      if (comma) output << ", ";
      comma = true;
      output << expand(arg.typen, t, i) << " " << arg.name;
    }
    output << ");\n";
  }
  void print_define(std::ostream& output, Type t, int i) const {
    if (!t.is_valid(i)) return;
    output << "#define " << t.prefix(i) << "_" << expand_type_pattern(name, t, i) << " __" << t.prefix(i) << "_" << expand_type_pattern(name, t, i) << "\n";
  }
};
struct HelperFunction {
  const char* rettype;
  const char* name;
  const Args args;
  const char* def;
  const bool macro = true;
  bool is_valid(const Type t, int i) const {
    if (!t.is_valid(i)) return false;
    std::string full = std::string() + rettype + " " + def + " " + name;
    for (const Arg arg : args) full += std::string(" ") + arg.typen;
    if (std::regex_search(full, std::regex("%[+]")) && !t.is_valid(i*2)) return false;
    if (std::regex_search(full, std::regex("%-")) && !t.is_valid(i/2)) return false;
    return true;
  }
  void print_def(std::ostream& output, Type t, int i) const {
    if (!is_valid(t, i)) return;
    if (macro) {
      output << "#define " << t.prefix(i) << "_" << expand_type_pattern(name, t, i) << "(";
      bool comma = false;
      for (const Arg arg : args) {
        if (comma) output << ", ";
        comma = true;
        output << arg.name;
      }
      output << ") " << expand_type_pattern(def, t, i) << "\n";
    } else {
      output << "inline " << expand_type_pattern(rettype, t, i) << " __" << t.prefix(i) << "_" << expand_type_pattern(name, t, i) << "(";
      bool comma = false;
      for (const Arg arg : args) {
        if (comma) output << ", ";
        comma = true;
        output << arg.str(t, i);
      }
      output << ") { " << expand_type_pattern(def, t, i) << " }\n";
    }
  }
  void print_declaration(std::ostream& output, Type t, int i) const {
    if (!is_valid(t, i)) return;
    output << "inline " << expand_type_pattern(rettype, t, i) << " __" << t.prefix(i) << "_" << expand_type_pattern(name, t, i) << "(";
    bool comma = false;
    for (const Arg arg : args) {
      if (comma) output << ", ";
      comma = true;
      output << arg.str(t, i);
    }
    output << ");\n";
  }
  void print_define(std::ostream& output, Type t, int i) const {
    if (!t.is_valid(i)) return;
    output << "#define " << t.prefix(i) << "_" << expand_type_pattern(name, t, i) << " __" << t.prefix(i) << "_" << expand_type_pattern(name, t, i) << "\n";
  }
};

const Args NO_ARG;
const Args TONE_ARG = {{"%T", "a"}};
const Args TTWO_ARGS = {{"%T", "a"},{"%T", "b"}};
const Args TTHREE_ARGS = {{"%T", "a"},{"%T", "b"},{"%T", "c"}};
const Args ONE_ARG = {{"%P", "a"}};
const Args TWO_ARGS = {{"%P", "a"},{"%P", "b"}};
const Args THREE_ARGS = {{"%P", "a"},{"%P", "b"},{"%P", "c"}};

//const Function NOT  = {"%T", "not",  TONE_ARG,  "%T r = { i: ~a.i }; return r;"};
const Function AND  = {"%T", "and",  TTWO_ARGS, "%T r = { i: a.i & b.i }; return r;"};
const Function OR   = {"%T", "or ",  TTWO_ARGS, "%T r = { i: a.i | b.i }; return r;"};
const Function XOR  = {"%T", "xor",  TTWO_ARGS, "%T r = { i: a.i ^ b.i }; return r;"};
const Function EQ   = {"%T", "eq ",  TTWO_ARGS, "%T r = { i: -(a.v == b.v) }; return r;"};
const Function NEQ  = {"%T", "neq",  TTWO_ARGS, "%T r = { i: -(a.v != b.v) }; return r;"};
const Function GT   = {"%T", "gt ",  TTWO_ARGS, "%T r = { i: -(a.v >  b.v) }; return r;"};
const Function GEQ  = {"%T", "geq",  TTWO_ARGS, "%T r = { i: -(a.v >= b.v) }; return r;"};
const Function LT   = {"%T", "lt ",  TTWO_ARGS, "%T r = { i: -(a.v <  b.v) }; return r;"};
const Function LEQ  = {"%T", "leq",  TTWO_ARGS, "%T r = { i: -(a.v <= b.v) }; return r;"};
const Function ADD  = {"%T", "add",  TTWO_ARGS, "%T r = { a.v +  b.v }; return r;"};
const Function SUB  = {"%T", "sub",  TTWO_ARGS, "%T r = { a.v -  b.v }; return r;"};
const Function MUL  = {"%T", "mul",  TTWO_ARGS, "%T r = { a.v *  b.v }; return r;"};
const Function DIV  = {"%T", "div",  TTWO_ARGS, "%T r = { a.v /  b.v }; return r;"};
const Function SQRT = {"%T", "sqrt", TONE_ARG,  "%T r = { sqrt(a.v) }; return r;"};
//const Function ZERO   = {"%T",   "zero",   NO_ARG,         "%T r = { 0 }; return r;"};
//const Function SET    = {"%T",   "set  ",  {{"%t ", "v"}}, "%T r = { v  }; return r;", nullptr};
const Function SET1   = {"%T",   "set1 ",  {{"%t ", "v"}}, "%T r = { v  }; return r;"};
const Function LOAD   = {"%T",   "load ",  {{"const %t*", "p"}}, "%T r = { *p }; return r;", "return %P_merge_%-P(%-P_load(p), %-P_load(p+%-N));"};
//const Function LOADU  = {"%T",   "loadu",  {{"const %t*", "p"}}, "%T r = { *p }; return r;", "%T r = { a: %-P_loadu(p), b: %-P_loadu(p+%-N) }; return r;"};
//const Function LOAD1  = {"%T",   "load1",  {{"const %t*", "p"}}, "%T r = { *p }; return r;"};
const Function STORE  = {"void", "store ", {{"%t*", "p"}, {"%T", "a"}}, "*p = a.v;", "%-P_store (p, %-P_get_low_%P(a)); %-P_store (p+%-N, %-P_get_high_%P(a));"};
//const Function STOREU = {"void", "storeu", {{"%t*", "p"}, {"%T", "a"}}, "*p = a.v;", "%-P_storeu(p, a.a); %-P_storeu(p+%-N, a.b);"};
//const Function ISZERO = {"int",  "is_zero", {{"%T", "a"}}, "return a.v == 0;", "return %-P_is_zero(a.a) && %-P_is_zero(a.b);"};
const Function FUNCTIONS[] = {
  /*NOT,*/ AND, OR, XOR,
  EQ, NEQ, GT, GEQ, LT, LEQ,
  ADD, SUB, MUL, DIV, SQRT,
  /*ZERO, SET,*/ SET1, LOAD, /*LOADU, LOAD1,*/ STORE//, //STOREU//,
  //ISZERO
};

//const HelperFunction AND    = {"%P", "and",    TWO_ARGS, "\n"
//"  int i;\n"
//"  %it va[%N], vb[%N];\n"
//"  %P_storeu((%t*) va, a);\n"
//"  %P_storeu((%t*) vb, b);\n"
//"  for (i = 0; i < %N; i++) va[i] &= vb[i];\n"
//"  return %P_loadu((%t*) va);\n"
//, false};
//const HelperFunction OR     = {"%P", "or",     TWO_ARGS, "\n"
//"  int i;\n"
//"  %it va[%N], vb[%N];\n"
//"  %P_storeu((%t*) va, a);\n"
//"  %P_storeu((%t*) vb, b);\n"
//"  for (i = 0; i < %N; i++) va[i] |= vb[i];\n"
//"  return %P_loadu((%t*) va);\n"
//, false};
//const HelperFunction XOR    = {"%P", "xor",    TWO_ARGS, "\n"
//"  int i;\n"
//"  %it va[%N], vb[%N];\n"
//"  %P_storeu((%t*) va, a);\n"
//"  %P_storeu((%t*) vb, b);\n"
//"  for (i = 0; i < %N; i++) va[i] ^= vb[i];\n"
//"  return %P_loadu((%t*) va);\n"
//, false};
//
//const HelperFunction EQ     = {"%P", "eq",     TWO_ARGS, "\n"
//"  int i;\n"
//"  %it va[%N], vb[%N];\n"
//"  %P_storeu((%t*) va, a);\n"
//"  %P_storeu((%t*) vb, b);\n"
//"  for (i = 0; i < %N; i++) va[i] = -(va[i] == vb[i]);\n"
//"  return %P_loadu((%t*) va);\n"
//, false};
//
//const HelperFunction NEQ    = {"%P", "neq",    TWO_ARGS, "\n"
//"  int i;\n"
//"  %it va[%N], vb[%N];\n"
//"  %P_storeu((%t*) va, a);\n"
//"  %P_storeu((%t*) vb, b);\n"
//"  for (i = 0; i < %N; i++) va[i] = -(va[i] != vb[i]);\n"
//"  return %P_loadu((%t*) va);\n"
//, false};
//
//const HelperFunction GT     = {"%P", "gt",     TWO_ARGS, "\n"
//"  int i;\n"
//"  %it va[%N], vb[%N];\n"
//"  %P_storeu((%t*) va, a);\n"
//"  %P_storeu((%t*) vb, b);\n"
//"  for (i = 0; i < %N; i++) va[i] = -(va[i] >  vb[i]);\n"
//"  return %P_loadu((%t*) va);\n"
//, false};
//
//const HelperFunction GEQ    = {"%P", "geq",    TWO_ARGS, "\n"
//"  int i;\n"
//"  %it va[%N], vb[%N];\n"
//"  %P_storeu((%t*) va, a);\n"
//"  %P_storeu((%t*) vb, b);\n"
//"  for (i = 0; i < %N; i++) va[i] = -(va[i] >= vb[i]);\n"
//"  return %P_loadu((%t*) va);\n"
//, false};
//
//const HelperFunction LT     = {"%P", "lt",     TWO_ARGS, "\n"
//"  int i;\n"
//"  %it va[%N], vb[%N];\n"
//"  %P_storeu((%t*) va, a);\n"
//"  %P_storeu((%t*) vb, b);\n"
//"  for (i = 0; i < %N; i++) va[i] = -(va[i] <  vb[i]);\n"
//"  return %P_loadu((%t*) va);\n"
//, false};
//
//const HelperFunction LEQ    = {"%P", "leq",    TWO_ARGS, "\n"
//"  int i;\n"
//"  %it va[%N], vb[%N];\n"
//"  %P_storeu((%t*) va, a);\n"
//"  %P_storeu((%t*) vb, b);\n"
//"  for (i = 0; i < %N; i++) va[i] = -(va[i] <= vb[i]);\n"
//"  return %P_loadu((%t*) va);\n"
//, false};
//const HelperFunction ADD    = {"%P", "add",    TWO_ARGS, "\n"
//"  int i;\n"
//"  %t va[%N], vb[%N];\n"
//"  %P_storeu(va, a);\n"
//"  %P_storeu(vb, b);\n"
//"  for (i = 0; i < %N; i++) va[i] += vb[i];\n"
//"  return %P_loadu(va);\n"
//, false};
//const HelperFunction SUB    = {"%P", "sub",    TWO_ARGS, "\n"
//"  int i;\n"
//"  %t va[%N], vb[%N];\n"
//"  %P_storeu(va, a);\n"
//"  %P_storeu(vb, b);\n"
//"  for (i = 0; i < %N; i++) va[i] -= vb[i];\n"
//"  return %P_loadu(va);\n"
//, false};
//const HelperFunction MUL    = {"%P", "mul",    TWO_ARGS, "\n"
//"  int i;\n"
//"  %t va[%N], vb[%N];\n"
//"  %P_storeu(va, a);\n"
//"  %P_storeu(vb, b);\n"
//"  for (i = 0; i < %N; i++) va[i] *= vb[i];\n"
//"  return %P_loadu(va);\n"
//, false};
//const HelperFunction DIV    = {"%P", "div",    TWO_ARGS, "\n"
//"  int i;\n"
//"  %t va[%N], vb[%N];\n"
//"  %P_storeu(va, a);\n"
//"  %P_storeu(vb, b);\n"
//"  for (i = 0; i < %N; i++) va[i] /= vb[i];\n"
//"  return %P_loadu(va);\n"
//, false};
//const HelperFunction SQRT   = {"%P", "sqrt",    ONE_ARG, "\n"
//"  int i;\n"
//"  %t va[%N];\n"
//"  %P_storeu(va, a);\n"
//"  for (i = 0; i < %N; i++) va[i] = sqrt(va[i]);\n"
//"  return %P_loadu(va);\n"
//, false};
const HelperFunction ISZERO = {"int", "is_zero",    ONE_ARG, "\n"
"  int i, b = 1;\n"
"  %t va[%N];\n"
"  %P_storeu(va, a);\n"
"  for (i = 0; i < %N; i++) b = b && !va[i];\n"
"  return b;\n"
, false};
const HelperFunction ZERO   = {"%P", "zero",   NO_ARG,  "%P_set1(0)"};
const HelperFunction NOT    = {"%P", "not",    ONE_ARG, "%P_cast_%iP(%iP_xor(%iP_set1(-1), %iP_cast_%P(a)))"};
const HelperFunction NEG    = {"%P", "neg",    ONE_ARG, "%P_sub(%P_set1(0), a)"};
const HelperFunction NOR    = {"%P", "nor",    TWO_ARGS,"%P_not(%P_or (a, b))"};
const HelperFunction ORNOT  = {"%P", "ornot",  TWO_ARGS,"%P_or (a, %P_not(b))"};
const HelperFunction NAND   = {"%P", "nand",   TWO_ARGS,"%P_not(%P_and(a, b))"};
const HelperFunction ANDNOT = {"%P", "andnot", TWO_ARGS,"%P_and(a, %P_not(b))"};
const HelperFunction ISONES = {"int", "is_ones", ONE_ARG, "%P_is_zero(%P_not(a))"};
const HelperFunction FMADD  = {"%P", "fmadd",  THREE_ARGS, "%P_add(%P_mul(a, b), c)"};
const HelperFunction FMSUB  = {"%P", "fmsub",  THREE_ARGS, "%P_fmadd(a, b, %P_neg(c))"};
const HelperFunction FNMADD = {"%P", "fnmadd", THREE_ARGS, "%P_neg(%P_fmadd(a, b, c))"};
const HelperFunction FNMSUB = {"%P", "fnmsub", THREE_ARGS, "%P_neg(%P_fmsub(a, b, c))"};
const HelperFunction RCP    = {"%P", "rcp",    ONE_ARG, "%P_div(%P_set1(1), a)"};
const HelperFunction FRCP   = {"%P", "frcp",   ONE_ARG, "%P_rcp(a)"};
const HelperFunction RSQRT  = {"%P", "rsqrt",  ONE_ARG, "%P_div(%P_set1(1), %P_sqrt(a))"};
const HelperFunction FRSQRT = {"%P", "frsqrt", ONE_ARG, "%P_rsqrt(a)"};
const HelperFunction MLOAD  = {"%P", "mload",  {{"const %t*", "p"}, {"%iT", "mask"}}, "%P_and(%P_load (p), %P_cast_%iP(mask))"};
const HelperFunction MLOADU = {"%P", "mloadu", {{"const %t*", "p"}, {"%iT", "mask"}}, "%P_and(%P_loadu(p), %P_cast_%iP(mask))"};
const HelperFunction FPRINT = {"void", "fprint", {{"void*", "f"},{"%P", "a"}}, "\n"
"  %t vec[%N];\n"
"  int i, comma = 0;\n"
"  %P_storeu(vec, a);\n"
"  for (i = 0; i < %N; i++) {\n"
"    if (comma) fprintf(f, \"\t\");\n"
"    comma = 1;\n"
"    fprintf(f, \"%f\", vec[%N-i-1]);\n"
"  }\n"
, false};
const HelperFunction PRINT = {"void", "print", {{"%P", "a"}}, "%P_fprint(stdout, a);", false};
const HelperFunction SHUFFLE = {"%P", "shuffle", {{"%P", "a"}, {"%P", "b"}, {"int", "imm8"}}, "%P_intel_shuffle(a, b, imm8)"};
const HelperFunction IPERMUTE = {"%P", "intel_permute", {{"%P", "a"}, {"int", "imm8"}}, "%P_shuffle(a, a, imm8)"};
const HelperFunction PERMUTE = {"%P", "permute", {{"%P", "a"}, {"int", "imm8"}}, "%P_intel_permute(a, imm8)"};
//const HelperFunction GETLOW  = {"%P", "get_low_%+P", {{"%+P", "a"}}, "%P_cast_%+P(a)"};
const HelperFunction GETLOW  = {"%P", "get_low_%+P", {{"%+T", "a"}}, "return a.a;", false};
const HelperFunction GETHIGH  = {"%P", "get_high_%+P", {{"%+T", "a"}}, "return a.b;", false};
const HelperFunction SETLOW  = {"%T", "set_low_%-P", {{"%T", "src"}, {"%-P", "a"}}, "src.a = a; return src;", false};
const HelperFunction SETHIGH  = {"%T", "set_high_%-P", {{"%T", "src"}, {"%-P", "a"}}, "src.b = a; return src;", false};
const HelperFunction MERGE    = {"%T", "merge_%-P", {{"%-P", "a"}, {"%-P", "b"}}, "%T r = { a: a, b: b }; return r;", false};
const HelperFunction CGETLOW  = {"%P", "compatible_get_low_%+P", {{"%+P", "a"}}, "\n"
"  %t va[%+N];\n"
"  %+P_storeu(va, a);\n"
"  return %P_loadu(va);\n"
, false};
const HelperFunction CGETHIGH = {"%P", "compatible_get_high_%+P", {{"%+P", "a"}}, "\n"
"  %t va[%+N];\n"
"  %+P_storeu(va, a);\n"
"  return %P_loadu(&va[%N]);\n"
, false};
const HelperFunction GETHILO = {"%P", "get_hilo_%+P", {{"%+P", "a"}, {"int", "high"}}, "(high ? %P_get_high_%+P(a) : %P_get_low_%+P(a))"};
const HelperFunction CSETLOW = {"%P", "compatible_set_low_%-P", {{"%P", "src"}, {"%-P", "a"}}, "\n"
"  %t v[%N];\n"
"  %P_storeu(v, src);\n"
"  %-P_storeu(v, a);\n"
"  return %P_loadu(v);\n"
, false};
const HelperFunction CSETHIGH = {"%P", "compatible_set_high_%-P", {{"%P", "src"}, {"%-P", "a"}}, "\n"
"  %t v[%N];\n"
"  %P_storeu(v, src);\n"
"  %-P_storeu(&v[%-N], a);\n"
"  return %P_loadu(v);\n"
, false};
const HelperFunction SETHILO = {"%P", "set_hilo_%-P", {{"%P", "src"}, {"%-P", "a"}, {"int", "high"}}, "(high ? %P_set_high_%-P(src, a) : %P_set_low_%-P(src, a))"};
const HelperFunction CMERGE = {"%P", "compatible_merge_%-P", {{"%-P", "a"}, {"%-P", "b"}}, "\n"
"  %t v[%N];\n"
"  %-P_storeu(&v[0], a);\n"
"  %-P_storeu(&v[%-N], b);\n"
"  return %P_loadu(v);\n"
, false};
const HelperFunction LOAD1 = {"%P", "load1", {{"%t*", "p"}}, "%P_set1(*(p))"};
const HelperFunction LOADU = {"%P", "loadu", {{"%t*", "p"}}, "%P_load(p)"};
const HelperFunction STOREU = {"void", "storeu", {{"%t*", "p"}, {"%P", "a"}}, "%P_store(p, a)"};

const HelperFunction HELPERS[] = {
  /*AND, OR, XOR,
  EQ, NEQ, GT, GEQ, LT, LEQ,
  ADD, SUB, MUL, DIV, SQRT,*/
  ZERO, /*SET1,*/
  ISZERO, NOT,
  NEG, NOR, ORNOT, NAND, ANDNOT, ISONES,
  FMADD, FMSUB, FNMADD, FNMSUB,
  RCP, FRCP, RSQRT, FRSQRT,
  MLOAD, MLOADU,
  GETHIGH, GETLOW, SETLOW, SETHIGH, MERGE,
  CGETHIGH, CGETLOW, CSETLOW, CSETHIGH, CMERGE,
  GETHILO, SETHILO, SHUFFLE, IPERMUTE, PERMUTE,
  LOAD1, LOADU, STOREU,
  FPRINT, PRINT
};

void generate_set_intern(std::ostream& output) {
  bool comma;
  for (int i : SIZES) {
    for (const Type t : TYPES) {
      if (!t.is_valid(i)) continue;
      output << "inline " << t.prefix(i) << " __" << t.prefix(i) << "_set(";
      comma = false;
      for (int j = 0; j < i; ++j) {
        if (comma) output << ", ";
        comma = true;
        output << t.name << " a" << i-1-j;
      }
      output << ") {\n";
      output << "  " << t.name << " vec[" << i << "] = {";
      comma = false;
      for (int j = 0; j < i; ++j) {
        if (comma) output << ", ";
        comma = true;
        output << "a" << j;
      }
      output << "};\n";
      output << "  return " << t.prefix(i) << "_loadu(vec);\n}\n";
    }
  }
}

void generate_set_defines(std::ostream& output) {
  bool comma;
  for (int i : SIZES) {
    for (const Type t : TYPES) {
      if (!t.is_valid(i)) continue;
      output << "#define " << t.prefix(i) << "_set(";
      comma = false;
      for (int j = 0; j < i; ++j) {
        if (comma) output << ", ";
        comma = true;
        output << "a" << i-j-1;
      }
      output << ") __" << t.prefix(i) << "_set(";
      comma = false;
      for (int j = 0; j < i; ++j) {
        if (comma) output << ", ";
        comma = true;
        output << "a" << i-j-1;
      }
      output << ")\n";


      output << "#define " << t.prefix(i) << "_setr(";
      comma = false;
      for (int j = 0; j < i; ++j) {
        if (comma) output << ", ";
        comma = true;
        output << "a" << j;
      }
      output << ") " << t.prefix(i) << "_set(";
      comma = false;
      for (int j = 0; j < i; ++j) {
        if (comma) output << ", ";
        comma = true;
        output << "a" << i-j-1;
      }
      output << ")\n";
    }
  }
}

void generate_size1_structs(std::ostream& output) {
  output << "// 1 element vectors\n";
  for (const Type t : TYPES) {
    output << t.union_name() << " {\n";
    output << "  " << t.name << " v;\n";
    output << "  " << t.inttype->name << " i;\n";
    output << "};\n";
  }
  output << "\n";
}

void generate_cvt_intern(std::ostream& output, int i) {
  for (const Type from : TYPES) {
    for (const Type to : TYPES) {
      if (!from.is_valid(i) || !to.is_valid(i)) continue;
      output << "inline " << to.prefix(i) << " __" << to.prefix(i) << "_cvt_" << from.prefix(i) << "(" << from.prefix(i) << " a) {\n";
      output << "  " << from.name << " src[" << i << "];\n";
      output << "  " <<   to.name << " dst[" << i << "];\n";
      output << "  int i;\n";
      output << "  " << from.prefix(i) << "_storeu(src, a);\n";
      output << "  for (i = 0; i < " << i << "; i++) dst[i] = src[i];\n";
      output << "  return " << to.prefix(i) << "_loadu(dst);\n";
      output << "}\n";
    }
  }
}

void generate_cvt_defines(std::ostream& output) {
  for (int i : SIZES) {
    for (int j : SIZES) {
      for (const Type from : TYPES) {
        for (const Type to : TYPES) {
          if (!from.is_valid(i) || !to.is_valid(j)) continue;
          output << "#define " << to.prefix(j) << "_cvt_" << from.prefix(i) << "(a) ";
          if (from.letter == to.letter) {
            output << to.prefix(j) << "_cast_" << from.prefix(i) << "(a)";
          } else if (i == j) {
            output << "__" << to.prefix(j) << "_cvt_" << from.prefix(i) << "(a)";
          } else if (i < j) {
            output << to.prefix(j) << "_cast_" << to.prefix(i) << "(" << to.prefix(i) << "_cvt_" << from.prefix(i) << "(a))";
          } else if (i > j) {
            output << to.prefix(j) << "_cvt_" << from.prefix(j) << "(" << from.prefix(j) << "_cast_" << from.prefix(i) << "(a))";
          }
          output << "\n";
        }
      }
    }
  }
}

void generate_cast_intern(std::ostream& output, int i) {
  for (const Type from : TYPES) {
    if (from.is_valid(i)) {
      if (i != 1) {
        output << "inline " << from.prefix(i/2) << " __" << from.prefix(i/2) << "_cast_" << from.prefix(i);
        output << "(" << from.intern_name(i) << " a) { ";
        output << "return a.a;";
        output << " }\n";
        output << "inline " << from.intern_name(i) << " __" << from.prefix(i) << "_cast_" << from.prefix(i/2);
        output << "(" << from.prefix(i/2) << " a) { ";
        output << from.intern_name(i) << " r = { a: a }; return r;";
        output << " }\n";
      } else {
        output << "inline " << from.name << " __" << from.letter << "_cast_" << from.prefix(1);
        output << "(" << from.intern_name(1) << " a) { return a.v; }\n";
      }
    }
    for (const Type to : TYPES) {
      if (from.size == to.size) {
        if (!from.is_valid(i) || !to.is_valid(i)) continue;
        output << "inline " << to.prefix(i) << " __" << to.prefix(i) << "_cast_" << from.prefix(i);
        output << "(" << from.prefix(i) << " a) { ";
        output << "return *((" << to.prefix(i) << "*) &a);";
        output << " }\n";
      } else if (from.size == to.size/2) {
        if (!from.is_valid(i) || !to.is_valid(i/2)) continue;
        if (i == 1) continue;
        output << "inline " << to.prefix(i/2) << " __" << to.prefix(i/2) << "_cast_" << from.prefix(i);
        output << "(" << from.prefix(i) << " a) { ";
        output << "return *((" << to.prefix(i/2) << "*) &a);";
        output << " }\n";
      } else if (from.size == to.size*2) {
        if (!from.is_valid(i/2) || !to.is_valid(i)) continue;
        if (i == 1) continue;
        output << "inline " << to.prefix(i) << " __" << to.prefix(i) << "_cast_" << from.prefix(i/2);
        output << "(" << from.prefix(i/2) << " a) { ";
        output << "return *((" << to.prefix(i) << "*) &a);";
        output << " }\n";
      }
    }
  }
}

void generate_cast_defines(std::ostream& output) {
  for (int i : SIZES) {
    for (int j : SIZES) {
      for (const Type from : TYPES) {
        for (const Type to : TYPES) {
          if (!from.is_valid(i) || !to.is_valid(j)) continue;
          std::stringstream ss;
          ss << "#define " << to.prefix(j) << "_cast_" << from.prefix(i) << "(a) ";
          if (from.letter == to.letter) {
            const Type t = from;
            if (i == j) {
              ss << "(a)";
            } else if (i == j*2) {
              ss << "__" << t.prefix(j) << "_cast_" << t.prefix(i) << "(a)";
            } else if (i == j/2) {
              ss << "__" << t.prefix(j) << "_cast_" << t.prefix(i) << "(a)";
            } else if (i < j) {
              ss << t.prefix(j) << "_cast_" << t.prefix(j/2) << "(" << t.prefix(j/2) << "_cast_" << t.prefix(i) << "(a))";
            } else if (i > j) {
              ss << t.prefix(j) << "_cast_" << t.prefix(i/2) << "(" << t.prefix(i/2) << "_cast_" << t.prefix(i) << "(a))";
            }
          } else {
            if (from.size == to.size) {
              if (i == j) {
                ss << "__" << to.prefix(j) << "_cast_" << from.prefix(i) << "(a)";
              } else if (i < j) {
                ss << to.prefix(j) << "_cast_" << to.prefix(i) << "(" << to.prefix(i) << "_cast_" << from.prefix(i) << "(a))";
              } else if (i > j) {
                ss << to.prefix(j) << "_cast_" << from.prefix(j) << "(" << from.prefix(j) << "_cast_" << from.prefix(i) << "(a))";
              }
            } else if (from.size == to.size/2) {
              if (i == j*2) {
                ss << "__" << to.prefix(j) << "_cast_" << from.prefix(i) << "(a)";
              } else if (i < j*2) {
                if (i == 1) continue;
                ss << to.prefix(j) << "_cast_" << to.prefix(i/2) << "(" << to.prefix(i/2) << "_cast_" << from.prefix(i) << "(a))";
              } else if (i > j*2) {
                ss << to.prefix(j) << "_cast_" << from.prefix(j*2) << "(" << from.prefix(j*2) << "_cast_" << from.prefix(i) << "(a))";
              }
            } else if (from.size == to.size*2) {
              if (i == j/2) {
                ss << "__" << to.prefix(j) << "_cast_" << from.prefix(i) << "(a)";
              } else if (i < j/2) {
                ss << to.prefix(j) << "_cast_" << to.prefix(i*2) << "(" << to.prefix(i*2) << "_cast_" << from.prefix(i) << "(a))";
              } else if (i > j/2) {
                if (j == 1) continue;
                ss << to.prefix(j) << "_cast_" << from.prefix(j/2) << "(" << from.prefix(j/2) << "_cast_" << from.prefix(i) << "(a))";
              }
            }
          }
          ss << "\n";
          output << ss.str();
        }
      }
    }
  }
}

void generate_intel_shuffle_intern(std::ostream& output) {
  for (int i : SIZES) {
    for (const Type t : TYPES32) {
      if (!t.is_valid(i)) continue;
      if (i != 4) continue;
      std::string merge1 = t.prefix(i) + "_merge_" + t.prefix(i/2);
      std::string merge2 = t.prefix(i/2) + "_merge_" + t.prefix(i/4);
      std::string getLow = t.prefix(i/2) + "_get_low_" + t.prefix(i);
      std::string getHigh = t.prefix(i/2) + "_get_high_" + t.prefix(i);

      output << "inline " << t.prefix(i) << " __" << t.prefix(i) << "_intel_shuffle(";
      output << t.prefix(i) << " a, " << t.prefix(i) << " b, const int imm8) {\n";
      output << "  " << t.prefix(i) << " src;\n";
      output << "  " << t.prefix(i/4) << " dst[4];\n";
      output << "  int i, ctrl;\n";
      output << "  for (i = 0; i < 4; i++) {\n";
      output << "    ctrl = (imm8 >> (i*2)) & 0x3;\n";
      output << "    src = (i < 2) ? a : b;\n";
      output << "    dst[i] = " << t.prefix(i/4) << "_get_hilo_" << t.prefix(i/2) << "(";
      output << t.prefix(i/2) << "_get_hilo_" << t.prefix(i) << "(";
      output << "src, ctrl&2), ctrl&1);\n";
      output << "  }\n";
      output << "  return " << merge1 << "(" << merge2 << "(dst[0], dst[1]), " << merge2 << "(dst[2], dst[3]));\n";
      output << "}\n";
    }
    for (const Type t : TYPES64) {
      if (!t.is_valid(i)) continue;
      if (i != 2) continue;
      std::string merge = t.prefix(i) + "_merge_" + t.prefix(i/2);
      std::string getLow = t.prefix(i/2) + "_get_low_" + t.prefix(i);
      std::string getHigh = t.prefix(i/2) + "_get_high_" + t.prefix(i);
      std::string getHiLo = t.prefix(i/2) + "_get_hilo_" + t.prefix(i);

      output << "inline " << t.prefix(i) << " __" << t.prefix(i) << "_intel_shuffle(";
      output << t.prefix(i) << " a, " << t.prefix(i) << " b, const int imm8) { ";
      output << "return " << merge << "(";
      output << getHiLo << "(a,  imm8       & 1), ";
      output << getHiLo << "(b, (imm8 >> 1) & 1)";
      output << "); }";
    }
  }
}

void generate_intel_shuffle_defines(std::ostream& output) {
  for (int i : SIZES) {
    for (const Type t : TYPES) {
      if (!t.is_valid(i)) continue;
      if (i < 16 / t.size) continue;
      output << "#define " << t.prefix(i) << "_intel_shuffle __" << t.prefix(i) << "_intel_shuffle\n";
      if (i == 16 / t.size) continue;
      std::string merge = t.prefix(i) + "_merge_" + t.prefix(i/2);
      std::string getLow = t.prefix(i/2) + "_get_low_" + t.prefix(i);
      std::string getHigh = t.prefix(i/2) + "_get_high_" + t.prefix(i);
      std::string getHiLo = t.prefix(i/2) + "_get_hilo_" + t.prefix(i);
      output << "#define __" << t.prefix(i) << "_intel_shuffle(a, b, imm8) ";
      output << merge << "(";
      output << t.prefix(i/2) << "_intel_shuffle(" << getLow  << "(a), " << getLow  << "(b), imm8), ";
      output << t.prefix(i/2) << "_intel_shuffle(" << getHigh << "(a), " << getHigh << "(b), imm8)";
      output << ")\n";
    }
  }
}


void generate_size1_funcs(std::ostream& output) {
  output << "// 1 element vectors functions\n";
  for (const Function f : FUNCTIONS) {
    for (const Type t : TYPES) {
      f.print_def(output, t);
    }
    output << "\n";
  }
  output << "\n";
}

void declare_funcs(std::ostream& output) {
  for (int i : SIZES) {
    for (const Function f : FUNCTIONS) {
      for (const Type t : TYPES) {
        f.print_declaration(output, t, i);
      }
    }
    for (const HelperFunction f : HELPERS) {
      if (f.macro) continue;
      for (const Type t : TYPES) {
        f.print_declaration(output, t, i);
      }
    }
  }
}

void generate_struct_define(std::ostream& output, int i) {
  //output << "// Aliases for internal vector struct\n";
  for (const Type t : TYPES) {
    if (!t.is_valid(i)) continue;
    output << "#define " << t.prefix(i) << " " << t.intern_name(i) << "\n";
  }
}

void generate_func_define(std::ostream& output, int i) {
  for (const Function f : FUNCTIONS) {
    for (const Type t : TYPES) {
      f.print_define(output, t, i);
    }
  }
}

void widen_vector(std::ostream& output, int i) {
  for (const Type t : TYPES) {
    if (!t.is_valid(i)) continue;
    output << t.intern_name(i) << " { " << t.prefix(i/2) << " a, b; };\n";
  }
}

void widen_funcs(std::ostream& output, int i) {
  if (i == 0) return;
  for (const Function f : FUNCTIONS) {
    for (const Type t : TYPES) {
      if (!t.is_valid(i)) continue;
      f.print_wider(output, t, i);
    }
    if (f.widenrule) output << "\n";
  }
}

void generate_helpers(std::ostream& output, int i, bool macro) {
  for (const HelperFunction f : HELPERS) {
    for (const Type t : TYPES) {
      if (!f.is_valid(t, i)) continue;
      if ((macro && f.macro) || (!macro && !f.macro)) {
        f.print_def(output, t, i);
      } else if (macro) {
        f.print_define(output, t, i);
      }
    }
    output << "\n";
  }
}

void append_file(std::ostream& output, const std::string& filename) {
  std::ifstream file(filename);
  output << file.rdbuf();
}


void generate_defines() {
  std::ofstream output(output_filename1);
  append_file(output, header_filename1);

  generate_cast_defines(output);
  generate_cvt_defines(output);
  generate_set_defines(output);
  generate_intel_shuffle_defines(output);

  output << "// Aliases for internal structs\n";
  for (int size : SIZES) {
    generate_struct_define(output, size);
  }
  output << "\n// Aliases for internal functions\n";
  for (int size : SIZES) {
    generate_func_define(output, size);
  }
  output << "\n// Helpers\n";
  for (int size : SIZES) {
    generate_helpers(output, size, true);
  }
  output << "\n";

  append_file(output, footer_filename1);
}


void generate_funcs() {
  std::ofstream output(output_filename2);
  append_file(output, header_filename2);


  generate_size1_structs(output);
  output << "\n// Internal wider vectors\n";
  for (int size : SIZES) {
    if (size == 1) continue;
    widen_vector(output, size);
  }
  declare_funcs(output);
  output << "\n// Casts\n";
  for (int size : SIZES) {
    generate_cast_intern(output, size);
  }
  output << "\n// Conversions\n";
  for (int size : SIZES) {
    generate_cvt_intern(output, size);
  }
  generate_set_intern(output);
  output << "\n";
  generate_intel_shuffle_intern(output);
  generate_size1_funcs(output);
  output << "\n// Internal wider functions\n";
  for (int size : SIZES) {
    if (size == 1) continue;
    widen_funcs(output, size);
  }
  output << "\n// Helpers\n";
  for (int size : SIZES) {
    generate_helpers(output, size, false);
  }
  output << "\n";

  append_file(output, footer_filename2);
}

int main() {
  generate_defines();
  generate_funcs();
  return 0;
}
