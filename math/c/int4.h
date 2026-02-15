#ifndef __STDMATH_int32_t4_H__
#define __STDMATH_int32_t4_H__

#include <stdint.h>
#if !false
#include "bool4.h"
#endif
#include "int3.h"
#include "int2.h"
#include "int1.h"
#include "util.h"

union stdmath_int4 {
	struct {
		int32_t x, y, z, w;
	};
	struct {
		int32_t r, g, b, a;
	};
	struct {
		int32_t h, s, v;
	};
	int32_t data[4];
};

stdmath_int4 stdmath_int4_broadcast(int32_t all);

stdmath_int4 stdmath_int4_add(stdmath_int4 a, stdmath_int4 b);
stdmath_int4 stdmath_int4_subtract(stdmath_int4 a, stdmath_int4 b);
stdmath_int4 stdmath_int4_negate(stdmath_int4 v);
stdmath_int4 stdmath_int4_multiply(stdmath_int4 a, stdmath_int4 b);
stdmath_int4 stdmath_int4_divide(stdmath_int4 a, stdmath_int4 b);
stdmath_int4 stdmath_int4_scale(stdmath_int3 v, int32_t s);

#if false
stdmath_int4 stdmath_int4_modulus(stdmath_int4 a, stdmath_int4 b);
stdmath_int4 stdmath_int4_logical_not(stdmath_int4 v);
stdmath_int4 stdmath_int4_bitwise_not(stdmath_int4 v);
stdmath_int4 stdmath_int4_logical_and(stdmath_int4 a, stdmath_int4 b);
stdmath_int4 stdmath_int4_bitwise_and(stdmath_int4 a, stdmath_int4 b);
stdmath_int4 stdmath_int4_logical_or(stdmath_int4 a, stdmath_int4 b);
stdmath_int4 stdmath_int4_bitwise_or(stdmath_int4 a, stdmath_int4 b);
stdmath_int4 stdmath_int4_bitwise_xor(stdmath_int4 a, stdmath_int4 b);
stdmath_int4 stdmath_int4_shift_left(stdmath_int4 a, stdmath_int4 b);
stdmath_int4 stdmath_int4_shift_right(stdmath_int4 a, stdmath_int4 b);
#endif

stdmath_bool4 stdmath_int4_equal_to(stdmath_int4 a, stdmath_int4 b);
stdmath_bool4 stdmath_int4_not_equal_to(stdmath_int4 a, stdmath_int4 b);
stdmath_bool4 stdmath_int4_less_than(stdmath_int4 a, stdmath_int4 b);
stdmath_bool4 stdmath_int4_less_than_or_equal_to(stdmath_int4 a, stdmath_int4 b);
stdmath_bool4 stdmath_int4_greater_than(stdmath_int4 a, stdmath_int4 b);
stdmath_bool4 stdmath_int4_greater_than_or_equal_to(stdmath_int4 a, stdmath_int4 b);

int32_t stdmath_int4_length_squared(stdmath_int4 v);
int32_t stdmath_int4_length(stdmath_int4 v);
int32_t stdmath_int4_dot(stdmath_int4 v);
int32_t stdmath_int4_min_element(stdmath_int4 v);
int32_t stdmath_int4_max_element(stdmath_int4 v);

stdmath_int4 stdmath_int4_elementwise_transform(stdmath_int4 v, int32_t(*func)(int32_t));
// int32_t stdmath_int4_reduce_elements(stdmath_int4 v, int32_t initial_value, int32_t(*reducer)(stdmath_int4, stdmath_int4));

stdmath_int4 stdmath_int4_min(stdmath_int4 a, stdmath_int4 b);
stdmath_int4 stdmath_int4_max(stdmath_int4 a, stdmath_int4 b);
stdmath_int4 stdmath_int4_normalize(stdmath_int4 v);
stdmath_int4 stdmath_int4_lerp(stdmath_int4 a, stdmath_int4 b, float t);
stdmath_int4 stdmath_int4_clamp(stdmath_int4 a, stdmath_int4 min, stdmath_int4 max);
stdmath_int4 stdmath_int4_reflect(stdmath_int4 a, stdmath_int4 b);
stdmath_bool4 stdmath_int4_approximately_equal(stdmath_int4 a, stdmath_int4 b);

#if false
bool stdmath_bool4_all_of(stdmath_bool4 v);
bool stdmath_bool4_any_of(stdmath_bool4 v);
bool stdmath_bool4_none_of(stdmath_bool4 v);
bool stdmath_bool4_some_of(stdmath_bool4 v);
#endif

inline static stdmath_int1 stdmath_int4_x(stdmath_int4 v) { return {v.x}; }
inline static stdmath_int4 stdmath_int4_x_value(stdmath_int4 v, stdmath_int1 value) { v.x = value.x; return v; }
inline static stdmath_int1 stdmath_int4_y(stdmath_int4 v) { return {v.y}; }
inline static stdmath_int4 stdmath_int4_y_value(stdmath_int4 v, stdmath_int1 value) { v.y = value.x; return v; }
inline static stdmath_int1 stdmath_int4_z(stdmath_int4 v) { return {v.z}; }
inline static stdmath_int4 stdmath_int4_z_value(stdmath_int4 v, stdmath_int1 value) { v.z = value.x; return v; }
inline static stdmath_int1 stdmath_int4_w(stdmath_int4 v) { return {v.w}; }
inline static stdmath_int4 stdmath_int4_w_value(stdmath_int4 v, stdmath_int1 value) { v.w = value.x; return v; }
inline static stdmath_int2 stdmath_int4_xx(stdmath_int4 v) { return {v.x,v.x}; }
inline static stdmath_int4 stdmath_int4_xx_value(stdmath_int4 v, stdmath_int2 value) { v.x = value.x; v.x = value.y; return v; }
inline static stdmath_int2 stdmath_int4_xy(stdmath_int4 v) { return {v.x,v.y}; }
inline static stdmath_int4 stdmath_int4_xy_value(stdmath_int4 v, stdmath_int2 value) { v.x = value.x; v.y = value.y; return v; }
inline static stdmath_int2 stdmath_int4_xz(stdmath_int4 v) { return {v.x,v.z}; }
inline static stdmath_int4 stdmath_int4_xz_value(stdmath_int4 v, stdmath_int2 value) { v.x = value.x; v.z = value.y; return v; }
inline static stdmath_int2 stdmath_int4_xw(stdmath_int4 v) { return {v.x,v.w}; }
inline static stdmath_int4 stdmath_int4_xw_value(stdmath_int4 v, stdmath_int2 value) { v.x = value.x; v.w = value.y; return v; }
inline static stdmath_int2 stdmath_int4_yx(stdmath_int4 v) { return {v.y,v.x}; }
inline static stdmath_int4 stdmath_int4_yx_value(stdmath_int4 v, stdmath_int2 value) { v.y = value.x; v.x = value.y; return v; }
inline static stdmath_int2 stdmath_int4_yy(stdmath_int4 v) { return {v.y,v.y}; }
inline static stdmath_int4 stdmath_int4_yy_value(stdmath_int4 v, stdmath_int2 value) { v.y = value.x; v.y = value.y; return v; }
inline static stdmath_int2 stdmath_int4_yz(stdmath_int4 v) { return {v.y,v.z}; }
inline static stdmath_int4 stdmath_int4_yz_value(stdmath_int4 v, stdmath_int2 value) { v.y = value.x; v.z = value.y; return v; }
inline static stdmath_int2 stdmath_int4_yw(stdmath_int4 v) { return {v.y,v.w}; }
inline static stdmath_int4 stdmath_int4_yw_value(stdmath_int4 v, stdmath_int2 value) { v.y = value.x; v.w = value.y; return v; }
inline static stdmath_int2 stdmath_int4_zx(stdmath_int4 v) { return {v.z,v.x}; }
inline static stdmath_int4 stdmath_int4_zx_value(stdmath_int4 v, stdmath_int2 value) { v.z = value.x; v.x = value.y; return v; }
inline static stdmath_int2 stdmath_int4_zy(stdmath_int4 v) { return {v.z,v.y}; }
inline static stdmath_int4 stdmath_int4_zy_value(stdmath_int4 v, stdmath_int2 value) { v.z = value.x; v.y = value.y; return v; }
inline static stdmath_int2 stdmath_int4_zz(stdmath_int4 v) { return {v.z,v.z}; }
inline static stdmath_int4 stdmath_int4_zz_value(stdmath_int4 v, stdmath_int2 value) { v.z = value.x; v.z = value.y; return v; }
inline static stdmath_int2 stdmath_int4_zw(stdmath_int4 v) { return {v.z,v.w}; }
inline static stdmath_int4 stdmath_int4_zw_value(stdmath_int4 v, stdmath_int2 value) { v.z = value.x; v.w = value.y; return v; }
inline static stdmath_int2 stdmath_int4_wx(stdmath_int4 v) { return {v.w,v.x}; }
inline static stdmath_int4 stdmath_int4_wx_value(stdmath_int4 v, stdmath_int2 value) { v.w = value.x; v.x = value.y; return v; }
inline static stdmath_int2 stdmath_int4_wy(stdmath_int4 v) { return {v.w,v.y}; }
inline static stdmath_int4 stdmath_int4_wy_value(stdmath_int4 v, stdmath_int2 value) { v.w = value.x; v.y = value.y; return v; }
inline static stdmath_int2 stdmath_int4_wz(stdmath_int4 v) { return {v.w,v.z}; }
inline static stdmath_int4 stdmath_int4_wz_value(stdmath_int4 v, stdmath_int2 value) { v.w = value.x; v.z = value.y; return v; }
inline static stdmath_int2 stdmath_int4_ww(stdmath_int4 v) { return {v.w,v.w}; }
inline static stdmath_int4 stdmath_int4_ww_value(stdmath_int4 v, stdmath_int2 value) { v.w = value.x; v.w = value.y; return v; }
inline static stdmath_int3 stdmath_int4_xxx(stdmath_int4 v) { return {v.x,v.x,v.x}; }
inline static stdmath_int4 stdmath_int4_xxx_value(stdmath_int4 v, stdmath_int3 value) { v.x = value.x; v.x = value.y; v.x = value.z; return v; }
inline static stdmath_int3 stdmath_int4_xxy(stdmath_int4 v) { return {v.x,v.x,v.y}; }
inline static stdmath_int4 stdmath_int4_xxy_value(stdmath_int4 v, stdmath_int3 value) { v.x = value.x; v.x = value.y; v.y = value.z; return v; }
inline static stdmath_int3 stdmath_int4_xxz(stdmath_int4 v) { return {v.x,v.x,v.z}; }
inline static stdmath_int4 stdmath_int4_xxz_value(stdmath_int4 v, stdmath_int3 value) { v.x = value.x; v.x = value.y; v.z = value.z; return v; }
inline static stdmath_int3 stdmath_int4_xxw(stdmath_int4 v) { return {v.x,v.x,v.w}; }
inline static stdmath_int4 stdmath_int4_xxw_value(stdmath_int4 v, stdmath_int3 value) { v.x = value.x; v.x = value.y; v.w = value.z; return v; }
inline static stdmath_int3 stdmath_int4_xyx(stdmath_int4 v) { return {v.x,v.y,v.x}; }
inline static stdmath_int4 stdmath_int4_xyx_value(stdmath_int4 v, stdmath_int3 value) { v.x = value.x; v.y = value.y; v.x = value.z; return v; }
inline static stdmath_int3 stdmath_int4_xyy(stdmath_int4 v) { return {v.x,v.y,v.y}; }
inline static stdmath_int4 stdmath_int4_xyy_value(stdmath_int4 v, stdmath_int3 value) { v.x = value.x; v.y = value.y; v.y = value.z; return v; }
inline static stdmath_int3 stdmath_int4_xyz(stdmath_int4 v) { return {v.x,v.y,v.z}; }
inline static stdmath_int4 stdmath_int4_xyz_value(stdmath_int4 v, stdmath_int3 value) { v.x = value.x; v.y = value.y; v.z = value.z; return v; }
inline static stdmath_int3 stdmath_int4_xyw(stdmath_int4 v) { return {v.x,v.y,v.w}; }
inline static stdmath_int4 stdmath_int4_xyw_value(stdmath_int4 v, stdmath_int3 value) { v.x = value.x; v.y = value.y; v.w = value.z; return v; }
inline static stdmath_int3 stdmath_int4_xzx(stdmath_int4 v) { return {v.x,v.z,v.x}; }
inline static stdmath_int4 stdmath_int4_xzx_value(stdmath_int4 v, stdmath_int3 value) { v.x = value.x; v.z = value.y; v.x = value.z; return v; }
inline static stdmath_int3 stdmath_int4_xzy(stdmath_int4 v) { return {v.x,v.z,v.y}; }
inline static stdmath_int4 stdmath_int4_xzy_value(stdmath_int4 v, stdmath_int3 value) { v.x = value.x; v.z = value.y; v.y = value.z; return v; }
inline static stdmath_int3 stdmath_int4_xzz(stdmath_int4 v) { return {v.x,v.z,v.z}; }
inline static stdmath_int4 stdmath_int4_xzz_value(stdmath_int4 v, stdmath_int3 value) { v.x = value.x; v.z = value.y; v.z = value.z; return v; }
inline static stdmath_int3 stdmath_int4_xzw(stdmath_int4 v) { return {v.x,v.z,v.w}; }
inline static stdmath_int4 stdmath_int4_xzw_value(stdmath_int4 v, stdmath_int3 value) { v.x = value.x; v.z = value.y; v.w = value.z; return v; }
inline static stdmath_int3 stdmath_int4_xwx(stdmath_int4 v) { return {v.x,v.w,v.x}; }
inline static stdmath_int4 stdmath_int4_xwx_value(stdmath_int4 v, stdmath_int3 value) { v.x = value.x; v.w = value.y; v.x = value.z; return v; }
inline static stdmath_int3 stdmath_int4_xwy(stdmath_int4 v) { return {v.x,v.w,v.y}; }
inline static stdmath_int4 stdmath_int4_xwy_value(stdmath_int4 v, stdmath_int3 value) { v.x = value.x; v.w = value.y; v.y = value.z; return v; }
inline static stdmath_int3 stdmath_int4_xwz(stdmath_int4 v) { return {v.x,v.w,v.z}; }
inline static stdmath_int4 stdmath_int4_xwz_value(stdmath_int4 v, stdmath_int3 value) { v.x = value.x; v.w = value.y; v.z = value.z; return v; }
inline static stdmath_int3 stdmath_int4_xww(stdmath_int4 v) { return {v.x,v.w,v.w}; }
inline static stdmath_int4 stdmath_int4_xww_value(stdmath_int4 v, stdmath_int3 value) { v.x = value.x; v.w = value.y; v.w = value.z; return v; }
inline static stdmath_int3 stdmath_int4_yxx(stdmath_int4 v) { return {v.y,v.x,v.x}; }
inline static stdmath_int4 stdmath_int4_yxx_value(stdmath_int4 v, stdmath_int3 value) { v.y = value.x; v.x = value.y; v.x = value.z; return v; }
inline static stdmath_int3 stdmath_int4_yxy(stdmath_int4 v) { return {v.y,v.x,v.y}; }
inline static stdmath_int4 stdmath_int4_yxy_value(stdmath_int4 v, stdmath_int3 value) { v.y = value.x; v.x = value.y; v.y = value.z; return v; }
inline static stdmath_int3 stdmath_int4_yxz(stdmath_int4 v) { return {v.y,v.x,v.z}; }
inline static stdmath_int4 stdmath_int4_yxz_value(stdmath_int4 v, stdmath_int3 value) { v.y = value.x; v.x = value.y; v.z = value.z; return v; }
inline static stdmath_int3 stdmath_int4_yxw(stdmath_int4 v) { return {v.y,v.x,v.w}; }
inline static stdmath_int4 stdmath_int4_yxw_value(stdmath_int4 v, stdmath_int3 value) { v.y = value.x; v.x = value.y; v.w = value.z; return v; }
inline static stdmath_int3 stdmath_int4_yyx(stdmath_int4 v) { return {v.y,v.y,v.x}; }
inline static stdmath_int4 stdmath_int4_yyx_value(stdmath_int4 v, stdmath_int3 value) { v.y = value.x; v.y = value.y; v.x = value.z; return v; }
inline static stdmath_int3 stdmath_int4_yyy(stdmath_int4 v) { return {v.y,v.y,v.y}; }
inline static stdmath_int4 stdmath_int4_yyy_value(stdmath_int4 v, stdmath_int3 value) { v.y = value.x; v.y = value.y; v.y = value.z; return v; }
inline static stdmath_int3 stdmath_int4_yyz(stdmath_int4 v) { return {v.y,v.y,v.z}; }
inline static stdmath_int4 stdmath_int4_yyz_value(stdmath_int4 v, stdmath_int3 value) { v.y = value.x; v.y = value.y; v.z = value.z; return v; }
inline static stdmath_int3 stdmath_int4_yyw(stdmath_int4 v) { return {v.y,v.y,v.w}; }
inline static stdmath_int4 stdmath_int4_yyw_value(stdmath_int4 v, stdmath_int3 value) { v.y = value.x; v.y = value.y; v.w = value.z; return v; }
inline static stdmath_int3 stdmath_int4_yzx(stdmath_int4 v) { return {v.y,v.z,v.x}; }
inline static stdmath_int4 stdmath_int4_yzx_value(stdmath_int4 v, stdmath_int3 value) { v.y = value.x; v.z = value.y; v.x = value.z; return v; }
inline static stdmath_int3 stdmath_int4_yzy(stdmath_int4 v) { return {v.y,v.z,v.y}; }
inline static stdmath_int4 stdmath_int4_yzy_value(stdmath_int4 v, stdmath_int3 value) { v.y = value.x; v.z = value.y; v.y = value.z; return v; }
inline static stdmath_int3 stdmath_int4_yzz(stdmath_int4 v) { return {v.y,v.z,v.z}; }
inline static stdmath_int4 stdmath_int4_yzz_value(stdmath_int4 v, stdmath_int3 value) { v.y = value.x; v.z = value.y; v.z = value.z; return v; }
inline static stdmath_int3 stdmath_int4_yzw(stdmath_int4 v) { return {v.y,v.z,v.w}; }
inline static stdmath_int4 stdmath_int4_yzw_value(stdmath_int4 v, stdmath_int3 value) { v.y = value.x; v.z = value.y; v.w = value.z; return v; }
inline static stdmath_int3 stdmath_int4_ywx(stdmath_int4 v) { return {v.y,v.w,v.x}; }
inline static stdmath_int4 stdmath_int4_ywx_value(stdmath_int4 v, stdmath_int3 value) { v.y = value.x; v.w = value.y; v.x = value.z; return v; }
inline static stdmath_int3 stdmath_int4_ywy(stdmath_int4 v) { return {v.y,v.w,v.y}; }
inline static stdmath_int4 stdmath_int4_ywy_value(stdmath_int4 v, stdmath_int3 value) { v.y = value.x; v.w = value.y; v.y = value.z; return v; }
inline static stdmath_int3 stdmath_int4_ywz(stdmath_int4 v) { return {v.y,v.w,v.z}; }
inline static stdmath_int4 stdmath_int4_ywz_value(stdmath_int4 v, stdmath_int3 value) { v.y = value.x; v.w = value.y; v.z = value.z; return v; }
inline static stdmath_int3 stdmath_int4_yww(stdmath_int4 v) { return {v.y,v.w,v.w}; }
inline static stdmath_int4 stdmath_int4_yww_value(stdmath_int4 v, stdmath_int3 value) { v.y = value.x; v.w = value.y; v.w = value.z; return v; }
inline static stdmath_int3 stdmath_int4_zxx(stdmath_int4 v) { return {v.z,v.x,v.x}; }
inline static stdmath_int4 stdmath_int4_zxx_value(stdmath_int4 v, stdmath_int3 value) { v.z = value.x; v.x = value.y; v.x = value.z; return v; }
inline static stdmath_int3 stdmath_int4_zxy(stdmath_int4 v) { return {v.z,v.x,v.y}; }
inline static stdmath_int4 stdmath_int4_zxy_value(stdmath_int4 v, stdmath_int3 value) { v.z = value.x; v.x = value.y; v.y = value.z; return v; }
inline static stdmath_int3 stdmath_int4_zxz(stdmath_int4 v) { return {v.z,v.x,v.z}; }
inline static stdmath_int4 stdmath_int4_zxz_value(stdmath_int4 v, stdmath_int3 value) { v.z = value.x; v.x = value.y; v.z = value.z; return v; }
inline static stdmath_int3 stdmath_int4_zxw(stdmath_int4 v) { return {v.z,v.x,v.w}; }
inline static stdmath_int4 stdmath_int4_zxw_value(stdmath_int4 v, stdmath_int3 value) { v.z = value.x; v.x = value.y; v.w = value.z; return v; }
inline static stdmath_int3 stdmath_int4_zyx(stdmath_int4 v) { return {v.z,v.y,v.x}; }
inline static stdmath_int4 stdmath_int4_zyx_value(stdmath_int4 v, stdmath_int3 value) { v.z = value.x; v.y = value.y; v.x = value.z; return v; }
inline static stdmath_int3 stdmath_int4_zyy(stdmath_int4 v) { return {v.z,v.y,v.y}; }
inline static stdmath_int4 stdmath_int4_zyy_value(stdmath_int4 v, stdmath_int3 value) { v.z = value.x; v.y = value.y; v.y = value.z; return v; }
inline static stdmath_int3 stdmath_int4_zyz(stdmath_int4 v) { return {v.z,v.y,v.z}; }
inline static stdmath_int4 stdmath_int4_zyz_value(stdmath_int4 v, stdmath_int3 value) { v.z = value.x; v.y = value.y; v.z = value.z; return v; }
inline static stdmath_int3 stdmath_int4_zyw(stdmath_int4 v) { return {v.z,v.y,v.w}; }
inline static stdmath_int4 stdmath_int4_zyw_value(stdmath_int4 v, stdmath_int3 value) { v.z = value.x; v.y = value.y; v.w = value.z; return v; }
inline static stdmath_int3 stdmath_int4_zzx(stdmath_int4 v) { return {v.z,v.z,v.x}; }
inline static stdmath_int4 stdmath_int4_zzx_value(stdmath_int4 v, stdmath_int3 value) { v.z = value.x; v.z = value.y; v.x = value.z; return v; }
inline static stdmath_int3 stdmath_int4_zzy(stdmath_int4 v) { return {v.z,v.z,v.y}; }
inline static stdmath_int4 stdmath_int4_zzy_value(stdmath_int4 v, stdmath_int3 value) { v.z = value.x; v.z = value.y; v.y = value.z; return v; }
inline static stdmath_int3 stdmath_int4_zzz(stdmath_int4 v) { return {v.z,v.z,v.z}; }
inline static stdmath_int4 stdmath_int4_zzz_value(stdmath_int4 v, stdmath_int3 value) { v.z = value.x; v.z = value.y; v.z = value.z; return v; }
inline static stdmath_int3 stdmath_int4_zzw(stdmath_int4 v) { return {v.z,v.z,v.w}; }
inline static stdmath_int4 stdmath_int4_zzw_value(stdmath_int4 v, stdmath_int3 value) { v.z = value.x; v.z = value.y; v.w = value.z; return v; }
inline static stdmath_int3 stdmath_int4_zwx(stdmath_int4 v) { return {v.z,v.w,v.x}; }
inline static stdmath_int4 stdmath_int4_zwx_value(stdmath_int4 v, stdmath_int3 value) { v.z = value.x; v.w = value.y; v.x = value.z; return v; }
inline static stdmath_int3 stdmath_int4_zwy(stdmath_int4 v) { return {v.z,v.w,v.y}; }
inline static stdmath_int4 stdmath_int4_zwy_value(stdmath_int4 v, stdmath_int3 value) { v.z = value.x; v.w = value.y; v.y = value.z; return v; }
inline static stdmath_int3 stdmath_int4_zwz(stdmath_int4 v) { return {v.z,v.w,v.z}; }
inline static stdmath_int4 stdmath_int4_zwz_value(stdmath_int4 v, stdmath_int3 value) { v.z = value.x; v.w = value.y; v.z = value.z; return v; }
inline static stdmath_int3 stdmath_int4_zww(stdmath_int4 v) { return {v.z,v.w,v.w}; }
inline static stdmath_int4 stdmath_int4_zww_value(stdmath_int4 v, stdmath_int3 value) { v.z = value.x; v.w = value.y; v.w = value.z; return v; }
inline static stdmath_int3 stdmath_int4_wxx(stdmath_int4 v) { return {v.w,v.x,v.x}; }
inline static stdmath_int4 stdmath_int4_wxx_value(stdmath_int4 v, stdmath_int3 value) { v.w = value.x; v.x = value.y; v.x = value.z; return v; }
inline static stdmath_int3 stdmath_int4_wxy(stdmath_int4 v) { return {v.w,v.x,v.y}; }
inline static stdmath_int4 stdmath_int4_wxy_value(stdmath_int4 v, stdmath_int3 value) { v.w = value.x; v.x = value.y; v.y = value.z; return v; }
inline static stdmath_int3 stdmath_int4_wxz(stdmath_int4 v) { return {v.w,v.x,v.z}; }
inline static stdmath_int4 stdmath_int4_wxz_value(stdmath_int4 v, stdmath_int3 value) { v.w = value.x; v.x = value.y; v.z = value.z; return v; }
inline static stdmath_int3 stdmath_int4_wxw(stdmath_int4 v) { return {v.w,v.x,v.w}; }
inline static stdmath_int4 stdmath_int4_wxw_value(stdmath_int4 v, stdmath_int3 value) { v.w = value.x; v.x = value.y; v.w = value.z; return v; }
inline static stdmath_int3 stdmath_int4_wyx(stdmath_int4 v) { return {v.w,v.y,v.x}; }
inline static stdmath_int4 stdmath_int4_wyx_value(stdmath_int4 v, stdmath_int3 value) { v.w = value.x; v.y = value.y; v.x = value.z; return v; }
inline static stdmath_int3 stdmath_int4_wyy(stdmath_int4 v) { return {v.w,v.y,v.y}; }
inline static stdmath_int4 stdmath_int4_wyy_value(stdmath_int4 v, stdmath_int3 value) { v.w = value.x; v.y = value.y; v.y = value.z; return v; }
inline static stdmath_int3 stdmath_int4_wyz(stdmath_int4 v) { return {v.w,v.y,v.z}; }
inline static stdmath_int4 stdmath_int4_wyz_value(stdmath_int4 v, stdmath_int3 value) { v.w = value.x; v.y = value.y; v.z = value.z; return v; }
inline static stdmath_int3 stdmath_int4_wyw(stdmath_int4 v) { return {v.w,v.y,v.w}; }
inline static stdmath_int4 stdmath_int4_wyw_value(stdmath_int4 v, stdmath_int3 value) { v.w = value.x; v.y = value.y; v.w = value.z; return v; }
inline static stdmath_int3 stdmath_int4_wzx(stdmath_int4 v) { return {v.w,v.z,v.x}; }
inline static stdmath_int4 stdmath_int4_wzx_value(stdmath_int4 v, stdmath_int3 value) { v.w = value.x; v.z = value.y; v.x = value.z; return v; }
inline static stdmath_int3 stdmath_int4_wzy(stdmath_int4 v) { return {v.w,v.z,v.y}; }
inline static stdmath_int4 stdmath_int4_wzy_value(stdmath_int4 v, stdmath_int3 value) { v.w = value.x; v.z = value.y; v.y = value.z; return v; }
inline static stdmath_int3 stdmath_int4_wzz(stdmath_int4 v) { return {v.w,v.z,v.z}; }
inline static stdmath_int4 stdmath_int4_wzz_value(stdmath_int4 v, stdmath_int3 value) { v.w = value.x; v.z = value.y; v.z = value.z; return v; }
inline static stdmath_int3 stdmath_int4_wzw(stdmath_int4 v) { return {v.w,v.z,v.w}; }
inline static stdmath_int4 stdmath_int4_wzw_value(stdmath_int4 v, stdmath_int3 value) { v.w = value.x; v.z = value.y; v.w = value.z; return v; }
inline static stdmath_int3 stdmath_int4_wwx(stdmath_int4 v) { return {v.w,v.w,v.x}; }
inline static stdmath_int4 stdmath_int4_wwx_value(stdmath_int4 v, stdmath_int3 value) { v.w = value.x; v.w = value.y; v.x = value.z; return v; }
inline static stdmath_int3 stdmath_int4_wwy(stdmath_int4 v) { return {v.w,v.w,v.y}; }
inline static stdmath_int4 stdmath_int4_wwy_value(stdmath_int4 v, stdmath_int3 value) { v.w = value.x; v.w = value.y; v.y = value.z; return v; }
inline static stdmath_int3 stdmath_int4_wwz(stdmath_int4 v) { return {v.w,v.w,v.z}; }
inline static stdmath_int4 stdmath_int4_wwz_value(stdmath_int4 v, stdmath_int3 value) { v.w = value.x; v.w = value.y; v.z = value.z; return v; }
inline static stdmath_int3 stdmath_int4_www(stdmath_int4 v) { return {v.w,v.w,v.w}; }
inline static stdmath_int4 stdmath_int4_www_value(stdmath_int4 v, stdmath_int3 value) { v.w = value.x; v.w = value.y; v.w = value.z; return v; }
inline static stdmath_int4 stdmath_int4_xxxx(stdmath_int4 v) { return {v.x,v.x,v.x,v.x}; }
inline static stdmath_int4 stdmath_int4_xxxx_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.x = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xxxy(stdmath_int4 v) { return {v.x,v.x,v.x,v.y}; }
inline static stdmath_int4 stdmath_int4_xxxy_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.x = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xxxz(stdmath_int4 v) { return {v.x,v.x,v.x,v.z}; }
inline static stdmath_int4 stdmath_int4_xxxz_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.x = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xxxw(stdmath_int4 v) { return {v.x,v.x,v.x,v.w}; }
inline static stdmath_int4 stdmath_int4_xxxw_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.x = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xxyx(stdmath_int4 v) { return {v.x,v.x,v.y,v.x}; }
inline static stdmath_int4 stdmath_int4_xxyx_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.x = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xxyy(stdmath_int4 v) { return {v.x,v.x,v.y,v.y}; }
inline static stdmath_int4 stdmath_int4_xxyy_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.x = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xxyz(stdmath_int4 v) { return {v.x,v.x,v.y,v.z}; }
inline static stdmath_int4 stdmath_int4_xxyz_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.x = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xxyw(stdmath_int4 v) { return {v.x,v.x,v.y,v.w}; }
inline static stdmath_int4 stdmath_int4_xxyw_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.x = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xxzx(stdmath_int4 v) { return {v.x,v.x,v.z,v.x}; }
inline static stdmath_int4 stdmath_int4_xxzx_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.x = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xxzy(stdmath_int4 v) { return {v.x,v.x,v.z,v.y}; }
inline static stdmath_int4 stdmath_int4_xxzy_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.x = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xxzz(stdmath_int4 v) { return {v.x,v.x,v.z,v.z}; }
inline static stdmath_int4 stdmath_int4_xxzz_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.x = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xxzw(stdmath_int4 v) { return {v.x,v.x,v.z,v.w}; }
inline static stdmath_int4 stdmath_int4_xxzw_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.x = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xxwx(stdmath_int4 v) { return {v.x,v.x,v.w,v.x}; }
inline static stdmath_int4 stdmath_int4_xxwx_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.x = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xxwy(stdmath_int4 v) { return {v.x,v.x,v.w,v.y}; }
inline static stdmath_int4 stdmath_int4_xxwy_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.x = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xxwz(stdmath_int4 v) { return {v.x,v.x,v.w,v.z}; }
inline static stdmath_int4 stdmath_int4_xxwz_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.x = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xxww(stdmath_int4 v) { return {v.x,v.x,v.w,v.w}; }
inline static stdmath_int4 stdmath_int4_xxww_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.x = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xyxx(stdmath_int4 v) { return {v.x,v.y,v.x,v.x}; }
inline static stdmath_int4 stdmath_int4_xyxx_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.y = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xyxy(stdmath_int4 v) { return {v.x,v.y,v.x,v.y}; }
inline static stdmath_int4 stdmath_int4_xyxy_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.y = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xyxz(stdmath_int4 v) { return {v.x,v.y,v.x,v.z}; }
inline static stdmath_int4 stdmath_int4_xyxz_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.y = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xyxw(stdmath_int4 v) { return {v.x,v.y,v.x,v.w}; }
inline static stdmath_int4 stdmath_int4_xyxw_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.y = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xyyx(stdmath_int4 v) { return {v.x,v.y,v.y,v.x}; }
inline static stdmath_int4 stdmath_int4_xyyx_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.y = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xyyy(stdmath_int4 v) { return {v.x,v.y,v.y,v.y}; }
inline static stdmath_int4 stdmath_int4_xyyy_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.y = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xyyz(stdmath_int4 v) { return {v.x,v.y,v.y,v.z}; }
inline static stdmath_int4 stdmath_int4_xyyz_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.y = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xyyw(stdmath_int4 v) { return {v.x,v.y,v.y,v.w}; }
inline static stdmath_int4 stdmath_int4_xyyw_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.y = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xyzx(stdmath_int4 v) { return {v.x,v.y,v.z,v.x}; }
inline static stdmath_int4 stdmath_int4_xyzx_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.y = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xyzy(stdmath_int4 v) { return {v.x,v.y,v.z,v.y}; }
inline static stdmath_int4 stdmath_int4_xyzy_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.y = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xyzz(stdmath_int4 v) { return {v.x,v.y,v.z,v.z}; }
inline static stdmath_int4 stdmath_int4_xyzz_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.y = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xyzw(stdmath_int4 v) { return {v.x,v.y,v.z,v.w}; }
inline static stdmath_int4 stdmath_int4_xyzw_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.y = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xywx(stdmath_int4 v) { return {v.x,v.y,v.w,v.x}; }
inline static stdmath_int4 stdmath_int4_xywx_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.y = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xywy(stdmath_int4 v) { return {v.x,v.y,v.w,v.y}; }
inline static stdmath_int4 stdmath_int4_xywy_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.y = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xywz(stdmath_int4 v) { return {v.x,v.y,v.w,v.z}; }
inline static stdmath_int4 stdmath_int4_xywz_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.y = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xyww(stdmath_int4 v) { return {v.x,v.y,v.w,v.w}; }
inline static stdmath_int4 stdmath_int4_xyww_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.y = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xzxx(stdmath_int4 v) { return {v.x,v.z,v.x,v.x}; }
inline static stdmath_int4 stdmath_int4_xzxx_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.z = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xzxy(stdmath_int4 v) { return {v.x,v.z,v.x,v.y}; }
inline static stdmath_int4 stdmath_int4_xzxy_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.z = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xzxz(stdmath_int4 v) { return {v.x,v.z,v.x,v.z}; }
inline static stdmath_int4 stdmath_int4_xzxz_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.z = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xzxw(stdmath_int4 v) { return {v.x,v.z,v.x,v.w}; }
inline static stdmath_int4 stdmath_int4_xzxw_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.z = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xzyx(stdmath_int4 v) { return {v.x,v.z,v.y,v.x}; }
inline static stdmath_int4 stdmath_int4_xzyx_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.z = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xzyy(stdmath_int4 v) { return {v.x,v.z,v.y,v.y}; }
inline static stdmath_int4 stdmath_int4_xzyy_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.z = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xzyz(stdmath_int4 v) { return {v.x,v.z,v.y,v.z}; }
inline static stdmath_int4 stdmath_int4_xzyz_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.z = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xzyw(stdmath_int4 v) { return {v.x,v.z,v.y,v.w}; }
inline static stdmath_int4 stdmath_int4_xzyw_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.z = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xzzx(stdmath_int4 v) { return {v.x,v.z,v.z,v.x}; }
inline static stdmath_int4 stdmath_int4_xzzx_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.z = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xzzy(stdmath_int4 v) { return {v.x,v.z,v.z,v.y}; }
inline static stdmath_int4 stdmath_int4_xzzy_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.z = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xzzz(stdmath_int4 v) { return {v.x,v.z,v.z,v.z}; }
inline static stdmath_int4 stdmath_int4_xzzz_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.z = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xzzw(stdmath_int4 v) { return {v.x,v.z,v.z,v.w}; }
inline static stdmath_int4 stdmath_int4_xzzw_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.z = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xzwx(stdmath_int4 v) { return {v.x,v.z,v.w,v.x}; }
inline static stdmath_int4 stdmath_int4_xzwx_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.z = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xzwy(stdmath_int4 v) { return {v.x,v.z,v.w,v.y}; }
inline static stdmath_int4 stdmath_int4_xzwy_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.z = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xzwz(stdmath_int4 v) { return {v.x,v.z,v.w,v.z}; }
inline static stdmath_int4 stdmath_int4_xzwz_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.z = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xzww(stdmath_int4 v) { return {v.x,v.z,v.w,v.w}; }
inline static stdmath_int4 stdmath_int4_xzww_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.z = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xwxx(stdmath_int4 v) { return {v.x,v.w,v.x,v.x}; }
inline static stdmath_int4 stdmath_int4_xwxx_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.w = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xwxy(stdmath_int4 v) { return {v.x,v.w,v.x,v.y}; }
inline static stdmath_int4 stdmath_int4_xwxy_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.w = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xwxz(stdmath_int4 v) { return {v.x,v.w,v.x,v.z}; }
inline static stdmath_int4 stdmath_int4_xwxz_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.w = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xwxw(stdmath_int4 v) { return {v.x,v.w,v.x,v.w}; }
inline static stdmath_int4 stdmath_int4_xwxw_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.w = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xwyx(stdmath_int4 v) { return {v.x,v.w,v.y,v.x}; }
inline static stdmath_int4 stdmath_int4_xwyx_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.w = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xwyy(stdmath_int4 v) { return {v.x,v.w,v.y,v.y}; }
inline static stdmath_int4 stdmath_int4_xwyy_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.w = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xwyz(stdmath_int4 v) { return {v.x,v.w,v.y,v.z}; }
inline static stdmath_int4 stdmath_int4_xwyz_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.w = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xwyw(stdmath_int4 v) { return {v.x,v.w,v.y,v.w}; }
inline static stdmath_int4 stdmath_int4_xwyw_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.w = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xwzx(stdmath_int4 v) { return {v.x,v.w,v.z,v.x}; }
inline static stdmath_int4 stdmath_int4_xwzx_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.w = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xwzy(stdmath_int4 v) { return {v.x,v.w,v.z,v.y}; }
inline static stdmath_int4 stdmath_int4_xwzy_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.w = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xwzz(stdmath_int4 v) { return {v.x,v.w,v.z,v.z}; }
inline static stdmath_int4 stdmath_int4_xwzz_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.w = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xwzw(stdmath_int4 v) { return {v.x,v.w,v.z,v.w}; }
inline static stdmath_int4 stdmath_int4_xwzw_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.w = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xwwx(stdmath_int4 v) { return {v.x,v.w,v.w,v.x}; }
inline static stdmath_int4 stdmath_int4_xwwx_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.w = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xwwy(stdmath_int4 v) { return {v.x,v.w,v.w,v.y}; }
inline static stdmath_int4 stdmath_int4_xwwy_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.w = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xwwz(stdmath_int4 v) { return {v.x,v.w,v.w,v.z}; }
inline static stdmath_int4 stdmath_int4_xwwz_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.w = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_xwww(stdmath_int4 v) { return {v.x,v.w,v.w,v.w}; }
inline static stdmath_int4 stdmath_int4_xwww_value(stdmath_int4 v, stdmath_int4 value) { v.x = value.x; v.w = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_yxxx(stdmath_int4 v) { return {v.y,v.x,v.x,v.x}; }
inline static stdmath_int4 stdmath_int4_yxxx_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.x = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_yxxy(stdmath_int4 v) { return {v.y,v.x,v.x,v.y}; }
inline static stdmath_int4 stdmath_int4_yxxy_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.x = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_yxxz(stdmath_int4 v) { return {v.y,v.x,v.x,v.z}; }
inline static stdmath_int4 stdmath_int4_yxxz_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.x = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_yxxw(stdmath_int4 v) { return {v.y,v.x,v.x,v.w}; }
inline static stdmath_int4 stdmath_int4_yxxw_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.x = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_yxyx(stdmath_int4 v) { return {v.y,v.x,v.y,v.x}; }
inline static stdmath_int4 stdmath_int4_yxyx_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.x = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_yxyy(stdmath_int4 v) { return {v.y,v.x,v.y,v.y}; }
inline static stdmath_int4 stdmath_int4_yxyy_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.x = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_yxyz(stdmath_int4 v) { return {v.y,v.x,v.y,v.z}; }
inline static stdmath_int4 stdmath_int4_yxyz_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.x = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_yxyw(stdmath_int4 v) { return {v.y,v.x,v.y,v.w}; }
inline static stdmath_int4 stdmath_int4_yxyw_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.x = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_yxzx(stdmath_int4 v) { return {v.y,v.x,v.z,v.x}; }
inline static stdmath_int4 stdmath_int4_yxzx_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.x = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_yxzy(stdmath_int4 v) { return {v.y,v.x,v.z,v.y}; }
inline static stdmath_int4 stdmath_int4_yxzy_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.x = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_yxzz(stdmath_int4 v) { return {v.y,v.x,v.z,v.z}; }
inline static stdmath_int4 stdmath_int4_yxzz_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.x = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_yxzw(stdmath_int4 v) { return {v.y,v.x,v.z,v.w}; }
inline static stdmath_int4 stdmath_int4_yxzw_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.x = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_yxwx(stdmath_int4 v) { return {v.y,v.x,v.w,v.x}; }
inline static stdmath_int4 stdmath_int4_yxwx_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.x = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_yxwy(stdmath_int4 v) { return {v.y,v.x,v.w,v.y}; }
inline static stdmath_int4 stdmath_int4_yxwy_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.x = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_yxwz(stdmath_int4 v) { return {v.y,v.x,v.w,v.z}; }
inline static stdmath_int4 stdmath_int4_yxwz_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.x = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_yxww(stdmath_int4 v) { return {v.y,v.x,v.w,v.w}; }
inline static stdmath_int4 stdmath_int4_yxww_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.x = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_yyxx(stdmath_int4 v) { return {v.y,v.y,v.x,v.x}; }
inline static stdmath_int4 stdmath_int4_yyxx_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.y = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_yyxy(stdmath_int4 v) { return {v.y,v.y,v.x,v.y}; }
inline static stdmath_int4 stdmath_int4_yyxy_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.y = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_yyxz(stdmath_int4 v) { return {v.y,v.y,v.x,v.z}; }
inline static stdmath_int4 stdmath_int4_yyxz_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.y = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_yyxw(stdmath_int4 v) { return {v.y,v.y,v.x,v.w}; }
inline static stdmath_int4 stdmath_int4_yyxw_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.y = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_yyyx(stdmath_int4 v) { return {v.y,v.y,v.y,v.x}; }
inline static stdmath_int4 stdmath_int4_yyyx_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.y = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_yyyy(stdmath_int4 v) { return {v.y,v.y,v.y,v.y}; }
inline static stdmath_int4 stdmath_int4_yyyy_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.y = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_yyyz(stdmath_int4 v) { return {v.y,v.y,v.y,v.z}; }
inline static stdmath_int4 stdmath_int4_yyyz_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.y = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_yyyw(stdmath_int4 v) { return {v.y,v.y,v.y,v.w}; }
inline static stdmath_int4 stdmath_int4_yyyw_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.y = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_yyzx(stdmath_int4 v) { return {v.y,v.y,v.z,v.x}; }
inline static stdmath_int4 stdmath_int4_yyzx_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.y = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_yyzy(stdmath_int4 v) { return {v.y,v.y,v.z,v.y}; }
inline static stdmath_int4 stdmath_int4_yyzy_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.y = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_yyzz(stdmath_int4 v) { return {v.y,v.y,v.z,v.z}; }
inline static stdmath_int4 stdmath_int4_yyzz_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.y = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_yyzw(stdmath_int4 v) { return {v.y,v.y,v.z,v.w}; }
inline static stdmath_int4 stdmath_int4_yyzw_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.y = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_yywx(stdmath_int4 v) { return {v.y,v.y,v.w,v.x}; }
inline static stdmath_int4 stdmath_int4_yywx_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.y = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_yywy(stdmath_int4 v) { return {v.y,v.y,v.w,v.y}; }
inline static stdmath_int4 stdmath_int4_yywy_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.y = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_yywz(stdmath_int4 v) { return {v.y,v.y,v.w,v.z}; }
inline static stdmath_int4 stdmath_int4_yywz_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.y = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_yyww(stdmath_int4 v) { return {v.y,v.y,v.w,v.w}; }
inline static stdmath_int4 stdmath_int4_yyww_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.y = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_yzxx(stdmath_int4 v) { return {v.y,v.z,v.x,v.x}; }
inline static stdmath_int4 stdmath_int4_yzxx_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.z = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_yzxy(stdmath_int4 v) { return {v.y,v.z,v.x,v.y}; }
inline static stdmath_int4 stdmath_int4_yzxy_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.z = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_yzxz(stdmath_int4 v) { return {v.y,v.z,v.x,v.z}; }
inline static stdmath_int4 stdmath_int4_yzxz_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.z = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_yzxw(stdmath_int4 v) { return {v.y,v.z,v.x,v.w}; }
inline static stdmath_int4 stdmath_int4_yzxw_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.z = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_yzyx(stdmath_int4 v) { return {v.y,v.z,v.y,v.x}; }
inline static stdmath_int4 stdmath_int4_yzyx_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.z = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_yzyy(stdmath_int4 v) { return {v.y,v.z,v.y,v.y}; }
inline static stdmath_int4 stdmath_int4_yzyy_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.z = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_yzyz(stdmath_int4 v) { return {v.y,v.z,v.y,v.z}; }
inline static stdmath_int4 stdmath_int4_yzyz_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.z = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_yzyw(stdmath_int4 v) { return {v.y,v.z,v.y,v.w}; }
inline static stdmath_int4 stdmath_int4_yzyw_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.z = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_yzzx(stdmath_int4 v) { return {v.y,v.z,v.z,v.x}; }
inline static stdmath_int4 stdmath_int4_yzzx_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.z = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_yzzy(stdmath_int4 v) { return {v.y,v.z,v.z,v.y}; }
inline static stdmath_int4 stdmath_int4_yzzy_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.z = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_yzzz(stdmath_int4 v) { return {v.y,v.z,v.z,v.z}; }
inline static stdmath_int4 stdmath_int4_yzzz_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.z = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_yzzw(stdmath_int4 v) { return {v.y,v.z,v.z,v.w}; }
inline static stdmath_int4 stdmath_int4_yzzw_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.z = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_yzwx(stdmath_int4 v) { return {v.y,v.z,v.w,v.x}; }
inline static stdmath_int4 stdmath_int4_yzwx_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.z = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_yzwy(stdmath_int4 v) { return {v.y,v.z,v.w,v.y}; }
inline static stdmath_int4 stdmath_int4_yzwy_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.z = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_yzwz(stdmath_int4 v) { return {v.y,v.z,v.w,v.z}; }
inline static stdmath_int4 stdmath_int4_yzwz_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.z = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_yzww(stdmath_int4 v) { return {v.y,v.z,v.w,v.w}; }
inline static stdmath_int4 stdmath_int4_yzww_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.z = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_ywxx(stdmath_int4 v) { return {v.y,v.w,v.x,v.x}; }
inline static stdmath_int4 stdmath_int4_ywxx_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.w = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_ywxy(stdmath_int4 v) { return {v.y,v.w,v.x,v.y}; }
inline static stdmath_int4 stdmath_int4_ywxy_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.w = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_ywxz(stdmath_int4 v) { return {v.y,v.w,v.x,v.z}; }
inline static stdmath_int4 stdmath_int4_ywxz_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.w = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_ywxw(stdmath_int4 v) { return {v.y,v.w,v.x,v.w}; }
inline static stdmath_int4 stdmath_int4_ywxw_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.w = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_ywyx(stdmath_int4 v) { return {v.y,v.w,v.y,v.x}; }
inline static stdmath_int4 stdmath_int4_ywyx_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.w = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_ywyy(stdmath_int4 v) { return {v.y,v.w,v.y,v.y}; }
inline static stdmath_int4 stdmath_int4_ywyy_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.w = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_ywyz(stdmath_int4 v) { return {v.y,v.w,v.y,v.z}; }
inline static stdmath_int4 stdmath_int4_ywyz_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.w = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_ywyw(stdmath_int4 v) { return {v.y,v.w,v.y,v.w}; }
inline static stdmath_int4 stdmath_int4_ywyw_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.w = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_ywzx(stdmath_int4 v) { return {v.y,v.w,v.z,v.x}; }
inline static stdmath_int4 stdmath_int4_ywzx_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.w = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_ywzy(stdmath_int4 v) { return {v.y,v.w,v.z,v.y}; }
inline static stdmath_int4 stdmath_int4_ywzy_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.w = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_ywzz(stdmath_int4 v) { return {v.y,v.w,v.z,v.z}; }
inline static stdmath_int4 stdmath_int4_ywzz_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.w = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_ywzw(stdmath_int4 v) { return {v.y,v.w,v.z,v.w}; }
inline static stdmath_int4 stdmath_int4_ywzw_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.w = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_ywwx(stdmath_int4 v) { return {v.y,v.w,v.w,v.x}; }
inline static stdmath_int4 stdmath_int4_ywwx_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.w = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_ywwy(stdmath_int4 v) { return {v.y,v.w,v.w,v.y}; }
inline static stdmath_int4 stdmath_int4_ywwy_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.w = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_ywwz(stdmath_int4 v) { return {v.y,v.w,v.w,v.z}; }
inline static stdmath_int4 stdmath_int4_ywwz_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.w = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_ywww(stdmath_int4 v) { return {v.y,v.w,v.w,v.w}; }
inline static stdmath_int4 stdmath_int4_ywww_value(stdmath_int4 v, stdmath_int4 value) { v.y = value.x; v.w = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zxxx(stdmath_int4 v) { return {v.z,v.x,v.x,v.x}; }
inline static stdmath_int4 stdmath_int4_zxxx_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.x = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zxxy(stdmath_int4 v) { return {v.z,v.x,v.x,v.y}; }
inline static stdmath_int4 stdmath_int4_zxxy_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.x = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zxxz(stdmath_int4 v) { return {v.z,v.x,v.x,v.z}; }
inline static stdmath_int4 stdmath_int4_zxxz_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.x = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zxxw(stdmath_int4 v) { return {v.z,v.x,v.x,v.w}; }
inline static stdmath_int4 stdmath_int4_zxxw_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.x = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zxyx(stdmath_int4 v) { return {v.z,v.x,v.y,v.x}; }
inline static stdmath_int4 stdmath_int4_zxyx_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.x = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zxyy(stdmath_int4 v) { return {v.z,v.x,v.y,v.y}; }
inline static stdmath_int4 stdmath_int4_zxyy_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.x = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zxyz(stdmath_int4 v) { return {v.z,v.x,v.y,v.z}; }
inline static stdmath_int4 stdmath_int4_zxyz_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.x = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zxyw(stdmath_int4 v) { return {v.z,v.x,v.y,v.w}; }
inline static stdmath_int4 stdmath_int4_zxyw_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.x = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zxzx(stdmath_int4 v) { return {v.z,v.x,v.z,v.x}; }
inline static stdmath_int4 stdmath_int4_zxzx_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.x = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zxzy(stdmath_int4 v) { return {v.z,v.x,v.z,v.y}; }
inline static stdmath_int4 stdmath_int4_zxzy_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.x = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zxzz(stdmath_int4 v) { return {v.z,v.x,v.z,v.z}; }
inline static stdmath_int4 stdmath_int4_zxzz_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.x = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zxzw(stdmath_int4 v) { return {v.z,v.x,v.z,v.w}; }
inline static stdmath_int4 stdmath_int4_zxzw_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.x = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zxwx(stdmath_int4 v) { return {v.z,v.x,v.w,v.x}; }
inline static stdmath_int4 stdmath_int4_zxwx_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.x = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zxwy(stdmath_int4 v) { return {v.z,v.x,v.w,v.y}; }
inline static stdmath_int4 stdmath_int4_zxwy_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.x = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zxwz(stdmath_int4 v) { return {v.z,v.x,v.w,v.z}; }
inline static stdmath_int4 stdmath_int4_zxwz_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.x = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zxww(stdmath_int4 v) { return {v.z,v.x,v.w,v.w}; }
inline static stdmath_int4 stdmath_int4_zxww_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.x = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zyxx(stdmath_int4 v) { return {v.z,v.y,v.x,v.x}; }
inline static stdmath_int4 stdmath_int4_zyxx_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.y = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zyxy(stdmath_int4 v) { return {v.z,v.y,v.x,v.y}; }
inline static stdmath_int4 stdmath_int4_zyxy_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.y = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zyxz(stdmath_int4 v) { return {v.z,v.y,v.x,v.z}; }
inline static stdmath_int4 stdmath_int4_zyxz_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.y = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zyxw(stdmath_int4 v) { return {v.z,v.y,v.x,v.w}; }
inline static stdmath_int4 stdmath_int4_zyxw_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.y = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zyyx(stdmath_int4 v) { return {v.z,v.y,v.y,v.x}; }
inline static stdmath_int4 stdmath_int4_zyyx_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.y = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zyyy(stdmath_int4 v) { return {v.z,v.y,v.y,v.y}; }
inline static stdmath_int4 stdmath_int4_zyyy_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.y = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zyyz(stdmath_int4 v) { return {v.z,v.y,v.y,v.z}; }
inline static stdmath_int4 stdmath_int4_zyyz_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.y = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zyyw(stdmath_int4 v) { return {v.z,v.y,v.y,v.w}; }
inline static stdmath_int4 stdmath_int4_zyyw_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.y = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zyzx(stdmath_int4 v) { return {v.z,v.y,v.z,v.x}; }
inline static stdmath_int4 stdmath_int4_zyzx_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.y = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zyzy(stdmath_int4 v) { return {v.z,v.y,v.z,v.y}; }
inline static stdmath_int4 stdmath_int4_zyzy_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.y = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zyzz(stdmath_int4 v) { return {v.z,v.y,v.z,v.z}; }
inline static stdmath_int4 stdmath_int4_zyzz_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.y = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zyzw(stdmath_int4 v) { return {v.z,v.y,v.z,v.w}; }
inline static stdmath_int4 stdmath_int4_zyzw_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.y = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zywx(stdmath_int4 v) { return {v.z,v.y,v.w,v.x}; }
inline static stdmath_int4 stdmath_int4_zywx_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.y = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zywy(stdmath_int4 v) { return {v.z,v.y,v.w,v.y}; }
inline static stdmath_int4 stdmath_int4_zywy_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.y = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zywz(stdmath_int4 v) { return {v.z,v.y,v.w,v.z}; }
inline static stdmath_int4 stdmath_int4_zywz_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.y = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zyww(stdmath_int4 v) { return {v.z,v.y,v.w,v.w}; }
inline static stdmath_int4 stdmath_int4_zyww_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.y = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zzxx(stdmath_int4 v) { return {v.z,v.z,v.x,v.x}; }
inline static stdmath_int4 stdmath_int4_zzxx_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.z = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zzxy(stdmath_int4 v) { return {v.z,v.z,v.x,v.y}; }
inline static stdmath_int4 stdmath_int4_zzxy_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.z = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zzxz(stdmath_int4 v) { return {v.z,v.z,v.x,v.z}; }
inline static stdmath_int4 stdmath_int4_zzxz_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.z = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zzxw(stdmath_int4 v) { return {v.z,v.z,v.x,v.w}; }
inline static stdmath_int4 stdmath_int4_zzxw_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.z = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zzyx(stdmath_int4 v) { return {v.z,v.z,v.y,v.x}; }
inline static stdmath_int4 stdmath_int4_zzyx_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.z = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zzyy(stdmath_int4 v) { return {v.z,v.z,v.y,v.y}; }
inline static stdmath_int4 stdmath_int4_zzyy_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.z = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zzyz(stdmath_int4 v) { return {v.z,v.z,v.y,v.z}; }
inline static stdmath_int4 stdmath_int4_zzyz_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.z = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zzyw(stdmath_int4 v) { return {v.z,v.z,v.y,v.w}; }
inline static stdmath_int4 stdmath_int4_zzyw_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.z = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zzzx(stdmath_int4 v) { return {v.z,v.z,v.z,v.x}; }
inline static stdmath_int4 stdmath_int4_zzzx_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.z = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zzzy(stdmath_int4 v) { return {v.z,v.z,v.z,v.y}; }
inline static stdmath_int4 stdmath_int4_zzzy_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.z = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zzzz(stdmath_int4 v) { return {v.z,v.z,v.z,v.z}; }
inline static stdmath_int4 stdmath_int4_zzzz_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.z = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zzzw(stdmath_int4 v) { return {v.z,v.z,v.z,v.w}; }
inline static stdmath_int4 stdmath_int4_zzzw_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.z = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zzwx(stdmath_int4 v) { return {v.z,v.z,v.w,v.x}; }
inline static stdmath_int4 stdmath_int4_zzwx_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.z = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zzwy(stdmath_int4 v) { return {v.z,v.z,v.w,v.y}; }
inline static stdmath_int4 stdmath_int4_zzwy_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.z = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zzwz(stdmath_int4 v) { return {v.z,v.z,v.w,v.z}; }
inline static stdmath_int4 stdmath_int4_zzwz_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.z = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zzww(stdmath_int4 v) { return {v.z,v.z,v.w,v.w}; }
inline static stdmath_int4 stdmath_int4_zzww_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.z = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zwxx(stdmath_int4 v) { return {v.z,v.w,v.x,v.x}; }
inline static stdmath_int4 stdmath_int4_zwxx_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.w = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zwxy(stdmath_int4 v) { return {v.z,v.w,v.x,v.y}; }
inline static stdmath_int4 stdmath_int4_zwxy_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.w = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zwxz(stdmath_int4 v) { return {v.z,v.w,v.x,v.z}; }
inline static stdmath_int4 stdmath_int4_zwxz_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.w = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zwxw(stdmath_int4 v) { return {v.z,v.w,v.x,v.w}; }
inline static stdmath_int4 stdmath_int4_zwxw_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.w = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zwyx(stdmath_int4 v) { return {v.z,v.w,v.y,v.x}; }
inline static stdmath_int4 stdmath_int4_zwyx_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.w = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zwyy(stdmath_int4 v) { return {v.z,v.w,v.y,v.y}; }
inline static stdmath_int4 stdmath_int4_zwyy_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.w = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zwyz(stdmath_int4 v) { return {v.z,v.w,v.y,v.z}; }
inline static stdmath_int4 stdmath_int4_zwyz_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.w = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zwyw(stdmath_int4 v) { return {v.z,v.w,v.y,v.w}; }
inline static stdmath_int4 stdmath_int4_zwyw_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.w = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zwzx(stdmath_int4 v) { return {v.z,v.w,v.z,v.x}; }
inline static stdmath_int4 stdmath_int4_zwzx_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.w = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zwzy(stdmath_int4 v) { return {v.z,v.w,v.z,v.y}; }
inline static stdmath_int4 stdmath_int4_zwzy_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.w = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zwzz(stdmath_int4 v) { return {v.z,v.w,v.z,v.z}; }
inline static stdmath_int4 stdmath_int4_zwzz_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.w = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zwzw(stdmath_int4 v) { return {v.z,v.w,v.z,v.w}; }
inline static stdmath_int4 stdmath_int4_zwzw_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.w = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zwwx(stdmath_int4 v) { return {v.z,v.w,v.w,v.x}; }
inline static stdmath_int4 stdmath_int4_zwwx_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.w = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zwwy(stdmath_int4 v) { return {v.z,v.w,v.w,v.y}; }
inline static stdmath_int4 stdmath_int4_zwwy_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.w = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zwwz(stdmath_int4 v) { return {v.z,v.w,v.w,v.z}; }
inline static stdmath_int4 stdmath_int4_zwwz_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.w = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_zwww(stdmath_int4 v) { return {v.z,v.w,v.w,v.w}; }
inline static stdmath_int4 stdmath_int4_zwww_value(stdmath_int4 v, stdmath_int4 value) { v.z = value.x; v.w = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wxxx(stdmath_int4 v) { return {v.w,v.x,v.x,v.x}; }
inline static stdmath_int4 stdmath_int4_wxxx_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.x = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wxxy(stdmath_int4 v) { return {v.w,v.x,v.x,v.y}; }
inline static stdmath_int4 stdmath_int4_wxxy_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.x = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wxxz(stdmath_int4 v) { return {v.w,v.x,v.x,v.z}; }
inline static stdmath_int4 stdmath_int4_wxxz_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.x = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wxxw(stdmath_int4 v) { return {v.w,v.x,v.x,v.w}; }
inline static stdmath_int4 stdmath_int4_wxxw_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.x = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wxyx(stdmath_int4 v) { return {v.w,v.x,v.y,v.x}; }
inline static stdmath_int4 stdmath_int4_wxyx_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.x = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wxyy(stdmath_int4 v) { return {v.w,v.x,v.y,v.y}; }
inline static stdmath_int4 stdmath_int4_wxyy_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.x = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wxyz(stdmath_int4 v) { return {v.w,v.x,v.y,v.z}; }
inline static stdmath_int4 stdmath_int4_wxyz_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.x = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wxyw(stdmath_int4 v) { return {v.w,v.x,v.y,v.w}; }
inline static stdmath_int4 stdmath_int4_wxyw_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.x = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wxzx(stdmath_int4 v) { return {v.w,v.x,v.z,v.x}; }
inline static stdmath_int4 stdmath_int4_wxzx_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.x = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wxzy(stdmath_int4 v) { return {v.w,v.x,v.z,v.y}; }
inline static stdmath_int4 stdmath_int4_wxzy_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.x = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wxzz(stdmath_int4 v) { return {v.w,v.x,v.z,v.z}; }
inline static stdmath_int4 stdmath_int4_wxzz_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.x = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wxzw(stdmath_int4 v) { return {v.w,v.x,v.z,v.w}; }
inline static stdmath_int4 stdmath_int4_wxzw_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.x = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wxwx(stdmath_int4 v) { return {v.w,v.x,v.w,v.x}; }
inline static stdmath_int4 stdmath_int4_wxwx_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.x = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wxwy(stdmath_int4 v) { return {v.w,v.x,v.w,v.y}; }
inline static stdmath_int4 stdmath_int4_wxwy_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.x = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wxwz(stdmath_int4 v) { return {v.w,v.x,v.w,v.z}; }
inline static stdmath_int4 stdmath_int4_wxwz_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.x = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wxww(stdmath_int4 v) { return {v.w,v.x,v.w,v.w}; }
inline static stdmath_int4 stdmath_int4_wxww_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.x = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wyxx(stdmath_int4 v) { return {v.w,v.y,v.x,v.x}; }
inline static stdmath_int4 stdmath_int4_wyxx_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.y = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wyxy(stdmath_int4 v) { return {v.w,v.y,v.x,v.y}; }
inline static stdmath_int4 stdmath_int4_wyxy_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.y = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wyxz(stdmath_int4 v) { return {v.w,v.y,v.x,v.z}; }
inline static stdmath_int4 stdmath_int4_wyxz_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.y = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wyxw(stdmath_int4 v) { return {v.w,v.y,v.x,v.w}; }
inline static stdmath_int4 stdmath_int4_wyxw_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.y = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wyyx(stdmath_int4 v) { return {v.w,v.y,v.y,v.x}; }
inline static stdmath_int4 stdmath_int4_wyyx_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.y = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wyyy(stdmath_int4 v) { return {v.w,v.y,v.y,v.y}; }
inline static stdmath_int4 stdmath_int4_wyyy_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.y = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wyyz(stdmath_int4 v) { return {v.w,v.y,v.y,v.z}; }
inline static stdmath_int4 stdmath_int4_wyyz_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.y = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wyyw(stdmath_int4 v) { return {v.w,v.y,v.y,v.w}; }
inline static stdmath_int4 stdmath_int4_wyyw_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.y = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wyzx(stdmath_int4 v) { return {v.w,v.y,v.z,v.x}; }
inline static stdmath_int4 stdmath_int4_wyzx_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.y = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wyzy(stdmath_int4 v) { return {v.w,v.y,v.z,v.y}; }
inline static stdmath_int4 stdmath_int4_wyzy_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.y = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wyzz(stdmath_int4 v) { return {v.w,v.y,v.z,v.z}; }
inline static stdmath_int4 stdmath_int4_wyzz_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.y = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wyzw(stdmath_int4 v) { return {v.w,v.y,v.z,v.w}; }
inline static stdmath_int4 stdmath_int4_wyzw_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.y = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wywx(stdmath_int4 v) { return {v.w,v.y,v.w,v.x}; }
inline static stdmath_int4 stdmath_int4_wywx_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.y = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wywy(stdmath_int4 v) { return {v.w,v.y,v.w,v.y}; }
inline static stdmath_int4 stdmath_int4_wywy_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.y = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wywz(stdmath_int4 v) { return {v.w,v.y,v.w,v.z}; }
inline static stdmath_int4 stdmath_int4_wywz_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.y = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wyww(stdmath_int4 v) { return {v.w,v.y,v.w,v.w}; }
inline static stdmath_int4 stdmath_int4_wyww_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.y = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wzxx(stdmath_int4 v) { return {v.w,v.z,v.x,v.x}; }
inline static stdmath_int4 stdmath_int4_wzxx_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.z = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wzxy(stdmath_int4 v) { return {v.w,v.z,v.x,v.y}; }
inline static stdmath_int4 stdmath_int4_wzxy_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.z = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wzxz(stdmath_int4 v) { return {v.w,v.z,v.x,v.z}; }
inline static stdmath_int4 stdmath_int4_wzxz_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.z = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wzxw(stdmath_int4 v) { return {v.w,v.z,v.x,v.w}; }
inline static stdmath_int4 stdmath_int4_wzxw_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.z = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wzyx(stdmath_int4 v) { return {v.w,v.z,v.y,v.x}; }
inline static stdmath_int4 stdmath_int4_wzyx_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.z = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wzyy(stdmath_int4 v) { return {v.w,v.z,v.y,v.y}; }
inline static stdmath_int4 stdmath_int4_wzyy_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.z = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wzyz(stdmath_int4 v) { return {v.w,v.z,v.y,v.z}; }
inline static stdmath_int4 stdmath_int4_wzyz_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.z = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wzyw(stdmath_int4 v) { return {v.w,v.z,v.y,v.w}; }
inline static stdmath_int4 stdmath_int4_wzyw_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.z = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wzzx(stdmath_int4 v) { return {v.w,v.z,v.z,v.x}; }
inline static stdmath_int4 stdmath_int4_wzzx_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.z = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wzzy(stdmath_int4 v) { return {v.w,v.z,v.z,v.y}; }
inline static stdmath_int4 stdmath_int4_wzzy_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.z = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wzzz(stdmath_int4 v) { return {v.w,v.z,v.z,v.z}; }
inline static stdmath_int4 stdmath_int4_wzzz_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.z = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wzzw(stdmath_int4 v) { return {v.w,v.z,v.z,v.w}; }
inline static stdmath_int4 stdmath_int4_wzzw_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.z = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wzwx(stdmath_int4 v) { return {v.w,v.z,v.w,v.x}; }
inline static stdmath_int4 stdmath_int4_wzwx_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.z = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wzwy(stdmath_int4 v) { return {v.w,v.z,v.w,v.y}; }
inline static stdmath_int4 stdmath_int4_wzwy_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.z = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wzwz(stdmath_int4 v) { return {v.w,v.z,v.w,v.z}; }
inline static stdmath_int4 stdmath_int4_wzwz_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.z = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wzww(stdmath_int4 v) { return {v.w,v.z,v.w,v.w}; }
inline static stdmath_int4 stdmath_int4_wzww_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.z = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wwxx(stdmath_int4 v) { return {v.w,v.w,v.x,v.x}; }
inline static stdmath_int4 stdmath_int4_wwxx_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.w = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wwxy(stdmath_int4 v) { return {v.w,v.w,v.x,v.y}; }
inline static stdmath_int4 stdmath_int4_wwxy_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.w = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wwxz(stdmath_int4 v) { return {v.w,v.w,v.x,v.z}; }
inline static stdmath_int4 stdmath_int4_wwxz_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.w = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wwxw(stdmath_int4 v) { return {v.w,v.w,v.x,v.w}; }
inline static stdmath_int4 stdmath_int4_wwxw_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.w = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wwyx(stdmath_int4 v) { return {v.w,v.w,v.y,v.x}; }
inline static stdmath_int4 stdmath_int4_wwyx_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.w = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wwyy(stdmath_int4 v) { return {v.w,v.w,v.y,v.y}; }
inline static stdmath_int4 stdmath_int4_wwyy_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.w = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wwyz(stdmath_int4 v) { return {v.w,v.w,v.y,v.z}; }
inline static stdmath_int4 stdmath_int4_wwyz_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.w = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wwyw(stdmath_int4 v) { return {v.w,v.w,v.y,v.w}; }
inline static stdmath_int4 stdmath_int4_wwyw_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.w = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wwzx(stdmath_int4 v) { return {v.w,v.w,v.z,v.x}; }
inline static stdmath_int4 stdmath_int4_wwzx_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.w = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wwzy(stdmath_int4 v) { return {v.w,v.w,v.z,v.y}; }
inline static stdmath_int4 stdmath_int4_wwzy_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.w = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wwzz(stdmath_int4 v) { return {v.w,v.w,v.z,v.z}; }
inline static stdmath_int4 stdmath_int4_wwzz_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.w = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wwzw(stdmath_int4 v) { return {v.w,v.w,v.z,v.w}; }
inline static stdmath_int4 stdmath_int4_wwzw_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.w = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wwwx(stdmath_int4 v) { return {v.w,v.w,v.w,v.x}; }
inline static stdmath_int4 stdmath_int4_wwwx_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.w = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wwwy(stdmath_int4 v) { return {v.w,v.w,v.w,v.y}; }
inline static stdmath_int4 stdmath_int4_wwwy_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.w = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wwwz(stdmath_int4 v) { return {v.w,v.w,v.w,v.z}; }
inline static stdmath_int4 stdmath_int4_wwwz_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.w = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_int4 stdmath_int4_wwww(stdmath_int4 v) { return {v.w,v.w,v.w,v.w}; }
inline static stdmath_int4 stdmath_int4_wwww_value(stdmath_int4 v, stdmath_int4 value) { v.w = value.x; v.w = value.y; v.w = value.z; v.w = value.w; return v; }


#ifdef STDMATH_IMPLEMENTATION
#ifndef __cplusplus
#error "The stdmath implementations require a C++ compiler"
#endif

import stdmath.slang;

stdmath::int4 c(stdmath_int4 c) {
	return (stdmath::int4&)c;
}
stdmath_int4 c(stdmath::int4 c) {
	return (stdmath_int4&)c;
}

stdmath_int4 stdmath_int4_broadcast(int32_t all) {
	return c(stdmath::int4((stdmath::int4::underlying_type)all));
}

stdmath_int4 stdmath_int4_add(stdmath_int4 a, stdmath_int4 b) {
	return c(c(a) + c(b));
}
stdmath_int4 stdmath_int4_subtract(stdmath_int4 a, stdmath_int4 b) {
	return c(c(a) - c(b));
}
stdmath_int4 stdmath_int4_negate(stdmath_int4 v) {
	return c(stdmath::int4(-(stdmath::vector<int32_t, 4>)c(v)));
}
stdmath_int4 stdmath_int4_multiply(stdmath_int4 a, stdmath_int4 b) {
	return c(c(a) * c(b));
}
stdmath_int4 stdmath_int4_divide(stdmath_int4 a, stdmath_int4 b) {
	return c(c(a) / c(b));
}
stdmath_int4 stdmath_int4_scale(stdmath_int4 v, int32_t s) {
	return c(c(v) * (stdmath::int4::underlying_type)s);
}

#if false
stdmath_int4 stdmath_int4_modulus(stdmath_int4 a, stdmath_int4 b) {
	return c(c(a) % c(b));
}
stdmath_int4 stdmath_int4_logical_not(stdmath_int4 v) {
	return c(!c(v));
}
stdmath_int4 stdmath_int4_bitwise_not(stdmath_int4 v) {
	return c(~c(v));
}
stdmath_int4 stdmath_int4_logical_and(stdmath_int4 a, stdmath_int4 b) {
	return c(c(a) && c(b));
}
stdmath_int4 stdmath_int4_bitwise_and(stdmath_int4 a, stdmath_int4 b) {
	return c(c(a) & c(b));
}
stdmath_int4 stdmath_int4_logical_or(stdmath_int4 a, stdmath_int4 b) {
	return c(c(a) || c(b));
}
stdmath_int4 stdmath_int4_bitwise_or(stdmath_int4 a, stdmath_int4 b) {
	return c(c(a) | c(b));
}
stdmath_int4 stdmath_int4_bitwise_xor(stdmath_int4 a, stdmath_int4 b) {
	return c(c(a) ^ c(b));
}
stdmath_int4 stdmath_int4_shift_left(stdmath_int4 a, stdmath_int4 b) {
	return c(c(a) << c(b));
}
stdmath_int4 stdmath_int4_shift_right(stdmath_int4 a, stdmath_int4 b) {
	return c(c(a) >> c(b));
}
#endif

stdmath_bool4 stdmath_int4_equal_to(stdmath_int4 a, stdmath_int4 b) {
	return c(c(a) == c(b));
}
stdmath_bool4 stdmath_int4_not_equal_to(stdmath_int4 a, stdmath_int4 b) {
	return c(c(a) != c(b));
}
stdmath_bool4 stdmath_int4_less_than(stdmath_int4 a, stdmath_int4 b) {
	return c(c(a) < c(b));
}
stdmath_bool4 stdmath_int4_less_than_or_equal_to(stdmath_int4 a, stdmath_int4 b) {
	return c(c(a) <= c(b));
}
stdmath_bool4 stdmath_int4_greater_than(stdmath_int4 a, stdmath_int4 b) {
	return c(c(a) > c(b));
}
stdmath_bool4 stdmath_int4_greater_than_or_equal_to(stdmath_int4 a, stdmath_int4 b) {
	return c(c(a) >= c(b));
}

int32_t stdmath_int4_length_squared(stdmath_int4 v)  {
	return (int32_t)c(v).length_squared();
}
int32_t stdmath_int4_length(stdmath_int4 v)  {
	return (int32_t)c(v).length();
}
int32_t stdmath_int4_dot(stdmath_int4 a, stdmath_int4 b)  {
	return (int32_t)dot(c(a), c(b));
}
int32_t stdmath_int4_min_element(stdmath_int4 v)  {
	return (int32_t)c(v).min_element();
}
int32_t stdmath_int4_max_element(stdmath_int4 v)  {
	return (int32_t)c(v).max_element();
}

stdmath_int4 stdmath_int4_elementwise_transform(stdmath_int4 v, int32_t(*func)(int32_t)) {
	return c(c(v).elementwise_transform(func));
}
// int32_t stdmath_int4_reduce_elements(stdmath_int4 v, int32_t initial_value, int32_t(*reducer)(stdmath_int4, stdmath_int4)) {
// 	return c(v).reduce_elements(initial_value, reducer);
// }

stdmath_int4 stdmath_int4_min(stdmath_int4 a, stdmath_int4 b) {
	return c(min(c(a), c(b)));
}
stdmath_int4 stdmath_int4_max(stdmath_int4 a, stdmath_int4 b) {
	return c(max(c(a), c(b)));
}
stdmath_int4 stdmath_int4_normalize(stdmath_int4 v) {
	return c(normalize(c(v)));
}
stdmath_int4 stdmath_int4_lerp(stdmath_int4 a, stdmath_int4 b, float t) {
	return c(lerp(c(a), c(b), t));
}
stdmath_int4 stdmath_int4_clamp(stdmath_int4 a, stdmath_int4 min, stdmath_int4 max) {
	return c(clamp(c(a), c(min), c(max)));
}
stdmath_int4 stdmath_int4_reflect(stdmath_int4 a, stdmath_int4 b) {
	return c(reflect(c(a), c(b)));
}
stdmath_bool4 stdmath_int4_approximately_equal(stdmath_int4 a, stdmath_int4 b) {
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

#endif // __STDMATH_int32_t4_H__
