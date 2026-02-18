#ifndef __STDMATH_byte4x3_H__
#define __STDMATH_byte4x3_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "../maybe_export.h"
STDMATH_EXPORT struct stdmath_byte4x2;
STDMATH_EXPORT struct stdmath_byte4x3;
STDMATH_EXPORT struct stdmath_byte4x4;
#if 4 != 3
STDMATH_EXPORT struct stdmath_byte3x2;
STDMATH_EXPORT struct stdmath_byte3x3;
STDMATH_EXPORT struct stdmath_byte3x4;
#endif

#ifdef __cplusplus
} // extern "C"
#endif

#ifndef STDMATH_MODULE
#include <stddef.h>
#endif
#include "byte3.h"

#ifdef __cplusplus
extern "C" {
#endif

struct stdmath_byte4x3 {
	uint8_t data[4 * 3];
};

STDMATH_EXPORT stdmath_byte4x3 stdmath_byte4x3_identity_scaled(uint8_t scale);
STDMATH_EXPORT stdmath_byte4x3 stdmath_byte4x3_identity();
STDMATH_EXPORT stdmath_byte4x3 stdmath_byte4x3_fill(uint8_t value);

STDMATH_EXPORT size_t stdmath_byte4x3_rows(const stdmath_byte4x3* m);
STDMATH_EXPORT inline size_t stdmath_byte4x3_rows_get(const stdmath_byte4x3* m) {
	return stdmath_byte4x3_rows(m);
}
STDMATH_EXPORT size_t stdmath_byte4x3_columns(const stdmath_byte4x3* m);
STDMATH_EXPORT inline size_t stdmath_byte4x3_columns_get(const stdmath_byte4x3* m) {
	return stdmath_byte4x3_columns(m);
}
STDMATH_EXPORT size_t stdmath_byte4x3_size(const stdmath_byte4x3* m);

STDMATH_EXPORT uint8_t stdmath_byte4x3_get_element(const stdmath_byte4x3* m, size_t x, size_t y);
STDMATH_EXPORT stdmath_byte4x3 stdmath_byte4x3_set_element(const stdmath_byte4x3* m, size_t x, size_t y, uint8_t value);

STDMATH_EXPORT stdmath_byte4x3 stdmath_byte4x3_add(const stdmath_byte4x3* a, const stdmath_byte4x3* b);
STDMATH_EXPORT stdmath_byte4x3 stdmath_byte4x3_subtract(const stdmath_byte4x3* a, const stdmath_byte4x3* b);
STDMATH_EXPORT stdmath_byte4x3 stdmath_byte4x3_negate(const stdmath_byte4x3* m);
STDMATH_EXPORT stdmath_byte3x4 stdmath_byte4x3_transpose(const stdmath_byte4x3* m);

STDMATH_EXPORT stdmath_byte4x2 stdmath_byte4x3_multiply2(const stdmath_byte4x3* a, const stdmath_byte3x2* b);
STDMATH_EXPORT stdmath_byte4x3 stdmath_byte4x3_multiply3(const stdmath_byte4x3* a, const stdmath_byte3x3* b);
STDMATH_EXPORT stdmath_byte4x4 stdmath_byte4x3_multiply4(const stdmath_byte4x3* a, const stdmath_byte3x4* b);
STDMATH_EXPORT stdmath_byte3 stdmath_byte4x3_multiply(const stdmath_byte4x3* m, stdmath_byte3 v);

STDMATH_EXPORT bool stdmath_byte4x3_equal_to(const stdmath_byte4x3* a, const stdmath_byte4x3* b);
STDMATH_EXPORT bool stdmath_byte4x3_not_equal_to(const stdmath_byte4x3* a, const stdmath_byte4x3* b);
STDMATH_EXPORT bool stdmath_byte4x3_approximately_equal(stdmath_byte4x3* a, stdmath_byte4x3* b);

#if 4 == 3
STDMATH_EXPORT stdmath_byte4x4 stdmath_byte4x4_scale(const stdmath_byte4x4* m, uint8_t s);
STDMATH_EXPORT stdmath_byte4x4 stdmath_byte4x4_inverse(const stdmath_byte4x4* m);
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

inline stdmath::byte4x3 c(stdmath_byte4x3 c) {
	return (stdmath::byte4x3&)c;
}
inline stdmath_byte4x3 c(stdmath::byte4x3 c) {
	return (stdmath_byte4x3&)c;
}

#ifdef __cplusplus
extern "C" {
#endif

stdmath_byte4x3 stdmath_byte4x3_identity_scaled(uint8_t scale) {
	return c(stdmath::byte4x3::identity((stdmath::byte4x3::underlying_type&)scale));
}
stdmath_byte4x3 stdmath_byte4x3_identity() {
	return c(stdmath::byte4x3::identity());
}
stdmath_byte4x3 stdmath_byte4x3_fill(uint8_t value) {
	return c(stdmath::byte4x3::fill((stdmath::byte4x3::underlying_type&)value));
}

size_t stdmath_byte4x3_rows(const stdmath_byte4x3* m) {
	return 4;
}
size_t stdmath_byte4x3_columns(const stdmath_byte4x3* m) {
	return 3;
}
size_t stdmath_byte4x3_size(const stdmath_byte4x3* m) {
	return 4 * 3;
}

uint8_t stdmath_byte4x3_get_element(const stdmath_byte4x3* m, size_t x, size_t y) {
	return (uint8_t&)c(*m)[x, y];
}
stdmath_byte4x3 stdmath_byte4x3_set_element(const stdmath_byte4x3* m, size_t x, size_t y, uint8_t value) {
	auto out = c(*m);
	out[x, y] = (stdmath::byte4x3::underlying_type&)value;
	return c(out);
}

stdmath_byte4x3 stdmath_byte4x3_add(const stdmath_byte4x3* a, const stdmath_byte4x3* b) {
	return c(c(*a) + c(*b));
}
stdmath_byte4x3 stdmath_byte4x3_subtract(const stdmath_byte4x3* a, const stdmath_byte4x3* b) {
	return c(c(*a) - c(*b));
}
stdmath_byte4x3 stdmath_byte4x3_negate(const stdmath_byte4x3* m) {
	return c(-c(*m));
}

stdmath_byte3 stdmath_byte4x3_multiply(const stdmath_byte4x3* m, stdmath_byte3 v) {
	return c(stdmath::byte4x3::multiply(c(*m), c(v)));
}

bool stdmath_byte4x3_equal_to(const stdmath_byte4x3* a, const stdmath_byte4x3* b) {
	return c(*a) == c(*b);
}
bool stdmath_byte4x3_not_equal_to(const stdmath_byte4x3* a, const stdmath_byte4x3* b) {
	return c(*a) != c(*b);
}
bool stdmath_byte4x3_approximately_equal(stdmath_byte4x3* a, stdmath_byte4x3* b) {
	return stdmath::approximately_equal(c(*a), c(*b));
}

#if 4 == 3
stdmath_byte4x4 stdmath_byte4x4_scale(const stdmath_byte4x4* m, uint8_t s) {
	return c(stdmath::byte4x4::multiply(c(*m), (stdmath::byte4x4::underlying_type&)s));
}
stdmath_byte4x4 stdmath_byte4x4_inverse(const stdmath_byte4x4* m) {
	return c(inverse(c(*m)));
}
#endif

#ifdef __cplusplus
} // extern "C"
#endif

#endif // #ifdef STDMATH_IMPLEMENTATION

#endif // __STDMATH_byte4x3_H__


#ifdef STDMATH_IMPLEMENTATION

#ifdef __cplusplus
extern "C" {
#endif


#ifdef __STDMATH_byte3x4_H__
#ifndef __STDMATH_byte4x3_TRANSPOSE_IMPL__
#define __STDMATH_byte4x3_TRANSPOSE_IMPL__
stdmath_byte3x4 stdmath_byte4x3_transpose(const stdmath_byte4x3* m) {
	return c(transpose(c(*m)));
}
#endif
#endif

#ifdef __STDMATH_byte3x2_H__
#ifdef __STDMATH_byte4x2_H__
#ifndef __STDMATH_byte4x3_4x2_IMPL__
#define __STDMATH_byte4x3_4x2_IMPL__
stdmath_byte4x2 stdmath_byte4x3_multiply2(const stdmath_byte4x3* a, const stdmath_byte3x2* b) {
	return c(stdmath::byte4x3::multiply(c(*a), c(*b)));
}
#endif
#endif
#endif

#ifdef __STDMATH_byte3x3_H__
#ifdef __STDMATH_byte4x3_H__
#ifndef __STDMATH_byte4x3_4x3_IMPL__
#define __STDMATH_byte4x3_4x3_IMPL__
stdmath_byte4x3 stdmath_byte4x3_multiply3(const stdmath_byte4x3* a, const stdmath_byte3x3* b) {
	return c(stdmath::byte4x3::multiply(c(*a), c(*b)));
}
#endif
#endif
#endif

#ifdef __STDMATH_byte3x4_H__
#ifdef __STDMATH_byte4x4_H__
#ifndef __STDMATH_byte4x3_4x4_IMPL__
#define __STDMATH_byte4x3_4x4_IMPL__
stdmath_byte4x4 stdmath_byte4x3_multiply4(const stdmath_byte4x3* a, const stdmath_byte3x4* b) {
	return c(stdmath::byte4x3::multiply(c(*a), c(*b)));
}
#endif
#endif
#endif

#ifdef __cplusplus
} // extern "C"
#endif

#endif // STDMATH_IMPLEMENTATION