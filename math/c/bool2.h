#ifndef __STDMATH_bool2_H__
#define __STDMATH_bool2_H__

#include <stdint.h>
#if !true
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
#include "bool1.h"
#elif 2 == 3
#include "bool2.h"
#include "bool1.h"
#elif 2 == 4
#include "bool3.h"
#include "bool2.h"
#include "bool1.h"
#endif
#include "util.h"

#if 2 == 1
union stdmath_bool1 {
	struct {
		bool x;
	};
	bool data[1];
};
#elif 2 == 2
union stdmath_bool2 {
	struct {
		bool x, y;
	};
	struct {
		bool u, v;
	};
	bool data[2];
};
#elif 2 == 3
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
#elif 2 == 4
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

stdmath_bool2 stdmath_bool2_broadcast(bool all);

stdmath_bool2 stdmath_bool2_add(stdmath_bool2 a, stdmath_bool2 b);
stdmath_bool2 stdmath_bool2_subtract(stdmath_bool2 a, stdmath_bool2 b);
stdmath_bool2 stdmath_bool2_negate(stdmath_bool2 v);
stdmath_bool2 stdmath_bool2_multiply(stdmath_bool2 a, stdmath_bool2 b);
stdmath_bool2 stdmath_bool2_divide(stdmath_bool2 a, stdmath_bool2 b);
stdmath_bool2 stdmath_bool2_scale(stdmath_bool2 v, bool s);

#if false
stdmath_bool2 stdmath_bool2_modulus(stdmath_bool2 a, stdmath_bool2 b);
stdmath_bool2 stdmath_bool2_logical_not(stdmath_bool2 v);
stdmath_bool2 stdmath_bool2_bitwise_not(stdmath_bool2 v);
stdmath_bool2 stdmath_bool2_logical_and(stdmath_bool2 a, stdmath_bool2 b);
stdmath_bool2 stdmath_bool2_bitwise_and(stdmath_bool2 a, stdmath_bool2 b);
stdmath_bool2 stdmath_bool2_logical_or(stdmath_bool2 a, stdmath_bool2 b);
stdmath_bool2 stdmath_bool2_bitwise_or(stdmath_bool2 a, stdmath_bool2 b);
stdmath_bool2 stdmath_bool2_bitwise_xor(stdmath_bool2 a, stdmath_bool2 b);
stdmath_bool2 stdmath_bool2_shift_left(stdmath_bool2 a, stdmath_bool2 b);
stdmath_bool2 stdmath_bool2_shift_right(stdmath_bool2 a, stdmath_bool2 b);
#endif

stdmath_bool2 stdmath_bool2_equal_to(stdmath_bool2 a, stdmath_bool2 b);
stdmath_bool2 stdmath_bool2_not_equal_to(stdmath_bool2 a, stdmath_bool2 b);
stdmath_bool2 stdmath_bool2_less_than(stdmath_bool2 a, stdmath_bool2 b);
stdmath_bool2 stdmath_bool2_less_than_or_equal_to(stdmath_bool2 a, stdmath_bool2 b);
stdmath_bool2 stdmath_bool2_greater_than(stdmath_bool2 a, stdmath_bool2 b);
stdmath_bool2 stdmath_bool2_greater_than_or_equal_to(stdmath_bool2 a, stdmath_bool2 b);

bool stdmath_bool2_length_squared(stdmath_bool2 v);
bool stdmath_bool2_length(stdmath_bool2 v);
bool stdmath_bool2_dot(stdmath_bool2 a, stdmath_bool2 b);
bool stdmath_bool2_min_element(stdmath_bool2 v);
bool stdmath_bool2_max_element(stdmath_bool2 v);

stdmath_bool2 stdmath_bool2_elementwise_transform(stdmath_bool2 v, bool(*func)(bool));
// bool stdmath_bool2_reduce_elements(stdmath_bool2 v, bool initial_value, bool(*reducer)(stdmath_bool2, stdmath_bool2));

#if 2 == 3
stdmath_bool3 stdmath_bool3_cross(stdmath_bool3 a, stdmath_bool3 b);
#endif

stdmath_bool2 stdmath_bool2_min(stdmath_bool2 a, stdmath_bool2 b);
stdmath_bool2 stdmath_bool2_max(stdmath_bool2 a, stdmath_bool2 b);
stdmath_bool2 stdmath_bool2_normalize(stdmath_bool2 v);
stdmath_bool2 stdmath_bool2_lerp(stdmath_bool2 a, stdmath_bool2 b, float t);
stdmath_bool2 stdmath_bool2_clamp(stdmath_bool2 a, stdmath_bool2 min, stdmath_bool2 max);
stdmath_bool2 stdmath_bool2_reflect(stdmath_bool2 a, stdmath_bool2 b);
stdmath_bool2 stdmath_bool2_approximately_equal(stdmath_bool2 a, stdmath_bool2 b);

#if true
bool stdmath_bool2_all_of(stdmath_bool2 v);
bool stdmath_bool2_any_of(stdmath_bool2 v);
bool stdmath_bool2_none_of(stdmath_bool2 v);
bool stdmath_bool2_some_of(stdmath_bool2 v);
#endif

inline static stdmath_bool1 stdmath_bool2_x(stdmath_bool2 v) { return {v.x}; }
inline static stdmath_bool1 stdmath_bool2_x_get(stdmath_bool2* p) { return stdmath_bool2_x(*p); }
inline static stdmath_bool2 stdmath_bool2_x_set(stdmath_bool2* p, stdmath_bool1 value) { p->x = value.x; return *p; }
inline static stdmath_bool1 stdmath_bool2_y(stdmath_bool2 v) { return {v.y}; }
inline static stdmath_bool1 stdmath_bool2_y_get(stdmath_bool2* p) { return stdmath_bool2_y(*p); }
inline static stdmath_bool2 stdmath_bool2_y_set(stdmath_bool2* p, stdmath_bool1 value) { p->y = value.x; return *p; }
inline static stdmath_bool2 stdmath_bool2_xx(stdmath_bool2 v) { return {v.x,v.x}; }
inline static stdmath_bool2 stdmath_bool2_xx_get(stdmath_bool2* p) { return stdmath_bool2_xx(*p); }
inline static stdmath_bool2 stdmath_bool2_xx_set(stdmath_bool2* p, stdmath_bool2 value) { p->x = value.x; p->x = value.y; return *p; }
inline static stdmath_bool2 stdmath_bool2_xy(stdmath_bool2 v) { return {v.x,v.y}; }
inline static stdmath_bool2 stdmath_bool2_xy_get(stdmath_bool2* p) { return stdmath_bool2_xy(*p); }
inline static stdmath_bool2 stdmath_bool2_xy_set(stdmath_bool2* p, stdmath_bool2 value) { p->x = value.x; p->y = value.y; return *p; }
inline static stdmath_bool2 stdmath_bool2_yx(stdmath_bool2 v) { return {v.y,v.x}; }
inline static stdmath_bool2 stdmath_bool2_yx_get(stdmath_bool2* p) { return stdmath_bool2_yx(*p); }
inline static stdmath_bool2 stdmath_bool2_yx_set(stdmath_bool2* p, stdmath_bool2 value) { p->y = value.x; p->x = value.y; return *p; }
inline static stdmath_bool2 stdmath_bool2_yy(stdmath_bool2 v) { return {v.y,v.y}; }
inline static stdmath_bool2 stdmath_bool2_yy_get(stdmath_bool2* p) { return stdmath_bool2_yy(*p); }
inline static stdmath_bool2 stdmath_bool2_yy_set(stdmath_bool2* p, stdmath_bool2 value) { p->y = value.x; p->y = value.y; return *p; }


#ifdef STDMATH_IMPLEMENTATION
#ifndef __cplusplus
#error "The stdmath implementations require a C++ compiler"
#endif

import stdmath.slang;

stdmath::bool2 c(stdmath_bool2 c) {
	return (stdmath::bool2&)c;
}
stdmath_bool2 c(stdmath::bool2 c) {
	return (stdmath_bool2&)c;
}

stdmath_bool2 stdmath_bool2_broadcast(bool all) {
	return c(stdmath::bool2((stdmath::bool2::underlying_type)all));
}

stdmath_bool2 stdmath_bool2_add(stdmath_bool2 a, stdmath_bool2 b) {
	return c(c(a) + c(b));
}
stdmath_bool2 stdmath_bool2_subtract(stdmath_bool2 a, stdmath_bool2 b) {
	return c(c(a) - c(b));
}
stdmath_bool2 stdmath_bool2_negate(stdmath_bool2 v) {
	return c(stdmath::bool2(-(stdmath::vector<bool, 2>)c(v)));
}
stdmath_bool2 stdmath_bool2_multiply(stdmath_bool2 a, stdmath_bool2 b) {
	return c(c(a) * c(b));
}
stdmath_bool2 stdmath_bool2_divide(stdmath_bool2 a, stdmath_bool2 b) {
	return c(c(a) / c(b));
}
stdmath_bool2 stdmath_bool2_scale(stdmath_bool2 v, bool s) {
	return c(c(v) * (stdmath::bool2::underlying_type)s);
}

#if false
stdmath_bool2 stdmath_bool2_modulus(stdmath_bool2 a, stdmath_bool2 b) {
	return c(c(a) % c(b));
}
stdmath_bool2 stdmath_bool2_logical_not(stdmath_bool2 v) {
	return c(!c(v));
}
stdmath_bool2 stdmath_bool2_bitwise_not(stdmath_bool2 v) {
	return c(~c(v));
}
stdmath_bool2 stdmath_bool2_logical_and(stdmath_bool2 a, stdmath_bool2 b) {
	return c(c(a) && c(b));
}
stdmath_bool2 stdmath_bool2_bitwise_and(stdmath_bool2 a, stdmath_bool2 b) {
	return c(c(a) & c(b));
}
stdmath_bool2 stdmath_bool2_logical_or(stdmath_bool2 a, stdmath_bool2 b) {
	return c(c(a) || c(b));
}
stdmath_bool2 stdmath_bool2_bitwise_or(stdmath_bool2 a, stdmath_bool2 b) {
	return c(c(a) | c(b));
}
stdmath_bool2 stdmath_bool2_bitwise_xor(stdmath_bool2 a, stdmath_bool2 b) {
	return c(c(a) ^ c(b));
}
stdmath_bool2 stdmath_bool2_shift_left(stdmath_bool2 a, stdmath_bool2 b) {
	return c(c(a) << c(b));
}
stdmath_bool2 stdmath_bool2_shift_right(stdmath_bool2 a, stdmath_bool2 b) {
	return c(c(a) >> c(b));
}
#endif

stdmath_bool2 stdmath_bool2_equal_to(stdmath_bool2 a, stdmath_bool2 b) {
	return c(c(a) == c(b));
}
stdmath_bool2 stdmath_bool2_not_equal_to(stdmath_bool2 a, stdmath_bool2 b) {
	return c(c(a) != c(b));
}
stdmath_bool2 stdmath_bool2_less_than(stdmath_bool2 a, stdmath_bool2 b) {
	return c(c(a) < c(b));
}
stdmath_bool2 stdmath_bool2_less_than_or_equal_to(stdmath_bool2 a, stdmath_bool2 b) {
	return c(c(a) <= c(b));
}
stdmath_bool2 stdmath_bool2_greater_than(stdmath_bool2 a, stdmath_bool2 b) {
	return c(c(a) > c(b));
}
stdmath_bool2 stdmath_bool2_greater_than_or_equal_to(stdmath_bool2 a, stdmath_bool2 b) {
	return c(c(a) >= c(b));
}

bool stdmath_bool2_length_squared(stdmath_bool2 v)  {
	return (bool)c(v).length_squared();
}
bool stdmath_bool2_length(stdmath_bool2 v)  {
	return (bool)c(v).length();
}
bool stdmath_bool2_dot(stdmath_bool2 a, stdmath_bool2 b)  {
	return (bool)dot(c(a), c(b));
}
bool stdmath_bool2_min_element(stdmath_bool2 v)  {
	return (bool)c(v).min_element();
}
bool stdmath_bool2_max_element(stdmath_bool2 v)  {
	return (bool)c(v).max_element();
}

stdmath_bool2 stdmath_bool2_elementwise_transform(stdmath_bool2 v, bool(*func)(bool)) {
	return c(c(v).elementwise_transform(func));
}
// bool stdmath_bool2_reduce_elements(stdmath_bool2 v, bool initial_value, bool(*reducer)(stdmath_bool2, stdmath_bool2)) {
// 	return c(v).reduce_elements(initial_value, reducer);
// }

#if 2 == 3
stdmath_bool2 stdmath_bool2_cross(stdmath_bool2 a, stdmath_bool2 b) {
	return c(cross(c(a), c(b)));
}
#endif

stdmath_bool2 stdmath_bool2_min(stdmath_bool2 a, stdmath_bool2 b) {
	return c(min(c(a), c(b)));
}
stdmath_bool2 stdmath_bool2_max(stdmath_bool2 a, stdmath_bool2 b) {
	return c(max(c(a), c(b)));
}
stdmath_bool2 stdmath_bool2_normalize(stdmath_bool2 v) {
	return c(normalize(c(v)));
}
stdmath_bool2 stdmath_bool2_lerp(stdmath_bool2 a, stdmath_bool2 b, float t) {
	return c(lerp(c(a), c(b), t));
}
stdmath_bool2 stdmath_bool2_clamp(stdmath_bool2 a, stdmath_bool2 min, stdmath_bool2 max) {
	return c(clamp(c(a), c(min), c(max)));
}
stdmath_bool2 stdmath_bool2_reflect(stdmath_bool2 a, stdmath_bool2 b) {
	return c(reflect(c(a), c(b)));
}
stdmath_bool2 stdmath_bool2_approximately_equal(stdmath_bool2 a, stdmath_bool2 b) {
	return c(approximately_equal(c(a), c(b)));
}

#if true
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

#endif // __STDMATH_bool2_H__