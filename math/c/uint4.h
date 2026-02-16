#ifndef __STDMATH_uint32_t4_H__
#define __STDMATH_uint32_t4_H__

#include <stdint.h>
#if !false
#if 4 == 1
#include "bool1.h"
#elif 4 == 2
#include "bool2.h"
#elif 4 == 3
#include "bool3.h"
#elif 4 == 4
#include "bool4.h"
#endif
#endif
#if 4 == 2
#include "uint1.h"
#elif 4 == 3
#include "uint2.h"
#include "uint1.h"
#elif 4 == 4
#include "uint3.h"
#include "uint2.h"
#include "uint1.h"
#endif
#include "util.h"

#if 4 == 1
union stdmath_uint1 {
	struct {
		uint32_t x;
	};
	uint32_t data[1];
};
#elif 4 == 2
union stdmath_uint2 {
	struct {
		uint32_t x, y;
	};
	struct {
		uint32_t u, v;
	};
	uint32_t data[2];
};
#elif 4 == 3
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
#elif 4 == 4
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

stdmath_uint4 stdmath_uint4_broadcast(uint32_t all);

stdmath_uint4 stdmath_uint4_add(stdmath_uint4 a, stdmath_uint4 b);
stdmath_uint4 stdmath_uint4_subtract(stdmath_uint4 a, stdmath_uint4 b);
stdmath_uint4 stdmath_uint4_negate(stdmath_uint4 v);
stdmath_uint4 stdmath_uint4_multiply(stdmath_uint4 a, stdmath_uint4 b);
stdmath_uint4 stdmath_uint4_divide(stdmath_uint4 a, stdmath_uint4 b);
stdmath_uint4 stdmath_uint4_scale(stdmath_uint4 v, uint32_t s);

#if false
stdmath_uint4 stdmath_uint4_modulus(stdmath_uint4 a, stdmath_uint4 b);
stdmath_uint4 stdmath_uint4_logical_not(stdmath_uint4 v);
stdmath_uint4 stdmath_uint4_bitwise_not(stdmath_uint4 v);
stdmath_uint4 stdmath_uint4_logical_and(stdmath_uint4 a, stdmath_uint4 b);
stdmath_uint4 stdmath_uint4_bitwise_and(stdmath_uint4 a, stdmath_uint4 b);
stdmath_uint4 stdmath_uint4_logical_or(stdmath_uint4 a, stdmath_uint4 b);
stdmath_uint4 stdmath_uint4_bitwise_or(stdmath_uint4 a, stdmath_uint4 b);
stdmath_uint4 stdmath_uint4_bitwise_xor(stdmath_uint4 a, stdmath_uint4 b);
stdmath_uint4 stdmath_uint4_shift_left(stdmath_uint4 a, stdmath_uint4 b);
stdmath_uint4 stdmath_uint4_shift_right(stdmath_uint4 a, stdmath_uint4 b);
#endif

stdmath_bool4 stdmath_uint4_equal_to(stdmath_uint4 a, stdmath_uint4 b);
stdmath_bool4 stdmath_uint4_not_equal_to(stdmath_uint4 a, stdmath_uint4 b);
stdmath_bool4 stdmath_uint4_less_than(stdmath_uint4 a, stdmath_uint4 b);
stdmath_bool4 stdmath_uint4_less_than_or_equal_to(stdmath_uint4 a, stdmath_uint4 b);
stdmath_bool4 stdmath_uint4_greater_than(stdmath_uint4 a, stdmath_uint4 b);
stdmath_bool4 stdmath_uint4_greater_than_or_equal_to(stdmath_uint4 a, stdmath_uint4 b);

uint32_t stdmath_uint4_length_squared(stdmath_uint4 v);
uint32_t stdmath_uint4_length(stdmath_uint4 v);
uint32_t stdmath_uint4_dot(stdmath_uint4 v);
uint32_t stdmath_uint4_min_element(stdmath_uint4 v);
uint32_t stdmath_uint4_max_element(stdmath_uint4 v);

stdmath_uint4 stdmath_uint4_elementwise_transform(stdmath_uint4 v, uint32_t(*func)(uint32_t));
// uint32_t stdmath_uint4_reduce_elements(stdmath_uint4 v, uint32_t initial_value, uint32_t(*reducer)(stdmath_uint4, stdmath_uint4));

#if 4 == 3
stdmath_uint3 stdmath_uint3_cross(stdmath_uint3 a, stdmath_uint3 b);
#endif

stdmath_uint4 stdmath_uint4_min(stdmath_uint4 a, stdmath_uint4 b);
stdmath_uint4 stdmath_uint4_max(stdmath_uint4 a, stdmath_uint4 b);
stdmath_uint4 stdmath_uint4_normalize(stdmath_uint4 v);
stdmath_uint4 stdmath_uint4_lerp(stdmath_uint4 a, stdmath_uint4 b, float t);
stdmath_uint4 stdmath_uint4_clamp(stdmath_uint4 a, stdmath_uint4 min, stdmath_uint4 max);
stdmath_uint4 stdmath_uint4_reflect(stdmath_uint4 a, stdmath_uint4 b);
stdmath_bool4 stdmath_uint4_approximately_equal(stdmath_uint4 a, stdmath_uint4 b);

#if false
bool stdmath_bool4_all_of(stdmath_bool4 v);
bool stdmath_bool4_any_of(stdmath_bool4 v);
bool stdmath_bool4_none_of(stdmath_bool4 v);
bool stdmath_bool4_some_of(stdmath_bool4 v);
#endif

inline static stdmath_uint1 stdmath_uint4_x(stdmath_uint4 v) { return {v.x}; }
inline static stdmath_uint4 stdmath_uint4_x_value(stdmath_uint4 v, stdmath_uint1 value) { v.x = value.x; return v; }
inline static stdmath_uint1 stdmath_uint4_y(stdmath_uint4 v) { return {v.y}; }
inline static stdmath_uint4 stdmath_uint4_y_value(stdmath_uint4 v, stdmath_uint1 value) { v.y = value.x; return v; }
inline static stdmath_uint1 stdmath_uint4_z(stdmath_uint4 v) { return {v.z}; }
inline static stdmath_uint4 stdmath_uint4_z_value(stdmath_uint4 v, stdmath_uint1 value) { v.z = value.x; return v; }
inline static stdmath_uint1 stdmath_uint4_w(stdmath_uint4 v) { return {v.w}; }
inline static stdmath_uint4 stdmath_uint4_w_value(stdmath_uint4 v, stdmath_uint1 value) { v.w = value.x; return v; }
inline static stdmath_uint2 stdmath_uint4_xx(stdmath_uint4 v) { return {v.x,v.x}; }
inline static stdmath_uint4 stdmath_uint4_xx_value(stdmath_uint4 v, stdmath_uint2 value) { v.x = value.x; v.x = value.y; return v; }
inline static stdmath_uint2 stdmath_uint4_xy(stdmath_uint4 v) { return {v.x,v.y}; }
inline static stdmath_uint4 stdmath_uint4_xy_value(stdmath_uint4 v, stdmath_uint2 value) { v.x = value.x; v.y = value.y; return v; }
inline static stdmath_uint2 stdmath_uint4_xz(stdmath_uint4 v) { return {v.x,v.z}; }
inline static stdmath_uint4 stdmath_uint4_xz_value(stdmath_uint4 v, stdmath_uint2 value) { v.x = value.x; v.z = value.y; return v; }
inline static stdmath_uint2 stdmath_uint4_xw(stdmath_uint4 v) { return {v.x,v.w}; }
inline static stdmath_uint4 stdmath_uint4_xw_value(stdmath_uint4 v, stdmath_uint2 value) { v.x = value.x; v.w = value.y; return v; }
inline static stdmath_uint2 stdmath_uint4_yx(stdmath_uint4 v) { return {v.y,v.x}; }
inline static stdmath_uint4 stdmath_uint4_yx_value(stdmath_uint4 v, stdmath_uint2 value) { v.y = value.x; v.x = value.y; return v; }
inline static stdmath_uint2 stdmath_uint4_yy(stdmath_uint4 v) { return {v.y,v.y}; }
inline static stdmath_uint4 stdmath_uint4_yy_value(stdmath_uint4 v, stdmath_uint2 value) { v.y = value.x; v.y = value.y; return v; }
inline static stdmath_uint2 stdmath_uint4_yz(stdmath_uint4 v) { return {v.y,v.z}; }
inline static stdmath_uint4 stdmath_uint4_yz_value(stdmath_uint4 v, stdmath_uint2 value) { v.y = value.x; v.z = value.y; return v; }
inline static stdmath_uint2 stdmath_uint4_yw(stdmath_uint4 v) { return {v.y,v.w}; }
inline static stdmath_uint4 stdmath_uint4_yw_value(stdmath_uint4 v, stdmath_uint2 value) { v.y = value.x; v.w = value.y; return v; }
inline static stdmath_uint2 stdmath_uint4_zx(stdmath_uint4 v) { return {v.z,v.x}; }
inline static stdmath_uint4 stdmath_uint4_zx_value(stdmath_uint4 v, stdmath_uint2 value) { v.z = value.x; v.x = value.y; return v; }
inline static stdmath_uint2 stdmath_uint4_zy(stdmath_uint4 v) { return {v.z,v.y}; }
inline static stdmath_uint4 stdmath_uint4_zy_value(stdmath_uint4 v, stdmath_uint2 value) { v.z = value.x; v.y = value.y; return v; }
inline static stdmath_uint2 stdmath_uint4_zz(stdmath_uint4 v) { return {v.z,v.z}; }
inline static stdmath_uint4 stdmath_uint4_zz_value(stdmath_uint4 v, stdmath_uint2 value) { v.z = value.x; v.z = value.y; return v; }
inline static stdmath_uint2 stdmath_uint4_zw(stdmath_uint4 v) { return {v.z,v.w}; }
inline static stdmath_uint4 stdmath_uint4_zw_value(stdmath_uint4 v, stdmath_uint2 value) { v.z = value.x; v.w = value.y; return v; }
inline static stdmath_uint2 stdmath_uint4_wx(stdmath_uint4 v) { return {v.w,v.x}; }
inline static stdmath_uint4 stdmath_uint4_wx_value(stdmath_uint4 v, stdmath_uint2 value) { v.w = value.x; v.x = value.y; return v; }
inline static stdmath_uint2 stdmath_uint4_wy(stdmath_uint4 v) { return {v.w,v.y}; }
inline static stdmath_uint4 stdmath_uint4_wy_value(stdmath_uint4 v, stdmath_uint2 value) { v.w = value.x; v.y = value.y; return v; }
inline static stdmath_uint2 stdmath_uint4_wz(stdmath_uint4 v) { return {v.w,v.z}; }
inline static stdmath_uint4 stdmath_uint4_wz_value(stdmath_uint4 v, stdmath_uint2 value) { v.w = value.x; v.z = value.y; return v; }
inline static stdmath_uint2 stdmath_uint4_ww(stdmath_uint4 v) { return {v.w,v.w}; }
inline static stdmath_uint4 stdmath_uint4_ww_value(stdmath_uint4 v, stdmath_uint2 value) { v.w = value.x; v.w = value.y; return v; }
inline static stdmath_uint3 stdmath_uint4_xxx(stdmath_uint4 v) { return {v.x,v.x,v.x}; }
inline static stdmath_uint4 stdmath_uint4_xxx_value(stdmath_uint4 v, stdmath_uint3 value) { v.x = value.x; v.x = value.y; v.x = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_xxy(stdmath_uint4 v) { return {v.x,v.x,v.y}; }
inline static stdmath_uint4 stdmath_uint4_xxy_value(stdmath_uint4 v, stdmath_uint3 value) { v.x = value.x; v.x = value.y; v.y = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_xxz(stdmath_uint4 v) { return {v.x,v.x,v.z}; }
inline static stdmath_uint4 stdmath_uint4_xxz_value(stdmath_uint4 v, stdmath_uint3 value) { v.x = value.x; v.x = value.y; v.z = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_xxw(stdmath_uint4 v) { return {v.x,v.x,v.w}; }
inline static stdmath_uint4 stdmath_uint4_xxw_value(stdmath_uint4 v, stdmath_uint3 value) { v.x = value.x; v.x = value.y; v.w = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_xyx(stdmath_uint4 v) { return {v.x,v.y,v.x}; }
inline static stdmath_uint4 stdmath_uint4_xyx_value(stdmath_uint4 v, stdmath_uint3 value) { v.x = value.x; v.y = value.y; v.x = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_xyy(stdmath_uint4 v) { return {v.x,v.y,v.y}; }
inline static stdmath_uint4 stdmath_uint4_xyy_value(stdmath_uint4 v, stdmath_uint3 value) { v.x = value.x; v.y = value.y; v.y = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_xyz(stdmath_uint4 v) { return {v.x,v.y,v.z}; }
inline static stdmath_uint4 stdmath_uint4_xyz_value(stdmath_uint4 v, stdmath_uint3 value) { v.x = value.x; v.y = value.y; v.z = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_xyw(stdmath_uint4 v) { return {v.x,v.y,v.w}; }
inline static stdmath_uint4 stdmath_uint4_xyw_value(stdmath_uint4 v, stdmath_uint3 value) { v.x = value.x; v.y = value.y; v.w = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_xzx(stdmath_uint4 v) { return {v.x,v.z,v.x}; }
inline static stdmath_uint4 stdmath_uint4_xzx_value(stdmath_uint4 v, stdmath_uint3 value) { v.x = value.x; v.z = value.y; v.x = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_xzy(stdmath_uint4 v) { return {v.x,v.z,v.y}; }
inline static stdmath_uint4 stdmath_uint4_xzy_value(stdmath_uint4 v, stdmath_uint3 value) { v.x = value.x; v.z = value.y; v.y = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_xzz(stdmath_uint4 v) { return {v.x,v.z,v.z}; }
inline static stdmath_uint4 stdmath_uint4_xzz_value(stdmath_uint4 v, stdmath_uint3 value) { v.x = value.x; v.z = value.y; v.z = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_xzw(stdmath_uint4 v) { return {v.x,v.z,v.w}; }
inline static stdmath_uint4 stdmath_uint4_xzw_value(stdmath_uint4 v, stdmath_uint3 value) { v.x = value.x; v.z = value.y; v.w = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_xwx(stdmath_uint4 v) { return {v.x,v.w,v.x}; }
inline static stdmath_uint4 stdmath_uint4_xwx_value(stdmath_uint4 v, stdmath_uint3 value) { v.x = value.x; v.w = value.y; v.x = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_xwy(stdmath_uint4 v) { return {v.x,v.w,v.y}; }
inline static stdmath_uint4 stdmath_uint4_xwy_value(stdmath_uint4 v, stdmath_uint3 value) { v.x = value.x; v.w = value.y; v.y = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_xwz(stdmath_uint4 v) { return {v.x,v.w,v.z}; }
inline static stdmath_uint4 stdmath_uint4_xwz_value(stdmath_uint4 v, stdmath_uint3 value) { v.x = value.x; v.w = value.y; v.z = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_xww(stdmath_uint4 v) { return {v.x,v.w,v.w}; }
inline static stdmath_uint4 stdmath_uint4_xww_value(stdmath_uint4 v, stdmath_uint3 value) { v.x = value.x; v.w = value.y; v.w = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_yxx(stdmath_uint4 v) { return {v.y,v.x,v.x}; }
inline static stdmath_uint4 stdmath_uint4_yxx_value(stdmath_uint4 v, stdmath_uint3 value) { v.y = value.x; v.x = value.y; v.x = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_yxy(stdmath_uint4 v) { return {v.y,v.x,v.y}; }
inline static stdmath_uint4 stdmath_uint4_yxy_value(stdmath_uint4 v, stdmath_uint3 value) { v.y = value.x; v.x = value.y; v.y = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_yxz(stdmath_uint4 v) { return {v.y,v.x,v.z}; }
inline static stdmath_uint4 stdmath_uint4_yxz_value(stdmath_uint4 v, stdmath_uint3 value) { v.y = value.x; v.x = value.y; v.z = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_yxw(stdmath_uint4 v) { return {v.y,v.x,v.w}; }
inline static stdmath_uint4 stdmath_uint4_yxw_value(stdmath_uint4 v, stdmath_uint3 value) { v.y = value.x; v.x = value.y; v.w = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_yyx(stdmath_uint4 v) { return {v.y,v.y,v.x}; }
inline static stdmath_uint4 stdmath_uint4_yyx_value(stdmath_uint4 v, stdmath_uint3 value) { v.y = value.x; v.y = value.y; v.x = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_yyy(stdmath_uint4 v) { return {v.y,v.y,v.y}; }
inline static stdmath_uint4 stdmath_uint4_yyy_value(stdmath_uint4 v, stdmath_uint3 value) { v.y = value.x; v.y = value.y; v.y = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_yyz(stdmath_uint4 v) { return {v.y,v.y,v.z}; }
inline static stdmath_uint4 stdmath_uint4_yyz_value(stdmath_uint4 v, stdmath_uint3 value) { v.y = value.x; v.y = value.y; v.z = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_yyw(stdmath_uint4 v) { return {v.y,v.y,v.w}; }
inline static stdmath_uint4 stdmath_uint4_yyw_value(stdmath_uint4 v, stdmath_uint3 value) { v.y = value.x; v.y = value.y; v.w = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_yzx(stdmath_uint4 v) { return {v.y,v.z,v.x}; }
inline static stdmath_uint4 stdmath_uint4_yzx_value(stdmath_uint4 v, stdmath_uint3 value) { v.y = value.x; v.z = value.y; v.x = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_yzy(stdmath_uint4 v) { return {v.y,v.z,v.y}; }
inline static stdmath_uint4 stdmath_uint4_yzy_value(stdmath_uint4 v, stdmath_uint3 value) { v.y = value.x; v.z = value.y; v.y = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_yzz(stdmath_uint4 v) { return {v.y,v.z,v.z}; }
inline static stdmath_uint4 stdmath_uint4_yzz_value(stdmath_uint4 v, stdmath_uint3 value) { v.y = value.x; v.z = value.y; v.z = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_yzw(stdmath_uint4 v) { return {v.y,v.z,v.w}; }
inline static stdmath_uint4 stdmath_uint4_yzw_value(stdmath_uint4 v, stdmath_uint3 value) { v.y = value.x; v.z = value.y; v.w = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_ywx(stdmath_uint4 v) { return {v.y,v.w,v.x}; }
inline static stdmath_uint4 stdmath_uint4_ywx_value(stdmath_uint4 v, stdmath_uint3 value) { v.y = value.x; v.w = value.y; v.x = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_ywy(stdmath_uint4 v) { return {v.y,v.w,v.y}; }
inline static stdmath_uint4 stdmath_uint4_ywy_value(stdmath_uint4 v, stdmath_uint3 value) { v.y = value.x; v.w = value.y; v.y = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_ywz(stdmath_uint4 v) { return {v.y,v.w,v.z}; }
inline static stdmath_uint4 stdmath_uint4_ywz_value(stdmath_uint4 v, stdmath_uint3 value) { v.y = value.x; v.w = value.y; v.z = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_yww(stdmath_uint4 v) { return {v.y,v.w,v.w}; }
inline static stdmath_uint4 stdmath_uint4_yww_value(stdmath_uint4 v, stdmath_uint3 value) { v.y = value.x; v.w = value.y; v.w = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_zxx(stdmath_uint4 v) { return {v.z,v.x,v.x}; }
inline static stdmath_uint4 stdmath_uint4_zxx_value(stdmath_uint4 v, stdmath_uint3 value) { v.z = value.x; v.x = value.y; v.x = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_zxy(stdmath_uint4 v) { return {v.z,v.x,v.y}; }
inline static stdmath_uint4 stdmath_uint4_zxy_value(stdmath_uint4 v, stdmath_uint3 value) { v.z = value.x; v.x = value.y; v.y = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_zxz(stdmath_uint4 v) { return {v.z,v.x,v.z}; }
inline static stdmath_uint4 stdmath_uint4_zxz_value(stdmath_uint4 v, stdmath_uint3 value) { v.z = value.x; v.x = value.y; v.z = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_zxw(stdmath_uint4 v) { return {v.z,v.x,v.w}; }
inline static stdmath_uint4 stdmath_uint4_zxw_value(stdmath_uint4 v, stdmath_uint3 value) { v.z = value.x; v.x = value.y; v.w = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_zyx(stdmath_uint4 v) { return {v.z,v.y,v.x}; }
inline static stdmath_uint4 stdmath_uint4_zyx_value(stdmath_uint4 v, stdmath_uint3 value) { v.z = value.x; v.y = value.y; v.x = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_zyy(stdmath_uint4 v) { return {v.z,v.y,v.y}; }
inline static stdmath_uint4 stdmath_uint4_zyy_value(stdmath_uint4 v, stdmath_uint3 value) { v.z = value.x; v.y = value.y; v.y = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_zyz(stdmath_uint4 v) { return {v.z,v.y,v.z}; }
inline static stdmath_uint4 stdmath_uint4_zyz_value(stdmath_uint4 v, stdmath_uint3 value) { v.z = value.x; v.y = value.y; v.z = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_zyw(stdmath_uint4 v) { return {v.z,v.y,v.w}; }
inline static stdmath_uint4 stdmath_uint4_zyw_value(stdmath_uint4 v, stdmath_uint3 value) { v.z = value.x; v.y = value.y; v.w = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_zzx(stdmath_uint4 v) { return {v.z,v.z,v.x}; }
inline static stdmath_uint4 stdmath_uint4_zzx_value(stdmath_uint4 v, stdmath_uint3 value) { v.z = value.x; v.z = value.y; v.x = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_zzy(stdmath_uint4 v) { return {v.z,v.z,v.y}; }
inline static stdmath_uint4 stdmath_uint4_zzy_value(stdmath_uint4 v, stdmath_uint3 value) { v.z = value.x; v.z = value.y; v.y = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_zzz(stdmath_uint4 v) { return {v.z,v.z,v.z}; }
inline static stdmath_uint4 stdmath_uint4_zzz_value(stdmath_uint4 v, stdmath_uint3 value) { v.z = value.x; v.z = value.y; v.z = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_zzw(stdmath_uint4 v) { return {v.z,v.z,v.w}; }
inline static stdmath_uint4 stdmath_uint4_zzw_value(stdmath_uint4 v, stdmath_uint3 value) { v.z = value.x; v.z = value.y; v.w = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_zwx(stdmath_uint4 v) { return {v.z,v.w,v.x}; }
inline static stdmath_uint4 stdmath_uint4_zwx_value(stdmath_uint4 v, stdmath_uint3 value) { v.z = value.x; v.w = value.y; v.x = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_zwy(stdmath_uint4 v) { return {v.z,v.w,v.y}; }
inline static stdmath_uint4 stdmath_uint4_zwy_value(stdmath_uint4 v, stdmath_uint3 value) { v.z = value.x; v.w = value.y; v.y = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_zwz(stdmath_uint4 v) { return {v.z,v.w,v.z}; }
inline static stdmath_uint4 stdmath_uint4_zwz_value(stdmath_uint4 v, stdmath_uint3 value) { v.z = value.x; v.w = value.y; v.z = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_zww(stdmath_uint4 v) { return {v.z,v.w,v.w}; }
inline static stdmath_uint4 stdmath_uint4_zww_value(stdmath_uint4 v, stdmath_uint3 value) { v.z = value.x; v.w = value.y; v.w = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_wxx(stdmath_uint4 v) { return {v.w,v.x,v.x}; }
inline static stdmath_uint4 stdmath_uint4_wxx_value(stdmath_uint4 v, stdmath_uint3 value) { v.w = value.x; v.x = value.y; v.x = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_wxy(stdmath_uint4 v) { return {v.w,v.x,v.y}; }
inline static stdmath_uint4 stdmath_uint4_wxy_value(stdmath_uint4 v, stdmath_uint3 value) { v.w = value.x; v.x = value.y; v.y = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_wxz(stdmath_uint4 v) { return {v.w,v.x,v.z}; }
inline static stdmath_uint4 stdmath_uint4_wxz_value(stdmath_uint4 v, stdmath_uint3 value) { v.w = value.x; v.x = value.y; v.z = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_wxw(stdmath_uint4 v) { return {v.w,v.x,v.w}; }
inline static stdmath_uint4 stdmath_uint4_wxw_value(stdmath_uint4 v, stdmath_uint3 value) { v.w = value.x; v.x = value.y; v.w = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_wyx(stdmath_uint4 v) { return {v.w,v.y,v.x}; }
inline static stdmath_uint4 stdmath_uint4_wyx_value(stdmath_uint4 v, stdmath_uint3 value) { v.w = value.x; v.y = value.y; v.x = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_wyy(stdmath_uint4 v) { return {v.w,v.y,v.y}; }
inline static stdmath_uint4 stdmath_uint4_wyy_value(stdmath_uint4 v, stdmath_uint3 value) { v.w = value.x; v.y = value.y; v.y = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_wyz(stdmath_uint4 v) { return {v.w,v.y,v.z}; }
inline static stdmath_uint4 stdmath_uint4_wyz_value(stdmath_uint4 v, stdmath_uint3 value) { v.w = value.x; v.y = value.y; v.z = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_wyw(stdmath_uint4 v) { return {v.w,v.y,v.w}; }
inline static stdmath_uint4 stdmath_uint4_wyw_value(stdmath_uint4 v, stdmath_uint3 value) { v.w = value.x; v.y = value.y; v.w = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_wzx(stdmath_uint4 v) { return {v.w,v.z,v.x}; }
inline static stdmath_uint4 stdmath_uint4_wzx_value(stdmath_uint4 v, stdmath_uint3 value) { v.w = value.x; v.z = value.y; v.x = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_wzy(stdmath_uint4 v) { return {v.w,v.z,v.y}; }
inline static stdmath_uint4 stdmath_uint4_wzy_value(stdmath_uint4 v, stdmath_uint3 value) { v.w = value.x; v.z = value.y; v.y = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_wzz(stdmath_uint4 v) { return {v.w,v.z,v.z}; }
inline static stdmath_uint4 stdmath_uint4_wzz_value(stdmath_uint4 v, stdmath_uint3 value) { v.w = value.x; v.z = value.y; v.z = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_wzw(stdmath_uint4 v) { return {v.w,v.z,v.w}; }
inline static stdmath_uint4 stdmath_uint4_wzw_value(stdmath_uint4 v, stdmath_uint3 value) { v.w = value.x; v.z = value.y; v.w = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_wwx(stdmath_uint4 v) { return {v.w,v.w,v.x}; }
inline static stdmath_uint4 stdmath_uint4_wwx_value(stdmath_uint4 v, stdmath_uint3 value) { v.w = value.x; v.w = value.y; v.x = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_wwy(stdmath_uint4 v) { return {v.w,v.w,v.y}; }
inline static stdmath_uint4 stdmath_uint4_wwy_value(stdmath_uint4 v, stdmath_uint3 value) { v.w = value.x; v.w = value.y; v.y = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_wwz(stdmath_uint4 v) { return {v.w,v.w,v.z}; }
inline static stdmath_uint4 stdmath_uint4_wwz_value(stdmath_uint4 v, stdmath_uint3 value) { v.w = value.x; v.w = value.y; v.z = value.z; return v; }
inline static stdmath_uint3 stdmath_uint4_www(stdmath_uint4 v) { return {v.w,v.w,v.w}; }
inline static stdmath_uint4 stdmath_uint4_www_value(stdmath_uint4 v, stdmath_uint3 value) { v.w = value.x; v.w = value.y; v.w = value.z; return v; }
inline static stdmath_uint4 stdmath_uint4_xxxx(stdmath_uint4 v) { return {v.x,v.x,v.x,v.x}; }
inline static stdmath_uint4 stdmath_uint4_xxxx_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.x = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xxxy(stdmath_uint4 v) { return {v.x,v.x,v.x,v.y}; }
inline static stdmath_uint4 stdmath_uint4_xxxy_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.x = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xxxz(stdmath_uint4 v) { return {v.x,v.x,v.x,v.z}; }
inline static stdmath_uint4 stdmath_uint4_xxxz_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.x = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xxxw(stdmath_uint4 v) { return {v.x,v.x,v.x,v.w}; }
inline static stdmath_uint4 stdmath_uint4_xxxw_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.x = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xxyx(stdmath_uint4 v) { return {v.x,v.x,v.y,v.x}; }
inline static stdmath_uint4 stdmath_uint4_xxyx_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.x = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xxyy(stdmath_uint4 v) { return {v.x,v.x,v.y,v.y}; }
inline static stdmath_uint4 stdmath_uint4_xxyy_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.x = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xxyz(stdmath_uint4 v) { return {v.x,v.x,v.y,v.z}; }
inline static stdmath_uint4 stdmath_uint4_xxyz_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.x = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xxyw(stdmath_uint4 v) { return {v.x,v.x,v.y,v.w}; }
inline static stdmath_uint4 stdmath_uint4_xxyw_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.x = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xxzx(stdmath_uint4 v) { return {v.x,v.x,v.z,v.x}; }
inline static stdmath_uint4 stdmath_uint4_xxzx_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.x = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xxzy(stdmath_uint4 v) { return {v.x,v.x,v.z,v.y}; }
inline static stdmath_uint4 stdmath_uint4_xxzy_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.x = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xxzz(stdmath_uint4 v) { return {v.x,v.x,v.z,v.z}; }
inline static stdmath_uint4 stdmath_uint4_xxzz_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.x = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xxzw(stdmath_uint4 v) { return {v.x,v.x,v.z,v.w}; }
inline static stdmath_uint4 stdmath_uint4_xxzw_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.x = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xxwx(stdmath_uint4 v) { return {v.x,v.x,v.w,v.x}; }
inline static stdmath_uint4 stdmath_uint4_xxwx_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.x = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xxwy(stdmath_uint4 v) { return {v.x,v.x,v.w,v.y}; }
inline static stdmath_uint4 stdmath_uint4_xxwy_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.x = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xxwz(stdmath_uint4 v) { return {v.x,v.x,v.w,v.z}; }
inline static stdmath_uint4 stdmath_uint4_xxwz_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.x = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xxww(stdmath_uint4 v) { return {v.x,v.x,v.w,v.w}; }
inline static stdmath_uint4 stdmath_uint4_xxww_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.x = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xyxx(stdmath_uint4 v) { return {v.x,v.y,v.x,v.x}; }
inline static stdmath_uint4 stdmath_uint4_xyxx_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.y = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xyxy(stdmath_uint4 v) { return {v.x,v.y,v.x,v.y}; }
inline static stdmath_uint4 stdmath_uint4_xyxy_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.y = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xyxz(stdmath_uint4 v) { return {v.x,v.y,v.x,v.z}; }
inline static stdmath_uint4 stdmath_uint4_xyxz_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.y = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xyxw(stdmath_uint4 v) { return {v.x,v.y,v.x,v.w}; }
inline static stdmath_uint4 stdmath_uint4_xyxw_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.y = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xyyx(stdmath_uint4 v) { return {v.x,v.y,v.y,v.x}; }
inline static stdmath_uint4 stdmath_uint4_xyyx_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.y = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xyyy(stdmath_uint4 v) { return {v.x,v.y,v.y,v.y}; }
inline static stdmath_uint4 stdmath_uint4_xyyy_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.y = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xyyz(stdmath_uint4 v) { return {v.x,v.y,v.y,v.z}; }
inline static stdmath_uint4 stdmath_uint4_xyyz_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.y = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xyyw(stdmath_uint4 v) { return {v.x,v.y,v.y,v.w}; }
inline static stdmath_uint4 stdmath_uint4_xyyw_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.y = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xyzx(stdmath_uint4 v) { return {v.x,v.y,v.z,v.x}; }
inline static stdmath_uint4 stdmath_uint4_xyzx_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.y = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xyzy(stdmath_uint4 v) { return {v.x,v.y,v.z,v.y}; }
inline static stdmath_uint4 stdmath_uint4_xyzy_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.y = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xyzz(stdmath_uint4 v) { return {v.x,v.y,v.z,v.z}; }
inline static stdmath_uint4 stdmath_uint4_xyzz_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.y = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xyzw(stdmath_uint4 v) { return {v.x,v.y,v.z,v.w}; }
inline static stdmath_uint4 stdmath_uint4_xyzw_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.y = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xywx(stdmath_uint4 v) { return {v.x,v.y,v.w,v.x}; }
inline static stdmath_uint4 stdmath_uint4_xywx_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.y = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xywy(stdmath_uint4 v) { return {v.x,v.y,v.w,v.y}; }
inline static stdmath_uint4 stdmath_uint4_xywy_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.y = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xywz(stdmath_uint4 v) { return {v.x,v.y,v.w,v.z}; }
inline static stdmath_uint4 stdmath_uint4_xywz_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.y = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xyww(stdmath_uint4 v) { return {v.x,v.y,v.w,v.w}; }
inline static stdmath_uint4 stdmath_uint4_xyww_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.y = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xzxx(stdmath_uint4 v) { return {v.x,v.z,v.x,v.x}; }
inline static stdmath_uint4 stdmath_uint4_xzxx_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.z = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xzxy(stdmath_uint4 v) { return {v.x,v.z,v.x,v.y}; }
inline static stdmath_uint4 stdmath_uint4_xzxy_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.z = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xzxz(stdmath_uint4 v) { return {v.x,v.z,v.x,v.z}; }
inline static stdmath_uint4 stdmath_uint4_xzxz_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.z = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xzxw(stdmath_uint4 v) { return {v.x,v.z,v.x,v.w}; }
inline static stdmath_uint4 stdmath_uint4_xzxw_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.z = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xzyx(stdmath_uint4 v) { return {v.x,v.z,v.y,v.x}; }
inline static stdmath_uint4 stdmath_uint4_xzyx_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.z = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xzyy(stdmath_uint4 v) { return {v.x,v.z,v.y,v.y}; }
inline static stdmath_uint4 stdmath_uint4_xzyy_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.z = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xzyz(stdmath_uint4 v) { return {v.x,v.z,v.y,v.z}; }
inline static stdmath_uint4 stdmath_uint4_xzyz_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.z = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xzyw(stdmath_uint4 v) { return {v.x,v.z,v.y,v.w}; }
inline static stdmath_uint4 stdmath_uint4_xzyw_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.z = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xzzx(stdmath_uint4 v) { return {v.x,v.z,v.z,v.x}; }
inline static stdmath_uint4 stdmath_uint4_xzzx_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.z = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xzzy(stdmath_uint4 v) { return {v.x,v.z,v.z,v.y}; }
inline static stdmath_uint4 stdmath_uint4_xzzy_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.z = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xzzz(stdmath_uint4 v) { return {v.x,v.z,v.z,v.z}; }
inline static stdmath_uint4 stdmath_uint4_xzzz_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.z = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xzzw(stdmath_uint4 v) { return {v.x,v.z,v.z,v.w}; }
inline static stdmath_uint4 stdmath_uint4_xzzw_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.z = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xzwx(stdmath_uint4 v) { return {v.x,v.z,v.w,v.x}; }
inline static stdmath_uint4 stdmath_uint4_xzwx_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.z = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xzwy(stdmath_uint4 v) { return {v.x,v.z,v.w,v.y}; }
inline static stdmath_uint4 stdmath_uint4_xzwy_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.z = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xzwz(stdmath_uint4 v) { return {v.x,v.z,v.w,v.z}; }
inline static stdmath_uint4 stdmath_uint4_xzwz_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.z = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xzww(stdmath_uint4 v) { return {v.x,v.z,v.w,v.w}; }
inline static stdmath_uint4 stdmath_uint4_xzww_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.z = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xwxx(stdmath_uint4 v) { return {v.x,v.w,v.x,v.x}; }
inline static stdmath_uint4 stdmath_uint4_xwxx_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.w = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xwxy(stdmath_uint4 v) { return {v.x,v.w,v.x,v.y}; }
inline static stdmath_uint4 stdmath_uint4_xwxy_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.w = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xwxz(stdmath_uint4 v) { return {v.x,v.w,v.x,v.z}; }
inline static stdmath_uint4 stdmath_uint4_xwxz_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.w = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xwxw(stdmath_uint4 v) { return {v.x,v.w,v.x,v.w}; }
inline static stdmath_uint4 stdmath_uint4_xwxw_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.w = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xwyx(stdmath_uint4 v) { return {v.x,v.w,v.y,v.x}; }
inline static stdmath_uint4 stdmath_uint4_xwyx_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.w = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xwyy(stdmath_uint4 v) { return {v.x,v.w,v.y,v.y}; }
inline static stdmath_uint4 stdmath_uint4_xwyy_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.w = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xwyz(stdmath_uint4 v) { return {v.x,v.w,v.y,v.z}; }
inline static stdmath_uint4 stdmath_uint4_xwyz_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.w = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xwyw(stdmath_uint4 v) { return {v.x,v.w,v.y,v.w}; }
inline static stdmath_uint4 stdmath_uint4_xwyw_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.w = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xwzx(stdmath_uint4 v) { return {v.x,v.w,v.z,v.x}; }
inline static stdmath_uint4 stdmath_uint4_xwzx_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.w = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xwzy(stdmath_uint4 v) { return {v.x,v.w,v.z,v.y}; }
inline static stdmath_uint4 stdmath_uint4_xwzy_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.w = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xwzz(stdmath_uint4 v) { return {v.x,v.w,v.z,v.z}; }
inline static stdmath_uint4 stdmath_uint4_xwzz_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.w = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xwzw(stdmath_uint4 v) { return {v.x,v.w,v.z,v.w}; }
inline static stdmath_uint4 stdmath_uint4_xwzw_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.w = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xwwx(stdmath_uint4 v) { return {v.x,v.w,v.w,v.x}; }
inline static stdmath_uint4 stdmath_uint4_xwwx_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.w = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xwwy(stdmath_uint4 v) { return {v.x,v.w,v.w,v.y}; }
inline static stdmath_uint4 stdmath_uint4_xwwy_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.w = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xwwz(stdmath_uint4 v) { return {v.x,v.w,v.w,v.z}; }
inline static stdmath_uint4 stdmath_uint4_xwwz_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.w = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_xwww(stdmath_uint4 v) { return {v.x,v.w,v.w,v.w}; }
inline static stdmath_uint4 stdmath_uint4_xwww_value(stdmath_uint4 v, stdmath_uint4 value) { v.x = value.x; v.w = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_yxxx(stdmath_uint4 v) { return {v.y,v.x,v.x,v.x}; }
inline static stdmath_uint4 stdmath_uint4_yxxx_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.x = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_yxxy(stdmath_uint4 v) { return {v.y,v.x,v.x,v.y}; }
inline static stdmath_uint4 stdmath_uint4_yxxy_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.x = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_yxxz(stdmath_uint4 v) { return {v.y,v.x,v.x,v.z}; }
inline static stdmath_uint4 stdmath_uint4_yxxz_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.x = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_yxxw(stdmath_uint4 v) { return {v.y,v.x,v.x,v.w}; }
inline static stdmath_uint4 stdmath_uint4_yxxw_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.x = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_yxyx(stdmath_uint4 v) { return {v.y,v.x,v.y,v.x}; }
inline static stdmath_uint4 stdmath_uint4_yxyx_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.x = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_yxyy(stdmath_uint4 v) { return {v.y,v.x,v.y,v.y}; }
inline static stdmath_uint4 stdmath_uint4_yxyy_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.x = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_yxyz(stdmath_uint4 v) { return {v.y,v.x,v.y,v.z}; }
inline static stdmath_uint4 stdmath_uint4_yxyz_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.x = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_yxyw(stdmath_uint4 v) { return {v.y,v.x,v.y,v.w}; }
inline static stdmath_uint4 stdmath_uint4_yxyw_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.x = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_yxzx(stdmath_uint4 v) { return {v.y,v.x,v.z,v.x}; }
inline static stdmath_uint4 stdmath_uint4_yxzx_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.x = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_yxzy(stdmath_uint4 v) { return {v.y,v.x,v.z,v.y}; }
inline static stdmath_uint4 stdmath_uint4_yxzy_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.x = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_yxzz(stdmath_uint4 v) { return {v.y,v.x,v.z,v.z}; }
inline static stdmath_uint4 stdmath_uint4_yxzz_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.x = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_yxzw(stdmath_uint4 v) { return {v.y,v.x,v.z,v.w}; }
inline static stdmath_uint4 stdmath_uint4_yxzw_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.x = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_yxwx(stdmath_uint4 v) { return {v.y,v.x,v.w,v.x}; }
inline static stdmath_uint4 stdmath_uint4_yxwx_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.x = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_yxwy(stdmath_uint4 v) { return {v.y,v.x,v.w,v.y}; }
inline static stdmath_uint4 stdmath_uint4_yxwy_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.x = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_yxwz(stdmath_uint4 v) { return {v.y,v.x,v.w,v.z}; }
inline static stdmath_uint4 stdmath_uint4_yxwz_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.x = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_yxww(stdmath_uint4 v) { return {v.y,v.x,v.w,v.w}; }
inline static stdmath_uint4 stdmath_uint4_yxww_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.x = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_yyxx(stdmath_uint4 v) { return {v.y,v.y,v.x,v.x}; }
inline static stdmath_uint4 stdmath_uint4_yyxx_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.y = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_yyxy(stdmath_uint4 v) { return {v.y,v.y,v.x,v.y}; }
inline static stdmath_uint4 stdmath_uint4_yyxy_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.y = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_yyxz(stdmath_uint4 v) { return {v.y,v.y,v.x,v.z}; }
inline static stdmath_uint4 stdmath_uint4_yyxz_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.y = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_yyxw(stdmath_uint4 v) { return {v.y,v.y,v.x,v.w}; }
inline static stdmath_uint4 stdmath_uint4_yyxw_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.y = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_yyyx(stdmath_uint4 v) { return {v.y,v.y,v.y,v.x}; }
inline static stdmath_uint4 stdmath_uint4_yyyx_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.y = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_yyyy(stdmath_uint4 v) { return {v.y,v.y,v.y,v.y}; }
inline static stdmath_uint4 stdmath_uint4_yyyy_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.y = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_yyyz(stdmath_uint4 v) { return {v.y,v.y,v.y,v.z}; }
inline static stdmath_uint4 stdmath_uint4_yyyz_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.y = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_yyyw(stdmath_uint4 v) { return {v.y,v.y,v.y,v.w}; }
inline static stdmath_uint4 stdmath_uint4_yyyw_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.y = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_yyzx(stdmath_uint4 v) { return {v.y,v.y,v.z,v.x}; }
inline static stdmath_uint4 stdmath_uint4_yyzx_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.y = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_yyzy(stdmath_uint4 v) { return {v.y,v.y,v.z,v.y}; }
inline static stdmath_uint4 stdmath_uint4_yyzy_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.y = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_yyzz(stdmath_uint4 v) { return {v.y,v.y,v.z,v.z}; }
inline static stdmath_uint4 stdmath_uint4_yyzz_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.y = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_yyzw(stdmath_uint4 v) { return {v.y,v.y,v.z,v.w}; }
inline static stdmath_uint4 stdmath_uint4_yyzw_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.y = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_yywx(stdmath_uint4 v) { return {v.y,v.y,v.w,v.x}; }
inline static stdmath_uint4 stdmath_uint4_yywx_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.y = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_yywy(stdmath_uint4 v) { return {v.y,v.y,v.w,v.y}; }
inline static stdmath_uint4 stdmath_uint4_yywy_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.y = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_yywz(stdmath_uint4 v) { return {v.y,v.y,v.w,v.z}; }
inline static stdmath_uint4 stdmath_uint4_yywz_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.y = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_yyww(stdmath_uint4 v) { return {v.y,v.y,v.w,v.w}; }
inline static stdmath_uint4 stdmath_uint4_yyww_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.y = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_yzxx(stdmath_uint4 v) { return {v.y,v.z,v.x,v.x}; }
inline static stdmath_uint4 stdmath_uint4_yzxx_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.z = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_yzxy(stdmath_uint4 v) { return {v.y,v.z,v.x,v.y}; }
inline static stdmath_uint4 stdmath_uint4_yzxy_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.z = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_yzxz(stdmath_uint4 v) { return {v.y,v.z,v.x,v.z}; }
inline static stdmath_uint4 stdmath_uint4_yzxz_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.z = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_yzxw(stdmath_uint4 v) { return {v.y,v.z,v.x,v.w}; }
inline static stdmath_uint4 stdmath_uint4_yzxw_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.z = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_yzyx(stdmath_uint4 v) { return {v.y,v.z,v.y,v.x}; }
inline static stdmath_uint4 stdmath_uint4_yzyx_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.z = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_yzyy(stdmath_uint4 v) { return {v.y,v.z,v.y,v.y}; }
inline static stdmath_uint4 stdmath_uint4_yzyy_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.z = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_yzyz(stdmath_uint4 v) { return {v.y,v.z,v.y,v.z}; }
inline static stdmath_uint4 stdmath_uint4_yzyz_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.z = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_yzyw(stdmath_uint4 v) { return {v.y,v.z,v.y,v.w}; }
inline static stdmath_uint4 stdmath_uint4_yzyw_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.z = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_yzzx(stdmath_uint4 v) { return {v.y,v.z,v.z,v.x}; }
inline static stdmath_uint4 stdmath_uint4_yzzx_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.z = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_yzzy(stdmath_uint4 v) { return {v.y,v.z,v.z,v.y}; }
inline static stdmath_uint4 stdmath_uint4_yzzy_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.z = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_yzzz(stdmath_uint4 v) { return {v.y,v.z,v.z,v.z}; }
inline static stdmath_uint4 stdmath_uint4_yzzz_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.z = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_yzzw(stdmath_uint4 v) { return {v.y,v.z,v.z,v.w}; }
inline static stdmath_uint4 stdmath_uint4_yzzw_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.z = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_yzwx(stdmath_uint4 v) { return {v.y,v.z,v.w,v.x}; }
inline static stdmath_uint4 stdmath_uint4_yzwx_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.z = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_yzwy(stdmath_uint4 v) { return {v.y,v.z,v.w,v.y}; }
inline static stdmath_uint4 stdmath_uint4_yzwy_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.z = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_yzwz(stdmath_uint4 v) { return {v.y,v.z,v.w,v.z}; }
inline static stdmath_uint4 stdmath_uint4_yzwz_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.z = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_yzww(stdmath_uint4 v) { return {v.y,v.z,v.w,v.w}; }
inline static stdmath_uint4 stdmath_uint4_yzww_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.z = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_ywxx(stdmath_uint4 v) { return {v.y,v.w,v.x,v.x}; }
inline static stdmath_uint4 stdmath_uint4_ywxx_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.w = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_ywxy(stdmath_uint4 v) { return {v.y,v.w,v.x,v.y}; }
inline static stdmath_uint4 stdmath_uint4_ywxy_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.w = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_ywxz(stdmath_uint4 v) { return {v.y,v.w,v.x,v.z}; }
inline static stdmath_uint4 stdmath_uint4_ywxz_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.w = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_ywxw(stdmath_uint4 v) { return {v.y,v.w,v.x,v.w}; }
inline static stdmath_uint4 stdmath_uint4_ywxw_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.w = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_ywyx(stdmath_uint4 v) { return {v.y,v.w,v.y,v.x}; }
inline static stdmath_uint4 stdmath_uint4_ywyx_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.w = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_ywyy(stdmath_uint4 v) { return {v.y,v.w,v.y,v.y}; }
inline static stdmath_uint4 stdmath_uint4_ywyy_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.w = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_ywyz(stdmath_uint4 v) { return {v.y,v.w,v.y,v.z}; }
inline static stdmath_uint4 stdmath_uint4_ywyz_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.w = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_ywyw(stdmath_uint4 v) { return {v.y,v.w,v.y,v.w}; }
inline static stdmath_uint4 stdmath_uint4_ywyw_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.w = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_ywzx(stdmath_uint4 v) { return {v.y,v.w,v.z,v.x}; }
inline static stdmath_uint4 stdmath_uint4_ywzx_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.w = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_ywzy(stdmath_uint4 v) { return {v.y,v.w,v.z,v.y}; }
inline static stdmath_uint4 stdmath_uint4_ywzy_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.w = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_ywzz(stdmath_uint4 v) { return {v.y,v.w,v.z,v.z}; }
inline static stdmath_uint4 stdmath_uint4_ywzz_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.w = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_ywzw(stdmath_uint4 v) { return {v.y,v.w,v.z,v.w}; }
inline static stdmath_uint4 stdmath_uint4_ywzw_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.w = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_ywwx(stdmath_uint4 v) { return {v.y,v.w,v.w,v.x}; }
inline static stdmath_uint4 stdmath_uint4_ywwx_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.w = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_ywwy(stdmath_uint4 v) { return {v.y,v.w,v.w,v.y}; }
inline static stdmath_uint4 stdmath_uint4_ywwy_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.w = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_ywwz(stdmath_uint4 v) { return {v.y,v.w,v.w,v.z}; }
inline static stdmath_uint4 stdmath_uint4_ywwz_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.w = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_ywww(stdmath_uint4 v) { return {v.y,v.w,v.w,v.w}; }
inline static stdmath_uint4 stdmath_uint4_ywww_value(stdmath_uint4 v, stdmath_uint4 value) { v.y = value.x; v.w = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zxxx(stdmath_uint4 v) { return {v.z,v.x,v.x,v.x}; }
inline static stdmath_uint4 stdmath_uint4_zxxx_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.x = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zxxy(stdmath_uint4 v) { return {v.z,v.x,v.x,v.y}; }
inline static stdmath_uint4 stdmath_uint4_zxxy_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.x = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zxxz(stdmath_uint4 v) { return {v.z,v.x,v.x,v.z}; }
inline static stdmath_uint4 stdmath_uint4_zxxz_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.x = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zxxw(stdmath_uint4 v) { return {v.z,v.x,v.x,v.w}; }
inline static stdmath_uint4 stdmath_uint4_zxxw_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.x = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zxyx(stdmath_uint4 v) { return {v.z,v.x,v.y,v.x}; }
inline static stdmath_uint4 stdmath_uint4_zxyx_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.x = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zxyy(stdmath_uint4 v) { return {v.z,v.x,v.y,v.y}; }
inline static stdmath_uint4 stdmath_uint4_zxyy_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.x = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zxyz(stdmath_uint4 v) { return {v.z,v.x,v.y,v.z}; }
inline static stdmath_uint4 stdmath_uint4_zxyz_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.x = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zxyw(stdmath_uint4 v) { return {v.z,v.x,v.y,v.w}; }
inline static stdmath_uint4 stdmath_uint4_zxyw_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.x = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zxzx(stdmath_uint4 v) { return {v.z,v.x,v.z,v.x}; }
inline static stdmath_uint4 stdmath_uint4_zxzx_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.x = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zxzy(stdmath_uint4 v) { return {v.z,v.x,v.z,v.y}; }
inline static stdmath_uint4 stdmath_uint4_zxzy_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.x = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zxzz(stdmath_uint4 v) { return {v.z,v.x,v.z,v.z}; }
inline static stdmath_uint4 stdmath_uint4_zxzz_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.x = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zxzw(stdmath_uint4 v) { return {v.z,v.x,v.z,v.w}; }
inline static stdmath_uint4 stdmath_uint4_zxzw_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.x = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zxwx(stdmath_uint4 v) { return {v.z,v.x,v.w,v.x}; }
inline static stdmath_uint4 stdmath_uint4_zxwx_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.x = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zxwy(stdmath_uint4 v) { return {v.z,v.x,v.w,v.y}; }
inline static stdmath_uint4 stdmath_uint4_zxwy_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.x = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zxwz(stdmath_uint4 v) { return {v.z,v.x,v.w,v.z}; }
inline static stdmath_uint4 stdmath_uint4_zxwz_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.x = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zxww(stdmath_uint4 v) { return {v.z,v.x,v.w,v.w}; }
inline static stdmath_uint4 stdmath_uint4_zxww_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.x = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zyxx(stdmath_uint4 v) { return {v.z,v.y,v.x,v.x}; }
inline static stdmath_uint4 stdmath_uint4_zyxx_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.y = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zyxy(stdmath_uint4 v) { return {v.z,v.y,v.x,v.y}; }
inline static stdmath_uint4 stdmath_uint4_zyxy_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.y = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zyxz(stdmath_uint4 v) { return {v.z,v.y,v.x,v.z}; }
inline static stdmath_uint4 stdmath_uint4_zyxz_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.y = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zyxw(stdmath_uint4 v) { return {v.z,v.y,v.x,v.w}; }
inline static stdmath_uint4 stdmath_uint4_zyxw_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.y = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zyyx(stdmath_uint4 v) { return {v.z,v.y,v.y,v.x}; }
inline static stdmath_uint4 stdmath_uint4_zyyx_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.y = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zyyy(stdmath_uint4 v) { return {v.z,v.y,v.y,v.y}; }
inline static stdmath_uint4 stdmath_uint4_zyyy_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.y = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zyyz(stdmath_uint4 v) { return {v.z,v.y,v.y,v.z}; }
inline static stdmath_uint4 stdmath_uint4_zyyz_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.y = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zyyw(stdmath_uint4 v) { return {v.z,v.y,v.y,v.w}; }
inline static stdmath_uint4 stdmath_uint4_zyyw_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.y = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zyzx(stdmath_uint4 v) { return {v.z,v.y,v.z,v.x}; }
inline static stdmath_uint4 stdmath_uint4_zyzx_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.y = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zyzy(stdmath_uint4 v) { return {v.z,v.y,v.z,v.y}; }
inline static stdmath_uint4 stdmath_uint4_zyzy_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.y = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zyzz(stdmath_uint4 v) { return {v.z,v.y,v.z,v.z}; }
inline static stdmath_uint4 stdmath_uint4_zyzz_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.y = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zyzw(stdmath_uint4 v) { return {v.z,v.y,v.z,v.w}; }
inline static stdmath_uint4 stdmath_uint4_zyzw_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.y = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zywx(stdmath_uint4 v) { return {v.z,v.y,v.w,v.x}; }
inline static stdmath_uint4 stdmath_uint4_zywx_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.y = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zywy(stdmath_uint4 v) { return {v.z,v.y,v.w,v.y}; }
inline static stdmath_uint4 stdmath_uint4_zywy_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.y = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zywz(stdmath_uint4 v) { return {v.z,v.y,v.w,v.z}; }
inline static stdmath_uint4 stdmath_uint4_zywz_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.y = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zyww(stdmath_uint4 v) { return {v.z,v.y,v.w,v.w}; }
inline static stdmath_uint4 stdmath_uint4_zyww_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.y = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zzxx(stdmath_uint4 v) { return {v.z,v.z,v.x,v.x}; }
inline static stdmath_uint4 stdmath_uint4_zzxx_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.z = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zzxy(stdmath_uint4 v) { return {v.z,v.z,v.x,v.y}; }
inline static stdmath_uint4 stdmath_uint4_zzxy_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.z = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zzxz(stdmath_uint4 v) { return {v.z,v.z,v.x,v.z}; }
inline static stdmath_uint4 stdmath_uint4_zzxz_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.z = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zzxw(stdmath_uint4 v) { return {v.z,v.z,v.x,v.w}; }
inline static stdmath_uint4 stdmath_uint4_zzxw_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.z = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zzyx(stdmath_uint4 v) { return {v.z,v.z,v.y,v.x}; }
inline static stdmath_uint4 stdmath_uint4_zzyx_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.z = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zzyy(stdmath_uint4 v) { return {v.z,v.z,v.y,v.y}; }
inline static stdmath_uint4 stdmath_uint4_zzyy_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.z = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zzyz(stdmath_uint4 v) { return {v.z,v.z,v.y,v.z}; }
inline static stdmath_uint4 stdmath_uint4_zzyz_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.z = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zzyw(stdmath_uint4 v) { return {v.z,v.z,v.y,v.w}; }
inline static stdmath_uint4 stdmath_uint4_zzyw_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.z = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zzzx(stdmath_uint4 v) { return {v.z,v.z,v.z,v.x}; }
inline static stdmath_uint4 stdmath_uint4_zzzx_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.z = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zzzy(stdmath_uint4 v) { return {v.z,v.z,v.z,v.y}; }
inline static stdmath_uint4 stdmath_uint4_zzzy_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.z = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zzzz(stdmath_uint4 v) { return {v.z,v.z,v.z,v.z}; }
inline static stdmath_uint4 stdmath_uint4_zzzz_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.z = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zzzw(stdmath_uint4 v) { return {v.z,v.z,v.z,v.w}; }
inline static stdmath_uint4 stdmath_uint4_zzzw_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.z = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zzwx(stdmath_uint4 v) { return {v.z,v.z,v.w,v.x}; }
inline static stdmath_uint4 stdmath_uint4_zzwx_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.z = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zzwy(stdmath_uint4 v) { return {v.z,v.z,v.w,v.y}; }
inline static stdmath_uint4 stdmath_uint4_zzwy_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.z = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zzwz(stdmath_uint4 v) { return {v.z,v.z,v.w,v.z}; }
inline static stdmath_uint4 stdmath_uint4_zzwz_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.z = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zzww(stdmath_uint4 v) { return {v.z,v.z,v.w,v.w}; }
inline static stdmath_uint4 stdmath_uint4_zzww_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.z = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zwxx(stdmath_uint4 v) { return {v.z,v.w,v.x,v.x}; }
inline static stdmath_uint4 stdmath_uint4_zwxx_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.w = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zwxy(stdmath_uint4 v) { return {v.z,v.w,v.x,v.y}; }
inline static stdmath_uint4 stdmath_uint4_zwxy_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.w = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zwxz(stdmath_uint4 v) { return {v.z,v.w,v.x,v.z}; }
inline static stdmath_uint4 stdmath_uint4_zwxz_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.w = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zwxw(stdmath_uint4 v) { return {v.z,v.w,v.x,v.w}; }
inline static stdmath_uint4 stdmath_uint4_zwxw_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.w = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zwyx(stdmath_uint4 v) { return {v.z,v.w,v.y,v.x}; }
inline static stdmath_uint4 stdmath_uint4_zwyx_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.w = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zwyy(stdmath_uint4 v) { return {v.z,v.w,v.y,v.y}; }
inline static stdmath_uint4 stdmath_uint4_zwyy_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.w = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zwyz(stdmath_uint4 v) { return {v.z,v.w,v.y,v.z}; }
inline static stdmath_uint4 stdmath_uint4_zwyz_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.w = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zwyw(stdmath_uint4 v) { return {v.z,v.w,v.y,v.w}; }
inline static stdmath_uint4 stdmath_uint4_zwyw_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.w = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zwzx(stdmath_uint4 v) { return {v.z,v.w,v.z,v.x}; }
inline static stdmath_uint4 stdmath_uint4_zwzx_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.w = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zwzy(stdmath_uint4 v) { return {v.z,v.w,v.z,v.y}; }
inline static stdmath_uint4 stdmath_uint4_zwzy_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.w = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zwzz(stdmath_uint4 v) { return {v.z,v.w,v.z,v.z}; }
inline static stdmath_uint4 stdmath_uint4_zwzz_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.w = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zwzw(stdmath_uint4 v) { return {v.z,v.w,v.z,v.w}; }
inline static stdmath_uint4 stdmath_uint4_zwzw_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.w = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zwwx(stdmath_uint4 v) { return {v.z,v.w,v.w,v.x}; }
inline static stdmath_uint4 stdmath_uint4_zwwx_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.w = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zwwy(stdmath_uint4 v) { return {v.z,v.w,v.w,v.y}; }
inline static stdmath_uint4 stdmath_uint4_zwwy_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.w = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zwwz(stdmath_uint4 v) { return {v.z,v.w,v.w,v.z}; }
inline static stdmath_uint4 stdmath_uint4_zwwz_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.w = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_zwww(stdmath_uint4 v) { return {v.z,v.w,v.w,v.w}; }
inline static stdmath_uint4 stdmath_uint4_zwww_value(stdmath_uint4 v, stdmath_uint4 value) { v.z = value.x; v.w = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wxxx(stdmath_uint4 v) { return {v.w,v.x,v.x,v.x}; }
inline static stdmath_uint4 stdmath_uint4_wxxx_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.x = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wxxy(stdmath_uint4 v) { return {v.w,v.x,v.x,v.y}; }
inline static stdmath_uint4 stdmath_uint4_wxxy_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.x = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wxxz(stdmath_uint4 v) { return {v.w,v.x,v.x,v.z}; }
inline static stdmath_uint4 stdmath_uint4_wxxz_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.x = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wxxw(stdmath_uint4 v) { return {v.w,v.x,v.x,v.w}; }
inline static stdmath_uint4 stdmath_uint4_wxxw_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.x = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wxyx(stdmath_uint4 v) { return {v.w,v.x,v.y,v.x}; }
inline static stdmath_uint4 stdmath_uint4_wxyx_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.x = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wxyy(stdmath_uint4 v) { return {v.w,v.x,v.y,v.y}; }
inline static stdmath_uint4 stdmath_uint4_wxyy_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.x = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wxyz(stdmath_uint4 v) { return {v.w,v.x,v.y,v.z}; }
inline static stdmath_uint4 stdmath_uint4_wxyz_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.x = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wxyw(stdmath_uint4 v) { return {v.w,v.x,v.y,v.w}; }
inline static stdmath_uint4 stdmath_uint4_wxyw_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.x = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wxzx(stdmath_uint4 v) { return {v.w,v.x,v.z,v.x}; }
inline static stdmath_uint4 stdmath_uint4_wxzx_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.x = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wxzy(stdmath_uint4 v) { return {v.w,v.x,v.z,v.y}; }
inline static stdmath_uint4 stdmath_uint4_wxzy_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.x = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wxzz(stdmath_uint4 v) { return {v.w,v.x,v.z,v.z}; }
inline static stdmath_uint4 stdmath_uint4_wxzz_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.x = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wxzw(stdmath_uint4 v) { return {v.w,v.x,v.z,v.w}; }
inline static stdmath_uint4 stdmath_uint4_wxzw_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.x = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wxwx(stdmath_uint4 v) { return {v.w,v.x,v.w,v.x}; }
inline static stdmath_uint4 stdmath_uint4_wxwx_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.x = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wxwy(stdmath_uint4 v) { return {v.w,v.x,v.w,v.y}; }
inline static stdmath_uint4 stdmath_uint4_wxwy_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.x = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wxwz(stdmath_uint4 v) { return {v.w,v.x,v.w,v.z}; }
inline static stdmath_uint4 stdmath_uint4_wxwz_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.x = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wxww(stdmath_uint4 v) { return {v.w,v.x,v.w,v.w}; }
inline static stdmath_uint4 stdmath_uint4_wxww_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.x = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wyxx(stdmath_uint4 v) { return {v.w,v.y,v.x,v.x}; }
inline static stdmath_uint4 stdmath_uint4_wyxx_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.y = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wyxy(stdmath_uint4 v) { return {v.w,v.y,v.x,v.y}; }
inline static stdmath_uint4 stdmath_uint4_wyxy_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.y = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wyxz(stdmath_uint4 v) { return {v.w,v.y,v.x,v.z}; }
inline static stdmath_uint4 stdmath_uint4_wyxz_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.y = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wyxw(stdmath_uint4 v) { return {v.w,v.y,v.x,v.w}; }
inline static stdmath_uint4 stdmath_uint4_wyxw_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.y = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wyyx(stdmath_uint4 v) { return {v.w,v.y,v.y,v.x}; }
inline static stdmath_uint4 stdmath_uint4_wyyx_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.y = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wyyy(stdmath_uint4 v) { return {v.w,v.y,v.y,v.y}; }
inline static stdmath_uint4 stdmath_uint4_wyyy_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.y = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wyyz(stdmath_uint4 v) { return {v.w,v.y,v.y,v.z}; }
inline static stdmath_uint4 stdmath_uint4_wyyz_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.y = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wyyw(stdmath_uint4 v) { return {v.w,v.y,v.y,v.w}; }
inline static stdmath_uint4 stdmath_uint4_wyyw_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.y = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wyzx(stdmath_uint4 v) { return {v.w,v.y,v.z,v.x}; }
inline static stdmath_uint4 stdmath_uint4_wyzx_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.y = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wyzy(stdmath_uint4 v) { return {v.w,v.y,v.z,v.y}; }
inline static stdmath_uint4 stdmath_uint4_wyzy_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.y = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wyzz(stdmath_uint4 v) { return {v.w,v.y,v.z,v.z}; }
inline static stdmath_uint4 stdmath_uint4_wyzz_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.y = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wyzw(stdmath_uint4 v) { return {v.w,v.y,v.z,v.w}; }
inline static stdmath_uint4 stdmath_uint4_wyzw_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.y = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wywx(stdmath_uint4 v) { return {v.w,v.y,v.w,v.x}; }
inline static stdmath_uint4 stdmath_uint4_wywx_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.y = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wywy(stdmath_uint4 v) { return {v.w,v.y,v.w,v.y}; }
inline static stdmath_uint4 stdmath_uint4_wywy_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.y = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wywz(stdmath_uint4 v) { return {v.w,v.y,v.w,v.z}; }
inline static stdmath_uint4 stdmath_uint4_wywz_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.y = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wyww(stdmath_uint4 v) { return {v.w,v.y,v.w,v.w}; }
inline static stdmath_uint4 stdmath_uint4_wyww_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.y = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wzxx(stdmath_uint4 v) { return {v.w,v.z,v.x,v.x}; }
inline static stdmath_uint4 stdmath_uint4_wzxx_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.z = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wzxy(stdmath_uint4 v) { return {v.w,v.z,v.x,v.y}; }
inline static stdmath_uint4 stdmath_uint4_wzxy_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.z = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wzxz(stdmath_uint4 v) { return {v.w,v.z,v.x,v.z}; }
inline static stdmath_uint4 stdmath_uint4_wzxz_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.z = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wzxw(stdmath_uint4 v) { return {v.w,v.z,v.x,v.w}; }
inline static stdmath_uint4 stdmath_uint4_wzxw_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.z = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wzyx(stdmath_uint4 v) { return {v.w,v.z,v.y,v.x}; }
inline static stdmath_uint4 stdmath_uint4_wzyx_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.z = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wzyy(stdmath_uint4 v) { return {v.w,v.z,v.y,v.y}; }
inline static stdmath_uint4 stdmath_uint4_wzyy_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.z = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wzyz(stdmath_uint4 v) { return {v.w,v.z,v.y,v.z}; }
inline static stdmath_uint4 stdmath_uint4_wzyz_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.z = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wzyw(stdmath_uint4 v) { return {v.w,v.z,v.y,v.w}; }
inline static stdmath_uint4 stdmath_uint4_wzyw_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.z = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wzzx(stdmath_uint4 v) { return {v.w,v.z,v.z,v.x}; }
inline static stdmath_uint4 stdmath_uint4_wzzx_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.z = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wzzy(stdmath_uint4 v) { return {v.w,v.z,v.z,v.y}; }
inline static stdmath_uint4 stdmath_uint4_wzzy_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.z = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wzzz(stdmath_uint4 v) { return {v.w,v.z,v.z,v.z}; }
inline static stdmath_uint4 stdmath_uint4_wzzz_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.z = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wzzw(stdmath_uint4 v) { return {v.w,v.z,v.z,v.w}; }
inline static stdmath_uint4 stdmath_uint4_wzzw_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.z = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wzwx(stdmath_uint4 v) { return {v.w,v.z,v.w,v.x}; }
inline static stdmath_uint4 stdmath_uint4_wzwx_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.z = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wzwy(stdmath_uint4 v) { return {v.w,v.z,v.w,v.y}; }
inline static stdmath_uint4 stdmath_uint4_wzwy_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.z = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wzwz(stdmath_uint4 v) { return {v.w,v.z,v.w,v.z}; }
inline static stdmath_uint4 stdmath_uint4_wzwz_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.z = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wzww(stdmath_uint4 v) { return {v.w,v.z,v.w,v.w}; }
inline static stdmath_uint4 stdmath_uint4_wzww_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.z = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wwxx(stdmath_uint4 v) { return {v.w,v.w,v.x,v.x}; }
inline static stdmath_uint4 stdmath_uint4_wwxx_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.w = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wwxy(stdmath_uint4 v) { return {v.w,v.w,v.x,v.y}; }
inline static stdmath_uint4 stdmath_uint4_wwxy_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.w = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wwxz(stdmath_uint4 v) { return {v.w,v.w,v.x,v.z}; }
inline static stdmath_uint4 stdmath_uint4_wwxz_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.w = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wwxw(stdmath_uint4 v) { return {v.w,v.w,v.x,v.w}; }
inline static stdmath_uint4 stdmath_uint4_wwxw_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.w = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wwyx(stdmath_uint4 v) { return {v.w,v.w,v.y,v.x}; }
inline static stdmath_uint4 stdmath_uint4_wwyx_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.w = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wwyy(stdmath_uint4 v) { return {v.w,v.w,v.y,v.y}; }
inline static stdmath_uint4 stdmath_uint4_wwyy_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.w = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wwyz(stdmath_uint4 v) { return {v.w,v.w,v.y,v.z}; }
inline static stdmath_uint4 stdmath_uint4_wwyz_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.w = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wwyw(stdmath_uint4 v) { return {v.w,v.w,v.y,v.w}; }
inline static stdmath_uint4 stdmath_uint4_wwyw_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.w = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wwzx(stdmath_uint4 v) { return {v.w,v.w,v.z,v.x}; }
inline static stdmath_uint4 stdmath_uint4_wwzx_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.w = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wwzy(stdmath_uint4 v) { return {v.w,v.w,v.z,v.y}; }
inline static stdmath_uint4 stdmath_uint4_wwzy_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.w = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wwzz(stdmath_uint4 v) { return {v.w,v.w,v.z,v.z}; }
inline static stdmath_uint4 stdmath_uint4_wwzz_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.w = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wwzw(stdmath_uint4 v) { return {v.w,v.w,v.z,v.w}; }
inline static stdmath_uint4 stdmath_uint4_wwzw_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.w = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wwwx(stdmath_uint4 v) { return {v.w,v.w,v.w,v.x}; }
inline static stdmath_uint4 stdmath_uint4_wwwx_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.w = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wwwy(stdmath_uint4 v) { return {v.w,v.w,v.w,v.y}; }
inline static stdmath_uint4 stdmath_uint4_wwwy_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.w = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wwwz(stdmath_uint4 v) { return {v.w,v.w,v.w,v.z}; }
inline static stdmath_uint4 stdmath_uint4_wwwz_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.w = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_uint4 stdmath_uint4_wwww(stdmath_uint4 v) { return {v.w,v.w,v.w,v.w}; }
inline static stdmath_uint4 stdmath_uint4_wwww_value(stdmath_uint4 v, stdmath_uint4 value) { v.w = value.x; v.w = value.y; v.w = value.z; v.w = value.w; return v; }


#ifdef STDMATH_IMPLEMENTATION
#ifndef __cplusplus
#error "The stdmath implementations require a C++ compiler"
#endif

import stdmath.slang;

stdmath::uint4 c(stdmath_uint4 c) {
	return (stdmath::uint4&)c;
}
stdmath_uint4 c(stdmath::uint4 c) {
	return (stdmath_uint4&)c;
}

stdmath_uint4 stdmath_uint4_broadcast(uint32_t all) {
	return c(stdmath::uint4((stdmath::uint4::underlying_type)all));
}

stdmath_uint4 stdmath_uint4_add(stdmath_uint4 a, stdmath_uint4 b) {
	return c(c(a) + c(b));
}
stdmath_uint4 stdmath_uint4_subtract(stdmath_uint4 a, stdmath_uint4 b) {
	return c(c(a) - c(b));
}
stdmath_uint4 stdmath_uint4_negate(stdmath_uint4 v) {
	return c(stdmath::uint4(-(stdmath::vector<uint32_t, 4>)c(v)));
}
stdmath_uint4 stdmath_uint4_multiply(stdmath_uint4 a, stdmath_uint4 b) {
	return c(c(a) * c(b));
}
stdmath_uint4 stdmath_uint4_divide(stdmath_uint4 a, stdmath_uint4 b) {
	return c(c(a) / c(b));
}
stdmath_uint4 stdmath_uint4_scale(stdmath_uint4 v, uint32_t s) {
	return c(c(v) * (stdmath::uint4::underlying_type)s);
}

#if false
stdmath_uint4 stdmath_uint4_modulus(stdmath_uint4 a, stdmath_uint4 b) {
	return c(c(a) % c(b));
}
stdmath_uint4 stdmath_uint4_logical_not(stdmath_uint4 v) {
	return c(!c(v));
}
stdmath_uint4 stdmath_uint4_bitwise_not(stdmath_uint4 v) {
	return c(~c(v));
}
stdmath_uint4 stdmath_uint4_logical_and(stdmath_uint4 a, stdmath_uint4 b) {
	return c(c(a) && c(b));
}
stdmath_uint4 stdmath_uint4_bitwise_and(stdmath_uint4 a, stdmath_uint4 b) {
	return c(c(a) & c(b));
}
stdmath_uint4 stdmath_uint4_logical_or(stdmath_uint4 a, stdmath_uint4 b) {
	return c(c(a) || c(b));
}
stdmath_uint4 stdmath_uint4_bitwise_or(stdmath_uint4 a, stdmath_uint4 b) {
	return c(c(a) | c(b));
}
stdmath_uint4 stdmath_uint4_bitwise_xor(stdmath_uint4 a, stdmath_uint4 b) {
	return c(c(a) ^ c(b));
}
stdmath_uint4 stdmath_uint4_shift_left(stdmath_uint4 a, stdmath_uint4 b) {
	return c(c(a) << c(b));
}
stdmath_uint4 stdmath_uint4_shift_right(stdmath_uint4 a, stdmath_uint4 b) {
	return c(c(a) >> c(b));
}
#endif

stdmath_bool4 stdmath_uint4_equal_to(stdmath_uint4 a, stdmath_uint4 b) {
	return c(c(a) == c(b));
}
stdmath_bool4 stdmath_uint4_not_equal_to(stdmath_uint4 a, stdmath_uint4 b) {
	return c(c(a) != c(b));
}
stdmath_bool4 stdmath_uint4_less_than(stdmath_uint4 a, stdmath_uint4 b) {
	return c(c(a) < c(b));
}
stdmath_bool4 stdmath_uint4_less_than_or_equal_to(stdmath_uint4 a, stdmath_uint4 b) {
	return c(c(a) <= c(b));
}
stdmath_bool4 stdmath_uint4_greater_than(stdmath_uint4 a, stdmath_uint4 b) {
	return c(c(a) > c(b));
}
stdmath_bool4 stdmath_uint4_greater_than_or_equal_to(stdmath_uint4 a, stdmath_uint4 b) {
	return c(c(a) >= c(b));
}

uint32_t stdmath_uint4_length_squared(stdmath_uint4 v)  {
	return (uint32_t)c(v).length_squared();
}
uint32_t stdmath_uint4_length(stdmath_uint4 v)  {
	return (uint32_t)c(v).length();
}
uint32_t stdmath_uint4_dot(stdmath_uint4 a, stdmath_uint4 b)  {
	return (uint32_t)dot(c(a), c(b));
}
uint32_t stdmath_uint4_min_element(stdmath_uint4 v)  {
	return (uint32_t)c(v).min_element();
}
uint32_t stdmath_uint4_max_element(stdmath_uint4 v)  {
	return (uint32_t)c(v).max_element();
}

stdmath_uint4 stdmath_uint4_elementwise_transform(stdmath_uint4 v, uint32_t(*func)(uint32_t)) {
	return c(c(v).elementwise_transform(func));
}
// uint32_t stdmath_uint4_reduce_elements(stdmath_uint4 v, uint32_t initial_value, uint32_t(*reducer)(stdmath_uint4, stdmath_uint4)) {
// 	return c(v).reduce_elements(initial_value, reducer);
// }

#if 4 == 3
stdmath_uint4 stdmath_uint4_cross(stdmath_uint4 a, stdmath_uint4 b) {
	return c(cross(c(a), c(b)));
}
#endif

stdmath_uint4 stdmath_uint4_min(stdmath_uint4 a, stdmath_uint4 b) {
	return c(min(c(a), c(b)));
}
stdmath_uint4 stdmath_uint4_max(stdmath_uint4 a, stdmath_uint4 b) {
	return c(max(c(a), c(b)));
}
stdmath_uint4 stdmath_uint4_normalize(stdmath_uint4 v) {
	return c(normalize(c(v)));
}
stdmath_uint4 stdmath_uint4_lerp(stdmath_uint4 a, stdmath_uint4 b, float t) {
	return c(lerp(c(a), c(b), t));
}
stdmath_uint4 stdmath_uint4_clamp(stdmath_uint4 a, stdmath_uint4 min, stdmath_uint4 max) {
	return c(clamp(c(a), c(min), c(max)));
}
stdmath_uint4 stdmath_uint4_reflect(stdmath_uint4 a, stdmath_uint4 b) {
	return c(reflect(c(a), c(b)));
}
stdmath_bool4 stdmath_uint4_approximately_equal(stdmath_uint4 a, stdmath_uint4 b) {
	return c(approximately_equal(c(a), c(b)));
}

#if false
bool stdmath_bool4_all_of(stdmath_bool4 v) {
	return all_of(c(v));
}
bool stdmath_bool4_any_of(stdmath_bool4 v) {
	return any_of(c(v));
}
bool stdmath_bool4_none_of(stdmath_bool4 v) {
	return none_of(c(v));
}
bool stdmath_bool4_some_of(stdmath_bool4 v) {
	return some_of(c(v));
}
#endif

#endif // STDMATH_IMPLEMENTATION

#endif // __STDMATH_uint32_t4_H__