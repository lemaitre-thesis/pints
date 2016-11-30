#ifndef PINTS_ARCH_DETECT_H
#define PINTS_ARCH_DETECT_H

#ifdef __SSE__
#define PINTS_SSE
#pragma message "SSE enabled"
#endif
#ifdef __SSE2__
#define PINTS_SSE2
#pragma message "SSE2 enabled"
#endif
#ifdef __SSE3__
#define PINTS_SSE3
#pragma message "SSE3 enabled"
#endif
#ifdef __SSSE3__
#define PINTS_SSSE3
#pragma message "SSSE3 enabled"
#endif
#ifdef __SSE4_1__
#define PINTS_SSE41
#pragma message "SSE41 enabled"
#endif
#ifdef __SSE4_2__
#define PINTS_SSE42
#pragma message "SSE42 enabled"
#endif
#ifdef __AVX__
#define PINTS_AVX
#pragma message "AVX enabled"
#endif
#ifdef __AVX2__
#define PINTS_AVX2
#pragma message "AVX2 enabled"
#endif
#ifdef __FMA__
#define PINTS_AVX_FMA
#pragma message "FMA enabled"
#endif
//#ifdef __AVX512F__
//#define PINTS_AVX512
//#pragma message "AVX512 enabled"
//#endif
//#ifdef __MIC__
//#define PINTS_AVX_KNC
//#pragma message "MIC enabled"
//#endif

#if defined(PINTS_SSE) || defined(PINTS_AVX) || defined(PINTS_AVX512) || defined(PINTS_AVX_KNC)
#include "immintrin.h"
#endif


#endif //PINTS_ARCH_DETECT_H
