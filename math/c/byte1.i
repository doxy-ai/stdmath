%rename(byte1) stdmath_byte1;
%include "byte1.h"

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

%extend stdmath_byte1 {
	stdmath_byte1(uint8_t broadcast) {
		stdmath_byte1 *v;
		v = (stdmath_byte1 *) malloc(sizeof(stdmath_byte1));
		*v = stdmath_byte1_broadcast(broadcast);
		return v;
	}

#if 1 == 4
	stdmath_byte1(uint8_t x = 0, uint8_t y = 0, uint8_t z = 0, uint8_t w = 0) {
		stdmath_byte1 *v;
		v = (stdmath_byte1 *) malloc(sizeof(stdmath_byte1));
		v->x = x;
		v->y = y;
		v->z = z;
		v->w = w;
		return v;
	}
#elif 1 == 3
	stdmath_byte1(uint8_t x = 0, uint8_t y = 0, uint8_t z = 0) {
		stdmath_byte1 *v;
		v = (stdmath_byte1 *) malloc(sizeof(stdmath_byte1));
		v->x = x;
		v->y = y;
		v->z = z;
		return v;
	}
#elif 1 == 2
	stdmath_byte1(uint8_t x = 0, uint8_t y = 0) {
		stdmath_byte1 *v;
		v = (stdmath_byte1 *) malloc(sizeof(stdmath_byte1));
		v->x = x;
		v->y = y;
		return v;
	}
#elif 1 == 1
	stdmath_byte1(uint8_t x = 0) {
		stdmath_byte1 *v;
		v = (stdmath_byte1 *) malloc(sizeof(stdmath_byte1));
		v->x = x;
		return v;
	}
#endif



	stdmath_byte1 _add(stdmath_byte1 o) {
		return stdmath_byte1_add(*self, o);
	}
	stdmath_byte1 _subtract(stdmath_byte1 o) {
		return stdmath_byte1_subtract(*self, o);
	}
	stdmath_byte1 _negate() {
		return stdmath_byte1_negate(*self);
	}
	stdmath_byte1 _multiply(stdmath_byte1 o) {
		return stdmath_byte1_multiply(*self, o);
	}
	stdmath_byte1 _divide(stdmath_byte1 o) {
		return stdmath_byte1_divide(*self, o);
	}
	stdmath_byte1 _scale(uint8_t o) {
		return stdmath_byte1_scale(*self, o);
	}

#if false
	stdmath_byte1 _modulus(stdmath_byte1 o) {
		return stdmath_byte1_modulus(*self, o);
	}
	stdmath_byte1 _logical_not() {
		return stdmath_byte1_logical_not(*self);
	}
	stdmath_byte1 _bitwise_not() {
		return stdmath_byte1_bitwise_not(*self);
	}
	stdmath_byte1 _logical_and(stdmath_byte1 o) {
		return stdmath_byte1_logical_and(*self, o);
	}
	stdmath_byte1 _bitwise_and(stdmath_byte1 o) {
		return stdmath_byte1_bitwise_and(*self, o);
	}
	stdmath_byte1 _logical_or(stdmath_byte1 o) {
		return stdmath_byte1_logical_or(*self, o);
	}
	stdmath_byte1 _bitwise_or(stdmath_byte1 o) {
		return stdmath_byte1_bitwise_or(*self, o);
	}
	stdmath_byte1 _bitwise_xor(stdmath_byte1 o) {
		return stdmath_byte1_bitwise_xor(*self, o);
	}
	stdmath_byte1 _shift_left(stdmath_byte1 o) {
		return stdmath_byte1_shift_left(*self, o);
	}
	stdmath_byte1 _shift_right(stdmath_byte1 o) {
		return stdmath_byte1_shift_right(*self, o);
	}
#endif

	bool1 _equal_to(stdmath_byte1 o) {
		return stdmath_byte1_equal_to(*self, o);
	}
	bool1 _not_equal_to(stdmath_byte1 o) {
		return stdmath_byte1_not_equal_to(*self, o);
	}
	bool1 _less_than(stdmath_byte1 o) {
		return stdmath_byte1_less_than(*self, o);
	}
	bool1 _less_than_or_equal_to(stdmath_byte1 o) {
		return stdmath_byte1_less_than_or_equal_to(*self, o);
	}
	bool1 _greater_than(stdmath_byte1 o) {
		return stdmath_byte1_greater_than(*self, o);
	}
	bool1 _greater_than_or_equal_to(stdmath_byte1 o) {
		return stdmath_byte1_greater_than_or_equal_to(*self, o);
	}

	uint8_t _length_squared() {
		return stdmath_byte1_length_squared(*self);
	}
	uint8_t _length() {
		return stdmath_byte1_length(*self);
	}
	uint8_t _dot() {
		return stdmath_byte1_dot(*self);
	}
	uint8_t _min_element() {
		return stdmath_byte1_min_element(*self);
	}
	uint8_t _max_element() {
		return stdmath_byte1_max_element(*self);
	}

	// uint8_t elementwise_transform()
	// uint8_t reduce_element

	stdmath_byte1 _min(stdmath_byte1 o) {
		return stdmath_byte1_min(*self, o);
	}
	stdmath_byte1 _max(stdmath_byte1 o) {
		return stdmath_byte1_max(*self, o);
	}
	stdmath_byte1 _normalize() {
		return stdmath_byte1_normalize(*self);
	}
	stdmath_byte1 _lerp(stdmath_byte1 o, byte t) {
		return stdmath_byte1_lerp(*self, o, t);
	}
	stdmath_byte1 _clamp(stdmath_byte1 min, stdmath_byte1 max) {
		return stdmath_byte1_clamp(*self, min, max);
	}
	stdmath_byte1 _reflect(stdmath_byte1 n) {
		return stdmath_byte1_reflect(*self, n);
	}
	bool1 _approximately_equal(stdmath_byte1 o) {
		return stdmath_byte1_approximately_equal()
	}

#if false
	bool1 _all_of() {
		return bool1_all_of(*self);
	}
	bool1 _any_of() {
		return bool1_any_of(*self);
	}
	bool1 _none_of() {
		return bool1_none_of(*self);
	}
	bool1 _some_of() {
		return bool1_some_of(*self);
	}
#endif

	size_t _size() {
		return 1;
	}

	uint8_t _get_element(size_t i) {
		return self->data[i];
	}

	uint8_t _set_element(size_t i, uint8_t value) {
		return self->data[i] = value;
	}
}
