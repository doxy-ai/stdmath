#ifndef __STDMATH_float4x4_H__
#define __STDMATH_float4x4_H__

struct stdmath_float4x2;
struct stdmath_float4x3;
struct stdmath_float4x4;
#if 4 != 4
struct stdmath_float4x2;
struct stdmath_float4x3;
struct stdmath_float4x4;
#endif

#include <stddef.h>
#include "float4.h"

struct stdmath_float4x4 {
	float data[4 * 4];
};

stdmath_float4x4 stdmath_float4x4_identity_scaled(float scale);
stdmath_float4x4 stdmath_float4x4_identity();
stdmath_float4x4 stdmath_float4x4_fill(float value);

size_t stdmath_float4x4_rows(const stdmath_float4x4* m);
inline size_t stdmath_float4x4_rows_get(const stdmath_float4x4* m) {
	return stdmath_float4x4_rows(m);
}
size_t stdmath_float4x4_columns(const stdmath_float4x4* m);
inline size_t stdmath_float4x4_columns_get(const stdmath_float4x4* m) {
	return stdmath_float4x4_columns(m);
}
size_t stdmath_float4x4_size(const stdmath_float4x4* m);

float stdmath_float4x4_get_element(const stdmath_float4x4* m, size_t x, size_t y);
stdmath_float4x4 stdmath_float4x4_set_element(const stdmath_float4x4* m, size_t x, size_t y, float value);

stdmath_float4x4 stdmath_float4x4_add(const stdmath_float4x4* a, const stdmath_float4x4* b);
stdmath_float4x4 stdmath_float4x4_subtract(const stdmath_float4x4* a, const stdmath_float4x4* b);
stdmath_float4x4 stdmath_float4x4_negate(const stdmath_float4x4* m);
stdmath_float4x4 stdmath_float4x4_transpose(const stdmath_float4x4* m);

stdmath_float4x2 stdmath_float4x4_multiply2(const stdmath_float4x4* a, const stdmath_float4x2* b);
stdmath_float4x3 stdmath_float4x4_multiply3(const stdmath_float4x4* a, const stdmath_float4x3* b);
stdmath_float4x4 stdmath_float4x4_multiply4(const stdmath_float4x4* a, const stdmath_float4x4* b);
stdmath_float4 stdmath_float4x4_multiply(const stdmath_float4x4* m, stdmath_float4 v);

#if 4 == 4
stdmath_float4x4 stdmath_float4x4_scale(const stdmath_float4x4* m, float s);
stdmath_float4x4 stdmath_float4x4_inverse(const stdmath_float4x4* m);
#endif

#ifdef STDMATH_IMPLEMENTATION
#ifndef __cplusplus
#error "The stdmath implementations require a C++ compiler"
#endif

import stdmath.slang;

stdmath::float4x4 c(stdmath_float4x4 c) {
	return (stdmath::float4x4&)c;
}
stdmath_float4x4 c(stdmath::float4x4 c) {
	return (stdmath_float4x4&)c;
}

stdmath_float4x4 stdmath_float4x4_identity_scaled(float scale) {
	return c(stdmath::float4x4::identity((stdmath::float4x4::underlying_type)scale));
}
stdmath_float4x4 stdmath_float4x4_identity() {
	return c(stdmath::float4x4::identity());
}
stdmath_float4x4 stdmath_float4x4_fill(float value) {
	return c(stdmath::float4x4::fill((stdmath::float4x4::underlying_type)value));
}

size_t stdmath_float4x4_rows(const stdmath_float4x4* m) {
	return 4;
}
size_t stdmath_float4x4_columns(const stdmath_float4x4* m) {
	return 4;
}
size_t stdmath_float4x4_size(const stdmath_float4x4* m) {
	return 4 * 4;
}

float stdmath_float4x4_get_element(const stdmath_float4x4* m, size_t x, size_t y) {
	return c(*m)[x, y];
}
stdmath_float4x4 stdmath_float4x4_set_element(const stdmath_float4x4* m, size_t x, size_t y, float value) {
	auto out = c(*m);
	out[x, y] = (stdmath::float4x4::underlying_type)value;
	return c(out);
}

stdmath_float4x4 stdmath_float4x4_add(const stdmath_float4x4* a, const stdmath_float4x4* b) {
	return c(c(*a) + c(*b));
}
stdmath_float4x4 stdmath_float4x4_subtract(const stdmath_float4x4* a, const stdmath_float4x4* b) {
	return c(c(*a) - c(*b));
}
stdmath_float4x4 stdmath_float4x4_negate(const stdmath_float4x4* m) {
	return c(-c(*m));
}

stdmath_float4 stdmath_float4x4_multiply(const stdmath_float4x4* m, stdmath_float4 v) {
	return c(stdmath::float4x4::multiply(c(*m), c(v)));
}

#if 4 == 4
stdmath_float4x4 stdmath_float4x4_scale(const stdmath_float4x4* m, float s) {
	return c(stdmath::float4x4::multiply(c(*m), (stdmath::float4x4::underlying_type)s));
}
stdmath_float4x4 stdmath_float4x4_inverse(const stdmath_float4x4* m) {
	return c(inverse(c(*m)));
}
#endif

#endif // #ifdef STDMATH_IMPLEMENTATION

#endif // __STDMATH_float4x4_H__


#ifdef STDMATH_IMPLEMENTATION

#ifdef __STDMATH_float4x4_H__
#ifndef __STDMATH_float4x4_TRANSPOSE_IMPL__
#define __STDMATH_float4x4_TRANSPOSE_IMPL__
stdmath_float4x4 stdmath_float4x4_transpose(const stdmath_float4x4* m) {
	return c(transpose(c(*m)));
}
#endif
#endif

#ifdef __STDMATH_float4x2_H__
#ifdef __STDMATH_float4x2_H__
#ifndef __STDMATH_float4x4_4x2_IMPL__
#define __STDMATH_float4x4_4x2_IMPL__
stdmath_float4x2 stdmath_float4x4_multiply2(const stdmath_float4x4* a, const stdmath_float4x2* b) {
	return c(stdmath::float4x4::multiply(c(*a), c(*b)));
}
#endif
#endif
#endif

#ifdef __STDMATH_float4x3_H__
#ifdef __STDMATH_float4x3_H__
#ifndef __STDMATH_float4x4_4x3_IMPL__
#define __STDMATH_float4x4_4x3_IMPL__
stdmath_float4x3 stdmath_float4x4_multiply3(const stdmath_float4x4* a, const stdmath_float4x3* b) {
	return c(stdmath::float4x4::multiply(c(*a), c(*b)));
}
#endif
#endif
#endif

#ifdef __STDMATH_float4x4_H__
#ifdef __STDMATH_float4x4_H__
#ifndef __STDMATH_float4x4_4x4_IMPL__
#define __STDMATH_float4x4_4x4_IMPL__
stdmath_float4x4 stdmath_float4x4_multiply4(const stdmath_float4x4* a, const stdmath_float4x4* b) {
	return c(stdmath::float4x4::multiply(c(*a), c(*b)));
}
#endif
#endif
#endif

#endif // STDMATH_IMPLEMENTATION