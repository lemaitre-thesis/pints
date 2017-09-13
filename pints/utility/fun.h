#ifndef PINTS_UTILITY_FUN
#define PINTS_UTILITY_FUN

namespace pints {
  namespace utility {
    // min (can mix types)
    template <class U, class V>
    constexpr auto min(U&& u, V&& v)
    -> decltype(u < v ? u : v) {
      return u < v ? u : v;
    }

    // max (can mix types)
    template <class U, class V>
    constexpr auto max(U&& u, V&& v)
    -> decltype(u >= v ? u : v) {
      return u >= v ? u : v;
    }


    // is power of 2?
    template <class T>
    constexpr bool is_power2(T t) {
      return (t <= T{1}) ? (t == T{1}) : ( t & T{1} ? false : is_power2(t >> 1));
    }

    template <class T>
    constexpr T next_power2(T t) {
      return (t <= T{1}) ? T{1} : (next_power2(t >> 1) << 1);
    }
  }
}

#endif // PINTS_UTILITY_FUN
