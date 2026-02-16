#ifndef __STDMATH_uint32_t4_H__
#define __STDMATH_uint32_t4_H__

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
#include "uint1.h"
#elif 4 == 3
#include "uint2.h"
#include "uint1.h"
#elif 4 == 4
#include "uint3.h"
#include "uint2.h"
#include "uint1.h"
#endif
#include "util.h"

#if 4 == 1
union stdmath_uint1 {
	struct {
		uint32_t x;
	};
	uint32_t data[1];
};
#elif 4 == 2
union stdmath_uint2 {
	struct {
		uint32_t x, y;
	};
	struct {
		uint32_t u, v;
	};
	uint32_t data[2];
};
#elif 4 == 3
union stdmath_uint3 {
	struct {
		uint32_t x, y, z;
	};
	struct {
		uint32_t r, g, b;
	};
	struct {
		uint32_t h, s, v;
	};
	uint32_t data[4]; // uint3s are aligned as if they were uint4s
};
#elif 4 == 4
union stdmath_uint4 {
	struct {
		uint32_t x, y, z, w;
	};
	struct {
		uint32_t r, g, b, a;
	};
	struct {
		uint32_t h, s, v;
	};
	uint32_t data[4];
};
#endif

stdmath_uint4 stdmath_uint4_broadcast(uint32_t all);

stdmath_uint4 stdmath_uint4_add(stdmath_uint4 a, stdmath_uint4 b);
stdmath_uint4 stdmath_uint4_subtract(stdmath_uint4 a, stdmath_uint4 b);
stdmath_uint4 stdmath_uint4_negate(stdmath_uint4 v);
stdmath_uint4 stdmath_uint4_multiply(stdmath_uint4 a, stdmath_uint4 b);
stdmath_uint4 stdmath_uint4_divide(stdmath_uint4 a, stdmath_uint4 b);
stdmath_uint4 stdmath_uint4_scale(stdmath_uint4 v, uint32_t s);

#if false
stdmath_uint4 stdmath_uint4_modulus(stdmath_uint4 a, stdmath_uint4 b);
stdmath_uint4 stdmath_uint4_logical_not(stdmath_uint4 v);
stdmath_uint4 stdmath_uint4_bitwise_not(stdmath_uint4 v);
stdmath_uint4 stdmath_uint4_logical_and(stdmath_uint4 a, stdmath_uint4 b);
stdmath_uint4 stdmath_uint4_bitwise_and(stdmath_uint4 a, stdmath_uint4 b);
stdmath_uint4 stdmath_uint4_logical_or(stdmath_uint4 a, stdmath_uint4 b);
stdmath_uint4 stdmath_uint4_bitwise_or(stdmath_uint4 a, stdmath_uint4 b);
stdmath_uint4 stdmath_uint4_bitwise_xor(stdmath_uint4 a, stdmath_uint4 b);
stdmath_uint4 stdmath_uint4_shift_left(stdmath_uint4 a, stdmath_uint4 b);
stdmath_uint4 stdmath_uint4_shift_right(stdmath_uint4 a, stdmath_uint4 b);
#endif

stdmath_bool4 stdmath_uint4_equal_to(stdmath_uint4 a, stdmath_uint4 b);
stdmath_bool4 stdmath_uint4_not_equal_to(stdmath_uint4 a, stdmath_uint4 b);
stdmath_bool4 stdmath_uint4_less_than(stdmath_uint4 a, stdmath_uint4 b);
stdmath_bool4 stdmath_uint4_less_than_or_equal_to(stdmath_uint4 a, stdmath_uint4 b);
stdmath_bool4 stdmath_uint4_greater_than(stdmath_uint4 a, stdmath_uint4 b);
stdmath_bool4 stdmath_uint4_greater_than_or_equal_to(stdmath_uint4 a, stdmath_uint4 b);

uint32_t stdmath_uint4_length_squared(stdmath_uint4 v);
uint32_t stdmath_uint4_length(stdmath_uint4 v);
uint32_t stdmath_uint4_dot(stdmath_uint4 a, stdmath_uint4 b);
uint32_t stdmath_uint4_min_element(stdmath_uint4 v);
uint32_t stdmath_uint4_max_element(stdmath_uint4 v);

stdmath_uint4 stdmath_uint4_elementwise_transform(stdmath_uint4 v, uint32_t(*func)(uint32_t));
// uint32_t stdmath_uint4_reduce_elements(stdmath_uint4 v, uint32_t initial_value, uint32_t(*reducer)(stdmath_uint4, stdmath_uint4));

#if 4 == 3
stdmath_uint3 stdmath_uint3_cross(stdmath_uint3 a, stdmath_uint3 b);
#endif

stdmath_uint4 stdmath_uint4_min(stdmath_uint4 a, stdmath_uint4 b);
stdmath_uint4 stdmath_uint4_max(stdmath_uint4 a, stdmath_uint4 b);
stdmath_uint4 stdmath_uint4_normalize(stdmath_uint4 v);
stdmath_uint4 stdmath_uint4_lerp(stdmath_uint4 a, stdmath_uint4 b, float t);
stdmath_uint4 stdmath_uint4_clamp(stdmath_uint4 a, stdmath_uint4 min, stdmath_uint4 max);
stdmath_uint4 stdmath_uint4_reflect(stdmath_uint4 a, stdmath_uint4 b);
stdmath_bool4 stdmath_uint4_approximately_equal(stdmath_uint4 a, stdmath_uint4 b);

#if false
bool stdmath_bool4_all_of(stdmath_bool4 v);
bool stdmath_bool4_any_of(stdmath_bool4 v);
bool stdmath_bool4_none_of(stdmath_bool4 v);
bool stdmath_bool4_some_of(stdmath_bool4 v);
#endif

inline static stdmath_uint1 stdmath_uint4_x(stdmath_uint4 v) { return {v.x}; }
inline static stdmath_uint1 stdmath_uint4_x_get(stdmath_uint4* p) { return stdmath_uint4_x(*p); }
inline static stdmath_uint4 stdmath_uint4_x_set(stdmath_uint4* p, stdmath_uint1 value) { p->x = value.x; return *p; }
inline static stdmath_uint1 stdmath_uint4_y(stdmath_uint4 v) { return {v.y}; }
inline static stdmath_uint1 stdmath_uint4_y_get(stdmath_uint4* p) { return stdmath_uint4_y(*p); }
inline static stdmath_uint4 stdmath_uint4_y_set(stdmath_uint4* p, stdmath_uint1 value) { p->y = value.x; return *p; }
inline static stdmath_uint1 stdmath_uint4_z(stdmath_uint4 v) { return {v.z}; }
inline static stdmath_uint1 stdmath_uint4_z_get(stdmath_uint4* p) { return stdmath_uint4_z(*p); }
inline static stdmath_uint4 stdmath_uint4_z_set(stdmath_uint4* p, stdmath_uint1 value) { p->z = value.x; return *p; }
inline static stdmath_uint1 stdmath_uint4_w(stdmath_uint4 v) { return {v.w}; }
inline static stdmath_uint1 stdmath_uint4_w_get(stdmath_uint4* p) { return stdmath_uint4_w(*p); }
inline static stdmath_uint4 stdmath_uint4_w_set(stdmath_uint4* p, stdmath_uint1 value) { p->w = value.x; return *p; }
inline static stdmath_uint2 stdmath_uint4_xx(stdmath_uint4 v) { return {v.x,v.x}; }
inline static stdmath_uint2 stdmath_uint4_xx_get(stdmath_uint4* p) { return stdmath_uint4_xx(*p); }
inline static stdmath_uint4 stdmath_uint4_xx_set(stdmath_uint4* p, stdmath_uint2 value) { p->x = value.x; p->x = value.y; return *p; }
inline static stdmath_uint2 stdmath_uint4_xy(stdmath_uint4 v) { return {v.x,v.y}; }
inline static stdmath_uint2 stdmath_uint4_xy_get(stdmath_uint4* p) { return stdmath_uint4_xy(*p); }
inline static stdmath_uint4 stdmath_uint4_xy_set(stdmath_uint4* p, stdmath_uint2 value) { p->x = value.x; p->y = value.y; return *p; }
inline static stdmath_uint2 stdmath_uint4_xz(stdmath_uint4 v) { return {v.x,v.z}; }
inline static stdmath_uint2 stdmath_uint4_xz_get(stdmath_uint4* p) { return stdmath_uint4_xz(*p); }
inline static stdmath_uint4 stdmath_uint4_xz_set(stdmath_uint4* p, stdmath_uint2 value) { p->x = value.x; p->z = value.y; return *p; }
inline static stdmath_uint2 stdmath_uint4_xw(stdmath_uint4 v) { return {v.x,v.w}; }
inline static stdmath_uint2 stdmath_uint4_xw_get(stdmath_uint4* p) { return stdmath_uint4_xw(*p); }
inline static stdmath_uint4 stdmath_uint4_xw_set(stdmath_uint4* p, stdmath_uint2 value) { p->x = value.x; p->w = value.y; return *p; }
inline static stdmath_uint2 stdmath_uint4_yx(stdmath_uint4 v) { return {v.y,v.x}; }
inline static stdmath_uint2 stdmath_uint4_yx_get(stdmath_uint4* p) { return stdmath_uint4_yx(*p); }
inline static stdmath_uint4 stdmath_uint4_yx_set(stdmath_uint4* p, stdmath_uint2 value) { p->y = value.x; p->x = value.y; return *p; }
inline static stdmath_uint2 stdmath_uint4_yy(stdmath_uint4 v) { return {v.y,v.y}; }
inline static stdmath_uint2 stdmath_uint4_yy_get(stdmath_uint4* p) { return stdmath_uint4_yy(*p); }
inline static stdmath_uint4 stdmath_uint4_yy_set(stdmath_uint4* p, stdmath_uint2 value) { p->y = value.x; p->y = value.y; return *p; }
inline static stdmath_uint2 stdmath_uint4_yz(stdmath_uint4 v) { return {v.y,v.z}; }
inline static stdmath_uint2 stdmath_uint4_yz_get(stdmath_uint4* p) { return stdmath_uint4_yz(*p); }
inline static stdmath_uint4 stdmath_uint4_yz_set(stdmath_uint4* p, stdmath_uint2 value) { p->y = value.x; p->z = value.y; return *p; }
inline static stdmath_uint2 stdmath_uint4_yw(stdmath_uint4 v) { return {v.y,v.w}; }
inline static stdmath_uint2 stdmath_uint4_yw_get(stdmath_uint4* p) { return stdmath_uint4_yw(*p); }
inline static stdmath_uint4 stdmath_uint4_yw_set(stdmath_uint4* p, stdmath_uint2 value) { p->y = value.x; p->w = value.y; return *p; }
inline static stdmath_uint2 stdmath_uint4_zx(stdmath_uint4 v) { return {v.z,v.x}; }
inline static stdmath_uint2 stdmath_uint4_zx_get(stdmath_uint4* p) { return stdmath_uint4_zx(*p); }
inline static stdmath_uint4 stdmath_uint4_zx_set(stdmath_uint4* p, stdmath_uint2 value) { p->z = value.x; p->x = value.y; return *p; }
inline static stdmath_uint2 stdmath_uint4_zy(stdmath_uint4 v) { return {v.z,v.y}; }
inline static stdmath_uint2 stdmath_uint4_zy_get(stdmath_uint4* p) { return stdmath_uint4_zy(*p); }
inline static stdmath_uint4 stdmath_uint4_zy_set(stdmath_uint4* p, stdmath_uint2 value) { p->z = value.x; p->y = value.y; return *p; }
inline static stdmath_uint2 stdmath_uint4_zz(stdmath_uint4 v) { return {v.z,v.z}; }
inline static stdmath_uint2 stdmath_uint4_zz_get(stdmath_uint4* p) { return stdmath_uint4_zz(*p); }
inline static stdmath_uint4 stdmath_uint4_zz_set(stdmath_uint4* p, stdmath_uint2 value) { p->z = value.x; p->z = value.y; return *p; }
inline static stdmath_uint2 stdmath_uint4_zw(stdmath_uint4 v) { return {v.z,v.w}; }
inline static stdmath_uint2 stdmath_uint4_zw_get(stdmath_uint4* p) { return stdmath_uint4_zw(*p); }
inline static stdmath_uint4 stdmath_uint4_zw_set(stdmath_uint4* p, stdmath_uint2 value) { p->z = value.x; p->w = value.y; return *p; }
inline static stdmath_uint2 stdmath_uint4_wx(stdmath_uint4 v) { return {v.w,v.x}; }
inline static stdmath_uint2 stdmath_uint4_wx_get(stdmath_uint4* p) { return stdmath_uint4_wx(*p); }
inline static stdmath_uint4 stdmath_uint4_wx_set(stdmath_uint4* p, stdmath_uint2 value) { p->w = value.x; p->x = value.y; return *p; }
inline static stdmath_uint2 stdmath_uint4_wy(stdmath_uint4 v) { return {v.w,v.y}; }
inline static stdmath_uint2 stdmath_uint4_wy_get(stdmath_uint4* p) { return stdmath_uint4_wy(*p); }
inline static stdmath_uint4 stdmath_uint4_wy_set(stdmath_uint4* p, stdmath_uint2 value) { p->w = value.x; p->y = value.y; return *p; }
inline static stdmath_uint2 stdmath_uint4_wz(stdmath_uint4 v) { return {v.w,v.z}; }
inline static stdmath_uint2 stdmath_uint4_wz_get(stdmath_uint4* p) { return stdmath_uint4_wz(*p); }
inline static stdmath_uint4 stdmath_uint4_wz_set(stdmath_uint4* p, stdmath_uint2 value) { p->w = value.x; p->z = value.y; return *p; }
inline static stdmath_uint2 stdmath_uint4_ww(stdmath_uint4 v) { return {v.w,v.w}; }
inline static stdmath_uint2 stdmath_uint4_ww_get(stdmath_uint4* p) { return stdmath_uint4_ww(*p); }
inline static stdmath_uint4 stdmath_uint4_ww_set(stdmath_uint4* p, stdmath_uint2 value) { p->w = value.x; p->w = value.y; return *p; }
inline static stdmath_uint3 stdmath_uint4_xxx(stdmath_uint4 v) { return {v.x,v.x,v.x}; }
inline static stdmath_uint3 stdmath_uint4_xxx_get(stdmath_uint4* p) { return stdmath_uint4_xxx(*p); }
inline static stdmath_uint4 stdmath_uint4_xxx_set(stdmath_uint4* p, stdmath_uint3 value) { p->x = value.x; p->x = value.y; p->x = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_xxy(stdmath_uint4 v) { return {v.x,v.x,v.y}; }
inline static stdmath_uint3 stdmath_uint4_xxy_get(stdmath_uint4* p) { return stdmath_uint4_xxy(*p); }
inline static stdmath_uint4 stdmath_uint4_xxy_set(stdmath_uint4* p, stdmath_uint3 value) { p->x = value.x; p->x = value.y; p->y = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_xxz(stdmath_uint4 v) { return {v.x,v.x,v.z}; }
inline static stdmath_uint3 stdmath_uint4_xxz_get(stdmath_uint4* p) { return stdmath_uint4_xxz(*p); }
inline static stdmath_uint4 stdmath_uint4_xxz_set(stdmath_uint4* p, stdmath_uint3 value) { p->x = value.x; p->x = value.y; p->z = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_xxw(stdmath_uint4 v) { return {v.x,v.x,v.w}; }
inline static stdmath_uint3 stdmath_uint4_xxw_get(stdmath_uint4* p) { return stdmath_uint4_xxw(*p); }
inline static stdmath_uint4 stdmath_uint4_xxw_set(stdmath_uint4* p, stdmath_uint3 value) { p->x = value.x; p->x = value.y; p->w = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_xyx(stdmath_uint4 v) { return {v.x,v.y,v.x}; }
inline static stdmath_uint3 stdmath_uint4_xyx_get(stdmath_uint4* p) { return stdmath_uint4_xyx(*p); }
inline static stdmath_uint4 stdmath_uint4_xyx_set(stdmath_uint4* p, stdmath_uint3 value) { p->x = value.x; p->y = value.y; p->x = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_xyy(stdmath_uint4 v) { return {v.x,v.y,v.y}; }
inline static stdmath_uint3 stdmath_uint4_xyy_get(stdmath_uint4* p) { return stdmath_uint4_xyy(*p); }
inline static stdmath_uint4 stdmath_uint4_xyy_set(stdmath_uint4* p, stdmath_uint3 value) { p->x = value.x; p->y = value.y; p->y = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_xyz(stdmath_uint4 v) { return {v.x,v.y,v.z}; }
inline static stdmath_uint3 stdmath_uint4_xyz_get(stdmath_uint4* p) { return stdmath_uint4_xyz(*p); }
inline static stdmath_uint4 stdmath_uint4_xyz_set(stdmath_uint4* p, stdmath_uint3 value) { p->x = value.x; p->y = value.y; p->z = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_xyw(stdmath_uint4 v) { return {v.x,v.y,v.w}; }
inline static stdmath_uint3 stdmath_uint4_xyw_get(stdmath_uint4* p) { return stdmath_uint4_xyw(*p); }
inline static stdmath_uint4 stdmath_uint4_xyw_set(stdmath_uint4* p, stdmath_uint3 value) { p->x = value.x; p->y = value.y; p->w = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_xzx(stdmath_uint4 v) { return {v.x,v.z,v.x}; }
inline static stdmath_uint3 stdmath_uint4_xzx_get(stdmath_uint4* p) { return stdmath_uint4_xzx(*p); }
inline static stdmath_uint4 stdmath_uint4_xzx_set(stdmath_uint4* p, stdmath_uint3 value) { p->x = value.x; p->z = value.y; p->x = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_xzy(stdmath_uint4 v) { return {v.x,v.z,v.y}; }
inline static stdmath_uint3 stdmath_uint4_xzy_get(stdmath_uint4* p) { return stdmath_uint4_xzy(*p); }
inline static stdmath_uint4 stdmath_uint4_xzy_set(stdmath_uint4* p, stdmath_uint3 value) { p->x = value.x; p->z = value.y; p->y = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_xzz(stdmath_uint4 v) { return {v.x,v.z,v.z}; }
inline static stdmath_uint3 stdmath_uint4_xzz_get(stdmath_uint4* p) { return stdmath_uint4_xzz(*p); }
inline static stdmath_uint4 stdmath_uint4_xzz_set(stdmath_uint4* p, stdmath_uint3 value) { p->x = value.x; p->z = value.y; p->z = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_xzw(stdmath_uint4 v) { return {v.x,v.z,v.w}; }
inline static stdmath_uint3 stdmath_uint4_xzw_get(stdmath_uint4* p) { return stdmath_uint4_xzw(*p); }
inline static stdmath_uint4 stdmath_uint4_xzw_set(stdmath_uint4* p, stdmath_uint3 value) { p->x = value.x; p->z = value.y; p->w = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_xwx(stdmath_uint4 v) { return {v.x,v.w,v.x}; }
inline static stdmath_uint3 stdmath_uint4_xwx_get(stdmath_uint4* p) { return stdmath_uint4_xwx(*p); }
inline static stdmath_uint4 stdmath_uint4_xwx_set(stdmath_uint4* p, stdmath_uint3 value) { p->x = value.x; p->w = value.y; p->x = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_xwy(stdmath_uint4 v) { return {v.x,v.w,v.y}; }
inline static stdmath_uint3 stdmath_uint4_xwy_get(stdmath_uint4* p) { return stdmath_uint4_xwy(*p); }
inline static stdmath_uint4 stdmath_uint4_xwy_set(stdmath_uint4* p, stdmath_uint3 value) { p->x = value.x; p->w = value.y; p->y = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_xwz(stdmath_uint4 v) { return {v.x,v.w,v.z}; }
inline static stdmath_uint3 stdmath_uint4_xwz_get(stdmath_uint4* p) { return stdmath_uint4_xwz(*p); }
inline static stdmath_uint4 stdmath_uint4_xwz_set(stdmath_uint4* p, stdmath_uint3 value) { p->x = value.x; p->w = value.y; p->z = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_xww(stdmath_uint4 v) { return {v.x,v.w,v.w}; }
inline static stdmath_uint3 stdmath_uint4_xww_get(stdmath_uint4* p) { return stdmath_uint4_xww(*p); }
inline static stdmath_uint4 stdmath_uint4_xww_set(stdmath_uint4* p, stdmath_uint3 value) { p->x = value.x; p->w = value.y; p->w = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_yxx(stdmath_uint4 v) { return {v.y,v.x,v.x}; }
inline static stdmath_uint3 stdmath_uint4_yxx_get(stdmath_uint4* p) { return stdmath_uint4_yxx(*p); }
inline static stdmath_uint4 stdmath_uint4_yxx_set(stdmath_uint4* p, stdmath_uint3 value) { p->y = value.x; p->x = value.y; p->x = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_yxy(stdmath_uint4 v) { return {v.y,v.x,v.y}; }
inline static stdmath_uint3 stdmath_uint4_yxy_get(stdmath_uint4* p) { return stdmath_uint4_yxy(*p); }
inline static stdmath_uint4 stdmath_uint4_yxy_set(stdmath_uint4* p, stdmath_uint3 value) { p->y = value.x; p->x = value.y; p->y = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_yxz(stdmath_uint4 v) { return {v.y,v.x,v.z}; }
inline static stdmath_uint3 stdmath_uint4_yxz_get(stdmath_uint4* p) { return stdmath_uint4_yxz(*p); }
inline static stdmath_uint4 stdmath_uint4_yxz_set(stdmath_uint4* p, stdmath_uint3 value) { p->y = value.x; p->x = value.y; p->z = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_yxw(stdmath_uint4 v) { return {v.y,v.x,v.w}; }
inline static stdmath_uint3 stdmath_uint4_yxw_get(stdmath_uint4* p) { return stdmath_uint4_yxw(*p); }
inline static stdmath_uint4 stdmath_uint4_yxw_set(stdmath_uint4* p, stdmath_uint3 value) { p->y = value.x; p->x = value.y; p->w = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_yyx(stdmath_uint4 v) { return {v.y,v.y,v.x}; }
inline static stdmath_uint3 stdmath_uint4_yyx_get(stdmath_uint4* p) { return stdmath_uint4_yyx(*p); }
inline static stdmath_uint4 stdmath_uint4_yyx_set(stdmath_uint4* p, stdmath_uint3 value) { p->y = value.x; p->y = value.y; p->x = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_yyy(stdmath_uint4 v) { return {v.y,v.y,v.y}; }
inline static stdmath_uint3 stdmath_uint4_yyy_get(stdmath_uint4* p) { return stdmath_uint4_yyy(*p); }
inline static stdmath_uint4 stdmath_uint4_yyy_set(stdmath_uint4* p, stdmath_uint3 value) { p->y = value.x; p->y = value.y; p->y = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_yyz(stdmath_uint4 v) { return {v.y,v.y,v.z}; }
inline static stdmath_uint3 stdmath_uint4_yyz_get(stdmath_uint4* p) { return stdmath_uint4_yyz(*p); }
inline static stdmath_uint4 stdmath_uint4_yyz_set(stdmath_uint4* p, stdmath_uint3 value) { p->y = value.x; p->y = value.y; p->z = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_yyw(stdmath_uint4 v) { return {v.y,v.y,v.w}; }
inline static stdmath_uint3 stdmath_uint4_yyw_get(stdmath_uint4* p) { return stdmath_uint4_yyw(*p); }
inline static stdmath_uint4 stdmath_uint4_yyw_set(stdmath_uint4* p, stdmath_uint3 value) { p->y = value.x; p->y = value.y; p->w = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_yzx(stdmath_uint4 v) { return {v.y,v.z,v.x}; }
inline static stdmath_uint3 stdmath_uint4_yzx_get(stdmath_uint4* p) { return stdmath_uint4_yzx(*p); }
inline static stdmath_uint4 stdmath_uint4_yzx_set(stdmath_uint4* p, stdmath_uint3 value) { p->y = value.x; p->z = value.y; p->x = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_yzy(stdmath_uint4 v) { return {v.y,v.z,v.y}; }
inline static stdmath_uint3 stdmath_uint4_yzy_get(stdmath_uint4* p) { return stdmath_uint4_yzy(*p); }
inline static stdmath_uint4 stdmath_uint4_yzy_set(stdmath_uint4* p, stdmath_uint3 value) { p->y = value.x; p->z = value.y; p->y = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_yzz(stdmath_uint4 v) { return {v.y,v.z,v.z}; }
inline static stdmath_uint3 stdmath_uint4_yzz_get(stdmath_uint4* p) { return stdmath_uint4_yzz(*p); }
inline static stdmath_uint4 stdmath_uint4_yzz_set(stdmath_uint4* p, stdmath_uint3 value) { p->y = value.x; p->z = value.y; p->z = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_yzw(stdmath_uint4 v) { return {v.y,v.z,v.w}; }
inline static stdmath_uint3 stdmath_uint4_yzw_get(stdmath_uint4* p) { return stdmath_uint4_yzw(*p); }
inline static stdmath_uint4 stdmath_uint4_yzw_set(stdmath_uint4* p, stdmath_uint3 value) { p->y = value.x; p->z = value.y; p->w = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_ywx(stdmath_uint4 v) { return {v.y,v.w,v.x}; }
inline static stdmath_uint3 stdmath_uint4_ywx_get(stdmath_uint4* p) { return stdmath_uint4_ywx(*p); }
inline static stdmath_uint4 stdmath_uint4_ywx_set(stdmath_uint4* p, stdmath_uint3 value) { p->y = value.x; p->w = value.y; p->x = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_ywy(stdmath_uint4 v) { return {v.y,v.w,v.y}; }
inline static stdmath_uint3 stdmath_uint4_ywy_get(stdmath_uint4* p) { return stdmath_uint4_ywy(*p); }
inline static stdmath_uint4 stdmath_uint4_ywy_set(stdmath_uint4* p, stdmath_uint3 value) { p->y = value.x; p->w = value.y; p->y = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_ywz(stdmath_uint4 v) { return {v.y,v.w,v.z}; }
inline static stdmath_uint3 stdmath_uint4_ywz_get(stdmath_uint4* p) { return stdmath_uint4_ywz(*p); }
inline static stdmath_uint4 stdmath_uint4_ywz_set(stdmath_uint4* p, stdmath_uint3 value) { p->y = value.x; p->w = value.y; p->z = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_yww(stdmath_uint4 v) { return {v.y,v.w,v.w}; }
inline static stdmath_uint3 stdmath_uint4_yww_get(stdmath_uint4* p) { return stdmath_uint4_yww(*p); }
inline static stdmath_uint4 stdmath_uint4_yww_set(stdmath_uint4* p, stdmath_uint3 value) { p->y = value.x; p->w = value.y; p->w = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_zxx(stdmath_uint4 v) { return {v.z,v.x,v.x}; }
inline static stdmath_uint3 stdmath_uint4_zxx_get(stdmath_uint4* p) { return stdmath_uint4_zxx(*p); }
inline static stdmath_uint4 stdmath_uint4_zxx_set(stdmath_uint4* p, stdmath_uint3 value) { p->z = value.x; p->x = value.y; p->x = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_zxy(stdmath_uint4 v) { return {v.z,v.x,v.y}; }
inline static stdmath_uint3 stdmath_uint4_zxy_get(stdmath_uint4* p) { return stdmath_uint4_zxy(*p); }
inline static stdmath_uint4 stdmath_uint4_zxy_set(stdmath_uint4* p, stdmath_uint3 value) { p->z = value.x; p->x = value.y; p->y = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_zxz(stdmath_uint4 v) { return {v.z,v.x,v.z}; }
inline static stdmath_uint3 stdmath_uint4_zxz_get(stdmath_uint4* p) { return stdmath_uint4_zxz(*p); }
inline static stdmath_uint4 stdmath_uint4_zxz_set(stdmath_uint4* p, stdmath_uint3 value) { p->z = value.x; p->x = value.y; p->z = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_zxw(stdmath_uint4 v) { return {v.z,v.x,v.w}; }
inline static stdmath_uint3 stdmath_uint4_zxw_get(stdmath_uint4* p) { return stdmath_uint4_zxw(*p); }
inline static stdmath_uint4 stdmath_uint4_zxw_set(stdmath_uint4* p, stdmath_uint3 value) { p->z = value.x; p->x = value.y; p->w = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_zyx(stdmath_uint4 v) { return {v.z,v.y,v.x}; }
inline static stdmath_uint3 stdmath_uint4_zyx_get(stdmath_uint4* p) { return stdmath_uint4_zyx(*p); }
inline static stdmath_uint4 stdmath_uint4_zyx_set(stdmath_uint4* p, stdmath_uint3 value) { p->z = value.x; p->y = value.y; p->x = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_zyy(stdmath_uint4 v) { return {v.z,v.y,v.y}; }
inline static stdmath_uint3 stdmath_uint4_zyy_get(stdmath_uint4* p) { return stdmath_uint4_zyy(*p); }
inline static stdmath_uint4 stdmath_uint4_zyy_set(stdmath_uint4* p, stdmath_uint3 value) { p->z = value.x; p->y = value.y; p->y = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_zyz(stdmath_uint4 v) { return {v.z,v.y,v.z}; }
inline static stdmath_uint3 stdmath_uint4_zyz_get(stdmath_uint4* p) { return stdmath_uint4_zyz(*p); }
inline static stdmath_uint4 stdmath_uint4_zyz_set(stdmath_uint4* p, stdmath_uint3 value) { p->z = value.x; p->y = value.y; p->z = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_zyw(stdmath_uint4 v) { return {v.z,v.y,v.w}; }
inline static stdmath_uint3 stdmath_uint4_zyw_get(stdmath_uint4* p) { return stdmath_uint4_zyw(*p); }
inline static stdmath_uint4 stdmath_uint4_zyw_set(stdmath_uint4* p, stdmath_uint3 value) { p->z = value.x; p->y = value.y; p->w = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_zzx(stdmath_uint4 v) { return {v.z,v.z,v.x}; }
inline static stdmath_uint3 stdmath_uint4_zzx_get(stdmath_uint4* p) { return stdmath_uint4_zzx(*p); }
inline static stdmath_uint4 stdmath_uint4_zzx_set(stdmath_uint4* p, stdmath_uint3 value) { p->z = value.x; p->z = value.y; p->x = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_zzy(stdmath_uint4 v) { return {v.z,v.z,v.y}; }
inline static stdmath_uint3 stdmath_uint4_zzy_get(stdmath_uint4* p) { return stdmath_uint4_zzy(*p); }
inline static stdmath_uint4 stdmath_uint4_zzy_set(stdmath_uint4* p, stdmath_uint3 value) { p->z = value.x; p->z = value.y; p->y = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_zzz(stdmath_uint4 v) { return {v.z,v.z,v.z}; }
inline static stdmath_uint3 stdmath_uint4_zzz_get(stdmath_uint4* p) { return stdmath_uint4_zzz(*p); }
inline static stdmath_uint4 stdmath_uint4_zzz_set(stdmath_uint4* p, stdmath_uint3 value) { p->z = value.x; p->z = value.y; p->z = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_zzw(stdmath_uint4 v) { return {v.z,v.z,v.w}; }
inline static stdmath_uint3 stdmath_uint4_zzw_get(stdmath_uint4* p) { return stdmath_uint4_zzw(*p); }
inline static stdmath_uint4 stdmath_uint4_zzw_set(stdmath_uint4* p, stdmath_uint3 value) { p->z = value.x; p->z = value.y; p->w = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_zwx(stdmath_uint4 v) { return {v.z,v.w,v.x}; }
inline static stdmath_uint3 stdmath_uint4_zwx_get(stdmath_uint4* p) { return stdmath_uint4_zwx(*p); }
inline static stdmath_uint4 stdmath_uint4_zwx_set(stdmath_uint4* p, stdmath_uint3 value) { p->z = value.x; p->w = value.y; p->x = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_zwy(stdmath_uint4 v) { return {v.z,v.w,v.y}; }
inline static stdmath_uint3 stdmath_uint4_zwy_get(stdmath_uint4* p) { return stdmath_uint4_zwy(*p); }
inline static stdmath_uint4 stdmath_uint4_zwy_set(stdmath_uint4* p, stdmath_uint3 value) { p->z = value.x; p->w = value.y; p->y = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_zwz(stdmath_uint4 v) { return {v.z,v.w,v.z}; }
inline static stdmath_uint3 stdmath_uint4_zwz_get(stdmath_uint4* p) { return stdmath_uint4_zwz(*p); }
inline static stdmath_uint4 stdmath_uint4_zwz_set(stdmath_uint4* p, stdmath_uint3 value) { p->z = value.x; p->w = value.y; p->z = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_zww(stdmath_uint4 v) { return {v.z,v.w,v.w}; }
inline static stdmath_uint3 stdmath_uint4_zww_get(stdmath_uint4* p) { return stdmath_uint4_zww(*p); }
inline static stdmath_uint4 stdmath_uint4_zww_set(stdmath_uint4* p, stdmath_uint3 value) { p->z = value.x; p->w = value.y; p->w = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_wxx(stdmath_uint4 v) { return {v.w,v.x,v.x}; }
inline static stdmath_uint3 stdmath_uint4_wxx_get(stdmath_uint4* p) { return stdmath_uint4_wxx(*p); }
inline static stdmath_uint4 stdmath_uint4_wxx_set(stdmath_uint4* p, stdmath_uint3 value) { p->w = value.x; p->x = value.y; p->x = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_wxy(stdmath_uint4 v) { return {v.w,v.x,v.y}; }
inline static stdmath_uint3 stdmath_uint4_wxy_get(stdmath_uint4* p) { return stdmath_uint4_wxy(*p); }
inline static stdmath_uint4 stdmath_uint4_wxy_set(stdmath_uint4* p, stdmath_uint3 value) { p->w = value.x; p->x = value.y; p->y = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_wxz(stdmath_uint4 v) { return {v.w,v.x,v.z}; }
inline static stdmath_uint3 stdmath_uint4_wxz_get(stdmath_uint4* p) { return stdmath_uint4_wxz(*p); }
inline static stdmath_uint4 stdmath_uint4_wxz_set(stdmath_uint4* p, stdmath_uint3 value) { p->w = value.x; p->x = value.y; p->z = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_wxw(stdmath_uint4 v) { return {v.w,v.x,v.w}; }
inline static stdmath_uint3 stdmath_uint4_wxw_get(stdmath_uint4* p) { return stdmath_uint4_wxw(*p); }
inline static stdmath_uint4 stdmath_uint4_wxw_set(stdmath_uint4* p, stdmath_uint3 value) { p->w = value.x; p->x = value.y; p->w = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_wyx(stdmath_uint4 v) { return {v.w,v.y,v.x}; }
inline static stdmath_uint3 stdmath_uint4_wyx_get(stdmath_uint4* p) { return stdmath_uint4_wyx(*p); }
inline static stdmath_uint4 stdmath_uint4_wyx_set(stdmath_uint4* p, stdmath_uint3 value) { p->w = value.x; p->y = value.y; p->x = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_wyy(stdmath_uint4 v) { return {v.w,v.y,v.y}; }
inline static stdmath_uint3 stdmath_uint4_wyy_get(stdmath_uint4* p) { return stdmath_uint4_wyy(*p); }
inline static stdmath_uint4 stdmath_uint4_wyy_set(stdmath_uint4* p, stdmath_uint3 value) { p->w = value.x; p->y = value.y; p->y = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_wyz(stdmath_uint4 v) { return {v.w,v.y,v.z}; }
inline static stdmath_uint3 stdmath_uint4_wyz_get(stdmath_uint4* p) { return stdmath_uint4_wyz(*p); }
inline static stdmath_uint4 stdmath_uint4_wyz_set(stdmath_uint4* p, stdmath_uint3 value) { p->w = value.x; p->y = value.y; p->z = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_wyw(stdmath_uint4 v) { return {v.w,v.y,v.w}; }
inline static stdmath_uint3 stdmath_uint4_wyw_get(stdmath_uint4* p) { return stdmath_uint4_wyw(*p); }
inline static stdmath_uint4 stdmath_uint4_wyw_set(stdmath_uint4* p, stdmath_uint3 value) { p->w = value.x; p->y = value.y; p->w = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_wzx(stdmath_uint4 v) { return {v.w,v.z,v.x}; }
inline static stdmath_uint3 stdmath_uint4_wzx_get(stdmath_uint4* p) { return stdmath_uint4_wzx(*p); }
inline static stdmath_uint4 stdmath_uint4_wzx_set(stdmath_uint4* p, stdmath_uint3 value) { p->w = value.x; p->z = value.y; p->x = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_wzy(stdmath_uint4 v) { return {v.w,v.z,v.y}; }
inline static stdmath_uint3 stdmath_uint4_wzy_get(stdmath_uint4* p) { return stdmath_uint4_wzy(*p); }
inline static stdmath_uint4 stdmath_uint4_wzy_set(stdmath_uint4* p, stdmath_uint3 value) { p->w = value.x; p->z = value.y; p->y = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_wzz(stdmath_uint4 v) { return {v.w,v.z,v.z}; }
inline static stdmath_uint3 stdmath_uint4_wzz_get(stdmath_uint4* p) { return stdmath_uint4_wzz(*p); }
inline static stdmath_uint4 stdmath_uint4_wzz_set(stdmath_uint4* p, stdmath_uint3 value) { p->w = value.x; p->z = value.y; p->z = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_wzw(stdmath_uint4 v) { return {v.w,v.z,v.w}; }
inline static stdmath_uint3 stdmath_uint4_wzw_get(stdmath_uint4* p) { return stdmath_uint4_wzw(*p); }
inline static stdmath_uint4 stdmath_uint4_wzw_set(stdmath_uint4* p, stdmath_uint3 value) { p->w = value.x; p->z = value.y; p->w = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_wwx(stdmath_uint4 v) { return {v.w,v.w,v.x}; }
inline static stdmath_uint3 stdmath_uint4_wwx_get(stdmath_uint4* p) { return stdmath_uint4_wwx(*p); }
inline static stdmath_uint4 stdmath_uint4_wwx_set(stdmath_uint4* p, stdmath_uint3 value) { p->w = value.x; p->w = value.y; p->x = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_wwy(stdmath_uint4 v) { return {v.w,v.w,v.y}; }
inline static stdmath_uint3 stdmath_uint4_wwy_get(stdmath_uint4* p) { return stdmath_uint4_wwy(*p); }
inline static stdmath_uint4 stdmath_uint4_wwy_set(stdmath_uint4* p, stdmath_uint3 value) { p->w = value.x; p->w = value.y; p->y = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_wwz(stdmath_uint4 v) { return {v.w,v.w,v.z}; }
inline static stdmath_uint3 stdmath_uint4_wwz_get(stdmath_uint4* p) { return stdmath_uint4_wwz(*p); }
inline static stdmath_uint4 stdmath_uint4_wwz_set(stdmath_uint4* p, stdmath_uint3 value) { p->w = value.x; p->w = value.y; p->z = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint4_www(stdmath_uint4 v) { return {v.w,v.w,v.w}; }
inline static stdmath_uint3 stdmath_uint4_www_get(stdmath_uint4* p) { return stdmath_uint4_www(*p); }
inline static stdmath_uint4 stdmath_uint4_www_set(stdmath_uint4* p, stdmath_uint3 value) { p->w = value.x; p->w = value.y; p->w = value.z; return *p; }
inline static stdmath_uint4 stdmath_uint4_xxxx(stdmath_uint4 v) { return {v.x,v.x,v.x,v.x}; }
inline static stdmath_uint4 stdmath_uint4_xxxx_get(stdmath_uint4* p) { return stdmath_uint4_xxxx(*p); }
inline static stdmath_uint4 stdmath_uint4_xxxx_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->x = value.y; p->x = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xxxy(stdmath_uint4 v) { return {v.x,v.x,v.x,v.y}; }
inline static stdmath_uint4 stdmath_uint4_xxxy_get(stdmath_uint4* p) { return stdmath_uint4_xxxy(*p); }
inline static stdmath_uint4 stdmath_uint4_xxxy_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->x = value.y; p->x = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xxxz(stdmath_uint4 v) { return {v.x,v.x,v.x,v.z}; }
inline static stdmath_uint4 stdmath_uint4_xxxz_get(stdmath_uint4* p) { return stdmath_uint4_xxxz(*p); }
inline static stdmath_uint4 stdmath_uint4_xxxz_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->x = value.y; p->x = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xxxw(stdmath_uint4 v) { return {v.x,v.x,v.x,v.w}; }
inline static stdmath_uint4 stdmath_uint4_xxxw_get(stdmath_uint4* p) { return stdmath_uint4_xxxw(*p); }
inline static stdmath_uint4 stdmath_uint4_xxxw_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->x = value.y; p->x = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xxyx(stdmath_uint4 v) { return {v.x,v.x,v.y,v.x}; }
inline static stdmath_uint4 stdmath_uint4_xxyx_get(stdmath_uint4* p) { return stdmath_uint4_xxyx(*p); }
inline static stdmath_uint4 stdmath_uint4_xxyx_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->x = value.y; p->y = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xxyy(stdmath_uint4 v) { return {v.x,v.x,v.y,v.y}; }
inline static stdmath_uint4 stdmath_uint4_xxyy_get(stdmath_uint4* p) { return stdmath_uint4_xxyy(*p); }
inline static stdmath_uint4 stdmath_uint4_xxyy_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->x = value.y; p->y = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xxyz(stdmath_uint4 v) { return {v.x,v.x,v.y,v.z}; }
inline static stdmath_uint4 stdmath_uint4_xxyz_get(stdmath_uint4* p) { return stdmath_uint4_xxyz(*p); }
inline static stdmath_uint4 stdmath_uint4_xxyz_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->x = value.y; p->y = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xxyw(stdmath_uint4 v) { return {v.x,v.x,v.y,v.w}; }
inline static stdmath_uint4 stdmath_uint4_xxyw_get(stdmath_uint4* p) { return stdmath_uint4_xxyw(*p); }
inline static stdmath_uint4 stdmath_uint4_xxyw_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->x = value.y; p->y = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xxzx(stdmath_uint4 v) { return {v.x,v.x,v.z,v.x}; }
inline static stdmath_uint4 stdmath_uint4_xxzx_get(stdmath_uint4* p) { return stdmath_uint4_xxzx(*p); }
inline static stdmath_uint4 stdmath_uint4_xxzx_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->x = value.y; p->z = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xxzy(stdmath_uint4 v) { return {v.x,v.x,v.z,v.y}; }
inline static stdmath_uint4 stdmath_uint4_xxzy_get(stdmath_uint4* p) { return stdmath_uint4_xxzy(*p); }
inline static stdmath_uint4 stdmath_uint4_xxzy_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->x = value.y; p->z = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xxzz(stdmath_uint4 v) { return {v.x,v.x,v.z,v.z}; }
inline static stdmath_uint4 stdmath_uint4_xxzz_get(stdmath_uint4* p) { return stdmath_uint4_xxzz(*p); }
inline static stdmath_uint4 stdmath_uint4_xxzz_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->x = value.y; p->z = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xxzw(stdmath_uint4 v) { return {v.x,v.x,v.z,v.w}; }
inline static stdmath_uint4 stdmath_uint4_xxzw_get(stdmath_uint4* p) { return stdmath_uint4_xxzw(*p); }
inline static stdmath_uint4 stdmath_uint4_xxzw_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->x = value.y; p->z = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xxwx(stdmath_uint4 v) { return {v.x,v.x,v.w,v.x}; }
inline static stdmath_uint4 stdmath_uint4_xxwx_get(stdmath_uint4* p) { return stdmath_uint4_xxwx(*p); }
inline static stdmath_uint4 stdmath_uint4_xxwx_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->x = value.y; p->w = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xxwy(stdmath_uint4 v) { return {v.x,v.x,v.w,v.y}; }
inline static stdmath_uint4 stdmath_uint4_xxwy_get(stdmath_uint4* p) { return stdmath_uint4_xxwy(*p); }
inline static stdmath_uint4 stdmath_uint4_xxwy_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->x = value.y; p->w = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xxwz(stdmath_uint4 v) { return {v.x,v.x,v.w,v.z}; }
inline static stdmath_uint4 stdmath_uint4_xxwz_get(stdmath_uint4* p) { return stdmath_uint4_xxwz(*p); }
inline static stdmath_uint4 stdmath_uint4_xxwz_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->x = value.y; p->w = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xxww(stdmath_uint4 v) { return {v.x,v.x,v.w,v.w}; }
inline static stdmath_uint4 stdmath_uint4_xxww_get(stdmath_uint4* p) { return stdmath_uint4_xxww(*p); }
inline static stdmath_uint4 stdmath_uint4_xxww_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->x = value.y; p->w = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xyxx(stdmath_uint4 v) { return {v.x,v.y,v.x,v.x}; }
inline static stdmath_uint4 stdmath_uint4_xyxx_get(stdmath_uint4* p) { return stdmath_uint4_xyxx(*p); }
inline static stdmath_uint4 stdmath_uint4_xyxx_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->y = value.y; p->x = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xyxy(stdmath_uint4 v) { return {v.x,v.y,v.x,v.y}; }
inline static stdmath_uint4 stdmath_uint4_xyxy_get(stdmath_uint4* p) { return stdmath_uint4_xyxy(*p); }
inline static stdmath_uint4 stdmath_uint4_xyxy_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->y = value.y; p->x = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xyxz(stdmath_uint4 v) { return {v.x,v.y,v.x,v.z}; }
inline static stdmath_uint4 stdmath_uint4_xyxz_get(stdmath_uint4* p) { return stdmath_uint4_xyxz(*p); }
inline static stdmath_uint4 stdmath_uint4_xyxz_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->y = value.y; p->x = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xyxw(stdmath_uint4 v) { return {v.x,v.y,v.x,v.w}; }
inline static stdmath_uint4 stdmath_uint4_xyxw_get(stdmath_uint4* p) { return stdmath_uint4_xyxw(*p); }
inline static stdmath_uint4 stdmath_uint4_xyxw_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->y = value.y; p->x = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xyyx(stdmath_uint4 v) { return {v.x,v.y,v.y,v.x}; }
inline static stdmath_uint4 stdmath_uint4_xyyx_get(stdmath_uint4* p) { return stdmath_uint4_xyyx(*p); }
inline static stdmath_uint4 stdmath_uint4_xyyx_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->y = value.y; p->y = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xyyy(stdmath_uint4 v) { return {v.x,v.y,v.y,v.y}; }
inline static stdmath_uint4 stdmath_uint4_xyyy_get(stdmath_uint4* p) { return stdmath_uint4_xyyy(*p); }
inline static stdmath_uint4 stdmath_uint4_xyyy_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->y = value.y; p->y = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xyyz(stdmath_uint4 v) { return {v.x,v.y,v.y,v.z}; }
inline static stdmath_uint4 stdmath_uint4_xyyz_get(stdmath_uint4* p) { return stdmath_uint4_xyyz(*p); }
inline static stdmath_uint4 stdmath_uint4_xyyz_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->y = value.y; p->y = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xyyw(stdmath_uint4 v) { return {v.x,v.y,v.y,v.w}; }
inline static stdmath_uint4 stdmath_uint4_xyyw_get(stdmath_uint4* p) { return stdmath_uint4_xyyw(*p); }
inline static stdmath_uint4 stdmath_uint4_xyyw_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->y = value.y; p->y = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xyzx(stdmath_uint4 v) { return {v.x,v.y,v.z,v.x}; }
inline static stdmath_uint4 stdmath_uint4_xyzx_get(stdmath_uint4* p) { return stdmath_uint4_xyzx(*p); }
inline static stdmath_uint4 stdmath_uint4_xyzx_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->y = value.y; p->z = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xyzy(stdmath_uint4 v) { return {v.x,v.y,v.z,v.y}; }
inline static stdmath_uint4 stdmath_uint4_xyzy_get(stdmath_uint4* p) { return stdmath_uint4_xyzy(*p); }
inline static stdmath_uint4 stdmath_uint4_xyzy_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->y = value.y; p->z = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xyzz(stdmath_uint4 v) { return {v.x,v.y,v.z,v.z}; }
inline static stdmath_uint4 stdmath_uint4_xyzz_get(stdmath_uint4* p) { return stdmath_uint4_xyzz(*p); }
inline static stdmath_uint4 stdmath_uint4_xyzz_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->y = value.y; p->z = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xyzw(stdmath_uint4 v) { return {v.x,v.y,v.z,v.w}; }
inline static stdmath_uint4 stdmath_uint4_xyzw_get(stdmath_uint4* p) { return stdmath_uint4_xyzw(*p); }
inline static stdmath_uint4 stdmath_uint4_xyzw_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->y = value.y; p->z = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xywx(stdmath_uint4 v) { return {v.x,v.y,v.w,v.x}; }
inline static stdmath_uint4 stdmath_uint4_xywx_get(stdmath_uint4* p) { return stdmath_uint4_xywx(*p); }
inline static stdmath_uint4 stdmath_uint4_xywx_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->y = value.y; p->w = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xywy(stdmath_uint4 v) { return {v.x,v.y,v.w,v.y}; }
inline static stdmath_uint4 stdmath_uint4_xywy_get(stdmath_uint4* p) { return stdmath_uint4_xywy(*p); }
inline static stdmath_uint4 stdmath_uint4_xywy_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->y = value.y; p->w = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xywz(stdmath_uint4 v) { return {v.x,v.y,v.w,v.z}; }
inline static stdmath_uint4 stdmath_uint4_xywz_get(stdmath_uint4* p) { return stdmath_uint4_xywz(*p); }
inline static stdmath_uint4 stdmath_uint4_xywz_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->y = value.y; p->w = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xyww(stdmath_uint4 v) { return {v.x,v.y,v.w,v.w}; }
inline static stdmath_uint4 stdmath_uint4_xyww_get(stdmath_uint4* p) { return stdmath_uint4_xyww(*p); }
inline static stdmath_uint4 stdmath_uint4_xyww_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->y = value.y; p->w = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xzxx(stdmath_uint4 v) { return {v.x,v.z,v.x,v.x}; }
inline static stdmath_uint4 stdmath_uint4_xzxx_get(stdmath_uint4* p) { return stdmath_uint4_xzxx(*p); }
inline static stdmath_uint4 stdmath_uint4_xzxx_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->z = value.y; p->x = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xzxy(stdmath_uint4 v) { return {v.x,v.z,v.x,v.y}; }
inline static stdmath_uint4 stdmath_uint4_xzxy_get(stdmath_uint4* p) { return stdmath_uint4_xzxy(*p); }
inline static stdmath_uint4 stdmath_uint4_xzxy_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->z = value.y; p->x = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xzxz(stdmath_uint4 v) { return {v.x,v.z,v.x,v.z}; }
inline static stdmath_uint4 stdmath_uint4_xzxz_get(stdmath_uint4* p) { return stdmath_uint4_xzxz(*p); }
inline static stdmath_uint4 stdmath_uint4_xzxz_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->z = value.y; p->x = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xzxw(stdmath_uint4 v) { return {v.x,v.z,v.x,v.w}; }
inline static stdmath_uint4 stdmath_uint4_xzxw_get(stdmath_uint4* p) { return stdmath_uint4_xzxw(*p); }
inline static stdmath_uint4 stdmath_uint4_xzxw_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->z = value.y; p->x = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xzyx(stdmath_uint4 v) { return {v.x,v.z,v.y,v.x}; }
inline static stdmath_uint4 stdmath_uint4_xzyx_get(stdmath_uint4* p) { return stdmath_uint4_xzyx(*p); }
inline static stdmath_uint4 stdmath_uint4_xzyx_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->z = value.y; p->y = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xzyy(stdmath_uint4 v) { return {v.x,v.z,v.y,v.y}; }
inline static stdmath_uint4 stdmath_uint4_xzyy_get(stdmath_uint4* p) { return stdmath_uint4_xzyy(*p); }
inline static stdmath_uint4 stdmath_uint4_xzyy_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->z = value.y; p->y = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xzyz(stdmath_uint4 v) { return {v.x,v.z,v.y,v.z}; }
inline static stdmath_uint4 stdmath_uint4_xzyz_get(stdmath_uint4* p) { return stdmath_uint4_xzyz(*p); }
inline static stdmath_uint4 stdmath_uint4_xzyz_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->z = value.y; p->y = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xzyw(stdmath_uint4 v) { return {v.x,v.z,v.y,v.w}; }
inline static stdmath_uint4 stdmath_uint4_xzyw_get(stdmath_uint4* p) { return stdmath_uint4_xzyw(*p); }
inline static stdmath_uint4 stdmath_uint4_xzyw_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->z = value.y; p->y = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xzzx(stdmath_uint4 v) { return {v.x,v.z,v.z,v.x}; }
inline static stdmath_uint4 stdmath_uint4_xzzx_get(stdmath_uint4* p) { return stdmath_uint4_xzzx(*p); }
inline static stdmath_uint4 stdmath_uint4_xzzx_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->z = value.y; p->z = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xzzy(stdmath_uint4 v) { return {v.x,v.z,v.z,v.y}; }
inline static stdmath_uint4 stdmath_uint4_xzzy_get(stdmath_uint4* p) { return stdmath_uint4_xzzy(*p); }
inline static stdmath_uint4 stdmath_uint4_xzzy_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->z = value.y; p->z = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xzzz(stdmath_uint4 v) { return {v.x,v.z,v.z,v.z}; }
inline static stdmath_uint4 stdmath_uint4_xzzz_get(stdmath_uint4* p) { return stdmath_uint4_xzzz(*p); }
inline static stdmath_uint4 stdmath_uint4_xzzz_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->z = value.y; p->z = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xzzw(stdmath_uint4 v) { return {v.x,v.z,v.z,v.w}; }
inline static stdmath_uint4 stdmath_uint4_xzzw_get(stdmath_uint4* p) { return stdmath_uint4_xzzw(*p); }
inline static stdmath_uint4 stdmath_uint4_xzzw_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->z = value.y; p->z = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xzwx(stdmath_uint4 v) { return {v.x,v.z,v.w,v.x}; }
inline static stdmath_uint4 stdmath_uint4_xzwx_get(stdmath_uint4* p) { return stdmath_uint4_xzwx(*p); }
inline static stdmath_uint4 stdmath_uint4_xzwx_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->z = value.y; p->w = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xzwy(stdmath_uint4 v) { return {v.x,v.z,v.w,v.y}; }
inline static stdmath_uint4 stdmath_uint4_xzwy_get(stdmath_uint4* p) { return stdmath_uint4_xzwy(*p); }
inline static stdmath_uint4 stdmath_uint4_xzwy_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->z = value.y; p->w = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xzwz(stdmath_uint4 v) { return {v.x,v.z,v.w,v.z}; }
inline static stdmath_uint4 stdmath_uint4_xzwz_get(stdmath_uint4* p) { return stdmath_uint4_xzwz(*p); }
inline static stdmath_uint4 stdmath_uint4_xzwz_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->z = value.y; p->w = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xzww(stdmath_uint4 v) { return {v.x,v.z,v.w,v.w}; }
inline static stdmath_uint4 stdmath_uint4_xzww_get(stdmath_uint4* p) { return stdmath_uint4_xzww(*p); }
inline static stdmath_uint4 stdmath_uint4_xzww_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->z = value.y; p->w = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xwxx(stdmath_uint4 v) { return {v.x,v.w,v.x,v.x}; }
inline static stdmath_uint4 stdmath_uint4_xwxx_get(stdmath_uint4* p) { return stdmath_uint4_xwxx(*p); }
inline static stdmath_uint4 stdmath_uint4_xwxx_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->w = value.y; p->x = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xwxy(stdmath_uint4 v) { return {v.x,v.w,v.x,v.y}; }
inline static stdmath_uint4 stdmath_uint4_xwxy_get(stdmath_uint4* p) { return stdmath_uint4_xwxy(*p); }
inline static stdmath_uint4 stdmath_uint4_xwxy_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->w = value.y; p->x = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xwxz(stdmath_uint4 v) { return {v.x,v.w,v.x,v.z}; }
inline static stdmath_uint4 stdmath_uint4_xwxz_get(stdmath_uint4* p) { return stdmath_uint4_xwxz(*p); }
inline static stdmath_uint4 stdmath_uint4_xwxz_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->w = value.y; p->x = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xwxw(stdmath_uint4 v) { return {v.x,v.w,v.x,v.w}; }
inline static stdmath_uint4 stdmath_uint4_xwxw_get(stdmath_uint4* p) { return stdmath_uint4_xwxw(*p); }
inline static stdmath_uint4 stdmath_uint4_xwxw_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->w = value.y; p->x = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xwyx(stdmath_uint4 v) { return {v.x,v.w,v.y,v.x}; }
inline static stdmath_uint4 stdmath_uint4_xwyx_get(stdmath_uint4* p) { return stdmath_uint4_xwyx(*p); }
inline static stdmath_uint4 stdmath_uint4_xwyx_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->w = value.y; p->y = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xwyy(stdmath_uint4 v) { return {v.x,v.w,v.y,v.y}; }
inline static stdmath_uint4 stdmath_uint4_xwyy_get(stdmath_uint4* p) { return stdmath_uint4_xwyy(*p); }
inline static stdmath_uint4 stdmath_uint4_xwyy_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->w = value.y; p->y = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xwyz(stdmath_uint4 v) { return {v.x,v.w,v.y,v.z}; }
inline static stdmath_uint4 stdmath_uint4_xwyz_get(stdmath_uint4* p) { return stdmath_uint4_xwyz(*p); }
inline static stdmath_uint4 stdmath_uint4_xwyz_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->w = value.y; p->y = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xwyw(stdmath_uint4 v) { return {v.x,v.w,v.y,v.w}; }
inline static stdmath_uint4 stdmath_uint4_xwyw_get(stdmath_uint4* p) { return stdmath_uint4_xwyw(*p); }
inline static stdmath_uint4 stdmath_uint4_xwyw_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->w = value.y; p->y = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xwzx(stdmath_uint4 v) { return {v.x,v.w,v.z,v.x}; }
inline static stdmath_uint4 stdmath_uint4_xwzx_get(stdmath_uint4* p) { return stdmath_uint4_xwzx(*p); }
inline static stdmath_uint4 stdmath_uint4_xwzx_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->w = value.y; p->z = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xwzy(stdmath_uint4 v) { return {v.x,v.w,v.z,v.y}; }
inline static stdmath_uint4 stdmath_uint4_xwzy_get(stdmath_uint4* p) { return stdmath_uint4_xwzy(*p); }
inline static stdmath_uint4 stdmath_uint4_xwzy_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->w = value.y; p->z = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xwzz(stdmath_uint4 v) { return {v.x,v.w,v.z,v.z}; }
inline static stdmath_uint4 stdmath_uint4_xwzz_get(stdmath_uint4* p) { return stdmath_uint4_xwzz(*p); }
inline static stdmath_uint4 stdmath_uint4_xwzz_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->w = value.y; p->z = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xwzw(stdmath_uint4 v) { return {v.x,v.w,v.z,v.w}; }
inline static stdmath_uint4 stdmath_uint4_xwzw_get(stdmath_uint4* p) { return stdmath_uint4_xwzw(*p); }
inline static stdmath_uint4 stdmath_uint4_xwzw_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->w = value.y; p->z = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xwwx(stdmath_uint4 v) { return {v.x,v.w,v.w,v.x}; }
inline static stdmath_uint4 stdmath_uint4_xwwx_get(stdmath_uint4* p) { return stdmath_uint4_xwwx(*p); }
inline static stdmath_uint4 stdmath_uint4_xwwx_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->w = value.y; p->w = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xwwy(stdmath_uint4 v) { return {v.x,v.w,v.w,v.y}; }
inline static stdmath_uint4 stdmath_uint4_xwwy_get(stdmath_uint4* p) { return stdmath_uint4_xwwy(*p); }
inline static stdmath_uint4 stdmath_uint4_xwwy_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->w = value.y; p->w = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xwwz(stdmath_uint4 v) { return {v.x,v.w,v.w,v.z}; }
inline static stdmath_uint4 stdmath_uint4_xwwz_get(stdmath_uint4* p) { return stdmath_uint4_xwwz(*p); }
inline static stdmath_uint4 stdmath_uint4_xwwz_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->w = value.y; p->w = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_xwww(stdmath_uint4 v) { return {v.x,v.w,v.w,v.w}; }
inline static stdmath_uint4 stdmath_uint4_xwww_get(stdmath_uint4* p) { return stdmath_uint4_xwww(*p); }
inline static stdmath_uint4 stdmath_uint4_xwww_set(stdmath_uint4* p, stdmath_uint4 value) { p->x = value.x; p->w = value.y; p->w = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_yxxx(stdmath_uint4 v) { return {v.y,v.x,v.x,v.x}; }
inline static stdmath_uint4 stdmath_uint4_yxxx_get(stdmath_uint4* p) { return stdmath_uint4_yxxx(*p); }
inline static stdmath_uint4 stdmath_uint4_yxxx_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->x = value.y; p->x = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_yxxy(stdmath_uint4 v) { return {v.y,v.x,v.x,v.y}; }
inline static stdmath_uint4 stdmath_uint4_yxxy_get(stdmath_uint4* p) { return stdmath_uint4_yxxy(*p); }
inline static stdmath_uint4 stdmath_uint4_yxxy_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->x = value.y; p->x = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_yxxz(stdmath_uint4 v) { return {v.y,v.x,v.x,v.z}; }
inline static stdmath_uint4 stdmath_uint4_yxxz_get(stdmath_uint4* p) { return stdmath_uint4_yxxz(*p); }
inline static stdmath_uint4 stdmath_uint4_yxxz_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->x = value.y; p->x = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_yxxw(stdmath_uint4 v) { return {v.y,v.x,v.x,v.w}; }
inline static stdmath_uint4 stdmath_uint4_yxxw_get(stdmath_uint4* p) { return stdmath_uint4_yxxw(*p); }
inline static stdmath_uint4 stdmath_uint4_yxxw_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->x = value.y; p->x = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_yxyx(stdmath_uint4 v) { return {v.y,v.x,v.y,v.x}; }
inline static stdmath_uint4 stdmath_uint4_yxyx_get(stdmath_uint4* p) { return stdmath_uint4_yxyx(*p); }
inline static stdmath_uint4 stdmath_uint4_yxyx_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->x = value.y; p->y = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_yxyy(stdmath_uint4 v) { return {v.y,v.x,v.y,v.y}; }
inline static stdmath_uint4 stdmath_uint4_yxyy_get(stdmath_uint4* p) { return stdmath_uint4_yxyy(*p); }
inline static stdmath_uint4 stdmath_uint4_yxyy_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->x = value.y; p->y = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_yxyz(stdmath_uint4 v) { return {v.y,v.x,v.y,v.z}; }
inline static stdmath_uint4 stdmath_uint4_yxyz_get(stdmath_uint4* p) { return stdmath_uint4_yxyz(*p); }
inline static stdmath_uint4 stdmath_uint4_yxyz_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->x = value.y; p->y = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_yxyw(stdmath_uint4 v) { return {v.y,v.x,v.y,v.w}; }
inline static stdmath_uint4 stdmath_uint4_yxyw_get(stdmath_uint4* p) { return stdmath_uint4_yxyw(*p); }
inline static stdmath_uint4 stdmath_uint4_yxyw_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->x = value.y; p->y = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_yxzx(stdmath_uint4 v) { return {v.y,v.x,v.z,v.x}; }
inline static stdmath_uint4 stdmath_uint4_yxzx_get(stdmath_uint4* p) { return stdmath_uint4_yxzx(*p); }
inline static stdmath_uint4 stdmath_uint4_yxzx_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->x = value.y; p->z = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_yxzy(stdmath_uint4 v) { return {v.y,v.x,v.z,v.y}; }
inline static stdmath_uint4 stdmath_uint4_yxzy_get(stdmath_uint4* p) { return stdmath_uint4_yxzy(*p); }
inline static stdmath_uint4 stdmath_uint4_yxzy_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->x = value.y; p->z = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_yxzz(stdmath_uint4 v) { return {v.y,v.x,v.z,v.z}; }
inline static stdmath_uint4 stdmath_uint4_yxzz_get(stdmath_uint4* p) { return stdmath_uint4_yxzz(*p); }
inline static stdmath_uint4 stdmath_uint4_yxzz_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->x = value.y; p->z = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_yxzw(stdmath_uint4 v) { return {v.y,v.x,v.z,v.w}; }
inline static stdmath_uint4 stdmath_uint4_yxzw_get(stdmath_uint4* p) { return stdmath_uint4_yxzw(*p); }
inline static stdmath_uint4 stdmath_uint4_yxzw_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->x = value.y; p->z = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_yxwx(stdmath_uint4 v) { return {v.y,v.x,v.w,v.x}; }
inline static stdmath_uint4 stdmath_uint4_yxwx_get(stdmath_uint4* p) { return stdmath_uint4_yxwx(*p); }
inline static stdmath_uint4 stdmath_uint4_yxwx_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->x = value.y; p->w = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_yxwy(stdmath_uint4 v) { return {v.y,v.x,v.w,v.y}; }
inline static stdmath_uint4 stdmath_uint4_yxwy_get(stdmath_uint4* p) { return stdmath_uint4_yxwy(*p); }
inline static stdmath_uint4 stdmath_uint4_yxwy_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->x = value.y; p->w = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_yxwz(stdmath_uint4 v) { return {v.y,v.x,v.w,v.z}; }
inline static stdmath_uint4 stdmath_uint4_yxwz_get(stdmath_uint4* p) { return stdmath_uint4_yxwz(*p); }
inline static stdmath_uint4 stdmath_uint4_yxwz_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->x = value.y; p->w = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_yxww(stdmath_uint4 v) { return {v.y,v.x,v.w,v.w}; }
inline static stdmath_uint4 stdmath_uint4_yxww_get(stdmath_uint4* p) { return stdmath_uint4_yxww(*p); }
inline static stdmath_uint4 stdmath_uint4_yxww_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->x = value.y; p->w = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_yyxx(stdmath_uint4 v) { return {v.y,v.y,v.x,v.x}; }
inline static stdmath_uint4 stdmath_uint4_yyxx_get(stdmath_uint4* p) { return stdmath_uint4_yyxx(*p); }
inline static stdmath_uint4 stdmath_uint4_yyxx_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->y = value.y; p->x = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_yyxy(stdmath_uint4 v) { return {v.y,v.y,v.x,v.y}; }
inline static stdmath_uint4 stdmath_uint4_yyxy_get(stdmath_uint4* p) { return stdmath_uint4_yyxy(*p); }
inline static stdmath_uint4 stdmath_uint4_yyxy_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->y = value.y; p->x = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_yyxz(stdmath_uint4 v) { return {v.y,v.y,v.x,v.z}; }
inline static stdmath_uint4 stdmath_uint4_yyxz_get(stdmath_uint4* p) { return stdmath_uint4_yyxz(*p); }
inline static stdmath_uint4 stdmath_uint4_yyxz_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->y = value.y; p->x = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_yyxw(stdmath_uint4 v) { return {v.y,v.y,v.x,v.w}; }
inline static stdmath_uint4 stdmath_uint4_yyxw_get(stdmath_uint4* p) { return stdmath_uint4_yyxw(*p); }
inline static stdmath_uint4 stdmath_uint4_yyxw_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->y = value.y; p->x = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_yyyx(stdmath_uint4 v) { return {v.y,v.y,v.y,v.x}; }
inline static stdmath_uint4 stdmath_uint4_yyyx_get(stdmath_uint4* p) { return stdmath_uint4_yyyx(*p); }
inline static stdmath_uint4 stdmath_uint4_yyyx_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->y = value.y; p->y = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_yyyy(stdmath_uint4 v) { return {v.y,v.y,v.y,v.y}; }
inline static stdmath_uint4 stdmath_uint4_yyyy_get(stdmath_uint4* p) { return stdmath_uint4_yyyy(*p); }
inline static stdmath_uint4 stdmath_uint4_yyyy_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->y = value.y; p->y = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_yyyz(stdmath_uint4 v) { return {v.y,v.y,v.y,v.z}; }
inline static stdmath_uint4 stdmath_uint4_yyyz_get(stdmath_uint4* p) { return stdmath_uint4_yyyz(*p); }
inline static stdmath_uint4 stdmath_uint4_yyyz_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->y = value.y; p->y = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_yyyw(stdmath_uint4 v) { return {v.y,v.y,v.y,v.w}; }
inline static stdmath_uint4 stdmath_uint4_yyyw_get(stdmath_uint4* p) { return stdmath_uint4_yyyw(*p); }
inline static stdmath_uint4 stdmath_uint4_yyyw_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->y = value.y; p->y = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_yyzx(stdmath_uint4 v) { return {v.y,v.y,v.z,v.x}; }
inline static stdmath_uint4 stdmath_uint4_yyzx_get(stdmath_uint4* p) { return stdmath_uint4_yyzx(*p); }
inline static stdmath_uint4 stdmath_uint4_yyzx_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->y = value.y; p->z = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_yyzy(stdmath_uint4 v) { return {v.y,v.y,v.z,v.y}; }
inline static stdmath_uint4 stdmath_uint4_yyzy_get(stdmath_uint4* p) { return stdmath_uint4_yyzy(*p); }
inline static stdmath_uint4 stdmath_uint4_yyzy_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->y = value.y; p->z = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_yyzz(stdmath_uint4 v) { return {v.y,v.y,v.z,v.z}; }
inline static stdmath_uint4 stdmath_uint4_yyzz_get(stdmath_uint4* p) { return stdmath_uint4_yyzz(*p); }
inline static stdmath_uint4 stdmath_uint4_yyzz_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->y = value.y; p->z = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_yyzw(stdmath_uint4 v) { return {v.y,v.y,v.z,v.w}; }
inline static stdmath_uint4 stdmath_uint4_yyzw_get(stdmath_uint4* p) { return stdmath_uint4_yyzw(*p); }
inline static stdmath_uint4 stdmath_uint4_yyzw_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->y = value.y; p->z = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_yywx(stdmath_uint4 v) { return {v.y,v.y,v.w,v.x}; }
inline static stdmath_uint4 stdmath_uint4_yywx_get(stdmath_uint4* p) { return stdmath_uint4_yywx(*p); }
inline static stdmath_uint4 stdmath_uint4_yywx_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->y = value.y; p->w = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_yywy(stdmath_uint4 v) { return {v.y,v.y,v.w,v.y}; }
inline static stdmath_uint4 stdmath_uint4_yywy_get(stdmath_uint4* p) { return stdmath_uint4_yywy(*p); }
inline static stdmath_uint4 stdmath_uint4_yywy_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->y = value.y; p->w = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_yywz(stdmath_uint4 v) { return {v.y,v.y,v.w,v.z}; }
inline static stdmath_uint4 stdmath_uint4_yywz_get(stdmath_uint4* p) { return stdmath_uint4_yywz(*p); }
inline static stdmath_uint4 stdmath_uint4_yywz_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->y = value.y; p->w = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_yyww(stdmath_uint4 v) { return {v.y,v.y,v.w,v.w}; }
inline static stdmath_uint4 stdmath_uint4_yyww_get(stdmath_uint4* p) { return stdmath_uint4_yyww(*p); }
inline static stdmath_uint4 stdmath_uint4_yyww_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->y = value.y; p->w = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_yzxx(stdmath_uint4 v) { return {v.y,v.z,v.x,v.x}; }
inline static stdmath_uint4 stdmath_uint4_yzxx_get(stdmath_uint4* p) { return stdmath_uint4_yzxx(*p); }
inline static stdmath_uint4 stdmath_uint4_yzxx_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->z = value.y; p->x = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_yzxy(stdmath_uint4 v) { return {v.y,v.z,v.x,v.y}; }
inline static stdmath_uint4 stdmath_uint4_yzxy_get(stdmath_uint4* p) { return stdmath_uint4_yzxy(*p); }
inline static stdmath_uint4 stdmath_uint4_yzxy_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->z = value.y; p->x = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_yzxz(stdmath_uint4 v) { return {v.y,v.z,v.x,v.z}; }
inline static stdmath_uint4 stdmath_uint4_yzxz_get(stdmath_uint4* p) { return stdmath_uint4_yzxz(*p); }
inline static stdmath_uint4 stdmath_uint4_yzxz_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->z = value.y; p->x = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_yzxw(stdmath_uint4 v) { return {v.y,v.z,v.x,v.w}; }
inline static stdmath_uint4 stdmath_uint4_yzxw_get(stdmath_uint4* p) { return stdmath_uint4_yzxw(*p); }
inline static stdmath_uint4 stdmath_uint4_yzxw_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->z = value.y; p->x = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_yzyx(stdmath_uint4 v) { return {v.y,v.z,v.y,v.x}; }
inline static stdmath_uint4 stdmath_uint4_yzyx_get(stdmath_uint4* p) { return stdmath_uint4_yzyx(*p); }
inline static stdmath_uint4 stdmath_uint4_yzyx_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->z = value.y; p->y = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_yzyy(stdmath_uint4 v) { return {v.y,v.z,v.y,v.y}; }
inline static stdmath_uint4 stdmath_uint4_yzyy_get(stdmath_uint4* p) { return stdmath_uint4_yzyy(*p); }
inline static stdmath_uint4 stdmath_uint4_yzyy_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->z = value.y; p->y = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_yzyz(stdmath_uint4 v) { return {v.y,v.z,v.y,v.z}; }
inline static stdmath_uint4 stdmath_uint4_yzyz_get(stdmath_uint4* p) { return stdmath_uint4_yzyz(*p); }
inline static stdmath_uint4 stdmath_uint4_yzyz_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->z = value.y; p->y = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_yzyw(stdmath_uint4 v) { return {v.y,v.z,v.y,v.w}; }
inline static stdmath_uint4 stdmath_uint4_yzyw_get(stdmath_uint4* p) { return stdmath_uint4_yzyw(*p); }
inline static stdmath_uint4 stdmath_uint4_yzyw_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->z = value.y; p->y = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_yzzx(stdmath_uint4 v) { return {v.y,v.z,v.z,v.x}; }
inline static stdmath_uint4 stdmath_uint4_yzzx_get(stdmath_uint4* p) { return stdmath_uint4_yzzx(*p); }
inline static stdmath_uint4 stdmath_uint4_yzzx_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->z = value.y; p->z = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_yzzy(stdmath_uint4 v) { return {v.y,v.z,v.z,v.y}; }
inline static stdmath_uint4 stdmath_uint4_yzzy_get(stdmath_uint4* p) { return stdmath_uint4_yzzy(*p); }
inline static stdmath_uint4 stdmath_uint4_yzzy_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->z = value.y; p->z = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_yzzz(stdmath_uint4 v) { return {v.y,v.z,v.z,v.z}; }
inline static stdmath_uint4 stdmath_uint4_yzzz_get(stdmath_uint4* p) { return stdmath_uint4_yzzz(*p); }
inline static stdmath_uint4 stdmath_uint4_yzzz_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->z = value.y; p->z = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_yzzw(stdmath_uint4 v) { return {v.y,v.z,v.z,v.w}; }
inline static stdmath_uint4 stdmath_uint4_yzzw_get(stdmath_uint4* p) { return stdmath_uint4_yzzw(*p); }
inline static stdmath_uint4 stdmath_uint4_yzzw_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->z = value.y; p->z = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_yzwx(stdmath_uint4 v) { return {v.y,v.z,v.w,v.x}; }
inline static stdmath_uint4 stdmath_uint4_yzwx_get(stdmath_uint4* p) { return stdmath_uint4_yzwx(*p); }
inline static stdmath_uint4 stdmath_uint4_yzwx_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->z = value.y; p->w = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_yzwy(stdmath_uint4 v) { return {v.y,v.z,v.w,v.y}; }
inline static stdmath_uint4 stdmath_uint4_yzwy_get(stdmath_uint4* p) { return stdmath_uint4_yzwy(*p); }
inline static stdmath_uint4 stdmath_uint4_yzwy_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->z = value.y; p->w = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_yzwz(stdmath_uint4 v) { return {v.y,v.z,v.w,v.z}; }
inline static stdmath_uint4 stdmath_uint4_yzwz_get(stdmath_uint4* p) { return stdmath_uint4_yzwz(*p); }
inline static stdmath_uint4 stdmath_uint4_yzwz_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->z = value.y; p->w = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_yzww(stdmath_uint4 v) { return {v.y,v.z,v.w,v.w}; }
inline static stdmath_uint4 stdmath_uint4_yzww_get(stdmath_uint4* p) { return stdmath_uint4_yzww(*p); }
inline static stdmath_uint4 stdmath_uint4_yzww_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->z = value.y; p->w = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_ywxx(stdmath_uint4 v) { return {v.y,v.w,v.x,v.x}; }
inline static stdmath_uint4 stdmath_uint4_ywxx_get(stdmath_uint4* p) { return stdmath_uint4_ywxx(*p); }
inline static stdmath_uint4 stdmath_uint4_ywxx_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->w = value.y; p->x = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_ywxy(stdmath_uint4 v) { return {v.y,v.w,v.x,v.y}; }
inline static stdmath_uint4 stdmath_uint4_ywxy_get(stdmath_uint4* p) { return stdmath_uint4_ywxy(*p); }
inline static stdmath_uint4 stdmath_uint4_ywxy_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->w = value.y; p->x = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_ywxz(stdmath_uint4 v) { return {v.y,v.w,v.x,v.z}; }
inline static stdmath_uint4 stdmath_uint4_ywxz_get(stdmath_uint4* p) { return stdmath_uint4_ywxz(*p); }
inline static stdmath_uint4 stdmath_uint4_ywxz_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->w = value.y; p->x = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_ywxw(stdmath_uint4 v) { return {v.y,v.w,v.x,v.w}; }
inline static stdmath_uint4 stdmath_uint4_ywxw_get(stdmath_uint4* p) { return stdmath_uint4_ywxw(*p); }
inline static stdmath_uint4 stdmath_uint4_ywxw_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->w = value.y; p->x = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_ywyx(stdmath_uint4 v) { return {v.y,v.w,v.y,v.x}; }
inline static stdmath_uint4 stdmath_uint4_ywyx_get(stdmath_uint4* p) { return stdmath_uint4_ywyx(*p); }
inline static stdmath_uint4 stdmath_uint4_ywyx_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->w = value.y; p->y = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_ywyy(stdmath_uint4 v) { return {v.y,v.w,v.y,v.y}; }
inline static stdmath_uint4 stdmath_uint4_ywyy_get(stdmath_uint4* p) { return stdmath_uint4_ywyy(*p); }
inline static stdmath_uint4 stdmath_uint4_ywyy_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->w = value.y; p->y = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_ywyz(stdmath_uint4 v) { return {v.y,v.w,v.y,v.z}; }
inline static stdmath_uint4 stdmath_uint4_ywyz_get(stdmath_uint4* p) { return stdmath_uint4_ywyz(*p); }
inline static stdmath_uint4 stdmath_uint4_ywyz_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->w = value.y; p->y = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_ywyw(stdmath_uint4 v) { return {v.y,v.w,v.y,v.w}; }
inline static stdmath_uint4 stdmath_uint4_ywyw_get(stdmath_uint4* p) { return stdmath_uint4_ywyw(*p); }
inline static stdmath_uint4 stdmath_uint4_ywyw_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->w = value.y; p->y = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_ywzx(stdmath_uint4 v) { return {v.y,v.w,v.z,v.x}; }
inline static stdmath_uint4 stdmath_uint4_ywzx_get(stdmath_uint4* p) { return stdmath_uint4_ywzx(*p); }
inline static stdmath_uint4 stdmath_uint4_ywzx_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->w = value.y; p->z = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_ywzy(stdmath_uint4 v) { return {v.y,v.w,v.z,v.y}; }
inline static stdmath_uint4 stdmath_uint4_ywzy_get(stdmath_uint4* p) { return stdmath_uint4_ywzy(*p); }
inline static stdmath_uint4 stdmath_uint4_ywzy_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->w = value.y; p->z = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_ywzz(stdmath_uint4 v) { return {v.y,v.w,v.z,v.z}; }
inline static stdmath_uint4 stdmath_uint4_ywzz_get(stdmath_uint4* p) { return stdmath_uint4_ywzz(*p); }
inline static stdmath_uint4 stdmath_uint4_ywzz_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->w = value.y; p->z = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_ywzw(stdmath_uint4 v) { return {v.y,v.w,v.z,v.w}; }
inline static stdmath_uint4 stdmath_uint4_ywzw_get(stdmath_uint4* p) { return stdmath_uint4_ywzw(*p); }
inline static stdmath_uint4 stdmath_uint4_ywzw_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->w = value.y; p->z = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_ywwx(stdmath_uint4 v) { return {v.y,v.w,v.w,v.x}; }
inline static stdmath_uint4 stdmath_uint4_ywwx_get(stdmath_uint4* p) { return stdmath_uint4_ywwx(*p); }
inline static stdmath_uint4 stdmath_uint4_ywwx_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->w = value.y; p->w = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_ywwy(stdmath_uint4 v) { return {v.y,v.w,v.w,v.y}; }
inline static stdmath_uint4 stdmath_uint4_ywwy_get(stdmath_uint4* p) { return stdmath_uint4_ywwy(*p); }
inline static stdmath_uint4 stdmath_uint4_ywwy_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->w = value.y; p->w = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_ywwz(stdmath_uint4 v) { return {v.y,v.w,v.w,v.z}; }
inline static stdmath_uint4 stdmath_uint4_ywwz_get(stdmath_uint4* p) { return stdmath_uint4_ywwz(*p); }
inline static stdmath_uint4 stdmath_uint4_ywwz_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->w = value.y; p->w = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_ywww(stdmath_uint4 v) { return {v.y,v.w,v.w,v.w}; }
inline static stdmath_uint4 stdmath_uint4_ywww_get(stdmath_uint4* p) { return stdmath_uint4_ywww(*p); }
inline static stdmath_uint4 stdmath_uint4_ywww_set(stdmath_uint4* p, stdmath_uint4 value) { p->y = value.x; p->w = value.y; p->w = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zxxx(stdmath_uint4 v) { return {v.z,v.x,v.x,v.x}; }
inline static stdmath_uint4 stdmath_uint4_zxxx_get(stdmath_uint4* p) { return stdmath_uint4_zxxx(*p); }
inline static stdmath_uint4 stdmath_uint4_zxxx_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->x = value.y; p->x = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zxxy(stdmath_uint4 v) { return {v.z,v.x,v.x,v.y}; }
inline static stdmath_uint4 stdmath_uint4_zxxy_get(stdmath_uint4* p) { return stdmath_uint4_zxxy(*p); }
inline static stdmath_uint4 stdmath_uint4_zxxy_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->x = value.y; p->x = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zxxz(stdmath_uint4 v) { return {v.z,v.x,v.x,v.z}; }
inline static stdmath_uint4 stdmath_uint4_zxxz_get(stdmath_uint4* p) { return stdmath_uint4_zxxz(*p); }
inline static stdmath_uint4 stdmath_uint4_zxxz_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->x = value.y; p->x = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zxxw(stdmath_uint4 v) { return {v.z,v.x,v.x,v.w}; }
inline static stdmath_uint4 stdmath_uint4_zxxw_get(stdmath_uint4* p) { return stdmath_uint4_zxxw(*p); }
inline static stdmath_uint4 stdmath_uint4_zxxw_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->x = value.y; p->x = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zxyx(stdmath_uint4 v) { return {v.z,v.x,v.y,v.x}; }
inline static stdmath_uint4 stdmath_uint4_zxyx_get(stdmath_uint4* p) { return stdmath_uint4_zxyx(*p); }
inline static stdmath_uint4 stdmath_uint4_zxyx_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->x = value.y; p->y = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zxyy(stdmath_uint4 v) { return {v.z,v.x,v.y,v.y}; }
inline static stdmath_uint4 stdmath_uint4_zxyy_get(stdmath_uint4* p) { return stdmath_uint4_zxyy(*p); }
inline static stdmath_uint4 stdmath_uint4_zxyy_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->x = value.y; p->y = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zxyz(stdmath_uint4 v) { return {v.z,v.x,v.y,v.z}; }
inline static stdmath_uint4 stdmath_uint4_zxyz_get(stdmath_uint4* p) { return stdmath_uint4_zxyz(*p); }
inline static stdmath_uint4 stdmath_uint4_zxyz_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->x = value.y; p->y = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zxyw(stdmath_uint4 v) { return {v.z,v.x,v.y,v.w}; }
inline static stdmath_uint4 stdmath_uint4_zxyw_get(stdmath_uint4* p) { return stdmath_uint4_zxyw(*p); }
inline static stdmath_uint4 stdmath_uint4_zxyw_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->x = value.y; p->y = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zxzx(stdmath_uint4 v) { return {v.z,v.x,v.z,v.x}; }
inline static stdmath_uint4 stdmath_uint4_zxzx_get(stdmath_uint4* p) { return stdmath_uint4_zxzx(*p); }
inline static stdmath_uint4 stdmath_uint4_zxzx_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->x = value.y; p->z = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zxzy(stdmath_uint4 v) { return {v.z,v.x,v.z,v.y}; }
inline static stdmath_uint4 stdmath_uint4_zxzy_get(stdmath_uint4* p) { return stdmath_uint4_zxzy(*p); }
inline static stdmath_uint4 stdmath_uint4_zxzy_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->x = value.y; p->z = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zxzz(stdmath_uint4 v) { return {v.z,v.x,v.z,v.z}; }
inline static stdmath_uint4 stdmath_uint4_zxzz_get(stdmath_uint4* p) { return stdmath_uint4_zxzz(*p); }
inline static stdmath_uint4 stdmath_uint4_zxzz_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->x = value.y; p->z = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zxzw(stdmath_uint4 v) { return {v.z,v.x,v.z,v.w}; }
inline static stdmath_uint4 stdmath_uint4_zxzw_get(stdmath_uint4* p) { return stdmath_uint4_zxzw(*p); }
inline static stdmath_uint4 stdmath_uint4_zxzw_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->x = value.y; p->z = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zxwx(stdmath_uint4 v) { return {v.z,v.x,v.w,v.x}; }
inline static stdmath_uint4 stdmath_uint4_zxwx_get(stdmath_uint4* p) { return stdmath_uint4_zxwx(*p); }
inline static stdmath_uint4 stdmath_uint4_zxwx_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->x = value.y; p->w = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zxwy(stdmath_uint4 v) { return {v.z,v.x,v.w,v.y}; }
inline static stdmath_uint4 stdmath_uint4_zxwy_get(stdmath_uint4* p) { return stdmath_uint4_zxwy(*p); }
inline static stdmath_uint4 stdmath_uint4_zxwy_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->x = value.y; p->w = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zxwz(stdmath_uint4 v) { return {v.z,v.x,v.w,v.z}; }
inline static stdmath_uint4 stdmath_uint4_zxwz_get(stdmath_uint4* p) { return stdmath_uint4_zxwz(*p); }
inline static stdmath_uint4 stdmath_uint4_zxwz_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->x = value.y; p->w = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zxww(stdmath_uint4 v) { return {v.z,v.x,v.w,v.w}; }
inline static stdmath_uint4 stdmath_uint4_zxww_get(stdmath_uint4* p) { return stdmath_uint4_zxww(*p); }
inline static stdmath_uint4 stdmath_uint4_zxww_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->x = value.y; p->w = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zyxx(stdmath_uint4 v) { return {v.z,v.y,v.x,v.x}; }
inline static stdmath_uint4 stdmath_uint4_zyxx_get(stdmath_uint4* p) { return stdmath_uint4_zyxx(*p); }
inline static stdmath_uint4 stdmath_uint4_zyxx_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->y = value.y; p->x = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zyxy(stdmath_uint4 v) { return {v.z,v.y,v.x,v.y}; }
inline static stdmath_uint4 stdmath_uint4_zyxy_get(stdmath_uint4* p) { return stdmath_uint4_zyxy(*p); }
inline static stdmath_uint4 stdmath_uint4_zyxy_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->y = value.y; p->x = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zyxz(stdmath_uint4 v) { return {v.z,v.y,v.x,v.z}; }
inline static stdmath_uint4 stdmath_uint4_zyxz_get(stdmath_uint4* p) { return stdmath_uint4_zyxz(*p); }
inline static stdmath_uint4 stdmath_uint4_zyxz_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->y = value.y; p->x = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zyxw(stdmath_uint4 v) { return {v.z,v.y,v.x,v.w}; }
inline static stdmath_uint4 stdmath_uint4_zyxw_get(stdmath_uint4* p) { return stdmath_uint4_zyxw(*p); }
inline static stdmath_uint4 stdmath_uint4_zyxw_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->y = value.y; p->x = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zyyx(stdmath_uint4 v) { return {v.z,v.y,v.y,v.x}; }
inline static stdmath_uint4 stdmath_uint4_zyyx_get(stdmath_uint4* p) { return stdmath_uint4_zyyx(*p); }
inline static stdmath_uint4 stdmath_uint4_zyyx_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->y = value.y; p->y = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zyyy(stdmath_uint4 v) { return {v.z,v.y,v.y,v.y}; }
inline static stdmath_uint4 stdmath_uint4_zyyy_get(stdmath_uint4* p) { return stdmath_uint4_zyyy(*p); }
inline static stdmath_uint4 stdmath_uint4_zyyy_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->y = value.y; p->y = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zyyz(stdmath_uint4 v) { return {v.z,v.y,v.y,v.z}; }
inline static stdmath_uint4 stdmath_uint4_zyyz_get(stdmath_uint4* p) { return stdmath_uint4_zyyz(*p); }
inline static stdmath_uint4 stdmath_uint4_zyyz_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->y = value.y; p->y = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zyyw(stdmath_uint4 v) { return {v.z,v.y,v.y,v.w}; }
inline static stdmath_uint4 stdmath_uint4_zyyw_get(stdmath_uint4* p) { return stdmath_uint4_zyyw(*p); }
inline static stdmath_uint4 stdmath_uint4_zyyw_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->y = value.y; p->y = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zyzx(stdmath_uint4 v) { return {v.z,v.y,v.z,v.x}; }
inline static stdmath_uint4 stdmath_uint4_zyzx_get(stdmath_uint4* p) { return stdmath_uint4_zyzx(*p); }
inline static stdmath_uint4 stdmath_uint4_zyzx_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->y = value.y; p->z = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zyzy(stdmath_uint4 v) { return {v.z,v.y,v.z,v.y}; }
inline static stdmath_uint4 stdmath_uint4_zyzy_get(stdmath_uint4* p) { return stdmath_uint4_zyzy(*p); }
inline static stdmath_uint4 stdmath_uint4_zyzy_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->y = value.y; p->z = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zyzz(stdmath_uint4 v) { return {v.z,v.y,v.z,v.z}; }
inline static stdmath_uint4 stdmath_uint4_zyzz_get(stdmath_uint4* p) { return stdmath_uint4_zyzz(*p); }
inline static stdmath_uint4 stdmath_uint4_zyzz_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->y = value.y; p->z = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zyzw(stdmath_uint4 v) { return {v.z,v.y,v.z,v.w}; }
inline static stdmath_uint4 stdmath_uint4_zyzw_get(stdmath_uint4* p) { return stdmath_uint4_zyzw(*p); }
inline static stdmath_uint4 stdmath_uint4_zyzw_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->y = value.y; p->z = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zywx(stdmath_uint4 v) { return {v.z,v.y,v.w,v.x}; }
inline static stdmath_uint4 stdmath_uint4_zywx_get(stdmath_uint4* p) { return stdmath_uint4_zywx(*p); }
inline static stdmath_uint4 stdmath_uint4_zywx_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->y = value.y; p->w = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zywy(stdmath_uint4 v) { return {v.z,v.y,v.w,v.y}; }
inline static stdmath_uint4 stdmath_uint4_zywy_get(stdmath_uint4* p) { return stdmath_uint4_zywy(*p); }
inline static stdmath_uint4 stdmath_uint4_zywy_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->y = value.y; p->w = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zywz(stdmath_uint4 v) { return {v.z,v.y,v.w,v.z}; }
inline static stdmath_uint4 stdmath_uint4_zywz_get(stdmath_uint4* p) { return stdmath_uint4_zywz(*p); }
inline static stdmath_uint4 stdmath_uint4_zywz_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->y = value.y; p->w = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zyww(stdmath_uint4 v) { return {v.z,v.y,v.w,v.w}; }
inline static stdmath_uint4 stdmath_uint4_zyww_get(stdmath_uint4* p) { return stdmath_uint4_zyww(*p); }
inline static stdmath_uint4 stdmath_uint4_zyww_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->y = value.y; p->w = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zzxx(stdmath_uint4 v) { return {v.z,v.z,v.x,v.x}; }
inline static stdmath_uint4 stdmath_uint4_zzxx_get(stdmath_uint4* p) { return stdmath_uint4_zzxx(*p); }
inline static stdmath_uint4 stdmath_uint4_zzxx_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->z = value.y; p->x = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zzxy(stdmath_uint4 v) { return {v.z,v.z,v.x,v.y}; }
inline static stdmath_uint4 stdmath_uint4_zzxy_get(stdmath_uint4* p) { return stdmath_uint4_zzxy(*p); }
inline static stdmath_uint4 stdmath_uint4_zzxy_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->z = value.y; p->x = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zzxz(stdmath_uint4 v) { return {v.z,v.z,v.x,v.z}; }
inline static stdmath_uint4 stdmath_uint4_zzxz_get(stdmath_uint4* p) { return stdmath_uint4_zzxz(*p); }
inline static stdmath_uint4 stdmath_uint4_zzxz_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->z = value.y; p->x = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zzxw(stdmath_uint4 v) { return {v.z,v.z,v.x,v.w}; }
inline static stdmath_uint4 stdmath_uint4_zzxw_get(stdmath_uint4* p) { return stdmath_uint4_zzxw(*p); }
inline static stdmath_uint4 stdmath_uint4_zzxw_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->z = value.y; p->x = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zzyx(stdmath_uint4 v) { return {v.z,v.z,v.y,v.x}; }
inline static stdmath_uint4 stdmath_uint4_zzyx_get(stdmath_uint4* p) { return stdmath_uint4_zzyx(*p); }
inline static stdmath_uint4 stdmath_uint4_zzyx_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->z = value.y; p->y = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zzyy(stdmath_uint4 v) { return {v.z,v.z,v.y,v.y}; }
inline static stdmath_uint4 stdmath_uint4_zzyy_get(stdmath_uint4* p) { return stdmath_uint4_zzyy(*p); }
inline static stdmath_uint4 stdmath_uint4_zzyy_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->z = value.y; p->y = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zzyz(stdmath_uint4 v) { return {v.z,v.z,v.y,v.z}; }
inline static stdmath_uint4 stdmath_uint4_zzyz_get(stdmath_uint4* p) { return stdmath_uint4_zzyz(*p); }
inline static stdmath_uint4 stdmath_uint4_zzyz_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->z = value.y; p->y = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zzyw(stdmath_uint4 v) { return {v.z,v.z,v.y,v.w}; }
inline static stdmath_uint4 stdmath_uint4_zzyw_get(stdmath_uint4* p) { return stdmath_uint4_zzyw(*p); }
inline static stdmath_uint4 stdmath_uint4_zzyw_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->z = value.y; p->y = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zzzx(stdmath_uint4 v) { return {v.z,v.z,v.z,v.x}; }
inline static stdmath_uint4 stdmath_uint4_zzzx_get(stdmath_uint4* p) { return stdmath_uint4_zzzx(*p); }
inline static stdmath_uint4 stdmath_uint4_zzzx_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->z = value.y; p->z = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zzzy(stdmath_uint4 v) { return {v.z,v.z,v.z,v.y}; }
inline static stdmath_uint4 stdmath_uint4_zzzy_get(stdmath_uint4* p) { return stdmath_uint4_zzzy(*p); }
inline static stdmath_uint4 stdmath_uint4_zzzy_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->z = value.y; p->z = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zzzz(stdmath_uint4 v) { return {v.z,v.z,v.z,v.z}; }
inline static stdmath_uint4 stdmath_uint4_zzzz_get(stdmath_uint4* p) { return stdmath_uint4_zzzz(*p); }
inline static stdmath_uint4 stdmath_uint4_zzzz_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->z = value.y; p->z = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zzzw(stdmath_uint4 v) { return {v.z,v.z,v.z,v.w}; }
inline static stdmath_uint4 stdmath_uint4_zzzw_get(stdmath_uint4* p) { return stdmath_uint4_zzzw(*p); }
inline static stdmath_uint4 stdmath_uint4_zzzw_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->z = value.y; p->z = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zzwx(stdmath_uint4 v) { return {v.z,v.z,v.w,v.x}; }
inline static stdmath_uint4 stdmath_uint4_zzwx_get(stdmath_uint4* p) { return stdmath_uint4_zzwx(*p); }
inline static stdmath_uint4 stdmath_uint4_zzwx_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->z = value.y; p->w = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zzwy(stdmath_uint4 v) { return {v.z,v.z,v.w,v.y}; }
inline static stdmath_uint4 stdmath_uint4_zzwy_get(stdmath_uint4* p) { return stdmath_uint4_zzwy(*p); }
inline static stdmath_uint4 stdmath_uint4_zzwy_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->z = value.y; p->w = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zzwz(stdmath_uint4 v) { return {v.z,v.z,v.w,v.z}; }
inline static stdmath_uint4 stdmath_uint4_zzwz_get(stdmath_uint4* p) { return stdmath_uint4_zzwz(*p); }
inline static stdmath_uint4 stdmath_uint4_zzwz_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->z = value.y; p->w = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zzww(stdmath_uint4 v) { return {v.z,v.z,v.w,v.w}; }
inline static stdmath_uint4 stdmath_uint4_zzww_get(stdmath_uint4* p) { return stdmath_uint4_zzww(*p); }
inline static stdmath_uint4 stdmath_uint4_zzww_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->z = value.y; p->w = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zwxx(stdmath_uint4 v) { return {v.z,v.w,v.x,v.x}; }
inline static stdmath_uint4 stdmath_uint4_zwxx_get(stdmath_uint4* p) { return stdmath_uint4_zwxx(*p); }
inline static stdmath_uint4 stdmath_uint4_zwxx_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->w = value.y; p->x = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zwxy(stdmath_uint4 v) { return {v.z,v.w,v.x,v.y}; }
inline static stdmath_uint4 stdmath_uint4_zwxy_get(stdmath_uint4* p) { return stdmath_uint4_zwxy(*p); }
inline static stdmath_uint4 stdmath_uint4_zwxy_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->w = value.y; p->x = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zwxz(stdmath_uint4 v) { return {v.z,v.w,v.x,v.z}; }
inline static stdmath_uint4 stdmath_uint4_zwxz_get(stdmath_uint4* p) { return stdmath_uint4_zwxz(*p); }
inline static stdmath_uint4 stdmath_uint4_zwxz_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->w = value.y; p->x = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zwxw(stdmath_uint4 v) { return {v.z,v.w,v.x,v.w}; }
inline static stdmath_uint4 stdmath_uint4_zwxw_get(stdmath_uint4* p) { return stdmath_uint4_zwxw(*p); }
inline static stdmath_uint4 stdmath_uint4_zwxw_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->w = value.y; p->x = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zwyx(stdmath_uint4 v) { return {v.z,v.w,v.y,v.x}; }
inline static stdmath_uint4 stdmath_uint4_zwyx_get(stdmath_uint4* p) { return stdmath_uint4_zwyx(*p); }
inline static stdmath_uint4 stdmath_uint4_zwyx_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->w = value.y; p->y = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zwyy(stdmath_uint4 v) { return {v.z,v.w,v.y,v.y}; }
inline static stdmath_uint4 stdmath_uint4_zwyy_get(stdmath_uint4* p) { return stdmath_uint4_zwyy(*p); }
inline static stdmath_uint4 stdmath_uint4_zwyy_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->w = value.y; p->y = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zwyz(stdmath_uint4 v) { return {v.z,v.w,v.y,v.z}; }
inline static stdmath_uint4 stdmath_uint4_zwyz_get(stdmath_uint4* p) { return stdmath_uint4_zwyz(*p); }
inline static stdmath_uint4 stdmath_uint4_zwyz_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->w = value.y; p->y = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zwyw(stdmath_uint4 v) { return {v.z,v.w,v.y,v.w}; }
inline static stdmath_uint4 stdmath_uint4_zwyw_get(stdmath_uint4* p) { return stdmath_uint4_zwyw(*p); }
inline static stdmath_uint4 stdmath_uint4_zwyw_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->w = value.y; p->y = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zwzx(stdmath_uint4 v) { return {v.z,v.w,v.z,v.x}; }
inline static stdmath_uint4 stdmath_uint4_zwzx_get(stdmath_uint4* p) { return stdmath_uint4_zwzx(*p); }
inline static stdmath_uint4 stdmath_uint4_zwzx_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->w = value.y; p->z = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zwzy(stdmath_uint4 v) { return {v.z,v.w,v.z,v.y}; }
inline static stdmath_uint4 stdmath_uint4_zwzy_get(stdmath_uint4* p) { return stdmath_uint4_zwzy(*p); }
inline static stdmath_uint4 stdmath_uint4_zwzy_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->w = value.y; p->z = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zwzz(stdmath_uint4 v) { return {v.z,v.w,v.z,v.z}; }
inline static stdmath_uint4 stdmath_uint4_zwzz_get(stdmath_uint4* p) { return stdmath_uint4_zwzz(*p); }
inline static stdmath_uint4 stdmath_uint4_zwzz_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->w = value.y; p->z = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zwzw(stdmath_uint4 v) { return {v.z,v.w,v.z,v.w}; }
inline static stdmath_uint4 stdmath_uint4_zwzw_get(stdmath_uint4* p) { return stdmath_uint4_zwzw(*p); }
inline static stdmath_uint4 stdmath_uint4_zwzw_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->w = value.y; p->z = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zwwx(stdmath_uint4 v) { return {v.z,v.w,v.w,v.x}; }
inline static stdmath_uint4 stdmath_uint4_zwwx_get(stdmath_uint4* p) { return stdmath_uint4_zwwx(*p); }
inline static stdmath_uint4 stdmath_uint4_zwwx_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->w = value.y; p->w = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zwwy(stdmath_uint4 v) { return {v.z,v.w,v.w,v.y}; }
inline static stdmath_uint4 stdmath_uint4_zwwy_get(stdmath_uint4* p) { return stdmath_uint4_zwwy(*p); }
inline static stdmath_uint4 stdmath_uint4_zwwy_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->w = value.y; p->w = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zwwz(stdmath_uint4 v) { return {v.z,v.w,v.w,v.z}; }
inline static stdmath_uint4 stdmath_uint4_zwwz_get(stdmath_uint4* p) { return stdmath_uint4_zwwz(*p); }
inline static stdmath_uint4 stdmath_uint4_zwwz_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->w = value.y; p->w = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_zwww(stdmath_uint4 v) { return {v.z,v.w,v.w,v.w}; }
inline static stdmath_uint4 stdmath_uint4_zwww_get(stdmath_uint4* p) { return stdmath_uint4_zwww(*p); }
inline static stdmath_uint4 stdmath_uint4_zwww_set(stdmath_uint4* p, stdmath_uint4 value) { p->z = value.x; p->w = value.y; p->w = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wxxx(stdmath_uint4 v) { return {v.w,v.x,v.x,v.x}; }
inline static stdmath_uint4 stdmath_uint4_wxxx_get(stdmath_uint4* p) { return stdmath_uint4_wxxx(*p); }
inline static stdmath_uint4 stdmath_uint4_wxxx_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->x = value.y; p->x = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wxxy(stdmath_uint4 v) { return {v.w,v.x,v.x,v.y}; }
inline static stdmath_uint4 stdmath_uint4_wxxy_get(stdmath_uint4* p) { return stdmath_uint4_wxxy(*p); }
inline static stdmath_uint4 stdmath_uint4_wxxy_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->x = value.y; p->x = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wxxz(stdmath_uint4 v) { return {v.w,v.x,v.x,v.z}; }
inline static stdmath_uint4 stdmath_uint4_wxxz_get(stdmath_uint4* p) { return stdmath_uint4_wxxz(*p); }
inline static stdmath_uint4 stdmath_uint4_wxxz_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->x = value.y; p->x = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wxxw(stdmath_uint4 v) { return {v.w,v.x,v.x,v.w}; }
inline static stdmath_uint4 stdmath_uint4_wxxw_get(stdmath_uint4* p) { return stdmath_uint4_wxxw(*p); }
inline static stdmath_uint4 stdmath_uint4_wxxw_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->x = value.y; p->x = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wxyx(stdmath_uint4 v) { return {v.w,v.x,v.y,v.x}; }
inline static stdmath_uint4 stdmath_uint4_wxyx_get(stdmath_uint4* p) { return stdmath_uint4_wxyx(*p); }
inline static stdmath_uint4 stdmath_uint4_wxyx_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->x = value.y; p->y = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wxyy(stdmath_uint4 v) { return {v.w,v.x,v.y,v.y}; }
inline static stdmath_uint4 stdmath_uint4_wxyy_get(stdmath_uint4* p) { return stdmath_uint4_wxyy(*p); }
inline static stdmath_uint4 stdmath_uint4_wxyy_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->x = value.y; p->y = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wxyz(stdmath_uint4 v) { return {v.w,v.x,v.y,v.z}; }
inline static stdmath_uint4 stdmath_uint4_wxyz_get(stdmath_uint4* p) { return stdmath_uint4_wxyz(*p); }
inline static stdmath_uint4 stdmath_uint4_wxyz_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->x = value.y; p->y = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wxyw(stdmath_uint4 v) { return {v.w,v.x,v.y,v.w}; }
inline static stdmath_uint4 stdmath_uint4_wxyw_get(stdmath_uint4* p) { return stdmath_uint4_wxyw(*p); }
inline static stdmath_uint4 stdmath_uint4_wxyw_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->x = value.y; p->y = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wxzx(stdmath_uint4 v) { return {v.w,v.x,v.z,v.x}; }
inline static stdmath_uint4 stdmath_uint4_wxzx_get(stdmath_uint4* p) { return stdmath_uint4_wxzx(*p); }
inline static stdmath_uint4 stdmath_uint4_wxzx_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->x = value.y; p->z = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wxzy(stdmath_uint4 v) { return {v.w,v.x,v.z,v.y}; }
inline static stdmath_uint4 stdmath_uint4_wxzy_get(stdmath_uint4* p) { return stdmath_uint4_wxzy(*p); }
inline static stdmath_uint4 stdmath_uint4_wxzy_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->x = value.y; p->z = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wxzz(stdmath_uint4 v) { return {v.w,v.x,v.z,v.z}; }
inline static stdmath_uint4 stdmath_uint4_wxzz_get(stdmath_uint4* p) { return stdmath_uint4_wxzz(*p); }
inline static stdmath_uint4 stdmath_uint4_wxzz_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->x = value.y; p->z = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wxzw(stdmath_uint4 v) { return {v.w,v.x,v.z,v.w}; }
inline static stdmath_uint4 stdmath_uint4_wxzw_get(stdmath_uint4* p) { return stdmath_uint4_wxzw(*p); }
inline static stdmath_uint4 stdmath_uint4_wxzw_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->x = value.y; p->z = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wxwx(stdmath_uint4 v) { return {v.w,v.x,v.w,v.x}; }
inline static stdmath_uint4 stdmath_uint4_wxwx_get(stdmath_uint4* p) { return stdmath_uint4_wxwx(*p); }
inline static stdmath_uint4 stdmath_uint4_wxwx_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->x = value.y; p->w = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wxwy(stdmath_uint4 v) { return {v.w,v.x,v.w,v.y}; }
inline static stdmath_uint4 stdmath_uint4_wxwy_get(stdmath_uint4* p) { return stdmath_uint4_wxwy(*p); }
inline static stdmath_uint4 stdmath_uint4_wxwy_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->x = value.y; p->w = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wxwz(stdmath_uint4 v) { return {v.w,v.x,v.w,v.z}; }
inline static stdmath_uint4 stdmath_uint4_wxwz_get(stdmath_uint4* p) { return stdmath_uint4_wxwz(*p); }
inline static stdmath_uint4 stdmath_uint4_wxwz_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->x = value.y; p->w = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wxww(stdmath_uint4 v) { return {v.w,v.x,v.w,v.w}; }
inline static stdmath_uint4 stdmath_uint4_wxww_get(stdmath_uint4* p) { return stdmath_uint4_wxww(*p); }
inline static stdmath_uint4 stdmath_uint4_wxww_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->x = value.y; p->w = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wyxx(stdmath_uint4 v) { return {v.w,v.y,v.x,v.x}; }
inline static stdmath_uint4 stdmath_uint4_wyxx_get(stdmath_uint4* p) { return stdmath_uint4_wyxx(*p); }
inline static stdmath_uint4 stdmath_uint4_wyxx_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->y = value.y; p->x = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wyxy(stdmath_uint4 v) { return {v.w,v.y,v.x,v.y}; }
inline static stdmath_uint4 stdmath_uint4_wyxy_get(stdmath_uint4* p) { return stdmath_uint4_wyxy(*p); }
inline static stdmath_uint4 stdmath_uint4_wyxy_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->y = value.y; p->x = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wyxz(stdmath_uint4 v) { return {v.w,v.y,v.x,v.z}; }
inline static stdmath_uint4 stdmath_uint4_wyxz_get(stdmath_uint4* p) { return stdmath_uint4_wyxz(*p); }
inline static stdmath_uint4 stdmath_uint4_wyxz_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->y = value.y; p->x = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wyxw(stdmath_uint4 v) { return {v.w,v.y,v.x,v.w}; }
inline static stdmath_uint4 stdmath_uint4_wyxw_get(stdmath_uint4* p) { return stdmath_uint4_wyxw(*p); }
inline static stdmath_uint4 stdmath_uint4_wyxw_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->y = value.y; p->x = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wyyx(stdmath_uint4 v) { return {v.w,v.y,v.y,v.x}; }
inline static stdmath_uint4 stdmath_uint4_wyyx_get(stdmath_uint4* p) { return stdmath_uint4_wyyx(*p); }
inline static stdmath_uint4 stdmath_uint4_wyyx_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->y = value.y; p->y = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wyyy(stdmath_uint4 v) { return {v.w,v.y,v.y,v.y}; }
inline static stdmath_uint4 stdmath_uint4_wyyy_get(stdmath_uint4* p) { return stdmath_uint4_wyyy(*p); }
inline static stdmath_uint4 stdmath_uint4_wyyy_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->y = value.y; p->y = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wyyz(stdmath_uint4 v) { return {v.w,v.y,v.y,v.z}; }
inline static stdmath_uint4 stdmath_uint4_wyyz_get(stdmath_uint4* p) { return stdmath_uint4_wyyz(*p); }
inline static stdmath_uint4 stdmath_uint4_wyyz_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->y = value.y; p->y = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wyyw(stdmath_uint4 v) { return {v.w,v.y,v.y,v.w}; }
inline static stdmath_uint4 stdmath_uint4_wyyw_get(stdmath_uint4* p) { return stdmath_uint4_wyyw(*p); }
inline static stdmath_uint4 stdmath_uint4_wyyw_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->y = value.y; p->y = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wyzx(stdmath_uint4 v) { return {v.w,v.y,v.z,v.x}; }
inline static stdmath_uint4 stdmath_uint4_wyzx_get(stdmath_uint4* p) { return stdmath_uint4_wyzx(*p); }
inline static stdmath_uint4 stdmath_uint4_wyzx_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->y = value.y; p->z = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wyzy(stdmath_uint4 v) { return {v.w,v.y,v.z,v.y}; }
inline static stdmath_uint4 stdmath_uint4_wyzy_get(stdmath_uint4* p) { return stdmath_uint4_wyzy(*p); }
inline static stdmath_uint4 stdmath_uint4_wyzy_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->y = value.y; p->z = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wyzz(stdmath_uint4 v) { return {v.w,v.y,v.z,v.z}; }
inline static stdmath_uint4 stdmath_uint4_wyzz_get(stdmath_uint4* p) { return stdmath_uint4_wyzz(*p); }
inline static stdmath_uint4 stdmath_uint4_wyzz_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->y = value.y; p->z = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wyzw(stdmath_uint4 v) { return {v.w,v.y,v.z,v.w}; }
inline static stdmath_uint4 stdmath_uint4_wyzw_get(stdmath_uint4* p) { return stdmath_uint4_wyzw(*p); }
inline static stdmath_uint4 stdmath_uint4_wyzw_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->y = value.y; p->z = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wywx(stdmath_uint4 v) { return {v.w,v.y,v.w,v.x}; }
inline static stdmath_uint4 stdmath_uint4_wywx_get(stdmath_uint4* p) { return stdmath_uint4_wywx(*p); }
inline static stdmath_uint4 stdmath_uint4_wywx_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->y = value.y; p->w = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wywy(stdmath_uint4 v) { return {v.w,v.y,v.w,v.y}; }
inline static stdmath_uint4 stdmath_uint4_wywy_get(stdmath_uint4* p) { return stdmath_uint4_wywy(*p); }
inline static stdmath_uint4 stdmath_uint4_wywy_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->y = value.y; p->w = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wywz(stdmath_uint4 v) { return {v.w,v.y,v.w,v.z}; }
inline static stdmath_uint4 stdmath_uint4_wywz_get(stdmath_uint4* p) { return stdmath_uint4_wywz(*p); }
inline static stdmath_uint4 stdmath_uint4_wywz_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->y = value.y; p->w = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wyww(stdmath_uint4 v) { return {v.w,v.y,v.w,v.w}; }
inline static stdmath_uint4 stdmath_uint4_wyww_get(stdmath_uint4* p) { return stdmath_uint4_wyww(*p); }
inline static stdmath_uint4 stdmath_uint4_wyww_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->y = value.y; p->w = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wzxx(stdmath_uint4 v) { return {v.w,v.z,v.x,v.x}; }
inline static stdmath_uint4 stdmath_uint4_wzxx_get(stdmath_uint4* p) { return stdmath_uint4_wzxx(*p); }
inline static stdmath_uint4 stdmath_uint4_wzxx_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->z = value.y; p->x = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wzxy(stdmath_uint4 v) { return {v.w,v.z,v.x,v.y}; }
inline static stdmath_uint4 stdmath_uint4_wzxy_get(stdmath_uint4* p) { return stdmath_uint4_wzxy(*p); }
inline static stdmath_uint4 stdmath_uint4_wzxy_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->z = value.y; p->x = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wzxz(stdmath_uint4 v) { return {v.w,v.z,v.x,v.z}; }
inline static stdmath_uint4 stdmath_uint4_wzxz_get(stdmath_uint4* p) { return stdmath_uint4_wzxz(*p); }
inline static stdmath_uint4 stdmath_uint4_wzxz_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->z = value.y; p->x = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wzxw(stdmath_uint4 v) { return {v.w,v.z,v.x,v.w}; }
inline static stdmath_uint4 stdmath_uint4_wzxw_get(stdmath_uint4* p) { return stdmath_uint4_wzxw(*p); }
inline static stdmath_uint4 stdmath_uint4_wzxw_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->z = value.y; p->x = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wzyx(stdmath_uint4 v) { return {v.w,v.z,v.y,v.x}; }
inline static stdmath_uint4 stdmath_uint4_wzyx_get(stdmath_uint4* p) { return stdmath_uint4_wzyx(*p); }
inline static stdmath_uint4 stdmath_uint4_wzyx_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->z = value.y; p->y = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wzyy(stdmath_uint4 v) { return {v.w,v.z,v.y,v.y}; }
inline static stdmath_uint4 stdmath_uint4_wzyy_get(stdmath_uint4* p) { return stdmath_uint4_wzyy(*p); }
inline static stdmath_uint4 stdmath_uint4_wzyy_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->z = value.y; p->y = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wzyz(stdmath_uint4 v) { return {v.w,v.z,v.y,v.z}; }
inline static stdmath_uint4 stdmath_uint4_wzyz_get(stdmath_uint4* p) { return stdmath_uint4_wzyz(*p); }
inline static stdmath_uint4 stdmath_uint4_wzyz_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->z = value.y; p->y = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wzyw(stdmath_uint4 v) { return {v.w,v.z,v.y,v.w}; }
inline static stdmath_uint4 stdmath_uint4_wzyw_get(stdmath_uint4* p) { return stdmath_uint4_wzyw(*p); }
inline static stdmath_uint4 stdmath_uint4_wzyw_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->z = value.y; p->y = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wzzx(stdmath_uint4 v) { return {v.w,v.z,v.z,v.x}; }
inline static stdmath_uint4 stdmath_uint4_wzzx_get(stdmath_uint4* p) { return stdmath_uint4_wzzx(*p); }
inline static stdmath_uint4 stdmath_uint4_wzzx_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->z = value.y; p->z = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wzzy(stdmath_uint4 v) { return {v.w,v.z,v.z,v.y}; }
inline static stdmath_uint4 stdmath_uint4_wzzy_get(stdmath_uint4* p) { return stdmath_uint4_wzzy(*p); }
inline static stdmath_uint4 stdmath_uint4_wzzy_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->z = value.y; p->z = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wzzz(stdmath_uint4 v) { return {v.w,v.z,v.z,v.z}; }
inline static stdmath_uint4 stdmath_uint4_wzzz_get(stdmath_uint4* p) { return stdmath_uint4_wzzz(*p); }
inline static stdmath_uint4 stdmath_uint4_wzzz_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->z = value.y; p->z = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wzzw(stdmath_uint4 v) { return {v.w,v.z,v.z,v.w}; }
inline static stdmath_uint4 stdmath_uint4_wzzw_get(stdmath_uint4* p) { return stdmath_uint4_wzzw(*p); }
inline static stdmath_uint4 stdmath_uint4_wzzw_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->z = value.y; p->z = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wzwx(stdmath_uint4 v) { return {v.w,v.z,v.w,v.x}; }
inline static stdmath_uint4 stdmath_uint4_wzwx_get(stdmath_uint4* p) { return stdmath_uint4_wzwx(*p); }
inline static stdmath_uint4 stdmath_uint4_wzwx_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->z = value.y; p->w = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wzwy(stdmath_uint4 v) { return {v.w,v.z,v.w,v.y}; }
inline static stdmath_uint4 stdmath_uint4_wzwy_get(stdmath_uint4* p) { return stdmath_uint4_wzwy(*p); }
inline static stdmath_uint4 stdmath_uint4_wzwy_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->z = value.y; p->w = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wzwz(stdmath_uint4 v) { return {v.w,v.z,v.w,v.z}; }
inline static stdmath_uint4 stdmath_uint4_wzwz_get(stdmath_uint4* p) { return stdmath_uint4_wzwz(*p); }
inline static stdmath_uint4 stdmath_uint4_wzwz_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->z = value.y; p->w = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wzww(stdmath_uint4 v) { return {v.w,v.z,v.w,v.w}; }
inline static stdmath_uint4 stdmath_uint4_wzww_get(stdmath_uint4* p) { return stdmath_uint4_wzww(*p); }
inline static stdmath_uint4 stdmath_uint4_wzww_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->z = value.y; p->w = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wwxx(stdmath_uint4 v) { return {v.w,v.w,v.x,v.x}; }
inline static stdmath_uint4 stdmath_uint4_wwxx_get(stdmath_uint4* p) { return stdmath_uint4_wwxx(*p); }
inline static stdmath_uint4 stdmath_uint4_wwxx_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->w = value.y; p->x = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wwxy(stdmath_uint4 v) { return {v.w,v.w,v.x,v.y}; }
inline static stdmath_uint4 stdmath_uint4_wwxy_get(stdmath_uint4* p) { return stdmath_uint4_wwxy(*p); }
inline static stdmath_uint4 stdmath_uint4_wwxy_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->w = value.y; p->x = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wwxz(stdmath_uint4 v) { return {v.w,v.w,v.x,v.z}; }
inline static stdmath_uint4 stdmath_uint4_wwxz_get(stdmath_uint4* p) { return stdmath_uint4_wwxz(*p); }
inline static stdmath_uint4 stdmath_uint4_wwxz_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->w = value.y; p->x = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wwxw(stdmath_uint4 v) { return {v.w,v.w,v.x,v.w}; }
inline static stdmath_uint4 stdmath_uint4_wwxw_get(stdmath_uint4* p) { return stdmath_uint4_wwxw(*p); }
inline static stdmath_uint4 stdmath_uint4_wwxw_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->w = value.y; p->x = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wwyx(stdmath_uint4 v) { return {v.w,v.w,v.y,v.x}; }
inline static stdmath_uint4 stdmath_uint4_wwyx_get(stdmath_uint4* p) { return stdmath_uint4_wwyx(*p); }
inline static stdmath_uint4 stdmath_uint4_wwyx_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->w = value.y; p->y = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wwyy(stdmath_uint4 v) { return {v.w,v.w,v.y,v.y}; }
inline static stdmath_uint4 stdmath_uint4_wwyy_get(stdmath_uint4* p) { return stdmath_uint4_wwyy(*p); }
inline static stdmath_uint4 stdmath_uint4_wwyy_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->w = value.y; p->y = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wwyz(stdmath_uint4 v) { return {v.w,v.w,v.y,v.z}; }
inline static stdmath_uint4 stdmath_uint4_wwyz_get(stdmath_uint4* p) { return stdmath_uint4_wwyz(*p); }
inline static stdmath_uint4 stdmath_uint4_wwyz_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->w = value.y; p->y = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wwyw(stdmath_uint4 v) { return {v.w,v.w,v.y,v.w}; }
inline static stdmath_uint4 stdmath_uint4_wwyw_get(stdmath_uint4* p) { return stdmath_uint4_wwyw(*p); }
inline static stdmath_uint4 stdmath_uint4_wwyw_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->w = value.y; p->y = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wwzx(stdmath_uint4 v) { return {v.w,v.w,v.z,v.x}; }
inline static stdmath_uint4 stdmath_uint4_wwzx_get(stdmath_uint4* p) { return stdmath_uint4_wwzx(*p); }
inline static stdmath_uint4 stdmath_uint4_wwzx_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->w = value.y; p->z = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wwzy(stdmath_uint4 v) { return {v.w,v.w,v.z,v.y}; }
inline static stdmath_uint4 stdmath_uint4_wwzy_get(stdmath_uint4* p) { return stdmath_uint4_wwzy(*p); }
inline static stdmath_uint4 stdmath_uint4_wwzy_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->w = value.y; p->z = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wwzz(stdmath_uint4 v) { return {v.w,v.w,v.z,v.z}; }
inline static stdmath_uint4 stdmath_uint4_wwzz_get(stdmath_uint4* p) { return stdmath_uint4_wwzz(*p); }
inline static stdmath_uint4 stdmath_uint4_wwzz_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->w = value.y; p->z = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wwzw(stdmath_uint4 v) { return {v.w,v.w,v.z,v.w}; }
inline static stdmath_uint4 stdmath_uint4_wwzw_get(stdmath_uint4* p) { return stdmath_uint4_wwzw(*p); }
inline static stdmath_uint4 stdmath_uint4_wwzw_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->w = value.y; p->z = value.z; p->w = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wwwx(stdmath_uint4 v) { return {v.w,v.w,v.w,v.x}; }
inline static stdmath_uint4 stdmath_uint4_wwwx_get(stdmath_uint4* p) { return stdmath_uint4_wwwx(*p); }
inline static stdmath_uint4 stdmath_uint4_wwwx_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->w = value.y; p->w = value.z; p->x = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wwwy(stdmath_uint4 v) { return {v.w,v.w,v.w,v.y}; }
inline static stdmath_uint4 stdmath_uint4_wwwy_get(stdmath_uint4* p) { return stdmath_uint4_wwwy(*p); }
inline static stdmath_uint4 stdmath_uint4_wwwy_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->w = value.y; p->w = value.z; p->y = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wwwz(stdmath_uint4 v) { return {v.w,v.w,v.w,v.z}; }
inline static stdmath_uint4 stdmath_uint4_wwwz_get(stdmath_uint4* p) { return stdmath_uint4_wwwz(*p); }
inline static stdmath_uint4 stdmath_uint4_wwwz_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->w = value.y; p->w = value.z; p->z = value.w; return *p; }
inline static stdmath_uint4 stdmath_uint4_wwww(stdmath_uint4 v) { return {v.w,v.w,v.w,v.w}; }
inline static stdmath_uint4 stdmath_uint4_wwww_get(stdmath_uint4* p) { return stdmath_uint4_wwww(*p); }
inline static stdmath_uint4 stdmath_uint4_wwww_set(stdmath_uint4* p, stdmath_uint4 value) { p->w = value.x; p->w = value.y; p->w = value.z; p->w = value.w; return *p; }


#ifdef STDMATH_IMPLEMENTATION
#ifndef __cplusplus
#error "The stdmath implementations require a C++ compiler"
#endif

import stdmath.slang;

stdmath::uint4 c(stdmath_uint4 c) {
	return (stdmath::uint4&)c;
}
stdmath_uint4 c(stdmath::uint4 c) {
	return (stdmath_uint4&)c;
}

stdmath_uint4 stdmath_uint4_broadcast(uint32_t all) {
	return c(stdmath::uint4((stdmath::uint4::underlying_type)all));
}

stdmath_uint4 stdmath_uint4_add(stdmath_uint4 a, stdmath_uint4 b) {
	return c(c(a) + c(b));
}
stdmath_uint4 stdmath_uint4_subtract(stdmath_uint4 a, stdmath_uint4 b) {
	return c(c(a) - c(b));
}
stdmath_uint4 stdmath_uint4_negate(stdmath_uint4 v) {
	return c(stdmath::uint4(-(stdmath::vector<uint32_t, 4>)c(v)));
}
stdmath_uint4 stdmath_uint4_multiply(stdmath_uint4 a, stdmath_uint4 b) {
	return c(c(a) * c(b));
}
stdmath_uint4 stdmath_uint4_divide(stdmath_uint4 a, stdmath_uint4 b) {
	return c(c(a) / c(b));
}
stdmath_uint4 stdmath_uint4_scale(stdmath_uint4 v, uint32_t s) {
	return c(c(v) * (stdmath::uint4::underlying_type)s);
}

#if false
stdmath_uint4 stdmath_uint4_modulus(stdmath_uint4 a, stdmath_uint4 b) {
	return c(c(a) % c(b));
}
stdmath_uint4 stdmath_uint4_logical_not(stdmath_uint4 v) {
	return c(!c(v));
}
stdmath_uint4 stdmath_uint4_bitwise_not(stdmath_uint4 v) {
	return c(~c(v));
}
stdmath_uint4 stdmath_uint4_logical_and(stdmath_uint4 a, stdmath_uint4 b) {
	return c(c(a) && c(b));
}
stdmath_uint4 stdmath_uint4_bitwise_and(stdmath_uint4 a, stdmath_uint4 b) {
	return c(c(a) & c(b));
}
stdmath_uint4 stdmath_uint4_logical_or(stdmath_uint4 a, stdmath_uint4 b) {
	return c(c(a) || c(b));
}
stdmath_uint4 stdmath_uint4_bitwise_or(stdmath_uint4 a, stdmath_uint4 b) {
	return c(c(a) | c(b));
}
stdmath_uint4 stdmath_uint4_bitwise_xor(stdmath_uint4 a, stdmath_uint4 b) {
	return c(c(a) ^ c(b));
}
stdmath_uint4 stdmath_uint4_shift_left(stdmath_uint4 a, stdmath_uint4 b) {
	return c(c(a) << c(b));
}
stdmath_uint4 stdmath_uint4_shift_right(stdmath_uint4 a, stdmath_uint4 b) {
	return c(c(a) >> c(b));
}
#endif

stdmath_bool4 stdmath_uint4_equal_to(stdmath_uint4 a, stdmath_uint4 b) {
	return c(c(a) == c(b));
}
stdmath_bool4 stdmath_uint4_not_equal_to(stdmath_uint4 a, stdmath_uint4 b) {
	return c(c(a) != c(b));
}
stdmath_bool4 stdmath_uint4_less_than(stdmath_uint4 a, stdmath_uint4 b) {
	return c(c(a) < c(b));
}
stdmath_bool4 stdmath_uint4_less_than_or_equal_to(stdmath_uint4 a, stdmath_uint4 b) {
	return c(c(a) <= c(b));
}
stdmath_bool4 stdmath_uint4_greater_than(stdmath_uint4 a, stdmath_uint4 b) {
	return c(c(a) > c(b));
}
stdmath_bool4 stdmath_uint4_greater_than_or_equal_to(stdmath_uint4 a, stdmath_uint4 b) {
	return c(c(a) >= c(b));
}

uint32_t stdmath_uint4_length_squared(stdmath_uint4 v)  {
	return (uint32_t)c(v).length_squared();
}
uint32_t stdmath_uint4_length(stdmath_uint4 v)  {
	return (uint32_t)c(v).length();
}
uint32_t stdmath_uint4_dot(stdmath_uint4 a, stdmath_uint4 b)  {
	return (uint32_t)dot(c(a), c(b));
}
uint32_t stdmath_uint4_min_element(stdmath_uint4 v)  {
	return (uint32_t)c(v).min_element();
}
uint32_t stdmath_uint4_max_element(stdmath_uint4 v)  {
	return (uint32_t)c(v).max_element();
}

stdmath_uint4 stdmath_uint4_elementwise_transform(stdmath_uint4 v, uint32_t(*func)(uint32_t)) {
	return c(c(v).elementwise_transform(func));
}
// uint32_t stdmath_uint4_reduce_elements(stdmath_uint4 v, uint32_t initial_value, uint32_t(*reducer)(stdmath_uint4, stdmath_uint4)) {
// 	return c(v).reduce_elements(initial_value, reducer);
// }

#if 4 == 3
stdmath_uint4 stdmath_uint4_cross(stdmath_uint4 a, stdmath_uint4 b) {
	return c(cross(c(a), c(b)));
}
#endif

stdmath_uint4 stdmath_uint4_min(stdmath_uint4 a, stdmath_uint4 b) {
	return c(min(c(a), c(b)));
}
stdmath_uint4 stdmath_uint4_max(stdmath_uint4 a, stdmath_uint4 b) {
	return c(max(c(a), c(b)));
}
stdmath_uint4 stdmath_uint4_normalize(stdmath_uint4 v) {
	return c(normalize(c(v)));
}
stdmath_uint4 stdmath_uint4_lerp(stdmath_uint4 a, stdmath_uint4 b, float t) {
	return c(lerp(c(a), c(b), t));
}
stdmath_uint4 stdmath_uint4_clamp(stdmath_uint4 a, stdmath_uint4 min, stdmath_uint4 max) {
	return c(clamp(c(a), c(min), c(max)));
}
stdmath_uint4 stdmath_uint4_reflect(stdmath_uint4 a, stdmath_uint4 b) {
	return c(reflect(c(a), c(b)));
}
stdmath_bool4 stdmath_uint4_approximately_equal(stdmath_uint4 a, stdmath_uint4 b) {
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

#endif // __STDMATH_uint32_t4_H__