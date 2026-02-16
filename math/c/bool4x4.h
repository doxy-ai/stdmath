#ifndef __STDMATH_bool4x4_H__
#define __STDMATH_bool4x4_H__

struct stdmath_bool4x2;
struct stdmath_bool4x3;
struct stdmath_bool4x4;
#if 4 != 4
struct stdmath_bool4x2;
struct stdmath_bool4x3;
struct stdmath_bool4x4;
#endif

#include <stddef.h>
#include "bool4.h"

struct stdmath_bool4x4 {
	bool data[4 * 4];
};

stdmath_bool4x4 stdmath_bool4x4_identity_scaled(bool scale);
stdmath_bool4x4 stdmath_bool4x4_identity();
stdmath_bool4x4 stdmath_bool4x4_fill(bool value);

size_t stdmath_bool4x4_rows(const stdmath_bool4x4* m);
inline size_t stdmath_bool4x4_rows_get(const stdmath_bool4x4* m) {
	return stdmath_bool4x4_rows(m);
}
size_t stdmath_bool4x4_columns(const stdmath_bool4x4* m);
inline size_t stdmath_bool4x4_columns_get(const stdmath_bool4x4* m) {
	return stdmath_bool4x4_columns(m);
}
size_t stdmath_bool4x4_size(const stdmath_bool4x4* m);

bool stdmath_bool4x4_get_element(const stdmath_bool4x4* m, size_t x, size_t y);
stdmath_bool4x4 stdmath_bool4x4_set_element(const stdmath_bool4x4* m, size_t x, size_t y, bool value);

stdmath_bool4x4 stdmath_bool4x4_add(const stdmath_bool4x4* a, const stdmath_bool4x4* b);
stdmath_bool4x4 stdmath_bool4x4_subtract(const stdmath_bool4x4* a, const stdmath_bool4x4* b);
stdmath_bool4x4 stdmath_bool4x4_negate(const stdmath_bool4x4* m);
stdmath_bool4x4 stdmath_bool4x4_transpose(const stdmath_bool4x4* m);

stdmath_bool4x2 stdmath_bool4x4_multiply2(const stdmath_bool4x4* a, const stdmath_bool4x2* b);
stdmath_bool4x3 stdmath_bool4x4_multiply3(const stdmath_bool4x4* a, const stdmath_bool4x3* b);
stdmath_bool4x4 stdmath_bool4x4_multiply4(const stdmath_bool4x4* a, const stdmath_bool4x4* b);
stdmath_bool4 stdmath_bool4x4_multiply(const stdmath_bool4x4* m, stdmath_bool4 v);

#if 4 == 4
stdmath_bool4x4 stdmath_bool4x4_scale(const stdmath_bool4x4* m, bool s);
stdmath_bool4x4 stdmath_bool4x4_inverse(const stdmath_bool4x4* m);
#endif

#ifdef STDMATH_IMPLEMENTATION
#ifndef __cplusplus
#error "The stdmath implementations require a C++ compiler"
#endif

import stdmath.slang;

stdmath::bool4x4 c(stdmath_bool4x4 c) {
	return (stdmath::bool4x4&)c;
}
stdmath_bool4x4 c(stdmath::bool4x4 c) {
	return (stdmath_bool4x4&)c;
}

stdmath_bool4x4 stdmath_bool4x4_identity_scaled(bool scale) {
	return c(stdmath::bool4x4::identity((stdmath::bool4x4::underlying_type)scale));
}
stdmath_bool4x4 stdmath_bool4x4_identity() {
	return c(stdmath::bool4x4::identity());
}
stdmath_bool4x4 stdmath_bool4x4_fill(bool value) {
	return c(stdmath::bool4x4::fill((stdmath::bool4x4::underlying_type)value));
}

size_t stdmath_bool4x4_rows(const stdmath_bool4x4* m) {
	return 4;
}
size_t stdmath_bool4x4_columns(const stdmath_bool4x4* m) {
	return 4;
}
size_t stdmath_bool4x4_size(const stdmath_bool4x4* m) {
	return 4 * 4;
}

bool stdmath_bool4x4_get_element(const stdmath_bool4x4* m, size_t x, size_t y) {
	return c(*m)[x, y];
}
stdmath_bool4x4 stdmath_bool4x4_set_element(const stdmath_bool4x4* m, size_t x, size_t y, bool value) {
	auto out = c(*m);
	out[x, y] = (stdmath::bool4x4::underlying_type)value;
	return c(out);
}

stdmath_bool4x4 stdmath_bool4x4_add(const stdmath_bool4x4* a, const stdmath_bool4x4* b) {
	return c(c(*a) + c(*b));
}
stdmath_bool4x4 stdmath_bool4x4_subtract(const stdmath_bool4x4* a, const stdmath_bool4x4* b) {
	return c(c(*a) - c(*b));
}
stdmath_bool4x4 stdmath_bool4x4_negate(const stdmath_bool4x4* m) {
	return c(-c(*m));
}

stdmath_bool4 stdmath_bool4x4_multiply(const stdmath_bool4x4* m, stdmath_bool4 v) {
	return c(stdmath::bool4x4::multiply(c(*m), c(v)));
}

#if 4 == 4
stdmath_bool4x4 stdmath_bool4x4_scale(const stdmath_bool4x4* m, bool s) {
	return c(stdmath::bool4x4::multiply(c(*m), (stdmath::bool4x4::underlying_type)s));
}
stdmath_bool4x4 stdmath_bool4x4_inverse(const stdmath_bool4x4* m) {
	return c(inverse(c(*m)));
}
#endif

#endif // #ifdef STDMATH_IMPLEMENTATION

#endif // __STDMATH_bool4x4_H__


#ifdef STDMATH_IMPLEMENTATION

#ifdef __STDMATH_bool4x4_H__
#ifndef __STDMATH_bool4x4_TRANSPOSE_IMPL__
#define __STDMATH_bool4x4_TRANSPOSE_IMPL__
stdmath_bool4x4 stdmath_bool4x4_transpose(const stdmath_bool4x4* m) {
	return c(transpose(c(*m)));
}
#endif
#endif

#ifdef __STDMATH_bool4x2_H__
#ifdef __STDMATH_bool4x2_H__
#ifndef __STDMATH_bool4x4_4x2_IMPL__
#define __STDMATH_bool4x4_4x2_IMPL__
stdmath_bool4x2 stdmath_bool4x4_multiply2(const stdmath_bool4x4* a, const stdmath_bool4x2* b) {
	return c(stdmath::bool4x4::multiply(c(*a), c(*b)));
}
#endif
#endif
#endif

#ifdef __STDMATH_bool4x3_H__
#ifdef __STDMATH_bool4x3_H__
#ifndef __STDMATH_bool4x4_4x3_IMPL__
#define __STDMATH_bool4x4_4x3_IMPL__
stdmath_bool4x3 stdmath_bool4x4_multiply3(const stdmath_bool4x4* a, const stdmath_bool4x3* b) {
	return c(stdmath::bool4x4::multiply(c(*a), c(*b)));
}
#endif
#endif
#endif

#ifdef __STDMATH_bool4x4_H__
#ifdef __STDMATH_bool4x4_H__
#ifndef __STDMATH_bool4x4_4x4_IMPL__
#define __STDMATH_bool4x4_4x4_IMPL__
stdmath_bool4x4 stdmath_bool4x4_multiply4(const stdmath_bool4x4* a, const stdmath_bool4x4* b) {
	return c(stdmath::bool4x4::multiply(c(*a), c(*b)));
}
#endif
#endif
#endif

#endif // STDMATH_IMPLEMENTATION