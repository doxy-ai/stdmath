#ifndef __STDMATH_int32_t1_H__
#define __STDMATH_int32_t1_H__

#include <stdint.h>
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
#include "int1.h"
#elif 1 == 3
#include "int2.h"
#include "int1.h"
#elif 1 == 4
#include "int3.h"
#include "int2.h"
#include "int1.h"
#endif
#include "util.h"

#if 1 == 1
union stdmath_int1 {
	struct {
		int32_t x;
	};
	int32_t data[1];
};
#elif 1 == 2
union stdmath_int2 {
	struct {
		int32_t x, y;
	};
	struct {
		int32_t u, v;
	};
	int32_t data[2];
};
#elif 1 == 3
union stdmath_int3 {
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
#elif 1 == 4
union stdmath_int4 {
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

stdmath_int1 stdmath_int1_broadcast(int32_t all);

stdmath_int1 stdmath_int1_add(stdmath_int1 a, stdmath_int1 b);
stdmath_int1 stdmath_int1_subtract(stdmath_int1 a, stdmath_int1 b);
stdmath_int1 stdmath_int1_negate(stdmath_int1 v);
stdmath_int1 stdmath_int1_multiply(stdmath_int1 a, stdmath_int1 b);
stdmath_int1 stdmath_int1_divide(stdmath_int1 a, stdmath_int1 b);
stdmath_int1 stdmath_int1_scale(stdmath_int1 v, int32_t s);

#if false
stdmath_int1 stdmath_int1_modulus(stdmath_int1 a, stdmath_int1 b);
stdmath_int1 stdmath_int1_logical_not(stdmath_int1 v);
stdmath_int1 stdmath_int1_bitwise_not(stdmath_int1 v);
stdmath_int1 stdmath_int1_logical_and(stdmath_int1 a, stdmath_int1 b);
stdmath_int1 stdmath_int1_bitwise_and(stdmath_int1 a, stdmath_int1 b);
stdmath_int1 stdmath_int1_logical_or(stdmath_int1 a, stdmath_int1 b);
stdmath_int1 stdmath_int1_bitwise_or(stdmath_int1 a, stdmath_int1 b);
stdmath_int1 stdmath_int1_bitwise_xor(stdmath_int1 a, stdmath_int1 b);
stdmath_int1 stdmath_int1_shift_left(stdmath_int1 a, stdmath_int1 b);
stdmath_int1 stdmath_int1_shift_right(stdmath_int1 a, stdmath_int1 b);
#endif

stdmath_bool1 stdmath_int1_equal_to(stdmath_int1 a, stdmath_int1 b);
stdmath_bool1 stdmath_int1_not_equal_to(stdmath_int1 a, stdmath_int1 b);
stdmath_bool1 stdmath_int1_less_than(stdmath_int1 a, stdmath_int1 b);
stdmath_bool1 stdmath_int1_less_than_or_equal_to(stdmath_int1 a, stdmath_int1 b);
stdmath_bool1 stdmath_int1_greater_than(stdmath_int1 a, stdmath_int1 b);
stdmath_bool1 stdmath_int1_greater_than_or_equal_to(stdmath_int1 a, stdmath_int1 b);

int32_t stdmath_int1_length_squared(stdmath_int1 v);
int32_t stdmath_int1_length(stdmath_int1 v);
int32_t stdmath_int1_dot(stdmath_int1 v);
int32_t stdmath_int1_min_element(stdmath_int1 v);
int32_t stdmath_int1_max_element(stdmath_int1 v);

stdmath_int1 stdmath_int1_elementwise_transform(stdmath_int1 v, int32_t(*func)(int32_t));
// int32_t stdmath_int1_reduce_elements(stdmath_int1 v, int32_t initial_value, int32_t(*reducer)(stdmath_int1, stdmath_int1));

#if 1 == 3
stdmath_int3 stdmath_int3_cross(stdmath_int3 a, stdmath_int3 b);
#endif

stdmath_int1 stdmath_int1_min(stdmath_int1 a, stdmath_int1 b);
stdmath_int1 stdmath_int1_max(stdmath_int1 a, stdmath_int1 b);
stdmath_int1 stdmath_int1_normalize(stdmath_int1 v);
stdmath_int1 stdmath_int1_lerp(stdmath_int1 a, stdmath_int1 b, float t);
stdmath_int1 stdmath_int1_clamp(stdmath_int1 a, stdmath_int1 min, stdmath_int1 max);
stdmath_int1 stdmath_int1_reflect(stdmath_int1 a, stdmath_int1 b);
stdmath_bool1 stdmath_int1_approximately_equal(stdmath_int1 a, stdmath_int1 b);

#if false
bool stdmath_bool1_all_of(stdmath_bool1 v);
bool stdmath_bool1_any_of(stdmath_bool1 v);
bool stdmath_bool1_none_of(stdmath_bool1 v);
bool stdmath_bool1_some_of(stdmath_bool1 v);
#endif

inline static stdmath_int1 stdmath_int1_x(stdmath_int1 v) { return {v.x}; }
inline static stdmath_int1 stdmath_int1_x_value(stdmath_int1 v, stdmath_int1 value) { v.x = value.x; return v; }


#ifdef STDMATH_IMPLEMENTATION
#ifndef __cplusplus
#error "The stdmath implementations require a C++ compiler"
#endif

import stdmath.slang;

stdmath::int1 c(stdmath_int1 c) {
	return (stdmath::int1&)c;
}
stdmath_int1 c(stdmath::int1 c) {
	return (stdmath_int1&)c;
}

stdmath_int1 stdmath_int1_broadcast(int32_t all) {
	return c(stdmath::int1((stdmath::int1::underlying_type)all));
}

stdmath_int1 stdmath_int1_add(stdmath_int1 a, stdmath_int1 b) {
	return c(c(a) + c(b));
}
stdmath_int1 stdmath_int1_subtract(stdmath_int1 a, stdmath_int1 b) {
	return c(c(a) - c(b));
}
stdmath_int1 stdmath_int1_negate(stdmath_int1 v) {
	return c(stdmath::int1(-(stdmath::vector<int32_t, 1>)c(v)));
}
stdmath_int1 stdmath_int1_multiply(stdmath_int1 a, stdmath_int1 b) {
	return c(c(a) * c(b));
}
stdmath_int1 stdmath_int1_divide(stdmath_int1 a, stdmath_int1 b) {
	return c(c(a) / c(b));
}
stdmath_int1 stdmath_int1_scale(stdmath_int1 v, int32_t s) {
	return c(c(v) * (stdmath::int1::underlying_type)s);
}

#if false
stdmath_int1 stdmath_int1_modulus(stdmath_int1 a, stdmath_int1 b) {
	return c(c(a) % c(b));
}
stdmath_int1 stdmath_int1_logical_not(stdmath_int1 v) {
	return c(!c(v));
}
stdmath_int1 stdmath_int1_bitwise_not(stdmath_int1 v) {
	return c(~c(v));
}
stdmath_int1 stdmath_int1_logical_and(stdmath_int1 a, stdmath_int1 b) {
	return c(c(a) && c(b));
}
stdmath_int1 stdmath_int1_bitwise_and(stdmath_int1 a, stdmath_int1 b) {
	return c(c(a) & c(b));
}
stdmath_int1 stdmath_int1_logical_or(stdmath_int1 a, stdmath_int1 b) {
	return c(c(a) || c(b));
}
stdmath_int1 stdmath_int1_bitwise_or(stdmath_int1 a, stdmath_int1 b) {
	return c(c(a) | c(b));
}
stdmath_int1 stdmath_int1_bitwise_xor(stdmath_int1 a, stdmath_int1 b) {
	return c(c(a) ^ c(b));
}
stdmath_int1 stdmath_int1_shift_left(stdmath_int1 a, stdmath_int1 b) {
	return c(c(a) << c(b));
}
stdmath_int1 stdmath_int1_shift_right(stdmath_int1 a, stdmath_int1 b) {
	return c(c(a) >> c(b));
}
#endif

stdmath_bool1 stdmath_int1_equal_to(stdmath_int1 a, stdmath_int1 b) {
	return c(c(a) == c(b));
}
stdmath_bool1 stdmath_int1_not_equal_to(stdmath_int1 a, stdmath_int1 b) {
	return c(c(a) != c(b));
}
stdmath_bool1 stdmath_int1_less_than(stdmath_int1 a, stdmath_int1 b) {
	return c(c(a) < c(b));
}
stdmath_bool1 stdmath_int1_less_than_or_equal_to(stdmath_int1 a, stdmath_int1 b) {
	return c(c(a) <= c(b));
}
stdmath_bool1 stdmath_int1_greater_than(stdmath_int1 a, stdmath_int1 b) {
	return c(c(a) > c(b));
}
stdmath_bool1 stdmath_int1_greater_than_or_equal_to(stdmath_int1 a, stdmath_int1 b) {
	return c(c(a) >= c(b));
}

int32_t stdmath_int1_length_squared(stdmath_int1 v)  {
	return (int32_t)c(v).length_squared();
}
int32_t stdmath_int1_length(stdmath_int1 v)  {
	return (int32_t)c(v).length();
}
int32_t stdmath_int1_dot(stdmath_int1 a, stdmath_int1 b)  {
	return (int32_t)dot(c(a), c(b));
}
int32_t stdmath_int1_min_element(stdmath_int1 v)  {
	return (int32_t)c(v).min_element();
}
int32_t stdmath_int1_max_element(stdmath_int1 v)  {
	return (int32_t)c(v).max_element();
}

stdmath_int1 stdmath_int1_elementwise_transform(stdmath_int1 v, int32_t(*func)(int32_t)) {
	return c(c(v).elementwise_transform(func));
}
// int32_t stdmath_int1_reduce_elements(stdmath_int1 v, int32_t initial_value, int32_t(*reducer)(stdmath_int1, stdmath_int1)) {
// 	return c(v).reduce_elements(initial_value, reducer);
// }

#if 1 == 3
stdmath_int1 stdmath_int1_cross(stdmath_int1 a, stdmath_int1 b) {
	return c(cross(c(a), c(b)));
}
#endif

stdmath_int1 stdmath_int1_min(stdmath_int1 a, stdmath_int1 b) {
	return c(min(c(a), c(b)));
}
stdmath_int1 stdmath_int1_max(stdmath_int1 a, stdmath_int1 b) {
	return c(max(c(a), c(b)));
}
stdmath_int1 stdmath_int1_normalize(stdmath_int1 v) {
	return c(normalize(c(v)));
}
stdmath_int1 stdmath_int1_lerp(stdmath_int1 a, stdmath_int1 b, float t) {
	return c(lerp(c(a), c(b), t));
}
stdmath_int1 stdmath_int1_clamp(stdmath_int1 a, stdmath_int1 min, stdmath_int1 max) {
	return c(clamp(c(a), c(min), c(max)));
}
stdmath_int1 stdmath_int1_reflect(stdmath_int1 a, stdmath_int1 b) {
	return c(reflect(c(a), c(b)));
}
stdmath_bool1 stdmath_int1_approximately_equal(stdmath_int1 a, stdmath_int1 b) {
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

#endif // STDMATH_IMPLEMENTATION

#endif // __STDMATH_int32_t1_H__