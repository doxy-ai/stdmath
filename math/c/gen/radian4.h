#ifndef __STDMATH_stdmath_radian4_H__
#define __STDMATH_stdmath_radian4_H__

#ifndef STDMATH_MODULE
#include <stdint.h>
#include <assert.h>
#endif
#include "../maybe_export.h"

#if true
#include "radian.h"
#endif
#if false
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
#include "radian1.h"
#elif 4 == 3
#include "radian2.h"
#include "radian1.h"
#elif 4 == 4
#include "radian3.h"
#include "radian2.h"
#include "radian1.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if 4 == 1
STDMATH_EXPORT union stdmath_radian1 {
	struct {
		stdmath_radian x;
	};
	stdmath_radian data[1];
};
#elif 4 == 2
STDMATH_EXPORT union stdmath_radian2 {
	struct {
		stdmath_radian x, y;
	};
	struct {
		stdmath_radian u, v;
	};
	stdmath_radian data[2];
};
#elif 4 == 3
STDMATH_EXPORT union stdmath_radian3 {
	struct {
		stdmath_radian x, y, z;
	};
	struct {
		stdmath_radian r, g, b;
	};
	struct {
		stdmath_radian h, s, v;
	};
	stdmath_radian data[4]; // radian3s are aligned as if they were radian4s
};
#elif 4 == 4
STDMATH_EXPORT union stdmath_radian4 {
	struct {
		stdmath_radian x, y, z, w;
	};
	struct {
		stdmath_radian r, g, b, a;
	};
	struct {
		stdmath_radian h, s, v;
	};
	stdmath_radian data[4];
};
#endif

STDMATH_EXPORT stdmath_radian4 stdmath_radian4_broadcast(stdmath_radian all);

STDMATH_EXPORT stdmath_radian4 stdmath_radian4_add(stdmath_radian4 a, stdmath_radian4 b);
STDMATH_EXPORT stdmath_radian4 stdmath_radian4_subtract(stdmath_radian4 a, stdmath_radian4 b);
STDMATH_EXPORT stdmath_radian4 stdmath_radian4_negate(stdmath_radian4 v);
STDMATH_EXPORT stdmath_radian4 stdmath_radian4_multiply(stdmath_radian4 a, stdmath_radian4 b);
STDMATH_EXPORT stdmath_radian4 stdmath_radian4_divide(stdmath_radian4 a, stdmath_radian4 b);
STDMATH_EXPORT stdmath_radian4 stdmath_radian4_scale(stdmath_radian4 v, stdmath_radian s);

#if false
STDMATH_EXPORT stdmath_radian4 stdmath_radian4_modulus(stdmath_radian4 a, stdmath_radian4 b);
STDMATH_EXPORT stdmath_radian4 stdmath_radian4_logical_not(stdmath_radian4 v);
STDMATH_EXPORT stdmath_radian4 stdmath_radian4_bitwise_not(stdmath_radian4 v);
STDMATH_EXPORT stdmath_radian4 stdmath_radian4_logical_and(stdmath_radian4 a, stdmath_radian4 b);
STDMATH_EXPORT stdmath_radian4 stdmath_radian4_bitwise_and(stdmath_radian4 a, stdmath_radian4 b);
STDMATH_EXPORT stdmath_radian4 stdmath_radian4_logical_or(stdmath_radian4 a, stdmath_radian4 b);
STDMATH_EXPORT stdmath_radian4 stdmath_radian4_bitwise_or(stdmath_radian4 a, stdmath_radian4 b);
STDMATH_EXPORT stdmath_radian4 stdmath_radian4_bitwise_xor(stdmath_radian4 a, stdmath_radian4 b);
STDMATH_EXPORT stdmath_radian4 stdmath_radian4_shift_left(stdmath_radian4 a, stdmath_radian4 b);
STDMATH_EXPORT stdmath_radian4 stdmath_radian4_shift_right(stdmath_radian4 a, stdmath_radian4 b);
#endif

STDMATH_EXPORT stdmath_bool4 stdmath_radian4_equal_to(stdmath_radian4 a, stdmath_radian4 b);
STDMATH_EXPORT stdmath_bool4 stdmath_radian4_not_equal_to(stdmath_radian4 a, stdmath_radian4 b);
STDMATH_EXPORT stdmath_bool4 stdmath_radian4_less_than(stdmath_radian4 a, stdmath_radian4 b);
STDMATH_EXPORT stdmath_bool4 stdmath_radian4_less_than_or_equal_to(stdmath_radian4 a, stdmath_radian4 b);
STDMATH_EXPORT stdmath_bool4 stdmath_radian4_greater_than(stdmath_radian4 a, stdmath_radian4 b);
STDMATH_EXPORT stdmath_bool4 stdmath_radian4_greater_than_or_equal_to(stdmath_radian4 a, stdmath_radian4 b);

STDMATH_EXPORT stdmath_radian stdmath_radian4_length_squared(stdmath_radian4 v);
STDMATH_EXPORT stdmath_radian stdmath_radian4_length(stdmath_radian4 v);
STDMATH_EXPORT stdmath_radian stdmath_radian4_dot(stdmath_radian4 a, stdmath_radian4 b);
STDMATH_EXPORT stdmath_radian stdmath_radian4_min_element(stdmath_radian4 v);
STDMATH_EXPORT stdmath_radian stdmath_radian4_max_element(stdmath_radian4 v);

// STDMATH_EXPORT stdmath_radian4 stdmath_radian4_elementwise_transform(stdmath_radian4 v, stdmath_radian(*func)(stdmath_radian));
// STDMATH_EXPORT stdmath_radian stdmath_radian4_reduce_elements(stdmath_radian4 v, stdmath_radian initial_value, stdmath_radian(*reducer)(stdmath_radian4, stdmath_radian4));

#if 4 == 3
STDMATH_EXPORT stdmath_radian3 stdmath_radian3_cross(stdmath_radian3 a, stdmath_radian3 b);
#endif

STDMATH_EXPORT stdmath_radian4 stdmath_radian4_min(stdmath_radian4 a, stdmath_radian4 b);
STDMATH_EXPORT stdmath_radian4 stdmath_radian4_max(stdmath_radian4 a, stdmath_radian4 b);
STDMATH_EXPORT stdmath_radian4 stdmath_radian4_normalize(stdmath_radian4 v);
STDMATH_EXPORT stdmath_radian4 stdmath_radian4_lerp(stdmath_radian4 a, stdmath_radian4 b, float t);
STDMATH_EXPORT stdmath_radian4 stdmath_radian4_clamp(stdmath_radian4 a, stdmath_radian4 min, stdmath_radian4 max);
STDMATH_EXPORT stdmath_radian4 stdmath_radian4_reflect(stdmath_radian4 a, stdmath_radian4 b);
STDMATH_EXPORT stdmath_bool4 stdmath_radian4_approximately_equal(stdmath_radian4 a, stdmath_radian4 b);

#if false
STDMATH_EXPORT bool stdmath_bool4_all_of(stdmath_bool4 v);
STDMATH_EXPORT bool stdmath_bool4_any_of(stdmath_bool4 v);
STDMATH_EXPORT bool stdmath_bool4_none_of(stdmath_bool4 v);
STDMATH_EXPORT bool stdmath_bool4_some_of(stdmath_bool4 v);
#endif

#ifndef STDMATH_NO_SWIZZLES
STDMATH_EXPORT STDMATH_INLINE stdmath_radian1 stdmath_radian4_x(stdmath_radian4 v) { return {v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian1 stdmath_radian4_x_get(stdmath_radian4* p) { return stdmath_radian4_x(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_x_set(stdmath_radian4* p, stdmath_radian1 value) { p->x = value.x; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian1 stdmath_radian4_y(stdmath_radian4 v) { return {v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian1 stdmath_radian4_y_get(stdmath_radian4* p) { return stdmath_radian4_y(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_y_set(stdmath_radian4* p, stdmath_radian1 value) { p->y = value.x; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian1 stdmath_radian4_z(stdmath_radian4 v) { return {v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian1 stdmath_radian4_z_get(stdmath_radian4* p) { return stdmath_radian4_z(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_z_set(stdmath_radian4* p, stdmath_radian1 value) { p->z = value.x; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian1 stdmath_radian4_w(stdmath_radian4 v) { return {v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian1 stdmath_radian4_w_get(stdmath_radian4* p) { return stdmath_radian4_w(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_w_set(stdmath_radian4* p, stdmath_radian1 value) { p->w = value.x; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian4_xx(stdmath_radian4 v) { return {v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian4_xx_get(stdmath_radian4* p) { return stdmath_radian4_xx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xx_set(stdmath_radian4* p, stdmath_radian2 value) { p->x = value.x; p->x = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian4_xy(stdmath_radian4 v) { return {v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian4_xy_get(stdmath_radian4* p) { return stdmath_radian4_xy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xy_set(stdmath_radian4* p, stdmath_radian2 value) { p->x = value.x; p->y = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian4_xz(stdmath_radian4 v) { return {v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian4_xz_get(stdmath_radian4* p) { return stdmath_radian4_xz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xz_set(stdmath_radian4* p, stdmath_radian2 value) { p->x = value.x; p->z = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian4_xw(stdmath_radian4 v) { return {v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian4_xw_get(stdmath_radian4* p) { return stdmath_radian4_xw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xw_set(stdmath_radian4* p, stdmath_radian2 value) { p->x = value.x; p->w = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian4_yx(stdmath_radian4 v) { return {v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian4_yx_get(stdmath_radian4* p) { return stdmath_radian4_yx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yx_set(stdmath_radian4* p, stdmath_radian2 value) { p->y = value.x; p->x = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian4_yy(stdmath_radian4 v) { return {v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian4_yy_get(stdmath_radian4* p) { return stdmath_radian4_yy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yy_set(stdmath_radian4* p, stdmath_radian2 value) { p->y = value.x; p->y = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian4_yz(stdmath_radian4 v) { return {v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian4_yz_get(stdmath_radian4* p) { return stdmath_radian4_yz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yz_set(stdmath_radian4* p, stdmath_radian2 value) { p->y = value.x; p->z = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian4_yw(stdmath_radian4 v) { return {v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian4_yw_get(stdmath_radian4* p) { return stdmath_radian4_yw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yw_set(stdmath_radian4* p, stdmath_radian2 value) { p->y = value.x; p->w = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian4_zx(stdmath_radian4 v) { return {v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian4_zx_get(stdmath_radian4* p) { return stdmath_radian4_zx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zx_set(stdmath_radian4* p, stdmath_radian2 value) { p->z = value.x; p->x = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian4_zy(stdmath_radian4 v) { return {v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian4_zy_get(stdmath_radian4* p) { return stdmath_radian4_zy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zy_set(stdmath_radian4* p, stdmath_radian2 value) { p->z = value.x; p->y = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian4_zz(stdmath_radian4 v) { return {v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian4_zz_get(stdmath_radian4* p) { return stdmath_radian4_zz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zz_set(stdmath_radian4* p, stdmath_radian2 value) { p->z = value.x; p->z = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian4_zw(stdmath_radian4 v) { return {v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian4_zw_get(stdmath_radian4* p) { return stdmath_radian4_zw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zw_set(stdmath_radian4* p, stdmath_radian2 value) { p->z = value.x; p->w = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian4_wx(stdmath_radian4 v) { return {v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian4_wx_get(stdmath_radian4* p) { return stdmath_radian4_wx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wx_set(stdmath_radian4* p, stdmath_radian2 value) { p->w = value.x; p->x = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian4_wy(stdmath_radian4 v) { return {v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian4_wy_get(stdmath_radian4* p) { return stdmath_radian4_wy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wy_set(stdmath_radian4* p, stdmath_radian2 value) { p->w = value.x; p->y = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian4_wz(stdmath_radian4 v) { return {v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian4_wz_get(stdmath_radian4* p) { return stdmath_radian4_wz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wz_set(stdmath_radian4* p, stdmath_radian2 value) { p->w = value.x; p->z = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian4_ww(stdmath_radian4 v) { return {v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian4_ww_get(stdmath_radian4* p) { return stdmath_radian4_ww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_ww_set(stdmath_radian4* p, stdmath_radian2 value) { p->w = value.x; p->w = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_xxx(stdmath_radian4 v) { return {v.x,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_xxx_get(stdmath_radian4* p) { return stdmath_radian4_xxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xxx_set(stdmath_radian4* p, stdmath_radian3 value) { p->x = value.x; p->x = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_xxy(stdmath_radian4 v) { return {v.x,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_xxy_get(stdmath_radian4* p) { return stdmath_radian4_xxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xxy_set(stdmath_radian4* p, stdmath_radian3 value) { p->x = value.x; p->x = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_xxz(stdmath_radian4 v) { return {v.x,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_xxz_get(stdmath_radian4* p) { return stdmath_radian4_xxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xxz_set(stdmath_radian4* p, stdmath_radian3 value) { p->x = value.x; p->x = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_xxw(stdmath_radian4 v) { return {v.x,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_xxw_get(stdmath_radian4* p) { return stdmath_radian4_xxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xxw_set(stdmath_radian4* p, stdmath_radian3 value) { p->x = value.x; p->x = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_xyx(stdmath_radian4 v) { return {v.x,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_xyx_get(stdmath_radian4* p) { return stdmath_radian4_xyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xyx_set(stdmath_radian4* p, stdmath_radian3 value) { p->x = value.x; p->y = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_xyy(stdmath_radian4 v) { return {v.x,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_xyy_get(stdmath_radian4* p) { return stdmath_radian4_xyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xyy_set(stdmath_radian4* p, stdmath_radian3 value) { p->x = value.x; p->y = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_xyz(stdmath_radian4 v) { return {v.x,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_xyz_get(stdmath_radian4* p) { return stdmath_radian4_xyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xyz_set(stdmath_radian4* p, stdmath_radian3 value) { p->x = value.x; p->y = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_xyw(stdmath_radian4 v) { return {v.x,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_xyw_get(stdmath_radian4* p) { return stdmath_radian4_xyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xyw_set(stdmath_radian4* p, stdmath_radian3 value) { p->x = value.x; p->y = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_xzx(stdmath_radian4 v) { return {v.x,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_xzx_get(stdmath_radian4* p) { return stdmath_radian4_xzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xzx_set(stdmath_radian4* p, stdmath_radian3 value) { p->x = value.x; p->z = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_xzy(stdmath_radian4 v) { return {v.x,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_xzy_get(stdmath_radian4* p) { return stdmath_radian4_xzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xzy_set(stdmath_radian4* p, stdmath_radian3 value) { p->x = value.x; p->z = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_xzz(stdmath_radian4 v) { return {v.x,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_xzz_get(stdmath_radian4* p) { return stdmath_radian4_xzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xzz_set(stdmath_radian4* p, stdmath_radian3 value) { p->x = value.x; p->z = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_xzw(stdmath_radian4 v) { return {v.x,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_xzw_get(stdmath_radian4* p) { return stdmath_radian4_xzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xzw_set(stdmath_radian4* p, stdmath_radian3 value) { p->x = value.x; p->z = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_xwx(stdmath_radian4 v) { return {v.x,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_xwx_get(stdmath_radian4* p) { return stdmath_radian4_xwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xwx_set(stdmath_radian4* p, stdmath_radian3 value) { p->x = value.x; p->w = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_xwy(stdmath_radian4 v) { return {v.x,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_xwy_get(stdmath_radian4* p) { return stdmath_radian4_xwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xwy_set(stdmath_radian4* p, stdmath_radian3 value) { p->x = value.x; p->w = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_xwz(stdmath_radian4 v) { return {v.x,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_xwz_get(stdmath_radian4* p) { return stdmath_radian4_xwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xwz_set(stdmath_radian4* p, stdmath_radian3 value) { p->x = value.x; p->w = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_xww(stdmath_radian4 v) { return {v.x,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_xww_get(stdmath_radian4* p) { return stdmath_radian4_xww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xww_set(stdmath_radian4* p, stdmath_radian3 value) { p->x = value.x; p->w = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_yxx(stdmath_radian4 v) { return {v.y,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_yxx_get(stdmath_radian4* p) { return stdmath_radian4_yxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yxx_set(stdmath_radian4* p, stdmath_radian3 value) { p->y = value.x; p->x = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_yxy(stdmath_radian4 v) { return {v.y,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_yxy_get(stdmath_radian4* p) { return stdmath_radian4_yxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yxy_set(stdmath_radian4* p, stdmath_radian3 value) { p->y = value.x; p->x = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_yxz(stdmath_radian4 v) { return {v.y,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_yxz_get(stdmath_radian4* p) { return stdmath_radian4_yxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yxz_set(stdmath_radian4* p, stdmath_radian3 value) { p->y = value.x; p->x = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_yxw(stdmath_radian4 v) { return {v.y,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_yxw_get(stdmath_radian4* p) { return stdmath_radian4_yxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yxw_set(stdmath_radian4* p, stdmath_radian3 value) { p->y = value.x; p->x = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_yyx(stdmath_radian4 v) { return {v.y,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_yyx_get(stdmath_radian4* p) { return stdmath_radian4_yyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yyx_set(stdmath_radian4* p, stdmath_radian3 value) { p->y = value.x; p->y = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_yyy(stdmath_radian4 v) { return {v.y,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_yyy_get(stdmath_radian4* p) { return stdmath_radian4_yyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yyy_set(stdmath_radian4* p, stdmath_radian3 value) { p->y = value.x; p->y = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_yyz(stdmath_radian4 v) { return {v.y,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_yyz_get(stdmath_radian4* p) { return stdmath_radian4_yyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yyz_set(stdmath_radian4* p, stdmath_radian3 value) { p->y = value.x; p->y = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_yyw(stdmath_radian4 v) { return {v.y,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_yyw_get(stdmath_radian4* p) { return stdmath_radian4_yyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yyw_set(stdmath_radian4* p, stdmath_radian3 value) { p->y = value.x; p->y = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_yzx(stdmath_radian4 v) { return {v.y,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_yzx_get(stdmath_radian4* p) { return stdmath_radian4_yzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yzx_set(stdmath_radian4* p, stdmath_radian3 value) { p->y = value.x; p->z = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_yzy(stdmath_radian4 v) { return {v.y,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_yzy_get(stdmath_radian4* p) { return stdmath_radian4_yzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yzy_set(stdmath_radian4* p, stdmath_radian3 value) { p->y = value.x; p->z = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_yzz(stdmath_radian4 v) { return {v.y,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_yzz_get(stdmath_radian4* p) { return stdmath_radian4_yzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yzz_set(stdmath_radian4* p, stdmath_radian3 value) { p->y = value.x; p->z = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_yzw(stdmath_radian4 v) { return {v.y,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_yzw_get(stdmath_radian4* p) { return stdmath_radian4_yzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yzw_set(stdmath_radian4* p, stdmath_radian3 value) { p->y = value.x; p->z = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_ywx(stdmath_radian4 v) { return {v.y,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_ywx_get(stdmath_radian4* p) { return stdmath_radian4_ywx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_ywx_set(stdmath_radian4* p, stdmath_radian3 value) { p->y = value.x; p->w = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_ywy(stdmath_radian4 v) { return {v.y,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_ywy_get(stdmath_radian4* p) { return stdmath_radian4_ywy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_ywy_set(stdmath_radian4* p, stdmath_radian3 value) { p->y = value.x; p->w = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_ywz(stdmath_radian4 v) { return {v.y,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_ywz_get(stdmath_radian4* p) { return stdmath_radian4_ywz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_ywz_set(stdmath_radian4* p, stdmath_radian3 value) { p->y = value.x; p->w = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_yww(stdmath_radian4 v) { return {v.y,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_yww_get(stdmath_radian4* p) { return stdmath_radian4_yww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yww_set(stdmath_radian4* p, stdmath_radian3 value) { p->y = value.x; p->w = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_zxx(stdmath_radian4 v) { return {v.z,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_zxx_get(stdmath_radian4* p) { return stdmath_radian4_zxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zxx_set(stdmath_radian4* p, stdmath_radian3 value) { p->z = value.x; p->x = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_zxy(stdmath_radian4 v) { return {v.z,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_zxy_get(stdmath_radian4* p) { return stdmath_radian4_zxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zxy_set(stdmath_radian4* p, stdmath_radian3 value) { p->z = value.x; p->x = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_zxz(stdmath_radian4 v) { return {v.z,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_zxz_get(stdmath_radian4* p) { return stdmath_radian4_zxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zxz_set(stdmath_radian4* p, stdmath_radian3 value) { p->z = value.x; p->x = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_zxw(stdmath_radian4 v) { return {v.z,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_zxw_get(stdmath_radian4* p) { return stdmath_radian4_zxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zxw_set(stdmath_radian4* p, stdmath_radian3 value) { p->z = value.x; p->x = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_zyx(stdmath_radian4 v) { return {v.z,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_zyx_get(stdmath_radian4* p) { return stdmath_radian4_zyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zyx_set(stdmath_radian4* p, stdmath_radian3 value) { p->z = value.x; p->y = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_zyy(stdmath_radian4 v) { return {v.z,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_zyy_get(stdmath_radian4* p) { return stdmath_radian4_zyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zyy_set(stdmath_radian4* p, stdmath_radian3 value) { p->z = value.x; p->y = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_zyz(stdmath_radian4 v) { return {v.z,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_zyz_get(stdmath_radian4* p) { return stdmath_radian4_zyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zyz_set(stdmath_radian4* p, stdmath_radian3 value) { p->z = value.x; p->y = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_zyw(stdmath_radian4 v) { return {v.z,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_zyw_get(stdmath_radian4* p) { return stdmath_radian4_zyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zyw_set(stdmath_radian4* p, stdmath_radian3 value) { p->z = value.x; p->y = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_zzx(stdmath_radian4 v) { return {v.z,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_zzx_get(stdmath_radian4* p) { return stdmath_radian4_zzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zzx_set(stdmath_radian4* p, stdmath_radian3 value) { p->z = value.x; p->z = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_zzy(stdmath_radian4 v) { return {v.z,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_zzy_get(stdmath_radian4* p) { return stdmath_radian4_zzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zzy_set(stdmath_radian4* p, stdmath_radian3 value) { p->z = value.x; p->z = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_zzz(stdmath_radian4 v) { return {v.z,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_zzz_get(stdmath_radian4* p) { return stdmath_radian4_zzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zzz_set(stdmath_radian4* p, stdmath_radian3 value) { p->z = value.x; p->z = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_zzw(stdmath_radian4 v) { return {v.z,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_zzw_get(stdmath_radian4* p) { return stdmath_radian4_zzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zzw_set(stdmath_radian4* p, stdmath_radian3 value) { p->z = value.x; p->z = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_zwx(stdmath_radian4 v) { return {v.z,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_zwx_get(stdmath_radian4* p) { return stdmath_radian4_zwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zwx_set(stdmath_radian4* p, stdmath_radian3 value) { p->z = value.x; p->w = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_zwy(stdmath_radian4 v) { return {v.z,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_zwy_get(stdmath_radian4* p) { return stdmath_radian4_zwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zwy_set(stdmath_radian4* p, stdmath_radian3 value) { p->z = value.x; p->w = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_zwz(stdmath_radian4 v) { return {v.z,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_zwz_get(stdmath_radian4* p) { return stdmath_radian4_zwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zwz_set(stdmath_radian4* p, stdmath_radian3 value) { p->z = value.x; p->w = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_zww(stdmath_radian4 v) { return {v.z,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_zww_get(stdmath_radian4* p) { return stdmath_radian4_zww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zww_set(stdmath_radian4* p, stdmath_radian3 value) { p->z = value.x; p->w = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_wxx(stdmath_radian4 v) { return {v.w,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_wxx_get(stdmath_radian4* p) { return stdmath_radian4_wxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wxx_set(stdmath_radian4* p, stdmath_radian3 value) { p->w = value.x; p->x = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_wxy(stdmath_radian4 v) { return {v.w,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_wxy_get(stdmath_radian4* p) { return stdmath_radian4_wxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wxy_set(stdmath_radian4* p, stdmath_radian3 value) { p->w = value.x; p->x = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_wxz(stdmath_radian4 v) { return {v.w,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_wxz_get(stdmath_radian4* p) { return stdmath_radian4_wxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wxz_set(stdmath_radian4* p, stdmath_radian3 value) { p->w = value.x; p->x = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_wxw(stdmath_radian4 v) { return {v.w,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_wxw_get(stdmath_radian4* p) { return stdmath_radian4_wxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wxw_set(stdmath_radian4* p, stdmath_radian3 value) { p->w = value.x; p->x = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_wyx(stdmath_radian4 v) { return {v.w,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_wyx_get(stdmath_radian4* p) { return stdmath_radian4_wyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wyx_set(stdmath_radian4* p, stdmath_radian3 value) { p->w = value.x; p->y = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_wyy(stdmath_radian4 v) { return {v.w,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_wyy_get(stdmath_radian4* p) { return stdmath_radian4_wyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wyy_set(stdmath_radian4* p, stdmath_radian3 value) { p->w = value.x; p->y = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_wyz(stdmath_radian4 v) { return {v.w,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_wyz_get(stdmath_radian4* p) { return stdmath_radian4_wyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wyz_set(stdmath_radian4* p, stdmath_radian3 value) { p->w = value.x; p->y = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_wyw(stdmath_radian4 v) { return {v.w,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_wyw_get(stdmath_radian4* p) { return stdmath_radian4_wyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wyw_set(stdmath_radian4* p, stdmath_radian3 value) { p->w = value.x; p->y = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_wzx(stdmath_radian4 v) { return {v.w,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_wzx_get(stdmath_radian4* p) { return stdmath_radian4_wzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wzx_set(stdmath_radian4* p, stdmath_radian3 value) { p->w = value.x; p->z = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_wzy(stdmath_radian4 v) { return {v.w,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_wzy_get(stdmath_radian4* p) { return stdmath_radian4_wzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wzy_set(stdmath_radian4* p, stdmath_radian3 value) { p->w = value.x; p->z = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_wzz(stdmath_radian4 v) { return {v.w,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_wzz_get(stdmath_radian4* p) { return stdmath_radian4_wzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wzz_set(stdmath_radian4* p, stdmath_radian3 value) { p->w = value.x; p->z = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_wzw(stdmath_radian4 v) { return {v.w,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_wzw_get(stdmath_radian4* p) { return stdmath_radian4_wzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wzw_set(stdmath_radian4* p, stdmath_radian3 value) { p->w = value.x; p->z = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_wwx(stdmath_radian4 v) { return {v.w,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_wwx_get(stdmath_radian4* p) { return stdmath_radian4_wwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wwx_set(stdmath_radian4* p, stdmath_radian3 value) { p->w = value.x; p->w = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_wwy(stdmath_radian4 v) { return {v.w,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_wwy_get(stdmath_radian4* p) { return stdmath_radian4_wwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wwy_set(stdmath_radian4* p, stdmath_radian3 value) { p->w = value.x; p->w = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_wwz(stdmath_radian4 v) { return {v.w,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_wwz_get(stdmath_radian4* p) { return stdmath_radian4_wwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wwz_set(stdmath_radian4* p, stdmath_radian3 value) { p->w = value.x; p->w = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_www(stdmath_radian4 v) { return {v.w,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian4_www_get(stdmath_radian4* p) { return stdmath_radian4_www(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_www_set(stdmath_radian4* p, stdmath_radian3 value) { p->w = value.x; p->w = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xxxx(stdmath_radian4 v) { return {v.x,v.x,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xxxx_get(stdmath_radian4* p) { return stdmath_radian4_xxxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xxxx_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->x = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xxxy(stdmath_radian4 v) { return {v.x,v.x,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xxxy_get(stdmath_radian4* p) { return stdmath_radian4_xxxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xxxy_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->x = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xxxz(stdmath_radian4 v) { return {v.x,v.x,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xxxz_get(stdmath_radian4* p) { return stdmath_radian4_xxxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xxxz_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->x = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xxxw(stdmath_radian4 v) { return {v.x,v.x,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xxxw_get(stdmath_radian4* p) { return stdmath_radian4_xxxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xxxw_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->x = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xxyx(stdmath_radian4 v) { return {v.x,v.x,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xxyx_get(stdmath_radian4* p) { return stdmath_radian4_xxyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xxyx_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->x = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xxyy(stdmath_radian4 v) { return {v.x,v.x,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xxyy_get(stdmath_radian4* p) { return stdmath_radian4_xxyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xxyy_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->x = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xxyz(stdmath_radian4 v) { return {v.x,v.x,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xxyz_get(stdmath_radian4* p) { return stdmath_radian4_xxyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xxyz_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->x = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xxyw(stdmath_radian4 v) { return {v.x,v.x,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xxyw_get(stdmath_radian4* p) { return stdmath_radian4_xxyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xxyw_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->x = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xxzx(stdmath_radian4 v) { return {v.x,v.x,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xxzx_get(stdmath_radian4* p) { return stdmath_radian4_xxzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xxzx_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->x = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xxzy(stdmath_radian4 v) { return {v.x,v.x,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xxzy_get(stdmath_radian4* p) { return stdmath_radian4_xxzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xxzy_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->x = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xxzz(stdmath_radian4 v) { return {v.x,v.x,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xxzz_get(stdmath_radian4* p) { return stdmath_radian4_xxzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xxzz_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->x = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xxzw(stdmath_radian4 v) { return {v.x,v.x,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xxzw_get(stdmath_radian4* p) { return stdmath_radian4_xxzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xxzw_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->x = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xxwx(stdmath_radian4 v) { return {v.x,v.x,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xxwx_get(stdmath_radian4* p) { return stdmath_radian4_xxwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xxwx_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->x = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xxwy(stdmath_radian4 v) { return {v.x,v.x,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xxwy_get(stdmath_radian4* p) { return stdmath_radian4_xxwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xxwy_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->x = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xxwz(stdmath_radian4 v) { return {v.x,v.x,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xxwz_get(stdmath_radian4* p) { return stdmath_radian4_xxwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xxwz_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->x = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xxww(stdmath_radian4 v) { return {v.x,v.x,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xxww_get(stdmath_radian4* p) { return stdmath_radian4_xxww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xxww_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->x = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xyxx(stdmath_radian4 v) { return {v.x,v.y,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xyxx_get(stdmath_radian4* p) { return stdmath_radian4_xyxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xyxx_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->y = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xyxy(stdmath_radian4 v) { return {v.x,v.y,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xyxy_get(stdmath_radian4* p) { return stdmath_radian4_xyxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xyxy_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->y = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xyxz(stdmath_radian4 v) { return {v.x,v.y,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xyxz_get(stdmath_radian4* p) { return stdmath_radian4_xyxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xyxz_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->y = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xyxw(stdmath_radian4 v) { return {v.x,v.y,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xyxw_get(stdmath_radian4* p) { return stdmath_radian4_xyxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xyxw_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->y = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xyyx(stdmath_radian4 v) { return {v.x,v.y,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xyyx_get(stdmath_radian4* p) { return stdmath_radian4_xyyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xyyx_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->y = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xyyy(stdmath_radian4 v) { return {v.x,v.y,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xyyy_get(stdmath_radian4* p) { return stdmath_radian4_xyyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xyyy_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->y = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xyyz(stdmath_radian4 v) { return {v.x,v.y,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xyyz_get(stdmath_radian4* p) { return stdmath_radian4_xyyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xyyz_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->y = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xyyw(stdmath_radian4 v) { return {v.x,v.y,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xyyw_get(stdmath_radian4* p) { return stdmath_radian4_xyyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xyyw_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->y = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xyzx(stdmath_radian4 v) { return {v.x,v.y,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xyzx_get(stdmath_radian4* p) { return stdmath_radian4_xyzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xyzx_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->y = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xyzy(stdmath_radian4 v) { return {v.x,v.y,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xyzy_get(stdmath_radian4* p) { return stdmath_radian4_xyzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xyzy_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->y = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xyzz(stdmath_radian4 v) { return {v.x,v.y,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xyzz_get(stdmath_radian4* p) { return stdmath_radian4_xyzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xyzz_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->y = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xyzw(stdmath_radian4 v) { return {v.x,v.y,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xyzw_get(stdmath_radian4* p) { return stdmath_radian4_xyzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xyzw_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->y = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xywx(stdmath_radian4 v) { return {v.x,v.y,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xywx_get(stdmath_radian4* p) { return stdmath_radian4_xywx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xywx_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->y = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xywy(stdmath_radian4 v) { return {v.x,v.y,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xywy_get(stdmath_radian4* p) { return stdmath_radian4_xywy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xywy_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->y = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xywz(stdmath_radian4 v) { return {v.x,v.y,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xywz_get(stdmath_radian4* p) { return stdmath_radian4_xywz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xywz_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->y = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xyww(stdmath_radian4 v) { return {v.x,v.y,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xyww_get(stdmath_radian4* p) { return stdmath_radian4_xyww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xyww_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->y = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xzxx(stdmath_radian4 v) { return {v.x,v.z,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xzxx_get(stdmath_radian4* p) { return stdmath_radian4_xzxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xzxx_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->z = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xzxy(stdmath_radian4 v) { return {v.x,v.z,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xzxy_get(stdmath_radian4* p) { return stdmath_radian4_xzxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xzxy_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->z = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xzxz(stdmath_radian4 v) { return {v.x,v.z,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xzxz_get(stdmath_radian4* p) { return stdmath_radian4_xzxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xzxz_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->z = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xzxw(stdmath_radian4 v) { return {v.x,v.z,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xzxw_get(stdmath_radian4* p) { return stdmath_radian4_xzxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xzxw_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->z = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xzyx(stdmath_radian4 v) { return {v.x,v.z,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xzyx_get(stdmath_radian4* p) { return stdmath_radian4_xzyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xzyx_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->z = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xzyy(stdmath_radian4 v) { return {v.x,v.z,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xzyy_get(stdmath_radian4* p) { return stdmath_radian4_xzyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xzyy_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->z = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xzyz(stdmath_radian4 v) { return {v.x,v.z,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xzyz_get(stdmath_radian4* p) { return stdmath_radian4_xzyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xzyz_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->z = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xzyw(stdmath_radian4 v) { return {v.x,v.z,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xzyw_get(stdmath_radian4* p) { return stdmath_radian4_xzyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xzyw_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->z = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xzzx(stdmath_radian4 v) { return {v.x,v.z,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xzzx_get(stdmath_radian4* p) { return stdmath_radian4_xzzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xzzx_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->z = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xzzy(stdmath_radian4 v) { return {v.x,v.z,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xzzy_get(stdmath_radian4* p) { return stdmath_radian4_xzzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xzzy_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->z = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xzzz(stdmath_radian4 v) { return {v.x,v.z,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xzzz_get(stdmath_radian4* p) { return stdmath_radian4_xzzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xzzz_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->z = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xzzw(stdmath_radian4 v) { return {v.x,v.z,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xzzw_get(stdmath_radian4* p) { return stdmath_radian4_xzzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xzzw_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->z = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xzwx(stdmath_radian4 v) { return {v.x,v.z,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xzwx_get(stdmath_radian4* p) { return stdmath_radian4_xzwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xzwx_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->z = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xzwy(stdmath_radian4 v) { return {v.x,v.z,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xzwy_get(stdmath_radian4* p) { return stdmath_radian4_xzwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xzwy_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->z = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xzwz(stdmath_radian4 v) { return {v.x,v.z,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xzwz_get(stdmath_radian4* p) { return stdmath_radian4_xzwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xzwz_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->z = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xzww(stdmath_radian4 v) { return {v.x,v.z,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xzww_get(stdmath_radian4* p) { return stdmath_radian4_xzww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xzww_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->z = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xwxx(stdmath_radian4 v) { return {v.x,v.w,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xwxx_get(stdmath_radian4* p) { return stdmath_radian4_xwxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xwxx_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->w = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xwxy(stdmath_radian4 v) { return {v.x,v.w,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xwxy_get(stdmath_radian4* p) { return stdmath_radian4_xwxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xwxy_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->w = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xwxz(stdmath_radian4 v) { return {v.x,v.w,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xwxz_get(stdmath_radian4* p) { return stdmath_radian4_xwxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xwxz_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->w = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xwxw(stdmath_radian4 v) { return {v.x,v.w,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xwxw_get(stdmath_radian4* p) { return stdmath_radian4_xwxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xwxw_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->w = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xwyx(stdmath_radian4 v) { return {v.x,v.w,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xwyx_get(stdmath_radian4* p) { return stdmath_radian4_xwyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xwyx_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->w = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xwyy(stdmath_radian4 v) { return {v.x,v.w,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xwyy_get(stdmath_radian4* p) { return stdmath_radian4_xwyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xwyy_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->w = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xwyz(stdmath_radian4 v) { return {v.x,v.w,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xwyz_get(stdmath_radian4* p) { return stdmath_radian4_xwyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xwyz_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->w = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xwyw(stdmath_radian4 v) { return {v.x,v.w,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xwyw_get(stdmath_radian4* p) { return stdmath_radian4_xwyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xwyw_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->w = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xwzx(stdmath_radian4 v) { return {v.x,v.w,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xwzx_get(stdmath_radian4* p) { return stdmath_radian4_xwzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xwzx_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->w = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xwzy(stdmath_radian4 v) { return {v.x,v.w,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xwzy_get(stdmath_radian4* p) { return stdmath_radian4_xwzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xwzy_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->w = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xwzz(stdmath_radian4 v) { return {v.x,v.w,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xwzz_get(stdmath_radian4* p) { return stdmath_radian4_xwzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xwzz_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->w = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xwzw(stdmath_radian4 v) { return {v.x,v.w,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xwzw_get(stdmath_radian4* p) { return stdmath_radian4_xwzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xwzw_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->w = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xwwx(stdmath_radian4 v) { return {v.x,v.w,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xwwx_get(stdmath_radian4* p) { return stdmath_radian4_xwwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xwwx_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->w = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xwwy(stdmath_radian4 v) { return {v.x,v.w,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xwwy_get(stdmath_radian4* p) { return stdmath_radian4_xwwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xwwy_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->w = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xwwz(stdmath_radian4 v) { return {v.x,v.w,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xwwz_get(stdmath_radian4* p) { return stdmath_radian4_xwwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xwwz_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->w = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xwww(stdmath_radian4 v) { return {v.x,v.w,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xwww_get(stdmath_radian4* p) { return stdmath_radian4_xwww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_xwww_set(stdmath_radian4* p, stdmath_radian4 value) { p->x = value.x; p->w = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yxxx(stdmath_radian4 v) { return {v.y,v.x,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yxxx_get(stdmath_radian4* p) { return stdmath_radian4_yxxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yxxx_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->x = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yxxy(stdmath_radian4 v) { return {v.y,v.x,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yxxy_get(stdmath_radian4* p) { return stdmath_radian4_yxxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yxxy_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->x = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yxxz(stdmath_radian4 v) { return {v.y,v.x,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yxxz_get(stdmath_radian4* p) { return stdmath_radian4_yxxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yxxz_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->x = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yxxw(stdmath_radian4 v) { return {v.y,v.x,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yxxw_get(stdmath_radian4* p) { return stdmath_radian4_yxxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yxxw_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->x = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yxyx(stdmath_radian4 v) { return {v.y,v.x,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yxyx_get(stdmath_radian4* p) { return stdmath_radian4_yxyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yxyx_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->x = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yxyy(stdmath_radian4 v) { return {v.y,v.x,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yxyy_get(stdmath_radian4* p) { return stdmath_radian4_yxyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yxyy_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->x = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yxyz(stdmath_radian4 v) { return {v.y,v.x,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yxyz_get(stdmath_radian4* p) { return stdmath_radian4_yxyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yxyz_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->x = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yxyw(stdmath_radian4 v) { return {v.y,v.x,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yxyw_get(stdmath_radian4* p) { return stdmath_radian4_yxyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yxyw_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->x = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yxzx(stdmath_radian4 v) { return {v.y,v.x,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yxzx_get(stdmath_radian4* p) { return stdmath_radian4_yxzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yxzx_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->x = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yxzy(stdmath_radian4 v) { return {v.y,v.x,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yxzy_get(stdmath_radian4* p) { return stdmath_radian4_yxzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yxzy_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->x = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yxzz(stdmath_radian4 v) { return {v.y,v.x,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yxzz_get(stdmath_radian4* p) { return stdmath_radian4_yxzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yxzz_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->x = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yxzw(stdmath_radian4 v) { return {v.y,v.x,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yxzw_get(stdmath_radian4* p) { return stdmath_radian4_yxzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yxzw_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->x = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yxwx(stdmath_radian4 v) { return {v.y,v.x,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yxwx_get(stdmath_radian4* p) { return stdmath_radian4_yxwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yxwx_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->x = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yxwy(stdmath_radian4 v) { return {v.y,v.x,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yxwy_get(stdmath_radian4* p) { return stdmath_radian4_yxwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yxwy_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->x = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yxwz(stdmath_radian4 v) { return {v.y,v.x,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yxwz_get(stdmath_radian4* p) { return stdmath_radian4_yxwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yxwz_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->x = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yxww(stdmath_radian4 v) { return {v.y,v.x,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yxww_get(stdmath_radian4* p) { return stdmath_radian4_yxww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yxww_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->x = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yyxx(stdmath_radian4 v) { return {v.y,v.y,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yyxx_get(stdmath_radian4* p) { return stdmath_radian4_yyxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yyxx_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->y = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yyxy(stdmath_radian4 v) { return {v.y,v.y,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yyxy_get(stdmath_radian4* p) { return stdmath_radian4_yyxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yyxy_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->y = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yyxz(stdmath_radian4 v) { return {v.y,v.y,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yyxz_get(stdmath_radian4* p) { return stdmath_radian4_yyxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yyxz_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->y = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yyxw(stdmath_radian4 v) { return {v.y,v.y,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yyxw_get(stdmath_radian4* p) { return stdmath_radian4_yyxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yyxw_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->y = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yyyx(stdmath_radian4 v) { return {v.y,v.y,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yyyx_get(stdmath_radian4* p) { return stdmath_radian4_yyyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yyyx_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->y = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yyyy(stdmath_radian4 v) { return {v.y,v.y,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yyyy_get(stdmath_radian4* p) { return stdmath_radian4_yyyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yyyy_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->y = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yyyz(stdmath_radian4 v) { return {v.y,v.y,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yyyz_get(stdmath_radian4* p) { return stdmath_radian4_yyyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yyyz_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->y = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yyyw(stdmath_radian4 v) { return {v.y,v.y,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yyyw_get(stdmath_radian4* p) { return stdmath_radian4_yyyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yyyw_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->y = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yyzx(stdmath_radian4 v) { return {v.y,v.y,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yyzx_get(stdmath_radian4* p) { return stdmath_radian4_yyzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yyzx_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->y = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yyzy(stdmath_radian4 v) { return {v.y,v.y,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yyzy_get(stdmath_radian4* p) { return stdmath_radian4_yyzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yyzy_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->y = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yyzz(stdmath_radian4 v) { return {v.y,v.y,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yyzz_get(stdmath_radian4* p) { return stdmath_radian4_yyzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yyzz_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->y = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yyzw(stdmath_radian4 v) { return {v.y,v.y,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yyzw_get(stdmath_radian4* p) { return stdmath_radian4_yyzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yyzw_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->y = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yywx(stdmath_radian4 v) { return {v.y,v.y,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yywx_get(stdmath_radian4* p) { return stdmath_radian4_yywx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yywx_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->y = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yywy(stdmath_radian4 v) { return {v.y,v.y,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yywy_get(stdmath_radian4* p) { return stdmath_radian4_yywy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yywy_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->y = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yywz(stdmath_radian4 v) { return {v.y,v.y,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yywz_get(stdmath_radian4* p) { return stdmath_radian4_yywz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yywz_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->y = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yyww(stdmath_radian4 v) { return {v.y,v.y,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yyww_get(stdmath_radian4* p) { return stdmath_radian4_yyww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yyww_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->y = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yzxx(stdmath_radian4 v) { return {v.y,v.z,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yzxx_get(stdmath_radian4* p) { return stdmath_radian4_yzxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yzxx_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->z = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yzxy(stdmath_radian4 v) { return {v.y,v.z,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yzxy_get(stdmath_radian4* p) { return stdmath_radian4_yzxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yzxy_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->z = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yzxz(stdmath_radian4 v) { return {v.y,v.z,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yzxz_get(stdmath_radian4* p) { return stdmath_radian4_yzxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yzxz_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->z = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yzxw(stdmath_radian4 v) { return {v.y,v.z,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yzxw_get(stdmath_radian4* p) { return stdmath_radian4_yzxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yzxw_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->z = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yzyx(stdmath_radian4 v) { return {v.y,v.z,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yzyx_get(stdmath_radian4* p) { return stdmath_radian4_yzyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yzyx_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->z = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yzyy(stdmath_radian4 v) { return {v.y,v.z,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yzyy_get(stdmath_radian4* p) { return stdmath_radian4_yzyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yzyy_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->z = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yzyz(stdmath_radian4 v) { return {v.y,v.z,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yzyz_get(stdmath_radian4* p) { return stdmath_radian4_yzyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yzyz_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->z = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yzyw(stdmath_radian4 v) { return {v.y,v.z,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yzyw_get(stdmath_radian4* p) { return stdmath_radian4_yzyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yzyw_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->z = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yzzx(stdmath_radian4 v) { return {v.y,v.z,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yzzx_get(stdmath_radian4* p) { return stdmath_radian4_yzzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yzzx_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->z = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yzzy(stdmath_radian4 v) { return {v.y,v.z,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yzzy_get(stdmath_radian4* p) { return stdmath_radian4_yzzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yzzy_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->z = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yzzz(stdmath_radian4 v) { return {v.y,v.z,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yzzz_get(stdmath_radian4* p) { return stdmath_radian4_yzzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yzzz_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->z = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yzzw(stdmath_radian4 v) { return {v.y,v.z,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yzzw_get(stdmath_radian4* p) { return stdmath_radian4_yzzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yzzw_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->z = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yzwx(stdmath_radian4 v) { return {v.y,v.z,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yzwx_get(stdmath_radian4* p) { return stdmath_radian4_yzwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yzwx_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->z = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yzwy(stdmath_radian4 v) { return {v.y,v.z,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yzwy_get(stdmath_radian4* p) { return stdmath_radian4_yzwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yzwy_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->z = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yzwz(stdmath_radian4 v) { return {v.y,v.z,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yzwz_get(stdmath_radian4* p) { return stdmath_radian4_yzwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yzwz_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->z = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yzww(stdmath_radian4 v) { return {v.y,v.z,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yzww_get(stdmath_radian4* p) { return stdmath_radian4_yzww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_yzww_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->z = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_ywxx(stdmath_radian4 v) { return {v.y,v.w,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_ywxx_get(stdmath_radian4* p) { return stdmath_radian4_ywxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_ywxx_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->w = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_ywxy(stdmath_radian4 v) { return {v.y,v.w,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_ywxy_get(stdmath_radian4* p) { return stdmath_radian4_ywxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_ywxy_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->w = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_ywxz(stdmath_radian4 v) { return {v.y,v.w,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_ywxz_get(stdmath_radian4* p) { return stdmath_radian4_ywxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_ywxz_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->w = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_ywxw(stdmath_radian4 v) { return {v.y,v.w,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_ywxw_get(stdmath_radian4* p) { return stdmath_radian4_ywxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_ywxw_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->w = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_ywyx(stdmath_radian4 v) { return {v.y,v.w,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_ywyx_get(stdmath_radian4* p) { return stdmath_radian4_ywyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_ywyx_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->w = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_ywyy(stdmath_radian4 v) { return {v.y,v.w,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_ywyy_get(stdmath_radian4* p) { return stdmath_radian4_ywyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_ywyy_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->w = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_ywyz(stdmath_radian4 v) { return {v.y,v.w,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_ywyz_get(stdmath_radian4* p) { return stdmath_radian4_ywyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_ywyz_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->w = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_ywyw(stdmath_radian4 v) { return {v.y,v.w,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_ywyw_get(stdmath_radian4* p) { return stdmath_radian4_ywyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_ywyw_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->w = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_ywzx(stdmath_radian4 v) { return {v.y,v.w,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_ywzx_get(stdmath_radian4* p) { return stdmath_radian4_ywzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_ywzx_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->w = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_ywzy(stdmath_radian4 v) { return {v.y,v.w,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_ywzy_get(stdmath_radian4* p) { return stdmath_radian4_ywzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_ywzy_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->w = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_ywzz(stdmath_radian4 v) { return {v.y,v.w,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_ywzz_get(stdmath_radian4* p) { return stdmath_radian4_ywzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_ywzz_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->w = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_ywzw(stdmath_radian4 v) { return {v.y,v.w,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_ywzw_get(stdmath_radian4* p) { return stdmath_radian4_ywzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_ywzw_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->w = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_ywwx(stdmath_radian4 v) { return {v.y,v.w,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_ywwx_get(stdmath_radian4* p) { return stdmath_radian4_ywwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_ywwx_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->w = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_ywwy(stdmath_radian4 v) { return {v.y,v.w,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_ywwy_get(stdmath_radian4* p) { return stdmath_radian4_ywwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_ywwy_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->w = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_ywwz(stdmath_radian4 v) { return {v.y,v.w,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_ywwz_get(stdmath_radian4* p) { return stdmath_radian4_ywwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_ywwz_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->w = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_ywww(stdmath_radian4 v) { return {v.y,v.w,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_ywww_get(stdmath_radian4* p) { return stdmath_radian4_ywww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_ywww_set(stdmath_radian4* p, stdmath_radian4 value) { p->y = value.x; p->w = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zxxx(stdmath_radian4 v) { return {v.z,v.x,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zxxx_get(stdmath_radian4* p) { return stdmath_radian4_zxxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zxxx_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->x = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zxxy(stdmath_radian4 v) { return {v.z,v.x,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zxxy_get(stdmath_radian4* p) { return stdmath_radian4_zxxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zxxy_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->x = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zxxz(stdmath_radian4 v) { return {v.z,v.x,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zxxz_get(stdmath_radian4* p) { return stdmath_radian4_zxxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zxxz_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->x = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zxxw(stdmath_radian4 v) { return {v.z,v.x,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zxxw_get(stdmath_radian4* p) { return stdmath_radian4_zxxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zxxw_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->x = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zxyx(stdmath_radian4 v) { return {v.z,v.x,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zxyx_get(stdmath_radian4* p) { return stdmath_radian4_zxyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zxyx_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->x = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zxyy(stdmath_radian4 v) { return {v.z,v.x,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zxyy_get(stdmath_radian4* p) { return stdmath_radian4_zxyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zxyy_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->x = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zxyz(stdmath_radian4 v) { return {v.z,v.x,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zxyz_get(stdmath_radian4* p) { return stdmath_radian4_zxyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zxyz_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->x = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zxyw(stdmath_radian4 v) { return {v.z,v.x,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zxyw_get(stdmath_radian4* p) { return stdmath_radian4_zxyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zxyw_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->x = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zxzx(stdmath_radian4 v) { return {v.z,v.x,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zxzx_get(stdmath_radian4* p) { return stdmath_radian4_zxzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zxzx_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->x = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zxzy(stdmath_radian4 v) { return {v.z,v.x,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zxzy_get(stdmath_radian4* p) { return stdmath_radian4_zxzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zxzy_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->x = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zxzz(stdmath_radian4 v) { return {v.z,v.x,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zxzz_get(stdmath_radian4* p) { return stdmath_radian4_zxzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zxzz_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->x = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zxzw(stdmath_radian4 v) { return {v.z,v.x,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zxzw_get(stdmath_radian4* p) { return stdmath_radian4_zxzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zxzw_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->x = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zxwx(stdmath_radian4 v) { return {v.z,v.x,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zxwx_get(stdmath_radian4* p) { return stdmath_radian4_zxwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zxwx_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->x = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zxwy(stdmath_radian4 v) { return {v.z,v.x,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zxwy_get(stdmath_radian4* p) { return stdmath_radian4_zxwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zxwy_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->x = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zxwz(stdmath_radian4 v) { return {v.z,v.x,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zxwz_get(stdmath_radian4* p) { return stdmath_radian4_zxwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zxwz_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->x = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zxww(stdmath_radian4 v) { return {v.z,v.x,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zxww_get(stdmath_radian4* p) { return stdmath_radian4_zxww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zxww_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->x = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zyxx(stdmath_radian4 v) { return {v.z,v.y,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zyxx_get(stdmath_radian4* p) { return stdmath_radian4_zyxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zyxx_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->y = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zyxy(stdmath_radian4 v) { return {v.z,v.y,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zyxy_get(stdmath_radian4* p) { return stdmath_radian4_zyxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zyxy_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->y = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zyxz(stdmath_radian4 v) { return {v.z,v.y,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zyxz_get(stdmath_radian4* p) { return stdmath_radian4_zyxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zyxz_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->y = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zyxw(stdmath_radian4 v) { return {v.z,v.y,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zyxw_get(stdmath_radian4* p) { return stdmath_radian4_zyxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zyxw_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->y = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zyyx(stdmath_radian4 v) { return {v.z,v.y,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zyyx_get(stdmath_radian4* p) { return stdmath_radian4_zyyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zyyx_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->y = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zyyy(stdmath_radian4 v) { return {v.z,v.y,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zyyy_get(stdmath_radian4* p) { return stdmath_radian4_zyyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zyyy_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->y = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zyyz(stdmath_radian4 v) { return {v.z,v.y,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zyyz_get(stdmath_radian4* p) { return stdmath_radian4_zyyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zyyz_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->y = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zyyw(stdmath_radian4 v) { return {v.z,v.y,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zyyw_get(stdmath_radian4* p) { return stdmath_radian4_zyyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zyyw_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->y = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zyzx(stdmath_radian4 v) { return {v.z,v.y,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zyzx_get(stdmath_radian4* p) { return stdmath_radian4_zyzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zyzx_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->y = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zyzy(stdmath_radian4 v) { return {v.z,v.y,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zyzy_get(stdmath_radian4* p) { return stdmath_radian4_zyzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zyzy_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->y = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zyzz(stdmath_radian4 v) { return {v.z,v.y,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zyzz_get(stdmath_radian4* p) { return stdmath_radian4_zyzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zyzz_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->y = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zyzw(stdmath_radian4 v) { return {v.z,v.y,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zyzw_get(stdmath_radian4* p) { return stdmath_radian4_zyzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zyzw_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->y = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zywx(stdmath_radian4 v) { return {v.z,v.y,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zywx_get(stdmath_radian4* p) { return stdmath_radian4_zywx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zywx_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->y = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zywy(stdmath_radian4 v) { return {v.z,v.y,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zywy_get(stdmath_radian4* p) { return stdmath_radian4_zywy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zywy_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->y = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zywz(stdmath_radian4 v) { return {v.z,v.y,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zywz_get(stdmath_radian4* p) { return stdmath_radian4_zywz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zywz_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->y = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zyww(stdmath_radian4 v) { return {v.z,v.y,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zyww_get(stdmath_radian4* p) { return stdmath_radian4_zyww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zyww_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->y = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zzxx(stdmath_radian4 v) { return {v.z,v.z,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zzxx_get(stdmath_radian4* p) { return stdmath_radian4_zzxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zzxx_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->z = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zzxy(stdmath_radian4 v) { return {v.z,v.z,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zzxy_get(stdmath_radian4* p) { return stdmath_radian4_zzxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zzxy_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->z = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zzxz(stdmath_radian4 v) { return {v.z,v.z,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zzxz_get(stdmath_radian4* p) { return stdmath_radian4_zzxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zzxz_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->z = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zzxw(stdmath_radian4 v) { return {v.z,v.z,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zzxw_get(stdmath_radian4* p) { return stdmath_radian4_zzxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zzxw_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->z = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zzyx(stdmath_radian4 v) { return {v.z,v.z,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zzyx_get(stdmath_radian4* p) { return stdmath_radian4_zzyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zzyx_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->z = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zzyy(stdmath_radian4 v) { return {v.z,v.z,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zzyy_get(stdmath_radian4* p) { return stdmath_radian4_zzyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zzyy_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->z = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zzyz(stdmath_radian4 v) { return {v.z,v.z,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zzyz_get(stdmath_radian4* p) { return stdmath_radian4_zzyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zzyz_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->z = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zzyw(stdmath_radian4 v) { return {v.z,v.z,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zzyw_get(stdmath_radian4* p) { return stdmath_radian4_zzyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zzyw_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->z = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zzzx(stdmath_radian4 v) { return {v.z,v.z,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zzzx_get(stdmath_radian4* p) { return stdmath_radian4_zzzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zzzx_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->z = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zzzy(stdmath_radian4 v) { return {v.z,v.z,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zzzy_get(stdmath_radian4* p) { return stdmath_radian4_zzzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zzzy_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->z = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zzzz(stdmath_radian4 v) { return {v.z,v.z,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zzzz_get(stdmath_radian4* p) { return stdmath_radian4_zzzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zzzz_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->z = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zzzw(stdmath_radian4 v) { return {v.z,v.z,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zzzw_get(stdmath_radian4* p) { return stdmath_radian4_zzzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zzzw_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->z = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zzwx(stdmath_radian4 v) { return {v.z,v.z,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zzwx_get(stdmath_radian4* p) { return stdmath_radian4_zzwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zzwx_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->z = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zzwy(stdmath_radian4 v) { return {v.z,v.z,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zzwy_get(stdmath_radian4* p) { return stdmath_radian4_zzwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zzwy_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->z = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zzwz(stdmath_radian4 v) { return {v.z,v.z,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zzwz_get(stdmath_radian4* p) { return stdmath_radian4_zzwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zzwz_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->z = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zzww(stdmath_radian4 v) { return {v.z,v.z,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zzww_get(stdmath_radian4* p) { return stdmath_radian4_zzww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zzww_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->z = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zwxx(stdmath_radian4 v) { return {v.z,v.w,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zwxx_get(stdmath_radian4* p) { return stdmath_radian4_zwxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zwxx_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->w = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zwxy(stdmath_radian4 v) { return {v.z,v.w,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zwxy_get(stdmath_radian4* p) { return stdmath_radian4_zwxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zwxy_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->w = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zwxz(stdmath_radian4 v) { return {v.z,v.w,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zwxz_get(stdmath_radian4* p) { return stdmath_radian4_zwxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zwxz_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->w = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zwxw(stdmath_radian4 v) { return {v.z,v.w,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zwxw_get(stdmath_radian4* p) { return stdmath_radian4_zwxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zwxw_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->w = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zwyx(stdmath_radian4 v) { return {v.z,v.w,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zwyx_get(stdmath_radian4* p) { return stdmath_radian4_zwyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zwyx_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->w = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zwyy(stdmath_radian4 v) { return {v.z,v.w,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zwyy_get(stdmath_radian4* p) { return stdmath_radian4_zwyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zwyy_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->w = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zwyz(stdmath_radian4 v) { return {v.z,v.w,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zwyz_get(stdmath_radian4* p) { return stdmath_radian4_zwyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zwyz_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->w = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zwyw(stdmath_radian4 v) { return {v.z,v.w,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zwyw_get(stdmath_radian4* p) { return stdmath_radian4_zwyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zwyw_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->w = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zwzx(stdmath_radian4 v) { return {v.z,v.w,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zwzx_get(stdmath_radian4* p) { return stdmath_radian4_zwzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zwzx_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->w = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zwzy(stdmath_radian4 v) { return {v.z,v.w,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zwzy_get(stdmath_radian4* p) { return stdmath_radian4_zwzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zwzy_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->w = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zwzz(stdmath_radian4 v) { return {v.z,v.w,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zwzz_get(stdmath_radian4* p) { return stdmath_radian4_zwzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zwzz_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->w = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zwzw(stdmath_radian4 v) { return {v.z,v.w,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zwzw_get(stdmath_radian4* p) { return stdmath_radian4_zwzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zwzw_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->w = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zwwx(stdmath_radian4 v) { return {v.z,v.w,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zwwx_get(stdmath_radian4* p) { return stdmath_radian4_zwwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zwwx_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->w = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zwwy(stdmath_radian4 v) { return {v.z,v.w,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zwwy_get(stdmath_radian4* p) { return stdmath_radian4_zwwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zwwy_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->w = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zwwz(stdmath_radian4 v) { return {v.z,v.w,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zwwz_get(stdmath_radian4* p) { return stdmath_radian4_zwwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zwwz_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->w = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zwww(stdmath_radian4 v) { return {v.z,v.w,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zwww_get(stdmath_radian4* p) { return stdmath_radian4_zwww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_zwww_set(stdmath_radian4* p, stdmath_radian4 value) { p->z = value.x; p->w = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wxxx(stdmath_radian4 v) { return {v.w,v.x,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wxxx_get(stdmath_radian4* p) { return stdmath_radian4_wxxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wxxx_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->x = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wxxy(stdmath_radian4 v) { return {v.w,v.x,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wxxy_get(stdmath_radian4* p) { return stdmath_radian4_wxxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wxxy_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->x = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wxxz(stdmath_radian4 v) { return {v.w,v.x,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wxxz_get(stdmath_radian4* p) { return stdmath_radian4_wxxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wxxz_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->x = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wxxw(stdmath_radian4 v) { return {v.w,v.x,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wxxw_get(stdmath_radian4* p) { return stdmath_radian4_wxxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wxxw_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->x = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wxyx(stdmath_radian4 v) { return {v.w,v.x,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wxyx_get(stdmath_radian4* p) { return stdmath_radian4_wxyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wxyx_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->x = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wxyy(stdmath_radian4 v) { return {v.w,v.x,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wxyy_get(stdmath_radian4* p) { return stdmath_radian4_wxyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wxyy_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->x = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wxyz(stdmath_radian4 v) { return {v.w,v.x,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wxyz_get(stdmath_radian4* p) { return stdmath_radian4_wxyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wxyz_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->x = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wxyw(stdmath_radian4 v) { return {v.w,v.x,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wxyw_get(stdmath_radian4* p) { return stdmath_radian4_wxyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wxyw_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->x = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wxzx(stdmath_radian4 v) { return {v.w,v.x,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wxzx_get(stdmath_radian4* p) { return stdmath_radian4_wxzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wxzx_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->x = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wxzy(stdmath_radian4 v) { return {v.w,v.x,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wxzy_get(stdmath_radian4* p) { return stdmath_radian4_wxzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wxzy_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->x = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wxzz(stdmath_radian4 v) { return {v.w,v.x,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wxzz_get(stdmath_radian4* p) { return stdmath_radian4_wxzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wxzz_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->x = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wxzw(stdmath_radian4 v) { return {v.w,v.x,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wxzw_get(stdmath_radian4* p) { return stdmath_radian4_wxzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wxzw_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->x = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wxwx(stdmath_radian4 v) { return {v.w,v.x,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wxwx_get(stdmath_radian4* p) { return stdmath_radian4_wxwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wxwx_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->x = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wxwy(stdmath_radian4 v) { return {v.w,v.x,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wxwy_get(stdmath_radian4* p) { return stdmath_radian4_wxwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wxwy_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->x = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wxwz(stdmath_radian4 v) { return {v.w,v.x,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wxwz_get(stdmath_radian4* p) { return stdmath_radian4_wxwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wxwz_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->x = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wxww(stdmath_radian4 v) { return {v.w,v.x,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wxww_get(stdmath_radian4* p) { return stdmath_radian4_wxww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wxww_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->x = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wyxx(stdmath_radian4 v) { return {v.w,v.y,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wyxx_get(stdmath_radian4* p) { return stdmath_radian4_wyxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wyxx_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->y = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wyxy(stdmath_radian4 v) { return {v.w,v.y,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wyxy_get(stdmath_radian4* p) { return stdmath_radian4_wyxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wyxy_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->y = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wyxz(stdmath_radian4 v) { return {v.w,v.y,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wyxz_get(stdmath_radian4* p) { return stdmath_radian4_wyxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wyxz_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->y = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wyxw(stdmath_radian4 v) { return {v.w,v.y,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wyxw_get(stdmath_radian4* p) { return stdmath_radian4_wyxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wyxw_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->y = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wyyx(stdmath_radian4 v) { return {v.w,v.y,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wyyx_get(stdmath_radian4* p) { return stdmath_radian4_wyyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wyyx_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->y = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wyyy(stdmath_radian4 v) { return {v.w,v.y,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wyyy_get(stdmath_radian4* p) { return stdmath_radian4_wyyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wyyy_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->y = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wyyz(stdmath_radian4 v) { return {v.w,v.y,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wyyz_get(stdmath_radian4* p) { return stdmath_radian4_wyyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wyyz_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->y = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wyyw(stdmath_radian4 v) { return {v.w,v.y,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wyyw_get(stdmath_radian4* p) { return stdmath_radian4_wyyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wyyw_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->y = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wyzx(stdmath_radian4 v) { return {v.w,v.y,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wyzx_get(stdmath_radian4* p) { return stdmath_radian4_wyzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wyzx_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->y = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wyzy(stdmath_radian4 v) { return {v.w,v.y,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wyzy_get(stdmath_radian4* p) { return stdmath_radian4_wyzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wyzy_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->y = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wyzz(stdmath_radian4 v) { return {v.w,v.y,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wyzz_get(stdmath_radian4* p) { return stdmath_radian4_wyzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wyzz_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->y = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wyzw(stdmath_radian4 v) { return {v.w,v.y,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wyzw_get(stdmath_radian4* p) { return stdmath_radian4_wyzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wyzw_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->y = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wywx(stdmath_radian4 v) { return {v.w,v.y,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wywx_get(stdmath_radian4* p) { return stdmath_radian4_wywx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wywx_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->y = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wywy(stdmath_radian4 v) { return {v.w,v.y,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wywy_get(stdmath_radian4* p) { return stdmath_radian4_wywy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wywy_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->y = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wywz(stdmath_radian4 v) { return {v.w,v.y,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wywz_get(stdmath_radian4* p) { return stdmath_radian4_wywz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wywz_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->y = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wyww(stdmath_radian4 v) { return {v.w,v.y,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wyww_get(stdmath_radian4* p) { return stdmath_radian4_wyww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wyww_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->y = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wzxx(stdmath_radian4 v) { return {v.w,v.z,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wzxx_get(stdmath_radian4* p) { return stdmath_radian4_wzxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wzxx_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->z = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wzxy(stdmath_radian4 v) { return {v.w,v.z,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wzxy_get(stdmath_radian4* p) { return stdmath_radian4_wzxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wzxy_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->z = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wzxz(stdmath_radian4 v) { return {v.w,v.z,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wzxz_get(stdmath_radian4* p) { return stdmath_radian4_wzxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wzxz_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->z = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wzxw(stdmath_radian4 v) { return {v.w,v.z,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wzxw_get(stdmath_radian4* p) { return stdmath_radian4_wzxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wzxw_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->z = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wzyx(stdmath_radian4 v) { return {v.w,v.z,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wzyx_get(stdmath_radian4* p) { return stdmath_radian4_wzyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wzyx_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->z = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wzyy(stdmath_radian4 v) { return {v.w,v.z,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wzyy_get(stdmath_radian4* p) { return stdmath_radian4_wzyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wzyy_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->z = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wzyz(stdmath_radian4 v) { return {v.w,v.z,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wzyz_get(stdmath_radian4* p) { return stdmath_radian4_wzyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wzyz_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->z = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wzyw(stdmath_radian4 v) { return {v.w,v.z,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wzyw_get(stdmath_radian4* p) { return stdmath_radian4_wzyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wzyw_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->z = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wzzx(stdmath_radian4 v) { return {v.w,v.z,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wzzx_get(stdmath_radian4* p) { return stdmath_radian4_wzzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wzzx_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->z = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wzzy(stdmath_radian4 v) { return {v.w,v.z,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wzzy_get(stdmath_radian4* p) { return stdmath_radian4_wzzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wzzy_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->z = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wzzz(stdmath_radian4 v) { return {v.w,v.z,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wzzz_get(stdmath_radian4* p) { return stdmath_radian4_wzzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wzzz_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->z = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wzzw(stdmath_radian4 v) { return {v.w,v.z,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wzzw_get(stdmath_radian4* p) { return stdmath_radian4_wzzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wzzw_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->z = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wzwx(stdmath_radian4 v) { return {v.w,v.z,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wzwx_get(stdmath_radian4* p) { return stdmath_radian4_wzwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wzwx_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->z = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wzwy(stdmath_radian4 v) { return {v.w,v.z,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wzwy_get(stdmath_radian4* p) { return stdmath_radian4_wzwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wzwy_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->z = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wzwz(stdmath_radian4 v) { return {v.w,v.z,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wzwz_get(stdmath_radian4* p) { return stdmath_radian4_wzwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wzwz_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->z = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wzww(stdmath_radian4 v) { return {v.w,v.z,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wzww_get(stdmath_radian4* p) { return stdmath_radian4_wzww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wzww_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->z = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wwxx(stdmath_radian4 v) { return {v.w,v.w,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wwxx_get(stdmath_radian4* p) { return stdmath_radian4_wwxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wwxx_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->w = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wwxy(stdmath_radian4 v) { return {v.w,v.w,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wwxy_get(stdmath_radian4* p) { return stdmath_radian4_wwxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wwxy_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->w = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wwxz(stdmath_radian4 v) { return {v.w,v.w,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wwxz_get(stdmath_radian4* p) { return stdmath_radian4_wwxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wwxz_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->w = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wwxw(stdmath_radian4 v) { return {v.w,v.w,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wwxw_get(stdmath_radian4* p) { return stdmath_radian4_wwxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wwxw_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->w = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wwyx(stdmath_radian4 v) { return {v.w,v.w,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wwyx_get(stdmath_radian4* p) { return stdmath_radian4_wwyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wwyx_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->w = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wwyy(stdmath_radian4 v) { return {v.w,v.w,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wwyy_get(stdmath_radian4* p) { return stdmath_radian4_wwyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wwyy_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->w = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wwyz(stdmath_radian4 v) { return {v.w,v.w,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wwyz_get(stdmath_radian4* p) { return stdmath_radian4_wwyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wwyz_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->w = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wwyw(stdmath_radian4 v) { return {v.w,v.w,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wwyw_get(stdmath_radian4* p) { return stdmath_radian4_wwyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wwyw_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->w = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wwzx(stdmath_radian4 v) { return {v.w,v.w,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wwzx_get(stdmath_radian4* p) { return stdmath_radian4_wwzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wwzx_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->w = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wwzy(stdmath_radian4 v) { return {v.w,v.w,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wwzy_get(stdmath_radian4* p) { return stdmath_radian4_wwzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wwzy_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->w = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wwzz(stdmath_radian4 v) { return {v.w,v.w,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wwzz_get(stdmath_radian4* p) { return stdmath_radian4_wwzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wwzz_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->w = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wwzw(stdmath_radian4 v) { return {v.w,v.w,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wwzw_get(stdmath_radian4* p) { return stdmath_radian4_wwzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wwzw_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->w = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wwwx(stdmath_radian4 v) { return {v.w,v.w,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wwwx_get(stdmath_radian4* p) { return stdmath_radian4_wwwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wwwx_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->w = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wwwy(stdmath_radian4 v) { return {v.w,v.w,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wwwy_get(stdmath_radian4* p) { return stdmath_radian4_wwwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wwwy_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->w = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wwwz(stdmath_radian4 v) { return {v.w,v.w,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wwwz_get(stdmath_radian4* p) { return stdmath_radian4_wwwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wwwz_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->w = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wwww(stdmath_radian4 v) { return {v.w,v.w,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wwww_get(stdmath_radian4* p) { return stdmath_radian4_wwww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian4 stdmath_radian4_wwww_set(stdmath_radian4* p, stdmath_radian4 value) { p->w = value.x; p->w = value.y; p->w = value.z; p->w = value.w; return *p; }

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

inline stdmath::radian4 c(stdmath_radian4 c) {
	return (stdmath::radian4&)c;
}
inline stdmath_radian4 c(stdmath::radian4 c) {
	return (stdmath_radian4&)c;
}

#ifdef __cplusplus
extern "C" {
#endif

stdmath_radian4 stdmath_radian4_broadcast(stdmath_radian all) {
	return c(stdmath::radian4((stdmath::radian4::underlying_type&)all));
}

stdmath_radian4 stdmath_radian4_add(stdmath_radian4 a, stdmath_radian4 b) {
	return c(c(a) + c(b));
}
stdmath_radian4 stdmath_radian4_subtract(stdmath_radian4 a, stdmath_radian4 b) {
	return c(c(a) - c(b));
}
stdmath_radian4 stdmath_radian4_negate(stdmath_radian4 v) {
#if !true && !false
	return c(stdmath::radian4(-(stdmath::vector<stdmath_radian, 4>)c(v)));
#else
	assert(false && "TODO: Why can't we use - on vector<degree/radian, N>?");
#endif
}
stdmath_radian4 stdmath_radian4_multiply(stdmath_radian4 a, stdmath_radian4 b) {
	return c(c(a) * c(b));
}
stdmath_radian4 stdmath_radian4_divide(stdmath_radian4 a, stdmath_radian4 b) {
	return c(c(a) / c(b));
}
stdmath_radian4 stdmath_radian4_scale(stdmath_radian4 v, stdmath_radian s) {
	return c(c(v) * (stdmath::radian4::underlying_type&)s);
}

#if false
stdmath_radian4 stdmath_radian4_modulus(stdmath_radian4 a, stdmath_radian4 b) {
	return c(c(a) % c(b));
}
stdmath_radian4 stdmath_radian4_logical_not(stdmath_radian4 v) {
	return c(!c(v));
}
stdmath_radian4 stdmath_radian4_bitwise_not(stdmath_radian4 v) {
	return c(~c(v));
}
stdmath_radian4 stdmath_radian4_logical_and(stdmath_radian4 a, stdmath_radian4 b) {
	return c(c(a) && c(b));
}
stdmath_radian4 stdmath_radian4_bitwise_and(stdmath_radian4 a, stdmath_radian4 b) {
	return c(c(a) & c(b));
}
stdmath_radian4 stdmath_radian4_logical_or(stdmath_radian4 a, stdmath_radian4 b) {
	return c(c(a) || c(b));
}
stdmath_radian4 stdmath_radian4_bitwise_or(stdmath_radian4 a, stdmath_radian4 b) {
	return c(c(a) | c(b));
}
stdmath_radian4 stdmath_radian4_bitwise_xor(stdmath_radian4 a, stdmath_radian4 b) {
	return c(c(a) ^ c(b));
}
stdmath_radian4 stdmath_radian4_shift_left(stdmath_radian4 a, stdmath_radian4 b) {
	return c(c(a) << c(b));
}
stdmath_radian4 stdmath_radian4_shift_right(stdmath_radian4 a, stdmath_radian4 b) {
	return c(c(a) >> c(b));
}
#endif

stdmath_bool4 stdmath_radian4_equal_to(stdmath_radian4 a, stdmath_radian4 b) {
	return c(c(a) == c(b));
}
stdmath_bool4 stdmath_radian4_not_equal_to(stdmath_radian4 a, stdmath_radian4 b) {
	return c(c(a) != c(b));
}
stdmath_bool4 stdmath_radian4_less_than(stdmath_radian4 a, stdmath_radian4 b) {
	return c(c(a) < c(b));
}
stdmath_bool4 stdmath_radian4_less_than_or_equal_to(stdmath_radian4 a, stdmath_radian4 b) {
	return c(c(a) <= c(b));
}
stdmath_bool4 stdmath_radian4_greater_than(stdmath_radian4 a, stdmath_radian4 b) {
	return c(c(a) > c(b));
}
stdmath_bool4 stdmath_radian4_greater_than_or_equal_to(stdmath_radian4 a, stdmath_radian4 b) {
	return c(c(a) >= c(b));
}

stdmath_radian stdmath_radian4_length_squared(stdmath_radian4 v)  {
	auto out = c(v).length_squared();
	return (stdmath_radian&)out;
}
stdmath_radian stdmath_radian4_length(stdmath_radian4 v)  {
	auto out = c(v).length();
	return (stdmath_radian&)out;
}
stdmath_radian stdmath_radian4_dot(stdmath_radian4 a, stdmath_radian4 b)  {
	auto out = dot(c(a), c(b));
	return (stdmath_radian&)out;
}
stdmath_radian stdmath_radian4_min_element(stdmath_radian4 v)  {
	auto out = c(v).min_element();
	return (stdmath_radian&)out;
}
stdmath_radian stdmath_radian4_max_element(stdmath_radian4 v)  {
	auto out = c(v).max_element();
	return (stdmath_radian&)out;
}

// stdmath_radian4 stdmath_radian4_elementwise_transform(stdmath_radian4 v, stdmath_radian(*func)(stdmath_radian)) {
// 	return c(c(v).elementwise_transform(func));
// }
// stdmath_radian stdmath_radian4_reduce_elements(stdmath_radian4 v, stdmath_radian initial_value, stdmath_radian(*reducer)(stdmath_radian4, stdmath_radian4)) {
// 	return c(v).reduce_elements(initial_value, reducer);
// }

#if 4 == 3
stdmath_radian4 stdmath_radian4_cross(stdmath_radian4 a, stdmath_radian4 b) {
	return c(cross(c(a), c(b)));
}
#endif

stdmath_radian4 stdmath_radian4_min(stdmath_radian4 a, stdmath_radian4 b) {
	return c(min(c(a), c(b)));
}
stdmath_radian4 stdmath_radian4_max(stdmath_radian4 a, stdmath_radian4 b) {
	return c(max(c(a), c(b)));
}
stdmath_radian4 stdmath_radian4_normalize(stdmath_radian4 v) {
	return c(normalize(c(v)));
}
stdmath_radian4 stdmath_radian4_lerp(stdmath_radian4 a, stdmath_radian4 b, float t) {
	return c(lerp(c(a), c(b), t));
}
stdmath_radian4 stdmath_radian4_clamp(stdmath_radian4 a, stdmath_radian4 min, stdmath_radian4 max) {
	return c(clamp(c(a), c(min), c(max)));
}
stdmath_radian4 stdmath_radian4_reflect(stdmath_radian4 a, stdmath_radian4 b) {
	return c(reflect(c(a), c(b)));
}
stdmath_bool4 stdmath_radian4_approximately_equal(stdmath_radian4 a, stdmath_radian4 b) {
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

#endif // __STDMATH_stdmath_radian4_H__