#ifndef __STDMATH_float4x3_H__
#define __STDMATH_float4x3_H__

struct stdmath_float4x2;
struct stdmath_float4x3;
struct stdmath_float4x4;
#if 4 != 3
struct stdmath_float3x2;
struct stdmath_float3x3;
struct stdmath_float3x4;
#endif

#include <stddef.h>
#include "float3.h"

struct stdmath_float4x3 {
	float data[4 * 3];
};

stdmath_float4x3 stdmath_float4x3_identity_scaled(float scale);
stdmath_float4x3 stdmath_float4x3_identity();
stdmath_float4x3 stdmath_float4x3_fill(float value);

size_t stdmath_float4x3_rows(const stdmath_float4x3* m);
inline size_t stdmath_float4x3_rows_get(const stdmath_float4x3* m) {
	return stdmath_float4x3_rows(m);
}
size_t stdmath_float4x3_columns(const stdmath_float4x3* m);
inline size_t stdmath_float4x3_columns_get(const stdmath_float4x3* m) {
	return stdmath_float4x3_columns(m);
}
size_t stdmath_float4x3_size(const stdmath_float4x3* m);

float stdmath_float4x3_get_element(const stdmath_float4x3* m, size_t x, size_t y);
stdmath_float4x3 stdmath_float4x3_set_element(const stdmath_float4x3* m, size_t x, size_t y, float value);

stdmath_float4x3 stdmath_float4x3_add(const stdmath_float4x3* a, const stdmath_float4x3* b);
stdmath_float4x3 stdmath_float4x3_subtract(const stdmath_float4x3* a, const stdmath_float4x3* b);
stdmath_float4x3 stdmath_float4x3_negate(const stdmath_float4x3* m);
stdmath_float3x4 stdmath_float4x3_transpose(const stdmath_float4x3* m);

stdmath_float4x2 stdmath_float4x3_multiply2(const stdmath_float4x3* a, const stdmath_float3x2* b);
stdmath_float4x3 stdmath_float4x3_multiply3(const stdmath_float4x3* a, const stdmath_float3x3* b);
stdmath_float4x4 stdmath_float4x3_multiply4(const stdmath_float4x3* a, const stdmath_float3x4* b);
stdmath_float3 stdmath_float4x3_multiply(const stdmath_float4x3* m, stdmath_float3 v);

#if 4 == 3
stdmath_float4x4 stdmath_float4x4_scale(const stdmath_float4x4* m, float s);
stdmath_float4x4 stdmath_float4x4_inverse(const stdmath_float4x4* m);
#endif

#ifdef STDMATH_IMPLEMENTATION
#ifndef __cplusplus
#error "The stdmath implementations require a C++ compiler"
#endif

import stdmath.slang;

stdmath::float4x3 c(stdmath_float4x3 c) {
	return (stdmath::float4x3&)c;
}
stdmath_float4x3 c(stdmath::float4x3 c) {
	return (stdmath_float4x3&)c;
}

stdmath_float4x3 stdmath_float4x3_identity_scaled(float scale) {
	return c(stdmath::float4x3::identity((stdmath::float4x3::underlying_type)scale));
}
stdmath_float4x3 stdmath_float4x3_identity() {
	return c(stdmath::float4x3::identity());
}
stdmath_float4x3 stdmath_float4x3_fill(float value) {
	return c(stdmath::float4x3::fill((stdmath::float4x3::underlying_type)value));
}

size_t stdmath_float4x3_rows(const stdmath_float4x3* m) {
	return 4;
}
size_t stdmath_float4x3_columns(const stdmath_float4x3* m) {
	return 3;
}
size_t stdmath_float4x3_size(const stdmath_float4x3* m) {
	return 4 * 3;
}

float stdmath_float4x3_get_element(const stdmath_float4x3* m, size_t x, size_t y) {
	return c(*m)[x, y];
}
stdmath_float4x3 stdmath_float4x3_set_element(const stdmath_float4x3* m, size_t x, size_t y, float value) {
	auto out = c(*m);
	out[x, y] = (stdmath::float4x3::underlying_type)value;
	return c(out);
}

stdmath_float4x3 stdmath_float4x3_add(const stdmath_float4x3* a, const stdmath_float4x3* b) {
	return c(c(*a) + c(*b));
}
stdmath_float4x3 stdmath_float4x3_subtract(const stdmath_float4x3* a, const stdmath_float4x3* b) {
	return c(c(*a) - c(*b));
}
stdmath_float4x3 stdmath_float4x3_negate(const stdmath_float4x3* m) {
	return c(-c(*m));
}

stdmath_float3 stdmath_float4x3_multiply(const stdmath_float4x3* m, stdmath_float3 v) {
	return c(stdmath::float4x3::multiply(c(*m), c(v)));
}

#if 4 == 3
stdmath_float4x4 stdmath_float4x4_scale(const stdmath_float4x4* m, float s) {
	return c(stdmath::float4x4::multiply(c(*m), (stdmath::float4x4::underlying_type)s));
}
stdmath_float4x4 stdmath_float4x4_inverse(const stdmath_float4x4* m) {
	return c(inverse(c(*m)));
}
#endif

#endif // #ifdef STDMATH_IMPLEMENTATION

#endif // __STDMATH_float4x3_H__


#ifdef STDMATH_IMPLEMENTATION

#ifdef __STDMATH_float3x4_H__
#ifndef __STDMATH_float4x3_TRANSPOSE_IMPL__
#define __STDMATH_float4x3_TRANSPOSE_IMPL__
stdmath_float3x4 stdmath_float4x3_transpose(const stdmath_float4x3* m) {
	return c(transpose(c(*m)));
}
#endif
#endif

#ifdef __STDMATH_float3x2_H__
#ifdef __STDMATH_float4x2_H__
#ifndef __STDMATH_float4x3_4x2_IMPL__
#define __STDMATH_float4x3_4x2_IMPL__
stdmath_float4x2 stdmath_float4x3_multiply2(const stdmath_float4x3* a, const stdmath_float3x2* b) {
	return c(stdmath::float4x3::multiply(c(*a), c(*b)));
}
#endif
#endif
#endif

#ifdef __STDMATH_float3x3_H__
#ifdef __STDMATH_float4x3_H__
#ifndef __STDMATH_float4x3_4x3_IMPL__
#define __STDMATH_float4x3_4x3_IMPL__
stdmath_float4x3 stdmath_float4x3_multiply3(const stdmath_float4x3* a, const stdmath_float3x3* b) {
	return c(stdmath::float4x3::multiply(c(*a), c(*b)));
}
#endif
#endif
#endif

#ifdef __STDMATH_float3x4_H__
#ifdef __STDMATH_float4x4_H__
#ifndef __STDMATH_float4x3_4x4_IMPL__
#define __STDMATH_float4x3_4x4_IMPL__
stdmath_float4x4 stdmath_float4x3_multiply4(const stdmath_float4x3* a, const stdmath_float3x4* b) {
	return c(stdmath::float4x3::multiply(c(*a), c(*b)));
}
#endif
#endif
#endif

#endif // STDMATH_IMPLEMENTATION