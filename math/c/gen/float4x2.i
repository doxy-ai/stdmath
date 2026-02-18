#define STDMATH_EXPORT
#define STDMATH_INLINE
%rename(float4x2) stdmath_float4x2;
%include "float4x2.h"

%rename(transpose) _transpose;
%rename(scale) _scale;
%rename(inverse) _inverse;
%rename(identity) _identity;
%rename(fill) _fill;
%rename(approximately_equal) _approximately_equal;

%extend stdmath_float4x2 {

	static stdmath_float4x2 _identity(float v) {
		return stdmath_float4x2_identity_scaled(v);
	}
	static stdmath_float4x2 _identity() {
		return stdmath_float4x2_identity();
	}
	static stdmath_float4x2 _fill(float v) {
		return stdmath_float4x2_fill(v);
	}

	const size_t rows;
	const size_t columns;

	size_t _size() {
		return stdmath_float4x2_size(self);
	}

	float _get_element(size_t x, size_t y) {
		return stdmath_float4x2_get_element(self, x, y);
	}
	stdmath_float4x2 _set_element(size_t x, size_t y, float value) {
		return stdmath_float4x2_set_element(self, x, y, value);
	}

	stdmath_float4x2 _add(const stdmath_float4x2* b) {
		return stdmath_float4x2_add(self, b);
	}
	stdmath_float4x2 _subtract(const stdmath_float4x2* b) {
		return stdmath_float4x2_subtract(self, b);
	}
	stdmath_float4x2 _negate() {
		return stdmath_float4x2_negate(self);
	}
	stdmath_float2x4 _transpose() {
		return stdmath_float4x2_transpose(self);
	}

	stdmath_float4x2 _multiply(const stdmath_float2x2* o) {
		return stdmath_float4x2_multiply2(self, o);
	}
	stdmath_float4x3 _multiply(const stdmath_float2x3* o) {
		return stdmath_float4x2_multiply3(self, o);
	}
	stdmath_float4x4 _multiply(const stdmath_float2x4* o) {
		return stdmath_float4x2_multiply4(self, o);
	}
	stdmath_float2 _multiply(stdmath_float2 v) {
		return stdmath_float4x2_multiply(self, v);
	}

	bool _equal_to(stdmath_float4x2* o) {
		return stdmath_float4x2_equal_to(self, o);
	}
	bool _not_equal_to(stdmath_float4x2* o) {
		return stdmath_float4x2_not_equal_to(self, o);
	}
	bool _approximately_equal(stdmath_float4x2* o) {
		return stdmath_float4x2_approximately_equal(self, o);
	}

#if 4 == 2
	stdmath_float4x4 _scale(float s) {
		return stdmath_float4x4_scale(self, s);
	}
	stdmath_float4x4 _inverse() {
		return stdmath_float4x4_inverse(self);
	}
#endif

}
