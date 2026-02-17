#ifndef __STDMATH_float3x2_H__
#define __STDMATH_float3x2_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "../maybe_export.h"
STDMATH_EXPORT struct stdmath_float3x2;
STDMATH_EXPORT struct stdmath_float3x3;
STDMATH_EXPORT struct stdmath_float3x4;
#if 3 != 2
STDMATH_EXPORT struct stdmath_float2x2;
STDMATH_EXPORT struct stdmath_float2x3;
STDMATH_EXPORT struct stdmath_float2x4;
#endif

#ifdef __cplusplus
} // extern "C"
#endif

#ifndef STDMATH_MODULE
#include <stddef.h>
#endif
#include "float2.h"

#ifdef __cplusplus
extern "C" {
#endif

struct stdmath_float3x2 {
	float data[3 * 2];
};

STDMATH_EXPORT stdmath_float3x2 stdmath_float3x2_identity_scaled(float scale);
STDMATH_EXPORT stdmath_float3x2 stdmath_float3x2_identity();
STDMATH_EXPORT stdmath_float3x2 stdmath_float3x2_fill(float value);

STDMATH_EXPORT size_t stdmath_float3x2_rows(const stdmath_float3x2* m);
STDMATH_EXPORT inline size_t stdmath_float3x2_rows_get(const stdmath_float3x2* m) {
	return stdmath_float3x2_rows(m);
}
STDMATH_EXPORT size_t stdmath_float3x2_columns(const stdmath_float3x2* m);
STDMATH_EXPORT inline size_t stdmath_float3x2_columns_get(const stdmath_float3x2* m) {
	return stdmath_float3x2_columns(m);
}
STDMATH_EXPORT size_t stdmath_float3x2_size(const stdmath_float3x2* m);

STDMATH_EXPORT float stdmath_float3x2_get_element(const stdmath_float3x2* m, size_t x, size_t y);
STDMATH_EXPORT stdmath_float3x2 stdmath_float3x2_set_element(const stdmath_float3x2* m, size_t x, size_t y, float value);

STDMATH_EXPORT stdmath_float3x2 stdmath_float3x2_add(const stdmath_float3x2* a, const stdmath_float3x2* b);
STDMATH_EXPORT stdmath_float3x2 stdmath_float3x2_subtract(const stdmath_float3x2* a, const stdmath_float3x2* b);
STDMATH_EXPORT stdmath_float3x2 stdmath_float3x2_negate(const stdmath_float3x2* m);
STDMATH_EXPORT stdmath_float2x3 stdmath_float3x2_transpose(const stdmath_float3x2* m);

STDMATH_EXPORT stdmath_float3x2 stdmath_float3x2_multiply2(const stdmath_float3x2* a, const stdmath_float2x2* b);
STDMATH_EXPORT stdmath_float3x3 stdmath_float3x2_multiply3(const stdmath_float3x2* a, const stdmath_float2x3* b);
STDMATH_EXPORT stdmath_float3x4 stdmath_float3x2_multiply4(const stdmath_float3x2* a, const stdmath_float2x4* b);
STDMATH_EXPORT stdmath_float2 stdmath_float3x2_multiply(const stdmath_float3x2* m, stdmath_float2 v);

#if 3 == 2
STDMATH_EXPORT stdmath_float3x3 stdmath_float3x3_scale(const stdmath_float3x3* m, float s);
STDMATH_EXPORT stdmath_float3x3 stdmath_float3x3_inverse(const stdmath_float3x3* m);
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

inline stdmath::float3x2 c(stdmath_float3x2 c) {
	return (stdmath::float3x2&)c;
}
inline stdmath_float3x2 c(stdmath::float3x2 c) {
	return (stdmath_float3x2&)c;
}

#ifdef __cplusplus
extern "C" {
#endif

stdmath_float3x2 stdmath_float3x2_identity_scaled(float scale) {
	return c(stdmath::float3x2::identity((stdmath::float3x2::underlying_type)scale));
}
stdmath_float3x2 stdmath_float3x2_identity() {
	return c(stdmath::float3x2::identity());
}
stdmath_float3x2 stdmath_float3x2_fill(float value) {
	return c(stdmath::float3x2::fill((stdmath::float3x2::underlying_type)value));
}

size_t stdmath_float3x2_rows(const stdmath_float3x2* m) {
	return 3;
}
size_t stdmath_float3x2_columns(const stdmath_float3x2* m) {
	return 2;
}
size_t stdmath_float3x2_size(const stdmath_float3x2* m) {
	return 3 * 2;
}

float stdmath_float3x2_get_element(const stdmath_float3x2* m, size_t x, size_t y) {
	return c(*m)[x, y];
}
stdmath_float3x2 stdmath_float3x2_set_element(const stdmath_float3x2* m, size_t x, size_t y, float value) {
	auto out = c(*m);
	out[x, y] = (stdmath::float3x2::underlying_type)value;
	return c(out);
}

stdmath_float3x2 stdmath_float3x2_add(const stdmath_float3x2* a, const stdmath_float3x2* b) {
	return c(c(*a) + c(*b));
}
stdmath_float3x2 stdmath_float3x2_subtract(const stdmath_float3x2* a, const stdmath_float3x2* b) {
	return c(c(*a) - c(*b));
}
stdmath_float3x2 stdmath_float3x2_negate(const stdmath_float3x2* m) {
	return c(-c(*m));
}

stdmath_float2 stdmath_float3x2_multiply(const stdmath_float3x2* m, stdmath_float2 v) {
	return c(stdmath::float3x2::multiply(c(*m), c(v)));
}

#if 3 == 2
stdmath_float3x3 stdmath_float3x3_scale(const stdmath_float3x3* m, float s) {
	return c(stdmath::float3x3::multiply(c(*m), (stdmath::float3x3::underlying_type)s));
}
stdmath_float3x3 stdmath_float3x3_inverse(const stdmath_float3x3* m) {
	return c(inverse(c(*m)));
}
#endif

#ifdef __cplusplus
} // extern "C"
#endif

#endif // #ifdef STDMATH_IMPLEMENTATION

#endif // __STDMATH_float3x2_H__


#ifdef STDMATH_IMPLEMENTATION

#ifdef __cplusplus
extern "C" {
#endif


#ifdef __STDMATH_float2x3_H__
#ifndef __STDMATH_float3x2_TRANSPOSE_IMPL__
#define __STDMATH_float3x2_TRANSPOSE_IMPL__
stdmath_float2x3 stdmath_float3x2_transpose(const stdmath_float3x2* m) {
	return c(transpose(c(*m)));
}
#endif
#endif

#ifdef __STDMATH_float2x2_H__
#ifdef __STDMATH_float3x2_H__
#ifndef __STDMATH_float3x2_3x2_IMPL__
#define __STDMATH_float3x2_3x2_IMPL__
stdmath_float3x2 stdmath_float3x2_multiply2(const stdmath_float3x2* a, const stdmath_float2x2* b) {
	return c(stdmath::float3x2::multiply(c(*a), c(*b)));
}
#endif
#endif
#endif

#ifdef __STDMATH_float2x3_H__
#ifdef __STDMATH_float3x3_H__
#ifndef __STDMATH_float3x2_3x3_IMPL__
#define __STDMATH_float3x2_3x3_IMPL__
stdmath_float3x3 stdmath_float3x2_multiply3(const stdmath_float3x2* a, const stdmath_float2x3* b) {
	return c(stdmath::float3x2::multiply(c(*a), c(*b)));
}
#endif
#endif
#endif

#ifdef __STDMATH_float2x4_H__
#ifdef __STDMATH_float3x4_H__
#ifndef __STDMATH_float3x2_3x4_IMPL__
#define __STDMATH_float3x2_3x4_IMPL__
stdmath_float3x4 stdmath_float3x2_multiply4(const stdmath_float3x2* a, const stdmath_float2x4* b) {
	return c(stdmath::float3x2::multiply(c(*a), c(*b)));
}
#endif
#endif
#endif

#ifdef __cplusplus
} // extern "C"
#endif

#endif // STDMATH_IMPLEMENTATION