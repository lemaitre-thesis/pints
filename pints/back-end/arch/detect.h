#ifndef PINTS_BACKEND_ARCH_DETECT_H
#define PINTS_BACKEND_ARCH_DETECT_H

# if defined(__SSE__)
#   define PINTS_SSE 1
#   ifndef PINTS_VEC
#     define PINTS_VEC 1
#   endif
#   if defined(__SSE2__)
#     define PINTS_SSE2 1
#   endif
#   if defined(__SSE3__)
#     define PINTS_SSE3 1
#   endif
#   if defined(__SSSE3__)
#     define PINTS_SSSE3 1
#   endif
#   if defined(__SSE4_1__)
#     define PINTS_SSE4_1 1
#   endif
#   if defined(__SSE4_2__)
#     define PINTS_SSE4_2 1
#   endif
#   if defined(__AVX__)
#     define PINTS_AVX 1
#   endif
#   if defined(__AVX2__)
#     define PINTS_AVX2 1
#   endif
#   if defined(__FMA__)
#     define PINTS_AVX2_FMA 1
#   endif
#   if defined(__AVX512F__)
#     define PINTS_AVX512 1
#   endif
# endif

#endif // PINTS_BACKEND_ARCH_DETECT_H
