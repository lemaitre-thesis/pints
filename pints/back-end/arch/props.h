#ifndef PINTS_BACKEND_ARCH_PROPS_H
#define PINTS_BACKEND_ARCH_PROPS_H

#include "./detect.h"
#include "../../utility/types.h"
#include "../../utility/meta.h"

namespace PintS {
  namespace backend {
    namespace arch {



      // details namespace
      namespace _ {
        template <int W>
        struct isa {

          // Width (in bits) of the SIMD register
          constexpr int width() const {
            return W;
          }

          // Check hardware support for a given type
          // If no hardware support: emulation is mandatory
          template <class T>
          constexpr bool hardware_support() const {
            return PintS::utility::in<T, PintS::types::int8, PintS::types::uint8, PintS::types::int16, PintS::types::uint16, PintS::types::int32, PintS::types::uint32, PintS::types::int64, PintS::types::uint64, PintS::types::float32, PintS::types::float64>();
          }

          // Number of elements a SIMD register can have
          template <class T>
          constexpr int card() const {
            return hardware_support<T>() ? width() / (8*sizeof(T)) : 1;
          }

          // If SIMD is supported
          static constexpr bool is_simd = true;

        };
      }

      // Default "ISA": No SIMD support
      struct scalar_t {
        constexpr int width() const {
          return 0;
        }

        template <class>
        constexpr bool hardware_support() const {
          return false;
        }

        template <class>
        constexpr int card() const {
          return 1;
        }

        static constexpr bool is_simd = false;
      } constexpr scalar;

      // SSE2
      struct sse2_t : _::isa<128> {
        static constexpr const char* name = "SSE2";
      } constexpr sse2;

      // SSE3
      struct sse3_t : sse2_t {
        static constexpr const char* name = "SSE3";
      } constexpr sse3;

      // SSSE3
      struct ssse3_t : sse3_t {
        static constexpr const char* name = "SSSE3";
      } constexpr ssse3;

      // SSE4.1
      struct sse4_1_t : ssse3_t {
        static constexpr const char* name = "SSE4.1";
      } constexpr sse4_1;

      // SSE4.2
      struct sse4_2_t : sse4_1_t {
        static constexpr const char* name = "SSE4.2";
      } constexpr sse4_2;

      // AVX
      struct avx_t : _::isa<256> {
        static constexpr const char* name = "AVX";
      } constexpr avx;

      // AVX2
      struct avx2_t : avx_t {
        static constexpr const char* name = "AVX2";
      } constexpr avx2;

      // AVX2 + FMA
      struct avx2_fma_t : avx2_t {
        static constexpr const char* name = "AVX2+FMA";
      } constexpr avx2_fma;

      // AVX512
      struct avx512_t : _::isa<512> {
        static constexpr const char* name = "AVX512";
      } constexpr avx512;


#if PINTS_AVX512
      using isa_t = avx512_t;
#elif PINTS_AVX2_FMA
      using isa_t = avx2_fma_t;
#elif PINTS_AVX2
      using isa_t = avx2_t;
#elif PINTS_AVX
      using isa_t = avx_t;
#elif PINTS_SSE4_2
      using isa_t = sse4_2_t;
#elif PINTS_SSE4_1
      using isa_t = sse4_1_t;
#elif PINTS_SSSE3
      using isa_t = ssse3_t;
#elif PINTS_SSE3
      using isa_t = sse3_t;
#elif PINTS_SSE2
      using isa_t = sse2_t;
#else
      using isa_t = scalar_t;
#endif
      constexpr isa_t isa;
    }
  }
}

#endif // PINTS_BACKEND_ARCH_PROPS_H
