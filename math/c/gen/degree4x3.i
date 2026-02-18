#define STDMATH_EXPORT
#define STDMATH_INLINE
%rename(degree4x3) stdmath_degree4x3;
%include "degree4x3.h"

%rename(transpose) _transpose;
%rename(scale) _scale;
%rename(inverse) _inverse;
%rename(identity) _identity;
%rename(fill) _fill;
%rename(approximately_equal) _approximately_equal;

%extend stdmath_degree4x3 {

	static stdmath_degree4x3 _identity(stdmath_degree v) {
		return stdmath_degree4x3_identity_scaled(v);
	}
	static stdmath_degree4x3 _identity() {
		return stdmath_degree4x3_identity();
	}
	static stdmath_degree4x3 _fill(stdmath_degree v) {
		return stdmath_degree4x3_fill(v);
	}

	const size_t rows;
	const size_t columns;

	size_t _size() {
		return stdmath_degree4x3_size(self);
	}

	stdmath_degree _get_element(size_t x, size_t y) {
		return stdmath_degree4x3_get_element(self, x, y);
	}
	stdmath_degree4x3 _set_element(size_t x, size_t y, stdmath_degree value) {
		return stdmath_degree4x3_set_element(self, x, y, value);
	}

	stdmath_degree4x3 _add(const stdmath_degree4x3* b) {
		return stdmath_degree4x3_add(self, b);
	}
	stdmath_degree4x3 _subtract(const stdmath_degree4x3* b) {
		return stdmath_degree4x3_subtract(self, b);
	}
	stdmath_degree4x3 _negate() {
		return stdmath_degree4x3_negate(self);
	}
	stdmath_degree3x4 _transpose() {
		return stdmath_degree4x3_transpose(self);
	}

	stdmath_degree4x2 _multiply(const stdmath_degree3x2* o) {
		return stdmath_degree4x3_multiply2(self, o);
	}
	stdmath_degree4x3 _multiply(const stdmath_degree3x3* o) {
		return stdmath_degree4x3_multiply3(self, o);
	}
	stdmath_degree4x4 _multiply(const stdmath_degree3x4* o) {
		return stdmath_degree4x3_multiply4(self, o);
	}
	stdmath_degree3 _multiply(stdmath_degree3 v) {
		return stdmath_degree4x3_multiply(self, v);
	}

	bool _equal_to(stdmath_degree4x3* o) {
		return stdmath_degree4x3_equal_to(self, o);
	}
	bool _not_equal_to(stdmath_degree4x3* o) {
		return stdmath_degree4x3_not_equal_to(self, o);
	}
	bool _approximately_equal(stdmath_degree4x3* o) {
		return stdmath_degree4x3_approximately_equal(self, o);
	}

#if 4 == 3
	stdmath_degree4x4 _scale(stdmath_degree s) {
		return stdmath_degree4x4_scale(self, s);
	}
	stdmath_degree4x4 _inverse() {
		return stdmath_degree4x4_inverse(self);
	}
#endif

}
