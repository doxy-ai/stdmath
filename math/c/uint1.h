#ifndef __STDMATH_uint32_t1_H__
#define __STDMATH_uint32_t1_H__

#include <stdint.h>
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
#include "util.h"

#if 1 == 1
union stdmath_uint1 {
	struct {
		uint32_t x;
	};
	uint32_t data[1];
};
#elif 1 == 2
union stdmath_uint2 {
	struct {
		uint32_t x, y;
	};
	struct {
		uint32_t u, v;
	};
	uint32_t data[2];
};
#elif 1 == 3
union stdmath_uint3 {
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
union stdmath_uint4 {
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

stdmath_uint1 stdmath_uint1_broadcast(uint32_t all);

stdmath_uint1 stdmath_uint1_add(stdmath_uint1 a, stdmath_uint1 b);
stdmath_uint1 stdmath_uint1_subtract(stdmath_uint1 a, stdmath_uint1 b);
stdmath_uint1 stdmath_uint1_negate(stdmath_uint1 v);
stdmath_uint1 stdmath_uint1_multiply(stdmath_uint1 a, stdmath_uint1 b);
stdmath_uint1 stdmath_uint1_divide(stdmath_uint1 a, stdmath_uint1 b);
stdmath_uint1 stdmath_uint1_scale(stdmath_uint1 v, uint32_t s);

#if false
stdmath_uint1 stdmath_uint1_modulus(stdmath_uint1 a, stdmath_uint1 b);
stdmath_uint1 stdmath_uint1_logical_not(stdmath_uint1 v);
stdmath_uint1 stdmath_uint1_bitwise_not(stdmath_uint1 v);
stdmath_uint1 stdmath_uint1_logical_and(stdmath_uint1 a, stdmath_uint1 b);
stdmath_uint1 stdmath_uint1_bitwise_and(stdmath_uint1 a, stdmath_uint1 b);
stdmath_uint1 stdmath_uint1_logical_or(stdmath_uint1 a, stdmath_uint1 b);
stdmath_uint1 stdmath_uint1_bitwise_or(stdmath_uint1 a, stdmath_uint1 b);
stdmath_uint1 stdmath_uint1_bitwise_xor(stdmath_uint1 a, stdmath_uint1 b);
stdmath_uint1 stdmath_uint1_shift_left(stdmath_uint1 a, stdmath_uint1 b);
stdmath_uint1 stdmath_uint1_shift_right(stdmath_uint1 a, stdmath_uint1 b);
#endif

stdmath_bool1 stdmath_uint1_equal_to(stdmath_uint1 a, stdmath_uint1 b);
stdmath_bool1 stdmath_uint1_not_equal_to(stdmath_uint1 a, stdmath_uint1 b);
stdmath_bool1 stdmath_uint1_less_than(stdmath_uint1 a, stdmath_uint1 b);
stdmath_bool1 stdmath_uint1_less_than_or_equal_to(stdmath_uint1 a, stdmath_uint1 b);
stdmath_bool1 stdmath_uint1_greater_than(stdmath_uint1 a, stdmath_uint1 b);
stdmath_bool1 stdmath_uint1_greater_than_or_equal_to(stdmath_uint1 a, stdmath_uint1 b);

uint32_t stdmath_uint1_length_squared(stdmath_uint1 v);
uint32_t stdmath_uint1_length(stdmath_uint1 v);
uint32_t stdmath_uint1_dot(stdmath_uint1 v);
uint32_t stdmath_uint1_min_element(stdmath_uint1 v);
uint32_t stdmath_uint1_max_element(stdmath_uint1 v);

stdmath_uint1 stdmath_uint1_elementwise_transform(stdmath_uint1 v, uint32_t(*func)(uint32_t));
// uint32_t stdmath_uint1_reduce_elements(stdmath_uint1 v, uint32_t initial_value, uint32_t(*reducer)(stdmath_uint1, stdmath_uint1));

#if 1 == 3
stdmath_uint3 stdmath_uint3_cross(stdmath_uint3 a, stdmath_uint3 b);
#endif

stdmath_uint1 stdmath_uint1_min(stdmath_uint1 a, stdmath_uint1 b);
stdmath_uint1 stdmath_uint1_max(stdmath_uint1 a, stdmath_uint1 b);
stdmath_uint1 stdmath_uint1_normalize(stdmath_uint1 v);
stdmath_uint1 stdmath_uint1_lerp(stdmath_uint1 a, stdmath_uint1 b, float t);
stdmath_uint1 stdmath_uint1_clamp(stdmath_uint1 a, stdmath_uint1 min, stdmath_uint1 max);
stdmath_uint1 stdmath_uint1_reflect(stdmath_uint1 a, stdmath_uint1 b);
stdmath_bool1 stdmath_uint1_approximately_equal(stdmath_uint1 a, stdmath_uint1 b);

#if false
bool stdmath_bool1_all_of(stdmath_bool1 v);
bool stdmath_bool1_any_of(stdmath_bool1 v);
bool stdmath_bool1_none_of(stdmath_bool1 v);
bool stdmath_bool1_some_of(stdmath_bool1 v);
#endif

inline static stdmath_uint1 stdmath_uint1_x(stdmath_uint1 v) { return {v.x}; }
inline static stdmath_uint1 stdmath_uint1_x_value(stdmath_uint1 v, stdmath_uint1 value) { v.x = value.x; return v; }


#ifdef STDMATH_IMPLEMENTATION
#ifndef __cplusplus
#error "The stdmath implementations require a C++ compiler"
#endif

import stdmath.slang;

stdmath::uint1 c(stdmath_uint1 c) {
	return (stdmath::uint1&)c;
}
stdmath_uint1 c(stdmath::uint1 c) {
	return (stdmath_uint1&)c;
}

stdmath_uint1 stdmath_uint1_broadcast(uint32_t all) {
	return c(stdmath::uint1((stdmath::uint1::underlying_type)all));
}

stdmath_uint1 stdmath_uint1_add(stdmath_uint1 a, stdmath_uint1 b) {
	return c(c(a) + c(b));
}
stdmath_uint1 stdmath_uint1_subtract(stdmath_uint1 a, stdmath_uint1 b) {
	return c(c(a) - c(b));
}
stdmath_uint1 stdmath_uint1_negate(stdmath_uint1 v) {
	return c(stdmath::uint1(-(stdmath::vector<uint32_t, 1>)c(v)));
}
stdmath_uint1 stdmath_uint1_multiply(stdmath_uint1 a, stdmath_uint1 b) {
	return c(c(a) * c(b));
}
stdmath_uint1 stdmath_uint1_divide(stdmath_uint1 a, stdmath_uint1 b) {
	return c(c(a) / c(b));
}
stdmath_uint1 stdmath_uint1_scale(stdmath_uint1 v, uint32_t s) {
	return c(c(v) * (stdmath::uint1::underlying_type)s);
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
	return (uint32_t)c(v).length_squared();
}
uint32_t stdmath_uint1_length(stdmath_uint1 v)  {
	return (uint32_t)c(v).length();
}
uint32_t stdmath_uint1_dot(stdmath_uint1 a, stdmath_uint1 b)  {
	return (uint32_t)dot(c(a), c(b));
}
uint32_t stdmath_uint1_min_element(stdmath_uint1 v)  {
	return (uint32_t)c(v).min_element();
}
uint32_t stdmath_uint1_max_element(stdmath_uint1 v)  {
	return (uint32_t)c(v).max_element();
}

stdmath_uint1 stdmath_uint1_elementwise_transform(stdmath_uint1 v, uint32_t(*func)(uint32_t)) {
	return c(c(v).elementwise_transform(func));
}
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

#endif // STDMATH_IMPLEMENTATION

#endif // __STDMATH_uint32_t1_H__