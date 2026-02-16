%rename(uint1) stdmath_uint1;
%include "uint1.h"

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

%extend stdmath_uint1 {
	stdmath_uint1(uint32_t broadcast) {
		stdmath_uint1 *v;
		v = (stdmath_uint1 *) malloc(sizeof(stdmath_uint1));
		*v = stdmath_uint1_broadcast(broadcast);
		return v;
	}

#if 1 == 4
	stdmath_uint1(uint32_t x = 0, uint32_t y = 0, uint32_t z = 0, uint32_t w = 0) {
		stdmath_uint1 *v;
		v = (stdmath_uint1 *) malloc(sizeof(stdmath_uint1));
		v->x = x;
		v->y = y;
		v->z = z;
		v->w = w;
		return v;
	}
#elif 1 == 3
	stdmath_uint1(uint32_t x = 0, uint32_t y = 0, uint32_t z = 0) {
		stdmath_uint1 *v;
		v = (stdmath_uint1 *) malloc(sizeof(stdmath_uint1));
		v->x = x;
		v->y = y;
		v->z = z;
		return v;
	}
#elif 1 == 2
	stdmath_uint1(uint32_t x = 0, uint32_t y = 0) {
		stdmath_uint1 *v;
		v = (stdmath_uint1 *) malloc(sizeof(stdmath_uint1));
		v->x = x;
		v->y = y;
		return v;
	}
#elif 1 == 1
	stdmath_uint1(uint32_t x = 0) {
		stdmath_uint1 *v;
		v = (stdmath_uint1 *) malloc(sizeof(stdmath_uint1));
		v->x = x;
		return v;
	}
#endif



	stdmath_uint1 _add(stdmath_uint1 o) {
		return stdmath_uint1_add(*self, o);
	}
	stdmath_uint1 _subtract(stdmath_uint1 o) {
		return stdmath_uint1_subtract(*self, o);
	}
	stdmath_uint1 _negate() {
		return stdmath_uint1_negate(*self);
	}
	stdmath_uint1 _multiply(stdmath_uint1 o) {
		return stdmath_uint1_multiply(*self, o);
	}
	stdmath_uint1 _divide(stdmath_uint1 o) {
		return stdmath_uint1_divide(*self, o);
	}
	stdmath_uint1 _scale(uint32_t o) {
		return stdmath_uint1_scale(*self, o);
	}

#if false
	stdmath_uint1 _modulus(stdmath_uint1 o) {
		return stdmath_uint1_modulus(*self, o);
	}
	stdmath_uint1 _logical_not() {
		return stdmath_uint1_logical_not(*self);
	}
	stdmath_uint1 _bitwise_not() {
		return stdmath_uint1_bitwise_not(*self);
	}
	stdmath_uint1 _logical_and(stdmath_uint1 o) {
		return stdmath_uint1_logical_and(*self, o);
	}
	stdmath_uint1 _bitwise_and(stdmath_uint1 o) {
		return stdmath_uint1_bitwise_and(*self, o);
	}
	stdmath_uint1 _logical_or(stdmath_uint1 o) {
		return stdmath_uint1_logical_or(*self, o);
	}
	stdmath_uint1 _bitwise_or(stdmath_uint1 o) {
		return stdmath_uint1_bitwise_or(*self, o);
	}
	stdmath_uint1 _bitwise_xor(stdmath_uint1 o) {
		return stdmath_uint1_bitwise_xor(*self, o);
	}
	stdmath_uint1 _shift_left(stdmath_uint1 o) {
		return stdmath_uint1_shift_left(*self, o);
	}
	stdmath_uint1 _shift_right(stdmath_uint1 o) {
		return stdmath_uint1_shift_right(*self, o);
	}
#endif

	stdmath_bool1 _equal_to(stdmath_uint1 o) {
		return stdmath_uint1_equal_to(*self, o);
	}
	stdmath_bool1 _not_equal_to(stdmath_uint1 o) {
		return stdmath_uint1_not_equal_to(*self, o);
	}
	stdmath_bool1 _less_than(stdmath_uint1 o) {
		return stdmath_uint1_less_than(*self, o);
	}
	stdmath_bool1 _less_than_or_equal_to(stdmath_uint1 o) {
		return stdmath_uint1_less_than_or_equal_to(*self, o);
	}
	stdmath_bool1 _greater_than(stdmath_uint1 o) {
		return stdmath_uint1_greater_than(*self, o);
	}
	stdmath_bool1 _greater_than_or_equal_to(stdmath_uint1 o) {
		return stdmath_uint1_greater_than_or_equal_to(*self, o);
	}

	uint32_t _length_squared() {
		return stdmath_uint1_length_squared(*self);
	}
	uint32_t _length() {
		return stdmath_uint1_length(*self);
	}
	uint32_t _dot(stdmath_uint1 o) {
		return stdmath_uint1_dot(*self, o);
	}
	uint32_t _min_element() {
		return stdmath_uint1_min_element(*self);
	}
	uint32_t _max_element() {
		return stdmath_uint1_max_element(*self);
	}

	// uint32_t elementwise_transform()
	// uint32_t reduce_element

	stdmath_uint1 _min(stdmath_uint1 o) {
		return stdmath_uint1_min(*self, o);
	}
	stdmath_uint1 _max(stdmath_uint1 o) {
		return stdmath_uint1_max(*self, o);
	}
	stdmath_uint1 _normalize() {
		return stdmath_uint1_normalize(*self);
	}
	stdmath_uint1 _lerp(stdmath_uint1 o, float t) {
		return stdmath_uint1_lerp(*self, o, t);
	}
	stdmath_uint1 _clamp(stdmath_uint1 min, stdmath_uint1 max) {
		return stdmath_uint1_clamp(*self, min, max);
	}
	stdmath_uint1 _reflect(stdmath_uint1 n) {
		return stdmath_uint1_reflect(*self, n);
	}
	stdmath_bool1 _approximately_equal(stdmath_uint1 o) {
		return stdmath_uint1_approximately_equal(*self, o);
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

	uint32_t _get_element(size_t i) {
		return self->data[i];
	}

	uint32_t _set_element(size_t i, uint32_t value) {
		return self->data[i] = value;
	}
}