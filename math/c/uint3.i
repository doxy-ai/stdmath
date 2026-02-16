%rename(uint3) stdmath_uint3;
%include "uint3.h"

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

%extend stdmath_uint3 {
	stdmath_uint3(uint32_t broadcast) {
		stdmath_uint3 *v;
		v = (stdmath_uint3 *) malloc(sizeof(stdmath_uint3));
		*v = stdmath_uint3_broadcast(broadcast);
		return v;
	}

#if 3 == 4
	stdmath_uint3(uint32_t x = 0, uint32_t y = 0, uint32_t z = 0, uint32_t w = 0) {
		stdmath_uint3 *v;
		v = (stdmath_uint3 *) malloc(sizeof(stdmath_uint3));
		v->x = x;
		v->y = y;
		v->z = z;
		v->w = w;
		return v;
	}
#elif 3 == 3
	stdmath_uint3(uint32_t x = 0, uint32_t y = 0, uint32_t z = 0) {
		stdmath_uint3 *v;
		v = (stdmath_uint3 *) malloc(sizeof(stdmath_uint3));
		v->x = x;
		v->y = y;
		v->z = z;
		return v;
	}
#elif 3 == 2
	stdmath_uint3(uint32_t x = 0, uint32_t y = 0) {
		stdmath_uint3 *v;
		v = (stdmath_uint3 *) malloc(sizeof(stdmath_uint3));
		v->x = x;
		v->y = y;
		return v;
	}
#elif 3 == 1
	stdmath_uint3(uint32_t x = 0) {
		stdmath_uint3 *v;
		v = (stdmath_uint3 *) malloc(sizeof(stdmath_uint3));
		v->x = x;
		return v;
	}
#endif

	stdmath_uint2 xx;
	stdmath_uint2 xy;
	stdmath_uint2 xz;
	stdmath_uint2 yx;
	stdmath_uint2 yy;
	stdmath_uint2 yz;
	stdmath_uint2 zx;
	stdmath_uint2 zy;
	stdmath_uint2 zz;
	stdmath_uint3 xxx;
	stdmath_uint3 xxy;
	stdmath_uint3 xxz;
	stdmath_uint3 xyx;
	stdmath_uint3 xyy;
	stdmath_uint3 xyz;
	stdmath_uint3 xzx;
	stdmath_uint3 xzy;
	stdmath_uint3 xzz;
	stdmath_uint3 yxx;
	stdmath_uint3 yxy;
	stdmath_uint3 yxz;
	stdmath_uint3 yyx;
	stdmath_uint3 yyy;
	stdmath_uint3 yyz;
	stdmath_uint3 yzx;
	stdmath_uint3 yzy;
	stdmath_uint3 yzz;
	stdmath_uint3 zxx;
	stdmath_uint3 zxy;
	stdmath_uint3 zxz;
	stdmath_uint3 zyx;
	stdmath_uint3 zyy;
	stdmath_uint3 zyz;
	stdmath_uint3 zzx;
	stdmath_uint3 zzy;
	stdmath_uint3 zzz;


	stdmath_uint3 _add(stdmath_uint3 o) {
		return stdmath_uint3_add(*self, o);
	}
	stdmath_uint3 _subtract(stdmath_uint3 o) {
		return stdmath_uint3_subtract(*self, o);
	}
	stdmath_uint3 _negate() {
		return stdmath_uint3_negate(*self);
	}
	stdmath_uint3 _multiply(stdmath_uint3 o) {
		return stdmath_uint3_multiply(*self, o);
	}
	stdmath_uint3 _divide(stdmath_uint3 o) {
		return stdmath_uint3_divide(*self, o);
	}
	stdmath_uint3 _scale(uint32_t o) {
		return stdmath_uint3_scale(*self, o);
	}

#if false
	stdmath_uint3 _modulus(stdmath_uint3 o) {
		return stdmath_uint3_modulus(*self, o);
	}
	stdmath_uint3 _logical_not() {
		return stdmath_uint3_logical_not(*self);
	}
	stdmath_uint3 _bitwise_not() {
		return stdmath_uint3_bitwise_not(*self);
	}
	stdmath_uint3 _logical_and(stdmath_uint3 o) {
		return stdmath_uint3_logical_and(*self, o);
	}
	stdmath_uint3 _bitwise_and(stdmath_uint3 o) {
		return stdmath_uint3_bitwise_and(*self, o);
	}
	stdmath_uint3 _logical_or(stdmath_uint3 o) {
		return stdmath_uint3_logical_or(*self, o);
	}
	stdmath_uint3 _bitwise_or(stdmath_uint3 o) {
		return stdmath_uint3_bitwise_or(*self, o);
	}
	stdmath_uint3 _bitwise_xor(stdmath_uint3 o) {
		return stdmath_uint3_bitwise_xor(*self, o);
	}
	stdmath_uint3 _shift_left(stdmath_uint3 o) {
		return stdmath_uint3_shift_left(*self, o);
	}
	stdmath_uint3 _shift_right(stdmath_uint3 o) {
		return stdmath_uint3_shift_right(*self, o);
	}
#endif

	stdmath_bool3 _equal_to(stdmath_uint3 o) {
		return stdmath_uint3_equal_to(*self, o);
	}
	stdmath_bool3 _not_equal_to(stdmath_uint3 o) {
		return stdmath_uint3_not_equal_to(*self, o);
	}
	stdmath_bool3 _less_than(stdmath_uint3 o) {
		return stdmath_uint3_less_than(*self, o);
	}
	stdmath_bool3 _less_than_or_equal_to(stdmath_uint3 o) {
		return stdmath_uint3_less_than_or_equal_to(*self, o);
	}
	stdmath_bool3 _greater_than(stdmath_uint3 o) {
		return stdmath_uint3_greater_than(*self, o);
	}
	stdmath_bool3 _greater_than_or_equal_to(stdmath_uint3 o) {
		return stdmath_uint3_greater_than_or_equal_to(*self, o);
	}

	uint32_t _length_squared() {
		return stdmath_uint3_length_squared(*self);
	}
	uint32_t _length() {
		return stdmath_uint3_length(*self);
	}
	uint32_t _dot(stdmath_uint3 o) {
		return stdmath_uint3_dot(*self, o);
	}
	uint32_t _min_element() {
		return stdmath_uint3_min_element(*self);
	}
	uint32_t _max_element() {
		return stdmath_uint3_max_element(*self);
	}

	// uint32_t elementwise_transform()
	// uint32_t reduce_element

	stdmath_uint3 _min(stdmath_uint3 o) {
		return stdmath_uint3_min(*self, o);
	}
	stdmath_uint3 _max(stdmath_uint3 o) {
		return stdmath_uint3_max(*self, o);
	}
	stdmath_uint3 _normalize() {
		return stdmath_uint3_normalize(*self);
	}
	stdmath_uint3 _lerp(stdmath_uint3 o, float t) {
		return stdmath_uint3_lerp(*self, o, t);
	}
	stdmath_uint3 _clamp(stdmath_uint3 min, stdmath_uint3 max) {
		return stdmath_uint3_clamp(*self, min, max);
	}
	stdmath_uint3 _reflect(stdmath_uint3 n) {
		return stdmath_uint3_reflect(*self, n);
	}
	stdmath_bool3 _approximately_equal(stdmath_uint3 o) {
		return stdmath_uint3_approximately_equal(*self, o);
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

	uint32_t _get_element(size_t i) {
		return self->data[i];
	}

	uint32_t _set_element(size_t i, uint32_t value) {
		return self->data[i] = value;
	}
}