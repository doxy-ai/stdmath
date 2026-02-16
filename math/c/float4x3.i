%rename(float4x3) stdmath_float4x3;
%include "float4x3.h"

%rename(transpose) _transpose;
%rename(scale) _scale;
%rename(inverse) _inverse;
%rename(identity) _identity;
%rename(fill) _fill;

%extend stdmath_float4x3 {

	static stdmath_float4x3 _identity(float v) {
		return stdmath_float4x3_identity_scaled(v);
	}
	static stdmath_float4x3 _identity() {
		return stdmath_float4x3_identity();
	}
	static stdmath_float4x3 _fill(float v) {
		return stdmath_float4x3_fill(v);
	}

	const size_t rows;
	const size_t columns;

	size_t _size() {
		return stdmath_float4x3_size(self);
	}

	float _get_element(size_t x, size_t y) {
		return stdmath_float4x3_get_element(self, x, y);
	}
	stdmath_float4x3 _set_element(size_t x, size_t y, float value) {
		return stdmath_float4x3_set_element(self, x, y, value);
	}

	stdmath_float4x3 _add(const stdmath_float4x3* b) {
		return stdmath_float4x3_add(self, b);
	}
	stdmath_float4x3 _subtract(const stdmath_float4x3* b) {
		return stdmath_float4x3_subtract(self, b);
	}
	stdmath_float4x3 _negate() {
		return stdmath_float4x3_negate(self);
	}
	stdmath_float3x4 _transpose() {
		return stdmath_float4x3_transpose(self);
	}

	stdmath_float4x2 _multiply(const stdmath_float3x2* o) {
		return stdmath_float4x3_multiply2(self, o);
	}
	stdmath_float4x3 _multiply(const stdmath_float3x3* o) {
		return stdmath_float4x3_multiply3(self, o);
	}
	stdmath_float4x4 _multiply(const stdmath_float3x4* o) {
		return stdmath_float4x3_multiply4(self, o);
	}
	stdmath_float3 _multiply(stdmath_float3 v) {
		return stdmath_float4x3_multiply(self, v);
	}

#if 4 == 3
	stdmath_float4x4 _scale(float s) {
		return stdmath_float4x4_scale(self, s);
	}
	stdmath_float4x4 _inverse() {
		return stdmath_float4x4_inverse(self);
	}
#endif

}
