#ifndef PINTS_HELPER_H
#define PINTS_HELPER_H
//include/pints-helper.h

#define PINTS_ALIGN_UP(p, a) ((void*) ((((uintptr_t) p) + a-1) & ~(a-1)))
#define PINTS_ALIGN_DOWN(p, a) ((void*) (((uintptr_t) p) & ~(a-1)))

#define PINTS_ALIGNED_ARRAY(type, name, size, align) \
  type name##_unaligned[(size) + (align)]; \
  type *name = (type*)PINTS_ALIGN_UP(name##_unaligned, align)

#define PINTS_REINTERPRET(to_t, from_t, v) (((union { from_t from; to_t to; }) { from: (v) }).to)

#define __PINTS_PP_CAT(a, b) a##b
#define PINTS_PP_CAT(a, b) __PINTS_PP_CAT(a, b)

#define PINTS_PP_NARGS(...) __PINTS_PP_NARGS(__VA_ARGS__, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)
#define __PINTS_PP_NARGS(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, N, ...) N

#define ___PINTS_2BITS_TO_B4(b1, b0) __PINTS_2BITS_TO_B4_##b1##b0
#define __PINTS_2BITS_TO_B4(b1, b0) ___PINTS_2BITS_TO_B4(b1, b0)
#define __PINTS_2BITS_TO_B4_00 0
#define __PINTS_2BITS_TO_B4_01 1
#define __PINTS_2BITS_TO_B4_10 2
#define __PINTS_2BITS_TO_B4_11 3

#define ___PINTS_3BITS_TO_OCTAL(b2, b1, b0) __PINTS_3BITS_TO_OCTAL_##b2##b1##b0
#define __PINTS_3BITS_TO_OCTAL(b2, b1, b0) ___PINTS_3BITS_TO_OCTAL(b2, b1, b0)
#define __PINTS_3BITS_TO_OCTAL_000 0
#define __PINTS_3BITS_TO_OCTAL_001 1
#define __PINTS_3BITS_TO_OCTAL_010 2
#define __PINTS_3BITS_TO_OCTAL_011 3
#define __PINTS_3BITS_TO_OCTAL_100 4
#define __PINTS_3BITS_TO_OCTAL_101 5
#define __PINTS_3BITS_TO_OCTAL_110 6
#define __PINTS_3BITS_TO_OCTAL_111 7

/* QIT: Quad digit */
#define ___PINTS_2QITS_TO_HEXA(b1, b0) __PINTS_2QITS_TO_HEXA_##b1##b0
#define __PINTS_2QITS_TO_HEXA(b1, b0) ___PINTS_2QITS_TO_HEXA(b1, b0)
#define __PINTS_2QITS_TO_HEXA_00 0
#define __PINTS_2QITS_TO_HEXA_01 1
#define __PINTS_2QITS_TO_HEXA_02 2
#define __PINTS_2QITS_TO_HEXA_03 3
#define __PINTS_2QITS_TO_HEXA_10 4
#define __PINTS_2QITS_TO_HEXA_11 5
#define __PINTS_2QITS_TO_HEXA_12 6
#define __PINTS_2QITS_TO_HEXA_13 7
#define __PINTS_2QITS_TO_HEXA_20 8
#define __PINTS_2QITS_TO_HEXA_21 9
#define __PINTS_2QITS_TO_HEXA_22 A
#define __PINTS_2QITS_TO_HEXA_23 B
#define __PINTS_2QITS_TO_HEXA_30 C
#define __PINTS_2QITS_TO_HEXA_31 D
#define __PINTS_2QITS_TO_HEXA_32 E
#define __PINTS_2QITS_TO_HEXA_33 F

#define __PINTS_4BITS_TO_HEXA(b3, b2, b1, b0) __PINTS_2QITS_TO_HEXA(__PINTS_2BITS_TO_B4(b3, b2), __PINTS_2BITS_TO_B4(b1, b0))

#define ___PINTS_DEC_TO_HEXA(d) __PINTS_DEC_TO_HEXA_##d
#define __PINTS_DEC_TO_HEXA(d) ___PINTS_DEC_TO_HEXA(d)
#define __PINTS_DEC_TO_HEXA_0  0
#define __PINTS_DEC_TO_HEXA_1  1
#define __PINTS_DEC_TO_HEXA_2  2
#define __PINTS_DEC_TO_HEXA_3  3
#define __PINTS_DEC_TO_HEXA_4  4
#define __PINTS_DEC_TO_HEXA_5  5
#define __PINTS_DEC_TO_HEXA_6  6
#define __PINTS_DEC_TO_HEXA_7  7
#define __PINTS_DEC_TO_HEXA_8  8
#define __PINTS_DEC_TO_HEXA_9  9
#define __PINTS_DEC_TO_HEXA_10 A
#define __PINTS_DEC_TO_HEXA_11 B
#define __PINTS_DEC_TO_HEXA_12 C
#define __PINTS_DEC_TO_HEXA_13 D
#define __PINTS_DEC_TO_HEXA_14 E
#define __PINTS_DEC_TO_HEXA_15 F

/* Base 2 */
#define PINTS_BASE2x0() \
  0x0
#define PINTS_BASE2x1(b0) \
  PINTS_BASE2x4(0, 0, 0, b0)
#define PINTS_BASE2x2(b1, b0) \
  PINTS_BASE2x4(0, 0, b1, b0)
#define PINTS_BASE2x3(b2, b1, b0) \
  PINTS_BASE2x4(0, b2, b1, b0)
#define PINTS_BASE2x4(b3, b2, b1, b0) \
  PINTS_PP_CAT(0x, __PINTS_4BITS_TO_HEXA(b3, b2, b1, b0))
#define PINTS_BASE2x5(b4, b3, b2, b1, b0) \
  PINTS_BASE2x8(0, 0, 0, b4, b3, b2, b1, b0)
#define PINTS_BASE2x6(b5, b4, b3, b2, b1, b0) \
  PINTS_BASE2x8(0, 0, b5, b4, b3, b2, b1, b0)
#define PINTS_BASE2x7(b6, b5, b4, b3, b2, b1, b0) \
  PINTS_BASE2x8(0, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_BASE2x8(b7, b6, b5, b4, b3, b2, b1, b0) \
  PINTS_PP_CAT(PINTS_BASE2x4(b7, b6, b5, b4), __PINTS_4BITS_TO_HEXA(b3, b2, b1, b0))
#define PINTS_BASE2x9(b8, b7, b6, b5, b4, b3, b2, b1, b0) \
  PINTS_BASE2x12(0, 0, 0, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_BASE2x10(b9, b8, b7, b6, b5, b4, b3, b2, b1, b0) \
  PINTS_BASE2x12(0, 0, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_BASE2x11(b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0) \
  PINTS_BASE2x12(0, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_BASE2x12(b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0) \
  PINTS_PP_CAT(PINTS_BASE2x8(b11, b10, b9, b8, b7, b6, b5, b4), __PINTS_4BITS_TO_HEXA(b3, b2, b1, b0))
#define PINTS_BASE2x13(b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0) \
  PINTS_BASE2x16(0, 0, 0, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_BASE2x14(b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0) \
  PINTS_BASE2x16(0, 0, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_BASE2x15(b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0) \
  PINTS_BASE2x16(0, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_BASE2x16(b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0) \
  PINTS_PP_CAT(PINTS_BASE2x12(b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4), __PINTS_4BITS_TO_HEXA(b3, b2, b1, b0))
#define PINTS_BASE2x17(b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0) \
  PINTS_BASE2x20(0, 0, 0, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_BASE2x18(b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0) \
  PINTS_BASE2x20(0, 0, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_BASE2x19(b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0) \
  PINTS_BASE2x20(0, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_BASE2x20(b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0) \
  PINTS_PP_CAT(PINTS_BASE2x16(b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4), __PINTS_4BITS_TO_HEXA(b3, b2, b1, b0))
#define PINTS_BASE2x21(b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0) \
  PINTS_BASE2x24(0, 0, 0, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_BASE2x22(b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0) \
  PINTS_BASE2x24(0, 0, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_BASE2x23(b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0) \
  PINTS_BASE2x24(0, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_BASE2x24(b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0) \
  PINTS_PP_CAT(PINTS_BASE2x20(b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4), __PINTS_4BITS_TO_HEXA(b3, b2, b1, b0))
#define PINTS_BASE2x25(b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0) \
  PINTS_BASE2x28(0, 0, 0, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_BASE2x26(b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0) \
  PINTS_BASE2x28(0, 0, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_BASE2x27(b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0) \
  PINTS_BASE2x28(0, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_BASE2x28(b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0) \
  PINTS_PP_CAT(PINTS_BASE2x24(b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4), __PINTS_4BITS_TO_HEXA(b3, b2, b1, b0))
#define PINTS_BASE2x29(b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0) \
  PINTS_BASE2x32(0, 0, 0, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_BASE2x30(b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0) \
  PINTS_BASE2x32(0, 0, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_BASE2x31(b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0) \
  PINTS_BASE2x32(0, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_BASE2x32(b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0) \
  PINTS_PP_CAT(PINTS_BASE2x28(b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4), __PINTS_4BITS_TO_HEXA(b3, b2, b1, b0))
#define PINTS_BASE2x33(b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0) \
  PINTS_BASE2x36(0, 0, 0, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_BASE2x34(b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0) \
  PINTS_BASE2x36(0, 0, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_BASE2x35(b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0) \
  PINTS_BASE2x36(0, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_BASE2x36(b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0) \
  PINTS_PP_CAT(PINTS_BASE2x32(b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4), __PINTS_4BITS_TO_HEXA(b3, b2, b1, b0))
#define PINTS_BASE2x37(b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0) \
  PINTS_BASE2x40(0, 0, 0, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_BASE2x38(b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0) \
  PINTS_BASE2x40(0, 0, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_BASE2x39(b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0) \
  PINTS_BASE2x40(0, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_BASE2x40(b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0) \
  PINTS_PP_CAT(PINTS_BASE2x36(b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4), __PINTS_4BITS_TO_HEXA(b3, b2, b1, b0))
#define PINTS_BASE2x41(b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0) \
  PINTS_BASE2x44(0, 0, 0, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_BASE2x42(b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0) \
  PINTS_BASE2x44(0, 0, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_BASE2x43(b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0) \
  PINTS_BASE2x44(0, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_BASE2x44(b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0) \
  PINTS_PP_CAT(PINTS_BASE2x40(b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4), __PINTS_4BITS_TO_HEXA(b3, b2, b1, b0))
#define PINTS_BASE2x45(b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0) \
  PINTS_BASE2x48(0, 0, 0, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_BASE2x46(b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0) \
  PINTS_BASE2x48(0, 0, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_BASE2x47(b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0) \
  PINTS_BASE2x48(0, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_BASE2x48(b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0) \
  PINTS_PP_CAT(PINTS_BASE2x44(b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4), __PINTS_4BITS_TO_HEXA(b3, b2, b1, b0))
#define PINTS_BASE2x49(b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0) \
  PINTS_BASE2x52(0, 0, 0, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_BASE2x50(b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0) \
  PINTS_BASE2x52(0, 0, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_BASE2x51(b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0) \
  PINTS_BASE2x52(0, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_BASE2x52(b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0) \
  PINTS_PP_CAT(PINTS_BASE2x48(b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4), __PINTS_4BITS_TO_HEXA(b3, b2, b1, b0))
#define PINTS_BASE2x53(b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0) \
  PINTS_BASE2x56(0, 0, 0, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_BASE2x54(b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0) \
  PINTS_BASE2x56(0, 0, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_BASE2x55(b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0) \
  PINTS_BASE2x56(0, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_BASE2x56(b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0) \
  PINTS_PP_CAT(PINTS_BASE2x52(b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4), __PINTS_4BITS_TO_HEXA(b3, b2, b1, b0))
#define PINTS_BASE2x57(b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0) \
  PINTS_BASE2x60(0, 0, 0, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_BASE2x58(b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0) \
  PINTS_BASE2x60(0, 0, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_BASE2x59(b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0) \
  PINTS_BASE2x60(0, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_BASE2x60(b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0) \
  PINTS_PP_CAT(PINTS_BASE2x56(b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4), __PINTS_4BITS_TO_HEXA(b3, b2, b1, b0))
#define PINTS_BASE2x61(b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0) \
  PINTS_BASE2x64(0, 0, 0, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_BASE2x62(b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0) \
  PINTS_BASE2x64(0, 0, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_BASE2x63(b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0) \
  PINTS_BASE2x64(0, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_BASE2x64(b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0) \
  PINTS_PP_CAT(PINTS_BASE2x60(b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4), __PINTS_4BITS_TO_HEXA(b3, b2, b1, b0))

#define PINTS_RBASE2x0() \
 PINTS_BASE2x0()
#define PINTS_RBASE2x1(b0) \
 PINTS_BASE2x1(b0)
#define PINTS_RBASE2x2(b0, b1) \
 PINTS_BASE2x2(b1, b0)
#define PINTS_RBASE2x3(b0, b1, b2) \
 PINTS_BASE2x3(b2, b1, b0)
#define PINTS_RBASE2x4(b0, b1, b2, b3) \
 PINTS_BASE2x4(b3, b2, b1, b0)
#define PINTS_RBASE2x5(b0, b1, b2, b3, b4) \
 PINTS_BASE2x5(b4, b3, b2, b1, b0)
#define PINTS_RBASE2x6(b0, b1, b2, b3, b4, b5) \
 PINTS_BASE2x6(b5, b4, b3, b2, b1, b0)
#define PINTS_RBASE2x7(b0, b1, b2, b3, b4, b5, b6) \
 PINTS_BASE2x7(b6, b5, b4, b3, b2, b1, b0)
#define PINTS_RBASE2x8(b0, b1, b2, b3, b4, b5, b6, b7) \
 PINTS_BASE2x8(b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_RBASE2x9(b0, b1, b2, b3, b4, b5, b6, b7, b8) \
 PINTS_BASE2x9(b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_RBASE2x10(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9) \
 PINTS_BASE2x10(b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_RBASE2x11(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10) \
 PINTS_BASE2x11(b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_RBASE2x12(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11) \
 PINTS_BASE2x12(b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_RBASE2x13(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12) \
 PINTS_BASE2x13(b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_RBASE2x14(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13) \
 PINTS_BASE2x14(b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_RBASE2x15(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14) \
 PINTS_BASE2x15(b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_RBASE2x16(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15) \
 PINTS_BASE2x16(b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_RBASE2x17(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16) \
 PINTS_BASE2x17(b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_RBASE2x18(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17) \
 PINTS_BASE2x18(b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_RBASE2x19(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18) \
 PINTS_BASE2x19(b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_RBASE2x20(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19) \
 PINTS_BASE2x20(b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_RBASE2x21(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20) \
 PINTS_BASE2x21(b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_RBASE2x22(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21) \
 PINTS_BASE2x22(b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_RBASE2x23(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22) \
 PINTS_BASE2x23(b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_RBASE2x24(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23) \
 PINTS_BASE2x24(b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_RBASE2x25(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24) \
 PINTS_BASE2x25(b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_RBASE2x26(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25) \
 PINTS_BASE2x26(b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_RBASE2x27(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26) \
 PINTS_BASE2x27(b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_RBASE2x28(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27) \
 PINTS_BASE2x28(b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_RBASE2x29(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28) \
 PINTS_BASE2x29(b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_RBASE2x30(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29) \
 PINTS_BASE2x30(b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_RBASE2x31(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30) \
 PINTS_BASE2x31(b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_RBASE2x32(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31) \
 PINTS_BASE2x32(b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_RBASE2x33(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32) \
 PINTS_BASE2x33(b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_RBASE2x34(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33) \
 PINTS_BASE2x34(b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_RBASE2x35(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34) \
 PINTS_BASE2x35(b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_RBASE2x36(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35) \
 PINTS_BASE2x36(b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_RBASE2x37(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36) \
 PINTS_BASE2x37(b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_RBASE2x38(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37) \
 PINTS_BASE2x38(b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_RBASE2x39(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38) \
 PINTS_BASE2x39(b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_RBASE2x40(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39) \
 PINTS_BASE2x40(b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_RBASE2x41(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40) \
 PINTS_BASE2x41(b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_RBASE2x42(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40, b41) \
 PINTS_BASE2x42(b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_RBASE2x43(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40, b41, b42) \
 PINTS_BASE2x43(b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_RBASE2x44(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40, b41, b42, b43) \
 PINTS_BASE2x44(b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_RBASE2x45(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40, b41, b42, b43, b44) \
 PINTS_BASE2x45(b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_RBASE2x46(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40, b41, b42, b43, b44, b45) \
 PINTS_BASE2x46(b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_RBASE2x47(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40, b41, b42, b43, b44, b45, b46) \
 PINTS_BASE2x47(b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_RBASE2x48(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40, b41, b42, b43, b44, b45, b46, b47) \
 PINTS_BASE2x48(b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_RBASE2x49(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40, b41, b42, b43, b44, b45, b46, b47, b48) \
 PINTS_BASE2x49(b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_RBASE2x50(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40, b41, b42, b43, b44, b45, b46, b47, b48, b49) \
 PINTS_BASE2x50(b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_RBASE2x51(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40, b41, b42, b43, b44, b45, b46, b47, b48, b49, b50) \
 PINTS_BASE2x51(b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_RBASE2x52(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40, b41, b42, b43, b44, b45, b46, b47, b48, b49, b50, b51) \
 PINTS_BASE2x52(b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_RBASE2x53(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40, b41, b42, b43, b44, b45, b46, b47, b48, b49, b50, b51, b52) \
 PINTS_BASE2x53(b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_RBASE2x54(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40, b41, b42, b43, b44, b45, b46, b47, b48, b49, b50, b51, b52, b53) \
 PINTS_BASE2x54(b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_RBASE2x55(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40, b41, b42, b43, b44, b45, b46, b47, b48, b49, b50, b51, b52, b53, b54) \
 PINTS_BASE2x55(b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_RBASE2x56(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40, b41, b42, b43, b44, b45, b46, b47, b48, b49, b50, b51, b52, b53, b54, b55) \
 PINTS_BASE2x56(b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_RBASE2x57(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40, b41, b42, b43, b44, b45, b46, b47, b48, b49, b50, b51, b52, b53, b54, b55, b56) \
 PINTS_BASE2x57(b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_RBASE2x58(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40, b41, b42, b43, b44, b45, b46, b47, b48, b49, b50, b51, b52, b53, b54, b55, b56, b57) \
 PINTS_BASE2x58(b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_RBASE2x59(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40, b41, b42, b43, b44, b45, b46, b47, b48, b49, b50, b51, b52, b53, b54, b55, b56, b57, b58) \
 PINTS_BASE2x59(b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_RBASE2x60(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40, b41, b42, b43, b44, b45, b46, b47, b48, b49, b50, b51, b52, b53, b54, b55, b56, b57, b58, b59) \
 PINTS_BASE2x60(b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_RBASE2x61(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40, b41, b42, b43, b44, b45, b46, b47, b48, b49, b50, b51, b52, b53, b54, b55, b56, b57, b58, b59, b60) \
 PINTS_BASE2x61(b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_RBASE2x62(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40, b41, b42, b43, b44, b45, b46, b47, b48, b49, b50, b51, b52, b53, b54, b55, b56, b57, b58, b59, b60, b61) \
 PINTS_BASE2x62(b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_RBASE2x63(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40, b41, b42, b43, b44, b45, b46, b47, b48, b49, b50, b51, b52, b53, b54, b55, b56, b57, b58, b59, b60, b61, b62) \
 PINTS_BASE2x63(b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)
#define PINTS_RBASE2x64(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40, b41, b42, b43, b44, b45, b46, b47, b48, b49, b50, b51, b52, b53, b54, b55, b56, b57, b58, b59, b60, b61, b62, b63) \
 PINTS_BASE2x64(b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0)


/* Base 4 */
#define PINTS_BASE4x0() \
  0x0
#define PINTS_BASE4x1(q0) \
  PINTS_BASE4x2(0, q0)
#define PINTS_BASE4x2(q1, q0) \
  PINTS_PP_CAT(0x, __PINTS_2QITS_TO_HEXA(q1, q0))
#define PINTS_BASE4x3(q2, q1, q0) \
  PINTS_BASE4x4(0, q2, q1, q0)
#define PINTS_BASE4x4(q3, q2, q1, q0) \
  PINTS_PP_CAT(PINTS_BASE4x2(q3, q2), __PINTS_2QITS_TO_HEXA(q1, q0))
#define PINTS_BASE4x5(q4, q3, q2, q1, q0) \
  PINTS_BASE4x6(0, q4, q3, q2, q1, q0)
#define PINTS_BASE4x6(q5, q4, q3, q2, q1, q0) \
  PINTS_PP_CAT(PINTS_BASE4x4(q5, q4, q3, q2), __PINTS_2QITS_TO_HEXA(q1, q0))
#define PINTS_BASE4x7(q6, q5, q4, q3, q2, q1, q0) \
  PINTS_BASE4x8(0, q6, q5, q4, q3, q2, q1, q0)
#define PINTS_BASE4x8(q7, q6, q5, q4, q3, q2, q1, q0) \
  PINTS_PP_CAT(PINTS_BASE4x6(q7, q6, q5, q4, q3, q2), __PINTS_2QITS_TO_HEXA(q1, q0))
#define PINTS_BASE4x9(q8, q7, q6, q5, q4, q3, q2, q1, q0) \
  PINTS_BASE4x10(0, q8, q7, q6, q5, q4, q3, q2, q1, q0)
#define PINTS_BASE4x10(q9, q8, q7, q6, q5, q4, q3, q2, q1, q0) \
  PINTS_PP_CAT(PINTS_BASE4x8(q9, q8, q7, q6, q5, q4, q3, q2), __PINTS_2QITS_TO_HEXA(q1, q0))
#define PINTS_BASE4x11(q10, q9, q8, q7, q6, q5, q4, q3, q2, q1, q0) \
  PINTS_BASE4x12(0, q10, q9, q8, q7, q6, q5, q4, q3, q2, q1, q0)
#define PINTS_BASE4x12(q11, q10, q9, q8, q7, q6, q5, q4, q3, q2, q1, q0) \
  PINTS_PP_CAT(PINTS_BASE4x10(q11, q10, q9, q8, q7, q6, q5, q4, q3, q2), __PINTS_2QITS_TO_HEXA(q1, q0))
#define PINTS_BASE4x13(q12, q11, q10, q9, q8, q7, q6, q5, q4, q3, q2, q1, q0) \
  PINTS_BASE4x14(0, q12, q11, q10, q9, q8, q7, q6, q5, q4, q3, q2, q1, q0)
#define PINTS_BASE4x14(q13, q12, q11, q10, q9, q8, q7, q6, q5, q4, q3, q2, q1, q0) \
  PINTS_PP_CAT(PINTS_BASE4x12(q13, q12, q11, q10, q9, q8, q7, q6, q5, q4, q3, q2), __PINTS_2QITS_TO_HEXA(q1, q0))
#define PINTS_BASE4x15(q14, q13, q12, q11, q10, q9, q8, q7, q6, q5, q4, q3, q2, q1, q0) \
  PINTS_BASE4x16(0, q14, q13, q12, q11, q10, q9, q8, q7, q6, q5, q4, q3, q2, q1, q0)
#define PINTS_BASE4x16(q15, q14, q13, q12, q11, q10, q9, q8, q7, q6, q5, q4, q3, q2, q1, q0) \
  PINTS_PP_CAT(PINTS_BASE4x14(q15, q14, q13, q12, q11, q10, q9, q8, q7, q6, q5, q4, q3, q2), __PINTS_2QITS_TO_HEXA(q1, q0))
#define PINTS_BASE4x17(q16, q15, q14, q13, q12, q11, q10, q9, q8, q7, q6, q5, q4, q3, q2, q1, q0) \
  PINTS_BASE4x18(0, q16, q15, q14, q13, q12, q11, q10, q9, q8, q7, q6, q5, q4, q3, q2, q1, q0)
#define PINTS_BASE4x18(q17, q16, q15, q14, q13, q12, q11, q10, q9, q8, q7, q6, q5, q4, q3, q2, q1, q0) \
  PINTS_PP_CAT(PINTS_BASE4x16(q17, q16, q15, q14, q13, q12, q11, q10, q9, q8, q7, q6, q5, q4, q3, q2), __PINTS_2QITS_TO_HEXA(q1, q0))
#define PINTS_BASE4x19(q18, q17, q16, q15, q14, q13, q12, q11, q10, q9, q8, q7, q6, q5, q4, q3, q2, q1, q0) \
  PINTS_BASE4x20(0, q18, q17, q16, q15, q14, q13, q12, q11, q10, q9, q8, q7, q6, q5, q4, q3, q2, q1, q0)
#define PINTS_BASE4x20(q19, q18, q17, q16, q15, q14, q13, q12, q11, q10, q9, q8, q7, q6, q5, q4, q3, q2, q1, q0) \
  PINTS_PP_CAT(PINTS_BASE4x18(q19, q18, q17, q16, q15, q14, q13, q12, q11, q10, q9, q8, q7, q6, q5, q4, q3, q2), __PINTS_2QITS_TO_HEXA(q1, q0))
#define PINTS_BASE4x21(q20, q19, q18, q17, q16, q15, q14, q13, q12, q11, q10, q9, q8, q7, q6, q5, q4, q3, q2, q1, q0) \
  PINTS_BASE4x22(0, q20, q19, q18, q17, q16, q15, q14, q13, q12, q11, q10, q9, q8, q7, q6, q5, q4, q3, q2, q1, q0)
#define PINTS_BASE4x22(q21, q20, q19, q18, q17, q16, q15, q14, q13, q12, q11, q10, q9, q8, q7, q6, q5, q4, q3, q2, q1, q0) \
  PINTS_PP_CAT(PINTS_BASE4x20(q21, q20, q19, q18, q17, q16, q15, q14, q13, q12, q11, q10, q9, q8, q7, q6, q5, q4, q3, q2), __PINTS_2QITS_TO_HEXA(q1, q0))
#define PINTS_BASE4x23(q22, q21, q20, q19, q18, q17, q16, q15, q14, q13, q12, q11, q10, q9, q8, q7, q6, q5, q4, q3, q2, q1, q0) \
  PINTS_BASE4x24(0, q22, q21, q20, q19, q18, q17, q16, q15, q14, q13, q12, q11, q10, q9, q8, q7, q6, q5, q4, q3, q2, q1, q0)
#define PINTS_BASE4x24(q23, q22, q21, q20, q19, q18, q17, q16, q15, q14, q13, q12, q11, q10, q9, q8, q7, q6, q5, q4, q3, q2, q1, q0) \
  PINTS_PP_CAT(PINTS_BASE4x22(q23, q22, q21, q20, q19, q18, q17, q16, q15, q14, q13, q12, q11, q10, q9, q8, q7, q6, q5, q4, q3, q2), __PINTS_2QITS_TO_HEXA(q1, q0))
#define PINTS_BASE4x25(q24, q23, q22, q21, q20, q19, q18, q17, q16, q15, q14, q13, q12, q11, q10, q9, q8, q7, q6, q5, q4, q3, q2, q1, q0) \
  PINTS_BASE4x26(0, q24, q23, q22, q21, q20, q19, q18, q17, q16, q15, q14, q13, q12, q11, q10, q9, q8, q7, q6, q5, q4, q3, q2, q1, q0)
#define PINTS_BASE4x26(q25, q24, q23, q22, q21, q20, q19, q18, q17, q16, q15, q14, q13, q12, q11, q10, q9, q8, q7, q6, q5, q4, q3, q2, q1, q0) \
  PINTS_PP_CAT(PINTS_BASE4x24(q25, q24, q23, q22, q21, q20, q19, q18, q17, q16, q15, q14, q13, q12, q11, q10, q9, q8, q7, q6, q5, q4, q3, q2), __PINTS_2QITS_TO_HEXA(q1, q0))
#define PINTS_BASE4x27(q26, q25, q24, q23, q22, q21, q20, q19, q18, q17, q16, q15, q14, q13, q12, q11, q10, q9, q8, q7, q6, q5, q4, q3, q2, q1, q0) \
  PINTS_BASE4x28(0, q26, q25, q24, q23, q22, q21, q20, q19, q18, q17, q16, q15, q14, q13, q12, q11, q10, q9, q8, q7, q6, q5, q4, q3, q2, q1, q0)
#define PINTS_BASE4x28(q27, q26, q25, q24, q23, q22, q21, q20, q19, q18, q17, q16, q15, q14, q13, q12, q11, q10, q9, q8, q7, q6, q5, q4, q3, q2, q1, q0) \
  PINTS_PP_CAT(PINTS_BASE4x26(q27, q26, q25, q24, q23, q22, q21, q20, q19, q18, q17, q16, q15, q14, q13, q12, q11, q10, q9, q8, q7, q6, q5, q4, q3, q2), __PINTS_2QITS_TO_HEXA(q1, q0))
#define PINTS_BASE4x29(q28, q27, q26, q25, q24, q23, q22, q21, q20, q19, q18, q17, q16, q15, q14, q13, q12, q11, q10, q9, q8, q7, q6, q5, q4, q3, q2, q1, q0) \
  PINTS_BASE4x30(0, q28, q27, q26, q25, q24, q23, q22, q21, q20, q19, q18, q17, q16, q15, q14, q13, q12, q11, q10, q9, q8, q7, q6, q5, q4, q3, q2, q1, q0)
#define PINTS_BASE4x30(q29, q28, q27, q26, q25, q24, q23, q22, q21, q20, q19, q18, q17, q16, q15, q14, q13, q12, q11, q10, q9, q8, q7, q6, q5, q4, q3, q2, q1, q0) \
  PINTS_PP_CAT(PINTS_BASE4x28(q29, q28, q27, q26, q25, q24, q23, q22, q21, q20, q19, q18, q17, q16, q15, q14, q13, q12, q11, q10, q9, q8, q7, q6, q5, q4, q3, q2), __PINTS_2QITS_TO_HEXA(q1, q0))
#define PINTS_BASE4x31(q30, q29, q28, q27, q26, q25, q24, q23, q22, q21, q20, q19, q18, q17, q16, q15, q14, q13, q12, q11, q10, q9, q8, q7, q6, q5, q4, q3, q2, q1, q0) \
  PINTS_BASE4x32(0, q30, q29, q28, q27, q26, q25, q24, q23, q22, q21, q20, q19, q18, q17, q16, q15, q14, q13, q12, q11, q10, q9, q8, q7, q6, q5, q4, q3, q2, q1, q0)
#define PINTS_BASE4x32(q31, q30, q29, q28, q27, q26, q25, q24, q23, q22, q21, q20, q19, q18, q17, q16, q15, q14, q13, q12, q11, q10, q9, q8, q7, q6, q5, q4, q3, q2, q1, q0) \
  PINTS_PP_CAT(PINTS_BASE4x30(q31, q30, q29, q28, q27, q26, q25, q24, q23, q22, q21, q20, q19, q18, q17, q16, q15, q14, q13, q12, q11, q10, q9, q8, q7, q6, q5, q4, q3, q2), __PINTS_2QITS_TO_HEXA(q1, q0))

#define PINTS_RBASE4x0() \
 PINTS_BASE4x0()
#define PINTS_RBASE4x1(q0) \
 PINTS_BASE4x1(q0)
#define PINTS_RBASE4x2(q0, q1) \
 PINTS_BASE4x2(q1, q0)
#define PINTS_RBASE4x3(q0, q1, q2) \
 PINTS_BASE4x3(q2, q1, q0)
#define PINTS_RBASE4x4(q0, q1, q2, q3) \
 PINTS_BASE4x4(q3, q2, q1, q0)
#define PINTS_RBASE4x5(q0, q1, q2, q3, q4) \
 PINTS_BASE4x5(q4, q3, q2, q1, q0)
#define PINTS_RBASE4x6(q0, q1, q2, q3, q4, q5) \
 PINTS_BASE4x6(q5, q4, q3, q2, q1, q0)
#define PINTS_RBASE4x7(q0, q1, q2, q3, q4, q5, q6) \
 PINTS_BASE4x7(q6, q5, q4, q3, q2, q1, q0)
#define PINTS_RBASE4x8(q0, q1, q2, q3, q4, q5, q6, q7) \
 PINTS_BASE4x8(q7, q6, q5, q4, q3, q2, q1, q0)
#define PINTS_RBASE4x9(q0, q1, q2, q3, q4, q5, q6, q7, q8) \
 PINTS_BASE4x9(q8, q7, q6, q5, q4, q3, q2, q1, q0)
#define PINTS_RBASE4x10(q0, q1, q2, q3, q4, q5, q6, q7, q8, q9) \
 PINTS_BASE4x10(q9, q8, q7, q6, q5, q4, q3, q2, q1, q0)
#define PINTS_RBASE4x11(q0, q1, q2, q3, q4, q5, q6, q7, q8, q9, q10) \
 PINTS_BASE4x11(q10, q9, q8, q7, q6, q5, q4, q3, q2, q1, q0)
#define PINTS_RBASE4x12(q0, q1, q2, q3, q4, q5, q6, q7, q8, q9, q10, q11) \
 PINTS_BASE4x12(q11, q10, q9, q8, q7, q6, q5, q4, q3, q2, q1, q0)
#define PINTS_RBASE4x13(q0, q1, q2, q3, q4, q5, q6, q7, q8, q9, q10, q11, q12) \
 PINTS_BASE4x13(q12, q11, q10, q9, q8, q7, q6, q5, q4, q3, q2, q1, q0)
#define PINTS_RBASE4x14(q0, q1, q2, q3, q4, q5, q6, q7, q8, q9, q10, q11, q12, q13) \
 PINTS_BASE4x14(q13, q12, q11, q10, q9, q8, q7, q6, q5, q4, q3, q2, q1, q0)
#define PINTS_RBASE4x15(q0, q1, q2, q3, q4, q5, q6, q7, q8, q9, q10, q11, q12, q13, q14) \
 PINTS_BASE4x15(q14, q13, q12, q11, q10, q9, q8, q7, q6, q5, q4, q3, q2, q1, q0)
#define PINTS_RBASE4x16(q0, q1, q2, q3, q4, q5, q6, q7, q8, q9, q10, q11, q12, q13, q14, q15) \
 PINTS_BASE4x16(q15, q14, q13, q12, q11, q10, q9, q8, q7, q6, q5, q4, q3, q2, q1, q0)
#define PINTS_RBASE4x17(q0, q1, q2, q3, q4, q5, q6, q7, q8, q9, q10, q11, q12, q13, q14, q15, q16) \
 PINTS_BASE4x17(q16, q15, q14, q13, q12, q11, q10, q9, q8, q7, q6, q5, q4, q3, q2, q1, q0)
#define PINTS_RBASE4x18(q0, q1, q2, q3, q4, q5, q6, q7, q8, q9, q10, q11, q12, q13, q14, q15, q16, q17) \
 PINTS_BASE4x18(q17, q16, q15, q14, q13, q12, q11, q10, q9, q8, q7, q6, q5, q4, q3, q2, q1, q0)
#define PINTS_RBASE4x19(q0, q1, q2, q3, q4, q5, q6, q7, q8, q9, q10, q11, q12, q13, q14, q15, q16, q17, q18) \
 PINTS_BASE4x19(q18, q17, q16, q15, q14, q13, q12, q11, q10, q9, q8, q7, q6, q5, q4, q3, q2, q1, q0)
#define PINTS_RBASE4x20(q0, q1, q2, q3, q4, q5, q6, q7, q8, q9, q10, q11, q12, q13, q14, q15, q16, q17, q18, q19) \
 PINTS_BASE4x20(q19, q18, q17, q16, q15, q14, q13, q12, q11, q10, q9, q8, q7, q6, q5, q4, q3, q2, q1, q0)
#define PINTS_RBASE4x21(q0, q1, q2, q3, q4, q5, q6, q7, q8, q9, q10, q11, q12, q13, q14, q15, q16, q17, q18, q19, q20) \
 PINTS_BASE4x21(q20, q19, q18, q17, q16, q15, q14, q13, q12, q11, q10, q9, q8, q7, q6, q5, q4, q3, q2, q1, q0)
#define PINTS_RBASE4x22(q0, q1, q2, q3, q4, q5, q6, q7, q8, q9, q10, q11, q12, q13, q14, q15, q16, q17, q18, q19, q20, q21) \
 PINTS_BASE4x22(q21, q20, q19, q18, q17, q16, q15, q14, q13, q12, q11, q10, q9, q8, q7, q6, q5, q4, q3, q2, q1, q0)
#define PINTS_RBASE4x23(q0, q1, q2, q3, q4, q5, q6, q7, q8, q9, q10, q11, q12, q13, q14, q15, q16, q17, q18, q19, q20, q21, q22) \
 PINTS_BASE4x23(q22, q21, q20, q19, q18, q17, q16, q15, q14, q13, q12, q11, q10, q9, q8, q7, q6, q5, q4, q3, q2, q1, q0)
#define PINTS_RBASE4x24(q0, q1, q2, q3, q4, q5, q6, q7, q8, q9, q10, q11, q12, q13, q14, q15, q16, q17, q18, q19, q20, q21, q22, q23) \
 PINTS_BASE4x24(q23, q22, q21, q20, q19, q18, q17, q16, q15, q14, q13, q12, q11, q10, q9, q8, q7, q6, q5, q4, q3, q2, q1, q0)
#define PINTS_RBASE4x25(q0, q1, q2, q3, q4, q5, q6, q7, q8, q9, q10, q11, q12, q13, q14, q15, q16, q17, q18, q19, q20, q21, q22, q23, q24) \
 PINTS_BASE4x25(q24, q23, q22, q21, q20, q19, q18, q17, q16, q15, q14, q13, q12, q11, q10, q9, q8, q7, q6, q5, q4, q3, q2, q1, q0)
#define PINTS_RBASE4x26(q0, q1, q2, q3, q4, q5, q6, q7, q8, q9, q10, q11, q12, q13, q14, q15, q16, q17, q18, q19, q20, q21, q22, q23, q24, q25) \
 PINTS_BASE4x26(q25, q24, q23, q22, q21, q20, q19, q18, q17, q16, q15, q14, q13, q12, q11, q10, q9, q8, q7, q6, q5, q4, q3, q2, q1, q0)
#define PINTS_RBASE4x27(q0, q1, q2, q3, q4, q5, q6, q7, q8, q9, q10, q11, q12, q13, q14, q15, q16, q17, q18, q19, q20, q21, q22, q23, q24, q25, q26) \
 PINTS_BASE4x27(q26, q25, q24, q23, q22, q21, q20, q19, q18, q17, q16, q15, q14, q13, q12, q11, q10, q9, q8, q7, q6, q5, q4, q3, q2, q1, q0)
#define PINTS_RBASE4x28(q0, q1, q2, q3, q4, q5, q6, q7, q8, q9, q10, q11, q12, q13, q14, q15, q16, q17, q18, q19, q20, q21, q22, q23, q24, q25, q26, q27) \
 PINTS_BASE4x28(q27, q26, q25, q24, q23, q22, q21, q20, q19, q18, q17, q16, q15, q14, q13, q12, q11, q10, q9, q8, q7, q6, q5, q4, q3, q2, q1, q0)
#define PINTS_RBASE4x29(q0, q1, q2, q3, q4, q5, q6, q7, q8, q9, q10, q11, q12, q13, q14, q15, q16, q17, q18, q19, q20, q21, q22, q23, q24, q25, q26, q27, q28) \
 PINTS_BASE4x29(q28, q27, q26, q25, q24, q23, q22, q21, q20, q19, q18, q17, q16, q15, q14, q13, q12, q11, q10, q9, q8, q7, q6, q5, q4, q3, q2, q1, q0)
#define PINTS_RBASE4x30(q0, q1, q2, q3, q4, q5, q6, q7, q8, q9, q10, q11, q12, q13, q14, q15, q16, q17, q18, q19, q20, q21, q22, q23, q24, q25, q26, q27, q28, q29) \
 PINTS_BASE4x30(q29, q28, q27, q26, q25, q24, q23, q22, q21, q20, q19, q18, q17, q16, q15, q14, q13, q12, q11, q10, q9, q8, q7, q6, q5, q4, q3, q2, q1, q0)
#define PINTS_RBASE4x31(q0, q1, q2, q3, q4, q5, q6, q7, q8, q9, q10, q11, q12, q13, q14, q15, q16, q17, q18, q19, q20, q21, q22, q23, q24, q25, q26, q27, q28, q29, q30) \
 PINTS_BASE4x31(q30, q29, q28, q27, q26, q25, q24, q23, q22, q21, q20, q19, q18, q17, q16, q15, q14, q13, q12, q11, q10, q9, q8, q7, q6, q5, q4, q3, q2, q1, q0)
#define PINTS_RBASE4x32(q0, q1, q2, q3, q4, q5, q6, q7, q8, q9, q10, q11, q12, q13, q14, q15, q16, q17, q18, q19, q20, q21, q22, q23, q24, q25, q26, q27, q28, q29, q30, q31) \
 PINTS_BASE4x32(q31, q30, q29, q28, q27, q26, q25, q24, q23, q22, q21, q20, q19, q18, q17, q16, q15, q14, q13, q12, q11, q10, q9, q8, q7, q6, q5, q4, q3, q2, q1, q0)


/* Base 8 */
#define PINTS_BASE8x0() \
  0
#define PINTS_BASE8x1(o0) \
  PINTS_PP_CAT(PINTS_BASE8x0(), o0)
#define PINTS_BASE8x2(o1, o0) \
  PINTS_PP_CAT(PINTS_BASE8x1(o1), o0)
#define PINTS_BASE8x3(o2, o1, o0) \
  PINTS_PP_CAT(PINTS_BASE8x2(o2, o1), o0)
#define PINTS_BASE8x4(o3, o2, o1, o0) \
  PINTS_PP_CAT(PINTS_BASE8x3(o3, o2, o1), o0)
#define PINTS_BASE8x5(o4, o3, o2, o1, o0) \
  PINTS_PP_CAT(PINTS_BASE8x4(o4, o3, o2, o1), o0)
#define PINTS_BASE8x6(o5, o4, o3, o2, o1, o0) \
  PINTS_PP_CAT(PINTS_BASE8x5(o5, o4, o3, o2, o1), o0)
#define PINTS_BASE8x7(o6, o5, o4, o3, o2, o1, o0) \
  PINTS_PP_CAT(PINTS_BASE8x6(o6, o5, o4, o3, o2, o1), o0)
#define PINTS_BASE8x8(o7, o6, o5, o4, o3, o2, o1, o0) \
  PINTS_PP_CAT(PINTS_BASE8x7(o7, o6, o5, o4, o3, o2, o1), o0)
#define PINTS_BASE8x9(o8, o7, o6, o5, o4, o3, o2, o1, o0) \
  PINTS_PP_CAT(PINTS_BASE8x8(o8, o7, o6, o5, o4, o3, o2, o1), o0)
#define PINTS_BASE8x10(o9, o8, o7, o6, o5, o4, o3, o2, o1, o0) \
  PINTS_PP_CAT(PINTS_BASE8x9(o9, o8, o7, o6, o5, o4, o3, o2, o1), o0)
#define PINTS_BASE8x11(o10, o9, o8, o7, o6, o5, o4, o3, o2, o1, o0) \
  PINTS_PP_CAT(PINTS_BASE8x10(o10, o9, o8, o7, o6, o5, o4, o3, o2, o1), o0)
#define PINTS_BASE8x12(o11, o10, o9, o8, o7, o6, o5, o4, o3, o2, o1, o0) \
  PINTS_PP_CAT(PINTS_BASE8x11(o11, o10, o9, o8, o7, o6, o5, o4, o3, o2, o1), o0)
#define PINTS_BASE8x13(o12, o11, o10, o9, o8, o7, o6, o5, o4, o3, o2, o1, o0) \
  PINTS_PP_CAT(PINTS_BASE8x12(o12, o11, o10, o9, o8, o7, o6, o5, o4, o3, o2, o1), o0)
#define PINTS_BASE8x14(o13, o12, o11, o10, o9, o8, o7, o6, o5, o4, o3, o2, o1, o0) \
  PINTS_PP_CAT(PINTS_BASE8x13(o13, o12, o11, o10, o9, o8, o7, o6, o5, o4, o3, o2, o1), o0)
#define PINTS_BASE8x15(o14, o13, o12, o11, o10, o9, o8, o7, o6, o5, o4, o3, o2, o1, o0) \
  PINTS_PP_CAT(PINTS_BASE8x14(o14, o13, o12, o11, o10, o9, o8, o7, o6, o5, o4, o3, o2, o1), o0)
#define PINTS_BASE8x16(o15, o14, o13, o12, o11, o10, o9, o8, o7, o6, o5, o4, o3, o2, o1, o0) \
  PINTS_PP_CAT(PINTS_BASE8x15(o15, o14, o13, o12, o11, o10, o9, o8, o7, o6, o5, o4, o3, o2, o1), o0)
#define PINTS_BASE8x17(o16, o15, o14, o13, o12, o11, o10, o9, o8, o7, o6, o5, o4, o3, o2, o1, o0) \
  PINTS_PP_CAT(PINTS_BASE8x16(o16, o15, o14, o13, o12, o11, o10, o9, o8, o7, o6, o5, o4, o3, o2, o1), o0)
#define PINTS_BASE8x18(o17, o16, o15, o14, o13, o12, o11, o10, o9, o8, o7, o6, o5, o4, o3, o2, o1, o0) \
  PINTS_PP_CAT(PINTS_BASE8x17(o17, o16, o15, o14, o13, o12, o11, o10, o9, o8, o7, o6, o5, o4, o3, o2, o1), o0)
#define PINTS_BASE8x19(o18, o17, o16, o15, o14, o13, o12, o11, o10, o9, o8, o7, o6, o5, o4, o3, o2, o1, o0) \
  PINTS_PP_CAT(PINTS_BASE8x18(o18, o17, o16, o15, o14, o13, o12, o11, o10, o9, o8, o7, o6, o5, o4, o3, o2, o1), o0)
#define PINTS_BASE8x20(o19, o18, o17, o16, o15, o14, o13, o12, o11, o10, o9, o8, o7, o6, o5, o4, o3, o2, o1, o0) \
  PINTS_PP_CAT(PINTS_BASE8x19(o19, o18, o17, o16, o15, o14, o13, o12, o11, o10, o9, o8, o7, o6, o5, o4, o3, o2, o1), o0)
#define PINTS_BASE8x21(o20, o19, o18, o17, o16, o15, o14, o13, o12, o11, o10, o9, o8, o7, o6, o5, o4, o3, o2, o1, o0) \
  PINTS_PP_CAT(PINTS_BASE8x20(o20, o19, o18, o17, o16, o15, o14, o13, o12, o11, o10, o9, o8, o7, o6, o5, o4, o3, o2, o1), o0)

#define PINTS_RBASE8x0() \
 PINTS_BASE8x0()
#define PINTS_RBASE8x1(o0) \
 PINTS_BASE8x1(o0)
#define PINTS_RBASE8x2(o0, o1) \
 PINTS_BASE8x2(o1, o0)
#define PINTS_RBASE8x3(o0, o1, o2) \
 PINTS_BASE8x3(o2, o1, o0)
#define PINTS_RBASE8x4(o0, o1, o2, o3) \
 PINTS_BASE8x4(o3, o2, o1, o0)
#define PINTS_RBASE8x5(o0, o1, o2, o3, o4) \
 PINTS_BASE8x5(o4, o3, o2, o1, o0)
#define PINTS_RBASE8x6(o0, o1, o2, o3, o4, o5) \
 PINTS_BASE8x6(o5, o4, o3, o2, o1, o0)
#define PINTS_RBASE8x7(o0, o1, o2, o3, o4, o5, o6) \
 PINTS_BASE8x7(o6, o5, o4, o3, o2, o1, o0)
#define PINTS_RBASE8x8(o0, o1, o2, o3, o4, o5, o6, o7) \
 PINTS_BASE8x8(o7, o6, o5, o4, o3, o2, o1, o0)
#define PINTS_RBASE8x9(o0, o1, o2, o3, o4, o5, o6, o7, o8) \
 PINTS_BASE8x9(o8, o7, o6, o5, o4, o3, o2, o1, o0)
#define PINTS_RBASE8x10(o0, o1, o2, o3, o4, o5, o6, o7, o8, o9) \
 PINTS_BASE8x10(o9, o8, o7, o6, o5, o4, o3, o2, o1, o0)
#define PINTS_RBASE8x11(o0, o1, o2, o3, o4, o5, o6, o7, o8, o9, o10) \
 PINTS_BASE8x11(o10, o9, o8, o7, o6, o5, o4, o3, o2, o1, o0)
#define PINTS_RBASE8x12(o0, o1, o2, o3, o4, o5, o6, o7, o8, o9, o10, o11) \
 PINTS_BASE8x12(o11, o10, o9, o8, o7, o6, o5, o4, o3, o2, o1, o0)
#define PINTS_RBASE8x13(o0, o1, o2, o3, o4, o5, o6, o7, o8, o9, o10, o11, o12) \
 PINTS_BASE8x13(o12, o11, o10, o9, o8, o7, o6, o5, o4, o3, o2, o1, o0)
#define PINTS_RBASE8x14(o0, o1, o2, o3, o4, o5, o6, o7, o8, o9, o10, o11, o12, o13) \
 PINTS_BASE8x14(o13, o12, o11, o10, o9, o8, o7, o6, o5, o4, o3, o2, o1, o0)
#define PINTS_RBASE8x15(o0, o1, o2, o3, o4, o5, o6, o7, o8, o9, o10, o11, o12, o13, o14) \
 PINTS_BASE8x15(o14, o13, o12, o11, o10, o9, o8, o7, o6, o5, o4, o3, o2, o1, o0)
#define PINTS_RBASE8x16(o0, o1, o2, o3, o4, o5, o6, o7, o8, o9, o10, o11, o12, o13, o14, o15) \
 PINTS_BASE8x16(o15, o14, o13, o12, o11, o10, o9, o8, o7, o6, o5, o4, o3, o2, o1, o0)
#define PINTS_RBASE8x17(o0, o1, o2, o3, o4, o5, o6, o7, o8, o9, o10, o11, o12, o13, o14, o15, o16) \
 PINTS_BASE8x17(o16, o15, o14, o13, o12, o11, o10, o9, o8, o7, o6, o5, o4, o3, o2, o1, o0)
#define PINTS_RBASE8x18(o0, o1, o2, o3, o4, o5, o6, o7, o8, o9, o10, o11, o12, o13, o14, o15, o16, o17) \
 PINTS_BASE8x18(o17, o16, o15, o14, o13, o12, o11, o10, o9, o8, o7, o6, o5, o4, o3, o2, o1, o0)
#define PINTS_RBASE8x19(o0, o1, o2, o3, o4, o5, o6, o7, o8, o9, o10, o11, o12, o13, o14, o15, o16, o17, o18) \
 PINTS_BASE8x19(o18, o17, o16, o15, o14, o13, o12, o11, o10, o9, o8, o7, o6, o5, o4, o3, o2, o1, o0)
#define PINTS_RBASE8x20(o0, o1, o2, o3, o4, o5, o6, o7, o8, o9, o10, o11, o12, o13, o14, o15, o16, o17, o18, o19) \
 PINTS_BASE8x20(o19, o18, o17, o16, o15, o14, o13, o12, o11, o10, o9, o8, o7, o6, o5, o4, o3, o2, o1, o0)
#define PINTS_RBASE8x21(o0, o1, o2, o3, o4, o5, o6, o7, o8, o9, o10, o11, o12, o13, o14, o15, o16, o17, o18, o19, o20) \
 PINTS_BASE8x21(o20, o19, o18, o17, o16, o15, o14, o13, o12, o11, o10, o9, o8, o7, o6, o5, o4, o3, o2, o1, o0)


/* Base 16 */
#define PINTS_BASE16x0() \
  0x0
#define PINTS_BASE16x1(h0) \
  PINTS_PP_CAT(0x, __PINTS_DEC_TO_HEXA(h0))
#define PINTS_BASE16x2(h1, h0) \
  PINTS_PP_CAT(PINTS_BASE16x1(h1), __PINTS_DEC_TO_HEXA(h0))
#define PINTS_BASE16x3(h2, h1, h0) \
  PINTS_PP_CAT(PINTS_BASE16x2(h2, h1), __PINTS_DEC_TO_HEXA(h0))
#define PINTS_BASE16x4(h3, h2, h1, h0) \
  PINTS_PP_CAT(PINTS_BASE16x3(h3, h2, h1), __PINTS_DEC_TO_HEXA(h0))
#define PINTS_BASE16x5(h4, h3, h2, h1, h0) \
  PINTS_PP_CAT(PINTS_BASE16x4(h4, h3, h2, h1), __PINTS_DEC_TO_HEXA(h0))
#define PINTS_BASE16x6(h5, h4, h3, h2, h1, h0) \
  PINTS_PP_CAT(PINTS_BASE16x5(h5, h4, h3, h2, h1), __PINTS_DEC_TO_HEXA(h0))
#define PINTS_BASE16x7(h6, h5, h4, h3, h2, h1, h0) \
  PINTS_PP_CAT(PINTS_BASE16x6(h6, h5, h4, h3, h2, h1), __PINTS_DEC_TO_HEXA(h0))
#define PINTS_BASE16x8(h7, h6, h5, h4, h3, h2, h1, h0) \
  PINTS_PP_CAT(PINTS_BASE16x7(h7, h6, h5, h4, h3, h2, h1), __PINTS_DEC_TO_HEXA(h0))
#define PINTS_BASE16x9(h8, h7, h6, h5, h4, h3, h2, h1, h0) \
  PINTS_PP_CAT(PINTS_BASE16x8(h8, h7, h6, h5, h4, h3, h2, h1), __PINTS_DEC_TO_HEXA(h0))
#define PINTS_BASE16x10(h9, h8, h7, h6, h5, h4, h3, h2, h1, h0) \
  PINTS_PP_CAT(PINTS_BASE16x9(h9, h8, h7, h6, h5, h4, h3, h2, h1), __PINTS_DEC_TO_HEXA(h0))
#define PINTS_BASE16x11(h10, h9, h8, h7, h6, h5, h4, h3, h2, h1, h0) \
  PINTS_PP_CAT(PINTS_BASE16x10(h10, h9, h8, h7, h6, h5, h4, h3, h2, h1), __PINTS_DEC_TO_HEXA(h0))
#define PINTS_BASE16x12(h11, h10, h9, h8, h7, h6, h5, h4, h3, h2, h1, h0) \
  PINTS_PP_CAT(PINTS_BASE16x11(h11, h10, h9, h8, h7, h6, h5, h4, h3, h2, h1), __PINTS_DEC_TO_HEXA(h0))
#define PINTS_BASE16x13(h12, h11, h10, h9, h8, h7, h6, h5, h4, h3, h2, h1, h0) \
  PINTS_PP_CAT(PINTS_BASE16x12(h12, h11, h10, h9, h8, h7, h6, h5, h4, h3, h2, h1), __PINTS_DEC_TO_HEXA(h0))
#define PINTS_BASE16x14(h13, h12, h11, h10, h9, h8, h7, h6, h5, h4, h3, h2, h1, h0) \
  PINTS_PP_CAT(PINTS_BASE16x13(h13, h12, h11, h10, h9, h8, h7, h6, h5, h4, h3, h2, h1), __PINTS_DEC_TO_HEXA(h0))
#define PINTS_BASE16x15(h14, h13, h12, h11, h10, h9, h8, h7, h6, h5, h4, h3, h2, h1, h0) \
  PINTS_PP_CAT(PINTS_BASE16x14(h14, h13, h12, h11, h10, h9, h8, h7, h6, h5, h4, h3, h2, h1), __PINTS_DEC_TO_HEXA(h0))
#define PINTS_BASE16x16(h15, h14, h13, h12, h11, h10, h9, h8, h7, h6, h5, h4, h3, h2, h1, h0) \
  PINTS_PP_CAT(PINTS_BASE16x15(h15, h14, h13, h12, h11, h10, h9, h8, h7, h6, h5, h4, h3, h2, h1), __PINTS_DEC_TO_HEXA(h0))

#define PINTS_RBASE16x0() \
 PINTS_BASE16x0()
#define PINTS_RBASE16x1(h0) \
 PINTS_BASE16x1(h0)
#define PINTS_RBASE16x2(h0, h1) \
 PINTS_BASE16x2(h1, h0)
#define PINTS_RBASE16x3(h0, h1, h2) \
 PINTS_BASE16x3(h2, h1, h0)
#define PINTS_RBASE16x4(h0, h1, h2, h3) \
 PINTS_BASE16x4(h3, h2, h1, h0)
#define PINTS_RBASE16x5(h0, h1, h2, h3, h4) \
 PINTS_BASE16x5(h4, h3, h2, h1, h0)
#define PINTS_RBASE16x6(h0, h1, h2, h3, h4, h5) \
 PINTS_BASE16x6(h5, h4, h3, h2, h1, h0)
#define PINTS_RBASE16x7(h0, h1, h2, h3, h4, h5, h6) \
 PINTS_BASE16x7(h6, h5, h4, h3, h2, h1, h0)
#define PINTS_RBASE16x8(h0, h1, h2, h3, h4, h5, h6, h7) \
 PINTS_BASE16x8(h7, h6, h5, h4, h3, h2, h1, h0)
#define PINTS_RBASE16x9(h0, h1, h2, h3, h4, h5, h6, h7, h8) \
 PINTS_BASE16x9(h8, h7, h6, h5, h4, h3, h2, h1, h0)
#define PINTS_RBASE16x10(h0, h1, h2, h3, h4, h5, h6, h7, h8, h9) \
 PINTS_BASE16x10(h9, h8, h7, h6, h5, h4, h3, h2, h1, h0)
#define PINTS_RBASE16x11(h0, h1, h2, h3, h4, h5, h6, h7, h8, h9, h10) \
 PINTS_BASE16x11(h10, h9, h8, h7, h6, h5, h4, h3, h2, h1, h0)
#define PINTS_RBASE16x12(h0, h1, h2, h3, h4, h5, h6, h7, h8, h9, h10, h11) \
 PINTS_BASE16x12(h11, h10, h9, h8, h7, h6, h5, h4, h3, h2, h1, h0)
#define PINTS_RBASE16x13(h0, h1, h2, h3, h4, h5, h6, h7, h8, h9, h10, h11, h12) \
 PINTS_BASE16x13(h12, h11, h10, h9, h8, h7, h6, h5, h4, h3, h2, h1, h0)
#define PINTS_RBASE16x14(h0, h1, h2, h3, h4, h5, h6, h7, h8, h9, h10, h11, h12, h13) \
 PINTS_BASE16x14(h13, h12, h11, h10, h9, h8, h7, h6, h5, h4, h3, h2, h1, h0)
#define PINTS_RBASE16x15(h0, h1, h2, h3, h4, h5, h6, h7, h8, h9, h10, h11, h12, h13, h14) \
 PINTS_BASE16x15(h14, h13, h12, h11, h10, h9, h8, h7, h6, h5, h4, h3, h2, h1, h0)
#define PINTS_RBASE16x16(h0, h1, h2, h3, h4, h5, h6, h7, h8, h9, h10, h11, h12, h13, h14, h15) \
 PINTS_BASE16x16(h15, h14, h13, h12, h11, h10, h9, h8, h7, h6, h5, h4, h3, h2, h1, h0)

/* Unspecified number of args */
#define PINTS_BASE2(...) PINTS_PP_CAT(PINTS_BASE2x, PINTS_PP_NARGS(__VA_ARGS__))(__VA_ARGS__)
#define PINTS_RBASE2(...) PINTS_PP_CAT(PINTS_RBASE2x, PINTS_PP_NARGS(__VA_ARGS__))(__VA_ARGS__)
#define PINTS_BASE4(...) PINTS_PP_CAT(PINTS_BASE4x, PINTS_PP_NARGS(__VA_ARGS__))(__VA_ARGS__)
#define PINTS_RBASE4(...) PINTS_PP_CAT(PINTS_RBASE4x, PINTS_PP_NARGS(__VA_ARGS__))(__VA_ARGS__)
#define PINTS_BASE8(...) PINTS_PP_CAT(PINTS_BASE8x, PINTS_PP_NARGS(__VA_ARGS__))(__VA_ARGS__)
#define PINTS_RBASE8(...) PINTS_PP_CAT(PINTS_RBASE8x, PINTS_PP_NARGS(__VA_ARGS__))(__VA_ARGS__)
#define PINTS_BASE16(...) PINTS_PP_CAT(PINTS_BASE16x, PINTS_PP_NARGS(__VA_ARGS__))(__VA_ARGS__)
#define PINTS_RBASE16(...) PINTS_PP_CAT(PINTS_RBASE16x, PINTS_PP_NARGS(__VA_ARGS__))(__VA_ARGS__)
#define PINTS_BASE2_U(...) PINTS_PP_CAT(PINTS_BASE2(__VA_ARGS__), U)
#define PINTS_RBASE2_U(...) PINTS_PP_CAT(PINTS_RBASE2(__VA_ARGS__), U)
#define PINTS_BASE4_U(...) PINTS_PP_CAT(PINTS_BASE4(__VA_ARGS__), U)
#define PINTS_RBASE4_U(...) PINTS_PP_CAT(PINTS_RBASE4(__VA_ARGS__), U)
#define PINTS_BASE8_U(...) PINTS_PP_CAT(PINTS_BASE8(__VA_ARGS__), U)
#define PINTS_RBASE8_U(...) PINTS_PP_CAT(PINTS_RBASE8(__VA_ARGS__), U)
#define PINTS_BASE16_U(...) PINTS_PP_CAT(PINTS_BASE16(__VA_ARGS__), U)
#define PINTS_RBASE16_U(...) PINTS_PP_CAT(PINTS_RBASE16(__VA_ARGS__), U)
#define PINTS_BASE2_UL(...) PINTS_PP_CAT(PINTS_BASE2(__VA_ARGS__), UL)
#define PINTS_RBASE2_UL(...) PINTS_PP_CAT(PINTS_RBASE2(__VA_ARGS__), UL)
#define PINTS_BASE4_UL(...) PINTS_PP_CAT(PINTS_BASE4(__VA_ARGS__), UL)
#define PINTS_RBASE4_UL(...) PINTS_PP_CAT(PINTS_RBASE4(__VA_ARGS__), UL)
#define PINTS_BASE8_UL(...) PINTS_PP_CAT(PINTS_BASE8(__VA_ARGS__), UL)
#define PINTS_RBASE8_UL(...) PINTS_PP_CAT(PINTS_RBASE8(__VA_ARGS__), UL)
#define PINTS_BASE16_UL(...) PINTS_PP_CAT(PINTS_BASE16(__VA_ARGS__), UL)
#define PINTS_RBASE16_UL(...) PINTS_PP_CAT(PINTS_RBASE16(__VA_ARGS__), UL)
#define PINTS_BASE2_LU(...) PINTS_PP_CAT(PINTS_BASE2(__VA_ARGS__), LU)
#define PINTS_RBASE2_LU(...) PINTS_PP_CAT(PINTS_RBASE2(__VA_ARGS__), LU)
#define PINTS_BASE4_LU(...) PINTS_PP_CAT(PINTS_BASE4(__VA_ARGS__), LU)
#define PINTS_RBASE4_LU(...) PINTS_PP_CAT(PINTS_RBASE4(__VA_ARGS__), LU)
#define PINTS_BASE8_LU(...) PINTS_PP_CAT(PINTS_BASE8(__VA_ARGS__), LU)
#define PINTS_RBASE8_LU(...) PINTS_PP_CAT(PINTS_RBASE8(__VA_ARGS__), LU)
#define PINTS_BASE16_LU(...) PINTS_PP_CAT(PINTS_BASE16(__VA_ARGS__), LU)
#define PINTS_RBASE16_LU(...) PINTS_PP_CAT(PINTS_RBASE16(__VA_ARGS__), LU)
#define PINTS_BASE2_ULL(...) PINTS_PP_CAT(PINTS_BASE2(__VA_ARGS__), ULL)
#define PINTS_RBASE2_ULL(...) PINTS_PP_CAT(PINTS_RBASE2(__VA_ARGS__), ULL)
#define PINTS_BASE4_ULL(...) PINTS_PP_CAT(PINTS_BASE4(__VA_ARGS__), ULL)
#define PINTS_RBASE4_ULL(...) PINTS_PP_CAT(PINTS_RBASE4(__VA_ARGS__), ULL)
#define PINTS_BASE8_ULL(...) PINTS_PP_CAT(PINTS_BASE8(__VA_ARGS__), ULL)
#define PINTS_RBASE8_ULL(...) PINTS_PP_CAT(PINTS_RBASE8(__VA_ARGS__), ULL)
#define PINTS_BASE16_ULL(...) PINTS_PP_CAT(PINTS_BASE16(__VA_ARGS__), ULL)
#define PINTS_RBASE16_ULL(...) PINTS_PP_CAT(PINTS_RBASE16(__VA_ARGS__), ULL)
#define PINTS_BASE2_LLU(...) PINTS_PP_CAT(PINTS_BASE2(__VA_ARGS__), LLU)
#define PINTS_RBASE2_LLU(...) PINTS_PP_CAT(PINTS_RBASE2(__VA_ARGS__), LLU)
#define PINTS_BASE4_LLU(...) PINTS_PP_CAT(PINTS_BASE4(__VA_ARGS__), LLU)
#define PINTS_RBASE4_LLU(...) PINTS_PP_CAT(PINTS_RBASE4(__VA_ARGS__), LLU)
#define PINTS_BASE8_LLU(...) PINTS_PP_CAT(PINTS_BASE8(__VA_ARGS__), LLU)
#define PINTS_RBASE8_LLU(...) PINTS_PP_CAT(PINTS_RBASE8(__VA_ARGS__), LLU)
#define PINTS_BASE16_LLU(...) PINTS_PP_CAT(PINTS_BASE16(__VA_ARGS__), LLU)
#define PINTS_RBASE16_LLU(...) PINTS_PP_CAT(PINTS_RBASE16(__VA_ARGS__), LLU)

/* Shuffles helper */
#define PINTS_SHUFFLE2 PINTS_RBASE2
#define PINTS_RSHUFFLE2 PINTS_BASE2
#define PINTS_SHUFFLE4 PINTS_RBASE4
#define PINTS_RSHUFFLE4 PINTS_BASE4
#define PINTS_SHUFFLE8 PINTS_RBASE8
#define PINTS_RSHUFFLE8 PINTS_BASE8
#define PINTS_SHUFFLE16 PINTS_RBASE16
#define PINTS_RSHUFFLE16 PINTS_BASE16

#define PINTS_SHUFFLE(...) PINTS_PP_CAT(PINTS_SHUFFLE, PINTS_PP_NARGS(__VA_ARGS__))(__VA_ARGS__)
#define PINTS_RSHUFFLE(...) PINTS_PP_CAT(PINTS_RSHUFFLE, PINTS_PP_NARGS(__VA_ARGS__))(__VA_ARGS__)


#endif //PINTS_HELPER_H