#include <stdio.h>
#include <stdlib.h>
//#include <intrin.h>

//#define SSE
//#define SSE2
//#define AVX
//#define AVX2
//#define inline
#include "psimd.h"

#define N 128
float A[N] = {1}, B[N] = {1};
double C[N] = {1}, D[N] = {1};

double dotprod_v2d(const double* a, const double* b, int n) {
  double r;
  int i;
  v2l vmask;
  v2d va, vb, s = v2d_zero(), sp, add;
  for (i = 0; i < n - 2; i += 2) {
    va = v2d_loadu(&a[i]);
    vb = v2d_loadu(&b[i]);
    s = v2d_fmadd(va, vb, s);
  } /* remainder */ {
    vmask = v2l_gt(v2l_set1(n-i), v2l_set(1, 0));
    va = v2d_loadu(&a[i]);
    vb = v2d_loadu(&b[i]);
    va = v2d_and(va, v2d_cast_v2l(vmask));
    s = v2d_fmadd(va, vb, s);
  }
  // reduce s
  sp = v2d_permute(s, 0x1);
  add = v2d_add(s, sp);
  v1d_store(&r, v1d_cast_v2d(add));
  return r;
}

float dotprod_v4f(const float* a, const float* b, int n) {
  float r;
  int i;
  v4i vmask;
  v4f va, vb, s = v4f_zero(), sp, add1, add1p, add2;
  for (i = 0; i < n - 4; i += 4) {
    va = v4f_loadu(&a[i]);
    vb = v4f_loadu(&b[i]);
    s = v4f_fmadd(va, vb, s);
  } /* remainder */ {
    vmask = v4i_gt(v4i_set1(n-i), v4i_set(3, 2, 1, 0));
    va = v4f_loadu(&a[i]);
    vb = v4f_loadu(&b[i]);
    va = v4f_and(va, v4f_cast_v4i(vmask));
    s = v4f_fmadd(va, vb, s);
  }
  // reduce s
  sp = v4f_permute(s, 0xB1);
  add1 = v4f_add(s, sp);
  add1p = v4f_permute(add1, 0x4E);
  add2 = v4f_add(add1, add1p);
  v1f_store(&r, v1f_cast_v4f(add2));
  return r;
}
float dotprod_v8f(const float* a, const float* b, int n) {
  float r;
  int i;
  v8i vmask;
  v8f va, vb, s = v8f_zero(), sp, add1, add1p, add2, add2p, add3;
  for (i = 0; i < n - 8; i += 8) {
    va = v8f_loadu(&a[i]);
    vb = v8f_loadu(&b[i]);
    s = v8f_fmadd(va, vb, s);
  } /* remainder */ {
    vmask = v8i_gt(v8i_set1(n-i), v8i_set(7, 6, 5, 4, 3, 2, 1, 0));
    va = v8f_loadu(&a[i]);
    vb = v8f_loadu(&b[i]);
    va = v8f_and(va, v8f_cast_v8i(vmask));
    s = v8f_fmadd(va, vb, s);
  }
  // reduce s
  sp = v8f_permute(s, 0xB1);
  add1 = v8f_add(s, sp);
  add1p = v8f_permute(add1, 0x4E);
  add2 = v8f_add(add1, add1p);
  add2p = v8f_merge_v4f(v4f_get_high_v8f(add2), v4f_get_low_v8f(add2));
  add3 = v8f_add(add2, add2p);
  v1f_store(&r, v1f_cast_v8f(add3));
  return r;
}

int main() {
  float f1[16] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
  float f2[16] = {1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1};
  double d1[16] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
  double d2[16] = {1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1};
  printf("f1.f2: %f\n  A.B: %f\n", dotprod_v4f(f1, f2, 15), dotprod_v4f(A, B, N));
  printf("f1.f2: %f\n  A.B: %f\n", dotprod_v8f(f1, f2, 15), dotprod_v8f(A, B, N));
  printf("d1.d2: %lf\n  C.D: %lf\n", dotprod_v2d(d1, d2, 16), dotprod_v2d(C, D, N));

  v4f a0 = v4f_set(4,4,4,4);
  v2d b = v2d_set(2,2);
  v4f c = a0;
  //c = _mm_cvtpd_ps(b);
  v4f_print(c);
  printf("\n");
  
  return 0;
}
