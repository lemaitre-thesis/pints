#include <iostream>
#include "pints-cpp.h"
#include "pints-cpp-sse.h"
#include "pints-cpp-avx.h"

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

int main() {
  return 0;
}
