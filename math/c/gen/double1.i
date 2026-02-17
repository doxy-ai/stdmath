#define STDMATH_EXPORT
#define STDMATH_INLINE
%rename(double1) stdmath_double1;
%include "double1.h"

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

%extend stdmath_double1 {
	stdmath_double1(double broadcast) {
		stdmath_double1 *v;
		v = (stdmath_double1 *) malloc(sizeof(stdmath_double1));
		*v = stdmath_double1_broadcast(broadcast);
		return v;
	}

#if 1 == 4
	stdmath_double1(double x = 0, double y = 0, double z = 0, double w = 0) {
		stdmath_double1 *v;
		v = (stdmath_double1 *) malloc(sizeof(stdmath_double1));
		v->x = x;
		v->y = y;
		v->z = z;
		v->w = w;
		return v;
	}
#elif 1 == 3
	stdmath_double1(double x = 0, double y = 0, double z = 0) {
		stdmath_double1 *v;
		v = (stdmath_double1 *) malloc(sizeof(stdmath_double1));
		v->x = x;
		v->y = y;
		v->z = z;
		return v;
	}
#elif 1 == 2
	stdmath_double1(double x = 0, double y = 0) {
		stdmath_double1 *v;
		v = (stdmath_double1 *) malloc(sizeof(stdmath_double1));
		v->x = x;
		v->y = y;
		return v;
	}
#elif 1 == 1
	stdmath_double1(double x = 0) {
		stdmath_double1 *v;
		v = (stdmath_double1 *) malloc(sizeof(stdmath_double1));
		v->x = x;
		return v;
	}
#endif

#ifndef STDMATH_NO_SWIZZLES

#endif

	stdmath_double1 _add(stdmath_double1 o) {
		return stdmath_double1_add(*self, o);
	}
	stdmath_double1 _subtract(stdmath_double1 o) {
		return stdmath_double1_subtract(*self, o);
	}
	stdmath_double1 _negate() {
		return stdmath_double1_negate(*self);
	}
	stdmath_double1 _multiply(stdmath_double1 o) {
		return stdmath_double1_multiply(*self, o);
	}
	stdmath_double1 _divide(stdmath_double1 o) {
		return stdmath_double1_divide(*self, o);
	}
	stdmath_double1 _scale(double o) {
		return stdmath_double1_scale(*self, o);
	}

#if false
	stdmath_double1 _modulus(stdmath_double1 o) {
		return stdmath_double1_modulus(*self, o);
	}
	stdmath_double1 _logical_not() {
		return stdmath_double1_logical_not(*self);
	}
	stdmath_double1 _bitwise_not() {
		return stdmath_double1_bitwise_not(*self);
	}
	stdmath_double1 _logical_and(stdmath_double1 o) {
		return stdmath_double1_logical_and(*self, o);
	}
	stdmath_double1 _bitwise_and(stdmath_double1 o) {
		return stdmath_double1_bitwise_and(*self, o);
	}
	stdmath_double1 _logical_or(stdmath_double1 o) {
		return stdmath_double1_logical_or(*self, o);
	}
	stdmath_double1 _bitwise_or(stdmath_double1 o) {
		return stdmath_double1_bitwise_or(*self, o);
	}
	stdmath_double1 _bitwise_xor(stdmath_double1 o) {
		return stdmath_double1_bitwise_xor(*self, o);
	}
	stdmath_double1 _shift_left(stdmath_double1 o) {
		return stdmath_double1_shift_left(*self, o);
	}
	stdmath_double1 _shift_right(stdmath_double1 o) {
		return stdmath_double1_shift_right(*self, o);
	}
#endif

	stdmath_bool1 _equal_to(stdmath_double1 o) {
		return stdmath_double1_equal_to(*self, o);
	}
	stdmath_bool1 _not_equal_to(stdmath_double1 o) {
		return stdmath_double1_not_equal_to(*self, o);
	}
	stdmath_bool1 _less_than(stdmath_double1 o) {
		return stdmath_double1_less_than(*self, o);
	}
	stdmath_bool1 _less_than_or_equal_to(stdmath_double1 o) {
		return stdmath_double1_less_than_or_equal_to(*self, o);
	}
	stdmath_bool1 _greater_than(stdmath_double1 o) {
		return stdmath_double1_greater_than(*self, o);
	}
	stdmath_bool1 _greater_than_or_equal_to(stdmath_double1 o) {
		return stdmath_double1_greater_than_or_equal_to(*self, o);
	}

	double _length_squared() {
		return stdmath_double1_length_squared(*self);
	}
	double _length() {
		return stdmath_double1_length(*self);
	}
	double _dot(stdmath_double1 o) {
		return stdmath_double1_dot(*self, o);
	}
	double _min_element() {
		return stdmath_double1_min_element(*self);
	}
	double _max_element() {
		return stdmath_double1_max_element(*self);
	}

	// double elementwise_transform()
	// double reduce_element

	stdmath_double1 _min(stdmath_double1 o) {
		return stdmath_double1_min(*self, o);
	}
	stdmath_double1 _max(stdmath_double1 o) {
		return stdmath_double1_max(*self, o);
	}
	stdmath_double1 _normalize() {
		return stdmath_double1_normalize(*self);
	}
	stdmath_double1 _lerp(stdmath_double1 o, float t) {
		return stdmath_double1_lerp(*self, o, t);
	}
	stdmath_double1 _clamp(stdmath_double1 min, stdmath_double1 max) {
		return stdmath_double1_clamp(*self, min, max);
	}
	stdmath_double1 _reflect(stdmath_double1 n) {
		return stdmath_double1_reflect(*self, n);
	}
	stdmath_bool1 _approximately_equal(stdmath_double1 o) {
		return stdmath_double1_approximately_equal(*self, o);
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

	double _get_element(size_t i) {
		return self->data[i];
	}

	double _set_element(size_t i, double value) {
		return self->data[i] = value;
	}
}