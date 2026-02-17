#ifndef __STDMATH_uint32_t2_H__
#define __STDMATH_uint32_t2_H__

#ifndef STDMATH_MODULE
#include <stdint.h>
#endif
#include "../maybe_export.h"

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
#include "uint1.h"
#elif 2 == 3
#include "uint2.h"
#include "uint1.h"
#elif 2 == 4
#include "uint3.h"
#include "uint2.h"
#include "uint1.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if 2 == 1
STDMATH_EXPORT union stdmath_uint1 {
	struct {
		uint32_t x;
	};
	uint32_t data[1];
};
#elif 2 == 2
STDMATH_EXPORT union stdmath_uint2 {
	struct {
		uint32_t x, y;
	};
	struct {
		uint32_t u, v;
	};
	uint32_t data[2];
};
#elif 2 == 3
STDMATH_EXPORT union stdmath_uint3 {
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
#elif 2 == 4
STDMATH_EXPORT union stdmath_uint4 {
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

STDMATH_EXPORT stdmath_uint2 stdmath_uint2_broadcast(uint32_t all);

STDMATH_EXPORT stdmath_uint2 stdmath_uint2_add(stdmath_uint2 a, stdmath_uint2 b);
STDMATH_EXPORT stdmath_uint2 stdmath_uint2_subtract(stdmath_uint2 a, stdmath_uint2 b);
STDMATH_EXPORT stdmath_uint2 stdmath_uint2_negate(stdmath_uint2 v);
STDMATH_EXPORT stdmath_uint2 stdmath_uint2_multiply(stdmath_uint2 a, stdmath_uint2 b);
STDMATH_EXPORT stdmath_uint2 stdmath_uint2_divide(stdmath_uint2 a, stdmath_uint2 b);
STDMATH_EXPORT stdmath_uint2 stdmath_uint2_scale(stdmath_uint2 v, uint32_t s);

#if false
STDMATH_EXPORT stdmath_uint2 stdmath_uint2_modulus(stdmath_uint2 a, stdmath_uint2 b);
STDMATH_EXPORT stdmath_uint2 stdmath_uint2_logical_not(stdmath_uint2 v);
STDMATH_EXPORT stdmath_uint2 stdmath_uint2_bitwise_not(stdmath_uint2 v);
STDMATH_EXPORT stdmath_uint2 stdmath_uint2_logical_and(stdmath_uint2 a, stdmath_uint2 b);
STDMATH_EXPORT stdmath_uint2 stdmath_uint2_bitwise_and(stdmath_uint2 a, stdmath_uint2 b);
STDMATH_EXPORT stdmath_uint2 stdmath_uint2_logical_or(stdmath_uint2 a, stdmath_uint2 b);
STDMATH_EXPORT stdmath_uint2 stdmath_uint2_bitwise_or(stdmath_uint2 a, stdmath_uint2 b);
STDMATH_EXPORT stdmath_uint2 stdmath_uint2_bitwise_xor(stdmath_uint2 a, stdmath_uint2 b);
STDMATH_EXPORT stdmath_uint2 stdmath_uint2_shift_left(stdmath_uint2 a, stdmath_uint2 b);
STDMATH_EXPORT stdmath_uint2 stdmath_uint2_shift_right(stdmath_uint2 a, stdmath_uint2 b);
#endif

STDMATH_EXPORT stdmath_bool2 stdmath_uint2_equal_to(stdmath_uint2 a, stdmath_uint2 b);
STDMATH_EXPORT stdmath_bool2 stdmath_uint2_not_equal_to(stdmath_uint2 a, stdmath_uint2 b);
STDMATH_EXPORT stdmath_bool2 stdmath_uint2_less_than(stdmath_uint2 a, stdmath_uint2 b);
STDMATH_EXPORT stdmath_bool2 stdmath_uint2_less_than_or_equal_to(stdmath_uint2 a, stdmath_uint2 b);
STDMATH_EXPORT stdmath_bool2 stdmath_uint2_greater_than(stdmath_uint2 a, stdmath_uint2 b);
STDMATH_EXPORT stdmath_bool2 stdmath_uint2_greater_than_or_equal_to(stdmath_uint2 a, stdmath_uint2 b);

STDMATH_EXPORT uint32_t stdmath_uint2_length_squared(stdmath_uint2 v);
STDMATH_EXPORT uint32_t stdmath_uint2_length(stdmath_uint2 v);
STDMATH_EXPORT uint32_t stdmath_uint2_dot(stdmath_uint2 a, stdmath_uint2 b);
STDMATH_EXPORT uint32_t stdmath_uint2_min_element(stdmath_uint2 v);
STDMATH_EXPORT uint32_t stdmath_uint2_max_element(stdmath_uint2 v);

STDMATH_EXPORT stdmath_uint2 stdmath_uint2_elementwise_transform(stdmath_uint2 v, uint32_t(*func)(uint32_t));
// STDMATH_EXPORT uint32_t stdmath_uint2_reduce_elements(stdmath_uint2 v, uint32_t initial_value, uint32_t(*reducer)(stdmath_uint2, stdmath_uint2));

#if 2 == 3
STDMATH_EXPORT stdmath_uint3 stdmath_uint3_cross(stdmath_uint3 a, stdmath_uint3 b);
#endif

STDMATH_EXPORT stdmath_uint2 stdmath_uint2_min(stdmath_uint2 a, stdmath_uint2 b);
STDMATH_EXPORT stdmath_uint2 stdmath_uint2_max(stdmath_uint2 a, stdmath_uint2 b);
STDMATH_EXPORT stdmath_uint2 stdmath_uint2_normalize(stdmath_uint2 v);
STDMATH_EXPORT stdmath_uint2 stdmath_uint2_lerp(stdmath_uint2 a, stdmath_uint2 b, float t);
STDMATH_EXPORT stdmath_uint2 stdmath_uint2_clamp(stdmath_uint2 a, stdmath_uint2 min, stdmath_uint2 max);
STDMATH_EXPORT stdmath_uint2 stdmath_uint2_reflect(stdmath_uint2 a, stdmath_uint2 b);
STDMATH_EXPORT stdmath_bool2 stdmath_uint2_approximately_equal(stdmath_uint2 a, stdmath_uint2 b);

#if false
STDMATH_EXPORT bool stdmath_bool2_all_of(stdmath_bool2 v);
STDMATH_EXPORT bool stdmath_bool2_any_of(stdmath_bool2 v);
STDMATH_EXPORT bool stdmath_bool2_none_of(stdmath_bool2 v);
STDMATH_EXPORT bool stdmath_bool2_some_of(stdmath_bool2 v);
#endif

#ifndef STDMATH_NO_SWIZZLES
STDMATH_EXPORT STDMATH_INLINE stdmath_uint1 stdmath_uint2_x(stdmath_uint2 v) { return {v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_uint1 stdmath_uint2_x_get(stdmath_uint2* p) { return stdmath_uint2_x(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_uint2 stdmath_uint2_x_set(stdmath_uint2* p, stdmath_uint1 value) { p->x = value.x; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_uint1 stdmath_uint2_y(stdmath_uint2 v) { return {v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_uint1 stdmath_uint2_y_get(stdmath_uint2* p) { return stdmath_uint2_y(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_uint2 stdmath_uint2_y_set(stdmath_uint2* p, stdmath_uint1 value) { p->y = value.x; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_uint2 stdmath_uint2_xx(stdmath_uint2 v) { return {v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_uint2 stdmath_uint2_xx_get(stdmath_uint2* p) { return stdmath_uint2_xx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_uint2 stdmath_uint2_xx_set(stdmath_uint2* p, stdmath_uint2 value) { p->x = value.x; p->x = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_uint2 stdmath_uint2_xy(stdmath_uint2 v) { return {v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_uint2 stdmath_uint2_xy_get(stdmath_uint2* p) { return stdmath_uint2_xy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_uint2 stdmath_uint2_xy_set(stdmath_uint2* p, stdmath_uint2 value) { p->x = value.x; p->y = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_uint2 stdmath_uint2_yx(stdmath_uint2 v) { return {v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_uint2 stdmath_uint2_yx_get(stdmath_uint2* p) { return stdmath_uint2_yx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_uint2 stdmath_uint2_yx_set(stdmath_uint2* p, stdmath_uint2 value) { p->y = value.x; p->x = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_uint2 stdmath_uint2_yy(stdmath_uint2 v) { return {v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_uint2 stdmath_uint2_yy_get(stdmath_uint2* p) { return stdmath_uint2_yy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_uint2 stdmath_uint2_yy_set(stdmath_uint2* p, stdmath_uint2 value) { p->y = value.x; p->y = value.y; return *p; }

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

inline stdmath::uint2 c(stdmath_uint2 c) {
	return (stdmath::uint2&)c;
}
inline stdmath_uint2 c(stdmath::uint2 c) {
	return (stdmath_uint2&)c;
}

#ifdef __cplusplus
extern "C" {
#endif

stdmath_uint2 stdmath_uint2_broadcast(uint32_t all) {
	return c(stdmath::uint2((stdmath::uint2::underlying_type)all));
}

stdmath_uint2 stdmath_uint2_add(stdmath_uint2 a, stdmath_uint2 b) {
	return c(c(a) + c(b));
}
stdmath_uint2 stdmath_uint2_subtract(stdmath_uint2 a, stdmath_uint2 b) {
	return c(c(a) - c(b));
}
stdmath_uint2 stdmath_uint2_negate(stdmath_uint2 v) {
	return c(stdmath::uint2(-(stdmath::vector<uint32_t, 2>)c(v)));
}
stdmath_uint2 stdmath_uint2_multiply(stdmath_uint2 a, stdmath_uint2 b) {
	return c(c(a) * c(b));
}
stdmath_uint2 stdmath_uint2_divide(stdmath_uint2 a, stdmath_uint2 b) {
	return c(c(a) / c(b));
}
stdmath_uint2 stdmath_uint2_scale(stdmath_uint2 v, uint32_t s) {
	return c(c(v) * (stdmath::uint2::underlying_type)s);
}

#if false
stdmath_uint2 stdmath_uint2_modulus(stdmath_uint2 a, stdmath_uint2 b) {
	return c(c(a) % c(b));
}
stdmath_uint2 stdmath_uint2_logical_not(stdmath_uint2 v) {
	return c(!c(v));
}
stdmath_uint2 stdmath_uint2_bitwise_not(stdmath_uint2 v) {
	return c(~c(v));
}
stdmath_uint2 stdmath_uint2_logical_and(stdmath_uint2 a, stdmath_uint2 b) {
	return c(c(a) && c(b));
}
stdmath_uint2 stdmath_uint2_bitwise_and(stdmath_uint2 a, stdmath_uint2 b) {
	return c(c(a) & c(b));
}
stdmath_uint2 stdmath_uint2_logical_or(stdmath_uint2 a, stdmath_uint2 b) {
	return c(c(a) || c(b));
}
stdmath_uint2 stdmath_uint2_bitwise_or(stdmath_uint2 a, stdmath_uint2 b) {
	return c(c(a) | c(b));
}
stdmath_uint2 stdmath_uint2_bitwise_xor(stdmath_uint2 a, stdmath_uint2 b) {
	return c(c(a) ^ c(b));
}
stdmath_uint2 stdmath_uint2_shift_left(stdmath_uint2 a, stdmath_uint2 b) {
	return c(c(a) << c(b));
}
stdmath_uint2 stdmath_uint2_shift_right(stdmath_uint2 a, stdmath_uint2 b) {
	return c(c(a) >> c(b));
}
#endif

stdmath_bool2 stdmath_uint2_equal_to(stdmath_uint2 a, stdmath_uint2 b) {
	return c(c(a) == c(b));
}
stdmath_bool2 stdmath_uint2_not_equal_to(stdmath_uint2 a, stdmath_uint2 b) {
	return c(c(a) != c(b));
}
stdmath_bool2 stdmath_uint2_less_than(stdmath_uint2 a, stdmath_uint2 b) {
	return c(c(a) < c(b));
}
stdmath_bool2 stdmath_uint2_less_than_or_equal_to(stdmath_uint2 a, stdmath_uint2 b) {
	return c(c(a) <= c(b));
}
stdmath_bool2 stdmath_uint2_greater_than(stdmath_uint2 a, stdmath_uint2 b) {
	return c(c(a) > c(b));
}
stdmath_bool2 stdmath_uint2_greater_than_or_equal_to(stdmath_uint2 a, stdmath_uint2 b) {
	return c(c(a) >= c(b));
}

uint32_t stdmath_uint2_length_squared(stdmath_uint2 v)  {
	return (uint32_t)c(v).length_squared();
}
uint32_t stdmath_uint2_length(stdmath_uint2 v)  {
	return (uint32_t)c(v).length();
}
uint32_t stdmath_uint2_dot(stdmath_uint2 a, stdmath_uint2 b)  {
	return (uint32_t)dot(c(a), c(b));
}
uint32_t stdmath_uint2_min_element(stdmath_uint2 v)  {
	return (uint32_t)c(v).min_element();
}
uint32_t stdmath_uint2_max_element(stdmath_uint2 v)  {
	return (uint32_t)c(v).max_element();
}

stdmath_uint2 stdmath_uint2_elementwise_transform(stdmath_uint2 v, uint32_t(*func)(uint32_t)) {
	return c(c(v).elementwise_transform(func));
}
// uint32_t stdmath_uint2_reduce_elements(stdmath_uint2 v, uint32_t initial_value, uint32_t(*reducer)(stdmath_uint2, stdmath_uint2)) {
// 	return c(v).reduce_elements(initial_value, reducer);
// }

#if 2 == 3
stdmath_uint2 stdmath_uint2_cross(stdmath_uint2 a, stdmath_uint2 b) {
	return c(cross(c(a), c(b)));
}
#endif

stdmath_uint2 stdmath_uint2_min(stdmath_uint2 a, stdmath_uint2 b) {
	return c(min(c(a), c(b)));
}
stdmath_uint2 stdmath_uint2_max(stdmath_uint2 a, stdmath_uint2 b) {
	return c(max(c(a), c(b)));
}
stdmath_uint2 stdmath_uint2_normalize(stdmath_uint2 v) {
	return c(normalize(c(v)));
}
stdmath_uint2 stdmath_uint2_lerp(stdmath_uint2 a, stdmath_uint2 b, float t) {
	return c(lerp(c(a), c(b), t));
}
stdmath_uint2 stdmath_uint2_clamp(stdmath_uint2 a, stdmath_uint2 min, stdmath_uint2 max) {
	return c(clamp(c(a), c(min), c(max)));
}
stdmath_uint2 stdmath_uint2_reflect(stdmath_uint2 a, stdmath_uint2 b) {
	return c(reflect(c(a), c(b)));
}
stdmath_bool2 stdmath_uint2_approximately_equal(stdmath_uint2 a, stdmath_uint2 b) {
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

#ifdef __cplusplus
} // extern "C"
#endif

#endif // STDMATH_IMPLEMENTATION

#endif // __STDMATH_uint32_t2_H__