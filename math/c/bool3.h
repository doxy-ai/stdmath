#ifndef __STDMATH_bool3_H__
#define __STDMATH_bool3_H__

#include <stdint.h>
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
#include "util.h"

#if 3 == 1
union stdmath_bool1 {
	struct {
		bool x;
	};
	bool data[1];
};
#elif 3 == 2
union stdmath_bool2 {
	struct {
		bool x, y;
	};
	struct {
		bool u, v;
	};
	bool data[2];
};
#elif 3 == 3
union stdmath_bool3 {
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
union stdmath_bool4 {
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

stdmath_bool3 stdmath_bool3_broadcast(bool all);

stdmath_bool3 stdmath_bool3_add(stdmath_bool3 a, stdmath_bool3 b);
stdmath_bool3 stdmath_bool3_subtract(stdmath_bool3 a, stdmath_bool3 b);
stdmath_bool3 stdmath_bool3_negate(stdmath_bool3 v);
stdmath_bool3 stdmath_bool3_multiply(stdmath_bool3 a, stdmath_bool3 b);
stdmath_bool3 stdmath_bool3_divide(stdmath_bool3 a, stdmath_bool3 b);
stdmath_bool3 stdmath_bool3_scale(stdmath_bool3 v, bool s);

#if false
stdmath_bool3 stdmath_bool3_modulus(stdmath_bool3 a, stdmath_bool3 b);
stdmath_bool3 stdmath_bool3_logical_not(stdmath_bool3 v);
stdmath_bool3 stdmath_bool3_bitwise_not(stdmath_bool3 v);
stdmath_bool3 stdmath_bool3_logical_and(stdmath_bool3 a, stdmath_bool3 b);
stdmath_bool3 stdmath_bool3_bitwise_and(stdmath_bool3 a, stdmath_bool3 b);
stdmath_bool3 stdmath_bool3_logical_or(stdmath_bool3 a, stdmath_bool3 b);
stdmath_bool3 stdmath_bool3_bitwise_or(stdmath_bool3 a, stdmath_bool3 b);
stdmath_bool3 stdmath_bool3_bitwise_xor(stdmath_bool3 a, stdmath_bool3 b);
stdmath_bool3 stdmath_bool3_shift_left(stdmath_bool3 a, stdmath_bool3 b);
stdmath_bool3 stdmath_bool3_shift_right(stdmath_bool3 a, stdmath_bool3 b);
#endif

stdmath_bool3 stdmath_bool3_equal_to(stdmath_bool3 a, stdmath_bool3 b);
stdmath_bool3 stdmath_bool3_not_equal_to(stdmath_bool3 a, stdmath_bool3 b);
stdmath_bool3 stdmath_bool3_less_than(stdmath_bool3 a, stdmath_bool3 b);
stdmath_bool3 stdmath_bool3_less_than_or_equal_to(stdmath_bool3 a, stdmath_bool3 b);
stdmath_bool3 stdmath_bool3_greater_than(stdmath_bool3 a, stdmath_bool3 b);
stdmath_bool3 stdmath_bool3_greater_than_or_equal_to(stdmath_bool3 a, stdmath_bool3 b);

bool stdmath_bool3_length_squared(stdmath_bool3 v);
bool stdmath_bool3_length(stdmath_bool3 v);
bool stdmath_bool3_dot(stdmath_bool3 v);
bool stdmath_bool3_min_element(stdmath_bool3 v);
bool stdmath_bool3_max_element(stdmath_bool3 v);

stdmath_bool3 stdmath_bool3_elementwise_transform(stdmath_bool3 v, bool(*func)(bool));
// bool stdmath_bool3_reduce_elements(stdmath_bool3 v, bool initial_value, bool(*reducer)(stdmath_bool3, stdmath_bool3));

#if 3 == 3
stdmath_bool3 stdmath_bool3_cross(stdmath_bool3 a, stdmath_bool3 b);
#endif

stdmath_bool3 stdmath_bool3_min(stdmath_bool3 a, stdmath_bool3 b);
stdmath_bool3 stdmath_bool3_max(stdmath_bool3 a, stdmath_bool3 b);
stdmath_bool3 stdmath_bool3_normalize(stdmath_bool3 v);
stdmath_bool3 stdmath_bool3_lerp(stdmath_bool3 a, stdmath_bool3 b, float t);
stdmath_bool3 stdmath_bool3_clamp(stdmath_bool3 a, stdmath_bool3 min, stdmath_bool3 max);
stdmath_bool3 stdmath_bool3_reflect(stdmath_bool3 a, stdmath_bool3 b);
stdmath_bool3 stdmath_bool3_approximately_equal(stdmath_bool3 a, stdmath_bool3 b);

#if true
bool stdmath_bool3_all_of(stdmath_bool3 v);
bool stdmath_bool3_any_of(stdmath_bool3 v);
bool stdmath_bool3_none_of(stdmath_bool3 v);
bool stdmath_bool3_some_of(stdmath_bool3 v);
#endif

inline static stdmath_bool1 stdmath_bool3_x(stdmath_bool3 v) { return {v.x}; }
inline static stdmath_bool3 stdmath_bool3_x_value(stdmath_bool3 v, stdmath_bool1 value) { v.x = value.x; return v; }
inline static stdmath_bool1 stdmath_bool3_y(stdmath_bool3 v) { return {v.y}; }
inline static stdmath_bool3 stdmath_bool3_y_value(stdmath_bool3 v, stdmath_bool1 value) { v.y = value.x; return v; }
inline static stdmath_bool1 stdmath_bool3_z(stdmath_bool3 v) { return {v.z}; }
inline static stdmath_bool3 stdmath_bool3_z_value(stdmath_bool3 v, stdmath_bool1 value) { v.z = value.x; return v; }
inline static stdmath_bool2 stdmath_bool3_xx(stdmath_bool3 v) { return {v.x,v.x}; }
inline static stdmath_bool3 stdmath_bool3_xx_value(stdmath_bool3 v, stdmath_bool2 value) { v.x = value.x; v.x = value.y; return v; }
inline static stdmath_bool2 stdmath_bool3_xy(stdmath_bool3 v) { return {v.x,v.y}; }
inline static stdmath_bool3 stdmath_bool3_xy_value(stdmath_bool3 v, stdmath_bool2 value) { v.x = value.x; v.y = value.y; return v; }
inline static stdmath_bool2 stdmath_bool3_xz(stdmath_bool3 v) { return {v.x,v.z}; }
inline static stdmath_bool3 stdmath_bool3_xz_value(stdmath_bool3 v, stdmath_bool2 value) { v.x = value.x; v.z = value.y; return v; }
inline static stdmath_bool2 stdmath_bool3_yx(stdmath_bool3 v) { return {v.y,v.x}; }
inline static stdmath_bool3 stdmath_bool3_yx_value(stdmath_bool3 v, stdmath_bool2 value) { v.y = value.x; v.x = value.y; return v; }
inline static stdmath_bool2 stdmath_bool3_yy(stdmath_bool3 v) { return {v.y,v.y}; }
inline static stdmath_bool3 stdmath_bool3_yy_value(stdmath_bool3 v, stdmath_bool2 value) { v.y = value.x; v.y = value.y; return v; }
inline static stdmath_bool2 stdmath_bool3_yz(stdmath_bool3 v) { return {v.y,v.z}; }
inline static stdmath_bool3 stdmath_bool3_yz_value(stdmath_bool3 v, stdmath_bool2 value) { v.y = value.x; v.z = value.y; return v; }
inline static stdmath_bool2 stdmath_bool3_zx(stdmath_bool3 v) { return {v.z,v.x}; }
inline static stdmath_bool3 stdmath_bool3_zx_value(stdmath_bool3 v, stdmath_bool2 value) { v.z = value.x; v.x = value.y; return v; }
inline static stdmath_bool2 stdmath_bool3_zy(stdmath_bool3 v) { return {v.z,v.y}; }
inline static stdmath_bool3 stdmath_bool3_zy_value(stdmath_bool3 v, stdmath_bool2 value) { v.z = value.x; v.y = value.y; return v; }
inline static stdmath_bool2 stdmath_bool3_zz(stdmath_bool3 v) { return {v.z,v.z}; }
inline static stdmath_bool3 stdmath_bool3_zz_value(stdmath_bool3 v, stdmath_bool2 value) { v.z = value.x; v.z = value.y; return v; }
inline static stdmath_bool3 stdmath_bool3_xxx(stdmath_bool3 v) { return {v.x,v.x,v.x}; }
inline static stdmath_bool3 stdmath_bool3_xxx_value(stdmath_bool3 v, stdmath_bool3 value) { v.x = value.x; v.x = value.y; v.x = value.z; return v; }
inline static stdmath_bool3 stdmath_bool3_xxy(stdmath_bool3 v) { return {v.x,v.x,v.y}; }
inline static stdmath_bool3 stdmath_bool3_xxy_value(stdmath_bool3 v, stdmath_bool3 value) { v.x = value.x; v.x = value.y; v.y = value.z; return v; }
inline static stdmath_bool3 stdmath_bool3_xxz(stdmath_bool3 v) { return {v.x,v.x,v.z}; }
inline static stdmath_bool3 stdmath_bool3_xxz_value(stdmath_bool3 v, stdmath_bool3 value) { v.x = value.x; v.x = value.y; v.z = value.z; return v; }
inline static stdmath_bool3 stdmath_bool3_xyx(stdmath_bool3 v) { return {v.x,v.y,v.x}; }
inline static stdmath_bool3 stdmath_bool3_xyx_value(stdmath_bool3 v, stdmath_bool3 value) { v.x = value.x; v.y = value.y; v.x = value.z; return v; }
inline static stdmath_bool3 stdmath_bool3_xyy(stdmath_bool3 v) { return {v.x,v.y,v.y}; }
inline static stdmath_bool3 stdmath_bool3_xyy_value(stdmath_bool3 v, stdmath_bool3 value) { v.x = value.x; v.y = value.y; v.y = value.z; return v; }
inline static stdmath_bool3 stdmath_bool3_xyz(stdmath_bool3 v) { return {v.x,v.y,v.z}; }
inline static stdmath_bool3 stdmath_bool3_xyz_value(stdmath_bool3 v, stdmath_bool3 value) { v.x = value.x; v.y = value.y; v.z = value.z; return v; }
inline static stdmath_bool3 stdmath_bool3_xzx(stdmath_bool3 v) { return {v.x,v.z,v.x}; }
inline static stdmath_bool3 stdmath_bool3_xzx_value(stdmath_bool3 v, stdmath_bool3 value) { v.x = value.x; v.z = value.y; v.x = value.z; return v; }
inline static stdmath_bool3 stdmath_bool3_xzy(stdmath_bool3 v) { return {v.x,v.z,v.y}; }
inline static stdmath_bool3 stdmath_bool3_xzy_value(stdmath_bool3 v, stdmath_bool3 value) { v.x = value.x; v.z = value.y; v.y = value.z; return v; }
inline static stdmath_bool3 stdmath_bool3_xzz(stdmath_bool3 v) { return {v.x,v.z,v.z}; }
inline static stdmath_bool3 stdmath_bool3_xzz_value(stdmath_bool3 v, stdmath_bool3 value) { v.x = value.x; v.z = value.y; v.z = value.z; return v; }
inline static stdmath_bool3 stdmath_bool3_yxx(stdmath_bool3 v) { return {v.y,v.x,v.x}; }
inline static stdmath_bool3 stdmath_bool3_yxx_value(stdmath_bool3 v, stdmath_bool3 value) { v.y = value.x; v.x = value.y; v.x = value.z; return v; }
inline static stdmath_bool3 stdmath_bool3_yxy(stdmath_bool3 v) { return {v.y,v.x,v.y}; }
inline static stdmath_bool3 stdmath_bool3_yxy_value(stdmath_bool3 v, stdmath_bool3 value) { v.y = value.x; v.x = value.y; v.y = value.z; return v; }
inline static stdmath_bool3 stdmath_bool3_yxz(stdmath_bool3 v) { return {v.y,v.x,v.z}; }
inline static stdmath_bool3 stdmath_bool3_yxz_value(stdmath_bool3 v, stdmath_bool3 value) { v.y = value.x; v.x = value.y; v.z = value.z; return v; }
inline static stdmath_bool3 stdmath_bool3_yyx(stdmath_bool3 v) { return {v.y,v.y,v.x}; }
inline static stdmath_bool3 stdmath_bool3_yyx_value(stdmath_bool3 v, stdmath_bool3 value) { v.y = value.x; v.y = value.y; v.x = value.z; return v; }
inline static stdmath_bool3 stdmath_bool3_yyy(stdmath_bool3 v) { return {v.y,v.y,v.y}; }
inline static stdmath_bool3 stdmath_bool3_yyy_value(stdmath_bool3 v, stdmath_bool3 value) { v.y = value.x; v.y = value.y; v.y = value.z; return v; }
inline static stdmath_bool3 stdmath_bool3_yyz(stdmath_bool3 v) { return {v.y,v.y,v.z}; }
inline static stdmath_bool3 stdmath_bool3_yyz_value(stdmath_bool3 v, stdmath_bool3 value) { v.y = value.x; v.y = value.y; v.z = value.z; return v; }
inline static stdmath_bool3 stdmath_bool3_yzx(stdmath_bool3 v) { return {v.y,v.z,v.x}; }
inline static stdmath_bool3 stdmath_bool3_yzx_value(stdmath_bool3 v, stdmath_bool3 value) { v.y = value.x; v.z = value.y; v.x = value.z; return v; }
inline static stdmath_bool3 stdmath_bool3_yzy(stdmath_bool3 v) { return {v.y,v.z,v.y}; }
inline static stdmath_bool3 stdmath_bool3_yzy_value(stdmath_bool3 v, stdmath_bool3 value) { v.y = value.x; v.z = value.y; v.y = value.z; return v; }
inline static stdmath_bool3 stdmath_bool3_yzz(stdmath_bool3 v) { return {v.y,v.z,v.z}; }
inline static stdmath_bool3 stdmath_bool3_yzz_value(stdmath_bool3 v, stdmath_bool3 value) { v.y = value.x; v.z = value.y; v.z = value.z; return v; }
inline static stdmath_bool3 stdmath_bool3_zxx(stdmath_bool3 v) { return {v.z,v.x,v.x}; }
inline static stdmath_bool3 stdmath_bool3_zxx_value(stdmath_bool3 v, stdmath_bool3 value) { v.z = value.x; v.x = value.y; v.x = value.z; return v; }
inline static stdmath_bool3 stdmath_bool3_zxy(stdmath_bool3 v) { return {v.z,v.x,v.y}; }
inline static stdmath_bool3 stdmath_bool3_zxy_value(stdmath_bool3 v, stdmath_bool3 value) { v.z = value.x; v.x = value.y; v.y = value.z; return v; }
inline static stdmath_bool3 stdmath_bool3_zxz(stdmath_bool3 v) { return {v.z,v.x,v.z}; }
inline static stdmath_bool3 stdmath_bool3_zxz_value(stdmath_bool3 v, stdmath_bool3 value) { v.z = value.x; v.x = value.y; v.z = value.z; return v; }
inline static stdmath_bool3 stdmath_bool3_zyx(stdmath_bool3 v) { return {v.z,v.y,v.x}; }
inline static stdmath_bool3 stdmath_bool3_zyx_value(stdmath_bool3 v, stdmath_bool3 value) { v.z = value.x; v.y = value.y; v.x = value.z; return v; }
inline static stdmath_bool3 stdmath_bool3_zyy(stdmath_bool3 v) { return {v.z,v.y,v.y}; }
inline static stdmath_bool3 stdmath_bool3_zyy_value(stdmath_bool3 v, stdmath_bool3 value) { v.z = value.x; v.y = value.y; v.y = value.z; return v; }
inline static stdmath_bool3 stdmath_bool3_zyz(stdmath_bool3 v) { return {v.z,v.y,v.z}; }
inline static stdmath_bool3 stdmath_bool3_zyz_value(stdmath_bool3 v, stdmath_bool3 value) { v.z = value.x; v.y = value.y; v.z = value.z; return v; }
inline static stdmath_bool3 stdmath_bool3_zzx(stdmath_bool3 v) { return {v.z,v.z,v.x}; }
inline static stdmath_bool3 stdmath_bool3_zzx_value(stdmath_bool3 v, stdmath_bool3 value) { v.z = value.x; v.z = value.y; v.x = value.z; return v; }
inline static stdmath_bool3 stdmath_bool3_zzy(stdmath_bool3 v) { return {v.z,v.z,v.y}; }
inline static stdmath_bool3 stdmath_bool3_zzy_value(stdmath_bool3 v, stdmath_bool3 value) { v.z = value.x; v.z = value.y; v.y = value.z; return v; }
inline static stdmath_bool3 stdmath_bool3_zzz(stdmath_bool3 v) { return {v.z,v.z,v.z}; }
inline static stdmath_bool3 stdmath_bool3_zzz_value(stdmath_bool3 v, stdmath_bool3 value) { v.z = value.x; v.z = value.y; v.z = value.z; return v; }


#ifdef STDMATH_IMPLEMENTATION
#ifndef __cplusplus
#error "The stdmath implementations require a C++ compiler"
#endif

import stdmath.slang;

stdmath::bool3 c(stdmath_bool3 c) {
	return (stdmath::bool3&)c;
}
stdmath_bool3 c(stdmath::bool3 c) {
	return (stdmath_bool3&)c;
}

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

#endif // STDMATH_IMPLEMENTATION

#endif // __STDMATH_bool3_H__