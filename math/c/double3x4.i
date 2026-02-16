%rename(double3x4) stdmath_double3x4;
%include "double3x4.h"

%rename(transpose) _transpose;
%rename(scale) _scale;
%rename(inverse) _inverse;
%rename(identity) _identity;
%rename(fill) _fill;

%extend stdmath_double3x4 {

	static stdmath_double3x4 _identity(double v) {
		return stdmath_double3x4_identity_scaled(v);
	}
	static stdmath_double3x4 _identity() {
		return stdmath_double3x4_identity();
	}
	static stdmath_double3x4 _fill(double v) {
		return stdmath_double3x4_fill(v);
	}

	const size_t rows;
	const size_t columns;

	size_t _size() {
		return stdmath_double3x4_size(self);
	}

	double _get_element(size_t x, size_t y) {
		return stdmath_double3x4_get_element(self, x, y);
	}
	stdmath_double3x4 _set_element(size_t x, size_t y, double value) {
		return stdmath_double3x4_set_element(self, x, y, value);
	}

	stdmath_double3x4 _add(const stdmath_double3x4* b) {
		return stdmath_double3x4_add(self, b);
	}
	stdmath_double3x4 _subtract(const stdmath_double3x4* b) {
		return stdmath_double3x4_subtract(self, b);
	}
	stdmath_double3x4 _negate() {
		return stdmath_double3x4_negate(self);
	}
	stdmath_double4x3 _transpose() {
		return stdmath_double3x4_transpose(self);
	}

	stdmath_double3x2 _multiply(const stdmath_double4x2* o) {
		return stdmath_double3x4_multiply2(self, o);
	}
	stdmath_double3x3 _multiply(const stdmath_double4x3* o) {
		return stdmath_double3x4_multiply3(self, o);
	}
	stdmath_double3x4 _multiply(const stdmath_double4x4* o) {
		return stdmath_double3x4_multiply4(self, o);
	}
	stdmath_double4 _multiply(stdmath_double4 v) {
		return stdmath_double3x4_multiply(self, v);
	}

#if 3 == 4
	stdmath_double3x3 _scale(double s) {
		return stdmath_double3x3_scale(self, s);
	}
	stdmath_double3x3 _inverse() {
		return stdmath_double3x3_inverse(self);
	}
#endif

}
