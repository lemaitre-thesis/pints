#pragma once
#ifdef __AVX__
#include "immintrin.h"

#define ISA ISA::AVX

/**
 * Vec class
 */
template <>
class Vec<float, 8> : public detail::VecHelper<__m256> {
  using detail::VecHelper<__m256>::VecHelper;
};

template <>
class Vec<double, 4> : public detail::VecHelper<__m256d> {
  using detail::VecHelper<__m256d>::VecHelper;
};


namespace Op {
  /**
   * Get low
   */
  Vec<float, 4> call(low<float, 8>, ISA, Vec<float, 8> v) {
    return Vec<float, 4>(_mm256_castps256_ps128(v.inner));
  }

  Vec<double, 2> call(low<double, 4>, ISA, Vec<double, 4> v) {
    return Vec<double, 2>(_mm256_castpd256_pd128(v.inner));
  }

  /**
   * Get high
   */
  Vec<float, 4> call(high<float, 8>, ISA, Vec<float, 8> v) {
    return Vec<float, 4>(_mm256_extractf128_ps(v.inner, 1));
  }

  Vec<double, 2> call(high<double, 4>, ISA, Vec<double, 4> v) {
    return Vec<double, 2>(_mm256_extractf128_pd(v.inner, 1));
  }

  /**
   * Merge
   */
  Vec<float, 8> call(merge<float, 4>, ISA, Vec<float, 4> low, Vec<float, 4> high) {
    return Vec<float, 8>(_mm256_insertf128_ps(_mm256_castps128_ps256(low.inner), high.inner, 1));
  }
  Vec<double, 4> call(merge<double, 2>, ISA, Vec<double, 2> low, Vec<double, 2> high) {
    return Vec<double, 4>(_mm256_insertf128_pd(_mm256_castpd128_pd256(low.inner), high.inner, 1));
  }

  /**
   * load
   */
  Vec<float, 8> call(load<float, 8>, ISA, const float* p) {
    return Vec<float, 8>(_mm256_loadu_ps(p));
  }

  Vec<double, 4> call(load<double, 4>, ISA, const double* p) {
    return Vec<double, 4>(_mm256_loadu_pd(p));
  }

  /**
   * store
   */
  void call(store<float, 8>, ISA, float* p, Vec<float, 8> v) {
    _mm256_storeu_ps(p, v.inner);
  }

  void call(store<double, 4>, ISA, double* p, Vec<double, 4> v) {
    _mm256_storeu_pd(p, v.inner);
  }

  /**
   * Add
   */
  Vec<float, 8> call(add<float, 8>, ISA, Vec<float, 8> a, Vec<float, 8> b) {
    return Vec<float, 8>(_mm256_add_ps(a.inner, b.inner));
  }

  Vec<double, 4> call(add<double, 4>, ISA, Vec<double, 4> a, Vec<double, 4> b) {
    return Vec<double, 4>(_mm256_add_pd(a.inner, b.inner));
  }

  /**
   * Sub
   */
  Vec<float, 8> call(sub<float, 8>, ISA, Vec<float, 8> a, Vec<float, 8> b) {
    return Vec<float, 8>(_mm256_sub_ps(a.inner, b.inner));
  }

  Vec<double, 4> call(sub<double, 4>, ISA, Vec<double, 4> a, Vec<double, 4> b) {
    return Vec<double, 4>(_mm256_sub_pd(a.inner, b.inner));
  }

  /**
   * Mul
   */
  Vec<float, 8> call(mul<float, 8>, ISA, Vec<float, 8> a, Vec<float, 8> b) {
    return Vec<float, 8>(_mm256_mul_ps(a.inner, b.inner));
  }

  Vec<double, 4> call(mul<double, 4>, ISA, Vec<double, 4> a, Vec<double, 4> b) {
    return Vec<double, 4>(_mm256_mul_pd(a.inner, b.inner));
  }

  /**
   * Div
   */
  Vec<float, 8> call(div<float, 8>, ISA, Vec<float, 8> a, Vec<float, 8> b) {
    return Vec<float, 8>(_mm256_div_ps(a.inner, b.inner));
  }

  Vec<double, 4> call(div<double, 4>, ISA, Vec<double, 4> a, Vec<double, 4> b) {
    return Vec<double, 4>(_mm256_div_pd(a.inner, b.inner));
  }

  /**
   * FMA
   */
  template <class T, int N>
  Vec<T, N> call(fma<T, N>, ISA, Vec<T, N> a, Vec<T, N> b, Vec<T, N> c) {
    return fallback::call(fma<T, N>{}, a, b, c);
  }

  /**
   * Cast
   */
  // down casts
  Vec<float, 4> call(cast<float, 4, float, 8>, ISA, Vec<float, 8> v) {
    return vlow(v);
  }

  Vec<double, 2> call(cast<double, 2, double, 4>, ISA, Vec<double, 4> v) {
    return vlow(v);
  }

  // up casts
  Vec<float, 8> call(cast<float, 8, float, 4>, ISA, Vec<float, 4> v) {
    return Vec<float, 8>(_mm256_castps128_ps256(v.inner));
  }

  Vec<double, 4> call(cast<double, 4, double, 2>, ISA, Vec<double, 2> v) {
    return Vec<double, 4>(_mm256_castpd128_pd256(v.inner));
  }

  // type casts
  Vec<float, 8> call(cast<float, 8, double, 4>, ISA, Vec<double, 4> v) {
    return Vec<float, 8>(_mm256_castpd_ps(v.inner));
  }

  Vec<double, 4> call(cast<double, 4, float, 8>, ISA, Vec<float, 8> v) {
    return Vec<double, 4>(_mm256_castps_pd(v.inner));
  }

  /**
   * Convert
   */
  Vec<float, 4> call(convert<float, 4, double, 4>, ISA, Vec<double, 4> v) {
    return Vec<float, 4>(_mm256_cvtpd_ps(v.inner));
  }

  Vec<double, 4> call(convert<double, 4, float, 4>, ISA, Vec<float, 4> v) {
    return Vec<double, 4>(_mm256_cvtps_pd(v.inner));
  }
}


#undef ISA
#endif

#ifdef __FMA__
#define ISA ISA::FMA


namespace detail {
  /**
   * FMA
   */
  Vec<float, 1> call(fma<float, 1>, ISA, Vec<float, 1> a, Vec<float, 1> b, Vec<float, 1> c) {
    return Vec<float, 1>(_mm_fmadd_ss(a.inner, b.inner, c.inner));
  }
  Vec<float, 2> call(fma<float, 2>, ISA, Vec<float, 2> a, Vec<float, 2> b, Vec<float, 2> c) {
    return Vec<float, 2>(_mm_fmadd_ps(a.inner, b.inner, c.inner));
  }
  Vec<float, 4> call(fma<float, 4>, ISA, Vec<float, 4> a, Vec<float, 4> b, Vec<float, 4> c) {
    return Vec<float, 4>(_mm_fmadd_ps(a.inner, b.inner, c.inner));
  }
  Vec<float, 8> call(fma<float, 8>, ISA, Vec<float, 8> a, Vec<float, 8> b, Vec<float, 8> c) {
    return Vec<float, 8>(_mm256_fmadd_ps(a.inner, b.inner, c.inner));
  }


  Vec<double, 1> call(fma<double, 1>, ISA, Vec<double, 1> a, Vec<double, 1> b, Vec<double, 1> c) {
    return Vec<double, 1>(_mm_fmadd_sd(a.inner, b.inner, c.inner));
  }
  Vec<double, 2> call(fma<double, 2>, ISA, Vec<double, 2> a, Vec<double, 2> b, Vec<double, 2> c) {
    return Vec<double, 2>(_mm_fmadd_pd(a.inner, b.inner, c.inner));
  }
  Vec<double, 4> call(fma<double, 4>, ISA, Vec<double, 4> a, Vec<double, 4> b, Vec<double, 4> c) {
    return Vec<double, 4>(_mm256_fmadd_pd(a.inner, b.inner, c.inner));
  }
}

#undef ISA
#endif
