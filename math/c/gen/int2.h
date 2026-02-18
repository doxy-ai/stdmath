#ifndef __STDMATH_int32_t2_H__
#define __STDMATH_int32_t2_H__

#ifndef STDMATH_MODULE
#include <stdint.h>
#include <assert.h>
#endif
#include "../maybe_export.h"

#if false
#include "radian.h"
#endif
#if false
#include "degree.h"
#endif

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
#include "int1.h"
#elif 2 == 3
#include "int2.h"
#include "int1.h"
#elif 2 == 4
#include "int3.h"
#include "int2.h"
#include "int1.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if 2 == 1
STDMATH_EXPORT union stdmath_int1 {
	struct {
		int32_t x;
	};
	int32_t data[1];
};
#elif 2 == 2
STDMATH_EXPORT union stdmath_int2 {
	struct {
		int32_t x, y;
	};
	struct {
		int32_t u, v;
	};
	int32_t data[2];
};
#elif 2 == 3
STDMATH_EXPORT union stdmath_int3 {
	struct {
		int32_t x, y, z;
	};
	struct {
		int32_t r, g, b;
	};
	struct {
		int32_t h, s, v;
	};
	int32_t data[4]; // int3s are aligned as if they were int4s
};
#elif 2 == 4
STDMATH_EXPORT union stdmath_int4 {
	struct {
		int32_t x, y, z, w;
	};
	struct {
		int32_t r, g, b, a;
	};
	struct {
		int32_t h, s, v;
	};
	int32_t data[4];
};
#endif

STDMATH_EXPORT stdmath_int2 stdmath_int2_broadcast(int32_t all);

STDMATH_EXPORT stdmath_int2 stdmath_int2_add(stdmath_int2 a, stdmath_int2 b);
STDMATH_EXPORT stdmath_int2 stdmath_int2_subtract(stdmath_int2 a, stdmath_int2 b);
STDMATH_EXPORT stdmath_int2 stdmath_int2_negate(stdmath_int2 v);
STDMATH_EXPORT stdmath_int2 stdmath_int2_multiply(stdmath_int2 a, stdmath_int2 b);
STDMATH_EXPORT stdmath_int2 stdmath_int2_divide(stdmath_int2 a, stdmath_int2 b);
STDMATH_EXPORT stdmath_int2 stdmath_int2_scale(stdmath_int2 v, int32_t s);

#if false
STDMATH_EXPORT stdmath_int2 stdmath_int2_modulus(stdmath_int2 a, stdmath_int2 b);
STDMATH_EXPORT stdmath_int2 stdmath_int2_logical_not(stdmath_int2 v);
STDMATH_EXPORT stdmath_int2 stdmath_int2_bitwise_not(stdmath_int2 v);
STDMATH_EXPORT stdmath_int2 stdmath_int2_logical_and(stdmath_int2 a, stdmath_int2 b);
STDMATH_EXPORT stdmath_int2 stdmath_int2_bitwise_and(stdmath_int2 a, stdmath_int2 b);
STDMATH_EXPORT stdmath_int2 stdmath_int2_logical_or(stdmath_int2 a, stdmath_int2 b);
STDMATH_EXPORT stdmath_int2 stdmath_int2_bitwise_or(stdmath_int2 a, stdmath_int2 b);
STDMATH_EXPORT stdmath_int2 stdmath_int2_bitwise_xor(stdmath_int2 a, stdmath_int2 b);
STDMATH_EXPORT stdmath_int2 stdmath_int2_shift_left(stdmath_int2 a, stdmath_int2 b);
STDMATH_EXPORT stdmath_int2 stdmath_int2_shift_right(stdmath_int2 a, stdmath_int2 b);
#endif

STDMATH_EXPORT stdmath_bool2 stdmath_int2_equal_to(stdmath_int2 a, stdmath_int2 b);
STDMATH_EXPORT stdmath_bool2 stdmath_int2_not_equal_to(stdmath_int2 a, stdmath_int2 b);
STDMATH_EXPORT stdmath_bool2 stdmath_int2_less_than(stdmath_int2 a, stdmath_int2 b);
STDMATH_EXPORT stdmath_bool2 stdmath_int2_less_than_or_equal_to(stdmath_int2 a, stdmath_int2 b);
STDMATH_EXPORT stdmath_bool2 stdmath_int2_greater_than(stdmath_int2 a, stdmath_int2 b);
STDMATH_EXPORT stdmath_bool2 stdmath_int2_greater_than_or_equal_to(stdmath_int2 a, stdmath_int2 b);

STDMATH_EXPORT int32_t stdmath_int2_length_squared(stdmath_int2 v);
STDMATH_EXPORT int32_t stdmath_int2_length(stdmath_int2 v);
STDMATH_EXPORT int32_t stdmath_int2_dot(stdmath_int2 a, stdmath_int2 b);
STDMATH_EXPORT int32_t stdmath_int2_min_element(stdmath_int2 v);
STDMATH_EXPORT int32_t stdmath_int2_max_element(stdmath_int2 v);

// STDMATH_EXPORT stdmath_int2 stdmath_int2_elementwise_transform(stdmath_int2 v, int32_t(*func)(int32_t));
// STDMATH_EXPORT int32_t stdmath_int2_reduce_elements(stdmath_int2 v, int32_t initial_value, int32_t(*reducer)(stdmath_int2, stdmath_int2));

#if 2 == 3
STDMATH_EXPORT stdmath_int3 stdmath_int3_cross(stdmath_int3 a, stdmath_int3 b);
#endif

STDMATH_EXPORT stdmath_int2 stdmath_int2_min(stdmath_int2 a, stdmath_int2 b);
STDMATH_EXPORT stdmath_int2 stdmath_int2_max(stdmath_int2 a, stdmath_int2 b);
STDMATH_EXPORT stdmath_int2 stdmath_int2_normalize(stdmath_int2 v);
STDMATH_EXPORT stdmath_int2 stdmath_int2_lerp(stdmath_int2 a, stdmath_int2 b, float t);
STDMATH_EXPORT stdmath_int2 stdmath_int2_clamp(stdmath_int2 a, stdmath_int2 min, stdmath_int2 max);
STDMATH_EXPORT stdmath_int2 stdmath_int2_reflect(stdmath_int2 a, stdmath_int2 b);
STDMATH_EXPORT stdmath_bool2 stdmath_int2_approximately_equal(stdmath_int2 a, stdmath_int2 b);

#if false
STDMATH_EXPORT bool stdmath_bool2_all_of(stdmath_bool2 v);
STDMATH_EXPORT bool stdmath_bool2_any_of(stdmath_bool2 v);
STDMATH_EXPORT bool stdmath_bool2_none_of(stdmath_bool2 v);
STDMATH_EXPORT bool stdmath_bool2_some_of(stdmath_bool2 v);
#endif

#ifndef STDMATH_NO_SWIZZLES
STDMATH_EXPORT STDMATH_INLINE stdmath_int1 stdmath_int2_x(stdmath_int2 v) { return {v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int1 stdmath_int2_x_get(stdmath_int2* p) { return stdmath_int2_x(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int2_x_set(stdmath_int2* p, stdmath_int1 value) { p->x = value.x; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int1 stdmath_int2_y(stdmath_int2 v) { return {v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int1 stdmath_int2_y_get(stdmath_int2* p) { return stdmath_int2_y(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int2_y_set(stdmath_int2* p, stdmath_int1 value) { p->y = value.x; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int2_xx(stdmath_int2 v) { return {v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int2_xx_get(stdmath_int2* p) { return stdmath_int2_xx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int2_xx_set(stdmath_int2* p, stdmath_int2 value) { p->x = value.x; p->x = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int2_xy(stdmath_int2 v) { return {v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int2_xy_get(stdmath_int2* p) { return stdmath_int2_xy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int2_xy_set(stdmath_int2* p, stdmath_int2 value) { p->x = value.x; p->y = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int2_yx(stdmath_int2 v) { return {v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int2_yx_get(stdmath_int2* p) { return stdmath_int2_yx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int2_yx_set(stdmath_int2* p, stdmath_int2 value) { p->y = value.x; p->x = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int2_yy(stdmath_int2 v) { return {v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int2_yy_get(stdmath_int2* p) { return stdmath_int2_yy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_int2 stdmath_int2_yy_set(stdmath_int2* p, stdmath_int2 value) { p->y = value.x; p->y = value.y; return *p; }

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

inline stdmath::int2 c(stdmath_int2 c) {
	return (stdmath::int2&)c;
}
inline stdmath_int2 c(stdmath::int2 c) {
	return (stdmath_int2&)c;
}

#ifdef __cplusplus
extern "C" {
#endif

stdmath_int2 stdmath_int2_broadcast(int32_t all) {
	return c(stdmath::int2((stdmath::int2::underlying_type&)all));
}

stdmath_int2 stdmath_int2_add(stdmath_int2 a, stdmath_int2 b) {
	return c(c(a) + c(b));
}
stdmath_int2 stdmath_int2_subtract(stdmath_int2 a, stdmath_int2 b) {
	return c(c(a) - c(b));
}
stdmath_int2 stdmath_int2_negate(stdmath_int2 v) {
#if !false && !false
	return c(stdmath::int2(-(stdmath::vector<int32_t, 2>)c(v)));
#else
	assert(false && "TODO: Why can't we use - on vector<degree/radian, N>?");
#endif
}
stdmath_int2 stdmath_int2_multiply(stdmath_int2 a, stdmath_int2 b) {
	return c(c(a) * c(b));
}
stdmath_int2 stdmath_int2_divide(stdmath_int2 a, stdmath_int2 b) {
	return c(c(a) / c(b));
}
stdmath_int2 stdmath_int2_scale(stdmath_int2 v, int32_t s) {
	return c(c(v) * (stdmath::int2::underlying_type&)s);
}

#if false
stdmath_int2 stdmath_int2_modulus(stdmath_int2 a, stdmath_int2 b) {
	return c(c(a) % c(b));
}
stdmath_int2 stdmath_int2_logical_not(stdmath_int2 v) {
	return c(!c(v));
}
stdmath_int2 stdmath_int2_bitwise_not(stdmath_int2 v) {
	return c(~c(v));
}
stdmath_int2 stdmath_int2_logical_and(stdmath_int2 a, stdmath_int2 b) {
	return c(c(a) && c(b));
}
stdmath_int2 stdmath_int2_bitwise_and(stdmath_int2 a, stdmath_int2 b) {
	return c(c(a) & c(b));
}
stdmath_int2 stdmath_int2_logical_or(stdmath_int2 a, stdmath_int2 b) {
	return c(c(a) || c(b));
}
stdmath_int2 stdmath_int2_bitwise_or(stdmath_int2 a, stdmath_int2 b) {
	return c(c(a) | c(b));
}
stdmath_int2 stdmath_int2_bitwise_xor(stdmath_int2 a, stdmath_int2 b) {
	return c(c(a) ^ c(b));
}
stdmath_int2 stdmath_int2_shift_left(stdmath_int2 a, stdmath_int2 b) {
	return c(c(a) << c(b));
}
stdmath_int2 stdmath_int2_shift_right(stdmath_int2 a, stdmath_int2 b) {
	return c(c(a) >> c(b));
}
#endif

stdmath_bool2 stdmath_int2_equal_to(stdmath_int2 a, stdmath_int2 b) {
	return c(c(a) == c(b));
}
stdmath_bool2 stdmath_int2_not_equal_to(stdmath_int2 a, stdmath_int2 b) {
	return c(c(a) != c(b));
}
stdmath_bool2 stdmath_int2_less_than(stdmath_int2 a, stdmath_int2 b) {
	return c(c(a) < c(b));
}
stdmath_bool2 stdmath_int2_less_than_or_equal_to(stdmath_int2 a, stdmath_int2 b) {
	return c(c(a) <= c(b));
}
stdmath_bool2 stdmath_int2_greater_than(stdmath_int2 a, stdmath_int2 b) {
	return c(c(a) > c(b));
}
stdmath_bool2 stdmath_int2_greater_than_or_equal_to(stdmath_int2 a, stdmath_int2 b) {
	return c(c(a) >= c(b));
}

int32_t stdmath_int2_length_squared(stdmath_int2 v)  {
	auto out = c(v).length_squared();
	return (int32_t&)out;
}
int32_t stdmath_int2_length(stdmath_int2 v)  {
	auto out = c(v).length();
	return (int32_t&)out;
}
int32_t stdmath_int2_dot(stdmath_int2 a, stdmath_int2 b)  {
	auto out = dot(c(a), c(b));
	return (int32_t&)out;
}
int32_t stdmath_int2_min_element(stdmath_int2 v)  {
	auto out = c(v).min_element();
	return (int32_t&)out;
}
int32_t stdmath_int2_max_element(stdmath_int2 v)  {
	auto out = c(v).max_element();
	return (int32_t&)out;
}

// stdmath_int2 stdmath_int2_elementwise_transform(stdmath_int2 v, int32_t(*func)(int32_t)) {
// 	return c(c(v).elementwise_transform(func));
// }
// int32_t stdmath_int2_reduce_elements(stdmath_int2 v, int32_t initial_value, int32_t(*reducer)(stdmath_int2, stdmath_int2)) {
// 	return c(v).reduce_elements(initial_value, reducer);
// }

#if 2 == 3
stdmath_int2 stdmath_int2_cross(stdmath_int2 a, stdmath_int2 b) {
	return c(cross(c(a), c(b)));
}
#endif

stdmath_int2 stdmath_int2_min(stdmath_int2 a, stdmath_int2 b) {
	return c(min(c(a), c(b)));
}
stdmath_int2 stdmath_int2_max(stdmath_int2 a, stdmath_int2 b) {
	return c(max(c(a), c(b)));
}
stdmath_int2 stdmath_int2_normalize(stdmath_int2 v) {
	return c(normalize(c(v)));
}
stdmath_int2 stdmath_int2_lerp(stdmath_int2 a, stdmath_int2 b, float t) {
	return c(lerp(c(a), c(b), t));
}
stdmath_int2 stdmath_int2_clamp(stdmath_int2 a, stdmath_int2 min, stdmath_int2 max) {
	return c(clamp(c(a), c(min), c(max)));
}
stdmath_int2 stdmath_int2_reflect(stdmath_int2 a, stdmath_int2 b) {
	return c(reflect(c(a), c(b)));
}
stdmath_bool2 stdmath_int2_approximately_equal(stdmath_int2 a, stdmath_int2 b) {
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

#endif // __STDMATH_int32_t2_H__