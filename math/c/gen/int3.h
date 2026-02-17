#ifndef __STDMATH_int32_t3_H__
#define __STDMATH_int32_t3_H__

#ifndef STDMATH_MODULE
#include <stdint.h>
#endif
#include "../maybe_export.h"

#if !false
#if 3 == 1
#include "bool1.h"
#elif 3 == 2
#include "bool2.h"
#elif 3 == 3
#include "bool3.h"
#elif 3 == 4
#include "bool4.h"
#endif
#endif
#if 3 == 2
#include "int1.h"
#elif 3 == 3
#include "int2.h"
#include "int1.h"
#elif 3 == 4
#include "int3.h"
#include "int2.h"
#include "int1.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if 3 == 1
STDMATH_EXPORT union stdmath_int1 {
	struct {
		int32_t x;
	};
	int32_t data[1];
};
#elif 3 == 2
STDMATH_EXPORT union stdmath_int2 {
	struct {
		int32_t x, y;
	};
	struct {
		int32_t u, v;
	};
	int32_t data[2];
};
#elif 3 == 3
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
#elif 3 == 4
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

STDMATH_EXPORT stdmath_int3 stdmath_int3_broadcast(int32_t all);

STDMATH_EXPORT stdmath_int3 stdmath_int3_add(stdmath_int3 a, stdmath_int3 b);
STDMATH_EXPORT stdmath_int3 stdmath_int3_subtract(stdmath_int3 a, stdmath_int3 b);
STDMATH_EXPORT stdmath_int3 stdmath_int3_negate(stdmath_int3 v);
STDMATH_EXPORT stdmath_int3 stdmath_int3_multiply(stdmath_int3 a, stdmath_int3 b);
STDMATH_EXPORT stdmath_int3 stdmath_int3_divide(stdmath_int3 a, stdmath_int3 b);
STDMATH_EXPORT stdmath_int3 stdmath_int3_scale(stdmath_int3 v, int32_t s);

#if false
STDMATH_EXPORT stdmath_int3 stdmath_int3_modulus(stdmath_int3 a, stdmath_int3 b);
STDMATH_EXPORT stdmath_int3 stdmath_int3_logical_not(stdmath_int3 v);
STDMATH_EXPORT stdmath_int3 stdmath_int3_bitwise_not(stdmath_int3 v);
STDMATH_EXPORT stdmath_int3 stdmath_int3_logical_and(stdmath_int3 a, stdmath_int3 b);
STDMATH_EXPORT stdmath_int3 stdmath_int3_bitwise_and(stdmath_int3 a, stdmath_int3 b);
STDMATH_EXPORT stdmath_int3 stdmath_int3_logical_or(stdmath_int3 a, stdmath_int3 b);
STDMATH_EXPORT stdmath_int3 stdmath_int3_bitwise_or(stdmath_int3 a, stdmath_int3 b);
STDMATH_EXPORT stdmath_int3 stdmath_int3_bitwise_xor(stdmath_int3 a, stdmath_int3 b);
STDMATH_EXPORT stdmath_int3 stdmath_int3_shift_left(stdmath_int3 a, stdmath_int3 b);
STDMATH_EXPORT stdmath_int3 stdmath_int3_shift_right(stdmath_int3 a, stdmath_int3 b);
#endif

STDMATH_EXPORT stdmath_bool3 stdmath_int3_equal_to(stdmath_int3 a, stdmath_int3 b);
STDMATH_EXPORT stdmath_bool3 stdmath_int3_not_equal_to(stdmath_int3 a, stdmath_int3 b);
STDMATH_EXPORT stdmath_bool3 stdmath_int3_less_than(stdmath_int3 a, stdmath_int3 b);
STDMATH_EXPORT stdmath_bool3 stdmath_int3_less_than_or_equal_to(stdmath_int3 a, stdmath_int3 b);
STDMATH_EXPORT stdmath_bool3 stdmath_int3_greater_than(stdmath_int3 a, stdmath_int3 b);
STDMATH_EXPORT stdmath_bool3 stdmath_int3_greater_than_or_equal_to(stdmath_int3 a, stdmath_int3 b);

STDMATH_EXPORT int32_t stdmath_int3_length_squared(stdmath_int3 v);
STDMATH_EXPORT int32_t stdmath_int3_length(stdmath_int3 v);
STDMATH_EXPORT int32_t stdmath_int3_dot(stdmath_int3 a, stdmath_int3 b);
STDMATH_EXPORT int32_t stdmath_int3_min_element(stdmath_int3 v);
STDMATH_EXPORT int32_t stdmath_int3_max_element(stdmath_int3 v);

STDMATH_EXPORT stdmath_int3 stdmath_int3_elementwise_transform(stdmath_int3 v, int32_t(*func)(int32_t));
// STDMATH_EXPORT int32_t stdmath_int3_reduce_elements(stdmath_int3 v, int32_t initial_value, int32_t(*reducer)(stdmath_int3, stdmath_int3));

#if 3 == 3
STDMATH_EXPORT stdmath_int3 stdmath_int3_cross(stdmath_int3 a, stdmath_int3 b);
#endif

STDMATH_EXPORT stdmath_int3 stdmath_int3_min(stdmath_int3 a, stdmath_int3 b);
STDMATH_EXPORT stdmath_int3 stdmath_int3_max(stdmath_int3 a, stdmath_int3 b);
STDMATH_EXPORT stdmath_int3 stdmath_int3_normalize(stdmath_int3 v);
STDMATH_EXPORT stdmath_int3 stdmath_int3_lerp(stdmath_int3 a, stdmath_int3 b, float t);
STDMATH_EXPORT stdmath_int3 stdmath_int3_clamp(stdmath_int3 a, stdmath_int3 min, stdmath_int3 max);
STDMATH_EXPORT stdmath_int3 stdmath_int3_reflect(stdmath_int3 a, stdmath_int3 b);
STDMATH_EXPORT stdmath_bool3 stdmath_int3_approximately_equal(stdmath_int3 a, stdmath_int3 b);

#if false
STDMATH_EXPORT bool stdmath_bool3_all_of(stdmath_bool3 v);
STDMATH_EXPORT bool stdmath_bool3_any_of(stdmath_bool3 v);
STDMATH_EXPORT bool stdmath_bool3_none_of(stdmath_bool3 v);
STDMATH_EXPORT bool stdmath_bool3_some_of(stdmath_bool3 v);
#endif

#ifndef STDMATH_NO_SWIZZLES
STDMATH_EXPORT STDMATH_INLINE stdmath_int1 stdmath_int3_x(stdmath_int3 v) { return {v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int1 stdmath_int3_x_get(stdmath_int3* p) { return stdmath_int3_x(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_x_set(stdmath_int3* p, stdmath_int1 value) { p->x = value.x; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int1 stdmath_int3_y(stdmath_int3 v) { return {v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int1 stdmath_int3_y_get(stdmath_int3* p) { return stdmath_int3_y(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_y_set(stdmath_int3* p, stdmath_int1 value) { p->y = value.x; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int1 stdmath_int3_z(stdmath_int3 v) { return {v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int1 stdmath_int3_z_get(stdmath_int3* p) { return stdmath_int3_z(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_z_set(stdmath_int3* p, stdmath_int1 value) { p->z = value.x; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int3_xx(stdmath_int3 v) { return {v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int3_xx_get(stdmath_int3* p) { return stdmath_int3_xx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_xx_set(stdmath_int3* p, stdmath_int2 value) { p->x = value.x; p->x = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int3_xy(stdmath_int3 v) { return {v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int3_xy_get(stdmath_int3* p) { return stdmath_int3_xy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_xy_set(stdmath_int3* p, stdmath_int2 value) { p->x = value.x; p->y = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int3_xz(stdmath_int3 v) { return {v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int3_xz_get(stdmath_int3* p) { return stdmath_int3_xz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_xz_set(stdmath_int3* p, stdmath_int2 value) { p->x = value.x; p->z = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int3_yx(stdmath_int3 v) { return {v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int3_yx_get(stdmath_int3* p) { return stdmath_int3_yx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_yx_set(stdmath_int3* p, stdmath_int2 value) { p->y = value.x; p->x = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int3_yy(stdmath_int3 v) { return {v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int3_yy_get(stdmath_int3* p) { return stdmath_int3_yy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_yy_set(stdmath_int3* p, stdmath_int2 value) { p->y = value.x; p->y = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int3_yz(stdmath_int3 v) { return {v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int3_yz_get(stdmath_int3* p) { return stdmath_int3_yz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_yz_set(stdmath_int3* p, stdmath_int2 value) { p->y = value.x; p->z = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int3_zx(stdmath_int3 v) { return {v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int3_zx_get(stdmath_int3* p) { return stdmath_int3_zx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_zx_set(stdmath_int3* p, stdmath_int2 value) { p->z = value.x; p->x = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int3_zy(stdmath_int3 v) { return {v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int3_zy_get(stdmath_int3* p) { return stdmath_int3_zy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_zy_set(stdmath_int3* p, stdmath_int2 value) { p->z = value.x; p->y = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int3_zz(stdmath_int3 v) { return {v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int3_zz_get(stdmath_int3* p) { return stdmath_int3_zz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_zz_set(stdmath_int3* p, stdmath_int2 value) { p->z = value.x; p->z = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_xxx(stdmath_int3 v) { return {v.x,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_xxx_get(stdmath_int3* p) { return stdmath_int3_xxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_xxx_set(stdmath_int3* p, stdmath_int3 value) { p->x = value.x; p->x = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_xxy(stdmath_int3 v) { return {v.x,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_xxy_get(stdmath_int3* p) { return stdmath_int3_xxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_xxy_set(stdmath_int3* p, stdmath_int3 value) { p->x = value.x; p->x = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_xxz(stdmath_int3 v) { return {v.x,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_xxz_get(stdmath_int3* p) { return stdmath_int3_xxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_xxz_set(stdmath_int3* p, stdmath_int3 value) { p->x = value.x; p->x = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_xyx(stdmath_int3 v) { return {v.x,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_xyx_get(stdmath_int3* p) { return stdmath_int3_xyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_xyx_set(stdmath_int3* p, stdmath_int3 value) { p->x = value.x; p->y = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_xyy(stdmath_int3 v) { return {v.x,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_xyy_get(stdmath_int3* p) { return stdmath_int3_xyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_xyy_set(stdmath_int3* p, stdmath_int3 value) { p->x = value.x; p->y = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_xyz(stdmath_int3 v) { return {v.x,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_xyz_get(stdmath_int3* p) { return stdmath_int3_xyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_xyz_set(stdmath_int3* p, stdmath_int3 value) { p->x = value.x; p->y = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_xzx(stdmath_int3 v) { return {v.x,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_xzx_get(stdmath_int3* p) { return stdmath_int3_xzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_xzx_set(stdmath_int3* p, stdmath_int3 value) { p->x = value.x; p->z = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_xzy(stdmath_int3 v) { return {v.x,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_xzy_get(stdmath_int3* p) { return stdmath_int3_xzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_xzy_set(stdmath_int3* p, stdmath_int3 value) { p->x = value.x; p->z = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_xzz(stdmath_int3 v) { return {v.x,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_xzz_get(stdmath_int3* p) { return stdmath_int3_xzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_xzz_set(stdmath_int3* p, stdmath_int3 value) { p->x = value.x; p->z = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_yxx(stdmath_int3 v) { return {v.y,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_yxx_get(stdmath_int3* p) { return stdmath_int3_yxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_yxx_set(stdmath_int3* p, stdmath_int3 value) { p->y = value.x; p->x = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_yxy(stdmath_int3 v) { return {v.y,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_yxy_get(stdmath_int3* p) { return stdmath_int3_yxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_yxy_set(stdmath_int3* p, stdmath_int3 value) { p->y = value.x; p->x = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_yxz(stdmath_int3 v) { return {v.y,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_yxz_get(stdmath_int3* p) { return stdmath_int3_yxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_yxz_set(stdmath_int3* p, stdmath_int3 value) { p->y = value.x; p->x = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_yyx(stdmath_int3 v) { return {v.y,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_yyx_get(stdmath_int3* p) { return stdmath_int3_yyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_yyx_set(stdmath_int3* p, stdmath_int3 value) { p->y = value.x; p->y = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_yyy(stdmath_int3 v) { return {v.y,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_yyy_get(stdmath_int3* p) { return stdmath_int3_yyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_yyy_set(stdmath_int3* p, stdmath_int3 value) { p->y = value.x; p->y = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_yyz(stdmath_int3 v) { return {v.y,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_yyz_get(stdmath_int3* p) { return stdmath_int3_yyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_yyz_set(stdmath_int3* p, stdmath_int3 value) { p->y = value.x; p->y = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_yzx(stdmath_int3 v) { return {v.y,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_yzx_get(stdmath_int3* p) { return stdmath_int3_yzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_yzx_set(stdmath_int3* p, stdmath_int3 value) { p->y = value.x; p->z = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_yzy(stdmath_int3 v) { return {v.y,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_yzy_get(stdmath_int3* p) { return stdmath_int3_yzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_yzy_set(stdmath_int3* p, stdmath_int3 value) { p->y = value.x; p->z = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_yzz(stdmath_int3 v) { return {v.y,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_yzz_get(stdmath_int3* p) { return stdmath_int3_yzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_yzz_set(stdmath_int3* p, stdmath_int3 value) { p->y = value.x; p->z = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_zxx(stdmath_int3 v) { return {v.z,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_zxx_get(stdmath_int3* p) { return stdmath_int3_zxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_zxx_set(stdmath_int3* p, stdmath_int3 value) { p->z = value.x; p->x = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_zxy(stdmath_int3 v) { return {v.z,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_zxy_get(stdmath_int3* p) { return stdmath_int3_zxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_zxy_set(stdmath_int3* p, stdmath_int3 value) { p->z = value.x; p->x = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_zxz(stdmath_int3 v) { return {v.z,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_zxz_get(stdmath_int3* p) { return stdmath_int3_zxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_zxz_set(stdmath_int3* p, stdmath_int3 value) { p->z = value.x; p->x = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_zyx(stdmath_int3 v) { return {v.z,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_zyx_get(stdmath_int3* p) { return stdmath_int3_zyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_zyx_set(stdmath_int3* p, stdmath_int3 value) { p->z = value.x; p->y = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_zyy(stdmath_int3 v) { return {v.z,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_zyy_get(stdmath_int3* p) { return stdmath_int3_zyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_zyy_set(stdmath_int3* p, stdmath_int3 value) { p->z = value.x; p->y = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_zyz(stdmath_int3 v) { return {v.z,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_zyz_get(stdmath_int3* p) { return stdmath_int3_zyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_zyz_set(stdmath_int3* p, stdmath_int3 value) { p->z = value.x; p->y = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_zzx(stdmath_int3 v) { return {v.z,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_zzx_get(stdmath_int3* p) { return stdmath_int3_zzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_zzx_set(stdmath_int3* p, stdmath_int3 value) { p->z = value.x; p->z = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_zzy(stdmath_int3 v) { return {v.z,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_zzy_get(stdmath_int3* p) { return stdmath_int3_zzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_zzy_set(stdmath_int3* p, stdmath_int3 value) { p->z = value.x; p->z = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_zzz(stdmath_int3 v) { return {v.z,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_zzz_get(stdmath_int3* p) { return stdmath_int3_zzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int3 stdmath_int3_zzz_set(stdmath_int3* p, stdmath_int3 value) { p->z = value.x; p->z = value.y; p->z = value.z; return *p; }

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

inline stdmath::int3 c(stdmath_int3 c) {
	return (stdmath::int3&)c;
}
inline stdmath_int3 c(stdmath::int3 c) {
	return (stdmath_int3&)c;
}

#ifdef __cplusplus
extern "C" {
#endif

stdmath_int3 stdmath_int3_broadcast(int32_t all) {
	return c(stdmath::int3((stdmath::int3::underlying_type)all));
}

stdmath_int3 stdmath_int3_add(stdmath_int3 a, stdmath_int3 b) {
	return c(c(a) + c(b));
}
stdmath_int3 stdmath_int3_subtract(stdmath_int3 a, stdmath_int3 b) {
	return c(c(a) - c(b));
}
stdmath_int3 stdmath_int3_negate(stdmath_int3 v) {
	return c(stdmath::int3(-(stdmath::vector<int32_t, 3>)c(v)));
}
stdmath_int3 stdmath_int3_multiply(stdmath_int3 a, stdmath_int3 b) {
	return c(c(a) * c(b));
}
stdmath_int3 stdmath_int3_divide(stdmath_int3 a, stdmath_int3 b) {
	return c(c(a) / c(b));
}
stdmath_int3 stdmath_int3_scale(stdmath_int3 v, int32_t s) {
	return c(c(v) * (stdmath::int3::underlying_type)s);
}

#if false
stdmath_int3 stdmath_int3_modulus(stdmath_int3 a, stdmath_int3 b) {
	return c(c(a) % c(b));
}
stdmath_int3 stdmath_int3_logical_not(stdmath_int3 v) {
	return c(!c(v));
}
stdmath_int3 stdmath_int3_bitwise_not(stdmath_int3 v) {
	return c(~c(v));
}
stdmath_int3 stdmath_int3_logical_and(stdmath_int3 a, stdmath_int3 b) {
	return c(c(a) && c(b));
}
stdmath_int3 stdmath_int3_bitwise_and(stdmath_int3 a, stdmath_int3 b) {
	return c(c(a) & c(b));
}
stdmath_int3 stdmath_int3_logical_or(stdmath_int3 a, stdmath_int3 b) {
	return c(c(a) || c(b));
}
stdmath_int3 stdmath_int3_bitwise_or(stdmath_int3 a, stdmath_int3 b) {
	return c(c(a) | c(b));
}
stdmath_int3 stdmath_int3_bitwise_xor(stdmath_int3 a, stdmath_int3 b) {
	return c(c(a) ^ c(b));
}
stdmath_int3 stdmath_int3_shift_left(stdmath_int3 a, stdmath_int3 b) {
	return c(c(a) << c(b));
}
stdmath_int3 stdmath_int3_shift_right(stdmath_int3 a, stdmath_int3 b) {
	return c(c(a) >> c(b));
}
#endif

stdmath_bool3 stdmath_int3_equal_to(stdmath_int3 a, stdmath_int3 b) {
	return c(c(a) == c(b));
}
stdmath_bool3 stdmath_int3_not_equal_to(stdmath_int3 a, stdmath_int3 b) {
	return c(c(a) != c(b));
}
stdmath_bool3 stdmath_int3_less_than(stdmath_int3 a, stdmath_int3 b) {
	return c(c(a) < c(b));
}
stdmath_bool3 stdmath_int3_less_than_or_equal_to(stdmath_int3 a, stdmath_int3 b) {
	return c(c(a) <= c(b));
}
stdmath_bool3 stdmath_int3_greater_than(stdmath_int3 a, stdmath_int3 b) {
	return c(c(a) > c(b));
}
stdmath_bool3 stdmath_int3_greater_than_or_equal_to(stdmath_int3 a, stdmath_int3 b) {
	return c(c(a) >= c(b));
}

int32_t stdmath_int3_length_squared(stdmath_int3 v)  {
	return (int32_t)c(v).length_squared();
}
int32_t stdmath_int3_length(stdmath_int3 v)  {
	return (int32_t)c(v).length();
}
int32_t stdmath_int3_dot(stdmath_int3 a, stdmath_int3 b)  {
	return (int32_t)dot(c(a), c(b));
}
int32_t stdmath_int3_min_element(stdmath_int3 v)  {
	return (int32_t)c(v).min_element();
}
int32_t stdmath_int3_max_element(stdmath_int3 v)  {
	return (int32_t)c(v).max_element();
}

stdmath_int3 stdmath_int3_elementwise_transform(stdmath_int3 v, int32_t(*func)(int32_t)) {
	return c(c(v).elementwise_transform(func));
}
// int32_t stdmath_int3_reduce_elements(stdmath_int3 v, int32_t initial_value, int32_t(*reducer)(stdmath_int3, stdmath_int3)) {
// 	return c(v).reduce_elements(initial_value, reducer);
// }

#if 3 == 3
stdmath_int3 stdmath_int3_cross(stdmath_int3 a, stdmath_int3 b) {
	return c(cross(c(a), c(b)));
}
#endif

stdmath_int3 stdmath_int3_min(stdmath_int3 a, stdmath_int3 b) {
	return c(min(c(a), c(b)));
}
stdmath_int3 stdmath_int3_max(stdmath_int3 a, stdmath_int3 b) {
	return c(max(c(a), c(b)));
}
stdmath_int3 stdmath_int3_normalize(stdmath_int3 v) {
	return c(normalize(c(v)));
}
stdmath_int3 stdmath_int3_lerp(stdmath_int3 a, stdmath_int3 b, float t) {
	return c(lerp(c(a), c(b), t));
}
stdmath_int3 stdmath_int3_clamp(stdmath_int3 a, stdmath_int3 min, stdmath_int3 max) {
	return c(clamp(c(a), c(min), c(max)));
}
stdmath_int3 stdmath_int3_reflect(stdmath_int3 a, stdmath_int3 b) {
	return c(reflect(c(a), c(b)));
}
stdmath_bool3 stdmath_int3_approximately_equal(stdmath_int3 a, stdmath_int3 b) {
	return c(approximately_equal(c(a), c(b)));
}

#if false
bool stdmath_bool3_all_of(stdmath_bool3 v) {
	return all_of(c(v));
}
bool stdmath_bool3_any_of(stdmath_bool3 v) {
	return any_of(c(v));
}
bool stdmath_bool3_none_of(stdmath_bool3 v) {
	return none_of(c(v));
}
bool stdmath_bool3_some_of(stdmath_bool3 v) {
	return some_of(c(v));
}
#endif

#ifdef __cplusplus
} // extern "C"
#endif

#endif // STDMATH_IMPLEMENTATION

#endif // __STDMATH_int32_t3_H__