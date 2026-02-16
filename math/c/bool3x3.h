#ifndef __STDMATH_bool3x3_H__
#define __STDMATH_bool3x3_H__

struct stdmath_bool3x2;
struct stdmath_bool3x3;
struct stdmath_bool3x4;
#if 3 != 3
struct stdmath_bool3x2;
struct stdmath_bool3x3;
struct stdmath_bool3x4;
#endif

#include <stddef.h>
#include "bool3.h"

struct stdmath_bool3x3 {
	bool data[3 * 3];
};

stdmath_bool3x3 stdmath_bool3x3_identity_scaled(bool scale);
stdmath_bool3x3 stdmath_bool3x3_identity();
stdmath_bool3x3 stdmath_bool3x3_fill(bool value);

size_t stdmath_bool3x3_rows(const stdmath_bool3x3* m);
inline size_t stdmath_bool3x3_rows_get(const stdmath_bool3x3* m) {
	return stdmath_bool3x3_rows(m);
}
size_t stdmath_bool3x3_columns(const stdmath_bool3x3* m);
inline size_t stdmath_bool3x3_columns_get(const stdmath_bool3x3* m) {
	return stdmath_bool3x3_columns(m);
}
size_t stdmath_bool3x3_size(const stdmath_bool3x3* m);

bool stdmath_bool3x3_get_element(const stdmath_bool3x3* m, size_t x, size_t y);
stdmath_bool3x3 stdmath_bool3x3_set_element(const stdmath_bool3x3* m, size_t x, size_t y, bool value);

stdmath_bool3x3 stdmath_bool3x3_add(const stdmath_bool3x3* a, const stdmath_bool3x3* b);
stdmath_bool3x3 stdmath_bool3x3_subtract(const stdmath_bool3x3* a, const stdmath_bool3x3* b);
stdmath_bool3x3 stdmath_bool3x3_negate(const stdmath_bool3x3* m);
stdmath_bool3x3 stdmath_bool3x3_transpose(const stdmath_bool3x3* m);

stdmath_bool3x2 stdmath_bool3x3_multiply2(const stdmath_bool3x3* a, const stdmath_bool3x2* b);
stdmath_bool3x3 stdmath_bool3x3_multiply3(const stdmath_bool3x3* a, const stdmath_bool3x3* b);
stdmath_bool3x4 stdmath_bool3x3_multiply4(const stdmath_bool3x3* a, const stdmath_bool3x4* b);
stdmath_bool3 stdmath_bool3x3_multiply(const stdmath_bool3x3* m, stdmath_bool3 v);

#if 3 == 3
stdmath_bool3x3 stdmath_bool3x3_scale(const stdmath_bool3x3* m, bool s);
stdmath_bool3x3 stdmath_bool3x3_inverse(const stdmath_bool3x3* m);
#endif

#ifdef STDMATH_IMPLEMENTATION
#ifndef __cplusplus
#error "The stdmath implementations require a C++ compiler"
#endif

import stdmath.slang;

stdmath::bool3x3 c(stdmath_bool3x3 c) {
	return (stdmath::bool3x3&)c;
}
stdmath_bool3x3 c(stdmath::bool3x3 c) {
	return (stdmath_bool3x3&)c;
}

stdmath_bool3x3 stdmath_bool3x3_identity_scaled(bool scale) {
	return c(stdmath::bool3x3::identity((stdmath::bool3x3::underlying_type)scale));
}
stdmath_bool3x3 stdmath_bool3x3_identity() {
	return c(stdmath::bool3x3::identity());
}
stdmath_bool3x3 stdmath_bool3x3_fill(bool value) {
	return c(stdmath::bool3x3::fill((stdmath::bool3x3::underlying_type)value));
}

size_t stdmath_bool3x3_rows(const stdmath_bool3x3* m) {
	return 3;
}
size_t stdmath_bool3x3_columns(const stdmath_bool3x3* m) {
	return 3;
}
size_t stdmath_bool3x3_size(const stdmath_bool3x3* m) {
	return 3 * 3;
}

bool stdmath_bool3x3_get_element(const stdmath_bool3x3* m, size_t x, size_t y) {
	return c(*m)[x, y];
}
stdmath_bool3x3 stdmath_bool3x3_set_element(const stdmath_bool3x3* m, size_t x, size_t y, bool value) {
	auto out = c(*m);
	out[x, y] = (stdmath::bool3x3::underlying_type)value;
	return c(out);
}

stdmath_bool3x3 stdmath_bool3x3_add(const stdmath_bool3x3* a, const stdmath_bool3x3* b) {
	return c(c(*a) + c(*b));
}
stdmath_bool3x3 stdmath_bool3x3_subtract(const stdmath_bool3x3* a, const stdmath_bool3x3* b) {
	return c(c(*a) - c(*b));
}
stdmath_bool3x3 stdmath_bool3x3_negate(const stdmath_bool3x3* m) {
	return c(-c(*m));
}

stdmath_bool3 stdmath_bool3x3_multiply(const stdmath_bool3x3* m, stdmath_bool3 v) {
	return c(stdmath::bool3x3::multiply(c(*m), c(v)));
}

#if 3 == 3
stdmath_bool3x3 stdmath_bool3x3_scale(const stdmath_bool3x3* m, bool s) {
	return c(stdmath::bool3x3::multiply(c(*m), (stdmath::bool3x3::underlying_type)s));
}
stdmath_bool3x3 stdmath_bool3x3_inverse(const stdmath_bool3x3* m) {
	return c(inverse(c(*m)));
}
#endif

#endif // #ifdef STDMATH_IMPLEMENTATION

#endif // __STDMATH_bool3x3_H__


#ifdef STDMATH_IMPLEMENTATION

#ifdef __STDMATH_bool3x3_H__
#ifndef __STDMATH_bool3x3_TRANSPOSE_IMPL__
#define __STDMATH_bool3x3_TRANSPOSE_IMPL__
stdmath_bool3x3 stdmath_bool3x3_transpose(const stdmath_bool3x3* m) {
	return c(transpose(c(*m)));
}
#endif
#endif

#ifdef __STDMATH_bool3x2_H__
#ifdef __STDMATH_bool3x2_H__
#ifndef __STDMATH_bool3x3_3x2_IMPL__
#define __STDMATH_bool3x3_3x2_IMPL__
stdmath_bool3x2 stdmath_bool3x3_multiply2(const stdmath_bool3x3* a, const stdmath_bool3x2* b) {
	return c(stdmath::bool3x3::multiply(c(*a), c(*b)));
}
#endif
#endif
#endif

#ifdef __STDMATH_bool3x3_H__
#ifdef __STDMATH_bool3x3_H__
#ifndef __STDMATH_bool3x3_3x3_IMPL__
#define __STDMATH_bool3x3_3x3_IMPL__
stdmath_bool3x3 stdmath_bool3x3_multiply3(const stdmath_bool3x3* a, const stdmath_bool3x3* b) {
	return c(stdmath::bool3x3::multiply(c(*a), c(*b)));
}
#endif
#endif
#endif

#ifdef __STDMATH_bool3x4_H__
#ifdef __STDMATH_bool3x4_H__
#ifndef __STDMATH_bool3x3_3x4_IMPL__
#define __STDMATH_bool3x3_3x4_IMPL__
stdmath_bool3x4 stdmath_bool3x3_multiply4(const stdmath_bool3x3* a, const stdmath_bool3x4* b) {
	return c(stdmath::bool3x3::multiply(c(*a), c(*b)));
}
#endif
#endif
#endif

#endif // STDMATH_IMPLEMENTATION