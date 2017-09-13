#ifndef PINTS_BACKEND_FUN_FWD
#define PINTS_BACKEND_FUN_FWD

#include "./types.h"

namespace pints {
  namespace backend {
    // Assign
    template <class Mask, class T, int N>
    simd<T, N> assign(Mask, simd<T, N>);

    // Loads
    template <class T, int N>
    simd<T, N> load(const T*);
    template <class T, int N, class Mask>
    simd<T, N> load(Mask, const T*);

    // Aligned loads
    template <class T, int N>
    simd<T, N> loada(const T*);
    template <class T, int N, class Mask>
    simd<T, N> loada(Mask, const T*);

    // Stores
    template <class T, int N>
    void store(const T*, simd<T, N>);
    template <class T, int N, class Mask>
    void store(Mask, const T*, simd<T, N>);

    // Aligned Stores
    template <class T, int N>
    void storea(const T*, simd<T, N>);
    template <class T, int N, class Mask>
    void storea(Mask, const T*, simd<T, N>);

    // Extract Low
    template <class T, int N>
    simd<T, N/2> low(simd<T, N>);

    // Extract High
    template <class T, int N>
    simd<T, N/2> high(simd<T, N>);

    // Merge
    template <class T, int N>
    simd<T, N*2> high(simd<T, N>, simd<T, N>);

    // Blend
    template <class Inner, class Outer, class Mask, class T, int N>
    simd<T, N> blend(Inner, Outer, Mask, simd<T, N>, simd<T, N>);

    // Half Shuffle
    template <class Inner, class Outer, class Indices, class T, int N>
    simd<T, N> swizzle(Inner, Outer, Indices, simd<T, N>, simd<T, N>);
    // Full Shuffle
    template <class Inner, class Outer, class Mask, class Indices, class T, int N>
    simd<T, N> swizzle(Inner, Outer, Mask, Indices, simd<T, N>, simd<T, N>);

    // Cast & Convert
    // cast
    template <class T2, int N2, class T1, int N1>
    simd<T2, N2> cast(simd<T1, N1>);

    // convert
    template <class T2, int N2, class T1, int N1>
    simd<T2, N2> convert(simd<T1, N1>);

    // Arithmetic
    // add
    template <class T, int N>
    simd<T, N> add(simd<T, N>, simd<T, N>);

    // sub
    template <class T, int N>
    simd<T, N> sub(simd<T, N>, simd<T, N>);

    // mul
    template <class T, int N>
    simd<T, N> mul(simd<T, N>, simd<T, N>);

    // madd
    template <class Accuracy, class T, int N>
    simd<T, N> madd(Accuracy, simd<T, N>, simd<T, N>, simd<T, N>);
    // msub
    template <class Accuracy, class T, int N>
    simd<T, N> msub(Accuracy, simd<T, N>, simd<T, N>, simd<T, N>);
    // nmadd
    template <class Accuracy, class T, int N>
    simd<T, N> nmadd(Accuracy, simd<T, N>, simd<T, N>, simd<T, N>);
    // nmsub
    template <class Accuracy, class T, int N>
    simd<T, N> nmsub(Accuracy, simd<T, N>, simd<T, N>, simd<T, N>);

    // div
    template <class Accuracy, class T, int N>
    simd<T, N> div(Accuracy, simd<T, N>, simd<T, N>);

    namespace math {
      // rcp
      template <class Accuracy, class T, int N>
      simd<T, N> rcp(Accuracy, simd<T, N>);

      // sqrt
      template <class Accuracy, class T, int N>
      simd<T, N> sqrt(Accuracy, simd<T, N>);

      // rsqrt
      template <class Accuracy, class T, int N>
      simd<T, N> rsqrt(Accuracy, simd<T, N>);
    }
  }
}

#endif // PINTS_BACKEND_FUN_FWD
