#ifndef __STDMATH_stdmath_radian2_H__
#define __STDMATH_stdmath_radian2_H__

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
#include "radian1.h"
#elif 2 == 3
#include "radian2.h"
#include "radian1.h"
#elif 2 == 4
#include "radian3.h"
#include "radian2.h"
#include "radian1.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if 2 == 1
STDMATH_EXPORT union stdmath_radian1 {
	struct {
		stdmath_radian x;
	};
	stdmath_radian data[1];
};
#elif 2 == 2
STDMATH_EXPORT union stdmath_radian2 {
	struct {
		stdmath_radian x, y;
	};
	struct {
		stdmath_radian u, v;
	};
	stdmath_radian data[2];
};
#elif 2 == 3
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
#elif 2 == 4
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

STDMATH_EXPORT stdmath_radian2 stdmath_radian2_broadcast(stdmath_radian all);

STDMATH_EXPORT stdmath_radian2 stdmath_radian2_add(stdmath_radian2 a, stdmath_radian2 b);
STDMATH_EXPORT stdmath_radian2 stdmath_radian2_subtract(stdmath_radian2 a, stdmath_radian2 b);
STDMATH_EXPORT stdmath_radian2 stdmath_radian2_negate(stdmath_radian2 v);
STDMATH_EXPORT stdmath_radian2 stdmath_radian2_multiply(stdmath_radian2 a, stdmath_radian2 b);
STDMATH_EXPORT stdmath_radian2 stdmath_radian2_divide(stdmath_radian2 a, stdmath_radian2 b);
STDMATH_EXPORT stdmath_radian2 stdmath_radian2_scale(stdmath_radian2 v, stdmath_radian s);

#if false
STDMATH_EXPORT stdmath_radian2 stdmath_radian2_modulus(stdmath_radian2 a, stdmath_radian2 b);
STDMATH_EXPORT stdmath_radian2 stdmath_radian2_logical_not(stdmath_radian2 v);
STDMATH_EXPORT stdmath_radian2 stdmath_radian2_bitwise_not(stdmath_radian2 v);
STDMATH_EXPORT stdmath_radian2 stdmath_radian2_logical_and(stdmath_radian2 a, stdmath_radian2 b);
STDMATH_EXPORT stdmath_radian2 stdmath_radian2_bitwise_and(stdmath_radian2 a, stdmath_radian2 b);
STDMATH_EXPORT stdmath_radian2 stdmath_radian2_logical_or(stdmath_radian2 a, stdmath_radian2 b);
STDMATH_EXPORT stdmath_radian2 stdmath_radian2_bitwise_or(stdmath_radian2 a, stdmath_radian2 b);
STDMATH_EXPORT stdmath_radian2 stdmath_radian2_bitwise_xor(stdmath_radian2 a, stdmath_radian2 b);
STDMATH_EXPORT stdmath_radian2 stdmath_radian2_shift_left(stdmath_radian2 a, stdmath_radian2 b);
STDMATH_EXPORT stdmath_radian2 stdmath_radian2_shift_right(stdmath_radian2 a, stdmath_radian2 b);
#endif

STDMATH_EXPORT stdmath_bool2 stdmath_radian2_equal_to(stdmath_radian2 a, stdmath_radian2 b);
STDMATH_EXPORT stdmath_bool2 stdmath_radian2_not_equal_to(stdmath_radian2 a, stdmath_radian2 b);
STDMATH_EXPORT stdmath_bool2 stdmath_radian2_less_than(stdmath_radian2 a, stdmath_radian2 b);
STDMATH_EXPORT stdmath_bool2 stdmath_radian2_less_than_or_equal_to(stdmath_radian2 a, stdmath_radian2 b);
STDMATH_EXPORT stdmath_bool2 stdmath_radian2_greater_than(stdmath_radian2 a, stdmath_radian2 b);
STDMATH_EXPORT stdmath_bool2 stdmath_radian2_greater_than_or_equal_to(stdmath_radian2 a, stdmath_radian2 b);

STDMATH_EXPORT stdmath_radian stdmath_radian2_length_squared(stdmath_radian2 v);
STDMATH_EXPORT stdmath_radian stdmath_radian2_length(stdmath_radian2 v);
STDMATH_EXPORT stdmath_radian stdmath_radian2_dot(stdmath_radian2 a, stdmath_radian2 b);
STDMATH_EXPORT stdmath_radian stdmath_radian2_min_element(stdmath_radian2 v);
STDMATH_EXPORT stdmath_radian stdmath_radian2_max_element(stdmath_radian2 v);

// STDMATH_EXPORT stdmath_radian2 stdmath_radian2_elementwise_transform(stdmath_radian2 v, stdmath_radian(*func)(stdmath_radian));
// STDMATH_EXPORT stdmath_radian stdmath_radian2_reduce_elements(stdmath_radian2 v, stdmath_radian initial_value, stdmath_radian(*reducer)(stdmath_radian2, stdmath_radian2));

#if 2 == 3
STDMATH_EXPORT stdmath_radian3 stdmath_radian3_cross(stdmath_radian3 a, stdmath_radian3 b);
#endif

STDMATH_EXPORT stdmath_radian2 stdmath_radian2_min(stdmath_radian2 a, stdmath_radian2 b);
STDMATH_EXPORT stdmath_radian2 stdmath_radian2_max(stdmath_radian2 a, stdmath_radian2 b);
STDMATH_EXPORT stdmath_radian2 stdmath_radian2_normalize(stdmath_radian2 v);
STDMATH_EXPORT stdmath_radian2 stdmath_radian2_lerp(stdmath_radian2 a, stdmath_radian2 b, float t);
STDMATH_EXPORT stdmath_radian2 stdmath_radian2_clamp(stdmath_radian2 a, stdmath_radian2 min, stdmath_radian2 max);
STDMATH_EXPORT stdmath_radian2 stdmath_radian2_reflect(stdmath_radian2 a, stdmath_radian2 b);
STDMATH_EXPORT stdmath_bool2 stdmath_radian2_approximately_equal(stdmath_radian2 a, stdmath_radian2 b);

#if false
STDMATH_EXPORT bool stdmath_bool2_all_of(stdmath_bool2 v);
STDMATH_EXPORT bool stdmath_bool2_any_of(stdmath_bool2 v);
STDMATH_EXPORT bool stdmath_bool2_none_of(stdmath_bool2 v);
STDMATH_EXPORT bool stdmath_bool2_some_of(stdmath_bool2 v);
#endif

#ifndef STDMATH_NO_SWIZZLES
STDMATH_EXPORT STDMATH_INLINE stdmath_radian1 stdmath_radian2_x(stdmath_radian2 v) { return {v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian1 stdmath_radian2_x_get(stdmath_radian2* p) { return stdmath_radian2_x(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian2_x_set(stdmath_radian2* p, stdmath_radian1 value) { p->x = value.x; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian1 stdmath_radian2_y(stdmath_radian2 v) { return {v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian1 stdmath_radian2_y_get(stdmath_radian2* p) { return stdmath_radian2_y(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian2_y_set(stdmath_radian2* p, stdmath_radian1 value) { p->y = value.x; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian2_xx(stdmath_radian2 v) { return {v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian2_xx_get(stdmath_radian2* p) { return stdmath_radian2_xx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian2_xx_set(stdmath_radian2* p, stdmath_radian2 value) { p->x = value.x; p->x = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian2_xy(stdmath_radian2 v) { return {v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian2_xy_get(stdmath_radian2* p) { return stdmath_radian2_xy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian2_xy_set(stdmath_radian2* p, stdmath_radian2 value) { p->x = value.x; p->y = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian2_yx(stdmath_radian2 v) { return {v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian2_yx_get(stdmath_radian2* p) { return stdmath_radian2_yx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian2_yx_set(stdmath_radian2* p, stdmath_radian2 value) { p->y = value.x; p->x = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian2_yy(stdmath_radian2 v) { return {v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian2_yy_get(stdmath_radian2* p) { return stdmath_radian2_yy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_radian2 stdmath_radian2_yy_set(stdmath_radian2* p, stdmath_radian2 value) { p->y = value.x; p->y = value.y; return *p; }

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

inline stdmath::radian2 c(stdmath_radian2 c) {
	return (stdmath::radian2&)c;
}
inline stdmath_radian2 c(stdmath::radian2 c) {
	return (stdmath_radian2&)c;
}

#ifdef __cplusplus
extern "C" {
#endif

stdmath_radian2 stdmath_radian2_broadcast(stdmath_radian all) {
	return c(stdmath::radian2((stdmath::radian2::underlying_type&)all));
}

stdmath_radian2 stdmath_radian2_add(stdmath_radian2 a, stdmath_radian2 b) {
	return c(c(a) + c(b));
}
stdmath_radian2 stdmath_radian2_subtract(stdmath_radian2 a, stdmath_radian2 b) {
	return c(c(a) - c(b));
}
stdmath_radian2 stdmath_radian2_negate(stdmath_radian2 v) {
#if !true && !false
	return c(stdmath::radian2(-(stdmath::vector<stdmath_radian, 2>)c(v)));
#else
	assert(false && "TODO: Why can't we use - on vector<degree/radian, N>?");
#endif
}
stdmath_radian2 stdmath_radian2_multiply(stdmath_radian2 a, stdmath_radian2 b) {
	return c(c(a) * c(b));
}
stdmath_radian2 stdmath_radian2_divide(stdmath_radian2 a, stdmath_radian2 b) {
	return c(c(a) / c(b));
}
stdmath_radian2 stdmath_radian2_scale(stdmath_radian2 v, stdmath_radian s) {
	return c(c(v) * (stdmath::radian2::underlying_type&)s);
}

#if false
stdmath_radian2 stdmath_radian2_modulus(stdmath_radian2 a, stdmath_radian2 b) {
	return c(c(a) % c(b));
}
stdmath_radian2 stdmath_radian2_logical_not(stdmath_radian2 v) {
	return c(!c(v));
}
stdmath_radian2 stdmath_radian2_bitwise_not(stdmath_radian2 v) {
	return c(~c(v));
}
stdmath_radian2 stdmath_radian2_logical_and(stdmath_radian2 a, stdmath_radian2 b) {
	return c(c(a) && c(b));
}
stdmath_radian2 stdmath_radian2_bitwise_and(stdmath_radian2 a, stdmath_radian2 b) {
	return c(c(a) & c(b));
}
stdmath_radian2 stdmath_radian2_logical_or(stdmath_radian2 a, stdmath_radian2 b) {
	return c(c(a) || c(b));
}
stdmath_radian2 stdmath_radian2_bitwise_or(stdmath_radian2 a, stdmath_radian2 b) {
	return c(c(a) | c(b));
}
stdmath_radian2 stdmath_radian2_bitwise_xor(stdmath_radian2 a, stdmath_radian2 b) {
	return c(c(a) ^ c(b));
}
stdmath_radian2 stdmath_radian2_shift_left(stdmath_radian2 a, stdmath_radian2 b) {
	return c(c(a) << c(b));
}
stdmath_radian2 stdmath_radian2_shift_right(stdmath_radian2 a, stdmath_radian2 b) {
	return c(c(a) >> c(b));
}
#endif

stdmath_bool2 stdmath_radian2_equal_to(stdmath_radian2 a, stdmath_radian2 b) {
	return c(c(a) == c(b));
}
stdmath_bool2 stdmath_radian2_not_equal_to(stdmath_radian2 a, stdmath_radian2 b) {
	return c(c(a) != c(b));
}
stdmath_bool2 stdmath_radian2_less_than(stdmath_radian2 a, stdmath_radian2 b) {
	return c(c(a) < c(b));
}
stdmath_bool2 stdmath_radian2_less_than_or_equal_to(stdmath_radian2 a, stdmath_radian2 b) {
	return c(c(a) <= c(b));
}
stdmath_bool2 stdmath_radian2_greater_than(stdmath_radian2 a, stdmath_radian2 b) {
	return c(c(a) > c(b));
}
stdmath_bool2 stdmath_radian2_greater_than_or_equal_to(stdmath_radian2 a, stdmath_radian2 b) {
	return c(c(a) >= c(b));
}

stdmath_radian stdmath_radian2_length_squared(stdmath_radian2 v)  {
	auto out = c(v).length_squared();
	return (stdmath_radian&)out;
}
stdmath_radian stdmath_radian2_length(stdmath_radian2 v)  {
	auto out = c(v).length();
	return (stdmath_radian&)out;
}
stdmath_radian stdmath_radian2_dot(stdmath_radian2 a, stdmath_radian2 b)  {
	auto out = dot(c(a), c(b));
	return (stdmath_radian&)out;
}
stdmath_radian stdmath_radian2_min_element(stdmath_radian2 v)  {
	auto out = c(v).min_element();
	return (stdmath_radian&)out;
}
stdmath_radian stdmath_radian2_max_element(stdmath_radian2 v)  {
	auto out = c(v).max_element();
	return (stdmath_radian&)out;
}

// stdmath_radian2 stdmath_radian2_elementwise_transform(stdmath_radian2 v, stdmath_radian(*func)(stdmath_radian)) {
// 	return c(c(v).elementwise_transform(func));
// }
// stdmath_radian stdmath_radian2_reduce_elements(stdmath_radian2 v, stdmath_radian initial_value, stdmath_radian(*reducer)(stdmath_radian2, stdmath_radian2)) {
// 	return c(v).reduce_elements(initial_value, reducer);
// }

#if 2 == 3
stdmath_radian2 stdmath_radian2_cross(stdmath_radian2 a, stdmath_radian2 b) {
	return c(cross(c(a), c(b)));
}
#endif

stdmath_radian2 stdmath_radian2_min(stdmath_radian2 a, stdmath_radian2 b) {
	return c(min(c(a), c(b)));
}
stdmath_radian2 stdmath_radian2_max(stdmath_radian2 a, stdmath_radian2 b) {
	return c(max(c(a), c(b)));
}
stdmath_radian2 stdmath_radian2_normalize(stdmath_radian2 v) {
	return c(normalize(c(v)));
}
stdmath_radian2 stdmath_radian2_lerp(stdmath_radian2 a, stdmath_radian2 b, float t) {
	return c(lerp(c(a), c(b), t));
}
stdmath_radian2 stdmath_radian2_clamp(stdmath_radian2 a, stdmath_radian2 min, stdmath_radian2 max) {
	return c(clamp(c(a), c(min), c(max)));
}
stdmath_radian2 stdmath_radian2_reflect(stdmath_radian2 a, stdmath_radian2 b) {
	return c(reflect(c(a), c(b)));
}
stdmath_bool2 stdmath_radian2_approximately_equal(stdmath_radian2 a, stdmath_radian2 b) {
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

#endif // __STDMATH_stdmath_radian2_H__