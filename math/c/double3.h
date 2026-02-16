#ifndef __STDMATH_double3_H__
#define __STDMATH_double3_H__

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
#include "double1.h"
#elif 3 == 3
#include "double2.h"
#include "double1.h"
#elif 3 == 4
#include "double3.h"
#include "double2.h"
#include "double1.h"
#endif
#include "util.h"

#if 3 == 1
union stdmath_double1 {
	struct {
		double x;
	};
	double data[1];
};
#elif 3 == 2
union stdmath_double2 {
	struct {
		double x, y;
	};
	struct {
		double u, v;
	};
	double data[2];
};
#elif 3 == 3
union stdmath_double3 {
	struct {
		double x, y, z;
	};
	struct {
		double r, g, b;
	};
	struct {
		double h, s, v;
	};
	double data[4]; // double3s are aligned as if they were double4s
};
#elif 3 == 4
union stdmath_double4 {
	struct {
		double x, y, z, w;
	};
	struct {
		double r, g, b, a;
	};
	struct {
		double h, s, v;
	};
	double data[4];
};
#endif

stdmath_double3 stdmath_double3_broadcast(double all);

stdmath_double3 stdmath_double3_add(stdmath_double3 a, stdmath_double3 b);
stdmath_double3 stdmath_double3_subtract(stdmath_double3 a, stdmath_double3 b);
stdmath_double3 stdmath_double3_negate(stdmath_double3 v);
stdmath_double3 stdmath_double3_multiply(stdmath_double3 a, stdmath_double3 b);
stdmath_double3 stdmath_double3_divide(stdmath_double3 a, stdmath_double3 b);
stdmath_double3 stdmath_double3_scale(stdmath_double3 v, double s);

#if false
stdmath_double3 stdmath_double3_modulus(stdmath_double3 a, stdmath_double3 b);
stdmath_double3 stdmath_double3_logical_not(stdmath_double3 v);
stdmath_double3 stdmath_double3_bitwise_not(stdmath_double3 v);
stdmath_double3 stdmath_double3_logical_and(stdmath_double3 a, stdmath_double3 b);
stdmath_double3 stdmath_double3_bitwise_and(stdmath_double3 a, stdmath_double3 b);
stdmath_double3 stdmath_double3_logical_or(stdmath_double3 a, stdmath_double3 b);
stdmath_double3 stdmath_double3_bitwise_or(stdmath_double3 a, stdmath_double3 b);
stdmath_double3 stdmath_double3_bitwise_xor(stdmath_double3 a, stdmath_double3 b);
stdmath_double3 stdmath_double3_shift_left(stdmath_double3 a, stdmath_double3 b);
stdmath_double3 stdmath_double3_shift_right(stdmath_double3 a, stdmath_double3 b);
#endif

stdmath_bool3 stdmath_double3_equal_to(stdmath_double3 a, stdmath_double3 b);
stdmath_bool3 stdmath_double3_not_equal_to(stdmath_double3 a, stdmath_double3 b);
stdmath_bool3 stdmath_double3_less_than(stdmath_double3 a, stdmath_double3 b);
stdmath_bool3 stdmath_double3_less_than_or_equal_to(stdmath_double3 a, stdmath_double3 b);
stdmath_bool3 stdmath_double3_greater_than(stdmath_double3 a, stdmath_double3 b);
stdmath_bool3 stdmath_double3_greater_than_or_equal_to(stdmath_double3 a, stdmath_double3 b);

double stdmath_double3_length_squared(stdmath_double3 v);
double stdmath_double3_length(stdmath_double3 v);
double stdmath_double3_dot(stdmath_double3 a, stdmath_double3 b);
double stdmath_double3_min_element(stdmath_double3 v);
double stdmath_double3_max_element(stdmath_double3 v);

stdmath_double3 stdmath_double3_elementwise_transform(stdmath_double3 v, double(*func)(double));
// double stdmath_double3_reduce_elements(stdmath_double3 v, double initial_value, double(*reducer)(stdmath_double3, stdmath_double3));

#if 3 == 3
stdmath_double3 stdmath_double3_cross(stdmath_double3 a, stdmath_double3 b);
#endif

stdmath_double3 stdmath_double3_min(stdmath_double3 a, stdmath_double3 b);
stdmath_double3 stdmath_double3_max(stdmath_double3 a, stdmath_double3 b);
stdmath_double3 stdmath_double3_normalize(stdmath_double3 v);
stdmath_double3 stdmath_double3_lerp(stdmath_double3 a, stdmath_double3 b, float t);
stdmath_double3 stdmath_double3_clamp(stdmath_double3 a, stdmath_double3 min, stdmath_double3 max);
stdmath_double3 stdmath_double3_reflect(stdmath_double3 a, stdmath_double3 b);
stdmath_bool3 stdmath_double3_approximately_equal(stdmath_double3 a, stdmath_double3 b);

#if false
bool stdmath_bool3_all_of(stdmath_bool3 v);
bool stdmath_bool3_any_of(stdmath_bool3 v);
bool stdmath_bool3_none_of(stdmath_bool3 v);
bool stdmath_bool3_some_of(stdmath_bool3 v);
#endif

inline static stdmath_double1 stdmath_double3_x(stdmath_double3 v) { return {v.x}; }
inline static stdmath_double1 stdmath_double3_x_get(stdmath_double3* p) { return stdmath_double3_x(*p); }
inline static stdmath_double3 stdmath_double3_x_set(stdmath_double3* p, stdmath_double1 value) { p->x = value.x; return *p; }
inline static stdmath_double1 stdmath_double3_y(stdmath_double3 v) { return {v.y}; }
inline static stdmath_double1 stdmath_double3_y_get(stdmath_double3* p) { return stdmath_double3_y(*p); }
inline static stdmath_double3 stdmath_double3_y_set(stdmath_double3* p, stdmath_double1 value) { p->y = value.x; return *p; }
inline static stdmath_double1 stdmath_double3_z(stdmath_double3 v) { return {v.z}; }
inline static stdmath_double1 stdmath_double3_z_get(stdmath_double3* p) { return stdmath_double3_z(*p); }
inline static stdmath_double3 stdmath_double3_z_set(stdmath_double3* p, stdmath_double1 value) { p->z = value.x; return *p; }
inline static stdmath_double2 stdmath_double3_xx(stdmath_double3 v) { return {v.x,v.x}; }
inline static stdmath_double2 stdmath_double3_xx_get(stdmath_double3* p) { return stdmath_double3_xx(*p); }
inline static stdmath_double3 stdmath_double3_xx_set(stdmath_double3* p, stdmath_double2 value) { p->x = value.x; p->x = value.y; return *p; }
inline static stdmath_double2 stdmath_double3_xy(stdmath_double3 v) { return {v.x,v.y}; }
inline static stdmath_double2 stdmath_double3_xy_get(stdmath_double3* p) { return stdmath_double3_xy(*p); }
inline static stdmath_double3 stdmath_double3_xy_set(stdmath_double3* p, stdmath_double2 value) { p->x = value.x; p->y = value.y; return *p; }
inline static stdmath_double2 stdmath_double3_xz(stdmath_double3 v) { return {v.x,v.z}; }
inline static stdmath_double2 stdmath_double3_xz_get(stdmath_double3* p) { return stdmath_double3_xz(*p); }
inline static stdmath_double3 stdmath_double3_xz_set(stdmath_double3* p, stdmath_double2 value) { p->x = value.x; p->z = value.y; return *p; }
inline static stdmath_double2 stdmath_double3_yx(stdmath_double3 v) { return {v.y,v.x}; }
inline static stdmath_double2 stdmath_double3_yx_get(stdmath_double3* p) { return stdmath_double3_yx(*p); }
inline static stdmath_double3 stdmath_double3_yx_set(stdmath_double3* p, stdmath_double2 value) { p->y = value.x; p->x = value.y; return *p; }
inline static stdmath_double2 stdmath_double3_yy(stdmath_double3 v) { return {v.y,v.y}; }
inline static stdmath_double2 stdmath_double3_yy_get(stdmath_double3* p) { return stdmath_double3_yy(*p); }
inline static stdmath_double3 stdmath_double3_yy_set(stdmath_double3* p, stdmath_double2 value) { p->y = value.x; p->y = value.y; return *p; }
inline static stdmath_double2 stdmath_double3_yz(stdmath_double3 v) { return {v.y,v.z}; }
inline static stdmath_double2 stdmath_double3_yz_get(stdmath_double3* p) { return stdmath_double3_yz(*p); }
inline static stdmath_double3 stdmath_double3_yz_set(stdmath_double3* p, stdmath_double2 value) { p->y = value.x; p->z = value.y; return *p; }
inline static stdmath_double2 stdmath_double3_zx(stdmath_double3 v) { return {v.z,v.x}; }
inline static stdmath_double2 stdmath_double3_zx_get(stdmath_double3* p) { return stdmath_double3_zx(*p); }
inline static stdmath_double3 stdmath_double3_zx_set(stdmath_double3* p, stdmath_double2 value) { p->z = value.x; p->x = value.y; return *p; }
inline static stdmath_double2 stdmath_double3_zy(stdmath_double3 v) { return {v.z,v.y}; }
inline static stdmath_double2 stdmath_double3_zy_get(stdmath_double3* p) { return stdmath_double3_zy(*p); }
inline static stdmath_double3 stdmath_double3_zy_set(stdmath_double3* p, stdmath_double2 value) { p->z = value.x; p->y = value.y; return *p; }
inline static stdmath_double2 stdmath_double3_zz(stdmath_double3 v) { return {v.z,v.z}; }
inline static stdmath_double2 stdmath_double3_zz_get(stdmath_double3* p) { return stdmath_double3_zz(*p); }
inline static stdmath_double3 stdmath_double3_zz_set(stdmath_double3* p, stdmath_double2 value) { p->z = value.x; p->z = value.y; return *p; }
inline static stdmath_double3 stdmath_double3_xxx(stdmath_double3 v) { return {v.x,v.x,v.x}; }
inline static stdmath_double3 stdmath_double3_xxx_get(stdmath_double3* p) { return stdmath_double3_xxx(*p); }
inline static stdmath_double3 stdmath_double3_xxx_set(stdmath_double3* p, stdmath_double3 value) { p->x = value.x; p->x = value.y; p->x = value.z; return *p; }
inline static stdmath_double3 stdmath_double3_xxy(stdmath_double3 v) { return {v.x,v.x,v.y}; }
inline static stdmath_double3 stdmath_double3_xxy_get(stdmath_double3* p) { return stdmath_double3_xxy(*p); }
inline static stdmath_double3 stdmath_double3_xxy_set(stdmath_double3* p, stdmath_double3 value) { p->x = value.x; p->x = value.y; p->y = value.z; return *p; }
inline static stdmath_double3 stdmath_double3_xxz(stdmath_double3 v) { return {v.x,v.x,v.z}; }
inline static stdmath_double3 stdmath_double3_xxz_get(stdmath_double3* p) { return stdmath_double3_xxz(*p); }
inline static stdmath_double3 stdmath_double3_xxz_set(stdmath_double3* p, stdmath_double3 value) { p->x = value.x; p->x = value.y; p->z = value.z; return *p; }
inline static stdmath_double3 stdmath_double3_xyx(stdmath_double3 v) { return {v.x,v.y,v.x}; }
inline static stdmath_double3 stdmath_double3_xyx_get(stdmath_double3* p) { return stdmath_double3_xyx(*p); }
inline static stdmath_double3 stdmath_double3_xyx_set(stdmath_double3* p, stdmath_double3 value) { p->x = value.x; p->y = value.y; p->x = value.z; return *p; }
inline static stdmath_double3 stdmath_double3_xyy(stdmath_double3 v) { return {v.x,v.y,v.y}; }
inline static stdmath_double3 stdmath_double3_xyy_get(stdmath_double3* p) { return stdmath_double3_xyy(*p); }
inline static stdmath_double3 stdmath_double3_xyy_set(stdmath_double3* p, stdmath_double3 value) { p->x = value.x; p->y = value.y; p->y = value.z; return *p; }
inline static stdmath_double3 stdmath_double3_xyz(stdmath_double3 v) { return {v.x,v.y,v.z}; }
inline static stdmath_double3 stdmath_double3_xyz_get(stdmath_double3* p) { return stdmath_double3_xyz(*p); }
inline static stdmath_double3 stdmath_double3_xyz_set(stdmath_double3* p, stdmath_double3 value) { p->x = value.x; p->y = value.y; p->z = value.z; return *p; }
inline static stdmath_double3 stdmath_double3_xzx(stdmath_double3 v) { return {v.x,v.z,v.x}; }
inline static stdmath_double3 stdmath_double3_xzx_get(stdmath_double3* p) { return stdmath_double3_xzx(*p); }
inline static stdmath_double3 stdmath_double3_xzx_set(stdmath_double3* p, stdmath_double3 value) { p->x = value.x; p->z = value.y; p->x = value.z; return *p; }
inline static stdmath_double3 stdmath_double3_xzy(stdmath_double3 v) { return {v.x,v.z,v.y}; }
inline static stdmath_double3 stdmath_double3_xzy_get(stdmath_double3* p) { return stdmath_double3_xzy(*p); }
inline static stdmath_double3 stdmath_double3_xzy_set(stdmath_double3* p, stdmath_double3 value) { p->x = value.x; p->z = value.y; p->y = value.z; return *p; }
inline static stdmath_double3 stdmath_double3_xzz(stdmath_double3 v) { return {v.x,v.z,v.z}; }
inline static stdmath_double3 stdmath_double3_xzz_get(stdmath_double3* p) { return stdmath_double3_xzz(*p); }
inline static stdmath_double3 stdmath_double3_xzz_set(stdmath_double3* p, stdmath_double3 value) { p->x = value.x; p->z = value.y; p->z = value.z; return *p; }
inline static stdmath_double3 stdmath_double3_yxx(stdmath_double3 v) { return {v.y,v.x,v.x}; }
inline static stdmath_double3 stdmath_double3_yxx_get(stdmath_double3* p) { return stdmath_double3_yxx(*p); }
inline static stdmath_double3 stdmath_double3_yxx_set(stdmath_double3* p, stdmath_double3 value) { p->y = value.x; p->x = value.y; p->x = value.z; return *p; }
inline static stdmath_double3 stdmath_double3_yxy(stdmath_double3 v) { return {v.y,v.x,v.y}; }
inline static stdmath_double3 stdmath_double3_yxy_get(stdmath_double3* p) { return stdmath_double3_yxy(*p); }
inline static stdmath_double3 stdmath_double3_yxy_set(stdmath_double3* p, stdmath_double3 value) { p->y = value.x; p->x = value.y; p->y = value.z; return *p; }
inline static stdmath_double3 stdmath_double3_yxz(stdmath_double3 v) { return {v.y,v.x,v.z}; }
inline static stdmath_double3 stdmath_double3_yxz_get(stdmath_double3* p) { return stdmath_double3_yxz(*p); }
inline static stdmath_double3 stdmath_double3_yxz_set(stdmath_double3* p, stdmath_double3 value) { p->y = value.x; p->x = value.y; p->z = value.z; return *p; }
inline static stdmath_double3 stdmath_double3_yyx(stdmath_double3 v) { return {v.y,v.y,v.x}; }
inline static stdmath_double3 stdmath_double3_yyx_get(stdmath_double3* p) { return stdmath_double3_yyx(*p); }
inline static stdmath_double3 stdmath_double3_yyx_set(stdmath_double3* p, stdmath_double3 value) { p->y = value.x; p->y = value.y; p->x = value.z; return *p; }
inline static stdmath_double3 stdmath_double3_yyy(stdmath_double3 v) { return {v.y,v.y,v.y}; }
inline static stdmath_double3 stdmath_double3_yyy_get(stdmath_double3* p) { return stdmath_double3_yyy(*p); }
inline static stdmath_double3 stdmath_double3_yyy_set(stdmath_double3* p, stdmath_double3 value) { p->y = value.x; p->y = value.y; p->y = value.z; return *p; }
inline static stdmath_double3 stdmath_double3_yyz(stdmath_double3 v) { return {v.y,v.y,v.z}; }
inline static stdmath_double3 stdmath_double3_yyz_get(stdmath_double3* p) { return stdmath_double3_yyz(*p); }
inline static stdmath_double3 stdmath_double3_yyz_set(stdmath_double3* p, stdmath_double3 value) { p->y = value.x; p->y = value.y; p->z = value.z; return *p; }
inline static stdmath_double3 stdmath_double3_yzx(stdmath_double3 v) { return {v.y,v.z,v.x}; }
inline static stdmath_double3 stdmath_double3_yzx_get(stdmath_double3* p) { return stdmath_double3_yzx(*p); }
inline static stdmath_double3 stdmath_double3_yzx_set(stdmath_double3* p, stdmath_double3 value) { p->y = value.x; p->z = value.y; p->x = value.z; return *p; }
inline static stdmath_double3 stdmath_double3_yzy(stdmath_double3 v) { return {v.y,v.z,v.y}; }
inline static stdmath_double3 stdmath_double3_yzy_get(stdmath_double3* p) { return stdmath_double3_yzy(*p); }
inline static stdmath_double3 stdmath_double3_yzy_set(stdmath_double3* p, stdmath_double3 value) { p->y = value.x; p->z = value.y; p->y = value.z; return *p; }
inline static stdmath_double3 stdmath_double3_yzz(stdmath_double3 v) { return {v.y,v.z,v.z}; }
inline static stdmath_double3 stdmath_double3_yzz_get(stdmath_double3* p) { return stdmath_double3_yzz(*p); }
inline static stdmath_double3 stdmath_double3_yzz_set(stdmath_double3* p, stdmath_double3 value) { p->y = value.x; p->z = value.y; p->z = value.z; return *p; }
inline static stdmath_double3 stdmath_double3_zxx(stdmath_double3 v) { return {v.z,v.x,v.x}; }
inline static stdmath_double3 stdmath_double3_zxx_get(stdmath_double3* p) { return stdmath_double3_zxx(*p); }
inline static stdmath_double3 stdmath_double3_zxx_set(stdmath_double3* p, stdmath_double3 value) { p->z = value.x; p->x = value.y; p->x = value.z; return *p; }
inline static stdmath_double3 stdmath_double3_zxy(stdmath_double3 v) { return {v.z,v.x,v.y}; }
inline static stdmath_double3 stdmath_double3_zxy_get(stdmath_double3* p) { return stdmath_double3_zxy(*p); }
inline static stdmath_double3 stdmath_double3_zxy_set(stdmath_double3* p, stdmath_double3 value) { p->z = value.x; p->x = value.y; p->y = value.z; return *p; }
inline static stdmath_double3 stdmath_double3_zxz(stdmath_double3 v) { return {v.z,v.x,v.z}; }
inline static stdmath_double3 stdmath_double3_zxz_get(stdmath_double3* p) { return stdmath_double3_zxz(*p); }
inline static stdmath_double3 stdmath_double3_zxz_set(stdmath_double3* p, stdmath_double3 value) { p->z = value.x; p->x = value.y; p->z = value.z; return *p; }
inline static stdmath_double3 stdmath_double3_zyx(stdmath_double3 v) { return {v.z,v.y,v.x}; }
inline static stdmath_double3 stdmath_double3_zyx_get(stdmath_double3* p) { return stdmath_double3_zyx(*p); }
inline static stdmath_double3 stdmath_double3_zyx_set(stdmath_double3* p, stdmath_double3 value) { p->z = value.x; p->y = value.y; p->x = value.z; return *p; }
inline static stdmath_double3 stdmath_double3_zyy(stdmath_double3 v) { return {v.z,v.y,v.y}; }
inline static stdmath_double3 stdmath_double3_zyy_get(stdmath_double3* p) { return stdmath_double3_zyy(*p); }
inline static stdmath_double3 stdmath_double3_zyy_set(stdmath_double3* p, stdmath_double3 value) { p->z = value.x; p->y = value.y; p->y = value.z; return *p; }
inline static stdmath_double3 stdmath_double3_zyz(stdmath_double3 v) { return {v.z,v.y,v.z}; }
inline static stdmath_double3 stdmath_double3_zyz_get(stdmath_double3* p) { return stdmath_double3_zyz(*p); }
inline static stdmath_double3 stdmath_double3_zyz_set(stdmath_double3* p, stdmath_double3 value) { p->z = value.x; p->y = value.y; p->z = value.z; return *p; }
inline static stdmath_double3 stdmath_double3_zzx(stdmath_double3 v) { return {v.z,v.z,v.x}; }
inline static stdmath_double3 stdmath_double3_zzx_get(stdmath_double3* p) { return stdmath_double3_zzx(*p); }
inline static stdmath_double3 stdmath_double3_zzx_set(stdmath_double3* p, stdmath_double3 value) { p->z = value.x; p->z = value.y; p->x = value.z; return *p; }
inline static stdmath_double3 stdmath_double3_zzy(stdmath_double3 v) { return {v.z,v.z,v.y}; }
inline static stdmath_double3 stdmath_double3_zzy_get(stdmath_double3* p) { return stdmath_double3_zzy(*p); }
inline static stdmath_double3 stdmath_double3_zzy_set(stdmath_double3* p, stdmath_double3 value) { p->z = value.x; p->z = value.y; p->y = value.z; return *p; }
inline static stdmath_double3 stdmath_double3_zzz(stdmath_double3 v) { return {v.z,v.z,v.z}; }
inline static stdmath_double3 stdmath_double3_zzz_get(stdmath_double3* p) { return stdmath_double3_zzz(*p); }
inline static stdmath_double3 stdmath_double3_zzz_set(stdmath_double3* p, stdmath_double3 value) { p->z = value.x; p->z = value.y; p->z = value.z; return *p; }


#ifdef STDMATH_IMPLEMENTATION
#ifndef __cplusplus
#error "The stdmath implementations require a C++ compiler"
#endif

import stdmath.slang;

stdmath::double3 c(stdmath_double3 c) {
	return (stdmath::double3&)c;
}
stdmath_double3 c(stdmath::double3 c) {
	return (stdmath_double3&)c;
}

stdmath_double3 stdmath_double3_broadcast(double all) {
	return c(stdmath::double3((stdmath::double3::underlying_type)all));
}

stdmath_double3 stdmath_double3_add(stdmath_double3 a, stdmath_double3 b) {
	return c(c(a) + c(b));
}
stdmath_double3 stdmath_double3_subtract(stdmath_double3 a, stdmath_double3 b) {
	return c(c(a) - c(b));
}
stdmath_double3 stdmath_double3_negate(stdmath_double3 v) {
	return c(stdmath::double3(-(stdmath::vector<double, 3>)c(v)));
}
stdmath_double3 stdmath_double3_multiply(stdmath_double3 a, stdmath_double3 b) {
	return c(c(a) * c(b));
}
stdmath_double3 stdmath_double3_divide(stdmath_double3 a, stdmath_double3 b) {
	return c(c(a) / c(b));
}
stdmath_double3 stdmath_double3_scale(stdmath_double3 v, double s) {
	return c(c(v) * (stdmath::double3::underlying_type)s);
}

#if false
stdmath_double3 stdmath_double3_modulus(stdmath_double3 a, stdmath_double3 b) {
	return c(c(a) % c(b));
}
stdmath_double3 stdmath_double3_logical_not(stdmath_double3 v) {
	return c(!c(v));
}
stdmath_double3 stdmath_double3_bitwise_not(stdmath_double3 v) {
	return c(~c(v));
}
stdmath_double3 stdmath_double3_logical_and(stdmath_double3 a, stdmath_double3 b) {
	return c(c(a) && c(b));
}
stdmath_double3 stdmath_double3_bitwise_and(stdmath_double3 a, stdmath_double3 b) {
	return c(c(a) & c(b));
}
stdmath_double3 stdmath_double3_logical_or(stdmath_double3 a, stdmath_double3 b) {
	return c(c(a) || c(b));
}
stdmath_double3 stdmath_double3_bitwise_or(stdmath_double3 a, stdmath_double3 b) {
	return c(c(a) | c(b));
}
stdmath_double3 stdmath_double3_bitwise_xor(stdmath_double3 a, stdmath_double3 b) {
	return c(c(a) ^ c(b));
}
stdmath_double3 stdmath_double3_shift_left(stdmath_double3 a, stdmath_double3 b) {
	return c(c(a) << c(b));
}
stdmath_double3 stdmath_double3_shift_right(stdmath_double3 a, stdmath_double3 b) {
	return c(c(a) >> c(b));
}
#endif

stdmath_bool3 stdmath_double3_equal_to(stdmath_double3 a, stdmath_double3 b) {
	return c(c(a) == c(b));
}
stdmath_bool3 stdmath_double3_not_equal_to(stdmath_double3 a, stdmath_double3 b) {
	return c(c(a) != c(b));
}
stdmath_bool3 stdmath_double3_less_than(stdmath_double3 a, stdmath_double3 b) {
	return c(c(a) < c(b));
}
stdmath_bool3 stdmath_double3_less_than_or_equal_to(stdmath_double3 a, stdmath_double3 b) {
	return c(c(a) <= c(b));
}
stdmath_bool3 stdmath_double3_greater_than(stdmath_double3 a, stdmath_double3 b) {
	return c(c(a) > c(b));
}
stdmath_bool3 stdmath_double3_greater_than_or_equal_to(stdmath_double3 a, stdmath_double3 b) {
	return c(c(a) >= c(b));
}

double stdmath_double3_length_squared(stdmath_double3 v)  {
	return (double)c(v).length_squared();
}
double stdmath_double3_length(stdmath_double3 v)  {
	return (double)c(v).length();
}
double stdmath_double3_dot(stdmath_double3 a, stdmath_double3 b)  {
	return (double)dot(c(a), c(b));
}
double stdmath_double3_min_element(stdmath_double3 v)  {
	return (double)c(v).min_element();
}
double stdmath_double3_max_element(stdmath_double3 v)  {
	return (double)c(v).max_element();
}

stdmath_double3 stdmath_double3_elementwise_transform(stdmath_double3 v, double(*func)(double)) {
	return c(c(v).elementwise_transform(func));
}
// double stdmath_double3_reduce_elements(stdmath_double3 v, double initial_value, double(*reducer)(stdmath_double3, stdmath_double3)) {
// 	return c(v).reduce_elements(initial_value, reducer);
// }

#if 3 == 3
stdmath_double3 stdmath_double3_cross(stdmath_double3 a, stdmath_double3 b) {
	return c(cross(c(a), c(b)));
}
#endif

stdmath_double3 stdmath_double3_min(stdmath_double3 a, stdmath_double3 b) {
	return c(min(c(a), c(b)));
}
stdmath_double3 stdmath_double3_max(stdmath_double3 a, stdmath_double3 b) {
	return c(max(c(a), c(b)));
}
stdmath_double3 stdmath_double3_normalize(stdmath_double3 v) {
	return c(normalize(c(v)));
}
stdmath_double3 stdmath_double3_lerp(stdmath_double3 a, stdmath_double3 b, float t) {
	return c(lerp(c(a), c(b), t));
}
stdmath_double3 stdmath_double3_clamp(stdmath_double3 a, stdmath_double3 min, stdmath_double3 max) {
	return c(clamp(c(a), c(min), c(max)));
}
stdmath_double3 stdmath_double3_reflect(stdmath_double3 a, stdmath_double3 b) {
	return c(reflect(c(a), c(b)));
}
stdmath_bool3 stdmath_double3_approximately_equal(stdmath_double3 a, stdmath_double3 b) {
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

#endif // __STDMATH_double3_H__