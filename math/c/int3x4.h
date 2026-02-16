#ifndef __STDMATH_int3x4_H__
#define __STDMATH_int3x4_H__

struct stdmath_int3x2;
struct stdmath_int3x3;
struct stdmath_int3x4;
#if 3 != 4
struct stdmath_int4x2;
struct stdmath_int4x3;
struct stdmath_int4x4;
#endif

#include <stddef.h>
#include "int4.h"

struct stdmath_int3x4 {
	int32_t data[3 * 4];
};

stdmath_int3x4 stdmath_int3x4_identity_scaled(int32_t scale);
stdmath_int3x4 stdmath_int3x4_identity();
stdmath_int3x4 stdmath_int3x4_fill(int32_t value);

size_t stdmath_int3x4_rows(const stdmath_int3x4* m);
inline size_t stdmath_int3x4_rows_get(const stdmath_int3x4* m) {
	return stdmath_int3x4_rows(m);
}
size_t stdmath_int3x4_columns(const stdmath_int3x4* m);
inline size_t stdmath_int3x4_columns_get(const stdmath_int3x4* m) {
	return stdmath_int3x4_columns(m);
}
size_t stdmath_int3x4_size(const stdmath_int3x4* m);

int32_t stdmath_int3x4_get_element(const stdmath_int3x4* m, size_t x, size_t y);
stdmath_int3x4 stdmath_int3x4_set_element(const stdmath_int3x4* m, size_t x, size_t y, int32_t value);

stdmath_int3x4 stdmath_int3x4_add(const stdmath_int3x4* a, const stdmath_int3x4* b);
stdmath_int3x4 stdmath_int3x4_subtract(const stdmath_int3x4* a, const stdmath_int3x4* b);
stdmath_int3x4 stdmath_int3x4_negate(const stdmath_int3x4* m);
stdmath_int4x3 stdmath_int3x4_transpose(const stdmath_int3x4* m);

stdmath_int3x2 stdmath_int3x4_multiply2(const stdmath_int3x4* a, const stdmath_int4x2* b);
stdmath_int3x3 stdmath_int3x4_multiply3(const stdmath_int3x4* a, const stdmath_int4x3* b);
stdmath_int3x4 stdmath_int3x4_multiply4(const stdmath_int3x4* a, const stdmath_int4x4* b);
stdmath_int4 stdmath_int3x4_multiply(const stdmath_int3x4* m, stdmath_int4 v);

#if 3 == 4
stdmath_int3x3 stdmath_int3x3_scale(const stdmath_int3x3* m, int32_t s);
stdmath_int3x3 stdmath_int3x3_inverse(const stdmath_int3x3* m);
#endif

#ifdef STDMATH_IMPLEMENTATION
#ifndef __cplusplus
#error "The stdmath implementations require a C++ compiler"
#endif

import stdmath.slang;

stdmath::int3x4 c(stdmath_int3x4 c) {
	return (stdmath::int3x4&)c;
}
stdmath_int3x4 c(stdmath::int3x4 c) {
	return (stdmath_int3x4&)c;
}

stdmath_int3x4 stdmath_int3x4_identity_scaled(int32_t scale) {
	return c(stdmath::int3x4::identity((stdmath::int3x4::underlying_type)scale));
}
stdmath_int3x4 stdmath_int3x4_identity() {
	return c(stdmath::int3x4::identity());
}
stdmath_int3x4 stdmath_int3x4_fill(int32_t value) {
	return c(stdmath::int3x4::fill((stdmath::int3x4::underlying_type)value));
}

size_t stdmath_int3x4_rows(const stdmath_int3x4* m) {
	return 3;
}
size_t stdmath_int3x4_columns(const stdmath_int3x4* m) {
	return 4;
}
size_t stdmath_int3x4_size(const stdmath_int3x4* m) {
	return 3 * 4;
}

int32_t stdmath_int3x4_get_element(const stdmath_int3x4* m, size_t x, size_t y) {
	return c(*m)[x, y];
}
stdmath_int3x4 stdmath_int3x4_set_element(const stdmath_int3x4* m, size_t x, size_t y, int32_t value) {
	auto out = c(*m);
	out[x, y] = (stdmath::int3x4::underlying_type)value;
	return c(out);
}

stdmath_int3x4 stdmath_int3x4_add(const stdmath_int3x4* a, const stdmath_int3x4* b) {
	return c(c(*a) + c(*b));
}
stdmath_int3x4 stdmath_int3x4_subtract(const stdmath_int3x4* a, const stdmath_int3x4* b) {
	return c(c(*a) - c(*b));
}
stdmath_int3x4 stdmath_int3x4_negate(const stdmath_int3x4* m) {
	return c(-c(*m));
}

stdmath_int4 stdmath_int3x4_multiply(const stdmath_int3x4* m, stdmath_int4 v) {
	return c(stdmath::int3x4::multiply(c(*m), c(v)));
}

#if 3 == 4
stdmath_int3x3 stdmath_int3x3_scale(const stdmath_int3x3* m, int32_t s) {
	return c(stdmath::int3x3::multiply(c(*m), (stdmath::int3x3::underlying_type)s));
}
stdmath_int3x3 stdmath_int3x3_inverse(const stdmath_int3x3* m) {
	return c(inverse(c(*m)));
}
#endif

#endif // #ifdef STDMATH_IMPLEMENTATION

#endif // __STDMATH_int3x4_H__


#ifdef STDMATH_IMPLEMENTATION

#ifdef __STDMATH_int4x3_H__
#ifndef __STDMATH_int3x4_TRANSPOSE_IMPL__
#define __STDMATH_int3x4_TRANSPOSE_IMPL__
stdmath_int4x3 stdmath_int3x4_transpose(const stdmath_int3x4* m) {
	return c(transpose(c(*m)));
}
#endif
#endif

#ifdef __STDMATH_int4x2_H__
#ifdef __STDMATH_int3x2_H__
#ifndef __STDMATH_int3x4_3x2_IMPL__
#define __STDMATH_int3x4_3x2_IMPL__
stdmath_int3x2 stdmath_int3x4_multiply2(const stdmath_int3x4* a, const stdmath_int4x2* b) {
	return c(stdmath::int3x4::multiply(c(*a), c(*b)));
}
#endif
#endif
#endif

#ifdef __STDMATH_int4x3_H__
#ifdef __STDMATH_int3x3_H__
#ifndef __STDMATH_int3x4_3x3_IMPL__
#define __STDMATH_int3x4_3x3_IMPL__
stdmath_int3x3 stdmath_int3x4_multiply3(const stdmath_int3x4* a, const stdmath_int4x3* b) {
	return c(stdmath::int3x4::multiply(c(*a), c(*b)));
}
#endif
#endif
#endif

#ifdef __STDMATH_int4x4_H__
#ifdef __STDMATH_int3x4_H__
#ifndef __STDMATH_int3x4_3x4_IMPL__
#define __STDMATH_int3x4_3x4_IMPL__
stdmath_int3x4 stdmath_int3x4_multiply4(const stdmath_int3x4* a, const stdmath_int4x4* b) {
	return c(stdmath::int3x4::multiply(c(*a), c(*b)));
}
#endif
#endif
#endif

#endif // STDMATH_IMPLEMENTATION