#ifndef __STDMATH_int4x2_H__
#define __STDMATH_int4x2_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "../maybe_export.h"
STDMATH_EXPORT struct stdmath_int4x2;
STDMATH_EXPORT struct stdmath_int4x3;
STDMATH_EXPORT struct stdmath_int4x4;
#if 4 != 2
STDMATH_EXPORT struct stdmath_int2x2;
STDMATH_EXPORT struct stdmath_int2x3;
STDMATH_EXPORT struct stdmath_int2x4;
#endif

#ifdef __cplusplus
} // extern "C"
#endif

#ifndef STDMATH_MODULE
#include <stddef.h>
#endif
#include "int2.h"

#ifdef __cplusplus
extern "C" {
#endif

struct stdmath_int4x2 {
	int32_t data[4 * 2];
};

STDMATH_EXPORT stdmath_int4x2 stdmath_int4x2_identity_scaled(int32_t scale);
STDMATH_EXPORT stdmath_int4x2 stdmath_int4x2_identity();
STDMATH_EXPORT stdmath_int4x2 stdmath_int4x2_fill(int32_t value);

STDMATH_EXPORT size_t stdmath_int4x2_rows(const stdmath_int4x2* m);
STDMATH_EXPORT inline size_t stdmath_int4x2_rows_get(const stdmath_int4x2* m) {
	return stdmath_int4x2_rows(m);
}
STDMATH_EXPORT size_t stdmath_int4x2_columns(const stdmath_int4x2* m);
STDMATH_EXPORT inline size_t stdmath_int4x2_columns_get(const stdmath_int4x2* m) {
	return stdmath_int4x2_columns(m);
}
STDMATH_EXPORT size_t stdmath_int4x2_size(const stdmath_int4x2* m);

STDMATH_EXPORT int32_t stdmath_int4x2_get_element(const stdmath_int4x2* m, size_t x, size_t y);
STDMATH_EXPORT stdmath_int4x2 stdmath_int4x2_set_element(const stdmath_int4x2* m, size_t x, size_t y, int32_t value);

STDMATH_EXPORT stdmath_int4x2 stdmath_int4x2_add(const stdmath_int4x2* a, const stdmath_int4x2* b);
STDMATH_EXPORT stdmath_int4x2 stdmath_int4x2_subtract(const stdmath_int4x2* a, const stdmath_int4x2* b);
STDMATH_EXPORT stdmath_int4x2 stdmath_int4x2_negate(const stdmath_int4x2* m);
STDMATH_EXPORT stdmath_int2x4 stdmath_int4x2_transpose(const stdmath_int4x2* m);

STDMATH_EXPORT stdmath_int4x2 stdmath_int4x2_multiply2(const stdmath_int4x2* a, const stdmath_int2x2* b);
STDMATH_EXPORT stdmath_int4x3 stdmath_int4x2_multiply3(const stdmath_int4x2* a, const stdmath_int2x3* b);
STDMATH_EXPORT stdmath_int4x4 stdmath_int4x2_multiply4(const stdmath_int4x2* a, const stdmath_int2x4* b);
STDMATH_EXPORT stdmath_int2 stdmath_int4x2_multiply(const stdmath_int4x2* m, stdmath_int2 v);

STDMATH_EXPORT bool stdmath_int4x2_equal_to(const stdmath_int4x2* a, const stdmath_int4x2* b);
STDMATH_EXPORT bool stdmath_int4x2_not_equal_to(const stdmath_int4x2* a, const stdmath_int4x2* b);
STDMATH_EXPORT bool stdmath_int4x2_approximately_equal(stdmath_int4x2* a, stdmath_int4x2* b);

#if 4 == 2
STDMATH_EXPORT stdmath_int4x4 stdmath_int4x4_scale(const stdmath_int4x4* m, int32_t s);
STDMATH_EXPORT stdmath_int4x4 stdmath_int4x4_inverse(const stdmath_int4x4* m);
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

inline stdmath::int4x2 c(stdmath_int4x2 c) {
	return (stdmath::int4x2&)c;
}
inline stdmath_int4x2 c(stdmath::int4x2 c) {
	return (stdmath_int4x2&)c;
}

#ifdef __cplusplus
extern "C" {
#endif

stdmath_int4x2 stdmath_int4x2_identity_scaled(int32_t scale) {
	return c(stdmath::int4x2::identity((stdmath::int4x2::underlying_type&)scale));
}
stdmath_int4x2 stdmath_int4x2_identity() {
	return c(stdmath::int4x2::identity());
}
stdmath_int4x2 stdmath_int4x2_fill(int32_t value) {
	return c(stdmath::int4x2::fill((stdmath::int4x2::underlying_type&)value));
}

size_t stdmath_int4x2_rows(const stdmath_int4x2* m) {
	return 4;
}
size_t stdmath_int4x2_columns(const stdmath_int4x2* m) {
	return 2;
}
size_t stdmath_int4x2_size(const stdmath_int4x2* m) {
	return 4 * 2;
}

int32_t stdmath_int4x2_get_element(const stdmath_int4x2* m, size_t x, size_t y) {
	return (int32_t&)c(*m)[x, y];
}
stdmath_int4x2 stdmath_int4x2_set_element(const stdmath_int4x2* m, size_t x, size_t y, int32_t value) {
	auto out = c(*m);
	out[x, y] = (stdmath::int4x2::underlying_type&)value;
	return c(out);
}

stdmath_int4x2 stdmath_int4x2_add(const stdmath_int4x2* a, const stdmath_int4x2* b) {
	return c(c(*a) + c(*b));
}
stdmath_int4x2 stdmath_int4x2_subtract(const stdmath_int4x2* a, const stdmath_int4x2* b) {
	return c(c(*a) - c(*b));
}
stdmath_int4x2 stdmath_int4x2_negate(const stdmath_int4x2* m) {
	return c(-c(*m));
}

stdmath_int2 stdmath_int4x2_multiply(const stdmath_int4x2* m, stdmath_int2 v) {
	return c(stdmath::int4x2::multiply(c(*m), c(v)));
}

bool stdmath_int4x2_equal_to(const stdmath_int4x2* a, const stdmath_int4x2* b) {
	return c(*a) == c(*b);
}
bool stdmath_int4x2_not_equal_to(const stdmath_int4x2* a, const stdmath_int4x2* b) {
	return c(*a) != c(*b);
}
bool stdmath_int4x2_approximately_equal(stdmath_int4x2* a, stdmath_int4x2* b) {
	return stdmath::approximately_equal(c(*a), c(*b));
}

#if 4 == 2
stdmath_int4x4 stdmath_int4x4_scale(const stdmath_int4x4* m, int32_t s) {
	return c(stdmath::int4x4::multiply(c(*m), (stdmath::int4x4::underlying_type&)s));
}
stdmath_int4x4 stdmath_int4x4_inverse(const stdmath_int4x4* m) {
	return c(inverse(c(*m)));
}
#endif

#ifdef __cplusplus
} // extern "C"
#endif

#endif // #ifdef STDMATH_IMPLEMENTATION

#endif // __STDMATH_int4x2_H__


#ifdef STDMATH_IMPLEMENTATION

#ifdef __cplusplus
extern "C" {
#endif


#ifdef __STDMATH_int2x4_H__
#ifndef __STDMATH_int4x2_TRANSPOSE_IMPL__
#define __STDMATH_int4x2_TRANSPOSE_IMPL__
stdmath_int2x4 stdmath_int4x2_transpose(const stdmath_int4x2* m) {
	return c(transpose(c(*m)));
}
#endif
#endif

#ifdef __STDMATH_int2x2_H__
#ifdef __STDMATH_int4x2_H__
#ifndef __STDMATH_int4x2_4x2_IMPL__
#define __STDMATH_int4x2_4x2_IMPL__
stdmath_int4x2 stdmath_int4x2_multiply2(const stdmath_int4x2* a, const stdmath_int2x2* b) {
	return c(stdmath::int4x2::multiply(c(*a), c(*b)));
}
#endif
#endif
#endif

#ifdef __STDMATH_int2x3_H__
#ifdef __STDMATH_int4x3_H__
#ifndef __STDMATH_int4x2_4x3_IMPL__
#define __STDMATH_int4x2_4x3_IMPL__
stdmath_int4x3 stdmath_int4x2_multiply3(const stdmath_int4x2* a, const stdmath_int2x3* b) {
	return c(stdmath::int4x2::multiply(c(*a), c(*b)));
}
#endif
#endif
#endif

#ifdef __STDMATH_int2x4_H__
#ifdef __STDMATH_int4x4_H__
#ifndef __STDMATH_int4x2_4x4_IMPL__
#define __STDMATH_int4x2_4x4_IMPL__
stdmath_int4x4 stdmath_int4x2_multiply4(const stdmath_int4x2* a, const stdmath_int2x4* b) {
	return c(stdmath::int4x2::multiply(c(*a), c(*b)));
}
#endif
#endif
#endif

#ifdef __cplusplus
} // extern "C"
#endif

#endif // STDMATH_IMPLEMENTATION