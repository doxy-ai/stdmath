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
double stdmath_double4_dot(stdmath_double4 a, stdmath_double4 b);
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
inline static stdmath_double1 stdmath_double4_x_get(stdmath_double4* p) { return stdmath_double4_x(*p); }
inline static stdmath_double4 stdmath_double4_x_set(stdmath_double4* p, stdmath_double1 value) { p->x = value.x; return *p; }
inline static stdmath_double1 stdmath_double4_y(stdmath_double4 v) { return {v.y}; }
inline static stdmath_double1 stdmath_double4_y_get(stdmath_double4* p) { return stdmath_double4_y(*p); }
inline static stdmath_double4 stdmath_double4_y_set(stdmath_double4* p, stdmath_double1 value) { p->y = value.x; return *p; }
inline static stdmath_double1 stdmath_double4_z(stdmath_double4 v) { return {v.z}; }
inline static stdmath_double1 stdmath_double4_z_get(stdmath_double4* p) { return stdmath_double4_z(*p); }
inline static stdmath_double4 stdmath_double4_z_set(stdmath_double4* p, stdmath_double1 value) { p->z = value.x; return *p; }
inline static stdmath_double1 stdmath_double4_w(stdmath_double4 v) { return {v.w}; }
inline static stdmath_double1 stdmath_double4_w_get(stdmath_double4* p) { return stdmath_double4_w(*p); }
inline static stdmath_double4 stdmath_double4_w_set(stdmath_double4* p, stdmath_double1 value) { p->w = value.x; return *p; }
inline static stdmath_double2 stdmath_double4_xx(stdmath_double4 v) { return {v.x,v.x}; }
inline static stdmath_double2 stdmath_double4_xx_get(stdmath_double4* p) { return stdmath_double4_xx(*p); }
inline static stdmath_double4 stdmath_double4_xx_set(stdmath_double4* p, stdmath_double2 value) { p->x = value.x; p->x = value.y; return *p; }
inline static stdmath_double2 stdmath_double4_xy(stdmath_double4 v) { return {v.x,v.y}; }
inline static stdmath_double2 stdmath_double4_xy_get(stdmath_double4* p) { return stdmath_double4_xy(*p); }
inline static stdmath_double4 stdmath_double4_xy_set(stdmath_double4* p, stdmath_double2 value) { p->x = value.x; p->y = value.y; return *p; }
inline static stdmath_double2 stdmath_double4_xz(stdmath_double4 v) { return {v.x,v.z}; }
inline static stdmath_double2 stdmath_double4_xz_get(stdmath_double4* p) { return stdmath_double4_xz(*p); }
inline static stdmath_double4 stdmath_double4_xz_set(stdmath_double4* p, stdmath_double2 value) { p->x = value.x; p->z = value.y; return *p; }
inline static stdmath_double2 stdmath_double4_xw(stdmath_double4 v) { return {v.x,v.w}; }
inline static stdmath_double2 stdmath_double4_xw_get(stdmath_double4* p) { return stdmath_double4_xw(*p); }
inline static stdmath_double4 stdmath_double4_xw_set(stdmath_double4* p, stdmath_double2 value) { p->x = value.x; p->w = value.y; return *p; }
inline static stdmath_double2 stdmath_double4_yx(stdmath_double4 v) { return {v.y,v.x}; }
inline static stdmath_double2 stdmath_double4_yx_get(stdmath_double4* p) { return stdmath_double4_yx(*p); }
inline static stdmath_double4 stdmath_double4_yx_set(stdmath_double4* p, stdmath_double2 value) { p->y = value.x; p->x = value.y; return *p; }
inline static stdmath_double2 stdmath_double4_yy(stdmath_double4 v) { return {v.y,v.y}; }
inline static stdmath_double2 stdmath_double4_yy_get(stdmath_double4* p) { return stdmath_double4_yy(*p); }
inline static stdmath_double4 stdmath_double4_yy_set(stdmath_double4* p, stdmath_double2 value) { p->y = value.x; p->y = value.y; return *p; }
inline static stdmath_double2 stdmath_double4_yz(stdmath_double4 v) { return {v.y,v.z}; }
inline static stdmath_double2 stdmath_double4_yz_get(stdmath_double4* p) { return stdmath_double4_yz(*p); }
inline static stdmath_double4 stdmath_double4_yz_set(stdmath_double4* p, stdmath_double2 value) { p->y = value.x; p->z = value.y; return *p; }
inline static stdmath_double2 stdmath_double4_yw(stdmath_double4 v) { return {v.y,v.w}; }
inline static stdmath_double2 stdmath_double4_yw_get(stdmath_double4* p) { return stdmath_double4_yw(*p); }
inline static stdmath_double4 stdmath_double4_yw_set(stdmath_double4* p, stdmath_double2 value) { p->y = value.x; p->w = value.y; return *p; }
inline static stdmath_double2 stdmath_double4_zx(stdmath_double4 v) { return {v.z,v.x}; }
inline static stdmath_double2 stdmath_double4_zx_get(stdmath_double4* p) { return stdmath_double4_zx(*p); }
inline static stdmath_double4 stdmath_double4_zx_set(stdmath_double4* p, stdmath_double2 value) { p->z = value.x; p->x = value.y; return *p; }
inline static stdmath_double2 stdmath_double4_zy(stdmath_double4 v) { return {v.z,v.y}; }
inline static stdmath_double2 stdmath_double4_zy_get(stdmath_double4* p) { return stdmath_double4_zy(*p); }
inline static stdmath_double4 stdmath_double4_zy_set(stdmath_double4* p, stdmath_double2 value) { p->z = value.x; p->y = value.y; return *p; }
inline static stdmath_double2 stdmath_double4_zz(stdmath_double4 v) { return {v.z,v.z}; }
inline static stdmath_double2 stdmath_double4_zz_get(stdmath_double4* p) { return stdmath_double4_zz(*p); }
inline static stdmath_double4 stdmath_double4_zz_set(stdmath_double4* p, stdmath_double2 value) { p->z = value.x; p->z = value.y; return *p; }
inline static stdmath_double2 stdmath_double4_zw(stdmath_double4 v) { return {v.z,v.w}; }
inline static stdmath_double2 stdmath_double4_zw_get(stdmath_double4* p) { return stdmath_double4_zw(*p); }
inline static stdmath_double4 stdmath_double4_zw_set(stdmath_double4* p, stdmath_double2 value) { p->z = value.x; p->w = value.y; return *p; }
inline static stdmath_double2 stdmath_double4_wx(stdmath_double4 v) { return {v.w,v.x}; }
inline static stdmath_double2 stdmath_double4_wx_get(stdmath_double4* p) { return stdmath_double4_wx(*p); }
inline static stdmath_double4 stdmath_double4_wx_set(stdmath_double4* p, stdmath_double2 value) { p->w = value.x; p->x = value.y; return *p; }
inline static stdmath_double2 stdmath_double4_wy(stdmath_double4 v) { return {v.w,v.y}; }
inline static stdmath_double2 stdmath_double4_wy_get(stdmath_double4* p) { return stdmath_double4_wy(*p); }
inline static stdmath_double4 stdmath_double4_wy_set(stdmath_double4* p, stdmath_double2 value) { p->w = value.x; p->y = value.y; return *p; }
inline static stdmath_double2 stdmath_double4_wz(stdmath_double4 v) { return {v.w,v.z}; }
inline static stdmath_double2 stdmath_double4_wz_get(stdmath_double4* p) { return stdmath_double4_wz(*p); }
inline static stdmath_double4 stdmath_double4_wz_set(stdmath_double4* p, stdmath_double2 value) { p->w = value.x; p->z = value.y; return *p; }
inline static stdmath_double2 stdmath_double4_ww(stdmath_double4 v) { return {v.w,v.w}; }
inline static stdmath_double2 stdmath_double4_ww_get(stdmath_double4* p) { return stdmath_double4_ww(*p); }
inline static stdmath_double4 stdmath_double4_ww_set(stdmath_double4* p, stdmath_double2 value) { p->w = value.x; p->w = value.y; return *p; }
inline static stdmath_double3 stdmath_double4_xxx(stdmath_double4 v) { return {v.x,v.x,v.x}; }
inline static stdmath_double3 stdmath_double4_xxx_get(stdmath_double4* p) { return stdmath_double4_xxx(*p); }
inline static stdmath_double4 stdmath_double4_xxx_set(stdmath_double4* p, stdmath_double3 value) { p->x = value.x; p->x = value.y; p->x = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_xxy(stdmath_double4 v) { return {v.x,v.x,v.y}; }
inline static stdmath_double3 stdmath_double4_xxy_get(stdmath_double4* p) { return stdmath_double4_xxy(*p); }
inline static stdmath_double4 stdmath_double4_xxy_set(stdmath_double4* p, stdmath_double3 value) { p->x = value.x; p->x = value.y; p->y = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_xxz(stdmath_double4 v) { return {v.x,v.x,v.z}; }
inline static stdmath_double3 stdmath_double4_xxz_get(stdmath_double4* p) { return stdmath_double4_xxz(*p); }
inline static stdmath_double4 stdmath_double4_xxz_set(stdmath_double4* p, stdmath_double3 value) { p->x = value.x; p->x = value.y; p->z = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_xxw(stdmath_double4 v) { return {v.x,v.x,v.w}; }
inline static stdmath_double3 stdmath_double4_xxw_get(stdmath_double4* p) { return stdmath_double4_xxw(*p); }
inline static stdmath_double4 stdmath_double4_xxw_set(stdmath_double4* p, stdmath_double3 value) { p->x = value.x; p->x = value.y; p->w = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_xyx(stdmath_double4 v) { return {v.x,v.y,v.x}; }
inline static stdmath_double3 stdmath_double4_xyx_get(stdmath_double4* p) { return stdmath_double4_xyx(*p); }
inline static stdmath_double4 stdmath_double4_xyx_set(stdmath_double4* p, stdmath_double3 value) { p->x = value.x; p->y = value.y; p->x = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_xyy(stdmath_double4 v) { return {v.x,v.y,v.y}; }
inline static stdmath_double3 stdmath_double4_xyy_get(stdmath_double4* p) { return stdmath_double4_xyy(*p); }
inline static stdmath_double4 stdmath_double4_xyy_set(stdmath_double4* p, stdmath_double3 value) { p->x = value.x; p->y = value.y; p->y = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_xyz(stdmath_double4 v) { return {v.x,v.y,v.z}; }
inline static stdmath_double3 stdmath_double4_xyz_get(stdmath_double4* p) { return stdmath_double4_xyz(*p); }
inline static stdmath_double4 stdmath_double4_xyz_set(stdmath_double4* p, stdmath_double3 value) { p->x = value.x; p->y = value.y; p->z = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_xyw(stdmath_double4 v) { return {v.x,v.y,v.w}; }
inline static stdmath_double3 stdmath_double4_xyw_get(stdmath_double4* p) { return stdmath_double4_xyw(*p); }
inline static stdmath_double4 stdmath_double4_xyw_set(stdmath_double4* p, stdmath_double3 value) { p->x = value.x; p->y = value.y; p->w = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_xzx(stdmath_double4 v) { return {v.x,v.z,v.x}; }
inline static stdmath_double3 stdmath_double4_xzx_get(stdmath_double4* p) { return stdmath_double4_xzx(*p); }
inline static stdmath_double4 stdmath_double4_xzx_set(stdmath_double4* p, stdmath_double3 value) { p->x = value.x; p->z = value.y; p->x = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_xzy(stdmath_double4 v) { return {v.x,v.z,v.y}; }
inline static stdmath_double3 stdmath_double4_xzy_get(stdmath_double4* p) { return stdmath_double4_xzy(*p); }
inline static stdmath_double4 stdmath_double4_xzy_set(stdmath_double4* p, stdmath_double3 value) { p->x = value.x; p->z = value.y; p->y = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_xzz(stdmath_double4 v) { return {v.x,v.z,v.z}; }
inline static stdmath_double3 stdmath_double4_xzz_get(stdmath_double4* p) { return stdmath_double4_xzz(*p); }
inline static stdmath_double4 stdmath_double4_xzz_set(stdmath_double4* p, stdmath_double3 value) { p->x = value.x; p->z = value.y; p->z = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_xzw(stdmath_double4 v) { return {v.x,v.z,v.w}; }
inline static stdmath_double3 stdmath_double4_xzw_get(stdmath_double4* p) { return stdmath_double4_xzw(*p); }
inline static stdmath_double4 stdmath_double4_xzw_set(stdmath_double4* p, stdmath_double3 value) { p->x = value.x; p->z = value.y; p->w = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_xwx(stdmath_double4 v) { return {v.x,v.w,v.x}; }
inline static stdmath_double3 stdmath_double4_xwx_get(stdmath_double4* p) { return stdmath_double4_xwx(*p); }
inline static stdmath_double4 stdmath_double4_xwx_set(stdmath_double4* p, stdmath_double3 value) { p->x = value.x; p->w = value.y; p->x = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_xwy(stdmath_double4 v) { return {v.x,v.w,v.y}; }
inline static stdmath_double3 stdmath_double4_xwy_get(stdmath_double4* p) { return stdmath_double4_xwy(*p); }
inline static stdmath_double4 stdmath_double4_xwy_set(stdmath_double4* p, stdmath_double3 value) { p->x = value.x; p->w = value.y; p->y = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_xwz(stdmath_double4 v) { return {v.x,v.w,v.z}; }
inline static stdmath_double3 stdmath_double4_xwz_get(stdmath_double4* p) { return stdmath_double4_xwz(*p); }
inline static stdmath_double4 stdmath_double4_xwz_set(stdmath_double4* p, stdmath_double3 value) { p->x = value.x; p->w = value.y; p->z = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_xww(stdmath_double4 v) { return {v.x,v.w,v.w}; }
inline static stdmath_double3 stdmath_double4_xww_get(stdmath_double4* p) { return stdmath_double4_xww(*p); }
inline static stdmath_double4 stdmath_double4_xww_set(stdmath_double4* p, stdmath_double3 value) { p->x = value.x; p->w = value.y; p->w = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_yxx(stdmath_double4 v) { return {v.y,v.x,v.x}; }
inline static stdmath_double3 stdmath_double4_yxx_get(stdmath_double4* p) { return stdmath_double4_yxx(*p); }
inline static stdmath_double4 stdmath_double4_yxx_set(stdmath_double4* p, stdmath_double3 value) { p->y = value.x; p->x = value.y; p->x = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_yxy(stdmath_double4 v) { return {v.y,v.x,v.y}; }
inline static stdmath_double3 stdmath_double4_yxy_get(stdmath_double4* p) { return stdmath_double4_yxy(*p); }
inline static stdmath_double4 stdmath_double4_yxy_set(stdmath_double4* p, stdmath_double3 value) { p->y = value.x; p->x = value.y; p->y = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_yxz(stdmath_double4 v) { return {v.y,v.x,v.z}; }
inline static stdmath_double3 stdmath_double4_yxz_get(stdmath_double4* p) { return stdmath_double4_yxz(*p); }
inline static stdmath_double4 stdmath_double4_yxz_set(stdmath_double4* p, stdmath_double3 value) { p->y = value.x; p->x = value.y; p->z = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_yxw(stdmath_double4 v) { return {v.y,v.x,v.w}; }
inline static stdmath_double3 stdmath_double4_yxw_get(stdmath_double4* p) { return stdmath_double4_yxw(*p); }
inline static stdmath_double4 stdmath_double4_yxw_set(stdmath_double4* p, stdmath_double3 value) { p->y = value.x; p->x = value.y; p->w = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_yyx(stdmath_double4 v) { return {v.y,v.y,v.x}; }
inline static stdmath_double3 stdmath_double4_yyx_get(stdmath_double4* p) { return stdmath_double4_yyx(*p); }
inline static stdmath_double4 stdmath_double4_yyx_set(stdmath_double4* p, stdmath_double3 value) { p->y = value.x; p->y = value.y; p->x = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_yyy(stdmath_double4 v) { return {v.y,v.y,v.y}; }
inline static stdmath_double3 stdmath_double4_yyy_get(stdmath_double4* p) { return stdmath_double4_yyy(*p); }
inline static stdmath_double4 stdmath_double4_yyy_set(stdmath_double4* p, stdmath_double3 value) { p->y = value.x; p->y = value.y; p->y = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_yyz(stdmath_double4 v) { return {v.y,v.y,v.z}; }
inline static stdmath_double3 stdmath_double4_yyz_get(stdmath_double4* p) { return stdmath_double4_yyz(*p); }
inline static stdmath_double4 stdmath_double4_yyz_set(stdmath_double4* p, stdmath_double3 value) { p->y = value.x; p->y = value.y; p->z = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_yyw(stdmath_double4 v) { return {v.y,v.y,v.w}; }
inline static stdmath_double3 stdmath_double4_yyw_get(stdmath_double4* p) { return stdmath_double4_yyw(*p); }
inline static stdmath_double4 stdmath_double4_yyw_set(stdmath_double4* p, stdmath_double3 value) { p->y = value.x; p->y = value.y; p->w = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_yzx(stdmath_double4 v) { return {v.y,v.z,v.x}; }
inline static stdmath_double3 stdmath_double4_yzx_get(stdmath_double4* p) { return stdmath_double4_yzx(*p); }
inline static stdmath_double4 stdmath_double4_yzx_set(stdmath_double4* p, stdmath_double3 value) { p->y = value.x; p->z = value.y; p->x = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_yzy(stdmath_double4 v) { return {v.y,v.z,v.y}; }
inline static stdmath_double3 stdmath_double4_yzy_get(stdmath_double4* p) { return stdmath_double4_yzy(*p); }
inline static stdmath_double4 stdmath_double4_yzy_set(stdmath_double4* p, stdmath_double3 value) { p->y = value.x; p->z = value.y; p->y = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_yzz(stdmath_double4 v) { return {v.y,v.z,v.z}; }
inline static stdmath_double3 stdmath_double4_yzz_get(stdmath_double4* p) { return stdmath_double4_yzz(*p); }
inline static stdmath_double4 stdmath_double4_yzz_set(stdmath_double4* p, stdmath_double3 value) { p->y = value.x; p->z = value.y; p->z = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_yzw(stdmath_double4 v) { return {v.y,v.z,v.w}; }
inline static stdmath_double3 stdmath_double4_yzw_get(stdmath_double4* p) { return stdmath_double4_yzw(*p); }
inline static stdmath_double4 stdmath_double4_yzw_set(stdmath_double4* p, stdmath_double3 value) { p->y = value.x; p->z = value.y; p->w = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_ywx(stdmath_double4 v) { return {v.y,v.w,v.x}; }
inline static stdmath_double3 stdmath_double4_ywx_get(stdmath_double4* p) { return stdmath_double4_ywx(*p); }
inline static stdmath_double4 stdmath_double4_ywx_set(stdmath_double4* p, stdmath_double3 value) { p->y = value.x; p->w = value.y; p->x = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_ywy(stdmath_double4 v) { return {v.y,v.w,v.y}; }
inline static stdmath_double3 stdmath_double4_ywy_get(stdmath_double4* p) { return stdmath_double4_ywy(*p); }
inline static stdmath_double4 stdmath_double4_ywy_set(stdmath_double4* p, stdmath_double3 value) { p->y = value.x; p->w = value.y; p->y = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_ywz(stdmath_double4 v) { return {v.y,v.w,v.z}; }
inline static stdmath_double3 stdmath_double4_ywz_get(stdmath_double4* p) { return stdmath_double4_ywz(*p); }
inline static stdmath_double4 stdmath_double4_ywz_set(stdmath_double4* p, stdmath_double3 value) { p->y = value.x; p->w = value.y; p->z = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_yww(stdmath_double4 v) { return {v.y,v.w,v.w}; }
inline static stdmath_double3 stdmath_double4_yww_get(stdmath_double4* p) { return stdmath_double4_yww(*p); }
inline static stdmath_double4 stdmath_double4_yww_set(stdmath_double4* p, stdmath_double3 value) { p->y = value.x; p->w = value.y; p->w = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_zxx(stdmath_double4 v) { return {v.z,v.x,v.x}; }
inline static stdmath_double3 stdmath_double4_zxx_get(stdmath_double4* p) { return stdmath_double4_zxx(*p); }
inline static stdmath_double4 stdmath_double4_zxx_set(stdmath_double4* p, stdmath_double3 value) { p->z = value.x; p->x = value.y; p->x = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_zxy(stdmath_double4 v) { return {v.z,v.x,v.y}; }
inline static stdmath_double3 stdmath_double4_zxy_get(stdmath_double4* p) { return stdmath_double4_zxy(*p); }
inline static stdmath_double4 stdmath_double4_zxy_set(stdmath_double4* p, stdmath_double3 value) { p->z = value.x; p->x = value.y; p->y = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_zxz(stdmath_double4 v) { return {v.z,v.x,v.z}; }
inline static stdmath_double3 stdmath_double4_zxz_get(stdmath_double4* p) { return stdmath_double4_zxz(*p); }
inline static stdmath_double4 stdmath_double4_zxz_set(stdmath_double4* p, stdmath_double3 value) { p->z = value.x; p->x = value.y; p->z = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_zxw(stdmath_double4 v) { return {v.z,v.x,v.w}; }
inline static stdmath_double3 stdmath_double4_zxw_get(stdmath_double4* p) { return stdmath_double4_zxw(*p); }
inline static stdmath_double4 stdmath_double4_zxw_set(stdmath_double4* p, stdmath_double3 value) { p->z = value.x; p->x = value.y; p->w = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_zyx(stdmath_double4 v) { return {v.z,v.y,v.x}; }
inline static stdmath_double3 stdmath_double4_zyx_get(stdmath_double4* p) { return stdmath_double4_zyx(*p); }
inline static stdmath_double4 stdmath_double4_zyx_set(stdmath_double4* p, stdmath_double3 value) { p->z = value.x; p->y = value.y; p->x = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_zyy(stdmath_double4 v) { return {v.z,v.y,v.y}; }
inline static stdmath_double3 stdmath_double4_zyy_get(stdmath_double4* p) { return stdmath_double4_zyy(*p); }
inline static stdmath_double4 stdmath_double4_zyy_set(stdmath_double4* p, stdmath_double3 value) { p->z = value.x; p->y = value.y; p->y = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_zyz(stdmath_double4 v) { return {v.z,v.y,v.z}; }
inline static stdmath_double3 stdmath_double4_zyz_get(stdmath_double4* p) { return stdmath_double4_zyz(*p); }
inline static stdmath_double4 stdmath_double4_zyz_set(stdmath_double4* p, stdmath_double3 value) { p->z = value.x; p->y = value.y; p->z = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_zyw(stdmath_double4 v) { return {v.z,v.y,v.w}; }
inline static stdmath_double3 stdmath_double4_zyw_get(stdmath_double4* p) { return stdmath_double4_zyw(*p); }
inline static stdmath_double4 stdmath_double4_zyw_set(stdmath_double4* p, stdmath_double3 value) { p->z = value.x; p->y = value.y; p->w = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_zzx(stdmath_double4 v) { return {v.z,v.z,v.x}; }
inline static stdmath_double3 stdmath_double4_zzx_get(stdmath_double4* p) { return stdmath_double4_zzx(*p); }
inline static stdmath_double4 stdmath_double4_zzx_set(stdmath_double4* p, stdmath_double3 value) { p->z = value.x; p->z = value.y; p->x = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_zzy(stdmath_double4 v) { return {v.z,v.z,v.y}; }
inline static stdmath_double3 stdmath_double4_zzy_get(stdmath_double4* p) { return stdmath_double4_zzy(*p); }
inline static stdmath_double4 stdmath_double4_zzy_set(stdmath_double4* p, stdmath_double3 value) { p->z = value.x; p->z = value.y; p->y = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_zzz(stdmath_double4 v) { return {v.z,v.z,v.z}; }
inline static stdmath_double3 stdmath_double4_zzz_get(stdmath_double4* p) { return stdmath_double4_zzz(*p); }
inline static stdmath_double4 stdmath_double4_zzz_set(stdmath_double4* p, stdmath_double3 value) { p->z = value.x; p->z = value.y; p->z = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_zzw(stdmath_double4 v) { return {v.z,v.z,v.w}; }
inline static stdmath_double3 stdmath_double4_zzw_get(stdmath_double4* p) { return stdmath_double4_zzw(*p); }
inline static stdmath_double4 stdmath_double4_zzw_set(stdmath_double4* p, stdmath_double3 value) { p->z = value.x; p->z = value.y; p->w = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_zwx(stdmath_double4 v) { return {v.z,v.w,v.x}; }
inline static stdmath_double3 stdmath_double4_zwx_get(stdmath_double4* p) { return stdmath_double4_zwx(*p); }
inline static stdmath_double4 stdmath_double4_zwx_set(stdmath_double4* p, stdmath_double3 value) { p->z = value.x; p->w = value.y; p->x = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_zwy(stdmath_double4 v) { return {v.z,v.w,v.y}; }
inline static stdmath_double3 stdmath_double4_zwy_get(stdmath_double4* p) { return stdmath_double4_zwy(*p); }
inline static stdmath_double4 stdmath_double4_zwy_set(stdmath_double4* p, stdmath_double3 value) { p->z = value.x; p->w = value.y; p->y = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_zwz(stdmath_double4 v) { return {v.z,v.w,v.z}; }
inline static stdmath_double3 stdmath_double4_zwz_get(stdmath_double4* p) { return stdmath_double4_zwz(*p); }
inline static stdmath_double4 stdmath_double4_zwz_set(stdmath_double4* p, stdmath_double3 value) { p->z = value.x; p->w = value.y; p->z = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_zww(stdmath_double4 v) { return {v.z,v.w,v.w}; }
inline static stdmath_double3 stdmath_double4_zww_get(stdmath_double4* p) { return stdmath_double4_zww(*p); }
inline static stdmath_double4 stdmath_double4_zww_set(stdmath_double4* p, stdmath_double3 value) { p->z = value.x; p->w = value.y; p->w = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_wxx(stdmath_double4 v) { return {v.w,v.x,v.x}; }
inline static stdmath_double3 stdmath_double4_wxx_get(stdmath_double4* p) { return stdmath_double4_wxx(*p); }
inline static stdmath_double4 stdmath_double4_wxx_set(stdmath_double4* p, stdmath_double3 value) { p->w = value.x; p->x = value.y; p->x = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_wxy(stdmath_double4 v) { return {v.w,v.x,v.y}; }
inline static stdmath_double3 stdmath_double4_wxy_get(stdmath_double4* p) { return stdmath_double4_wxy(*p); }
inline static stdmath_double4 stdmath_double4_wxy_set(stdmath_double4* p, stdmath_double3 value) { p->w = value.x; p->x = value.y; p->y = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_wxz(stdmath_double4 v) { return {v.w,v.x,v.z}; }
inline static stdmath_double3 stdmath_double4_wxz_get(stdmath_double4* p) { return stdmath_double4_wxz(*p); }
inline static stdmath_double4 stdmath_double4_wxz_set(stdmath_double4* p, stdmath_double3 value) { p->w = value.x; p->x = value.y; p->z = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_wxw(stdmath_double4 v) { return {v.w,v.x,v.w}; }
inline static stdmath_double3 stdmath_double4_wxw_get(stdmath_double4* p) { return stdmath_double4_wxw(*p); }
inline static stdmath_double4 stdmath_double4_wxw_set(stdmath_double4* p, stdmath_double3 value) { p->w = value.x; p->x = value.y; p->w = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_wyx(stdmath_double4 v) { return {v.w,v.y,v.x}; }
inline static stdmath_double3 stdmath_double4_wyx_get(stdmath_double4* p) { return stdmath_double4_wyx(*p); }
inline static stdmath_double4 stdmath_double4_wyx_set(stdmath_double4* p, stdmath_double3 value) { p->w = value.x; p->y = value.y; p->x = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_wyy(stdmath_double4 v) { return {v.w,v.y,v.y}; }
inline static stdmath_double3 stdmath_double4_wyy_get(stdmath_double4* p) { return stdmath_double4_wyy(*p); }
inline static stdmath_double4 stdmath_double4_wyy_set(stdmath_double4* p, stdmath_double3 value) { p->w = value.x; p->y = value.y; p->y = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_wyz(stdmath_double4 v) { return {v.w,v.y,v.z}; }
inline static stdmath_double3 stdmath_double4_wyz_get(stdmath_double4* p) { return stdmath_double4_wyz(*p); }
inline static stdmath_double4 stdmath_double4_wyz_set(stdmath_double4* p, stdmath_double3 value) { p->w = value.x; p->y = value.y; p->z = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_wyw(stdmath_double4 v) { return {v.w,v.y,v.w}; }
inline static stdmath_double3 stdmath_double4_wyw_get(stdmath_double4* p) { return stdmath_double4_wyw(*p); }
inline static stdmath_double4 stdmath_double4_wyw_set(stdmath_double4* p, stdmath_double3 value) { p->w = value.x; p->y = value.y; p->w = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_wzx(stdmath_double4 v) { return {v.w,v.z,v.x}; }
inline static stdmath_double3 stdmath_double4_wzx_get(stdmath_double4* p) { return stdmath_double4_wzx(*p); }
inline static stdmath_double4 stdmath_double4_wzx_set(stdmath_double4* p, stdmath_double3 value) { p->w = value.x; p->z = value.y; p->x = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_wzy(stdmath_double4 v) { return {v.w,v.z,v.y}; }
inline static stdmath_double3 stdmath_double4_wzy_get(stdmath_double4* p) { return stdmath_double4_wzy(*p); }
inline static stdmath_double4 stdmath_double4_wzy_set(stdmath_double4* p, stdmath_double3 value) { p->w = value.x; p->z = value.y; p->y = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_wzz(stdmath_double4 v) { return {v.w,v.z,v.z}; }
inline static stdmath_double3 stdmath_double4_wzz_get(stdmath_double4* p) { return stdmath_double4_wzz(*p); }
inline static stdmath_double4 stdmath_double4_wzz_set(stdmath_double4* p, stdmath_double3 value) { p->w = value.x; p->z = value.y; p->z = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_wzw(stdmath_double4 v) { return {v.w,v.z,v.w}; }
inline static stdmath_double3 stdmath_double4_wzw_get(stdmath_double4* p) { return stdmath_double4_wzw(*p); }
inline static stdmath_double4 stdmath_double4_wzw_set(stdmath_double4* p, stdmath_double3 value) { p->w = value.x; p->z = value.y; p->w = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_wwx(stdmath_double4 v) { return {v.w,v.w,v.x}; }
inline static stdmath_double3 stdmath_double4_wwx_get(stdmath_double4* p) { return stdmath_double4_wwx(*p); }
inline static stdmath_double4 stdmath_double4_wwx_set(stdmath_double4* p, stdmath_double3 value) { p->w = value.x; p->w = value.y; p->x = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_wwy(stdmath_double4 v) { return {v.w,v.w,v.y}; }
inline static stdmath_double3 stdmath_double4_wwy_get(stdmath_double4* p) { return stdmath_double4_wwy(*p); }
inline static stdmath_double4 stdmath_double4_wwy_set(stdmath_double4* p, stdmath_double3 value) { p->w = value.x; p->w = value.y; p->y = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_wwz(stdmath_double4 v) { return {v.w,v.w,v.z}; }
inline static stdmath_double3 stdmath_double4_wwz_get(stdmath_double4* p) { return stdmath_double4_wwz(*p); }
inline static stdmath_double4 stdmath_double4_wwz_set(stdmath_double4* p, stdmath_double3 value) { p->w = value.x; p->w = value.y; p->z = value.z; return *p; }
inline static stdmath_double3 stdmath_double4_www(stdmath_double4 v) { return {v.w,v.w,v.w}; }
inline static stdmath_double3 stdmath_double4_www_get(stdmath_double4* p) { return stdmath_double4_www(*p); }
inline static stdmath_double4 stdmath_double4_www_set(stdmath_double4* p, stdmath_double3 value) { p->w = value.x; p->w = value.y; p->w = value.z; return *p; }
inline static stdmath_double4 stdmath_double4_xxxx(stdmath_double4 v) { return {v.x,v.x,v.x,v.x}; }
inline static stdmath_double4 stdmath_double4_xxxx_get(stdmath_double4* p) { return stdmath_double4_xxxx(*p); }
inline static stdmath_double4 stdmath_double4_xxxx_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->x = value.y; p->x = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xxxy(stdmath_double4 v) { return {v.x,v.x,v.x,v.y}; }
inline static stdmath_double4 stdmath_double4_xxxy_get(stdmath_double4* p) { return stdmath_double4_xxxy(*p); }
inline static stdmath_double4 stdmath_double4_xxxy_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->x = value.y; p->x = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xxxz(stdmath_double4 v) { return {v.x,v.x,v.x,v.z}; }
inline static stdmath_double4 stdmath_double4_xxxz_get(stdmath_double4* p) { return stdmath_double4_xxxz(*p); }
inline static stdmath_double4 stdmath_double4_xxxz_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->x = value.y; p->x = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xxxw(stdmath_double4 v) { return {v.x,v.x,v.x,v.w}; }
inline static stdmath_double4 stdmath_double4_xxxw_get(stdmath_double4* p) { return stdmath_double4_xxxw(*p); }
inline static stdmath_double4 stdmath_double4_xxxw_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->x = value.y; p->x = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xxyx(stdmath_double4 v) { return {v.x,v.x,v.y,v.x}; }
inline static stdmath_double4 stdmath_double4_xxyx_get(stdmath_double4* p) { return stdmath_double4_xxyx(*p); }
inline static stdmath_double4 stdmath_double4_xxyx_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->x = value.y; p->y = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xxyy(stdmath_double4 v) { return {v.x,v.x,v.y,v.y}; }
inline static stdmath_double4 stdmath_double4_xxyy_get(stdmath_double4* p) { return stdmath_double4_xxyy(*p); }
inline static stdmath_double4 stdmath_double4_xxyy_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->x = value.y; p->y = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xxyz(stdmath_double4 v) { return {v.x,v.x,v.y,v.z}; }
inline static stdmath_double4 stdmath_double4_xxyz_get(stdmath_double4* p) { return stdmath_double4_xxyz(*p); }
inline static stdmath_double4 stdmath_double4_xxyz_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->x = value.y; p->y = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xxyw(stdmath_double4 v) { return {v.x,v.x,v.y,v.w}; }
inline static stdmath_double4 stdmath_double4_xxyw_get(stdmath_double4* p) { return stdmath_double4_xxyw(*p); }
inline static stdmath_double4 stdmath_double4_xxyw_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->x = value.y; p->y = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xxzx(stdmath_double4 v) { return {v.x,v.x,v.z,v.x}; }
inline static stdmath_double4 stdmath_double4_xxzx_get(stdmath_double4* p) { return stdmath_double4_xxzx(*p); }
inline static stdmath_double4 stdmath_double4_xxzx_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->x = value.y; p->z = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xxzy(stdmath_double4 v) { return {v.x,v.x,v.z,v.y}; }
inline static stdmath_double4 stdmath_double4_xxzy_get(stdmath_double4* p) { return stdmath_double4_xxzy(*p); }
inline static stdmath_double4 stdmath_double4_xxzy_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->x = value.y; p->z = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xxzz(stdmath_double4 v) { return {v.x,v.x,v.z,v.z}; }
inline static stdmath_double4 stdmath_double4_xxzz_get(stdmath_double4* p) { return stdmath_double4_xxzz(*p); }
inline static stdmath_double4 stdmath_double4_xxzz_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->x = value.y; p->z = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xxzw(stdmath_double4 v) { return {v.x,v.x,v.z,v.w}; }
inline static stdmath_double4 stdmath_double4_xxzw_get(stdmath_double4* p) { return stdmath_double4_xxzw(*p); }
inline static stdmath_double4 stdmath_double4_xxzw_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->x = value.y; p->z = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xxwx(stdmath_double4 v) { return {v.x,v.x,v.w,v.x}; }
inline static stdmath_double4 stdmath_double4_xxwx_get(stdmath_double4* p) { return stdmath_double4_xxwx(*p); }
inline static stdmath_double4 stdmath_double4_xxwx_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->x = value.y; p->w = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xxwy(stdmath_double4 v) { return {v.x,v.x,v.w,v.y}; }
inline static stdmath_double4 stdmath_double4_xxwy_get(stdmath_double4* p) { return stdmath_double4_xxwy(*p); }
inline static stdmath_double4 stdmath_double4_xxwy_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->x = value.y; p->w = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xxwz(stdmath_double4 v) { return {v.x,v.x,v.w,v.z}; }
inline static stdmath_double4 stdmath_double4_xxwz_get(stdmath_double4* p) { return stdmath_double4_xxwz(*p); }
inline static stdmath_double4 stdmath_double4_xxwz_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->x = value.y; p->w = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xxww(stdmath_double4 v) { return {v.x,v.x,v.w,v.w}; }
inline static stdmath_double4 stdmath_double4_xxww_get(stdmath_double4* p) { return stdmath_double4_xxww(*p); }
inline static stdmath_double4 stdmath_double4_xxww_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->x = value.y; p->w = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xyxx(stdmath_double4 v) { return {v.x,v.y,v.x,v.x}; }
inline static stdmath_double4 stdmath_double4_xyxx_get(stdmath_double4* p) { return stdmath_double4_xyxx(*p); }
inline static stdmath_double4 stdmath_double4_xyxx_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->y = value.y; p->x = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xyxy(stdmath_double4 v) { return {v.x,v.y,v.x,v.y}; }
inline static stdmath_double4 stdmath_double4_xyxy_get(stdmath_double4* p) { return stdmath_double4_xyxy(*p); }
inline static stdmath_double4 stdmath_double4_xyxy_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->y = value.y; p->x = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xyxz(stdmath_double4 v) { return {v.x,v.y,v.x,v.z}; }
inline static stdmath_double4 stdmath_double4_xyxz_get(stdmath_double4* p) { return stdmath_double4_xyxz(*p); }
inline static stdmath_double4 stdmath_double4_xyxz_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->y = value.y; p->x = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xyxw(stdmath_double4 v) { return {v.x,v.y,v.x,v.w}; }
inline static stdmath_double4 stdmath_double4_xyxw_get(stdmath_double4* p) { return stdmath_double4_xyxw(*p); }
inline static stdmath_double4 stdmath_double4_xyxw_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->y = value.y; p->x = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xyyx(stdmath_double4 v) { return {v.x,v.y,v.y,v.x}; }
inline static stdmath_double4 stdmath_double4_xyyx_get(stdmath_double4* p) { return stdmath_double4_xyyx(*p); }
inline static stdmath_double4 stdmath_double4_xyyx_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->y = value.y; p->y = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xyyy(stdmath_double4 v) { return {v.x,v.y,v.y,v.y}; }
inline static stdmath_double4 stdmath_double4_xyyy_get(stdmath_double4* p) { return stdmath_double4_xyyy(*p); }
inline static stdmath_double4 stdmath_double4_xyyy_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->y = value.y; p->y = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xyyz(stdmath_double4 v) { return {v.x,v.y,v.y,v.z}; }
inline static stdmath_double4 stdmath_double4_xyyz_get(stdmath_double4* p) { return stdmath_double4_xyyz(*p); }
inline static stdmath_double4 stdmath_double4_xyyz_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->y = value.y; p->y = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xyyw(stdmath_double4 v) { return {v.x,v.y,v.y,v.w}; }
inline static stdmath_double4 stdmath_double4_xyyw_get(stdmath_double4* p) { return stdmath_double4_xyyw(*p); }
inline static stdmath_double4 stdmath_double4_xyyw_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->y = value.y; p->y = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xyzx(stdmath_double4 v) { return {v.x,v.y,v.z,v.x}; }
inline static stdmath_double4 stdmath_double4_xyzx_get(stdmath_double4* p) { return stdmath_double4_xyzx(*p); }
inline static stdmath_double4 stdmath_double4_xyzx_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->y = value.y; p->z = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xyzy(stdmath_double4 v) { return {v.x,v.y,v.z,v.y}; }
inline static stdmath_double4 stdmath_double4_xyzy_get(stdmath_double4* p) { return stdmath_double4_xyzy(*p); }
inline static stdmath_double4 stdmath_double4_xyzy_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->y = value.y; p->z = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xyzz(stdmath_double4 v) { return {v.x,v.y,v.z,v.z}; }
inline static stdmath_double4 stdmath_double4_xyzz_get(stdmath_double4* p) { return stdmath_double4_xyzz(*p); }
inline static stdmath_double4 stdmath_double4_xyzz_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->y = value.y; p->z = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xyzw(stdmath_double4 v) { return {v.x,v.y,v.z,v.w}; }
inline static stdmath_double4 stdmath_double4_xyzw_get(stdmath_double4* p) { return stdmath_double4_xyzw(*p); }
inline static stdmath_double4 stdmath_double4_xyzw_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->y = value.y; p->z = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xywx(stdmath_double4 v) { return {v.x,v.y,v.w,v.x}; }
inline static stdmath_double4 stdmath_double4_xywx_get(stdmath_double4* p) { return stdmath_double4_xywx(*p); }
inline static stdmath_double4 stdmath_double4_xywx_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->y = value.y; p->w = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xywy(stdmath_double4 v) { return {v.x,v.y,v.w,v.y}; }
inline static stdmath_double4 stdmath_double4_xywy_get(stdmath_double4* p) { return stdmath_double4_xywy(*p); }
inline static stdmath_double4 stdmath_double4_xywy_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->y = value.y; p->w = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xywz(stdmath_double4 v) { return {v.x,v.y,v.w,v.z}; }
inline static stdmath_double4 stdmath_double4_xywz_get(stdmath_double4* p) { return stdmath_double4_xywz(*p); }
inline static stdmath_double4 stdmath_double4_xywz_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->y = value.y; p->w = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xyww(stdmath_double4 v) { return {v.x,v.y,v.w,v.w}; }
inline static stdmath_double4 stdmath_double4_xyww_get(stdmath_double4* p) { return stdmath_double4_xyww(*p); }
inline static stdmath_double4 stdmath_double4_xyww_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->y = value.y; p->w = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xzxx(stdmath_double4 v) { return {v.x,v.z,v.x,v.x}; }
inline static stdmath_double4 stdmath_double4_xzxx_get(stdmath_double4* p) { return stdmath_double4_xzxx(*p); }
inline static stdmath_double4 stdmath_double4_xzxx_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->z = value.y; p->x = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xzxy(stdmath_double4 v) { return {v.x,v.z,v.x,v.y}; }
inline static stdmath_double4 stdmath_double4_xzxy_get(stdmath_double4* p) { return stdmath_double4_xzxy(*p); }
inline static stdmath_double4 stdmath_double4_xzxy_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->z = value.y; p->x = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xzxz(stdmath_double4 v) { return {v.x,v.z,v.x,v.z}; }
inline static stdmath_double4 stdmath_double4_xzxz_get(stdmath_double4* p) { return stdmath_double4_xzxz(*p); }
inline static stdmath_double4 stdmath_double4_xzxz_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->z = value.y; p->x = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xzxw(stdmath_double4 v) { return {v.x,v.z,v.x,v.w}; }
inline static stdmath_double4 stdmath_double4_xzxw_get(stdmath_double4* p) { return stdmath_double4_xzxw(*p); }
inline static stdmath_double4 stdmath_double4_xzxw_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->z = value.y; p->x = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xzyx(stdmath_double4 v) { return {v.x,v.z,v.y,v.x}; }
inline static stdmath_double4 stdmath_double4_xzyx_get(stdmath_double4* p) { return stdmath_double4_xzyx(*p); }
inline static stdmath_double4 stdmath_double4_xzyx_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->z = value.y; p->y = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xzyy(stdmath_double4 v) { return {v.x,v.z,v.y,v.y}; }
inline static stdmath_double4 stdmath_double4_xzyy_get(stdmath_double4* p) { return stdmath_double4_xzyy(*p); }
inline static stdmath_double4 stdmath_double4_xzyy_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->z = value.y; p->y = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xzyz(stdmath_double4 v) { return {v.x,v.z,v.y,v.z}; }
inline static stdmath_double4 stdmath_double4_xzyz_get(stdmath_double4* p) { return stdmath_double4_xzyz(*p); }
inline static stdmath_double4 stdmath_double4_xzyz_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->z = value.y; p->y = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xzyw(stdmath_double4 v) { return {v.x,v.z,v.y,v.w}; }
inline static stdmath_double4 stdmath_double4_xzyw_get(stdmath_double4* p) { return stdmath_double4_xzyw(*p); }
inline static stdmath_double4 stdmath_double4_xzyw_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->z = value.y; p->y = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xzzx(stdmath_double4 v) { return {v.x,v.z,v.z,v.x}; }
inline static stdmath_double4 stdmath_double4_xzzx_get(stdmath_double4* p) { return stdmath_double4_xzzx(*p); }
inline static stdmath_double4 stdmath_double4_xzzx_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->z = value.y; p->z = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xzzy(stdmath_double4 v) { return {v.x,v.z,v.z,v.y}; }
inline static stdmath_double4 stdmath_double4_xzzy_get(stdmath_double4* p) { return stdmath_double4_xzzy(*p); }
inline static stdmath_double4 stdmath_double4_xzzy_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->z = value.y; p->z = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xzzz(stdmath_double4 v) { return {v.x,v.z,v.z,v.z}; }
inline static stdmath_double4 stdmath_double4_xzzz_get(stdmath_double4* p) { return stdmath_double4_xzzz(*p); }
inline static stdmath_double4 stdmath_double4_xzzz_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->z = value.y; p->z = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xzzw(stdmath_double4 v) { return {v.x,v.z,v.z,v.w}; }
inline static stdmath_double4 stdmath_double4_xzzw_get(stdmath_double4* p) { return stdmath_double4_xzzw(*p); }
inline static stdmath_double4 stdmath_double4_xzzw_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->z = value.y; p->z = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xzwx(stdmath_double4 v) { return {v.x,v.z,v.w,v.x}; }
inline static stdmath_double4 stdmath_double4_xzwx_get(stdmath_double4* p) { return stdmath_double4_xzwx(*p); }
inline static stdmath_double4 stdmath_double4_xzwx_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->z = value.y; p->w = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xzwy(stdmath_double4 v) { return {v.x,v.z,v.w,v.y}; }
inline static stdmath_double4 stdmath_double4_xzwy_get(stdmath_double4* p) { return stdmath_double4_xzwy(*p); }
inline static stdmath_double4 stdmath_double4_xzwy_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->z = value.y; p->w = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xzwz(stdmath_double4 v) { return {v.x,v.z,v.w,v.z}; }
inline static stdmath_double4 stdmath_double4_xzwz_get(stdmath_double4* p) { return stdmath_double4_xzwz(*p); }
inline static stdmath_double4 stdmath_double4_xzwz_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->z = value.y; p->w = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xzww(stdmath_double4 v) { return {v.x,v.z,v.w,v.w}; }
inline static stdmath_double4 stdmath_double4_xzww_get(stdmath_double4* p) { return stdmath_double4_xzww(*p); }
inline static stdmath_double4 stdmath_double4_xzww_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->z = value.y; p->w = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xwxx(stdmath_double4 v) { return {v.x,v.w,v.x,v.x}; }
inline static stdmath_double4 stdmath_double4_xwxx_get(stdmath_double4* p) { return stdmath_double4_xwxx(*p); }
inline static stdmath_double4 stdmath_double4_xwxx_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->w = value.y; p->x = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xwxy(stdmath_double4 v) { return {v.x,v.w,v.x,v.y}; }
inline static stdmath_double4 stdmath_double4_xwxy_get(stdmath_double4* p) { return stdmath_double4_xwxy(*p); }
inline static stdmath_double4 stdmath_double4_xwxy_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->w = value.y; p->x = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xwxz(stdmath_double4 v) { return {v.x,v.w,v.x,v.z}; }
inline static stdmath_double4 stdmath_double4_xwxz_get(stdmath_double4* p) { return stdmath_double4_xwxz(*p); }
inline static stdmath_double4 stdmath_double4_xwxz_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->w = value.y; p->x = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xwxw(stdmath_double4 v) { return {v.x,v.w,v.x,v.w}; }
inline static stdmath_double4 stdmath_double4_xwxw_get(stdmath_double4* p) { return stdmath_double4_xwxw(*p); }
inline static stdmath_double4 stdmath_double4_xwxw_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->w = value.y; p->x = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xwyx(stdmath_double4 v) { return {v.x,v.w,v.y,v.x}; }
inline static stdmath_double4 stdmath_double4_xwyx_get(stdmath_double4* p) { return stdmath_double4_xwyx(*p); }
inline static stdmath_double4 stdmath_double4_xwyx_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->w = value.y; p->y = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xwyy(stdmath_double4 v) { return {v.x,v.w,v.y,v.y}; }
inline static stdmath_double4 stdmath_double4_xwyy_get(stdmath_double4* p) { return stdmath_double4_xwyy(*p); }
inline static stdmath_double4 stdmath_double4_xwyy_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->w = value.y; p->y = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xwyz(stdmath_double4 v) { return {v.x,v.w,v.y,v.z}; }
inline static stdmath_double4 stdmath_double4_xwyz_get(stdmath_double4* p) { return stdmath_double4_xwyz(*p); }
inline static stdmath_double4 stdmath_double4_xwyz_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->w = value.y; p->y = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xwyw(stdmath_double4 v) { return {v.x,v.w,v.y,v.w}; }
inline static stdmath_double4 stdmath_double4_xwyw_get(stdmath_double4* p) { return stdmath_double4_xwyw(*p); }
inline static stdmath_double4 stdmath_double4_xwyw_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->w = value.y; p->y = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xwzx(stdmath_double4 v) { return {v.x,v.w,v.z,v.x}; }
inline static stdmath_double4 stdmath_double4_xwzx_get(stdmath_double4* p) { return stdmath_double4_xwzx(*p); }
inline static stdmath_double4 stdmath_double4_xwzx_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->w = value.y; p->z = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xwzy(stdmath_double4 v) { return {v.x,v.w,v.z,v.y}; }
inline static stdmath_double4 stdmath_double4_xwzy_get(stdmath_double4* p) { return stdmath_double4_xwzy(*p); }
inline static stdmath_double4 stdmath_double4_xwzy_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->w = value.y; p->z = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xwzz(stdmath_double4 v) { return {v.x,v.w,v.z,v.z}; }
inline static stdmath_double4 stdmath_double4_xwzz_get(stdmath_double4* p) { return stdmath_double4_xwzz(*p); }
inline static stdmath_double4 stdmath_double4_xwzz_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->w = value.y; p->z = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xwzw(stdmath_double4 v) { return {v.x,v.w,v.z,v.w}; }
inline static stdmath_double4 stdmath_double4_xwzw_get(stdmath_double4* p) { return stdmath_double4_xwzw(*p); }
inline static stdmath_double4 stdmath_double4_xwzw_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->w = value.y; p->z = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xwwx(stdmath_double4 v) { return {v.x,v.w,v.w,v.x}; }
inline static stdmath_double4 stdmath_double4_xwwx_get(stdmath_double4* p) { return stdmath_double4_xwwx(*p); }
inline static stdmath_double4 stdmath_double4_xwwx_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->w = value.y; p->w = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xwwy(stdmath_double4 v) { return {v.x,v.w,v.w,v.y}; }
inline static stdmath_double4 stdmath_double4_xwwy_get(stdmath_double4* p) { return stdmath_double4_xwwy(*p); }
inline static stdmath_double4 stdmath_double4_xwwy_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->w = value.y; p->w = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xwwz(stdmath_double4 v) { return {v.x,v.w,v.w,v.z}; }
inline static stdmath_double4 stdmath_double4_xwwz_get(stdmath_double4* p) { return stdmath_double4_xwwz(*p); }
inline static stdmath_double4 stdmath_double4_xwwz_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->w = value.y; p->w = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_xwww(stdmath_double4 v) { return {v.x,v.w,v.w,v.w}; }
inline static stdmath_double4 stdmath_double4_xwww_get(stdmath_double4* p) { return stdmath_double4_xwww(*p); }
inline static stdmath_double4 stdmath_double4_xwww_set(stdmath_double4* p, stdmath_double4 value) { p->x = value.x; p->w = value.y; p->w = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_yxxx(stdmath_double4 v) { return {v.y,v.x,v.x,v.x}; }
inline static stdmath_double4 stdmath_double4_yxxx_get(stdmath_double4* p) { return stdmath_double4_yxxx(*p); }
inline static stdmath_double4 stdmath_double4_yxxx_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->x = value.y; p->x = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_yxxy(stdmath_double4 v) { return {v.y,v.x,v.x,v.y}; }
inline static stdmath_double4 stdmath_double4_yxxy_get(stdmath_double4* p) { return stdmath_double4_yxxy(*p); }
inline static stdmath_double4 stdmath_double4_yxxy_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->x = value.y; p->x = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_yxxz(stdmath_double4 v) { return {v.y,v.x,v.x,v.z}; }
inline static stdmath_double4 stdmath_double4_yxxz_get(stdmath_double4* p) { return stdmath_double4_yxxz(*p); }
inline static stdmath_double4 stdmath_double4_yxxz_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->x = value.y; p->x = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_yxxw(stdmath_double4 v) { return {v.y,v.x,v.x,v.w}; }
inline static stdmath_double4 stdmath_double4_yxxw_get(stdmath_double4* p) { return stdmath_double4_yxxw(*p); }
inline static stdmath_double4 stdmath_double4_yxxw_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->x = value.y; p->x = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_yxyx(stdmath_double4 v) { return {v.y,v.x,v.y,v.x}; }
inline static stdmath_double4 stdmath_double4_yxyx_get(stdmath_double4* p) { return stdmath_double4_yxyx(*p); }
inline static stdmath_double4 stdmath_double4_yxyx_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->x = value.y; p->y = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_yxyy(stdmath_double4 v) { return {v.y,v.x,v.y,v.y}; }
inline static stdmath_double4 stdmath_double4_yxyy_get(stdmath_double4* p) { return stdmath_double4_yxyy(*p); }
inline static stdmath_double4 stdmath_double4_yxyy_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->x = value.y; p->y = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_yxyz(stdmath_double4 v) { return {v.y,v.x,v.y,v.z}; }
inline static stdmath_double4 stdmath_double4_yxyz_get(stdmath_double4* p) { return stdmath_double4_yxyz(*p); }
inline static stdmath_double4 stdmath_double4_yxyz_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->x = value.y; p->y = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_yxyw(stdmath_double4 v) { return {v.y,v.x,v.y,v.w}; }
inline static stdmath_double4 stdmath_double4_yxyw_get(stdmath_double4* p) { return stdmath_double4_yxyw(*p); }
inline static stdmath_double4 stdmath_double4_yxyw_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->x = value.y; p->y = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_yxzx(stdmath_double4 v) { return {v.y,v.x,v.z,v.x}; }
inline static stdmath_double4 stdmath_double4_yxzx_get(stdmath_double4* p) { return stdmath_double4_yxzx(*p); }
inline static stdmath_double4 stdmath_double4_yxzx_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->x = value.y; p->z = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_yxzy(stdmath_double4 v) { return {v.y,v.x,v.z,v.y}; }
inline static stdmath_double4 stdmath_double4_yxzy_get(stdmath_double4* p) { return stdmath_double4_yxzy(*p); }
inline static stdmath_double4 stdmath_double4_yxzy_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->x = value.y; p->z = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_yxzz(stdmath_double4 v) { return {v.y,v.x,v.z,v.z}; }
inline static stdmath_double4 stdmath_double4_yxzz_get(stdmath_double4* p) { return stdmath_double4_yxzz(*p); }
inline static stdmath_double4 stdmath_double4_yxzz_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->x = value.y; p->z = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_yxzw(stdmath_double4 v) { return {v.y,v.x,v.z,v.w}; }
inline static stdmath_double4 stdmath_double4_yxzw_get(stdmath_double4* p) { return stdmath_double4_yxzw(*p); }
inline static stdmath_double4 stdmath_double4_yxzw_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->x = value.y; p->z = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_yxwx(stdmath_double4 v) { return {v.y,v.x,v.w,v.x}; }
inline static stdmath_double4 stdmath_double4_yxwx_get(stdmath_double4* p) { return stdmath_double4_yxwx(*p); }
inline static stdmath_double4 stdmath_double4_yxwx_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->x = value.y; p->w = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_yxwy(stdmath_double4 v) { return {v.y,v.x,v.w,v.y}; }
inline static stdmath_double4 stdmath_double4_yxwy_get(stdmath_double4* p) { return stdmath_double4_yxwy(*p); }
inline static stdmath_double4 stdmath_double4_yxwy_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->x = value.y; p->w = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_yxwz(stdmath_double4 v) { return {v.y,v.x,v.w,v.z}; }
inline static stdmath_double4 stdmath_double4_yxwz_get(stdmath_double4* p) { return stdmath_double4_yxwz(*p); }
inline static stdmath_double4 stdmath_double4_yxwz_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->x = value.y; p->w = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_yxww(stdmath_double4 v) { return {v.y,v.x,v.w,v.w}; }
inline static stdmath_double4 stdmath_double4_yxww_get(stdmath_double4* p) { return stdmath_double4_yxww(*p); }
inline static stdmath_double4 stdmath_double4_yxww_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->x = value.y; p->w = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_yyxx(stdmath_double4 v) { return {v.y,v.y,v.x,v.x}; }
inline static stdmath_double4 stdmath_double4_yyxx_get(stdmath_double4* p) { return stdmath_double4_yyxx(*p); }
inline static stdmath_double4 stdmath_double4_yyxx_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->y = value.y; p->x = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_yyxy(stdmath_double4 v) { return {v.y,v.y,v.x,v.y}; }
inline static stdmath_double4 stdmath_double4_yyxy_get(stdmath_double4* p) { return stdmath_double4_yyxy(*p); }
inline static stdmath_double4 stdmath_double4_yyxy_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->y = value.y; p->x = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_yyxz(stdmath_double4 v) { return {v.y,v.y,v.x,v.z}; }
inline static stdmath_double4 stdmath_double4_yyxz_get(stdmath_double4* p) { return stdmath_double4_yyxz(*p); }
inline static stdmath_double4 stdmath_double4_yyxz_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->y = value.y; p->x = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_yyxw(stdmath_double4 v) { return {v.y,v.y,v.x,v.w}; }
inline static stdmath_double4 stdmath_double4_yyxw_get(stdmath_double4* p) { return stdmath_double4_yyxw(*p); }
inline static stdmath_double4 stdmath_double4_yyxw_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->y = value.y; p->x = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_yyyx(stdmath_double4 v) { return {v.y,v.y,v.y,v.x}; }
inline static stdmath_double4 stdmath_double4_yyyx_get(stdmath_double4* p) { return stdmath_double4_yyyx(*p); }
inline static stdmath_double4 stdmath_double4_yyyx_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->y = value.y; p->y = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_yyyy(stdmath_double4 v) { return {v.y,v.y,v.y,v.y}; }
inline static stdmath_double4 stdmath_double4_yyyy_get(stdmath_double4* p) { return stdmath_double4_yyyy(*p); }
inline static stdmath_double4 stdmath_double4_yyyy_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->y = value.y; p->y = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_yyyz(stdmath_double4 v) { return {v.y,v.y,v.y,v.z}; }
inline static stdmath_double4 stdmath_double4_yyyz_get(stdmath_double4* p) { return stdmath_double4_yyyz(*p); }
inline static stdmath_double4 stdmath_double4_yyyz_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->y = value.y; p->y = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_yyyw(stdmath_double4 v) { return {v.y,v.y,v.y,v.w}; }
inline static stdmath_double4 stdmath_double4_yyyw_get(stdmath_double4* p) { return stdmath_double4_yyyw(*p); }
inline static stdmath_double4 stdmath_double4_yyyw_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->y = value.y; p->y = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_yyzx(stdmath_double4 v) { return {v.y,v.y,v.z,v.x}; }
inline static stdmath_double4 stdmath_double4_yyzx_get(stdmath_double4* p) { return stdmath_double4_yyzx(*p); }
inline static stdmath_double4 stdmath_double4_yyzx_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->y = value.y; p->z = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_yyzy(stdmath_double4 v) { return {v.y,v.y,v.z,v.y}; }
inline static stdmath_double4 stdmath_double4_yyzy_get(stdmath_double4* p) { return stdmath_double4_yyzy(*p); }
inline static stdmath_double4 stdmath_double4_yyzy_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->y = value.y; p->z = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_yyzz(stdmath_double4 v) { return {v.y,v.y,v.z,v.z}; }
inline static stdmath_double4 stdmath_double4_yyzz_get(stdmath_double4* p) { return stdmath_double4_yyzz(*p); }
inline static stdmath_double4 stdmath_double4_yyzz_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->y = value.y; p->z = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_yyzw(stdmath_double4 v) { return {v.y,v.y,v.z,v.w}; }
inline static stdmath_double4 stdmath_double4_yyzw_get(stdmath_double4* p) { return stdmath_double4_yyzw(*p); }
inline static stdmath_double4 stdmath_double4_yyzw_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->y = value.y; p->z = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_yywx(stdmath_double4 v) { return {v.y,v.y,v.w,v.x}; }
inline static stdmath_double4 stdmath_double4_yywx_get(stdmath_double4* p) { return stdmath_double4_yywx(*p); }
inline static stdmath_double4 stdmath_double4_yywx_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->y = value.y; p->w = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_yywy(stdmath_double4 v) { return {v.y,v.y,v.w,v.y}; }
inline static stdmath_double4 stdmath_double4_yywy_get(stdmath_double4* p) { return stdmath_double4_yywy(*p); }
inline static stdmath_double4 stdmath_double4_yywy_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->y = value.y; p->w = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_yywz(stdmath_double4 v) { return {v.y,v.y,v.w,v.z}; }
inline static stdmath_double4 stdmath_double4_yywz_get(stdmath_double4* p) { return stdmath_double4_yywz(*p); }
inline static stdmath_double4 stdmath_double4_yywz_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->y = value.y; p->w = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_yyww(stdmath_double4 v) { return {v.y,v.y,v.w,v.w}; }
inline static stdmath_double4 stdmath_double4_yyww_get(stdmath_double4* p) { return stdmath_double4_yyww(*p); }
inline static stdmath_double4 stdmath_double4_yyww_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->y = value.y; p->w = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_yzxx(stdmath_double4 v) { return {v.y,v.z,v.x,v.x}; }
inline static stdmath_double4 stdmath_double4_yzxx_get(stdmath_double4* p) { return stdmath_double4_yzxx(*p); }
inline static stdmath_double4 stdmath_double4_yzxx_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->z = value.y; p->x = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_yzxy(stdmath_double4 v) { return {v.y,v.z,v.x,v.y}; }
inline static stdmath_double4 stdmath_double4_yzxy_get(stdmath_double4* p) { return stdmath_double4_yzxy(*p); }
inline static stdmath_double4 stdmath_double4_yzxy_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->z = value.y; p->x = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_yzxz(stdmath_double4 v) { return {v.y,v.z,v.x,v.z}; }
inline static stdmath_double4 stdmath_double4_yzxz_get(stdmath_double4* p) { return stdmath_double4_yzxz(*p); }
inline static stdmath_double4 stdmath_double4_yzxz_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->z = value.y; p->x = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_yzxw(stdmath_double4 v) { return {v.y,v.z,v.x,v.w}; }
inline static stdmath_double4 stdmath_double4_yzxw_get(stdmath_double4* p) { return stdmath_double4_yzxw(*p); }
inline static stdmath_double4 stdmath_double4_yzxw_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->z = value.y; p->x = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_yzyx(stdmath_double4 v) { return {v.y,v.z,v.y,v.x}; }
inline static stdmath_double4 stdmath_double4_yzyx_get(stdmath_double4* p) { return stdmath_double4_yzyx(*p); }
inline static stdmath_double4 stdmath_double4_yzyx_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->z = value.y; p->y = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_yzyy(stdmath_double4 v) { return {v.y,v.z,v.y,v.y}; }
inline static stdmath_double4 stdmath_double4_yzyy_get(stdmath_double4* p) { return stdmath_double4_yzyy(*p); }
inline static stdmath_double4 stdmath_double4_yzyy_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->z = value.y; p->y = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_yzyz(stdmath_double4 v) { return {v.y,v.z,v.y,v.z}; }
inline static stdmath_double4 stdmath_double4_yzyz_get(stdmath_double4* p) { return stdmath_double4_yzyz(*p); }
inline static stdmath_double4 stdmath_double4_yzyz_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->z = value.y; p->y = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_yzyw(stdmath_double4 v) { return {v.y,v.z,v.y,v.w}; }
inline static stdmath_double4 stdmath_double4_yzyw_get(stdmath_double4* p) { return stdmath_double4_yzyw(*p); }
inline static stdmath_double4 stdmath_double4_yzyw_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->z = value.y; p->y = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_yzzx(stdmath_double4 v) { return {v.y,v.z,v.z,v.x}; }
inline static stdmath_double4 stdmath_double4_yzzx_get(stdmath_double4* p) { return stdmath_double4_yzzx(*p); }
inline static stdmath_double4 stdmath_double4_yzzx_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->z = value.y; p->z = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_yzzy(stdmath_double4 v) { return {v.y,v.z,v.z,v.y}; }
inline static stdmath_double4 stdmath_double4_yzzy_get(stdmath_double4* p) { return stdmath_double4_yzzy(*p); }
inline static stdmath_double4 stdmath_double4_yzzy_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->z = value.y; p->z = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_yzzz(stdmath_double4 v) { return {v.y,v.z,v.z,v.z}; }
inline static stdmath_double4 stdmath_double4_yzzz_get(stdmath_double4* p) { return stdmath_double4_yzzz(*p); }
inline static stdmath_double4 stdmath_double4_yzzz_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->z = value.y; p->z = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_yzzw(stdmath_double4 v) { return {v.y,v.z,v.z,v.w}; }
inline static stdmath_double4 stdmath_double4_yzzw_get(stdmath_double4* p) { return stdmath_double4_yzzw(*p); }
inline static stdmath_double4 stdmath_double4_yzzw_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->z = value.y; p->z = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_yzwx(stdmath_double4 v) { return {v.y,v.z,v.w,v.x}; }
inline static stdmath_double4 stdmath_double4_yzwx_get(stdmath_double4* p) { return stdmath_double4_yzwx(*p); }
inline static stdmath_double4 stdmath_double4_yzwx_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->z = value.y; p->w = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_yzwy(stdmath_double4 v) { return {v.y,v.z,v.w,v.y}; }
inline static stdmath_double4 stdmath_double4_yzwy_get(stdmath_double4* p) { return stdmath_double4_yzwy(*p); }
inline static stdmath_double4 stdmath_double4_yzwy_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->z = value.y; p->w = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_yzwz(stdmath_double4 v) { return {v.y,v.z,v.w,v.z}; }
inline static stdmath_double4 stdmath_double4_yzwz_get(stdmath_double4* p) { return stdmath_double4_yzwz(*p); }
inline static stdmath_double4 stdmath_double4_yzwz_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->z = value.y; p->w = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_yzww(stdmath_double4 v) { return {v.y,v.z,v.w,v.w}; }
inline static stdmath_double4 stdmath_double4_yzww_get(stdmath_double4* p) { return stdmath_double4_yzww(*p); }
inline static stdmath_double4 stdmath_double4_yzww_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->z = value.y; p->w = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_ywxx(stdmath_double4 v) { return {v.y,v.w,v.x,v.x}; }
inline static stdmath_double4 stdmath_double4_ywxx_get(stdmath_double4* p) { return stdmath_double4_ywxx(*p); }
inline static stdmath_double4 stdmath_double4_ywxx_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->w = value.y; p->x = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_ywxy(stdmath_double4 v) { return {v.y,v.w,v.x,v.y}; }
inline static stdmath_double4 stdmath_double4_ywxy_get(stdmath_double4* p) { return stdmath_double4_ywxy(*p); }
inline static stdmath_double4 stdmath_double4_ywxy_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->w = value.y; p->x = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_ywxz(stdmath_double4 v) { return {v.y,v.w,v.x,v.z}; }
inline static stdmath_double4 stdmath_double4_ywxz_get(stdmath_double4* p) { return stdmath_double4_ywxz(*p); }
inline static stdmath_double4 stdmath_double4_ywxz_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->w = value.y; p->x = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_ywxw(stdmath_double4 v) { return {v.y,v.w,v.x,v.w}; }
inline static stdmath_double4 stdmath_double4_ywxw_get(stdmath_double4* p) { return stdmath_double4_ywxw(*p); }
inline static stdmath_double4 stdmath_double4_ywxw_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->w = value.y; p->x = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_ywyx(stdmath_double4 v) { return {v.y,v.w,v.y,v.x}; }
inline static stdmath_double4 stdmath_double4_ywyx_get(stdmath_double4* p) { return stdmath_double4_ywyx(*p); }
inline static stdmath_double4 stdmath_double4_ywyx_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->w = value.y; p->y = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_ywyy(stdmath_double4 v) { return {v.y,v.w,v.y,v.y}; }
inline static stdmath_double4 stdmath_double4_ywyy_get(stdmath_double4* p) { return stdmath_double4_ywyy(*p); }
inline static stdmath_double4 stdmath_double4_ywyy_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->w = value.y; p->y = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_ywyz(stdmath_double4 v) { return {v.y,v.w,v.y,v.z}; }
inline static stdmath_double4 stdmath_double4_ywyz_get(stdmath_double4* p) { return stdmath_double4_ywyz(*p); }
inline static stdmath_double4 stdmath_double4_ywyz_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->w = value.y; p->y = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_ywyw(stdmath_double4 v) { return {v.y,v.w,v.y,v.w}; }
inline static stdmath_double4 stdmath_double4_ywyw_get(stdmath_double4* p) { return stdmath_double4_ywyw(*p); }
inline static stdmath_double4 stdmath_double4_ywyw_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->w = value.y; p->y = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_ywzx(stdmath_double4 v) { return {v.y,v.w,v.z,v.x}; }
inline static stdmath_double4 stdmath_double4_ywzx_get(stdmath_double4* p) { return stdmath_double4_ywzx(*p); }
inline static stdmath_double4 stdmath_double4_ywzx_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->w = value.y; p->z = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_ywzy(stdmath_double4 v) { return {v.y,v.w,v.z,v.y}; }
inline static stdmath_double4 stdmath_double4_ywzy_get(stdmath_double4* p) { return stdmath_double4_ywzy(*p); }
inline static stdmath_double4 stdmath_double4_ywzy_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->w = value.y; p->z = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_ywzz(stdmath_double4 v) { return {v.y,v.w,v.z,v.z}; }
inline static stdmath_double4 stdmath_double4_ywzz_get(stdmath_double4* p) { return stdmath_double4_ywzz(*p); }
inline static stdmath_double4 stdmath_double4_ywzz_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->w = value.y; p->z = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_ywzw(stdmath_double4 v) { return {v.y,v.w,v.z,v.w}; }
inline static stdmath_double4 stdmath_double4_ywzw_get(stdmath_double4* p) { return stdmath_double4_ywzw(*p); }
inline static stdmath_double4 stdmath_double4_ywzw_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->w = value.y; p->z = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_ywwx(stdmath_double4 v) { return {v.y,v.w,v.w,v.x}; }
inline static stdmath_double4 stdmath_double4_ywwx_get(stdmath_double4* p) { return stdmath_double4_ywwx(*p); }
inline static stdmath_double4 stdmath_double4_ywwx_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->w = value.y; p->w = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_ywwy(stdmath_double4 v) { return {v.y,v.w,v.w,v.y}; }
inline static stdmath_double4 stdmath_double4_ywwy_get(stdmath_double4* p) { return stdmath_double4_ywwy(*p); }
inline static stdmath_double4 stdmath_double4_ywwy_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->w = value.y; p->w = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_ywwz(stdmath_double4 v) { return {v.y,v.w,v.w,v.z}; }
inline static stdmath_double4 stdmath_double4_ywwz_get(stdmath_double4* p) { return stdmath_double4_ywwz(*p); }
inline static stdmath_double4 stdmath_double4_ywwz_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->w = value.y; p->w = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_ywww(stdmath_double4 v) { return {v.y,v.w,v.w,v.w}; }
inline static stdmath_double4 stdmath_double4_ywww_get(stdmath_double4* p) { return stdmath_double4_ywww(*p); }
inline static stdmath_double4 stdmath_double4_ywww_set(stdmath_double4* p, stdmath_double4 value) { p->y = value.x; p->w = value.y; p->w = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zxxx(stdmath_double4 v) { return {v.z,v.x,v.x,v.x}; }
inline static stdmath_double4 stdmath_double4_zxxx_get(stdmath_double4* p) { return stdmath_double4_zxxx(*p); }
inline static stdmath_double4 stdmath_double4_zxxx_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->x = value.y; p->x = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zxxy(stdmath_double4 v) { return {v.z,v.x,v.x,v.y}; }
inline static stdmath_double4 stdmath_double4_zxxy_get(stdmath_double4* p) { return stdmath_double4_zxxy(*p); }
inline static stdmath_double4 stdmath_double4_zxxy_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->x = value.y; p->x = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zxxz(stdmath_double4 v) { return {v.z,v.x,v.x,v.z}; }
inline static stdmath_double4 stdmath_double4_zxxz_get(stdmath_double4* p) { return stdmath_double4_zxxz(*p); }
inline static stdmath_double4 stdmath_double4_zxxz_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->x = value.y; p->x = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zxxw(stdmath_double4 v) { return {v.z,v.x,v.x,v.w}; }
inline static stdmath_double4 stdmath_double4_zxxw_get(stdmath_double4* p) { return stdmath_double4_zxxw(*p); }
inline static stdmath_double4 stdmath_double4_zxxw_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->x = value.y; p->x = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zxyx(stdmath_double4 v) { return {v.z,v.x,v.y,v.x}; }
inline static stdmath_double4 stdmath_double4_zxyx_get(stdmath_double4* p) { return stdmath_double4_zxyx(*p); }
inline static stdmath_double4 stdmath_double4_zxyx_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->x = value.y; p->y = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zxyy(stdmath_double4 v) { return {v.z,v.x,v.y,v.y}; }
inline static stdmath_double4 stdmath_double4_zxyy_get(stdmath_double4* p) { return stdmath_double4_zxyy(*p); }
inline static stdmath_double4 stdmath_double4_zxyy_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->x = value.y; p->y = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zxyz(stdmath_double4 v) { return {v.z,v.x,v.y,v.z}; }
inline static stdmath_double4 stdmath_double4_zxyz_get(stdmath_double4* p) { return stdmath_double4_zxyz(*p); }
inline static stdmath_double4 stdmath_double4_zxyz_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->x = value.y; p->y = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zxyw(stdmath_double4 v) { return {v.z,v.x,v.y,v.w}; }
inline static stdmath_double4 stdmath_double4_zxyw_get(stdmath_double4* p) { return stdmath_double4_zxyw(*p); }
inline static stdmath_double4 stdmath_double4_zxyw_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->x = value.y; p->y = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zxzx(stdmath_double4 v) { return {v.z,v.x,v.z,v.x}; }
inline static stdmath_double4 stdmath_double4_zxzx_get(stdmath_double4* p) { return stdmath_double4_zxzx(*p); }
inline static stdmath_double4 stdmath_double4_zxzx_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->x = value.y; p->z = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zxzy(stdmath_double4 v) { return {v.z,v.x,v.z,v.y}; }
inline static stdmath_double4 stdmath_double4_zxzy_get(stdmath_double4* p) { return stdmath_double4_zxzy(*p); }
inline static stdmath_double4 stdmath_double4_zxzy_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->x = value.y; p->z = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zxzz(stdmath_double4 v) { return {v.z,v.x,v.z,v.z}; }
inline static stdmath_double4 stdmath_double4_zxzz_get(stdmath_double4* p) { return stdmath_double4_zxzz(*p); }
inline static stdmath_double4 stdmath_double4_zxzz_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->x = value.y; p->z = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zxzw(stdmath_double4 v) { return {v.z,v.x,v.z,v.w}; }
inline static stdmath_double4 stdmath_double4_zxzw_get(stdmath_double4* p) { return stdmath_double4_zxzw(*p); }
inline static stdmath_double4 stdmath_double4_zxzw_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->x = value.y; p->z = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zxwx(stdmath_double4 v) { return {v.z,v.x,v.w,v.x}; }
inline static stdmath_double4 stdmath_double4_zxwx_get(stdmath_double4* p) { return stdmath_double4_zxwx(*p); }
inline static stdmath_double4 stdmath_double4_zxwx_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->x = value.y; p->w = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zxwy(stdmath_double4 v) { return {v.z,v.x,v.w,v.y}; }
inline static stdmath_double4 stdmath_double4_zxwy_get(stdmath_double4* p) { return stdmath_double4_zxwy(*p); }
inline static stdmath_double4 stdmath_double4_zxwy_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->x = value.y; p->w = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zxwz(stdmath_double4 v) { return {v.z,v.x,v.w,v.z}; }
inline static stdmath_double4 stdmath_double4_zxwz_get(stdmath_double4* p) { return stdmath_double4_zxwz(*p); }
inline static stdmath_double4 stdmath_double4_zxwz_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->x = value.y; p->w = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zxww(stdmath_double4 v) { return {v.z,v.x,v.w,v.w}; }
inline static stdmath_double4 stdmath_double4_zxww_get(stdmath_double4* p) { return stdmath_double4_zxww(*p); }
inline static stdmath_double4 stdmath_double4_zxww_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->x = value.y; p->w = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zyxx(stdmath_double4 v) { return {v.z,v.y,v.x,v.x}; }
inline static stdmath_double4 stdmath_double4_zyxx_get(stdmath_double4* p) { return stdmath_double4_zyxx(*p); }
inline static stdmath_double4 stdmath_double4_zyxx_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->y = value.y; p->x = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zyxy(stdmath_double4 v) { return {v.z,v.y,v.x,v.y}; }
inline static stdmath_double4 stdmath_double4_zyxy_get(stdmath_double4* p) { return stdmath_double4_zyxy(*p); }
inline static stdmath_double4 stdmath_double4_zyxy_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->y = value.y; p->x = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zyxz(stdmath_double4 v) { return {v.z,v.y,v.x,v.z}; }
inline static stdmath_double4 stdmath_double4_zyxz_get(stdmath_double4* p) { return stdmath_double4_zyxz(*p); }
inline static stdmath_double4 stdmath_double4_zyxz_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->y = value.y; p->x = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zyxw(stdmath_double4 v) { return {v.z,v.y,v.x,v.w}; }
inline static stdmath_double4 stdmath_double4_zyxw_get(stdmath_double4* p) { return stdmath_double4_zyxw(*p); }
inline static stdmath_double4 stdmath_double4_zyxw_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->y = value.y; p->x = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zyyx(stdmath_double4 v) { return {v.z,v.y,v.y,v.x}; }
inline static stdmath_double4 stdmath_double4_zyyx_get(stdmath_double4* p) { return stdmath_double4_zyyx(*p); }
inline static stdmath_double4 stdmath_double4_zyyx_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->y = value.y; p->y = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zyyy(stdmath_double4 v) { return {v.z,v.y,v.y,v.y}; }
inline static stdmath_double4 stdmath_double4_zyyy_get(stdmath_double4* p) { return stdmath_double4_zyyy(*p); }
inline static stdmath_double4 stdmath_double4_zyyy_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->y = value.y; p->y = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zyyz(stdmath_double4 v) { return {v.z,v.y,v.y,v.z}; }
inline static stdmath_double4 stdmath_double4_zyyz_get(stdmath_double4* p) { return stdmath_double4_zyyz(*p); }
inline static stdmath_double4 stdmath_double4_zyyz_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->y = value.y; p->y = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zyyw(stdmath_double4 v) { return {v.z,v.y,v.y,v.w}; }
inline static stdmath_double4 stdmath_double4_zyyw_get(stdmath_double4* p) { return stdmath_double4_zyyw(*p); }
inline static stdmath_double4 stdmath_double4_zyyw_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->y = value.y; p->y = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zyzx(stdmath_double4 v) { return {v.z,v.y,v.z,v.x}; }
inline static stdmath_double4 stdmath_double4_zyzx_get(stdmath_double4* p) { return stdmath_double4_zyzx(*p); }
inline static stdmath_double4 stdmath_double4_zyzx_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->y = value.y; p->z = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zyzy(stdmath_double4 v) { return {v.z,v.y,v.z,v.y}; }
inline static stdmath_double4 stdmath_double4_zyzy_get(stdmath_double4* p) { return stdmath_double4_zyzy(*p); }
inline static stdmath_double4 stdmath_double4_zyzy_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->y = value.y; p->z = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zyzz(stdmath_double4 v) { return {v.z,v.y,v.z,v.z}; }
inline static stdmath_double4 stdmath_double4_zyzz_get(stdmath_double4* p) { return stdmath_double4_zyzz(*p); }
inline static stdmath_double4 stdmath_double4_zyzz_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->y = value.y; p->z = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zyzw(stdmath_double4 v) { return {v.z,v.y,v.z,v.w}; }
inline static stdmath_double4 stdmath_double4_zyzw_get(stdmath_double4* p) { return stdmath_double4_zyzw(*p); }
inline static stdmath_double4 stdmath_double4_zyzw_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->y = value.y; p->z = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zywx(stdmath_double4 v) { return {v.z,v.y,v.w,v.x}; }
inline static stdmath_double4 stdmath_double4_zywx_get(stdmath_double4* p) { return stdmath_double4_zywx(*p); }
inline static stdmath_double4 stdmath_double4_zywx_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->y = value.y; p->w = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zywy(stdmath_double4 v) { return {v.z,v.y,v.w,v.y}; }
inline static stdmath_double4 stdmath_double4_zywy_get(stdmath_double4* p) { return stdmath_double4_zywy(*p); }
inline static stdmath_double4 stdmath_double4_zywy_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->y = value.y; p->w = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zywz(stdmath_double4 v) { return {v.z,v.y,v.w,v.z}; }
inline static stdmath_double4 stdmath_double4_zywz_get(stdmath_double4* p) { return stdmath_double4_zywz(*p); }
inline static stdmath_double4 stdmath_double4_zywz_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->y = value.y; p->w = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zyww(stdmath_double4 v) { return {v.z,v.y,v.w,v.w}; }
inline static stdmath_double4 stdmath_double4_zyww_get(stdmath_double4* p) { return stdmath_double4_zyww(*p); }
inline static stdmath_double4 stdmath_double4_zyww_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->y = value.y; p->w = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zzxx(stdmath_double4 v) { return {v.z,v.z,v.x,v.x}; }
inline static stdmath_double4 stdmath_double4_zzxx_get(stdmath_double4* p) { return stdmath_double4_zzxx(*p); }
inline static stdmath_double4 stdmath_double4_zzxx_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->z = value.y; p->x = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zzxy(stdmath_double4 v) { return {v.z,v.z,v.x,v.y}; }
inline static stdmath_double4 stdmath_double4_zzxy_get(stdmath_double4* p) { return stdmath_double4_zzxy(*p); }
inline static stdmath_double4 stdmath_double4_zzxy_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->z = value.y; p->x = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zzxz(stdmath_double4 v) { return {v.z,v.z,v.x,v.z}; }
inline static stdmath_double4 stdmath_double4_zzxz_get(stdmath_double4* p) { return stdmath_double4_zzxz(*p); }
inline static stdmath_double4 stdmath_double4_zzxz_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->z = value.y; p->x = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zzxw(stdmath_double4 v) { return {v.z,v.z,v.x,v.w}; }
inline static stdmath_double4 stdmath_double4_zzxw_get(stdmath_double4* p) { return stdmath_double4_zzxw(*p); }
inline static stdmath_double4 stdmath_double4_zzxw_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->z = value.y; p->x = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zzyx(stdmath_double4 v) { return {v.z,v.z,v.y,v.x}; }
inline static stdmath_double4 stdmath_double4_zzyx_get(stdmath_double4* p) { return stdmath_double4_zzyx(*p); }
inline static stdmath_double4 stdmath_double4_zzyx_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->z = value.y; p->y = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zzyy(stdmath_double4 v) { return {v.z,v.z,v.y,v.y}; }
inline static stdmath_double4 stdmath_double4_zzyy_get(stdmath_double4* p) { return stdmath_double4_zzyy(*p); }
inline static stdmath_double4 stdmath_double4_zzyy_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->z = value.y; p->y = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zzyz(stdmath_double4 v) { return {v.z,v.z,v.y,v.z}; }
inline static stdmath_double4 stdmath_double4_zzyz_get(stdmath_double4* p) { return stdmath_double4_zzyz(*p); }
inline static stdmath_double4 stdmath_double4_zzyz_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->z = value.y; p->y = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zzyw(stdmath_double4 v) { return {v.z,v.z,v.y,v.w}; }
inline static stdmath_double4 stdmath_double4_zzyw_get(stdmath_double4* p) { return stdmath_double4_zzyw(*p); }
inline static stdmath_double4 stdmath_double4_zzyw_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->z = value.y; p->y = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zzzx(stdmath_double4 v) { return {v.z,v.z,v.z,v.x}; }
inline static stdmath_double4 stdmath_double4_zzzx_get(stdmath_double4* p) { return stdmath_double4_zzzx(*p); }
inline static stdmath_double4 stdmath_double4_zzzx_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->z = value.y; p->z = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zzzy(stdmath_double4 v) { return {v.z,v.z,v.z,v.y}; }
inline static stdmath_double4 stdmath_double4_zzzy_get(stdmath_double4* p) { return stdmath_double4_zzzy(*p); }
inline static stdmath_double4 stdmath_double4_zzzy_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->z = value.y; p->z = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zzzz(stdmath_double4 v) { return {v.z,v.z,v.z,v.z}; }
inline static stdmath_double4 stdmath_double4_zzzz_get(stdmath_double4* p) { return stdmath_double4_zzzz(*p); }
inline static stdmath_double4 stdmath_double4_zzzz_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->z = value.y; p->z = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zzzw(stdmath_double4 v) { return {v.z,v.z,v.z,v.w}; }
inline static stdmath_double4 stdmath_double4_zzzw_get(stdmath_double4* p) { return stdmath_double4_zzzw(*p); }
inline static stdmath_double4 stdmath_double4_zzzw_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->z = value.y; p->z = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zzwx(stdmath_double4 v) { return {v.z,v.z,v.w,v.x}; }
inline static stdmath_double4 stdmath_double4_zzwx_get(stdmath_double4* p) { return stdmath_double4_zzwx(*p); }
inline static stdmath_double4 stdmath_double4_zzwx_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->z = value.y; p->w = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zzwy(stdmath_double4 v) { return {v.z,v.z,v.w,v.y}; }
inline static stdmath_double4 stdmath_double4_zzwy_get(stdmath_double4* p) { return stdmath_double4_zzwy(*p); }
inline static stdmath_double4 stdmath_double4_zzwy_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->z = value.y; p->w = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zzwz(stdmath_double4 v) { return {v.z,v.z,v.w,v.z}; }
inline static stdmath_double4 stdmath_double4_zzwz_get(stdmath_double4* p) { return stdmath_double4_zzwz(*p); }
inline static stdmath_double4 stdmath_double4_zzwz_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->z = value.y; p->w = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zzww(stdmath_double4 v) { return {v.z,v.z,v.w,v.w}; }
inline static stdmath_double4 stdmath_double4_zzww_get(stdmath_double4* p) { return stdmath_double4_zzww(*p); }
inline static stdmath_double4 stdmath_double4_zzww_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->z = value.y; p->w = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zwxx(stdmath_double4 v) { return {v.z,v.w,v.x,v.x}; }
inline static stdmath_double4 stdmath_double4_zwxx_get(stdmath_double4* p) { return stdmath_double4_zwxx(*p); }
inline static stdmath_double4 stdmath_double4_zwxx_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->w = value.y; p->x = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zwxy(stdmath_double4 v) { return {v.z,v.w,v.x,v.y}; }
inline static stdmath_double4 stdmath_double4_zwxy_get(stdmath_double4* p) { return stdmath_double4_zwxy(*p); }
inline static stdmath_double4 stdmath_double4_zwxy_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->w = value.y; p->x = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zwxz(stdmath_double4 v) { return {v.z,v.w,v.x,v.z}; }
inline static stdmath_double4 stdmath_double4_zwxz_get(stdmath_double4* p) { return stdmath_double4_zwxz(*p); }
inline static stdmath_double4 stdmath_double4_zwxz_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->w = value.y; p->x = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zwxw(stdmath_double4 v) { return {v.z,v.w,v.x,v.w}; }
inline static stdmath_double4 stdmath_double4_zwxw_get(stdmath_double4* p) { return stdmath_double4_zwxw(*p); }
inline static stdmath_double4 stdmath_double4_zwxw_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->w = value.y; p->x = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zwyx(stdmath_double4 v) { return {v.z,v.w,v.y,v.x}; }
inline static stdmath_double4 stdmath_double4_zwyx_get(stdmath_double4* p) { return stdmath_double4_zwyx(*p); }
inline static stdmath_double4 stdmath_double4_zwyx_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->w = value.y; p->y = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zwyy(stdmath_double4 v) { return {v.z,v.w,v.y,v.y}; }
inline static stdmath_double4 stdmath_double4_zwyy_get(stdmath_double4* p) { return stdmath_double4_zwyy(*p); }
inline static stdmath_double4 stdmath_double4_zwyy_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->w = value.y; p->y = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zwyz(stdmath_double4 v) { return {v.z,v.w,v.y,v.z}; }
inline static stdmath_double4 stdmath_double4_zwyz_get(stdmath_double4* p) { return stdmath_double4_zwyz(*p); }
inline static stdmath_double4 stdmath_double4_zwyz_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->w = value.y; p->y = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zwyw(stdmath_double4 v) { return {v.z,v.w,v.y,v.w}; }
inline static stdmath_double4 stdmath_double4_zwyw_get(stdmath_double4* p) { return stdmath_double4_zwyw(*p); }
inline static stdmath_double4 stdmath_double4_zwyw_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->w = value.y; p->y = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zwzx(stdmath_double4 v) { return {v.z,v.w,v.z,v.x}; }
inline static stdmath_double4 stdmath_double4_zwzx_get(stdmath_double4* p) { return stdmath_double4_zwzx(*p); }
inline static stdmath_double4 stdmath_double4_zwzx_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->w = value.y; p->z = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zwzy(stdmath_double4 v) { return {v.z,v.w,v.z,v.y}; }
inline static stdmath_double4 stdmath_double4_zwzy_get(stdmath_double4* p) { return stdmath_double4_zwzy(*p); }
inline static stdmath_double4 stdmath_double4_zwzy_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->w = value.y; p->z = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zwzz(stdmath_double4 v) { return {v.z,v.w,v.z,v.z}; }
inline static stdmath_double4 stdmath_double4_zwzz_get(stdmath_double4* p) { return stdmath_double4_zwzz(*p); }
inline static stdmath_double4 stdmath_double4_zwzz_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->w = value.y; p->z = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zwzw(stdmath_double4 v) { return {v.z,v.w,v.z,v.w}; }
inline static stdmath_double4 stdmath_double4_zwzw_get(stdmath_double4* p) { return stdmath_double4_zwzw(*p); }
inline static stdmath_double4 stdmath_double4_zwzw_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->w = value.y; p->z = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zwwx(stdmath_double4 v) { return {v.z,v.w,v.w,v.x}; }
inline static stdmath_double4 stdmath_double4_zwwx_get(stdmath_double4* p) { return stdmath_double4_zwwx(*p); }
inline static stdmath_double4 stdmath_double4_zwwx_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->w = value.y; p->w = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zwwy(stdmath_double4 v) { return {v.z,v.w,v.w,v.y}; }
inline static stdmath_double4 stdmath_double4_zwwy_get(stdmath_double4* p) { return stdmath_double4_zwwy(*p); }
inline static stdmath_double4 stdmath_double4_zwwy_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->w = value.y; p->w = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zwwz(stdmath_double4 v) { return {v.z,v.w,v.w,v.z}; }
inline static stdmath_double4 stdmath_double4_zwwz_get(stdmath_double4* p) { return stdmath_double4_zwwz(*p); }
inline static stdmath_double4 stdmath_double4_zwwz_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->w = value.y; p->w = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_zwww(stdmath_double4 v) { return {v.z,v.w,v.w,v.w}; }
inline static stdmath_double4 stdmath_double4_zwww_get(stdmath_double4* p) { return stdmath_double4_zwww(*p); }
inline static stdmath_double4 stdmath_double4_zwww_set(stdmath_double4* p, stdmath_double4 value) { p->z = value.x; p->w = value.y; p->w = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wxxx(stdmath_double4 v) { return {v.w,v.x,v.x,v.x}; }
inline static stdmath_double4 stdmath_double4_wxxx_get(stdmath_double4* p) { return stdmath_double4_wxxx(*p); }
inline static stdmath_double4 stdmath_double4_wxxx_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->x = value.y; p->x = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wxxy(stdmath_double4 v) { return {v.w,v.x,v.x,v.y}; }
inline static stdmath_double4 stdmath_double4_wxxy_get(stdmath_double4* p) { return stdmath_double4_wxxy(*p); }
inline static stdmath_double4 stdmath_double4_wxxy_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->x = value.y; p->x = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wxxz(stdmath_double4 v) { return {v.w,v.x,v.x,v.z}; }
inline static stdmath_double4 stdmath_double4_wxxz_get(stdmath_double4* p) { return stdmath_double4_wxxz(*p); }
inline static stdmath_double4 stdmath_double4_wxxz_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->x = value.y; p->x = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wxxw(stdmath_double4 v) { return {v.w,v.x,v.x,v.w}; }
inline static stdmath_double4 stdmath_double4_wxxw_get(stdmath_double4* p) { return stdmath_double4_wxxw(*p); }
inline static stdmath_double4 stdmath_double4_wxxw_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->x = value.y; p->x = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wxyx(stdmath_double4 v) { return {v.w,v.x,v.y,v.x}; }
inline static stdmath_double4 stdmath_double4_wxyx_get(stdmath_double4* p) { return stdmath_double4_wxyx(*p); }
inline static stdmath_double4 stdmath_double4_wxyx_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->x = value.y; p->y = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wxyy(stdmath_double4 v) { return {v.w,v.x,v.y,v.y}; }
inline static stdmath_double4 stdmath_double4_wxyy_get(stdmath_double4* p) { return stdmath_double4_wxyy(*p); }
inline static stdmath_double4 stdmath_double4_wxyy_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->x = value.y; p->y = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wxyz(stdmath_double4 v) { return {v.w,v.x,v.y,v.z}; }
inline static stdmath_double4 stdmath_double4_wxyz_get(stdmath_double4* p) { return stdmath_double4_wxyz(*p); }
inline static stdmath_double4 stdmath_double4_wxyz_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->x = value.y; p->y = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wxyw(stdmath_double4 v) { return {v.w,v.x,v.y,v.w}; }
inline static stdmath_double4 stdmath_double4_wxyw_get(stdmath_double4* p) { return stdmath_double4_wxyw(*p); }
inline static stdmath_double4 stdmath_double4_wxyw_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->x = value.y; p->y = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wxzx(stdmath_double4 v) { return {v.w,v.x,v.z,v.x}; }
inline static stdmath_double4 stdmath_double4_wxzx_get(stdmath_double4* p) { return stdmath_double4_wxzx(*p); }
inline static stdmath_double4 stdmath_double4_wxzx_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->x = value.y; p->z = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wxzy(stdmath_double4 v) { return {v.w,v.x,v.z,v.y}; }
inline static stdmath_double4 stdmath_double4_wxzy_get(stdmath_double4* p) { return stdmath_double4_wxzy(*p); }
inline static stdmath_double4 stdmath_double4_wxzy_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->x = value.y; p->z = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wxzz(stdmath_double4 v) { return {v.w,v.x,v.z,v.z}; }
inline static stdmath_double4 stdmath_double4_wxzz_get(stdmath_double4* p) { return stdmath_double4_wxzz(*p); }
inline static stdmath_double4 stdmath_double4_wxzz_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->x = value.y; p->z = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wxzw(stdmath_double4 v) { return {v.w,v.x,v.z,v.w}; }
inline static stdmath_double4 stdmath_double4_wxzw_get(stdmath_double4* p) { return stdmath_double4_wxzw(*p); }
inline static stdmath_double4 stdmath_double4_wxzw_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->x = value.y; p->z = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wxwx(stdmath_double4 v) { return {v.w,v.x,v.w,v.x}; }
inline static stdmath_double4 stdmath_double4_wxwx_get(stdmath_double4* p) { return stdmath_double4_wxwx(*p); }
inline static stdmath_double4 stdmath_double4_wxwx_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->x = value.y; p->w = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wxwy(stdmath_double4 v) { return {v.w,v.x,v.w,v.y}; }
inline static stdmath_double4 stdmath_double4_wxwy_get(stdmath_double4* p) { return stdmath_double4_wxwy(*p); }
inline static stdmath_double4 stdmath_double4_wxwy_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->x = value.y; p->w = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wxwz(stdmath_double4 v) { return {v.w,v.x,v.w,v.z}; }
inline static stdmath_double4 stdmath_double4_wxwz_get(stdmath_double4* p) { return stdmath_double4_wxwz(*p); }
inline static stdmath_double4 stdmath_double4_wxwz_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->x = value.y; p->w = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wxww(stdmath_double4 v) { return {v.w,v.x,v.w,v.w}; }
inline static stdmath_double4 stdmath_double4_wxww_get(stdmath_double4* p) { return stdmath_double4_wxww(*p); }
inline static stdmath_double4 stdmath_double4_wxww_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->x = value.y; p->w = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wyxx(stdmath_double4 v) { return {v.w,v.y,v.x,v.x}; }
inline static stdmath_double4 stdmath_double4_wyxx_get(stdmath_double4* p) { return stdmath_double4_wyxx(*p); }
inline static stdmath_double4 stdmath_double4_wyxx_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->y = value.y; p->x = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wyxy(stdmath_double4 v) { return {v.w,v.y,v.x,v.y}; }
inline static stdmath_double4 stdmath_double4_wyxy_get(stdmath_double4* p) { return stdmath_double4_wyxy(*p); }
inline static stdmath_double4 stdmath_double4_wyxy_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->y = value.y; p->x = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wyxz(stdmath_double4 v) { return {v.w,v.y,v.x,v.z}; }
inline static stdmath_double4 stdmath_double4_wyxz_get(stdmath_double4* p) { return stdmath_double4_wyxz(*p); }
inline static stdmath_double4 stdmath_double4_wyxz_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->y = value.y; p->x = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wyxw(stdmath_double4 v) { return {v.w,v.y,v.x,v.w}; }
inline static stdmath_double4 stdmath_double4_wyxw_get(stdmath_double4* p) { return stdmath_double4_wyxw(*p); }
inline static stdmath_double4 stdmath_double4_wyxw_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->y = value.y; p->x = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wyyx(stdmath_double4 v) { return {v.w,v.y,v.y,v.x}; }
inline static stdmath_double4 stdmath_double4_wyyx_get(stdmath_double4* p) { return stdmath_double4_wyyx(*p); }
inline static stdmath_double4 stdmath_double4_wyyx_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->y = value.y; p->y = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wyyy(stdmath_double4 v) { return {v.w,v.y,v.y,v.y}; }
inline static stdmath_double4 stdmath_double4_wyyy_get(stdmath_double4* p) { return stdmath_double4_wyyy(*p); }
inline static stdmath_double4 stdmath_double4_wyyy_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->y = value.y; p->y = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wyyz(stdmath_double4 v) { return {v.w,v.y,v.y,v.z}; }
inline static stdmath_double4 stdmath_double4_wyyz_get(stdmath_double4* p) { return stdmath_double4_wyyz(*p); }
inline static stdmath_double4 stdmath_double4_wyyz_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->y = value.y; p->y = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wyyw(stdmath_double4 v) { return {v.w,v.y,v.y,v.w}; }
inline static stdmath_double4 stdmath_double4_wyyw_get(stdmath_double4* p) { return stdmath_double4_wyyw(*p); }
inline static stdmath_double4 stdmath_double4_wyyw_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->y = value.y; p->y = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wyzx(stdmath_double4 v) { return {v.w,v.y,v.z,v.x}; }
inline static stdmath_double4 stdmath_double4_wyzx_get(stdmath_double4* p) { return stdmath_double4_wyzx(*p); }
inline static stdmath_double4 stdmath_double4_wyzx_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->y = value.y; p->z = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wyzy(stdmath_double4 v) { return {v.w,v.y,v.z,v.y}; }
inline static stdmath_double4 stdmath_double4_wyzy_get(stdmath_double4* p) { return stdmath_double4_wyzy(*p); }
inline static stdmath_double4 stdmath_double4_wyzy_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->y = value.y; p->z = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wyzz(stdmath_double4 v) { return {v.w,v.y,v.z,v.z}; }
inline static stdmath_double4 stdmath_double4_wyzz_get(stdmath_double4* p) { return stdmath_double4_wyzz(*p); }
inline static stdmath_double4 stdmath_double4_wyzz_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->y = value.y; p->z = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wyzw(stdmath_double4 v) { return {v.w,v.y,v.z,v.w}; }
inline static stdmath_double4 stdmath_double4_wyzw_get(stdmath_double4* p) { return stdmath_double4_wyzw(*p); }
inline static stdmath_double4 stdmath_double4_wyzw_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->y = value.y; p->z = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wywx(stdmath_double4 v) { return {v.w,v.y,v.w,v.x}; }
inline static stdmath_double4 stdmath_double4_wywx_get(stdmath_double4* p) { return stdmath_double4_wywx(*p); }
inline static stdmath_double4 stdmath_double4_wywx_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->y = value.y; p->w = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wywy(stdmath_double4 v) { return {v.w,v.y,v.w,v.y}; }
inline static stdmath_double4 stdmath_double4_wywy_get(stdmath_double4* p) { return stdmath_double4_wywy(*p); }
inline static stdmath_double4 stdmath_double4_wywy_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->y = value.y; p->w = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wywz(stdmath_double4 v) { return {v.w,v.y,v.w,v.z}; }
inline static stdmath_double4 stdmath_double4_wywz_get(stdmath_double4* p) { return stdmath_double4_wywz(*p); }
inline static stdmath_double4 stdmath_double4_wywz_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->y = value.y; p->w = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wyww(stdmath_double4 v) { return {v.w,v.y,v.w,v.w}; }
inline static stdmath_double4 stdmath_double4_wyww_get(stdmath_double4* p) { return stdmath_double4_wyww(*p); }
inline static stdmath_double4 stdmath_double4_wyww_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->y = value.y; p->w = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wzxx(stdmath_double4 v) { return {v.w,v.z,v.x,v.x}; }
inline static stdmath_double4 stdmath_double4_wzxx_get(stdmath_double4* p) { return stdmath_double4_wzxx(*p); }
inline static stdmath_double4 stdmath_double4_wzxx_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->z = value.y; p->x = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wzxy(stdmath_double4 v) { return {v.w,v.z,v.x,v.y}; }
inline static stdmath_double4 stdmath_double4_wzxy_get(stdmath_double4* p) { return stdmath_double4_wzxy(*p); }
inline static stdmath_double4 stdmath_double4_wzxy_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->z = value.y; p->x = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wzxz(stdmath_double4 v) { return {v.w,v.z,v.x,v.z}; }
inline static stdmath_double4 stdmath_double4_wzxz_get(stdmath_double4* p) { return stdmath_double4_wzxz(*p); }
inline static stdmath_double4 stdmath_double4_wzxz_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->z = value.y; p->x = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wzxw(stdmath_double4 v) { return {v.w,v.z,v.x,v.w}; }
inline static stdmath_double4 stdmath_double4_wzxw_get(stdmath_double4* p) { return stdmath_double4_wzxw(*p); }
inline static stdmath_double4 stdmath_double4_wzxw_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->z = value.y; p->x = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wzyx(stdmath_double4 v) { return {v.w,v.z,v.y,v.x}; }
inline static stdmath_double4 stdmath_double4_wzyx_get(stdmath_double4* p) { return stdmath_double4_wzyx(*p); }
inline static stdmath_double4 stdmath_double4_wzyx_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->z = value.y; p->y = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wzyy(stdmath_double4 v) { return {v.w,v.z,v.y,v.y}; }
inline static stdmath_double4 stdmath_double4_wzyy_get(stdmath_double4* p) { return stdmath_double4_wzyy(*p); }
inline static stdmath_double4 stdmath_double4_wzyy_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->z = value.y; p->y = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wzyz(stdmath_double4 v) { return {v.w,v.z,v.y,v.z}; }
inline static stdmath_double4 stdmath_double4_wzyz_get(stdmath_double4* p) { return stdmath_double4_wzyz(*p); }
inline static stdmath_double4 stdmath_double4_wzyz_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->z = value.y; p->y = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wzyw(stdmath_double4 v) { return {v.w,v.z,v.y,v.w}; }
inline static stdmath_double4 stdmath_double4_wzyw_get(stdmath_double4* p) { return stdmath_double4_wzyw(*p); }
inline static stdmath_double4 stdmath_double4_wzyw_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->z = value.y; p->y = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wzzx(stdmath_double4 v) { return {v.w,v.z,v.z,v.x}; }
inline static stdmath_double4 stdmath_double4_wzzx_get(stdmath_double4* p) { return stdmath_double4_wzzx(*p); }
inline static stdmath_double4 stdmath_double4_wzzx_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->z = value.y; p->z = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wzzy(stdmath_double4 v) { return {v.w,v.z,v.z,v.y}; }
inline static stdmath_double4 stdmath_double4_wzzy_get(stdmath_double4* p) { return stdmath_double4_wzzy(*p); }
inline static stdmath_double4 stdmath_double4_wzzy_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->z = value.y; p->z = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wzzz(stdmath_double4 v) { return {v.w,v.z,v.z,v.z}; }
inline static stdmath_double4 stdmath_double4_wzzz_get(stdmath_double4* p) { return stdmath_double4_wzzz(*p); }
inline static stdmath_double4 stdmath_double4_wzzz_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->z = value.y; p->z = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wzzw(stdmath_double4 v) { return {v.w,v.z,v.z,v.w}; }
inline static stdmath_double4 stdmath_double4_wzzw_get(stdmath_double4* p) { return stdmath_double4_wzzw(*p); }
inline static stdmath_double4 stdmath_double4_wzzw_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->z = value.y; p->z = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wzwx(stdmath_double4 v) { return {v.w,v.z,v.w,v.x}; }
inline static stdmath_double4 stdmath_double4_wzwx_get(stdmath_double4* p) { return stdmath_double4_wzwx(*p); }
inline static stdmath_double4 stdmath_double4_wzwx_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->z = value.y; p->w = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wzwy(stdmath_double4 v) { return {v.w,v.z,v.w,v.y}; }
inline static stdmath_double4 stdmath_double4_wzwy_get(stdmath_double4* p) { return stdmath_double4_wzwy(*p); }
inline static stdmath_double4 stdmath_double4_wzwy_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->z = value.y; p->w = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wzwz(stdmath_double4 v) { return {v.w,v.z,v.w,v.z}; }
inline static stdmath_double4 stdmath_double4_wzwz_get(stdmath_double4* p) { return stdmath_double4_wzwz(*p); }
inline static stdmath_double4 stdmath_double4_wzwz_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->z = value.y; p->w = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wzww(stdmath_double4 v) { return {v.w,v.z,v.w,v.w}; }
inline static stdmath_double4 stdmath_double4_wzww_get(stdmath_double4* p) { return stdmath_double4_wzww(*p); }
inline static stdmath_double4 stdmath_double4_wzww_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->z = value.y; p->w = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wwxx(stdmath_double4 v) { return {v.w,v.w,v.x,v.x}; }
inline static stdmath_double4 stdmath_double4_wwxx_get(stdmath_double4* p) { return stdmath_double4_wwxx(*p); }
inline static stdmath_double4 stdmath_double4_wwxx_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->w = value.y; p->x = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wwxy(stdmath_double4 v) { return {v.w,v.w,v.x,v.y}; }
inline static stdmath_double4 stdmath_double4_wwxy_get(stdmath_double4* p) { return stdmath_double4_wwxy(*p); }
inline static stdmath_double4 stdmath_double4_wwxy_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->w = value.y; p->x = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wwxz(stdmath_double4 v) { return {v.w,v.w,v.x,v.z}; }
inline static stdmath_double4 stdmath_double4_wwxz_get(stdmath_double4* p) { return stdmath_double4_wwxz(*p); }
inline static stdmath_double4 stdmath_double4_wwxz_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->w = value.y; p->x = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wwxw(stdmath_double4 v) { return {v.w,v.w,v.x,v.w}; }
inline static stdmath_double4 stdmath_double4_wwxw_get(stdmath_double4* p) { return stdmath_double4_wwxw(*p); }
inline static stdmath_double4 stdmath_double4_wwxw_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->w = value.y; p->x = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wwyx(stdmath_double4 v) { return {v.w,v.w,v.y,v.x}; }
inline static stdmath_double4 stdmath_double4_wwyx_get(stdmath_double4* p) { return stdmath_double4_wwyx(*p); }
inline static stdmath_double4 stdmath_double4_wwyx_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->w = value.y; p->y = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wwyy(stdmath_double4 v) { return {v.w,v.w,v.y,v.y}; }
inline static stdmath_double4 stdmath_double4_wwyy_get(stdmath_double4* p) { return stdmath_double4_wwyy(*p); }
inline static stdmath_double4 stdmath_double4_wwyy_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->w = value.y; p->y = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wwyz(stdmath_double4 v) { return {v.w,v.w,v.y,v.z}; }
inline static stdmath_double4 stdmath_double4_wwyz_get(stdmath_double4* p) { return stdmath_double4_wwyz(*p); }
inline static stdmath_double4 stdmath_double4_wwyz_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->w = value.y; p->y = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wwyw(stdmath_double4 v) { return {v.w,v.w,v.y,v.w}; }
inline static stdmath_double4 stdmath_double4_wwyw_get(stdmath_double4* p) { return stdmath_double4_wwyw(*p); }
inline static stdmath_double4 stdmath_double4_wwyw_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->w = value.y; p->y = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wwzx(stdmath_double4 v) { return {v.w,v.w,v.z,v.x}; }
inline static stdmath_double4 stdmath_double4_wwzx_get(stdmath_double4* p) { return stdmath_double4_wwzx(*p); }
inline static stdmath_double4 stdmath_double4_wwzx_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->w = value.y; p->z = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wwzy(stdmath_double4 v) { return {v.w,v.w,v.z,v.y}; }
inline static stdmath_double4 stdmath_double4_wwzy_get(stdmath_double4* p) { return stdmath_double4_wwzy(*p); }
inline static stdmath_double4 stdmath_double4_wwzy_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->w = value.y; p->z = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wwzz(stdmath_double4 v) { return {v.w,v.w,v.z,v.z}; }
inline static stdmath_double4 stdmath_double4_wwzz_get(stdmath_double4* p) { return stdmath_double4_wwzz(*p); }
inline static stdmath_double4 stdmath_double4_wwzz_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->w = value.y; p->z = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wwzw(stdmath_double4 v) { return {v.w,v.w,v.z,v.w}; }
inline static stdmath_double4 stdmath_double4_wwzw_get(stdmath_double4* p) { return stdmath_double4_wwzw(*p); }
inline static stdmath_double4 stdmath_double4_wwzw_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->w = value.y; p->z = value.z; p->w = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wwwx(stdmath_double4 v) { return {v.w,v.w,v.w,v.x}; }
inline static stdmath_double4 stdmath_double4_wwwx_get(stdmath_double4* p) { return stdmath_double4_wwwx(*p); }
inline static stdmath_double4 stdmath_double4_wwwx_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->w = value.y; p->w = value.z; p->x = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wwwy(stdmath_double4 v) { return {v.w,v.w,v.w,v.y}; }
inline static stdmath_double4 stdmath_double4_wwwy_get(stdmath_double4* p) { return stdmath_double4_wwwy(*p); }
inline static stdmath_double4 stdmath_double4_wwwy_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->w = value.y; p->w = value.z; p->y = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wwwz(stdmath_double4 v) { return {v.w,v.w,v.w,v.z}; }
inline static stdmath_double4 stdmath_double4_wwwz_get(stdmath_double4* p) { return stdmath_double4_wwwz(*p); }
inline static stdmath_double4 stdmath_double4_wwwz_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->w = value.y; p->w = value.z; p->z = value.w; return *p; }
inline static stdmath_double4 stdmath_double4_wwww(stdmath_double4 v) { return {v.w,v.w,v.w,v.w}; }
inline static stdmath_double4 stdmath_double4_wwww_get(stdmath_double4* p) { return stdmath_double4_wwww(*p); }
inline static stdmath_double4 stdmath_double4_wwww_set(stdmath_double4* p, stdmath_double4 value) { p->w = value.x; p->w = value.y; p->w = value.z; p->w = value.w; return *p; }


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