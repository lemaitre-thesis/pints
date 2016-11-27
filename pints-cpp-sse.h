#pragma once
#ifdef __SSE2__
#include "immintrin.h"


/**
 * Vec class
 */
template <>
class Vec<float, 1> : public VecHelper<__m128> {
  using VecHelper<__m128>::VecHelper;
};
template <>
class Vec<float, 2> : public VecHelper<__m128> {
  using VecHelper<__m128>::VecHelper;
};
template <>
class Vec<float, 4> : public VecHelper<__m128> {
  using VecHelper<__m128>::VecHelper;
};

template <>
class Vec<double, 1> : public VecHelper<__m128d> {
  using VecHelper<__m128d>::VecHelper;
};
template <>
class Vec<double, 2> : public VecHelper<__m128d> {
  using VecHelper<__m128d>::VecHelper;
};


/**
 * Get low
 */
template <>
inline Vec<float, 1> vlow(Vec<float, 2> v) {
  return Vec<float, 1>(v.inner);
}
template <>
inline Vec<float, 2> vlow(Vec<float, 4> v) {
  return Vec<float, 2>(v.inner);
}

template <>
inline Vec<double, 1> vlow(Vec<double, 2> v) {
  return Vec<double, 1>(v.inner);
}

/**
 * Get high
 */
template <>
inline Vec<float, 1> vhigh(Vec<float, 2> v) {
  return Vec<float, 1>(_mm_shuffle_ps(v.inner, v.inner, 0x1));
}
template <>
inline Vec<float, 2> vhigh(Vec<float, 4> v) {
  return Vec<float, 2>(_mm_shuffle_ps(v.inner, v.inner, 0xE));
}

template <>
inline Vec<double, 1> vhigh(Vec<double, 2> v) {
  return Vec<double, 1>(_mm_shuffle_pd(v.inner, v.inner, 0x1));
}

/**
 * Merge
 */
template <>
inline Vec<float, 2> merge(Vec<float, 1> low, Vec<float, 1> high) {
  return Vec<float, 2>(_mm_unpacklo_ps(high.inner, low.inner));
}
template <>
inline Vec<float, 4> merge(Vec<float, 2> low, Vec<float, 2> high) {
  return Vec<float, 4>(_mm_shuffle_ps(high.inner, low.inner, 0x44));
}

template <>
inline Vec<double, 2> merge(Vec<double, 1> low, Vec<double, 1> high) {
  return Vec<double, 2>(_mm_shuffle_pd(high.inner, low.inner, 0));
}

/**
 * load
 */
template <>
inline Vec<float, 1> vload<float, 1>(const float* p) {
  return Vec<float, 1>(_mm_load_ss(p));
}

// Load2 is created from Load1

template <>
inline Vec<float, 4> vload<float, 4>(const float* p) {
  return Vec<float, 4>(_mm_loadu_ps(p));
}


template <>
inline Vec<double, 1> vload<double, 1>(const double* p) {
  return Vec<double, 1>(_mm_load_sd(p));
}
template <>
inline Vec<double, 2> vload<double, 2>(const double* p) {
  return Vec<double, 2>(_mm_loadu_pd(p));
}

/**
 * store
 */
template <>
inline void vstore(float* p, Vec<float, 1> v) {
  _mm_store_ss(p, v.inner);
}

// Store2 is created from Store1

template <>
inline void vstore(float* p, Vec<float, 4> v) {
  _mm_storeu_ps(p, v.inner);
}


template <>
inline void vstore(double* p, Vec<double, 1> v) {
  _mm_store_sd(p, v.inner);
}

template <>
inline void vstore(double* p, Vec<double, 2> v) {
  _mm_storeu_pd(p, v.inner);
}

/**
 * Add
 */
template <>
inline Vec<float, 1> vadd(Vec<float, 1> a, Vec<float, 1> b) {
  return Vec<float, 1>(_mm_add_ss(a.inner, b.inner));
}
template <>
inline Vec<float, 2> vadd(Vec<float, 2> a, Vec<float, 2> b) {
  return Vec<float, 2>(_mm_add_ps(a.inner, b.inner));
}
template <>
inline Vec<float, 4> vadd(Vec<float, 4> a, Vec<float, 4> b) {
  return Vec<float, 4>(_mm_add_ps(a.inner, b.inner));
}

template <>
inline Vec<double, 1> vadd(Vec<double, 1> a, Vec<double, 1> b) {
  return Vec<double, 1>(_mm_add_sd(a.inner, b.inner));
}
template <>
inline Vec<double, 2> vadd(Vec<double, 2> a, Vec<double, 2> b) {
  return Vec<double, 2>(_mm_add_pd(a.inner, b.inner));
}

/**
 * Sub
 */
template <>
inline Vec<float, 1> vsub(Vec<float, 1> a, Vec<float, 1> b) {
  return Vec<float, 1>(_mm_sub_ss(a.inner, b.inner));
}
template <>
inline Vec<float, 2> vsub(Vec<float, 2> a, Vec<float, 2> b) {
  return Vec<float, 2>(_mm_sub_ps(a.inner, b.inner));
}
template <>
inline Vec<float, 4> vsub(Vec<float, 4> a, Vec<float, 4> b) {
  return Vec<float, 4>(_mm_sub_ps(a.inner, b.inner));
}

template <>
inline Vec<double, 1> vsub(Vec<double, 1> a, Vec<double, 1> b) {
  return Vec<double, 1>(_mm_sub_sd(a.inner, b.inner));
}
template <>
inline Vec<double, 2> vsub(Vec<double, 2> a, Vec<double, 2> b) {
  return Vec<double, 2>(_mm_sub_pd(a.inner, b.inner));
}

/**
 * Mul
 */
template <>
inline Vec<float, 1> vmul(Vec<float, 1> a, Vec<float, 1> b) {
  return Vec<float, 1>(_mm_mul_ss(a.inner, b.inner));
}
template <>
inline Vec<float, 2> vmul(Vec<float, 2> a, Vec<float, 2> b) {
  return Vec<float, 2>(_mm_mul_ps(a.inner, b.inner));
}
template <>
inline Vec<float, 4> vmul(Vec<float, 4> a, Vec<float, 4> b) {
  return Vec<float, 4>(_mm_mul_ps(a.inner, b.inner));
}

template <>
inline Vec<double, 1> vmul(Vec<double, 1> a, Vec<double, 1> b) {
  return Vec<double, 1>(_mm_mul_sd(a.inner, b.inner));
}
template <>
inline Vec<double, 2> vmul(Vec<double, 2> a, Vec<double, 2> b) {
  return Vec<double, 2>(_mm_mul_pd(a.inner, b.inner));
}

/**
 * Div
 */
template <>
inline Vec<float, 1> vdiv(Vec<float, 1> a, Vec<float, 1> b) {
  return Vec<float, 1>(_mm_div_ss(a.inner, b.inner));
}
template <>
inline Vec<float, 2> vdiv(Vec<float, 2> a, Vec<float, 2> b) {
  return Vec<float, 2>(_mm_div_ps(a.inner, b.inner));
}
template <>
inline Vec<float, 4> vdiv(Vec<float, 4> a, Vec<float, 4> b) {
  return Vec<float, 4>(_mm_div_ps(a.inner, b.inner));
}

template <>
inline Vec<double, 1> vdiv(Vec<double, 1> a, Vec<double, 1> b) {
  return Vec<double, 1>(_mm_div_sd(a.inner, b.inner));
}
template <>
inline Vec<double, 2> vdiv(Vec<double, 2> a, Vec<double, 2> b) {
  return Vec<double, 2>(_mm_div_pd(a.inner, b.inner));
}

/**
 * FMA
 */
#ifndef __FMA__
template <>
inline Vec<float, 1> vfma(Vec<float, 1> a, Vec<float, 1> b, Vec<float, 1> c) {
  return fallback::vfma(a, b, c);
}
template <>
inline Vec<float, 2> vfma(Vec<float, 2> a, Vec<float, 2> b, Vec<float, 2> c) {
  return fallback::vfma(a, b, c);
}
template <>
inline Vec<float, 4> vfma(Vec<float, 4> a, Vec<float, 4> b, Vec<float, 4> c) {
  return fallback::vfma(a, b, c);
}

template <>
inline Vec<double, 1> vfma(Vec<double, 1> a, Vec<double, 1> b, Vec<double, 1> c) {
  return fallback::vfma(a, b, c);
}
template <>
inline Vec<double, 2> vfma(Vec<double, 2> a, Vec<double, 2> b, Vec<double, 2> c) {
  return fallback::vfma(a, b, c);
}
#else
template <>
inline Vec<float, 1> vfma(Vec<float, 1> a, Vec<float, 1> b, Vec<float, 1> c) {
  return Vec<float, 1>(_mm_fmadd_ss(a.inner, b.inner, c.inner));
}
template <>
inline Vec<float, 2> vfma(Vec<float, 2> a, Vec<float, 2> b, Vec<float, 2> c) {
  return Vec<float, 2>(_mm_fmadd_ps(a.inner, b.inner, c.inner));
}
template <>
inline Vec<float, 4> vfma(Vec<float, 4> a, Vec<float, 4> b, Vec<float, 4> c) {
  return Vec<float, 4>(_mm_fmadd_ps(a.inner, b.inner, c.inner));
}

template <>
inline Vec<double, 1> vfma(Vec<double, 1> a, Vec<double, 1> b, Vec<double, 1> c) {
  return Vec<double, 1>(_mm_fmadd_sd(a.inner, b.inner, c.inner));
}
template <>
inline Vec<double, 2> vfma(Vec<double, 2> a, Vec<double, 2> b, Vec<double, 2> c) {
  return Vec<double, 2>(_mm_fmadd_pd(a.inner, b.inner, c.inner));
}
#endif

/**
 * Cast
 */
// down casts
template <>
inline Vec<float, 1> vcast<float, 1>(Vec<float, 2> v) {
  return Vec<float, 1>(v.inner);
}
template <>
inline Vec<float, 1> vcast<float, 1>(Vec<float, 4> v) {
  return Vec<float, 1>(v.inner);
}
template <>
inline Vec<float, 2> vcast<float, 2>(Vec<float, 4> v) {
  return Vec<float, 2>(v.inner);
}
template <>
inline Vec<double, 1> vcast<double, 1>(Vec<double, 2> v) {
  return Vec<double, 1>(v.inner);
}

// up casts
template <>
inline Vec<float, 2> vcast<float, 2>(Vec<float, 1> v) {
  return Vec<float, 2>(v.inner);
}
template <>
inline Vec<float, 4> vcast<float, 4>(Vec<float, 1> v) {
  return Vec<float, 4>(v.inner);
}
template <>
inline Vec<float, 4> vcast<float, 4>(Vec<float, 2> v) {
  return Vec<float, 4>(v.inner);
}

template <>
inline Vec<double, 2> vcast<double, 2>(Vec<double, 1> v) {
  return Vec<double, 2>(v.inner);
}

// type casts
template <>
inline Vec<float, 2> vcast<float, 2>(Vec<double, 1> v) {
  return Vec<float, 2>(_mm_castpd_ps(v.inner));
}
template <>
inline Vec<double, 1> vcast<double, 1>(Vec<float, 2> v) {
  return Vec<double, 1>(_mm_castps_pd(v.inner));
}

template <>
inline Vec<float, 4> vcast<float, 4>(Vec<double, 2> v) {
  return Vec<float, 4>(_mm_castpd_ps(v.inner));
}
template <>
inline Vec<double, 2> vcast<double, 2>(Vec<float, 4> v) {
  return Vec<double, 2>(_mm_castps_pd(v.inner));
}

/**
 * Convert
 */
template <>
inline Vec<float, 1> vconvert<float, 1>(Vec<double, 1> v) {
  return Vec<float, 1>(_mm_cvtsd_ss(_mm_undefined_ps(), v.inner));
}
template <>
inline Vec<float, 2> vconvert<float, 2>(Vec<double, 2> v) {
  return Vec<float, 2>(_mm_cvtpd_ps(v.inner));
}

template <>
inline Vec<double, 1> vconvert<double, 1>(Vec<float, 1> v) {
  return Vec<double, 1>(_mm_cvtss_sd(_mm_undefined_pd(), v.inner));
}
template <>
inline Vec<double, 2> vconvert<double, 2>(Vec<float, 2> v) {
  return Vec<double, 2>(_mm_cvtps_pd(v.inner));
}
#endif
