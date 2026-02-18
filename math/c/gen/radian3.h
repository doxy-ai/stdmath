#ifndef __STDMATH_stdmath_radian3_H__
#define __STDMATH_stdmath_radian3_H__

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
#include "radian1.h"
#elif 3 == 3
#include "radian2.h"
#include "radian1.h"
#elif 3 == 4
#include "radian3.h"
#include "radian2.h"
#include "radian1.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if 3 == 1
STDMATH_EXPORT union stdmath_radian1 {
	struct {
		stdmath_radian x;
	};
	stdmath_radian data[1];
};
#elif 3 == 2
STDMATH_EXPORT union stdmath_radian2 {
	struct {
		stdmath_radian x, y;
	};
	struct {
		stdmath_radian u, v;
	};
	stdmath_radian data[2];
};
#elif 3 == 3
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
#elif 3 == 4
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

STDMATH_EXPORT stdmath_radian3 stdmath_radian3_broadcast(stdmath_radian all);

STDMATH_EXPORT stdmath_radian3 stdmath_radian3_add(stdmath_radian3 a, stdmath_radian3 b);
STDMATH_EXPORT stdmath_radian3 stdmath_radian3_subtract(stdmath_radian3 a, stdmath_radian3 b);
STDMATH_EXPORT stdmath_radian3 stdmath_radian3_negate(stdmath_radian3 v);
STDMATH_EXPORT stdmath_radian3 stdmath_radian3_multiply(stdmath_radian3 a, stdmath_radian3 b);
STDMATH_EXPORT stdmath_radian3 stdmath_radian3_divide(stdmath_radian3 a, stdmath_radian3 b);
STDMATH_EXPORT stdmath_radian3 stdmath_radian3_scale(stdmath_radian3 v, stdmath_radian s);

#if false
STDMATH_EXPORT stdmath_radian3 stdmath_radian3_modulus(stdmath_radian3 a, stdmath_radian3 b);
STDMATH_EXPORT stdmath_radian3 stdmath_radian3_logical_not(stdmath_radian3 v);
STDMATH_EXPORT stdmath_radian3 stdmath_radian3_bitwise_not(stdmath_radian3 v);
STDMATH_EXPORT stdmath_radian3 stdmath_radian3_logical_and(stdmath_radian3 a, stdmath_radian3 b);
STDMATH_EXPORT stdmath_radian3 stdmath_radian3_bitwise_and(stdmath_radian3 a, stdmath_radian3 b);
STDMATH_EXPORT stdmath_radian3 stdmath_radian3_logical_or(stdmath_radian3 a, stdmath_radian3 b);
STDMATH_EXPORT stdmath_radian3 stdmath_radian3_bitwise_or(stdmath_radian3 a, stdmath_radian3 b);
STDMATH_EXPORT stdmath_radian3 stdmath_radian3_bitwise_xor(stdmath_radian3 a, stdmath_radian3 b);
STDMATH_EXPORT stdmath_radian3 stdmath_radian3_shift_left(stdmath_radian3 a, stdmath_radian3 b);
STDMATH_EXPORT stdmath_radian3 stdmath_radian3_shift_right(stdmath_radian3 a, stdmath_radian3 b);
#endif

STDMATH_EXPORT stdmath_bool3 stdmath_radian3_equal_to(stdmath_radian3 a, stdmath_radian3 b);
STDMATH_EXPORT stdmath_bool3 stdmath_radian3_not_equal_to(stdmath_radian3 a, stdmath_radian3 b);
STDMATH_EXPORT stdmath_bool3 stdmath_radian3_less_than(stdmath_radian3 a, stdmath_radian3 b);
STDMATH_EXPORT stdmath_bool3 stdmath_radian3_less_than_or_equal_to(stdmath_radian3 a, stdmath_radian3 b);
STDMATH_EXPORT stdmath_bool3 stdmath_radian3_greater_than(stdmath_radian3 a, stdmath_radian3 b);
STDMATH_EXPORT stdmath_bool3 stdmath_radian3_greater_than_or_equal_to(stdmath_radian3 a, stdmath_radian3 b);

STDMATH_EXPORT stdmath_radian stdmath_radian3_length_squared(stdmath_radian3 v);
STDMATH_EXPORT stdmath_radian stdmath_radian3_length(stdmath_radian3 v);
STDMATH_EXPORT stdmath_radian stdmath_radian3_dot(stdmath_radian3 a, stdmath_radian3 b);
STDMATH_EXPORT stdmath_radian stdmath_radian3_min_element(stdmath_radian3 v);
STDMATH_EXPORT stdmath_radian stdmath_radian3_max_element(stdmath_radian3 v);

// STDMATH_EXPORT stdmath_radian3 stdmath_radian3_elementwise_transform(stdmath_radian3 v, stdmath_radian(*func)(stdmath_radian));
// STDMATH_EXPORT stdmath_radian stdmath_radian3_reduce_elements(stdmath_radian3 v, stdmath_radian initial_value, stdmath_radian(*reducer)(stdmath_radian3, stdmath_radian3));

#if 3 == 3
STDMATH_EXPORT stdmath_radian3 stdmath_radian3_cross(stdmath_radian3 a, stdmath_radian3 b);
#endif

STDMATH_EXPORT stdmath_radian3 stdmath_radian3_min(stdmath_radian3 a, stdmath_radian3 b);
STDMATH_EXPORT stdmath_radian3 stdmath_radian3_max(stdmath_radian3 a, stdmath_radian3 b);
STDMATH_EXPORT stdmath_radian3 stdmath_radian3_normalize(stdmath_radian3 v);
STDMATH_EXPORT stdmath_radian3 stdmath_radian3_lerp(stdmath_radian3 a, stdmath_radian3 b, float t);
STDMATH_EXPORT stdmath_radian3 stdmath_radian3_clamp(stdmath_radian3 a, stdmath_radian3 min, stdmath_radian3 max);
STDMATH_EXPORT stdmath_radian3 stdmath_radian3_reflect(stdmath_radian3 a, stdmath_radian3 b);
STDMATH_EXPORT stdmath_bool3 stdmath_radian3_approximately_equal(stdmath_radian3 a, stdmath_radian3 b);

#if false
STDMATH_EXPORT bool stdmath_bool3_all_of(stdmath_bool3 v);
STDMATH_EXPORT bool stdmath_bool3_any_of(stdmath_bool3 v);
STDMATH_EXPORT bool stdmath_bool3_none_of(stdmath_bool3 v);
STDMATH_EXPORT bool stdmath_bool3_some_of(stdmath_bool3 v);
#endif

#ifndef STDMATH_NO_SWIZZLES
STDMATH_EXPORT STDMATH_INLINE stdmath_radian1 stdmath_radian3_x(stdmath_radian3 v) { return {v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian1 stdmath_radian3_x_get(stdmath_radian3* p) { return stdmath_radian3_x(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_x_set(stdmath_radian3* p, stdmath_radian1 value) { p->x = value.x; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian1 stdmath_radian3_y(stdmath_radian3 v) { return {v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian1 stdmath_radian3_y_get(stdmath_radian3* p) { return stdmath_radian3_y(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_y_set(stdmath_radian3* p, stdmath_radian1 value) { p->y = value.x; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian1 stdmath_radian3_z(stdmath_radian3 v) { return {v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian1 stdmath_radian3_z_get(stdmath_radian3* p) { return stdmath_radian3_z(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_z_set(stdmath_radian3* p, stdmath_radian1 value) { p->z = value.x; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian3_xx(stdmath_radian3 v) { return {v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian3_xx_get(stdmath_radian3* p) { return stdmath_radian3_xx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_xx_set(stdmath_radian3* p, stdmath_radian2 value) { p->x = value.x; p->x = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian3_xy(stdmath_radian3 v) { return {v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian3_xy_get(stdmath_radian3* p) { return stdmath_radian3_xy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_xy_set(stdmath_radian3* p, stdmath_radian2 value) { p->x = value.x; p->y = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian3_xz(stdmath_radian3 v) { return {v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian3_xz_get(stdmath_radian3* p) { return stdmath_radian3_xz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_xz_set(stdmath_radian3* p, stdmath_radian2 value) { p->x = value.x; p->z = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian3_yx(stdmath_radian3 v) { return {v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian3_yx_get(stdmath_radian3* p) { return stdmath_radian3_yx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_yx_set(stdmath_radian3* p, stdmath_radian2 value) { p->y = value.x; p->x = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian3_yy(stdmath_radian3 v) { return {v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian3_yy_get(stdmath_radian3* p) { return stdmath_radian3_yy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_yy_set(stdmath_radian3* p, stdmath_radian2 value) { p->y = value.x; p->y = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian3_yz(stdmath_radian3 v) { return {v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian3_yz_get(stdmath_radian3* p) { return stdmath_radian3_yz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_yz_set(stdmath_radian3* p, stdmath_radian2 value) { p->y = value.x; p->z = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian3_zx(stdmath_radian3 v) { return {v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian3_zx_get(stdmath_radian3* p) { return stdmath_radian3_zx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_zx_set(stdmath_radian3* p, stdmath_radian2 value) { p->z = value.x; p->x = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian3_zy(stdmath_radian3 v) { return {v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian3_zy_get(stdmath_radian3* p) { return stdmath_radian3_zy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_zy_set(stdmath_radian3* p, stdmath_radian2 value) { p->z = value.x; p->y = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian3_zz(stdmath_radian3 v) { return {v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian3_zz_get(stdmath_radian3* p) { return stdmath_radian3_zz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_zz_set(stdmath_radian3* p, stdmath_radian2 value) { p->z = value.x; p->z = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_xxx(stdmath_radian3 v) { return {v.x,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_xxx_get(stdmath_radian3* p) { return stdmath_radian3_xxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_xxx_set(stdmath_radian3* p, stdmath_radian3 value) { p->x = value.x; p->x = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_xxy(stdmath_radian3 v) { return {v.x,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_xxy_get(stdmath_radian3* p) { return stdmath_radian3_xxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_xxy_set(stdmath_radian3* p, stdmath_radian3 value) { p->x = value.x; p->x = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_xxz(stdmath_radian3 v) { return {v.x,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_xxz_get(stdmath_radian3* p) { return stdmath_radian3_xxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_xxz_set(stdmath_radian3* p, stdmath_radian3 value) { p->x = value.x; p->x = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_xyx(stdmath_radian3 v) { return {v.x,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_xyx_get(stdmath_radian3* p) { return stdmath_radian3_xyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_xyx_set(stdmath_radian3* p, stdmath_radian3 value) { p->x = value.x; p->y = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_xyy(stdmath_radian3 v) { return {v.x,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_xyy_get(stdmath_radian3* p) { return stdmath_radian3_xyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_xyy_set(stdmath_radian3* p, stdmath_radian3 value) { p->x = value.x; p->y = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_xyz(stdmath_radian3 v) { return {v.x,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_xyz_get(stdmath_radian3* p) { return stdmath_radian3_xyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_xyz_set(stdmath_radian3* p, stdmath_radian3 value) { p->x = value.x; p->y = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_xzx(stdmath_radian3 v) { return {v.x,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_xzx_get(stdmath_radian3* p) { return stdmath_radian3_xzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_xzx_set(stdmath_radian3* p, stdmath_radian3 value) { p->x = value.x; p->z = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_xzy(stdmath_radian3 v) { return {v.x,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_xzy_get(stdmath_radian3* p) { return stdmath_radian3_xzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_xzy_set(stdmath_radian3* p, stdmath_radian3 value) { p->x = value.x; p->z = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_xzz(stdmath_radian3 v) { return {v.x,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_xzz_get(stdmath_radian3* p) { return stdmath_radian3_xzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_xzz_set(stdmath_radian3* p, stdmath_radian3 value) { p->x = value.x; p->z = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_yxx(stdmath_radian3 v) { return {v.y,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_yxx_get(stdmath_radian3* p) { return stdmath_radian3_yxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_yxx_set(stdmath_radian3* p, stdmath_radian3 value) { p->y = value.x; p->x = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_yxy(stdmath_radian3 v) { return {v.y,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_yxy_get(stdmath_radian3* p) { return stdmath_radian3_yxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_yxy_set(stdmath_radian3* p, stdmath_radian3 value) { p->y = value.x; p->x = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_yxz(stdmath_radian3 v) { return {v.y,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_yxz_get(stdmath_radian3* p) { return stdmath_radian3_yxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_yxz_set(stdmath_radian3* p, stdmath_radian3 value) { p->y = value.x; p->x = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_yyx(stdmath_radian3 v) { return {v.y,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_yyx_get(stdmath_radian3* p) { return stdmath_radian3_yyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_yyx_set(stdmath_radian3* p, stdmath_radian3 value) { p->y = value.x; p->y = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_yyy(stdmath_radian3 v) { return {v.y,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_yyy_get(stdmath_radian3* p) { return stdmath_radian3_yyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_yyy_set(stdmath_radian3* p, stdmath_radian3 value) { p->y = value.x; p->y = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_yyz(stdmath_radian3 v) { return {v.y,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_yyz_get(stdmath_radian3* p) { return stdmath_radian3_yyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_yyz_set(stdmath_radian3* p, stdmath_radian3 value) { p->y = value.x; p->y = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_yzx(stdmath_radian3 v) { return {v.y,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_yzx_get(stdmath_radian3* p) { return stdmath_radian3_yzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_yzx_set(stdmath_radian3* p, stdmath_radian3 value) { p->y = value.x; p->z = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_yzy(stdmath_radian3 v) { return {v.y,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_yzy_get(stdmath_radian3* p) { return stdmath_radian3_yzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_yzy_set(stdmath_radian3* p, stdmath_radian3 value) { p->y = value.x; p->z = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_yzz(stdmath_radian3 v) { return {v.y,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_yzz_get(stdmath_radian3* p) { return stdmath_radian3_yzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_yzz_set(stdmath_radian3* p, stdmath_radian3 value) { p->y = value.x; p->z = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_zxx(stdmath_radian3 v) { return {v.z,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_zxx_get(stdmath_radian3* p) { return stdmath_radian3_zxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_zxx_set(stdmath_radian3* p, stdmath_radian3 value) { p->z = value.x; p->x = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_zxy(stdmath_radian3 v) { return {v.z,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_zxy_get(stdmath_radian3* p) { return stdmath_radian3_zxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_zxy_set(stdmath_radian3* p, stdmath_radian3 value) { p->z = value.x; p->x = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_zxz(stdmath_radian3 v) { return {v.z,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_zxz_get(stdmath_radian3* p) { return stdmath_radian3_zxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_zxz_set(stdmath_radian3* p, stdmath_radian3 value) { p->z = value.x; p->x = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_zyx(stdmath_radian3 v) { return {v.z,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_zyx_get(stdmath_radian3* p) { return stdmath_radian3_zyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_zyx_set(stdmath_radian3* p, stdmath_radian3 value) { p->z = value.x; p->y = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_zyy(stdmath_radian3 v) { return {v.z,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_zyy_get(stdmath_radian3* p) { return stdmath_radian3_zyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_zyy_set(stdmath_radian3* p, stdmath_radian3 value) { p->z = value.x; p->y = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_zyz(stdmath_radian3 v) { return {v.z,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_zyz_get(stdmath_radian3* p) { return stdmath_radian3_zyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_zyz_set(stdmath_radian3* p, stdmath_radian3 value) { p->z = value.x; p->y = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_zzx(stdmath_radian3 v) { return {v.z,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_zzx_get(stdmath_radian3* p) { return stdmath_radian3_zzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_zzx_set(stdmath_radian3* p, stdmath_radian3 value) { p->z = value.x; p->z = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_zzy(stdmath_radian3 v) { return {v.z,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_zzy_get(stdmath_radian3* p) { return stdmath_radian3_zzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_zzy_set(stdmath_radian3* p, stdmath_radian3 value) { p->z = value.x; p->z = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_zzz(stdmath_radian3 v) { return {v.z,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_zzz_get(stdmath_radian3* p) { return stdmath_radian3_zzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian3 stdmath_radian3_zzz_set(stdmath_radian3* p, stdmath_radian3 value) { p->z = value.x; p->z = value.y; p->z = value.z; return *p; }

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

inline stdmath::radian3 c(stdmath_radian3 c) {
	return (stdmath::radian3&)c;
}
inline stdmath_radian3 c(stdmath::radian3 c) {
	return (stdmath_radian3&)c;
}

#ifdef __cplusplus
extern "C" {
#endif

stdmath_radian3 stdmath_radian3_broadcast(stdmath_radian all) {
	return c(stdmath::radian3((stdmath::radian3::underlying_type&)all));
}

stdmath_radian3 stdmath_radian3_add(stdmath_radian3 a, stdmath_radian3 b) {
	return c(c(a) + c(b));
}
stdmath_radian3 stdmath_radian3_subtract(stdmath_radian3 a, stdmath_radian3 b) {
	return c(c(a) - c(b));
}
stdmath_radian3 stdmath_radian3_negate(stdmath_radian3 v) {
#if !true && !false
	return c(stdmath::radian3(-(stdmath::vector<stdmath_radian, 3>)c(v)));
#else
	assert(false && "TODO: Why can't we use - on vector<degree/radian, N>?");
#endif
}
stdmath_radian3 stdmath_radian3_multiply(stdmath_radian3 a, stdmath_radian3 b) {
	return c(c(a) * c(b));
}
stdmath_radian3 stdmath_radian3_divide(stdmath_radian3 a, stdmath_radian3 b) {
	return c(c(a) / c(b));
}
stdmath_radian3 stdmath_radian3_scale(stdmath_radian3 v, stdmath_radian s) {
	return c(c(v) * (stdmath::radian3::underlying_type&)s);
}

#if false
stdmath_radian3 stdmath_radian3_modulus(stdmath_radian3 a, stdmath_radian3 b) {
	return c(c(a) % c(b));
}
stdmath_radian3 stdmath_radian3_logical_not(stdmath_radian3 v) {
	return c(!c(v));
}
stdmath_radian3 stdmath_radian3_bitwise_not(stdmath_radian3 v) {
	return c(~c(v));
}
stdmath_radian3 stdmath_radian3_logical_and(stdmath_radian3 a, stdmath_radian3 b) {
	return c(c(a) && c(b));
}
stdmath_radian3 stdmath_radian3_bitwise_and(stdmath_radian3 a, stdmath_radian3 b) {
	return c(c(a) & c(b));
}
stdmath_radian3 stdmath_radian3_logical_or(stdmath_radian3 a, stdmath_radian3 b) {
	return c(c(a) || c(b));
}
stdmath_radian3 stdmath_radian3_bitwise_or(stdmath_radian3 a, stdmath_radian3 b) {
	return c(c(a) | c(b));
}
stdmath_radian3 stdmath_radian3_bitwise_xor(stdmath_radian3 a, stdmath_radian3 b) {
	return c(c(a) ^ c(b));
}
stdmath_radian3 stdmath_radian3_shift_left(stdmath_radian3 a, stdmath_radian3 b) {
	return c(c(a) << c(b));
}
stdmath_radian3 stdmath_radian3_shift_right(stdmath_radian3 a, stdmath_radian3 b) {
	return c(c(a) >> c(b));
}
#endif

stdmath_bool3 stdmath_radian3_equal_to(stdmath_radian3 a, stdmath_radian3 b) {
	return c(c(a) == c(b));
}
stdmath_bool3 stdmath_radian3_not_equal_to(stdmath_radian3 a, stdmath_radian3 b) {
	return c(c(a) != c(b));
}
stdmath_bool3 stdmath_radian3_less_than(stdmath_radian3 a, stdmath_radian3 b) {
	return c(c(a) < c(b));
}
stdmath_bool3 stdmath_radian3_less_than_or_equal_to(stdmath_radian3 a, stdmath_radian3 b) {
	return c(c(a) <= c(b));
}
stdmath_bool3 stdmath_radian3_greater_than(stdmath_radian3 a, stdmath_radian3 b) {
	return c(c(a) > c(b));
}
stdmath_bool3 stdmath_radian3_greater_than_or_equal_to(stdmath_radian3 a, stdmath_radian3 b) {
	return c(c(a) >= c(b));
}

stdmath_radian stdmath_radian3_length_squared(stdmath_radian3 v)  {
	auto out = c(v).length_squared();
	return (stdmath_radian&)out;
}
stdmath_radian stdmath_radian3_length(stdmath_radian3 v)  {
	auto out = c(v).length();
	return (stdmath_radian&)out;
}
stdmath_radian stdmath_radian3_dot(stdmath_radian3 a, stdmath_radian3 b)  {
	auto out = dot(c(a), c(b));
	return (stdmath_radian&)out;
}
stdmath_radian stdmath_radian3_min_element(stdmath_radian3 v)  {
	auto out = c(v).min_element();
	return (stdmath_radian&)out;
}
stdmath_radian stdmath_radian3_max_element(stdmath_radian3 v)  {
	auto out = c(v).max_element();
	return (stdmath_radian&)out;
}

// stdmath_radian3 stdmath_radian3_elementwise_transform(stdmath_radian3 v, stdmath_radian(*func)(stdmath_radian)) {
// 	return c(c(v).elementwise_transform(func));
// }
// stdmath_radian stdmath_radian3_reduce_elements(stdmath_radian3 v, stdmath_radian initial_value, stdmath_radian(*reducer)(stdmath_radian3, stdmath_radian3)) {
// 	return c(v).reduce_elements(initial_value, reducer);
// }

#if 3 == 3
stdmath_radian3 stdmath_radian3_cross(stdmath_radian3 a, stdmath_radian3 b) {
	return c(cross(c(a), c(b)));
}
#endif

stdmath_radian3 stdmath_radian3_min(stdmath_radian3 a, stdmath_radian3 b) {
	return c(min(c(a), c(b)));
}
stdmath_radian3 stdmath_radian3_max(stdmath_radian3 a, stdmath_radian3 b) {
	return c(max(c(a), c(b)));
}
stdmath_radian3 stdmath_radian3_normalize(stdmath_radian3 v) {
	return c(normalize(c(v)));
}
stdmath_radian3 stdmath_radian3_lerp(stdmath_radian3 a, stdmath_radian3 b, float t) {
	return c(lerp(c(a), c(b), t));
}
stdmath_radian3 stdmath_radian3_clamp(stdmath_radian3 a, stdmath_radian3 min, stdmath_radian3 max) {
	return c(clamp(c(a), c(min), c(max)));
}
stdmath_radian3 stdmath_radian3_reflect(stdmath_radian3 a, stdmath_radian3 b) {
	return c(reflect(c(a), c(b)));
}
stdmath_bool3 stdmath_radian3_approximately_equal(stdmath_radian3 a, stdmath_radian3 b) {
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

#endif // __STDMATH_stdmath_radian3_H__