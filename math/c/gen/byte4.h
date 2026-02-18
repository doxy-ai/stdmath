#ifndef __STDMATH_uint8_t4_H__
#define __STDMATH_uint8_t4_H__

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
#include "byte1.h"
#elif 4 == 3
#include "byte2.h"
#include "byte1.h"
#elif 4 == 4
#include "byte3.h"
#include "byte2.h"
#include "byte1.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if 4 == 1
STDMATH_EXPORT union stdmath_byte1 {
	struct {
		uint8_t x;
	};
	uint8_t data[1];
};
#elif 4 == 2
STDMATH_EXPORT union stdmath_byte2 {
	struct {
		uint8_t x, y;
	};
	struct {
		uint8_t u, v;
	};
	uint8_t data[2];
};
#elif 4 == 3
STDMATH_EXPORT union stdmath_byte3 {
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
STDMATH_EXPORT union stdmath_byte4 {
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

STDMATH_EXPORT stdmath_byte4 stdmath_byte4_broadcast(uint8_t all);

STDMATH_EXPORT stdmath_byte4 stdmath_byte4_add(stdmath_byte4 a, stdmath_byte4 b);
STDMATH_EXPORT stdmath_byte4 stdmath_byte4_subtract(stdmath_byte4 a, stdmath_byte4 b);
STDMATH_EXPORT stdmath_byte4 stdmath_byte4_negate(stdmath_byte4 v);
STDMATH_EXPORT stdmath_byte4 stdmath_byte4_multiply(stdmath_byte4 a, stdmath_byte4 b);
STDMATH_EXPORT stdmath_byte4 stdmath_byte4_divide(stdmath_byte4 a, stdmath_byte4 b);
STDMATH_EXPORT stdmath_byte4 stdmath_byte4_scale(stdmath_byte4 v, uint8_t s);

#if false
STDMATH_EXPORT stdmath_byte4 stdmath_byte4_modulus(stdmath_byte4 a, stdmath_byte4 b);
STDMATH_EXPORT stdmath_byte4 stdmath_byte4_logical_not(stdmath_byte4 v);
STDMATH_EXPORT stdmath_byte4 stdmath_byte4_bitwise_not(stdmath_byte4 v);
STDMATH_EXPORT stdmath_byte4 stdmath_byte4_logical_and(stdmath_byte4 a, stdmath_byte4 b);
STDMATH_EXPORT stdmath_byte4 stdmath_byte4_bitwise_and(stdmath_byte4 a, stdmath_byte4 b);
STDMATH_EXPORT stdmath_byte4 stdmath_byte4_logical_or(stdmath_byte4 a, stdmath_byte4 b);
STDMATH_EXPORT stdmath_byte4 stdmath_byte4_bitwise_or(stdmath_byte4 a, stdmath_byte4 b);
STDMATH_EXPORT stdmath_byte4 stdmath_byte4_bitwise_xor(stdmath_byte4 a, stdmath_byte4 b);
STDMATH_EXPORT stdmath_byte4 stdmath_byte4_shift_left(stdmath_byte4 a, stdmath_byte4 b);
STDMATH_EXPORT stdmath_byte4 stdmath_byte4_shift_right(stdmath_byte4 a, stdmath_byte4 b);
#endif

STDMATH_EXPORT stdmath_bool4 stdmath_byte4_equal_to(stdmath_byte4 a, stdmath_byte4 b);
STDMATH_EXPORT stdmath_bool4 stdmath_byte4_not_equal_to(stdmath_byte4 a, stdmath_byte4 b);
STDMATH_EXPORT stdmath_bool4 stdmath_byte4_less_than(stdmath_byte4 a, stdmath_byte4 b);
STDMATH_EXPORT stdmath_bool4 stdmath_byte4_less_than_or_equal_to(stdmath_byte4 a, stdmath_byte4 b);
STDMATH_EXPORT stdmath_bool4 stdmath_byte4_greater_than(stdmath_byte4 a, stdmath_byte4 b);
STDMATH_EXPORT stdmath_bool4 stdmath_byte4_greater_than_or_equal_to(stdmath_byte4 a, stdmath_byte4 b);

STDMATH_EXPORT uint8_t stdmath_byte4_length_squared(stdmath_byte4 v);
STDMATH_EXPORT uint8_t stdmath_byte4_length(stdmath_byte4 v);
STDMATH_EXPORT uint8_t stdmath_byte4_dot(stdmath_byte4 a, stdmath_byte4 b);
STDMATH_EXPORT uint8_t stdmath_byte4_min_element(stdmath_byte4 v);
STDMATH_EXPORT uint8_t stdmath_byte4_max_element(stdmath_byte4 v);

// STDMATH_EXPORT stdmath_byte4 stdmath_byte4_elementwise_transform(stdmath_byte4 v, uint8_t(*func)(uint8_t));
// STDMATH_EXPORT uint8_t stdmath_byte4_reduce_elements(stdmath_byte4 v, uint8_t initial_value, uint8_t(*reducer)(stdmath_byte4, stdmath_byte4));

#if 4 == 3
STDMATH_EXPORT stdmath_byte3 stdmath_byte3_cross(stdmath_byte3 a, stdmath_byte3 b);
#endif

STDMATH_EXPORT stdmath_byte4 stdmath_byte4_min(stdmath_byte4 a, stdmath_byte4 b);
STDMATH_EXPORT stdmath_byte4 stdmath_byte4_max(stdmath_byte4 a, stdmath_byte4 b);
STDMATH_EXPORT stdmath_byte4 stdmath_byte4_normalize(stdmath_byte4 v);
STDMATH_EXPORT stdmath_byte4 stdmath_byte4_lerp(stdmath_byte4 a, stdmath_byte4 b, float t);
STDMATH_EXPORT stdmath_byte4 stdmath_byte4_clamp(stdmath_byte4 a, stdmath_byte4 min, stdmath_byte4 max);
STDMATH_EXPORT stdmath_byte4 stdmath_byte4_reflect(stdmath_byte4 a, stdmath_byte4 b);
STDMATH_EXPORT stdmath_bool4 stdmath_byte4_approximately_equal(stdmath_byte4 a, stdmath_byte4 b);

#if false
STDMATH_EXPORT bool stdmath_bool4_all_of(stdmath_bool4 v);
STDMATH_EXPORT bool stdmath_bool4_any_of(stdmath_bool4 v);
STDMATH_EXPORT bool stdmath_bool4_none_of(stdmath_bool4 v);
STDMATH_EXPORT bool stdmath_bool4_some_of(stdmath_bool4 v);
#endif

#ifndef STDMATH_NO_SWIZZLES
STDMATH_EXPORT STDMATH_INLINE stdmath_byte1 stdmath_byte4_x(stdmath_byte4 v) { return {v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte1 stdmath_byte4_x_get(stdmath_byte4* p) { return stdmath_byte4_x(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_x_set(stdmath_byte4* p, stdmath_byte1 value) { p->x = value.x; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte1 stdmath_byte4_y(stdmath_byte4 v) { return {v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte1 stdmath_byte4_y_get(stdmath_byte4* p) { return stdmath_byte4_y(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_y_set(stdmath_byte4* p, stdmath_byte1 value) { p->y = value.x; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte1 stdmath_byte4_z(stdmath_byte4 v) { return {v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte1 stdmath_byte4_z_get(stdmath_byte4* p) { return stdmath_byte4_z(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_z_set(stdmath_byte4* p, stdmath_byte1 value) { p->z = value.x; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte1 stdmath_byte4_w(stdmath_byte4 v) { return {v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte1 stdmath_byte4_w_get(stdmath_byte4* p) { return stdmath_byte4_w(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_w_set(stdmath_byte4* p, stdmath_byte1 value) { p->w = value.x; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte2 stdmath_byte4_xx(stdmath_byte4 v) { return {v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte2 stdmath_byte4_xx_get(stdmath_byte4* p) { return stdmath_byte4_xx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xx_set(stdmath_byte4* p, stdmath_byte2 value) { p->x = value.x; p->x = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte2 stdmath_byte4_xy(stdmath_byte4 v) { return {v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte2 stdmath_byte4_xy_get(stdmath_byte4* p) { return stdmath_byte4_xy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xy_set(stdmath_byte4* p, stdmath_byte2 value) { p->x = value.x; p->y = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte2 stdmath_byte4_xz(stdmath_byte4 v) { return {v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte2 stdmath_byte4_xz_get(stdmath_byte4* p) { return stdmath_byte4_xz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xz_set(stdmath_byte4* p, stdmath_byte2 value) { p->x = value.x; p->z = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte2 stdmath_byte4_xw(stdmath_byte4 v) { return {v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte2 stdmath_byte4_xw_get(stdmath_byte4* p) { return stdmath_byte4_xw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xw_set(stdmath_byte4* p, stdmath_byte2 value) { p->x = value.x; p->w = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte2 stdmath_byte4_yx(stdmath_byte4 v) { return {v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte2 stdmath_byte4_yx_get(stdmath_byte4* p) { return stdmath_byte4_yx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yx_set(stdmath_byte4* p, stdmath_byte2 value) { p->y = value.x; p->x = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte2 stdmath_byte4_yy(stdmath_byte4 v) { return {v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte2 stdmath_byte4_yy_get(stdmath_byte4* p) { return stdmath_byte4_yy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yy_set(stdmath_byte4* p, stdmath_byte2 value) { p->y = value.x; p->y = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte2 stdmath_byte4_yz(stdmath_byte4 v) { return {v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte2 stdmath_byte4_yz_get(stdmath_byte4* p) { return stdmath_byte4_yz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yz_set(stdmath_byte4* p, stdmath_byte2 value) { p->y = value.x; p->z = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte2 stdmath_byte4_yw(stdmath_byte4 v) { return {v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte2 stdmath_byte4_yw_get(stdmath_byte4* p) { return stdmath_byte4_yw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yw_set(stdmath_byte4* p, stdmath_byte2 value) { p->y = value.x; p->w = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte2 stdmath_byte4_zx(stdmath_byte4 v) { return {v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte2 stdmath_byte4_zx_get(stdmath_byte4* p) { return stdmath_byte4_zx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zx_set(stdmath_byte4* p, stdmath_byte2 value) { p->z = value.x; p->x = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte2 stdmath_byte4_zy(stdmath_byte4 v) { return {v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte2 stdmath_byte4_zy_get(stdmath_byte4* p) { return stdmath_byte4_zy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zy_set(stdmath_byte4* p, stdmath_byte2 value) { p->z = value.x; p->y = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte2 stdmath_byte4_zz(stdmath_byte4 v) { return {v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte2 stdmath_byte4_zz_get(stdmath_byte4* p) { return stdmath_byte4_zz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zz_set(stdmath_byte4* p, stdmath_byte2 value) { p->z = value.x; p->z = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte2 stdmath_byte4_zw(stdmath_byte4 v) { return {v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte2 stdmath_byte4_zw_get(stdmath_byte4* p) { return stdmath_byte4_zw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zw_set(stdmath_byte4* p, stdmath_byte2 value) { p->z = value.x; p->w = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte2 stdmath_byte4_wx(stdmath_byte4 v) { return {v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte2 stdmath_byte4_wx_get(stdmath_byte4* p) { return stdmath_byte4_wx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wx_set(stdmath_byte4* p, stdmath_byte2 value) { p->w = value.x; p->x = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte2 stdmath_byte4_wy(stdmath_byte4 v) { return {v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte2 stdmath_byte4_wy_get(stdmath_byte4* p) { return stdmath_byte4_wy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wy_set(stdmath_byte4* p, stdmath_byte2 value) { p->w = value.x; p->y = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte2 stdmath_byte4_wz(stdmath_byte4 v) { return {v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte2 stdmath_byte4_wz_get(stdmath_byte4* p) { return stdmath_byte4_wz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wz_set(stdmath_byte4* p, stdmath_byte2 value) { p->w = value.x; p->z = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte2 stdmath_byte4_ww(stdmath_byte4 v) { return {v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte2 stdmath_byte4_ww_get(stdmath_byte4* p) { return stdmath_byte4_ww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_ww_set(stdmath_byte4* p, stdmath_byte2 value) { p->w = value.x; p->w = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_xxx(stdmath_byte4 v) { return {v.x,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_xxx_get(stdmath_byte4* p) { return stdmath_byte4_xxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xxx_set(stdmath_byte4* p, stdmath_byte3 value) { p->x = value.x; p->x = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_xxy(stdmath_byte4 v) { return {v.x,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_xxy_get(stdmath_byte4* p) { return stdmath_byte4_xxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xxy_set(stdmath_byte4* p, stdmath_byte3 value) { p->x = value.x; p->x = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_xxz(stdmath_byte4 v) { return {v.x,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_xxz_get(stdmath_byte4* p) { return stdmath_byte4_xxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xxz_set(stdmath_byte4* p, stdmath_byte3 value) { p->x = value.x; p->x = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_xxw(stdmath_byte4 v) { return {v.x,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_xxw_get(stdmath_byte4* p) { return stdmath_byte4_xxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xxw_set(stdmath_byte4* p, stdmath_byte3 value) { p->x = value.x; p->x = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_xyx(stdmath_byte4 v) { return {v.x,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_xyx_get(stdmath_byte4* p) { return stdmath_byte4_xyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xyx_set(stdmath_byte4* p, stdmath_byte3 value) { p->x = value.x; p->y = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_xyy(stdmath_byte4 v) { return {v.x,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_xyy_get(stdmath_byte4* p) { return stdmath_byte4_xyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xyy_set(stdmath_byte4* p, stdmath_byte3 value) { p->x = value.x; p->y = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_xyz(stdmath_byte4 v) { return {v.x,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_xyz_get(stdmath_byte4* p) { return stdmath_byte4_xyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xyz_set(stdmath_byte4* p, stdmath_byte3 value) { p->x = value.x; p->y = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_xyw(stdmath_byte4 v) { return {v.x,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_xyw_get(stdmath_byte4* p) { return stdmath_byte4_xyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xyw_set(stdmath_byte4* p, stdmath_byte3 value) { p->x = value.x; p->y = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_xzx(stdmath_byte4 v) { return {v.x,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_xzx_get(stdmath_byte4* p) { return stdmath_byte4_xzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xzx_set(stdmath_byte4* p, stdmath_byte3 value) { p->x = value.x; p->z = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_xzy(stdmath_byte4 v) { return {v.x,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_xzy_get(stdmath_byte4* p) { return stdmath_byte4_xzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xzy_set(stdmath_byte4* p, stdmath_byte3 value) { p->x = value.x; p->z = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_xzz(stdmath_byte4 v) { return {v.x,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_xzz_get(stdmath_byte4* p) { return stdmath_byte4_xzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xzz_set(stdmath_byte4* p, stdmath_byte3 value) { p->x = value.x; p->z = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_xzw(stdmath_byte4 v) { return {v.x,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_xzw_get(stdmath_byte4* p) { return stdmath_byte4_xzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xzw_set(stdmath_byte4* p, stdmath_byte3 value) { p->x = value.x; p->z = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_xwx(stdmath_byte4 v) { return {v.x,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_xwx_get(stdmath_byte4* p) { return stdmath_byte4_xwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xwx_set(stdmath_byte4* p, stdmath_byte3 value) { p->x = value.x; p->w = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_xwy(stdmath_byte4 v) { return {v.x,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_xwy_get(stdmath_byte4* p) { return stdmath_byte4_xwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xwy_set(stdmath_byte4* p, stdmath_byte3 value) { p->x = value.x; p->w = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_xwz(stdmath_byte4 v) { return {v.x,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_xwz_get(stdmath_byte4* p) { return stdmath_byte4_xwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xwz_set(stdmath_byte4* p, stdmath_byte3 value) { p->x = value.x; p->w = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_xww(stdmath_byte4 v) { return {v.x,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_xww_get(stdmath_byte4* p) { return stdmath_byte4_xww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xww_set(stdmath_byte4* p, stdmath_byte3 value) { p->x = value.x; p->w = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_yxx(stdmath_byte4 v) { return {v.y,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_yxx_get(stdmath_byte4* p) { return stdmath_byte4_yxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yxx_set(stdmath_byte4* p, stdmath_byte3 value) { p->y = value.x; p->x = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_yxy(stdmath_byte4 v) { return {v.y,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_yxy_get(stdmath_byte4* p) { return stdmath_byte4_yxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yxy_set(stdmath_byte4* p, stdmath_byte3 value) { p->y = value.x; p->x = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_yxz(stdmath_byte4 v) { return {v.y,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_yxz_get(stdmath_byte4* p) { return stdmath_byte4_yxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yxz_set(stdmath_byte4* p, stdmath_byte3 value) { p->y = value.x; p->x = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_yxw(stdmath_byte4 v) { return {v.y,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_yxw_get(stdmath_byte4* p) { return stdmath_byte4_yxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yxw_set(stdmath_byte4* p, stdmath_byte3 value) { p->y = value.x; p->x = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_yyx(stdmath_byte4 v) { return {v.y,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_yyx_get(stdmath_byte4* p) { return stdmath_byte4_yyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yyx_set(stdmath_byte4* p, stdmath_byte3 value) { p->y = value.x; p->y = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_yyy(stdmath_byte4 v) { return {v.y,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_yyy_get(stdmath_byte4* p) { return stdmath_byte4_yyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yyy_set(stdmath_byte4* p, stdmath_byte3 value) { p->y = value.x; p->y = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_yyz(stdmath_byte4 v) { return {v.y,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_yyz_get(stdmath_byte4* p) { return stdmath_byte4_yyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yyz_set(stdmath_byte4* p, stdmath_byte3 value) { p->y = value.x; p->y = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_yyw(stdmath_byte4 v) { return {v.y,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_yyw_get(stdmath_byte4* p) { return stdmath_byte4_yyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yyw_set(stdmath_byte4* p, stdmath_byte3 value) { p->y = value.x; p->y = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_yzx(stdmath_byte4 v) { return {v.y,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_yzx_get(stdmath_byte4* p) { return stdmath_byte4_yzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yzx_set(stdmath_byte4* p, stdmath_byte3 value) { p->y = value.x; p->z = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_yzy(stdmath_byte4 v) { return {v.y,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_yzy_get(stdmath_byte4* p) { return stdmath_byte4_yzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yzy_set(stdmath_byte4* p, stdmath_byte3 value) { p->y = value.x; p->z = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_yzz(stdmath_byte4 v) { return {v.y,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_yzz_get(stdmath_byte4* p) { return stdmath_byte4_yzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yzz_set(stdmath_byte4* p, stdmath_byte3 value) { p->y = value.x; p->z = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_yzw(stdmath_byte4 v) { return {v.y,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_yzw_get(stdmath_byte4* p) { return stdmath_byte4_yzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yzw_set(stdmath_byte4* p, stdmath_byte3 value) { p->y = value.x; p->z = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_ywx(stdmath_byte4 v) { return {v.y,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_ywx_get(stdmath_byte4* p) { return stdmath_byte4_ywx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_ywx_set(stdmath_byte4* p, stdmath_byte3 value) { p->y = value.x; p->w = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_ywy(stdmath_byte4 v) { return {v.y,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_ywy_get(stdmath_byte4* p) { return stdmath_byte4_ywy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_ywy_set(stdmath_byte4* p, stdmath_byte3 value) { p->y = value.x; p->w = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_ywz(stdmath_byte4 v) { return {v.y,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_ywz_get(stdmath_byte4* p) { return stdmath_byte4_ywz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_ywz_set(stdmath_byte4* p, stdmath_byte3 value) { p->y = value.x; p->w = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_yww(stdmath_byte4 v) { return {v.y,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_yww_get(stdmath_byte4* p) { return stdmath_byte4_yww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yww_set(stdmath_byte4* p, stdmath_byte3 value) { p->y = value.x; p->w = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_zxx(stdmath_byte4 v) { return {v.z,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_zxx_get(stdmath_byte4* p) { return stdmath_byte4_zxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zxx_set(stdmath_byte4* p, stdmath_byte3 value) { p->z = value.x; p->x = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_zxy(stdmath_byte4 v) { return {v.z,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_zxy_get(stdmath_byte4* p) { return stdmath_byte4_zxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zxy_set(stdmath_byte4* p, stdmath_byte3 value) { p->z = value.x; p->x = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_zxz(stdmath_byte4 v) { return {v.z,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_zxz_get(stdmath_byte4* p) { return stdmath_byte4_zxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zxz_set(stdmath_byte4* p, stdmath_byte3 value) { p->z = value.x; p->x = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_zxw(stdmath_byte4 v) { return {v.z,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_zxw_get(stdmath_byte4* p) { return stdmath_byte4_zxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zxw_set(stdmath_byte4* p, stdmath_byte3 value) { p->z = value.x; p->x = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_zyx(stdmath_byte4 v) { return {v.z,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_zyx_get(stdmath_byte4* p) { return stdmath_byte4_zyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zyx_set(stdmath_byte4* p, stdmath_byte3 value) { p->z = value.x; p->y = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_zyy(stdmath_byte4 v) { return {v.z,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_zyy_get(stdmath_byte4* p) { return stdmath_byte4_zyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zyy_set(stdmath_byte4* p, stdmath_byte3 value) { p->z = value.x; p->y = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_zyz(stdmath_byte4 v) { return {v.z,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_zyz_get(stdmath_byte4* p) { return stdmath_byte4_zyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zyz_set(stdmath_byte4* p, stdmath_byte3 value) { p->z = value.x; p->y = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_zyw(stdmath_byte4 v) { return {v.z,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_zyw_get(stdmath_byte4* p) { return stdmath_byte4_zyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zyw_set(stdmath_byte4* p, stdmath_byte3 value) { p->z = value.x; p->y = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_zzx(stdmath_byte4 v) { return {v.z,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_zzx_get(stdmath_byte4* p) { return stdmath_byte4_zzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zzx_set(stdmath_byte4* p, stdmath_byte3 value) { p->z = value.x; p->z = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_zzy(stdmath_byte4 v) { return {v.z,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_zzy_get(stdmath_byte4* p) { return stdmath_byte4_zzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zzy_set(stdmath_byte4* p, stdmath_byte3 value) { p->z = value.x; p->z = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_zzz(stdmath_byte4 v) { return {v.z,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_zzz_get(stdmath_byte4* p) { return stdmath_byte4_zzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zzz_set(stdmath_byte4* p, stdmath_byte3 value) { p->z = value.x; p->z = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_zzw(stdmath_byte4 v) { return {v.z,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_zzw_get(stdmath_byte4* p) { return stdmath_byte4_zzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zzw_set(stdmath_byte4* p, stdmath_byte3 value) { p->z = value.x; p->z = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_zwx(stdmath_byte4 v) { return {v.z,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_zwx_get(stdmath_byte4* p) { return stdmath_byte4_zwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zwx_set(stdmath_byte4* p, stdmath_byte3 value) { p->z = value.x; p->w = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_zwy(stdmath_byte4 v) { return {v.z,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_zwy_get(stdmath_byte4* p) { return stdmath_byte4_zwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zwy_set(stdmath_byte4* p, stdmath_byte3 value) { p->z = value.x; p->w = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_zwz(stdmath_byte4 v) { return {v.z,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_zwz_get(stdmath_byte4* p) { return stdmath_byte4_zwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zwz_set(stdmath_byte4* p, stdmath_byte3 value) { p->z = value.x; p->w = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_zww(stdmath_byte4 v) { return {v.z,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_zww_get(stdmath_byte4* p) { return stdmath_byte4_zww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zww_set(stdmath_byte4* p, stdmath_byte3 value) { p->z = value.x; p->w = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_wxx(stdmath_byte4 v) { return {v.w,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_wxx_get(stdmath_byte4* p) { return stdmath_byte4_wxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wxx_set(stdmath_byte4* p, stdmath_byte3 value) { p->w = value.x; p->x = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_wxy(stdmath_byte4 v) { return {v.w,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_wxy_get(stdmath_byte4* p) { return stdmath_byte4_wxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wxy_set(stdmath_byte4* p, stdmath_byte3 value) { p->w = value.x; p->x = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_wxz(stdmath_byte4 v) { return {v.w,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_wxz_get(stdmath_byte4* p) { return stdmath_byte4_wxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wxz_set(stdmath_byte4* p, stdmath_byte3 value) { p->w = value.x; p->x = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_wxw(stdmath_byte4 v) { return {v.w,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_wxw_get(stdmath_byte4* p) { return stdmath_byte4_wxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wxw_set(stdmath_byte4* p, stdmath_byte3 value) { p->w = value.x; p->x = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_wyx(stdmath_byte4 v) { return {v.w,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_wyx_get(stdmath_byte4* p) { return stdmath_byte4_wyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wyx_set(stdmath_byte4* p, stdmath_byte3 value) { p->w = value.x; p->y = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_wyy(stdmath_byte4 v) { return {v.w,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_wyy_get(stdmath_byte4* p) { return stdmath_byte4_wyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wyy_set(stdmath_byte4* p, stdmath_byte3 value) { p->w = value.x; p->y = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_wyz(stdmath_byte4 v) { return {v.w,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_wyz_get(stdmath_byte4* p) { return stdmath_byte4_wyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wyz_set(stdmath_byte4* p, stdmath_byte3 value) { p->w = value.x; p->y = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_wyw(stdmath_byte4 v) { return {v.w,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_wyw_get(stdmath_byte4* p) { return stdmath_byte4_wyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wyw_set(stdmath_byte4* p, stdmath_byte3 value) { p->w = value.x; p->y = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_wzx(stdmath_byte4 v) { return {v.w,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_wzx_get(stdmath_byte4* p) { return stdmath_byte4_wzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wzx_set(stdmath_byte4* p, stdmath_byte3 value) { p->w = value.x; p->z = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_wzy(stdmath_byte4 v) { return {v.w,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_wzy_get(stdmath_byte4* p) { return stdmath_byte4_wzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wzy_set(stdmath_byte4* p, stdmath_byte3 value) { p->w = value.x; p->z = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_wzz(stdmath_byte4 v) { return {v.w,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_wzz_get(stdmath_byte4* p) { return stdmath_byte4_wzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wzz_set(stdmath_byte4* p, stdmath_byte3 value) { p->w = value.x; p->z = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_wzw(stdmath_byte4 v) { return {v.w,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_wzw_get(stdmath_byte4* p) { return stdmath_byte4_wzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wzw_set(stdmath_byte4* p, stdmath_byte3 value) { p->w = value.x; p->z = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_wwx(stdmath_byte4 v) { return {v.w,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_wwx_get(stdmath_byte4* p) { return stdmath_byte4_wwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wwx_set(stdmath_byte4* p, stdmath_byte3 value) { p->w = value.x; p->w = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_wwy(stdmath_byte4 v) { return {v.w,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_wwy_get(stdmath_byte4* p) { return stdmath_byte4_wwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wwy_set(stdmath_byte4* p, stdmath_byte3 value) { p->w = value.x; p->w = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_wwz(stdmath_byte4 v) { return {v.w,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_wwz_get(stdmath_byte4* p) { return stdmath_byte4_wwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wwz_set(stdmath_byte4* p, stdmath_byte3 value) { p->w = value.x; p->w = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_www(stdmath_byte4 v) { return {v.w,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte3 stdmath_byte4_www_get(stdmath_byte4* p) { return stdmath_byte4_www(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_www_set(stdmath_byte4* p, stdmath_byte3 value) { p->w = value.x; p->w = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xxxx(stdmath_byte4 v) { return {v.x,v.x,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xxxx_get(stdmath_byte4* p) { return stdmath_byte4_xxxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xxxx_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->x = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xxxy(stdmath_byte4 v) { return {v.x,v.x,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xxxy_get(stdmath_byte4* p) { return stdmath_byte4_xxxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xxxy_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->x = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xxxz(stdmath_byte4 v) { return {v.x,v.x,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xxxz_get(stdmath_byte4* p) { return stdmath_byte4_xxxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xxxz_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->x = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xxxw(stdmath_byte4 v) { return {v.x,v.x,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xxxw_get(stdmath_byte4* p) { return stdmath_byte4_xxxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xxxw_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->x = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xxyx(stdmath_byte4 v) { return {v.x,v.x,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xxyx_get(stdmath_byte4* p) { return stdmath_byte4_xxyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xxyx_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->x = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xxyy(stdmath_byte4 v) { return {v.x,v.x,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xxyy_get(stdmath_byte4* p) { return stdmath_byte4_xxyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xxyy_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->x = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xxyz(stdmath_byte4 v) { return {v.x,v.x,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xxyz_get(stdmath_byte4* p) { return stdmath_byte4_xxyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xxyz_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->x = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xxyw(stdmath_byte4 v) { return {v.x,v.x,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xxyw_get(stdmath_byte4* p) { return stdmath_byte4_xxyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xxyw_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->x = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xxzx(stdmath_byte4 v) { return {v.x,v.x,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xxzx_get(stdmath_byte4* p) { return stdmath_byte4_xxzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xxzx_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->x = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xxzy(stdmath_byte4 v) { return {v.x,v.x,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xxzy_get(stdmath_byte4* p) { return stdmath_byte4_xxzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xxzy_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->x = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xxzz(stdmath_byte4 v) { return {v.x,v.x,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xxzz_get(stdmath_byte4* p) { return stdmath_byte4_xxzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xxzz_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->x = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xxzw(stdmath_byte4 v) { return {v.x,v.x,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xxzw_get(stdmath_byte4* p) { return stdmath_byte4_xxzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xxzw_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->x = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xxwx(stdmath_byte4 v) { return {v.x,v.x,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xxwx_get(stdmath_byte4* p) { return stdmath_byte4_xxwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xxwx_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->x = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xxwy(stdmath_byte4 v) { return {v.x,v.x,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xxwy_get(stdmath_byte4* p) { return stdmath_byte4_xxwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xxwy_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->x = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xxwz(stdmath_byte4 v) { return {v.x,v.x,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xxwz_get(stdmath_byte4* p) { return stdmath_byte4_xxwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xxwz_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->x = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xxww(stdmath_byte4 v) { return {v.x,v.x,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xxww_get(stdmath_byte4* p) { return stdmath_byte4_xxww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xxww_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->x = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xyxx(stdmath_byte4 v) { return {v.x,v.y,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xyxx_get(stdmath_byte4* p) { return stdmath_byte4_xyxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xyxx_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->y = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xyxy(stdmath_byte4 v) { return {v.x,v.y,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xyxy_get(stdmath_byte4* p) { return stdmath_byte4_xyxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xyxy_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->y = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xyxz(stdmath_byte4 v) { return {v.x,v.y,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xyxz_get(stdmath_byte4* p) { return stdmath_byte4_xyxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xyxz_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->y = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xyxw(stdmath_byte4 v) { return {v.x,v.y,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xyxw_get(stdmath_byte4* p) { return stdmath_byte4_xyxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xyxw_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->y = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xyyx(stdmath_byte4 v) { return {v.x,v.y,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xyyx_get(stdmath_byte4* p) { return stdmath_byte4_xyyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xyyx_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->y = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xyyy(stdmath_byte4 v) { return {v.x,v.y,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xyyy_get(stdmath_byte4* p) { return stdmath_byte4_xyyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xyyy_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->y = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xyyz(stdmath_byte4 v) { return {v.x,v.y,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xyyz_get(stdmath_byte4* p) { return stdmath_byte4_xyyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xyyz_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->y = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xyyw(stdmath_byte4 v) { return {v.x,v.y,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xyyw_get(stdmath_byte4* p) { return stdmath_byte4_xyyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xyyw_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->y = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xyzx(stdmath_byte4 v) { return {v.x,v.y,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xyzx_get(stdmath_byte4* p) { return stdmath_byte4_xyzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xyzx_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->y = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xyzy(stdmath_byte4 v) { return {v.x,v.y,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xyzy_get(stdmath_byte4* p) { return stdmath_byte4_xyzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xyzy_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->y = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xyzz(stdmath_byte4 v) { return {v.x,v.y,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xyzz_get(stdmath_byte4* p) { return stdmath_byte4_xyzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xyzz_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->y = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xyzw(stdmath_byte4 v) { return {v.x,v.y,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xyzw_get(stdmath_byte4* p) { return stdmath_byte4_xyzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xyzw_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->y = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xywx(stdmath_byte4 v) { return {v.x,v.y,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xywx_get(stdmath_byte4* p) { return stdmath_byte4_xywx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xywx_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->y = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xywy(stdmath_byte4 v) { return {v.x,v.y,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xywy_get(stdmath_byte4* p) { return stdmath_byte4_xywy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xywy_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->y = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xywz(stdmath_byte4 v) { return {v.x,v.y,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xywz_get(stdmath_byte4* p) { return stdmath_byte4_xywz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xywz_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->y = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xyww(stdmath_byte4 v) { return {v.x,v.y,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xyww_get(stdmath_byte4* p) { return stdmath_byte4_xyww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xyww_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->y = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xzxx(stdmath_byte4 v) { return {v.x,v.z,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xzxx_get(stdmath_byte4* p) { return stdmath_byte4_xzxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xzxx_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->z = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xzxy(stdmath_byte4 v) { return {v.x,v.z,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xzxy_get(stdmath_byte4* p) { return stdmath_byte4_xzxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xzxy_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->z = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xzxz(stdmath_byte4 v) { return {v.x,v.z,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xzxz_get(stdmath_byte4* p) { return stdmath_byte4_xzxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xzxz_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->z = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xzxw(stdmath_byte4 v) { return {v.x,v.z,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xzxw_get(stdmath_byte4* p) { return stdmath_byte4_xzxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xzxw_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->z = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xzyx(stdmath_byte4 v) { return {v.x,v.z,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xzyx_get(stdmath_byte4* p) { return stdmath_byte4_xzyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xzyx_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->z = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xzyy(stdmath_byte4 v) { return {v.x,v.z,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xzyy_get(stdmath_byte4* p) { return stdmath_byte4_xzyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xzyy_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->z = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xzyz(stdmath_byte4 v) { return {v.x,v.z,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xzyz_get(stdmath_byte4* p) { return stdmath_byte4_xzyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xzyz_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->z = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xzyw(stdmath_byte4 v) { return {v.x,v.z,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xzyw_get(stdmath_byte4* p) { return stdmath_byte4_xzyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xzyw_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->z = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xzzx(stdmath_byte4 v) { return {v.x,v.z,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xzzx_get(stdmath_byte4* p) { return stdmath_byte4_xzzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xzzx_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->z = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xzzy(stdmath_byte4 v) { return {v.x,v.z,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xzzy_get(stdmath_byte4* p) { return stdmath_byte4_xzzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xzzy_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->z = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xzzz(stdmath_byte4 v) { return {v.x,v.z,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xzzz_get(stdmath_byte4* p) { return stdmath_byte4_xzzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xzzz_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->z = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xzzw(stdmath_byte4 v) { return {v.x,v.z,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xzzw_get(stdmath_byte4* p) { return stdmath_byte4_xzzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xzzw_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->z = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xzwx(stdmath_byte4 v) { return {v.x,v.z,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xzwx_get(stdmath_byte4* p) { return stdmath_byte4_xzwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xzwx_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->z = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xzwy(stdmath_byte4 v) { return {v.x,v.z,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xzwy_get(stdmath_byte4* p) { return stdmath_byte4_xzwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xzwy_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->z = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xzwz(stdmath_byte4 v) { return {v.x,v.z,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xzwz_get(stdmath_byte4* p) { return stdmath_byte4_xzwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xzwz_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->z = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xzww(stdmath_byte4 v) { return {v.x,v.z,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xzww_get(stdmath_byte4* p) { return stdmath_byte4_xzww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xzww_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->z = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xwxx(stdmath_byte4 v) { return {v.x,v.w,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xwxx_get(stdmath_byte4* p) { return stdmath_byte4_xwxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xwxx_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->w = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xwxy(stdmath_byte4 v) { return {v.x,v.w,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xwxy_get(stdmath_byte4* p) { return stdmath_byte4_xwxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xwxy_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->w = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xwxz(stdmath_byte4 v) { return {v.x,v.w,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xwxz_get(stdmath_byte4* p) { return stdmath_byte4_xwxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xwxz_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->w = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xwxw(stdmath_byte4 v) { return {v.x,v.w,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xwxw_get(stdmath_byte4* p) { return stdmath_byte4_xwxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xwxw_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->w = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xwyx(stdmath_byte4 v) { return {v.x,v.w,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xwyx_get(stdmath_byte4* p) { return stdmath_byte4_xwyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xwyx_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->w = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xwyy(stdmath_byte4 v) { return {v.x,v.w,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xwyy_get(stdmath_byte4* p) { return stdmath_byte4_xwyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xwyy_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->w = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xwyz(stdmath_byte4 v) { return {v.x,v.w,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xwyz_get(stdmath_byte4* p) { return stdmath_byte4_xwyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xwyz_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->w = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xwyw(stdmath_byte4 v) { return {v.x,v.w,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xwyw_get(stdmath_byte4* p) { return stdmath_byte4_xwyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xwyw_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->w = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xwzx(stdmath_byte4 v) { return {v.x,v.w,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xwzx_get(stdmath_byte4* p) { return stdmath_byte4_xwzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xwzx_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->w = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xwzy(stdmath_byte4 v) { return {v.x,v.w,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xwzy_get(stdmath_byte4* p) { return stdmath_byte4_xwzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xwzy_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->w = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xwzz(stdmath_byte4 v) { return {v.x,v.w,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xwzz_get(stdmath_byte4* p) { return stdmath_byte4_xwzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xwzz_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->w = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xwzw(stdmath_byte4 v) { return {v.x,v.w,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xwzw_get(stdmath_byte4* p) { return stdmath_byte4_xwzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xwzw_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->w = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xwwx(stdmath_byte4 v) { return {v.x,v.w,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xwwx_get(stdmath_byte4* p) { return stdmath_byte4_xwwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xwwx_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->w = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xwwy(stdmath_byte4 v) { return {v.x,v.w,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xwwy_get(stdmath_byte4* p) { return stdmath_byte4_xwwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xwwy_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->w = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xwwz(stdmath_byte4 v) { return {v.x,v.w,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xwwz_get(stdmath_byte4* p) { return stdmath_byte4_xwwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xwwz_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->w = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xwww(stdmath_byte4 v) { return {v.x,v.w,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xwww_get(stdmath_byte4* p) { return stdmath_byte4_xwww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_xwww_set(stdmath_byte4* p, stdmath_byte4 value) { p->x = value.x; p->w = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yxxx(stdmath_byte4 v) { return {v.y,v.x,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yxxx_get(stdmath_byte4* p) { return stdmath_byte4_yxxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yxxx_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->x = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yxxy(stdmath_byte4 v) { return {v.y,v.x,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yxxy_get(stdmath_byte4* p) { return stdmath_byte4_yxxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yxxy_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->x = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yxxz(stdmath_byte4 v) { return {v.y,v.x,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yxxz_get(stdmath_byte4* p) { return stdmath_byte4_yxxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yxxz_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->x = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yxxw(stdmath_byte4 v) { return {v.y,v.x,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yxxw_get(stdmath_byte4* p) { return stdmath_byte4_yxxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yxxw_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->x = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yxyx(stdmath_byte4 v) { return {v.y,v.x,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yxyx_get(stdmath_byte4* p) { return stdmath_byte4_yxyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yxyx_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->x = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yxyy(stdmath_byte4 v) { return {v.y,v.x,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yxyy_get(stdmath_byte4* p) { return stdmath_byte4_yxyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yxyy_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->x = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yxyz(stdmath_byte4 v) { return {v.y,v.x,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yxyz_get(stdmath_byte4* p) { return stdmath_byte4_yxyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yxyz_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->x = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yxyw(stdmath_byte4 v) { return {v.y,v.x,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yxyw_get(stdmath_byte4* p) { return stdmath_byte4_yxyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yxyw_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->x = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yxzx(stdmath_byte4 v) { return {v.y,v.x,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yxzx_get(stdmath_byte4* p) { return stdmath_byte4_yxzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yxzx_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->x = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yxzy(stdmath_byte4 v) { return {v.y,v.x,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yxzy_get(stdmath_byte4* p) { return stdmath_byte4_yxzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yxzy_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->x = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yxzz(stdmath_byte4 v) { return {v.y,v.x,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yxzz_get(stdmath_byte4* p) { return stdmath_byte4_yxzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yxzz_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->x = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yxzw(stdmath_byte4 v) { return {v.y,v.x,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yxzw_get(stdmath_byte4* p) { return stdmath_byte4_yxzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yxzw_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->x = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yxwx(stdmath_byte4 v) { return {v.y,v.x,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yxwx_get(stdmath_byte4* p) { return stdmath_byte4_yxwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yxwx_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->x = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yxwy(stdmath_byte4 v) { return {v.y,v.x,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yxwy_get(stdmath_byte4* p) { return stdmath_byte4_yxwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yxwy_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->x = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yxwz(stdmath_byte4 v) { return {v.y,v.x,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yxwz_get(stdmath_byte4* p) { return stdmath_byte4_yxwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yxwz_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->x = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yxww(stdmath_byte4 v) { return {v.y,v.x,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yxww_get(stdmath_byte4* p) { return stdmath_byte4_yxww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yxww_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->x = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yyxx(stdmath_byte4 v) { return {v.y,v.y,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yyxx_get(stdmath_byte4* p) { return stdmath_byte4_yyxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yyxx_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->y = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yyxy(stdmath_byte4 v) { return {v.y,v.y,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yyxy_get(stdmath_byte4* p) { return stdmath_byte4_yyxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yyxy_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->y = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yyxz(stdmath_byte4 v) { return {v.y,v.y,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yyxz_get(stdmath_byte4* p) { return stdmath_byte4_yyxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yyxz_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->y = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yyxw(stdmath_byte4 v) { return {v.y,v.y,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yyxw_get(stdmath_byte4* p) { return stdmath_byte4_yyxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yyxw_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->y = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yyyx(stdmath_byte4 v) { return {v.y,v.y,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yyyx_get(stdmath_byte4* p) { return stdmath_byte4_yyyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yyyx_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->y = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yyyy(stdmath_byte4 v) { return {v.y,v.y,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yyyy_get(stdmath_byte4* p) { return stdmath_byte4_yyyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yyyy_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->y = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yyyz(stdmath_byte4 v) { return {v.y,v.y,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yyyz_get(stdmath_byte4* p) { return stdmath_byte4_yyyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yyyz_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->y = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yyyw(stdmath_byte4 v) { return {v.y,v.y,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yyyw_get(stdmath_byte4* p) { return stdmath_byte4_yyyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yyyw_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->y = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yyzx(stdmath_byte4 v) { return {v.y,v.y,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yyzx_get(stdmath_byte4* p) { return stdmath_byte4_yyzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yyzx_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->y = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yyzy(stdmath_byte4 v) { return {v.y,v.y,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yyzy_get(stdmath_byte4* p) { return stdmath_byte4_yyzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yyzy_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->y = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yyzz(stdmath_byte4 v) { return {v.y,v.y,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yyzz_get(stdmath_byte4* p) { return stdmath_byte4_yyzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yyzz_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->y = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yyzw(stdmath_byte4 v) { return {v.y,v.y,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yyzw_get(stdmath_byte4* p) { return stdmath_byte4_yyzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yyzw_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->y = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yywx(stdmath_byte4 v) { return {v.y,v.y,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yywx_get(stdmath_byte4* p) { return stdmath_byte4_yywx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yywx_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->y = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yywy(stdmath_byte4 v) { return {v.y,v.y,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yywy_get(stdmath_byte4* p) { return stdmath_byte4_yywy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yywy_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->y = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yywz(stdmath_byte4 v) { return {v.y,v.y,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yywz_get(stdmath_byte4* p) { return stdmath_byte4_yywz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yywz_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->y = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yyww(stdmath_byte4 v) { return {v.y,v.y,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yyww_get(stdmath_byte4* p) { return stdmath_byte4_yyww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yyww_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->y = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yzxx(stdmath_byte4 v) { return {v.y,v.z,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yzxx_get(stdmath_byte4* p) { return stdmath_byte4_yzxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yzxx_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->z = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yzxy(stdmath_byte4 v) { return {v.y,v.z,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yzxy_get(stdmath_byte4* p) { return stdmath_byte4_yzxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yzxy_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->z = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yzxz(stdmath_byte4 v) { return {v.y,v.z,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yzxz_get(stdmath_byte4* p) { return stdmath_byte4_yzxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yzxz_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->z = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yzxw(stdmath_byte4 v) { return {v.y,v.z,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yzxw_get(stdmath_byte4* p) { return stdmath_byte4_yzxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yzxw_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->z = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yzyx(stdmath_byte4 v) { return {v.y,v.z,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yzyx_get(stdmath_byte4* p) { return stdmath_byte4_yzyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yzyx_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->z = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yzyy(stdmath_byte4 v) { return {v.y,v.z,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yzyy_get(stdmath_byte4* p) { return stdmath_byte4_yzyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yzyy_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->z = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yzyz(stdmath_byte4 v) { return {v.y,v.z,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yzyz_get(stdmath_byte4* p) { return stdmath_byte4_yzyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yzyz_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->z = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yzyw(stdmath_byte4 v) { return {v.y,v.z,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yzyw_get(stdmath_byte4* p) { return stdmath_byte4_yzyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yzyw_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->z = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yzzx(stdmath_byte4 v) { return {v.y,v.z,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yzzx_get(stdmath_byte4* p) { return stdmath_byte4_yzzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yzzx_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->z = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yzzy(stdmath_byte4 v) { return {v.y,v.z,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yzzy_get(stdmath_byte4* p) { return stdmath_byte4_yzzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yzzy_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->z = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yzzz(stdmath_byte4 v) { return {v.y,v.z,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yzzz_get(stdmath_byte4* p) { return stdmath_byte4_yzzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yzzz_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->z = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yzzw(stdmath_byte4 v) { return {v.y,v.z,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yzzw_get(stdmath_byte4* p) { return stdmath_byte4_yzzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yzzw_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->z = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yzwx(stdmath_byte4 v) { return {v.y,v.z,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yzwx_get(stdmath_byte4* p) { return stdmath_byte4_yzwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yzwx_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->z = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yzwy(stdmath_byte4 v) { return {v.y,v.z,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yzwy_get(stdmath_byte4* p) { return stdmath_byte4_yzwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yzwy_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->z = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yzwz(stdmath_byte4 v) { return {v.y,v.z,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yzwz_get(stdmath_byte4* p) { return stdmath_byte4_yzwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yzwz_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->z = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yzww(stdmath_byte4 v) { return {v.y,v.z,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yzww_get(stdmath_byte4* p) { return stdmath_byte4_yzww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_yzww_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->z = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_ywxx(stdmath_byte4 v) { return {v.y,v.w,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_ywxx_get(stdmath_byte4* p) { return stdmath_byte4_ywxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_ywxx_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->w = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_ywxy(stdmath_byte4 v) { return {v.y,v.w,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_ywxy_get(stdmath_byte4* p) { return stdmath_byte4_ywxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_ywxy_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->w = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_ywxz(stdmath_byte4 v) { return {v.y,v.w,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_ywxz_get(stdmath_byte4* p) { return stdmath_byte4_ywxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_ywxz_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->w = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_ywxw(stdmath_byte4 v) { return {v.y,v.w,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_ywxw_get(stdmath_byte4* p) { return stdmath_byte4_ywxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_ywxw_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->w = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_ywyx(stdmath_byte4 v) { return {v.y,v.w,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_ywyx_get(stdmath_byte4* p) { return stdmath_byte4_ywyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_ywyx_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->w = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_ywyy(stdmath_byte4 v) { return {v.y,v.w,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_ywyy_get(stdmath_byte4* p) { return stdmath_byte4_ywyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_ywyy_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->w = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_ywyz(stdmath_byte4 v) { return {v.y,v.w,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_ywyz_get(stdmath_byte4* p) { return stdmath_byte4_ywyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_ywyz_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->w = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_ywyw(stdmath_byte4 v) { return {v.y,v.w,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_ywyw_get(stdmath_byte4* p) { return stdmath_byte4_ywyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_ywyw_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->w = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_ywzx(stdmath_byte4 v) { return {v.y,v.w,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_ywzx_get(stdmath_byte4* p) { return stdmath_byte4_ywzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_ywzx_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->w = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_ywzy(stdmath_byte4 v) { return {v.y,v.w,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_ywzy_get(stdmath_byte4* p) { return stdmath_byte4_ywzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_ywzy_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->w = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_ywzz(stdmath_byte4 v) { return {v.y,v.w,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_ywzz_get(stdmath_byte4* p) { return stdmath_byte4_ywzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_ywzz_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->w = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_ywzw(stdmath_byte4 v) { return {v.y,v.w,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_ywzw_get(stdmath_byte4* p) { return stdmath_byte4_ywzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_ywzw_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->w = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_ywwx(stdmath_byte4 v) { return {v.y,v.w,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_ywwx_get(stdmath_byte4* p) { return stdmath_byte4_ywwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_ywwx_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->w = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_ywwy(stdmath_byte4 v) { return {v.y,v.w,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_ywwy_get(stdmath_byte4* p) { return stdmath_byte4_ywwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_ywwy_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->w = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_ywwz(stdmath_byte4 v) { return {v.y,v.w,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_ywwz_get(stdmath_byte4* p) { return stdmath_byte4_ywwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_ywwz_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->w = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_ywww(stdmath_byte4 v) { return {v.y,v.w,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_ywww_get(stdmath_byte4* p) { return stdmath_byte4_ywww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_ywww_set(stdmath_byte4* p, stdmath_byte4 value) { p->y = value.x; p->w = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zxxx(stdmath_byte4 v) { return {v.z,v.x,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zxxx_get(stdmath_byte4* p) { return stdmath_byte4_zxxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zxxx_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->x = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zxxy(stdmath_byte4 v) { return {v.z,v.x,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zxxy_get(stdmath_byte4* p) { return stdmath_byte4_zxxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zxxy_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->x = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zxxz(stdmath_byte4 v) { return {v.z,v.x,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zxxz_get(stdmath_byte4* p) { return stdmath_byte4_zxxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zxxz_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->x = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zxxw(stdmath_byte4 v) { return {v.z,v.x,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zxxw_get(stdmath_byte4* p) { return stdmath_byte4_zxxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zxxw_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->x = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zxyx(stdmath_byte4 v) { return {v.z,v.x,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zxyx_get(stdmath_byte4* p) { return stdmath_byte4_zxyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zxyx_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->x = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zxyy(stdmath_byte4 v) { return {v.z,v.x,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zxyy_get(stdmath_byte4* p) { return stdmath_byte4_zxyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zxyy_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->x = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zxyz(stdmath_byte4 v) { return {v.z,v.x,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zxyz_get(stdmath_byte4* p) { return stdmath_byte4_zxyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zxyz_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->x = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zxyw(stdmath_byte4 v) { return {v.z,v.x,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zxyw_get(stdmath_byte4* p) { return stdmath_byte4_zxyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zxyw_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->x = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zxzx(stdmath_byte4 v) { return {v.z,v.x,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zxzx_get(stdmath_byte4* p) { return stdmath_byte4_zxzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zxzx_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->x = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zxzy(stdmath_byte4 v) { return {v.z,v.x,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zxzy_get(stdmath_byte4* p) { return stdmath_byte4_zxzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zxzy_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->x = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zxzz(stdmath_byte4 v) { return {v.z,v.x,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zxzz_get(stdmath_byte4* p) { return stdmath_byte4_zxzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zxzz_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->x = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zxzw(stdmath_byte4 v) { return {v.z,v.x,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zxzw_get(stdmath_byte4* p) { return stdmath_byte4_zxzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zxzw_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->x = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zxwx(stdmath_byte4 v) { return {v.z,v.x,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zxwx_get(stdmath_byte4* p) { return stdmath_byte4_zxwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zxwx_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->x = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zxwy(stdmath_byte4 v) { return {v.z,v.x,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zxwy_get(stdmath_byte4* p) { return stdmath_byte4_zxwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zxwy_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->x = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zxwz(stdmath_byte4 v) { return {v.z,v.x,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zxwz_get(stdmath_byte4* p) { return stdmath_byte4_zxwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zxwz_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->x = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zxww(stdmath_byte4 v) { return {v.z,v.x,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zxww_get(stdmath_byte4* p) { return stdmath_byte4_zxww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zxww_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->x = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zyxx(stdmath_byte4 v) { return {v.z,v.y,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zyxx_get(stdmath_byte4* p) { return stdmath_byte4_zyxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zyxx_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->y = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zyxy(stdmath_byte4 v) { return {v.z,v.y,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zyxy_get(stdmath_byte4* p) { return stdmath_byte4_zyxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zyxy_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->y = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zyxz(stdmath_byte4 v) { return {v.z,v.y,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zyxz_get(stdmath_byte4* p) { return stdmath_byte4_zyxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zyxz_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->y = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zyxw(stdmath_byte4 v) { return {v.z,v.y,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zyxw_get(stdmath_byte4* p) { return stdmath_byte4_zyxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zyxw_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->y = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zyyx(stdmath_byte4 v) { return {v.z,v.y,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zyyx_get(stdmath_byte4* p) { return stdmath_byte4_zyyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zyyx_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->y = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zyyy(stdmath_byte4 v) { return {v.z,v.y,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zyyy_get(stdmath_byte4* p) { return stdmath_byte4_zyyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zyyy_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->y = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zyyz(stdmath_byte4 v) { return {v.z,v.y,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zyyz_get(stdmath_byte4* p) { return stdmath_byte4_zyyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zyyz_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->y = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zyyw(stdmath_byte4 v) { return {v.z,v.y,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zyyw_get(stdmath_byte4* p) { return stdmath_byte4_zyyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zyyw_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->y = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zyzx(stdmath_byte4 v) { return {v.z,v.y,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zyzx_get(stdmath_byte4* p) { return stdmath_byte4_zyzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zyzx_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->y = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zyzy(stdmath_byte4 v) { return {v.z,v.y,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zyzy_get(stdmath_byte4* p) { return stdmath_byte4_zyzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zyzy_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->y = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zyzz(stdmath_byte4 v) { return {v.z,v.y,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zyzz_get(stdmath_byte4* p) { return stdmath_byte4_zyzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zyzz_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->y = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zyzw(stdmath_byte4 v) { return {v.z,v.y,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zyzw_get(stdmath_byte4* p) { return stdmath_byte4_zyzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zyzw_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->y = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zywx(stdmath_byte4 v) { return {v.z,v.y,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zywx_get(stdmath_byte4* p) { return stdmath_byte4_zywx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zywx_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->y = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zywy(stdmath_byte4 v) { return {v.z,v.y,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zywy_get(stdmath_byte4* p) { return stdmath_byte4_zywy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zywy_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->y = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zywz(stdmath_byte4 v) { return {v.z,v.y,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zywz_get(stdmath_byte4* p) { return stdmath_byte4_zywz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zywz_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->y = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zyww(stdmath_byte4 v) { return {v.z,v.y,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zyww_get(stdmath_byte4* p) { return stdmath_byte4_zyww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zyww_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->y = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zzxx(stdmath_byte4 v) { return {v.z,v.z,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zzxx_get(stdmath_byte4* p) { return stdmath_byte4_zzxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zzxx_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->z = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zzxy(stdmath_byte4 v) { return {v.z,v.z,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zzxy_get(stdmath_byte4* p) { return stdmath_byte4_zzxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zzxy_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->z = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zzxz(stdmath_byte4 v) { return {v.z,v.z,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zzxz_get(stdmath_byte4* p) { return stdmath_byte4_zzxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zzxz_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->z = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zzxw(stdmath_byte4 v) { return {v.z,v.z,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zzxw_get(stdmath_byte4* p) { return stdmath_byte4_zzxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zzxw_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->z = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zzyx(stdmath_byte4 v) { return {v.z,v.z,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zzyx_get(stdmath_byte4* p) { return stdmath_byte4_zzyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zzyx_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->z = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zzyy(stdmath_byte4 v) { return {v.z,v.z,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zzyy_get(stdmath_byte4* p) { return stdmath_byte4_zzyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zzyy_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->z = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zzyz(stdmath_byte4 v) { return {v.z,v.z,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zzyz_get(stdmath_byte4* p) { return stdmath_byte4_zzyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zzyz_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->z = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zzyw(stdmath_byte4 v) { return {v.z,v.z,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zzyw_get(stdmath_byte4* p) { return stdmath_byte4_zzyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zzyw_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->z = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zzzx(stdmath_byte4 v) { return {v.z,v.z,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zzzx_get(stdmath_byte4* p) { return stdmath_byte4_zzzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zzzx_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->z = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zzzy(stdmath_byte4 v) { return {v.z,v.z,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zzzy_get(stdmath_byte4* p) { return stdmath_byte4_zzzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zzzy_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->z = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zzzz(stdmath_byte4 v) { return {v.z,v.z,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zzzz_get(stdmath_byte4* p) { return stdmath_byte4_zzzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zzzz_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->z = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zzzw(stdmath_byte4 v) { return {v.z,v.z,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zzzw_get(stdmath_byte4* p) { return stdmath_byte4_zzzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zzzw_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->z = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zzwx(stdmath_byte4 v) { return {v.z,v.z,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zzwx_get(stdmath_byte4* p) { return stdmath_byte4_zzwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zzwx_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->z = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zzwy(stdmath_byte4 v) { return {v.z,v.z,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zzwy_get(stdmath_byte4* p) { return stdmath_byte4_zzwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zzwy_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->z = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zzwz(stdmath_byte4 v) { return {v.z,v.z,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zzwz_get(stdmath_byte4* p) { return stdmath_byte4_zzwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zzwz_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->z = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zzww(stdmath_byte4 v) { return {v.z,v.z,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zzww_get(stdmath_byte4* p) { return stdmath_byte4_zzww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zzww_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->z = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zwxx(stdmath_byte4 v) { return {v.z,v.w,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zwxx_get(stdmath_byte4* p) { return stdmath_byte4_zwxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zwxx_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->w = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zwxy(stdmath_byte4 v) { return {v.z,v.w,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zwxy_get(stdmath_byte4* p) { return stdmath_byte4_zwxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zwxy_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->w = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zwxz(stdmath_byte4 v) { return {v.z,v.w,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zwxz_get(stdmath_byte4* p) { return stdmath_byte4_zwxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zwxz_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->w = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zwxw(stdmath_byte4 v) { return {v.z,v.w,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zwxw_get(stdmath_byte4* p) { return stdmath_byte4_zwxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zwxw_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->w = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zwyx(stdmath_byte4 v) { return {v.z,v.w,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zwyx_get(stdmath_byte4* p) { return stdmath_byte4_zwyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zwyx_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->w = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zwyy(stdmath_byte4 v) { return {v.z,v.w,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zwyy_get(stdmath_byte4* p) { return stdmath_byte4_zwyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zwyy_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->w = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zwyz(stdmath_byte4 v) { return {v.z,v.w,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zwyz_get(stdmath_byte4* p) { return stdmath_byte4_zwyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zwyz_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->w = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zwyw(stdmath_byte4 v) { return {v.z,v.w,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zwyw_get(stdmath_byte4* p) { return stdmath_byte4_zwyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zwyw_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->w = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zwzx(stdmath_byte4 v) { return {v.z,v.w,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zwzx_get(stdmath_byte4* p) { return stdmath_byte4_zwzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zwzx_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->w = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zwzy(stdmath_byte4 v) { return {v.z,v.w,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zwzy_get(stdmath_byte4* p) { return stdmath_byte4_zwzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zwzy_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->w = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zwzz(stdmath_byte4 v) { return {v.z,v.w,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zwzz_get(stdmath_byte4* p) { return stdmath_byte4_zwzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zwzz_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->w = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zwzw(stdmath_byte4 v) { return {v.z,v.w,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zwzw_get(stdmath_byte4* p) { return stdmath_byte4_zwzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zwzw_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->w = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zwwx(stdmath_byte4 v) { return {v.z,v.w,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zwwx_get(stdmath_byte4* p) { return stdmath_byte4_zwwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zwwx_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->w = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zwwy(stdmath_byte4 v) { return {v.z,v.w,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zwwy_get(stdmath_byte4* p) { return stdmath_byte4_zwwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zwwy_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->w = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zwwz(stdmath_byte4 v) { return {v.z,v.w,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zwwz_get(stdmath_byte4* p) { return stdmath_byte4_zwwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zwwz_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->w = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zwww(stdmath_byte4 v) { return {v.z,v.w,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zwww_get(stdmath_byte4* p) { return stdmath_byte4_zwww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_zwww_set(stdmath_byte4* p, stdmath_byte4 value) { p->z = value.x; p->w = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wxxx(stdmath_byte4 v) { return {v.w,v.x,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wxxx_get(stdmath_byte4* p) { return stdmath_byte4_wxxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wxxx_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->x = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wxxy(stdmath_byte4 v) { return {v.w,v.x,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wxxy_get(stdmath_byte4* p) { return stdmath_byte4_wxxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wxxy_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->x = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wxxz(stdmath_byte4 v) { return {v.w,v.x,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wxxz_get(stdmath_byte4* p) { return stdmath_byte4_wxxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wxxz_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->x = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wxxw(stdmath_byte4 v) { return {v.w,v.x,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wxxw_get(stdmath_byte4* p) { return stdmath_byte4_wxxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wxxw_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->x = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wxyx(stdmath_byte4 v) { return {v.w,v.x,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wxyx_get(stdmath_byte4* p) { return stdmath_byte4_wxyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wxyx_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->x = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wxyy(stdmath_byte4 v) { return {v.w,v.x,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wxyy_get(stdmath_byte4* p) { return stdmath_byte4_wxyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wxyy_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->x = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wxyz(stdmath_byte4 v) { return {v.w,v.x,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wxyz_get(stdmath_byte4* p) { return stdmath_byte4_wxyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wxyz_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->x = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wxyw(stdmath_byte4 v) { return {v.w,v.x,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wxyw_get(stdmath_byte4* p) { return stdmath_byte4_wxyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wxyw_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->x = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wxzx(stdmath_byte4 v) { return {v.w,v.x,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wxzx_get(stdmath_byte4* p) { return stdmath_byte4_wxzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wxzx_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->x = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wxzy(stdmath_byte4 v) { return {v.w,v.x,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wxzy_get(stdmath_byte4* p) { return stdmath_byte4_wxzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wxzy_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->x = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wxzz(stdmath_byte4 v) { return {v.w,v.x,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wxzz_get(stdmath_byte4* p) { return stdmath_byte4_wxzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wxzz_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->x = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wxzw(stdmath_byte4 v) { return {v.w,v.x,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wxzw_get(stdmath_byte4* p) { return stdmath_byte4_wxzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wxzw_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->x = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wxwx(stdmath_byte4 v) { return {v.w,v.x,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wxwx_get(stdmath_byte4* p) { return stdmath_byte4_wxwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wxwx_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->x = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wxwy(stdmath_byte4 v) { return {v.w,v.x,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wxwy_get(stdmath_byte4* p) { return stdmath_byte4_wxwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wxwy_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->x = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wxwz(stdmath_byte4 v) { return {v.w,v.x,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wxwz_get(stdmath_byte4* p) { return stdmath_byte4_wxwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wxwz_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->x = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wxww(stdmath_byte4 v) { return {v.w,v.x,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wxww_get(stdmath_byte4* p) { return stdmath_byte4_wxww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wxww_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->x = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wyxx(stdmath_byte4 v) { return {v.w,v.y,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wyxx_get(stdmath_byte4* p) { return stdmath_byte4_wyxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wyxx_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->y = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wyxy(stdmath_byte4 v) { return {v.w,v.y,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wyxy_get(stdmath_byte4* p) { return stdmath_byte4_wyxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wyxy_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->y = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wyxz(stdmath_byte4 v) { return {v.w,v.y,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wyxz_get(stdmath_byte4* p) { return stdmath_byte4_wyxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wyxz_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->y = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wyxw(stdmath_byte4 v) { return {v.w,v.y,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wyxw_get(stdmath_byte4* p) { return stdmath_byte4_wyxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wyxw_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->y = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wyyx(stdmath_byte4 v) { return {v.w,v.y,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wyyx_get(stdmath_byte4* p) { return stdmath_byte4_wyyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wyyx_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->y = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wyyy(stdmath_byte4 v) { return {v.w,v.y,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wyyy_get(stdmath_byte4* p) { return stdmath_byte4_wyyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wyyy_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->y = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wyyz(stdmath_byte4 v) { return {v.w,v.y,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wyyz_get(stdmath_byte4* p) { return stdmath_byte4_wyyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wyyz_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->y = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wyyw(stdmath_byte4 v) { return {v.w,v.y,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wyyw_get(stdmath_byte4* p) { return stdmath_byte4_wyyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wyyw_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->y = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wyzx(stdmath_byte4 v) { return {v.w,v.y,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wyzx_get(stdmath_byte4* p) { return stdmath_byte4_wyzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wyzx_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->y = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wyzy(stdmath_byte4 v) { return {v.w,v.y,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wyzy_get(stdmath_byte4* p) { return stdmath_byte4_wyzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wyzy_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->y = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wyzz(stdmath_byte4 v) { return {v.w,v.y,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wyzz_get(stdmath_byte4* p) { return stdmath_byte4_wyzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wyzz_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->y = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wyzw(stdmath_byte4 v) { return {v.w,v.y,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wyzw_get(stdmath_byte4* p) { return stdmath_byte4_wyzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wyzw_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->y = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wywx(stdmath_byte4 v) { return {v.w,v.y,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wywx_get(stdmath_byte4* p) { return stdmath_byte4_wywx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wywx_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->y = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wywy(stdmath_byte4 v) { return {v.w,v.y,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wywy_get(stdmath_byte4* p) { return stdmath_byte4_wywy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wywy_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->y = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wywz(stdmath_byte4 v) { return {v.w,v.y,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wywz_get(stdmath_byte4* p) { return stdmath_byte4_wywz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wywz_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->y = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wyww(stdmath_byte4 v) { return {v.w,v.y,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wyww_get(stdmath_byte4* p) { return stdmath_byte4_wyww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wyww_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->y = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wzxx(stdmath_byte4 v) { return {v.w,v.z,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wzxx_get(stdmath_byte4* p) { return stdmath_byte4_wzxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wzxx_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->z = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wzxy(stdmath_byte4 v) { return {v.w,v.z,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wzxy_get(stdmath_byte4* p) { return stdmath_byte4_wzxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wzxy_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->z = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wzxz(stdmath_byte4 v) { return {v.w,v.z,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wzxz_get(stdmath_byte4* p) { return stdmath_byte4_wzxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wzxz_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->z = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wzxw(stdmath_byte4 v) { return {v.w,v.z,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wzxw_get(stdmath_byte4* p) { return stdmath_byte4_wzxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wzxw_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->z = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wzyx(stdmath_byte4 v) { return {v.w,v.z,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wzyx_get(stdmath_byte4* p) { return stdmath_byte4_wzyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wzyx_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->z = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wzyy(stdmath_byte4 v) { return {v.w,v.z,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wzyy_get(stdmath_byte4* p) { return stdmath_byte4_wzyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wzyy_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->z = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wzyz(stdmath_byte4 v) { return {v.w,v.z,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wzyz_get(stdmath_byte4* p) { return stdmath_byte4_wzyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wzyz_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->z = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wzyw(stdmath_byte4 v) { return {v.w,v.z,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wzyw_get(stdmath_byte4* p) { return stdmath_byte4_wzyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wzyw_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->z = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wzzx(stdmath_byte4 v) { return {v.w,v.z,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wzzx_get(stdmath_byte4* p) { return stdmath_byte4_wzzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wzzx_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->z = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wzzy(stdmath_byte4 v) { return {v.w,v.z,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wzzy_get(stdmath_byte4* p) { return stdmath_byte4_wzzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wzzy_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->z = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wzzz(stdmath_byte4 v) { return {v.w,v.z,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wzzz_get(stdmath_byte4* p) { return stdmath_byte4_wzzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wzzz_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->z = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wzzw(stdmath_byte4 v) { return {v.w,v.z,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wzzw_get(stdmath_byte4* p) { return stdmath_byte4_wzzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wzzw_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->z = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wzwx(stdmath_byte4 v) { return {v.w,v.z,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wzwx_get(stdmath_byte4* p) { return stdmath_byte4_wzwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wzwx_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->z = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wzwy(stdmath_byte4 v) { return {v.w,v.z,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wzwy_get(stdmath_byte4* p) { return stdmath_byte4_wzwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wzwy_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->z = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wzwz(stdmath_byte4 v) { return {v.w,v.z,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wzwz_get(stdmath_byte4* p) { return stdmath_byte4_wzwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wzwz_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->z = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wzww(stdmath_byte4 v) { return {v.w,v.z,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wzww_get(stdmath_byte4* p) { return stdmath_byte4_wzww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wzww_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->z = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wwxx(stdmath_byte4 v) { return {v.w,v.w,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wwxx_get(stdmath_byte4* p) { return stdmath_byte4_wwxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wwxx_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->w = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wwxy(stdmath_byte4 v) { return {v.w,v.w,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wwxy_get(stdmath_byte4* p) { return stdmath_byte4_wwxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wwxy_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->w = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wwxz(stdmath_byte4 v) { return {v.w,v.w,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wwxz_get(stdmath_byte4* p) { return stdmath_byte4_wwxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wwxz_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->w = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wwxw(stdmath_byte4 v) { return {v.w,v.w,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wwxw_get(stdmath_byte4* p) { return stdmath_byte4_wwxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wwxw_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->w = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wwyx(stdmath_byte4 v) { return {v.w,v.w,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wwyx_get(stdmath_byte4* p) { return stdmath_byte4_wwyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wwyx_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->w = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wwyy(stdmath_byte4 v) { return {v.w,v.w,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wwyy_get(stdmath_byte4* p) { return stdmath_byte4_wwyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wwyy_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->w = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wwyz(stdmath_byte4 v) { return {v.w,v.w,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wwyz_get(stdmath_byte4* p) { return stdmath_byte4_wwyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wwyz_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->w = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wwyw(stdmath_byte4 v) { return {v.w,v.w,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wwyw_get(stdmath_byte4* p) { return stdmath_byte4_wwyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wwyw_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->w = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wwzx(stdmath_byte4 v) { return {v.w,v.w,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wwzx_get(stdmath_byte4* p) { return stdmath_byte4_wwzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wwzx_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->w = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wwzy(stdmath_byte4 v) { return {v.w,v.w,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wwzy_get(stdmath_byte4* p) { return stdmath_byte4_wwzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wwzy_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->w = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wwzz(stdmath_byte4 v) { return {v.w,v.w,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wwzz_get(stdmath_byte4* p) { return stdmath_byte4_wwzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wwzz_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->w = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wwzw(stdmath_byte4 v) { return {v.w,v.w,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wwzw_get(stdmath_byte4* p) { return stdmath_byte4_wwzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wwzw_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->w = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wwwx(stdmath_byte4 v) { return {v.w,v.w,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wwwx_get(stdmath_byte4* p) { return stdmath_byte4_wwwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wwwx_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->w = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wwwy(stdmath_byte4 v) { return {v.w,v.w,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wwwy_get(stdmath_byte4* p) { return stdmath_byte4_wwwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wwwy_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->w = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wwwz(stdmath_byte4 v) { return {v.w,v.w,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wwwz_get(stdmath_byte4* p) { return stdmath_byte4_wwwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wwwz_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->w = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wwww(stdmath_byte4 v) { return {v.w,v.w,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wwww_get(stdmath_byte4* p) { return stdmath_byte4_wwww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte4 stdmath_byte4_wwww_set(stdmath_byte4* p, stdmath_byte4 value) { p->w = value.x; p->w = value.y; p->w = value.z; p->w = value.w; return *p; }

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

inline stdmath::byte4 c(stdmath_byte4 c) {
	return (stdmath::byte4&)c;
}
inline stdmath_byte4 c(stdmath::byte4 c) {
	return (stdmath_byte4&)c;
}

#ifdef __cplusplus
extern "C" {
#endif

stdmath_byte4 stdmath_byte4_broadcast(uint8_t all) {
	return c(stdmath::byte4((stdmath::byte4::underlying_type&)all));
}

stdmath_byte4 stdmath_byte4_add(stdmath_byte4 a, stdmath_byte4 b) {
	return c(c(a) + c(b));
}
stdmath_byte4 stdmath_byte4_subtract(stdmath_byte4 a, stdmath_byte4 b) {
	return c(c(a) - c(b));
}
stdmath_byte4 stdmath_byte4_negate(stdmath_byte4 v) {
#if !false && !false
	return c(stdmath::byte4(-(stdmath::vector<uint8_t, 4>)c(v)));
#else
	assert(false && "TODO: Why can't we use - on vector<degree/radian, N>?");
#endif
}
stdmath_byte4 stdmath_byte4_multiply(stdmath_byte4 a, stdmath_byte4 b) {
	return c(c(a) * c(b));
}
stdmath_byte4 stdmath_byte4_divide(stdmath_byte4 a, stdmath_byte4 b) {
	return c(c(a) / c(b));
}
stdmath_byte4 stdmath_byte4_scale(stdmath_byte4 v, uint8_t s) {
	return c(c(v) * (stdmath::byte4::underlying_type&)s);
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
	auto out = c(v).length_squared();
	return (uint8_t&)out;
}
uint8_t stdmath_byte4_length(stdmath_byte4 v)  {
	auto out = c(v).length();
	return (uint8_t&)out;
}
uint8_t stdmath_byte4_dot(stdmath_byte4 a, stdmath_byte4 b)  {
	auto out = dot(c(a), c(b));
	return (uint8_t&)out;
}
uint8_t stdmath_byte4_min_element(stdmath_byte4 v)  {
	auto out = c(v).min_element();
	return (uint8_t&)out;
}
uint8_t stdmath_byte4_max_element(stdmath_byte4 v)  {
	auto out = c(v).max_element();
	return (uint8_t&)out;
}

// stdmath_byte4 stdmath_byte4_elementwise_transform(stdmath_byte4 v, uint8_t(*func)(uint8_t)) {
// 	return c(c(v).elementwise_transform(func));
// }
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

#ifdef __cplusplus
} // extern "C"
#endif

#endif // STDMATH_IMPLEMENTATION

#endif // __STDMATH_uint8_t4_H__