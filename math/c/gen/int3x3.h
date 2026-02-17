#ifndef __STDMATH_int3x3_H__
#define __STDMATH_int3x3_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "../maybe_export.h"
STDMATH_EXPORT struct stdmath_int3x2;
STDMATH_EXPORT struct stdmath_int3x3;
STDMATH_EXPORT struct stdmath_int3x4;
#if 3 != 3
STDMATH_EXPORT struct stdmath_int3x2;
STDMATH_EXPORT struct stdmath_int3x3;
STDMATH_EXPORT struct stdmath_int3x4;
#endif

#ifdef __cplusplus
} // extern "C"
#endif

#ifndef STDMATH_MODULE
#include <stddef.h>
#endif
#include "int3.h"

#ifdef __cplusplus
extern "C" {
#endif

struct stdmath_int3x3 {
	int32_t data[3 * 3];
};

STDMATH_EXPORT stdmath_int3x3 stdmath_int3x3_identity_scaled(int32_t scale);
STDMATH_EXPORT stdmath_int3x3 stdmath_int3x3_identity();
STDMATH_EXPORT stdmath_int3x3 stdmath_int3x3_fill(int32_t value);

STDMATH_EXPORT size_t stdmath_int3x3_rows(const stdmath_int3x3* m);
STDMATH_EXPORT inline size_t stdmath_int3x3_rows_get(const stdmath_int3x3* m) {
	return stdmath_int3x3_rows(m);
}
STDMATH_EXPORT size_t stdmath_int3x3_columns(const stdmath_int3x3* m);
STDMATH_EXPORT inline size_t stdmath_int3x3_columns_get(const stdmath_int3x3* m) {
	return stdmath_int3x3_columns(m);
}
STDMATH_EXPORT size_t stdmath_int3x3_size(const stdmath_int3x3* m);

STDMATH_EXPORT int32_t stdmath_int3x3_get_element(const stdmath_int3x3* m, size_t x, size_t y);
STDMATH_EXPORT stdmath_int3x3 stdmath_int3x3_set_element(const stdmath_int3x3* m, size_t x, size_t y, int32_t value);

STDMATH_EXPORT stdmath_int3x3 stdmath_int3x3_add(const stdmath_int3x3* a, const stdmath_int3x3* b);
STDMATH_EXPORT stdmath_int3x3 stdmath_int3x3_subtract(const stdmath_int3x3* a, const stdmath_int3x3* b);
STDMATH_EXPORT stdmath_int3x3 stdmath_int3x3_negate(const stdmath_int3x3* m);
STDMATH_EXPORT stdmath_int3x3 stdmath_int3x3_transpose(const stdmath_int3x3* m);

STDMATH_EXPORT stdmath_int3x2 stdmath_int3x3_multiply2(const stdmath_int3x3* a, const stdmath_int3x2* b);
STDMATH_EXPORT stdmath_int3x3 stdmath_int3x3_multiply3(const stdmath_int3x3* a, const stdmath_int3x3* b);
STDMATH_EXPORT stdmath_int3x4 stdmath_int3x3_multiply4(const stdmath_int3x3* a, const stdmath_int3x4* b);
STDMATH_EXPORT stdmath_int3 stdmath_int3x3_multiply(const stdmath_int3x3* m, stdmath_int3 v);

#if 3 == 3
STDMATH_EXPORT stdmath_int3x3 stdmath_int3x3_scale(const stdmath_int3x3* m, int32_t s);
STDMATH_EXPORT stdmath_int3x3 stdmath_int3x3_inverse(const stdmath_int3x3* m);
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

inline stdmath::int3x3 c(stdmath_int3x3 c) {
	return (stdmath::int3x3&)c;
}
inline stdmath_int3x3 c(stdmath::int3x3 c) {
	return (stdmath_int3x3&)c;
}

#ifdef __cplusplus
extern "C" {
#endif

stdmath_int3x3 stdmath_int3x3_identity_scaled(int32_t scale) {
	return c(stdmath::int3x3::identity((stdmath::int3x3::underlying_type)scale));
}
stdmath_int3x3 stdmath_int3x3_identity() {
	return c(stdmath::int3x3::identity());
}
stdmath_int3x3 stdmath_int3x3_fill(int32_t value) {
	return c(stdmath::int3x3::fill((stdmath::int3x3::underlying_type)value));
}

size_t stdmath_int3x3_rows(const stdmath_int3x3* m) {
	return 3;
}
size_t stdmath_int3x3_columns(const stdmath_int3x3* m) {
	return 3;
}
size_t stdmath_int3x3_size(const stdmath_int3x3* m) {
	return 3 * 3;
}

int32_t stdmath_int3x3_get_element(const stdmath_int3x3* m, size_t x, size_t y) {
	return c(*m)[x, y];
}
stdmath_int3x3 stdmath_int3x3_set_element(const stdmath_int3x3* m, size_t x, size_t y, int32_t value) {
	auto out = c(*m);
	out[x, y] = (stdmath::int3x3::underlying_type)value;
	return c(out);
}

stdmath_int3x3 stdmath_int3x3_add(const stdmath_int3x3* a, const stdmath_int3x3* b) {
	return c(c(*a) + c(*b));
}
stdmath_int3x3 stdmath_int3x3_subtract(const stdmath_int3x3* a, const stdmath_int3x3* b) {
	return c(c(*a) - c(*b));
}
stdmath_int3x3 stdmath_int3x3_negate(const stdmath_int3x3* m) {
	return c(-c(*m));
}

stdmath_int3 stdmath_int3x3_multiply(const stdmath_int3x3* m, stdmath_int3 v) {
	return c(stdmath::int3x3::multiply(c(*m), c(v)));
}

#if 3 == 3
stdmath_int3x3 stdmath_int3x3_scale(const stdmath_int3x3* m, int32_t s) {
	return c(stdmath::int3x3::multiply(c(*m), (stdmath::int3x3::underlying_type)s));
}
stdmath_int3x3 stdmath_int3x3_inverse(const stdmath_int3x3* m) {
	return c(inverse(c(*m)));
}
#endif

#ifdef __cplusplus
} // extern "C"
#endif

#endif // #ifdef STDMATH_IMPLEMENTATION

#endif // __STDMATH_int3x3_H__


#ifdef STDMATH_IMPLEMENTATION

#ifdef __cplusplus
extern "C" {
#endif


#ifdef __STDMATH_int3x3_H__
#ifndef __STDMATH_int3x3_TRANSPOSE_IMPL__
#define __STDMATH_int3x3_TRANSPOSE_IMPL__
stdmath_int3x3 stdmath_int3x3_transpose(const stdmath_int3x3* m) {
	return c(transpose(c(*m)));
}
#endif
#endif

#ifdef __STDMATH_int3x2_H__
#ifdef __STDMATH_int3x2_H__
#ifndef __STDMATH_int3x3_3x2_IMPL__
#define __STDMATH_int3x3_3x2_IMPL__
stdmath_int3x2 stdmath_int3x3_multiply2(const stdmath_int3x3* a, const stdmath_int3x2* b) {
	return c(stdmath::int3x3::multiply(c(*a), c(*b)));
}
#endif
#endif
#endif

#ifdef __STDMATH_int3x3_H__
#ifdef __STDMATH_int3x3_H__
#ifndef __STDMATH_int3x3_3x3_IMPL__
#define __STDMATH_int3x3_3x3_IMPL__
stdmath_int3x3 stdmath_int3x3_multiply3(const stdmath_int3x3* a, const stdmath_int3x3* b) {
	return c(stdmath::int3x3::multiply(c(*a), c(*b)));
}
#endif
#endif
#endif

#ifdef __STDMATH_int3x4_H__
#ifdef __STDMATH_int3x4_H__
#ifndef __STDMATH_int3x3_3x4_IMPL__
#define __STDMATH_int3x3_3x4_IMPL__
stdmath_int3x4 stdmath_int3x3_multiply4(const stdmath_int3x3* a, const stdmath_int3x4* b) {
	return c(stdmath::int3x3::multiply(c(*a), c(*b)));
}
#endif
#endif
#endif

#ifdef __cplusplus
} // extern "C"
#endif

#endif // STDMATH_IMPLEMENTATION