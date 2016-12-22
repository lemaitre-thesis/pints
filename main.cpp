#include <iostream>
#include <cstddef>
#include "pints-cpp.h"
//#include "pints-cpp-sse.h"
//#include "pints-cpp-avx.h"
#include "pints-cpp-funcs.h"

template <class T> struct Swap_FP_type;
template <> struct Swap_FP_type<float> { using type = double; };
template <> struct Swap_FP_type<double> { using type = float; };
template <class T> using swap_fp_t = typename Swap_FP_type<T>::type;

template <class T, int N>
void smul(const T* A, const swap_fp_t<T>* B, T* C, int n) {
  Vec<T, N> vA, vB, vC;
  for (int i = 0; i < n; i += N) {
    vA = vload<T, N>(&A[i]);
    vB = vconvert<T, N>(vload<swap_fp_t<T>, N>(&B[i]));
    vC = vadd(vA, vB);
    vC = vfma(vA, vB, vC);
    vstore(&C[i], vC);
  }
}

template void smul<float, 1>(const float* A, const double* B, float* C, int n);
template void smul<float, 2>(const float* A, const double* B, float* C, int n);
template void smul<float, 4>(const float* A, const double* B, float* C, int n);
template void smul<float, 8>(const float* A, const double* B, float* C, int n);
template void smul<float, 16>(const float* A, const double* B, float* C, int n);

template void smul<double, 1>(const double* A, const float* B, double* C, int n);
template void smul<double, 2>(const double* A, const float* B, double* C, int n);
template void smul<double, 4>(const double* A, const float* B, double* C, int n);
template void smul<double, 8>(const double* A, const float* B, double* C, int n);
template void smul<double, 16>(const double* A, const float* B, double* C, int n);

const char* types() { return "void"; }
template <class... Args> const char* types() { return __PRETTY_FUNCTION__; }
template <class... Args> const char* types(Args&&...) { return types<Args&&...>(); }

int main() {
  float A[4] = {-0.3f, -1.4f, -2.3f, -3.5f};
  float B[4] = {0.3f, 1.4f, 2.3f, 3.5f};
  Vec<float, 4> a = vload<float, 4>(A);
  Vec<float, 4> b = vload<float, 4>(B);
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << vshuffle<4,1>(a, b, swizzle<3,3,3,3>{}, mask<true, false, false, false>{}) << std::endl;
  return 0;
}
