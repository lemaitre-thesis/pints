#include <stdio.h>
#include <stdlib.h>
//#include <immintrin.h>

//#define SSE
//#define SSE2
//#define AVX
//#define AVX2
//#define AVX_FMA
//#define inline
#include "pints.h"

#define N 128
float A[N] = {1}, B[N] = {1};
double C[N] = {1}, D[N] = {1};

//#define v8f_partial_transpose(row3, row2, row1, row0, tmp3, tmp2, tmp1, tmp0, col3, col2, col1, col0) \
//  tmp3 = _mm256_unpackhi_ps(row2, row3); \
//  tmp2 = _mm256_unpackhi_ps(row0, row1); \
//  tmp1 = _mm256_unpacklo_ps(row2, row3); \
//  tmp0 = _mm256_unpacklo_ps(row0, row1); \
//  col3 = _mm256_shuffle_ps(tmp2, tmp3, 0xEE); \
//  col2 = _mm256_shuffle_ps(tmp2, tmp3, 0x44); \
//  col1 = _mm256_shuffle_ps(tmp0, tmp1, 0xEE); \
//  col0 = _mm256_shuffle_ps(tmp0, tmp1, 0x44)
//#define v8f_transpose_hilo(srchigh, srclow, dsthigh, dstlow) \
//  dsthigh = _mm256_permute2f128_ps(srchigh, srclow, 0x13); \
//  dstlow  = _mm256_permute2f128_ps(srchigh, srclow, 0x02)
//
//
//#define v8f_transpose(row0, row1, row2, row3, row4, row5, row6, row7) { \
//  __m256 t0, t1, t2, t3, t4, t5, t6, t7, u0, u1, u2, u3, u4, u5, u6, u7; \
//  v8f_partial_transpose(row7, row6, row5, row4, t7, t6, t5, t4, u7, u6, u5, u4); \
//  v8f_partial_transpose(row3, row2, row1, row0, t3, t2, t1, t0, u3, u2, u1, u0); \
//  v8f_transpose_hilo(u7, u3, row7, row3); \
//  v8f_transpose_hilo(u6, u2, row6, row2); \
//  v8f_transpose_hilo(u5, u1, row5, row1); \
//  v8f_transpose_hilo(u4, u0, row4, row0); \
//}
//
//#define v4f_transpose(row0, row1, row2, row3) { \
//  __m128 tmp0, tmp1, tmp2, tmp3; \
//  tmp0 = _mm_unpacklo_ps(row0, row1); \
//  tmp2 = _mm_unpacklo_ps(row2, row3); \
//  tmp1 = _mm_unpackhi_ps(row0, row1); \
//  tmp3 = _mm_unpackhi_ps(row2, row3); \
//  row0 = _mm_movelh_ps(tmp0, tmp2); \
//  row1 = _mm_movehl_ps(tmp2, tmp0); \
//  row2 = _mm_movelh_ps(tmp1, tmp3); \
//  row3 = _mm_movehl_ps(tmp3, tmp1); \
//}
//
//#define v8f_print_matrix(row0, row1, row2, row3, row4, row5, row6, row7) { \
//  v8f_print(row7);printf("\n"); \
//  v8f_print(row6);printf("\n"); \
//  v8f_print(row5);printf("\n"); \
//  v8f_print(row4);printf("\n"); \
//  v8f_print(row3);printf("\n"); \
//  v8f_print(row2);printf("\n"); \
//  v8f_print(row1);printf("\n"); \
//  v8f_print(row0);printf("\n"); \
//}
//
//void transpose_v8f(float* m) {
//  v8f
//    row0 = v8f_load(m),
//    row1 = v8f_load(m + 8),
//    row2 = v8f_load(m + 16),
//    row3 = v8f_load(m + 24),
//    row4 = v8f_load(m + 32),
//    row5 = v8f_load(m + 40),
//    row6 = v8f_load(m + 48),
//    row7 = v8f_load(m + 56);
//  v8f_transpose(row0, row1, row2, row3, row4, row5, row6, row7);
//  v8f_store(m,      row0);
//  v8f_store(m + 8,  row1);
//  v8f_store(m + 16, row2);
//  v8f_store(m + 24, row3);
//  v8f_store(m + 32, row4);
//  v8f_store(m + 40, row5);
//  v8f_store(m + 48, row6);
//  v8f_store(m + 56, row7);
//}
//void transpose_v4f(float* m) {
//  v4f
//    row0 = v4f_load(m),
//    row1 = v4f_load(m + 4),
//    row2 = v4f_load(m + 8),
//    row3 = v4f_load(m + 12);
//  v4f_transpose(row0, row1, row2, row3);
//  v4f_store(m,      row0);
//  v4f_store(m + 4,  row1);
//  v4f_store(m + 8,  row2);
//  v4f_store(m + 12, row3);
//}
//
//#define v8f_transpose4(row10, row32) { \
//  v8f tmp32, tmp10; \
//  v8i indices = v8i_set(7, 3, 6, 2, 5, 1, 4, 0); \
//  tmp32 = _mm256_unpackhi_ps(row10, row32); \
//  tmp10 = _mm256_unpacklo_ps(row10, row32); \
//  row32 = _mm256_permutevar8x32_ps(tmp32, indices); \
//  row10 = _mm256_permutevar8x32_ps(tmp10, indices); \
//}
//void transpose4_v8f(float* m) {
//  v8f row32, row10;
//  row32 = v8f_loadu(m + 8);
//  row10 = v8f_loadu(m);
//  v8f_transpose4(row10, row32);
//  v8f_storeu(m + 8, row32);
//  v8f_storeu(m,     row10);
//}
//
//void transpose8_v8f(float* m) {
//  v8f row76, row54, row32, row10;
//  // Transpose Upper Left
//  row32 = _mm256_loadu2_m128(m + 24, m + 16);
//  row10 = _mm256_loadu2_m128(m + 8,  m);
//  v8f_transpose4(row10, row32);
//  _mm256_storeu2_m128(m + 24, m + 16, row32);
//  _mm256_storeu2_m128(m + 8,  m     , row10);
//  // Load Upper Right
//  row32 = _mm256_loadu2_m128(m + 28, m + 20);
//  row10 = _mm256_loadu2_m128(m + 12, m + 4);
//  // Load Lower Left
//  row76 = _mm256_loadu2_m128(m + 56, m + 48);
//  row54 = _mm256_loadu2_m128(m + 40, m + 32);
//  // Transpose Blocks
//  v8f_transpose4(row10, row32);
//  v8f_transpose4(row54, row76);
//  // Store Upper Right
//  _mm256_storeu2_m128(m + 28, m + 20, row76);
//  _mm256_storeu2_m128(m + 12, m + 4,  row54);
//  // Store Lower Left
//  _mm256_storeu2_m128(m + 56, m + 48, row32);
//  _mm256_storeu2_m128(m + 40, m + 32, row10);
//  // Transpose Upper Left
//  row32 = _mm256_loadu2_m128(m + 60, m + 52);
//  row10 = _mm256_loadu2_m128(m + 44, m + 36);
//  v8f_transpose4(row10, row32);
//  _mm256_storeu2_m128(m + 60, m + 52, row32);
//  _mm256_storeu2_m128(m + 44, m + 36, row10);
//}
//
//void transpose8_v4f(float* m) {
//  v4f row0, row1, row2, row3, row4, row5, row6, row7;
//  // Transpose Upper Left
//  row0 = v4f_loadu(m);
//  row1 = v4f_loadu(m + 8);
//  row2 = v4f_loadu(m + 16);
//  row3 = v4f_loadu(m + 24);
//  v4f_transpose(row0, row1, row2, row3);
//  v4f_storeu(m,      row0);
//  v4f_storeu(m + 8,  row1);
//  v4f_storeu(m + 16, row2);
//  v4f_storeu(m + 24, row3);
//  // Load Upper Right
//  row0 = v4f_loadu(m + 4);
//  row1 = v4f_loadu(m + 12);
//  row2 = v4f_loadu(m + 20);
//  row3 = v4f_loadu(m + 28);
//  // Load Lower Left
//  row4 = v4f_loadu(m + 32);
//  row5 = v4f_loadu(m + 40);
//  row6 = v4f_loadu(m + 48);
//  row7 = v4f_loadu(m + 56);
//  // Transpose Blocks
//  v4f_transpose(row0, row1, row2, row3);
//  v4f_transpose(row4, row5, row6, row7);
//  // Store Upper Right
//  v4f_storeu(m + 4,  row4);
//  v4f_storeu(m + 12, row5);
//  v4f_storeu(m + 20, row6);
//  v4f_storeu(m + 28, row7);
//  // Store Lower Left
//  v4f_storeu(m + 32, row0);
//  v4f_storeu(m + 40, row1);
//  v4f_storeu(m + 48, row2);
//  v4f_storeu(m + 56, row3);
//  // Transpose Lower Right
//  row0 = v4f_loadu(m + 36);
//  row1 = v4f_loadu(m + 44);
//  row2 = v4f_loadu(m + 52);
//  row3 = v4f_loadu(m + 60);
//  v4f_transpose(row0, row1, row2, row3);
//  v4f_storeu(m + 36, row0);
//  v4f_storeu(m + 44, row1);
//  v4f_storeu(m + 52, row2);
//  v4f_storeu(m + 60, row3);
//}
//#define DO1(...) __VA_ARGS__;
//#define DO10(...) DO1(__VA_ARGS__);DO1(__VA_ARGS__);DO1(__VA_ARGS__);DO1(__VA_ARGS__);DO1(__VA_ARGS__);DO1(__VA_ARGS__);DO1(__VA_ARGS__);DO1(__VA_ARGS__);DO1(__VA_ARGS__);DO1(__VA_ARGS__);
//#define DO100(...) DO10(__VA_ARGS__);DO10(__VA_ARGS__);DO10(__VA_ARGS__);DO10(__VA_ARGS__);DO10(__VA_ARGS__);DO10(__VA_ARGS__);DO10(__VA_ARGS__);DO10(__VA_ARGS__);DO10(__VA_ARGS__);DO10(__VA_ARGS__);
//#define DO1000(...) DO100(__VA_ARGS__);DO100(__VA_ARGS__);DO100(__VA_ARGS__);DO100(__VA_ARGS__);DO100(__VA_ARGS__);DO100(__VA_ARGS__);DO100(__VA_ARGS__);DO100(__VA_ARGS__);DO100(__VA_ARGS__);DO100(__VA_ARGS__);
//
//#define MIN(a, b) (((a) < (b)) ? (a) : (b))
//#define MAX(a, b) (((a) > (b)) ? (a) : (b))
//
//#define M_SIZE 100
//#define NTRY 1000000
//float M8[8*8*M_SIZE];
//float M4[4*4*M_SIZE];
//void test_transpose_v8f() {
//  float *M8p[M_SIZE], *M4p[M_SIZE];
//  for (int i = 0; i < M_SIZE; ++i) {
//    M8p[i] = &M8[8*8*i];
//    M4p[i] = &M4[4*4*i];
//  }
//  v8f
//    row0 = v8f_set(07, 06, 05, 04, 03, 02, 01, 00),
//    row1 = v8f_set(17, 16, 15, 14, 13, 12, 11, 10),
//    row2 = v8f_set(27, 26, 25, 24, 23, 22, 21, 20),
//    row3 = v8f_set(37, 36, 35, 34, 33, 32, 31, 30),
//    row4 = v8f_set(47, 46, 45, 44, 43, 42, 41, 40),
//    row5 = v8f_set(57, 56, 55, 54, 53, 52, 51, 50),
//    row6 = v8f_set(67, 66, 65, 64, 63, 62, 61, 60),
//    row7 = v8f_set(77, 76, 75, 74, 73, 72, 71, 70);
//  
//  //v8f_print_matrix(row0, row1, row2, row3, row4, row5, row6, row7);
//  printf("\nTranspose\n\n");
//  double mintime;
//  mintime = 1.0/0.0;
//  for (int j = 0; j < NTRY; ++j) {
//    for (int i = 0; i < M_SIZE; ++i) transpose_v8f(M8p[i]);// */v8f_transpose(row0, row1, row2, row3, row4, row5, row6, row7);
//    long long t0 = _rdtsc();
//    for (int i = 0; i < M_SIZE; ++i) {DO1(transpose_v8f(M8p[i]))}// */{DO1(v8f_transpose(row0, row1, row2, row3, row4, row5, row6, row7);)}
//    long long t1 = _rdtsc();
//    double tdiff = t1 - t0;
//    mintime = MIN(tdiff, mintime);
//  }
//  printf("\ntranspose(v8f) 8x8: %lf cycles\n", mintime / (M_SIZE * 1));
//
//  mintime = 1.0/0.0;
//  for (int j = 0; j < NTRY; ++j) {
//    for (int i = 0; i < M_SIZE; ++i) transpose8_v4f(M8p[i]);
//    long long t0 = _rdtsc();
//    for (int i = 0; i < M_SIZE; ++i) {DO1(transpose8_v4f(M8p[i]))}
//    long long t1 = _rdtsc();
//    double tdiff = t1 - t0;
//    mintime = MIN(tdiff, mintime);
//  }
//  printf("\ntranspose(v4f) 8x8: %lf cycles\n", mintime / (M_SIZE * 1));
//
//  mintime = 1.0/0.0;
//  for (int j = 0; j < NTRY; ++j) {
//    for (int i = 0; i < M_SIZE; ++i) transpose8_v8f(M8p[i]);
//    long long t0 = _rdtsc();
//    for (int i = 0; i < M_SIZE; ++i) {DO1(transpose8_v8f(M8p[i]))}
//    long long t1 = _rdtsc();
//    double tdiff = t1 - t0;
//    mintime = MIN(tdiff, mintime);
//  }
//  printf("\ntranspose(v8f)'8x8: %lf cycles\n", mintime / (M_SIZE * 1));
//
//  mintime = 1.0/0.0;
//  for (int j = 0; j < NTRY; ++j) {
//    for (int i = 0; i < M_SIZE; ++i) transpose4_v8f(M4p[i]);
//    long long t0 = _rdtsc();
//    for (int i = 0; i < M_SIZE; ++i) {DO1(transpose4_v8f(M4p[i]))}
//    long long t1 = _rdtsc();
//    double tdiff = t1 - t0;
//    mintime = MIN(tdiff, mintime);
//  }
//  printf("\ntranspose(v8f) 4x4: %lf cycles (= 0.25 * %lf)\n", mintime / (M_SIZE * 1), 4 * mintime / (M_SIZE * 1));
//
//  mintime = 1.0/0.0;
//  for (int j = 0; j < NTRY; ++j) {
//    for (int i = 0; i < M_SIZE; ++i) transpose_v4f(M4p[i]);
//    long long t0 = _rdtsc();
//    for (int i = 0; i < M_SIZE; ++i) {DO1(transpose_v4f(M4p[i]))}
//    long long t1 = _rdtsc();
//    double tdiff = t1 - t0;
//    mintime = MIN(tdiff, mintime);
//  }
//  printf("\ntranspose(v4f) 4x4: %lf cycles (= 0.25 * %lf)\n", mintime / (M_SIZE * 1), 4 * mintime / (M_SIZE * 1));
//}

double dotprod_v2d(const double* a, const double* b, int n) {
  double r;
  int i;
  m2d vmask;
  v2d va, vb, s = v2d_zero(), sp, add;
  for (i = 0; i < n - 2; i += 2) {
    va = v2d_loadu(&a[i]);
    vb = v2d_loadu(&b[i]);
    s = v2d_fmadd(va, vb, s);
  } /* remainder */ {
    vmask = m2d_cvt_m2l(m2l_gt(v2l_set1(n-i), v2l_set(0, 1)));
    va = v2d_loadu(&a[i]);
    vb = v2d_loadu(&b[i]);
    va = v2d_maskz_move(vmask, va);
    s = v2d_fmadd(va, vb, s);
  }
  // reduce s
  return sd_cvt_v2d(v2d_reduce_add(s));
#if 0
  sp = v2d_permute(s, PINTS_SHUFFLE(1, 0));
  add = v2d_add(s, sp);
  //v1d_store(&r, v1d_cast_v2d(add));
  return sd_cvt_v2d(add);
#endif
}

float dotprod_v4f(const float* a, const float* b, int n) {
  float r;
  int i;
  m4f vmask;
  v4f va, vb, s = v4f_zero(), sp, add1, add1p, add2;
  for (i = 0; i < n - 4; i += 4) {
    va = v4f_loadu(&a[i]);
    vb = v4f_loadu(&b[i]);
    s = v4f_fmadd(va, vb, s);
  } /* remainder */ {
    vmask = m4f_cvt_m4i(m4i_gt(v4i_set1(n-i), v4i_set(0, 1, 2, 3)));
    va = v4f_loadu(&a[i]);
    vb = v4f_loadu(&b[i]);
    va = v4f_maskz_move(vmask, va);
    s = v4f_fmadd(va, vb, s);
  }
  // reduce s
  return sf_cvt_v4f(v4f_reduce_add(s));
#if 0
  sp = v4f_permute2(s, PINTS_SHUFFLE(1, 0));
  add1 = v4f_add(s, sp);
  add1p = v4f_permute2x2(add1, PINTS_SHUFFLE(1, 0));
  add2 = v4f_add(add1, add1p);
  //v1f_store(&r, v1f_cast_v4f(add2));
  return sf_cvt_v4f(add2);
#endif
}
float dotprod_v8f(const float* a, const float* b, int n) {
  float r;
  int i;
  m8f vmask;
  v8f va, vb, s = v8f_zero(), sp, add1, add1p, add2, add2p, add3;
  for (i = 0; i < n - 8; i += 8) {
    va = v8f_loadu(&a[i]);
    vb = v8f_loadu(&b[i]);
    s = v8f_fmadd(va, vb, s);
  } /* remainder */ {
    vmask = m8f_cvt_m8i(m8i_gt(v8i_set1(n-i), v8i_set(0, 1, 2, 3, 4, 5, 6, 7)));
    va = v8f_loadu(&a[i]);
    vb = v8f_loadu(&b[i]);
    va = v8f_maskz_move(vmask, va);
    s = v8f_fmadd(va, vb, s);
  }
  // reduce s
  return sf_cvt_v8f(v8f_reduce_add(s));
#if 0
  sp = v8f_permute2(s, PINTS_SHUFFLE(1, 0));
  add1 = v8f_add(s, sp);
  add1p = v8f_permute4x2(add1, PINTS_SHUFFLE(2, 3, 0, 1)/*0x4E*/);
  add2 = v8f_add(add1, add1p);
  add2p = v8f_permute2x4(add2, PINTS_SHUFFLE(1, 0));
  add3 = v8f_add(add2, add2p);
  //v1f_store(&r, v1f_cast_v8f(add3));
  return sf_cvt_v8f(add3);
#endif
}
float dotprod_v16f(const float* a, const float* b, int n) {
  float r;
  int i;
  m16f vmask;
  v16f va, vb, s = v16f_zero(), sp, add1, add1p, add2, add2p, add3, add3p, add4;
  for (i = 0; i < n - 16; i += 16) {
    va = v16f_loadu(&a[i]);
    vb = v16f_loadu(&b[i]);
    s = v16f_fmadd(va, vb, s);
  } /* remainder */ {
    vmask = m16f_cvt_m16i(m16i_gt(v16i_set1(n-i), v16i_set(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15)));
    va = v16f_loadu(&a[i]);
    vb = v16f_loadu(&b[i]);
    va = v16f_maskz_move(vmask, va);
    s = v16f_fmadd(va, vb, s);
  }
  // reduce s
  return sf_cvt_v16f(v16f_reduce_add(s));
#if 0
  sp = v16f_permute2(s, PINTS_SHUFFLE(1, 0));
  add1 = v16f_add(s, sp);
  add1p = v16f_permute4(add1, PINTS_SHUFFLE(1, 0, 3, 2)/*0xB1*/);
  add2 = v16f_add(add1, add1p);
  add2p = v16f_permute4x4(add2, PINTS_SHUFFLE(2, 3, 0, 1)/*0x4E*/);
  add3 = v16f_add(add2, add2p);
  add3p = v16f_permute2x8(add3, PINTS_SHUFFLE(1, 0));
  add4 = v16f_add(add3, add3p);
  return sf_cvt_v16f(add4);
#endif
}

int main() {
  float f1[16] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
  float f2[16] = {1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1};
  double d1[16] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
  double d2[16] = {1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1};
  printf("(v4f) f1.f2: %f\n  A.B: %f\n", dotprod_v4f(f1, f2, 15), dotprod_v4f(A, B, N));
  printf("(v8f) f1.f2: %f\n  A.B: %f\n", dotprod_v8f(f1, f2, 15), dotprod_v8f(A, B, N));
  printf("(v16) f1.f2: %f\n  A.B: %f\n", dotprod_v16f(f1, f2, 15), dotprod_v16f(A, B, N));
  printf("(v2d) d1.d2: %lf\n  C.D: %lf\n", dotprod_v2d(d1, d2, 15), dotprod_v2d(C, D, N));
  //test_transpose_v8f();
  
  return 0;
}
