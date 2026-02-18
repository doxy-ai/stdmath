#ifndef __STDMATH_uint32_t1_H__
#define __STDMATH_uint32_t1_H__

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
#include "uint1.h"
#elif 1 == 3
#include "uint2.h"
#include "uint1.h"
#elif 1 == 4
#include "uint3.h"
#include "uint2.h"
#include "uint1.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if 1 == 1
STDMATH_EXPORT union stdmath_uint1 {
	struct {
		uint32_t x;
	};
	uint32_t data[1];
};
#elif 1 == 2
STDMATH_EXPORT union stdmath_uint2 {
	struct {
		uint32_t x, y;
	};
	struct {
		uint32_t u, v;
	};
	uint32_t data[2];
};
#elif 1 == 3
STDMATH_EXPORT union stdmath_uint3 {
	struct {
		uint32_t x, y, z;
	};
	struct {
		uint32_t r, g, b;
	};
	struct {
		uint32_t h, s, v;
	};
	uint32_t data[4]; // uint3s are aligned as if they were uint4s
};
#elif 1 == 4
STDMATH_EXPORT union stdmath_uint4 {
	struct {
		uint32_t x, y, z, w;
	};
	struct {
		uint32_t r, g, b, a;
	};
	struct {
		uint32_t h, s, v;
	};
	uint32_t data[4];
};
#endif

STDMATH_EXPORT stdmath_uint1 stdmath_uint1_broadcast(uint32_t all);

STDMATH_EXPORT stdmath_uint1 stdmath_uint1_add(stdmath_uint1 a, stdmath_uint1 b);
STDMATH_EXPORT stdmath_uint1 stdmath_uint1_subtract(stdmath_uint1 a, stdmath_uint1 b);
STDMATH_EXPORT stdmath_uint1 stdmath_uint1_negate(stdmath_uint1 v);
STDMATH_EXPORT stdmath_uint1 stdmath_uint1_multiply(stdmath_uint1 a, stdmath_uint1 b);
STDMATH_EXPORT stdmath_uint1 stdmath_uint1_divide(stdmath_uint1 a, stdmath_uint1 b);
STDMATH_EXPORT stdmath_uint1 stdmath_uint1_scale(stdmath_uint1 v, uint32_t s);

#if false
STDMATH_EXPORT stdmath_uint1 stdmath_uint1_modulus(stdmath_uint1 a, stdmath_uint1 b);
STDMATH_EXPORT stdmath_uint1 stdmath_uint1_logical_not(stdmath_uint1 v);
STDMATH_EXPORT stdmath_uint1 stdmath_uint1_bitwise_not(stdmath_uint1 v);
STDMATH_EXPORT stdmath_uint1 stdmath_uint1_logical_and(stdmath_uint1 a, stdmath_uint1 b);
STDMATH_EXPORT stdmath_uint1 stdmath_uint1_bitwise_and(stdmath_uint1 a, stdmath_uint1 b);
STDMATH_EXPORT stdmath_uint1 stdmath_uint1_logical_or(stdmath_uint1 a, stdmath_uint1 b);
STDMATH_EXPORT stdmath_uint1 stdmath_uint1_bitwise_or(stdmath_uint1 a, stdmath_uint1 b);
STDMATH_EXPORT stdmath_uint1 stdmath_uint1_bitwise_xor(stdmath_uint1 a, stdmath_uint1 b);
STDMATH_EXPORT stdmath_uint1 stdmath_uint1_shift_left(stdmath_uint1 a, stdmath_uint1 b);
STDMATH_EXPORT stdmath_uint1 stdmath_uint1_shift_right(stdmath_uint1 a, stdmath_uint1 b);
#endif

STDMATH_EXPORT stdmath_bool1 stdmath_uint1_equal_to(stdmath_uint1 a, stdmath_uint1 b);
STDMATH_EXPORT stdmath_bool1 stdmath_uint1_not_equal_to(stdmath_uint1 a, stdmath_uint1 b);
STDMATH_EXPORT stdmath_bool1 stdmath_uint1_less_than(stdmath_uint1 a, stdmath_uint1 b);
STDMATH_EXPORT stdmath_bool1 stdmath_uint1_less_than_or_equal_to(stdmath_uint1 a, stdmath_uint1 b);
STDMATH_EXPORT stdmath_bool1 stdmath_uint1_greater_than(stdmath_uint1 a, stdmath_uint1 b);
STDMATH_EXPORT stdmath_bool1 stdmath_uint1_greater_than_or_equal_to(stdmath_uint1 a, stdmath_uint1 b);

STDMATH_EXPORT uint32_t stdmath_uint1_length_squared(stdmath_uint1 v);
STDMATH_EXPORT uint32_t stdmath_uint1_length(stdmath_uint1 v);
STDMATH_EXPORT uint32_t stdmath_uint1_dot(stdmath_uint1 a, stdmath_uint1 b);
STDMATH_EXPORT uint32_t stdmath_uint1_min_element(stdmath_uint1 v);
STDMATH_EXPORT uint32_t stdmath_uint1_max_element(stdmath_uint1 v);

// STDMATH_EXPORT stdmath_uint1 stdmath_uint1_elementwise_transform(stdmath_uint1 v, uint32_t(*func)(uint32_t));
// STDMATH_EXPORT uint32_t stdmath_uint1_reduce_elements(stdmath_uint1 v, uint32_t initial_value, uint32_t(*reducer)(stdmath_uint1, stdmath_uint1));

#if 1 == 3
STDMATH_EXPORT stdmath_uint3 stdmath_uint3_cross(stdmath_uint3 a, stdmath_uint3 b);
#endif

STDMATH_EXPORT stdmath_uint1 stdmath_uint1_min(stdmath_uint1 a, stdmath_uint1 b);
STDMATH_EXPORT stdmath_uint1 stdmath_uint1_max(stdmath_uint1 a, stdmath_uint1 b);
STDMATH_EXPORT stdmath_uint1 stdmath_uint1_normalize(stdmath_uint1 v);
STDMATH_EXPORT stdmath_uint1 stdmath_uint1_lerp(stdmath_uint1 a, stdmath_uint1 b, float t);
STDMATH_EXPORT stdmath_uint1 stdmath_uint1_clamp(stdmath_uint1 a, stdmath_uint1 min, stdmath_uint1 max);
STDMATH_EXPORT stdmath_uint1 stdmath_uint1_reflect(stdmath_uint1 a, stdmath_uint1 b);
STDMATH_EXPORT stdmath_bool1 stdmath_uint1_approximately_equal(stdmath_uint1 a, stdmath_uint1 b);

#if false
STDMATH_EXPORT bool stdmath_bool1_all_of(stdmath_bool1 v);
STDMATH_EXPORT bool stdmath_bool1_any_of(stdmath_bool1 v);
STDMATH_EXPORT bool stdmath_bool1_none_of(stdmath_bool1 v);
STDMATH_EXPORT bool stdmath_bool1_some_of(stdmath_bool1 v);
#endif

#ifndef STDMATH_NO_SWIZZLES
STDMATH_EXPORT STDMATH_INLINE stdmath_uint1 stdmath_uint1_x(stdmath_uint1 v) { return {v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_uint1 stdmath_uint1_x_get(stdmath_uint1* p) { return stdmath_uint1_x(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_uint1 stdmath_uint1_x_set(stdmath_uint1* p, stdmath_uint1 value) { p->x = value.x; return *p; }

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

inline stdmath::uint1 c(stdmath_uint1 c) {
	return (stdmath::uint1&)c;
}
inline stdmath_uint1 c(stdmath::uint1 c) {
	return (stdmath_uint1&)c;
}

#ifdef __cplusplus
extern "C" {
#endif

stdmath_uint1 stdmath_uint1_broadcast(uint32_t all) {
	return c(stdmath::uint1((stdmath::uint1::underlying_type&)all));
}

stdmath_uint1 stdmath_uint1_add(stdmath_uint1 a, stdmath_uint1 b) {
	return c(c(a) + c(b));
}
stdmath_uint1 stdmath_uint1_subtract(stdmath_uint1 a, stdmath_uint1 b) {
	return c(c(a) - c(b));
}
stdmath_uint1 stdmath_uint1_negate(stdmath_uint1 v) {
#if !false && !false
	return c(stdmath::uint1(-(stdmath::vector<uint32_t, 1>)c(v)));
#else
	assert(false && "TODO: Why can't we use - on vector<degree/radian, N>?");
#endif
}
stdmath_uint1 stdmath_uint1_multiply(stdmath_uint1 a, stdmath_uint1 b) {
	return c(c(a) * c(b));
}
stdmath_uint1 stdmath_uint1_divide(stdmath_uint1 a, stdmath_uint1 b) {
	return c(c(a) / c(b));
}
stdmath_uint1 stdmath_uint1_scale(stdmath_uint1 v, uint32_t s) {
	return c(c(v) * (stdmath::uint1::underlying_type&)s);
}

#if false
stdmath_uint1 stdmath_uint1_modulus(stdmath_uint1 a, stdmath_uint1 b) {
	return c(c(a) % c(b));
}
stdmath_uint1 stdmath_uint1_logical_not(stdmath_uint1 v) {
	return c(!c(v));
}
stdmath_uint1 stdmath_uint1_bitwise_not(stdmath_uint1 v) {
	return c(~c(v));
}
stdmath_uint1 stdmath_uint1_logical_and(stdmath_uint1 a, stdmath_uint1 b) {
	return c(c(a) && c(b));
}
stdmath_uint1 stdmath_uint1_bitwise_and(stdmath_uint1 a, stdmath_uint1 b) {
	return c(c(a) & c(b));
}
stdmath_uint1 stdmath_uint1_logical_or(stdmath_uint1 a, stdmath_uint1 b) {
	return c(c(a) || c(b));
}
stdmath_uint1 stdmath_uint1_bitwise_or(stdmath_uint1 a, stdmath_uint1 b) {
	return c(c(a) | c(b));
}
stdmath_uint1 stdmath_uint1_bitwise_xor(stdmath_uint1 a, stdmath_uint1 b) {
	return c(c(a) ^ c(b));
}
stdmath_uint1 stdmath_uint1_shift_left(stdmath_uint1 a, stdmath_uint1 b) {
	return c(c(a) << c(b));
}
stdmath_uint1 stdmath_uint1_shift_right(stdmath_uint1 a, stdmath_uint1 b) {
	return c(c(a) >> c(b));
}
#endif

stdmath_bool1 stdmath_uint1_equal_to(stdmath_uint1 a, stdmath_uint1 b) {
	return c(c(a) == c(b));
}
stdmath_bool1 stdmath_uint1_not_equal_to(stdmath_uint1 a, stdmath_uint1 b) {
	return c(c(a) != c(b));
}
stdmath_bool1 stdmath_uint1_less_than(stdmath_uint1 a, stdmath_uint1 b) {
	return c(c(a) < c(b));
}
stdmath_bool1 stdmath_uint1_less_than_or_equal_to(stdmath_uint1 a, stdmath_uint1 b) {
	return c(c(a) <= c(b));
}
stdmath_bool1 stdmath_uint1_greater_than(stdmath_uint1 a, stdmath_uint1 b) {
	return c(c(a) > c(b));
}
stdmath_bool1 stdmath_uint1_greater_than_or_equal_to(stdmath_uint1 a, stdmath_uint1 b) {
	return c(c(a) >= c(b));
}

uint32_t stdmath_uint1_length_squared(stdmath_uint1 v)  {
	auto out = c(v).length_squared();
	return (uint32_t&)out;
}
uint32_t stdmath_uint1_length(stdmath_uint1 v)  {
	auto out = c(v).length();
	return (uint32_t&)out;
}
uint32_t stdmath_uint1_dot(stdmath_uint1 a, stdmath_uint1 b)  {
	auto out = dot(c(a), c(b));
	return (uint32_t&)out;
}
uint32_t stdmath_uint1_min_element(stdmath_uint1 v)  {
	auto out = c(v).min_element();
	return (uint32_t&)out;
}
uint32_t stdmath_uint1_max_element(stdmath_uint1 v)  {
	auto out = c(v).max_element();
	return (uint32_t&)out;
}

// stdmath_uint1 stdmath_uint1_elementwise_transform(stdmath_uint1 v, uint32_t(*func)(uint32_t)) {
// 	return c(c(v).elementwise_transform(func));
// }
// uint32_t stdmath_uint1_reduce_elements(stdmath_uint1 v, uint32_t initial_value, uint32_t(*reducer)(stdmath_uint1, stdmath_uint1)) {
// 	return c(v).reduce_elements(initial_value, reducer);
// }

#if 1 == 3
stdmath_uint1 stdmath_uint1_cross(stdmath_uint1 a, stdmath_uint1 b) {
	return c(cross(c(a), c(b)));
}
#endif

stdmath_uint1 stdmath_uint1_min(stdmath_uint1 a, stdmath_uint1 b) {
	return c(min(c(a), c(b)));
}
stdmath_uint1 stdmath_uint1_max(stdmath_uint1 a, stdmath_uint1 b) {
	return c(max(c(a), c(b)));
}
stdmath_uint1 stdmath_uint1_normalize(stdmath_uint1 v) {
	return c(normalize(c(v)));
}
stdmath_uint1 stdmath_uint1_lerp(stdmath_uint1 a, stdmath_uint1 b, float t) {
	return c(lerp(c(a), c(b), t));
}
stdmath_uint1 stdmath_uint1_clamp(stdmath_uint1 a, stdmath_uint1 min, stdmath_uint1 max) {
	return c(clamp(c(a), c(min), c(max)));
}
stdmath_uint1 stdmath_uint1_reflect(stdmath_uint1 a, stdmath_uint1 b) {
	return c(reflect(c(a), c(b)));
}
stdmath_bool1 stdmath_uint1_approximately_equal(stdmath_uint1 a, stdmath_uint1 b) {
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

#endif // __STDMATH_uint32_t1_H__