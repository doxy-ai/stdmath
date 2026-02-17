#define STDMATH_EXPORT
#define STDMATH_INLINE
%rename(bool3) stdmath_bool3;
%include "bool3.h"

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

%extend stdmath_bool3 {
	stdmath_bool3(bool broadcast) {
		stdmath_bool3 *v;
		v = (stdmath_bool3 *) malloc(sizeof(stdmath_bool3));
		*v = stdmath_bool3_broadcast(broadcast);
		return v;
	}

#if 3 == 4
	stdmath_bool3(bool x = 0, bool y = 0, bool z = 0, bool w = 0) {
		stdmath_bool3 *v;
		v = (stdmath_bool3 *) malloc(sizeof(stdmath_bool3));
		v->x = x;
		v->y = y;
		v->z = z;
		v->w = w;
		return v;
	}
#elif 3 == 3
	stdmath_bool3(bool x = 0, bool y = 0, bool z = 0) {
		stdmath_bool3 *v;
		v = (stdmath_bool3 *) malloc(sizeof(stdmath_bool3));
		v->x = x;
		v->y = y;
		v->z = z;
		return v;
	}
#elif 3 == 2
	stdmath_bool3(bool x = 0, bool y = 0) {
		stdmath_bool3 *v;
		v = (stdmath_bool3 *) malloc(sizeof(stdmath_bool3));
		v->x = x;
		v->y = y;
		return v;
	}
#elif 3 == 1
	stdmath_bool3(bool x = 0) {
		stdmath_bool3 *v;
		v = (stdmath_bool3 *) malloc(sizeof(stdmath_bool3));
		v->x = x;
		return v;
	}
#endif

#ifndef STDMATH_NO_SWIZZLES
	stdmath_bool2 xx;
	stdmath_bool2 xy;
	stdmath_bool2 xz;
	stdmath_bool2 yx;
	stdmath_bool2 yy;
	stdmath_bool2 yz;
	stdmath_bool2 zx;
	stdmath_bool2 zy;
	stdmath_bool2 zz;
	stdmath_bool3 xxx;
	stdmath_bool3 xxy;
	stdmath_bool3 xxz;
	stdmath_bool3 xyx;
	stdmath_bool3 xyy;
	stdmath_bool3 xyz;
	stdmath_bool3 xzx;
	stdmath_bool3 xzy;
	stdmath_bool3 xzz;
	stdmath_bool3 yxx;
	stdmath_bool3 yxy;
	stdmath_bool3 yxz;
	stdmath_bool3 yyx;
	stdmath_bool3 yyy;
	stdmath_bool3 yyz;
	stdmath_bool3 yzx;
	stdmath_bool3 yzy;
	stdmath_bool3 yzz;
	stdmath_bool3 zxx;
	stdmath_bool3 zxy;
	stdmath_bool3 zxz;
	stdmath_bool3 zyx;
	stdmath_bool3 zyy;
	stdmath_bool3 zyz;
	stdmath_bool3 zzx;
	stdmath_bool3 zzy;
	stdmath_bool3 zzz;

#endif

	stdmath_bool3 _add(stdmath_bool3 o) {
		return stdmath_bool3_add(*self, o);
	}
	stdmath_bool3 _subtract(stdmath_bool3 o) {
		return stdmath_bool3_subtract(*self, o);
	}
	stdmath_bool3 _negate() {
		return stdmath_bool3_negate(*self);
	}
	stdmath_bool3 _multiply(stdmath_bool3 o) {
		return stdmath_bool3_multiply(*self, o);
	}
	stdmath_bool3 _divide(stdmath_bool3 o) {
		return stdmath_bool3_divide(*self, o);
	}
	stdmath_bool3 _scale(bool o) {
		return stdmath_bool3_scale(*self, o);
	}

#if false
	stdmath_bool3 _modulus(stdmath_bool3 o) {
		return stdmath_bool3_modulus(*self, o);
	}
	stdmath_bool3 _logical_not() {
		return stdmath_bool3_logical_not(*self);
	}
	stdmath_bool3 _bitwise_not() {
		return stdmath_bool3_bitwise_not(*self);
	}
	stdmath_bool3 _logical_and(stdmath_bool3 o) {
		return stdmath_bool3_logical_and(*self, o);
	}
	stdmath_bool3 _bitwise_and(stdmath_bool3 o) {
		return stdmath_bool3_bitwise_and(*self, o);
	}
	stdmath_bool3 _logical_or(stdmath_bool3 o) {
		return stdmath_bool3_logical_or(*self, o);
	}
	stdmath_bool3 _bitwise_or(stdmath_bool3 o) {
		return stdmath_bool3_bitwise_or(*self, o);
	}
	stdmath_bool3 _bitwise_xor(stdmath_bool3 o) {
		return stdmath_bool3_bitwise_xor(*self, o);
	}
	stdmath_bool3 _shift_left(stdmath_bool3 o) {
		return stdmath_bool3_shift_left(*self, o);
	}
	stdmath_bool3 _shift_right(stdmath_bool3 o) {
		return stdmath_bool3_shift_right(*self, o);
	}
#endif

	stdmath_bool3 _equal_to(stdmath_bool3 o) {
		return stdmath_bool3_equal_to(*self, o);
	}
	stdmath_bool3 _not_equal_to(stdmath_bool3 o) {
		return stdmath_bool3_not_equal_to(*self, o);
	}
	stdmath_bool3 _less_than(stdmath_bool3 o) {
		return stdmath_bool3_less_than(*self, o);
	}
	stdmath_bool3 _less_than_or_equal_to(stdmath_bool3 o) {
		return stdmath_bool3_less_than_or_equal_to(*self, o);
	}
	stdmath_bool3 _greater_than(stdmath_bool3 o) {
		return stdmath_bool3_greater_than(*self, o);
	}
	stdmath_bool3 _greater_than_or_equal_to(stdmath_bool3 o) {
		return stdmath_bool3_greater_than_or_equal_to(*self, o);
	}

	bool _length_squared() {
		return stdmath_bool3_length_squared(*self);
	}
	bool _length() {
		return stdmath_bool3_length(*self);
	}
	bool _dot(stdmath_bool3 o) {
		return stdmath_bool3_dot(*self, o);
	}
	bool _min_element() {
		return stdmath_bool3_min_element(*self);
	}
	bool _max_element() {
		return stdmath_bool3_max_element(*self);
	}

	// bool elementwise_transform()
	// bool reduce_element

	stdmath_bool3 _min(stdmath_bool3 o) {
		return stdmath_bool3_min(*self, o);
	}
	stdmath_bool3 _max(stdmath_bool3 o) {
		return stdmath_bool3_max(*self, o);
	}
	stdmath_bool3 _normalize() {
		return stdmath_bool3_normalize(*self);
	}
	stdmath_bool3 _lerp(stdmath_bool3 o, float t) {
		return stdmath_bool3_lerp(*self, o, t);
	}
	stdmath_bool3 _clamp(stdmath_bool3 min, stdmath_bool3 max) {
		return stdmath_bool3_clamp(*self, min, max);
	}
	stdmath_bool3 _reflect(stdmath_bool3 n) {
		return stdmath_bool3_reflect(*self, n);
	}
	stdmath_bool3 _approximately_equal(stdmath_bool3 o) {
		return stdmath_bool3_approximately_equal(*self, o);
	}

#if true
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

	bool _get_element(size_t i) {
		return self->data[i];
	}

	bool _set_element(size_t i, bool value) {
		return self->data[i] = value;
	}
}