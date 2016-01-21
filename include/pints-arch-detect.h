#ifndef PINTS_ARCH_DETECT_H
#define PINTS_ARCH_DETECT_H

#ifdef __SSE__
#define SSE
#pragma message "SSE enabled"
#endif
#ifdef __SSE2__
#define SSE2
#pragma message "SSE2 enabled"
#endif
#ifdef __SSE3__
#define SSE3
#pragma message "SSE3 enabled"
#endif
#ifdef __SSSE3__
#define SSSE3
#pragma message "SSSE3 enabled"
#endif
#ifdef __SSE4_1__
#define SSE41
#pragma message "SSE41 enabled"
#endif
#ifdef __SSE4_2__
#define SSE42
#pragma message "SSE42 enabled"
#endif
#ifdef __AVX__
#define AVX
#pragma message "AVX enabled"
#endif
#ifdef __AVX2__
#define AVX2
#pragma message "AVX2 enabled"
#endif
#ifdef __FMA__
#define AVX_FMA
#pragma message "FMA enabled"
#endif
//#ifdef __AVX512F__
//#define AVX512
//#pragma message "AVX512 enabled"
//#endif
//#ifdef __MIC__
//#define AVX_KNC
//#pragma message "MIC enabled"
//#endif

#if defined(SSE) || defined(AVX) || defined(AVX512) || defined(AVX_KNC)
#include "immintrin.h"
#endif


#endif //PINTS_ARCH_DETECT_H
