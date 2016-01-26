#ifndef PINTS_POLYFILL_DEFINES_H
#define PINTS_POLYFILL_DEFINES_H
//include/pints-polyfill-defines.h

////////////////////////////////////////////////////////////////////////////////
// Internal Types
////////////////////////////////////////////////////////////////////////////////
#define v1d union __v1d
#define v1f union __v1f
#define v1i union __v1i
#define v1l union __v1l
#define v2d struct __v2d
#define v2f struct __v2f
#define v2i struct __v2i
#define v2l struct __v2l
#define v4d struct __v4d
#define v4f struct __v4f
#define v4i struct __v4i
#define v4l struct __v4l
#define v8d struct __v8d
#define v8f struct __v8f
#define v8i struct __v8i
#define v8l struct __v8l
#define v16f struct __v16f
#define v16i struct __v16i
#define m1d v1d
#define m1f v1f
#define m1i v1i
#define m1l v1l
#define m2d v2d
#define m2f v2f
#define m2i v2i
#define m2l v2l
#define m4d v4d
#define m4f v4f
#define m4i v4i
#define m4l v4l
#define m8d v8d
#define m8f v8f
#define m8i v8i
#define m8l v8l
#define m16f v16f
#define m16i v16i



/* LOADS */

#define v1d_load __v1d_load
#define v1f_load __v1f_load
#define v1i_load __v1i_load
#define v1l_load __v1l_load
#define v2d_load __v2d_load
#define v2f_load __v2f_load
#define v2i_load __v2i_load
#define v2l_load __v2l_load
#define v4d_load __v4d_load
#define v4f_load __v4f_load
#define v4i_load __v4i_load
#define v4l_load __v4l_load
#define v8d_load __v8d_load
#define v8f_load __v8f_load
#define v8i_load __v8i_load
#define v8l_load __v8l_load
#define v16f_load __v16f_load
#define v16i_load __v16i_load

#define v1d_loadu(p)  v1d_load(p)
#define v1f_loadu(p)  v1f_load(p)
#define v1i_loadu(p)  v1i_load(p)
#define v1l_loadu(p)  v1l_load(p)
#define v2d_loadu __v2d_loadu
#define v2f_loadu __v2f_loadu
#define v2i_loadu __v2i_loadu
#define v2l_loadu __v2l_loadu
#define v4d_loadu __v4d_loadu
#define v4f_loadu __v4f_loadu
#define v4i_loadu __v4i_loadu
#define v4l_loadu __v4l_loadu
#define v8d_loadu __v8d_loadu
#define v8f_loadu __v8f_loadu
#define v8i_loadu __v8i_loadu
#define v8l_loadu __v8l_loadu
#define v16f_loadu __v16f_loadu
#define v16i_loadu __v16i_loadu

#define v1d_load1(p)  v1d_set1(*(p))
#define v1f_load1(p)  v1f_set1(*(p))
#define v1i_load1(p)  v1i_set1(*(p))
#define v1l_load1(p)  v1l_set1(*(p))
#define v2d_load1 __v2d_load1
#define v2f_load1 __v2f_load1
#define v2i_load1 __v2i_load1
#define v2l_load1 __v2l_load1
#define v4d_load1 __v4d_load1
#define v4f_load1 __v4f_load1
#define v4i_load1 __v4i_load1
#define v4l_load1 __v4l_load1
#define v8d_load1 __v8d_load1
#define v8f_load1 __v8f_load1
#define v8i_load1 __v8i_load1
#define v8l_load1 __v8l_load1
#define v16f_load1 __v16f_load1
#define v16i_load1 __v16i_load1


/* STORES */

#define v1d_store __v1d_store
#define v1f_store __v1f_store
#define v1i_store __v1i_store
#define v1l_store __v1l_store
#define v2d_store __v2d_store
#define v2f_store __v2f_store
#define v2i_store __v2i_store
#define v2l_store __v2l_store
#define v4d_store __v4d_store
#define v4f_store __v4f_store
#define v4i_store __v4i_store
#define v4l_store __v4l_store
#define v8d_store __v8d_store
#define v8f_store __v8f_store
#define v8i_store __v8i_store
#define v8l_store __v8l_store
#define v16f_store __v16f_store
#define v16i_store __v16i_store

#define v1d_storeu(p,a)  v1d_store((p), (a))
#define v1f_storeu(p,a)  v1f_store((p), (a))
#define v1i_storeu(p,a)  v1i_store((p), (a))
#define v1l_storeu(p,a)  v1l_store((p), (a))
#define v2d_storeu __v2d_storeu
#define v2f_storeu __v2f_storeu
#define v2i_storeu __v2i_storeu
#define v2l_storeu __v2l_storeu
#define v4d_storeu __v4d_storeu
#define v4f_storeu __v4f_storeu
#define v4i_storeu __v4i_storeu
#define v4l_storeu __v4l_storeu
#define v8d_storeu __v8d_storeu
#define v8f_storeu __v8f_storeu
#define v8i_storeu __v8i_storeu
#define v8l_storeu __v8l_storeu
#define v16f_storeu __v16f_storeu
#define v16i_storeu __v16i_storeu

#define v1d_store1(p,a)  (*(p) = sd_cvt_v1d(a))
#define v1f_store1(p,a)  (*(p) = sf_cvt_v1f(a))
#define v1i_store1(p,a)  (*(p) = si_cvt_v1i(a))
#define v1l_store1(p,a)  (*(p) = sl_cvt_v1l(a))
#define v2d_store1(p,a)  v1d_store1(p, v1d_get_low_v2d(a))
#define v2f_store1(p,a)  v1f_store1(p, v1f_get_low_v2f(a))
#define v2i_store1(p,a)  v1i_store1(p, v1i_get_low_v2i(a))
#define v2l_store1(p,a)  v1l_store1(p, v1l_get_low_v2l(a))
#define v4d_store1(p,a)  v2d_store1(p, v2d_get_low_v4d(a))
#define v4f_store1(p,a)  v2f_store1(p, v2f_get_low_v4f(a))
#define v4i_store1(p,a)  v2i_store1(p, v2i_get_low_v4i(a))
#define v4l_store1(p,a)  v2l_store1(p, v2l_get_low_v4l(a))
#define v8d_store1(p,a)  v4d_store1(p, v4d_get_low_v8d(a))
#define v8f_store1(p,a)  v4f_store1(p, v4f_get_low_v8f(a))
#define v8i_store1(p,a)  v4i_store1(p, v4i_get_low_v8i(a))
#define v8l_store1(p,a)  v4l_store1(p, v4l_get_low_v8l(a))
#define v16f_store1(p,a)  v8f_store1(p, v8f_get_low_v16f(a))
#define v16i_store1(p,a)  v8i_store1(p, v8i_get_low_v16i(a))


/* SETS */

#define v1d_set __v1d_set
#define v1f_set __v1f_set
#define v1i_set __v1i_set
#define v1l_set __v1l_set
#define v2d_set(v0, v1)  v2d_merge2_v1d(v1d_set((v0)), v1d_set((v1)))
#define v2f_set(v0, v1)  v2f_merge2_v1f(v1f_set((v0)), v1f_set((v1)))
#define v2i_set(v0, v1)  v2i_merge2_v1i(v1i_set((v0)), v1i_set((v1)))
#define v2l_set(v0, v1)  v2l_merge2_v1l(v1l_set((v0)), v1l_set((v1)))
#define v4d_set(v0, v1, v2, v3)  v4d_merge2_v2d(v2d_set((v0), (v1)), v2d_set((v2), (v3)))
#define v4f_set(v0, v1, v2, v3)  v4f_merge2_v2f(v2f_set((v0), (v1)), v2f_set((v2), (v3)))
#define v4i_set(v0, v1, v2, v3)  v4i_merge2_v2i(v2i_set((v0), (v1)), v2i_set((v2), (v3)))
#define v4l_set(v0, v1, v2, v3)  v4l_merge2_v2l(v2l_set((v0), (v1)), v2l_set((v2), (v3)))
#define v8d_set(v0, v1, v2, v3, v4, v5, v6, v7)  v8d_merge2_v4d(v4d_set((v0), (v1), (v2), (v3)), v4d_set((v4), (v5), (v6), (v7)))
#define v8f_set(v0, v1, v2, v3, v4, v5, v6, v7)  v8f_merge2_v4f(v4f_set((v0), (v1), (v2), (v3)), v4f_set((v4), (v5), (v6), (v7)))
#define v8i_set(v0, v1, v2, v3, v4, v5, v6, v7)  v8i_merge2_v4i(v4i_set((v0), (v1), (v2), (v3)), v4i_set((v4), (v5), (v6), (v7)))
#define v8l_set(v0, v1, v2, v3, v4, v5, v6, v7)  v8l_merge2_v4l(v4l_set((v0), (v1), (v2), (v3)), v4l_set((v4), (v5), (v6), (v7)))
#define v16f_set(v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15)  v16f_merge2_v8f(v8f_set((v0), (v1), (v2), (v3), (v4), (v5), (v6), (v7)), v8f_set((v8), (v9), (v10), (v11), (v12), (v13), (v14), (v15)))
#define v16i_set(v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15)  v16i_merge2_v8i(v8i_set((v0), (v1), (v2), (v3), (v4), (v5), (v6), (v7)), v8i_set((v8), (v9), (v10), (v11), (v12), (v13), (v14), (v15)))

#define v1d_rset(v0)  v1d_set((v0))
#define v1f_rset(v0)  v1f_set((v0))
#define v1i_rset(v0)  v1i_set((v0))
#define v1l_rset(v0)  v1l_set((v0))
#define v2d_rset(v1, v0)  v2d_set((v0), (v1))
#define v2f_rset(v1, v0)  v2f_set((v0), (v1))
#define v2i_rset(v1, v0)  v2i_set((v0), (v1))
#define v2l_rset(v1, v0)  v2l_set((v0), (v1))
#define v4d_rset(v3, v2, v1, v0)  v4d_set((v0), (v1), (v2), (v3))
#define v4f_rset(v3, v2, v1, v0)  v4f_set((v0), (v1), (v2), (v3))
#define v4i_rset(v3, v2, v1, v0)  v4i_set((v0), (v1), (v2), (v3))
#define v4l_rset(v3, v2, v1, v0)  v4l_set((v0), (v1), (v2), (v3))
#define v8d_rset(v7, v6, v5, v4, v3, v2, v1, v0)  v8d_set((v0), (v1), (v2), (v3), (v4), (v5), (v6), (v7))
#define v8f_rset(v7, v6, v5, v4, v3, v2, v1, v0)  v8f_set((v0), (v1), (v2), (v3), (v4), (v5), (v6), (v7))
#define v8i_rset(v7, v6, v5, v4, v3, v2, v1, v0)  v8i_set((v0), (v1), (v2), (v3), (v4), (v5), (v6), (v7))
#define v8l_rset(v7, v6, v5, v4, v3, v2, v1, v0)  v8l_set((v0), (v1), (v2), (v3), (v4), (v5), (v6), (v7))
#define v16f_rset(v15, v14, v13, v12, v11, v10, v9, v8, v7, v6, v5, v4, v3, v2, v1, v0)  v16f_set((v0), (v1), (v2), (v3), (v4), (v5), (v6), (v7), (v8), (v9), (v10), (v11), (v12), (v13), (v14), (v15))
#define v16i_rset(v15, v14, v13, v12, v11, v10, v9, v8, v7, v6, v5, v4, v3, v2, v1, v0)  v16i_set((v0), (v1), (v2), (v3), (v4), (v5), (v6), (v7), (v8), (v9), (v10), (v11), (v12), (v13), (v14), (v15))

#define v1d_set1(v)  v1d_set(v)
#define v1f_set1(v)  v1f_set(v)
#define v1i_set1(v)  v1i_set(v)
#define v1l_set1(v)  v1l_set(v)
#define v2d_set1 __v2d_set1
#define v2f_set1 __v2f_set1
#define v2i_set1 __v2i_set1
#define v2l_set1 __v2l_set1
#define v4d_set1 __v4d_set1
#define v4f_set1 __v4f_set1
#define v4i_set1 __v4i_set1
#define v4l_set1 __v4l_set1
#define v8d_set1 __v8d_set1
#define v8f_set1 __v8f_set1
#define v8i_set1 __v8i_set1
#define v8l_set1 __v8l_set1
#define v16f_set1 __v16f_set1
#define v16i_set1 __v16i_set1

/* CONSTANTS */
#define v1d_zeros()  v1d_set1(0)
#define v1f_zeros()  v1f_set1(0)
#define v1i_zeros()  v1i_set1(0)
#define v1l_zeros()  v1l_set1(0)
#define v2d_zeros()  v2d_set1(0)
#define v2f_zeros()  v2f_set1(0)
#define v2i_zeros()  v2i_set1(0)
#define v2l_zeros()  v2l_set1(0)
#define v4d_zeros()  v4d_set1(0)
#define v4f_zeros()  v4f_set1(0)
#define v4i_zeros()  v4i_set1(0)
#define v4l_zeros()  v4l_set1(0)
#define v8d_zeros()  v8d_set1(0)
#define v8f_zeros()  v8f_set1(0)
#define v8i_zeros()  v8i_set1(0)
#define v8l_zeros()  v8l_set1(0)
#define v16f_zeros()  v16f_set1(0)
#define v16i_zeros()  v16i_set1(0)
#define v1d_ones()  v1d_set1(PINTS_REINTERPRET(double, int64_t, -1))
#define v1f_ones()  v1f_set1(PINTS_REINTERPRET(float, int32_t, -1))
#define v1i_ones()  v1i_set1(-1)
#define v1l_ones()  v1l_set1(-1)
#define v2d_ones()  v2d_set1(PINTS_REINTERPRET(double, int64_t, -1))
#define v2f_ones()  v2f_set1(PINTS_REINTERPRET(float, int32_t, -1))
#define v2i_ones()  v2i_set1(-1)
#define v2l_ones()  v2l_set1(-1)
#define v4d_ones()  v4d_set1(PINTS_REINTERPRET(double, int64_t, -1))
#define v4f_ones()  v4f_set1(PINTS_REINTERPRET(float, int32_t, -1))
#define v4i_ones()  v4i_set1(-1)
#define v4l_ones()  v4l_set1(-1)
#define v8d_ones()  v8d_set1(PINTS_REINTERPRET(double, int64_t, -1))
#define v8f_ones()  v8f_set1(PINTS_REINTERPRET(float, int32_t, -1))
#define v8i_ones()  v8i_set1(-1)
#define v8l_ones()  v8l_set1(-1)
#define v16f_ones()  v16f_set1(PINTS_REINTERPRET(float, int32_t, -1))
#define v16i_ones()  v16i_set1(-1)
#define v1d_zero()  v1d_zeros()
#define v1f_zero()  v1f_zeros()
#define v1i_zero()  v1i_zeros()
#define v1l_zero()  v1l_zeros()
#define v2d_zero()  v2d_zeros()
#define v2f_zero()  v2f_zeros()
#define v2i_zero()  v2i_zeros()
#define v2l_zero()  v2l_zeros()
#define v4d_zero()  v4d_zeros()
#define v4f_zero()  v4f_zeros()
#define v4i_zero()  v4i_zeros()
#define v4l_zero()  v4l_zeros()
#define v8d_zero()  v8d_zeros()
#define v8f_zero()  v8f_zeros()
#define v8i_zero()  v8i_zeros()
#define v8l_zero()  v8l_zeros()
#define v16f_zero()  v16f_zeros()
#define v16i_zero()  v16i_zeros()
#define v1d_one()  v1d_set1(1)
#define v1f_one()  v1f_set1(1)
#define v1i_one()  v1i_set1(1)
#define v1l_one()  v1l_set1(1)
#define v2d_one()  v2d_set1(1)
#define v2f_one()  v2f_set1(1)
#define v2i_one()  v2i_set1(1)
#define v2l_one()  v2l_set1(1)
#define v4d_one()  v4d_set1(1)
#define v4f_one()  v4f_set1(1)
#define v4i_one()  v4i_set1(1)
#define v4l_one()  v4l_set1(1)
#define v8d_one()  v8d_set1(1)
#define v8f_one()  v8f_set1(1)
#define v8i_one()  v8i_set1(1)
#define v8l_one()  v8l_set1(1)
#define v16f_one()  v16f_set1(1)
#define v16i_one()  v16i_set1(1)


/* COMPARISONS */

#define m1d_eq(a,b)  m1d_cast_v1d(v1d_eq(a, b))
#define m1f_eq(a,b)  m1f_cast_v1f(v1f_eq(a, b))
#define m1i_eq(a,b)  m1i_cast_v1i(v1i_eq(a, b))
#define m1l_eq(a,b)  m1l_cast_v1l(v1l_eq(a, b))
#define m2d_eq(a,b)  m2d_cast_v2d(v2d_eq(a, b))
#define m2f_eq(a,b)  m2f_cast_v2f(v2f_eq(a, b))
#define m2i_eq(a,b)  m2i_cast_v2i(v2i_eq(a, b))
#define m2l_eq(a,b)  m2l_cast_v2l(v2l_eq(a, b))
#define m4d_eq(a,b)  m4d_cast_v4d(v4d_eq(a, b))
#define m4f_eq(a,b)  m4f_cast_v4f(v4f_eq(a, b))
#define m4i_eq(a,b)  m4i_cast_v4i(v4i_eq(a, b))
#define m4l_eq(a,b)  m4l_cast_v4l(v4l_eq(a, b))
#define m8d_eq(a,b)  m8d_cast_v8d(v8d_eq(a, b))
#define m8f_eq(a,b)  m8f_cast_v8f(v8f_eq(a, b))
#define m8i_eq(a,b)  m8i_cast_v8i(v8i_eq(a, b))
#define m8l_eq(a,b)  m8l_cast_v8l(v8l_eq(a, b))
#define m16f_eq(a,b)  m16f_cast_v16f(v16f_eq(a, b))
#define m16i_eq(a,b)  m16i_cast_v16i(v16i_eq(a, b))

#define m1d_neq(a,b)  m1d_cast_v1d(v1d_neq(a, b))
#define m1f_neq(a,b)  m1f_cast_v1f(v1f_neq(a, b))
#define m1i_neq(a,b)  m1i_cast_v1i(v1i_neq(a, b))
#define m1l_neq(a,b)  m1l_cast_v1l(v1l_neq(a, b))
#define m2d_neq(a,b)  m2d_cast_v2d(v2d_neq(a, b))
#define m2f_neq(a,b)  m2f_cast_v2f(v2f_neq(a, b))
#define m2i_neq(a,b)  m2i_cast_v2i(v2i_neq(a, b))
#define m2l_neq(a,b)  m2l_cast_v2l(v2l_neq(a, b))
#define m4d_neq(a,b)  m4d_cast_v4d(v4d_neq(a, b))
#define m4f_neq(a,b)  m4f_cast_v4f(v4f_neq(a, b))
#define m4i_neq(a,b)  m4i_cast_v4i(v4i_neq(a, b))
#define m4l_neq(a,b)  m4l_cast_v4l(v4l_neq(a, b))
#define m8d_neq(a,b)  m8d_cast_v8d(v8d_neq(a, b))
#define m8f_neq(a,b)  m8f_cast_v8f(v8f_neq(a, b))
#define m8i_neq(a,b)  m8i_cast_v8i(v8i_neq(a, b))
#define m8l_neq(a,b)  m8l_cast_v8l(v8l_neq(a, b))
#define m16f_neq(a,b)  m16f_cast_v16f(v16f_neq(a, b))
#define m16i_neq(a,b)  m16i_cast_v16i(v16i_neq(a, b))

#define m1d_gt(a,b)  m1d_cast_v1d(v1d_gt(a, b))
#define m1f_gt(a,b)  m1f_cast_v1f(v1f_gt(a, b))
#define m1i_gt(a,b)  m1i_cast_v1i(v1i_gt(a, b))
#define m1l_gt(a,b)  m1l_cast_v1l(v1l_gt(a, b))
#define m2d_gt(a,b)  m2d_cast_v2d(v2d_gt(a, b))
#define m2f_gt(a,b)  m2f_cast_v2f(v2f_gt(a, b))
#define m2i_gt(a,b)  m2i_cast_v2i(v2i_gt(a, b))
#define m2l_gt(a,b)  m2l_cast_v2l(v2l_gt(a, b))
#define m4d_gt(a,b)  m4d_cast_v4d(v4d_gt(a, b))
#define m4f_gt(a,b)  m4f_cast_v4f(v4f_gt(a, b))
#define m4i_gt(a,b)  m4i_cast_v4i(v4i_gt(a, b))
#define m4l_gt(a,b)  m4l_cast_v4l(v4l_gt(a, b))
#define m8d_gt(a,b)  m8d_cast_v8d(v8d_gt(a, b))
#define m8f_gt(a,b)  m8f_cast_v8f(v8f_gt(a, b))
#define m8i_gt(a,b)  m8i_cast_v8i(v8i_gt(a, b))
#define m8l_gt(a,b)  m8l_cast_v8l(v8l_gt(a, b))
#define m16f_gt(a,b)  m16f_cast_v16f(v16f_gt(a, b))
#define m16i_gt(a,b)  m16i_cast_v16i(v16i_gt(a, b))

#define m1d_geq(a,b)  m1d_cast_v1d(v1d_geq(a, b))
#define m1f_geq(a,b)  m1f_cast_v1f(v1f_geq(a, b))
#define m1i_geq(a,b)  m1i_cast_v1i(v1i_geq(a, b))
#define m1l_geq(a,b)  m1l_cast_v1l(v1l_geq(a, b))
#define m2d_geq(a,b)  m2d_cast_v2d(v2d_geq(a, b))
#define m2f_geq(a,b)  m2f_cast_v2f(v2f_geq(a, b))
#define m2i_geq(a,b)  m2i_cast_v2i(v2i_geq(a, b))
#define m2l_geq(a,b)  m2l_cast_v2l(v2l_geq(a, b))
#define m4d_geq(a,b)  m4d_cast_v4d(v4d_geq(a, b))
#define m4f_geq(a,b)  m4f_cast_v4f(v4f_geq(a, b))
#define m4i_geq(a,b)  m4i_cast_v4i(v4i_geq(a, b))
#define m4l_geq(a,b)  m4l_cast_v4l(v4l_geq(a, b))
#define m8d_geq(a,b)  m8d_cast_v8d(v8d_geq(a, b))
#define m8f_geq(a,b)  m8f_cast_v8f(v8f_geq(a, b))
#define m8i_geq(a,b)  m8i_cast_v8i(v8i_geq(a, b))
#define m8l_geq(a,b)  m8l_cast_v8l(v8l_geq(a, b))
#define m16f_geq(a,b)  m16f_cast_v16f(v16f_geq(a, b))
#define m16i_geq(a,b)  m16i_cast_v16i(v16i_geq(a, b))

#define m1d_lt(a,b)  m1d_cast_v1d(v1d_lt(a, b))
#define m1f_lt(a,b)  m1f_cast_v1f(v1f_lt(a, b))
#define m1i_lt(a,b)  m1i_cast_v1i(v1i_lt(a, b))
#define m1l_lt(a,b)  m1l_cast_v1l(v1l_lt(a, b))
#define m2d_lt(a,b)  m2d_cast_v2d(v2d_lt(a, b))
#define m2f_lt(a,b)  m2f_cast_v2f(v2f_lt(a, b))
#define m2i_lt(a,b)  m2i_cast_v2i(v2i_lt(a, b))
#define m2l_lt(a,b)  m2l_cast_v2l(v2l_lt(a, b))
#define m4d_lt(a,b)  m4d_cast_v4d(v4d_lt(a, b))
#define m4f_lt(a,b)  m4f_cast_v4f(v4f_lt(a, b))
#define m4i_lt(a,b)  m4i_cast_v4i(v4i_lt(a, b))
#define m4l_lt(a,b)  m4l_cast_v4l(v4l_lt(a, b))
#define m8d_lt(a,b)  m8d_cast_v8d(v8d_lt(a, b))
#define m8f_lt(a,b)  m8f_cast_v8f(v8f_lt(a, b))
#define m8i_lt(a,b)  m8i_cast_v8i(v8i_lt(a, b))
#define m8l_lt(a,b)  m8l_cast_v8l(v8l_lt(a, b))
#define m16f_lt(a,b)  m16f_cast_v16f(v16f_lt(a, b))
#define m16i_lt(a,b)  m16i_cast_v16i(v16i_lt(a, b))

#define m1d_leq(a,b)  m1d_cast_v1d(v1d_leq(a, b))
#define m1f_leq(a,b)  m1f_cast_v1f(v1f_leq(a, b))
#define m1i_leq(a,b)  m1i_cast_v1i(v1i_leq(a, b))
#define m1l_leq(a,b)  m1l_cast_v1l(v1l_leq(a, b))
#define m2d_leq(a,b)  m2d_cast_v2d(v2d_leq(a, b))
#define m2f_leq(a,b)  m2f_cast_v2f(v2f_leq(a, b))
#define m2i_leq(a,b)  m2i_cast_v2i(v2i_leq(a, b))
#define m2l_leq(a,b)  m2l_cast_v2l(v2l_leq(a, b))
#define m4d_leq(a,b)  m4d_cast_v4d(v4d_leq(a, b))
#define m4f_leq(a,b)  m4f_cast_v4f(v4f_leq(a, b))
#define m4i_leq(a,b)  m4i_cast_v4i(v4i_leq(a, b))
#define m4l_leq(a,b)  m4l_cast_v4l(v4l_leq(a, b))
#define m8d_leq(a,b)  m8d_cast_v8d(v8d_leq(a, b))
#define m8f_leq(a,b)  m8f_cast_v8f(v8f_leq(a, b))
#define m8i_leq(a,b)  m8i_cast_v8i(v8i_leq(a, b))
#define m8l_leq(a,b)  m8l_cast_v8l(v8l_leq(a, b))
#define m16f_leq(a,b)  m16f_cast_v16f(v16f_leq(a, b))
#define m16i_leq(a,b)  m16i_cast_v16i(v16i_leq(a, b))


/* LOGIC */

#define m1d_and(a,b)  m1d_and(a, b)
#define m1f_and(a,b)  m1f_and(a, b)
#define m1i_and(a,b)  m1i_and(a, b)
#define m1l_and(a,b)  m1l_and(a, b)
#define m2d_and(a,b)  m2d_and(a, b)
#define m2f_and(a,b)  m2f_and(a, b)
#define m2i_and(a,b)  m2i_and(a, b)
#define m2l_and(a,b)  m2l_and(a, b)
#define m4d_and(a,b)  m4d_and(a, b)
#define m4f_and(a,b)  m4f_and(a, b)
#define m4i_and(a,b)  m4i_and(a, b)
#define m4l_and(a,b)  m4l_and(a, b)
#define m8d_and(a,b)  m8d_and(a, b)
#define m8f_and(a,b)  m8f_and(a, b)
#define m8i_and(a,b)  m8i_and(a, b)
#define m8l_and(a,b)  m8l_and(a, b)
#define m16f_and(a,b)  m16f_and(a, b)
#define m16i_and(a,b)  m16i_and(a, b)

#define m1d_or(a,b)  m1d_or(a, b)
#define m1f_or(a,b)  m1f_or(a, b)
#define m1i_or(a,b)  m1i_or(a, b)
#define m1l_or(a,b)  m1l_or(a, b)
#define m2d_or(a,b)  m2d_or(a, b)
#define m2f_or(a,b)  m2f_or(a, b)
#define m2i_or(a,b)  m2i_or(a, b)
#define m2l_or(a,b)  m2l_or(a, b)
#define m4d_or(a,b)  m4d_or(a, b)
#define m4f_or(a,b)  m4f_or(a, b)
#define m4i_or(a,b)  m4i_or(a, b)
#define m4l_or(a,b)  m4l_or(a, b)
#define m8d_or(a,b)  m8d_or(a, b)
#define m8f_or(a,b)  m8f_or(a, b)
#define m8i_or(a,b)  m8i_or(a, b)
#define m8l_or(a,b)  m8l_or(a, b)
#define m16f_or(a,b)  m16f_or(a, b)
#define m16i_or(a,b)  m16i_or(a, b)

#define m1d_xor(a,b)  m1d_xor(a, b)
#define m1f_xor(a,b)  m1f_xor(a, b)
#define m1i_xor(a,b)  m1i_xor(a, b)
#define m1l_xor(a,b)  m1l_xor(a, b)
#define m2d_xor(a,b)  m2d_xor(a, b)
#define m2f_xor(a,b)  m2f_xor(a, b)
#define m2i_xor(a,b)  m2i_xor(a, b)
#define m2l_xor(a,b)  m2l_xor(a, b)
#define m4d_xor(a,b)  m4d_xor(a, b)
#define m4f_xor(a,b)  m4f_xor(a, b)
#define m4i_xor(a,b)  m4i_xor(a, b)
#define m4l_xor(a,b)  m4l_xor(a, b)
#define m8d_xor(a,b)  m8d_xor(a, b)
#define m8f_xor(a,b)  m8f_xor(a, b)
#define m8i_xor(a,b)  m8i_xor(a, b)
#define m8l_xor(a,b)  m8l_xor(a, b)
#define m16f_xor(a,b)  m16f_xor(a, b)
#define m16i_xor(a,b)  m16i_xor(a, b)

#define m1d_not(a)  m1d_not(a)
#define m1f_not(a)  m1f_not(a)
#define m1i_not(a)  m1i_not(a)
#define m1l_not(a)  m1l_not(a)
#define m2d_not(a)  m2d_not(a)
#define m2f_not(a)  m2f_not(a)
#define m2i_not(a)  m2i_not(a)
#define m2l_not(a)  m2l_not(a)
#define m4d_not(a)  m4d_not(a)
#define m4f_not(a)  m4f_not(a)
#define m4i_not(a)  m4i_not(a)
#define m4l_not(a)  m4l_not(a)
#define m8d_not(a)  m8d_not(a)
#define m8f_not(a)  m8f_not(a)
#define m8i_not(a)  m8i_not(a)
#define m8l_not(a)  m8l_not(a)
#define m16f_not(a)  m16f_not(a)
#define m16i_not(a)  m16i_not(a)

#define m1d_nand(a,b)  m1d_nand(a, b)
#define m1f_nand(a,b)  m1f_nand(a, b)
#define m1i_nand(a,b)  m1i_nand(a, b)
#define m1l_nand(a,b)  m1l_nand(a, b)
#define m2d_nand(a,b)  m2d_nand(a, b)
#define m2f_nand(a,b)  m2f_nand(a, b)
#define m2i_nand(a,b)  m2i_nand(a, b)
#define m2l_nand(a,b)  m2l_nand(a, b)
#define m4d_nand(a,b)  m4d_nand(a, b)
#define m4f_nand(a,b)  m4f_nand(a, b)
#define m4i_nand(a,b)  m4i_nand(a, b)
#define m4l_nand(a,b)  m4l_nand(a, b)
#define m8d_nand(a,b)  m8d_nand(a, b)
#define m8f_nand(a,b)  m8f_nand(a, b)
#define m8i_nand(a,b)  m8i_nand(a, b)
#define m8l_nand(a,b)  m8l_nand(a, b)
#define m16f_nand(a,b)  m16f_nand(a, b)
#define m16i_nand(a,b)  m16i_nand(a, b)

#define m1d_nor(a,b)  m1d_nor(a, b)
#define m1f_nor(a,b)  m1f_nor(a, b)
#define m1i_nor(a,b)  m1i_nor(a, b)
#define m1l_nor(a,b)  m1l_nor(a, b)
#define m2d_nor(a,b)  m2d_nor(a, b)
#define m2f_nor(a,b)  m2f_nor(a, b)
#define m2i_nor(a,b)  m2i_nor(a, b)
#define m2l_nor(a,b)  m2l_nor(a, b)
#define m4d_nor(a,b)  m4d_nor(a, b)
#define m4f_nor(a,b)  m4f_nor(a, b)
#define m4i_nor(a,b)  m4i_nor(a, b)
#define m4l_nor(a,b)  m4l_nor(a, b)
#define m8d_nor(a,b)  m8d_nor(a, b)
#define m8f_nor(a,b)  m8f_nor(a, b)
#define m8i_nor(a,b)  m8i_nor(a, b)
#define m8l_nor(a,b)  m8l_nor(a, b)
#define m16f_nor(a,b)  m16f_nor(a, b)
#define m16i_nor(a,b)  m16i_nor(a, b)

#define m1d_nxor(a,b)  m1d_nxor(a, b)
#define m1f_nxor(a,b)  m1f_nxor(a, b)
#define m1i_nxor(a,b)  m1i_nxor(a, b)
#define m1l_nxor(a,b)  m1l_nxor(a, b)
#define m2d_nxor(a,b)  m2d_nxor(a, b)
#define m2f_nxor(a,b)  m2f_nxor(a, b)
#define m2i_nxor(a,b)  m2i_nxor(a, b)
#define m2l_nxor(a,b)  m2l_nxor(a, b)
#define m4d_nxor(a,b)  m4d_nxor(a, b)
#define m4f_nxor(a,b)  m4f_nxor(a, b)
#define m4i_nxor(a,b)  m4i_nxor(a, b)
#define m4l_nxor(a,b)  m4l_nxor(a, b)
#define m8d_nxor(a,b)  m8d_nxor(a, b)
#define m8f_nxor(a,b)  m8f_nxor(a, b)
#define m8i_nxor(a,b)  m8i_nxor(a, b)
#define m8l_nxor(a,b)  m8l_nxor(a, b)
#define m16f_nxor(a,b)  m16f_nxor(a, b)
#define m16i_nxor(a,b)  m16i_nxor(a, b)

#define m1d_andnot(a,b)  m1d_andnot(a, b)
#define m1f_andnot(a,b)  m1f_andnot(a, b)
#define m1i_andnot(a,b)  m1i_andnot(a, b)
#define m1l_andnot(a,b)  m1l_andnot(a, b)
#define m2d_andnot(a,b)  m2d_andnot(a, b)
#define m2f_andnot(a,b)  m2f_andnot(a, b)
#define m2i_andnot(a,b)  m2i_andnot(a, b)
#define m2l_andnot(a,b)  m2l_andnot(a, b)
#define m4d_andnot(a,b)  m4d_andnot(a, b)
#define m4f_andnot(a,b)  m4f_andnot(a, b)
#define m4i_andnot(a,b)  m4i_andnot(a, b)
#define m4l_andnot(a,b)  m4l_andnot(a, b)
#define m8d_andnot(a,b)  m8d_andnot(a, b)
#define m8f_andnot(a,b)  m8f_andnot(a, b)
#define m8i_andnot(a,b)  m8i_andnot(a, b)
#define m8l_andnot(a,b)  m8l_andnot(a, b)
#define m16f_andnot(a,b)  m16f_andnot(a, b)
#define m16i_andnot(a,b)  m16i_andnot(a, b)

#define m1d_ornot(a,b)  m1d_ornot(a, b)
#define m1f_ornot(a,b)  m1f_ornot(a, b)
#define m1i_ornot(a,b)  m1i_ornot(a, b)
#define m1l_ornot(a,b)  m1l_ornot(a, b)
#define m2d_ornot(a,b)  m2d_ornot(a, b)
#define m2f_ornot(a,b)  m2f_ornot(a, b)
#define m2i_ornot(a,b)  m2i_ornot(a, b)
#define m2l_ornot(a,b)  m2l_ornot(a, b)
#define m4d_ornot(a,b)  m4d_ornot(a, b)
#define m4f_ornot(a,b)  m4f_ornot(a, b)
#define m4i_ornot(a,b)  m4i_ornot(a, b)
#define m4l_ornot(a,b)  m4l_ornot(a, b)
#define m8d_ornot(a,b)  m8d_ornot(a, b)
#define m8f_ornot(a,b)  m8f_ornot(a, b)
#define m8i_ornot(a,b)  m8i_ornot(a, b)
#define m8l_ornot(a,b)  m8l_ornot(a, b)
#define m16f_ornot(a,b)  m16f_ornot(a, b)
#define m16i_ornot(a,b)  m16i_ornot(a, b)


/* COMPARISONS */

#define v1d_eq __v1d_eq
#define v1f_eq __v1f_eq
#define v1i_eq __v1i_eq
#define v1l_eq __v1l_eq
#define v2d_eq __v2d_eq
#define v2f_eq __v2f_eq
#define v2i_eq __v2i_eq
#define v2l_eq __v2l_eq
#define v4d_eq __v4d_eq
#define v4f_eq __v4f_eq
#define v4i_eq __v4i_eq
#define v4l_eq __v4l_eq
#define v8d_eq __v8d_eq
#define v8f_eq __v8f_eq
#define v8i_eq __v8i_eq
#define v8l_eq __v8l_eq
#define v16f_eq __v16f_eq
#define v16i_eq __v16i_eq

#define v1d_neq __v1d_neq
#define v1f_neq __v1f_neq
#define v1i_neq __v1i_neq
#define v1l_neq __v1l_neq
#define v2d_neq __v2d_neq
#define v2f_neq __v2f_neq
#define v2i_neq __v2i_neq
#define v2l_neq __v2l_neq
#define v4d_neq __v4d_neq
#define v4f_neq __v4f_neq
#define v4i_neq __v4i_neq
#define v4l_neq __v4l_neq
#define v8d_neq __v8d_neq
#define v8f_neq __v8f_neq
#define v8i_neq __v8i_neq
#define v8l_neq __v8l_neq
#define v16f_neq __v16f_neq
#define v16i_neq __v16i_neq

#define v1d_gt __v1d_gt
#define v1f_gt __v1f_gt
#define v1i_gt __v1i_gt
#define v1l_gt __v1l_gt
#define v2d_gt __v2d_gt
#define v2f_gt __v2f_gt
#define v2i_gt __v2i_gt
#define v2l_gt __v2l_gt
#define v4d_gt __v4d_gt
#define v4f_gt __v4f_gt
#define v4i_gt __v4i_gt
#define v4l_gt __v4l_gt
#define v8d_gt __v8d_gt
#define v8f_gt __v8f_gt
#define v8i_gt __v8i_gt
#define v8l_gt __v8l_gt
#define v16f_gt __v16f_gt
#define v16i_gt __v16i_gt

#define v1d_geq __v1d_geq
#define v1f_geq __v1f_geq
#define v1i_geq __v1i_geq
#define v1l_geq __v1l_geq
#define v2d_geq __v2d_geq
#define v2f_geq __v2f_geq
#define v2i_geq __v2i_geq
#define v2l_geq __v2l_geq
#define v4d_geq __v4d_geq
#define v4f_geq __v4f_geq
#define v4i_geq __v4i_geq
#define v4l_geq __v4l_geq
#define v8d_geq __v8d_geq
#define v8f_geq __v8f_geq
#define v8i_geq __v8i_geq
#define v8l_geq __v8l_geq
#define v16f_geq __v16f_geq
#define v16i_geq __v16i_geq

#define v1d_lt __v1d_lt
#define v1f_lt __v1f_lt
#define v1i_lt __v1i_lt
#define v1l_lt __v1l_lt
#define v2d_lt __v2d_lt
#define v2f_lt __v2f_lt
#define v2i_lt __v2i_lt
#define v2l_lt __v2l_lt
#define v4d_lt __v4d_lt
#define v4f_lt __v4f_lt
#define v4i_lt __v4i_lt
#define v4l_lt __v4l_lt
#define v8d_lt __v8d_lt
#define v8f_lt __v8f_lt
#define v8i_lt __v8i_lt
#define v8l_lt __v8l_lt
#define v16f_lt __v16f_lt
#define v16i_lt __v16i_lt

#define v1d_leq __v1d_leq
#define v1f_leq __v1f_leq
#define v1i_leq __v1i_leq
#define v1l_leq __v1l_leq
#define v2d_leq __v2d_leq
#define v2f_leq __v2f_leq
#define v2i_leq __v2i_leq
#define v2l_leq __v2l_leq
#define v4d_leq __v4d_leq
#define v4f_leq __v4f_leq
#define v4i_leq __v4i_leq
#define v4l_leq __v4l_leq
#define v8d_leq __v8d_leq
#define v8f_leq __v8f_leq
#define v8i_leq __v8i_leq
#define v8l_leq __v8l_leq
#define v16f_leq __v16f_leq
#define v16i_leq __v16i_leq

/* LOGIC */

#define v1d_and __v1d_and
#define v1f_and __v1f_and
#define v1i_and __v1i_and
#define v1l_and __v1l_and
#define v2d_and __v2d_and
#define v2f_and __v2f_and
#define v2i_and __v2i_and
#define v2l_and __v2l_and
#define v4d_and __v4d_and
#define v4f_and __v4f_and
#define v4i_and __v4i_and
#define v4l_and __v4l_and
#define v8d_and __v8d_and
#define v8f_and __v8f_and
#define v8i_and __v8i_and
#define v8l_and __v8l_and
#define v16f_and __v16f_and
#define v16i_and __v16i_and

#define v1d_or __v1d_or
#define v1f_or __v1f_or
#define v1i_or __v1i_or
#define v1l_or __v1l_or
#define v2d_or __v2d_or
#define v2f_or __v2f_or
#define v2i_or __v2i_or
#define v2l_or __v2l_or
#define v4d_or __v4d_or
#define v4f_or __v4f_or
#define v4i_or __v4i_or
#define v4l_or __v4l_or
#define v8d_or __v8d_or
#define v8f_or __v8f_or
#define v8i_or __v8i_or
#define v8l_or __v8l_or
#define v16f_or __v16f_or
#define v16i_or __v16i_or

#define v1d_xor __v1d_xor
#define v1f_xor __v1f_xor
#define v1i_xor __v1i_xor
#define v1l_xor __v1l_xor
#define v2d_xor __v2d_xor
#define v2f_xor __v2f_xor
#define v2i_xor __v2i_xor
#define v2l_xor __v2l_xor
#define v4d_xor __v4d_xor
#define v4f_xor __v4f_xor
#define v4i_xor __v4i_xor
#define v4l_xor __v4l_xor
#define v8d_xor __v8d_xor
#define v8f_xor __v8f_xor
#define v8i_xor __v8i_xor
#define v8l_xor __v8l_xor
#define v16f_xor __v16f_xor
#define v16i_xor __v16i_xor

#define v1d_not(a)  v1d_xor((a), v1d_ones())
#define v1f_not(a)  v1f_xor((a), v1f_ones())
#define v1i_not(a)  v1i_xor((a), v1i_ones())
#define v1l_not(a)  v1l_xor((a), v1l_ones())
#define v2d_not(a)  v2d_xor((a), v2d_ones())
#define v2f_not(a)  v2f_xor((a), v2f_ones())
#define v2i_not(a)  v2i_xor((a), v2i_ones())
#define v2l_not(a)  v2l_xor((a), v2l_ones())
#define v4d_not(a)  v4d_xor((a), v4d_ones())
#define v4f_not(a)  v4f_xor((a), v4f_ones())
#define v4i_not(a)  v4i_xor((a), v4i_ones())
#define v4l_not(a)  v4l_xor((a), v4l_ones())
#define v8d_not(a)  v8d_xor((a), v8d_ones())
#define v8f_not(a)  v8f_xor((a), v8f_ones())
#define v8i_not(a)  v8i_xor((a), v8i_ones())
#define v8l_not(a)  v8l_xor((a), v8l_ones())
#define v16f_not(a)  v16f_xor((a), v16f_ones())
#define v16i_not(a)  v16i_xor((a), v16i_ones())

#define v1d_nand(a,b)  v1d_not(v1d_and((a), (b)))
#define v1f_nand(a,b)  v1f_not(v1f_and((a), (b)))
#define v1i_nand(a,b)  v1i_not(v1i_and((a), (b)))
#define v1l_nand(a,b)  v1l_not(v1l_and((a), (b)))
#define v2d_nand(a,b)  v2d_not(v2d_and((a), (b)))
#define v2f_nand(a,b)  v2f_not(v2f_and((a), (b)))
#define v2i_nand(a,b)  v2i_not(v2i_and((a), (b)))
#define v2l_nand(a,b)  v2l_not(v2l_and((a), (b)))
#define v4d_nand(a,b)  v4d_not(v4d_and((a), (b)))
#define v4f_nand(a,b)  v4f_not(v4f_and((a), (b)))
#define v4i_nand(a,b)  v4i_not(v4i_and((a), (b)))
#define v4l_nand(a,b)  v4l_not(v4l_and((a), (b)))
#define v8d_nand(a,b)  v8d_not(v8d_and((a), (b)))
#define v8f_nand(a,b)  v8f_not(v8f_and((a), (b)))
#define v8i_nand(a,b)  v8i_not(v8i_and((a), (b)))
#define v8l_nand(a,b)  v8l_not(v8l_and((a), (b)))
#define v16f_nand(a,b)  v16f_not(v16f_and((a), (b)))
#define v16i_nand(a,b)  v16i_not(v16i_and((a), (b)))

#define v1d_nor(a,b)  v1d_not(v1d_or((a), (b)))
#define v1f_nor(a,b)  v1f_not(v1f_or((a), (b)))
#define v1i_nor(a,b)  v1i_not(v1i_or((a), (b)))
#define v1l_nor(a,b)  v1l_not(v1l_or((a), (b)))
#define v2d_nor(a,b)  v2d_not(v2d_or((a), (b)))
#define v2f_nor(a,b)  v2f_not(v2f_or((a), (b)))
#define v2i_nor(a,b)  v2i_not(v2i_or((a), (b)))
#define v2l_nor(a,b)  v2l_not(v2l_or((a), (b)))
#define v4d_nor(a,b)  v4d_not(v4d_or((a), (b)))
#define v4f_nor(a,b)  v4f_not(v4f_or((a), (b)))
#define v4i_nor(a,b)  v4i_not(v4i_or((a), (b)))
#define v4l_nor(a,b)  v4l_not(v4l_or((a), (b)))
#define v8d_nor(a,b)  v8d_not(v8d_or((a), (b)))
#define v8f_nor(a,b)  v8f_not(v8f_or((a), (b)))
#define v8i_nor(a,b)  v8i_not(v8i_or((a), (b)))
#define v8l_nor(a,b)  v8l_not(v8l_or((a), (b)))
#define v16f_nor(a,b)  v16f_not(v16f_or((a), (b)))
#define v16i_nor(a,b)  v16i_not(v16i_or((a), (b)))

#define v1d_nxor(a,b)  v1d_not(v1d_xor((a), (b)))
#define v1f_nxor(a,b)  v1f_not(v1f_xor((a), (b)))
#define v1i_nxor(a,b)  v1i_not(v1i_xor((a), (b)))
#define v1l_nxor(a,b)  v1l_not(v1l_xor((a), (b)))
#define v2d_nxor(a,b)  v2d_not(v2d_xor((a), (b)))
#define v2f_nxor(a,b)  v2f_not(v2f_xor((a), (b)))
#define v2i_nxor(a,b)  v2i_not(v2i_xor((a), (b)))
#define v2l_nxor(a,b)  v2l_not(v2l_xor((a), (b)))
#define v4d_nxor(a,b)  v4d_not(v4d_xor((a), (b)))
#define v4f_nxor(a,b)  v4f_not(v4f_xor((a), (b)))
#define v4i_nxor(a,b)  v4i_not(v4i_xor((a), (b)))
#define v4l_nxor(a,b)  v4l_not(v4l_xor((a), (b)))
#define v8d_nxor(a,b)  v8d_not(v8d_xor((a), (b)))
#define v8f_nxor(a,b)  v8f_not(v8f_xor((a), (b)))
#define v8i_nxor(a,b)  v8i_not(v8i_xor((a), (b)))
#define v8l_nxor(a,b)  v8l_not(v8l_xor((a), (b)))
#define v16f_nxor(a,b)  v16f_not(v16f_xor((a), (b)))
#define v16i_nxor(a,b)  v16i_not(v16i_xor((a), (b)))

#define v1d_andnot(a,b)  v1d_and((a), v1d_not(b))
#define v1f_andnot(a,b)  v1f_and((a), v1f_not(b))
#define v1i_andnot(a,b)  v1i_and((a), v1i_not(b))
#define v1l_andnot(a,b)  v1l_and((a), v1l_not(b))
#define v2d_andnot(a,b)  v2d_and((a), v2d_not(b))
#define v2f_andnot(a,b)  v2f_and((a), v2f_not(b))
#define v2i_andnot(a,b)  v2i_and((a), v2i_not(b))
#define v2l_andnot(a,b)  v2l_and((a), v2l_not(b))
#define v4d_andnot(a,b)  v4d_and((a), v4d_not(b))
#define v4f_andnot(a,b)  v4f_and((a), v4f_not(b))
#define v4i_andnot(a,b)  v4i_and((a), v4i_not(b))
#define v4l_andnot(a,b)  v4l_and((a), v4l_not(b))
#define v8d_andnot(a,b)  v8d_and((a), v8d_not(b))
#define v8f_andnot(a,b)  v8f_and((a), v8f_not(b))
#define v8i_andnot(a,b)  v8i_and((a), v8i_not(b))
#define v8l_andnot(a,b)  v8l_and((a), v8l_not(b))
#define v16f_andnot(a,b)  v16f_and((a), v16f_not(b))
#define v16i_andnot(a,b)  v16i_and((a), v16i_not(b))

#define v1d_ornot(a,b)  v1d_or((a), v1d_not(b))
#define v1f_ornot(a,b)  v1f_or((a), v1f_not(b))
#define v1i_ornot(a,b)  v1i_or((a), v1i_not(b))
#define v1l_ornot(a,b)  v1l_or((a), v1l_not(b))
#define v2d_ornot(a,b)  v2d_or((a), v2d_not(b))
#define v2f_ornot(a,b)  v2f_or((a), v2f_not(b))
#define v2i_ornot(a,b)  v2i_or((a), v2i_not(b))
#define v2l_ornot(a,b)  v2l_or((a), v2l_not(b))
#define v4d_ornot(a,b)  v4d_or((a), v4d_not(b))
#define v4f_ornot(a,b)  v4f_or((a), v4f_not(b))
#define v4i_ornot(a,b)  v4i_or((a), v4i_not(b))
#define v4l_ornot(a,b)  v4l_or((a), v4l_not(b))
#define v8d_ornot(a,b)  v8d_or((a), v8d_not(b))
#define v8f_ornot(a,b)  v8f_or((a), v8f_not(b))
#define v8i_ornot(a,b)  v8i_or((a), v8i_not(b))
#define v8l_ornot(a,b)  v8l_or((a), v8l_not(b))
#define v16f_ornot(a,b)  v16f_or((a), v16f_not(b))
#define v16i_ornot(a,b)  v16i_or((a), v16i_not(b))


/* ARITHMETIC AND MATH */


#define v1d_add __v1d_add
#define v1f_add __v1f_add
#define v1i_add __v1i_add
#define v1l_add __v1l_add
#define v2d_add __v2d_add
#define v2f_add __v2f_add
#define v2i_add __v2i_add
#define v2l_add __v2l_add
#define v4d_add __v4d_add
#define v4f_add __v4f_add
#define v4i_add __v4i_add
#define v4l_add __v4l_add
#define v8d_add __v8d_add
#define v8f_add __v8f_add
#define v8i_add __v8i_add
#define v8l_add __v8l_add
#define v16f_add __v16f_add
#define v16i_add __v16i_add

#define v1d_sub __v1d_sub
#define v1f_sub __v1f_sub
#define v1i_sub __v1i_sub
#define v1l_sub __v1l_sub
#define v2d_sub __v2d_sub
#define v2f_sub __v2f_sub
#define v2i_sub __v2i_sub
#define v2l_sub __v2l_sub
#define v4d_sub __v4d_sub
#define v4f_sub __v4f_sub
#define v4i_sub __v4i_sub
#define v4l_sub __v4l_sub
#define v8d_sub __v8d_sub
#define v8f_sub __v8f_sub
#define v8i_sub __v8i_sub
#define v8l_sub __v8l_sub
#define v16f_sub __v16f_sub
#define v16i_sub __v16i_sub

#define v1d_neg(a)  v1d_sub(v1d_zero(), (a))
#define v1f_neg(a)  v1f_sub(v1f_zero(), (a))
#define v1i_neg(a)  v1i_sub(v1i_zero(), (a))
#define v1l_neg(a)  v1l_sub(v1l_zero(), (a))
#define v2d_neg(a)  v2d_sub(v2d_zero(), (a))
#define v2f_neg(a)  v2f_sub(v2f_zero(), (a))
#define v2i_neg(a)  v2i_sub(v2i_zero(), (a))
#define v2l_neg(a)  v2l_sub(v2l_zero(), (a))
#define v4d_neg(a)  v4d_sub(v4d_zero(), (a))
#define v4f_neg(a)  v4f_sub(v4f_zero(), (a))
#define v4i_neg(a)  v4i_sub(v4i_zero(), (a))
#define v4l_neg(a)  v4l_sub(v4l_zero(), (a))
#define v8d_neg(a)  v8d_sub(v8d_zero(), (a))
#define v8f_neg(a)  v8f_sub(v8f_zero(), (a))
#define v8i_neg(a)  v8i_sub(v8i_zero(), (a))
#define v8l_neg(a)  v8l_sub(v8l_zero(), (a))
#define v16f_neg(a)  v16f_sub(v16f_zero(), (a))
#define v16i_neg(a)  v16i_sub(v16i_zero(), (a))

#define v1d_min(a,b)  v1d_mask_move(v1d_lt(a, b), b, a)
#define v1f_min(a,b)  v1f_mask_move(v1f_lt(a, b), b, a)
#define v1i_min(a,b)  v1i_mask_move(v1i_lt(a, b), b, a)
#define v1l_min(a,b)  v1l_mask_move(v1l_lt(a, b), b, a)
#define v2d_min(a,b)  v2d_mask_move(v2d_lt(a, b), b, a)
#define v2f_min(a,b)  v2f_mask_move(v2f_lt(a, b), b, a)
#define v2i_min(a,b)  v2i_mask_move(v2i_lt(a, b), b, a)
#define v2l_min(a,b)  v2l_mask_move(v2l_lt(a, b), b, a)
#define v4d_min(a,b)  v4d_mask_move(v4d_lt(a, b), b, a)
#define v4f_min(a,b)  v4f_mask_move(v4f_lt(a, b), b, a)
#define v4i_min(a,b)  v4i_mask_move(v4i_lt(a, b), b, a)
#define v4l_min(a,b)  v4l_mask_move(v4l_lt(a, b), b, a)
#define v8d_min(a,b)  v8d_mask_move(v8d_lt(a, b), b, a)
#define v8f_min(a,b)  v8f_mask_move(v8f_lt(a, b), b, a)
#define v8i_min(a,b)  v8i_mask_move(v8i_lt(a, b), b, a)
#define v8l_min(a,b)  v8l_mask_move(v8l_lt(a, b), b, a)
#define v16f_min(a,b)  v16f_mask_move(v16f_lt(a, b), b, a)
#define v16i_min(a,b)  v16i_mask_move(v16i_lt(a, b), b, a)

#define v1d_max(a,b)  v1d_mask_move(v1d_gt(a, b), b, a)
#define v1f_max(a,b)  v1f_mask_move(v1f_gt(a, b), b, a)
#define v1i_max(a,b)  v1i_mask_move(v1i_gt(a, b), b, a)
#define v1l_max(a,b)  v1l_mask_move(v1l_gt(a, b), b, a)
#define v2d_max(a,b)  v2d_mask_move(v2d_gt(a, b), b, a)
#define v2f_max(a,b)  v2f_mask_move(v2f_gt(a, b), b, a)
#define v2i_max(a,b)  v2i_mask_move(v2i_gt(a, b), b, a)
#define v2l_max(a,b)  v2l_mask_move(v2l_gt(a, b), b, a)
#define v4d_max(a,b)  v4d_mask_move(v4d_gt(a, b), b, a)
#define v4f_max(a,b)  v4f_mask_move(v4f_gt(a, b), b, a)
#define v4i_max(a,b)  v4i_mask_move(v4i_gt(a, b), b, a)
#define v4l_max(a,b)  v4l_mask_move(v4l_gt(a, b), b, a)
#define v8d_max(a,b)  v8d_mask_move(v8d_gt(a, b), b, a)
#define v8f_max(a,b)  v8f_mask_move(v8f_gt(a, b), b, a)
#define v8i_max(a,b)  v8i_mask_move(v8i_gt(a, b), b, a)
#define v8l_max(a,b)  v8l_mask_move(v8l_gt(a, b), b, a)
#define v16f_max(a,b)  v16f_mask_move(v16f_gt(a, b), b, a)
#define v16i_max(a,b)  v16i_mask_move(v16i_gt(a, b), b, a)

#define v1d_abs(a)  v1d_max((a), v1d_neg(a))
#define v1f_abs(a)  v1f_max((a), v1f_neg(a))
#define v1i_abs(a)  v1i_max((a), v1i_neg(a))
#define v1l_abs(a)  v1l_max((a), v1l_neg(a))
#define v2d_abs(a)  v2d_max((a), v2d_neg(a))
#define v2f_abs(a)  v2f_max((a), v2f_neg(a))
#define v2i_abs(a)  v2i_max((a), v2i_neg(a))
#define v2l_abs(a)  v2l_max((a), v2l_neg(a))
#define v4d_abs(a)  v4d_max((a), v4d_neg(a))
#define v4f_abs(a)  v4f_max((a), v4f_neg(a))
#define v4i_abs(a)  v4i_max((a), v4i_neg(a))
#define v4l_abs(a)  v4l_max((a), v4l_neg(a))
#define v8d_abs(a)  v8d_max((a), v8d_neg(a))
#define v8f_abs(a)  v8f_max((a), v8f_neg(a))
#define v8i_abs(a)  v8i_max((a), v8i_neg(a))
#define v8l_abs(a)  v8l_max((a), v8l_neg(a))
#define v16f_abs(a)  v16f_max((a), v16f_neg(a))
#define v16i_abs(a)  v16i_max((a), v16i_neg(a))

#define v1d_mul __v1d_mul
#define v1f_mul __v1f_mul
#define v1i_mul __v1i_mul
#define v1l_mul __v1l_mul
#define v2d_mul __v2d_mul
#define v2f_mul __v2f_mul
#define v2i_mul __v2i_mul
#define v2l_mul __v2l_mul
#define v4d_mul __v4d_mul
#define v4f_mul __v4f_mul
#define v4i_mul __v4i_mul
#define v4l_mul __v4l_mul
#define v8d_mul __v8d_mul
#define v8f_mul __v8f_mul
#define v8i_mul __v8i_mul
#define v8l_mul __v8l_mul
#define v16f_mul __v16f_mul
#define v16i_mul __v16i_mul

#define v1d_div __v1d_div
#define v1f_div __v1f_div
#define v1i_div __v1i_div
#define v1l_div __v1l_div
#define v2d_div __v2d_div
#define v2f_div __v2f_div
#define v2i_div __v2i_div
#define v2l_div __v2l_div
#define v4d_div __v4d_div
#define v4f_div __v4f_div
#define v4i_div __v4i_div
#define v4l_div __v4l_div
#define v8d_div __v8d_div
#define v8f_div __v8f_div
#define v8i_div __v8i_div
#define v8l_div __v8l_div
#define v16f_div __v16f_div
#define v16i_div __v16i_div

#define v1d_rcp(a)  v1d_div(v1d_one(), (a))
#define v1f_rcp(a)  v1f_div(v1f_one(), (a))
#define v1i_rcp(a)  v1i_div(v1i_one(), (a))
#define v1l_rcp(a)  v1l_div(v1l_one(), (a))
#define v2d_rcp(a)  v2d_div(v2d_one(), (a))
#define v2f_rcp(a)  v2f_div(v2f_one(), (a))
#define v2i_rcp(a)  v2i_div(v2i_one(), (a))
#define v2l_rcp(a)  v2l_div(v2l_one(), (a))
#define v4d_rcp(a)  v4d_div(v4d_one(), (a))
#define v4f_rcp(a)  v4f_div(v4f_one(), (a))
#define v4i_rcp(a)  v4i_div(v4i_one(), (a))
#define v4l_rcp(a)  v4l_div(v4l_one(), (a))
#define v8d_rcp(a)  v8d_div(v8d_one(), (a))
#define v8f_rcp(a)  v8f_div(v8f_one(), (a))
#define v8i_rcp(a)  v8i_div(v8i_one(), (a))
#define v8l_rcp(a)  v8l_div(v8l_one(), (a))
#define v16f_rcp(a)  v16f_div(v16f_one(), (a))
#define v16i_rcp(a)  v16i_div(v16i_one(), (a))

#define v1d_frcp(a)  v1d_rcp(a)
#define v1f_frcp(a)  v1f_rcp(a)
#define v1i_frcp(a)  v1i_rcp(a)
#define v1l_frcp(a)  v1l_rcp(a)
#define v2d_frcp(a)  v2d_rcp(a)
#define v2f_frcp(a)  v2f_rcp(a)
#define v2i_frcp(a)  v2i_rcp(a)
#define v2l_frcp(a)  v2l_rcp(a)
#define v4d_frcp(a)  v4d_rcp(a)
#define v4f_frcp(a)  v4f_rcp(a)
#define v4i_frcp(a)  v4i_rcp(a)
#define v4l_frcp(a)  v4l_rcp(a)
#define v8d_frcp(a)  v8d_rcp(a)
#define v8f_frcp(a)  v8f_rcp(a)
#define v8i_frcp(a)  v8i_rcp(a)
#define v8l_frcp(a)  v8l_rcp(a)
#define v16f_frcp(a)  v16f_rcp(a)
#define v16i_frcp(a)  v16i_rcp(a)

#define v1d_sqrt __v1d_sqrt
#define v1f_sqrt __v1f_sqrt
#define v1i_sqrt __v1i_sqrt
#define v1l_sqrt __v1l_sqrt
#define v2d_sqrt __v2d_sqrt
#define v2f_sqrt __v2f_sqrt
#define v2i_sqrt __v2i_sqrt
#define v2l_sqrt __v2l_sqrt
#define v4d_sqrt __v4d_sqrt
#define v4f_sqrt __v4f_sqrt
#define v4i_sqrt __v4i_sqrt
#define v4l_sqrt __v4l_sqrt
#define v8d_sqrt __v8d_sqrt
#define v8f_sqrt __v8f_sqrt
#define v8i_sqrt __v8i_sqrt
#define v8l_sqrt __v8l_sqrt
#define v16f_sqrt __v16f_sqrt
#define v16i_sqrt __v16i_sqrt

#define v1d_rsqrt(a)  v1d_rcp(v1d_sqrt(a))
#define v1f_rsqrt(a)  v1f_rcp(v1f_sqrt(a))
#define v1i_rsqrt(a)  v1i_rcp(v1i_sqrt(a))
#define v1l_rsqrt(a)  v1l_rcp(v1l_sqrt(a))
#define v2d_rsqrt(a)  v2d_rcp(v2d_sqrt(a))
#define v2f_rsqrt(a)  v2f_rcp(v2f_sqrt(a))
#define v2i_rsqrt(a)  v2i_rcp(v2i_sqrt(a))
#define v2l_rsqrt(a)  v2l_rcp(v2l_sqrt(a))
#define v4d_rsqrt(a)  v4d_rcp(v4d_sqrt(a))
#define v4f_rsqrt(a)  v4f_rcp(v4f_sqrt(a))
#define v4i_rsqrt(a)  v4i_rcp(v4i_sqrt(a))
#define v4l_rsqrt(a)  v4l_rcp(v4l_sqrt(a))
#define v8d_rsqrt(a)  v8d_rcp(v8d_sqrt(a))
#define v8f_rsqrt(a)  v8f_rcp(v8f_sqrt(a))
#define v8i_rsqrt(a)  v8i_rcp(v8i_sqrt(a))
#define v8l_rsqrt(a)  v8l_rcp(v8l_sqrt(a))
#define v16f_rsqrt(a)  v16f_rcp(v16f_sqrt(a))
#define v16i_rsqrt(a)  v16i_rcp(v16i_sqrt(a))

#define v1d_frsqrt(a)  v1d_frcp(v1d_sqrt(a))
#define v1f_frsqrt(a)  v1f_frcp(v1f_sqrt(a))
#define v1i_frsqrt(a)  v1i_frcp(v1i_sqrt(a))
#define v1l_frsqrt(a)  v1l_frcp(v1l_sqrt(a))
#define v2d_frsqrt(a)  v2d_frcp(v2d_sqrt(a))
#define v2f_frsqrt(a)  v2f_frcp(v2f_sqrt(a))
#define v2i_frsqrt(a)  v2i_frcp(v2i_sqrt(a))
#define v2l_frsqrt(a)  v2l_frcp(v2l_sqrt(a))
#define v4d_frsqrt(a)  v4d_frcp(v4d_sqrt(a))
#define v4f_frsqrt(a)  v4f_frcp(v4f_sqrt(a))
#define v4i_frsqrt(a)  v4i_frcp(v4i_sqrt(a))
#define v4l_frsqrt(a)  v4l_frcp(v4l_sqrt(a))
#define v8d_frsqrt(a)  v8d_frcp(v8d_sqrt(a))
#define v8f_frsqrt(a)  v8f_frcp(v8f_sqrt(a))
#define v8i_frsqrt(a)  v8i_frcp(v8i_sqrt(a))
#define v8l_frsqrt(a)  v8l_frcp(v8l_sqrt(a))
#define v16f_frsqrt(a)  v16f_frcp(v16f_sqrt(a))
#define v16i_frsqrt(a)  v16i_frcp(v16i_sqrt(a))

/* Fused Multiply-Add */
#define v1d_fmadd(a,b,acc)  v1d_add(v1d_mul((a), (b)), (acc))
#define v1f_fmadd(a,b,acc)  v1f_add(v1f_mul((a), (b)), (acc))
#define v1i_fmadd(a,b,acc)  v1i_add(v1i_mul((a), (b)), (acc))
#define v1l_fmadd(a,b,acc)  v1l_add(v1l_mul((a), (b)), (acc))
#define v2d_fmadd(a,b,acc)  v2d_add(v2d_mul((a), (b)), (acc))
#define v2f_fmadd(a,b,acc)  v2f_add(v2f_mul((a), (b)), (acc))
#define v2i_fmadd(a,b,acc)  v2i_add(v2i_mul((a), (b)), (acc))
#define v2l_fmadd(a,b,acc)  v2l_add(v2l_mul((a), (b)), (acc))
#define v4d_fmadd(a,b,acc)  v4d_add(v4d_mul((a), (b)), (acc))
#define v4f_fmadd(a,b,acc)  v4f_add(v4f_mul((a), (b)), (acc))
#define v4i_fmadd(a,b,acc)  v4i_add(v4i_mul((a), (b)), (acc))
#define v4l_fmadd(a,b,acc)  v4l_add(v4l_mul((a), (b)), (acc))
#define v8d_fmadd(a,b,acc)  v8d_add(v8d_mul((a), (b)), (acc))
#define v8f_fmadd(a,b,acc)  v8f_add(v8f_mul((a), (b)), (acc))
#define v8i_fmadd(a,b,acc)  v8i_add(v8i_mul((a), (b)), (acc))
#define v8l_fmadd(a,b,acc)  v8l_add(v8l_mul((a), (b)), (acc))
#define v16f_fmadd(a,b,acc)  v16f_add(v16f_mul((a), (b)), (acc))
#define v16i_fmadd(a,b,acc)  v16i_add(v16i_mul((a), (b)), (acc))

#define v1d_fmsub(a,b,acc)  v1d_sub(v1d_mul((a), (b)), (acc))
#define v1f_fmsub(a,b,acc)  v1f_sub(v1f_mul((a), (b)), (acc))
#define v1i_fmsub(a,b,acc)  v1i_sub(v1i_mul((a), (b)), (acc))
#define v1l_fmsub(a,b,acc)  v1l_sub(v1l_mul((a), (b)), (acc))
#define v2d_fmsub(a,b,acc)  v2d_sub(v2d_mul((a), (b)), (acc))
#define v2f_fmsub(a,b,acc)  v2f_sub(v2f_mul((a), (b)), (acc))
#define v2i_fmsub(a,b,acc)  v2i_sub(v2i_mul((a), (b)), (acc))
#define v2l_fmsub(a,b,acc)  v2l_sub(v2l_mul((a), (b)), (acc))
#define v4d_fmsub(a,b,acc)  v4d_sub(v4d_mul((a), (b)), (acc))
#define v4f_fmsub(a,b,acc)  v4f_sub(v4f_mul((a), (b)), (acc))
#define v4i_fmsub(a,b,acc)  v4i_sub(v4i_mul((a), (b)), (acc))
#define v4l_fmsub(a,b,acc)  v4l_sub(v4l_mul((a), (b)), (acc))
#define v8d_fmsub(a,b,acc)  v8d_sub(v8d_mul((a), (b)), (acc))
#define v8f_fmsub(a,b,acc)  v8f_sub(v8f_mul((a), (b)), (acc))
#define v8i_fmsub(a,b,acc)  v8i_sub(v8i_mul((a), (b)), (acc))
#define v8l_fmsub(a,b,acc)  v8l_sub(v8l_mul((a), (b)), (acc))
#define v16f_fmsub(a,b,acc)  v16f_sub(v16f_mul((a), (b)), (acc))
#define v16i_fmsub(a,b,acc)  v16i_sub(v16i_mul((a), (b)), (acc))

#define v1d_fnmadd(a,b,acc)  v1d_sub((acc), v1d_mul((a), (b)))
#define v1f_fnmadd(a,b,acc)  v1f_sub((acc), v1f_mul((a), (b)))
#define v1i_fnmadd(a,b,acc)  v1i_sub((acc), v1i_mul((a), (b)))
#define v1l_fnmadd(a,b,acc)  v1l_sub((acc), v1l_mul((a), (b)))
#define v2d_fnmadd(a,b,acc)  v2d_sub((acc), v2d_mul((a), (b)))
#define v2f_fnmadd(a,b,acc)  v2f_sub((acc), v2f_mul((a), (b)))
#define v2i_fnmadd(a,b,acc)  v2i_sub((acc), v2i_mul((a), (b)))
#define v2l_fnmadd(a,b,acc)  v2l_sub((acc), v2l_mul((a), (b)))
#define v4d_fnmadd(a,b,acc)  v4d_sub((acc), v4d_mul((a), (b)))
#define v4f_fnmadd(a,b,acc)  v4f_sub((acc), v4f_mul((a), (b)))
#define v4i_fnmadd(a,b,acc)  v4i_sub((acc), v4i_mul((a), (b)))
#define v4l_fnmadd(a,b,acc)  v4l_sub((acc), v4l_mul((a), (b)))
#define v8d_fnmadd(a,b,acc)  v8d_sub((acc), v8d_mul((a), (b)))
#define v8f_fnmadd(a,b,acc)  v8f_sub((acc), v8f_mul((a), (b)))
#define v8i_fnmadd(a,b,acc)  v8i_sub((acc), v8i_mul((a), (b)))
#define v8l_fnmadd(a,b,acc)  v8l_sub((acc), v8l_mul((a), (b)))
#define v16f_fnmadd(a,b,acc)  v16f_sub((acc), v16f_mul((a), (b)))
#define v16i_fnmadd(a,b,acc)  v16i_sub((acc), v16i_mul((a), (b)))

#define v1d_fnmsub(a,b,acc)  v1d_sub(v1d_neg(acc), v1d_mul((a), (b)))
#define v1f_fnmsub(a,b,acc)  v1f_sub(v1f_neg(acc), v1f_mul((a), (b)))
#define v1i_fnmsub(a,b,acc)  v1i_sub(v1i_neg(acc), v1i_mul((a), (b)))
#define v1l_fnmsub(a,b,acc)  v1l_sub(v1l_neg(acc), v1l_mul((a), (b)))
#define v2d_fnmsub(a,b,acc)  v2d_sub(v2d_neg(acc), v2d_mul((a), (b)))
#define v2f_fnmsub(a,b,acc)  v2f_sub(v2f_neg(acc), v2f_mul((a), (b)))
#define v2i_fnmsub(a,b,acc)  v2i_sub(v2i_neg(acc), v2i_mul((a), (b)))
#define v2l_fnmsub(a,b,acc)  v2l_sub(v2l_neg(acc), v2l_mul((a), (b)))
#define v4d_fnmsub(a,b,acc)  v4d_sub(v4d_neg(acc), v4d_mul((a), (b)))
#define v4f_fnmsub(a,b,acc)  v4f_sub(v4f_neg(acc), v4f_mul((a), (b)))
#define v4i_fnmsub(a,b,acc)  v4i_sub(v4i_neg(acc), v4i_mul((a), (b)))
#define v4l_fnmsub(a,b,acc)  v4l_sub(v4l_neg(acc), v4l_mul((a), (b)))
#define v8d_fnmsub(a,b,acc)  v8d_sub(v8d_neg(acc), v8d_mul((a), (b)))
#define v8f_fnmsub(a,b,acc)  v8f_sub(v8f_neg(acc), v8f_mul((a), (b)))
#define v8i_fnmsub(a,b,acc)  v8i_sub(v8i_neg(acc), v8i_mul((a), (b)))
#define v8l_fnmsub(a,b,acc)  v8l_sub(v8l_neg(acc), v8l_mul((a), (b)))
#define v16f_fnmsub(a,b,acc)  v16f_sub(v16f_neg(acc), v16f_mul((a), (b)))
#define v16i_fnmsub(a,b,acc)  v16i_sub(v16i_neg(acc), v16i_mul((a), (b)))

/* MERGES */

#define v2d_merge2_v1d __v2d_merge2_v1d
#define v2f_merge2_v1f __v2f_merge2_v1f
#define v2i_merge2_v1i __v2i_merge2_v1i
#define v2l_merge2_v1l __v2l_merge2_v1l
#define v4d_merge2_v2d __v4d_merge2_v2d
#define v4f_merge2_v2f __v4f_merge2_v2f
#define v4i_merge2_v2i __v4i_merge2_v2i
#define v4l_merge2_v2l __v4l_merge2_v2l
#define v8d_merge2_v4d __v8d_merge2_v4d
#define v8f_merge2_v4f __v8f_merge2_v4f
#define v8i_merge2_v4i __v8i_merge2_v4i
#define v8l_merge2_v4l __v8l_merge2_v4l
#define v16f_merge2_v8f __v16f_merge2_v8f
#define v16i_merge2_v8i __v16i_merge2_v8i
#define v4d_merge4_v1d(a0, a1, a2, a3)  v4d_merge2_v2d(v2d_merge2_v1d((a0), (a1)), v2d_merge2_v1d((a2), (a3)))
#define v4f_merge4_v1f(a0, a1, a2, a3)  v4f_merge2_v2f(v2f_merge2_v1f((a0), (a1)), v2f_merge2_v1f((a2), (a3)))
#define v4i_merge4_v1i(a0, a1, a2, a3)  v4i_merge2_v2i(v2i_merge2_v1i((a0), (a1)), v2i_merge2_v1i((a2), (a3)))
#define v4l_merge4_v1l(a0, a1, a2, a3)  v4l_merge2_v2l(v2l_merge2_v1l((a0), (a1)), v2l_merge2_v1l((a2), (a3)))
#define v8d_merge4_v2d(a0, a1, a2, a3)  v8d_merge2_v4d(v4d_merge2_v2d((a0), (a1)), v4d_merge2_v2d((a2), (a3)))
#define v8f_merge4_v2f(a0, a1, a2, a3)  v8f_merge2_v4f(v4f_merge2_v2f((a0), (a1)), v4f_merge2_v2f((a2), (a3)))
#define v8i_merge4_v2i(a0, a1, a2, a3)  v8i_merge2_v4i(v4i_merge2_v2i((a0), (a1)), v4i_merge2_v2i((a2), (a3)))
#define v8l_merge4_v2l(a0, a1, a2, a3)  v8l_merge2_v4l(v4l_merge2_v2l((a0), (a1)), v4l_merge2_v2l((a2), (a3)))
#define v16f_merge4_v4f(a0, a1, a2, a3)  v16f_merge2_v8f(v8f_merge2_v4f((a0), (a1)), v8f_merge2_v4f((a2), (a3)))
#define v16i_merge4_v4i(a0, a1, a2, a3)  v16i_merge2_v8i(v8i_merge2_v4i((a0), (a1)), v8i_merge2_v4i((a2), (a3)))
#define v8d_merge8_v1d(a0, a1, a2, a3, a4, a5, a6, a7)  v8d_merge2_v4d(v4d_merge4_v1d((a0), (a1), (a2), (a3)), v4d_merge4_v1d((a4), (a5), (a6), (a7)))
#define v8f_merge8_v1f(a0, a1, a2, a3, a4, a5, a6, a7)  v8f_merge2_v4f(v4f_merge4_v1f((a0), (a1), (a2), (a3)), v4f_merge4_v1f((a4), (a5), (a6), (a7)))
#define v8i_merge8_v1i(a0, a1, a2, a3, a4, a5, a6, a7)  v8i_merge2_v4i(v4i_merge4_v1i((a0), (a1), (a2), (a3)), v4i_merge4_v1i((a4), (a5), (a6), (a7)))
#define v8l_merge8_v1l(a0, a1, a2, a3, a4, a5, a6, a7)  v8l_merge2_v4l(v4l_merge4_v1l((a0), (a1), (a2), (a3)), v4l_merge4_v1l((a4), (a5), (a6), (a7)))
#define v16f_merge8_v2f(a0, a1, a2, a3, a4, a5, a6, a7)  v16f_merge2_v8f(v8f_merge4_v2f((a0), (a1), (a2), (a3)), v8f_merge4_v2f((a4), (a5), (a6), (a7)))
#define v16i_merge8_v2i(a0, a1, a2, a3, a4, a5, a6, a7)  v16i_merge2_v8i(v8i_merge4_v2i((a0), (a1), (a2), (a3)), v8i_merge4_v2i((a4), (a5), (a6), (a7)))
#define v16f_merge16_v1f(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15)  v16f_merge2_v8f(v8f_merge8_v1f((a0), (a1), (a2), (a3), (a4), (a5), (a6), (a7)), v8f_merge8_v1f((a8), (a9), (a10), (a11), (a12), (a13), (a14), (a15)))
#define v16i_merge16_v1i(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15)  v16i_merge2_v8i(v8i_merge8_v1i((a0), (a1), (a2), (a3), (a4), (a5), (a6), (a7)), v8i_merge8_v1i((a8), (a9), (a10), (a11), (a12), (a13), (a14), (a15)))

#define v2d_rmerge2_v1d(a1, a0)  v2d_merge2_v1d((a0), (a1))
#define v2f_rmerge2_v1f(a1, a0)  v2f_merge2_v1f((a0), (a1))
#define v2i_rmerge2_v1i(a1, a0)  v2i_merge2_v1i((a0), (a1))
#define v2l_rmerge2_v1l(a1, a0)  v2l_merge2_v1l((a0), (a1))
#define v4d_rmerge2_v2d(a1, a0)  v4d_merge2_v2d((a0), (a1))
#define v4f_rmerge2_v2f(a1, a0)  v4f_merge2_v2f((a0), (a1))
#define v4i_rmerge2_v2i(a1, a0)  v4i_merge2_v2i((a0), (a1))
#define v4l_rmerge2_v2l(a1, a0)  v4l_merge2_v2l((a0), (a1))
#define v8d_rmerge2_v4d(a1, a0)  v8d_merge2_v4d((a0), (a1))
#define v8f_rmerge2_v4f(a1, a0)  v8f_merge2_v4f((a0), (a1))
#define v8i_rmerge2_v4i(a1, a0)  v8i_merge2_v4i((a0), (a1))
#define v8l_rmerge2_v4l(a1, a0)  v8l_merge2_v4l((a0), (a1))
#define v16f_rmerge2_v8f(a1, a0)  v16f_merge2_v8f((a0), (a1))
#define v16i_rmerge2_v8i(a1, a0)  v16i_merge2_v8i((a0), (a1))
#define v4d_rmerge4_v1d(a3, a2, a1, a0)  v4d_merge4_v1d((a0), (a1), (a2), (a3))
#define v4f_rmerge4_v1f(a3, a2, a1, a0)  v4f_merge4_v1f((a0), (a1), (a2), (a3))
#define v4i_rmerge4_v1i(a3, a2, a1, a0)  v4i_merge4_v1i((a0), (a1), (a2), (a3))
#define v4l_rmerge4_v1l(a3, a2, a1, a0)  v4l_merge4_v1l((a0), (a1), (a2), (a3))
#define v8d_rmerge4_v2d(a3, a2, a1, a0)  v8d_merge4_v2d((a0), (a1), (a2), (a3))
#define v8f_rmerge4_v2f(a3, a2, a1, a0)  v8f_merge4_v2f((a0), (a1), (a2), (a3))
#define v8i_rmerge4_v2i(a3, a2, a1, a0)  v8i_merge4_v2i((a0), (a1), (a2), (a3))
#define v8l_rmerge4_v2l(a3, a2, a1, a0)  v8l_merge4_v2l((a0), (a1), (a2), (a3))
#define v16f_rmerge4_v4f(a3, a2, a1, a0)  v16f_merge4_v4f((a0), (a1), (a2), (a3))
#define v16i_rmerge4_v4i(a3, a2, a1, a0)  v16i_merge4_v4i((a0), (a1), (a2), (a3))
#define v8d_rmerge8_v1d(a7, a6, a5, a4, a3, a2, a1, a0)  v8d_merge8_v1d((a0), (a1), (a2), (a3), (a4), (a5), (a6), (a7))
#define v8f_rmerge8_v1f(a7, a6, a5, a4, a3, a2, a1, a0)  v8f_merge8_v1f((a0), (a1), (a2), (a3), (a4), (a5), (a6), (a7))
#define v8i_rmerge8_v1i(a7, a6, a5, a4, a3, a2, a1, a0)  v8i_merge8_v1i((a0), (a1), (a2), (a3), (a4), (a5), (a6), (a7))
#define v8l_rmerge8_v1l(a7, a6, a5, a4, a3, a2, a1, a0)  v8l_merge8_v1l((a0), (a1), (a2), (a3), (a4), (a5), (a6), (a7))
#define v16f_rmerge8_v2f(a7, a6, a5, a4, a3, a2, a1, a0)  v16f_merge8_v2f((a0), (a1), (a2), (a3), (a4), (a5), (a6), (a7))
#define v16i_rmerge8_v2i(a7, a6, a5, a4, a3, a2, a1, a0)  v16i_merge8_v2i((a0), (a1), (a2), (a3), (a4), (a5), (a6), (a7))
#define v16f_rmerge16_v1f(a15, a14, a13, a12, a11, a10, a9, a8, a7, a6, a5, a4, a3, a2, a1, a0)  v16f_merge16_v1f((a0), (a1), (a2), (a3), (a4), (a5), (a6), (a7), (a8), (a9), (a10), (a11), (a12), (a13), (a14), (a15))
#define v16i_rmerge16_v1i(a15, a14, a13, a12, a11, a10, a9, a8, a7, a6, a5, a4, a3, a2, a1, a0)  v16i_merge16_v1i((a0), (a1), (a2), (a3), (a4), (a5), (a6), (a7), (a8), (a9), (a10), (a11), (a12), (a13), (a14), (a15))

#define v2d_merge_v1d v2d_merge2_v1d
#define v2f_merge_v1f v2f_merge2_v1f
#define v2i_merge_v1i v2i_merge2_v1i
#define v2l_merge_v1l v2l_merge2_v1l
#define v4d_merge_v2d v4d_merge2_v2d
#define v4f_merge_v2f v4f_merge2_v2f
#define v4i_merge_v2i v4i_merge2_v2i
#define v4l_merge_v2l v4l_merge2_v2l
#define v8d_merge_v4d v8d_merge2_v4d
#define v8f_merge_v4f v8f_merge2_v4f
#define v8i_merge_v4i v8i_merge2_v4i
#define v8l_merge_v4l v8l_merge2_v4l
#define v16f_merge_v8f v16f_merge2_v8f
#define v16i_merge_v8i v16i_merge2_v8i

#define v2d_rmerge_v1d v2d_rmerge2_v1d
#define v2f_rmerge_v1f v2f_rmerge2_v1f
#define v2i_rmerge_v1i v2i_rmerge2_v1i
#define v2l_rmerge_v1l v2l_rmerge2_v1l
#define v4d_rmerge_v2d v4d_rmerge2_v2d
#define v4f_rmerge_v2f v4f_rmerge2_v2f
#define v4i_rmerge_v2i v4i_rmerge2_v2i
#define v4l_rmerge_v2l v4l_rmerge2_v2l
#define v8d_rmerge_v4d v8d_rmerge2_v4d
#define v8f_rmerge_v4f v8f_rmerge2_v4f
#define v8i_rmerge_v4i v8i_rmerge2_v4i
#define v8l_rmerge_v4l v8l_rmerge2_v4l
#define v16f_rmerge_v8f v16f_rmerge2_v8f
#define v16i_rmerge_v8i v16i_rmerge2_v8i


/* HIGH and LOW manipulation */

#define v1d_get_low_v2d(a) v1d_cast_v2d(a)
#define v1f_get_low_v2f(a) v1f_cast_v2f(a)
#define v1i_get_low_v2i(a) v1i_cast_v2i(a)
#define v1l_get_low_v2l(a) v1l_cast_v2l(a)
#define v2d_get_low_v4d(a) v2d_cast_v4d(a)
#define v2f_get_low_v4f(a) v2f_cast_v4f(a)
#define v2i_get_low_v4i(a) v2i_cast_v4i(a)
#define v2l_get_low_v4l(a) v2l_cast_v4l(a)
#define v4d_get_low_v8d(a) v4d_cast_v8d(a)
#define v4f_get_low_v8f(a) v4f_cast_v8f(a)
#define v4i_get_low_v8i(a) v4i_cast_v8i(a)
#define v4l_get_low_v8l(a) v4l_cast_v8l(a)
#define v8f_get_low_v16f(a) v8f_cast_v16f(a)
#define v8i_get_low_v16i(a) v8i_cast_v16i(a)
#define v1d_get_high_v2d __v1d_get_high_v2d
#define v1f_get_high_v2f __v1f_get_high_v2f
#define v1i_get_high_v2i __v1i_get_high_v2i
#define v1l_get_high_v2l __v1l_get_high_v2l
#define v2d_get_high_v4d __v2d_get_high_v4d
#define v2f_get_high_v4f __v2f_get_high_v4f
#define v2i_get_high_v4i __v2i_get_high_v4i
#define v2l_get_high_v4l __v2l_get_high_v4l
#define v4d_get_high_v8d __v4d_get_high_v8d
#define v4f_get_high_v8f __v4f_get_high_v8f
#define v4i_get_high_v8i __v4i_get_high_v8i
#define v4l_get_high_v8l __v4l_get_high_v8l
#define v8f_get_high_v16f __v8f_get_high_v16f
#define v8i_get_high_v16i __v8i_get_high_v16i
#define v1d_get_hilo_v2d(a,high)  ((high) ? v1d_get_high_v2d(a) : v1d_get_low_v2d(a))
#define v1f_get_hilo_v2f(a,high)  ((high) ? v1f_get_high_v2f(a) : v1f_get_low_v2f(a))
#define v1i_get_hilo_v2i(a,high)  ((high) ? v1i_get_high_v2i(a) : v1i_get_low_v2i(a))
#define v1l_get_hilo_v2l(a,high)  ((high) ? v1l_get_high_v2l(a) : v1l_get_low_v2l(a))
#define v2d_get_hilo_v4d(a,high)  ((high) ? v2d_get_high_v4d(a) : v2d_get_low_v4d(a))
#define v2f_get_hilo_v4f(a,high)  ((high) ? v2f_get_high_v4f(a) : v2f_get_low_v4f(a))
#define v2i_get_hilo_v4i(a,high)  ((high) ? v2i_get_high_v4i(a) : v2i_get_low_v4i(a))
#define v2l_get_hilo_v4l(a,high)  ((high) ? v2l_get_high_v4l(a) : v2l_get_low_v4l(a))
#define v4d_get_hilo_v8d(a,high)  ((high) ? v4d_get_high_v8d(a) : v4d_get_low_v8d(a))
#define v4f_get_hilo_v8f(a,high)  ((high) ? v4f_get_high_v8f(a) : v4f_get_low_v8f(a))
#define v4i_get_hilo_v8i(a,high)  ((high) ? v4i_get_high_v8i(a) : v4i_get_low_v8i(a))
#define v4l_get_hilo_v8l(a,high)  ((high) ? v4l_get_high_v8l(a) : v4l_get_low_v8l(a))
#define v8f_get_hilo_v16f(a,high)  ((high) ? v8f_get_high_v16f(a) : v8f_get_low_v16f(a))
#define v8i_get_hilo_v16i(a,high)  ((high) ? v8i_get_high_v16i(a) : v8i_get_low_v16i(a))
#define v2d_set_low_v1d(src,low) v2d_merge2_v1d(low, v1d_get_high_v2d(src))
#define v2f_set_low_v1f(src,low) v2f_merge2_v1f(low, v1f_get_high_v2f(src))
#define v2i_set_low_v1i(src,low) v2i_merge2_v1i(low, v1i_get_high_v2i(src))
#define v2l_set_low_v1l(src,low) v2l_merge2_v1l(low, v1l_get_high_v2l(src))
#define v4d_set_low_v2d(src,low) v4d_merge2_v2d(low, v2d_get_high_v4d(src))
#define v4f_set_low_v2f(src,low) v4f_merge2_v2f(low, v2f_get_high_v4f(src))
#define v4i_set_low_v2i(src,low) v4i_merge2_v2i(low, v2i_get_high_v4i(src))
#define v4l_set_low_v2l(src,low) v4l_merge2_v2l(low, v2l_get_high_v4l(src))
#define v8d_set_low_v4d(src,low) v8d_merge2_v4d(low, v4d_get_high_v8d(src))
#define v8f_set_low_v4f(src,low) v8f_merge2_v4f(low, v4f_get_high_v8f(src))
#define v8i_set_low_v4i(src,low) v8i_merge2_v4i(low, v4i_get_high_v8i(src))
#define v8l_set_low_v4l(src,low) v8l_merge2_v4l(low, v4l_get_high_v8l(src))
#define v16f_set_low_v8f(src,low) v16f_merge2_v8f(low, v8f_get_high_v16f(src))
#define v16i_set_low_v8i(src,low) v16i_merge2_v8i(low, v8i_get_high_v16i(src))
#define v2d_set_high_v1d(src,high) v2d_merge2_v1d(v1d_get_low_v2d(src), high)
#define v2f_set_high_v1f(src,high) v2f_merge2_v1f(v1f_get_low_v2f(src), high)
#define v2i_set_high_v1i(src,high) v2i_merge2_v1i(v1i_get_low_v2i(src), high)
#define v2l_set_high_v1l(src,high) v2l_merge2_v1l(v1l_get_low_v2l(src), high)
#define v4d_set_high_v2d(src,high) v4d_merge2_v2d(v2d_get_low_v4d(src), high)
#define v4f_set_high_v2f(src,high) v4f_merge2_v2f(v2f_get_low_v4f(src), high)
#define v4i_set_high_v2i(src,high) v4i_merge2_v2i(v2i_get_low_v4i(src), high)
#define v4l_set_high_v2l(src,high) v4l_merge2_v2l(v2l_get_low_v4l(src), high)
#define v8d_set_high_v4d(src,high) v8d_merge2_v4d(v4d_get_low_v8d(src), high)
#define v8f_set_high_v4f(src,high) v8f_merge2_v4f(v4f_get_low_v8f(src), high)
#define v8i_set_high_v4i(src,high) v8i_merge2_v4i(v4i_get_low_v8i(src), high)
#define v8l_set_high_v4l(src,high) v8l_merge2_v4l(v4l_get_low_v8l(src), high)
#define v16f_set_high_v8f(src,high) v16f_merge2_v8f(v8f_get_low_v16f(src), high)
#define v16i_set_high_v8i(src,high) v16i_merge2_v8i(v8i_get_low_v16i(src), high)
#define v2d_set_hilo_v1d(src,a,high)  ((high) ? v2d_set_high_v1d(src, a) : v2d_set_low_v1d(src, a))
#define v2f_set_hilo_v1f(src,a,high)  ((high) ? v2f_set_high_v1f(src, a) : v2f_set_low_v1f(src, a))
#define v2i_set_hilo_v1i(src,a,high)  ((high) ? v2i_set_high_v1i(src, a) : v2i_set_low_v1i(src, a))
#define v2l_set_hilo_v1l(src,a,high)  ((high) ? v2l_set_high_v1l(src, a) : v2l_set_low_v1l(src, a))
#define v4d_set_hilo_v2d(src,a,high)  ((high) ? v4d_set_high_v2d(src, a) : v4d_set_low_v2d(src, a))
#define v4f_set_hilo_v2f(src,a,high)  ((high) ? v4f_set_high_v2f(src, a) : v4f_set_low_v2f(src, a))
#define v4i_set_hilo_v2i(src,a,high)  ((high) ? v4i_set_high_v2i(src, a) : v4i_set_low_v2i(src, a))
#define v4l_set_hilo_v2l(src,a,high)  ((high) ? v4l_set_high_v2l(src, a) : v4l_set_low_v2l(src, a))
#define v8d_set_hilo_v4d(src,a,high)  ((high) ? v8d_set_high_v4d(src, a) : v8d_set_low_v4d(src, a))
#define v8f_set_hilo_v4f(src,a,high)  ((high) ? v8f_set_high_v4f(src, a) : v8f_set_low_v4f(src, a))
#define v8i_set_hilo_v4i(src,a,high)  ((high) ? v8i_set_high_v4i(src, a) : v8i_set_low_v4i(src, a))
#define v8l_set_hilo_v4l(src,a,high)  ((high) ? v8l_set_high_v4l(src, a) : v8l_set_low_v4l(src, a))
#define v16f_set_hilo_v8f(src,a,high)  ((high) ? v16f_set_high_v8f(src, a) : v16f_set_low_v8f(src, a))
#define v16i_set_hilo_v8i(src,a,high)  ((high) ? v16i_set_high_v8i(src, a) : v16i_set_low_v8i(src, a))

/* BLENDS */

#define v1d_blend1(a,b,mask)  (((mask)&1) ? (b) : (a))
#define v1f_blend1(a,b,mask)  (((mask)&1) ? (b) : (a))
#define v1i_blend1(a,b,mask)  (((mask)&1) ? (b) : (a))
#define v1l_blend1(a,b,mask)  (((mask)&1) ? (b) : (a))
#define v2d_blend1(a,b,mask)  (((mask)&1) ? (b) : (a))
#define v2f_blend1(a,b,mask)  (((mask)&1) ? (b) : (a))
#define v2i_blend1(a,b,mask)  (((mask)&1) ? (b) : (a))
#define v2l_blend1(a,b,mask)  (((mask)&1) ? (b) : (a))
#define v4d_blend1(a,b,mask)  (((mask)&1) ? (b) : (a))
#define v4f_blend1(a,b,mask)  (((mask)&1) ? (b) : (a))
#define v4i_blend1(a,b,mask)  (((mask)&1) ? (b) : (a))
#define v4l_blend1(a,b,mask)  (((mask)&1) ? (b) : (a))
#define v8d_blend1(a,b,mask)  (((mask)&1) ? (b) : (a))
#define v8f_blend1(a,b,mask)  (((mask)&1) ? (b) : (a))
#define v8i_blend1(a,b,mask)  (((mask)&1) ? (b) : (a))
#define v8l_blend1(a,b,mask)  (((mask)&1) ? (b) : (a))
#define v16f_blend1(a,b,mask)  (((mask)&1) ? (b) : (a))
#define v16i_blend1(a,b,mask)  (((mask)&1) ? (b) : (a))
#define v2d_blend2(a,b,mask)  v2d_merge2_v1d(v1d_blend1(v1d_get_low_v2d(a), v1d_get_low_v2d(b), (mask) & 1), v1d_blend1(v1d_get_high_v2d(a), v1d_get_high_v2d(b), ((mask) >> 1) & 1))
#define v2f_blend2(a,b,mask)  v2f_merge2_v1f(v1f_blend1(v1f_get_low_v2f(a), v1f_get_low_v2f(b), (mask) & 1), v1f_blend1(v1f_get_high_v2f(a), v1f_get_high_v2f(b), ((mask) >> 1) & 1))
#define v2i_blend2(a,b,mask)  v2i_merge2_v1i(v1i_blend1(v1i_get_low_v2i(a), v1i_get_low_v2i(b), (mask) & 1), v1i_blend1(v1i_get_high_v2i(a), v1i_get_high_v2i(b), ((mask) >> 1) & 1))
#define v2l_blend2(a,b,mask)  v2l_merge2_v1l(v1l_blend1(v1l_get_low_v2l(a), v1l_get_low_v2l(b), (mask) & 1), v1l_blend1(v1l_get_high_v2l(a), v1l_get_high_v2l(b), ((mask) >> 1) & 1))
#define v4d_blend2(a,b,mask)  v4d_merge2_v2d(v2d_blend1(v2d_get_low_v4d(a), v2d_get_low_v4d(b), (mask) & 1), v2d_blend1(v2d_get_high_v4d(a), v2d_get_high_v4d(b), ((mask) >> 1) & 1))
#define v4f_blend2(a,b,mask)  v4f_merge2_v2f(v2f_blend1(v2f_get_low_v4f(a), v2f_get_low_v4f(b), (mask) & 1), v2f_blend1(v2f_get_high_v4f(a), v2f_get_high_v4f(b), ((mask) >> 1) & 1))
#define v4i_blend2(a,b,mask)  v4i_merge2_v2i(v2i_blend1(v2i_get_low_v4i(a), v2i_get_low_v4i(b), (mask) & 1), v2i_blend1(v2i_get_high_v4i(a), v2i_get_high_v4i(b), ((mask) >> 1) & 1))
#define v4l_blend2(a,b,mask)  v4l_merge2_v2l(v2l_blend1(v2l_get_low_v4l(a), v2l_get_low_v4l(b), (mask) & 1), v2l_blend1(v2l_get_high_v4l(a), v2l_get_high_v4l(b), ((mask) >> 1) & 1))
#define v8d_blend2(a,b,mask)  v8d_merge2_v4d(v4d_blend1(v4d_get_low_v8d(a), v4d_get_low_v8d(b), (mask) & 1), v4d_blend1(v4d_get_high_v8d(a), v4d_get_high_v8d(b), ((mask) >> 1) & 1))
#define v8f_blend2(a,b,mask)  v8f_merge2_v4f(v4f_blend1(v4f_get_low_v8f(a), v4f_get_low_v8f(b), (mask) & 1), v4f_blend1(v4f_get_high_v8f(a), v4f_get_high_v8f(b), ((mask) >> 1) & 1))
#define v8i_blend2(a,b,mask)  v8i_merge2_v4i(v4i_blend1(v4i_get_low_v8i(a), v4i_get_low_v8i(b), (mask) & 1), v4i_blend1(v4i_get_high_v8i(a), v4i_get_high_v8i(b), ((mask) >> 1) & 1))
#define v8l_blend2(a,b,mask)  v8l_merge2_v4l(v4l_blend1(v4l_get_low_v8l(a), v4l_get_low_v8l(b), (mask) & 1), v4l_blend1(v4l_get_high_v8l(a), v4l_get_high_v8l(b), ((mask) >> 1) & 1))
#define v16f_blend2(a,b,mask)  v16f_merge2_v8f(v8f_blend1(v8f_get_low_v16f(a), v8f_get_low_v16f(b), (mask) & 1), v8f_blend1(v8f_get_high_v16f(a), v8f_get_high_v16f(b), ((mask) >> 1) & 1))
#define v16i_blend2(a,b,mask)  v16i_merge2_v8i(v8i_blend1(v8i_get_low_v16i(a), v8i_get_low_v16i(b), (mask) & 1), v8i_blend1(v8i_get_high_v16i(a), v8i_get_high_v16i(b), ((mask) >> 1) & 1))
#define v4d_blend4(a,b,mask)  v4d_merge2_v2d(v2d_blend2(v2d_get_low_v4d(a), v2d_get_low_v4d(b), (mask) & 3), v2d_blend2(v2d_get_high_v4d(a), v2d_get_high_v4d(b), ((mask) >> 2) & 3))
#define v4f_blend4(a,b,mask)  v4f_merge2_v2f(v2f_blend2(v2f_get_low_v4f(a), v2f_get_low_v4f(b), (mask) & 3), v2f_blend2(v2f_get_high_v4f(a), v2f_get_high_v4f(b), ((mask) >> 2) & 3))
#define v4i_blend4(a,b,mask)  v4i_merge2_v2i(v2i_blend2(v2i_get_low_v4i(a), v2i_get_low_v4i(b), (mask) & 3), v2i_blend2(v2i_get_high_v4i(a), v2i_get_high_v4i(b), ((mask) >> 2) & 3))
#define v4l_blend4(a,b,mask)  v4l_merge2_v2l(v2l_blend2(v2l_get_low_v4l(a), v2l_get_low_v4l(b), (mask) & 3), v2l_blend2(v2l_get_high_v4l(a), v2l_get_high_v4l(b), ((mask) >> 2) & 3))
#define v8d_blend4(a,b,mask)  v8d_merge2_v4d(v4d_blend2(v4d_get_low_v8d(a), v4d_get_low_v8d(b), (mask) & 3), v4d_blend2(v4d_get_high_v8d(a), v4d_get_high_v8d(b), ((mask) >> 2) & 3))
#define v8f_blend4(a,b,mask)  v8f_merge2_v4f(v4f_blend2(v4f_get_low_v8f(a), v4f_get_low_v8f(b), (mask) & 3), v4f_blend2(v4f_get_high_v8f(a), v4f_get_high_v8f(b), ((mask) >> 2) & 3))
#define v8i_blend4(a,b,mask)  v8i_merge2_v4i(v4i_blend2(v4i_get_low_v8i(a), v4i_get_low_v8i(b), (mask) & 3), v4i_blend2(v4i_get_high_v8i(a), v4i_get_high_v8i(b), ((mask) >> 2) & 3))
#define v8l_blend4(a,b,mask)  v8l_merge2_v4l(v4l_blend2(v4l_get_low_v8l(a), v4l_get_low_v8l(b), (mask) & 3), v4l_blend2(v4l_get_high_v8l(a), v4l_get_high_v8l(b), ((mask) >> 2) & 3))
#define v16f_blend4(a,b,mask)  v16f_merge2_v8f(v8f_blend2(v8f_get_low_v16f(a), v8f_get_low_v16f(b), (mask) & 3), v8f_blend2(v8f_get_high_v16f(a), v8f_get_high_v16f(b), ((mask) >> 2) & 3))
#define v16i_blend4(a,b,mask)  v16i_merge2_v8i(v8i_blend2(v8i_get_low_v16i(a), v8i_get_low_v16i(b), (mask) & 3), v8i_blend2(v8i_get_high_v16i(a), v8i_get_high_v16i(b), ((mask) >> 2) & 3))
#define v8d_blend8(a,b,mask)  v8d_merge2_v4d(v4d_blend4(v4d_get_low_v8d(a), v4d_get_low_v8d(b), (mask) & 15), v4d_blend4(v4d_get_high_v8d(a), v4d_get_high_v8d(b), ((mask) >> 4) & 15))
#define v8f_blend8(a,b,mask)  v8f_merge2_v4f(v4f_blend4(v4f_get_low_v8f(a), v4f_get_low_v8f(b), (mask) & 15), v4f_blend4(v4f_get_high_v8f(a), v4f_get_high_v8f(b), ((mask) >> 4) & 15))
#define v8i_blend8(a,b,mask)  v8i_merge2_v4i(v4i_blend4(v4i_get_low_v8i(a), v4i_get_low_v8i(b), (mask) & 15), v4i_blend4(v4i_get_high_v8i(a), v4i_get_high_v8i(b), ((mask) >> 4) & 15))
#define v8l_blend8(a,b,mask)  v8l_merge2_v4l(v4l_blend4(v4l_get_low_v8l(a), v4l_get_low_v8l(b), (mask) & 15), v4l_blend4(v4l_get_high_v8l(a), v4l_get_high_v8l(b), ((mask) >> 4) & 15))
#define v16f_blend8(a,b,mask)  v16f_merge2_v8f(v8f_blend4(v8f_get_low_v16f(a), v8f_get_low_v16f(b), (mask) & 15), v8f_blend4(v8f_get_high_v16f(a), v8f_get_high_v16f(b), ((mask) >> 4) & 15))
#define v16i_blend8(a,b,mask)  v16i_merge2_v8i(v8i_blend4(v8i_get_low_v16i(a), v8i_get_low_v16i(b), (mask) & 15), v8i_blend4(v8i_get_high_v16i(a), v8i_get_high_v16i(b), ((mask) >> 4) & 15))
#define v16f_blend16(a,b,mask)  v16f_merge2_v8f(v8f_blend8(v8f_get_low_v16f(a), v8f_get_low_v16f(b), (mask) & 255), v8f_blend8(v8f_get_high_v16f(a), v8f_get_high_v16f(b), ((mask) >> 8) & 255))
#define v16i_blend16(a,b,mask)  v16i_merge2_v8i(v8i_blend8(v8i_get_low_v16i(a), v8i_get_low_v16i(b), (mask) & 255), v8i_blend8(v8i_get_high_v16i(a), v8i_get_high_v16i(b), ((mask) >> 8) & 255))

#define v1d_blend1x1 v1d_blend1
#define v1f_blend1x1 v1f_blend1
#define v1i_blend1x1 v1i_blend1
#define v1l_blend1x1 v1l_blend1
#define v2d_blend1x2 v2d_blend2
#define v2f_blend1x2 v2f_blend2
#define v2i_blend1x2 v2i_blend2
#define v2l_blend1x2 v2l_blend2
#define v4d_blend1x4 v4d_blend4
#define v4f_blend1x4 v4f_blend4
#define v4i_blend1x4 v4i_blend4
#define v4l_blend1x4 v4l_blend4
#define v8d_blend1x8 v8d_blend8
#define v8f_blend1x8 v8f_blend8
#define v8i_blend1x8 v8i_blend8
#define v8l_blend1x8 v8l_blend8
#define v16f_blend1x16 v16f_blend16
#define v16i_blend1x16 v16i_blend16
#define v2d_blend2x1 v2d_blend2
#define v2f_blend2x1 v2f_blend2
#define v2i_blend2x1 v2i_blend2
#define v2l_blend2x1 v2l_blend2
#define v4d_blend2x2(a,b,mask)  v4d_blend4x1((a), (b), (mask) | ((mask) << 2))
#define v4f_blend2x2(a,b,mask)  v4f_blend4x1((a), (b), (mask) | ((mask) << 2))
#define v4i_blend2x2(a,b,mask)  v4i_blend4x1((a), (b), (mask) | ((mask) << 2))
#define v4l_blend2x2(a,b,mask)  v4l_blend4x1((a), (b), (mask) | ((mask) << 2))
#define v8d_blend2x4(a,b,mask)  v8d_blend4x2((a), (b), (mask) | ((mask) << 2))
#define v8f_blend2x4(a,b,mask)  v8f_blend4x2((a), (b), (mask) | ((mask) << 2))
#define v8i_blend2x4(a,b,mask)  v8i_blend4x2((a), (b), (mask) | ((mask) << 2))
#define v8l_blend2x4(a,b,mask)  v8l_blend4x2((a), (b), (mask) | ((mask) << 2))
#define v16f_blend2x8(a,b,mask)  v16f_blend4x4((a), (b), (mask) | ((mask) << 2))
#define v16i_blend2x8(a,b,mask)  v16i_blend4x4((a), (b), (mask) | ((mask) << 2))
#define v4d_blend4x1 v4d_blend4
#define v4f_blend4x1 v4f_blend4
#define v4i_blend4x1 v4i_blend4
#define v4l_blend4x1 v4l_blend4
#define v8d_blend4x2(a,b,mask)  v8d_blend8x1((a), (b), (mask) | ((mask) << 4))
#define v8f_blend4x2(a,b,mask)  v8f_blend8x1((a), (b), (mask) | ((mask) << 4))
#define v8i_blend4x2(a,b,mask)  v8i_blend8x1((a), (b), (mask) | ((mask) << 4))
#define v8l_blend4x2(a,b,mask)  v8l_blend8x1((a), (b), (mask) | ((mask) << 4))
#define v16f_blend4x4(a,b,mask)  v16f_blend8x2((a), (b), (mask) | ((mask) << 4))
#define v16i_blend4x4(a,b,mask)  v16i_blend8x2((a), (b), (mask) | ((mask) << 4))
#define v8d_blend8x1 v8d_blend8
#define v8f_blend8x1 v8f_blend8
#define v8i_blend8x1 v8i_blend8
#define v8l_blend8x1 v8l_blend8
#define v16f_blend8x2(a,b,mask)  v16f_blend16x1((a), (b), (mask) | ((mask) << 8))
#define v16i_blend8x2(a,b,mask)  v16i_blend16x1((a), (b), (mask) | ((mask) << 8))
#define v16f_blend16x1 v16f_blend16
#define v16i_blend16x1 v16i_blend16

#define v1d_blend v1d_blend1
#define v1f_blend v1f_blend1
#define v1i_blend v1i_blend1
#define v1l_blend v1l_blend1
#define v2d_blend v2d_blend2
#define v2f_blend v2f_blend2
#define v2i_blend v2i_blend2
#define v2l_blend v2l_blend2
#define v4d_blend v4d_blend4
#define v4f_blend v4f_blend4
#define v4i_blend v4i_blend4
#define v4l_blend v4l_blend4
#define v8d_blend v8d_blend8
#define v8f_blend v8f_blend8
#define v8i_blend v8i_blend8
#define v8l_blend v8l_blend8
#define v16f_blend v16f_blend16
#define v16i_blend v16i_blend16

/* SHUFFLES */

#define v2d_hshuffle2(a,b,rule)  v2d_merge_v1d(v1d_get_hilo_v2d((a), (rule) & 1), v1d_get_hilo_v2d((b), ((rule) >> 1) & 1))
#define v2f_hshuffle2(a,b,rule)  v2f_merge_v1f(v1f_get_hilo_v2f((a), (rule) & 1), v1f_get_hilo_v2f((b), ((rule) >> 1) & 1))
#define v2i_hshuffle2(a,b,rule)  v2i_merge_v1i(v1i_get_hilo_v2i((a), (rule) & 1), v1i_get_hilo_v2i((b), ((rule) >> 1) & 1))
#define v2l_hshuffle2(a,b,rule)  v2l_merge_v1l(v1l_get_hilo_v2l((a), (rule) & 1), v1l_get_hilo_v2l((b), ((rule) >> 1) & 1))
#define v4d_hshuffle2(a,b,rule)  v4d_merge_v2d(v2d_get_hilo_v4d((a), (rule) & 1), v2d_get_hilo_v4d((b), ((rule) >> 1) & 1))
#define v4f_hshuffle2(a,b,rule)  v4f_merge_v2f(v2f_get_hilo_v4f((a), (rule) & 1), v2f_get_hilo_v4f((b), ((rule) >> 1) & 1))
#define v4i_hshuffle2(a,b,rule)  v4i_merge_v2i(v2i_get_hilo_v4i((a), (rule) & 1), v2i_get_hilo_v4i((b), ((rule) >> 1) & 1))
#define v4l_hshuffle2(a,b,rule)  v4l_merge_v2l(v2l_get_hilo_v4l((a), (rule) & 1), v2l_get_hilo_v4l((b), ((rule) >> 1) & 1))
#define v8d_hshuffle2(a,b,rule)  v8d_merge_v4d(v4d_get_hilo_v8d((a), (rule) & 1), v4d_get_hilo_v8d((b), ((rule) >> 1) & 1))
#define v8f_hshuffle2(a,b,rule)  v8f_merge_v4f(v4f_get_hilo_v8f((a), (rule) & 1), v4f_get_hilo_v8f((b), ((rule) >> 1) & 1))
#define v8i_hshuffle2(a,b,rule)  v8i_merge_v4i(v4i_get_hilo_v8i((a), (rule) & 1), v4i_get_hilo_v8i((b), ((rule) >> 1) & 1))
#define v8l_hshuffle2(a,b,rule)  v8l_merge_v4l(v4l_get_hilo_v8l((a), (rule) & 1), v4l_get_hilo_v8l((b), ((rule) >> 1) & 1))
#define v16f_hshuffle2(a,b,rule)  v16f_merge_v8f(v8f_get_hilo_v16f((a), (rule) & 1), v8f_get_hilo_v16f((b), ((rule) >> 1) & 1))
#define v16i_hshuffle2(a,b,rule)  v16i_merge_v8i(v8i_get_hilo_v16i((a), (rule) & 1), v8i_get_hilo_v16i((b), ((rule) >> 1) & 1))
#define v4d_hshuffle4(a,b,rule) v4d_merge2_v2d( \
    v2d_fshuffle2( \
      v2d_get_low_v4d(a), v2d_get_high_v4d(a), \
      ((rule) & 1)|((((rule) >> 2) & 1) << 1), \
      (((rule) >> 1) & 1)|((((rule) >> 3) & 1) << 1) \
    ), \
    v2d_fshuffle2( \
      v2d_get_low_v4d(b), v2d_get_high_v4d(b), \
      (((rule) >> 4) & 1)|((((rule) >> 6) & 1) << 1), \
      (((rule) >> 5) & 1)|((((rule) >> 7) & 1) << 1) \
    ) \
  )
#define v4f_hshuffle4(a,b,rule) v4f_merge2_v2f( \
    v2f_fshuffle2( \
      v2f_get_low_v4f(a), v2f_get_high_v4f(a), \
      ((rule) & 1)|((((rule) >> 2) & 1) << 1), \
      (((rule) >> 1) & 1)|((((rule) >> 3) & 1) << 1) \
    ), \
    v2f_fshuffle2( \
      v2f_get_low_v4f(b), v2f_get_high_v4f(b), \
      (((rule) >> 4) & 1)|((((rule) >> 6) & 1) << 1), \
      (((rule) >> 5) & 1)|((((rule) >> 7) & 1) << 1) \
    ) \
  )
#define v4i_hshuffle4(a,b,rule) v4i_merge2_v2i( \
    v2i_fshuffle2( \
      v2i_get_low_v4i(a), v2i_get_high_v4i(a), \
      ((rule) & 1)|((((rule) >> 2) & 1) << 1), \
      (((rule) >> 1) & 1)|((((rule) >> 3) & 1) << 1) \
    ), \
    v2i_fshuffle2( \
      v2i_get_low_v4i(b), v2i_get_high_v4i(b), \
      (((rule) >> 4) & 1)|((((rule) >> 6) & 1) << 1), \
      (((rule) >> 5) & 1)|((((rule) >> 7) & 1) << 1) \
    ) \
  )
#define v4l_hshuffle4(a,b,rule) v4l_merge2_v2l( \
    v2l_fshuffle2( \
      v2l_get_low_v4l(a), v2l_get_high_v4l(a), \
      ((rule) & 1)|((((rule) >> 2) & 1) << 1), \
      (((rule) >> 1) & 1)|((((rule) >> 3) & 1) << 1) \
    ), \
    v2l_fshuffle2( \
      v2l_get_low_v4l(b), v2l_get_high_v4l(b), \
      (((rule) >> 4) & 1)|((((rule) >> 6) & 1) << 1), \
      (((rule) >> 5) & 1)|((((rule) >> 7) & 1) << 1) \
    ) \
  )
#define v8d_hshuffle4(a,b,rule) v8d_merge2_v4d( \
    v4d_fshuffle2( \
      v4d_get_low_v8d(a), v4d_get_high_v8d(a), \
      ((rule) & 1)|((((rule) >> 2) & 1) << 1), \
      (((rule) >> 1) & 1)|((((rule) >> 3) & 1) << 1) \
    ), \
    v4d_fshuffle2( \
      v4d_get_low_v8d(b), v4d_get_high_v8d(b), \
      (((rule) >> 4) & 1)|((((rule) >> 6) & 1) << 1), \
      (((rule) >> 5) & 1)|((((rule) >> 7) & 1) << 1) \
    ) \
  )
#define v8f_hshuffle4(a,b,rule) v8f_merge2_v4f( \
    v4f_fshuffle2( \
      v4f_get_low_v8f(a), v4f_get_high_v8f(a), \
      ((rule) & 1)|((((rule) >> 2) & 1) << 1), \
      (((rule) >> 1) & 1)|((((rule) >> 3) & 1) << 1) \
    ), \
    v4f_fshuffle2( \
      v4f_get_low_v8f(b), v4f_get_high_v8f(b), \
      (((rule) >> 4) & 1)|((((rule) >> 6) & 1) << 1), \
      (((rule) >> 5) & 1)|((((rule) >> 7) & 1) << 1) \
    ) \
  )
#define v8i_hshuffle4(a,b,rule) v8i_merge2_v4i( \
    v4i_fshuffle2( \
      v4i_get_low_v8i(a), v4i_get_high_v8i(a), \
      ((rule) & 1)|((((rule) >> 2) & 1) << 1), \
      (((rule) >> 1) & 1)|((((rule) >> 3) & 1) << 1) \
    ), \
    v4i_fshuffle2( \
      v4i_get_low_v8i(b), v4i_get_high_v8i(b), \
      (((rule) >> 4) & 1)|((((rule) >> 6) & 1) << 1), \
      (((rule) >> 5) & 1)|((((rule) >> 7) & 1) << 1) \
    ) \
  )
#define v8l_hshuffle4(a,b,rule) v8l_merge2_v4l( \
    v4l_fshuffle2( \
      v4l_get_low_v8l(a), v4l_get_high_v8l(a), \
      ((rule) & 1)|((((rule) >> 2) & 1) << 1), \
      (((rule) >> 1) & 1)|((((rule) >> 3) & 1) << 1) \
    ), \
    v4l_fshuffle2( \
      v4l_get_low_v8l(b), v4l_get_high_v8l(b), \
      (((rule) >> 4) & 1)|((((rule) >> 6) & 1) << 1), \
      (((rule) >> 5) & 1)|((((rule) >> 7) & 1) << 1) \
    ) \
  )
#define v16f_hshuffle4(a,b,rule) v16f_merge2_v8f( \
    v8f_fshuffle2( \
      v8f_get_low_v16f(a), v8f_get_high_v16f(a), \
      ((rule) & 1)|((((rule) >> 2) & 1) << 1), \
      (((rule) >> 1) & 1)|((((rule) >> 3) & 1) << 1) \
    ), \
    v8f_fshuffle2( \
      v8f_get_low_v16f(b), v8f_get_high_v16f(b), \
      (((rule) >> 4) & 1)|((((rule) >> 6) & 1) << 1), \
      (((rule) >> 5) & 1)|((((rule) >> 7) & 1) << 1) \
    ) \
  )
#define v16i_hshuffle4(a,b,rule) v16i_merge2_v8i( \
    v8i_fshuffle2( \
      v8i_get_low_v16i(a), v8i_get_high_v16i(a), \
      ((rule) & 1)|((((rule) >> 2) & 1) << 1), \
      (((rule) >> 1) & 1)|((((rule) >> 3) & 1) << 1) \
    ), \
    v8i_fshuffle2( \
      v8i_get_low_v16i(b), v8i_get_high_v16i(b), \
      (((rule) >> 4) & 1)|((((rule) >> 6) & 1) << 1), \
      (((rule) >> 5) & 1)|((((rule) >> 7) & 1) << 1) \
    ) \
  )
#define v8d_hshuffle8(a,b,rule) v8d_merge2_v4d( \
    v4d_fshuffle4( \
      v4d_get_low_v8d(a), v4d_get_high_v8d(a), \
      ((rule) & 3)|((((rule) >> 3) & 3) << 2)|((((rule) >> 6) & 3) << 4)|((((rule) >> 9) & 3) << 6), \
      (((rule) >> 2) & 3)|((((rule) >> 5) & 3) << 1)|((((rule) >> 8) & 3) << 2)|((((rule) >> 11) & 3) << 3) \
    ), \
    v4d_fshuffle4( \
      v4d_get_low_v8d(b), v4d_get_high_v8d(b), \
      (((rule) >> 12) & 3)|((((rule) >> 15) & 3) << 2)|((((rule) >> 18) & 3) << 4)|((((rule) >> 21) & 3) << 6), \
      (((rule) >> 14) & 3)|((((rule) >> 17) & 3) << 1)|((((rule) >> 20) & 3) << 2)|((((rule) >> 23) & 3) << 3) \
    ) \
  )
#define v8f_hshuffle8(a,b,rule) v8f_merge2_v4f( \
    v4f_fshuffle4( \
      v4f_get_low_v8f(a), v4f_get_high_v8f(a), \
      ((rule) & 3)|((((rule) >> 3) & 3) << 2)|((((rule) >> 6) & 3) << 4)|((((rule) >> 9) & 3) << 6), \
      (((rule) >> 2) & 3)|((((rule) >> 5) & 3) << 1)|((((rule) >> 8) & 3) << 2)|((((rule) >> 11) & 3) << 3) \
    ), \
    v4f_fshuffle4( \
      v4f_get_low_v8f(b), v4f_get_high_v8f(b), \
      (((rule) >> 12) & 3)|((((rule) >> 15) & 3) << 2)|((((rule) >> 18) & 3) << 4)|((((rule) >> 21) & 3) << 6), \
      (((rule) >> 14) & 3)|((((rule) >> 17) & 3) << 1)|((((rule) >> 20) & 3) << 2)|((((rule) >> 23) & 3) << 3) \
    ) \
  )
#define v8i_hshuffle8(a,b,rule) v8i_merge2_v4i( \
    v4i_fshuffle4( \
      v4i_get_low_v8i(a), v4i_get_high_v8i(a), \
      ((rule) & 3)|((((rule) >> 3) & 3) << 2)|((((rule) >> 6) & 3) << 4)|((((rule) >> 9) & 3) << 6), \
      (((rule) >> 2) & 3)|((((rule) >> 5) & 3) << 1)|((((rule) >> 8) & 3) << 2)|((((rule) >> 11) & 3) << 3) \
    ), \
    v4i_fshuffle4( \
      v4i_get_low_v8i(b), v4i_get_high_v8i(b), \
      (((rule) >> 12) & 3)|((((rule) >> 15) & 3) << 2)|((((rule) >> 18) & 3) << 4)|((((rule) >> 21) & 3) << 6), \
      (((rule) >> 14) & 3)|((((rule) >> 17) & 3) << 1)|((((rule) >> 20) & 3) << 2)|((((rule) >> 23) & 3) << 3) \
    ) \
  )
#define v8l_hshuffle8(a,b,rule) v8l_merge2_v4l( \
    v4l_fshuffle4( \
      v4l_get_low_v8l(a), v4l_get_high_v8l(a), \
      ((rule) & 3)|((((rule) >> 3) & 3) << 2)|((((rule) >> 6) & 3) << 4)|((((rule) >> 9) & 3) << 6), \
      (((rule) >> 2) & 3)|((((rule) >> 5) & 3) << 1)|((((rule) >> 8) & 3) << 2)|((((rule) >> 11) & 3) << 3) \
    ), \
    v4l_fshuffle4( \
      v4l_get_low_v8l(b), v4l_get_high_v8l(b), \
      (((rule) >> 12) & 3)|((((rule) >> 15) & 3) << 2)|((((rule) >> 18) & 3) << 4)|((((rule) >> 21) & 3) << 6), \
      (((rule) >> 14) & 3)|((((rule) >> 17) & 3) << 1)|((((rule) >> 20) & 3) << 2)|((((rule) >> 23) & 3) << 3) \
    ) \
  )
#define v16f_hshuffle8(a,b,rule) v16f_merge2_v8f( \
    v8f_fshuffle4( \
      v8f_get_low_v16f(a), v8f_get_high_v16f(a), \
      ((rule) & 3)|((((rule) >> 3) & 3) << 2)|((((rule) >> 6) & 3) << 4)|((((rule) >> 9) & 3) << 6), \
      (((rule) >> 2) & 3)|((((rule) >> 5) & 3) << 1)|((((rule) >> 8) & 3) << 2)|((((rule) >> 11) & 3) << 3) \
    ), \
    v8f_fshuffle4( \
      v8f_get_low_v16f(b), v8f_get_high_v16f(b), \
      (((rule) >> 12) & 3)|((((rule) >> 15) & 3) << 2)|((((rule) >> 18) & 3) << 4)|((((rule) >> 21) & 3) << 6), \
      (((rule) >> 14) & 3)|((((rule) >> 17) & 3) << 1)|((((rule) >> 20) & 3) << 2)|((((rule) >> 23) & 3) << 3) \
    ) \
  )
#define v16i_hshuffle8(a,b,rule) v16i_merge2_v8i( \
    v8i_fshuffle4( \
      v8i_get_low_v16i(a), v8i_get_high_v16i(a), \
      ((rule) & 3)|((((rule) >> 3) & 3) << 2)|((((rule) >> 6) & 3) << 4)|((((rule) >> 9) & 3) << 6), \
      (((rule) >> 2) & 3)|((((rule) >> 5) & 3) << 1)|((((rule) >> 8) & 3) << 2)|((((rule) >> 11) & 3) << 3) \
    ), \
    v8i_fshuffle4( \
      v8i_get_low_v16i(b), v8i_get_high_v16i(b), \
      (((rule) >> 12) & 3)|((((rule) >> 15) & 3) << 2)|((((rule) >> 18) & 3) << 4)|((((rule) >> 21) & 3) << 6), \
      (((rule) >> 14) & 3)|((((rule) >> 17) & 3) << 1)|((((rule) >> 20) & 3) << 2)|((((rule) >> 23) & 3) << 3) \
    ) \
  )
#define v16f_hshuffle16(a,b,rule) v16f_merge2_v8f( \
    v8f_fshuffle8( \
      v8f_get_low_v16f(a), v8f_get_high_v16f(a), \
      ((rule) & 7)|((((rule) >> 4) & 7) << 3)|((((rule) >> 8) & 7) << 6)|((((rule) >> 12) & 7) << 9)|((((rule) >> 16) & 7) << 12)|((((rule) >> 20) & 7) << 15)|((((rule) >> 24) & 7) << 18)|((((rule) >> 28) & 7) << 21), \
      (((rule) >> 3) & 7)|((((rule) >> 7) & 7) << 1)|((((rule) >> 11) & 7) << 2)|((((rule) >> 15) & 7) << 3)|((((rule) >> 19) & 7) << 4)|((((rule) >> 23) & 7) << 5)|((((rule) >> 27) & 7) << 6)|((((rule) >> 31) & 7) << 7) \
    ), \
    v8f_fshuffle8( \
      v8f_get_low_v16f(b), v8f_get_high_v16f(b), \
      (((rule) >> 32) & 7)|((((rule) >> 36) & 7) << 3)|((((rule) >> 40) & 7) << 6)|((((rule) >> 44) & 7) << 9)|((((rule) >> 48) & 7) << 12)|((((rule) >> 52) & 7) << 15)|((((rule) >> 56) & 7) << 18)|((((rule) >> 60) & 7) << 21), \
      (((rule) >> 35) & 7)|((((rule) >> 39) & 7) << 1)|((((rule) >> 43) & 7) << 2)|((((rule) >> 47) & 7) << 3)|((((rule) >> 51) & 7) << 4)|((((rule) >> 55) & 7) << 5)|((((rule) >> 59) & 7) << 6)|((((rule) >> 63) & 7) << 7) \
    ) \
  )
#define v16i_hshuffle16(a,b,rule) v16i_merge2_v8i( \
    v8i_fshuffle8( \
      v8i_get_low_v16i(a), v8i_get_high_v16i(a), \
      ((rule) & 7)|((((rule) >> 4) & 7) << 3)|((((rule) >> 8) & 7) << 6)|((((rule) >> 12) & 7) << 9)|((((rule) >> 16) & 7) << 12)|((((rule) >> 20) & 7) << 15)|((((rule) >> 24) & 7) << 18)|((((rule) >> 28) & 7) << 21), \
      (((rule) >> 3) & 7)|((((rule) >> 7) & 7) << 1)|((((rule) >> 11) & 7) << 2)|((((rule) >> 15) & 7) << 3)|((((rule) >> 19) & 7) << 4)|((((rule) >> 23) & 7) << 5)|((((rule) >> 27) & 7) << 6)|((((rule) >> 31) & 7) << 7) \
    ), \
    v8i_fshuffle8( \
      v8i_get_low_v16i(b), v8i_get_high_v16i(b), \
      (((rule) >> 32) & 7)|((((rule) >> 36) & 7) << 3)|((((rule) >> 40) & 7) << 6)|((((rule) >> 44) & 7) << 9)|((((rule) >> 48) & 7) << 12)|((((rule) >> 52) & 7) << 15)|((((rule) >> 56) & 7) << 18)|((((rule) >> 60) & 7) << 21), \
      (((rule) >> 35) & 7)|((((rule) >> 39) & 7) << 1)|((((rule) >> 43) & 7) << 2)|((((rule) >> 47) & 7) << 3)|((((rule) >> 51) & 7) << 4)|((((rule) >> 55) & 7) << 5)|((((rule) >> 59) & 7) << 6)|((((rule) >> 63) & 7) << 7) \
    ) \
  )

#define v2d_hshuffle2x1 v2d_hshuffle2
#define v2f_hshuffle2x1 v2f_hshuffle2
#define v2i_hshuffle2x1 v2i_hshuffle2
#define v2l_hshuffle2x1 v2l_hshuffle2
#define v4d_hshuffle2x2(a,b,rule)  v4d_merge2_v2d(v2d_hshuffle2x1(v2d_get_low_v4d(a), v2d_get_low_v4d(b), (rule)), v2d_hshuffle2x1(v2d_get_high_v4d(a), v2d_get_high_v4d(b), (rule)))
#define v4f_hshuffle2x2(a,b,rule)  v4f_merge2_v2f(v2f_hshuffle2x1(v2f_get_low_v4f(a), v2f_get_low_v4f(b), (rule)), v2f_hshuffle2x1(v2f_get_high_v4f(a), v2f_get_high_v4f(b), (rule)))
#define v4i_hshuffle2x2(a,b,rule)  v4i_merge2_v2i(v2i_hshuffle2x1(v2i_get_low_v4i(a), v2i_get_low_v4i(b), (rule)), v2i_hshuffle2x1(v2i_get_high_v4i(a), v2i_get_high_v4i(b), (rule)))
#define v4l_hshuffle2x2(a,b,rule)  v4l_merge2_v2l(v2l_hshuffle2x1(v2l_get_low_v4l(a), v2l_get_low_v4l(b), (rule)), v2l_hshuffle2x1(v2l_get_high_v4l(a), v2l_get_high_v4l(b), (rule)))
#define v8d_hshuffle2x4(a,b,rule)  v8d_merge2_v4d(v4d_hshuffle2x2(v4d_get_low_v8d(a), v4d_get_low_v8d(b), (rule)), v4d_hshuffle2x2(v4d_get_high_v8d(a), v4d_get_high_v8d(b), (rule)))
#define v8f_hshuffle2x4(a,b,rule)  v8f_merge2_v4f(v4f_hshuffle2x2(v4f_get_low_v8f(a), v4f_get_low_v8f(b), (rule)), v4f_hshuffle2x2(v4f_get_high_v8f(a), v4f_get_high_v8f(b), (rule)))
#define v8i_hshuffle2x4(a,b,rule)  v8i_merge2_v4i(v4i_hshuffle2x2(v4i_get_low_v8i(a), v4i_get_low_v8i(b), (rule)), v4i_hshuffle2x2(v4i_get_high_v8i(a), v4i_get_high_v8i(b), (rule)))
#define v8l_hshuffle2x4(a,b,rule)  v8l_merge2_v4l(v4l_hshuffle2x2(v4l_get_low_v8l(a), v4l_get_low_v8l(b), (rule)), v4l_hshuffle2x2(v4l_get_high_v8l(a), v4l_get_high_v8l(b), (rule)))
#define v16f_hshuffle2x8(a,b,rule)  v16f_merge2_v8f(v8f_hshuffle2x4(v8f_get_low_v16f(a), v8f_get_low_v16f(b), (rule)), v8f_hshuffle2x4(v8f_get_high_v16f(a), v8f_get_high_v16f(b), (rule)))
#define v16i_hshuffle2x8(a,b,rule)  v16i_merge2_v8i(v8i_hshuffle2x4(v8i_get_low_v16i(a), v8i_get_low_v16i(b), (rule)), v8i_hshuffle2x4(v8i_get_high_v16i(a), v8i_get_high_v16i(b), (rule)))
#define v4d_hshuffle4x1 v4d_hshuffle4
#define v4f_hshuffle4x1 v4f_hshuffle4
#define v4i_hshuffle4x1 v4i_hshuffle4
#define v4l_hshuffle4x1 v4l_hshuffle4
#define v8d_hshuffle4x2(a,b,rule)  v8d_merge2_v4d(v4d_hshuffle4x1(v4d_get_low_v8d(a), v4d_get_low_v8d(b), (rule)), v4d_hshuffle4x1(v4d_get_high_v8d(a), v4d_get_high_v8d(b), (rule)))
#define v8f_hshuffle4x2(a,b,rule)  v8f_merge2_v4f(v4f_hshuffle4x1(v4f_get_low_v8f(a), v4f_get_low_v8f(b), (rule)), v4f_hshuffle4x1(v4f_get_high_v8f(a), v4f_get_high_v8f(b), (rule)))
#define v8i_hshuffle4x2(a,b,rule)  v8i_merge2_v4i(v4i_hshuffle4x1(v4i_get_low_v8i(a), v4i_get_low_v8i(b), (rule)), v4i_hshuffle4x1(v4i_get_high_v8i(a), v4i_get_high_v8i(b), (rule)))
#define v8l_hshuffle4x2(a,b,rule)  v8l_merge2_v4l(v4l_hshuffle4x1(v4l_get_low_v8l(a), v4l_get_low_v8l(b), (rule)), v4l_hshuffle4x1(v4l_get_high_v8l(a), v4l_get_high_v8l(b), (rule)))
#define v16f_hshuffle4x4(a,b,rule)  v16f_merge2_v8f(v8f_hshuffle4x2(v8f_get_low_v16f(a), v8f_get_low_v16f(b), (rule)), v8f_hshuffle4x2(v8f_get_high_v16f(a), v8f_get_high_v16f(b), (rule)))
#define v16i_hshuffle4x4(a,b,rule)  v16i_merge2_v8i(v8i_hshuffle4x2(v8i_get_low_v16i(a), v8i_get_low_v16i(b), (rule)), v8i_hshuffle4x2(v8i_get_high_v16i(a), v8i_get_high_v16i(b), (rule)))
#define v8d_hshuffle8x1 v8d_hshuffle8
#define v8f_hshuffle8x1 v8f_hshuffle8
#define v8i_hshuffle8x1 v8i_hshuffle8
#define v8l_hshuffle8x1 v8l_hshuffle8
#define v16f_hshuffle8x2(a,b,rule)  v16f_merge2_v8f(v8f_hshuffle8x1(v8f_get_low_v16f(a), v8f_get_low_v16f(b), (rule)), v8f_hshuffle8x1(v8f_get_high_v16f(a), v8f_get_high_v16f(b), (rule)))
#define v16i_hshuffle8x2(a,b,rule)  v16i_merge2_v8i(v8i_hshuffle8x1(v8i_get_low_v16i(a), v8i_get_low_v16i(b), (rule)), v8i_hshuffle8x1(v8i_get_high_v16i(a), v8i_get_high_v16i(b), (rule)))
#define v16f_hshuffle16x1 v16f_hshuffle16
#define v16i_hshuffle16x1 v16i_hshuffle16

#define v2d_permute2(a,rule)  v2d_hshuffle2((a), (a), (rule))
#define v2f_permute2(a,rule)  v2f_hshuffle2((a), (a), (rule))
#define v2i_permute2(a,rule)  v2i_hshuffle2((a), (a), (rule))
#define v2l_permute2(a,rule)  v2l_hshuffle2((a), (a), (rule))
#define v4d_permute2(a,rule)  v4d_hshuffle2((a), (a), (rule))
#define v4f_permute2(a,rule)  v4f_hshuffle2((a), (a), (rule))
#define v4i_permute2(a,rule)  v4i_hshuffle2((a), (a), (rule))
#define v4l_permute2(a,rule)  v4l_hshuffle2((a), (a), (rule))
#define v8d_permute2(a,rule)  v8d_hshuffle2((a), (a), (rule))
#define v8f_permute2(a,rule)  v8f_hshuffle2((a), (a), (rule))
#define v8i_permute2(a,rule)  v8i_hshuffle2((a), (a), (rule))
#define v8l_permute2(a,rule)  v8l_hshuffle2((a), (a), (rule))
#define v16f_permute2(a,rule)  v16f_hshuffle2((a), (a), (rule))
#define v16i_permute2(a,rule)  v16i_hshuffle2((a), (a), (rule))
#define v4d_permute4(a,rule)  v4d_hshuffle4((a), (a), (rule))
#define v4f_permute4(a,rule)  v4f_hshuffle4((a), (a), (rule))
#define v4i_permute4(a,rule)  v4i_hshuffle4((a), (a), (rule))
#define v4l_permute4(a,rule)  v4l_hshuffle4((a), (a), (rule))
#define v8d_permute4(a,rule)  v8d_hshuffle4((a), (a), (rule))
#define v8f_permute4(a,rule)  v8f_hshuffle4((a), (a), (rule))
#define v8i_permute4(a,rule)  v8i_hshuffle4((a), (a), (rule))
#define v8l_permute4(a,rule)  v8l_hshuffle4((a), (a), (rule))
#define v16f_permute4(a,rule)  v16f_hshuffle4((a), (a), (rule))
#define v16i_permute4(a,rule)  v16i_hshuffle4((a), (a), (rule))
#define v8d_permute8(a,rule)  v8d_hshuffle8((a), (a), (rule))
#define v8f_permute8(a,rule)  v8f_hshuffle8((a), (a), (rule))
#define v8i_permute8(a,rule)  v8i_hshuffle8((a), (a), (rule))
#define v8l_permute8(a,rule)  v8l_hshuffle8((a), (a), (rule))
#define v16f_permute8(a,rule)  v16f_hshuffle8((a), (a), (rule))
#define v16i_permute8(a,rule)  v16i_hshuffle8((a), (a), (rule))
#define v16f_permute16(a,rule)  v16f_hshuffle16((a), (a), (rule))
#define v16i_permute16(a,rule)  v16i_hshuffle16((a), (a), (rule))

#define v2d_permute2x1 v2d_permute2
#define v2f_permute2x1 v2f_permute2
#define v2i_permute2x1 v2i_permute2
#define v2l_permute2x1 v2l_permute2
#define v4d_permute2x2(a,rule)  v4d_hshuffle2x2((a), (a), (rule))
#define v4f_permute2x2(a,rule)  v4f_hshuffle2x2((a), (a), (rule))
#define v4i_permute2x2(a,rule)  v4i_hshuffle2x2((a), (a), (rule))
#define v4l_permute2x2(a,rule)  v4l_hshuffle2x2((a), (a), (rule))
#define v8d_permute2x4(a,rule)  v8d_hshuffle2x4((a), (a), (rule))
#define v8f_permute2x4(a,rule)  v8f_hshuffle2x4((a), (a), (rule))
#define v8i_permute2x4(a,rule)  v8i_hshuffle2x4((a), (a), (rule))
#define v8l_permute2x4(a,rule)  v8l_hshuffle2x4((a), (a), (rule))
#define v16f_permute2x8(a,rule)  v16f_hshuffle2x8((a), (a), (rule))
#define v16i_permute2x8(a,rule)  v16i_hshuffle2x8((a), (a), (rule))
#define v4d_permute4x1 v4d_permute4
#define v4f_permute4x1 v4f_permute4
#define v4i_permute4x1 v4i_permute4
#define v4l_permute4x1 v4l_permute4
#define v8d_permute4x2(a,rule)  v8d_hshuffle4x2((a), (a), (rule))
#define v8f_permute4x2(a,rule)  v8f_hshuffle4x2((a), (a), (rule))
#define v8i_permute4x2(a,rule)  v8i_hshuffle4x2((a), (a), (rule))
#define v8l_permute4x2(a,rule)  v8l_hshuffle4x2((a), (a), (rule))
#define v16f_permute4x4(a,rule)  v16f_hshuffle4x4((a), (a), (rule))
#define v16i_permute4x4(a,rule)  v16i_hshuffle4x4((a), (a), (rule))
#define v8d_permute8x1 v8d_permute8
#define v8f_permute8x1 v8f_permute8
#define v8i_permute8x1 v8i_permute8
#define v8l_permute8x1 v8l_permute8
#define v16f_permute8x2(a,rule)  v16f_hshuffle8x2((a), (a), (rule))
#define v16i_permute8x2(a,rule)  v16i_hshuffle8x2((a), (a), (rule))
#define v16f_permute16x1 v16f_permute16
#define v16i_permute16x1 v16i_permute16

#define v2d_fshuffle2(a,b,rule,mask)  v2d_blend(v2d_permute2((a), (rule)), v2d_permute2((b), (rule)), (mask))
#define v2f_fshuffle2(a,b,rule,mask)  v2f_blend(v2f_permute2((a), (rule)), v2f_permute2((b), (rule)), (mask))
#define v2i_fshuffle2(a,b,rule,mask)  v2i_blend(v2i_permute2((a), (rule)), v2i_permute2((b), (rule)), (mask))
#define v2l_fshuffle2(a,b,rule,mask)  v2l_blend(v2l_permute2((a), (rule)), v2l_permute2((b), (rule)), (mask))
#define v4d_fshuffle2(a,b,rule,mask)  v4d_blend(v4d_permute2((a), (rule)), v4d_permute2((b), (rule)), (mask))
#define v4f_fshuffle2(a,b,rule,mask)  v4f_blend(v4f_permute2((a), (rule)), v4f_permute2((b), (rule)), (mask))
#define v4i_fshuffle2(a,b,rule,mask)  v4i_blend(v4i_permute2((a), (rule)), v4i_permute2((b), (rule)), (mask))
#define v4l_fshuffle2(a,b,rule,mask)  v4l_blend(v4l_permute2((a), (rule)), v4l_permute2((b), (rule)), (mask))
#define v8d_fshuffle2(a,b,rule,mask)  v8d_blend(v8d_permute2((a), (rule)), v8d_permute2((b), (rule)), (mask))
#define v8f_fshuffle2(a,b,rule,mask)  v8f_blend(v8f_permute2((a), (rule)), v8f_permute2((b), (rule)), (mask))
#define v8i_fshuffle2(a,b,rule,mask)  v8i_blend(v8i_permute2((a), (rule)), v8i_permute2((b), (rule)), (mask))
#define v8l_fshuffle2(a,b,rule,mask)  v8l_blend(v8l_permute2((a), (rule)), v8l_permute2((b), (rule)), (mask))
#define v16f_fshuffle2(a,b,rule,mask)  v16f_blend(v16f_permute2((a), (rule)), v16f_permute2((b), (rule)), (mask))
#define v16i_fshuffle2(a,b,rule,mask)  v16i_blend(v16i_permute2((a), (rule)), v16i_permute2((b), (rule)), (mask))
#define v4d_fshuffle4(a,b,rule,mask)  v4d_blend(v4d_permute4((a), (rule)), v4d_permute4((b), (rule)), (mask))
#define v4f_fshuffle4(a,b,rule,mask)  v4f_blend(v4f_permute4((a), (rule)), v4f_permute4((b), (rule)), (mask))
#define v4i_fshuffle4(a,b,rule,mask)  v4i_blend(v4i_permute4((a), (rule)), v4i_permute4((b), (rule)), (mask))
#define v4l_fshuffle4(a,b,rule,mask)  v4l_blend(v4l_permute4((a), (rule)), v4l_permute4((b), (rule)), (mask))
#define v8d_fshuffle4(a,b,rule,mask)  v8d_blend(v8d_permute4((a), (rule)), v8d_permute4((b), (rule)), (mask))
#define v8f_fshuffle4(a,b,rule,mask)  v8f_blend(v8f_permute4((a), (rule)), v8f_permute4((b), (rule)), (mask))
#define v8i_fshuffle4(a,b,rule,mask)  v8i_blend(v8i_permute4((a), (rule)), v8i_permute4((b), (rule)), (mask))
#define v8l_fshuffle4(a,b,rule,mask)  v8l_blend(v8l_permute4((a), (rule)), v8l_permute4((b), (rule)), (mask))
#define v16f_fshuffle4(a,b,rule,mask)  v16f_blend(v16f_permute4((a), (rule)), v16f_permute4((b), (rule)), (mask))
#define v16i_fshuffle4(a,b,rule,mask)  v16i_blend(v16i_permute4((a), (rule)), v16i_permute4((b), (rule)), (mask))
#define v8d_fshuffle8(a,b,rule,mask)  v8d_blend(v8d_permute8((a), (rule)), v8d_permute8((b), (rule)), (mask))
#define v8f_fshuffle8(a,b,rule,mask)  v8f_blend(v8f_permute8((a), (rule)), v8f_permute8((b), (rule)), (mask))
#define v8i_fshuffle8(a,b,rule,mask)  v8i_blend(v8i_permute8((a), (rule)), v8i_permute8((b), (rule)), (mask))
#define v8l_fshuffle8(a,b,rule,mask)  v8l_blend(v8l_permute8((a), (rule)), v8l_permute8((b), (rule)), (mask))
#define v16f_fshuffle8(a,b,rule,mask)  v16f_blend(v16f_permute8((a), (rule)), v16f_permute8((b), (rule)), (mask))
#define v16i_fshuffle8(a,b,rule,mask)  v16i_blend(v16i_permute8((a), (rule)), v16i_permute8((b), (rule)), (mask))
#define v16f_fshuffle16(a,b,rule,mask)  v16f_blend(v16f_permute16((a), (rule)), v16f_permute16((b), (rule)), (mask))
#define v16i_fshuffle16(a,b,rule,mask)  v16i_blend(v16i_permute16((a), (rule)), v16i_permute16((b), (rule)), (mask))

#define v2d_fshuffle2x1 v2d_fshuffle2
#define v2f_fshuffle2x1 v2f_fshuffle2
#define v2i_fshuffle2x1 v2i_fshuffle2
#define v2l_fshuffle2x1 v2l_fshuffle2
#define v4d_fshuffle2x2(a,b,rule,mask)  v4d_blend(v4d_permute2x2((a), (rule)), v4d_permute2x2((b), (rule)), (mask))
#define v4f_fshuffle2x2(a,b,rule,mask)  v4f_blend(v4f_permute2x2((a), (rule)), v4f_permute2x2((b), (rule)), (mask))
#define v4i_fshuffle2x2(a,b,rule,mask)  v4i_blend(v4i_permute2x2((a), (rule)), v4i_permute2x2((b), (rule)), (mask))
#define v4l_fshuffle2x2(a,b,rule,mask)  v4l_blend(v4l_permute2x2((a), (rule)), v4l_permute2x2((b), (rule)), (mask))
#define v8d_fshuffle2x4(a,b,rule,mask)  v8d_blend(v8d_permute2x4((a), (rule)), v8d_permute2x4((b), (rule)), (mask))
#define v8f_fshuffle2x4(a,b,rule,mask)  v8f_blend(v8f_permute2x4((a), (rule)), v8f_permute2x4((b), (rule)), (mask))
#define v8i_fshuffle2x4(a,b,rule,mask)  v8i_blend(v8i_permute2x4((a), (rule)), v8i_permute2x4((b), (rule)), (mask))
#define v8l_fshuffle2x4(a,b,rule,mask)  v8l_blend(v8l_permute2x4((a), (rule)), v8l_permute2x4((b), (rule)), (mask))
#define v16f_fshuffle2x8(a,b,rule,mask)  v16f_blend(v16f_permute2x8((a), (rule)), v16f_permute2x8((b), (rule)), (mask))
#define v16i_fshuffle2x8(a,b,rule,mask)  v16i_blend(v16i_permute2x8((a), (rule)), v16i_permute2x8((b), (rule)), (mask))
#define v4d_fshuffle4x1 v4d_fshuffle4
#define v4f_fshuffle4x1 v4f_fshuffle4
#define v4i_fshuffle4x1 v4i_fshuffle4
#define v4l_fshuffle4x1 v4l_fshuffle4
#define v8d_fshuffle4x2(a,b,rule,mask)  v8d_blend(v8d_permute4x2((a), (rule)), v8d_permute4x2((b), (rule)), (mask))
#define v8f_fshuffle4x2(a,b,rule,mask)  v8f_blend(v8f_permute4x2((a), (rule)), v8f_permute4x2((b), (rule)), (mask))
#define v8i_fshuffle4x2(a,b,rule,mask)  v8i_blend(v8i_permute4x2((a), (rule)), v8i_permute4x2((b), (rule)), (mask))
#define v8l_fshuffle4x2(a,b,rule,mask)  v8l_blend(v8l_permute4x2((a), (rule)), v8l_permute4x2((b), (rule)), (mask))
#define v16f_fshuffle4x4(a,b,rule,mask)  v16f_blend(v16f_permute4x4((a), (rule)), v16f_permute4x4((b), (rule)), (mask))
#define v16i_fshuffle4x4(a,b,rule,mask)  v16i_blend(v16i_permute4x4((a), (rule)), v16i_permute4x4((b), (rule)), (mask))
#define v8d_fshuffle8x1 v8d_fshuffle8
#define v8f_fshuffle8x1 v8f_fshuffle8
#define v8i_fshuffle8x1 v8i_fshuffle8
#define v8l_fshuffle8x1 v8l_fshuffle8
#define v16f_fshuffle8x2(a,b,rule,mask)  v16f_blend(v16f_permute8x2((a), (rule)), v16f_permute8x2((b), (rule)), (mask))
#define v16i_fshuffle8x2(a,b,rule,mask)  v16i_blend(v16i_permute8x2((a), (rule)), v16i_permute8x2((b), (rule)), (mask))
#define v16f_fshuffle16x1 v16f_fshuffle16
#define v16i_fshuffle16x1 v16i_fshuffle16

#define v1d_hshuffle v1d_hshuffle1
#define v1f_hshuffle v1f_hshuffle1
#define v1i_hshuffle v1i_hshuffle1
#define v1l_hshuffle v1l_hshuffle1
#define v2d_hshuffle v2d_hshuffle2
#define v2f_hshuffle v2f_hshuffle2
#define v2i_hshuffle v2i_hshuffle2
#define v2l_hshuffle v2l_hshuffle2
#define v4d_hshuffle v4d_hshuffle4
#define v4f_hshuffle v4f_hshuffle4
#define v4i_hshuffle v4i_hshuffle4
#define v4l_hshuffle v4l_hshuffle4
#define v8d_hshuffle v8d_hshuffle8
#define v8f_hshuffle v8f_hshuffle8
#define v8i_hshuffle v8i_hshuffle8
#define v8l_hshuffle v8l_hshuffle8
#define v16f_hshuffle v16f_hshuffle16
#define v16i_hshuffle v16i_hshuffle16

#define v1d_permute v1d_permute1
#define v1f_permute v1f_permute1
#define v1i_permute v1i_permute1
#define v1l_permute v1l_permute1
#define v2d_permute v2d_permute2
#define v2f_permute v2f_permute2
#define v2i_permute v2i_permute2
#define v2l_permute v2l_permute2
#define v4d_permute v4d_permute4
#define v4f_permute v4f_permute4
#define v4i_permute v4i_permute4
#define v4l_permute v4l_permute4
#define v8d_permute v8d_permute8
#define v8f_permute v8f_permute8
#define v8i_permute v8i_permute8
#define v8l_permute v8l_permute8
#define v16f_permute v16f_permute16
#define v16i_permute v16i_permute16

#define v1d_fshuffle v1d_fshuffle1
#define v1f_fshuffle v1f_fshuffle1
#define v1i_fshuffle v1i_fshuffle1
#define v1l_fshuffle v1l_fshuffle1
#define v2d_fshuffle v2d_fshuffle2
#define v2f_fshuffle v2f_fshuffle2
#define v2i_fshuffle v2i_fshuffle2
#define v2l_fshuffle v2l_fshuffle2
#define v4d_fshuffle v4d_fshuffle4
#define v4f_fshuffle v4f_fshuffle4
#define v4i_fshuffle v4i_fshuffle4
#define v4l_fshuffle v4l_fshuffle4
#define v8d_fshuffle v8d_fshuffle8
#define v8f_fshuffle v8f_fshuffle8
#define v8i_fshuffle v8i_fshuffle8
#define v8l_fshuffle v8l_fshuffle8
#define v16f_fshuffle v16f_fshuffle16
#define v16i_fshuffle v16i_fshuffle16

/* REDUCTIONS */

#define __PINTS_REDUCE1(func, vec_t, input, output) do { \
    output = input; \
  } while(0)
#define __PINTS_REDUCE2(func, vec_t, input, output) do { \
    vec_t __input, __p; \
    __input = (input); \
    __p = vec_t##_permute2(__input, PINTS_SHUFFLE(1, 0)); \
    output = vec_t##_##func (__input, __p); \
  } while(0)
#define __PINTS_REDUCE4(func, vec_t, input, output) do { \
    vec_t __input, __p, __r, __rp; \
    __input = (input); \
    __p = vec_t##_permute2(__input, PINTS_SHUFFLE(1, 0)); \
    __r = vec_t##_##func (__input, __p); \
    __rp = vec_t##_permute2x2(__r, PINTS_SHUFFLE(1, 0)); \
    output = vec_t##_##func (__r, __rp); \
  } while(0)
#define __PINTS_REDUCE8(func, vec_t, input, output) do { \
    vec_t __input, __p, __r1, __rp1, __r2, __rp2; \
    __input = (input); \
    __p = vec_t##_permute2(__input, PINTS_SHUFFLE(1, 0)); \
    __r1 = vec_t##_##func (__input, __p); \
    __rp1 = vec_t##_permute4x2(__r1, PINTS_SHUFFLE(2, 3, 0, 1)); \
    __r2 = vec_t##_##func (__r1, __rp1); \
    __rp2 = vec_t##_permute2x4(__r2, PINTS_SHUFFLE(1, 0)); \
    output = vec_t##_##func (__r2, __rp2); \
  } while(0)
#define __PINTS_REDUCE16(func, vec_t, input, output) do { \
    vec_t __input, __p, __r1, __rp1, __r2, __rp2, __r3, __rp3; \
    __input = (input); \
    __p = vec_t##_permute2(__input, PINTS_SHUFFLE(1, 0)); \
    __r1 = vec_t##_##func (__input, __p); \
    __rp1 = vec_t##_permute4(__r1, PINTS_SHUFFLE(1, 0, 3, 2)); \
    __r2 = vec_t##_##func (__r1, __rp1); \
    __rp2 = vec_t##_permute4x4(__r2, PINTS_SHUFFLE(2, 3, 0, 1)); \
    __r3 = vec_t##_##func (__r2, __rp2); \
    __rp3 = vec_t##_permute2x8(__r3, PINTS_SHUFFLE(1, 0)); \
    output = vec_t##_##func (__r3, __rp3); \
  } while(0)
#define __PINTS_1REDUCE1(func, suffix_t, input, output) __PINTS_REDUCE1(func, v1##suffix_t, input, output)
#define __PINTS_2REDUCE1(func, suffix_t, input, output) do { \
    v1##suffix_t __temp1; \
    __PINTS_1REDUCE1(func, suffix_t, input, __temp1); \
    output = v2##suffix_t##_merge2_##v1##suffix_t(__temp1, __temp1); \
  } while(0)
#define __PINTS_4REDUCE1(func, suffix_t, input, output) do { \
    v2##suffix_t __temp2; \
    __PINTS_2REDUCE1(func, suffix_t, input, __temp2); \
    output = v4##suffix_t##_merge2_##v2##suffix_t(__temp2, __temp2); \
  } while(0)
#define __PINTS_8REDUCE1(func, suffix_t, input, output) do { \
    v4##suffix_t __temp4; \
    __PINTS_4REDUCE1(func, suffix_t, input, __temp4); \
    output = v8##suffix_t##_merge2_##v4##suffix_t(__temp4, __temp4); \
  } while(0)
#define __PINTS_16REDUCE1(func, suffix_t, input, output) do { \
    v8##suffix_t __temp8; \
    __PINTS_8REDUCE1(func, suffix_t, input, __temp8); \
    output = v16##suffix_t##_merge2_##v8##suffix_t(__temp8, __temp8); \
  } while(0)
#define __PINTS_1REDUCE2(func, suffix_t, input, output) do { \
    v2##suffix_t __input2; \
    v1##suffix_t __low1, __high1, __temp1; \
    __input2 = (input); \
    __low1 = v1##suffix_t##_get_low_##v2##suffix_t(__input2); \
    __high1 = v1##suffix_t##_get_high_##v2##suffix_t(__input2); \
    __temp1 = v1##suffix_t##_##func(__low1, __high1); \
    __PINTS_1REDUCE1(func, suffix_t, __temp1, output); \
  } while(0)
#define __PINTS_2REDUCE2(func, suffix_t, input, output) __PINTS_REDUCE2(func, v2##suffix_t, input, output)
#define __PINTS_4REDUCE2(func, suffix_t, input, output) do { \
    v2##suffix_t __temp2; \
    __PINTS_2REDUCE2(func, suffix_t, input, __temp2); \
    output = v4##suffix_t##_merge2_##v2##suffix_t(__temp2, __temp2); \
  } while(0)
#define __PINTS_8REDUCE2(func, suffix_t, input, output) do { \
    v4##suffix_t __temp4; \
    __PINTS_4REDUCE2(func, suffix_t, input, __temp4); \
    output = v8##suffix_t##_merge2_##v4##suffix_t(__temp4, __temp4); \
  } while(0)
#define __PINTS_16REDUCE2(func, suffix_t, input, output) do { \
    v8##suffix_t __temp8; \
    __PINTS_8REDUCE2(func, suffix_t, input, __temp8); \
    output = v16##suffix_t##_merge2_##v8##suffix_t(__temp8, __temp8); \
  } while(0)
#define __PINTS_1REDUCE4(func, suffix_t, input, output) do { \
    v4##suffix_t __input4; \
    v2##suffix_t __low2, __high2, __temp2; \
    __input4 = (input); \
    __low2 = v2##suffix_t##_get_low_##v4##suffix_t(__input4); \
    __high2 = v2##suffix_t##_get_high_##v4##suffix_t(__input4); \
    __temp2 = v2##suffix_t##_##func(__low2, __high2); \
    __PINTS_1REDUCE2(func, suffix_t, __temp2, output); \
  } while(0)
#define __PINTS_2REDUCE4(func, suffix_t, input, output) do { \
    v4##suffix_t __input4; \
    v2##suffix_t __low2, __high2, __temp2; \
    __input4 = (input); \
    __low2 = v2##suffix_t##_get_low_##v4##suffix_t(__input4); \
    __high2 = v2##suffix_t##_get_high_##v4##suffix_t(__input4); \
    __temp2 = v2##suffix_t##_##func(__low2, __high2); \
    __PINTS_2REDUCE2(func, suffix_t, __temp2, output); \
  } while(0)
#define __PINTS_4REDUCE4(func, suffix_t, input, output) __PINTS_REDUCE4(func, v4##suffix_t, input, output)
#define __PINTS_8REDUCE4(func, suffix_t, input, output) do { \
    v4##suffix_t __temp4; \
    __PINTS_4REDUCE4(func, suffix_t, input, __temp4); \
    output = v8##suffix_t##_merge2_##v4##suffix_t(__temp4, __temp4); \
  } while(0)
#define __PINTS_16REDUCE4(func, suffix_t, input, output) do { \
    v8##suffix_t __temp8; \
    __PINTS_8REDUCE4(func, suffix_t, input, __temp8); \
    output = v16##suffix_t##_merge2_##v8##suffix_t(__temp8, __temp8); \
  } while(0)
#define __PINTS_1REDUCE8(func, suffix_t, input, output) do { \
    v8##suffix_t __input8; \
    v4##suffix_t __low4, __high4, __temp4; \
    __input8 = (input); \
    __low4 = v4##suffix_t##_get_low_##v8##suffix_t(__input8); \
    __high4 = v4##suffix_t##_get_high_##v8##suffix_t(__input8); \
    __temp4 = v4##suffix_t##_##func(__low4, __high4); \
    __PINTS_1REDUCE4(func, suffix_t, __temp4, output); \
  } while(0)
#define __PINTS_2REDUCE8(func, suffix_t, input, output) do { \
    v8##suffix_t __input8; \
    v4##suffix_t __low4, __high4, __temp4; \
    __input8 = (input); \
    __low4 = v4##suffix_t##_get_low_##v8##suffix_t(__input8); \
    __high4 = v4##suffix_t##_get_high_##v8##suffix_t(__input8); \
    __temp4 = v4##suffix_t##_##func(__low4, __high4); \
    __PINTS_2REDUCE4(func, suffix_t, __temp4, output); \
  } while(0)
#define __PINTS_4REDUCE8(func, suffix_t, input, output) do { \
    v8##suffix_t __input8; \
    v4##suffix_t __low4, __high4, __temp4; \
    __input8 = (input); \
    __low4 = v4##suffix_t##_get_low_##v8##suffix_t(__input8); \
    __high4 = v4##suffix_t##_get_high_##v8##suffix_t(__input8); \
    __temp4 = v4##suffix_t##_##func(__low4, __high4); \
    __PINTS_4REDUCE4(func, suffix_t, __temp4, output); \
  } while(0)
#define __PINTS_8REDUCE8(func, suffix_t, input, output) __PINTS_REDUCE8(func, v8##suffix_t, input, output)
#define __PINTS_16REDUCE8(func, suffix_t, input, output) do { \
    v8##suffix_t __temp8; \
    __PINTS_8REDUCE8(func, suffix_t, input, __temp8); \
    output = v16##suffix_t##_merge2_##v8##suffix_t(__temp8, __temp8); \
  } while(0)
#define __PINTS_1REDUCE16(func, suffix_t, input, output) do { \
    v16##suffix_t __input16; \
    v8##suffix_t __low8, __high8, __temp8; \
    __input16 = (input); \
    __low8 = v8##suffix_t##_get_low_##v16##suffix_t(__input16); \
    __high8 = v8##suffix_t##_get_high_##v16##suffix_t(__input16); \
    __temp8 = v8##suffix_t##_##func(__low8, __high8); \
    __PINTS_1REDUCE8(func, suffix_t, __temp8, output); \
  } while(0)
#define __PINTS_2REDUCE16(func, suffix_t, input, output) do { \
    v16##suffix_t __input16; \
    v8##suffix_t __low8, __high8, __temp8; \
    __input16 = (input); \
    __low8 = v8##suffix_t##_get_low_##v16##suffix_t(__input16); \
    __high8 = v8##suffix_t##_get_high_##v16##suffix_t(__input16); \
    __temp8 = v8##suffix_t##_##func(__low8, __high8); \
    __PINTS_2REDUCE8(func, suffix_t, __temp8, output); \
  } while(0)
#define __PINTS_4REDUCE16(func, suffix_t, input, output) do { \
    v16##suffix_t __input16; \
    v8##suffix_t __low8, __high8, __temp8; \
    __input16 = (input); \
    __low8 = v8##suffix_t##_get_low_##v16##suffix_t(__input16); \
    __high8 = v8##suffix_t##_get_high_##v16##suffix_t(__input16); \
    __temp8 = v8##suffix_t##_##func(__low8, __high8); \
    __PINTS_4REDUCE8(func, suffix_t, __temp8, output); \
  } while(0)
#define __PINTS_8REDUCE16(func, suffix_t, input, output) do { \
    v16##suffix_t __input16; \
    v8##suffix_t __low8, __high8, __temp8; \
    __input16 = (input); \
    __low8 = v8##suffix_t##_get_low_##v16##suffix_t(__input16); \
    __high8 = v8##suffix_t##_get_high_##v16##suffix_t(__input16); \
    __temp8 = v8##suffix_t##_##func(__low8, __high8); \
    __PINTS_8REDUCE8(func, suffix_t, __temp8, output); \
  } while(0)
#define __PINTS_16REDUCE16(func, suffix_t, input, output) __PINTS_REDUCE16(func, v16##suffix_t, input, output)
#define v1d_reduce_add __v1d_reduce_add
#define v1f_reduce_add __v1f_reduce_add
#define v1i_reduce_add __v1i_reduce_add
#define v1l_reduce_add __v1l_reduce_add
#define v2d_reduce_add __v2d_reduce_add
#define v2f_reduce_add __v2f_reduce_add
#define v2i_reduce_add __v2i_reduce_add
#define v2l_reduce_add __v2l_reduce_add
#define v4d_reduce_add __v4d_reduce_add
#define v4f_reduce_add __v4f_reduce_add
#define v4i_reduce_add __v4i_reduce_add
#define v4l_reduce_add __v4l_reduce_add
#define v8d_reduce_add __v8d_reduce_add
#define v8f_reduce_add __v8f_reduce_add
#define v8i_reduce_add __v8i_reduce_add
#define v8l_reduce_add __v8l_reduce_add
#define v16f_reduce_add __v16f_reduce_add
#define v16i_reduce_add __v16i_reduce_add
#define v1d_reduce_add_v1d __v1d_reduce_add_v1d
#define v1f_reduce_add_v1f __v1f_reduce_add_v1f
#define v1i_reduce_add_v1i __v1i_reduce_add_v1i
#define v1l_reduce_add_v1l __v1l_reduce_add_v1l
#define v2d_reduce_add_v1d __v2d_reduce_add_v1d
#define v2f_reduce_add_v1f __v2f_reduce_add_v1f
#define v2i_reduce_add_v1i __v2i_reduce_add_v1i
#define v2l_reduce_add_v1l __v2l_reduce_add_v1l
#define v4d_reduce_add_v1d __v4d_reduce_add_v1d
#define v4f_reduce_add_v1f __v4f_reduce_add_v1f
#define v4i_reduce_add_v1i __v4i_reduce_add_v1i
#define v4l_reduce_add_v1l __v4l_reduce_add_v1l
#define v8d_reduce_add_v1d __v8d_reduce_add_v1d
#define v8f_reduce_add_v1f __v8f_reduce_add_v1f
#define v8i_reduce_add_v1i __v8i_reduce_add_v1i
#define v8l_reduce_add_v1l __v8l_reduce_add_v1l
#define v16f_reduce_add_v1f __v16f_reduce_add_v1f
#define v16i_reduce_add_v1i __v16i_reduce_add_v1i
#define v1d_reduce_add_v2d __v1d_reduce_add_v2d
#define v1f_reduce_add_v2f __v1f_reduce_add_v2f
#define v1i_reduce_add_v2i __v1i_reduce_add_v2i
#define v1l_reduce_add_v2l __v1l_reduce_add_v2l
#define v2d_reduce_add_v2d __v2d_reduce_add_v2d
#define v2f_reduce_add_v2f __v2f_reduce_add_v2f
#define v2i_reduce_add_v2i __v2i_reduce_add_v2i
#define v2l_reduce_add_v2l __v2l_reduce_add_v2l
#define v4d_reduce_add_v2d __v4d_reduce_add_v2d
#define v4f_reduce_add_v2f __v4f_reduce_add_v2f
#define v4i_reduce_add_v2i __v4i_reduce_add_v2i
#define v4l_reduce_add_v2l __v4l_reduce_add_v2l
#define v8d_reduce_add_v2d __v8d_reduce_add_v2d
#define v8f_reduce_add_v2f __v8f_reduce_add_v2f
#define v8i_reduce_add_v2i __v8i_reduce_add_v2i
#define v8l_reduce_add_v2l __v8l_reduce_add_v2l
#define v16f_reduce_add_v2f __v16f_reduce_add_v2f
#define v16i_reduce_add_v2i __v16i_reduce_add_v2i
#define v1d_reduce_add_v4d __v1d_reduce_add_v4d
#define v1f_reduce_add_v4f __v1f_reduce_add_v4f
#define v1i_reduce_add_v4i __v1i_reduce_add_v4i
#define v1l_reduce_add_v4l __v1l_reduce_add_v4l
#define v2d_reduce_add_v4d __v2d_reduce_add_v4d
#define v2f_reduce_add_v4f __v2f_reduce_add_v4f
#define v2i_reduce_add_v4i __v2i_reduce_add_v4i
#define v2l_reduce_add_v4l __v2l_reduce_add_v4l
#define v4d_reduce_add_v4d __v4d_reduce_add_v4d
#define v4f_reduce_add_v4f __v4f_reduce_add_v4f
#define v4i_reduce_add_v4i __v4i_reduce_add_v4i
#define v4l_reduce_add_v4l __v4l_reduce_add_v4l
#define v8d_reduce_add_v4d __v8d_reduce_add_v4d
#define v8f_reduce_add_v4f __v8f_reduce_add_v4f
#define v8i_reduce_add_v4i __v8i_reduce_add_v4i
#define v8l_reduce_add_v4l __v8l_reduce_add_v4l
#define v16f_reduce_add_v4f __v16f_reduce_add_v4f
#define v16i_reduce_add_v4i __v16i_reduce_add_v4i
#define v1d_reduce_add_v8d __v1d_reduce_add_v8d
#define v1f_reduce_add_v8f __v1f_reduce_add_v8f
#define v1i_reduce_add_v8i __v1i_reduce_add_v8i
#define v1l_reduce_add_v8l __v1l_reduce_add_v8l
#define v2d_reduce_add_v8d __v2d_reduce_add_v8d
#define v2f_reduce_add_v8f __v2f_reduce_add_v8f
#define v2i_reduce_add_v8i __v2i_reduce_add_v8i
#define v2l_reduce_add_v8l __v2l_reduce_add_v8l
#define v4d_reduce_add_v8d __v4d_reduce_add_v8d
#define v4f_reduce_add_v8f __v4f_reduce_add_v8f
#define v4i_reduce_add_v8i __v4i_reduce_add_v8i
#define v4l_reduce_add_v8l __v4l_reduce_add_v8l
#define v8d_reduce_add_v8d __v8d_reduce_add_v8d
#define v8f_reduce_add_v8f __v8f_reduce_add_v8f
#define v8i_reduce_add_v8i __v8i_reduce_add_v8i
#define v8l_reduce_add_v8l __v8l_reduce_add_v8l
#define v16f_reduce_add_v8f __v16f_reduce_add_v8f
#define v16i_reduce_add_v8i __v16i_reduce_add_v8i
#define v1f_reduce_add_v16f __v1f_reduce_add_v16f
#define v1i_reduce_add_v16i __v1i_reduce_add_v16i
#define v2f_reduce_add_v16f __v2f_reduce_add_v16f
#define v2i_reduce_add_v16i __v2i_reduce_add_v16i
#define v4f_reduce_add_v16f __v4f_reduce_add_v16f
#define v4i_reduce_add_v16i __v4i_reduce_add_v16i
#define v8f_reduce_add_v16f __v8f_reduce_add_v16f
#define v8i_reduce_add_v16i __v8i_reduce_add_v16i
#define v16f_reduce_add_v16f __v16f_reduce_add_v16f
#define v16i_reduce_add_v16i __v16i_reduce_add_v16i
#define sd_reduce_add_v1d(a)  sd_cvt_v1d(v1d_reduce_add_v1d(a))
#define sf_reduce_add_v1f(a)  sf_cvt_v1f(v1f_reduce_add_v1f(a))
#define si_reduce_add_v1i(a)  si_cvt_v1i(v1i_reduce_add_v1i(a))
#define sl_reduce_add_v1l(a)  sl_cvt_v1l(v1l_reduce_add_v1l(a))
#define sd_reduce_add_v2d(a)  sd_cvt_v1d(v1d_reduce_add_v2d(a))
#define sf_reduce_add_v2f(a)  sf_cvt_v1f(v1f_reduce_add_v2f(a))
#define si_reduce_add_v2i(a)  si_cvt_v1i(v1i_reduce_add_v2i(a))
#define sl_reduce_add_v2l(a)  sl_cvt_v1l(v1l_reduce_add_v2l(a))
#define sd_reduce_add_v4d(a)  sd_cvt_v1d(v1d_reduce_add_v4d(a))
#define sf_reduce_add_v4f(a)  sf_cvt_v1f(v1f_reduce_add_v4f(a))
#define si_reduce_add_v4i(a)  si_cvt_v1i(v1i_reduce_add_v4i(a))
#define sl_reduce_add_v4l(a)  sl_cvt_v1l(v1l_reduce_add_v4l(a))
#define sd_reduce_add_v8d(a)  sd_cvt_v1d(v1d_reduce_add_v8d(a))
#define sf_reduce_add_v8f(a)  sf_cvt_v1f(v1f_reduce_add_v8f(a))
#define si_reduce_add_v8i(a)  si_cvt_v1i(v1i_reduce_add_v8i(a))
#define sl_reduce_add_v8l(a)  sl_cvt_v1l(v1l_reduce_add_v8l(a))
#define sf_reduce_add_v16f(a)  sf_cvt_v1f(v1f_reduce_add_v16f(a))
#define si_reduce_add_v16i(a)  si_cvt_v1i(v1i_reduce_add_v16i(a))
#define v1d_reduce_mul __v1d_reduce_mul
#define v1f_reduce_mul __v1f_reduce_mul
#define v1i_reduce_mul __v1i_reduce_mul
#define v1l_reduce_mul __v1l_reduce_mul
#define v2d_reduce_mul __v2d_reduce_mul
#define v2f_reduce_mul __v2f_reduce_mul
#define v2i_reduce_mul __v2i_reduce_mul
#define v2l_reduce_mul __v2l_reduce_mul
#define v4d_reduce_mul __v4d_reduce_mul
#define v4f_reduce_mul __v4f_reduce_mul
#define v4i_reduce_mul __v4i_reduce_mul
#define v4l_reduce_mul __v4l_reduce_mul
#define v8d_reduce_mul __v8d_reduce_mul
#define v8f_reduce_mul __v8f_reduce_mul
#define v8i_reduce_mul __v8i_reduce_mul
#define v8l_reduce_mul __v8l_reduce_mul
#define v16f_reduce_mul __v16f_reduce_mul
#define v16i_reduce_mul __v16i_reduce_mul
#define v1d_reduce_mul_v1d __v1d_reduce_mul_v1d
#define v1f_reduce_mul_v1f __v1f_reduce_mul_v1f
#define v1i_reduce_mul_v1i __v1i_reduce_mul_v1i
#define v1l_reduce_mul_v1l __v1l_reduce_mul_v1l
#define v2d_reduce_mul_v1d __v2d_reduce_mul_v1d
#define v2f_reduce_mul_v1f __v2f_reduce_mul_v1f
#define v2i_reduce_mul_v1i __v2i_reduce_mul_v1i
#define v2l_reduce_mul_v1l __v2l_reduce_mul_v1l
#define v4d_reduce_mul_v1d __v4d_reduce_mul_v1d
#define v4f_reduce_mul_v1f __v4f_reduce_mul_v1f
#define v4i_reduce_mul_v1i __v4i_reduce_mul_v1i
#define v4l_reduce_mul_v1l __v4l_reduce_mul_v1l
#define v8d_reduce_mul_v1d __v8d_reduce_mul_v1d
#define v8f_reduce_mul_v1f __v8f_reduce_mul_v1f
#define v8i_reduce_mul_v1i __v8i_reduce_mul_v1i
#define v8l_reduce_mul_v1l __v8l_reduce_mul_v1l
#define v16f_reduce_mul_v1f __v16f_reduce_mul_v1f
#define v16i_reduce_mul_v1i __v16i_reduce_mul_v1i
#define v1d_reduce_mul_v2d __v1d_reduce_mul_v2d
#define v1f_reduce_mul_v2f __v1f_reduce_mul_v2f
#define v1i_reduce_mul_v2i __v1i_reduce_mul_v2i
#define v1l_reduce_mul_v2l __v1l_reduce_mul_v2l
#define v2d_reduce_mul_v2d __v2d_reduce_mul_v2d
#define v2f_reduce_mul_v2f __v2f_reduce_mul_v2f
#define v2i_reduce_mul_v2i __v2i_reduce_mul_v2i
#define v2l_reduce_mul_v2l __v2l_reduce_mul_v2l
#define v4d_reduce_mul_v2d __v4d_reduce_mul_v2d
#define v4f_reduce_mul_v2f __v4f_reduce_mul_v2f
#define v4i_reduce_mul_v2i __v4i_reduce_mul_v2i
#define v4l_reduce_mul_v2l __v4l_reduce_mul_v2l
#define v8d_reduce_mul_v2d __v8d_reduce_mul_v2d
#define v8f_reduce_mul_v2f __v8f_reduce_mul_v2f
#define v8i_reduce_mul_v2i __v8i_reduce_mul_v2i
#define v8l_reduce_mul_v2l __v8l_reduce_mul_v2l
#define v16f_reduce_mul_v2f __v16f_reduce_mul_v2f
#define v16i_reduce_mul_v2i __v16i_reduce_mul_v2i
#define v1d_reduce_mul_v4d __v1d_reduce_mul_v4d
#define v1f_reduce_mul_v4f __v1f_reduce_mul_v4f
#define v1i_reduce_mul_v4i __v1i_reduce_mul_v4i
#define v1l_reduce_mul_v4l __v1l_reduce_mul_v4l
#define v2d_reduce_mul_v4d __v2d_reduce_mul_v4d
#define v2f_reduce_mul_v4f __v2f_reduce_mul_v4f
#define v2i_reduce_mul_v4i __v2i_reduce_mul_v4i
#define v2l_reduce_mul_v4l __v2l_reduce_mul_v4l
#define v4d_reduce_mul_v4d __v4d_reduce_mul_v4d
#define v4f_reduce_mul_v4f __v4f_reduce_mul_v4f
#define v4i_reduce_mul_v4i __v4i_reduce_mul_v4i
#define v4l_reduce_mul_v4l __v4l_reduce_mul_v4l
#define v8d_reduce_mul_v4d __v8d_reduce_mul_v4d
#define v8f_reduce_mul_v4f __v8f_reduce_mul_v4f
#define v8i_reduce_mul_v4i __v8i_reduce_mul_v4i
#define v8l_reduce_mul_v4l __v8l_reduce_mul_v4l
#define v16f_reduce_mul_v4f __v16f_reduce_mul_v4f
#define v16i_reduce_mul_v4i __v16i_reduce_mul_v4i
#define v1d_reduce_mul_v8d __v1d_reduce_mul_v8d
#define v1f_reduce_mul_v8f __v1f_reduce_mul_v8f
#define v1i_reduce_mul_v8i __v1i_reduce_mul_v8i
#define v1l_reduce_mul_v8l __v1l_reduce_mul_v8l
#define v2d_reduce_mul_v8d __v2d_reduce_mul_v8d
#define v2f_reduce_mul_v8f __v2f_reduce_mul_v8f
#define v2i_reduce_mul_v8i __v2i_reduce_mul_v8i
#define v2l_reduce_mul_v8l __v2l_reduce_mul_v8l
#define v4d_reduce_mul_v8d __v4d_reduce_mul_v8d
#define v4f_reduce_mul_v8f __v4f_reduce_mul_v8f
#define v4i_reduce_mul_v8i __v4i_reduce_mul_v8i
#define v4l_reduce_mul_v8l __v4l_reduce_mul_v8l
#define v8d_reduce_mul_v8d __v8d_reduce_mul_v8d
#define v8f_reduce_mul_v8f __v8f_reduce_mul_v8f
#define v8i_reduce_mul_v8i __v8i_reduce_mul_v8i
#define v8l_reduce_mul_v8l __v8l_reduce_mul_v8l
#define v16f_reduce_mul_v8f __v16f_reduce_mul_v8f
#define v16i_reduce_mul_v8i __v16i_reduce_mul_v8i
#define v1f_reduce_mul_v16f __v1f_reduce_mul_v16f
#define v1i_reduce_mul_v16i __v1i_reduce_mul_v16i
#define v2f_reduce_mul_v16f __v2f_reduce_mul_v16f
#define v2i_reduce_mul_v16i __v2i_reduce_mul_v16i
#define v4f_reduce_mul_v16f __v4f_reduce_mul_v16f
#define v4i_reduce_mul_v16i __v4i_reduce_mul_v16i
#define v8f_reduce_mul_v16f __v8f_reduce_mul_v16f
#define v8i_reduce_mul_v16i __v8i_reduce_mul_v16i
#define v16f_reduce_mul_v16f __v16f_reduce_mul_v16f
#define v16i_reduce_mul_v16i __v16i_reduce_mul_v16i
#define sd_reduce_mul_v1d(a)  sd_cvt_v1d(v1d_reduce_mul_v1d(a))
#define sf_reduce_mul_v1f(a)  sf_cvt_v1f(v1f_reduce_mul_v1f(a))
#define si_reduce_mul_v1i(a)  si_cvt_v1i(v1i_reduce_mul_v1i(a))
#define sl_reduce_mul_v1l(a)  sl_cvt_v1l(v1l_reduce_mul_v1l(a))
#define sd_reduce_mul_v2d(a)  sd_cvt_v1d(v1d_reduce_mul_v2d(a))
#define sf_reduce_mul_v2f(a)  sf_cvt_v1f(v1f_reduce_mul_v2f(a))
#define si_reduce_mul_v2i(a)  si_cvt_v1i(v1i_reduce_mul_v2i(a))
#define sl_reduce_mul_v2l(a)  sl_cvt_v1l(v1l_reduce_mul_v2l(a))
#define sd_reduce_mul_v4d(a)  sd_cvt_v1d(v1d_reduce_mul_v4d(a))
#define sf_reduce_mul_v4f(a)  sf_cvt_v1f(v1f_reduce_mul_v4f(a))
#define si_reduce_mul_v4i(a)  si_cvt_v1i(v1i_reduce_mul_v4i(a))
#define sl_reduce_mul_v4l(a)  sl_cvt_v1l(v1l_reduce_mul_v4l(a))
#define sd_reduce_mul_v8d(a)  sd_cvt_v1d(v1d_reduce_mul_v8d(a))
#define sf_reduce_mul_v8f(a)  sf_cvt_v1f(v1f_reduce_mul_v8f(a))
#define si_reduce_mul_v8i(a)  si_cvt_v1i(v1i_reduce_mul_v8i(a))
#define sl_reduce_mul_v8l(a)  sl_cvt_v1l(v1l_reduce_mul_v8l(a))
#define sf_reduce_mul_v16f(a)  sf_cvt_v1f(v1f_reduce_mul_v16f(a))
#define si_reduce_mul_v16i(a)  si_cvt_v1i(v1i_reduce_mul_v16i(a))
#define v1d_reduce_and __v1d_reduce_and
#define v1f_reduce_and __v1f_reduce_and
#define v1i_reduce_and __v1i_reduce_and
#define v1l_reduce_and __v1l_reduce_and
#define v2d_reduce_and __v2d_reduce_and
#define v2f_reduce_and __v2f_reduce_and
#define v2i_reduce_and __v2i_reduce_and
#define v2l_reduce_and __v2l_reduce_and
#define v4d_reduce_and __v4d_reduce_and
#define v4f_reduce_and __v4f_reduce_and
#define v4i_reduce_and __v4i_reduce_and
#define v4l_reduce_and __v4l_reduce_and
#define v8d_reduce_and __v8d_reduce_and
#define v8f_reduce_and __v8f_reduce_and
#define v8i_reduce_and __v8i_reduce_and
#define v8l_reduce_and __v8l_reduce_and
#define v16f_reduce_and __v16f_reduce_and
#define v16i_reduce_and __v16i_reduce_and
#define v1d_reduce_and_v1d __v1d_reduce_and_v1d
#define v1f_reduce_and_v1f __v1f_reduce_and_v1f
#define v1i_reduce_and_v1i __v1i_reduce_and_v1i
#define v1l_reduce_and_v1l __v1l_reduce_and_v1l
#define v2d_reduce_and_v1d __v2d_reduce_and_v1d
#define v2f_reduce_and_v1f __v2f_reduce_and_v1f
#define v2i_reduce_and_v1i __v2i_reduce_and_v1i
#define v2l_reduce_and_v1l __v2l_reduce_and_v1l
#define v4d_reduce_and_v1d __v4d_reduce_and_v1d
#define v4f_reduce_and_v1f __v4f_reduce_and_v1f
#define v4i_reduce_and_v1i __v4i_reduce_and_v1i
#define v4l_reduce_and_v1l __v4l_reduce_and_v1l
#define v8d_reduce_and_v1d __v8d_reduce_and_v1d
#define v8f_reduce_and_v1f __v8f_reduce_and_v1f
#define v8i_reduce_and_v1i __v8i_reduce_and_v1i
#define v8l_reduce_and_v1l __v8l_reduce_and_v1l
#define v16f_reduce_and_v1f __v16f_reduce_and_v1f
#define v16i_reduce_and_v1i __v16i_reduce_and_v1i
#define v1d_reduce_and_v2d __v1d_reduce_and_v2d
#define v1f_reduce_and_v2f __v1f_reduce_and_v2f
#define v1i_reduce_and_v2i __v1i_reduce_and_v2i
#define v1l_reduce_and_v2l __v1l_reduce_and_v2l
#define v2d_reduce_and_v2d __v2d_reduce_and_v2d
#define v2f_reduce_and_v2f __v2f_reduce_and_v2f
#define v2i_reduce_and_v2i __v2i_reduce_and_v2i
#define v2l_reduce_and_v2l __v2l_reduce_and_v2l
#define v4d_reduce_and_v2d __v4d_reduce_and_v2d
#define v4f_reduce_and_v2f __v4f_reduce_and_v2f
#define v4i_reduce_and_v2i __v4i_reduce_and_v2i
#define v4l_reduce_and_v2l __v4l_reduce_and_v2l
#define v8d_reduce_and_v2d __v8d_reduce_and_v2d
#define v8f_reduce_and_v2f __v8f_reduce_and_v2f
#define v8i_reduce_and_v2i __v8i_reduce_and_v2i
#define v8l_reduce_and_v2l __v8l_reduce_and_v2l
#define v16f_reduce_and_v2f __v16f_reduce_and_v2f
#define v16i_reduce_and_v2i __v16i_reduce_and_v2i
#define v1d_reduce_and_v4d __v1d_reduce_and_v4d
#define v1f_reduce_and_v4f __v1f_reduce_and_v4f
#define v1i_reduce_and_v4i __v1i_reduce_and_v4i
#define v1l_reduce_and_v4l __v1l_reduce_and_v4l
#define v2d_reduce_and_v4d __v2d_reduce_and_v4d
#define v2f_reduce_and_v4f __v2f_reduce_and_v4f
#define v2i_reduce_and_v4i __v2i_reduce_and_v4i
#define v2l_reduce_and_v4l __v2l_reduce_and_v4l
#define v4d_reduce_and_v4d __v4d_reduce_and_v4d
#define v4f_reduce_and_v4f __v4f_reduce_and_v4f
#define v4i_reduce_and_v4i __v4i_reduce_and_v4i
#define v4l_reduce_and_v4l __v4l_reduce_and_v4l
#define v8d_reduce_and_v4d __v8d_reduce_and_v4d
#define v8f_reduce_and_v4f __v8f_reduce_and_v4f
#define v8i_reduce_and_v4i __v8i_reduce_and_v4i
#define v8l_reduce_and_v4l __v8l_reduce_and_v4l
#define v16f_reduce_and_v4f __v16f_reduce_and_v4f
#define v16i_reduce_and_v4i __v16i_reduce_and_v4i
#define v1d_reduce_and_v8d __v1d_reduce_and_v8d
#define v1f_reduce_and_v8f __v1f_reduce_and_v8f
#define v1i_reduce_and_v8i __v1i_reduce_and_v8i
#define v1l_reduce_and_v8l __v1l_reduce_and_v8l
#define v2d_reduce_and_v8d __v2d_reduce_and_v8d
#define v2f_reduce_and_v8f __v2f_reduce_and_v8f
#define v2i_reduce_and_v8i __v2i_reduce_and_v8i
#define v2l_reduce_and_v8l __v2l_reduce_and_v8l
#define v4d_reduce_and_v8d __v4d_reduce_and_v8d
#define v4f_reduce_and_v8f __v4f_reduce_and_v8f
#define v4i_reduce_and_v8i __v4i_reduce_and_v8i
#define v4l_reduce_and_v8l __v4l_reduce_and_v8l
#define v8d_reduce_and_v8d __v8d_reduce_and_v8d
#define v8f_reduce_and_v8f __v8f_reduce_and_v8f
#define v8i_reduce_and_v8i __v8i_reduce_and_v8i
#define v8l_reduce_and_v8l __v8l_reduce_and_v8l
#define v16f_reduce_and_v8f __v16f_reduce_and_v8f
#define v16i_reduce_and_v8i __v16i_reduce_and_v8i
#define v1f_reduce_and_v16f __v1f_reduce_and_v16f
#define v1i_reduce_and_v16i __v1i_reduce_and_v16i
#define v2f_reduce_and_v16f __v2f_reduce_and_v16f
#define v2i_reduce_and_v16i __v2i_reduce_and_v16i
#define v4f_reduce_and_v16f __v4f_reduce_and_v16f
#define v4i_reduce_and_v16i __v4i_reduce_and_v16i
#define v8f_reduce_and_v16f __v8f_reduce_and_v16f
#define v8i_reduce_and_v16i __v8i_reduce_and_v16i
#define v16f_reduce_and_v16f __v16f_reduce_and_v16f
#define v16i_reduce_and_v16i __v16i_reduce_and_v16i
#define sd_reduce_and_v1d(a)  sd_cvt_v1d(v1d_reduce_and_v1d(a))
#define sf_reduce_and_v1f(a)  sf_cvt_v1f(v1f_reduce_and_v1f(a))
#define si_reduce_and_v1i(a)  si_cvt_v1i(v1i_reduce_and_v1i(a))
#define sl_reduce_and_v1l(a)  sl_cvt_v1l(v1l_reduce_and_v1l(a))
#define sd_reduce_and_v2d(a)  sd_cvt_v1d(v1d_reduce_and_v2d(a))
#define sf_reduce_and_v2f(a)  sf_cvt_v1f(v1f_reduce_and_v2f(a))
#define si_reduce_and_v2i(a)  si_cvt_v1i(v1i_reduce_and_v2i(a))
#define sl_reduce_and_v2l(a)  sl_cvt_v1l(v1l_reduce_and_v2l(a))
#define sd_reduce_and_v4d(a)  sd_cvt_v1d(v1d_reduce_and_v4d(a))
#define sf_reduce_and_v4f(a)  sf_cvt_v1f(v1f_reduce_and_v4f(a))
#define si_reduce_and_v4i(a)  si_cvt_v1i(v1i_reduce_and_v4i(a))
#define sl_reduce_and_v4l(a)  sl_cvt_v1l(v1l_reduce_and_v4l(a))
#define sd_reduce_and_v8d(a)  sd_cvt_v1d(v1d_reduce_and_v8d(a))
#define sf_reduce_and_v8f(a)  sf_cvt_v1f(v1f_reduce_and_v8f(a))
#define si_reduce_and_v8i(a)  si_cvt_v1i(v1i_reduce_and_v8i(a))
#define sl_reduce_and_v8l(a)  sl_cvt_v1l(v1l_reduce_and_v8l(a))
#define sf_reduce_and_v16f(a)  sf_cvt_v1f(v1f_reduce_and_v16f(a))
#define si_reduce_and_v16i(a)  si_cvt_v1i(v1i_reduce_and_v16i(a))
#define v1d_reduce_or __v1d_reduce_or
#define v1f_reduce_or __v1f_reduce_or
#define v1i_reduce_or __v1i_reduce_or
#define v1l_reduce_or __v1l_reduce_or
#define v2d_reduce_or __v2d_reduce_or
#define v2f_reduce_or __v2f_reduce_or
#define v2i_reduce_or __v2i_reduce_or
#define v2l_reduce_or __v2l_reduce_or
#define v4d_reduce_or __v4d_reduce_or
#define v4f_reduce_or __v4f_reduce_or
#define v4i_reduce_or __v4i_reduce_or
#define v4l_reduce_or __v4l_reduce_or
#define v8d_reduce_or __v8d_reduce_or
#define v8f_reduce_or __v8f_reduce_or
#define v8i_reduce_or __v8i_reduce_or
#define v8l_reduce_or __v8l_reduce_or
#define v16f_reduce_or __v16f_reduce_or
#define v16i_reduce_or __v16i_reduce_or
#define v1d_reduce_or_v1d __v1d_reduce_or_v1d
#define v1f_reduce_or_v1f __v1f_reduce_or_v1f
#define v1i_reduce_or_v1i __v1i_reduce_or_v1i
#define v1l_reduce_or_v1l __v1l_reduce_or_v1l
#define v2d_reduce_or_v1d __v2d_reduce_or_v1d
#define v2f_reduce_or_v1f __v2f_reduce_or_v1f
#define v2i_reduce_or_v1i __v2i_reduce_or_v1i
#define v2l_reduce_or_v1l __v2l_reduce_or_v1l
#define v4d_reduce_or_v1d __v4d_reduce_or_v1d
#define v4f_reduce_or_v1f __v4f_reduce_or_v1f
#define v4i_reduce_or_v1i __v4i_reduce_or_v1i
#define v4l_reduce_or_v1l __v4l_reduce_or_v1l
#define v8d_reduce_or_v1d __v8d_reduce_or_v1d
#define v8f_reduce_or_v1f __v8f_reduce_or_v1f
#define v8i_reduce_or_v1i __v8i_reduce_or_v1i
#define v8l_reduce_or_v1l __v8l_reduce_or_v1l
#define v16f_reduce_or_v1f __v16f_reduce_or_v1f
#define v16i_reduce_or_v1i __v16i_reduce_or_v1i
#define v1d_reduce_or_v2d __v1d_reduce_or_v2d
#define v1f_reduce_or_v2f __v1f_reduce_or_v2f
#define v1i_reduce_or_v2i __v1i_reduce_or_v2i
#define v1l_reduce_or_v2l __v1l_reduce_or_v2l
#define v2d_reduce_or_v2d __v2d_reduce_or_v2d
#define v2f_reduce_or_v2f __v2f_reduce_or_v2f
#define v2i_reduce_or_v2i __v2i_reduce_or_v2i
#define v2l_reduce_or_v2l __v2l_reduce_or_v2l
#define v4d_reduce_or_v2d __v4d_reduce_or_v2d
#define v4f_reduce_or_v2f __v4f_reduce_or_v2f
#define v4i_reduce_or_v2i __v4i_reduce_or_v2i
#define v4l_reduce_or_v2l __v4l_reduce_or_v2l
#define v8d_reduce_or_v2d __v8d_reduce_or_v2d
#define v8f_reduce_or_v2f __v8f_reduce_or_v2f
#define v8i_reduce_or_v2i __v8i_reduce_or_v2i
#define v8l_reduce_or_v2l __v8l_reduce_or_v2l
#define v16f_reduce_or_v2f __v16f_reduce_or_v2f
#define v16i_reduce_or_v2i __v16i_reduce_or_v2i
#define v1d_reduce_or_v4d __v1d_reduce_or_v4d
#define v1f_reduce_or_v4f __v1f_reduce_or_v4f
#define v1i_reduce_or_v4i __v1i_reduce_or_v4i
#define v1l_reduce_or_v4l __v1l_reduce_or_v4l
#define v2d_reduce_or_v4d __v2d_reduce_or_v4d
#define v2f_reduce_or_v4f __v2f_reduce_or_v4f
#define v2i_reduce_or_v4i __v2i_reduce_or_v4i
#define v2l_reduce_or_v4l __v2l_reduce_or_v4l
#define v4d_reduce_or_v4d __v4d_reduce_or_v4d
#define v4f_reduce_or_v4f __v4f_reduce_or_v4f
#define v4i_reduce_or_v4i __v4i_reduce_or_v4i
#define v4l_reduce_or_v4l __v4l_reduce_or_v4l
#define v8d_reduce_or_v4d __v8d_reduce_or_v4d
#define v8f_reduce_or_v4f __v8f_reduce_or_v4f
#define v8i_reduce_or_v4i __v8i_reduce_or_v4i
#define v8l_reduce_or_v4l __v8l_reduce_or_v4l
#define v16f_reduce_or_v4f __v16f_reduce_or_v4f
#define v16i_reduce_or_v4i __v16i_reduce_or_v4i
#define v1d_reduce_or_v8d __v1d_reduce_or_v8d
#define v1f_reduce_or_v8f __v1f_reduce_or_v8f
#define v1i_reduce_or_v8i __v1i_reduce_or_v8i
#define v1l_reduce_or_v8l __v1l_reduce_or_v8l
#define v2d_reduce_or_v8d __v2d_reduce_or_v8d
#define v2f_reduce_or_v8f __v2f_reduce_or_v8f
#define v2i_reduce_or_v8i __v2i_reduce_or_v8i
#define v2l_reduce_or_v8l __v2l_reduce_or_v8l
#define v4d_reduce_or_v8d __v4d_reduce_or_v8d
#define v4f_reduce_or_v8f __v4f_reduce_or_v8f
#define v4i_reduce_or_v8i __v4i_reduce_or_v8i
#define v4l_reduce_or_v8l __v4l_reduce_or_v8l
#define v8d_reduce_or_v8d __v8d_reduce_or_v8d
#define v8f_reduce_or_v8f __v8f_reduce_or_v8f
#define v8i_reduce_or_v8i __v8i_reduce_or_v8i
#define v8l_reduce_or_v8l __v8l_reduce_or_v8l
#define v16f_reduce_or_v8f __v16f_reduce_or_v8f
#define v16i_reduce_or_v8i __v16i_reduce_or_v8i
#define v1f_reduce_or_v16f __v1f_reduce_or_v16f
#define v1i_reduce_or_v16i __v1i_reduce_or_v16i
#define v2f_reduce_or_v16f __v2f_reduce_or_v16f
#define v2i_reduce_or_v16i __v2i_reduce_or_v16i
#define v4f_reduce_or_v16f __v4f_reduce_or_v16f
#define v4i_reduce_or_v16i __v4i_reduce_or_v16i
#define v8f_reduce_or_v16f __v8f_reduce_or_v16f
#define v8i_reduce_or_v16i __v8i_reduce_or_v16i
#define v16f_reduce_or_v16f __v16f_reduce_or_v16f
#define v16i_reduce_or_v16i __v16i_reduce_or_v16i
#define sd_reduce_or_v1d(a)  sd_cvt_v1d(v1d_reduce_or_v1d(a))
#define sf_reduce_or_v1f(a)  sf_cvt_v1f(v1f_reduce_or_v1f(a))
#define si_reduce_or_v1i(a)  si_cvt_v1i(v1i_reduce_or_v1i(a))
#define sl_reduce_or_v1l(a)  sl_cvt_v1l(v1l_reduce_or_v1l(a))
#define sd_reduce_or_v2d(a)  sd_cvt_v1d(v1d_reduce_or_v2d(a))
#define sf_reduce_or_v2f(a)  sf_cvt_v1f(v1f_reduce_or_v2f(a))
#define si_reduce_or_v2i(a)  si_cvt_v1i(v1i_reduce_or_v2i(a))
#define sl_reduce_or_v2l(a)  sl_cvt_v1l(v1l_reduce_or_v2l(a))
#define sd_reduce_or_v4d(a)  sd_cvt_v1d(v1d_reduce_or_v4d(a))
#define sf_reduce_or_v4f(a)  sf_cvt_v1f(v1f_reduce_or_v4f(a))
#define si_reduce_or_v4i(a)  si_cvt_v1i(v1i_reduce_or_v4i(a))
#define sl_reduce_or_v4l(a)  sl_cvt_v1l(v1l_reduce_or_v4l(a))
#define sd_reduce_or_v8d(a)  sd_cvt_v1d(v1d_reduce_or_v8d(a))
#define sf_reduce_or_v8f(a)  sf_cvt_v1f(v1f_reduce_or_v8f(a))
#define si_reduce_or_v8i(a)  si_cvt_v1i(v1i_reduce_or_v8i(a))
#define sl_reduce_or_v8l(a)  sl_cvt_v1l(v1l_reduce_or_v8l(a))
#define sf_reduce_or_v16f(a)  sf_cvt_v1f(v1f_reduce_or_v16f(a))
#define si_reduce_or_v16i(a)  si_cvt_v1i(v1i_reduce_or_v16i(a))
#define v1d_reduce_min __v1d_reduce_min
#define v1f_reduce_min __v1f_reduce_min
#define v1i_reduce_min __v1i_reduce_min
#define v1l_reduce_min __v1l_reduce_min
#define v2d_reduce_min __v2d_reduce_min
#define v2f_reduce_min __v2f_reduce_min
#define v2i_reduce_min __v2i_reduce_min
#define v2l_reduce_min __v2l_reduce_min
#define v4d_reduce_min __v4d_reduce_min
#define v4f_reduce_min __v4f_reduce_min
#define v4i_reduce_min __v4i_reduce_min
#define v4l_reduce_min __v4l_reduce_min
#define v8d_reduce_min __v8d_reduce_min
#define v8f_reduce_min __v8f_reduce_min
#define v8i_reduce_min __v8i_reduce_min
#define v8l_reduce_min __v8l_reduce_min
#define v16f_reduce_min __v16f_reduce_min
#define v16i_reduce_min __v16i_reduce_min
#define v1d_reduce_min_v1d __v1d_reduce_min_v1d
#define v1f_reduce_min_v1f __v1f_reduce_min_v1f
#define v1i_reduce_min_v1i __v1i_reduce_min_v1i
#define v1l_reduce_min_v1l __v1l_reduce_min_v1l
#define v2d_reduce_min_v1d __v2d_reduce_min_v1d
#define v2f_reduce_min_v1f __v2f_reduce_min_v1f
#define v2i_reduce_min_v1i __v2i_reduce_min_v1i
#define v2l_reduce_min_v1l __v2l_reduce_min_v1l
#define v4d_reduce_min_v1d __v4d_reduce_min_v1d
#define v4f_reduce_min_v1f __v4f_reduce_min_v1f
#define v4i_reduce_min_v1i __v4i_reduce_min_v1i
#define v4l_reduce_min_v1l __v4l_reduce_min_v1l
#define v8d_reduce_min_v1d __v8d_reduce_min_v1d
#define v8f_reduce_min_v1f __v8f_reduce_min_v1f
#define v8i_reduce_min_v1i __v8i_reduce_min_v1i
#define v8l_reduce_min_v1l __v8l_reduce_min_v1l
#define v16f_reduce_min_v1f __v16f_reduce_min_v1f
#define v16i_reduce_min_v1i __v16i_reduce_min_v1i
#define v1d_reduce_min_v2d __v1d_reduce_min_v2d
#define v1f_reduce_min_v2f __v1f_reduce_min_v2f
#define v1i_reduce_min_v2i __v1i_reduce_min_v2i
#define v1l_reduce_min_v2l __v1l_reduce_min_v2l
#define v2d_reduce_min_v2d __v2d_reduce_min_v2d
#define v2f_reduce_min_v2f __v2f_reduce_min_v2f
#define v2i_reduce_min_v2i __v2i_reduce_min_v2i
#define v2l_reduce_min_v2l __v2l_reduce_min_v2l
#define v4d_reduce_min_v2d __v4d_reduce_min_v2d
#define v4f_reduce_min_v2f __v4f_reduce_min_v2f
#define v4i_reduce_min_v2i __v4i_reduce_min_v2i
#define v4l_reduce_min_v2l __v4l_reduce_min_v2l
#define v8d_reduce_min_v2d __v8d_reduce_min_v2d
#define v8f_reduce_min_v2f __v8f_reduce_min_v2f
#define v8i_reduce_min_v2i __v8i_reduce_min_v2i
#define v8l_reduce_min_v2l __v8l_reduce_min_v2l
#define v16f_reduce_min_v2f __v16f_reduce_min_v2f
#define v16i_reduce_min_v2i __v16i_reduce_min_v2i
#define v1d_reduce_min_v4d __v1d_reduce_min_v4d
#define v1f_reduce_min_v4f __v1f_reduce_min_v4f
#define v1i_reduce_min_v4i __v1i_reduce_min_v4i
#define v1l_reduce_min_v4l __v1l_reduce_min_v4l
#define v2d_reduce_min_v4d __v2d_reduce_min_v4d
#define v2f_reduce_min_v4f __v2f_reduce_min_v4f
#define v2i_reduce_min_v4i __v2i_reduce_min_v4i
#define v2l_reduce_min_v4l __v2l_reduce_min_v4l
#define v4d_reduce_min_v4d __v4d_reduce_min_v4d
#define v4f_reduce_min_v4f __v4f_reduce_min_v4f
#define v4i_reduce_min_v4i __v4i_reduce_min_v4i
#define v4l_reduce_min_v4l __v4l_reduce_min_v4l
#define v8d_reduce_min_v4d __v8d_reduce_min_v4d
#define v8f_reduce_min_v4f __v8f_reduce_min_v4f
#define v8i_reduce_min_v4i __v8i_reduce_min_v4i
#define v8l_reduce_min_v4l __v8l_reduce_min_v4l
#define v16f_reduce_min_v4f __v16f_reduce_min_v4f
#define v16i_reduce_min_v4i __v16i_reduce_min_v4i
#define v1d_reduce_min_v8d __v1d_reduce_min_v8d
#define v1f_reduce_min_v8f __v1f_reduce_min_v8f
#define v1i_reduce_min_v8i __v1i_reduce_min_v8i
#define v1l_reduce_min_v8l __v1l_reduce_min_v8l
#define v2d_reduce_min_v8d __v2d_reduce_min_v8d
#define v2f_reduce_min_v8f __v2f_reduce_min_v8f
#define v2i_reduce_min_v8i __v2i_reduce_min_v8i
#define v2l_reduce_min_v8l __v2l_reduce_min_v8l
#define v4d_reduce_min_v8d __v4d_reduce_min_v8d
#define v4f_reduce_min_v8f __v4f_reduce_min_v8f
#define v4i_reduce_min_v8i __v4i_reduce_min_v8i
#define v4l_reduce_min_v8l __v4l_reduce_min_v8l
#define v8d_reduce_min_v8d __v8d_reduce_min_v8d
#define v8f_reduce_min_v8f __v8f_reduce_min_v8f
#define v8i_reduce_min_v8i __v8i_reduce_min_v8i
#define v8l_reduce_min_v8l __v8l_reduce_min_v8l
#define v16f_reduce_min_v8f __v16f_reduce_min_v8f
#define v16i_reduce_min_v8i __v16i_reduce_min_v8i
#define v1f_reduce_min_v16f __v1f_reduce_min_v16f
#define v1i_reduce_min_v16i __v1i_reduce_min_v16i
#define v2f_reduce_min_v16f __v2f_reduce_min_v16f
#define v2i_reduce_min_v16i __v2i_reduce_min_v16i
#define v4f_reduce_min_v16f __v4f_reduce_min_v16f
#define v4i_reduce_min_v16i __v4i_reduce_min_v16i
#define v8f_reduce_min_v16f __v8f_reduce_min_v16f
#define v8i_reduce_min_v16i __v8i_reduce_min_v16i
#define v16f_reduce_min_v16f __v16f_reduce_min_v16f
#define v16i_reduce_min_v16i __v16i_reduce_min_v16i
#define sd_reduce_min_v1d(a)  sd_cvt_v1d(v1d_reduce_min_v1d(a))
#define sf_reduce_min_v1f(a)  sf_cvt_v1f(v1f_reduce_min_v1f(a))
#define si_reduce_min_v1i(a)  si_cvt_v1i(v1i_reduce_min_v1i(a))
#define sl_reduce_min_v1l(a)  sl_cvt_v1l(v1l_reduce_min_v1l(a))
#define sd_reduce_min_v2d(a)  sd_cvt_v1d(v1d_reduce_min_v2d(a))
#define sf_reduce_min_v2f(a)  sf_cvt_v1f(v1f_reduce_min_v2f(a))
#define si_reduce_min_v2i(a)  si_cvt_v1i(v1i_reduce_min_v2i(a))
#define sl_reduce_min_v2l(a)  sl_cvt_v1l(v1l_reduce_min_v2l(a))
#define sd_reduce_min_v4d(a)  sd_cvt_v1d(v1d_reduce_min_v4d(a))
#define sf_reduce_min_v4f(a)  sf_cvt_v1f(v1f_reduce_min_v4f(a))
#define si_reduce_min_v4i(a)  si_cvt_v1i(v1i_reduce_min_v4i(a))
#define sl_reduce_min_v4l(a)  sl_cvt_v1l(v1l_reduce_min_v4l(a))
#define sd_reduce_min_v8d(a)  sd_cvt_v1d(v1d_reduce_min_v8d(a))
#define sf_reduce_min_v8f(a)  sf_cvt_v1f(v1f_reduce_min_v8f(a))
#define si_reduce_min_v8i(a)  si_cvt_v1i(v1i_reduce_min_v8i(a))
#define sl_reduce_min_v8l(a)  sl_cvt_v1l(v1l_reduce_min_v8l(a))
#define sf_reduce_min_v16f(a)  sf_cvt_v1f(v1f_reduce_min_v16f(a))
#define si_reduce_min_v16i(a)  si_cvt_v1i(v1i_reduce_min_v16i(a))
#define v1d_reduce_max __v1d_reduce_max
#define v1f_reduce_max __v1f_reduce_max
#define v1i_reduce_max __v1i_reduce_max
#define v1l_reduce_max __v1l_reduce_max
#define v2d_reduce_max __v2d_reduce_max
#define v2f_reduce_max __v2f_reduce_max
#define v2i_reduce_max __v2i_reduce_max
#define v2l_reduce_max __v2l_reduce_max
#define v4d_reduce_max __v4d_reduce_max
#define v4f_reduce_max __v4f_reduce_max
#define v4i_reduce_max __v4i_reduce_max
#define v4l_reduce_max __v4l_reduce_max
#define v8d_reduce_max __v8d_reduce_max
#define v8f_reduce_max __v8f_reduce_max
#define v8i_reduce_max __v8i_reduce_max
#define v8l_reduce_max __v8l_reduce_max
#define v16f_reduce_max __v16f_reduce_max
#define v16i_reduce_max __v16i_reduce_max
#define v1d_reduce_max_v1d __v1d_reduce_max_v1d
#define v1f_reduce_max_v1f __v1f_reduce_max_v1f
#define v1i_reduce_max_v1i __v1i_reduce_max_v1i
#define v1l_reduce_max_v1l __v1l_reduce_max_v1l
#define v2d_reduce_max_v1d __v2d_reduce_max_v1d
#define v2f_reduce_max_v1f __v2f_reduce_max_v1f
#define v2i_reduce_max_v1i __v2i_reduce_max_v1i
#define v2l_reduce_max_v1l __v2l_reduce_max_v1l
#define v4d_reduce_max_v1d __v4d_reduce_max_v1d
#define v4f_reduce_max_v1f __v4f_reduce_max_v1f
#define v4i_reduce_max_v1i __v4i_reduce_max_v1i
#define v4l_reduce_max_v1l __v4l_reduce_max_v1l
#define v8d_reduce_max_v1d __v8d_reduce_max_v1d
#define v8f_reduce_max_v1f __v8f_reduce_max_v1f
#define v8i_reduce_max_v1i __v8i_reduce_max_v1i
#define v8l_reduce_max_v1l __v8l_reduce_max_v1l
#define v16f_reduce_max_v1f __v16f_reduce_max_v1f
#define v16i_reduce_max_v1i __v16i_reduce_max_v1i
#define v1d_reduce_max_v2d __v1d_reduce_max_v2d
#define v1f_reduce_max_v2f __v1f_reduce_max_v2f
#define v1i_reduce_max_v2i __v1i_reduce_max_v2i
#define v1l_reduce_max_v2l __v1l_reduce_max_v2l
#define v2d_reduce_max_v2d __v2d_reduce_max_v2d
#define v2f_reduce_max_v2f __v2f_reduce_max_v2f
#define v2i_reduce_max_v2i __v2i_reduce_max_v2i
#define v2l_reduce_max_v2l __v2l_reduce_max_v2l
#define v4d_reduce_max_v2d __v4d_reduce_max_v2d
#define v4f_reduce_max_v2f __v4f_reduce_max_v2f
#define v4i_reduce_max_v2i __v4i_reduce_max_v2i
#define v4l_reduce_max_v2l __v4l_reduce_max_v2l
#define v8d_reduce_max_v2d __v8d_reduce_max_v2d
#define v8f_reduce_max_v2f __v8f_reduce_max_v2f
#define v8i_reduce_max_v2i __v8i_reduce_max_v2i
#define v8l_reduce_max_v2l __v8l_reduce_max_v2l
#define v16f_reduce_max_v2f __v16f_reduce_max_v2f
#define v16i_reduce_max_v2i __v16i_reduce_max_v2i
#define v1d_reduce_max_v4d __v1d_reduce_max_v4d
#define v1f_reduce_max_v4f __v1f_reduce_max_v4f
#define v1i_reduce_max_v4i __v1i_reduce_max_v4i
#define v1l_reduce_max_v4l __v1l_reduce_max_v4l
#define v2d_reduce_max_v4d __v2d_reduce_max_v4d
#define v2f_reduce_max_v4f __v2f_reduce_max_v4f
#define v2i_reduce_max_v4i __v2i_reduce_max_v4i
#define v2l_reduce_max_v4l __v2l_reduce_max_v4l
#define v4d_reduce_max_v4d __v4d_reduce_max_v4d
#define v4f_reduce_max_v4f __v4f_reduce_max_v4f
#define v4i_reduce_max_v4i __v4i_reduce_max_v4i
#define v4l_reduce_max_v4l __v4l_reduce_max_v4l
#define v8d_reduce_max_v4d __v8d_reduce_max_v4d
#define v8f_reduce_max_v4f __v8f_reduce_max_v4f
#define v8i_reduce_max_v4i __v8i_reduce_max_v4i
#define v8l_reduce_max_v4l __v8l_reduce_max_v4l
#define v16f_reduce_max_v4f __v16f_reduce_max_v4f
#define v16i_reduce_max_v4i __v16i_reduce_max_v4i
#define v1d_reduce_max_v8d __v1d_reduce_max_v8d
#define v1f_reduce_max_v8f __v1f_reduce_max_v8f
#define v1i_reduce_max_v8i __v1i_reduce_max_v8i
#define v1l_reduce_max_v8l __v1l_reduce_max_v8l
#define v2d_reduce_max_v8d __v2d_reduce_max_v8d
#define v2f_reduce_max_v8f __v2f_reduce_max_v8f
#define v2i_reduce_max_v8i __v2i_reduce_max_v8i
#define v2l_reduce_max_v8l __v2l_reduce_max_v8l
#define v4d_reduce_max_v8d __v4d_reduce_max_v8d
#define v4f_reduce_max_v8f __v4f_reduce_max_v8f
#define v4i_reduce_max_v8i __v4i_reduce_max_v8i
#define v4l_reduce_max_v8l __v4l_reduce_max_v8l
#define v8d_reduce_max_v8d __v8d_reduce_max_v8d
#define v8f_reduce_max_v8f __v8f_reduce_max_v8f
#define v8i_reduce_max_v8i __v8i_reduce_max_v8i
#define v8l_reduce_max_v8l __v8l_reduce_max_v8l
#define v16f_reduce_max_v8f __v16f_reduce_max_v8f
#define v16i_reduce_max_v8i __v16i_reduce_max_v8i
#define v1f_reduce_max_v16f __v1f_reduce_max_v16f
#define v1i_reduce_max_v16i __v1i_reduce_max_v16i
#define v2f_reduce_max_v16f __v2f_reduce_max_v16f
#define v2i_reduce_max_v16i __v2i_reduce_max_v16i
#define v4f_reduce_max_v16f __v4f_reduce_max_v16f
#define v4i_reduce_max_v16i __v4i_reduce_max_v16i
#define v8f_reduce_max_v16f __v8f_reduce_max_v16f
#define v8i_reduce_max_v16i __v8i_reduce_max_v16i
#define v16f_reduce_max_v16f __v16f_reduce_max_v16f
#define v16i_reduce_max_v16i __v16i_reduce_max_v16i
#define sd_reduce_max_v1d(a)  sd_cvt_v1d(v1d_reduce_max_v1d(a))
#define sf_reduce_max_v1f(a)  sf_cvt_v1f(v1f_reduce_max_v1f(a))
#define si_reduce_max_v1i(a)  si_cvt_v1i(v1i_reduce_max_v1i(a))
#define sl_reduce_max_v1l(a)  sl_cvt_v1l(v1l_reduce_max_v1l(a))
#define sd_reduce_max_v2d(a)  sd_cvt_v1d(v1d_reduce_max_v2d(a))
#define sf_reduce_max_v2f(a)  sf_cvt_v1f(v1f_reduce_max_v2f(a))
#define si_reduce_max_v2i(a)  si_cvt_v1i(v1i_reduce_max_v2i(a))
#define sl_reduce_max_v2l(a)  sl_cvt_v1l(v1l_reduce_max_v2l(a))
#define sd_reduce_max_v4d(a)  sd_cvt_v1d(v1d_reduce_max_v4d(a))
#define sf_reduce_max_v4f(a)  sf_cvt_v1f(v1f_reduce_max_v4f(a))
#define si_reduce_max_v4i(a)  si_cvt_v1i(v1i_reduce_max_v4i(a))
#define sl_reduce_max_v4l(a)  sl_cvt_v1l(v1l_reduce_max_v4l(a))
#define sd_reduce_max_v8d(a)  sd_cvt_v1d(v1d_reduce_max_v8d(a))
#define sf_reduce_max_v8f(a)  sf_cvt_v1f(v1f_reduce_max_v8f(a))
#define si_reduce_max_v8i(a)  si_cvt_v1i(v1i_reduce_max_v8i(a))
#define sl_reduce_max_v8l(a)  sl_cvt_v1l(v1l_reduce_max_v8l(a))
#define sf_reduce_max_v16f(a)  sf_cvt_v1f(v1f_reduce_max_v16f(a))
#define si_reduce_max_v16i(a)  si_cvt_v1i(v1i_reduce_max_v16i(a))


/* MOVES */

#define v1d_move(a)  (a)
#define v1f_move(a)  (a)
#define v1i_move(a)  (a)
#define v1l_move(a)  (a)
#define v2d_move(a)  (a)
#define v2f_move(a)  (a)
#define v2i_move(a)  (a)
#define v2l_move(a)  (a)
#define v4d_move(a)  (a)
#define v4f_move(a)  (a)
#define v4i_move(a)  (a)
#define v4l_move(a)  (a)
#define v8d_move(a)  (a)
#define v8f_move(a)  (a)
#define v8i_move(a)  (a)
#define v8l_move(a)  (a)
#define v16f_move(a)  (a)
#define v16i_move(a)  (a)

#define v1d_maskz_move(mask,a)  v1d_and(mask, a)
#define v1f_maskz_move(mask,a)  v1f_and(mask, a)
#define v1i_maskz_move(mask,a)  v1i_and(mask, a)
#define v1l_maskz_move(mask,a)  v1l_and(mask, a)
#define v2d_maskz_move(mask,a)  v2d_and(mask, a)
#define v2f_maskz_move(mask,a)  v2f_and(mask, a)
#define v2i_maskz_move(mask,a)  v2i_and(mask, a)
#define v2l_maskz_move(mask,a)  v2l_and(mask, a)
#define v4d_maskz_move(mask,a)  v4d_and(mask, a)
#define v4f_maskz_move(mask,a)  v4f_and(mask, a)
#define v4i_maskz_move(mask,a)  v4i_and(mask, a)
#define v4l_maskz_move(mask,a)  v4l_and(mask, a)
#define v8d_maskz_move(mask,a)  v8d_and(mask, a)
#define v8f_maskz_move(mask,a)  v8f_and(mask, a)
#define v8i_maskz_move(mask,a)  v8i_and(mask, a)
#define v8l_maskz_move(mask,a)  v8l_and(mask, a)
#define v16f_maskz_move(mask,a)  v16f_and(mask, a)
#define v16i_maskz_move(mask,a)  v16i_and(mask, a)

#define v1d_mask_move(mask,src,a)  v1d_or(v1d_and(a, mask), v1d_andnot(a, mask))
#define v1f_mask_move(mask,src,a)  v1f_or(v1f_and(a, mask), v1f_andnot(a, mask))
#define v1i_mask_move(mask,src,a)  v1i_or(v1i_and(a, mask), v1i_andnot(a, mask))
#define v1l_mask_move(mask,src,a)  v1l_or(v1l_and(a, mask), v1l_andnot(a, mask))
#define v2d_mask_move(mask,src,a)  v2d_or(v2d_and(a, mask), v2d_andnot(a, mask))
#define v2f_mask_move(mask,src,a)  v2f_or(v2f_and(a, mask), v2f_andnot(a, mask))
#define v2i_mask_move(mask,src,a)  v2i_or(v2i_and(a, mask), v2i_andnot(a, mask))
#define v2l_mask_move(mask,src,a)  v2l_or(v2l_and(a, mask), v2l_andnot(a, mask))
#define v4d_mask_move(mask,src,a)  v4d_or(v4d_and(a, mask), v4d_andnot(a, mask))
#define v4f_mask_move(mask,src,a)  v4f_or(v4f_and(a, mask), v4f_andnot(a, mask))
#define v4i_mask_move(mask,src,a)  v4i_or(v4i_and(a, mask), v4i_andnot(a, mask))
#define v4l_mask_move(mask,src,a)  v4l_or(v4l_and(a, mask), v4l_andnot(a, mask))
#define v8d_mask_move(mask,src,a)  v8d_or(v8d_and(a, mask), v8d_andnot(a, mask))
#define v8f_mask_move(mask,src,a)  v8f_or(v8f_and(a, mask), v8f_andnot(a, mask))
#define v8i_mask_move(mask,src,a)  v8i_or(v8i_and(a, mask), v8i_andnot(a, mask))
#define v8l_mask_move(mask,src,a)  v8l_or(v8l_and(a, mask), v8l_andnot(a, mask))
#define v16f_mask_move(mask,src,a)  v16f_or(v16f_and(a, mask), v16f_andnot(a, mask))
#define v16i_mask_move(mask,src,a)  v16i_or(v16i_and(a, mask), v16i_andnot(a, mask))


/* PRINTS */

#define v1d_fprintf __v1d_fprintf
#define v1f_fprintf __v1f_fprintf
#define v1i_fprintf __v1i_fprintf
#define v1l_fprintf __v1l_fprintf
#define v2d_fprintf __v2d_fprintf
#define v2f_fprintf __v2f_fprintf
#define v2i_fprintf __v2i_fprintf
#define v2l_fprintf __v2l_fprintf
#define v4d_fprintf __v4d_fprintf
#define v4f_fprintf __v4f_fprintf
#define v4i_fprintf __v4i_fprintf
#define v4l_fprintf __v4l_fprintf
#define v8d_fprintf __v8d_fprintf
#define v8f_fprintf __v8f_fprintf
#define v8i_fprintf __v8i_fprintf
#define v8l_fprintf __v8l_fprintf
#define v16f_fprintf __v16f_fprintf
#define v16i_fprintf __v16i_fprintf

#define v1d_printf(a,format)  v1d_fprintf(stdout, (a), format)
#define v1f_printf(a,format)  v1f_fprintf(stdout, (a), format)
#define v1i_printf(a,format)  v1i_fprintf(stdout, (a), format)
#define v1l_printf(a,format)  v1l_fprintf(stdout, (a), format)
#define v2d_printf(a,format)  v2d_fprintf(stdout, (a), format)
#define v2f_printf(a,format)  v2f_fprintf(stdout, (a), format)
#define v2i_printf(a,format)  v2i_fprintf(stdout, (a), format)
#define v2l_printf(a,format)  v2l_fprintf(stdout, (a), format)
#define v4d_printf(a,format)  v4d_fprintf(stdout, (a), format)
#define v4f_printf(a,format)  v4f_fprintf(stdout, (a), format)
#define v4i_printf(a,format)  v4i_fprintf(stdout, (a), format)
#define v4l_printf(a,format)  v4l_fprintf(stdout, (a), format)
#define v8d_printf(a,format)  v8d_fprintf(stdout, (a), format)
#define v8f_printf(a,format)  v8f_fprintf(stdout, (a), format)
#define v8i_printf(a,format)  v8i_fprintf(stdout, (a), format)
#define v8l_printf(a,format)  v8l_fprintf(stdout, (a), format)
#define v16f_printf(a,format)  v16f_fprintf(stdout, (a), format)
#define v16i_printf(a,format)  v16i_fprintf(stdout, (a), format)

#define v1d_fprint(file,a)  v1d_fprintf((file), (a), "%lf")
#define v1f_fprint(file,a)  v1f_fprintf((file), (a), "%f")
#define v1i_fprint(file,a)  v1i_fprintf((file), (a), "%i")
#define v1l_fprint(file,a)  v1l_fprintf((file), (a), "%lli")
#define v2d_fprint(file,a)  v2d_fprintf((file), (a), "%lf")
#define v2f_fprint(file,a)  v2f_fprintf((file), (a), "%f")
#define v2i_fprint(file,a)  v2i_fprintf((file), (a), "%i")
#define v2l_fprint(file,a)  v2l_fprintf((file), (a), "%lli")
#define v4d_fprint(file,a)  v4d_fprintf((file), (a), "%lf")
#define v4f_fprint(file,a)  v4f_fprintf((file), (a), "%f")
#define v4i_fprint(file,a)  v4i_fprintf((file), (a), "%i")
#define v4l_fprint(file,a)  v4l_fprintf((file), (a), "%lli")
#define v8d_fprint(file,a)  v8d_fprintf((file), (a), "%lf")
#define v8f_fprint(file,a)  v8f_fprintf((file), (a), "%f")
#define v8i_fprint(file,a)  v8i_fprintf((file), (a), "%i")
#define v8l_fprint(file,a)  v8l_fprintf((file), (a), "%lli")
#define v16f_fprint(file,a)  v16f_fprintf((file), (a), "%f")
#define v16i_fprint(file,a)  v16i_fprintf((file), (a), "%i")

#define v1d_print(a)  v1d_fprintf(stdout, (a), "%lf")
#define v1f_print(a)  v1f_fprintf(stdout, (a), "%f")
#define v1i_print(a)  v1i_fprintf(stdout, (a), "%i")
#define v1l_print(a)  v1l_fprintf(stdout, (a), "%lli")
#define v2d_print(a)  v2d_fprintf(stdout, (a), "%lf")
#define v2f_print(a)  v2f_fprintf(stdout, (a), "%f")
#define v2i_print(a)  v2i_fprintf(stdout, (a), "%i")
#define v2l_print(a)  v2l_fprintf(stdout, (a), "%lli")
#define v4d_print(a)  v4d_fprintf(stdout, (a), "%lf")
#define v4f_print(a)  v4f_fprintf(stdout, (a), "%f")
#define v4i_print(a)  v4i_fprintf(stdout, (a), "%i")
#define v4l_print(a)  v4l_fprintf(stdout, (a), "%lli")
#define v8d_print(a)  v8d_fprintf(stdout, (a), "%lf")
#define v8f_print(a)  v8f_fprintf(stdout, (a), "%f")
#define v8i_print(a)  v8i_fprintf(stdout, (a), "%i")
#define v8l_print(a)  v8l_fprintf(stdout, (a), "%lli")
#define v16f_print(a)  v16f_fprintf(stdout, (a), "%f")
#define v16i_print(a)  v16i_fprintf(stdout, (a), "%i")

#define v1d_rfprintf __v1d_rfprintf
#define v1f_rfprintf __v1f_rfprintf
#define v1i_rfprintf __v1i_rfprintf
#define v1l_rfprintf __v1l_rfprintf
#define v2d_rfprintf __v2d_rfprintf
#define v2f_rfprintf __v2f_rfprintf
#define v2i_rfprintf __v2i_rfprintf
#define v2l_rfprintf __v2l_rfprintf
#define v4d_rfprintf __v4d_rfprintf
#define v4f_rfprintf __v4f_rfprintf
#define v4i_rfprintf __v4i_rfprintf
#define v4l_rfprintf __v4l_rfprintf
#define v8d_rfprintf __v8d_rfprintf
#define v8f_rfprintf __v8f_rfprintf
#define v8i_rfprintf __v8i_rfprintf
#define v8l_rfprintf __v8l_rfprintf
#define v16f_rfprintf __v16f_rfprintf
#define v16i_rfprintf __v16i_rfprintf

#define v1d_rprintf(a,format)  v1d_rfprintf(stdout, (a), format)
#define v1f_rprintf(a,format)  v1f_rfprintf(stdout, (a), format)
#define v1i_rprintf(a,format)  v1i_rfprintf(stdout, (a), format)
#define v1l_rprintf(a,format)  v1l_rfprintf(stdout, (a), format)
#define v2d_rprintf(a,format)  v2d_rfprintf(stdout, (a), format)
#define v2f_rprintf(a,format)  v2f_rfprintf(stdout, (a), format)
#define v2i_rprintf(a,format)  v2i_rfprintf(stdout, (a), format)
#define v2l_rprintf(a,format)  v2l_rfprintf(stdout, (a), format)
#define v4d_rprintf(a,format)  v4d_rfprintf(stdout, (a), format)
#define v4f_rprintf(a,format)  v4f_rfprintf(stdout, (a), format)
#define v4i_rprintf(a,format)  v4i_rfprintf(stdout, (a), format)
#define v4l_rprintf(a,format)  v4l_rfprintf(stdout, (a), format)
#define v8d_rprintf(a,format)  v8d_rfprintf(stdout, (a), format)
#define v8f_rprintf(a,format)  v8f_rfprintf(stdout, (a), format)
#define v8i_rprintf(a,format)  v8i_rfprintf(stdout, (a), format)
#define v8l_rprintf(a,format)  v8l_rfprintf(stdout, (a), format)
#define v16f_rprintf(a,format)  v16f_rfprintf(stdout, (a), format)
#define v16i_rprintf(a,format)  v16i_rfprintf(stdout, (a), format)

#define v1d_rfprint(file,a)  v1d_rfprintf((file), (a), "%lf")
#define v1f_rfprint(file,a)  v1f_rfprintf((file), (a), "%f")
#define v1i_rfprint(file,a)  v1i_rfprintf((file), (a), "%i")
#define v1l_rfprint(file,a)  v1l_rfprintf((file), (a), "%lli")
#define v2d_rfprint(file,a)  v2d_rfprintf((file), (a), "%lf")
#define v2f_rfprint(file,a)  v2f_rfprintf((file), (a), "%f")
#define v2i_rfprint(file,a)  v2i_rfprintf((file), (a), "%i")
#define v2l_rfprint(file,a)  v2l_rfprintf((file), (a), "%lli")
#define v4d_rfprint(file,a)  v4d_rfprintf((file), (a), "%lf")
#define v4f_rfprint(file,a)  v4f_rfprintf((file), (a), "%f")
#define v4i_rfprint(file,a)  v4i_rfprintf((file), (a), "%i")
#define v4l_rfprint(file,a)  v4l_rfprintf((file), (a), "%lli")
#define v8d_rfprint(file,a)  v8d_rfprintf((file), (a), "%lf")
#define v8f_rfprint(file,a)  v8f_rfprintf((file), (a), "%f")
#define v8i_rfprint(file,a)  v8i_rfprintf((file), (a), "%i")
#define v8l_rfprint(file,a)  v8l_rfprintf((file), (a), "%lli")
#define v16f_rfprint(file,a)  v16f_rfprintf((file), (a), "%f")
#define v16i_rfprint(file,a)  v16i_rfprintf((file), (a), "%i")

#define v1d_rprint(a)  v1d_rfprintf(stdout, (a), "%lf")
#define v1f_rprint(a)  v1f_rfprintf(stdout, (a), "%f")
#define v1i_rprint(a)  v1i_rfprintf(stdout, (a), "%i")
#define v1l_rprint(a)  v1l_rfprintf(stdout, (a), "%lli")
#define v2d_rprint(a)  v2d_rfprintf(stdout, (a), "%lf")
#define v2f_rprint(a)  v2f_rfprintf(stdout, (a), "%f")
#define v2i_rprint(a)  v2i_rfprintf(stdout, (a), "%i")
#define v2l_rprint(a)  v2l_rfprintf(stdout, (a), "%lli")
#define v4d_rprint(a)  v4d_rfprintf(stdout, (a), "%lf")
#define v4f_rprint(a)  v4f_rfprintf(stdout, (a), "%f")
#define v4i_rprint(a)  v4i_rfprintf(stdout, (a), "%i")
#define v4l_rprint(a)  v4l_rfprintf(stdout, (a), "%lli")
#define v8d_rprint(a)  v8d_rfprintf(stdout, (a), "%lf")
#define v8f_rprint(a)  v8f_rfprintf(stdout, (a), "%f")
#define v8i_rprint(a)  v8i_rfprintf(stdout, (a), "%i")
#define v8l_rprint(a)  v8l_rfprintf(stdout, (a), "%lli")
#define v16f_rprint(a)  v16f_rfprintf(stdout, (a), "%f")
#define v16i_rprint(a)  v16i_rfprintf(stdout, (a), "%i")

/* CASTS */

#define v1d_cast_v1d(a)  (a)
#define v1l_cast_v1d(a)  PINTS_REINTERPRET(v1l, v1d, (a))
#define v2d_cast_v1d __v2d_cast_v1d
#define v2f_cast_v1d(a)  PINTS_REINTERPRET(v2f, v1d, (a))
#define v2i_cast_v1d(a)  PINTS_REINTERPRET(v2i, v1d, (a))
#define v2l_cast_v1d(a)  v2l_cast_v1l(v1l_cast_v1l(v1l_cast_v1d(a)))
#define v4d_cast_v1d(a)  v4d_cast_v2d(v2d_cast_v1d(a))
#define v4f_cast_v1d(a)  v4f_cast_v2f(v2f_cast_v1f(v1f_cast_v1d(a)))
#define v4i_cast_v1d(a)  v4i_cast_v2i(v2i_cast_v1i(v1i_cast_v1d(a)))
#define v4l_cast_v1d(a)  v4l_cast_v2l(v2l_cast_v1l(v1l_cast_v1d(a)))
#define v8d_cast_v1d(a)  v8d_cast_v4d(v4d_cast_v1d(a))
#define v8f_cast_v1d(a)  v8f_cast_v4f(v4f_cast_v1f(v1f_cast_v1d(a)))
#define v8i_cast_v1d(a)  v8i_cast_v4i(v4i_cast_v1i(v1i_cast_v1d(a)))
#define v8l_cast_v1d(a)  v8l_cast_v4l(v4l_cast_v1l(v1l_cast_v1d(a)))
#define v16f_cast_v1d(a)  v16f_cast_v8f(v8f_cast_v1f(v1f_cast_v1d(a)))
#define v16i_cast_v1d(a)  v16i_cast_v8i(v8i_cast_v1i(v1i_cast_v1d(a)))
#define v1f_cast_v1f(a)  (a)
#define v1i_cast_v1f(a)  PINTS_REINTERPRET(v1i, v1f, (a))
#define v2d_cast_v1f(a)  v2d_cast_v1d(v1d_cast_v1d(v1d_cast_v1f(a)))
#define v2f_cast_v1f __v2f_cast_v1f
#define v2i_cast_v1f(a)  v2i_cast_v1i(v1i_cast_v1i(v1i_cast_v1f(a)))
#define v2l_cast_v1f(a)  v2l_cast_v1l(v1l_cast_v1l(v1l_cast_v1f(a)))
#define v4d_cast_v1f(a)  v4d_cast_v2d(v2d_cast_v1d(v1d_cast_v1f(a)))
#define v4f_cast_v1f(a)  v4f_cast_v2f(v2f_cast_v1f(a))
#define v4i_cast_v1f(a)  v4i_cast_v2i(v2i_cast_v1i(v1i_cast_v1f(a)))
#define v4l_cast_v1f(a)  v4l_cast_v2l(v2l_cast_v1l(v1l_cast_v1f(a)))
#define v8d_cast_v1f(a)  v8d_cast_v4d(v4d_cast_v1d(v1d_cast_v1f(a)))
#define v8f_cast_v1f(a)  v8f_cast_v4f(v4f_cast_v1f(a))
#define v8i_cast_v1f(a)  v8i_cast_v4i(v4i_cast_v1i(v1i_cast_v1f(a)))
#define v8l_cast_v1f(a)  v8l_cast_v4l(v4l_cast_v1l(v1l_cast_v1f(a)))
#define v16f_cast_v1f(a)  v16f_cast_v8f(v8f_cast_v1f(a))
#define v16i_cast_v1f(a)  v16i_cast_v8i(v8i_cast_v1i(v1i_cast_v1f(a)))
#define v1f_cast_v1i(a)  PINTS_REINTERPRET(v1f, v1i, (a))
#define v1i_cast_v1i(a)  (a)
#define v2d_cast_v1i(a)  v2d_cast_v1d(v1d_cast_v1d(v1d_cast_v1i(a)))
#define v2f_cast_v1i(a)  v2f_cast_v1f(v1f_cast_v1f(v1f_cast_v1i(a)))
#define v2i_cast_v1i __v2i_cast_v1i
#define v2l_cast_v1i(a)  v2l_cast_v1l(v1l_cast_v1l(v1l_cast_v1i(a)))
#define v4d_cast_v1i(a)  v4d_cast_v2d(v2d_cast_v1d(v1d_cast_v1i(a)))
#define v4f_cast_v1i(a)  v4f_cast_v2f(v2f_cast_v1f(v1f_cast_v1i(a)))
#define v4i_cast_v1i(a)  v4i_cast_v2i(v2i_cast_v1i(a))
#define v4l_cast_v1i(a)  v4l_cast_v2l(v2l_cast_v1l(v1l_cast_v1i(a)))
#define v8d_cast_v1i(a)  v8d_cast_v4d(v4d_cast_v1d(v1d_cast_v1i(a)))
#define v8f_cast_v1i(a)  v8f_cast_v4f(v4f_cast_v1f(v1f_cast_v1i(a)))
#define v8i_cast_v1i(a)  v8i_cast_v4i(v4i_cast_v1i(a))
#define v8l_cast_v1i(a)  v8l_cast_v4l(v4l_cast_v1l(v1l_cast_v1i(a)))
#define v16f_cast_v1i(a)  v16f_cast_v8f(v8f_cast_v1f(v1f_cast_v1i(a)))
#define v16i_cast_v1i(a)  v16i_cast_v8i(v8i_cast_v1i(a))
#define v1d_cast_v1l(a)  PINTS_REINTERPRET(v1d, v1l, (a))
#define v1l_cast_v1l(a)  (a)
#define v2d_cast_v1l(a)  v2d_cast_v1d(v1d_cast_v1d(v1d_cast_v1l(a)))
#define v2f_cast_v1l(a)  PINTS_REINTERPRET(v2f, v1l, (a))
#define v2i_cast_v1l(a)  PINTS_REINTERPRET(v2i, v1l, (a))
#define v2l_cast_v1l __v2l_cast_v1l
#define v4d_cast_v1l(a)  v4d_cast_v2d(v2d_cast_v1d(v1d_cast_v1l(a)))
#define v4f_cast_v1l(a)  v4f_cast_v2f(v2f_cast_v1f(v1f_cast_v1l(a)))
#define v4i_cast_v1l(a)  v4i_cast_v2i(v2i_cast_v1i(v1i_cast_v1l(a)))
#define v4l_cast_v1l(a)  v4l_cast_v2l(v2l_cast_v1l(a))
#define v8d_cast_v1l(a)  v8d_cast_v4d(v4d_cast_v1d(v1d_cast_v1l(a)))
#define v8f_cast_v1l(a)  v8f_cast_v4f(v4f_cast_v1f(v1f_cast_v1l(a)))
#define v8i_cast_v1l(a)  v8i_cast_v4i(v4i_cast_v1i(v1i_cast_v1l(a)))
#define v8l_cast_v1l(a)  v8l_cast_v4l(v4l_cast_v1l(a))
#define v16f_cast_v1l(a)  v16f_cast_v8f(v8f_cast_v1f(v1f_cast_v1l(a)))
#define v16i_cast_v1l(a)  v16i_cast_v8i(v8i_cast_v1i(v1i_cast_v1l(a)))
#define v1d_cast_v2d __v1d_cast_v2d
#define v1f_cast_v2d(a)  v1f_cast_v1d(v1d_cast_v1d(v1d_cast_v2d(a)))
#define v1i_cast_v2d(a)  v1i_cast_v1d(v1d_cast_v1d(v1d_cast_v2d(a)))
#define v1l_cast_v2d(a)  v1l_cast_v1d(v1d_cast_v1d(v1d_cast_v2d(a)))
#define v2d_cast_v2d(a)  (a)
#define v2f_cast_v2d(a)  v2f_cast_v2d(v2d_cast_v1d(v1d_cast_v2d(a)))
#define v2i_cast_v2d(a)  v2i_cast_v2d(v2d_cast_v1d(v1d_cast_v2d(a)))
#define v2l_cast_v2d(a)  PINTS_REINTERPRET(v2l, v2d, (a))
#define v4d_cast_v2d __v4d_cast_v2d
#define v4f_cast_v2d(a)  PINTS_REINTERPRET(v4f, v2d, (a))
#define v4i_cast_v2d(a)  PINTS_REINTERPRET(v4i, v2d, (a))
#define v4l_cast_v2d(a)  v4l_cast_v2l(v2l_cast_v2l(v2l_cast_v2d(a)))
#define v8d_cast_v2d(a)  v8d_cast_v4d(v4d_cast_v2d(a))
#define v8f_cast_v2d(a)  v8f_cast_v4f(v4f_cast_v2f(v2f_cast_v2d(a)))
#define v8i_cast_v2d(a)  v8i_cast_v4i(v4i_cast_v2i(v2i_cast_v2d(a)))
#define v8l_cast_v2d(a)  v8l_cast_v4l(v4l_cast_v2l(v2l_cast_v2d(a)))
#define v16f_cast_v2d(a)  v16f_cast_v8f(v8f_cast_v2f(v2f_cast_v2d(a)))
#define v16i_cast_v2d(a)  v16i_cast_v8i(v8i_cast_v2i(v2i_cast_v2d(a)))
#define v1d_cast_v2f(a)  PINTS_REINTERPRET(v1d, v2f, (a))
#define v1f_cast_v2f __v1f_cast_v2f
#define v1i_cast_v2f(a)  v1i_cast_v1f(v1f_cast_v1f(v1f_cast_v2f(a)))
#define v1l_cast_v2f(a)  PINTS_REINTERPRET(v1l, v2f, (a))
#define v2d_cast_v2f(a)  v2d_cast_v1d(v1d_cast_v2d(v2d_cast_v2f(a)))
#define v2f_cast_v2f(a)  (a)
#define v2i_cast_v2f(a)  PINTS_REINTERPRET(v2i, v2f, (a))
#define v2l_cast_v2f(a)  v2l_cast_v1l(v1l_cast_v2l(v2l_cast_v2f(a)))
#define v4d_cast_v2f(a)  v4d_cast_v2d(v2d_cast_v2d(v2d_cast_v2f(a)))
#define v4f_cast_v2f __v4f_cast_v2f
#define v4i_cast_v2f(a)  v4i_cast_v2i(v2i_cast_v2i(v2i_cast_v2f(a)))
#define v4l_cast_v2f(a)  v4l_cast_v2l(v2l_cast_v2l(v2l_cast_v2f(a)))
#define v8d_cast_v2f(a)  v8d_cast_v4d(v4d_cast_v2d(v2d_cast_v2f(a)))
#define v8f_cast_v2f(a)  v8f_cast_v4f(v4f_cast_v2f(a))
#define v8i_cast_v2f(a)  v8i_cast_v4i(v4i_cast_v2i(v2i_cast_v2f(a)))
#define v8l_cast_v2f(a)  v8l_cast_v4l(v4l_cast_v2l(v2l_cast_v2f(a)))
#define v16f_cast_v2f(a)  v16f_cast_v8f(v8f_cast_v2f(a))
#define v16i_cast_v2f(a)  v16i_cast_v8i(v8i_cast_v2i(v2i_cast_v2f(a)))
#define v1d_cast_v2i(a)  PINTS_REINTERPRET(v1d, v2i, (a))
#define v1f_cast_v2i(a)  v1f_cast_v1i(v1i_cast_v1i(v1i_cast_v2i(a)))
#define v1i_cast_v2i __v1i_cast_v2i
#define v1l_cast_v2i(a)  PINTS_REINTERPRET(v1l, v2i, (a))
#define v2d_cast_v2i(a)  v2d_cast_v1d(v1d_cast_v2d(v2d_cast_v2i(a)))
#define v2f_cast_v2i(a)  PINTS_REINTERPRET(v2f, v2i, (a))
#define v2i_cast_v2i(a)  (a)
#define v2l_cast_v2i(a)  v2l_cast_v1l(v1l_cast_v2l(v2l_cast_v2i(a)))
#define v4d_cast_v2i(a)  v4d_cast_v2d(v2d_cast_v2d(v2d_cast_v2i(a)))
#define v4f_cast_v2i(a)  v4f_cast_v2f(v2f_cast_v2f(v2f_cast_v2i(a)))
#define v4i_cast_v2i __v4i_cast_v2i
#define v4l_cast_v2i(a)  v4l_cast_v2l(v2l_cast_v2l(v2l_cast_v2i(a)))
#define v8d_cast_v2i(a)  v8d_cast_v4d(v4d_cast_v2d(v2d_cast_v2i(a)))
#define v8f_cast_v2i(a)  v8f_cast_v4f(v4f_cast_v2f(v2f_cast_v2i(a)))
#define v8i_cast_v2i(a)  v8i_cast_v4i(v4i_cast_v2i(a))
#define v8l_cast_v2i(a)  v8l_cast_v4l(v4l_cast_v2l(v2l_cast_v2i(a)))
#define v16f_cast_v2i(a)  v16f_cast_v8f(v8f_cast_v2f(v2f_cast_v2i(a)))
#define v16i_cast_v2i(a)  v16i_cast_v8i(v8i_cast_v2i(a))
#define v1d_cast_v2l(a)  v1d_cast_v1l(v1l_cast_v1l(v1l_cast_v2l(a)))
#define v1f_cast_v2l(a)  v1f_cast_v1l(v1l_cast_v1l(v1l_cast_v2l(a)))
#define v1i_cast_v2l(a)  v1i_cast_v1l(v1l_cast_v1l(v1l_cast_v2l(a)))
#define v1l_cast_v2l __v1l_cast_v2l
#define v2d_cast_v2l(a)  PINTS_REINTERPRET(v2d, v2l, (a))
#define v2f_cast_v2l(a)  v2f_cast_v2l(v2l_cast_v1l(v1l_cast_v2l(a)))
#define v2i_cast_v2l(a)  v2i_cast_v2l(v2l_cast_v1l(v1l_cast_v2l(a)))
#define v2l_cast_v2l(a)  (a)
#define v4d_cast_v2l(a)  v4d_cast_v2d(v2d_cast_v2d(v2d_cast_v2l(a)))
#define v4f_cast_v2l(a)  PINTS_REINTERPRET(v4f, v2l, (a))
#define v4i_cast_v2l(a)  PINTS_REINTERPRET(v4i, v2l, (a))
#define v4l_cast_v2l __v4l_cast_v2l
#define v8d_cast_v2l(a)  v8d_cast_v4d(v4d_cast_v2d(v2d_cast_v2l(a)))
#define v8f_cast_v2l(a)  v8f_cast_v4f(v4f_cast_v2f(v2f_cast_v2l(a)))
#define v8i_cast_v2l(a)  v8i_cast_v4i(v4i_cast_v2i(v2i_cast_v2l(a)))
#define v8l_cast_v2l(a)  v8l_cast_v4l(v4l_cast_v2l(a))
#define v16f_cast_v2l(a)  v16f_cast_v8f(v8f_cast_v2f(v2f_cast_v2l(a)))
#define v16i_cast_v2l(a)  v16i_cast_v8i(v8i_cast_v2i(v2i_cast_v2l(a)))
#define v1d_cast_v4d(a)  v1d_cast_v2d(v2d_cast_v4d(a))
#define v1f_cast_v4d(a)  v1f_cast_v1d(v1d_cast_v2d(v2d_cast_v4d(a)))
#define v1i_cast_v4d(a)  v1i_cast_v1d(v1d_cast_v2d(v2d_cast_v4d(a)))
#define v1l_cast_v4d(a)  v1l_cast_v1d(v1d_cast_v2d(v2d_cast_v4d(a)))
#define v2d_cast_v4d __v2d_cast_v4d
#define v2f_cast_v4d(a)  v2f_cast_v2d(v2d_cast_v2d(v2d_cast_v4d(a)))
#define v2i_cast_v4d(a)  v2i_cast_v2d(v2d_cast_v2d(v2d_cast_v4d(a)))
#define v2l_cast_v4d(a)  v2l_cast_v2d(v2d_cast_v2d(v2d_cast_v4d(a)))
#define v4d_cast_v4d(a)  (a)
#define v4f_cast_v4d(a)  v4f_cast_v4d(v4d_cast_v2d(v2d_cast_v4d(a)))
#define v4i_cast_v4d(a)  v4i_cast_v4d(v4d_cast_v2d(v2d_cast_v4d(a)))
#define v4l_cast_v4d(a)  PINTS_REINTERPRET(v4l, v4d, (a))
#define v8d_cast_v4d __v8d_cast_v4d
#define v8f_cast_v4d(a)  PINTS_REINTERPRET(v8f, v4d, (a))
#define v8i_cast_v4d(a)  PINTS_REINTERPRET(v8i, v4d, (a))
#define v8l_cast_v4d(a)  v8l_cast_v4l(v4l_cast_v4l(v4l_cast_v4d(a)))
#define v16f_cast_v4d(a)  v16f_cast_v8f(v8f_cast_v4f(v4f_cast_v4d(a)))
#define v16i_cast_v4d(a)  v16i_cast_v8i(v8i_cast_v4i(v4i_cast_v4d(a)))
#define v1d_cast_v4f(a)  v1d_cast_v1f(v1f_cast_v2f(v2f_cast_v4f(a)))
#define v1f_cast_v4f(a)  v1f_cast_v2f(v2f_cast_v4f(a))
#define v1i_cast_v4f(a)  v1i_cast_v1f(v1f_cast_v2f(v2f_cast_v4f(a)))
#define v1l_cast_v4f(a)  v1l_cast_v1f(v1f_cast_v2f(v2f_cast_v4f(a)))
#define v2d_cast_v4f(a)  PINTS_REINTERPRET(v2d, v4f, (a))
#define v2f_cast_v4f __v2f_cast_v4f
#define v2i_cast_v4f(a)  v2i_cast_v2f(v2f_cast_v2f(v2f_cast_v4f(a)))
#define v2l_cast_v4f(a)  PINTS_REINTERPRET(v2l, v4f, (a))
#define v4d_cast_v4f(a)  v4d_cast_v2d(v2d_cast_v4d(v4d_cast_v4f(a)))
#define v4f_cast_v4f(a)  (a)
#define v4i_cast_v4f(a)  PINTS_REINTERPRET(v4i, v4f, (a))
#define v4l_cast_v4f(a)  v4l_cast_v2l(v2l_cast_v4l(v4l_cast_v4f(a)))
#define v8d_cast_v4f(a)  v8d_cast_v4d(v4d_cast_v4d(v4d_cast_v4f(a)))
#define v8f_cast_v4f __v8f_cast_v4f
#define v8i_cast_v4f(a)  v8i_cast_v4i(v4i_cast_v4i(v4i_cast_v4f(a)))
#define v8l_cast_v4f(a)  v8l_cast_v4l(v4l_cast_v4l(v4l_cast_v4f(a)))
#define v16f_cast_v4f(a)  v16f_cast_v8f(v8f_cast_v4f(a))
#define v16i_cast_v4f(a)  v16i_cast_v8i(v8i_cast_v4i(v4i_cast_v4f(a)))
#define v1d_cast_v4i(a)  v1d_cast_v1i(v1i_cast_v2i(v2i_cast_v4i(a)))
#define v1f_cast_v4i(a)  v1f_cast_v1i(v1i_cast_v2i(v2i_cast_v4i(a)))
#define v1i_cast_v4i(a)  v1i_cast_v2i(v2i_cast_v4i(a))
#define v1l_cast_v4i(a)  v1l_cast_v1i(v1i_cast_v2i(v2i_cast_v4i(a)))
#define v2d_cast_v4i(a)  PINTS_REINTERPRET(v2d, v4i, (a))
#define v2f_cast_v4i(a)  v2f_cast_v2i(v2i_cast_v2i(v2i_cast_v4i(a)))
#define v2i_cast_v4i __v2i_cast_v4i
#define v2l_cast_v4i(a)  PINTS_REINTERPRET(v2l, v4i, (a))
#define v4d_cast_v4i(a)  v4d_cast_v2d(v2d_cast_v4d(v4d_cast_v4i(a)))
#define v4f_cast_v4i(a)  PINTS_REINTERPRET(v4f, v4i, (a))
#define v4i_cast_v4i(a)  (a)
#define v4l_cast_v4i(a)  v4l_cast_v2l(v2l_cast_v4l(v4l_cast_v4i(a)))
#define v8d_cast_v4i(a)  v8d_cast_v4d(v4d_cast_v4d(v4d_cast_v4i(a)))
#define v8f_cast_v4i(a)  v8f_cast_v4f(v4f_cast_v4f(v4f_cast_v4i(a)))
#define v8i_cast_v4i __v8i_cast_v4i
#define v8l_cast_v4i(a)  v8l_cast_v4l(v4l_cast_v4l(v4l_cast_v4i(a)))
#define v16f_cast_v4i(a)  v16f_cast_v8f(v8f_cast_v4f(v4f_cast_v4i(a)))
#define v16i_cast_v4i(a)  v16i_cast_v8i(v8i_cast_v4i(a))
#define v1d_cast_v4l(a)  v1d_cast_v1l(v1l_cast_v2l(v2l_cast_v4l(a)))
#define v1f_cast_v4l(a)  v1f_cast_v1l(v1l_cast_v2l(v2l_cast_v4l(a)))
#define v1i_cast_v4l(a)  v1i_cast_v1l(v1l_cast_v2l(v2l_cast_v4l(a)))
#define v1l_cast_v4l(a)  v1l_cast_v2l(v2l_cast_v4l(a))
#define v2d_cast_v4l(a)  v2d_cast_v2l(v2l_cast_v2l(v2l_cast_v4l(a)))
#define v2f_cast_v4l(a)  v2f_cast_v2l(v2l_cast_v2l(v2l_cast_v4l(a)))
#define v2i_cast_v4l(a)  v2i_cast_v2l(v2l_cast_v2l(v2l_cast_v4l(a)))
#define v2l_cast_v4l __v2l_cast_v4l
#define v4d_cast_v4l(a)  PINTS_REINTERPRET(v4d, v4l, (a))
#define v4f_cast_v4l(a)  v4f_cast_v4l(v4l_cast_v2l(v2l_cast_v4l(a)))
#define v4i_cast_v4l(a)  v4i_cast_v4l(v4l_cast_v2l(v2l_cast_v4l(a)))
#define v4l_cast_v4l(a)  (a)
#define v8d_cast_v4l(a)  v8d_cast_v4d(v4d_cast_v4d(v4d_cast_v4l(a)))
#define v8f_cast_v4l(a)  PINTS_REINTERPRET(v8f, v4l, (a))
#define v8i_cast_v4l(a)  PINTS_REINTERPRET(v8i, v4l, (a))
#define v8l_cast_v4l __v8l_cast_v4l
#define v16f_cast_v4l(a)  v16f_cast_v8f(v8f_cast_v4f(v4f_cast_v4l(a)))
#define v16i_cast_v4l(a)  v16i_cast_v8i(v8i_cast_v4i(v4i_cast_v4l(a)))
#define v1d_cast_v8d(a)  v1d_cast_v4d(v4d_cast_v8d(a))
#define v1f_cast_v8d(a)  v1f_cast_v1d(v1d_cast_v4d(v4d_cast_v8d(a)))
#define v1i_cast_v8d(a)  v1i_cast_v1d(v1d_cast_v4d(v4d_cast_v8d(a)))
#define v1l_cast_v8d(a)  v1l_cast_v1d(v1d_cast_v4d(v4d_cast_v8d(a)))
#define v2d_cast_v8d(a)  v2d_cast_v4d(v4d_cast_v8d(a))
#define v2f_cast_v8d(a)  v2f_cast_v2d(v2d_cast_v4d(v4d_cast_v8d(a)))
#define v2i_cast_v8d(a)  v2i_cast_v2d(v2d_cast_v4d(v4d_cast_v8d(a)))
#define v2l_cast_v8d(a)  v2l_cast_v2d(v2d_cast_v4d(v4d_cast_v8d(a)))
#define v4d_cast_v8d __v4d_cast_v8d
#define v4f_cast_v8d(a)  v4f_cast_v4d(v4d_cast_v4d(v4d_cast_v8d(a)))
#define v4i_cast_v8d(a)  v4i_cast_v4d(v4d_cast_v4d(v4d_cast_v8d(a)))
#define v4l_cast_v8d(a)  v4l_cast_v4d(v4d_cast_v4d(v4d_cast_v8d(a)))
#define v8d_cast_v8d(a)  (a)
#define v8f_cast_v8d(a)  v8f_cast_v8d(v8d_cast_v4d(v4d_cast_v8d(a)))
#define v8i_cast_v8d(a)  v8i_cast_v8d(v8d_cast_v4d(v4d_cast_v8d(a)))
#define v8l_cast_v8d(a)  PINTS_REINTERPRET(v8l, v8d, (a))
#define v16f_cast_v8d(a)  PINTS_REINTERPRET(v16f, v8d, (a))
#define v16i_cast_v8d(a)  PINTS_REINTERPRET(v16i, v8d, (a))
#define v1d_cast_v8f(a)  v1d_cast_v1f(v1f_cast_v4f(v4f_cast_v8f(a)))
#define v1f_cast_v8f(a)  v1f_cast_v4f(v4f_cast_v8f(a))
#define v1i_cast_v8f(a)  v1i_cast_v1f(v1f_cast_v4f(v4f_cast_v8f(a)))
#define v1l_cast_v8f(a)  v1l_cast_v1f(v1f_cast_v4f(v4f_cast_v8f(a)))
#define v2d_cast_v8f(a)  v2d_cast_v2f(v2f_cast_v4f(v4f_cast_v8f(a)))
#define v2f_cast_v8f(a)  v2f_cast_v4f(v4f_cast_v8f(a))
#define v2i_cast_v8f(a)  v2i_cast_v2f(v2f_cast_v4f(v4f_cast_v8f(a)))
#define v2l_cast_v8f(a)  v2l_cast_v2f(v2f_cast_v4f(v4f_cast_v8f(a)))
#define v4d_cast_v8f(a)  PINTS_REINTERPRET(v4d, v8f, (a))
#define v4f_cast_v8f __v4f_cast_v8f
#define v4i_cast_v8f(a)  v4i_cast_v4f(v4f_cast_v4f(v4f_cast_v8f(a)))
#define v4l_cast_v8f(a)  PINTS_REINTERPRET(v4l, v8f, (a))
#define v8d_cast_v8f(a)  v8d_cast_v4d(v4d_cast_v8d(v8d_cast_v8f(a)))
#define v8f_cast_v8f(a)  (a)
#define v8i_cast_v8f(a)  PINTS_REINTERPRET(v8i, v8f, (a))
#define v8l_cast_v8f(a)  v8l_cast_v4l(v4l_cast_v8l(v8l_cast_v8f(a)))
#define v16f_cast_v8f __v16f_cast_v8f
#define v16i_cast_v8f(a)  v16i_cast_v8i(v8i_cast_v8i(v8i_cast_v8f(a)))
#define v1d_cast_v8i(a)  v1d_cast_v1i(v1i_cast_v4i(v4i_cast_v8i(a)))
#define v1f_cast_v8i(a)  v1f_cast_v1i(v1i_cast_v4i(v4i_cast_v8i(a)))
#define v1i_cast_v8i(a)  v1i_cast_v4i(v4i_cast_v8i(a))
#define v1l_cast_v8i(a)  v1l_cast_v1i(v1i_cast_v4i(v4i_cast_v8i(a)))
#define v2d_cast_v8i(a)  v2d_cast_v2i(v2i_cast_v4i(v4i_cast_v8i(a)))
#define v2f_cast_v8i(a)  v2f_cast_v2i(v2i_cast_v4i(v4i_cast_v8i(a)))
#define v2i_cast_v8i(a)  v2i_cast_v4i(v4i_cast_v8i(a))
#define v2l_cast_v8i(a)  v2l_cast_v2i(v2i_cast_v4i(v4i_cast_v8i(a)))
#define v4d_cast_v8i(a)  PINTS_REINTERPRET(v4d, v8i, (a))
#define v4f_cast_v8i(a)  v4f_cast_v4i(v4i_cast_v4i(v4i_cast_v8i(a)))
#define v4i_cast_v8i __v4i_cast_v8i
#define v4l_cast_v8i(a)  PINTS_REINTERPRET(v4l, v8i, (a))
#define v8d_cast_v8i(a)  v8d_cast_v4d(v4d_cast_v8d(v8d_cast_v8i(a)))
#define v8f_cast_v8i(a)  PINTS_REINTERPRET(v8f, v8i, (a))
#define v8i_cast_v8i(a)  (a)
#define v8l_cast_v8i(a)  v8l_cast_v4l(v4l_cast_v8l(v8l_cast_v8i(a)))
#define v16f_cast_v8i(a)  v16f_cast_v8f(v8f_cast_v8f(v8f_cast_v8i(a)))
#define v16i_cast_v8i __v16i_cast_v8i
#define v1d_cast_v8l(a)  v1d_cast_v1l(v1l_cast_v4l(v4l_cast_v8l(a)))
#define v1f_cast_v8l(a)  v1f_cast_v1l(v1l_cast_v4l(v4l_cast_v8l(a)))
#define v1i_cast_v8l(a)  v1i_cast_v1l(v1l_cast_v4l(v4l_cast_v8l(a)))
#define v1l_cast_v8l(a)  v1l_cast_v4l(v4l_cast_v8l(a))
#define v2d_cast_v8l(a)  v2d_cast_v2l(v2l_cast_v4l(v4l_cast_v8l(a)))
#define v2f_cast_v8l(a)  v2f_cast_v2l(v2l_cast_v4l(v4l_cast_v8l(a)))
#define v2i_cast_v8l(a)  v2i_cast_v2l(v2l_cast_v4l(v4l_cast_v8l(a)))
#define v2l_cast_v8l(a)  v2l_cast_v4l(v4l_cast_v8l(a))
#define v4d_cast_v8l(a)  v4d_cast_v4l(v4l_cast_v4l(v4l_cast_v8l(a)))
#define v4f_cast_v8l(a)  v4f_cast_v4l(v4l_cast_v4l(v4l_cast_v8l(a)))
#define v4i_cast_v8l(a)  v4i_cast_v4l(v4l_cast_v4l(v4l_cast_v8l(a)))
#define v4l_cast_v8l __v4l_cast_v8l
#define v8d_cast_v8l(a)  PINTS_REINTERPRET(v8d, v8l, (a))
#define v8f_cast_v8l(a)  v8f_cast_v8l(v8l_cast_v4l(v4l_cast_v8l(a)))
#define v8i_cast_v8l(a)  v8i_cast_v8l(v8l_cast_v4l(v4l_cast_v8l(a)))
#define v8l_cast_v8l(a)  (a)
#define v16f_cast_v8l(a)  PINTS_REINTERPRET(v16f, v8l, (a))
#define v16i_cast_v8l(a)  PINTS_REINTERPRET(v16i, v8l, (a))
#define v1d_cast_v16f(a)  v1d_cast_v1f(v1f_cast_v8f(v8f_cast_v16f(a)))
#define v1f_cast_v16f(a)  v1f_cast_v8f(v8f_cast_v16f(a))
#define v1i_cast_v16f(a)  v1i_cast_v1f(v1f_cast_v8f(v8f_cast_v16f(a)))
#define v1l_cast_v16f(a)  v1l_cast_v1f(v1f_cast_v8f(v8f_cast_v16f(a)))
#define v2d_cast_v16f(a)  v2d_cast_v2f(v2f_cast_v8f(v8f_cast_v16f(a)))
#define v2f_cast_v16f(a)  v2f_cast_v8f(v8f_cast_v16f(a))
#define v2i_cast_v16f(a)  v2i_cast_v2f(v2f_cast_v8f(v8f_cast_v16f(a)))
#define v2l_cast_v16f(a)  v2l_cast_v2f(v2f_cast_v8f(v8f_cast_v16f(a)))
#define v4d_cast_v16f(a)  v4d_cast_v4f(v4f_cast_v8f(v8f_cast_v16f(a)))
#define v4f_cast_v16f(a)  v4f_cast_v8f(v8f_cast_v16f(a))
#define v4i_cast_v16f(a)  v4i_cast_v4f(v4f_cast_v8f(v8f_cast_v16f(a)))
#define v4l_cast_v16f(a)  v4l_cast_v4f(v4f_cast_v8f(v8f_cast_v16f(a)))
#define v8d_cast_v16f(a)  PINTS_REINTERPRET(v8d, v16f, (a))
#define v8f_cast_v16f __v8f_cast_v16f
#define v8i_cast_v16f(a)  v8i_cast_v8f(v8f_cast_v8f(v8f_cast_v16f(a)))
#define v8l_cast_v16f(a)  PINTS_REINTERPRET(v8l, v16f, (a))
#define v16f_cast_v16f(a)  (a)
#define v16i_cast_v16f(a)  PINTS_REINTERPRET(v16i, v16f, (a))
#define v1d_cast_v16i(a)  v1d_cast_v1i(v1i_cast_v8i(v8i_cast_v16i(a)))
#define v1f_cast_v16i(a)  v1f_cast_v1i(v1i_cast_v8i(v8i_cast_v16i(a)))
#define v1i_cast_v16i(a)  v1i_cast_v8i(v8i_cast_v16i(a))
#define v1l_cast_v16i(a)  v1l_cast_v1i(v1i_cast_v8i(v8i_cast_v16i(a)))
#define v2d_cast_v16i(a)  v2d_cast_v2i(v2i_cast_v8i(v8i_cast_v16i(a)))
#define v2f_cast_v16i(a)  v2f_cast_v2i(v2i_cast_v8i(v8i_cast_v16i(a)))
#define v2i_cast_v16i(a)  v2i_cast_v8i(v8i_cast_v16i(a))
#define v2l_cast_v16i(a)  v2l_cast_v2i(v2i_cast_v8i(v8i_cast_v16i(a)))
#define v4d_cast_v16i(a)  v4d_cast_v4i(v4i_cast_v8i(v8i_cast_v16i(a)))
#define v4f_cast_v16i(a)  v4f_cast_v4i(v4i_cast_v8i(v8i_cast_v16i(a)))
#define v4i_cast_v16i(a)  v4i_cast_v8i(v8i_cast_v16i(a))
#define v4l_cast_v16i(a)  v4l_cast_v4i(v4i_cast_v8i(v8i_cast_v16i(a)))
#define v8d_cast_v16i(a)  PINTS_REINTERPRET(v8d, v16i, (a))
#define v8f_cast_v16i(a)  v8f_cast_v8i(v8i_cast_v8i(v8i_cast_v16i(a)))
#define v8i_cast_v16i __v8i_cast_v16i
#define v8l_cast_v16i(a)  PINTS_REINTERPRET(v8l, v16i, (a))
#define v16f_cast_v16i(a)  PINTS_REINTERPRET(v16f, v16i, (a))
#define v16i_cast_v16i(a)  (a)


#define m1d_cast_v1d(a)  (a)
#define m1f_cast_v1f(a)  (a)
#define m1i_cast_v1i(a)  (a)
#define m1l_cast_v1l(a)  (a)
#define m2d_cast_v2d(a)  (a)
#define m2f_cast_v2f(a)  (a)
#define m2i_cast_v2i(a)  (a)
#define m2l_cast_v2l(a)  (a)
#define m4d_cast_v4d(a)  (a)
#define m4f_cast_v4f(a)  (a)
#define m4i_cast_v4i(a)  (a)
#define m4l_cast_v4l(a)  (a)
#define m8d_cast_v8d(a)  (a)
#define m8f_cast_v8f(a)  (a)
#define m8i_cast_v8i(a)  (a)
#define m8l_cast_v8l(a)  (a)
#define m16f_cast_v16f(a)  (a)
#define m16i_cast_v16i(a)  (a)
#define v1d_cast_m1d(a)  (a)
#define v1f_cast_m1f(a)  (a)
#define v1i_cast_m1i(a)  (a)
#define v1l_cast_m1l(a)  (a)
#define v2d_cast_m2d(a)  (a)
#define v2f_cast_m2f(a)  (a)
#define v2i_cast_m2i(a)  (a)
#define v2l_cast_m2l(a)  (a)
#define v4d_cast_m4d(a)  (a)
#define v4f_cast_m4f(a)  (a)
#define v4i_cast_m4i(a)  (a)
#define v4l_cast_m4l(a)  (a)
#define v8d_cast_m8d(a)  (a)
#define v8f_cast_m8f(a)  (a)
#define v8i_cast_m8i(a)  (a)
#define v8l_cast_m8l(a)  (a)
#define v16f_cast_m16f(a)  (a)
#define v16i_cast_m16i(a)  (a)


/* CONVERTS */

#define v1d_cvt_v1d(a)  (a)
#define v1f_cvt_v1d __v1f_cvt_v1d
#define v1i_cvt_v1d __v1i_cvt_v1d
#define v1l_cvt_v1d __v1l_cvt_v1d
#define v2d_cvt_v1d(a)  v2d_cast_v1d(v1d_cvt_v1d(a))
#define v2f_cvt_v1d(a)  v2f_cast_v1f(v1f_cvt_v1d(a))
#define v2i_cvt_v1d(a)  v2i_cast_v1i(v1i_cvt_v1d(a))
#define v2l_cvt_v1d(a)  v2l_cast_v1l(v1l_cvt_v1d(a))
#define v4d_cvt_v1d(a)  v4d_cast_v1d(v1d_cvt_v1d(a))
#define v4f_cvt_v1d(a)  v4f_cast_v1f(v1f_cvt_v1d(a))
#define v4i_cvt_v1d(a)  v4i_cast_v1i(v1i_cvt_v1d(a))
#define v4l_cvt_v1d(a)  v4l_cast_v1l(v1l_cvt_v1d(a))
#define v8d_cvt_v1d(a)  v8d_cast_v1d(v1d_cvt_v1d(a))
#define v8f_cvt_v1d(a)  v8f_cast_v1f(v1f_cvt_v1d(a))
#define v8i_cvt_v1d(a)  v8i_cast_v1i(v1i_cvt_v1d(a))
#define v8l_cvt_v1d(a)  v8l_cast_v1l(v1l_cvt_v1d(a))
#define v16f_cvt_v1d(a)  v16f_cast_v1f(v1f_cvt_v1d(a))
#define v16i_cvt_v1d(a)  v16i_cast_v1i(v1i_cvt_v1d(a))
#define v1d_cvt_v1f __v1d_cvt_v1f
#define v1f_cvt_v1f(a)  (a)
#define v1i_cvt_v1f __v1i_cvt_v1f
#define v1l_cvt_v1f __v1l_cvt_v1f
#define v2d_cvt_v1f(a)  v2d_cast_v1d(v1d_cvt_v1f(a))
#define v2f_cvt_v1f(a)  v2f_cast_v1f(v1f_cvt_v1f(a))
#define v2i_cvt_v1f(a)  v2i_cast_v1i(v1i_cvt_v1f(a))
#define v2l_cvt_v1f(a)  v2l_cast_v1l(v1l_cvt_v1f(a))
#define v4d_cvt_v1f(a)  v4d_cast_v1d(v1d_cvt_v1f(a))
#define v4f_cvt_v1f(a)  v4f_cast_v1f(v1f_cvt_v1f(a))
#define v4i_cvt_v1f(a)  v4i_cast_v1i(v1i_cvt_v1f(a))
#define v4l_cvt_v1f(a)  v4l_cast_v1l(v1l_cvt_v1f(a))
#define v8d_cvt_v1f(a)  v8d_cast_v1d(v1d_cvt_v1f(a))
#define v8f_cvt_v1f(a)  v8f_cast_v1f(v1f_cvt_v1f(a))
#define v8i_cvt_v1f(a)  v8i_cast_v1i(v1i_cvt_v1f(a))
#define v8l_cvt_v1f(a)  v8l_cast_v1l(v1l_cvt_v1f(a))
#define v16f_cvt_v1f(a)  v16f_cast_v1f(v1f_cvt_v1f(a))
#define v16i_cvt_v1f(a)  v16i_cast_v1i(v1i_cvt_v1f(a))
#define v1d_cvt_v1i __v1d_cvt_v1i
#define v1f_cvt_v1i __v1f_cvt_v1i
#define v1i_cvt_v1i(a)  (a)
#define v1l_cvt_v1i __v1l_cvt_v1i
#define v2d_cvt_v1i(a)  v2d_cast_v1d(v1d_cvt_v1i(a))
#define v2f_cvt_v1i(a)  v2f_cast_v1f(v1f_cvt_v1i(a))
#define v2i_cvt_v1i(a)  v2i_cast_v1i(v1i_cvt_v1i(a))
#define v2l_cvt_v1i(a)  v2l_cast_v1l(v1l_cvt_v1i(a))
#define v4d_cvt_v1i(a)  v4d_cast_v1d(v1d_cvt_v1i(a))
#define v4f_cvt_v1i(a)  v4f_cast_v1f(v1f_cvt_v1i(a))
#define v4i_cvt_v1i(a)  v4i_cast_v1i(v1i_cvt_v1i(a))
#define v4l_cvt_v1i(a)  v4l_cast_v1l(v1l_cvt_v1i(a))
#define v8d_cvt_v1i(a)  v8d_cast_v1d(v1d_cvt_v1i(a))
#define v8f_cvt_v1i(a)  v8f_cast_v1f(v1f_cvt_v1i(a))
#define v8i_cvt_v1i(a)  v8i_cast_v1i(v1i_cvt_v1i(a))
#define v8l_cvt_v1i(a)  v8l_cast_v1l(v1l_cvt_v1i(a))
#define v16f_cvt_v1i(a)  v16f_cast_v1f(v1f_cvt_v1i(a))
#define v16i_cvt_v1i(a)  v16i_cast_v1i(v1i_cvt_v1i(a))
#define v1d_cvt_v1l __v1d_cvt_v1l
#define v1f_cvt_v1l __v1f_cvt_v1l
#define v1i_cvt_v1l __v1i_cvt_v1l
#define v1l_cvt_v1l(a)  (a)
#define v2d_cvt_v1l(a)  v2d_cast_v1d(v1d_cvt_v1l(a))
#define v2f_cvt_v1l(a)  v2f_cast_v1f(v1f_cvt_v1l(a))
#define v2i_cvt_v1l(a)  v2i_cast_v1i(v1i_cvt_v1l(a))
#define v2l_cvt_v1l(a)  v2l_cast_v1l(v1l_cvt_v1l(a))
#define v4d_cvt_v1l(a)  v4d_cast_v1d(v1d_cvt_v1l(a))
#define v4f_cvt_v1l(a)  v4f_cast_v1f(v1f_cvt_v1l(a))
#define v4i_cvt_v1l(a)  v4i_cast_v1i(v1i_cvt_v1l(a))
#define v4l_cvt_v1l(a)  v4l_cast_v1l(v1l_cvt_v1l(a))
#define v8d_cvt_v1l(a)  v8d_cast_v1d(v1d_cvt_v1l(a))
#define v8f_cvt_v1l(a)  v8f_cast_v1f(v1f_cvt_v1l(a))
#define v8i_cvt_v1l(a)  v8i_cast_v1i(v1i_cvt_v1l(a))
#define v8l_cvt_v1l(a)  v8l_cast_v1l(v1l_cvt_v1l(a))
#define v16f_cvt_v1l(a)  v16f_cast_v1f(v1f_cvt_v1l(a))
#define v16i_cvt_v1l(a)  v16i_cast_v1i(v1i_cvt_v1l(a))
#define v1d_cvt_v2d(a)  v1d_cvt_v1d(v1d_cast_v2d(a))
#define v1f_cvt_v2d(a)  v1f_cvt_v1d(v1d_cast_v2d(a))
#define v1i_cvt_v2d(a)  v1i_cvt_v1d(v1d_cast_v2d(a))
#define v1l_cvt_v2d(a)  v1l_cvt_v1d(v1d_cast_v2d(a))
#define v2d_cvt_v2d(a)  (a)
#define v2f_cvt_v2d(a)  v2f_merge2_v1f(v1f_cvt_v1d(v1d_get_low_v2d(a)), v1f_cvt_v1d(v1d_get_high_v2d(a)))
#define v2i_cvt_v2d(a)  v2i_merge2_v1i(v1i_cvt_v1d(v1d_get_low_v2d(a)), v1i_cvt_v1d(v1d_get_high_v2d(a)))
#define v2l_cvt_v2d(a)  v2l_merge2_v1l(v1l_cvt_v1d(v1d_get_low_v2d(a)), v1l_cvt_v1d(v1d_get_high_v2d(a)))
#define v4d_cvt_v2d(a)  v4d_cast_v2d(v2d_cvt_v2d(a))
#define v4f_cvt_v2d(a)  v4f_cast_v2f(v2f_cvt_v2d(a))
#define v4i_cvt_v2d(a)  v4i_cast_v2i(v2i_cvt_v2d(a))
#define v4l_cvt_v2d(a)  v4l_cast_v2l(v2l_cvt_v2d(a))
#define v8d_cvt_v2d(a)  v8d_cast_v2d(v2d_cvt_v2d(a))
#define v8f_cvt_v2d(a)  v8f_cast_v2f(v2f_cvt_v2d(a))
#define v8i_cvt_v2d(a)  v8i_cast_v2i(v2i_cvt_v2d(a))
#define v8l_cvt_v2d(a)  v8l_cast_v2l(v2l_cvt_v2d(a))
#define v16f_cvt_v2d(a)  v16f_cast_v2f(v2f_cvt_v2d(a))
#define v16i_cvt_v2d(a)  v16i_cast_v2i(v2i_cvt_v2d(a))
#define v1d_cvt_v2f(a)  v1d_cvt_v1f(v1f_cast_v2f(a))
#define v1f_cvt_v2f(a)  v1f_cvt_v1f(v1f_cast_v2f(a))
#define v1i_cvt_v2f(a)  v1i_cvt_v1f(v1f_cast_v2f(a))
#define v1l_cvt_v2f(a)  v1l_cvt_v1f(v1f_cast_v2f(a))
#define v2d_cvt_v2f(a)  v2d_merge2_v1d(v1d_cvt_v1f(v1f_get_low_v2f(a)), v1d_cvt_v1f(v1f_get_high_v2f(a)))
#define v2f_cvt_v2f(a)  (a)
#define v2i_cvt_v2f(a)  v2i_merge2_v1i(v1i_cvt_v1f(v1f_get_low_v2f(a)), v1i_cvt_v1f(v1f_get_high_v2f(a)))
#define v2l_cvt_v2f(a)  v2l_merge2_v1l(v1l_cvt_v1f(v1f_get_low_v2f(a)), v1l_cvt_v1f(v1f_get_high_v2f(a)))
#define v4d_cvt_v2f(a)  v4d_cast_v2d(v2d_cvt_v2f(a))
#define v4f_cvt_v2f(a)  v4f_cast_v2f(v2f_cvt_v2f(a))
#define v4i_cvt_v2f(a)  v4i_cast_v2i(v2i_cvt_v2f(a))
#define v4l_cvt_v2f(a)  v4l_cast_v2l(v2l_cvt_v2f(a))
#define v8d_cvt_v2f(a)  v8d_cast_v2d(v2d_cvt_v2f(a))
#define v8f_cvt_v2f(a)  v8f_cast_v2f(v2f_cvt_v2f(a))
#define v8i_cvt_v2f(a)  v8i_cast_v2i(v2i_cvt_v2f(a))
#define v8l_cvt_v2f(a)  v8l_cast_v2l(v2l_cvt_v2f(a))
#define v16f_cvt_v2f(a)  v16f_cast_v2f(v2f_cvt_v2f(a))
#define v16i_cvt_v2f(a)  v16i_cast_v2i(v2i_cvt_v2f(a))
#define v1d_cvt_v2i(a)  v1d_cvt_v1i(v1i_cast_v2i(a))
#define v1f_cvt_v2i(a)  v1f_cvt_v1i(v1i_cast_v2i(a))
#define v1i_cvt_v2i(a)  v1i_cvt_v1i(v1i_cast_v2i(a))
#define v1l_cvt_v2i(a)  v1l_cvt_v1i(v1i_cast_v2i(a))
#define v2d_cvt_v2i(a)  v2d_merge2_v1d(v1d_cvt_v1i(v1i_get_low_v2i(a)), v1d_cvt_v1i(v1i_get_high_v2i(a)))
#define v2f_cvt_v2i(a)  v2f_merge2_v1f(v1f_cvt_v1i(v1i_get_low_v2i(a)), v1f_cvt_v1i(v1i_get_high_v2i(a)))
#define v2i_cvt_v2i(a)  (a)
#define v2l_cvt_v2i(a)  v2l_merge2_v1l(v1l_cvt_v1i(v1i_get_low_v2i(a)), v1l_cvt_v1i(v1i_get_high_v2i(a)))
#define v4d_cvt_v2i(a)  v4d_cast_v2d(v2d_cvt_v2i(a))
#define v4f_cvt_v2i(a)  v4f_cast_v2f(v2f_cvt_v2i(a))
#define v4i_cvt_v2i(a)  v4i_cast_v2i(v2i_cvt_v2i(a))
#define v4l_cvt_v2i(a)  v4l_cast_v2l(v2l_cvt_v2i(a))
#define v8d_cvt_v2i(a)  v8d_cast_v2d(v2d_cvt_v2i(a))
#define v8f_cvt_v2i(a)  v8f_cast_v2f(v2f_cvt_v2i(a))
#define v8i_cvt_v2i(a)  v8i_cast_v2i(v2i_cvt_v2i(a))
#define v8l_cvt_v2i(a)  v8l_cast_v2l(v2l_cvt_v2i(a))
#define v16f_cvt_v2i(a)  v16f_cast_v2f(v2f_cvt_v2i(a))
#define v16i_cvt_v2i(a)  v16i_cast_v2i(v2i_cvt_v2i(a))
#define v1d_cvt_v2l(a)  v1d_cvt_v1l(v1l_cast_v2l(a))
#define v1f_cvt_v2l(a)  v1f_cvt_v1l(v1l_cast_v2l(a))
#define v1i_cvt_v2l(a)  v1i_cvt_v1l(v1l_cast_v2l(a))
#define v1l_cvt_v2l(a)  v1l_cvt_v1l(v1l_cast_v2l(a))
#define v2d_cvt_v2l(a)  v2d_merge2_v1d(v1d_cvt_v1l(v1l_get_low_v2l(a)), v1d_cvt_v1l(v1l_get_high_v2l(a)))
#define v2f_cvt_v2l(a)  v2f_merge2_v1f(v1f_cvt_v1l(v1l_get_low_v2l(a)), v1f_cvt_v1l(v1l_get_high_v2l(a)))
#define v2i_cvt_v2l(a)  v2i_merge2_v1i(v1i_cvt_v1l(v1l_get_low_v2l(a)), v1i_cvt_v1l(v1l_get_high_v2l(a)))
#define v2l_cvt_v2l(a)  (a)
#define v4d_cvt_v2l(a)  v4d_cast_v2d(v2d_cvt_v2l(a))
#define v4f_cvt_v2l(a)  v4f_cast_v2f(v2f_cvt_v2l(a))
#define v4i_cvt_v2l(a)  v4i_cast_v2i(v2i_cvt_v2l(a))
#define v4l_cvt_v2l(a)  v4l_cast_v2l(v2l_cvt_v2l(a))
#define v8d_cvt_v2l(a)  v8d_cast_v2d(v2d_cvt_v2l(a))
#define v8f_cvt_v2l(a)  v8f_cast_v2f(v2f_cvt_v2l(a))
#define v8i_cvt_v2l(a)  v8i_cast_v2i(v2i_cvt_v2l(a))
#define v8l_cvt_v2l(a)  v8l_cast_v2l(v2l_cvt_v2l(a))
#define v16f_cvt_v2l(a)  v16f_cast_v2f(v2f_cvt_v2l(a))
#define v16i_cvt_v2l(a)  v16i_cast_v2i(v2i_cvt_v2l(a))
#define v1d_cvt_v4d(a)  v1d_cvt_v1d(v1d_cast_v4d(a))
#define v1f_cvt_v4d(a)  v1f_cvt_v1d(v1d_cast_v4d(a))
#define v1i_cvt_v4d(a)  v1i_cvt_v1d(v1d_cast_v4d(a))
#define v1l_cvt_v4d(a)  v1l_cvt_v1d(v1d_cast_v4d(a))
#define v2d_cvt_v4d(a)  v2d_cvt_v2d(v2d_cast_v4d(a))
#define v2f_cvt_v4d(a)  v2f_cvt_v2d(v2d_cast_v4d(a))
#define v2i_cvt_v4d(a)  v2i_cvt_v2d(v2d_cast_v4d(a))
#define v2l_cvt_v4d(a)  v2l_cvt_v2d(v2d_cast_v4d(a))
#define v4d_cvt_v4d(a)  (a)
#define v4f_cvt_v4d(a)  v4f_merge2_v2f(v2f_cvt_v2d(v2d_get_low_v4d(a)), v2f_cvt_v2d(v2d_get_high_v4d(a)))
#define v4i_cvt_v4d(a)  v4i_merge2_v2i(v2i_cvt_v2d(v2d_get_low_v4d(a)), v2i_cvt_v2d(v2d_get_high_v4d(a)))
#define v4l_cvt_v4d(a)  v4l_merge2_v2l(v2l_cvt_v2d(v2d_get_low_v4d(a)), v2l_cvt_v2d(v2d_get_high_v4d(a)))
#define v8d_cvt_v4d(a)  v8d_cast_v4d(v4d_cvt_v4d(a))
#define v8f_cvt_v4d(a)  v8f_cast_v4f(v4f_cvt_v4d(a))
#define v8i_cvt_v4d(a)  v8i_cast_v4i(v4i_cvt_v4d(a))
#define v8l_cvt_v4d(a)  v8l_cast_v4l(v4l_cvt_v4d(a))
#define v16f_cvt_v4d(a)  v16f_cast_v4f(v4f_cvt_v4d(a))
#define v16i_cvt_v4d(a)  v16i_cast_v4i(v4i_cvt_v4d(a))
#define v1d_cvt_v4f(a)  v1d_cvt_v1f(v1f_cast_v4f(a))
#define v1f_cvt_v4f(a)  v1f_cvt_v1f(v1f_cast_v4f(a))
#define v1i_cvt_v4f(a)  v1i_cvt_v1f(v1f_cast_v4f(a))
#define v1l_cvt_v4f(a)  v1l_cvt_v1f(v1f_cast_v4f(a))
#define v2d_cvt_v4f(a)  v2d_cvt_v2f(v2f_cast_v4f(a))
#define v2f_cvt_v4f(a)  v2f_cvt_v2f(v2f_cast_v4f(a))
#define v2i_cvt_v4f(a)  v2i_cvt_v2f(v2f_cast_v4f(a))
#define v2l_cvt_v4f(a)  v2l_cvt_v2f(v2f_cast_v4f(a))
#define v4d_cvt_v4f(a)  v4d_merge2_v2d(v2d_cvt_v2f(v2f_get_low_v4f(a)), v2d_cvt_v2f(v2f_get_high_v4f(a)))
#define v4f_cvt_v4f(a)  (a)
#define v4i_cvt_v4f(a)  v4i_merge2_v2i(v2i_cvt_v2f(v2f_get_low_v4f(a)), v2i_cvt_v2f(v2f_get_high_v4f(a)))
#define v4l_cvt_v4f(a)  v4l_merge2_v2l(v2l_cvt_v2f(v2f_get_low_v4f(a)), v2l_cvt_v2f(v2f_get_high_v4f(a)))
#define v8d_cvt_v4f(a)  v8d_cast_v4d(v4d_cvt_v4f(a))
#define v8f_cvt_v4f(a)  v8f_cast_v4f(v4f_cvt_v4f(a))
#define v8i_cvt_v4f(a)  v8i_cast_v4i(v4i_cvt_v4f(a))
#define v8l_cvt_v4f(a)  v8l_cast_v4l(v4l_cvt_v4f(a))
#define v16f_cvt_v4f(a)  v16f_cast_v4f(v4f_cvt_v4f(a))
#define v16i_cvt_v4f(a)  v16i_cast_v4i(v4i_cvt_v4f(a))
#define v1d_cvt_v4i(a)  v1d_cvt_v1i(v1i_cast_v4i(a))
#define v1f_cvt_v4i(a)  v1f_cvt_v1i(v1i_cast_v4i(a))
#define v1i_cvt_v4i(a)  v1i_cvt_v1i(v1i_cast_v4i(a))
#define v1l_cvt_v4i(a)  v1l_cvt_v1i(v1i_cast_v4i(a))
#define v2d_cvt_v4i(a)  v2d_cvt_v2i(v2i_cast_v4i(a))
#define v2f_cvt_v4i(a)  v2f_cvt_v2i(v2i_cast_v4i(a))
#define v2i_cvt_v4i(a)  v2i_cvt_v2i(v2i_cast_v4i(a))
#define v2l_cvt_v4i(a)  v2l_cvt_v2i(v2i_cast_v4i(a))
#define v4d_cvt_v4i(a)  v4d_merge2_v2d(v2d_cvt_v2i(v2i_get_low_v4i(a)), v2d_cvt_v2i(v2i_get_high_v4i(a)))
#define v4f_cvt_v4i(a)  v4f_merge2_v2f(v2f_cvt_v2i(v2i_get_low_v4i(a)), v2f_cvt_v2i(v2i_get_high_v4i(a)))
#define v4i_cvt_v4i(a)  (a)
#define v4l_cvt_v4i(a)  v4l_merge2_v2l(v2l_cvt_v2i(v2i_get_low_v4i(a)), v2l_cvt_v2i(v2i_get_high_v4i(a)))
#define v8d_cvt_v4i(a)  v8d_cast_v4d(v4d_cvt_v4i(a))
#define v8f_cvt_v4i(a)  v8f_cast_v4f(v4f_cvt_v4i(a))
#define v8i_cvt_v4i(a)  v8i_cast_v4i(v4i_cvt_v4i(a))
#define v8l_cvt_v4i(a)  v8l_cast_v4l(v4l_cvt_v4i(a))
#define v16f_cvt_v4i(a)  v16f_cast_v4f(v4f_cvt_v4i(a))
#define v16i_cvt_v4i(a)  v16i_cast_v4i(v4i_cvt_v4i(a))
#define v1d_cvt_v4l(a)  v1d_cvt_v1l(v1l_cast_v4l(a))
#define v1f_cvt_v4l(a)  v1f_cvt_v1l(v1l_cast_v4l(a))
#define v1i_cvt_v4l(a)  v1i_cvt_v1l(v1l_cast_v4l(a))
#define v1l_cvt_v4l(a)  v1l_cvt_v1l(v1l_cast_v4l(a))
#define v2d_cvt_v4l(a)  v2d_cvt_v2l(v2l_cast_v4l(a))
#define v2f_cvt_v4l(a)  v2f_cvt_v2l(v2l_cast_v4l(a))
#define v2i_cvt_v4l(a)  v2i_cvt_v2l(v2l_cast_v4l(a))
#define v2l_cvt_v4l(a)  v2l_cvt_v2l(v2l_cast_v4l(a))
#define v4d_cvt_v4l(a)  v4d_merge2_v2d(v2d_cvt_v2l(v2l_get_low_v4l(a)), v2d_cvt_v2l(v2l_get_high_v4l(a)))
#define v4f_cvt_v4l(a)  v4f_merge2_v2f(v2f_cvt_v2l(v2l_get_low_v4l(a)), v2f_cvt_v2l(v2l_get_high_v4l(a)))
#define v4i_cvt_v4l(a)  v4i_merge2_v2i(v2i_cvt_v2l(v2l_get_low_v4l(a)), v2i_cvt_v2l(v2l_get_high_v4l(a)))
#define v4l_cvt_v4l(a)  (a)
#define v8d_cvt_v4l(a)  v8d_cast_v4d(v4d_cvt_v4l(a))
#define v8f_cvt_v4l(a)  v8f_cast_v4f(v4f_cvt_v4l(a))
#define v8i_cvt_v4l(a)  v8i_cast_v4i(v4i_cvt_v4l(a))
#define v8l_cvt_v4l(a)  v8l_cast_v4l(v4l_cvt_v4l(a))
#define v16f_cvt_v4l(a)  v16f_cast_v4f(v4f_cvt_v4l(a))
#define v16i_cvt_v4l(a)  v16i_cast_v4i(v4i_cvt_v4l(a))
#define v1d_cvt_v8d(a)  v1d_cvt_v1d(v1d_cast_v8d(a))
#define v1f_cvt_v8d(a)  v1f_cvt_v1d(v1d_cast_v8d(a))
#define v1i_cvt_v8d(a)  v1i_cvt_v1d(v1d_cast_v8d(a))
#define v1l_cvt_v8d(a)  v1l_cvt_v1d(v1d_cast_v8d(a))
#define v2d_cvt_v8d(a)  v2d_cvt_v2d(v2d_cast_v8d(a))
#define v2f_cvt_v8d(a)  v2f_cvt_v2d(v2d_cast_v8d(a))
#define v2i_cvt_v8d(a)  v2i_cvt_v2d(v2d_cast_v8d(a))
#define v2l_cvt_v8d(a)  v2l_cvt_v2d(v2d_cast_v8d(a))
#define v4d_cvt_v8d(a)  v4d_cvt_v4d(v4d_cast_v8d(a))
#define v4f_cvt_v8d(a)  v4f_cvt_v4d(v4d_cast_v8d(a))
#define v4i_cvt_v8d(a)  v4i_cvt_v4d(v4d_cast_v8d(a))
#define v4l_cvt_v8d(a)  v4l_cvt_v4d(v4d_cast_v8d(a))
#define v8d_cvt_v8d(a)  (a)
#define v8f_cvt_v8d(a)  v8f_merge2_v4f(v4f_cvt_v4d(v4d_get_low_v8d(a)), v4f_cvt_v4d(v4d_get_high_v8d(a)))
#define v8i_cvt_v8d(a)  v8i_merge2_v4i(v4i_cvt_v4d(v4d_get_low_v8d(a)), v4i_cvt_v4d(v4d_get_high_v8d(a)))
#define v8l_cvt_v8d(a)  v8l_merge2_v4l(v4l_cvt_v4d(v4d_get_low_v8d(a)), v4l_cvt_v4d(v4d_get_high_v8d(a)))
#define v16f_cvt_v8d(a)  v16f_cast_v8f(v8f_cvt_v8d(a))
#define v16i_cvt_v8d(a)  v16i_cast_v8i(v8i_cvt_v8d(a))
#define v1d_cvt_v8f(a)  v1d_cvt_v1f(v1f_cast_v8f(a))
#define v1f_cvt_v8f(a)  v1f_cvt_v1f(v1f_cast_v8f(a))
#define v1i_cvt_v8f(a)  v1i_cvt_v1f(v1f_cast_v8f(a))
#define v1l_cvt_v8f(a)  v1l_cvt_v1f(v1f_cast_v8f(a))
#define v2d_cvt_v8f(a)  v2d_cvt_v2f(v2f_cast_v8f(a))
#define v2f_cvt_v8f(a)  v2f_cvt_v2f(v2f_cast_v8f(a))
#define v2i_cvt_v8f(a)  v2i_cvt_v2f(v2f_cast_v8f(a))
#define v2l_cvt_v8f(a)  v2l_cvt_v2f(v2f_cast_v8f(a))
#define v4d_cvt_v8f(a)  v4d_cvt_v4f(v4f_cast_v8f(a))
#define v4f_cvt_v8f(a)  v4f_cvt_v4f(v4f_cast_v8f(a))
#define v4i_cvt_v8f(a)  v4i_cvt_v4f(v4f_cast_v8f(a))
#define v4l_cvt_v8f(a)  v4l_cvt_v4f(v4f_cast_v8f(a))
#define v8d_cvt_v8f(a)  v8d_merge2_v4d(v4d_cvt_v4f(v4f_get_low_v8f(a)), v4d_cvt_v4f(v4f_get_high_v8f(a)))
#define v8f_cvt_v8f(a)  (a)
#define v8i_cvt_v8f(a)  v8i_merge2_v4i(v4i_cvt_v4f(v4f_get_low_v8f(a)), v4i_cvt_v4f(v4f_get_high_v8f(a)))
#define v8l_cvt_v8f(a)  v8l_merge2_v4l(v4l_cvt_v4f(v4f_get_low_v8f(a)), v4l_cvt_v4f(v4f_get_high_v8f(a)))
#define v16f_cvt_v8f(a)  v16f_cast_v8f(v8f_cvt_v8f(a))
#define v16i_cvt_v8f(a)  v16i_cast_v8i(v8i_cvt_v8f(a))
#define v1d_cvt_v8i(a)  v1d_cvt_v1i(v1i_cast_v8i(a))
#define v1f_cvt_v8i(a)  v1f_cvt_v1i(v1i_cast_v8i(a))
#define v1i_cvt_v8i(a)  v1i_cvt_v1i(v1i_cast_v8i(a))
#define v1l_cvt_v8i(a)  v1l_cvt_v1i(v1i_cast_v8i(a))
#define v2d_cvt_v8i(a)  v2d_cvt_v2i(v2i_cast_v8i(a))
#define v2f_cvt_v8i(a)  v2f_cvt_v2i(v2i_cast_v8i(a))
#define v2i_cvt_v8i(a)  v2i_cvt_v2i(v2i_cast_v8i(a))
#define v2l_cvt_v8i(a)  v2l_cvt_v2i(v2i_cast_v8i(a))
#define v4d_cvt_v8i(a)  v4d_cvt_v4i(v4i_cast_v8i(a))
#define v4f_cvt_v8i(a)  v4f_cvt_v4i(v4i_cast_v8i(a))
#define v4i_cvt_v8i(a)  v4i_cvt_v4i(v4i_cast_v8i(a))
#define v4l_cvt_v8i(a)  v4l_cvt_v4i(v4i_cast_v8i(a))
#define v8d_cvt_v8i(a)  v8d_merge2_v4d(v4d_cvt_v4i(v4i_get_low_v8i(a)), v4d_cvt_v4i(v4i_get_high_v8i(a)))
#define v8f_cvt_v8i(a)  v8f_merge2_v4f(v4f_cvt_v4i(v4i_get_low_v8i(a)), v4f_cvt_v4i(v4i_get_high_v8i(a)))
#define v8i_cvt_v8i(a)  (a)
#define v8l_cvt_v8i(a)  v8l_merge2_v4l(v4l_cvt_v4i(v4i_get_low_v8i(a)), v4l_cvt_v4i(v4i_get_high_v8i(a)))
#define v16f_cvt_v8i(a)  v16f_cast_v8f(v8f_cvt_v8i(a))
#define v16i_cvt_v8i(a)  v16i_cast_v8i(v8i_cvt_v8i(a))
#define v1d_cvt_v8l(a)  v1d_cvt_v1l(v1l_cast_v8l(a))
#define v1f_cvt_v8l(a)  v1f_cvt_v1l(v1l_cast_v8l(a))
#define v1i_cvt_v8l(a)  v1i_cvt_v1l(v1l_cast_v8l(a))
#define v1l_cvt_v8l(a)  v1l_cvt_v1l(v1l_cast_v8l(a))
#define v2d_cvt_v8l(a)  v2d_cvt_v2l(v2l_cast_v8l(a))
#define v2f_cvt_v8l(a)  v2f_cvt_v2l(v2l_cast_v8l(a))
#define v2i_cvt_v8l(a)  v2i_cvt_v2l(v2l_cast_v8l(a))
#define v2l_cvt_v8l(a)  v2l_cvt_v2l(v2l_cast_v8l(a))
#define v4d_cvt_v8l(a)  v4d_cvt_v4l(v4l_cast_v8l(a))
#define v4f_cvt_v8l(a)  v4f_cvt_v4l(v4l_cast_v8l(a))
#define v4i_cvt_v8l(a)  v4i_cvt_v4l(v4l_cast_v8l(a))
#define v4l_cvt_v8l(a)  v4l_cvt_v4l(v4l_cast_v8l(a))
#define v8d_cvt_v8l(a)  v8d_merge2_v4d(v4d_cvt_v4l(v4l_get_low_v8l(a)), v4d_cvt_v4l(v4l_get_high_v8l(a)))
#define v8f_cvt_v8l(a)  v8f_merge2_v4f(v4f_cvt_v4l(v4l_get_low_v8l(a)), v4f_cvt_v4l(v4l_get_high_v8l(a)))
#define v8i_cvt_v8l(a)  v8i_merge2_v4i(v4i_cvt_v4l(v4l_get_low_v8l(a)), v4i_cvt_v4l(v4l_get_high_v8l(a)))
#define v8l_cvt_v8l(a)  (a)
#define v16f_cvt_v8l(a)  v16f_cast_v8f(v8f_cvt_v8l(a))
#define v16i_cvt_v8l(a)  v16i_cast_v8i(v8i_cvt_v8l(a))
#define v1d_cvt_v16f(a)  v1d_cvt_v1f(v1f_cast_v16f(a))
#define v1f_cvt_v16f(a)  v1f_cvt_v1f(v1f_cast_v16f(a))
#define v1i_cvt_v16f(a)  v1i_cvt_v1f(v1f_cast_v16f(a))
#define v1l_cvt_v16f(a)  v1l_cvt_v1f(v1f_cast_v16f(a))
#define v2d_cvt_v16f(a)  v2d_cvt_v2f(v2f_cast_v16f(a))
#define v2f_cvt_v16f(a)  v2f_cvt_v2f(v2f_cast_v16f(a))
#define v2i_cvt_v16f(a)  v2i_cvt_v2f(v2f_cast_v16f(a))
#define v2l_cvt_v16f(a)  v2l_cvt_v2f(v2f_cast_v16f(a))
#define v4d_cvt_v16f(a)  v4d_cvt_v4f(v4f_cast_v16f(a))
#define v4f_cvt_v16f(a)  v4f_cvt_v4f(v4f_cast_v16f(a))
#define v4i_cvt_v16f(a)  v4i_cvt_v4f(v4f_cast_v16f(a))
#define v4l_cvt_v16f(a)  v4l_cvt_v4f(v4f_cast_v16f(a))
#define v8d_cvt_v16f(a)  v8d_cvt_v8f(v8f_cast_v16f(a))
#define v8f_cvt_v16f(a)  v8f_cvt_v8f(v8f_cast_v16f(a))
#define v8i_cvt_v16f(a)  v8i_cvt_v8f(v8f_cast_v16f(a))
#define v8l_cvt_v16f(a)  v8l_cvt_v8f(v8f_cast_v16f(a))
#define v16f_cvt_v16f(a)  (a)
#define v16i_cvt_v16f(a)  v16i_merge2_v8i(v8i_cvt_v8f(v8f_get_low_v16f(a)), v8i_cvt_v8f(v8f_get_high_v16f(a)))
#define v1d_cvt_v16i(a)  v1d_cvt_v1i(v1i_cast_v16i(a))
#define v1f_cvt_v16i(a)  v1f_cvt_v1i(v1i_cast_v16i(a))
#define v1i_cvt_v16i(a)  v1i_cvt_v1i(v1i_cast_v16i(a))
#define v1l_cvt_v16i(a)  v1l_cvt_v1i(v1i_cast_v16i(a))
#define v2d_cvt_v16i(a)  v2d_cvt_v2i(v2i_cast_v16i(a))
#define v2f_cvt_v16i(a)  v2f_cvt_v2i(v2i_cast_v16i(a))
#define v2i_cvt_v16i(a)  v2i_cvt_v2i(v2i_cast_v16i(a))
#define v2l_cvt_v16i(a)  v2l_cvt_v2i(v2i_cast_v16i(a))
#define v4d_cvt_v16i(a)  v4d_cvt_v4i(v4i_cast_v16i(a))
#define v4f_cvt_v16i(a)  v4f_cvt_v4i(v4i_cast_v16i(a))
#define v4i_cvt_v16i(a)  v4i_cvt_v4i(v4i_cast_v16i(a))
#define v4l_cvt_v16i(a)  v4l_cvt_v4i(v4i_cast_v16i(a))
#define v8d_cvt_v16i(a)  v8d_cvt_v8i(v8i_cast_v16i(a))
#define v8f_cvt_v16i(a)  v8f_cvt_v8i(v8i_cast_v16i(a))
#define v8i_cvt_v16i(a)  v8i_cvt_v8i(v8i_cast_v16i(a))
#define v8l_cvt_v16i(a)  v8l_cvt_v8i(v8i_cast_v16i(a))
#define v16f_cvt_v16i(a)  v16f_merge2_v8f(v8f_cvt_v8i(v8i_get_low_v16i(a)), v8f_cvt_v8i(v8i_get_high_v16i(a)))
#define v16i_cvt_v16i(a)  (a)


#define sd_cvt_v1d __sd_cvt_v1d
#define sf_cvt_v1d(a)  sf_cvt_v1f(v1f_cvt_v1d(a))
#define si_cvt_v1d(a)  si_cvt_v1i(v1i_cvt_v1d(a))
#define sl_cvt_v1d(a)  sl_cvt_v1l(v1l_cvt_v1d(a))
#define sd_cvt_v1f(a)  sd_cvt_v1d(v1d_cvt_v1f(a))
#define sf_cvt_v1f __sf_cvt_v1f
#define si_cvt_v1f(a)  si_cvt_v1i(v1i_cvt_v1f(a))
#define sl_cvt_v1f(a)  sl_cvt_v1l(v1l_cvt_v1f(a))
#define sd_cvt_v1i(a)  sd_cvt_v1d(v1d_cvt_v1i(a))
#define sf_cvt_v1i(a)  sf_cvt_v1f(v1f_cvt_v1i(a))
#define si_cvt_v1i __si_cvt_v1i
#define sl_cvt_v1i(a)  sl_cvt_v1l(v1l_cvt_v1i(a))
#define sd_cvt_v1l(a)  sd_cvt_v1d(v1d_cvt_v1l(a))
#define sf_cvt_v1l(a)  sf_cvt_v1f(v1f_cvt_v1l(a))
#define si_cvt_v1l(a)  si_cvt_v1i(v1i_cvt_v1l(a))
#define sl_cvt_v1l __sl_cvt_v1l
#define sd_cvt_v2d(a)  sd_cvt_v1d(v1d_cvt_v2d(a))
#define sf_cvt_v2d(a)  sf_cvt_v1f(v1f_cvt_v2d(a))
#define si_cvt_v2d(a)  si_cvt_v1i(v1i_cvt_v2d(a))
#define sl_cvt_v2d(a)  sl_cvt_v1l(v1l_cvt_v2d(a))
#define sd_cvt_v2f(a)  sd_cvt_v1d(v1d_cvt_v2f(a))
#define sf_cvt_v2f(a)  sf_cvt_v1f(v1f_cvt_v2f(a))
#define si_cvt_v2f(a)  si_cvt_v1i(v1i_cvt_v2f(a))
#define sl_cvt_v2f(a)  sl_cvt_v1l(v1l_cvt_v2f(a))
#define sd_cvt_v2i(a)  sd_cvt_v1d(v1d_cvt_v2i(a))
#define sf_cvt_v2i(a)  sf_cvt_v1f(v1f_cvt_v2i(a))
#define si_cvt_v2i(a)  si_cvt_v1i(v1i_cvt_v2i(a))
#define sl_cvt_v2i(a)  sl_cvt_v1l(v1l_cvt_v2i(a))
#define sd_cvt_v2l(a)  sd_cvt_v1d(v1d_cvt_v2l(a))
#define sf_cvt_v2l(a)  sf_cvt_v1f(v1f_cvt_v2l(a))
#define si_cvt_v2l(a)  si_cvt_v1i(v1i_cvt_v2l(a))
#define sl_cvt_v2l(a)  sl_cvt_v1l(v1l_cvt_v2l(a))
#define sd_cvt_v4d(a)  sd_cvt_v1d(v1d_cvt_v4d(a))
#define sf_cvt_v4d(a)  sf_cvt_v1f(v1f_cvt_v4d(a))
#define si_cvt_v4d(a)  si_cvt_v1i(v1i_cvt_v4d(a))
#define sl_cvt_v4d(a)  sl_cvt_v1l(v1l_cvt_v4d(a))
#define sd_cvt_v4f(a)  sd_cvt_v1d(v1d_cvt_v4f(a))
#define sf_cvt_v4f(a)  sf_cvt_v1f(v1f_cvt_v4f(a))
#define si_cvt_v4f(a)  si_cvt_v1i(v1i_cvt_v4f(a))
#define sl_cvt_v4f(a)  sl_cvt_v1l(v1l_cvt_v4f(a))
#define sd_cvt_v4i(a)  sd_cvt_v1d(v1d_cvt_v4i(a))
#define sf_cvt_v4i(a)  sf_cvt_v1f(v1f_cvt_v4i(a))
#define si_cvt_v4i(a)  si_cvt_v1i(v1i_cvt_v4i(a))
#define sl_cvt_v4i(a)  sl_cvt_v1l(v1l_cvt_v4i(a))
#define sd_cvt_v4l(a)  sd_cvt_v1d(v1d_cvt_v4l(a))
#define sf_cvt_v4l(a)  sf_cvt_v1f(v1f_cvt_v4l(a))
#define si_cvt_v4l(a)  si_cvt_v1i(v1i_cvt_v4l(a))
#define sl_cvt_v4l(a)  sl_cvt_v1l(v1l_cvt_v4l(a))
#define sd_cvt_v8d(a)  sd_cvt_v1d(v1d_cvt_v8d(a))
#define sf_cvt_v8d(a)  sf_cvt_v1f(v1f_cvt_v8d(a))
#define si_cvt_v8d(a)  si_cvt_v1i(v1i_cvt_v8d(a))
#define sl_cvt_v8d(a)  sl_cvt_v1l(v1l_cvt_v8d(a))
#define sd_cvt_v8f(a)  sd_cvt_v1d(v1d_cvt_v8f(a))
#define sf_cvt_v8f(a)  sf_cvt_v1f(v1f_cvt_v8f(a))
#define si_cvt_v8f(a)  si_cvt_v1i(v1i_cvt_v8f(a))
#define sl_cvt_v8f(a)  sl_cvt_v1l(v1l_cvt_v8f(a))
#define sd_cvt_v8i(a)  sd_cvt_v1d(v1d_cvt_v8i(a))
#define sf_cvt_v8i(a)  sf_cvt_v1f(v1f_cvt_v8i(a))
#define si_cvt_v8i(a)  si_cvt_v1i(v1i_cvt_v8i(a))
#define sl_cvt_v8i(a)  sl_cvt_v1l(v1l_cvt_v8i(a))
#define sd_cvt_v8l(a)  sd_cvt_v1d(v1d_cvt_v8l(a))
#define sf_cvt_v8l(a)  sf_cvt_v1f(v1f_cvt_v8l(a))
#define si_cvt_v8l(a)  si_cvt_v1i(v1i_cvt_v8l(a))
#define sl_cvt_v8l(a)  sl_cvt_v1l(v1l_cvt_v8l(a))
#define sd_cvt_v16f(a)  sd_cvt_v1d(v1d_cvt_v16f(a))
#define sf_cvt_v16f(a)  sf_cvt_v1f(v1f_cvt_v16f(a))
#define si_cvt_v16f(a)  si_cvt_v1i(v1i_cvt_v16f(a))
#define sl_cvt_v16f(a)  sl_cvt_v1l(v1l_cvt_v16f(a))
#define sd_cvt_v16i(a)  sd_cvt_v1d(v1d_cvt_v16i(a))
#define sf_cvt_v16i(a)  sf_cvt_v1f(v1f_cvt_v16i(a))
#define si_cvt_v16i(a)  si_cvt_v1i(v1i_cvt_v16i(a))
#define sl_cvt_v16i(a)  sl_cvt_v1l(v1l_cvt_v16i(a))


#define m1d_cvt_v1d(a)  v1d_lt(a, v1d_zero())
#define m1f_cvt_v1f(a)  v1f_lt(a, v1f_zero())
#define m1i_cvt_v1i(a)  v1i_lt(a, v1i_zero())
#define m1l_cvt_v1l(a)  v1l_lt(a, v1l_zero())
#define m2d_cvt_v2d(a)  v2d_lt(a, v2d_zero())
#define m2f_cvt_v2f(a)  v2f_lt(a, v2f_zero())
#define m2i_cvt_v2i(a)  v2i_lt(a, v2i_zero())
#define m2l_cvt_v2l(a)  v2l_lt(a, v2l_zero())
#define m4d_cvt_v4d(a)  v4d_lt(a, v4d_zero())
#define m4f_cvt_v4f(a)  v4f_lt(a, v4f_zero())
#define m4i_cvt_v4i(a)  v4i_lt(a, v4i_zero())
#define m4l_cvt_v4l(a)  v4l_lt(a, v4l_zero())
#define m8d_cvt_v8d(a)  v8d_lt(a, v8d_zero())
#define m8f_cvt_v8f(a)  v8f_lt(a, v8f_zero())
#define m8i_cvt_v8i(a)  v8i_lt(a, v8i_zero())
#define m8l_cvt_v8l(a)  v8l_lt(a, v8l_zero())
#define m16f_cvt_v16f(a)  v16f_lt(a, v16f_zero())
#define m16i_cvt_v16i(a)  v16i_lt(a, v16i_zero())
#define v1d_cvt_m1d(a)  v1d_maskz_mov(a, v1d_ones())
#define v1f_cvt_m1f(a)  v1f_maskz_mov(a, v1f_ones())
#define v1i_cvt_m1i(a)  v1i_maskz_mov(a, v1i_ones())
#define v1l_cvt_m1l(a)  v1l_maskz_mov(a, v1l_ones())
#define v2d_cvt_m2d(a)  v2d_maskz_mov(a, v2d_ones())
#define v2f_cvt_m2f(a)  v2f_maskz_mov(a, v2f_ones())
#define v2i_cvt_m2i(a)  v2i_maskz_mov(a, v2i_ones())
#define v2l_cvt_m2l(a)  v2l_maskz_mov(a, v2l_ones())
#define v4d_cvt_m4d(a)  v4d_maskz_mov(a, v4d_ones())
#define v4f_cvt_m4f(a)  v4f_maskz_mov(a, v4f_ones())
#define v4i_cvt_m4i(a)  v4i_maskz_mov(a, v4i_ones())
#define v4l_cvt_m4l(a)  v4l_maskz_mov(a, v4l_ones())
#define v8d_cvt_m8d(a)  v8d_maskz_mov(a, v8d_ones())
#define v8f_cvt_m8f(a)  v8f_maskz_mov(a, v8f_ones())
#define v8i_cvt_m8i(a)  v8i_maskz_mov(a, v8i_ones())
#define v8l_cvt_m8l(a)  v8l_maskz_mov(a, v8l_ones())
#define v16f_cvt_m16f(a)  v16f_maskz_mov(a, v16f_ones())
#define v16i_cvt_m16i(a)  v16i_maskz_mov(a, v16i_ones())

#define m1d_cvt_m1d(a)  m1d_cast_v1d(v1d_cast_v1l(v1l_cvt_v1l(v1l_cast_v1d(v1d_cast_m1d(a)))))
#define m1f_cvt_m1d(a)  m1f_cast_v1f(v1f_cast_v1i(v1i_cvt_v1l(v1l_cast_v1d(v1d_cast_m1d(a)))))
#define m1i_cvt_m1d(a)  m1i_cast_v1i(v1i_cast_v1i(v1i_cvt_v1l(v1l_cast_v1d(v1d_cast_m1d(a)))))
#define m1l_cvt_m1d(a)  m1l_cast_v1l(v1l_cast_v1l(v1l_cvt_v1l(v1l_cast_v1d(v1d_cast_m1d(a)))))
#define m2d_cvt_m2d(a)  m2d_cast_v2d(v2d_cast_v2l(v2l_cvt_v2l(v2l_cast_v2d(v2d_cast_m2d(a)))))
#define m2f_cvt_m2d(a)  m2f_cast_v2f(v2f_cast_v2i(v2i_cvt_v2l(v2l_cast_v2d(v2d_cast_m2d(a)))))
#define m2i_cvt_m2d(a)  m2i_cast_v2i(v2i_cast_v2i(v2i_cvt_v2l(v2l_cast_v2d(v2d_cast_m2d(a)))))
#define m2l_cvt_m2d(a)  m2l_cast_v2l(v2l_cast_v2l(v2l_cvt_v2l(v2l_cast_v2d(v2d_cast_m2d(a)))))
#define m4d_cvt_m4d(a)  m4d_cast_v4d(v4d_cast_v4l(v4l_cvt_v4l(v4l_cast_v4d(v4d_cast_m4d(a)))))
#define m4f_cvt_m4d(a)  m4f_cast_v4f(v4f_cast_v4i(v4i_cvt_v4l(v4l_cast_v4d(v4d_cast_m4d(a)))))
#define m4i_cvt_m4d(a)  m4i_cast_v4i(v4i_cast_v4i(v4i_cvt_v4l(v4l_cast_v4d(v4d_cast_m4d(a)))))
#define m4l_cvt_m4d(a)  m4l_cast_v4l(v4l_cast_v4l(v4l_cvt_v4l(v4l_cast_v4d(v4d_cast_m4d(a)))))
#define m8d_cvt_m8d(a)  m8d_cast_v8d(v8d_cast_v8l(v8l_cvt_v8l(v8l_cast_v8d(v8d_cast_m8d(a)))))
#define m8f_cvt_m8d(a)  m8f_cast_v8f(v8f_cast_v8i(v8i_cvt_v8l(v8l_cast_v8d(v8d_cast_m8d(a)))))
#define m8i_cvt_m8d(a)  m8i_cast_v8i(v8i_cast_v8i(v8i_cvt_v8l(v8l_cast_v8d(v8d_cast_m8d(a)))))
#define m8l_cvt_m8d(a)  m8l_cast_v8l(v8l_cast_v8l(v8l_cvt_v8l(v8l_cast_v8d(v8d_cast_m8d(a)))))
#define m1d_cvt_m1f(a)  m1d_cast_v1d(v1d_cast_v1l(v1l_cvt_v1i(v1i_cast_v1f(v1f_cast_m1f(a)))))
#define m1f_cvt_m1f(a)  m1f_cast_v1f(v1f_cast_v1i(v1i_cvt_v1i(v1i_cast_v1f(v1f_cast_m1f(a)))))
#define m1i_cvt_m1f(a)  m1i_cast_v1i(v1i_cast_v1i(v1i_cvt_v1i(v1i_cast_v1f(v1f_cast_m1f(a)))))
#define m1l_cvt_m1f(a)  m1l_cast_v1l(v1l_cast_v1l(v1l_cvt_v1i(v1i_cast_v1f(v1f_cast_m1f(a)))))
#define m2d_cvt_m2f(a)  m2d_cast_v2d(v2d_cast_v2l(v2l_cvt_v2i(v2i_cast_v2f(v2f_cast_m2f(a)))))
#define m2f_cvt_m2f(a)  m2f_cast_v2f(v2f_cast_v2i(v2i_cvt_v2i(v2i_cast_v2f(v2f_cast_m2f(a)))))
#define m2i_cvt_m2f(a)  m2i_cast_v2i(v2i_cast_v2i(v2i_cvt_v2i(v2i_cast_v2f(v2f_cast_m2f(a)))))
#define m2l_cvt_m2f(a)  m2l_cast_v2l(v2l_cast_v2l(v2l_cvt_v2i(v2i_cast_v2f(v2f_cast_m2f(a)))))
#define m4d_cvt_m4f(a)  m4d_cast_v4d(v4d_cast_v4l(v4l_cvt_v4i(v4i_cast_v4f(v4f_cast_m4f(a)))))
#define m4f_cvt_m4f(a)  m4f_cast_v4f(v4f_cast_v4i(v4i_cvt_v4i(v4i_cast_v4f(v4f_cast_m4f(a)))))
#define m4i_cvt_m4f(a)  m4i_cast_v4i(v4i_cast_v4i(v4i_cvt_v4i(v4i_cast_v4f(v4f_cast_m4f(a)))))
#define m4l_cvt_m4f(a)  m4l_cast_v4l(v4l_cast_v4l(v4l_cvt_v4i(v4i_cast_v4f(v4f_cast_m4f(a)))))
#define m8d_cvt_m8f(a)  m8d_cast_v8d(v8d_cast_v8l(v8l_cvt_v8i(v8i_cast_v8f(v8f_cast_m8f(a)))))
#define m8f_cvt_m8f(a)  m8f_cast_v8f(v8f_cast_v8i(v8i_cvt_v8i(v8i_cast_v8f(v8f_cast_m8f(a)))))
#define m8i_cvt_m8f(a)  m8i_cast_v8i(v8i_cast_v8i(v8i_cvt_v8i(v8i_cast_v8f(v8f_cast_m8f(a)))))
#define m8l_cvt_m8f(a)  m8l_cast_v8l(v8l_cast_v8l(v8l_cvt_v8i(v8i_cast_v8f(v8f_cast_m8f(a)))))
#define m16f_cvt_m16f(a)  m16f_cast_v16f(v16f_cast_v16i(v16i_cvt_v16i(v16i_cast_v16f(v16f_cast_m16f(a)))))
#define m16i_cvt_m16f(a)  m16i_cast_v16i(v16i_cast_v16i(v16i_cvt_v16i(v16i_cast_v16f(v16f_cast_m16f(a)))))
#define m1d_cvt_m1i(a)  m1d_cast_v1d(v1d_cast_v1l(v1l_cvt_v1i(v1i_cast_v1i(v1i_cast_m1i(a)))))
#define m1f_cvt_m1i(a)  m1f_cast_v1f(v1f_cast_v1i(v1i_cvt_v1i(v1i_cast_v1i(v1i_cast_m1i(a)))))
#define m1i_cvt_m1i(a)  m1i_cast_v1i(v1i_cast_v1i(v1i_cvt_v1i(v1i_cast_v1i(v1i_cast_m1i(a)))))
#define m1l_cvt_m1i(a)  m1l_cast_v1l(v1l_cast_v1l(v1l_cvt_v1i(v1i_cast_v1i(v1i_cast_m1i(a)))))
#define m2d_cvt_m2i(a)  m2d_cast_v2d(v2d_cast_v2l(v2l_cvt_v2i(v2i_cast_v2i(v2i_cast_m2i(a)))))
#define m2f_cvt_m2i(a)  m2f_cast_v2f(v2f_cast_v2i(v2i_cvt_v2i(v2i_cast_v2i(v2i_cast_m2i(a)))))
#define m2i_cvt_m2i(a)  m2i_cast_v2i(v2i_cast_v2i(v2i_cvt_v2i(v2i_cast_v2i(v2i_cast_m2i(a)))))
#define m2l_cvt_m2i(a)  m2l_cast_v2l(v2l_cast_v2l(v2l_cvt_v2i(v2i_cast_v2i(v2i_cast_m2i(a)))))
#define m4d_cvt_m4i(a)  m4d_cast_v4d(v4d_cast_v4l(v4l_cvt_v4i(v4i_cast_v4i(v4i_cast_m4i(a)))))
#define m4f_cvt_m4i(a)  m4f_cast_v4f(v4f_cast_v4i(v4i_cvt_v4i(v4i_cast_v4i(v4i_cast_m4i(a)))))
#define m4i_cvt_m4i(a)  m4i_cast_v4i(v4i_cast_v4i(v4i_cvt_v4i(v4i_cast_v4i(v4i_cast_m4i(a)))))
#define m4l_cvt_m4i(a)  m4l_cast_v4l(v4l_cast_v4l(v4l_cvt_v4i(v4i_cast_v4i(v4i_cast_m4i(a)))))
#define m8d_cvt_m8i(a)  m8d_cast_v8d(v8d_cast_v8l(v8l_cvt_v8i(v8i_cast_v8i(v8i_cast_m8i(a)))))
#define m8f_cvt_m8i(a)  m8f_cast_v8f(v8f_cast_v8i(v8i_cvt_v8i(v8i_cast_v8i(v8i_cast_m8i(a)))))
#define m8i_cvt_m8i(a)  m8i_cast_v8i(v8i_cast_v8i(v8i_cvt_v8i(v8i_cast_v8i(v8i_cast_m8i(a)))))
#define m8l_cvt_m8i(a)  m8l_cast_v8l(v8l_cast_v8l(v8l_cvt_v8i(v8i_cast_v8i(v8i_cast_m8i(a)))))
#define m16f_cvt_m16i(a)  m16f_cast_v16f(v16f_cast_v16i(v16i_cvt_v16i(v16i_cast_v16i(v16i_cast_m16i(a)))))
#define m16i_cvt_m16i(a)  m16i_cast_v16i(v16i_cast_v16i(v16i_cvt_v16i(v16i_cast_v16i(v16i_cast_m16i(a)))))
#define m1d_cvt_m1l(a)  m1d_cast_v1d(v1d_cast_v1l(v1l_cvt_v1l(v1l_cast_v1l(v1l_cast_m1l(a)))))
#define m1f_cvt_m1l(a)  m1f_cast_v1f(v1f_cast_v1i(v1i_cvt_v1l(v1l_cast_v1l(v1l_cast_m1l(a)))))
#define m1i_cvt_m1l(a)  m1i_cast_v1i(v1i_cast_v1i(v1i_cvt_v1l(v1l_cast_v1l(v1l_cast_m1l(a)))))
#define m1l_cvt_m1l(a)  m1l_cast_v1l(v1l_cast_v1l(v1l_cvt_v1l(v1l_cast_v1l(v1l_cast_m1l(a)))))
#define m2d_cvt_m2l(a)  m2d_cast_v2d(v2d_cast_v2l(v2l_cvt_v2l(v2l_cast_v2l(v2l_cast_m2l(a)))))
#define m2f_cvt_m2l(a)  m2f_cast_v2f(v2f_cast_v2i(v2i_cvt_v2l(v2l_cast_v2l(v2l_cast_m2l(a)))))
#define m2i_cvt_m2l(a)  m2i_cast_v2i(v2i_cast_v2i(v2i_cvt_v2l(v2l_cast_v2l(v2l_cast_m2l(a)))))
#define m2l_cvt_m2l(a)  m2l_cast_v2l(v2l_cast_v2l(v2l_cvt_v2l(v2l_cast_v2l(v2l_cast_m2l(a)))))
#define m4d_cvt_m4l(a)  m4d_cast_v4d(v4d_cast_v4l(v4l_cvt_v4l(v4l_cast_v4l(v4l_cast_m4l(a)))))
#define m4f_cvt_m4l(a)  m4f_cast_v4f(v4f_cast_v4i(v4i_cvt_v4l(v4l_cast_v4l(v4l_cast_m4l(a)))))
#define m4i_cvt_m4l(a)  m4i_cast_v4i(v4i_cast_v4i(v4i_cvt_v4l(v4l_cast_v4l(v4l_cast_m4l(a)))))
#define m4l_cvt_m4l(a)  m4l_cast_v4l(v4l_cast_v4l(v4l_cvt_v4l(v4l_cast_v4l(v4l_cast_m4l(a)))))
#define m8d_cvt_m8l(a)  m8d_cast_v8d(v8d_cast_v8l(v8l_cvt_v8l(v8l_cast_v8l(v8l_cast_m8l(a)))))
#define m8f_cvt_m8l(a)  m8f_cast_v8f(v8f_cast_v8i(v8i_cvt_v8l(v8l_cast_v8l(v8l_cast_m8l(a)))))
#define m8i_cvt_m8l(a)  m8i_cast_v8i(v8i_cast_v8i(v8i_cvt_v8l(v8l_cast_v8l(v8l_cast_m8l(a)))))
#define m8l_cvt_m8l(a)  m8l_cast_v8l(v8l_cast_v8l(v8l_cvt_v8l(v8l_cast_v8l(v8l_cast_m8l(a)))))

/* compatible CONVERTS */

#endif //PINTS_POLYFILL_DEFINES_H