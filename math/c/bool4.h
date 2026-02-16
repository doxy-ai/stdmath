#ifndef __STDMATH_bool4_H__
#define __STDMATH_bool4_H__

#include <stdint.h>
#if !true
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
#include "bool1.h"
#elif 4 == 3
#include "bool2.h"
#include "bool1.h"
#elif 4 == 4
#include "bool3.h"
#include "bool2.h"
#include "bool1.h"
#endif
#include "util.h"

#if 4 == 1
union stdmath_bool1 {
	struct {
		bool x;
	};
	bool data[1];
};
#elif 4 == 2
union stdmath_bool2 {
	struct {
		bool x, y;
	};
	struct {
		bool u, v;
	};
	bool data[2];
};
#elif 4 == 3
union stdmath_bool3 {
	struct {
		bool x, y, z;
	};
	struct {
		bool r, g, b;
	};
	struct {
		bool h, s, v;
	};
	bool data[4]; // bool3s are aligned as if they were bool4s
};
#elif 4 == 4
union stdmath_bool4 {
	struct {
		bool x, y, z, w;
	};
	struct {
		bool r, g, b, a;
	};
	struct {
		bool h, s, v;
	};
	bool data[4];
};
#endif

stdmath_bool4 stdmath_bool4_broadcast(bool all);

stdmath_bool4 stdmath_bool4_add(stdmath_bool4 a, stdmath_bool4 b);
stdmath_bool4 stdmath_bool4_subtract(stdmath_bool4 a, stdmath_bool4 b);
stdmath_bool4 stdmath_bool4_negate(stdmath_bool4 v);
stdmath_bool4 stdmath_bool4_multiply(stdmath_bool4 a, stdmath_bool4 b);
stdmath_bool4 stdmath_bool4_divide(stdmath_bool4 a, stdmath_bool4 b);
stdmath_bool4 stdmath_bool4_scale(stdmath_bool4 v, bool s);

#if false
stdmath_bool4 stdmath_bool4_modulus(stdmath_bool4 a, stdmath_bool4 b);
stdmath_bool4 stdmath_bool4_logical_not(stdmath_bool4 v);
stdmath_bool4 stdmath_bool4_bitwise_not(stdmath_bool4 v);
stdmath_bool4 stdmath_bool4_logical_and(stdmath_bool4 a, stdmath_bool4 b);
stdmath_bool4 stdmath_bool4_bitwise_and(stdmath_bool4 a, stdmath_bool4 b);
stdmath_bool4 stdmath_bool4_logical_or(stdmath_bool4 a, stdmath_bool4 b);
stdmath_bool4 stdmath_bool4_bitwise_or(stdmath_bool4 a, stdmath_bool4 b);
stdmath_bool4 stdmath_bool4_bitwise_xor(stdmath_bool4 a, stdmath_bool4 b);
stdmath_bool4 stdmath_bool4_shift_left(stdmath_bool4 a, stdmath_bool4 b);
stdmath_bool4 stdmath_bool4_shift_right(stdmath_bool4 a, stdmath_bool4 b);
#endif

stdmath_bool4 stdmath_bool4_equal_to(stdmath_bool4 a, stdmath_bool4 b);
stdmath_bool4 stdmath_bool4_not_equal_to(stdmath_bool4 a, stdmath_bool4 b);
stdmath_bool4 stdmath_bool4_less_than(stdmath_bool4 a, stdmath_bool4 b);
stdmath_bool4 stdmath_bool4_less_than_or_equal_to(stdmath_bool4 a, stdmath_bool4 b);
stdmath_bool4 stdmath_bool4_greater_than(stdmath_bool4 a, stdmath_bool4 b);
stdmath_bool4 stdmath_bool4_greater_than_or_equal_to(stdmath_bool4 a, stdmath_bool4 b);

bool stdmath_bool4_length_squared(stdmath_bool4 v);
bool stdmath_bool4_length(stdmath_bool4 v);
bool stdmath_bool4_dot(stdmath_bool4 v);
bool stdmath_bool4_min_element(stdmath_bool4 v);
bool stdmath_bool4_max_element(stdmath_bool4 v);

stdmath_bool4 stdmath_bool4_elementwise_transform(stdmath_bool4 v, bool(*func)(bool));
// bool stdmath_bool4_reduce_elements(stdmath_bool4 v, bool initial_value, bool(*reducer)(stdmath_bool4, stdmath_bool4));

#if 4 == 3
stdmath_bool3 stdmath_bool3_cross(stdmath_bool3 a, stdmath_bool3 b);
#endif

stdmath_bool4 stdmath_bool4_min(stdmath_bool4 a, stdmath_bool4 b);
stdmath_bool4 stdmath_bool4_max(stdmath_bool4 a, stdmath_bool4 b);
stdmath_bool4 stdmath_bool4_normalize(stdmath_bool4 v);
stdmath_bool4 stdmath_bool4_lerp(stdmath_bool4 a, stdmath_bool4 b, float t);
stdmath_bool4 stdmath_bool4_clamp(stdmath_bool4 a, stdmath_bool4 min, stdmath_bool4 max);
stdmath_bool4 stdmath_bool4_reflect(stdmath_bool4 a, stdmath_bool4 b);
stdmath_bool4 stdmath_bool4_approximately_equal(stdmath_bool4 a, stdmath_bool4 b);

#if true
bool stdmath_bool4_all_of(stdmath_bool4 v);
bool stdmath_bool4_any_of(stdmath_bool4 v);
bool stdmath_bool4_none_of(stdmath_bool4 v);
bool stdmath_bool4_some_of(stdmath_bool4 v);
#endif

inline static stdmath_bool1 stdmath_bool4_x(stdmath_bool4 v) { return {v.x}; }
inline static stdmath_bool4 stdmath_bool4_x_value(stdmath_bool4 v, stdmath_bool1 value) { v.x = value.x; return v; }
inline static stdmath_bool1 stdmath_bool4_y(stdmath_bool4 v) { return {v.y}; }
inline static stdmath_bool4 stdmath_bool4_y_value(stdmath_bool4 v, stdmath_bool1 value) { v.y = value.x; return v; }
inline static stdmath_bool1 stdmath_bool4_z(stdmath_bool4 v) { return {v.z}; }
inline static stdmath_bool4 stdmath_bool4_z_value(stdmath_bool4 v, stdmath_bool1 value) { v.z = value.x; return v; }
inline static stdmath_bool1 stdmath_bool4_w(stdmath_bool4 v) { return {v.w}; }
inline static stdmath_bool4 stdmath_bool4_w_value(stdmath_bool4 v, stdmath_bool1 value) { v.w = value.x; return v; }
inline static stdmath_bool2 stdmath_bool4_xx(stdmath_bool4 v) { return {v.x,v.x}; }
inline static stdmath_bool4 stdmath_bool4_xx_value(stdmath_bool4 v, stdmath_bool2 value) { v.x = value.x; v.x = value.y; return v; }
inline static stdmath_bool2 stdmath_bool4_xy(stdmath_bool4 v) { return {v.x,v.y}; }
inline static stdmath_bool4 stdmath_bool4_xy_value(stdmath_bool4 v, stdmath_bool2 value) { v.x = value.x; v.y = value.y; return v; }
inline static stdmath_bool2 stdmath_bool4_xz(stdmath_bool4 v) { return {v.x,v.z}; }
inline static stdmath_bool4 stdmath_bool4_xz_value(stdmath_bool4 v, stdmath_bool2 value) { v.x = value.x; v.z = value.y; return v; }
inline static stdmath_bool2 stdmath_bool4_xw(stdmath_bool4 v) { return {v.x,v.w}; }
inline static stdmath_bool4 stdmath_bool4_xw_value(stdmath_bool4 v, stdmath_bool2 value) { v.x = value.x; v.w = value.y; return v; }
inline static stdmath_bool2 stdmath_bool4_yx(stdmath_bool4 v) { return {v.y,v.x}; }
inline static stdmath_bool4 stdmath_bool4_yx_value(stdmath_bool4 v, stdmath_bool2 value) { v.y = value.x; v.x = value.y; return v; }
inline static stdmath_bool2 stdmath_bool4_yy(stdmath_bool4 v) { return {v.y,v.y}; }
inline static stdmath_bool4 stdmath_bool4_yy_value(stdmath_bool4 v, stdmath_bool2 value) { v.y = value.x; v.y = value.y; return v; }
inline static stdmath_bool2 stdmath_bool4_yz(stdmath_bool4 v) { return {v.y,v.z}; }
inline static stdmath_bool4 stdmath_bool4_yz_value(stdmath_bool4 v, stdmath_bool2 value) { v.y = value.x; v.z = value.y; return v; }
inline static stdmath_bool2 stdmath_bool4_yw(stdmath_bool4 v) { return {v.y,v.w}; }
inline static stdmath_bool4 stdmath_bool4_yw_value(stdmath_bool4 v, stdmath_bool2 value) { v.y = value.x; v.w = value.y; return v; }
inline static stdmath_bool2 stdmath_bool4_zx(stdmath_bool4 v) { return {v.z,v.x}; }
inline static stdmath_bool4 stdmath_bool4_zx_value(stdmath_bool4 v, stdmath_bool2 value) { v.z = value.x; v.x = value.y; return v; }
inline static stdmath_bool2 stdmath_bool4_zy(stdmath_bool4 v) { return {v.z,v.y}; }
inline static stdmath_bool4 stdmath_bool4_zy_value(stdmath_bool4 v, stdmath_bool2 value) { v.z = value.x; v.y = value.y; return v; }
inline static stdmath_bool2 stdmath_bool4_zz(stdmath_bool4 v) { return {v.z,v.z}; }
inline static stdmath_bool4 stdmath_bool4_zz_value(stdmath_bool4 v, stdmath_bool2 value) { v.z = value.x; v.z = value.y; return v; }
inline static stdmath_bool2 stdmath_bool4_zw(stdmath_bool4 v) { return {v.z,v.w}; }
inline static stdmath_bool4 stdmath_bool4_zw_value(stdmath_bool4 v, stdmath_bool2 value) { v.z = value.x; v.w = value.y; return v; }
inline static stdmath_bool2 stdmath_bool4_wx(stdmath_bool4 v) { return {v.w,v.x}; }
inline static stdmath_bool4 stdmath_bool4_wx_value(stdmath_bool4 v, stdmath_bool2 value) { v.w = value.x; v.x = value.y; return v; }
inline static stdmath_bool2 stdmath_bool4_wy(stdmath_bool4 v) { return {v.w,v.y}; }
inline static stdmath_bool4 stdmath_bool4_wy_value(stdmath_bool4 v, stdmath_bool2 value) { v.w = value.x; v.y = value.y; return v; }
inline static stdmath_bool2 stdmath_bool4_wz(stdmath_bool4 v) { return {v.w,v.z}; }
inline static stdmath_bool4 stdmath_bool4_wz_value(stdmath_bool4 v, stdmath_bool2 value) { v.w = value.x; v.z = value.y; return v; }
inline static stdmath_bool2 stdmath_bool4_ww(stdmath_bool4 v) { return {v.w,v.w}; }
inline static stdmath_bool4 stdmath_bool4_ww_value(stdmath_bool4 v, stdmath_bool2 value) { v.w = value.x; v.w = value.y; return v; }
inline static stdmath_bool3 stdmath_bool4_xxx(stdmath_bool4 v) { return {v.x,v.x,v.x}; }
inline static stdmath_bool4 stdmath_bool4_xxx_value(stdmath_bool4 v, stdmath_bool3 value) { v.x = value.x; v.x = value.y; v.x = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_xxy(stdmath_bool4 v) { return {v.x,v.x,v.y}; }
inline static stdmath_bool4 stdmath_bool4_xxy_value(stdmath_bool4 v, stdmath_bool3 value) { v.x = value.x; v.x = value.y; v.y = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_xxz(stdmath_bool4 v) { return {v.x,v.x,v.z}; }
inline static stdmath_bool4 stdmath_bool4_xxz_value(stdmath_bool4 v, stdmath_bool3 value) { v.x = value.x; v.x = value.y; v.z = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_xxw(stdmath_bool4 v) { return {v.x,v.x,v.w}; }
inline static stdmath_bool4 stdmath_bool4_xxw_value(stdmath_bool4 v, stdmath_bool3 value) { v.x = value.x; v.x = value.y; v.w = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_xyx(stdmath_bool4 v) { return {v.x,v.y,v.x}; }
inline static stdmath_bool4 stdmath_bool4_xyx_value(stdmath_bool4 v, stdmath_bool3 value) { v.x = value.x; v.y = value.y; v.x = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_xyy(stdmath_bool4 v) { return {v.x,v.y,v.y}; }
inline static stdmath_bool4 stdmath_bool4_xyy_value(stdmath_bool4 v, stdmath_bool3 value) { v.x = value.x; v.y = value.y; v.y = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_xyz(stdmath_bool4 v) { return {v.x,v.y,v.z}; }
inline static stdmath_bool4 stdmath_bool4_xyz_value(stdmath_bool4 v, stdmath_bool3 value) { v.x = value.x; v.y = value.y; v.z = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_xyw(stdmath_bool4 v) { return {v.x,v.y,v.w}; }
inline static stdmath_bool4 stdmath_bool4_xyw_value(stdmath_bool4 v, stdmath_bool3 value) { v.x = value.x; v.y = value.y; v.w = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_xzx(stdmath_bool4 v) { return {v.x,v.z,v.x}; }
inline static stdmath_bool4 stdmath_bool4_xzx_value(stdmath_bool4 v, stdmath_bool3 value) { v.x = value.x; v.z = value.y; v.x = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_xzy(stdmath_bool4 v) { return {v.x,v.z,v.y}; }
inline static stdmath_bool4 stdmath_bool4_xzy_value(stdmath_bool4 v, stdmath_bool3 value) { v.x = value.x; v.z = value.y; v.y = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_xzz(stdmath_bool4 v) { return {v.x,v.z,v.z}; }
inline static stdmath_bool4 stdmath_bool4_xzz_value(stdmath_bool4 v, stdmath_bool3 value) { v.x = value.x; v.z = value.y; v.z = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_xzw(stdmath_bool4 v) { return {v.x,v.z,v.w}; }
inline static stdmath_bool4 stdmath_bool4_xzw_value(stdmath_bool4 v, stdmath_bool3 value) { v.x = value.x; v.z = value.y; v.w = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_xwx(stdmath_bool4 v) { return {v.x,v.w,v.x}; }
inline static stdmath_bool4 stdmath_bool4_xwx_value(stdmath_bool4 v, stdmath_bool3 value) { v.x = value.x; v.w = value.y; v.x = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_xwy(stdmath_bool4 v) { return {v.x,v.w,v.y}; }
inline static stdmath_bool4 stdmath_bool4_xwy_value(stdmath_bool4 v, stdmath_bool3 value) { v.x = value.x; v.w = value.y; v.y = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_xwz(stdmath_bool4 v) { return {v.x,v.w,v.z}; }
inline static stdmath_bool4 stdmath_bool4_xwz_value(stdmath_bool4 v, stdmath_bool3 value) { v.x = value.x; v.w = value.y; v.z = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_xww(stdmath_bool4 v) { return {v.x,v.w,v.w}; }
inline static stdmath_bool4 stdmath_bool4_xww_value(stdmath_bool4 v, stdmath_bool3 value) { v.x = value.x; v.w = value.y; v.w = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_yxx(stdmath_bool4 v) { return {v.y,v.x,v.x}; }
inline static stdmath_bool4 stdmath_bool4_yxx_value(stdmath_bool4 v, stdmath_bool3 value) { v.y = value.x; v.x = value.y; v.x = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_yxy(stdmath_bool4 v) { return {v.y,v.x,v.y}; }
inline static stdmath_bool4 stdmath_bool4_yxy_value(stdmath_bool4 v, stdmath_bool3 value) { v.y = value.x; v.x = value.y; v.y = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_yxz(stdmath_bool4 v) { return {v.y,v.x,v.z}; }
inline static stdmath_bool4 stdmath_bool4_yxz_value(stdmath_bool4 v, stdmath_bool3 value) { v.y = value.x; v.x = value.y; v.z = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_yxw(stdmath_bool4 v) { return {v.y,v.x,v.w}; }
inline static stdmath_bool4 stdmath_bool4_yxw_value(stdmath_bool4 v, stdmath_bool3 value) { v.y = value.x; v.x = value.y; v.w = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_yyx(stdmath_bool4 v) { return {v.y,v.y,v.x}; }
inline static stdmath_bool4 stdmath_bool4_yyx_value(stdmath_bool4 v, stdmath_bool3 value) { v.y = value.x; v.y = value.y; v.x = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_yyy(stdmath_bool4 v) { return {v.y,v.y,v.y}; }
inline static stdmath_bool4 stdmath_bool4_yyy_value(stdmath_bool4 v, stdmath_bool3 value) { v.y = value.x; v.y = value.y; v.y = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_yyz(stdmath_bool4 v) { return {v.y,v.y,v.z}; }
inline static stdmath_bool4 stdmath_bool4_yyz_value(stdmath_bool4 v, stdmath_bool3 value) { v.y = value.x; v.y = value.y; v.z = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_yyw(stdmath_bool4 v) { return {v.y,v.y,v.w}; }
inline static stdmath_bool4 stdmath_bool4_yyw_value(stdmath_bool4 v, stdmath_bool3 value) { v.y = value.x; v.y = value.y; v.w = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_yzx(stdmath_bool4 v) { return {v.y,v.z,v.x}; }
inline static stdmath_bool4 stdmath_bool4_yzx_value(stdmath_bool4 v, stdmath_bool3 value) { v.y = value.x; v.z = value.y; v.x = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_yzy(stdmath_bool4 v) { return {v.y,v.z,v.y}; }
inline static stdmath_bool4 stdmath_bool4_yzy_value(stdmath_bool4 v, stdmath_bool3 value) { v.y = value.x; v.z = value.y; v.y = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_yzz(stdmath_bool4 v) { return {v.y,v.z,v.z}; }
inline static stdmath_bool4 stdmath_bool4_yzz_value(stdmath_bool4 v, stdmath_bool3 value) { v.y = value.x; v.z = value.y; v.z = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_yzw(stdmath_bool4 v) { return {v.y,v.z,v.w}; }
inline static stdmath_bool4 stdmath_bool4_yzw_value(stdmath_bool4 v, stdmath_bool3 value) { v.y = value.x; v.z = value.y; v.w = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_ywx(stdmath_bool4 v) { return {v.y,v.w,v.x}; }
inline static stdmath_bool4 stdmath_bool4_ywx_value(stdmath_bool4 v, stdmath_bool3 value) { v.y = value.x; v.w = value.y; v.x = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_ywy(stdmath_bool4 v) { return {v.y,v.w,v.y}; }
inline static stdmath_bool4 stdmath_bool4_ywy_value(stdmath_bool4 v, stdmath_bool3 value) { v.y = value.x; v.w = value.y; v.y = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_ywz(stdmath_bool4 v) { return {v.y,v.w,v.z}; }
inline static stdmath_bool4 stdmath_bool4_ywz_value(stdmath_bool4 v, stdmath_bool3 value) { v.y = value.x; v.w = value.y; v.z = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_yww(stdmath_bool4 v) { return {v.y,v.w,v.w}; }
inline static stdmath_bool4 stdmath_bool4_yww_value(stdmath_bool4 v, stdmath_bool3 value) { v.y = value.x; v.w = value.y; v.w = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_zxx(stdmath_bool4 v) { return {v.z,v.x,v.x}; }
inline static stdmath_bool4 stdmath_bool4_zxx_value(stdmath_bool4 v, stdmath_bool3 value) { v.z = value.x; v.x = value.y; v.x = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_zxy(stdmath_bool4 v) { return {v.z,v.x,v.y}; }
inline static stdmath_bool4 stdmath_bool4_zxy_value(stdmath_bool4 v, stdmath_bool3 value) { v.z = value.x; v.x = value.y; v.y = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_zxz(stdmath_bool4 v) { return {v.z,v.x,v.z}; }
inline static stdmath_bool4 stdmath_bool4_zxz_value(stdmath_bool4 v, stdmath_bool3 value) { v.z = value.x; v.x = value.y; v.z = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_zxw(stdmath_bool4 v) { return {v.z,v.x,v.w}; }
inline static stdmath_bool4 stdmath_bool4_zxw_value(stdmath_bool4 v, stdmath_bool3 value) { v.z = value.x; v.x = value.y; v.w = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_zyx(stdmath_bool4 v) { return {v.z,v.y,v.x}; }
inline static stdmath_bool4 stdmath_bool4_zyx_value(stdmath_bool4 v, stdmath_bool3 value) { v.z = value.x; v.y = value.y; v.x = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_zyy(stdmath_bool4 v) { return {v.z,v.y,v.y}; }
inline static stdmath_bool4 stdmath_bool4_zyy_value(stdmath_bool4 v, stdmath_bool3 value) { v.z = value.x; v.y = value.y; v.y = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_zyz(stdmath_bool4 v) { return {v.z,v.y,v.z}; }
inline static stdmath_bool4 stdmath_bool4_zyz_value(stdmath_bool4 v, stdmath_bool3 value) { v.z = value.x; v.y = value.y; v.z = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_zyw(stdmath_bool4 v) { return {v.z,v.y,v.w}; }
inline static stdmath_bool4 stdmath_bool4_zyw_value(stdmath_bool4 v, stdmath_bool3 value) { v.z = value.x; v.y = value.y; v.w = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_zzx(stdmath_bool4 v) { return {v.z,v.z,v.x}; }
inline static stdmath_bool4 stdmath_bool4_zzx_value(stdmath_bool4 v, stdmath_bool3 value) { v.z = value.x; v.z = value.y; v.x = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_zzy(stdmath_bool4 v) { return {v.z,v.z,v.y}; }
inline static stdmath_bool4 stdmath_bool4_zzy_value(stdmath_bool4 v, stdmath_bool3 value) { v.z = value.x; v.z = value.y; v.y = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_zzz(stdmath_bool4 v) { return {v.z,v.z,v.z}; }
inline static stdmath_bool4 stdmath_bool4_zzz_value(stdmath_bool4 v, stdmath_bool3 value) { v.z = value.x; v.z = value.y; v.z = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_zzw(stdmath_bool4 v) { return {v.z,v.z,v.w}; }
inline static stdmath_bool4 stdmath_bool4_zzw_value(stdmath_bool4 v, stdmath_bool3 value) { v.z = value.x; v.z = value.y; v.w = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_zwx(stdmath_bool4 v) { return {v.z,v.w,v.x}; }
inline static stdmath_bool4 stdmath_bool4_zwx_value(stdmath_bool4 v, stdmath_bool3 value) { v.z = value.x; v.w = value.y; v.x = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_zwy(stdmath_bool4 v) { return {v.z,v.w,v.y}; }
inline static stdmath_bool4 stdmath_bool4_zwy_value(stdmath_bool4 v, stdmath_bool3 value) { v.z = value.x; v.w = value.y; v.y = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_zwz(stdmath_bool4 v) { return {v.z,v.w,v.z}; }
inline static stdmath_bool4 stdmath_bool4_zwz_value(stdmath_bool4 v, stdmath_bool3 value) { v.z = value.x; v.w = value.y; v.z = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_zww(stdmath_bool4 v) { return {v.z,v.w,v.w}; }
inline static stdmath_bool4 stdmath_bool4_zww_value(stdmath_bool4 v, stdmath_bool3 value) { v.z = value.x; v.w = value.y; v.w = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_wxx(stdmath_bool4 v) { return {v.w,v.x,v.x}; }
inline static stdmath_bool4 stdmath_bool4_wxx_value(stdmath_bool4 v, stdmath_bool3 value) { v.w = value.x; v.x = value.y; v.x = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_wxy(stdmath_bool4 v) { return {v.w,v.x,v.y}; }
inline static stdmath_bool4 stdmath_bool4_wxy_value(stdmath_bool4 v, stdmath_bool3 value) { v.w = value.x; v.x = value.y; v.y = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_wxz(stdmath_bool4 v) { return {v.w,v.x,v.z}; }
inline static stdmath_bool4 stdmath_bool4_wxz_value(stdmath_bool4 v, stdmath_bool3 value) { v.w = value.x; v.x = value.y; v.z = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_wxw(stdmath_bool4 v) { return {v.w,v.x,v.w}; }
inline static stdmath_bool4 stdmath_bool4_wxw_value(stdmath_bool4 v, stdmath_bool3 value) { v.w = value.x; v.x = value.y; v.w = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_wyx(stdmath_bool4 v) { return {v.w,v.y,v.x}; }
inline static stdmath_bool4 stdmath_bool4_wyx_value(stdmath_bool4 v, stdmath_bool3 value) { v.w = value.x; v.y = value.y; v.x = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_wyy(stdmath_bool4 v) { return {v.w,v.y,v.y}; }
inline static stdmath_bool4 stdmath_bool4_wyy_value(stdmath_bool4 v, stdmath_bool3 value) { v.w = value.x; v.y = value.y; v.y = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_wyz(stdmath_bool4 v) { return {v.w,v.y,v.z}; }
inline static stdmath_bool4 stdmath_bool4_wyz_value(stdmath_bool4 v, stdmath_bool3 value) { v.w = value.x; v.y = value.y; v.z = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_wyw(stdmath_bool4 v) { return {v.w,v.y,v.w}; }
inline static stdmath_bool4 stdmath_bool4_wyw_value(stdmath_bool4 v, stdmath_bool3 value) { v.w = value.x; v.y = value.y; v.w = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_wzx(stdmath_bool4 v) { return {v.w,v.z,v.x}; }
inline static stdmath_bool4 stdmath_bool4_wzx_value(stdmath_bool4 v, stdmath_bool3 value) { v.w = value.x; v.z = value.y; v.x = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_wzy(stdmath_bool4 v) { return {v.w,v.z,v.y}; }
inline static stdmath_bool4 stdmath_bool4_wzy_value(stdmath_bool4 v, stdmath_bool3 value) { v.w = value.x; v.z = value.y; v.y = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_wzz(stdmath_bool4 v) { return {v.w,v.z,v.z}; }
inline static stdmath_bool4 stdmath_bool4_wzz_value(stdmath_bool4 v, stdmath_bool3 value) { v.w = value.x; v.z = value.y; v.z = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_wzw(stdmath_bool4 v) { return {v.w,v.z,v.w}; }
inline static stdmath_bool4 stdmath_bool4_wzw_value(stdmath_bool4 v, stdmath_bool3 value) { v.w = value.x; v.z = value.y; v.w = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_wwx(stdmath_bool4 v) { return {v.w,v.w,v.x}; }
inline static stdmath_bool4 stdmath_bool4_wwx_value(stdmath_bool4 v, stdmath_bool3 value) { v.w = value.x; v.w = value.y; v.x = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_wwy(stdmath_bool4 v) { return {v.w,v.w,v.y}; }
inline static stdmath_bool4 stdmath_bool4_wwy_value(stdmath_bool4 v, stdmath_bool3 value) { v.w = value.x; v.w = value.y; v.y = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_wwz(stdmath_bool4 v) { return {v.w,v.w,v.z}; }
inline static stdmath_bool4 stdmath_bool4_wwz_value(stdmath_bool4 v, stdmath_bool3 value) { v.w = value.x; v.w = value.y; v.z = value.z; return v; }
inline static stdmath_bool3 stdmath_bool4_www(stdmath_bool4 v) { return {v.w,v.w,v.w}; }
inline static stdmath_bool4 stdmath_bool4_www_value(stdmath_bool4 v, stdmath_bool3 value) { v.w = value.x; v.w = value.y; v.w = value.z; return v; }
inline static stdmath_bool4 stdmath_bool4_xxxx(stdmath_bool4 v) { return {v.x,v.x,v.x,v.x}; }
inline static stdmath_bool4 stdmath_bool4_xxxx_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.x = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xxxy(stdmath_bool4 v) { return {v.x,v.x,v.x,v.y}; }
inline static stdmath_bool4 stdmath_bool4_xxxy_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.x = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xxxz(stdmath_bool4 v) { return {v.x,v.x,v.x,v.z}; }
inline static stdmath_bool4 stdmath_bool4_xxxz_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.x = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xxxw(stdmath_bool4 v) { return {v.x,v.x,v.x,v.w}; }
inline static stdmath_bool4 stdmath_bool4_xxxw_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.x = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xxyx(stdmath_bool4 v) { return {v.x,v.x,v.y,v.x}; }
inline static stdmath_bool4 stdmath_bool4_xxyx_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.x = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xxyy(stdmath_bool4 v) { return {v.x,v.x,v.y,v.y}; }
inline static stdmath_bool4 stdmath_bool4_xxyy_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.x = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xxyz(stdmath_bool4 v) { return {v.x,v.x,v.y,v.z}; }
inline static stdmath_bool4 stdmath_bool4_xxyz_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.x = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xxyw(stdmath_bool4 v) { return {v.x,v.x,v.y,v.w}; }
inline static stdmath_bool4 stdmath_bool4_xxyw_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.x = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xxzx(stdmath_bool4 v) { return {v.x,v.x,v.z,v.x}; }
inline static stdmath_bool4 stdmath_bool4_xxzx_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.x = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xxzy(stdmath_bool4 v) { return {v.x,v.x,v.z,v.y}; }
inline static stdmath_bool4 stdmath_bool4_xxzy_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.x = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xxzz(stdmath_bool4 v) { return {v.x,v.x,v.z,v.z}; }
inline static stdmath_bool4 stdmath_bool4_xxzz_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.x = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xxzw(stdmath_bool4 v) { return {v.x,v.x,v.z,v.w}; }
inline static stdmath_bool4 stdmath_bool4_xxzw_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.x = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xxwx(stdmath_bool4 v) { return {v.x,v.x,v.w,v.x}; }
inline static stdmath_bool4 stdmath_bool4_xxwx_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.x = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xxwy(stdmath_bool4 v) { return {v.x,v.x,v.w,v.y}; }
inline static stdmath_bool4 stdmath_bool4_xxwy_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.x = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xxwz(stdmath_bool4 v) { return {v.x,v.x,v.w,v.z}; }
inline static stdmath_bool4 stdmath_bool4_xxwz_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.x = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xxww(stdmath_bool4 v) { return {v.x,v.x,v.w,v.w}; }
inline static stdmath_bool4 stdmath_bool4_xxww_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.x = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xyxx(stdmath_bool4 v) { return {v.x,v.y,v.x,v.x}; }
inline static stdmath_bool4 stdmath_bool4_xyxx_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.y = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xyxy(stdmath_bool4 v) { return {v.x,v.y,v.x,v.y}; }
inline static stdmath_bool4 stdmath_bool4_xyxy_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.y = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xyxz(stdmath_bool4 v) { return {v.x,v.y,v.x,v.z}; }
inline static stdmath_bool4 stdmath_bool4_xyxz_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.y = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xyxw(stdmath_bool4 v) { return {v.x,v.y,v.x,v.w}; }
inline static stdmath_bool4 stdmath_bool4_xyxw_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.y = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xyyx(stdmath_bool4 v) { return {v.x,v.y,v.y,v.x}; }
inline static stdmath_bool4 stdmath_bool4_xyyx_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.y = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xyyy(stdmath_bool4 v) { return {v.x,v.y,v.y,v.y}; }
inline static stdmath_bool4 stdmath_bool4_xyyy_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.y = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xyyz(stdmath_bool4 v) { return {v.x,v.y,v.y,v.z}; }
inline static stdmath_bool4 stdmath_bool4_xyyz_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.y = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xyyw(stdmath_bool4 v) { return {v.x,v.y,v.y,v.w}; }
inline static stdmath_bool4 stdmath_bool4_xyyw_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.y = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xyzx(stdmath_bool4 v) { return {v.x,v.y,v.z,v.x}; }
inline static stdmath_bool4 stdmath_bool4_xyzx_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.y = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xyzy(stdmath_bool4 v) { return {v.x,v.y,v.z,v.y}; }
inline static stdmath_bool4 stdmath_bool4_xyzy_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.y = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xyzz(stdmath_bool4 v) { return {v.x,v.y,v.z,v.z}; }
inline static stdmath_bool4 stdmath_bool4_xyzz_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.y = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xyzw(stdmath_bool4 v) { return {v.x,v.y,v.z,v.w}; }
inline static stdmath_bool4 stdmath_bool4_xyzw_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.y = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xywx(stdmath_bool4 v) { return {v.x,v.y,v.w,v.x}; }
inline static stdmath_bool4 stdmath_bool4_xywx_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.y = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xywy(stdmath_bool4 v) { return {v.x,v.y,v.w,v.y}; }
inline static stdmath_bool4 stdmath_bool4_xywy_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.y = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xywz(stdmath_bool4 v) { return {v.x,v.y,v.w,v.z}; }
inline static stdmath_bool4 stdmath_bool4_xywz_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.y = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xyww(stdmath_bool4 v) { return {v.x,v.y,v.w,v.w}; }
inline static stdmath_bool4 stdmath_bool4_xyww_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.y = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xzxx(stdmath_bool4 v) { return {v.x,v.z,v.x,v.x}; }
inline static stdmath_bool4 stdmath_bool4_xzxx_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.z = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xzxy(stdmath_bool4 v) { return {v.x,v.z,v.x,v.y}; }
inline static stdmath_bool4 stdmath_bool4_xzxy_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.z = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xzxz(stdmath_bool4 v) { return {v.x,v.z,v.x,v.z}; }
inline static stdmath_bool4 stdmath_bool4_xzxz_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.z = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xzxw(stdmath_bool4 v) { return {v.x,v.z,v.x,v.w}; }
inline static stdmath_bool4 stdmath_bool4_xzxw_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.z = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xzyx(stdmath_bool4 v) { return {v.x,v.z,v.y,v.x}; }
inline static stdmath_bool4 stdmath_bool4_xzyx_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.z = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xzyy(stdmath_bool4 v) { return {v.x,v.z,v.y,v.y}; }
inline static stdmath_bool4 stdmath_bool4_xzyy_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.z = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xzyz(stdmath_bool4 v) { return {v.x,v.z,v.y,v.z}; }
inline static stdmath_bool4 stdmath_bool4_xzyz_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.z = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xzyw(stdmath_bool4 v) { return {v.x,v.z,v.y,v.w}; }
inline static stdmath_bool4 stdmath_bool4_xzyw_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.z = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xzzx(stdmath_bool4 v) { return {v.x,v.z,v.z,v.x}; }
inline static stdmath_bool4 stdmath_bool4_xzzx_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.z = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xzzy(stdmath_bool4 v) { return {v.x,v.z,v.z,v.y}; }
inline static stdmath_bool4 stdmath_bool4_xzzy_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.z = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xzzz(stdmath_bool4 v) { return {v.x,v.z,v.z,v.z}; }
inline static stdmath_bool4 stdmath_bool4_xzzz_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.z = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xzzw(stdmath_bool4 v) { return {v.x,v.z,v.z,v.w}; }
inline static stdmath_bool4 stdmath_bool4_xzzw_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.z = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xzwx(stdmath_bool4 v) { return {v.x,v.z,v.w,v.x}; }
inline static stdmath_bool4 stdmath_bool4_xzwx_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.z = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xzwy(stdmath_bool4 v) { return {v.x,v.z,v.w,v.y}; }
inline static stdmath_bool4 stdmath_bool4_xzwy_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.z = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xzwz(stdmath_bool4 v) { return {v.x,v.z,v.w,v.z}; }
inline static stdmath_bool4 stdmath_bool4_xzwz_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.z = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xzww(stdmath_bool4 v) { return {v.x,v.z,v.w,v.w}; }
inline static stdmath_bool4 stdmath_bool4_xzww_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.z = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xwxx(stdmath_bool4 v) { return {v.x,v.w,v.x,v.x}; }
inline static stdmath_bool4 stdmath_bool4_xwxx_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.w = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xwxy(stdmath_bool4 v) { return {v.x,v.w,v.x,v.y}; }
inline static stdmath_bool4 stdmath_bool4_xwxy_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.w = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xwxz(stdmath_bool4 v) { return {v.x,v.w,v.x,v.z}; }
inline static stdmath_bool4 stdmath_bool4_xwxz_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.w = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xwxw(stdmath_bool4 v) { return {v.x,v.w,v.x,v.w}; }
inline static stdmath_bool4 stdmath_bool4_xwxw_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.w = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xwyx(stdmath_bool4 v) { return {v.x,v.w,v.y,v.x}; }
inline static stdmath_bool4 stdmath_bool4_xwyx_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.w = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xwyy(stdmath_bool4 v) { return {v.x,v.w,v.y,v.y}; }
inline static stdmath_bool4 stdmath_bool4_xwyy_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.w = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xwyz(stdmath_bool4 v) { return {v.x,v.w,v.y,v.z}; }
inline static stdmath_bool4 stdmath_bool4_xwyz_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.w = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xwyw(stdmath_bool4 v) { return {v.x,v.w,v.y,v.w}; }
inline static stdmath_bool4 stdmath_bool4_xwyw_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.w = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xwzx(stdmath_bool4 v) { return {v.x,v.w,v.z,v.x}; }
inline static stdmath_bool4 stdmath_bool4_xwzx_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.w = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xwzy(stdmath_bool4 v) { return {v.x,v.w,v.z,v.y}; }
inline static stdmath_bool4 stdmath_bool4_xwzy_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.w = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xwzz(stdmath_bool4 v) { return {v.x,v.w,v.z,v.z}; }
inline static stdmath_bool4 stdmath_bool4_xwzz_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.w = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xwzw(stdmath_bool4 v) { return {v.x,v.w,v.z,v.w}; }
inline static stdmath_bool4 stdmath_bool4_xwzw_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.w = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xwwx(stdmath_bool4 v) { return {v.x,v.w,v.w,v.x}; }
inline static stdmath_bool4 stdmath_bool4_xwwx_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.w = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xwwy(stdmath_bool4 v) { return {v.x,v.w,v.w,v.y}; }
inline static stdmath_bool4 stdmath_bool4_xwwy_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.w = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xwwz(stdmath_bool4 v) { return {v.x,v.w,v.w,v.z}; }
inline static stdmath_bool4 stdmath_bool4_xwwz_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.w = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_xwww(stdmath_bool4 v) { return {v.x,v.w,v.w,v.w}; }
inline static stdmath_bool4 stdmath_bool4_xwww_value(stdmath_bool4 v, stdmath_bool4 value) { v.x = value.x; v.w = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_yxxx(stdmath_bool4 v) { return {v.y,v.x,v.x,v.x}; }
inline static stdmath_bool4 stdmath_bool4_yxxx_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.x = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_yxxy(stdmath_bool4 v) { return {v.y,v.x,v.x,v.y}; }
inline static stdmath_bool4 stdmath_bool4_yxxy_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.x = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_yxxz(stdmath_bool4 v) { return {v.y,v.x,v.x,v.z}; }
inline static stdmath_bool4 stdmath_bool4_yxxz_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.x = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_yxxw(stdmath_bool4 v) { return {v.y,v.x,v.x,v.w}; }
inline static stdmath_bool4 stdmath_bool4_yxxw_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.x = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_yxyx(stdmath_bool4 v) { return {v.y,v.x,v.y,v.x}; }
inline static stdmath_bool4 stdmath_bool4_yxyx_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.x = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_yxyy(stdmath_bool4 v) { return {v.y,v.x,v.y,v.y}; }
inline static stdmath_bool4 stdmath_bool4_yxyy_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.x = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_yxyz(stdmath_bool4 v) { return {v.y,v.x,v.y,v.z}; }
inline static stdmath_bool4 stdmath_bool4_yxyz_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.x = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_yxyw(stdmath_bool4 v) { return {v.y,v.x,v.y,v.w}; }
inline static stdmath_bool4 stdmath_bool4_yxyw_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.x = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_yxzx(stdmath_bool4 v) { return {v.y,v.x,v.z,v.x}; }
inline static stdmath_bool4 stdmath_bool4_yxzx_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.x = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_yxzy(stdmath_bool4 v) { return {v.y,v.x,v.z,v.y}; }
inline static stdmath_bool4 stdmath_bool4_yxzy_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.x = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_yxzz(stdmath_bool4 v) { return {v.y,v.x,v.z,v.z}; }
inline static stdmath_bool4 stdmath_bool4_yxzz_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.x = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_yxzw(stdmath_bool4 v) { return {v.y,v.x,v.z,v.w}; }
inline static stdmath_bool4 stdmath_bool4_yxzw_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.x = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_yxwx(stdmath_bool4 v) { return {v.y,v.x,v.w,v.x}; }
inline static stdmath_bool4 stdmath_bool4_yxwx_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.x = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_yxwy(stdmath_bool4 v) { return {v.y,v.x,v.w,v.y}; }
inline static stdmath_bool4 stdmath_bool4_yxwy_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.x = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_yxwz(stdmath_bool4 v) { return {v.y,v.x,v.w,v.z}; }
inline static stdmath_bool4 stdmath_bool4_yxwz_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.x = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_yxww(stdmath_bool4 v) { return {v.y,v.x,v.w,v.w}; }
inline static stdmath_bool4 stdmath_bool4_yxww_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.x = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_yyxx(stdmath_bool4 v) { return {v.y,v.y,v.x,v.x}; }
inline static stdmath_bool4 stdmath_bool4_yyxx_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.y = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_yyxy(stdmath_bool4 v) { return {v.y,v.y,v.x,v.y}; }
inline static stdmath_bool4 stdmath_bool4_yyxy_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.y = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_yyxz(stdmath_bool4 v) { return {v.y,v.y,v.x,v.z}; }
inline static stdmath_bool4 stdmath_bool4_yyxz_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.y = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_yyxw(stdmath_bool4 v) { return {v.y,v.y,v.x,v.w}; }
inline static stdmath_bool4 stdmath_bool4_yyxw_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.y = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_yyyx(stdmath_bool4 v) { return {v.y,v.y,v.y,v.x}; }
inline static stdmath_bool4 stdmath_bool4_yyyx_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.y = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_yyyy(stdmath_bool4 v) { return {v.y,v.y,v.y,v.y}; }
inline static stdmath_bool4 stdmath_bool4_yyyy_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.y = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_yyyz(stdmath_bool4 v) { return {v.y,v.y,v.y,v.z}; }
inline static stdmath_bool4 stdmath_bool4_yyyz_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.y = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_yyyw(stdmath_bool4 v) { return {v.y,v.y,v.y,v.w}; }
inline static stdmath_bool4 stdmath_bool4_yyyw_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.y = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_yyzx(stdmath_bool4 v) { return {v.y,v.y,v.z,v.x}; }
inline static stdmath_bool4 stdmath_bool4_yyzx_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.y = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_yyzy(stdmath_bool4 v) { return {v.y,v.y,v.z,v.y}; }
inline static stdmath_bool4 stdmath_bool4_yyzy_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.y = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_yyzz(stdmath_bool4 v) { return {v.y,v.y,v.z,v.z}; }
inline static stdmath_bool4 stdmath_bool4_yyzz_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.y = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_yyzw(stdmath_bool4 v) { return {v.y,v.y,v.z,v.w}; }
inline static stdmath_bool4 stdmath_bool4_yyzw_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.y = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_yywx(stdmath_bool4 v) { return {v.y,v.y,v.w,v.x}; }
inline static stdmath_bool4 stdmath_bool4_yywx_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.y = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_yywy(stdmath_bool4 v) { return {v.y,v.y,v.w,v.y}; }
inline static stdmath_bool4 stdmath_bool4_yywy_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.y = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_yywz(stdmath_bool4 v) { return {v.y,v.y,v.w,v.z}; }
inline static stdmath_bool4 stdmath_bool4_yywz_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.y = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_yyww(stdmath_bool4 v) { return {v.y,v.y,v.w,v.w}; }
inline static stdmath_bool4 stdmath_bool4_yyww_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.y = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_yzxx(stdmath_bool4 v) { return {v.y,v.z,v.x,v.x}; }
inline static stdmath_bool4 stdmath_bool4_yzxx_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.z = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_yzxy(stdmath_bool4 v) { return {v.y,v.z,v.x,v.y}; }
inline static stdmath_bool4 stdmath_bool4_yzxy_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.z = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_yzxz(stdmath_bool4 v) { return {v.y,v.z,v.x,v.z}; }
inline static stdmath_bool4 stdmath_bool4_yzxz_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.z = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_yzxw(stdmath_bool4 v) { return {v.y,v.z,v.x,v.w}; }
inline static stdmath_bool4 stdmath_bool4_yzxw_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.z = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_yzyx(stdmath_bool4 v) { return {v.y,v.z,v.y,v.x}; }
inline static stdmath_bool4 stdmath_bool4_yzyx_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.z = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_yzyy(stdmath_bool4 v) { return {v.y,v.z,v.y,v.y}; }
inline static stdmath_bool4 stdmath_bool4_yzyy_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.z = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_yzyz(stdmath_bool4 v) { return {v.y,v.z,v.y,v.z}; }
inline static stdmath_bool4 stdmath_bool4_yzyz_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.z = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_yzyw(stdmath_bool4 v) { return {v.y,v.z,v.y,v.w}; }
inline static stdmath_bool4 stdmath_bool4_yzyw_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.z = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_yzzx(stdmath_bool4 v) { return {v.y,v.z,v.z,v.x}; }
inline static stdmath_bool4 stdmath_bool4_yzzx_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.z = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_yzzy(stdmath_bool4 v) { return {v.y,v.z,v.z,v.y}; }
inline static stdmath_bool4 stdmath_bool4_yzzy_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.z = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_yzzz(stdmath_bool4 v) { return {v.y,v.z,v.z,v.z}; }
inline static stdmath_bool4 stdmath_bool4_yzzz_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.z = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_yzzw(stdmath_bool4 v) { return {v.y,v.z,v.z,v.w}; }
inline static stdmath_bool4 stdmath_bool4_yzzw_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.z = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_yzwx(stdmath_bool4 v) { return {v.y,v.z,v.w,v.x}; }
inline static stdmath_bool4 stdmath_bool4_yzwx_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.z = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_yzwy(stdmath_bool4 v) { return {v.y,v.z,v.w,v.y}; }
inline static stdmath_bool4 stdmath_bool4_yzwy_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.z = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_yzwz(stdmath_bool4 v) { return {v.y,v.z,v.w,v.z}; }
inline static stdmath_bool4 stdmath_bool4_yzwz_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.z = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_yzww(stdmath_bool4 v) { return {v.y,v.z,v.w,v.w}; }
inline static stdmath_bool4 stdmath_bool4_yzww_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.z = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_ywxx(stdmath_bool4 v) { return {v.y,v.w,v.x,v.x}; }
inline static stdmath_bool4 stdmath_bool4_ywxx_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.w = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_ywxy(stdmath_bool4 v) { return {v.y,v.w,v.x,v.y}; }
inline static stdmath_bool4 stdmath_bool4_ywxy_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.w = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_ywxz(stdmath_bool4 v) { return {v.y,v.w,v.x,v.z}; }
inline static stdmath_bool4 stdmath_bool4_ywxz_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.w = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_ywxw(stdmath_bool4 v) { return {v.y,v.w,v.x,v.w}; }
inline static stdmath_bool4 stdmath_bool4_ywxw_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.w = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_ywyx(stdmath_bool4 v) { return {v.y,v.w,v.y,v.x}; }
inline static stdmath_bool4 stdmath_bool4_ywyx_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.w = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_ywyy(stdmath_bool4 v) { return {v.y,v.w,v.y,v.y}; }
inline static stdmath_bool4 stdmath_bool4_ywyy_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.w = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_ywyz(stdmath_bool4 v) { return {v.y,v.w,v.y,v.z}; }
inline static stdmath_bool4 stdmath_bool4_ywyz_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.w = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_ywyw(stdmath_bool4 v) { return {v.y,v.w,v.y,v.w}; }
inline static stdmath_bool4 stdmath_bool4_ywyw_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.w = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_ywzx(stdmath_bool4 v) { return {v.y,v.w,v.z,v.x}; }
inline static stdmath_bool4 stdmath_bool4_ywzx_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.w = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_ywzy(stdmath_bool4 v) { return {v.y,v.w,v.z,v.y}; }
inline static stdmath_bool4 stdmath_bool4_ywzy_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.w = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_ywzz(stdmath_bool4 v) { return {v.y,v.w,v.z,v.z}; }
inline static stdmath_bool4 stdmath_bool4_ywzz_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.w = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_ywzw(stdmath_bool4 v) { return {v.y,v.w,v.z,v.w}; }
inline static stdmath_bool4 stdmath_bool4_ywzw_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.w = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_ywwx(stdmath_bool4 v) { return {v.y,v.w,v.w,v.x}; }
inline static stdmath_bool4 stdmath_bool4_ywwx_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.w = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_ywwy(stdmath_bool4 v) { return {v.y,v.w,v.w,v.y}; }
inline static stdmath_bool4 stdmath_bool4_ywwy_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.w = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_ywwz(stdmath_bool4 v) { return {v.y,v.w,v.w,v.z}; }
inline static stdmath_bool4 stdmath_bool4_ywwz_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.w = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_ywww(stdmath_bool4 v) { return {v.y,v.w,v.w,v.w}; }
inline static stdmath_bool4 stdmath_bool4_ywww_value(stdmath_bool4 v, stdmath_bool4 value) { v.y = value.x; v.w = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zxxx(stdmath_bool4 v) { return {v.z,v.x,v.x,v.x}; }
inline static stdmath_bool4 stdmath_bool4_zxxx_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.x = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zxxy(stdmath_bool4 v) { return {v.z,v.x,v.x,v.y}; }
inline static stdmath_bool4 stdmath_bool4_zxxy_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.x = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zxxz(stdmath_bool4 v) { return {v.z,v.x,v.x,v.z}; }
inline static stdmath_bool4 stdmath_bool4_zxxz_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.x = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zxxw(stdmath_bool4 v) { return {v.z,v.x,v.x,v.w}; }
inline static stdmath_bool4 stdmath_bool4_zxxw_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.x = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zxyx(stdmath_bool4 v) { return {v.z,v.x,v.y,v.x}; }
inline static stdmath_bool4 stdmath_bool4_zxyx_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.x = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zxyy(stdmath_bool4 v) { return {v.z,v.x,v.y,v.y}; }
inline static stdmath_bool4 stdmath_bool4_zxyy_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.x = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zxyz(stdmath_bool4 v) { return {v.z,v.x,v.y,v.z}; }
inline static stdmath_bool4 stdmath_bool4_zxyz_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.x = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zxyw(stdmath_bool4 v) { return {v.z,v.x,v.y,v.w}; }
inline static stdmath_bool4 stdmath_bool4_zxyw_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.x = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zxzx(stdmath_bool4 v) { return {v.z,v.x,v.z,v.x}; }
inline static stdmath_bool4 stdmath_bool4_zxzx_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.x = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zxzy(stdmath_bool4 v) { return {v.z,v.x,v.z,v.y}; }
inline static stdmath_bool4 stdmath_bool4_zxzy_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.x = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zxzz(stdmath_bool4 v) { return {v.z,v.x,v.z,v.z}; }
inline static stdmath_bool4 stdmath_bool4_zxzz_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.x = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zxzw(stdmath_bool4 v) { return {v.z,v.x,v.z,v.w}; }
inline static stdmath_bool4 stdmath_bool4_zxzw_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.x = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zxwx(stdmath_bool4 v) { return {v.z,v.x,v.w,v.x}; }
inline static stdmath_bool4 stdmath_bool4_zxwx_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.x = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zxwy(stdmath_bool4 v) { return {v.z,v.x,v.w,v.y}; }
inline static stdmath_bool4 stdmath_bool4_zxwy_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.x = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zxwz(stdmath_bool4 v) { return {v.z,v.x,v.w,v.z}; }
inline static stdmath_bool4 stdmath_bool4_zxwz_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.x = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zxww(stdmath_bool4 v) { return {v.z,v.x,v.w,v.w}; }
inline static stdmath_bool4 stdmath_bool4_zxww_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.x = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zyxx(stdmath_bool4 v) { return {v.z,v.y,v.x,v.x}; }
inline static stdmath_bool4 stdmath_bool4_zyxx_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.y = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zyxy(stdmath_bool4 v) { return {v.z,v.y,v.x,v.y}; }
inline static stdmath_bool4 stdmath_bool4_zyxy_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.y = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zyxz(stdmath_bool4 v) { return {v.z,v.y,v.x,v.z}; }
inline static stdmath_bool4 stdmath_bool4_zyxz_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.y = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zyxw(stdmath_bool4 v) { return {v.z,v.y,v.x,v.w}; }
inline static stdmath_bool4 stdmath_bool4_zyxw_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.y = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zyyx(stdmath_bool4 v) { return {v.z,v.y,v.y,v.x}; }
inline static stdmath_bool4 stdmath_bool4_zyyx_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.y = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zyyy(stdmath_bool4 v) { return {v.z,v.y,v.y,v.y}; }
inline static stdmath_bool4 stdmath_bool4_zyyy_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.y = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zyyz(stdmath_bool4 v) { return {v.z,v.y,v.y,v.z}; }
inline static stdmath_bool4 stdmath_bool4_zyyz_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.y = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zyyw(stdmath_bool4 v) { return {v.z,v.y,v.y,v.w}; }
inline static stdmath_bool4 stdmath_bool4_zyyw_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.y = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zyzx(stdmath_bool4 v) { return {v.z,v.y,v.z,v.x}; }
inline static stdmath_bool4 stdmath_bool4_zyzx_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.y = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zyzy(stdmath_bool4 v) { return {v.z,v.y,v.z,v.y}; }
inline static stdmath_bool4 stdmath_bool4_zyzy_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.y = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zyzz(stdmath_bool4 v) { return {v.z,v.y,v.z,v.z}; }
inline static stdmath_bool4 stdmath_bool4_zyzz_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.y = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zyzw(stdmath_bool4 v) { return {v.z,v.y,v.z,v.w}; }
inline static stdmath_bool4 stdmath_bool4_zyzw_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.y = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zywx(stdmath_bool4 v) { return {v.z,v.y,v.w,v.x}; }
inline static stdmath_bool4 stdmath_bool4_zywx_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.y = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zywy(stdmath_bool4 v) { return {v.z,v.y,v.w,v.y}; }
inline static stdmath_bool4 stdmath_bool4_zywy_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.y = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zywz(stdmath_bool4 v) { return {v.z,v.y,v.w,v.z}; }
inline static stdmath_bool4 stdmath_bool4_zywz_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.y = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zyww(stdmath_bool4 v) { return {v.z,v.y,v.w,v.w}; }
inline static stdmath_bool4 stdmath_bool4_zyww_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.y = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zzxx(stdmath_bool4 v) { return {v.z,v.z,v.x,v.x}; }
inline static stdmath_bool4 stdmath_bool4_zzxx_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.z = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zzxy(stdmath_bool4 v) { return {v.z,v.z,v.x,v.y}; }
inline static stdmath_bool4 stdmath_bool4_zzxy_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.z = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zzxz(stdmath_bool4 v) { return {v.z,v.z,v.x,v.z}; }
inline static stdmath_bool4 stdmath_bool4_zzxz_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.z = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zzxw(stdmath_bool4 v) { return {v.z,v.z,v.x,v.w}; }
inline static stdmath_bool4 stdmath_bool4_zzxw_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.z = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zzyx(stdmath_bool4 v) { return {v.z,v.z,v.y,v.x}; }
inline static stdmath_bool4 stdmath_bool4_zzyx_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.z = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zzyy(stdmath_bool4 v) { return {v.z,v.z,v.y,v.y}; }
inline static stdmath_bool4 stdmath_bool4_zzyy_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.z = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zzyz(stdmath_bool4 v) { return {v.z,v.z,v.y,v.z}; }
inline static stdmath_bool4 stdmath_bool4_zzyz_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.z = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zzyw(stdmath_bool4 v) { return {v.z,v.z,v.y,v.w}; }
inline static stdmath_bool4 stdmath_bool4_zzyw_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.z = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zzzx(stdmath_bool4 v) { return {v.z,v.z,v.z,v.x}; }
inline static stdmath_bool4 stdmath_bool4_zzzx_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.z = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zzzy(stdmath_bool4 v) { return {v.z,v.z,v.z,v.y}; }
inline static stdmath_bool4 stdmath_bool4_zzzy_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.z = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zzzz(stdmath_bool4 v) { return {v.z,v.z,v.z,v.z}; }
inline static stdmath_bool4 stdmath_bool4_zzzz_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.z = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zzzw(stdmath_bool4 v) { return {v.z,v.z,v.z,v.w}; }
inline static stdmath_bool4 stdmath_bool4_zzzw_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.z = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zzwx(stdmath_bool4 v) { return {v.z,v.z,v.w,v.x}; }
inline static stdmath_bool4 stdmath_bool4_zzwx_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.z = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zzwy(stdmath_bool4 v) { return {v.z,v.z,v.w,v.y}; }
inline static stdmath_bool4 stdmath_bool4_zzwy_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.z = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zzwz(stdmath_bool4 v) { return {v.z,v.z,v.w,v.z}; }
inline static stdmath_bool4 stdmath_bool4_zzwz_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.z = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zzww(stdmath_bool4 v) { return {v.z,v.z,v.w,v.w}; }
inline static stdmath_bool4 stdmath_bool4_zzww_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.z = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zwxx(stdmath_bool4 v) { return {v.z,v.w,v.x,v.x}; }
inline static stdmath_bool4 stdmath_bool4_zwxx_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.w = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zwxy(stdmath_bool4 v) { return {v.z,v.w,v.x,v.y}; }
inline static stdmath_bool4 stdmath_bool4_zwxy_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.w = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zwxz(stdmath_bool4 v) { return {v.z,v.w,v.x,v.z}; }
inline static stdmath_bool4 stdmath_bool4_zwxz_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.w = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zwxw(stdmath_bool4 v) { return {v.z,v.w,v.x,v.w}; }
inline static stdmath_bool4 stdmath_bool4_zwxw_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.w = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zwyx(stdmath_bool4 v) { return {v.z,v.w,v.y,v.x}; }
inline static stdmath_bool4 stdmath_bool4_zwyx_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.w = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zwyy(stdmath_bool4 v) { return {v.z,v.w,v.y,v.y}; }
inline static stdmath_bool4 stdmath_bool4_zwyy_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.w = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zwyz(stdmath_bool4 v) { return {v.z,v.w,v.y,v.z}; }
inline static stdmath_bool4 stdmath_bool4_zwyz_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.w = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zwyw(stdmath_bool4 v) { return {v.z,v.w,v.y,v.w}; }
inline static stdmath_bool4 stdmath_bool4_zwyw_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.w = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zwzx(stdmath_bool4 v) { return {v.z,v.w,v.z,v.x}; }
inline static stdmath_bool4 stdmath_bool4_zwzx_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.w = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zwzy(stdmath_bool4 v) { return {v.z,v.w,v.z,v.y}; }
inline static stdmath_bool4 stdmath_bool4_zwzy_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.w = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zwzz(stdmath_bool4 v) { return {v.z,v.w,v.z,v.z}; }
inline static stdmath_bool4 stdmath_bool4_zwzz_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.w = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zwzw(stdmath_bool4 v) { return {v.z,v.w,v.z,v.w}; }
inline static stdmath_bool4 stdmath_bool4_zwzw_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.w = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zwwx(stdmath_bool4 v) { return {v.z,v.w,v.w,v.x}; }
inline static stdmath_bool4 stdmath_bool4_zwwx_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.w = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zwwy(stdmath_bool4 v) { return {v.z,v.w,v.w,v.y}; }
inline static stdmath_bool4 stdmath_bool4_zwwy_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.w = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zwwz(stdmath_bool4 v) { return {v.z,v.w,v.w,v.z}; }
inline static stdmath_bool4 stdmath_bool4_zwwz_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.w = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_zwww(stdmath_bool4 v) { return {v.z,v.w,v.w,v.w}; }
inline static stdmath_bool4 stdmath_bool4_zwww_value(stdmath_bool4 v, stdmath_bool4 value) { v.z = value.x; v.w = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wxxx(stdmath_bool4 v) { return {v.w,v.x,v.x,v.x}; }
inline static stdmath_bool4 stdmath_bool4_wxxx_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.x = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wxxy(stdmath_bool4 v) { return {v.w,v.x,v.x,v.y}; }
inline static stdmath_bool4 stdmath_bool4_wxxy_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.x = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wxxz(stdmath_bool4 v) { return {v.w,v.x,v.x,v.z}; }
inline static stdmath_bool4 stdmath_bool4_wxxz_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.x = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wxxw(stdmath_bool4 v) { return {v.w,v.x,v.x,v.w}; }
inline static stdmath_bool4 stdmath_bool4_wxxw_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.x = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wxyx(stdmath_bool4 v) { return {v.w,v.x,v.y,v.x}; }
inline static stdmath_bool4 stdmath_bool4_wxyx_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.x = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wxyy(stdmath_bool4 v) { return {v.w,v.x,v.y,v.y}; }
inline static stdmath_bool4 stdmath_bool4_wxyy_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.x = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wxyz(stdmath_bool4 v) { return {v.w,v.x,v.y,v.z}; }
inline static stdmath_bool4 stdmath_bool4_wxyz_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.x = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wxyw(stdmath_bool4 v) { return {v.w,v.x,v.y,v.w}; }
inline static stdmath_bool4 stdmath_bool4_wxyw_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.x = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wxzx(stdmath_bool4 v) { return {v.w,v.x,v.z,v.x}; }
inline static stdmath_bool4 stdmath_bool4_wxzx_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.x = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wxzy(stdmath_bool4 v) { return {v.w,v.x,v.z,v.y}; }
inline static stdmath_bool4 stdmath_bool4_wxzy_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.x = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wxzz(stdmath_bool4 v) { return {v.w,v.x,v.z,v.z}; }
inline static stdmath_bool4 stdmath_bool4_wxzz_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.x = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wxzw(stdmath_bool4 v) { return {v.w,v.x,v.z,v.w}; }
inline static stdmath_bool4 stdmath_bool4_wxzw_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.x = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wxwx(stdmath_bool4 v) { return {v.w,v.x,v.w,v.x}; }
inline static stdmath_bool4 stdmath_bool4_wxwx_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.x = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wxwy(stdmath_bool4 v) { return {v.w,v.x,v.w,v.y}; }
inline static stdmath_bool4 stdmath_bool4_wxwy_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.x = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wxwz(stdmath_bool4 v) { return {v.w,v.x,v.w,v.z}; }
inline static stdmath_bool4 stdmath_bool4_wxwz_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.x = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wxww(stdmath_bool4 v) { return {v.w,v.x,v.w,v.w}; }
inline static stdmath_bool4 stdmath_bool4_wxww_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.x = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wyxx(stdmath_bool4 v) { return {v.w,v.y,v.x,v.x}; }
inline static stdmath_bool4 stdmath_bool4_wyxx_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.y = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wyxy(stdmath_bool4 v) { return {v.w,v.y,v.x,v.y}; }
inline static stdmath_bool4 stdmath_bool4_wyxy_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.y = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wyxz(stdmath_bool4 v) { return {v.w,v.y,v.x,v.z}; }
inline static stdmath_bool4 stdmath_bool4_wyxz_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.y = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wyxw(stdmath_bool4 v) { return {v.w,v.y,v.x,v.w}; }
inline static stdmath_bool4 stdmath_bool4_wyxw_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.y = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wyyx(stdmath_bool4 v) { return {v.w,v.y,v.y,v.x}; }
inline static stdmath_bool4 stdmath_bool4_wyyx_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.y = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wyyy(stdmath_bool4 v) { return {v.w,v.y,v.y,v.y}; }
inline static stdmath_bool4 stdmath_bool4_wyyy_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.y = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wyyz(stdmath_bool4 v) { return {v.w,v.y,v.y,v.z}; }
inline static stdmath_bool4 stdmath_bool4_wyyz_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.y = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wyyw(stdmath_bool4 v) { return {v.w,v.y,v.y,v.w}; }
inline static stdmath_bool4 stdmath_bool4_wyyw_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.y = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wyzx(stdmath_bool4 v) { return {v.w,v.y,v.z,v.x}; }
inline static stdmath_bool4 stdmath_bool4_wyzx_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.y = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wyzy(stdmath_bool4 v) { return {v.w,v.y,v.z,v.y}; }
inline static stdmath_bool4 stdmath_bool4_wyzy_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.y = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wyzz(stdmath_bool4 v) { return {v.w,v.y,v.z,v.z}; }
inline static stdmath_bool4 stdmath_bool4_wyzz_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.y = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wyzw(stdmath_bool4 v) { return {v.w,v.y,v.z,v.w}; }
inline static stdmath_bool4 stdmath_bool4_wyzw_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.y = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wywx(stdmath_bool4 v) { return {v.w,v.y,v.w,v.x}; }
inline static stdmath_bool4 stdmath_bool4_wywx_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.y = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wywy(stdmath_bool4 v) { return {v.w,v.y,v.w,v.y}; }
inline static stdmath_bool4 stdmath_bool4_wywy_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.y = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wywz(stdmath_bool4 v) { return {v.w,v.y,v.w,v.z}; }
inline static stdmath_bool4 stdmath_bool4_wywz_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.y = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wyww(stdmath_bool4 v) { return {v.w,v.y,v.w,v.w}; }
inline static stdmath_bool4 stdmath_bool4_wyww_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.y = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wzxx(stdmath_bool4 v) { return {v.w,v.z,v.x,v.x}; }
inline static stdmath_bool4 stdmath_bool4_wzxx_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.z = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wzxy(stdmath_bool4 v) { return {v.w,v.z,v.x,v.y}; }
inline static stdmath_bool4 stdmath_bool4_wzxy_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.z = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wzxz(stdmath_bool4 v) { return {v.w,v.z,v.x,v.z}; }
inline static stdmath_bool4 stdmath_bool4_wzxz_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.z = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wzxw(stdmath_bool4 v) { return {v.w,v.z,v.x,v.w}; }
inline static stdmath_bool4 stdmath_bool4_wzxw_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.z = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wzyx(stdmath_bool4 v) { return {v.w,v.z,v.y,v.x}; }
inline static stdmath_bool4 stdmath_bool4_wzyx_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.z = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wzyy(stdmath_bool4 v) { return {v.w,v.z,v.y,v.y}; }
inline static stdmath_bool4 stdmath_bool4_wzyy_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.z = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wzyz(stdmath_bool4 v) { return {v.w,v.z,v.y,v.z}; }
inline static stdmath_bool4 stdmath_bool4_wzyz_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.z = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wzyw(stdmath_bool4 v) { return {v.w,v.z,v.y,v.w}; }
inline static stdmath_bool4 stdmath_bool4_wzyw_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.z = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wzzx(stdmath_bool4 v) { return {v.w,v.z,v.z,v.x}; }
inline static stdmath_bool4 stdmath_bool4_wzzx_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.z = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wzzy(stdmath_bool4 v) { return {v.w,v.z,v.z,v.y}; }
inline static stdmath_bool4 stdmath_bool4_wzzy_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.z = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wzzz(stdmath_bool4 v) { return {v.w,v.z,v.z,v.z}; }
inline static stdmath_bool4 stdmath_bool4_wzzz_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.z = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wzzw(stdmath_bool4 v) { return {v.w,v.z,v.z,v.w}; }
inline static stdmath_bool4 stdmath_bool4_wzzw_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.z = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wzwx(stdmath_bool4 v) { return {v.w,v.z,v.w,v.x}; }
inline static stdmath_bool4 stdmath_bool4_wzwx_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.z = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wzwy(stdmath_bool4 v) { return {v.w,v.z,v.w,v.y}; }
inline static stdmath_bool4 stdmath_bool4_wzwy_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.z = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wzwz(stdmath_bool4 v) { return {v.w,v.z,v.w,v.z}; }
inline static stdmath_bool4 stdmath_bool4_wzwz_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.z = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wzww(stdmath_bool4 v) { return {v.w,v.z,v.w,v.w}; }
inline static stdmath_bool4 stdmath_bool4_wzww_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.z = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wwxx(stdmath_bool4 v) { return {v.w,v.w,v.x,v.x}; }
inline static stdmath_bool4 stdmath_bool4_wwxx_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.w = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wwxy(stdmath_bool4 v) { return {v.w,v.w,v.x,v.y}; }
inline static stdmath_bool4 stdmath_bool4_wwxy_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.w = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wwxz(stdmath_bool4 v) { return {v.w,v.w,v.x,v.z}; }
inline static stdmath_bool4 stdmath_bool4_wwxz_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.w = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wwxw(stdmath_bool4 v) { return {v.w,v.w,v.x,v.w}; }
inline static stdmath_bool4 stdmath_bool4_wwxw_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.w = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wwyx(stdmath_bool4 v) { return {v.w,v.w,v.y,v.x}; }
inline static stdmath_bool4 stdmath_bool4_wwyx_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.w = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wwyy(stdmath_bool4 v) { return {v.w,v.w,v.y,v.y}; }
inline static stdmath_bool4 stdmath_bool4_wwyy_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.w = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wwyz(stdmath_bool4 v) { return {v.w,v.w,v.y,v.z}; }
inline static stdmath_bool4 stdmath_bool4_wwyz_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.w = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wwyw(stdmath_bool4 v) { return {v.w,v.w,v.y,v.w}; }
inline static stdmath_bool4 stdmath_bool4_wwyw_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.w = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wwzx(stdmath_bool4 v) { return {v.w,v.w,v.z,v.x}; }
inline static stdmath_bool4 stdmath_bool4_wwzx_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.w = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wwzy(stdmath_bool4 v) { return {v.w,v.w,v.z,v.y}; }
inline static stdmath_bool4 stdmath_bool4_wwzy_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.w = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wwzz(stdmath_bool4 v) { return {v.w,v.w,v.z,v.z}; }
inline static stdmath_bool4 stdmath_bool4_wwzz_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.w = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wwzw(stdmath_bool4 v) { return {v.w,v.w,v.z,v.w}; }
inline static stdmath_bool4 stdmath_bool4_wwzw_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.w = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wwwx(stdmath_bool4 v) { return {v.w,v.w,v.w,v.x}; }
inline static stdmath_bool4 stdmath_bool4_wwwx_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.w = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wwwy(stdmath_bool4 v) { return {v.w,v.w,v.w,v.y}; }
inline static stdmath_bool4 stdmath_bool4_wwwy_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.w = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wwwz(stdmath_bool4 v) { return {v.w,v.w,v.w,v.z}; }
inline static stdmath_bool4 stdmath_bool4_wwwz_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.w = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_bool4 stdmath_bool4_wwww(stdmath_bool4 v) { return {v.w,v.w,v.w,v.w}; }
inline static stdmath_bool4 stdmath_bool4_wwww_value(stdmath_bool4 v, stdmath_bool4 value) { v.w = value.x; v.w = value.y; v.w = value.z; v.w = value.w; return v; }


#ifdef STDMATH_IMPLEMENTATION
#ifndef __cplusplus
#error "The stdmath implementations require a C++ compiler"
#endif

import stdmath.slang;

stdmath::bool4 c(stdmath_bool4 c) {
	return (stdmath::bool4&)c;
}
stdmath_bool4 c(stdmath::bool4 c) {
	return (stdmath_bool4&)c;
}

stdmath_bool4 stdmath_bool4_broadcast(bool all) {
	return c(stdmath::bool4((stdmath::bool4::underlying_type)all));
}

stdmath_bool4 stdmath_bool4_add(stdmath_bool4 a, stdmath_bool4 b) {
	return c(c(a) + c(b));
}
stdmath_bool4 stdmath_bool4_subtract(stdmath_bool4 a, stdmath_bool4 b) {
	return c(c(a) - c(b));
}
stdmath_bool4 stdmath_bool4_negate(stdmath_bool4 v) {
	return c(stdmath::bool4(-(stdmath::vector<bool, 4>)c(v)));
}
stdmath_bool4 stdmath_bool4_multiply(stdmath_bool4 a, stdmath_bool4 b) {
	return c(c(a) * c(b));
}
stdmath_bool4 stdmath_bool4_divide(stdmath_bool4 a, stdmath_bool4 b) {
	return c(c(a) / c(b));
}
stdmath_bool4 stdmath_bool4_scale(stdmath_bool4 v, bool s) {
	return c(c(v) * (stdmath::bool4::underlying_type)s);
}

#if false
stdmath_bool4 stdmath_bool4_modulus(stdmath_bool4 a, stdmath_bool4 b) {
	return c(c(a) % c(b));
}
stdmath_bool4 stdmath_bool4_logical_not(stdmath_bool4 v) {
	return c(!c(v));
}
stdmath_bool4 stdmath_bool4_bitwise_not(stdmath_bool4 v) {
	return c(~c(v));
}
stdmath_bool4 stdmath_bool4_logical_and(stdmath_bool4 a, stdmath_bool4 b) {
	return c(c(a) && c(b));
}
stdmath_bool4 stdmath_bool4_bitwise_and(stdmath_bool4 a, stdmath_bool4 b) {
	return c(c(a) & c(b));
}
stdmath_bool4 stdmath_bool4_logical_or(stdmath_bool4 a, stdmath_bool4 b) {
	return c(c(a) || c(b));
}
stdmath_bool4 stdmath_bool4_bitwise_or(stdmath_bool4 a, stdmath_bool4 b) {
	return c(c(a) | c(b));
}
stdmath_bool4 stdmath_bool4_bitwise_xor(stdmath_bool4 a, stdmath_bool4 b) {
	return c(c(a) ^ c(b));
}
stdmath_bool4 stdmath_bool4_shift_left(stdmath_bool4 a, stdmath_bool4 b) {
	return c(c(a) << c(b));
}
stdmath_bool4 stdmath_bool4_shift_right(stdmath_bool4 a, stdmath_bool4 b) {
	return c(c(a) >> c(b));
}
#endif

stdmath_bool4 stdmath_bool4_equal_to(stdmath_bool4 a, stdmath_bool4 b) {
	return c(c(a) == c(b));
}
stdmath_bool4 stdmath_bool4_not_equal_to(stdmath_bool4 a, stdmath_bool4 b) {
	return c(c(a) != c(b));
}
stdmath_bool4 stdmath_bool4_less_than(stdmath_bool4 a, stdmath_bool4 b) {
	return c(c(a) < c(b));
}
stdmath_bool4 stdmath_bool4_less_than_or_equal_to(stdmath_bool4 a, stdmath_bool4 b) {
	return c(c(a) <= c(b));
}
stdmath_bool4 stdmath_bool4_greater_than(stdmath_bool4 a, stdmath_bool4 b) {
	return c(c(a) > c(b));
}
stdmath_bool4 stdmath_bool4_greater_than_or_equal_to(stdmath_bool4 a, stdmath_bool4 b) {
	return c(c(a) >= c(b));
}

bool stdmath_bool4_length_squared(stdmath_bool4 v)  {
	return (bool)c(v).length_squared();
}
bool stdmath_bool4_length(stdmath_bool4 v)  {
	return (bool)c(v).length();
}
bool stdmath_bool4_dot(stdmath_bool4 a, stdmath_bool4 b)  {
	return (bool)dot(c(a), c(b));
}
bool stdmath_bool4_min_element(stdmath_bool4 v)  {
	return (bool)c(v).min_element();
}
bool stdmath_bool4_max_element(stdmath_bool4 v)  {
	return (bool)c(v).max_element();
}

stdmath_bool4 stdmath_bool4_elementwise_transform(stdmath_bool4 v, bool(*func)(bool)) {
	return c(c(v).elementwise_transform(func));
}
// bool stdmath_bool4_reduce_elements(stdmath_bool4 v, bool initial_value, bool(*reducer)(stdmath_bool4, stdmath_bool4)) {
// 	return c(v).reduce_elements(initial_value, reducer);
// }

#if 4 == 3
stdmath_bool4 stdmath_bool4_cross(stdmath_bool4 a, stdmath_bool4 b) {
	return c(cross(c(a), c(b)));
}
#endif

stdmath_bool4 stdmath_bool4_min(stdmath_bool4 a, stdmath_bool4 b) {
	return c(min(c(a), c(b)));
}
stdmath_bool4 stdmath_bool4_max(stdmath_bool4 a, stdmath_bool4 b) {
	return c(max(c(a), c(b)));
}
stdmath_bool4 stdmath_bool4_normalize(stdmath_bool4 v) {
	return c(normalize(c(v)));
}
stdmath_bool4 stdmath_bool4_lerp(stdmath_bool4 a, stdmath_bool4 b, float t) {
	return c(lerp(c(a), c(b), t));
}
stdmath_bool4 stdmath_bool4_clamp(stdmath_bool4 a, stdmath_bool4 min, stdmath_bool4 max) {
	return c(clamp(c(a), c(min), c(max)));
}
stdmath_bool4 stdmath_bool4_reflect(stdmath_bool4 a, stdmath_bool4 b) {
	return c(reflect(c(a), c(b)));
}
stdmath_bool4 stdmath_bool4_approximately_equal(stdmath_bool4 a, stdmath_bool4 b) {
	return c(approximately_equal(c(a), c(b)));
}

#if true
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

#endif // __STDMATH_bool4_H__