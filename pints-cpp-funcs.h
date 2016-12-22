#pragma once

/**
 * Functions
 */
template <class T, int N>
Vec<T, N/2> vlow(Vec<T, N> a) {
  return Op::call(Op::low<T, N>{}, ISA::max{}, a);
}
template <class T, int N>
Vec<T, N/2> vhigh(Vec<T, N> a) {
  return Op::call(Op::high<T, N>{}, ISA::max{}, a);
}
template <class T, int N>
Vec<T, 2*N> vmerge(Vec<T, N> low, Vec<T, N> high) {
  return Op::call(Op::merge<T, N>{}, ISA::max{}, low, high);
}
template <class T, int N>
Vec<T, N> vload(const T* p) {
  return Op::call(Op::load<T, N>{}, ISA::max{}, p);
}
template <class T, int N>
void vstore(T* p, Vec<T, N> v) {
  return Op::call(Op::store<T, N>{}, ISA::max{}, p, v);
}
template <class T, int N>
Vec<T, N> vadd(Vec<T, N> a, Vec<T, N> b) {
  return Op::call(Op::add<T, N>{}, ISA::max{}, a, b);
}
template <class T, int N>
Vec<T, N> vsub(Vec<T, N> a, Vec<T, N> b) {
  return Op::call(Op::sub<T, N>{}, ISA::max{}, a, b);
}
template <class T, int N>
Vec<T, N> vmul(Vec<T, N> a, Vec<T, N> b) {
  return Op::call(Op::mul<T, N>{}, ISA::max{}, a, b);
}
template <class T, int N>
Vec<T, N> vdiv(Vec<T, N> a, Vec<T, N> b) {
  return Op::call(Op::div<T, N>{}, ISA::max{}, a, b);
}
template <class T, int N>
Vec<T, N> vfma(Vec<T, N> a, Vec<T, N> b, Vec<T, N> c) {
  return Op::call(Op::fma<T, N>{}, ISA::max{}, a, b, c);
}
template <class T1, int N1, class T2, int N2>
Vec<T1, N1> vcast(Vec<T2, N2> a) {
  return Op::call(Op::cast<T1, N1, T2, N2>{}, ISA::max{}, a);
}
template <class T1, int N1, class T2, int N2>
Vec<T1, N1> vconvert(Vec<T2, N2> a) {
  return Op::call(Op::convert<T1, N1, T2, N2>{}, ISA::max{}, a);
}

// permute
template <int inner, int outer, class T, int N, int... swizzle_rule>
Vec<T, N> vshuffle(Vec<T, N> a, swizzle<swizzle_rule...>) {
  static_assert(inner > 0, "inner should be positive");
  static_assert(outer > 0, "outer should be positive");
  static_assert(inner * outer <= N, "inner*outer should be less than SIMD card");
  static_assert(detail::is_power2(inner), "inner should be a power of 2");
  static_assert(detail::is_power2(outer), "outer should be a power of 2");
  static_assert(sizeof...(swizzle_rule) == inner, "Swizzle rule should have 'inner' elements");
  return Op::call(Op::permute<T, N, inner, outer, swizzle<swizzle_rule...>>{}, ISA::max{}, a);
}

// half shuffle
template <int inner, int outer, class T, int N, int... swizzle_rule>
Vec<T, N> vshuffle(Vec<T, N> a, Vec<T, N> b, swizzle<swizzle_rule...>) {
  static_assert(inner > 0, "inner should be positive");
  static_assert(inner > 0, "inner should be at least 2");
  static_assert(outer > 0, "outer should be positive");
  static_assert(inner * outer <= N, "inner*outer should be less than SIMD card");
  static_assert(detail::is_power2(inner), "inner should be a power of 2");
  static_assert(detail::is_power2(outer), "outer should be a power of 2");
  static_assert(sizeof...(swizzle_rule) == inner, "Swizzle rule should have 'inner' elements");
  return Op::call(Op::hshuffle<T, N, inner, outer, swizzle<swizzle_rule...>>{}, ISA::max{}, a, b);
}

// full shuffle 
template <int inner, int outer, class T, int N, int... swizzle_rule, bool... mask_rule>
Vec<T, N> vshuffle(Vec<T, N> a, Vec<T, N> b, swizzle<swizzle_rule...>, mask<mask_rule...>) {
  static_assert(inner > 0, "inner should be positive");
  static_assert(outer > 0, "outer should be positive");
  static_assert(inner * outer <= N, "inner*outer should be less than SIMD card");
  static_assert(detail::is_power2(inner), "inner should be a power of 2");
  static_assert(detail::is_power2(outer), "outer should be a power of 2");
  static_assert(sizeof...(swizzle_rule) == inner, "Swizzle rule should have 'inner' elements");
  static_assert(sizeof...(mask_rule) == inner, "Mask rule should have 'inner' elements");
  return Op::call(Op::fshuffle<T, N, inner, outer, swizzle<swizzle_rule...>, mask<mask_rule...>>{}, ISA::max{}, a, b);
}

// Blend
template <int inner, int outer, class T, int N, bool... mask_rule>
Vec<T, N> vblend(Vec<T, N> a, Vec<T, N> b, mask<mask_rule...>) {
  static_assert(inner > 0, "inner should be positive");
  static_assert(outer > 0, "outer should be positive");
  static_assert(inner * outer <= N, "inner*outer should be less than SIMD card");
  static_assert(detail::is_power2(inner), "inner should be a power of 2");
  static_assert(detail::is_power2(outer), "outer should be a power of 2");
  static_assert(sizeof...(mask_rule) == inner, "Mask rule should have 'inner' elements");
  return Op::call(Op::blend<T, N, inner, outer, mask<mask_rule...>>{}, ISA::max{}, a, b);
}

/**
 * IO
 */
template <class T, int N>
std::ostream& operator<<(std::ostream& out, Vec<T, N> v) {
  T buf[N];
  vstore(buf, v);

  for (int i = 0; i < N; ++i) {
    if (i != 0) out << " ";
    out << buf[i];
  }
  return out;
}
