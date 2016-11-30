#pragma once
#ifdef __SSE2__
#include "immintrin.h"

#define ISA 1

/**
 * Vec class
 */
template <>
class Vec<float, 1, ISA> : public detail::VecHelper<__m128> {
  using detail::VecHelper<__m128>::VecHelper;
};
template <>
class Vec<float, 2, ISA> : public detail::VecHelper<__m128> {
  using detail::VecHelper<__m128>::VecHelper;
};
template <>
class Vec<float, 4, ISA> : public detail::VecHelper<__m128> {
  using detail::VecHelper<__m128>::VecHelper;
};

template <>
class Vec<double, 1, ISA> : public detail::VecHelper<__m128d> {
  using detail::VecHelper<__m128d>::VecHelper;
};
template <>
class Vec<double, 2, ISA> : public detail::VecHelper<__m128d> {
  using detail::VecHelper<__m128d>::VecHelper;
};


namespace detail {
  /**
   * Get low
   */
  template <>
  struct low<float, 2, ISA> {
    static Vec<float, 1> call(Vec<float, 2> v) {
      return Vec<float, 1>(v.inner);
    }
  };
  template <>
  struct low<float, 4, ISA> {
    static Vec<float, 2> call(Vec<float, 4> v) {
      return Vec<float, 2>(v.inner);
    }
  };

  template <>
  struct low<double, 2, ISA> {
    static Vec<double, 1> call(Vec<double, 2> v) {
      return Vec<double, 1>(v.inner);
    }
  };

  /**
   * Get high
   */
  template <>
  struct high<float, 2, ISA> {
    static Vec<float, 1> call(Vec<float, 2> v) {
      return Vec<float, 1>(_mm_shuffle_ps(v.inner, v.inner, 0x1));
    }
  };
  template <>
  struct high<float, 4, ISA> {
    static Vec<float, 2> call(Vec<float, 4> v) {
      return Vec<float, 2>(_mm_shuffle_ps(v.inner, v.inner, 0xE));
    }
  };

  template <>
  struct high<double, 2, ISA> {
    static Vec<double, 1> call(Vec<double, 2> v) {
      return Vec<double, 1>(_mm_shuffle_pd(v.inner, v.inner, 0x1));
    }
  };

  /**
   * Merge
   */
  template <>
  struct merge<float, 1, ISA> {
    static Vec<float, 2> call(Vec<float, 1> low, Vec<float, 1> high) {
      return Vec<float, 2>(_mm_unpacklo_ps(high.inner, low.inner));
    }
  };
  template <>
  struct merge<float, 2, ISA> {
    static Vec<float, 4> call(Vec<float, 2> low, Vec<float, 2> high) {
      return Vec<float, 4>(_mm_shuffle_ps(high.inner, low.inner, 0x44));
    }
  };
  template <>
  struct merge<double, 1, ISA> {
    static Vec<double, 2> call(Vec<double, 1> low, Vec<double, 1> high) {
      return Vec<double, 2>(_mm_unpacklo_pd(high.inner, low.inner));
    }
  };

  /**
   * load
   */
  template <>
  struct load<float, 1, ISA> {
    static Vec<float, 1> call(const float* p) {
      return Vec<float, 1>(_mm_load_ss(p));
    }
  };

  // Load2 is created from Load1

  template <>
  struct load<float, 4, ISA> {
    static Vec<float, 4> call(const float* p) {
      return Vec<float, 4>(_mm_loadu_ps(p));
    }
  };

  template <>
  struct load<double, 1, ISA> {
    static Vec<double, 1> call(const double* p) {
      return Vec<double, 1>(_mm_load_sd(p));
    }
  };

  template <>
  struct load<double, 2, ISA> {
    static Vec<double, 2> call(const double* p) {
      return Vec<double, 2>(_mm_loadu_pd(p));
    }
  };

  /**
   * store
   */
  template <>
  struct store<float, 1, ISA> {
    static void call(float* p, Vec<float, 1> v) {
      _mm_store_ss(p, v.inner);
    }
  };

  // store2 is created from store1

  template <>
  struct store<float, 4, ISA> {
    static void call(float* p, Vec<float, 4> v) {
      _mm_storeu_ps(p, v.inner);
    }
  };

  template <>
  struct store<double, 1, ISA> {
    static void call(double* p, Vec<double, 1> v) {
      _mm_store_sd(p, v.inner);
    }
  };

  template <>
  struct store<double, 2, ISA> {
    static void call(double* p, Vec<double, 2> v) {
      _mm_storeu_pd(p, v.inner);
    }
  };

  /**
   * Add
   */
  template <>
  struct add<float, 1, ISA> {
    static Vec<float, 1> call(Vec<float, 1> a, Vec<float, 1> b) {
      return Vec<float, 1>(_mm_add_ss(a.inner, b.inner));
    }
  };
  template <>
  struct add<float, 2, ISA> {
    static Vec<float, 2> call(Vec<float, 2> a, Vec<float, 2> b) {
      return Vec<float, 2>(_mm_add_ps(a.inner, b.inner));
    }
  };
  template <>
  struct add<float, 4, ISA> {
    static Vec<float, 4> call(Vec<float, 4> a, Vec<float, 4> b) {
      return Vec<float, 4>(_mm_add_ps(a.inner, b.inner));
    }
  };

  template <>
  struct add<double, 1, ISA> {
    static Vec<double, 1> call(Vec<double, 1> a, Vec<double, 1> b) {
      return Vec<double, 1>(_mm_add_sd(a.inner, b.inner));
    }
  };
  template <>
  struct add<double, 2, ISA> {
    static Vec<double, 2> call(Vec<double, 2> a, Vec<double, 2> b) {
      return Vec<double, 2>(_mm_add_pd(a.inner, b.inner));
    }
  };

  /**
   * Sub
   */
  template <>
  struct sub<float, 1, ISA> {
    static Vec<float, 1> call(Vec<float, 1> a, Vec<float, 1> b) {
      return Vec<float, 1>(_mm_sub_ss(a.inner, b.inner));
    }
  };
  template <>
  struct sub<float, 2, ISA> {
    static Vec<float, 2> call(Vec<float, 2> a, Vec<float, 2> b) {
      return Vec<float, 2>(_mm_sub_ps(a.inner, b.inner));
    }
  };
  template <>
  struct sub<float, 4, ISA> {
    static Vec<float, 4> call(Vec<float, 4> a, Vec<float, 4> b) {
      return Vec<float, 4>(_mm_sub_ps(a.inner, b.inner));
    }
  };

  template <>
  struct sub<double, 1, ISA> {
    static Vec<double, 1> call(Vec<double, 1> a, Vec<double, 1> b) {
      return Vec<double, 1>(_mm_sub_sd(a.inner, b.inner));
    }
  };
  template <>
  struct sub<double, 2, ISA> {
    static Vec<double, 2> call(Vec<double, 2> a, Vec<double, 2> b) {
      return Vec<double, 2>(_mm_sub_pd(a.inner, b.inner));
    }
  };

  /**
   * Mul
   */
  template <>
  struct mul<float, 1, ISA> {
    static Vec<float, 1> call(Vec<float, 1> a, Vec<float, 1> b) {
      return Vec<float, 1>(_mm_mul_ss(a.inner, b.inner));
    }
  };
  template <>
  struct mul<float, 2, ISA> {
    static Vec<float, 2> call(Vec<float, 2> a, Vec<float, 2> b) {
      return Vec<float, 2>(_mm_mul_ps(a.inner, b.inner));
    }
  };
  template <>
  struct mul<float, 4, ISA> {
    static Vec<float, 4> call(Vec<float, 4> a, Vec<float, 4> b) {
      return Vec<float, 4>(_mm_mul_ps(a.inner, b.inner));
    }
  };

  template <>
  struct mul<double, 1, ISA> {
    static Vec<double, 1> call(Vec<double, 1> a, Vec<double, 1> b) {
      return Vec<double, 1>(_mm_mul_sd(a.inner, b.inner));
    }
  };
  template <>
  struct mul<double, 2, ISA> {
    static Vec<double, 2> call(Vec<double, 2> a, Vec<double, 2> b) {
      return Vec<double, 2>(_mm_mul_pd(a.inner, b.inner));
    }
  };

  /**
   * Div
   */
  template <>
  struct div<float, 1, ISA> {
    static Vec<float, 1> call(Vec<float, 1> a, Vec<float, 1> b) {
      return Vec<float, 1>(_mm_div_ss(a.inner, b.inner));
    }
  };
  template <>
  struct div<float, 2, ISA> {
    static Vec<float, 2> call(Vec<float, 2> a, Vec<float, 2> b) {
      return Vec<float, 2>(_mm_div_ps(a.inner, b.inner));
    }
  };
  template <>
  struct div<float, 4, ISA> {
    static Vec<float, 4> call(Vec<float, 4> a, Vec<float, 4> b) {
      return Vec<float, 4>(_mm_div_ps(a.inner, b.inner));
    }
  };

  template <>
  struct div<double, 1, ISA> {
    static Vec<double, 1> call(Vec<double, 1> a, Vec<double, 1> b) {
      return Vec<double, 1>(_mm_div_sd(a.inner, b.inner));
    }
  };
  template <>
  struct div<double, 2, ISA> {
    static Vec<double, 2> call(Vec<double, 2> a, Vec<double, 2> b) {
      return Vec<double, 2>(_mm_div_pd(a.inner, b.inner));
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
  struct cast<float, 1, float, 2, ISA> {
    static Vec<float, 1> call(Vec<float, 2> v) {
      return Vec<float, 1>(v.inner);
    }
  };
  template <>
  struct cast<float, 1, float, 4, ISA> {
    static Vec<float, 1> call(Vec<float, 4> v) {
      return Vec<float, 1>(v.inner);
    }
  };
  template <>
  struct cast<float, 2, float, 4, ISA> {
    static Vec<float, 2> call(Vec<float, 4> v) {
      return Vec<float, 2>(v.inner);
    }
  };

  template <>
  struct cast<double, 1, double, 2, ISA> {
    static Vec<double, 1> call(Vec<double, 2> v) {
      return Vec<double, 1>(v.inner);
    }
  };

  // up casts
  template <>
  struct cast<float, 2, float, 1, ISA> {
    static Vec<float, 2> call(Vec<float, 1> v) {
      return Vec<float, 2>(v.inner);
    }
  };
  template <>
  struct cast<float, 4, float, 1, ISA> {
    static Vec<float, 4> call(Vec<float, 1> v) {
      return Vec<float, 4>(v.inner);
    }
  };
  template <>
  struct cast<float, 4, float, 2, ISA> {
    static Vec<float, 4> call(Vec<float, 2> v) {
      return Vec<float, 4>(v.inner);
    }
  };

  template <>
  struct cast<double, 2, double, 1, ISA> {
    static Vec<double, 2> call(Vec<double, 1> v) {
      return Vec<double, 2>(v.inner);
    }
  };

  // type casts
  template <>
  struct cast<float, 2, double, 1, ISA> {
    static Vec<float, 2> call(Vec<double, 1> v) {
      return Vec<float, 2>(_mm_castpd_ps(v.inner));
    }
  };
  template <>
  struct cast<float, 4, double, 2, ISA> {
    static Vec<float, 4> call(Vec<double, 2> v) {
      return Vec<float, 4>(_mm_castpd_ps(v.inner));
    }
  };

  template <>
  struct cast<double, 1, float, 2, ISA> {
    static Vec<double, 1> call(Vec<float, 2> v) {
      return Vec<double, 1>(_mm_castps_pd(v.inner));
    }
  };
  template <>
  struct cast<double, 2, float, 4, ISA> {
    static Vec<double, 2> call(Vec<float, 4> v) {
      return Vec<double, 2>(_mm_castps_pd(v.inner));
    }
  };

  /**
   * Convert
   */
  template <>
  struct convert<float, 1, double, 1, ISA> {
    static Vec<float, 1> call(Vec<double, 1> v) {
      return Vec<float, 1>(_mm_cvtsd_ss(_mm_undefined_ps(), v.inner));
    }
  };
  template <>
  struct convert<float, 2, double, 2, ISA> {
    static Vec<float, 2> call(Vec<double, 2> v) {
      return Vec<float, 2>(_mm_cvtpd_ps(v.inner));
    }
  };

  template <>
  struct convert<double, 1, float, 1, ISA> {
    static Vec<double, 1> call(Vec<float, 1> v) {
      return Vec<double, 1>(_mm_cvtss_sd(_mm_undefined_pd(), v.inner));
    }
  };
  template <>
  struct convert<double, 2, float, 2, ISA> {
    static Vec<double, 2> call(Vec<float, 2> v) {
      return Vec<double, 2>(_mm_cvtps_pd(v.inner));
    }
  };
}
#undef ISA
#endif
