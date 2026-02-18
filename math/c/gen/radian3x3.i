#define STDMATH_EXPORT
#define STDMATH_INLINE
%rename(radian3x3) stdmath_radian3x3;
%include "radian3x3.h"

%rename(transpose) _transpose;
%rename(scale) _scale;
%rename(inverse) _inverse;
%rename(identity) _identity;
%rename(fill) _fill;
%rename(approximately_equal) _approximately_equal;

%extend stdmath_radian3x3 {

	static stdmath_radian3x3 _identity(stdmath_radian v) {
		return stdmath_radian3x3_identity_scaled(v);
	}
	static stdmath_radian3x3 _identity() {
		return stdmath_radian3x3_identity();
	}
	static stdmath_radian3x3 _fill(stdmath_radian v) {
		return stdmath_radian3x3_fill(v);
	}

	const size_t rows;
	const size_t columns;

	size_t _size() {
		return stdmath_radian3x3_size(self);
	}

	stdmath_radian _get_element(size_t x, size_t y) {
		return stdmath_radian3x3_get_element(self, x, y);
	}
	stdmath_radian3x3 _set_element(size_t x, size_t y, stdmath_radian value) {
		return stdmath_radian3x3_set_element(self, x, y, value);
	}

	stdmath_radian3x3 _add(const stdmath_radian3x3* b) {
		return stdmath_radian3x3_add(self, b);
	}
	stdmath_radian3x3 _subtract(const stdmath_radian3x3* b) {
		return stdmath_radian3x3_subtract(self, b);
	}
	stdmath_radian3x3 _negate() {
		return stdmath_radian3x3_negate(self);
	}
	stdmath_radian3x3 _transpose() {
		return stdmath_radian3x3_transpose(self);
	}

	stdmath_radian3x2 _multiply(const stdmath_radian3x2* o) {
		return stdmath_radian3x3_multiply2(self, o);
	}
	stdmath_radian3x3 _multiply(const stdmath_radian3x3* o) {
		return stdmath_radian3x3_multiply3(self, o);
	}
	stdmath_radian3x4 _multiply(const stdmath_radian3x4* o) {
		return stdmath_radian3x3_multiply4(self, o);
	}
	stdmath_radian3 _multiply(stdmath_radian3 v) {
		return stdmath_radian3x3_multiply(self, v);
	}

	bool _equal_to(stdmath_radian3x3* o) {
		return stdmath_radian3x3_equal_to(self, o);
	}
	bool _not_equal_to(stdmath_radian3x3* o) {
		return stdmath_radian3x3_not_equal_to(self, o);
	}
	bool _approximately_equal(stdmath_radian3x3* o) {
		return stdmath_radian3x3_approximately_equal(self, o);
	}

#if 3 == 3
	stdmath_radian3x3 _scale(stdmath_radian s) {
		return stdmath_radian3x3_scale(self, s);
	}
	stdmath_radian3x3 _inverse() {
		return stdmath_radian3x3_inverse(self);
	}
#endif

}
