#ifndef PINTS_AVX_H
#define PINTS_AVX_H


#ifdef AVX
#undef v4d
#undef v8f
#undef v8i
#undef v4l
typedef __m256d v4d;
typedef __m256  v8f;
typedef __m256i v8i;
typedef __m256i v4l;
#endif

#ifdef AVX512
#undef v8d
#undef v16f
#undef v16i
#undef v8l
typedef __m512d v8d;
typedef __m512  v16f;
typedef __m512i v16i;
typedef __m512i v8l;
#endif

#ifdef AVX
// 256 bits

#undef v4d_set
#undef v8f_set
#undef v8i_set
#undef v4l_set
#define v4d_set(a0, a1, a2, a3)                 _mm256_set_pd(a3, a2, a1, a0)
#define v8f_set(a0, a1, a2, a3, a4, a5, a6, a7) _mm256_set_ps(a7, a6, a5, a4, a3, a2, a1, a0)
#define v8i_set(a0, a1, a2, a3, a4, a5, a6, a7) _mm256_set_epi32(a7, a6, a5, a4, a3, a2, a1, a0)
#define v4l_set(a0, a1, a2, a3)                 _mm256_set_epi64x(a3, a2, a1, a0)

#undef v4d_setr
#undef v8f_setr
#undef v8i_setr
#undef v4l_setr
#define v4d_setr(a3, a2, a1, a0)                 _mm256_setr_pd(a0, a1, a2, a3)
#define v8f_setr(a7, a6, a5, a4, a3, a2, a1, a0) _mm256_setr_ps(a0, a1, a2, a3, a4, a5, a6, a7)
#define v8i_setr(a7, a6, a5, a4, a3, a2, a1, a0) _mm256_setr_epi32(a0, a1, a2, a3, a4, a5, a6, a7)
#define v4l_setr(a3, a2, a1, a0)                 _mm256_setr_epi64x(a0, a1, a2, a3)

#undef v4d_set1
#undef v8f_set1
#undef v8i_set1
#undef v4l_set1
#define v4d_set1(a) _mm256_set1_pd(a)
#define v8f_set1(a) _mm256_set1_ps(a)
#define v8i_set1(a) _mm256_set1_epi32(a)
#define v4l_set1(a) _mm256_set1_epi64x(a)

#undef v4d_load
#undef v8f_load
#undef v8i_load
#undef v4l_load
#define v4d_load(p) _mm256_load_pd(p)
#define v8f_load(p) _mm256_load_ps(p)
#define v8i_load(p) _mm256_load_si256((__m256i*)p)
#define v4l_load(p) _mm256_load_si256((__m256i*)p)

#undef v4d_loadu
#undef v8f_loadu
#undef v8i_loadu
#undef v4l_loadu
#define v4d_loadu(p) _mm256_loadu_pd(p)
#define v8f_loadu(p) _mm256_loadu_ps(p)
#define v8i_loadu(p) _mm256_loadu_si256((__m256i*)p)
#define v4l_loadu(p) _mm256_loadu_si256((__m256i*)p)

#undef v4d_load1
#undef v8f_load1
#undef v8i_load1
#undef v4l_load1
#define v4d_load1(p) v4d_set1(*p)
#define v8f_load1(p) v8f_set1(*p)
#define v8i_load1(p) v8i_set1(*p)
#define v4l_load1(p) v4l_set1(*p)

#undef v4d_store
#undef v8f_store
#undef v8i_store
#undef v4l_store
#define v4d_store(p, a) _mm256_store_pd(p, a)
#define v8f_store(p, a) _mm256_store_ps(p, a)
#define v8i_store(p, a) _mm256_store_si256((__m256i*)p, a)
#define v4l_store(p, a) _mm256_store_si256((__m256i*)p, a)

#undef v4d_storeu
#undef v8f_storeu
#undef v8i_storeu
#undef v4l_storeu
#define v4d_storeu(p, a) _mm256_storeu_pd(p, a)
#define v8f_storeu(p, a) _mm256_storeu_ps(p, a)
#define v8i_storeu(p, a) _mm256_storeu_si256((__m256i*)p, a)
#define v4l_storeu(p, a) _mm256_storeu_si256((__m256i*)p, a)

#undef v4d_zero
#undef v8f_zero
#undef v8i_zero
#undef v4l_zero
#define v4d_zero() _mm256_setzero_pd()
#define v8f_zero() _mm256_setzero_ps()
#define v8i_zero() _mm256_setzero_si256()
#define v4l_zero() _mm256_setzero_si256()

#undef v4d_is_zero
#undef v8f_is_zero
#undef v8i_is_zero
#undef v4l_is_zero
#define v4d_is_zero(a) _mm256_testz_pd(a, a)
#define v8f_is_zero(a) _mm256_testz_ps(a, a)
#define v8i_is_zero(a) _mm256_testz_si256(a, a)
#define v4l_is_zero(a) _mm256_testz_si256(a, a)

#undef v4d_and
#undef v8f_and
#undef v8i_and
#undef v4l_and
#define v4d_and(a, b) _mm256_and_pd(a, b)
#define v8f_and(a, b) _mm256_and_ps(a, b)
#define v8i_and(a, b) _mm256_and_si256(a, b)
#define v4l_and(a, b) _mm256_and_si256(a, b)

#undef v4d_or
#undef v8f_or
#undef v8i_or
#undef v4l_or
#define v4d_or(a, b) _mm256_or_pd(a, b)
#define v8f_or(a, b) _mm256_or_ps(a, b)
#define v8i_or(a, b) _mm256_or_si256(a, b)
#define v4l_or(a, b) _mm256_or_si256(a, b)

#undef v4d_xor
#undef v8f_xor
#undef v8i_xor
#undef v4l_xor
#define v4d_xor(a, b) _mm256_xor_pd(a, b)
#define v8f_xor(a, b) _mm256_xor_ps(a, b)
#define v8i_xor(a, b) _mm256_xor_si256(a, b)
#define v4l_xor(a, b) _mm256_xor_si256(a, b)

#undef v4d_andnot
#undef v8f_andnot
#undef v8i_andnot
#undef v4l_andnot
#define v4d_andnot(a, b) _mm256_andnot_pd(b, a)
#define v8f_andnot(a, b) _mm256_andnot_ps(b, a)
#define v8i_andnot(a, b) _mm256_andnot_si256(b, a)
#define v4l_andnot(a, b) _mm256_andnot_si256(b, a)

#undef v4d_eq
#undef v8f_eq
#define v4d_eq(a, b) _mm256_cmp_pd(a, b, _CMP_EQ_OQ)
#define v8f_eq(a, b) _mm256_cmp_ps(a, b, _CMP_EQ_OQ)

#undef v4d_neq
#undef v8f_neq
#define v4d_neq(a, b) _mm256_cmp_pd(a, b, _CMP_NEQ_UQ)
#define v8f_neq(a, b) _mm256_cmp_ps(a, b, _CMP_NEQ_UQ)

#undef v4d_gt
#undef v8f_gt
#define v4d_gt(a, b) _mm256_cmp_pd(a, b, _CMP_GT_OQ)
#define v8f_gt(a, b) _mm256_cmp_ps(a, b, _CMP_GT_OQ)

#undef v4d_lt
#undef v8f_lt
#define v4d_lt(a, b) _mm256_cmp_pd(a, b, _CMP_LT_OQ)
#define v8f_lt(a, b) _mm256_cmp_ps(a, b, _CMP_LT_OQ)

#undef v4d_leq
#undef v8f_leq
#define v4d_leq(a, b) _mm256_cmp_pd(a, b, _CMP_LE_OQ)
#define v8f_leq(a, b) _mm256_cmp_ps(a, b, _CMP_LE_OQ)

#undef v4d_geq
#undef v8f_geq
#define v4d_geq(a, b) _mm256_cmp_pd(a, b, _CMP_GE_OQ)
#define v8f_geq(a, b) _mm256_cmp_ps(a, b, _CMP_GE_OQ)

#undef v4d_add
#undef v8f_add
#define v4d_add(a, b) _mm256_add_pd(a, b)
#define v8f_add(a, b) _mm256_add_ps(a, b)

#undef v4d_sub
#undef v8f_sub
#define v4d_sub(a, b) _mm256_sub_pd(a, b)
#define v8f_sub(a, b) _mm256_sub_ps(a, b)

#undef v4d_mul
#undef v8f_mul
#undef v4l_mul
#define v4d_mul(a, b) _mm256_mul_pd(a, b)
#define v8f_mul(a, b) _mm256_mul_ps(a, b)
#define v4l_mul(a, b) v4l_cvt_v4d(v4d_mul(v4d_cvt_v4l(a), v4d_cvt_v4l(b)))

#undef v4d_div
#undef v8f_div
#undef v8i_div
#undef v4l_div
#define v4d_div(a, b) _mm256_div_pd(a, b)
#define v8f_div(a, b) _mm256_div_ps(a, b)
#define v8i_div(a, b) v8i_cvt_v8f(v8f_div(v8f_cvt_v8i(a), v8f_cvt_v8i(b)))
#define v4l_div(a, b) v4l_cvt_v4d(v4d_div(v4d_cvt_v4l(a), v4d_cvt_v4l(b)))

#undef v4d_sqrt
#undef v8f_sqrt
#undef v8i_sqrt
#undef v4l_sqrt
#define v4d_sqrt(a) _mm256_sqrt_pd(a)
#define v8f_sqrt(a) _mm256_sqrt_ps(a)
#define v8i_sqrt(a) v8i_cvt_v8f(v8f_sqrt(v8f_cvt_v8i(a)))
#define v4l_sqrt(a) v4l_cvt_v4d(v4d_sqrt(v4d_cvt_v4l(a)))

#undef v4d_blend2
#undef v4d_blend4
#undef v8f_blend2
#undef v8f_blend4
#undef v8f_blend8
#undef v8i_blend2
#undef v8i_blend4
#undef v8i_blend8
#undef v4l_blend2
#undef v4l_blend4
#define v4d_blend2(a, b, mask) v4d_blend4(a, b, (((mask) & 3) << 2) | ((mask) & 3))
#define v4d_blend4(a, b, mask) _mm256_blend_pd(a, b, mask)
#define v8f_blend2(a, b, mask) v8f_blend4(a, b, (((mask) & 3) << 2) | ((mask) & 3))
#define v8f_blend4(a, b, mask) v8f_blend8(a, b, (((mask) & 7) << 4) | ((mask) & 7))
#define v8f_blend8(a, b, mask) _mm256_blend_ps(a, b, mask)
#define v8i_blend2(a, b, mask) v8i_blend4(a, b, (((mask) & 3) << 2) | ((mask) & 3))
#define v8i_blend4(a, b, mask) v8i_blend8(a, b, (((mask) & 7) << 4) | ((mask) & 7))
#define v8i_blend8(a, b, mask) v8i_cast_v8f(v8f_blend8(v8f_cast_v8i(a), v8f_cast_v8i(b), mask))
#define v4l_blend2(a, b, mask) v4l_blend4(a, b, (((mask) & 3) << 2) | ((mask) & 3))
#define v4l_blend4(a, b, mask) v4l_cast_v8i(v8i_blend4(v8i_cast_v4l(a), v8i_blend4(v8i_cast_v4l(b)), mask))

#undef v4d_hshuffle2x2
#undef v4l_hshuffle2x2
#define v4d_hshuffle2x2(a, b, rule) _mm256_shuffle_pd(a, b, rule)
#define v4l_hshuffle2x2(a, b, rule) v4l_cast_v4d(v4d_hshuffle2x2(v4d_cast_v4l(a), v4d_cast_v4l(b), rule))

#undef v4d_permute2x2
#undef v4l_permute2x2
#define v4d_permute2x2(a, rule) _mm256_permute_pd(a, rule)
#define v4l_permute2x2(a, rule) v4l_cast_v4d(v4d_permute2x2(v4d_cast_v4l(a), rule))

#undef v8f_hshuffle4x2
#undef v8i_hshuffle4x2
#define v8f_hshuffle4x2(a, b, rule) _mm256_shuffle_ps(a, b, rule)
#define v8i_hshuffle4x2(a, b, rule) v8i_cast_v8f(v8f_hshuffle4x2(v8f_cast_v8i(a), v8f_cast_v8i(b), rule))

#undef v8f_permute4x2
#undef v8i_permute4x2
#define v8f_permute4x2(a, rule) _mm256_permute_ps(a, rule)
#define v8i_permute4x2(a, rule) v8i_cast_v8f(v8f_permute4x2(v8f_cast_v8i(a), rule))

#undef v8f_hshuffle2x4
#undef v8i_hshuffle2x4
#define v8f_hshuffle2x4(a, b, rule) v8f_hshuffle4x2(a, b, (((rule)&2)<<1) | (((rule)&2)<<5) | (((rule)&1)<<4) | ((rule)&1) | 0xA0)
#define v8i_hshuffle2x4(a, b, rule) v8i_hshuffle4x2(a, b, (((rule)&2)<<1) | (((rule)&2)<<5) | (((rule)&1)<<4) | ((rule)&1) | 0xA0)

#undef v8f_permute2x4
#undef v8i_permute2x4
#define v8f_permute2x4(a, rule) v8f_permute4x2(a, (((rule)&2)<<1) | (((rule)&2)<<5) | (((rule)&1)<<4) | ((rule)&1) | 0xA0)
#define v8i_permute2x4(a, rule) v8i_permute4x2(a, (((rule)&2)<<1) | (((rule)&2)<<5) | (((rule)&1)<<4) | ((rule)&1) | 0xA0)

#undef v4d_fshuffle2
#undef v8f_fshuffle2
#undef v8i_fshuffle2
#undef v4l_fshuffle2
#define v4d_fshuffle2(a, b, rule, mask) _mm256_permute2f128_pd(a, b, ((rule)&1)|(((mask)&1)<<1)|(((rule)&2)<<3)|(((mask)&2)<<4))
#define v8f_fshuffle2(a, b, rule, mask) _mm256_permute2f128_ps(a, b, ((rule)&1)|(((mask)&1)<<1)|(((rule)&2)<<3)|(((mask)&2)<<4))
#define v8i_fshuffle2(a, b, rule, mask) _mm256_permute2f128_si256(a, b, ((rule)&1)|(((mask)&1)<<1)|(((rule)&2)<<3)|(((mask)&2)<<4))
#define v4l_fshuffle2(a, b, rule, mask) _mm256_permute2f128_si256(a, b, ((rule)&1)|(((mask)&1)<<1)|(((rule)&2)<<3)|(((mask)&2)<<4))


#undef v4d_hshuffle2
#undef v8f_hshuffle2
#undef v8i_hshuffle2
#undef v4l_hshuffle2
#define v4d_hshuffle2(a, b, rule) _mm256_permute2f128_pd(a, b, ((rule)&1)|(((rule)&2)<<3)|0x20)
#define v8f_hshuffle2(a, b, rule) _mm256_permute2f128_ps(a, b, ((rule)&1)|(((rule)&2)<<3)|0x20)
#define v8i_hshuffle2(a, b, rule) _mm256_permute2f128_si256(a, b, ((rule)&1)|(((rule)&2)<<3)|0x20)
#define v4l_hshuffle2(a, b, rule) _mm256_permute2f128_si256(a, b, ((rule)&1)|(((rule)&2)<<3)|0x20)



// Casts

// Down Casts
#undef v2d_cast_v4d
#undef v4f_cast_v8f
#undef v4i_cast_v8i
#undef v2l_cast_v4l
#define v2d_cast_v4d(a) _mm256_castpd256_pd128(a)
#define v4f_cast_v8f(a) _mm256_castps256_ps128(a)
#define v4i_cast_v8i(a) _mm256_castsi256_si128(a)
#define v2l_cast_v4l(a) _mm256_castsi256_si128(a)

// Up Casts
#undef v4d_cast_v2d
#undef v8f_cast_v4f
#undef v8i_cast_v4i
#undef v4l_cast_v2l
#define v4d_cast_v2d(a) _mm256_castpd128_pd256(a)
#define v8f_cast_v4f(a) _mm256_castps128_ps256(a)
#define v8i_cast_v4i(a) _mm256_castsi128_si256(a)
#define v4l_cast_v2l(a) _mm256_castsi128_si256(a)

// Transtype Casts

// 256 bits
#undef v4d_cast_v4d
#undef v4d_cast_v8f
#undef v4d_cast_v8i
#undef v4d_cast_v4l
#undef v8f_cast_v4d
#undef v8f_cast_v8f
#undef v8f_cast_v8i
#undef v8f_cast_v4l
#undef v8i_cast_v4d
#undef v8i_cast_v8f
#undef v8i_cast_v8i
#undef v8i_cast_v4l
#undef v4l_cast_v4d
#undef v4l_cast_v8f
#undef v4l_cast_v8i
#undef v4l_cast_v4l

#define v4d_cast_v4d(a) (a)
#define v4d_cast_v8f(a) _mm256_castps_pd(a)
#define v4d_cast_v8i(a) _mm256_castsi256_pd(a)
#define v4d_cast_v4l(a) _mm256_castsi256_pd(a)
#define v8f_cast_v4d(a) _mm256_castpd_ps(a)
#define v8f_cast_v8f(a) (a)
#define v8f_cast_v8i(a) _mm256_castsi256_ps(a)
#define v8f_cast_v4l(a) _mm256_castsi256_ps(a)
#define v8i_cast_v4d(a) _mm256_castpd_si256(a)
#define v8i_cast_v8f(a) _mm256_castps_si256(a)
#define v8i_cast_v8i(a) (a)
#define v8i_cast_v4l(a) (a)
#define v4l_cast_v4d(a) _mm256_castpd_si256(a)
#define v4l_cast_v8f(a) _mm256_castps_si256(a)
#define v4l_cast_v8i(a) (a)
#define v4l_cast_v4l(a) (a)


// Conversions
#undef v8f_cvt_v8f
#undef v8f_cvt_v8i
#undef v8i_cvt_v8f
#undef v8i_cvt_v8i
#undef v4d_cvt_v4d
#undef v4f_cvt_v4d
#undef v4i_cvt_v4d
#undef v4l_cvt_v4d
#undef v4d_cvt_v4f
#undef v4l_cvt_v4f
#undef v4d_cvt_v4i
#undef v4l_cvt_v4i
#undef v4d_cvt_v4l
#undef v4f_cvt_v4l
#undef v4i_cvt_v4l
#undef v4l_cvt_v4l


#define v8f_cvt_v8f(a) (a)
#define v8f_cvt_v8i(a) _mm256_cvtepi32_ps(a)
#define v8i_cvt_v8f(a) _mm256_cvtps_epi32(a)
#define v8i_cvt_v8i(a) (a)
#define v4d_cvt_v4d(a) (a)
#define v4f_cvt_v4d(a) _mm256_cvtpd_ps(a)
#define v4i_cvt_v4d(a) _mm256_cvtpd_epi32(a)
#define v4l_cvt_v4d(a) __v4l_cvt_v4d(a)
#define v4d_cvt_v4f(a) _mm256_cvtps_pd(a)
#define v4l_cvt_v4f(a) __v4l_cvt_v4f(a)
#define v4d_cvt_v4i(a) _mm256_cvtepi32_pd(a)
#define v4l_cvt_v4i(a) _mm256_cvtepi32_epi64(a)
#define v4d_cvt_v4l(a) __v4d_cvt_v4l(a)
#define v4f_cvt_v4l(a) __v4f_cvt_v4l(a)
#define v4i_cvt_v4l(a) __v4i_cvt_v4l(a)
#define v4l_cvt_v4l(a) (a)


// Default get_high get_low, sethigh, setlow, merge
#undef v2d_get_high_v4d
#undef v4f_get_high_v8f
#undef v4i_get_high_v8i
#undef v2l_get_high_v4l
#undef v2d_get_low_v4d
#undef v4f_get_low_v8f
#undef v4i_get_low_v8i
#undef v2l_get_low_v4l
#undef v4d_set_high_v2d
#undef v8f_set_high_v4f
#undef v8i_set_high_v4i
#undef v4l_set_high_v2l
#undef v4d_set_low_v2d
#undef v8f_set_low_v4f
#undef v8i_set_low_v4i
#undef v4l_set_low_v2l
#undef v4d_merge2_v2d
#undef v8f_merge2_v4f
#undef v8i_merge2_v4i
#undef v4l_merge2_v2l

#define v2d_get_high_v4d(a)      _mm256_extractf128_pd(a, 1)
#define v4f_get_high_v8f(a)      _mm256_extractf128_ps(a, 1)
#define v4i_get_high_v8i(a)      v4i_cast_v4f(v4f_get_high_v8f(v8f_cast_v8i(a)))
#define v2l_get_high_v4l(a)      v2l_cast_v2d(v2d_get_high_v4d(v4d_cast_v4l(a)))
#define v2d_get_low_v4d(a)       _mm256_extractf128_pd(a, 0)
#define v4f_get_low_v8f(a)       _mm256_extractf128_ps(a, 0)
#define v4i_get_low_v8i(a)       v4i_cast_v4f(v4f_get_low_v8f(v8f_cast_v8i(a)))
#define v2l_get_low_v4l(a)       v2l_cast_v2d(v2d_get_low_v4d(v4d_cast_v4l(a)))
#define v4d_set_high_v2d(src, a) _mm256_insertf128_pd(src, a, 1)
#define v8f_set_high_v4f(src, a) _mm256_insertf128_ps(src, a, 1)
#define v8i_set_high_v4i(src, a) _mm256_insertf128_si256(src, a, 1)
#define v4l_set_high_v2l(src, a) _mm256_insertf128_si256(src, a, 1)
#define v4d_set_low_v2d(src, a)  _mm256_insertf128_pd(src, a, 0)
#define v8f_set_low_v4f(src, a)  _mm256_insertf128_ps(src, a, 0)
#define v8i_set_low_v4i(src, a)  _mm256_insertf128_si256(src, a, 0)
#define v4l_set_low_v2l(src, a)  _mm256_insertf128_si256(src, a, 0)
#define v4d_merge2_v2d(a, b)      _mm256_insertf128_pd(_mm256_castpd128_pd256(a), b, 1)
#define v8f_merge2_v4f(a, b)      _mm256_insertf128_ps(_mm256_castps128_ps256(a), b, 1)
#define v8i_merge2_v4i(a, b)      _mm256_insertf128_si256(_mm256_castsi128_si256(a), b, 1)
#define v4l_merge2_v2l(a, b)      _mm256_insertf128_si256(_mm256_castsi128_si256(a), b, 1)

#endif

#ifdef AVX2

#undef v4d_load1
#undef v8f_load1
#undef v8i_load1
#undef v4l_load1
#define v4d_load1(p) _mm256_broadcast_sd(p)
#define v8f_load1(p) _mm256_broadcast_ss(p)
#define v8i_load1(p) v8i_cast_v8f(v8f_load1((float *) p))
#define v4l_load1(p) v4l_cast_v4d(v4d_load1((double*) p))


#undef v8i_eq
#undef v4l_eq
#define v8i_eq(a, b) _mm256_cmpeq_epi32(a, b)
#define v4l_eq(a, b) _mm256_cmpeq_epi64(a, b)

#undef v8i_neq
#undef v4l_neq
#define v8i_neq(a, b) v8i_not(v8i_eq(a, b))
#define v4l_neq(a, b) v4l_not(v4l_eq(a, b))

#undef v8i_gt
#undef v4l_gt
#define v8i_gt(a, b) _mm256_cmpgt_epi32(a, b)
#define v4l_gt(a, b) _mm256_cmpgt_epi64(a, b)

#undef v8i_lt
#undef v4l_lt
#define v8i_lt(a, b) v8i_andnot(v8i_leq(a, b), v8i_eq(a, b))
#define v4l_lt(a, b) v4l_andnot(v4l_leq(a, b), v4l_eq(a, b))

#undef v8i_leq
#undef v4l_leq
#define v8i_leq(a, b) v8i_gt(b, a)
#define v4l_leq(a, b) v4l_gt(b, a)

#undef v8i_geq
#undef v4l_geq
#define v8i_geq(a, b) v8i_lt(b, a)
#define v4l_geq(a, b) v4l_lt(b, a)

#undef v8i_add
#undef v4l_add
#define v8i_add(a, b) _mm256_add_epi32(a, b)
#define v4l_add(a, b) _mm256_add_epi64(a, b)

#undef v8i_sub
#undef v4l_sub
#define v8i_sub(a, b) _mm256_sub_epi32(a, b)
#define v4l_sub(a, b) _mm256_sub_epi64(a, b)

#undef v8i_mul
#define v8i_mul(a, b) _mm256_mullo_epi32(a, b)

#undef v8i_blend8
#define v8i_blend8(a, b, mask) _mm256_blend_epi32(a, b, mask)

#undef v4i_blend4
#define v4i_blend4(a, b, mask) _mm_blend_epi32(a, b, mask)

#undef v8i_hshuffle4x2
#define v8i_hshuffle4x2(a, b, rule) v8f_fshuffle4x2(v8f_cast_v8i(a), v8f_cast_v8i(b), rule, 0xC)

#undef v8i_permute4x2
#define v8i_permute4x2(a, rule) _mm256_shuffle_epi32(a, rule)

#undef v8i_fshuffle2
#undef v4l_fshuffle2
#define v8i_fshuffle2(a, b, rule, mask) _mm256_permute2x128_si256(a, b, ((rule)&1)|(((mask)&1)<<1)|(((rule)&2)<<3)|(((mask)&2)<<4))
#define v4l_fshuffle2(a, b, rule, mask) _mm256_permute2x128_si256(a, b, ((rule)&1)|(((mask)&1)<<1)|(((rule)&2)<<3)|(((mask)&2)<<4))


#undef v8i_hshuffle2
#undef v4l_hshuffle2
#define v8i_hshuffle2(a, b, rule) _mm256_permute2x128_si256(a, b, ((rule)&1)|(((rule)&2)<<3)|0x20)
#define v4l_hshuffle2(a, b, rule) _mm256_permute2x128_si256(a, b, ((rule)&1)|(((rule)&2)<<3)|0x20)

#endif

#ifdef AVX_FMA
#undef v1d_fmadd
#undef v1d_fmsub
#undef v1d_fnmadd
#undef v1d_fnmsub
#undef v1f_fmadd
#undef v1f_fmsub
#undef v1f_fnmadd
#undef v1f_fnmsub
#undef v2d_fmadd
#undef v2d_fmsub
#undef v2d_fnmadd
#undef v2d_fnmsub
#undef v2f_fmadd
#undef v2f_fmsub
#undef v2f_fnmadd
#undef v2f_fnmsub
#undef v4d_fmadd
#undef v4d_fmsub
#undef v4d_fnmadd
#undef v4d_fnmsub
#undef v4f_fmadd
#undef v4f_fmsub
#undef v4f_fnmadd
#undef v4f_fnmsub
#undef v8f_fmadd
#undef v8f_fmsub
#undef v8f_fnmadd
#undef v8f_fnmsub

#define  v1d_fmadd(a, b, c)  _mm_fmadd_sd(a, b, c)
#define  v1d_fmsub(a, b, c)  _mm_fmsub_sd(a, b, c)
#define v1d_fnmadd(a, b, c) _mm_fnmadd_sd(a, b, c)
#define v1d_fnmsub(a, b, c) _mm_fnmsub_sd(a, b, c)
#define  v1f_fmadd(a, b, c)  _mm_fmadd_ss(a, b, c)
#define  v1f_fmsub(a, b, c)  _mm_fmsub_ss(a, b, c)
#define v1f_fnmadd(a, b, c) _mm_fnmadd_ss(a, b, c)
#define v1f_fnmsub(a, b, c) _mm_fnmsub_ss(a, b, c)
#define  v2d_fmadd(a, b, c)  _mm_fmadd_pd(a, b, c)
#define  v2d_fmsub(a, b, c)  _mm_fmsub_pd(a, b, c)
#define v2d_fnmadd(a, b, c) _mm_fnmadd_pd(a, b, c)
#define v2d_fnmsub(a, b, c) _mm_fnmsub_pd(a, b, c)
#define  v2f_fmadd(a, b, c)  _mm_fmadd_ps(a, b, c)
#define  v2f_fmsub(a, b, c)  _mm_fmsub_ps(a, b, c)
#define v2f_fnmadd(a, b, c) _mm_fnmadd_ps(a, b, c)
#define v2f_fnmsub(a, b, c) _mm_fnmsub_ps(a, b, c)
#define  v4f_fmadd(a, b, c)  _mm_fmadd_ps(a, b, c)
#define  v4f_fmsub(a, b, c)  _mm_fmsub_ps(a, b, c)
#define v4f_fnmadd(a, b, c) _mm_fnmadd_ps(a, b, c)
#define v4f_fnmsub(a, b, c) _mm_fnmsub_ps(a, b, c)
#define  v4d_fmadd(a, b, c)  _mm256_fmadd_pd(a, b, c)
#define  v4d_fmsub(a, b, c)  _mm256_fmsub_pd(a, b, c)
#define v4d_fnmadd(a, b, c) _mm256_fnmadd_pd(a, b, c)
#define v4d_fnmsub(a, b, c) _mm256_fnmsub_pd(a, b, c)
#define  v8f_fmadd(a, b, c)  _mm256_fmadd_ps(a, b, c)
#define  v8f_fmsub(a, b, c)  _mm256_fmsub_ps(a, b, c)
#define v8f_fnmadd(a, b, c) _mm256_fnmadd_ps(a, b, c)
#define v8f_fnmsub(a, b, c) _mm256_fnmsub_ps(a, b, c)


#undef v8d_fmadd
#undef v8d_fmsub
#undef v8d_fnmadd
#undef v8d_fnmsub
#undef v16f_fmadd
#undef v16f_fmsub
#undef v16f_fnmadd
#undef v16f_fnmsub
#undef v16i_fmadd
#undef v16i_fmsub
#undef v16i_fnmadd
#undef v16i_fnmsub
#undef v8l_fmadd
#undef v8l_fmsub
#undef v8l_fnmadd
#undef v8l_fnmsub
#define   v8d_fmadd(a, b, c)   v8d_merge_v4d(v4d_fmadd(v4d_get_low_v8d(a), v4d_get_low_v8d(b), v4d_get_low_v8d(c)), v4d_fmadd(v4d_get_high_v8d(a), v4d_get_high_v8d(b), v4d_get_high_v8d(c)))
#define   v8d_fmsub(a, b, c)   v8d_merge_v4d(v4d_fmsub(v4d_get_low_v8d(a), v4d_get_low_v8d(b), v4d_get_low_v8d(c)), v4d_fmsub(v4d_get_high_v8d(a), v4d_get_high_v8d(b), v4d_get_high_v8d(c)))
#define  v8d_fnmadd(a, b, c)   v8d_merge_v4d(v4d_fnmadd(v4d_get_low_v8d(a), v4d_get_low_v8d(b), v4d_get_low_v8d(c)), v4d_fnmadd(v4d_get_high_v8d(a), v4d_get_high_v8d(b), v4d_get_high_v8d(c)))
#define  v8d_fnmsub(a, b, c)   v8d_merge_v4d(v4d_fnmsub(v4d_get_low_v8d(a), v4d_get_low_v8d(b), v4d_get_low_v8d(c)), v4d_fnmsub(v4d_get_high_v8d(a), v4d_get_high_v8d(b), v4d_get_high_v8d(c)))
#define  v16f_fmadd(a, b, c)   v16f_merge_v8f(v8f_fmadd(v8f_get_low_v16f(a), v8f_get_low_v16f(b), v8f_get_low_v16f(c)), v8f_fmadd(v8f_get_high_v16f(a), v8f_get_high_v16f(b), v8f_get_high_v16f(c)))
#define  v16f_fmsub(a, b, c)   v16f_merge_v8f(v8f_fmsub(v8f_get_low_v16f(a), v8f_get_low_v16f(b), v8f_get_low_v16f(c)), v8f_fmsub(v8f_get_high_v16f(a), v8f_get_high_v16f(b), v8f_get_high_v16f(c)))
#define v16f_fnmadd(a, b, c)   v16f_merge_v8f(v8f_fnmadd(v8f_get_low_v16f(a), v8f_get_low_v16f(b), v8f_get_low_v16f(c)), v8f_fnmadd(v8f_get_high_v16f(a), v8f_get_high_v16f(b), v8f_get_high_v16f(c)))
#define v16f_fnmsub(a, b, c)   v16f_merge_v8f(v8f_fnmsub(v8f_get_low_v16f(a), v8f_get_low_v16f(b), v8f_get_low_v16f(c)), v8f_fnmsub(v8f_get_high_v16f(a), v8f_get_high_v16f(b), v8f_get_high_v16f(c)))
#define  v16i_fmadd(a, b, c)   v16i_merge_v8i(v8i_fmadd(v8i_get_low_v16i(a), v8i_get_low_v16i(b), v8i_get_low_v16i(c)), v8i_fmadd(v8i_get_high_v16i(a), v8i_get_high_v16i(b), v8i_get_high_v16i(c)))
#define  v16i_fmsub(a, b, c)   v16i_merge_v8i(v8i_fmsub(v8i_get_low_v16i(a), v8i_get_low_v16i(b), v8i_get_low_v16i(c)), v8i_fmsub(v8i_get_high_v16i(a), v8i_get_high_v16i(b), v8i_get_high_v16i(c)))
#define v16i_fnmadd(a, b, c)   v16i_merge_v8i(v8i_fnmadd(v8i_get_low_v16i(a), v8i_get_low_v16i(b), v8i_get_low_v16i(c)), v8i_fnmadd(v8i_get_high_v16i(a), v8i_get_high_v16i(b), v8i_get_high_v16i(c)))
#define v16i_fnmsub(a, b, c)   v16i_merge_v8i(v8i_fnmsub(v8i_get_low_v16i(a), v8i_get_low_v16i(b), v8i_get_low_v16i(c)), v8i_fnmsub(v8i_get_high_v16i(a), v8i_get_high_v16i(b), v8i_get_high_v16i(c)))
#define   v8l_fmadd(a, b, c)   v8l_merge_v4l(v4l_fmadd(v4l_get_low_v8l(a), v4l_get_low_v8l(b), v4l_get_low_v8l(c)), v4l_fmadd(v4l_get_high_v8l(a), v4l_get_high_v8l(b), v4l_get_high_v8l(c)))
#define   v8l_fmsub(a, b, c)   v8l_merge_v4l(v4l_fmsub(v4l_get_low_v8l(a), v4l_get_low_v8l(b), v4l_get_low_v8l(c)), v4l_fmsub(v4l_get_high_v8l(a), v4l_get_high_v8l(b), v4l_get_high_v8l(c)))
#define  v8l_fnmadd(a, b, c)   v8l_merge_v4l(v4l_fnmadd(v4l_get_low_v8l(a), v4l_get_low_v8l(b), v4l_get_low_v8l(c)), v4l_fnmadd(v4l_get_high_v8l(a), v4l_get_high_v8l(b), v4l_get_high_v8l(c)))
#define  v8l_fnmsub(a, b, c)   v8l_merge_v4l(v4l_fnmsub(v4l_get_low_v8l(a), v4l_get_low_v8l(b), v4l_get_low_v8l(c)), v4l_fnmsub(v4l_get_high_v8l(a), v4l_get_high_v8l(b), v4l_get_high_v8l(c)))
#endif

#endif //PINTS_AVX_H
