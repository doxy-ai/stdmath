#define STDMATH_EXPORT
#define STDMATH_INLINE
%rename(uint3x4) stdmath_uint3x4;
%include "uint3x4.h"

%rename(transpose) _transpose;
%rename(scale) _scale;
%rename(inverse) _inverse;
%rename(identity) _identity;
%rename(fill) _fill;
%rename(approximately_equal) _approximately_equal;

%extend stdmath_uint3x4 {

	static stdmath_uint3x4 _identity(uint32_t v) {
		return stdmath_uint3x4_identity_scaled(v);
	}
	static stdmath_uint3x4 _identity() {
		return stdmath_uint3x4_identity();
	}
	static stdmath_uint3x4 _fill(uint32_t v) {
		return stdmath_uint3x4_fill(v);
	}

	const size_t rows;
	const size_t columns;

	size_t _size() {
		return stdmath_uint3x4_size(self);
	}

	uint32_t _get_element(size_t x, size_t y) {
		return stdmath_uint3x4_get_element(self, x, y);
	}
	stdmath_uint3x4 _set_element(size_t x, size_t y, uint32_t value) {
		return stdmath_uint3x4_set_element(self, x, y, value);
	}

	stdmath_uint3x4 _add(const stdmath_uint3x4* b) {
		return stdmath_uint3x4_add(self, b);
	}
	stdmath_uint3x4 _subtract(const stdmath_uint3x4* b) {
		return stdmath_uint3x4_subtract(self, b);
	}
	stdmath_uint3x4 _negate() {
		return stdmath_uint3x4_negate(self);
	}
	stdmath_uint4x3 _transpose() {
		return stdmath_uint3x4_transpose(self);
	}

	stdmath_uint3x2 _multiply(const stdmath_uint4x2* o) {
		return stdmath_uint3x4_multiply2(self, o);
	}
	stdmath_uint3x3 _multiply(const stdmath_uint4x3* o) {
		return stdmath_uint3x4_multiply3(self, o);
	}
	stdmath_uint3x4 _multiply(const stdmath_uint4x4* o) {
		return stdmath_uint3x4_multiply4(self, o);
	}
	stdmath_uint4 _multiply(stdmath_uint4 v) {
		return stdmath_uint3x4_multiply(self, v);
	}

	bool _equal_to(stdmath_uint3x4* o) {
		return stdmath_uint3x4_equal_to(self, o);
	}
	bool _not_equal_to(stdmath_uint3x4* o) {
		return stdmath_uint3x4_not_equal_to(self, o);
	}
	bool _approximately_equal(stdmath_uint3x4* o) {
		return stdmath_uint3x4_approximately_equal(self, o);
	}

#if 3 == 4
	stdmath_uint3x3 _scale(uint32_t s) {
		return stdmath_uint3x3_scale(self, s);
	}
	stdmath_uint3x3 _inverse() {
		return stdmath_uint3x3_inverse(self);
	}
#endif

}
