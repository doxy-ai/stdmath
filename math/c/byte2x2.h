#ifndef __STDMATH_byte2x2_H__
#define __STDMATH_byte2x2_H__

struct stdmath_byte2x2;
struct stdmath_byte2x3;
struct stdmath_byte2x4;
#if 2 != 2
struct stdmath_byte2x2;
struct stdmath_byte2x3;
struct stdmath_byte2x4;
#endif

#include <stddef.h>
#include "byte2.h"

struct stdmath_byte2x2 {
	uint8_t data[2 * 2];
};

stdmath_byte2x2 stdmath_byte2x2_identity_scaled(uint8_t scale);
stdmath_byte2x2 stdmath_byte2x2_identity();
stdmath_byte2x2 stdmath_byte2x2_fill(uint8_t value);

size_t stdmath_byte2x2_rows(const stdmath_byte2x2* m);
inline size_t stdmath_byte2x2_rows_get(const stdmath_byte2x2* m) {
	return stdmath_byte2x2_rows(m);
}
size_t stdmath_byte2x2_columns(const stdmath_byte2x2* m);
inline size_t stdmath_byte2x2_columns_get(const stdmath_byte2x2* m) {
	return stdmath_byte2x2_columns(m);
}
size_t stdmath_byte2x2_size(const stdmath_byte2x2* m);

uint8_t stdmath_byte2x2_get_element(const stdmath_byte2x2* m, size_t x, size_t y);
stdmath_byte2x2 stdmath_byte2x2_set_element(const stdmath_byte2x2* m, size_t x, size_t y, uint8_t value);

stdmath_byte2x2 stdmath_byte2x2_add(const stdmath_byte2x2* a, const stdmath_byte2x2* b);
stdmath_byte2x2 stdmath_byte2x2_subtract(const stdmath_byte2x2* a, const stdmath_byte2x2* b);
stdmath_byte2x2 stdmath_byte2x2_negate(const stdmath_byte2x2* m);
stdmath_byte2x2 stdmath_byte2x2_transpose(const stdmath_byte2x2* m);

stdmath_byte2x2 stdmath_byte2x2_multiply2(const stdmath_byte2x2* a, const stdmath_byte2x2* b);
stdmath_byte2x3 stdmath_byte2x2_multiply3(const stdmath_byte2x2* a, const stdmath_byte2x3* b);
stdmath_byte2x4 stdmath_byte2x2_multiply4(const stdmath_byte2x2* a, const stdmath_byte2x4* b);
stdmath_byte2 stdmath_byte2x2_multiply(const stdmath_byte2x2* m, stdmath_byte2 v);

#if 2 == 2
stdmath_byte2x2 stdmath_byte2x2_scale(const stdmath_byte2x2* m, uint8_t s);
stdmath_byte2x2 stdmath_byte2x2_inverse(const stdmath_byte2x2* m);
#endif

#ifdef STDMATH_IMPLEMENTATION
#ifndef __cplusplus
#error "The stdmath implementations require a C++ compiler"
#endif

import stdmath.slang;

stdmath::byte2x2 c(stdmath_byte2x2 c) {
	return (stdmath::byte2x2&)c;
}
stdmath_byte2x2 c(stdmath::byte2x2 c) {
	return (stdmath_byte2x2&)c;
}

stdmath_byte2x2 stdmath_byte2x2_identity_scaled(uint8_t scale) {
	return c(stdmath::byte2x2::identity((stdmath::byte2x2::underlying_type)scale));
}
stdmath_byte2x2 stdmath_byte2x2_identity() {
	return c(stdmath::byte2x2::identity());
}
stdmath_byte2x2 stdmath_byte2x2_fill(uint8_t value) {
	return c(stdmath::byte2x2::fill((stdmath::byte2x2::underlying_type)value));
}

size_t stdmath_byte2x2_rows(const stdmath_byte2x2* m) {
	return 2;
}
size_t stdmath_byte2x2_columns(const stdmath_byte2x2* m) {
	return 2;
}
size_t stdmath_byte2x2_size(const stdmath_byte2x2* m) {
	return 2 * 2;
}

uint8_t stdmath_byte2x2_get_element(const stdmath_byte2x2* m, size_t x, size_t y) {
	return c(*m)[x, y];
}
stdmath_byte2x2 stdmath_byte2x2_set_element(const stdmath_byte2x2* m, size_t x, size_t y, uint8_t value) {
	auto out = c(*m);
	out[x, y] = (stdmath::byte2x2::underlying_type)value;
	return c(out);
}

stdmath_byte2x2 stdmath_byte2x2_add(const stdmath_byte2x2* a, const stdmath_byte2x2* b) {
	return c(c(*a) + c(*b));
}
stdmath_byte2x2 stdmath_byte2x2_subtract(const stdmath_byte2x2* a, const stdmath_byte2x2* b) {
	return c(c(*a) - c(*b));
}
stdmath_byte2x2 stdmath_byte2x2_negate(const stdmath_byte2x2* m) {
	return c(-c(*m));
}

stdmath_byte2 stdmath_byte2x2_multiply(const stdmath_byte2x2* m, stdmath_byte2 v) {
	return c(stdmath::byte2x2::multiply(c(*m), c(v)));
}

#if 2 == 2
stdmath_byte2x2 stdmath_byte2x2_scale(const stdmath_byte2x2* m, uint8_t s) {
	return c(stdmath::byte2x2::multiply(c(*m), (stdmath::byte2x2::underlying_type)s));
}
stdmath_byte2x2 stdmath_byte2x2_inverse(const stdmath_byte2x2* m) {
	return c(inverse(c(*m)));
}
#endif

#endif // #ifdef STDMATH_IMPLEMENTATION

#endif // __STDMATH_byte2x2_H__


#ifdef STDMATH_IMPLEMENTATION

#ifdef __STDMATH_byte2x2_H__
#ifndef __STDMATH_byte2x2_TRANSPOSE_IMPL__
#define __STDMATH_byte2x2_TRANSPOSE_IMPL__
stdmath_byte2x2 stdmath_byte2x2_transpose(const stdmath_byte2x2* m) {
	return c(transpose(c(*m)));
}
#endif
#endif

#ifdef __STDMATH_byte2x2_H__
#ifdef __STDMATH_byte2x2_H__
#ifndef __STDMATH_byte2x2_2x2_IMPL__
#define __STDMATH_byte2x2_2x2_IMPL__
stdmath_byte2x2 stdmath_byte2x2_multiply2(const stdmath_byte2x2* a, const stdmath_byte2x2* b) {
	return c(stdmath::byte2x2::multiply(c(*a), c(*b)));
}
#endif
#endif
#endif

#ifdef __STDMATH_byte2x3_H__
#ifdef __STDMATH_byte2x3_H__
#ifndef __STDMATH_byte2x2_2x3_IMPL__
#define __STDMATH_byte2x2_2x3_IMPL__
stdmath_byte2x3 stdmath_byte2x2_multiply3(const stdmath_byte2x2* a, const stdmath_byte2x3* b) {
	return c(stdmath::byte2x2::multiply(c(*a), c(*b)));
}
#endif
#endif
#endif

#ifdef __STDMATH_byte2x4_H__
#ifdef __STDMATH_byte2x4_H__
#ifndef __STDMATH_byte2x2_2x4_IMPL__
#define __STDMATH_byte2x2_2x4_IMPL__
stdmath_byte2x4 stdmath_byte2x2_multiply4(const stdmath_byte2x2* a, const stdmath_byte2x4* b) {
	return c(stdmath::byte2x2::multiply(c(*a), c(*b)));
}
#endif
#endif
#endif

#endif // STDMATH_IMPLEMENTATION