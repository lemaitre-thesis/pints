#pragma once
#include <iosfwd>

namespace detail {
  static constexpr int max_ISA = 3;
  static constexpr int max_align = 64;
}

template <class T, int N, int ISA = detail::max_ISA> class Vec;

namespace detail {
  template <class T, int N, int ISA = max_ISA> struct low   : public low  <T, N, ISA-1> {};
  template <class T, int N, int ISA = max_ISA> struct high  : public high <T, N, ISA-1> {};
  template <class T, int N, int ISA = max_ISA> struct merge : public merge<T, N, ISA-1> {};
  template <class T, int N, int ISA = max_ISA> struct load  : public load <T, N, ISA-1> {};
  template <class T, int N, int ISA = max_ISA> struct store : public store<T, N, ISA-1> {};
  template <class T, int N, int ISA = max_ISA> struct add   : public add  <T, N, ISA-1> {};
  template <class T, int N, int ISA = max_ISA> struct sub   : public sub  <T, N, ISA-1> {};
  template <class T, int N, int ISA = max_ISA> struct mul   : public mul  <T, N, ISA-1> {};
  template <class T, int N, int ISA = max_ISA> struct div   : public div  <T, N, ISA-1> {};
  template <class T, int N, int ISA = max_ISA> struct fma   : public fma  <T, N, ISA-1> {};
  template <class T1, int N1, class T2, int N2, int ISA = max_ISA> struct cast    : public cast   <T1, N1, T2, N2, ISA-1> {};
  template <class T1, int N1, class T2, int N2, int ISA = max_ISA> struct convert : public convert<T1, N1, T2, N2, ISA-1> {};

  /**
   * Helpers
   */
  constexpr bool is_power2(int n) {
    return n == 1 || ((n&1) == 0 && n > 0 && is_power2(n/2));
  }

  template <class To, class From, class U>
  To reinterpret(U&& u) {
    static_assert(sizeof(From) == sizeof(To), "Types should have the same size");
    union {
      From from;
      To to;
    } caster;
    caster.from = static_cast<U&&>(u);
    return caster.to;
  }

  template <bool B>
  using enable_if = typename std::enable_if<B>::type;

  template <class T>
  class VecHelper {
    public:
      T inner;

      VecHelper() = default;
      VecHelper(const VecHelper&) = default;

      VecHelper& operator=(const VecHelper&) = default;

      ~VecHelper() = default;

      explicit VecHelper(T t) : inner(t) {}
  };
}


/**
 * Vec class
 */
template <class T, int N, int ISA>
class Vec : public Vec<T, N, ISA-1> {
  using Vec<T, N, ISA-1>::Vec;
};

template <class T, int N>
class alignas(sizeof(T)*N < detail::max_align ? sizeof(T)*N : detail::max_align) Vec<T, N, 0> {
  public:
    static_assert(detail::is_power2(N), "N should be a power of 2");
    Vec<T, N/2> low, high;

    Vec() = default;
    Vec(const Vec&) = default;

    Vec& operator=(const Vec&) = default;

    ~Vec() = default;
    Vec(Vec<T, N/2> l, Vec<T, N/2> h) : low(l), high(h) {}
};

template <class T>
class Vec<T, 1, 0> : public detail::VecHelper<T> {
  using detail::VecHelper<T>::VecHelper;
};

template <class T>
class Vec<T, 0, 0> {};

/**
 * Functions
 */
template <class T, int N>
Vec<T, N/2> vlow(Vec<T, N> a) {
  return detail::low<T, N>::call(a);
}
template <class T, int N>
Vec<T, N/2> vhigh(Vec<T, N> a) {
  return detail::high<T, N>::call(a);
}
template <class T, int N>
Vec<T, 2*N> vmerge(Vec<T, N> low, Vec<T, N> high) {
  return detail::merge<T, N>::call(low, high);
}
template <class T, int N>
Vec<T, N> vload(const T* p) {
  return detail::load<T, N>::call(p);
}
template <class T, int N>
void vstore(T* p, Vec<T, N> v) {
  return detail::store<T, N>::call(p, v);
}
template <class T, int N>
Vec<T, N> vadd(Vec<T, N> a, Vec<T, N> b) {
  return detail::add<T, N>::call(a, b);
}
template <class T, int N>
Vec<T, N> vsub(Vec<T, N> a, Vec<T, N> b) {
  return detail::sub<T, N>::call(a, b);
}
template <class T, int N>
Vec<T, N> vmul(Vec<T, N> a, Vec<T, N> b) {
  return detail::mul<T, N>::call(a, b);
}
template <class T, int N>
Vec<T, N> vdiv(Vec<T, N> a, Vec<T, N> b) {
  return detail::div<T, N>::call(a, b);
}
template <class T, int N>
Vec<T, N> vfma(Vec<T, N> a, Vec<T, N> b, Vec<T, N> c) {
  return detail::fma<T, N>::call(a, b, c);
}
template <class T1, int N1, class T2, int N2>
Vec<T1, N1> vcast(Vec<T2, N2> a) {
  return detail::cast<T1, N1, T2, N2>::call(a);
}
template <class T1, int N1, class T2, int N2>
Vec<T1, N1> vconvert(Vec<T2, N2> a) {
  return detail::convert<T1, N1, T2, N2>::call(a);
}

namespace detail {
  /**
   * Get low
   */
  template <class T, int N>
  struct low<T, N, 0> {
    static Vec<T, N/2> call(Vec<T, N> v) {
      static_assert(N > 1, "Cannot get low part of one element");
      return v.low;
    }
  };

  /**
   * Get high
   */
  template <class T, int N>
  struct high<T, N, 0> {
    static Vec<T, N/2> call(Vec<T, N> v) {
      static_assert(N > 1, "Cannot get high part of one element");
      return v.high;
    }
  };

  /**
   * Merge
   */
  template <class T, int N>
  struct merge<T, N, 0> {
    static Vec<T, 2*N> call(Vec<T, N> low, Vec<T, N> high) {
      return Vec<T, 2*N>(low, high);
    }
  };

  /**
   * load
   */
  template <class T, int N>
  struct load<T, N, 0> {
    static Vec<T, N> call(const T* p) {
      return vmerge(vload<T, N/2>(p), vload<T, N/2>(p+N/2));
    }
  };

  template <class T>
  struct load<T, 1, 0> {
    static Vec<T, 1> call(const T* p) {
      return Vec<T, 1>(*p);
    }
  };

  /**
   * store
   */
  template <class T, int N>
  struct store<T, N, 0> {
    static void call(T* p, Vec<T, N> v) {
      vstore(p    , vlow (v));
      vstore(p+N/2, vhigh(v));
    }
  };

  template <class T>
  struct store<T, 1, 0> {
    static void call(T* p, Vec<T, 1> v) {
      *p = v.inner;
    }
  };

  /**
   * Add
   */
  template <class T, int N>
  struct add<T, N, 0> {
    static Vec<T, N> call(Vec<T, N> a, Vec<T, N> b) {
      return vmerge(vadd(vlow(a), vlow(b)), vadd(vhigh(a), vhigh(b)));
    }
  };

  template <class T>
  struct add<T, 1, 0> {
    static Vec<T, 1> call(Vec<T, 1> a, Vec<T, 1> b) {
      return Vec<T, 1>(a.inner + b.inner);
    }
  };

  /**
   * Sub
   */
  template <class T, int N>
  struct sub<T, N, 0> {
    static Vec<T, N> call(Vec<T, N> a, Vec<T, N> b) {
      return vmerge(vsub(vlow(a), vlow(b)), vsub(vhigh(a), vhigh(b)));
    }
  };

  template <class T>
  struct sub<T, 1, 0> {
    static Vec<T, 1> call(Vec<T, 1> a, Vec<T, 1> b) {
      return Vec<T, 1>(a.inner - b.inner);
    }
  };

  /**
   * Mul
   */
  template <class T, int N>
  struct mul<T, N, 0> {
    static Vec<T, N> call(Vec<T, N> a, Vec<T, N> b) {
      return vmerge(vmul(vlow(a), vlow(b)), vmul(vhigh(a), vhigh(b)));
    }
  };

  template <class T>
  struct mul<T, 1, 0> {
    static Vec<T, 1> call(Vec<T, 1> a, Vec<T, 1> b) {
      return Vec<T, 1>(a.inner * b.inner);
    }
  };

  /**
   * Div
   */
  template <class T, int N>
  struct div<T, N, 0> {
    static Vec<T, N> call(Vec<T, N> a, Vec<T, N> b) {
      return vmerge(vdiv(vlow(a), vlow(b)), vdiv(vhigh(a), vhigh(b)));
    }
  };

  template <class T>
  struct div<T, 1, 0> {
    static Vec<T, 1> call(Vec<T, 1> a, Vec<T, 1> b) {
      return Vec<T, 1>(a.inner / b.inner);
    }
  };

  /**
   * FMA
   */
  template <class T, int N>
  struct fma<T, N, 0> {
    static Vec<T, N> call(Vec<T, N> a, Vec<T, N> b, Vec<T, N> c) {
      return vmerge(vfma(vlow(a), vlow(b), vlow(c)), vfma(vhigh(a), vhigh(b), vhigh(c)));
    }
  };

  template <class T>
  struct fma<T, 1, 0> {
    static Vec<T, 1> call(Vec<T, 1> a, Vec<T, 1> b, Vec<T, 1> c) {
      return Vec<T, 1>(a.inner * b.inner + c.inner);
    }
  };

  // Opt-in fallback when fma is not available but add and mul are
  namespace fallback {
    template <class T, int N>
    struct fma {
      static Vec<T, N> call(Vec<T, N> a, Vec<T, N> b, Vec<T, N> c) {
        return vadd(vmul(a, b), c);
      }
    };
  }

  /**
   * Cast
   */
  // same size
  template <class T1, int N1, class T2, int N2>
  struct cast<T1, N1, T2, N2, (typename std::enable_if<(sizeof(T1)*N1 == sizeof(T2)*N2), int>::type)(0)> {
    static Vec<T1, N1> call(Vec<T2, N2> v) {
      return reinterpret<Vec<T1, N1>, Vec<T2, N2>>(v);
    }
  };

  // down cast
  template <class T1, int N1, class T2, int N2>
  struct cast<T1, N1, T2, N2, (typename std::enable_if<(sizeof(T1)*N1 < sizeof(T2)*N2), int>::type)(0)> {
    static Vec<T1, N1> call(Vec<T2, N2> v) {
      return vcast<T1, N1>(vlow(v));
    }
  };

  // up cast
  template <class T1, int N1, class T2, int N2>
  struct cast<T1, N1, T2, N2, (typename std::enable_if<(sizeof(T1)*N1 > sizeof(T2)*N2), int>::type)(0)> {
    static Vec<T1, N1> call(Vec<T2, N2> v) {
      return vcast<T1, N1>(vmerge(v, Vec<T2, N2>()));
    }
  };

  // Noop cast
  template <class T, int N>
  struct cast<T, N, T, N, 0> {
    static Vec<T, N> call(Vec<T, N> v) {
      return v;
    }
  };
  
  /**
   * Convert
   */
  // cardinal 1
  template <class T1, class T2>
  struct convert<T1, 1, T2, 1, 0> {
    static Vec<T1, 1> call(Vec<T2, 1> v) {
      return Vec<T1, 1>(T1(v.inner));
    }
  };
  // same cardinal
  template <class T1, class T2, int N>
  struct convert<T1, N, T2, N, 0> {
    static Vec<T1, N> call(Vec<T2, N> v) {
    return vmerge(vconvert<T1, N/2>(vlow(v)), vconvert<T1, N/2>(vhigh(v)));
    }
  };

  // down convert
  template <class T1, int N1, class T2, int N2>
  struct convert<T1, N1, T2, N2, (typename std::enable_if<(N1 < N2), int>::type)(0)> {
    static Vec<T1, N1> call(Vec<T2, N2> v) {
    return vconvert<T1, N1>(vcast<T2, N1>(v));
    }
  };

  // up convert
  template <class T1, int N1, class T2, int N2>
  struct convert<T1, N1, T2, N2, (typename std::enable_if<(N1 > N2), int>::type)(0)> {
    static Vec<T1, N1> call(Vec<T2, N2> v) {
    return vcast<T1, N1>(vconvert<T1, N2>(v));
    }
  };

  // Noop convert
  template <class T, int N>
  struct convert<T, N, T, N, 0> {
    static Vec<T, N> call(Vec<T, N> v) {
      return v;
    }
  };

}

/**
 * IO
 */
template <class T, int N>
std::ostream& operator>>(std::ostream& out, Vec<T, N> v) {
  T buf[N];
  vstore(buf, v);

  for (int i = 0; i < N; ++i) {
    if (i != 0) out << " ";
    out << buf[i];
  }
  return out;
}
