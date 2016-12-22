#pragma once
#include <iosfwd>

namespace detail {
  static constexpr int max_align = 64;

}

namespace ISA {
  template <int N>
  struct ISA_tag : public ISA_tag<N-1> {};
  template <>
  struct ISA_tag<0> {};
  typedef ISA_tag<0> scalar;
  typedef ISA_tag<1> fallback;
  typedef ISA_tag<2> SSE;
  typedef ISA_tag<3> AVX;
  typedef ISA_tag<4> FMA;
  typedef ISA_tag<10> max;
}

namespace Op {
  template <class T, int N> struct low  {};
  template <class T, int N> struct high {};
  template <class T, int N> struct merge{};
  template <class T, int N> struct load {};
  template <class T, int N> struct store{};
  template <class T, int N> struct add  {};
  template <class T, int N> struct sub  {};
  template <class T, int N> struct mul  {};
  template <class T, int N> struct div  {};
  template <class T, int N> struct fma  {};
  template <class T1, int N1, class T2, int N2> struct cast   {};
  template <class T1, int N1, class T2, int N2> struct convert{};
  template <class T, int N, int inner, int outer, class swizzle_t> struct hshuffle{};
  template <class T, int N, int inner, int outer, class swizzle_t> struct permute{};
  template <class T, int N, int inner, int outer, class swizzle_t, class mask_t> struct fshuffle{};
  template <class T, int N, int inner, int outer, class mask_t> struct blend{};
}

template <class T, int N> class Vec;

namespace detail {

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

  template <int... Is>
  struct index_sequence {};

  template <int N, class T = index_sequence<>>
  struct make_index_sequence_s;

  template <int N, int... Is>
  struct make_index_sequence_s<N, index_sequence<Is...>> : public make_index_sequence_s<N-1, index_sequence<N-1, Is...>> {};

  template <int... Is>
  struct make_index_sequence_s<0, index_sequence<Is...>> {
    using type = index_sequence<Is...>;
  };

  template <int N>
  using make_index_sequence = typename make_index_sequence_s<N>::type;

  template <class T, class S>
  struct size_s;

  template <class T, template <T...> class S, T... Ts>
  struct size_s<T, S<Ts...>> {
    static constexpr int value = sizeof...(Ts);
  };

  template <class T, int N>
  struct constexpr_array {
    T data[N];
    constexpr T operator[](int i) const {
      return data[i];
    }
  };

  template <class T, class S, class Is = make_index_sequence<(size_s<T, S>::value+1)/2>>
  struct low_s;

  template <class T, template <T...> class S, T... Ts, int... Is>
  struct low_s<T, S<Ts...>, index_sequence<Is...>> {
    using type = S<((constexpr_array<T, sizeof...(Ts)>{Ts...})[Is])...>;
  };

  template <class T, class S>
  using low_t = typename low_s<T, S>::type;

  template <class T, class S, class Is = make_index_sequence<size_s<T, S>::value/2>>
  struct high_s;

  template <class T, template <T...> class S, T... Ts, int... Is>
  struct high_s<T, S<Ts...>, index_sequence<Is...>> {
    using type = S<((constexpr_array<T, sizeof...(Ts)>{Ts...})[Is + sizeof...(Ts) - sizeof...(Is)])...>;
  };

  template <class T, class S>
  using high_t = typename high_s<T, S>::type;
}


/**
 * Vec class
 */
template <class T, int N>
class alignas(sizeof(T)*N < detail::max_align ? sizeof(T)*N : detail::max_align) Vec {
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
class Vec<T, 1> : public detail::VecHelper<T> {
  using detail::VecHelper<T>::VecHelper;
};

template <class T>
class Vec<T, 0> {};

template <int... rules>
struct swizzle {
  static constexpr int size() {
    return sizeof...(rules);
  }
  static constexpr int get(int i) {
    constexpr int arr[] = {rules...};
    return arr[i];
  }
  constexpr int operator[](int i) const {
    return get(i);
  }
};

template <bool... rules>
struct mask {
  static constexpr int size() {
    return sizeof...(rules);
  }
  static constexpr bool get(int i) {
    constexpr int arr[] = {rules...};
    return arr[i];
  }
  constexpr bool operator[](int i) const {
    return get(i);
  }
};

/**
 * Functions
 */
template <class T, int N>
Vec<T, N/2> vlow(Vec<T, N> a);
template <class T, int N>
Vec<T, N/2> vhigh(Vec<T, N> a);
template <class T, int N>
Vec<T, 2*N> vmerge(Vec<T, N> low, Vec<T, N> high);
template <class T, int N>
Vec<T, N> vload(const T* p);
template <class T, int N>
void vstore(T* p, Vec<T, N> v);
template <class T, int N>
Vec<T, N> vadd(Vec<T, N> a, Vec<T, N> b);
template <class T, int N>
Vec<T, N> vsub(Vec<T, N> a, Vec<T, N> b);
template <class T, int N>
Vec<T, N> vmul(Vec<T, N> a, Vec<T, N> b);
template <class T, int N>
Vec<T, N> vdiv(Vec<T, N> a, Vec<T, N> b);
template <class T, int N>
Vec<T, N> vfma(Vec<T, N> a, Vec<T, N> b, Vec<T, N> c);
template <class T1, int N1, class T2, int N2>
Vec<T1, N1> vcast(Vec<T2, N2> a);
template <class T1, int N1, class T2, int N2>
Vec<T1, N1> vconvert(Vec<T2, N2> a);

// permute
template <int inner, int outer, class T, int N, int... swizzle_rule>
Vec<T, N> vshuffle(Vec<T, N> a, swizzle<swizzle_rule...>);

// half shuffle
template <int inner, int outer, class T, int N, int... swizzle_rule>
Vec<T, N> vshuffle(Vec<T, N> a, Vec<T, N> b, swizzle<swizzle_rule...>);

// full shuffle 
template <int inner, int outer, class T, int N, int... swizzle_rule, bool... mask_rule>
Vec<T, N> vshuffle(Vec<T, N> a, Vec<T, N> b, swizzle<swizzle_rule...>, mask<mask_rule...>);

// Blend
template <int inner, int outer, class T, int N, bool... mask_rule>
Vec<T, N> vblend(Vec<T, N> a, Vec<T, N> b, mask<mask_rule...>);

namespace Op {
  /**
   * Get low
   */
  template <class T, int N>
  Vec<T, N/2> call(low<T, N>, ISA::scalar, Vec<T, N> v) {
    return v.low;
  }

  /**
   * Get high
   */
  template <class T, int N>
  Vec<T, N/2> call(high<T, N>, ISA::scalar, Vec<T, N> v) {
    return v.high;
  }

  /**
   * Merge
   */
  template <class T, int N>
  Vec<T, 2*N> call(merge<T, N>, ISA::scalar, Vec<T, N> low, Vec<T, N> high) {
    return Vec<T, 2*N>(low, high);
  }

  /**
   * load
   */
  template <class T, int N>
  Vec<T, N> call(load<T, N>, ISA::scalar, const T* p) {
    return vmerge(vload<T, N/2>(p), vload<T, N/2>(p+N/2));
  }

  template <class T>
  Vec<T, 1> call(load<T, 1>, ISA::scalar, const T* p) {
    return Vec<T, 1>(*p);
  }

  /**
   * store
   */
  template <class T, int N>
  void call(store<T, N>, ISA::scalar, T* p, Vec<T, N> v) {
    vstore(p    , vlow (v));
    vstore(p+N/2, vhigh(v));
  }

  template <class T>
  void call(store<T, 1>, ISA::scalar, T* p, Vec<T, 1> v) {
    *p = v.inner;
  }

  /**
   * Add
   */
  template <class T, int N>
  Vec<T, N> call(add<T, N>, ISA::scalar, Vec<T, N> a, Vec<T, N> b) {
    return vmerge(vadd(vlow(a), vlow(b)), vadd(vhigh(a), vhigh(b)));
  }

  template <class T>
  Vec<T, 1> call(add<T, 1>, ISA::scalar, Vec<T, 1> a, Vec<T, 1> b) {
    return Vec<T, 1>(a.inner + b.inner);
  }

  /**
   * Sub
   */
  template <class T, int N>
  Vec<T, N> call(sub<T, N>, ISA::scalar, Vec<T, N> a, Vec<T, N> b) {
    return vmerge(vsub(vlow(a), vlow(b)), vsub(vhigh(a), vhigh(b)));
  }

  template <class T>
  Vec<T, 1> call(sub<T, 1>, ISA::scalar, Vec<T, 1> a, Vec<T, 1> b) {
    return Vec<T, 1>(a.inner - b.inner);
  }

  /**
   * Mul
   */
  template <class T, int N>
  Vec<T, N> call(mul<T, N>, ISA::scalar, Vec<T, N> a, Vec<T, N> b) {
    return vmerge(vmul(vlow(a), vlow(b)), vmul(vhigh(a), vhigh(b)));
  }

  template <class T>
  Vec<T, 1> call(mul<T, 1>, ISA::scalar, Vec<T, 1> a, Vec<T, 1> b) {
    return Vec<T, 1>(a.inner * b.inner);
  }

  /**
   * Div
   */
  template <class T, int N>
  Vec<T, N> call(div<T, N>, ISA::scalar, Vec<T, N> a, Vec<T, N> b) {
    return vmerge(vdiv(vlow(a), vlow(b)), vdiv(vhigh(a), vhigh(b)));
  }

  template <class T>
  Vec<T, 1> call(div<T, 1>, ISA::scalar, Vec<T, 1> a, Vec<T, 1> b) {
    return Vec<T, 1>(a.inner / b.inner);
  }

  /**
   * FMA
   */
  template <class T, int N>
  Vec<T, N> call(fma<T, N>, ISA::scalar, Vec<T, N> a, Vec<T, N> b, Vec<T, N> c) {
    return vmerge(vfma(vlow(a), vlow(b), vlow(c)), vfma(vhigh(a), vhigh(b), vhigh(c)));
  }

  template <class T>
  Vec<T, 1> call(fma<T, 1>, ISA::scalar, Vec<T, 1> a, Vec<T, 1> b, Vec<T, 1> c) {
    return Vec<T, 1>(a.inner * b.inner + c.inner);
  }

  // Opt-in fallback when fma is not available but add and mul are
  namespace fallback {
    template <class T, int N>
    Vec<T, N> call(fma<T, N>, Vec<T, N> a, Vec<T, N> b, Vec<T, N> c) {
      return vadd(vmul(a, b), c);
    }
  }

  /**
   * Cast
   */
  // same size
  template <class T1, int N1, class T2, int N2, typename std::enable_if<(sizeof(T1)*N1 == sizeof(T2)*N2), int>::type* = nullptr>
  Vec<T1, N1> call(cast<T1, N1, T2, N2>, ISA::scalar, Vec<T2, N2> v) {
    return detail::reinterpret<Vec<T1, N1>, Vec<T2, N2>>(v);
  }

  // down cast
  template <class T1, int N1, class T2, int N2, typename std::enable_if<(sizeof(T1)*N1 < sizeof(T2)*N2), int>::type* = nullptr>
  Vec<T1, N1> call(cast<T1, N1, T2, N2>, ISA::scalar, Vec<T2, N2> v) {
    return vcast<T1, N1>(vlow(v));
  }

  // up cast
  template <class T1, int N1, class T2, int N2, typename std::enable_if<(sizeof(T1)*N1 > sizeof(T2)*N2), int>::type* = nullptr>
  Vec<T1, N1> call(cast<T1, N1, T2, N2>, ISA::scalar, Vec<T2, N2> v) {
    return vcast<T1, N1>(vmerge(v, Vec<T2, N2>()));
  }

  // Noop cast
  template <class T, int N>
  Vec<T, N> call(cast<T, N, T, N>, ISA::scalar, Vec<T, N> v) {
    return v;
  }
  
  /**
   * Convert
   */
  // cardinal 1
  template <class T1, class T2>
  Vec<T1, 1> call(convert<T1, 1, T2, 1>, ISA::scalar, Vec<T2, 1> v) {
    return Vec<T1, 1>(T1(v.inner));
  }
  // same cardinal
  template <class T1, class T2, int N>
  Vec<T1, N> call(convert<T1, N, T2, N>, ISA::scalar, Vec<T2, N> v) {
    return vmerge(vconvert<T1, N/2>(vlow(v)), vconvert<T1, N/2>(vhigh(v)));
  }

  // down convert
  template <class T1, int N1, class T2, int N2, typename std::enable_if<(N1 < N2), int>::type* = nullptr>
  Vec<T1, N1> call(convert<T1, N1, T2, N2>, ISA::scalar, Vec<T2, N2> v) {
    return vconvert<T1, N1>(vcast<T2, N1>(v));
  }

  // up convert
  template <class T1, int N1, class T2, int N2, typename std::enable_if<(N1 > N2), int>::type* = nullptr>
  Vec<T1, N1> call(convert<T1, N1, T2, N2>, ISA::scalar, Vec<T2, N2> v) {
    return vcast<T1, N1>(vconvert<T1, N2>(v));
  }

  // Noop convert
  template <class T, int N>
  Vec<T, N> call(convert<T, N, T, N>, ISA::scalar, Vec<T, N> v) {
    return v;
  }

  /**
   * Blend
   */
  template <class T, int N, bool mask_rule>
  Vec<T, N> call(blend<T, N, 1, 1, mask<mask_rule>>, ISA::scalar, Vec<T, N> a, Vec<T, N> b) {
    return mask_rule ? b : a;
  }

  template <class T, int N, int inner, bool... mask_rule>
  Vec<T, N> call(blend<T, N, inner, 1, mask<mask_rule...>>, ISA::scalar, Vec<T, N> a, Vec<T, N> b) {
    using mask_t = mask<mask_rule...>;
    return vmerge(vblend<inner/2, 1>(vlow(a), vlow(b), detail::low_t<bool, mask_t>{}), vblend<inner/2, 1>(vhigh(a), vhigh(b), detail::high_t<bool, mask_t>{}));
  }

  template <class T, int N, int inner, int outer, bool... mask_rule>
  Vec<T, N> call(blend<T, N, inner, outer, mask<mask_rule...>>, ISA::scalar, Vec<T, N> a, Vec<T, N> b) {
    constexpr mask<mask_rule...> m;
    return vmerge(vblend<inner, outer/2>(vlow(a), vlow(b), m), vblend<inner, outer/2>(vhigh(a), vhigh(b), m));
  }



  /**
   * Shuffles
   */

  // permute
  template <class T, int N, int inner, int outer, int... swizzle_rule>
  Vec<T, N> call(permute<T, N, inner, outer, swizzle<swizzle_rule...>>, ISA::scalar, Vec<T, N> v) {
    constexpr swizzle<swizzle_rule...> s;
    return vmerge(vshuffle<inner, outer/2>(vlow(v), s), vshuffle<inner, outer/2>(vhigh(v), s));
  }
  template <class T, int N, int inner, int... swizzle_rule>
  Vec<T, N> call(permute<T, N, inner, 1, swizzle<swizzle_rule...>>, ISA::scalar, Vec<T, N> v) {
    constexpr swizzle<swizzle_rule...> s;
    return vshuffle<inner, 1>(v, v, s);
  }
  template <class T, int N, int outer, int swizzle_rule>
  Vec<T, N> call(permute<T, N, 1, outer, swizzle<swizzle_rule>>, ISA::scalar, Vec<T, N> v) {
    return v;
  }
  template <class T, int N, int swizzle_rule>
  Vec<T, N> call(permute<T, N, 1, 1, swizzle<swizzle_rule>>, ISA::scalar, Vec<T, N> v) {
    return v;
  }

  // Full shuffle
  template <class T, int N, int inner, int outer, int... swizzle_rule, bool... mask_rule>
  Vec<T, N> call(fshuffle<T, N, inner, outer, swizzle<swizzle_rule...>, mask<mask_rule...>>, ISA::scalar, Vec<T, N> a, Vec<T, N> b) {
    constexpr swizzle<swizzle_rule...> s;
    constexpr mask<mask_rule...> m;
    return vmerge(vshuffle<inner, outer/2>(vlow(a), vlow(b), s, m), vshuffle<inner, outer/2>(vhigh(a), vhigh(b), s, m));
  }

  template <class T, int N, int inner, int... swizzle_rule, bool... mask_rule>
  Vec<T, N> call(fshuffle<T, N, inner, 1, swizzle<swizzle_rule...>, mask<mask_rule...>>, ISA::scalar, Vec<T, N> a, Vec<T, N> b) {
    constexpr swizzle<swizzle_rule...> s;
    constexpr mask<mask_rule...> m;
    return vblend<inner, 1>(vshuffle<inner, 1>(a, s), vshuffle<inner, 1>(b, s), m);
  }

  // Half shuffle
  template <class T, int N, int inner, int outer, int... swizzle_rule>
  Vec<T, N> call(hshuffle<T, N, inner, outer, swizzle<swizzle_rule...>>, ISA::scalar, Vec<T, N> a, Vec<T, N> b) {
    constexpr swizzle<swizzle_rule...> s;
    return vmerge(vshuffle<inner, outer/2>(vlow(a), vlow(b), s), vshuffle<inner, outer/2>(vhigh(a), vhigh(b), s));
  }

  template <class T, int N, int inner, int... swizzle_rule>
  Vec<T, N> call(hshuffle<T, N, inner, 1, swizzle<swizzle_rule...>>, ISA::scalar, Vec<T, N> a, Vec<T, N> b) {
    using swizzle_t = swizzle<(swizzle_rule & (inner/2-1))...>;
    using mask_t = mask<(swizzle_rule >= inner/2)...>;
    return vmerge(vshuffle<inner/2, 1>(vlow(a), vhigh(a), detail::low_t<int, swizzle_t>{}, detail::low_t<bool, mask_t>{}), vshuffle<inner/2, 1>(vlow(b), vhigh(b), detail::high_t<int, swizzle_t>{}, detail::high_t<bool, mask_t>{}));
  }
}
