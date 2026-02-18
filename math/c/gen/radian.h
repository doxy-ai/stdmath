#ifndef __STDMATH_radian_H__
#define __STDMATH_radian_H__

#include "../util.h"

#ifdef __cplusplus
extern "C" {
#endif

STDMATH_EXPORT struct stdmath_radian {
	real_t value;

// #ifdef __cplusplus
// 	stdmath_radian() = default;
// 	stdmath_radian(float value) : value(value) {}
// 	stdmath_radian(const stdmath_radian&) = default;
// 	stdmath_radian(stdmath_radian&&) = default;
// 	stdmath_radian& operator=(const stdmath_radian&) = default;
// 	stdmath_radian& operator=(stdmath_radian&&) = default;
// #endif
};

STDMATH_EXPORT stdmath_radian stdmath_radian_add(stdmath_radian a, stdmath_radian b);
STDMATH_EXPORT stdmath_radian stdmath_radian_subtract(stdmath_radian a, stdmath_radian b);
STDMATH_EXPORT stdmath_radian stdmath_radian_multiply(stdmath_radian a, stdmath_radian b);
STDMATH_EXPORT stdmath_radian stdmath_radian_divide(stdmath_radian a, stdmath_radian b);
STDMATH_EXPORT bool stdmath_radian_equal_to(stdmath_radian a, stdmath_radian b);
STDMATH_EXPORT bool stdmath_radian_not_equal_to(stdmath_radian a, stdmath_radian b);
STDMATH_EXPORT bool stdmath_radian_less_than(stdmath_radian a, stdmath_radian b);
STDMATH_EXPORT bool stdmath_radian_less_than_or_equal_to(stdmath_radian a, stdmath_radian b);
STDMATH_EXPORT bool stdmath_radian_greater_than(stdmath_radian a, stdmath_radian b);
STDMATH_EXPORT bool stdmath_radian_greater_than_or_equal_to(stdmath_radian a, stdmath_radian b);

STDMATH_EXPORT stdmath_radian stdmath_radian_negate(stdmath_radian a);
STDMATH_EXPORT stdmath_radian stdmath_radian_wrap(stdmath_radian a);
STDMATH_EXPORT struct stdmath_radian stdmath_radian_radian(stdmath_radian a);
STDMATH_EXPORT struct stdmath_degree stdmath_radian_degree(stdmath_radian a);

STDMATH_EXPORT bool stdmath_radian_approximately_equal(stdmath_radian a, stdmath_radian b);

STDMATH_EXPORT float sinr(stdmath_radian a);
STDMATH_EXPORT float cosr(stdmath_radian a);
STDMATH_EXPORT float tanr(stdmath_radian a);
STDMATH_EXPORT stdmath_radian asinr(float a);
STDMATH_EXPORT stdmath_radian acosr(float a);
STDMATH_EXPORT stdmath_radian atanr(float a);
STDMATH_EXPORT stdmath_radian atan2r(float y, float x);
STDMATH_EXPORT float sinhr(stdmath_radian a);
STDMATH_EXPORT float coshr(stdmath_radian a);
STDMATH_EXPORT float tanhr(stdmath_radian a);
STDMATH_EXPORT stdmath_radian asinhr(float a);
STDMATH_EXPORT stdmath_radian acoshr(float a);
STDMATH_EXPORT stdmath_radian atanhr(float a);

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

#if true
#include "degree.h"
#else
#include "radian.h"
#endif

inline stdmath::radian c(stdmath_radian c) {
	return (stdmath::radian&)c;
}
inline stdmath_radian c(stdmath::radian c) {
	return (stdmath_radian&)c;
}

#ifdef __cplusplus
extern "C" {
#endif

stdmath_radian stdmath_radian_add(stdmath_radian a, stdmath_radian b) {
	return c(c(a) + c(b));
}
stdmath_radian stdmath_radian_subtract(stdmath_radian a, stdmath_radian b) {
	return c(c(a) - c(b));
}
stdmath_radian stdmath_radian_multiply(stdmath_radian a, stdmath_radian b) {
	return c(c(a) * c(b));
}
stdmath_radian stdmath_radian_divide(stdmath_radian a, stdmath_radian b) {
	return c(c(a) / c(b));
}
bool stdmath_radian_equal_to(stdmath_radian a, stdmath_radian b) {
	return c(a) == c(b);
}
bool stdmath_radian_not_equal_to(stdmath_radian a, stdmath_radian b) {
	return c(a) != c(b);
}
bool stdmath_radian_less_than(stdmath_radian a, stdmath_radian b) {
	return c(a) < c(b);
}
bool stdmath_radian_less_than_or_equal_to(stdmath_radian a, stdmath_radian b) {
	return c(a) <= c(b);
}
bool stdmath_radian_greater_than(stdmath_radian a, stdmath_radian b) {
	return c(a) > c(b);
}
bool stdmath_radian_greater_than_or_equal_to(stdmath_radian a, stdmath_radian b) {
	return c(a) >= c(b);
}

stdmath_radian stdmath_radian_negate(stdmath_radian a) {
	return c(-c(a));
}
stdmath_radian stdmath_radian_wrap(stdmath_radian a) {
	return c(angle_wrap(c(a)));
}
stdmath_radian stdmath_radian_radian(stdmath_radian a) {
	return {c(a).radian()};
}
stdmath_degree stdmath_radian_degree(stdmath_radian a) {
	return {c(a).degree()};
}

bool stdmath_radian_approximately_equal(stdmath_radian a, stdmath_radian b) {
	return stdmath::approximately_equal(c(a), c(b));
}

float sinr(stdmath_radian a) {
	return stdmath::sin<float>(c(a));
}
float cosr(stdmath_radian a) {
	return stdmath::cos<float>(c(a));
}
float tanr(stdmath_radian a) {
	return stdmath::tan<float>(c(a));
}
stdmath_radian asinr(float a) {
	return c(stdmath::radian(stdmath::asin(a)));
}
stdmath_radian acosr(float a) {
	return c(stdmath::radian(stdmath::acos(a)));
}
stdmath_radian atanr(float a) {
	return c(stdmath::radian(stdmath::atan(a)));
}
stdmath_radian atan2r(float y, float x) {
	return c(stdmath::radian(stdmath::atan2(y, x)));
}
float sinhr(stdmath_radian a) {
	return stdmath::sinh<float>(c(a));
}
float coshr(stdmath_radian a) {
	return stdmath::cosh<float>(c(a));
}
float tanhr(stdmath_radian a) {
	return stdmath::tanh<float>(c(a));
}
stdmath_radian asinhr(float a) {
	return c(stdmath::radian(stdmath::asinh(a)));
}
stdmath_radian acoshr(float a) {
	return c(stdmath::radian(stdmath::acosh(a)));
}
stdmath_radian atanhr(float a) {
	return c(stdmath::radian(stdmath::atanh(a)));
}

#ifdef __cplusplus
} // extern "C"
#endif

#endif // STDMATH_IMPLEMENTATION

#endif // __STDMATH_stdmath_radian_H__