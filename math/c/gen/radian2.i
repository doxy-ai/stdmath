#define STDMATH_EXPORT
#define STDMATH_INLINE
%rename(radian2) stdmath_radian2;
%include "radian2.h"

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

%extend stdmath_radian2 {
	stdmath_radian2(stdmath_radian broadcast) {
		stdmath_radian2 *v;
		v = (stdmath_radian2 *) malloc(sizeof(stdmath_radian2));
		*v = stdmath_radian2_broadcast(broadcast);
		return v;
	}

#if 2 == 4
	stdmath_radian2(stdmath_radian x = 0, stdmath_radian y = 0, stdmath_radian z = 0, stdmath_radian w = 0) {
		stdmath_radian2 *v;
		v = (stdmath_radian2 *) malloc(sizeof(stdmath_radian2));
		v->x = x;
		v->y = y;
		v->z = z;
		v->w = w;
		return v;
	}
#elif 2 == 3
	stdmath_radian2(stdmath_radian x = 0, stdmath_radian y = 0, stdmath_radian z = 0) {
		stdmath_radian2 *v;
		v = (stdmath_radian2 *) malloc(sizeof(stdmath_radian2));
		v->x = x;
		v->y = y;
		v->z = z;
		return v;
	}
#elif 2 == 2
	stdmath_radian2(stdmath_radian x = 0, stdmath_radian y = 0) {
		stdmath_radian2 *v;
		v = (stdmath_radian2 *) malloc(sizeof(stdmath_radian2));
		v->x = x;
		v->y = y;
		return v;
	}
#elif 2 == 1
	stdmath_radian2(stdmath_radian x = 0) {
		stdmath_radian2 *v;
		v = (stdmath_radian2 *) malloc(sizeof(stdmath_radian2));
		v->x = x;
		return v;
	}
#endif

#ifndef STDMATH_NO_SWIZZLES
	stdmath_radian2 xx;
	stdmath_radian2 xy;
	stdmath_radian2 yx;
	stdmath_radian2 yy;

#endif

	stdmath_radian2 _add(stdmath_radian2 o) {
		return stdmath_radian2_add(*self, o);
	}
	stdmath_radian2 _subtract(stdmath_radian2 o) {
		return stdmath_radian2_subtract(*self, o);
	}
	stdmath_radian2 _negate() {
		return stdmath_radian2_negate(*self);
	}
	stdmath_radian2 _multiply(stdmath_radian2 o) {
		return stdmath_radian2_multiply(*self, o);
	}
	stdmath_radian2 _divide(stdmath_radian2 o) {
		return stdmath_radian2_divide(*self, o);
	}
	stdmath_radian2 _scale(stdmath_radian o) {
		return stdmath_radian2_scale(*self, o);
	}

#if false
	stdmath_radian2 _modulus(stdmath_radian2 o) {
		return stdmath_radian2_modulus(*self, o);
	}
	stdmath_radian2 _logical_not() {
		return stdmath_radian2_logical_not(*self);
	}
	stdmath_radian2 _bitwise_not() {
		return stdmath_radian2_bitwise_not(*self);
	}
	stdmath_radian2 _logical_and(stdmath_radian2 o) {
		return stdmath_radian2_logical_and(*self, o);
	}
	stdmath_radian2 _bitwise_and(stdmath_radian2 o) {
		return stdmath_radian2_bitwise_and(*self, o);
	}
	stdmath_radian2 _logical_or(stdmath_radian2 o) {
		return stdmath_radian2_logical_or(*self, o);
	}
	stdmath_radian2 _bitwise_or(stdmath_radian2 o) {
		return stdmath_radian2_bitwise_or(*self, o);
	}
	stdmath_radian2 _bitwise_xor(stdmath_radian2 o) {
		return stdmath_radian2_bitwise_xor(*self, o);
	}
	stdmath_radian2 _shift_left(stdmath_radian2 o) {
		return stdmath_radian2_shift_left(*self, o);
	}
	stdmath_radian2 _shift_right(stdmath_radian2 o) {
		return stdmath_radian2_shift_right(*self, o);
	}
#endif

	stdmath_bool2 _equal_to(stdmath_radian2 o) {
		return stdmath_radian2_equal_to(*self, o);
	}
	stdmath_bool2 _not_equal_to(stdmath_radian2 o) {
		return stdmath_radian2_not_equal_to(*self, o);
	}
	stdmath_bool2 _less_than(stdmath_radian2 o) {
		return stdmath_radian2_less_than(*self, o);
	}
	stdmath_bool2 _less_than_or_equal_to(stdmath_radian2 o) {
		return stdmath_radian2_less_than_or_equal_to(*self, o);
	}
	stdmath_bool2 _greater_than(stdmath_radian2 o) {
		return stdmath_radian2_greater_than(*self, o);
	}
	stdmath_bool2 _greater_than_or_equal_to(stdmath_radian2 o) {
		return stdmath_radian2_greater_than_or_equal_to(*self, o);
	}

	stdmath_radian _length_squared() {
		return stdmath_radian2_length_squared(*self);
	}
	stdmath_radian _length() {
		return stdmath_radian2_length(*self);
	}
	stdmath_radian _dot(stdmath_radian2 o) {
		return stdmath_radian2_dot(*self, o);
	}
	stdmath_radian _min_element() {
		return stdmath_radian2_min_element(*self);
	}
	stdmath_radian _max_element() {
		return stdmath_radian2_max_element(*self);
	}

	// stdmath_radian elementwise_transform()
	// stdmath_radian reduce_element

	stdmath_radian2 _min(stdmath_radian2 o) {
		return stdmath_radian2_min(*self, o);
	}
	stdmath_radian2 _max(stdmath_radian2 o) {
		return stdmath_radian2_max(*self, o);
	}
	stdmath_radian2 _normalize() {
		return stdmath_radian2_normalize(*self);
	}
	stdmath_radian2 _lerp(stdmath_radian2 o, float t) {
		return stdmath_radian2_lerp(*self, o, t);
	}
	stdmath_radian2 _clamp(stdmath_radian2 min, stdmath_radian2 max) {
		return stdmath_radian2_clamp(*self, min, max);
	}
	stdmath_radian2 _reflect(stdmath_radian2 n) {
		return stdmath_radian2_reflect(*self, n);
	}
	stdmath_bool2 _approximately_equal(stdmath_radian2 o) {
		return stdmath_radian2_approximately_equal(*self, o);
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

	stdmath_radian _get_element(size_t i) {
		return self->data[i];
	}

	stdmath_radian _set_element(size_t i, stdmath_radian value) {
		return self->data[i] = value;
	}
}