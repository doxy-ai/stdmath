#ifndef __STDMATH_uint8_t3_H__
#define __STDMATH_uint8_t3_H__

#include <stdint.h>
#if !false
#include "bool3.h"
#endif
#include "byte2.h"
#include "byte1.h"
#include "util.h"

union stdmath_byte3 {
	struct {
		uint8_t x, y, z;
	};
	struct {
		uint8_t r, g, b;
	};
	struct {
		uint8_t h, s, v;
	};
	uint8_t data[3]; // byte3s are aligned as if they were byte3s
};

stdmath_byte3 stdmath_byte3_broadcast(uint8_t all);

stdmath_byte3 stdmath_byte3_add(stdmath_byte3 a, stdmath_byte3 b);
stdmath_byte3 stdmath_byte3_subtract(stdmath_byte3 a, stdmath_byte3 b);
stdmath_byte3 stdmath_byte3_negate(stdmath_byte3 v);
stdmath_byte3 stdmath_byte3_multiply(stdmath_byte3 a, stdmath_byte3 b);
stdmath_byte3 stdmath_byte3_divide(stdmath_byte3 a, stdmath_byte3 b);
stdmath_byte3 stdmath_byte3_scale(stdmath_byte3 v, uint8_t s);

#if false
stdmath_byte3 stdmath_byte3_modulus(stdmath_byte3 a, stdmath_byte3 b);
stdmath_byte3 stdmath_byte3_logical_not(stdmath_byte3 v);
stdmath_byte3 stdmath_byte3_bitwise_not(stdmath_byte3 v);
stdmath_byte3 stdmath_byte3_logical_and(stdmath_byte3 a, stdmath_byte3 b);
stdmath_byte3 stdmath_byte3_bitwise_and(stdmath_byte3 a, stdmath_byte3 b);
stdmath_byte3 stdmath_byte3_logical_or(stdmath_byte3 a, stdmath_byte3 b);
stdmath_byte3 stdmath_byte3_bitwise_or(stdmath_byte3 a, stdmath_byte3 b);
stdmath_byte3 stdmath_byte3_bitwise_xor(stdmath_byte3 a, stdmath_byte3 b);
stdmath_byte3 stdmath_byte3_shift_left(stdmath_byte3 a, stdmath_byte3 b);
stdmath_byte3 stdmath_byte3_shift_right(stdmath_byte3 a, stdmath_byte3 b);
#endif

stdmath_bool3 stdmath_byte3_equal_to(stdmath_byte3 a, stdmath_byte3 b);
stdmath_bool3 stdmath_byte3_not_equal_to(stdmath_byte3 a, stdmath_byte3 b);
stdmath_bool3 stdmath_byte3_less_than(stdmath_byte3 a, stdmath_byte3 b);
stdmath_bool3 stdmath_byte3_less_than_or_equal_to(stdmath_byte3 a, stdmath_byte3 b);
stdmath_bool3 stdmath_byte3_greater_than(stdmath_byte3 a, stdmath_byte3 b);
stdmath_bool3 stdmath_byte3_greater_than_or_equal_to(stdmath_byte3 a, stdmath_byte3 b);

uint8_t stdmath_byte3_length_squared(stdmath_byte3 v);
uint8_t stdmath_byte3_length(stdmath_byte3 v);
uint8_t stdmath_byte3_dot(stdmath_byte3 v);
uint8_t stdmath_byte3_min_element(stdmath_byte3 v);
uint8_t stdmath_byte3_max_element(stdmath_byte3 v);

stdmath_byte3 stdmath_byte3_elementwise_transform(stdmath_byte3 v, uint8_t(*func)(uint8_t));
// uint8_t stdmath_byte3_reduce_elements(stdmath_byte3 v, uint8_t initial_value, uint8_t(*reducer)(stdmath_byte3, stdmath_byte3));

stdmath_byte3 stdmath_byte3_cross(stdmath_byte3 a, stdmath_byte3 b);

stdmath_byte3 stdmath_byte3_min(stdmath_byte3 a, stdmath_byte3 b);
stdmath_byte3 stdmath_byte3_max(stdmath_byte3 a, stdmath_byte3 b);
stdmath_byte3 stdmath_byte3_normalize(stdmath_byte3 v);
stdmath_byte3 stdmath_byte3_lerp(stdmath_byte3 a, stdmath_byte3 b, float t);
stdmath_byte3 stdmath_byte3_clamp(stdmath_byte3 a, stdmath_byte3 min, stdmath_byte3 max);
stdmath_byte3 stdmath_byte3_reflect(stdmath_byte3 a, stdmath_byte3 b);
stdmath_bool3 stdmath_byte3_approximately_equal(stdmath_byte3 a, stdmath_byte3 b);

#if false
bool stdmath_bool3_all_of(stdmath_bool3 v);
bool stdmath_bool3_any_of(stdmath_bool3 v);
bool stdmath_bool3_none_of(stdmath_bool3 v);
bool stdmath_bool3_some_of(stdmath_bool3 v);
#endif

inline static stdmath_byte1 stdmath_byte3_x(stdmath_byte3 v) { return {v.x}; }
inline static stdmath_byte3 stdmath_byte3_x_value(stdmath_byte3 v, stdmath_byte1 value) { v.x = value.x; return v; }
inline static stdmath_byte1 stdmath_byte3_y(stdmath_byte3 v) { return {v.y}; }
inline static stdmath_byte3 stdmath_byte3_y_value(stdmath_byte3 v, stdmath_byte1 value) { v.y = value.x; return v; }
inline static stdmath_byte1 stdmath_byte3_z(stdmath_byte3 v) { return {v.z}; }
inline static stdmath_byte3 stdmath_byte3_z_value(stdmath_byte3 v, stdmath_byte1 value) { v.z = value.x; return v; }
inline static stdmath_byte2 stdmath_byte3_xx(stdmath_byte3 v) { return {v.x,v.x}; }
inline static stdmath_byte3 stdmath_byte3_xx_value(stdmath_byte3 v, stdmath_byte2 value) { v.x = value.x; v.x = value.y; return v; }
inline static stdmath_byte2 stdmath_byte3_xy(stdmath_byte3 v) { return {v.x,v.y}; }
inline static stdmath_byte3 stdmath_byte3_xy_value(stdmath_byte3 v, stdmath_byte2 value) { v.x = value.x; v.y = value.y; return v; }
inline static stdmath_byte2 stdmath_byte3_xz(stdmath_byte3 v) { return {v.x,v.z}; }
inline static stdmath_byte3 stdmath_byte3_xz_value(stdmath_byte3 v, stdmath_byte2 value) { v.x = value.x; v.z = value.y; return v; }
inline static stdmath_byte2 stdmath_byte3_yx(stdmath_byte3 v) { return {v.y,v.x}; }
inline static stdmath_byte3 stdmath_byte3_yx_value(stdmath_byte3 v, stdmath_byte2 value) { v.y = value.x; v.x = value.y; return v; }
inline static stdmath_byte2 stdmath_byte3_yy(stdmath_byte3 v) { return {v.y,v.y}; }
inline static stdmath_byte3 stdmath_byte3_yy_value(stdmath_byte3 v, stdmath_byte2 value) { v.y = value.x; v.y = value.y; return v; }
inline static stdmath_byte2 stdmath_byte3_yz(stdmath_byte3 v) { return {v.y,v.z}; }
inline static stdmath_byte3 stdmath_byte3_yz_value(stdmath_byte3 v, stdmath_byte2 value) { v.y = value.x; v.z = value.y; return v; }
inline static stdmath_byte2 stdmath_byte3_zx(stdmath_byte3 v) { return {v.z,v.x}; }
inline static stdmath_byte3 stdmath_byte3_zx_value(stdmath_byte3 v, stdmath_byte2 value) { v.z = value.x; v.x = value.y; return v; }
inline static stdmath_byte2 stdmath_byte3_zy(stdmath_byte3 v) { return {v.z,v.y}; }
inline static stdmath_byte3 stdmath_byte3_zy_value(stdmath_byte3 v, stdmath_byte2 value) { v.z = value.x; v.y = value.y; return v; }
inline static stdmath_byte2 stdmath_byte3_zz(stdmath_byte3 v) { return {v.z,v.z}; }
inline static stdmath_byte3 stdmath_byte3_zz_value(stdmath_byte3 v, stdmath_byte2 value) { v.z = value.x; v.z = value.y; return v; }
inline static stdmath_byte3 stdmath_byte3_xxx(stdmath_byte3 v) { return {v.x,v.x,v.x}; }
inline static stdmath_byte3 stdmath_byte3_xxx_value(stdmath_byte3 v, stdmath_byte3 value) { v.x = value.x; v.x = value.y; v.x = value.z; return v; }
inline static stdmath_byte3 stdmath_byte3_xxy(stdmath_byte3 v) { return {v.x,v.x,v.y}; }
inline static stdmath_byte3 stdmath_byte3_xxy_value(stdmath_byte3 v, stdmath_byte3 value) { v.x = value.x; v.x = value.y; v.y = value.z; return v; }
inline static stdmath_byte3 stdmath_byte3_xxz(stdmath_byte3 v) { return {v.x,v.x,v.z}; }
inline static stdmath_byte3 stdmath_byte3_xxz_value(stdmath_byte3 v, stdmath_byte3 value) { v.x = value.x; v.x = value.y; v.z = value.z; return v; }
inline static stdmath_byte3 stdmath_byte3_xyx(stdmath_byte3 v) { return {v.x,v.y,v.x}; }
inline static stdmath_byte3 stdmath_byte3_xyx_value(stdmath_byte3 v, stdmath_byte3 value) { v.x = value.x; v.y = value.y; v.x = value.z; return v; }
inline static stdmath_byte3 stdmath_byte3_xyy(stdmath_byte3 v) { return {v.x,v.y,v.y}; }
inline static stdmath_byte3 stdmath_byte3_xyy_value(stdmath_byte3 v, stdmath_byte3 value) { v.x = value.x; v.y = value.y; v.y = value.z; return v; }
inline static stdmath_byte3 stdmath_byte3_xyz(stdmath_byte3 v) { return {v.x,v.y,v.z}; }
inline static stdmath_byte3 stdmath_byte3_xyz_value(stdmath_byte3 v, stdmath_byte3 value) { v.x = value.x; v.y = value.y; v.z = value.z; return v; }
inline static stdmath_byte3 stdmath_byte3_xzx(stdmath_byte3 v) { return {v.x,v.z,v.x}; }
inline static stdmath_byte3 stdmath_byte3_xzx_value(stdmath_byte3 v, stdmath_byte3 value) { v.x = value.x; v.z = value.y; v.x = value.z; return v; }
inline static stdmath_byte3 stdmath_byte3_xzy(stdmath_byte3 v) { return {v.x,v.z,v.y}; }
inline static stdmath_byte3 stdmath_byte3_xzy_value(stdmath_byte3 v, stdmath_byte3 value) { v.x = value.x; v.z = value.y; v.y = value.z; return v; }
inline static stdmath_byte3 stdmath_byte3_xzz(stdmath_byte3 v) { return {v.x,v.z,v.z}; }
inline static stdmath_byte3 stdmath_byte3_xzz_value(stdmath_byte3 v, stdmath_byte3 value) { v.x = value.x; v.z = value.y; v.z = value.z; return v; }
inline static stdmath_byte3 stdmath_byte3_yxx(stdmath_byte3 v) { return {v.y,v.x,v.x}; }
inline static stdmath_byte3 stdmath_byte3_yxx_value(stdmath_byte3 v, stdmath_byte3 value) { v.y = value.x; v.x = value.y; v.x = value.z; return v; }
inline static stdmath_byte3 stdmath_byte3_yxy(stdmath_byte3 v) { return {v.y,v.x,v.y}; }
inline static stdmath_byte3 stdmath_byte3_yxy_value(stdmath_byte3 v, stdmath_byte3 value) { v.y = value.x; v.x = value.y; v.y = value.z; return v; }
inline static stdmath_byte3 stdmath_byte3_yxz(stdmath_byte3 v) { return {v.y,v.x,v.z}; }
inline static stdmath_byte3 stdmath_byte3_yxz_value(stdmath_byte3 v, stdmath_byte3 value) { v.y = value.x; v.x = value.y; v.z = value.z; return v; }
inline static stdmath_byte3 stdmath_byte3_yyx(stdmath_byte3 v) { return {v.y,v.y,v.x}; }
inline static stdmath_byte3 stdmath_byte3_yyx_value(stdmath_byte3 v, stdmath_byte3 value) { v.y = value.x; v.y = value.y; v.x = value.z; return v; }
inline static stdmath_byte3 stdmath_byte3_yyy(stdmath_byte3 v) { return {v.y,v.y,v.y}; }
inline static stdmath_byte3 stdmath_byte3_yyy_value(stdmath_byte3 v, stdmath_byte3 value) { v.y = value.x; v.y = value.y; v.y = value.z; return v; }
inline static stdmath_byte3 stdmath_byte3_yyz(stdmath_byte3 v) { return {v.y,v.y,v.z}; }
inline static stdmath_byte3 stdmath_byte3_yyz_value(stdmath_byte3 v, stdmath_byte3 value) { v.y = value.x; v.y = value.y; v.z = value.z; return v; }
inline static stdmath_byte3 stdmath_byte3_yzx(stdmath_byte3 v) { return {v.y,v.z,v.x}; }
inline static stdmath_byte3 stdmath_byte3_yzx_value(stdmath_byte3 v, stdmath_byte3 value) { v.y = value.x; v.z = value.y; v.x = value.z; return v; }
inline static stdmath_byte3 stdmath_byte3_yzy(stdmath_byte3 v) { return {v.y,v.z,v.y}; }
inline static stdmath_byte3 stdmath_byte3_yzy_value(stdmath_byte3 v, stdmath_byte3 value) { v.y = value.x; v.z = value.y; v.y = value.z; return v; }
inline static stdmath_byte3 stdmath_byte3_yzz(stdmath_byte3 v) { return {v.y,v.z,v.z}; }
inline static stdmath_byte3 stdmath_byte3_yzz_value(stdmath_byte3 v, stdmath_byte3 value) { v.y = value.x; v.z = value.y; v.z = value.z; return v; }
inline static stdmath_byte3 stdmath_byte3_zxx(stdmath_byte3 v) { return {v.z,v.x,v.x}; }
inline static stdmath_byte3 stdmath_byte3_zxx_value(stdmath_byte3 v, stdmath_byte3 value) { v.z = value.x; v.x = value.y; v.x = value.z; return v; }
inline static stdmath_byte3 stdmath_byte3_zxy(stdmath_byte3 v) { return {v.z,v.x,v.y}; }
inline static stdmath_byte3 stdmath_byte3_zxy_value(stdmath_byte3 v, stdmath_byte3 value) { v.z = value.x; v.x = value.y; v.y = value.z; return v; }
inline static stdmath_byte3 stdmath_byte3_zxz(stdmath_byte3 v) { return {v.z,v.x,v.z}; }
inline static stdmath_byte3 stdmath_byte3_zxz_value(stdmath_byte3 v, stdmath_byte3 value) { v.z = value.x; v.x = value.y; v.z = value.z; return v; }
inline static stdmath_byte3 stdmath_byte3_zyx(stdmath_byte3 v) { return {v.z,v.y,v.x}; }
inline static stdmath_byte3 stdmath_byte3_zyx_value(stdmath_byte3 v, stdmath_byte3 value) { v.z = value.x; v.y = value.y; v.x = value.z; return v; }
inline static stdmath_byte3 stdmath_byte3_zyy(stdmath_byte3 v) { return {v.z,v.y,v.y}; }
inline static stdmath_byte3 stdmath_byte3_zyy_value(stdmath_byte3 v, stdmath_byte3 value) { v.z = value.x; v.y = value.y; v.y = value.z; return v; }
inline static stdmath_byte3 stdmath_byte3_zyz(stdmath_byte3 v) { return {v.z,v.y,v.z}; }
inline static stdmath_byte3 stdmath_byte3_zyz_value(stdmath_byte3 v, stdmath_byte3 value) { v.z = value.x; v.y = value.y; v.z = value.z; return v; }
inline static stdmath_byte3 stdmath_byte3_zzx(stdmath_byte3 v) { return {v.z,v.z,v.x}; }
inline static stdmath_byte3 stdmath_byte3_zzx_value(stdmath_byte3 v, stdmath_byte3 value) { v.z = value.x; v.z = value.y; v.x = value.z; return v; }
inline static stdmath_byte3 stdmath_byte3_zzy(stdmath_byte3 v) { return {v.z,v.z,v.y}; }
inline static stdmath_byte3 stdmath_byte3_zzy_value(stdmath_byte3 v, stdmath_byte3 value) { v.z = value.x; v.z = value.y; v.y = value.z; return v; }
inline static stdmath_byte3 stdmath_byte3_zzz(stdmath_byte3 v) { return {v.z,v.z,v.z}; }
inline static stdmath_byte3 stdmath_byte3_zzz_value(stdmath_byte3 v, stdmath_byte3 value) { v.z = value.x; v.z = value.y; v.z = value.z; return v; }


#ifdef STDMATH_IMPLEMENTATION
#ifndef __cplusplus
#error "The stdmath implementations require a C++ compiler"
#endif

import stdmath.slang;

stdmath::byte3 c(stdmath_byte3 c) {
	return (stdmath::byte3&)c;
}
stdmath_byte3 c(stdmath::byte3 c) {
	return (stdmath_byte3&)c;
}

stdmath_byte3 stdmath_byte3_broadcast(uint8_t all) {
	return c(stdmath::byte3((stdmath::byte3::underlying_type)all));
}

stdmath_byte3 stdmath_byte3_add(stdmath_byte3 a, stdmath_byte3 b) {
	return c(c(a) + c(b));
}
stdmath_byte3 stdmath_byte3_subtract(stdmath_byte3 a, stdmath_byte3 b) {
	return c(c(a) - c(b));
}
stdmath_byte3 stdmath_byte3_negate(stdmath_byte3 v) {
	return c(stdmath::byte3(-(stdmath::vector<uint8_t, 3>)c(v)));
}
stdmath_byte3 stdmath_byte3_multiply(stdmath_byte3 a, stdmath_byte3 b) {
	return c(c(a) * c(b));
}
stdmath_byte3 stdmath_byte3_divide(stdmath_byte3 a, stdmath_byte3 b) {
	return c(c(a) / c(b));
}
stdmath_byte3 stdmath_byte3_scale(stdmath_byte3 v, uint8_t s) {
	return c(c(v) * (stdmath::byte3::underlying_type)s);
}

#if false
stdmath_byte3 stdmath_byte3_modulus(stdmath_byte3 a, stdmath_byte3 b) {
	return c(c(a) % c(b));
}
stdmath_byte3 stdmath_byte3_logical_not(stdmath_byte3 v) {
	return c(!c(v));
}
stdmath_byte3 stdmath_byte3_bitwise_not(stdmath_byte3 v) {
	return c(~c(v));
}
stdmath_byte3 stdmath_byte3_logical_and(stdmath_byte3 a, stdmath_byte3 b) {
	return c(c(a) && c(b));
}
stdmath_byte3 stdmath_byte3_bitwise_and(stdmath_byte3 a, stdmath_byte3 b) {
	return c(c(a) & c(b));
}
stdmath_byte3 stdmath_byte3_logical_or(stdmath_byte3 a, stdmath_byte3 b) {
	return c(c(a) || c(b));
}
stdmath_byte3 stdmath_byte3_bitwise_or(stdmath_byte3 a, stdmath_byte3 b) {
	return c(c(a) | c(b));
}
stdmath_byte3 stdmath_byte3_bitwise_xor(stdmath_byte3 a, stdmath_byte3 b) {
	return c(c(a) ^ c(b));
}
stdmath_byte3 stdmath_byte3_shift_left(stdmath_byte3 a, stdmath_byte3 b) {
	return c(c(a) << c(b));
}
stdmath_byte3 stdmath_byte3_shift_right(stdmath_byte3 a, stdmath_byte3 b) {
	return c(c(a) >> c(b));
}
#endif

stdmath_bool3 stdmath_byte3_equal_to(stdmath_byte3 a, stdmath_byte3 b) {
	return c(c(a) == c(b));
}
stdmath_bool3 stdmath_byte3_not_equal_to(stdmath_byte3 a, stdmath_byte3 b) {
	return c(c(a) != c(b));
}
stdmath_bool3 stdmath_byte3_less_than(stdmath_byte3 a, stdmath_byte3 b) {
	return c(c(a) < c(b));
}
stdmath_bool3 stdmath_byte3_less_than_or_equal_to(stdmath_byte3 a, stdmath_byte3 b) {
	return c(c(a) <= c(b));
}
stdmath_bool3 stdmath_byte3_greater_than(stdmath_byte3 a, stdmath_byte3 b) {
	return c(c(a) > c(b));
}
stdmath_bool3 stdmath_byte3_greater_than_or_equal_to(stdmath_byte3 a, stdmath_byte3 b) {
	return c(c(a) >= c(b));
}

uint8_t stdmath_byte3_length_squared(stdmath_byte3 v)  {
	return (uint8_t)c(v).length_squared();
}
uint8_t stdmath_byte3_length(stdmath_byte3 v)  {
	return (uint8_t)c(v).length();
}
uint8_t stdmath_byte3_dot(stdmath_byte3 a, stdmath_byte3 b)  {
	return (uint8_t)dot(c(a), c(b));
}
uint8_t stdmath_byte3_min_element(stdmath_byte3 v)  {
	return (uint8_t)c(v).min_element();
}
uint8_t stdmath_byte3_max_element(stdmath_byte3 v)  {
	return (uint8_t)c(v).max_element();
}


stdmath_byte3 stdmath_byte3_elementwise_transform(stdmath_byte3 v, uint8_t(*func)(uint8_t)) {
	return c(c(v).elementwise_transform(func));
}
// uint8_t stdmath_byte3_reduce_elements(stdmath_byte3 v, uint8_t initial_value, uint8_t(*reducer)(stdmath_byte3, stdmath_byte3)) {
// 	return c(v).reduce_elements(initial_value, reducer);
// }

stdmath_byte3 stdmath_byte3_cross(stdmath_byte3 a, stdmath_byte3 b) {
	return c(cross(c(a), c(b)));
}

stdmath_byte3 stdmath_byte3_min(stdmath_byte3 a, stdmath_byte3 b) {
	return c(min(c(a), c(b)));
}
stdmath_byte3 stdmath_byte3_max(stdmath_byte3 a, stdmath_byte3 b) {
	return c(max(c(a), c(b)));
}
stdmath_byte3 stdmath_byte3_normalize(stdmath_byte3 v) {
	return c(normalize(c(v)));
}
stdmath_byte3 stdmath_byte3_lerp(stdmath_byte3 a, stdmath_byte3 b, float t) {
	return c(lerp(c(a), c(b), t));
}
stdmath_byte3 stdmath_byte3_clamp(stdmath_byte3 a, stdmath_byte3 min, stdmath_byte3 max) {
	return c(clamp(c(a), c(min), c(max)));
}
stdmath_byte3 stdmath_byte3_reflect(stdmath_byte3 a, stdmath_byte3 b) {
	return c(reflect(c(a), c(b)));
}
stdmath_bool3 stdmath_byte3_approximately_equal(stdmath_byte3 a, stdmath_byte3 b) {
	return c(approximately_equal(c(a), c(b)));
}

#if false
bool stdmath_bool3_all_of(stdmath_bool3 v) {
	return all_of(c(v));
}
bool stdmath_bool3_any_of(stdmath_bool3 v) {
	return any_of(c(v));
}
bool stdmath_bool3_none_of(stdmath_bool3 v) {
	return none_of(c(v));
}
bool stdmath_bool3_some_of(stdmath_bool3 v) {
	return some_of(c(v));
}
#endif

#endif // STDMATH_IMPLEMENTATION

#endif // __STDMATH_uint8_t3_H__
