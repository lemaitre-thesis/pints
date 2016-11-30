#pragma once
#ifdef __AVX__
#include "immintrin.h"

#define ISA 2

/**
 * Vec class
 */
template <>
class Vec<float, 8, ISA> : public detail::VecHelper<__m256> {
  using detail::VecHelper<__m256>::VecHelper;
};

template <>
class Vec<double, 4, ISA> : public detail::VecHelper<__m256d> {
  using detail::VecHelper<__m256d>::VecHelper;
};


namespace detail {
  /**
   * Get low
   */
  template <>
  struct low<float, 8, ISA> {
    static Vec<float, 4> call(Vec<float, 8> v) {
      return Vec<float, 4>(_mm256_castps256_ps128(v.inner));
    }
  };

  template <>
  struct low<double, 4, ISA> {
    static Vec<double, 2> call(Vec<double, 4> v) {
      return Vec<double, 2>(_mm256_castpd256_pd128(v.inner));
    }
  };

  /**
   * Get high
   */
  template <>
  struct high<float, 8, ISA> {
    static Vec<float, 4> call(Vec<float, 8> v) {
      return Vec<float, 4>(_mm256_extractf128_ps(v.inner, 1));
    }
  };

  template <>
  struct high<double, 4, ISA> {
    static Vec<double, 2> call(Vec<double, 4> v) {
      return Vec<double, 2>(_mm256_extractf128_pd(v.inner, 1));
    }
  };

  /**
   * Merge
   */
  template <>
  struct merge<float, 4, ISA> {
    static Vec<float, 8> call(Vec<float, 4> low, Vec<float, 4> high) {
      return Vec<float, 8>(_mm256_insertf128_ps(_mm256_castps128_ps256(low.inner), high.inner, 1));
    }
  };
  template <>
  struct merge<double, 2, ISA> {
    static Vec<double, 4> call(Vec<double, 2> low, Vec<double, 2> high) {
      return Vec<double, 4>(_mm256_insertf128_pd(_mm256_castpd128_pd256(low.inner), high.inner, 1));
    }
  };

  /**
   * load
   */
  template <>
  struct load<float, 8, ISA> {
    static Vec<float, 8> call(const float* p) {
      return Vec<float, 8>(_mm256_loadu_ps(p));
    }
  };

  template <>
  struct load<double, 4, ISA> {
    static Vec<double, 4> call(const double* p) {
      return Vec<double, 4>(_mm256_loadu_pd(p));
    }
  };

  /**
   * store
   */
  template <>
  struct store<float, 8, ISA> {
    static void call(float* p, Vec<float, 8> v) {
      _mm256_storeu_ps(p, v.inner);
    }
  };

  template <>
  struct store<double, 4, ISA> {
    static void call(double* p, Vec<double, 4> v) {
      _mm256_storeu_pd(p, v.inner);
    }
  };

  /**
   * Add
   */
  template <>
  struct add<float, 8, ISA> {
    static Vec<float, 8> call(Vec<float, 8> a, Vec<float, 8> b) {
      return Vec<float, 8>(_mm256_add_ps(a.inner, b.inner));
    }
  };

  template <>
  struct add<double, 4, ISA> {
    static Vec<double, 4> call(Vec<double, 4> a, Vec<double, 4> b) {
      return Vec<double, 4>(_mm256_add_pd(a.inner, b.inner));
    }
  };

  /**
   * Sub
   */
  template <>
  struct sub<float, 8, ISA> {
    static Vec<float, 8> call(Vec<float, 8> a, Vec<float, 8> b) {
      return Vec<float, 8>(_mm256_sub_ps(a.inner, b.inner));
    }
  };

  template <>
  struct sub<double, 4, ISA> {
    static Vec<double, 4> call(Vec<double, 4> a, Vec<double, 4> b) {
      return Vec<double, 4>(_mm256_sub_pd(a.inner, b.inner));
    }
  };

  /**
   * Mul
   */
  template <>
  struct mul<float, 8, ISA> {
    static Vec<float, 8> call(Vec<float, 8> a, Vec<float, 8> b) {
      return Vec<float, 8>(_mm256_mul_ps(a.inner, b.inner));
    }
  };

  template <>
  struct mul<double, 4, ISA> {
    static Vec<double, 4> call(Vec<double, 4> a, Vec<double, 4> b) {
      return Vec<double, 4>(_mm256_mul_pd(a.inner, b.inner));
    }
  };

  /**
   * Div
   */
  template <>
  struct div<float, 8, ISA> {
    static Vec<float, 8> call(Vec<float, 8> a, Vec<float, 8> b) {
      return Vec<float, 8>(_mm256_div_ps(a.inner, b.inner));
    }
  };

  template <>
  struct div<double, 4, ISA> {
    static Vec<double, 4> call(Vec<double, 4> a, Vec<double, 4> b) {
      return Vec<double, 4>(_mm256_div_pd(a.inner, b.inner));
    }
  };

  /**
   * FMA
   */
  template <class T, int N>
  struct fma<T, N, ISA> : public fallback::fma<T, N>{};

  /**
   * Cast
   */
  // down casts
  template <>
  struct cast<float, 4, float, 8, ISA> {
    static Vec<float, 4> call(Vec<float, 8> v) {
      return vlow(v);
    }
  };

  template <>
  struct cast<double, 2, double, 4, ISA> {
    static Vec<double, 2> call(Vec<double, 4> v) {
      return vlow(v);
    }
  };

  // up casts
  template <>
  struct cast<float, 8, float, 4, ISA> {
    static Vec<float, 8> call(Vec<float, 4> v) {
      return Vec<float, 8>(_mm256_castps128_ps256(v.inner));
    }
  };

  template <>
  struct cast<double, 4, double, 2, ISA> {
    static Vec<double, 4> call(Vec<double, 2> v) {
      return Vec<double, 4>(_mm256_castpd128_pd256(v.inner));
    }
  };

  // type casts
  template <>
  struct cast<float, 8, double, 4, ISA> {
    static Vec<float, 8> call(Vec<double, 4> v) {
      return Vec<float, 8>(_mm256_castpd_ps(v.inner));
    }
  };

  template <>
  struct cast<double, 4, float, 8, ISA> {
    static Vec<double, 4> call(Vec<float, 8> v) {
      return Vec<double, 4>(_mm256_castps_pd(v.inner));
    }
  };

  /**
   * Convert
   */
  template <>
  struct convert<float, 4, double, 4, ISA> {
    static Vec<float, 4> call(Vec<double, 4> v) {
      return Vec<float, 4>(_mm256_cvtpd_ps(v.inner));
    }
  };

  template <>
  struct convert<double, 4, float, 4, ISA> {
    static Vec<double, 4> call(Vec<float, 4> v) {
      return Vec<double, 4>(_mm256_cvtps_pd(v.inner));
    }
  };
}


#undef ISA
#endif

#ifdef __FMA__
#define ISA 3


namespace detail {
  /**
   * FMA
   */
  template <>
  struct fma<float, 1, ISA> {
    static Vec<float, 1> call(Vec<float, 1> a, Vec<float, 1> b, Vec<float, 1> c) {
      return Vec<float, 1>(_mm_fmadd_ss(a.inner, b.inner, c.inner));
    }
  };
  template <>
  struct fma<float, 2, ISA> {
    static Vec<float, 2> call(Vec<float, 2> a, Vec<float, 2> b, Vec<float, 2> c) {
      return Vec<float, 2>(_mm_fmadd_ps(a.inner, b.inner, c.inner));
    }
  };
  template <>
  struct fma<float, 4, ISA> {
    static Vec<float, 4> call(Vec<float, 4> a, Vec<float, 4> b, Vec<float, 4> c) {
      return Vec<float, 4>(_mm_fmadd_ps(a.inner, b.inner, c.inner));
    }
  };
  template <>
  struct fma<float, 8, ISA> {
    static Vec<float, 8> call(Vec<float, 8> a, Vec<float, 8> b, Vec<float, 8> c) {
      return Vec<float, 8>(_mm256_fmadd_ps(a.inner, b.inner, c.inner));
    }
  };


  template <>
  struct fma<double, 1, ISA> {
    static Vec<double, 1> call(Vec<double, 1> a, Vec<double, 1> b, Vec<double, 1> c) {
      return Vec<double, 1>(_mm_fmadd_sd(a.inner, b.inner, c.inner));
    }
  };
  template <>
  struct fma<double, 2, ISA> {
    static Vec<double, 2> call(Vec<double, 2> a, Vec<double, 2> b, Vec<double, 2> c) {
      return Vec<double, 2>(_mm_fmadd_pd(a.inner, b.inner, c.inner));
    }
  };
  template <>
  struct fma<double, 4, ISA> {
    static Vec<double, 4> call(Vec<double, 4> a, Vec<double, 4> b, Vec<double, 4> c) {
      return Vec<double, 4>(_mm256_fmadd_pd(a.inner, b.inner, c.inner));
    }
  };
}

#undef ISA
#endif
