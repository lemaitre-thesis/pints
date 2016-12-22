#pragma once
#ifdef __SSE2__
#include "immintrin.h"

#define ISA ISA::SSE

/**
 * Vec class
 */
template <>
class Vec<float, 1> : public detail::VecHelper<__m128> {
  using detail::VecHelper<__m128>::VecHelper;
};
template <>
class Vec<float, 2> : public detail::VecHelper<__m128> {
  using detail::VecHelper<__m128>::VecHelper;
};
template <>
class Vec<float, 4> : public detail::VecHelper<__m128> {
  using detail::VecHelper<__m128>::VecHelper;
};

template <>
class Vec<double, 1> : public detail::VecHelper<__m128d> {
  using detail::VecHelper<__m128d>::VecHelper;
};
template <>
class Vec<double, 2> : public detail::VecHelper<__m128d> {
  using detail::VecHelper<__m128d>::VecHelper;
};


namespace Op {
  /**
   * Get low
   */
  Vec<float, 1> call(low<float, 2>, ISA, Vec<float, 2> v) {
    return Vec<float, 1>(v.inner);
  }
  Vec<float, 2> call(low<float, 4>, ISA, Vec<float, 4> v) {
    return Vec<float, 2>(v.inner);
  }

  Vec<double, 1> call(low<double, 2>, ISA, Vec<double, 2> v) {
    return Vec<double, 1>(v.inner);
  }

  /**
   * Get high
   */
  Vec<float, 1> call(high<float, 2>, ISA, Vec<float, 2> v) {
    return Vec<float, 1>(_mm_shuffle_ps(v.inner, v.inner, 0x1));
  }
  Vec<float, 2> call(high<float, 4>, ISA, Vec<float, 4> v) {
    return Vec<float, 2>(_mm_shuffle_ps(v.inner, v.inner, 0xE));
  }

  Vec<double, 1> call(high<double, 2>, ISA, Vec<double, 2> v) {
    return Vec<double, 1>(_mm_shuffle_pd(v.inner, v.inner, 0x1));
  }

  /**
   * Merge
   */
  Vec<float, 2> call(merge<float, 1>, ISA, Vec<float, 1> low, Vec<float, 1> high) {
    return Vec<float, 2>(_mm_unpacklo_ps(high.inner, low.inner));
  }
  Vec<float, 4> call(merge<float, 2>, ISA, Vec<float, 2> low, Vec<float, 2> high) {
    return Vec<float, 4>(_mm_shuffle_ps(high.inner, low.inner, 0x44));
  }
  Vec<double, 2> call(merge<double, 1>, ISA, Vec<double, 1> low, Vec<double, 1> high) {
    return Vec<double, 2>(_mm_unpacklo_pd(high.inner, low.inner));
  }

  /**
   * load
   */
  Vec<float, 1> call(load<float, 1>, ISA, const float* p) {
    return Vec<float, 1>(_mm_load_ss(p));
  }

  // Load2 is created from Load1

  Vec<float, 4> call(load<float, 4>, ISA, const float* p) {
    return Vec<float, 4>(_mm_loadu_ps(p));
  }

  Vec<double, 1> call(load<double, 1>, ISA, const double* p) {
    return Vec<double, 1>(_mm_load_sd(p));
  }

  Vec<double, 2> call(load<double, 2>, ISA, const double* p) {
    return Vec<double, 2>(_mm_loadu_pd(p));
  }

  /**
   * store
   */
  void call(store<float, 1>, ISA, float* p, Vec<float, 1> v) {
    _mm_store_ss(p, v.inner);
  }

  // store2 is created from store1

  void call(store<float, 4>, ISA, float* p, Vec<float, 4> v) {
    _mm_storeu_ps(p, v.inner);
  }

  void call(store<double, 1>, ISA, double* p, Vec<double, 1> v) {
    _mm_store_sd(p, v.inner);
  }

  void call(store<double, 2>, ISA, double* p, Vec<double, 2> v) {
    _mm_storeu_pd(p, v.inner);
  }

  /**
   * Add
   */
  Vec<float, 1> call(add<float, 1>, ISA, Vec<float, 1> a, Vec<float, 1> b) {
    return Vec<float, 1>(_mm_add_ss(a.inner, b.inner));
  }
  Vec<float, 2> call(add<float, 2>, ISA, Vec<float, 2> a, Vec<float, 2> b) {
    return Vec<float, 2>(_mm_add_ps(a.inner, b.inner));
  }
  Vec<float, 4> call(add<float, 4>, ISA, Vec<float, 4> a, Vec<float, 4> b) {
    return Vec<float, 4>(_mm_add_ps(a.inner, b.inner));
  }

  Vec<double, 1> call(add<double, 1>, ISA, Vec<double, 1> a, Vec<double, 1> b) {
    return Vec<double, 1>(_mm_add_sd(a.inner, b.inner));
  }
  Vec<double, 2> call(add<double, 2>, ISA, Vec<double, 2> a, Vec<double, 2> b) {
    return Vec<double, 2>(_mm_add_pd(a.inner, b.inner));
  }

  /**
   * Sub
   */
  Vec<float, 1> call(sub<float, 1>, ISA, Vec<float, 1> a, Vec<float, 1> b) {
    return Vec<float, 1>(_mm_sub_ss(a.inner, b.inner));
  }
  Vec<float, 2> call(sub<float, 2>, ISA, Vec<float, 2> a, Vec<float, 2> b) {
    return Vec<float, 2>(_mm_sub_ps(a.inner, b.inner));
  }
  Vec<float, 4> call(sub<float, 4>, ISA, Vec<float, 4> a, Vec<float, 4> b) {
    return Vec<float, 4>(_mm_sub_ps(a.inner, b.inner));
  }

  Vec<double, 1> call(sub<double, 1>, ISA, Vec<double, 1> a, Vec<double, 1> b) {
    return Vec<double, 1>(_mm_sub_sd(a.inner, b.inner));
  }
  Vec<double, 2> call(sub<double, 2>, ISA, Vec<double, 2> a, Vec<double, 2> b) {
    return Vec<double, 2>(_mm_sub_pd(a.inner, b.inner));
  }

  /**
   * Mul
   */
  Vec<float, 1> call(mul<float, 1>, ISA, Vec<float, 1> a, Vec<float, 1> b) {
    return Vec<float, 1>(_mm_mul_ss(a.inner, b.inner));
  }
  Vec<float, 2> call(mul<float, 2>, ISA, Vec<float, 2> a, Vec<float, 2> b) {
    return Vec<float, 2>(_mm_mul_ps(a.inner, b.inner));
  }
  Vec<float, 4> call(mul<float, 4>, ISA, Vec<float, 4> a, Vec<float, 4> b) {
    return Vec<float, 4>(_mm_mul_ps(a.inner, b.inner));
  }

  Vec<double, 1> call(mul<double, 1>, ISA, Vec<double, 1> a, Vec<double, 1> b) {
    return Vec<double, 1>(_mm_mul_sd(a.inner, b.inner));
  }
  Vec<double, 2> call(mul<double, 2>, ISA, Vec<double, 2> a, Vec<double, 2> b) {
    return Vec<double, 2>(_mm_mul_pd(a.inner, b.inner));
  }

  /**
   * Div
   */
  Vec<float, 1> call(div<float, 1>, ISA, Vec<float, 1> a, Vec<float, 1> b) {
    return Vec<float, 1>(_mm_div_ss(a.inner, b.inner));
  }
  Vec<float, 2> call(div<float, 2>, ISA, Vec<float, 2> a, Vec<float, 2> b) {
    return Vec<float, 2>(_mm_div_ps(a.inner, b.inner));
  }
  Vec<float, 4> call(div<float, 4>, ISA, Vec<float, 4> a, Vec<float, 4> b) {
    return Vec<float, 4>(_mm_div_ps(a.inner, b.inner));
  }

  Vec<double, 1> call(div<double, 1>, ISA, Vec<double, 1> a, Vec<double, 1> b) {
    return Vec<double, 1>(_mm_div_sd(a.inner, b.inner));
  }
  Vec<double, 2> call(div<double, 2>, ISA, Vec<double, 2> a, Vec<double, 2> b) {
    return Vec<double, 2>(_mm_div_pd(a.inner, b.inner));
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
  Vec<float, 1> call(cast<float, 1, float, 2>, ISA, Vec<float, 2> v) {
    return Vec<float, 1>(v.inner);
  }
  Vec<float, 1> call(cast<float, 1, float, 4>, ISA, Vec<float, 4> v) {
    return Vec<float, 1>(v.inner);
  }
  Vec<float, 2> call(cast<float, 2, float, 4>, ISA, Vec<float, 4> v) {
    return Vec<float, 2>(v.inner);
  }

  Vec<double, 1> call(cast<double, 1, double, 2>, ISA, Vec<double, 2> v) {
    return Vec<double, 1>(v.inner);
  }

  // up casts
  Vec<float, 2> call(cast<float, 2, float, 1>, ISA, Vec<float, 1> v) {
    return Vec<float, 2>(v.inner);
  }
  Vec<float, 4> call(cast<float, 4, float, 1>, ISA, Vec<float, 1> v) {
    return Vec<float, 4>(v.inner);
  }
  Vec<float, 4> call(cast<float, 4, float, 2>, ISA, Vec<float, 2> v) {
    return Vec<float, 4>(v.inner);
  }

  Vec<double, 2> call(cast<double, 2, double, 1>, ISA, Vec<double, 1> v) {
    return Vec<double, 2>(v.inner);
  }

  // type casts
  Vec<float, 2> call(cast<float, 2, double, 1>, ISA, Vec<double, 1> v) {
    return Vec<float, 2>(_mm_castpd_ps(v.inner));
  }
  Vec<float, 4> call(cast<float, 4, double, 2>, ISA, Vec<double, 2> v) {
    return Vec<float, 4>(_mm_castpd_ps(v.inner));
  }

  Vec<double, 1> call(cast<double, 1, float, 2>, ISA, Vec<float, 2> v) {
    return Vec<double, 1>(_mm_castps_pd(v.inner));
  }
  Vec<double, 2> call(cast<double, 2, float, 4>, ISA, Vec<float, 4> v) {
    return Vec<double, 2>(_mm_castps_pd(v.inner));
  }

  /**
   * Convert
   */
  Vec<float, 1> call(convert<float, 1, double, 1>, ISA, Vec<double, 1> v) {
    return Vec<float, 1>(_mm_cvtsd_ss(_mm_undefined_ps(), v.inner));
  }
  Vec<float, 2> call(convert<float, 2, double, 2>, ISA, Vec<double, 2> v) {
    return Vec<float, 2>(_mm_cvtpd_ps(v.inner));
  }

  Vec<double, 1> call(convert<double, 1, float, 1>, ISA, Vec<float, 1> v) {
    return Vec<double, 1>(_mm_cvtss_sd(_mm_undefined_pd(), v.inner));
  }
  Vec<double, 2> call(convert<double, 2, float, 2>, ISA, Vec<float, 2> v) {
    return Vec<double, 2>(_mm_cvtps_pd(v.inner));
  }
}
#undef ISA
#endif
