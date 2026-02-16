%rename(float3) stdmath_float3;
%include "float3.h"

%rename(length_squared) _length_squared;
%rename(length) _length;
%rename(dot) _dot;
%rename(min_element) _min_element;
%rename(max_element) _max_element;
%rename(min) _min;
%rename(max) _max;
%rename(normalize) _normalize;
%rename(lerp) _lerp;
%rename(clamp) _clamp;
%rename(reflect) _reflect;
%rename(approximately_equal) _approximately_equal;
%rename(all_of) _all_of;
%rename(any_of) _any_of;
%rename(none_of) _none_of;
%rename(some_of) _some_of;

%extend stdmath_float3 {
	stdmath_float3(float broadcast) {
		stdmath_float3 *v;
		v = (stdmath_float3 *) malloc(sizeof(stdmath_float3));
		*v = stdmath_float3_broadcast(broadcast);
		return v;
	}

#if 3 == 4
	stdmath_float3(float x = 0, float y = 0, float z = 0, float w = 0) {
		stdmath_float3 *v;
		v = (stdmath_float3 *) malloc(sizeof(stdmath_float3));
		v->x = x;
		v->y = y;
		v->z = z;
		v->w = w;
		return v;
	}
#elif 3 == 3
	stdmath_float3(float x = 0, float y = 0, float z = 0) {
		stdmath_float3 *v;
		v = (stdmath_float3 *) malloc(sizeof(stdmath_float3));
		v->x = x;
		v->y = y;
		v->z = z;
		return v;
	}
#elif 3 == 2
	stdmath_float3(float x = 0, float y = 0) {
		stdmath_float3 *v;
		v = (stdmath_float3 *) malloc(sizeof(stdmath_float3));
		v->x = x;
		v->y = y;
		return v;
	}
#elif 3 == 1
	stdmath_float3(float x = 0) {
		stdmath_float3 *v;
		v = (stdmath_float3 *) malloc(sizeof(stdmath_float3));
		v->x = x;
		return v;
	}
#endif

	stdmath_float2 xx;
	stdmath_float2 xy;
	stdmath_float2 xz;
	stdmath_float2 yx;
	stdmath_float2 yy;
	stdmath_float2 yz;
	stdmath_float2 zx;
	stdmath_float2 zy;
	stdmath_float2 zz;
	stdmath_float3 xxx;
	stdmath_float3 xxy;
	stdmath_float3 xxz;
	stdmath_float3 xyx;
	stdmath_float3 xyy;
	stdmath_float3 xyz;
	stdmath_float3 xzx;
	stdmath_float3 xzy;
	stdmath_float3 xzz;
	stdmath_float3 yxx;
	stdmath_float3 yxy;
	stdmath_float3 yxz;
	stdmath_float3 yyx;
	stdmath_float3 yyy;
	stdmath_float3 yyz;
	stdmath_float3 yzx;
	stdmath_float3 yzy;
	stdmath_float3 yzz;
	stdmath_float3 zxx;
	stdmath_float3 zxy;
	stdmath_float3 zxz;
	stdmath_float3 zyx;
	stdmath_float3 zyy;
	stdmath_float3 zyz;
	stdmath_float3 zzx;
	stdmath_float3 zzy;
	stdmath_float3 zzz;


	stdmath_float3 _add(stdmath_float3 o) {
		return stdmath_float3_add(*self, o);
	}
	stdmath_float3 _subtract(stdmath_float3 o) {
		return stdmath_float3_subtract(*self, o);
	}
	stdmath_float3 _negate() {
		return stdmath_float3_negate(*self);
	}
	stdmath_float3 _multiply(stdmath_float3 o) {
		return stdmath_float3_multiply(*self, o);
	}
	stdmath_float3 _divide(stdmath_float3 o) {
		return stdmath_float3_divide(*self, o);
	}
	stdmath_float3 _scale(float o) {
		return stdmath_float3_scale(*self, o);
	}

#if false
	stdmath_float3 _modulus(stdmath_float3 o) {
		return stdmath_float3_modulus(*self, o);
	}
	stdmath_float3 _logical_not() {
		return stdmath_float3_logical_not(*self);
	}
	stdmath_float3 _bitwise_not() {
		return stdmath_float3_bitwise_not(*self);
	}
	stdmath_float3 _logical_and(stdmath_float3 o) {
		return stdmath_float3_logical_and(*self, o);
	}
	stdmath_float3 _bitwise_and(stdmath_float3 o) {
		return stdmath_float3_bitwise_and(*self, o);
	}
	stdmath_float3 _logical_or(stdmath_float3 o) {
		return stdmath_float3_logical_or(*self, o);
	}
	stdmath_float3 _bitwise_or(stdmath_float3 o) {
		return stdmath_float3_bitwise_or(*self, o);
	}
	stdmath_float3 _bitwise_xor(stdmath_float3 o) {
		return stdmath_float3_bitwise_xor(*self, o);
	}
	stdmath_float3 _shift_left(stdmath_float3 o) {
		return stdmath_float3_shift_left(*self, o);
	}
	stdmath_float3 _shift_right(stdmath_float3 o) {
		return stdmath_float3_shift_right(*self, o);
	}
#endif

	stdmath_bool3 _equal_to(stdmath_float3 o) {
		return stdmath_float3_equal_to(*self, o);
	}
	stdmath_bool3 _not_equal_to(stdmath_float3 o) {
		return stdmath_float3_not_equal_to(*self, o);
	}
	stdmath_bool3 _less_than(stdmath_float3 o) {
		return stdmath_float3_less_than(*self, o);
	}
	stdmath_bool3 _less_than_or_equal_to(stdmath_float3 o) {
		return stdmath_float3_less_than_or_equal_to(*self, o);
	}
	stdmath_bool3 _greater_than(stdmath_float3 o) {
		return stdmath_float3_greater_than(*self, o);
	}
	stdmath_bool3 _greater_than_or_equal_to(stdmath_float3 o) {
		return stdmath_float3_greater_than_or_equal_to(*self, o);
	}

	float _length_squared() {
		return stdmath_float3_length_squared(*self);
	}
	float _length() {
		return stdmath_float3_length(*self);
	}
	float _dot(stdmath_float3 o) {
		return stdmath_float3_dot(*self, o);
	}
	float _min_element() {
		return stdmath_float3_min_element(*self);
	}
	float _max_element() {
		return stdmath_float3_max_element(*self);
	}

	// float elementwise_transform()
	// float reduce_element

	stdmath_float3 _min(stdmath_float3 o) {
		return stdmath_float3_min(*self, o);
	}
	stdmath_float3 _max(stdmath_float3 o) {
		return stdmath_float3_max(*self, o);
	}
	stdmath_float3 _normalize() {
		return stdmath_float3_normalize(*self);
	}
	stdmath_float3 _lerp(stdmath_float3 o, float t) {
		return stdmath_float3_lerp(*self, o, t);
	}
	stdmath_float3 _clamp(stdmath_float3 min, stdmath_float3 max) {
		return stdmath_float3_clamp(*self, min, max);
	}
	stdmath_float3 _reflect(stdmath_float3 n) {
		return stdmath_float3_reflect(*self, n);
	}
	stdmath_bool3 _approximately_equal(stdmath_float3 o) {
		return stdmath_float3_approximately_equal(*self, o);
	}

#if false
	stdmath_bool3 _all_of() {
		return stdmath_bool3_all_of(*self);
	}
	stdmath_bool3 _any_of() {
		return stdmath_bool3_any_of(*self);
	}
	stdmath_bool3 _none_of() {
		return stdmath_bool3_none_of(*self);
	}
	stdmath_bool3 _some_of() {
		return stdmath_bool3_some_of(*self);
	}
#endif

	size_t _size() {
		return 3;
	}

	float _get_element(size_t i) {
		return self->data[i];
	}

	float _set_element(size_t i, float value) {
		return self->data[i] = value;
	}
}