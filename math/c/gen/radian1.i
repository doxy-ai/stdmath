#define STDMATH_EXPORT
#define STDMATH_INLINE
%rename(radian1) stdmath_radian1;
%include "radian1.h"

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

%extend stdmath_radian1 {
	stdmath_radian1(stdmath_radian broadcast) {
		stdmath_radian1 *v;
		v = (stdmath_radian1 *) malloc(sizeof(stdmath_radian1));
		*v = stdmath_radian1_broadcast(broadcast);
		return v;
	}

#if 1 == 4
	stdmath_radian1(stdmath_radian x = 0, stdmath_radian y = 0, stdmath_radian z = 0, stdmath_radian w = 0) {
		stdmath_radian1 *v;
		v = (stdmath_radian1 *) malloc(sizeof(stdmath_radian1));
		v->x = x;
		v->y = y;
		v->z = z;
		v->w = w;
		return v;
	}
#elif 1 == 3
	stdmath_radian1(stdmath_radian x = 0, stdmath_radian y = 0, stdmath_radian z = 0) {
		stdmath_radian1 *v;
		v = (stdmath_radian1 *) malloc(sizeof(stdmath_radian1));
		v->x = x;
		v->y = y;
		v->z = z;
		return v;
	}
#elif 1 == 2
	stdmath_radian1(stdmath_radian x = 0, stdmath_radian y = 0) {
		stdmath_radian1 *v;
		v = (stdmath_radian1 *) malloc(sizeof(stdmath_radian1));
		v->x = x;
		v->y = y;
		return v;
	}
#elif 1 == 1
	stdmath_radian1(stdmath_radian x = 0) {
		stdmath_radian1 *v;
		v = (stdmath_radian1 *) malloc(sizeof(stdmath_radian1));
		v->x = x;
		return v;
	}
#endif

#ifndef STDMATH_NO_SWIZZLES

#endif

	stdmath_radian1 _add(stdmath_radian1 o) {
		return stdmath_radian1_add(*self, o);
	}
	stdmath_radian1 _subtract(stdmath_radian1 o) {
		return stdmath_radian1_subtract(*self, o);
	}
	stdmath_radian1 _negate() {
		return stdmath_radian1_negate(*self);
	}
	stdmath_radian1 _multiply(stdmath_radian1 o) {
		return stdmath_radian1_multiply(*self, o);
	}
	stdmath_radian1 _divide(stdmath_radian1 o) {
		return stdmath_radian1_divide(*self, o);
	}
	stdmath_radian1 _scale(stdmath_radian o) {
		return stdmath_radian1_scale(*self, o);
	}

#if false
	stdmath_radian1 _modulus(stdmath_radian1 o) {
		return stdmath_radian1_modulus(*self, o);
	}
	stdmath_radian1 _logical_not() {
		return stdmath_radian1_logical_not(*self);
	}
	stdmath_radian1 _bitwise_not() {
		return stdmath_radian1_bitwise_not(*self);
	}
	stdmath_radian1 _logical_and(stdmath_radian1 o) {
		return stdmath_radian1_logical_and(*self, o);
	}
	stdmath_radian1 _bitwise_and(stdmath_radian1 o) {
		return stdmath_radian1_bitwise_and(*self, o);
	}
	stdmath_radian1 _logical_or(stdmath_radian1 o) {
		return stdmath_radian1_logical_or(*self, o);
	}
	stdmath_radian1 _bitwise_or(stdmath_radian1 o) {
		return stdmath_radian1_bitwise_or(*self, o);
	}
	stdmath_radian1 _bitwise_xor(stdmath_radian1 o) {
		return stdmath_radian1_bitwise_xor(*self, o);
	}
	stdmath_radian1 _shift_left(stdmath_radian1 o) {
		return stdmath_radian1_shift_left(*self, o);
	}
	stdmath_radian1 _shift_right(stdmath_radian1 o) {
		return stdmath_radian1_shift_right(*self, o);
	}
#endif

	stdmath_bool1 _equal_to(stdmath_radian1 o) {
		return stdmath_radian1_equal_to(*self, o);
	}
	stdmath_bool1 _not_equal_to(stdmath_radian1 o) {
		return stdmath_radian1_not_equal_to(*self, o);
	}
	stdmath_bool1 _less_than(stdmath_radian1 o) {
		return stdmath_radian1_less_than(*self, o);
	}
	stdmath_bool1 _less_than_or_equal_to(stdmath_radian1 o) {
		return stdmath_radian1_less_than_or_equal_to(*self, o);
	}
	stdmath_bool1 _greater_than(stdmath_radian1 o) {
		return stdmath_radian1_greater_than(*self, o);
	}
	stdmath_bool1 _greater_than_or_equal_to(stdmath_radian1 o) {
		return stdmath_radian1_greater_than_or_equal_to(*self, o);
	}

	stdmath_radian _length_squared() {
		return stdmath_radian1_length_squared(*self);
	}
	stdmath_radian _length() {
		return stdmath_radian1_length(*self);
	}
	stdmath_radian _dot(stdmath_radian1 o) {
		return stdmath_radian1_dot(*self, o);
	}
	stdmath_radian _min_element() {
		return stdmath_radian1_min_element(*self);
	}
	stdmath_radian _max_element() {
		return stdmath_radian1_max_element(*self);
	}

	// stdmath_radian elementwise_transform()
	// stdmath_radian reduce_element

	stdmath_radian1 _min(stdmath_radian1 o) {
		return stdmath_radian1_min(*self, o);
	}
	stdmath_radian1 _max(stdmath_radian1 o) {
		return stdmath_radian1_max(*self, o);
	}
	stdmath_radian1 _normalize() {
		return stdmath_radian1_normalize(*self);
	}
	stdmath_radian1 _lerp(stdmath_radian1 o, float t) {
		return stdmath_radian1_lerp(*self, o, t);
	}
	stdmath_radian1 _clamp(stdmath_radian1 min, stdmath_radian1 max) {
		return stdmath_radian1_clamp(*self, min, max);
	}
	stdmath_radian1 _reflect(stdmath_radian1 n) {
		return stdmath_radian1_reflect(*self, n);
	}
	stdmath_bool1 _approximately_equal(stdmath_radian1 o) {
		return stdmath_radian1_approximately_equal(*self, o);
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

	stdmath_radian _get_element(size_t i) {
		return self->data[i];
	}

	stdmath_radian _set_element(size_t i, stdmath_radian value) {
		return self->data[i] = value;
	}
}