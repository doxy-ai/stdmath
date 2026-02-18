#ifndef __STDMATH_bool2x3_H__
#define __STDMATH_bool2x3_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "../maybe_export.h"
STDMATH_EXPORT struct stdmath_bool2x2;
STDMATH_EXPORT struct stdmath_bool2x3;
STDMATH_EXPORT struct stdmath_bool2x4;
#if 2 != 3
STDMATH_EXPORT struct stdmath_bool3x2;
STDMATH_EXPORT struct stdmath_bool3x3;
STDMATH_EXPORT struct stdmath_bool3x4;
#endif

#ifdef __cplusplus
} // extern "C"
#endif

#ifndef STDMATH_MODULE
#include <stddef.h>
#endif
#include "bool3.h"

#ifdef __cplusplus
extern "C" {
#endif

struct stdmath_bool2x3 {
	bool data[2 * 3];
};

STDMATH_EXPORT stdmath_bool2x3 stdmath_bool2x3_identity_scaled(bool scale);
STDMATH_EXPORT stdmath_bool2x3 stdmath_bool2x3_identity();
STDMATH_EXPORT stdmath_bool2x3 stdmath_bool2x3_fill(bool value);

STDMATH_EXPORT size_t stdmath_bool2x3_rows(const stdmath_bool2x3* m);
STDMATH_EXPORT inline size_t stdmath_bool2x3_rows_get(const stdmath_bool2x3* m) {
	return stdmath_bool2x3_rows(m);
}
STDMATH_EXPORT size_t stdmath_bool2x3_columns(const stdmath_bool2x3* m);
STDMATH_EXPORT inline size_t stdmath_bool2x3_columns_get(const stdmath_bool2x3* m) {
	return stdmath_bool2x3_columns(m);
}
STDMATH_EXPORT size_t stdmath_bool2x3_size(const stdmath_bool2x3* m);

STDMATH_EXPORT bool stdmath_bool2x3_get_element(const stdmath_bool2x3* m, size_t x, size_t y);
STDMATH_EXPORT stdmath_bool2x3 stdmath_bool2x3_set_element(const stdmath_bool2x3* m, size_t x, size_t y, bool value);

STDMATH_EXPORT stdmath_bool2x3 stdmath_bool2x3_add(const stdmath_bool2x3* a, const stdmath_bool2x3* b);
STDMATH_EXPORT stdmath_bool2x3 stdmath_bool2x3_subtract(const stdmath_bool2x3* a, const stdmath_bool2x3* b);
STDMATH_EXPORT stdmath_bool2x3 stdmath_bool2x3_negate(const stdmath_bool2x3* m);
STDMATH_EXPORT stdmath_bool3x2 stdmath_bool2x3_transpose(const stdmath_bool2x3* m);

STDMATH_EXPORT stdmath_bool2x2 stdmath_bool2x3_multiply2(const stdmath_bool2x3* a, const stdmath_bool3x2* b);
STDMATH_EXPORT stdmath_bool2x3 stdmath_bool2x3_multiply3(const stdmath_bool2x3* a, const stdmath_bool3x3* b);
STDMATH_EXPORT stdmath_bool2x4 stdmath_bool2x3_multiply4(const stdmath_bool2x3* a, const stdmath_bool3x4* b);
STDMATH_EXPORT stdmath_bool3 stdmath_bool2x3_multiply(const stdmath_bool2x3* m, stdmath_bool3 v);

STDMATH_EXPORT bool stdmath_bool2x3_equal_to(const stdmath_bool2x3* a, const stdmath_bool2x3* b);
STDMATH_EXPORT bool stdmath_bool2x3_not_equal_to(const stdmath_bool2x3* a, const stdmath_bool2x3* b);
STDMATH_EXPORT bool stdmath_bool2x3_approximately_equal(stdmath_bool2x3* a, stdmath_bool2x3* b);

#if 2 == 3
STDMATH_EXPORT stdmath_bool2x2 stdmath_bool2x2_scale(const stdmath_bool2x2* m, bool s);
STDMATH_EXPORT stdmath_bool2x2 stdmath_bool2x2_inverse(const stdmath_bool2x2* m);
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

inline stdmath::bool2x3 c(stdmath_bool2x3 c) {
	return (stdmath::bool2x3&)c;
}
inline stdmath_bool2x3 c(stdmath::bool2x3 c) {
	return (stdmath_bool2x3&)c;
}

#ifdef __cplusplus
extern "C" {
#endif

stdmath_bool2x3 stdmath_bool2x3_identity_scaled(bool scale) {
	return c(stdmath::bool2x3::identity((stdmath::bool2x3::underlying_type&)scale));
}
stdmath_bool2x3 stdmath_bool2x3_identity() {
	return c(stdmath::bool2x3::identity());
}
stdmath_bool2x3 stdmath_bool2x3_fill(bool value) {
	return c(stdmath::bool2x3::fill((stdmath::bool2x3::underlying_type&)value));
}

size_t stdmath_bool2x3_rows(const stdmath_bool2x3* m) {
	return 2;
}
size_t stdmath_bool2x3_columns(const stdmath_bool2x3* m) {
	return 3;
}
size_t stdmath_bool2x3_size(const stdmath_bool2x3* m) {
	return 2 * 3;
}

bool stdmath_bool2x3_get_element(const stdmath_bool2x3* m, size_t x, size_t y) {
	return (bool&)c(*m)[x, y];
}
stdmath_bool2x3 stdmath_bool2x3_set_element(const stdmath_bool2x3* m, size_t x, size_t y, bool value) {
	auto out = c(*m);
	out[x, y] = (stdmath::bool2x3::underlying_type&)value;
	return c(out);
}

stdmath_bool2x3 stdmath_bool2x3_add(const stdmath_bool2x3* a, const stdmath_bool2x3* b) {
	return c(c(*a) + c(*b));
}
stdmath_bool2x3 stdmath_bool2x3_subtract(const stdmath_bool2x3* a, const stdmath_bool2x3* b) {
	return c(c(*a) - c(*b));
}
stdmath_bool2x3 stdmath_bool2x3_negate(const stdmath_bool2x3* m) {
	return c(-c(*m));
}

stdmath_bool3 stdmath_bool2x3_multiply(const stdmath_bool2x3* m, stdmath_bool3 v) {
	return c(stdmath::bool2x3::multiply(c(*m), c(v)));
}

bool stdmath_bool2x3_equal_to(const stdmath_bool2x3* a, const stdmath_bool2x3* b) {
	return c(*a) == c(*b);
}
bool stdmath_bool2x3_not_equal_to(const stdmath_bool2x3* a, const stdmath_bool2x3* b) {
	return c(*a) != c(*b);
}
bool stdmath_bool2x3_approximately_equal(stdmath_bool2x3* a, stdmath_bool2x3* b) {
	return stdmath::approximately_equal(c(*a), c(*b));
}

#if 2 == 3
stdmath_bool2x2 stdmath_bool2x2_scale(const stdmath_bool2x2* m, bool s) {
	return c(stdmath::bool2x2::multiply(c(*m), (stdmath::bool2x2::underlying_type&)s));
}
stdmath_bool2x2 stdmath_bool2x2_inverse(const stdmath_bool2x2* m) {
	return c(inverse(c(*m)));
}
#endif

#ifdef __cplusplus
} // extern "C"
#endif

#endif // #ifdef STDMATH_IMPLEMENTATION

#endif // __STDMATH_bool2x3_H__


#ifdef STDMATH_IMPLEMENTATION

#ifdef __cplusplus
extern "C" {
#endif


#ifdef __STDMATH_bool3x2_H__
#ifndef __STDMATH_bool2x3_TRANSPOSE_IMPL__
#define __STDMATH_bool2x3_TRANSPOSE_IMPL__
stdmath_bool3x2 stdmath_bool2x3_transpose(const stdmath_bool2x3* m) {
	return c(transpose(c(*m)));
}
#endif
#endif

#ifdef __STDMATH_bool3x2_H__
#ifdef __STDMATH_bool2x2_H__
#ifndef __STDMATH_bool2x3_2x2_IMPL__
#define __STDMATH_bool2x3_2x2_IMPL__
stdmath_bool2x2 stdmath_bool2x3_multiply2(const stdmath_bool2x3* a, const stdmath_bool3x2* b) {
	return c(stdmath::bool2x3::multiply(c(*a), c(*b)));
}
#endif
#endif
#endif

#ifdef __STDMATH_bool3x3_H__
#ifdef __STDMATH_bool2x3_H__
#ifndef __STDMATH_bool2x3_2x3_IMPL__
#define __STDMATH_bool2x3_2x3_IMPL__
stdmath_bool2x3 stdmath_bool2x3_multiply3(const stdmath_bool2x3* a, const stdmath_bool3x3* b) {
	return c(stdmath::bool2x3::multiply(c(*a), c(*b)));
}
#endif
#endif
#endif

#ifdef __STDMATH_bool3x4_H__
#ifdef __STDMATH_bool2x4_H__
#ifndef __STDMATH_bool2x3_2x4_IMPL__
#define __STDMATH_bool2x3_2x4_IMPL__
stdmath_bool2x4 stdmath_bool2x3_multiply4(const stdmath_bool2x3* a, const stdmath_bool3x4* b) {
	return c(stdmath::bool2x3::multiply(c(*a), c(*b)));
}
#endif
#endif
#endif

#ifdef __cplusplus
} // extern "C"
#endif

#endif // STDMATH_IMPLEMENTATION