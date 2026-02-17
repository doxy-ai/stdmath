#define STDMATH_EXPORT
#define STDMATH_INLINE
%rename(uint2x3) stdmath_uint2x3;
%include "uint2x3.h"

%rename(transpose) _transpose;
%rename(scale) _scale;
%rename(inverse) _inverse;
%rename(identity) _identity;
%rename(fill) _fill;

%extend stdmath_uint2x3 {

	static stdmath_uint2x3 _identity(uint32_t v) {
		return stdmath_uint2x3_identity_scaled(v);
	}
	static stdmath_uint2x3 _identity() {
		return stdmath_uint2x3_identity();
	}
	static stdmath_uint2x3 _fill(uint32_t v) {
		return stdmath_uint2x3_fill(v);
	}

	const size_t rows;
	const size_t columns;

	size_t _size() {
		return stdmath_uint2x3_size(self);
	}

	uint32_t _get_element(size_t x, size_t y) {
		return stdmath_uint2x3_get_element(self, x, y);
	}
	stdmath_uint2x3 _set_element(size_t x, size_t y, uint32_t value) {
		return stdmath_uint2x3_set_element(self, x, y, value);
	}

	stdmath_uint2x3 _add(const stdmath_uint2x3* b) {
		return stdmath_uint2x3_add(self, b);
	}
	stdmath_uint2x3 _subtract(const stdmath_uint2x3* b) {
		return stdmath_uint2x3_subtract(self, b);
	}
	stdmath_uint2x3 _negate() {
		return stdmath_uint2x3_negate(self);
	}
	stdmath_uint3x2 _transpose() {
		return stdmath_uint2x3_transpose(self);
	}

	stdmath_uint2x2 _multiply(const stdmath_uint3x2* o) {
		return stdmath_uint2x3_multiply2(self, o);
	}
	stdmath_uint2x3 _multiply(const stdmath_uint3x3* o) {
		return stdmath_uint2x3_multiply3(self, o);
	}
	stdmath_uint2x4 _multiply(const stdmath_uint3x4* o) {
		return stdmath_uint2x3_multiply4(self, o);
	}
	stdmath_uint3 _multiply(stdmath_uint3 v) {
		return stdmath_uint2x3_multiply(self, v);
	}

#if 2 == 3
	stdmath_uint2x2 _scale(uint32_t s) {
		return stdmath_uint2x2_scale(self, s);
	}
	stdmath_uint2x2 _inverse() {
		return stdmath_uint2x2_inverse(self);
	}
#endif

}
