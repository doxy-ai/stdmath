#define STDMATH_EXPORT
#define STDMATH_INLINE
%rename(degree3) stdmath_degree3;
%include "degree3.h"

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

%extend stdmath_degree3 {
	stdmath_degree3(stdmath_degree broadcast) {
		stdmath_degree3 *v;
		v = (stdmath_degree3 *) malloc(sizeof(stdmath_degree3));
		*v = stdmath_degree3_broadcast(broadcast);
		return v;
	}

#if 3 == 4
	stdmath_degree3(stdmath_degree x = 0, stdmath_degree y = 0, stdmath_degree z = 0, stdmath_degree w = 0) {
		stdmath_degree3 *v;
		v = (stdmath_degree3 *) malloc(sizeof(stdmath_degree3));
		v->x = x;
		v->y = y;
		v->z = z;
		v->w = w;
		return v;
	}
#elif 3 == 3
	stdmath_degree3(stdmath_degree x = 0, stdmath_degree y = 0, stdmath_degree z = 0) {
		stdmath_degree3 *v;
		v = (stdmath_degree3 *) malloc(sizeof(stdmath_degree3));
		v->x = x;
		v->y = y;
		v->z = z;
		return v;
	}
#elif 3 == 2
	stdmath_degree3(stdmath_degree x = 0, stdmath_degree y = 0) {
		stdmath_degree3 *v;
		v = (stdmath_degree3 *) malloc(sizeof(stdmath_degree3));
		v->x = x;
		v->y = y;
		return v;
	}
#elif 3 == 1
	stdmath_degree3(stdmath_degree x = 0) {
		stdmath_degree3 *v;
		v = (stdmath_degree3 *) malloc(sizeof(stdmath_degree3));
		v->x = x;
		return v;
	}
#endif

#ifndef STDMATH_NO_SWIZZLES
	stdmath_degree2 xx;
	stdmath_degree2 xy;
	stdmath_degree2 xz;
	stdmath_degree2 yx;
	stdmath_degree2 yy;
	stdmath_degree2 yz;
	stdmath_degree2 zx;
	stdmath_degree2 zy;
	stdmath_degree2 zz;
	stdmath_degree3 xxx;
	stdmath_degree3 xxy;
	stdmath_degree3 xxz;
	stdmath_degree3 xyx;
	stdmath_degree3 xyy;
	stdmath_degree3 xyz;
	stdmath_degree3 xzx;
	stdmath_degree3 xzy;
	stdmath_degree3 xzz;
	stdmath_degree3 yxx;
	stdmath_degree3 yxy;
	stdmath_degree3 yxz;
	stdmath_degree3 yyx;
	stdmath_degree3 yyy;
	stdmath_degree3 yyz;
	stdmath_degree3 yzx;
	stdmath_degree3 yzy;
	stdmath_degree3 yzz;
	stdmath_degree3 zxx;
	stdmath_degree3 zxy;
	stdmath_degree3 zxz;
	stdmath_degree3 zyx;
	stdmath_degree3 zyy;
	stdmath_degree3 zyz;
	stdmath_degree3 zzx;
	stdmath_degree3 zzy;
	stdmath_degree3 zzz;

#endif

	stdmath_degree3 _add(stdmath_degree3 o) {
		return stdmath_degree3_add(*self, o);
	}
	stdmath_degree3 _subtract(stdmath_degree3 o) {
		return stdmath_degree3_subtract(*self, o);
	}
	stdmath_degree3 _negate() {
		return stdmath_degree3_negate(*self);
	}
	stdmath_degree3 _multiply(stdmath_degree3 o) {
		return stdmath_degree3_multiply(*self, o);
	}
	stdmath_degree3 _divide(stdmath_degree3 o) {
		return stdmath_degree3_divide(*self, o);
	}
	stdmath_degree3 _scale(stdmath_degree o) {
		return stdmath_degree3_scale(*self, o);
	}

#if false
	stdmath_degree3 _modulus(stdmath_degree3 o) {
		return stdmath_degree3_modulus(*self, o);
	}
	stdmath_degree3 _logical_not() {
		return stdmath_degree3_logical_not(*self);
	}
	stdmath_degree3 _bitwise_not() {
		return stdmath_degree3_bitwise_not(*self);
	}
	stdmath_degree3 _logical_and(stdmath_degree3 o) {
		return stdmath_degree3_logical_and(*self, o);
	}
	stdmath_degree3 _bitwise_and(stdmath_degree3 o) {
		return stdmath_degree3_bitwise_and(*self, o);
	}
	stdmath_degree3 _logical_or(stdmath_degree3 o) {
		return stdmath_degree3_logical_or(*self, o);
	}
	stdmath_degree3 _bitwise_or(stdmath_degree3 o) {
		return stdmath_degree3_bitwise_or(*self, o);
	}
	stdmath_degree3 _bitwise_xor(stdmath_degree3 o) {
		return stdmath_degree3_bitwise_xor(*self, o);
	}
	stdmath_degree3 _shift_left(stdmath_degree3 o) {
		return stdmath_degree3_shift_left(*self, o);
	}
	stdmath_degree3 _shift_right(stdmath_degree3 o) {
		return stdmath_degree3_shift_right(*self, o);
	}
#endif

	stdmath_bool3 _equal_to(stdmath_degree3 o) {
		return stdmath_degree3_equal_to(*self, o);
	}
	stdmath_bool3 _not_equal_to(stdmath_degree3 o) {
		return stdmath_degree3_not_equal_to(*self, o);
	}
	stdmath_bool3 _less_than(stdmath_degree3 o) {
		return stdmath_degree3_less_than(*self, o);
	}
	stdmath_bool3 _less_than_or_equal_to(stdmath_degree3 o) {
		return stdmath_degree3_less_than_or_equal_to(*self, o);
	}
	stdmath_bool3 _greater_than(stdmath_degree3 o) {
		return stdmath_degree3_greater_than(*self, o);
	}
	stdmath_bool3 _greater_than_or_equal_to(stdmath_degree3 o) {
		return stdmath_degree3_greater_than_or_equal_to(*self, o);
	}

	stdmath_degree _length_squared() {
		return stdmath_degree3_length_squared(*self);
	}
	stdmath_degree _length() {
		return stdmath_degree3_length(*self);
	}
	stdmath_degree _dot(stdmath_degree3 o) {
		return stdmath_degree3_dot(*self, o);
	}
	stdmath_degree _min_element() {
		return stdmath_degree3_min_element(*self);
	}
	stdmath_degree _max_element() {
		return stdmath_degree3_max_element(*self);
	}

	// stdmath_degree elementwise_transform()
	// stdmath_degree reduce_element

	stdmath_degree3 _min(stdmath_degree3 o) {
		return stdmath_degree3_min(*self, o);
	}
	stdmath_degree3 _max(stdmath_degree3 o) {
		return stdmath_degree3_max(*self, o);
	}
	stdmath_degree3 _normalize() {
		return stdmath_degree3_normalize(*self);
	}
	stdmath_degree3 _lerp(stdmath_degree3 o, float t) {
		return stdmath_degree3_lerp(*self, o, t);
	}
	stdmath_degree3 _clamp(stdmath_degree3 min, stdmath_degree3 max) {
		return stdmath_degree3_clamp(*self, min, max);
	}
	stdmath_degree3 _reflect(stdmath_degree3 n) {
		return stdmath_degree3_reflect(*self, n);
	}
	stdmath_bool3 _approximately_equal(stdmath_degree3 o) {
		return stdmath_degree3_approximately_equal(*self, o);
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

	stdmath_degree _get_element(size_t i) {
		return self->data[i];
	}

	stdmath_degree _set_element(size_t i, stdmath_degree value) {
		return self->data[i] = value;
	}
}