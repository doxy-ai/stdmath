#ifndef __STDMATH_float3_H__
#define __STDMATH_float3_H__

#include <stdint.h>
#if !false
#if 3 == 1
#include "bool1.h"
#elif 3 == 2
#include "bool2.h"
#elif 3 == 3
#include "bool3.h"
#elif 3 == 4
#include "bool4.h"
#endif
#endif
#if 3 == 2
#include "float1.h"
#elif 3 == 3
#include "float2.h"
#include "float1.h"
#elif 3 == 4
#include "float3.h"
#include "float2.h"
#include "float1.h"
#endif
#include "util.h"

#if 3 == 1
union stdmath_float1 {
	struct {
		float x;
	};
	float data[1];
};
#elif 3 == 2
union stdmath_float2 {
	struct {
		float x, y;
	};
	struct {
		float u, v;
	};
	float data[2];
};
#elif 3 == 3
union stdmath_float3 {
	struct {
		float x, y, z;
	};
	struct {
		float r, g, b;
	};
	struct {
		float h, s, v;
	};
	float data[4]; // float3s are aligned as if they were float4s
};
#elif 3 == 4
union stdmath_float4 {
	struct {
		float x, y, z, w;
	};
	struct {
		float r, g, b, a;
	};
	struct {
		float h, s, v;
	};
	float data[4];
};
#endif

stdmath_float3 stdmath_float3_broadcast(float all);

stdmath_float3 stdmath_float3_add(stdmath_float3 a, stdmath_float3 b);
stdmath_float3 stdmath_float3_subtract(stdmath_float3 a, stdmath_float3 b);
stdmath_float3 stdmath_float3_negate(stdmath_float3 v);
stdmath_float3 stdmath_float3_multiply(stdmath_float3 a, stdmath_float3 b);
stdmath_float3 stdmath_float3_divide(stdmath_float3 a, stdmath_float3 b);
stdmath_float3 stdmath_float3_scale(stdmath_float3 v, float s);

#if false
stdmath_float3 stdmath_float3_modulus(stdmath_float3 a, stdmath_float3 b);
stdmath_float3 stdmath_float3_logical_not(stdmath_float3 v);
stdmath_float3 stdmath_float3_bitwise_not(stdmath_float3 v);
stdmath_float3 stdmath_float3_logical_and(stdmath_float3 a, stdmath_float3 b);
stdmath_float3 stdmath_float3_bitwise_and(stdmath_float3 a, stdmath_float3 b);
stdmath_float3 stdmath_float3_logical_or(stdmath_float3 a, stdmath_float3 b);
stdmath_float3 stdmath_float3_bitwise_or(stdmath_float3 a, stdmath_float3 b);
stdmath_float3 stdmath_float3_bitwise_xor(stdmath_float3 a, stdmath_float3 b);
stdmath_float3 stdmath_float3_shift_left(stdmath_float3 a, stdmath_float3 b);
stdmath_float3 stdmath_float3_shift_right(stdmath_float3 a, stdmath_float3 b);
#endif

stdmath_bool3 stdmath_float3_equal_to(stdmath_float3 a, stdmath_float3 b);
stdmath_bool3 stdmath_float3_not_equal_to(stdmath_float3 a, stdmath_float3 b);
stdmath_bool3 stdmath_float3_less_than(stdmath_float3 a, stdmath_float3 b);
stdmath_bool3 stdmath_float3_less_than_or_equal_to(stdmath_float3 a, stdmath_float3 b);
stdmath_bool3 stdmath_float3_greater_than(stdmath_float3 a, stdmath_float3 b);
stdmath_bool3 stdmath_float3_greater_than_or_equal_to(stdmath_float3 a, stdmath_float3 b);

float stdmath_float3_length_squared(stdmath_float3 v);
float stdmath_float3_length(stdmath_float3 v);
float stdmath_float3_dot(stdmath_float3 v);
float stdmath_float3_min_element(stdmath_float3 v);
float stdmath_float3_max_element(stdmath_float3 v);

stdmath_float3 stdmath_float3_elementwise_transform(stdmath_float3 v, float(*func)(float));
// float stdmath_float3_reduce_elements(stdmath_float3 v, float initial_value, float(*reducer)(stdmath_float3, stdmath_float3));

#if 3 == 3
stdmath_float3 stdmath_float3_cross(stdmath_float3 a, stdmath_float3 b);
#endif

stdmath_float3 stdmath_float3_min(stdmath_float3 a, stdmath_float3 b);
stdmath_float3 stdmath_float3_max(stdmath_float3 a, stdmath_float3 b);
stdmath_float3 stdmath_float3_normalize(stdmath_float3 v);
stdmath_float3 stdmath_float3_lerp(stdmath_float3 a, stdmath_float3 b, float t);
stdmath_float3 stdmath_float3_clamp(stdmath_float3 a, stdmath_float3 min, stdmath_float3 max);
stdmath_float3 stdmath_float3_reflect(stdmath_float3 a, stdmath_float3 b);
stdmath_bool3 stdmath_float3_approximately_equal(stdmath_float3 a, stdmath_float3 b);

#if false
bool stdmath_bool3_all_of(stdmath_bool3 v);
bool stdmath_bool3_any_of(stdmath_bool3 v);
bool stdmath_bool3_none_of(stdmath_bool3 v);
bool stdmath_bool3_some_of(stdmath_bool3 v);
#endif

inline static stdmath_float1 stdmath_float3_x(stdmath_float3 v) { return {v.x}; }
inline static stdmath_float3 stdmath_float3_x_value(stdmath_float3 v, stdmath_float1 value) { v.x = value.x; return v; }
inline static stdmath_float1 stdmath_float3_y(stdmath_float3 v) { return {v.y}; }
inline static stdmath_float3 stdmath_float3_y_value(stdmath_float3 v, stdmath_float1 value) { v.y = value.x; return v; }
inline static stdmath_float1 stdmath_float3_z(stdmath_float3 v) { return {v.z}; }
inline static stdmath_float3 stdmath_float3_z_value(stdmath_float3 v, stdmath_float1 value) { v.z = value.x; return v; }
inline static stdmath_float2 stdmath_float3_xx(stdmath_float3 v) { return {v.x,v.x}; }
inline static stdmath_float3 stdmath_float3_xx_value(stdmath_float3 v, stdmath_float2 value) { v.x = value.x; v.x = value.y; return v; }
inline static stdmath_float2 stdmath_float3_xy(stdmath_float3 v) { return {v.x,v.y}; }
inline static stdmath_float3 stdmath_float3_xy_value(stdmath_float3 v, stdmath_float2 value) { v.x = value.x; v.y = value.y; return v; }
inline static stdmath_float2 stdmath_float3_xz(stdmath_float3 v) { return {v.x,v.z}; }
inline static stdmath_float3 stdmath_float3_xz_value(stdmath_float3 v, stdmath_float2 value) { v.x = value.x; v.z = value.y; return v; }
inline static stdmath_float2 stdmath_float3_yx(stdmath_float3 v) { return {v.y,v.x}; }
inline static stdmath_float3 stdmath_float3_yx_value(stdmath_float3 v, stdmath_float2 value) { v.y = value.x; v.x = value.y; return v; }
inline static stdmath_float2 stdmath_float3_yy(stdmath_float3 v) { return {v.y,v.y}; }
inline static stdmath_float3 stdmath_float3_yy_value(stdmath_float3 v, stdmath_float2 value) { v.y = value.x; v.y = value.y; return v; }
inline static stdmath_float2 stdmath_float3_yz(stdmath_float3 v) { return {v.y,v.z}; }
inline static stdmath_float3 stdmath_float3_yz_value(stdmath_float3 v, stdmath_float2 value) { v.y = value.x; v.z = value.y; return v; }
inline static stdmath_float2 stdmath_float3_zx(stdmath_float3 v) { return {v.z,v.x}; }
inline static stdmath_float3 stdmath_float3_zx_value(stdmath_float3 v, stdmath_float2 value) { v.z = value.x; v.x = value.y; return v; }
inline static stdmath_float2 stdmath_float3_zy(stdmath_float3 v) { return {v.z,v.y}; }
inline static stdmath_float3 stdmath_float3_zy_value(stdmath_float3 v, stdmath_float2 value) { v.z = value.x; v.y = value.y; return v; }
inline static stdmath_float2 stdmath_float3_zz(stdmath_float3 v) { return {v.z,v.z}; }
inline static stdmath_float3 stdmath_float3_zz_value(stdmath_float3 v, stdmath_float2 value) { v.z = value.x; v.z = value.y; return v; }
inline static stdmath_float3 stdmath_float3_xxx(stdmath_float3 v) { return {v.x,v.x,v.x}; }
inline static stdmath_float3 stdmath_float3_xxx_value(stdmath_float3 v, stdmath_float3 value) { v.x = value.x; v.x = value.y; v.x = value.z; return v; }
inline static stdmath_float3 stdmath_float3_xxy(stdmath_float3 v) { return {v.x,v.x,v.y}; }
inline static stdmath_float3 stdmath_float3_xxy_value(stdmath_float3 v, stdmath_float3 value) { v.x = value.x; v.x = value.y; v.y = value.z; return v; }
inline static stdmath_float3 stdmath_float3_xxz(stdmath_float3 v) { return {v.x,v.x,v.z}; }
inline static stdmath_float3 stdmath_float3_xxz_value(stdmath_float3 v, stdmath_float3 value) { v.x = value.x; v.x = value.y; v.z = value.z; return v; }
inline static stdmath_float3 stdmath_float3_xyx(stdmath_float3 v) { return {v.x,v.y,v.x}; }
inline static stdmath_float3 stdmath_float3_xyx_value(stdmath_float3 v, stdmath_float3 value) { v.x = value.x; v.y = value.y; v.x = value.z; return v; }
inline static stdmath_float3 stdmath_float3_xyy(stdmath_float3 v) { return {v.x,v.y,v.y}; }
inline static stdmath_float3 stdmath_float3_xyy_value(stdmath_float3 v, stdmath_float3 value) { v.x = value.x; v.y = value.y; v.y = value.z; return v; }
inline static stdmath_float3 stdmath_float3_xyz(stdmath_float3 v) { return {v.x,v.y,v.z}; }
inline static stdmath_float3 stdmath_float3_xyz_value(stdmath_float3 v, stdmath_float3 value) { v.x = value.x; v.y = value.y; v.z = value.z; return v; }
inline static stdmath_float3 stdmath_float3_xzx(stdmath_float3 v) { return {v.x,v.z,v.x}; }
inline static stdmath_float3 stdmath_float3_xzx_value(stdmath_float3 v, stdmath_float3 value) { v.x = value.x; v.z = value.y; v.x = value.z; return v; }
inline static stdmath_float3 stdmath_float3_xzy(stdmath_float3 v) { return {v.x,v.z,v.y}; }
inline static stdmath_float3 stdmath_float3_xzy_value(stdmath_float3 v, stdmath_float3 value) { v.x = value.x; v.z = value.y; v.y = value.z; return v; }
inline static stdmath_float3 stdmath_float3_xzz(stdmath_float3 v) { return {v.x,v.z,v.z}; }
inline static stdmath_float3 stdmath_float3_xzz_value(stdmath_float3 v, stdmath_float3 value) { v.x = value.x; v.z = value.y; v.z = value.z; return v; }
inline static stdmath_float3 stdmath_float3_yxx(stdmath_float3 v) { return {v.y,v.x,v.x}; }
inline static stdmath_float3 stdmath_float3_yxx_value(stdmath_float3 v, stdmath_float3 value) { v.y = value.x; v.x = value.y; v.x = value.z; return v; }
inline static stdmath_float3 stdmath_float3_yxy(stdmath_float3 v) { return {v.y,v.x,v.y}; }
inline static stdmath_float3 stdmath_float3_yxy_value(stdmath_float3 v, stdmath_float3 value) { v.y = value.x; v.x = value.y; v.y = value.z; return v; }
inline static stdmath_float3 stdmath_float3_yxz(stdmath_float3 v) { return {v.y,v.x,v.z}; }
inline static stdmath_float3 stdmath_float3_yxz_value(stdmath_float3 v, stdmath_float3 value) { v.y = value.x; v.x = value.y; v.z = value.z; return v; }
inline static stdmath_float3 stdmath_float3_yyx(stdmath_float3 v) { return {v.y,v.y,v.x}; }
inline static stdmath_float3 stdmath_float3_yyx_value(stdmath_float3 v, stdmath_float3 value) { v.y = value.x; v.y = value.y; v.x = value.z; return v; }
inline static stdmath_float3 stdmath_float3_yyy(stdmath_float3 v) { return {v.y,v.y,v.y}; }
inline static stdmath_float3 stdmath_float3_yyy_value(stdmath_float3 v, stdmath_float3 value) { v.y = value.x; v.y = value.y; v.y = value.z; return v; }
inline static stdmath_float3 stdmath_float3_yyz(stdmath_float3 v) { return {v.y,v.y,v.z}; }
inline static stdmath_float3 stdmath_float3_yyz_value(stdmath_float3 v, stdmath_float3 value) { v.y = value.x; v.y = value.y; v.z = value.z; return v; }
inline static stdmath_float3 stdmath_float3_yzx(stdmath_float3 v) { return {v.y,v.z,v.x}; }
inline static stdmath_float3 stdmath_float3_yzx_value(stdmath_float3 v, stdmath_float3 value) { v.y = value.x; v.z = value.y; v.x = value.z; return v; }
inline static stdmath_float3 stdmath_float3_yzy(stdmath_float3 v) { return {v.y,v.z,v.y}; }
inline static stdmath_float3 stdmath_float3_yzy_value(stdmath_float3 v, stdmath_float3 value) { v.y = value.x; v.z = value.y; v.y = value.z; return v; }
inline static stdmath_float3 stdmath_float3_yzz(stdmath_float3 v) { return {v.y,v.z,v.z}; }
inline static stdmath_float3 stdmath_float3_yzz_value(stdmath_float3 v, stdmath_float3 value) { v.y = value.x; v.z = value.y; v.z = value.z; return v; }
inline static stdmath_float3 stdmath_float3_zxx(stdmath_float3 v) { return {v.z,v.x,v.x}; }
inline static stdmath_float3 stdmath_float3_zxx_value(stdmath_float3 v, stdmath_float3 value) { v.z = value.x; v.x = value.y; v.x = value.z; return v; }
inline static stdmath_float3 stdmath_float3_zxy(stdmath_float3 v) { return {v.z,v.x,v.y}; }
inline static stdmath_float3 stdmath_float3_zxy_value(stdmath_float3 v, stdmath_float3 value) { v.z = value.x; v.x = value.y; v.y = value.z; return v; }
inline static stdmath_float3 stdmath_float3_zxz(stdmath_float3 v) { return {v.z,v.x,v.z}; }
inline static stdmath_float3 stdmath_float3_zxz_value(stdmath_float3 v, stdmath_float3 value) { v.z = value.x; v.x = value.y; v.z = value.z; return v; }
inline static stdmath_float3 stdmath_float3_zyx(stdmath_float3 v) { return {v.z,v.y,v.x}; }
inline static stdmath_float3 stdmath_float3_zyx_value(stdmath_float3 v, stdmath_float3 value) { v.z = value.x; v.y = value.y; v.x = value.z; return v; }
inline static stdmath_float3 stdmath_float3_zyy(stdmath_float3 v) { return {v.z,v.y,v.y}; }
inline static stdmath_float3 stdmath_float3_zyy_value(stdmath_float3 v, stdmath_float3 value) { v.z = value.x; v.y = value.y; v.y = value.z; return v; }
inline static stdmath_float3 stdmath_float3_zyz(stdmath_float3 v) { return {v.z,v.y,v.z}; }
inline static stdmath_float3 stdmath_float3_zyz_value(stdmath_float3 v, stdmath_float3 value) { v.z = value.x; v.y = value.y; v.z = value.z; return v; }
inline static stdmath_float3 stdmath_float3_zzx(stdmath_float3 v) { return {v.z,v.z,v.x}; }
inline static stdmath_float3 stdmath_float3_zzx_value(stdmath_float3 v, stdmath_float3 value) { v.z = value.x; v.z = value.y; v.x = value.z; return v; }
inline static stdmath_float3 stdmath_float3_zzy(stdmath_float3 v) { return {v.z,v.z,v.y}; }
inline static stdmath_float3 stdmath_float3_zzy_value(stdmath_float3 v, stdmath_float3 value) { v.z = value.x; v.z = value.y; v.y = value.z; return v; }
inline static stdmath_float3 stdmath_float3_zzz(stdmath_float3 v) { return {v.z,v.z,v.z}; }
inline static stdmath_float3 stdmath_float3_zzz_value(stdmath_float3 v, stdmath_float3 value) { v.z = value.x; v.z = value.y; v.z = value.z; return v; }


#ifdef STDMATH_IMPLEMENTATION
#ifndef __cplusplus
#error "The stdmath implementations require a C++ compiler"
#endif

import stdmath.slang;

stdmath::float3 c(stdmath_float3 c) {
	return (stdmath::float3&)c;
}
stdmath_float3 c(stdmath::float3 c) {
	return (stdmath_float3&)c;
}

stdmath_float3 stdmath_float3_broadcast(float all) {
	return c(stdmath::float3((stdmath::float3::underlying_type)all));
}

stdmath_float3 stdmath_float3_add(stdmath_float3 a, stdmath_float3 b) {
	return c(c(a) + c(b));
}
stdmath_float3 stdmath_float3_subtract(stdmath_float3 a, stdmath_float3 b) {
	return c(c(a) - c(b));
}
stdmath_float3 stdmath_float3_negate(stdmath_float3 v) {
	return c(stdmath::float3(-(stdmath::vector<float, 3>)c(v)));
}
stdmath_float3 stdmath_float3_multiply(stdmath_float3 a, stdmath_float3 b) {
	return c(c(a) * c(b));
}
stdmath_float3 stdmath_float3_divide(stdmath_float3 a, stdmath_float3 b) {
	return c(c(a) / c(b));
}
stdmath_float3 stdmath_float3_scale(stdmath_float3 v, float s) {
	return c(c(v) * (stdmath::float3::underlying_type)s);
}

#if false
stdmath_float3 stdmath_float3_modulus(stdmath_float3 a, stdmath_float3 b) {
	return c(c(a) % c(b));
}
stdmath_float3 stdmath_float3_logical_not(stdmath_float3 v) {
	return c(!c(v));
}
stdmath_float3 stdmath_float3_bitwise_not(stdmath_float3 v) {
	return c(~c(v));
}
stdmath_float3 stdmath_float3_logical_and(stdmath_float3 a, stdmath_float3 b) {
	return c(c(a) && c(b));
}
stdmath_float3 stdmath_float3_bitwise_and(stdmath_float3 a, stdmath_float3 b) {
	return c(c(a) & c(b));
}
stdmath_float3 stdmath_float3_logical_or(stdmath_float3 a, stdmath_float3 b) {
	return c(c(a) || c(b));
}
stdmath_float3 stdmath_float3_bitwise_or(stdmath_float3 a, stdmath_float3 b) {
	return c(c(a) | c(b));
}
stdmath_float3 stdmath_float3_bitwise_xor(stdmath_float3 a, stdmath_float3 b) {
	return c(c(a) ^ c(b));
}
stdmath_float3 stdmath_float3_shift_left(stdmath_float3 a, stdmath_float3 b) {
	return c(c(a) << c(b));
}
stdmath_float3 stdmath_float3_shift_right(stdmath_float3 a, stdmath_float3 b) {
	return c(c(a) >> c(b));
}
#endif

stdmath_bool3 stdmath_float3_equal_to(stdmath_float3 a, stdmath_float3 b) {
	return c(c(a) == c(b));
}
stdmath_bool3 stdmath_float3_not_equal_to(stdmath_float3 a, stdmath_float3 b) {
	return c(c(a) != c(b));
}
stdmath_bool3 stdmath_float3_less_than(stdmath_float3 a, stdmath_float3 b) {
	return c(c(a) < c(b));
}
stdmath_bool3 stdmath_float3_less_than_or_equal_to(stdmath_float3 a, stdmath_float3 b) {
	return c(c(a) <= c(b));
}
stdmath_bool3 stdmath_float3_greater_than(stdmath_float3 a, stdmath_float3 b) {
	return c(c(a) > c(b));
}
stdmath_bool3 stdmath_float3_greater_than_or_equal_to(stdmath_float3 a, stdmath_float3 b) {
	return c(c(a) >= c(b));
}

float stdmath_float3_length_squared(stdmath_float3 v)  {
	return (float)c(v).length_squared();
}
float stdmath_float3_length(stdmath_float3 v)  {
	return (float)c(v).length();
}
float stdmath_float3_dot(stdmath_float3 a, stdmath_float3 b)  {
	return (float)dot(c(a), c(b));
}
float stdmath_float3_min_element(stdmath_float3 v)  {
	return (float)c(v).min_element();
}
float stdmath_float3_max_element(stdmath_float3 v)  {
	return (float)c(v).max_element();
}

stdmath_float3 stdmath_float3_elementwise_transform(stdmath_float3 v, float(*func)(float)) {
	return c(c(v).elementwise_transform(func));
}
// float stdmath_float3_reduce_elements(stdmath_float3 v, float initial_value, float(*reducer)(stdmath_float3, stdmath_float3)) {
// 	return c(v).reduce_elements(initial_value, reducer);
// }

#if 3 == 3
stdmath_float3 stdmath_float3_cross(stdmath_float3 a, stdmath_float3 b) {
	return c(cross(c(a), c(b)));
}
#endif

stdmath_float3 stdmath_float3_min(stdmath_float3 a, stdmath_float3 b) {
	return c(min(c(a), c(b)));
}
stdmath_float3 stdmath_float3_max(stdmath_float3 a, stdmath_float3 b) {
	return c(max(c(a), c(b)));
}
stdmath_float3 stdmath_float3_normalize(stdmath_float3 v) {
	return c(normalize(c(v)));
}
stdmath_float3 stdmath_float3_lerp(stdmath_float3 a, stdmath_float3 b, float t) {
	return c(lerp(c(a), c(b), t));
}
stdmath_float3 stdmath_float3_clamp(stdmath_float3 a, stdmath_float3 min, stdmath_float3 max) {
	return c(clamp(c(a), c(min), c(max)));
}
stdmath_float3 stdmath_float3_reflect(stdmath_float3 a, stdmath_float3 b) {
	return c(reflect(c(a), c(b)));
}
stdmath_bool3 stdmath_float3_approximately_equal(stdmath_float3 a, stdmath_float3 b) {
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

#endif // __STDMATH_float3_H__