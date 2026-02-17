#define STDMATH_EXPORT
#define STDMATH_INLINE
%rename(byte4x3) stdmath_byte4x3;
%include "byte4x3.h"

%rename(transpose) _transpose;
%rename(scale) _scale;
%rename(inverse) _inverse;
%rename(identity) _identity;
%rename(fill) _fill;

%extend stdmath_byte4x3 {

	static stdmath_byte4x3 _identity(uint8_t v) {
		return stdmath_byte4x3_identity_scaled(v);
	}
	static stdmath_byte4x3 _identity() {
		return stdmath_byte4x3_identity();
	}
	static stdmath_byte4x3 _fill(uint8_t v) {
		return stdmath_byte4x3_fill(v);
	}

	const size_t rows;
	const size_t columns;

	size_t _size() {
		return stdmath_byte4x3_size(self);
	}

	uint8_t _get_element(size_t x, size_t y) {
		return stdmath_byte4x3_get_element(self, x, y);
	}
	stdmath_byte4x3 _set_element(size_t x, size_t y, uint8_t value) {
		return stdmath_byte4x3_set_element(self, x, y, value);
	}

	stdmath_byte4x3 _add(const stdmath_byte4x3* b) {
		return stdmath_byte4x3_add(self, b);
	}
	stdmath_byte4x3 _subtract(const stdmath_byte4x3* b) {
		return stdmath_byte4x3_subtract(self, b);
	}
	stdmath_byte4x3 _negate() {
		return stdmath_byte4x3_negate(self);
	}
	stdmath_byte3x4 _transpose() {
		return stdmath_byte4x3_transpose(self);
	}

	stdmath_byte4x2 _multiply(const stdmath_byte3x2* o) {
		return stdmath_byte4x3_multiply2(self, o);
	}
	stdmath_byte4x3 _multiply(const stdmath_byte3x3* o) {
		return stdmath_byte4x3_multiply3(self, o);
	}
	stdmath_byte4x4 _multiply(const stdmath_byte3x4* o) {
		return stdmath_byte4x3_multiply4(self, o);
	}
	stdmath_byte3 _multiply(stdmath_byte3 v) {
		return stdmath_byte4x3_multiply(self, v);
	}

#if 4 == 3
	stdmath_byte4x4 _scale(uint8_t s) {
		return stdmath_byte4x4_scale(self, s);
	}
	stdmath_byte4x4 _inverse() {
		return stdmath_byte4x4_inverse(self);
	}
#endif

}
