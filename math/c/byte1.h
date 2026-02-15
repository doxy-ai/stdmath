#ifndef __STDMATH_uint8_t1_H__
#define __STDMATH_uint8_t1_H__

#include <stdint.h>
#if !false
#include "bool1.h"
#endif
#include "util.h"

union stdmath_byte1 {
	struct {
		uint8_t x;
	};
	uint8_t data[1];
};

stdmath_byte1 stdmath_byte1_broadcast(uint8_t all);

stdmath_byte1 stdmath_byte1_add(stdmath_byte1 a, stdmath_byte1 b);
stdmath_byte1 stdmath_byte1_subtract(stdmath_byte1 a, stdmath_byte1 b);
stdmath_byte1 stdmath_byte1_negate(stdmath_byte1 v);
stdmath_byte1 stdmath_byte1_multiply(stdmath_byte1 a, stdmath_byte1 b);
stdmath_byte1 stdmath_byte1_divide(stdmath_byte1 a, stdmath_byte1 b);
stdmath_byte1 stdmath_byte1_scale(stdmath_byte1 v, uint8_t s);

#if false
stdmath_byte1 stdmath_byte1_modulus(stdmath_byte1 a, stdmath_byte1 b);
stdmath_byte1 stdmath_byte1_logical_not(stdmath_byte1 v);
stdmath_byte1 stdmath_byte1_bitwise_not(stdmath_byte1 v);
stdmath_byte1 stdmath_byte1_logical_and(stdmath_byte1 a, stdmath_byte1 b);
stdmath_byte1 stdmath_byte1_bitwise_and(stdmath_byte1 a, stdmath_byte1 b);
stdmath_byte1 stdmath_byte1_logical_or(stdmath_byte1 a, stdmath_byte1 b);
stdmath_byte1 stdmath_byte1_bitwise_or(stdmath_byte1 a, stdmath_byte1 b);
stdmath_byte1 stdmath_byte1_bitwise_xor(stdmath_byte1 a, stdmath_byte1 b);
stdmath_byte1 stdmath_byte1_shift_left(stdmath_byte1 a, stdmath_byte1 b);
stdmath_byte1 stdmath_byte1_shift_right(stdmath_byte1 a, stdmath_byte1 b);
#endif

stdmath_bool1 stdmath_byte1_equal_to(stdmath_byte1 a, stdmath_byte1 b);
stdmath_bool1 stdmath_byte1_not_equal_to(stdmath_byte1 a, stdmath_byte1 b);
stdmath_bool1 stdmath_byte1_less_than(stdmath_byte1 a, stdmath_byte1 b);
stdmath_bool1 stdmath_byte1_less_than_or_equal_to(stdmath_byte1 a, stdmath_byte1 b);
stdmath_bool1 stdmath_byte1_greater_than(stdmath_byte1 a, stdmath_byte1 b);
stdmath_bool1 stdmath_byte1_greater_than_or_equal_to(stdmath_byte1 a, stdmath_byte1 b);

uint8_t stdmath_byte1_length_squared(stdmath_byte1 v);
uint8_t stdmath_byte1_length(stdmath_byte1 v);
uint8_t stdmath_byte1_dot(stdmath_byte1 v);
uint8_t stdmath_byte1_min_element(stdmath_byte1 v);
uint8_t stdmath_byte1_max_element(stdmath_byte1 v);

stdmath_byte1 stdmath_byte1_elementwise_transform(stdmath_byte1 v, uint8_t(*func)(uint8_t));
// uint8_t stdmath_byte1_reduce_elements(stdmath_byte1 v, uint8_t initial_value, uint8_t(*reducer)(stdmath_byte1, stdmath_byte1));

stdmath_byte1 stdmath_byte1_min(stdmath_byte1 a, stdmath_byte1 b);
stdmath_byte1 stdmath_byte1_max(stdmath_byte1 a, stdmath_byte1 b);
stdmath_byte1 stdmath_byte1_normalize(stdmath_byte1 v);
stdmath_byte1 stdmath_byte1_lerp(stdmath_byte1 a, stdmath_byte1 b, float t);
stdmath_byte1 stdmath_byte1_clamp(stdmath_byte1 a, stdmath_byte1 min, stdmath_byte1 max);
stdmath_byte1 stdmath_byte1_reflect(stdmath_byte1 a, stdmath_byte1 b);
stdmath_bool1 stdmath_byte1_approximately_equal(stdmath_byte1 a, stdmath_byte1 b);

#if false
bool stdmath_bool1_all_of(stdmath_bool1 v);
bool stdmath_bool1_any_of(stdmath_bool1 v);
bool stdmath_bool1_none_of(stdmath_bool1 v);
bool stdmath_bool1_some_of(stdmath_bool1 v);
#endif

inline static stdmath_byte1 stdmath_byte1_x(stdmath_byte1 v) { return {v.x}; }
inline static stdmath_byte1 stdmath_byte1_x_value(stdmath_byte1 v, stdmath_byte1 value) { v.x = value.x; return v; }


#ifdef STDMATH_IMPLEMENTATION
#ifndef __cplusplus
#error "The stdmath implementations require a C++ compiler"
#endif

import stdmath.slang;

stdmath::byte1 c(stdmath_byte1 c) {
	return (stdmath::byte1&)c;
}
stdmath_byte1 c(stdmath::byte1 c) {
	return (stdmath_byte1&)c;
}

stdmath_byte1 stdmath_byte1_broadcast(uint8_t all) {
	return c(stdmath::byte1((stdmath::byte1::underlying_type&)all));
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
	return c(c(v) * (stdmath::byte1::underlying_type&)s);
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

#endif // STDMATH_IMPLEMENTATION

#endif // __STDMATH_uint8_t1_H__
