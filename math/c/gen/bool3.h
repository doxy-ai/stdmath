#ifndef __STDMATH_bool3_H__
#define __STDMATH_bool3_H__

#ifndef STDMATH_MODULE
#include <stdint.h>
#endif
#include "../maybe_export.h"

#if !true
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
#include "bool1.h"
#elif 3 == 3
#include "bool2.h"
#include "bool1.h"
#elif 3 == 4
#include "bool3.h"
#include "bool2.h"
#include "bool1.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if 3 == 1
STDMATH_EXPORT union stdmath_bool1 {
	struct {
		bool x;
	};
	bool data[1];
};
#elif 3 == 2
STDMATH_EXPORT union stdmath_bool2 {
	struct {
		bool x, y;
	};
	struct {
		bool u, v;
	};
	bool data[2];
};
#elif 3 == 3
STDMATH_EXPORT union stdmath_bool3 {
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
#elif 3 == 4
STDMATH_EXPORT union stdmath_bool4 {
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

STDMATH_EXPORT stdmath_bool3 stdmath_bool3_broadcast(bool all);

STDMATH_EXPORT stdmath_bool3 stdmath_bool3_add(stdmath_bool3 a, stdmath_bool3 b);
STDMATH_EXPORT stdmath_bool3 stdmath_bool3_subtract(stdmath_bool3 a, stdmath_bool3 b);
STDMATH_EXPORT stdmath_bool3 stdmath_bool3_negate(stdmath_bool3 v);
STDMATH_EXPORT stdmath_bool3 stdmath_bool3_multiply(stdmath_bool3 a, stdmath_bool3 b);
STDMATH_EXPORT stdmath_bool3 stdmath_bool3_divide(stdmath_bool3 a, stdmath_bool3 b);
STDMATH_EXPORT stdmath_bool3 stdmath_bool3_scale(stdmath_bool3 v, bool s);

#if false
STDMATH_EXPORT stdmath_bool3 stdmath_bool3_modulus(stdmath_bool3 a, stdmath_bool3 b);
STDMATH_EXPORT stdmath_bool3 stdmath_bool3_logical_not(stdmath_bool3 v);
STDMATH_EXPORT stdmath_bool3 stdmath_bool3_bitwise_not(stdmath_bool3 v);
STDMATH_EXPORT stdmath_bool3 stdmath_bool3_logical_and(stdmath_bool3 a, stdmath_bool3 b);
STDMATH_EXPORT stdmath_bool3 stdmath_bool3_bitwise_and(stdmath_bool3 a, stdmath_bool3 b);
STDMATH_EXPORT stdmath_bool3 stdmath_bool3_logical_or(stdmath_bool3 a, stdmath_bool3 b);
STDMATH_EXPORT stdmath_bool3 stdmath_bool3_bitwise_or(stdmath_bool3 a, stdmath_bool3 b);
STDMATH_EXPORT stdmath_bool3 stdmath_bool3_bitwise_xor(stdmath_bool3 a, stdmath_bool3 b);
STDMATH_EXPORT stdmath_bool3 stdmath_bool3_shift_left(stdmath_bool3 a, stdmath_bool3 b);
STDMATH_EXPORT stdmath_bool3 stdmath_bool3_shift_right(stdmath_bool3 a, stdmath_bool3 b);
#endif

STDMATH_EXPORT stdmath_bool3 stdmath_bool3_equal_to(stdmath_bool3 a, stdmath_bool3 b);
STDMATH_EXPORT stdmath_bool3 stdmath_bool3_not_equal_to(stdmath_bool3 a, stdmath_bool3 b);
STDMATH_EXPORT stdmath_bool3 stdmath_bool3_less_than(stdmath_bool3 a, stdmath_bool3 b);
STDMATH_EXPORT stdmath_bool3 stdmath_bool3_less_than_or_equal_to(stdmath_bool3 a, stdmath_bool3 b);
STDMATH_EXPORT stdmath_bool3 stdmath_bool3_greater_than(stdmath_bool3 a, stdmath_bool3 b);
STDMATH_EXPORT stdmath_bool3 stdmath_bool3_greater_than_or_equal_to(stdmath_bool3 a, stdmath_bool3 b);

STDMATH_EXPORT bool stdmath_bool3_length_squared(stdmath_bool3 v);
STDMATH_EXPORT bool stdmath_bool3_length(stdmath_bool3 v);
STDMATH_EXPORT bool stdmath_bool3_dot(stdmath_bool3 a, stdmath_bool3 b);
STDMATH_EXPORT bool stdmath_bool3_min_element(stdmath_bool3 v);
STDMATH_EXPORT bool stdmath_bool3_max_element(stdmath_bool3 v);

STDMATH_EXPORT stdmath_bool3 stdmath_bool3_elementwise_transform(stdmath_bool3 v, bool(*func)(bool));
// STDMATH_EXPORT bool stdmath_bool3_reduce_elements(stdmath_bool3 v, bool initial_value, bool(*reducer)(stdmath_bool3, stdmath_bool3));

#if 3 == 3
STDMATH_EXPORT stdmath_bool3 stdmath_bool3_cross(stdmath_bool3 a, stdmath_bool3 b);
#endif

STDMATH_EXPORT stdmath_bool3 stdmath_bool3_min(stdmath_bool3 a, stdmath_bool3 b);
STDMATH_EXPORT stdmath_bool3 stdmath_bool3_max(stdmath_bool3 a, stdmath_bool3 b);
STDMATH_EXPORT stdmath_bool3 stdmath_bool3_normalize(stdmath_bool3 v);
STDMATH_EXPORT stdmath_bool3 stdmath_bool3_lerp(stdmath_bool3 a, stdmath_bool3 b, float t);
STDMATH_EXPORT stdmath_bool3 stdmath_bool3_clamp(stdmath_bool3 a, stdmath_bool3 min, stdmath_bool3 max);
STDMATH_EXPORT stdmath_bool3 stdmath_bool3_reflect(stdmath_bool3 a, stdmath_bool3 b);
STDMATH_EXPORT stdmath_bool3 stdmath_bool3_approximately_equal(stdmath_bool3 a, stdmath_bool3 b);

#if true
STDMATH_EXPORT bool stdmath_bool3_all_of(stdmath_bool3 v);
STDMATH_EXPORT bool stdmath_bool3_any_of(stdmath_bool3 v);
STDMATH_EXPORT bool stdmath_bool3_none_of(stdmath_bool3 v);
STDMATH_EXPORT bool stdmath_bool3_some_of(stdmath_bool3 v);
#endif

#ifndef STDMATH_NO_SWIZZLES
STDMATH_EXPORT STDMATH_INLINE stdmath_bool1 stdmath_bool3_x(stdmath_bool3 v) { return {v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool1 stdmath_bool3_x_get(stdmath_bool3* p) { return stdmath_bool3_x(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_x_set(stdmath_bool3* p, stdmath_bool1 value) { p->x = value.x; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool1 stdmath_bool3_y(stdmath_bool3 v) { return {v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool1 stdmath_bool3_y_get(stdmath_bool3* p) { return stdmath_bool3_y(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_y_set(stdmath_bool3* p, stdmath_bool1 value) { p->y = value.x; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool1 stdmath_bool3_z(stdmath_bool3 v) { return {v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool1 stdmath_bool3_z_get(stdmath_bool3* p) { return stdmath_bool3_z(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_z_set(stdmath_bool3* p, stdmath_bool1 value) { p->z = value.x; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool2 stdmath_bool3_xx(stdmath_bool3 v) { return {v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool2 stdmath_bool3_xx_get(stdmath_bool3* p) { return stdmath_bool3_xx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_xx_set(stdmath_bool3* p, stdmath_bool2 value) { p->x = value.x; p->x = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool2 stdmath_bool3_xy(stdmath_bool3 v) { return {v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool2 stdmath_bool3_xy_get(stdmath_bool3* p) { return stdmath_bool3_xy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_xy_set(stdmath_bool3* p, stdmath_bool2 value) { p->x = value.x; p->y = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool2 stdmath_bool3_xz(stdmath_bool3 v) { return {v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool2 stdmath_bool3_xz_get(stdmath_bool3* p) { return stdmath_bool3_xz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_xz_set(stdmath_bool3* p, stdmath_bool2 value) { p->x = value.x; p->z = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool2 stdmath_bool3_yx(stdmath_bool3 v) { return {v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool2 stdmath_bool3_yx_get(stdmath_bool3* p) { return stdmath_bool3_yx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_yx_set(stdmath_bool3* p, stdmath_bool2 value) { p->y = value.x; p->x = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool2 stdmath_bool3_yy(stdmath_bool3 v) { return {v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool2 stdmath_bool3_yy_get(stdmath_bool3* p) { return stdmath_bool3_yy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_yy_set(stdmath_bool3* p, stdmath_bool2 value) { p->y = value.x; p->y = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool2 stdmath_bool3_yz(stdmath_bool3 v) { return {v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool2 stdmath_bool3_yz_get(stdmath_bool3* p) { return stdmath_bool3_yz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_yz_set(stdmath_bool3* p, stdmath_bool2 value) { p->y = value.x; p->z = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool2 stdmath_bool3_zx(stdmath_bool3 v) { return {v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool2 stdmath_bool3_zx_get(stdmath_bool3* p) { return stdmath_bool3_zx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_zx_set(stdmath_bool3* p, stdmath_bool2 value) { p->z = value.x; p->x = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool2 stdmath_bool3_zy(stdmath_bool3 v) { return {v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool2 stdmath_bool3_zy_get(stdmath_bool3* p) { return stdmath_bool3_zy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_zy_set(stdmath_bool3* p, stdmath_bool2 value) { p->z = value.x; p->y = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool2 stdmath_bool3_zz(stdmath_bool3 v) { return {v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool2 stdmath_bool3_zz_get(stdmath_bool3* p) { return stdmath_bool3_zz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_zz_set(stdmath_bool3* p, stdmath_bool2 value) { p->z = value.x; p->z = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_xxx(stdmath_bool3 v) { return {v.x,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_xxx_get(stdmath_bool3* p) { return stdmath_bool3_xxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_xxx_set(stdmath_bool3* p, stdmath_bool3 value) { p->x = value.x; p->x = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_xxy(stdmath_bool3 v) { return {v.x,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_xxy_get(stdmath_bool3* p) { return stdmath_bool3_xxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_xxy_set(stdmath_bool3* p, stdmath_bool3 value) { p->x = value.x; p->x = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_xxz(stdmath_bool3 v) { return {v.x,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_xxz_get(stdmath_bool3* p) { return stdmath_bool3_xxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_xxz_set(stdmath_bool3* p, stdmath_bool3 value) { p->x = value.x; p->x = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_xyx(stdmath_bool3 v) { return {v.x,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_xyx_get(stdmath_bool3* p) { return stdmath_bool3_xyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_xyx_set(stdmath_bool3* p, stdmath_bool3 value) { p->x = value.x; p->y = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_xyy(stdmath_bool3 v) { return {v.x,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_xyy_get(stdmath_bool3* p) { return stdmath_bool3_xyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_xyy_set(stdmath_bool3* p, stdmath_bool3 value) { p->x = value.x; p->y = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_xyz(stdmath_bool3 v) { return {v.x,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_xyz_get(stdmath_bool3* p) { return stdmath_bool3_xyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_xyz_set(stdmath_bool3* p, stdmath_bool3 value) { p->x = value.x; p->y = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_xzx(stdmath_bool3 v) { return {v.x,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_xzx_get(stdmath_bool3* p) { return stdmath_bool3_xzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_xzx_set(stdmath_bool3* p, stdmath_bool3 value) { p->x = value.x; p->z = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_xzy(stdmath_bool3 v) { return {v.x,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_xzy_get(stdmath_bool3* p) { return stdmath_bool3_xzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_xzy_set(stdmath_bool3* p, stdmath_bool3 value) { p->x = value.x; p->z = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_xzz(stdmath_bool3 v) { return {v.x,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_xzz_get(stdmath_bool3* p) { return stdmath_bool3_xzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_xzz_set(stdmath_bool3* p, stdmath_bool3 value) { p->x = value.x; p->z = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_yxx(stdmath_bool3 v) { return {v.y,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_yxx_get(stdmath_bool3* p) { return stdmath_bool3_yxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_yxx_set(stdmath_bool3* p, stdmath_bool3 value) { p->y = value.x; p->x = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_yxy(stdmath_bool3 v) { return {v.y,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_yxy_get(stdmath_bool3* p) { return stdmath_bool3_yxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_yxy_set(stdmath_bool3* p, stdmath_bool3 value) { p->y = value.x; p->x = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_yxz(stdmath_bool3 v) { return {v.y,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_yxz_get(stdmath_bool3* p) { return stdmath_bool3_yxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_yxz_set(stdmath_bool3* p, stdmath_bool3 value) { p->y = value.x; p->x = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_yyx(stdmath_bool3 v) { return {v.y,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_yyx_get(stdmath_bool3* p) { return stdmath_bool3_yyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_yyx_set(stdmath_bool3* p, stdmath_bool3 value) { p->y = value.x; p->y = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_yyy(stdmath_bool3 v) { return {v.y,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_yyy_get(stdmath_bool3* p) { return stdmath_bool3_yyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_yyy_set(stdmath_bool3* p, stdmath_bool3 value) { p->y = value.x; p->y = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_yyz(stdmath_bool3 v) { return {v.y,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_yyz_get(stdmath_bool3* p) { return stdmath_bool3_yyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_yyz_set(stdmath_bool3* p, stdmath_bool3 value) { p->y = value.x; p->y = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_yzx(stdmath_bool3 v) { return {v.y,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_yzx_get(stdmath_bool3* p) { return stdmath_bool3_yzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_yzx_set(stdmath_bool3* p, stdmath_bool3 value) { p->y = value.x; p->z = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_yzy(stdmath_bool3 v) { return {v.y,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_yzy_get(stdmath_bool3* p) { return stdmath_bool3_yzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_yzy_set(stdmath_bool3* p, stdmath_bool3 value) { p->y = value.x; p->z = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_yzz(stdmath_bool3 v) { return {v.y,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_yzz_get(stdmath_bool3* p) { return stdmath_bool3_yzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_yzz_set(stdmath_bool3* p, stdmath_bool3 value) { p->y = value.x; p->z = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_zxx(stdmath_bool3 v) { return {v.z,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_zxx_get(stdmath_bool3* p) { return stdmath_bool3_zxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_zxx_set(stdmath_bool3* p, stdmath_bool3 value) { p->z = value.x; p->x = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_zxy(stdmath_bool3 v) { return {v.z,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_zxy_get(stdmath_bool3* p) { return stdmath_bool3_zxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_zxy_set(stdmath_bool3* p, stdmath_bool3 value) { p->z = value.x; p->x = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_zxz(stdmath_bool3 v) { return {v.z,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_zxz_get(stdmath_bool3* p) { return stdmath_bool3_zxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_zxz_set(stdmath_bool3* p, stdmath_bool3 value) { p->z = value.x; p->x = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_zyx(stdmath_bool3 v) { return {v.z,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_zyx_get(stdmath_bool3* p) { return stdmath_bool3_zyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_zyx_set(stdmath_bool3* p, stdmath_bool3 value) { p->z = value.x; p->y = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_zyy(stdmath_bool3 v) { return {v.z,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_zyy_get(stdmath_bool3* p) { return stdmath_bool3_zyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_zyy_set(stdmath_bool3* p, stdmath_bool3 value) { p->z = value.x; p->y = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_zyz(stdmath_bool3 v) { return {v.z,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_zyz_get(stdmath_bool3* p) { return stdmath_bool3_zyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_zyz_set(stdmath_bool3* p, stdmath_bool3 value) { p->z = value.x; p->y = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_zzx(stdmath_bool3 v) { return {v.z,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_zzx_get(stdmath_bool3* p) { return stdmath_bool3_zzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_zzx_set(stdmath_bool3* p, stdmath_bool3 value) { p->z = value.x; p->z = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_zzy(stdmath_bool3 v) { return {v.z,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_zzy_get(stdmath_bool3* p) { return stdmath_bool3_zzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_zzy_set(stdmath_bool3* p, stdmath_bool3 value) { p->z = value.x; p->z = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_zzz(stdmath_bool3 v) { return {v.z,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_zzz_get(stdmath_bool3* p) { return stdmath_bool3_zzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_bool3 stdmath_bool3_zzz_set(stdmath_bool3* p, stdmath_bool3 value) { p->z = value.x; p->z = value.y; p->z = value.z; return *p; }

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

inline stdmath::bool3 c(stdmath_bool3 c) {
	return (stdmath::bool3&)c;
}
inline stdmath_bool3 c(stdmath::bool3 c) {
	return (stdmath_bool3&)c;
}

#ifdef __cplusplus
extern "C" {
#endif

stdmath_bool3 stdmath_bool3_broadcast(bool all) {
	return c(stdmath::bool3((stdmath::bool3::underlying_type)all));
}

stdmath_bool3 stdmath_bool3_add(stdmath_bool3 a, stdmath_bool3 b) {
	return c(c(a) + c(b));
}
stdmath_bool3 stdmath_bool3_subtract(stdmath_bool3 a, stdmath_bool3 b) {
	return c(c(a) - c(b));
}
stdmath_bool3 stdmath_bool3_negate(stdmath_bool3 v) {
	return c(stdmath::bool3(-(stdmath::vector<bool, 3>)c(v)));
}
stdmath_bool3 stdmath_bool3_multiply(stdmath_bool3 a, stdmath_bool3 b) {
	return c(c(a) * c(b));
}
stdmath_bool3 stdmath_bool3_divide(stdmath_bool3 a, stdmath_bool3 b) {
	return c(c(a) / c(b));
}
stdmath_bool3 stdmath_bool3_scale(stdmath_bool3 v, bool s) {
	return c(c(v) * (stdmath::bool3::underlying_type)s);
}

#if false
stdmath_bool3 stdmath_bool3_modulus(stdmath_bool3 a, stdmath_bool3 b) {
	return c(c(a) % c(b));
}
stdmath_bool3 stdmath_bool3_logical_not(stdmath_bool3 v) {
	return c(!c(v));
}
stdmath_bool3 stdmath_bool3_bitwise_not(stdmath_bool3 v) {
	return c(~c(v));
}
stdmath_bool3 stdmath_bool3_logical_and(stdmath_bool3 a, stdmath_bool3 b) {
	return c(c(a) && c(b));
}
stdmath_bool3 stdmath_bool3_bitwise_and(stdmath_bool3 a, stdmath_bool3 b) {
	return c(c(a) & c(b));
}
stdmath_bool3 stdmath_bool3_logical_or(stdmath_bool3 a, stdmath_bool3 b) {
	return c(c(a) || c(b));
}
stdmath_bool3 stdmath_bool3_bitwise_or(stdmath_bool3 a, stdmath_bool3 b) {
	return c(c(a) | c(b));
}
stdmath_bool3 stdmath_bool3_bitwise_xor(stdmath_bool3 a, stdmath_bool3 b) {
	return c(c(a) ^ c(b));
}
stdmath_bool3 stdmath_bool3_shift_left(stdmath_bool3 a, stdmath_bool3 b) {
	return c(c(a) << c(b));
}
stdmath_bool3 stdmath_bool3_shift_right(stdmath_bool3 a, stdmath_bool3 b) {
	return c(c(a) >> c(b));
}
#endif

stdmath_bool3 stdmath_bool3_equal_to(stdmath_bool3 a, stdmath_bool3 b) {
	return c(c(a) == c(b));
}
stdmath_bool3 stdmath_bool3_not_equal_to(stdmath_bool3 a, stdmath_bool3 b) {
	return c(c(a) != c(b));
}
stdmath_bool3 stdmath_bool3_less_than(stdmath_bool3 a, stdmath_bool3 b) {
	return c(c(a) < c(b));
}
stdmath_bool3 stdmath_bool3_less_than_or_equal_to(stdmath_bool3 a, stdmath_bool3 b) {
	return c(c(a) <= c(b));
}
stdmath_bool3 stdmath_bool3_greater_than(stdmath_bool3 a, stdmath_bool3 b) {
	return c(c(a) > c(b));
}
stdmath_bool3 stdmath_bool3_greater_than_or_equal_to(stdmath_bool3 a, stdmath_bool3 b) {
	return c(c(a) >= c(b));
}

bool stdmath_bool3_length_squared(stdmath_bool3 v)  {
	return (bool)c(v).length_squared();
}
bool stdmath_bool3_length(stdmath_bool3 v)  {
	return (bool)c(v).length();
}
bool stdmath_bool3_dot(stdmath_bool3 a, stdmath_bool3 b)  {
	return (bool)dot(c(a), c(b));
}
bool stdmath_bool3_min_element(stdmath_bool3 v)  {
	return (bool)c(v).min_element();
}
bool stdmath_bool3_max_element(stdmath_bool3 v)  {
	return (bool)c(v).max_element();
}

stdmath_bool3 stdmath_bool3_elementwise_transform(stdmath_bool3 v, bool(*func)(bool)) {
	return c(c(v).elementwise_transform(func));
}
// bool stdmath_bool3_reduce_elements(stdmath_bool3 v, bool initial_value, bool(*reducer)(stdmath_bool3, stdmath_bool3)) {
// 	return c(v).reduce_elements(initial_value, reducer);
// }

#if 3 == 3
stdmath_bool3 stdmath_bool3_cross(stdmath_bool3 a, stdmath_bool3 b) {
	return c(cross(c(a), c(b)));
}
#endif

stdmath_bool3 stdmath_bool3_min(stdmath_bool3 a, stdmath_bool3 b) {
	return c(min(c(a), c(b)));
}
stdmath_bool3 stdmath_bool3_max(stdmath_bool3 a, stdmath_bool3 b) {
	return c(max(c(a), c(b)));
}
stdmath_bool3 stdmath_bool3_normalize(stdmath_bool3 v) {
	return c(normalize(c(v)));
}
stdmath_bool3 stdmath_bool3_lerp(stdmath_bool3 a, stdmath_bool3 b, float t) {
	return c(lerp(c(a), c(b), t));
}
stdmath_bool3 stdmath_bool3_clamp(stdmath_bool3 a, stdmath_bool3 min, stdmath_bool3 max) {
	return c(clamp(c(a), c(min), c(max)));
}
stdmath_bool3 stdmath_bool3_reflect(stdmath_bool3 a, stdmath_bool3 b) {
	return c(reflect(c(a), c(b)));
}
stdmath_bool3 stdmath_bool3_approximately_equal(stdmath_bool3 a, stdmath_bool3 b) {
	return c(approximately_equal(c(a), c(b)));
}

#if true
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

#endif // __STDMATH_bool3_H__