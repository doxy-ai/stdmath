#ifndef __STDMATH_double1_H__
#define __STDMATH_double1_H__

#ifndef STDMATH_MODULE
#include <stdint.h>
#include <assert.h>
#endif
#include "../maybe_export.h"

#if false
#include "radian.h"
#endif
#if false
#include "degree.h"
#endif

#if !false
#if 1 == 1
#include "bool1.h"
#elif 1 == 2
#include "bool2.h"
#elif 1 == 3
#include "bool3.h"
#elif 1 == 4
#include "bool4.h"
#endif
#endif
#if 1 == 2
#include "double1.h"
#elif 1 == 3
#include "double2.h"
#include "double1.h"
#elif 1 == 4
#include "double3.h"
#include "double2.h"
#include "double1.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if 1 == 1
STDMATH_EXPORT union stdmath_double1 {
	struct {
		double x;
	};
	double data[1];
};
#elif 1 == 2
STDMATH_EXPORT union stdmath_double2 {
	struct {
		double x, y;
	};
	struct {
		double u, v;
	};
	double data[2];
};
#elif 1 == 3
STDMATH_EXPORT union stdmath_double3 {
	struct {
		double x, y, z;
	};
	struct {
		double r, g, b;
	};
	struct {
		double h, s, v;
	};
	double data[4]; // double3s are aligned as if they were double4s
};
#elif 1 == 4
STDMATH_EXPORT union stdmath_double4 {
	struct {
		double x, y, z, w;
	};
	struct {
		double r, g, b, a;
	};
	struct {
		double h, s, v;
	};
	double data[4];
};
#endif

STDMATH_EXPORT stdmath_double1 stdmath_double1_broadcast(double all);

STDMATH_EXPORT stdmath_double1 stdmath_double1_add(stdmath_double1 a, stdmath_double1 b);
STDMATH_EXPORT stdmath_double1 stdmath_double1_subtract(stdmath_double1 a, stdmath_double1 b);
STDMATH_EXPORT stdmath_double1 stdmath_double1_negate(stdmath_double1 v);
STDMATH_EXPORT stdmath_double1 stdmath_double1_multiply(stdmath_double1 a, stdmath_double1 b);
STDMATH_EXPORT stdmath_double1 stdmath_double1_divide(stdmath_double1 a, stdmath_double1 b);
STDMATH_EXPORT stdmath_double1 stdmath_double1_scale(stdmath_double1 v, double s);

#if false
STDMATH_EXPORT stdmath_double1 stdmath_double1_modulus(stdmath_double1 a, stdmath_double1 b);
STDMATH_EXPORT stdmath_double1 stdmath_double1_logical_not(stdmath_double1 v);
STDMATH_EXPORT stdmath_double1 stdmath_double1_bitwise_not(stdmath_double1 v);
STDMATH_EXPORT stdmath_double1 stdmath_double1_logical_and(stdmath_double1 a, stdmath_double1 b);
STDMATH_EXPORT stdmath_double1 stdmath_double1_bitwise_and(stdmath_double1 a, stdmath_double1 b);
STDMATH_EXPORT stdmath_double1 stdmath_double1_logical_or(stdmath_double1 a, stdmath_double1 b);
STDMATH_EXPORT stdmath_double1 stdmath_double1_bitwise_or(stdmath_double1 a, stdmath_double1 b);
STDMATH_EXPORT stdmath_double1 stdmath_double1_bitwise_xor(stdmath_double1 a, stdmath_double1 b);
STDMATH_EXPORT stdmath_double1 stdmath_double1_shift_left(stdmath_double1 a, stdmath_double1 b);
STDMATH_EXPORT stdmath_double1 stdmath_double1_shift_right(stdmath_double1 a, stdmath_double1 b);
#endif

STDMATH_EXPORT stdmath_bool1 stdmath_double1_equal_to(stdmath_double1 a, stdmath_double1 b);
STDMATH_EXPORT stdmath_bool1 stdmath_double1_not_equal_to(stdmath_double1 a, stdmath_double1 b);
STDMATH_EXPORT stdmath_bool1 stdmath_double1_less_than(stdmath_double1 a, stdmath_double1 b);
STDMATH_EXPORT stdmath_bool1 stdmath_double1_less_than_or_equal_to(stdmath_double1 a, stdmath_double1 b);
STDMATH_EXPORT stdmath_bool1 stdmath_double1_greater_than(stdmath_double1 a, stdmath_double1 b);
STDMATH_EXPORT stdmath_bool1 stdmath_double1_greater_than_or_equal_to(stdmath_double1 a, stdmath_double1 b);

STDMATH_EXPORT double stdmath_double1_length_squared(stdmath_double1 v);
STDMATH_EXPORT double stdmath_double1_length(stdmath_double1 v);
STDMATH_EXPORT double stdmath_double1_dot(stdmath_double1 a, stdmath_double1 b);
STDMATH_EXPORT double stdmath_double1_min_element(stdmath_double1 v);
STDMATH_EXPORT double stdmath_double1_max_element(stdmath_double1 v);

// STDMATH_EXPORT stdmath_double1 stdmath_double1_elementwise_transform(stdmath_double1 v, double(*func)(double));
// STDMATH_EXPORT double stdmath_double1_reduce_elements(stdmath_double1 v, double initial_value, double(*reducer)(stdmath_double1, stdmath_double1));

#if 1 == 3
STDMATH_EXPORT stdmath_double3 stdmath_double3_cross(stdmath_double3 a, stdmath_double3 b);
#endif

STDMATH_EXPORT stdmath_double1 stdmath_double1_min(stdmath_double1 a, stdmath_double1 b);
STDMATH_EXPORT stdmath_double1 stdmath_double1_max(stdmath_double1 a, stdmath_double1 b);
STDMATH_EXPORT stdmath_double1 stdmath_double1_normalize(stdmath_double1 v);
STDMATH_EXPORT stdmath_double1 stdmath_double1_lerp(stdmath_double1 a, stdmath_double1 b, float t);
STDMATH_EXPORT stdmath_double1 stdmath_double1_clamp(stdmath_double1 a, stdmath_double1 min, stdmath_double1 max);
STDMATH_EXPORT stdmath_double1 stdmath_double1_reflect(stdmath_double1 a, stdmath_double1 b);
STDMATH_EXPORT stdmath_bool1 stdmath_double1_approximately_equal(stdmath_double1 a, stdmath_double1 b);

#if false
STDMATH_EXPORT bool stdmath_bool1_all_of(stdmath_bool1 v);
STDMATH_EXPORT bool stdmath_bool1_any_of(stdmath_bool1 v);
STDMATH_EXPORT bool stdmath_bool1_none_of(stdmath_bool1 v);
STDMATH_EXPORT bool stdmath_bool1_some_of(stdmath_bool1 v);
#endif

#ifndef STDMATH_NO_SWIZZLES
STDMATH_EXPORT STDMATH_INLINE stdmath_double1 stdmath_double1_x(stdmath_double1 v) { return {v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_double1 stdmath_double1_x_get(stdmath_double1* p) { return stdmath_double1_x(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_double1 stdmath_double1_x_set(stdmath_double1* p, stdmath_double1 value) { p->x = value.x; return *p; }

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

inline stdmath::double1 c(stdmath_double1 c) {
	return (stdmath::double1&)c;
}
inline stdmath_double1 c(stdmath::double1 c) {
	return (stdmath_double1&)c;
}

#ifdef __cplusplus
extern "C" {
#endif

stdmath_double1 stdmath_double1_broadcast(double all) {
	return c(stdmath::double1((stdmath::double1::underlying_type&)all));
}

stdmath_double1 stdmath_double1_add(stdmath_double1 a, stdmath_double1 b) {
	return c(c(a) + c(b));
}
stdmath_double1 stdmath_double1_subtract(stdmath_double1 a, stdmath_double1 b) {
	return c(c(a) - c(b));
}
stdmath_double1 stdmath_double1_negate(stdmath_double1 v) {
#if !false && !false
	return c(stdmath::double1(-(stdmath::vector<double, 1>)c(v)));
#else
	assert(false && "TODO: Why can't we use - on vector<degree/radian, N>?");
#endif
}
stdmath_double1 stdmath_double1_multiply(stdmath_double1 a, stdmath_double1 b) {
	return c(c(a) * c(b));
}
stdmath_double1 stdmath_double1_divide(stdmath_double1 a, stdmath_double1 b) {
	return c(c(a) / c(b));
}
stdmath_double1 stdmath_double1_scale(stdmath_double1 v, double s) {
	return c(c(v) * (stdmath::double1::underlying_type&)s);
}

#if false
stdmath_double1 stdmath_double1_modulus(stdmath_double1 a, stdmath_double1 b) {
	return c(c(a) % c(b));
}
stdmath_double1 stdmath_double1_logical_not(stdmath_double1 v) {
	return c(!c(v));
}
stdmath_double1 stdmath_double1_bitwise_not(stdmath_double1 v) {
	return c(~c(v));
}
stdmath_double1 stdmath_double1_logical_and(stdmath_double1 a, stdmath_double1 b) {
	return c(c(a) && c(b));
}
stdmath_double1 stdmath_double1_bitwise_and(stdmath_double1 a, stdmath_double1 b) {
	return c(c(a) & c(b));
}
stdmath_double1 stdmath_double1_logical_or(stdmath_double1 a, stdmath_double1 b) {
	return c(c(a) || c(b));
}
stdmath_double1 stdmath_double1_bitwise_or(stdmath_double1 a, stdmath_double1 b) {
	return c(c(a) | c(b));
}
stdmath_double1 stdmath_double1_bitwise_xor(stdmath_double1 a, stdmath_double1 b) {
	return c(c(a) ^ c(b));
}
stdmath_double1 stdmath_double1_shift_left(stdmath_double1 a, stdmath_double1 b) {
	return c(c(a) << c(b));
}
stdmath_double1 stdmath_double1_shift_right(stdmath_double1 a, stdmath_double1 b) {
	return c(c(a) >> c(b));
}
#endif

stdmath_bool1 stdmath_double1_equal_to(stdmath_double1 a, stdmath_double1 b) {
	return c(c(a) == c(b));
}
stdmath_bool1 stdmath_double1_not_equal_to(stdmath_double1 a, stdmath_double1 b) {
	return c(c(a) != c(b));
}
stdmath_bool1 stdmath_double1_less_than(stdmath_double1 a, stdmath_double1 b) {
	return c(c(a) < c(b));
}
stdmath_bool1 stdmath_double1_less_than_or_equal_to(stdmath_double1 a, stdmath_double1 b) {
	return c(c(a) <= c(b));
}
stdmath_bool1 stdmath_double1_greater_than(stdmath_double1 a, stdmath_double1 b) {
	return c(c(a) > c(b));
}
stdmath_bool1 stdmath_double1_greater_than_or_equal_to(stdmath_double1 a, stdmath_double1 b) {
	return c(c(a) >= c(b));
}

double stdmath_double1_length_squared(stdmath_double1 v)  {
	auto out = c(v).length_squared();
	return (double&)out;
}
double stdmath_double1_length(stdmath_double1 v)  {
	auto out = c(v).length();
	return (double&)out;
}
double stdmath_double1_dot(stdmath_double1 a, stdmath_double1 b)  {
	auto out = dot(c(a), c(b));
	return (double&)out;
}
double stdmath_double1_min_element(stdmath_double1 v)  {
	auto out = c(v).min_element();
	return (double&)out;
}
double stdmath_double1_max_element(stdmath_double1 v)  {
	auto out = c(v).max_element();
	return (double&)out;
}

// stdmath_double1 stdmath_double1_elementwise_transform(stdmath_double1 v, double(*func)(double)) {
// 	return c(c(v).elementwise_transform(func));
// }
// double stdmath_double1_reduce_elements(stdmath_double1 v, double initial_value, double(*reducer)(stdmath_double1, stdmath_double1)) {
// 	return c(v).reduce_elements(initial_value, reducer);
// }

#if 1 == 3
stdmath_double1 stdmath_double1_cross(stdmath_double1 a, stdmath_double1 b) {
	return c(cross(c(a), c(b)));
}
#endif

stdmath_double1 stdmath_double1_min(stdmath_double1 a, stdmath_double1 b) {
	return c(min(c(a), c(b)));
}
stdmath_double1 stdmath_double1_max(stdmath_double1 a, stdmath_double1 b) {
	return c(max(c(a), c(b)));
}
stdmath_double1 stdmath_double1_normalize(stdmath_double1 v) {
	return c(normalize(c(v)));
}
stdmath_double1 stdmath_double1_lerp(stdmath_double1 a, stdmath_double1 b, float t) {
	return c(lerp(c(a), c(b), t));
}
stdmath_double1 stdmath_double1_clamp(stdmath_double1 a, stdmath_double1 min, stdmath_double1 max) {
	return c(clamp(c(a), c(min), c(max)));
}
stdmath_double1 stdmath_double1_reflect(stdmath_double1 a, stdmath_double1 b) {
	return c(reflect(c(a), c(b)));
}
stdmath_bool1 stdmath_double1_approximately_equal(stdmath_double1 a, stdmath_double1 b) {
	return c(approximately_equal(c(a), c(b)));
}

#if false
bool stdmath_bool1_all_of(stdmath_bool1 v) {
	return all_of(c(v));
}
bool stdmath_bool1_any_of(stdmath_bool1 v) {
	return any_of(c(v));
}
bool stdmath_bool1_none_of(stdmath_bool1 v) {
	return none_of(c(v));
}
bool stdmath_bool1_some_of(stdmath_bool1 v) {
	return some_of(c(v));
}
#endif

#ifdef __cplusplus
} // extern "C"
#endif

#endif // STDMATH_IMPLEMENTATION

#endif // __STDMATH_double1_H__