#ifndef __STDMATH_degree2x4_H__
#define __STDMATH_degree2x4_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "../maybe_export.h"
STDMATH_EXPORT struct stdmath_degree2x2;
STDMATH_EXPORT struct stdmath_degree2x3;
STDMATH_EXPORT struct stdmath_degree2x4;
#if 2 != 4
STDMATH_EXPORT struct stdmath_degree4x2;
STDMATH_EXPORT struct stdmath_degree4x3;
STDMATH_EXPORT struct stdmath_degree4x4;
#endif

#ifdef __cplusplus
} // extern "C"
#endif

#ifndef STDMATH_MODULE
#include <stddef.h>
#endif
#include "degree4.h"

#ifdef __cplusplus
extern "C" {
#endif

struct stdmath_degree2x4 {
	stdmath_degree data[2 * 4];
};

STDMATH_EXPORT stdmath_degree2x4 stdmath_degree2x4_identity_scaled(stdmath_degree scale);
STDMATH_EXPORT stdmath_degree2x4 stdmath_degree2x4_identity();
STDMATH_EXPORT stdmath_degree2x4 stdmath_degree2x4_fill(stdmath_degree value);

STDMATH_EXPORT size_t stdmath_degree2x4_rows(const stdmath_degree2x4* m);
STDMATH_EXPORT inline size_t stdmath_degree2x4_rows_get(const stdmath_degree2x4* m) {
	return stdmath_degree2x4_rows(m);
}
STDMATH_EXPORT size_t stdmath_degree2x4_columns(const stdmath_degree2x4* m);
STDMATH_EXPORT inline size_t stdmath_degree2x4_columns_get(const stdmath_degree2x4* m) {
	return stdmath_degree2x4_columns(m);
}
STDMATH_EXPORT size_t stdmath_degree2x4_size(const stdmath_degree2x4* m);

STDMATH_EXPORT stdmath_degree stdmath_degree2x4_get_element(const stdmath_degree2x4* m, size_t x, size_t y);
STDMATH_EXPORT stdmath_degree2x4 stdmath_degree2x4_set_element(const stdmath_degree2x4* m, size_t x, size_t y, stdmath_degree value);

STDMATH_EXPORT stdmath_degree2x4 stdmath_degree2x4_add(const stdmath_degree2x4* a, const stdmath_degree2x4* b);
STDMATH_EXPORT stdmath_degree2x4 stdmath_degree2x4_subtract(const stdmath_degree2x4* a, const stdmath_degree2x4* b);
STDMATH_EXPORT stdmath_degree2x4 stdmath_degree2x4_negate(const stdmath_degree2x4* m);
STDMATH_EXPORT stdmath_degree4x2 stdmath_degree2x4_transpose(const stdmath_degree2x4* m);

STDMATH_EXPORT stdmath_degree2x2 stdmath_degree2x4_multiply2(const stdmath_degree2x4* a, const stdmath_degree4x2* b);
STDMATH_EXPORT stdmath_degree2x3 stdmath_degree2x4_multiply3(const stdmath_degree2x4* a, const stdmath_degree4x3* b);
STDMATH_EXPORT stdmath_degree2x4 stdmath_degree2x4_multiply4(const stdmath_degree2x4* a, const stdmath_degree4x4* b);
STDMATH_EXPORT stdmath_degree4 stdmath_degree2x4_multiply(const stdmath_degree2x4* m, stdmath_degree4 v);

STDMATH_EXPORT bool stdmath_degree2x4_equal_to(const stdmath_degree2x4* a, const stdmath_degree2x4* b);
STDMATH_EXPORT bool stdmath_degree2x4_not_equal_to(const stdmath_degree2x4* a, const stdmath_degree2x4* b);
STDMATH_EXPORT bool stdmath_degree2x4_approximately_equal(stdmath_degree2x4* a, stdmath_degree2x4* b);

#if 2 == 4
STDMATH_EXPORT stdmath_degree2x2 stdmath_degree2x2_scale(const stdmath_degree2x2* m, stdmath_degree s);
STDMATH_EXPORT stdmath_degree2x2 stdmath_degree2x2_inverse(const stdmath_degree2x2* m);
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

inline stdmath::degree2x4 c(stdmath_degree2x4 c) {
	return (stdmath::degree2x4&)c;
}
inline stdmath_degree2x4 c(stdmath::degree2x4 c) {
	return (stdmath_degree2x4&)c;
}

#ifdef __cplusplus
extern "C" {
#endif

stdmath_degree2x4 stdmath_degree2x4_identity_scaled(stdmath_degree scale) {
	return c(stdmath::degree2x4::identity((stdmath::degree2x4::underlying_type&)scale));
}
stdmath_degree2x4 stdmath_degree2x4_identity() {
	return c(stdmath::degree2x4::identity());
}
stdmath_degree2x4 stdmath_degree2x4_fill(stdmath_degree value) {
	return c(stdmath::degree2x4::fill((stdmath::degree2x4::underlying_type&)value));
}

size_t stdmath_degree2x4_rows(const stdmath_degree2x4* m) {
	return 2;
}
size_t stdmath_degree2x4_columns(const stdmath_degree2x4* m) {
	return 4;
}
size_t stdmath_degree2x4_size(const stdmath_degree2x4* m) {
	return 2 * 4;
}

stdmath_degree stdmath_degree2x4_get_element(const stdmath_degree2x4* m, size_t x, size_t y) {
	return (stdmath_degree&)c(*m)[x, y];
}
stdmath_degree2x4 stdmath_degree2x4_set_element(const stdmath_degree2x4* m, size_t x, size_t y, stdmath_degree value) {
	auto out = c(*m);
	out[x, y] = (stdmath::degree2x4::underlying_type&)value;
	return c(out);
}

stdmath_degree2x4 stdmath_degree2x4_add(const stdmath_degree2x4* a, const stdmath_degree2x4* b) {
	return c(c(*a) + c(*b));
}
stdmath_degree2x4 stdmath_degree2x4_subtract(const stdmath_degree2x4* a, const stdmath_degree2x4* b) {
	return c(c(*a) - c(*b));
}
stdmath_degree2x4 stdmath_degree2x4_negate(const stdmath_degree2x4* m) {
	return c(-c(*m));
}

stdmath_degree4 stdmath_degree2x4_multiply(const stdmath_degree2x4* m, stdmath_degree4 v) {
	return c(stdmath::degree2x4::multiply(c(*m), c(v)));
}

bool stdmath_degree2x4_equal_to(const stdmath_degree2x4* a, const stdmath_degree2x4* b) {
	return c(*a) == c(*b);
}
bool stdmath_degree2x4_not_equal_to(const stdmath_degree2x4* a, const stdmath_degree2x4* b) {
	return c(*a) != c(*b);
}
bool stdmath_degree2x4_approximately_equal(stdmath_degree2x4* a, stdmath_degree2x4* b) {
	return stdmath::approximately_equal(c(*a), c(*b));
}

#if 2 == 4
stdmath_degree2x2 stdmath_degree2x2_scale(const stdmath_degree2x2* m, stdmath_degree s) {
	return c(stdmath::degree2x2::multiply(c(*m), (stdmath::degree2x2::underlying_type&)s));
}
stdmath_degree2x2 stdmath_degree2x2_inverse(const stdmath_degree2x2* m) {
	return c(inverse(c(*m)));
}
#endif

#ifdef __cplusplus
} // extern "C"
#endif

#endif // #ifdef STDMATH_IMPLEMENTATION

#endif // __STDMATH_degree2x4_H__


#ifdef STDMATH_IMPLEMENTATION

#ifdef __cplusplus
extern "C" {
#endif


#ifdef __STDMATH_degree4x2_H__
#ifndef __STDMATH_degree2x4_TRANSPOSE_IMPL__
#define __STDMATH_degree2x4_TRANSPOSE_IMPL__
stdmath_degree4x2 stdmath_degree2x4_transpose(const stdmath_degree2x4* m) {
	return c(transpose(c(*m)));
}
#endif
#endif

#ifdef __STDMATH_degree4x2_H__
#ifdef __STDMATH_degree2x2_H__
#ifndef __STDMATH_degree2x4_2x2_IMPL__
#define __STDMATH_degree2x4_2x2_IMPL__
stdmath_degree2x2 stdmath_degree2x4_multiply2(const stdmath_degree2x4* a, const stdmath_degree4x2* b) {
	return c(stdmath::degree2x4::multiply(c(*a), c(*b)));
}
#endif
#endif
#endif

#ifdef __STDMATH_degree4x3_H__
#ifdef __STDMATH_degree2x3_H__
#ifndef __STDMATH_degree2x4_2x3_IMPL__
#define __STDMATH_degree2x4_2x3_IMPL__
stdmath_degree2x3 stdmath_degree2x4_multiply3(const stdmath_degree2x4* a, const stdmath_degree4x3* b) {
	return c(stdmath::degree2x4::multiply(c(*a), c(*b)));
}
#endif
#endif
#endif

#ifdef __STDMATH_degree4x4_H__
#ifdef __STDMATH_degree2x4_H__
#ifndef __STDMATH_degree2x4_2x4_IMPL__
#define __STDMATH_degree2x4_2x4_IMPL__
stdmath_degree2x4 stdmath_degree2x4_multiply4(const stdmath_degree2x4* a, const stdmath_degree4x4* b) {
	return c(stdmath::degree2x4::multiply(c(*a), c(*b)));
}
#endif
#endif
#endif

#ifdef __cplusplus
} // extern "C"
#endif

#endif // STDMATH_IMPLEMENTATION