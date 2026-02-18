#ifndef __STDMATH_int32_t4_H__
#define __STDMATH_int32_t4_H__

#ifndef STDMATH_MODULE
#include <stdint.h>
#include <assert.h>
#endif
#include "../maybe_export.h"

#if false
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
#include "int1.h"
#elif 4 == 3
#include "int2.h"
#include "int1.h"
#elif 4 == 4
#include "int3.h"
#include "int2.h"
#include "int1.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if 4 == 1
STDMATH_EXPORT union stdmath_int1 {
	struct {
		int32_t x;
	};
	int32_t data[1];
};
#elif 4 == 2
STDMATH_EXPORT union stdmath_int2 {
	struct {
		int32_t x, y;
	};
	struct {
		int32_t u, v;
	};
	int32_t data[2];
};
#elif 4 == 3
STDMATH_EXPORT union stdmath_int3 {
	struct {
		int32_t x, y, z;
	};
	struct {
		int32_t r, g, b;
	};
	struct {
		int32_t h, s, v;
	};
	int32_t data[4]; // int3s are aligned as if they were int4s
};
#elif 4 == 4
STDMATH_EXPORT union stdmath_int4 {
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
#endif

STDMATH_EXPORT stdmath_int4 stdmath_int4_broadcast(int32_t all);

STDMATH_EXPORT stdmath_int4 stdmath_int4_add(stdmath_int4 a, stdmath_int4 b);
STDMATH_EXPORT stdmath_int4 stdmath_int4_subtract(stdmath_int4 a, stdmath_int4 b);
STDMATH_EXPORT stdmath_int4 stdmath_int4_negate(stdmath_int4 v);
STDMATH_EXPORT stdmath_int4 stdmath_int4_multiply(stdmath_int4 a, stdmath_int4 b);
STDMATH_EXPORT stdmath_int4 stdmath_int4_divide(stdmath_int4 a, stdmath_int4 b);
STDMATH_EXPORT stdmath_int4 stdmath_int4_scale(stdmath_int4 v, int32_t s);

#if false
STDMATH_EXPORT stdmath_int4 stdmath_int4_modulus(stdmath_int4 a, stdmath_int4 b);
STDMATH_EXPORT stdmath_int4 stdmath_int4_logical_not(stdmath_int4 v);
STDMATH_EXPORT stdmath_int4 stdmath_int4_bitwise_not(stdmath_int4 v);
STDMATH_EXPORT stdmath_int4 stdmath_int4_logical_and(stdmath_int4 a, stdmath_int4 b);
STDMATH_EXPORT stdmath_int4 stdmath_int4_bitwise_and(stdmath_int4 a, stdmath_int4 b);
STDMATH_EXPORT stdmath_int4 stdmath_int4_logical_or(stdmath_int4 a, stdmath_int4 b);
STDMATH_EXPORT stdmath_int4 stdmath_int4_bitwise_or(stdmath_int4 a, stdmath_int4 b);
STDMATH_EXPORT stdmath_int4 stdmath_int4_bitwise_xor(stdmath_int4 a, stdmath_int4 b);
STDMATH_EXPORT stdmath_int4 stdmath_int4_shift_left(stdmath_int4 a, stdmath_int4 b);
STDMATH_EXPORT stdmath_int4 stdmath_int4_shift_right(stdmath_int4 a, stdmath_int4 b);
#endif

STDMATH_EXPORT stdmath_bool4 stdmath_int4_equal_to(stdmath_int4 a, stdmath_int4 b);
STDMATH_EXPORT stdmath_bool4 stdmath_int4_not_equal_to(stdmath_int4 a, stdmath_int4 b);
STDMATH_EXPORT stdmath_bool4 stdmath_int4_less_than(stdmath_int4 a, stdmath_int4 b);
STDMATH_EXPORT stdmath_bool4 stdmath_int4_less_than_or_equal_to(stdmath_int4 a, stdmath_int4 b);
STDMATH_EXPORT stdmath_bool4 stdmath_int4_greater_than(stdmath_int4 a, stdmath_int4 b);
STDMATH_EXPORT stdmath_bool4 stdmath_int4_greater_than_or_equal_to(stdmath_int4 a, stdmath_int4 b);

STDMATH_EXPORT int32_t stdmath_int4_length_squared(stdmath_int4 v);
STDMATH_EXPORT int32_t stdmath_int4_length(stdmath_int4 v);
STDMATH_EXPORT int32_t stdmath_int4_dot(stdmath_int4 a, stdmath_int4 b);
STDMATH_EXPORT int32_t stdmath_int4_min_element(stdmath_int4 v);
STDMATH_EXPORT int32_t stdmath_int4_max_element(stdmath_int4 v);

// STDMATH_EXPORT stdmath_int4 stdmath_int4_elementwise_transform(stdmath_int4 v, int32_t(*func)(int32_t));
// STDMATH_EXPORT int32_t stdmath_int4_reduce_elements(stdmath_int4 v, int32_t initial_value, int32_t(*reducer)(stdmath_int4, stdmath_int4));

#if 4 == 3
STDMATH_EXPORT stdmath_int3 stdmath_int3_cross(stdmath_int3 a, stdmath_int3 b);
#endif

STDMATH_EXPORT stdmath_int4 stdmath_int4_min(stdmath_int4 a, stdmath_int4 b);
STDMATH_EXPORT stdmath_int4 stdmath_int4_max(stdmath_int4 a, stdmath_int4 b);
STDMATH_EXPORT stdmath_int4 stdmath_int4_normalize(stdmath_int4 v);
STDMATH_EXPORT stdmath_int4 stdmath_int4_lerp(stdmath_int4 a, stdmath_int4 b, float t);
STDMATH_EXPORT stdmath_int4 stdmath_int4_clamp(stdmath_int4 a, stdmath_int4 min, stdmath_int4 max);
STDMATH_EXPORT stdmath_int4 stdmath_int4_reflect(stdmath_int4 a, stdmath_int4 b);
STDMATH_EXPORT stdmath_bool4 stdmath_int4_approximately_equal(stdmath_int4 a, stdmath_int4 b);

#if false
STDMATH_EXPORT bool stdmath_bool4_all_of(stdmath_bool4 v);
STDMATH_EXPORT bool stdmath_bool4_any_of(stdmath_bool4 v);
STDMATH_EXPORT bool stdmath_bool4_none_of(stdmath_bool4 v);
STDMATH_EXPORT bool stdmath_bool4_some_of(stdmath_bool4 v);
#endif

#ifndef STDMATH_NO_SWIZZLES
STDMATH_EXPORT STDMATH_INLINE stdmath_int1 stdmath_int4_x(stdmath_int4 v) { return {v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int1 stdmath_int4_x_get(stdmath_int4* p) { return stdmath_int4_x(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_x_set(stdmath_int4* p, stdmath_int1 value) { p->x = value.x; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int1 stdmath_int4_y(stdmath_int4 v) { return {v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int1 stdmath_int4_y_get(stdmath_int4* p) { return stdmath_int4_y(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_y_set(stdmath_int4* p, stdmath_int1 value) { p->y = value.x; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int1 stdmath_int4_z(stdmath_int4 v) { return {v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int1 stdmath_int4_z_get(stdmath_int4* p) { return stdmath_int4_z(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_z_set(stdmath_int4* p, stdmath_int1 value) { p->z = value.x; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int1 stdmath_int4_w(stdmath_int4 v) { return {v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int1 stdmath_int4_w_get(stdmath_int4* p) { return stdmath_int4_w(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_w_set(stdmath_int4* p, stdmath_int1 value) { p->w = value.x; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int4_xx(stdmath_int4 v) { return {v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int4_xx_get(stdmath_int4* p) { return stdmath_int4_xx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xx_set(stdmath_int4* p, stdmath_int2 value) { p->x = value.x; p->x = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int4_xy(stdmath_int4 v) { return {v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int4_xy_get(stdmath_int4* p) { return stdmath_int4_xy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xy_set(stdmath_int4* p, stdmath_int2 value) { p->x = value.x; p->y = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int4_xz(stdmath_int4 v) { return {v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int4_xz_get(stdmath_int4* p) { return stdmath_int4_xz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xz_set(stdmath_int4* p, stdmath_int2 value) { p->x = value.x; p->z = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int4_xw(stdmath_int4 v) { return {v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int4_xw_get(stdmath_int4* p) { return stdmath_int4_xw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xw_set(stdmath_int4* p, stdmath_int2 value) { p->x = value.x; p->w = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int4_yx(stdmath_int4 v) { return {v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int4_yx_get(stdmath_int4* p) { return stdmath_int4_yx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yx_set(stdmath_int4* p, stdmath_int2 value) { p->y = value.x; p->x = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int4_yy(stdmath_int4 v) { return {v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int4_yy_get(stdmath_int4* p) { return stdmath_int4_yy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yy_set(stdmath_int4* p, stdmath_int2 value) { p->y = value.x; p->y = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int4_yz(stdmath_int4 v) { return {v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int4_yz_get(stdmath_int4* p) { return stdmath_int4_yz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yz_set(stdmath_int4* p, stdmath_int2 value) { p->y = value.x; p->z = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int4_yw(stdmath_int4 v) { return {v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int4_yw_get(stdmath_int4* p) { return stdmath_int4_yw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yw_set(stdmath_int4* p, stdmath_int2 value) { p->y = value.x; p->w = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int4_zx(stdmath_int4 v) { return {v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int4_zx_get(stdmath_int4* p) { return stdmath_int4_zx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zx_set(stdmath_int4* p, stdmath_int2 value) { p->z = value.x; p->x = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int4_zy(stdmath_int4 v) { return {v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int4_zy_get(stdmath_int4* p) { return stdmath_int4_zy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zy_set(stdmath_int4* p, stdmath_int2 value) { p->z = value.x; p->y = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int4_zz(stdmath_int4 v) { return {v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int4_zz_get(stdmath_int4* p) { return stdmath_int4_zz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zz_set(stdmath_int4* p, stdmath_int2 value) { p->z = value.x; p->z = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int4_zw(stdmath_int4 v) { return {v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int4_zw_get(stdmath_int4* p) { return stdmath_int4_zw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zw_set(stdmath_int4* p, stdmath_int2 value) { p->z = value.x; p->w = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int4_wx(stdmath_int4 v) { return {v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int4_wx_get(stdmath_int4* p) { return stdmath_int4_wx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wx_set(stdmath_int4* p, stdmath_int2 value) { p->w = value.x; p->x = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int4_wy(stdmath_int4 v) { return {v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int4_wy_get(stdmath_int4* p) { return stdmath_int4_wy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wy_set(stdmath_int4* p, stdmath_int2 value) { p->w = value.x; p->y = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int4_wz(stdmath_int4 v) { return {v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int4_wz_get(stdmath_int4* p) { return stdmath_int4_wz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wz_set(stdmath_int4* p, stdmath_int2 value) { p->w = value.x; p->z = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int4_ww(stdmath_int4 v) { return {v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int4_ww_get(stdmath_int4* p) { return stdmath_int4_ww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_ww_set(stdmath_int4* p, stdmath_int2 value) { p->w = value.x; p->w = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_xxx(stdmath_int4 v) { return {v.x,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_xxx_get(stdmath_int4* p) { return stdmath_int4_xxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xxx_set(stdmath_int4* p, stdmath_int3 value) { p->x = value.x; p->x = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_xxy(stdmath_int4 v) { return {v.x,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_xxy_get(stdmath_int4* p) { return stdmath_int4_xxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xxy_set(stdmath_int4* p, stdmath_int3 value) { p->x = value.x; p->x = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_xxz(stdmath_int4 v) { return {v.x,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_xxz_get(stdmath_int4* p) { return stdmath_int4_xxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xxz_set(stdmath_int4* p, stdmath_int3 value) { p->x = value.x; p->x = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_xxw(stdmath_int4 v) { return {v.x,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_xxw_get(stdmath_int4* p) { return stdmath_int4_xxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xxw_set(stdmath_int4* p, stdmath_int3 value) { p->x = value.x; p->x = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_xyx(stdmath_int4 v) { return {v.x,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_xyx_get(stdmath_int4* p) { return stdmath_int4_xyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xyx_set(stdmath_int4* p, stdmath_int3 value) { p->x = value.x; p->y = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_xyy(stdmath_int4 v) { return {v.x,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_xyy_get(stdmath_int4* p) { return stdmath_int4_xyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xyy_set(stdmath_int4* p, stdmath_int3 value) { p->x = value.x; p->y = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_xyz(stdmath_int4 v) { return {v.x,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_xyz_get(stdmath_int4* p) { return stdmath_int4_xyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xyz_set(stdmath_int4* p, stdmath_int3 value) { p->x = value.x; p->y = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_xyw(stdmath_int4 v) { return {v.x,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_xyw_get(stdmath_int4* p) { return stdmath_int4_xyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xyw_set(stdmath_int4* p, stdmath_int3 value) { p->x = value.x; p->y = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_xzx(stdmath_int4 v) { return {v.x,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_xzx_get(stdmath_int4* p) { return stdmath_int4_xzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xzx_set(stdmath_int4* p, stdmath_int3 value) { p->x = value.x; p->z = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_xzy(stdmath_int4 v) { return {v.x,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_xzy_get(stdmath_int4* p) { return stdmath_int4_xzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xzy_set(stdmath_int4* p, stdmath_int3 value) { p->x = value.x; p->z = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_xzz(stdmath_int4 v) { return {v.x,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_xzz_get(stdmath_int4* p) { return stdmath_int4_xzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xzz_set(stdmath_int4* p, stdmath_int3 value) { p->x = value.x; p->z = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_xzw(stdmath_int4 v) { return {v.x,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_xzw_get(stdmath_int4* p) { return stdmath_int4_xzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xzw_set(stdmath_int4* p, stdmath_int3 value) { p->x = value.x; p->z = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_xwx(stdmath_int4 v) { return {v.x,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_xwx_get(stdmath_int4* p) { return stdmath_int4_xwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xwx_set(stdmath_int4* p, stdmath_int3 value) { p->x = value.x; p->w = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_xwy(stdmath_int4 v) { return {v.x,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_xwy_get(stdmath_int4* p) { return stdmath_int4_xwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xwy_set(stdmath_int4* p, stdmath_int3 value) { p->x = value.x; p->w = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_xwz(stdmath_int4 v) { return {v.x,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_xwz_get(stdmath_int4* p) { return stdmath_int4_xwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xwz_set(stdmath_int4* p, stdmath_int3 value) { p->x = value.x; p->w = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_xww(stdmath_int4 v) { return {v.x,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_xww_get(stdmath_int4* p) { return stdmath_int4_xww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xww_set(stdmath_int4* p, stdmath_int3 value) { p->x = value.x; p->w = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_yxx(stdmath_int4 v) { return {v.y,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_yxx_get(stdmath_int4* p) { return stdmath_int4_yxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yxx_set(stdmath_int4* p, stdmath_int3 value) { p->y = value.x; p->x = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_yxy(stdmath_int4 v) { return {v.y,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_yxy_get(stdmath_int4* p) { return stdmath_int4_yxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yxy_set(stdmath_int4* p, stdmath_int3 value) { p->y = value.x; p->x = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_yxz(stdmath_int4 v) { return {v.y,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_yxz_get(stdmath_int4* p) { return stdmath_int4_yxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yxz_set(stdmath_int4* p, stdmath_int3 value) { p->y = value.x; p->x = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_yxw(stdmath_int4 v) { return {v.y,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_yxw_get(stdmath_int4* p) { return stdmath_int4_yxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yxw_set(stdmath_int4* p, stdmath_int3 value) { p->y = value.x; p->x = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_yyx(stdmath_int4 v) { return {v.y,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_yyx_get(stdmath_int4* p) { return stdmath_int4_yyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yyx_set(stdmath_int4* p, stdmath_int3 value) { p->y = value.x; p->y = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_yyy(stdmath_int4 v) { return {v.y,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_yyy_get(stdmath_int4* p) { return stdmath_int4_yyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yyy_set(stdmath_int4* p, stdmath_int3 value) { p->y = value.x; p->y = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_yyz(stdmath_int4 v) { return {v.y,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_yyz_get(stdmath_int4* p) { return stdmath_int4_yyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yyz_set(stdmath_int4* p, stdmath_int3 value) { p->y = value.x; p->y = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_yyw(stdmath_int4 v) { return {v.y,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_yyw_get(stdmath_int4* p) { return stdmath_int4_yyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yyw_set(stdmath_int4* p, stdmath_int3 value) { p->y = value.x; p->y = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_yzx(stdmath_int4 v) { return {v.y,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_yzx_get(stdmath_int4* p) { return stdmath_int4_yzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yzx_set(stdmath_int4* p, stdmath_int3 value) { p->y = value.x; p->z = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_yzy(stdmath_int4 v) { return {v.y,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_yzy_get(stdmath_int4* p) { return stdmath_int4_yzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yzy_set(stdmath_int4* p, stdmath_int3 value) { p->y = value.x; p->z = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_yzz(stdmath_int4 v) { return {v.y,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_yzz_get(stdmath_int4* p) { return stdmath_int4_yzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yzz_set(stdmath_int4* p, stdmath_int3 value) { p->y = value.x; p->z = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_yzw(stdmath_int4 v) { return {v.y,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_yzw_get(stdmath_int4* p) { return stdmath_int4_yzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yzw_set(stdmath_int4* p, stdmath_int3 value) { p->y = value.x; p->z = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_ywx(stdmath_int4 v) { return {v.y,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_ywx_get(stdmath_int4* p) { return stdmath_int4_ywx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_ywx_set(stdmath_int4* p, stdmath_int3 value) { p->y = value.x; p->w = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_ywy(stdmath_int4 v) { return {v.y,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_ywy_get(stdmath_int4* p) { return stdmath_int4_ywy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_ywy_set(stdmath_int4* p, stdmath_int3 value) { p->y = value.x; p->w = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_ywz(stdmath_int4 v) { return {v.y,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_ywz_get(stdmath_int4* p) { return stdmath_int4_ywz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_ywz_set(stdmath_int4* p, stdmath_int3 value) { p->y = value.x; p->w = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_yww(stdmath_int4 v) { return {v.y,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_yww_get(stdmath_int4* p) { return stdmath_int4_yww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yww_set(stdmath_int4* p, stdmath_int3 value) { p->y = value.x; p->w = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_zxx(stdmath_int4 v) { return {v.z,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_zxx_get(stdmath_int4* p) { return stdmath_int4_zxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zxx_set(stdmath_int4* p, stdmath_int3 value) { p->z = value.x; p->x = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_zxy(stdmath_int4 v) { return {v.z,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_zxy_get(stdmath_int4* p) { return stdmath_int4_zxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zxy_set(stdmath_int4* p, stdmath_int3 value) { p->z = value.x; p->x = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_zxz(stdmath_int4 v) { return {v.z,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_zxz_get(stdmath_int4* p) { return stdmath_int4_zxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zxz_set(stdmath_int4* p, stdmath_int3 value) { p->z = value.x; p->x = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_zxw(stdmath_int4 v) { return {v.z,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_zxw_get(stdmath_int4* p) { return stdmath_int4_zxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zxw_set(stdmath_int4* p, stdmath_int3 value) { p->z = value.x; p->x = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_zyx(stdmath_int4 v) { return {v.z,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_zyx_get(stdmath_int4* p) { return stdmath_int4_zyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zyx_set(stdmath_int4* p, stdmath_int3 value) { p->z = value.x; p->y = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_zyy(stdmath_int4 v) { return {v.z,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_zyy_get(stdmath_int4* p) { return stdmath_int4_zyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zyy_set(stdmath_int4* p, stdmath_int3 value) { p->z = value.x; p->y = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_zyz(stdmath_int4 v) { return {v.z,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_zyz_get(stdmath_int4* p) { return stdmath_int4_zyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zyz_set(stdmath_int4* p, stdmath_int3 value) { p->z = value.x; p->y = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_zyw(stdmath_int4 v) { return {v.z,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_zyw_get(stdmath_int4* p) { return stdmath_int4_zyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zyw_set(stdmath_int4* p, stdmath_int3 value) { p->z = value.x; p->y = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_zzx(stdmath_int4 v) { return {v.z,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_zzx_get(stdmath_int4* p) { return stdmath_int4_zzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zzx_set(stdmath_int4* p, stdmath_int3 value) { p->z = value.x; p->z = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_zzy(stdmath_int4 v) { return {v.z,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_zzy_get(stdmath_int4* p) { return stdmath_int4_zzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zzy_set(stdmath_int4* p, stdmath_int3 value) { p->z = value.x; p->z = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_zzz(stdmath_int4 v) { return {v.z,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_zzz_get(stdmath_int4* p) { return stdmath_int4_zzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zzz_set(stdmath_int4* p, stdmath_int3 value) { p->z = value.x; p->z = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_zzw(stdmath_int4 v) { return {v.z,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_zzw_get(stdmath_int4* p) { return stdmath_int4_zzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zzw_set(stdmath_int4* p, stdmath_int3 value) { p->z = value.x; p->z = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_zwx(stdmath_int4 v) { return {v.z,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_zwx_get(stdmath_int4* p) { return stdmath_int4_zwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zwx_set(stdmath_int4* p, stdmath_int3 value) { p->z = value.x; p->w = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_zwy(stdmath_int4 v) { return {v.z,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_zwy_get(stdmath_int4* p) { return stdmath_int4_zwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zwy_set(stdmath_int4* p, stdmath_int3 value) { p->z = value.x; p->w = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_zwz(stdmath_int4 v) { return {v.z,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_zwz_get(stdmath_int4* p) { return stdmath_int4_zwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zwz_set(stdmath_int4* p, stdmath_int3 value) { p->z = value.x; p->w = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_zww(stdmath_int4 v) { return {v.z,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_zww_get(stdmath_int4* p) { return stdmath_int4_zww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zww_set(stdmath_int4* p, stdmath_int3 value) { p->z = value.x; p->w = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_wxx(stdmath_int4 v) { return {v.w,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_wxx_get(stdmath_int4* p) { return stdmath_int4_wxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wxx_set(stdmath_int4* p, stdmath_int3 value) { p->w = value.x; p->x = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_wxy(stdmath_int4 v) { return {v.w,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_wxy_get(stdmath_int4* p) { return stdmath_int4_wxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wxy_set(stdmath_int4* p, stdmath_int3 value) { p->w = value.x; p->x = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_wxz(stdmath_int4 v) { return {v.w,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_wxz_get(stdmath_int4* p) { return stdmath_int4_wxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wxz_set(stdmath_int4* p, stdmath_int3 value) { p->w = value.x; p->x = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_wxw(stdmath_int4 v) { return {v.w,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_wxw_get(stdmath_int4* p) { return stdmath_int4_wxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wxw_set(stdmath_int4* p, stdmath_int3 value) { p->w = value.x; p->x = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_wyx(stdmath_int4 v) { return {v.w,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_wyx_get(stdmath_int4* p) { return stdmath_int4_wyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wyx_set(stdmath_int4* p, stdmath_int3 value) { p->w = value.x; p->y = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_wyy(stdmath_int4 v) { return {v.w,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_wyy_get(stdmath_int4* p) { return stdmath_int4_wyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wyy_set(stdmath_int4* p, stdmath_int3 value) { p->w = value.x; p->y = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_wyz(stdmath_int4 v) { return {v.w,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_wyz_get(stdmath_int4* p) { return stdmath_int4_wyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wyz_set(stdmath_int4* p, stdmath_int3 value) { p->w = value.x; p->y = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_wyw(stdmath_int4 v) { return {v.w,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_wyw_get(stdmath_int4* p) { return stdmath_int4_wyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wyw_set(stdmath_int4* p, stdmath_int3 value) { p->w = value.x; p->y = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_wzx(stdmath_int4 v) { return {v.w,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_wzx_get(stdmath_int4* p) { return stdmath_int4_wzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wzx_set(stdmath_int4* p, stdmath_int3 value) { p->w = value.x; p->z = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_wzy(stdmath_int4 v) { return {v.w,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_wzy_get(stdmath_int4* p) { return stdmath_int4_wzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wzy_set(stdmath_int4* p, stdmath_int3 value) { p->w = value.x; p->z = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_wzz(stdmath_int4 v) { return {v.w,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_wzz_get(stdmath_int4* p) { return stdmath_int4_wzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wzz_set(stdmath_int4* p, stdmath_int3 value) { p->w = value.x; p->z = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_wzw(stdmath_int4 v) { return {v.w,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_wzw_get(stdmath_int4* p) { return stdmath_int4_wzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wzw_set(stdmath_int4* p, stdmath_int3 value) { p->w = value.x; p->z = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_wwx(stdmath_int4 v) { return {v.w,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_wwx_get(stdmath_int4* p) { return stdmath_int4_wwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wwx_set(stdmath_int4* p, stdmath_int3 value) { p->w = value.x; p->w = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_wwy(stdmath_int4 v) { return {v.w,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_wwy_get(stdmath_int4* p) { return stdmath_int4_wwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wwy_set(stdmath_int4* p, stdmath_int3 value) { p->w = value.x; p->w = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_wwz(stdmath_int4 v) { return {v.w,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_wwz_get(stdmath_int4* p) { return stdmath_int4_wwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wwz_set(stdmath_int4* p, stdmath_int3 value) { p->w = value.x; p->w = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_www(stdmath_int4 v) { return {v.w,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int4_www_get(stdmath_int4* p) { return stdmath_int4_www(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_www_set(stdmath_int4* p, stdmath_int3 value) { p->w = value.x; p->w = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xxxx(stdmath_int4 v) { return {v.x,v.x,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xxxx_get(stdmath_int4* p) { return stdmath_int4_xxxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xxxx_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->x = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xxxy(stdmath_int4 v) { return {v.x,v.x,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xxxy_get(stdmath_int4* p) { return stdmath_int4_xxxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xxxy_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->x = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xxxz(stdmath_int4 v) { return {v.x,v.x,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xxxz_get(stdmath_int4* p) { return stdmath_int4_xxxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xxxz_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->x = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xxxw(stdmath_int4 v) { return {v.x,v.x,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xxxw_get(stdmath_int4* p) { return stdmath_int4_xxxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xxxw_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->x = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xxyx(stdmath_int4 v) { return {v.x,v.x,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xxyx_get(stdmath_int4* p) { return stdmath_int4_xxyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xxyx_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->x = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xxyy(stdmath_int4 v) { return {v.x,v.x,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xxyy_get(stdmath_int4* p) { return stdmath_int4_xxyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xxyy_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->x = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xxyz(stdmath_int4 v) { return {v.x,v.x,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xxyz_get(stdmath_int4* p) { return stdmath_int4_xxyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xxyz_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->x = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xxyw(stdmath_int4 v) { return {v.x,v.x,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xxyw_get(stdmath_int4* p) { return stdmath_int4_xxyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xxyw_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->x = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xxzx(stdmath_int4 v) { return {v.x,v.x,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xxzx_get(stdmath_int4* p) { return stdmath_int4_xxzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xxzx_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->x = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xxzy(stdmath_int4 v) { return {v.x,v.x,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xxzy_get(stdmath_int4* p) { return stdmath_int4_xxzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xxzy_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->x = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xxzz(stdmath_int4 v) { return {v.x,v.x,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xxzz_get(stdmath_int4* p) { return stdmath_int4_xxzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xxzz_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->x = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xxzw(stdmath_int4 v) { return {v.x,v.x,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xxzw_get(stdmath_int4* p) { return stdmath_int4_xxzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xxzw_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->x = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xxwx(stdmath_int4 v) { return {v.x,v.x,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xxwx_get(stdmath_int4* p) { return stdmath_int4_xxwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xxwx_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->x = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xxwy(stdmath_int4 v) { return {v.x,v.x,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xxwy_get(stdmath_int4* p) { return stdmath_int4_xxwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xxwy_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->x = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xxwz(stdmath_int4 v) { return {v.x,v.x,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xxwz_get(stdmath_int4* p) { return stdmath_int4_xxwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xxwz_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->x = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xxww(stdmath_int4 v) { return {v.x,v.x,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xxww_get(stdmath_int4* p) { return stdmath_int4_xxww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xxww_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->x = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xyxx(stdmath_int4 v) { return {v.x,v.y,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xyxx_get(stdmath_int4* p) { return stdmath_int4_xyxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xyxx_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->y = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xyxy(stdmath_int4 v) { return {v.x,v.y,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xyxy_get(stdmath_int4* p) { return stdmath_int4_xyxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xyxy_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->y = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xyxz(stdmath_int4 v) { return {v.x,v.y,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xyxz_get(stdmath_int4* p) { return stdmath_int4_xyxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xyxz_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->y = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xyxw(stdmath_int4 v) { return {v.x,v.y,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xyxw_get(stdmath_int4* p) { return stdmath_int4_xyxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xyxw_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->y = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xyyx(stdmath_int4 v) { return {v.x,v.y,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xyyx_get(stdmath_int4* p) { return stdmath_int4_xyyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xyyx_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->y = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xyyy(stdmath_int4 v) { return {v.x,v.y,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xyyy_get(stdmath_int4* p) { return stdmath_int4_xyyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xyyy_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->y = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xyyz(stdmath_int4 v) { return {v.x,v.y,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xyyz_get(stdmath_int4* p) { return stdmath_int4_xyyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xyyz_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->y = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xyyw(stdmath_int4 v) { return {v.x,v.y,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xyyw_get(stdmath_int4* p) { return stdmath_int4_xyyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xyyw_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->y = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xyzx(stdmath_int4 v) { return {v.x,v.y,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xyzx_get(stdmath_int4* p) { return stdmath_int4_xyzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xyzx_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->y = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xyzy(stdmath_int4 v) { return {v.x,v.y,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xyzy_get(stdmath_int4* p) { return stdmath_int4_xyzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xyzy_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->y = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xyzz(stdmath_int4 v) { return {v.x,v.y,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xyzz_get(stdmath_int4* p) { return stdmath_int4_xyzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xyzz_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->y = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xyzw(stdmath_int4 v) { return {v.x,v.y,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xyzw_get(stdmath_int4* p) { return stdmath_int4_xyzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xyzw_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->y = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xywx(stdmath_int4 v) { return {v.x,v.y,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xywx_get(stdmath_int4* p) { return stdmath_int4_xywx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xywx_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->y = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xywy(stdmath_int4 v) { return {v.x,v.y,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xywy_get(stdmath_int4* p) { return stdmath_int4_xywy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xywy_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->y = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xywz(stdmath_int4 v) { return {v.x,v.y,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xywz_get(stdmath_int4* p) { return stdmath_int4_xywz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xywz_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->y = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xyww(stdmath_int4 v) { return {v.x,v.y,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xyww_get(stdmath_int4* p) { return stdmath_int4_xyww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xyww_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->y = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xzxx(stdmath_int4 v) { return {v.x,v.z,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xzxx_get(stdmath_int4* p) { return stdmath_int4_xzxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xzxx_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->z = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xzxy(stdmath_int4 v) { return {v.x,v.z,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xzxy_get(stdmath_int4* p) { return stdmath_int4_xzxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xzxy_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->z = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xzxz(stdmath_int4 v) { return {v.x,v.z,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xzxz_get(stdmath_int4* p) { return stdmath_int4_xzxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xzxz_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->z = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xzxw(stdmath_int4 v) { return {v.x,v.z,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xzxw_get(stdmath_int4* p) { return stdmath_int4_xzxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xzxw_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->z = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xzyx(stdmath_int4 v) { return {v.x,v.z,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xzyx_get(stdmath_int4* p) { return stdmath_int4_xzyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xzyx_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->z = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xzyy(stdmath_int4 v) { return {v.x,v.z,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xzyy_get(stdmath_int4* p) { return stdmath_int4_xzyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xzyy_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->z = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xzyz(stdmath_int4 v) { return {v.x,v.z,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xzyz_get(stdmath_int4* p) { return stdmath_int4_xzyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xzyz_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->z = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xzyw(stdmath_int4 v) { return {v.x,v.z,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xzyw_get(stdmath_int4* p) { return stdmath_int4_xzyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xzyw_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->z = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xzzx(stdmath_int4 v) { return {v.x,v.z,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xzzx_get(stdmath_int4* p) { return stdmath_int4_xzzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xzzx_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->z = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xzzy(stdmath_int4 v) { return {v.x,v.z,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xzzy_get(stdmath_int4* p) { return stdmath_int4_xzzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xzzy_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->z = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xzzz(stdmath_int4 v) { return {v.x,v.z,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xzzz_get(stdmath_int4* p) { return stdmath_int4_xzzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xzzz_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->z = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xzzw(stdmath_int4 v) { return {v.x,v.z,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xzzw_get(stdmath_int4* p) { return stdmath_int4_xzzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xzzw_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->z = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xzwx(stdmath_int4 v) { return {v.x,v.z,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xzwx_get(stdmath_int4* p) { return stdmath_int4_xzwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xzwx_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->z = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xzwy(stdmath_int4 v) { return {v.x,v.z,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xzwy_get(stdmath_int4* p) { return stdmath_int4_xzwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xzwy_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->z = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xzwz(stdmath_int4 v) { return {v.x,v.z,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xzwz_get(stdmath_int4* p) { return stdmath_int4_xzwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xzwz_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->z = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xzww(stdmath_int4 v) { return {v.x,v.z,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xzww_get(stdmath_int4* p) { return stdmath_int4_xzww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xzww_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->z = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xwxx(stdmath_int4 v) { return {v.x,v.w,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xwxx_get(stdmath_int4* p) { return stdmath_int4_xwxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xwxx_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->w = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xwxy(stdmath_int4 v) { return {v.x,v.w,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xwxy_get(stdmath_int4* p) { return stdmath_int4_xwxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xwxy_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->w = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xwxz(stdmath_int4 v) { return {v.x,v.w,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xwxz_get(stdmath_int4* p) { return stdmath_int4_xwxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xwxz_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->w = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xwxw(stdmath_int4 v) { return {v.x,v.w,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xwxw_get(stdmath_int4* p) { return stdmath_int4_xwxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xwxw_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->w = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xwyx(stdmath_int4 v) { return {v.x,v.w,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xwyx_get(stdmath_int4* p) { return stdmath_int4_xwyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xwyx_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->w = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xwyy(stdmath_int4 v) { return {v.x,v.w,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xwyy_get(stdmath_int4* p) { return stdmath_int4_xwyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xwyy_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->w = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xwyz(stdmath_int4 v) { return {v.x,v.w,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xwyz_get(stdmath_int4* p) { return stdmath_int4_xwyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xwyz_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->w = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xwyw(stdmath_int4 v) { return {v.x,v.w,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xwyw_get(stdmath_int4* p) { return stdmath_int4_xwyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xwyw_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->w = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xwzx(stdmath_int4 v) { return {v.x,v.w,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xwzx_get(stdmath_int4* p) { return stdmath_int4_xwzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xwzx_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->w = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xwzy(stdmath_int4 v) { return {v.x,v.w,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xwzy_get(stdmath_int4* p) { return stdmath_int4_xwzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xwzy_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->w = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xwzz(stdmath_int4 v) { return {v.x,v.w,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xwzz_get(stdmath_int4* p) { return stdmath_int4_xwzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xwzz_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->w = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xwzw(stdmath_int4 v) { return {v.x,v.w,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xwzw_get(stdmath_int4* p) { return stdmath_int4_xwzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xwzw_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->w = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xwwx(stdmath_int4 v) { return {v.x,v.w,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xwwx_get(stdmath_int4* p) { return stdmath_int4_xwwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xwwx_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->w = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xwwy(stdmath_int4 v) { return {v.x,v.w,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xwwy_get(stdmath_int4* p) { return stdmath_int4_xwwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xwwy_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->w = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xwwz(stdmath_int4 v) { return {v.x,v.w,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xwwz_get(stdmath_int4* p) { return stdmath_int4_xwwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xwwz_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->w = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xwww(stdmath_int4 v) { return {v.x,v.w,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xwww_get(stdmath_int4* p) { return stdmath_int4_xwww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_xwww_set(stdmath_int4* p, stdmath_int4 value) { p->x = value.x; p->w = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yxxx(stdmath_int4 v) { return {v.y,v.x,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yxxx_get(stdmath_int4* p) { return stdmath_int4_yxxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yxxx_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->x = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yxxy(stdmath_int4 v) { return {v.y,v.x,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yxxy_get(stdmath_int4* p) { return stdmath_int4_yxxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yxxy_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->x = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yxxz(stdmath_int4 v) { return {v.y,v.x,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yxxz_get(stdmath_int4* p) { return stdmath_int4_yxxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yxxz_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->x = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yxxw(stdmath_int4 v) { return {v.y,v.x,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yxxw_get(stdmath_int4* p) { return stdmath_int4_yxxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yxxw_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->x = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yxyx(stdmath_int4 v) { return {v.y,v.x,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yxyx_get(stdmath_int4* p) { return stdmath_int4_yxyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yxyx_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->x = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yxyy(stdmath_int4 v) { return {v.y,v.x,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yxyy_get(stdmath_int4* p) { return stdmath_int4_yxyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yxyy_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->x = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yxyz(stdmath_int4 v) { return {v.y,v.x,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yxyz_get(stdmath_int4* p) { return stdmath_int4_yxyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yxyz_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->x = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yxyw(stdmath_int4 v) { return {v.y,v.x,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yxyw_get(stdmath_int4* p) { return stdmath_int4_yxyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yxyw_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->x = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yxzx(stdmath_int4 v) { return {v.y,v.x,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yxzx_get(stdmath_int4* p) { return stdmath_int4_yxzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yxzx_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->x = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yxzy(stdmath_int4 v) { return {v.y,v.x,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yxzy_get(stdmath_int4* p) { return stdmath_int4_yxzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yxzy_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->x = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yxzz(stdmath_int4 v) { return {v.y,v.x,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yxzz_get(stdmath_int4* p) { return stdmath_int4_yxzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yxzz_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->x = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yxzw(stdmath_int4 v) { return {v.y,v.x,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yxzw_get(stdmath_int4* p) { return stdmath_int4_yxzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yxzw_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->x = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yxwx(stdmath_int4 v) { return {v.y,v.x,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yxwx_get(stdmath_int4* p) { return stdmath_int4_yxwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yxwx_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->x = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yxwy(stdmath_int4 v) { return {v.y,v.x,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yxwy_get(stdmath_int4* p) { return stdmath_int4_yxwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yxwy_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->x = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yxwz(stdmath_int4 v) { return {v.y,v.x,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yxwz_get(stdmath_int4* p) { return stdmath_int4_yxwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yxwz_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->x = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yxww(stdmath_int4 v) { return {v.y,v.x,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yxww_get(stdmath_int4* p) { return stdmath_int4_yxww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yxww_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->x = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yyxx(stdmath_int4 v) { return {v.y,v.y,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yyxx_get(stdmath_int4* p) { return stdmath_int4_yyxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yyxx_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->y = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yyxy(stdmath_int4 v) { return {v.y,v.y,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yyxy_get(stdmath_int4* p) { return stdmath_int4_yyxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yyxy_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->y = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yyxz(stdmath_int4 v) { return {v.y,v.y,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yyxz_get(stdmath_int4* p) { return stdmath_int4_yyxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yyxz_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->y = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yyxw(stdmath_int4 v) { return {v.y,v.y,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yyxw_get(stdmath_int4* p) { return stdmath_int4_yyxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yyxw_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->y = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yyyx(stdmath_int4 v) { return {v.y,v.y,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yyyx_get(stdmath_int4* p) { return stdmath_int4_yyyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yyyx_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->y = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yyyy(stdmath_int4 v) { return {v.y,v.y,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yyyy_get(stdmath_int4* p) { return stdmath_int4_yyyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yyyy_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->y = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yyyz(stdmath_int4 v) { return {v.y,v.y,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yyyz_get(stdmath_int4* p) { return stdmath_int4_yyyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yyyz_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->y = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yyyw(stdmath_int4 v) { return {v.y,v.y,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yyyw_get(stdmath_int4* p) { return stdmath_int4_yyyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yyyw_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->y = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yyzx(stdmath_int4 v) { return {v.y,v.y,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yyzx_get(stdmath_int4* p) { return stdmath_int4_yyzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yyzx_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->y = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yyzy(stdmath_int4 v) { return {v.y,v.y,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yyzy_get(stdmath_int4* p) { return stdmath_int4_yyzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yyzy_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->y = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yyzz(stdmath_int4 v) { return {v.y,v.y,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yyzz_get(stdmath_int4* p) { return stdmath_int4_yyzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yyzz_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->y = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yyzw(stdmath_int4 v) { return {v.y,v.y,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yyzw_get(stdmath_int4* p) { return stdmath_int4_yyzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yyzw_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->y = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yywx(stdmath_int4 v) { return {v.y,v.y,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yywx_get(stdmath_int4* p) { return stdmath_int4_yywx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yywx_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->y = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yywy(stdmath_int4 v) { return {v.y,v.y,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yywy_get(stdmath_int4* p) { return stdmath_int4_yywy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yywy_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->y = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yywz(stdmath_int4 v) { return {v.y,v.y,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yywz_get(stdmath_int4* p) { return stdmath_int4_yywz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yywz_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->y = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yyww(stdmath_int4 v) { return {v.y,v.y,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yyww_get(stdmath_int4* p) { return stdmath_int4_yyww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yyww_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->y = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yzxx(stdmath_int4 v) { return {v.y,v.z,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yzxx_get(stdmath_int4* p) { return stdmath_int4_yzxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yzxx_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->z = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yzxy(stdmath_int4 v) { return {v.y,v.z,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yzxy_get(stdmath_int4* p) { return stdmath_int4_yzxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yzxy_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->z = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yzxz(stdmath_int4 v) { return {v.y,v.z,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yzxz_get(stdmath_int4* p) { return stdmath_int4_yzxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yzxz_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->z = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yzxw(stdmath_int4 v) { return {v.y,v.z,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yzxw_get(stdmath_int4* p) { return stdmath_int4_yzxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yzxw_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->z = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yzyx(stdmath_int4 v) { return {v.y,v.z,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yzyx_get(stdmath_int4* p) { return stdmath_int4_yzyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yzyx_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->z = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yzyy(stdmath_int4 v) { return {v.y,v.z,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yzyy_get(stdmath_int4* p) { return stdmath_int4_yzyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yzyy_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->z = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yzyz(stdmath_int4 v) { return {v.y,v.z,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yzyz_get(stdmath_int4* p) { return stdmath_int4_yzyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yzyz_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->z = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yzyw(stdmath_int4 v) { return {v.y,v.z,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yzyw_get(stdmath_int4* p) { return stdmath_int4_yzyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yzyw_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->z = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yzzx(stdmath_int4 v) { return {v.y,v.z,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yzzx_get(stdmath_int4* p) { return stdmath_int4_yzzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yzzx_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->z = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yzzy(stdmath_int4 v) { return {v.y,v.z,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yzzy_get(stdmath_int4* p) { return stdmath_int4_yzzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yzzy_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->z = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yzzz(stdmath_int4 v) { return {v.y,v.z,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yzzz_get(stdmath_int4* p) { return stdmath_int4_yzzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yzzz_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->z = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yzzw(stdmath_int4 v) { return {v.y,v.z,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yzzw_get(stdmath_int4* p) { return stdmath_int4_yzzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yzzw_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->z = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yzwx(stdmath_int4 v) { return {v.y,v.z,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yzwx_get(stdmath_int4* p) { return stdmath_int4_yzwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yzwx_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->z = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yzwy(stdmath_int4 v) { return {v.y,v.z,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yzwy_get(stdmath_int4* p) { return stdmath_int4_yzwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yzwy_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->z = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yzwz(stdmath_int4 v) { return {v.y,v.z,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yzwz_get(stdmath_int4* p) { return stdmath_int4_yzwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yzwz_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->z = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yzww(stdmath_int4 v) { return {v.y,v.z,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yzww_get(stdmath_int4* p) { return stdmath_int4_yzww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_yzww_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->z = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_ywxx(stdmath_int4 v) { return {v.y,v.w,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_ywxx_get(stdmath_int4* p) { return stdmath_int4_ywxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_ywxx_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->w = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_ywxy(stdmath_int4 v) { return {v.y,v.w,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_ywxy_get(stdmath_int4* p) { return stdmath_int4_ywxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_ywxy_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->w = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_ywxz(stdmath_int4 v) { return {v.y,v.w,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_ywxz_get(stdmath_int4* p) { return stdmath_int4_ywxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_ywxz_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->w = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_ywxw(stdmath_int4 v) { return {v.y,v.w,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_ywxw_get(stdmath_int4* p) { return stdmath_int4_ywxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_ywxw_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->w = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_ywyx(stdmath_int4 v) { return {v.y,v.w,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_ywyx_get(stdmath_int4* p) { return stdmath_int4_ywyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_ywyx_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->w = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_ywyy(stdmath_int4 v) { return {v.y,v.w,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_ywyy_get(stdmath_int4* p) { return stdmath_int4_ywyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_ywyy_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->w = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_ywyz(stdmath_int4 v) { return {v.y,v.w,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_ywyz_get(stdmath_int4* p) { return stdmath_int4_ywyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_ywyz_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->w = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_ywyw(stdmath_int4 v) { return {v.y,v.w,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_ywyw_get(stdmath_int4* p) { return stdmath_int4_ywyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_ywyw_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->w = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_ywzx(stdmath_int4 v) { return {v.y,v.w,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_ywzx_get(stdmath_int4* p) { return stdmath_int4_ywzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_ywzx_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->w = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_ywzy(stdmath_int4 v) { return {v.y,v.w,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_ywzy_get(stdmath_int4* p) { return stdmath_int4_ywzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_ywzy_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->w = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_ywzz(stdmath_int4 v) { return {v.y,v.w,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_ywzz_get(stdmath_int4* p) { return stdmath_int4_ywzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_ywzz_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->w = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_ywzw(stdmath_int4 v) { return {v.y,v.w,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_ywzw_get(stdmath_int4* p) { return stdmath_int4_ywzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_ywzw_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->w = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_ywwx(stdmath_int4 v) { return {v.y,v.w,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_ywwx_get(stdmath_int4* p) { return stdmath_int4_ywwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_ywwx_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->w = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_ywwy(stdmath_int4 v) { return {v.y,v.w,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_ywwy_get(stdmath_int4* p) { return stdmath_int4_ywwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_ywwy_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->w = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_ywwz(stdmath_int4 v) { return {v.y,v.w,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_ywwz_get(stdmath_int4* p) { return stdmath_int4_ywwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_ywwz_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->w = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_ywww(stdmath_int4 v) { return {v.y,v.w,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_ywww_get(stdmath_int4* p) { return stdmath_int4_ywww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_ywww_set(stdmath_int4* p, stdmath_int4 value) { p->y = value.x; p->w = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zxxx(stdmath_int4 v) { return {v.z,v.x,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zxxx_get(stdmath_int4* p) { return stdmath_int4_zxxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zxxx_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->x = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zxxy(stdmath_int4 v) { return {v.z,v.x,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zxxy_get(stdmath_int4* p) { return stdmath_int4_zxxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zxxy_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->x = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zxxz(stdmath_int4 v) { return {v.z,v.x,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zxxz_get(stdmath_int4* p) { return stdmath_int4_zxxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zxxz_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->x = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zxxw(stdmath_int4 v) { return {v.z,v.x,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zxxw_get(stdmath_int4* p) { return stdmath_int4_zxxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zxxw_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->x = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zxyx(stdmath_int4 v) { return {v.z,v.x,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zxyx_get(stdmath_int4* p) { return stdmath_int4_zxyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zxyx_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->x = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zxyy(stdmath_int4 v) { return {v.z,v.x,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zxyy_get(stdmath_int4* p) { return stdmath_int4_zxyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zxyy_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->x = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zxyz(stdmath_int4 v) { return {v.z,v.x,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zxyz_get(stdmath_int4* p) { return stdmath_int4_zxyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zxyz_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->x = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zxyw(stdmath_int4 v) { return {v.z,v.x,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zxyw_get(stdmath_int4* p) { return stdmath_int4_zxyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zxyw_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->x = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zxzx(stdmath_int4 v) { return {v.z,v.x,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zxzx_get(stdmath_int4* p) { return stdmath_int4_zxzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zxzx_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->x = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zxzy(stdmath_int4 v) { return {v.z,v.x,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zxzy_get(stdmath_int4* p) { return stdmath_int4_zxzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zxzy_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->x = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zxzz(stdmath_int4 v) { return {v.z,v.x,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zxzz_get(stdmath_int4* p) { return stdmath_int4_zxzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zxzz_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->x = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zxzw(stdmath_int4 v) { return {v.z,v.x,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zxzw_get(stdmath_int4* p) { return stdmath_int4_zxzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zxzw_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->x = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zxwx(stdmath_int4 v) { return {v.z,v.x,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zxwx_get(stdmath_int4* p) { return stdmath_int4_zxwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zxwx_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->x = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zxwy(stdmath_int4 v) { return {v.z,v.x,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zxwy_get(stdmath_int4* p) { return stdmath_int4_zxwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zxwy_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->x = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zxwz(stdmath_int4 v) { return {v.z,v.x,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zxwz_get(stdmath_int4* p) { return stdmath_int4_zxwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zxwz_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->x = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zxww(stdmath_int4 v) { return {v.z,v.x,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zxww_get(stdmath_int4* p) { return stdmath_int4_zxww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zxww_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->x = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zyxx(stdmath_int4 v) { return {v.z,v.y,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zyxx_get(stdmath_int4* p) { return stdmath_int4_zyxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zyxx_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->y = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zyxy(stdmath_int4 v) { return {v.z,v.y,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zyxy_get(stdmath_int4* p) { return stdmath_int4_zyxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zyxy_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->y = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zyxz(stdmath_int4 v) { return {v.z,v.y,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zyxz_get(stdmath_int4* p) { return stdmath_int4_zyxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zyxz_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->y = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zyxw(stdmath_int4 v) { return {v.z,v.y,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zyxw_get(stdmath_int4* p) { return stdmath_int4_zyxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zyxw_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->y = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zyyx(stdmath_int4 v) { return {v.z,v.y,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zyyx_get(stdmath_int4* p) { return stdmath_int4_zyyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zyyx_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->y = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zyyy(stdmath_int4 v) { return {v.z,v.y,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zyyy_get(stdmath_int4* p) { return stdmath_int4_zyyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zyyy_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->y = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zyyz(stdmath_int4 v) { return {v.z,v.y,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zyyz_get(stdmath_int4* p) { return stdmath_int4_zyyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zyyz_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->y = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zyyw(stdmath_int4 v) { return {v.z,v.y,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zyyw_get(stdmath_int4* p) { return stdmath_int4_zyyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zyyw_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->y = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zyzx(stdmath_int4 v) { return {v.z,v.y,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zyzx_get(stdmath_int4* p) { return stdmath_int4_zyzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zyzx_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->y = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zyzy(stdmath_int4 v) { return {v.z,v.y,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zyzy_get(stdmath_int4* p) { return stdmath_int4_zyzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zyzy_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->y = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zyzz(stdmath_int4 v) { return {v.z,v.y,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zyzz_get(stdmath_int4* p) { return stdmath_int4_zyzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zyzz_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->y = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zyzw(stdmath_int4 v) { return {v.z,v.y,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zyzw_get(stdmath_int4* p) { return stdmath_int4_zyzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zyzw_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->y = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zywx(stdmath_int4 v) { return {v.z,v.y,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zywx_get(stdmath_int4* p) { return stdmath_int4_zywx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zywx_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->y = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zywy(stdmath_int4 v) { return {v.z,v.y,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zywy_get(stdmath_int4* p) { return stdmath_int4_zywy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zywy_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->y = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zywz(stdmath_int4 v) { return {v.z,v.y,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zywz_get(stdmath_int4* p) { return stdmath_int4_zywz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zywz_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->y = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zyww(stdmath_int4 v) { return {v.z,v.y,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zyww_get(stdmath_int4* p) { return stdmath_int4_zyww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zyww_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->y = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zzxx(stdmath_int4 v) { return {v.z,v.z,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zzxx_get(stdmath_int4* p) { return stdmath_int4_zzxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zzxx_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->z = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zzxy(stdmath_int4 v) { return {v.z,v.z,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zzxy_get(stdmath_int4* p) { return stdmath_int4_zzxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zzxy_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->z = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zzxz(stdmath_int4 v) { return {v.z,v.z,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zzxz_get(stdmath_int4* p) { return stdmath_int4_zzxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zzxz_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->z = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zzxw(stdmath_int4 v) { return {v.z,v.z,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zzxw_get(stdmath_int4* p) { return stdmath_int4_zzxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zzxw_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->z = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zzyx(stdmath_int4 v) { return {v.z,v.z,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zzyx_get(stdmath_int4* p) { return stdmath_int4_zzyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zzyx_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->z = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zzyy(stdmath_int4 v) { return {v.z,v.z,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zzyy_get(stdmath_int4* p) { return stdmath_int4_zzyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zzyy_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->z = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zzyz(stdmath_int4 v) { return {v.z,v.z,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zzyz_get(stdmath_int4* p) { return stdmath_int4_zzyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zzyz_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->z = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zzyw(stdmath_int4 v) { return {v.z,v.z,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zzyw_get(stdmath_int4* p) { return stdmath_int4_zzyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zzyw_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->z = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zzzx(stdmath_int4 v) { return {v.z,v.z,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zzzx_get(stdmath_int4* p) { return stdmath_int4_zzzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zzzx_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->z = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zzzy(stdmath_int4 v) { return {v.z,v.z,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zzzy_get(stdmath_int4* p) { return stdmath_int4_zzzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zzzy_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->z = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zzzz(stdmath_int4 v) { return {v.z,v.z,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zzzz_get(stdmath_int4* p) { return stdmath_int4_zzzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zzzz_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->z = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zzzw(stdmath_int4 v) { return {v.z,v.z,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zzzw_get(stdmath_int4* p) { return stdmath_int4_zzzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zzzw_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->z = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zzwx(stdmath_int4 v) { return {v.z,v.z,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zzwx_get(stdmath_int4* p) { return stdmath_int4_zzwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zzwx_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->z = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zzwy(stdmath_int4 v) { return {v.z,v.z,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zzwy_get(stdmath_int4* p) { return stdmath_int4_zzwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zzwy_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->z = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zzwz(stdmath_int4 v) { return {v.z,v.z,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zzwz_get(stdmath_int4* p) { return stdmath_int4_zzwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zzwz_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->z = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zzww(stdmath_int4 v) { return {v.z,v.z,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zzww_get(stdmath_int4* p) { return stdmath_int4_zzww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zzww_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->z = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zwxx(stdmath_int4 v) { return {v.z,v.w,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zwxx_get(stdmath_int4* p) { return stdmath_int4_zwxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zwxx_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->w = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zwxy(stdmath_int4 v) { return {v.z,v.w,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zwxy_get(stdmath_int4* p) { return stdmath_int4_zwxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zwxy_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->w = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zwxz(stdmath_int4 v) { return {v.z,v.w,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zwxz_get(stdmath_int4* p) { return stdmath_int4_zwxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zwxz_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->w = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zwxw(stdmath_int4 v) { return {v.z,v.w,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zwxw_get(stdmath_int4* p) { return stdmath_int4_zwxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zwxw_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->w = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zwyx(stdmath_int4 v) { return {v.z,v.w,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zwyx_get(stdmath_int4* p) { return stdmath_int4_zwyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zwyx_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->w = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zwyy(stdmath_int4 v) { return {v.z,v.w,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zwyy_get(stdmath_int4* p) { return stdmath_int4_zwyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zwyy_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->w = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zwyz(stdmath_int4 v) { return {v.z,v.w,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zwyz_get(stdmath_int4* p) { return stdmath_int4_zwyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zwyz_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->w = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zwyw(stdmath_int4 v) { return {v.z,v.w,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zwyw_get(stdmath_int4* p) { return stdmath_int4_zwyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zwyw_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->w = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zwzx(stdmath_int4 v) { return {v.z,v.w,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zwzx_get(stdmath_int4* p) { return stdmath_int4_zwzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zwzx_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->w = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zwzy(stdmath_int4 v) { return {v.z,v.w,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zwzy_get(stdmath_int4* p) { return stdmath_int4_zwzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zwzy_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->w = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zwzz(stdmath_int4 v) { return {v.z,v.w,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zwzz_get(stdmath_int4* p) { return stdmath_int4_zwzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zwzz_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->w = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zwzw(stdmath_int4 v) { return {v.z,v.w,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zwzw_get(stdmath_int4* p) { return stdmath_int4_zwzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zwzw_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->w = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zwwx(stdmath_int4 v) { return {v.z,v.w,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zwwx_get(stdmath_int4* p) { return stdmath_int4_zwwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zwwx_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->w = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zwwy(stdmath_int4 v) { return {v.z,v.w,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zwwy_get(stdmath_int4* p) { return stdmath_int4_zwwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zwwy_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->w = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zwwz(stdmath_int4 v) { return {v.z,v.w,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zwwz_get(stdmath_int4* p) { return stdmath_int4_zwwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zwwz_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->w = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zwww(stdmath_int4 v) { return {v.z,v.w,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zwww_get(stdmath_int4* p) { return stdmath_int4_zwww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_zwww_set(stdmath_int4* p, stdmath_int4 value) { p->z = value.x; p->w = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wxxx(stdmath_int4 v) { return {v.w,v.x,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wxxx_get(stdmath_int4* p) { return stdmath_int4_wxxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wxxx_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->x = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wxxy(stdmath_int4 v) { return {v.w,v.x,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wxxy_get(stdmath_int4* p) { return stdmath_int4_wxxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wxxy_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->x = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wxxz(stdmath_int4 v) { return {v.w,v.x,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wxxz_get(stdmath_int4* p) { return stdmath_int4_wxxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wxxz_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->x = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wxxw(stdmath_int4 v) { return {v.w,v.x,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wxxw_get(stdmath_int4* p) { return stdmath_int4_wxxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wxxw_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->x = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wxyx(stdmath_int4 v) { return {v.w,v.x,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wxyx_get(stdmath_int4* p) { return stdmath_int4_wxyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wxyx_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->x = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wxyy(stdmath_int4 v) { return {v.w,v.x,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wxyy_get(stdmath_int4* p) { return stdmath_int4_wxyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wxyy_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->x = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wxyz(stdmath_int4 v) { return {v.w,v.x,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wxyz_get(stdmath_int4* p) { return stdmath_int4_wxyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wxyz_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->x = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wxyw(stdmath_int4 v) { return {v.w,v.x,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wxyw_get(stdmath_int4* p) { return stdmath_int4_wxyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wxyw_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->x = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wxzx(stdmath_int4 v) { return {v.w,v.x,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wxzx_get(stdmath_int4* p) { return stdmath_int4_wxzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wxzx_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->x = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wxzy(stdmath_int4 v) { return {v.w,v.x,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wxzy_get(stdmath_int4* p) { return stdmath_int4_wxzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wxzy_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->x = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wxzz(stdmath_int4 v) { return {v.w,v.x,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wxzz_get(stdmath_int4* p) { return stdmath_int4_wxzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wxzz_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->x = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wxzw(stdmath_int4 v) { return {v.w,v.x,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wxzw_get(stdmath_int4* p) { return stdmath_int4_wxzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wxzw_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->x = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wxwx(stdmath_int4 v) { return {v.w,v.x,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wxwx_get(stdmath_int4* p) { return stdmath_int4_wxwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wxwx_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->x = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wxwy(stdmath_int4 v) { return {v.w,v.x,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wxwy_get(stdmath_int4* p) { return stdmath_int4_wxwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wxwy_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->x = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wxwz(stdmath_int4 v) { return {v.w,v.x,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wxwz_get(stdmath_int4* p) { return stdmath_int4_wxwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wxwz_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->x = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wxww(stdmath_int4 v) { return {v.w,v.x,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wxww_get(stdmath_int4* p) { return stdmath_int4_wxww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wxww_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->x = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wyxx(stdmath_int4 v) { return {v.w,v.y,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wyxx_get(stdmath_int4* p) { return stdmath_int4_wyxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wyxx_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->y = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wyxy(stdmath_int4 v) { return {v.w,v.y,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wyxy_get(stdmath_int4* p) { return stdmath_int4_wyxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wyxy_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->y = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wyxz(stdmath_int4 v) { return {v.w,v.y,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wyxz_get(stdmath_int4* p) { return stdmath_int4_wyxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wyxz_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->y = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wyxw(stdmath_int4 v) { return {v.w,v.y,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wyxw_get(stdmath_int4* p) { return stdmath_int4_wyxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wyxw_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->y = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wyyx(stdmath_int4 v) { return {v.w,v.y,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wyyx_get(stdmath_int4* p) { return stdmath_int4_wyyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wyyx_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->y = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wyyy(stdmath_int4 v) { return {v.w,v.y,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wyyy_get(stdmath_int4* p) { return stdmath_int4_wyyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wyyy_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->y = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wyyz(stdmath_int4 v) { return {v.w,v.y,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wyyz_get(stdmath_int4* p) { return stdmath_int4_wyyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wyyz_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->y = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wyyw(stdmath_int4 v) { return {v.w,v.y,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wyyw_get(stdmath_int4* p) { return stdmath_int4_wyyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wyyw_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->y = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wyzx(stdmath_int4 v) { return {v.w,v.y,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wyzx_get(stdmath_int4* p) { return stdmath_int4_wyzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wyzx_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->y = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wyzy(stdmath_int4 v) { return {v.w,v.y,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wyzy_get(stdmath_int4* p) { return stdmath_int4_wyzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wyzy_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->y = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wyzz(stdmath_int4 v) { return {v.w,v.y,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wyzz_get(stdmath_int4* p) { return stdmath_int4_wyzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wyzz_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->y = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wyzw(stdmath_int4 v) { return {v.w,v.y,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wyzw_get(stdmath_int4* p) { return stdmath_int4_wyzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wyzw_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->y = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wywx(stdmath_int4 v) { return {v.w,v.y,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wywx_get(stdmath_int4* p) { return stdmath_int4_wywx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wywx_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->y = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wywy(stdmath_int4 v) { return {v.w,v.y,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wywy_get(stdmath_int4* p) { return stdmath_int4_wywy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wywy_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->y = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wywz(stdmath_int4 v) { return {v.w,v.y,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wywz_get(stdmath_int4* p) { return stdmath_int4_wywz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wywz_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->y = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wyww(stdmath_int4 v) { return {v.w,v.y,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wyww_get(stdmath_int4* p) { return stdmath_int4_wyww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wyww_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->y = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wzxx(stdmath_int4 v) { return {v.w,v.z,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wzxx_get(stdmath_int4* p) { return stdmath_int4_wzxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wzxx_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->z = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wzxy(stdmath_int4 v) { return {v.w,v.z,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wzxy_get(stdmath_int4* p) { return stdmath_int4_wzxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wzxy_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->z = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wzxz(stdmath_int4 v) { return {v.w,v.z,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wzxz_get(stdmath_int4* p) { return stdmath_int4_wzxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wzxz_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->z = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wzxw(stdmath_int4 v) { return {v.w,v.z,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wzxw_get(stdmath_int4* p) { return stdmath_int4_wzxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wzxw_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->z = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wzyx(stdmath_int4 v) { return {v.w,v.z,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wzyx_get(stdmath_int4* p) { return stdmath_int4_wzyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wzyx_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->z = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wzyy(stdmath_int4 v) { return {v.w,v.z,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wzyy_get(stdmath_int4* p) { return stdmath_int4_wzyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wzyy_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->z = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wzyz(stdmath_int4 v) { return {v.w,v.z,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wzyz_get(stdmath_int4* p) { return stdmath_int4_wzyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wzyz_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->z = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wzyw(stdmath_int4 v) { return {v.w,v.z,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wzyw_get(stdmath_int4* p) { return stdmath_int4_wzyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wzyw_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->z = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wzzx(stdmath_int4 v) { return {v.w,v.z,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wzzx_get(stdmath_int4* p) { return stdmath_int4_wzzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wzzx_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->z = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wzzy(stdmath_int4 v) { return {v.w,v.z,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wzzy_get(stdmath_int4* p) { return stdmath_int4_wzzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wzzy_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->z = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wzzz(stdmath_int4 v) { return {v.w,v.z,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wzzz_get(stdmath_int4* p) { return stdmath_int4_wzzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wzzz_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->z = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wzzw(stdmath_int4 v) { return {v.w,v.z,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wzzw_get(stdmath_int4* p) { return stdmath_int4_wzzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wzzw_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->z = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wzwx(stdmath_int4 v) { return {v.w,v.z,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wzwx_get(stdmath_int4* p) { return stdmath_int4_wzwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wzwx_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->z = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wzwy(stdmath_int4 v) { return {v.w,v.z,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wzwy_get(stdmath_int4* p) { return stdmath_int4_wzwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wzwy_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->z = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wzwz(stdmath_int4 v) { return {v.w,v.z,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wzwz_get(stdmath_int4* p) { return stdmath_int4_wzwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wzwz_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->z = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wzww(stdmath_int4 v) { return {v.w,v.z,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wzww_get(stdmath_int4* p) { return stdmath_int4_wzww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wzww_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->z = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wwxx(stdmath_int4 v) { return {v.w,v.w,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wwxx_get(stdmath_int4* p) { return stdmath_int4_wwxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wwxx_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->w = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wwxy(stdmath_int4 v) { return {v.w,v.w,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wwxy_get(stdmath_int4* p) { return stdmath_int4_wwxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wwxy_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->w = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wwxz(stdmath_int4 v) { return {v.w,v.w,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wwxz_get(stdmath_int4* p) { return stdmath_int4_wwxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wwxz_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->w = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wwxw(stdmath_int4 v) { return {v.w,v.w,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wwxw_get(stdmath_int4* p) { return stdmath_int4_wwxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wwxw_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->w = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wwyx(stdmath_int4 v) { return {v.w,v.w,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wwyx_get(stdmath_int4* p) { return stdmath_int4_wwyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wwyx_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->w = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wwyy(stdmath_int4 v) { return {v.w,v.w,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wwyy_get(stdmath_int4* p) { return stdmath_int4_wwyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wwyy_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->w = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wwyz(stdmath_int4 v) { return {v.w,v.w,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wwyz_get(stdmath_int4* p) { return stdmath_int4_wwyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wwyz_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->w = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wwyw(stdmath_int4 v) { return {v.w,v.w,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wwyw_get(stdmath_int4* p) { return stdmath_int4_wwyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wwyw_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->w = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wwzx(stdmath_int4 v) { return {v.w,v.w,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wwzx_get(stdmath_int4* p) { return stdmath_int4_wwzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wwzx_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->w = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wwzy(stdmath_int4 v) { return {v.w,v.w,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wwzy_get(stdmath_int4* p) { return stdmath_int4_wwzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wwzy_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->w = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wwzz(stdmath_int4 v) { return {v.w,v.w,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wwzz_get(stdmath_int4* p) { return stdmath_int4_wwzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wwzz_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->w = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wwzw(stdmath_int4 v) { return {v.w,v.w,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wwzw_get(stdmath_int4* p) { return stdmath_int4_wwzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wwzw_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->w = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wwwx(stdmath_int4 v) { return {v.w,v.w,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wwwx_get(stdmath_int4* p) { return stdmath_int4_wwwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wwwx_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->w = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wwwy(stdmath_int4 v) { return {v.w,v.w,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wwwy_get(stdmath_int4* p) { return stdmath_int4_wwwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wwwy_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->w = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wwwz(stdmath_int4 v) { return {v.w,v.w,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wwwz_get(stdmath_int4* p) { return stdmath_int4_wwwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wwwz_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->w = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wwww(stdmath_int4 v) { return {v.w,v.w,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wwww_get(stdmath_int4* p) { return stdmath_int4_wwww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int4 stdmath_int4_wwww_set(stdmath_int4* p, stdmath_int4 value) { p->w = value.x; p->w = value.y; p->w = value.z; p->w = value.w; return *p; }

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

inline stdmath::int4 c(stdmath_int4 c) {
	return (stdmath::int4&)c;
}
inline stdmath_int4 c(stdmath::int4 c) {
	return (stdmath_int4&)c;
}

#ifdef __cplusplus
extern "C" {
#endif

stdmath_int4 stdmath_int4_broadcast(int32_t all) {
	return c(stdmath::int4((stdmath::int4::underlying_type&)all));
}

stdmath_int4 stdmath_int4_add(stdmath_int4 a, stdmath_int4 b) {
	return c(c(a) + c(b));
}
stdmath_int4 stdmath_int4_subtract(stdmath_int4 a, stdmath_int4 b) {
	return c(c(a) - c(b));
}
stdmath_int4 stdmath_int4_negate(stdmath_int4 v) {
#if !false && !false
	return c(stdmath::int4(-(stdmath::vector<int32_t, 4>)c(v)));
#else
	assert(false && "TODO: Why can't we use - on vector<degree/radian, N>?");
#endif
}
stdmath_int4 stdmath_int4_multiply(stdmath_int4 a, stdmath_int4 b) {
	return c(c(a) * c(b));
}
stdmath_int4 stdmath_int4_divide(stdmath_int4 a, stdmath_int4 b) {
	return c(c(a) / c(b));
}
stdmath_int4 stdmath_int4_scale(stdmath_int4 v, int32_t s) {
	return c(c(v) * (stdmath::int4::underlying_type&)s);
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
	auto out = c(v).length_squared();
	return (int32_t&)out;
}
int32_t stdmath_int4_length(stdmath_int4 v)  {
	auto out = c(v).length();
	return (int32_t&)out;
}
int32_t stdmath_int4_dot(stdmath_int4 a, stdmath_int4 b)  {
	auto out = dot(c(a), c(b));
	return (int32_t&)out;
}
int32_t stdmath_int4_min_element(stdmath_int4 v)  {
	auto out = c(v).min_element();
	return (int32_t&)out;
}
int32_t stdmath_int4_max_element(stdmath_int4 v)  {
	auto out = c(v).max_element();
	return (int32_t&)out;
}

// stdmath_int4 stdmath_int4_elementwise_transform(stdmath_int4 v, int32_t(*func)(int32_t)) {
// 	return c(c(v).elementwise_transform(func));
// }
// int32_t stdmath_int4_reduce_elements(stdmath_int4 v, int32_t initial_value, int32_t(*reducer)(stdmath_int4, stdmath_int4)) {
// 	return c(v).reduce_elements(initial_value, reducer);
// }

#if 4 == 3
stdmath_int4 stdmath_int4_cross(stdmath_int4 a, stdmath_int4 b) {
	return c(cross(c(a), c(b)));
}
#endif

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

#ifdef __cplusplus
} // extern "C"
#endif

#endif // STDMATH_IMPLEMENTATION

#endif // __STDMATH_int32_t4_H__