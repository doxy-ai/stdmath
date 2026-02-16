%rename(bool2) stdmath_bool2;
%include "bool2.h"

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

%extend stdmath_bool2 {
	stdmath_bool2(bool broadcast) {
		stdmath_bool2 *v;
		v = (stdmath_bool2 *) malloc(sizeof(stdmath_bool2));
		*v = stdmath_bool2_broadcast(broadcast);
		return v;
	}

#if 2 == 4
	stdmath_bool2(bool x = 0, bool y = 0, bool z = 0, bool w = 0) {
		stdmath_bool2 *v;
		v = (stdmath_bool2 *) malloc(sizeof(stdmath_bool2));
		v->x = x;
		v->y = y;
		v->z = z;
		v->w = w;
		return v;
	}
#elif 2 == 3
	stdmath_bool2(bool x = 0, bool y = 0, bool z = 0) {
		stdmath_bool2 *v;
		v = (stdmath_bool2 *) malloc(sizeof(stdmath_bool2));
		v->x = x;
		v->y = y;
		v->z = z;
		return v;
	}
#elif 2 == 2
	stdmath_bool2(bool x = 0, bool y = 0) {
		stdmath_bool2 *v;
		v = (stdmath_bool2 *) malloc(sizeof(stdmath_bool2));
		v->x = x;
		v->y = y;
		return v;
	}
#elif 2 == 1
	stdmath_bool2(bool x = 0) {
		stdmath_bool2 *v;
		v = (stdmath_bool2 *) malloc(sizeof(stdmath_bool2));
		v->x = x;
		return v;
	}
#endif

	stdmath_bool2 xx;
	stdmath_bool2 xy;
	stdmath_bool2 yx;
	stdmath_bool2 yy;


	stdmath_bool2 _add(stdmath_bool2 o) {
		return stdmath_bool2_add(*self, o);
	}
	stdmath_bool2 _subtract(stdmath_bool2 o) {
		return stdmath_bool2_subtract(*self, o);
	}
	stdmath_bool2 _negate() {
		return stdmath_bool2_negate(*self);
	}
	stdmath_bool2 _multiply(stdmath_bool2 o) {
		return stdmath_bool2_multiply(*self, o);
	}
	stdmath_bool2 _divide(stdmath_bool2 o) {
		return stdmath_bool2_divide(*self, o);
	}
	stdmath_bool2 _scale(bool o) {
		return stdmath_bool2_scale(*self, o);
	}

#if false
	stdmath_bool2 _modulus(stdmath_bool2 o) {
		return stdmath_bool2_modulus(*self, o);
	}
	stdmath_bool2 _logical_not() {
		return stdmath_bool2_logical_not(*self);
	}
	stdmath_bool2 _bitwise_not() {
		return stdmath_bool2_bitwise_not(*self);
	}
	stdmath_bool2 _logical_and(stdmath_bool2 o) {
		return stdmath_bool2_logical_and(*self, o);
	}
	stdmath_bool2 _bitwise_and(stdmath_bool2 o) {
		return stdmath_bool2_bitwise_and(*self, o);
	}
	stdmath_bool2 _logical_or(stdmath_bool2 o) {
		return stdmath_bool2_logical_or(*self, o);
	}
	stdmath_bool2 _bitwise_or(stdmath_bool2 o) {
		return stdmath_bool2_bitwise_or(*self, o);
	}
	stdmath_bool2 _bitwise_xor(stdmath_bool2 o) {
		return stdmath_bool2_bitwise_xor(*self, o);
	}
	stdmath_bool2 _shift_left(stdmath_bool2 o) {
		return stdmath_bool2_shift_left(*self, o);
	}
	stdmath_bool2 _shift_right(stdmath_bool2 o) {
		return stdmath_bool2_shift_right(*self, o);
	}
#endif

	stdmath_bool2 _equal_to(stdmath_bool2 o) {
		return stdmath_bool2_equal_to(*self, o);
	}
	stdmath_bool2 _not_equal_to(stdmath_bool2 o) {
		return stdmath_bool2_not_equal_to(*self, o);
	}
	stdmath_bool2 _less_than(stdmath_bool2 o) {
		return stdmath_bool2_less_than(*self, o);
	}
	stdmath_bool2 _less_than_or_equal_to(stdmath_bool2 o) {
		return stdmath_bool2_less_than_or_equal_to(*self, o);
	}
	stdmath_bool2 _greater_than(stdmath_bool2 o) {
		return stdmath_bool2_greater_than(*self, o);
	}
	stdmath_bool2 _greater_than_or_equal_to(stdmath_bool2 o) {
		return stdmath_bool2_greater_than_or_equal_to(*self, o);
	}

	bool _length_squared() {
		return stdmath_bool2_length_squared(*self);
	}
	bool _length() {
		return stdmath_bool2_length(*self);
	}
	bool _dot(stdmath_bool2 o) {
		return stdmath_bool2_dot(*self, o);
	}
	bool _min_element() {
		return stdmath_bool2_min_element(*self);
	}
	bool _max_element() {
		return stdmath_bool2_max_element(*self);
	}

	// bool elementwise_transform()
	// bool reduce_element

	stdmath_bool2 _min(stdmath_bool2 o) {
		return stdmath_bool2_min(*self, o);
	}
	stdmath_bool2 _max(stdmath_bool2 o) {
		return stdmath_bool2_max(*self, o);
	}
	stdmath_bool2 _normalize() {
		return stdmath_bool2_normalize(*self);
	}
	stdmath_bool2 _lerp(stdmath_bool2 o, float t) {
		return stdmath_bool2_lerp(*self, o, t);
	}
	stdmath_bool2 _clamp(stdmath_bool2 min, stdmath_bool2 max) {
		return stdmath_bool2_clamp(*self, min, max);
	}
	stdmath_bool2 _reflect(stdmath_bool2 n) {
		return stdmath_bool2_reflect(*self, n);
	}
	stdmath_bool2 _approximately_equal(stdmath_bool2 o) {
		return stdmath_bool2_approximately_equal(*self, o);
	}

#if true
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

	bool _get_element(size_t i) {
		return self->data[i];
	}

	bool _set_element(size_t i, bool value) {
		return self->data[i] = value;
	}
}