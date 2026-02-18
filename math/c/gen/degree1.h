#ifndef __STDMATH_stdmath_degree1_H__
#define __STDMATH_stdmath_degree1_H__

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
#if 1 == 1
#include "bool1.h"
#elif 1 == 2
#include "bool2.h"
#elif 1 == 3
#include "bool3.h"
#elif 1 == 4
#include "bool4.h"
#endif
#endif
#if 1 == 2
#include "degree1.h"
#elif 1 == 3
#include "degree2.h"
#include "degree1.h"
#elif 1 == 4
#include "degree3.h"
#include "degree2.h"
#include "degree1.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if 1 == 1
STDMATH_EXPORT union stdmath_degree1 {
	struct {
		stdmath_degree x;
	};
	stdmath_degree data[1];
};
#elif 1 == 2
STDMATH_EXPORT union stdmath_degree2 {
	struct {
		stdmath_degree x, y;
	};
	struct {
		stdmath_degree u, v;
	};
	stdmath_degree data[2];
};
#elif 1 == 3
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
#elif 1 == 4
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

STDMATH_EXPORT stdmath_degree1 stdmath_degree1_broadcast(stdmath_degree all);

STDMATH_EXPORT stdmath_degree1 stdmath_degree1_add(stdmath_degree1 a, stdmath_degree1 b);
STDMATH_EXPORT stdmath_degree1 stdmath_degree1_subtract(stdmath_degree1 a, stdmath_degree1 b);
STDMATH_EXPORT stdmath_degree1 stdmath_degree1_negate(stdmath_degree1 v);
STDMATH_EXPORT stdmath_degree1 stdmath_degree1_multiply(stdmath_degree1 a, stdmath_degree1 b);
STDMATH_EXPORT stdmath_degree1 stdmath_degree1_divide(stdmath_degree1 a, stdmath_degree1 b);
STDMATH_EXPORT stdmath_degree1 stdmath_degree1_scale(stdmath_degree1 v, stdmath_degree s);

#if false
STDMATH_EXPORT stdmath_degree1 stdmath_degree1_modulus(stdmath_degree1 a, stdmath_degree1 b);
STDMATH_EXPORT stdmath_degree1 stdmath_degree1_logical_not(stdmath_degree1 v);
STDMATH_EXPORT stdmath_degree1 stdmath_degree1_bitwise_not(stdmath_degree1 v);
STDMATH_EXPORT stdmath_degree1 stdmath_degree1_logical_and(stdmath_degree1 a, stdmath_degree1 b);
STDMATH_EXPORT stdmath_degree1 stdmath_degree1_bitwise_and(stdmath_degree1 a, stdmath_degree1 b);
STDMATH_EXPORT stdmath_degree1 stdmath_degree1_logical_or(stdmath_degree1 a, stdmath_degree1 b);
STDMATH_EXPORT stdmath_degree1 stdmath_degree1_bitwise_or(stdmath_degree1 a, stdmath_degree1 b);
STDMATH_EXPORT stdmath_degree1 stdmath_degree1_bitwise_xor(stdmath_degree1 a, stdmath_degree1 b);
STDMATH_EXPORT stdmath_degree1 stdmath_degree1_shift_left(stdmath_degree1 a, stdmath_degree1 b);
STDMATH_EXPORT stdmath_degree1 stdmath_degree1_shift_right(stdmath_degree1 a, stdmath_degree1 b);
#endif

STDMATH_EXPORT stdmath_bool1 stdmath_degree1_equal_to(stdmath_degree1 a, stdmath_degree1 b);
STDMATH_EXPORT stdmath_bool1 stdmath_degree1_not_equal_to(stdmath_degree1 a, stdmath_degree1 b);
STDMATH_EXPORT stdmath_bool1 stdmath_degree1_less_than(stdmath_degree1 a, stdmath_degree1 b);
STDMATH_EXPORT stdmath_bool1 stdmath_degree1_less_than_or_equal_to(stdmath_degree1 a, stdmath_degree1 b);
STDMATH_EXPORT stdmath_bool1 stdmath_degree1_greater_than(stdmath_degree1 a, stdmath_degree1 b);
STDMATH_EXPORT stdmath_bool1 stdmath_degree1_greater_than_or_equal_to(stdmath_degree1 a, stdmath_degree1 b);

STDMATH_EXPORT stdmath_degree stdmath_degree1_length_squared(stdmath_degree1 v);
STDMATH_EXPORT stdmath_degree stdmath_degree1_length(stdmath_degree1 v);
STDMATH_EXPORT stdmath_degree stdmath_degree1_dot(stdmath_degree1 a, stdmath_degree1 b);
STDMATH_EXPORT stdmath_degree stdmath_degree1_min_element(stdmath_degree1 v);
STDMATH_EXPORT stdmath_degree stdmath_degree1_max_element(stdmath_degree1 v);

// STDMATH_EXPORT stdmath_degree1 stdmath_degree1_elementwise_transform(stdmath_degree1 v, stdmath_degree(*func)(stdmath_degree));
// STDMATH_EXPORT stdmath_degree stdmath_degree1_reduce_elements(stdmath_degree1 v, stdmath_degree initial_value, stdmath_degree(*reducer)(stdmath_degree1, stdmath_degree1));

#if 1 == 3
STDMATH_EXPORT stdmath_degree3 stdmath_degree3_cross(stdmath_degree3 a, stdmath_degree3 b);
#endif

STDMATH_EXPORT stdmath_degree1 stdmath_degree1_min(stdmath_degree1 a, stdmath_degree1 b);
STDMATH_EXPORT stdmath_degree1 stdmath_degree1_max(stdmath_degree1 a, stdmath_degree1 b);
STDMATH_EXPORT stdmath_degree1 stdmath_degree1_normalize(stdmath_degree1 v);
STDMATH_EXPORT stdmath_degree1 stdmath_degree1_lerp(stdmath_degree1 a, stdmath_degree1 b, float t);
STDMATH_EXPORT stdmath_degree1 stdmath_degree1_clamp(stdmath_degree1 a, stdmath_degree1 min, stdmath_degree1 max);
STDMATH_EXPORT stdmath_degree1 stdmath_degree1_reflect(stdmath_degree1 a, stdmath_degree1 b);
STDMATH_EXPORT stdmath_bool1 stdmath_degree1_approximately_equal(stdmath_degree1 a, stdmath_degree1 b);

#if false
STDMATH_EXPORT bool stdmath_bool1_all_of(stdmath_bool1 v);
STDMATH_EXPORT bool stdmath_bool1_any_of(stdmath_bool1 v);
STDMATH_EXPORT bool stdmath_bool1_none_of(stdmath_bool1 v);
STDMATH_EXPORT bool stdmath_bool1_some_of(stdmath_bool1 v);
#endif

#ifndef STDMATH_NO_SWIZZLES
STDMATH_EXPORT STDMATH_INLINE stdmath_degree1 stdmath_degree1_x(stdmath_degree1 v) { return {v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree1 stdmath_degree1_x_get(stdmath_degree1* p) { return stdmath_degree1_x(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_degree1 stdmath_degree1_x_set(stdmath_degree1* p, stdmath_degree1 value) { p->x = value.x; return *p; }

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

inline stdmath::degree1 c(stdmath_degree1 c) {
	return (stdmath::degree1&)c;
}
inline stdmath_degree1 c(stdmath::degree1 c) {
	return (stdmath_degree1&)c;
}

#ifdef __cplusplus
extern "C" {
#endif

stdmath_degree1 stdmath_degree1_broadcast(stdmath_degree all) {
	return c(stdmath::degree1((stdmath::degree1::underlying_type&)all));
}

stdmath_degree1 stdmath_degree1_add(stdmath_degree1 a, stdmath_degree1 b) {
	return c(c(a) + c(b));
}
stdmath_degree1 stdmath_degree1_subtract(stdmath_degree1 a, stdmath_degree1 b) {
	return c(c(a) - c(b));
}
stdmath_degree1 stdmath_degree1_negate(stdmath_degree1 v) {
#if !false && !true
	return c(stdmath::degree1(-(stdmath::vector<stdmath_degree, 1>)c(v)));
#else
	assert(false && "TODO: Why can't we use - on vector<degree/radian, N>?");
#endif
}
stdmath_degree1 stdmath_degree1_multiply(stdmath_degree1 a, stdmath_degree1 b) {
	return c(c(a) * c(b));
}
stdmath_degree1 stdmath_degree1_divide(stdmath_degree1 a, stdmath_degree1 b) {
	return c(c(a) / c(b));
}
stdmath_degree1 stdmath_degree1_scale(stdmath_degree1 v, stdmath_degree s) {
	return c(c(v) * (stdmath::degree1::underlying_type&)s);
}

#if false
stdmath_degree1 stdmath_degree1_modulus(stdmath_degree1 a, stdmath_degree1 b) {
	return c(c(a) % c(b));
}
stdmath_degree1 stdmath_degree1_logical_not(stdmath_degree1 v) {
	return c(!c(v));
}
stdmath_degree1 stdmath_degree1_bitwise_not(stdmath_degree1 v) {
	return c(~c(v));
}
stdmath_degree1 stdmath_degree1_logical_and(stdmath_degree1 a, stdmath_degree1 b) {
	return c(c(a) && c(b));
}
stdmath_degree1 stdmath_degree1_bitwise_and(stdmath_degree1 a, stdmath_degree1 b) {
	return c(c(a) & c(b));
}
stdmath_degree1 stdmath_degree1_logical_or(stdmath_degree1 a, stdmath_degree1 b) {
	return c(c(a) || c(b));
}
stdmath_degree1 stdmath_degree1_bitwise_or(stdmath_degree1 a, stdmath_degree1 b) {
	return c(c(a) | c(b));
}
stdmath_degree1 stdmath_degree1_bitwise_xor(stdmath_degree1 a, stdmath_degree1 b) {
	return c(c(a) ^ c(b));
}
stdmath_degree1 stdmath_degree1_shift_left(stdmath_degree1 a, stdmath_degree1 b) {
	return c(c(a) << c(b));
}
stdmath_degree1 stdmath_degree1_shift_right(stdmath_degree1 a, stdmath_degree1 b) {
	return c(c(a) >> c(b));
}
#endif

stdmath_bool1 stdmath_degree1_equal_to(stdmath_degree1 a, stdmath_degree1 b) {
	return c(c(a) == c(b));
}
stdmath_bool1 stdmath_degree1_not_equal_to(stdmath_degree1 a, stdmath_degree1 b) {
	return c(c(a) != c(b));
}
stdmath_bool1 stdmath_degree1_less_than(stdmath_degree1 a, stdmath_degree1 b) {
	return c(c(a) < c(b));
}
stdmath_bool1 stdmath_degree1_less_than_or_equal_to(stdmath_degree1 a, stdmath_degree1 b) {
	return c(c(a) <= c(b));
}
stdmath_bool1 stdmath_degree1_greater_than(stdmath_degree1 a, stdmath_degree1 b) {
	return c(c(a) > c(b));
}
stdmath_bool1 stdmath_degree1_greater_than_or_equal_to(stdmath_degree1 a, stdmath_degree1 b) {
	return c(c(a) >= c(b));
}

stdmath_degree stdmath_degree1_length_squared(stdmath_degree1 v)  {
	auto out = c(v).length_squared();
	return (stdmath_degree&)out;
}
stdmath_degree stdmath_degree1_length(stdmath_degree1 v)  {
	auto out = c(v).length();
	return (stdmath_degree&)out;
}
stdmath_degree stdmath_degree1_dot(stdmath_degree1 a, stdmath_degree1 b)  {
	auto out = dot(c(a), c(b));
	return (stdmath_degree&)out;
}
stdmath_degree stdmath_degree1_min_element(stdmath_degree1 v)  {
	auto out = c(v).min_element();
	return (stdmath_degree&)out;
}
stdmath_degree stdmath_degree1_max_element(stdmath_degree1 v)  {
	auto out = c(v).max_element();
	return (stdmath_degree&)out;
}

// stdmath_degree1 stdmath_degree1_elementwise_transform(stdmath_degree1 v, stdmath_degree(*func)(stdmath_degree)) {
// 	return c(c(v).elementwise_transform(func));
// }
// stdmath_degree stdmath_degree1_reduce_elements(stdmath_degree1 v, stdmath_degree initial_value, stdmath_degree(*reducer)(stdmath_degree1, stdmath_degree1)) {
// 	return c(v).reduce_elements(initial_value, reducer);
// }

#if 1 == 3
stdmath_degree1 stdmath_degree1_cross(stdmath_degree1 a, stdmath_degree1 b) {
	return c(cross(c(a), c(b)));
}
#endif

stdmath_degree1 stdmath_degree1_min(stdmath_degree1 a, stdmath_degree1 b) {
	return c(min(c(a), c(b)));
}
stdmath_degree1 stdmath_degree1_max(stdmath_degree1 a, stdmath_degree1 b) {
	return c(max(c(a), c(b)));
}
stdmath_degree1 stdmath_degree1_normalize(stdmath_degree1 v) {
	return c(normalize(c(v)));
}
stdmath_degree1 stdmath_degree1_lerp(stdmath_degree1 a, stdmath_degree1 b, float t) {
	return c(lerp(c(a), c(b), t));
}
stdmath_degree1 stdmath_degree1_clamp(stdmath_degree1 a, stdmath_degree1 min, stdmath_degree1 max) {
	return c(clamp(c(a), c(min), c(max)));
}
stdmath_degree1 stdmath_degree1_reflect(stdmath_degree1 a, stdmath_degree1 b) {
	return c(reflect(c(a), c(b)));
}
stdmath_bool1 stdmath_degree1_approximately_equal(stdmath_degree1 a, stdmath_degree1 b) {
	return c(approximately_equal(c(a), c(b)));
}

#if false
bool stdmath_bool1_all_of(stdmath_bool1 v) {
	return all_of(c(v));
}
bool stdmath_bool1_any_of(stdmath_bool1 v) {
	return any_of(c(v));
}
bool stdmath_bool1_none_of(stdmath_bool1 v) {
	return none_of(c(v));
}
bool stdmath_bool1_some_of(stdmath_bool1 v) {
	return some_of(c(v));
}
#endif

#ifdef __cplusplus
} // extern "C"
#endif

#endif // STDMATH_IMPLEMENTATION

#endif // __STDMATH_stdmath_degree1_H__