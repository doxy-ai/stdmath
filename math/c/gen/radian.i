#define STDMATH_EXPORT
#define STDMATH_INLINE
%rename(radian) stdmath_radian;
%include "radian.h"

%rename(wrap) _wrap;
%rename(radian) _radian;
%rename(degree) _degree;
%rename(approximately_equal) _approximately_equal;

%extend stdmath_radian {
	stdmath_radian _add(stdmath_radian o) {
		return stdmath_radian_add(*self, o);
	}
	stdmath_radian _subtract(stdmath_radian o) {
		return stdmath_radian_subtract(*self, o);
	}
	stdmath_radian _multiply(stdmath_radian o) {
		return stdmath_radian_multiply(*self, o);
	}
	stdmath_radian _divide(stdmath_radian o) {
		return stdmath_radian_divide(*self, o);
	}
	bool _equal_to(stdmath_radian o) {
		return stdmath_radian_equal_to(*self, o);
	}
	bool _not_equal_to(stdmath_radian o) {
		return stdmath_radian_not_equal_to(*self, o);
	}
	bool _less_than(stdmath_radian o) {
		return stdmath_radian_less_than(*self, o);
	}
	bool _less_than_or_equal_to(stdmath_radian o) {
		return stdmath_radian_less_than_or_equal_to(*self, o);
	}
	bool _greater_than(stdmath_radian o) {
		return stdmath_radian_greater_than(*self, o);
	}
	bool _greater_than_or_equal_to(stdmath_radian o) {
		return stdmath_radian_greater_than_or_equal_to(*self, o);
	}

	stdmath_radian _negate() {
		return stdmath_radian_negate(*self);
	}
	stdmath_radian _wrap() {
		return stdmath_radian_wrap(*self);
	}
	stdmath_radian _radian() {
		return stdmath_radian_radian(*self);
	}
	stdmath_degree _degree() {
		return stdmath_radian_degree(*self);
	}

	bool _approximately_equal(stdmath_radian o) {
		return stdmath_radian_approximately_equal(*self, o);
	}

	float sin() {
		return sinr(*self);
	}
	float cos() {
		return cosr(*self);
	}
	float tan() {
		return tanr(*self);
	}
	static stdmath_radian asin(float v) {
		return asinr(v);
	}
	static stdmath_radian acos(float v) {
		return acosr(v);
	}
	static stdmath_radian atan(float v) {
		return atanr(v);
	}
	static stdmath_radian atan2(float y, float x) {
		return atan2r(y, x);
	}
	float sinh() {
		return sinhr(*self);
	}
	float cosh() {
		return coshr(*self);
	}
	float tanh() {
		return tanhr(*self);
	}
	static stdmath_radian asinh(float v) {
		return asinhr(v);
	}
	static stdmath_radian acosh(float v) {
		return acoshr(v);
	}
	static stdmath_radian atanh(float v) {
		return atanhr(v);
	}
}

