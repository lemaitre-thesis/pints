#ifndef PSIMD_HELPER_H
#define PSIMD_HELPER_H

// SSE
//#define SSE
//#define SSE2
//#define SSE3
//#define SSSE3
//#define SSE41
//#define SSE42

// AVX
//#define AVX
//#define AVX2
//#define AVX_FMA
//#define AVX_KNC
//#define AVX512


#include "psimd-polyfill-defines.h"

#include "psimd-arch-detect.h"

#include "psimd-sse.h"
#include "psimd-avx.h"

#include "psimd-polyfill-funcs.h"


#endif //PSIMD_HELPER_H
