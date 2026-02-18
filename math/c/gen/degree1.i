#define STDMATH_EXPORT
#define STDMATH_INLINE
%rename(degree1) stdmath_degree1;
%include "degree1.h"

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

%extend stdmath_degree1 {
	stdmath_degree1(stdmath_degree broadcast) {
		stdmath_degree1 *v;
		v = (stdmath_degree1 *) malloc(sizeof(stdmath_degree1));
		*v = stdmath_degree1_broadcast(broadcast);
		return v;
	}

#if 1 == 4
	stdmath_degree1(stdmath_degree x = 0, stdmath_degree y = 0, stdmath_degree z = 0, stdmath_degree w = 0) {
		stdmath_degree1 *v;
		v = (stdmath_degree1 *) malloc(sizeof(stdmath_degree1));
		v->x = x;
		v->y = y;
		v->z = z;
		v->w = w;
		return v;
	}
#elif 1 == 3
	stdmath_degree1(stdmath_degree x = 0, stdmath_degree y = 0, stdmath_degree z = 0) {
		stdmath_degree1 *v;
		v = (stdmath_degree1 *) malloc(sizeof(stdmath_degree1));
		v->x = x;
		v->y = y;
		v->z = z;
		return v;
	}
#elif 1 == 2
	stdmath_degree1(stdmath_degree x = 0, stdmath_degree y = 0) {
		stdmath_degree1 *v;
		v = (stdmath_degree1 *) malloc(sizeof(stdmath_degree1));
		v->x = x;
		v->y = y;
		return v;
	}
#elif 1 == 1
	stdmath_degree1(stdmath_degree x = 0) {
		stdmath_degree1 *v;
		v = (stdmath_degree1 *) malloc(sizeof(stdmath_degree1));
		v->x = x;
		return v;
	}
#endif

#ifndef STDMATH_NO_SWIZZLES

#endif

	stdmath_degree1 _add(stdmath_degree1 o) {
		return stdmath_degree1_add(*self, o);
	}
	stdmath_degree1 _subtract(stdmath_degree1 o) {
		return stdmath_degree1_subtract(*self, o);
	}
	stdmath_degree1 _negate() {
		return stdmath_degree1_negate(*self);
	}
	stdmath_degree1 _multiply(stdmath_degree1 o) {
		return stdmath_degree1_multiply(*self, o);
	}
	stdmath_degree1 _divide(stdmath_degree1 o) {
		return stdmath_degree1_divide(*self, o);
	}
	stdmath_degree1 _scale(stdmath_degree o) {
		return stdmath_degree1_scale(*self, o);
	}

#if false
	stdmath_degree1 _modulus(stdmath_degree1 o) {
		return stdmath_degree1_modulus(*self, o);
	}
	stdmath_degree1 _logical_not() {
		return stdmath_degree1_logical_not(*self);
	}
	stdmath_degree1 _bitwise_not() {
		return stdmath_degree1_bitwise_not(*self);
	}
	stdmath_degree1 _logical_and(stdmath_degree1 o) {
		return stdmath_degree1_logical_and(*self, o);
	}
	stdmath_degree1 _bitwise_and(stdmath_degree1 o) {
		return stdmath_degree1_bitwise_and(*self, o);
	}
	stdmath_degree1 _logical_or(stdmath_degree1 o) {
		return stdmath_degree1_logical_or(*self, o);
	}
	stdmath_degree1 _bitwise_or(stdmath_degree1 o) {
		return stdmath_degree1_bitwise_or(*self, o);
	}
	stdmath_degree1 _bitwise_xor(stdmath_degree1 o) {
		return stdmath_degree1_bitwise_xor(*self, o);
	}
	stdmath_degree1 _shift_left(stdmath_degree1 o) {
		return stdmath_degree1_shift_left(*self, o);
	}
	stdmath_degree1 _shift_right(stdmath_degree1 o) {
		return stdmath_degree1_shift_right(*self, o);
	}
#endif

	stdmath_bool1 _equal_to(stdmath_degree1 o) {
		return stdmath_degree1_equal_to(*self, o);
	}
	stdmath_bool1 _not_equal_to(stdmath_degree1 o) {
		return stdmath_degree1_not_equal_to(*self, o);
	}
	stdmath_bool1 _less_than(stdmath_degree1 o) {
		return stdmath_degree1_less_than(*self, o);
	}
	stdmath_bool1 _less_than_or_equal_to(stdmath_degree1 o) {
		return stdmath_degree1_less_than_or_equal_to(*self, o);
	}
	stdmath_bool1 _greater_than(stdmath_degree1 o) {
		return stdmath_degree1_greater_than(*self, o);
	}
	stdmath_bool1 _greater_than_or_equal_to(stdmath_degree1 o) {
		return stdmath_degree1_greater_than_or_equal_to(*self, o);
	}

	stdmath_degree _length_squared() {
		return stdmath_degree1_length_squared(*self);
	}
	stdmath_degree _length() {
		return stdmath_degree1_length(*self);
	}
	stdmath_degree _dot(stdmath_degree1 o) {
		return stdmath_degree1_dot(*self, o);
	}
	stdmath_degree _min_element() {
		return stdmath_degree1_min_element(*self);
	}
	stdmath_degree _max_element() {
		return stdmath_degree1_max_element(*self);
	}

	// stdmath_degree elementwise_transform()
	// stdmath_degree reduce_element

	stdmath_degree1 _min(stdmath_degree1 o) {
		return stdmath_degree1_min(*self, o);
	}
	stdmath_degree1 _max(stdmath_degree1 o) {
		return stdmath_degree1_max(*self, o);
	}
	stdmath_degree1 _normalize() {
		return stdmath_degree1_normalize(*self);
	}
	stdmath_degree1 _lerp(stdmath_degree1 o, float t) {
		return stdmath_degree1_lerp(*self, o, t);
	}
	stdmath_degree1 _clamp(stdmath_degree1 min, stdmath_degree1 max) {
		return stdmath_degree1_clamp(*self, min, max);
	}
	stdmath_degree1 _reflect(stdmath_degree1 n) {
		return stdmath_degree1_reflect(*self, n);
	}
	stdmath_bool1 _approximately_equal(stdmath_degree1 o) {
		return stdmath_degree1_approximately_equal(*self, o);
	}

#if false
	stdmath_bool1 _all_of() {
		return stdmath_bool1_all_of(*self);
	}
	stdmath_bool1 _any_of() {
		return stdmath_bool1_any_of(*self);
	}
	stdmath_bool1 _none_of() {
		return stdmath_bool1_none_of(*self);
	}
	stdmath_bool1 _some_of() {
		return stdmath_bool1_some_of(*self);
	}
#endif

	size_t _size() {
		return 1;
	}

	stdmath_degree _get_element(size_t i) {
		return self->data[i];
	}

	stdmath_degree _set_element(size_t i, stdmath_degree value) {
		return self->data[i] = value;
	}
}