# PintS

Portable intrinsics for SIMD

Doxygen documentation: http://lemaitre-thesis.github.io/pints/

## What is it?

PintS is an abstraction library to write SIMD code.
It is fully compatible with both C and C++ and it is a header only library.

The main goal is to provide a library to have the same code
on multiple SIMD architecture or even without SIMD.

## How does it work?

The library consists in definitions of the functions for non SIMD architectures,
and specialization of some of them for SIMD architectures.
These specializations are done by undefining the previous macro
(which can be an alias to a function)
and redefining it for the target architecture.

## How does it look?

~~~c
float dotprod_v8f(const float* a, const float* b, int n) {
  // Local var declarations
  int i;
  v8i vmask;
  v8f va, vb, s,
      sp, add1, add1p, add2, add2p, add3; // used only for the final reduction

  // initialization
  s = v8f_zero();

  // main loop
  for (i = 0; i < n - 8; i += 8) {
    va = v8f_loadu(&a[i]);
    vb = v8f_loadu(&b[i]);
    s = v8f_fmadd(va, vb, s);

  } /* remainder */ {
    vmask = v8i_gt(v8i_set1(n-i), v8i_set(0, 1, 2, 3, 4, 5, 6, 7));
    va = v8f_loadu(&a[i]);
    vb = v8f_loadu(&b[i]);
    va = v8f_and(va, v8f_cast_v8i(vmask));
    s = v8f_fmadd(va, vb, s);
  }

  // reduce s
  sp = v8f_permute2(s, PINTS_SHUFFLE(1, 0));
  add1 = v8f_add(s, sp);
  add1p = v8f_permute4x2(add1, PINTS_SHUFFLE(2, 3, 0, 1));
  add2 = v8f_add(add1, add1p);
  add2p = v8f_permute2x4(add2, PINTS_SHUFFLE(1, 0));
  add3 = v8f_add(add2, add2p);

  // convert 1st element of add3 to float
  return sf_cvt_v8f(add3);
}
~~~

## Supported architectures

For now, the supported architectures are:
- SSE
- SSE2
- SSE3
- SSSE3
- SSE4.1
- SSE4.2
- AVX
- AVX2
- FMA (AVX)

It is planned to also support in the future:
- KNC
- AVX512 (all variants)
- Neon

## Future features

It is planned to add the following features to the library:
- Reductions (eg: full horizontal sum)
- Transpositions (of vectors)
- Masks primitives (for AVX512 and KNC support)
- Shuffles with vector of indices
- per instruction Rounding method? (only when supported)


## Disclaimer

This project is still in development and might not be stable enough
for a production use.
