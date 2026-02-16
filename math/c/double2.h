#ifndef __STDMATH_double2_H__
#define __STDMATH_double2_H__

#include <stdint.h>
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
#include "double1.h"
#elif 2 == 3
#include "double2.h"
#include "double1.h"
#elif 2 == 4
#include "double3.h"
#include "double2.h"
#include "double1.h"
#endif
#include "util.h"

#if 2 == 1
union stdmath_double1 {
	struct {
		double x;
	};
	double data[1];
};
#elif 2 == 2
union stdmath_double2 {
	struct {
		double x, y;
	};
	struct {
		double u, v;
	};
	double data[2];
};
#elif 2 == 3
union stdmath_double3 {
	struct {
		double x, y, z;
	};
	struct {
		double r, g, b;
	};
	struct {
		double h, s, v;
	};
	double data[4]; // double3s are aligned as if they were double4s
};
#elif 2 == 4
union stdmath_double4 {
	struct {
		double x, y, z, w;
	};
	struct {
		double r, g, b, a;
	};
	struct {
		double h, s, v;
	};
	double data[4];
};
#endif

stdmath_double2 stdmath_double2_broadcast(double all);

stdmath_double2 stdmath_double2_add(stdmath_double2 a, stdmath_double2 b);
stdmath_double2 stdmath_double2_subtract(stdmath_double2 a, stdmath_double2 b);
stdmath_double2 stdmath_double2_negate(stdmath_double2 v);
stdmath_double2 stdmath_double2_multiply(stdmath_double2 a, stdmath_double2 b);
stdmath_double2 stdmath_double2_divide(stdmath_double2 a, stdmath_double2 b);
stdmath_double2 stdmath_double2_scale(stdmath_double2 v, double s);

#if false
stdmath_double2 stdmath_double2_modulus(stdmath_double2 a, stdmath_double2 b);
stdmath_double2 stdmath_double2_logical_not(stdmath_double2 v);
stdmath_double2 stdmath_double2_bitwise_not(stdmath_double2 v);
stdmath_double2 stdmath_double2_logical_and(stdmath_double2 a, stdmath_double2 b);
stdmath_double2 stdmath_double2_bitwise_and(stdmath_double2 a, stdmath_double2 b);
stdmath_double2 stdmath_double2_logical_or(stdmath_double2 a, stdmath_double2 b);
stdmath_double2 stdmath_double2_bitwise_or(stdmath_double2 a, stdmath_double2 b);
stdmath_double2 stdmath_double2_bitwise_xor(stdmath_double2 a, stdmath_double2 b);
stdmath_double2 stdmath_double2_shift_left(stdmath_double2 a, stdmath_double2 b);
stdmath_double2 stdmath_double2_shift_right(stdmath_double2 a, stdmath_double2 b);
#endif

stdmath_bool2 stdmath_double2_equal_to(stdmath_double2 a, stdmath_double2 b);
stdmath_bool2 stdmath_double2_not_equal_to(stdmath_double2 a, stdmath_double2 b);
stdmath_bool2 stdmath_double2_less_than(stdmath_double2 a, stdmath_double2 b);
stdmath_bool2 stdmath_double2_less_than_or_equal_to(stdmath_double2 a, stdmath_double2 b);
stdmath_bool2 stdmath_double2_greater_than(stdmath_double2 a, stdmath_double2 b);
stdmath_bool2 stdmath_double2_greater_than_or_equal_to(stdmath_double2 a, stdmath_double2 b);

double stdmath_double2_length_squared(stdmath_double2 v);
double stdmath_double2_length(stdmath_double2 v);
double stdmath_double2_dot(stdmath_double2 a, stdmath_double2 b);
double stdmath_double2_min_element(stdmath_double2 v);
double stdmath_double2_max_element(stdmath_double2 v);

stdmath_double2 stdmath_double2_elementwise_transform(stdmath_double2 v, double(*func)(double));
// double stdmath_double2_reduce_elements(stdmath_double2 v, double initial_value, double(*reducer)(stdmath_double2, stdmath_double2));

#if 2 == 3
stdmath_double3 stdmath_double3_cross(stdmath_double3 a, stdmath_double3 b);
#endif

stdmath_double2 stdmath_double2_min(stdmath_double2 a, stdmath_double2 b);
stdmath_double2 stdmath_double2_max(stdmath_double2 a, stdmath_double2 b);
stdmath_double2 stdmath_double2_normalize(stdmath_double2 v);
stdmath_double2 stdmath_double2_lerp(stdmath_double2 a, stdmath_double2 b, float t);
stdmath_double2 stdmath_double2_clamp(stdmath_double2 a, stdmath_double2 min, stdmath_double2 max);
stdmath_double2 stdmath_double2_reflect(stdmath_double2 a, stdmath_double2 b);
stdmath_bool2 stdmath_double2_approximately_equal(stdmath_double2 a, stdmath_double2 b);

#if false
bool stdmath_bool2_all_of(stdmath_bool2 v);
bool stdmath_bool2_any_of(stdmath_bool2 v);
bool stdmath_bool2_none_of(stdmath_bool2 v);
bool stdmath_bool2_some_of(stdmath_bool2 v);
#endif

inline static stdmath_double1 stdmath_double2_x(stdmath_double2 v) { return {v.x}; }
inline static stdmath_double1 stdmath_double2_x_get(stdmath_double2* p) { return stdmath_double2_x(*p); }
inline static stdmath_double2 stdmath_double2_x_set(stdmath_double2* p, stdmath_double1 value) { p->x = value.x; return *p; }
inline static stdmath_double1 stdmath_double2_y(stdmath_double2 v) { return {v.y}; }
inline static stdmath_double1 stdmath_double2_y_get(stdmath_double2* p) { return stdmath_double2_y(*p); }
inline static stdmath_double2 stdmath_double2_y_set(stdmath_double2* p, stdmath_double1 value) { p->y = value.x; return *p; }
inline static stdmath_double2 stdmath_double2_xx(stdmath_double2 v) { return {v.x,v.x}; }
inline static stdmath_double2 stdmath_double2_xx_get(stdmath_double2* p) { return stdmath_double2_xx(*p); }
inline static stdmath_double2 stdmath_double2_xx_set(stdmath_double2* p, stdmath_double2 value) { p->x = value.x; p->x = value.y; return *p; }
inline static stdmath_double2 stdmath_double2_xy(stdmath_double2 v) { return {v.x,v.y}; }
inline static stdmath_double2 stdmath_double2_xy_get(stdmath_double2* p) { return stdmath_double2_xy(*p); }
inline static stdmath_double2 stdmath_double2_xy_set(stdmath_double2* p, stdmath_double2 value) { p->x = value.x; p->y = value.y; return *p; }
inline static stdmath_double2 stdmath_double2_yx(stdmath_double2 v) { return {v.y,v.x}; }
inline static stdmath_double2 stdmath_double2_yx_get(stdmath_double2* p) { return stdmath_double2_yx(*p); }
inline static stdmath_double2 stdmath_double2_yx_set(stdmath_double2* p, stdmath_double2 value) { p->y = value.x; p->x = value.y; return *p; }
inline static stdmath_double2 stdmath_double2_yy(stdmath_double2 v) { return {v.y,v.y}; }
inline static stdmath_double2 stdmath_double2_yy_get(stdmath_double2* p) { return stdmath_double2_yy(*p); }
inline static stdmath_double2 stdmath_double2_yy_set(stdmath_double2* p, stdmath_double2 value) { p->y = value.x; p->y = value.y; return *p; }


#ifdef STDMATH_IMPLEMENTATION
#ifndef __cplusplus
#error "The stdmath implementations require a C++ compiler"
#endif

import stdmath.slang;

stdmath::double2 c(stdmath_double2 c) {
	return (stdmath::double2&)c;
}
stdmath_double2 c(stdmath::double2 c) {
	return (stdmath_double2&)c;
}

stdmath_double2 stdmath_double2_broadcast(double all) {
	return c(stdmath::double2((stdmath::double2::underlying_type)all));
}

stdmath_double2 stdmath_double2_add(stdmath_double2 a, stdmath_double2 b) {
	return c(c(a) + c(b));
}
stdmath_double2 stdmath_double2_subtract(stdmath_double2 a, stdmath_double2 b) {
	return c(c(a) - c(b));
}
stdmath_double2 stdmath_double2_negate(stdmath_double2 v) {
	return c(stdmath::double2(-(stdmath::vector<double, 2>)c(v)));
}
stdmath_double2 stdmath_double2_multiply(stdmath_double2 a, stdmath_double2 b) {
	return c(c(a) * c(b));
}
stdmath_double2 stdmath_double2_divide(stdmath_double2 a, stdmath_double2 b) {
	return c(c(a) / c(b));
}
stdmath_double2 stdmath_double2_scale(stdmath_double2 v, double s) {
	return c(c(v) * (stdmath::double2::underlying_type)s);
}

#if false
stdmath_double2 stdmath_double2_modulus(stdmath_double2 a, stdmath_double2 b) {
	return c(c(a) % c(b));
}
stdmath_double2 stdmath_double2_logical_not(stdmath_double2 v) {
	return c(!c(v));
}
stdmath_double2 stdmath_double2_bitwise_not(stdmath_double2 v) {
	return c(~c(v));
}
stdmath_double2 stdmath_double2_logical_and(stdmath_double2 a, stdmath_double2 b) {
	return c(c(a) && c(b));
}
stdmath_double2 stdmath_double2_bitwise_and(stdmath_double2 a, stdmath_double2 b) {
	return c(c(a) & c(b));
}
stdmath_double2 stdmath_double2_logical_or(stdmath_double2 a, stdmath_double2 b) {
	return c(c(a) || c(b));
}
stdmath_double2 stdmath_double2_bitwise_or(stdmath_double2 a, stdmath_double2 b) {
	return c(c(a) | c(b));
}
stdmath_double2 stdmath_double2_bitwise_xor(stdmath_double2 a, stdmath_double2 b) {
	return c(c(a) ^ c(b));
}
stdmath_double2 stdmath_double2_shift_left(stdmath_double2 a, stdmath_double2 b) {
	return c(c(a) << c(b));
}
stdmath_double2 stdmath_double2_shift_right(stdmath_double2 a, stdmath_double2 b) {
	return c(c(a) >> c(b));
}
#endif

stdmath_bool2 stdmath_double2_equal_to(stdmath_double2 a, stdmath_double2 b) {
	return c(c(a) == c(b));
}
stdmath_bool2 stdmath_double2_not_equal_to(stdmath_double2 a, stdmath_double2 b) {
	return c(c(a) != c(b));
}
stdmath_bool2 stdmath_double2_less_than(stdmath_double2 a, stdmath_double2 b) {
	return c(c(a) < c(b));
}
stdmath_bool2 stdmath_double2_less_than_or_equal_to(stdmath_double2 a, stdmath_double2 b) {
	return c(c(a) <= c(b));
}
stdmath_bool2 stdmath_double2_greater_than(stdmath_double2 a, stdmath_double2 b) {
	return c(c(a) > c(b));
}
stdmath_bool2 stdmath_double2_greater_than_or_equal_to(stdmath_double2 a, stdmath_double2 b) {
	return c(c(a) >= c(b));
}

double stdmath_double2_length_squared(stdmath_double2 v)  {
	return (double)c(v).length_squared();
}
double stdmath_double2_length(stdmath_double2 v)  {
	return (double)c(v).length();
}
double stdmath_double2_dot(stdmath_double2 a, stdmath_double2 b)  {
	return (double)dot(c(a), c(b));
}
double stdmath_double2_min_element(stdmath_double2 v)  {
	return (double)c(v).min_element();
}
double stdmath_double2_max_element(stdmath_double2 v)  {
	return (double)c(v).max_element();
}

stdmath_double2 stdmath_double2_elementwise_transform(stdmath_double2 v, double(*func)(double)) {
	return c(c(v).elementwise_transform(func));
}
// double stdmath_double2_reduce_elements(stdmath_double2 v, double initial_value, double(*reducer)(stdmath_double2, stdmath_double2)) {
// 	return c(v).reduce_elements(initial_value, reducer);
// }

#if 2 == 3
stdmath_double2 stdmath_double2_cross(stdmath_double2 a, stdmath_double2 b) {
	return c(cross(c(a), c(b)));
}
#endif

stdmath_double2 stdmath_double2_min(stdmath_double2 a, stdmath_double2 b) {
	return c(min(c(a), c(b)));
}
stdmath_double2 stdmath_double2_max(stdmath_double2 a, stdmath_double2 b) {
	return c(max(c(a), c(b)));
}
stdmath_double2 stdmath_double2_normalize(stdmath_double2 v) {
	return c(normalize(c(v)));
}
stdmath_double2 stdmath_double2_lerp(stdmath_double2 a, stdmath_double2 b, float t) {
	return c(lerp(c(a), c(b), t));
}
stdmath_double2 stdmath_double2_clamp(stdmath_double2 a, stdmath_double2 min, stdmath_double2 max) {
	return c(clamp(c(a), c(min), c(max)));
}
stdmath_double2 stdmath_double2_reflect(stdmath_double2 a, stdmath_double2 b) {
	return c(reflect(c(a), c(b)));
}
stdmath_bool2 stdmath_double2_approximately_equal(stdmath_double2 a, stdmath_double2 b) {
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

#endif // STDMATH_IMPLEMENTATION

#endif // __STDMATH_double2_H__