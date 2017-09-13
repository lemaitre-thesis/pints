#ifndef PINTS_UTILITY_TYPES
#define PINTS_UTILITY_TYPES

#include <cstdint>

namespace PintS {
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
}

#endif // PINTS_UTILITY_TYPES
