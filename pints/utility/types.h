#ifndef PINTS_UTILITY_TYPES
#define PINTS_UTILITY_TYPES

#include <cstdint>
#include "./fun.h"

namespace pints {
  namespace types {
    // Signed integers
    using  int8  = std:: int8_t;
    using  int16 = std:: int16_t;
    using  int32 = std:: int32_t;
    using  int64 = std:: int64_t;

    // Unsigned integers
    using uint8  = std::uint8_t;
    using uint16 = std::uint16_t;
    using uint32 = std::uint32_t;
    using uint64 = std::uint64_t;

    // Floating points
    using float32 = float;
    using float64 = double;


  }
  namespace utility {
    namespace _ {
      template <int N>
      struct int_s {};

      template <>
      struct int_s<8> {
        using s = types:: int8;
        using u = types::uint8;
      };

      template <>
      struct int_s<16> {
        using s = types:: int16;
        using u = types::uint16;
      };

      template <>
      struct int_s<32> {
        using s = types:: int32;
        using u = types::uint32;
      };

      template <>
      struct int_s<64> {
        using s = types:: int64;
        using u = types::uint64;
      };
    }


    // Find smallest int containing N bits
    template <int N>
    using smallest_int = _::int_s<max(8, (int)next_power2(N))>;
  }
}

#endif // PINTS_UTILITY_TYPES
