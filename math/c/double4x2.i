%rename(double4x2) stdmath_double4x2;
%include "double4x2.h"

%rename(transpose) _transpose;
%rename(scale) _scale;
%rename(inverse) _inverse;
%rename(identity) _identity;
%rename(fill) _fill;

%extend stdmath_double4x2 {

	static stdmath_double4x2 _identity(double v) {
		return stdmath_double4x2_identity_scaled(v);
	}
	static stdmath_double4x2 _identity() {
		return stdmath_double4x2_identity();
	}
	static stdmath_double4x2 _fill(double v) {
		return stdmath_double4x2_fill(v);
	}

	const size_t rows;
	const size_t columns;

	size_t _size() {
		return stdmath_double4x2_size(self);
	}

	double _get_element(size_t x, size_t y) {
		return stdmath_double4x2_get_element(self, x, y);
	}
	stdmath_double4x2 _set_element(size_t x, size_t y, double value) {
		return stdmath_double4x2_set_element(self, x, y, value);
	}

	stdmath_double4x2 _add(const stdmath_double4x2* b) {
		return stdmath_double4x2_add(self, b);
	}
	stdmath_double4x2 _subtract(const stdmath_double4x2* b) {
		return stdmath_double4x2_subtract(self, b);
	}
	stdmath_double4x2 _negate() {
		return stdmath_double4x2_negate(self);
	}
	stdmath_double2x4 _transpose() {
		return stdmath_double4x2_transpose(self);
	}

	stdmath_double4x2 _multiply(const stdmath_double2x2* o) {
		return stdmath_double4x2_multiply2(self, o);
	}
	stdmath_double4x3 _multiply(const stdmath_double2x3* o) {
		return stdmath_double4x2_multiply3(self, o);
	}
	stdmath_double4x4 _multiply(const stdmath_double2x4* o) {
		return stdmath_double4x2_multiply4(self, o);
	}
	stdmath_double2 _multiply(stdmath_double2 v) {
		return stdmath_double4x2_multiply(self, v);
	}

#if 4 == 2
	stdmath_double4x4 _scale(double s) {
		return stdmath_double4x4_scale(self, s);
	}
	stdmath_double4x4 _inverse() {
		return stdmath_double4x4_inverse(self);
	}
#endif

}
