#ifndef __STDMATH_uint32_t3_H__
#define __STDMATH_uint32_t3_H__

#include <stdint.h>
#if !false
#include "bool3.h"
#endif
#include "uint2.h"
#include "uint1.h"
#include "util.h"

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
	uint32_t data[3]; // uint3s are aligned as if they were uint3s
};

stdmath_uint3 stdmath_uint3_broadcast(uint32_t all);

stdmath_uint3 stdmath_uint3_add(stdmath_uint3 a, stdmath_uint3 b);
stdmath_uint3 stdmath_uint3_subtract(stdmath_uint3 a, stdmath_uint3 b);
stdmath_uint3 stdmath_uint3_negate(stdmath_uint3 v);
stdmath_uint3 stdmath_uint3_multiply(stdmath_uint3 a, stdmath_uint3 b);
stdmath_uint3 stdmath_uint3_divide(stdmath_uint3 a, stdmath_uint3 b);
stdmath_uint3 stdmath_uint3_scale(stdmath_uint3 v, uint32_t s);

#if false
stdmath_uint3 stdmath_uint3_modulus(stdmath_uint3 a, stdmath_uint3 b);
stdmath_uint3 stdmath_uint3_logical_not(stdmath_uint3 v);
stdmath_uint3 stdmath_uint3_bitwise_not(stdmath_uint3 v);
stdmath_uint3 stdmath_uint3_logical_and(stdmath_uint3 a, stdmath_uint3 b);
stdmath_uint3 stdmath_uint3_bitwise_and(stdmath_uint3 a, stdmath_uint3 b);
stdmath_uint3 stdmath_uint3_logical_or(stdmath_uint3 a, stdmath_uint3 b);
stdmath_uint3 stdmath_uint3_bitwise_or(stdmath_uint3 a, stdmath_uint3 b);
stdmath_uint3 stdmath_uint3_bitwise_xor(stdmath_uint3 a, stdmath_uint3 b);
stdmath_uint3 stdmath_uint3_shift_left(stdmath_uint3 a, stdmath_uint3 b);
stdmath_uint3 stdmath_uint3_shift_right(stdmath_uint3 a, stdmath_uint3 b);
#endif

stdmath_bool3 stdmath_uint3_equal_to(stdmath_uint3 a, stdmath_uint3 b);
stdmath_bool3 stdmath_uint3_not_equal_to(stdmath_uint3 a, stdmath_uint3 b);
stdmath_bool3 stdmath_uint3_less_than(stdmath_uint3 a, stdmath_uint3 b);
stdmath_bool3 stdmath_uint3_less_than_or_equal_to(stdmath_uint3 a, stdmath_uint3 b);
stdmath_bool3 stdmath_uint3_greater_than(stdmath_uint3 a, stdmath_uint3 b);
stdmath_bool3 stdmath_uint3_greater_than_or_equal_to(stdmath_uint3 a, stdmath_uint3 b);

uint32_t stdmath_uint3_length_squared(stdmath_uint3 v);
uint32_t stdmath_uint3_length(stdmath_uint3 v);
uint32_t stdmath_uint3_dot(stdmath_uint3 v);
uint32_t stdmath_uint3_min_element(stdmath_uint3 v);
uint32_t stdmath_uint3_max_element(stdmath_uint3 v);

stdmath_uint3 stdmath_uint3_elementwise_transform(stdmath_uint3 v, uint32_t(*func)(uint32_t));
// uint32_t stdmath_uint3_reduce_elements(stdmath_uint3 v, uint32_t initial_value, uint32_t(*reducer)(stdmath_uint3, stdmath_uint3));

stdmath_uint3 stdmath_uint3_cross(stdmath_uint3 a, stdmath_uint3 b);

stdmath_uint3 stdmath_uint3_min(stdmath_uint3 a, stdmath_uint3 b);
stdmath_uint3 stdmath_uint3_max(stdmath_uint3 a, stdmath_uint3 b);
stdmath_uint3 stdmath_uint3_normalize(stdmath_uint3 v);
stdmath_uint3 stdmath_uint3_lerp(stdmath_uint3 a, stdmath_uint3 b, float t);
stdmath_uint3 stdmath_uint3_clamp(stdmath_uint3 a, stdmath_uint3 min, stdmath_uint3 max);
stdmath_uint3 stdmath_uint3_reflect(stdmath_uint3 a, stdmath_uint3 b);
stdmath_bool3 stdmath_uint3_approximately_equal(stdmath_uint3 a, stdmath_uint3 b);

#if false
bool stdmath_bool3_all_of(stdmath_bool3 v);
bool stdmath_bool3_any_of(stdmath_bool3 v);
bool stdmath_bool3_none_of(stdmath_bool3 v);
bool stdmath_bool3_some_of(stdmath_bool3 v);
#endif

inline static stdmath_uint1 stdmath_uint3_x(stdmath_uint3 v) { return {v.x}; }
inline static stdmath_uint3 stdmath_uint3_x_value(stdmath_uint3 v, stdmath_uint1 value) { v.x = value.x; return v; }
inline static stdmath_uint1 stdmath_uint3_y(stdmath_uint3 v) { return {v.y}; }
inline static stdmath_uint3 stdmath_uint3_y_value(stdmath_uint3 v, stdmath_uint1 value) { v.y = value.x; return v; }
inline static stdmath_uint1 stdmath_uint3_z(stdmath_uint3 v) { return {v.z}; }
inline static stdmath_uint3 stdmath_uint3_z_value(stdmath_uint3 v, stdmath_uint1 value) { v.z = value.x; return v; }
inline static stdmath_uint2 stdmath_uint3_xx(stdmath_uint3 v) { return {v.x,v.x}; }
inline static stdmath_uint3 stdmath_uint3_xx_value(stdmath_uint3 v, stdmath_uint2 value) { v.x = value.x; v.x = value.y; return v; }
inline static stdmath_uint2 stdmath_uint3_xy(stdmath_uint3 v) { return {v.x,v.y}; }
inline static stdmath_uint3 stdmath_uint3_xy_value(stdmath_uint3 v, stdmath_uint2 value) { v.x = value.x; v.y = value.y; return v; }
inline static stdmath_uint2 stdmath_uint3_xz(stdmath_uint3 v) { return {v.x,v.z}; }
inline static stdmath_uint3 stdmath_uint3_xz_value(stdmath_uint3 v, stdmath_uint2 value) { v.x = value.x; v.z = value.y; return v; }
inline static stdmath_uint2 stdmath_uint3_yx(stdmath_uint3 v) { return {v.y,v.x}; }
inline static stdmath_uint3 stdmath_uint3_yx_value(stdmath_uint3 v, stdmath_uint2 value) { v.y = value.x; v.x = value.y; return v; }
inline static stdmath_uint2 stdmath_uint3_yy(stdmath_uint3 v) { return {v.y,v.y}; }
inline static stdmath_uint3 stdmath_uint3_yy_value(stdmath_uint3 v, stdmath_uint2 value) { v.y = value.x; v.y = value.y; return v; }
inline static stdmath_uint2 stdmath_uint3_yz(stdmath_uint3 v) { return {v.y,v.z}; }
inline static stdmath_uint3 stdmath_uint3_yz_value(stdmath_uint3 v, stdmath_uint2 value) { v.y = value.x; v.z = value.y; return v; }
inline static stdmath_uint2 stdmath_uint3_zx(stdmath_uint3 v) { return {v.z,v.x}; }
inline static stdmath_uint3 stdmath_uint3_zx_value(stdmath_uint3 v, stdmath_uint2 value) { v.z = value.x; v.x = value.y; return v; }
inline static stdmath_uint2 stdmath_uint3_zy(stdmath_uint3 v) { return {v.z,v.y}; }
inline static stdmath_uint3 stdmath_uint3_zy_value(stdmath_uint3 v, stdmath_uint2 value) { v.z = value.x; v.y = value.y; return v; }
inline static stdmath_uint2 stdmath_uint3_zz(stdmath_uint3 v) { return {v.z,v.z}; }
inline static stdmath_uint3 stdmath_uint3_zz_value(stdmath_uint3 v, stdmath_uint2 value) { v.z = value.x; v.z = value.y; return v; }
inline static stdmath_uint3 stdmath_uint3_xxx(stdmath_uint3 v) { return {v.x,v.x,v.x}; }
inline static stdmath_uint3 stdmath_uint3_xxx_value(stdmath_uint3 v, stdmath_uint3 value) { v.x = value.x; v.x = value.y; v.x = value.z; return v; }
inline static stdmath_uint3 stdmath_uint3_xxy(stdmath_uint3 v) { return {v.x,v.x,v.y}; }
inline static stdmath_uint3 stdmath_uint3_xxy_value(stdmath_uint3 v, stdmath_uint3 value) { v.x = value.x; v.x = value.y; v.y = value.z; return v; }
inline static stdmath_uint3 stdmath_uint3_xxz(stdmath_uint3 v) { return {v.x,v.x,v.z}; }
inline static stdmath_uint3 stdmath_uint3_xxz_value(stdmath_uint3 v, stdmath_uint3 value) { v.x = value.x; v.x = value.y; v.z = value.z; return v; }
inline static stdmath_uint3 stdmath_uint3_xyx(stdmath_uint3 v) { return {v.x,v.y,v.x}; }
inline static stdmath_uint3 stdmath_uint3_xyx_value(stdmath_uint3 v, stdmath_uint3 value) { v.x = value.x; v.y = value.y; v.x = value.z; return v; }
inline static stdmath_uint3 stdmath_uint3_xyy(stdmath_uint3 v) { return {v.x,v.y,v.y}; }
inline static stdmath_uint3 stdmath_uint3_xyy_value(stdmath_uint3 v, stdmath_uint3 value) { v.x = value.x; v.y = value.y; v.y = value.z; return v; }
inline static stdmath_uint3 stdmath_uint3_xyz(stdmath_uint3 v) { return {v.x,v.y,v.z}; }
inline static stdmath_uint3 stdmath_uint3_xyz_value(stdmath_uint3 v, stdmath_uint3 value) { v.x = value.x; v.y = value.y; v.z = value.z; return v; }
inline static stdmath_uint3 stdmath_uint3_xzx(stdmath_uint3 v) { return {v.x,v.z,v.x}; }
inline static stdmath_uint3 stdmath_uint3_xzx_value(stdmath_uint3 v, stdmath_uint3 value) { v.x = value.x; v.z = value.y; v.x = value.z; return v; }
inline static stdmath_uint3 stdmath_uint3_xzy(stdmath_uint3 v) { return {v.x,v.z,v.y}; }
inline static stdmath_uint3 stdmath_uint3_xzy_value(stdmath_uint3 v, stdmath_uint3 value) { v.x = value.x; v.z = value.y; v.y = value.z; return v; }
inline static stdmath_uint3 stdmath_uint3_xzz(stdmath_uint3 v) { return {v.x,v.z,v.z}; }
inline static stdmath_uint3 stdmath_uint3_xzz_value(stdmath_uint3 v, stdmath_uint3 value) { v.x = value.x; v.z = value.y; v.z = value.z; return v; }
inline static stdmath_uint3 stdmath_uint3_yxx(stdmath_uint3 v) { return {v.y,v.x,v.x}; }
inline static stdmath_uint3 stdmath_uint3_yxx_value(stdmath_uint3 v, stdmath_uint3 value) { v.y = value.x; v.x = value.y; v.x = value.z; return v; }
inline static stdmath_uint3 stdmath_uint3_yxy(stdmath_uint3 v) { return {v.y,v.x,v.y}; }
inline static stdmath_uint3 stdmath_uint3_yxy_value(stdmath_uint3 v, stdmath_uint3 value) { v.y = value.x; v.x = value.y; v.y = value.z; return v; }
inline static stdmath_uint3 stdmath_uint3_yxz(stdmath_uint3 v) { return {v.y,v.x,v.z}; }
inline static stdmath_uint3 stdmath_uint3_yxz_value(stdmath_uint3 v, stdmath_uint3 value) { v.y = value.x; v.x = value.y; v.z = value.z; return v; }
inline static stdmath_uint3 stdmath_uint3_yyx(stdmath_uint3 v) { return {v.y,v.y,v.x}; }
inline static stdmath_uint3 stdmath_uint3_yyx_value(stdmath_uint3 v, stdmath_uint3 value) { v.y = value.x; v.y = value.y; v.x = value.z; return v; }
inline static stdmath_uint3 stdmath_uint3_yyy(stdmath_uint3 v) { return {v.y,v.y,v.y}; }
inline static stdmath_uint3 stdmath_uint3_yyy_value(stdmath_uint3 v, stdmath_uint3 value) { v.y = value.x; v.y = value.y; v.y = value.z; return v; }
inline static stdmath_uint3 stdmath_uint3_yyz(stdmath_uint3 v) { return {v.y,v.y,v.z}; }
inline static stdmath_uint3 stdmath_uint3_yyz_value(stdmath_uint3 v, stdmath_uint3 value) { v.y = value.x; v.y = value.y; v.z = value.z; return v; }
inline static stdmath_uint3 stdmath_uint3_yzx(stdmath_uint3 v) { return {v.y,v.z,v.x}; }
inline static stdmath_uint3 stdmath_uint3_yzx_value(stdmath_uint3 v, stdmath_uint3 value) { v.y = value.x; v.z = value.y; v.x = value.z; return v; }
inline static stdmath_uint3 stdmath_uint3_yzy(stdmath_uint3 v) { return {v.y,v.z,v.y}; }
inline static stdmath_uint3 stdmath_uint3_yzy_value(stdmath_uint3 v, stdmath_uint3 value) { v.y = value.x; v.z = value.y; v.y = value.z; return v; }
inline static stdmath_uint3 stdmath_uint3_yzz(stdmath_uint3 v) { return {v.y,v.z,v.z}; }
inline static stdmath_uint3 stdmath_uint3_yzz_value(stdmath_uint3 v, stdmath_uint3 value) { v.y = value.x; v.z = value.y; v.z = value.z; return v; }
inline static stdmath_uint3 stdmath_uint3_zxx(stdmath_uint3 v) { return {v.z,v.x,v.x}; }
inline static stdmath_uint3 stdmath_uint3_zxx_value(stdmath_uint3 v, stdmath_uint3 value) { v.z = value.x; v.x = value.y; v.x = value.z; return v; }
inline static stdmath_uint3 stdmath_uint3_zxy(stdmath_uint3 v) { return {v.z,v.x,v.y}; }
inline static stdmath_uint3 stdmath_uint3_zxy_value(stdmath_uint3 v, stdmath_uint3 value) { v.z = value.x; v.x = value.y; v.y = value.z; return v; }
inline static stdmath_uint3 stdmath_uint3_zxz(stdmath_uint3 v) { return {v.z,v.x,v.z}; }
inline static stdmath_uint3 stdmath_uint3_zxz_value(stdmath_uint3 v, stdmath_uint3 value) { v.z = value.x; v.x = value.y; v.z = value.z; return v; }
inline static stdmath_uint3 stdmath_uint3_zyx(stdmath_uint3 v) { return {v.z,v.y,v.x}; }
inline static stdmath_uint3 stdmath_uint3_zyx_value(stdmath_uint3 v, stdmath_uint3 value) { v.z = value.x; v.y = value.y; v.x = value.z; return v; }
inline static stdmath_uint3 stdmath_uint3_zyy(stdmath_uint3 v) { return {v.z,v.y,v.y}; }
inline static stdmath_uint3 stdmath_uint3_zyy_value(stdmath_uint3 v, stdmath_uint3 value) { v.z = value.x; v.y = value.y; v.y = value.z; return v; }
inline static stdmath_uint3 stdmath_uint3_zyz(stdmath_uint3 v) { return {v.z,v.y,v.z}; }
inline static stdmath_uint3 stdmath_uint3_zyz_value(stdmath_uint3 v, stdmath_uint3 value) { v.z = value.x; v.y = value.y; v.z = value.z; return v; }
inline static stdmath_uint3 stdmath_uint3_zzx(stdmath_uint3 v) { return {v.z,v.z,v.x}; }
inline static stdmath_uint3 stdmath_uint3_zzx_value(stdmath_uint3 v, stdmath_uint3 value) { v.z = value.x; v.z = value.y; v.x = value.z; return v; }
inline static stdmath_uint3 stdmath_uint3_zzy(stdmath_uint3 v) { return {v.z,v.z,v.y}; }
inline static stdmath_uint3 stdmath_uint3_zzy_value(stdmath_uint3 v, stdmath_uint3 value) { v.z = value.x; v.z = value.y; v.y = value.z; return v; }
inline static stdmath_uint3 stdmath_uint3_zzz(stdmath_uint3 v) { return {v.z,v.z,v.z}; }
inline static stdmath_uint3 stdmath_uint3_zzz_value(stdmath_uint3 v, stdmath_uint3 value) { v.z = value.x; v.z = value.y; v.z = value.z; return v; }


#ifdef STDMATH_IMPLEMENTATION
#ifndef __cplusplus
#error "The stdmath implementations require a C++ compiler"
#endif

import stdmath.slang;

stdmath::uint3 c(stdmath_uint3 c) {
	return (stdmath::uint3&)c;
}
stdmath_uint3 c(stdmath::uint3 c) {
	return (stdmath_uint3&)c;
}

stdmath_uint3 stdmath_uint3_broadcast(uint32_t all) {
	return c(stdmath::uint3((stdmath::uint3::underlying_type)all));
}

stdmath_uint3 stdmath_uint3_add(stdmath_uint3 a, stdmath_uint3 b) {
	return c(c(a) + c(b));
}
stdmath_uint3 stdmath_uint3_subtract(stdmath_uint3 a, stdmath_uint3 b) {
	return c(c(a) - c(b));
}
stdmath_uint3 stdmath_uint3_negate(stdmath_uint3 v) {
	return c(stdmath::uint3(-(stdmath::vector<uint32_t, 3>)c(v)));
}
stdmath_uint3 stdmath_uint3_multiply(stdmath_uint3 a, stdmath_uint3 b) {
	return c(c(a) * c(b));
}
stdmath_uint3 stdmath_uint3_divide(stdmath_uint3 a, stdmath_uint3 b) {
	return c(c(a) / c(b));
}
stdmath_uint3 stdmath_uint3_scale(stdmath_uint3 v, uint32_t s) {
	return c(c(v) * (stdmath::uint3::underlying_type)s);
}

#if false
stdmath_uint3 stdmath_uint3_modulus(stdmath_uint3 a, stdmath_uint3 b) {
	return c(c(a) % c(b));
}
stdmath_uint3 stdmath_uint3_logical_not(stdmath_uint3 v) {
	return c(!c(v));
}
stdmath_uint3 stdmath_uint3_bitwise_not(stdmath_uint3 v) {
	return c(~c(v));
}
stdmath_uint3 stdmath_uint3_logical_and(stdmath_uint3 a, stdmath_uint3 b) {
	return c(c(a) && c(b));
}
stdmath_uint3 stdmath_uint3_bitwise_and(stdmath_uint3 a, stdmath_uint3 b) {
	return c(c(a) & c(b));
}
stdmath_uint3 stdmath_uint3_logical_or(stdmath_uint3 a, stdmath_uint3 b) {
	return c(c(a) || c(b));
}
stdmath_uint3 stdmath_uint3_bitwise_or(stdmath_uint3 a, stdmath_uint3 b) {
	return c(c(a) | c(b));
}
stdmath_uint3 stdmath_uint3_bitwise_xor(stdmath_uint3 a, stdmath_uint3 b) {
	return c(c(a) ^ c(b));
}
stdmath_uint3 stdmath_uint3_shift_left(stdmath_uint3 a, stdmath_uint3 b) {
	return c(c(a) << c(b));
}
stdmath_uint3 stdmath_uint3_shift_right(stdmath_uint3 a, stdmath_uint3 b) {
	return c(c(a) >> c(b));
}
#endif

stdmath_bool3 stdmath_uint3_equal_to(stdmath_uint3 a, stdmath_uint3 b) {
	return c(c(a) == c(b));
}
stdmath_bool3 stdmath_uint3_not_equal_to(stdmath_uint3 a, stdmath_uint3 b) {
	return c(c(a) != c(b));
}
stdmath_bool3 stdmath_uint3_less_than(stdmath_uint3 a, stdmath_uint3 b) {
	return c(c(a) < c(b));
}
stdmath_bool3 stdmath_uint3_less_than_or_equal_to(stdmath_uint3 a, stdmath_uint3 b) {
	return c(c(a) <= c(b));
}
stdmath_bool3 stdmath_uint3_greater_than(stdmath_uint3 a, stdmath_uint3 b) {
	return c(c(a) > c(b));
}
stdmath_bool3 stdmath_uint3_greater_than_or_equal_to(stdmath_uint3 a, stdmath_uint3 b) {
	return c(c(a) >= c(b));
}

uint32_t stdmath_uint3_length_squared(stdmath_uint3 v)  {
	return (uint32_t)c(v).length_squared();
}
uint32_t stdmath_uint3_length(stdmath_uint3 v)  {
	return (uint32_t)c(v).length();
}
uint32_t stdmath_uint3_dot(stdmath_uint3 a, stdmath_uint3 b)  {
	return (uint32_t)dot(c(a), c(b));
}
uint32_t stdmath_uint3_min_element(stdmath_uint3 v)  {
	return (uint32_t)c(v).min_element();
}
uint32_t stdmath_uint3_max_element(stdmath_uint3 v)  {
	return (uint32_t)c(v).max_element();
}


stdmath_uint3 stdmath_uint3_elementwise_transform(stdmath_uint3 v, uint32_t(*func)(uint32_t)) {
	return c(c(v).elementwise_transform(func));
}
// uint32_t stdmath_uint3_reduce_elements(stdmath_uint3 v, uint32_t initial_value, uint32_t(*reducer)(stdmath_uint3, stdmath_uint3)) {
// 	return c(v).reduce_elements(initial_value, reducer);
// }

stdmath_uint3 stdmath_uint3_cross(stdmath_uint3 a, stdmath_uint3 b) {
	return c(cross(c(a), c(b)));
}

stdmath_uint3 stdmath_uint3_min(stdmath_uint3 a, stdmath_uint3 b) {
	return c(min(c(a), c(b)));
}
stdmath_uint3 stdmath_uint3_max(stdmath_uint3 a, stdmath_uint3 b) {
	return c(max(c(a), c(b)));
}
stdmath_uint3 stdmath_uint3_normalize(stdmath_uint3 v) {
	return c(normalize(c(v)));
}
stdmath_uint3 stdmath_uint3_lerp(stdmath_uint3 a, stdmath_uint3 b, float t) {
	return c(lerp(c(a), c(b), t));
}
stdmath_uint3 stdmath_uint3_clamp(stdmath_uint3 a, stdmath_uint3 min, stdmath_uint3 max) {
	return c(clamp(c(a), c(min), c(max)));
}
stdmath_uint3 stdmath_uint3_reflect(stdmath_uint3 a, stdmath_uint3 b) {
	return c(reflect(c(a), c(b)));
}
stdmath_bool3 stdmath_uint3_approximately_equal(stdmath_uint3 a, stdmath_uint3 b) {
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

#endif // __STDMATH_uint32_t3_H__
