#ifndef __STDMATH_UTIL_H__
#define __STDMATH_UTIL_H__

bool stdmath_approximately_equal_no_default(double a, double b, double epsilon);
bool stdmath_approximately_equal(double a, double b);

#ifdef STDMATH_IMPLEMENTATION
#ifndef __cplusplus
#error "The stdmath implementations require a C++ compiler"
#endif

import stdmath.slang;

bool stdmath_approximately_equal_no_default(double a, double b, double epsilon) {
    return stdmath::approximately_equal(a, b, epsilon);
}

bool stdmath_approximately_equal(double a, double b) {
    return stdmath::approximately_equal(a, b);
}

#endif // STDMATH_IMPLEMENTATION

#endif // __STDMATH_UTIL_H__