#define STDMATH_EXPORT
#define STDMATH_INLINE
%rename(degree) stdmath_degree;
%include "degree.h"

%rename(wrap) _wrap;
%rename(radian) _radian;
%rename(degree) _degree;
%rename(approximately_equal) _approximately_equal;

%extend stdmath_degree {
	stdmath_degree _add(stdmath_degree o) {
		return stdmath_degree_add(*self, o);
	}
	stdmath_degree _subtract(stdmath_degree o) {
		return stdmath_degree_subtract(*self, o);
	}
	stdmath_degree _multiply(stdmath_degree o) {
		return stdmath_degree_multiply(*self, o);
	}
	stdmath_degree _divide(stdmath_degree o) {
		return stdmath_degree_divide(*self, o);
	}
	bool _equal_to(stdmath_degree o) {
		return stdmath_degree_equal_to(*self, o);
	}
	bool _not_equal_to(stdmath_degree o) {
		return stdmath_degree_not_equal_to(*self, o);
	}
	bool _less_than(stdmath_degree o) {
		return stdmath_degree_less_than(*self, o);
	}
	bool _less_than_or_equal_to(stdmath_degree o) {
		return stdmath_degree_less_than_or_equal_to(*self, o);
	}
	bool _greater_than(stdmath_degree o) {
		return stdmath_degree_greater_than(*self, o);
	}
	bool _greater_than_or_equal_to(stdmath_degree o) {
		return stdmath_degree_greater_than_or_equal_to(*self, o);
	}

	stdmath_degree _negate() {
		return stdmath_degree_negate(*self);
	}
	stdmath_degree _wrap() {
		return stdmath_degree_wrap(*self);
	}
	stdmath_radian _radian() {
		return stdmath_degree_radian(*self);
	}
	stdmath_degree _degree() {
		return stdmath_degree_degree(*self);
	}

	bool _approximately_equal(stdmath_degree o) {
		return stdmath_degree_approximately_equal(*self, o);
	}

	float sin() {
		return sind(*self);
	}
	float cos() {
		return cosd(*self);
	}
	float tan() {
		return tand(*self);
	}
	static stdmath_degree asin(float v) {
		return asind(v);
	}
	static stdmath_degree acos(float v) {
		return acosd(v);
	}
	static stdmath_degree atan(float v) {
		return atand(v);
	}
	static stdmath_degree atan2(float y, float x) {
		return atan2d(y, x);
	}
	float sinh() {
		return sinhd(*self);
	}
	float cosh() {
		return coshd(*self);
	}
	float tanh() {
		return tanhd(*self);
	}
	static stdmath_degree asinh(float v) {
		return asinhd(v);
	}
	static stdmath_degree acosh(float v) {
		return acoshd(v);
	}
	static stdmath_degree atanh(float v) {
		return atanhd(v);
	}
}

