#ifndef __STDMATH_int32_t3_H__
#define __STDMATH_int32_t3_H__

#include <stdint.h>
#if !false
#include "bool3.h"
#endif
#include "int2.h"
#include "int1.h"
#include "util.h"

union stdmath_int3 {
	struct {
		int32_t x, y, z;
	};
	struct {
		int32_t r, g, b;
	};
	struct {
		int32_t h, s, v;
	};
	int32_t data[3]; // int3s are aligned as if they were int3s
};

stdmath_int3 stdmath_int3_broadcast(int32_t all);

stdmath_int3 stdmath_int3_add(stdmath_int3 a, stdmath_int3 b);
stdmath_int3 stdmath_int3_subtract(stdmath_int3 a, stdmath_int3 b);
stdmath_int3 stdmath_int3_negate(stdmath_int3 v);
stdmath_int3 stdmath_int3_multiply(stdmath_int3 a, stdmath_int3 b);
stdmath_int3 stdmath_int3_divide(stdmath_int3 a, stdmath_int3 b);
stdmath_int3 stdmath_int3_scale(stdmath_int3 v, int32_t s);

#if false
stdmath_int3 stdmath_int3_modulus(stdmath_int3 a, stdmath_int3 b);
stdmath_int3 stdmath_int3_logical_not(stdmath_int3 v);
stdmath_int3 stdmath_int3_bitwise_not(stdmath_int3 v);
stdmath_int3 stdmath_int3_logical_and(stdmath_int3 a, stdmath_int3 b);
stdmath_int3 stdmath_int3_bitwise_and(stdmath_int3 a, stdmath_int3 b);
stdmath_int3 stdmath_int3_logical_or(stdmath_int3 a, stdmath_int3 b);
stdmath_int3 stdmath_int3_bitwise_or(stdmath_int3 a, stdmath_int3 b);
stdmath_int3 stdmath_int3_bitwise_xor(stdmath_int3 a, stdmath_int3 b);
stdmath_int3 stdmath_int3_shift_left(stdmath_int3 a, stdmath_int3 b);
stdmath_int3 stdmath_int3_shift_right(stdmath_int3 a, stdmath_int3 b);
#endif

stdmath_bool3 stdmath_int3_equal_to(stdmath_int3 a, stdmath_int3 b);
stdmath_bool3 stdmath_int3_not_equal_to(stdmath_int3 a, stdmath_int3 b);
stdmath_bool3 stdmath_int3_less_than(stdmath_int3 a, stdmath_int3 b);
stdmath_bool3 stdmath_int3_less_than_or_equal_to(stdmath_int3 a, stdmath_int3 b);
stdmath_bool3 stdmath_int3_greater_than(stdmath_int3 a, stdmath_int3 b);
stdmath_bool3 stdmath_int3_greater_than_or_equal_to(stdmath_int3 a, stdmath_int3 b);

int32_t stdmath_int3_length_squared(stdmath_int3 v);
int32_t stdmath_int3_length(stdmath_int3 v);
int32_t stdmath_int3_dot(stdmath_int3 v);
int32_t stdmath_int3_min_element(stdmath_int3 v);
int32_t stdmath_int3_max_element(stdmath_int3 v);

stdmath_int3 stdmath_int3_elementwise_transform(stdmath_int3 v, int32_t(*func)(int32_t));
// int32_t stdmath_int3_reduce_elements(stdmath_int3 v, int32_t initial_value, int32_t(*reducer)(stdmath_int3, stdmath_int3));

stdmath_int3 stdmath_int3_cross(stdmath_int3 a, stdmath_int3 b);

stdmath_int3 stdmath_int3_min(stdmath_int3 a, stdmath_int3 b);
stdmath_int3 stdmath_int3_max(stdmath_int3 a, stdmath_int3 b);
stdmath_int3 stdmath_int3_normalize(stdmath_int3 v);
stdmath_int3 stdmath_int3_lerp(stdmath_int3 a, stdmath_int3 b, float t);
stdmath_int3 stdmath_int3_clamp(stdmath_int3 a, stdmath_int3 min, stdmath_int3 max);
stdmath_int3 stdmath_int3_reflect(stdmath_int3 a, stdmath_int3 b);
stdmath_bool3 stdmath_int3_approximately_equal(stdmath_int3 a, stdmath_int3 b);

#if false
bool stdmath_bool3_all_of(stdmath_bool3 v);
bool stdmath_bool3_any_of(stdmath_bool3 v);
bool stdmath_bool3_none_of(stdmath_bool3 v);
bool stdmath_bool3_some_of(stdmath_bool3 v);
#endif

inline static stdmath_int1 stdmath_int3_x(stdmath_int3 v) { return {v.x}; }
inline static stdmath_int3 stdmath_int3_x_value(stdmath_int3 v, stdmath_int1 value) { v.x = value.x; return v; }
inline static stdmath_int1 stdmath_int3_y(stdmath_int3 v) { return {v.y}; }
inline static stdmath_int3 stdmath_int3_y_value(stdmath_int3 v, stdmath_int1 value) { v.y = value.x; return v; }
inline static stdmath_int1 stdmath_int3_z(stdmath_int3 v) { return {v.z}; }
inline static stdmath_int3 stdmath_int3_z_value(stdmath_int3 v, stdmath_int1 value) { v.z = value.x; return v; }
inline static stdmath_int2 stdmath_int3_xx(stdmath_int3 v) { return {v.x,v.x}; }
inline static stdmath_int3 stdmath_int3_xx_value(stdmath_int3 v, stdmath_int2 value) { v.x = value.x; v.x = value.y; return v; }
inline static stdmath_int2 stdmath_int3_xy(stdmath_int3 v) { return {v.x,v.y}; }
inline static stdmath_int3 stdmath_int3_xy_value(stdmath_int3 v, stdmath_int2 value) { v.x = value.x; v.y = value.y; return v; }
inline static stdmath_int2 stdmath_int3_xz(stdmath_int3 v) { return {v.x,v.z}; }
inline static stdmath_int3 stdmath_int3_xz_value(stdmath_int3 v, stdmath_int2 value) { v.x = value.x; v.z = value.y; return v; }
inline static stdmath_int2 stdmath_int3_yx(stdmath_int3 v) { return {v.y,v.x}; }
inline static stdmath_int3 stdmath_int3_yx_value(stdmath_int3 v, stdmath_int2 value) { v.y = value.x; v.x = value.y; return v; }
inline static stdmath_int2 stdmath_int3_yy(stdmath_int3 v) { return {v.y,v.y}; }
inline static stdmath_int3 stdmath_int3_yy_value(stdmath_int3 v, stdmath_int2 value) { v.y = value.x; v.y = value.y; return v; }
inline static stdmath_int2 stdmath_int3_yz(stdmath_int3 v) { return {v.y,v.z}; }
inline static stdmath_int3 stdmath_int3_yz_value(stdmath_int3 v, stdmath_int2 value) { v.y = value.x; v.z = value.y; return v; }
inline static stdmath_int2 stdmath_int3_zx(stdmath_int3 v) { return {v.z,v.x}; }
inline static stdmath_int3 stdmath_int3_zx_value(stdmath_int3 v, stdmath_int2 value) { v.z = value.x; v.x = value.y; return v; }
inline static stdmath_int2 stdmath_int3_zy(stdmath_int3 v) { return {v.z,v.y}; }
inline static stdmath_int3 stdmath_int3_zy_value(stdmath_int3 v, stdmath_int2 value) { v.z = value.x; v.y = value.y; return v; }
inline static stdmath_int2 stdmath_int3_zz(stdmath_int3 v) { return {v.z,v.z}; }
inline static stdmath_int3 stdmath_int3_zz_value(stdmath_int3 v, stdmath_int2 value) { v.z = value.x; v.z = value.y; return v; }
inline static stdmath_int3 stdmath_int3_xxx(stdmath_int3 v) { return {v.x,v.x,v.x}; }
inline static stdmath_int3 stdmath_int3_xxx_value(stdmath_int3 v, stdmath_int3 value) { v.x = value.x; v.x = value.y; v.x = value.z; return v; }
inline static stdmath_int3 stdmath_int3_xxy(stdmath_int3 v) { return {v.x,v.x,v.y}; }
inline static stdmath_int3 stdmath_int3_xxy_value(stdmath_int3 v, stdmath_int3 value) { v.x = value.x; v.x = value.y; v.y = value.z; return v; }
inline static stdmath_int3 stdmath_int3_xxz(stdmath_int3 v) { return {v.x,v.x,v.z}; }
inline static stdmath_int3 stdmath_int3_xxz_value(stdmath_int3 v, stdmath_int3 value) { v.x = value.x; v.x = value.y; v.z = value.z; return v; }
inline static stdmath_int3 stdmath_int3_xyx(stdmath_int3 v) { return {v.x,v.y,v.x}; }
inline static stdmath_int3 stdmath_int3_xyx_value(stdmath_int3 v, stdmath_int3 value) { v.x = value.x; v.y = value.y; v.x = value.z; return v; }
inline static stdmath_int3 stdmath_int3_xyy(stdmath_int3 v) { return {v.x,v.y,v.y}; }
inline static stdmath_int3 stdmath_int3_xyy_value(stdmath_int3 v, stdmath_int3 value) { v.x = value.x; v.y = value.y; v.y = value.z; return v; }
inline static stdmath_int3 stdmath_int3_xyz(stdmath_int3 v) { return {v.x,v.y,v.z}; }
inline static stdmath_int3 stdmath_int3_xyz_value(stdmath_int3 v, stdmath_int3 value) { v.x = value.x; v.y = value.y; v.z = value.z; return v; }
inline static stdmath_int3 stdmath_int3_xzx(stdmath_int3 v) { return {v.x,v.z,v.x}; }
inline static stdmath_int3 stdmath_int3_xzx_value(stdmath_int3 v, stdmath_int3 value) { v.x = value.x; v.z = value.y; v.x = value.z; return v; }
inline static stdmath_int3 stdmath_int3_xzy(stdmath_int3 v) { return {v.x,v.z,v.y}; }
inline static stdmath_int3 stdmath_int3_xzy_value(stdmath_int3 v, stdmath_int3 value) { v.x = value.x; v.z = value.y; v.y = value.z; return v; }
inline static stdmath_int3 stdmath_int3_xzz(stdmath_int3 v) { return {v.x,v.z,v.z}; }
inline static stdmath_int3 stdmath_int3_xzz_value(stdmath_int3 v, stdmath_int3 value) { v.x = value.x; v.z = value.y; v.z = value.z; return v; }
inline static stdmath_int3 stdmath_int3_yxx(stdmath_int3 v) { return {v.y,v.x,v.x}; }
inline static stdmath_int3 stdmath_int3_yxx_value(stdmath_int3 v, stdmath_int3 value) { v.y = value.x; v.x = value.y; v.x = value.z; return v; }
inline static stdmath_int3 stdmath_int3_yxy(stdmath_int3 v) { return {v.y,v.x,v.y}; }
inline static stdmath_int3 stdmath_int3_yxy_value(stdmath_int3 v, stdmath_int3 value) { v.y = value.x; v.x = value.y; v.y = value.z; return v; }
inline static stdmath_int3 stdmath_int3_yxz(stdmath_int3 v) { return {v.y,v.x,v.z}; }
inline static stdmath_int3 stdmath_int3_yxz_value(stdmath_int3 v, stdmath_int3 value) { v.y = value.x; v.x = value.y; v.z = value.z; return v; }
inline static stdmath_int3 stdmath_int3_yyx(stdmath_int3 v) { return {v.y,v.y,v.x}; }
inline static stdmath_int3 stdmath_int3_yyx_value(stdmath_int3 v, stdmath_int3 value) { v.y = value.x; v.y = value.y; v.x = value.z; return v; }
inline static stdmath_int3 stdmath_int3_yyy(stdmath_int3 v) { return {v.y,v.y,v.y}; }
inline static stdmath_int3 stdmath_int3_yyy_value(stdmath_int3 v, stdmath_int3 value) { v.y = value.x; v.y = value.y; v.y = value.z; return v; }
inline static stdmath_int3 stdmath_int3_yyz(stdmath_int3 v) { return {v.y,v.y,v.z}; }
inline static stdmath_int3 stdmath_int3_yyz_value(stdmath_int3 v, stdmath_int3 value) { v.y = value.x; v.y = value.y; v.z = value.z; return v; }
inline static stdmath_int3 stdmath_int3_yzx(stdmath_int3 v) { return {v.y,v.z,v.x}; }
inline static stdmath_int3 stdmath_int3_yzx_value(stdmath_int3 v, stdmath_int3 value) { v.y = value.x; v.z = value.y; v.x = value.z; return v; }
inline static stdmath_int3 stdmath_int3_yzy(stdmath_int3 v) { return {v.y,v.z,v.y}; }
inline static stdmath_int3 stdmath_int3_yzy_value(stdmath_int3 v, stdmath_int3 value) { v.y = value.x; v.z = value.y; v.y = value.z; return v; }
inline static stdmath_int3 stdmath_int3_yzz(stdmath_int3 v) { return {v.y,v.z,v.z}; }
inline static stdmath_int3 stdmath_int3_yzz_value(stdmath_int3 v, stdmath_int3 value) { v.y = value.x; v.z = value.y; v.z = value.z; return v; }
inline static stdmath_int3 stdmath_int3_zxx(stdmath_int3 v) { return {v.z,v.x,v.x}; }
inline static stdmath_int3 stdmath_int3_zxx_value(stdmath_int3 v, stdmath_int3 value) { v.z = value.x; v.x = value.y; v.x = value.z; return v; }
inline static stdmath_int3 stdmath_int3_zxy(stdmath_int3 v) { return {v.z,v.x,v.y}; }
inline static stdmath_int3 stdmath_int3_zxy_value(stdmath_int3 v, stdmath_int3 value) { v.z = value.x; v.x = value.y; v.y = value.z; return v; }
inline static stdmath_int3 stdmath_int3_zxz(stdmath_int3 v) { return {v.z,v.x,v.z}; }
inline static stdmath_int3 stdmath_int3_zxz_value(stdmath_int3 v, stdmath_int3 value) { v.z = value.x; v.x = value.y; v.z = value.z; return v; }
inline static stdmath_int3 stdmath_int3_zyx(stdmath_int3 v) { return {v.z,v.y,v.x}; }
inline static stdmath_int3 stdmath_int3_zyx_value(stdmath_int3 v, stdmath_int3 value) { v.z = value.x; v.y = value.y; v.x = value.z; return v; }
inline static stdmath_int3 stdmath_int3_zyy(stdmath_int3 v) { return {v.z,v.y,v.y}; }
inline static stdmath_int3 stdmath_int3_zyy_value(stdmath_int3 v, stdmath_int3 value) { v.z = value.x; v.y = value.y; v.y = value.z; return v; }
inline static stdmath_int3 stdmath_int3_zyz(stdmath_int3 v) { return {v.z,v.y,v.z}; }
inline static stdmath_int3 stdmath_int3_zyz_value(stdmath_int3 v, stdmath_int3 value) { v.z = value.x; v.y = value.y; v.z = value.z; return v; }
inline static stdmath_int3 stdmath_int3_zzx(stdmath_int3 v) { return {v.z,v.z,v.x}; }
inline static stdmath_int3 stdmath_int3_zzx_value(stdmath_int3 v, stdmath_int3 value) { v.z = value.x; v.z = value.y; v.x = value.z; return v; }
inline static stdmath_int3 stdmath_int3_zzy(stdmath_int3 v) { return {v.z,v.z,v.y}; }
inline static stdmath_int3 stdmath_int3_zzy_value(stdmath_int3 v, stdmath_int3 value) { v.z = value.x; v.z = value.y; v.y = value.z; return v; }
inline static stdmath_int3 stdmath_int3_zzz(stdmath_int3 v) { return {v.z,v.z,v.z}; }
inline static stdmath_int3 stdmath_int3_zzz_value(stdmath_int3 v, stdmath_int3 value) { v.z = value.x; v.z = value.y; v.z = value.z; return v; }


#ifdef STDMATH_IMPLEMENTATION
#ifndef __cplusplus
#error "The stdmath implementations require a C++ compiler"
#endif

import stdmath.slang;

stdmath::int3 c(stdmath_int3 c) {
	return (stdmath::int3&)c;
}
stdmath_int3 c(stdmath::int3 c) {
	return (stdmath_int3&)c;
}

stdmath_int3 stdmath_int3_broadcast(int32_t all) {
	return c(stdmath::int3((stdmath::int3::underlying_type)all));
}

stdmath_int3 stdmath_int3_add(stdmath_int3 a, stdmath_int3 b) {
	return c(c(a) + c(b));
}
stdmath_int3 stdmath_int3_subtract(stdmath_int3 a, stdmath_int3 b) {
	return c(c(a) - c(b));
}
stdmath_int3 stdmath_int3_negate(stdmath_int3 v) {
	return c(stdmath::int3(-(stdmath::vector<int32_t, 3>)c(v)));
}
stdmath_int3 stdmath_int3_multiply(stdmath_int3 a, stdmath_int3 b) {
	return c(c(a) * c(b));
}
stdmath_int3 stdmath_int3_divide(stdmath_int3 a, stdmath_int3 b) {
	return c(c(a) / c(b));
}
stdmath_int3 stdmath_int3_scale(stdmath_int3 v, int32_t s) {
	return c(c(v) * (stdmath::int3::underlying_type)s);
}

#if false
stdmath_int3 stdmath_int3_modulus(stdmath_int3 a, stdmath_int3 b) {
	return c(c(a) % c(b));
}
stdmath_int3 stdmath_int3_logical_not(stdmath_int3 v) {
	return c(!c(v));
}
stdmath_int3 stdmath_int3_bitwise_not(stdmath_int3 v) {
	return c(~c(v));
}
stdmath_int3 stdmath_int3_logical_and(stdmath_int3 a, stdmath_int3 b) {
	return c(c(a) && c(b));
}
stdmath_int3 stdmath_int3_bitwise_and(stdmath_int3 a, stdmath_int3 b) {
	return c(c(a) & c(b));
}
stdmath_int3 stdmath_int3_logical_or(stdmath_int3 a, stdmath_int3 b) {
	return c(c(a) || c(b));
}
stdmath_int3 stdmath_int3_bitwise_or(stdmath_int3 a, stdmath_int3 b) {
	return c(c(a) | c(b));
}
stdmath_int3 stdmath_int3_bitwise_xor(stdmath_int3 a, stdmath_int3 b) {
	return c(c(a) ^ c(b));
}
stdmath_int3 stdmath_int3_shift_left(stdmath_int3 a, stdmath_int3 b) {
	return c(c(a) << c(b));
}
stdmath_int3 stdmath_int3_shift_right(stdmath_int3 a, stdmath_int3 b) {
	return c(c(a) >> c(b));
}
#endif

stdmath_bool3 stdmath_int3_equal_to(stdmath_int3 a, stdmath_int3 b) {
	return c(c(a) == c(b));
}
stdmath_bool3 stdmath_int3_not_equal_to(stdmath_int3 a, stdmath_int3 b) {
	return c(c(a) != c(b));
}
stdmath_bool3 stdmath_int3_less_than(stdmath_int3 a, stdmath_int3 b) {
	return c(c(a) < c(b));
}
stdmath_bool3 stdmath_int3_less_than_or_equal_to(stdmath_int3 a, stdmath_int3 b) {
	return c(c(a) <= c(b));
}
stdmath_bool3 stdmath_int3_greater_than(stdmath_int3 a, stdmath_int3 b) {
	return c(c(a) > c(b));
}
stdmath_bool3 stdmath_int3_greater_than_or_equal_to(stdmath_int3 a, stdmath_int3 b) {
	return c(c(a) >= c(b));
}

int32_t stdmath_int3_length_squared(stdmath_int3 v)  {
	return (int32_t)c(v).length_squared();
}
int32_t stdmath_int3_length(stdmath_int3 v)  {
	return (int32_t)c(v).length();
}
int32_t stdmath_int3_dot(stdmath_int3 a, stdmath_int3 b)  {
	return (int32_t)dot(c(a), c(b));
}
int32_t stdmath_int3_min_element(stdmath_int3 v)  {
	return (int32_t)c(v).min_element();
}
int32_t stdmath_int3_max_element(stdmath_int3 v)  {
	return (int32_t)c(v).max_element();
}


stdmath_int3 stdmath_int3_elementwise_transform(stdmath_int3 v, int32_t(*func)(int32_t)) {
	return c(c(v).elementwise_transform(func));
}
// int32_t stdmath_int3_reduce_elements(stdmath_int3 v, int32_t initial_value, int32_t(*reducer)(stdmath_int3, stdmath_int3)) {
// 	return c(v).reduce_elements(initial_value, reducer);
// }

stdmath_int3 stdmath_int3_cross(stdmath_int3 a, stdmath_int3 b) {
	return c(cross(c(a), c(b)));
}

stdmath_int3 stdmath_int3_min(stdmath_int3 a, stdmath_int3 b) {
	return c(min(c(a), c(b)));
}
stdmath_int3 stdmath_int3_max(stdmath_int3 a, stdmath_int3 b) {
	return c(max(c(a), c(b)));
}
stdmath_int3 stdmath_int3_normalize(stdmath_int3 v) {
	return c(normalize(c(v)));
}
stdmath_int3 stdmath_int3_lerp(stdmath_int3 a, stdmath_int3 b, float t) {
	return c(lerp(c(a), c(b), t));
}
stdmath_int3 stdmath_int3_clamp(stdmath_int3 a, stdmath_int3 min, stdmath_int3 max) {
	return c(clamp(c(a), c(min), c(max)));
}
stdmath_int3 stdmath_int3_reflect(stdmath_int3 a, stdmath_int3 b) {
	return c(reflect(c(a), c(b)));
}
stdmath_bool3 stdmath_int3_approximately_equal(stdmath_int3 a, stdmath_int3 b) {
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

#endif // __STDMATH_int32_t3_H__
