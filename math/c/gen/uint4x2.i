#define STDMATH_EXPORT
#define STDMATH_INLINE
%rename(uint4x2) stdmath_uint4x2;
%include "uint4x2.h"

%rename(transpose) _transpose;
%rename(scale) _scale;
%rename(inverse) _inverse;
%rename(identity) _identity;
%rename(fill) _fill;
%rename(approximately_equal) _approximately_equal;

%extend stdmath_uint4x2 {

	static stdmath_uint4x2 _identity(uint32_t v) {
		return stdmath_uint4x2_identity_scaled(v);
	}
	static stdmath_uint4x2 _identity() {
		return stdmath_uint4x2_identity();
	}
	static stdmath_uint4x2 _fill(uint32_t v) {
		return stdmath_uint4x2_fill(v);
	}

	const size_t rows;
	const size_t columns;

	size_t _size() {
		return stdmath_uint4x2_size(self);
	}

	uint32_t _get_element(size_t x, size_t y) {
		return stdmath_uint4x2_get_element(self, x, y);
	}
	stdmath_uint4x2 _set_element(size_t x, size_t y, uint32_t value) {
		return stdmath_uint4x2_set_element(self, x, y, value);
	}

	stdmath_uint4x2 _add(const stdmath_uint4x2* b) {
		return stdmath_uint4x2_add(self, b);
	}
	stdmath_uint4x2 _subtract(const stdmath_uint4x2* b) {
		return stdmath_uint4x2_subtract(self, b);
	}
	stdmath_uint4x2 _negate() {
		return stdmath_uint4x2_negate(self);
	}
	stdmath_uint2x4 _transpose() {
		return stdmath_uint4x2_transpose(self);
	}

	stdmath_uint4x2 _multiply(const stdmath_uint2x2* o) {
		return stdmath_uint4x2_multiply2(self, o);
	}
	stdmath_uint4x3 _multiply(const stdmath_uint2x3* o) {
		return stdmath_uint4x2_multiply3(self, o);
	}
	stdmath_uint4x4 _multiply(const stdmath_uint2x4* o) {
		return stdmath_uint4x2_multiply4(self, o);
	}
	stdmath_uint2 _multiply(stdmath_uint2 v) {
		return stdmath_uint4x2_multiply(self, v);
	}

	bool _equal_to(stdmath_uint4x2* o) {
		return stdmath_uint4x2_equal_to(self, o);
	}
	bool _not_equal_to(stdmath_uint4x2* o) {
		return stdmath_uint4x2_not_equal_to(self, o);
	}
	bool _approximately_equal(stdmath_uint4x2* o) {
		return stdmath_uint4x2_approximately_equal(self, o);
	}

#if 4 == 2
	stdmath_uint4x4 _scale(uint32_t s) {
		return stdmath_uint4x4_scale(self, s);
	}
	stdmath_uint4x4 _inverse() {
		return stdmath_uint4x4_inverse(self);
	}
#endif

}
