#define STDMATH_EXPORT
#define STDMATH_INLINE
%rename(double2x3) stdmath_double2x3;
%include "double2x3.h"

%rename(transpose) _transpose;
%rename(scale) _scale;
%rename(inverse) _inverse;
%rename(identity) _identity;
%rename(fill) _fill;
%rename(approximately_equal) _approximately_equal;

%extend stdmath_double2x3 {

	static stdmath_double2x3 _identity(double v) {
		return stdmath_double2x3_identity_scaled(v);
	}
	static stdmath_double2x3 _identity() {
		return stdmath_double2x3_identity();
	}
	static stdmath_double2x3 _fill(double v) {
		return stdmath_double2x3_fill(v);
	}

	const size_t rows;
	const size_t columns;

	size_t _size() {
		return stdmath_double2x3_size(self);
	}

	double _get_element(size_t x, size_t y) {
		return stdmath_double2x3_get_element(self, x, y);
	}
	stdmath_double2x3 _set_element(size_t x, size_t y, double value) {
		return stdmath_double2x3_set_element(self, x, y, value);
	}

	stdmath_double2x3 _add(const stdmath_double2x3* b) {
		return stdmath_double2x3_add(self, b);
	}
	stdmath_double2x3 _subtract(const stdmath_double2x3* b) {
		return stdmath_double2x3_subtract(self, b);
	}
	stdmath_double2x3 _negate() {
		return stdmath_double2x3_negate(self);
	}
	stdmath_double3x2 _transpose() {
		return stdmath_double2x3_transpose(self);
	}

	stdmath_double2x2 _multiply(const stdmath_double3x2* o) {
		return stdmath_double2x3_multiply2(self, o);
	}
	stdmath_double2x3 _multiply(const stdmath_double3x3* o) {
		return stdmath_double2x3_multiply3(self, o);
	}
	stdmath_double2x4 _multiply(const stdmath_double3x4* o) {
		return stdmath_double2x3_multiply4(self, o);
	}
	stdmath_double3 _multiply(stdmath_double3 v) {
		return stdmath_double2x3_multiply(self, v);
	}

	bool _equal_to(stdmath_double2x3* o) {
		return stdmath_double2x3_equal_to(self, o);
	}
	bool _not_equal_to(stdmath_double2x3* o) {
		return stdmath_double2x3_not_equal_to(self, o);
	}
	bool _approximately_equal(stdmath_double2x3* o) {
		return stdmath_double2x3_approximately_equal(self, o);
	}

#if 2 == 3
	stdmath_double2x2 _scale(double s) {
		return stdmath_double2x2_scale(self, s);
	}
	stdmath_double2x2 _inverse() {
		return stdmath_double2x2_inverse(self);
	}
#endif

}
