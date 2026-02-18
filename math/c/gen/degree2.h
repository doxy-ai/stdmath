#ifndef __STDMATH_stdmath_degree2_H__
#define __STDMATH_stdmath_degree2_H__

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
#include "degree1.h"
#elif 2 == 3
#include "degree2.h"
#include "degree1.h"
#elif 2 == 4
#include "degree3.h"
#include "degree2.h"
#include "degree1.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if 2 == 1
STDMATH_EXPORT union stdmath_degree1 {
	struct {
		stdmath_degree x;
	};
	stdmath_degree data[1];
};
#elif 2 == 2
STDMATH_EXPORT union stdmath_degree2 {
	struct {
		stdmath_degree x, y;
	};
	struct {
		stdmath_degree u, v;
	};
	stdmath_degree data[2];
};
#elif 2 == 3
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
#elif 2 == 4
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

STDMATH_EXPORT stdmath_degree2 stdmath_degree2_broadcast(stdmath_degree all);

STDMATH_EXPORT stdmath_degree2 stdmath_degree2_add(stdmath_degree2 a, stdmath_degree2 b);
STDMATH_EXPORT stdmath_degree2 stdmath_degree2_subtract(stdmath_degree2 a, stdmath_degree2 b);
STDMATH_EXPORT stdmath_degree2 stdmath_degree2_negate(stdmath_degree2 v);
STDMATH_EXPORT stdmath_degree2 stdmath_degree2_multiply(stdmath_degree2 a, stdmath_degree2 b);
STDMATH_EXPORT stdmath_degree2 stdmath_degree2_divide(stdmath_degree2 a, stdmath_degree2 b);
STDMATH_EXPORT stdmath_degree2 stdmath_degree2_scale(stdmath_degree2 v, stdmath_degree s);

#if false
STDMATH_EXPORT stdmath_degree2 stdmath_degree2_modulus(stdmath_degree2 a, stdmath_degree2 b);
STDMATH_EXPORT stdmath_degree2 stdmath_degree2_logical_not(stdmath_degree2 v);
STDMATH_EXPORT stdmath_degree2 stdmath_degree2_bitwise_not(stdmath_degree2 v);
STDMATH_EXPORT stdmath_degree2 stdmath_degree2_logical_and(stdmath_degree2 a, stdmath_degree2 b);
STDMATH_EXPORT stdmath_degree2 stdmath_degree2_bitwise_and(stdmath_degree2 a, stdmath_degree2 b);
STDMATH_EXPORT stdmath_degree2 stdmath_degree2_logical_or(stdmath_degree2 a, stdmath_degree2 b);
STDMATH_EXPORT stdmath_degree2 stdmath_degree2_bitwise_or(stdmath_degree2 a, stdmath_degree2 b);
STDMATH_EXPORT stdmath_degree2 stdmath_degree2_bitwise_xor(stdmath_degree2 a, stdmath_degree2 b);
STDMATH_EXPORT stdmath_degree2 stdmath_degree2_shift_left(stdmath_degree2 a, stdmath_degree2 b);
STDMATH_EXPORT stdmath_degree2 stdmath_degree2_shift_right(stdmath_degree2 a, stdmath_degree2 b);
#endif

STDMATH_EXPORT stdmath_bool2 stdmath_degree2_equal_to(stdmath_degree2 a, stdmath_degree2 b);
STDMATH_EXPORT stdmath_bool2 stdmath_degree2_not_equal_to(stdmath_degree2 a, stdmath_degree2 b);
STDMATH_EXPORT stdmath_bool2 stdmath_degree2_less_than(stdmath_degree2 a, stdmath_degree2 b);
STDMATH_EXPORT stdmath_bool2 stdmath_degree2_less_than_or_equal_to(stdmath_degree2 a, stdmath_degree2 b);
STDMATH_EXPORT stdmath_bool2 stdmath_degree2_greater_than(stdmath_degree2 a, stdmath_degree2 b);
STDMATH_EXPORT stdmath_bool2 stdmath_degree2_greater_than_or_equal_to(stdmath_degree2 a, stdmath_degree2 b);

STDMATH_EXPORT stdmath_degree stdmath_degree2_length_squared(stdmath_degree2 v);
STDMATH_EXPORT stdmath_degree stdmath_degree2_length(stdmath_degree2 v);
STDMATH_EXPORT stdmath_degree stdmath_degree2_dot(stdmath_degree2 a, stdmath_degree2 b);
STDMATH_EXPORT stdmath_degree stdmath_degree2_min_element(stdmath_degree2 v);
STDMATH_EXPORT stdmath_degree stdmath_degree2_max_element(stdmath_degree2 v);

// STDMATH_EXPORT stdmath_degree2 stdmath_degree2_elementwise_transform(stdmath_degree2 v, stdmath_degree(*func)(stdmath_degree));
// STDMATH_EXPORT stdmath_degree stdmath_degree2_reduce_elements(stdmath_degree2 v, stdmath_degree initial_value, stdmath_degree(*reducer)(stdmath_degree2, stdmath_degree2));

#if 2 == 3
STDMATH_EXPORT stdmath_degree3 stdmath_degree3_cross(stdmath_degree3 a, stdmath_degree3 b);
#endif

STDMATH_EXPORT stdmath_degree2 stdmath_degree2_min(stdmath_degree2 a, stdmath_degree2 b);
STDMATH_EXPORT stdmath_degree2 stdmath_degree2_max(stdmath_degree2 a, stdmath_degree2 b);
STDMATH_EXPORT stdmath_degree2 stdmath_degree2_normalize(stdmath_degree2 v);
STDMATH_EXPORT stdmath_degree2 stdmath_degree2_lerp(stdmath_degree2 a, stdmath_degree2 b, float t);
STDMATH_EXPORT stdmath_degree2 stdmath_degree2_clamp(stdmath_degree2 a, stdmath_degree2 min, stdmath_degree2 max);
STDMATH_EXPORT stdmath_degree2 stdmath_degree2_reflect(stdmath_degree2 a, stdmath_degree2 b);
STDMATH_EXPORT stdmath_bool2 stdmath_degree2_approximately_equal(stdmath_degree2 a, stdmath_degree2 b);

#if false
STDMATH_EXPORT bool stdmath_bool2_all_of(stdmath_bool2 v);
STDMATH_EXPORT bool stdmath_bool2_any_of(stdmath_bool2 v);
STDMATH_EXPORT bool stdmath_bool2_none_of(stdmath_bool2 v);
STDMATH_EXPORT bool stdmath_bool2_some_of(stdmath_bool2 v);
#endif

#ifndef STDMATH_NO_SWIZZLES
STDMATH_EXPORT STDMATH_INLINE stdmath_degree1 stdmath_degree2_x(stdmath_degree2 v) { return {v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree1 stdmath_degree2_x_get(stdmath_degree2* p) { return stdmath_degree2_x(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree2_x_set(stdmath_degree2* p, stdmath_degree1 value) { p->x = value.x; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree1 stdmath_degree2_y(stdmath_degree2 v) { return {v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree1 stdmath_degree2_y_get(stdmath_degree2* p) { return stdmath_degree2_y(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree2_y_set(stdmath_degree2* p, stdmath_degree1 value) { p->y = value.x; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree2_xx(stdmath_degree2 v) { return {v.x,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree2_xx_get(stdmath_degree2* p) { return stdmath_degree2_xx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree2_xx_set(stdmath_degree2* p, stdmath_degree2 value) { p->x = value.x; p->x = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree2_xy(stdmath_degree2 v) { return {v.x,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree2_xy_get(stdmath_degree2* p) { return stdmath_degree2_xy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree2_xy_set(stdmath_degree2* p, stdmath_degree2 value) { p->x = value.x; p->y = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree2_yx(stdmath_degree2 v) { return {v.y,v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree2_yx_get(stdmath_degree2* p) { return stdmath_degree2_yx(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree2_yx_set(stdmath_degree2* p, stdmath_degree2 value) { p->y = value.x; p->x = value.y; return *p; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree2_yy(stdmath_degree2 v) { return {v.y,v.y}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree2_yy_get(stdmath_degree2* p) { return stdmath_degree2_yy(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree2 stdmath_degree2_yy_set(stdmath_degree2* p, stdmath_degree2 value) { p->y = value.x; p->y = value.y; return *p; }

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

inline stdmath::degree2 c(stdmath_degree2 c) {
	return (stdmath::degree2&)c;
}
inline stdmath_degree2 c(stdmath::degree2 c) {
	return (stdmath_degree2&)c;
}

#ifdef __cplusplus
extern "C" {
#endif

stdmath_degree2 stdmath_degree2_broadcast(stdmath_degree all) {
	return c(stdmath::degree2((stdmath::degree2::underlying_type&)all));
}

stdmath_degree2 stdmath_degree2_add(stdmath_degree2 a, stdmath_degree2 b) {
	return c(c(a) + c(b));
}
stdmath_degree2 stdmath_degree2_subtract(stdmath_degree2 a, stdmath_degree2 b) {
	return c(c(a) - c(b));
}
stdmath_degree2 stdmath_degree2_negate(stdmath_degree2 v) {
#if !false && !true
	return c(stdmath::degree2(-(stdmath::vector<stdmath_degree, 2>)c(v)));
#else
	assert(false && "TODO: Why can't we use - on vector<degree/radian, N>?");
#endif
}
stdmath_degree2 stdmath_degree2_multiply(stdmath_degree2 a, stdmath_degree2 b) {
	return c(c(a) * c(b));
}
stdmath_degree2 stdmath_degree2_divide(stdmath_degree2 a, stdmath_degree2 b) {
	return c(c(a) / c(b));
}
stdmath_degree2 stdmath_degree2_scale(stdmath_degree2 v, stdmath_degree s) {
	return c(c(v) * (stdmath::degree2::underlying_type&)s);
}

#if false
stdmath_degree2 stdmath_degree2_modulus(stdmath_degree2 a, stdmath_degree2 b) {
	return c(c(a) % c(b));
}
stdmath_degree2 stdmath_degree2_logical_not(stdmath_degree2 v) {
	return c(!c(v));
}
stdmath_degree2 stdmath_degree2_bitwise_not(stdmath_degree2 v) {
	return c(~c(v));
}
stdmath_degree2 stdmath_degree2_logical_and(stdmath_degree2 a, stdmath_degree2 b) {
	return c(c(a) && c(b));
}
stdmath_degree2 stdmath_degree2_bitwise_and(stdmath_degree2 a, stdmath_degree2 b) {
	return c(c(a) & c(b));
}
stdmath_degree2 stdmath_degree2_logical_or(stdmath_degree2 a, stdmath_degree2 b) {
	return c(c(a) || c(b));
}
stdmath_degree2 stdmath_degree2_bitwise_or(stdmath_degree2 a, stdmath_degree2 b) {
	return c(c(a) | c(b));
}
stdmath_degree2 stdmath_degree2_bitwise_xor(stdmath_degree2 a, stdmath_degree2 b) {
	return c(c(a) ^ c(b));
}
stdmath_degree2 stdmath_degree2_shift_left(stdmath_degree2 a, stdmath_degree2 b) {
	return c(c(a) << c(b));
}
stdmath_degree2 stdmath_degree2_shift_right(stdmath_degree2 a, stdmath_degree2 b) {
	return c(c(a) >> c(b));
}
#endif

stdmath_bool2 stdmath_degree2_equal_to(stdmath_degree2 a, stdmath_degree2 b) {
	return c(c(a) == c(b));
}
stdmath_bool2 stdmath_degree2_not_equal_to(stdmath_degree2 a, stdmath_degree2 b) {
	return c(c(a) != c(b));
}
stdmath_bool2 stdmath_degree2_less_than(stdmath_degree2 a, stdmath_degree2 b) {
	return c(c(a) < c(b));
}
stdmath_bool2 stdmath_degree2_less_than_or_equal_to(stdmath_degree2 a, stdmath_degree2 b) {
	return c(c(a) <= c(b));
}
stdmath_bool2 stdmath_degree2_greater_than(stdmath_degree2 a, stdmath_degree2 b) {
	return c(c(a) > c(b));
}
stdmath_bool2 stdmath_degree2_greater_than_or_equal_to(stdmath_degree2 a, stdmath_degree2 b) {
	return c(c(a) >= c(b));
}

stdmath_degree stdmath_degree2_length_squared(stdmath_degree2 v)  {
	auto out = c(v).length_squared();
	return (stdmath_degree&)out;
}
stdmath_degree stdmath_degree2_length(stdmath_degree2 v)  {
	auto out = c(v).length();
	return (stdmath_degree&)out;
}
stdmath_degree stdmath_degree2_dot(stdmath_degree2 a, stdmath_degree2 b)  {
	auto out = dot(c(a), c(b));
	return (stdmath_degree&)out;
}
stdmath_degree stdmath_degree2_min_element(stdmath_degree2 v)  {
	auto out = c(v).min_element();
	return (stdmath_degree&)out;
}
stdmath_degree stdmath_degree2_max_element(stdmath_degree2 v)  {
	auto out = c(v).max_element();
	return (stdmath_degree&)out;
}

// stdmath_degree2 stdmath_degree2_elementwise_transform(stdmath_degree2 v, stdmath_degree(*func)(stdmath_degree)) {
// 	return c(c(v).elementwise_transform(func));
// }
// stdmath_degree stdmath_degree2_reduce_elements(stdmath_degree2 v, stdmath_degree initial_value, stdmath_degree(*reducer)(stdmath_degree2, stdmath_degree2)) {
// 	return c(v).reduce_elements(initial_value, reducer);
// }

#if 2 == 3
stdmath_degree2 stdmath_degree2_cross(stdmath_degree2 a, stdmath_degree2 b) {
	return c(cross(c(a), c(b)));
}
#endif

stdmath_degree2 stdmath_degree2_min(stdmath_degree2 a, stdmath_degree2 b) {
	return c(min(c(a), c(b)));
}
stdmath_degree2 stdmath_degree2_max(stdmath_degree2 a, stdmath_degree2 b) {
	return c(max(c(a), c(b)));
}
stdmath_degree2 stdmath_degree2_normalize(stdmath_degree2 v) {
	return c(normalize(c(v)));
}
stdmath_degree2 stdmath_degree2_lerp(stdmath_degree2 a, stdmath_degree2 b, float t) {
	return c(lerp(c(a), c(b), t));
}
stdmath_degree2 stdmath_degree2_clamp(stdmath_degree2 a, stdmath_degree2 min, stdmath_degree2 max) {
	return c(clamp(c(a), c(min), c(max)));
}
stdmath_degree2 stdmath_degree2_reflect(stdmath_degree2 a, stdmath_degree2 b) {
	return c(reflect(c(a), c(b)));
}
stdmath_bool2 stdmath_degree2_approximately_equal(stdmath_degree2 a, stdmath_degree2 b) {
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

#endif // __STDMATH_stdmath_degree2_H__