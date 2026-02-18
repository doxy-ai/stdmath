#define STDMATH_EXPORT
#define STDMATH_INLINE
%rename(radian4x2) stdmath_radian4x2;
%include "radian4x2.h"

%rename(transpose) _transpose;
%rename(scale) _scale;
%rename(inverse) _inverse;
%rename(identity) _identity;
%rename(fill) _fill;
%rename(approximately_equal) _approximately_equal;

%extend stdmath_radian4x2 {

	static stdmath_radian4x2 _identity(stdmath_radian v) {
		return stdmath_radian4x2_identity_scaled(v);
	}
	static stdmath_radian4x2 _identity() {
		return stdmath_radian4x2_identity();
	}
	static stdmath_radian4x2 _fill(stdmath_radian v) {
		return stdmath_radian4x2_fill(v);
	}

	const size_t rows;
	const size_t columns;

	size_t _size() {
		return stdmath_radian4x2_size(self);
	}

	stdmath_radian _get_element(size_t x, size_t y) {
		return stdmath_radian4x2_get_element(self, x, y);
	}
	stdmath_radian4x2 _set_element(size_t x, size_t y, stdmath_radian value) {
		return stdmath_radian4x2_set_element(self, x, y, value);
	}

	stdmath_radian4x2 _add(const stdmath_radian4x2* b) {
		return stdmath_radian4x2_add(self, b);
	}
	stdmath_radian4x2 _subtract(const stdmath_radian4x2* b) {
		return stdmath_radian4x2_subtract(self, b);
	}
	stdmath_radian4x2 _negate() {
		return stdmath_radian4x2_negate(self);
	}
	stdmath_radian2x4 _transpose() {
		return stdmath_radian4x2_transpose(self);
	}

	stdmath_radian4x2 _multiply(const stdmath_radian2x2* o) {
		return stdmath_radian4x2_multiply2(self, o);
	}
	stdmath_radian4x3 _multiply(const stdmath_radian2x3* o) {
		return stdmath_radian4x2_multiply3(self, o);
	}
	stdmath_radian4x4 _multiply(const stdmath_radian2x4* o) {
		return stdmath_radian4x2_multiply4(self, o);
	}
	stdmath_radian2 _multiply(stdmath_radian2 v) {
		return stdmath_radian4x2_multiply(self, v);
	}

	bool _equal_to(stdmath_radian4x2* o) {
		return stdmath_radian4x2_equal_to(self, o);
	}
	bool _not_equal_to(stdmath_radian4x2* o) {
		return stdmath_radian4x2_not_equal_to(self, o);
	}
	bool _approximately_equal(stdmath_radian4x2* o) {
		return stdmath_radian4x2_approximately_equal(self, o);
	}

#if 4 == 2
	stdmath_radian4x4 _scale(stdmath_radian s) {
		return stdmath_radian4x4_scale(self, s);
	}
	stdmath_radian4x4 _inverse() {
		return stdmath_radian4x4_inverse(self);
	}
#endif

}
