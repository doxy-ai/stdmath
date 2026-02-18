#ifndef __STDMATH_stdmath_degree3_H__
#define __STDMATH_stdmath_degree3_H__

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
#include "degree1.h"
#elif 3 == 3
#include "degree2.h"
#include "degree1.h"
#elif 3 == 4
#include "degree3.h"
#include "degree2.h"
#include "degree1.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if 3 == 1
STDMATH_EXPORT union stdmath_degree1 {
	struct {
		stdmath_degree x;
	};
	stdmath_degree data[1];
};
#elif 3 == 2
STDMATH_EXPORT union stdmath_degree2 {
	struct {
		stdmath_degree x, y;
	};
	struct {
		stdmath_degree u, v;
	};
	stdmath_degree data[2];
};
#elif 3 == 3
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
#elif 3 == 4
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

STDMATH_EXPORT stdmath_degree3 stdmath_degree3_broadcast(stdmath_degree all);

STDMATH_EXPORT stdmath_degree3 stdmath_degree3_add(stdmath_degree3 a, stdmath_degree3 b);
STDMATH_EXPORT stdmath_degree3 stdmath_degree3_subtract(stdmath_degree3 a, stdmath_degree3 b);
STDMATH_EXPORT stdmath_degree3 stdmath_degree3_negate(stdmath_degree3 v);
STDMATH_EXPORT stdmath_degree3 stdmath_degree3_multiply(stdmath_degree3 a, stdmath_degree3 b);
STDMATH_EXPORT stdmath_degree3 stdmath_degree3_divide(stdmath_degree3 a, stdmath_degree3 b);
STDMATH_EXPORT stdmath_degree3 stdmath_degree3_scale(stdmath_degree3 v, stdmath_degree s);

#if false
STDMATH_EXPORT stdmath_degree3 stdmath_degree3_modulus(stdmath_degree3 a, stdmath_degree3 b);
STDMATH_EXPORT stdmath_degree3 stdmath_degree3_logical_not(stdmath_degree3 v);
STDMATH_EXPORT stdmath_degree3 stdmath_degree3_bitwise_not(stdmath_degree3 v);
STDMATH_EXPORT stdmath_degree3 stdmath_degree3_logical_and(stdmath_degree3 a, stdmath_degree3 b);
STDMATH_EXPORT stdmath_degree3 stdmath_degree3_bitwise_and(stdmath_degree3 a, stdmath_degree3 b);
STDMATH_EXPORT stdmath_degree3 stdmath_degree3_logical_or(stdmath_degree3 a, stdmath_degree3 b);
STDMATH_EXPORT stdmath_degree3 stdmath_degree3_bitwise_or(stdmath_degree3 a, stdmath_degree3 b);
STDMATH_EXPORT stdmath_degree3 stdmath_degree3_bitwise_xor(stdmath_degree3 a, stdmath_degree3 b);
STDMATH_EXPORT stdmath_degree3 stdmath_degree3_shift_left(stdmath_degree3 a, stdmath_degree3 b);
STDMATH_EXPORT stdmath_degree3 stdmath_degree3_shift_right(stdmath_degree3 a, stdmath_degree3 b);
#endif

STDMATH_EXPORT stdmath_bool3 stdmath_degree3_equal_to(stdmath_degree3 a, stdmath_degree3 b);
STDMATH_EXPORT stdmath_bool3 stdmath_degree3_not_equal_to(stdmath_degree3 a, stdmath_degree3 b);
STDMATH_EXPORT stdmath_bool3 stdmath_degree3_less_than(stdmath_degree3 a, stdmath_degree3 b);
STDMATH_EXPORT stdmath_bool3 stdmath_degree3_less_than_or_equal_to(stdmath_degree3 a, stdmath_degree3 b);
STDMATH_EXPORT stdmath_bool3 stdmath_degree3_greater_than(stdmath_degree3 a, stdmath_degree3 b);
STDMATH_EXPORT stdmath_bool3 stdmath_degree3_greater_than_or_equal_to(stdmath_degree3 a, stdmath_degree3 b);

STDMATH_EXPORT stdmath_degree stdmath_degree3_length_squared(stdmath_degree3 v);
STDMATH_EXPORT stdmath_degree stdmath_degree3_length(stdmath_degree3 v);
STDMATH_EXPORT stdmath_degree stdmath_degree3_dot(stdmath_degree3 a, stdmath_degree3 b);
STDMATH_EXPORT stdmath_degree stdmath_degree3_min_element(stdmath_degree3 v);
STDMATH_EXPORT stdmath_degree stdmath_degree3_max_element(stdmath_degree3 v);

// STDMATH_EXPORT stdmath_degree3 stdmath_degree3_elementwise_transform(stdmath_degree3 v, stdmath_degree(*func)(stdmath_degree));
// STDMATH_EXPORT stdmath_degree stdmath_degree3_reduce_elements(stdmath_degree3 v, stdmath_degree initial_value, stdmath_degree(*reducer)(stdmath_degree3, stdmath_degree3));

#if 3 == 3
STDMATH_EXPORT stdmath_degree3 stdmath_degree3_cross(stdmath_degree3 a, stdmath_degree3 b);
#endif

STDMATH_EXPORT stdmath_degree3 stdmath_degree3_min(stdmath_degree3 a, stdmath_degree3 b);
STDMATH_EXPORT stdmath_degree3 stdmath_degree3_max(stdmath_degree3 a, stdmath_degree3 b);
STDMATH_EXPORT stdmath_degree3 stdmath_degree3_normalize(stdmath_degree3 v);
STDMATH_EXPORT stdmath_degree3 stdmath_degree3_lerp(stdmath_degree3 a, stdmath_degree3 b, float t);
STDMATH_EXPORT stdmath_degree3 stdmath_degree3_clamp(stdmath_degree3 a, stdmath_degree3 min, stdmath_degree3 max);
STDMATH_EXPORT stdmath_degree3 stdmath_degree3_reflect(stdmath_degree3 a, stdmath_degree3 b);
STDMATH_EXPORT stdmath_bool3 stdmath_degree3_approximately_equal(stdmath_degree3 a, stdmath_degree3 b);

#if false
STDMATH_EXPORT bool stdmath_bool3_all_of(stdmath_bool3 v);
STDMATH_EXPORT bool stdmath_bool3_any_of(stdmath_bool3 v);
STDMATH_EXPORT bool stdmath_bool3_none_of(stdmath_bool3 v);
STDMATH_EXPORT bool stdmath_bool3_some_of(stdmath_bool3 v);
#endif

#ifndef STDMATH_NO_SWIZZLES
STDMATH_EXPORT STDMATH_INLINE stdmath_degree1 stdmath_degree3_x(stdmath_degree3 v) { return {v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree1 stdmath_degree3_x_get(stdmath_degree3* p) { return stdmath_degree3_x(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_x_set(stdmath_degree3* p, stdmath_degree1 value) { p->x = value.x; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree1 stdmath_degree3_y(stdmath_degree3 v) { return {v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree1 stdmath_degree3_y_get(stdmath_degree3* p) { return stdmath_degree3_y(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_y_set(stdmath_degree3* p, stdmath_degree1 value) { p->y = value.x; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree1 stdmath_degree3_z(stdmath_degree3 v) { return {v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree1 stdmath_degree3_z_get(stdmath_degree3* p) { return stdmath_degree3_z(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_z_set(stdmath_degree3* p, stdmath_degree1 value) { p->z = value.x; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree3_xx(stdmath_degree3 v) { return {v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree3_xx_get(stdmath_degree3* p) { return stdmath_degree3_xx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_xx_set(stdmath_degree3* p, stdmath_degree2 value) { p->x = value.x; p->x = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree3_xy(stdmath_degree3 v) { return {v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree3_xy_get(stdmath_degree3* p) { return stdmath_degree3_xy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_xy_set(stdmath_degree3* p, stdmath_degree2 value) { p->x = value.x; p->y = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree3_xz(stdmath_degree3 v) { return {v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree3_xz_get(stdmath_degree3* p) { return stdmath_degree3_xz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_xz_set(stdmath_degree3* p, stdmath_degree2 value) { p->x = value.x; p->z = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree3_yx(stdmath_degree3 v) { return {v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree3_yx_get(stdmath_degree3* p) { return stdmath_degree3_yx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_yx_set(stdmath_degree3* p, stdmath_degree2 value) { p->y = value.x; p->x = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree3_yy(stdmath_degree3 v) { return {v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree3_yy_get(stdmath_degree3* p) { return stdmath_degree3_yy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_yy_set(stdmath_degree3* p, stdmath_degree2 value) { p->y = value.x; p->y = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree3_yz(stdmath_degree3 v) { return {v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree3_yz_get(stdmath_degree3* p) { return stdmath_degree3_yz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_yz_set(stdmath_degree3* p, stdmath_degree2 value) { p->y = value.x; p->z = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree3_zx(stdmath_degree3 v) { return {v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree3_zx_get(stdmath_degree3* p) { return stdmath_degree3_zx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_zx_set(stdmath_degree3* p, stdmath_degree2 value) { p->z = value.x; p->x = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree3_zy(stdmath_degree3 v) { return {v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree3_zy_get(stdmath_degree3* p) { return stdmath_degree3_zy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_zy_set(stdmath_degree3* p, stdmath_degree2 value) { p->z = value.x; p->y = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree3_zz(stdmath_degree3 v) { return {v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree3_zz_get(stdmath_degree3* p) { return stdmath_degree3_zz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_zz_set(stdmath_degree3* p, stdmath_degree2 value) { p->z = value.x; p->z = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_xxx(stdmath_degree3 v) { return {v.x,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_xxx_get(stdmath_degree3* p) { return stdmath_degree3_xxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_xxx_set(stdmath_degree3* p, stdmath_degree3 value) { p->x = value.x; p->x = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_xxy(stdmath_degree3 v) { return {v.x,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_xxy_get(stdmath_degree3* p) { return stdmath_degree3_xxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_xxy_set(stdmath_degree3* p, stdmath_degree3 value) { p->x = value.x; p->x = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_xxz(stdmath_degree3 v) { return {v.x,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_xxz_get(stdmath_degree3* p) { return stdmath_degree3_xxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_xxz_set(stdmath_degree3* p, stdmath_degree3 value) { p->x = value.x; p->x = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_xyx(stdmath_degree3 v) { return {v.x,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_xyx_get(stdmath_degree3* p) { return stdmath_degree3_xyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_xyx_set(stdmath_degree3* p, stdmath_degree3 value) { p->x = value.x; p->y = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_xyy(stdmath_degree3 v) { return {v.x,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_xyy_get(stdmath_degree3* p) { return stdmath_degree3_xyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_xyy_set(stdmath_degree3* p, stdmath_degree3 value) { p->x = value.x; p->y = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_xyz(stdmath_degree3 v) { return {v.x,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_xyz_get(stdmath_degree3* p) { return stdmath_degree3_xyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_xyz_set(stdmath_degree3* p, stdmath_degree3 value) { p->x = value.x; p->y = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_xzx(stdmath_degree3 v) { return {v.x,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_xzx_get(stdmath_degree3* p) { return stdmath_degree3_xzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_xzx_set(stdmath_degree3* p, stdmath_degree3 value) { p->x = value.x; p->z = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_xzy(stdmath_degree3 v) { return {v.x,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_xzy_get(stdmath_degree3* p) { return stdmath_degree3_xzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_xzy_set(stdmath_degree3* p, stdmath_degree3 value) { p->x = value.x; p->z = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_xzz(stdmath_degree3 v) { return {v.x,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_xzz_get(stdmath_degree3* p) { return stdmath_degree3_xzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_xzz_set(stdmath_degree3* p, stdmath_degree3 value) { p->x = value.x; p->z = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_yxx(stdmath_degree3 v) { return {v.y,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_yxx_get(stdmath_degree3* p) { return stdmath_degree3_yxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_yxx_set(stdmath_degree3* p, stdmath_degree3 value) { p->y = value.x; p->x = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_yxy(stdmath_degree3 v) { return {v.y,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_yxy_get(stdmath_degree3* p) { return stdmath_degree3_yxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_yxy_set(stdmath_degree3* p, stdmath_degree3 value) { p->y = value.x; p->x = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_yxz(stdmath_degree3 v) { return {v.y,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_yxz_get(stdmath_degree3* p) { return stdmath_degree3_yxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_yxz_set(stdmath_degree3* p, stdmath_degree3 value) { p->y = value.x; p->x = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_yyx(stdmath_degree3 v) { return {v.y,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_yyx_get(stdmath_degree3* p) { return stdmath_degree3_yyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_yyx_set(stdmath_degree3* p, stdmath_degree3 value) { p->y = value.x; p->y = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_yyy(stdmath_degree3 v) { return {v.y,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_yyy_get(stdmath_degree3* p) { return stdmath_degree3_yyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_yyy_set(stdmath_degree3* p, stdmath_degree3 value) { p->y = value.x; p->y = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_yyz(stdmath_degree3 v) { return {v.y,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_yyz_get(stdmath_degree3* p) { return stdmath_degree3_yyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_yyz_set(stdmath_degree3* p, stdmath_degree3 value) { p->y = value.x; p->y = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_yzx(stdmath_degree3 v) { return {v.y,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_yzx_get(stdmath_degree3* p) { return stdmath_degree3_yzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_yzx_set(stdmath_degree3* p, stdmath_degree3 value) { p->y = value.x; p->z = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_yzy(stdmath_degree3 v) { return {v.y,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_yzy_get(stdmath_degree3* p) { return stdmath_degree3_yzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_yzy_set(stdmath_degree3* p, stdmath_degree3 value) { p->y = value.x; p->z = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_yzz(stdmath_degree3 v) { return {v.y,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_yzz_get(stdmath_degree3* p) { return stdmath_degree3_yzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_yzz_set(stdmath_degree3* p, stdmath_degree3 value) { p->y = value.x; p->z = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_zxx(stdmath_degree3 v) { return {v.z,v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_zxx_get(stdmath_degree3* p) { return stdmath_degree3_zxx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_zxx_set(stdmath_degree3* p, stdmath_degree3 value) { p->z = value.x; p->x = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_zxy(stdmath_degree3 v) { return {v.z,v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_zxy_get(stdmath_degree3* p) { return stdmath_degree3_zxy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_zxy_set(stdmath_degree3* p, stdmath_degree3 value) { p->z = value.x; p->x = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_zxz(stdmath_degree3 v) { return {v.z,v.x,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_zxz_get(stdmath_degree3* p) { return stdmath_degree3_zxz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_zxz_set(stdmath_degree3* p, stdmath_degree3 value) { p->z = value.x; p->x = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_zyx(stdmath_degree3 v) { return {v.z,v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_zyx_get(stdmath_degree3* p) { return stdmath_degree3_zyx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_zyx_set(stdmath_degree3* p, stdmath_degree3 value) { p->z = value.x; p->y = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_zyy(stdmath_degree3 v) { return {v.z,v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_zyy_get(stdmath_degree3* p) { return stdmath_degree3_zyy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_zyy_set(stdmath_degree3* p, stdmath_degree3 value) { p->z = value.x; p->y = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_zyz(stdmath_degree3 v) { return {v.z,v.y,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_zyz_get(stdmath_degree3* p) { return stdmath_degree3_zyz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_zyz_set(stdmath_degree3* p, stdmath_degree3 value) { p->z = value.x; p->y = value.y; p->z = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_zzx(stdmath_degree3 v) { return {v.z,v.z,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_zzx_get(stdmath_degree3* p) { return stdmath_degree3_zzx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_zzx_set(stdmath_degree3* p, stdmath_degree3 value) { p->z = value.x; p->z = value.y; p->x = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_zzy(stdmath_degree3 v) { return {v.z,v.z,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_zzy_get(stdmath_degree3* p) { return stdmath_degree3_zzy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_zzy_set(stdmath_degree3* p, stdmath_degree3 value) { p->z = value.x; p->z = value.y; p->y = value.z; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_zzz(stdmath_degree3 v) { return {v.z,v.z,v.z}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_zzz_get(stdmath_degree3* p) { return stdmath_degree3_zzz(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree3 stdmath_degree3_zzz_set(stdmath_degree3* p, stdmath_degree3 value) { p->z = value.x; p->z = value.y; p->z = value.z; return *p; }

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

inline stdmath::degree3 c(stdmath_degree3 c) {
	return (stdmath::degree3&)c;
}
inline stdmath_degree3 c(stdmath::degree3 c) {
	return (stdmath_degree3&)c;
}

#ifdef __cplusplus
extern "C" {
#endif

stdmath_degree3 stdmath_degree3_broadcast(stdmath_degree all) {
	return c(stdmath::degree3((stdmath::degree3::underlying_type&)all));
}

stdmath_degree3 stdmath_degree3_add(stdmath_degree3 a, stdmath_degree3 b) {
	return c(c(a) + c(b));
}
stdmath_degree3 stdmath_degree3_subtract(stdmath_degree3 a, stdmath_degree3 b) {
	return c(c(a) - c(b));
}
stdmath_degree3 stdmath_degree3_negate(stdmath_degree3 v) {
#if !false && !true
	return c(stdmath::degree3(-(stdmath::vector<stdmath_degree, 3>)c(v)));
#else
	assert(false && "TODO: Why can't we use - on vector<degree/radian, N>?");
#endif
}
stdmath_degree3 stdmath_degree3_multiply(stdmath_degree3 a, stdmath_degree3 b) {
	return c(c(a) * c(b));
}
stdmath_degree3 stdmath_degree3_divide(stdmath_degree3 a, stdmath_degree3 b) {
	return c(c(a) / c(b));
}
stdmath_degree3 stdmath_degree3_scale(stdmath_degree3 v, stdmath_degree s) {
	return c(c(v) * (stdmath::degree3::underlying_type&)s);
}

#if false
stdmath_degree3 stdmath_degree3_modulus(stdmath_degree3 a, stdmath_degree3 b) {
	return c(c(a) % c(b));
}
stdmath_degree3 stdmath_degree3_logical_not(stdmath_degree3 v) {
	return c(!c(v));
}
stdmath_degree3 stdmath_degree3_bitwise_not(stdmath_degree3 v) {
	return c(~c(v));
}
stdmath_degree3 stdmath_degree3_logical_and(stdmath_degree3 a, stdmath_degree3 b) {
	return c(c(a) && c(b));
}
stdmath_degree3 stdmath_degree3_bitwise_and(stdmath_degree3 a, stdmath_degree3 b) {
	return c(c(a) & c(b));
}
stdmath_degree3 stdmath_degree3_logical_or(stdmath_degree3 a, stdmath_degree3 b) {
	return c(c(a) || c(b));
}
stdmath_degree3 stdmath_degree3_bitwise_or(stdmath_degree3 a, stdmath_degree3 b) {
	return c(c(a) | c(b));
}
stdmath_degree3 stdmath_degree3_bitwise_xor(stdmath_degree3 a, stdmath_degree3 b) {
	return c(c(a) ^ c(b));
}
stdmath_degree3 stdmath_degree3_shift_left(stdmath_degree3 a, stdmath_degree3 b) {
	return c(c(a) << c(b));
}
stdmath_degree3 stdmath_degree3_shift_right(stdmath_degree3 a, stdmath_degree3 b) {
	return c(c(a) >> c(b));
}
#endif

stdmath_bool3 stdmath_degree3_equal_to(stdmath_degree3 a, stdmath_degree3 b) {
	return c(c(a) == c(b));
}
stdmath_bool3 stdmath_degree3_not_equal_to(stdmath_degree3 a, stdmath_degree3 b) {
	return c(c(a) != c(b));
}
stdmath_bool3 stdmath_degree3_less_than(stdmath_degree3 a, stdmath_degree3 b) {
	return c(c(a) < c(b));
}
stdmath_bool3 stdmath_degree3_less_than_or_equal_to(stdmath_degree3 a, stdmath_degree3 b) {
	return c(c(a) <= c(b));
}
stdmath_bool3 stdmath_degree3_greater_than(stdmath_degree3 a, stdmath_degree3 b) {
	return c(c(a) > c(b));
}
stdmath_bool3 stdmath_degree3_greater_than_or_equal_to(stdmath_degree3 a, stdmath_degree3 b) {
	return c(c(a) >= c(b));
}

stdmath_degree stdmath_degree3_length_squared(stdmath_degree3 v)  {
	auto out = c(v).length_squared();
	return (stdmath_degree&)out;
}
stdmath_degree stdmath_degree3_length(stdmath_degree3 v)  {
	auto out = c(v).length();
	return (stdmath_degree&)out;
}
stdmath_degree stdmath_degree3_dot(stdmath_degree3 a, stdmath_degree3 b)  {
	auto out = dot(c(a), c(b));
	return (stdmath_degree&)out;
}
stdmath_degree stdmath_degree3_min_element(stdmath_degree3 v)  {
	auto out = c(v).min_element();
	return (stdmath_degree&)out;
}
stdmath_degree stdmath_degree3_max_element(stdmath_degree3 v)  {
	auto out = c(v).max_element();
	return (stdmath_degree&)out;
}

// stdmath_degree3 stdmath_degree3_elementwise_transform(stdmath_degree3 v, stdmath_degree(*func)(stdmath_degree)) {
// 	return c(c(v).elementwise_transform(func));
// }
// stdmath_degree stdmath_degree3_reduce_elements(stdmath_degree3 v, stdmath_degree initial_value, stdmath_degree(*reducer)(stdmath_degree3, stdmath_degree3)) {
// 	return c(v).reduce_elements(initial_value, reducer);
// }

#if 3 == 3
stdmath_degree3 stdmath_degree3_cross(stdmath_degree3 a, stdmath_degree3 b) {
	return c(cross(c(a), c(b)));
}
#endif

stdmath_degree3 stdmath_degree3_min(stdmath_degree3 a, stdmath_degree3 b) {
	return c(min(c(a), c(b)));
}
stdmath_degree3 stdmath_degree3_max(stdmath_degree3 a, stdmath_degree3 b) {
	return c(max(c(a), c(b)));
}
stdmath_degree3 stdmath_degree3_normalize(stdmath_degree3 v) {
	return c(normalize(c(v)));
}
stdmath_degree3 stdmath_degree3_lerp(stdmath_degree3 a, stdmath_degree3 b, float t) {
	return c(lerp(c(a), c(b), t));
}
stdmath_degree3 stdmath_degree3_clamp(stdmath_degree3 a, stdmath_degree3 min, stdmath_degree3 max) {
	return c(clamp(c(a), c(min), c(max)));
}
stdmath_degree3 stdmath_degree3_reflect(stdmath_degree3 a, stdmath_degree3 b) {
	return c(reflect(c(a), c(b)));
}
stdmath_bool3 stdmath_degree3_approximately_equal(stdmath_degree3 a, stdmath_degree3 b) {
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

#endif // __STDMATH_stdmath_degree3_H__