#ifndef __STDMATH_uint3x4_H__
#define __STDMATH_uint3x4_H__

struct stdmath_uint3x2;
struct stdmath_uint3x3;
struct stdmath_uint3x4;
#if 3 != 4
struct stdmath_uint4x2;
struct stdmath_uint4x3;
struct stdmath_uint4x4;
#endif

#include <stddef.h>
#include "uint4.h"

struct stdmath_uint3x4 {
	uint32_t data[3 * 4];
};

stdmath_uint3x4 stdmath_uint3x4_identity_scaled(uint32_t scale);
stdmath_uint3x4 stdmath_uint3x4_identity();
stdmath_uint3x4 stdmath_uint3x4_fill(uint32_t value);

size_t stdmath_uint3x4_rows(const stdmath_uint3x4* m);
inline size_t stdmath_uint3x4_rows_get(const stdmath_uint3x4* m) {
	return stdmath_uint3x4_rows(m);
}
size_t stdmath_uint3x4_columns(const stdmath_uint3x4* m);
inline size_t stdmath_uint3x4_columns_get(const stdmath_uint3x4* m) {
	return stdmath_uint3x4_columns(m);
}
size_t stdmath_uint3x4_size(const stdmath_uint3x4* m);

uint32_t stdmath_uint3x4_get_element(const stdmath_uint3x4* m, size_t x, size_t y);
stdmath_uint3x4 stdmath_uint3x4_set_element(const stdmath_uint3x4* m, size_t x, size_t y, uint32_t value);

stdmath_uint3x4 stdmath_uint3x4_add(const stdmath_uint3x4* a, const stdmath_uint3x4* b);
stdmath_uint3x4 stdmath_uint3x4_subtract(const stdmath_uint3x4* a, const stdmath_uint3x4* b);
stdmath_uint3x4 stdmath_uint3x4_negate(const stdmath_uint3x4* m);
stdmath_uint4x3 stdmath_uint3x4_transpose(const stdmath_uint3x4* m);

stdmath_uint3x2 stdmath_uint3x4_multiply2(const stdmath_uint3x4* a, const stdmath_uint4x2* b);
stdmath_uint3x3 stdmath_uint3x4_multiply3(const stdmath_uint3x4* a, const stdmath_uint4x3* b);
stdmath_uint3x4 stdmath_uint3x4_multiply4(const stdmath_uint3x4* a, const stdmath_uint4x4* b);
stdmath_uint4 stdmath_uint3x4_multiply(const stdmath_uint3x4* m, stdmath_uint4 v);

#if 3 == 4
stdmath_uint3x3 stdmath_uint3x3_scale(const stdmath_uint3x3* m, uint32_t s);
stdmath_uint3x3 stdmath_uint3x3_inverse(const stdmath_uint3x3* m);
#endif

#ifdef STDMATH_IMPLEMENTATION
#ifndef __cplusplus
#error "The stdmath implementations require a C++ compiler"
#endif

import stdmath.slang;

stdmath::uint3x4 c(stdmath_uint3x4 c) {
	return (stdmath::uint3x4&)c;
}
stdmath_uint3x4 c(stdmath::uint3x4 c) {
	return (stdmath_uint3x4&)c;
}

stdmath_uint3x4 stdmath_uint3x4_identity_scaled(uint32_t scale) {
	return c(stdmath::uint3x4::identity((stdmath::uint3x4::underlying_type)scale));
}
stdmath_uint3x4 stdmath_uint3x4_identity() {
	return c(stdmath::uint3x4::identity());
}
stdmath_uint3x4 stdmath_uint3x4_fill(uint32_t value) {
	return c(stdmath::uint3x4::fill((stdmath::uint3x4::underlying_type)value));
}

size_t stdmath_uint3x4_rows(const stdmath_uint3x4* m) {
	return 3;
}
size_t stdmath_uint3x4_columns(const stdmath_uint3x4* m) {
	return 4;
}
size_t stdmath_uint3x4_size(const stdmath_uint3x4* m) {
	return 3 * 4;
}

uint32_t stdmath_uint3x4_get_element(const stdmath_uint3x4* m, size_t x, size_t y) {
	return c(*m)[x, y];
}
stdmath_uint3x4 stdmath_uint3x4_set_element(const stdmath_uint3x4* m, size_t x, size_t y, uint32_t value) {
	auto out = c(*m);
	out[x, y] = (stdmath::uint3x4::underlying_type)value;
	return c(out);
}

stdmath_uint3x4 stdmath_uint3x4_add(const stdmath_uint3x4* a, const stdmath_uint3x4* b) {
	return c(c(*a) + c(*b));
}
stdmath_uint3x4 stdmath_uint3x4_subtract(const stdmath_uint3x4* a, const stdmath_uint3x4* b) {
	return c(c(*a) - c(*b));
}
stdmath_uint3x4 stdmath_uint3x4_negate(const stdmath_uint3x4* m) {
	return c(-c(*m));
}

stdmath_uint4 stdmath_uint3x4_multiply(const stdmath_uint3x4* m, stdmath_uint4 v) {
	return c(stdmath::uint3x4::multiply(c(*m), c(v)));
}

#if 3 == 4
stdmath_uint3x3 stdmath_uint3x3_scale(const stdmath_uint3x3* m, uint32_t s) {
	return c(stdmath::uint3x3::multiply(c(*m), (stdmath::uint3x3::underlying_type)s));
}
stdmath_uint3x3 stdmath_uint3x3_inverse(const stdmath_uint3x3* m) {
	return c(inverse(c(*m)));
}
#endif

#endif // #ifdef STDMATH_IMPLEMENTATION

#endif // __STDMATH_uint3x4_H__


#ifdef STDMATH_IMPLEMENTATION

#ifdef __STDMATH_uint4x3_H__
#ifndef __STDMATH_uint3x4_TRANSPOSE_IMPL__
#define __STDMATH_uint3x4_TRANSPOSE_IMPL__
stdmath_uint4x3 stdmath_uint3x4_transpose(const stdmath_uint3x4* m) {
	return c(transpose(c(*m)));
}
#endif
#endif

#ifdef __STDMATH_uint4x2_H__
#ifdef __STDMATH_uint3x2_H__
#ifndef __STDMATH_uint3x4_3x2_IMPL__
#define __STDMATH_uint3x4_3x2_IMPL__
stdmath_uint3x2 stdmath_uint3x4_multiply2(const stdmath_uint3x4* a, const stdmath_uint4x2* b) {
	return c(stdmath::uint3x4::multiply(c(*a), c(*b)));
}
#endif
#endif
#endif

#ifdef __STDMATH_uint4x3_H__
#ifdef __STDMATH_uint3x3_H__
#ifndef __STDMATH_uint3x4_3x3_IMPL__
#define __STDMATH_uint3x4_3x3_IMPL__
stdmath_uint3x3 stdmath_uint3x4_multiply3(const stdmath_uint3x4* a, const stdmath_uint4x3* b) {
	return c(stdmath::uint3x4::multiply(c(*a), c(*b)));
}
#endif
#endif
#endif

#ifdef __STDMATH_uint4x4_H__
#ifdef __STDMATH_uint3x4_H__
#ifndef __STDMATH_uint3x4_3x4_IMPL__
#define __STDMATH_uint3x4_3x4_IMPL__
stdmath_uint3x4 stdmath_uint3x4_multiply4(const stdmath_uint3x4* a, const stdmath_uint4x4* b) {
	return c(stdmath::uint3x4::multiply(c(*a), c(*b)));
}
#endif
#endif
#endif

#endif // STDMATH_IMPLEMENTATION