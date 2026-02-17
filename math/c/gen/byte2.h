#ifndef __STDMATH_uint8_t2_H__
#define __STDMATH_uint8_t2_H__

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
#include "byte1.h"
#elif 2 == 3
#include "byte2.h"
#include "byte1.h"
#elif 2 == 4
#include "byte3.h"
#include "byte2.h"
#include "byte1.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if 2 == 1
STDMATH_EXPORT union stdmath_byte1 {
	struct {
		uint8_t x;
	};
	uint8_t data[1];
};
#elif 2 == 2
STDMATH_EXPORT union stdmath_byte2 {
	struct {
		uint8_t x, y;
	};
	struct {
		uint8_t u, v;
	};
	uint8_t data[2];
};
#elif 2 == 3
STDMATH_EXPORT union stdmath_byte3 {
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
#elif 2 == 4
STDMATH_EXPORT union stdmath_byte4 {
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

STDMATH_EXPORT stdmath_byte2 stdmath_byte2_broadcast(uint8_t all);

STDMATH_EXPORT stdmath_byte2 stdmath_byte2_add(stdmath_byte2 a, stdmath_byte2 b);
STDMATH_EXPORT stdmath_byte2 stdmath_byte2_subtract(stdmath_byte2 a, stdmath_byte2 b);
STDMATH_EXPORT stdmath_byte2 stdmath_byte2_negate(stdmath_byte2 v);
STDMATH_EXPORT stdmath_byte2 stdmath_byte2_multiply(stdmath_byte2 a, stdmath_byte2 b);
STDMATH_EXPORT stdmath_byte2 stdmath_byte2_divide(stdmath_byte2 a, stdmath_byte2 b);
STDMATH_EXPORT stdmath_byte2 stdmath_byte2_scale(stdmath_byte2 v, uint8_t s);

#if false
STDMATH_EXPORT stdmath_byte2 stdmath_byte2_modulus(stdmath_byte2 a, stdmath_byte2 b);
STDMATH_EXPORT stdmath_byte2 stdmath_byte2_logical_not(stdmath_byte2 v);
STDMATH_EXPORT stdmath_byte2 stdmath_byte2_bitwise_not(stdmath_byte2 v);
STDMATH_EXPORT stdmath_byte2 stdmath_byte2_logical_and(stdmath_byte2 a, stdmath_byte2 b);
STDMATH_EXPORT stdmath_byte2 stdmath_byte2_bitwise_and(stdmath_byte2 a, stdmath_byte2 b);
STDMATH_EXPORT stdmath_byte2 stdmath_byte2_logical_or(stdmath_byte2 a, stdmath_byte2 b);
STDMATH_EXPORT stdmath_byte2 stdmath_byte2_bitwise_or(stdmath_byte2 a, stdmath_byte2 b);
STDMATH_EXPORT stdmath_byte2 stdmath_byte2_bitwise_xor(stdmath_byte2 a, stdmath_byte2 b);
STDMATH_EXPORT stdmath_byte2 stdmath_byte2_shift_left(stdmath_byte2 a, stdmath_byte2 b);
STDMATH_EXPORT stdmath_byte2 stdmath_byte2_shift_right(stdmath_byte2 a, stdmath_byte2 b);
#endif

STDMATH_EXPORT stdmath_bool2 stdmath_byte2_equal_to(stdmath_byte2 a, stdmath_byte2 b);
STDMATH_EXPORT stdmath_bool2 stdmath_byte2_not_equal_to(stdmath_byte2 a, stdmath_byte2 b);
STDMATH_EXPORT stdmath_bool2 stdmath_byte2_less_than(stdmath_byte2 a, stdmath_byte2 b);
STDMATH_EXPORT stdmath_bool2 stdmath_byte2_less_than_or_equal_to(stdmath_byte2 a, stdmath_byte2 b);
STDMATH_EXPORT stdmath_bool2 stdmath_byte2_greater_than(stdmath_byte2 a, stdmath_byte2 b);
STDMATH_EXPORT stdmath_bool2 stdmath_byte2_greater_than_or_equal_to(stdmath_byte2 a, stdmath_byte2 b);

STDMATH_EXPORT uint8_t stdmath_byte2_length_squared(stdmath_byte2 v);
STDMATH_EXPORT uint8_t stdmath_byte2_length(stdmath_byte2 v);
STDMATH_EXPORT uint8_t stdmath_byte2_dot(stdmath_byte2 a, stdmath_byte2 b);
STDMATH_EXPORT uint8_t stdmath_byte2_min_element(stdmath_byte2 v);
STDMATH_EXPORT uint8_t stdmath_byte2_max_element(stdmath_byte2 v);

STDMATH_EXPORT stdmath_byte2 stdmath_byte2_elementwise_transform(stdmath_byte2 v, uint8_t(*func)(uint8_t));
// STDMATH_EXPORT uint8_t stdmath_byte2_reduce_elements(stdmath_byte2 v, uint8_t initial_value, uint8_t(*reducer)(stdmath_byte2, stdmath_byte2));

#if 2 == 3
STDMATH_EXPORT stdmath_byte3 stdmath_byte3_cross(stdmath_byte3 a, stdmath_byte3 b);
#endif

STDMATH_EXPORT stdmath_byte2 stdmath_byte2_min(stdmath_byte2 a, stdmath_byte2 b);
STDMATH_EXPORT stdmath_byte2 stdmath_byte2_max(stdmath_byte2 a, stdmath_byte2 b);
STDMATH_EXPORT stdmath_byte2 stdmath_byte2_normalize(stdmath_byte2 v);
STDMATH_EXPORT stdmath_byte2 stdmath_byte2_lerp(stdmath_byte2 a, stdmath_byte2 b, float t);
STDMATH_EXPORT stdmath_byte2 stdmath_byte2_clamp(stdmath_byte2 a, stdmath_byte2 min, stdmath_byte2 max);
STDMATH_EXPORT stdmath_byte2 stdmath_byte2_reflect(stdmath_byte2 a, stdmath_byte2 b);
STDMATH_EXPORT stdmath_bool2 stdmath_byte2_approximately_equal(stdmath_byte2 a, stdmath_byte2 b);

#if false
STDMATH_EXPORT bool stdmath_bool2_all_of(stdmath_bool2 v);
STDMATH_EXPORT bool stdmath_bool2_any_of(stdmath_bool2 v);
STDMATH_EXPORT bool stdmath_bool2_none_of(stdmath_bool2 v);
STDMATH_EXPORT bool stdmath_bool2_some_of(stdmath_bool2 v);
#endif

#ifndef STDMATH_NO_SWIZZLES
STDMATH_EXPORT STDMATH_INLINE stdmath_byte1 stdmath_byte2_x(stdmath_byte2 v) { return {v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte1 stdmath_byte2_x_get(stdmath_byte2* p) { return stdmath_byte2_x(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte2 stdmath_byte2_x_set(stdmath_byte2* p, stdmath_byte1 value) { p->x = value.x; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte1 stdmath_byte2_y(stdmath_byte2 v) { return {v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte1 stdmath_byte2_y_get(stdmath_byte2* p) { return stdmath_byte2_y(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte2 stdmath_byte2_y_set(stdmath_byte2* p, stdmath_byte1 value) { p->y = value.x; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte2 stdmath_byte2_xx(stdmath_byte2 v) { return {v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte2 stdmath_byte2_xx_get(stdmath_byte2* p) { return stdmath_byte2_xx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte2 stdmath_byte2_xx_set(stdmath_byte2* p, stdmath_byte2 value) { p->x = value.x; p->x = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte2 stdmath_byte2_xy(stdmath_byte2 v) { return {v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte2 stdmath_byte2_xy_get(stdmath_byte2* p) { return stdmath_byte2_xy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte2 stdmath_byte2_xy_set(stdmath_byte2* p, stdmath_byte2 value) { p->x = value.x; p->y = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte2 stdmath_byte2_yx(stdmath_byte2 v) { return {v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte2 stdmath_byte2_yx_get(stdmath_byte2* p) { return stdmath_byte2_yx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte2 stdmath_byte2_yx_set(stdmath_byte2* p, stdmath_byte2 value) { p->y = value.x; p->x = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte2 stdmath_byte2_yy(stdmath_byte2 v) { return {v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte2 stdmath_byte2_yy_get(stdmath_byte2* p) { return stdmath_byte2_yy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_byte2 stdmath_byte2_yy_set(stdmath_byte2* p, stdmath_byte2 value) { p->y = value.x; p->y = value.y; return *p; }

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

inline stdmath::byte2 c(stdmath_byte2 c) {
	return (stdmath::byte2&)c;
}
inline stdmath_byte2 c(stdmath::byte2 c) {
	return (stdmath_byte2&)c;
}

#ifdef __cplusplus
extern "C" {
#endif

stdmath_byte2 stdmath_byte2_broadcast(uint8_t all) {
	return c(stdmath::byte2((stdmath::byte2::underlying_type)all));
}

stdmath_byte2 stdmath_byte2_add(stdmath_byte2 a, stdmath_byte2 b) {
	return c(c(a) + c(b));
}
stdmath_byte2 stdmath_byte2_subtract(stdmath_byte2 a, stdmath_byte2 b) {
	return c(c(a) - c(b));
}
stdmath_byte2 stdmath_byte2_negate(stdmath_byte2 v) {
	return c(stdmath::byte2(-(stdmath::vector<uint8_t, 2>)c(v)));
}
stdmath_byte2 stdmath_byte2_multiply(stdmath_byte2 a, stdmath_byte2 b) {
	return c(c(a) * c(b));
}
stdmath_byte2 stdmath_byte2_divide(stdmath_byte2 a, stdmath_byte2 b) {
	return c(c(a) / c(b));
}
stdmath_byte2 stdmath_byte2_scale(stdmath_byte2 v, uint8_t s) {
	return c(c(v) * (stdmath::byte2::underlying_type)s);
}

#if false
stdmath_byte2 stdmath_byte2_modulus(stdmath_byte2 a, stdmath_byte2 b) {
	return c(c(a) % c(b));
}
stdmath_byte2 stdmath_byte2_logical_not(stdmath_byte2 v) {
	return c(!c(v));
}
stdmath_byte2 stdmath_byte2_bitwise_not(stdmath_byte2 v) {
	return c(~c(v));
}
stdmath_byte2 stdmath_byte2_logical_and(stdmath_byte2 a, stdmath_byte2 b) {
	return c(c(a) && c(b));
}
stdmath_byte2 stdmath_byte2_bitwise_and(stdmath_byte2 a, stdmath_byte2 b) {
	return c(c(a) & c(b));
}
stdmath_byte2 stdmath_byte2_logical_or(stdmath_byte2 a, stdmath_byte2 b) {
	return c(c(a) || c(b));
}
stdmath_byte2 stdmath_byte2_bitwise_or(stdmath_byte2 a, stdmath_byte2 b) {
	return c(c(a) | c(b));
}
stdmath_byte2 stdmath_byte2_bitwise_xor(stdmath_byte2 a, stdmath_byte2 b) {
	return c(c(a) ^ c(b));
}
stdmath_byte2 stdmath_byte2_shift_left(stdmath_byte2 a, stdmath_byte2 b) {
	return c(c(a) << c(b));
}
stdmath_byte2 stdmath_byte2_shift_right(stdmath_byte2 a, stdmath_byte2 b) {
	return c(c(a) >> c(b));
}
#endif

stdmath_bool2 stdmath_byte2_equal_to(stdmath_byte2 a, stdmath_byte2 b) {
	return c(c(a) == c(b));
}
stdmath_bool2 stdmath_byte2_not_equal_to(stdmath_byte2 a, stdmath_byte2 b) {
	return c(c(a) != c(b));
}
stdmath_bool2 stdmath_byte2_less_than(stdmath_byte2 a, stdmath_byte2 b) {
	return c(c(a) < c(b));
}
stdmath_bool2 stdmath_byte2_less_than_or_equal_to(stdmath_byte2 a, stdmath_byte2 b) {
	return c(c(a) <= c(b));
}
stdmath_bool2 stdmath_byte2_greater_than(stdmath_byte2 a, stdmath_byte2 b) {
	return c(c(a) > c(b));
}
stdmath_bool2 stdmath_byte2_greater_than_or_equal_to(stdmath_byte2 a, stdmath_byte2 b) {
	return c(c(a) >= c(b));
}

uint8_t stdmath_byte2_length_squared(stdmath_byte2 v)  {
	return (uint8_t)c(v).length_squared();
}
uint8_t stdmath_byte2_length(stdmath_byte2 v)  {
	return (uint8_t)c(v).length();
}
uint8_t stdmath_byte2_dot(stdmath_byte2 a, stdmath_byte2 b)  {
	return (uint8_t)dot(c(a), c(b));
}
uint8_t stdmath_byte2_min_element(stdmath_byte2 v)  {
	return (uint8_t)c(v).min_element();
}
uint8_t stdmath_byte2_max_element(stdmath_byte2 v)  {
	return (uint8_t)c(v).max_element();
}

stdmath_byte2 stdmath_byte2_elementwise_transform(stdmath_byte2 v, uint8_t(*func)(uint8_t)) {
	return c(c(v).elementwise_transform(func));
}
// uint8_t stdmath_byte2_reduce_elements(stdmath_byte2 v, uint8_t initial_value, uint8_t(*reducer)(stdmath_byte2, stdmath_byte2)) {
// 	return c(v).reduce_elements(initial_value, reducer);
// }

#if 2 == 3
stdmath_byte2 stdmath_byte2_cross(stdmath_byte2 a, stdmath_byte2 b) {
	return c(cross(c(a), c(b)));
}
#endif

stdmath_byte2 stdmath_byte2_min(stdmath_byte2 a, stdmath_byte2 b) {
	return c(min(c(a), c(b)));
}
stdmath_byte2 stdmath_byte2_max(stdmath_byte2 a, stdmath_byte2 b) {
	return c(max(c(a), c(b)));
}
stdmath_byte2 stdmath_byte2_normalize(stdmath_byte2 v) {
	return c(normalize(c(v)));
}
stdmath_byte2 stdmath_byte2_lerp(stdmath_byte2 a, stdmath_byte2 b, float t) {
	return c(lerp(c(a), c(b), t));
}
stdmath_byte2 stdmath_byte2_clamp(stdmath_byte2 a, stdmath_byte2 min, stdmath_byte2 max) {
	return c(clamp(c(a), c(min), c(max)));
}
stdmath_byte2 stdmath_byte2_reflect(stdmath_byte2 a, stdmath_byte2 b) {
	return c(reflect(c(a), c(b)));
}
stdmath_bool2 stdmath_byte2_approximately_equal(stdmath_byte2 a, stdmath_byte2 b) {
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

#endif // __STDMATH_uint8_t2_H__