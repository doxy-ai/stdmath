#ifndef __STDMATH_float2_H__
#define __STDMATH_float2_H__

#include <stdint.h>
#if !false
#if 2 == 1
#include "bool1.h"
#elif 2 == 2
#include "bool2.h"
#elif 2 == 3
#include "bool3.h"
#elif 2 == 4
#include "bool4.h"
#endif
#endif
#if 2 == 2
#include "float1.h"
#elif 2 == 3
#include "float2.h"
#include "float1.h"
#elif 2 == 4
#include "float3.h"
#include "float2.h"
#include "float1.h"
#endif
#include "util.h"

#if 2 == 1
union stdmath_float1 {
	struct {
		float x;
	};
	float data[1];
};
#elif 2 == 2
union stdmath_float2 {
	struct {
		float x, y;
	};
	struct {
		float u, v;
	};
	float data[2];
};
#elif 2 == 3
union stdmath_float3 {
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
#elif 2 == 4
union stdmath_float4 {
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

stdmath_float2 stdmath_float2_broadcast(float all);

stdmath_float2 stdmath_float2_add(stdmath_float2 a, stdmath_float2 b);
stdmath_float2 stdmath_float2_subtract(stdmath_float2 a, stdmath_float2 b);
stdmath_float2 stdmath_float2_negate(stdmath_float2 v);
stdmath_float2 stdmath_float2_multiply(stdmath_float2 a, stdmath_float2 b);
stdmath_float2 stdmath_float2_divide(stdmath_float2 a, stdmath_float2 b);
stdmath_float2 stdmath_float2_scale(stdmath_float2 v, float s);

#if false
stdmath_float2 stdmath_float2_modulus(stdmath_float2 a, stdmath_float2 b);
stdmath_float2 stdmath_float2_logical_not(stdmath_float2 v);
stdmath_float2 stdmath_float2_bitwise_not(stdmath_float2 v);
stdmath_float2 stdmath_float2_logical_and(stdmath_float2 a, stdmath_float2 b);
stdmath_float2 stdmath_float2_bitwise_and(stdmath_float2 a, stdmath_float2 b);
stdmath_float2 stdmath_float2_logical_or(stdmath_float2 a, stdmath_float2 b);
stdmath_float2 stdmath_float2_bitwise_or(stdmath_float2 a, stdmath_float2 b);
stdmath_float2 stdmath_float2_bitwise_xor(stdmath_float2 a, stdmath_float2 b);
stdmath_float2 stdmath_float2_shift_left(stdmath_float2 a, stdmath_float2 b);
stdmath_float2 stdmath_float2_shift_right(stdmath_float2 a, stdmath_float2 b);
#endif

stdmath_bool2 stdmath_float2_equal_to(stdmath_float2 a, stdmath_float2 b);
stdmath_bool2 stdmath_float2_not_equal_to(stdmath_float2 a, stdmath_float2 b);
stdmath_bool2 stdmath_float2_less_than(stdmath_float2 a, stdmath_float2 b);
stdmath_bool2 stdmath_float2_less_than_or_equal_to(stdmath_float2 a, stdmath_float2 b);
stdmath_bool2 stdmath_float2_greater_than(stdmath_float2 a, stdmath_float2 b);
stdmath_bool2 stdmath_float2_greater_than_or_equal_to(stdmath_float2 a, stdmath_float2 b);

float stdmath_float2_length_squared(stdmath_float2 v);
float stdmath_float2_length(stdmath_float2 v);
float stdmath_float2_dot(stdmath_float2 a, stdmath_float2 b);
float stdmath_float2_min_element(stdmath_float2 v);
float stdmath_float2_max_element(stdmath_float2 v);

stdmath_float2 stdmath_float2_elementwise_transform(stdmath_float2 v, float(*func)(float));
// float stdmath_float2_reduce_elements(stdmath_float2 v, float initial_value, float(*reducer)(stdmath_float2, stdmath_float2));

#if 2 == 3
stdmath_float3 stdmath_float3_cross(stdmath_float3 a, stdmath_float3 b);
#endif

stdmath_float2 stdmath_float2_min(stdmath_float2 a, stdmath_float2 b);
stdmath_float2 stdmath_float2_max(stdmath_float2 a, stdmath_float2 b);
stdmath_float2 stdmath_float2_normalize(stdmath_float2 v);
stdmath_float2 stdmath_float2_lerp(stdmath_float2 a, stdmath_float2 b, float t);
stdmath_float2 stdmath_float2_clamp(stdmath_float2 a, stdmath_float2 min, stdmath_float2 max);
stdmath_float2 stdmath_float2_reflect(stdmath_float2 a, stdmath_float2 b);
stdmath_bool2 stdmath_float2_approximately_equal(stdmath_float2 a, stdmath_float2 b);

#if false
bool stdmath_bool2_all_of(stdmath_bool2 v);
bool stdmath_bool2_any_of(stdmath_bool2 v);
bool stdmath_bool2_none_of(stdmath_bool2 v);
bool stdmath_bool2_some_of(stdmath_bool2 v);
#endif

inline static stdmath_float1 stdmath_float2_x(stdmath_float2 v) { return {v.x}; }
inline static stdmath_float1 stdmath_float2_x_get(stdmath_float2* p) { return stdmath_float2_x(*p); }
inline static stdmath_float2 stdmath_float2_x_set(stdmath_float2* p, stdmath_float1 value) { p->x = value.x; return *p; }
inline static stdmath_float1 stdmath_float2_y(stdmath_float2 v) { return {v.y}; }
inline static stdmath_float1 stdmath_float2_y_get(stdmath_float2* p) { return stdmath_float2_y(*p); }
inline static stdmath_float2 stdmath_float2_y_set(stdmath_float2* p, stdmath_float1 value) { p->y = value.x; return *p; }
inline static stdmath_float2 stdmath_float2_xx(stdmath_float2 v) { return {v.x,v.x}; }
inline static stdmath_float2 stdmath_float2_xx_get(stdmath_float2* p) { return stdmath_float2_xx(*p); }
inline static stdmath_float2 stdmath_float2_xx_set(stdmath_float2* p, stdmath_float2 value) { p->x = value.x; p->x = value.y; return *p; }
inline static stdmath_float2 stdmath_float2_xy(stdmath_float2 v) { return {v.x,v.y}; }
inline static stdmath_float2 stdmath_float2_xy_get(stdmath_float2* p) { return stdmath_float2_xy(*p); }
inline static stdmath_float2 stdmath_float2_xy_set(stdmath_float2* p, stdmath_float2 value) { p->x = value.x; p->y = value.y; return *p; }
inline static stdmath_float2 stdmath_float2_yx(stdmath_float2 v) { return {v.y,v.x}; }
inline static stdmath_float2 stdmath_float2_yx_get(stdmath_float2* p) { return stdmath_float2_yx(*p); }
inline static stdmath_float2 stdmath_float2_yx_set(stdmath_float2* p, stdmath_float2 value) { p->y = value.x; p->x = value.y; return *p; }
inline static stdmath_float2 stdmath_float2_yy(stdmath_float2 v) { return {v.y,v.y}; }
inline static stdmath_float2 stdmath_float2_yy_get(stdmath_float2* p) { return stdmath_float2_yy(*p); }
inline static stdmath_float2 stdmath_float2_yy_set(stdmath_float2* p, stdmath_float2 value) { p->y = value.x; p->y = value.y; return *p; }


#ifdef STDMATH_IMPLEMENTATION
#ifndef __cplusplus
#error "The stdmath implementations require a C++ compiler"
#endif

import stdmath.slang;

stdmath::float2 c(stdmath_float2 c) {
	return (stdmath::float2&)c;
}
stdmath_float2 c(stdmath::float2 c) {
	return (stdmath_float2&)c;
}

stdmath_float2 stdmath_float2_broadcast(float all) {
	return c(stdmath::float2((stdmath::float2::underlying_type)all));
}

stdmath_float2 stdmath_float2_add(stdmath_float2 a, stdmath_float2 b) {
	return c(c(a) + c(b));
}
stdmath_float2 stdmath_float2_subtract(stdmath_float2 a, stdmath_float2 b) {
	return c(c(a) - c(b));
}
stdmath_float2 stdmath_float2_negate(stdmath_float2 v) {
	return c(stdmath::float2(-(stdmath::vector<float, 2>)c(v)));
}
stdmath_float2 stdmath_float2_multiply(stdmath_float2 a, stdmath_float2 b) {
	return c(c(a) * c(b));
}
stdmath_float2 stdmath_float2_divide(stdmath_float2 a, stdmath_float2 b) {
	return c(c(a) / c(b));
}
stdmath_float2 stdmath_float2_scale(stdmath_float2 v, float s) {
	return c(c(v) * (stdmath::float2::underlying_type)s);
}

#if false
stdmath_float2 stdmath_float2_modulus(stdmath_float2 a, stdmath_float2 b) {
	return c(c(a) % c(b));
}
stdmath_float2 stdmath_float2_logical_not(stdmath_float2 v) {
	return c(!c(v));
}
stdmath_float2 stdmath_float2_bitwise_not(stdmath_float2 v) {
	return c(~c(v));
}
stdmath_float2 stdmath_float2_logical_and(stdmath_float2 a, stdmath_float2 b) {
	return c(c(a) && c(b));
}
stdmath_float2 stdmath_float2_bitwise_and(stdmath_float2 a, stdmath_float2 b) {
	return c(c(a) & c(b));
}
stdmath_float2 stdmath_float2_logical_or(stdmath_float2 a, stdmath_float2 b) {
	return c(c(a) || c(b));
}
stdmath_float2 stdmath_float2_bitwise_or(stdmath_float2 a, stdmath_float2 b) {
	return c(c(a) | c(b));
}
stdmath_float2 stdmath_float2_bitwise_xor(stdmath_float2 a, stdmath_float2 b) {
	return c(c(a) ^ c(b));
}
stdmath_float2 stdmath_float2_shift_left(stdmath_float2 a, stdmath_float2 b) {
	return c(c(a) << c(b));
}
stdmath_float2 stdmath_float2_shift_right(stdmath_float2 a, stdmath_float2 b) {
	return c(c(a) >> c(b));
}
#endif

stdmath_bool2 stdmath_float2_equal_to(stdmath_float2 a, stdmath_float2 b) {
	return c(c(a) == c(b));
}
stdmath_bool2 stdmath_float2_not_equal_to(stdmath_float2 a, stdmath_float2 b) {
	return c(c(a) != c(b));
}
stdmath_bool2 stdmath_float2_less_than(stdmath_float2 a, stdmath_float2 b) {
	return c(c(a) < c(b));
}
stdmath_bool2 stdmath_float2_less_than_or_equal_to(stdmath_float2 a, stdmath_float2 b) {
	return c(c(a) <= c(b));
}
stdmath_bool2 stdmath_float2_greater_than(stdmath_float2 a, stdmath_float2 b) {
	return c(c(a) > c(b));
}
stdmath_bool2 stdmath_float2_greater_than_or_equal_to(stdmath_float2 a, stdmath_float2 b) {
	return c(c(a) >= c(b));
}

float stdmath_float2_length_squared(stdmath_float2 v)  {
	return (float)c(v).length_squared();
}
float stdmath_float2_length(stdmath_float2 v)  {
	return (float)c(v).length();
}
float stdmath_float2_dot(stdmath_float2 a, stdmath_float2 b)  {
	return (float)dot(c(a), c(b));
}
float stdmath_float2_min_element(stdmath_float2 v)  {
	return (float)c(v).min_element();
}
float stdmath_float2_max_element(stdmath_float2 v)  {
	return (float)c(v).max_element();
}

stdmath_float2 stdmath_float2_elementwise_transform(stdmath_float2 v, float(*func)(float)) {
	return c(c(v).elementwise_transform(func));
}
// float stdmath_float2_reduce_elements(stdmath_float2 v, float initial_value, float(*reducer)(stdmath_float2, stdmath_float2)) {
// 	return c(v).reduce_elements(initial_value, reducer);
// }

#if 2 == 3
stdmath_float2 stdmath_float2_cross(stdmath_float2 a, stdmath_float2 b) {
	return c(cross(c(a), c(b)));
}
#endif

stdmath_float2 stdmath_float2_min(stdmath_float2 a, stdmath_float2 b) {
	return c(min(c(a), c(b)));
}
stdmath_float2 stdmath_float2_max(stdmath_float2 a, stdmath_float2 b) {
	return c(max(c(a), c(b)));
}
stdmath_float2 stdmath_float2_normalize(stdmath_float2 v) {
	return c(normalize(c(v)));
}
stdmath_float2 stdmath_float2_lerp(stdmath_float2 a, stdmath_float2 b, float t) {
	return c(lerp(c(a), c(b), t));
}
stdmath_float2 stdmath_float2_clamp(stdmath_float2 a, stdmath_float2 min, stdmath_float2 max) {
	return c(clamp(c(a), c(min), c(max)));
}
stdmath_float2 stdmath_float2_reflect(stdmath_float2 a, stdmath_float2 b) {
	return c(reflect(c(a), c(b)));
}
stdmath_bool2 stdmath_float2_approximately_equal(stdmath_float2 a, stdmath_float2 b) {
	return c(approximately_equal(c(a), c(b)));
}

#if false
bool stdmath_bool2_all_of(stdmath_bool2 v) {
	return all_of(c(v));
}
bool stdmath_bool2_any_of(stdmath_bool2 v) {
	return any_of(c(v));
}
bool stdmath_bool2_none_of(stdmath_bool2 v) {
	return none_of(c(v));
}
bool stdmath_bool2_some_of(stdmath_bool2 v) {
	return some_of(c(v));
}
#endif

#endif // STDMATH_IMPLEMENTATION

#endif // __STDMATH_float2_H__