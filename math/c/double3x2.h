#ifndef __STDMATH_double3x2_H__
#define __STDMATH_double3x2_H__

struct stdmath_double3x2;
struct stdmath_double3x3;
struct stdmath_double3x4;
#if 3 != 2
struct stdmath_double2x2;
struct stdmath_double2x3;
struct stdmath_double2x4;
#endif

#include <stddef.h>
#include "double2.h"

struct stdmath_double3x2 {
	double data[3 * 2];
};

stdmath_double3x2 stdmath_double3x2_identity_scaled(double scale);
stdmath_double3x2 stdmath_double3x2_identity();
stdmath_double3x2 stdmath_double3x2_fill(double value);

size_t stdmath_double3x2_rows(const stdmath_double3x2* m);
inline size_t stdmath_double3x2_rows_get(const stdmath_double3x2* m) {
	return stdmath_double3x2_rows(m);
}
size_t stdmath_double3x2_columns(const stdmath_double3x2* m);
inline size_t stdmath_double3x2_columns_get(const stdmath_double3x2* m) {
	return stdmath_double3x2_columns(m);
}
size_t stdmath_double3x2_size(const stdmath_double3x2* m);

double stdmath_double3x2_get_element(const stdmath_double3x2* m, size_t x, size_t y);
stdmath_double3x2 stdmath_double3x2_set_element(const stdmath_double3x2* m, size_t x, size_t y, double value);

stdmath_double3x2 stdmath_double3x2_add(const stdmath_double3x2* a, const stdmath_double3x2* b);
stdmath_double3x2 stdmath_double3x2_subtract(const stdmath_double3x2* a, const stdmath_double3x2* b);
stdmath_double3x2 stdmath_double3x2_negate(const stdmath_double3x2* m);
stdmath_double2x3 stdmath_double3x2_transpose(const stdmath_double3x2* m);

stdmath_double3x2 stdmath_double3x2_multiply2(const stdmath_double3x2* a, const stdmath_double2x2* b);
stdmath_double3x3 stdmath_double3x2_multiply3(const stdmath_double3x2* a, const stdmath_double2x3* b);
stdmath_double3x4 stdmath_double3x2_multiply4(const stdmath_double3x2* a, const stdmath_double2x4* b);
stdmath_double2 stdmath_double3x2_multiply(const stdmath_double3x2* m, stdmath_double2 v);

#if 3 == 2
stdmath_double3x3 stdmath_double3x3_scale(const stdmath_double3x3* m, double s);
stdmath_double3x3 stdmath_double3x3_inverse(const stdmath_double3x3* m);
#endif

#ifdef STDMATH_IMPLEMENTATION
#ifndef __cplusplus
#error "The stdmath implementations require a C++ compiler"
#endif

import stdmath.slang;

stdmath::double3x2 c(stdmath_double3x2 c) {
	return (stdmath::double3x2&)c;
}
stdmath_double3x2 c(stdmath::double3x2 c) {
	return (stdmath_double3x2&)c;
}

stdmath_double3x2 stdmath_double3x2_identity_scaled(double scale) {
	return c(stdmath::double3x2::identity((stdmath::double3x2::underlying_type)scale));
}
stdmath_double3x2 stdmath_double3x2_identity() {
	return c(stdmath::double3x2::identity());
}
stdmath_double3x2 stdmath_double3x2_fill(double value) {
	return c(stdmath::double3x2::fill((stdmath::double3x2::underlying_type)value));
}

size_t stdmath_double3x2_rows(const stdmath_double3x2* m) {
	return 3;
}
size_t stdmath_double3x2_columns(const stdmath_double3x2* m) {
	return 2;
}
size_t stdmath_double3x2_size(const stdmath_double3x2* m) {
	return 3 * 2;
}

double stdmath_double3x2_get_element(const stdmath_double3x2* m, size_t x, size_t y) {
	return c(*m)[x, y];
}
stdmath_double3x2 stdmath_double3x2_set_element(const stdmath_double3x2* m, size_t x, size_t y, double value) {
	auto out = c(*m);
	out[x, y] = (stdmath::double3x2::underlying_type)value;
	return c(out);
}

stdmath_double3x2 stdmath_double3x2_add(const stdmath_double3x2* a, const stdmath_double3x2* b) {
	return c(c(*a) + c(*b));
}
stdmath_double3x2 stdmath_double3x2_subtract(const stdmath_double3x2* a, const stdmath_double3x2* b) {
	return c(c(*a) - c(*b));
}
stdmath_double3x2 stdmath_double3x2_negate(const stdmath_double3x2* m) {
	return c(-c(*m));
}

stdmath_double2 stdmath_double3x2_multiply(const stdmath_double3x2* m, stdmath_double2 v) {
	return c(stdmath::double3x2::multiply(c(*m), c(v)));
}

#if 3 == 2
stdmath_double3x3 stdmath_double3x3_scale(const stdmath_double3x3* m, double s) {
	return c(stdmath::double3x3::multiply(c(*m), (stdmath::double3x3::underlying_type)s));
}
stdmath_double3x3 stdmath_double3x3_inverse(const stdmath_double3x3* m) {
	return c(inverse(c(*m)));
}
#endif

#endif // #ifdef STDMATH_IMPLEMENTATION

#endif // __STDMATH_double3x2_H__


#ifdef STDMATH_IMPLEMENTATION

#ifdef __STDMATH_double2x3_H__
#ifndef __STDMATH_double3x2_TRANSPOSE_IMPL__
#define __STDMATH_double3x2_TRANSPOSE_IMPL__
stdmath_double2x3 stdmath_double3x2_transpose(const stdmath_double3x2* m) {
	return c(transpose(c(*m)));
}
#endif
#endif

#ifdef __STDMATH_double2x2_H__
#ifdef __STDMATH_double3x2_H__
#ifndef __STDMATH_double3x2_3x2_IMPL__
#define __STDMATH_double3x2_3x2_IMPL__
stdmath_double3x2 stdmath_double3x2_multiply2(const stdmath_double3x2* a, const stdmath_double2x2* b) {
	return c(stdmath::double3x2::multiply(c(*a), c(*b)));
}
#endif
#endif
#endif

#ifdef __STDMATH_double2x3_H__
#ifdef __STDMATH_double3x3_H__
#ifndef __STDMATH_double3x2_3x3_IMPL__
#define __STDMATH_double3x2_3x3_IMPL__
stdmath_double3x3 stdmath_double3x2_multiply3(const stdmath_double3x2* a, const stdmath_double2x3* b) {
	return c(stdmath::double3x2::multiply(c(*a), c(*b)));
}
#endif
#endif
#endif

#ifdef __STDMATH_double2x4_H__
#ifdef __STDMATH_double3x4_H__
#ifndef __STDMATH_double3x2_3x4_IMPL__
#define __STDMATH_double3x2_3x4_IMPL__
stdmath_double3x4 stdmath_double3x2_multiply4(const stdmath_double3x2* a, const stdmath_double2x4* b) {
	return c(stdmath::double3x2::multiply(c(*a), c(*b)));
}
#endif
#endif
#endif

#endif // STDMATH_IMPLEMENTATION