#ifndef __STDMATH_stdmath_degree4_H__
#define __STDMATH_stdmath_degree4_H__

#ifndef STDMATH_MODULE
#include <stdint.h>
#include <assert.h>
#endif
#include "../maybe_export.h"

#if false
#include "radian.h"
#endif
#if true
#include "degree.h"
#endif

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
#include "degree1.h"
#elif 4 == 3
#include "degree2.h"
#include "degree1.h"
#elif 4 == 4
#include "degree3.h"
#include "degree2.h"
#include "degree1.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if 4 == 1
STDMATH_EXPORT union stdmath_degree1 {
	struct {
		stdmath_degree x;
	};
	stdmath_degree data[1];
};
#elif 4 == 2
STDMATH_EXPORT union stdmath_degree2 {
	struct {
		stdmath_degree x, y;
	};
	struct {
		stdmath_degree u, v;
	};
	stdmath_degree data[2];
};
#elif 4 == 3
STDMATH_EXPORT union stdmath_degree3 {
	struct {
		stdmath_degree x, y, z;
	};
	struct {
		stdmath_degree r, g, b;
	};
	struct {
		stdmath_degree h, s, v;
	};
	stdmath_degree data[4]; // degree3s are aligned as if they were degree4s
};
#elif 4 == 4
STDMATH_EXPORT union stdmath_degree4 {
	struct {
		stdmath_degree x, y, z, w;
	};
	struct {
		stdmath_degree r, g, b, a;
	};
	struct {
		stdmath_degree h, s, v;
	};
	stdmath_degree data[4];
};
#endif

STDMATH_EXPORT stdmath_degree4 stdmath_degree4_broadcast(stdmath_degree all);

STDMATH_EXPORT stdmath_degree4 stdmath_degree4_add(stdmath_degree4 a, stdmath_degree4 b);
STDMATH_EXPORT stdmath_degree4 stdmath_degree4_subtract(stdmath_degree4 a, stdmath_degree4 b);
STDMATH_EXPORT stdmath_degree4 stdmath_degree4_negate(stdmath_degree4 v);
STDMATH_EXPORT stdmath_degree4 stdmath_degree4_multiply(stdmath_degree4 a, stdmath_degree4 b);
STDMATH_EXPORT stdmath_degree4 stdmath_degree4_divide(stdmath_degree4 a, stdmath_degree4 b);
STDMATH_EXPORT stdmath_degree4 stdmath_degree4_scale(stdmath_degree4 v, stdmath_degree s);

#if false
STDMATH_EXPORT stdmath_degree4 stdmath_degree4_modulus(stdmath_degree4 a, stdmath_degree4 b);
STDMATH_EXPORT stdmath_degree4 stdmath_degree4_logical_not(stdmath_degree4 v);
STDMATH_EXPORT stdmath_degree4 stdmath_degree4_bitwise_not(stdmath_degree4 v);
STDMATH_EXPORT stdmath_degree4 stdmath_degree4_logical_and(stdmath_degree4 a, stdmath_degree4 b);
STDMATH_EXPORT stdmath_degree4 stdmath_degree4_bitwise_and(stdmath_degree4 a, stdmath_degree4 b);
STDMATH_EXPORT stdmath_degree4 stdmath_degree4_logical_or(stdmath_degree4 a, stdmath_degree4 b);
STDMATH_EXPORT stdmath_degree4 stdmath_degree4_bitwise_or(stdmath_degree4 a, stdmath_degree4 b);
STDMATH_EXPORT stdmath_degree4 stdmath_degree4_bitwise_xor(stdmath_degree4 a, stdmath_degree4 b);
STDMATH_EXPORT stdmath_degree4 stdmath_degree4_shift_left(stdmath_degree4 a, stdmath_degree4 b);
STDMATH_EXPORT stdmath_degree4 stdmath_degree4_shift_right(stdmath_degree4 a, stdmath_degree4 b);
#endif

STDMATH_EXPORT stdmath_bool4 stdmath_degree4_equal_to(stdmath_degree4 a, stdmath_degree4 b);
STDMATH_EXPORT stdmath_bool4 stdmath_degree4_not_equal_to(stdmath_degree4 a, stdmath_degree4 b);
STDMATH_EXPORT stdmath_bool4 stdmath_degree4_less_than(stdmath_degree4 a, stdmath_degree4 b);
STDMATH_EXPORT stdmath_bool4 stdmath_degree4_less_than_or_equal_to(stdmath_degree4 a, stdmath_degree4 b);
STDMATH_EXPORT stdmath_bool4 stdmath_degree4_greater_than(stdmath_degree4 a, stdmath_degree4 b);
STDMATH_EXPORT stdmath_bool4 stdmath_degree4_greater_than_or_equal_to(stdmath_degree4 a, stdmath_degree4 b);

STDMATH_EXPORT stdmath_degree stdmath_degree4_length_squared(stdmath_degree4 v);
STDMATH_EXPORT stdmath_degree stdmath_degree4_length(stdmath_degree4 v);
STDMATH_EXPORT stdmath_degree stdmath_degree4_dot(stdmath_degree4 a, stdmath_degree4 b);
STDMATH_EXPORT stdmath_degree stdmath_degree4_min_element(stdmath_degree4 v);
STDMATH_EXPORT stdmath_degree stdmath_degree4_max_element(stdmath_degree4 v);

// STDMATH_EXPORT stdmath_degree4 stdmath_degree4_elementwise_transform(stdmath_degree4 v, stdmath_degree(*func)(stdmath_degree));
// STDMATH_EXPORT stdmath_degree stdmath_degree4_reduce_elements(stdmath_degree4 v, stdmath_degree initial_value, stdmath_degree(*reducer)(stdmath_degree4, stdmath_degree4));

#if 4 == 3
STDMATH_EXPORT stdmath_degree3 stdmath_degree3_cross(stdmath_degree3 a, stdmath_degree3 b);
#endif

STDMATH_EXPORT stdmath_degree4 stdmath_degree4_min(stdmath_degree4 a, stdmath_degree4 b);
STDMATH_EXPORT stdmath_degree4 stdmath_degree4_max(stdmath_degree4 a, stdmath_degree4 b);
STDMATH_EXPORT stdmath_degree4 stdmath_degree4_normalize(stdmath_degree4 v);
STDMATH_EXPORT stdmath_degree4 stdmath_degree4_lerp(stdmath_degree4 a, stdmath_degree4 b, float t);
STDMATH_EXPORT stdmath_degree4 stdmath_degree4_clamp(stdmath_degree4 a, stdmath_degree4 min, stdmath_degree4 max);
STDMATH_EXPORT stdmath_degree4 stdmath_degree4_reflect(stdmath_degree4 a, stdmath_degree4 b);
STDMATH_EXPORT stdmath_bool4 stdmath_degree4_approximately_equal(stdmath_degree4 a, stdmath_degree4 b);

#if false
STDMATH_EXPORT bool stdmath_bool4_all_of(stdmath_bool4 v);
STDMATH_EXPORT bool stdmath_bool4_any_of(stdmath_bool4 v);
STDMATH_EXPORT bool stdmath_bool4_none_of(stdmath_bool4 v);
STDMATH_EXPORT bool stdmath_bool4_some_of(stdmath_bool4 v);
#endif

#ifndef STDMATH_NO_SWIZZLES
STDMATH_EXPORT STDMATH_INLINE stdmath_degree1 stdmath_degree4_x(stdmath_degree4 v) { return {v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree1 stdmath_degree4_x_get(stdmath_degree4* p) { return stdmath_degree4_x(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_x_set(stdmath_degree4* p, stdmath_degree1 value) { p->x = value.x; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree1 stdmath_degree4_y(stdmath_degree4 v) { return {v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree1 stdmath_degree4_y_get(stdmath_degree4* p) { return stdmath_degree4_y(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_y_set(stdmath_degree4* p, stdmath_degree1 value) { p->y = value.x; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree1 stdmath_degree4_z(stdmath_degree4 v) { return {v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree1 stdmath_degree4_z_get(stdmath_degree4* p) { return stdmath_degree4_z(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_z_set(stdmath_degree4* p, stdmath_degree1 value) { p->z = value.x; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree1 stdmath_degree4_w(stdmath_degree4 v) { return {v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree1 stdmath_degree4_w_get(stdmath_degree4* p) { return stdmath_degree4_w(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_w_set(stdmath_degree4* p, stdmath_degree1 value) { p->w = value.x; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree4_xx(stdmath_degree4 v) { return {v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree4_xx_get(stdmath_degree4* p) { return stdmath_degree4_xx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xx_set(stdmath_degree4* p, stdmath_degree2 value) { p->x = value.x; p->x = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree4_xy(stdmath_degree4 v) { return {v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree4_xy_get(stdmath_degree4* p) { return stdmath_degree4_xy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xy_set(stdmath_degree4* p, stdmath_degree2 value) { p->x = value.x; p->y = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree4_xz(stdmath_degree4 v) { return {v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree4_xz_get(stdmath_degree4* p) { return stdmath_degree4_xz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xz_set(stdmath_degree4* p, stdmath_degree2 value) { p->x = value.x; p->z = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree4_xw(stdmath_degree4 v) { return {v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree4_xw_get(stdmath_degree4* p) { return stdmath_degree4_xw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xw_set(stdmath_degree4* p, stdmath_degree2 value) { p->x = value.x; p->w = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree4_yx(stdmath_degree4 v) { return {v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree4_yx_get(stdmath_degree4* p) { return stdmath_degree4_yx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yx_set(stdmath_degree4* p, stdmath_degree2 value) { p->y = value.x; p->x = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree4_yy(stdmath_degree4 v) { return {v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree4_yy_get(stdmath_degree4* p) { return stdmath_degree4_yy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yy_set(stdmath_degree4* p, stdmath_degree2 value) { p->y = value.x; p->y = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree4_yz(stdmath_degree4 v) { return {v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree4_yz_get(stdmath_degree4* p) { return stdmath_degree4_yz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yz_set(stdmath_degree4* p, stdmath_degree2 value) { p->y = value.x; p->z = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree4_yw(stdmath_degree4 v) { return {v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree4_yw_get(stdmath_degree4* p) { return stdmath_degree4_yw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yw_set(stdmath_degree4* p, stdmath_degree2 value) { p->y = value.x; p->w = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree4_zx(stdmath_degree4 v) { return {v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree4_zx_get(stdmath_degree4* p) { return stdmath_degree4_zx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zx_set(stdmath_degree4* p, stdmath_degree2 value) { p->z = value.x; p->x = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree4_zy(stdmath_degree4 v) { return {v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree4_zy_get(stdmath_degree4* p) { return stdmath_degree4_zy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zy_set(stdmath_degree4* p, stdmath_degree2 value) { p->z = value.x; p->y = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree4_zz(stdmath_degree4 v) { return {v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree4_zz_get(stdmath_degree4* p) { return stdmath_degree4_zz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zz_set(stdmath_degree4* p, stdmath_degree2 value) { p->z = value.x; p->z = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree4_zw(stdmath_degree4 v) { return {v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree4_zw_get(stdmath_degree4* p) { return stdmath_degree4_zw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zw_set(stdmath_degree4* p, stdmath_degree2 value) { p->z = value.x; p->w = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree4_wx(stdmath_degree4 v) { return {v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree4_wx_get(stdmath_degree4* p) { return stdmath_degree4_wx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wx_set(stdmath_degree4* p, stdmath_degree2 value) { p->w = value.x; p->x = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree4_wy(stdmath_degree4 v) { return {v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree4_wy_get(stdmath_degree4* p) { return stdmath_degree4_wy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wy_set(stdmath_degree4* p, stdmath_degree2 value) { p->w = value.x; p->y = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree4_wz(stdmath_degree4 v) { return {v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree4_wz_get(stdmath_degree4* p) { return stdmath_degree4_wz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wz_set(stdmath_degree4* p, stdmath_degree2 value) { p->w = value.x; p->z = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree4_ww(stdmath_degree4 v) { return {v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree4_ww_get(stdmath_degree4* p) { return stdmath_degree4_ww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_ww_set(stdmath_degree4* p, stdmath_degree2 value) { p->w = value.x; p->w = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_xxx(stdmath_degree4 v) { return {v.x,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_xxx_get(stdmath_degree4* p) { return stdmath_degree4_xxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xxx_set(stdmath_degree4* p, stdmath_degree3 value) { p->x = value.x; p->x = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_xxy(stdmath_degree4 v) { return {v.x,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_xxy_get(stdmath_degree4* p) { return stdmath_degree4_xxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xxy_set(stdmath_degree4* p, stdmath_degree3 value) { p->x = value.x; p->x = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_xxz(stdmath_degree4 v) { return {v.x,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_xxz_get(stdmath_degree4* p) { return stdmath_degree4_xxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xxz_set(stdmath_degree4* p, stdmath_degree3 value) { p->x = value.x; p->x = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_xxw(stdmath_degree4 v) { return {v.x,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_xxw_get(stdmath_degree4* p) { return stdmath_degree4_xxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xxw_set(stdmath_degree4* p, stdmath_degree3 value) { p->x = value.x; p->x = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_xyx(stdmath_degree4 v) { return {v.x,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_xyx_get(stdmath_degree4* p) { return stdmath_degree4_xyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xyx_set(stdmath_degree4* p, stdmath_degree3 value) { p->x = value.x; p->y = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_xyy(stdmath_degree4 v) { return {v.x,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_xyy_get(stdmath_degree4* p) { return stdmath_degree4_xyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xyy_set(stdmath_degree4* p, stdmath_degree3 value) { p->x = value.x; p->y = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_xyz(stdmath_degree4 v) { return {v.x,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_xyz_get(stdmath_degree4* p) { return stdmath_degree4_xyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xyz_set(stdmath_degree4* p, stdmath_degree3 value) { p->x = value.x; p->y = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_xyw(stdmath_degree4 v) { return {v.x,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_xyw_get(stdmath_degree4* p) { return stdmath_degree4_xyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xyw_set(stdmath_degree4* p, stdmath_degree3 value) { p->x = value.x; p->y = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_xzx(stdmath_degree4 v) { return {v.x,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_xzx_get(stdmath_degree4* p) { return stdmath_degree4_xzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xzx_set(stdmath_degree4* p, stdmath_degree3 value) { p->x = value.x; p->z = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_xzy(stdmath_degree4 v) { return {v.x,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_xzy_get(stdmath_degree4* p) { return stdmath_degree4_xzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xzy_set(stdmath_degree4* p, stdmath_degree3 value) { p->x = value.x; p->z = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_xzz(stdmath_degree4 v) { return {v.x,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_xzz_get(stdmath_degree4* p) { return stdmath_degree4_xzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xzz_set(stdmath_degree4* p, stdmath_degree3 value) { p->x = value.x; p->z = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_xzw(stdmath_degree4 v) { return {v.x,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_xzw_get(stdmath_degree4* p) { return stdmath_degree4_xzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xzw_set(stdmath_degree4* p, stdmath_degree3 value) { p->x = value.x; p->z = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_xwx(stdmath_degree4 v) { return {v.x,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_xwx_get(stdmath_degree4* p) { return stdmath_degree4_xwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xwx_set(stdmath_degree4* p, stdmath_degree3 value) { p->x = value.x; p->w = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_xwy(stdmath_degree4 v) { return {v.x,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_xwy_get(stdmath_degree4* p) { return stdmath_degree4_xwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xwy_set(stdmath_degree4* p, stdmath_degree3 value) { p->x = value.x; p->w = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_xwz(stdmath_degree4 v) { return {v.x,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_xwz_get(stdmath_degree4* p) { return stdmath_degree4_xwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xwz_set(stdmath_degree4* p, stdmath_degree3 value) { p->x = value.x; p->w = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_xww(stdmath_degree4 v) { return {v.x,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_xww_get(stdmath_degree4* p) { return stdmath_degree4_xww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xww_set(stdmath_degree4* p, stdmath_degree3 value) { p->x = value.x; p->w = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_yxx(stdmath_degree4 v) { return {v.y,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_yxx_get(stdmath_degree4* p) { return stdmath_degree4_yxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yxx_set(stdmath_degree4* p, stdmath_degree3 value) { p->y = value.x; p->x = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_yxy(stdmath_degree4 v) { return {v.y,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_yxy_get(stdmath_degree4* p) { return stdmath_degree4_yxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yxy_set(stdmath_degree4* p, stdmath_degree3 value) { p->y = value.x; p->x = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_yxz(stdmath_degree4 v) { return {v.y,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_yxz_get(stdmath_degree4* p) { return stdmath_degree4_yxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yxz_set(stdmath_degree4* p, stdmath_degree3 value) { p->y = value.x; p->x = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_yxw(stdmath_degree4 v) { return {v.y,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_yxw_get(stdmath_degree4* p) { return stdmath_degree4_yxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yxw_set(stdmath_degree4* p, stdmath_degree3 value) { p->y = value.x; p->x = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_yyx(stdmath_degree4 v) { return {v.y,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_yyx_get(stdmath_degree4* p) { return stdmath_degree4_yyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yyx_set(stdmath_degree4* p, stdmath_degree3 value) { p->y = value.x; p->y = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_yyy(stdmath_degree4 v) { return {v.y,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_yyy_get(stdmath_degree4* p) { return stdmath_degree4_yyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yyy_set(stdmath_degree4* p, stdmath_degree3 value) { p->y = value.x; p->y = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_yyz(stdmath_degree4 v) { return {v.y,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_yyz_get(stdmath_degree4* p) { return stdmath_degree4_yyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yyz_set(stdmath_degree4* p, stdmath_degree3 value) { p->y = value.x; p->y = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_yyw(stdmath_degree4 v) { return {v.y,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_yyw_get(stdmath_degree4* p) { return stdmath_degree4_yyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yyw_set(stdmath_degree4* p, stdmath_degree3 value) { p->y = value.x; p->y = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_yzx(stdmath_degree4 v) { return {v.y,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_yzx_get(stdmath_degree4* p) { return stdmath_degree4_yzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yzx_set(stdmath_degree4* p, stdmath_degree3 value) { p->y = value.x; p->z = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_yzy(stdmath_degree4 v) { return {v.y,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_yzy_get(stdmath_degree4* p) { return stdmath_degree4_yzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yzy_set(stdmath_degree4* p, stdmath_degree3 value) { p->y = value.x; p->z = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_yzz(stdmath_degree4 v) { return {v.y,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_yzz_get(stdmath_degree4* p) { return stdmath_degree4_yzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yzz_set(stdmath_degree4* p, stdmath_degree3 value) { p->y = value.x; p->z = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_yzw(stdmath_degree4 v) { return {v.y,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_yzw_get(stdmath_degree4* p) { return stdmath_degree4_yzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yzw_set(stdmath_degree4* p, stdmath_degree3 value) { p->y = value.x; p->z = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_ywx(stdmath_degree4 v) { return {v.y,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_ywx_get(stdmath_degree4* p) { return stdmath_degree4_ywx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_ywx_set(stdmath_degree4* p, stdmath_degree3 value) { p->y = value.x; p->w = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_ywy(stdmath_degree4 v) { return {v.y,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_ywy_get(stdmath_degree4* p) { return stdmath_degree4_ywy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_ywy_set(stdmath_degree4* p, stdmath_degree3 value) { p->y = value.x; p->w = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_ywz(stdmath_degree4 v) { return {v.y,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_ywz_get(stdmath_degree4* p) { return stdmath_degree4_ywz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_ywz_set(stdmath_degree4* p, stdmath_degree3 value) { p->y = value.x; p->w = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_yww(stdmath_degree4 v) { return {v.y,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_yww_get(stdmath_degree4* p) { return stdmath_degree4_yww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yww_set(stdmath_degree4* p, stdmath_degree3 value) { p->y = value.x; p->w = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_zxx(stdmath_degree4 v) { return {v.z,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_zxx_get(stdmath_degree4* p) { return stdmath_degree4_zxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zxx_set(stdmath_degree4* p, stdmath_degree3 value) { p->z = value.x; p->x = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_zxy(stdmath_degree4 v) { return {v.z,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_zxy_get(stdmath_degree4* p) { return stdmath_degree4_zxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zxy_set(stdmath_degree4* p, stdmath_degree3 value) { p->z = value.x; p->x = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_zxz(stdmath_degree4 v) { return {v.z,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_zxz_get(stdmath_degree4* p) { return stdmath_degree4_zxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zxz_set(stdmath_degree4* p, stdmath_degree3 value) { p->z = value.x; p->x = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_zxw(stdmath_degree4 v) { return {v.z,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_zxw_get(stdmath_degree4* p) { return stdmath_degree4_zxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zxw_set(stdmath_degree4* p, stdmath_degree3 value) { p->z = value.x; p->x = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_zyx(stdmath_degree4 v) { return {v.z,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_zyx_get(stdmath_degree4* p) { return stdmath_degree4_zyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zyx_set(stdmath_degree4* p, stdmath_degree3 value) { p->z = value.x; p->y = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_zyy(stdmath_degree4 v) { return {v.z,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_zyy_get(stdmath_degree4* p) { return stdmath_degree4_zyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zyy_set(stdmath_degree4* p, stdmath_degree3 value) { p->z = value.x; p->y = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_zyz(stdmath_degree4 v) { return {v.z,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_zyz_get(stdmath_degree4* p) { return stdmath_degree4_zyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zyz_set(stdmath_degree4* p, stdmath_degree3 value) { p->z = value.x; p->y = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_zyw(stdmath_degree4 v) { return {v.z,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_zyw_get(stdmath_degree4* p) { return stdmath_degree4_zyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zyw_set(stdmath_degree4* p, stdmath_degree3 value) { p->z = value.x; p->y = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_zzx(stdmath_degree4 v) { return {v.z,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_zzx_get(stdmath_degree4* p) { return stdmath_degree4_zzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zzx_set(stdmath_degree4* p, stdmath_degree3 value) { p->z = value.x; p->z = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_zzy(stdmath_degree4 v) { return {v.z,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_zzy_get(stdmath_degree4* p) { return stdmath_degree4_zzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zzy_set(stdmath_degree4* p, stdmath_degree3 value) { p->z = value.x; p->z = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_zzz(stdmath_degree4 v) { return {v.z,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_zzz_get(stdmath_degree4* p) { return stdmath_degree4_zzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zzz_set(stdmath_degree4* p, stdmath_degree3 value) { p->z = value.x; p->z = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_zzw(stdmath_degree4 v) { return {v.z,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_zzw_get(stdmath_degree4* p) { return stdmath_degree4_zzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zzw_set(stdmath_degree4* p, stdmath_degree3 value) { p->z = value.x; p->z = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_zwx(stdmath_degree4 v) { return {v.z,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_zwx_get(stdmath_degree4* p) { return stdmath_degree4_zwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zwx_set(stdmath_degree4* p, stdmath_degree3 value) { p->z = value.x; p->w = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_zwy(stdmath_degree4 v) { return {v.z,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_zwy_get(stdmath_degree4* p) { return stdmath_degree4_zwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zwy_set(stdmath_degree4* p, stdmath_degree3 value) { p->z = value.x; p->w = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_zwz(stdmath_degree4 v) { return {v.z,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_zwz_get(stdmath_degree4* p) { return stdmath_degree4_zwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zwz_set(stdmath_degree4* p, stdmath_degree3 value) { p->z = value.x; p->w = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_zww(stdmath_degree4 v) { return {v.z,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_zww_get(stdmath_degree4* p) { return stdmath_degree4_zww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zww_set(stdmath_degree4* p, stdmath_degree3 value) { p->z = value.x; p->w = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_wxx(stdmath_degree4 v) { return {v.w,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_wxx_get(stdmath_degree4* p) { return stdmath_degree4_wxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wxx_set(stdmath_degree4* p, stdmath_degree3 value) { p->w = value.x; p->x = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_wxy(stdmath_degree4 v) { return {v.w,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_wxy_get(stdmath_degree4* p) { return stdmath_degree4_wxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wxy_set(stdmath_degree4* p, stdmath_degree3 value) { p->w = value.x; p->x = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_wxz(stdmath_degree4 v) { return {v.w,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_wxz_get(stdmath_degree4* p) { return stdmath_degree4_wxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wxz_set(stdmath_degree4* p, stdmath_degree3 value) { p->w = value.x; p->x = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_wxw(stdmath_degree4 v) { return {v.w,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_wxw_get(stdmath_degree4* p) { return stdmath_degree4_wxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wxw_set(stdmath_degree4* p, stdmath_degree3 value) { p->w = value.x; p->x = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_wyx(stdmath_degree4 v) { return {v.w,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_wyx_get(stdmath_degree4* p) { return stdmath_degree4_wyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wyx_set(stdmath_degree4* p, stdmath_degree3 value) { p->w = value.x; p->y = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_wyy(stdmath_degree4 v) { return {v.w,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_wyy_get(stdmath_degree4* p) { return stdmath_degree4_wyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wyy_set(stdmath_degree4* p, stdmath_degree3 value) { p->w = value.x; p->y = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_wyz(stdmath_degree4 v) { return {v.w,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_wyz_get(stdmath_degree4* p) { return stdmath_degree4_wyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wyz_set(stdmath_degree4* p, stdmath_degree3 value) { p->w = value.x; p->y = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_wyw(stdmath_degree4 v) { return {v.w,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_wyw_get(stdmath_degree4* p) { return stdmath_degree4_wyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wyw_set(stdmath_degree4* p, stdmath_degree3 value) { p->w = value.x; p->y = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_wzx(stdmath_degree4 v) { return {v.w,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_wzx_get(stdmath_degree4* p) { return stdmath_degree4_wzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wzx_set(stdmath_degree4* p, stdmath_degree3 value) { p->w = value.x; p->z = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_wzy(stdmath_degree4 v) { return {v.w,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_wzy_get(stdmath_degree4* p) { return stdmath_degree4_wzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wzy_set(stdmath_degree4* p, stdmath_degree3 value) { p->w = value.x; p->z = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_wzz(stdmath_degree4 v) { return {v.w,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_wzz_get(stdmath_degree4* p) { return stdmath_degree4_wzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wzz_set(stdmath_degree4* p, stdmath_degree3 value) { p->w = value.x; p->z = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_wzw(stdmath_degree4 v) { return {v.w,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_wzw_get(stdmath_degree4* p) { return stdmath_degree4_wzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wzw_set(stdmath_degree4* p, stdmath_degree3 value) { p->w = value.x; p->z = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_wwx(stdmath_degree4 v) { return {v.w,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_wwx_get(stdmath_degree4* p) { return stdmath_degree4_wwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wwx_set(stdmath_degree4* p, stdmath_degree3 value) { p->w = value.x; p->w = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_wwy(stdmath_degree4 v) { return {v.w,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_wwy_get(stdmath_degree4* p) { return stdmath_degree4_wwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wwy_set(stdmath_degree4* p, stdmath_degree3 value) { p->w = value.x; p->w = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_wwz(stdmath_degree4 v) { return {v.w,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_wwz_get(stdmath_degree4* p) { return stdmath_degree4_wwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wwz_set(stdmath_degree4* p, stdmath_degree3 value) { p->w = value.x; p->w = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_www(stdmath_degree4 v) { return {v.w,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree4_www_get(stdmath_degree4* p) { return stdmath_degree4_www(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_www_set(stdmath_degree4* p, stdmath_degree3 value) { p->w = value.x; p->w = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xxxx(stdmath_degree4 v) { return {v.x,v.x,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xxxx_get(stdmath_degree4* p) { return stdmath_degree4_xxxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xxxx_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->x = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xxxy(stdmath_degree4 v) { return {v.x,v.x,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xxxy_get(stdmath_degree4* p) { return stdmath_degree4_xxxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xxxy_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->x = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xxxz(stdmath_degree4 v) { return {v.x,v.x,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xxxz_get(stdmath_degree4* p) { return stdmath_degree4_xxxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xxxz_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->x = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xxxw(stdmath_degree4 v) { return {v.x,v.x,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xxxw_get(stdmath_degree4* p) { return stdmath_degree4_xxxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xxxw_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->x = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xxyx(stdmath_degree4 v) { return {v.x,v.x,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xxyx_get(stdmath_degree4* p) { return stdmath_degree4_xxyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xxyx_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->x = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xxyy(stdmath_degree4 v) { return {v.x,v.x,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xxyy_get(stdmath_degree4* p) { return stdmath_degree4_xxyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xxyy_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->x = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xxyz(stdmath_degree4 v) { return {v.x,v.x,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xxyz_get(stdmath_degree4* p) { return stdmath_degree4_xxyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xxyz_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->x = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xxyw(stdmath_degree4 v) { return {v.x,v.x,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xxyw_get(stdmath_degree4* p) { return stdmath_degree4_xxyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xxyw_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->x = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xxzx(stdmath_degree4 v) { return {v.x,v.x,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xxzx_get(stdmath_degree4* p) { return stdmath_degree4_xxzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xxzx_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->x = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xxzy(stdmath_degree4 v) { return {v.x,v.x,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xxzy_get(stdmath_degree4* p) { return stdmath_degree4_xxzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xxzy_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->x = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xxzz(stdmath_degree4 v) { return {v.x,v.x,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xxzz_get(stdmath_degree4* p) { return stdmath_degree4_xxzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xxzz_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->x = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xxzw(stdmath_degree4 v) { return {v.x,v.x,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xxzw_get(stdmath_degree4* p) { return stdmath_degree4_xxzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xxzw_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->x = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xxwx(stdmath_degree4 v) { return {v.x,v.x,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xxwx_get(stdmath_degree4* p) { return stdmath_degree4_xxwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xxwx_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->x = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xxwy(stdmath_degree4 v) { return {v.x,v.x,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xxwy_get(stdmath_degree4* p) { return stdmath_degree4_xxwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xxwy_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->x = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xxwz(stdmath_degree4 v) { return {v.x,v.x,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xxwz_get(stdmath_degree4* p) { return stdmath_degree4_xxwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xxwz_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->x = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xxww(stdmath_degree4 v) { return {v.x,v.x,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xxww_get(stdmath_degree4* p) { return stdmath_degree4_xxww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xxww_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->x = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xyxx(stdmath_degree4 v) { return {v.x,v.y,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xyxx_get(stdmath_degree4* p) { return stdmath_degree4_xyxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xyxx_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->y = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xyxy(stdmath_degree4 v) { return {v.x,v.y,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xyxy_get(stdmath_degree4* p) { return stdmath_degree4_xyxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xyxy_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->y = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xyxz(stdmath_degree4 v) { return {v.x,v.y,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xyxz_get(stdmath_degree4* p) { return stdmath_degree4_xyxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xyxz_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->y = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xyxw(stdmath_degree4 v) { return {v.x,v.y,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xyxw_get(stdmath_degree4* p) { return stdmath_degree4_xyxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xyxw_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->y = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xyyx(stdmath_degree4 v) { return {v.x,v.y,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xyyx_get(stdmath_degree4* p) { return stdmath_degree4_xyyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xyyx_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->y = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xyyy(stdmath_degree4 v) { return {v.x,v.y,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xyyy_get(stdmath_degree4* p) { return stdmath_degree4_xyyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xyyy_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->y = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xyyz(stdmath_degree4 v) { return {v.x,v.y,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xyyz_get(stdmath_degree4* p) { return stdmath_degree4_xyyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xyyz_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->y = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xyyw(stdmath_degree4 v) { return {v.x,v.y,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xyyw_get(stdmath_degree4* p) { return stdmath_degree4_xyyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xyyw_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->y = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xyzx(stdmath_degree4 v) { return {v.x,v.y,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xyzx_get(stdmath_degree4* p) { return stdmath_degree4_xyzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xyzx_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->y = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xyzy(stdmath_degree4 v) { return {v.x,v.y,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xyzy_get(stdmath_degree4* p) { return stdmath_degree4_xyzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xyzy_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->y = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xyzz(stdmath_degree4 v) { return {v.x,v.y,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xyzz_get(stdmath_degree4* p) { return stdmath_degree4_xyzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xyzz_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->y = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xyzw(stdmath_degree4 v) { return {v.x,v.y,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xyzw_get(stdmath_degree4* p) { return stdmath_degree4_xyzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xyzw_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->y = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xywx(stdmath_degree4 v) { return {v.x,v.y,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xywx_get(stdmath_degree4* p) { return stdmath_degree4_xywx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xywx_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->y = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xywy(stdmath_degree4 v) { return {v.x,v.y,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xywy_get(stdmath_degree4* p) { return stdmath_degree4_xywy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xywy_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->y = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xywz(stdmath_degree4 v) { return {v.x,v.y,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xywz_get(stdmath_degree4* p) { return stdmath_degree4_xywz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xywz_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->y = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xyww(stdmath_degree4 v) { return {v.x,v.y,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xyww_get(stdmath_degree4* p) { return stdmath_degree4_xyww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xyww_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->y = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xzxx(stdmath_degree4 v) { return {v.x,v.z,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xzxx_get(stdmath_degree4* p) { return stdmath_degree4_xzxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xzxx_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->z = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xzxy(stdmath_degree4 v) { return {v.x,v.z,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xzxy_get(stdmath_degree4* p) { return stdmath_degree4_xzxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xzxy_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->z = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xzxz(stdmath_degree4 v) { return {v.x,v.z,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xzxz_get(stdmath_degree4* p) { return stdmath_degree4_xzxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xzxz_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->z = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xzxw(stdmath_degree4 v) { return {v.x,v.z,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xzxw_get(stdmath_degree4* p) { return stdmath_degree4_xzxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xzxw_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->z = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xzyx(stdmath_degree4 v) { return {v.x,v.z,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xzyx_get(stdmath_degree4* p) { return stdmath_degree4_xzyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xzyx_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->z = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xzyy(stdmath_degree4 v) { return {v.x,v.z,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xzyy_get(stdmath_degree4* p) { return stdmath_degree4_xzyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xzyy_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->z = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xzyz(stdmath_degree4 v) { return {v.x,v.z,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xzyz_get(stdmath_degree4* p) { return stdmath_degree4_xzyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xzyz_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->z = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xzyw(stdmath_degree4 v) { return {v.x,v.z,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xzyw_get(stdmath_degree4* p) { return stdmath_degree4_xzyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xzyw_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->z = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xzzx(stdmath_degree4 v) { return {v.x,v.z,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xzzx_get(stdmath_degree4* p) { return stdmath_degree4_xzzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xzzx_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->z = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xzzy(stdmath_degree4 v) { return {v.x,v.z,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xzzy_get(stdmath_degree4* p) { return stdmath_degree4_xzzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xzzy_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->z = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xzzz(stdmath_degree4 v) { return {v.x,v.z,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xzzz_get(stdmath_degree4* p) { return stdmath_degree4_xzzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xzzz_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->z = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xzzw(stdmath_degree4 v) { return {v.x,v.z,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xzzw_get(stdmath_degree4* p) { return stdmath_degree4_xzzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xzzw_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->z = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xzwx(stdmath_degree4 v) { return {v.x,v.z,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xzwx_get(stdmath_degree4* p) { return stdmath_degree4_xzwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xzwx_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->z = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xzwy(stdmath_degree4 v) { return {v.x,v.z,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xzwy_get(stdmath_degree4* p) { return stdmath_degree4_xzwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xzwy_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->z = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xzwz(stdmath_degree4 v) { return {v.x,v.z,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xzwz_get(stdmath_degree4* p) { return stdmath_degree4_xzwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xzwz_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->z = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xzww(stdmath_degree4 v) { return {v.x,v.z,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xzww_get(stdmath_degree4* p) { return stdmath_degree4_xzww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xzww_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->z = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xwxx(stdmath_degree4 v) { return {v.x,v.w,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xwxx_get(stdmath_degree4* p) { return stdmath_degree4_xwxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xwxx_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->w = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xwxy(stdmath_degree4 v) { return {v.x,v.w,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xwxy_get(stdmath_degree4* p) { return stdmath_degree4_xwxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xwxy_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->w = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xwxz(stdmath_degree4 v) { return {v.x,v.w,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xwxz_get(stdmath_degree4* p) { return stdmath_degree4_xwxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xwxz_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->w = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xwxw(stdmath_degree4 v) { return {v.x,v.w,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xwxw_get(stdmath_degree4* p) { return stdmath_degree4_xwxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xwxw_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->w = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xwyx(stdmath_degree4 v) { return {v.x,v.w,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xwyx_get(stdmath_degree4* p) { return stdmath_degree4_xwyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xwyx_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->w = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xwyy(stdmath_degree4 v) { return {v.x,v.w,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xwyy_get(stdmath_degree4* p) { return stdmath_degree4_xwyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xwyy_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->w = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xwyz(stdmath_degree4 v) { return {v.x,v.w,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xwyz_get(stdmath_degree4* p) { return stdmath_degree4_xwyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xwyz_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->w = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xwyw(stdmath_degree4 v) { return {v.x,v.w,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xwyw_get(stdmath_degree4* p) { return stdmath_degree4_xwyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xwyw_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->w = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xwzx(stdmath_degree4 v) { return {v.x,v.w,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xwzx_get(stdmath_degree4* p) { return stdmath_degree4_xwzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xwzx_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->w = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xwzy(stdmath_degree4 v) { return {v.x,v.w,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xwzy_get(stdmath_degree4* p) { return stdmath_degree4_xwzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xwzy_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->w = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xwzz(stdmath_degree4 v) { return {v.x,v.w,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xwzz_get(stdmath_degree4* p) { return stdmath_degree4_xwzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xwzz_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->w = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xwzw(stdmath_degree4 v) { return {v.x,v.w,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xwzw_get(stdmath_degree4* p) { return stdmath_degree4_xwzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xwzw_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->w = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xwwx(stdmath_degree4 v) { return {v.x,v.w,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xwwx_get(stdmath_degree4* p) { return stdmath_degree4_xwwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xwwx_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->w = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xwwy(stdmath_degree4 v) { return {v.x,v.w,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xwwy_get(stdmath_degree4* p) { return stdmath_degree4_xwwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xwwy_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->w = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xwwz(stdmath_degree4 v) { return {v.x,v.w,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xwwz_get(stdmath_degree4* p) { return stdmath_degree4_xwwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xwwz_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->w = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xwww(stdmath_degree4 v) { return {v.x,v.w,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xwww_get(stdmath_degree4* p) { return stdmath_degree4_xwww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_xwww_set(stdmath_degree4* p, stdmath_degree4 value) { p->x = value.x; p->w = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yxxx(stdmath_degree4 v) { return {v.y,v.x,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yxxx_get(stdmath_degree4* p) { return stdmath_degree4_yxxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yxxx_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->x = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yxxy(stdmath_degree4 v) { return {v.y,v.x,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yxxy_get(stdmath_degree4* p) { return stdmath_degree4_yxxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yxxy_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->x = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yxxz(stdmath_degree4 v) { return {v.y,v.x,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yxxz_get(stdmath_degree4* p) { return stdmath_degree4_yxxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yxxz_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->x = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yxxw(stdmath_degree4 v) { return {v.y,v.x,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yxxw_get(stdmath_degree4* p) { return stdmath_degree4_yxxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yxxw_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->x = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yxyx(stdmath_degree4 v) { return {v.y,v.x,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yxyx_get(stdmath_degree4* p) { return stdmath_degree4_yxyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yxyx_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->x = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yxyy(stdmath_degree4 v) { return {v.y,v.x,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yxyy_get(stdmath_degree4* p) { return stdmath_degree4_yxyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yxyy_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->x = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yxyz(stdmath_degree4 v) { return {v.y,v.x,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yxyz_get(stdmath_degree4* p) { return stdmath_degree4_yxyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yxyz_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->x = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yxyw(stdmath_degree4 v) { return {v.y,v.x,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yxyw_get(stdmath_degree4* p) { return stdmath_degree4_yxyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yxyw_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->x = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yxzx(stdmath_degree4 v) { return {v.y,v.x,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yxzx_get(stdmath_degree4* p) { return stdmath_degree4_yxzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yxzx_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->x = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yxzy(stdmath_degree4 v) { return {v.y,v.x,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yxzy_get(stdmath_degree4* p) { return stdmath_degree4_yxzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yxzy_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->x = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yxzz(stdmath_degree4 v) { return {v.y,v.x,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yxzz_get(stdmath_degree4* p) { return stdmath_degree4_yxzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yxzz_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->x = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yxzw(stdmath_degree4 v) { return {v.y,v.x,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yxzw_get(stdmath_degree4* p) { return stdmath_degree4_yxzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yxzw_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->x = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yxwx(stdmath_degree4 v) { return {v.y,v.x,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yxwx_get(stdmath_degree4* p) { return stdmath_degree4_yxwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yxwx_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->x = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yxwy(stdmath_degree4 v) { return {v.y,v.x,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yxwy_get(stdmath_degree4* p) { return stdmath_degree4_yxwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yxwy_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->x = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yxwz(stdmath_degree4 v) { return {v.y,v.x,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yxwz_get(stdmath_degree4* p) { return stdmath_degree4_yxwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yxwz_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->x = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yxww(stdmath_degree4 v) { return {v.y,v.x,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yxww_get(stdmath_degree4* p) { return stdmath_degree4_yxww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yxww_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->x = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yyxx(stdmath_degree4 v) { return {v.y,v.y,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yyxx_get(stdmath_degree4* p) { return stdmath_degree4_yyxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yyxx_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->y = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yyxy(stdmath_degree4 v) { return {v.y,v.y,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yyxy_get(stdmath_degree4* p) { return stdmath_degree4_yyxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yyxy_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->y = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yyxz(stdmath_degree4 v) { return {v.y,v.y,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yyxz_get(stdmath_degree4* p) { return stdmath_degree4_yyxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yyxz_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->y = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yyxw(stdmath_degree4 v) { return {v.y,v.y,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yyxw_get(stdmath_degree4* p) { return stdmath_degree4_yyxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yyxw_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->y = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yyyx(stdmath_degree4 v) { return {v.y,v.y,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yyyx_get(stdmath_degree4* p) { return stdmath_degree4_yyyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yyyx_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->y = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yyyy(stdmath_degree4 v) { return {v.y,v.y,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yyyy_get(stdmath_degree4* p) { return stdmath_degree4_yyyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yyyy_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->y = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yyyz(stdmath_degree4 v) { return {v.y,v.y,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yyyz_get(stdmath_degree4* p) { return stdmath_degree4_yyyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yyyz_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->y = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yyyw(stdmath_degree4 v) { return {v.y,v.y,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yyyw_get(stdmath_degree4* p) { return stdmath_degree4_yyyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yyyw_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->y = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yyzx(stdmath_degree4 v) { return {v.y,v.y,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yyzx_get(stdmath_degree4* p) { return stdmath_degree4_yyzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yyzx_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->y = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yyzy(stdmath_degree4 v) { return {v.y,v.y,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yyzy_get(stdmath_degree4* p) { return stdmath_degree4_yyzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yyzy_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->y = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yyzz(stdmath_degree4 v) { return {v.y,v.y,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yyzz_get(stdmath_degree4* p) { return stdmath_degree4_yyzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yyzz_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->y = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yyzw(stdmath_degree4 v) { return {v.y,v.y,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yyzw_get(stdmath_degree4* p) { return stdmath_degree4_yyzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yyzw_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->y = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yywx(stdmath_degree4 v) { return {v.y,v.y,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yywx_get(stdmath_degree4* p) { return stdmath_degree4_yywx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yywx_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->y = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yywy(stdmath_degree4 v) { return {v.y,v.y,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yywy_get(stdmath_degree4* p) { return stdmath_degree4_yywy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yywy_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->y = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yywz(stdmath_degree4 v) { return {v.y,v.y,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yywz_get(stdmath_degree4* p) { return stdmath_degree4_yywz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yywz_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->y = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yyww(stdmath_degree4 v) { return {v.y,v.y,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yyww_get(stdmath_degree4* p) { return stdmath_degree4_yyww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yyww_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->y = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yzxx(stdmath_degree4 v) { return {v.y,v.z,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yzxx_get(stdmath_degree4* p) { return stdmath_degree4_yzxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yzxx_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->z = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yzxy(stdmath_degree4 v) { return {v.y,v.z,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yzxy_get(stdmath_degree4* p) { return stdmath_degree4_yzxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yzxy_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->z = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yzxz(stdmath_degree4 v) { return {v.y,v.z,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yzxz_get(stdmath_degree4* p) { return stdmath_degree4_yzxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yzxz_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->z = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yzxw(stdmath_degree4 v) { return {v.y,v.z,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yzxw_get(stdmath_degree4* p) { return stdmath_degree4_yzxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yzxw_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->z = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yzyx(stdmath_degree4 v) { return {v.y,v.z,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yzyx_get(stdmath_degree4* p) { return stdmath_degree4_yzyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yzyx_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->z = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yzyy(stdmath_degree4 v) { return {v.y,v.z,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yzyy_get(stdmath_degree4* p) { return stdmath_degree4_yzyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yzyy_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->z = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yzyz(stdmath_degree4 v) { return {v.y,v.z,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yzyz_get(stdmath_degree4* p) { return stdmath_degree4_yzyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yzyz_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->z = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yzyw(stdmath_degree4 v) { return {v.y,v.z,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yzyw_get(stdmath_degree4* p) { return stdmath_degree4_yzyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yzyw_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->z = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yzzx(stdmath_degree4 v) { return {v.y,v.z,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yzzx_get(stdmath_degree4* p) { return stdmath_degree4_yzzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yzzx_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->z = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yzzy(stdmath_degree4 v) { return {v.y,v.z,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yzzy_get(stdmath_degree4* p) { return stdmath_degree4_yzzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yzzy_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->z = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yzzz(stdmath_degree4 v) { return {v.y,v.z,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yzzz_get(stdmath_degree4* p) { return stdmath_degree4_yzzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yzzz_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->z = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yzzw(stdmath_degree4 v) { return {v.y,v.z,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yzzw_get(stdmath_degree4* p) { return stdmath_degree4_yzzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yzzw_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->z = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yzwx(stdmath_degree4 v) { return {v.y,v.z,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yzwx_get(stdmath_degree4* p) { return stdmath_degree4_yzwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yzwx_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->z = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yzwy(stdmath_degree4 v) { return {v.y,v.z,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yzwy_get(stdmath_degree4* p) { return stdmath_degree4_yzwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yzwy_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->z = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yzwz(stdmath_degree4 v) { return {v.y,v.z,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yzwz_get(stdmath_degree4* p) { return stdmath_degree4_yzwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yzwz_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->z = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yzww(stdmath_degree4 v) { return {v.y,v.z,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yzww_get(stdmath_degree4* p) { return stdmath_degree4_yzww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_yzww_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->z = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_ywxx(stdmath_degree4 v) { return {v.y,v.w,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_ywxx_get(stdmath_degree4* p) { return stdmath_degree4_ywxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_ywxx_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->w = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_ywxy(stdmath_degree4 v) { return {v.y,v.w,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_ywxy_get(stdmath_degree4* p) { return stdmath_degree4_ywxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_ywxy_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->w = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_ywxz(stdmath_degree4 v) { return {v.y,v.w,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_ywxz_get(stdmath_degree4* p) { return stdmath_degree4_ywxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_ywxz_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->w = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_ywxw(stdmath_degree4 v) { return {v.y,v.w,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_ywxw_get(stdmath_degree4* p) { return stdmath_degree4_ywxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_ywxw_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->w = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_ywyx(stdmath_degree4 v) { return {v.y,v.w,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_ywyx_get(stdmath_degree4* p) { return stdmath_degree4_ywyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_ywyx_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->w = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_ywyy(stdmath_degree4 v) { return {v.y,v.w,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_ywyy_get(stdmath_degree4* p) { return stdmath_degree4_ywyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_ywyy_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->w = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_ywyz(stdmath_degree4 v) { return {v.y,v.w,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_ywyz_get(stdmath_degree4* p) { return stdmath_degree4_ywyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_ywyz_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->w = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_ywyw(stdmath_degree4 v) { return {v.y,v.w,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_ywyw_get(stdmath_degree4* p) { return stdmath_degree4_ywyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_ywyw_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->w = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_ywzx(stdmath_degree4 v) { return {v.y,v.w,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_ywzx_get(stdmath_degree4* p) { return stdmath_degree4_ywzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_ywzx_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->w = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_ywzy(stdmath_degree4 v) { return {v.y,v.w,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_ywzy_get(stdmath_degree4* p) { return stdmath_degree4_ywzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_ywzy_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->w = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_ywzz(stdmath_degree4 v) { return {v.y,v.w,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_ywzz_get(stdmath_degree4* p) { return stdmath_degree4_ywzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_ywzz_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->w = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_ywzw(stdmath_degree4 v) { return {v.y,v.w,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_ywzw_get(stdmath_degree4* p) { return stdmath_degree4_ywzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_ywzw_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->w = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_ywwx(stdmath_degree4 v) { return {v.y,v.w,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_ywwx_get(stdmath_degree4* p) { return stdmath_degree4_ywwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_ywwx_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->w = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_ywwy(stdmath_degree4 v) { return {v.y,v.w,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_ywwy_get(stdmath_degree4* p) { return stdmath_degree4_ywwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_ywwy_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->w = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_ywwz(stdmath_degree4 v) { return {v.y,v.w,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_ywwz_get(stdmath_degree4* p) { return stdmath_degree4_ywwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_ywwz_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->w = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_ywww(stdmath_degree4 v) { return {v.y,v.w,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_ywww_get(stdmath_degree4* p) { return stdmath_degree4_ywww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_ywww_set(stdmath_degree4* p, stdmath_degree4 value) { p->y = value.x; p->w = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zxxx(stdmath_degree4 v) { return {v.z,v.x,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zxxx_get(stdmath_degree4* p) { return stdmath_degree4_zxxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zxxx_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->x = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zxxy(stdmath_degree4 v) { return {v.z,v.x,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zxxy_get(stdmath_degree4* p) { return stdmath_degree4_zxxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zxxy_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->x = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zxxz(stdmath_degree4 v) { return {v.z,v.x,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zxxz_get(stdmath_degree4* p) { return stdmath_degree4_zxxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zxxz_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->x = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zxxw(stdmath_degree4 v) { return {v.z,v.x,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zxxw_get(stdmath_degree4* p) { return stdmath_degree4_zxxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zxxw_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->x = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zxyx(stdmath_degree4 v) { return {v.z,v.x,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zxyx_get(stdmath_degree4* p) { return stdmath_degree4_zxyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zxyx_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->x = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zxyy(stdmath_degree4 v) { return {v.z,v.x,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zxyy_get(stdmath_degree4* p) { return stdmath_degree4_zxyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zxyy_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->x = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zxyz(stdmath_degree4 v) { return {v.z,v.x,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zxyz_get(stdmath_degree4* p) { return stdmath_degree4_zxyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zxyz_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->x = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zxyw(stdmath_degree4 v) { return {v.z,v.x,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zxyw_get(stdmath_degree4* p) { return stdmath_degree4_zxyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zxyw_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->x = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zxzx(stdmath_degree4 v) { return {v.z,v.x,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zxzx_get(stdmath_degree4* p) { return stdmath_degree4_zxzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zxzx_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->x = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zxzy(stdmath_degree4 v) { return {v.z,v.x,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zxzy_get(stdmath_degree4* p) { return stdmath_degree4_zxzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zxzy_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->x = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zxzz(stdmath_degree4 v) { return {v.z,v.x,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zxzz_get(stdmath_degree4* p) { return stdmath_degree4_zxzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zxzz_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->x = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zxzw(stdmath_degree4 v) { return {v.z,v.x,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zxzw_get(stdmath_degree4* p) { return stdmath_degree4_zxzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zxzw_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->x = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zxwx(stdmath_degree4 v) { return {v.z,v.x,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zxwx_get(stdmath_degree4* p) { return stdmath_degree4_zxwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zxwx_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->x = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zxwy(stdmath_degree4 v) { return {v.z,v.x,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zxwy_get(stdmath_degree4* p) { return stdmath_degree4_zxwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zxwy_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->x = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zxwz(stdmath_degree4 v) { return {v.z,v.x,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zxwz_get(stdmath_degree4* p) { return stdmath_degree4_zxwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zxwz_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->x = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zxww(stdmath_degree4 v) { return {v.z,v.x,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zxww_get(stdmath_degree4* p) { return stdmath_degree4_zxww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zxww_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->x = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zyxx(stdmath_degree4 v) { return {v.z,v.y,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zyxx_get(stdmath_degree4* p) { return stdmath_degree4_zyxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zyxx_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->y = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zyxy(stdmath_degree4 v) { return {v.z,v.y,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zyxy_get(stdmath_degree4* p) { return stdmath_degree4_zyxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zyxy_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->y = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zyxz(stdmath_degree4 v) { return {v.z,v.y,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zyxz_get(stdmath_degree4* p) { return stdmath_degree4_zyxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zyxz_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->y = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zyxw(stdmath_degree4 v) { return {v.z,v.y,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zyxw_get(stdmath_degree4* p) { return stdmath_degree4_zyxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zyxw_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->y = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zyyx(stdmath_degree4 v) { return {v.z,v.y,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zyyx_get(stdmath_degree4* p) { return stdmath_degree4_zyyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zyyx_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->y = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zyyy(stdmath_degree4 v) { return {v.z,v.y,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zyyy_get(stdmath_degree4* p) { return stdmath_degree4_zyyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zyyy_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->y = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zyyz(stdmath_degree4 v) { return {v.z,v.y,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zyyz_get(stdmath_degree4* p) { return stdmath_degree4_zyyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zyyz_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->y = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zyyw(stdmath_degree4 v) { return {v.z,v.y,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zyyw_get(stdmath_degree4* p) { return stdmath_degree4_zyyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zyyw_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->y = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zyzx(stdmath_degree4 v) { return {v.z,v.y,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zyzx_get(stdmath_degree4* p) { return stdmath_degree4_zyzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zyzx_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->y = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zyzy(stdmath_degree4 v) { return {v.z,v.y,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zyzy_get(stdmath_degree4* p) { return stdmath_degree4_zyzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zyzy_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->y = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zyzz(stdmath_degree4 v) { return {v.z,v.y,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zyzz_get(stdmath_degree4* p) { return stdmath_degree4_zyzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zyzz_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->y = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zyzw(stdmath_degree4 v) { return {v.z,v.y,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zyzw_get(stdmath_degree4* p) { return stdmath_degree4_zyzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zyzw_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->y = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zywx(stdmath_degree4 v) { return {v.z,v.y,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zywx_get(stdmath_degree4* p) { return stdmath_degree4_zywx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zywx_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->y = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zywy(stdmath_degree4 v) { return {v.z,v.y,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zywy_get(stdmath_degree4* p) { return stdmath_degree4_zywy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zywy_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->y = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zywz(stdmath_degree4 v) { return {v.z,v.y,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zywz_get(stdmath_degree4* p) { return stdmath_degree4_zywz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zywz_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->y = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zyww(stdmath_degree4 v) { return {v.z,v.y,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zyww_get(stdmath_degree4* p) { return stdmath_degree4_zyww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zyww_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->y = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zzxx(stdmath_degree4 v) { return {v.z,v.z,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zzxx_get(stdmath_degree4* p) { return stdmath_degree4_zzxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zzxx_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->z = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zzxy(stdmath_degree4 v) { return {v.z,v.z,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zzxy_get(stdmath_degree4* p) { return stdmath_degree4_zzxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zzxy_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->z = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zzxz(stdmath_degree4 v) { return {v.z,v.z,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zzxz_get(stdmath_degree4* p) { return stdmath_degree4_zzxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zzxz_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->z = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zzxw(stdmath_degree4 v) { return {v.z,v.z,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zzxw_get(stdmath_degree4* p) { return stdmath_degree4_zzxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zzxw_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->z = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zzyx(stdmath_degree4 v) { return {v.z,v.z,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zzyx_get(stdmath_degree4* p) { return stdmath_degree4_zzyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zzyx_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->z = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zzyy(stdmath_degree4 v) { return {v.z,v.z,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zzyy_get(stdmath_degree4* p) { return stdmath_degree4_zzyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zzyy_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->z = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zzyz(stdmath_degree4 v) { return {v.z,v.z,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zzyz_get(stdmath_degree4* p) { return stdmath_degree4_zzyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zzyz_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->z = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zzyw(stdmath_degree4 v) { return {v.z,v.z,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zzyw_get(stdmath_degree4* p) { return stdmath_degree4_zzyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zzyw_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->z = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zzzx(stdmath_degree4 v) { return {v.z,v.z,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zzzx_get(stdmath_degree4* p) { return stdmath_degree4_zzzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zzzx_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->z = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zzzy(stdmath_degree4 v) { return {v.z,v.z,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zzzy_get(stdmath_degree4* p) { return stdmath_degree4_zzzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zzzy_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->z = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zzzz(stdmath_degree4 v) { return {v.z,v.z,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zzzz_get(stdmath_degree4* p) { return stdmath_degree4_zzzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zzzz_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->z = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zzzw(stdmath_degree4 v) { return {v.z,v.z,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zzzw_get(stdmath_degree4* p) { return stdmath_degree4_zzzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zzzw_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->z = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zzwx(stdmath_degree4 v) { return {v.z,v.z,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zzwx_get(stdmath_degree4* p) { return stdmath_degree4_zzwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zzwx_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->z = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zzwy(stdmath_degree4 v) { return {v.z,v.z,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zzwy_get(stdmath_degree4* p) { return stdmath_degree4_zzwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zzwy_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->z = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zzwz(stdmath_degree4 v) { return {v.z,v.z,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zzwz_get(stdmath_degree4* p) { return stdmath_degree4_zzwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zzwz_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->z = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zzww(stdmath_degree4 v) { return {v.z,v.z,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zzww_get(stdmath_degree4* p) { return stdmath_degree4_zzww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zzww_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->z = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zwxx(stdmath_degree4 v) { return {v.z,v.w,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zwxx_get(stdmath_degree4* p) { return stdmath_degree4_zwxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zwxx_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->w = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zwxy(stdmath_degree4 v) { return {v.z,v.w,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zwxy_get(stdmath_degree4* p) { return stdmath_degree4_zwxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zwxy_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->w = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zwxz(stdmath_degree4 v) { return {v.z,v.w,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zwxz_get(stdmath_degree4* p) { return stdmath_degree4_zwxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zwxz_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->w = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zwxw(stdmath_degree4 v) { return {v.z,v.w,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zwxw_get(stdmath_degree4* p) { return stdmath_degree4_zwxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zwxw_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->w = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zwyx(stdmath_degree4 v) { return {v.z,v.w,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zwyx_get(stdmath_degree4* p) { return stdmath_degree4_zwyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zwyx_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->w = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zwyy(stdmath_degree4 v) { return {v.z,v.w,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zwyy_get(stdmath_degree4* p) { return stdmath_degree4_zwyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zwyy_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->w = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zwyz(stdmath_degree4 v) { return {v.z,v.w,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zwyz_get(stdmath_degree4* p) { return stdmath_degree4_zwyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zwyz_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->w = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zwyw(stdmath_degree4 v) { return {v.z,v.w,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zwyw_get(stdmath_degree4* p) { return stdmath_degree4_zwyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zwyw_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->w = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zwzx(stdmath_degree4 v) { return {v.z,v.w,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zwzx_get(stdmath_degree4* p) { return stdmath_degree4_zwzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zwzx_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->w = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zwzy(stdmath_degree4 v) { return {v.z,v.w,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zwzy_get(stdmath_degree4* p) { return stdmath_degree4_zwzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zwzy_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->w = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zwzz(stdmath_degree4 v) { return {v.z,v.w,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zwzz_get(stdmath_degree4* p) { return stdmath_degree4_zwzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zwzz_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->w = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zwzw(stdmath_degree4 v) { return {v.z,v.w,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zwzw_get(stdmath_degree4* p) { return stdmath_degree4_zwzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zwzw_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->w = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zwwx(stdmath_degree4 v) { return {v.z,v.w,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zwwx_get(stdmath_degree4* p) { return stdmath_degree4_zwwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zwwx_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->w = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zwwy(stdmath_degree4 v) { return {v.z,v.w,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zwwy_get(stdmath_degree4* p) { return stdmath_degree4_zwwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zwwy_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->w = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zwwz(stdmath_degree4 v) { return {v.z,v.w,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zwwz_get(stdmath_degree4* p) { return stdmath_degree4_zwwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zwwz_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->w = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zwww(stdmath_degree4 v) { return {v.z,v.w,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zwww_get(stdmath_degree4* p) { return stdmath_degree4_zwww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_zwww_set(stdmath_degree4* p, stdmath_degree4 value) { p->z = value.x; p->w = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wxxx(stdmath_degree4 v) { return {v.w,v.x,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wxxx_get(stdmath_degree4* p) { return stdmath_degree4_wxxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wxxx_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->x = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wxxy(stdmath_degree4 v) { return {v.w,v.x,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wxxy_get(stdmath_degree4* p) { return stdmath_degree4_wxxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wxxy_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->x = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wxxz(stdmath_degree4 v) { return {v.w,v.x,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wxxz_get(stdmath_degree4* p) { return stdmath_degree4_wxxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wxxz_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->x = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wxxw(stdmath_degree4 v) { return {v.w,v.x,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wxxw_get(stdmath_degree4* p) { return stdmath_degree4_wxxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wxxw_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->x = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wxyx(stdmath_degree4 v) { return {v.w,v.x,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wxyx_get(stdmath_degree4* p) { return stdmath_degree4_wxyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wxyx_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->x = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wxyy(stdmath_degree4 v) { return {v.w,v.x,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wxyy_get(stdmath_degree4* p) { return stdmath_degree4_wxyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wxyy_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->x = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wxyz(stdmath_degree4 v) { return {v.w,v.x,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wxyz_get(stdmath_degree4* p) { return stdmath_degree4_wxyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wxyz_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->x = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wxyw(stdmath_degree4 v) { return {v.w,v.x,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wxyw_get(stdmath_degree4* p) { return stdmath_degree4_wxyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wxyw_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->x = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wxzx(stdmath_degree4 v) { return {v.w,v.x,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wxzx_get(stdmath_degree4* p) { return stdmath_degree4_wxzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wxzx_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->x = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wxzy(stdmath_degree4 v) { return {v.w,v.x,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wxzy_get(stdmath_degree4* p) { return stdmath_degree4_wxzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wxzy_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->x = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wxzz(stdmath_degree4 v) { return {v.w,v.x,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wxzz_get(stdmath_degree4* p) { return stdmath_degree4_wxzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wxzz_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->x = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wxzw(stdmath_degree4 v) { return {v.w,v.x,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wxzw_get(stdmath_degree4* p) { return stdmath_degree4_wxzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wxzw_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->x = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wxwx(stdmath_degree4 v) { return {v.w,v.x,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wxwx_get(stdmath_degree4* p) { return stdmath_degree4_wxwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wxwx_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->x = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wxwy(stdmath_degree4 v) { return {v.w,v.x,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wxwy_get(stdmath_degree4* p) { return stdmath_degree4_wxwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wxwy_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->x = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wxwz(stdmath_degree4 v) { return {v.w,v.x,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wxwz_get(stdmath_degree4* p) { return stdmath_degree4_wxwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wxwz_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->x = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wxww(stdmath_degree4 v) { return {v.w,v.x,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wxww_get(stdmath_degree4* p) { return stdmath_degree4_wxww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wxww_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->x = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wyxx(stdmath_degree4 v) { return {v.w,v.y,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wyxx_get(stdmath_degree4* p) { return stdmath_degree4_wyxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wyxx_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->y = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wyxy(stdmath_degree4 v) { return {v.w,v.y,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wyxy_get(stdmath_degree4* p) { return stdmath_degree4_wyxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wyxy_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->y = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wyxz(stdmath_degree4 v) { return {v.w,v.y,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wyxz_get(stdmath_degree4* p) { return stdmath_degree4_wyxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wyxz_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->y = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wyxw(stdmath_degree4 v) { return {v.w,v.y,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wyxw_get(stdmath_degree4* p) { return stdmath_degree4_wyxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wyxw_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->y = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wyyx(stdmath_degree4 v) { return {v.w,v.y,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wyyx_get(stdmath_degree4* p) { return stdmath_degree4_wyyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wyyx_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->y = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wyyy(stdmath_degree4 v) { return {v.w,v.y,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wyyy_get(stdmath_degree4* p) { return stdmath_degree4_wyyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wyyy_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->y = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wyyz(stdmath_degree4 v) { return {v.w,v.y,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wyyz_get(stdmath_degree4* p) { return stdmath_degree4_wyyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wyyz_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->y = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wyyw(stdmath_degree4 v) { return {v.w,v.y,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wyyw_get(stdmath_degree4* p) { return stdmath_degree4_wyyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wyyw_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->y = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wyzx(stdmath_degree4 v) { return {v.w,v.y,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wyzx_get(stdmath_degree4* p) { return stdmath_degree4_wyzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wyzx_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->y = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wyzy(stdmath_degree4 v) { return {v.w,v.y,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wyzy_get(stdmath_degree4* p) { return stdmath_degree4_wyzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wyzy_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->y = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wyzz(stdmath_degree4 v) { return {v.w,v.y,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wyzz_get(stdmath_degree4* p) { return stdmath_degree4_wyzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wyzz_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->y = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wyzw(stdmath_degree4 v) { return {v.w,v.y,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wyzw_get(stdmath_degree4* p) { return stdmath_degree4_wyzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wyzw_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->y = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wywx(stdmath_degree4 v) { return {v.w,v.y,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wywx_get(stdmath_degree4* p) { return stdmath_degree4_wywx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wywx_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->y = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wywy(stdmath_degree4 v) { return {v.w,v.y,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wywy_get(stdmath_degree4* p) { return stdmath_degree4_wywy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wywy_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->y = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wywz(stdmath_degree4 v) { return {v.w,v.y,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wywz_get(stdmath_degree4* p) { return stdmath_degree4_wywz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wywz_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->y = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wyww(stdmath_degree4 v) { return {v.w,v.y,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wyww_get(stdmath_degree4* p) { return stdmath_degree4_wyww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wyww_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->y = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wzxx(stdmath_degree4 v) { return {v.w,v.z,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wzxx_get(stdmath_degree4* p) { return stdmath_degree4_wzxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wzxx_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->z = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wzxy(stdmath_degree4 v) { return {v.w,v.z,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wzxy_get(stdmath_degree4* p) { return stdmath_degree4_wzxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wzxy_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->z = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wzxz(stdmath_degree4 v) { return {v.w,v.z,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wzxz_get(stdmath_degree4* p) { return stdmath_degree4_wzxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wzxz_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->z = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wzxw(stdmath_degree4 v) { return {v.w,v.z,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wzxw_get(stdmath_degree4* p) { return stdmath_degree4_wzxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wzxw_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->z = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wzyx(stdmath_degree4 v) { return {v.w,v.z,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wzyx_get(stdmath_degree4* p) { return stdmath_degree4_wzyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wzyx_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->z = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wzyy(stdmath_degree4 v) { return {v.w,v.z,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wzyy_get(stdmath_degree4* p) { return stdmath_degree4_wzyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wzyy_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->z = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wzyz(stdmath_degree4 v) { return {v.w,v.z,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wzyz_get(stdmath_degree4* p) { return stdmath_degree4_wzyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wzyz_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->z = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wzyw(stdmath_degree4 v) { return {v.w,v.z,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wzyw_get(stdmath_degree4* p) { return stdmath_degree4_wzyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wzyw_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->z = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wzzx(stdmath_degree4 v) { return {v.w,v.z,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wzzx_get(stdmath_degree4* p) { return stdmath_degree4_wzzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wzzx_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->z = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wzzy(stdmath_degree4 v) { return {v.w,v.z,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wzzy_get(stdmath_degree4* p) { return stdmath_degree4_wzzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wzzy_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->z = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wzzz(stdmath_degree4 v) { return {v.w,v.z,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wzzz_get(stdmath_degree4* p) { return stdmath_degree4_wzzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wzzz_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->z = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wzzw(stdmath_degree4 v) { return {v.w,v.z,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wzzw_get(stdmath_degree4* p) { return stdmath_degree4_wzzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wzzw_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->z = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wzwx(stdmath_degree4 v) { return {v.w,v.z,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wzwx_get(stdmath_degree4* p) { return stdmath_degree4_wzwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wzwx_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->z = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wzwy(stdmath_degree4 v) { return {v.w,v.z,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wzwy_get(stdmath_degree4* p) { return stdmath_degree4_wzwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wzwy_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->z = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wzwz(stdmath_degree4 v) { return {v.w,v.z,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wzwz_get(stdmath_degree4* p) { return stdmath_degree4_wzwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wzwz_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->z = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wzww(stdmath_degree4 v) { return {v.w,v.z,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wzww_get(stdmath_degree4* p) { return stdmath_degree4_wzww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wzww_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->z = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wwxx(stdmath_degree4 v) { return {v.w,v.w,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wwxx_get(stdmath_degree4* p) { return stdmath_degree4_wwxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wwxx_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->w = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wwxy(stdmath_degree4 v) { return {v.w,v.w,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wwxy_get(stdmath_degree4* p) { return stdmath_degree4_wwxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wwxy_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->w = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wwxz(stdmath_degree4 v) { return {v.w,v.w,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wwxz_get(stdmath_degree4* p) { return stdmath_degree4_wwxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wwxz_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->w = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wwxw(stdmath_degree4 v) { return {v.w,v.w,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wwxw_get(stdmath_degree4* p) { return stdmath_degree4_wwxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wwxw_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->w = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wwyx(stdmath_degree4 v) { return {v.w,v.w,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wwyx_get(stdmath_degree4* p) { return stdmath_degree4_wwyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wwyx_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->w = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wwyy(stdmath_degree4 v) { return {v.w,v.w,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wwyy_get(stdmath_degree4* p) { return stdmath_degree4_wwyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wwyy_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->w = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wwyz(stdmath_degree4 v) { return {v.w,v.w,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wwyz_get(stdmath_degree4* p) { return stdmath_degree4_wwyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wwyz_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->w = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wwyw(stdmath_degree4 v) { return {v.w,v.w,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wwyw_get(stdmath_degree4* p) { return stdmath_degree4_wwyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wwyw_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->w = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wwzx(stdmath_degree4 v) { return {v.w,v.w,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wwzx_get(stdmath_degree4* p) { return stdmath_degree4_wwzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wwzx_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->w = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wwzy(stdmath_degree4 v) { return {v.w,v.w,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wwzy_get(stdmath_degree4* p) { return stdmath_degree4_wwzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wwzy_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->w = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wwzz(stdmath_degree4 v) { return {v.w,v.w,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wwzz_get(stdmath_degree4* p) { return stdmath_degree4_wwzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wwzz_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->w = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wwzw(stdmath_degree4 v) { return {v.w,v.w,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wwzw_get(stdmath_degree4* p) { return stdmath_degree4_wwzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wwzw_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->w = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wwwx(stdmath_degree4 v) { return {v.w,v.w,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wwwx_get(stdmath_degree4* p) { return stdmath_degree4_wwwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wwwx_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->w = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wwwy(stdmath_degree4 v) { return {v.w,v.w,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wwwy_get(stdmath_degree4* p) { return stdmath_degree4_wwwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wwwy_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->w = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wwwz(stdmath_degree4 v) { return {v.w,v.w,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wwwz_get(stdmath_degree4* p) { return stdmath_degree4_wwwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wwwz_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->w = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wwww(stdmath_degree4 v) { return {v.w,v.w,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wwww_get(stdmath_degree4* p) { return stdmath_degree4_wwww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree4 stdmath_degree4_wwww_set(stdmath_degree4* p, stdmath_degree4 value) { p->w = value.x; p->w = value.y; p->w = value.z; p->w = value.w; return *p; }

#endif

#ifdef __cplusplus
} // extern "C"
#endif

#ifdef STDMATH_IMPLEMENTATION
#ifndef __cplusplus
#error "The stdmath implementations require a C++ compiler"
#endif

#ifndef STDMATH_MODULE
import stdmath.slang;
#endif

inline stdmath::degree4 c(stdmath_degree4 c) {
	return (stdmath::degree4&)c;
}
inline stdmath_degree4 c(stdmath::degree4 c) {
	return (stdmath_degree4&)c;
}

#ifdef __cplusplus
extern "C" {
#endif

stdmath_degree4 stdmath_degree4_broadcast(stdmath_degree all) {
	return c(stdmath::degree4((stdmath::degree4::underlying_type&)all));
}

stdmath_degree4 stdmath_degree4_add(stdmath_degree4 a, stdmath_degree4 b) {
	return c(c(a) + c(b));
}
stdmath_degree4 stdmath_degree4_subtract(stdmath_degree4 a, stdmath_degree4 b) {
	return c(c(a) - c(b));
}
stdmath_degree4 stdmath_degree4_negate(stdmath_degree4 v) {
#if !false && !true
	return c(stdmath::degree4(-(stdmath::vector<stdmath_degree, 4>)c(v)));
#else
	assert(false && "TODO: Why can't we use - on vector<degree/radian, N>?");
#endif
}
stdmath_degree4 stdmath_degree4_multiply(stdmath_degree4 a, stdmath_degree4 b) {
	return c(c(a) * c(b));
}
stdmath_degree4 stdmath_degree4_divide(stdmath_degree4 a, stdmath_degree4 b) {
	return c(c(a) / c(b));
}
stdmath_degree4 stdmath_degree4_scale(stdmath_degree4 v, stdmath_degree s) {
	return c(c(v) * (stdmath::degree4::underlying_type&)s);
}

#if false
stdmath_degree4 stdmath_degree4_modulus(stdmath_degree4 a, stdmath_degree4 b) {
	return c(c(a) % c(b));
}
stdmath_degree4 stdmath_degree4_logical_not(stdmath_degree4 v) {
	return c(!c(v));
}
stdmath_degree4 stdmath_degree4_bitwise_not(stdmath_degree4 v) {
	return c(~c(v));
}
stdmath_degree4 stdmath_degree4_logical_and(stdmath_degree4 a, stdmath_degree4 b) {
	return c(c(a) && c(b));
}
stdmath_degree4 stdmath_degree4_bitwise_and(stdmath_degree4 a, stdmath_degree4 b) {
	return c(c(a) & c(b));
}
stdmath_degree4 stdmath_degree4_logical_or(stdmath_degree4 a, stdmath_degree4 b) {
	return c(c(a) || c(b));
}
stdmath_degree4 stdmath_degree4_bitwise_or(stdmath_degree4 a, stdmath_degree4 b) {
	return c(c(a) | c(b));
}
stdmath_degree4 stdmath_degree4_bitwise_xor(stdmath_degree4 a, stdmath_degree4 b) {
	return c(c(a) ^ c(b));
}
stdmath_degree4 stdmath_degree4_shift_left(stdmath_degree4 a, stdmath_degree4 b) {
	return c(c(a) << c(b));
}
stdmath_degree4 stdmath_degree4_shift_right(stdmath_degree4 a, stdmath_degree4 b) {
	return c(c(a) >> c(b));
}
#endif

stdmath_bool4 stdmath_degree4_equal_to(stdmath_degree4 a, stdmath_degree4 b) {
	return c(c(a) == c(b));
}
stdmath_bool4 stdmath_degree4_not_equal_to(stdmath_degree4 a, stdmath_degree4 b) {
	return c(c(a) != c(b));
}
stdmath_bool4 stdmath_degree4_less_than(stdmath_degree4 a, stdmath_degree4 b) {
	return c(c(a) < c(b));
}
stdmath_bool4 stdmath_degree4_less_than_or_equal_to(stdmath_degree4 a, stdmath_degree4 b) {
	return c(c(a) <= c(b));
}
stdmath_bool4 stdmath_degree4_greater_than(stdmath_degree4 a, stdmath_degree4 b) {
	return c(c(a) > c(b));
}
stdmath_bool4 stdmath_degree4_greater_than_or_equal_to(stdmath_degree4 a, stdmath_degree4 b) {
	return c(c(a) >= c(b));
}

stdmath_degree stdmath_degree4_length_squared(stdmath_degree4 v)  {
	auto out = c(v).length_squared();
	return (stdmath_degree&)out;
}
stdmath_degree stdmath_degree4_length(stdmath_degree4 v)  {
	auto out = c(v).length();
	return (stdmath_degree&)out;
}
stdmath_degree stdmath_degree4_dot(stdmath_degree4 a, stdmath_degree4 b)  {
	auto out = dot(c(a), c(b));
	return (stdmath_degree&)out;
}
stdmath_degree stdmath_degree4_min_element(stdmath_degree4 v)  {
	auto out = c(v).min_element();
	return (stdmath_degree&)out;
}
stdmath_degree stdmath_degree4_max_element(stdmath_degree4 v)  {
	auto out = c(v).max_element();
	return (stdmath_degree&)out;
}

// stdmath_degree4 stdmath_degree4_elementwise_transform(stdmath_degree4 v, stdmath_degree(*func)(stdmath_degree)) {
// 	return c(c(v).elementwise_transform(func));
// }
// stdmath_degree stdmath_degree4_reduce_elements(stdmath_degree4 v, stdmath_degree initial_value, stdmath_degree(*reducer)(stdmath_degree4, stdmath_degree4)) {
// 	return c(v).reduce_elements(initial_value, reducer);
// }

#if 4 == 3
stdmath_degree4 stdmath_degree4_cross(stdmath_degree4 a, stdmath_degree4 b) {
	return c(cross(c(a), c(b)));
}
#endif

stdmath_degree4 stdmath_degree4_min(stdmath_degree4 a, stdmath_degree4 b) {
	return c(min(c(a), c(b)));
}
stdmath_degree4 stdmath_degree4_max(stdmath_degree4 a, stdmath_degree4 b) {
	return c(max(c(a), c(b)));
}
stdmath_degree4 stdmath_degree4_normalize(stdmath_degree4 v) {
	return c(normalize(c(v)));
}
stdmath_degree4 stdmath_degree4_lerp(stdmath_degree4 a, stdmath_degree4 b, float t) {
	return c(lerp(c(a), c(b), t));
}
stdmath_degree4 stdmath_degree4_clamp(stdmath_degree4 a, stdmath_degree4 min, stdmath_degree4 max) {
	return c(clamp(c(a), c(min), c(max)));
}
stdmath_degree4 stdmath_degree4_reflect(stdmath_degree4 a, stdmath_degree4 b) {
	return c(reflect(c(a), c(b)));
}
stdmath_bool4 stdmath_degree4_approximately_equal(stdmath_degree4 a, stdmath_degree4 b) {
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

#ifdef __cplusplus
} // extern "C"
#endif

#endif // STDMATH_IMPLEMENTATION

#endif // __STDMATH_stdmath_degree4_H__