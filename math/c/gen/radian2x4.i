#define STDMATH_EXPORT
#define STDMATH_INLINE
%rename(radian2x4) stdmath_radian2x4;
%include "radian2x4.h"

%rename(transpose) _transpose;
%rename(scale) _scale;
%rename(inverse) _inverse;
%rename(identity) _identity;
%rename(fill) _fill;
%rename(approximately_equal) _approximately_equal;

%extend stdmath_radian2x4 {

	static stdmath_radian2x4 _identity(stdmath_radian v) {
		return stdmath_radian2x4_identity_scaled(v);
	}
	static stdmath_radian2x4 _identity() {
		return stdmath_radian2x4_identity();
	}
	static stdmath_radian2x4 _fill(stdmath_radian v) {
		return stdmath_radian2x4_fill(v);
	}

	const size_t rows;
	const size_t columns;

	size_t _size() {
		return stdmath_radian2x4_size(self);
	}

	stdmath_radian _get_element(size_t x, size_t y) {
		return stdmath_radian2x4_get_element(self, x, y);
	}
	stdmath_radian2x4 _set_element(size_t x, size_t y, stdmath_radian value) {
		return stdmath_radian2x4_set_element(self, x, y, value);
	}

	stdmath_radian2x4 _add(const stdmath_radian2x4* b) {
		return stdmath_radian2x4_add(self, b);
	}
	stdmath_radian2x4 _subtract(const stdmath_radian2x4* b) {
		return stdmath_radian2x4_subtract(self, b);
	}
	stdmath_radian2x4 _negate() {
		return stdmath_radian2x4_negate(self);
	}
	stdmath_radian4x2 _transpose() {
		return stdmath_radian2x4_transpose(self);
	}

	stdmath_radian2x2 _multiply(const stdmath_radian4x2* o) {
		return stdmath_radian2x4_multiply2(self, o);
	}
	stdmath_radian2x3 _multiply(const stdmath_radian4x3* o) {
		return stdmath_radian2x4_multiply3(self, o);
	}
	stdmath_radian2x4 _multiply(const stdmath_radian4x4* o) {
		return stdmath_radian2x4_multiply4(self, o);
	}
	stdmath_radian4 _multiply(stdmath_radian4 v) {
		return stdmath_radian2x4_multiply(self, v);
	}

	bool _equal_to(stdmath_radian2x4* o) {
		return stdmath_radian2x4_equal_to(self, o);
	}
	bool _not_equal_to(stdmath_radian2x4* o) {
		return stdmath_radian2x4_not_equal_to(self, o);
	}
	bool _approximately_equal(stdmath_radian2x4* o) {
		return stdmath_radian2x4_approximately_equal(self, o);
	}

#if 2 == 4
	stdmath_radian2x2 _scale(stdmath_radian s) {
		return stdmath_radian2x2_scale(self, s);
	}
	stdmath_radian2x2 _inverse() {
		return stdmath_radian2x2_inverse(self);
	}
#endif

}
