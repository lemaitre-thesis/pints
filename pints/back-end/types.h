#ifndef PINTS_BACKEND_TYPES_H
#define PINTS_BACKEND_TYPES_H

#include "../utility/types.h"
#include "./arch/props.h"

namespace pints {
  namespace backend {

    // recursive runtime mask
    template <class T, int N>
    struct rt_mask {
      rt_mask<T, N/2> low, high;
    };

    // Single element mask
    template <class T>
    struct rt_mask<T, 1> {
      bool inner;
    };

    // recursive SIMD register
    template <class T, int N>
    struct alignas(utility::min(arch::isa::max_align(), (int) alignof(T) * N)) simd {
      simd<T, N/2> low, high;

      using mask = rt_mask<T, N>;
      using indices = simd<typename utility::smallest_int<8*sizeof(T)>::s, N>;
    };

    // Single value SIMD register
    template <class T>
    struct simd<T, 1> {
      T inner;
    };

    // runtime indices are just SIMD registers of ints with same size
    template <class T, int N>
    using rt_indices = typename simd<T, N>::indices;

    // Type agnostic runtime mask is a SIMD register of bits
    template <int N>
    struct rt_mask<void, N> : simd<types::uint8, utility::max(1, N/8)> {};

    // Compile time mask
    template <bool... N>
    struct mask {};

    // Compile time indices
    template <int... N>
    struct indices {};

  }
}

#endif // PINTS_BACKEND_TYPES_H
