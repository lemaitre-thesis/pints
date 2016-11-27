#pragma once
#ifdef __AVX__
#include "immintrin.h"


/**
 * Vec class
 */
template <>
class Vec<float, 8> : public VecHelper<__m256> {
  using VecHelper<__m256>::VecHelper;
};

template <>
class Vec<double, 4> : public VecHelper<__m256d> {
  using VecHelper<__m256d>::VecHelper;
};


/**
 * Get low
 */
template <>
inline Vec<float, 4> vlow(Vec<float, 8> v) {
  return Vec<float, 4>(_mm256_castps256_ps128(v.inner));
}

template <>
inline Vec<double, 2> vlow(Vec<double, 4> v) {
  return Vec<double, 2>(_mm256_castpd256_pd128(v.inner));
}

/**
 * Get high
 */
template <>
inline Vec<float, 4> vhigh(Vec<float, 8> v) {
  return Vec<float, 4>(_mm256_extractf128_ps(v.inner, 1));
}

template <>
inline Vec<double, 2> vhigh(Vec<double, 4> v) {
  return Vec<double, 2>(_mm256_extractf128_pd(v.inner, 1));
}

/**
 * Merge
 */
template <>
inline Vec<float, 8> merge(Vec<float, 4> low, Vec<float, 4> high) {
  return Vec<float, 8>(_mm256_insertf128_ps(_mm256_castps128_ps256(low.inner), high.inner, 1));
}

template <>
inline Vec<double, 4> merge(Vec<double, 2> low, Vec<double, 2> high) {
  return Vec<double, 4>(_mm256_insertf128_pd(_mm256_castpd128_pd256(low.inner), high.inner, 1));
}

/**
 * load
 */
template <>
inline Vec<float, 8> vload<float, 8>(const float* p) {
  return Vec<float, 8>(_mm256_loadu_ps(p));
}


template <>
inline Vec<double, 4> vload<double, 4>(const double* p) {
  return Vec<double, 4>(_mm256_loadu_pd(p));
}

/**
 * store
 */
template <>
inline void vstore(float* p, Vec<float, 8> v) {
  _mm256_storeu_ps(p, v.inner);
}


template <>
inline void vstore(double* p, Vec<double, 4> v) {
  _mm256_storeu_pd(p, v.inner);
}

/**
 * Add
 */
template <>
inline Vec<float, 8> vadd(Vec<float, 8> a, Vec<float, 8> b) {
  return Vec<float, 8>(_mm256_add_ps(a.inner, b.inner));
}

template <>
inline Vec<double, 4> vadd(Vec<double, 4> a, Vec<double, 4> b) {
  return Vec<double, 4>(_mm256_add_pd(a.inner, b.inner));
}

/**
 * Sub
 */
template <>
inline Vec<float, 8> vsub(Vec<float, 8> a, Vec<float, 8> b) {
  return Vec<float, 8>(_mm256_sub_ps(a.inner, b.inner));
}

template <>
inline Vec<double, 4> vsub(Vec<double, 4> a, Vec<double, 4> b) {
  return Vec<double, 4>(_mm256_sub_pd(a.inner, b.inner));
}

/**
 * Mul
 */
template <>
inline Vec<float, 8> vmul(Vec<float, 8> a, Vec<float, 8> b) {
  return Vec<float, 8>(_mm256_mul_ps(a.inner, b.inner));
}

template <>
inline Vec<double, 4> vmul(Vec<double, 4> a, Vec<double, 4> b) {
  return Vec<double, 4>(_mm256_mul_pd(a.inner, b.inner));
}

/**
 * Div
 */
template <>
inline Vec<float, 8> vdiv(Vec<float, 8> a, Vec<float, 8> b) {
  return Vec<float, 8>(_mm256_div_ps(a.inner, b.inner));
}

template <>
inline Vec<double, 4> vdiv(Vec<double, 4> a, Vec<double, 4> b) {
  return Vec<double, 4>(_mm256_div_pd(a.inner, b.inner));
}

/**
 * FMA
 */
#ifndef __FMA__
template <>
inline Vec<float, 8> vfma(Vec<float, 8> a, Vec<float, 8> b, Vec<float, 8> c) {
  return fallback::vfma(a, b, c);
}

template <>
inline Vec<double, 4> vfma(Vec<double, 4> a, Vec<double, 4> b, Vec<double, 4> c) {
  return fallback::vfma(a, b, c);
}
#else
template <>
inline Vec<float, 8> vfma(Vec<float, 8> a, Vec<float, 8> b, Vec<float, 8> c) {
  return Vec<float, 8>(_mm256_fmadd_ps(a.inner, b.inner, c.inner));
}

template <>
inline Vec<double, 4> vfma(Vec<double, 4> a, Vec<double, 4> b, Vec<double, 4> c) {
  return Vec<double, 4>(_mm256_fmadd_pd(a.inner, b.inner, c.inner));
}
#endif

/**
 * Cast
 */
// down casts
template <>
inline Vec<float, 4> vcast<float, 4>(Vec<float, 8> v) {
  return vlow(v);
}
template <>
inline Vec<double, 2> vcast<double, 2>(Vec<double, 4> v) {
  return vlow(v);
}

// up casts
template <>
inline Vec<float, 8> vcast<float, 8>(Vec<float, 4> v) {
  return Vec<float, 8>(_mm256_castps128_ps256(v.inner));
}

template <>
inline Vec<double, 4> vcast<double, 4>(Vec<double, 2> v) {
  return Vec<double, 4>(_mm256_castpd128_pd256(v.inner));
}

// type casts
template <>
inline Vec<float, 8> vcast<float, 8>(Vec<double, 4> v) {
  return Vec<float, 8>(_mm256_castpd_ps(v.inner));
}
template <>
inline Vec<double, 4> vcast<double, 4>(Vec<float, 8> v) {
  return Vec<double, 4>(_mm256_castps_pd(v.inner));
}

/**
 * Convert
 */
template <>
inline Vec<float, 4> vconvert<float, 4>(Vec<double, 4> v) {
  return Vec<float, 4>(_mm256_cvtpd_ps(v.inner));
}

template <>
inline Vec<double, 4> vconvert<double, 4>(Vec<float, 4> v) {
  return Vec<double, 4>(_mm256_cvtps_pd(v.inner));
}
#endif
