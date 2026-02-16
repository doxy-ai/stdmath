%rename(int3x3) stdmath_int3x3;
%include "int3x3.h"

%rename(transpose) _transpose;
%rename(scale) _scale;
%rename(inverse) _inverse;
%rename(identity) _identity;
%rename(fill) _fill;

%extend stdmath_int3x3 {

	static stdmath_int3x3 _identity(int32_t v) {
		return stdmath_int3x3_identity_scaled(v);
	}
	static stdmath_int3x3 _identity() {
		return stdmath_int3x3_identity();
	}
	static stdmath_int3x3 _fill(int32_t v) {
		return stdmath_int3x3_fill(v);
	}

	const size_t rows;
	const size_t columns;

	size_t _size() {
		return stdmath_int3x3_size(self);
	}

	int32_t _get_element(size_t x, size_t y) {
		return stdmath_int3x3_get_element(self, x, y);
	}
	stdmath_int3x3 _set_element(size_t x, size_t y, int32_t value) {
		return stdmath_int3x3_set_element(self, x, y, value);
	}

	stdmath_int3x3 _add(const stdmath_int3x3* b) {
		return stdmath_int3x3_add(self, b);
	}
	stdmath_int3x3 _subtract(const stdmath_int3x3* b) {
		return stdmath_int3x3_subtract(self, b);
	}
	stdmath_int3x3 _negate() {
		return stdmath_int3x3_negate(self);
	}
	stdmath_int3x3 _transpose() {
		return stdmath_int3x3_transpose(self);
	}

	stdmath_int3x2 _multiply(const stdmath_int3x2* o) {
		return stdmath_int3x3_multiply2(self, o);
	}
	stdmath_int3x3 _multiply(const stdmath_int3x3* o) {
		return stdmath_int3x3_multiply3(self, o);
	}
	stdmath_int3x4 _multiply(const stdmath_int3x4* o) {
		return stdmath_int3x3_multiply4(self, o);
	}
	stdmath_int3 _multiply(stdmath_int3 v) {
		return stdmath_int3x3_multiply(self, v);
	}

#if 3 == 3
	stdmath_int3x3 _scale(int32_t s) {
		return stdmath_int3x3_scale(self, s);
	}
	stdmath_int3x3 _inverse() {
		return stdmath_int3x3_inverse(self);
	}
#endif

}
