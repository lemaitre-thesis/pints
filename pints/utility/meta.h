#ifndef PINTS_UTILITY_META_H
#define PINTS_UTILITY_META_H

#include <utility>

namespace PintS {
  namespace utility {
    // details namespace
    namespace _ {
      // check if T is in Args...
      template <class T, class... Args>
      struct in_s {
        static constexpr bool value = false;
      };

      // Recursion
      template <class T, class Head, class... Tail>
      struct in_s<T, Head, Tail...> : in_s<T, Tail...> {};

      // Found
      template <class T, class... Tail>
      struct in_s<T, T, Tail...> {
        static constexpr bool value = true;
      };
    }

    // check if T is in Args...
    template <class T, class... Args>
    constexpr bool in() { return _::template in_s<T, Args...>::value; }
  }
}

#endif // PINTS_UTILITY_META_H
