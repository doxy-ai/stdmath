#ifndef __STDMATH_float2x3_H__
#define __STDMATH_float2x3_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "../maybe_export.h"
STDMATH_EXPORT struct stdmath_float2x2;
STDMATH_EXPORT struct stdmath_float2x3;
STDMATH_EXPORT struct stdmath_float2x4;
#if 2 != 3
STDMATH_EXPORT struct stdmath_float3x2;
STDMATH_EXPORT struct stdmath_float3x3;
STDMATH_EXPORT struct stdmath_float3x4;
#endif

#ifdef __cplusplus
} // extern "C"
#endif

#ifndef STDMATH_MODULE
#include <stddef.h>
#endif
#include "float3.h"

#ifdef __cplusplus
extern "C" {
#endif

struct stdmath_float2x3 {
	float data[2 * 3];
};

STDMATH_EXPORT stdmath_float2x3 stdmath_float2x3_identity_scaled(float scale);
STDMATH_EXPORT stdmath_float2x3 stdmath_float2x3_identity();
STDMATH_EXPORT stdmath_float2x3 stdmath_float2x3_fill(float value);

STDMATH_EXPORT size_t stdmath_float2x3_rows(const stdmath_float2x3* m);
STDMATH_EXPORT inline size_t stdmath_float2x3_rows_get(const stdmath_float2x3* m) {
	return stdmath_float2x3_rows(m);
}
STDMATH_EXPORT size_t stdmath_float2x3_columns(const stdmath_float2x3* m);
STDMATH_EXPORT inline size_t stdmath_float2x3_columns_get(const stdmath_float2x3* m) {
	return stdmath_float2x3_columns(m);
}
STDMATH_EXPORT size_t stdmath_float2x3_size(const stdmath_float2x3* m);

STDMATH_EXPORT float stdmath_float2x3_get_element(const stdmath_float2x3* m, size_t x, size_t y);
STDMATH_EXPORT stdmath_float2x3 stdmath_float2x3_set_element(const stdmath_float2x3* m, size_t x, size_t y, float value);

STDMATH_EXPORT stdmath_float2x3 stdmath_float2x3_add(const stdmath_float2x3* a, const stdmath_float2x3* b);
STDMATH_EXPORT stdmath_float2x3 stdmath_float2x3_subtract(const stdmath_float2x3* a, const stdmath_float2x3* b);
STDMATH_EXPORT stdmath_float2x3 stdmath_float2x3_negate(const stdmath_float2x3* m);
STDMATH_EXPORT stdmath_float3x2 stdmath_float2x3_transpose(const stdmath_float2x3* m);

STDMATH_EXPORT stdmath_float2x2 stdmath_float2x3_multiply2(const stdmath_float2x3* a, const stdmath_float3x2* b);
STDMATH_EXPORT stdmath_float2x3 stdmath_float2x3_multiply3(const stdmath_float2x3* a, const stdmath_float3x3* b);
STDMATH_EXPORT stdmath_float2x4 stdmath_float2x3_multiply4(const stdmath_float2x3* a, const stdmath_float3x4* b);
STDMATH_EXPORT stdmath_float3 stdmath_float2x3_multiply(const stdmath_float2x3* m, stdmath_float3 v);

STDMATH_EXPORT bool stdmath_float2x3_equal_to(const stdmath_float2x3* a, const stdmath_float2x3* b);
STDMATH_EXPORT bool stdmath_float2x3_not_equal_to(const stdmath_float2x3* a, const stdmath_float2x3* b);
STDMATH_EXPORT bool stdmath_float2x3_approximately_equal(stdmath_float2x3* a, stdmath_float2x3* b);

#if 2 == 3
STDMATH_EXPORT stdmath_float2x2 stdmath_float2x2_scale(const stdmath_float2x2* m, float s);
STDMATH_EXPORT stdmath_float2x2 stdmath_float2x2_inverse(const stdmath_float2x2* m);
#endif

#ifdef __cplusplus
} // extern "C"
#endif

#ifdef STDMATH_IMPLEMENTATION
#ifndef __cplusplus
#error "The stdmath implementations require a C++ compiler"
#endif

#ifndef STDMATH_MODULE
import stdmath.slang;
#endif

inline stdmath::float2x3 c(stdmath_float2x3 c) {
	return (stdmath::float2x3&)c;
}
inline stdmath_float2x3 c(stdmath::float2x3 c) {
	return (stdmath_float2x3&)c;
}

#ifdef __cplusplus
extern "C" {
#endif

stdmath_float2x3 stdmath_float2x3_identity_scaled(float scale) {
	return c(stdmath::float2x3::identity((stdmath::float2x3::underlying_type&)scale));
}
stdmath_float2x3 stdmath_float2x3_identity() {
	return c(stdmath::float2x3::identity());
}
stdmath_float2x3 stdmath_float2x3_fill(float value) {
	return c(stdmath::float2x3::fill((stdmath::float2x3::underlying_type&)value));
}

size_t stdmath_float2x3_rows(const stdmath_float2x3* m) {
	return 2;
}
size_t stdmath_float2x3_columns(const stdmath_float2x3* m) {
	return 3;
}
size_t stdmath_float2x3_size(const stdmath_float2x3* m) {
	return 2 * 3;
}

float stdmath_float2x3_get_element(const stdmath_float2x3* m, size_t x, size_t y) {
	return (float&)c(*m)[x, y];
}
stdmath_float2x3 stdmath_float2x3_set_element(const stdmath_float2x3* m, size_t x, size_t y, float value) {
	auto out = c(*m);
	out[x, y] = (stdmath::float2x3::underlying_type&)value;
	return c(out);
}

stdmath_float2x3 stdmath_float2x3_add(const stdmath_float2x3* a, const stdmath_float2x3* b) {
	return c(c(*a) + c(*b));
}
stdmath_float2x3 stdmath_float2x3_subtract(const stdmath_float2x3* a, const stdmath_float2x3* b) {
	return c(c(*a) - c(*b));
}
stdmath_float2x3 stdmath_float2x3_negate(const stdmath_float2x3* m) {
	return c(-c(*m));
}

stdmath_float3 stdmath_float2x3_multiply(const stdmath_float2x3* m, stdmath_float3 v) {
	return c(stdmath::float2x3::multiply(c(*m), c(v)));
}

bool stdmath_float2x3_equal_to(const stdmath_float2x3* a, const stdmath_float2x3* b) {
	return c(*a) == c(*b);
}
bool stdmath_float2x3_not_equal_to(const stdmath_float2x3* a, const stdmath_float2x3* b) {
	return c(*a) != c(*b);
}
bool stdmath_float2x3_approximately_equal(stdmath_float2x3* a, stdmath_float2x3* b) {
	return stdmath::approximately_equal(c(*a), c(*b));
}

#if 2 == 3
stdmath_float2x2 stdmath_float2x2_scale(const stdmath_float2x2* m, float s) {
	return c(stdmath::float2x2::multiply(c(*m), (stdmath::float2x2::underlying_type&)s));
}
stdmath_float2x2 stdmath_float2x2_inverse(const stdmath_float2x2* m) {
	return c(inverse(c(*m)));
}
#endif

#ifdef __cplusplus
} // extern "C"
#endif

#endif // #ifdef STDMATH_IMPLEMENTATION

#endif // __STDMATH_float2x3_H__


#ifdef STDMATH_IMPLEMENTATION

#ifdef __cplusplus
extern "C" {
#endif


#ifdef __STDMATH_float3x2_H__
#ifndef __STDMATH_float2x3_TRANSPOSE_IMPL__
#define __STDMATH_float2x3_TRANSPOSE_IMPL__
stdmath_float3x2 stdmath_float2x3_transpose(const stdmath_float2x3* m) {
	return c(transpose(c(*m)));
}
#endif
#endif

#ifdef __STDMATH_float3x2_H__
#ifdef __STDMATH_float2x2_H__
#ifndef __STDMATH_float2x3_2x2_IMPL__
#define __STDMATH_float2x3_2x2_IMPL__
stdmath_float2x2 stdmath_float2x3_multiply2(const stdmath_float2x3* a, const stdmath_float3x2* b) {
	return c(stdmath::float2x3::multiply(c(*a), c(*b)));
}
#endif
#endif
#endif

#ifdef __STDMATH_float3x3_H__
#ifdef __STDMATH_float2x3_H__
#ifndef __STDMATH_float2x3_2x3_IMPL__
#define __STDMATH_float2x3_2x3_IMPL__
stdmath_float2x3 stdmath_float2x3_multiply3(const stdmath_float2x3* a, const stdmath_float3x3* b) {
	return c(stdmath::float2x3::multiply(c(*a), c(*b)));
}
#endif
#endif
#endif

#ifdef __STDMATH_float3x4_H__
#ifdef __STDMATH_float2x4_H__
#ifndef __STDMATH_float2x3_2x4_IMPL__
#define __STDMATH_float2x3_2x4_IMPL__
stdmath_float2x4 stdmath_float2x3_multiply4(const stdmath_float2x3* a, const stdmath_float3x4* b) {
	return c(stdmath::float2x3::multiply(c(*a), c(*b)));
}
#endif
#endif
#endif

#ifdef __cplusplus
} // extern "C"
#endif

#endif // STDMATH_IMPLEMENTATION