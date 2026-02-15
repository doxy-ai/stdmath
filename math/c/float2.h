#ifndef __STDMATH_float2_H__
#define __STDMATH_float2_H__

#include <stdint.h>
#if !false
#include "bool2.h"
#endif
#include "float1.h"
#include "util.h"

union stdmath_float2 {
	struct {
		float x, y;
	};
	struct {
		float u, v;
	};
	float data[2];
};

stdmath_float2 stdmath_float2_broadcast(float all);

stdmath_float2 stdmath_float2_add(stdmath_float2 a, stdmath_float2 b);
stdmath_float2 stdmath_float2_subtract(stdmath_float2 a, stdmath_float2 b);
stdmath_float2 stdmath_float2_negate(stdmath_float2 v);
stdmath_float2 stdmath_float2_multiply(stdmath_float2 a, stdmath_float2 b);
stdmath_float2 stdmath_float2_divide(stdmath_float2 a, stdmath_float2 b);
stdmath_float2 stdmath_float2_scale(stdmath_float2 v, float s);

#if false
stdmath_float2 stdmath_float2_modulus(stdmath_float2 a, stdmath_float2 b);
stdmath_float2 stdmath_float2_logical_not(stdmath_float2 v);
stdmath_float2 stdmath_float2_bitwise_not(stdmath_float2 v);
stdmath_float2 stdmath_float2_logical_and(stdmath_float2 a, stdmath_float2 b);
stdmath_float2 stdmath_float2_bitwise_and(stdmath_float2 a, stdmath_float2 b);
stdmath_float2 stdmath_float2_logical_or(stdmath_float2 a, stdmath_float2 b);
stdmath_float2 stdmath_float2_bitwise_or(stdmath_float2 a, stdmath_float2 b);
stdmath_float2 stdmath_float2_bitwise_xor(stdmath_float2 a, stdmath_float2 b);
stdmath_float2 stdmath_float2_shift_left(stdmath_float2 a, stdmath_float2 b);
stdmath_float2 stdmath_float2_shift_right(stdmath_float2 a, stdmath_float2 b);
#endif

stdmath_bool2 stdmath_float2_equal_to(stdmath_float2 a, stdmath_float2 b);
stdmath_bool2 stdmath_float2_not_equal_to(stdmath_float2 a, stdmath_float2 b);
stdmath_bool2 stdmath_float2_less_than(stdmath_float2 a, stdmath_float2 b);
stdmath_bool2 stdmath_float2_less_than_or_equal_to(stdmath_float2 a, stdmath_float2 b);
stdmath_bool2 stdmath_float2_greater_than(stdmath_float2 a, stdmath_float2 b);
stdmath_bool2 stdmath_float2_greater_than_or_equal_to(stdmath_float2 a, stdmath_float2 b);

float stdmath_float2_length_squared(stdmath_float2 v);
float stdmath_float2_length(stdmath_float2 v);
float stdmath_float2_dot(stdmath_float2 v);
float stdmath_float2_min_element(stdmath_float2 v);
float stdmath_float2_max_element(stdmath_float2 v);

stdmath_float2 stdmath_float2_elementwise_transform(stdmath_float2 v, float(*func)(float));
// float stdmath_float2_reduce_elements(stdmath_float2 v, float initial_value, float(*reducer)(stdmath_float2, stdmath_float2));

stdmath_float2 stdmath_float2_min(stdmath_float2 a, stdmath_float2 b);
stdmath_float2 stdmath_float2_max(stdmath_float2 a, stdmath_float2 b);
stdmath_float2 stdmath_float2_normalize(stdmath_float2 v);
stdmath_float2 stdmath_float2_lerp(stdmath_float2 a, stdmath_float2 b, float t);
stdmath_float2 stdmath_float2_clamp(stdmath_float2 a, stdmath_float2 min, stdmath_float2 max);
stdmath_float2 stdmath_float2_reflect(stdmath_float2 a, stdmath_float2 b);
stdmath_bool2 stdmath_float2_approximately_equal(stdmath_float2 a, stdmath_float2 b);

#if false
bool stdmath_bool2_all_of(stdmath_bool2 v);
bool stdmath_bool2_any_of(stdmath_bool2 v);
bool stdmath_bool2_none_of(stdmath_bool2 v);
bool stdmath_bool2_some_of(stdmath_bool2 v);
#endif

inline static stdmath_float1 stdmath_float2_x(stdmath_float2 v) { return {v.x}; }
inline static stdmath_float2 stdmath_float2_x_value(stdmath_float2 v, stdmath_float1 value) { v.x = value.x; return v; }
inline static stdmath_float1 stdmath_float2_y(stdmath_float2 v) { return {v.y}; }
inline static stdmath_float2 stdmath_float2_y_value(stdmath_float2 v, stdmath_float1 value) { v.y = value.x; return v; }
inline static stdmath_float2 stdmath_float2_xx(stdmath_float2 v) { return {v.x,v.x}; }
inline static stdmath_float2 stdmath_float2_xx_value(stdmath_float2 v, stdmath_float2 value) { v.x = value.x; v.x = value.y; return v; }
inline static stdmath_float2 stdmath_float2_xy(stdmath_float2 v) { return {v.x,v.y}; }
inline static stdmath_float2 stdmath_float2_xy_value(stdmath_float2 v, stdmath_float2 value) { v.x = value.x; v.y = value.y; return v; }
inline static stdmath_float2 stdmath_float2_yx(stdmath_float2 v) { return {v.y,v.x}; }
inline static stdmath_float2 stdmath_float2_yx_value(stdmath_float2 v, stdmath_float2 value) { v.y = value.x; v.x = value.y; return v; }
inline static stdmath_float2 stdmath_float2_yy(stdmath_float2 v) { return {v.y,v.y}; }
inline static stdmath_float2 stdmath_float2_yy_value(stdmath_float2 v, stdmath_float2 value) { v.y = value.x; v.y = value.y; return v; }


#ifdef STDMATH_IMPLEMENTATION
#ifndef __cplusplus
#error "The stdmath implementations require a C++ compiler"
#endif

import stdmath.slang;

stdmath::float2 c(stdmath_float2 c) {
	return (stdmath::float2&)c;
}
stdmath_float2 c(stdmath::float2 c) {
	return (stdmath_float2&)c;
}

stdmath_float2 stdmath_float2_broadcast(float all) {
	return c(stdmath::float2((stdmath::float2::underlying_type)all));
}

stdmath_float2 stdmath_float2_add(stdmath_float2 a, stdmath_float2 b) {
	return c(c(a) + c(b));
}
stdmath_float2 stdmath_float2_subtract(stdmath_float2 a, stdmath_float2 b) {
	return c(c(a) - c(b));
}
stdmath_float2 stdmath_float2_negate(stdmath_float2 v) {
	return c(stdmath::float2(-(stdmath::vector<float, 2>)c(v)));
}
stdmath_float2 stdmath_float2_multiply(stdmath_float2 a, stdmath_float2 b) {
	return c(c(a) * c(b));
}
stdmath_float2 stdmath_float2_divide(stdmath_float2 a, stdmath_float2 b) {
	return c(c(a) / c(b));
}
stdmath_float2 stdmath_float2_scale(stdmath_float2 v, float s) {
	return c(c(v) * (stdmath::float2::underlying_type)s);
}

#if false
stdmath_float2 stdmath_float2_modulus(stdmath_float2 a, stdmath_float2 b) {
	return c(c(a) % c(b));
}
stdmath_float2 stdmath_float2_logical_not(stdmath_float2 v) {
	return c(!c(v));
}
stdmath_float2 stdmath_float2_bitwise_not(stdmath_float2 v) {
	return c(~c(v));
}
stdmath_float2 stdmath_float2_logical_and(stdmath_float2 a, stdmath_float2 b) {
	return c(c(a) && c(b));
}
stdmath_float2 stdmath_float2_bitwise_and(stdmath_float2 a, stdmath_float2 b) {
	return c(c(a) & c(b));
}
stdmath_float2 stdmath_float2_logical_or(stdmath_float2 a, stdmath_float2 b) {
	return c(c(a) || c(b));
}
stdmath_float2 stdmath_float2_bitwise_or(stdmath_float2 a, stdmath_float2 b) {
	return c(c(a) | c(b));
}
stdmath_float2 stdmath_float2_bitwise_xor(stdmath_float2 a, stdmath_float2 b) {
	return c(c(a) ^ c(b));
}
stdmath_float2 stdmath_float2_shift_left(stdmath_float2 a, stdmath_float2 b) {
	return c(c(a) << c(b));
}
stdmath_float2 stdmath_float2_shift_right(stdmath_float2 a, stdmath_float2 b) {
	return c(c(a) >> c(b));
}
#endif

stdmath_bool2 stdmath_float2_equal_to(stdmath_float2 a, stdmath_float2 b) {
	return c(c(a) == c(b));
}
stdmath_bool2 stdmath_float2_not_equal_to(stdmath_float2 a, stdmath_float2 b) {
	return c(c(a) != c(b));
}
stdmath_bool2 stdmath_float2_less_than(stdmath_float2 a, stdmath_float2 b) {
	return c(c(a) < c(b));
}
stdmath_bool2 stdmath_float2_less_than_or_equal_to(stdmath_float2 a, stdmath_float2 b) {
	return c(c(a) <= c(b));
}
stdmath_bool2 stdmath_float2_greater_than(stdmath_float2 a, stdmath_float2 b) {
	return c(c(a) > c(b));
}
stdmath_bool2 stdmath_float2_greater_than_or_equal_to(stdmath_float2 a, stdmath_float2 b) {
	return c(c(a) >= c(b));
}

float stdmath_float2_length_squared(stdmath_float2 v)  {
	return (float)c(v).length_squared();
}
float stdmath_float2_length(stdmath_float2 v)  {
	return (float)c(v).length();
}
float stdmath_float2_dot(stdmath_float2 a, stdmath_float2 b)  {
	return (float)dot(c(a), c(b));
}
float stdmath_float2_min_element(stdmath_float2 v)  {
	return (float)c(v).min_element();
}
float stdmath_float2_max_element(stdmath_float2 v)  {
	return (float)c(v).max_element();
}

stdmath_float2 stdmath_float2_elementwise_transform(stdmath_float2 v, float(*func)(float)) {
	return c(c(v).elementwise_transform(func));
}
// float stdmath_float2_reduce_elements(stdmath_float2 v, float initial_value, float(*reducer)(stdmath_float2, stdmath_float2)) {
// 	return c(v).reduce_elements(initial_value, reducer);
// }

stdmath_float2 stdmath_float2_min(stdmath_float2 a, stdmath_float2 b) {
	return c(min(c(a), c(b)));
}
stdmath_float2 stdmath_float2_max(stdmath_float2 a, stdmath_float2 b) {
	return c(max(c(a), c(b)));
}
stdmath_float2 stdmath_float2_normalize(stdmath_float2 v) {
	return c(normalize(c(v)));
}
stdmath_float2 stdmath_float2_lerp(stdmath_float2 a, stdmath_float2 b, float t) {
	return c(lerp(c(a), c(b), t));
}
stdmath_float2 stdmath_float2_clamp(stdmath_float2 a, stdmath_float2 min, stdmath_float2 max) {
	return c(clamp(c(a), c(min), c(max)));
}
stdmath_float2 stdmath_float2_reflect(stdmath_float2 a, stdmath_float2 b) {
	return c(reflect(c(a), c(b)));
}
stdmath_bool2 stdmath_float2_approximately_equal(stdmath_float2 a, stdmath_float2 b) {
	return c(approximately_equal(c(a), c(b)));
}

#if false
bool stdmath_bool2_all_of(stdmath_bool2 v) {
	return all_of(c(v));
}
bool stdmath_bool2_any_of(stdmath_bool2 v) {
	return any_of(c(v));
}
bool stdmath_bool2_none_of(stdmath_bool2 v) {
	return none_of(c(v));
}
bool stdmath_bool2_some_of(stdmath_bool2 v) {
	return some_of(c(v));
}
#endif

#endif // STDMATH_IMPLEMENTATION

#endif // __STDMATH_float2_H__
