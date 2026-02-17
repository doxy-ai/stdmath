#define STDMATH_EXPORT
#define STDMATH_INLINE
%rename(bool1) stdmath_bool1;
%include "bool1.h"

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

%extend stdmath_bool1 {
	stdmath_bool1(bool broadcast) {
		stdmath_bool1 *v;
		v = (stdmath_bool1 *) malloc(sizeof(stdmath_bool1));
		*v = stdmath_bool1_broadcast(broadcast);
		return v;
	}

#if 1 == 4
	stdmath_bool1(bool x = 0, bool y = 0, bool z = 0, bool w = 0) {
		stdmath_bool1 *v;
		v = (stdmath_bool1 *) malloc(sizeof(stdmath_bool1));
		v->x = x;
		v->y = y;
		v->z = z;
		v->w = w;
		return v;
	}
#elif 1 == 3
	stdmath_bool1(bool x = 0, bool y = 0, bool z = 0) {
		stdmath_bool1 *v;
		v = (stdmath_bool1 *) malloc(sizeof(stdmath_bool1));
		v->x = x;
		v->y = y;
		v->z = z;
		return v;
	}
#elif 1 == 2
	stdmath_bool1(bool x = 0, bool y = 0) {
		stdmath_bool1 *v;
		v = (stdmath_bool1 *) malloc(sizeof(stdmath_bool1));
		v->x = x;
		v->y = y;
		return v;
	}
#elif 1 == 1
	stdmath_bool1(bool x = 0) {
		stdmath_bool1 *v;
		v = (stdmath_bool1 *) malloc(sizeof(stdmath_bool1));
		v->x = x;
		return v;
	}
#endif

#ifndef STDMATH_NO_SWIZZLES

#endif

	stdmath_bool1 _add(stdmath_bool1 o) {
		return stdmath_bool1_add(*self, o);
	}
	stdmath_bool1 _subtract(stdmath_bool1 o) {
		return stdmath_bool1_subtract(*self, o);
	}
	stdmath_bool1 _negate() {
		return stdmath_bool1_negate(*self);
	}
	stdmath_bool1 _multiply(stdmath_bool1 o) {
		return stdmath_bool1_multiply(*self, o);
	}
	stdmath_bool1 _divide(stdmath_bool1 o) {
		return stdmath_bool1_divide(*self, o);
	}
	stdmath_bool1 _scale(bool o) {
		return stdmath_bool1_scale(*self, o);
	}

#if false
	stdmath_bool1 _modulus(stdmath_bool1 o) {
		return stdmath_bool1_modulus(*self, o);
	}
	stdmath_bool1 _logical_not() {
		return stdmath_bool1_logical_not(*self);
	}
	stdmath_bool1 _bitwise_not() {
		return stdmath_bool1_bitwise_not(*self);
	}
	stdmath_bool1 _logical_and(stdmath_bool1 o) {
		return stdmath_bool1_logical_and(*self, o);
	}
	stdmath_bool1 _bitwise_and(stdmath_bool1 o) {
		return stdmath_bool1_bitwise_and(*self, o);
	}
	stdmath_bool1 _logical_or(stdmath_bool1 o) {
		return stdmath_bool1_logical_or(*self, o);
	}
	stdmath_bool1 _bitwise_or(stdmath_bool1 o) {
		return stdmath_bool1_bitwise_or(*self, o);
	}
	stdmath_bool1 _bitwise_xor(stdmath_bool1 o) {
		return stdmath_bool1_bitwise_xor(*self, o);
	}
	stdmath_bool1 _shift_left(stdmath_bool1 o) {
		return stdmath_bool1_shift_left(*self, o);
	}
	stdmath_bool1 _shift_right(stdmath_bool1 o) {
		return stdmath_bool1_shift_right(*self, o);
	}
#endif

	stdmath_bool1 _equal_to(stdmath_bool1 o) {
		return stdmath_bool1_equal_to(*self, o);
	}
	stdmath_bool1 _not_equal_to(stdmath_bool1 o) {
		return stdmath_bool1_not_equal_to(*self, o);
	}
	stdmath_bool1 _less_than(stdmath_bool1 o) {
		return stdmath_bool1_less_than(*self, o);
	}
	stdmath_bool1 _less_than_or_equal_to(stdmath_bool1 o) {
		return stdmath_bool1_less_than_or_equal_to(*self, o);
	}
	stdmath_bool1 _greater_than(stdmath_bool1 o) {
		return stdmath_bool1_greater_than(*self, o);
	}
	stdmath_bool1 _greater_than_or_equal_to(stdmath_bool1 o) {
		return stdmath_bool1_greater_than_or_equal_to(*self, o);
	}

	bool _length_squared() {
		return stdmath_bool1_length_squared(*self);
	}
	bool _length() {
		return stdmath_bool1_length(*self);
	}
	bool _dot(stdmath_bool1 o) {
		return stdmath_bool1_dot(*self, o);
	}
	bool _min_element() {
		return stdmath_bool1_min_element(*self);
	}
	bool _max_element() {
		return stdmath_bool1_max_element(*self);
	}

	// bool elementwise_transform()
	// bool reduce_element

	stdmath_bool1 _min(stdmath_bool1 o) {
		return stdmath_bool1_min(*self, o);
	}
	stdmath_bool1 _max(stdmath_bool1 o) {
		return stdmath_bool1_max(*self, o);
	}
	stdmath_bool1 _normalize() {
		return stdmath_bool1_normalize(*self);
	}
	stdmath_bool1 _lerp(stdmath_bool1 o, float t) {
		return stdmath_bool1_lerp(*self, o, t);
	}
	stdmath_bool1 _clamp(stdmath_bool1 min, stdmath_bool1 max) {
		return stdmath_bool1_clamp(*self, min, max);
	}
	stdmath_bool1 _reflect(stdmath_bool1 n) {
		return stdmath_bool1_reflect(*self, n);
	}
	stdmath_bool1 _approximately_equal(stdmath_bool1 o) {
		return stdmath_bool1_approximately_equal(*self, o);
	}

#if true
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

	bool _get_element(size_t i) {
		return self->data[i];
	}

	bool _set_element(size_t i, bool value) {
		return self->data[i] = value;
	}
}