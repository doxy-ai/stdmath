#ifndef __STDMATH_degree_H__
#define __STDMATH_degree_H__

#include "../util.h"

#ifdef __cplusplus
extern "C" {
#endif

STDMATH_EXPORT struct stdmath_degree {
	real_t value;

// #ifdef __cplusplus
// 	stdmath_degree() = default;
// 	stdmath_degree(float value) : value(value) {}
// 	stdmath_degree(const stdmath_degree&) = default;
// 	stdmath_degree(stdmath_degree&&) = default;
// 	stdmath_degree& operator=(const stdmath_degree&) = default;
// 	stdmath_degree& operator=(stdmath_degree&&) = default;
// #endif
};

STDMATH_EXPORT stdmath_degree stdmath_degree_add(stdmath_degree a, stdmath_degree b);
STDMATH_EXPORT stdmath_degree stdmath_degree_subtract(stdmath_degree a, stdmath_degree b);
STDMATH_EXPORT stdmath_degree stdmath_degree_multiply(stdmath_degree a, stdmath_degree b);
STDMATH_EXPORT stdmath_degree stdmath_degree_divide(stdmath_degree a, stdmath_degree b);
STDMATH_EXPORT bool stdmath_degree_equal_to(stdmath_degree a, stdmath_degree b);
STDMATH_EXPORT bool stdmath_degree_not_equal_to(stdmath_degree a, stdmath_degree b);
STDMATH_EXPORT bool stdmath_degree_less_than(stdmath_degree a, stdmath_degree b);
STDMATH_EXPORT bool stdmath_degree_less_than_or_equal_to(stdmath_degree a, stdmath_degree b);
STDMATH_EXPORT bool stdmath_degree_greater_than(stdmath_degree a, stdmath_degree b);
STDMATH_EXPORT bool stdmath_degree_greater_than_or_equal_to(stdmath_degree a, stdmath_degree b);

STDMATH_EXPORT stdmath_degree stdmath_degree_negate(stdmath_degree a);
STDMATH_EXPORT stdmath_degree stdmath_degree_wrap(stdmath_degree a);
STDMATH_EXPORT struct stdmath_radian stdmath_degree_radian(stdmath_degree a);
STDMATH_EXPORT struct stdmath_degree stdmath_degree_degree(stdmath_degree a);

STDMATH_EXPORT bool stdmath_degree_approximately_equal(stdmath_degree a, stdmath_degree b);

STDMATH_EXPORT float sind(stdmath_degree a);
STDMATH_EXPORT float cosd(stdmath_degree a);
STDMATH_EXPORT float tand(stdmath_degree a);
STDMATH_EXPORT stdmath_degree asind(float a);
STDMATH_EXPORT stdmath_degree acosd(float a);
STDMATH_EXPORT stdmath_degree atand(float a);
STDMATH_EXPORT stdmath_degree atan2d(float y, float x);
STDMATH_EXPORT float sinhd(stdmath_degree a);
STDMATH_EXPORT float coshd(stdmath_degree a);
STDMATH_EXPORT float tanhd(stdmath_degree a);
STDMATH_EXPORT stdmath_degree asinhd(float a);
STDMATH_EXPORT stdmath_degree acoshd(float a);
STDMATH_EXPORT stdmath_degree atanhd(float a);

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

#if false
#include "degree.h"
#else
#include "radian.h"
#endif

inline stdmath::degree c(stdmath_degree c) {
	return (stdmath::degree&)c;
}
inline stdmath_degree c(stdmath::degree c) {
	return (stdmath_degree&)c;
}

#ifdef __cplusplus
extern "C" {
#endif

stdmath_degree stdmath_degree_add(stdmath_degree a, stdmath_degree b) {
	return c(c(a) + c(b));
}
stdmath_degree stdmath_degree_subtract(stdmath_degree a, stdmath_degree b) {
	return c(c(a) - c(b));
}
stdmath_degree stdmath_degree_multiply(stdmath_degree a, stdmath_degree b) {
	return c(c(a) * c(b));
}
stdmath_degree stdmath_degree_divide(stdmath_degree a, stdmath_degree b) {
	return c(c(a) / c(b));
}
bool stdmath_degree_equal_to(stdmath_degree a, stdmath_degree b) {
	return c(a) == c(b);
}
bool stdmath_degree_not_equal_to(stdmath_degree a, stdmath_degree b) {
	return c(a) != c(b);
}
bool stdmath_degree_less_than(stdmath_degree a, stdmath_degree b) {
	return c(a) < c(b);
}
bool stdmath_degree_less_than_or_equal_to(stdmath_degree a, stdmath_degree b) {
	return c(a) <= c(b);
}
bool stdmath_degree_greater_than(stdmath_degree a, stdmath_degree b) {
	return c(a) > c(b);
}
bool stdmath_degree_greater_than_or_equal_to(stdmath_degree a, stdmath_degree b) {
	return c(a) >= c(b);
}

stdmath_degree stdmath_degree_negate(stdmath_degree a) {
	return c(-c(a));
}
stdmath_degree stdmath_degree_wrap(stdmath_degree a) {
	return c(angle_wrap(c(a)));
}
stdmath_radian stdmath_degree_radian(stdmath_degree a) {
	return {c(a).radian()};
}
stdmath_degree stdmath_degree_degree(stdmath_degree a) {
	return {c(a).degree()};
}

bool stdmath_degree_approximately_equal(stdmath_degree a, stdmath_degree b) {
	return stdmath::approximately_equal(c(a), c(b));
}

float sind(stdmath_degree a) {
	return stdmath::sin<float>(c(a));
}
float cosd(stdmath_degree a) {
	return stdmath::cos<float>(c(a));
}
float tand(stdmath_degree a) {
	return stdmath::tan<float>(c(a));
}
stdmath_degree asind(float a) {
	return c(stdmath::degree(stdmath::asin(a)));
}
stdmath_degree acosd(float a) {
	return c(stdmath::degree(stdmath::acos(a)));
}
stdmath_degree atand(float a) {
	return c(stdmath::degree(stdmath::atan(a)));
}
stdmath_degree atan2d(float y, float x) {
	return c(stdmath::degree(stdmath::atan2(y, x)));
}
float sinhd(stdmath_degree a) {
	return stdmath::sinh<float>(c(a));
}
float coshd(stdmath_degree a) {
	return stdmath::cosh<float>(c(a));
}
float tanhd(stdmath_degree a) {
	return stdmath::tanh<float>(c(a));
}
stdmath_degree asinhd(float a) {
	return c(stdmath::degree(stdmath::asinh(a)));
}
stdmath_degree acoshd(float a) {
	return c(stdmath::degree(stdmath::acosh(a)));
}
stdmath_degree atanhd(float a) {
	return c(stdmath::degree(stdmath::atanh(a)));
}

#ifdef __cplusplus
} // extern "C"
#endif

#endif // STDMATH_IMPLEMENTATION

#endif // __STDMATH_stdmath_degree_H__