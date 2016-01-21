#ifndef PINTS_POLYFILL_FUNCS_H
#define PINTS_POLYFILL_FUNCS_H
//include/pints-polyfill-funcs.h

#include "stdint.h"
#include "math.h"

////////////////////////////////////////////////////////////////////////////////
// Internal Types
////////////////////////////////////////////////////////////////////////////////
union __v1d {
  double v;
  int64_t i;
};
union __v1f {
  float v;
  int32_t i;
};
union __v1i {
  int32_t v;
  int32_t i;
};
union __v1l {
  int64_t v;
  int64_t i;
};
struct __v2d { v1d a, b; };
struct __v2f { v1f a, b; };
struct __v2i { v1i a, b; };
struct __v2l { v1l a, b; };
struct __v4d { v2d a, b; };
struct __v4f { v2f a, b; };
struct __v4i { v2i a, b; };
struct __v4l { v2l a, b; };
struct __v8d { v4d a, b; };
struct __v8f { v4f a, b; };
struct __v8i { v4i a, b; };
struct __v8l { v4l a, b; };
struct __v16f { v8f a, b; };
struct __v16i { v8i a, b; };

////////////////////////////////////////////////////////////////////////////////
// Declarations
////////////////////////////////////////////////////////////////////////////////
/* LOADS */

static inline union __v1d __v1d_load(const double *p);
static inline union __v1f __v1f_load(const float *p);
static inline union __v1i __v1i_load(const int32_t *p);
static inline union __v1l __v1l_load(const int64_t *p);
static inline v2d __v2d_load(const double *p);
static inline v2f __v2f_load(const float *p);
static inline v2i __v2i_load(const int32_t *p);
static inline v2l __v2l_load(const int64_t *p);
static inline v4d __v4d_load(const double *p);
static inline v4f __v4f_load(const float *p);
static inline v4i __v4i_load(const int32_t *p);
static inline v4l __v4l_load(const int64_t *p);
static inline v8d __v8d_load(const double *p);
static inline v8f __v8f_load(const float *p);
static inline v8i __v8i_load(const int32_t *p);
static inline v8l __v8l_load(const int64_t *p);
static inline v16f __v16f_load(const float *p);
static inline v16i __v16i_load(const int32_t *p);

static inline v2d __v2d_loadu(const double *p);
static inline v2f __v2f_loadu(const float *p);
static inline v2i __v2i_loadu(const int32_t *p);
static inline v2l __v2l_loadu(const int64_t *p);
static inline v4d __v4d_loadu(const double *p);
static inline v4f __v4f_loadu(const float *p);
static inline v4i __v4i_loadu(const int32_t *p);
static inline v4l __v4l_loadu(const int64_t *p);
static inline v8d __v8d_loadu(const double *p);
static inline v8f __v8f_loadu(const float *p);
static inline v8i __v8i_loadu(const int32_t *p);
static inline v8l __v8l_loadu(const int64_t *p);
static inline v16f __v16f_loadu(const float *p);
static inline v16i __v16i_loadu(const int32_t *p);

static inline v2d __v2d_load1(const double *p);
static inline v2f __v2f_load1(const float *p);
static inline v2i __v2i_load1(const int32_t *p);
static inline v2l __v2l_load1(const int64_t *p);
static inline v4d __v4d_load1(const double *p);
static inline v4f __v4f_load1(const float *p);
static inline v4i __v4i_load1(const int32_t *p);
static inline v4l __v4l_load1(const int64_t *p);
static inline v8d __v8d_load1(const double *p);
static inline v8f __v8f_load1(const float *p);
static inline v8i __v8i_load1(const int32_t *p);
static inline v8l __v8l_load1(const int64_t *p);
static inline v16f __v16f_load1(const float *p);
static inline v16i __v16i_load1(const int32_t *p);

static inline v1d compatible_v1d_loadu(const double *p);
static inline v1f compatible_v1f_loadu(const float *p);
static inline v1i compatible_v1i_loadu(const int32_t *p);
static inline v1l compatible_v1l_loadu(const int64_t *p);
static inline v2d compatible_v2d_loadu(const double *p);
static inline v2f compatible_v2f_loadu(const float *p);
static inline v2i compatible_v2i_loadu(const int32_t *p);
static inline v2l compatible_v2l_loadu(const int64_t *p);
static inline v4d compatible_v4d_loadu(const double *p);
static inline v4f compatible_v4f_loadu(const float *p);
static inline v4i compatible_v4i_loadu(const int32_t *p);
static inline v4l compatible_v4l_loadu(const int64_t *p);
static inline v8d compatible_v8d_loadu(const double *p);
static inline v8f compatible_v8f_loadu(const float *p);
static inline v8i compatible_v8i_loadu(const int32_t *p);
static inline v8l compatible_v8l_loadu(const int64_t *p);
static inline v16f compatible_v16f_loadu(const float *p);
static inline v16i compatible_v16i_loadu(const int32_t *p);

/* STORES */

static inline void __v1d_store(double *p, union __v1d a);
static inline void __v1f_store(float *p, union __v1f a);
static inline void __v1i_store(int32_t *p, union __v1i a);
static inline void __v1l_store(int64_t *p, union __v1l a);
static inline void __v2d_store(double *p, v2d a);
static inline void __v2f_store(float *p, v2f a);
static inline void __v2i_store(int32_t *p, v2i a);
static inline void __v2l_store(int64_t *p, v2l a);
static inline void __v4d_store(double *p, v4d a);
static inline void __v4f_store(float *p, v4f a);
static inline void __v4i_store(int32_t *p, v4i a);
static inline void __v4l_store(int64_t *p, v4l a);
static inline void __v8d_store(double *p, v8d a);
static inline void __v8f_store(float *p, v8f a);
static inline void __v8i_store(int32_t *p, v8i a);
static inline void __v8l_store(int64_t *p, v8l a);
static inline void __v16f_store(float *p, v16f a);
static inline void __v16i_store(int32_t *p, v16i a);

static inline void __v2d_storeu(double *p, v2d a);
static inline void __v2f_storeu(float *p, v2f a);
static inline void __v2i_storeu(int32_t *p, v2i a);
static inline void __v2l_storeu(int64_t *p, v2l a);
static inline void __v4d_storeu(double *p, v4d a);
static inline void __v4f_storeu(float *p, v4f a);
static inline void __v4i_storeu(int32_t *p, v4i a);
static inline void __v4l_storeu(int64_t *p, v4l a);
static inline void __v8d_storeu(double *p, v8d a);
static inline void __v8f_storeu(float *p, v8f a);
static inline void __v8i_storeu(int32_t *p, v8i a);
static inline void __v8l_storeu(int64_t *p, v8l a);
static inline void __v16f_storeu(float *p, v16f a);
static inline void __v16i_storeu(int32_t *p, v16i a);


static inline void compatible_v1d_storeu(double *p, v1d a);
static inline void compatible_v1f_storeu(float *p, v1f a);
static inline void compatible_v1i_storeu(int32_t *p, v1i a);
static inline void compatible_v1l_storeu(int64_t *p, v1l a);
static inline void compatible_v2d_storeu(double *p, v2d a);
static inline void compatible_v2f_storeu(float *p, v2f a);
static inline void compatible_v2i_storeu(int32_t *p, v2i a);
static inline void compatible_v2l_storeu(int64_t *p, v2l a);
static inline void compatible_v4d_storeu(double *p, v4d a);
static inline void compatible_v4f_storeu(float *p, v4f a);
static inline void compatible_v4i_storeu(int32_t *p, v4i a);
static inline void compatible_v4l_storeu(int64_t *p, v4l a);
static inline void compatible_v8d_storeu(double *p, v8d a);
static inline void compatible_v8f_storeu(float *p, v8f a);
static inline void compatible_v8i_storeu(int32_t *p, v8i a);
static inline void compatible_v8l_storeu(int64_t *p, v8l a);
static inline void compatible_v16f_storeu(float *p, v16f a);
static inline void compatible_v16i_storeu(int32_t *p, v16i a);

/* SETS */

static inline v1d __v1d_set(double v0);
static inline v1f __v1f_set(float v0);
static inline v1i __v1i_set(int32_t v0);
static inline v1l __v1l_set(int64_t v0);


static inline v2d __v2d_set1(double v);
static inline v2f __v2f_set1(float v);
static inline v2i __v2i_set1(int32_t v);
static inline v2l __v2l_set1(int64_t v);
static inline v4d __v4d_set1(double v);
static inline v4f __v4f_set1(float v);
static inline v4i __v4i_set1(int32_t v);
static inline v4l __v4l_set1(int64_t v);
static inline v8d __v8d_set1(double v);
static inline v8f __v8f_set1(float v);
static inline v8i __v8i_set1(int32_t v);
static inline v8l __v8l_set1(int64_t v);
static inline v16f __v16f_set1(float v);
static inline v16i __v16i_set1(int32_t v);

/* CONSTANTS */


/* COMPARISONS */

static inline union __v1d __v1d_eq(union __v1d a, union __v1d b);
static inline union __v1f __v1f_eq(union __v1f a, union __v1f b);
static inline union __v1i __v1i_eq(union __v1i a, union __v1i b);
static inline union __v1l __v1l_eq(union __v1l a, union __v1l b);
static inline v2d __v2d_eq(v2d a, v2d b);
static inline v2f __v2f_eq(v2f a, v2f b);
static inline v2i __v2i_eq(v2i a, v2i b);
static inline v2l __v2l_eq(v2l a, v2l b);
static inline v4d __v4d_eq(v4d a, v4d b);
static inline v4f __v4f_eq(v4f a, v4f b);
static inline v4i __v4i_eq(v4i a, v4i b);
static inline v4l __v4l_eq(v4l a, v4l b);
static inline v8d __v8d_eq(v8d a, v8d b);
static inline v8f __v8f_eq(v8f a, v8f b);
static inline v8i __v8i_eq(v8i a, v8i b);
static inline v8l __v8l_eq(v8l a, v8l b);
static inline v16f __v16f_eq(v16f a, v16f b);
static inline v16i __v16i_eq(v16i a, v16i b);

static inline union __v1d __v1d_neq(union __v1d a, union __v1d b);
static inline union __v1f __v1f_neq(union __v1f a, union __v1f b);
static inline union __v1i __v1i_neq(union __v1i a, union __v1i b);
static inline union __v1l __v1l_neq(union __v1l a, union __v1l b);
static inline v2d __v2d_neq(v2d a, v2d b);
static inline v2f __v2f_neq(v2f a, v2f b);
static inline v2i __v2i_neq(v2i a, v2i b);
static inline v2l __v2l_neq(v2l a, v2l b);
static inline v4d __v4d_neq(v4d a, v4d b);
static inline v4f __v4f_neq(v4f a, v4f b);
static inline v4i __v4i_neq(v4i a, v4i b);
static inline v4l __v4l_neq(v4l a, v4l b);
static inline v8d __v8d_neq(v8d a, v8d b);
static inline v8f __v8f_neq(v8f a, v8f b);
static inline v8i __v8i_neq(v8i a, v8i b);
static inline v8l __v8l_neq(v8l a, v8l b);
static inline v16f __v16f_neq(v16f a, v16f b);
static inline v16i __v16i_neq(v16i a, v16i b);

static inline union __v1d __v1d_gt(union __v1d a, union __v1d b);
static inline union __v1f __v1f_gt(union __v1f a, union __v1f b);
static inline union __v1i __v1i_gt(union __v1i a, union __v1i b);
static inline union __v1l __v1l_gt(union __v1l a, union __v1l b);
static inline v2d __v2d_gt(v2d a, v2d b);
static inline v2f __v2f_gt(v2f a, v2f b);
static inline v2i __v2i_gt(v2i a, v2i b);
static inline v2l __v2l_gt(v2l a, v2l b);
static inline v4d __v4d_gt(v4d a, v4d b);
static inline v4f __v4f_gt(v4f a, v4f b);
static inline v4i __v4i_gt(v4i a, v4i b);
static inline v4l __v4l_gt(v4l a, v4l b);
static inline v8d __v8d_gt(v8d a, v8d b);
static inline v8f __v8f_gt(v8f a, v8f b);
static inline v8i __v8i_gt(v8i a, v8i b);
static inline v8l __v8l_gt(v8l a, v8l b);
static inline v16f __v16f_gt(v16f a, v16f b);
static inline v16i __v16i_gt(v16i a, v16i b);

static inline union __v1d __v1d_geq(union __v1d a, union __v1d b);
static inline union __v1f __v1f_geq(union __v1f a, union __v1f b);
static inline union __v1i __v1i_geq(union __v1i a, union __v1i b);
static inline union __v1l __v1l_geq(union __v1l a, union __v1l b);
static inline v2d __v2d_geq(v2d a, v2d b);
static inline v2f __v2f_geq(v2f a, v2f b);
static inline v2i __v2i_geq(v2i a, v2i b);
static inline v2l __v2l_geq(v2l a, v2l b);
static inline v4d __v4d_geq(v4d a, v4d b);
static inline v4f __v4f_geq(v4f a, v4f b);
static inline v4i __v4i_geq(v4i a, v4i b);
static inline v4l __v4l_geq(v4l a, v4l b);
static inline v8d __v8d_geq(v8d a, v8d b);
static inline v8f __v8f_geq(v8f a, v8f b);
static inline v8i __v8i_geq(v8i a, v8i b);
static inline v8l __v8l_geq(v8l a, v8l b);
static inline v16f __v16f_geq(v16f a, v16f b);
static inline v16i __v16i_geq(v16i a, v16i b);

static inline union __v1d __v1d_lt(union __v1d a, union __v1d b);
static inline union __v1f __v1f_lt(union __v1f a, union __v1f b);
static inline union __v1i __v1i_lt(union __v1i a, union __v1i b);
static inline union __v1l __v1l_lt(union __v1l a, union __v1l b);
static inline v2d __v2d_lt(v2d a, v2d b);
static inline v2f __v2f_lt(v2f a, v2f b);
static inline v2i __v2i_lt(v2i a, v2i b);
static inline v2l __v2l_lt(v2l a, v2l b);
static inline v4d __v4d_lt(v4d a, v4d b);
static inline v4f __v4f_lt(v4f a, v4f b);
static inline v4i __v4i_lt(v4i a, v4i b);
static inline v4l __v4l_lt(v4l a, v4l b);
static inline v8d __v8d_lt(v8d a, v8d b);
static inline v8f __v8f_lt(v8f a, v8f b);
static inline v8i __v8i_lt(v8i a, v8i b);
static inline v8l __v8l_lt(v8l a, v8l b);
static inline v16f __v16f_lt(v16f a, v16f b);
static inline v16i __v16i_lt(v16i a, v16i b);

static inline union __v1d __v1d_leq(union __v1d a, union __v1d b);
static inline union __v1f __v1f_leq(union __v1f a, union __v1f b);
static inline union __v1i __v1i_leq(union __v1i a, union __v1i b);
static inline union __v1l __v1l_leq(union __v1l a, union __v1l b);
static inline v2d __v2d_leq(v2d a, v2d b);
static inline v2f __v2f_leq(v2f a, v2f b);
static inline v2i __v2i_leq(v2i a, v2i b);
static inline v2l __v2l_leq(v2l a, v2l b);
static inline v4d __v4d_leq(v4d a, v4d b);
static inline v4f __v4f_leq(v4f a, v4f b);
static inline v4i __v4i_leq(v4i a, v4i b);
static inline v4l __v4l_leq(v4l a, v4l b);
static inline v8d __v8d_leq(v8d a, v8d b);
static inline v8f __v8f_leq(v8f a, v8f b);
static inline v8i __v8i_leq(v8i a, v8i b);
static inline v8l __v8l_leq(v8l a, v8l b);
static inline v16f __v16f_leq(v16f a, v16f b);
static inline v16i __v16i_leq(v16i a, v16i b);

/* LOGIC */

static inline union __v1d __v1d_and(union __v1d a, union __v1d b);
static inline union __v1f __v1f_and(union __v1f a, union __v1f b);
static inline union __v1i __v1i_and(union __v1i a, union __v1i b);
static inline union __v1l __v1l_and(union __v1l a, union __v1l b);
static inline v2d __v2d_and(v2d a, v2d b);
static inline v2f __v2f_and(v2f a, v2f b);
static inline v2i __v2i_and(v2i a, v2i b);
static inline v2l __v2l_and(v2l a, v2l b);
static inline v4d __v4d_and(v4d a, v4d b);
static inline v4f __v4f_and(v4f a, v4f b);
static inline v4i __v4i_and(v4i a, v4i b);
static inline v4l __v4l_and(v4l a, v4l b);
static inline v8d __v8d_and(v8d a, v8d b);
static inline v8f __v8f_and(v8f a, v8f b);
static inline v8i __v8i_and(v8i a, v8i b);
static inline v8l __v8l_and(v8l a, v8l b);
static inline v16f __v16f_and(v16f a, v16f b);
static inline v16i __v16i_and(v16i a, v16i b);

static inline union __v1d __v1d_or(union __v1d a, union __v1d b);
static inline union __v1f __v1f_or(union __v1f a, union __v1f b);
static inline union __v1i __v1i_or(union __v1i a, union __v1i b);
static inline union __v1l __v1l_or(union __v1l a, union __v1l b);
static inline v2d __v2d_or(v2d a, v2d b);
static inline v2f __v2f_or(v2f a, v2f b);
static inline v2i __v2i_or(v2i a, v2i b);
static inline v2l __v2l_or(v2l a, v2l b);
static inline v4d __v4d_or(v4d a, v4d b);
static inline v4f __v4f_or(v4f a, v4f b);
static inline v4i __v4i_or(v4i a, v4i b);
static inline v4l __v4l_or(v4l a, v4l b);
static inline v8d __v8d_or(v8d a, v8d b);
static inline v8f __v8f_or(v8f a, v8f b);
static inline v8i __v8i_or(v8i a, v8i b);
static inline v8l __v8l_or(v8l a, v8l b);
static inline v16f __v16f_or(v16f a, v16f b);
static inline v16i __v16i_or(v16i a, v16i b);

static inline union __v1d __v1d_xor(union __v1d a, union __v1d b);
static inline union __v1f __v1f_xor(union __v1f a, union __v1f b);
static inline union __v1i __v1i_xor(union __v1i a, union __v1i b);
static inline union __v1l __v1l_xor(union __v1l a, union __v1l b);
static inline v2d __v2d_xor(v2d a, v2d b);
static inline v2f __v2f_xor(v2f a, v2f b);
static inline v2i __v2i_xor(v2i a, v2i b);
static inline v2l __v2l_xor(v2l a, v2l b);
static inline v4d __v4d_xor(v4d a, v4d b);
static inline v4f __v4f_xor(v4f a, v4f b);
static inline v4i __v4i_xor(v4i a, v4i b);
static inline v4l __v4l_xor(v4l a, v4l b);
static inline v8d __v8d_xor(v8d a, v8d b);
static inline v8f __v8f_xor(v8f a, v8f b);
static inline v8i __v8i_xor(v8i a, v8i b);
static inline v8l __v8l_xor(v8l a, v8l b);
static inline v16f __v16f_xor(v16f a, v16f b);
static inline v16i __v16i_xor(v16i a, v16i b);








/* ARITHMETIC AND MATH */


static inline union __v1d __v1d_add(union __v1d a, union __v1d b);
static inline union __v1f __v1f_add(union __v1f a, union __v1f b);
static inline union __v1i __v1i_add(union __v1i a, union __v1i b);
static inline union __v1l __v1l_add(union __v1l a, union __v1l b);
static inline v2d __v2d_add(v2d a, v2d b);
static inline v2f __v2f_add(v2f a, v2f b);
static inline v2i __v2i_add(v2i a, v2i b);
static inline v2l __v2l_add(v2l a, v2l b);
static inline v4d __v4d_add(v4d a, v4d b);
static inline v4f __v4f_add(v4f a, v4f b);
static inline v4i __v4i_add(v4i a, v4i b);
static inline v4l __v4l_add(v4l a, v4l b);
static inline v8d __v8d_add(v8d a, v8d b);
static inline v8f __v8f_add(v8f a, v8f b);
static inline v8i __v8i_add(v8i a, v8i b);
static inline v8l __v8l_add(v8l a, v8l b);
static inline v16f __v16f_add(v16f a, v16f b);
static inline v16i __v16i_add(v16i a, v16i b);

static inline union __v1d __v1d_sub(union __v1d a, union __v1d b);
static inline union __v1f __v1f_sub(union __v1f a, union __v1f b);
static inline union __v1i __v1i_sub(union __v1i a, union __v1i b);
static inline union __v1l __v1l_sub(union __v1l a, union __v1l b);
static inline v2d __v2d_sub(v2d a, v2d b);
static inline v2f __v2f_sub(v2f a, v2f b);
static inline v2i __v2i_sub(v2i a, v2i b);
static inline v2l __v2l_sub(v2l a, v2l b);
static inline v4d __v4d_sub(v4d a, v4d b);
static inline v4f __v4f_sub(v4f a, v4f b);
static inline v4i __v4i_sub(v4i a, v4i b);
static inline v4l __v4l_sub(v4l a, v4l b);
static inline v8d __v8d_sub(v8d a, v8d b);
static inline v8f __v8f_sub(v8f a, v8f b);
static inline v8i __v8i_sub(v8i a, v8i b);
static inline v8l __v8l_sub(v8l a, v8l b);
static inline v16f __v16f_sub(v16f a, v16f b);
static inline v16i __v16i_sub(v16i a, v16i b);


static inline union __v1d __v1d_mul(union __v1d a, union __v1d b);
static inline union __v1f __v1f_mul(union __v1f a, union __v1f b);
static inline union __v1i __v1i_mul(union __v1i a, union __v1i b);
static inline union __v1l __v1l_mul(union __v1l a, union __v1l b);
static inline v2d __v2d_mul(v2d a, v2d b);
static inline v2f __v2f_mul(v2f a, v2f b);
static inline v2i __v2i_mul(v2i a, v2i b);
static inline v2l __v2l_mul(v2l a, v2l b);
static inline v4d __v4d_mul(v4d a, v4d b);
static inline v4f __v4f_mul(v4f a, v4f b);
static inline v4i __v4i_mul(v4i a, v4i b);
static inline v4l __v4l_mul(v4l a, v4l b);
static inline v8d __v8d_mul(v8d a, v8d b);
static inline v8f __v8f_mul(v8f a, v8f b);
static inline v8i __v8i_mul(v8i a, v8i b);
static inline v8l __v8l_mul(v8l a, v8l b);
static inline v16f __v16f_mul(v16f a, v16f b);
static inline v16i __v16i_mul(v16i a, v16i b);

static inline union __v1d __v1d_div(union __v1d a, union __v1d b);
static inline union __v1f __v1f_div(union __v1f a, union __v1f b);
static inline union __v1i __v1i_div(union __v1i a, union __v1i b);
static inline union __v1l __v1l_div(union __v1l a, union __v1l b);
static inline v2d __v2d_div(v2d a, v2d b);
static inline v2f __v2f_div(v2f a, v2f b);
static inline v2i __v2i_div(v2i a, v2i b);
static inline v2l __v2l_div(v2l a, v2l b);
static inline v4d __v4d_div(v4d a, v4d b);
static inline v4f __v4f_div(v4f a, v4f b);
static inline v4i __v4i_div(v4i a, v4i b);
static inline v4l __v4l_div(v4l a, v4l b);
static inline v8d __v8d_div(v8d a, v8d b);
static inline v8f __v8f_div(v8f a, v8f b);
static inline v8i __v8i_div(v8i a, v8i b);
static inline v8l __v8l_div(v8l a, v8l b);
static inline v16f __v16f_div(v16f a, v16f b);
static inline v16i __v16i_div(v16i a, v16i b);



static inline union __v1d __v1d_sqrt(union __v1d a);
static inline union __v1f __v1f_sqrt(union __v1f a);
static inline v1i __v1i_sqrt(v1i a);
static inline v1l __v1l_sqrt(v1l a);
static inline v2d __v2d_sqrt(v2d a);
static inline v2f __v2f_sqrt(v2f a);
static inline v2i __v2i_sqrt(v2i a);
static inline v2l __v2l_sqrt(v2l a);
static inline v4d __v4d_sqrt(v4d a);
static inline v4f __v4f_sqrt(v4f a);
static inline v4i __v4i_sqrt(v4i a);
static inline v4l __v4l_sqrt(v4l a);
static inline v8d __v8d_sqrt(v8d a);
static inline v8f __v8f_sqrt(v8f a);
static inline v8i __v8i_sqrt(v8i a);
static inline v8l __v8l_sqrt(v8l a);
static inline v16f __v16f_sqrt(v16f a);
static inline v16i __v16i_sqrt(v16i a);



/* Fused Multiply-Add */




/* MERGES */

static inline struct __v2d __v2d_merge2_v1d(v1d a0, v1d a1);
static inline struct __v2f __v2f_merge2_v1f(v1f a0, v1f a1);
static inline struct __v2i __v2i_merge2_v1i(v1i a0, v1i a1);
static inline struct __v2l __v2l_merge2_v1l(v1l a0, v1l a1);
static inline struct __v4d __v4d_merge2_v2d(v2d a0, v2d a1);
static inline struct __v4f __v4f_merge2_v2f(v2f a0, v2f a1);
static inline struct __v4i __v4i_merge2_v2i(v2i a0, v2i a1);
static inline struct __v4l __v4l_merge2_v2l(v2l a0, v2l a1);
static inline struct __v8d __v8d_merge2_v4d(v4d a0, v4d a1);
static inline struct __v8f __v8f_merge2_v4f(v4f a0, v4f a1);
static inline struct __v8i __v8i_merge2_v4i(v4i a0, v4i a1);
static inline struct __v8l __v8l_merge2_v4l(v4l a0, v4l a1);
static inline struct __v16f __v16f_merge2_v8f(v8f a0, v8f a1);
static inline struct __v16i __v16i_merge2_v8i(v8i a0, v8i a1);




static inline v2d compatible_v2d_merge_v1d(v1d low, v1d high);
static inline v2f compatible_v2f_merge_v1f(v1f low, v1f high);
static inline v2i compatible_v2i_merge_v1i(v1i low, v1i high);
static inline v2l compatible_v2l_merge_v1l(v1l low, v1l high);
static inline v4d compatible_v4d_merge_v2d(v2d low, v2d high);
static inline v4f compatible_v4f_merge_v2f(v2f low, v2f high);
static inline v4i compatible_v4i_merge_v2i(v2i low, v2i high);
static inline v4l compatible_v4l_merge_v2l(v2l low, v2l high);
static inline v8d compatible_v8d_merge_v4d(v4d low, v4d high);
static inline v8f compatible_v8f_merge_v4f(v4f low, v4f high);
static inline v8i compatible_v8i_merge_v4i(v4i low, v4i high);
static inline v8l compatible_v8l_merge_v4l(v4l low, v4l high);
static inline v16f compatible_v16f_merge_v8f(v8f low, v8f high);
static inline v16i compatible_v16i_merge_v8i(v8i low, v8i high);

/* HIGH and LOW manipulation */

static inline v1d __v1d_get_high_v2d(struct __v2d a);
static inline v1f __v1f_get_high_v2f(struct __v2f a);
static inline v1i __v1i_get_high_v2i(struct __v2i a);
static inline v1l __v1l_get_high_v2l(struct __v2l a);
static inline v2d __v2d_get_high_v4d(struct __v4d a);
static inline v2f __v2f_get_high_v4f(struct __v4f a);
static inline v2i __v2i_get_high_v4i(struct __v4i a);
static inline v2l __v2l_get_high_v4l(struct __v4l a);
static inline v4d __v4d_get_high_v8d(struct __v8d a);
static inline v4f __v4f_get_high_v8f(struct __v8f a);
static inline v4i __v4i_get_high_v8i(struct __v8i a);
static inline v4l __v4l_get_high_v8l(struct __v8l a);
static inline v8f __v8f_get_high_v16f(struct __v16f a);
static inline v8i __v8i_get_high_v16i(struct __v16i a);
static inline v1d compatible_v1d_get_low_v2d(v2d a);
static inline v1f compatible_v1f_get_low_v2f(v2f a);
static inline v1i compatible_v1i_get_low_v2i(v2i a);
static inline v1l compatible_v1l_get_low_v2l(v2l a);
static inline v2d compatible_v2d_get_low_v4d(v4d a);
static inline v2f compatible_v2f_get_low_v4f(v4f a);
static inline v2i compatible_v2i_get_low_v4i(v4i a);
static inline v2l compatible_v2l_get_low_v4l(v4l a);
static inline v4d compatible_v4d_get_low_v8d(v8d a);
static inline v4f compatible_v4f_get_low_v8f(v8f a);
static inline v4i compatible_v4i_get_low_v8i(v8i a);
static inline v4l compatible_v4l_get_low_v8l(v8l a);
static inline v8f compatible_v8f_get_low_v16f(v16f a);
static inline v8i compatible_v8i_get_low_v16i(v16i a);
static inline v1d compatible_v1d_get_high_v2d(v2d a);
static inline v1f compatible_v1f_get_high_v2f(v2f a);
static inline v1i compatible_v1i_get_high_v2i(v2i a);
static inline v1l compatible_v1l_get_high_v2l(v2l a);
static inline v2d compatible_v2d_get_high_v4d(v4d a);
static inline v2f compatible_v2f_get_high_v4f(v4f a);
static inline v2i compatible_v2i_get_high_v4i(v4i a);
static inline v2l compatible_v2l_get_high_v4l(v4l a);
static inline v4d compatible_v4d_get_high_v8d(v8d a);
static inline v4f compatible_v4f_get_high_v8f(v8f a);
static inline v4i compatible_v4i_get_high_v8i(v8i a);
static inline v4l compatible_v4l_get_high_v8l(v8l a);
static inline v8f compatible_v8f_get_high_v16f(v16f a);
static inline v8i compatible_v8i_get_high_v16i(v16i a);

/* BLENDS */




/* SHUFFLES */











/* PRINTS */

static inline void __v1d_fprintf(FILE *file, v1d a, const char* format);
static inline void __v1f_fprintf(FILE *file, v1f a, const char* format);
static inline void __v1i_fprintf(FILE *file, v1i a, const char* format);
static inline void __v1l_fprintf(FILE *file, v1l a, const char* format);
static inline void __v2d_fprintf(FILE *file, v2d a, const char* format);
static inline void __v2f_fprintf(FILE *file, v2f a, const char* format);
static inline void __v2i_fprintf(FILE *file, v2i a, const char* format);
static inline void __v2l_fprintf(FILE *file, v2l a, const char* format);
static inline void __v4d_fprintf(FILE *file, v4d a, const char* format);
static inline void __v4f_fprintf(FILE *file, v4f a, const char* format);
static inline void __v4i_fprintf(FILE *file, v4i a, const char* format);
static inline void __v4l_fprintf(FILE *file, v4l a, const char* format);
static inline void __v8d_fprintf(FILE *file, v8d a, const char* format);
static inline void __v8f_fprintf(FILE *file, v8f a, const char* format);
static inline void __v8i_fprintf(FILE *file, v8i a, const char* format);
static inline void __v8l_fprintf(FILE *file, v8l a, const char* format);
static inline void __v16f_fprintf(FILE *file, v16f a, const char* format);
static inline void __v16i_fprintf(FILE *file, v16i a, const char* format);




static inline void __v1d_rfprintf(FILE *file, v1d a, const char* format);
static inline void __v1f_rfprintf(FILE *file, v1f a, const char* format);
static inline void __v1i_rfprintf(FILE *file, v1i a, const char* format);
static inline void __v1l_rfprintf(FILE *file, v1l a, const char* format);
static inline void __v2d_rfprintf(FILE *file, v2d a, const char* format);
static inline void __v2f_rfprintf(FILE *file, v2f a, const char* format);
static inline void __v2i_rfprintf(FILE *file, v2i a, const char* format);
static inline void __v2l_rfprintf(FILE *file, v2l a, const char* format);
static inline void __v4d_rfprintf(FILE *file, v4d a, const char* format);
static inline void __v4f_rfprintf(FILE *file, v4f a, const char* format);
static inline void __v4i_rfprintf(FILE *file, v4i a, const char* format);
static inline void __v4l_rfprintf(FILE *file, v4l a, const char* format);
static inline void __v8d_rfprintf(FILE *file, v8d a, const char* format);
static inline void __v8f_rfprintf(FILE *file, v8f a, const char* format);
static inline void __v8i_rfprintf(FILE *file, v8i a, const char* format);
static inline void __v8l_rfprintf(FILE *file, v8l a, const char* format);
static inline void __v16f_rfprintf(FILE *file, v16f a, const char* format);
static inline void __v16i_rfprintf(FILE *file, v16i a, const char* format);




/* CASTS */

static inline struct __v2d __v2d_cast_v1d(v1d a);
static inline struct __v2f __v2f_cast_v1f(v1f a);
static inline struct __v2i __v2i_cast_v1i(v1i a);
static inline struct __v2l __v2l_cast_v1l(v1l a);
static inline v1d __v1d_cast_v2d(struct __v2d a);
static inline struct __v4d __v4d_cast_v2d(v2d a);
static inline v1f __v1f_cast_v2f(struct __v2f a);
static inline struct __v4f __v4f_cast_v2f(v2f a);
static inline v1i __v1i_cast_v2i(struct __v2i a);
static inline struct __v4i __v4i_cast_v2i(v2i a);
static inline v1l __v1l_cast_v2l(struct __v2l a);
static inline struct __v4l __v4l_cast_v2l(v2l a);
static inline v2d __v2d_cast_v4d(struct __v4d a);
static inline struct __v8d __v8d_cast_v4d(v4d a);
static inline v2f __v2f_cast_v4f(struct __v4f a);
static inline struct __v8f __v8f_cast_v4f(v4f a);
static inline v2i __v2i_cast_v4i(struct __v4i a);
static inline struct __v8i __v8i_cast_v4i(v4i a);
static inline v2l __v2l_cast_v4l(struct __v4l a);
static inline struct __v8l __v8l_cast_v4l(v4l a);
static inline v4d __v4d_cast_v8d(struct __v8d a);
static inline v4f __v4f_cast_v8f(struct __v8f a);
static inline struct __v16f __v16f_cast_v8f(v8f a);
static inline v4i __v4i_cast_v8i(struct __v8i a);
static inline struct __v16i __v16i_cast_v8i(v8i a);
static inline v4l __v4l_cast_v8l(struct __v8l a);
static inline v8f __v8f_cast_v16f(struct __v16f a);
static inline v8i __v8i_cast_v16i(struct __v16i a);


/* CONVERTS */

static inline v1f __v1f_cvt_v1d(v1d a);
static inline v1i __v1i_cvt_v1d(v1d a);
static inline v1l __v1l_cvt_v1d(v1d a);
static inline v1d __v1d_cvt_v1f(v1f a);
static inline v1i __v1i_cvt_v1f(v1f a);
static inline v1l __v1l_cvt_v1f(v1f a);
static inline v1d __v1d_cvt_v1i(v1i a);
static inline v1f __v1f_cvt_v1i(v1i a);
static inline v1l __v1l_cvt_v1i(v1i a);
static inline v1d __v1d_cvt_v1l(v1l a);
static inline v1f __v1f_cvt_v1l(v1l a);
static inline v1i __v1i_cvt_v1l(v1l a);


static inline double __sd_cvt_v1d(v1d a);
static inline float __sf_cvt_v1f(v1f a);
static inline int32_t __si_cvt_v1i(v1i a);
static inline int64_t __sl_cvt_v1l(v1l a);




/* compatible CONVERTS */
static inline v1d compatible_v1d_cvt_v1d(v1d a);
static inline v1f compatible_v1f_cvt_v1d(v1d a);
static inline v1i compatible_v1i_cvt_v1d(v1d a);
static inline v1l compatible_v1l_cvt_v1d(v1d a);
static inline v2d compatible_v2d_cvt_v1d(v1d a);
static inline v2f compatible_v2f_cvt_v1d(v1d a);
static inline v2i compatible_v2i_cvt_v1d(v1d a);
static inline v2l compatible_v2l_cvt_v1d(v1d a);
static inline v4d compatible_v4d_cvt_v1d(v1d a);
static inline v4f compatible_v4f_cvt_v1d(v1d a);
static inline v4i compatible_v4i_cvt_v1d(v1d a);
static inline v4l compatible_v4l_cvt_v1d(v1d a);
static inline v8d compatible_v8d_cvt_v1d(v1d a);
static inline v8f compatible_v8f_cvt_v1d(v1d a);
static inline v8i compatible_v8i_cvt_v1d(v1d a);
static inline v8l compatible_v8l_cvt_v1d(v1d a);
static inline v16f compatible_v16f_cvt_v1d(v1d a);
static inline v16i compatible_v16i_cvt_v1d(v1d a);
static inline v1d compatible_v1d_cvt_v1f(v1f a);
static inline v1f compatible_v1f_cvt_v1f(v1f a);
static inline v1i compatible_v1i_cvt_v1f(v1f a);
static inline v1l compatible_v1l_cvt_v1f(v1f a);
static inline v2d compatible_v2d_cvt_v1f(v1f a);
static inline v2f compatible_v2f_cvt_v1f(v1f a);
static inline v2i compatible_v2i_cvt_v1f(v1f a);
static inline v2l compatible_v2l_cvt_v1f(v1f a);
static inline v4d compatible_v4d_cvt_v1f(v1f a);
static inline v4f compatible_v4f_cvt_v1f(v1f a);
static inline v4i compatible_v4i_cvt_v1f(v1f a);
static inline v4l compatible_v4l_cvt_v1f(v1f a);
static inline v8d compatible_v8d_cvt_v1f(v1f a);
static inline v8f compatible_v8f_cvt_v1f(v1f a);
static inline v8i compatible_v8i_cvt_v1f(v1f a);
static inline v8l compatible_v8l_cvt_v1f(v1f a);
static inline v16f compatible_v16f_cvt_v1f(v1f a);
static inline v16i compatible_v16i_cvt_v1f(v1f a);
static inline v1d compatible_v1d_cvt_v1i(v1i a);
static inline v1f compatible_v1f_cvt_v1i(v1i a);
static inline v1i compatible_v1i_cvt_v1i(v1i a);
static inline v1l compatible_v1l_cvt_v1i(v1i a);
static inline v2d compatible_v2d_cvt_v1i(v1i a);
static inline v2f compatible_v2f_cvt_v1i(v1i a);
static inline v2i compatible_v2i_cvt_v1i(v1i a);
static inline v2l compatible_v2l_cvt_v1i(v1i a);
static inline v4d compatible_v4d_cvt_v1i(v1i a);
static inline v4f compatible_v4f_cvt_v1i(v1i a);
static inline v4i compatible_v4i_cvt_v1i(v1i a);
static inline v4l compatible_v4l_cvt_v1i(v1i a);
static inline v8d compatible_v8d_cvt_v1i(v1i a);
static inline v8f compatible_v8f_cvt_v1i(v1i a);
static inline v8i compatible_v8i_cvt_v1i(v1i a);
static inline v8l compatible_v8l_cvt_v1i(v1i a);
static inline v16f compatible_v16f_cvt_v1i(v1i a);
static inline v16i compatible_v16i_cvt_v1i(v1i a);
static inline v1d compatible_v1d_cvt_v1l(v1l a);
static inline v1f compatible_v1f_cvt_v1l(v1l a);
static inline v1i compatible_v1i_cvt_v1l(v1l a);
static inline v1l compatible_v1l_cvt_v1l(v1l a);
static inline v2d compatible_v2d_cvt_v1l(v1l a);
static inline v2f compatible_v2f_cvt_v1l(v1l a);
static inline v2i compatible_v2i_cvt_v1l(v1l a);
static inline v2l compatible_v2l_cvt_v1l(v1l a);
static inline v4d compatible_v4d_cvt_v1l(v1l a);
static inline v4f compatible_v4f_cvt_v1l(v1l a);
static inline v4i compatible_v4i_cvt_v1l(v1l a);
static inline v4l compatible_v4l_cvt_v1l(v1l a);
static inline v8d compatible_v8d_cvt_v1l(v1l a);
static inline v8f compatible_v8f_cvt_v1l(v1l a);
static inline v8i compatible_v8i_cvt_v1l(v1l a);
static inline v8l compatible_v8l_cvt_v1l(v1l a);
static inline v16f compatible_v16f_cvt_v1l(v1l a);
static inline v16i compatible_v16i_cvt_v1l(v1l a);
static inline v1d compatible_v1d_cvt_v2d(v2d a);
static inline v1f compatible_v1f_cvt_v2d(v2d a);
static inline v1i compatible_v1i_cvt_v2d(v2d a);
static inline v1l compatible_v1l_cvt_v2d(v2d a);
static inline v2d compatible_v2d_cvt_v2d(v2d a);
static inline v2f compatible_v2f_cvt_v2d(v2d a);
static inline v2i compatible_v2i_cvt_v2d(v2d a);
static inline v2l compatible_v2l_cvt_v2d(v2d a);
static inline v4d compatible_v4d_cvt_v2d(v2d a);
static inline v4f compatible_v4f_cvt_v2d(v2d a);
static inline v4i compatible_v4i_cvt_v2d(v2d a);
static inline v4l compatible_v4l_cvt_v2d(v2d a);
static inline v8d compatible_v8d_cvt_v2d(v2d a);
static inline v8f compatible_v8f_cvt_v2d(v2d a);
static inline v8i compatible_v8i_cvt_v2d(v2d a);
static inline v8l compatible_v8l_cvt_v2d(v2d a);
static inline v16f compatible_v16f_cvt_v2d(v2d a);
static inline v16i compatible_v16i_cvt_v2d(v2d a);
static inline v1d compatible_v1d_cvt_v2f(v2f a);
static inline v1f compatible_v1f_cvt_v2f(v2f a);
static inline v1i compatible_v1i_cvt_v2f(v2f a);
static inline v1l compatible_v1l_cvt_v2f(v2f a);
static inline v2d compatible_v2d_cvt_v2f(v2f a);
static inline v2f compatible_v2f_cvt_v2f(v2f a);
static inline v2i compatible_v2i_cvt_v2f(v2f a);
static inline v2l compatible_v2l_cvt_v2f(v2f a);
static inline v4d compatible_v4d_cvt_v2f(v2f a);
static inline v4f compatible_v4f_cvt_v2f(v2f a);
static inline v4i compatible_v4i_cvt_v2f(v2f a);
static inline v4l compatible_v4l_cvt_v2f(v2f a);
static inline v8d compatible_v8d_cvt_v2f(v2f a);
static inline v8f compatible_v8f_cvt_v2f(v2f a);
static inline v8i compatible_v8i_cvt_v2f(v2f a);
static inline v8l compatible_v8l_cvt_v2f(v2f a);
static inline v16f compatible_v16f_cvt_v2f(v2f a);
static inline v16i compatible_v16i_cvt_v2f(v2f a);
static inline v1d compatible_v1d_cvt_v2i(v2i a);
static inline v1f compatible_v1f_cvt_v2i(v2i a);
static inline v1i compatible_v1i_cvt_v2i(v2i a);
static inline v1l compatible_v1l_cvt_v2i(v2i a);
static inline v2d compatible_v2d_cvt_v2i(v2i a);
static inline v2f compatible_v2f_cvt_v2i(v2i a);
static inline v2i compatible_v2i_cvt_v2i(v2i a);
static inline v2l compatible_v2l_cvt_v2i(v2i a);
static inline v4d compatible_v4d_cvt_v2i(v2i a);
static inline v4f compatible_v4f_cvt_v2i(v2i a);
static inline v4i compatible_v4i_cvt_v2i(v2i a);
static inline v4l compatible_v4l_cvt_v2i(v2i a);
static inline v8d compatible_v8d_cvt_v2i(v2i a);
static inline v8f compatible_v8f_cvt_v2i(v2i a);
static inline v8i compatible_v8i_cvt_v2i(v2i a);
static inline v8l compatible_v8l_cvt_v2i(v2i a);
static inline v16f compatible_v16f_cvt_v2i(v2i a);
static inline v16i compatible_v16i_cvt_v2i(v2i a);
static inline v1d compatible_v1d_cvt_v2l(v2l a);
static inline v1f compatible_v1f_cvt_v2l(v2l a);
static inline v1i compatible_v1i_cvt_v2l(v2l a);
static inline v1l compatible_v1l_cvt_v2l(v2l a);
static inline v2d compatible_v2d_cvt_v2l(v2l a);
static inline v2f compatible_v2f_cvt_v2l(v2l a);
static inline v2i compatible_v2i_cvt_v2l(v2l a);
static inline v2l compatible_v2l_cvt_v2l(v2l a);
static inline v4d compatible_v4d_cvt_v2l(v2l a);
static inline v4f compatible_v4f_cvt_v2l(v2l a);
static inline v4i compatible_v4i_cvt_v2l(v2l a);
static inline v4l compatible_v4l_cvt_v2l(v2l a);
static inline v8d compatible_v8d_cvt_v2l(v2l a);
static inline v8f compatible_v8f_cvt_v2l(v2l a);
static inline v8i compatible_v8i_cvt_v2l(v2l a);
static inline v8l compatible_v8l_cvt_v2l(v2l a);
static inline v16f compatible_v16f_cvt_v2l(v2l a);
static inline v16i compatible_v16i_cvt_v2l(v2l a);
static inline v1d compatible_v1d_cvt_v4d(v4d a);
static inline v1f compatible_v1f_cvt_v4d(v4d a);
static inline v1i compatible_v1i_cvt_v4d(v4d a);
static inline v1l compatible_v1l_cvt_v4d(v4d a);
static inline v2d compatible_v2d_cvt_v4d(v4d a);
static inline v2f compatible_v2f_cvt_v4d(v4d a);
static inline v2i compatible_v2i_cvt_v4d(v4d a);
static inline v2l compatible_v2l_cvt_v4d(v4d a);
static inline v4d compatible_v4d_cvt_v4d(v4d a);
static inline v4f compatible_v4f_cvt_v4d(v4d a);
static inline v4i compatible_v4i_cvt_v4d(v4d a);
static inline v4l compatible_v4l_cvt_v4d(v4d a);
static inline v8d compatible_v8d_cvt_v4d(v4d a);
static inline v8f compatible_v8f_cvt_v4d(v4d a);
static inline v8i compatible_v8i_cvt_v4d(v4d a);
static inline v8l compatible_v8l_cvt_v4d(v4d a);
static inline v16f compatible_v16f_cvt_v4d(v4d a);
static inline v16i compatible_v16i_cvt_v4d(v4d a);
static inline v1d compatible_v1d_cvt_v4f(v4f a);
static inline v1f compatible_v1f_cvt_v4f(v4f a);
static inline v1i compatible_v1i_cvt_v4f(v4f a);
static inline v1l compatible_v1l_cvt_v4f(v4f a);
static inline v2d compatible_v2d_cvt_v4f(v4f a);
static inline v2f compatible_v2f_cvt_v4f(v4f a);
static inline v2i compatible_v2i_cvt_v4f(v4f a);
static inline v2l compatible_v2l_cvt_v4f(v4f a);
static inline v4d compatible_v4d_cvt_v4f(v4f a);
static inline v4f compatible_v4f_cvt_v4f(v4f a);
static inline v4i compatible_v4i_cvt_v4f(v4f a);
static inline v4l compatible_v4l_cvt_v4f(v4f a);
static inline v8d compatible_v8d_cvt_v4f(v4f a);
static inline v8f compatible_v8f_cvt_v4f(v4f a);
static inline v8i compatible_v8i_cvt_v4f(v4f a);
static inline v8l compatible_v8l_cvt_v4f(v4f a);
static inline v16f compatible_v16f_cvt_v4f(v4f a);
static inline v16i compatible_v16i_cvt_v4f(v4f a);
static inline v1d compatible_v1d_cvt_v4i(v4i a);
static inline v1f compatible_v1f_cvt_v4i(v4i a);
static inline v1i compatible_v1i_cvt_v4i(v4i a);
static inline v1l compatible_v1l_cvt_v4i(v4i a);
static inline v2d compatible_v2d_cvt_v4i(v4i a);
static inline v2f compatible_v2f_cvt_v4i(v4i a);
static inline v2i compatible_v2i_cvt_v4i(v4i a);
static inline v2l compatible_v2l_cvt_v4i(v4i a);
static inline v4d compatible_v4d_cvt_v4i(v4i a);
static inline v4f compatible_v4f_cvt_v4i(v4i a);
static inline v4i compatible_v4i_cvt_v4i(v4i a);
static inline v4l compatible_v4l_cvt_v4i(v4i a);
static inline v8d compatible_v8d_cvt_v4i(v4i a);
static inline v8f compatible_v8f_cvt_v4i(v4i a);
static inline v8i compatible_v8i_cvt_v4i(v4i a);
static inline v8l compatible_v8l_cvt_v4i(v4i a);
static inline v16f compatible_v16f_cvt_v4i(v4i a);
static inline v16i compatible_v16i_cvt_v4i(v4i a);
static inline v1d compatible_v1d_cvt_v4l(v4l a);
static inline v1f compatible_v1f_cvt_v4l(v4l a);
static inline v1i compatible_v1i_cvt_v4l(v4l a);
static inline v1l compatible_v1l_cvt_v4l(v4l a);
static inline v2d compatible_v2d_cvt_v4l(v4l a);
static inline v2f compatible_v2f_cvt_v4l(v4l a);
static inline v2i compatible_v2i_cvt_v4l(v4l a);
static inline v2l compatible_v2l_cvt_v4l(v4l a);
static inline v4d compatible_v4d_cvt_v4l(v4l a);
static inline v4f compatible_v4f_cvt_v4l(v4l a);
static inline v4i compatible_v4i_cvt_v4l(v4l a);
static inline v4l compatible_v4l_cvt_v4l(v4l a);
static inline v8d compatible_v8d_cvt_v4l(v4l a);
static inline v8f compatible_v8f_cvt_v4l(v4l a);
static inline v8i compatible_v8i_cvt_v4l(v4l a);
static inline v8l compatible_v8l_cvt_v4l(v4l a);
static inline v16f compatible_v16f_cvt_v4l(v4l a);
static inline v16i compatible_v16i_cvt_v4l(v4l a);
static inline v1d compatible_v1d_cvt_v8d(v8d a);
static inline v1f compatible_v1f_cvt_v8d(v8d a);
static inline v1i compatible_v1i_cvt_v8d(v8d a);
static inline v1l compatible_v1l_cvt_v8d(v8d a);
static inline v2d compatible_v2d_cvt_v8d(v8d a);
static inline v2f compatible_v2f_cvt_v8d(v8d a);
static inline v2i compatible_v2i_cvt_v8d(v8d a);
static inline v2l compatible_v2l_cvt_v8d(v8d a);
static inline v4d compatible_v4d_cvt_v8d(v8d a);
static inline v4f compatible_v4f_cvt_v8d(v8d a);
static inline v4i compatible_v4i_cvt_v8d(v8d a);
static inline v4l compatible_v4l_cvt_v8d(v8d a);
static inline v8d compatible_v8d_cvt_v8d(v8d a);
static inline v8f compatible_v8f_cvt_v8d(v8d a);
static inline v8i compatible_v8i_cvt_v8d(v8d a);
static inline v8l compatible_v8l_cvt_v8d(v8d a);
static inline v16f compatible_v16f_cvt_v8d(v8d a);
static inline v16i compatible_v16i_cvt_v8d(v8d a);
static inline v1d compatible_v1d_cvt_v8f(v8f a);
static inline v1f compatible_v1f_cvt_v8f(v8f a);
static inline v1i compatible_v1i_cvt_v8f(v8f a);
static inline v1l compatible_v1l_cvt_v8f(v8f a);
static inline v2d compatible_v2d_cvt_v8f(v8f a);
static inline v2f compatible_v2f_cvt_v8f(v8f a);
static inline v2i compatible_v2i_cvt_v8f(v8f a);
static inline v2l compatible_v2l_cvt_v8f(v8f a);
static inline v4d compatible_v4d_cvt_v8f(v8f a);
static inline v4f compatible_v4f_cvt_v8f(v8f a);
static inline v4i compatible_v4i_cvt_v8f(v8f a);
static inline v4l compatible_v4l_cvt_v8f(v8f a);
static inline v8d compatible_v8d_cvt_v8f(v8f a);
static inline v8f compatible_v8f_cvt_v8f(v8f a);
static inline v8i compatible_v8i_cvt_v8f(v8f a);
static inline v8l compatible_v8l_cvt_v8f(v8f a);
static inline v16f compatible_v16f_cvt_v8f(v8f a);
static inline v16i compatible_v16i_cvt_v8f(v8f a);
static inline v1d compatible_v1d_cvt_v8i(v8i a);
static inline v1f compatible_v1f_cvt_v8i(v8i a);
static inline v1i compatible_v1i_cvt_v8i(v8i a);
static inline v1l compatible_v1l_cvt_v8i(v8i a);
static inline v2d compatible_v2d_cvt_v8i(v8i a);
static inline v2f compatible_v2f_cvt_v8i(v8i a);
static inline v2i compatible_v2i_cvt_v8i(v8i a);
static inline v2l compatible_v2l_cvt_v8i(v8i a);
static inline v4d compatible_v4d_cvt_v8i(v8i a);
static inline v4f compatible_v4f_cvt_v8i(v8i a);
static inline v4i compatible_v4i_cvt_v8i(v8i a);
static inline v4l compatible_v4l_cvt_v8i(v8i a);
static inline v8d compatible_v8d_cvt_v8i(v8i a);
static inline v8f compatible_v8f_cvt_v8i(v8i a);
static inline v8i compatible_v8i_cvt_v8i(v8i a);
static inline v8l compatible_v8l_cvt_v8i(v8i a);
static inline v16f compatible_v16f_cvt_v8i(v8i a);
static inline v16i compatible_v16i_cvt_v8i(v8i a);
static inline v1d compatible_v1d_cvt_v8l(v8l a);
static inline v1f compatible_v1f_cvt_v8l(v8l a);
static inline v1i compatible_v1i_cvt_v8l(v8l a);
static inline v1l compatible_v1l_cvt_v8l(v8l a);
static inline v2d compatible_v2d_cvt_v8l(v8l a);
static inline v2f compatible_v2f_cvt_v8l(v8l a);
static inline v2i compatible_v2i_cvt_v8l(v8l a);
static inline v2l compatible_v2l_cvt_v8l(v8l a);
static inline v4d compatible_v4d_cvt_v8l(v8l a);
static inline v4f compatible_v4f_cvt_v8l(v8l a);
static inline v4i compatible_v4i_cvt_v8l(v8l a);
static inline v4l compatible_v4l_cvt_v8l(v8l a);
static inline v8d compatible_v8d_cvt_v8l(v8l a);
static inline v8f compatible_v8f_cvt_v8l(v8l a);
static inline v8i compatible_v8i_cvt_v8l(v8l a);
static inline v8l compatible_v8l_cvt_v8l(v8l a);
static inline v16f compatible_v16f_cvt_v8l(v8l a);
static inline v16i compatible_v16i_cvt_v8l(v8l a);
static inline v1d compatible_v1d_cvt_v16f(v16f a);
static inline v1f compatible_v1f_cvt_v16f(v16f a);
static inline v1i compatible_v1i_cvt_v16f(v16f a);
static inline v1l compatible_v1l_cvt_v16f(v16f a);
static inline v2d compatible_v2d_cvt_v16f(v16f a);
static inline v2f compatible_v2f_cvt_v16f(v16f a);
static inline v2i compatible_v2i_cvt_v16f(v16f a);
static inline v2l compatible_v2l_cvt_v16f(v16f a);
static inline v4d compatible_v4d_cvt_v16f(v16f a);
static inline v4f compatible_v4f_cvt_v16f(v16f a);
static inline v4i compatible_v4i_cvt_v16f(v16f a);
static inline v4l compatible_v4l_cvt_v16f(v16f a);
static inline v8d compatible_v8d_cvt_v16f(v16f a);
static inline v8f compatible_v8f_cvt_v16f(v16f a);
static inline v8i compatible_v8i_cvt_v16f(v16f a);
static inline v8l compatible_v8l_cvt_v16f(v16f a);
static inline v16f compatible_v16f_cvt_v16f(v16f a);
static inline v16i compatible_v16i_cvt_v16f(v16f a);
static inline v1d compatible_v1d_cvt_v16i(v16i a);
static inline v1f compatible_v1f_cvt_v16i(v16i a);
static inline v1i compatible_v1i_cvt_v16i(v16i a);
static inline v1l compatible_v1l_cvt_v16i(v16i a);
static inline v2d compatible_v2d_cvt_v16i(v16i a);
static inline v2f compatible_v2f_cvt_v16i(v16i a);
static inline v2i compatible_v2i_cvt_v16i(v16i a);
static inline v2l compatible_v2l_cvt_v16i(v16i a);
static inline v4d compatible_v4d_cvt_v16i(v16i a);
static inline v4f compatible_v4f_cvt_v16i(v16i a);
static inline v4i compatible_v4i_cvt_v16i(v16i a);
static inline v4l compatible_v4l_cvt_v16i(v16i a);
static inline v8d compatible_v8d_cvt_v16i(v16i a);
static inline v8f compatible_v8f_cvt_v16i(v16i a);
static inline v8i compatible_v8i_cvt_v16i(v16i a);
static inline v8l compatible_v8l_cvt_v16i(v16i a);
static inline v16f compatible_v16f_cvt_v16i(v16i a);
static inline v16i compatible_v16i_cvt_v16i(v16i a);

////////////////////////////////////////////////////////////////////////////////
// Implementations
////////////////////////////////////////////////////////////////////////////////
/* LOADS */

static inline union __v1d __v1d_load(const double *p) { union __v1d r = { .v = *p }; return r; }
static inline union __v1f __v1f_load(const float *p) { union __v1f r = { .v = *p }; return r; }
static inline union __v1i __v1i_load(const int32_t *p) { union __v1i r = { .v = *p }; return r; }
static inline union __v1l __v1l_load(const int64_t *p) { union __v1l r = { .v = *p }; return r; }
static inline v2d __v2d_load(const double *p) { return v2d_merge2_v1d(v1d_load(p), v1d_load(p+1)); }
static inline v2f __v2f_load(const float *p) { return v2f_merge2_v1f(v1f_load(p), v1f_load(p+1)); }
static inline v2i __v2i_load(const int32_t *p) { return v2i_merge2_v1i(v1i_load(p), v1i_load(p+1)); }
static inline v2l __v2l_load(const int64_t *p) { return v2l_merge2_v1l(v1l_load(p), v1l_load(p+1)); }
static inline v4d __v4d_load(const double *p) { return v4d_merge2_v2d(v2d_load(p), v2d_load(p+2)); }
static inline v4f __v4f_load(const float *p) { return v4f_merge2_v2f(v2f_load(p), v2f_load(p+2)); }
static inline v4i __v4i_load(const int32_t *p) { return v4i_merge2_v2i(v2i_load(p), v2i_load(p+2)); }
static inline v4l __v4l_load(const int64_t *p) { return v4l_merge2_v2l(v2l_load(p), v2l_load(p+2)); }
static inline v8d __v8d_load(const double *p) { return v8d_merge2_v4d(v4d_load(p), v4d_load(p+4)); }
static inline v8f __v8f_load(const float *p) { return v8f_merge2_v4f(v4f_load(p), v4f_load(p+4)); }
static inline v8i __v8i_load(const int32_t *p) { return v8i_merge2_v4i(v4i_load(p), v4i_load(p+4)); }
static inline v8l __v8l_load(const int64_t *p) { return v8l_merge2_v4l(v4l_load(p), v4l_load(p+4)); }
static inline v16f __v16f_load(const float *p) { return v16f_merge2_v8f(v8f_load(p), v8f_load(p+8)); }
static inline v16i __v16i_load(const int32_t *p) { return v16i_merge2_v8i(v8i_load(p), v8i_load(p+8)); }

static inline v2d __v2d_loadu(const double *p) { return v2d_merge2_v1d(v1d_loadu(p), v1d_loadu(p+1)); }
static inline v2f __v2f_loadu(const float *p) { return v2f_merge2_v1f(v1f_loadu(p), v1f_loadu(p+1)); }
static inline v2i __v2i_loadu(const int32_t *p) { return v2i_merge2_v1i(v1i_loadu(p), v1i_loadu(p+1)); }
static inline v2l __v2l_loadu(const int64_t *p) { return v2l_merge2_v1l(v1l_loadu(p), v1l_loadu(p+1)); }
static inline v4d __v4d_loadu(const double *p) { return v4d_merge2_v2d(v2d_loadu(p), v2d_loadu(p+2)); }
static inline v4f __v4f_loadu(const float *p) { return v4f_merge2_v2f(v2f_loadu(p), v2f_loadu(p+2)); }
static inline v4i __v4i_loadu(const int32_t *p) { return v4i_merge2_v2i(v2i_loadu(p), v2i_loadu(p+2)); }
static inline v4l __v4l_loadu(const int64_t *p) { return v4l_merge2_v2l(v2l_loadu(p), v2l_loadu(p+2)); }
static inline v8d __v8d_loadu(const double *p) { return v8d_merge2_v4d(v4d_loadu(p), v4d_loadu(p+4)); }
static inline v8f __v8f_loadu(const float *p) { return v8f_merge2_v4f(v4f_loadu(p), v4f_loadu(p+4)); }
static inline v8i __v8i_loadu(const int32_t *p) { return v8i_merge2_v4i(v4i_loadu(p), v4i_loadu(p+4)); }
static inline v8l __v8l_loadu(const int64_t *p) { return v8l_merge2_v4l(v4l_loadu(p), v4l_loadu(p+4)); }
static inline v16f __v16f_loadu(const float *p) { return v16f_merge2_v8f(v8f_loadu(p), v8f_loadu(p+8)); }
static inline v16i __v16i_loadu(const int32_t *p) { return v16i_merge2_v8i(v8i_loadu(p), v8i_loadu(p+8)); }

static inline v2d __v2d_load1(const double *p) { v1d a = v1d_load1(p); return v2d_merge2_v1d(a, a); }
static inline v2f __v2f_load1(const float *p) { v1f a = v1f_load1(p); return v2f_merge2_v1f(a, a); }
static inline v2i __v2i_load1(const int32_t *p) { v1i a = v1i_load1(p); return v2i_merge2_v1i(a, a); }
static inline v2l __v2l_load1(const int64_t *p) { v1l a = v1l_load1(p); return v2l_merge2_v1l(a, a); }
static inline v4d __v4d_load1(const double *p) { v2d a = v2d_load1(p); return v4d_merge2_v2d(a, a); }
static inline v4f __v4f_load1(const float *p) { v2f a = v2f_load1(p); return v4f_merge2_v2f(a, a); }
static inline v4i __v4i_load1(const int32_t *p) { v2i a = v2i_load1(p); return v4i_merge2_v2i(a, a); }
static inline v4l __v4l_load1(const int64_t *p) { v2l a = v2l_load1(p); return v4l_merge2_v2l(a, a); }
static inline v8d __v8d_load1(const double *p) { v4d a = v4d_load1(p); return v8d_merge2_v4d(a, a); }
static inline v8f __v8f_load1(const float *p) { v4f a = v4f_load1(p); return v8f_merge2_v4f(a, a); }
static inline v8i __v8i_load1(const int32_t *p) { v4i a = v4i_load1(p); return v8i_merge2_v4i(a, a); }
static inline v8l __v8l_load1(const int64_t *p) { v4l a = v4l_load1(p); return v8l_merge2_v4l(a, a); }
static inline v16f __v16f_load1(const float *p) { v8f a = v8f_load1(p); return v16f_merge2_v8f(a, a); }
static inline v16i __v16i_load1(const int32_t *p) { v8i a = v8i_load1(p); return v16i_merge2_v8i(a, a); }

static inline v1d compatible_v1d_loadu(const double *p) {
  int i;
  PINTS_ALIGNED_ARRAY(double, v, 1, 1*sizeof(double));
  for (i = 0; i < 1; ++i) v[i] = p[i];
  return v1d_load(v);
}
static inline v1f compatible_v1f_loadu(const float *p) {
  int i;
  PINTS_ALIGNED_ARRAY(float, v, 1, 1*sizeof(float));
  for (i = 0; i < 1; ++i) v[i] = p[i];
  return v1f_load(v);
}
static inline v1i compatible_v1i_loadu(const int32_t *p) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, v, 1, 1*sizeof(int32_t));
  for (i = 0; i < 1; ++i) v[i] = p[i];
  return v1i_load(v);
}
static inline v1l compatible_v1l_loadu(const int64_t *p) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, v, 1, 1*sizeof(int64_t));
  for (i = 0; i < 1; ++i) v[i] = p[i];
  return v1l_load(v);
}
static inline v2d compatible_v2d_loadu(const double *p) {
  int i;
  PINTS_ALIGNED_ARRAY(double, v, 2, 2*sizeof(double));
  for (i = 0; i < 2; ++i) v[i] = p[i];
  return v2d_load(v);
}
static inline v2f compatible_v2f_loadu(const float *p) {
  int i;
  PINTS_ALIGNED_ARRAY(float, v, 2, 2*sizeof(float));
  for (i = 0; i < 2; ++i) v[i] = p[i];
  return v2f_load(v);
}
static inline v2i compatible_v2i_loadu(const int32_t *p) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, v, 2, 2*sizeof(int32_t));
  for (i = 0; i < 2; ++i) v[i] = p[i];
  return v2i_load(v);
}
static inline v2l compatible_v2l_loadu(const int64_t *p) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, v, 2, 2*sizeof(int64_t));
  for (i = 0; i < 2; ++i) v[i] = p[i];
  return v2l_load(v);
}
static inline v4d compatible_v4d_loadu(const double *p) {
  int i;
  PINTS_ALIGNED_ARRAY(double, v, 4, 4*sizeof(double));
  for (i = 0; i < 4; ++i) v[i] = p[i];
  return v4d_load(v);
}
static inline v4f compatible_v4f_loadu(const float *p) {
  int i;
  PINTS_ALIGNED_ARRAY(float, v, 4, 4*sizeof(float));
  for (i = 0; i < 4; ++i) v[i] = p[i];
  return v4f_load(v);
}
static inline v4i compatible_v4i_loadu(const int32_t *p) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, v, 4, 4*sizeof(int32_t));
  for (i = 0; i < 4; ++i) v[i] = p[i];
  return v4i_load(v);
}
static inline v4l compatible_v4l_loadu(const int64_t *p) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, v, 4, 4*sizeof(int64_t));
  for (i = 0; i < 4; ++i) v[i] = p[i];
  return v4l_load(v);
}
static inline v8d compatible_v8d_loadu(const double *p) {
  int i;
  PINTS_ALIGNED_ARRAY(double, v, 8, 8*sizeof(double));
  for (i = 0; i < 8; ++i) v[i] = p[i];
  return v8d_load(v);
}
static inline v8f compatible_v8f_loadu(const float *p) {
  int i;
  PINTS_ALIGNED_ARRAY(float, v, 8, 8*sizeof(float));
  for (i = 0; i < 8; ++i) v[i] = p[i];
  return v8f_load(v);
}
static inline v8i compatible_v8i_loadu(const int32_t *p) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, v, 8, 8*sizeof(int32_t));
  for (i = 0; i < 8; ++i) v[i] = p[i];
  return v8i_load(v);
}
static inline v8l compatible_v8l_loadu(const int64_t *p) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, v, 8, 8*sizeof(int64_t));
  for (i = 0; i < 8; ++i) v[i] = p[i];
  return v8l_load(v);
}
static inline v16f compatible_v16f_loadu(const float *p) {
  int i;
  PINTS_ALIGNED_ARRAY(float, v, 16, 16*sizeof(float));
  for (i = 0; i < 16; ++i) v[i] = p[i];
  return v16f_load(v);
}
static inline v16i compatible_v16i_loadu(const int32_t *p) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, v, 16, 16*sizeof(int32_t));
  for (i = 0; i < 16; ++i) v[i] = p[i];
  return v16i_load(v);
}

/* STORES */

static inline void __v1d_store(double *p, union __v1d a) { *p = a.v; }
static inline void __v1f_store(float *p, union __v1f a) { *p = a.v; }
static inline void __v1i_store(int32_t *p, union __v1i a) { *p = a.v; }
static inline void __v1l_store(int64_t *p, union __v1l a) { *p = a.v; }
static inline void __v2d_store(double *p, v2d a) { v1d_store(p, v1d_get_low_v2d(a)); v1d_store(p+1, v1d_get_high_v2d(a)); }
static inline void __v2f_store(float *p, v2f a) { v1f_store(p, v1f_get_low_v2f(a)); v1f_store(p+1, v1f_get_high_v2f(a)); }
static inline void __v2i_store(int32_t *p, v2i a) { v1i_store(p, v1i_get_low_v2i(a)); v1i_store(p+1, v1i_get_high_v2i(a)); }
static inline void __v2l_store(int64_t *p, v2l a) { v1l_store(p, v1l_get_low_v2l(a)); v1l_store(p+1, v1l_get_high_v2l(a)); }
static inline void __v4d_store(double *p, v4d a) { v2d_store(p, v2d_get_low_v4d(a)); v2d_store(p+2, v2d_get_high_v4d(a)); }
static inline void __v4f_store(float *p, v4f a) { v2f_store(p, v2f_get_low_v4f(a)); v2f_store(p+2, v2f_get_high_v4f(a)); }
static inline void __v4i_store(int32_t *p, v4i a) { v2i_store(p, v2i_get_low_v4i(a)); v2i_store(p+2, v2i_get_high_v4i(a)); }
static inline void __v4l_store(int64_t *p, v4l a) { v2l_store(p, v2l_get_low_v4l(a)); v2l_store(p+2, v2l_get_high_v4l(a)); }
static inline void __v8d_store(double *p, v8d a) { v4d_store(p, v4d_get_low_v8d(a)); v4d_store(p+4, v4d_get_high_v8d(a)); }
static inline void __v8f_store(float *p, v8f a) { v4f_store(p, v4f_get_low_v8f(a)); v4f_store(p+4, v4f_get_high_v8f(a)); }
static inline void __v8i_store(int32_t *p, v8i a) { v4i_store(p, v4i_get_low_v8i(a)); v4i_store(p+4, v4i_get_high_v8i(a)); }
static inline void __v8l_store(int64_t *p, v8l a) { v4l_store(p, v4l_get_low_v8l(a)); v4l_store(p+4, v4l_get_high_v8l(a)); }
static inline void __v16f_store(float *p, v16f a) { v8f_store(p, v8f_get_low_v16f(a)); v8f_store(p+8, v8f_get_high_v16f(a)); }
static inline void __v16i_store(int32_t *p, v16i a) { v8i_store(p, v8i_get_low_v16i(a)); v8i_store(p+8, v8i_get_high_v16i(a)); }

static inline void __v2d_storeu(double *p, v2d a) { v1d_storeu(p, v1d_get_low_v2d(a)); v1d_storeu(p+1, v1d_get_high_v2d(a)); }
static inline void __v2f_storeu(float *p, v2f a) { v1f_storeu(p, v1f_get_low_v2f(a)); v1f_storeu(p+1, v1f_get_high_v2f(a)); }
static inline void __v2i_storeu(int32_t *p, v2i a) { v1i_storeu(p, v1i_get_low_v2i(a)); v1i_storeu(p+1, v1i_get_high_v2i(a)); }
static inline void __v2l_storeu(int64_t *p, v2l a) { v1l_storeu(p, v1l_get_low_v2l(a)); v1l_storeu(p+1, v1l_get_high_v2l(a)); }
static inline void __v4d_storeu(double *p, v4d a) { v2d_storeu(p, v2d_get_low_v4d(a)); v2d_storeu(p+2, v2d_get_high_v4d(a)); }
static inline void __v4f_storeu(float *p, v4f a) { v2f_storeu(p, v2f_get_low_v4f(a)); v2f_storeu(p+2, v2f_get_high_v4f(a)); }
static inline void __v4i_storeu(int32_t *p, v4i a) { v2i_storeu(p, v2i_get_low_v4i(a)); v2i_storeu(p+2, v2i_get_high_v4i(a)); }
static inline void __v4l_storeu(int64_t *p, v4l a) { v2l_storeu(p, v2l_get_low_v4l(a)); v2l_storeu(p+2, v2l_get_high_v4l(a)); }
static inline void __v8d_storeu(double *p, v8d a) { v4d_storeu(p, v4d_get_low_v8d(a)); v4d_storeu(p+4, v4d_get_high_v8d(a)); }
static inline void __v8f_storeu(float *p, v8f a) { v4f_storeu(p, v4f_get_low_v8f(a)); v4f_storeu(p+4, v4f_get_high_v8f(a)); }
static inline void __v8i_storeu(int32_t *p, v8i a) { v4i_storeu(p, v4i_get_low_v8i(a)); v4i_storeu(p+4, v4i_get_high_v8i(a)); }
static inline void __v8l_storeu(int64_t *p, v8l a) { v4l_storeu(p, v4l_get_low_v8l(a)); v4l_storeu(p+4, v4l_get_high_v8l(a)); }
static inline void __v16f_storeu(float *p, v16f a) { v8f_storeu(p, v8f_get_low_v16f(a)); v8f_storeu(p+8, v8f_get_high_v16f(a)); }
static inline void __v16i_storeu(int32_t *p, v16i a) { v8i_storeu(p, v8i_get_low_v16i(a)); v8i_storeu(p+8, v8i_get_high_v16i(a)); }


static inline void compatible_v1d_storeu(double *p, v1d a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, v, 1, 1*sizeof(double));
  v1d_store(v, a);
  for (i = 0; i < 1; ++i) p[i] = v[i];
}
static inline void compatible_v1f_storeu(float *p, v1f a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, v, 1, 1*sizeof(float));
  v1f_store(v, a);
  for (i = 0; i < 1; ++i) p[i] = v[i];
}
static inline void compatible_v1i_storeu(int32_t *p, v1i a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, v, 1, 1*sizeof(int32_t));
  v1i_store(v, a);
  for (i = 0; i < 1; ++i) p[i] = v[i];
}
static inline void compatible_v1l_storeu(int64_t *p, v1l a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, v, 1, 1*sizeof(int64_t));
  v1l_store(v, a);
  for (i = 0; i < 1; ++i) p[i] = v[i];
}
static inline void compatible_v2d_storeu(double *p, v2d a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, v, 2, 2*sizeof(double));
  v2d_store(v, a);
  for (i = 0; i < 2; ++i) p[i] = v[i];
}
static inline void compatible_v2f_storeu(float *p, v2f a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, v, 2, 2*sizeof(float));
  v2f_store(v, a);
  for (i = 0; i < 2; ++i) p[i] = v[i];
}
static inline void compatible_v2i_storeu(int32_t *p, v2i a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, v, 2, 2*sizeof(int32_t));
  v2i_store(v, a);
  for (i = 0; i < 2; ++i) p[i] = v[i];
}
static inline void compatible_v2l_storeu(int64_t *p, v2l a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, v, 2, 2*sizeof(int64_t));
  v2l_store(v, a);
  for (i = 0; i < 2; ++i) p[i] = v[i];
}
static inline void compatible_v4d_storeu(double *p, v4d a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, v, 4, 4*sizeof(double));
  v4d_store(v, a);
  for (i = 0; i < 4; ++i) p[i] = v[i];
}
static inline void compatible_v4f_storeu(float *p, v4f a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, v, 4, 4*sizeof(float));
  v4f_store(v, a);
  for (i = 0; i < 4; ++i) p[i] = v[i];
}
static inline void compatible_v4i_storeu(int32_t *p, v4i a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, v, 4, 4*sizeof(int32_t));
  v4i_store(v, a);
  for (i = 0; i < 4; ++i) p[i] = v[i];
}
static inline void compatible_v4l_storeu(int64_t *p, v4l a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, v, 4, 4*sizeof(int64_t));
  v4l_store(v, a);
  for (i = 0; i < 4; ++i) p[i] = v[i];
}
static inline void compatible_v8d_storeu(double *p, v8d a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, v, 8, 8*sizeof(double));
  v8d_store(v, a);
  for (i = 0; i < 8; ++i) p[i] = v[i];
}
static inline void compatible_v8f_storeu(float *p, v8f a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, v, 8, 8*sizeof(float));
  v8f_store(v, a);
  for (i = 0; i < 8; ++i) p[i] = v[i];
}
static inline void compatible_v8i_storeu(int32_t *p, v8i a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, v, 8, 8*sizeof(int32_t));
  v8i_store(v, a);
  for (i = 0; i < 8; ++i) p[i] = v[i];
}
static inline void compatible_v8l_storeu(int64_t *p, v8l a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, v, 8, 8*sizeof(int64_t));
  v8l_store(v, a);
  for (i = 0; i < 8; ++i) p[i] = v[i];
}
static inline void compatible_v16f_storeu(float *p, v16f a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, v, 16, 16*sizeof(float));
  v16f_store(v, a);
  for (i = 0; i < 16; ++i) p[i] = v[i];
}
static inline void compatible_v16i_storeu(int32_t *p, v16i a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, v, 16, 16*sizeof(int32_t));
  v16i_store(v, a);
  for (i = 0; i < 16; ++i) p[i] = v[i];
}

/* SETS */

static inline v1d __v1d_set(double v0) { return v1d_load(&v0); }
static inline v1f __v1f_set(float v0) { return v1f_load(&v0); }
static inline v1i __v1i_set(int32_t v0) { return v1i_load(&v0); }
static inline v1l __v1l_set(int64_t v0) { return v1l_load(&v0); }


static inline v2d __v2d_set1(double v) { v1d a = v1d_set1(v); return v2d_merge2_v1d(a, a); }
static inline v2f __v2f_set1(float v) { v1f a = v1f_set1(v); return v2f_merge2_v1f(a, a); }
static inline v2i __v2i_set1(int32_t v) { v1i a = v1i_set1(v); return v2i_merge2_v1i(a, a); }
static inline v2l __v2l_set1(int64_t v) { v1l a = v1l_set1(v); return v2l_merge2_v1l(a, a); }
static inline v4d __v4d_set1(double v) { v2d a = v2d_set1(v); return v4d_merge2_v2d(a, a); }
static inline v4f __v4f_set1(float v) { v2f a = v2f_set1(v); return v4f_merge2_v2f(a, a); }
static inline v4i __v4i_set1(int32_t v) { v2i a = v2i_set1(v); return v4i_merge2_v2i(a, a); }
static inline v4l __v4l_set1(int64_t v) { v2l a = v2l_set1(v); return v4l_merge2_v2l(a, a); }
static inline v8d __v8d_set1(double v) { v4d a = v4d_set1(v); return v8d_merge2_v4d(a, a); }
static inline v8f __v8f_set1(float v) { v4f a = v4f_set1(v); return v8f_merge2_v4f(a, a); }
static inline v8i __v8i_set1(int32_t v) { v4i a = v4i_set1(v); return v8i_merge2_v4i(a, a); }
static inline v8l __v8l_set1(int64_t v) { v4l a = v4l_set1(v); return v8l_merge2_v4l(a, a); }
static inline v16f __v16f_set1(float v) { v8f a = v8f_set1(v); return v16f_merge2_v8f(a, a); }
static inline v16i __v16i_set1(int32_t v) { v8i a = v8i_set1(v); return v16i_merge2_v8i(a, a); }

/* CONSTANTS */


/* COMPARISONS */

static inline union __v1d __v1d_eq(union __v1d a, union __v1d b) { union __v1d r = { .i = -(a.v == b.v) }; return r; }
static inline union __v1f __v1f_eq(union __v1f a, union __v1f b) { union __v1f r = { .i = -(a.v == b.v) }; return r; }
static inline union __v1i __v1i_eq(union __v1i a, union __v1i b) { union __v1i r = { .i = -(a.v == b.v) }; return r; }
static inline union __v1l __v1l_eq(union __v1l a, union __v1l b) { union __v1l r = { .i = -(a.v == b.v) }; return r; }
static inline v2d __v2d_eq(v2d a, v2d b) { return v2d_merge2_v1d(v1d_eq(v1d_get_low_v2d(a), v1d_get_low_v2d(b)), v1d_eq(v1d_get_high_v2d(a), v1d_get_high_v2d(b))); }
static inline v2f __v2f_eq(v2f a, v2f b) { return v2f_merge2_v1f(v1f_eq(v1f_get_low_v2f(a), v1f_get_low_v2f(b)), v1f_eq(v1f_get_high_v2f(a), v1f_get_high_v2f(b))); }
static inline v2i __v2i_eq(v2i a, v2i b) { return v2i_merge2_v1i(v1i_eq(v1i_get_low_v2i(a), v1i_get_low_v2i(b)), v1i_eq(v1i_get_high_v2i(a), v1i_get_high_v2i(b))); }
static inline v2l __v2l_eq(v2l a, v2l b) { return v2l_merge2_v1l(v1l_eq(v1l_get_low_v2l(a), v1l_get_low_v2l(b)), v1l_eq(v1l_get_high_v2l(a), v1l_get_high_v2l(b))); }
static inline v4d __v4d_eq(v4d a, v4d b) { return v4d_merge2_v2d(v2d_eq(v2d_get_low_v4d(a), v2d_get_low_v4d(b)), v2d_eq(v2d_get_high_v4d(a), v2d_get_high_v4d(b))); }
static inline v4f __v4f_eq(v4f a, v4f b) { return v4f_merge2_v2f(v2f_eq(v2f_get_low_v4f(a), v2f_get_low_v4f(b)), v2f_eq(v2f_get_high_v4f(a), v2f_get_high_v4f(b))); }
static inline v4i __v4i_eq(v4i a, v4i b) { return v4i_merge2_v2i(v2i_eq(v2i_get_low_v4i(a), v2i_get_low_v4i(b)), v2i_eq(v2i_get_high_v4i(a), v2i_get_high_v4i(b))); }
static inline v4l __v4l_eq(v4l a, v4l b) { return v4l_merge2_v2l(v2l_eq(v2l_get_low_v4l(a), v2l_get_low_v4l(b)), v2l_eq(v2l_get_high_v4l(a), v2l_get_high_v4l(b))); }
static inline v8d __v8d_eq(v8d a, v8d b) { return v8d_merge2_v4d(v4d_eq(v4d_get_low_v8d(a), v4d_get_low_v8d(b)), v4d_eq(v4d_get_high_v8d(a), v4d_get_high_v8d(b))); }
static inline v8f __v8f_eq(v8f a, v8f b) { return v8f_merge2_v4f(v4f_eq(v4f_get_low_v8f(a), v4f_get_low_v8f(b)), v4f_eq(v4f_get_high_v8f(a), v4f_get_high_v8f(b))); }
static inline v8i __v8i_eq(v8i a, v8i b) { return v8i_merge2_v4i(v4i_eq(v4i_get_low_v8i(a), v4i_get_low_v8i(b)), v4i_eq(v4i_get_high_v8i(a), v4i_get_high_v8i(b))); }
static inline v8l __v8l_eq(v8l a, v8l b) { return v8l_merge2_v4l(v4l_eq(v4l_get_low_v8l(a), v4l_get_low_v8l(b)), v4l_eq(v4l_get_high_v8l(a), v4l_get_high_v8l(b))); }
static inline v16f __v16f_eq(v16f a, v16f b) { return v16f_merge2_v8f(v8f_eq(v8f_get_low_v16f(a), v8f_get_low_v16f(b)), v8f_eq(v8f_get_high_v16f(a), v8f_get_high_v16f(b))); }
static inline v16i __v16i_eq(v16i a, v16i b) { return v16i_merge2_v8i(v8i_eq(v8i_get_low_v16i(a), v8i_get_low_v16i(b)), v8i_eq(v8i_get_high_v16i(a), v8i_get_high_v16i(b))); }

static inline union __v1d __v1d_neq(union __v1d a, union __v1d b) { union __v1d r = { .i = -(a.v != b.v) }; return r; }
static inline union __v1f __v1f_neq(union __v1f a, union __v1f b) { union __v1f r = { .i = -(a.v != b.v) }; return r; }
static inline union __v1i __v1i_neq(union __v1i a, union __v1i b) { union __v1i r = { .i = -(a.v != b.v) }; return r; }
static inline union __v1l __v1l_neq(union __v1l a, union __v1l b) { union __v1l r = { .i = -(a.v != b.v) }; return r; }
static inline v2d __v2d_neq(v2d a, v2d b) { return v2d_merge2_v1d(v1d_neq(v1d_get_low_v2d(a), v1d_get_low_v2d(b)), v1d_neq(v1d_get_high_v2d(a), v1d_get_high_v2d(b))); }
static inline v2f __v2f_neq(v2f a, v2f b) { return v2f_merge2_v1f(v1f_neq(v1f_get_low_v2f(a), v1f_get_low_v2f(b)), v1f_neq(v1f_get_high_v2f(a), v1f_get_high_v2f(b))); }
static inline v2i __v2i_neq(v2i a, v2i b) { return v2i_merge2_v1i(v1i_neq(v1i_get_low_v2i(a), v1i_get_low_v2i(b)), v1i_neq(v1i_get_high_v2i(a), v1i_get_high_v2i(b))); }
static inline v2l __v2l_neq(v2l a, v2l b) { return v2l_merge2_v1l(v1l_neq(v1l_get_low_v2l(a), v1l_get_low_v2l(b)), v1l_neq(v1l_get_high_v2l(a), v1l_get_high_v2l(b))); }
static inline v4d __v4d_neq(v4d a, v4d b) { return v4d_merge2_v2d(v2d_neq(v2d_get_low_v4d(a), v2d_get_low_v4d(b)), v2d_neq(v2d_get_high_v4d(a), v2d_get_high_v4d(b))); }
static inline v4f __v4f_neq(v4f a, v4f b) { return v4f_merge2_v2f(v2f_neq(v2f_get_low_v4f(a), v2f_get_low_v4f(b)), v2f_neq(v2f_get_high_v4f(a), v2f_get_high_v4f(b))); }
static inline v4i __v4i_neq(v4i a, v4i b) { return v4i_merge2_v2i(v2i_neq(v2i_get_low_v4i(a), v2i_get_low_v4i(b)), v2i_neq(v2i_get_high_v4i(a), v2i_get_high_v4i(b))); }
static inline v4l __v4l_neq(v4l a, v4l b) { return v4l_merge2_v2l(v2l_neq(v2l_get_low_v4l(a), v2l_get_low_v4l(b)), v2l_neq(v2l_get_high_v4l(a), v2l_get_high_v4l(b))); }
static inline v8d __v8d_neq(v8d a, v8d b) { return v8d_merge2_v4d(v4d_neq(v4d_get_low_v8d(a), v4d_get_low_v8d(b)), v4d_neq(v4d_get_high_v8d(a), v4d_get_high_v8d(b))); }
static inline v8f __v8f_neq(v8f a, v8f b) { return v8f_merge2_v4f(v4f_neq(v4f_get_low_v8f(a), v4f_get_low_v8f(b)), v4f_neq(v4f_get_high_v8f(a), v4f_get_high_v8f(b))); }
static inline v8i __v8i_neq(v8i a, v8i b) { return v8i_merge2_v4i(v4i_neq(v4i_get_low_v8i(a), v4i_get_low_v8i(b)), v4i_neq(v4i_get_high_v8i(a), v4i_get_high_v8i(b))); }
static inline v8l __v8l_neq(v8l a, v8l b) { return v8l_merge2_v4l(v4l_neq(v4l_get_low_v8l(a), v4l_get_low_v8l(b)), v4l_neq(v4l_get_high_v8l(a), v4l_get_high_v8l(b))); }
static inline v16f __v16f_neq(v16f a, v16f b) { return v16f_merge2_v8f(v8f_neq(v8f_get_low_v16f(a), v8f_get_low_v16f(b)), v8f_neq(v8f_get_high_v16f(a), v8f_get_high_v16f(b))); }
static inline v16i __v16i_neq(v16i a, v16i b) { return v16i_merge2_v8i(v8i_neq(v8i_get_low_v16i(a), v8i_get_low_v16i(b)), v8i_neq(v8i_get_high_v16i(a), v8i_get_high_v16i(b))); }

static inline union __v1d __v1d_gt(union __v1d a, union __v1d b) { union __v1d r = { .i = -(a.v > b.v) }; return r; }
static inline union __v1f __v1f_gt(union __v1f a, union __v1f b) { union __v1f r = { .i = -(a.v > b.v) }; return r; }
static inline union __v1i __v1i_gt(union __v1i a, union __v1i b) { union __v1i r = { .i = -(a.v > b.v) }; return r; }
static inline union __v1l __v1l_gt(union __v1l a, union __v1l b) { union __v1l r = { .i = -(a.v > b.v) }; return r; }
static inline v2d __v2d_gt(v2d a, v2d b) { return v2d_merge2_v1d(v1d_gt(v1d_get_low_v2d(a), v1d_get_low_v2d(b)), v1d_gt(v1d_get_high_v2d(a), v1d_get_high_v2d(b))); }
static inline v2f __v2f_gt(v2f a, v2f b) { return v2f_merge2_v1f(v1f_gt(v1f_get_low_v2f(a), v1f_get_low_v2f(b)), v1f_gt(v1f_get_high_v2f(a), v1f_get_high_v2f(b))); }
static inline v2i __v2i_gt(v2i a, v2i b) { return v2i_merge2_v1i(v1i_gt(v1i_get_low_v2i(a), v1i_get_low_v2i(b)), v1i_gt(v1i_get_high_v2i(a), v1i_get_high_v2i(b))); }
static inline v2l __v2l_gt(v2l a, v2l b) { return v2l_merge2_v1l(v1l_gt(v1l_get_low_v2l(a), v1l_get_low_v2l(b)), v1l_gt(v1l_get_high_v2l(a), v1l_get_high_v2l(b))); }
static inline v4d __v4d_gt(v4d a, v4d b) { return v4d_merge2_v2d(v2d_gt(v2d_get_low_v4d(a), v2d_get_low_v4d(b)), v2d_gt(v2d_get_high_v4d(a), v2d_get_high_v4d(b))); }
static inline v4f __v4f_gt(v4f a, v4f b) { return v4f_merge2_v2f(v2f_gt(v2f_get_low_v4f(a), v2f_get_low_v4f(b)), v2f_gt(v2f_get_high_v4f(a), v2f_get_high_v4f(b))); }
static inline v4i __v4i_gt(v4i a, v4i b) { return v4i_merge2_v2i(v2i_gt(v2i_get_low_v4i(a), v2i_get_low_v4i(b)), v2i_gt(v2i_get_high_v4i(a), v2i_get_high_v4i(b))); }
static inline v4l __v4l_gt(v4l a, v4l b) { return v4l_merge2_v2l(v2l_gt(v2l_get_low_v4l(a), v2l_get_low_v4l(b)), v2l_gt(v2l_get_high_v4l(a), v2l_get_high_v4l(b))); }
static inline v8d __v8d_gt(v8d a, v8d b) { return v8d_merge2_v4d(v4d_gt(v4d_get_low_v8d(a), v4d_get_low_v8d(b)), v4d_gt(v4d_get_high_v8d(a), v4d_get_high_v8d(b))); }
static inline v8f __v8f_gt(v8f a, v8f b) { return v8f_merge2_v4f(v4f_gt(v4f_get_low_v8f(a), v4f_get_low_v8f(b)), v4f_gt(v4f_get_high_v8f(a), v4f_get_high_v8f(b))); }
static inline v8i __v8i_gt(v8i a, v8i b) { return v8i_merge2_v4i(v4i_gt(v4i_get_low_v8i(a), v4i_get_low_v8i(b)), v4i_gt(v4i_get_high_v8i(a), v4i_get_high_v8i(b))); }
static inline v8l __v8l_gt(v8l a, v8l b) { return v8l_merge2_v4l(v4l_gt(v4l_get_low_v8l(a), v4l_get_low_v8l(b)), v4l_gt(v4l_get_high_v8l(a), v4l_get_high_v8l(b))); }
static inline v16f __v16f_gt(v16f a, v16f b) { return v16f_merge2_v8f(v8f_gt(v8f_get_low_v16f(a), v8f_get_low_v16f(b)), v8f_gt(v8f_get_high_v16f(a), v8f_get_high_v16f(b))); }
static inline v16i __v16i_gt(v16i a, v16i b) { return v16i_merge2_v8i(v8i_gt(v8i_get_low_v16i(a), v8i_get_low_v16i(b)), v8i_gt(v8i_get_high_v16i(a), v8i_get_high_v16i(b))); }

static inline union __v1d __v1d_geq(union __v1d a, union __v1d b) { union __v1d r = { .i = -(a.v >= b.v) }; return r; }
static inline union __v1f __v1f_geq(union __v1f a, union __v1f b) { union __v1f r = { .i = -(a.v >= b.v) }; return r; }
static inline union __v1i __v1i_geq(union __v1i a, union __v1i b) { union __v1i r = { .i = -(a.v >= b.v) }; return r; }
static inline union __v1l __v1l_geq(union __v1l a, union __v1l b) { union __v1l r = { .i = -(a.v >= b.v) }; return r; }
static inline v2d __v2d_geq(v2d a, v2d b) { return v2d_merge2_v1d(v1d_geq(v1d_get_low_v2d(a), v1d_get_low_v2d(b)), v1d_geq(v1d_get_high_v2d(a), v1d_get_high_v2d(b))); }
static inline v2f __v2f_geq(v2f a, v2f b) { return v2f_merge2_v1f(v1f_geq(v1f_get_low_v2f(a), v1f_get_low_v2f(b)), v1f_geq(v1f_get_high_v2f(a), v1f_get_high_v2f(b))); }
static inline v2i __v2i_geq(v2i a, v2i b) { return v2i_merge2_v1i(v1i_geq(v1i_get_low_v2i(a), v1i_get_low_v2i(b)), v1i_geq(v1i_get_high_v2i(a), v1i_get_high_v2i(b))); }
static inline v2l __v2l_geq(v2l a, v2l b) { return v2l_merge2_v1l(v1l_geq(v1l_get_low_v2l(a), v1l_get_low_v2l(b)), v1l_geq(v1l_get_high_v2l(a), v1l_get_high_v2l(b))); }
static inline v4d __v4d_geq(v4d a, v4d b) { return v4d_merge2_v2d(v2d_geq(v2d_get_low_v4d(a), v2d_get_low_v4d(b)), v2d_geq(v2d_get_high_v4d(a), v2d_get_high_v4d(b))); }
static inline v4f __v4f_geq(v4f a, v4f b) { return v4f_merge2_v2f(v2f_geq(v2f_get_low_v4f(a), v2f_get_low_v4f(b)), v2f_geq(v2f_get_high_v4f(a), v2f_get_high_v4f(b))); }
static inline v4i __v4i_geq(v4i a, v4i b) { return v4i_merge2_v2i(v2i_geq(v2i_get_low_v4i(a), v2i_get_low_v4i(b)), v2i_geq(v2i_get_high_v4i(a), v2i_get_high_v4i(b))); }
static inline v4l __v4l_geq(v4l a, v4l b) { return v4l_merge2_v2l(v2l_geq(v2l_get_low_v4l(a), v2l_get_low_v4l(b)), v2l_geq(v2l_get_high_v4l(a), v2l_get_high_v4l(b))); }
static inline v8d __v8d_geq(v8d a, v8d b) { return v8d_merge2_v4d(v4d_geq(v4d_get_low_v8d(a), v4d_get_low_v8d(b)), v4d_geq(v4d_get_high_v8d(a), v4d_get_high_v8d(b))); }
static inline v8f __v8f_geq(v8f a, v8f b) { return v8f_merge2_v4f(v4f_geq(v4f_get_low_v8f(a), v4f_get_low_v8f(b)), v4f_geq(v4f_get_high_v8f(a), v4f_get_high_v8f(b))); }
static inline v8i __v8i_geq(v8i a, v8i b) { return v8i_merge2_v4i(v4i_geq(v4i_get_low_v8i(a), v4i_get_low_v8i(b)), v4i_geq(v4i_get_high_v8i(a), v4i_get_high_v8i(b))); }
static inline v8l __v8l_geq(v8l a, v8l b) { return v8l_merge2_v4l(v4l_geq(v4l_get_low_v8l(a), v4l_get_low_v8l(b)), v4l_geq(v4l_get_high_v8l(a), v4l_get_high_v8l(b))); }
static inline v16f __v16f_geq(v16f a, v16f b) { return v16f_merge2_v8f(v8f_geq(v8f_get_low_v16f(a), v8f_get_low_v16f(b)), v8f_geq(v8f_get_high_v16f(a), v8f_get_high_v16f(b))); }
static inline v16i __v16i_geq(v16i a, v16i b) { return v16i_merge2_v8i(v8i_geq(v8i_get_low_v16i(a), v8i_get_low_v16i(b)), v8i_geq(v8i_get_high_v16i(a), v8i_get_high_v16i(b))); }

static inline union __v1d __v1d_lt(union __v1d a, union __v1d b) { union __v1d r = { .i = -(a.v < b.v) }; return r; }
static inline union __v1f __v1f_lt(union __v1f a, union __v1f b) { union __v1f r = { .i = -(a.v < b.v) }; return r; }
static inline union __v1i __v1i_lt(union __v1i a, union __v1i b) { union __v1i r = { .i = -(a.v < b.v) }; return r; }
static inline union __v1l __v1l_lt(union __v1l a, union __v1l b) { union __v1l r = { .i = -(a.v < b.v) }; return r; }
static inline v2d __v2d_lt(v2d a, v2d b) { return v2d_merge2_v1d(v1d_lt(v1d_get_low_v2d(a), v1d_get_low_v2d(b)), v1d_lt(v1d_get_high_v2d(a), v1d_get_high_v2d(b))); }
static inline v2f __v2f_lt(v2f a, v2f b) { return v2f_merge2_v1f(v1f_lt(v1f_get_low_v2f(a), v1f_get_low_v2f(b)), v1f_lt(v1f_get_high_v2f(a), v1f_get_high_v2f(b))); }
static inline v2i __v2i_lt(v2i a, v2i b) { return v2i_merge2_v1i(v1i_lt(v1i_get_low_v2i(a), v1i_get_low_v2i(b)), v1i_lt(v1i_get_high_v2i(a), v1i_get_high_v2i(b))); }
static inline v2l __v2l_lt(v2l a, v2l b) { return v2l_merge2_v1l(v1l_lt(v1l_get_low_v2l(a), v1l_get_low_v2l(b)), v1l_lt(v1l_get_high_v2l(a), v1l_get_high_v2l(b))); }
static inline v4d __v4d_lt(v4d a, v4d b) { return v4d_merge2_v2d(v2d_lt(v2d_get_low_v4d(a), v2d_get_low_v4d(b)), v2d_lt(v2d_get_high_v4d(a), v2d_get_high_v4d(b))); }
static inline v4f __v4f_lt(v4f a, v4f b) { return v4f_merge2_v2f(v2f_lt(v2f_get_low_v4f(a), v2f_get_low_v4f(b)), v2f_lt(v2f_get_high_v4f(a), v2f_get_high_v4f(b))); }
static inline v4i __v4i_lt(v4i a, v4i b) { return v4i_merge2_v2i(v2i_lt(v2i_get_low_v4i(a), v2i_get_low_v4i(b)), v2i_lt(v2i_get_high_v4i(a), v2i_get_high_v4i(b))); }
static inline v4l __v4l_lt(v4l a, v4l b) { return v4l_merge2_v2l(v2l_lt(v2l_get_low_v4l(a), v2l_get_low_v4l(b)), v2l_lt(v2l_get_high_v4l(a), v2l_get_high_v4l(b))); }
static inline v8d __v8d_lt(v8d a, v8d b) { return v8d_merge2_v4d(v4d_lt(v4d_get_low_v8d(a), v4d_get_low_v8d(b)), v4d_lt(v4d_get_high_v8d(a), v4d_get_high_v8d(b))); }
static inline v8f __v8f_lt(v8f a, v8f b) { return v8f_merge2_v4f(v4f_lt(v4f_get_low_v8f(a), v4f_get_low_v8f(b)), v4f_lt(v4f_get_high_v8f(a), v4f_get_high_v8f(b))); }
static inline v8i __v8i_lt(v8i a, v8i b) { return v8i_merge2_v4i(v4i_lt(v4i_get_low_v8i(a), v4i_get_low_v8i(b)), v4i_lt(v4i_get_high_v8i(a), v4i_get_high_v8i(b))); }
static inline v8l __v8l_lt(v8l a, v8l b) { return v8l_merge2_v4l(v4l_lt(v4l_get_low_v8l(a), v4l_get_low_v8l(b)), v4l_lt(v4l_get_high_v8l(a), v4l_get_high_v8l(b))); }
static inline v16f __v16f_lt(v16f a, v16f b) { return v16f_merge2_v8f(v8f_lt(v8f_get_low_v16f(a), v8f_get_low_v16f(b)), v8f_lt(v8f_get_high_v16f(a), v8f_get_high_v16f(b))); }
static inline v16i __v16i_lt(v16i a, v16i b) { return v16i_merge2_v8i(v8i_lt(v8i_get_low_v16i(a), v8i_get_low_v16i(b)), v8i_lt(v8i_get_high_v16i(a), v8i_get_high_v16i(b))); }

static inline union __v1d __v1d_leq(union __v1d a, union __v1d b) { union __v1d r = { .i = -(a.v <= b.v) }; return r; }
static inline union __v1f __v1f_leq(union __v1f a, union __v1f b) { union __v1f r = { .i = -(a.v <= b.v) }; return r; }
static inline union __v1i __v1i_leq(union __v1i a, union __v1i b) { union __v1i r = { .i = -(a.v <= b.v) }; return r; }
static inline union __v1l __v1l_leq(union __v1l a, union __v1l b) { union __v1l r = { .i = -(a.v <= b.v) }; return r; }
static inline v2d __v2d_leq(v2d a, v2d b) { return v2d_merge2_v1d(v1d_leq(v1d_get_low_v2d(a), v1d_get_low_v2d(b)), v1d_leq(v1d_get_high_v2d(a), v1d_get_high_v2d(b))); }
static inline v2f __v2f_leq(v2f a, v2f b) { return v2f_merge2_v1f(v1f_leq(v1f_get_low_v2f(a), v1f_get_low_v2f(b)), v1f_leq(v1f_get_high_v2f(a), v1f_get_high_v2f(b))); }
static inline v2i __v2i_leq(v2i a, v2i b) { return v2i_merge2_v1i(v1i_leq(v1i_get_low_v2i(a), v1i_get_low_v2i(b)), v1i_leq(v1i_get_high_v2i(a), v1i_get_high_v2i(b))); }
static inline v2l __v2l_leq(v2l a, v2l b) { return v2l_merge2_v1l(v1l_leq(v1l_get_low_v2l(a), v1l_get_low_v2l(b)), v1l_leq(v1l_get_high_v2l(a), v1l_get_high_v2l(b))); }
static inline v4d __v4d_leq(v4d a, v4d b) { return v4d_merge2_v2d(v2d_leq(v2d_get_low_v4d(a), v2d_get_low_v4d(b)), v2d_leq(v2d_get_high_v4d(a), v2d_get_high_v4d(b))); }
static inline v4f __v4f_leq(v4f a, v4f b) { return v4f_merge2_v2f(v2f_leq(v2f_get_low_v4f(a), v2f_get_low_v4f(b)), v2f_leq(v2f_get_high_v4f(a), v2f_get_high_v4f(b))); }
static inline v4i __v4i_leq(v4i a, v4i b) { return v4i_merge2_v2i(v2i_leq(v2i_get_low_v4i(a), v2i_get_low_v4i(b)), v2i_leq(v2i_get_high_v4i(a), v2i_get_high_v4i(b))); }
static inline v4l __v4l_leq(v4l a, v4l b) { return v4l_merge2_v2l(v2l_leq(v2l_get_low_v4l(a), v2l_get_low_v4l(b)), v2l_leq(v2l_get_high_v4l(a), v2l_get_high_v4l(b))); }
static inline v8d __v8d_leq(v8d a, v8d b) { return v8d_merge2_v4d(v4d_leq(v4d_get_low_v8d(a), v4d_get_low_v8d(b)), v4d_leq(v4d_get_high_v8d(a), v4d_get_high_v8d(b))); }
static inline v8f __v8f_leq(v8f a, v8f b) { return v8f_merge2_v4f(v4f_leq(v4f_get_low_v8f(a), v4f_get_low_v8f(b)), v4f_leq(v4f_get_high_v8f(a), v4f_get_high_v8f(b))); }
static inline v8i __v8i_leq(v8i a, v8i b) { return v8i_merge2_v4i(v4i_leq(v4i_get_low_v8i(a), v4i_get_low_v8i(b)), v4i_leq(v4i_get_high_v8i(a), v4i_get_high_v8i(b))); }
static inline v8l __v8l_leq(v8l a, v8l b) { return v8l_merge2_v4l(v4l_leq(v4l_get_low_v8l(a), v4l_get_low_v8l(b)), v4l_leq(v4l_get_high_v8l(a), v4l_get_high_v8l(b))); }
static inline v16f __v16f_leq(v16f a, v16f b) { return v16f_merge2_v8f(v8f_leq(v8f_get_low_v16f(a), v8f_get_low_v16f(b)), v8f_leq(v8f_get_high_v16f(a), v8f_get_high_v16f(b))); }
static inline v16i __v16i_leq(v16i a, v16i b) { return v16i_merge2_v8i(v8i_leq(v8i_get_low_v16i(a), v8i_get_low_v16i(b)), v8i_leq(v8i_get_high_v16i(a), v8i_get_high_v16i(b))); }

/* LOGIC */

static inline union __v1d __v1d_and(union __v1d a, union __v1d b) { union __v1d r = { .i = a.i & b.i }; return r; }
static inline union __v1f __v1f_and(union __v1f a, union __v1f b) { union __v1f r = { .i = a.i & b.i }; return r; }
static inline union __v1i __v1i_and(union __v1i a, union __v1i b) { union __v1i r = { .i = a.i & b.i }; return r; }
static inline union __v1l __v1l_and(union __v1l a, union __v1l b) { union __v1l r = { .i = a.i & b.i }; return r; }
static inline v2d __v2d_and(v2d a, v2d b) { return v2d_merge2_v1d(v1d_and(v1d_get_low_v2d(a), v1d_get_low_v2d(b)), v1d_and(v1d_get_high_v2d(a), v1d_get_high_v2d(b))); }
static inline v2f __v2f_and(v2f a, v2f b) { return v2f_merge2_v1f(v1f_and(v1f_get_low_v2f(a), v1f_get_low_v2f(b)), v1f_and(v1f_get_high_v2f(a), v1f_get_high_v2f(b))); }
static inline v2i __v2i_and(v2i a, v2i b) { return v2i_merge2_v1i(v1i_and(v1i_get_low_v2i(a), v1i_get_low_v2i(b)), v1i_and(v1i_get_high_v2i(a), v1i_get_high_v2i(b))); }
static inline v2l __v2l_and(v2l a, v2l b) { return v2l_merge2_v1l(v1l_and(v1l_get_low_v2l(a), v1l_get_low_v2l(b)), v1l_and(v1l_get_high_v2l(a), v1l_get_high_v2l(b))); }
static inline v4d __v4d_and(v4d a, v4d b) { return v4d_merge2_v2d(v2d_and(v2d_get_low_v4d(a), v2d_get_low_v4d(b)), v2d_and(v2d_get_high_v4d(a), v2d_get_high_v4d(b))); }
static inline v4f __v4f_and(v4f a, v4f b) { return v4f_merge2_v2f(v2f_and(v2f_get_low_v4f(a), v2f_get_low_v4f(b)), v2f_and(v2f_get_high_v4f(a), v2f_get_high_v4f(b))); }
static inline v4i __v4i_and(v4i a, v4i b) { return v4i_merge2_v2i(v2i_and(v2i_get_low_v4i(a), v2i_get_low_v4i(b)), v2i_and(v2i_get_high_v4i(a), v2i_get_high_v4i(b))); }
static inline v4l __v4l_and(v4l a, v4l b) { return v4l_merge2_v2l(v2l_and(v2l_get_low_v4l(a), v2l_get_low_v4l(b)), v2l_and(v2l_get_high_v4l(a), v2l_get_high_v4l(b))); }
static inline v8d __v8d_and(v8d a, v8d b) { return v8d_merge2_v4d(v4d_and(v4d_get_low_v8d(a), v4d_get_low_v8d(b)), v4d_and(v4d_get_high_v8d(a), v4d_get_high_v8d(b))); }
static inline v8f __v8f_and(v8f a, v8f b) { return v8f_merge2_v4f(v4f_and(v4f_get_low_v8f(a), v4f_get_low_v8f(b)), v4f_and(v4f_get_high_v8f(a), v4f_get_high_v8f(b))); }
static inline v8i __v8i_and(v8i a, v8i b) { return v8i_merge2_v4i(v4i_and(v4i_get_low_v8i(a), v4i_get_low_v8i(b)), v4i_and(v4i_get_high_v8i(a), v4i_get_high_v8i(b))); }
static inline v8l __v8l_and(v8l a, v8l b) { return v8l_merge2_v4l(v4l_and(v4l_get_low_v8l(a), v4l_get_low_v8l(b)), v4l_and(v4l_get_high_v8l(a), v4l_get_high_v8l(b))); }
static inline v16f __v16f_and(v16f a, v16f b) { return v16f_merge2_v8f(v8f_and(v8f_get_low_v16f(a), v8f_get_low_v16f(b)), v8f_and(v8f_get_high_v16f(a), v8f_get_high_v16f(b))); }
static inline v16i __v16i_and(v16i a, v16i b) { return v16i_merge2_v8i(v8i_and(v8i_get_low_v16i(a), v8i_get_low_v16i(b)), v8i_and(v8i_get_high_v16i(a), v8i_get_high_v16i(b))); }

static inline union __v1d __v1d_or(union __v1d a, union __v1d b) { union __v1d r = { .i = a.i | b.i }; return r; }
static inline union __v1f __v1f_or(union __v1f a, union __v1f b) { union __v1f r = { .i = a.i | b.i }; return r; }
static inline union __v1i __v1i_or(union __v1i a, union __v1i b) { union __v1i r = { .i = a.i | b.i }; return r; }
static inline union __v1l __v1l_or(union __v1l a, union __v1l b) { union __v1l r = { .i = a.i | b.i }; return r; }
static inline v2d __v2d_or(v2d a, v2d b) { return v2d_merge2_v1d(v1d_or(v1d_get_low_v2d(a), v1d_get_low_v2d(b)), v1d_or(v1d_get_high_v2d(a), v1d_get_high_v2d(b))); }
static inline v2f __v2f_or(v2f a, v2f b) { return v2f_merge2_v1f(v1f_or(v1f_get_low_v2f(a), v1f_get_low_v2f(b)), v1f_or(v1f_get_high_v2f(a), v1f_get_high_v2f(b))); }
static inline v2i __v2i_or(v2i a, v2i b) { return v2i_merge2_v1i(v1i_or(v1i_get_low_v2i(a), v1i_get_low_v2i(b)), v1i_or(v1i_get_high_v2i(a), v1i_get_high_v2i(b))); }
static inline v2l __v2l_or(v2l a, v2l b) { return v2l_merge2_v1l(v1l_or(v1l_get_low_v2l(a), v1l_get_low_v2l(b)), v1l_or(v1l_get_high_v2l(a), v1l_get_high_v2l(b))); }
static inline v4d __v4d_or(v4d a, v4d b) { return v4d_merge2_v2d(v2d_or(v2d_get_low_v4d(a), v2d_get_low_v4d(b)), v2d_or(v2d_get_high_v4d(a), v2d_get_high_v4d(b))); }
static inline v4f __v4f_or(v4f a, v4f b) { return v4f_merge2_v2f(v2f_or(v2f_get_low_v4f(a), v2f_get_low_v4f(b)), v2f_or(v2f_get_high_v4f(a), v2f_get_high_v4f(b))); }
static inline v4i __v4i_or(v4i a, v4i b) { return v4i_merge2_v2i(v2i_or(v2i_get_low_v4i(a), v2i_get_low_v4i(b)), v2i_or(v2i_get_high_v4i(a), v2i_get_high_v4i(b))); }
static inline v4l __v4l_or(v4l a, v4l b) { return v4l_merge2_v2l(v2l_or(v2l_get_low_v4l(a), v2l_get_low_v4l(b)), v2l_or(v2l_get_high_v4l(a), v2l_get_high_v4l(b))); }
static inline v8d __v8d_or(v8d a, v8d b) { return v8d_merge2_v4d(v4d_or(v4d_get_low_v8d(a), v4d_get_low_v8d(b)), v4d_or(v4d_get_high_v8d(a), v4d_get_high_v8d(b))); }
static inline v8f __v8f_or(v8f a, v8f b) { return v8f_merge2_v4f(v4f_or(v4f_get_low_v8f(a), v4f_get_low_v8f(b)), v4f_or(v4f_get_high_v8f(a), v4f_get_high_v8f(b))); }
static inline v8i __v8i_or(v8i a, v8i b) { return v8i_merge2_v4i(v4i_or(v4i_get_low_v8i(a), v4i_get_low_v8i(b)), v4i_or(v4i_get_high_v8i(a), v4i_get_high_v8i(b))); }
static inline v8l __v8l_or(v8l a, v8l b) { return v8l_merge2_v4l(v4l_or(v4l_get_low_v8l(a), v4l_get_low_v8l(b)), v4l_or(v4l_get_high_v8l(a), v4l_get_high_v8l(b))); }
static inline v16f __v16f_or(v16f a, v16f b) { return v16f_merge2_v8f(v8f_or(v8f_get_low_v16f(a), v8f_get_low_v16f(b)), v8f_or(v8f_get_high_v16f(a), v8f_get_high_v16f(b))); }
static inline v16i __v16i_or(v16i a, v16i b) { return v16i_merge2_v8i(v8i_or(v8i_get_low_v16i(a), v8i_get_low_v16i(b)), v8i_or(v8i_get_high_v16i(a), v8i_get_high_v16i(b))); }

static inline union __v1d __v1d_xor(union __v1d a, union __v1d b) { union __v1d r = { .i = a.i ^ b.i }; return r; }
static inline union __v1f __v1f_xor(union __v1f a, union __v1f b) { union __v1f r = { .i = a.i ^ b.i }; return r; }
static inline union __v1i __v1i_xor(union __v1i a, union __v1i b) { union __v1i r = { .i = a.i ^ b.i }; return r; }
static inline union __v1l __v1l_xor(union __v1l a, union __v1l b) { union __v1l r = { .i = a.i ^ b.i }; return r; }
static inline v2d __v2d_xor(v2d a, v2d b) { return v2d_merge2_v1d(v1d_xor(v1d_get_low_v2d(a), v1d_get_low_v2d(b)), v1d_xor(v1d_get_high_v2d(a), v1d_get_high_v2d(b))); }
static inline v2f __v2f_xor(v2f a, v2f b) { return v2f_merge2_v1f(v1f_xor(v1f_get_low_v2f(a), v1f_get_low_v2f(b)), v1f_xor(v1f_get_high_v2f(a), v1f_get_high_v2f(b))); }
static inline v2i __v2i_xor(v2i a, v2i b) { return v2i_merge2_v1i(v1i_xor(v1i_get_low_v2i(a), v1i_get_low_v2i(b)), v1i_xor(v1i_get_high_v2i(a), v1i_get_high_v2i(b))); }
static inline v2l __v2l_xor(v2l a, v2l b) { return v2l_merge2_v1l(v1l_xor(v1l_get_low_v2l(a), v1l_get_low_v2l(b)), v1l_xor(v1l_get_high_v2l(a), v1l_get_high_v2l(b))); }
static inline v4d __v4d_xor(v4d a, v4d b) { return v4d_merge2_v2d(v2d_xor(v2d_get_low_v4d(a), v2d_get_low_v4d(b)), v2d_xor(v2d_get_high_v4d(a), v2d_get_high_v4d(b))); }
static inline v4f __v4f_xor(v4f a, v4f b) { return v4f_merge2_v2f(v2f_xor(v2f_get_low_v4f(a), v2f_get_low_v4f(b)), v2f_xor(v2f_get_high_v4f(a), v2f_get_high_v4f(b))); }
static inline v4i __v4i_xor(v4i a, v4i b) { return v4i_merge2_v2i(v2i_xor(v2i_get_low_v4i(a), v2i_get_low_v4i(b)), v2i_xor(v2i_get_high_v4i(a), v2i_get_high_v4i(b))); }
static inline v4l __v4l_xor(v4l a, v4l b) { return v4l_merge2_v2l(v2l_xor(v2l_get_low_v4l(a), v2l_get_low_v4l(b)), v2l_xor(v2l_get_high_v4l(a), v2l_get_high_v4l(b))); }
static inline v8d __v8d_xor(v8d a, v8d b) { return v8d_merge2_v4d(v4d_xor(v4d_get_low_v8d(a), v4d_get_low_v8d(b)), v4d_xor(v4d_get_high_v8d(a), v4d_get_high_v8d(b))); }
static inline v8f __v8f_xor(v8f a, v8f b) { return v8f_merge2_v4f(v4f_xor(v4f_get_low_v8f(a), v4f_get_low_v8f(b)), v4f_xor(v4f_get_high_v8f(a), v4f_get_high_v8f(b))); }
static inline v8i __v8i_xor(v8i a, v8i b) { return v8i_merge2_v4i(v4i_xor(v4i_get_low_v8i(a), v4i_get_low_v8i(b)), v4i_xor(v4i_get_high_v8i(a), v4i_get_high_v8i(b))); }
static inline v8l __v8l_xor(v8l a, v8l b) { return v8l_merge2_v4l(v4l_xor(v4l_get_low_v8l(a), v4l_get_low_v8l(b)), v4l_xor(v4l_get_high_v8l(a), v4l_get_high_v8l(b))); }
static inline v16f __v16f_xor(v16f a, v16f b) { return v16f_merge2_v8f(v8f_xor(v8f_get_low_v16f(a), v8f_get_low_v16f(b)), v8f_xor(v8f_get_high_v16f(a), v8f_get_high_v16f(b))); }
static inline v16i __v16i_xor(v16i a, v16i b) { return v16i_merge2_v8i(v8i_xor(v8i_get_low_v16i(a), v8i_get_low_v16i(b)), v8i_xor(v8i_get_high_v16i(a), v8i_get_high_v16i(b))); }








/* ARITHMETIC AND MATH */


static inline union __v1d __v1d_add(union __v1d a, union __v1d b) { union __v1d r = { .v = a.v + b.v }; return r; }
static inline union __v1f __v1f_add(union __v1f a, union __v1f b) { union __v1f r = { .v = a.v + b.v }; return r; }
static inline union __v1i __v1i_add(union __v1i a, union __v1i b) { union __v1i r = { .v = a.v + b.v }; return r; }
static inline union __v1l __v1l_add(union __v1l a, union __v1l b) { union __v1l r = { .v = a.v + b.v }; return r; }
static inline v2d __v2d_add(v2d a, v2d b) { return v2d_merge2_v1d(v1d_add(v1d_get_low_v2d(a), v1d_get_low_v2d(b)), v1d_add(v1d_get_high_v2d(a), v1d_get_high_v2d(b))); }
static inline v2f __v2f_add(v2f a, v2f b) { return v2f_merge2_v1f(v1f_add(v1f_get_low_v2f(a), v1f_get_low_v2f(b)), v1f_add(v1f_get_high_v2f(a), v1f_get_high_v2f(b))); }
static inline v2i __v2i_add(v2i a, v2i b) { return v2i_merge2_v1i(v1i_add(v1i_get_low_v2i(a), v1i_get_low_v2i(b)), v1i_add(v1i_get_high_v2i(a), v1i_get_high_v2i(b))); }
static inline v2l __v2l_add(v2l a, v2l b) { return v2l_merge2_v1l(v1l_add(v1l_get_low_v2l(a), v1l_get_low_v2l(b)), v1l_add(v1l_get_high_v2l(a), v1l_get_high_v2l(b))); }
static inline v4d __v4d_add(v4d a, v4d b) { return v4d_merge2_v2d(v2d_add(v2d_get_low_v4d(a), v2d_get_low_v4d(b)), v2d_add(v2d_get_high_v4d(a), v2d_get_high_v4d(b))); }
static inline v4f __v4f_add(v4f a, v4f b) { return v4f_merge2_v2f(v2f_add(v2f_get_low_v4f(a), v2f_get_low_v4f(b)), v2f_add(v2f_get_high_v4f(a), v2f_get_high_v4f(b))); }
static inline v4i __v4i_add(v4i a, v4i b) { return v4i_merge2_v2i(v2i_add(v2i_get_low_v4i(a), v2i_get_low_v4i(b)), v2i_add(v2i_get_high_v4i(a), v2i_get_high_v4i(b))); }
static inline v4l __v4l_add(v4l a, v4l b) { return v4l_merge2_v2l(v2l_add(v2l_get_low_v4l(a), v2l_get_low_v4l(b)), v2l_add(v2l_get_high_v4l(a), v2l_get_high_v4l(b))); }
static inline v8d __v8d_add(v8d a, v8d b) { return v8d_merge2_v4d(v4d_add(v4d_get_low_v8d(a), v4d_get_low_v8d(b)), v4d_add(v4d_get_high_v8d(a), v4d_get_high_v8d(b))); }
static inline v8f __v8f_add(v8f a, v8f b) { return v8f_merge2_v4f(v4f_add(v4f_get_low_v8f(a), v4f_get_low_v8f(b)), v4f_add(v4f_get_high_v8f(a), v4f_get_high_v8f(b))); }
static inline v8i __v8i_add(v8i a, v8i b) { return v8i_merge2_v4i(v4i_add(v4i_get_low_v8i(a), v4i_get_low_v8i(b)), v4i_add(v4i_get_high_v8i(a), v4i_get_high_v8i(b))); }
static inline v8l __v8l_add(v8l a, v8l b) { return v8l_merge2_v4l(v4l_add(v4l_get_low_v8l(a), v4l_get_low_v8l(b)), v4l_add(v4l_get_high_v8l(a), v4l_get_high_v8l(b))); }
static inline v16f __v16f_add(v16f a, v16f b) { return v16f_merge2_v8f(v8f_add(v8f_get_low_v16f(a), v8f_get_low_v16f(b)), v8f_add(v8f_get_high_v16f(a), v8f_get_high_v16f(b))); }
static inline v16i __v16i_add(v16i a, v16i b) { return v16i_merge2_v8i(v8i_add(v8i_get_low_v16i(a), v8i_get_low_v16i(b)), v8i_add(v8i_get_high_v16i(a), v8i_get_high_v16i(b))); }

static inline union __v1d __v1d_sub(union __v1d a, union __v1d b) { union __v1d r = { .v = a.v - b.v }; return r; }
static inline union __v1f __v1f_sub(union __v1f a, union __v1f b) { union __v1f r = { .v = a.v - b.v }; return r; }
static inline union __v1i __v1i_sub(union __v1i a, union __v1i b) { union __v1i r = { .v = a.v - b.v }; return r; }
static inline union __v1l __v1l_sub(union __v1l a, union __v1l b) { union __v1l r = { .v = a.v - b.v }; return r; }
static inline v2d __v2d_sub(v2d a, v2d b) { return v2d_merge2_v1d(v1d_sub(v1d_get_low_v2d(a), v1d_get_low_v2d(b)), v1d_sub(v1d_get_high_v2d(a), v1d_get_high_v2d(b))); }
static inline v2f __v2f_sub(v2f a, v2f b) { return v2f_merge2_v1f(v1f_sub(v1f_get_low_v2f(a), v1f_get_low_v2f(b)), v1f_sub(v1f_get_high_v2f(a), v1f_get_high_v2f(b))); }
static inline v2i __v2i_sub(v2i a, v2i b) { return v2i_merge2_v1i(v1i_sub(v1i_get_low_v2i(a), v1i_get_low_v2i(b)), v1i_sub(v1i_get_high_v2i(a), v1i_get_high_v2i(b))); }
static inline v2l __v2l_sub(v2l a, v2l b) { return v2l_merge2_v1l(v1l_sub(v1l_get_low_v2l(a), v1l_get_low_v2l(b)), v1l_sub(v1l_get_high_v2l(a), v1l_get_high_v2l(b))); }
static inline v4d __v4d_sub(v4d a, v4d b) { return v4d_merge2_v2d(v2d_sub(v2d_get_low_v4d(a), v2d_get_low_v4d(b)), v2d_sub(v2d_get_high_v4d(a), v2d_get_high_v4d(b))); }
static inline v4f __v4f_sub(v4f a, v4f b) { return v4f_merge2_v2f(v2f_sub(v2f_get_low_v4f(a), v2f_get_low_v4f(b)), v2f_sub(v2f_get_high_v4f(a), v2f_get_high_v4f(b))); }
static inline v4i __v4i_sub(v4i a, v4i b) { return v4i_merge2_v2i(v2i_sub(v2i_get_low_v4i(a), v2i_get_low_v4i(b)), v2i_sub(v2i_get_high_v4i(a), v2i_get_high_v4i(b))); }
static inline v4l __v4l_sub(v4l a, v4l b) { return v4l_merge2_v2l(v2l_sub(v2l_get_low_v4l(a), v2l_get_low_v4l(b)), v2l_sub(v2l_get_high_v4l(a), v2l_get_high_v4l(b))); }
static inline v8d __v8d_sub(v8d a, v8d b) { return v8d_merge2_v4d(v4d_sub(v4d_get_low_v8d(a), v4d_get_low_v8d(b)), v4d_sub(v4d_get_high_v8d(a), v4d_get_high_v8d(b))); }
static inline v8f __v8f_sub(v8f a, v8f b) { return v8f_merge2_v4f(v4f_sub(v4f_get_low_v8f(a), v4f_get_low_v8f(b)), v4f_sub(v4f_get_high_v8f(a), v4f_get_high_v8f(b))); }
static inline v8i __v8i_sub(v8i a, v8i b) { return v8i_merge2_v4i(v4i_sub(v4i_get_low_v8i(a), v4i_get_low_v8i(b)), v4i_sub(v4i_get_high_v8i(a), v4i_get_high_v8i(b))); }
static inline v8l __v8l_sub(v8l a, v8l b) { return v8l_merge2_v4l(v4l_sub(v4l_get_low_v8l(a), v4l_get_low_v8l(b)), v4l_sub(v4l_get_high_v8l(a), v4l_get_high_v8l(b))); }
static inline v16f __v16f_sub(v16f a, v16f b) { return v16f_merge2_v8f(v8f_sub(v8f_get_low_v16f(a), v8f_get_low_v16f(b)), v8f_sub(v8f_get_high_v16f(a), v8f_get_high_v16f(b))); }
static inline v16i __v16i_sub(v16i a, v16i b) { return v16i_merge2_v8i(v8i_sub(v8i_get_low_v16i(a), v8i_get_low_v16i(b)), v8i_sub(v8i_get_high_v16i(a), v8i_get_high_v16i(b))); }


static inline union __v1d __v1d_mul(union __v1d a, union __v1d b) { union __v1d r = { .v = a.v * b.v }; return r; }
static inline union __v1f __v1f_mul(union __v1f a, union __v1f b) { union __v1f r = { .v = a.v * b.v }; return r; }
static inline union __v1i __v1i_mul(union __v1i a, union __v1i b) { union __v1i r = { .v = a.v * b.v }; return r; }
static inline union __v1l __v1l_mul(union __v1l a, union __v1l b) { union __v1l r = { .v = a.v * b.v }; return r; }
static inline v2d __v2d_mul(v2d a, v2d b) { return v2d_merge2_v1d(v1d_mul(v1d_get_low_v2d(a), v1d_get_low_v2d(b)), v1d_mul(v1d_get_high_v2d(a), v1d_get_high_v2d(b))); }
static inline v2f __v2f_mul(v2f a, v2f b) { return v2f_merge2_v1f(v1f_mul(v1f_get_low_v2f(a), v1f_get_low_v2f(b)), v1f_mul(v1f_get_high_v2f(a), v1f_get_high_v2f(b))); }
static inline v2i __v2i_mul(v2i a, v2i b) { return v2i_merge2_v1i(v1i_mul(v1i_get_low_v2i(a), v1i_get_low_v2i(b)), v1i_mul(v1i_get_high_v2i(a), v1i_get_high_v2i(b))); }
static inline v2l __v2l_mul(v2l a, v2l b) { return v2l_merge2_v1l(v1l_mul(v1l_get_low_v2l(a), v1l_get_low_v2l(b)), v1l_mul(v1l_get_high_v2l(a), v1l_get_high_v2l(b))); }
static inline v4d __v4d_mul(v4d a, v4d b) { return v4d_merge2_v2d(v2d_mul(v2d_get_low_v4d(a), v2d_get_low_v4d(b)), v2d_mul(v2d_get_high_v4d(a), v2d_get_high_v4d(b))); }
static inline v4f __v4f_mul(v4f a, v4f b) { return v4f_merge2_v2f(v2f_mul(v2f_get_low_v4f(a), v2f_get_low_v4f(b)), v2f_mul(v2f_get_high_v4f(a), v2f_get_high_v4f(b))); }
static inline v4i __v4i_mul(v4i a, v4i b) { return v4i_merge2_v2i(v2i_mul(v2i_get_low_v4i(a), v2i_get_low_v4i(b)), v2i_mul(v2i_get_high_v4i(a), v2i_get_high_v4i(b))); }
static inline v4l __v4l_mul(v4l a, v4l b) { return v4l_merge2_v2l(v2l_mul(v2l_get_low_v4l(a), v2l_get_low_v4l(b)), v2l_mul(v2l_get_high_v4l(a), v2l_get_high_v4l(b))); }
static inline v8d __v8d_mul(v8d a, v8d b) { return v8d_merge2_v4d(v4d_mul(v4d_get_low_v8d(a), v4d_get_low_v8d(b)), v4d_mul(v4d_get_high_v8d(a), v4d_get_high_v8d(b))); }
static inline v8f __v8f_mul(v8f a, v8f b) { return v8f_merge2_v4f(v4f_mul(v4f_get_low_v8f(a), v4f_get_low_v8f(b)), v4f_mul(v4f_get_high_v8f(a), v4f_get_high_v8f(b))); }
static inline v8i __v8i_mul(v8i a, v8i b) { return v8i_merge2_v4i(v4i_mul(v4i_get_low_v8i(a), v4i_get_low_v8i(b)), v4i_mul(v4i_get_high_v8i(a), v4i_get_high_v8i(b))); }
static inline v8l __v8l_mul(v8l a, v8l b) { return v8l_merge2_v4l(v4l_mul(v4l_get_low_v8l(a), v4l_get_low_v8l(b)), v4l_mul(v4l_get_high_v8l(a), v4l_get_high_v8l(b))); }
static inline v16f __v16f_mul(v16f a, v16f b) { return v16f_merge2_v8f(v8f_mul(v8f_get_low_v16f(a), v8f_get_low_v16f(b)), v8f_mul(v8f_get_high_v16f(a), v8f_get_high_v16f(b))); }
static inline v16i __v16i_mul(v16i a, v16i b) { return v16i_merge2_v8i(v8i_mul(v8i_get_low_v16i(a), v8i_get_low_v16i(b)), v8i_mul(v8i_get_high_v16i(a), v8i_get_high_v16i(b))); }

static inline union __v1d __v1d_div(union __v1d a, union __v1d b) { union __v1d r = { .v = a.v / b.v }; return r; }
static inline union __v1f __v1f_div(union __v1f a, union __v1f b) { union __v1f r = { .v = a.v / b.v }; return r; }
static inline union __v1i __v1i_div(union __v1i a, union __v1i b) { union __v1i r = { .v = a.v / b.v }; return r; }
static inline union __v1l __v1l_div(union __v1l a, union __v1l b) { union __v1l r = { .v = a.v / b.v }; return r; }
static inline v2d __v2d_div(v2d a, v2d b) { return v2d_merge2_v1d(v1d_div(v1d_get_low_v2d(a), v1d_get_low_v2d(b)), v1d_div(v1d_get_high_v2d(a), v1d_get_high_v2d(b))); }
static inline v2f __v2f_div(v2f a, v2f b) { return v2f_merge2_v1f(v1f_div(v1f_get_low_v2f(a), v1f_get_low_v2f(b)), v1f_div(v1f_get_high_v2f(a), v1f_get_high_v2f(b))); }
static inline v2i __v2i_div(v2i a, v2i b) { return v2i_merge2_v1i(v1i_div(v1i_get_low_v2i(a), v1i_get_low_v2i(b)), v1i_div(v1i_get_high_v2i(a), v1i_get_high_v2i(b))); }
static inline v2l __v2l_div(v2l a, v2l b) { return v2l_merge2_v1l(v1l_div(v1l_get_low_v2l(a), v1l_get_low_v2l(b)), v1l_div(v1l_get_high_v2l(a), v1l_get_high_v2l(b))); }
static inline v4d __v4d_div(v4d a, v4d b) { return v4d_merge2_v2d(v2d_div(v2d_get_low_v4d(a), v2d_get_low_v4d(b)), v2d_div(v2d_get_high_v4d(a), v2d_get_high_v4d(b))); }
static inline v4f __v4f_div(v4f a, v4f b) { return v4f_merge2_v2f(v2f_div(v2f_get_low_v4f(a), v2f_get_low_v4f(b)), v2f_div(v2f_get_high_v4f(a), v2f_get_high_v4f(b))); }
static inline v4i __v4i_div(v4i a, v4i b) { return v4i_merge2_v2i(v2i_div(v2i_get_low_v4i(a), v2i_get_low_v4i(b)), v2i_div(v2i_get_high_v4i(a), v2i_get_high_v4i(b))); }
static inline v4l __v4l_div(v4l a, v4l b) { return v4l_merge2_v2l(v2l_div(v2l_get_low_v4l(a), v2l_get_low_v4l(b)), v2l_div(v2l_get_high_v4l(a), v2l_get_high_v4l(b))); }
static inline v8d __v8d_div(v8d a, v8d b) { return v8d_merge2_v4d(v4d_div(v4d_get_low_v8d(a), v4d_get_low_v8d(b)), v4d_div(v4d_get_high_v8d(a), v4d_get_high_v8d(b))); }
static inline v8f __v8f_div(v8f a, v8f b) { return v8f_merge2_v4f(v4f_div(v4f_get_low_v8f(a), v4f_get_low_v8f(b)), v4f_div(v4f_get_high_v8f(a), v4f_get_high_v8f(b))); }
static inline v8i __v8i_div(v8i a, v8i b) { return v8i_merge2_v4i(v4i_div(v4i_get_low_v8i(a), v4i_get_low_v8i(b)), v4i_div(v4i_get_high_v8i(a), v4i_get_high_v8i(b))); }
static inline v8l __v8l_div(v8l a, v8l b) { return v8l_merge2_v4l(v4l_div(v4l_get_low_v8l(a), v4l_get_low_v8l(b)), v4l_div(v4l_get_high_v8l(a), v4l_get_high_v8l(b))); }
static inline v16f __v16f_div(v16f a, v16f b) { return v16f_merge2_v8f(v8f_div(v8f_get_low_v16f(a), v8f_get_low_v16f(b)), v8f_div(v8f_get_high_v16f(a), v8f_get_high_v16f(b))); }
static inline v16i __v16i_div(v16i a, v16i b) { return v16i_merge2_v8i(v8i_div(v8i_get_low_v16i(a), v8i_get_low_v16i(b)), v8i_div(v8i_get_high_v16i(a), v8i_get_high_v16i(b))); }



static inline union __v1d __v1d_sqrt(union __v1d a) { union __v1d r = { .v = sqrt(a.v) }; return r; }
static inline union __v1f __v1f_sqrt(union __v1f a) { union __v1f r = { .v = sqrt(a.v) }; return r; }
static inline v1i __v1i_sqrt(v1i a) { return v1i_cvt_v1f(v1f_sqrt(v1f_cvt_v1i(a))); }
static inline v1l __v1l_sqrt(v1l a) { return v1l_cvt_v1d(v1d_sqrt(v1d_cvt_v1l(a))); }
static inline v2d __v2d_sqrt(v2d a) { return v2d_merge2_v1d(v1d_sqrt(v1d_get_low_v2d(a)), v1d_sqrt(v1d_get_high_v2d(a))); }
static inline v2f __v2f_sqrt(v2f a) { return v2f_merge2_v1f(v1f_sqrt(v1f_get_low_v2f(a)), v1f_sqrt(v1f_get_high_v2f(a))); }
static inline v2i __v2i_sqrt(v2i a) { return v2i_cvt_v2f(v2f_sqrt(v2f_cvt_v2i(a))); }
static inline v2l __v2l_sqrt(v2l a) { return v2l_cvt_v2d(v2d_sqrt(v2d_cvt_v2l(a))); }
static inline v4d __v4d_sqrt(v4d a) { return v4d_merge2_v2d(v2d_sqrt(v2d_get_low_v4d(a)), v2d_sqrt(v2d_get_high_v4d(a))); }
static inline v4f __v4f_sqrt(v4f a) { return v4f_merge2_v2f(v2f_sqrt(v2f_get_low_v4f(a)), v2f_sqrt(v2f_get_high_v4f(a))); }
static inline v4i __v4i_sqrt(v4i a) { return v4i_cvt_v4f(v4f_sqrt(v4f_cvt_v4i(a))); }
static inline v4l __v4l_sqrt(v4l a) { return v4l_cvt_v4d(v4d_sqrt(v4d_cvt_v4l(a))); }
static inline v8d __v8d_sqrt(v8d a) { return v8d_merge2_v4d(v4d_sqrt(v4d_get_low_v8d(a)), v4d_sqrt(v4d_get_high_v8d(a))); }
static inline v8f __v8f_sqrt(v8f a) { return v8f_merge2_v4f(v4f_sqrt(v4f_get_low_v8f(a)), v4f_sqrt(v4f_get_high_v8f(a))); }
static inline v8i __v8i_sqrt(v8i a) { return v8i_cvt_v8f(v8f_sqrt(v8f_cvt_v8i(a))); }
static inline v8l __v8l_sqrt(v8l a) { return v8l_cvt_v8d(v8d_sqrt(v8d_cvt_v8l(a))); }
static inline v16f __v16f_sqrt(v16f a) { return v16f_merge2_v8f(v8f_sqrt(v8f_get_low_v16f(a)), v8f_sqrt(v8f_get_high_v16f(a))); }
static inline v16i __v16i_sqrt(v16i a) { return v16i_cvt_v16f(v16f_sqrt(v16f_cvt_v16i(a))); }



/* Fused Multiply-Add */




/* MERGES */

static inline struct __v2d __v2d_merge2_v1d(v1d a0, v1d a1) { struct __v2d r = { .a = a0, .b = a1 }; return r; }
static inline struct __v2f __v2f_merge2_v1f(v1f a0, v1f a1) { struct __v2f r = { .a = a0, .b = a1 }; return r; }
static inline struct __v2i __v2i_merge2_v1i(v1i a0, v1i a1) { struct __v2i r = { .a = a0, .b = a1 }; return r; }
static inline struct __v2l __v2l_merge2_v1l(v1l a0, v1l a1) { struct __v2l r = { .a = a0, .b = a1 }; return r; }
static inline struct __v4d __v4d_merge2_v2d(v2d a0, v2d a1) { struct __v4d r = { .a = a0, .b = a1 }; return r; }
static inline struct __v4f __v4f_merge2_v2f(v2f a0, v2f a1) { struct __v4f r = { .a = a0, .b = a1 }; return r; }
static inline struct __v4i __v4i_merge2_v2i(v2i a0, v2i a1) { struct __v4i r = { .a = a0, .b = a1 }; return r; }
static inline struct __v4l __v4l_merge2_v2l(v2l a0, v2l a1) { struct __v4l r = { .a = a0, .b = a1 }; return r; }
static inline struct __v8d __v8d_merge2_v4d(v4d a0, v4d a1) { struct __v8d r = { .a = a0, .b = a1 }; return r; }
static inline struct __v8f __v8f_merge2_v4f(v4f a0, v4f a1) { struct __v8f r = { .a = a0, .b = a1 }; return r; }
static inline struct __v8i __v8i_merge2_v4i(v4i a0, v4i a1) { struct __v8i r = { .a = a0, .b = a1 }; return r; }
static inline struct __v8l __v8l_merge2_v4l(v4l a0, v4l a1) { struct __v8l r = { .a = a0, .b = a1 }; return r; }
static inline struct __v16f __v16f_merge2_v8f(v8f a0, v8f a1) { struct __v16f r = { .a = a0, .b = a1 }; return r; }
static inline struct __v16i __v16i_merge2_v8i(v8i a0, v8i a1) { struct __v16i r = { .a = a0, .b = a1 }; return r; }




static inline v2d compatible_v2d_merge_v1d(v1d low, v1d high) {
  PINTS_ALIGNED_ARRAY(double, v, 2, 2*sizeof(double));
  v1d_store(v, low);
  v1d_store(v + 1, high);
  return v2d_load(v);
}
static inline v2f compatible_v2f_merge_v1f(v1f low, v1f high) {
  PINTS_ALIGNED_ARRAY(float, v, 2, 2*sizeof(float));
  v1f_store(v, low);
  v1f_store(v + 1, high);
  return v2f_load(v);
}
static inline v2i compatible_v2i_merge_v1i(v1i low, v1i high) {
  PINTS_ALIGNED_ARRAY(int32_t, v, 2, 2*sizeof(int32_t));
  v1i_store(v, low);
  v1i_store(v + 1, high);
  return v2i_load(v);
}
static inline v2l compatible_v2l_merge_v1l(v1l low, v1l high) {
  PINTS_ALIGNED_ARRAY(int64_t, v, 2, 2*sizeof(int64_t));
  v1l_store(v, low);
  v1l_store(v + 1, high);
  return v2l_load(v);
}
static inline v4d compatible_v4d_merge_v2d(v2d low, v2d high) {
  PINTS_ALIGNED_ARRAY(double, v, 4, 4*sizeof(double));
  v2d_store(v, low);
  v2d_store(v + 2, high);
  return v4d_load(v);
}
static inline v4f compatible_v4f_merge_v2f(v2f low, v2f high) {
  PINTS_ALIGNED_ARRAY(float, v, 4, 4*sizeof(float));
  v2f_store(v, low);
  v2f_store(v + 2, high);
  return v4f_load(v);
}
static inline v4i compatible_v4i_merge_v2i(v2i low, v2i high) {
  PINTS_ALIGNED_ARRAY(int32_t, v, 4, 4*sizeof(int32_t));
  v2i_store(v, low);
  v2i_store(v + 2, high);
  return v4i_load(v);
}
static inline v4l compatible_v4l_merge_v2l(v2l low, v2l high) {
  PINTS_ALIGNED_ARRAY(int64_t, v, 4, 4*sizeof(int64_t));
  v2l_store(v, low);
  v2l_store(v + 2, high);
  return v4l_load(v);
}
static inline v8d compatible_v8d_merge_v4d(v4d low, v4d high) {
  PINTS_ALIGNED_ARRAY(double, v, 8, 8*sizeof(double));
  v4d_store(v, low);
  v4d_store(v + 4, high);
  return v8d_load(v);
}
static inline v8f compatible_v8f_merge_v4f(v4f low, v4f high) {
  PINTS_ALIGNED_ARRAY(float, v, 8, 8*sizeof(float));
  v4f_store(v, low);
  v4f_store(v + 4, high);
  return v8f_load(v);
}
static inline v8i compatible_v8i_merge_v4i(v4i low, v4i high) {
  PINTS_ALIGNED_ARRAY(int32_t, v, 8, 8*sizeof(int32_t));
  v4i_store(v, low);
  v4i_store(v + 4, high);
  return v8i_load(v);
}
static inline v8l compatible_v8l_merge_v4l(v4l low, v4l high) {
  PINTS_ALIGNED_ARRAY(int64_t, v, 8, 8*sizeof(int64_t));
  v4l_store(v, low);
  v4l_store(v + 4, high);
  return v8l_load(v);
}
static inline v16f compatible_v16f_merge_v8f(v8f low, v8f high) {
  PINTS_ALIGNED_ARRAY(float, v, 16, 16*sizeof(float));
  v8f_store(v, low);
  v8f_store(v + 8, high);
  return v16f_load(v);
}
static inline v16i compatible_v16i_merge_v8i(v8i low, v8i high) {
  PINTS_ALIGNED_ARRAY(int32_t, v, 16, 16*sizeof(int32_t));
  v8i_store(v, low);
  v8i_store(v + 8, high);
  return v16i_load(v);
}

/* HIGH and LOW manipulation */

static inline v1d __v1d_get_high_v2d(struct __v2d a) { return a.b; }
static inline v1f __v1f_get_high_v2f(struct __v2f a) { return a.b; }
static inline v1i __v1i_get_high_v2i(struct __v2i a) { return a.b; }
static inline v1l __v1l_get_high_v2l(struct __v2l a) { return a.b; }
static inline v2d __v2d_get_high_v4d(struct __v4d a) { return a.b; }
static inline v2f __v2f_get_high_v4f(struct __v4f a) { return a.b; }
static inline v2i __v2i_get_high_v4i(struct __v4i a) { return a.b; }
static inline v2l __v2l_get_high_v4l(struct __v4l a) { return a.b; }
static inline v4d __v4d_get_high_v8d(struct __v8d a) { return a.b; }
static inline v4f __v4f_get_high_v8f(struct __v8f a) { return a.b; }
static inline v4i __v4i_get_high_v8i(struct __v8i a) { return a.b; }
static inline v4l __v4l_get_high_v8l(struct __v8l a) { return a.b; }
static inline v8f __v8f_get_high_v16f(struct __v16f a) { return a.b; }
static inline v8i __v8i_get_high_v16i(struct __v16i a) { return a.b; }
static inline v1d compatible_v1d_get_low_v2d(v2d a) {
  PINTS_ALIGNED_ARRAY(double, v, 2, 2*sizeof(double));
  v2d_store(v, a);
  return v1d_load(v);
}
static inline v1f compatible_v1f_get_low_v2f(v2f a) {
  PINTS_ALIGNED_ARRAY(float, v, 2, 2*sizeof(float));
  v2f_store(v, a);
  return v1f_load(v);
}
static inline v1i compatible_v1i_get_low_v2i(v2i a) {
  PINTS_ALIGNED_ARRAY(int32_t, v, 2, 2*sizeof(int32_t));
  v2i_store(v, a);
  return v1i_load(v);
}
static inline v1l compatible_v1l_get_low_v2l(v2l a) {
  PINTS_ALIGNED_ARRAY(int64_t, v, 2, 2*sizeof(int64_t));
  v2l_store(v, a);
  return v1l_load(v);
}
static inline v2d compatible_v2d_get_low_v4d(v4d a) {
  PINTS_ALIGNED_ARRAY(double, v, 4, 4*sizeof(double));
  v4d_store(v, a);
  return v2d_load(v);
}
static inline v2f compatible_v2f_get_low_v4f(v4f a) {
  PINTS_ALIGNED_ARRAY(float, v, 4, 4*sizeof(float));
  v4f_store(v, a);
  return v2f_load(v);
}
static inline v2i compatible_v2i_get_low_v4i(v4i a) {
  PINTS_ALIGNED_ARRAY(int32_t, v, 4, 4*sizeof(int32_t));
  v4i_store(v, a);
  return v2i_load(v);
}
static inline v2l compatible_v2l_get_low_v4l(v4l a) {
  PINTS_ALIGNED_ARRAY(int64_t, v, 4, 4*sizeof(int64_t));
  v4l_store(v, a);
  return v2l_load(v);
}
static inline v4d compatible_v4d_get_low_v8d(v8d a) {
  PINTS_ALIGNED_ARRAY(double, v, 8, 8*sizeof(double));
  v8d_store(v, a);
  return v4d_load(v);
}
static inline v4f compatible_v4f_get_low_v8f(v8f a) {
  PINTS_ALIGNED_ARRAY(float, v, 8, 8*sizeof(float));
  v8f_store(v, a);
  return v4f_load(v);
}
static inline v4i compatible_v4i_get_low_v8i(v8i a) {
  PINTS_ALIGNED_ARRAY(int32_t, v, 8, 8*sizeof(int32_t));
  v8i_store(v, a);
  return v4i_load(v);
}
static inline v4l compatible_v4l_get_low_v8l(v8l a) {
  PINTS_ALIGNED_ARRAY(int64_t, v, 8, 8*sizeof(int64_t));
  v8l_store(v, a);
  return v4l_load(v);
}
static inline v8f compatible_v8f_get_low_v16f(v16f a) {
  PINTS_ALIGNED_ARRAY(float, v, 16, 16*sizeof(float));
  v16f_store(v, a);
  return v8f_load(v);
}
static inline v8i compatible_v8i_get_low_v16i(v16i a) {
  PINTS_ALIGNED_ARRAY(int32_t, v, 16, 16*sizeof(int32_t));
  v16i_store(v, a);
  return v8i_load(v);
}
static inline v1d compatible_v1d_get_high_v2d(v2d a) {
  PINTS_ALIGNED_ARRAY(double, v, 2, 2*sizeof(double));
  v2d_store(v, a);
  return v1d_load(v+1);
}
static inline v1f compatible_v1f_get_high_v2f(v2f a) {
  PINTS_ALIGNED_ARRAY(float, v, 2, 2*sizeof(float));
  v2f_store(v, a);
  return v1f_load(v+1);
}
static inline v1i compatible_v1i_get_high_v2i(v2i a) {
  PINTS_ALIGNED_ARRAY(int32_t, v, 2, 2*sizeof(int32_t));
  v2i_store(v, a);
  return v1i_load(v+1);
}
static inline v1l compatible_v1l_get_high_v2l(v2l a) {
  PINTS_ALIGNED_ARRAY(int64_t, v, 2, 2*sizeof(int64_t));
  v2l_store(v, a);
  return v1l_load(v+1);
}
static inline v2d compatible_v2d_get_high_v4d(v4d a) {
  PINTS_ALIGNED_ARRAY(double, v, 4, 4*sizeof(double));
  v4d_store(v, a);
  return v2d_load(v+2);
}
static inline v2f compatible_v2f_get_high_v4f(v4f a) {
  PINTS_ALIGNED_ARRAY(float, v, 4, 4*sizeof(float));
  v4f_store(v, a);
  return v2f_load(v+2);
}
static inline v2i compatible_v2i_get_high_v4i(v4i a) {
  PINTS_ALIGNED_ARRAY(int32_t, v, 4, 4*sizeof(int32_t));
  v4i_store(v, a);
  return v2i_load(v+2);
}
static inline v2l compatible_v2l_get_high_v4l(v4l a) {
  PINTS_ALIGNED_ARRAY(int64_t, v, 4, 4*sizeof(int64_t));
  v4l_store(v, a);
  return v2l_load(v+2);
}
static inline v4d compatible_v4d_get_high_v8d(v8d a) {
  PINTS_ALIGNED_ARRAY(double, v, 8, 8*sizeof(double));
  v8d_store(v, a);
  return v4d_load(v+4);
}
static inline v4f compatible_v4f_get_high_v8f(v8f a) {
  PINTS_ALIGNED_ARRAY(float, v, 8, 8*sizeof(float));
  v8f_store(v, a);
  return v4f_load(v+4);
}
static inline v4i compatible_v4i_get_high_v8i(v8i a) {
  PINTS_ALIGNED_ARRAY(int32_t, v, 8, 8*sizeof(int32_t));
  v8i_store(v, a);
  return v4i_load(v+4);
}
static inline v4l compatible_v4l_get_high_v8l(v8l a) {
  PINTS_ALIGNED_ARRAY(int64_t, v, 8, 8*sizeof(int64_t));
  v8l_store(v, a);
  return v4l_load(v+4);
}
static inline v8f compatible_v8f_get_high_v16f(v16f a) {
  PINTS_ALIGNED_ARRAY(float, v, 16, 16*sizeof(float));
  v16f_store(v, a);
  return v8f_load(v+8);
}
static inline v8i compatible_v8i_get_high_v16i(v16i a) {
  PINTS_ALIGNED_ARRAY(int32_t, v, 16, 16*sizeof(int32_t));
  v16i_store(v, a);
  return v8i_load(v+8);
}

/* BLENDS */




/* SHUFFLES */











/* PRINTS */

static inline void __v1d_fprintf(FILE *file, v1d a, const char* format) {
  int i, comma = 0;
  PINTS_ALIGNED_ARRAY(double, v, 1, 1*sizeof(double));
  v1d_store(v, a);
  for (i = 0; i < 1; ++i) {
    if (comma) fprintf(file, "\t");
    comma = 1;
    fprintf(file, format, v[i]);
  }
}
static inline void __v1f_fprintf(FILE *file, v1f a, const char* format) {
  int i, comma = 0;
  PINTS_ALIGNED_ARRAY(float, v, 1, 1*sizeof(float));
  v1f_store(v, a);
  for (i = 0; i < 1; ++i) {
    if (comma) fprintf(file, "\t");
    comma = 1;
    fprintf(file, format, v[i]);
  }
}
static inline void __v1i_fprintf(FILE *file, v1i a, const char* format) {
  int i, comma = 0;
  PINTS_ALIGNED_ARRAY(int32_t, v, 1, 1*sizeof(int32_t));
  v1i_store(v, a);
  for (i = 0; i < 1; ++i) {
    if (comma) fprintf(file, "\t");
    comma = 1;
    fprintf(file, format, v[i]);
  }
}
static inline void __v1l_fprintf(FILE *file, v1l a, const char* format) {
  int i, comma = 0;
  PINTS_ALIGNED_ARRAY(int64_t, v, 1, 1*sizeof(int64_t));
  v1l_store(v, a);
  for (i = 0; i < 1; ++i) {
    if (comma) fprintf(file, "\t");
    comma = 1;
    fprintf(file, format, v[i]);
  }
}
static inline void __v2d_fprintf(FILE *file, v2d a, const char* format) {
  int i, comma = 0;
  PINTS_ALIGNED_ARRAY(double, v, 2, 2*sizeof(double));
  v2d_store(v, a);
  for (i = 0; i < 2; ++i) {
    if (comma) fprintf(file, "\t");
    comma = 1;
    fprintf(file, format, v[i]);
  }
}
static inline void __v2f_fprintf(FILE *file, v2f a, const char* format) {
  int i, comma = 0;
  PINTS_ALIGNED_ARRAY(float, v, 2, 2*sizeof(float));
  v2f_store(v, a);
  for (i = 0; i < 2; ++i) {
    if (comma) fprintf(file, "\t");
    comma = 1;
    fprintf(file, format, v[i]);
  }
}
static inline void __v2i_fprintf(FILE *file, v2i a, const char* format) {
  int i, comma = 0;
  PINTS_ALIGNED_ARRAY(int32_t, v, 2, 2*sizeof(int32_t));
  v2i_store(v, a);
  for (i = 0; i < 2; ++i) {
    if (comma) fprintf(file, "\t");
    comma = 1;
    fprintf(file, format, v[i]);
  }
}
static inline void __v2l_fprintf(FILE *file, v2l a, const char* format) {
  int i, comma = 0;
  PINTS_ALIGNED_ARRAY(int64_t, v, 2, 2*sizeof(int64_t));
  v2l_store(v, a);
  for (i = 0; i < 2; ++i) {
    if (comma) fprintf(file, "\t");
    comma = 1;
    fprintf(file, format, v[i]);
  }
}
static inline void __v4d_fprintf(FILE *file, v4d a, const char* format) {
  int i, comma = 0;
  PINTS_ALIGNED_ARRAY(double, v, 4, 4*sizeof(double));
  v4d_store(v, a);
  for (i = 0; i < 4; ++i) {
    if (comma) fprintf(file, "\t");
    comma = 1;
    fprintf(file, format, v[i]);
  }
}
static inline void __v4f_fprintf(FILE *file, v4f a, const char* format) {
  int i, comma = 0;
  PINTS_ALIGNED_ARRAY(float, v, 4, 4*sizeof(float));
  v4f_store(v, a);
  for (i = 0; i < 4; ++i) {
    if (comma) fprintf(file, "\t");
    comma = 1;
    fprintf(file, format, v[i]);
  }
}
static inline void __v4i_fprintf(FILE *file, v4i a, const char* format) {
  int i, comma = 0;
  PINTS_ALIGNED_ARRAY(int32_t, v, 4, 4*sizeof(int32_t));
  v4i_store(v, a);
  for (i = 0; i < 4; ++i) {
    if (comma) fprintf(file, "\t");
    comma = 1;
    fprintf(file, format, v[i]);
  }
}
static inline void __v4l_fprintf(FILE *file, v4l a, const char* format) {
  int i, comma = 0;
  PINTS_ALIGNED_ARRAY(int64_t, v, 4, 4*sizeof(int64_t));
  v4l_store(v, a);
  for (i = 0; i < 4; ++i) {
    if (comma) fprintf(file, "\t");
    comma = 1;
    fprintf(file, format, v[i]);
  }
}
static inline void __v8d_fprintf(FILE *file, v8d a, const char* format) {
  int i, comma = 0;
  PINTS_ALIGNED_ARRAY(double, v, 8, 8*sizeof(double));
  v8d_store(v, a);
  for (i = 0; i < 8; ++i) {
    if (comma) fprintf(file, "\t");
    comma = 1;
    fprintf(file, format, v[i]);
  }
}
static inline void __v8f_fprintf(FILE *file, v8f a, const char* format) {
  int i, comma = 0;
  PINTS_ALIGNED_ARRAY(float, v, 8, 8*sizeof(float));
  v8f_store(v, a);
  for (i = 0; i < 8; ++i) {
    if (comma) fprintf(file, "\t");
    comma = 1;
    fprintf(file, format, v[i]);
  }
}
static inline void __v8i_fprintf(FILE *file, v8i a, const char* format) {
  int i, comma = 0;
  PINTS_ALIGNED_ARRAY(int32_t, v, 8, 8*sizeof(int32_t));
  v8i_store(v, a);
  for (i = 0; i < 8; ++i) {
    if (comma) fprintf(file, "\t");
    comma = 1;
    fprintf(file, format, v[i]);
  }
}
static inline void __v8l_fprintf(FILE *file, v8l a, const char* format) {
  int i, comma = 0;
  PINTS_ALIGNED_ARRAY(int64_t, v, 8, 8*sizeof(int64_t));
  v8l_store(v, a);
  for (i = 0; i < 8; ++i) {
    if (comma) fprintf(file, "\t");
    comma = 1;
    fprintf(file, format, v[i]);
  }
}
static inline void __v16f_fprintf(FILE *file, v16f a, const char* format) {
  int i, comma = 0;
  PINTS_ALIGNED_ARRAY(float, v, 16, 16*sizeof(float));
  v16f_store(v, a);
  for (i = 0; i < 16; ++i) {
    if (comma) fprintf(file, "\t");
    comma = 1;
    fprintf(file, format, v[i]);
  }
}
static inline void __v16i_fprintf(FILE *file, v16i a, const char* format) {
  int i, comma = 0;
  PINTS_ALIGNED_ARRAY(int32_t, v, 16, 16*sizeof(int32_t));
  v16i_store(v, a);
  for (i = 0; i < 16; ++i) {
    if (comma) fprintf(file, "\t");
    comma = 1;
    fprintf(file, format, v[i]);
  }
}




static inline void __v1d_rfprintf(FILE *file, v1d a, const char* format) {
  int i, comma = 0;
  PINTS_ALIGNED_ARRAY(double, v, 1, 1*sizeof(double));
  v1d_store(v, a);
  for (i = 0; i < 1; ++i) {
    if (comma) fprintf(file, "\t");
    comma = 1;
    fprintf(file, format, v[0 - i]);
  }
}
static inline void __v1f_rfprintf(FILE *file, v1f a, const char* format) {
  int i, comma = 0;
  PINTS_ALIGNED_ARRAY(float, v, 1, 1*sizeof(float));
  v1f_store(v, a);
  for (i = 0; i < 1; ++i) {
    if (comma) fprintf(file, "\t");
    comma = 1;
    fprintf(file, format, v[0 - i]);
  }
}
static inline void __v1i_rfprintf(FILE *file, v1i a, const char* format) {
  int i, comma = 0;
  PINTS_ALIGNED_ARRAY(int32_t, v, 1, 1*sizeof(int32_t));
  v1i_store(v, a);
  for (i = 0; i < 1; ++i) {
    if (comma) fprintf(file, "\t");
    comma = 1;
    fprintf(file, format, v[0 - i]);
  }
}
static inline void __v1l_rfprintf(FILE *file, v1l a, const char* format) {
  int i, comma = 0;
  PINTS_ALIGNED_ARRAY(int64_t, v, 1, 1*sizeof(int64_t));
  v1l_store(v, a);
  for (i = 0; i < 1; ++i) {
    if (comma) fprintf(file, "\t");
    comma = 1;
    fprintf(file, format, v[0 - i]);
  }
}
static inline void __v2d_rfprintf(FILE *file, v2d a, const char* format) {
  int i, comma = 0;
  PINTS_ALIGNED_ARRAY(double, v, 2, 2*sizeof(double));
  v2d_store(v, a);
  for (i = 0; i < 2; ++i) {
    if (comma) fprintf(file, "\t");
    comma = 1;
    fprintf(file, format, v[1 - i]);
  }
}
static inline void __v2f_rfprintf(FILE *file, v2f a, const char* format) {
  int i, comma = 0;
  PINTS_ALIGNED_ARRAY(float, v, 2, 2*sizeof(float));
  v2f_store(v, a);
  for (i = 0; i < 2; ++i) {
    if (comma) fprintf(file, "\t");
    comma = 1;
    fprintf(file, format, v[1 - i]);
  }
}
static inline void __v2i_rfprintf(FILE *file, v2i a, const char* format) {
  int i, comma = 0;
  PINTS_ALIGNED_ARRAY(int32_t, v, 2, 2*sizeof(int32_t));
  v2i_store(v, a);
  for (i = 0; i < 2; ++i) {
    if (comma) fprintf(file, "\t");
    comma = 1;
    fprintf(file, format, v[1 - i]);
  }
}
static inline void __v2l_rfprintf(FILE *file, v2l a, const char* format) {
  int i, comma = 0;
  PINTS_ALIGNED_ARRAY(int64_t, v, 2, 2*sizeof(int64_t));
  v2l_store(v, a);
  for (i = 0; i < 2; ++i) {
    if (comma) fprintf(file, "\t");
    comma = 1;
    fprintf(file, format, v[1 - i]);
  }
}
static inline void __v4d_rfprintf(FILE *file, v4d a, const char* format) {
  int i, comma = 0;
  PINTS_ALIGNED_ARRAY(double, v, 4, 4*sizeof(double));
  v4d_store(v, a);
  for (i = 0; i < 4; ++i) {
    if (comma) fprintf(file, "\t");
    comma = 1;
    fprintf(file, format, v[3 - i]);
  }
}
static inline void __v4f_rfprintf(FILE *file, v4f a, const char* format) {
  int i, comma = 0;
  PINTS_ALIGNED_ARRAY(float, v, 4, 4*sizeof(float));
  v4f_store(v, a);
  for (i = 0; i < 4; ++i) {
    if (comma) fprintf(file, "\t");
    comma = 1;
    fprintf(file, format, v[3 - i]);
  }
}
static inline void __v4i_rfprintf(FILE *file, v4i a, const char* format) {
  int i, comma = 0;
  PINTS_ALIGNED_ARRAY(int32_t, v, 4, 4*sizeof(int32_t));
  v4i_store(v, a);
  for (i = 0; i < 4; ++i) {
    if (comma) fprintf(file, "\t");
    comma = 1;
    fprintf(file, format, v[3 - i]);
  }
}
static inline void __v4l_rfprintf(FILE *file, v4l a, const char* format) {
  int i, comma = 0;
  PINTS_ALIGNED_ARRAY(int64_t, v, 4, 4*sizeof(int64_t));
  v4l_store(v, a);
  for (i = 0; i < 4; ++i) {
    if (comma) fprintf(file, "\t");
    comma = 1;
    fprintf(file, format, v[3 - i]);
  }
}
static inline void __v8d_rfprintf(FILE *file, v8d a, const char* format) {
  int i, comma = 0;
  PINTS_ALIGNED_ARRAY(double, v, 8, 8*sizeof(double));
  v8d_store(v, a);
  for (i = 0; i < 8; ++i) {
    if (comma) fprintf(file, "\t");
    comma = 1;
    fprintf(file, format, v[7 - i]);
  }
}
static inline void __v8f_rfprintf(FILE *file, v8f a, const char* format) {
  int i, comma = 0;
  PINTS_ALIGNED_ARRAY(float, v, 8, 8*sizeof(float));
  v8f_store(v, a);
  for (i = 0; i < 8; ++i) {
    if (comma) fprintf(file, "\t");
    comma = 1;
    fprintf(file, format, v[7 - i]);
  }
}
static inline void __v8i_rfprintf(FILE *file, v8i a, const char* format) {
  int i, comma = 0;
  PINTS_ALIGNED_ARRAY(int32_t, v, 8, 8*sizeof(int32_t));
  v8i_store(v, a);
  for (i = 0; i < 8; ++i) {
    if (comma) fprintf(file, "\t");
    comma = 1;
    fprintf(file, format, v[7 - i]);
  }
}
static inline void __v8l_rfprintf(FILE *file, v8l a, const char* format) {
  int i, comma = 0;
  PINTS_ALIGNED_ARRAY(int64_t, v, 8, 8*sizeof(int64_t));
  v8l_store(v, a);
  for (i = 0; i < 8; ++i) {
    if (comma) fprintf(file, "\t");
    comma = 1;
    fprintf(file, format, v[7 - i]);
  }
}
static inline void __v16f_rfprintf(FILE *file, v16f a, const char* format) {
  int i, comma = 0;
  PINTS_ALIGNED_ARRAY(float, v, 16, 16*sizeof(float));
  v16f_store(v, a);
  for (i = 0; i < 16; ++i) {
    if (comma) fprintf(file, "\t");
    comma = 1;
    fprintf(file, format, v[15 - i]);
  }
}
static inline void __v16i_rfprintf(FILE *file, v16i a, const char* format) {
  int i, comma = 0;
  PINTS_ALIGNED_ARRAY(int32_t, v, 16, 16*sizeof(int32_t));
  v16i_store(v, a);
  for (i = 0; i < 16; ++i) {
    if (comma) fprintf(file, "\t");
    comma = 1;
    fprintf(file, format, v[15 - i]);
  }
}




/* CASTS */

static inline struct __v2d __v2d_cast_v1d(v1d a) { struct __v2d r = { .a = a }; return r; }
static inline struct __v2f __v2f_cast_v1f(v1f a) { struct __v2f r = { .a = a }; return r; }
static inline struct __v2i __v2i_cast_v1i(v1i a) { struct __v2i r = { .a = a }; return r; }
static inline struct __v2l __v2l_cast_v1l(v1l a) { struct __v2l r = { .a = a }; return r; }
static inline v1d __v1d_cast_v2d(struct __v2d a) { return a.a; }
static inline struct __v4d __v4d_cast_v2d(v2d a) { struct __v4d r = { .a = a }; return r; }
static inline v1f __v1f_cast_v2f(struct __v2f a) { return a.a; }
static inline struct __v4f __v4f_cast_v2f(v2f a) { struct __v4f r = { .a = a }; return r; }
static inline v1i __v1i_cast_v2i(struct __v2i a) { return a.a; }
static inline struct __v4i __v4i_cast_v2i(v2i a) { struct __v4i r = { .a = a }; return r; }
static inline v1l __v1l_cast_v2l(struct __v2l a) { return a.a; }
static inline struct __v4l __v4l_cast_v2l(v2l a) { struct __v4l r = { .a = a }; return r; }
static inline v2d __v2d_cast_v4d(struct __v4d a) { return a.a; }
static inline struct __v8d __v8d_cast_v4d(v4d a) { struct __v8d r = { .a = a }; return r; }
static inline v2f __v2f_cast_v4f(struct __v4f a) { return a.a; }
static inline struct __v8f __v8f_cast_v4f(v4f a) { struct __v8f r = { .a = a }; return r; }
static inline v2i __v2i_cast_v4i(struct __v4i a) { return a.a; }
static inline struct __v8i __v8i_cast_v4i(v4i a) { struct __v8i r = { .a = a }; return r; }
static inline v2l __v2l_cast_v4l(struct __v4l a) { return a.a; }
static inline struct __v8l __v8l_cast_v4l(v4l a) { struct __v8l r = { .a = a }; return r; }
static inline v4d __v4d_cast_v8d(struct __v8d a) { return a.a; }
static inline v4f __v4f_cast_v8f(struct __v8f a) { return a.a; }
static inline struct __v16f __v16f_cast_v8f(v8f a) { struct __v16f r = { .a = a }; return r; }
static inline v4i __v4i_cast_v8i(struct __v8i a) { return a.a; }
static inline struct __v16i __v16i_cast_v8i(v8i a) { struct __v16i r = { .a = a }; return r; }
static inline v4l __v4l_cast_v8l(struct __v8l a) { return a.a; }
static inline v8f __v8f_cast_v16f(struct __v16f a) { return a.a; }
static inline v8i __v8i_cast_v16i(struct __v16i a) { return a.a; }


/* CONVERTS */

static inline v1f __v1f_cvt_v1d(v1d a) { float sv1f; double sv1d; v1d_store(&sv1d, a); sv1f = (float) sv1d; return v1f_load(&sv1f); }
static inline v1i __v1i_cvt_v1d(v1d a) { int32_t sv1i; double sv1d; v1d_store(&sv1d, a); sv1i = (int32_t) sv1d; return v1i_load(&sv1i); }
static inline v1l __v1l_cvt_v1d(v1d a) { int64_t sv1l; double sv1d; v1d_store(&sv1d, a); sv1l = (int64_t) sv1d; return v1l_load(&sv1l); }
static inline v1d __v1d_cvt_v1f(v1f a) { double sv1d; float sv1f; v1f_store(&sv1f, a); sv1d = (double) sv1f; return v1d_load(&sv1d); }
static inline v1i __v1i_cvt_v1f(v1f a) { int32_t sv1i; float sv1f; v1f_store(&sv1f, a); sv1i = (int32_t) sv1f; return v1i_load(&sv1i); }
static inline v1l __v1l_cvt_v1f(v1f a) { int64_t sv1l; float sv1f; v1f_store(&sv1f, a); sv1l = (int64_t) sv1f; return v1l_load(&sv1l); }
static inline v1d __v1d_cvt_v1i(v1i a) { double sv1d; int32_t sv1i; v1i_store(&sv1i, a); sv1d = (double) sv1i; return v1d_load(&sv1d); }
static inline v1f __v1f_cvt_v1i(v1i a) { float sv1f; int32_t sv1i; v1i_store(&sv1i, a); sv1f = (float) sv1i; return v1f_load(&sv1f); }
static inline v1l __v1l_cvt_v1i(v1i a) { int64_t sv1l; int32_t sv1i; v1i_store(&sv1i, a); sv1l = (int64_t) sv1i; return v1l_load(&sv1l); }
static inline v1d __v1d_cvt_v1l(v1l a) { double sv1d; int64_t sv1l; v1l_store(&sv1l, a); sv1d = (double) sv1l; return v1d_load(&sv1d); }
static inline v1f __v1f_cvt_v1l(v1l a) { float sv1f; int64_t sv1l; v1l_store(&sv1l, a); sv1f = (float) sv1l; return v1f_load(&sv1f); }
static inline v1i __v1i_cvt_v1l(v1l a) { int32_t sv1i; int64_t sv1l; v1l_store(&sv1l, a); sv1i = (int32_t) sv1l; return v1i_load(&sv1i); }


static inline double __sd_cvt_v1d(v1d a) { double sv1d; v1d_store(&sv1d, a); return (double) sv1d; }
static inline float __sf_cvt_v1f(v1f a) { float sv1f; v1f_store(&sv1f, a); return (float) sv1f; }
static inline int32_t __si_cvt_v1i(v1i a) { int32_t sv1i; v1i_store(&sv1i, a); return (int32_t) sv1i; }
static inline int64_t __sl_cvt_v1l(v1l a) { int64_t sv1l; v1l_store(&sv1l, a); return (int64_t) sv1l; }




/* compatible CONVERTS */
static inline v1d compatible_v1d_cvt_v1d(v1d a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 1, 1*sizeof(double));
  PINTS_ALIGNED_ARRAY(double, vfrom, 1, 1*sizeof(double));
  v1d_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (double) vfrom[i];
  return v1d_load(vto);
}
static inline v1f compatible_v1f_cvt_v1d(v1d a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 1, 1*sizeof(float));
  PINTS_ALIGNED_ARRAY(double, vfrom, 1, 1*sizeof(double));
  v1d_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (float) vfrom[i];
  return v1f_load(vto);
}
static inline v1i compatible_v1i_cvt_v1d(v1d a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 1, 1*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(double, vfrom, 1, 1*sizeof(double));
  v1d_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int32_t) vfrom[i];
  return v1i_load(vto);
}
static inline v1l compatible_v1l_cvt_v1d(v1d a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 1, 1*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(double, vfrom, 1, 1*sizeof(double));
  v1d_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int64_t) vfrom[i];
  return v1l_load(vto);
}
static inline v2d compatible_v2d_cvt_v1d(v1d a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 2, 2*sizeof(double));
  PINTS_ALIGNED_ARRAY(double, vfrom, 1, 1*sizeof(double));
  v1d_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (double) vfrom[i];
  return v2d_load(vto);
}
static inline v2f compatible_v2f_cvt_v1d(v1d a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 2, 2*sizeof(float));
  PINTS_ALIGNED_ARRAY(double, vfrom, 1, 1*sizeof(double));
  v1d_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (float) vfrom[i];
  return v2f_load(vto);
}
static inline v2i compatible_v2i_cvt_v1d(v1d a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 2, 2*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(double, vfrom, 1, 1*sizeof(double));
  v1d_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int32_t) vfrom[i];
  return v2i_load(vto);
}
static inline v2l compatible_v2l_cvt_v1d(v1d a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 2, 2*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(double, vfrom, 1, 1*sizeof(double));
  v1d_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int64_t) vfrom[i];
  return v2l_load(vto);
}
static inline v4d compatible_v4d_cvt_v1d(v1d a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 4, 4*sizeof(double));
  PINTS_ALIGNED_ARRAY(double, vfrom, 1, 1*sizeof(double));
  v1d_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (double) vfrom[i];
  return v4d_load(vto);
}
static inline v4f compatible_v4f_cvt_v1d(v1d a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 4, 4*sizeof(float));
  PINTS_ALIGNED_ARRAY(double, vfrom, 1, 1*sizeof(double));
  v1d_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (float) vfrom[i];
  return v4f_load(vto);
}
static inline v4i compatible_v4i_cvt_v1d(v1d a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 4, 4*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(double, vfrom, 1, 1*sizeof(double));
  v1d_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int32_t) vfrom[i];
  return v4i_load(vto);
}
static inline v4l compatible_v4l_cvt_v1d(v1d a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 4, 4*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(double, vfrom, 1, 1*sizeof(double));
  v1d_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int64_t) vfrom[i];
  return v4l_load(vto);
}
static inline v8d compatible_v8d_cvt_v1d(v1d a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 8, 8*sizeof(double));
  PINTS_ALIGNED_ARRAY(double, vfrom, 1, 1*sizeof(double));
  v1d_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (double) vfrom[i];
  return v8d_load(vto);
}
static inline v8f compatible_v8f_cvt_v1d(v1d a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 8, 8*sizeof(float));
  PINTS_ALIGNED_ARRAY(double, vfrom, 1, 1*sizeof(double));
  v1d_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (float) vfrom[i];
  return v8f_load(vto);
}
static inline v8i compatible_v8i_cvt_v1d(v1d a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 8, 8*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(double, vfrom, 1, 1*sizeof(double));
  v1d_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int32_t) vfrom[i];
  return v8i_load(vto);
}
static inline v8l compatible_v8l_cvt_v1d(v1d a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 8, 8*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(double, vfrom, 1, 1*sizeof(double));
  v1d_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int64_t) vfrom[i];
  return v8l_load(vto);
}
static inline v16f compatible_v16f_cvt_v1d(v1d a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 16, 16*sizeof(float));
  PINTS_ALIGNED_ARRAY(double, vfrom, 1, 1*sizeof(double));
  v1d_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (float) vfrom[i];
  return v16f_load(vto);
}
static inline v16i compatible_v16i_cvt_v1d(v1d a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 16, 16*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(double, vfrom, 1, 1*sizeof(double));
  v1d_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int32_t) vfrom[i];
  return v16i_load(vto);
}
static inline v1d compatible_v1d_cvt_v1f(v1f a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 1, 1*sizeof(double));
  PINTS_ALIGNED_ARRAY(float, vfrom, 1, 1*sizeof(float));
  v1f_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (double) vfrom[i];
  return v1d_load(vto);
}
static inline v1f compatible_v1f_cvt_v1f(v1f a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 1, 1*sizeof(float));
  PINTS_ALIGNED_ARRAY(float, vfrom, 1, 1*sizeof(float));
  v1f_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (float) vfrom[i];
  return v1f_load(vto);
}
static inline v1i compatible_v1i_cvt_v1f(v1f a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 1, 1*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(float, vfrom, 1, 1*sizeof(float));
  v1f_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int32_t) vfrom[i];
  return v1i_load(vto);
}
static inline v1l compatible_v1l_cvt_v1f(v1f a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 1, 1*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(float, vfrom, 1, 1*sizeof(float));
  v1f_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int64_t) vfrom[i];
  return v1l_load(vto);
}
static inline v2d compatible_v2d_cvt_v1f(v1f a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 2, 2*sizeof(double));
  PINTS_ALIGNED_ARRAY(float, vfrom, 1, 1*sizeof(float));
  v1f_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (double) vfrom[i];
  return v2d_load(vto);
}
static inline v2f compatible_v2f_cvt_v1f(v1f a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 2, 2*sizeof(float));
  PINTS_ALIGNED_ARRAY(float, vfrom, 1, 1*sizeof(float));
  v1f_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (float) vfrom[i];
  return v2f_load(vto);
}
static inline v2i compatible_v2i_cvt_v1f(v1f a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 2, 2*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(float, vfrom, 1, 1*sizeof(float));
  v1f_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int32_t) vfrom[i];
  return v2i_load(vto);
}
static inline v2l compatible_v2l_cvt_v1f(v1f a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 2, 2*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(float, vfrom, 1, 1*sizeof(float));
  v1f_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int64_t) vfrom[i];
  return v2l_load(vto);
}
static inline v4d compatible_v4d_cvt_v1f(v1f a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 4, 4*sizeof(double));
  PINTS_ALIGNED_ARRAY(float, vfrom, 1, 1*sizeof(float));
  v1f_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (double) vfrom[i];
  return v4d_load(vto);
}
static inline v4f compatible_v4f_cvt_v1f(v1f a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 4, 4*sizeof(float));
  PINTS_ALIGNED_ARRAY(float, vfrom, 1, 1*sizeof(float));
  v1f_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (float) vfrom[i];
  return v4f_load(vto);
}
static inline v4i compatible_v4i_cvt_v1f(v1f a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 4, 4*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(float, vfrom, 1, 1*sizeof(float));
  v1f_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int32_t) vfrom[i];
  return v4i_load(vto);
}
static inline v4l compatible_v4l_cvt_v1f(v1f a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 4, 4*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(float, vfrom, 1, 1*sizeof(float));
  v1f_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int64_t) vfrom[i];
  return v4l_load(vto);
}
static inline v8d compatible_v8d_cvt_v1f(v1f a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 8, 8*sizeof(double));
  PINTS_ALIGNED_ARRAY(float, vfrom, 1, 1*sizeof(float));
  v1f_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (double) vfrom[i];
  return v8d_load(vto);
}
static inline v8f compatible_v8f_cvt_v1f(v1f a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 8, 8*sizeof(float));
  PINTS_ALIGNED_ARRAY(float, vfrom, 1, 1*sizeof(float));
  v1f_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (float) vfrom[i];
  return v8f_load(vto);
}
static inline v8i compatible_v8i_cvt_v1f(v1f a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 8, 8*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(float, vfrom, 1, 1*sizeof(float));
  v1f_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int32_t) vfrom[i];
  return v8i_load(vto);
}
static inline v8l compatible_v8l_cvt_v1f(v1f a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 8, 8*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(float, vfrom, 1, 1*sizeof(float));
  v1f_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int64_t) vfrom[i];
  return v8l_load(vto);
}
static inline v16f compatible_v16f_cvt_v1f(v1f a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 16, 16*sizeof(float));
  PINTS_ALIGNED_ARRAY(float, vfrom, 1, 1*sizeof(float));
  v1f_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (float) vfrom[i];
  return v16f_load(vto);
}
static inline v16i compatible_v16i_cvt_v1f(v1f a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 16, 16*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(float, vfrom, 1, 1*sizeof(float));
  v1f_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int32_t) vfrom[i];
  return v16i_load(vto);
}
static inline v1d compatible_v1d_cvt_v1i(v1i a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 1, 1*sizeof(double));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 1, 1*sizeof(int32_t));
  v1i_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (double) vfrom[i];
  return v1d_load(vto);
}
static inline v1f compatible_v1f_cvt_v1i(v1i a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 1, 1*sizeof(float));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 1, 1*sizeof(int32_t));
  v1i_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (float) vfrom[i];
  return v1f_load(vto);
}
static inline v1i compatible_v1i_cvt_v1i(v1i a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 1, 1*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 1, 1*sizeof(int32_t));
  v1i_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int32_t) vfrom[i];
  return v1i_load(vto);
}
static inline v1l compatible_v1l_cvt_v1i(v1i a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 1, 1*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 1, 1*sizeof(int32_t));
  v1i_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int64_t) vfrom[i];
  return v1l_load(vto);
}
static inline v2d compatible_v2d_cvt_v1i(v1i a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 2, 2*sizeof(double));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 1, 1*sizeof(int32_t));
  v1i_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (double) vfrom[i];
  return v2d_load(vto);
}
static inline v2f compatible_v2f_cvt_v1i(v1i a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 2, 2*sizeof(float));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 1, 1*sizeof(int32_t));
  v1i_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (float) vfrom[i];
  return v2f_load(vto);
}
static inline v2i compatible_v2i_cvt_v1i(v1i a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 2, 2*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 1, 1*sizeof(int32_t));
  v1i_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int32_t) vfrom[i];
  return v2i_load(vto);
}
static inline v2l compatible_v2l_cvt_v1i(v1i a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 2, 2*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 1, 1*sizeof(int32_t));
  v1i_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int64_t) vfrom[i];
  return v2l_load(vto);
}
static inline v4d compatible_v4d_cvt_v1i(v1i a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 4, 4*sizeof(double));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 1, 1*sizeof(int32_t));
  v1i_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (double) vfrom[i];
  return v4d_load(vto);
}
static inline v4f compatible_v4f_cvt_v1i(v1i a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 4, 4*sizeof(float));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 1, 1*sizeof(int32_t));
  v1i_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (float) vfrom[i];
  return v4f_load(vto);
}
static inline v4i compatible_v4i_cvt_v1i(v1i a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 4, 4*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 1, 1*sizeof(int32_t));
  v1i_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int32_t) vfrom[i];
  return v4i_load(vto);
}
static inline v4l compatible_v4l_cvt_v1i(v1i a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 4, 4*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 1, 1*sizeof(int32_t));
  v1i_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int64_t) vfrom[i];
  return v4l_load(vto);
}
static inline v8d compatible_v8d_cvt_v1i(v1i a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 8, 8*sizeof(double));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 1, 1*sizeof(int32_t));
  v1i_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (double) vfrom[i];
  return v8d_load(vto);
}
static inline v8f compatible_v8f_cvt_v1i(v1i a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 8, 8*sizeof(float));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 1, 1*sizeof(int32_t));
  v1i_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (float) vfrom[i];
  return v8f_load(vto);
}
static inline v8i compatible_v8i_cvt_v1i(v1i a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 8, 8*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 1, 1*sizeof(int32_t));
  v1i_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int32_t) vfrom[i];
  return v8i_load(vto);
}
static inline v8l compatible_v8l_cvt_v1i(v1i a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 8, 8*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 1, 1*sizeof(int32_t));
  v1i_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int64_t) vfrom[i];
  return v8l_load(vto);
}
static inline v16f compatible_v16f_cvt_v1i(v1i a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 16, 16*sizeof(float));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 1, 1*sizeof(int32_t));
  v1i_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (float) vfrom[i];
  return v16f_load(vto);
}
static inline v16i compatible_v16i_cvt_v1i(v1i a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 16, 16*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 1, 1*sizeof(int32_t));
  v1i_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int32_t) vfrom[i];
  return v16i_load(vto);
}
static inline v1d compatible_v1d_cvt_v1l(v1l a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 1, 1*sizeof(double));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 1, 1*sizeof(int64_t));
  v1l_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (double) vfrom[i];
  return v1d_load(vto);
}
static inline v1f compatible_v1f_cvt_v1l(v1l a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 1, 1*sizeof(float));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 1, 1*sizeof(int64_t));
  v1l_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (float) vfrom[i];
  return v1f_load(vto);
}
static inline v1i compatible_v1i_cvt_v1l(v1l a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 1, 1*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 1, 1*sizeof(int64_t));
  v1l_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int32_t) vfrom[i];
  return v1i_load(vto);
}
static inline v1l compatible_v1l_cvt_v1l(v1l a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 1, 1*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 1, 1*sizeof(int64_t));
  v1l_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int64_t) vfrom[i];
  return v1l_load(vto);
}
static inline v2d compatible_v2d_cvt_v1l(v1l a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 2, 2*sizeof(double));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 1, 1*sizeof(int64_t));
  v1l_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (double) vfrom[i];
  return v2d_load(vto);
}
static inline v2f compatible_v2f_cvt_v1l(v1l a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 2, 2*sizeof(float));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 1, 1*sizeof(int64_t));
  v1l_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (float) vfrom[i];
  return v2f_load(vto);
}
static inline v2i compatible_v2i_cvt_v1l(v1l a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 2, 2*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 1, 1*sizeof(int64_t));
  v1l_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int32_t) vfrom[i];
  return v2i_load(vto);
}
static inline v2l compatible_v2l_cvt_v1l(v1l a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 2, 2*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 1, 1*sizeof(int64_t));
  v1l_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int64_t) vfrom[i];
  return v2l_load(vto);
}
static inline v4d compatible_v4d_cvt_v1l(v1l a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 4, 4*sizeof(double));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 1, 1*sizeof(int64_t));
  v1l_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (double) vfrom[i];
  return v4d_load(vto);
}
static inline v4f compatible_v4f_cvt_v1l(v1l a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 4, 4*sizeof(float));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 1, 1*sizeof(int64_t));
  v1l_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (float) vfrom[i];
  return v4f_load(vto);
}
static inline v4i compatible_v4i_cvt_v1l(v1l a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 4, 4*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 1, 1*sizeof(int64_t));
  v1l_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int32_t) vfrom[i];
  return v4i_load(vto);
}
static inline v4l compatible_v4l_cvt_v1l(v1l a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 4, 4*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 1, 1*sizeof(int64_t));
  v1l_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int64_t) vfrom[i];
  return v4l_load(vto);
}
static inline v8d compatible_v8d_cvt_v1l(v1l a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 8, 8*sizeof(double));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 1, 1*sizeof(int64_t));
  v1l_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (double) vfrom[i];
  return v8d_load(vto);
}
static inline v8f compatible_v8f_cvt_v1l(v1l a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 8, 8*sizeof(float));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 1, 1*sizeof(int64_t));
  v1l_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (float) vfrom[i];
  return v8f_load(vto);
}
static inline v8i compatible_v8i_cvt_v1l(v1l a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 8, 8*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 1, 1*sizeof(int64_t));
  v1l_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int32_t) vfrom[i];
  return v8i_load(vto);
}
static inline v8l compatible_v8l_cvt_v1l(v1l a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 8, 8*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 1, 1*sizeof(int64_t));
  v1l_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int64_t) vfrom[i];
  return v8l_load(vto);
}
static inline v16f compatible_v16f_cvt_v1l(v1l a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 16, 16*sizeof(float));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 1, 1*sizeof(int64_t));
  v1l_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (float) vfrom[i];
  return v16f_load(vto);
}
static inline v16i compatible_v16i_cvt_v1l(v1l a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 16, 16*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 1, 1*sizeof(int64_t));
  v1l_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int32_t) vfrom[i];
  return v16i_load(vto);
}
static inline v1d compatible_v1d_cvt_v2d(v2d a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 1, 1*sizeof(double));
  PINTS_ALIGNED_ARRAY(double, vfrom, 2, 2*sizeof(double));
  v2d_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (double) vfrom[i];
  return v1d_load(vto);
}
static inline v1f compatible_v1f_cvt_v2d(v2d a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 1, 1*sizeof(float));
  PINTS_ALIGNED_ARRAY(double, vfrom, 2, 2*sizeof(double));
  v2d_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (float) vfrom[i];
  return v1f_load(vto);
}
static inline v1i compatible_v1i_cvt_v2d(v2d a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 1, 1*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(double, vfrom, 2, 2*sizeof(double));
  v2d_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int32_t) vfrom[i];
  return v1i_load(vto);
}
static inline v1l compatible_v1l_cvt_v2d(v2d a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 1, 1*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(double, vfrom, 2, 2*sizeof(double));
  v2d_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int64_t) vfrom[i];
  return v1l_load(vto);
}
static inline v2d compatible_v2d_cvt_v2d(v2d a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 2, 2*sizeof(double));
  PINTS_ALIGNED_ARRAY(double, vfrom, 2, 2*sizeof(double));
  v2d_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (double) vfrom[i];
  return v2d_load(vto);
}
static inline v2f compatible_v2f_cvt_v2d(v2d a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 2, 2*sizeof(float));
  PINTS_ALIGNED_ARRAY(double, vfrom, 2, 2*sizeof(double));
  v2d_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (float) vfrom[i];
  return v2f_load(vto);
}
static inline v2i compatible_v2i_cvt_v2d(v2d a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 2, 2*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(double, vfrom, 2, 2*sizeof(double));
  v2d_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (int32_t) vfrom[i];
  return v2i_load(vto);
}
static inline v2l compatible_v2l_cvt_v2d(v2d a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 2, 2*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(double, vfrom, 2, 2*sizeof(double));
  v2d_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (int64_t) vfrom[i];
  return v2l_load(vto);
}
static inline v4d compatible_v4d_cvt_v2d(v2d a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 4, 4*sizeof(double));
  PINTS_ALIGNED_ARRAY(double, vfrom, 2, 2*sizeof(double));
  v2d_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (double) vfrom[i];
  return v4d_load(vto);
}
static inline v4f compatible_v4f_cvt_v2d(v2d a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 4, 4*sizeof(float));
  PINTS_ALIGNED_ARRAY(double, vfrom, 2, 2*sizeof(double));
  v2d_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (float) vfrom[i];
  return v4f_load(vto);
}
static inline v4i compatible_v4i_cvt_v2d(v2d a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 4, 4*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(double, vfrom, 2, 2*sizeof(double));
  v2d_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (int32_t) vfrom[i];
  return v4i_load(vto);
}
static inline v4l compatible_v4l_cvt_v2d(v2d a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 4, 4*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(double, vfrom, 2, 2*sizeof(double));
  v2d_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (int64_t) vfrom[i];
  return v4l_load(vto);
}
static inline v8d compatible_v8d_cvt_v2d(v2d a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 8, 8*sizeof(double));
  PINTS_ALIGNED_ARRAY(double, vfrom, 2, 2*sizeof(double));
  v2d_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (double) vfrom[i];
  return v8d_load(vto);
}
static inline v8f compatible_v8f_cvt_v2d(v2d a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 8, 8*sizeof(float));
  PINTS_ALIGNED_ARRAY(double, vfrom, 2, 2*sizeof(double));
  v2d_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (float) vfrom[i];
  return v8f_load(vto);
}
static inline v8i compatible_v8i_cvt_v2d(v2d a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 8, 8*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(double, vfrom, 2, 2*sizeof(double));
  v2d_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (int32_t) vfrom[i];
  return v8i_load(vto);
}
static inline v8l compatible_v8l_cvt_v2d(v2d a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 8, 8*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(double, vfrom, 2, 2*sizeof(double));
  v2d_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (int64_t) vfrom[i];
  return v8l_load(vto);
}
static inline v16f compatible_v16f_cvt_v2d(v2d a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 16, 16*sizeof(float));
  PINTS_ALIGNED_ARRAY(double, vfrom, 2, 2*sizeof(double));
  v2d_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (float) vfrom[i];
  return v16f_load(vto);
}
static inline v16i compatible_v16i_cvt_v2d(v2d a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 16, 16*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(double, vfrom, 2, 2*sizeof(double));
  v2d_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (int32_t) vfrom[i];
  return v16i_load(vto);
}
static inline v1d compatible_v1d_cvt_v2f(v2f a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 1, 1*sizeof(double));
  PINTS_ALIGNED_ARRAY(float, vfrom, 2, 2*sizeof(float));
  v2f_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (double) vfrom[i];
  return v1d_load(vto);
}
static inline v1f compatible_v1f_cvt_v2f(v2f a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 1, 1*sizeof(float));
  PINTS_ALIGNED_ARRAY(float, vfrom, 2, 2*sizeof(float));
  v2f_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (float) vfrom[i];
  return v1f_load(vto);
}
static inline v1i compatible_v1i_cvt_v2f(v2f a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 1, 1*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(float, vfrom, 2, 2*sizeof(float));
  v2f_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int32_t) vfrom[i];
  return v1i_load(vto);
}
static inline v1l compatible_v1l_cvt_v2f(v2f a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 1, 1*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(float, vfrom, 2, 2*sizeof(float));
  v2f_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int64_t) vfrom[i];
  return v1l_load(vto);
}
static inline v2d compatible_v2d_cvt_v2f(v2f a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 2, 2*sizeof(double));
  PINTS_ALIGNED_ARRAY(float, vfrom, 2, 2*sizeof(float));
  v2f_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (double) vfrom[i];
  return v2d_load(vto);
}
static inline v2f compatible_v2f_cvt_v2f(v2f a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 2, 2*sizeof(float));
  PINTS_ALIGNED_ARRAY(float, vfrom, 2, 2*sizeof(float));
  v2f_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (float) vfrom[i];
  return v2f_load(vto);
}
static inline v2i compatible_v2i_cvt_v2f(v2f a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 2, 2*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(float, vfrom, 2, 2*sizeof(float));
  v2f_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (int32_t) vfrom[i];
  return v2i_load(vto);
}
static inline v2l compatible_v2l_cvt_v2f(v2f a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 2, 2*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(float, vfrom, 2, 2*sizeof(float));
  v2f_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (int64_t) vfrom[i];
  return v2l_load(vto);
}
static inline v4d compatible_v4d_cvt_v2f(v2f a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 4, 4*sizeof(double));
  PINTS_ALIGNED_ARRAY(float, vfrom, 2, 2*sizeof(float));
  v2f_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (double) vfrom[i];
  return v4d_load(vto);
}
static inline v4f compatible_v4f_cvt_v2f(v2f a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 4, 4*sizeof(float));
  PINTS_ALIGNED_ARRAY(float, vfrom, 2, 2*sizeof(float));
  v2f_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (float) vfrom[i];
  return v4f_load(vto);
}
static inline v4i compatible_v4i_cvt_v2f(v2f a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 4, 4*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(float, vfrom, 2, 2*sizeof(float));
  v2f_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (int32_t) vfrom[i];
  return v4i_load(vto);
}
static inline v4l compatible_v4l_cvt_v2f(v2f a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 4, 4*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(float, vfrom, 2, 2*sizeof(float));
  v2f_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (int64_t) vfrom[i];
  return v4l_load(vto);
}
static inline v8d compatible_v8d_cvt_v2f(v2f a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 8, 8*sizeof(double));
  PINTS_ALIGNED_ARRAY(float, vfrom, 2, 2*sizeof(float));
  v2f_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (double) vfrom[i];
  return v8d_load(vto);
}
static inline v8f compatible_v8f_cvt_v2f(v2f a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 8, 8*sizeof(float));
  PINTS_ALIGNED_ARRAY(float, vfrom, 2, 2*sizeof(float));
  v2f_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (float) vfrom[i];
  return v8f_load(vto);
}
static inline v8i compatible_v8i_cvt_v2f(v2f a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 8, 8*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(float, vfrom, 2, 2*sizeof(float));
  v2f_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (int32_t) vfrom[i];
  return v8i_load(vto);
}
static inline v8l compatible_v8l_cvt_v2f(v2f a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 8, 8*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(float, vfrom, 2, 2*sizeof(float));
  v2f_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (int64_t) vfrom[i];
  return v8l_load(vto);
}
static inline v16f compatible_v16f_cvt_v2f(v2f a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 16, 16*sizeof(float));
  PINTS_ALIGNED_ARRAY(float, vfrom, 2, 2*sizeof(float));
  v2f_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (float) vfrom[i];
  return v16f_load(vto);
}
static inline v16i compatible_v16i_cvt_v2f(v2f a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 16, 16*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(float, vfrom, 2, 2*sizeof(float));
  v2f_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (int32_t) vfrom[i];
  return v16i_load(vto);
}
static inline v1d compatible_v1d_cvt_v2i(v2i a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 1, 1*sizeof(double));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 2, 2*sizeof(int32_t));
  v2i_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (double) vfrom[i];
  return v1d_load(vto);
}
static inline v1f compatible_v1f_cvt_v2i(v2i a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 1, 1*sizeof(float));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 2, 2*sizeof(int32_t));
  v2i_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (float) vfrom[i];
  return v1f_load(vto);
}
static inline v1i compatible_v1i_cvt_v2i(v2i a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 1, 1*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 2, 2*sizeof(int32_t));
  v2i_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int32_t) vfrom[i];
  return v1i_load(vto);
}
static inline v1l compatible_v1l_cvt_v2i(v2i a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 1, 1*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 2, 2*sizeof(int32_t));
  v2i_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int64_t) vfrom[i];
  return v1l_load(vto);
}
static inline v2d compatible_v2d_cvt_v2i(v2i a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 2, 2*sizeof(double));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 2, 2*sizeof(int32_t));
  v2i_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (double) vfrom[i];
  return v2d_load(vto);
}
static inline v2f compatible_v2f_cvt_v2i(v2i a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 2, 2*sizeof(float));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 2, 2*sizeof(int32_t));
  v2i_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (float) vfrom[i];
  return v2f_load(vto);
}
static inline v2i compatible_v2i_cvt_v2i(v2i a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 2, 2*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 2, 2*sizeof(int32_t));
  v2i_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (int32_t) vfrom[i];
  return v2i_load(vto);
}
static inline v2l compatible_v2l_cvt_v2i(v2i a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 2, 2*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 2, 2*sizeof(int32_t));
  v2i_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (int64_t) vfrom[i];
  return v2l_load(vto);
}
static inline v4d compatible_v4d_cvt_v2i(v2i a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 4, 4*sizeof(double));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 2, 2*sizeof(int32_t));
  v2i_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (double) vfrom[i];
  return v4d_load(vto);
}
static inline v4f compatible_v4f_cvt_v2i(v2i a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 4, 4*sizeof(float));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 2, 2*sizeof(int32_t));
  v2i_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (float) vfrom[i];
  return v4f_load(vto);
}
static inline v4i compatible_v4i_cvt_v2i(v2i a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 4, 4*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 2, 2*sizeof(int32_t));
  v2i_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (int32_t) vfrom[i];
  return v4i_load(vto);
}
static inline v4l compatible_v4l_cvt_v2i(v2i a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 4, 4*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 2, 2*sizeof(int32_t));
  v2i_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (int64_t) vfrom[i];
  return v4l_load(vto);
}
static inline v8d compatible_v8d_cvt_v2i(v2i a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 8, 8*sizeof(double));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 2, 2*sizeof(int32_t));
  v2i_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (double) vfrom[i];
  return v8d_load(vto);
}
static inline v8f compatible_v8f_cvt_v2i(v2i a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 8, 8*sizeof(float));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 2, 2*sizeof(int32_t));
  v2i_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (float) vfrom[i];
  return v8f_load(vto);
}
static inline v8i compatible_v8i_cvt_v2i(v2i a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 8, 8*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 2, 2*sizeof(int32_t));
  v2i_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (int32_t) vfrom[i];
  return v8i_load(vto);
}
static inline v8l compatible_v8l_cvt_v2i(v2i a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 8, 8*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 2, 2*sizeof(int32_t));
  v2i_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (int64_t) vfrom[i];
  return v8l_load(vto);
}
static inline v16f compatible_v16f_cvt_v2i(v2i a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 16, 16*sizeof(float));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 2, 2*sizeof(int32_t));
  v2i_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (float) vfrom[i];
  return v16f_load(vto);
}
static inline v16i compatible_v16i_cvt_v2i(v2i a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 16, 16*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 2, 2*sizeof(int32_t));
  v2i_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (int32_t) vfrom[i];
  return v16i_load(vto);
}
static inline v1d compatible_v1d_cvt_v2l(v2l a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 1, 1*sizeof(double));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 2, 2*sizeof(int64_t));
  v2l_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (double) vfrom[i];
  return v1d_load(vto);
}
static inline v1f compatible_v1f_cvt_v2l(v2l a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 1, 1*sizeof(float));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 2, 2*sizeof(int64_t));
  v2l_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (float) vfrom[i];
  return v1f_load(vto);
}
static inline v1i compatible_v1i_cvt_v2l(v2l a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 1, 1*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 2, 2*sizeof(int64_t));
  v2l_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int32_t) vfrom[i];
  return v1i_load(vto);
}
static inline v1l compatible_v1l_cvt_v2l(v2l a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 1, 1*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 2, 2*sizeof(int64_t));
  v2l_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int64_t) vfrom[i];
  return v1l_load(vto);
}
static inline v2d compatible_v2d_cvt_v2l(v2l a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 2, 2*sizeof(double));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 2, 2*sizeof(int64_t));
  v2l_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (double) vfrom[i];
  return v2d_load(vto);
}
static inline v2f compatible_v2f_cvt_v2l(v2l a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 2, 2*sizeof(float));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 2, 2*sizeof(int64_t));
  v2l_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (float) vfrom[i];
  return v2f_load(vto);
}
static inline v2i compatible_v2i_cvt_v2l(v2l a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 2, 2*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 2, 2*sizeof(int64_t));
  v2l_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (int32_t) vfrom[i];
  return v2i_load(vto);
}
static inline v2l compatible_v2l_cvt_v2l(v2l a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 2, 2*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 2, 2*sizeof(int64_t));
  v2l_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (int64_t) vfrom[i];
  return v2l_load(vto);
}
static inline v4d compatible_v4d_cvt_v2l(v2l a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 4, 4*sizeof(double));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 2, 2*sizeof(int64_t));
  v2l_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (double) vfrom[i];
  return v4d_load(vto);
}
static inline v4f compatible_v4f_cvt_v2l(v2l a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 4, 4*sizeof(float));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 2, 2*sizeof(int64_t));
  v2l_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (float) vfrom[i];
  return v4f_load(vto);
}
static inline v4i compatible_v4i_cvt_v2l(v2l a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 4, 4*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 2, 2*sizeof(int64_t));
  v2l_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (int32_t) vfrom[i];
  return v4i_load(vto);
}
static inline v4l compatible_v4l_cvt_v2l(v2l a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 4, 4*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 2, 2*sizeof(int64_t));
  v2l_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (int64_t) vfrom[i];
  return v4l_load(vto);
}
static inline v8d compatible_v8d_cvt_v2l(v2l a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 8, 8*sizeof(double));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 2, 2*sizeof(int64_t));
  v2l_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (double) vfrom[i];
  return v8d_load(vto);
}
static inline v8f compatible_v8f_cvt_v2l(v2l a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 8, 8*sizeof(float));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 2, 2*sizeof(int64_t));
  v2l_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (float) vfrom[i];
  return v8f_load(vto);
}
static inline v8i compatible_v8i_cvt_v2l(v2l a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 8, 8*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 2, 2*sizeof(int64_t));
  v2l_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (int32_t) vfrom[i];
  return v8i_load(vto);
}
static inline v8l compatible_v8l_cvt_v2l(v2l a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 8, 8*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 2, 2*sizeof(int64_t));
  v2l_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (int64_t) vfrom[i];
  return v8l_load(vto);
}
static inline v16f compatible_v16f_cvt_v2l(v2l a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 16, 16*sizeof(float));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 2, 2*sizeof(int64_t));
  v2l_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (float) vfrom[i];
  return v16f_load(vto);
}
static inline v16i compatible_v16i_cvt_v2l(v2l a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 16, 16*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 2, 2*sizeof(int64_t));
  v2l_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (int32_t) vfrom[i];
  return v16i_load(vto);
}
static inline v1d compatible_v1d_cvt_v4d(v4d a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 1, 1*sizeof(double));
  PINTS_ALIGNED_ARRAY(double, vfrom, 4, 4*sizeof(double));
  v4d_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (double) vfrom[i];
  return v1d_load(vto);
}
static inline v1f compatible_v1f_cvt_v4d(v4d a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 1, 1*sizeof(float));
  PINTS_ALIGNED_ARRAY(double, vfrom, 4, 4*sizeof(double));
  v4d_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (float) vfrom[i];
  return v1f_load(vto);
}
static inline v1i compatible_v1i_cvt_v4d(v4d a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 1, 1*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(double, vfrom, 4, 4*sizeof(double));
  v4d_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int32_t) vfrom[i];
  return v1i_load(vto);
}
static inline v1l compatible_v1l_cvt_v4d(v4d a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 1, 1*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(double, vfrom, 4, 4*sizeof(double));
  v4d_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int64_t) vfrom[i];
  return v1l_load(vto);
}
static inline v2d compatible_v2d_cvt_v4d(v4d a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 2, 2*sizeof(double));
  PINTS_ALIGNED_ARRAY(double, vfrom, 4, 4*sizeof(double));
  v4d_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (double) vfrom[i];
  return v2d_load(vto);
}
static inline v2f compatible_v2f_cvt_v4d(v4d a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 2, 2*sizeof(float));
  PINTS_ALIGNED_ARRAY(double, vfrom, 4, 4*sizeof(double));
  v4d_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (float) vfrom[i];
  return v2f_load(vto);
}
static inline v2i compatible_v2i_cvt_v4d(v4d a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 2, 2*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(double, vfrom, 4, 4*sizeof(double));
  v4d_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (int32_t) vfrom[i];
  return v2i_load(vto);
}
static inline v2l compatible_v2l_cvt_v4d(v4d a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 2, 2*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(double, vfrom, 4, 4*sizeof(double));
  v4d_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (int64_t) vfrom[i];
  return v2l_load(vto);
}
static inline v4d compatible_v4d_cvt_v4d(v4d a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 4, 4*sizeof(double));
  PINTS_ALIGNED_ARRAY(double, vfrom, 4, 4*sizeof(double));
  v4d_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (double) vfrom[i];
  return v4d_load(vto);
}
static inline v4f compatible_v4f_cvt_v4d(v4d a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 4, 4*sizeof(float));
  PINTS_ALIGNED_ARRAY(double, vfrom, 4, 4*sizeof(double));
  v4d_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (float) vfrom[i];
  return v4f_load(vto);
}
static inline v4i compatible_v4i_cvt_v4d(v4d a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 4, 4*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(double, vfrom, 4, 4*sizeof(double));
  v4d_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (int32_t) vfrom[i];
  return v4i_load(vto);
}
static inline v4l compatible_v4l_cvt_v4d(v4d a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 4, 4*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(double, vfrom, 4, 4*sizeof(double));
  v4d_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (int64_t) vfrom[i];
  return v4l_load(vto);
}
static inline v8d compatible_v8d_cvt_v4d(v4d a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 8, 8*sizeof(double));
  PINTS_ALIGNED_ARRAY(double, vfrom, 4, 4*sizeof(double));
  v4d_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (double) vfrom[i];
  return v8d_load(vto);
}
static inline v8f compatible_v8f_cvt_v4d(v4d a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 8, 8*sizeof(float));
  PINTS_ALIGNED_ARRAY(double, vfrom, 4, 4*sizeof(double));
  v4d_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (float) vfrom[i];
  return v8f_load(vto);
}
static inline v8i compatible_v8i_cvt_v4d(v4d a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 8, 8*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(double, vfrom, 4, 4*sizeof(double));
  v4d_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (int32_t) vfrom[i];
  return v8i_load(vto);
}
static inline v8l compatible_v8l_cvt_v4d(v4d a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 8, 8*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(double, vfrom, 4, 4*sizeof(double));
  v4d_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (int64_t) vfrom[i];
  return v8l_load(vto);
}
static inline v16f compatible_v16f_cvt_v4d(v4d a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 16, 16*sizeof(float));
  PINTS_ALIGNED_ARRAY(double, vfrom, 4, 4*sizeof(double));
  v4d_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (float) vfrom[i];
  return v16f_load(vto);
}
static inline v16i compatible_v16i_cvt_v4d(v4d a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 16, 16*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(double, vfrom, 4, 4*sizeof(double));
  v4d_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (int32_t) vfrom[i];
  return v16i_load(vto);
}
static inline v1d compatible_v1d_cvt_v4f(v4f a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 1, 1*sizeof(double));
  PINTS_ALIGNED_ARRAY(float, vfrom, 4, 4*sizeof(float));
  v4f_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (double) vfrom[i];
  return v1d_load(vto);
}
static inline v1f compatible_v1f_cvt_v4f(v4f a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 1, 1*sizeof(float));
  PINTS_ALIGNED_ARRAY(float, vfrom, 4, 4*sizeof(float));
  v4f_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (float) vfrom[i];
  return v1f_load(vto);
}
static inline v1i compatible_v1i_cvt_v4f(v4f a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 1, 1*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(float, vfrom, 4, 4*sizeof(float));
  v4f_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int32_t) vfrom[i];
  return v1i_load(vto);
}
static inline v1l compatible_v1l_cvt_v4f(v4f a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 1, 1*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(float, vfrom, 4, 4*sizeof(float));
  v4f_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int64_t) vfrom[i];
  return v1l_load(vto);
}
static inline v2d compatible_v2d_cvt_v4f(v4f a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 2, 2*sizeof(double));
  PINTS_ALIGNED_ARRAY(float, vfrom, 4, 4*sizeof(float));
  v4f_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (double) vfrom[i];
  return v2d_load(vto);
}
static inline v2f compatible_v2f_cvt_v4f(v4f a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 2, 2*sizeof(float));
  PINTS_ALIGNED_ARRAY(float, vfrom, 4, 4*sizeof(float));
  v4f_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (float) vfrom[i];
  return v2f_load(vto);
}
static inline v2i compatible_v2i_cvt_v4f(v4f a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 2, 2*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(float, vfrom, 4, 4*sizeof(float));
  v4f_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (int32_t) vfrom[i];
  return v2i_load(vto);
}
static inline v2l compatible_v2l_cvt_v4f(v4f a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 2, 2*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(float, vfrom, 4, 4*sizeof(float));
  v4f_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (int64_t) vfrom[i];
  return v2l_load(vto);
}
static inline v4d compatible_v4d_cvt_v4f(v4f a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 4, 4*sizeof(double));
  PINTS_ALIGNED_ARRAY(float, vfrom, 4, 4*sizeof(float));
  v4f_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (double) vfrom[i];
  return v4d_load(vto);
}
static inline v4f compatible_v4f_cvt_v4f(v4f a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 4, 4*sizeof(float));
  PINTS_ALIGNED_ARRAY(float, vfrom, 4, 4*sizeof(float));
  v4f_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (float) vfrom[i];
  return v4f_load(vto);
}
static inline v4i compatible_v4i_cvt_v4f(v4f a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 4, 4*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(float, vfrom, 4, 4*sizeof(float));
  v4f_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (int32_t) vfrom[i];
  return v4i_load(vto);
}
static inline v4l compatible_v4l_cvt_v4f(v4f a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 4, 4*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(float, vfrom, 4, 4*sizeof(float));
  v4f_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (int64_t) vfrom[i];
  return v4l_load(vto);
}
static inline v8d compatible_v8d_cvt_v4f(v4f a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 8, 8*sizeof(double));
  PINTS_ALIGNED_ARRAY(float, vfrom, 4, 4*sizeof(float));
  v4f_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (double) vfrom[i];
  return v8d_load(vto);
}
static inline v8f compatible_v8f_cvt_v4f(v4f a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 8, 8*sizeof(float));
  PINTS_ALIGNED_ARRAY(float, vfrom, 4, 4*sizeof(float));
  v4f_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (float) vfrom[i];
  return v8f_load(vto);
}
static inline v8i compatible_v8i_cvt_v4f(v4f a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 8, 8*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(float, vfrom, 4, 4*sizeof(float));
  v4f_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (int32_t) vfrom[i];
  return v8i_load(vto);
}
static inline v8l compatible_v8l_cvt_v4f(v4f a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 8, 8*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(float, vfrom, 4, 4*sizeof(float));
  v4f_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (int64_t) vfrom[i];
  return v8l_load(vto);
}
static inline v16f compatible_v16f_cvt_v4f(v4f a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 16, 16*sizeof(float));
  PINTS_ALIGNED_ARRAY(float, vfrom, 4, 4*sizeof(float));
  v4f_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (float) vfrom[i];
  return v16f_load(vto);
}
static inline v16i compatible_v16i_cvt_v4f(v4f a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 16, 16*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(float, vfrom, 4, 4*sizeof(float));
  v4f_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (int32_t) vfrom[i];
  return v16i_load(vto);
}
static inline v1d compatible_v1d_cvt_v4i(v4i a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 1, 1*sizeof(double));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 4, 4*sizeof(int32_t));
  v4i_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (double) vfrom[i];
  return v1d_load(vto);
}
static inline v1f compatible_v1f_cvt_v4i(v4i a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 1, 1*sizeof(float));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 4, 4*sizeof(int32_t));
  v4i_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (float) vfrom[i];
  return v1f_load(vto);
}
static inline v1i compatible_v1i_cvt_v4i(v4i a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 1, 1*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 4, 4*sizeof(int32_t));
  v4i_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int32_t) vfrom[i];
  return v1i_load(vto);
}
static inline v1l compatible_v1l_cvt_v4i(v4i a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 1, 1*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 4, 4*sizeof(int32_t));
  v4i_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int64_t) vfrom[i];
  return v1l_load(vto);
}
static inline v2d compatible_v2d_cvt_v4i(v4i a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 2, 2*sizeof(double));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 4, 4*sizeof(int32_t));
  v4i_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (double) vfrom[i];
  return v2d_load(vto);
}
static inline v2f compatible_v2f_cvt_v4i(v4i a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 2, 2*sizeof(float));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 4, 4*sizeof(int32_t));
  v4i_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (float) vfrom[i];
  return v2f_load(vto);
}
static inline v2i compatible_v2i_cvt_v4i(v4i a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 2, 2*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 4, 4*sizeof(int32_t));
  v4i_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (int32_t) vfrom[i];
  return v2i_load(vto);
}
static inline v2l compatible_v2l_cvt_v4i(v4i a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 2, 2*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 4, 4*sizeof(int32_t));
  v4i_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (int64_t) vfrom[i];
  return v2l_load(vto);
}
static inline v4d compatible_v4d_cvt_v4i(v4i a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 4, 4*sizeof(double));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 4, 4*sizeof(int32_t));
  v4i_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (double) vfrom[i];
  return v4d_load(vto);
}
static inline v4f compatible_v4f_cvt_v4i(v4i a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 4, 4*sizeof(float));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 4, 4*sizeof(int32_t));
  v4i_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (float) vfrom[i];
  return v4f_load(vto);
}
static inline v4i compatible_v4i_cvt_v4i(v4i a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 4, 4*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 4, 4*sizeof(int32_t));
  v4i_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (int32_t) vfrom[i];
  return v4i_load(vto);
}
static inline v4l compatible_v4l_cvt_v4i(v4i a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 4, 4*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 4, 4*sizeof(int32_t));
  v4i_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (int64_t) vfrom[i];
  return v4l_load(vto);
}
static inline v8d compatible_v8d_cvt_v4i(v4i a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 8, 8*sizeof(double));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 4, 4*sizeof(int32_t));
  v4i_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (double) vfrom[i];
  return v8d_load(vto);
}
static inline v8f compatible_v8f_cvt_v4i(v4i a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 8, 8*sizeof(float));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 4, 4*sizeof(int32_t));
  v4i_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (float) vfrom[i];
  return v8f_load(vto);
}
static inline v8i compatible_v8i_cvt_v4i(v4i a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 8, 8*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 4, 4*sizeof(int32_t));
  v4i_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (int32_t) vfrom[i];
  return v8i_load(vto);
}
static inline v8l compatible_v8l_cvt_v4i(v4i a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 8, 8*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 4, 4*sizeof(int32_t));
  v4i_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (int64_t) vfrom[i];
  return v8l_load(vto);
}
static inline v16f compatible_v16f_cvt_v4i(v4i a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 16, 16*sizeof(float));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 4, 4*sizeof(int32_t));
  v4i_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (float) vfrom[i];
  return v16f_load(vto);
}
static inline v16i compatible_v16i_cvt_v4i(v4i a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 16, 16*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 4, 4*sizeof(int32_t));
  v4i_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (int32_t) vfrom[i];
  return v16i_load(vto);
}
static inline v1d compatible_v1d_cvt_v4l(v4l a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 1, 1*sizeof(double));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 4, 4*sizeof(int64_t));
  v4l_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (double) vfrom[i];
  return v1d_load(vto);
}
static inline v1f compatible_v1f_cvt_v4l(v4l a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 1, 1*sizeof(float));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 4, 4*sizeof(int64_t));
  v4l_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (float) vfrom[i];
  return v1f_load(vto);
}
static inline v1i compatible_v1i_cvt_v4l(v4l a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 1, 1*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 4, 4*sizeof(int64_t));
  v4l_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int32_t) vfrom[i];
  return v1i_load(vto);
}
static inline v1l compatible_v1l_cvt_v4l(v4l a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 1, 1*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 4, 4*sizeof(int64_t));
  v4l_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int64_t) vfrom[i];
  return v1l_load(vto);
}
static inline v2d compatible_v2d_cvt_v4l(v4l a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 2, 2*sizeof(double));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 4, 4*sizeof(int64_t));
  v4l_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (double) vfrom[i];
  return v2d_load(vto);
}
static inline v2f compatible_v2f_cvt_v4l(v4l a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 2, 2*sizeof(float));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 4, 4*sizeof(int64_t));
  v4l_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (float) vfrom[i];
  return v2f_load(vto);
}
static inline v2i compatible_v2i_cvt_v4l(v4l a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 2, 2*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 4, 4*sizeof(int64_t));
  v4l_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (int32_t) vfrom[i];
  return v2i_load(vto);
}
static inline v2l compatible_v2l_cvt_v4l(v4l a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 2, 2*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 4, 4*sizeof(int64_t));
  v4l_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (int64_t) vfrom[i];
  return v2l_load(vto);
}
static inline v4d compatible_v4d_cvt_v4l(v4l a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 4, 4*sizeof(double));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 4, 4*sizeof(int64_t));
  v4l_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (double) vfrom[i];
  return v4d_load(vto);
}
static inline v4f compatible_v4f_cvt_v4l(v4l a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 4, 4*sizeof(float));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 4, 4*sizeof(int64_t));
  v4l_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (float) vfrom[i];
  return v4f_load(vto);
}
static inline v4i compatible_v4i_cvt_v4l(v4l a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 4, 4*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 4, 4*sizeof(int64_t));
  v4l_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (int32_t) vfrom[i];
  return v4i_load(vto);
}
static inline v4l compatible_v4l_cvt_v4l(v4l a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 4, 4*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 4, 4*sizeof(int64_t));
  v4l_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (int64_t) vfrom[i];
  return v4l_load(vto);
}
static inline v8d compatible_v8d_cvt_v4l(v4l a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 8, 8*sizeof(double));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 4, 4*sizeof(int64_t));
  v4l_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (double) vfrom[i];
  return v8d_load(vto);
}
static inline v8f compatible_v8f_cvt_v4l(v4l a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 8, 8*sizeof(float));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 4, 4*sizeof(int64_t));
  v4l_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (float) vfrom[i];
  return v8f_load(vto);
}
static inline v8i compatible_v8i_cvt_v4l(v4l a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 8, 8*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 4, 4*sizeof(int64_t));
  v4l_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (int32_t) vfrom[i];
  return v8i_load(vto);
}
static inline v8l compatible_v8l_cvt_v4l(v4l a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 8, 8*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 4, 4*sizeof(int64_t));
  v4l_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (int64_t) vfrom[i];
  return v8l_load(vto);
}
static inline v16f compatible_v16f_cvt_v4l(v4l a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 16, 16*sizeof(float));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 4, 4*sizeof(int64_t));
  v4l_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (float) vfrom[i];
  return v16f_load(vto);
}
static inline v16i compatible_v16i_cvt_v4l(v4l a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 16, 16*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 4, 4*sizeof(int64_t));
  v4l_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (int32_t) vfrom[i];
  return v16i_load(vto);
}
static inline v1d compatible_v1d_cvt_v8d(v8d a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 1, 1*sizeof(double));
  PINTS_ALIGNED_ARRAY(double, vfrom, 8, 8*sizeof(double));
  v8d_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (double) vfrom[i];
  return v1d_load(vto);
}
static inline v1f compatible_v1f_cvt_v8d(v8d a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 1, 1*sizeof(float));
  PINTS_ALIGNED_ARRAY(double, vfrom, 8, 8*sizeof(double));
  v8d_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (float) vfrom[i];
  return v1f_load(vto);
}
static inline v1i compatible_v1i_cvt_v8d(v8d a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 1, 1*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(double, vfrom, 8, 8*sizeof(double));
  v8d_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int32_t) vfrom[i];
  return v1i_load(vto);
}
static inline v1l compatible_v1l_cvt_v8d(v8d a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 1, 1*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(double, vfrom, 8, 8*sizeof(double));
  v8d_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int64_t) vfrom[i];
  return v1l_load(vto);
}
static inline v2d compatible_v2d_cvt_v8d(v8d a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 2, 2*sizeof(double));
  PINTS_ALIGNED_ARRAY(double, vfrom, 8, 8*sizeof(double));
  v8d_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (double) vfrom[i];
  return v2d_load(vto);
}
static inline v2f compatible_v2f_cvt_v8d(v8d a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 2, 2*sizeof(float));
  PINTS_ALIGNED_ARRAY(double, vfrom, 8, 8*sizeof(double));
  v8d_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (float) vfrom[i];
  return v2f_load(vto);
}
static inline v2i compatible_v2i_cvt_v8d(v8d a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 2, 2*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(double, vfrom, 8, 8*sizeof(double));
  v8d_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (int32_t) vfrom[i];
  return v2i_load(vto);
}
static inline v2l compatible_v2l_cvt_v8d(v8d a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 2, 2*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(double, vfrom, 8, 8*sizeof(double));
  v8d_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (int64_t) vfrom[i];
  return v2l_load(vto);
}
static inline v4d compatible_v4d_cvt_v8d(v8d a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 4, 4*sizeof(double));
  PINTS_ALIGNED_ARRAY(double, vfrom, 8, 8*sizeof(double));
  v8d_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (double) vfrom[i];
  return v4d_load(vto);
}
static inline v4f compatible_v4f_cvt_v8d(v8d a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 4, 4*sizeof(float));
  PINTS_ALIGNED_ARRAY(double, vfrom, 8, 8*sizeof(double));
  v8d_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (float) vfrom[i];
  return v4f_load(vto);
}
static inline v4i compatible_v4i_cvt_v8d(v8d a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 4, 4*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(double, vfrom, 8, 8*sizeof(double));
  v8d_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (int32_t) vfrom[i];
  return v4i_load(vto);
}
static inline v4l compatible_v4l_cvt_v8d(v8d a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 4, 4*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(double, vfrom, 8, 8*sizeof(double));
  v8d_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (int64_t) vfrom[i];
  return v4l_load(vto);
}
static inline v8d compatible_v8d_cvt_v8d(v8d a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 8, 8*sizeof(double));
  PINTS_ALIGNED_ARRAY(double, vfrom, 8, 8*sizeof(double));
  v8d_store(vfrom, a);
  for (i = 0; i < 8; ++i) vto[i] = (double) vfrom[i];
  return v8d_load(vto);
}
static inline v8f compatible_v8f_cvt_v8d(v8d a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 8, 8*sizeof(float));
  PINTS_ALIGNED_ARRAY(double, vfrom, 8, 8*sizeof(double));
  v8d_store(vfrom, a);
  for (i = 0; i < 8; ++i) vto[i] = (float) vfrom[i];
  return v8f_load(vto);
}
static inline v8i compatible_v8i_cvt_v8d(v8d a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 8, 8*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(double, vfrom, 8, 8*sizeof(double));
  v8d_store(vfrom, a);
  for (i = 0; i < 8; ++i) vto[i] = (int32_t) vfrom[i];
  return v8i_load(vto);
}
static inline v8l compatible_v8l_cvt_v8d(v8d a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 8, 8*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(double, vfrom, 8, 8*sizeof(double));
  v8d_store(vfrom, a);
  for (i = 0; i < 8; ++i) vto[i] = (int64_t) vfrom[i];
  return v8l_load(vto);
}
static inline v16f compatible_v16f_cvt_v8d(v8d a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 16, 16*sizeof(float));
  PINTS_ALIGNED_ARRAY(double, vfrom, 8, 8*sizeof(double));
  v8d_store(vfrom, a);
  for (i = 0; i < 8; ++i) vto[i] = (float) vfrom[i];
  return v16f_load(vto);
}
static inline v16i compatible_v16i_cvt_v8d(v8d a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 16, 16*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(double, vfrom, 8, 8*sizeof(double));
  v8d_store(vfrom, a);
  for (i = 0; i < 8; ++i) vto[i] = (int32_t) vfrom[i];
  return v16i_load(vto);
}
static inline v1d compatible_v1d_cvt_v8f(v8f a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 1, 1*sizeof(double));
  PINTS_ALIGNED_ARRAY(float, vfrom, 8, 8*sizeof(float));
  v8f_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (double) vfrom[i];
  return v1d_load(vto);
}
static inline v1f compatible_v1f_cvt_v8f(v8f a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 1, 1*sizeof(float));
  PINTS_ALIGNED_ARRAY(float, vfrom, 8, 8*sizeof(float));
  v8f_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (float) vfrom[i];
  return v1f_load(vto);
}
static inline v1i compatible_v1i_cvt_v8f(v8f a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 1, 1*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(float, vfrom, 8, 8*sizeof(float));
  v8f_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int32_t) vfrom[i];
  return v1i_load(vto);
}
static inline v1l compatible_v1l_cvt_v8f(v8f a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 1, 1*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(float, vfrom, 8, 8*sizeof(float));
  v8f_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int64_t) vfrom[i];
  return v1l_load(vto);
}
static inline v2d compatible_v2d_cvt_v8f(v8f a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 2, 2*sizeof(double));
  PINTS_ALIGNED_ARRAY(float, vfrom, 8, 8*sizeof(float));
  v8f_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (double) vfrom[i];
  return v2d_load(vto);
}
static inline v2f compatible_v2f_cvt_v8f(v8f a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 2, 2*sizeof(float));
  PINTS_ALIGNED_ARRAY(float, vfrom, 8, 8*sizeof(float));
  v8f_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (float) vfrom[i];
  return v2f_load(vto);
}
static inline v2i compatible_v2i_cvt_v8f(v8f a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 2, 2*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(float, vfrom, 8, 8*sizeof(float));
  v8f_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (int32_t) vfrom[i];
  return v2i_load(vto);
}
static inline v2l compatible_v2l_cvt_v8f(v8f a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 2, 2*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(float, vfrom, 8, 8*sizeof(float));
  v8f_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (int64_t) vfrom[i];
  return v2l_load(vto);
}
static inline v4d compatible_v4d_cvt_v8f(v8f a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 4, 4*sizeof(double));
  PINTS_ALIGNED_ARRAY(float, vfrom, 8, 8*sizeof(float));
  v8f_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (double) vfrom[i];
  return v4d_load(vto);
}
static inline v4f compatible_v4f_cvt_v8f(v8f a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 4, 4*sizeof(float));
  PINTS_ALIGNED_ARRAY(float, vfrom, 8, 8*sizeof(float));
  v8f_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (float) vfrom[i];
  return v4f_load(vto);
}
static inline v4i compatible_v4i_cvt_v8f(v8f a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 4, 4*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(float, vfrom, 8, 8*sizeof(float));
  v8f_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (int32_t) vfrom[i];
  return v4i_load(vto);
}
static inline v4l compatible_v4l_cvt_v8f(v8f a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 4, 4*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(float, vfrom, 8, 8*sizeof(float));
  v8f_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (int64_t) vfrom[i];
  return v4l_load(vto);
}
static inline v8d compatible_v8d_cvt_v8f(v8f a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 8, 8*sizeof(double));
  PINTS_ALIGNED_ARRAY(float, vfrom, 8, 8*sizeof(float));
  v8f_store(vfrom, a);
  for (i = 0; i < 8; ++i) vto[i] = (double) vfrom[i];
  return v8d_load(vto);
}
static inline v8f compatible_v8f_cvt_v8f(v8f a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 8, 8*sizeof(float));
  PINTS_ALIGNED_ARRAY(float, vfrom, 8, 8*sizeof(float));
  v8f_store(vfrom, a);
  for (i = 0; i < 8; ++i) vto[i] = (float) vfrom[i];
  return v8f_load(vto);
}
static inline v8i compatible_v8i_cvt_v8f(v8f a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 8, 8*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(float, vfrom, 8, 8*sizeof(float));
  v8f_store(vfrom, a);
  for (i = 0; i < 8; ++i) vto[i] = (int32_t) vfrom[i];
  return v8i_load(vto);
}
static inline v8l compatible_v8l_cvt_v8f(v8f a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 8, 8*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(float, vfrom, 8, 8*sizeof(float));
  v8f_store(vfrom, a);
  for (i = 0; i < 8; ++i) vto[i] = (int64_t) vfrom[i];
  return v8l_load(vto);
}
static inline v16f compatible_v16f_cvt_v8f(v8f a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 16, 16*sizeof(float));
  PINTS_ALIGNED_ARRAY(float, vfrom, 8, 8*sizeof(float));
  v8f_store(vfrom, a);
  for (i = 0; i < 8; ++i) vto[i] = (float) vfrom[i];
  return v16f_load(vto);
}
static inline v16i compatible_v16i_cvt_v8f(v8f a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 16, 16*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(float, vfrom, 8, 8*sizeof(float));
  v8f_store(vfrom, a);
  for (i = 0; i < 8; ++i) vto[i] = (int32_t) vfrom[i];
  return v16i_load(vto);
}
static inline v1d compatible_v1d_cvt_v8i(v8i a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 1, 1*sizeof(double));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 8, 8*sizeof(int32_t));
  v8i_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (double) vfrom[i];
  return v1d_load(vto);
}
static inline v1f compatible_v1f_cvt_v8i(v8i a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 1, 1*sizeof(float));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 8, 8*sizeof(int32_t));
  v8i_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (float) vfrom[i];
  return v1f_load(vto);
}
static inline v1i compatible_v1i_cvt_v8i(v8i a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 1, 1*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 8, 8*sizeof(int32_t));
  v8i_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int32_t) vfrom[i];
  return v1i_load(vto);
}
static inline v1l compatible_v1l_cvt_v8i(v8i a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 1, 1*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 8, 8*sizeof(int32_t));
  v8i_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int64_t) vfrom[i];
  return v1l_load(vto);
}
static inline v2d compatible_v2d_cvt_v8i(v8i a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 2, 2*sizeof(double));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 8, 8*sizeof(int32_t));
  v8i_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (double) vfrom[i];
  return v2d_load(vto);
}
static inline v2f compatible_v2f_cvt_v8i(v8i a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 2, 2*sizeof(float));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 8, 8*sizeof(int32_t));
  v8i_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (float) vfrom[i];
  return v2f_load(vto);
}
static inline v2i compatible_v2i_cvt_v8i(v8i a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 2, 2*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 8, 8*sizeof(int32_t));
  v8i_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (int32_t) vfrom[i];
  return v2i_load(vto);
}
static inline v2l compatible_v2l_cvt_v8i(v8i a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 2, 2*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 8, 8*sizeof(int32_t));
  v8i_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (int64_t) vfrom[i];
  return v2l_load(vto);
}
static inline v4d compatible_v4d_cvt_v8i(v8i a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 4, 4*sizeof(double));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 8, 8*sizeof(int32_t));
  v8i_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (double) vfrom[i];
  return v4d_load(vto);
}
static inline v4f compatible_v4f_cvt_v8i(v8i a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 4, 4*sizeof(float));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 8, 8*sizeof(int32_t));
  v8i_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (float) vfrom[i];
  return v4f_load(vto);
}
static inline v4i compatible_v4i_cvt_v8i(v8i a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 4, 4*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 8, 8*sizeof(int32_t));
  v8i_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (int32_t) vfrom[i];
  return v4i_load(vto);
}
static inline v4l compatible_v4l_cvt_v8i(v8i a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 4, 4*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 8, 8*sizeof(int32_t));
  v8i_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (int64_t) vfrom[i];
  return v4l_load(vto);
}
static inline v8d compatible_v8d_cvt_v8i(v8i a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 8, 8*sizeof(double));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 8, 8*sizeof(int32_t));
  v8i_store(vfrom, a);
  for (i = 0; i < 8; ++i) vto[i] = (double) vfrom[i];
  return v8d_load(vto);
}
static inline v8f compatible_v8f_cvt_v8i(v8i a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 8, 8*sizeof(float));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 8, 8*sizeof(int32_t));
  v8i_store(vfrom, a);
  for (i = 0; i < 8; ++i) vto[i] = (float) vfrom[i];
  return v8f_load(vto);
}
static inline v8i compatible_v8i_cvt_v8i(v8i a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 8, 8*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 8, 8*sizeof(int32_t));
  v8i_store(vfrom, a);
  for (i = 0; i < 8; ++i) vto[i] = (int32_t) vfrom[i];
  return v8i_load(vto);
}
static inline v8l compatible_v8l_cvt_v8i(v8i a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 8, 8*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 8, 8*sizeof(int32_t));
  v8i_store(vfrom, a);
  for (i = 0; i < 8; ++i) vto[i] = (int64_t) vfrom[i];
  return v8l_load(vto);
}
static inline v16f compatible_v16f_cvt_v8i(v8i a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 16, 16*sizeof(float));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 8, 8*sizeof(int32_t));
  v8i_store(vfrom, a);
  for (i = 0; i < 8; ++i) vto[i] = (float) vfrom[i];
  return v16f_load(vto);
}
static inline v16i compatible_v16i_cvt_v8i(v8i a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 16, 16*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 8, 8*sizeof(int32_t));
  v8i_store(vfrom, a);
  for (i = 0; i < 8; ++i) vto[i] = (int32_t) vfrom[i];
  return v16i_load(vto);
}
static inline v1d compatible_v1d_cvt_v8l(v8l a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 1, 1*sizeof(double));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 8, 8*sizeof(int64_t));
  v8l_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (double) vfrom[i];
  return v1d_load(vto);
}
static inline v1f compatible_v1f_cvt_v8l(v8l a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 1, 1*sizeof(float));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 8, 8*sizeof(int64_t));
  v8l_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (float) vfrom[i];
  return v1f_load(vto);
}
static inline v1i compatible_v1i_cvt_v8l(v8l a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 1, 1*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 8, 8*sizeof(int64_t));
  v8l_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int32_t) vfrom[i];
  return v1i_load(vto);
}
static inline v1l compatible_v1l_cvt_v8l(v8l a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 1, 1*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 8, 8*sizeof(int64_t));
  v8l_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int64_t) vfrom[i];
  return v1l_load(vto);
}
static inline v2d compatible_v2d_cvt_v8l(v8l a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 2, 2*sizeof(double));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 8, 8*sizeof(int64_t));
  v8l_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (double) vfrom[i];
  return v2d_load(vto);
}
static inline v2f compatible_v2f_cvt_v8l(v8l a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 2, 2*sizeof(float));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 8, 8*sizeof(int64_t));
  v8l_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (float) vfrom[i];
  return v2f_load(vto);
}
static inline v2i compatible_v2i_cvt_v8l(v8l a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 2, 2*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 8, 8*sizeof(int64_t));
  v8l_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (int32_t) vfrom[i];
  return v2i_load(vto);
}
static inline v2l compatible_v2l_cvt_v8l(v8l a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 2, 2*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 8, 8*sizeof(int64_t));
  v8l_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (int64_t) vfrom[i];
  return v2l_load(vto);
}
static inline v4d compatible_v4d_cvt_v8l(v8l a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 4, 4*sizeof(double));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 8, 8*sizeof(int64_t));
  v8l_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (double) vfrom[i];
  return v4d_load(vto);
}
static inline v4f compatible_v4f_cvt_v8l(v8l a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 4, 4*sizeof(float));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 8, 8*sizeof(int64_t));
  v8l_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (float) vfrom[i];
  return v4f_load(vto);
}
static inline v4i compatible_v4i_cvt_v8l(v8l a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 4, 4*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 8, 8*sizeof(int64_t));
  v8l_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (int32_t) vfrom[i];
  return v4i_load(vto);
}
static inline v4l compatible_v4l_cvt_v8l(v8l a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 4, 4*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 8, 8*sizeof(int64_t));
  v8l_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (int64_t) vfrom[i];
  return v4l_load(vto);
}
static inline v8d compatible_v8d_cvt_v8l(v8l a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 8, 8*sizeof(double));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 8, 8*sizeof(int64_t));
  v8l_store(vfrom, a);
  for (i = 0; i < 8; ++i) vto[i] = (double) vfrom[i];
  return v8d_load(vto);
}
static inline v8f compatible_v8f_cvt_v8l(v8l a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 8, 8*sizeof(float));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 8, 8*sizeof(int64_t));
  v8l_store(vfrom, a);
  for (i = 0; i < 8; ++i) vto[i] = (float) vfrom[i];
  return v8f_load(vto);
}
static inline v8i compatible_v8i_cvt_v8l(v8l a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 8, 8*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 8, 8*sizeof(int64_t));
  v8l_store(vfrom, a);
  for (i = 0; i < 8; ++i) vto[i] = (int32_t) vfrom[i];
  return v8i_load(vto);
}
static inline v8l compatible_v8l_cvt_v8l(v8l a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 8, 8*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 8, 8*sizeof(int64_t));
  v8l_store(vfrom, a);
  for (i = 0; i < 8; ++i) vto[i] = (int64_t) vfrom[i];
  return v8l_load(vto);
}
static inline v16f compatible_v16f_cvt_v8l(v8l a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 16, 16*sizeof(float));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 8, 8*sizeof(int64_t));
  v8l_store(vfrom, a);
  for (i = 0; i < 8; ++i) vto[i] = (float) vfrom[i];
  return v16f_load(vto);
}
static inline v16i compatible_v16i_cvt_v8l(v8l a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 16, 16*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(int64_t, vfrom, 8, 8*sizeof(int64_t));
  v8l_store(vfrom, a);
  for (i = 0; i < 8; ++i) vto[i] = (int32_t) vfrom[i];
  return v16i_load(vto);
}
static inline v1d compatible_v1d_cvt_v16f(v16f a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 1, 1*sizeof(double));
  PINTS_ALIGNED_ARRAY(float, vfrom, 16, 16*sizeof(float));
  v16f_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (double) vfrom[i];
  return v1d_load(vto);
}
static inline v1f compatible_v1f_cvt_v16f(v16f a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 1, 1*sizeof(float));
  PINTS_ALIGNED_ARRAY(float, vfrom, 16, 16*sizeof(float));
  v16f_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (float) vfrom[i];
  return v1f_load(vto);
}
static inline v1i compatible_v1i_cvt_v16f(v16f a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 1, 1*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(float, vfrom, 16, 16*sizeof(float));
  v16f_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int32_t) vfrom[i];
  return v1i_load(vto);
}
static inline v1l compatible_v1l_cvt_v16f(v16f a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 1, 1*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(float, vfrom, 16, 16*sizeof(float));
  v16f_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int64_t) vfrom[i];
  return v1l_load(vto);
}
static inline v2d compatible_v2d_cvt_v16f(v16f a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 2, 2*sizeof(double));
  PINTS_ALIGNED_ARRAY(float, vfrom, 16, 16*sizeof(float));
  v16f_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (double) vfrom[i];
  return v2d_load(vto);
}
static inline v2f compatible_v2f_cvt_v16f(v16f a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 2, 2*sizeof(float));
  PINTS_ALIGNED_ARRAY(float, vfrom, 16, 16*sizeof(float));
  v16f_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (float) vfrom[i];
  return v2f_load(vto);
}
static inline v2i compatible_v2i_cvt_v16f(v16f a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 2, 2*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(float, vfrom, 16, 16*sizeof(float));
  v16f_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (int32_t) vfrom[i];
  return v2i_load(vto);
}
static inline v2l compatible_v2l_cvt_v16f(v16f a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 2, 2*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(float, vfrom, 16, 16*sizeof(float));
  v16f_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (int64_t) vfrom[i];
  return v2l_load(vto);
}
static inline v4d compatible_v4d_cvt_v16f(v16f a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 4, 4*sizeof(double));
  PINTS_ALIGNED_ARRAY(float, vfrom, 16, 16*sizeof(float));
  v16f_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (double) vfrom[i];
  return v4d_load(vto);
}
static inline v4f compatible_v4f_cvt_v16f(v16f a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 4, 4*sizeof(float));
  PINTS_ALIGNED_ARRAY(float, vfrom, 16, 16*sizeof(float));
  v16f_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (float) vfrom[i];
  return v4f_load(vto);
}
static inline v4i compatible_v4i_cvt_v16f(v16f a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 4, 4*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(float, vfrom, 16, 16*sizeof(float));
  v16f_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (int32_t) vfrom[i];
  return v4i_load(vto);
}
static inline v4l compatible_v4l_cvt_v16f(v16f a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 4, 4*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(float, vfrom, 16, 16*sizeof(float));
  v16f_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (int64_t) vfrom[i];
  return v4l_load(vto);
}
static inline v8d compatible_v8d_cvt_v16f(v16f a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 8, 8*sizeof(double));
  PINTS_ALIGNED_ARRAY(float, vfrom, 16, 16*sizeof(float));
  v16f_store(vfrom, a);
  for (i = 0; i < 8; ++i) vto[i] = (double) vfrom[i];
  return v8d_load(vto);
}
static inline v8f compatible_v8f_cvt_v16f(v16f a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 8, 8*sizeof(float));
  PINTS_ALIGNED_ARRAY(float, vfrom, 16, 16*sizeof(float));
  v16f_store(vfrom, a);
  for (i = 0; i < 8; ++i) vto[i] = (float) vfrom[i];
  return v8f_load(vto);
}
static inline v8i compatible_v8i_cvt_v16f(v16f a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 8, 8*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(float, vfrom, 16, 16*sizeof(float));
  v16f_store(vfrom, a);
  for (i = 0; i < 8; ++i) vto[i] = (int32_t) vfrom[i];
  return v8i_load(vto);
}
static inline v8l compatible_v8l_cvt_v16f(v16f a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 8, 8*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(float, vfrom, 16, 16*sizeof(float));
  v16f_store(vfrom, a);
  for (i = 0; i < 8; ++i) vto[i] = (int64_t) vfrom[i];
  return v8l_load(vto);
}
static inline v16f compatible_v16f_cvt_v16f(v16f a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 16, 16*sizeof(float));
  PINTS_ALIGNED_ARRAY(float, vfrom, 16, 16*sizeof(float));
  v16f_store(vfrom, a);
  for (i = 0; i < 16; ++i) vto[i] = (float) vfrom[i];
  return v16f_load(vto);
}
static inline v16i compatible_v16i_cvt_v16f(v16f a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 16, 16*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(float, vfrom, 16, 16*sizeof(float));
  v16f_store(vfrom, a);
  for (i = 0; i < 16; ++i) vto[i] = (int32_t) vfrom[i];
  return v16i_load(vto);
}
static inline v1d compatible_v1d_cvt_v16i(v16i a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 1, 1*sizeof(double));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 16, 16*sizeof(int32_t));
  v16i_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (double) vfrom[i];
  return v1d_load(vto);
}
static inline v1f compatible_v1f_cvt_v16i(v16i a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 1, 1*sizeof(float));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 16, 16*sizeof(int32_t));
  v16i_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (float) vfrom[i];
  return v1f_load(vto);
}
static inline v1i compatible_v1i_cvt_v16i(v16i a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 1, 1*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 16, 16*sizeof(int32_t));
  v16i_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int32_t) vfrom[i];
  return v1i_load(vto);
}
static inline v1l compatible_v1l_cvt_v16i(v16i a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 1, 1*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 16, 16*sizeof(int32_t));
  v16i_store(vfrom, a);
  for (i = 0; i < 1; ++i) vto[i] = (int64_t) vfrom[i];
  return v1l_load(vto);
}
static inline v2d compatible_v2d_cvt_v16i(v16i a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 2, 2*sizeof(double));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 16, 16*sizeof(int32_t));
  v16i_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (double) vfrom[i];
  return v2d_load(vto);
}
static inline v2f compatible_v2f_cvt_v16i(v16i a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 2, 2*sizeof(float));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 16, 16*sizeof(int32_t));
  v16i_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (float) vfrom[i];
  return v2f_load(vto);
}
static inline v2i compatible_v2i_cvt_v16i(v16i a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 2, 2*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 16, 16*sizeof(int32_t));
  v16i_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (int32_t) vfrom[i];
  return v2i_load(vto);
}
static inline v2l compatible_v2l_cvt_v16i(v16i a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 2, 2*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 16, 16*sizeof(int32_t));
  v16i_store(vfrom, a);
  for (i = 0; i < 2; ++i) vto[i] = (int64_t) vfrom[i];
  return v2l_load(vto);
}
static inline v4d compatible_v4d_cvt_v16i(v16i a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 4, 4*sizeof(double));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 16, 16*sizeof(int32_t));
  v16i_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (double) vfrom[i];
  return v4d_load(vto);
}
static inline v4f compatible_v4f_cvt_v16i(v16i a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 4, 4*sizeof(float));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 16, 16*sizeof(int32_t));
  v16i_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (float) vfrom[i];
  return v4f_load(vto);
}
static inline v4i compatible_v4i_cvt_v16i(v16i a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 4, 4*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 16, 16*sizeof(int32_t));
  v16i_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (int32_t) vfrom[i];
  return v4i_load(vto);
}
static inline v4l compatible_v4l_cvt_v16i(v16i a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 4, 4*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 16, 16*sizeof(int32_t));
  v16i_store(vfrom, a);
  for (i = 0; i < 4; ++i) vto[i] = (int64_t) vfrom[i];
  return v4l_load(vto);
}
static inline v8d compatible_v8d_cvt_v16i(v16i a) {
  int i;
  PINTS_ALIGNED_ARRAY(double, vto, 8, 8*sizeof(double));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 16, 16*sizeof(int32_t));
  v16i_store(vfrom, a);
  for (i = 0; i < 8; ++i) vto[i] = (double) vfrom[i];
  return v8d_load(vto);
}
static inline v8f compatible_v8f_cvt_v16i(v16i a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 8, 8*sizeof(float));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 16, 16*sizeof(int32_t));
  v16i_store(vfrom, a);
  for (i = 0; i < 8; ++i) vto[i] = (float) vfrom[i];
  return v8f_load(vto);
}
static inline v8i compatible_v8i_cvt_v16i(v16i a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 8, 8*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 16, 16*sizeof(int32_t));
  v16i_store(vfrom, a);
  for (i = 0; i < 8; ++i) vto[i] = (int32_t) vfrom[i];
  return v8i_load(vto);
}
static inline v8l compatible_v8l_cvt_v16i(v16i a) {
  int i;
  PINTS_ALIGNED_ARRAY(int64_t, vto, 8, 8*sizeof(int64_t));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 16, 16*sizeof(int32_t));
  v16i_store(vfrom, a);
  for (i = 0; i < 8; ++i) vto[i] = (int64_t) vfrom[i];
  return v8l_load(vto);
}
static inline v16f compatible_v16f_cvt_v16i(v16i a) {
  int i;
  PINTS_ALIGNED_ARRAY(float, vto, 16, 16*sizeof(float));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 16, 16*sizeof(int32_t));
  v16i_store(vfrom, a);
  for (i = 0; i < 16; ++i) vto[i] = (float) vfrom[i];
  return v16f_load(vto);
}
static inline v16i compatible_v16i_cvt_v16i(v16i a) {
  int i;
  PINTS_ALIGNED_ARRAY(int32_t, vto, 16, 16*sizeof(int32_t));
  PINTS_ALIGNED_ARRAY(int32_t, vfrom, 16, 16*sizeof(int32_t));
  v16i_store(vfrom, a);
  for (i = 0; i < 16; ++i) vto[i] = (int32_t) vfrom[i];
  return v16i_load(vto);
}

#endif //PINTS_POLYFILL_FUNCS_H