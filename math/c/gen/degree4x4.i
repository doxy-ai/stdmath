#define STDMATH_EXPORT
#define STDMATH_INLINE
%rename(degree4x4) stdmath_degree4x4;
%include "degree4x4.h"

%rename(transpose) _transpose;
%rename(scale) _scale;
%rename(inverse) _inverse;
%rename(identity) _identity;
%rename(fill) _fill;
%rename(approximately_equal) _approximately_equal;

%extend stdmath_degree4x4 {

	static stdmath_degree4x4 _identity(stdmath_degree v) {
		return stdmath_degree4x4_identity_scaled(v);
	}
	static stdmath_degree4x4 _identity() {
		return stdmath_degree4x4_identity();
	}
	static stdmath_degree4x4 _fill(stdmath_degree v) {
		return stdmath_degree4x4_fill(v);
	}

	const size_t rows;
	const size_t columns;

	size_t _size() {
		return stdmath_degree4x4_size(self);
	}

	stdmath_degree _get_element(size_t x, size_t y) {
		return stdmath_degree4x4_get_element(self, x, y);
	}
	stdmath_degree4x4 _set_element(size_t x, size_t y, stdmath_degree value) {
		return stdmath_degree4x4_set_element(self, x, y, value);
	}

	stdmath_degree4x4 _add(const stdmath_degree4x4* b) {
		return stdmath_degree4x4_add(self, b);
	}
	stdmath_degree4x4 _subtract(const stdmath_degree4x4* b) {
		return stdmath_degree4x4_subtract(self, b);
	}
	stdmath_degree4x4 _negate() {
		return stdmath_degree4x4_negate(self);
	}
	stdmath_degree4x4 _transpose() {
		return stdmath_degree4x4_transpose(self);
	}

	stdmath_degree4x2 _multiply(const stdmath_degree4x2* o) {
		return stdmath_degree4x4_multiply2(self, o);
	}
	stdmath_degree4x3 _multiply(const stdmath_degree4x3* o) {
		return stdmath_degree4x4_multiply3(self, o);
	}
	stdmath_degree4x4 _multiply(const stdmath_degree4x4* o) {
		return stdmath_degree4x4_multiply4(self, o);
	}
	stdmath_degree4 _multiply(stdmath_degree4 v) {
		return stdmath_degree4x4_multiply(self, v);
	}

	bool _equal_to(stdmath_degree4x4* o) {
		return stdmath_degree4x4_equal_to(self, o);
	}
	bool _not_equal_to(stdmath_degree4x4* o) {
		return stdmath_degree4x4_not_equal_to(self, o);
	}
	bool _approximately_equal(stdmath_degree4x4* o) {
		return stdmath_degree4x4_approximately_equal(self, o);
	}

#if 4 == 4
	stdmath_degree4x4 _scale(stdmath_degree s) {
		return stdmath_degree4x4_scale(self, s);
	}
	stdmath_degree4x4 _inverse() {
		return stdmath_degree4x4_inverse(self);
	}
#endif

}
