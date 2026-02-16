#ifndef __STDMATH_bool1_H__
#define __STDMATH_bool1_H__

#include <stdint.h>
#if !true
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
#include "bool1.h"
#elif 1 == 3
#include "bool2.h"
#include "bool1.h"
#elif 1 == 4
#include "bool3.h"
#include "bool2.h"
#include "bool1.h"
#endif
#include "util.h"

#if 1 == 1
union stdmath_bool1 {
	struct {
		bool x;
	};
	bool data[1];
};
#elif 1 == 2
union stdmath_bool2 {
	struct {
		bool x, y;
	};
	struct {
		bool u, v;
	};
	bool data[2];
};
#elif 1 == 3
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
#elif 1 == 4
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

stdmath_bool1 stdmath_bool1_broadcast(bool all);

stdmath_bool1 stdmath_bool1_add(stdmath_bool1 a, stdmath_bool1 b);
stdmath_bool1 stdmath_bool1_subtract(stdmath_bool1 a, stdmath_bool1 b);
stdmath_bool1 stdmath_bool1_negate(stdmath_bool1 v);
stdmath_bool1 stdmath_bool1_multiply(stdmath_bool1 a, stdmath_bool1 b);
stdmath_bool1 stdmath_bool1_divide(stdmath_bool1 a, stdmath_bool1 b);
stdmath_bool1 stdmath_bool1_scale(stdmath_bool1 v, bool s);

#if false
stdmath_bool1 stdmath_bool1_modulus(stdmath_bool1 a, stdmath_bool1 b);
stdmath_bool1 stdmath_bool1_logical_not(stdmath_bool1 v);
stdmath_bool1 stdmath_bool1_bitwise_not(stdmath_bool1 v);
stdmath_bool1 stdmath_bool1_logical_and(stdmath_bool1 a, stdmath_bool1 b);
stdmath_bool1 stdmath_bool1_bitwise_and(stdmath_bool1 a, stdmath_bool1 b);
stdmath_bool1 stdmath_bool1_logical_or(stdmath_bool1 a, stdmath_bool1 b);
stdmath_bool1 stdmath_bool1_bitwise_or(stdmath_bool1 a, stdmath_bool1 b);
stdmath_bool1 stdmath_bool1_bitwise_xor(stdmath_bool1 a, stdmath_bool1 b);
stdmath_bool1 stdmath_bool1_shift_left(stdmath_bool1 a, stdmath_bool1 b);
stdmath_bool1 stdmath_bool1_shift_right(stdmath_bool1 a, stdmath_bool1 b);
#endif

stdmath_bool1 stdmath_bool1_equal_to(stdmath_bool1 a, stdmath_bool1 b);
stdmath_bool1 stdmath_bool1_not_equal_to(stdmath_bool1 a, stdmath_bool1 b);
stdmath_bool1 stdmath_bool1_less_than(stdmath_bool1 a, stdmath_bool1 b);
stdmath_bool1 stdmath_bool1_less_than_or_equal_to(stdmath_bool1 a, stdmath_bool1 b);
stdmath_bool1 stdmath_bool1_greater_than(stdmath_bool1 a, stdmath_bool1 b);
stdmath_bool1 stdmath_bool1_greater_than_or_equal_to(stdmath_bool1 a, stdmath_bool1 b);

bool stdmath_bool1_length_squared(stdmath_bool1 v);
bool stdmath_bool1_length(stdmath_bool1 v);
bool stdmath_bool1_dot(stdmath_bool1 a, stdmath_bool1 b);
bool stdmath_bool1_min_element(stdmath_bool1 v);
bool stdmath_bool1_max_element(stdmath_bool1 v);

stdmath_bool1 stdmath_bool1_elementwise_transform(stdmath_bool1 v, bool(*func)(bool));
// bool stdmath_bool1_reduce_elements(stdmath_bool1 v, bool initial_value, bool(*reducer)(stdmath_bool1, stdmath_bool1));

#if 1 == 3
stdmath_bool3 stdmath_bool3_cross(stdmath_bool3 a, stdmath_bool3 b);
#endif

stdmath_bool1 stdmath_bool1_min(stdmath_bool1 a, stdmath_bool1 b);
stdmath_bool1 stdmath_bool1_max(stdmath_bool1 a, stdmath_bool1 b);
stdmath_bool1 stdmath_bool1_normalize(stdmath_bool1 v);
stdmath_bool1 stdmath_bool1_lerp(stdmath_bool1 a, stdmath_bool1 b, float t);
stdmath_bool1 stdmath_bool1_clamp(stdmath_bool1 a, stdmath_bool1 min, stdmath_bool1 max);
stdmath_bool1 stdmath_bool1_reflect(stdmath_bool1 a, stdmath_bool1 b);
stdmath_bool1 stdmath_bool1_approximately_equal(stdmath_bool1 a, stdmath_bool1 b);

#if true
bool stdmath_bool1_all_of(stdmath_bool1 v);
bool stdmath_bool1_any_of(stdmath_bool1 v);
bool stdmath_bool1_none_of(stdmath_bool1 v);
bool stdmath_bool1_some_of(stdmath_bool1 v);
#endif

inline static stdmath_bool1 stdmath_bool1_x(stdmath_bool1 v) { return {v.x}; }
inline static stdmath_bool1 stdmath_bool1_x_get(stdmath_bool1* p) { return stdmath_bool1_x(*p); }
inline static stdmath_bool1 stdmath_bool1_x_set(stdmath_bool1* p, stdmath_bool1 value) { p->x = value.x; return *p; }


#ifdef STDMATH_IMPLEMENTATION
#ifndef __cplusplus
#error "The stdmath implementations require a C++ compiler"
#endif

import stdmath.slang;

stdmath::bool1 c(stdmath_bool1 c) {
	return (stdmath::bool1&)c;
}
stdmath_bool1 c(stdmath::bool1 c) {
	return (stdmath_bool1&)c;
}

stdmath_bool1 stdmath_bool1_broadcast(bool all) {
	return c(stdmath::bool1((stdmath::bool1::underlying_type)all));
}

stdmath_bool1 stdmath_bool1_add(stdmath_bool1 a, stdmath_bool1 b) {
	return c(c(a) + c(b));
}
stdmath_bool1 stdmath_bool1_subtract(stdmath_bool1 a, stdmath_bool1 b) {
	return c(c(a) - c(b));
}
stdmath_bool1 stdmath_bool1_negate(stdmath_bool1 v) {
	return c(stdmath::bool1(-(stdmath::vector<bool, 1>)c(v)));
}
stdmath_bool1 stdmath_bool1_multiply(stdmath_bool1 a, stdmath_bool1 b) {
	return c(c(a) * c(b));
}
stdmath_bool1 stdmath_bool1_divide(stdmath_bool1 a, stdmath_bool1 b) {
	return c(c(a) / c(b));
}
stdmath_bool1 stdmath_bool1_scale(stdmath_bool1 v, bool s) {
	return c(c(v) * (stdmath::bool1::underlying_type)s);
}

#if false
stdmath_bool1 stdmath_bool1_modulus(stdmath_bool1 a, stdmath_bool1 b) {
	return c(c(a) % c(b));
}
stdmath_bool1 stdmath_bool1_logical_not(stdmath_bool1 v) {
	return c(!c(v));
}
stdmath_bool1 stdmath_bool1_bitwise_not(stdmath_bool1 v) {
	return c(~c(v));
}
stdmath_bool1 stdmath_bool1_logical_and(stdmath_bool1 a, stdmath_bool1 b) {
	return c(c(a) && c(b));
}
stdmath_bool1 stdmath_bool1_bitwise_and(stdmath_bool1 a, stdmath_bool1 b) {
	return c(c(a) & c(b));
}
stdmath_bool1 stdmath_bool1_logical_or(stdmath_bool1 a, stdmath_bool1 b) {
	return c(c(a) || c(b));
}
stdmath_bool1 stdmath_bool1_bitwise_or(stdmath_bool1 a, stdmath_bool1 b) {
	return c(c(a) | c(b));
}
stdmath_bool1 stdmath_bool1_bitwise_xor(stdmath_bool1 a, stdmath_bool1 b) {
	return c(c(a) ^ c(b));
}
stdmath_bool1 stdmath_bool1_shift_left(stdmath_bool1 a, stdmath_bool1 b) {
	return c(c(a) << c(b));
}
stdmath_bool1 stdmath_bool1_shift_right(stdmath_bool1 a, stdmath_bool1 b) {
	return c(c(a) >> c(b));
}
#endif

stdmath_bool1 stdmath_bool1_equal_to(stdmath_bool1 a, stdmath_bool1 b) {
	return c(c(a) == c(b));
}
stdmath_bool1 stdmath_bool1_not_equal_to(stdmath_bool1 a, stdmath_bool1 b) {
	return c(c(a) != c(b));
}
stdmath_bool1 stdmath_bool1_less_than(stdmath_bool1 a, stdmath_bool1 b) {
	return c(c(a) < c(b));
}
stdmath_bool1 stdmath_bool1_less_than_or_equal_to(stdmath_bool1 a, stdmath_bool1 b) {
	return c(c(a) <= c(b));
}
stdmath_bool1 stdmath_bool1_greater_than(stdmath_bool1 a, stdmath_bool1 b) {
	return c(c(a) > c(b));
}
stdmath_bool1 stdmath_bool1_greater_than_or_equal_to(stdmath_bool1 a, stdmath_bool1 b) {
	return c(c(a) >= c(b));
}

bool stdmath_bool1_length_squared(stdmath_bool1 v)  {
	return (bool)c(v).length_squared();
}
bool stdmath_bool1_length(stdmath_bool1 v)  {
	return (bool)c(v).length();
}
bool stdmath_bool1_dot(stdmath_bool1 a, stdmath_bool1 b)  {
	return (bool)dot(c(a), c(b));
}
bool stdmath_bool1_min_element(stdmath_bool1 v)  {
	return (bool)c(v).min_element();
}
bool stdmath_bool1_max_element(stdmath_bool1 v)  {
	return (bool)c(v).max_element();
}

stdmath_bool1 stdmath_bool1_elementwise_transform(stdmath_bool1 v, bool(*func)(bool)) {
	return c(c(v).elementwise_transform(func));
}
// bool stdmath_bool1_reduce_elements(stdmath_bool1 v, bool initial_value, bool(*reducer)(stdmath_bool1, stdmath_bool1)) {
// 	return c(v).reduce_elements(initial_value, reducer);
// }

#if 1 == 3
stdmath_bool1 stdmath_bool1_cross(stdmath_bool1 a, stdmath_bool1 b) {
	return c(cross(c(a), c(b)));
}
#endif

stdmath_bool1 stdmath_bool1_min(stdmath_bool1 a, stdmath_bool1 b) {
	return c(min(c(a), c(b)));
}
stdmath_bool1 stdmath_bool1_max(stdmath_bool1 a, stdmath_bool1 b) {
	return c(max(c(a), c(b)));
}
stdmath_bool1 stdmath_bool1_normalize(stdmath_bool1 v) {
	return c(normalize(c(v)));
}
stdmath_bool1 stdmath_bool1_lerp(stdmath_bool1 a, stdmath_bool1 b, float t) {
	return c(lerp(c(a), c(b), t));
}
stdmath_bool1 stdmath_bool1_clamp(stdmath_bool1 a, stdmath_bool1 min, stdmath_bool1 max) {
	return c(clamp(c(a), c(min), c(max)));
}
stdmath_bool1 stdmath_bool1_reflect(stdmath_bool1 a, stdmath_bool1 b) {
	return c(reflect(c(a), c(b)));
}
stdmath_bool1 stdmath_bool1_approximately_equal(stdmath_bool1 a, stdmath_bool1 b) {
	return c(approximately_equal(c(a), c(b)));
}

#if true
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

#endif // STDMATH_IMPLEMENTATION

#endif // __STDMATH_bool1_H__