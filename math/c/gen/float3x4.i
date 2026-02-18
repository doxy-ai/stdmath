#define STDMATH_EXPORT
#define STDMATH_INLINE
%rename(float3x4) stdmath_float3x4;
%include "float3x4.h"

%rename(transpose) _transpose;
%rename(scale) _scale;
%rename(inverse) _inverse;
%rename(identity) _identity;
%rename(fill) _fill;
%rename(approximately_equal) _approximately_equal;

%extend stdmath_float3x4 {

	static stdmath_float3x4 _identity(float v) {
		return stdmath_float3x4_identity_scaled(v);
	}
	static stdmath_float3x4 _identity() {
		return stdmath_float3x4_identity();
	}
	static stdmath_float3x4 _fill(float v) {
		return stdmath_float3x4_fill(v);
	}

	const size_t rows;
	const size_t columns;

	size_t _size() {
		return stdmath_float3x4_size(self);
	}

	float _get_element(size_t x, size_t y) {
		return stdmath_float3x4_get_element(self, x, y);
	}
	stdmath_float3x4 _set_element(size_t x, size_t y, float value) {
		return stdmath_float3x4_set_element(self, x, y, value);
	}

	stdmath_float3x4 _add(const stdmath_float3x4* b) {
		return stdmath_float3x4_add(self, b);
	}
	stdmath_float3x4 _subtract(const stdmath_float3x4* b) {
		return stdmath_float3x4_subtract(self, b);
	}
	stdmath_float3x4 _negate() {
		return stdmath_float3x4_negate(self);
	}
	stdmath_float4x3 _transpose() {
		return stdmath_float3x4_transpose(self);
	}

	stdmath_float3x2 _multiply(const stdmath_float4x2* o) {
		return stdmath_float3x4_multiply2(self, o);
	}
	stdmath_float3x3 _multiply(const stdmath_float4x3* o) {
		return stdmath_float3x4_multiply3(self, o);
	}
	stdmath_float3x4 _multiply(const stdmath_float4x4* o) {
		return stdmath_float3x4_multiply4(self, o);
	}
	stdmath_float4 _multiply(stdmath_float4 v) {
		return stdmath_float3x4_multiply(self, v);
	}

	bool _equal_to(stdmath_float3x4* o) {
		return stdmath_float3x4_equal_to(self, o);
	}
	bool _not_equal_to(stdmath_float3x4* o) {
		return stdmath_float3x4_not_equal_to(self, o);
	}
	bool _approximately_equal(stdmath_float3x4* o) {
		return stdmath_float3x4_approximately_equal(self, o);
	}

#if 3 == 4
	stdmath_float3x3 _scale(float s) {
		return stdmath_float3x3_scale(self, s);
	}
	stdmath_float3x3 _inverse() {
		return stdmath_float3x3_inverse(self);
	}
#endif

}
