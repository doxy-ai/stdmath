#define STDMATH_EXPORT
#define STDMATH_INLINE
%rename(int2x4) stdmath_int2x4;
%include "int2x4.h"

%rename(transpose) _transpose;
%rename(scale) _scale;
%rename(inverse) _inverse;
%rename(identity) _identity;
%rename(fill) _fill;

%extend stdmath_int2x4 {

	static stdmath_int2x4 _identity(int32_t v) {
		return stdmath_int2x4_identity_scaled(v);
	}
	static stdmath_int2x4 _identity() {
		return stdmath_int2x4_identity();
	}
	static stdmath_int2x4 _fill(int32_t v) {
		return stdmath_int2x4_fill(v);
	}

	const size_t rows;
	const size_t columns;

	size_t _size() {
		return stdmath_int2x4_size(self);
	}

	int32_t _get_element(size_t x, size_t y) {
		return stdmath_int2x4_get_element(self, x, y);
	}
	stdmath_int2x4 _set_element(size_t x, size_t y, int32_t value) {
		return stdmath_int2x4_set_element(self, x, y, value);
	}

	stdmath_int2x4 _add(const stdmath_int2x4* b) {
		return stdmath_int2x4_add(self, b);
	}
	stdmath_int2x4 _subtract(const stdmath_int2x4* b) {
		return stdmath_int2x4_subtract(self, b);
	}
	stdmath_int2x4 _negate() {
		return stdmath_int2x4_negate(self);
	}
	stdmath_int4x2 _transpose() {
		return stdmath_int2x4_transpose(self);
	}

	stdmath_int2x2 _multiply(const stdmath_int4x2* o) {
		return stdmath_int2x4_multiply2(self, o);
	}
	stdmath_int2x3 _multiply(const stdmath_int4x3* o) {
		return stdmath_int2x4_multiply3(self, o);
	}
	stdmath_int2x4 _multiply(const stdmath_int4x4* o) {
		return stdmath_int2x4_multiply4(self, o);
	}
	stdmath_int4 _multiply(stdmath_int4 v) {
		return stdmath_int2x4_multiply(self, v);
	}

#if 2 == 4
	stdmath_int2x2 _scale(int32_t s) {
		return stdmath_int2x2_scale(self, s);
	}
	stdmath_int2x2 _inverse() {
		return stdmath_int2x2_inverse(self);
	}
#endif

}
