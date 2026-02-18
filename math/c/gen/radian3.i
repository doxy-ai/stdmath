#define STDMATH_EXPORT
#define STDMATH_INLINE
%rename(radian3) stdmath_radian3;
%include "radian3.h"

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

%extend stdmath_radian3 {
	stdmath_radian3(stdmath_radian broadcast) {
		stdmath_radian3 *v;
		v = (stdmath_radian3 *) malloc(sizeof(stdmath_radian3));
		*v = stdmath_radian3_broadcast(broadcast);
		return v;
	}

#if 3 == 4
	stdmath_radian3(stdmath_radian x = 0, stdmath_radian y = 0, stdmath_radian z = 0, stdmath_radian w = 0) {
		stdmath_radian3 *v;
		v = (stdmath_radian3 *) malloc(sizeof(stdmath_radian3));
		v->x = x;
		v->y = y;
		v->z = z;
		v->w = w;
		return v;
	}
#elif 3 == 3
	stdmath_radian3(stdmath_radian x = 0, stdmath_radian y = 0, stdmath_radian z = 0) {
		stdmath_radian3 *v;
		v = (stdmath_radian3 *) malloc(sizeof(stdmath_radian3));
		v->x = x;
		v->y = y;
		v->z = z;
		return v;
	}
#elif 3 == 2
	stdmath_radian3(stdmath_radian x = 0, stdmath_radian y = 0) {
		stdmath_radian3 *v;
		v = (stdmath_radian3 *) malloc(sizeof(stdmath_radian3));
		v->x = x;
		v->y = y;
		return v;
	}
#elif 3 == 1
	stdmath_radian3(stdmath_radian x = 0) {
		stdmath_radian3 *v;
		v = (stdmath_radian3 *) malloc(sizeof(stdmath_radian3));
		v->x = x;
		return v;
	}
#endif

#ifndef STDMATH_NO_SWIZZLES
	stdmath_radian2 xx;
	stdmath_radian2 xy;
	stdmath_radian2 xz;
	stdmath_radian2 yx;
	stdmath_radian2 yy;
	stdmath_radian2 yz;
	stdmath_radian2 zx;
	stdmath_radian2 zy;
	stdmath_radian2 zz;
	stdmath_radian3 xxx;
	stdmath_radian3 xxy;
	stdmath_radian3 xxz;
	stdmath_radian3 xyx;
	stdmath_radian3 xyy;
	stdmath_radian3 xyz;
	stdmath_radian3 xzx;
	stdmath_radian3 xzy;
	stdmath_radian3 xzz;
	stdmath_radian3 yxx;
	stdmath_radian3 yxy;
	stdmath_radian3 yxz;
	stdmath_radian3 yyx;
	stdmath_radian3 yyy;
	stdmath_radian3 yyz;
	stdmath_radian3 yzx;
	stdmath_radian3 yzy;
	stdmath_radian3 yzz;
	stdmath_radian3 zxx;
	stdmath_radian3 zxy;
	stdmath_radian3 zxz;
	stdmath_radian3 zyx;
	stdmath_radian3 zyy;
	stdmath_radian3 zyz;
	stdmath_radian3 zzx;
	stdmath_radian3 zzy;
	stdmath_radian3 zzz;

#endif

	stdmath_radian3 _add(stdmath_radian3 o) {
		return stdmath_radian3_add(*self, o);
	}
	stdmath_radian3 _subtract(stdmath_radian3 o) {
		return stdmath_radian3_subtract(*self, o);
	}
	stdmath_radian3 _negate() {
		return stdmath_radian3_negate(*self);
	}
	stdmath_radian3 _multiply(stdmath_radian3 o) {
		return stdmath_radian3_multiply(*self, o);
	}
	stdmath_radian3 _divide(stdmath_radian3 o) {
		return stdmath_radian3_divide(*self, o);
	}
	stdmath_radian3 _scale(stdmath_radian o) {
		return stdmath_radian3_scale(*self, o);
	}

#if false
	stdmath_radian3 _modulus(stdmath_radian3 o) {
		return stdmath_radian3_modulus(*self, o);
	}
	stdmath_radian3 _logical_not() {
		return stdmath_radian3_logical_not(*self);
	}
	stdmath_radian3 _bitwise_not() {
		return stdmath_radian3_bitwise_not(*self);
	}
	stdmath_radian3 _logical_and(stdmath_radian3 o) {
		return stdmath_radian3_logical_and(*self, o);
	}
	stdmath_radian3 _bitwise_and(stdmath_radian3 o) {
		return stdmath_radian3_bitwise_and(*self, o);
	}
	stdmath_radian3 _logical_or(stdmath_radian3 o) {
		return stdmath_radian3_logical_or(*self, o);
	}
	stdmath_radian3 _bitwise_or(stdmath_radian3 o) {
		return stdmath_radian3_bitwise_or(*self, o);
	}
	stdmath_radian3 _bitwise_xor(stdmath_radian3 o) {
		return stdmath_radian3_bitwise_xor(*self, o);
	}
	stdmath_radian3 _shift_left(stdmath_radian3 o) {
		return stdmath_radian3_shift_left(*self, o);
	}
	stdmath_radian3 _shift_right(stdmath_radian3 o) {
		return stdmath_radian3_shift_right(*self, o);
	}
#endif

	stdmath_bool3 _equal_to(stdmath_radian3 o) {
		return stdmath_radian3_equal_to(*self, o);
	}
	stdmath_bool3 _not_equal_to(stdmath_radian3 o) {
		return stdmath_radian3_not_equal_to(*self, o);
	}
	stdmath_bool3 _less_than(stdmath_radian3 o) {
		return stdmath_radian3_less_than(*self, o);
	}
	stdmath_bool3 _less_than_or_equal_to(stdmath_radian3 o) {
		return stdmath_radian3_less_than_or_equal_to(*self, o);
	}
	stdmath_bool3 _greater_than(stdmath_radian3 o) {
		return stdmath_radian3_greater_than(*self, o);
	}
	stdmath_bool3 _greater_than_or_equal_to(stdmath_radian3 o) {
		return stdmath_radian3_greater_than_or_equal_to(*self, o);
	}

	stdmath_radian _length_squared() {
		return stdmath_radian3_length_squared(*self);
	}
	stdmath_radian _length() {
		return stdmath_radian3_length(*self);
	}
	stdmath_radian _dot(stdmath_radian3 o) {
		return stdmath_radian3_dot(*self, o);
	}
	stdmath_radian _min_element() {
		return stdmath_radian3_min_element(*self);
	}
	stdmath_radian _max_element() {
		return stdmath_radian3_max_element(*self);
	}

	// stdmath_radian elementwise_transform()
	// stdmath_radian reduce_element

	stdmath_radian3 _min(stdmath_radian3 o) {
		return stdmath_radian3_min(*self, o);
	}
	stdmath_radian3 _max(stdmath_radian3 o) {
		return stdmath_radian3_max(*self, o);
	}
	stdmath_radian3 _normalize() {
		return stdmath_radian3_normalize(*self);
	}
	stdmath_radian3 _lerp(stdmath_radian3 o, float t) {
		return stdmath_radian3_lerp(*self, o, t);
	}
	stdmath_radian3 _clamp(stdmath_radian3 min, stdmath_radian3 max) {
		return stdmath_radian3_clamp(*self, min, max);
	}
	stdmath_radian3 _reflect(stdmath_radian3 n) {
		return stdmath_radian3_reflect(*self, n);
	}
	stdmath_bool3 _approximately_equal(stdmath_radian3 o) {
		return stdmath_radian3_approximately_equal(*self, o);
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

	stdmath_radian _get_element(size_t i) {
		return self->data[i];
	}

	stdmath_radian _set_element(size_t i, stdmath_radian value) {
		return self->data[i] = value;
	}
}