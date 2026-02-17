#define STDMATH_EXPORT
#define STDMATH_INLINE
%rename(float4x4) stdmath_float4x4;
%include "float4x4.h"

%rename(transpose) _transpose;
%rename(scale) _scale;
%rename(inverse) _inverse;
%rename(identity) _identity;
%rename(fill) _fill;

%extend stdmath_float4x4 {

	static stdmath_float4x4 _identity(float v) {
		return stdmath_float4x4_identity_scaled(v);
	}
	static stdmath_float4x4 _identity() {
		return stdmath_float4x4_identity();
	}
	static stdmath_float4x4 _fill(float v) {
		return stdmath_float4x4_fill(v);
	}

	const size_t rows;
	const size_t columns;

	size_t _size() {
		return stdmath_float4x4_size(self);
	}

	float _get_element(size_t x, size_t y) {
		return stdmath_float4x4_get_element(self, x, y);
	}
	stdmath_float4x4 _set_element(size_t x, size_t y, float value) {
		return stdmath_float4x4_set_element(self, x, y, value);
	}

	stdmath_float4x4 _add(const stdmath_float4x4* b) {
		return stdmath_float4x4_add(self, b);
	}
	stdmath_float4x4 _subtract(const stdmath_float4x4* b) {
		return stdmath_float4x4_subtract(self, b);
	}
	stdmath_float4x4 _negate() {
		return stdmath_float4x4_negate(self);
	}
	stdmath_float4x4 _transpose() {
		return stdmath_float4x4_transpose(self);
	}

	stdmath_float4x2 _multiply(const stdmath_float4x2* o) {
		return stdmath_float4x4_multiply2(self, o);
	}
	stdmath_float4x3 _multiply(const stdmath_float4x3* o) {
		return stdmath_float4x4_multiply3(self, o);
	}
	stdmath_float4x4 _multiply(const stdmath_float4x4* o) {
		return stdmath_float4x4_multiply4(self, o);
	}
	stdmath_float4 _multiply(stdmath_float4 v) {
		return stdmath_float4x4_multiply(self, v);
	}

#if 4 == 4
	stdmath_float4x4 _scale(float s) {
		return stdmath_float4x4_scale(self, s);
	}
	stdmath_float4x4 _inverse() {
		return stdmath_float4x4_inverse(self);
	}
#endif

}
