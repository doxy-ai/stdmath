#ifndef __STDMATH_float1_H__
#define __STDMATH_float1_H__

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
#include "float1.h"
#elif 1 == 3
#include "float2.h"
#include "float1.h"
#elif 1 == 4
#include "float3.h"
#include "float2.h"
#include "float1.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if 1 == 1
STDMATH_EXPORT union stdmath_float1 {
	struct {
		float x;
	};
	float data[1];
};
#elif 1 == 2
STDMATH_EXPORT union stdmath_float2 {
	struct {
		float x, y;
	};
	struct {
		float u, v;
	};
	float data[2];
};
#elif 1 == 3
STDMATH_EXPORT union stdmath_float3 {
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
#elif 1 == 4
STDMATH_EXPORT union stdmath_float4 {
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

STDMATH_EXPORT stdmath_float1 stdmath_float1_broadcast(float all);

STDMATH_EXPORT stdmath_float1 stdmath_float1_add(stdmath_float1 a, stdmath_float1 b);
STDMATH_EXPORT stdmath_float1 stdmath_float1_subtract(stdmath_float1 a, stdmath_float1 b);
STDMATH_EXPORT stdmath_float1 stdmath_float1_negate(stdmath_float1 v);
STDMATH_EXPORT stdmath_float1 stdmath_float1_multiply(stdmath_float1 a, stdmath_float1 b);
STDMATH_EXPORT stdmath_float1 stdmath_float1_divide(stdmath_float1 a, stdmath_float1 b);
STDMATH_EXPORT stdmath_float1 stdmath_float1_scale(stdmath_float1 v, float s);

#if false
STDMATH_EXPORT stdmath_float1 stdmath_float1_modulus(stdmath_float1 a, stdmath_float1 b);
STDMATH_EXPORT stdmath_float1 stdmath_float1_logical_not(stdmath_float1 v);
STDMATH_EXPORT stdmath_float1 stdmath_float1_bitwise_not(stdmath_float1 v);
STDMATH_EXPORT stdmath_float1 stdmath_float1_logical_and(stdmath_float1 a, stdmath_float1 b);
STDMATH_EXPORT stdmath_float1 stdmath_float1_bitwise_and(stdmath_float1 a, stdmath_float1 b);
STDMATH_EXPORT stdmath_float1 stdmath_float1_logical_or(stdmath_float1 a, stdmath_float1 b);
STDMATH_EXPORT stdmath_float1 stdmath_float1_bitwise_or(stdmath_float1 a, stdmath_float1 b);
STDMATH_EXPORT stdmath_float1 stdmath_float1_bitwise_xor(stdmath_float1 a, stdmath_float1 b);
STDMATH_EXPORT stdmath_float1 stdmath_float1_shift_left(stdmath_float1 a, stdmath_float1 b);
STDMATH_EXPORT stdmath_float1 stdmath_float1_shift_right(stdmath_float1 a, stdmath_float1 b);
#endif

STDMATH_EXPORT stdmath_bool1 stdmath_float1_equal_to(stdmath_float1 a, stdmath_float1 b);
STDMATH_EXPORT stdmath_bool1 stdmath_float1_not_equal_to(stdmath_float1 a, stdmath_float1 b);
STDMATH_EXPORT stdmath_bool1 stdmath_float1_less_than(stdmath_float1 a, stdmath_float1 b);
STDMATH_EXPORT stdmath_bool1 stdmath_float1_less_than_or_equal_to(stdmath_float1 a, stdmath_float1 b);
STDMATH_EXPORT stdmath_bool1 stdmath_float1_greater_than(stdmath_float1 a, stdmath_float1 b);
STDMATH_EXPORT stdmath_bool1 stdmath_float1_greater_than_or_equal_to(stdmath_float1 a, stdmath_float1 b);

STDMATH_EXPORT float stdmath_float1_length_squared(stdmath_float1 v);
STDMATH_EXPORT float stdmath_float1_length(stdmath_float1 v);
STDMATH_EXPORT float stdmath_float1_dot(stdmath_float1 a, stdmath_float1 b);
STDMATH_EXPORT float stdmath_float1_min_element(stdmath_float1 v);
STDMATH_EXPORT float stdmath_float1_max_element(stdmath_float1 v);

// STDMATH_EXPORT stdmath_float1 stdmath_float1_elementwise_transform(stdmath_float1 v, float(*func)(float));
// STDMATH_EXPORT float stdmath_float1_reduce_elements(stdmath_float1 v, float initial_value, float(*reducer)(stdmath_float1, stdmath_float1));

#if 1 == 3
STDMATH_EXPORT stdmath_float3 stdmath_float3_cross(stdmath_float3 a, stdmath_float3 b);
#endif

STDMATH_EXPORT stdmath_float1 stdmath_float1_min(stdmath_float1 a, stdmath_float1 b);
STDMATH_EXPORT stdmath_float1 stdmath_float1_max(stdmath_float1 a, stdmath_float1 b);
STDMATH_EXPORT stdmath_float1 stdmath_float1_normalize(stdmath_float1 v);
STDMATH_EXPORT stdmath_float1 stdmath_float1_lerp(stdmath_float1 a, stdmath_float1 b, float t);
STDMATH_EXPORT stdmath_float1 stdmath_float1_clamp(stdmath_float1 a, stdmath_float1 min, stdmath_float1 max);
STDMATH_EXPORT stdmath_float1 stdmath_float1_reflect(stdmath_float1 a, stdmath_float1 b);
STDMATH_EXPORT stdmath_bool1 stdmath_float1_approximately_equal(stdmath_float1 a, stdmath_float1 b);

#if false
STDMATH_EXPORT bool stdmath_bool1_all_of(stdmath_bool1 v);
STDMATH_EXPORT bool stdmath_bool1_any_of(stdmath_bool1 v);
STDMATH_EXPORT bool stdmath_bool1_none_of(stdmath_bool1 v);
STDMATH_EXPORT bool stdmath_bool1_some_of(stdmath_bool1 v);
#endif

#ifndef STDMATH_NO_SWIZZLES
STDMATH_EXPORT STDMATH_INLINE stdmath_float1 stdmath_float1_x(stdmath_float1 v) { return {v.x}; }
STDMATH_EXPORT STDMATH_INLINE stdmath_float1 stdmath_float1_x_get(stdmath_float1* p) { return stdmath_float1_x(*p); }
STDMATH_EXPORT STDMATH_INLINE stdmath_float1 stdmath_float1_x_set(stdmath_float1* p, stdmath_float1 value) { p->x = value.x; return *p; }

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

inline stdmath::float1 c(stdmath_float1 c) {
	return (stdmath::float1&)c;
}
inline stdmath_float1 c(stdmath::float1 c) {
	return (stdmath_float1&)c;
}

#ifdef __cplusplus
extern "C" {
#endif

stdmath_float1 stdmath_float1_broadcast(float all) {
	return c(stdmath::float1((stdmath::float1::underlying_type&)all));
}

stdmath_float1 stdmath_float1_add(stdmath_float1 a, stdmath_float1 b) {
	return c(c(a) + c(b));
}
stdmath_float1 stdmath_float1_subtract(stdmath_float1 a, stdmath_float1 b) {
	return c(c(a) - c(b));
}
stdmath_float1 stdmath_float1_negate(stdmath_float1 v) {
#if !false && !false
	return c(stdmath::float1(-(stdmath::vector<float, 1>)c(v)));
#else
	assert(false && "TODO: Why can't we use - on vector<degree/radian, N>?");
#endif
}
stdmath_float1 stdmath_float1_multiply(stdmath_float1 a, stdmath_float1 b) {
	return c(c(a) * c(b));
}
stdmath_float1 stdmath_float1_divide(stdmath_float1 a, stdmath_float1 b) {
	return c(c(a) / c(b));
}
stdmath_float1 stdmath_float1_scale(stdmath_float1 v, float s) {
	return c(c(v) * (stdmath::float1::underlying_type&)s);
}

#if false
stdmath_float1 stdmath_float1_modulus(stdmath_float1 a, stdmath_float1 b) {
	return c(c(a) % c(b));
}
stdmath_float1 stdmath_float1_logical_not(stdmath_float1 v) {
	return c(!c(v));
}
stdmath_float1 stdmath_float1_bitwise_not(stdmath_float1 v) {
	return c(~c(v));
}
stdmath_float1 stdmath_float1_logical_and(stdmath_float1 a, stdmath_float1 b) {
	return c(c(a) && c(b));
}
stdmath_float1 stdmath_float1_bitwise_and(stdmath_float1 a, stdmath_float1 b) {
	return c(c(a) & c(b));
}
stdmath_float1 stdmath_float1_logical_or(stdmath_float1 a, stdmath_float1 b) {
	return c(c(a) || c(b));
}
stdmath_float1 stdmath_float1_bitwise_or(stdmath_float1 a, stdmath_float1 b) {
	return c(c(a) | c(b));
}
stdmath_float1 stdmath_float1_bitwise_xor(stdmath_float1 a, stdmath_float1 b) {
	return c(c(a) ^ c(b));
}
stdmath_float1 stdmath_float1_shift_left(stdmath_float1 a, stdmath_float1 b) {
	return c(c(a) << c(b));
}
stdmath_float1 stdmath_float1_shift_right(stdmath_float1 a, stdmath_float1 b) {
	return c(c(a) >> c(b));
}
#endif

stdmath_bool1 stdmath_float1_equal_to(stdmath_float1 a, stdmath_float1 b) {
	return c(c(a) == c(b));
}
stdmath_bool1 stdmath_float1_not_equal_to(stdmath_float1 a, stdmath_float1 b) {
	return c(c(a) != c(b));
}
stdmath_bool1 stdmath_float1_less_than(stdmath_float1 a, stdmath_float1 b) {
	return c(c(a) < c(b));
}
stdmath_bool1 stdmath_float1_less_than_or_equal_to(stdmath_float1 a, stdmath_float1 b) {
	return c(c(a) <= c(b));
}
stdmath_bool1 stdmath_float1_greater_than(stdmath_float1 a, stdmath_float1 b) {
	return c(c(a) > c(b));
}
stdmath_bool1 stdmath_float1_greater_than_or_equal_to(stdmath_float1 a, stdmath_float1 b) {
	return c(c(a) >= c(b));
}

float stdmath_float1_length_squared(stdmath_float1 v)  {
	auto out = c(v).length_squared();
	return (float&)out;
}
float stdmath_float1_length(stdmath_float1 v)  {
	auto out = c(v).length();
	return (float&)out;
}
float stdmath_float1_dot(stdmath_float1 a, stdmath_float1 b)  {
	auto out = dot(c(a), c(b));
	return (float&)out;
}
float stdmath_float1_min_element(stdmath_float1 v)  {
	auto out = c(v).min_element();
	return (float&)out;
}
float stdmath_float1_max_element(stdmath_float1 v)  {
	auto out = c(v).max_element();
	return (float&)out;
}

// stdmath_float1 stdmath_float1_elementwise_transform(stdmath_float1 v, float(*func)(float)) {
// 	return c(c(v).elementwise_transform(func));
// }
// float stdmath_float1_reduce_elements(stdmath_float1 v, float initial_value, float(*reducer)(stdmath_float1, stdmath_float1)) {
// 	return c(v).reduce_elements(initial_value, reducer);
// }

#if 1 == 3
stdmath_float1 stdmath_float1_cross(stdmath_float1 a, stdmath_float1 b) {
	return c(cross(c(a), c(b)));
}
#endif

stdmath_float1 stdmath_float1_min(stdmath_float1 a, stdmath_float1 b) {
	return c(min(c(a), c(b)));
}
stdmath_float1 stdmath_float1_max(stdmath_float1 a, stdmath_float1 b) {
	return c(max(c(a), c(b)));
}
stdmath_float1 stdmath_float1_normalize(stdmath_float1 v) {
	return c(normalize(c(v)));
}
stdmath_float1 stdmath_float1_lerp(stdmath_float1 a, stdmath_float1 b, float t) {
	return c(lerp(c(a), c(b), t));
}
stdmath_float1 stdmath_float1_clamp(stdmath_float1 a, stdmath_float1 min, stdmath_float1 max) {
	return c(clamp(c(a), c(min), c(max)));
}
stdmath_float1 stdmath_float1_reflect(stdmath_float1 a, stdmath_float1 b) {
	return c(reflect(c(a), c(b)));
}
stdmath_bool1 stdmath_float1_approximately_equal(stdmath_float1 a, stdmath_float1 b) {
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

#endif // __STDMATH_float1_H__