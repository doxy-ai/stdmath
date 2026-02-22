#ifndef __STDMATH_UTIL_H__
#define __STDMATH_UTIL_H__

#include "maybe_export.h"
#include <stddef.h>

#ifndef __STDMATH_REAL_T__
#define __STDMATH_REAL_T__
STDMATH_EXPORT typedef float real_t;
#endif // __STDMATH_REAL_T__

#ifndef __STDMATH_STRING_VIEW_T__
#define __STDMATH_STRING_VIEW_T__
STDMATH_EXPORT struct stdmath_string_view { const char* data; size_t len; };
#endif // __STDMATH_STRING_VIEW_T__

STDMATH_EXPORT bool stdmath_approximately_equal_no_default(double a, double b, double epsilon);
STDMATH_EXPORT bool stdmath_approximately_equal(double a, double b);

#ifdef STDMATH_IMPLEMENTATION
#ifndef __cplusplus
#error "The stdmath implementations require a C++ compiler"
#endif

#ifndef STDMATH_MODULE
import stdmath.slang;
#endif

bool stdmath_approximately_equal_no_default(double a, double b, double epsilon) {
    return stdmath::approximately_equal(a, b, epsilon);
}

bool stdmath_approximately_equal(double a, double b) {
    return stdmath::approximately_equal(a, b);
}

#endif // STDMATH_IMPLEMENTATION

#endif // __STDMATH_UTIL_H__