%rename(bool3x2) stdmath_bool3x2;
%include "bool3x2.h"

%rename(transpose) _transpose;
%rename(scale) _scale;
%rename(inverse) _inverse;
%rename(identity) _identity;
%rename(fill) _fill;

%extend stdmath_bool3x2 {

	static stdmath_bool3x2 _identity(bool v) {
		return stdmath_bool3x2_identity_scaled(v);
	}
	static stdmath_bool3x2 _identity() {
		return stdmath_bool3x2_identity();
	}
	static stdmath_bool3x2 _fill(bool v) {
		return stdmath_bool3x2_fill(v);
	}

	const size_t rows;
	const size_t columns;

	size_t _size() {
		return stdmath_bool3x2_size(self);
	}

	bool _get_element(size_t x, size_t y) {
		return stdmath_bool3x2_get_element(self, x, y);
	}
	stdmath_bool3x2 _set_element(size_t x, size_t y, bool value) {
		return stdmath_bool3x2_set_element(self, x, y, value);
	}

	stdmath_bool3x2 _add(const stdmath_bool3x2* b) {
		return stdmath_bool3x2_add(self, b);
	}
	stdmath_bool3x2 _subtract(const stdmath_bool3x2* b) {
		return stdmath_bool3x2_subtract(self, b);
	}
	stdmath_bool3x2 _negate() {
		return stdmath_bool3x2_negate(self);
	}
	stdmath_bool2x3 _transpose() {
		return stdmath_bool3x2_transpose(self);
	}

	stdmath_bool3x2 _multiply(const stdmath_bool2x2* o) {
		return stdmath_bool3x2_multiply2(self, o);
	}
	stdmath_bool3x3 _multiply(const stdmath_bool2x3* o) {
		return stdmath_bool3x2_multiply3(self, o);
	}
	stdmath_bool3x4 _multiply(const stdmath_bool2x4* o) {
		return stdmath_bool3x2_multiply4(self, o);
	}
	stdmath_bool2 _multiply(stdmath_bool2 v) {
		return stdmath_bool3x2_multiply(self, v);
	}

#if 3 == 2
	stdmath_bool3x3 _scale(bool s) {
		return stdmath_bool3x3_scale(self, s);
	}
	stdmath_bool3x3 _inverse() {
		return stdmath_bool3x3_inverse(self);
	}
#endif

}
