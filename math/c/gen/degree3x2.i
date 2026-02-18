#define STDMATH_EXPORT
#define STDMATH_INLINE
%rename(degree3x2) stdmath_degree3x2;
%include "degree3x2.h"

%rename(transpose) _transpose;
%rename(scale) _scale;
%rename(inverse) _inverse;
%rename(identity) _identity;
%rename(fill) _fill;
%rename(approximately_equal) _approximately_equal;

%extend stdmath_degree3x2 {

	static stdmath_degree3x2 _identity(stdmath_degree v) {
		return stdmath_degree3x2_identity_scaled(v);
	}
	static stdmath_degree3x2 _identity() {
		return stdmath_degree3x2_identity();
	}
	static stdmath_degree3x2 _fill(stdmath_degree v) {
		return stdmath_degree3x2_fill(v);
	}

	const size_t rows;
	const size_t columns;

	size_t _size() {
		return stdmath_degree3x2_size(self);
	}

	stdmath_degree _get_element(size_t x, size_t y) {
		return stdmath_degree3x2_get_element(self, x, y);
	}
	stdmath_degree3x2 _set_element(size_t x, size_t y, stdmath_degree value) {
		return stdmath_degree3x2_set_element(self, x, y, value);
	}

	stdmath_degree3x2 _add(const stdmath_degree3x2* b) {
		return stdmath_degree3x2_add(self, b);
	}
	stdmath_degree3x2 _subtract(const stdmath_degree3x2* b) {
		return stdmath_degree3x2_subtract(self, b);
	}
	stdmath_degree3x2 _negate() {
		return stdmath_degree3x2_negate(self);
	}
	stdmath_degree2x3 _transpose() {
		return stdmath_degree3x2_transpose(self);
	}

	stdmath_degree3x2 _multiply(const stdmath_degree2x2* o) {
		return stdmath_degree3x2_multiply2(self, o);
	}
	stdmath_degree3x3 _multiply(const stdmath_degree2x3* o) {
		return stdmath_degree3x2_multiply3(self, o);
	}
	stdmath_degree3x4 _multiply(const stdmath_degree2x4* o) {
		return stdmath_degree3x2_multiply4(self, o);
	}
	stdmath_degree2 _multiply(stdmath_degree2 v) {
		return stdmath_degree3x2_multiply(self, v);
	}

	bool _equal_to(stdmath_degree3x2* o) {
		return stdmath_degree3x2_equal_to(self, o);
	}
	bool _not_equal_to(stdmath_degree3x2* o) {
		return stdmath_degree3x2_not_equal_to(self, o);
	}
	bool _approximately_equal(stdmath_degree3x2* o) {
		return stdmath_degree3x2_approximately_equal(self, o);
	}

#if 3 == 2
	stdmath_degree3x3 _scale(stdmath_degree s) {
		return stdmath_degree3x3_scale(self, s);
	}
	stdmath_degree3x3 _inverse() {
		return stdmath_degree3x3_inverse(self);
	}
#endif

}
