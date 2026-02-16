#ifndef __STDMATH_uint8_t4_H__
#define __STDMATH_uint8_t4_H__

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
#include "byte1.h"
#elif 4 == 3
#include "byte2.h"
#include "byte1.h"
#elif 4 == 4
#include "byte3.h"
#include "byte2.h"
#include "byte1.h"
#endif
#include "util.h"

#if 4 == 1
union stdmath_byte1 {
	struct {
		uint8_t x;
	};
	uint8_t data[1];
};
#elif 4 == 2
union stdmath_byte2 {
	struct {
		uint8_t x, y;
	};
	struct {
		uint8_t u, v;
	};
	uint8_t data[2];
};
#elif 4 == 3
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
	uint8_t data[4]; // byte3s are aligned as if they were byte4s
};
#elif 4 == 4
union stdmath_byte4 {
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

stdmath_byte4 stdmath_byte4_broadcast(uint8_t all);

stdmath_byte4 stdmath_byte4_add(stdmath_byte4 a, stdmath_byte4 b);
stdmath_byte4 stdmath_byte4_subtract(stdmath_byte4 a, stdmath_byte4 b);
stdmath_byte4 stdmath_byte4_negate(stdmath_byte4 v);
stdmath_byte4 stdmath_byte4_multiply(stdmath_byte4 a, stdmath_byte4 b);
stdmath_byte4 stdmath_byte4_divide(stdmath_byte4 a, stdmath_byte4 b);
stdmath_byte4 stdmath_byte4_scale(stdmath_byte4 v, uint8_t s);

#if false
stdmath_byte4 stdmath_byte4_modulus(stdmath_byte4 a, stdmath_byte4 b);
stdmath_byte4 stdmath_byte4_logical_not(stdmath_byte4 v);
stdmath_byte4 stdmath_byte4_bitwise_not(stdmath_byte4 v);
stdmath_byte4 stdmath_byte4_logical_and(stdmath_byte4 a, stdmath_byte4 b);
stdmath_byte4 stdmath_byte4_bitwise_and(stdmath_byte4 a, stdmath_byte4 b);
stdmath_byte4 stdmath_byte4_logical_or(stdmath_byte4 a, stdmath_byte4 b);
stdmath_byte4 stdmath_byte4_bitwise_or(stdmath_byte4 a, stdmath_byte4 b);
stdmath_byte4 stdmath_byte4_bitwise_xor(stdmath_byte4 a, stdmath_byte4 b);
stdmath_byte4 stdmath_byte4_shift_left(stdmath_byte4 a, stdmath_byte4 b);
stdmath_byte4 stdmath_byte4_shift_right(stdmath_byte4 a, stdmath_byte4 b);
#endif

stdmath_bool4 stdmath_byte4_equal_to(stdmath_byte4 a, stdmath_byte4 b);
stdmath_bool4 stdmath_byte4_not_equal_to(stdmath_byte4 a, stdmath_byte4 b);
stdmath_bool4 stdmath_byte4_less_than(stdmath_byte4 a, stdmath_byte4 b);
stdmath_bool4 stdmath_byte4_less_than_or_equal_to(stdmath_byte4 a, stdmath_byte4 b);
stdmath_bool4 stdmath_byte4_greater_than(stdmath_byte4 a, stdmath_byte4 b);
stdmath_bool4 stdmath_byte4_greater_than_or_equal_to(stdmath_byte4 a, stdmath_byte4 b);

uint8_t stdmath_byte4_length_squared(stdmath_byte4 v);
uint8_t stdmath_byte4_length(stdmath_byte4 v);
uint8_t stdmath_byte4_dot(stdmath_byte4 v);
uint8_t stdmath_byte4_min_element(stdmath_byte4 v);
uint8_t stdmath_byte4_max_element(stdmath_byte4 v);

stdmath_byte4 stdmath_byte4_elementwise_transform(stdmath_byte4 v, uint8_t(*func)(uint8_t));
// uint8_t stdmath_byte4_reduce_elements(stdmath_byte4 v, uint8_t initial_value, uint8_t(*reducer)(stdmath_byte4, stdmath_byte4));

#if 4 == 3
stdmath_byte3 stdmath_byte3_cross(stdmath_byte3 a, stdmath_byte3 b);
#endif

stdmath_byte4 stdmath_byte4_min(stdmath_byte4 a, stdmath_byte4 b);
stdmath_byte4 stdmath_byte4_max(stdmath_byte4 a, stdmath_byte4 b);
stdmath_byte4 stdmath_byte4_normalize(stdmath_byte4 v);
stdmath_byte4 stdmath_byte4_lerp(stdmath_byte4 a, stdmath_byte4 b, float t);
stdmath_byte4 stdmath_byte4_clamp(stdmath_byte4 a, stdmath_byte4 min, stdmath_byte4 max);
stdmath_byte4 stdmath_byte4_reflect(stdmath_byte4 a, stdmath_byte4 b);
stdmath_bool4 stdmath_byte4_approximately_equal(stdmath_byte4 a, stdmath_byte4 b);

#if false
bool stdmath_bool4_all_of(stdmath_bool4 v);
bool stdmath_bool4_any_of(stdmath_bool4 v);
bool stdmath_bool4_none_of(stdmath_bool4 v);
bool stdmath_bool4_some_of(stdmath_bool4 v);
#endif

inline static stdmath_byte1 stdmath_byte4_x(stdmath_byte4 v) { return {v.x}; }
inline static stdmath_byte4 stdmath_byte4_x_value(stdmath_byte4 v, stdmath_byte1 value) { v.x = value.x; return v; }
inline static stdmath_byte1 stdmath_byte4_y(stdmath_byte4 v) { return {v.y}; }
inline static stdmath_byte4 stdmath_byte4_y_value(stdmath_byte4 v, stdmath_byte1 value) { v.y = value.x; return v; }
inline static stdmath_byte1 stdmath_byte4_z(stdmath_byte4 v) { return {v.z}; }
inline static stdmath_byte4 stdmath_byte4_z_value(stdmath_byte4 v, stdmath_byte1 value) { v.z = value.x; return v; }
inline static stdmath_byte1 stdmath_byte4_w(stdmath_byte4 v) { return {v.w}; }
inline static stdmath_byte4 stdmath_byte4_w_value(stdmath_byte4 v, stdmath_byte1 value) { v.w = value.x; return v; }
inline static stdmath_byte2 stdmath_byte4_xx(stdmath_byte4 v) { return {v.x,v.x}; }
inline static stdmath_byte4 stdmath_byte4_xx_value(stdmath_byte4 v, stdmath_byte2 value) { v.x = value.x; v.x = value.y; return v; }
inline static stdmath_byte2 stdmath_byte4_xy(stdmath_byte4 v) { return {v.x,v.y}; }
inline static stdmath_byte4 stdmath_byte4_xy_value(stdmath_byte4 v, stdmath_byte2 value) { v.x = value.x; v.y = value.y; return v; }
inline static stdmath_byte2 stdmath_byte4_xz(stdmath_byte4 v) { return {v.x,v.z}; }
inline static stdmath_byte4 stdmath_byte4_xz_value(stdmath_byte4 v, stdmath_byte2 value) { v.x = value.x; v.z = value.y; return v; }
inline static stdmath_byte2 stdmath_byte4_xw(stdmath_byte4 v) { return {v.x,v.w}; }
inline static stdmath_byte4 stdmath_byte4_xw_value(stdmath_byte4 v, stdmath_byte2 value) { v.x = value.x; v.w = value.y; return v; }
inline static stdmath_byte2 stdmath_byte4_yx(stdmath_byte4 v) { return {v.y,v.x}; }
inline static stdmath_byte4 stdmath_byte4_yx_value(stdmath_byte4 v, stdmath_byte2 value) { v.y = value.x; v.x = value.y; return v; }
inline static stdmath_byte2 stdmath_byte4_yy(stdmath_byte4 v) { return {v.y,v.y}; }
inline static stdmath_byte4 stdmath_byte4_yy_value(stdmath_byte4 v, stdmath_byte2 value) { v.y = value.x; v.y = value.y; return v; }
inline static stdmath_byte2 stdmath_byte4_yz(stdmath_byte4 v) { return {v.y,v.z}; }
inline static stdmath_byte4 stdmath_byte4_yz_value(stdmath_byte4 v, stdmath_byte2 value) { v.y = value.x; v.z = value.y; return v; }
inline static stdmath_byte2 stdmath_byte4_yw(stdmath_byte4 v) { return {v.y,v.w}; }
inline static stdmath_byte4 stdmath_byte4_yw_value(stdmath_byte4 v, stdmath_byte2 value) { v.y = value.x; v.w = value.y; return v; }
inline static stdmath_byte2 stdmath_byte4_zx(stdmath_byte4 v) { return {v.z,v.x}; }
inline static stdmath_byte4 stdmath_byte4_zx_value(stdmath_byte4 v, stdmath_byte2 value) { v.z = value.x; v.x = value.y; return v; }
inline static stdmath_byte2 stdmath_byte4_zy(stdmath_byte4 v) { return {v.z,v.y}; }
inline static stdmath_byte4 stdmath_byte4_zy_value(stdmath_byte4 v, stdmath_byte2 value) { v.z = value.x; v.y = value.y; return v; }
inline static stdmath_byte2 stdmath_byte4_zz(stdmath_byte4 v) { return {v.z,v.z}; }
inline static stdmath_byte4 stdmath_byte4_zz_value(stdmath_byte4 v, stdmath_byte2 value) { v.z = value.x; v.z = value.y; return v; }
inline static stdmath_byte2 stdmath_byte4_zw(stdmath_byte4 v) { return {v.z,v.w}; }
inline static stdmath_byte4 stdmath_byte4_zw_value(stdmath_byte4 v, stdmath_byte2 value) { v.z = value.x; v.w = value.y; return v; }
inline static stdmath_byte2 stdmath_byte4_wx(stdmath_byte4 v) { return {v.w,v.x}; }
inline static stdmath_byte4 stdmath_byte4_wx_value(stdmath_byte4 v, stdmath_byte2 value) { v.w = value.x; v.x = value.y; return v; }
inline static stdmath_byte2 stdmath_byte4_wy(stdmath_byte4 v) { return {v.w,v.y}; }
inline static stdmath_byte4 stdmath_byte4_wy_value(stdmath_byte4 v, stdmath_byte2 value) { v.w = value.x; v.y = value.y; return v; }
inline static stdmath_byte2 stdmath_byte4_wz(stdmath_byte4 v) { return {v.w,v.z}; }
inline static stdmath_byte4 stdmath_byte4_wz_value(stdmath_byte4 v, stdmath_byte2 value) { v.w = value.x; v.z = value.y; return v; }
inline static stdmath_byte2 stdmath_byte4_ww(stdmath_byte4 v) { return {v.w,v.w}; }
inline static stdmath_byte4 stdmath_byte4_ww_value(stdmath_byte4 v, stdmath_byte2 value) { v.w = value.x; v.w = value.y; return v; }
inline static stdmath_byte3 stdmath_byte4_xxx(stdmath_byte4 v) { return {v.x,v.x,v.x}; }
inline static stdmath_byte4 stdmath_byte4_xxx_value(stdmath_byte4 v, stdmath_byte3 value) { v.x = value.x; v.x = value.y; v.x = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_xxy(stdmath_byte4 v) { return {v.x,v.x,v.y}; }
inline static stdmath_byte4 stdmath_byte4_xxy_value(stdmath_byte4 v, stdmath_byte3 value) { v.x = value.x; v.x = value.y; v.y = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_xxz(stdmath_byte4 v) { return {v.x,v.x,v.z}; }
inline static stdmath_byte4 stdmath_byte4_xxz_value(stdmath_byte4 v, stdmath_byte3 value) { v.x = value.x; v.x = value.y; v.z = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_xxw(stdmath_byte4 v) { return {v.x,v.x,v.w}; }
inline static stdmath_byte4 stdmath_byte4_xxw_value(stdmath_byte4 v, stdmath_byte3 value) { v.x = value.x; v.x = value.y; v.w = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_xyx(stdmath_byte4 v) { return {v.x,v.y,v.x}; }
inline static stdmath_byte4 stdmath_byte4_xyx_value(stdmath_byte4 v, stdmath_byte3 value) { v.x = value.x; v.y = value.y; v.x = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_xyy(stdmath_byte4 v) { return {v.x,v.y,v.y}; }
inline static stdmath_byte4 stdmath_byte4_xyy_value(stdmath_byte4 v, stdmath_byte3 value) { v.x = value.x; v.y = value.y; v.y = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_xyz(stdmath_byte4 v) { return {v.x,v.y,v.z}; }
inline static stdmath_byte4 stdmath_byte4_xyz_value(stdmath_byte4 v, stdmath_byte3 value) { v.x = value.x; v.y = value.y; v.z = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_xyw(stdmath_byte4 v) { return {v.x,v.y,v.w}; }
inline static stdmath_byte4 stdmath_byte4_xyw_value(stdmath_byte4 v, stdmath_byte3 value) { v.x = value.x; v.y = value.y; v.w = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_xzx(stdmath_byte4 v) { return {v.x,v.z,v.x}; }
inline static stdmath_byte4 stdmath_byte4_xzx_value(stdmath_byte4 v, stdmath_byte3 value) { v.x = value.x; v.z = value.y; v.x = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_xzy(stdmath_byte4 v) { return {v.x,v.z,v.y}; }
inline static stdmath_byte4 stdmath_byte4_xzy_value(stdmath_byte4 v, stdmath_byte3 value) { v.x = value.x; v.z = value.y; v.y = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_xzz(stdmath_byte4 v) { return {v.x,v.z,v.z}; }
inline static stdmath_byte4 stdmath_byte4_xzz_value(stdmath_byte4 v, stdmath_byte3 value) { v.x = value.x; v.z = value.y; v.z = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_xzw(stdmath_byte4 v) { return {v.x,v.z,v.w}; }
inline static stdmath_byte4 stdmath_byte4_xzw_value(stdmath_byte4 v, stdmath_byte3 value) { v.x = value.x; v.z = value.y; v.w = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_xwx(stdmath_byte4 v) { return {v.x,v.w,v.x}; }
inline static stdmath_byte4 stdmath_byte4_xwx_value(stdmath_byte4 v, stdmath_byte3 value) { v.x = value.x; v.w = value.y; v.x = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_xwy(stdmath_byte4 v) { return {v.x,v.w,v.y}; }
inline static stdmath_byte4 stdmath_byte4_xwy_value(stdmath_byte4 v, stdmath_byte3 value) { v.x = value.x; v.w = value.y; v.y = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_xwz(stdmath_byte4 v) { return {v.x,v.w,v.z}; }
inline static stdmath_byte4 stdmath_byte4_xwz_value(stdmath_byte4 v, stdmath_byte3 value) { v.x = value.x; v.w = value.y; v.z = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_xww(stdmath_byte4 v) { return {v.x,v.w,v.w}; }
inline static stdmath_byte4 stdmath_byte4_xww_value(stdmath_byte4 v, stdmath_byte3 value) { v.x = value.x; v.w = value.y; v.w = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_yxx(stdmath_byte4 v) { return {v.y,v.x,v.x}; }
inline static stdmath_byte4 stdmath_byte4_yxx_value(stdmath_byte4 v, stdmath_byte3 value) { v.y = value.x; v.x = value.y; v.x = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_yxy(stdmath_byte4 v) { return {v.y,v.x,v.y}; }
inline static stdmath_byte4 stdmath_byte4_yxy_value(stdmath_byte4 v, stdmath_byte3 value) { v.y = value.x; v.x = value.y; v.y = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_yxz(stdmath_byte4 v) { return {v.y,v.x,v.z}; }
inline static stdmath_byte4 stdmath_byte4_yxz_value(stdmath_byte4 v, stdmath_byte3 value) { v.y = value.x; v.x = value.y; v.z = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_yxw(stdmath_byte4 v) { return {v.y,v.x,v.w}; }
inline static stdmath_byte4 stdmath_byte4_yxw_value(stdmath_byte4 v, stdmath_byte3 value) { v.y = value.x; v.x = value.y; v.w = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_yyx(stdmath_byte4 v) { return {v.y,v.y,v.x}; }
inline static stdmath_byte4 stdmath_byte4_yyx_value(stdmath_byte4 v, stdmath_byte3 value) { v.y = value.x; v.y = value.y; v.x = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_yyy(stdmath_byte4 v) { return {v.y,v.y,v.y}; }
inline static stdmath_byte4 stdmath_byte4_yyy_value(stdmath_byte4 v, stdmath_byte3 value) { v.y = value.x; v.y = value.y; v.y = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_yyz(stdmath_byte4 v) { return {v.y,v.y,v.z}; }
inline static stdmath_byte4 stdmath_byte4_yyz_value(stdmath_byte4 v, stdmath_byte3 value) { v.y = value.x; v.y = value.y; v.z = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_yyw(stdmath_byte4 v) { return {v.y,v.y,v.w}; }
inline static stdmath_byte4 stdmath_byte4_yyw_value(stdmath_byte4 v, stdmath_byte3 value) { v.y = value.x; v.y = value.y; v.w = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_yzx(stdmath_byte4 v) { return {v.y,v.z,v.x}; }
inline static stdmath_byte4 stdmath_byte4_yzx_value(stdmath_byte4 v, stdmath_byte3 value) { v.y = value.x; v.z = value.y; v.x = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_yzy(stdmath_byte4 v) { return {v.y,v.z,v.y}; }
inline static stdmath_byte4 stdmath_byte4_yzy_value(stdmath_byte4 v, stdmath_byte3 value) { v.y = value.x; v.z = value.y; v.y = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_yzz(stdmath_byte4 v) { return {v.y,v.z,v.z}; }
inline static stdmath_byte4 stdmath_byte4_yzz_value(stdmath_byte4 v, stdmath_byte3 value) { v.y = value.x; v.z = value.y; v.z = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_yzw(stdmath_byte4 v) { return {v.y,v.z,v.w}; }
inline static stdmath_byte4 stdmath_byte4_yzw_value(stdmath_byte4 v, stdmath_byte3 value) { v.y = value.x; v.z = value.y; v.w = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_ywx(stdmath_byte4 v) { return {v.y,v.w,v.x}; }
inline static stdmath_byte4 stdmath_byte4_ywx_value(stdmath_byte4 v, stdmath_byte3 value) { v.y = value.x; v.w = value.y; v.x = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_ywy(stdmath_byte4 v) { return {v.y,v.w,v.y}; }
inline static stdmath_byte4 stdmath_byte4_ywy_value(stdmath_byte4 v, stdmath_byte3 value) { v.y = value.x; v.w = value.y; v.y = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_ywz(stdmath_byte4 v) { return {v.y,v.w,v.z}; }
inline static stdmath_byte4 stdmath_byte4_ywz_value(stdmath_byte4 v, stdmath_byte3 value) { v.y = value.x; v.w = value.y; v.z = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_yww(stdmath_byte4 v) { return {v.y,v.w,v.w}; }
inline static stdmath_byte4 stdmath_byte4_yww_value(stdmath_byte4 v, stdmath_byte3 value) { v.y = value.x; v.w = value.y; v.w = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_zxx(stdmath_byte4 v) { return {v.z,v.x,v.x}; }
inline static stdmath_byte4 stdmath_byte4_zxx_value(stdmath_byte4 v, stdmath_byte3 value) { v.z = value.x; v.x = value.y; v.x = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_zxy(stdmath_byte4 v) { return {v.z,v.x,v.y}; }
inline static stdmath_byte4 stdmath_byte4_zxy_value(stdmath_byte4 v, stdmath_byte3 value) { v.z = value.x; v.x = value.y; v.y = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_zxz(stdmath_byte4 v) { return {v.z,v.x,v.z}; }
inline static stdmath_byte4 stdmath_byte4_zxz_value(stdmath_byte4 v, stdmath_byte3 value) { v.z = value.x; v.x = value.y; v.z = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_zxw(stdmath_byte4 v) { return {v.z,v.x,v.w}; }
inline static stdmath_byte4 stdmath_byte4_zxw_value(stdmath_byte4 v, stdmath_byte3 value) { v.z = value.x; v.x = value.y; v.w = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_zyx(stdmath_byte4 v) { return {v.z,v.y,v.x}; }
inline static stdmath_byte4 stdmath_byte4_zyx_value(stdmath_byte4 v, stdmath_byte3 value) { v.z = value.x; v.y = value.y; v.x = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_zyy(stdmath_byte4 v) { return {v.z,v.y,v.y}; }
inline static stdmath_byte4 stdmath_byte4_zyy_value(stdmath_byte4 v, stdmath_byte3 value) { v.z = value.x; v.y = value.y; v.y = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_zyz(stdmath_byte4 v) { return {v.z,v.y,v.z}; }
inline static stdmath_byte4 stdmath_byte4_zyz_value(stdmath_byte4 v, stdmath_byte3 value) { v.z = value.x; v.y = value.y; v.z = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_zyw(stdmath_byte4 v) { return {v.z,v.y,v.w}; }
inline static stdmath_byte4 stdmath_byte4_zyw_value(stdmath_byte4 v, stdmath_byte3 value) { v.z = value.x; v.y = value.y; v.w = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_zzx(stdmath_byte4 v) { return {v.z,v.z,v.x}; }
inline static stdmath_byte4 stdmath_byte4_zzx_value(stdmath_byte4 v, stdmath_byte3 value) { v.z = value.x; v.z = value.y; v.x = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_zzy(stdmath_byte4 v) { return {v.z,v.z,v.y}; }
inline static stdmath_byte4 stdmath_byte4_zzy_value(stdmath_byte4 v, stdmath_byte3 value) { v.z = value.x; v.z = value.y; v.y = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_zzz(stdmath_byte4 v) { return {v.z,v.z,v.z}; }
inline static stdmath_byte4 stdmath_byte4_zzz_value(stdmath_byte4 v, stdmath_byte3 value) { v.z = value.x; v.z = value.y; v.z = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_zzw(stdmath_byte4 v) { return {v.z,v.z,v.w}; }
inline static stdmath_byte4 stdmath_byte4_zzw_value(stdmath_byte4 v, stdmath_byte3 value) { v.z = value.x; v.z = value.y; v.w = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_zwx(stdmath_byte4 v) { return {v.z,v.w,v.x}; }
inline static stdmath_byte4 stdmath_byte4_zwx_value(stdmath_byte4 v, stdmath_byte3 value) { v.z = value.x; v.w = value.y; v.x = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_zwy(stdmath_byte4 v) { return {v.z,v.w,v.y}; }
inline static stdmath_byte4 stdmath_byte4_zwy_value(stdmath_byte4 v, stdmath_byte3 value) { v.z = value.x; v.w = value.y; v.y = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_zwz(stdmath_byte4 v) { return {v.z,v.w,v.z}; }
inline static stdmath_byte4 stdmath_byte4_zwz_value(stdmath_byte4 v, stdmath_byte3 value) { v.z = value.x; v.w = value.y; v.z = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_zww(stdmath_byte4 v) { return {v.z,v.w,v.w}; }
inline static stdmath_byte4 stdmath_byte4_zww_value(stdmath_byte4 v, stdmath_byte3 value) { v.z = value.x; v.w = value.y; v.w = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_wxx(stdmath_byte4 v) { return {v.w,v.x,v.x}; }
inline static stdmath_byte4 stdmath_byte4_wxx_value(stdmath_byte4 v, stdmath_byte3 value) { v.w = value.x; v.x = value.y; v.x = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_wxy(stdmath_byte4 v) { return {v.w,v.x,v.y}; }
inline static stdmath_byte4 stdmath_byte4_wxy_value(stdmath_byte4 v, stdmath_byte3 value) { v.w = value.x; v.x = value.y; v.y = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_wxz(stdmath_byte4 v) { return {v.w,v.x,v.z}; }
inline static stdmath_byte4 stdmath_byte4_wxz_value(stdmath_byte4 v, stdmath_byte3 value) { v.w = value.x; v.x = value.y; v.z = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_wxw(stdmath_byte4 v) { return {v.w,v.x,v.w}; }
inline static stdmath_byte4 stdmath_byte4_wxw_value(stdmath_byte4 v, stdmath_byte3 value) { v.w = value.x; v.x = value.y; v.w = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_wyx(stdmath_byte4 v) { return {v.w,v.y,v.x}; }
inline static stdmath_byte4 stdmath_byte4_wyx_value(stdmath_byte4 v, stdmath_byte3 value) { v.w = value.x; v.y = value.y; v.x = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_wyy(stdmath_byte4 v) { return {v.w,v.y,v.y}; }
inline static stdmath_byte4 stdmath_byte4_wyy_value(stdmath_byte4 v, stdmath_byte3 value) { v.w = value.x; v.y = value.y; v.y = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_wyz(stdmath_byte4 v) { return {v.w,v.y,v.z}; }
inline static stdmath_byte4 stdmath_byte4_wyz_value(stdmath_byte4 v, stdmath_byte3 value) { v.w = value.x; v.y = value.y; v.z = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_wyw(stdmath_byte4 v) { return {v.w,v.y,v.w}; }
inline static stdmath_byte4 stdmath_byte4_wyw_value(stdmath_byte4 v, stdmath_byte3 value) { v.w = value.x; v.y = value.y; v.w = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_wzx(stdmath_byte4 v) { return {v.w,v.z,v.x}; }
inline static stdmath_byte4 stdmath_byte4_wzx_value(stdmath_byte4 v, stdmath_byte3 value) { v.w = value.x; v.z = value.y; v.x = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_wzy(stdmath_byte4 v) { return {v.w,v.z,v.y}; }
inline static stdmath_byte4 stdmath_byte4_wzy_value(stdmath_byte4 v, stdmath_byte3 value) { v.w = value.x; v.z = value.y; v.y = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_wzz(stdmath_byte4 v) { return {v.w,v.z,v.z}; }
inline static stdmath_byte4 stdmath_byte4_wzz_value(stdmath_byte4 v, stdmath_byte3 value) { v.w = value.x; v.z = value.y; v.z = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_wzw(stdmath_byte4 v) { return {v.w,v.z,v.w}; }
inline static stdmath_byte4 stdmath_byte4_wzw_value(stdmath_byte4 v, stdmath_byte3 value) { v.w = value.x; v.z = value.y; v.w = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_wwx(stdmath_byte4 v) { return {v.w,v.w,v.x}; }
inline static stdmath_byte4 stdmath_byte4_wwx_value(stdmath_byte4 v, stdmath_byte3 value) { v.w = value.x; v.w = value.y; v.x = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_wwy(stdmath_byte4 v) { return {v.w,v.w,v.y}; }
inline static stdmath_byte4 stdmath_byte4_wwy_value(stdmath_byte4 v, stdmath_byte3 value) { v.w = value.x; v.w = value.y; v.y = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_wwz(stdmath_byte4 v) { return {v.w,v.w,v.z}; }
inline static stdmath_byte4 stdmath_byte4_wwz_value(stdmath_byte4 v, stdmath_byte3 value) { v.w = value.x; v.w = value.y; v.z = value.z; return v; }
inline static stdmath_byte3 stdmath_byte4_www(stdmath_byte4 v) { return {v.w,v.w,v.w}; }
inline static stdmath_byte4 stdmath_byte4_www_value(stdmath_byte4 v, stdmath_byte3 value) { v.w = value.x; v.w = value.y; v.w = value.z; return v; }
inline static stdmath_byte4 stdmath_byte4_xxxx(stdmath_byte4 v) { return {v.x,v.x,v.x,v.x}; }
inline static stdmath_byte4 stdmath_byte4_xxxx_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.x = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xxxy(stdmath_byte4 v) { return {v.x,v.x,v.x,v.y}; }
inline static stdmath_byte4 stdmath_byte4_xxxy_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.x = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xxxz(stdmath_byte4 v) { return {v.x,v.x,v.x,v.z}; }
inline static stdmath_byte4 stdmath_byte4_xxxz_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.x = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xxxw(stdmath_byte4 v) { return {v.x,v.x,v.x,v.w}; }
inline static stdmath_byte4 stdmath_byte4_xxxw_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.x = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xxyx(stdmath_byte4 v) { return {v.x,v.x,v.y,v.x}; }
inline static stdmath_byte4 stdmath_byte4_xxyx_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.x = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xxyy(stdmath_byte4 v) { return {v.x,v.x,v.y,v.y}; }
inline static stdmath_byte4 stdmath_byte4_xxyy_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.x = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xxyz(stdmath_byte4 v) { return {v.x,v.x,v.y,v.z}; }
inline static stdmath_byte4 stdmath_byte4_xxyz_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.x = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xxyw(stdmath_byte4 v) { return {v.x,v.x,v.y,v.w}; }
inline static stdmath_byte4 stdmath_byte4_xxyw_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.x = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xxzx(stdmath_byte4 v) { return {v.x,v.x,v.z,v.x}; }
inline static stdmath_byte4 stdmath_byte4_xxzx_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.x = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xxzy(stdmath_byte4 v) { return {v.x,v.x,v.z,v.y}; }
inline static stdmath_byte4 stdmath_byte4_xxzy_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.x = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xxzz(stdmath_byte4 v) { return {v.x,v.x,v.z,v.z}; }
inline static stdmath_byte4 stdmath_byte4_xxzz_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.x = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xxzw(stdmath_byte4 v) { return {v.x,v.x,v.z,v.w}; }
inline static stdmath_byte4 stdmath_byte4_xxzw_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.x = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xxwx(stdmath_byte4 v) { return {v.x,v.x,v.w,v.x}; }
inline static stdmath_byte4 stdmath_byte4_xxwx_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.x = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xxwy(stdmath_byte4 v) { return {v.x,v.x,v.w,v.y}; }
inline static stdmath_byte4 stdmath_byte4_xxwy_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.x = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xxwz(stdmath_byte4 v) { return {v.x,v.x,v.w,v.z}; }
inline static stdmath_byte4 stdmath_byte4_xxwz_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.x = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xxww(stdmath_byte4 v) { return {v.x,v.x,v.w,v.w}; }
inline static stdmath_byte4 stdmath_byte4_xxww_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.x = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xyxx(stdmath_byte4 v) { return {v.x,v.y,v.x,v.x}; }
inline static stdmath_byte4 stdmath_byte4_xyxx_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.y = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xyxy(stdmath_byte4 v) { return {v.x,v.y,v.x,v.y}; }
inline static stdmath_byte4 stdmath_byte4_xyxy_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.y = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xyxz(stdmath_byte4 v) { return {v.x,v.y,v.x,v.z}; }
inline static stdmath_byte4 stdmath_byte4_xyxz_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.y = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xyxw(stdmath_byte4 v) { return {v.x,v.y,v.x,v.w}; }
inline static stdmath_byte4 stdmath_byte4_xyxw_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.y = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xyyx(stdmath_byte4 v) { return {v.x,v.y,v.y,v.x}; }
inline static stdmath_byte4 stdmath_byte4_xyyx_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.y = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xyyy(stdmath_byte4 v) { return {v.x,v.y,v.y,v.y}; }
inline static stdmath_byte4 stdmath_byte4_xyyy_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.y = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xyyz(stdmath_byte4 v) { return {v.x,v.y,v.y,v.z}; }
inline static stdmath_byte4 stdmath_byte4_xyyz_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.y = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xyyw(stdmath_byte4 v) { return {v.x,v.y,v.y,v.w}; }
inline static stdmath_byte4 stdmath_byte4_xyyw_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.y = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xyzx(stdmath_byte4 v) { return {v.x,v.y,v.z,v.x}; }
inline static stdmath_byte4 stdmath_byte4_xyzx_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.y = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xyzy(stdmath_byte4 v) { return {v.x,v.y,v.z,v.y}; }
inline static stdmath_byte4 stdmath_byte4_xyzy_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.y = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xyzz(stdmath_byte4 v) { return {v.x,v.y,v.z,v.z}; }
inline static stdmath_byte4 stdmath_byte4_xyzz_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.y = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xyzw(stdmath_byte4 v) { return {v.x,v.y,v.z,v.w}; }
inline static stdmath_byte4 stdmath_byte4_xyzw_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.y = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xywx(stdmath_byte4 v) { return {v.x,v.y,v.w,v.x}; }
inline static stdmath_byte4 stdmath_byte4_xywx_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.y = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xywy(stdmath_byte4 v) { return {v.x,v.y,v.w,v.y}; }
inline static stdmath_byte4 stdmath_byte4_xywy_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.y = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xywz(stdmath_byte4 v) { return {v.x,v.y,v.w,v.z}; }
inline static stdmath_byte4 stdmath_byte4_xywz_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.y = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xyww(stdmath_byte4 v) { return {v.x,v.y,v.w,v.w}; }
inline static stdmath_byte4 stdmath_byte4_xyww_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.y = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xzxx(stdmath_byte4 v) { return {v.x,v.z,v.x,v.x}; }
inline static stdmath_byte4 stdmath_byte4_xzxx_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.z = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xzxy(stdmath_byte4 v) { return {v.x,v.z,v.x,v.y}; }
inline static stdmath_byte4 stdmath_byte4_xzxy_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.z = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xzxz(stdmath_byte4 v) { return {v.x,v.z,v.x,v.z}; }
inline static stdmath_byte4 stdmath_byte4_xzxz_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.z = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xzxw(stdmath_byte4 v) { return {v.x,v.z,v.x,v.w}; }
inline static stdmath_byte4 stdmath_byte4_xzxw_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.z = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xzyx(stdmath_byte4 v) { return {v.x,v.z,v.y,v.x}; }
inline static stdmath_byte4 stdmath_byte4_xzyx_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.z = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xzyy(stdmath_byte4 v) { return {v.x,v.z,v.y,v.y}; }
inline static stdmath_byte4 stdmath_byte4_xzyy_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.z = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xzyz(stdmath_byte4 v) { return {v.x,v.z,v.y,v.z}; }
inline static stdmath_byte4 stdmath_byte4_xzyz_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.z = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xzyw(stdmath_byte4 v) { return {v.x,v.z,v.y,v.w}; }
inline static stdmath_byte4 stdmath_byte4_xzyw_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.z = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xzzx(stdmath_byte4 v) { return {v.x,v.z,v.z,v.x}; }
inline static stdmath_byte4 stdmath_byte4_xzzx_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.z = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xzzy(stdmath_byte4 v) { return {v.x,v.z,v.z,v.y}; }
inline static stdmath_byte4 stdmath_byte4_xzzy_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.z = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xzzz(stdmath_byte4 v) { return {v.x,v.z,v.z,v.z}; }
inline static stdmath_byte4 stdmath_byte4_xzzz_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.z = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xzzw(stdmath_byte4 v) { return {v.x,v.z,v.z,v.w}; }
inline static stdmath_byte4 stdmath_byte4_xzzw_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.z = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xzwx(stdmath_byte4 v) { return {v.x,v.z,v.w,v.x}; }
inline static stdmath_byte4 stdmath_byte4_xzwx_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.z = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xzwy(stdmath_byte4 v) { return {v.x,v.z,v.w,v.y}; }
inline static stdmath_byte4 stdmath_byte4_xzwy_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.z = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xzwz(stdmath_byte4 v) { return {v.x,v.z,v.w,v.z}; }
inline static stdmath_byte4 stdmath_byte4_xzwz_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.z = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xzww(stdmath_byte4 v) { return {v.x,v.z,v.w,v.w}; }
inline static stdmath_byte4 stdmath_byte4_xzww_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.z = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xwxx(stdmath_byte4 v) { return {v.x,v.w,v.x,v.x}; }
inline static stdmath_byte4 stdmath_byte4_xwxx_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.w = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xwxy(stdmath_byte4 v) { return {v.x,v.w,v.x,v.y}; }
inline static stdmath_byte4 stdmath_byte4_xwxy_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.w = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xwxz(stdmath_byte4 v) { return {v.x,v.w,v.x,v.z}; }
inline static stdmath_byte4 stdmath_byte4_xwxz_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.w = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xwxw(stdmath_byte4 v) { return {v.x,v.w,v.x,v.w}; }
inline static stdmath_byte4 stdmath_byte4_xwxw_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.w = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xwyx(stdmath_byte4 v) { return {v.x,v.w,v.y,v.x}; }
inline static stdmath_byte4 stdmath_byte4_xwyx_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.w = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xwyy(stdmath_byte4 v) { return {v.x,v.w,v.y,v.y}; }
inline static stdmath_byte4 stdmath_byte4_xwyy_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.w = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xwyz(stdmath_byte4 v) { return {v.x,v.w,v.y,v.z}; }
inline static stdmath_byte4 stdmath_byte4_xwyz_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.w = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xwyw(stdmath_byte4 v) { return {v.x,v.w,v.y,v.w}; }
inline static stdmath_byte4 stdmath_byte4_xwyw_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.w = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xwzx(stdmath_byte4 v) { return {v.x,v.w,v.z,v.x}; }
inline static stdmath_byte4 stdmath_byte4_xwzx_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.w = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xwzy(stdmath_byte4 v) { return {v.x,v.w,v.z,v.y}; }
inline static stdmath_byte4 stdmath_byte4_xwzy_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.w = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xwzz(stdmath_byte4 v) { return {v.x,v.w,v.z,v.z}; }
inline static stdmath_byte4 stdmath_byte4_xwzz_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.w = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xwzw(stdmath_byte4 v) { return {v.x,v.w,v.z,v.w}; }
inline static stdmath_byte4 stdmath_byte4_xwzw_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.w = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xwwx(stdmath_byte4 v) { return {v.x,v.w,v.w,v.x}; }
inline static stdmath_byte4 stdmath_byte4_xwwx_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.w = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xwwy(stdmath_byte4 v) { return {v.x,v.w,v.w,v.y}; }
inline static stdmath_byte4 stdmath_byte4_xwwy_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.w = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xwwz(stdmath_byte4 v) { return {v.x,v.w,v.w,v.z}; }
inline static stdmath_byte4 stdmath_byte4_xwwz_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.w = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_xwww(stdmath_byte4 v) { return {v.x,v.w,v.w,v.w}; }
inline static stdmath_byte4 stdmath_byte4_xwww_value(stdmath_byte4 v, stdmath_byte4 value) { v.x = value.x; v.w = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_yxxx(stdmath_byte4 v) { return {v.y,v.x,v.x,v.x}; }
inline static stdmath_byte4 stdmath_byte4_yxxx_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.x = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_yxxy(stdmath_byte4 v) { return {v.y,v.x,v.x,v.y}; }
inline static stdmath_byte4 stdmath_byte4_yxxy_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.x = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_yxxz(stdmath_byte4 v) { return {v.y,v.x,v.x,v.z}; }
inline static stdmath_byte4 stdmath_byte4_yxxz_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.x = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_yxxw(stdmath_byte4 v) { return {v.y,v.x,v.x,v.w}; }
inline static stdmath_byte4 stdmath_byte4_yxxw_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.x = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_yxyx(stdmath_byte4 v) { return {v.y,v.x,v.y,v.x}; }
inline static stdmath_byte4 stdmath_byte4_yxyx_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.x = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_yxyy(stdmath_byte4 v) { return {v.y,v.x,v.y,v.y}; }
inline static stdmath_byte4 stdmath_byte4_yxyy_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.x = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_yxyz(stdmath_byte4 v) { return {v.y,v.x,v.y,v.z}; }
inline static stdmath_byte4 stdmath_byte4_yxyz_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.x = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_yxyw(stdmath_byte4 v) { return {v.y,v.x,v.y,v.w}; }
inline static stdmath_byte4 stdmath_byte4_yxyw_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.x = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_yxzx(stdmath_byte4 v) { return {v.y,v.x,v.z,v.x}; }
inline static stdmath_byte4 stdmath_byte4_yxzx_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.x = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_yxzy(stdmath_byte4 v) { return {v.y,v.x,v.z,v.y}; }
inline static stdmath_byte4 stdmath_byte4_yxzy_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.x = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_yxzz(stdmath_byte4 v) { return {v.y,v.x,v.z,v.z}; }
inline static stdmath_byte4 stdmath_byte4_yxzz_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.x = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_yxzw(stdmath_byte4 v) { return {v.y,v.x,v.z,v.w}; }
inline static stdmath_byte4 stdmath_byte4_yxzw_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.x = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_yxwx(stdmath_byte4 v) { return {v.y,v.x,v.w,v.x}; }
inline static stdmath_byte4 stdmath_byte4_yxwx_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.x = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_yxwy(stdmath_byte4 v) { return {v.y,v.x,v.w,v.y}; }
inline static stdmath_byte4 stdmath_byte4_yxwy_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.x = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_yxwz(stdmath_byte4 v) { return {v.y,v.x,v.w,v.z}; }
inline static stdmath_byte4 stdmath_byte4_yxwz_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.x = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_yxww(stdmath_byte4 v) { return {v.y,v.x,v.w,v.w}; }
inline static stdmath_byte4 stdmath_byte4_yxww_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.x = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_yyxx(stdmath_byte4 v) { return {v.y,v.y,v.x,v.x}; }
inline static stdmath_byte4 stdmath_byte4_yyxx_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.y = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_yyxy(stdmath_byte4 v) { return {v.y,v.y,v.x,v.y}; }
inline static stdmath_byte4 stdmath_byte4_yyxy_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.y = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_yyxz(stdmath_byte4 v) { return {v.y,v.y,v.x,v.z}; }
inline static stdmath_byte4 stdmath_byte4_yyxz_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.y = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_yyxw(stdmath_byte4 v) { return {v.y,v.y,v.x,v.w}; }
inline static stdmath_byte4 stdmath_byte4_yyxw_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.y = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_yyyx(stdmath_byte4 v) { return {v.y,v.y,v.y,v.x}; }
inline static stdmath_byte4 stdmath_byte4_yyyx_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.y = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_yyyy(stdmath_byte4 v) { return {v.y,v.y,v.y,v.y}; }
inline static stdmath_byte4 stdmath_byte4_yyyy_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.y = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_yyyz(stdmath_byte4 v) { return {v.y,v.y,v.y,v.z}; }
inline static stdmath_byte4 stdmath_byte4_yyyz_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.y = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_yyyw(stdmath_byte4 v) { return {v.y,v.y,v.y,v.w}; }
inline static stdmath_byte4 stdmath_byte4_yyyw_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.y = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_yyzx(stdmath_byte4 v) { return {v.y,v.y,v.z,v.x}; }
inline static stdmath_byte4 stdmath_byte4_yyzx_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.y = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_yyzy(stdmath_byte4 v) { return {v.y,v.y,v.z,v.y}; }
inline static stdmath_byte4 stdmath_byte4_yyzy_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.y = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_yyzz(stdmath_byte4 v) { return {v.y,v.y,v.z,v.z}; }
inline static stdmath_byte4 stdmath_byte4_yyzz_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.y = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_yyzw(stdmath_byte4 v) { return {v.y,v.y,v.z,v.w}; }
inline static stdmath_byte4 stdmath_byte4_yyzw_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.y = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_yywx(stdmath_byte4 v) { return {v.y,v.y,v.w,v.x}; }
inline static stdmath_byte4 stdmath_byte4_yywx_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.y = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_yywy(stdmath_byte4 v) { return {v.y,v.y,v.w,v.y}; }
inline static stdmath_byte4 stdmath_byte4_yywy_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.y = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_yywz(stdmath_byte4 v) { return {v.y,v.y,v.w,v.z}; }
inline static stdmath_byte4 stdmath_byte4_yywz_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.y = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_yyww(stdmath_byte4 v) { return {v.y,v.y,v.w,v.w}; }
inline static stdmath_byte4 stdmath_byte4_yyww_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.y = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_yzxx(stdmath_byte4 v) { return {v.y,v.z,v.x,v.x}; }
inline static stdmath_byte4 stdmath_byte4_yzxx_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.z = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_yzxy(stdmath_byte4 v) { return {v.y,v.z,v.x,v.y}; }
inline static stdmath_byte4 stdmath_byte4_yzxy_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.z = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_yzxz(stdmath_byte4 v) { return {v.y,v.z,v.x,v.z}; }
inline static stdmath_byte4 stdmath_byte4_yzxz_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.z = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_yzxw(stdmath_byte4 v) { return {v.y,v.z,v.x,v.w}; }
inline static stdmath_byte4 stdmath_byte4_yzxw_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.z = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_yzyx(stdmath_byte4 v) { return {v.y,v.z,v.y,v.x}; }
inline static stdmath_byte4 stdmath_byte4_yzyx_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.z = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_yzyy(stdmath_byte4 v) { return {v.y,v.z,v.y,v.y}; }
inline static stdmath_byte4 stdmath_byte4_yzyy_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.z = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_yzyz(stdmath_byte4 v) { return {v.y,v.z,v.y,v.z}; }
inline static stdmath_byte4 stdmath_byte4_yzyz_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.z = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_yzyw(stdmath_byte4 v) { return {v.y,v.z,v.y,v.w}; }
inline static stdmath_byte4 stdmath_byte4_yzyw_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.z = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_yzzx(stdmath_byte4 v) { return {v.y,v.z,v.z,v.x}; }
inline static stdmath_byte4 stdmath_byte4_yzzx_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.z = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_yzzy(stdmath_byte4 v) { return {v.y,v.z,v.z,v.y}; }
inline static stdmath_byte4 stdmath_byte4_yzzy_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.z = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_yzzz(stdmath_byte4 v) { return {v.y,v.z,v.z,v.z}; }
inline static stdmath_byte4 stdmath_byte4_yzzz_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.z = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_yzzw(stdmath_byte4 v) { return {v.y,v.z,v.z,v.w}; }
inline static stdmath_byte4 stdmath_byte4_yzzw_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.z = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_yzwx(stdmath_byte4 v) { return {v.y,v.z,v.w,v.x}; }
inline static stdmath_byte4 stdmath_byte4_yzwx_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.z = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_yzwy(stdmath_byte4 v) { return {v.y,v.z,v.w,v.y}; }
inline static stdmath_byte4 stdmath_byte4_yzwy_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.z = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_yzwz(stdmath_byte4 v) { return {v.y,v.z,v.w,v.z}; }
inline static stdmath_byte4 stdmath_byte4_yzwz_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.z = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_yzww(stdmath_byte4 v) { return {v.y,v.z,v.w,v.w}; }
inline static stdmath_byte4 stdmath_byte4_yzww_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.z = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_ywxx(stdmath_byte4 v) { return {v.y,v.w,v.x,v.x}; }
inline static stdmath_byte4 stdmath_byte4_ywxx_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.w = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_ywxy(stdmath_byte4 v) { return {v.y,v.w,v.x,v.y}; }
inline static stdmath_byte4 stdmath_byte4_ywxy_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.w = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_ywxz(stdmath_byte4 v) { return {v.y,v.w,v.x,v.z}; }
inline static stdmath_byte4 stdmath_byte4_ywxz_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.w = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_ywxw(stdmath_byte4 v) { return {v.y,v.w,v.x,v.w}; }
inline static stdmath_byte4 stdmath_byte4_ywxw_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.w = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_ywyx(stdmath_byte4 v) { return {v.y,v.w,v.y,v.x}; }
inline static stdmath_byte4 stdmath_byte4_ywyx_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.w = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_ywyy(stdmath_byte4 v) { return {v.y,v.w,v.y,v.y}; }
inline static stdmath_byte4 stdmath_byte4_ywyy_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.w = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_ywyz(stdmath_byte4 v) { return {v.y,v.w,v.y,v.z}; }
inline static stdmath_byte4 stdmath_byte4_ywyz_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.w = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_ywyw(stdmath_byte4 v) { return {v.y,v.w,v.y,v.w}; }
inline static stdmath_byte4 stdmath_byte4_ywyw_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.w = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_ywzx(stdmath_byte4 v) { return {v.y,v.w,v.z,v.x}; }
inline static stdmath_byte4 stdmath_byte4_ywzx_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.w = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_ywzy(stdmath_byte4 v) { return {v.y,v.w,v.z,v.y}; }
inline static stdmath_byte4 stdmath_byte4_ywzy_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.w = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_ywzz(stdmath_byte4 v) { return {v.y,v.w,v.z,v.z}; }
inline static stdmath_byte4 stdmath_byte4_ywzz_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.w = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_ywzw(stdmath_byte4 v) { return {v.y,v.w,v.z,v.w}; }
inline static stdmath_byte4 stdmath_byte4_ywzw_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.w = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_ywwx(stdmath_byte4 v) { return {v.y,v.w,v.w,v.x}; }
inline static stdmath_byte4 stdmath_byte4_ywwx_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.w = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_ywwy(stdmath_byte4 v) { return {v.y,v.w,v.w,v.y}; }
inline static stdmath_byte4 stdmath_byte4_ywwy_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.w = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_ywwz(stdmath_byte4 v) { return {v.y,v.w,v.w,v.z}; }
inline static stdmath_byte4 stdmath_byte4_ywwz_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.w = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_ywww(stdmath_byte4 v) { return {v.y,v.w,v.w,v.w}; }
inline static stdmath_byte4 stdmath_byte4_ywww_value(stdmath_byte4 v, stdmath_byte4 value) { v.y = value.x; v.w = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zxxx(stdmath_byte4 v) { return {v.z,v.x,v.x,v.x}; }
inline static stdmath_byte4 stdmath_byte4_zxxx_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.x = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zxxy(stdmath_byte4 v) { return {v.z,v.x,v.x,v.y}; }
inline static stdmath_byte4 stdmath_byte4_zxxy_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.x = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zxxz(stdmath_byte4 v) { return {v.z,v.x,v.x,v.z}; }
inline static stdmath_byte4 stdmath_byte4_zxxz_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.x = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zxxw(stdmath_byte4 v) { return {v.z,v.x,v.x,v.w}; }
inline static stdmath_byte4 stdmath_byte4_zxxw_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.x = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zxyx(stdmath_byte4 v) { return {v.z,v.x,v.y,v.x}; }
inline static stdmath_byte4 stdmath_byte4_zxyx_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.x = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zxyy(stdmath_byte4 v) { return {v.z,v.x,v.y,v.y}; }
inline static stdmath_byte4 stdmath_byte4_zxyy_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.x = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zxyz(stdmath_byte4 v) { return {v.z,v.x,v.y,v.z}; }
inline static stdmath_byte4 stdmath_byte4_zxyz_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.x = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zxyw(stdmath_byte4 v) { return {v.z,v.x,v.y,v.w}; }
inline static stdmath_byte4 stdmath_byte4_zxyw_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.x = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zxzx(stdmath_byte4 v) { return {v.z,v.x,v.z,v.x}; }
inline static stdmath_byte4 stdmath_byte4_zxzx_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.x = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zxzy(stdmath_byte4 v) { return {v.z,v.x,v.z,v.y}; }
inline static stdmath_byte4 stdmath_byte4_zxzy_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.x = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zxzz(stdmath_byte4 v) { return {v.z,v.x,v.z,v.z}; }
inline static stdmath_byte4 stdmath_byte4_zxzz_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.x = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zxzw(stdmath_byte4 v) { return {v.z,v.x,v.z,v.w}; }
inline static stdmath_byte4 stdmath_byte4_zxzw_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.x = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zxwx(stdmath_byte4 v) { return {v.z,v.x,v.w,v.x}; }
inline static stdmath_byte4 stdmath_byte4_zxwx_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.x = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zxwy(stdmath_byte4 v) { return {v.z,v.x,v.w,v.y}; }
inline static stdmath_byte4 stdmath_byte4_zxwy_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.x = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zxwz(stdmath_byte4 v) { return {v.z,v.x,v.w,v.z}; }
inline static stdmath_byte4 stdmath_byte4_zxwz_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.x = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zxww(stdmath_byte4 v) { return {v.z,v.x,v.w,v.w}; }
inline static stdmath_byte4 stdmath_byte4_zxww_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.x = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zyxx(stdmath_byte4 v) { return {v.z,v.y,v.x,v.x}; }
inline static stdmath_byte4 stdmath_byte4_zyxx_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.y = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zyxy(stdmath_byte4 v) { return {v.z,v.y,v.x,v.y}; }
inline static stdmath_byte4 stdmath_byte4_zyxy_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.y = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zyxz(stdmath_byte4 v) { return {v.z,v.y,v.x,v.z}; }
inline static stdmath_byte4 stdmath_byte4_zyxz_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.y = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zyxw(stdmath_byte4 v) { return {v.z,v.y,v.x,v.w}; }
inline static stdmath_byte4 stdmath_byte4_zyxw_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.y = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zyyx(stdmath_byte4 v) { return {v.z,v.y,v.y,v.x}; }
inline static stdmath_byte4 stdmath_byte4_zyyx_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.y = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zyyy(stdmath_byte4 v) { return {v.z,v.y,v.y,v.y}; }
inline static stdmath_byte4 stdmath_byte4_zyyy_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.y = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zyyz(stdmath_byte4 v) { return {v.z,v.y,v.y,v.z}; }
inline static stdmath_byte4 stdmath_byte4_zyyz_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.y = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zyyw(stdmath_byte4 v) { return {v.z,v.y,v.y,v.w}; }
inline static stdmath_byte4 stdmath_byte4_zyyw_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.y = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zyzx(stdmath_byte4 v) { return {v.z,v.y,v.z,v.x}; }
inline static stdmath_byte4 stdmath_byte4_zyzx_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.y = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zyzy(stdmath_byte4 v) { return {v.z,v.y,v.z,v.y}; }
inline static stdmath_byte4 stdmath_byte4_zyzy_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.y = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zyzz(stdmath_byte4 v) { return {v.z,v.y,v.z,v.z}; }
inline static stdmath_byte4 stdmath_byte4_zyzz_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.y = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zyzw(stdmath_byte4 v) { return {v.z,v.y,v.z,v.w}; }
inline static stdmath_byte4 stdmath_byte4_zyzw_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.y = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zywx(stdmath_byte4 v) { return {v.z,v.y,v.w,v.x}; }
inline static stdmath_byte4 stdmath_byte4_zywx_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.y = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zywy(stdmath_byte4 v) { return {v.z,v.y,v.w,v.y}; }
inline static stdmath_byte4 stdmath_byte4_zywy_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.y = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zywz(stdmath_byte4 v) { return {v.z,v.y,v.w,v.z}; }
inline static stdmath_byte4 stdmath_byte4_zywz_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.y = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zyww(stdmath_byte4 v) { return {v.z,v.y,v.w,v.w}; }
inline static stdmath_byte4 stdmath_byte4_zyww_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.y = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zzxx(stdmath_byte4 v) { return {v.z,v.z,v.x,v.x}; }
inline static stdmath_byte4 stdmath_byte4_zzxx_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.z = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zzxy(stdmath_byte4 v) { return {v.z,v.z,v.x,v.y}; }
inline static stdmath_byte4 stdmath_byte4_zzxy_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.z = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zzxz(stdmath_byte4 v) { return {v.z,v.z,v.x,v.z}; }
inline static stdmath_byte4 stdmath_byte4_zzxz_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.z = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zzxw(stdmath_byte4 v) { return {v.z,v.z,v.x,v.w}; }
inline static stdmath_byte4 stdmath_byte4_zzxw_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.z = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zzyx(stdmath_byte4 v) { return {v.z,v.z,v.y,v.x}; }
inline static stdmath_byte4 stdmath_byte4_zzyx_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.z = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zzyy(stdmath_byte4 v) { return {v.z,v.z,v.y,v.y}; }
inline static stdmath_byte4 stdmath_byte4_zzyy_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.z = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zzyz(stdmath_byte4 v) { return {v.z,v.z,v.y,v.z}; }
inline static stdmath_byte4 stdmath_byte4_zzyz_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.z = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zzyw(stdmath_byte4 v) { return {v.z,v.z,v.y,v.w}; }
inline static stdmath_byte4 stdmath_byte4_zzyw_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.z = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zzzx(stdmath_byte4 v) { return {v.z,v.z,v.z,v.x}; }
inline static stdmath_byte4 stdmath_byte4_zzzx_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.z = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zzzy(stdmath_byte4 v) { return {v.z,v.z,v.z,v.y}; }
inline static stdmath_byte4 stdmath_byte4_zzzy_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.z = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zzzz(stdmath_byte4 v) { return {v.z,v.z,v.z,v.z}; }
inline static stdmath_byte4 stdmath_byte4_zzzz_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.z = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zzzw(stdmath_byte4 v) { return {v.z,v.z,v.z,v.w}; }
inline static stdmath_byte4 stdmath_byte4_zzzw_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.z = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zzwx(stdmath_byte4 v) { return {v.z,v.z,v.w,v.x}; }
inline static stdmath_byte4 stdmath_byte4_zzwx_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.z = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zzwy(stdmath_byte4 v) { return {v.z,v.z,v.w,v.y}; }
inline static stdmath_byte4 stdmath_byte4_zzwy_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.z = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zzwz(stdmath_byte4 v) { return {v.z,v.z,v.w,v.z}; }
inline static stdmath_byte4 stdmath_byte4_zzwz_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.z = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zzww(stdmath_byte4 v) { return {v.z,v.z,v.w,v.w}; }
inline static stdmath_byte4 stdmath_byte4_zzww_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.z = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zwxx(stdmath_byte4 v) { return {v.z,v.w,v.x,v.x}; }
inline static stdmath_byte4 stdmath_byte4_zwxx_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.w = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zwxy(stdmath_byte4 v) { return {v.z,v.w,v.x,v.y}; }
inline static stdmath_byte4 stdmath_byte4_zwxy_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.w = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zwxz(stdmath_byte4 v) { return {v.z,v.w,v.x,v.z}; }
inline static stdmath_byte4 stdmath_byte4_zwxz_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.w = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zwxw(stdmath_byte4 v) { return {v.z,v.w,v.x,v.w}; }
inline static stdmath_byte4 stdmath_byte4_zwxw_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.w = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zwyx(stdmath_byte4 v) { return {v.z,v.w,v.y,v.x}; }
inline static stdmath_byte4 stdmath_byte4_zwyx_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.w = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zwyy(stdmath_byte4 v) { return {v.z,v.w,v.y,v.y}; }
inline static stdmath_byte4 stdmath_byte4_zwyy_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.w = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zwyz(stdmath_byte4 v) { return {v.z,v.w,v.y,v.z}; }
inline static stdmath_byte4 stdmath_byte4_zwyz_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.w = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zwyw(stdmath_byte4 v) { return {v.z,v.w,v.y,v.w}; }
inline static stdmath_byte4 stdmath_byte4_zwyw_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.w = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zwzx(stdmath_byte4 v) { return {v.z,v.w,v.z,v.x}; }
inline static stdmath_byte4 stdmath_byte4_zwzx_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.w = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zwzy(stdmath_byte4 v) { return {v.z,v.w,v.z,v.y}; }
inline static stdmath_byte4 stdmath_byte4_zwzy_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.w = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zwzz(stdmath_byte4 v) { return {v.z,v.w,v.z,v.z}; }
inline static stdmath_byte4 stdmath_byte4_zwzz_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.w = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zwzw(stdmath_byte4 v) { return {v.z,v.w,v.z,v.w}; }
inline static stdmath_byte4 stdmath_byte4_zwzw_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.w = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zwwx(stdmath_byte4 v) { return {v.z,v.w,v.w,v.x}; }
inline static stdmath_byte4 stdmath_byte4_zwwx_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.w = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zwwy(stdmath_byte4 v) { return {v.z,v.w,v.w,v.y}; }
inline static stdmath_byte4 stdmath_byte4_zwwy_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.w = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zwwz(stdmath_byte4 v) { return {v.z,v.w,v.w,v.z}; }
inline static stdmath_byte4 stdmath_byte4_zwwz_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.w = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_zwww(stdmath_byte4 v) { return {v.z,v.w,v.w,v.w}; }
inline static stdmath_byte4 stdmath_byte4_zwww_value(stdmath_byte4 v, stdmath_byte4 value) { v.z = value.x; v.w = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wxxx(stdmath_byte4 v) { return {v.w,v.x,v.x,v.x}; }
inline static stdmath_byte4 stdmath_byte4_wxxx_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.x = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wxxy(stdmath_byte4 v) { return {v.w,v.x,v.x,v.y}; }
inline static stdmath_byte4 stdmath_byte4_wxxy_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.x = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wxxz(stdmath_byte4 v) { return {v.w,v.x,v.x,v.z}; }
inline static stdmath_byte4 stdmath_byte4_wxxz_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.x = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wxxw(stdmath_byte4 v) { return {v.w,v.x,v.x,v.w}; }
inline static stdmath_byte4 stdmath_byte4_wxxw_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.x = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wxyx(stdmath_byte4 v) { return {v.w,v.x,v.y,v.x}; }
inline static stdmath_byte4 stdmath_byte4_wxyx_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.x = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wxyy(stdmath_byte4 v) { return {v.w,v.x,v.y,v.y}; }
inline static stdmath_byte4 stdmath_byte4_wxyy_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.x = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wxyz(stdmath_byte4 v) { return {v.w,v.x,v.y,v.z}; }
inline static stdmath_byte4 stdmath_byte4_wxyz_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.x = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wxyw(stdmath_byte4 v) { return {v.w,v.x,v.y,v.w}; }
inline static stdmath_byte4 stdmath_byte4_wxyw_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.x = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wxzx(stdmath_byte4 v) { return {v.w,v.x,v.z,v.x}; }
inline static stdmath_byte4 stdmath_byte4_wxzx_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.x = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wxzy(stdmath_byte4 v) { return {v.w,v.x,v.z,v.y}; }
inline static stdmath_byte4 stdmath_byte4_wxzy_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.x = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wxzz(stdmath_byte4 v) { return {v.w,v.x,v.z,v.z}; }
inline static stdmath_byte4 stdmath_byte4_wxzz_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.x = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wxzw(stdmath_byte4 v) { return {v.w,v.x,v.z,v.w}; }
inline static stdmath_byte4 stdmath_byte4_wxzw_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.x = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wxwx(stdmath_byte4 v) { return {v.w,v.x,v.w,v.x}; }
inline static stdmath_byte4 stdmath_byte4_wxwx_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.x = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wxwy(stdmath_byte4 v) { return {v.w,v.x,v.w,v.y}; }
inline static stdmath_byte4 stdmath_byte4_wxwy_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.x = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wxwz(stdmath_byte4 v) { return {v.w,v.x,v.w,v.z}; }
inline static stdmath_byte4 stdmath_byte4_wxwz_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.x = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wxww(stdmath_byte4 v) { return {v.w,v.x,v.w,v.w}; }
inline static stdmath_byte4 stdmath_byte4_wxww_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.x = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wyxx(stdmath_byte4 v) { return {v.w,v.y,v.x,v.x}; }
inline static stdmath_byte4 stdmath_byte4_wyxx_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.y = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wyxy(stdmath_byte4 v) { return {v.w,v.y,v.x,v.y}; }
inline static stdmath_byte4 stdmath_byte4_wyxy_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.y = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wyxz(stdmath_byte4 v) { return {v.w,v.y,v.x,v.z}; }
inline static stdmath_byte4 stdmath_byte4_wyxz_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.y = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wyxw(stdmath_byte4 v) { return {v.w,v.y,v.x,v.w}; }
inline static stdmath_byte4 stdmath_byte4_wyxw_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.y = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wyyx(stdmath_byte4 v) { return {v.w,v.y,v.y,v.x}; }
inline static stdmath_byte4 stdmath_byte4_wyyx_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.y = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wyyy(stdmath_byte4 v) { return {v.w,v.y,v.y,v.y}; }
inline static stdmath_byte4 stdmath_byte4_wyyy_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.y = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wyyz(stdmath_byte4 v) { return {v.w,v.y,v.y,v.z}; }
inline static stdmath_byte4 stdmath_byte4_wyyz_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.y = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wyyw(stdmath_byte4 v) { return {v.w,v.y,v.y,v.w}; }
inline static stdmath_byte4 stdmath_byte4_wyyw_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.y = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wyzx(stdmath_byte4 v) { return {v.w,v.y,v.z,v.x}; }
inline static stdmath_byte4 stdmath_byte4_wyzx_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.y = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wyzy(stdmath_byte4 v) { return {v.w,v.y,v.z,v.y}; }
inline static stdmath_byte4 stdmath_byte4_wyzy_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.y = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wyzz(stdmath_byte4 v) { return {v.w,v.y,v.z,v.z}; }
inline static stdmath_byte4 stdmath_byte4_wyzz_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.y = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wyzw(stdmath_byte4 v) { return {v.w,v.y,v.z,v.w}; }
inline static stdmath_byte4 stdmath_byte4_wyzw_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.y = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wywx(stdmath_byte4 v) { return {v.w,v.y,v.w,v.x}; }
inline static stdmath_byte4 stdmath_byte4_wywx_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.y = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wywy(stdmath_byte4 v) { return {v.w,v.y,v.w,v.y}; }
inline static stdmath_byte4 stdmath_byte4_wywy_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.y = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wywz(stdmath_byte4 v) { return {v.w,v.y,v.w,v.z}; }
inline static stdmath_byte4 stdmath_byte4_wywz_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.y = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wyww(stdmath_byte4 v) { return {v.w,v.y,v.w,v.w}; }
inline static stdmath_byte4 stdmath_byte4_wyww_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.y = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wzxx(stdmath_byte4 v) { return {v.w,v.z,v.x,v.x}; }
inline static stdmath_byte4 stdmath_byte4_wzxx_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.z = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wzxy(stdmath_byte4 v) { return {v.w,v.z,v.x,v.y}; }
inline static stdmath_byte4 stdmath_byte4_wzxy_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.z = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wzxz(stdmath_byte4 v) { return {v.w,v.z,v.x,v.z}; }
inline static stdmath_byte4 stdmath_byte4_wzxz_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.z = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wzxw(stdmath_byte4 v) { return {v.w,v.z,v.x,v.w}; }
inline static stdmath_byte4 stdmath_byte4_wzxw_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.z = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wzyx(stdmath_byte4 v) { return {v.w,v.z,v.y,v.x}; }
inline static stdmath_byte4 stdmath_byte4_wzyx_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.z = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wzyy(stdmath_byte4 v) { return {v.w,v.z,v.y,v.y}; }
inline static stdmath_byte4 stdmath_byte4_wzyy_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.z = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wzyz(stdmath_byte4 v) { return {v.w,v.z,v.y,v.z}; }
inline static stdmath_byte4 stdmath_byte4_wzyz_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.z = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wzyw(stdmath_byte4 v) { return {v.w,v.z,v.y,v.w}; }
inline static stdmath_byte4 stdmath_byte4_wzyw_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.z = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wzzx(stdmath_byte4 v) { return {v.w,v.z,v.z,v.x}; }
inline static stdmath_byte4 stdmath_byte4_wzzx_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.z = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wzzy(stdmath_byte4 v) { return {v.w,v.z,v.z,v.y}; }
inline static stdmath_byte4 stdmath_byte4_wzzy_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.z = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wzzz(stdmath_byte4 v) { return {v.w,v.z,v.z,v.z}; }
inline static stdmath_byte4 stdmath_byte4_wzzz_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.z = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wzzw(stdmath_byte4 v) { return {v.w,v.z,v.z,v.w}; }
inline static stdmath_byte4 stdmath_byte4_wzzw_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.z = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wzwx(stdmath_byte4 v) { return {v.w,v.z,v.w,v.x}; }
inline static stdmath_byte4 stdmath_byte4_wzwx_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.z = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wzwy(stdmath_byte4 v) { return {v.w,v.z,v.w,v.y}; }
inline static stdmath_byte4 stdmath_byte4_wzwy_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.z = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wzwz(stdmath_byte4 v) { return {v.w,v.z,v.w,v.z}; }
inline static stdmath_byte4 stdmath_byte4_wzwz_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.z = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wzww(stdmath_byte4 v) { return {v.w,v.z,v.w,v.w}; }
inline static stdmath_byte4 stdmath_byte4_wzww_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.z = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wwxx(stdmath_byte4 v) { return {v.w,v.w,v.x,v.x}; }
inline static stdmath_byte4 stdmath_byte4_wwxx_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.w = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wwxy(stdmath_byte4 v) { return {v.w,v.w,v.x,v.y}; }
inline static stdmath_byte4 stdmath_byte4_wwxy_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.w = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wwxz(stdmath_byte4 v) { return {v.w,v.w,v.x,v.z}; }
inline static stdmath_byte4 stdmath_byte4_wwxz_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.w = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wwxw(stdmath_byte4 v) { return {v.w,v.w,v.x,v.w}; }
inline static stdmath_byte4 stdmath_byte4_wwxw_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.w = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wwyx(stdmath_byte4 v) { return {v.w,v.w,v.y,v.x}; }
inline static stdmath_byte4 stdmath_byte4_wwyx_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.w = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wwyy(stdmath_byte4 v) { return {v.w,v.w,v.y,v.y}; }
inline static stdmath_byte4 stdmath_byte4_wwyy_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.w = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wwyz(stdmath_byte4 v) { return {v.w,v.w,v.y,v.z}; }
inline static stdmath_byte4 stdmath_byte4_wwyz_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.w = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wwyw(stdmath_byte4 v) { return {v.w,v.w,v.y,v.w}; }
inline static stdmath_byte4 stdmath_byte4_wwyw_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.w = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wwzx(stdmath_byte4 v) { return {v.w,v.w,v.z,v.x}; }
inline static stdmath_byte4 stdmath_byte4_wwzx_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.w = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wwzy(stdmath_byte4 v) { return {v.w,v.w,v.z,v.y}; }
inline static stdmath_byte4 stdmath_byte4_wwzy_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.w = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wwzz(stdmath_byte4 v) { return {v.w,v.w,v.z,v.z}; }
inline static stdmath_byte4 stdmath_byte4_wwzz_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.w = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wwzw(stdmath_byte4 v) { return {v.w,v.w,v.z,v.w}; }
inline static stdmath_byte4 stdmath_byte4_wwzw_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.w = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wwwx(stdmath_byte4 v) { return {v.w,v.w,v.w,v.x}; }
inline static stdmath_byte4 stdmath_byte4_wwwx_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.w = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wwwy(stdmath_byte4 v) { return {v.w,v.w,v.w,v.y}; }
inline static stdmath_byte4 stdmath_byte4_wwwy_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.w = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wwwz(stdmath_byte4 v) { return {v.w,v.w,v.w,v.z}; }
inline static stdmath_byte4 stdmath_byte4_wwwz_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.w = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_byte4 stdmath_byte4_wwww(stdmath_byte4 v) { return {v.w,v.w,v.w,v.w}; }
inline static stdmath_byte4 stdmath_byte4_wwww_value(stdmath_byte4 v, stdmath_byte4 value) { v.w = value.x; v.w = value.y; v.w = value.z; v.w = value.w; return v; }


#ifdef STDMATH_IMPLEMENTATION
#ifndef __cplusplus
#error "The stdmath implementations require a C++ compiler"
#endif

import stdmath.slang;

stdmath::byte4 c(stdmath_byte4 c) {
	return (stdmath::byte4&)c;
}
stdmath_byte4 c(stdmath::byte4 c) {
	return (stdmath_byte4&)c;
}

stdmath_byte4 stdmath_byte4_broadcast(uint8_t all) {
	return c(stdmath::byte4((stdmath::byte4::underlying_type)all));
}

stdmath_byte4 stdmath_byte4_add(stdmath_byte4 a, stdmath_byte4 b) {
	return c(c(a) + c(b));
}
stdmath_byte4 stdmath_byte4_subtract(stdmath_byte4 a, stdmath_byte4 b) {
	return c(c(a) - c(b));
}
stdmath_byte4 stdmath_byte4_negate(stdmath_byte4 v) {
	return c(stdmath::byte4(-(stdmath::vector<uint8_t, 4>)c(v)));
}
stdmath_byte4 stdmath_byte4_multiply(stdmath_byte4 a, stdmath_byte4 b) {
	return c(c(a) * c(b));
}
stdmath_byte4 stdmath_byte4_divide(stdmath_byte4 a, stdmath_byte4 b) {
	return c(c(a) / c(b));
}
stdmath_byte4 stdmath_byte4_scale(stdmath_byte4 v, uint8_t s) {
	return c(c(v) * (stdmath::byte4::underlying_type)s);
}

#if false
stdmath_byte4 stdmath_byte4_modulus(stdmath_byte4 a, stdmath_byte4 b) {
	return c(c(a) % c(b));
}
stdmath_byte4 stdmath_byte4_logical_not(stdmath_byte4 v) {
	return c(!c(v));
}
stdmath_byte4 stdmath_byte4_bitwise_not(stdmath_byte4 v) {
	return c(~c(v));
}
stdmath_byte4 stdmath_byte4_logical_and(stdmath_byte4 a, stdmath_byte4 b) {
	return c(c(a) && c(b));
}
stdmath_byte4 stdmath_byte4_bitwise_and(stdmath_byte4 a, stdmath_byte4 b) {
	return c(c(a) & c(b));
}
stdmath_byte4 stdmath_byte4_logical_or(stdmath_byte4 a, stdmath_byte4 b) {
	return c(c(a) || c(b));
}
stdmath_byte4 stdmath_byte4_bitwise_or(stdmath_byte4 a, stdmath_byte4 b) {
	return c(c(a) | c(b));
}
stdmath_byte4 stdmath_byte4_bitwise_xor(stdmath_byte4 a, stdmath_byte4 b) {
	return c(c(a) ^ c(b));
}
stdmath_byte4 stdmath_byte4_shift_left(stdmath_byte4 a, stdmath_byte4 b) {
	return c(c(a) << c(b));
}
stdmath_byte4 stdmath_byte4_shift_right(stdmath_byte4 a, stdmath_byte4 b) {
	return c(c(a) >> c(b));
}
#endif

stdmath_bool4 stdmath_byte4_equal_to(stdmath_byte4 a, stdmath_byte4 b) {
	return c(c(a) == c(b));
}
stdmath_bool4 stdmath_byte4_not_equal_to(stdmath_byte4 a, stdmath_byte4 b) {
	return c(c(a) != c(b));
}
stdmath_bool4 stdmath_byte4_less_than(stdmath_byte4 a, stdmath_byte4 b) {
	return c(c(a) < c(b));
}
stdmath_bool4 stdmath_byte4_less_than_or_equal_to(stdmath_byte4 a, stdmath_byte4 b) {
	return c(c(a) <= c(b));
}
stdmath_bool4 stdmath_byte4_greater_than(stdmath_byte4 a, stdmath_byte4 b) {
	return c(c(a) > c(b));
}
stdmath_bool4 stdmath_byte4_greater_than_or_equal_to(stdmath_byte4 a, stdmath_byte4 b) {
	return c(c(a) >= c(b));
}

uint8_t stdmath_byte4_length_squared(stdmath_byte4 v)  {
	return (uint8_t)c(v).length_squared();
}
uint8_t stdmath_byte4_length(stdmath_byte4 v)  {
	return (uint8_t)c(v).length();
}
uint8_t stdmath_byte4_dot(stdmath_byte4 a, stdmath_byte4 b)  {
	return (uint8_t)dot(c(a), c(b));
}
uint8_t stdmath_byte4_min_element(stdmath_byte4 v)  {
	return (uint8_t)c(v).min_element();
}
uint8_t stdmath_byte4_max_element(stdmath_byte4 v)  {
	return (uint8_t)c(v).max_element();
}

stdmath_byte4 stdmath_byte4_elementwise_transform(stdmath_byte4 v, uint8_t(*func)(uint8_t)) {
	return c(c(v).elementwise_transform(func));
}
// uint8_t stdmath_byte4_reduce_elements(stdmath_byte4 v, uint8_t initial_value, uint8_t(*reducer)(stdmath_byte4, stdmath_byte4)) {
// 	return c(v).reduce_elements(initial_value, reducer);
// }

#if 4 == 3
stdmath_byte4 stdmath_byte4_cross(stdmath_byte4 a, stdmath_byte4 b) {
	return c(cross(c(a), c(b)));
}
#endif

stdmath_byte4 stdmath_byte4_min(stdmath_byte4 a, stdmath_byte4 b) {
	return c(min(c(a), c(b)));
}
stdmath_byte4 stdmath_byte4_max(stdmath_byte4 a, stdmath_byte4 b) {
	return c(max(c(a), c(b)));
}
stdmath_byte4 stdmath_byte4_normalize(stdmath_byte4 v) {
	return c(normalize(c(v)));
}
stdmath_byte4 stdmath_byte4_lerp(stdmath_byte4 a, stdmath_byte4 b, float t) {
	return c(lerp(c(a), c(b), t));
}
stdmath_byte4 stdmath_byte4_clamp(stdmath_byte4 a, stdmath_byte4 min, stdmath_byte4 max) {
	return c(clamp(c(a), c(min), c(max)));
}
stdmath_byte4 stdmath_byte4_reflect(stdmath_byte4 a, stdmath_byte4 b) {
	return c(reflect(c(a), c(b)));
}
stdmath_bool4 stdmath_byte4_approximately_equal(stdmath_byte4 a, stdmath_byte4 b) {
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

#endif // __STDMATH_uint8_t4_H__