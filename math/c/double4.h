#ifndef __STDMATH_double4_H__
#define __STDMATH_double4_H__

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
#include "double1.h"
#elif 4 == 3
#include "double2.h"
#include "double1.h"
#elif 4 == 4
#include "double3.h"
#include "double2.h"
#include "double1.h"
#endif
#include "util.h"

#if 4 == 1
union stdmath_double1 {
	struct {
		double x;
	};
	double data[1];
};
#elif 4 == 2
union stdmath_double2 {
	struct {
		double x, y;
	};
	struct {
		double u, v;
	};
	double data[2];
};
#elif 4 == 3
union stdmath_double3 {
	struct {
		double x, y, z;
	};
	struct {
		double r, g, b;
	};
	struct {
		double h, s, v;
	};
	double data[4]; // double3s are aligned as if they were double4s
};
#elif 4 == 4
union stdmath_double4 {
	struct {
		double x, y, z, w;
	};
	struct {
		double r, g, b, a;
	};
	struct {
		double h, s, v;
	};
	double data[4];
};
#endif

stdmath_double4 stdmath_double4_broadcast(double all);

stdmath_double4 stdmath_double4_add(stdmath_double4 a, stdmath_double4 b);
stdmath_double4 stdmath_double4_subtract(stdmath_double4 a, stdmath_double4 b);
stdmath_double4 stdmath_double4_negate(stdmath_double4 v);
stdmath_double4 stdmath_double4_multiply(stdmath_double4 a, stdmath_double4 b);
stdmath_double4 stdmath_double4_divide(stdmath_double4 a, stdmath_double4 b);
stdmath_double4 stdmath_double4_scale(stdmath_double4 v, double s);

#if false
stdmath_double4 stdmath_double4_modulus(stdmath_double4 a, stdmath_double4 b);
stdmath_double4 stdmath_double4_logical_not(stdmath_double4 v);
stdmath_double4 stdmath_double4_bitwise_not(stdmath_double4 v);
stdmath_double4 stdmath_double4_logical_and(stdmath_double4 a, stdmath_double4 b);
stdmath_double4 stdmath_double4_bitwise_and(stdmath_double4 a, stdmath_double4 b);
stdmath_double4 stdmath_double4_logical_or(stdmath_double4 a, stdmath_double4 b);
stdmath_double4 stdmath_double4_bitwise_or(stdmath_double4 a, stdmath_double4 b);
stdmath_double4 stdmath_double4_bitwise_xor(stdmath_double4 a, stdmath_double4 b);
stdmath_double4 stdmath_double4_shift_left(stdmath_double4 a, stdmath_double4 b);
stdmath_double4 stdmath_double4_shift_right(stdmath_double4 a, stdmath_double4 b);
#endif

stdmath_bool4 stdmath_double4_equal_to(stdmath_double4 a, stdmath_double4 b);
stdmath_bool4 stdmath_double4_not_equal_to(stdmath_double4 a, stdmath_double4 b);
stdmath_bool4 stdmath_double4_less_than(stdmath_double4 a, stdmath_double4 b);
stdmath_bool4 stdmath_double4_less_than_or_equal_to(stdmath_double4 a, stdmath_double4 b);
stdmath_bool4 stdmath_double4_greater_than(stdmath_double4 a, stdmath_double4 b);
stdmath_bool4 stdmath_double4_greater_than_or_equal_to(stdmath_double4 a, stdmath_double4 b);

double stdmath_double4_length_squared(stdmath_double4 v);
double stdmath_double4_length(stdmath_double4 v);
double stdmath_double4_dot(stdmath_double4 v);
double stdmath_double4_min_element(stdmath_double4 v);
double stdmath_double4_max_element(stdmath_double4 v);

stdmath_double4 stdmath_double4_elementwise_transform(stdmath_double4 v, double(*func)(double));
// double stdmath_double4_reduce_elements(stdmath_double4 v, double initial_value, double(*reducer)(stdmath_double4, stdmath_double4));

#if 4 == 3
stdmath_double3 stdmath_double3_cross(stdmath_double3 a, stdmath_double3 b);
#endif

stdmath_double4 stdmath_double4_min(stdmath_double4 a, stdmath_double4 b);
stdmath_double4 stdmath_double4_max(stdmath_double4 a, stdmath_double4 b);
stdmath_double4 stdmath_double4_normalize(stdmath_double4 v);
stdmath_double4 stdmath_double4_lerp(stdmath_double4 a, stdmath_double4 b, float t);
stdmath_double4 stdmath_double4_clamp(stdmath_double4 a, stdmath_double4 min, stdmath_double4 max);
stdmath_double4 stdmath_double4_reflect(stdmath_double4 a, stdmath_double4 b);
stdmath_bool4 stdmath_double4_approximately_equal(stdmath_double4 a, stdmath_double4 b);

#if false
bool stdmath_bool4_all_of(stdmath_bool4 v);
bool stdmath_bool4_any_of(stdmath_bool4 v);
bool stdmath_bool4_none_of(stdmath_bool4 v);
bool stdmath_bool4_some_of(stdmath_bool4 v);
#endif

inline static stdmath_double1 stdmath_double4_x(stdmath_double4 v) { return {v.x}; }
inline static stdmath_double4 stdmath_double4_x_value(stdmath_double4 v, stdmath_double1 value) { v.x = value.x; return v; }
inline static stdmath_double1 stdmath_double4_y(stdmath_double4 v) { return {v.y}; }
inline static stdmath_double4 stdmath_double4_y_value(stdmath_double4 v, stdmath_double1 value) { v.y = value.x; return v; }
inline static stdmath_double1 stdmath_double4_z(stdmath_double4 v) { return {v.z}; }
inline static stdmath_double4 stdmath_double4_z_value(stdmath_double4 v, stdmath_double1 value) { v.z = value.x; return v; }
inline static stdmath_double1 stdmath_double4_w(stdmath_double4 v) { return {v.w}; }
inline static stdmath_double4 stdmath_double4_w_value(stdmath_double4 v, stdmath_double1 value) { v.w = value.x; return v; }
inline static stdmath_double2 stdmath_double4_xx(stdmath_double4 v) { return {v.x,v.x}; }
inline static stdmath_double4 stdmath_double4_xx_value(stdmath_double4 v, stdmath_double2 value) { v.x = value.x; v.x = value.y; return v; }
inline static stdmath_double2 stdmath_double4_xy(stdmath_double4 v) { return {v.x,v.y}; }
inline static stdmath_double4 stdmath_double4_xy_value(stdmath_double4 v, stdmath_double2 value) { v.x = value.x; v.y = value.y; return v; }
inline static stdmath_double2 stdmath_double4_xz(stdmath_double4 v) { return {v.x,v.z}; }
inline static stdmath_double4 stdmath_double4_xz_value(stdmath_double4 v, stdmath_double2 value) { v.x = value.x; v.z = value.y; return v; }
inline static stdmath_double2 stdmath_double4_xw(stdmath_double4 v) { return {v.x,v.w}; }
inline static stdmath_double4 stdmath_double4_xw_value(stdmath_double4 v, stdmath_double2 value) { v.x = value.x; v.w = value.y; return v; }
inline static stdmath_double2 stdmath_double4_yx(stdmath_double4 v) { return {v.y,v.x}; }
inline static stdmath_double4 stdmath_double4_yx_value(stdmath_double4 v, stdmath_double2 value) { v.y = value.x; v.x = value.y; return v; }
inline static stdmath_double2 stdmath_double4_yy(stdmath_double4 v) { return {v.y,v.y}; }
inline static stdmath_double4 stdmath_double4_yy_value(stdmath_double4 v, stdmath_double2 value) { v.y = value.x; v.y = value.y; return v; }
inline static stdmath_double2 stdmath_double4_yz(stdmath_double4 v) { return {v.y,v.z}; }
inline static stdmath_double4 stdmath_double4_yz_value(stdmath_double4 v, stdmath_double2 value) { v.y = value.x; v.z = value.y; return v; }
inline static stdmath_double2 stdmath_double4_yw(stdmath_double4 v) { return {v.y,v.w}; }
inline static stdmath_double4 stdmath_double4_yw_value(stdmath_double4 v, stdmath_double2 value) { v.y = value.x; v.w = value.y; return v; }
inline static stdmath_double2 stdmath_double4_zx(stdmath_double4 v) { return {v.z,v.x}; }
inline static stdmath_double4 stdmath_double4_zx_value(stdmath_double4 v, stdmath_double2 value) { v.z = value.x; v.x = value.y; return v; }
inline static stdmath_double2 stdmath_double4_zy(stdmath_double4 v) { return {v.z,v.y}; }
inline static stdmath_double4 stdmath_double4_zy_value(stdmath_double4 v, stdmath_double2 value) { v.z = value.x; v.y = value.y; return v; }
inline static stdmath_double2 stdmath_double4_zz(stdmath_double4 v) { return {v.z,v.z}; }
inline static stdmath_double4 stdmath_double4_zz_value(stdmath_double4 v, stdmath_double2 value) { v.z = value.x; v.z = value.y; return v; }
inline static stdmath_double2 stdmath_double4_zw(stdmath_double4 v) { return {v.z,v.w}; }
inline static stdmath_double4 stdmath_double4_zw_value(stdmath_double4 v, stdmath_double2 value) { v.z = value.x; v.w = value.y; return v; }
inline static stdmath_double2 stdmath_double4_wx(stdmath_double4 v) { return {v.w,v.x}; }
inline static stdmath_double4 stdmath_double4_wx_value(stdmath_double4 v, stdmath_double2 value) { v.w = value.x; v.x = value.y; return v; }
inline static stdmath_double2 stdmath_double4_wy(stdmath_double4 v) { return {v.w,v.y}; }
inline static stdmath_double4 stdmath_double4_wy_value(stdmath_double4 v, stdmath_double2 value) { v.w = value.x; v.y = value.y; return v; }
inline static stdmath_double2 stdmath_double4_wz(stdmath_double4 v) { return {v.w,v.z}; }
inline static stdmath_double4 stdmath_double4_wz_value(stdmath_double4 v, stdmath_double2 value) { v.w = value.x; v.z = value.y; return v; }
inline static stdmath_double2 stdmath_double4_ww(stdmath_double4 v) { return {v.w,v.w}; }
inline static stdmath_double4 stdmath_double4_ww_value(stdmath_double4 v, stdmath_double2 value) { v.w = value.x; v.w = value.y; return v; }
inline static stdmath_double3 stdmath_double4_xxx(stdmath_double4 v) { return {v.x,v.x,v.x}; }
inline static stdmath_double4 stdmath_double4_xxx_value(stdmath_double4 v, stdmath_double3 value) { v.x = value.x; v.x = value.y; v.x = value.z; return v; }
inline static stdmath_double3 stdmath_double4_xxy(stdmath_double4 v) { return {v.x,v.x,v.y}; }
inline static stdmath_double4 stdmath_double4_xxy_value(stdmath_double4 v, stdmath_double3 value) { v.x = value.x; v.x = value.y; v.y = value.z; return v; }
inline static stdmath_double3 stdmath_double4_xxz(stdmath_double4 v) { return {v.x,v.x,v.z}; }
inline static stdmath_double4 stdmath_double4_xxz_value(stdmath_double4 v, stdmath_double3 value) { v.x = value.x; v.x = value.y; v.z = value.z; return v; }
inline static stdmath_double3 stdmath_double4_xxw(stdmath_double4 v) { return {v.x,v.x,v.w}; }
inline static stdmath_double4 stdmath_double4_xxw_value(stdmath_double4 v, stdmath_double3 value) { v.x = value.x; v.x = value.y; v.w = value.z; return v; }
inline static stdmath_double3 stdmath_double4_xyx(stdmath_double4 v) { return {v.x,v.y,v.x}; }
inline static stdmath_double4 stdmath_double4_xyx_value(stdmath_double4 v, stdmath_double3 value) { v.x = value.x; v.y = value.y; v.x = value.z; return v; }
inline static stdmath_double3 stdmath_double4_xyy(stdmath_double4 v) { return {v.x,v.y,v.y}; }
inline static stdmath_double4 stdmath_double4_xyy_value(stdmath_double4 v, stdmath_double3 value) { v.x = value.x; v.y = value.y; v.y = value.z; return v; }
inline static stdmath_double3 stdmath_double4_xyz(stdmath_double4 v) { return {v.x,v.y,v.z}; }
inline static stdmath_double4 stdmath_double4_xyz_value(stdmath_double4 v, stdmath_double3 value) { v.x = value.x; v.y = value.y; v.z = value.z; return v; }
inline static stdmath_double3 stdmath_double4_xyw(stdmath_double4 v) { return {v.x,v.y,v.w}; }
inline static stdmath_double4 stdmath_double4_xyw_value(stdmath_double4 v, stdmath_double3 value) { v.x = value.x; v.y = value.y; v.w = value.z; return v; }
inline static stdmath_double3 stdmath_double4_xzx(stdmath_double4 v) { return {v.x,v.z,v.x}; }
inline static stdmath_double4 stdmath_double4_xzx_value(stdmath_double4 v, stdmath_double3 value) { v.x = value.x; v.z = value.y; v.x = value.z; return v; }
inline static stdmath_double3 stdmath_double4_xzy(stdmath_double4 v) { return {v.x,v.z,v.y}; }
inline static stdmath_double4 stdmath_double4_xzy_value(stdmath_double4 v, stdmath_double3 value) { v.x = value.x; v.z = value.y; v.y = value.z; return v; }
inline static stdmath_double3 stdmath_double4_xzz(stdmath_double4 v) { return {v.x,v.z,v.z}; }
inline static stdmath_double4 stdmath_double4_xzz_value(stdmath_double4 v, stdmath_double3 value) { v.x = value.x; v.z = value.y; v.z = value.z; return v; }
inline static stdmath_double3 stdmath_double4_xzw(stdmath_double4 v) { return {v.x,v.z,v.w}; }
inline static stdmath_double4 stdmath_double4_xzw_value(stdmath_double4 v, stdmath_double3 value) { v.x = value.x; v.z = value.y; v.w = value.z; return v; }
inline static stdmath_double3 stdmath_double4_xwx(stdmath_double4 v) { return {v.x,v.w,v.x}; }
inline static stdmath_double4 stdmath_double4_xwx_value(stdmath_double4 v, stdmath_double3 value) { v.x = value.x; v.w = value.y; v.x = value.z; return v; }
inline static stdmath_double3 stdmath_double4_xwy(stdmath_double4 v) { return {v.x,v.w,v.y}; }
inline static stdmath_double4 stdmath_double4_xwy_value(stdmath_double4 v, stdmath_double3 value) { v.x = value.x; v.w = value.y; v.y = value.z; return v; }
inline static stdmath_double3 stdmath_double4_xwz(stdmath_double4 v) { return {v.x,v.w,v.z}; }
inline static stdmath_double4 stdmath_double4_xwz_value(stdmath_double4 v, stdmath_double3 value) { v.x = value.x; v.w = value.y; v.z = value.z; return v; }
inline static stdmath_double3 stdmath_double4_xww(stdmath_double4 v) { return {v.x,v.w,v.w}; }
inline static stdmath_double4 stdmath_double4_xww_value(stdmath_double4 v, stdmath_double3 value) { v.x = value.x; v.w = value.y; v.w = value.z; return v; }
inline static stdmath_double3 stdmath_double4_yxx(stdmath_double4 v) { return {v.y,v.x,v.x}; }
inline static stdmath_double4 stdmath_double4_yxx_value(stdmath_double4 v, stdmath_double3 value) { v.y = value.x; v.x = value.y; v.x = value.z; return v; }
inline static stdmath_double3 stdmath_double4_yxy(stdmath_double4 v) { return {v.y,v.x,v.y}; }
inline static stdmath_double4 stdmath_double4_yxy_value(stdmath_double4 v, stdmath_double3 value) { v.y = value.x; v.x = value.y; v.y = value.z; return v; }
inline static stdmath_double3 stdmath_double4_yxz(stdmath_double4 v) { return {v.y,v.x,v.z}; }
inline static stdmath_double4 stdmath_double4_yxz_value(stdmath_double4 v, stdmath_double3 value) { v.y = value.x; v.x = value.y; v.z = value.z; return v; }
inline static stdmath_double3 stdmath_double4_yxw(stdmath_double4 v) { return {v.y,v.x,v.w}; }
inline static stdmath_double4 stdmath_double4_yxw_value(stdmath_double4 v, stdmath_double3 value) { v.y = value.x; v.x = value.y; v.w = value.z; return v; }
inline static stdmath_double3 stdmath_double4_yyx(stdmath_double4 v) { return {v.y,v.y,v.x}; }
inline static stdmath_double4 stdmath_double4_yyx_value(stdmath_double4 v, stdmath_double3 value) { v.y = value.x; v.y = value.y; v.x = value.z; return v; }
inline static stdmath_double3 stdmath_double4_yyy(stdmath_double4 v) { return {v.y,v.y,v.y}; }
inline static stdmath_double4 stdmath_double4_yyy_value(stdmath_double4 v, stdmath_double3 value) { v.y = value.x; v.y = value.y; v.y = value.z; return v; }
inline static stdmath_double3 stdmath_double4_yyz(stdmath_double4 v) { return {v.y,v.y,v.z}; }
inline static stdmath_double4 stdmath_double4_yyz_value(stdmath_double4 v, stdmath_double3 value) { v.y = value.x; v.y = value.y; v.z = value.z; return v; }
inline static stdmath_double3 stdmath_double4_yyw(stdmath_double4 v) { return {v.y,v.y,v.w}; }
inline static stdmath_double4 stdmath_double4_yyw_value(stdmath_double4 v, stdmath_double3 value) { v.y = value.x; v.y = value.y; v.w = value.z; return v; }
inline static stdmath_double3 stdmath_double4_yzx(stdmath_double4 v) { return {v.y,v.z,v.x}; }
inline static stdmath_double4 stdmath_double4_yzx_value(stdmath_double4 v, stdmath_double3 value) { v.y = value.x; v.z = value.y; v.x = value.z; return v; }
inline static stdmath_double3 stdmath_double4_yzy(stdmath_double4 v) { return {v.y,v.z,v.y}; }
inline static stdmath_double4 stdmath_double4_yzy_value(stdmath_double4 v, stdmath_double3 value) { v.y = value.x; v.z = value.y; v.y = value.z; return v; }
inline static stdmath_double3 stdmath_double4_yzz(stdmath_double4 v) { return {v.y,v.z,v.z}; }
inline static stdmath_double4 stdmath_double4_yzz_value(stdmath_double4 v, stdmath_double3 value) { v.y = value.x; v.z = value.y; v.z = value.z; return v; }
inline static stdmath_double3 stdmath_double4_yzw(stdmath_double4 v) { return {v.y,v.z,v.w}; }
inline static stdmath_double4 stdmath_double4_yzw_value(stdmath_double4 v, stdmath_double3 value) { v.y = value.x; v.z = value.y; v.w = value.z; return v; }
inline static stdmath_double3 stdmath_double4_ywx(stdmath_double4 v) { return {v.y,v.w,v.x}; }
inline static stdmath_double4 stdmath_double4_ywx_value(stdmath_double4 v, stdmath_double3 value) { v.y = value.x; v.w = value.y; v.x = value.z; return v; }
inline static stdmath_double3 stdmath_double4_ywy(stdmath_double4 v) { return {v.y,v.w,v.y}; }
inline static stdmath_double4 stdmath_double4_ywy_value(stdmath_double4 v, stdmath_double3 value) { v.y = value.x; v.w = value.y; v.y = value.z; return v; }
inline static stdmath_double3 stdmath_double4_ywz(stdmath_double4 v) { return {v.y,v.w,v.z}; }
inline static stdmath_double4 stdmath_double4_ywz_value(stdmath_double4 v, stdmath_double3 value) { v.y = value.x; v.w = value.y; v.z = value.z; return v; }
inline static stdmath_double3 stdmath_double4_yww(stdmath_double4 v) { return {v.y,v.w,v.w}; }
inline static stdmath_double4 stdmath_double4_yww_value(stdmath_double4 v, stdmath_double3 value) { v.y = value.x; v.w = value.y; v.w = value.z; return v; }
inline static stdmath_double3 stdmath_double4_zxx(stdmath_double4 v) { return {v.z,v.x,v.x}; }
inline static stdmath_double4 stdmath_double4_zxx_value(stdmath_double4 v, stdmath_double3 value) { v.z = value.x; v.x = value.y; v.x = value.z; return v; }
inline static stdmath_double3 stdmath_double4_zxy(stdmath_double4 v) { return {v.z,v.x,v.y}; }
inline static stdmath_double4 stdmath_double4_zxy_value(stdmath_double4 v, stdmath_double3 value) { v.z = value.x; v.x = value.y; v.y = value.z; return v; }
inline static stdmath_double3 stdmath_double4_zxz(stdmath_double4 v) { return {v.z,v.x,v.z}; }
inline static stdmath_double4 stdmath_double4_zxz_value(stdmath_double4 v, stdmath_double3 value) { v.z = value.x; v.x = value.y; v.z = value.z; return v; }
inline static stdmath_double3 stdmath_double4_zxw(stdmath_double4 v) { return {v.z,v.x,v.w}; }
inline static stdmath_double4 stdmath_double4_zxw_value(stdmath_double4 v, stdmath_double3 value) { v.z = value.x; v.x = value.y; v.w = value.z; return v; }
inline static stdmath_double3 stdmath_double4_zyx(stdmath_double4 v) { return {v.z,v.y,v.x}; }
inline static stdmath_double4 stdmath_double4_zyx_value(stdmath_double4 v, stdmath_double3 value) { v.z = value.x; v.y = value.y; v.x = value.z; return v; }
inline static stdmath_double3 stdmath_double4_zyy(stdmath_double4 v) { return {v.z,v.y,v.y}; }
inline static stdmath_double4 stdmath_double4_zyy_value(stdmath_double4 v, stdmath_double3 value) { v.z = value.x; v.y = value.y; v.y = value.z; return v; }
inline static stdmath_double3 stdmath_double4_zyz(stdmath_double4 v) { return {v.z,v.y,v.z}; }
inline static stdmath_double4 stdmath_double4_zyz_value(stdmath_double4 v, stdmath_double3 value) { v.z = value.x; v.y = value.y; v.z = value.z; return v; }
inline static stdmath_double3 stdmath_double4_zyw(stdmath_double4 v) { return {v.z,v.y,v.w}; }
inline static stdmath_double4 stdmath_double4_zyw_value(stdmath_double4 v, stdmath_double3 value) { v.z = value.x; v.y = value.y; v.w = value.z; return v; }
inline static stdmath_double3 stdmath_double4_zzx(stdmath_double4 v) { return {v.z,v.z,v.x}; }
inline static stdmath_double4 stdmath_double4_zzx_value(stdmath_double4 v, stdmath_double3 value) { v.z = value.x; v.z = value.y; v.x = value.z; return v; }
inline static stdmath_double3 stdmath_double4_zzy(stdmath_double4 v) { return {v.z,v.z,v.y}; }
inline static stdmath_double4 stdmath_double4_zzy_value(stdmath_double4 v, stdmath_double3 value) { v.z = value.x; v.z = value.y; v.y = value.z; return v; }
inline static stdmath_double3 stdmath_double4_zzz(stdmath_double4 v) { return {v.z,v.z,v.z}; }
inline static stdmath_double4 stdmath_double4_zzz_value(stdmath_double4 v, stdmath_double3 value) { v.z = value.x; v.z = value.y; v.z = value.z; return v; }
inline static stdmath_double3 stdmath_double4_zzw(stdmath_double4 v) { return {v.z,v.z,v.w}; }
inline static stdmath_double4 stdmath_double4_zzw_value(stdmath_double4 v, stdmath_double3 value) { v.z = value.x; v.z = value.y; v.w = value.z; return v; }
inline static stdmath_double3 stdmath_double4_zwx(stdmath_double4 v) { return {v.z,v.w,v.x}; }
inline static stdmath_double4 stdmath_double4_zwx_value(stdmath_double4 v, stdmath_double3 value) { v.z = value.x; v.w = value.y; v.x = value.z; return v; }
inline static stdmath_double3 stdmath_double4_zwy(stdmath_double4 v) { return {v.z,v.w,v.y}; }
inline static stdmath_double4 stdmath_double4_zwy_value(stdmath_double4 v, stdmath_double3 value) { v.z = value.x; v.w = value.y; v.y = value.z; return v; }
inline static stdmath_double3 stdmath_double4_zwz(stdmath_double4 v) { return {v.z,v.w,v.z}; }
inline static stdmath_double4 stdmath_double4_zwz_value(stdmath_double4 v, stdmath_double3 value) { v.z = value.x; v.w = value.y; v.z = value.z; return v; }
inline static stdmath_double3 stdmath_double4_zww(stdmath_double4 v) { return {v.z,v.w,v.w}; }
inline static stdmath_double4 stdmath_double4_zww_value(stdmath_double4 v, stdmath_double3 value) { v.z = value.x; v.w = value.y; v.w = value.z; return v; }
inline static stdmath_double3 stdmath_double4_wxx(stdmath_double4 v) { return {v.w,v.x,v.x}; }
inline static stdmath_double4 stdmath_double4_wxx_value(stdmath_double4 v, stdmath_double3 value) { v.w = value.x; v.x = value.y; v.x = value.z; return v; }
inline static stdmath_double3 stdmath_double4_wxy(stdmath_double4 v) { return {v.w,v.x,v.y}; }
inline static stdmath_double4 stdmath_double4_wxy_value(stdmath_double4 v, stdmath_double3 value) { v.w = value.x; v.x = value.y; v.y = value.z; return v; }
inline static stdmath_double3 stdmath_double4_wxz(stdmath_double4 v) { return {v.w,v.x,v.z}; }
inline static stdmath_double4 stdmath_double4_wxz_value(stdmath_double4 v, stdmath_double3 value) { v.w = value.x; v.x = value.y; v.z = value.z; return v; }
inline static stdmath_double3 stdmath_double4_wxw(stdmath_double4 v) { return {v.w,v.x,v.w}; }
inline static stdmath_double4 stdmath_double4_wxw_value(stdmath_double4 v, stdmath_double3 value) { v.w = value.x; v.x = value.y; v.w = value.z; return v; }
inline static stdmath_double3 stdmath_double4_wyx(stdmath_double4 v) { return {v.w,v.y,v.x}; }
inline static stdmath_double4 stdmath_double4_wyx_value(stdmath_double4 v, stdmath_double3 value) { v.w = value.x; v.y = value.y; v.x = value.z; return v; }
inline static stdmath_double3 stdmath_double4_wyy(stdmath_double4 v) { return {v.w,v.y,v.y}; }
inline static stdmath_double4 stdmath_double4_wyy_value(stdmath_double4 v, stdmath_double3 value) { v.w = value.x; v.y = value.y; v.y = value.z; return v; }
inline static stdmath_double3 stdmath_double4_wyz(stdmath_double4 v) { return {v.w,v.y,v.z}; }
inline static stdmath_double4 stdmath_double4_wyz_value(stdmath_double4 v, stdmath_double3 value) { v.w = value.x; v.y = value.y; v.z = value.z; return v; }
inline static stdmath_double3 stdmath_double4_wyw(stdmath_double4 v) { return {v.w,v.y,v.w}; }
inline static stdmath_double4 stdmath_double4_wyw_value(stdmath_double4 v, stdmath_double3 value) { v.w = value.x; v.y = value.y; v.w = value.z; return v; }
inline static stdmath_double3 stdmath_double4_wzx(stdmath_double4 v) { return {v.w,v.z,v.x}; }
inline static stdmath_double4 stdmath_double4_wzx_value(stdmath_double4 v, stdmath_double3 value) { v.w = value.x; v.z = value.y; v.x = value.z; return v; }
inline static stdmath_double3 stdmath_double4_wzy(stdmath_double4 v) { return {v.w,v.z,v.y}; }
inline static stdmath_double4 stdmath_double4_wzy_value(stdmath_double4 v, stdmath_double3 value) { v.w = value.x; v.z = value.y; v.y = value.z; return v; }
inline static stdmath_double3 stdmath_double4_wzz(stdmath_double4 v) { return {v.w,v.z,v.z}; }
inline static stdmath_double4 stdmath_double4_wzz_value(stdmath_double4 v, stdmath_double3 value) { v.w = value.x; v.z = value.y; v.z = value.z; return v; }
inline static stdmath_double3 stdmath_double4_wzw(stdmath_double4 v) { return {v.w,v.z,v.w}; }
inline static stdmath_double4 stdmath_double4_wzw_value(stdmath_double4 v, stdmath_double3 value) { v.w = value.x; v.z = value.y; v.w = value.z; return v; }
inline static stdmath_double3 stdmath_double4_wwx(stdmath_double4 v) { return {v.w,v.w,v.x}; }
inline static stdmath_double4 stdmath_double4_wwx_value(stdmath_double4 v, stdmath_double3 value) { v.w = value.x; v.w = value.y; v.x = value.z; return v; }
inline static stdmath_double3 stdmath_double4_wwy(stdmath_double4 v) { return {v.w,v.w,v.y}; }
inline static stdmath_double4 stdmath_double4_wwy_value(stdmath_double4 v, stdmath_double3 value) { v.w = value.x; v.w = value.y; v.y = value.z; return v; }
inline static stdmath_double3 stdmath_double4_wwz(stdmath_double4 v) { return {v.w,v.w,v.z}; }
inline static stdmath_double4 stdmath_double4_wwz_value(stdmath_double4 v, stdmath_double3 value) { v.w = value.x; v.w = value.y; v.z = value.z; return v; }
inline static stdmath_double3 stdmath_double4_www(stdmath_double4 v) { return {v.w,v.w,v.w}; }
inline static stdmath_double4 stdmath_double4_www_value(stdmath_double4 v, stdmath_double3 value) { v.w = value.x; v.w = value.y; v.w = value.z; return v; }
inline static stdmath_double4 stdmath_double4_xxxx(stdmath_double4 v) { return {v.x,v.x,v.x,v.x}; }
inline static stdmath_double4 stdmath_double4_xxxx_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.x = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xxxy(stdmath_double4 v) { return {v.x,v.x,v.x,v.y}; }
inline static stdmath_double4 stdmath_double4_xxxy_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.x = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xxxz(stdmath_double4 v) { return {v.x,v.x,v.x,v.z}; }
inline static stdmath_double4 stdmath_double4_xxxz_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.x = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xxxw(stdmath_double4 v) { return {v.x,v.x,v.x,v.w}; }
inline static stdmath_double4 stdmath_double4_xxxw_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.x = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xxyx(stdmath_double4 v) { return {v.x,v.x,v.y,v.x}; }
inline static stdmath_double4 stdmath_double4_xxyx_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.x = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xxyy(stdmath_double4 v) { return {v.x,v.x,v.y,v.y}; }
inline static stdmath_double4 stdmath_double4_xxyy_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.x = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xxyz(stdmath_double4 v) { return {v.x,v.x,v.y,v.z}; }
inline static stdmath_double4 stdmath_double4_xxyz_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.x = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xxyw(stdmath_double4 v) { return {v.x,v.x,v.y,v.w}; }
inline static stdmath_double4 stdmath_double4_xxyw_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.x = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xxzx(stdmath_double4 v) { return {v.x,v.x,v.z,v.x}; }
inline static stdmath_double4 stdmath_double4_xxzx_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.x = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xxzy(stdmath_double4 v) { return {v.x,v.x,v.z,v.y}; }
inline static stdmath_double4 stdmath_double4_xxzy_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.x = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xxzz(stdmath_double4 v) { return {v.x,v.x,v.z,v.z}; }
inline static stdmath_double4 stdmath_double4_xxzz_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.x = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xxzw(stdmath_double4 v) { return {v.x,v.x,v.z,v.w}; }
inline static stdmath_double4 stdmath_double4_xxzw_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.x = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xxwx(stdmath_double4 v) { return {v.x,v.x,v.w,v.x}; }
inline static stdmath_double4 stdmath_double4_xxwx_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.x = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xxwy(stdmath_double4 v) { return {v.x,v.x,v.w,v.y}; }
inline static stdmath_double4 stdmath_double4_xxwy_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.x = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xxwz(stdmath_double4 v) { return {v.x,v.x,v.w,v.z}; }
inline static stdmath_double4 stdmath_double4_xxwz_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.x = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xxww(stdmath_double4 v) { return {v.x,v.x,v.w,v.w}; }
inline static stdmath_double4 stdmath_double4_xxww_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.x = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xyxx(stdmath_double4 v) { return {v.x,v.y,v.x,v.x}; }
inline static stdmath_double4 stdmath_double4_xyxx_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.y = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xyxy(stdmath_double4 v) { return {v.x,v.y,v.x,v.y}; }
inline static stdmath_double4 stdmath_double4_xyxy_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.y = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xyxz(stdmath_double4 v) { return {v.x,v.y,v.x,v.z}; }
inline static stdmath_double4 stdmath_double4_xyxz_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.y = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xyxw(stdmath_double4 v) { return {v.x,v.y,v.x,v.w}; }
inline static stdmath_double4 stdmath_double4_xyxw_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.y = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xyyx(stdmath_double4 v) { return {v.x,v.y,v.y,v.x}; }
inline static stdmath_double4 stdmath_double4_xyyx_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.y = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xyyy(stdmath_double4 v) { return {v.x,v.y,v.y,v.y}; }
inline static stdmath_double4 stdmath_double4_xyyy_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.y = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xyyz(stdmath_double4 v) { return {v.x,v.y,v.y,v.z}; }
inline static stdmath_double4 stdmath_double4_xyyz_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.y = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xyyw(stdmath_double4 v) { return {v.x,v.y,v.y,v.w}; }
inline static stdmath_double4 stdmath_double4_xyyw_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.y = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xyzx(stdmath_double4 v) { return {v.x,v.y,v.z,v.x}; }
inline static stdmath_double4 stdmath_double4_xyzx_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.y = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xyzy(stdmath_double4 v) { return {v.x,v.y,v.z,v.y}; }
inline static stdmath_double4 stdmath_double4_xyzy_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.y = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xyzz(stdmath_double4 v) { return {v.x,v.y,v.z,v.z}; }
inline static stdmath_double4 stdmath_double4_xyzz_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.y = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xyzw(stdmath_double4 v) { return {v.x,v.y,v.z,v.w}; }
inline static stdmath_double4 stdmath_double4_xyzw_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.y = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xywx(stdmath_double4 v) { return {v.x,v.y,v.w,v.x}; }
inline static stdmath_double4 stdmath_double4_xywx_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.y = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xywy(stdmath_double4 v) { return {v.x,v.y,v.w,v.y}; }
inline static stdmath_double4 stdmath_double4_xywy_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.y = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xywz(stdmath_double4 v) { return {v.x,v.y,v.w,v.z}; }
inline static stdmath_double4 stdmath_double4_xywz_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.y = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xyww(stdmath_double4 v) { return {v.x,v.y,v.w,v.w}; }
inline static stdmath_double4 stdmath_double4_xyww_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.y = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xzxx(stdmath_double4 v) { return {v.x,v.z,v.x,v.x}; }
inline static stdmath_double4 stdmath_double4_xzxx_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.z = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xzxy(stdmath_double4 v) { return {v.x,v.z,v.x,v.y}; }
inline static stdmath_double4 stdmath_double4_xzxy_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.z = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xzxz(stdmath_double4 v) { return {v.x,v.z,v.x,v.z}; }
inline static stdmath_double4 stdmath_double4_xzxz_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.z = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xzxw(stdmath_double4 v) { return {v.x,v.z,v.x,v.w}; }
inline static stdmath_double4 stdmath_double4_xzxw_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.z = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xzyx(stdmath_double4 v) { return {v.x,v.z,v.y,v.x}; }
inline static stdmath_double4 stdmath_double4_xzyx_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.z = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xzyy(stdmath_double4 v) { return {v.x,v.z,v.y,v.y}; }
inline static stdmath_double4 stdmath_double4_xzyy_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.z = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xzyz(stdmath_double4 v) { return {v.x,v.z,v.y,v.z}; }
inline static stdmath_double4 stdmath_double4_xzyz_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.z = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xzyw(stdmath_double4 v) { return {v.x,v.z,v.y,v.w}; }
inline static stdmath_double4 stdmath_double4_xzyw_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.z = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xzzx(stdmath_double4 v) { return {v.x,v.z,v.z,v.x}; }
inline static stdmath_double4 stdmath_double4_xzzx_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.z = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xzzy(stdmath_double4 v) { return {v.x,v.z,v.z,v.y}; }
inline static stdmath_double4 stdmath_double4_xzzy_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.z = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xzzz(stdmath_double4 v) { return {v.x,v.z,v.z,v.z}; }
inline static stdmath_double4 stdmath_double4_xzzz_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.z = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xzzw(stdmath_double4 v) { return {v.x,v.z,v.z,v.w}; }
inline static stdmath_double4 stdmath_double4_xzzw_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.z = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xzwx(stdmath_double4 v) { return {v.x,v.z,v.w,v.x}; }
inline static stdmath_double4 stdmath_double4_xzwx_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.z = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xzwy(stdmath_double4 v) { return {v.x,v.z,v.w,v.y}; }
inline static stdmath_double4 stdmath_double4_xzwy_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.z = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xzwz(stdmath_double4 v) { return {v.x,v.z,v.w,v.z}; }
inline static stdmath_double4 stdmath_double4_xzwz_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.z = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xzww(stdmath_double4 v) { return {v.x,v.z,v.w,v.w}; }
inline static stdmath_double4 stdmath_double4_xzww_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.z = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xwxx(stdmath_double4 v) { return {v.x,v.w,v.x,v.x}; }
inline static stdmath_double4 stdmath_double4_xwxx_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.w = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xwxy(stdmath_double4 v) { return {v.x,v.w,v.x,v.y}; }
inline static stdmath_double4 stdmath_double4_xwxy_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.w = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xwxz(stdmath_double4 v) { return {v.x,v.w,v.x,v.z}; }
inline static stdmath_double4 stdmath_double4_xwxz_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.w = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xwxw(stdmath_double4 v) { return {v.x,v.w,v.x,v.w}; }
inline static stdmath_double4 stdmath_double4_xwxw_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.w = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xwyx(stdmath_double4 v) { return {v.x,v.w,v.y,v.x}; }
inline static stdmath_double4 stdmath_double4_xwyx_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.w = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xwyy(stdmath_double4 v) { return {v.x,v.w,v.y,v.y}; }
inline static stdmath_double4 stdmath_double4_xwyy_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.w = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xwyz(stdmath_double4 v) { return {v.x,v.w,v.y,v.z}; }
inline static stdmath_double4 stdmath_double4_xwyz_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.w = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xwyw(stdmath_double4 v) { return {v.x,v.w,v.y,v.w}; }
inline static stdmath_double4 stdmath_double4_xwyw_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.w = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xwzx(stdmath_double4 v) { return {v.x,v.w,v.z,v.x}; }
inline static stdmath_double4 stdmath_double4_xwzx_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.w = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xwzy(stdmath_double4 v) { return {v.x,v.w,v.z,v.y}; }
inline static stdmath_double4 stdmath_double4_xwzy_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.w = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xwzz(stdmath_double4 v) { return {v.x,v.w,v.z,v.z}; }
inline static stdmath_double4 stdmath_double4_xwzz_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.w = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xwzw(stdmath_double4 v) { return {v.x,v.w,v.z,v.w}; }
inline static stdmath_double4 stdmath_double4_xwzw_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.w = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xwwx(stdmath_double4 v) { return {v.x,v.w,v.w,v.x}; }
inline static stdmath_double4 stdmath_double4_xwwx_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.w = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xwwy(stdmath_double4 v) { return {v.x,v.w,v.w,v.y}; }
inline static stdmath_double4 stdmath_double4_xwwy_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.w = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xwwz(stdmath_double4 v) { return {v.x,v.w,v.w,v.z}; }
inline static stdmath_double4 stdmath_double4_xwwz_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.w = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_xwww(stdmath_double4 v) { return {v.x,v.w,v.w,v.w}; }
inline static stdmath_double4 stdmath_double4_xwww_value(stdmath_double4 v, stdmath_double4 value) { v.x = value.x; v.w = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_yxxx(stdmath_double4 v) { return {v.y,v.x,v.x,v.x}; }
inline static stdmath_double4 stdmath_double4_yxxx_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.x = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_yxxy(stdmath_double4 v) { return {v.y,v.x,v.x,v.y}; }
inline static stdmath_double4 stdmath_double4_yxxy_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.x = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_yxxz(stdmath_double4 v) { return {v.y,v.x,v.x,v.z}; }
inline static stdmath_double4 stdmath_double4_yxxz_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.x = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_yxxw(stdmath_double4 v) { return {v.y,v.x,v.x,v.w}; }
inline static stdmath_double4 stdmath_double4_yxxw_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.x = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_yxyx(stdmath_double4 v) { return {v.y,v.x,v.y,v.x}; }
inline static stdmath_double4 stdmath_double4_yxyx_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.x = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_yxyy(stdmath_double4 v) { return {v.y,v.x,v.y,v.y}; }
inline static stdmath_double4 stdmath_double4_yxyy_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.x = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_yxyz(stdmath_double4 v) { return {v.y,v.x,v.y,v.z}; }
inline static stdmath_double4 stdmath_double4_yxyz_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.x = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_yxyw(stdmath_double4 v) { return {v.y,v.x,v.y,v.w}; }
inline static stdmath_double4 stdmath_double4_yxyw_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.x = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_yxzx(stdmath_double4 v) { return {v.y,v.x,v.z,v.x}; }
inline static stdmath_double4 stdmath_double4_yxzx_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.x = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_yxzy(stdmath_double4 v) { return {v.y,v.x,v.z,v.y}; }
inline static stdmath_double4 stdmath_double4_yxzy_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.x = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_yxzz(stdmath_double4 v) { return {v.y,v.x,v.z,v.z}; }
inline static stdmath_double4 stdmath_double4_yxzz_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.x = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_yxzw(stdmath_double4 v) { return {v.y,v.x,v.z,v.w}; }
inline static stdmath_double4 stdmath_double4_yxzw_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.x = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_yxwx(stdmath_double4 v) { return {v.y,v.x,v.w,v.x}; }
inline static stdmath_double4 stdmath_double4_yxwx_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.x = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_yxwy(stdmath_double4 v) { return {v.y,v.x,v.w,v.y}; }
inline static stdmath_double4 stdmath_double4_yxwy_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.x = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_yxwz(stdmath_double4 v) { return {v.y,v.x,v.w,v.z}; }
inline static stdmath_double4 stdmath_double4_yxwz_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.x = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_yxww(stdmath_double4 v) { return {v.y,v.x,v.w,v.w}; }
inline static stdmath_double4 stdmath_double4_yxww_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.x = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_yyxx(stdmath_double4 v) { return {v.y,v.y,v.x,v.x}; }
inline static stdmath_double4 stdmath_double4_yyxx_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.y = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_yyxy(stdmath_double4 v) { return {v.y,v.y,v.x,v.y}; }
inline static stdmath_double4 stdmath_double4_yyxy_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.y = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_yyxz(stdmath_double4 v) { return {v.y,v.y,v.x,v.z}; }
inline static stdmath_double4 stdmath_double4_yyxz_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.y = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_yyxw(stdmath_double4 v) { return {v.y,v.y,v.x,v.w}; }
inline static stdmath_double4 stdmath_double4_yyxw_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.y = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_yyyx(stdmath_double4 v) { return {v.y,v.y,v.y,v.x}; }
inline static stdmath_double4 stdmath_double4_yyyx_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.y = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_yyyy(stdmath_double4 v) { return {v.y,v.y,v.y,v.y}; }
inline static stdmath_double4 stdmath_double4_yyyy_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.y = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_yyyz(stdmath_double4 v) { return {v.y,v.y,v.y,v.z}; }
inline static stdmath_double4 stdmath_double4_yyyz_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.y = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_yyyw(stdmath_double4 v) { return {v.y,v.y,v.y,v.w}; }
inline static stdmath_double4 stdmath_double4_yyyw_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.y = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_yyzx(stdmath_double4 v) { return {v.y,v.y,v.z,v.x}; }
inline static stdmath_double4 stdmath_double4_yyzx_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.y = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_yyzy(stdmath_double4 v) { return {v.y,v.y,v.z,v.y}; }
inline static stdmath_double4 stdmath_double4_yyzy_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.y = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_yyzz(stdmath_double4 v) { return {v.y,v.y,v.z,v.z}; }
inline static stdmath_double4 stdmath_double4_yyzz_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.y = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_yyzw(stdmath_double4 v) { return {v.y,v.y,v.z,v.w}; }
inline static stdmath_double4 stdmath_double4_yyzw_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.y = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_yywx(stdmath_double4 v) { return {v.y,v.y,v.w,v.x}; }
inline static stdmath_double4 stdmath_double4_yywx_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.y = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_yywy(stdmath_double4 v) { return {v.y,v.y,v.w,v.y}; }
inline static stdmath_double4 stdmath_double4_yywy_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.y = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_yywz(stdmath_double4 v) { return {v.y,v.y,v.w,v.z}; }
inline static stdmath_double4 stdmath_double4_yywz_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.y = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_yyww(stdmath_double4 v) { return {v.y,v.y,v.w,v.w}; }
inline static stdmath_double4 stdmath_double4_yyww_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.y = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_yzxx(stdmath_double4 v) { return {v.y,v.z,v.x,v.x}; }
inline static stdmath_double4 stdmath_double4_yzxx_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.z = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_yzxy(stdmath_double4 v) { return {v.y,v.z,v.x,v.y}; }
inline static stdmath_double4 stdmath_double4_yzxy_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.z = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_yzxz(stdmath_double4 v) { return {v.y,v.z,v.x,v.z}; }
inline static stdmath_double4 stdmath_double4_yzxz_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.z = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_yzxw(stdmath_double4 v) { return {v.y,v.z,v.x,v.w}; }
inline static stdmath_double4 stdmath_double4_yzxw_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.z = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_yzyx(stdmath_double4 v) { return {v.y,v.z,v.y,v.x}; }
inline static stdmath_double4 stdmath_double4_yzyx_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.z = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_yzyy(stdmath_double4 v) { return {v.y,v.z,v.y,v.y}; }
inline static stdmath_double4 stdmath_double4_yzyy_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.z = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_yzyz(stdmath_double4 v) { return {v.y,v.z,v.y,v.z}; }
inline static stdmath_double4 stdmath_double4_yzyz_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.z = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_yzyw(stdmath_double4 v) { return {v.y,v.z,v.y,v.w}; }
inline static stdmath_double4 stdmath_double4_yzyw_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.z = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_yzzx(stdmath_double4 v) { return {v.y,v.z,v.z,v.x}; }
inline static stdmath_double4 stdmath_double4_yzzx_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.z = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_yzzy(stdmath_double4 v) { return {v.y,v.z,v.z,v.y}; }
inline static stdmath_double4 stdmath_double4_yzzy_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.z = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_yzzz(stdmath_double4 v) { return {v.y,v.z,v.z,v.z}; }
inline static stdmath_double4 stdmath_double4_yzzz_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.z = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_yzzw(stdmath_double4 v) { return {v.y,v.z,v.z,v.w}; }
inline static stdmath_double4 stdmath_double4_yzzw_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.z = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_yzwx(stdmath_double4 v) { return {v.y,v.z,v.w,v.x}; }
inline static stdmath_double4 stdmath_double4_yzwx_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.z = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_yzwy(stdmath_double4 v) { return {v.y,v.z,v.w,v.y}; }
inline static stdmath_double4 stdmath_double4_yzwy_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.z = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_yzwz(stdmath_double4 v) { return {v.y,v.z,v.w,v.z}; }
inline static stdmath_double4 stdmath_double4_yzwz_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.z = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_yzww(stdmath_double4 v) { return {v.y,v.z,v.w,v.w}; }
inline static stdmath_double4 stdmath_double4_yzww_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.z = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_ywxx(stdmath_double4 v) { return {v.y,v.w,v.x,v.x}; }
inline static stdmath_double4 stdmath_double4_ywxx_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.w = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_ywxy(stdmath_double4 v) { return {v.y,v.w,v.x,v.y}; }
inline static stdmath_double4 stdmath_double4_ywxy_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.w = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_ywxz(stdmath_double4 v) { return {v.y,v.w,v.x,v.z}; }
inline static stdmath_double4 stdmath_double4_ywxz_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.w = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_ywxw(stdmath_double4 v) { return {v.y,v.w,v.x,v.w}; }
inline static stdmath_double4 stdmath_double4_ywxw_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.w = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_ywyx(stdmath_double4 v) { return {v.y,v.w,v.y,v.x}; }
inline static stdmath_double4 stdmath_double4_ywyx_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.w = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_ywyy(stdmath_double4 v) { return {v.y,v.w,v.y,v.y}; }
inline static stdmath_double4 stdmath_double4_ywyy_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.w = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_ywyz(stdmath_double4 v) { return {v.y,v.w,v.y,v.z}; }
inline static stdmath_double4 stdmath_double4_ywyz_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.w = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_ywyw(stdmath_double4 v) { return {v.y,v.w,v.y,v.w}; }
inline static stdmath_double4 stdmath_double4_ywyw_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.w = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_ywzx(stdmath_double4 v) { return {v.y,v.w,v.z,v.x}; }
inline static stdmath_double4 stdmath_double4_ywzx_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.w = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_ywzy(stdmath_double4 v) { return {v.y,v.w,v.z,v.y}; }
inline static stdmath_double4 stdmath_double4_ywzy_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.w = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_ywzz(stdmath_double4 v) { return {v.y,v.w,v.z,v.z}; }
inline static stdmath_double4 stdmath_double4_ywzz_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.w = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_ywzw(stdmath_double4 v) { return {v.y,v.w,v.z,v.w}; }
inline static stdmath_double4 stdmath_double4_ywzw_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.w = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_ywwx(stdmath_double4 v) { return {v.y,v.w,v.w,v.x}; }
inline static stdmath_double4 stdmath_double4_ywwx_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.w = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_ywwy(stdmath_double4 v) { return {v.y,v.w,v.w,v.y}; }
inline static stdmath_double4 stdmath_double4_ywwy_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.w = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_ywwz(stdmath_double4 v) { return {v.y,v.w,v.w,v.z}; }
inline static stdmath_double4 stdmath_double4_ywwz_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.w = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_ywww(stdmath_double4 v) { return {v.y,v.w,v.w,v.w}; }
inline static stdmath_double4 stdmath_double4_ywww_value(stdmath_double4 v, stdmath_double4 value) { v.y = value.x; v.w = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zxxx(stdmath_double4 v) { return {v.z,v.x,v.x,v.x}; }
inline static stdmath_double4 stdmath_double4_zxxx_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.x = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zxxy(stdmath_double4 v) { return {v.z,v.x,v.x,v.y}; }
inline static stdmath_double4 stdmath_double4_zxxy_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.x = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zxxz(stdmath_double4 v) { return {v.z,v.x,v.x,v.z}; }
inline static stdmath_double4 stdmath_double4_zxxz_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.x = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zxxw(stdmath_double4 v) { return {v.z,v.x,v.x,v.w}; }
inline static stdmath_double4 stdmath_double4_zxxw_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.x = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zxyx(stdmath_double4 v) { return {v.z,v.x,v.y,v.x}; }
inline static stdmath_double4 stdmath_double4_zxyx_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.x = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zxyy(stdmath_double4 v) { return {v.z,v.x,v.y,v.y}; }
inline static stdmath_double4 stdmath_double4_zxyy_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.x = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zxyz(stdmath_double4 v) { return {v.z,v.x,v.y,v.z}; }
inline static stdmath_double4 stdmath_double4_zxyz_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.x = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zxyw(stdmath_double4 v) { return {v.z,v.x,v.y,v.w}; }
inline static stdmath_double4 stdmath_double4_zxyw_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.x = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zxzx(stdmath_double4 v) { return {v.z,v.x,v.z,v.x}; }
inline static stdmath_double4 stdmath_double4_zxzx_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.x = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zxzy(stdmath_double4 v) { return {v.z,v.x,v.z,v.y}; }
inline static stdmath_double4 stdmath_double4_zxzy_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.x = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zxzz(stdmath_double4 v) { return {v.z,v.x,v.z,v.z}; }
inline static stdmath_double4 stdmath_double4_zxzz_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.x = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zxzw(stdmath_double4 v) { return {v.z,v.x,v.z,v.w}; }
inline static stdmath_double4 stdmath_double4_zxzw_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.x = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zxwx(stdmath_double4 v) { return {v.z,v.x,v.w,v.x}; }
inline static stdmath_double4 stdmath_double4_zxwx_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.x = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zxwy(stdmath_double4 v) { return {v.z,v.x,v.w,v.y}; }
inline static stdmath_double4 stdmath_double4_zxwy_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.x = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zxwz(stdmath_double4 v) { return {v.z,v.x,v.w,v.z}; }
inline static stdmath_double4 stdmath_double4_zxwz_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.x = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zxww(stdmath_double4 v) { return {v.z,v.x,v.w,v.w}; }
inline static stdmath_double4 stdmath_double4_zxww_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.x = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zyxx(stdmath_double4 v) { return {v.z,v.y,v.x,v.x}; }
inline static stdmath_double4 stdmath_double4_zyxx_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.y = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zyxy(stdmath_double4 v) { return {v.z,v.y,v.x,v.y}; }
inline static stdmath_double4 stdmath_double4_zyxy_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.y = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zyxz(stdmath_double4 v) { return {v.z,v.y,v.x,v.z}; }
inline static stdmath_double4 stdmath_double4_zyxz_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.y = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zyxw(stdmath_double4 v) { return {v.z,v.y,v.x,v.w}; }
inline static stdmath_double4 stdmath_double4_zyxw_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.y = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zyyx(stdmath_double4 v) { return {v.z,v.y,v.y,v.x}; }
inline static stdmath_double4 stdmath_double4_zyyx_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.y = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zyyy(stdmath_double4 v) { return {v.z,v.y,v.y,v.y}; }
inline static stdmath_double4 stdmath_double4_zyyy_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.y = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zyyz(stdmath_double4 v) { return {v.z,v.y,v.y,v.z}; }
inline static stdmath_double4 stdmath_double4_zyyz_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.y = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zyyw(stdmath_double4 v) { return {v.z,v.y,v.y,v.w}; }
inline static stdmath_double4 stdmath_double4_zyyw_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.y = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zyzx(stdmath_double4 v) { return {v.z,v.y,v.z,v.x}; }
inline static stdmath_double4 stdmath_double4_zyzx_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.y = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zyzy(stdmath_double4 v) { return {v.z,v.y,v.z,v.y}; }
inline static stdmath_double4 stdmath_double4_zyzy_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.y = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zyzz(stdmath_double4 v) { return {v.z,v.y,v.z,v.z}; }
inline static stdmath_double4 stdmath_double4_zyzz_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.y = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zyzw(stdmath_double4 v) { return {v.z,v.y,v.z,v.w}; }
inline static stdmath_double4 stdmath_double4_zyzw_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.y = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zywx(stdmath_double4 v) { return {v.z,v.y,v.w,v.x}; }
inline static stdmath_double4 stdmath_double4_zywx_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.y = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zywy(stdmath_double4 v) { return {v.z,v.y,v.w,v.y}; }
inline static stdmath_double4 stdmath_double4_zywy_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.y = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zywz(stdmath_double4 v) { return {v.z,v.y,v.w,v.z}; }
inline static stdmath_double4 stdmath_double4_zywz_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.y = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zyww(stdmath_double4 v) { return {v.z,v.y,v.w,v.w}; }
inline static stdmath_double4 stdmath_double4_zyww_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.y = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zzxx(stdmath_double4 v) { return {v.z,v.z,v.x,v.x}; }
inline static stdmath_double4 stdmath_double4_zzxx_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.z = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zzxy(stdmath_double4 v) { return {v.z,v.z,v.x,v.y}; }
inline static stdmath_double4 stdmath_double4_zzxy_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.z = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zzxz(stdmath_double4 v) { return {v.z,v.z,v.x,v.z}; }
inline static stdmath_double4 stdmath_double4_zzxz_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.z = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zzxw(stdmath_double4 v) { return {v.z,v.z,v.x,v.w}; }
inline static stdmath_double4 stdmath_double4_zzxw_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.z = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zzyx(stdmath_double4 v) { return {v.z,v.z,v.y,v.x}; }
inline static stdmath_double4 stdmath_double4_zzyx_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.z = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zzyy(stdmath_double4 v) { return {v.z,v.z,v.y,v.y}; }
inline static stdmath_double4 stdmath_double4_zzyy_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.z = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zzyz(stdmath_double4 v) { return {v.z,v.z,v.y,v.z}; }
inline static stdmath_double4 stdmath_double4_zzyz_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.z = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zzyw(stdmath_double4 v) { return {v.z,v.z,v.y,v.w}; }
inline static stdmath_double4 stdmath_double4_zzyw_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.z = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zzzx(stdmath_double4 v) { return {v.z,v.z,v.z,v.x}; }
inline static stdmath_double4 stdmath_double4_zzzx_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.z = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zzzy(stdmath_double4 v) { return {v.z,v.z,v.z,v.y}; }
inline static stdmath_double4 stdmath_double4_zzzy_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.z = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zzzz(stdmath_double4 v) { return {v.z,v.z,v.z,v.z}; }
inline static stdmath_double4 stdmath_double4_zzzz_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.z = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zzzw(stdmath_double4 v) { return {v.z,v.z,v.z,v.w}; }
inline static stdmath_double4 stdmath_double4_zzzw_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.z = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zzwx(stdmath_double4 v) { return {v.z,v.z,v.w,v.x}; }
inline static stdmath_double4 stdmath_double4_zzwx_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.z = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zzwy(stdmath_double4 v) { return {v.z,v.z,v.w,v.y}; }
inline static stdmath_double4 stdmath_double4_zzwy_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.z = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zzwz(stdmath_double4 v) { return {v.z,v.z,v.w,v.z}; }
inline static stdmath_double4 stdmath_double4_zzwz_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.z = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zzww(stdmath_double4 v) { return {v.z,v.z,v.w,v.w}; }
inline static stdmath_double4 stdmath_double4_zzww_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.z = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zwxx(stdmath_double4 v) { return {v.z,v.w,v.x,v.x}; }
inline static stdmath_double4 stdmath_double4_zwxx_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.w = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zwxy(stdmath_double4 v) { return {v.z,v.w,v.x,v.y}; }
inline static stdmath_double4 stdmath_double4_zwxy_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.w = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zwxz(stdmath_double4 v) { return {v.z,v.w,v.x,v.z}; }
inline static stdmath_double4 stdmath_double4_zwxz_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.w = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zwxw(stdmath_double4 v) { return {v.z,v.w,v.x,v.w}; }
inline static stdmath_double4 stdmath_double4_zwxw_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.w = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zwyx(stdmath_double4 v) { return {v.z,v.w,v.y,v.x}; }
inline static stdmath_double4 stdmath_double4_zwyx_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.w = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zwyy(stdmath_double4 v) { return {v.z,v.w,v.y,v.y}; }
inline static stdmath_double4 stdmath_double4_zwyy_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.w = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zwyz(stdmath_double4 v) { return {v.z,v.w,v.y,v.z}; }
inline static stdmath_double4 stdmath_double4_zwyz_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.w = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zwyw(stdmath_double4 v) { return {v.z,v.w,v.y,v.w}; }
inline static stdmath_double4 stdmath_double4_zwyw_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.w = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zwzx(stdmath_double4 v) { return {v.z,v.w,v.z,v.x}; }
inline static stdmath_double4 stdmath_double4_zwzx_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.w = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zwzy(stdmath_double4 v) { return {v.z,v.w,v.z,v.y}; }
inline static stdmath_double4 stdmath_double4_zwzy_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.w = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zwzz(stdmath_double4 v) { return {v.z,v.w,v.z,v.z}; }
inline static stdmath_double4 stdmath_double4_zwzz_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.w = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zwzw(stdmath_double4 v) { return {v.z,v.w,v.z,v.w}; }
inline static stdmath_double4 stdmath_double4_zwzw_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.w = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zwwx(stdmath_double4 v) { return {v.z,v.w,v.w,v.x}; }
inline static stdmath_double4 stdmath_double4_zwwx_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.w = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zwwy(stdmath_double4 v) { return {v.z,v.w,v.w,v.y}; }
inline static stdmath_double4 stdmath_double4_zwwy_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.w = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zwwz(stdmath_double4 v) { return {v.z,v.w,v.w,v.z}; }
inline static stdmath_double4 stdmath_double4_zwwz_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.w = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_zwww(stdmath_double4 v) { return {v.z,v.w,v.w,v.w}; }
inline static stdmath_double4 stdmath_double4_zwww_value(stdmath_double4 v, stdmath_double4 value) { v.z = value.x; v.w = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wxxx(stdmath_double4 v) { return {v.w,v.x,v.x,v.x}; }
inline static stdmath_double4 stdmath_double4_wxxx_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.x = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wxxy(stdmath_double4 v) { return {v.w,v.x,v.x,v.y}; }
inline static stdmath_double4 stdmath_double4_wxxy_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.x = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wxxz(stdmath_double4 v) { return {v.w,v.x,v.x,v.z}; }
inline static stdmath_double4 stdmath_double4_wxxz_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.x = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wxxw(stdmath_double4 v) { return {v.w,v.x,v.x,v.w}; }
inline static stdmath_double4 stdmath_double4_wxxw_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.x = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wxyx(stdmath_double4 v) { return {v.w,v.x,v.y,v.x}; }
inline static stdmath_double4 stdmath_double4_wxyx_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.x = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wxyy(stdmath_double4 v) { return {v.w,v.x,v.y,v.y}; }
inline static stdmath_double4 stdmath_double4_wxyy_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.x = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wxyz(stdmath_double4 v) { return {v.w,v.x,v.y,v.z}; }
inline static stdmath_double4 stdmath_double4_wxyz_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.x = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wxyw(stdmath_double4 v) { return {v.w,v.x,v.y,v.w}; }
inline static stdmath_double4 stdmath_double4_wxyw_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.x = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wxzx(stdmath_double4 v) { return {v.w,v.x,v.z,v.x}; }
inline static stdmath_double4 stdmath_double4_wxzx_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.x = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wxzy(stdmath_double4 v) { return {v.w,v.x,v.z,v.y}; }
inline static stdmath_double4 stdmath_double4_wxzy_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.x = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wxzz(stdmath_double4 v) { return {v.w,v.x,v.z,v.z}; }
inline static stdmath_double4 stdmath_double4_wxzz_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.x = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wxzw(stdmath_double4 v) { return {v.w,v.x,v.z,v.w}; }
inline static stdmath_double4 stdmath_double4_wxzw_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.x = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wxwx(stdmath_double4 v) { return {v.w,v.x,v.w,v.x}; }
inline static stdmath_double4 stdmath_double4_wxwx_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.x = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wxwy(stdmath_double4 v) { return {v.w,v.x,v.w,v.y}; }
inline static stdmath_double4 stdmath_double4_wxwy_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.x = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wxwz(stdmath_double4 v) { return {v.w,v.x,v.w,v.z}; }
inline static stdmath_double4 stdmath_double4_wxwz_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.x = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wxww(stdmath_double4 v) { return {v.w,v.x,v.w,v.w}; }
inline static stdmath_double4 stdmath_double4_wxww_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.x = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wyxx(stdmath_double4 v) { return {v.w,v.y,v.x,v.x}; }
inline static stdmath_double4 stdmath_double4_wyxx_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.y = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wyxy(stdmath_double4 v) { return {v.w,v.y,v.x,v.y}; }
inline static stdmath_double4 stdmath_double4_wyxy_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.y = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wyxz(stdmath_double4 v) { return {v.w,v.y,v.x,v.z}; }
inline static stdmath_double4 stdmath_double4_wyxz_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.y = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wyxw(stdmath_double4 v) { return {v.w,v.y,v.x,v.w}; }
inline static stdmath_double4 stdmath_double4_wyxw_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.y = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wyyx(stdmath_double4 v) { return {v.w,v.y,v.y,v.x}; }
inline static stdmath_double4 stdmath_double4_wyyx_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.y = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wyyy(stdmath_double4 v) { return {v.w,v.y,v.y,v.y}; }
inline static stdmath_double4 stdmath_double4_wyyy_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.y = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wyyz(stdmath_double4 v) { return {v.w,v.y,v.y,v.z}; }
inline static stdmath_double4 stdmath_double4_wyyz_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.y = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wyyw(stdmath_double4 v) { return {v.w,v.y,v.y,v.w}; }
inline static stdmath_double4 stdmath_double4_wyyw_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.y = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wyzx(stdmath_double4 v) { return {v.w,v.y,v.z,v.x}; }
inline static stdmath_double4 stdmath_double4_wyzx_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.y = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wyzy(stdmath_double4 v) { return {v.w,v.y,v.z,v.y}; }
inline static stdmath_double4 stdmath_double4_wyzy_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.y = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wyzz(stdmath_double4 v) { return {v.w,v.y,v.z,v.z}; }
inline static stdmath_double4 stdmath_double4_wyzz_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.y = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wyzw(stdmath_double4 v) { return {v.w,v.y,v.z,v.w}; }
inline static stdmath_double4 stdmath_double4_wyzw_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.y = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wywx(stdmath_double4 v) { return {v.w,v.y,v.w,v.x}; }
inline static stdmath_double4 stdmath_double4_wywx_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.y = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wywy(stdmath_double4 v) { return {v.w,v.y,v.w,v.y}; }
inline static stdmath_double4 stdmath_double4_wywy_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.y = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wywz(stdmath_double4 v) { return {v.w,v.y,v.w,v.z}; }
inline static stdmath_double4 stdmath_double4_wywz_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.y = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wyww(stdmath_double4 v) { return {v.w,v.y,v.w,v.w}; }
inline static stdmath_double4 stdmath_double4_wyww_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.y = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wzxx(stdmath_double4 v) { return {v.w,v.z,v.x,v.x}; }
inline static stdmath_double4 stdmath_double4_wzxx_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.z = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wzxy(stdmath_double4 v) { return {v.w,v.z,v.x,v.y}; }
inline static stdmath_double4 stdmath_double4_wzxy_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.z = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wzxz(stdmath_double4 v) { return {v.w,v.z,v.x,v.z}; }
inline static stdmath_double4 stdmath_double4_wzxz_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.z = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wzxw(stdmath_double4 v) { return {v.w,v.z,v.x,v.w}; }
inline static stdmath_double4 stdmath_double4_wzxw_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.z = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wzyx(stdmath_double4 v) { return {v.w,v.z,v.y,v.x}; }
inline static stdmath_double4 stdmath_double4_wzyx_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.z = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wzyy(stdmath_double4 v) { return {v.w,v.z,v.y,v.y}; }
inline static stdmath_double4 stdmath_double4_wzyy_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.z = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wzyz(stdmath_double4 v) { return {v.w,v.z,v.y,v.z}; }
inline static stdmath_double4 stdmath_double4_wzyz_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.z = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wzyw(stdmath_double4 v) { return {v.w,v.z,v.y,v.w}; }
inline static stdmath_double4 stdmath_double4_wzyw_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.z = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wzzx(stdmath_double4 v) { return {v.w,v.z,v.z,v.x}; }
inline static stdmath_double4 stdmath_double4_wzzx_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.z = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wzzy(stdmath_double4 v) { return {v.w,v.z,v.z,v.y}; }
inline static stdmath_double4 stdmath_double4_wzzy_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.z = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wzzz(stdmath_double4 v) { return {v.w,v.z,v.z,v.z}; }
inline static stdmath_double4 stdmath_double4_wzzz_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.z = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wzzw(stdmath_double4 v) { return {v.w,v.z,v.z,v.w}; }
inline static stdmath_double4 stdmath_double4_wzzw_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.z = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wzwx(stdmath_double4 v) { return {v.w,v.z,v.w,v.x}; }
inline static stdmath_double4 stdmath_double4_wzwx_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.z = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wzwy(stdmath_double4 v) { return {v.w,v.z,v.w,v.y}; }
inline static stdmath_double4 stdmath_double4_wzwy_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.z = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wzwz(stdmath_double4 v) { return {v.w,v.z,v.w,v.z}; }
inline static stdmath_double4 stdmath_double4_wzwz_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.z = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wzww(stdmath_double4 v) { return {v.w,v.z,v.w,v.w}; }
inline static stdmath_double4 stdmath_double4_wzww_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.z = value.y; v.w = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wwxx(stdmath_double4 v) { return {v.w,v.w,v.x,v.x}; }
inline static stdmath_double4 stdmath_double4_wwxx_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.w = value.y; v.x = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wwxy(stdmath_double4 v) { return {v.w,v.w,v.x,v.y}; }
inline static stdmath_double4 stdmath_double4_wwxy_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.w = value.y; v.x = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wwxz(stdmath_double4 v) { return {v.w,v.w,v.x,v.z}; }
inline static stdmath_double4 stdmath_double4_wwxz_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.w = value.y; v.x = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wwxw(stdmath_double4 v) { return {v.w,v.w,v.x,v.w}; }
inline static stdmath_double4 stdmath_double4_wwxw_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.w = value.y; v.x = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wwyx(stdmath_double4 v) { return {v.w,v.w,v.y,v.x}; }
inline static stdmath_double4 stdmath_double4_wwyx_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.w = value.y; v.y = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wwyy(stdmath_double4 v) { return {v.w,v.w,v.y,v.y}; }
inline static stdmath_double4 stdmath_double4_wwyy_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.w = value.y; v.y = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wwyz(stdmath_double4 v) { return {v.w,v.w,v.y,v.z}; }
inline static stdmath_double4 stdmath_double4_wwyz_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.w = value.y; v.y = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wwyw(stdmath_double4 v) { return {v.w,v.w,v.y,v.w}; }
inline static stdmath_double4 stdmath_double4_wwyw_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.w = value.y; v.y = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wwzx(stdmath_double4 v) { return {v.w,v.w,v.z,v.x}; }
inline static stdmath_double4 stdmath_double4_wwzx_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.w = value.y; v.z = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wwzy(stdmath_double4 v) { return {v.w,v.w,v.z,v.y}; }
inline static stdmath_double4 stdmath_double4_wwzy_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.w = value.y; v.z = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wwzz(stdmath_double4 v) { return {v.w,v.w,v.z,v.z}; }
inline static stdmath_double4 stdmath_double4_wwzz_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.w = value.y; v.z = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wwzw(stdmath_double4 v) { return {v.w,v.w,v.z,v.w}; }
inline static stdmath_double4 stdmath_double4_wwzw_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.w = value.y; v.z = value.z; v.w = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wwwx(stdmath_double4 v) { return {v.w,v.w,v.w,v.x}; }
inline static stdmath_double4 stdmath_double4_wwwx_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.w = value.y; v.w = value.z; v.x = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wwwy(stdmath_double4 v) { return {v.w,v.w,v.w,v.y}; }
inline static stdmath_double4 stdmath_double4_wwwy_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.w = value.y; v.w = value.z; v.y = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wwwz(stdmath_double4 v) { return {v.w,v.w,v.w,v.z}; }
inline static stdmath_double4 stdmath_double4_wwwz_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.w = value.y; v.w = value.z; v.z = value.w; return v; }
inline static stdmath_double4 stdmath_double4_wwww(stdmath_double4 v) { return {v.w,v.w,v.w,v.w}; }
inline static stdmath_double4 stdmath_double4_wwww_value(stdmath_double4 v, stdmath_double4 value) { v.w = value.x; v.w = value.y; v.w = value.z; v.w = value.w; return v; }


#ifdef STDMATH_IMPLEMENTATION
#ifndef __cplusplus
#error "The stdmath implementations require a C++ compiler"
#endif

import stdmath.slang;

stdmath::double4 c(stdmath_double4 c) {
	return (stdmath::double4&)c;
}
stdmath_double4 c(stdmath::double4 c) {
	return (stdmath_double4&)c;
}

stdmath_double4 stdmath_double4_broadcast(double all) {
	return c(stdmath::double4((stdmath::double4::underlying_type)all));
}

stdmath_double4 stdmath_double4_add(stdmath_double4 a, stdmath_double4 b) {
	return c(c(a) + c(b));
}
stdmath_double4 stdmath_double4_subtract(stdmath_double4 a, stdmath_double4 b) {
	return c(c(a) - c(b));
}
stdmath_double4 stdmath_double4_negate(stdmath_double4 v) {
	return c(stdmath::double4(-(stdmath::vector<double, 4>)c(v)));
}
stdmath_double4 stdmath_double4_multiply(stdmath_double4 a, stdmath_double4 b) {
	return c(c(a) * c(b));
}
stdmath_double4 stdmath_double4_divide(stdmath_double4 a, stdmath_double4 b) {
	return c(c(a) / c(b));
}
stdmath_double4 stdmath_double4_scale(stdmath_double4 v, double s) {
	return c(c(v) * (stdmath::double4::underlying_type)s);
}

#if false
stdmath_double4 stdmath_double4_modulus(stdmath_double4 a, stdmath_double4 b) {
	return c(c(a) % c(b));
}
stdmath_double4 stdmath_double4_logical_not(stdmath_double4 v) {
	return c(!c(v));
}
stdmath_double4 stdmath_double4_bitwise_not(stdmath_double4 v) {
	return c(~c(v));
}
stdmath_double4 stdmath_double4_logical_and(stdmath_double4 a, stdmath_double4 b) {
	return c(c(a) && c(b));
}
stdmath_double4 stdmath_double4_bitwise_and(stdmath_double4 a, stdmath_double4 b) {
	return c(c(a) & c(b));
}
stdmath_double4 stdmath_double4_logical_or(stdmath_double4 a, stdmath_double4 b) {
	return c(c(a) || c(b));
}
stdmath_double4 stdmath_double4_bitwise_or(stdmath_double4 a, stdmath_double4 b) {
	return c(c(a) | c(b));
}
stdmath_double4 stdmath_double4_bitwise_xor(stdmath_double4 a, stdmath_double4 b) {
	return c(c(a) ^ c(b));
}
stdmath_double4 stdmath_double4_shift_left(stdmath_double4 a, stdmath_double4 b) {
	return c(c(a) << c(b));
}
stdmath_double4 stdmath_double4_shift_right(stdmath_double4 a, stdmath_double4 b) {
	return c(c(a) >> c(b));
}
#endif

stdmath_bool4 stdmath_double4_equal_to(stdmath_double4 a, stdmath_double4 b) {
	return c(c(a) == c(b));
}
stdmath_bool4 stdmath_double4_not_equal_to(stdmath_double4 a, stdmath_double4 b) {
	return c(c(a) != c(b));
}
stdmath_bool4 stdmath_double4_less_than(stdmath_double4 a, stdmath_double4 b) {
	return c(c(a) < c(b));
}
stdmath_bool4 stdmath_double4_less_than_or_equal_to(stdmath_double4 a, stdmath_double4 b) {
	return c(c(a) <= c(b));
}
stdmath_bool4 stdmath_double4_greater_than(stdmath_double4 a, stdmath_double4 b) {
	return c(c(a) > c(b));
}
stdmath_bool4 stdmath_double4_greater_than_or_equal_to(stdmath_double4 a, stdmath_double4 b) {
	return c(c(a) >= c(b));
}

double stdmath_double4_length_squared(stdmath_double4 v)  {
	return (double)c(v).length_squared();
}
double stdmath_double4_length(stdmath_double4 v)  {
	return (double)c(v).length();
}
double stdmath_double4_dot(stdmath_double4 a, stdmath_double4 b)  {
	return (double)dot(c(a), c(b));
}
double stdmath_double4_min_element(stdmath_double4 v)  {
	return (double)c(v).min_element();
}
double stdmath_double4_max_element(stdmath_double4 v)  {
	return (double)c(v).max_element();
}

stdmath_double4 stdmath_double4_elementwise_transform(stdmath_double4 v, double(*func)(double)) {
	return c(c(v).elementwise_transform(func));
}
// double stdmath_double4_reduce_elements(stdmath_double4 v, double initial_value, double(*reducer)(stdmath_double4, stdmath_double4)) {
// 	return c(v).reduce_elements(initial_value, reducer);
// }

#if 4 == 3
stdmath_double4 stdmath_double4_cross(stdmath_double4 a, stdmath_double4 b) {
	return c(cross(c(a), c(b)));
}
#endif

stdmath_double4 stdmath_double4_min(stdmath_double4 a, stdmath_double4 b) {
	return c(min(c(a), c(b)));
}
stdmath_double4 stdmath_double4_max(stdmath_double4 a, stdmath_double4 b) {
	return c(max(c(a), c(b)));
}
stdmath_double4 stdmath_double4_normalize(stdmath_double4 v) {
	return c(normalize(c(v)));
}
stdmath_double4 stdmath_double4_lerp(stdmath_double4 a, stdmath_double4 b, float t) {
	return c(lerp(c(a), c(b), t));
}
stdmath_double4 stdmath_double4_clamp(stdmath_double4 a, stdmath_double4 min, stdmath_double4 max) {
	return c(clamp(c(a), c(min), c(max)));
}
stdmath_double4 stdmath_double4_reflect(stdmath_double4 a, stdmath_double4 b) {
	return c(reflect(c(a), c(b)));
}
stdmath_bool4 stdmath_double4_approximately_equal(stdmath_double4 a, stdmath_double4 b) {
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

#endif // __STDMATH_double4_H__