#ifndef __STDMATH_uint32_t3_H__
#define __STDMATH_uint32_t3_H__

#include <stdint.h>
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
#include "uint1.h"
#elif 3 == 3
#include "uint2.h"
#include "uint1.h"
#elif 3 == 4
#include "uint3.h"
#include "uint2.h"
#include "uint1.h"
#endif
#include "util.h"

#if 3 == 1
union stdmath_uint1 {
	struct {
		uint32_t x;
	};
	uint32_t data[1];
};
#elif 3 == 2
union stdmath_uint2 {
	struct {
		uint32_t x, y;
	};
	struct {
		uint32_t u, v;
	};
	uint32_t data[2];
};
#elif 3 == 3
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
#elif 3 == 4
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

stdmath_uint3 stdmath_uint3_broadcast(uint32_t all);

stdmath_uint3 stdmath_uint3_add(stdmath_uint3 a, stdmath_uint3 b);
stdmath_uint3 stdmath_uint3_subtract(stdmath_uint3 a, stdmath_uint3 b);
stdmath_uint3 stdmath_uint3_negate(stdmath_uint3 v);
stdmath_uint3 stdmath_uint3_multiply(stdmath_uint3 a, stdmath_uint3 b);
stdmath_uint3 stdmath_uint3_divide(stdmath_uint3 a, stdmath_uint3 b);
stdmath_uint3 stdmath_uint3_scale(stdmath_uint3 v, uint32_t s);

#if false
stdmath_uint3 stdmath_uint3_modulus(stdmath_uint3 a, stdmath_uint3 b);
stdmath_uint3 stdmath_uint3_logical_not(stdmath_uint3 v);
stdmath_uint3 stdmath_uint3_bitwise_not(stdmath_uint3 v);
stdmath_uint3 stdmath_uint3_logical_and(stdmath_uint3 a, stdmath_uint3 b);
stdmath_uint3 stdmath_uint3_bitwise_and(stdmath_uint3 a, stdmath_uint3 b);
stdmath_uint3 stdmath_uint3_logical_or(stdmath_uint3 a, stdmath_uint3 b);
stdmath_uint3 stdmath_uint3_bitwise_or(stdmath_uint3 a, stdmath_uint3 b);
stdmath_uint3 stdmath_uint3_bitwise_xor(stdmath_uint3 a, stdmath_uint3 b);
stdmath_uint3 stdmath_uint3_shift_left(stdmath_uint3 a, stdmath_uint3 b);
stdmath_uint3 stdmath_uint3_shift_right(stdmath_uint3 a, stdmath_uint3 b);
#endif

stdmath_bool3 stdmath_uint3_equal_to(stdmath_uint3 a, stdmath_uint3 b);
stdmath_bool3 stdmath_uint3_not_equal_to(stdmath_uint3 a, stdmath_uint3 b);
stdmath_bool3 stdmath_uint3_less_than(stdmath_uint3 a, stdmath_uint3 b);
stdmath_bool3 stdmath_uint3_less_than_or_equal_to(stdmath_uint3 a, stdmath_uint3 b);
stdmath_bool3 stdmath_uint3_greater_than(stdmath_uint3 a, stdmath_uint3 b);
stdmath_bool3 stdmath_uint3_greater_than_or_equal_to(stdmath_uint3 a, stdmath_uint3 b);

uint32_t stdmath_uint3_length_squared(stdmath_uint3 v);
uint32_t stdmath_uint3_length(stdmath_uint3 v);
uint32_t stdmath_uint3_dot(stdmath_uint3 a, stdmath_uint3 b);
uint32_t stdmath_uint3_min_element(stdmath_uint3 v);
uint32_t stdmath_uint3_max_element(stdmath_uint3 v);

stdmath_uint3 stdmath_uint3_elementwise_transform(stdmath_uint3 v, uint32_t(*func)(uint32_t));
// uint32_t stdmath_uint3_reduce_elements(stdmath_uint3 v, uint32_t initial_value, uint32_t(*reducer)(stdmath_uint3, stdmath_uint3));

#if 3 == 3
stdmath_uint3 stdmath_uint3_cross(stdmath_uint3 a, stdmath_uint3 b);
#endif

stdmath_uint3 stdmath_uint3_min(stdmath_uint3 a, stdmath_uint3 b);
stdmath_uint3 stdmath_uint3_max(stdmath_uint3 a, stdmath_uint3 b);
stdmath_uint3 stdmath_uint3_normalize(stdmath_uint3 v);
stdmath_uint3 stdmath_uint3_lerp(stdmath_uint3 a, stdmath_uint3 b, float t);
stdmath_uint3 stdmath_uint3_clamp(stdmath_uint3 a, stdmath_uint3 min, stdmath_uint3 max);
stdmath_uint3 stdmath_uint3_reflect(stdmath_uint3 a, stdmath_uint3 b);
stdmath_bool3 stdmath_uint3_approximately_equal(stdmath_uint3 a, stdmath_uint3 b);

#if false
bool stdmath_bool3_all_of(stdmath_bool3 v);
bool stdmath_bool3_any_of(stdmath_bool3 v);
bool stdmath_bool3_none_of(stdmath_bool3 v);
bool stdmath_bool3_some_of(stdmath_bool3 v);
#endif

inline static stdmath_uint1 stdmath_uint3_x(stdmath_uint3 v) { return {v.x}; }
inline static stdmath_uint1 stdmath_uint3_x_get(stdmath_uint3* p) { return stdmath_uint3_x(*p); }
inline static stdmath_uint3 stdmath_uint3_x_set(stdmath_uint3* p, stdmath_uint1 value) { p->x = value.x; return *p; }
inline static stdmath_uint1 stdmath_uint3_y(stdmath_uint3 v) { return {v.y}; }
inline static stdmath_uint1 stdmath_uint3_y_get(stdmath_uint3* p) { return stdmath_uint3_y(*p); }
inline static stdmath_uint3 stdmath_uint3_y_set(stdmath_uint3* p, stdmath_uint1 value) { p->y = value.x; return *p; }
inline static stdmath_uint1 stdmath_uint3_z(stdmath_uint3 v) { return {v.z}; }
inline static stdmath_uint1 stdmath_uint3_z_get(stdmath_uint3* p) { return stdmath_uint3_z(*p); }
inline static stdmath_uint3 stdmath_uint3_z_set(stdmath_uint3* p, stdmath_uint1 value) { p->z = value.x; return *p; }
inline static stdmath_uint2 stdmath_uint3_xx(stdmath_uint3 v) { return {v.x,v.x}; }
inline static stdmath_uint2 stdmath_uint3_xx_get(stdmath_uint3* p) { return stdmath_uint3_xx(*p); }
inline static stdmath_uint3 stdmath_uint3_xx_set(stdmath_uint3* p, stdmath_uint2 value) { p->x = value.x; p->x = value.y; return *p; }
inline static stdmath_uint2 stdmath_uint3_xy(stdmath_uint3 v) { return {v.x,v.y}; }
inline static stdmath_uint2 stdmath_uint3_xy_get(stdmath_uint3* p) { return stdmath_uint3_xy(*p); }
inline static stdmath_uint3 stdmath_uint3_xy_set(stdmath_uint3* p, stdmath_uint2 value) { p->x = value.x; p->y = value.y; return *p; }
inline static stdmath_uint2 stdmath_uint3_xz(stdmath_uint3 v) { return {v.x,v.z}; }
inline static stdmath_uint2 stdmath_uint3_xz_get(stdmath_uint3* p) { return stdmath_uint3_xz(*p); }
inline static stdmath_uint3 stdmath_uint3_xz_set(stdmath_uint3* p, stdmath_uint2 value) { p->x = value.x; p->z = value.y; return *p; }
inline static stdmath_uint2 stdmath_uint3_yx(stdmath_uint3 v) { return {v.y,v.x}; }
inline static stdmath_uint2 stdmath_uint3_yx_get(stdmath_uint3* p) { return stdmath_uint3_yx(*p); }
inline static stdmath_uint3 stdmath_uint3_yx_set(stdmath_uint3* p, stdmath_uint2 value) { p->y = value.x; p->x = value.y; return *p; }
inline static stdmath_uint2 stdmath_uint3_yy(stdmath_uint3 v) { return {v.y,v.y}; }
inline static stdmath_uint2 stdmath_uint3_yy_get(stdmath_uint3* p) { return stdmath_uint3_yy(*p); }
inline static stdmath_uint3 stdmath_uint3_yy_set(stdmath_uint3* p, stdmath_uint2 value) { p->y = value.x; p->y = value.y; return *p; }
inline static stdmath_uint2 stdmath_uint3_yz(stdmath_uint3 v) { return {v.y,v.z}; }
inline static stdmath_uint2 stdmath_uint3_yz_get(stdmath_uint3* p) { return stdmath_uint3_yz(*p); }
inline static stdmath_uint3 stdmath_uint3_yz_set(stdmath_uint3* p, stdmath_uint2 value) { p->y = value.x; p->z = value.y; return *p; }
inline static stdmath_uint2 stdmath_uint3_zx(stdmath_uint3 v) { return {v.z,v.x}; }
inline static stdmath_uint2 stdmath_uint3_zx_get(stdmath_uint3* p) { return stdmath_uint3_zx(*p); }
inline static stdmath_uint3 stdmath_uint3_zx_set(stdmath_uint3* p, stdmath_uint2 value) { p->z = value.x; p->x = value.y; return *p; }
inline static stdmath_uint2 stdmath_uint3_zy(stdmath_uint3 v) { return {v.z,v.y}; }
inline static stdmath_uint2 stdmath_uint3_zy_get(stdmath_uint3* p) { return stdmath_uint3_zy(*p); }
inline static stdmath_uint3 stdmath_uint3_zy_set(stdmath_uint3* p, stdmath_uint2 value) { p->z = value.x; p->y = value.y; return *p; }
inline static stdmath_uint2 stdmath_uint3_zz(stdmath_uint3 v) { return {v.z,v.z}; }
inline static stdmath_uint2 stdmath_uint3_zz_get(stdmath_uint3* p) { return stdmath_uint3_zz(*p); }
inline static stdmath_uint3 stdmath_uint3_zz_set(stdmath_uint3* p, stdmath_uint2 value) { p->z = value.x; p->z = value.y; return *p; }
inline static stdmath_uint3 stdmath_uint3_xxx(stdmath_uint3 v) { return {v.x,v.x,v.x}; }
inline static stdmath_uint3 stdmath_uint3_xxx_get(stdmath_uint3* p) { return stdmath_uint3_xxx(*p); }
inline static stdmath_uint3 stdmath_uint3_xxx_set(stdmath_uint3* p, stdmath_uint3 value) { p->x = value.x; p->x = value.y; p->x = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint3_xxy(stdmath_uint3 v) { return {v.x,v.x,v.y}; }
inline static stdmath_uint3 stdmath_uint3_xxy_get(stdmath_uint3* p) { return stdmath_uint3_xxy(*p); }
inline static stdmath_uint3 stdmath_uint3_xxy_set(stdmath_uint3* p, stdmath_uint3 value) { p->x = value.x; p->x = value.y; p->y = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint3_xxz(stdmath_uint3 v) { return {v.x,v.x,v.z}; }
inline static stdmath_uint3 stdmath_uint3_xxz_get(stdmath_uint3* p) { return stdmath_uint3_xxz(*p); }
inline static stdmath_uint3 stdmath_uint3_xxz_set(stdmath_uint3* p, stdmath_uint3 value) { p->x = value.x; p->x = value.y; p->z = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint3_xyx(stdmath_uint3 v) { return {v.x,v.y,v.x}; }
inline static stdmath_uint3 stdmath_uint3_xyx_get(stdmath_uint3* p) { return stdmath_uint3_xyx(*p); }
inline static stdmath_uint3 stdmath_uint3_xyx_set(stdmath_uint3* p, stdmath_uint3 value) { p->x = value.x; p->y = value.y; p->x = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint3_xyy(stdmath_uint3 v) { return {v.x,v.y,v.y}; }
inline static stdmath_uint3 stdmath_uint3_xyy_get(stdmath_uint3* p) { return stdmath_uint3_xyy(*p); }
inline static stdmath_uint3 stdmath_uint3_xyy_set(stdmath_uint3* p, stdmath_uint3 value) { p->x = value.x; p->y = value.y; p->y = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint3_xyz(stdmath_uint3 v) { return {v.x,v.y,v.z}; }
inline static stdmath_uint3 stdmath_uint3_xyz_get(stdmath_uint3* p) { return stdmath_uint3_xyz(*p); }
inline static stdmath_uint3 stdmath_uint3_xyz_set(stdmath_uint3* p, stdmath_uint3 value) { p->x = value.x; p->y = value.y; p->z = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint3_xzx(stdmath_uint3 v) { return {v.x,v.z,v.x}; }
inline static stdmath_uint3 stdmath_uint3_xzx_get(stdmath_uint3* p) { return stdmath_uint3_xzx(*p); }
inline static stdmath_uint3 stdmath_uint3_xzx_set(stdmath_uint3* p, stdmath_uint3 value) { p->x = value.x; p->z = value.y; p->x = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint3_xzy(stdmath_uint3 v) { return {v.x,v.z,v.y}; }
inline static stdmath_uint3 stdmath_uint3_xzy_get(stdmath_uint3* p) { return stdmath_uint3_xzy(*p); }
inline static stdmath_uint3 stdmath_uint3_xzy_set(stdmath_uint3* p, stdmath_uint3 value) { p->x = value.x; p->z = value.y; p->y = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint3_xzz(stdmath_uint3 v) { return {v.x,v.z,v.z}; }
inline static stdmath_uint3 stdmath_uint3_xzz_get(stdmath_uint3* p) { return stdmath_uint3_xzz(*p); }
inline static stdmath_uint3 stdmath_uint3_xzz_set(stdmath_uint3* p, stdmath_uint3 value) { p->x = value.x; p->z = value.y; p->z = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint3_yxx(stdmath_uint3 v) { return {v.y,v.x,v.x}; }
inline static stdmath_uint3 stdmath_uint3_yxx_get(stdmath_uint3* p) { return stdmath_uint3_yxx(*p); }
inline static stdmath_uint3 stdmath_uint3_yxx_set(stdmath_uint3* p, stdmath_uint3 value) { p->y = value.x; p->x = value.y; p->x = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint3_yxy(stdmath_uint3 v) { return {v.y,v.x,v.y}; }
inline static stdmath_uint3 stdmath_uint3_yxy_get(stdmath_uint3* p) { return stdmath_uint3_yxy(*p); }
inline static stdmath_uint3 stdmath_uint3_yxy_set(stdmath_uint3* p, stdmath_uint3 value) { p->y = value.x; p->x = value.y; p->y = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint3_yxz(stdmath_uint3 v) { return {v.y,v.x,v.z}; }
inline static stdmath_uint3 stdmath_uint3_yxz_get(stdmath_uint3* p) { return stdmath_uint3_yxz(*p); }
inline static stdmath_uint3 stdmath_uint3_yxz_set(stdmath_uint3* p, stdmath_uint3 value) { p->y = value.x; p->x = value.y; p->z = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint3_yyx(stdmath_uint3 v) { return {v.y,v.y,v.x}; }
inline static stdmath_uint3 stdmath_uint3_yyx_get(stdmath_uint3* p) { return stdmath_uint3_yyx(*p); }
inline static stdmath_uint3 stdmath_uint3_yyx_set(stdmath_uint3* p, stdmath_uint3 value) { p->y = value.x; p->y = value.y; p->x = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint3_yyy(stdmath_uint3 v) { return {v.y,v.y,v.y}; }
inline static stdmath_uint3 stdmath_uint3_yyy_get(stdmath_uint3* p) { return stdmath_uint3_yyy(*p); }
inline static stdmath_uint3 stdmath_uint3_yyy_set(stdmath_uint3* p, stdmath_uint3 value) { p->y = value.x; p->y = value.y; p->y = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint3_yyz(stdmath_uint3 v) { return {v.y,v.y,v.z}; }
inline static stdmath_uint3 stdmath_uint3_yyz_get(stdmath_uint3* p) { return stdmath_uint3_yyz(*p); }
inline static stdmath_uint3 stdmath_uint3_yyz_set(stdmath_uint3* p, stdmath_uint3 value) { p->y = value.x; p->y = value.y; p->z = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint3_yzx(stdmath_uint3 v) { return {v.y,v.z,v.x}; }
inline static stdmath_uint3 stdmath_uint3_yzx_get(stdmath_uint3* p) { return stdmath_uint3_yzx(*p); }
inline static stdmath_uint3 stdmath_uint3_yzx_set(stdmath_uint3* p, stdmath_uint3 value) { p->y = value.x; p->z = value.y; p->x = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint3_yzy(stdmath_uint3 v) { return {v.y,v.z,v.y}; }
inline static stdmath_uint3 stdmath_uint3_yzy_get(stdmath_uint3* p) { return stdmath_uint3_yzy(*p); }
inline static stdmath_uint3 stdmath_uint3_yzy_set(stdmath_uint3* p, stdmath_uint3 value) { p->y = value.x; p->z = value.y; p->y = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint3_yzz(stdmath_uint3 v) { return {v.y,v.z,v.z}; }
inline static stdmath_uint3 stdmath_uint3_yzz_get(stdmath_uint3* p) { return stdmath_uint3_yzz(*p); }
inline static stdmath_uint3 stdmath_uint3_yzz_set(stdmath_uint3* p, stdmath_uint3 value) { p->y = value.x; p->z = value.y; p->z = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint3_zxx(stdmath_uint3 v) { return {v.z,v.x,v.x}; }
inline static stdmath_uint3 stdmath_uint3_zxx_get(stdmath_uint3* p) { return stdmath_uint3_zxx(*p); }
inline static stdmath_uint3 stdmath_uint3_zxx_set(stdmath_uint3* p, stdmath_uint3 value) { p->z = value.x; p->x = value.y; p->x = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint3_zxy(stdmath_uint3 v) { return {v.z,v.x,v.y}; }
inline static stdmath_uint3 stdmath_uint3_zxy_get(stdmath_uint3* p) { return stdmath_uint3_zxy(*p); }
inline static stdmath_uint3 stdmath_uint3_zxy_set(stdmath_uint3* p, stdmath_uint3 value) { p->z = value.x; p->x = value.y; p->y = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint3_zxz(stdmath_uint3 v) { return {v.z,v.x,v.z}; }
inline static stdmath_uint3 stdmath_uint3_zxz_get(stdmath_uint3* p) { return stdmath_uint3_zxz(*p); }
inline static stdmath_uint3 stdmath_uint3_zxz_set(stdmath_uint3* p, stdmath_uint3 value) { p->z = value.x; p->x = value.y; p->z = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint3_zyx(stdmath_uint3 v) { return {v.z,v.y,v.x}; }
inline static stdmath_uint3 stdmath_uint3_zyx_get(stdmath_uint3* p) { return stdmath_uint3_zyx(*p); }
inline static stdmath_uint3 stdmath_uint3_zyx_set(stdmath_uint3* p, stdmath_uint3 value) { p->z = value.x; p->y = value.y; p->x = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint3_zyy(stdmath_uint3 v) { return {v.z,v.y,v.y}; }
inline static stdmath_uint3 stdmath_uint3_zyy_get(stdmath_uint3* p) { return stdmath_uint3_zyy(*p); }
inline static stdmath_uint3 stdmath_uint3_zyy_set(stdmath_uint3* p, stdmath_uint3 value) { p->z = value.x; p->y = value.y; p->y = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint3_zyz(stdmath_uint3 v) { return {v.z,v.y,v.z}; }
inline static stdmath_uint3 stdmath_uint3_zyz_get(stdmath_uint3* p) { return stdmath_uint3_zyz(*p); }
inline static stdmath_uint3 stdmath_uint3_zyz_set(stdmath_uint3* p, stdmath_uint3 value) { p->z = value.x; p->y = value.y; p->z = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint3_zzx(stdmath_uint3 v) { return {v.z,v.z,v.x}; }
inline static stdmath_uint3 stdmath_uint3_zzx_get(stdmath_uint3* p) { return stdmath_uint3_zzx(*p); }
inline static stdmath_uint3 stdmath_uint3_zzx_set(stdmath_uint3* p, stdmath_uint3 value) { p->z = value.x; p->z = value.y; p->x = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint3_zzy(stdmath_uint3 v) { return {v.z,v.z,v.y}; }
inline static stdmath_uint3 stdmath_uint3_zzy_get(stdmath_uint3* p) { return stdmath_uint3_zzy(*p); }
inline static stdmath_uint3 stdmath_uint3_zzy_set(stdmath_uint3* p, stdmath_uint3 value) { p->z = value.x; p->z = value.y; p->y = value.z; return *p; }
inline static stdmath_uint3 stdmath_uint3_zzz(stdmath_uint3 v) { return {v.z,v.z,v.z}; }
inline static stdmath_uint3 stdmath_uint3_zzz_get(stdmath_uint3* p) { return stdmath_uint3_zzz(*p); }
inline static stdmath_uint3 stdmath_uint3_zzz_set(stdmath_uint3* p, stdmath_uint3 value) { p->z = value.x; p->z = value.y; p->z = value.z; return *p; }


#ifdef STDMATH_IMPLEMENTATION
#ifndef __cplusplus
#error "The stdmath implementations require a C++ compiler"
#endif

import stdmath.slang;

stdmath::uint3 c(stdmath_uint3 c) {
	return (stdmath::uint3&)c;
}
stdmath_uint3 c(stdmath::uint3 c) {
	return (stdmath_uint3&)c;
}

stdmath_uint3 stdmath_uint3_broadcast(uint32_t all) {
	return c(stdmath::uint3((stdmath::uint3::underlying_type)all));
}

stdmath_uint3 stdmath_uint3_add(stdmath_uint3 a, stdmath_uint3 b) {
	return c(c(a) + c(b));
}
stdmath_uint3 stdmath_uint3_subtract(stdmath_uint3 a, stdmath_uint3 b) {
	return c(c(a) - c(b));
}
stdmath_uint3 stdmath_uint3_negate(stdmath_uint3 v) {
	return c(stdmath::uint3(-(stdmath::vector<uint32_t, 3>)c(v)));
}
stdmath_uint3 stdmath_uint3_multiply(stdmath_uint3 a, stdmath_uint3 b) {
	return c(c(a) * c(b));
}
stdmath_uint3 stdmath_uint3_divide(stdmath_uint3 a, stdmath_uint3 b) {
	return c(c(a) / c(b));
}
stdmath_uint3 stdmath_uint3_scale(stdmath_uint3 v, uint32_t s) {
	return c(c(v) * (stdmath::uint3::underlying_type)s);
}

#if false
stdmath_uint3 stdmath_uint3_modulus(stdmath_uint3 a, stdmath_uint3 b) {
	return c(c(a) % c(b));
}
stdmath_uint3 stdmath_uint3_logical_not(stdmath_uint3 v) {
	return c(!c(v));
}
stdmath_uint3 stdmath_uint3_bitwise_not(stdmath_uint3 v) {
	return c(~c(v));
}
stdmath_uint3 stdmath_uint3_logical_and(stdmath_uint3 a, stdmath_uint3 b) {
	return c(c(a) && c(b));
}
stdmath_uint3 stdmath_uint3_bitwise_and(stdmath_uint3 a, stdmath_uint3 b) {
	return c(c(a) & c(b));
}
stdmath_uint3 stdmath_uint3_logical_or(stdmath_uint3 a, stdmath_uint3 b) {
	return c(c(a) || c(b));
}
stdmath_uint3 stdmath_uint3_bitwise_or(stdmath_uint3 a, stdmath_uint3 b) {
	return c(c(a) | c(b));
}
stdmath_uint3 stdmath_uint3_bitwise_xor(stdmath_uint3 a, stdmath_uint3 b) {
	return c(c(a) ^ c(b));
}
stdmath_uint3 stdmath_uint3_shift_left(stdmath_uint3 a, stdmath_uint3 b) {
	return c(c(a) << c(b));
}
stdmath_uint3 stdmath_uint3_shift_right(stdmath_uint3 a, stdmath_uint3 b) {
	return c(c(a) >> c(b));
}
#endif

stdmath_bool3 stdmath_uint3_equal_to(stdmath_uint3 a, stdmath_uint3 b) {
	return c(c(a) == c(b));
}
stdmath_bool3 stdmath_uint3_not_equal_to(stdmath_uint3 a, stdmath_uint3 b) {
	return c(c(a) != c(b));
}
stdmath_bool3 stdmath_uint3_less_than(stdmath_uint3 a, stdmath_uint3 b) {
	return c(c(a) < c(b));
}
stdmath_bool3 stdmath_uint3_less_than_or_equal_to(stdmath_uint3 a, stdmath_uint3 b) {
	return c(c(a) <= c(b));
}
stdmath_bool3 stdmath_uint3_greater_than(stdmath_uint3 a, stdmath_uint3 b) {
	return c(c(a) > c(b));
}
stdmath_bool3 stdmath_uint3_greater_than_or_equal_to(stdmath_uint3 a, stdmath_uint3 b) {
	return c(c(a) >= c(b));
}

uint32_t stdmath_uint3_length_squared(stdmath_uint3 v)  {
	return (uint32_t)c(v).length_squared();
}
uint32_t stdmath_uint3_length(stdmath_uint3 v)  {
	return (uint32_t)c(v).length();
}
uint32_t stdmath_uint3_dot(stdmath_uint3 a, stdmath_uint3 b)  {
	return (uint32_t)dot(c(a), c(b));
}
uint32_t stdmath_uint3_min_element(stdmath_uint3 v)  {
	return (uint32_t)c(v).min_element();
}
uint32_t stdmath_uint3_max_element(stdmath_uint3 v)  {
	return (uint32_t)c(v).max_element();
}

stdmath_uint3 stdmath_uint3_elementwise_transform(stdmath_uint3 v, uint32_t(*func)(uint32_t)) {
	return c(c(v).elementwise_transform(func));
}
// uint32_t stdmath_uint3_reduce_elements(stdmath_uint3 v, uint32_t initial_value, uint32_t(*reducer)(stdmath_uint3, stdmath_uint3)) {
// 	return c(v).reduce_elements(initial_value, reducer);
// }

#if 3 == 3
stdmath_uint3 stdmath_uint3_cross(stdmath_uint3 a, stdmath_uint3 b) {
	return c(cross(c(a), c(b)));
}
#endif

stdmath_uint3 stdmath_uint3_min(stdmath_uint3 a, stdmath_uint3 b) {
	return c(min(c(a), c(b)));
}
stdmath_uint3 stdmath_uint3_max(stdmath_uint3 a, stdmath_uint3 b) {
	return c(max(c(a), c(b)));
}
stdmath_uint3 stdmath_uint3_normalize(stdmath_uint3 v) {
	return c(normalize(c(v)));
}
stdmath_uint3 stdmath_uint3_lerp(stdmath_uint3 a, stdmath_uint3 b, float t) {
	return c(lerp(c(a), c(b), t));
}
stdmath_uint3 stdmath_uint3_clamp(stdmath_uint3 a, stdmath_uint3 min, stdmath_uint3 max) {
	return c(clamp(c(a), c(min), c(max)));
}
stdmath_uint3 stdmath_uint3_reflect(stdmath_uint3 a, stdmath_uint3 b) {
	return c(reflect(c(a), c(b)));
}
stdmath_bool3 stdmath_uint3_approximately_equal(stdmath_uint3 a, stdmath_uint3 b) {
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

#endif // STDMATH_IMPLEMENTATION

#endif // __STDMATH_uint32_t3_H__