#ifndef __STDMATH_uint8_t3_H__
#define __STDMATH_uint8_t3_H__

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
#include "byte1.h"
#elif 3 == 3
#include "byte2.h"
#include "byte1.h"
#elif 3 == 4
#include "byte3.h"
#include "byte2.h"
#include "byte1.h"
#endif
#include "util.h"

#if 3 == 1
union stdmath_byte1 {
	struct {
		uint8_t x;
	};
	uint8_t data[1];
};
#elif 3 == 2
union stdmath_byte2 {
	struct {
		uint8_t x, y;
	};
	struct {
		uint8_t u, v;
	};
	uint8_t data[2];
};
#elif 3 == 3
union stdmath_byte3 {
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
#elif 3 == 4
union stdmath_byte4 {
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

stdmath_byte3 stdmath_byte3_broadcast(uint8_t all);

stdmath_byte3 stdmath_byte3_add(stdmath_byte3 a, stdmath_byte3 b);
stdmath_byte3 stdmath_byte3_subtract(stdmath_byte3 a, stdmath_byte3 b);
stdmath_byte3 stdmath_byte3_negate(stdmath_byte3 v);
stdmath_byte3 stdmath_byte3_multiply(stdmath_byte3 a, stdmath_byte3 b);
stdmath_byte3 stdmath_byte3_divide(stdmath_byte3 a, stdmath_byte3 b);
stdmath_byte3 stdmath_byte3_scale(stdmath_byte3 v, uint8_t s);

#if false
stdmath_byte3 stdmath_byte3_modulus(stdmath_byte3 a, stdmath_byte3 b);
stdmath_byte3 stdmath_byte3_logical_not(stdmath_byte3 v);
stdmath_byte3 stdmath_byte3_bitwise_not(stdmath_byte3 v);
stdmath_byte3 stdmath_byte3_logical_and(stdmath_byte3 a, stdmath_byte3 b);
stdmath_byte3 stdmath_byte3_bitwise_and(stdmath_byte3 a, stdmath_byte3 b);
stdmath_byte3 stdmath_byte3_logical_or(stdmath_byte3 a, stdmath_byte3 b);
stdmath_byte3 stdmath_byte3_bitwise_or(stdmath_byte3 a, stdmath_byte3 b);
stdmath_byte3 stdmath_byte3_bitwise_xor(stdmath_byte3 a, stdmath_byte3 b);
stdmath_byte3 stdmath_byte3_shift_left(stdmath_byte3 a, stdmath_byte3 b);
stdmath_byte3 stdmath_byte3_shift_right(stdmath_byte3 a, stdmath_byte3 b);
#endif

stdmath_bool3 stdmath_byte3_equal_to(stdmath_byte3 a, stdmath_byte3 b);
stdmath_bool3 stdmath_byte3_not_equal_to(stdmath_byte3 a, stdmath_byte3 b);
stdmath_bool3 stdmath_byte3_less_than(stdmath_byte3 a, stdmath_byte3 b);
stdmath_bool3 stdmath_byte3_less_than_or_equal_to(stdmath_byte3 a, stdmath_byte3 b);
stdmath_bool3 stdmath_byte3_greater_than(stdmath_byte3 a, stdmath_byte3 b);
stdmath_bool3 stdmath_byte3_greater_than_or_equal_to(stdmath_byte3 a, stdmath_byte3 b);

uint8_t stdmath_byte3_length_squared(stdmath_byte3 v);
uint8_t stdmath_byte3_length(stdmath_byte3 v);
uint8_t stdmath_byte3_dot(stdmath_byte3 a, stdmath_byte3 b);
uint8_t stdmath_byte3_min_element(stdmath_byte3 v);
uint8_t stdmath_byte3_max_element(stdmath_byte3 v);

stdmath_byte3 stdmath_byte3_elementwise_transform(stdmath_byte3 v, uint8_t(*func)(uint8_t));
// uint8_t stdmath_byte3_reduce_elements(stdmath_byte3 v, uint8_t initial_value, uint8_t(*reducer)(stdmath_byte3, stdmath_byte3));

#if 3 == 3
stdmath_byte3 stdmath_byte3_cross(stdmath_byte3 a, stdmath_byte3 b);
#endif

stdmath_byte3 stdmath_byte3_min(stdmath_byte3 a, stdmath_byte3 b);
stdmath_byte3 stdmath_byte3_max(stdmath_byte3 a, stdmath_byte3 b);
stdmath_byte3 stdmath_byte3_normalize(stdmath_byte3 v);
stdmath_byte3 stdmath_byte3_lerp(stdmath_byte3 a, stdmath_byte3 b, float t);
stdmath_byte3 stdmath_byte3_clamp(stdmath_byte3 a, stdmath_byte3 min, stdmath_byte3 max);
stdmath_byte3 stdmath_byte3_reflect(stdmath_byte3 a, stdmath_byte3 b);
stdmath_bool3 stdmath_byte3_approximately_equal(stdmath_byte3 a, stdmath_byte3 b);

#if false
bool stdmath_bool3_all_of(stdmath_bool3 v);
bool stdmath_bool3_any_of(stdmath_bool3 v);
bool stdmath_bool3_none_of(stdmath_bool3 v);
bool stdmath_bool3_some_of(stdmath_bool3 v);
#endif

inline static stdmath_byte1 stdmath_byte3_x(stdmath_byte3 v) { return {v.x}; }
inline static stdmath_byte1 stdmath_byte3_x_get(stdmath_byte3* p) { return stdmath_byte3_x(*p); }
inline static stdmath_byte3 stdmath_byte3_x_set(stdmath_byte3* p, stdmath_byte1 value) { p->x = value.x; return *p; }
inline static stdmath_byte1 stdmath_byte3_y(stdmath_byte3 v) { return {v.y}; }
inline static stdmath_byte1 stdmath_byte3_y_get(stdmath_byte3* p) { return stdmath_byte3_y(*p); }
inline static stdmath_byte3 stdmath_byte3_y_set(stdmath_byte3* p, stdmath_byte1 value) { p->y = value.x; return *p; }
inline static stdmath_byte1 stdmath_byte3_z(stdmath_byte3 v) { return {v.z}; }
inline static stdmath_byte1 stdmath_byte3_z_get(stdmath_byte3* p) { return stdmath_byte3_z(*p); }
inline static stdmath_byte3 stdmath_byte3_z_set(stdmath_byte3* p, stdmath_byte1 value) { p->z = value.x; return *p; }
inline static stdmath_byte2 stdmath_byte3_xx(stdmath_byte3 v) { return {v.x,v.x}; }
inline static stdmath_byte2 stdmath_byte3_xx_get(stdmath_byte3* p) { return stdmath_byte3_xx(*p); }
inline static stdmath_byte3 stdmath_byte3_xx_set(stdmath_byte3* p, stdmath_byte2 value) { p->x = value.x; p->x = value.y; return *p; }
inline static stdmath_byte2 stdmath_byte3_xy(stdmath_byte3 v) { return {v.x,v.y}; }
inline static stdmath_byte2 stdmath_byte3_xy_get(stdmath_byte3* p) { return stdmath_byte3_xy(*p); }
inline static stdmath_byte3 stdmath_byte3_xy_set(stdmath_byte3* p, stdmath_byte2 value) { p->x = value.x; p->y = value.y; return *p; }
inline static stdmath_byte2 stdmath_byte3_xz(stdmath_byte3 v) { return {v.x,v.z}; }
inline static stdmath_byte2 stdmath_byte3_xz_get(stdmath_byte3* p) { return stdmath_byte3_xz(*p); }
inline static stdmath_byte3 stdmath_byte3_xz_set(stdmath_byte3* p, stdmath_byte2 value) { p->x = value.x; p->z = value.y; return *p; }
inline static stdmath_byte2 stdmath_byte3_yx(stdmath_byte3 v) { return {v.y,v.x}; }
inline static stdmath_byte2 stdmath_byte3_yx_get(stdmath_byte3* p) { return stdmath_byte3_yx(*p); }
inline static stdmath_byte3 stdmath_byte3_yx_set(stdmath_byte3* p, stdmath_byte2 value) { p->y = value.x; p->x = value.y; return *p; }
inline static stdmath_byte2 stdmath_byte3_yy(stdmath_byte3 v) { return {v.y,v.y}; }
inline static stdmath_byte2 stdmath_byte3_yy_get(stdmath_byte3* p) { return stdmath_byte3_yy(*p); }
inline static stdmath_byte3 stdmath_byte3_yy_set(stdmath_byte3* p, stdmath_byte2 value) { p->y = value.x; p->y = value.y; return *p; }
inline static stdmath_byte2 stdmath_byte3_yz(stdmath_byte3 v) { return {v.y,v.z}; }
inline static stdmath_byte2 stdmath_byte3_yz_get(stdmath_byte3* p) { return stdmath_byte3_yz(*p); }
inline static stdmath_byte3 stdmath_byte3_yz_set(stdmath_byte3* p, stdmath_byte2 value) { p->y = value.x; p->z = value.y; return *p; }
inline static stdmath_byte2 stdmath_byte3_zx(stdmath_byte3 v) { return {v.z,v.x}; }
inline static stdmath_byte2 stdmath_byte3_zx_get(stdmath_byte3* p) { return stdmath_byte3_zx(*p); }
inline static stdmath_byte3 stdmath_byte3_zx_set(stdmath_byte3* p, stdmath_byte2 value) { p->z = value.x; p->x = value.y; return *p; }
inline static stdmath_byte2 stdmath_byte3_zy(stdmath_byte3 v) { return {v.z,v.y}; }
inline static stdmath_byte2 stdmath_byte3_zy_get(stdmath_byte3* p) { return stdmath_byte3_zy(*p); }
inline static stdmath_byte3 stdmath_byte3_zy_set(stdmath_byte3* p, stdmath_byte2 value) { p->z = value.x; p->y = value.y; return *p; }
inline static stdmath_byte2 stdmath_byte3_zz(stdmath_byte3 v) { return {v.z,v.z}; }
inline static stdmath_byte2 stdmath_byte3_zz_get(stdmath_byte3* p) { return stdmath_byte3_zz(*p); }
inline static stdmath_byte3 stdmath_byte3_zz_set(stdmath_byte3* p, stdmath_byte2 value) { p->z = value.x; p->z = value.y; return *p; }
inline static stdmath_byte3 stdmath_byte3_xxx(stdmath_byte3 v) { return {v.x,v.x,v.x}; }
inline static stdmath_byte3 stdmath_byte3_xxx_get(stdmath_byte3* p) { return stdmath_byte3_xxx(*p); }
inline static stdmath_byte3 stdmath_byte3_xxx_set(stdmath_byte3* p, stdmath_byte3 value) { p->x = value.x; p->x = value.y; p->x = value.z; return *p; }
inline static stdmath_byte3 stdmath_byte3_xxy(stdmath_byte3 v) { return {v.x,v.x,v.y}; }
inline static stdmath_byte3 stdmath_byte3_xxy_get(stdmath_byte3* p) { return stdmath_byte3_xxy(*p); }
inline static stdmath_byte3 stdmath_byte3_xxy_set(stdmath_byte3* p, stdmath_byte3 value) { p->x = value.x; p->x = value.y; p->y = value.z; return *p; }
inline static stdmath_byte3 stdmath_byte3_xxz(stdmath_byte3 v) { return {v.x,v.x,v.z}; }
inline static stdmath_byte3 stdmath_byte3_xxz_get(stdmath_byte3* p) { return stdmath_byte3_xxz(*p); }
inline static stdmath_byte3 stdmath_byte3_xxz_set(stdmath_byte3* p, stdmath_byte3 value) { p->x = value.x; p->x = value.y; p->z = value.z; return *p; }
inline static stdmath_byte3 stdmath_byte3_xyx(stdmath_byte3 v) { return {v.x,v.y,v.x}; }
inline static stdmath_byte3 stdmath_byte3_xyx_get(stdmath_byte3* p) { return stdmath_byte3_xyx(*p); }
inline static stdmath_byte3 stdmath_byte3_xyx_set(stdmath_byte3* p, stdmath_byte3 value) { p->x = value.x; p->y = value.y; p->x = value.z; return *p; }
inline static stdmath_byte3 stdmath_byte3_xyy(stdmath_byte3 v) { return {v.x,v.y,v.y}; }
inline static stdmath_byte3 stdmath_byte3_xyy_get(stdmath_byte3* p) { return stdmath_byte3_xyy(*p); }
inline static stdmath_byte3 stdmath_byte3_xyy_set(stdmath_byte3* p, stdmath_byte3 value) { p->x = value.x; p->y = value.y; p->y = value.z; return *p; }
inline static stdmath_byte3 stdmath_byte3_xyz(stdmath_byte3 v) { return {v.x,v.y,v.z}; }
inline static stdmath_byte3 stdmath_byte3_xyz_get(stdmath_byte3* p) { return stdmath_byte3_xyz(*p); }
inline static stdmath_byte3 stdmath_byte3_xyz_set(stdmath_byte3* p, stdmath_byte3 value) { p->x = value.x; p->y = value.y; p->z = value.z; return *p; }
inline static stdmath_byte3 stdmath_byte3_xzx(stdmath_byte3 v) { return {v.x,v.z,v.x}; }
inline static stdmath_byte3 stdmath_byte3_xzx_get(stdmath_byte3* p) { return stdmath_byte3_xzx(*p); }
inline static stdmath_byte3 stdmath_byte3_xzx_set(stdmath_byte3* p, stdmath_byte3 value) { p->x = value.x; p->z = value.y; p->x = value.z; return *p; }
inline static stdmath_byte3 stdmath_byte3_xzy(stdmath_byte3 v) { return {v.x,v.z,v.y}; }
inline static stdmath_byte3 stdmath_byte3_xzy_get(stdmath_byte3* p) { return stdmath_byte3_xzy(*p); }
inline static stdmath_byte3 stdmath_byte3_xzy_set(stdmath_byte3* p, stdmath_byte3 value) { p->x = value.x; p->z = value.y; p->y = value.z; return *p; }
inline static stdmath_byte3 stdmath_byte3_xzz(stdmath_byte3 v) { return {v.x,v.z,v.z}; }
inline static stdmath_byte3 stdmath_byte3_xzz_get(stdmath_byte3* p) { return stdmath_byte3_xzz(*p); }
inline static stdmath_byte3 stdmath_byte3_xzz_set(stdmath_byte3* p, stdmath_byte3 value) { p->x = value.x; p->z = value.y; p->z = value.z; return *p; }
inline static stdmath_byte3 stdmath_byte3_yxx(stdmath_byte3 v) { return {v.y,v.x,v.x}; }
inline static stdmath_byte3 stdmath_byte3_yxx_get(stdmath_byte3* p) { return stdmath_byte3_yxx(*p); }
inline static stdmath_byte3 stdmath_byte3_yxx_set(stdmath_byte3* p, stdmath_byte3 value) { p->y = value.x; p->x = value.y; p->x = value.z; return *p; }
inline static stdmath_byte3 stdmath_byte3_yxy(stdmath_byte3 v) { return {v.y,v.x,v.y}; }
inline static stdmath_byte3 stdmath_byte3_yxy_get(stdmath_byte3* p) { return stdmath_byte3_yxy(*p); }
inline static stdmath_byte3 stdmath_byte3_yxy_set(stdmath_byte3* p, stdmath_byte3 value) { p->y = value.x; p->x = value.y; p->y = value.z; return *p; }
inline static stdmath_byte3 stdmath_byte3_yxz(stdmath_byte3 v) { return {v.y,v.x,v.z}; }
inline static stdmath_byte3 stdmath_byte3_yxz_get(stdmath_byte3* p) { return stdmath_byte3_yxz(*p); }
inline static stdmath_byte3 stdmath_byte3_yxz_set(stdmath_byte3* p, stdmath_byte3 value) { p->y = value.x; p->x = value.y; p->z = value.z; return *p; }
inline static stdmath_byte3 stdmath_byte3_yyx(stdmath_byte3 v) { return {v.y,v.y,v.x}; }
inline static stdmath_byte3 stdmath_byte3_yyx_get(stdmath_byte3* p) { return stdmath_byte3_yyx(*p); }
inline static stdmath_byte3 stdmath_byte3_yyx_set(stdmath_byte3* p, stdmath_byte3 value) { p->y = value.x; p->y = value.y; p->x = value.z; return *p; }
inline static stdmath_byte3 stdmath_byte3_yyy(stdmath_byte3 v) { return {v.y,v.y,v.y}; }
inline static stdmath_byte3 stdmath_byte3_yyy_get(stdmath_byte3* p) { return stdmath_byte3_yyy(*p); }
inline static stdmath_byte3 stdmath_byte3_yyy_set(stdmath_byte3* p, stdmath_byte3 value) { p->y = value.x; p->y = value.y; p->y = value.z; return *p; }
inline static stdmath_byte3 stdmath_byte3_yyz(stdmath_byte3 v) { return {v.y,v.y,v.z}; }
inline static stdmath_byte3 stdmath_byte3_yyz_get(stdmath_byte3* p) { return stdmath_byte3_yyz(*p); }
inline static stdmath_byte3 stdmath_byte3_yyz_set(stdmath_byte3* p, stdmath_byte3 value) { p->y = value.x; p->y = value.y; p->z = value.z; return *p; }
inline static stdmath_byte3 stdmath_byte3_yzx(stdmath_byte3 v) { return {v.y,v.z,v.x}; }
inline static stdmath_byte3 stdmath_byte3_yzx_get(stdmath_byte3* p) { return stdmath_byte3_yzx(*p); }
inline static stdmath_byte3 stdmath_byte3_yzx_set(stdmath_byte3* p, stdmath_byte3 value) { p->y = value.x; p->z = value.y; p->x = value.z; return *p; }
inline static stdmath_byte3 stdmath_byte3_yzy(stdmath_byte3 v) { return {v.y,v.z,v.y}; }
inline static stdmath_byte3 stdmath_byte3_yzy_get(stdmath_byte3* p) { return stdmath_byte3_yzy(*p); }
inline static stdmath_byte3 stdmath_byte3_yzy_set(stdmath_byte3* p, stdmath_byte3 value) { p->y = value.x; p->z = value.y; p->y = value.z; return *p; }
inline static stdmath_byte3 stdmath_byte3_yzz(stdmath_byte3 v) { return {v.y,v.z,v.z}; }
inline static stdmath_byte3 stdmath_byte3_yzz_get(stdmath_byte3* p) { return stdmath_byte3_yzz(*p); }
inline static stdmath_byte3 stdmath_byte3_yzz_set(stdmath_byte3* p, stdmath_byte3 value) { p->y = value.x; p->z = value.y; p->z = value.z; return *p; }
inline static stdmath_byte3 stdmath_byte3_zxx(stdmath_byte3 v) { return {v.z,v.x,v.x}; }
inline static stdmath_byte3 stdmath_byte3_zxx_get(stdmath_byte3* p) { return stdmath_byte3_zxx(*p); }
inline static stdmath_byte3 stdmath_byte3_zxx_set(stdmath_byte3* p, stdmath_byte3 value) { p->z = value.x; p->x = value.y; p->x = value.z; return *p; }
inline static stdmath_byte3 stdmath_byte3_zxy(stdmath_byte3 v) { return {v.z,v.x,v.y}; }
inline static stdmath_byte3 stdmath_byte3_zxy_get(stdmath_byte3* p) { return stdmath_byte3_zxy(*p); }
inline static stdmath_byte3 stdmath_byte3_zxy_set(stdmath_byte3* p, stdmath_byte3 value) { p->z = value.x; p->x = value.y; p->y = value.z; return *p; }
inline static stdmath_byte3 stdmath_byte3_zxz(stdmath_byte3 v) { return {v.z,v.x,v.z}; }
inline static stdmath_byte3 stdmath_byte3_zxz_get(stdmath_byte3* p) { return stdmath_byte3_zxz(*p); }
inline static stdmath_byte3 stdmath_byte3_zxz_set(stdmath_byte3* p, stdmath_byte3 value) { p->z = value.x; p->x = value.y; p->z = value.z; return *p; }
inline static stdmath_byte3 stdmath_byte3_zyx(stdmath_byte3 v) { return {v.z,v.y,v.x}; }
inline static stdmath_byte3 stdmath_byte3_zyx_get(stdmath_byte3* p) { return stdmath_byte3_zyx(*p); }
inline static stdmath_byte3 stdmath_byte3_zyx_set(stdmath_byte3* p, stdmath_byte3 value) { p->z = value.x; p->y = value.y; p->x = value.z; return *p; }
inline static stdmath_byte3 stdmath_byte3_zyy(stdmath_byte3 v) { return {v.z,v.y,v.y}; }
inline static stdmath_byte3 stdmath_byte3_zyy_get(stdmath_byte3* p) { return stdmath_byte3_zyy(*p); }
inline static stdmath_byte3 stdmath_byte3_zyy_set(stdmath_byte3* p, stdmath_byte3 value) { p->z = value.x; p->y = value.y; p->y = value.z; return *p; }
inline static stdmath_byte3 stdmath_byte3_zyz(stdmath_byte3 v) { return {v.z,v.y,v.z}; }
inline static stdmath_byte3 stdmath_byte3_zyz_get(stdmath_byte3* p) { return stdmath_byte3_zyz(*p); }
inline static stdmath_byte3 stdmath_byte3_zyz_set(stdmath_byte3* p, stdmath_byte3 value) { p->z = value.x; p->y = value.y; p->z = value.z; return *p; }
inline static stdmath_byte3 stdmath_byte3_zzx(stdmath_byte3 v) { return {v.z,v.z,v.x}; }
inline static stdmath_byte3 stdmath_byte3_zzx_get(stdmath_byte3* p) { return stdmath_byte3_zzx(*p); }
inline static stdmath_byte3 stdmath_byte3_zzx_set(stdmath_byte3* p, stdmath_byte3 value) { p->z = value.x; p->z = value.y; p->x = value.z; return *p; }
inline static stdmath_byte3 stdmath_byte3_zzy(stdmath_byte3 v) { return {v.z,v.z,v.y}; }
inline static stdmath_byte3 stdmath_byte3_zzy_get(stdmath_byte3* p) { return stdmath_byte3_zzy(*p); }
inline static stdmath_byte3 stdmath_byte3_zzy_set(stdmath_byte3* p, stdmath_byte3 value) { p->z = value.x; p->z = value.y; p->y = value.z; return *p; }
inline static stdmath_byte3 stdmath_byte3_zzz(stdmath_byte3 v) { return {v.z,v.z,v.z}; }
inline static stdmath_byte3 stdmath_byte3_zzz_get(stdmath_byte3* p) { return stdmath_byte3_zzz(*p); }
inline static stdmath_byte3 stdmath_byte3_zzz_set(stdmath_byte3* p, stdmath_byte3 value) { p->z = value.x; p->z = value.y; p->z = value.z; return *p; }


#ifdef STDMATH_IMPLEMENTATION
#ifndef __cplusplus
#error "The stdmath implementations require a C++ compiler"
#endif

import stdmath.slang;

stdmath::byte3 c(stdmath_byte3 c) {
	return (stdmath::byte3&)c;
}
stdmath_byte3 c(stdmath::byte3 c) {
	return (stdmath_byte3&)c;
}

stdmath_byte3 stdmath_byte3_broadcast(uint8_t all) {
	return c(stdmath::byte3((stdmath::byte3::underlying_type)all));
}

stdmath_byte3 stdmath_byte3_add(stdmath_byte3 a, stdmath_byte3 b) {
	return c(c(a) + c(b));
}
stdmath_byte3 stdmath_byte3_subtract(stdmath_byte3 a, stdmath_byte3 b) {
	return c(c(a) - c(b));
}
stdmath_byte3 stdmath_byte3_negate(stdmath_byte3 v) {
	return c(stdmath::byte3(-(stdmath::vector<uint8_t, 3>)c(v)));
}
stdmath_byte3 stdmath_byte3_multiply(stdmath_byte3 a, stdmath_byte3 b) {
	return c(c(a) * c(b));
}
stdmath_byte3 stdmath_byte3_divide(stdmath_byte3 a, stdmath_byte3 b) {
	return c(c(a) / c(b));
}
stdmath_byte3 stdmath_byte3_scale(stdmath_byte3 v, uint8_t s) {
	return c(c(v) * (stdmath::byte3::underlying_type)s);
}

#if false
stdmath_byte3 stdmath_byte3_modulus(stdmath_byte3 a, stdmath_byte3 b) {
	return c(c(a) % c(b));
}
stdmath_byte3 stdmath_byte3_logical_not(stdmath_byte3 v) {
	return c(!c(v));
}
stdmath_byte3 stdmath_byte3_bitwise_not(stdmath_byte3 v) {
	return c(~c(v));
}
stdmath_byte3 stdmath_byte3_logical_and(stdmath_byte3 a, stdmath_byte3 b) {
	return c(c(a) && c(b));
}
stdmath_byte3 stdmath_byte3_bitwise_and(stdmath_byte3 a, stdmath_byte3 b) {
	return c(c(a) & c(b));
}
stdmath_byte3 stdmath_byte3_logical_or(stdmath_byte3 a, stdmath_byte3 b) {
	return c(c(a) || c(b));
}
stdmath_byte3 stdmath_byte3_bitwise_or(stdmath_byte3 a, stdmath_byte3 b) {
	return c(c(a) | c(b));
}
stdmath_byte3 stdmath_byte3_bitwise_xor(stdmath_byte3 a, stdmath_byte3 b) {
	return c(c(a) ^ c(b));
}
stdmath_byte3 stdmath_byte3_shift_left(stdmath_byte3 a, stdmath_byte3 b) {
	return c(c(a) << c(b));
}
stdmath_byte3 stdmath_byte3_shift_right(stdmath_byte3 a, stdmath_byte3 b) {
	return c(c(a) >> c(b));
}
#endif

stdmath_bool3 stdmath_byte3_equal_to(stdmath_byte3 a, stdmath_byte3 b) {
	return c(c(a) == c(b));
}
stdmath_bool3 stdmath_byte3_not_equal_to(stdmath_byte3 a, stdmath_byte3 b) {
	return c(c(a) != c(b));
}
stdmath_bool3 stdmath_byte3_less_than(stdmath_byte3 a, stdmath_byte3 b) {
	return c(c(a) < c(b));
}
stdmath_bool3 stdmath_byte3_less_than_or_equal_to(stdmath_byte3 a, stdmath_byte3 b) {
	return c(c(a) <= c(b));
}
stdmath_bool3 stdmath_byte3_greater_than(stdmath_byte3 a, stdmath_byte3 b) {
	return c(c(a) > c(b));
}
stdmath_bool3 stdmath_byte3_greater_than_or_equal_to(stdmath_byte3 a, stdmath_byte3 b) {
	return c(c(a) >= c(b));
}

uint8_t stdmath_byte3_length_squared(stdmath_byte3 v)  {
	return (uint8_t)c(v).length_squared();
}
uint8_t stdmath_byte3_length(stdmath_byte3 v)  {
	return (uint8_t)c(v).length();
}
uint8_t stdmath_byte3_dot(stdmath_byte3 a, stdmath_byte3 b)  {
	return (uint8_t)dot(c(a), c(b));
}
uint8_t stdmath_byte3_min_element(stdmath_byte3 v)  {
	return (uint8_t)c(v).min_element();
}
uint8_t stdmath_byte3_max_element(stdmath_byte3 v)  {
	return (uint8_t)c(v).max_element();
}

stdmath_byte3 stdmath_byte3_elementwise_transform(stdmath_byte3 v, uint8_t(*func)(uint8_t)) {
	return c(c(v).elementwise_transform(func));
}
// uint8_t stdmath_byte3_reduce_elements(stdmath_byte3 v, uint8_t initial_value, uint8_t(*reducer)(stdmath_byte3, stdmath_byte3)) {
// 	return c(v).reduce_elements(initial_value, reducer);
// }

#if 3 == 3
stdmath_byte3 stdmath_byte3_cross(stdmath_byte3 a, stdmath_byte3 b) {
	return c(cross(c(a), c(b)));
}
#endif

stdmath_byte3 stdmath_byte3_min(stdmath_byte3 a, stdmath_byte3 b) {
	return c(min(c(a), c(b)));
}
stdmath_byte3 stdmath_byte3_max(stdmath_byte3 a, stdmath_byte3 b) {
	return c(max(c(a), c(b)));
}
stdmath_byte3 stdmath_byte3_normalize(stdmath_byte3 v) {
	return c(normalize(c(v)));
}
stdmath_byte3 stdmath_byte3_lerp(stdmath_byte3 a, stdmath_byte3 b, float t) {
	return c(lerp(c(a), c(b), t));
}
stdmath_byte3 stdmath_byte3_clamp(stdmath_byte3 a, stdmath_byte3 min, stdmath_byte3 max) {
	return c(clamp(c(a), c(min), c(max)));
}
stdmath_byte3 stdmath_byte3_reflect(stdmath_byte3 a, stdmath_byte3 b) {
	return c(reflect(c(a), c(b)));
}
stdmath_bool3 stdmath_byte3_approximately_equal(stdmath_byte3 a, stdmath_byte3 b) {
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

#endif // __STDMATH_uint8_t3_H__