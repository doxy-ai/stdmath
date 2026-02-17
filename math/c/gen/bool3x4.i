#define STDMATH_EXPORT
#define STDMATH_INLINE
%rename(bool3x4) stdmath_bool3x4;
%include "bool3x4.h"

%rename(transpose) _transpose;
%rename(scale) _scale;
%rename(inverse) _inverse;
%rename(identity) _identity;
%rename(fill) _fill;

%extend stdmath_bool3x4 {

	static stdmath_bool3x4 _identity(bool v) {
		return stdmath_bool3x4_identity_scaled(v);
	}
	static stdmath_bool3x4 _identity() {
		return stdmath_bool3x4_identity();
	}
	static stdmath_bool3x4 _fill(bool v) {
		return stdmath_bool3x4_fill(v);
	}

	const size_t rows;
	const size_t columns;

	size_t _size() {
		return stdmath_bool3x4_size(self);
	}

	bool _get_element(size_t x, size_t y) {
		return stdmath_bool3x4_get_element(self, x, y);
	}
	stdmath_bool3x4 _set_element(size_t x, size_t y, bool value) {
		return stdmath_bool3x4_set_element(self, x, y, value);
	}

	stdmath_bool3x4 _add(const stdmath_bool3x4* b) {
		return stdmath_bool3x4_add(self, b);
	}
	stdmath_bool3x4 _subtract(const stdmath_bool3x4* b) {
		return stdmath_bool3x4_subtract(self, b);
	}
	stdmath_bool3x4 _negate() {
		return stdmath_bool3x4_negate(self);
	}
	stdmath_bool4x3 _transpose() {
		return stdmath_bool3x4_transpose(self);
	}

	stdmath_bool3x2 _multiply(const stdmath_bool4x2* o) {
		return stdmath_bool3x4_multiply2(self, o);
	}
	stdmath_bool3x3 _multiply(const stdmath_bool4x3* o) {
		return stdmath_bool3x4_multiply3(self, o);
	}
	stdmath_bool3x4 _multiply(const stdmath_bool4x4* o) {
		return stdmath_bool3x4_multiply4(self, o);
	}
	stdmath_bool4 _multiply(stdmath_bool4 v) {
		return stdmath_bool3x4_multiply(self, v);
	}

#if 3 == 4
	stdmath_bool3x3 _scale(bool s) {
		return stdmath_bool3x3_scale(self, s);
	}
	stdmath_bool3x3 _inverse() {
		return stdmath_bool3x3_inverse(self);
	}
#endif

}
