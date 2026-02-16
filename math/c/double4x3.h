#ifndef __STDMATH_double4x3_H__
#define __STDMATH_double4x3_H__

struct stdmath_double4x2;
struct stdmath_double4x3;
struct stdmath_double4x4;
#if 4 != 3
struct stdmath_double3x2;
struct stdmath_double3x3;
struct stdmath_double3x4;
#endif

#include <stddef.h>
#include "double3.h"

struct stdmath_double4x3 {
	double data[4 * 3];
};

stdmath_double4x3 stdmath_double4x3_identity_scaled(double scale);
stdmath_double4x3 stdmath_double4x3_identity();
stdmath_double4x3 stdmath_double4x3_fill(double value);

size_t stdmath_double4x3_rows(const stdmath_double4x3* m);
inline size_t stdmath_double4x3_rows_get(const stdmath_double4x3* m) {
	return stdmath_double4x3_rows(m);
}
size_t stdmath_double4x3_columns(const stdmath_double4x3* m);
inline size_t stdmath_double4x3_columns_get(const stdmath_double4x3* m) {
	return stdmath_double4x3_columns(m);
}
size_t stdmath_double4x3_size(const stdmath_double4x3* m);

double stdmath_double4x3_get_element(const stdmath_double4x3* m, size_t x, size_t y);
stdmath_double4x3 stdmath_double4x3_set_element(const stdmath_double4x3* m, size_t x, size_t y, double value);

stdmath_double4x3 stdmath_double4x3_add(const stdmath_double4x3* a, const stdmath_double4x3* b);
stdmath_double4x3 stdmath_double4x3_subtract(const stdmath_double4x3* a, const stdmath_double4x3* b);
stdmath_double4x3 stdmath_double4x3_negate(const stdmath_double4x3* m);
stdmath_double3x4 stdmath_double4x3_transpose(const stdmath_double4x3* m);

stdmath_double4x2 stdmath_double4x3_multiply2(const stdmath_double4x3* a, const stdmath_double3x2* b);
stdmath_double4x3 stdmath_double4x3_multiply3(const stdmath_double4x3* a, const stdmath_double3x3* b);
stdmath_double4x4 stdmath_double4x3_multiply4(const stdmath_double4x3* a, const stdmath_double3x4* b);
stdmath_double3 stdmath_double4x3_multiply(const stdmath_double4x3* m, stdmath_double3 v);

#if 4 == 3
stdmath_double4x4 stdmath_double4x4_scale(const stdmath_double4x4* m, double s);
stdmath_double4x4 stdmath_double4x4_inverse(const stdmath_double4x4* m);
#endif

#ifdef STDMATH_IMPLEMENTATION
#ifndef __cplusplus
#error "The stdmath implementations require a C++ compiler"
#endif

import stdmath.slang;

stdmath::double4x3 c(stdmath_double4x3 c) {
	return (stdmath::double4x3&)c;
}
stdmath_double4x3 c(stdmath::double4x3 c) {
	return (stdmath_double4x3&)c;
}

stdmath_double4x3 stdmath_double4x3_identity_scaled(double scale) {
	return c(stdmath::double4x3::identity((stdmath::double4x3::underlying_type)scale));
}
stdmath_double4x3 stdmath_double4x3_identity() {
	return c(stdmath::double4x3::identity());
}
stdmath_double4x3 stdmath_double4x3_fill(double value) {
	return c(stdmath::double4x3::fill((stdmath::double4x3::underlying_type)value));
}

size_t stdmath_double4x3_rows(const stdmath_double4x3* m) {
	return 4;
}
size_t stdmath_double4x3_columns(const stdmath_double4x3* m) {
	return 3;
}
size_t stdmath_double4x3_size(const stdmath_double4x3* m) {
	return 4 * 3;
}

double stdmath_double4x3_get_element(const stdmath_double4x3* m, size_t x, size_t y) {
	return c(*m)[x, y];
}
stdmath_double4x3 stdmath_double4x3_set_element(const stdmath_double4x3* m, size_t x, size_t y, double value) {
	auto out = c(*m);
	out[x, y] = (stdmath::double4x3::underlying_type)value;
	return c(out);
}

stdmath_double4x3 stdmath_double4x3_add(const stdmath_double4x3* a, const stdmath_double4x3* b) {
	return c(c(*a) + c(*b));
}
stdmath_double4x3 stdmath_double4x3_subtract(const stdmath_double4x3* a, const stdmath_double4x3* b) {
	return c(c(*a) - c(*b));
}
stdmath_double4x3 stdmath_double4x3_negate(const stdmath_double4x3* m) {
	return c(-c(*m));
}

stdmath_double3 stdmath_double4x3_multiply(const stdmath_double4x3* m, stdmath_double3 v) {
	return c(stdmath::double4x3::multiply(c(*m), c(v)));
}

#if 4 == 3
stdmath_double4x4 stdmath_double4x4_scale(const stdmath_double4x4* m, double s) {
	return c(stdmath::double4x4::multiply(c(*m), (stdmath::double4x4::underlying_type)s));
}
stdmath_double4x4 stdmath_double4x4_inverse(const stdmath_double4x4* m) {
	return c(inverse(c(*m)));
}
#endif

#endif // #ifdef STDMATH_IMPLEMENTATION

#endif // __STDMATH_double4x3_H__


#ifdef STDMATH_IMPLEMENTATION

#ifdef __STDMATH_double3x4_H__
#ifndef __STDMATH_double4x3_TRANSPOSE_IMPL__
#define __STDMATH_double4x3_TRANSPOSE_IMPL__
stdmath_double3x4 stdmath_double4x3_transpose(const stdmath_double4x3* m) {
	return c(transpose(c(*m)));
}
#endif
#endif

#ifdef __STDMATH_double3x2_H__
#ifdef __STDMATH_double4x2_H__
#ifndef __STDMATH_double4x3_4x2_IMPL__
#define __STDMATH_double4x3_4x2_IMPL__
stdmath_double4x2 stdmath_double4x3_multiply2(const stdmath_double4x3* a, const stdmath_double3x2* b) {
	return c(stdmath::double4x3::multiply(c(*a), c(*b)));
}
#endif
#endif
#endif

#ifdef __STDMATH_double3x3_H__
#ifdef __STDMATH_double4x3_H__
#ifndef __STDMATH_double4x3_4x3_IMPL__
#define __STDMATH_double4x3_4x3_IMPL__
stdmath_double4x3 stdmath_double4x3_multiply3(const stdmath_double4x3* a, const stdmath_double3x3* b) {
	return c(stdmath::double4x3::multiply(c(*a), c(*b)));
}
#endif
#endif
#endif

#ifdef __STDMATH_double3x4_H__
#ifdef __STDMATH_double4x4_H__
#ifndef __STDMATH_double4x3_4x4_IMPL__
#define __STDMATH_double4x3_4x4_IMPL__
stdmath_double4x4 stdmath_double4x3_multiply4(const stdmath_double4x3* a, const stdmath_double3x4* b) {
	return c(stdmath::double4x3::multiply(c(*a), c(*b)));
}
#endif
#endif
#endif

#endif // STDMATH_IMPLEMENTATION