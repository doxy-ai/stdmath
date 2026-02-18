#define STDMATH_EXPORT
#define STDMATH_INLINE
%rename(byte3x4) stdmath_byte3x4;
%include "byte3x4.h"

%rename(transpose) _transpose;
%rename(scale) _scale;
%rename(inverse) _inverse;
%rename(identity) _identity;
%rename(fill) _fill;
%rename(approximately_equal) _approximately_equal;

%extend stdmath_byte3x4 {

	static stdmath_byte3x4 _identity(uint8_t v) {
		return stdmath_byte3x4_identity_scaled(v);
	}
	static stdmath_byte3x4 _identity() {
		return stdmath_byte3x4_identity();
	}
	static stdmath_byte3x4 _fill(uint8_t v) {
		return stdmath_byte3x4_fill(v);
	}

	const size_t rows;
	const size_t columns;

	size_t _size() {
		return stdmath_byte3x4_size(self);
	}

	uint8_t _get_element(size_t x, size_t y) {
		return stdmath_byte3x4_get_element(self, x, y);
	}
	stdmath_byte3x4 _set_element(size_t x, size_t y, uint8_t value) {
		return stdmath_byte3x4_set_element(self, x, y, value);
	}

	stdmath_byte3x4 _add(const stdmath_byte3x4* b) {
		return stdmath_byte3x4_add(self, b);
	}
	stdmath_byte3x4 _subtract(const stdmath_byte3x4* b) {
		return stdmath_byte3x4_subtract(self, b);
	}
	stdmath_byte3x4 _negate() {
		return stdmath_byte3x4_negate(self);
	}
	stdmath_byte4x3 _transpose() {
		return stdmath_byte3x4_transpose(self);
	}

	stdmath_byte3x2 _multiply(const stdmath_byte4x2* o) {
		return stdmath_byte3x4_multiply2(self, o);
	}
	stdmath_byte3x3 _multiply(const stdmath_byte4x3* o) {
		return stdmath_byte3x4_multiply3(self, o);
	}
	stdmath_byte3x4 _multiply(const stdmath_byte4x4* o) {
		return stdmath_byte3x4_multiply4(self, o);
	}
	stdmath_byte4 _multiply(stdmath_byte4 v) {
		return stdmath_byte3x4_multiply(self, v);
	}

	bool _equal_to(stdmath_byte3x4* o) {
		return stdmath_byte3x4_equal_to(self, o);
	}
	bool _not_equal_to(stdmath_byte3x4* o) {
		return stdmath_byte3x4_not_equal_to(self, o);
	}
	bool _approximately_equal(stdmath_byte3x4* o) {
		return stdmath_byte3x4_approximately_equal(self, o);
	}

#if 3 == 4
	stdmath_byte3x3 _scale(uint8_t s) {
		return stdmath_byte3x3_scale(self, s);
	}
	stdmath_byte3x3 _inverse() {
		return stdmath_byte3x3_inverse(self);
	}
#endif

}
