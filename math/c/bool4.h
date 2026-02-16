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
bool stdmath_bool4_dot(stdmath_bool4 a, stdmath_bool4 b);
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
inline static stdmath_bool1 stdmath_bool4_x_get(stdmath_bool4* p) { return stdmath_bool4_x(*p); }
inline static stdmath_bool4 stdmath_bool4_x_set(stdmath_bool4* p, stdmath_bool1 value) { p->x = value.x; return *p; }
inline static stdmath_bool1 stdmath_bool4_y(stdmath_bool4 v) { return {v.y}; }
inline static stdmath_bool1 stdmath_bool4_y_get(stdmath_bool4* p) { return stdmath_bool4_y(*p); }
inline static stdmath_bool4 stdmath_bool4_y_set(stdmath_bool4* p, stdmath_bool1 value) { p->y = value.x; return *p; }
inline static stdmath_bool1 stdmath_bool4_z(stdmath_bool4 v) { return {v.z}; }
inline static stdmath_bool1 stdmath_bool4_z_get(stdmath_bool4* p) { return stdmath_bool4_z(*p); }
inline static stdmath_bool4 stdmath_bool4_z_set(stdmath_bool4* p, stdmath_bool1 value) { p->z = value.x; return *p; }
inline static stdmath_bool1 stdmath_bool4_w(stdmath_bool4 v) { return {v.w}; }
inline static stdmath_bool1 stdmath_bool4_w_get(stdmath_bool4* p) { return stdmath_bool4_w(*p); }
inline static stdmath_bool4 stdmath_bool4_w_set(stdmath_bool4* p, stdmath_bool1 value) { p->w = value.x; return *p; }
inline static stdmath_bool2 stdmath_bool4_xx(stdmath_bool4 v) { return {v.x,v.x}; }
inline static stdmath_bool2 stdmath_bool4_xx_get(stdmath_bool4* p) { return stdmath_bool4_xx(*p); }
inline static stdmath_bool4 stdmath_bool4_xx_set(stdmath_bool4* p, stdmath_bool2 value) { p->x = value.x; p->x = value.y; return *p; }
inline static stdmath_bool2 stdmath_bool4_xy(stdmath_bool4 v) { return {v.x,v.y}; }
inline static stdmath_bool2 stdmath_bool4_xy_get(stdmath_bool4* p) { return stdmath_bool4_xy(*p); }
inline static stdmath_bool4 stdmath_bool4_xy_set(stdmath_bool4* p, stdmath_bool2 value) { p->x = value.x; p->y = value.y; return *p; }
inline static stdmath_bool2 stdmath_bool4_xz(stdmath_bool4 v) { return {v.x,v.z}; }
inline static stdmath_bool2 stdmath_bool4_xz_get(stdmath_bool4* p) { return stdmath_bool4_xz(*p); }
inline static stdmath_bool4 stdmath_bool4_xz_set(stdmath_bool4* p, stdmath_bool2 value) { p->x = value.x; p->z = value.y; return *p; }
inline static stdmath_bool2 stdmath_bool4_xw(stdmath_bool4 v) { return {v.x,v.w}; }
inline static stdmath_bool2 stdmath_bool4_xw_get(stdmath_bool4* p) { return stdmath_bool4_xw(*p); }
inline static stdmath_bool4 stdmath_bool4_xw_set(stdmath_bool4* p, stdmath_bool2 value) { p->x = value.x; p->w = value.y; return *p; }
inline static stdmath_bool2 stdmath_bool4_yx(stdmath_bool4 v) { return {v.y,v.x}; }
inline static stdmath_bool2 stdmath_bool4_yx_get(stdmath_bool4* p) { return stdmath_bool4_yx(*p); }
inline static stdmath_bool4 stdmath_bool4_yx_set(stdmath_bool4* p, stdmath_bool2 value) { p->y = value.x; p->x = value.y; return *p; }
inline static stdmath_bool2 stdmath_bool4_yy(stdmath_bool4 v) { return {v.y,v.y}; }
inline static stdmath_bool2 stdmath_bool4_yy_get(stdmath_bool4* p) { return stdmath_bool4_yy(*p); }
inline static stdmath_bool4 stdmath_bool4_yy_set(stdmath_bool4* p, stdmath_bool2 value) { p->y = value.x; p->y = value.y; return *p; }
inline static stdmath_bool2 stdmath_bool4_yz(stdmath_bool4 v) { return {v.y,v.z}; }
inline static stdmath_bool2 stdmath_bool4_yz_get(stdmath_bool4* p) { return stdmath_bool4_yz(*p); }
inline static stdmath_bool4 stdmath_bool4_yz_set(stdmath_bool4* p, stdmath_bool2 value) { p->y = value.x; p->z = value.y; return *p; }
inline static stdmath_bool2 stdmath_bool4_yw(stdmath_bool4 v) { return {v.y,v.w}; }
inline static stdmath_bool2 stdmath_bool4_yw_get(stdmath_bool4* p) { return stdmath_bool4_yw(*p); }
inline static stdmath_bool4 stdmath_bool4_yw_set(stdmath_bool4* p, stdmath_bool2 value) { p->y = value.x; p->w = value.y; return *p; }
inline static stdmath_bool2 stdmath_bool4_zx(stdmath_bool4 v) { return {v.z,v.x}; }
inline static stdmath_bool2 stdmath_bool4_zx_get(stdmath_bool4* p) { return stdmath_bool4_zx(*p); }
inline static stdmath_bool4 stdmath_bool4_zx_set(stdmath_bool4* p, stdmath_bool2 value) { p->z = value.x; p->x = value.y; return *p; }
inline static stdmath_bool2 stdmath_bool4_zy(stdmath_bool4 v) { return {v.z,v.y}; }
inline static stdmath_bool2 stdmath_bool4_zy_get(stdmath_bool4* p) { return stdmath_bool4_zy(*p); }
inline static stdmath_bool4 stdmath_bool4_zy_set(stdmath_bool4* p, stdmath_bool2 value) { p->z = value.x; p->y = value.y; return *p; }
inline static stdmath_bool2 stdmath_bool4_zz(stdmath_bool4 v) { return {v.z,v.z}; }
inline static stdmath_bool2 stdmath_bool4_zz_get(stdmath_bool4* p) { return stdmath_bool4_zz(*p); }
inline static stdmath_bool4 stdmath_bool4_zz_set(stdmath_bool4* p, stdmath_bool2 value) { p->z = value.x; p->z = value.y; return *p; }
inline static stdmath_bool2 stdmath_bool4_zw(stdmath_bool4 v) { return {v.z,v.w}; }
inline static stdmath_bool2 stdmath_bool4_zw_get(stdmath_bool4* p) { return stdmath_bool4_zw(*p); }
inline static stdmath_bool4 stdmath_bool4_zw_set(stdmath_bool4* p, stdmath_bool2 value) { p->z = value.x; p->w = value.y; return *p; }
inline static stdmath_bool2 stdmath_bool4_wx(stdmath_bool4 v) { return {v.w,v.x}; }
inline static stdmath_bool2 stdmath_bool4_wx_get(stdmath_bool4* p) { return stdmath_bool4_wx(*p); }
inline static stdmath_bool4 stdmath_bool4_wx_set(stdmath_bool4* p, stdmath_bool2 value) { p->w = value.x; p->x = value.y; return *p; }
inline static stdmath_bool2 stdmath_bool4_wy(stdmath_bool4 v) { return {v.w,v.y}; }
inline static stdmath_bool2 stdmath_bool4_wy_get(stdmath_bool4* p) { return stdmath_bool4_wy(*p); }
inline static stdmath_bool4 stdmath_bool4_wy_set(stdmath_bool4* p, stdmath_bool2 value) { p->w = value.x; p->y = value.y; return *p; }
inline static stdmath_bool2 stdmath_bool4_wz(stdmath_bool4 v) { return {v.w,v.z}; }
inline static stdmath_bool2 stdmath_bool4_wz_get(stdmath_bool4* p) { return stdmath_bool4_wz(*p); }
inline static stdmath_bool4 stdmath_bool4_wz_set(stdmath_bool4* p, stdmath_bool2 value) { p->w = value.x; p->z = value.y; return *p; }
inline static stdmath_bool2 stdmath_bool4_ww(stdmath_bool4 v) { return {v.w,v.w}; }
inline static stdmath_bool2 stdmath_bool4_ww_get(stdmath_bool4* p) { return stdmath_bool4_ww(*p); }
inline static stdmath_bool4 stdmath_bool4_ww_set(stdmath_bool4* p, stdmath_bool2 value) { p->w = value.x; p->w = value.y; return *p; }
inline static stdmath_bool3 stdmath_bool4_xxx(stdmath_bool4 v) { return {v.x,v.x,v.x}; }
inline static stdmath_bool3 stdmath_bool4_xxx_get(stdmath_bool4* p) { return stdmath_bool4_xxx(*p); }
inline static stdmath_bool4 stdmath_bool4_xxx_set(stdmath_bool4* p, stdmath_bool3 value) { p->x = value.x; p->x = value.y; p->x = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_xxy(stdmath_bool4 v) { return {v.x,v.x,v.y}; }
inline static stdmath_bool3 stdmath_bool4_xxy_get(stdmath_bool4* p) { return stdmath_bool4_xxy(*p); }
inline static stdmath_bool4 stdmath_bool4_xxy_set(stdmath_bool4* p, stdmath_bool3 value) { p->x = value.x; p->x = value.y; p->y = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_xxz(stdmath_bool4 v) { return {v.x,v.x,v.z}; }
inline static stdmath_bool3 stdmath_bool4_xxz_get(stdmath_bool4* p) { return stdmath_bool4_xxz(*p); }
inline static stdmath_bool4 stdmath_bool4_xxz_set(stdmath_bool4* p, stdmath_bool3 value) { p->x = value.x; p->x = value.y; p->z = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_xxw(stdmath_bool4 v) { return {v.x,v.x,v.w}; }
inline static stdmath_bool3 stdmath_bool4_xxw_get(stdmath_bool4* p) { return stdmath_bool4_xxw(*p); }
inline static stdmath_bool4 stdmath_bool4_xxw_set(stdmath_bool4* p, stdmath_bool3 value) { p->x = value.x; p->x = value.y; p->w = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_xyx(stdmath_bool4 v) { return {v.x,v.y,v.x}; }
inline static stdmath_bool3 stdmath_bool4_xyx_get(stdmath_bool4* p) { return stdmath_bool4_xyx(*p); }
inline static stdmath_bool4 stdmath_bool4_xyx_set(stdmath_bool4* p, stdmath_bool3 value) { p->x = value.x; p->y = value.y; p->x = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_xyy(stdmath_bool4 v) { return {v.x,v.y,v.y}; }
inline static stdmath_bool3 stdmath_bool4_xyy_get(stdmath_bool4* p) { return stdmath_bool4_xyy(*p); }
inline static stdmath_bool4 stdmath_bool4_xyy_set(stdmath_bool4* p, stdmath_bool3 value) { p->x = value.x; p->y = value.y; p->y = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_xyz(stdmath_bool4 v) { return {v.x,v.y,v.z}; }
inline static stdmath_bool3 stdmath_bool4_xyz_get(stdmath_bool4* p) { return stdmath_bool4_xyz(*p); }
inline static stdmath_bool4 stdmath_bool4_xyz_set(stdmath_bool4* p, stdmath_bool3 value) { p->x = value.x; p->y = value.y; p->z = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_xyw(stdmath_bool4 v) { return {v.x,v.y,v.w}; }
inline static stdmath_bool3 stdmath_bool4_xyw_get(stdmath_bool4* p) { return stdmath_bool4_xyw(*p); }
inline static stdmath_bool4 stdmath_bool4_xyw_set(stdmath_bool4* p, stdmath_bool3 value) { p->x = value.x; p->y = value.y; p->w = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_xzx(stdmath_bool4 v) { return {v.x,v.z,v.x}; }
inline static stdmath_bool3 stdmath_bool4_xzx_get(stdmath_bool4* p) { return stdmath_bool4_xzx(*p); }
inline static stdmath_bool4 stdmath_bool4_xzx_set(stdmath_bool4* p, stdmath_bool3 value) { p->x = value.x; p->z = value.y; p->x = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_xzy(stdmath_bool4 v) { return {v.x,v.z,v.y}; }
inline static stdmath_bool3 stdmath_bool4_xzy_get(stdmath_bool4* p) { return stdmath_bool4_xzy(*p); }
inline static stdmath_bool4 stdmath_bool4_xzy_set(stdmath_bool4* p, stdmath_bool3 value) { p->x = value.x; p->z = value.y; p->y = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_xzz(stdmath_bool4 v) { return {v.x,v.z,v.z}; }
inline static stdmath_bool3 stdmath_bool4_xzz_get(stdmath_bool4* p) { return stdmath_bool4_xzz(*p); }
inline static stdmath_bool4 stdmath_bool4_xzz_set(stdmath_bool4* p, stdmath_bool3 value) { p->x = value.x; p->z = value.y; p->z = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_xzw(stdmath_bool4 v) { return {v.x,v.z,v.w}; }
inline static stdmath_bool3 stdmath_bool4_xzw_get(stdmath_bool4* p) { return stdmath_bool4_xzw(*p); }
inline static stdmath_bool4 stdmath_bool4_xzw_set(stdmath_bool4* p, stdmath_bool3 value) { p->x = value.x; p->z = value.y; p->w = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_xwx(stdmath_bool4 v) { return {v.x,v.w,v.x}; }
inline static stdmath_bool3 stdmath_bool4_xwx_get(stdmath_bool4* p) { return stdmath_bool4_xwx(*p); }
inline static stdmath_bool4 stdmath_bool4_xwx_set(stdmath_bool4* p, stdmath_bool3 value) { p->x = value.x; p->w = value.y; p->x = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_xwy(stdmath_bool4 v) { return {v.x,v.w,v.y}; }
inline static stdmath_bool3 stdmath_bool4_xwy_get(stdmath_bool4* p) { return stdmath_bool4_xwy(*p); }
inline static stdmath_bool4 stdmath_bool4_xwy_set(stdmath_bool4* p, stdmath_bool3 value) { p->x = value.x; p->w = value.y; p->y = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_xwz(stdmath_bool4 v) { return {v.x,v.w,v.z}; }
inline static stdmath_bool3 stdmath_bool4_xwz_get(stdmath_bool4* p) { return stdmath_bool4_xwz(*p); }
inline static stdmath_bool4 stdmath_bool4_xwz_set(stdmath_bool4* p, stdmath_bool3 value) { p->x = value.x; p->w = value.y; p->z = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_xww(stdmath_bool4 v) { return {v.x,v.w,v.w}; }
inline static stdmath_bool3 stdmath_bool4_xww_get(stdmath_bool4* p) { return stdmath_bool4_xww(*p); }
inline static stdmath_bool4 stdmath_bool4_xww_set(stdmath_bool4* p, stdmath_bool3 value) { p->x = value.x; p->w = value.y; p->w = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_yxx(stdmath_bool4 v) { return {v.y,v.x,v.x}; }
inline static stdmath_bool3 stdmath_bool4_yxx_get(stdmath_bool4* p) { return stdmath_bool4_yxx(*p); }
inline static stdmath_bool4 stdmath_bool4_yxx_set(stdmath_bool4* p, stdmath_bool3 value) { p->y = value.x; p->x = value.y; p->x = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_yxy(stdmath_bool4 v) { return {v.y,v.x,v.y}; }
inline static stdmath_bool3 stdmath_bool4_yxy_get(stdmath_bool4* p) { return stdmath_bool4_yxy(*p); }
inline static stdmath_bool4 stdmath_bool4_yxy_set(stdmath_bool4* p, stdmath_bool3 value) { p->y = value.x; p->x = value.y; p->y = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_yxz(stdmath_bool4 v) { return {v.y,v.x,v.z}; }
inline static stdmath_bool3 stdmath_bool4_yxz_get(stdmath_bool4* p) { return stdmath_bool4_yxz(*p); }
inline static stdmath_bool4 stdmath_bool4_yxz_set(stdmath_bool4* p, stdmath_bool3 value) { p->y = value.x; p->x = value.y; p->z = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_yxw(stdmath_bool4 v) { return {v.y,v.x,v.w}; }
inline static stdmath_bool3 stdmath_bool4_yxw_get(stdmath_bool4* p) { return stdmath_bool4_yxw(*p); }
inline static stdmath_bool4 stdmath_bool4_yxw_set(stdmath_bool4* p, stdmath_bool3 value) { p->y = value.x; p->x = value.y; p->w = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_yyx(stdmath_bool4 v) { return {v.y,v.y,v.x}; }
inline static stdmath_bool3 stdmath_bool4_yyx_get(stdmath_bool4* p) { return stdmath_bool4_yyx(*p); }
inline static stdmath_bool4 stdmath_bool4_yyx_set(stdmath_bool4* p, stdmath_bool3 value) { p->y = value.x; p->y = value.y; p->x = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_yyy(stdmath_bool4 v) { return {v.y,v.y,v.y}; }
inline static stdmath_bool3 stdmath_bool4_yyy_get(stdmath_bool4* p) { return stdmath_bool4_yyy(*p); }
inline static stdmath_bool4 stdmath_bool4_yyy_set(stdmath_bool4* p, stdmath_bool3 value) { p->y = value.x; p->y = value.y; p->y = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_yyz(stdmath_bool4 v) { return {v.y,v.y,v.z}; }
inline static stdmath_bool3 stdmath_bool4_yyz_get(stdmath_bool4* p) { return stdmath_bool4_yyz(*p); }
inline static stdmath_bool4 stdmath_bool4_yyz_set(stdmath_bool4* p, stdmath_bool3 value) { p->y = value.x; p->y = value.y; p->z = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_yyw(stdmath_bool4 v) { return {v.y,v.y,v.w}; }
inline static stdmath_bool3 stdmath_bool4_yyw_get(stdmath_bool4* p) { return stdmath_bool4_yyw(*p); }
inline static stdmath_bool4 stdmath_bool4_yyw_set(stdmath_bool4* p, stdmath_bool3 value) { p->y = value.x; p->y = value.y; p->w = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_yzx(stdmath_bool4 v) { return {v.y,v.z,v.x}; }
inline static stdmath_bool3 stdmath_bool4_yzx_get(stdmath_bool4* p) { return stdmath_bool4_yzx(*p); }
inline static stdmath_bool4 stdmath_bool4_yzx_set(stdmath_bool4* p, stdmath_bool3 value) { p->y = value.x; p->z = value.y; p->x = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_yzy(stdmath_bool4 v) { return {v.y,v.z,v.y}; }
inline static stdmath_bool3 stdmath_bool4_yzy_get(stdmath_bool4* p) { return stdmath_bool4_yzy(*p); }
inline static stdmath_bool4 stdmath_bool4_yzy_set(stdmath_bool4* p, stdmath_bool3 value) { p->y = value.x; p->z = value.y; p->y = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_yzz(stdmath_bool4 v) { return {v.y,v.z,v.z}; }
inline static stdmath_bool3 stdmath_bool4_yzz_get(stdmath_bool4* p) { return stdmath_bool4_yzz(*p); }
inline static stdmath_bool4 stdmath_bool4_yzz_set(stdmath_bool4* p, stdmath_bool3 value) { p->y = value.x; p->z = value.y; p->z = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_yzw(stdmath_bool4 v) { return {v.y,v.z,v.w}; }
inline static stdmath_bool3 stdmath_bool4_yzw_get(stdmath_bool4* p) { return stdmath_bool4_yzw(*p); }
inline static stdmath_bool4 stdmath_bool4_yzw_set(stdmath_bool4* p, stdmath_bool3 value) { p->y = value.x; p->z = value.y; p->w = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_ywx(stdmath_bool4 v) { return {v.y,v.w,v.x}; }
inline static stdmath_bool3 stdmath_bool4_ywx_get(stdmath_bool4* p) { return stdmath_bool4_ywx(*p); }
inline static stdmath_bool4 stdmath_bool4_ywx_set(stdmath_bool4* p, stdmath_bool3 value) { p->y = value.x; p->w = value.y; p->x = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_ywy(stdmath_bool4 v) { return {v.y,v.w,v.y}; }
inline static stdmath_bool3 stdmath_bool4_ywy_get(stdmath_bool4* p) { return stdmath_bool4_ywy(*p); }
inline static stdmath_bool4 stdmath_bool4_ywy_set(stdmath_bool4* p, stdmath_bool3 value) { p->y = value.x; p->w = value.y; p->y = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_ywz(stdmath_bool4 v) { return {v.y,v.w,v.z}; }
inline static stdmath_bool3 stdmath_bool4_ywz_get(stdmath_bool4* p) { return stdmath_bool4_ywz(*p); }
inline static stdmath_bool4 stdmath_bool4_ywz_set(stdmath_bool4* p, stdmath_bool3 value) { p->y = value.x; p->w = value.y; p->z = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_yww(stdmath_bool4 v) { return {v.y,v.w,v.w}; }
inline static stdmath_bool3 stdmath_bool4_yww_get(stdmath_bool4* p) { return stdmath_bool4_yww(*p); }
inline static stdmath_bool4 stdmath_bool4_yww_set(stdmath_bool4* p, stdmath_bool3 value) { p->y = value.x; p->w = value.y; p->w = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_zxx(stdmath_bool4 v) { return {v.z,v.x,v.x}; }
inline static stdmath_bool3 stdmath_bool4_zxx_get(stdmath_bool4* p) { return stdmath_bool4_zxx(*p); }
inline static stdmath_bool4 stdmath_bool4_zxx_set(stdmath_bool4* p, stdmath_bool3 value) { p->z = value.x; p->x = value.y; p->x = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_zxy(stdmath_bool4 v) { return {v.z,v.x,v.y}; }
inline static stdmath_bool3 stdmath_bool4_zxy_get(stdmath_bool4* p) { return stdmath_bool4_zxy(*p); }
inline static stdmath_bool4 stdmath_bool4_zxy_set(stdmath_bool4* p, stdmath_bool3 value) { p->z = value.x; p->x = value.y; p->y = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_zxz(stdmath_bool4 v) { return {v.z,v.x,v.z}; }
inline static stdmath_bool3 stdmath_bool4_zxz_get(stdmath_bool4* p) { return stdmath_bool4_zxz(*p); }
inline static stdmath_bool4 stdmath_bool4_zxz_set(stdmath_bool4* p, stdmath_bool3 value) { p->z = value.x; p->x = value.y; p->z = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_zxw(stdmath_bool4 v) { return {v.z,v.x,v.w}; }
inline static stdmath_bool3 stdmath_bool4_zxw_get(stdmath_bool4* p) { return stdmath_bool4_zxw(*p); }
inline static stdmath_bool4 stdmath_bool4_zxw_set(stdmath_bool4* p, stdmath_bool3 value) { p->z = value.x; p->x = value.y; p->w = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_zyx(stdmath_bool4 v) { return {v.z,v.y,v.x}; }
inline static stdmath_bool3 stdmath_bool4_zyx_get(stdmath_bool4* p) { return stdmath_bool4_zyx(*p); }
inline static stdmath_bool4 stdmath_bool4_zyx_set(stdmath_bool4* p, stdmath_bool3 value) { p->z = value.x; p->y = value.y; p->x = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_zyy(stdmath_bool4 v) { return {v.z,v.y,v.y}; }
inline static stdmath_bool3 stdmath_bool4_zyy_get(stdmath_bool4* p) { return stdmath_bool4_zyy(*p); }
inline static stdmath_bool4 stdmath_bool4_zyy_set(stdmath_bool4* p, stdmath_bool3 value) { p->z = value.x; p->y = value.y; p->y = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_zyz(stdmath_bool4 v) { return {v.z,v.y,v.z}; }
inline static stdmath_bool3 stdmath_bool4_zyz_get(stdmath_bool4* p) { return stdmath_bool4_zyz(*p); }
inline static stdmath_bool4 stdmath_bool4_zyz_set(stdmath_bool4* p, stdmath_bool3 value) { p->z = value.x; p->y = value.y; p->z = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_zyw(stdmath_bool4 v) { return {v.z,v.y,v.w}; }
inline static stdmath_bool3 stdmath_bool4_zyw_get(stdmath_bool4* p) { return stdmath_bool4_zyw(*p); }
inline static stdmath_bool4 stdmath_bool4_zyw_set(stdmath_bool4* p, stdmath_bool3 value) { p->z = value.x; p->y = value.y; p->w = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_zzx(stdmath_bool4 v) { return {v.z,v.z,v.x}; }
inline static stdmath_bool3 stdmath_bool4_zzx_get(stdmath_bool4* p) { return stdmath_bool4_zzx(*p); }
inline static stdmath_bool4 stdmath_bool4_zzx_set(stdmath_bool4* p, stdmath_bool3 value) { p->z = value.x; p->z = value.y; p->x = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_zzy(stdmath_bool4 v) { return {v.z,v.z,v.y}; }
inline static stdmath_bool3 stdmath_bool4_zzy_get(stdmath_bool4* p) { return stdmath_bool4_zzy(*p); }
inline static stdmath_bool4 stdmath_bool4_zzy_set(stdmath_bool4* p, stdmath_bool3 value) { p->z = value.x; p->z = value.y; p->y = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_zzz(stdmath_bool4 v) { return {v.z,v.z,v.z}; }
inline static stdmath_bool3 stdmath_bool4_zzz_get(stdmath_bool4* p) { return stdmath_bool4_zzz(*p); }
inline static stdmath_bool4 stdmath_bool4_zzz_set(stdmath_bool4* p, stdmath_bool3 value) { p->z = value.x; p->z = value.y; p->z = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_zzw(stdmath_bool4 v) { return {v.z,v.z,v.w}; }
inline static stdmath_bool3 stdmath_bool4_zzw_get(stdmath_bool4* p) { return stdmath_bool4_zzw(*p); }
inline static stdmath_bool4 stdmath_bool4_zzw_set(stdmath_bool4* p, stdmath_bool3 value) { p->z = value.x; p->z = value.y; p->w = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_zwx(stdmath_bool4 v) { return {v.z,v.w,v.x}; }
inline static stdmath_bool3 stdmath_bool4_zwx_get(stdmath_bool4* p) { return stdmath_bool4_zwx(*p); }
inline static stdmath_bool4 stdmath_bool4_zwx_set(stdmath_bool4* p, stdmath_bool3 value) { p->z = value.x; p->w = value.y; p->x = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_zwy(stdmath_bool4 v) { return {v.z,v.w,v.y}; }
inline static stdmath_bool3 stdmath_bool4_zwy_get(stdmath_bool4* p) { return stdmath_bool4_zwy(*p); }
inline static stdmath_bool4 stdmath_bool4_zwy_set(stdmath_bool4* p, stdmath_bool3 value) { p->z = value.x; p->w = value.y; p->y = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_zwz(stdmath_bool4 v) { return {v.z,v.w,v.z}; }
inline static stdmath_bool3 stdmath_bool4_zwz_get(stdmath_bool4* p) { return stdmath_bool4_zwz(*p); }
inline static stdmath_bool4 stdmath_bool4_zwz_set(stdmath_bool4* p, stdmath_bool3 value) { p->z = value.x; p->w = value.y; p->z = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_zww(stdmath_bool4 v) { return {v.z,v.w,v.w}; }
inline static stdmath_bool3 stdmath_bool4_zww_get(stdmath_bool4* p) { return stdmath_bool4_zww(*p); }
inline static stdmath_bool4 stdmath_bool4_zww_set(stdmath_bool4* p, stdmath_bool3 value) { p->z = value.x; p->w = value.y; p->w = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_wxx(stdmath_bool4 v) { return {v.w,v.x,v.x}; }
inline static stdmath_bool3 stdmath_bool4_wxx_get(stdmath_bool4* p) { return stdmath_bool4_wxx(*p); }
inline static stdmath_bool4 stdmath_bool4_wxx_set(stdmath_bool4* p, stdmath_bool3 value) { p->w = value.x; p->x = value.y; p->x = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_wxy(stdmath_bool4 v) { return {v.w,v.x,v.y}; }
inline static stdmath_bool3 stdmath_bool4_wxy_get(stdmath_bool4* p) { return stdmath_bool4_wxy(*p); }
inline static stdmath_bool4 stdmath_bool4_wxy_set(stdmath_bool4* p, stdmath_bool3 value) { p->w = value.x; p->x = value.y; p->y = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_wxz(stdmath_bool4 v) { return {v.w,v.x,v.z}; }
inline static stdmath_bool3 stdmath_bool4_wxz_get(stdmath_bool4* p) { return stdmath_bool4_wxz(*p); }
inline static stdmath_bool4 stdmath_bool4_wxz_set(stdmath_bool4* p, stdmath_bool3 value) { p->w = value.x; p->x = value.y; p->z = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_wxw(stdmath_bool4 v) { return {v.w,v.x,v.w}; }
inline static stdmath_bool3 stdmath_bool4_wxw_get(stdmath_bool4* p) { return stdmath_bool4_wxw(*p); }
inline static stdmath_bool4 stdmath_bool4_wxw_set(stdmath_bool4* p, stdmath_bool3 value) { p->w = value.x; p->x = value.y; p->w = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_wyx(stdmath_bool4 v) { return {v.w,v.y,v.x}; }
inline static stdmath_bool3 stdmath_bool4_wyx_get(stdmath_bool4* p) { return stdmath_bool4_wyx(*p); }
inline static stdmath_bool4 stdmath_bool4_wyx_set(stdmath_bool4* p, stdmath_bool3 value) { p->w = value.x; p->y = value.y; p->x = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_wyy(stdmath_bool4 v) { return {v.w,v.y,v.y}; }
inline static stdmath_bool3 stdmath_bool4_wyy_get(stdmath_bool4* p) { return stdmath_bool4_wyy(*p); }
inline static stdmath_bool4 stdmath_bool4_wyy_set(stdmath_bool4* p, stdmath_bool3 value) { p->w = value.x; p->y = value.y; p->y = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_wyz(stdmath_bool4 v) { return {v.w,v.y,v.z}; }
inline static stdmath_bool3 stdmath_bool4_wyz_get(stdmath_bool4* p) { return stdmath_bool4_wyz(*p); }
inline static stdmath_bool4 stdmath_bool4_wyz_set(stdmath_bool4* p, stdmath_bool3 value) { p->w = value.x; p->y = value.y; p->z = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_wyw(stdmath_bool4 v) { return {v.w,v.y,v.w}; }
inline static stdmath_bool3 stdmath_bool4_wyw_get(stdmath_bool4* p) { return stdmath_bool4_wyw(*p); }
inline static stdmath_bool4 stdmath_bool4_wyw_set(stdmath_bool4* p, stdmath_bool3 value) { p->w = value.x; p->y = value.y; p->w = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_wzx(stdmath_bool4 v) { return {v.w,v.z,v.x}; }
inline static stdmath_bool3 stdmath_bool4_wzx_get(stdmath_bool4* p) { return stdmath_bool4_wzx(*p); }
inline static stdmath_bool4 stdmath_bool4_wzx_set(stdmath_bool4* p, stdmath_bool3 value) { p->w = value.x; p->z = value.y; p->x = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_wzy(stdmath_bool4 v) { return {v.w,v.z,v.y}; }
inline static stdmath_bool3 stdmath_bool4_wzy_get(stdmath_bool4* p) { return stdmath_bool4_wzy(*p); }
inline static stdmath_bool4 stdmath_bool4_wzy_set(stdmath_bool4* p, stdmath_bool3 value) { p->w = value.x; p->z = value.y; p->y = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_wzz(stdmath_bool4 v) { return {v.w,v.z,v.z}; }
inline static stdmath_bool3 stdmath_bool4_wzz_get(stdmath_bool4* p) { return stdmath_bool4_wzz(*p); }
inline static stdmath_bool4 stdmath_bool4_wzz_set(stdmath_bool4* p, stdmath_bool3 value) { p->w = value.x; p->z = value.y; p->z = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_wzw(stdmath_bool4 v) { return {v.w,v.z,v.w}; }
inline static stdmath_bool3 stdmath_bool4_wzw_get(stdmath_bool4* p) { return stdmath_bool4_wzw(*p); }
inline static stdmath_bool4 stdmath_bool4_wzw_set(stdmath_bool4* p, stdmath_bool3 value) { p->w = value.x; p->z = value.y; p->w = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_wwx(stdmath_bool4 v) { return {v.w,v.w,v.x}; }
inline static stdmath_bool3 stdmath_bool4_wwx_get(stdmath_bool4* p) { return stdmath_bool4_wwx(*p); }
inline static stdmath_bool4 stdmath_bool4_wwx_set(stdmath_bool4* p, stdmath_bool3 value) { p->w = value.x; p->w = value.y; p->x = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_wwy(stdmath_bool4 v) { return {v.w,v.w,v.y}; }
inline static stdmath_bool3 stdmath_bool4_wwy_get(stdmath_bool4* p) { return stdmath_bool4_wwy(*p); }
inline static stdmath_bool4 stdmath_bool4_wwy_set(stdmath_bool4* p, stdmath_bool3 value) { p->w = value.x; p->w = value.y; p->y = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_wwz(stdmath_bool4 v) { return {v.w,v.w,v.z}; }
inline static stdmath_bool3 stdmath_bool4_wwz_get(stdmath_bool4* p) { return stdmath_bool4_wwz(*p); }
inline static stdmath_bool4 stdmath_bool4_wwz_set(stdmath_bool4* p, stdmath_bool3 value) { p->w = value.x; p->w = value.y; p->z = value.z; return *p; }
inline static stdmath_bool3 stdmath_bool4_www(stdmath_bool4 v) { return {v.w,v.w,v.w}; }
inline static stdmath_bool3 stdmath_bool4_www_get(stdmath_bool4* p) { return stdmath_bool4_www(*p); }
inline static stdmath_bool4 stdmath_bool4_www_set(stdmath_bool4* p, stdmath_bool3 value) { p->w = value.x; p->w = value.y; p->w = value.z; return *p; }
inline static stdmath_bool4 stdmath_bool4_xxxx(stdmath_bool4 v) { return {v.x,v.x,v.x,v.x}; }
inline static stdmath_bool4 stdmath_bool4_xxxx_get(stdmath_bool4* p) { return stdmath_bool4_xxxx(*p); }
inline static stdmath_bool4 stdmath_bool4_xxxx_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->x = value.y; p->x = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xxxy(stdmath_bool4 v) { return {v.x,v.x,v.x,v.y}; }
inline static stdmath_bool4 stdmath_bool4_xxxy_get(stdmath_bool4* p) { return stdmath_bool4_xxxy(*p); }
inline static stdmath_bool4 stdmath_bool4_xxxy_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->x = value.y; p->x = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xxxz(stdmath_bool4 v) { return {v.x,v.x,v.x,v.z}; }
inline static stdmath_bool4 stdmath_bool4_xxxz_get(stdmath_bool4* p) { return stdmath_bool4_xxxz(*p); }
inline static stdmath_bool4 stdmath_bool4_xxxz_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->x = value.y; p->x = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xxxw(stdmath_bool4 v) { return {v.x,v.x,v.x,v.w}; }
inline static stdmath_bool4 stdmath_bool4_xxxw_get(stdmath_bool4* p) { return stdmath_bool4_xxxw(*p); }
inline static stdmath_bool4 stdmath_bool4_xxxw_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->x = value.y; p->x = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xxyx(stdmath_bool4 v) { return {v.x,v.x,v.y,v.x}; }
inline static stdmath_bool4 stdmath_bool4_xxyx_get(stdmath_bool4* p) { return stdmath_bool4_xxyx(*p); }
inline static stdmath_bool4 stdmath_bool4_xxyx_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->x = value.y; p->y = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xxyy(stdmath_bool4 v) { return {v.x,v.x,v.y,v.y}; }
inline static stdmath_bool4 stdmath_bool4_xxyy_get(stdmath_bool4* p) { return stdmath_bool4_xxyy(*p); }
inline static stdmath_bool4 stdmath_bool4_xxyy_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->x = value.y; p->y = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xxyz(stdmath_bool4 v) { return {v.x,v.x,v.y,v.z}; }
inline static stdmath_bool4 stdmath_bool4_xxyz_get(stdmath_bool4* p) { return stdmath_bool4_xxyz(*p); }
inline static stdmath_bool4 stdmath_bool4_xxyz_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->x = value.y; p->y = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xxyw(stdmath_bool4 v) { return {v.x,v.x,v.y,v.w}; }
inline static stdmath_bool4 stdmath_bool4_xxyw_get(stdmath_bool4* p) { return stdmath_bool4_xxyw(*p); }
inline static stdmath_bool4 stdmath_bool4_xxyw_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->x = value.y; p->y = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xxzx(stdmath_bool4 v) { return {v.x,v.x,v.z,v.x}; }
inline static stdmath_bool4 stdmath_bool4_xxzx_get(stdmath_bool4* p) { return stdmath_bool4_xxzx(*p); }
inline static stdmath_bool4 stdmath_bool4_xxzx_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->x = value.y; p->z = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xxzy(stdmath_bool4 v) { return {v.x,v.x,v.z,v.y}; }
inline static stdmath_bool4 stdmath_bool4_xxzy_get(stdmath_bool4* p) { return stdmath_bool4_xxzy(*p); }
inline static stdmath_bool4 stdmath_bool4_xxzy_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->x = value.y; p->z = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xxzz(stdmath_bool4 v) { return {v.x,v.x,v.z,v.z}; }
inline static stdmath_bool4 stdmath_bool4_xxzz_get(stdmath_bool4* p) { return stdmath_bool4_xxzz(*p); }
inline static stdmath_bool4 stdmath_bool4_xxzz_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->x = value.y; p->z = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xxzw(stdmath_bool4 v) { return {v.x,v.x,v.z,v.w}; }
inline static stdmath_bool4 stdmath_bool4_xxzw_get(stdmath_bool4* p) { return stdmath_bool4_xxzw(*p); }
inline static stdmath_bool4 stdmath_bool4_xxzw_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->x = value.y; p->z = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xxwx(stdmath_bool4 v) { return {v.x,v.x,v.w,v.x}; }
inline static stdmath_bool4 stdmath_bool4_xxwx_get(stdmath_bool4* p) { return stdmath_bool4_xxwx(*p); }
inline static stdmath_bool4 stdmath_bool4_xxwx_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->x = value.y; p->w = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xxwy(stdmath_bool4 v) { return {v.x,v.x,v.w,v.y}; }
inline static stdmath_bool4 stdmath_bool4_xxwy_get(stdmath_bool4* p) { return stdmath_bool4_xxwy(*p); }
inline static stdmath_bool4 stdmath_bool4_xxwy_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->x = value.y; p->w = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xxwz(stdmath_bool4 v) { return {v.x,v.x,v.w,v.z}; }
inline static stdmath_bool4 stdmath_bool4_xxwz_get(stdmath_bool4* p) { return stdmath_bool4_xxwz(*p); }
inline static stdmath_bool4 stdmath_bool4_xxwz_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->x = value.y; p->w = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xxww(stdmath_bool4 v) { return {v.x,v.x,v.w,v.w}; }
inline static stdmath_bool4 stdmath_bool4_xxww_get(stdmath_bool4* p) { return stdmath_bool4_xxww(*p); }
inline static stdmath_bool4 stdmath_bool4_xxww_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->x = value.y; p->w = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xyxx(stdmath_bool4 v) { return {v.x,v.y,v.x,v.x}; }
inline static stdmath_bool4 stdmath_bool4_xyxx_get(stdmath_bool4* p) { return stdmath_bool4_xyxx(*p); }
inline static stdmath_bool4 stdmath_bool4_xyxx_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->y = value.y; p->x = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xyxy(stdmath_bool4 v) { return {v.x,v.y,v.x,v.y}; }
inline static stdmath_bool4 stdmath_bool4_xyxy_get(stdmath_bool4* p) { return stdmath_bool4_xyxy(*p); }
inline static stdmath_bool4 stdmath_bool4_xyxy_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->y = value.y; p->x = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xyxz(stdmath_bool4 v) { return {v.x,v.y,v.x,v.z}; }
inline static stdmath_bool4 stdmath_bool4_xyxz_get(stdmath_bool4* p) { return stdmath_bool4_xyxz(*p); }
inline static stdmath_bool4 stdmath_bool4_xyxz_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->y = value.y; p->x = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xyxw(stdmath_bool4 v) { return {v.x,v.y,v.x,v.w}; }
inline static stdmath_bool4 stdmath_bool4_xyxw_get(stdmath_bool4* p) { return stdmath_bool4_xyxw(*p); }
inline static stdmath_bool4 stdmath_bool4_xyxw_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->y = value.y; p->x = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xyyx(stdmath_bool4 v) { return {v.x,v.y,v.y,v.x}; }
inline static stdmath_bool4 stdmath_bool4_xyyx_get(stdmath_bool4* p) { return stdmath_bool4_xyyx(*p); }
inline static stdmath_bool4 stdmath_bool4_xyyx_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->y = value.y; p->y = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xyyy(stdmath_bool4 v) { return {v.x,v.y,v.y,v.y}; }
inline static stdmath_bool4 stdmath_bool4_xyyy_get(stdmath_bool4* p) { return stdmath_bool4_xyyy(*p); }
inline static stdmath_bool4 stdmath_bool4_xyyy_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->y = value.y; p->y = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xyyz(stdmath_bool4 v) { return {v.x,v.y,v.y,v.z}; }
inline static stdmath_bool4 stdmath_bool4_xyyz_get(stdmath_bool4* p) { return stdmath_bool4_xyyz(*p); }
inline static stdmath_bool4 stdmath_bool4_xyyz_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->y = value.y; p->y = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xyyw(stdmath_bool4 v) { return {v.x,v.y,v.y,v.w}; }
inline static stdmath_bool4 stdmath_bool4_xyyw_get(stdmath_bool4* p) { return stdmath_bool4_xyyw(*p); }
inline static stdmath_bool4 stdmath_bool4_xyyw_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->y = value.y; p->y = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xyzx(stdmath_bool4 v) { return {v.x,v.y,v.z,v.x}; }
inline static stdmath_bool4 stdmath_bool4_xyzx_get(stdmath_bool4* p) { return stdmath_bool4_xyzx(*p); }
inline static stdmath_bool4 stdmath_bool4_xyzx_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->y = value.y; p->z = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xyzy(stdmath_bool4 v) { return {v.x,v.y,v.z,v.y}; }
inline static stdmath_bool4 stdmath_bool4_xyzy_get(stdmath_bool4* p) { return stdmath_bool4_xyzy(*p); }
inline static stdmath_bool4 stdmath_bool4_xyzy_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->y = value.y; p->z = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xyzz(stdmath_bool4 v) { return {v.x,v.y,v.z,v.z}; }
inline static stdmath_bool4 stdmath_bool4_xyzz_get(stdmath_bool4* p) { return stdmath_bool4_xyzz(*p); }
inline static stdmath_bool4 stdmath_bool4_xyzz_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->y = value.y; p->z = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xyzw(stdmath_bool4 v) { return {v.x,v.y,v.z,v.w}; }
inline static stdmath_bool4 stdmath_bool4_xyzw_get(stdmath_bool4* p) { return stdmath_bool4_xyzw(*p); }
inline static stdmath_bool4 stdmath_bool4_xyzw_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->y = value.y; p->z = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xywx(stdmath_bool4 v) { return {v.x,v.y,v.w,v.x}; }
inline static stdmath_bool4 stdmath_bool4_xywx_get(stdmath_bool4* p) { return stdmath_bool4_xywx(*p); }
inline static stdmath_bool4 stdmath_bool4_xywx_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->y = value.y; p->w = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xywy(stdmath_bool4 v) { return {v.x,v.y,v.w,v.y}; }
inline static stdmath_bool4 stdmath_bool4_xywy_get(stdmath_bool4* p) { return stdmath_bool4_xywy(*p); }
inline static stdmath_bool4 stdmath_bool4_xywy_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->y = value.y; p->w = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xywz(stdmath_bool4 v) { return {v.x,v.y,v.w,v.z}; }
inline static stdmath_bool4 stdmath_bool4_xywz_get(stdmath_bool4* p) { return stdmath_bool4_xywz(*p); }
inline static stdmath_bool4 stdmath_bool4_xywz_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->y = value.y; p->w = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xyww(stdmath_bool4 v) { return {v.x,v.y,v.w,v.w}; }
inline static stdmath_bool4 stdmath_bool4_xyww_get(stdmath_bool4* p) { return stdmath_bool4_xyww(*p); }
inline static stdmath_bool4 stdmath_bool4_xyww_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->y = value.y; p->w = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xzxx(stdmath_bool4 v) { return {v.x,v.z,v.x,v.x}; }
inline static stdmath_bool4 stdmath_bool4_xzxx_get(stdmath_bool4* p) { return stdmath_bool4_xzxx(*p); }
inline static stdmath_bool4 stdmath_bool4_xzxx_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->z = value.y; p->x = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xzxy(stdmath_bool4 v) { return {v.x,v.z,v.x,v.y}; }
inline static stdmath_bool4 stdmath_bool4_xzxy_get(stdmath_bool4* p) { return stdmath_bool4_xzxy(*p); }
inline static stdmath_bool4 stdmath_bool4_xzxy_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->z = value.y; p->x = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xzxz(stdmath_bool4 v) { return {v.x,v.z,v.x,v.z}; }
inline static stdmath_bool4 stdmath_bool4_xzxz_get(stdmath_bool4* p) { return stdmath_bool4_xzxz(*p); }
inline static stdmath_bool4 stdmath_bool4_xzxz_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->z = value.y; p->x = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xzxw(stdmath_bool4 v) { return {v.x,v.z,v.x,v.w}; }
inline static stdmath_bool4 stdmath_bool4_xzxw_get(stdmath_bool4* p) { return stdmath_bool4_xzxw(*p); }
inline static stdmath_bool4 stdmath_bool4_xzxw_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->z = value.y; p->x = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xzyx(stdmath_bool4 v) { return {v.x,v.z,v.y,v.x}; }
inline static stdmath_bool4 stdmath_bool4_xzyx_get(stdmath_bool4* p) { return stdmath_bool4_xzyx(*p); }
inline static stdmath_bool4 stdmath_bool4_xzyx_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->z = value.y; p->y = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xzyy(stdmath_bool4 v) { return {v.x,v.z,v.y,v.y}; }
inline static stdmath_bool4 stdmath_bool4_xzyy_get(stdmath_bool4* p) { return stdmath_bool4_xzyy(*p); }
inline static stdmath_bool4 stdmath_bool4_xzyy_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->z = value.y; p->y = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xzyz(stdmath_bool4 v) { return {v.x,v.z,v.y,v.z}; }
inline static stdmath_bool4 stdmath_bool4_xzyz_get(stdmath_bool4* p) { return stdmath_bool4_xzyz(*p); }
inline static stdmath_bool4 stdmath_bool4_xzyz_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->z = value.y; p->y = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xzyw(stdmath_bool4 v) { return {v.x,v.z,v.y,v.w}; }
inline static stdmath_bool4 stdmath_bool4_xzyw_get(stdmath_bool4* p) { return stdmath_bool4_xzyw(*p); }
inline static stdmath_bool4 stdmath_bool4_xzyw_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->z = value.y; p->y = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xzzx(stdmath_bool4 v) { return {v.x,v.z,v.z,v.x}; }
inline static stdmath_bool4 stdmath_bool4_xzzx_get(stdmath_bool4* p) { return stdmath_bool4_xzzx(*p); }
inline static stdmath_bool4 stdmath_bool4_xzzx_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->z = value.y; p->z = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xzzy(stdmath_bool4 v) { return {v.x,v.z,v.z,v.y}; }
inline static stdmath_bool4 stdmath_bool4_xzzy_get(stdmath_bool4* p) { return stdmath_bool4_xzzy(*p); }
inline static stdmath_bool4 stdmath_bool4_xzzy_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->z = value.y; p->z = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xzzz(stdmath_bool4 v) { return {v.x,v.z,v.z,v.z}; }
inline static stdmath_bool4 stdmath_bool4_xzzz_get(stdmath_bool4* p) { return stdmath_bool4_xzzz(*p); }
inline static stdmath_bool4 stdmath_bool4_xzzz_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->z = value.y; p->z = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xzzw(stdmath_bool4 v) { return {v.x,v.z,v.z,v.w}; }
inline static stdmath_bool4 stdmath_bool4_xzzw_get(stdmath_bool4* p) { return stdmath_bool4_xzzw(*p); }
inline static stdmath_bool4 stdmath_bool4_xzzw_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->z = value.y; p->z = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xzwx(stdmath_bool4 v) { return {v.x,v.z,v.w,v.x}; }
inline static stdmath_bool4 stdmath_bool4_xzwx_get(stdmath_bool4* p) { return stdmath_bool4_xzwx(*p); }
inline static stdmath_bool4 stdmath_bool4_xzwx_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->z = value.y; p->w = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xzwy(stdmath_bool4 v) { return {v.x,v.z,v.w,v.y}; }
inline static stdmath_bool4 stdmath_bool4_xzwy_get(stdmath_bool4* p) { return stdmath_bool4_xzwy(*p); }
inline static stdmath_bool4 stdmath_bool4_xzwy_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->z = value.y; p->w = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xzwz(stdmath_bool4 v) { return {v.x,v.z,v.w,v.z}; }
inline static stdmath_bool4 stdmath_bool4_xzwz_get(stdmath_bool4* p) { return stdmath_bool4_xzwz(*p); }
inline static stdmath_bool4 stdmath_bool4_xzwz_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->z = value.y; p->w = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xzww(stdmath_bool4 v) { return {v.x,v.z,v.w,v.w}; }
inline static stdmath_bool4 stdmath_bool4_xzww_get(stdmath_bool4* p) { return stdmath_bool4_xzww(*p); }
inline static stdmath_bool4 stdmath_bool4_xzww_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->z = value.y; p->w = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xwxx(stdmath_bool4 v) { return {v.x,v.w,v.x,v.x}; }
inline static stdmath_bool4 stdmath_bool4_xwxx_get(stdmath_bool4* p) { return stdmath_bool4_xwxx(*p); }
inline static stdmath_bool4 stdmath_bool4_xwxx_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->w = value.y; p->x = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xwxy(stdmath_bool4 v) { return {v.x,v.w,v.x,v.y}; }
inline static stdmath_bool4 stdmath_bool4_xwxy_get(stdmath_bool4* p) { return stdmath_bool4_xwxy(*p); }
inline static stdmath_bool4 stdmath_bool4_xwxy_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->w = value.y; p->x = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xwxz(stdmath_bool4 v) { return {v.x,v.w,v.x,v.z}; }
inline static stdmath_bool4 stdmath_bool4_xwxz_get(stdmath_bool4* p) { return stdmath_bool4_xwxz(*p); }
inline static stdmath_bool4 stdmath_bool4_xwxz_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->w = value.y; p->x = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xwxw(stdmath_bool4 v) { return {v.x,v.w,v.x,v.w}; }
inline static stdmath_bool4 stdmath_bool4_xwxw_get(stdmath_bool4* p) { return stdmath_bool4_xwxw(*p); }
inline static stdmath_bool4 stdmath_bool4_xwxw_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->w = value.y; p->x = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xwyx(stdmath_bool4 v) { return {v.x,v.w,v.y,v.x}; }
inline static stdmath_bool4 stdmath_bool4_xwyx_get(stdmath_bool4* p) { return stdmath_bool4_xwyx(*p); }
inline static stdmath_bool4 stdmath_bool4_xwyx_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->w = value.y; p->y = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xwyy(stdmath_bool4 v) { return {v.x,v.w,v.y,v.y}; }
inline static stdmath_bool4 stdmath_bool4_xwyy_get(stdmath_bool4* p) { return stdmath_bool4_xwyy(*p); }
inline static stdmath_bool4 stdmath_bool4_xwyy_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->w = value.y; p->y = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xwyz(stdmath_bool4 v) { return {v.x,v.w,v.y,v.z}; }
inline static stdmath_bool4 stdmath_bool4_xwyz_get(stdmath_bool4* p) { return stdmath_bool4_xwyz(*p); }
inline static stdmath_bool4 stdmath_bool4_xwyz_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->w = value.y; p->y = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xwyw(stdmath_bool4 v) { return {v.x,v.w,v.y,v.w}; }
inline static stdmath_bool4 stdmath_bool4_xwyw_get(stdmath_bool4* p) { return stdmath_bool4_xwyw(*p); }
inline static stdmath_bool4 stdmath_bool4_xwyw_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->w = value.y; p->y = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xwzx(stdmath_bool4 v) { return {v.x,v.w,v.z,v.x}; }
inline static stdmath_bool4 stdmath_bool4_xwzx_get(stdmath_bool4* p) { return stdmath_bool4_xwzx(*p); }
inline static stdmath_bool4 stdmath_bool4_xwzx_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->w = value.y; p->z = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xwzy(stdmath_bool4 v) { return {v.x,v.w,v.z,v.y}; }
inline static stdmath_bool4 stdmath_bool4_xwzy_get(stdmath_bool4* p) { return stdmath_bool4_xwzy(*p); }
inline static stdmath_bool4 stdmath_bool4_xwzy_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->w = value.y; p->z = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xwzz(stdmath_bool4 v) { return {v.x,v.w,v.z,v.z}; }
inline static stdmath_bool4 stdmath_bool4_xwzz_get(stdmath_bool4* p) { return stdmath_bool4_xwzz(*p); }
inline static stdmath_bool4 stdmath_bool4_xwzz_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->w = value.y; p->z = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xwzw(stdmath_bool4 v) { return {v.x,v.w,v.z,v.w}; }
inline static stdmath_bool4 stdmath_bool4_xwzw_get(stdmath_bool4* p) { return stdmath_bool4_xwzw(*p); }
inline static stdmath_bool4 stdmath_bool4_xwzw_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->w = value.y; p->z = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xwwx(stdmath_bool4 v) { return {v.x,v.w,v.w,v.x}; }
inline static stdmath_bool4 stdmath_bool4_xwwx_get(stdmath_bool4* p) { return stdmath_bool4_xwwx(*p); }
inline static stdmath_bool4 stdmath_bool4_xwwx_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->w = value.y; p->w = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xwwy(stdmath_bool4 v) { return {v.x,v.w,v.w,v.y}; }
inline static stdmath_bool4 stdmath_bool4_xwwy_get(stdmath_bool4* p) { return stdmath_bool4_xwwy(*p); }
inline static stdmath_bool4 stdmath_bool4_xwwy_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->w = value.y; p->w = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xwwz(stdmath_bool4 v) { return {v.x,v.w,v.w,v.z}; }
inline static stdmath_bool4 stdmath_bool4_xwwz_get(stdmath_bool4* p) { return stdmath_bool4_xwwz(*p); }
inline static stdmath_bool4 stdmath_bool4_xwwz_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->w = value.y; p->w = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_xwww(stdmath_bool4 v) { return {v.x,v.w,v.w,v.w}; }
inline static stdmath_bool4 stdmath_bool4_xwww_get(stdmath_bool4* p) { return stdmath_bool4_xwww(*p); }
inline static stdmath_bool4 stdmath_bool4_xwww_set(stdmath_bool4* p, stdmath_bool4 value) { p->x = value.x; p->w = value.y; p->w = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_yxxx(stdmath_bool4 v) { return {v.y,v.x,v.x,v.x}; }
inline static stdmath_bool4 stdmath_bool4_yxxx_get(stdmath_bool4* p) { return stdmath_bool4_yxxx(*p); }
inline static stdmath_bool4 stdmath_bool4_yxxx_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->x = value.y; p->x = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_yxxy(stdmath_bool4 v) { return {v.y,v.x,v.x,v.y}; }
inline static stdmath_bool4 stdmath_bool4_yxxy_get(stdmath_bool4* p) { return stdmath_bool4_yxxy(*p); }
inline static stdmath_bool4 stdmath_bool4_yxxy_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->x = value.y; p->x = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_yxxz(stdmath_bool4 v) { return {v.y,v.x,v.x,v.z}; }
inline static stdmath_bool4 stdmath_bool4_yxxz_get(stdmath_bool4* p) { return stdmath_bool4_yxxz(*p); }
inline static stdmath_bool4 stdmath_bool4_yxxz_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->x = value.y; p->x = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_yxxw(stdmath_bool4 v) { return {v.y,v.x,v.x,v.w}; }
inline static stdmath_bool4 stdmath_bool4_yxxw_get(stdmath_bool4* p) { return stdmath_bool4_yxxw(*p); }
inline static stdmath_bool4 stdmath_bool4_yxxw_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->x = value.y; p->x = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_yxyx(stdmath_bool4 v) { return {v.y,v.x,v.y,v.x}; }
inline static stdmath_bool4 stdmath_bool4_yxyx_get(stdmath_bool4* p) { return stdmath_bool4_yxyx(*p); }
inline static stdmath_bool4 stdmath_bool4_yxyx_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->x = value.y; p->y = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_yxyy(stdmath_bool4 v) { return {v.y,v.x,v.y,v.y}; }
inline static stdmath_bool4 stdmath_bool4_yxyy_get(stdmath_bool4* p) { return stdmath_bool4_yxyy(*p); }
inline static stdmath_bool4 stdmath_bool4_yxyy_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->x = value.y; p->y = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_yxyz(stdmath_bool4 v) { return {v.y,v.x,v.y,v.z}; }
inline static stdmath_bool4 stdmath_bool4_yxyz_get(stdmath_bool4* p) { return stdmath_bool4_yxyz(*p); }
inline static stdmath_bool4 stdmath_bool4_yxyz_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->x = value.y; p->y = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_yxyw(stdmath_bool4 v) { return {v.y,v.x,v.y,v.w}; }
inline static stdmath_bool4 stdmath_bool4_yxyw_get(stdmath_bool4* p) { return stdmath_bool4_yxyw(*p); }
inline static stdmath_bool4 stdmath_bool4_yxyw_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->x = value.y; p->y = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_yxzx(stdmath_bool4 v) { return {v.y,v.x,v.z,v.x}; }
inline static stdmath_bool4 stdmath_bool4_yxzx_get(stdmath_bool4* p) { return stdmath_bool4_yxzx(*p); }
inline static stdmath_bool4 stdmath_bool4_yxzx_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->x = value.y; p->z = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_yxzy(stdmath_bool4 v) { return {v.y,v.x,v.z,v.y}; }
inline static stdmath_bool4 stdmath_bool4_yxzy_get(stdmath_bool4* p) { return stdmath_bool4_yxzy(*p); }
inline static stdmath_bool4 stdmath_bool4_yxzy_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->x = value.y; p->z = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_yxzz(stdmath_bool4 v) { return {v.y,v.x,v.z,v.z}; }
inline static stdmath_bool4 stdmath_bool4_yxzz_get(stdmath_bool4* p) { return stdmath_bool4_yxzz(*p); }
inline static stdmath_bool4 stdmath_bool4_yxzz_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->x = value.y; p->z = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_yxzw(stdmath_bool4 v) { return {v.y,v.x,v.z,v.w}; }
inline static stdmath_bool4 stdmath_bool4_yxzw_get(stdmath_bool4* p) { return stdmath_bool4_yxzw(*p); }
inline static stdmath_bool4 stdmath_bool4_yxzw_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->x = value.y; p->z = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_yxwx(stdmath_bool4 v) { return {v.y,v.x,v.w,v.x}; }
inline static stdmath_bool4 stdmath_bool4_yxwx_get(stdmath_bool4* p) { return stdmath_bool4_yxwx(*p); }
inline static stdmath_bool4 stdmath_bool4_yxwx_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->x = value.y; p->w = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_yxwy(stdmath_bool4 v) { return {v.y,v.x,v.w,v.y}; }
inline static stdmath_bool4 stdmath_bool4_yxwy_get(stdmath_bool4* p) { return stdmath_bool4_yxwy(*p); }
inline static stdmath_bool4 stdmath_bool4_yxwy_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->x = value.y; p->w = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_yxwz(stdmath_bool4 v) { return {v.y,v.x,v.w,v.z}; }
inline static stdmath_bool4 stdmath_bool4_yxwz_get(stdmath_bool4* p) { return stdmath_bool4_yxwz(*p); }
inline static stdmath_bool4 stdmath_bool4_yxwz_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->x = value.y; p->w = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_yxww(stdmath_bool4 v) { return {v.y,v.x,v.w,v.w}; }
inline static stdmath_bool4 stdmath_bool4_yxww_get(stdmath_bool4* p) { return stdmath_bool4_yxww(*p); }
inline static stdmath_bool4 stdmath_bool4_yxww_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->x = value.y; p->w = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_yyxx(stdmath_bool4 v) { return {v.y,v.y,v.x,v.x}; }
inline static stdmath_bool4 stdmath_bool4_yyxx_get(stdmath_bool4* p) { return stdmath_bool4_yyxx(*p); }
inline static stdmath_bool4 stdmath_bool4_yyxx_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->y = value.y; p->x = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_yyxy(stdmath_bool4 v) { return {v.y,v.y,v.x,v.y}; }
inline static stdmath_bool4 stdmath_bool4_yyxy_get(stdmath_bool4* p) { return stdmath_bool4_yyxy(*p); }
inline static stdmath_bool4 stdmath_bool4_yyxy_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->y = value.y; p->x = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_yyxz(stdmath_bool4 v) { return {v.y,v.y,v.x,v.z}; }
inline static stdmath_bool4 stdmath_bool4_yyxz_get(stdmath_bool4* p) { return stdmath_bool4_yyxz(*p); }
inline static stdmath_bool4 stdmath_bool4_yyxz_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->y = value.y; p->x = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_yyxw(stdmath_bool4 v) { return {v.y,v.y,v.x,v.w}; }
inline static stdmath_bool4 stdmath_bool4_yyxw_get(stdmath_bool4* p) { return stdmath_bool4_yyxw(*p); }
inline static stdmath_bool4 stdmath_bool4_yyxw_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->y = value.y; p->x = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_yyyx(stdmath_bool4 v) { return {v.y,v.y,v.y,v.x}; }
inline static stdmath_bool4 stdmath_bool4_yyyx_get(stdmath_bool4* p) { return stdmath_bool4_yyyx(*p); }
inline static stdmath_bool4 stdmath_bool4_yyyx_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->y = value.y; p->y = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_yyyy(stdmath_bool4 v) { return {v.y,v.y,v.y,v.y}; }
inline static stdmath_bool4 stdmath_bool4_yyyy_get(stdmath_bool4* p) { return stdmath_bool4_yyyy(*p); }
inline static stdmath_bool4 stdmath_bool4_yyyy_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->y = value.y; p->y = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_yyyz(stdmath_bool4 v) { return {v.y,v.y,v.y,v.z}; }
inline static stdmath_bool4 stdmath_bool4_yyyz_get(stdmath_bool4* p) { return stdmath_bool4_yyyz(*p); }
inline static stdmath_bool4 stdmath_bool4_yyyz_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->y = value.y; p->y = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_yyyw(stdmath_bool4 v) { return {v.y,v.y,v.y,v.w}; }
inline static stdmath_bool4 stdmath_bool4_yyyw_get(stdmath_bool4* p) { return stdmath_bool4_yyyw(*p); }
inline static stdmath_bool4 stdmath_bool4_yyyw_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->y = value.y; p->y = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_yyzx(stdmath_bool4 v) { return {v.y,v.y,v.z,v.x}; }
inline static stdmath_bool4 stdmath_bool4_yyzx_get(stdmath_bool4* p) { return stdmath_bool4_yyzx(*p); }
inline static stdmath_bool4 stdmath_bool4_yyzx_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->y = value.y; p->z = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_yyzy(stdmath_bool4 v) { return {v.y,v.y,v.z,v.y}; }
inline static stdmath_bool4 stdmath_bool4_yyzy_get(stdmath_bool4* p) { return stdmath_bool4_yyzy(*p); }
inline static stdmath_bool4 stdmath_bool4_yyzy_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->y = value.y; p->z = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_yyzz(stdmath_bool4 v) { return {v.y,v.y,v.z,v.z}; }
inline static stdmath_bool4 stdmath_bool4_yyzz_get(stdmath_bool4* p) { return stdmath_bool4_yyzz(*p); }
inline static stdmath_bool4 stdmath_bool4_yyzz_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->y = value.y; p->z = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_yyzw(stdmath_bool4 v) { return {v.y,v.y,v.z,v.w}; }
inline static stdmath_bool4 stdmath_bool4_yyzw_get(stdmath_bool4* p) { return stdmath_bool4_yyzw(*p); }
inline static stdmath_bool4 stdmath_bool4_yyzw_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->y = value.y; p->z = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_yywx(stdmath_bool4 v) { return {v.y,v.y,v.w,v.x}; }
inline static stdmath_bool4 stdmath_bool4_yywx_get(stdmath_bool4* p) { return stdmath_bool4_yywx(*p); }
inline static stdmath_bool4 stdmath_bool4_yywx_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->y = value.y; p->w = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_yywy(stdmath_bool4 v) { return {v.y,v.y,v.w,v.y}; }
inline static stdmath_bool4 stdmath_bool4_yywy_get(stdmath_bool4* p) { return stdmath_bool4_yywy(*p); }
inline static stdmath_bool4 stdmath_bool4_yywy_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->y = value.y; p->w = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_yywz(stdmath_bool4 v) { return {v.y,v.y,v.w,v.z}; }
inline static stdmath_bool4 stdmath_bool4_yywz_get(stdmath_bool4* p) { return stdmath_bool4_yywz(*p); }
inline static stdmath_bool4 stdmath_bool4_yywz_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->y = value.y; p->w = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_yyww(stdmath_bool4 v) { return {v.y,v.y,v.w,v.w}; }
inline static stdmath_bool4 stdmath_bool4_yyww_get(stdmath_bool4* p) { return stdmath_bool4_yyww(*p); }
inline static stdmath_bool4 stdmath_bool4_yyww_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->y = value.y; p->w = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_yzxx(stdmath_bool4 v) { return {v.y,v.z,v.x,v.x}; }
inline static stdmath_bool4 stdmath_bool4_yzxx_get(stdmath_bool4* p) { return stdmath_bool4_yzxx(*p); }
inline static stdmath_bool4 stdmath_bool4_yzxx_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->z = value.y; p->x = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_yzxy(stdmath_bool4 v) { return {v.y,v.z,v.x,v.y}; }
inline static stdmath_bool4 stdmath_bool4_yzxy_get(stdmath_bool4* p) { return stdmath_bool4_yzxy(*p); }
inline static stdmath_bool4 stdmath_bool4_yzxy_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->z = value.y; p->x = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_yzxz(stdmath_bool4 v) { return {v.y,v.z,v.x,v.z}; }
inline static stdmath_bool4 stdmath_bool4_yzxz_get(stdmath_bool4* p) { return stdmath_bool4_yzxz(*p); }
inline static stdmath_bool4 stdmath_bool4_yzxz_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->z = value.y; p->x = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_yzxw(stdmath_bool4 v) { return {v.y,v.z,v.x,v.w}; }
inline static stdmath_bool4 stdmath_bool4_yzxw_get(stdmath_bool4* p) { return stdmath_bool4_yzxw(*p); }
inline static stdmath_bool4 stdmath_bool4_yzxw_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->z = value.y; p->x = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_yzyx(stdmath_bool4 v) { return {v.y,v.z,v.y,v.x}; }
inline static stdmath_bool4 stdmath_bool4_yzyx_get(stdmath_bool4* p) { return stdmath_bool4_yzyx(*p); }
inline static stdmath_bool4 stdmath_bool4_yzyx_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->z = value.y; p->y = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_yzyy(stdmath_bool4 v) { return {v.y,v.z,v.y,v.y}; }
inline static stdmath_bool4 stdmath_bool4_yzyy_get(stdmath_bool4* p) { return stdmath_bool4_yzyy(*p); }
inline static stdmath_bool4 stdmath_bool4_yzyy_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->z = value.y; p->y = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_yzyz(stdmath_bool4 v) { return {v.y,v.z,v.y,v.z}; }
inline static stdmath_bool4 stdmath_bool4_yzyz_get(stdmath_bool4* p) { return stdmath_bool4_yzyz(*p); }
inline static stdmath_bool4 stdmath_bool4_yzyz_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->z = value.y; p->y = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_yzyw(stdmath_bool4 v) { return {v.y,v.z,v.y,v.w}; }
inline static stdmath_bool4 stdmath_bool4_yzyw_get(stdmath_bool4* p) { return stdmath_bool4_yzyw(*p); }
inline static stdmath_bool4 stdmath_bool4_yzyw_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->z = value.y; p->y = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_yzzx(stdmath_bool4 v) { return {v.y,v.z,v.z,v.x}; }
inline static stdmath_bool4 stdmath_bool4_yzzx_get(stdmath_bool4* p) { return stdmath_bool4_yzzx(*p); }
inline static stdmath_bool4 stdmath_bool4_yzzx_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->z = value.y; p->z = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_yzzy(stdmath_bool4 v) { return {v.y,v.z,v.z,v.y}; }
inline static stdmath_bool4 stdmath_bool4_yzzy_get(stdmath_bool4* p) { return stdmath_bool4_yzzy(*p); }
inline static stdmath_bool4 stdmath_bool4_yzzy_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->z = value.y; p->z = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_yzzz(stdmath_bool4 v) { return {v.y,v.z,v.z,v.z}; }
inline static stdmath_bool4 stdmath_bool4_yzzz_get(stdmath_bool4* p) { return stdmath_bool4_yzzz(*p); }
inline static stdmath_bool4 stdmath_bool4_yzzz_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->z = value.y; p->z = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_yzzw(stdmath_bool4 v) { return {v.y,v.z,v.z,v.w}; }
inline static stdmath_bool4 stdmath_bool4_yzzw_get(stdmath_bool4* p) { return stdmath_bool4_yzzw(*p); }
inline static stdmath_bool4 stdmath_bool4_yzzw_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->z = value.y; p->z = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_yzwx(stdmath_bool4 v) { return {v.y,v.z,v.w,v.x}; }
inline static stdmath_bool4 stdmath_bool4_yzwx_get(stdmath_bool4* p) { return stdmath_bool4_yzwx(*p); }
inline static stdmath_bool4 stdmath_bool4_yzwx_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->z = value.y; p->w = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_yzwy(stdmath_bool4 v) { return {v.y,v.z,v.w,v.y}; }
inline static stdmath_bool4 stdmath_bool4_yzwy_get(stdmath_bool4* p) { return stdmath_bool4_yzwy(*p); }
inline static stdmath_bool4 stdmath_bool4_yzwy_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->z = value.y; p->w = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_yzwz(stdmath_bool4 v) { return {v.y,v.z,v.w,v.z}; }
inline static stdmath_bool4 stdmath_bool4_yzwz_get(stdmath_bool4* p) { return stdmath_bool4_yzwz(*p); }
inline static stdmath_bool4 stdmath_bool4_yzwz_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->z = value.y; p->w = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_yzww(stdmath_bool4 v) { return {v.y,v.z,v.w,v.w}; }
inline static stdmath_bool4 stdmath_bool4_yzww_get(stdmath_bool4* p) { return stdmath_bool4_yzww(*p); }
inline static stdmath_bool4 stdmath_bool4_yzww_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->z = value.y; p->w = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_ywxx(stdmath_bool4 v) { return {v.y,v.w,v.x,v.x}; }
inline static stdmath_bool4 stdmath_bool4_ywxx_get(stdmath_bool4* p) { return stdmath_bool4_ywxx(*p); }
inline static stdmath_bool4 stdmath_bool4_ywxx_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->w = value.y; p->x = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_ywxy(stdmath_bool4 v) { return {v.y,v.w,v.x,v.y}; }
inline static stdmath_bool4 stdmath_bool4_ywxy_get(stdmath_bool4* p) { return stdmath_bool4_ywxy(*p); }
inline static stdmath_bool4 stdmath_bool4_ywxy_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->w = value.y; p->x = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_ywxz(stdmath_bool4 v) { return {v.y,v.w,v.x,v.z}; }
inline static stdmath_bool4 stdmath_bool4_ywxz_get(stdmath_bool4* p) { return stdmath_bool4_ywxz(*p); }
inline static stdmath_bool4 stdmath_bool4_ywxz_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->w = value.y; p->x = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_ywxw(stdmath_bool4 v) { return {v.y,v.w,v.x,v.w}; }
inline static stdmath_bool4 stdmath_bool4_ywxw_get(stdmath_bool4* p) { return stdmath_bool4_ywxw(*p); }
inline static stdmath_bool4 stdmath_bool4_ywxw_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->w = value.y; p->x = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_ywyx(stdmath_bool4 v) { return {v.y,v.w,v.y,v.x}; }
inline static stdmath_bool4 stdmath_bool4_ywyx_get(stdmath_bool4* p) { return stdmath_bool4_ywyx(*p); }
inline static stdmath_bool4 stdmath_bool4_ywyx_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->w = value.y; p->y = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_ywyy(stdmath_bool4 v) { return {v.y,v.w,v.y,v.y}; }
inline static stdmath_bool4 stdmath_bool4_ywyy_get(stdmath_bool4* p) { return stdmath_bool4_ywyy(*p); }
inline static stdmath_bool4 stdmath_bool4_ywyy_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->w = value.y; p->y = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_ywyz(stdmath_bool4 v) { return {v.y,v.w,v.y,v.z}; }
inline static stdmath_bool4 stdmath_bool4_ywyz_get(stdmath_bool4* p) { return stdmath_bool4_ywyz(*p); }
inline static stdmath_bool4 stdmath_bool4_ywyz_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->w = value.y; p->y = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_ywyw(stdmath_bool4 v) { return {v.y,v.w,v.y,v.w}; }
inline static stdmath_bool4 stdmath_bool4_ywyw_get(stdmath_bool4* p) { return stdmath_bool4_ywyw(*p); }
inline static stdmath_bool4 stdmath_bool4_ywyw_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->w = value.y; p->y = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_ywzx(stdmath_bool4 v) { return {v.y,v.w,v.z,v.x}; }
inline static stdmath_bool4 stdmath_bool4_ywzx_get(stdmath_bool4* p) { return stdmath_bool4_ywzx(*p); }
inline static stdmath_bool4 stdmath_bool4_ywzx_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->w = value.y; p->z = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_ywzy(stdmath_bool4 v) { return {v.y,v.w,v.z,v.y}; }
inline static stdmath_bool4 stdmath_bool4_ywzy_get(stdmath_bool4* p) { return stdmath_bool4_ywzy(*p); }
inline static stdmath_bool4 stdmath_bool4_ywzy_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->w = value.y; p->z = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_ywzz(stdmath_bool4 v) { return {v.y,v.w,v.z,v.z}; }
inline static stdmath_bool4 stdmath_bool4_ywzz_get(stdmath_bool4* p) { return stdmath_bool4_ywzz(*p); }
inline static stdmath_bool4 stdmath_bool4_ywzz_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->w = value.y; p->z = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_ywzw(stdmath_bool4 v) { return {v.y,v.w,v.z,v.w}; }
inline static stdmath_bool4 stdmath_bool4_ywzw_get(stdmath_bool4* p) { return stdmath_bool4_ywzw(*p); }
inline static stdmath_bool4 stdmath_bool4_ywzw_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->w = value.y; p->z = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_ywwx(stdmath_bool4 v) { return {v.y,v.w,v.w,v.x}; }
inline static stdmath_bool4 stdmath_bool4_ywwx_get(stdmath_bool4* p) { return stdmath_bool4_ywwx(*p); }
inline static stdmath_bool4 stdmath_bool4_ywwx_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->w = value.y; p->w = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_ywwy(stdmath_bool4 v) { return {v.y,v.w,v.w,v.y}; }
inline static stdmath_bool4 stdmath_bool4_ywwy_get(stdmath_bool4* p) { return stdmath_bool4_ywwy(*p); }
inline static stdmath_bool4 stdmath_bool4_ywwy_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->w = value.y; p->w = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_ywwz(stdmath_bool4 v) { return {v.y,v.w,v.w,v.z}; }
inline static stdmath_bool4 stdmath_bool4_ywwz_get(stdmath_bool4* p) { return stdmath_bool4_ywwz(*p); }
inline static stdmath_bool4 stdmath_bool4_ywwz_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->w = value.y; p->w = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_ywww(stdmath_bool4 v) { return {v.y,v.w,v.w,v.w}; }
inline static stdmath_bool4 stdmath_bool4_ywww_get(stdmath_bool4* p) { return stdmath_bool4_ywww(*p); }
inline static stdmath_bool4 stdmath_bool4_ywww_set(stdmath_bool4* p, stdmath_bool4 value) { p->y = value.x; p->w = value.y; p->w = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zxxx(stdmath_bool4 v) { return {v.z,v.x,v.x,v.x}; }
inline static stdmath_bool4 stdmath_bool4_zxxx_get(stdmath_bool4* p) { return stdmath_bool4_zxxx(*p); }
inline static stdmath_bool4 stdmath_bool4_zxxx_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->x = value.y; p->x = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zxxy(stdmath_bool4 v) { return {v.z,v.x,v.x,v.y}; }
inline static stdmath_bool4 stdmath_bool4_zxxy_get(stdmath_bool4* p) { return stdmath_bool4_zxxy(*p); }
inline static stdmath_bool4 stdmath_bool4_zxxy_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->x = value.y; p->x = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zxxz(stdmath_bool4 v) { return {v.z,v.x,v.x,v.z}; }
inline static stdmath_bool4 stdmath_bool4_zxxz_get(stdmath_bool4* p) { return stdmath_bool4_zxxz(*p); }
inline static stdmath_bool4 stdmath_bool4_zxxz_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->x = value.y; p->x = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zxxw(stdmath_bool4 v) { return {v.z,v.x,v.x,v.w}; }
inline static stdmath_bool4 stdmath_bool4_zxxw_get(stdmath_bool4* p) { return stdmath_bool4_zxxw(*p); }
inline static stdmath_bool4 stdmath_bool4_zxxw_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->x = value.y; p->x = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zxyx(stdmath_bool4 v) { return {v.z,v.x,v.y,v.x}; }
inline static stdmath_bool4 stdmath_bool4_zxyx_get(stdmath_bool4* p) { return stdmath_bool4_zxyx(*p); }
inline static stdmath_bool4 stdmath_bool4_zxyx_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->x = value.y; p->y = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zxyy(stdmath_bool4 v) { return {v.z,v.x,v.y,v.y}; }
inline static stdmath_bool4 stdmath_bool4_zxyy_get(stdmath_bool4* p) { return stdmath_bool4_zxyy(*p); }
inline static stdmath_bool4 stdmath_bool4_zxyy_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->x = value.y; p->y = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zxyz(stdmath_bool4 v) { return {v.z,v.x,v.y,v.z}; }
inline static stdmath_bool4 stdmath_bool4_zxyz_get(stdmath_bool4* p) { return stdmath_bool4_zxyz(*p); }
inline static stdmath_bool4 stdmath_bool4_zxyz_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->x = value.y; p->y = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zxyw(stdmath_bool4 v) { return {v.z,v.x,v.y,v.w}; }
inline static stdmath_bool4 stdmath_bool4_zxyw_get(stdmath_bool4* p) { return stdmath_bool4_zxyw(*p); }
inline static stdmath_bool4 stdmath_bool4_zxyw_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->x = value.y; p->y = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zxzx(stdmath_bool4 v) { return {v.z,v.x,v.z,v.x}; }
inline static stdmath_bool4 stdmath_bool4_zxzx_get(stdmath_bool4* p) { return stdmath_bool4_zxzx(*p); }
inline static stdmath_bool4 stdmath_bool4_zxzx_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->x = value.y; p->z = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zxzy(stdmath_bool4 v) { return {v.z,v.x,v.z,v.y}; }
inline static stdmath_bool4 stdmath_bool4_zxzy_get(stdmath_bool4* p) { return stdmath_bool4_zxzy(*p); }
inline static stdmath_bool4 stdmath_bool4_zxzy_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->x = value.y; p->z = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zxzz(stdmath_bool4 v) { return {v.z,v.x,v.z,v.z}; }
inline static stdmath_bool4 stdmath_bool4_zxzz_get(stdmath_bool4* p) { return stdmath_bool4_zxzz(*p); }
inline static stdmath_bool4 stdmath_bool4_zxzz_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->x = value.y; p->z = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zxzw(stdmath_bool4 v) { return {v.z,v.x,v.z,v.w}; }
inline static stdmath_bool4 stdmath_bool4_zxzw_get(stdmath_bool4* p) { return stdmath_bool4_zxzw(*p); }
inline static stdmath_bool4 stdmath_bool4_zxzw_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->x = value.y; p->z = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zxwx(stdmath_bool4 v) { return {v.z,v.x,v.w,v.x}; }
inline static stdmath_bool4 stdmath_bool4_zxwx_get(stdmath_bool4* p) { return stdmath_bool4_zxwx(*p); }
inline static stdmath_bool4 stdmath_bool4_zxwx_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->x = value.y; p->w = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zxwy(stdmath_bool4 v) { return {v.z,v.x,v.w,v.y}; }
inline static stdmath_bool4 stdmath_bool4_zxwy_get(stdmath_bool4* p) { return stdmath_bool4_zxwy(*p); }
inline static stdmath_bool4 stdmath_bool4_zxwy_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->x = value.y; p->w = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zxwz(stdmath_bool4 v) { return {v.z,v.x,v.w,v.z}; }
inline static stdmath_bool4 stdmath_bool4_zxwz_get(stdmath_bool4* p) { return stdmath_bool4_zxwz(*p); }
inline static stdmath_bool4 stdmath_bool4_zxwz_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->x = value.y; p->w = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zxww(stdmath_bool4 v) { return {v.z,v.x,v.w,v.w}; }
inline static stdmath_bool4 stdmath_bool4_zxww_get(stdmath_bool4* p) { return stdmath_bool4_zxww(*p); }
inline static stdmath_bool4 stdmath_bool4_zxww_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->x = value.y; p->w = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zyxx(stdmath_bool4 v) { return {v.z,v.y,v.x,v.x}; }
inline static stdmath_bool4 stdmath_bool4_zyxx_get(stdmath_bool4* p) { return stdmath_bool4_zyxx(*p); }
inline static stdmath_bool4 stdmath_bool4_zyxx_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->y = value.y; p->x = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zyxy(stdmath_bool4 v) { return {v.z,v.y,v.x,v.y}; }
inline static stdmath_bool4 stdmath_bool4_zyxy_get(stdmath_bool4* p) { return stdmath_bool4_zyxy(*p); }
inline static stdmath_bool4 stdmath_bool4_zyxy_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->y = value.y; p->x = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zyxz(stdmath_bool4 v) { return {v.z,v.y,v.x,v.z}; }
inline static stdmath_bool4 stdmath_bool4_zyxz_get(stdmath_bool4* p) { return stdmath_bool4_zyxz(*p); }
inline static stdmath_bool4 stdmath_bool4_zyxz_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->y = value.y; p->x = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zyxw(stdmath_bool4 v) { return {v.z,v.y,v.x,v.w}; }
inline static stdmath_bool4 stdmath_bool4_zyxw_get(stdmath_bool4* p) { return stdmath_bool4_zyxw(*p); }
inline static stdmath_bool4 stdmath_bool4_zyxw_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->y = value.y; p->x = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zyyx(stdmath_bool4 v) { return {v.z,v.y,v.y,v.x}; }
inline static stdmath_bool4 stdmath_bool4_zyyx_get(stdmath_bool4* p) { return stdmath_bool4_zyyx(*p); }
inline static stdmath_bool4 stdmath_bool4_zyyx_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->y = value.y; p->y = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zyyy(stdmath_bool4 v) { return {v.z,v.y,v.y,v.y}; }
inline static stdmath_bool4 stdmath_bool4_zyyy_get(stdmath_bool4* p) { return stdmath_bool4_zyyy(*p); }
inline static stdmath_bool4 stdmath_bool4_zyyy_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->y = value.y; p->y = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zyyz(stdmath_bool4 v) { return {v.z,v.y,v.y,v.z}; }
inline static stdmath_bool4 stdmath_bool4_zyyz_get(stdmath_bool4* p) { return stdmath_bool4_zyyz(*p); }
inline static stdmath_bool4 stdmath_bool4_zyyz_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->y = value.y; p->y = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zyyw(stdmath_bool4 v) { return {v.z,v.y,v.y,v.w}; }
inline static stdmath_bool4 stdmath_bool4_zyyw_get(stdmath_bool4* p) { return stdmath_bool4_zyyw(*p); }
inline static stdmath_bool4 stdmath_bool4_zyyw_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->y = value.y; p->y = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zyzx(stdmath_bool4 v) { return {v.z,v.y,v.z,v.x}; }
inline static stdmath_bool4 stdmath_bool4_zyzx_get(stdmath_bool4* p) { return stdmath_bool4_zyzx(*p); }
inline static stdmath_bool4 stdmath_bool4_zyzx_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->y = value.y; p->z = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zyzy(stdmath_bool4 v) { return {v.z,v.y,v.z,v.y}; }
inline static stdmath_bool4 stdmath_bool4_zyzy_get(stdmath_bool4* p) { return stdmath_bool4_zyzy(*p); }
inline static stdmath_bool4 stdmath_bool4_zyzy_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->y = value.y; p->z = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zyzz(stdmath_bool4 v) { return {v.z,v.y,v.z,v.z}; }
inline static stdmath_bool4 stdmath_bool4_zyzz_get(stdmath_bool4* p) { return stdmath_bool4_zyzz(*p); }
inline static stdmath_bool4 stdmath_bool4_zyzz_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->y = value.y; p->z = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zyzw(stdmath_bool4 v) { return {v.z,v.y,v.z,v.w}; }
inline static stdmath_bool4 stdmath_bool4_zyzw_get(stdmath_bool4* p) { return stdmath_bool4_zyzw(*p); }
inline static stdmath_bool4 stdmath_bool4_zyzw_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->y = value.y; p->z = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zywx(stdmath_bool4 v) { return {v.z,v.y,v.w,v.x}; }
inline static stdmath_bool4 stdmath_bool4_zywx_get(stdmath_bool4* p) { return stdmath_bool4_zywx(*p); }
inline static stdmath_bool4 stdmath_bool4_zywx_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->y = value.y; p->w = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zywy(stdmath_bool4 v) { return {v.z,v.y,v.w,v.y}; }
inline static stdmath_bool4 stdmath_bool4_zywy_get(stdmath_bool4* p) { return stdmath_bool4_zywy(*p); }
inline static stdmath_bool4 stdmath_bool4_zywy_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->y = value.y; p->w = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zywz(stdmath_bool4 v) { return {v.z,v.y,v.w,v.z}; }
inline static stdmath_bool4 stdmath_bool4_zywz_get(stdmath_bool4* p) { return stdmath_bool4_zywz(*p); }
inline static stdmath_bool4 stdmath_bool4_zywz_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->y = value.y; p->w = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zyww(stdmath_bool4 v) { return {v.z,v.y,v.w,v.w}; }
inline static stdmath_bool4 stdmath_bool4_zyww_get(stdmath_bool4* p) { return stdmath_bool4_zyww(*p); }
inline static stdmath_bool4 stdmath_bool4_zyww_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->y = value.y; p->w = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zzxx(stdmath_bool4 v) { return {v.z,v.z,v.x,v.x}; }
inline static stdmath_bool4 stdmath_bool4_zzxx_get(stdmath_bool4* p) { return stdmath_bool4_zzxx(*p); }
inline static stdmath_bool4 stdmath_bool4_zzxx_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->z = value.y; p->x = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zzxy(stdmath_bool4 v) { return {v.z,v.z,v.x,v.y}; }
inline static stdmath_bool4 stdmath_bool4_zzxy_get(stdmath_bool4* p) { return stdmath_bool4_zzxy(*p); }
inline static stdmath_bool4 stdmath_bool4_zzxy_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->z = value.y; p->x = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zzxz(stdmath_bool4 v) { return {v.z,v.z,v.x,v.z}; }
inline static stdmath_bool4 stdmath_bool4_zzxz_get(stdmath_bool4* p) { return stdmath_bool4_zzxz(*p); }
inline static stdmath_bool4 stdmath_bool4_zzxz_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->z = value.y; p->x = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zzxw(stdmath_bool4 v) { return {v.z,v.z,v.x,v.w}; }
inline static stdmath_bool4 stdmath_bool4_zzxw_get(stdmath_bool4* p) { return stdmath_bool4_zzxw(*p); }
inline static stdmath_bool4 stdmath_bool4_zzxw_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->z = value.y; p->x = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zzyx(stdmath_bool4 v) { return {v.z,v.z,v.y,v.x}; }
inline static stdmath_bool4 stdmath_bool4_zzyx_get(stdmath_bool4* p) { return stdmath_bool4_zzyx(*p); }
inline static stdmath_bool4 stdmath_bool4_zzyx_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->z = value.y; p->y = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zzyy(stdmath_bool4 v) { return {v.z,v.z,v.y,v.y}; }
inline static stdmath_bool4 stdmath_bool4_zzyy_get(stdmath_bool4* p) { return stdmath_bool4_zzyy(*p); }
inline static stdmath_bool4 stdmath_bool4_zzyy_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->z = value.y; p->y = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zzyz(stdmath_bool4 v) { return {v.z,v.z,v.y,v.z}; }
inline static stdmath_bool4 stdmath_bool4_zzyz_get(stdmath_bool4* p) { return stdmath_bool4_zzyz(*p); }
inline static stdmath_bool4 stdmath_bool4_zzyz_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->z = value.y; p->y = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zzyw(stdmath_bool4 v) { return {v.z,v.z,v.y,v.w}; }
inline static stdmath_bool4 stdmath_bool4_zzyw_get(stdmath_bool4* p) { return stdmath_bool4_zzyw(*p); }
inline static stdmath_bool4 stdmath_bool4_zzyw_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->z = value.y; p->y = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zzzx(stdmath_bool4 v) { return {v.z,v.z,v.z,v.x}; }
inline static stdmath_bool4 stdmath_bool4_zzzx_get(stdmath_bool4* p) { return stdmath_bool4_zzzx(*p); }
inline static stdmath_bool4 stdmath_bool4_zzzx_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->z = value.y; p->z = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zzzy(stdmath_bool4 v) { return {v.z,v.z,v.z,v.y}; }
inline static stdmath_bool4 stdmath_bool4_zzzy_get(stdmath_bool4* p) { return stdmath_bool4_zzzy(*p); }
inline static stdmath_bool4 stdmath_bool4_zzzy_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->z = value.y; p->z = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zzzz(stdmath_bool4 v) { return {v.z,v.z,v.z,v.z}; }
inline static stdmath_bool4 stdmath_bool4_zzzz_get(stdmath_bool4* p) { return stdmath_bool4_zzzz(*p); }
inline static stdmath_bool4 stdmath_bool4_zzzz_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->z = value.y; p->z = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zzzw(stdmath_bool4 v) { return {v.z,v.z,v.z,v.w}; }
inline static stdmath_bool4 stdmath_bool4_zzzw_get(stdmath_bool4* p) { return stdmath_bool4_zzzw(*p); }
inline static stdmath_bool4 stdmath_bool4_zzzw_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->z = value.y; p->z = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zzwx(stdmath_bool4 v) { return {v.z,v.z,v.w,v.x}; }
inline static stdmath_bool4 stdmath_bool4_zzwx_get(stdmath_bool4* p) { return stdmath_bool4_zzwx(*p); }
inline static stdmath_bool4 stdmath_bool4_zzwx_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->z = value.y; p->w = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zzwy(stdmath_bool4 v) { return {v.z,v.z,v.w,v.y}; }
inline static stdmath_bool4 stdmath_bool4_zzwy_get(stdmath_bool4* p) { return stdmath_bool4_zzwy(*p); }
inline static stdmath_bool4 stdmath_bool4_zzwy_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->z = value.y; p->w = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zzwz(stdmath_bool4 v) { return {v.z,v.z,v.w,v.z}; }
inline static stdmath_bool4 stdmath_bool4_zzwz_get(stdmath_bool4* p) { return stdmath_bool4_zzwz(*p); }
inline static stdmath_bool4 stdmath_bool4_zzwz_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->z = value.y; p->w = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zzww(stdmath_bool4 v) { return {v.z,v.z,v.w,v.w}; }
inline static stdmath_bool4 stdmath_bool4_zzww_get(stdmath_bool4* p) { return stdmath_bool4_zzww(*p); }
inline static stdmath_bool4 stdmath_bool4_zzww_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->z = value.y; p->w = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zwxx(stdmath_bool4 v) { return {v.z,v.w,v.x,v.x}; }
inline static stdmath_bool4 stdmath_bool4_zwxx_get(stdmath_bool4* p) { return stdmath_bool4_zwxx(*p); }
inline static stdmath_bool4 stdmath_bool4_zwxx_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->w = value.y; p->x = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zwxy(stdmath_bool4 v) { return {v.z,v.w,v.x,v.y}; }
inline static stdmath_bool4 stdmath_bool4_zwxy_get(stdmath_bool4* p) { return stdmath_bool4_zwxy(*p); }
inline static stdmath_bool4 stdmath_bool4_zwxy_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->w = value.y; p->x = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zwxz(stdmath_bool4 v) { return {v.z,v.w,v.x,v.z}; }
inline static stdmath_bool4 stdmath_bool4_zwxz_get(stdmath_bool4* p) { return stdmath_bool4_zwxz(*p); }
inline static stdmath_bool4 stdmath_bool4_zwxz_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->w = value.y; p->x = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zwxw(stdmath_bool4 v) { return {v.z,v.w,v.x,v.w}; }
inline static stdmath_bool4 stdmath_bool4_zwxw_get(stdmath_bool4* p) { return stdmath_bool4_zwxw(*p); }
inline static stdmath_bool4 stdmath_bool4_zwxw_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->w = value.y; p->x = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zwyx(stdmath_bool4 v) { return {v.z,v.w,v.y,v.x}; }
inline static stdmath_bool4 stdmath_bool4_zwyx_get(stdmath_bool4* p) { return stdmath_bool4_zwyx(*p); }
inline static stdmath_bool4 stdmath_bool4_zwyx_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->w = value.y; p->y = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zwyy(stdmath_bool4 v) { return {v.z,v.w,v.y,v.y}; }
inline static stdmath_bool4 stdmath_bool4_zwyy_get(stdmath_bool4* p) { return stdmath_bool4_zwyy(*p); }
inline static stdmath_bool4 stdmath_bool4_zwyy_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->w = value.y; p->y = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zwyz(stdmath_bool4 v) { return {v.z,v.w,v.y,v.z}; }
inline static stdmath_bool4 stdmath_bool4_zwyz_get(stdmath_bool4* p) { return stdmath_bool4_zwyz(*p); }
inline static stdmath_bool4 stdmath_bool4_zwyz_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->w = value.y; p->y = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zwyw(stdmath_bool4 v) { return {v.z,v.w,v.y,v.w}; }
inline static stdmath_bool4 stdmath_bool4_zwyw_get(stdmath_bool4* p) { return stdmath_bool4_zwyw(*p); }
inline static stdmath_bool4 stdmath_bool4_zwyw_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->w = value.y; p->y = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zwzx(stdmath_bool4 v) { return {v.z,v.w,v.z,v.x}; }
inline static stdmath_bool4 stdmath_bool4_zwzx_get(stdmath_bool4* p) { return stdmath_bool4_zwzx(*p); }
inline static stdmath_bool4 stdmath_bool4_zwzx_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->w = value.y; p->z = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zwzy(stdmath_bool4 v) { return {v.z,v.w,v.z,v.y}; }
inline static stdmath_bool4 stdmath_bool4_zwzy_get(stdmath_bool4* p) { return stdmath_bool4_zwzy(*p); }
inline static stdmath_bool4 stdmath_bool4_zwzy_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->w = value.y; p->z = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zwzz(stdmath_bool4 v) { return {v.z,v.w,v.z,v.z}; }
inline static stdmath_bool4 stdmath_bool4_zwzz_get(stdmath_bool4* p) { return stdmath_bool4_zwzz(*p); }
inline static stdmath_bool4 stdmath_bool4_zwzz_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->w = value.y; p->z = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zwzw(stdmath_bool4 v) { return {v.z,v.w,v.z,v.w}; }
inline static stdmath_bool4 stdmath_bool4_zwzw_get(stdmath_bool4* p) { return stdmath_bool4_zwzw(*p); }
inline static stdmath_bool4 stdmath_bool4_zwzw_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->w = value.y; p->z = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zwwx(stdmath_bool4 v) { return {v.z,v.w,v.w,v.x}; }
inline static stdmath_bool4 stdmath_bool4_zwwx_get(stdmath_bool4* p) { return stdmath_bool4_zwwx(*p); }
inline static stdmath_bool4 stdmath_bool4_zwwx_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->w = value.y; p->w = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zwwy(stdmath_bool4 v) { return {v.z,v.w,v.w,v.y}; }
inline static stdmath_bool4 stdmath_bool4_zwwy_get(stdmath_bool4* p) { return stdmath_bool4_zwwy(*p); }
inline static stdmath_bool4 stdmath_bool4_zwwy_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->w = value.y; p->w = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zwwz(stdmath_bool4 v) { return {v.z,v.w,v.w,v.z}; }
inline static stdmath_bool4 stdmath_bool4_zwwz_get(stdmath_bool4* p) { return stdmath_bool4_zwwz(*p); }
inline static stdmath_bool4 stdmath_bool4_zwwz_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->w = value.y; p->w = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_zwww(stdmath_bool4 v) { return {v.z,v.w,v.w,v.w}; }
inline static stdmath_bool4 stdmath_bool4_zwww_get(stdmath_bool4* p) { return stdmath_bool4_zwww(*p); }
inline static stdmath_bool4 stdmath_bool4_zwww_set(stdmath_bool4* p, stdmath_bool4 value) { p->z = value.x; p->w = value.y; p->w = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wxxx(stdmath_bool4 v) { return {v.w,v.x,v.x,v.x}; }
inline static stdmath_bool4 stdmath_bool4_wxxx_get(stdmath_bool4* p) { return stdmath_bool4_wxxx(*p); }
inline static stdmath_bool4 stdmath_bool4_wxxx_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->x = value.y; p->x = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wxxy(stdmath_bool4 v) { return {v.w,v.x,v.x,v.y}; }
inline static stdmath_bool4 stdmath_bool4_wxxy_get(stdmath_bool4* p) { return stdmath_bool4_wxxy(*p); }
inline static stdmath_bool4 stdmath_bool4_wxxy_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->x = value.y; p->x = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wxxz(stdmath_bool4 v) { return {v.w,v.x,v.x,v.z}; }
inline static stdmath_bool4 stdmath_bool4_wxxz_get(stdmath_bool4* p) { return stdmath_bool4_wxxz(*p); }
inline static stdmath_bool4 stdmath_bool4_wxxz_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->x = value.y; p->x = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wxxw(stdmath_bool4 v) { return {v.w,v.x,v.x,v.w}; }
inline static stdmath_bool4 stdmath_bool4_wxxw_get(stdmath_bool4* p) { return stdmath_bool4_wxxw(*p); }
inline static stdmath_bool4 stdmath_bool4_wxxw_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->x = value.y; p->x = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wxyx(stdmath_bool4 v) { return {v.w,v.x,v.y,v.x}; }
inline static stdmath_bool4 stdmath_bool4_wxyx_get(stdmath_bool4* p) { return stdmath_bool4_wxyx(*p); }
inline static stdmath_bool4 stdmath_bool4_wxyx_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->x = value.y; p->y = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wxyy(stdmath_bool4 v) { return {v.w,v.x,v.y,v.y}; }
inline static stdmath_bool4 stdmath_bool4_wxyy_get(stdmath_bool4* p) { return stdmath_bool4_wxyy(*p); }
inline static stdmath_bool4 stdmath_bool4_wxyy_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->x = value.y; p->y = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wxyz(stdmath_bool4 v) { return {v.w,v.x,v.y,v.z}; }
inline static stdmath_bool4 stdmath_bool4_wxyz_get(stdmath_bool4* p) { return stdmath_bool4_wxyz(*p); }
inline static stdmath_bool4 stdmath_bool4_wxyz_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->x = value.y; p->y = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wxyw(stdmath_bool4 v) { return {v.w,v.x,v.y,v.w}; }
inline static stdmath_bool4 stdmath_bool4_wxyw_get(stdmath_bool4* p) { return stdmath_bool4_wxyw(*p); }
inline static stdmath_bool4 stdmath_bool4_wxyw_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->x = value.y; p->y = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wxzx(stdmath_bool4 v) { return {v.w,v.x,v.z,v.x}; }
inline static stdmath_bool4 stdmath_bool4_wxzx_get(stdmath_bool4* p) { return stdmath_bool4_wxzx(*p); }
inline static stdmath_bool4 stdmath_bool4_wxzx_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->x = value.y; p->z = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wxzy(stdmath_bool4 v) { return {v.w,v.x,v.z,v.y}; }
inline static stdmath_bool4 stdmath_bool4_wxzy_get(stdmath_bool4* p) { return stdmath_bool4_wxzy(*p); }
inline static stdmath_bool4 stdmath_bool4_wxzy_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->x = value.y; p->z = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wxzz(stdmath_bool4 v) { return {v.w,v.x,v.z,v.z}; }
inline static stdmath_bool4 stdmath_bool4_wxzz_get(stdmath_bool4* p) { return stdmath_bool4_wxzz(*p); }
inline static stdmath_bool4 stdmath_bool4_wxzz_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->x = value.y; p->z = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wxzw(stdmath_bool4 v) { return {v.w,v.x,v.z,v.w}; }
inline static stdmath_bool4 stdmath_bool4_wxzw_get(stdmath_bool4* p) { return stdmath_bool4_wxzw(*p); }
inline static stdmath_bool4 stdmath_bool4_wxzw_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->x = value.y; p->z = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wxwx(stdmath_bool4 v) { return {v.w,v.x,v.w,v.x}; }
inline static stdmath_bool4 stdmath_bool4_wxwx_get(stdmath_bool4* p) { return stdmath_bool4_wxwx(*p); }
inline static stdmath_bool4 stdmath_bool4_wxwx_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->x = value.y; p->w = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wxwy(stdmath_bool4 v) { return {v.w,v.x,v.w,v.y}; }
inline static stdmath_bool4 stdmath_bool4_wxwy_get(stdmath_bool4* p) { return stdmath_bool4_wxwy(*p); }
inline static stdmath_bool4 stdmath_bool4_wxwy_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->x = value.y; p->w = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wxwz(stdmath_bool4 v) { return {v.w,v.x,v.w,v.z}; }
inline static stdmath_bool4 stdmath_bool4_wxwz_get(stdmath_bool4* p) { return stdmath_bool4_wxwz(*p); }
inline static stdmath_bool4 stdmath_bool4_wxwz_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->x = value.y; p->w = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wxww(stdmath_bool4 v) { return {v.w,v.x,v.w,v.w}; }
inline static stdmath_bool4 stdmath_bool4_wxww_get(stdmath_bool4* p) { return stdmath_bool4_wxww(*p); }
inline static stdmath_bool4 stdmath_bool4_wxww_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->x = value.y; p->w = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wyxx(stdmath_bool4 v) { return {v.w,v.y,v.x,v.x}; }
inline static stdmath_bool4 stdmath_bool4_wyxx_get(stdmath_bool4* p) { return stdmath_bool4_wyxx(*p); }
inline static stdmath_bool4 stdmath_bool4_wyxx_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->y = value.y; p->x = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wyxy(stdmath_bool4 v) { return {v.w,v.y,v.x,v.y}; }
inline static stdmath_bool4 stdmath_bool4_wyxy_get(stdmath_bool4* p) { return stdmath_bool4_wyxy(*p); }
inline static stdmath_bool4 stdmath_bool4_wyxy_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->y = value.y; p->x = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wyxz(stdmath_bool4 v) { return {v.w,v.y,v.x,v.z}; }
inline static stdmath_bool4 stdmath_bool4_wyxz_get(stdmath_bool4* p) { return stdmath_bool4_wyxz(*p); }
inline static stdmath_bool4 stdmath_bool4_wyxz_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->y = value.y; p->x = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wyxw(stdmath_bool4 v) { return {v.w,v.y,v.x,v.w}; }
inline static stdmath_bool4 stdmath_bool4_wyxw_get(stdmath_bool4* p) { return stdmath_bool4_wyxw(*p); }
inline static stdmath_bool4 stdmath_bool4_wyxw_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->y = value.y; p->x = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wyyx(stdmath_bool4 v) { return {v.w,v.y,v.y,v.x}; }
inline static stdmath_bool4 stdmath_bool4_wyyx_get(stdmath_bool4* p) { return stdmath_bool4_wyyx(*p); }
inline static stdmath_bool4 stdmath_bool4_wyyx_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->y = value.y; p->y = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wyyy(stdmath_bool4 v) { return {v.w,v.y,v.y,v.y}; }
inline static stdmath_bool4 stdmath_bool4_wyyy_get(stdmath_bool4* p) { return stdmath_bool4_wyyy(*p); }
inline static stdmath_bool4 stdmath_bool4_wyyy_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->y = value.y; p->y = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wyyz(stdmath_bool4 v) { return {v.w,v.y,v.y,v.z}; }
inline static stdmath_bool4 stdmath_bool4_wyyz_get(stdmath_bool4* p) { return stdmath_bool4_wyyz(*p); }
inline static stdmath_bool4 stdmath_bool4_wyyz_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->y = value.y; p->y = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wyyw(stdmath_bool4 v) { return {v.w,v.y,v.y,v.w}; }
inline static stdmath_bool4 stdmath_bool4_wyyw_get(stdmath_bool4* p) { return stdmath_bool4_wyyw(*p); }
inline static stdmath_bool4 stdmath_bool4_wyyw_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->y = value.y; p->y = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wyzx(stdmath_bool4 v) { return {v.w,v.y,v.z,v.x}; }
inline static stdmath_bool4 stdmath_bool4_wyzx_get(stdmath_bool4* p) { return stdmath_bool4_wyzx(*p); }
inline static stdmath_bool4 stdmath_bool4_wyzx_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->y = value.y; p->z = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wyzy(stdmath_bool4 v) { return {v.w,v.y,v.z,v.y}; }
inline static stdmath_bool4 stdmath_bool4_wyzy_get(stdmath_bool4* p) { return stdmath_bool4_wyzy(*p); }
inline static stdmath_bool4 stdmath_bool4_wyzy_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->y = value.y; p->z = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wyzz(stdmath_bool4 v) { return {v.w,v.y,v.z,v.z}; }
inline static stdmath_bool4 stdmath_bool4_wyzz_get(stdmath_bool4* p) { return stdmath_bool4_wyzz(*p); }
inline static stdmath_bool4 stdmath_bool4_wyzz_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->y = value.y; p->z = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wyzw(stdmath_bool4 v) { return {v.w,v.y,v.z,v.w}; }
inline static stdmath_bool4 stdmath_bool4_wyzw_get(stdmath_bool4* p) { return stdmath_bool4_wyzw(*p); }
inline static stdmath_bool4 stdmath_bool4_wyzw_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->y = value.y; p->z = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wywx(stdmath_bool4 v) { return {v.w,v.y,v.w,v.x}; }
inline static stdmath_bool4 stdmath_bool4_wywx_get(stdmath_bool4* p) { return stdmath_bool4_wywx(*p); }
inline static stdmath_bool4 stdmath_bool4_wywx_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->y = value.y; p->w = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wywy(stdmath_bool4 v) { return {v.w,v.y,v.w,v.y}; }
inline static stdmath_bool4 stdmath_bool4_wywy_get(stdmath_bool4* p) { return stdmath_bool4_wywy(*p); }
inline static stdmath_bool4 stdmath_bool4_wywy_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->y = value.y; p->w = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wywz(stdmath_bool4 v) { return {v.w,v.y,v.w,v.z}; }
inline static stdmath_bool4 stdmath_bool4_wywz_get(stdmath_bool4* p) { return stdmath_bool4_wywz(*p); }
inline static stdmath_bool4 stdmath_bool4_wywz_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->y = value.y; p->w = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wyww(stdmath_bool4 v) { return {v.w,v.y,v.w,v.w}; }
inline static stdmath_bool4 stdmath_bool4_wyww_get(stdmath_bool4* p) { return stdmath_bool4_wyww(*p); }
inline static stdmath_bool4 stdmath_bool4_wyww_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->y = value.y; p->w = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wzxx(stdmath_bool4 v) { return {v.w,v.z,v.x,v.x}; }
inline static stdmath_bool4 stdmath_bool4_wzxx_get(stdmath_bool4* p) { return stdmath_bool4_wzxx(*p); }
inline static stdmath_bool4 stdmath_bool4_wzxx_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->z = value.y; p->x = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wzxy(stdmath_bool4 v) { return {v.w,v.z,v.x,v.y}; }
inline static stdmath_bool4 stdmath_bool4_wzxy_get(stdmath_bool4* p) { return stdmath_bool4_wzxy(*p); }
inline static stdmath_bool4 stdmath_bool4_wzxy_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->z = value.y; p->x = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wzxz(stdmath_bool4 v) { return {v.w,v.z,v.x,v.z}; }
inline static stdmath_bool4 stdmath_bool4_wzxz_get(stdmath_bool4* p) { return stdmath_bool4_wzxz(*p); }
inline static stdmath_bool4 stdmath_bool4_wzxz_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->z = value.y; p->x = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wzxw(stdmath_bool4 v) { return {v.w,v.z,v.x,v.w}; }
inline static stdmath_bool4 stdmath_bool4_wzxw_get(stdmath_bool4* p) { return stdmath_bool4_wzxw(*p); }
inline static stdmath_bool4 stdmath_bool4_wzxw_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->z = value.y; p->x = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wzyx(stdmath_bool4 v) { return {v.w,v.z,v.y,v.x}; }
inline static stdmath_bool4 stdmath_bool4_wzyx_get(stdmath_bool4* p) { return stdmath_bool4_wzyx(*p); }
inline static stdmath_bool4 stdmath_bool4_wzyx_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->z = value.y; p->y = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wzyy(stdmath_bool4 v) { return {v.w,v.z,v.y,v.y}; }
inline static stdmath_bool4 stdmath_bool4_wzyy_get(stdmath_bool4* p) { return stdmath_bool4_wzyy(*p); }
inline static stdmath_bool4 stdmath_bool4_wzyy_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->z = value.y; p->y = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wzyz(stdmath_bool4 v) { return {v.w,v.z,v.y,v.z}; }
inline static stdmath_bool4 stdmath_bool4_wzyz_get(stdmath_bool4* p) { return stdmath_bool4_wzyz(*p); }
inline static stdmath_bool4 stdmath_bool4_wzyz_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->z = value.y; p->y = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wzyw(stdmath_bool4 v) { return {v.w,v.z,v.y,v.w}; }
inline static stdmath_bool4 stdmath_bool4_wzyw_get(stdmath_bool4* p) { return stdmath_bool4_wzyw(*p); }
inline static stdmath_bool4 stdmath_bool4_wzyw_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->z = value.y; p->y = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wzzx(stdmath_bool4 v) { return {v.w,v.z,v.z,v.x}; }
inline static stdmath_bool4 stdmath_bool4_wzzx_get(stdmath_bool4* p) { return stdmath_bool4_wzzx(*p); }
inline static stdmath_bool4 stdmath_bool4_wzzx_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->z = value.y; p->z = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wzzy(stdmath_bool4 v) { return {v.w,v.z,v.z,v.y}; }
inline static stdmath_bool4 stdmath_bool4_wzzy_get(stdmath_bool4* p) { return stdmath_bool4_wzzy(*p); }
inline static stdmath_bool4 stdmath_bool4_wzzy_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->z = value.y; p->z = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wzzz(stdmath_bool4 v) { return {v.w,v.z,v.z,v.z}; }
inline static stdmath_bool4 stdmath_bool4_wzzz_get(stdmath_bool4* p) { return stdmath_bool4_wzzz(*p); }
inline static stdmath_bool4 stdmath_bool4_wzzz_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->z = value.y; p->z = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wzzw(stdmath_bool4 v) { return {v.w,v.z,v.z,v.w}; }
inline static stdmath_bool4 stdmath_bool4_wzzw_get(stdmath_bool4* p) { return stdmath_bool4_wzzw(*p); }
inline static stdmath_bool4 stdmath_bool4_wzzw_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->z = value.y; p->z = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wzwx(stdmath_bool4 v) { return {v.w,v.z,v.w,v.x}; }
inline static stdmath_bool4 stdmath_bool4_wzwx_get(stdmath_bool4* p) { return stdmath_bool4_wzwx(*p); }
inline static stdmath_bool4 stdmath_bool4_wzwx_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->z = value.y; p->w = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wzwy(stdmath_bool4 v) { return {v.w,v.z,v.w,v.y}; }
inline static stdmath_bool4 stdmath_bool4_wzwy_get(stdmath_bool4* p) { return stdmath_bool4_wzwy(*p); }
inline static stdmath_bool4 stdmath_bool4_wzwy_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->z = value.y; p->w = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wzwz(stdmath_bool4 v) { return {v.w,v.z,v.w,v.z}; }
inline static stdmath_bool4 stdmath_bool4_wzwz_get(stdmath_bool4* p) { return stdmath_bool4_wzwz(*p); }
inline static stdmath_bool4 stdmath_bool4_wzwz_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->z = value.y; p->w = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wzww(stdmath_bool4 v) { return {v.w,v.z,v.w,v.w}; }
inline static stdmath_bool4 stdmath_bool4_wzww_get(stdmath_bool4* p) { return stdmath_bool4_wzww(*p); }
inline static stdmath_bool4 stdmath_bool4_wzww_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->z = value.y; p->w = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wwxx(stdmath_bool4 v) { return {v.w,v.w,v.x,v.x}; }
inline static stdmath_bool4 stdmath_bool4_wwxx_get(stdmath_bool4* p) { return stdmath_bool4_wwxx(*p); }
inline static stdmath_bool4 stdmath_bool4_wwxx_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->w = value.y; p->x = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wwxy(stdmath_bool4 v) { return {v.w,v.w,v.x,v.y}; }
inline static stdmath_bool4 stdmath_bool4_wwxy_get(stdmath_bool4* p) { return stdmath_bool4_wwxy(*p); }
inline static stdmath_bool4 stdmath_bool4_wwxy_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->w = value.y; p->x = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wwxz(stdmath_bool4 v) { return {v.w,v.w,v.x,v.z}; }
inline static stdmath_bool4 stdmath_bool4_wwxz_get(stdmath_bool4* p) { return stdmath_bool4_wwxz(*p); }
inline static stdmath_bool4 stdmath_bool4_wwxz_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->w = value.y; p->x = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wwxw(stdmath_bool4 v) { return {v.w,v.w,v.x,v.w}; }
inline static stdmath_bool4 stdmath_bool4_wwxw_get(stdmath_bool4* p) { return stdmath_bool4_wwxw(*p); }
inline static stdmath_bool4 stdmath_bool4_wwxw_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->w = value.y; p->x = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wwyx(stdmath_bool4 v) { return {v.w,v.w,v.y,v.x}; }
inline static stdmath_bool4 stdmath_bool4_wwyx_get(stdmath_bool4* p) { return stdmath_bool4_wwyx(*p); }
inline static stdmath_bool4 stdmath_bool4_wwyx_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->w = value.y; p->y = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wwyy(stdmath_bool4 v) { return {v.w,v.w,v.y,v.y}; }
inline static stdmath_bool4 stdmath_bool4_wwyy_get(stdmath_bool4* p) { return stdmath_bool4_wwyy(*p); }
inline static stdmath_bool4 stdmath_bool4_wwyy_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->w = value.y; p->y = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wwyz(stdmath_bool4 v) { return {v.w,v.w,v.y,v.z}; }
inline static stdmath_bool4 stdmath_bool4_wwyz_get(stdmath_bool4* p) { return stdmath_bool4_wwyz(*p); }
inline static stdmath_bool4 stdmath_bool4_wwyz_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->w = value.y; p->y = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wwyw(stdmath_bool4 v) { return {v.w,v.w,v.y,v.w}; }
inline static stdmath_bool4 stdmath_bool4_wwyw_get(stdmath_bool4* p) { return stdmath_bool4_wwyw(*p); }
inline static stdmath_bool4 stdmath_bool4_wwyw_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->w = value.y; p->y = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wwzx(stdmath_bool4 v) { return {v.w,v.w,v.z,v.x}; }
inline static stdmath_bool4 stdmath_bool4_wwzx_get(stdmath_bool4* p) { return stdmath_bool4_wwzx(*p); }
inline static stdmath_bool4 stdmath_bool4_wwzx_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->w = value.y; p->z = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wwzy(stdmath_bool4 v) { return {v.w,v.w,v.z,v.y}; }
inline static stdmath_bool4 stdmath_bool4_wwzy_get(stdmath_bool4* p) { return stdmath_bool4_wwzy(*p); }
inline static stdmath_bool4 stdmath_bool4_wwzy_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->w = value.y; p->z = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wwzz(stdmath_bool4 v) { return {v.w,v.w,v.z,v.z}; }
inline static stdmath_bool4 stdmath_bool4_wwzz_get(stdmath_bool4* p) { return stdmath_bool4_wwzz(*p); }
inline static stdmath_bool4 stdmath_bool4_wwzz_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->w = value.y; p->z = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wwzw(stdmath_bool4 v) { return {v.w,v.w,v.z,v.w}; }
inline static stdmath_bool4 stdmath_bool4_wwzw_get(stdmath_bool4* p) { return stdmath_bool4_wwzw(*p); }
inline static stdmath_bool4 stdmath_bool4_wwzw_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->w = value.y; p->z = value.z; p->w = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wwwx(stdmath_bool4 v) { return {v.w,v.w,v.w,v.x}; }
inline static stdmath_bool4 stdmath_bool4_wwwx_get(stdmath_bool4* p) { return stdmath_bool4_wwwx(*p); }
inline static stdmath_bool4 stdmath_bool4_wwwx_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->w = value.y; p->w = value.z; p->x = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wwwy(stdmath_bool4 v) { return {v.w,v.w,v.w,v.y}; }
inline static stdmath_bool4 stdmath_bool4_wwwy_get(stdmath_bool4* p) { return stdmath_bool4_wwwy(*p); }
inline static stdmath_bool4 stdmath_bool4_wwwy_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->w = value.y; p->w = value.z; p->y = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wwwz(stdmath_bool4 v) { return {v.w,v.w,v.w,v.z}; }
inline static stdmath_bool4 stdmath_bool4_wwwz_get(stdmath_bool4* p) { return stdmath_bool4_wwwz(*p); }
inline static stdmath_bool4 stdmath_bool4_wwwz_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->w = value.y; p->w = value.z; p->z = value.w; return *p; }
inline static stdmath_bool4 stdmath_bool4_wwww(stdmath_bool4 v) { return {v.w,v.w,v.w,v.w}; }
inline static stdmath_bool4 stdmath_bool4_wwww_get(stdmath_bool4* p) { return stdmath_bool4_wwww(*p); }
inline static stdmath_bool4 stdmath_bool4_wwww_set(stdmath_bool4* p, stdmath_bool4 value) { p->w = value.x; p->w = value.y; p->w = value.z; p->w = value.w; return *p; }


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