#ifndef PINTS_BACKEND_ARCH_PROPS_H
#define PINTS_BACKEND_ARCH_PROPS_H

#include <cstddef>
#include "./detect.h"
#include "../../utility/types.h"
#include "../../utility/fun.h"
#include "../../utility/meta.h"

namespace pints {
  namespace backend {
    namespace arch {



      // details namespace
      namespace _ {
        template <int W>
        struct isa {

          // Width (in bits) of the SIMD register
          static constexpr int width() {
            return W;
          }

          // Check hardware support for a given type
          // If no hardware support: emulation is mandatory
          template <class T>
          static constexpr bool hardware_support() {
            return utility::in<T, types::int8, types::uint8, types::int16, types::uint16, types::int32, types::uint32, types::int64, types::uint64, types::float32, types::float64>();
          }

          // Number of elements a SIMD register can have
          template <class T>
          static constexpr int card() {
            return hardware_support<T>() ? width() / (8*sizeof(T)) : 1;
          }

          // If SIMD is supported
          static constexpr bool is_simd() {
            return true;
          }

          // alignment supported
          static constexpr int max_align() {
            return utility::max((int) alignof(std::max_align_t), width() / 8);
          }

        };
      }

      // Default "ISA": No SIMD support
      struct scalar {
        static constexpr int width() {
          return 0;
        }

        template <class>
        static constexpr bool hardware_support() {
          return false;
        }

        template <class>
        static constexpr int card() {
          return 1;
        }

        static constexpr bool is_simd() {
          return false;
        }

        static constexpr int max_align() {
          return alignof(std::max_align_t);
        }
      };

      // SSE2
      struct sse2 : _::isa<128> {
        static constexpr const char* name = "SSE2";
      };

      // SSE3
      struct sse3 : sse2 {
        static constexpr const char* name = "SSE3";
      };

      // SSSE3
      struct ssse3 : sse3 {
        static constexpr const char* name = "SSSE3";
      };

      // SSE4.1
      struct sse4_1 : ssse3 {
        static constexpr const char* name = "SSE4.1";
      };

      // SSE4.2
      struct sse4_2 : sse4_1 {
        static constexpr const char* name = "SSE4.2";
      };

      // AVX
      struct avx : _::isa<256> {
        static constexpr const char* name = "AVX";
      };

      // AVX2
      struct avx2 : avx {
        static constexpr const char* name = "AVX2";
      };

      // AVX2 + FMA
      struct avx2_fma : avx2 {
        static constexpr const char* name = "AVX2+FMA";
      };

      // AVX512
      struct avx512 : _::isa<512> {
        static constexpr const char* name = "AVX512";
      };


#if PINTS_AVX512
      using isa = avx512;
#elif PINTS_AVX2_FMA
      using isa = avx2_fma;
#elif PINTS_AVX2
      using isa = avx2;
#elif PINTS_AVX
      using isa = avx;
#elif PINTS_SSE4_2
      using isa = sse4_2;
#elif PINTS_SSE4_1
      using isa = sse4_1;
#elif PINTS_SSSE3
      using isa = ssse3;
#elif PINTS_SSE3
      using isa = sse3;
#elif PINTS_SSE2
      using isa = sse2;
#else
      using isa = scalar;
#endif
    }
  }
}

#endif // PINTS_BACKEND_ARCH_PROPS_H
