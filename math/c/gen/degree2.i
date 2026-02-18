#define STDMATH_EXPORT
#define STDMATH_INLINE
%rename(degree2) stdmath_degree2;
%include "degree2.h"

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

%extend stdmath_degree2 {
	stdmath_degree2(stdmath_degree broadcast) {
		stdmath_degree2 *v;
		v = (stdmath_degree2 *) malloc(sizeof(stdmath_degree2));
		*v = stdmath_degree2_broadcast(broadcast);
		return v;
	}

#if 2 == 4
	stdmath_degree2(stdmath_degree x = 0, stdmath_degree y = 0, stdmath_degree z = 0, stdmath_degree w = 0) {
		stdmath_degree2 *v;
		v = (stdmath_degree2 *) malloc(sizeof(stdmath_degree2));
		v->x = x;
		v->y = y;
		v->z = z;
		v->w = w;
		return v;
	}
#elif 2 == 3
	stdmath_degree2(stdmath_degree x = 0, stdmath_degree y = 0, stdmath_degree z = 0) {
		stdmath_degree2 *v;
		v = (stdmath_degree2 *) malloc(sizeof(stdmath_degree2));
		v->x = x;
		v->y = y;
		v->z = z;
		return v;
	}
#elif 2 == 2
	stdmath_degree2(stdmath_degree x = 0, stdmath_degree y = 0) {
		stdmath_degree2 *v;
		v = (stdmath_degree2 *) malloc(sizeof(stdmath_degree2));
		v->x = x;
		v->y = y;
		return v;
	}
#elif 2 == 1
	stdmath_degree2(stdmath_degree x = 0) {
		stdmath_degree2 *v;
		v = (stdmath_degree2 *) malloc(sizeof(stdmath_degree2));
		v->x = x;
		return v;
	}
#endif

#ifndef STDMATH_NO_SWIZZLES
	stdmath_degree2 xx;
	stdmath_degree2 xy;
	stdmath_degree2 yx;
	stdmath_degree2 yy;

#endif

	stdmath_degree2 _add(stdmath_degree2 o) {
		return stdmath_degree2_add(*self, o);
	}
	stdmath_degree2 _subtract(stdmath_degree2 o) {
		return stdmath_degree2_subtract(*self, o);
	}
	stdmath_degree2 _negate() {
		return stdmath_degree2_negate(*self);
	}
	stdmath_degree2 _multiply(stdmath_degree2 o) {
		return stdmath_degree2_multiply(*self, o);
	}
	stdmath_degree2 _divide(stdmath_degree2 o) {
		return stdmath_degree2_divide(*self, o);
	}
	stdmath_degree2 _scale(stdmath_degree o) {
		return stdmath_degree2_scale(*self, o);
	}

#if false
	stdmath_degree2 _modulus(stdmath_degree2 o) {
		return stdmath_degree2_modulus(*self, o);
	}
	stdmath_degree2 _logical_not() {
		return stdmath_degree2_logical_not(*self);
	}
	stdmath_degree2 _bitwise_not() {
		return stdmath_degree2_bitwise_not(*self);
	}
	stdmath_degree2 _logical_and(stdmath_degree2 o) {
		return stdmath_degree2_logical_and(*self, o);
	}
	stdmath_degree2 _bitwise_and(stdmath_degree2 o) {
		return stdmath_degree2_bitwise_and(*self, o);
	}
	stdmath_degree2 _logical_or(stdmath_degree2 o) {
		return stdmath_degree2_logical_or(*self, o);
	}
	stdmath_degree2 _bitwise_or(stdmath_degree2 o) {
		return stdmath_degree2_bitwise_or(*self, o);
	}
	stdmath_degree2 _bitwise_xor(stdmath_degree2 o) {
		return stdmath_degree2_bitwise_xor(*self, o);
	}
	stdmath_degree2 _shift_left(stdmath_degree2 o) {
		return stdmath_degree2_shift_left(*self, o);
	}
	stdmath_degree2 _shift_right(stdmath_degree2 o) {
		return stdmath_degree2_shift_right(*self, o);
	}
#endif

	stdmath_bool2 _equal_to(stdmath_degree2 o) {
		return stdmath_degree2_equal_to(*self, o);
	}
	stdmath_bool2 _not_equal_to(stdmath_degree2 o) {
		return stdmath_degree2_not_equal_to(*self, o);
	}
	stdmath_bool2 _less_than(stdmath_degree2 o) {
		return stdmath_degree2_less_than(*self, o);
	}
	stdmath_bool2 _less_than_or_equal_to(stdmath_degree2 o) {
		return stdmath_degree2_less_than_or_equal_to(*self, o);
	}
	stdmath_bool2 _greater_than(stdmath_degree2 o) {
		return stdmath_degree2_greater_than(*self, o);
	}
	stdmath_bool2 _greater_than_or_equal_to(stdmath_degree2 o) {
		return stdmath_degree2_greater_than_or_equal_to(*self, o);
	}

	stdmath_degree _length_squared() {
		return stdmath_degree2_length_squared(*self);
	}
	stdmath_degree _length() {
		return stdmath_degree2_length(*self);
	}
	stdmath_degree _dot(stdmath_degree2 o) {
		return stdmath_degree2_dot(*self, o);
	}
	stdmath_degree _min_element() {
		return stdmath_degree2_min_element(*self);
	}
	stdmath_degree _max_element() {
		return stdmath_degree2_max_element(*self);
	}

	// stdmath_degree elementwise_transform()
	// stdmath_degree reduce_element

	stdmath_degree2 _min(stdmath_degree2 o) {
		return stdmath_degree2_min(*self, o);
	}
	stdmath_degree2 _max(stdmath_degree2 o) {
		return stdmath_degree2_max(*self, o);
	}
	stdmath_degree2 _normalize() {
		return stdmath_degree2_normalize(*self);
	}
	stdmath_degree2 _lerp(stdmath_degree2 o, float t) {
		return stdmath_degree2_lerp(*self, o, t);
	}
	stdmath_degree2 _clamp(stdmath_degree2 min, stdmath_degree2 max) {
		return stdmath_degree2_clamp(*self, min, max);
	}
	stdmath_degree2 _reflect(stdmath_degree2 n) {
		return stdmath_degree2_reflect(*self, n);
	}
	stdmath_bool2 _approximately_equal(stdmath_degree2 o) {
		return stdmath_degree2_approximately_equal(*self, o);
	}

#if false
	stdmath_bool2 _all_of() {
		return stdmath_bool2_all_of(*self);
	}
	stdmath_bool2 _any_of() {
		return stdmath_bool2_any_of(*self);
	}
	stdmath_bool2 _none_of() {
		return stdmath_bool2_none_of(*self);
	}
	stdmath_bool2 _some_of() {
		return stdmath_bool2_some_of(*self);
	}
#endif

	size_t _size() {
		return 2;
	}

	stdmath_degree _get_element(size_t i) {
		return self->data[i];
	}

	stdmath_degree _set_element(size_t i, stdmath_degree value) {
		return self->data[i] = value;
	}
}