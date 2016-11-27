#pragma once
#include <iostream>

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

/**
 * Vec class
 */
template <class T, int N>
class Vec {
  public:
    //static_assert(is_power2(N), "N should be a power of 2");
    Vec<T, N/2> low, high;

    Vec() = default;
    Vec(const Vec&) = default;

    Vec& operator=(const Vec&) = default;

    ~Vec() = default;
    Vec(Vec<T, N/2> l, Vec<T, N/2> h) : low(l), high(h) {}
};

template <class T>
class Vec<T, 1> : public VecHelper<T> {
  using VecHelper<T>::VecHelper;
};

template <class T>
class Vec<T, 0> {};

/**
 * Get low
 */
template <class T, int N>
Vec<T, N/2> vlow(Vec<T, N> v) {
  static_assert(N > 1, "Cannot get low part of one element");
  return v.low;
}

/**
 * Get high
 */
template <class T, int N>
Vec<T, N/2> vhigh(Vec<T, N> v) {
  static_assert(N > 1, "Cannot get high part of one element");
  return v.high;
}

/**
 * Merge
 */
template <class T, int N>
Vec<T, 2*N> merge(Vec<T, N> low, Vec<T, N> high) {
  return Vec<T, 2*N>(low, high);
}

/**
 * load
 */

// An helper class is needed as there is no partial template specialization of functions in C++
template <class T, int N> Vec<T, N> vload(const T* p);

template <int N>
struct _vload {
  template <class T>
  static Vec<T, N> call(const T* p) {
    return merge(vload<T, N/2>(p), vload<T, N/2>(p+N/2));
  }
};
template <>
struct _vload<1> {
  template <class T>
  static Vec<T, 1> call(const T* p) {
    return Vec<T, 1>(*p);
  }
};
template <class T, int N>
Vec<T, N> vload(const T* p) {
  return _vload<N>::call(p);
}

/**
 * store
 */
template <class T, int N>
void vstore(T* p, Vec<T, N> v) {
  vstore(p, vlow(v));
  vstore(p+N/2, vhigh(v));
}
template <class T>
void vstore(T* p, Vec<T, 1> v) {
  *p = v.inner;
}

/**
 * Add
 */
template <class T, int N>
Vec<T, N> vadd(Vec<T, N> a, Vec<T, N> b) {
  return merge(vadd(vlow(a), vlow(b)), vadd(vhigh(a), vhigh(b)));
}
template <class T>
Vec<T, 1> vadd(Vec<T, 1> a, Vec<T, 1> b) {
  return Vec<T, 1>(a.inner + b.inner);
}

/**
 * Sub
 */
template <class T, int N>
Vec<T, N> vsub(Vec<T, N> a, Vec<T, N> b) {
  return merge(vsub(vlow(a), vlow(b)), vsub(vhigh(a), vhigh(b)));
}
template <class T>
Vec<T, 1> vsub(Vec<T, 1> a, Vec<T, 1> b) {
  return Vec<T, 1>(a.inner - b.inner);
}

/**
 * Mul
 */
template <class T, int N>
Vec<T, N> vmul(Vec<T, N> a, Vec<T, N> b) {
  return merge(vmul(vlow(a), vlow(b)), vmul(vhigh(a), vhigh(b)));
}
template <class T>
Vec<T, 1> vmul(Vec<T, 1> a, Vec<T, 1> b) {
  return Vec<T, 1>(a.inner * b.inner);
}

/**
 * Div
 */
template <class T, int N>
Vec<T, N> vdiv(Vec<T, N> a, Vec<T, N> b) {
  return merge(vdiv(vlow(a), vlow(b)), vdiv(vhigh(a), vhigh(b)));
}
template <class T>
Vec<T, 1> vdiv(Vec<T, 1> a, Vec<T, 1> b) {
  return Vec<T, 1>(a.inner / b.inner);
}

/**
 * FMA
 */
template <class T, int N>
Vec<T, N> vfma(Vec<T, N> a, Vec<T, N> b, Vec<T, N> c) {
  return merge(vfma(vlow(a), vlow(b), vlow(c)), vfma(vhigh(a), vhigh(b), vhigh(c)));
}
template <class T>
Vec<T, 1> vfma(Vec<T, 1> a, Vec<T, 1> b, Vec<T, 1> c) {
  return Vec<T, 1>(a.inner * b.inner + c.inner);
}

// Opt-in fallback when fma is not available but add and mul are
namespace fallback {
  template <class T, int N>
  Vec<T, N> vfma(Vec<T, N> a, Vec<T, N> b, Vec<T, N> c) {
    return vadd(vmul(a, b), c);
  }
}

/**
 * Cast
 */
// same size
template <class T1, int N1, class T2, int N2, enable_if<(sizeof(T1)*N1 == sizeof(T2)*N2)>* = nullptr>
Vec<T1, N1> vcast(Vec<T2, N2> v) {
  return reinterpret<Vec<T1, N1>, Vec<T2, N2>>(v);
}

// down cast
template <class T1, int N1, class T2, int N2, enable_if<(sizeof(T1)*N1 < sizeof(T2)*N2)>* = nullptr>
Vec<T1, N1> vcast(Vec<T2, N2> v) {
  return vcast<T1, N1>(vlow(v));
}

// up cast
template <class T1, int N1, class T2, int N2, enable_if<(sizeof(T1)*N1 > sizeof(T2)*N2)>* = nullptr>
Vec<T1, N1> vcast(Vec<T2, N2> v) {
  return vcast<T1, N1>(merge(v, Vec<T2, N2>()));
}

// Noop cast
template <class T, int N>
Vec<T, N> vcast(Vec<T, N> v) {
  return v;
}

/**
 * Convert
 */
// cardinal 1
template <class T1, int N1, class T2, int N2, enable_if<(N1 == N2 && N1 == 1)>* = nullptr>
Vec<T1, N1> vconvert(Vec<T2, N2> v) {
  return Vec<T1, N1>(static_cast<T1>(v.inner));
}

// same cardinal
template <class T1, int N1, class T2, int N2, enable_if<(N1 == N2 && N1 > 1)>* = nullptr>
Vec<T1, N1> vconvert(Vec<T2, N2> v) {
  return merge(vconvert<T1, N1/2>(vlow(v)), vconvert<T1, N1/2>(vhigh(v)));
}

// down convert
template <class T1, int N1, class T2, int N2, enable_if<(N1 < N2)>* = nullptr>
Vec<T1, N1> vconvert(Vec<T2, N2> v) {
  return vconvert<T1, N1>(vcast<T2, N1>(v));
}

// up convert
template <class T1, int N1, class T2, int N2, enable_if<(N1 > N2)>* = nullptr>
Vec<T1, N1> vconvert(Vec<T2, N2> v) {
  return vcast<T1, N1>(vconvert<T1, N2>(v));
}

// Noop convert
template <class T, int N>
Vec<T, N> vconvert(Vec<T, N> v) {
  return v;
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
