%rename(int2x2) stdmath_int2x2;
%include "int2x2.h"

%rename(transpose) _transpose;
%rename(scale) _scale;
%rename(inverse) _inverse;
%rename(identity) _identity;
%rename(fill) _fill;

%extend stdmath_int2x2 {

	static stdmath_int2x2 _identity(int32_t v) {
		return stdmath_int2x2_identity_scaled(v);
	}
	static stdmath_int2x2 _identity() {
		return stdmath_int2x2_identity();
	}
	static stdmath_int2x2 _fill(int32_t v) {
		return stdmath_int2x2_fill(v);
	}

	const size_t rows;
	const size_t columns;

	size_t _size() {
		return stdmath_int2x2_size(self);
	}

	int32_t _get_element(size_t x, size_t y) {
		return stdmath_int2x2_get_element(self, x, y);
	}
	stdmath_int2x2 _set_element(size_t x, size_t y, int32_t value) {
		return stdmath_int2x2_set_element(self, x, y, value);
	}

	stdmath_int2x2 _add(const stdmath_int2x2* b) {
		return stdmath_int2x2_add(self, b);
	}
	stdmath_int2x2 _subtract(const stdmath_int2x2* b) {
		return stdmath_int2x2_subtract(self, b);
	}
	stdmath_int2x2 _negate() {
		return stdmath_int2x2_negate(self);
	}
	stdmath_int2x2 _transpose() {
		return stdmath_int2x2_transpose(self);
	}

	stdmath_int2x2 _multiply(const stdmath_int2x2* o) {
		return stdmath_int2x2_multiply2(self, o);
	}
	stdmath_int2x3 _multiply(const stdmath_int2x3* o) {
		return stdmath_int2x2_multiply3(self, o);
	}
	stdmath_int2x4 _multiply(const stdmath_int2x4* o) {
		return stdmath_int2x2_multiply4(self, o);
	}
	stdmath_int2 _multiply(stdmath_int2 v) {
		return stdmath_int2x2_multiply(self, v);
	}

#if 2 == 2
	stdmath_int2x2 _scale(int32_t s) {
		return stdmath_int2x2_scale(self, s);
	}
	stdmath_int2x2 _inverse() {
		return stdmath_int2x2_inverse(self);
	}
#endif

}
