%rename(byte2) stdmath_byte2;
%include "byte2.h"

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

%extend stdmath_byte2 {
	stdmath_byte2(uint8_t broadcast) {
		stdmath_byte2 *v;
		v = (stdmath_byte2 *) malloc(sizeof(stdmath_byte2));
		*v = stdmath_byte2_broadcast(broadcast);
		return v;
	}

#if 2 == 4
	stdmath_byte2(uint8_t x = 0, uint8_t y = 0, uint8_t z = 0, uint8_t w = 0) {
		stdmath_byte2 *v;
		v = (stdmath_byte2 *) malloc(sizeof(stdmath_byte2));
		v->x = x;
		v->y = y;
		v->z = z;
		v->w = w;
		return v;
	}
#elif 2 == 3
	stdmath_byte2(uint8_t x = 0, uint8_t y = 0, uint8_t z = 0) {
		stdmath_byte2 *v;
		v = (stdmath_byte2 *) malloc(sizeof(stdmath_byte2));
		v->x = x;
		v->y = y;
		v->z = z;
		return v;
	}
#elif 2 == 2
	stdmath_byte2(uint8_t x = 0, uint8_t y = 0) {
		stdmath_byte2 *v;
		v = (stdmath_byte2 *) malloc(sizeof(stdmath_byte2));
		v->x = x;
		v->y = y;
		return v;
	}
#elif 2 == 1
	stdmath_byte2(uint8_t x = 0) {
		stdmath_byte2 *v;
		v = (stdmath_byte2 *) malloc(sizeof(stdmath_byte2));
		v->x = x;
		return v;
	}
#endif

	stdmath_byte2 xx;
	stdmath_byte2 get_xx() { return {self->x,self->x}; }
	stdmath_byte2 set_xx(stdmath_byte2 value) { self->x = value.x; self->x = value.y; return *self; }

	stdmath_byte2 xy;
	stdmath_byte2 get_xy() { return {self->x,self->y}; }
	stdmath_byte2 set_xy(stdmath_byte2 value) { self->x = value.x; self->y = value.y; return *self; }

	stdmath_byte2 yx;
	stdmath_byte2 get_yx() { return {self->y,self->x}; }
	stdmath_byte2 set_yx(stdmath_byte2 value) { self->y = value.x; self->x = value.y; return *self; }

	stdmath_byte2 yy;
	stdmath_byte2 get_yy() { return {self->y,self->y}; }
	stdmath_byte2 set_yy(stdmath_byte2 value) { self->y = value.x; self->y = value.y; return *self; }



	stdmath_byte2 _add(stdmath_byte2 o) {
		return stdmath_byte2_add(*self, o);
	}
	stdmath_byte2 _subtract(stdmath_byte2 o) {
		return stdmath_byte2_subtract(*self, o);
	}
	stdmath_byte2 _negate() {
		return stdmath_byte2_negate(*self);
	}
	stdmath_byte2 _multiply(stdmath_byte2 o) {
		return stdmath_byte2_multiply(*self, o);
	}
	stdmath_byte2 _divide(stdmath_byte2 o) {
		return stdmath_byte2_divide(*self, o);
	}
	stdmath_byte2 _scale(uint8_t o) {
		return stdmath_byte2_scale(*self, o);
	}

#if false
	stdmath_byte2 _modulus(stdmath_byte2 o) {
		return stdmath_byte2_modulus(*self, o);
	}
	stdmath_byte2 _logical_not() {
		return stdmath_byte2_logical_not(*self);
	}
	stdmath_byte2 _bitwise_not() {
		return stdmath_byte2_bitwise_not(*self);
	}
	stdmath_byte2 _logical_and(stdmath_byte2 o) {
		return stdmath_byte2_logical_and(*self, o);
	}
	stdmath_byte2 _bitwise_and(stdmath_byte2 o) {
		return stdmath_byte2_bitwise_and(*self, o);
	}
	stdmath_byte2 _logical_or(stdmath_byte2 o) {
		return stdmath_byte2_logical_or(*self, o);
	}
	stdmath_byte2 _bitwise_or(stdmath_byte2 o) {
		return stdmath_byte2_bitwise_or(*self, o);
	}
	stdmath_byte2 _bitwise_xor(stdmath_byte2 o) {
		return stdmath_byte2_bitwise_xor(*self, o);
	}
	stdmath_byte2 _shift_left(stdmath_byte2 o) {
		return stdmath_byte2_shift_left(*self, o);
	}
	stdmath_byte2 _shift_right(stdmath_byte2 o) {
		return stdmath_byte2_shift_right(*self, o);
	}
#endif

	bool2 _equal_to(stdmath_byte2 o) {
		return stdmath_byte2_equal_to(*self, o);
	}
	bool2 _not_equal_to(stdmath_byte2 o) {
		return stdmath_byte2_not_equal_to(*self, o);
	}
	bool2 _less_than(stdmath_byte2 o) {
		return stdmath_byte2_less_than(*self, o);
	}
	bool2 _less_than_or_equal_to(stdmath_byte2 o) {
		return stdmath_byte2_less_than_or_equal_to(*self, o);
	}
	bool2 _greater_than(stdmath_byte2 o) {
		return stdmath_byte2_greater_than(*self, o);
	}
	bool2 _greater_than_or_equal_to(stdmath_byte2 o) {
		return stdmath_byte2_greater_than_or_equal_to(*self, o);
	}

	uint8_t _length_squared() {
		return stdmath_byte2_length_squared(*self);
	}
	uint8_t _length() {
		return stdmath_byte2_length(*self);
	}
	uint8_t _dot() {
		return stdmath_byte2_dot(*self);
	}
	uint8_t _min_element() {
		return stdmath_byte2_min_element(*self);
	}
	uint8_t _max_element() {
		return stdmath_byte2_max_element(*self);
	}

	// uint8_t elementwise_transform()
	// uint8_t reduce_element

	stdmath_byte2 _min(stdmath_byte2 o) {
		return stdmath_byte2_min(*self, o);
	}
	stdmath_byte2 _max(stdmath_byte2 o) {
		return stdmath_byte2_max(*self, o);
	}
	stdmath_byte2 _normalize() {
		return stdmath_byte2_normalize(*self);
	}
	stdmath_byte2 _lerp(stdmath_byte2 o, byte t) {
		return stdmath_byte2_lerp(*self, o, t);
	}
	stdmath_byte2 _clamp(stdmath_byte2 min, stdmath_byte2 max) {
		return stdmath_byte2_clamp(*self, min, max);
	}
	stdmath_byte2 _reflect(stdmath_byte2 n) {
		return stdmath_byte2_reflect(*self, n);
	}
	bool2 _approximately_equal(stdmath_byte2 o) {
		return stdmath_byte2_approximately_equal()
	}

#if false
	bool2 _all_of() {
		return bool2_all_of(*self);
	}
	bool2 _any_of() {
		return bool2_any_of(*self);
	}
	bool2 _none_of() {
		return bool2_none_of(*self);
	}
	bool2 _some_of() {
		return bool2_some_of(*self);
	}
#endif

	size_t _size() {
		return 2;
	}

	uint8_t _get_element(size_t i) {
		return self->data[i];
	}

	uint8_t _set_element(size_t i, uint8_t value) {
		return self->data[i] = value;
	}
}
