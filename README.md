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

The library is able to detect the target architecture using information
given by the compiler and loads automatically the required header files.

## How does it look?

~~~c
float dotprod_v8f(const float* a, const float* b, int n) {
  // Local var declarations
  int i;
  v8f va, vb, s;
  m8f vmask;

  // initialization
  s = v8f_zero();

  // main loop
  for (i = 0; i < n - 8; i += 8) {
    va = v8f_loadu(&a[i]);
    vb = v8f_loadu(&b[i]);
    s = v8f_fmadd(va, vb, s);

  } /* remainder */ {
    vmask = m8f_cvt_m8i(m8i_gt(v8i_set1(n-i), v8i_set(0, 1, 2, 3, 4, 5, 6, 7)));
    va = v8f_loadu(&a[i]);
    vb = v8f_loadu(&b[i]);
    va = v8f_maskz_move(vmask, va);
    s = v8f_fmadd(va, vb, s);
  }

  // reduce s
  s = v8f_reduce_add(s);

  // convert 1st element of s to float
  return sf_cvt_v8f(s);
}
~~~

## How can I use it in my project?

You need to copy the folder `include` of this repository into your project
and include the file `pints.h` wherever you want to use it.

## Supported compilers

This library has only been tested on the following compilers:
- gcc (5.1)
- icc (16.0)

However, this library is written with compatibility in mind
and should also be compatible with other compilers

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
