#ifndef __STDMATH_uint8_t1_H__
#define __STDMATH_uint8_t1_H__

#ifndef STDMATH_MODULE
#include <stdint.h>
#endif
#include "../maybe_export.h"

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
#include "byte1.h"
#elif 1 == 3
#include "byte2.h"
#include "byte1.h"
#elif 1 == 4
#include "byte3.h"
#include "byte2.h"
#include "byte1.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if 1 == 1
STDMATH_EXPORT union stdmath_byte1 {
	struct {
		uint8_t x;
	};
	uint8_t data[1];
};
#elif 1 == 2
STDMATH_EXPORT union stdmath_byte2 {
	struct {
		uint8_t x, y;
	};
	struct {
		uint8_t u, v;
	};
	uint8_t data[2];
};
#elif 1 == 3
STDMATH_EXPORT union stdmath_byte3 {
	struct {
		uint8_t x, y, z;
	};
	struct {
		uint8_t r, g, b;
	};
	struct {
		uint8_t h, s, v;
	};
	uint8_t data[4]; // byte3s are aligned as if they were byte4s
};
#elif 1 == 4
STDMATH_EXPORT union stdmath_byte4 {
	struct {
		uint8_t x, y, z, w;
	};
	struct {
		uint8_t r, g, b, a;
	};
	struct {
		uint8_t h, s, v;
	};
	uint8_t data[4];
};
#endif

STDMATH_EXPORT stdmath_byte1 stdmath_byte1_broadcast(uint8_t all);

STDMATH_EXPORT stdmath_byte1 stdmath_byte1_add(stdmath_byte1 a, stdmath_byte1 b);
STDMATH_EXPORT stdmath_byte1 stdmath_byte1_subtract(stdmath_byte1 a, stdmath_byte1 b);
STDMATH_EXPORT stdmath_byte1 stdmath_byte1_negate(stdmath_byte1 v);
STDMATH_EXPORT stdmath_byte1 stdmath_byte1_multiply(stdmath_byte1 a, stdmath_byte1 b);
STDMATH_EXPORT stdmath_byte1 stdmath_byte1_divide(stdmath_byte1 a, stdmath_byte1 b);
STDMATH_EXPORT stdmath_byte1 stdmath_byte1_scale(stdmath_byte1 v, uint8_t s);

#if false
STDMATH_EXPORT stdmath_byte1 stdmath_byte1_modulus(stdmath_byte1 a, stdmath_byte1 b);
STDMATH_EXPORT stdmath_byte1 stdmath_byte1_logical_not(stdmath_byte1 v);
STDMATH_EXPORT stdmath_byte1 stdmath_byte1_bitwise_not(stdmath_byte1 v);
STDMATH_EXPORT stdmath_byte1 stdmath_byte1_logical_and(stdmath_byte1 a, stdmath_byte1 b);
STDMATH_EXPORT stdmath_byte1 stdmath_byte1_bitwise_and(stdmath_byte1 a, stdmath_byte1 b);
STDMATH_EXPORT stdmath_byte1 stdmath_byte1_logical_or(stdmath_byte1 a, stdmath_byte1 b);
STDMATH_EXPORT stdmath_byte1 stdmath_byte1_bitwise_or(stdmath_byte1 a, stdmath_byte1 b);
STDMATH_EXPORT stdmath_byte1 stdmath_byte1_bitwise_xor(stdmath_byte1 a, stdmath_byte1 b);
STDMATH_EXPORT stdmath_byte1 stdmath_byte1_shift_left(stdmath_byte1 a, stdmath_byte1 b);
STDMATH_EXPORT stdmath_byte1 stdmath_byte1_shift_right(stdmath_byte1 a, stdmath_byte1 b);
#endif

STDMATH_EXPORT stdmath_bool1 stdmath_byte1_equal_to(stdmath_byte1 a, stdmath_byte1 b);
STDMATH_EXPORT stdmath_bool1 stdmath_byte1_not_equal_to(stdmath_byte1 a, stdmath_byte1 b);
STDMATH_EXPORT stdmath_bool1 stdmath_byte1_less_than(stdmath_byte1 a, stdmath_byte1 b);
STDMATH_EXPORT stdmath_bool1 stdmath_byte1_less_than_or_equal_to(stdmath_byte1 a, stdmath_byte1 b);
STDMATH_EXPORT stdmath_bool1 stdmath_byte1_greater_than(stdmath_byte1 a, stdmath_byte1 b);
STDMATH_EXPORT stdmath_bool1 stdmath_byte1_greater_than_or_equal_to(stdmath_byte1 a, stdmath_byte1 b);

STDMATH_EXPORT uint8_t stdmath_byte1_length_squared(stdmath_byte1 v);
STDMATH_EXPORT uint8_t stdmath_byte1_length(stdmath_byte1 v);
STDMATH_EXPORT uint8_t stdmath_byte1_dot(stdmath_byte1 a, stdmath_byte1 b);
STDMATH_EXPORT uint8_t stdmath_byte1_min_element(stdmath_byte1 v);
STDMATH_EXPORT uint8_t stdmath_byte1_max_element(stdmath_byte1 v);

STDMATH_EXPORT stdmath_byte1 stdmath_byte1_elementwise_transform(stdmath_byte1 v, uint8_t(*func)(uint8_t));
// STDMATH_EXPORT uint8_t stdmath_byte1_reduce_elements(stdmath_byte1 v, uint8_t initial_value, uint8_t(*reducer)(stdmath_byte1, stdmath_byte1));

#if 1 == 3
STDMATH_EXPORT stdmath_byte3 stdmath_byte3_cross(stdmath_byte3 a, stdmath_byte3 b);
#endif

STDMATH_EXPORT stdmath_byte1 stdmath_byte1_min(stdmath_byte1 a, stdmath_byte1 b);
STDMATH_EXPORT stdmath_byte1 stdmath_byte1_max(stdmath_byte1 a, stdmath_byte1 b);
STDMATH_EXPORT stdmath_byte1 stdmath_byte1_normalize(stdmath_byte1 v);
STDMATH_EXPORT stdmath_byte1 stdmath_byte1_lerp(stdmath_byte1 a, stdmath_byte1 b, float t);
STDMATH_EXPORT stdmath_byte1 stdmath_byte1_clamp(stdmath_byte1 a, stdmath_byte1 min, stdmath_byte1 max);
STDMATH_EXPORT stdmath_byte1 stdmath_byte1_reflect(stdmath_byte1 a, stdmath_byte1 b);
STDMATH_EXPORT stdmath_bool1 stdmath_byte1_approximately_equal(stdmath_byte1 a, stdmath_byte1 b);

#if false
STDMATH_EXPORT bool stdmath_bool1_all_of(stdmath_bool1 v);
STDMATH_EXPORT bool stdmath_bool1_any_of(stdmath_bool1 v);
STDMATH_EXPORT bool stdmath_bool1_none_of(stdmath_bool1 v);
STDMATH_EXPORT bool stdmath_bool1_some_of(stdmath_bool1 v);
#endif

#ifndef STDMATH_NO_SWIZZLES
STDMATH_EXPORT STDMATH_INLINE stdmath_byte1 stdmath_byte1_x(stdmath_byte1 v) { return {v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte1 stdmath_byte1_x_get(stdmath_byte1* p) { return stdmath_byte1_x(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte1 stdmath_byte1_x_set(stdmath_byte1* p, stdmath_byte1 value) { p->x = value.x; return *p; }

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

inline stdmath::byte1 c(stdmath_byte1 c) {
	return (stdmath::byte1&)c;
}
inline stdmath_byte1 c(stdmath::byte1 c) {
	return (stdmath_byte1&)c;
}

#ifdef __cplusplus
extern "C" {
#endif

stdmath_byte1 stdmath_byte1_broadcast(uint8_t all) {
	return c(stdmath::byte1((stdmath::byte1::underlying_type)all));
}

stdmath_byte1 stdmath_byte1_add(stdmath_byte1 a, stdmath_byte1 b) {
	return c(c(a) + c(b));
}
stdmath_byte1 stdmath_byte1_subtract(stdmath_byte1 a, stdmath_byte1 b) {
	return c(c(a) - c(b));
}
stdmath_byte1 stdmath_byte1_negate(stdmath_byte1 v) {
	return c(stdmath::byte1(-(stdmath::vector<uint8_t, 1>)c(v)));
}
stdmath_byte1 stdmath_byte1_multiply(stdmath_byte1 a, stdmath_byte1 b) {
	return c(c(a) * c(b));
}
stdmath_byte1 stdmath_byte1_divide(stdmath_byte1 a, stdmath_byte1 b) {
	return c(c(a) / c(b));
}
stdmath_byte1 stdmath_byte1_scale(stdmath_byte1 v, uint8_t s) {
	return c(c(v) * (stdmath::byte1::underlying_type)s);
}

#if false
stdmath_byte1 stdmath_byte1_modulus(stdmath_byte1 a, stdmath_byte1 b) {
	return c(c(a) % c(b));
}
stdmath_byte1 stdmath_byte1_logical_not(stdmath_byte1 v) {
	return c(!c(v));
}
stdmath_byte1 stdmath_byte1_bitwise_not(stdmath_byte1 v) {
	return c(~c(v));
}
stdmath_byte1 stdmath_byte1_logical_and(stdmath_byte1 a, stdmath_byte1 b) {
	return c(c(a) && c(b));
}
stdmath_byte1 stdmath_byte1_bitwise_and(stdmath_byte1 a, stdmath_byte1 b) {
	return c(c(a) & c(b));
}
stdmath_byte1 stdmath_byte1_logical_or(stdmath_byte1 a, stdmath_byte1 b) {
	return c(c(a) || c(b));
}
stdmath_byte1 stdmath_byte1_bitwise_or(stdmath_byte1 a, stdmath_byte1 b) {
	return c(c(a) | c(b));
}
stdmath_byte1 stdmath_byte1_bitwise_xor(stdmath_byte1 a, stdmath_byte1 b) {
	return c(c(a) ^ c(b));
}
stdmath_byte1 stdmath_byte1_shift_left(stdmath_byte1 a, stdmath_byte1 b) {
	return c(c(a) << c(b));
}
stdmath_byte1 stdmath_byte1_shift_right(stdmath_byte1 a, stdmath_byte1 b) {
	return c(c(a) >> c(b));
}
#endif

stdmath_bool1 stdmath_byte1_equal_to(stdmath_byte1 a, stdmath_byte1 b) {
	return c(c(a) == c(b));
}
stdmath_bool1 stdmath_byte1_not_equal_to(stdmath_byte1 a, stdmath_byte1 b) {
	return c(c(a) != c(b));
}
stdmath_bool1 stdmath_byte1_less_than(stdmath_byte1 a, stdmath_byte1 b) {
	return c(c(a) < c(b));
}
stdmath_bool1 stdmath_byte1_less_than_or_equal_to(stdmath_byte1 a, stdmath_byte1 b) {
	return c(c(a) <= c(b));
}
stdmath_bool1 stdmath_byte1_greater_than(stdmath_byte1 a, stdmath_byte1 b) {
	return c(c(a) > c(b));
}
stdmath_bool1 stdmath_byte1_greater_than_or_equal_to(stdmath_byte1 a, stdmath_byte1 b) {
	return c(c(a) >= c(b));
}

uint8_t stdmath_byte1_length_squared(stdmath_byte1 v)  {
	return (uint8_t)c(v).length_squared();
}
uint8_t stdmath_byte1_length(stdmath_byte1 v)  {
	return (uint8_t)c(v).length();
}
uint8_t stdmath_byte1_dot(stdmath_byte1 a, stdmath_byte1 b)  {
	return (uint8_t)dot(c(a), c(b));
}
uint8_t stdmath_byte1_min_element(stdmath_byte1 v)  {
	return (uint8_t)c(v).min_element();
}
uint8_t stdmath_byte1_max_element(stdmath_byte1 v)  {
	return (uint8_t)c(v).max_element();
}

stdmath_byte1 stdmath_byte1_elementwise_transform(stdmath_byte1 v, uint8_t(*func)(uint8_t)) {
	return c(c(v).elementwise_transform(func));
}
// uint8_t stdmath_byte1_reduce_elements(stdmath_byte1 v, uint8_t initial_value, uint8_t(*reducer)(stdmath_byte1, stdmath_byte1)) {
// 	return c(v).reduce_elements(initial_value, reducer);
// }

#if 1 == 3
stdmath_byte1 stdmath_byte1_cross(stdmath_byte1 a, stdmath_byte1 b) {
	return c(cross(c(a), c(b)));
}
#endif

stdmath_byte1 stdmath_byte1_min(stdmath_byte1 a, stdmath_byte1 b) {
	return c(min(c(a), c(b)));
}
stdmath_byte1 stdmath_byte1_max(stdmath_byte1 a, stdmath_byte1 b) {
	return c(max(c(a), c(b)));
}
stdmath_byte1 stdmath_byte1_normalize(stdmath_byte1 v) {
	return c(normalize(c(v)));
}
stdmath_byte1 stdmath_byte1_lerp(stdmath_byte1 a, stdmath_byte1 b, float t) {
	return c(lerp(c(a), c(b), t));
}
stdmath_byte1 stdmath_byte1_clamp(stdmath_byte1 a, stdmath_byte1 min, stdmath_byte1 max) {
	return c(clamp(c(a), c(min), c(max)));
}
stdmath_byte1 stdmath_byte1_reflect(stdmath_byte1 a, stdmath_byte1 b) {
	return c(reflect(c(a), c(b)));
}
stdmath_bool1 stdmath_byte1_approximately_equal(stdmath_byte1 a, stdmath_byte1 b) {
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

#endif // __STDMATH_uint8_t1_H__