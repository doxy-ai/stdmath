#ifndef __STDMATH_float4_H__
#define __STDMATH_float4_H__

#ifndef STDMATH_MODULE
#include <stdint.h>
#endif
#include "../maybe_export.h"

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
#include "float1.h"
#elif 4 == 3
#include "float2.h"
#include "float1.h"
#elif 4 == 4
#include "float3.h"
#include "float2.h"
#include "float1.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if 4 == 1
STDMATH_EXPORT union stdmath_float1 {
	struct {
		float x;
	};
	float data[1];
};
#elif 4 == 2
STDMATH_EXPORT union stdmath_float2 {
	struct {
		float x, y;
	};
	struct {
		float u, v;
	};
	float data[2];
};
#elif 4 == 3
STDMATH_EXPORT union stdmath_float3 {
	struct {
		float x, y, z;
	};
	struct {
		float r, g, b;
	};
	struct {
		float h, s, v;
	};
	float data[4]; // float3s are aligned as if they were float4s
};
#elif 4 == 4
STDMATH_EXPORT union stdmath_float4 {
	struct {
		float x, y, z, w;
	};
	struct {
		float r, g, b, a;
	};
	struct {
		float h, s, v;
	};
	float data[4];
};
#endif

STDMATH_EXPORT stdmath_float4 stdmath_float4_broadcast(float all);

STDMATH_EXPORT stdmath_float4 stdmath_float4_add(stdmath_float4 a, stdmath_float4 b);
STDMATH_EXPORT stdmath_float4 stdmath_float4_subtract(stdmath_float4 a, stdmath_float4 b);
STDMATH_EXPORT stdmath_float4 stdmath_float4_negate(stdmath_float4 v);
STDMATH_EXPORT stdmath_float4 stdmath_float4_multiply(stdmath_float4 a, stdmath_float4 b);
STDMATH_EXPORT stdmath_float4 stdmath_float4_divide(stdmath_float4 a, stdmath_float4 b);
STDMATH_EXPORT stdmath_float4 stdmath_float4_scale(stdmath_float4 v, float s);

#if false
STDMATH_EXPORT stdmath_float4 stdmath_float4_modulus(stdmath_float4 a, stdmath_float4 b);
STDMATH_EXPORT stdmath_float4 stdmath_float4_logical_not(stdmath_float4 v);
STDMATH_EXPORT stdmath_float4 stdmath_float4_bitwise_not(stdmath_float4 v);
STDMATH_EXPORT stdmath_float4 stdmath_float4_logical_and(stdmath_float4 a, stdmath_float4 b);
STDMATH_EXPORT stdmath_float4 stdmath_float4_bitwise_and(stdmath_float4 a, stdmath_float4 b);
STDMATH_EXPORT stdmath_float4 stdmath_float4_logical_or(stdmath_float4 a, stdmath_float4 b);
STDMATH_EXPORT stdmath_float4 stdmath_float4_bitwise_or(stdmath_float4 a, stdmath_float4 b);
STDMATH_EXPORT stdmath_float4 stdmath_float4_bitwise_xor(stdmath_float4 a, stdmath_float4 b);
STDMATH_EXPORT stdmath_float4 stdmath_float4_shift_left(stdmath_float4 a, stdmath_float4 b);
STDMATH_EXPORT stdmath_float4 stdmath_float4_shift_right(stdmath_float4 a, stdmath_float4 b);
#endif

STDMATH_EXPORT stdmath_bool4 stdmath_float4_equal_to(stdmath_float4 a, stdmath_float4 b);
STDMATH_EXPORT stdmath_bool4 stdmath_float4_not_equal_to(stdmath_float4 a, stdmath_float4 b);
STDMATH_EXPORT stdmath_bool4 stdmath_float4_less_than(stdmath_float4 a, stdmath_float4 b);
STDMATH_EXPORT stdmath_bool4 stdmath_float4_less_than_or_equal_to(stdmath_float4 a, stdmath_float4 b);
STDMATH_EXPORT stdmath_bool4 stdmath_float4_greater_than(stdmath_float4 a, stdmath_float4 b);
STDMATH_EXPORT stdmath_bool4 stdmath_float4_greater_than_or_equal_to(stdmath_float4 a, stdmath_float4 b);

STDMATH_EXPORT float stdmath_float4_length_squared(stdmath_float4 v);
STDMATH_EXPORT float stdmath_float4_length(stdmath_float4 v);
STDMATH_EXPORT float stdmath_float4_dot(stdmath_float4 a, stdmath_float4 b);
STDMATH_EXPORT float stdmath_float4_min_element(stdmath_float4 v);
STDMATH_EXPORT float stdmath_float4_max_element(stdmath_float4 v);

STDMATH_EXPORT stdmath_float4 stdmath_float4_elementwise_transform(stdmath_float4 v, float(*func)(float));
// STDMATH_EXPORT float stdmath_float4_reduce_elements(stdmath_float4 v, float initial_value, float(*reducer)(stdmath_float4, stdmath_float4));

#if 4 == 3
STDMATH_EXPORT stdmath_float3 stdmath_float3_cross(stdmath_float3 a, stdmath_float3 b);
#endif

STDMATH_EXPORT stdmath_float4 stdmath_float4_min(stdmath_float4 a, stdmath_float4 b);
STDMATH_EXPORT stdmath_float4 stdmath_float4_max(stdmath_float4 a, stdmath_float4 b);
STDMATH_EXPORT stdmath_float4 stdmath_float4_normalize(stdmath_float4 v);
STDMATH_EXPORT stdmath_float4 stdmath_float4_lerp(stdmath_float4 a, stdmath_float4 b, float t);
STDMATH_EXPORT stdmath_float4 stdmath_float4_clamp(stdmath_float4 a, stdmath_float4 min, stdmath_float4 max);
STDMATH_EXPORT stdmath_float4 stdmath_float4_reflect(stdmath_float4 a, stdmath_float4 b);
STDMATH_EXPORT stdmath_bool4 stdmath_float4_approximately_equal(stdmath_float4 a, stdmath_float4 b);

#if false
STDMATH_EXPORT bool stdmath_bool4_all_of(stdmath_bool4 v);
STDMATH_EXPORT bool stdmath_bool4_any_of(stdmath_bool4 v);
STDMATH_EXPORT bool stdmath_bool4_none_of(stdmath_bool4 v);
STDMATH_EXPORT bool stdmath_bool4_some_of(stdmath_bool4 v);
#endif

#ifndef STDMATH_NO_SWIZZLES
STDMATH_EXPORT STDMATH_INLINE stdmath_float1 stdmath_float4_x(stdmath_float4 v) { return {v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float1 stdmath_float4_x_get(stdmath_float4* p) { return stdmath_float4_x(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_x_set(stdmath_float4* p, stdmath_float1 value) { p->x = value.x; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float1 stdmath_float4_y(stdmath_float4 v) { return {v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float1 stdmath_float4_y_get(stdmath_float4* p) { return stdmath_float4_y(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_y_set(stdmath_float4* p, stdmath_float1 value) { p->y = value.x; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float1 stdmath_float4_z(stdmath_float4 v) { return {v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float1 stdmath_float4_z_get(stdmath_float4* p) { return stdmath_float4_z(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_z_set(stdmath_float4* p, stdmath_float1 value) { p->z = value.x; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float1 stdmath_float4_w(stdmath_float4 v) { return {v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float1 stdmath_float4_w_get(stdmath_float4* p) { return stdmath_float4_w(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_w_set(stdmath_float4* p, stdmath_float1 value) { p->w = value.x; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float2 stdmath_float4_xx(stdmath_float4 v) { return {v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float2 stdmath_float4_xx_get(stdmath_float4* p) { return stdmath_float4_xx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xx_set(stdmath_float4* p, stdmath_float2 value) { p->x = value.x; p->x = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float2 stdmath_float4_xy(stdmath_float4 v) { return {v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float2 stdmath_float4_xy_get(stdmath_float4* p) { return stdmath_float4_xy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xy_set(stdmath_float4* p, stdmath_float2 value) { p->x = value.x; p->y = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float2 stdmath_float4_xz(stdmath_float4 v) { return {v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float2 stdmath_float4_xz_get(stdmath_float4* p) { return stdmath_float4_xz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xz_set(stdmath_float4* p, stdmath_float2 value) { p->x = value.x; p->z = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float2 stdmath_float4_xw(stdmath_float4 v) { return {v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float2 stdmath_float4_xw_get(stdmath_float4* p) { return stdmath_float4_xw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xw_set(stdmath_float4* p, stdmath_float2 value) { p->x = value.x; p->w = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float2 stdmath_float4_yx(stdmath_float4 v) { return {v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float2 stdmath_float4_yx_get(stdmath_float4* p) { return stdmath_float4_yx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yx_set(stdmath_float4* p, stdmath_float2 value) { p->y = value.x; p->x = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float2 stdmath_float4_yy(stdmath_float4 v) { return {v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float2 stdmath_float4_yy_get(stdmath_float4* p) { return stdmath_float4_yy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yy_set(stdmath_float4* p, stdmath_float2 value) { p->y = value.x; p->y = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float2 stdmath_float4_yz(stdmath_float4 v) { return {v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float2 stdmath_float4_yz_get(stdmath_float4* p) { return stdmath_float4_yz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yz_set(stdmath_float4* p, stdmath_float2 value) { p->y = value.x; p->z = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float2 stdmath_float4_yw(stdmath_float4 v) { return {v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float2 stdmath_float4_yw_get(stdmath_float4* p) { return stdmath_float4_yw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yw_set(stdmath_float4* p, stdmath_float2 value) { p->y = value.x; p->w = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float2 stdmath_float4_zx(stdmath_float4 v) { return {v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float2 stdmath_float4_zx_get(stdmath_float4* p) { return stdmath_float4_zx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zx_set(stdmath_float4* p, stdmath_float2 value) { p->z = value.x; p->x = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float2 stdmath_float4_zy(stdmath_float4 v) { return {v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float2 stdmath_float4_zy_get(stdmath_float4* p) { return stdmath_float4_zy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zy_set(stdmath_float4* p, stdmath_float2 value) { p->z = value.x; p->y = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float2 stdmath_float4_zz(stdmath_float4 v) { return {v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float2 stdmath_float4_zz_get(stdmath_float4* p) { return stdmath_float4_zz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zz_set(stdmath_float4* p, stdmath_float2 value) { p->z = value.x; p->z = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float2 stdmath_float4_zw(stdmath_float4 v) { return {v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float2 stdmath_float4_zw_get(stdmath_float4* p) { return stdmath_float4_zw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zw_set(stdmath_float4* p, stdmath_float2 value) { p->z = value.x; p->w = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float2 stdmath_float4_wx(stdmath_float4 v) { return {v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float2 stdmath_float4_wx_get(stdmath_float4* p) { return stdmath_float4_wx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wx_set(stdmath_float4* p, stdmath_float2 value) { p->w = value.x; p->x = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float2 stdmath_float4_wy(stdmath_float4 v) { return {v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float2 stdmath_float4_wy_get(stdmath_float4* p) { return stdmath_float4_wy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wy_set(stdmath_float4* p, stdmath_float2 value) { p->w = value.x; p->y = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float2 stdmath_float4_wz(stdmath_float4 v) { return {v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float2 stdmath_float4_wz_get(stdmath_float4* p) { return stdmath_float4_wz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wz_set(stdmath_float4* p, stdmath_float2 value) { p->w = value.x; p->z = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float2 stdmath_float4_ww(stdmath_float4 v) { return {v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float2 stdmath_float4_ww_get(stdmath_float4* p) { return stdmath_float4_ww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_ww_set(stdmath_float4* p, stdmath_float2 value) { p->w = value.x; p->w = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_xxx(stdmath_float4 v) { return {v.x,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_xxx_get(stdmath_float4* p) { return stdmath_float4_xxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xxx_set(stdmath_float4* p, stdmath_float3 value) { p->x = value.x; p->x = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_xxy(stdmath_float4 v) { return {v.x,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_xxy_get(stdmath_float4* p) { return stdmath_float4_xxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xxy_set(stdmath_float4* p, stdmath_float3 value) { p->x = value.x; p->x = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_xxz(stdmath_float4 v) { return {v.x,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_xxz_get(stdmath_float4* p) { return stdmath_float4_xxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xxz_set(stdmath_float4* p, stdmath_float3 value) { p->x = value.x; p->x = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_xxw(stdmath_float4 v) { return {v.x,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_xxw_get(stdmath_float4* p) { return stdmath_float4_xxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xxw_set(stdmath_float4* p, stdmath_float3 value) { p->x = value.x; p->x = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_xyx(stdmath_float4 v) { return {v.x,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_xyx_get(stdmath_float4* p) { return stdmath_float4_xyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xyx_set(stdmath_float4* p, stdmath_float3 value) { p->x = value.x; p->y = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_xyy(stdmath_float4 v) { return {v.x,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_xyy_get(stdmath_float4* p) { return stdmath_float4_xyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xyy_set(stdmath_float4* p, stdmath_float3 value) { p->x = value.x; p->y = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_xyz(stdmath_float4 v) { return {v.x,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_xyz_get(stdmath_float4* p) { return stdmath_float4_xyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xyz_set(stdmath_float4* p, stdmath_float3 value) { p->x = value.x; p->y = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_xyw(stdmath_float4 v) { return {v.x,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_xyw_get(stdmath_float4* p) { return stdmath_float4_xyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xyw_set(stdmath_float4* p, stdmath_float3 value) { p->x = value.x; p->y = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_xzx(stdmath_float4 v) { return {v.x,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_xzx_get(stdmath_float4* p) { return stdmath_float4_xzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xzx_set(stdmath_float4* p, stdmath_float3 value) { p->x = value.x; p->z = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_xzy(stdmath_float4 v) { return {v.x,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_xzy_get(stdmath_float4* p) { return stdmath_float4_xzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xzy_set(stdmath_float4* p, stdmath_float3 value) { p->x = value.x; p->z = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_xzz(stdmath_float4 v) { return {v.x,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_xzz_get(stdmath_float4* p) { return stdmath_float4_xzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xzz_set(stdmath_float4* p, stdmath_float3 value) { p->x = value.x; p->z = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_xzw(stdmath_float4 v) { return {v.x,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_xzw_get(stdmath_float4* p) { return stdmath_float4_xzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xzw_set(stdmath_float4* p, stdmath_float3 value) { p->x = value.x; p->z = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_xwx(stdmath_float4 v) { return {v.x,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_xwx_get(stdmath_float4* p) { return stdmath_float4_xwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xwx_set(stdmath_float4* p, stdmath_float3 value) { p->x = value.x; p->w = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_xwy(stdmath_float4 v) { return {v.x,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_xwy_get(stdmath_float4* p) { return stdmath_float4_xwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xwy_set(stdmath_float4* p, stdmath_float3 value) { p->x = value.x; p->w = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_xwz(stdmath_float4 v) { return {v.x,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_xwz_get(stdmath_float4* p) { return stdmath_float4_xwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xwz_set(stdmath_float4* p, stdmath_float3 value) { p->x = value.x; p->w = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_xww(stdmath_float4 v) { return {v.x,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_xww_get(stdmath_float4* p) { return stdmath_float4_xww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xww_set(stdmath_float4* p, stdmath_float3 value) { p->x = value.x; p->w = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_yxx(stdmath_float4 v) { return {v.y,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_yxx_get(stdmath_float4* p) { return stdmath_float4_yxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yxx_set(stdmath_float4* p, stdmath_float3 value) { p->y = value.x; p->x = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_yxy(stdmath_float4 v) { return {v.y,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_yxy_get(stdmath_float4* p) { return stdmath_float4_yxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yxy_set(stdmath_float4* p, stdmath_float3 value) { p->y = value.x; p->x = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_yxz(stdmath_float4 v) { return {v.y,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_yxz_get(stdmath_float4* p) { return stdmath_float4_yxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yxz_set(stdmath_float4* p, stdmath_float3 value) { p->y = value.x; p->x = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_yxw(stdmath_float4 v) { return {v.y,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_yxw_get(stdmath_float4* p) { return stdmath_float4_yxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yxw_set(stdmath_float4* p, stdmath_float3 value) { p->y = value.x; p->x = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_yyx(stdmath_float4 v) { return {v.y,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_yyx_get(stdmath_float4* p) { return stdmath_float4_yyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yyx_set(stdmath_float4* p, stdmath_float3 value) { p->y = value.x; p->y = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_yyy(stdmath_float4 v) { return {v.y,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_yyy_get(stdmath_float4* p) { return stdmath_float4_yyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yyy_set(stdmath_float4* p, stdmath_float3 value) { p->y = value.x; p->y = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_yyz(stdmath_float4 v) { return {v.y,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_yyz_get(stdmath_float4* p) { return stdmath_float4_yyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yyz_set(stdmath_float4* p, stdmath_float3 value) { p->y = value.x; p->y = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_yyw(stdmath_float4 v) { return {v.y,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_yyw_get(stdmath_float4* p) { return stdmath_float4_yyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yyw_set(stdmath_float4* p, stdmath_float3 value) { p->y = value.x; p->y = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_yzx(stdmath_float4 v) { return {v.y,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_yzx_get(stdmath_float4* p) { return stdmath_float4_yzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yzx_set(stdmath_float4* p, stdmath_float3 value) { p->y = value.x; p->z = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_yzy(stdmath_float4 v) { return {v.y,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_yzy_get(stdmath_float4* p) { return stdmath_float4_yzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yzy_set(stdmath_float4* p, stdmath_float3 value) { p->y = value.x; p->z = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_yzz(stdmath_float4 v) { return {v.y,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_yzz_get(stdmath_float4* p) { return stdmath_float4_yzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yzz_set(stdmath_float4* p, stdmath_float3 value) { p->y = value.x; p->z = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_yzw(stdmath_float4 v) { return {v.y,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_yzw_get(stdmath_float4* p) { return stdmath_float4_yzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yzw_set(stdmath_float4* p, stdmath_float3 value) { p->y = value.x; p->z = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_ywx(stdmath_float4 v) { return {v.y,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_ywx_get(stdmath_float4* p) { return stdmath_float4_ywx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_ywx_set(stdmath_float4* p, stdmath_float3 value) { p->y = value.x; p->w = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_ywy(stdmath_float4 v) { return {v.y,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_ywy_get(stdmath_float4* p) { return stdmath_float4_ywy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_ywy_set(stdmath_float4* p, stdmath_float3 value) { p->y = value.x; p->w = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_ywz(stdmath_float4 v) { return {v.y,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_ywz_get(stdmath_float4* p) { return stdmath_float4_ywz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_ywz_set(stdmath_float4* p, stdmath_float3 value) { p->y = value.x; p->w = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_yww(stdmath_float4 v) { return {v.y,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_yww_get(stdmath_float4* p) { return stdmath_float4_yww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yww_set(stdmath_float4* p, stdmath_float3 value) { p->y = value.x; p->w = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_zxx(stdmath_float4 v) { return {v.z,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_zxx_get(stdmath_float4* p) { return stdmath_float4_zxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zxx_set(stdmath_float4* p, stdmath_float3 value) { p->z = value.x; p->x = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_zxy(stdmath_float4 v) { return {v.z,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_zxy_get(stdmath_float4* p) { return stdmath_float4_zxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zxy_set(stdmath_float4* p, stdmath_float3 value) { p->z = value.x; p->x = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_zxz(stdmath_float4 v) { return {v.z,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_zxz_get(stdmath_float4* p) { return stdmath_float4_zxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zxz_set(stdmath_float4* p, stdmath_float3 value) { p->z = value.x; p->x = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_zxw(stdmath_float4 v) { return {v.z,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_zxw_get(stdmath_float4* p) { return stdmath_float4_zxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zxw_set(stdmath_float4* p, stdmath_float3 value) { p->z = value.x; p->x = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_zyx(stdmath_float4 v) { return {v.z,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_zyx_get(stdmath_float4* p) { return stdmath_float4_zyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zyx_set(stdmath_float4* p, stdmath_float3 value) { p->z = value.x; p->y = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_zyy(stdmath_float4 v) { return {v.z,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_zyy_get(stdmath_float4* p) { return stdmath_float4_zyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zyy_set(stdmath_float4* p, stdmath_float3 value) { p->z = value.x; p->y = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_zyz(stdmath_float4 v) { return {v.z,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_zyz_get(stdmath_float4* p) { return stdmath_float4_zyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zyz_set(stdmath_float4* p, stdmath_float3 value) { p->z = value.x; p->y = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_zyw(stdmath_float4 v) { return {v.z,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_zyw_get(stdmath_float4* p) { return stdmath_float4_zyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zyw_set(stdmath_float4* p, stdmath_float3 value) { p->z = value.x; p->y = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_zzx(stdmath_float4 v) { return {v.z,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_zzx_get(stdmath_float4* p) { return stdmath_float4_zzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zzx_set(stdmath_float4* p, stdmath_float3 value) { p->z = value.x; p->z = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_zzy(stdmath_float4 v) { return {v.z,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_zzy_get(stdmath_float4* p) { return stdmath_float4_zzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zzy_set(stdmath_float4* p, stdmath_float3 value) { p->z = value.x; p->z = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_zzz(stdmath_float4 v) { return {v.z,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_zzz_get(stdmath_float4* p) { return stdmath_float4_zzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zzz_set(stdmath_float4* p, stdmath_float3 value) { p->z = value.x; p->z = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_zzw(stdmath_float4 v) { return {v.z,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_zzw_get(stdmath_float4* p) { return stdmath_float4_zzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zzw_set(stdmath_float4* p, stdmath_float3 value) { p->z = value.x; p->z = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_zwx(stdmath_float4 v) { return {v.z,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_zwx_get(stdmath_float4* p) { return stdmath_float4_zwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zwx_set(stdmath_float4* p, stdmath_float3 value) { p->z = value.x; p->w = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_zwy(stdmath_float4 v) { return {v.z,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_zwy_get(stdmath_float4* p) { return stdmath_float4_zwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zwy_set(stdmath_float4* p, stdmath_float3 value) { p->z = value.x; p->w = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_zwz(stdmath_float4 v) { return {v.z,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_zwz_get(stdmath_float4* p) { return stdmath_float4_zwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zwz_set(stdmath_float4* p, stdmath_float3 value) { p->z = value.x; p->w = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_zww(stdmath_float4 v) { return {v.z,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_zww_get(stdmath_float4* p) { return stdmath_float4_zww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zww_set(stdmath_float4* p, stdmath_float3 value) { p->z = value.x; p->w = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_wxx(stdmath_float4 v) { return {v.w,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_wxx_get(stdmath_float4* p) { return stdmath_float4_wxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wxx_set(stdmath_float4* p, stdmath_float3 value) { p->w = value.x; p->x = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_wxy(stdmath_float4 v) { return {v.w,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_wxy_get(stdmath_float4* p) { return stdmath_float4_wxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wxy_set(stdmath_float4* p, stdmath_float3 value) { p->w = value.x; p->x = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_wxz(stdmath_float4 v) { return {v.w,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_wxz_get(stdmath_float4* p) { return stdmath_float4_wxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wxz_set(stdmath_float4* p, stdmath_float3 value) { p->w = value.x; p->x = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_wxw(stdmath_float4 v) { return {v.w,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_wxw_get(stdmath_float4* p) { return stdmath_float4_wxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wxw_set(stdmath_float4* p, stdmath_float3 value) { p->w = value.x; p->x = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_wyx(stdmath_float4 v) { return {v.w,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_wyx_get(stdmath_float4* p) { return stdmath_float4_wyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wyx_set(stdmath_float4* p, stdmath_float3 value) { p->w = value.x; p->y = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_wyy(stdmath_float4 v) { return {v.w,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_wyy_get(stdmath_float4* p) { return stdmath_float4_wyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wyy_set(stdmath_float4* p, stdmath_float3 value) { p->w = value.x; p->y = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_wyz(stdmath_float4 v) { return {v.w,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_wyz_get(stdmath_float4* p) { return stdmath_float4_wyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wyz_set(stdmath_float4* p, stdmath_float3 value) { p->w = value.x; p->y = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_wyw(stdmath_float4 v) { return {v.w,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_wyw_get(stdmath_float4* p) { return stdmath_float4_wyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wyw_set(stdmath_float4* p, stdmath_float3 value) { p->w = value.x; p->y = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_wzx(stdmath_float4 v) { return {v.w,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_wzx_get(stdmath_float4* p) { return stdmath_float4_wzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wzx_set(stdmath_float4* p, stdmath_float3 value) { p->w = value.x; p->z = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_wzy(stdmath_float4 v) { return {v.w,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_wzy_get(stdmath_float4* p) { return stdmath_float4_wzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wzy_set(stdmath_float4* p, stdmath_float3 value) { p->w = value.x; p->z = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_wzz(stdmath_float4 v) { return {v.w,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_wzz_get(stdmath_float4* p) { return stdmath_float4_wzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wzz_set(stdmath_float4* p, stdmath_float3 value) { p->w = value.x; p->z = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_wzw(stdmath_float4 v) { return {v.w,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_wzw_get(stdmath_float4* p) { return stdmath_float4_wzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wzw_set(stdmath_float4* p, stdmath_float3 value) { p->w = value.x; p->z = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_wwx(stdmath_float4 v) { return {v.w,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_wwx_get(stdmath_float4* p) { return stdmath_float4_wwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wwx_set(stdmath_float4* p, stdmath_float3 value) { p->w = value.x; p->w = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_wwy(stdmath_float4 v) { return {v.w,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_wwy_get(stdmath_float4* p) { return stdmath_float4_wwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wwy_set(stdmath_float4* p, stdmath_float3 value) { p->w = value.x; p->w = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_wwz(stdmath_float4 v) { return {v.w,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_wwz_get(stdmath_float4* p) { return stdmath_float4_wwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wwz_set(stdmath_float4* p, stdmath_float3 value) { p->w = value.x; p->w = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_www(stdmath_float4 v) { return {v.w,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float3 stdmath_float4_www_get(stdmath_float4* p) { return stdmath_float4_www(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_www_set(stdmath_float4* p, stdmath_float3 value) { p->w = value.x; p->w = value.y; p->w = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xxxx(stdmath_float4 v) { return {v.x,v.x,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xxxx_get(stdmath_float4* p) { return stdmath_float4_xxxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xxxx_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->x = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xxxy(stdmath_float4 v) { return {v.x,v.x,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xxxy_get(stdmath_float4* p) { return stdmath_float4_xxxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xxxy_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->x = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xxxz(stdmath_float4 v) { return {v.x,v.x,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xxxz_get(stdmath_float4* p) { return stdmath_float4_xxxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xxxz_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->x = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xxxw(stdmath_float4 v) { return {v.x,v.x,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xxxw_get(stdmath_float4* p) { return stdmath_float4_xxxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xxxw_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->x = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xxyx(stdmath_float4 v) { return {v.x,v.x,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xxyx_get(stdmath_float4* p) { return stdmath_float4_xxyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xxyx_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->x = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xxyy(stdmath_float4 v) { return {v.x,v.x,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xxyy_get(stdmath_float4* p) { return stdmath_float4_xxyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xxyy_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->x = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xxyz(stdmath_float4 v) { return {v.x,v.x,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xxyz_get(stdmath_float4* p) { return stdmath_float4_xxyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xxyz_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->x = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xxyw(stdmath_float4 v) { return {v.x,v.x,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xxyw_get(stdmath_float4* p) { return stdmath_float4_xxyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xxyw_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->x = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xxzx(stdmath_float4 v) { return {v.x,v.x,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xxzx_get(stdmath_float4* p) { return stdmath_float4_xxzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xxzx_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->x = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xxzy(stdmath_float4 v) { return {v.x,v.x,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xxzy_get(stdmath_float4* p) { return stdmath_float4_xxzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xxzy_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->x = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xxzz(stdmath_float4 v) { return {v.x,v.x,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xxzz_get(stdmath_float4* p) { return stdmath_float4_xxzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xxzz_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->x = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xxzw(stdmath_float4 v) { return {v.x,v.x,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xxzw_get(stdmath_float4* p) { return stdmath_float4_xxzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xxzw_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->x = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xxwx(stdmath_float4 v) { return {v.x,v.x,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xxwx_get(stdmath_float4* p) { return stdmath_float4_xxwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xxwx_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->x = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xxwy(stdmath_float4 v) { return {v.x,v.x,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xxwy_get(stdmath_float4* p) { return stdmath_float4_xxwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xxwy_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->x = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xxwz(stdmath_float4 v) { return {v.x,v.x,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xxwz_get(stdmath_float4* p) { return stdmath_float4_xxwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xxwz_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->x = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xxww(stdmath_float4 v) { return {v.x,v.x,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xxww_get(stdmath_float4* p) { return stdmath_float4_xxww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xxww_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->x = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xyxx(stdmath_float4 v) { return {v.x,v.y,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xyxx_get(stdmath_float4* p) { return stdmath_float4_xyxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xyxx_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->y = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xyxy(stdmath_float4 v) { return {v.x,v.y,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xyxy_get(stdmath_float4* p) { return stdmath_float4_xyxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xyxy_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->y = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xyxz(stdmath_float4 v) { return {v.x,v.y,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xyxz_get(stdmath_float4* p) { return stdmath_float4_xyxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xyxz_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->y = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xyxw(stdmath_float4 v) { return {v.x,v.y,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xyxw_get(stdmath_float4* p) { return stdmath_float4_xyxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xyxw_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->y = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xyyx(stdmath_float4 v) { return {v.x,v.y,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xyyx_get(stdmath_float4* p) { return stdmath_float4_xyyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xyyx_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->y = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xyyy(stdmath_float4 v) { return {v.x,v.y,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xyyy_get(stdmath_float4* p) { return stdmath_float4_xyyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xyyy_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->y = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xyyz(stdmath_float4 v) { return {v.x,v.y,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xyyz_get(stdmath_float4* p) { return stdmath_float4_xyyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xyyz_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->y = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xyyw(stdmath_float4 v) { return {v.x,v.y,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xyyw_get(stdmath_float4* p) { return stdmath_float4_xyyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xyyw_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->y = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xyzx(stdmath_float4 v) { return {v.x,v.y,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xyzx_get(stdmath_float4* p) { return stdmath_float4_xyzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xyzx_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->y = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xyzy(stdmath_float4 v) { return {v.x,v.y,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xyzy_get(stdmath_float4* p) { return stdmath_float4_xyzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xyzy_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->y = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xyzz(stdmath_float4 v) { return {v.x,v.y,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xyzz_get(stdmath_float4* p) { return stdmath_float4_xyzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xyzz_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->y = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xyzw(stdmath_float4 v) { return {v.x,v.y,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xyzw_get(stdmath_float4* p) { return stdmath_float4_xyzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xyzw_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->y = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xywx(stdmath_float4 v) { return {v.x,v.y,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xywx_get(stdmath_float4* p) { return stdmath_float4_xywx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xywx_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->y = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xywy(stdmath_float4 v) { return {v.x,v.y,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xywy_get(stdmath_float4* p) { return stdmath_float4_xywy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xywy_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->y = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xywz(stdmath_float4 v) { return {v.x,v.y,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xywz_get(stdmath_float4* p) { return stdmath_float4_xywz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xywz_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->y = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xyww(stdmath_float4 v) { return {v.x,v.y,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xyww_get(stdmath_float4* p) { return stdmath_float4_xyww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xyww_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->y = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xzxx(stdmath_float4 v) { return {v.x,v.z,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xzxx_get(stdmath_float4* p) { return stdmath_float4_xzxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xzxx_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->z = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xzxy(stdmath_float4 v) { return {v.x,v.z,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xzxy_get(stdmath_float4* p) { return stdmath_float4_xzxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xzxy_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->z = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xzxz(stdmath_float4 v) { return {v.x,v.z,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xzxz_get(stdmath_float4* p) { return stdmath_float4_xzxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xzxz_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->z = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xzxw(stdmath_float4 v) { return {v.x,v.z,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xzxw_get(stdmath_float4* p) { return stdmath_float4_xzxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xzxw_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->z = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xzyx(stdmath_float4 v) { return {v.x,v.z,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xzyx_get(stdmath_float4* p) { return stdmath_float4_xzyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xzyx_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->z = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xzyy(stdmath_float4 v) { return {v.x,v.z,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xzyy_get(stdmath_float4* p) { return stdmath_float4_xzyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xzyy_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->z = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xzyz(stdmath_float4 v) { return {v.x,v.z,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xzyz_get(stdmath_float4* p) { return stdmath_float4_xzyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xzyz_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->z = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xzyw(stdmath_float4 v) { return {v.x,v.z,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xzyw_get(stdmath_float4* p) { return stdmath_float4_xzyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xzyw_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->z = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xzzx(stdmath_float4 v) { return {v.x,v.z,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xzzx_get(stdmath_float4* p) { return stdmath_float4_xzzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xzzx_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->z = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xzzy(stdmath_float4 v) { return {v.x,v.z,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xzzy_get(stdmath_float4* p) { return stdmath_float4_xzzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xzzy_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->z = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xzzz(stdmath_float4 v) { return {v.x,v.z,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xzzz_get(stdmath_float4* p) { return stdmath_float4_xzzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xzzz_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->z = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xzzw(stdmath_float4 v) { return {v.x,v.z,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xzzw_get(stdmath_float4* p) { return stdmath_float4_xzzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xzzw_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->z = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xzwx(stdmath_float4 v) { return {v.x,v.z,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xzwx_get(stdmath_float4* p) { return stdmath_float4_xzwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xzwx_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->z = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xzwy(stdmath_float4 v) { return {v.x,v.z,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xzwy_get(stdmath_float4* p) { return stdmath_float4_xzwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xzwy_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->z = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xzwz(stdmath_float4 v) { return {v.x,v.z,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xzwz_get(stdmath_float4* p) { return stdmath_float4_xzwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xzwz_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->z = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xzww(stdmath_float4 v) { return {v.x,v.z,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xzww_get(stdmath_float4* p) { return stdmath_float4_xzww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xzww_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->z = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xwxx(stdmath_float4 v) { return {v.x,v.w,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xwxx_get(stdmath_float4* p) { return stdmath_float4_xwxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xwxx_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->w = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xwxy(stdmath_float4 v) { return {v.x,v.w,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xwxy_get(stdmath_float4* p) { return stdmath_float4_xwxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xwxy_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->w = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xwxz(stdmath_float4 v) { return {v.x,v.w,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xwxz_get(stdmath_float4* p) { return stdmath_float4_xwxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xwxz_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->w = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xwxw(stdmath_float4 v) { return {v.x,v.w,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xwxw_get(stdmath_float4* p) { return stdmath_float4_xwxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xwxw_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->w = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xwyx(stdmath_float4 v) { return {v.x,v.w,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xwyx_get(stdmath_float4* p) { return stdmath_float4_xwyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xwyx_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->w = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xwyy(stdmath_float4 v) { return {v.x,v.w,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xwyy_get(stdmath_float4* p) { return stdmath_float4_xwyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xwyy_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->w = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xwyz(stdmath_float4 v) { return {v.x,v.w,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xwyz_get(stdmath_float4* p) { return stdmath_float4_xwyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xwyz_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->w = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xwyw(stdmath_float4 v) { return {v.x,v.w,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xwyw_get(stdmath_float4* p) { return stdmath_float4_xwyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xwyw_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->w = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xwzx(stdmath_float4 v) { return {v.x,v.w,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xwzx_get(stdmath_float4* p) { return stdmath_float4_xwzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xwzx_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->w = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xwzy(stdmath_float4 v) { return {v.x,v.w,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xwzy_get(stdmath_float4* p) { return stdmath_float4_xwzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xwzy_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->w = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xwzz(stdmath_float4 v) { return {v.x,v.w,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xwzz_get(stdmath_float4* p) { return stdmath_float4_xwzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xwzz_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->w = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xwzw(stdmath_float4 v) { return {v.x,v.w,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xwzw_get(stdmath_float4* p) { return stdmath_float4_xwzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xwzw_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->w = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xwwx(stdmath_float4 v) { return {v.x,v.w,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xwwx_get(stdmath_float4* p) { return stdmath_float4_xwwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xwwx_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->w = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xwwy(stdmath_float4 v) { return {v.x,v.w,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xwwy_get(stdmath_float4* p) { return stdmath_float4_xwwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xwwy_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->w = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xwwz(stdmath_float4 v) { return {v.x,v.w,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xwwz_get(stdmath_float4* p) { return stdmath_float4_xwwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xwwz_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->w = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xwww(stdmath_float4 v) { return {v.x,v.w,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xwww_get(stdmath_float4* p) { return stdmath_float4_xwww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_xwww_set(stdmath_float4* p, stdmath_float4 value) { p->x = value.x; p->w = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yxxx(stdmath_float4 v) { return {v.y,v.x,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yxxx_get(stdmath_float4* p) { return stdmath_float4_yxxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yxxx_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->x = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yxxy(stdmath_float4 v) { return {v.y,v.x,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yxxy_get(stdmath_float4* p) { return stdmath_float4_yxxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yxxy_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->x = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yxxz(stdmath_float4 v) { return {v.y,v.x,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yxxz_get(stdmath_float4* p) { return stdmath_float4_yxxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yxxz_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->x = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yxxw(stdmath_float4 v) { return {v.y,v.x,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yxxw_get(stdmath_float4* p) { return stdmath_float4_yxxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yxxw_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->x = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yxyx(stdmath_float4 v) { return {v.y,v.x,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yxyx_get(stdmath_float4* p) { return stdmath_float4_yxyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yxyx_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->x = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yxyy(stdmath_float4 v) { return {v.y,v.x,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yxyy_get(stdmath_float4* p) { return stdmath_float4_yxyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yxyy_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->x = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yxyz(stdmath_float4 v) { return {v.y,v.x,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yxyz_get(stdmath_float4* p) { return stdmath_float4_yxyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yxyz_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->x = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yxyw(stdmath_float4 v) { return {v.y,v.x,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yxyw_get(stdmath_float4* p) { return stdmath_float4_yxyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yxyw_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->x = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yxzx(stdmath_float4 v) { return {v.y,v.x,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yxzx_get(stdmath_float4* p) { return stdmath_float4_yxzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yxzx_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->x = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yxzy(stdmath_float4 v) { return {v.y,v.x,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yxzy_get(stdmath_float4* p) { return stdmath_float4_yxzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yxzy_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->x = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yxzz(stdmath_float4 v) { return {v.y,v.x,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yxzz_get(stdmath_float4* p) { return stdmath_float4_yxzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yxzz_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->x = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yxzw(stdmath_float4 v) { return {v.y,v.x,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yxzw_get(stdmath_float4* p) { return stdmath_float4_yxzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yxzw_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->x = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yxwx(stdmath_float4 v) { return {v.y,v.x,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yxwx_get(stdmath_float4* p) { return stdmath_float4_yxwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yxwx_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->x = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yxwy(stdmath_float4 v) { return {v.y,v.x,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yxwy_get(stdmath_float4* p) { return stdmath_float4_yxwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yxwy_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->x = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yxwz(stdmath_float4 v) { return {v.y,v.x,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yxwz_get(stdmath_float4* p) { return stdmath_float4_yxwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yxwz_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->x = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yxww(stdmath_float4 v) { return {v.y,v.x,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yxww_get(stdmath_float4* p) { return stdmath_float4_yxww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yxww_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->x = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yyxx(stdmath_float4 v) { return {v.y,v.y,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yyxx_get(stdmath_float4* p) { return stdmath_float4_yyxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yyxx_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->y = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yyxy(stdmath_float4 v) { return {v.y,v.y,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yyxy_get(stdmath_float4* p) { return stdmath_float4_yyxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yyxy_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->y = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yyxz(stdmath_float4 v) { return {v.y,v.y,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yyxz_get(stdmath_float4* p) { return stdmath_float4_yyxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yyxz_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->y = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yyxw(stdmath_float4 v) { return {v.y,v.y,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yyxw_get(stdmath_float4* p) { return stdmath_float4_yyxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yyxw_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->y = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yyyx(stdmath_float4 v) { return {v.y,v.y,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yyyx_get(stdmath_float4* p) { return stdmath_float4_yyyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yyyx_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->y = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yyyy(stdmath_float4 v) { return {v.y,v.y,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yyyy_get(stdmath_float4* p) { return stdmath_float4_yyyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yyyy_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->y = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yyyz(stdmath_float4 v) { return {v.y,v.y,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yyyz_get(stdmath_float4* p) { return stdmath_float4_yyyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yyyz_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->y = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yyyw(stdmath_float4 v) { return {v.y,v.y,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yyyw_get(stdmath_float4* p) { return stdmath_float4_yyyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yyyw_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->y = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yyzx(stdmath_float4 v) { return {v.y,v.y,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yyzx_get(stdmath_float4* p) { return stdmath_float4_yyzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yyzx_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->y = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yyzy(stdmath_float4 v) { return {v.y,v.y,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yyzy_get(stdmath_float4* p) { return stdmath_float4_yyzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yyzy_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->y = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yyzz(stdmath_float4 v) { return {v.y,v.y,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yyzz_get(stdmath_float4* p) { return stdmath_float4_yyzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yyzz_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->y = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yyzw(stdmath_float4 v) { return {v.y,v.y,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yyzw_get(stdmath_float4* p) { return stdmath_float4_yyzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yyzw_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->y = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yywx(stdmath_float4 v) { return {v.y,v.y,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yywx_get(stdmath_float4* p) { return stdmath_float4_yywx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yywx_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->y = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yywy(stdmath_float4 v) { return {v.y,v.y,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yywy_get(stdmath_float4* p) { return stdmath_float4_yywy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yywy_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->y = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yywz(stdmath_float4 v) { return {v.y,v.y,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yywz_get(stdmath_float4* p) { return stdmath_float4_yywz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yywz_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->y = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yyww(stdmath_float4 v) { return {v.y,v.y,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yyww_get(stdmath_float4* p) { return stdmath_float4_yyww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yyww_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->y = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yzxx(stdmath_float4 v) { return {v.y,v.z,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yzxx_get(stdmath_float4* p) { return stdmath_float4_yzxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yzxx_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->z = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yzxy(stdmath_float4 v) { return {v.y,v.z,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yzxy_get(stdmath_float4* p) { return stdmath_float4_yzxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yzxy_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->z = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yzxz(stdmath_float4 v) { return {v.y,v.z,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yzxz_get(stdmath_float4* p) { return stdmath_float4_yzxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yzxz_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->z = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yzxw(stdmath_float4 v) { return {v.y,v.z,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yzxw_get(stdmath_float4* p) { return stdmath_float4_yzxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yzxw_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->z = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yzyx(stdmath_float4 v) { return {v.y,v.z,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yzyx_get(stdmath_float4* p) { return stdmath_float4_yzyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yzyx_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->z = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yzyy(stdmath_float4 v) { return {v.y,v.z,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yzyy_get(stdmath_float4* p) { return stdmath_float4_yzyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yzyy_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->z = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yzyz(stdmath_float4 v) { return {v.y,v.z,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yzyz_get(stdmath_float4* p) { return stdmath_float4_yzyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yzyz_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->z = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yzyw(stdmath_float4 v) { return {v.y,v.z,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yzyw_get(stdmath_float4* p) { return stdmath_float4_yzyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yzyw_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->z = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yzzx(stdmath_float4 v) { return {v.y,v.z,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yzzx_get(stdmath_float4* p) { return stdmath_float4_yzzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yzzx_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->z = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yzzy(stdmath_float4 v) { return {v.y,v.z,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yzzy_get(stdmath_float4* p) { return stdmath_float4_yzzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yzzy_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->z = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yzzz(stdmath_float4 v) { return {v.y,v.z,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yzzz_get(stdmath_float4* p) { return stdmath_float4_yzzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yzzz_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->z = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yzzw(stdmath_float4 v) { return {v.y,v.z,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yzzw_get(stdmath_float4* p) { return stdmath_float4_yzzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yzzw_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->z = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yzwx(stdmath_float4 v) { return {v.y,v.z,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yzwx_get(stdmath_float4* p) { return stdmath_float4_yzwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yzwx_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->z = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yzwy(stdmath_float4 v) { return {v.y,v.z,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yzwy_get(stdmath_float4* p) { return stdmath_float4_yzwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yzwy_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->z = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yzwz(stdmath_float4 v) { return {v.y,v.z,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yzwz_get(stdmath_float4* p) { return stdmath_float4_yzwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yzwz_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->z = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yzww(stdmath_float4 v) { return {v.y,v.z,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yzww_get(stdmath_float4* p) { return stdmath_float4_yzww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_yzww_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->z = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_ywxx(stdmath_float4 v) { return {v.y,v.w,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_ywxx_get(stdmath_float4* p) { return stdmath_float4_ywxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_ywxx_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->w = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_ywxy(stdmath_float4 v) { return {v.y,v.w,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_ywxy_get(stdmath_float4* p) { return stdmath_float4_ywxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_ywxy_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->w = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_ywxz(stdmath_float4 v) { return {v.y,v.w,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_ywxz_get(stdmath_float4* p) { return stdmath_float4_ywxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_ywxz_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->w = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_ywxw(stdmath_float4 v) { return {v.y,v.w,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_ywxw_get(stdmath_float4* p) { return stdmath_float4_ywxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_ywxw_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->w = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_ywyx(stdmath_float4 v) { return {v.y,v.w,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_ywyx_get(stdmath_float4* p) { return stdmath_float4_ywyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_ywyx_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->w = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_ywyy(stdmath_float4 v) { return {v.y,v.w,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_ywyy_get(stdmath_float4* p) { return stdmath_float4_ywyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_ywyy_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->w = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_ywyz(stdmath_float4 v) { return {v.y,v.w,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_ywyz_get(stdmath_float4* p) { return stdmath_float4_ywyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_ywyz_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->w = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_ywyw(stdmath_float4 v) { return {v.y,v.w,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_ywyw_get(stdmath_float4* p) { return stdmath_float4_ywyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_ywyw_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->w = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_ywzx(stdmath_float4 v) { return {v.y,v.w,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_ywzx_get(stdmath_float4* p) { return stdmath_float4_ywzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_ywzx_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->w = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_ywzy(stdmath_float4 v) { return {v.y,v.w,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_ywzy_get(stdmath_float4* p) { return stdmath_float4_ywzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_ywzy_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->w = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_ywzz(stdmath_float4 v) { return {v.y,v.w,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_ywzz_get(stdmath_float4* p) { return stdmath_float4_ywzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_ywzz_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->w = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_ywzw(stdmath_float4 v) { return {v.y,v.w,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_ywzw_get(stdmath_float4* p) { return stdmath_float4_ywzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_ywzw_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->w = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_ywwx(stdmath_float4 v) { return {v.y,v.w,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_ywwx_get(stdmath_float4* p) { return stdmath_float4_ywwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_ywwx_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->w = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_ywwy(stdmath_float4 v) { return {v.y,v.w,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_ywwy_get(stdmath_float4* p) { return stdmath_float4_ywwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_ywwy_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->w = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_ywwz(stdmath_float4 v) { return {v.y,v.w,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_ywwz_get(stdmath_float4* p) { return stdmath_float4_ywwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_ywwz_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->w = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_ywww(stdmath_float4 v) { return {v.y,v.w,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_ywww_get(stdmath_float4* p) { return stdmath_float4_ywww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_ywww_set(stdmath_float4* p, stdmath_float4 value) { p->y = value.x; p->w = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zxxx(stdmath_float4 v) { return {v.z,v.x,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zxxx_get(stdmath_float4* p) { return stdmath_float4_zxxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zxxx_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->x = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zxxy(stdmath_float4 v) { return {v.z,v.x,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zxxy_get(stdmath_float4* p) { return stdmath_float4_zxxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zxxy_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->x = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zxxz(stdmath_float4 v) { return {v.z,v.x,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zxxz_get(stdmath_float4* p) { return stdmath_float4_zxxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zxxz_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->x = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zxxw(stdmath_float4 v) { return {v.z,v.x,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zxxw_get(stdmath_float4* p) { return stdmath_float4_zxxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zxxw_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->x = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zxyx(stdmath_float4 v) { return {v.z,v.x,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zxyx_get(stdmath_float4* p) { return stdmath_float4_zxyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zxyx_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->x = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zxyy(stdmath_float4 v) { return {v.z,v.x,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zxyy_get(stdmath_float4* p) { return stdmath_float4_zxyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zxyy_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->x = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zxyz(stdmath_float4 v) { return {v.z,v.x,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zxyz_get(stdmath_float4* p) { return stdmath_float4_zxyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zxyz_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->x = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zxyw(stdmath_float4 v) { return {v.z,v.x,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zxyw_get(stdmath_float4* p) { return stdmath_float4_zxyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zxyw_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->x = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zxzx(stdmath_float4 v) { return {v.z,v.x,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zxzx_get(stdmath_float4* p) { return stdmath_float4_zxzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zxzx_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->x = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zxzy(stdmath_float4 v) { return {v.z,v.x,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zxzy_get(stdmath_float4* p) { return stdmath_float4_zxzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zxzy_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->x = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zxzz(stdmath_float4 v) { return {v.z,v.x,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zxzz_get(stdmath_float4* p) { return stdmath_float4_zxzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zxzz_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->x = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zxzw(stdmath_float4 v) { return {v.z,v.x,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zxzw_get(stdmath_float4* p) { return stdmath_float4_zxzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zxzw_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->x = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zxwx(stdmath_float4 v) { return {v.z,v.x,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zxwx_get(stdmath_float4* p) { return stdmath_float4_zxwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zxwx_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->x = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zxwy(stdmath_float4 v) { return {v.z,v.x,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zxwy_get(stdmath_float4* p) { return stdmath_float4_zxwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zxwy_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->x = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zxwz(stdmath_float4 v) { return {v.z,v.x,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zxwz_get(stdmath_float4* p) { return stdmath_float4_zxwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zxwz_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->x = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zxww(stdmath_float4 v) { return {v.z,v.x,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zxww_get(stdmath_float4* p) { return stdmath_float4_zxww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zxww_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->x = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zyxx(stdmath_float4 v) { return {v.z,v.y,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zyxx_get(stdmath_float4* p) { return stdmath_float4_zyxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zyxx_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->y = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zyxy(stdmath_float4 v) { return {v.z,v.y,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zyxy_get(stdmath_float4* p) { return stdmath_float4_zyxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zyxy_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->y = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zyxz(stdmath_float4 v) { return {v.z,v.y,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zyxz_get(stdmath_float4* p) { return stdmath_float4_zyxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zyxz_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->y = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zyxw(stdmath_float4 v) { return {v.z,v.y,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zyxw_get(stdmath_float4* p) { return stdmath_float4_zyxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zyxw_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->y = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zyyx(stdmath_float4 v) { return {v.z,v.y,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zyyx_get(stdmath_float4* p) { return stdmath_float4_zyyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zyyx_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->y = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zyyy(stdmath_float4 v) { return {v.z,v.y,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zyyy_get(stdmath_float4* p) { return stdmath_float4_zyyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zyyy_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->y = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zyyz(stdmath_float4 v) { return {v.z,v.y,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zyyz_get(stdmath_float4* p) { return stdmath_float4_zyyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zyyz_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->y = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zyyw(stdmath_float4 v) { return {v.z,v.y,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zyyw_get(stdmath_float4* p) { return stdmath_float4_zyyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zyyw_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->y = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zyzx(stdmath_float4 v) { return {v.z,v.y,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zyzx_get(stdmath_float4* p) { return stdmath_float4_zyzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zyzx_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->y = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zyzy(stdmath_float4 v) { return {v.z,v.y,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zyzy_get(stdmath_float4* p) { return stdmath_float4_zyzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zyzy_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->y = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zyzz(stdmath_float4 v) { return {v.z,v.y,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zyzz_get(stdmath_float4* p) { return stdmath_float4_zyzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zyzz_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->y = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zyzw(stdmath_float4 v) { return {v.z,v.y,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zyzw_get(stdmath_float4* p) { return stdmath_float4_zyzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zyzw_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->y = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zywx(stdmath_float4 v) { return {v.z,v.y,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zywx_get(stdmath_float4* p) { return stdmath_float4_zywx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zywx_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->y = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zywy(stdmath_float4 v) { return {v.z,v.y,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zywy_get(stdmath_float4* p) { return stdmath_float4_zywy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zywy_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->y = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zywz(stdmath_float4 v) { return {v.z,v.y,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zywz_get(stdmath_float4* p) { return stdmath_float4_zywz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zywz_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->y = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zyww(stdmath_float4 v) { return {v.z,v.y,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zyww_get(stdmath_float4* p) { return stdmath_float4_zyww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zyww_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->y = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zzxx(stdmath_float4 v) { return {v.z,v.z,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zzxx_get(stdmath_float4* p) { return stdmath_float4_zzxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zzxx_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->z = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zzxy(stdmath_float4 v) { return {v.z,v.z,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zzxy_get(stdmath_float4* p) { return stdmath_float4_zzxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zzxy_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->z = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zzxz(stdmath_float4 v) { return {v.z,v.z,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zzxz_get(stdmath_float4* p) { return stdmath_float4_zzxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zzxz_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->z = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zzxw(stdmath_float4 v) { return {v.z,v.z,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zzxw_get(stdmath_float4* p) { return stdmath_float4_zzxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zzxw_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->z = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zzyx(stdmath_float4 v) { return {v.z,v.z,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zzyx_get(stdmath_float4* p) { return stdmath_float4_zzyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zzyx_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->z = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zzyy(stdmath_float4 v) { return {v.z,v.z,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zzyy_get(stdmath_float4* p) { return stdmath_float4_zzyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zzyy_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->z = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zzyz(stdmath_float4 v) { return {v.z,v.z,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zzyz_get(stdmath_float4* p) { return stdmath_float4_zzyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zzyz_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->z = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zzyw(stdmath_float4 v) { return {v.z,v.z,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zzyw_get(stdmath_float4* p) { return stdmath_float4_zzyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zzyw_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->z = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zzzx(stdmath_float4 v) { return {v.z,v.z,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zzzx_get(stdmath_float4* p) { return stdmath_float4_zzzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zzzx_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->z = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zzzy(stdmath_float4 v) { return {v.z,v.z,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zzzy_get(stdmath_float4* p) { return stdmath_float4_zzzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zzzy_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->z = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zzzz(stdmath_float4 v) { return {v.z,v.z,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zzzz_get(stdmath_float4* p) { return stdmath_float4_zzzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zzzz_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->z = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zzzw(stdmath_float4 v) { return {v.z,v.z,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zzzw_get(stdmath_float4* p) { return stdmath_float4_zzzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zzzw_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->z = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zzwx(stdmath_float4 v) { return {v.z,v.z,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zzwx_get(stdmath_float4* p) { return stdmath_float4_zzwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zzwx_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->z = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zzwy(stdmath_float4 v) { return {v.z,v.z,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zzwy_get(stdmath_float4* p) { return stdmath_float4_zzwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zzwy_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->z = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zzwz(stdmath_float4 v) { return {v.z,v.z,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zzwz_get(stdmath_float4* p) { return stdmath_float4_zzwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zzwz_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->z = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zzww(stdmath_float4 v) { return {v.z,v.z,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zzww_get(stdmath_float4* p) { return stdmath_float4_zzww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zzww_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->z = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zwxx(stdmath_float4 v) { return {v.z,v.w,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zwxx_get(stdmath_float4* p) { return stdmath_float4_zwxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zwxx_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->w = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zwxy(stdmath_float4 v) { return {v.z,v.w,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zwxy_get(stdmath_float4* p) { return stdmath_float4_zwxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zwxy_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->w = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zwxz(stdmath_float4 v) { return {v.z,v.w,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zwxz_get(stdmath_float4* p) { return stdmath_float4_zwxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zwxz_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->w = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zwxw(stdmath_float4 v) { return {v.z,v.w,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zwxw_get(stdmath_float4* p) { return stdmath_float4_zwxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zwxw_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->w = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zwyx(stdmath_float4 v) { return {v.z,v.w,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zwyx_get(stdmath_float4* p) { return stdmath_float4_zwyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zwyx_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->w = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zwyy(stdmath_float4 v) { return {v.z,v.w,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zwyy_get(stdmath_float4* p) { return stdmath_float4_zwyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zwyy_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->w = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zwyz(stdmath_float4 v) { return {v.z,v.w,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zwyz_get(stdmath_float4* p) { return stdmath_float4_zwyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zwyz_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->w = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zwyw(stdmath_float4 v) { return {v.z,v.w,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zwyw_get(stdmath_float4* p) { return stdmath_float4_zwyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zwyw_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->w = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zwzx(stdmath_float4 v) { return {v.z,v.w,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zwzx_get(stdmath_float4* p) { return stdmath_float4_zwzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zwzx_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->w = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zwzy(stdmath_float4 v) { return {v.z,v.w,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zwzy_get(stdmath_float4* p) { return stdmath_float4_zwzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zwzy_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->w = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zwzz(stdmath_float4 v) { return {v.z,v.w,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zwzz_get(stdmath_float4* p) { return stdmath_float4_zwzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zwzz_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->w = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zwzw(stdmath_float4 v) { return {v.z,v.w,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zwzw_get(stdmath_float4* p) { return stdmath_float4_zwzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zwzw_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->w = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zwwx(stdmath_float4 v) { return {v.z,v.w,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zwwx_get(stdmath_float4* p) { return stdmath_float4_zwwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zwwx_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->w = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zwwy(stdmath_float4 v) { return {v.z,v.w,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zwwy_get(stdmath_float4* p) { return stdmath_float4_zwwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zwwy_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->w = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zwwz(stdmath_float4 v) { return {v.z,v.w,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zwwz_get(stdmath_float4* p) { return stdmath_float4_zwwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zwwz_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->w = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zwww(stdmath_float4 v) { return {v.z,v.w,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zwww_get(stdmath_float4* p) { return stdmath_float4_zwww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_zwww_set(stdmath_float4* p, stdmath_float4 value) { p->z = value.x; p->w = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wxxx(stdmath_float4 v) { return {v.w,v.x,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wxxx_get(stdmath_float4* p) { return stdmath_float4_wxxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wxxx_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->x = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wxxy(stdmath_float4 v) { return {v.w,v.x,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wxxy_get(stdmath_float4* p) { return stdmath_float4_wxxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wxxy_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->x = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wxxz(stdmath_float4 v) { return {v.w,v.x,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wxxz_get(stdmath_float4* p) { return stdmath_float4_wxxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wxxz_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->x = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wxxw(stdmath_float4 v) { return {v.w,v.x,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wxxw_get(stdmath_float4* p) { return stdmath_float4_wxxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wxxw_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->x = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wxyx(stdmath_float4 v) { return {v.w,v.x,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wxyx_get(stdmath_float4* p) { return stdmath_float4_wxyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wxyx_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->x = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wxyy(stdmath_float4 v) { return {v.w,v.x,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wxyy_get(stdmath_float4* p) { return stdmath_float4_wxyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wxyy_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->x = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wxyz(stdmath_float4 v) { return {v.w,v.x,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wxyz_get(stdmath_float4* p) { return stdmath_float4_wxyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wxyz_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->x = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wxyw(stdmath_float4 v) { return {v.w,v.x,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wxyw_get(stdmath_float4* p) { return stdmath_float4_wxyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wxyw_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->x = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wxzx(stdmath_float4 v) { return {v.w,v.x,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wxzx_get(stdmath_float4* p) { return stdmath_float4_wxzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wxzx_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->x = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wxzy(stdmath_float4 v) { return {v.w,v.x,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wxzy_get(stdmath_float4* p) { return stdmath_float4_wxzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wxzy_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->x = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wxzz(stdmath_float4 v) { return {v.w,v.x,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wxzz_get(stdmath_float4* p) { return stdmath_float4_wxzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wxzz_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->x = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wxzw(stdmath_float4 v) { return {v.w,v.x,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wxzw_get(stdmath_float4* p) { return stdmath_float4_wxzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wxzw_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->x = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wxwx(stdmath_float4 v) { return {v.w,v.x,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wxwx_get(stdmath_float4* p) { return stdmath_float4_wxwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wxwx_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->x = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wxwy(stdmath_float4 v) { return {v.w,v.x,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wxwy_get(stdmath_float4* p) { return stdmath_float4_wxwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wxwy_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->x = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wxwz(stdmath_float4 v) { return {v.w,v.x,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wxwz_get(stdmath_float4* p) { return stdmath_float4_wxwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wxwz_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->x = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wxww(stdmath_float4 v) { return {v.w,v.x,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wxww_get(stdmath_float4* p) { return stdmath_float4_wxww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wxww_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->x = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wyxx(stdmath_float4 v) { return {v.w,v.y,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wyxx_get(stdmath_float4* p) { return stdmath_float4_wyxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wyxx_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->y = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wyxy(stdmath_float4 v) { return {v.w,v.y,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wyxy_get(stdmath_float4* p) { return stdmath_float4_wyxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wyxy_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->y = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wyxz(stdmath_float4 v) { return {v.w,v.y,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wyxz_get(stdmath_float4* p) { return stdmath_float4_wyxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wyxz_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->y = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wyxw(stdmath_float4 v) { return {v.w,v.y,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wyxw_get(stdmath_float4* p) { return stdmath_float4_wyxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wyxw_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->y = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wyyx(stdmath_float4 v) { return {v.w,v.y,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wyyx_get(stdmath_float4* p) { return stdmath_float4_wyyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wyyx_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->y = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wyyy(stdmath_float4 v) { return {v.w,v.y,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wyyy_get(stdmath_float4* p) { return stdmath_float4_wyyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wyyy_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->y = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wyyz(stdmath_float4 v) { return {v.w,v.y,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wyyz_get(stdmath_float4* p) { return stdmath_float4_wyyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wyyz_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->y = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wyyw(stdmath_float4 v) { return {v.w,v.y,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wyyw_get(stdmath_float4* p) { return stdmath_float4_wyyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wyyw_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->y = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wyzx(stdmath_float4 v) { return {v.w,v.y,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wyzx_get(stdmath_float4* p) { return stdmath_float4_wyzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wyzx_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->y = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wyzy(stdmath_float4 v) { return {v.w,v.y,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wyzy_get(stdmath_float4* p) { return stdmath_float4_wyzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wyzy_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->y = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wyzz(stdmath_float4 v) { return {v.w,v.y,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wyzz_get(stdmath_float4* p) { return stdmath_float4_wyzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wyzz_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->y = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wyzw(stdmath_float4 v) { return {v.w,v.y,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wyzw_get(stdmath_float4* p) { return stdmath_float4_wyzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wyzw_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->y = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wywx(stdmath_float4 v) { return {v.w,v.y,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wywx_get(stdmath_float4* p) { return stdmath_float4_wywx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wywx_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->y = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wywy(stdmath_float4 v) { return {v.w,v.y,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wywy_get(stdmath_float4* p) { return stdmath_float4_wywy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wywy_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->y = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wywz(stdmath_float4 v) { return {v.w,v.y,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wywz_get(stdmath_float4* p) { return stdmath_float4_wywz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wywz_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->y = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wyww(stdmath_float4 v) { return {v.w,v.y,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wyww_get(stdmath_float4* p) { return stdmath_float4_wyww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wyww_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->y = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wzxx(stdmath_float4 v) { return {v.w,v.z,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wzxx_get(stdmath_float4* p) { return stdmath_float4_wzxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wzxx_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->z = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wzxy(stdmath_float4 v) { return {v.w,v.z,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wzxy_get(stdmath_float4* p) { return stdmath_float4_wzxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wzxy_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->z = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wzxz(stdmath_float4 v) { return {v.w,v.z,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wzxz_get(stdmath_float4* p) { return stdmath_float4_wzxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wzxz_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->z = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wzxw(stdmath_float4 v) { return {v.w,v.z,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wzxw_get(stdmath_float4* p) { return stdmath_float4_wzxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wzxw_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->z = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wzyx(stdmath_float4 v) { return {v.w,v.z,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wzyx_get(stdmath_float4* p) { return stdmath_float4_wzyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wzyx_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->z = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wzyy(stdmath_float4 v) { return {v.w,v.z,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wzyy_get(stdmath_float4* p) { return stdmath_float4_wzyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wzyy_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->z = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wzyz(stdmath_float4 v) { return {v.w,v.z,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wzyz_get(stdmath_float4* p) { return stdmath_float4_wzyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wzyz_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->z = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wzyw(stdmath_float4 v) { return {v.w,v.z,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wzyw_get(stdmath_float4* p) { return stdmath_float4_wzyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wzyw_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->z = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wzzx(stdmath_float4 v) { return {v.w,v.z,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wzzx_get(stdmath_float4* p) { return stdmath_float4_wzzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wzzx_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->z = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wzzy(stdmath_float4 v) { return {v.w,v.z,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wzzy_get(stdmath_float4* p) { return stdmath_float4_wzzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wzzy_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->z = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wzzz(stdmath_float4 v) { return {v.w,v.z,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wzzz_get(stdmath_float4* p) { return stdmath_float4_wzzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wzzz_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->z = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wzzw(stdmath_float4 v) { return {v.w,v.z,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wzzw_get(stdmath_float4* p) { return stdmath_float4_wzzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wzzw_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->z = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wzwx(stdmath_float4 v) { return {v.w,v.z,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wzwx_get(stdmath_float4* p) { return stdmath_float4_wzwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wzwx_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->z = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wzwy(stdmath_float4 v) { return {v.w,v.z,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wzwy_get(stdmath_float4* p) { return stdmath_float4_wzwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wzwy_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->z = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wzwz(stdmath_float4 v) { return {v.w,v.z,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wzwz_get(stdmath_float4* p) { return stdmath_float4_wzwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wzwz_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->z = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wzww(stdmath_float4 v) { return {v.w,v.z,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wzww_get(stdmath_float4* p) { return stdmath_float4_wzww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wzww_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->z = value.y; p->w = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wwxx(stdmath_float4 v) { return {v.w,v.w,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wwxx_get(stdmath_float4* p) { return stdmath_float4_wwxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wwxx_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->w = value.y; p->x = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wwxy(stdmath_float4 v) { return {v.w,v.w,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wwxy_get(stdmath_float4* p) { return stdmath_float4_wwxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wwxy_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->w = value.y; p->x = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wwxz(stdmath_float4 v) { return {v.w,v.w,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wwxz_get(stdmath_float4* p) { return stdmath_float4_wwxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wwxz_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->w = value.y; p->x = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wwxw(stdmath_float4 v) { return {v.w,v.w,v.x,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wwxw_get(stdmath_float4* p) { return stdmath_float4_wwxw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wwxw_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->w = value.y; p->x = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wwyx(stdmath_float4 v) { return {v.w,v.w,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wwyx_get(stdmath_float4* p) { return stdmath_float4_wwyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wwyx_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->w = value.y; p->y = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wwyy(stdmath_float4 v) { return {v.w,v.w,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wwyy_get(stdmath_float4* p) { return stdmath_float4_wwyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wwyy_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->w = value.y; p->y = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wwyz(stdmath_float4 v) { return {v.w,v.w,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wwyz_get(stdmath_float4* p) { return stdmath_float4_wwyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wwyz_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->w = value.y; p->y = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wwyw(stdmath_float4 v) { return {v.w,v.w,v.y,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wwyw_get(stdmath_float4* p) { return stdmath_float4_wwyw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wwyw_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->w = value.y; p->y = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wwzx(stdmath_float4 v) { return {v.w,v.w,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wwzx_get(stdmath_float4* p) { return stdmath_float4_wwzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wwzx_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->w = value.y; p->z = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wwzy(stdmath_float4 v) { return {v.w,v.w,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wwzy_get(stdmath_float4* p) { return stdmath_float4_wwzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wwzy_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->w = value.y; p->z = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wwzz(stdmath_float4 v) { return {v.w,v.w,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wwzz_get(stdmath_float4* p) { return stdmath_float4_wwzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wwzz_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->w = value.y; p->z = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wwzw(stdmath_float4 v) { return {v.w,v.w,v.z,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wwzw_get(stdmath_float4* p) { return stdmath_float4_wwzw(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wwzw_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->w = value.y; p->z = value.z; p->w = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wwwx(stdmath_float4 v) { return {v.w,v.w,v.w,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wwwx_get(stdmath_float4* p) { return stdmath_float4_wwwx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wwwx_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->w = value.y; p->w = value.z; p->x = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wwwy(stdmath_float4 v) { return {v.w,v.w,v.w,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wwwy_get(stdmath_float4* p) { return stdmath_float4_wwwy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wwwy_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->w = value.y; p->w = value.z; p->y = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wwwz(stdmath_float4 v) { return {v.w,v.w,v.w,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wwwz_get(stdmath_float4* p) { return stdmath_float4_wwwz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wwwz_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->w = value.y; p->w = value.z; p->z = value.w; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wwww(stdmath_float4 v) { return {v.w,v.w,v.w,v.w}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wwww_get(stdmath_float4* p) { return stdmath_float4_wwww(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float4 stdmath_float4_wwww_set(stdmath_float4* p, stdmath_float4 value) { p->w = value.x; p->w = value.y; p->w = value.z; p->w = value.w; return *p; }

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

inline stdmath::float4 c(stdmath_float4 c) {
	return (stdmath::float4&)c;
}
inline stdmath_float4 c(stdmath::float4 c) {
	return (stdmath_float4&)c;
}

#ifdef __cplusplus
extern "C" {
#endif

stdmath_float4 stdmath_float4_broadcast(float all) {
	return c(stdmath::float4((stdmath::float4::underlying_type)all));
}

stdmath_float4 stdmath_float4_add(stdmath_float4 a, stdmath_float4 b) {
	return c(c(a) + c(b));
}
stdmath_float4 stdmath_float4_subtract(stdmath_float4 a, stdmath_float4 b) {
	return c(c(a) - c(b));
}
stdmath_float4 stdmath_float4_negate(stdmath_float4 v) {
	return c(stdmath::float4(-(stdmath::vector<float, 4>)c(v)));
}
stdmath_float4 stdmath_float4_multiply(stdmath_float4 a, stdmath_float4 b) {
	return c(c(a) * c(b));
}
stdmath_float4 stdmath_float4_divide(stdmath_float4 a, stdmath_float4 b) {
	return c(c(a) / c(b));
}
stdmath_float4 stdmath_float4_scale(stdmath_float4 v, float s) {
	return c(c(v) * (stdmath::float4::underlying_type)s);
}

#if false
stdmath_float4 stdmath_float4_modulus(stdmath_float4 a, stdmath_float4 b) {
	return c(c(a) % c(b));
}
stdmath_float4 stdmath_float4_logical_not(stdmath_float4 v) {
	return c(!c(v));
}
stdmath_float4 stdmath_float4_bitwise_not(stdmath_float4 v) {
	return c(~c(v));
}
stdmath_float4 stdmath_float4_logical_and(stdmath_float4 a, stdmath_float4 b) {
	return c(c(a) && c(b));
}
stdmath_float4 stdmath_float4_bitwise_and(stdmath_float4 a, stdmath_float4 b) {
	return c(c(a) & c(b));
}
stdmath_float4 stdmath_float4_logical_or(stdmath_float4 a, stdmath_float4 b) {
	return c(c(a) || c(b));
}
stdmath_float4 stdmath_float4_bitwise_or(stdmath_float4 a, stdmath_float4 b) {
	return c(c(a) | c(b));
}
stdmath_float4 stdmath_float4_bitwise_xor(stdmath_float4 a, stdmath_float4 b) {
	return c(c(a) ^ c(b));
}
stdmath_float4 stdmath_float4_shift_left(stdmath_float4 a, stdmath_float4 b) {
	return c(c(a) << c(b));
}
stdmath_float4 stdmath_float4_shift_right(stdmath_float4 a, stdmath_float4 b) {
	return c(c(a) >> c(b));
}
#endif

stdmath_bool4 stdmath_float4_equal_to(stdmath_float4 a, stdmath_float4 b) {
	return c(c(a) == c(b));
}
stdmath_bool4 stdmath_float4_not_equal_to(stdmath_float4 a, stdmath_float4 b) {
	return c(c(a) != c(b));
}
stdmath_bool4 stdmath_float4_less_than(stdmath_float4 a, stdmath_float4 b) {
	return c(c(a) < c(b));
}
stdmath_bool4 stdmath_float4_less_than_or_equal_to(stdmath_float4 a, stdmath_float4 b) {
	return c(c(a) <= c(b));
}
stdmath_bool4 stdmath_float4_greater_than(stdmath_float4 a, stdmath_float4 b) {
	return c(c(a) > c(b));
}
stdmath_bool4 stdmath_float4_greater_than_or_equal_to(stdmath_float4 a, stdmath_float4 b) {
	return c(c(a) >= c(b));
}

float stdmath_float4_length_squared(stdmath_float4 v)  {
	return (float)c(v).length_squared();
}
float stdmath_float4_length(stdmath_float4 v)  {
	return (float)c(v).length();
}
float stdmath_float4_dot(stdmath_float4 a, stdmath_float4 b)  {
	return (float)dot(c(a), c(b));
}
float stdmath_float4_min_element(stdmath_float4 v)  {
	return (float)c(v).min_element();
}
float stdmath_float4_max_element(stdmath_float4 v)  {
	return (float)c(v).max_element();
}

stdmath_float4 stdmath_float4_elementwise_transform(stdmath_float4 v, float(*func)(float)) {
	return c(c(v).elementwise_transform(func));
}
// float stdmath_float4_reduce_elements(stdmath_float4 v, float initial_value, float(*reducer)(stdmath_float4, stdmath_float4)) {
// 	return c(v).reduce_elements(initial_value, reducer);
// }

#if 4 == 3
stdmath_float4 stdmath_float4_cross(stdmath_float4 a, stdmath_float4 b) {
	return c(cross(c(a), c(b)));
}
#endif

stdmath_float4 stdmath_float4_min(stdmath_float4 a, stdmath_float4 b) {
	return c(min(c(a), c(b)));
}
stdmath_float4 stdmath_float4_max(stdmath_float4 a, stdmath_float4 b) {
	return c(max(c(a), c(b)));
}
stdmath_float4 stdmath_float4_normalize(stdmath_float4 v) {
	return c(normalize(c(v)));
}
stdmath_float4 stdmath_float4_lerp(stdmath_float4 a, stdmath_float4 b, float t) {
	return c(lerp(c(a), c(b), t));
}
stdmath_float4 stdmath_float4_clamp(stdmath_float4 a, stdmath_float4 min, stdmath_float4 max) {
	return c(clamp(c(a), c(min), c(max)));
}
stdmath_float4 stdmath_float4_reflect(stdmath_float4 a, stdmath_float4 b) {
	return c(reflect(c(a), c(b)));
}
stdmath_bool4 stdmath_float4_approximately_equal(stdmath_float4 a, stdmath_float4 b) {
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

#endif // __STDMATH_float4_H__