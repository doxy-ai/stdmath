%rename(int2) stdmath_int2;
%include "int2.h"

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

%extend stdmath_int2 {
	stdmath_int2(int32_t broadcast) {
		stdmath_int2 *v;
		v = (stdmath_int2 *) malloc(sizeof(stdmath_int2));
		*v = stdmath_int2_broadcast(broadcast);
		return v;
	}

#if 2 == 4
	stdmath_int2(int32_t x = 0, int32_t y = 0, int32_t z = 0, int32_t w = 0) {
		stdmath_int2 *v;
		v = (stdmath_int2 *) malloc(sizeof(stdmath_int2));
		v->x = x;
		v->y = y;
		v->z = z;
		v->w = w;
		return v;
	}
#elif 2 == 3
	stdmath_int2(int32_t x = 0, int32_t y = 0, int32_t z = 0) {
		stdmath_int2 *v;
		v = (stdmath_int2 *) malloc(sizeof(stdmath_int2));
		v->x = x;
		v->y = y;
		v->z = z;
		return v;
	}
#elif 2 == 2
	stdmath_int2(int32_t x = 0, int32_t y = 0) {
		stdmath_int2 *v;
		v = (stdmath_int2 *) malloc(sizeof(stdmath_int2));
		v->x = x;
		v->y = y;
		return v;
	}
#elif 2 == 1
	stdmath_int2(int32_t x = 0) {
		stdmath_int2 *v;
		v = (stdmath_int2 *) malloc(sizeof(stdmath_int2));
		v->x = x;
		return v;
	}
#endif

	stdmath_int2 xx;
	stdmath_int2 xy;
	stdmath_int2 yx;
	stdmath_int2 yy;


	stdmath_int2 _add(stdmath_int2 o) {
		return stdmath_int2_add(*self, o);
	}
	stdmath_int2 _subtract(stdmath_int2 o) {
		return stdmath_int2_subtract(*self, o);
	}
	stdmath_int2 _negate() {
		return stdmath_int2_negate(*self);
	}
	stdmath_int2 _multiply(stdmath_int2 o) {
		return stdmath_int2_multiply(*self, o);
	}
	stdmath_int2 _divide(stdmath_int2 o) {
		return stdmath_int2_divide(*self, o);
	}
	stdmath_int2 _scale(int32_t o) {
		return stdmath_int2_scale(*self, o);
	}

#if false
	stdmath_int2 _modulus(stdmath_int2 o) {
		return stdmath_int2_modulus(*self, o);
	}
	stdmath_int2 _logical_not() {
		return stdmath_int2_logical_not(*self);
	}
	stdmath_int2 _bitwise_not() {
		return stdmath_int2_bitwise_not(*self);
	}
	stdmath_int2 _logical_and(stdmath_int2 o) {
		return stdmath_int2_logical_and(*self, o);
	}
	stdmath_int2 _bitwise_and(stdmath_int2 o) {
		return stdmath_int2_bitwise_and(*self, o);
	}
	stdmath_int2 _logical_or(stdmath_int2 o) {
		return stdmath_int2_logical_or(*self, o);
	}
	stdmath_int2 _bitwise_or(stdmath_int2 o) {
		return stdmath_int2_bitwise_or(*self, o);
	}
	stdmath_int2 _bitwise_xor(stdmath_int2 o) {
		return stdmath_int2_bitwise_xor(*self, o);
	}
	stdmath_int2 _shift_left(stdmath_int2 o) {
		return stdmath_int2_shift_left(*self, o);
	}
	stdmath_int2 _shift_right(stdmath_int2 o) {
		return stdmath_int2_shift_right(*self, o);
	}
#endif

	stdmath_bool2 _equal_to(stdmath_int2 o) {
		return stdmath_int2_equal_to(*self, o);
	}
	stdmath_bool2 _not_equal_to(stdmath_int2 o) {
		return stdmath_int2_not_equal_to(*self, o);
	}
	stdmath_bool2 _less_than(stdmath_int2 o) {
		return stdmath_int2_less_than(*self, o);
	}
	stdmath_bool2 _less_than_or_equal_to(stdmath_int2 o) {
		return stdmath_int2_less_than_or_equal_to(*self, o);
	}
	stdmath_bool2 _greater_than(stdmath_int2 o) {
		return stdmath_int2_greater_than(*self, o);
	}
	stdmath_bool2 _greater_than_or_equal_to(stdmath_int2 o) {
		return stdmath_int2_greater_than_or_equal_to(*self, o);
	}

	int32_t _length_squared() {
		return stdmath_int2_length_squared(*self);
	}
	int32_t _length() {
		return stdmath_int2_length(*self);
	}
	int32_t _dot(stdmath_int2 o) {
		return stdmath_int2_dot(*self, o);
	}
	int32_t _min_element() {
		return stdmath_int2_min_element(*self);
	}
	int32_t _max_element() {
		return stdmath_int2_max_element(*self);
	}

	// int32_t elementwise_transform()
	// int32_t reduce_element

	stdmath_int2 _min(stdmath_int2 o) {
		return stdmath_int2_min(*self, o);
	}
	stdmath_int2 _max(stdmath_int2 o) {
		return stdmath_int2_max(*self, o);
	}
	stdmath_int2 _normalize() {
		return stdmath_int2_normalize(*self);
	}
	stdmath_int2 _lerp(stdmath_int2 o, float t) {
		return stdmath_int2_lerp(*self, o, t);
	}
	stdmath_int2 _clamp(stdmath_int2 min, stdmath_int2 max) {
		return stdmath_int2_clamp(*self, min, max);
	}
	stdmath_int2 _reflect(stdmath_int2 n) {
		return stdmath_int2_reflect(*self, n);
	}
	stdmath_bool2 _approximately_equal(stdmath_int2 o) {
		return stdmath_int2_approximately_equal(*self, o);
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

	int32_t _get_element(size_t i) {
		return self->data[i];
	}

	int32_t _set_element(size_t i, int32_t value) {
		return self->data[i] = value;
	}
}