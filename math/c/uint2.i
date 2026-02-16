%rename(uint2) stdmath_uint2;
%include "uint2.h"

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

%extend stdmath_uint2 {
	stdmath_uint2(uint32_t broadcast) {
		stdmath_uint2 *v;
		v = (stdmath_uint2 *) malloc(sizeof(stdmath_uint2));
		*v = stdmath_uint2_broadcast(broadcast);
		return v;
	}

#if 2 == 4
	stdmath_uint2(uint32_t x = 0, uint32_t y = 0, uint32_t z = 0, uint32_t w = 0) {
		stdmath_uint2 *v;
		v = (stdmath_uint2 *) malloc(sizeof(stdmath_uint2));
		v->x = x;
		v->y = y;
		v->z = z;
		v->w = w;
		return v;
	}
#elif 2 == 3
	stdmath_uint2(uint32_t x = 0, uint32_t y = 0, uint32_t z = 0) {
		stdmath_uint2 *v;
		v = (stdmath_uint2 *) malloc(sizeof(stdmath_uint2));
		v->x = x;
		v->y = y;
		v->z = z;
		return v;
	}
#elif 2 == 2
	stdmath_uint2(uint32_t x = 0, uint32_t y = 0) {
		stdmath_uint2 *v;
		v = (stdmath_uint2 *) malloc(sizeof(stdmath_uint2));
		v->x = x;
		v->y = y;
		return v;
	}
#elif 2 == 1
	stdmath_uint2(uint32_t x = 0) {
		stdmath_uint2 *v;
		v = (stdmath_uint2 *) malloc(sizeof(stdmath_uint2));
		v->x = x;
		return v;
	}
#endif

	stdmath_uint2 xx;
	stdmath_uint2 get_xx() { return {self->x,self->x}; }
	stdmath_uint2 set_xx(stdmath_uint2 value) { self->x = value.x; self->x = value.y; return *self; }

	stdmath_uint2 xy;
	stdmath_uint2 get_xy() { return {self->x,self->y}; }
	stdmath_uint2 set_xy(stdmath_uint2 value) { self->x = value.x; self->y = value.y; return *self; }

	stdmath_uint2 yx;
	stdmath_uint2 get_yx() { return {self->y,self->x}; }
	stdmath_uint2 set_yx(stdmath_uint2 value) { self->y = value.x; self->x = value.y; return *self; }

	stdmath_uint2 yy;
	stdmath_uint2 get_yy() { return {self->y,self->y}; }
	stdmath_uint2 set_yy(stdmath_uint2 value) { self->y = value.x; self->y = value.y; return *self; }



	stdmath_uint2 _add(stdmath_uint2 o) {
		return stdmath_uint2_add(*self, o);
	}
	stdmath_uint2 _subtract(stdmath_uint2 o) {
		return stdmath_uint2_subtract(*self, o);
	}
	stdmath_uint2 _negate() {
		return stdmath_uint2_negate(*self);
	}
	stdmath_uint2 _multiply(stdmath_uint2 o) {
		return stdmath_uint2_multiply(*self, o);
	}
	stdmath_uint2 _divide(stdmath_uint2 o) {
		return stdmath_uint2_divide(*self, o);
	}
	stdmath_uint2 _scale(uint32_t o) {
		return stdmath_uint2_scale(*self, o);
	}

#if false
	stdmath_uint2 _modulus(stdmath_uint2 o) {
		return stdmath_uint2_modulus(*self, o);
	}
	stdmath_uint2 _logical_not() {
		return stdmath_uint2_logical_not(*self);
	}
	stdmath_uint2 _bitwise_not() {
		return stdmath_uint2_bitwise_not(*self);
	}
	stdmath_uint2 _logical_and(stdmath_uint2 o) {
		return stdmath_uint2_logical_and(*self, o);
	}
	stdmath_uint2 _bitwise_and(stdmath_uint2 o) {
		return stdmath_uint2_bitwise_and(*self, o);
	}
	stdmath_uint2 _logical_or(stdmath_uint2 o) {
		return stdmath_uint2_logical_or(*self, o);
	}
	stdmath_uint2 _bitwise_or(stdmath_uint2 o) {
		return stdmath_uint2_bitwise_or(*self, o);
	}
	stdmath_uint2 _bitwise_xor(stdmath_uint2 o) {
		return stdmath_uint2_bitwise_xor(*self, o);
	}
	stdmath_uint2 _shift_left(stdmath_uint2 o) {
		return stdmath_uint2_shift_left(*self, o);
	}
	stdmath_uint2 _shift_right(stdmath_uint2 o) {
		return stdmath_uint2_shift_right(*self, o);
	}
#endif

	bool2 _equal_to(stdmath_uint2 o) {
		return stdmath_uint2_equal_to(*self, o);
	}
	bool2 _not_equal_to(stdmath_uint2 o) {
		return stdmath_uint2_not_equal_to(*self, o);
	}
	bool2 _less_than(stdmath_uint2 o) {
		return stdmath_uint2_less_than(*self, o);
	}
	bool2 _less_than_or_equal_to(stdmath_uint2 o) {
		return stdmath_uint2_less_than_or_equal_to(*self, o);
	}
	bool2 _greater_than(stdmath_uint2 o) {
		return stdmath_uint2_greater_than(*self, o);
	}
	bool2 _greater_than_or_equal_to(stdmath_uint2 o) {
		return stdmath_uint2_greater_than_or_equal_to(*self, o);
	}

	uint32_t _length_squared() {
		return stdmath_uint2_length_squared(*self);
	}
	uint32_t _length() {
		return stdmath_uint2_length(*self);
	}
	uint32_t _dot() {
		return stdmath_uint2_dot(*self);
	}
	uint32_t _min_element() {
		return stdmath_uint2_min_element(*self);
	}
	uint32_t _max_element() {
		return stdmath_uint2_max_element(*self);
	}

	// uint32_t elementwise_transform()
	// uint32_t reduce_element

	stdmath_uint2 _min(stdmath_uint2 o) {
		return stdmath_uint2_min(*self, o);
	}
	stdmath_uint2 _max(stdmath_uint2 o) {
		return stdmath_uint2_max(*self, o);
	}
	stdmath_uint2 _normalize() {
		return stdmath_uint2_normalize(*self);
	}
	stdmath_uint2 _lerp(stdmath_uint2 o, uint t) {
		return stdmath_uint2_lerp(*self, o, t);
	}
	stdmath_uint2 _clamp(stdmath_uint2 min, stdmath_uint2 max) {
		return stdmath_uint2_clamp(*self, min, max);
	}
	stdmath_uint2 _reflect(stdmath_uint2 n) {
		return stdmath_uint2_reflect(*self, n);
	}
	bool2 _approximately_equal(stdmath_uint2 o) {
		return stdmath_uint2_approximately_equal()
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

	uint32_t _get_element(size_t i) {
		return self->data[i];
	}

	uint32_t _set_element(size_t i, uint32_t value) {
		return self->data[i] = value;
	}
}
