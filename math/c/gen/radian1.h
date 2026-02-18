#ifndef __STDMATH_stdmath_radian1_H__
#define __STDMATH_stdmath_radian1_H__

#ifndef STDMATH_MODULE
#include <stdint.h>
#include <assert.h>
#endif
#include "../maybe_export.h"

#if true
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
#include "radian1.h"
#elif 1 == 3
#include "radian2.h"
#include "radian1.h"
#elif 1 == 4
#include "radian3.h"
#include "radian2.h"
#include "radian1.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if 1 == 1
STDMATH_EXPORT union stdmath_radian1 {
	struct {
		stdmath_radian x;
	};
	stdmath_radian data[1];
};
#elif 1 == 2
STDMATH_EXPORT union stdmath_radian2 {
	struct {
		stdmath_radian x, y;
	};
	struct {
		stdmath_radian u, v;
	};
	stdmath_radian data[2];
};
#elif 1 == 3
STDMATH_EXPORT union stdmath_radian3 {
	struct {
		stdmath_radian x, y, z;
	};
	struct {
		stdmath_radian r, g, b;
	};
	struct {
		stdmath_radian h, s, v;
	};
	stdmath_radian data[4]; // radian3s are aligned as if they were radian4s
};
#elif 1 == 4
STDMATH_EXPORT union stdmath_radian4 {
	struct {
		stdmath_radian x, y, z, w;
	};
	struct {
		stdmath_radian r, g, b, a;
	};
	struct {
		stdmath_radian h, s, v;
	};
	stdmath_radian data[4];
};
#endif

STDMATH_EXPORT stdmath_radian1 stdmath_radian1_broadcast(stdmath_radian all);

STDMATH_EXPORT stdmath_radian1 stdmath_radian1_add(stdmath_radian1 a, stdmath_radian1 b);
STDMATH_EXPORT stdmath_radian1 stdmath_radian1_subtract(stdmath_radian1 a, stdmath_radian1 b);
STDMATH_EXPORT stdmath_radian1 stdmath_radian1_negate(stdmath_radian1 v);
STDMATH_EXPORT stdmath_radian1 stdmath_radian1_multiply(stdmath_radian1 a, stdmath_radian1 b);
STDMATH_EXPORT stdmath_radian1 stdmath_radian1_divide(stdmath_radian1 a, stdmath_radian1 b);
STDMATH_EXPORT stdmath_radian1 stdmath_radian1_scale(stdmath_radian1 v, stdmath_radian s);

#if false
STDMATH_EXPORT stdmath_radian1 stdmath_radian1_modulus(stdmath_radian1 a, stdmath_radian1 b);
STDMATH_EXPORT stdmath_radian1 stdmath_radian1_logical_not(stdmath_radian1 v);
STDMATH_EXPORT stdmath_radian1 stdmath_radian1_bitwise_not(stdmath_radian1 v);
STDMATH_EXPORT stdmath_radian1 stdmath_radian1_logical_and(stdmath_radian1 a, stdmath_radian1 b);
STDMATH_EXPORT stdmath_radian1 stdmath_radian1_bitwise_and(stdmath_radian1 a, stdmath_radian1 b);
STDMATH_EXPORT stdmath_radian1 stdmath_radian1_logical_or(stdmath_radian1 a, stdmath_radian1 b);
STDMATH_EXPORT stdmath_radian1 stdmath_radian1_bitwise_or(stdmath_radian1 a, stdmath_radian1 b);
STDMATH_EXPORT stdmath_radian1 stdmath_radian1_bitwise_xor(stdmath_radian1 a, stdmath_radian1 b);
STDMATH_EXPORT stdmath_radian1 stdmath_radian1_shift_left(stdmath_radian1 a, stdmath_radian1 b);
STDMATH_EXPORT stdmath_radian1 stdmath_radian1_shift_right(stdmath_radian1 a, stdmath_radian1 b);
#endif

STDMATH_EXPORT stdmath_bool1 stdmath_radian1_equal_to(stdmath_radian1 a, stdmath_radian1 b);
STDMATH_EXPORT stdmath_bool1 stdmath_radian1_not_equal_to(stdmath_radian1 a, stdmath_radian1 b);
STDMATH_EXPORT stdmath_bool1 stdmath_radian1_less_than(stdmath_radian1 a, stdmath_radian1 b);
STDMATH_EXPORT stdmath_bool1 stdmath_radian1_less_than_or_equal_to(stdmath_radian1 a, stdmath_radian1 b);
STDMATH_EXPORT stdmath_bool1 stdmath_radian1_greater_than(stdmath_radian1 a, stdmath_radian1 b);
STDMATH_EXPORT stdmath_bool1 stdmath_radian1_greater_than_or_equal_to(stdmath_radian1 a, stdmath_radian1 b);

STDMATH_EXPORT stdmath_radian stdmath_radian1_length_squared(stdmath_radian1 v);
STDMATH_EXPORT stdmath_radian stdmath_radian1_length(stdmath_radian1 v);
STDMATH_EXPORT stdmath_radian stdmath_radian1_dot(stdmath_radian1 a, stdmath_radian1 b);
STDMATH_EXPORT stdmath_radian stdmath_radian1_min_element(stdmath_radian1 v);
STDMATH_EXPORT stdmath_radian stdmath_radian1_max_element(stdmath_radian1 v);

// STDMATH_EXPORT stdmath_radian1 stdmath_radian1_elementwise_transform(stdmath_radian1 v, stdmath_radian(*func)(stdmath_radian));
// STDMATH_EXPORT stdmath_radian stdmath_radian1_reduce_elements(stdmath_radian1 v, stdmath_radian initial_value, stdmath_radian(*reducer)(stdmath_radian1, stdmath_radian1));

#if 1 == 3
STDMATH_EXPORT stdmath_radian3 stdmath_radian3_cross(stdmath_radian3 a, stdmath_radian3 b);
#endif

STDMATH_EXPORT stdmath_radian1 stdmath_radian1_min(stdmath_radian1 a, stdmath_radian1 b);
STDMATH_EXPORT stdmath_radian1 stdmath_radian1_max(stdmath_radian1 a, stdmath_radian1 b);
STDMATH_EXPORT stdmath_radian1 stdmath_radian1_normalize(stdmath_radian1 v);
STDMATH_EXPORT stdmath_radian1 stdmath_radian1_lerp(stdmath_radian1 a, stdmath_radian1 b, float t);
STDMATH_EXPORT stdmath_radian1 stdmath_radian1_clamp(stdmath_radian1 a, stdmath_radian1 min, stdmath_radian1 max);
STDMATH_EXPORT stdmath_radian1 stdmath_radian1_reflect(stdmath_radian1 a, stdmath_radian1 b);
STDMATH_EXPORT stdmath_bool1 stdmath_radian1_approximately_equal(stdmath_radian1 a, stdmath_radian1 b);

#if false
STDMATH_EXPORT bool stdmath_bool1_all_of(stdmath_bool1 v);
STDMATH_EXPORT bool stdmath_bool1_any_of(stdmath_bool1 v);
STDMATH_EXPORT bool stdmath_bool1_none_of(stdmath_bool1 v);
STDMATH_EXPORT bool stdmath_bool1_some_of(stdmath_bool1 v);
#endif

#ifndef STDMATH_NO_SWIZZLES
STDMATH_EXPORT STDMATH_INLINE stdmath_radian1 stdmath_radian1_x(stdmath_radian1 v) { return {v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian1 stdmath_radian1_x_get(stdmath_radian1* p) { return stdmath_radian1_x(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian1 stdmath_radian1_x_set(stdmath_radian1* p, stdmath_radian1 value) { p->x = value.x; return *p; }

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

inline stdmath::radian1 c(stdmath_radian1 c) {
	return (stdmath::radian1&)c;
}
inline stdmath_radian1 c(stdmath::radian1 c) {
	return (stdmath_radian1&)c;
}

#ifdef __cplusplus
extern "C" {
#endif

stdmath_radian1 stdmath_radian1_broadcast(stdmath_radian all) {
	return c(stdmath::radian1((stdmath::radian1::underlying_type&)all));
}

stdmath_radian1 stdmath_radian1_add(stdmath_radian1 a, stdmath_radian1 b) {
	return c(c(a) + c(b));
}
stdmath_radian1 stdmath_radian1_subtract(stdmath_radian1 a, stdmath_radian1 b) {
	return c(c(a) - c(b));
}
stdmath_radian1 stdmath_radian1_negate(stdmath_radian1 v) {
#if !true && !false
	return c(stdmath::radian1(-(stdmath::vector<stdmath_radian, 1>)c(v)));
#else
	assert(false && "TODO: Why can't we use - on vector<degree/radian, N>?");
#endif
}
stdmath_radian1 stdmath_radian1_multiply(stdmath_radian1 a, stdmath_radian1 b) {
	return c(c(a) * c(b));
}
stdmath_radian1 stdmath_radian1_divide(stdmath_radian1 a, stdmath_radian1 b) {
	return c(c(a) / c(b));
}
stdmath_radian1 stdmath_radian1_scale(stdmath_radian1 v, stdmath_radian s) {
	return c(c(v) * (stdmath::radian1::underlying_type&)s);
}

#if false
stdmath_radian1 stdmath_radian1_modulus(stdmath_radian1 a, stdmath_radian1 b) {
	return c(c(a) % c(b));
}
stdmath_radian1 stdmath_radian1_logical_not(stdmath_radian1 v) {
	return c(!c(v));
}
stdmath_radian1 stdmath_radian1_bitwise_not(stdmath_radian1 v) {
	return c(~c(v));
}
stdmath_radian1 stdmath_radian1_logical_and(stdmath_radian1 a, stdmath_radian1 b) {
	return c(c(a) && c(b));
}
stdmath_radian1 stdmath_radian1_bitwise_and(stdmath_radian1 a, stdmath_radian1 b) {
	return c(c(a) & c(b));
}
stdmath_radian1 stdmath_radian1_logical_or(stdmath_radian1 a, stdmath_radian1 b) {
	return c(c(a) || c(b));
}
stdmath_radian1 stdmath_radian1_bitwise_or(stdmath_radian1 a, stdmath_radian1 b) {
	return c(c(a) | c(b));
}
stdmath_radian1 stdmath_radian1_bitwise_xor(stdmath_radian1 a, stdmath_radian1 b) {
	return c(c(a) ^ c(b));
}
stdmath_radian1 stdmath_radian1_shift_left(stdmath_radian1 a, stdmath_radian1 b) {
	return c(c(a) << c(b));
}
stdmath_radian1 stdmath_radian1_shift_right(stdmath_radian1 a, stdmath_radian1 b) {
	return c(c(a) >> c(b));
}
#endif

stdmath_bool1 stdmath_radian1_equal_to(stdmath_radian1 a, stdmath_radian1 b) {
	return c(c(a) == c(b));
}
stdmath_bool1 stdmath_radian1_not_equal_to(stdmath_radian1 a, stdmath_radian1 b) {
	return c(c(a) != c(b));
}
stdmath_bool1 stdmath_radian1_less_than(stdmath_radian1 a, stdmath_radian1 b) {
	return c(c(a) < c(b));
}
stdmath_bool1 stdmath_radian1_less_than_or_equal_to(stdmath_radian1 a, stdmath_radian1 b) {
	return c(c(a) <= c(b));
}
stdmath_bool1 stdmath_radian1_greater_than(stdmath_radian1 a, stdmath_radian1 b) {
	return c(c(a) > c(b));
}
stdmath_bool1 stdmath_radian1_greater_than_or_equal_to(stdmath_radian1 a, stdmath_radian1 b) {
	return c(c(a) >= c(b));
}

stdmath_radian stdmath_radian1_length_squared(stdmath_radian1 v)  {
	auto out = c(v).length_squared();
	return (stdmath_radian&)out;
}
stdmath_radian stdmath_radian1_length(stdmath_radian1 v)  {
	auto out = c(v).length();
	return (stdmath_radian&)out;
}
stdmath_radian stdmath_radian1_dot(stdmath_radian1 a, stdmath_radian1 b)  {
	auto out = dot(c(a), c(b));
	return (stdmath_radian&)out;
}
stdmath_radian stdmath_radian1_min_element(stdmath_radian1 v)  {
	auto out = c(v).min_element();
	return (stdmath_radian&)out;
}
stdmath_radian stdmath_radian1_max_element(stdmath_radian1 v)  {
	auto out = c(v).max_element();
	return (stdmath_radian&)out;
}

// stdmath_radian1 stdmath_radian1_elementwise_transform(stdmath_radian1 v, stdmath_radian(*func)(stdmath_radian)) {
// 	return c(c(v).elementwise_transform(func));
// }
// stdmath_radian stdmath_radian1_reduce_elements(stdmath_radian1 v, stdmath_radian initial_value, stdmath_radian(*reducer)(stdmath_radian1, stdmath_radian1)) {
// 	return c(v).reduce_elements(initial_value, reducer);
// }

#if 1 == 3
stdmath_radian1 stdmath_radian1_cross(stdmath_radian1 a, stdmath_radian1 b) {
	return c(cross(c(a), c(b)));
}
#endif

stdmath_radian1 stdmath_radian1_min(stdmath_radian1 a, stdmath_radian1 b) {
	return c(min(c(a), c(b)));
}
stdmath_radian1 stdmath_radian1_max(stdmath_radian1 a, stdmath_radian1 b) {
	return c(max(c(a), c(b)));
}
stdmath_radian1 stdmath_radian1_normalize(stdmath_radian1 v) {
	return c(normalize(c(v)));
}
stdmath_radian1 stdmath_radian1_lerp(stdmath_radian1 a, stdmath_radian1 b, float t) {
	return c(lerp(c(a), c(b), t));
}
stdmath_radian1 stdmath_radian1_clamp(stdmath_radian1 a, stdmath_radian1 min, stdmath_radian1 max) {
	return c(clamp(c(a), c(min), c(max)));
}
stdmath_radian1 stdmath_radian1_reflect(stdmath_radian1 a, stdmath_radian1 b) {
	return c(reflect(c(a), c(b)));
}
stdmath_bool1 stdmath_radian1_approximately_equal(stdmath_radian1 a, stdmath_radian1 b) {
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

#endif // __STDMATH_stdmath_radian1_H__