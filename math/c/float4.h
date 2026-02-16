#ifndef __STDMATH_float4_H__
#define __STDMATH_float4_H__

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
#include "float1.h"
#elif 4 == 3
#include "float2.h"
#include "float1.h"
#elif 4 == 4
#include "float3.h"
#include "float2.h"
#include "float1.h"
#endif
#include "util.h"

#if 4 == 1
union stdmath_float1 {
	struct {
		float x;
	};
	float data[1];
};
#elif 4 == 2
union stdmath_float2 {
	struct {
		float x, y;
	};
	struct {
		float u, v;
	};
	float data[2];
};
#elif 4 == 3
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
#elif 4 == 4
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

stdmath_float4 stdmath_float4_broadcast(float all);

stdmath_float4 stdmath_float4_add(stdmath_float4 a, stdmath_float4 b);
stdmath_float4 stdmath_float4_subtract(stdmath_float4 a, stdmath_float4 b);
stdmath_float4 stdmath_float4_negate(stdmath_float4 v);
stdmath_float4 stdmath_float4_multiply(stdmath_float4 a, stdmath_float4 b);
stdmath_float4 stdmath_float4_divide(stdmath_float4 a, stdmath_float4 b);
stdmath_float4 stdmath_float4_scale(stdmath_float4 v, float s);

#if false
stdmath_float4 stdmath_float4_modulus(stdmath_float4 a, stdmath_float4 b);
stdmath_float4 stdmath_float4_logical_not(stdmath_float4 v);
stdmath_float4 stdmath_float4_bitwise_not(stdmath_float4 v);
stdmath_float4 stdmath_float4_logical_and(stdmath_float4 a, stdmath_float4 b);
stdmath_float4 stdmath_float4_bitwise_and(stdmath_float4 a, stdmath_float4 b);
stdmath_float4 stdmath_float4_logical_or(stdmath_float4 a, stdmath_float4 b);
stdmath_float4 stdmath_float4_bitwise_or(stdmath_float4 a, stdmath_float4 b);
stdmath_float4 stdmath_float4_bitwise_xor(stdmath_float4 a, stdmath_float4 b);
stdmath_float4 stdmath_float4_shift_left(stdmath_float4 a, stdmath_float4 b);
stdmath_float4 stdmath_float4_shift_right(stdmath_float4 a, stdmath_float4 b);
#endif

stdmath_bool4 stdmath_float4_equal_to(stdmath_float4 a, stdmath_float4 b);
stdmath_bool4 stdmath_float4_not_equal_to(stdmath_float4 a, stdmath_float4 b);
stdmath_bool4 stdmath_float4_less_than(stdmath_float4 a, stdmath_float4 b);
stdmath_bool4 stdmath_float4_less_than_or_equal_to(stdmath_float4 a, stdmath_float4 b);
stdmath_bool4 stdmath_float4_greater_than(stdmath_float4 a, stdmath_float4 b);
stdmath_bool4 stdmath_float4_greater_than_or_equal_to(stdmath_float4 a, stdmath_float4 b);

float stdmath_float4_length_squared(stdmath_float4 v);
float stdmath_float4_length(stdmath_float4 v);
float stdmath_float4_dot(stdmath_float4 v);
float stdmath_float4_min_element(stdmath_float4 v);
float stdmath_float4_max_element(stdmath_float4 v);

stdmath_float4 stdmath_float4_elementwise_transform(stdmath_float4 v, float(*func)(float));
// float stdmath_float4_reduce_elements(stdmath_float4 v, float initial_value, float(*reducer)(stdmath_float4, stdmath_float4));

#if 4 == 3
stdmath_float3 stdmath_float3_cross(stdmath_float3 a, stdmath_float3 b);
#endif

stdmath_float4 stdmath_float4_min(stdmath_float4 a, stdmath_float4 b);
stdmath_float4 stdmath_float4_max(stdmath_float4 a, stdmath_float4 b);
stdmath_float4 stdmath_float4_normalize(stdmath_float4 v);
stdmath_float4 stdmath_float4_lerp(stdmath_float4 a, stdmath_float4 b, float t);
stdmath_float4 stdmath_float4_clamp(stdmath_float4 a, stdmath_float4 min, stdmath_float4 max);
stdmath_float4 stdmath_float4_reflect(stdmath_float4 a, stdmath_float4 b);
stdmath_bool4 stdmath_float4_approximately_equal(stdmath_float4 a, stdmath_float4 b);

#if false
bool stdmath_bool4_all_of(stdmath_bool4 v);
bool stdmath_bool4_any_of(stdmath_bool4 v);
bool stdmath_bool4_none_of(stdmath_bool4 v);
bool stdmath_bool4_some_of(stdmath_bool4 v);
#endif

inline static stdmath_float1 stdmath_float4_x(stdmath_float4 v) { return {v.x}; }
inline static stdmath_float4 stdmath_float4_x_value(stdmath_float4 v, stdmath_float1 value) { v.x = value.x; return v; }
inline static stdmath_float1 stdmath_float4_y(stdmath_float4 v) { return {v.y}; }
inline static stdmath_float4 stdmath_float4_y_value(stdmath_float4 v, stdmath_float1 value) { v.y = value.x; return v; }
inline static stdmath_float1 stdmath_float4_z(stdmath_float4 v) { return {v.z}; }
inline static stdmath_float4 stdmath_float4_z_value(stdmath_float4 v, stdmath_float1 value) { v.z = value.x; return v; }
inline static stdmath_float1 stdmath_float4_w(stdmath_float4 v) { return {v.w}; }
inline static stdmath_float4 stdmath_float4_w_value(stdmath_float4 v, stdmath_float1 value) { v.w = value.x; return v; }
inline static stdmath_float2 stdmath_float4_xx(stdmath_float4 v) { return {v.x,v.x}; }
inline static stdmath_float4 stdmath_float4_xx_value(stdmath_float4 v, stdmath_float2 value) { v.x = value.x; v.x = value.y; return v; }
inline static stdmath_float2 stdmath_float4_xy(stdmath_float4 v) { return {v.x,v.y}; }
inline static stdmath_float4 stdmath_float4_xy_value(stdmath_float4 v, stdmath_float2 value) { v.x = value.x; v.y = value.y; return v; }
inline static stdmath_float2 stdmath_float4_xz(stdmath_float4 v) { return {v.x,v.z}; }
inline static stdmath_float4 stdmath_float4_xz_value(stdmath_float4 v, stdmath_float2 value) { v.x = value.x; v.z = value.y; return v; }
inline static stdmath_float2 stdmath_float4_xw(stdmath_float4 v) { return {v.x,v.w}; }
inline static stdmath_float4 stdmath_float4_xw_value(stdmath_float4 v, stdmath_float2 value) { v.x = value.x; v.w = value.y; return v; }
inline static stdmath_float2 stdmath_float4_yx(stdmath_float4 v) { return {v.y,v.x}; }
inline static stdmath_float4 stdmath_float4_yx_value(stdmath_float4 v, stdmath_float2 value) { v.y = value.x; v.x = value.y; return v; }
inline static stdmath_float2 stdmath_float4_yy(stdmath_float4 v) { return {v.y,v.y}; }
inline static stdmath_float4 stdmath_float4_yy_value(stdmath_float4 v, stdmath_float2 value) { v.y = value.x; v.y = value.y; return v; }
inline static stdmath_float2 stdmath_float4_yz(stdmath_float4 v) { return {v.y,v.z}; }
inline static stdmath_float4 stdmath_float4_yz_value(stdmath_float4 v, stdmath_float2 value) { v.y = value.x; v.z = value.y; return v; }
inline static stdmath_float2 stdmath_float4_yw(stdmath_float4 v) { return {v.y,v.w}; }
inline static stdmath_float4 stdmath_float4_yw_value(stdmath_float4 v, stdmath_float2 value) { v.y = value.x; v.w = value.y; return v; }
inline static stdmath_float2 stdmath_float4_zx(stdmath_float4 v) { return {v.z,v.x}; }
inline static stdmath_float4 stdmath_float4_zx_value(stdmath_float4 v, stdmath_float2 value) { v.z = value.x; v.x = value.y; return v; }
inline static stdmath_float2 stdmath_float4_zy(stdmath_float4 v) { return {v.z,v.y}; }
inline static stdmath_float4 stdmath_float4_zy_value(stdmath_float4 v, stdmath_float2 value) { v.z = value.x; v.y = value.y; return v; }
inline static stdmath_float2 stdmath_float4_zz(stdmath_float4 v) { return {v.z,v.z}; }
inline static stdmath_float4 stdmath_float4_zz_value(stdmath_float4 v, stdmath_float2 value) { v.z = value.x; v.z = value.y; return v; }
inline static stdmath_float2 stdmath_float4_zw(stdmath_float4 v) { return {v.z,v.w}; }
inline static stdmath_float4 stdmath_float4_zw_value(stdmath_float4 v, stdmath_float2 value) { v.z = value.x; v.w = value.y; return v; }
inline static stdmath_float2 stdmath_float4_wx(stdmath_float4 v) { return {v.w,v.x}; }
inline static stdmath_float4 stdmath_float4_wx_value(stdmath_float4 v, stdmath_float2 value) { v.w = value.x; v.x = value.y; return v; }
inline static stdmath_float2 stdmath_float4_wy(stdmath_float4 v) { return {v.w,v.y}; }
inline static stdmath_float4 stdmath_float4_wy_value(stdmath_float4 v, stdmath_float2 value) { v.w = value.x; v.y = value.y; return v; }
inline static stdmath_float2 stdmath_float4_wz(stdmath_float4 v) { return {v.w,v.z}; }
inline static stdmath_float4 stdmath_float4_wz_value(stdmath_float4 v, stdmath_float2 value) { v.w = value.x; v.z = value.y; return v; }
inline static stdmath_float2 stdmath_float4_ww(stdmath_float4 v) { return {v.w,v.w}; }
inline static stdmath_float4 stdmath_float4_ww_value(stdmath_float4 v, stdmath_float2 value) { v.w = value.x; v.w = value.y; return v; }
inline static stdmath_float3 stdmath_float4_xxx(stdmath_float4 v) { return {v.x,v.x,v.x}; }
inline static stdmath_float4 stdmath_float4_xxx_value(stdmath_float4 v, stdmath_float3 value) { v.x = value.x; v.x = value.y; v.x = value.z; return v; }
inline static stdmath_float3 stdmath_float4_xxy(stdmath_float4 v) { return {v.x,v.x,v.y}; }
inline static stdmath_float4 stdmath_float4_xxy_value(stdmath_float4 v, stdmath_float3 value) { v.x = value.x; v.x = value.y; v.y = value.z; return v; }
inline static stdmath_float3 stdmath_float4_xxz(stdmath_float4 v) { return {v.x,v.x,v.z}; }
inline static stdmath_float4 stdmath_float4_xxz_value(stdmath_float4 v, stdmath_float3 value) { v.x = value.x; v.x = value.y; v.z = value.z; return v; }
inline static stdmath_float3 stdmath_float4_xxw(stdmath_float4 v) { return {v.x,v.x,v.w}; }
inline static stdmath_float4 stdmath_float4_xxw_value(stdmath_float4 v, stdmath_float3 value) { v.x = value.x; v.x = value.y; v.w = value.z; return v; }
inline static stdmath_float3 stdmath_float4_xyx(stdmath_float4 v) { return {v.x,v.y,v.x}; }
inline static stdmath_float4 stdmath_float4_xyx_value(stdmath_float4 v, stdmath_float3 value) { v.x = value.x; v.y = value.y; v.x = value.z; return v; }
inline static stdmath_float3 stdmath_float4_xyy(stdmath_float4 v) { return {v.x,v.y,v.y}; }
inline static stdmath_float4 stdmath_float4_xyy_value(stdmath_float4 v, stdmath_float3 value) { v.x = value.x; v.y = value.y; v.y = value.z; return v; }
inline static stdmath_float3 stdmath_float4_xyz(stdmath_float4 v) { return {v.x,v.y,v.z}; }
inline static stdmath_float4 stdmath_float4_xyz_value(stdmath_float4 v, stdmath_float3 value) { v.x = value.x; v.y = value.y; v.z = value.z; return v; }
inline static stdmath_float3 stdmath_float4_xyw(stdmath_float4 v) { return {v.x,v.y,v.w}; }
inline static stdmath_float4 stdmath_float4_xyw_value(stdmath_float4 v, stdmath_float3 value) { v.x = value.x; v.y = value.y; v.w = value.z; return v; }
inline static stdmath_float3 stdmath_float4_xzx(stdmath_float4 v) { return {v.x,v.z,v.x}; }
inline static stdmath_float4 stdmath_float4_xzx_value(stdmath_float4 v, stdmath_float3 value) { v.x = value.x; v.z = value.y; v.x = value.z; return v; }
inline static stdmath_float3 stdmath_float4_xzy(stdmath_float4 v) { return {v.x,v.z,v.y}; }
inline static stdmath_float4 stdmath_float4_xzy_value(stdmath_float4 v, stdmath_float3 value) { v.x = value.x; v.z = value.y; v.y = value.z; return v; }
inline static stdmath_float3 stdmath_float4_xzz(stdmath_float4 v) { return {v.x,v.z,v.z}; }
inline static stdmath_float4 stdmath_float4_xzz_value(stdmath_float4 v, stdmath_float3 value) { v.x = value.x; v.z = value.y; v.z = value.z; return v; }
inline static stdmath_float3 stdmath_float4_xzw(stdmath_float4 v) { return {v.x,v.z,v.w}; }
inline static stdmath_float4 stdmath_float4_xzw_value(stdmath_float4 v, stdmath_float3 value) { v.x = value.x; v.z = value.y; v.w = value.z; return v; }
inline static stdmath_float3 stdmath_float4_xwx(stdmath_float4 v) { return {v.x,v.w,v.x}; }
inline static stdmath_float4 stdmath_float4_xwx_value(stdmath_float4 v, stdmath_float3 value) { v.x = value.x; v.w = value.y; v.x = value.z; return v; }
inline static stdmath_float3 stdmath_float4_xwy(stdmath_float4 v) { return {v.x,v.w,v.y}; }
inline static stdmath_float4 stdmath_float4_xwy_value(stdmath_float4 v, stdmath_float3 value) { v.x = value.x; v.w = value.y; v.y = value.z; return v; }
inline static stdmath_float3 stdmath_float4_xwz(stdmath_float4 v) { return {v.x,v.w,v.z}; }
inline static stdmath_float4 stdmath_float4_xwz_value(stdmath_float4 v, stdmath_float3 value) { v.x = value.x; v.w = value.y; v.z = value.z; return v; }
inline static stdmath_float3 stdmath_float4_xww(stdmath_float4 v) { return {v.x,v.w,v.w}; }
inline static stdmath_float4 stdmath_float4_xww_value(stdmath_float4 v, stdmath_float3 value) { v.x = value.x; v.w = value.y; v.w = value.z; return v; }
inline static stdmath_float3 stdmath_float4_yxx(stdmath_float4 v) { return {v.y,v.x,v.x}; }
inline static stdmath_float4 stdmath_float4_yxx_value(stdmath_float4 v, stdmath_float3 value) { v.y = value.x; v.x = value.y; v.x = value.z; return v; }
inline static stdmath_float3 stdmath_float4_yxy(stdmath_float4 v) { return {v.y,v.x,v.y}; }
inline static stdmath_float4 stdmath_float4_yxy_value(stdmath_float4 v, stdmath_float3 value) { v.y = value.x; v.x = value.y; v.y = value.z; return v; }
inline static stdmath_float3 stdmath_float4_yxz(stdmath_float4 v) { return {v.y,v.x,v.z}; }
inline static stdmath_float4 stdmath_float4_yxz_value(stdmath_float4 v, stdmath_float3 value) { v.y = value.x; v.x = value.y; v.z = value.z; return v; }
inline static stdmath_float3 stdmath_float4_yxw(stdmath_float4 v) { return {v.y,v.x,v.w}; }
inline static stdmath_float4 stdmath_float4_yxw_value(stdmath_float4 v, stdmath_float3 value) { v.y = value.x; v.x = value.y; v.w = value.z; return v; }
inline static stdmath_float3 stdmath_float4_yyx(stdmath_float4 v) { return {v.y,v.y,v.x}; }
inline static stdmath_float4 stdmath_float4_yyx_value(stdmath_float4 v, stdmath_float3 value) { v.y = value.x; v.y = value.y; v.x = value.z; return v; }
inline static stdmath_float3 stdmath_float4_yyy(stdmath_float4 v) { return {v.y,v.y,v.y}; }
inline static stdmath_float4 stdmath_float4_yyy_value(stdmath_float4 v, stdmath_float3 value) { v.y = value.x; v.y = value.y; v.y = value.z; return v; }
inline static stdmath_float3 stdmath_float4_yyz(stdmath_float4 v) { return {v.y,v.y,v.z}; }
inline static stdmath_float4 stdmath_float4_yyz_value(stdmath_float4 v, stdmath_float3 value) { v.y = value.x; v.y = value.y; v.z = value.z; return v; }
inline static stdmath_float3 stdmath_float4_yyw(stdmath_float4 v) { return {v.y,v.y,v.w}; }
inline static stdmath_float4 stdmath_float4_yyw_value(stdmath_float4 v, stdmath_float3 value) { v.y = value.x; v.y = value.y; v.w = value.z; return v; }
inline static stdmath_float3 stdmath_float4_yzx(stdmath_float4 v) { return {v.y,v.z,v.x}; }
inline static stdmath_float4 stdmath_float4_yzx_value(stdmath_float4 v, stdmath_float3 value) { v.y = value.x; v.z = value.y; v.x = value.z; return v; }
inline static stdmath_float3 stdmath_float4_yzy(stdmath_float4 v) { return {v.y,v.z,v.y}; }
inline static stdmath_float4 stdmath_float4_yzy_value(stdmath_float4 v, stdmath_float3 value) { v.y = value.x; v.z = value.y; v.y = value.z; return v; }
inline static stdmath_float3 stdmath_float4_yzz(stdmath_float4 v) { return {v.y,v.z,v.z}; }
inline static stdmath_float4 stdmath_float4_yzz_value(stdmath_float4 v, stdmath_float3 value) { v.y = value.x; v.z = value.y; v.z = value.z; return v; }
inline static stdmath_float3 stdmath_float4_yzw(stdmath_float4 v) { return {v.y,v.z,v.w}; }
inline static stdmath_float4 stdmath_float4_yzw_value(stdmath_float4 v, stdmath_float3 value) { v.y = value.x; v.z = value.y; v.w = value.z; return v; }
inline static stdmath_float3 stdmath_float4_ywx(stdmath_float4 v) { return {v.y,v.w,v.x}; }
inline static stdmath_float4 stdmath_float4_ywx_value(stdmath_float4 v, stdmath_float3 value) { v.y = value.x; v.w = value.y; v.x = value.z; return v; }
inline static stdmath_float3 stdmath_float4_ywy(stdmath_float4 v) { return {v.y,v.w,v.y}; }
inline static stdmath_float4 stdmath_float4_ywy_value(stdmath_float4 v, stdmath_float3 value) { v.y = value.x; v.w = value.y; v.y = value.z; return v; }
inline static stdmath_float3 stdmath_float4_ywz(stdmath_float4 v) { return {v.y,v.w,v.z}; }
inline static stdmath_float4 stdmath_float4_ywz_value(stdmath_float4 v, stdmath_float3 value) { v.y = value.x; v.w = value.y; v.z = value.z; return v; }
inline static stdmath_float3 stdmath_float4_yww(stdmath_float4 v) { return {v.y,v.w,v.w}; }
inline static stdmath_float4 stdmath_float4_yww_value(stdmath_float4 v, stdmath_float3 value) { v.y = value.x; v.w = value.y; v.w = value.z; return v; }
inline static stdmath_float3 stdmath_float4_zxx(stdmath_float4 v) { return {v.z,v.x,v.x}; }
inline static stdmath_float4 stdmath_float4_zxx_value(stdmath_float4 v, stdmath_float3 value) { v.z = value.x; v.x = value.y; v.x = value.z; return v; }
inline static stdmath_float3 stdmath_float4_zxy(stdmath_float4 v) { return {v.z,v.x,v.y}; }
inline static stdmath_float4 stdmath_float4_zxy_value(stdmath_float4 v, stdmath_float3 value) { v.z = value.x; v.x = value.y; v.y = value.z; return v; }
inline static stdmath_float3 stdmath_float4_zxz(stdmath_float4 v) { return {v.z,v.x,v.z}; }
inline static stdmath_float4 stdmath_float4_zxz_value(stdmath_float4 v, stdmath_float3 value) { v.z = value.x; v.x = value.y; v.z = value.z; return v; }
inline static stdmath_float3 stdmath_float4_zxw(stdmath_float4 v) { return {v.z,v.x,v.w}; }
inline static stdmath_float4 stdmath_float4_zxw_value(stdmath_float4 v, stdmath_float3 value) { v.z = value.x; v.x = value.y; v.w = value.z; return v; }
inline static stdmath_float3 stdmath_float4_zyx(stdmath_float4 v) { return {v.z,v.y,v.x}; }
inline static stdmath_float4 stdmath_float4_zyx_value(stdmath_float4 v, stdmath_float3 value) { v.z = value.x; v.y = value.y; v.x = value.z; return v; }
inline static stdmath_float3 stdmath_float4_zyy(stdmath_float4 v) { return {v.z,v.y,v.y}; }
inline static stdmath_float4 stdmath_float4_zyy_value(stdmath_float4 v, stdmath_float3 value) { v.z = value.x; v.y = value.y; v.y = value.z; return v; }
inline static stdmath_float3 stdmath_float4_zyz(stdmath_float4 v) { return {v.z,v.y,v.z}; }
inline static stdmath_float4 stdmath_float4_zyz_value(stdmath_float4 v, stdmath_float3 value) { v.z = value.x; v.y = value.y; v.z = value.z; return v; }
inline static stdmath_float3 stdmath_float4_zyw(stdmath_float4 v) { return {v.z,v.y,v.w}; }
inline static stdmath_float4 stdmath_float4_zyw_value(stdmath_float4 v, stdmath_float3 value) { v.z = value.x; v.y = value.y; v.w = value.z; return v; }
inline static stdmath_float3 stdmath_float4_zzx(stdmath_float4 v) { return {v.z,v.z,v.x}; }
inline static stdmath_float4 stdmath_float4_zzx_value(stdmath_float4 v, stdmath_float3 value) { v.z = value.x; v.z = value.y; v.x = value.z; return v; }
inline static stdmath_float3 stdmath_float4_zzy(stdmath_float4 v) { return {v.z,v.z,v.y}; }
inline static stdmath_float4 stdmath_float4_zzy_value(stdmath_float4 v, stdmath_float3 value) { v.z = value.x; v.z = value.y; v.y = value.z; return v; }
inline static stdmath_float3 stdmath_float4_zzz(stdmath_float4 v) { return {v.z,v.z,v.z}; }
inline static stdmath_float4 stdmath_float4_zzz_value(stdmath_float4 v, stdmath_float3 value) { v.z = value.x; v.z = value.y; v.z = value.z; return v; }
inline static stdmath_float3 stdmath_float4_zzw(stdmath_float4 v) { return {v.z,v.z,v.w}; }
inline static stdmath_float4 stdmath_float4_zzw_value(stdmath_float4 v, stdmath_float3 value) { v.z = value.x; v.z = value.y; v.w = value.z; return v; }
inline static stdmath_float3 stdmath_float4_zwx(stdmath_float4 v) { return {v.z,v.w,v.x}; }
inline static stdmath_float4 stdmath_float4_zwx_value(stdmath_float4 v, stdmath_float3 value) { v.z = value.x; v.w = value.y; v.x = value.z; return v; }
inline static stdmath_float3 stdmath_float4_zwy(stdmath_float4 v) { return {v.z,v.w,v.y}; }
inline static stdmath_float4 stdmath_float4_zwy_value(stdmath_float4 v, stdmath_float3 value) { v.z = value.x; v.w = value.y; v.y = value.z; return v; }
inline static stdmath_float3 stdmath_float4_zwz(stdmath_float4 v) { return {v.z,v.w,v.z}; }
inline static stdmath_float4 stdmath_float4_zwz_value(stdmath_float4 v, stdmath_float3 value) { v.z = value.x; v.w = value.y; v.z = value.z; return v; }
inline static stdmath_float3 stdmath_float4_zww(stdmath_float4 v) { return {v.z,v.w,v.w}; }
inline static stdmath_float4 stdmath_float4_zww_value(stdmath_float4 v, stdmath_float3 value) { v.z = value.x; v.w = value.y; v.w = value.z; return v; }
inline static stdmath_float3 stdmath_float4_wxx(stdmath_float4 v) { return {v.w,v.x,v.x}; }
inline static stdmath_float4 stdmath_float4_wxx_value(stdmath_float4 v, stdmath_float3 value) { v.w = value.x; v.x = value.y; v.x = value.z; return v; }
inline static stdmath_float3 stdmath_float4_wxy(stdmath_float4 v) { return {v.w,v.x,v.y}; }
inline static stdmath_float4 stdmath_float4_wxy_value(stdmath_float4 v, stdmath_float3 value) { v.w = value.x; v.x = value.y; v.y = value.z; return v; }
inline static stdmath_float3 stdmath_float4_wxz(stdmath_float4 v) { return {v.w,v.x,v.z}; }
inline static stdmath_float4 stdmath_float4_wxz_value(stdmath_float4 v, stdmath_float3 value) { v.w = value.x; v.x = value.y; v.z = value.z; return v; }
inline static stdmath_float3 stdmath_float4_wxw(stdmath_float4 v) { return {v.w,v.x,v.w}; }
inline static stdmath_float4 stdmath_float4_wxw_value(stdmath_float4 v, stdmath_float3 value) { v.w = value.x; v.x = value.y; v.w = value.z; return v; }
inline static stdmath_float3 stdmath_float4_wyx(stdmath_float4 v) { return {v.w,v.y,v.x}; }
inline static stdmath_float4 stdmath_float4_wyx_value(stdmath_float4 v, stdmath_float3 value) { v.w = value.x; v.y = value.y; v.x = value.z; return v; }
inline static stdmath_float3 stdmath_float4_wyy(stdmath_float4 v) { return {v.w,v.y,v.y}; }
inline static stdmath_float4 stdmath_float4_wyy_value(stdmath_float4 v, stdmath_float3 value) { v.w = value.x; v.y = value.y; v.y = value.z; return v; }
inline static stdmath_float3 stdmath_float4_wyz(stdmath_float4 v) { return {v.w,v.y,v.z}; }
inline static stdmath_float4 stdmath_float4_wyz_value(stdmath_float4 v, stdmath_float3 value) { v.w = value.x; v.y = value.y; v.z = value.z; return v; }
inline static stdmath_float3 stdmath_float4_wyw(stdmath_float4 v) { return {v.w,v.y,v.w}; }
inline static stdmath_float4 stdmath_float4_wyw_value(stdmath_float4 v, stdmath_float3 value) { v.w = value.x; v.y = value.y; v.w = value.z; return v; }
inline static stdmath_float3 stdmath_float4_wzx(stdmath_float4 v) { return {v.w,v.z,v.x}; }
inline static stdmath_float4 stdmath_float4_wzx_value(stdmath_float4 v, stdmath_float3 value) { v.w = value.x; v.z = value.y; v.x = value.z; return v; }
inline static stdmath_float3 stdmath_float4_wzy(stdmath_float4 v) { return {v.w,v.z,v.y}; }
inline static stdmath_float4 stdmath_float4_wzy_value(stdmath_float4 v, stdmath_float3 value) { v.w = value.x; v.z = value.y; v.y = value.z; return v; }
inline static stdmath_float3 stdmath_float4_wzz(stdmath_float4 v) { return {v.w,v.z,v.z}; }
inline static stdmath_float4 stdmath_float4_wzz_value(stdmath_float4 v, stdmath_float3 value) { v.w = value.x; v.z = value.y; v.z = value.z; return v; }
inline static stdmath_float3 stdmath_float4_wzw(stdmath_float4 v) { return {v.w,v.z,v.w}; }
inline static stdmath_float4 stdmath_float4_wzw_value(stdmath_float4 v, stdmath_float3 value) { v.w = value.x; v.z = value.y; v.w = value.z; return v; }
inline static stdmath_float3 stdmath_float4_wwx(stdmath_float4 v) { return {v.w,v.w,v.x}; }
inline static stdmath_float4 stdmath_float4_wwx_value(stdmath_float4 v, stdmath_float3 value) { v.w = value.x; v.w = value.y; v.x = value.z; return v; }
inline static stdmath_float3 stdmath_float4_wwy(stdmath_float4 v) { return {v.w,v.w,v.y}; }
inline static stdmath_float4 stdmath_float4_wwy_value(stdmath_float4 v, stdmath_float3 value) { v.w = value.x; v.w = value.y; v.y = value.z; return v; }
inline static stdmath_float3 stdmath_float4_wwz(stdmath_float4 v) { return {v.w,v.w,v.z}; }
inline static stdmath_float4 stdmath_float4_wwz_value(stdmath_float4 v, stdmath_float3 value) { v.w = value.x; v.w = value.y; v.z = value.z; return v; }
inline static stdmath_float3 stdmath_float4_www(stdmath_float4 v) { return {v.w,v.w,v.w}; }
inline static stdmath_float4 stdmath_float4_www_value(stdmath_float4 v, stdmath_float3 value) { v.w = value.x; v.w = value.y; v.w = value.z; return v; }
inline static stdmath_float4 stdmath_float4_xxxx(stdmath_float4 v) { return {v.x,v.x,v.x,v.x}; }
inline static stdmath_float4 stdmath_float4_xxxx_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.x = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xxxy(stdmath_float4 v) { return {v.x,v.x,v.x,v.y}; }
inline static stdmath_float4 stdmath_float4_xxxy_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.x = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xxxz(stdmath_float4 v) { return {v.x,v.x,v.x,v.z}; }
inline static stdmath_float4 stdmath_float4_xxxz_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.x = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xxxw(stdmath_float4 v) { return {v.x,v.x,v.x,v.w}; }
inline static stdmath_float4 stdmath_float4_xxxw_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.x = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xxyx(stdmath_float4 v) { return {v.x,v.x,v.y,v.x}; }
inline static stdmath_float4 stdmath_float4_xxyx_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.x = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xxyy(stdmath_float4 v) { return {v.x,v.x,v.y,v.y}; }
inline static stdmath_float4 stdmath_float4_xxyy_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.x = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xxyz(stdmath_float4 v) { return {v.x,v.x,v.y,v.z}; }
inline static stdmath_float4 stdmath_float4_xxyz_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.x = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xxyw(stdmath_float4 v) { return {v.x,v.x,v.y,v.w}; }
inline static stdmath_float4 stdmath_float4_xxyw_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.x = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xxzx(stdmath_float4 v) { return {v.x,v.x,v.z,v.x}; }
inline static stdmath_float4 stdmath_float4_xxzx_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.x = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xxzy(stdmath_float4 v) { return {v.x,v.x,v.z,v.y}; }
inline static stdmath_float4 stdmath_float4_xxzy_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.x = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xxzz(stdmath_float4 v) { return {v.x,v.x,v.z,v.z}; }
inline static stdmath_float4 stdmath_float4_xxzz_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.x = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xxzw(stdmath_float4 v) { return {v.x,v.x,v.z,v.w}; }
inline static stdmath_float4 stdmath_float4_xxzw_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.x = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xxwx(stdmath_float4 v) { return {v.x,v.x,v.w,v.x}; }
inline static stdmath_float4 stdmath_float4_xxwx_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.x = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xxwy(stdmath_float4 v) { return {v.x,v.x,v.w,v.y}; }
inline static stdmath_float4 stdmath_float4_xxwy_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.x = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xxwz(stdmath_float4 v) { return {v.x,v.x,v.w,v.z}; }
inline static stdmath_float4 stdmath_float4_xxwz_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.x = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xxww(stdmath_float4 v) { return {v.x,v.x,v.w,v.w}; }
inline static stdmath_float4 stdmath_float4_xxww_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.x = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xyxx(stdmath_float4 v) { return {v.x,v.y,v.x,v.x}; }
inline static stdmath_float4 stdmath_float4_xyxx_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.y = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xyxy(stdmath_float4 v) { return {v.x,v.y,v.x,v.y}; }
inline static stdmath_float4 stdmath_float4_xyxy_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.y = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xyxz(stdmath_float4 v) { return {v.x,v.y,v.x,v.z}; }
inline static stdmath_float4 stdmath_float4_xyxz_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.y = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xyxw(stdmath_float4 v) { return {v.x,v.y,v.x,v.w}; }
inline static stdmath_float4 stdmath_float4_xyxw_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.y = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xyyx(stdmath_float4 v) { return {v.x,v.y,v.y,v.x}; }
inline static stdmath_float4 stdmath_float4_xyyx_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.y = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xyyy(stdmath_float4 v) { return {v.x,v.y,v.y,v.y}; }
inline static stdmath_float4 stdmath_float4_xyyy_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.y = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xyyz(stdmath_float4 v) { return {v.x,v.y,v.y,v.z}; }
inline static stdmath_float4 stdmath_float4_xyyz_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.y = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xyyw(stdmath_float4 v) { return {v.x,v.y,v.y,v.w}; }
inline static stdmath_float4 stdmath_float4_xyyw_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.y = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xyzx(stdmath_float4 v) { return {v.x,v.y,v.z,v.x}; }
inline static stdmath_float4 stdmath_float4_xyzx_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.y = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xyzy(stdmath_float4 v) { return {v.x,v.y,v.z,v.y}; }
inline static stdmath_float4 stdmath_float4_xyzy_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.y = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xyzz(stdmath_float4 v) { return {v.x,v.y,v.z,v.z}; }
inline static stdmath_float4 stdmath_float4_xyzz_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.y = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xyzw(stdmath_float4 v) { return {v.x,v.y,v.z,v.w}; }
inline static stdmath_float4 stdmath_float4_xyzw_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.y = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xywx(stdmath_float4 v) { return {v.x,v.y,v.w,v.x}; }
inline static stdmath_float4 stdmath_float4_xywx_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.y = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xywy(stdmath_float4 v) { return {v.x,v.y,v.w,v.y}; }
inline static stdmath_float4 stdmath_float4_xywy_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.y = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xywz(stdmath_float4 v) { return {v.x,v.y,v.w,v.z}; }
inline static stdmath_float4 stdmath_float4_xywz_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.y = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xyww(stdmath_float4 v) { return {v.x,v.y,v.w,v.w}; }
inline static stdmath_float4 stdmath_float4_xyww_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.y = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xzxx(stdmath_float4 v) { return {v.x,v.z,v.x,v.x}; }
inline static stdmath_float4 stdmath_float4_xzxx_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.z = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xzxy(stdmath_float4 v) { return {v.x,v.z,v.x,v.y}; }
inline static stdmath_float4 stdmath_float4_xzxy_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.z = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xzxz(stdmath_float4 v) { return {v.x,v.z,v.x,v.z}; }
inline static stdmath_float4 stdmath_float4_xzxz_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.z = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xzxw(stdmath_float4 v) { return {v.x,v.z,v.x,v.w}; }
inline static stdmath_float4 stdmath_float4_xzxw_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.z = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xzyx(stdmath_float4 v) { return {v.x,v.z,v.y,v.x}; }
inline static stdmath_float4 stdmath_float4_xzyx_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.z = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xzyy(stdmath_float4 v) { return {v.x,v.z,v.y,v.y}; }
inline static stdmath_float4 stdmath_float4_xzyy_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.z = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xzyz(stdmath_float4 v) { return {v.x,v.z,v.y,v.z}; }
inline static stdmath_float4 stdmath_float4_xzyz_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.z = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xzyw(stdmath_float4 v) { return {v.x,v.z,v.y,v.w}; }
inline static stdmath_float4 stdmath_float4_xzyw_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.z = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xzzx(stdmath_float4 v) { return {v.x,v.z,v.z,v.x}; }
inline static stdmath_float4 stdmath_float4_xzzx_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.z = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xzzy(stdmath_float4 v) { return {v.x,v.z,v.z,v.y}; }
inline static stdmath_float4 stdmath_float4_xzzy_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.z = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xzzz(stdmath_float4 v) { return {v.x,v.z,v.z,v.z}; }
inline static stdmath_float4 stdmath_float4_xzzz_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.z = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xzzw(stdmath_float4 v) { return {v.x,v.z,v.z,v.w}; }
inline static stdmath_float4 stdmath_float4_xzzw_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.z = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xzwx(stdmath_float4 v) { return {v.x,v.z,v.w,v.x}; }
inline static stdmath_float4 stdmath_float4_xzwx_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.z = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xzwy(stdmath_float4 v) { return {v.x,v.z,v.w,v.y}; }
inline static stdmath_float4 stdmath_float4_xzwy_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.z = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xzwz(stdmath_float4 v) { return {v.x,v.z,v.w,v.z}; }
inline static stdmath_float4 stdmath_float4_xzwz_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.z = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xzww(stdmath_float4 v) { return {v.x,v.z,v.w,v.w}; }
inline static stdmath_float4 stdmath_float4_xzww_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.z = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xwxx(stdmath_float4 v) { return {v.x,v.w,v.x,v.x}; }
inline static stdmath_float4 stdmath_float4_xwxx_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.w = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xwxy(stdmath_float4 v) { return {v.x,v.w,v.x,v.y}; }
inline static stdmath_float4 stdmath_float4_xwxy_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.w = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xwxz(stdmath_float4 v) { return {v.x,v.w,v.x,v.z}; }
inline static stdmath_float4 stdmath_float4_xwxz_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.w = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xwxw(stdmath_float4 v) { return {v.x,v.w,v.x,v.w}; }
inline static stdmath_float4 stdmath_float4_xwxw_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.w = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xwyx(stdmath_float4 v) { return {v.x,v.w,v.y,v.x}; }
inline static stdmath_float4 stdmath_float4_xwyx_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.w = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xwyy(stdmath_float4 v) { return {v.x,v.w,v.y,v.y}; }
inline static stdmath_float4 stdmath_float4_xwyy_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.w = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xwyz(stdmath_float4 v) { return {v.x,v.w,v.y,v.z}; }
inline static stdmath_float4 stdmath_float4_xwyz_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.w = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xwyw(stdmath_float4 v) { return {v.x,v.w,v.y,v.w}; }
inline static stdmath_float4 stdmath_float4_xwyw_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.w = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xwzx(stdmath_float4 v) { return {v.x,v.w,v.z,v.x}; }
inline static stdmath_float4 stdmath_float4_xwzx_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.w = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xwzy(stdmath_float4 v) { return {v.x,v.w,v.z,v.y}; }
inline static stdmath_float4 stdmath_float4_xwzy_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.w = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xwzz(stdmath_float4 v) { return {v.x,v.w,v.z,v.z}; }
inline static stdmath_float4 stdmath_float4_xwzz_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.w = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xwzw(stdmath_float4 v) { return {v.x,v.w,v.z,v.w}; }
inline static stdmath_float4 stdmath_float4_xwzw_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.w = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xwwx(stdmath_float4 v) { return {v.x,v.w,v.w,v.x}; }
inline static stdmath_float4 stdmath_float4_xwwx_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.w = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xwwy(stdmath_float4 v) { return {v.x,v.w,v.w,v.y}; }
inline static stdmath_float4 stdmath_float4_xwwy_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.w = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xwwz(stdmath_float4 v) { return {v.x,v.w,v.w,v.z}; }
inline static stdmath_float4 stdmath_float4_xwwz_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.w = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_xwww(stdmath_float4 v) { return {v.x,v.w,v.w,v.w}; }
inline static stdmath_float4 stdmath_float4_xwww_value(stdmath_float4 v, stdmath_float4 value) { v.x = value.x; v.w = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_yxxx(stdmath_float4 v) { return {v.y,v.x,v.x,v.x}; }
inline static stdmath_float4 stdmath_float4_yxxx_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.x = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_yxxy(stdmath_float4 v) { return {v.y,v.x,v.x,v.y}; }
inline static stdmath_float4 stdmath_float4_yxxy_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.x = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_yxxz(stdmath_float4 v) { return {v.y,v.x,v.x,v.z}; }
inline static stdmath_float4 stdmath_float4_yxxz_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.x = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_yxxw(stdmath_float4 v) { return {v.y,v.x,v.x,v.w}; }
inline static stdmath_float4 stdmath_float4_yxxw_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.x = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_yxyx(stdmath_float4 v) { return {v.y,v.x,v.y,v.x}; }
inline static stdmath_float4 stdmath_float4_yxyx_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.x = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_yxyy(stdmath_float4 v) { return {v.y,v.x,v.y,v.y}; }
inline static stdmath_float4 stdmath_float4_yxyy_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.x = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_yxyz(stdmath_float4 v) { return {v.y,v.x,v.y,v.z}; }
inline static stdmath_float4 stdmath_float4_yxyz_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.x = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_yxyw(stdmath_float4 v) { return {v.y,v.x,v.y,v.w}; }
inline static stdmath_float4 stdmath_float4_yxyw_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.x = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_yxzx(stdmath_float4 v) { return {v.y,v.x,v.z,v.x}; }
inline static stdmath_float4 stdmath_float4_yxzx_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.x = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_yxzy(stdmath_float4 v) { return {v.y,v.x,v.z,v.y}; }
inline static stdmath_float4 stdmath_float4_yxzy_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.x = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_yxzz(stdmath_float4 v) { return {v.y,v.x,v.z,v.z}; }
inline static stdmath_float4 stdmath_float4_yxzz_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.x = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_yxzw(stdmath_float4 v) { return {v.y,v.x,v.z,v.w}; }
inline static stdmath_float4 stdmath_float4_yxzw_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.x = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_yxwx(stdmath_float4 v) { return {v.y,v.x,v.w,v.x}; }
inline static stdmath_float4 stdmath_float4_yxwx_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.x = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_yxwy(stdmath_float4 v) { return {v.y,v.x,v.w,v.y}; }
inline static stdmath_float4 stdmath_float4_yxwy_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.x = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_yxwz(stdmath_float4 v) { return {v.y,v.x,v.w,v.z}; }
inline static stdmath_float4 stdmath_float4_yxwz_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.x = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_yxww(stdmath_float4 v) { return {v.y,v.x,v.w,v.w}; }
inline static stdmath_float4 stdmath_float4_yxww_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.x = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_yyxx(stdmath_float4 v) { return {v.y,v.y,v.x,v.x}; }
inline static stdmath_float4 stdmath_float4_yyxx_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.y = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_yyxy(stdmath_float4 v) { return {v.y,v.y,v.x,v.y}; }
inline static stdmath_float4 stdmath_float4_yyxy_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.y = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_yyxz(stdmath_float4 v) { return {v.y,v.y,v.x,v.z}; }
inline static stdmath_float4 stdmath_float4_yyxz_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.y = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_yyxw(stdmath_float4 v) { return {v.y,v.y,v.x,v.w}; }
inline static stdmath_float4 stdmath_float4_yyxw_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.y = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_yyyx(stdmath_float4 v) { return {v.y,v.y,v.y,v.x}; }
inline static stdmath_float4 stdmath_float4_yyyx_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.y = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_yyyy(stdmath_float4 v) { return {v.y,v.y,v.y,v.y}; }
inline static stdmath_float4 stdmath_float4_yyyy_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.y = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_yyyz(stdmath_float4 v) { return {v.y,v.y,v.y,v.z}; }
inline static stdmath_float4 stdmath_float4_yyyz_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.y = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_yyyw(stdmath_float4 v) { return {v.y,v.y,v.y,v.w}; }
inline static stdmath_float4 stdmath_float4_yyyw_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.y = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_yyzx(stdmath_float4 v) { return {v.y,v.y,v.z,v.x}; }
inline static stdmath_float4 stdmath_float4_yyzx_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.y = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_yyzy(stdmath_float4 v) { return {v.y,v.y,v.z,v.y}; }
inline static stdmath_float4 stdmath_float4_yyzy_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.y = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_yyzz(stdmath_float4 v) { return {v.y,v.y,v.z,v.z}; }
inline static stdmath_float4 stdmath_float4_yyzz_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.y = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_yyzw(stdmath_float4 v) { return {v.y,v.y,v.z,v.w}; }
inline static stdmath_float4 stdmath_float4_yyzw_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.y = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_yywx(stdmath_float4 v) { return {v.y,v.y,v.w,v.x}; }
inline static stdmath_float4 stdmath_float4_yywx_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.y = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_yywy(stdmath_float4 v) { return {v.y,v.y,v.w,v.y}; }
inline static stdmath_float4 stdmath_float4_yywy_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.y = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_yywz(stdmath_float4 v) { return {v.y,v.y,v.w,v.z}; }
inline static stdmath_float4 stdmath_float4_yywz_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.y = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_yyww(stdmath_float4 v) { return {v.y,v.y,v.w,v.w}; }
inline static stdmath_float4 stdmath_float4_yyww_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.y = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_yzxx(stdmath_float4 v) { return {v.y,v.z,v.x,v.x}; }
inline static stdmath_float4 stdmath_float4_yzxx_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.z = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_yzxy(stdmath_float4 v) { return {v.y,v.z,v.x,v.y}; }
inline static stdmath_float4 stdmath_float4_yzxy_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.z = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_yzxz(stdmath_float4 v) { return {v.y,v.z,v.x,v.z}; }
inline static stdmath_float4 stdmath_float4_yzxz_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.z = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_yzxw(stdmath_float4 v) { return {v.y,v.z,v.x,v.w}; }
inline static stdmath_float4 stdmath_float4_yzxw_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.z = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_yzyx(stdmath_float4 v) { return {v.y,v.z,v.y,v.x}; }
inline static stdmath_float4 stdmath_float4_yzyx_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.z = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_yzyy(stdmath_float4 v) { return {v.y,v.z,v.y,v.y}; }
inline static stdmath_float4 stdmath_float4_yzyy_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.z = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_yzyz(stdmath_float4 v) { return {v.y,v.z,v.y,v.z}; }
inline static stdmath_float4 stdmath_float4_yzyz_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.z = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_yzyw(stdmath_float4 v) { return {v.y,v.z,v.y,v.w}; }
inline static stdmath_float4 stdmath_float4_yzyw_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.z = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_yzzx(stdmath_float4 v) { return {v.y,v.z,v.z,v.x}; }
inline static stdmath_float4 stdmath_float4_yzzx_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.z = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_yzzy(stdmath_float4 v) { return {v.y,v.z,v.z,v.y}; }
inline static stdmath_float4 stdmath_float4_yzzy_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.z = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_yzzz(stdmath_float4 v) { return {v.y,v.z,v.z,v.z}; }
inline static stdmath_float4 stdmath_float4_yzzz_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.z = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_yzzw(stdmath_float4 v) { return {v.y,v.z,v.z,v.w}; }
inline static stdmath_float4 stdmath_float4_yzzw_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.z = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_yzwx(stdmath_float4 v) { return {v.y,v.z,v.w,v.x}; }
inline static stdmath_float4 stdmath_float4_yzwx_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.z = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_yzwy(stdmath_float4 v) { return {v.y,v.z,v.w,v.y}; }
inline static stdmath_float4 stdmath_float4_yzwy_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.z = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_yzwz(stdmath_float4 v) { return {v.y,v.z,v.w,v.z}; }
inline static stdmath_float4 stdmath_float4_yzwz_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.z = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_yzww(stdmath_float4 v) { return {v.y,v.z,v.w,v.w}; }
inline static stdmath_float4 stdmath_float4_yzww_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.z = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_ywxx(stdmath_float4 v) { return {v.y,v.w,v.x,v.x}; }
inline static stdmath_float4 stdmath_float4_ywxx_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.w = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_ywxy(stdmath_float4 v) { return {v.y,v.w,v.x,v.y}; }
inline static stdmath_float4 stdmath_float4_ywxy_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.w = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_ywxz(stdmath_float4 v) { return {v.y,v.w,v.x,v.z}; }
inline static stdmath_float4 stdmath_float4_ywxz_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.w = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_ywxw(stdmath_float4 v) { return {v.y,v.w,v.x,v.w}; }
inline static stdmath_float4 stdmath_float4_ywxw_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.w = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_ywyx(stdmath_float4 v) { return {v.y,v.w,v.y,v.x}; }
inline static stdmath_float4 stdmath_float4_ywyx_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.w = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_ywyy(stdmath_float4 v) { return {v.y,v.w,v.y,v.y}; }
inline static stdmath_float4 stdmath_float4_ywyy_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.w = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_ywyz(stdmath_float4 v) { return {v.y,v.w,v.y,v.z}; }
inline static stdmath_float4 stdmath_float4_ywyz_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.w = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_ywyw(stdmath_float4 v) { return {v.y,v.w,v.y,v.w}; }
inline static stdmath_float4 stdmath_float4_ywyw_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.w = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_ywzx(stdmath_float4 v) { return {v.y,v.w,v.z,v.x}; }
inline static stdmath_float4 stdmath_float4_ywzx_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.w = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_ywzy(stdmath_float4 v) { return {v.y,v.w,v.z,v.y}; }
inline static stdmath_float4 stdmath_float4_ywzy_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.w = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_ywzz(stdmath_float4 v) { return {v.y,v.w,v.z,v.z}; }
inline static stdmath_float4 stdmath_float4_ywzz_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.w = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_ywzw(stdmath_float4 v) { return {v.y,v.w,v.z,v.w}; }
inline static stdmath_float4 stdmath_float4_ywzw_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.w = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_ywwx(stdmath_float4 v) { return {v.y,v.w,v.w,v.x}; }
inline static stdmath_float4 stdmath_float4_ywwx_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.w = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_ywwy(stdmath_float4 v) { return {v.y,v.w,v.w,v.y}; }
inline static stdmath_float4 stdmath_float4_ywwy_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.w = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_ywwz(stdmath_float4 v) { return {v.y,v.w,v.w,v.z}; }
inline static stdmath_float4 stdmath_float4_ywwz_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.w = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_ywww(stdmath_float4 v) { return {v.y,v.w,v.w,v.w}; }
inline static stdmath_float4 stdmath_float4_ywww_value(stdmath_float4 v, stdmath_float4 value) { v.y = value.x; v.w = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zxxx(stdmath_float4 v) { return {v.z,v.x,v.x,v.x}; }
inline static stdmath_float4 stdmath_float4_zxxx_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.x = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zxxy(stdmath_float4 v) { return {v.z,v.x,v.x,v.y}; }
inline static stdmath_float4 stdmath_float4_zxxy_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.x = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zxxz(stdmath_float4 v) { return {v.z,v.x,v.x,v.z}; }
inline static stdmath_float4 stdmath_float4_zxxz_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.x = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zxxw(stdmath_float4 v) { return {v.z,v.x,v.x,v.w}; }
inline static stdmath_float4 stdmath_float4_zxxw_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.x = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zxyx(stdmath_float4 v) { return {v.z,v.x,v.y,v.x}; }
inline static stdmath_float4 stdmath_float4_zxyx_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.x = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zxyy(stdmath_float4 v) { return {v.z,v.x,v.y,v.y}; }
inline static stdmath_float4 stdmath_float4_zxyy_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.x = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zxyz(stdmath_float4 v) { return {v.z,v.x,v.y,v.z}; }
inline static stdmath_float4 stdmath_float4_zxyz_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.x = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zxyw(stdmath_float4 v) { return {v.z,v.x,v.y,v.w}; }
inline static stdmath_float4 stdmath_float4_zxyw_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.x = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zxzx(stdmath_float4 v) { return {v.z,v.x,v.z,v.x}; }
inline static stdmath_float4 stdmath_float4_zxzx_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.x = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zxzy(stdmath_float4 v) { return {v.z,v.x,v.z,v.y}; }
inline static stdmath_float4 stdmath_float4_zxzy_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.x = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zxzz(stdmath_float4 v) { return {v.z,v.x,v.z,v.z}; }
inline static stdmath_float4 stdmath_float4_zxzz_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.x = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zxzw(stdmath_float4 v) { return {v.z,v.x,v.z,v.w}; }
inline static stdmath_float4 stdmath_float4_zxzw_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.x = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zxwx(stdmath_float4 v) { return {v.z,v.x,v.w,v.x}; }
inline static stdmath_float4 stdmath_float4_zxwx_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.x = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zxwy(stdmath_float4 v) { return {v.z,v.x,v.w,v.y}; }
inline static stdmath_float4 stdmath_float4_zxwy_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.x = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zxwz(stdmath_float4 v) { return {v.z,v.x,v.w,v.z}; }
inline static stdmath_float4 stdmath_float4_zxwz_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.x = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zxww(stdmath_float4 v) { return {v.z,v.x,v.w,v.w}; }
inline static stdmath_float4 stdmath_float4_zxww_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.x = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zyxx(stdmath_float4 v) { return {v.z,v.y,v.x,v.x}; }
inline static stdmath_float4 stdmath_float4_zyxx_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.y = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zyxy(stdmath_float4 v) { return {v.z,v.y,v.x,v.y}; }
inline static stdmath_float4 stdmath_float4_zyxy_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.y = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zyxz(stdmath_float4 v) { return {v.z,v.y,v.x,v.z}; }
inline static stdmath_float4 stdmath_float4_zyxz_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.y = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zyxw(stdmath_float4 v) { return {v.z,v.y,v.x,v.w}; }
inline static stdmath_float4 stdmath_float4_zyxw_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.y = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zyyx(stdmath_float4 v) { return {v.z,v.y,v.y,v.x}; }
inline static stdmath_float4 stdmath_float4_zyyx_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.y = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zyyy(stdmath_float4 v) { return {v.z,v.y,v.y,v.y}; }
inline static stdmath_float4 stdmath_float4_zyyy_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.y = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zyyz(stdmath_float4 v) { return {v.z,v.y,v.y,v.z}; }
inline static stdmath_float4 stdmath_float4_zyyz_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.y = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zyyw(stdmath_float4 v) { return {v.z,v.y,v.y,v.w}; }
inline static stdmath_float4 stdmath_float4_zyyw_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.y = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zyzx(stdmath_float4 v) { return {v.z,v.y,v.z,v.x}; }
inline static stdmath_float4 stdmath_float4_zyzx_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.y = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zyzy(stdmath_float4 v) { return {v.z,v.y,v.z,v.y}; }
inline static stdmath_float4 stdmath_float4_zyzy_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.y = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zyzz(stdmath_float4 v) { return {v.z,v.y,v.z,v.z}; }
inline static stdmath_float4 stdmath_float4_zyzz_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.y = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zyzw(stdmath_float4 v) { return {v.z,v.y,v.z,v.w}; }
inline static stdmath_float4 stdmath_float4_zyzw_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.y = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zywx(stdmath_float4 v) { return {v.z,v.y,v.w,v.x}; }
inline static stdmath_float4 stdmath_float4_zywx_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.y = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zywy(stdmath_float4 v) { return {v.z,v.y,v.w,v.y}; }
inline static stdmath_float4 stdmath_float4_zywy_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.y = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zywz(stdmath_float4 v) { return {v.z,v.y,v.w,v.z}; }
inline static stdmath_float4 stdmath_float4_zywz_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.y = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zyww(stdmath_float4 v) { return {v.z,v.y,v.w,v.w}; }
inline static stdmath_float4 stdmath_float4_zyww_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.y = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zzxx(stdmath_float4 v) { return {v.z,v.z,v.x,v.x}; }
inline static stdmath_float4 stdmath_float4_zzxx_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.z = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zzxy(stdmath_float4 v) { return {v.z,v.z,v.x,v.y}; }
inline static stdmath_float4 stdmath_float4_zzxy_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.z = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zzxz(stdmath_float4 v) { return {v.z,v.z,v.x,v.z}; }
inline static stdmath_float4 stdmath_float4_zzxz_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.z = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zzxw(stdmath_float4 v) { return {v.z,v.z,v.x,v.w}; }
inline static stdmath_float4 stdmath_float4_zzxw_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.z = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zzyx(stdmath_float4 v) { return {v.z,v.z,v.y,v.x}; }
inline static stdmath_float4 stdmath_float4_zzyx_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.z = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zzyy(stdmath_float4 v) { return {v.z,v.z,v.y,v.y}; }
inline static stdmath_float4 stdmath_float4_zzyy_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.z = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zzyz(stdmath_float4 v) { return {v.z,v.z,v.y,v.z}; }
inline static stdmath_float4 stdmath_float4_zzyz_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.z = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zzyw(stdmath_float4 v) { return {v.z,v.z,v.y,v.w}; }
inline static stdmath_float4 stdmath_float4_zzyw_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.z = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zzzx(stdmath_float4 v) { return {v.z,v.z,v.z,v.x}; }
inline static stdmath_float4 stdmath_float4_zzzx_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.z = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zzzy(stdmath_float4 v) { return {v.z,v.z,v.z,v.y}; }
inline static stdmath_float4 stdmath_float4_zzzy_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.z = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zzzz(stdmath_float4 v) { return {v.z,v.z,v.z,v.z}; }
inline static stdmath_float4 stdmath_float4_zzzz_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.z = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zzzw(stdmath_float4 v) { return {v.z,v.z,v.z,v.w}; }
inline static stdmath_float4 stdmath_float4_zzzw_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.z = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zzwx(stdmath_float4 v) { return {v.z,v.z,v.w,v.x}; }
inline static stdmath_float4 stdmath_float4_zzwx_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.z = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zzwy(stdmath_float4 v) { return {v.z,v.z,v.w,v.y}; }
inline static stdmath_float4 stdmath_float4_zzwy_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.z = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zzwz(stdmath_float4 v) { return {v.z,v.z,v.w,v.z}; }
inline static stdmath_float4 stdmath_float4_zzwz_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.z = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zzww(stdmath_float4 v) { return {v.z,v.z,v.w,v.w}; }
inline static stdmath_float4 stdmath_float4_zzww_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.z = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zwxx(stdmath_float4 v) { return {v.z,v.w,v.x,v.x}; }
inline static stdmath_float4 stdmath_float4_zwxx_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.w = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zwxy(stdmath_float4 v) { return {v.z,v.w,v.x,v.y}; }
inline static stdmath_float4 stdmath_float4_zwxy_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.w = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zwxz(stdmath_float4 v) { return {v.z,v.w,v.x,v.z}; }
inline static stdmath_float4 stdmath_float4_zwxz_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.w = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zwxw(stdmath_float4 v) { return {v.z,v.w,v.x,v.w}; }
inline static stdmath_float4 stdmath_float4_zwxw_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.w = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zwyx(stdmath_float4 v) { return {v.z,v.w,v.y,v.x}; }
inline static stdmath_float4 stdmath_float4_zwyx_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.w = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zwyy(stdmath_float4 v) { return {v.z,v.w,v.y,v.y}; }
inline static stdmath_float4 stdmath_float4_zwyy_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.w = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zwyz(stdmath_float4 v) { return {v.z,v.w,v.y,v.z}; }
inline static stdmath_float4 stdmath_float4_zwyz_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.w = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zwyw(stdmath_float4 v) { return {v.z,v.w,v.y,v.w}; }
inline static stdmath_float4 stdmath_float4_zwyw_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.w = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zwzx(stdmath_float4 v) { return {v.z,v.w,v.z,v.x}; }
inline static stdmath_float4 stdmath_float4_zwzx_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.w = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zwzy(stdmath_float4 v) { return {v.z,v.w,v.z,v.y}; }
inline static stdmath_float4 stdmath_float4_zwzy_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.w = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zwzz(stdmath_float4 v) { return {v.z,v.w,v.z,v.z}; }
inline static stdmath_float4 stdmath_float4_zwzz_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.w = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zwzw(stdmath_float4 v) { return {v.z,v.w,v.z,v.w}; }
inline static stdmath_float4 stdmath_float4_zwzw_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.w = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zwwx(stdmath_float4 v) { return {v.z,v.w,v.w,v.x}; }
inline static stdmath_float4 stdmath_float4_zwwx_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.w = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zwwy(stdmath_float4 v) { return {v.z,v.w,v.w,v.y}; }
inline static stdmath_float4 stdmath_float4_zwwy_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.w = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zwwz(stdmath_float4 v) { return {v.z,v.w,v.w,v.z}; }
inline static stdmath_float4 stdmath_float4_zwwz_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.w = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_zwww(stdmath_float4 v) { return {v.z,v.w,v.w,v.w}; }
inline static stdmath_float4 stdmath_float4_zwww_value(stdmath_float4 v, stdmath_float4 value) { v.z = value.x; v.w = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wxxx(stdmath_float4 v) { return {v.w,v.x,v.x,v.x}; }
inline static stdmath_float4 stdmath_float4_wxxx_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.x = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wxxy(stdmath_float4 v) { return {v.w,v.x,v.x,v.y}; }
inline static stdmath_float4 stdmath_float4_wxxy_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.x = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wxxz(stdmath_float4 v) { return {v.w,v.x,v.x,v.z}; }
inline static stdmath_float4 stdmath_float4_wxxz_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.x = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wxxw(stdmath_float4 v) { return {v.w,v.x,v.x,v.w}; }
inline static stdmath_float4 stdmath_float4_wxxw_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.x = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wxyx(stdmath_float4 v) { return {v.w,v.x,v.y,v.x}; }
inline static stdmath_float4 stdmath_float4_wxyx_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.x = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wxyy(stdmath_float4 v) { return {v.w,v.x,v.y,v.y}; }
inline static stdmath_float4 stdmath_float4_wxyy_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.x = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wxyz(stdmath_float4 v) { return {v.w,v.x,v.y,v.z}; }
inline static stdmath_float4 stdmath_float4_wxyz_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.x = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wxyw(stdmath_float4 v) { return {v.w,v.x,v.y,v.w}; }
inline static stdmath_float4 stdmath_float4_wxyw_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.x = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wxzx(stdmath_float4 v) { return {v.w,v.x,v.z,v.x}; }
inline static stdmath_float4 stdmath_float4_wxzx_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.x = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wxzy(stdmath_float4 v) { return {v.w,v.x,v.z,v.y}; }
inline static stdmath_float4 stdmath_float4_wxzy_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.x = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wxzz(stdmath_float4 v) { return {v.w,v.x,v.z,v.z}; }
inline static stdmath_float4 stdmath_float4_wxzz_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.x = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wxzw(stdmath_float4 v) { return {v.w,v.x,v.z,v.w}; }
inline static stdmath_float4 stdmath_float4_wxzw_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.x = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wxwx(stdmath_float4 v) { return {v.w,v.x,v.w,v.x}; }
inline static stdmath_float4 stdmath_float4_wxwx_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.x = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wxwy(stdmath_float4 v) { return {v.w,v.x,v.w,v.y}; }
inline static stdmath_float4 stdmath_float4_wxwy_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.x = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wxwz(stdmath_float4 v) { return {v.w,v.x,v.w,v.z}; }
inline static stdmath_float4 stdmath_float4_wxwz_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.x = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wxww(stdmath_float4 v) { return {v.w,v.x,v.w,v.w}; }
inline static stdmath_float4 stdmath_float4_wxww_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.x = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wyxx(stdmath_float4 v) { return {v.w,v.y,v.x,v.x}; }
inline static stdmath_float4 stdmath_float4_wyxx_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.y = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wyxy(stdmath_float4 v) { return {v.w,v.y,v.x,v.y}; }
inline static stdmath_float4 stdmath_float4_wyxy_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.y = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wyxz(stdmath_float4 v) { return {v.w,v.y,v.x,v.z}; }
inline static stdmath_float4 stdmath_float4_wyxz_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.y = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wyxw(stdmath_float4 v) { return {v.w,v.y,v.x,v.w}; }
inline static stdmath_float4 stdmath_float4_wyxw_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.y = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wyyx(stdmath_float4 v) { return {v.w,v.y,v.y,v.x}; }
inline static stdmath_float4 stdmath_float4_wyyx_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.y = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wyyy(stdmath_float4 v) { return {v.w,v.y,v.y,v.y}; }
inline static stdmath_float4 stdmath_float4_wyyy_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.y = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wyyz(stdmath_float4 v) { return {v.w,v.y,v.y,v.z}; }
inline static stdmath_float4 stdmath_float4_wyyz_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.y = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wyyw(stdmath_float4 v) { return {v.w,v.y,v.y,v.w}; }
inline static stdmath_float4 stdmath_float4_wyyw_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.y = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wyzx(stdmath_float4 v) { return {v.w,v.y,v.z,v.x}; }
inline static stdmath_float4 stdmath_float4_wyzx_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.y = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wyzy(stdmath_float4 v) { return {v.w,v.y,v.z,v.y}; }
inline static stdmath_float4 stdmath_float4_wyzy_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.y = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wyzz(stdmath_float4 v) { return {v.w,v.y,v.z,v.z}; }
inline static stdmath_float4 stdmath_float4_wyzz_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.y = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wyzw(stdmath_float4 v) { return {v.w,v.y,v.z,v.w}; }
inline static stdmath_float4 stdmath_float4_wyzw_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.y = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wywx(stdmath_float4 v) { return {v.w,v.y,v.w,v.x}; }
inline static stdmath_float4 stdmath_float4_wywx_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.y = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wywy(stdmath_float4 v) { return {v.w,v.y,v.w,v.y}; }
inline static stdmath_float4 stdmath_float4_wywy_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.y = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wywz(stdmath_float4 v) { return {v.w,v.y,v.w,v.z}; }
inline static stdmath_float4 stdmath_float4_wywz_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.y = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wyww(stdmath_float4 v) { return {v.w,v.y,v.w,v.w}; }
inline static stdmath_float4 stdmath_float4_wyww_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.y = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wzxx(stdmath_float4 v) { return {v.w,v.z,v.x,v.x}; }
inline static stdmath_float4 stdmath_float4_wzxx_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.z = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wzxy(stdmath_float4 v) { return {v.w,v.z,v.x,v.y}; }
inline static stdmath_float4 stdmath_float4_wzxy_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.z = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wzxz(stdmath_float4 v) { return {v.w,v.z,v.x,v.z}; }
inline static stdmath_float4 stdmath_float4_wzxz_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.z = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wzxw(stdmath_float4 v) { return {v.w,v.z,v.x,v.w}; }
inline static stdmath_float4 stdmath_float4_wzxw_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.z = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wzyx(stdmath_float4 v) { return {v.w,v.z,v.y,v.x}; }
inline static stdmath_float4 stdmath_float4_wzyx_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.z = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wzyy(stdmath_float4 v) { return {v.w,v.z,v.y,v.y}; }
inline static stdmath_float4 stdmath_float4_wzyy_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.z = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wzyz(stdmath_float4 v) { return {v.w,v.z,v.y,v.z}; }
inline static stdmath_float4 stdmath_float4_wzyz_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.z = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wzyw(stdmath_float4 v) { return {v.w,v.z,v.y,v.w}; }
inline static stdmath_float4 stdmath_float4_wzyw_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.z = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wzzx(stdmath_float4 v) { return {v.w,v.z,v.z,v.x}; }
inline static stdmath_float4 stdmath_float4_wzzx_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.z = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wzzy(stdmath_float4 v) { return {v.w,v.z,v.z,v.y}; }
inline static stdmath_float4 stdmath_float4_wzzy_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.z = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wzzz(stdmath_float4 v) { return {v.w,v.z,v.z,v.z}; }
inline static stdmath_float4 stdmath_float4_wzzz_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.z = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wzzw(stdmath_float4 v) { return {v.w,v.z,v.z,v.w}; }
inline static stdmath_float4 stdmath_float4_wzzw_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.z = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wzwx(stdmath_float4 v) { return {v.w,v.z,v.w,v.x}; }
inline static stdmath_float4 stdmath_float4_wzwx_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.z = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wzwy(stdmath_float4 v) { return {v.w,v.z,v.w,v.y}; }
inline static stdmath_float4 stdmath_float4_wzwy_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.z = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wzwz(stdmath_float4 v) { return {v.w,v.z,v.w,v.z}; }
inline static stdmath_float4 stdmath_float4_wzwz_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.z = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wzww(stdmath_float4 v) { return {v.w,v.z,v.w,v.w}; }
inline static stdmath_float4 stdmath_float4_wzww_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.z = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wwxx(stdmath_float4 v) { return {v.w,v.w,v.x,v.x}; }
inline static stdmath_float4 stdmath_float4_wwxx_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.w = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wwxy(stdmath_float4 v) { return {v.w,v.w,v.x,v.y}; }
inline static stdmath_float4 stdmath_float4_wwxy_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.w = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wwxz(stdmath_float4 v) { return {v.w,v.w,v.x,v.z}; }
inline static stdmath_float4 stdmath_float4_wwxz_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.w = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wwxw(stdmath_float4 v) { return {v.w,v.w,v.x,v.w}; }
inline static stdmath_float4 stdmath_float4_wwxw_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.w = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wwyx(stdmath_float4 v) { return {v.w,v.w,v.y,v.x}; }
inline static stdmath_float4 stdmath_float4_wwyx_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.w = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wwyy(stdmath_float4 v) { return {v.w,v.w,v.y,v.y}; }
inline static stdmath_float4 stdmath_float4_wwyy_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.w = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wwyz(stdmath_float4 v) { return {v.w,v.w,v.y,v.z}; }
inline static stdmath_float4 stdmath_float4_wwyz_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.w = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wwyw(stdmath_float4 v) { return {v.w,v.w,v.y,v.w}; }
inline static stdmath_float4 stdmath_float4_wwyw_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.w = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wwzx(stdmath_float4 v) { return {v.w,v.w,v.z,v.x}; }
inline static stdmath_float4 stdmath_float4_wwzx_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.w = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wwzy(stdmath_float4 v) { return {v.w,v.w,v.z,v.y}; }
inline static stdmath_float4 stdmath_float4_wwzy_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.w = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wwzz(stdmath_float4 v) { return {v.w,v.w,v.z,v.z}; }
inline static stdmath_float4 stdmath_float4_wwzz_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.w = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wwzw(stdmath_float4 v) { return {v.w,v.w,v.z,v.w}; }
inline static stdmath_float4 stdmath_float4_wwzw_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.w = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wwwx(stdmath_float4 v) { return {v.w,v.w,v.w,v.x}; }
inline static stdmath_float4 stdmath_float4_wwwx_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.w = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wwwy(stdmath_float4 v) { return {v.w,v.w,v.w,v.y}; }
inline static stdmath_float4 stdmath_float4_wwwy_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.w = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wwwz(stdmath_float4 v) { return {v.w,v.w,v.w,v.z}; }
inline static stdmath_float4 stdmath_float4_wwwz_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.w = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_float4 stdmath_float4_wwww(stdmath_float4 v) { return {v.w,v.w,v.w,v.w}; }
inline static stdmath_float4 stdmath_float4_wwww_value(stdmath_float4 v, stdmath_float4 value) { v.w = value.x; v.w = value.y; v.w = value.z; v.w = value.w; return v; }


#ifdef STDMATH_IMPLEMENTATION
#ifndef __cplusplus
#error "The stdmath implementations require a C++ compiler"
#endif

import stdmath.slang;

stdmath::float4 c(stdmath_float4 c) {
	return (stdmath::float4&)c;
}
stdmath_float4 c(stdmath::float4 c) {
	return (stdmath_float4&)c;
}

stdmath_float4 stdmath_float4_broadcast(float all) {
	return c(stdmath::float4((stdmath::float4::underlying_type)all));
}

stdmath_float4 stdmath_float4_add(stdmath_float4 a, stdmath_float4 b) {
	return c(c(a) + c(b));
}
stdmath_float4 stdmath_float4_subtract(stdmath_float4 a, stdmath_float4 b) {
	return c(c(a) - c(b));
}
stdmath_float4 stdmath_float4_negate(stdmath_float4 v) {
	return c(stdmath::float4(-(stdmath::vector<float, 4>)c(v)));
}
stdmath_float4 stdmath_float4_multiply(stdmath_float4 a, stdmath_float4 b) {
	return c(c(a) * c(b));
}
stdmath_float4 stdmath_float4_divide(stdmath_float4 a, stdmath_float4 b) {
	return c(c(a) / c(b));
}
stdmath_float4 stdmath_float4_scale(stdmath_float4 v, float s) {
	return c(c(v) * (stdmath::float4::underlying_type)s);
}

#if false
stdmath_float4 stdmath_float4_modulus(stdmath_float4 a, stdmath_float4 b) {
	return c(c(a) % c(b));
}
stdmath_float4 stdmath_float4_logical_not(stdmath_float4 v) {
	return c(!c(v));
}
stdmath_float4 stdmath_float4_bitwise_not(stdmath_float4 v) {
	return c(~c(v));
}
stdmath_float4 stdmath_float4_logical_and(stdmath_float4 a, stdmath_float4 b) {
	return c(c(a) && c(b));
}
stdmath_float4 stdmath_float4_bitwise_and(stdmath_float4 a, stdmath_float4 b) {
	return c(c(a) & c(b));
}
stdmath_float4 stdmath_float4_logical_or(stdmath_float4 a, stdmath_float4 b) {
	return c(c(a) || c(b));
}
stdmath_float4 stdmath_float4_bitwise_or(stdmath_float4 a, stdmath_float4 b) {
	return c(c(a) | c(b));
}
stdmath_float4 stdmath_float4_bitwise_xor(stdmath_float4 a, stdmath_float4 b) {
	return c(c(a) ^ c(b));
}
stdmath_float4 stdmath_float4_shift_left(stdmath_float4 a, stdmath_float4 b) {
	return c(c(a) << c(b));
}
stdmath_float4 stdmath_float4_shift_right(stdmath_float4 a, stdmath_float4 b) {
	return c(c(a) >> c(b));
}
#endif

stdmath_bool4 stdmath_float4_equal_to(stdmath_float4 a, stdmath_float4 b) {
	return c(c(a) == c(b));
}
stdmath_bool4 stdmath_float4_not_equal_to(stdmath_float4 a, stdmath_float4 b) {
	return c(c(a) != c(b));
}
stdmath_bool4 stdmath_float4_less_than(stdmath_float4 a, stdmath_float4 b) {
	return c(c(a) < c(b));
}
stdmath_bool4 stdmath_float4_less_than_or_equal_to(stdmath_float4 a, stdmath_float4 b) {
	return c(c(a) <= c(b));
}
stdmath_bool4 stdmath_float4_greater_than(stdmath_float4 a, stdmath_float4 b) {
	return c(c(a) > c(b));
}
stdmath_bool4 stdmath_float4_greater_than_or_equal_to(stdmath_float4 a, stdmath_float4 b) {
	return c(c(a) >= c(b));
}

float stdmath_float4_length_squared(stdmath_float4 v)  {
	return (float)c(v).length_squared();
}
float stdmath_float4_length(stdmath_float4 v)  {
	return (float)c(v).length();
}
float stdmath_float4_dot(stdmath_float4 a, stdmath_float4 b)  {
	return (float)dot(c(a), c(b));
}
float stdmath_float4_min_element(stdmath_float4 v)  {
	return (float)c(v).min_element();
}
float stdmath_float4_max_element(stdmath_float4 v)  {
	return (float)c(v).max_element();
}

stdmath_float4 stdmath_float4_elementwise_transform(stdmath_float4 v, float(*func)(float)) {
	return c(c(v).elementwise_transform(func));
}
// float stdmath_float4_reduce_elements(stdmath_float4 v, float initial_value, float(*reducer)(stdmath_float4, stdmath_float4)) {
// 	return c(v).reduce_elements(initial_value, reducer);
// }

#if 4 == 3
stdmath_float4 stdmath_float4_cross(stdmath_float4 a, stdmath_float4 b) {
	return c(cross(c(a), c(b)));
}
#endif

stdmath_float4 stdmath_float4_min(stdmath_float4 a, stdmath_float4 b) {
	return c(min(c(a), c(b)));
}
stdmath_float4 stdmath_float4_max(stdmath_float4 a, stdmath_float4 b) {
	return c(max(c(a), c(b)));
}
stdmath_float4 stdmath_float4_normalize(stdmath_float4 v) {
	return c(normalize(c(v)));
}
stdmath_float4 stdmath_float4_lerp(stdmath_float4 a, stdmath_float4 b, float t) {
	return c(lerp(c(a), c(b), t));
}
stdmath_float4 stdmath_float4_clamp(stdmath_float4 a, stdmath_float4 min, stdmath_float4 max) {
	return c(clamp(c(a), c(min), c(max)));
}
stdmath_float4 stdmath_float4_reflect(stdmath_float4 a, stdmath_float4 b) {
	return c(reflect(c(a), c(b)));
}
stdmath_bool4 stdmath_float4_approximately_equal(stdmath_float4 a, stdmath_float4 b) {
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

#endif // __STDMATH_float4_H__