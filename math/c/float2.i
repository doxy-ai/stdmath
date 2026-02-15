%rename(float2) stdmath_float2;
%include "float2.h"

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

%extend stdmath_float2 {
	stdmath_float2(float broadcast) {
		stdmath_float2 *v;
		v = (stdmath_float2 *) malloc(sizeof(stdmath_float2));
		*v = stdmath_float2_broadcast(broadcast);
		return v;
	}

#if 2 == 4
	stdmath_float2(float x = 0, float y = 0, float z = 0, float w = 0) {
		stdmath_float2 *v;
		v = (stdmath_float2 *) malloc(sizeof(stdmath_float2));
		v->x = x;
		v->y = y;
		v->z = z;
		v->w = w;
		return v;
	}
#elif 2 == 3
	stdmath_float2(float x = 0, float y = 0, float z = 0) {
		stdmath_float2 *v;
		v = (stdmath_float2 *) malloc(sizeof(stdmath_float2));
		v->x = x;
		v->y = y;
		v->z = z;
		return v;
	}
#elif 2 == 2
	stdmath_float2(float x = 0, float y = 0) {
		stdmath_float2 *v;
		v = (stdmath_float2 *) malloc(sizeof(stdmath_float2));
		v->x = x;
		v->y = y;
		return v;
	}
#elif 2 == 1
	stdmath_float2(float x = 0) {
		stdmath_float2 *v;
		v = (stdmath_float2 *) malloc(sizeof(stdmath_float2));
		v->x = x;
		return v;
	}
#endif

	stdmath_float2 xx;
	stdmath_float2 get_xx() { return {self->x,self->x}; }
	stdmath_float2 set_xx(stdmath_float2 value) { self->x = value.x; self->x = value.y; return *self; }

	stdmath_float2 xy;
	stdmath_float2 get_xy() { return {self->x,self->y}; }
	stdmath_float2 set_xy(stdmath_float2 value) { self->x = value.x; self->y = value.y; return *self; }

	stdmath_float2 yx;
	stdmath_float2 get_yx() { return {self->y,self->x}; }
	stdmath_float2 set_yx(stdmath_float2 value) { self->y = value.x; self->x = value.y; return *self; }

	stdmath_float2 yy;
	stdmath_float2 get_yy() { return {self->y,self->y}; }
	stdmath_float2 set_yy(stdmath_float2 value) { self->y = value.x; self->y = value.y; return *self; }



	stdmath_float2 _add(stdmath_float2 o) {
		return stdmath_float2_add(*self, o);
	}
	stdmath_float2 _subtract(stdmath_float2 o) {
		return stdmath_float2_subtract(*self, o);
	}
	stdmath_float2 _negate() {
		return stdmath_float2_negate(*self);
	}
	stdmath_float2 _multiply(stdmath_float2 o) {
		return stdmath_float2_multiply(*self, o);
	}
	stdmath_float2 _divide(stdmath_float2 o) {
		return stdmath_float2_divide(*self, o);
	}
	stdmath_float2 _scale(float o) {
		return stdmath_float2_scale(*self, o);
	}

#if false
	stdmath_float2 _modulus(stdmath_float2 o) {
		return stdmath_float2_modulus(*self, o);
	}
	stdmath_float2 _logical_not() {
		return stdmath_float2_logical_not(*self);
	}
	stdmath_float2 _bitwise_not() {
		return stdmath_float2_bitwise_not(*self);
	}
	stdmath_float2 _logical_and(stdmath_float2 o) {
		return stdmath_float2_logical_and(*self, o);
	}
	stdmath_float2 _bitwise_and(stdmath_float2 o) {
		return stdmath_float2_bitwise_and(*self, o);
	}
	stdmath_float2 _logical_or(stdmath_float2 o) {
		return stdmath_float2_logical_or(*self, o);
	}
	stdmath_float2 _bitwise_or(stdmath_float2 o) {
		return stdmath_float2_bitwise_or(*self, o);
	}
	stdmath_float2 _bitwise_xor(stdmath_float2 o) {
		return stdmath_float2_bitwise_xor(*self, o);
	}
	stdmath_float2 _shift_left(stdmath_float2 o) {
		return stdmath_float2_shift_left(*self, o);
	}
	stdmath_float2 _shift_right(stdmath_float2 o) {
		return stdmath_float2_shift_right(*self, o);
	}
#endif

	bool2 _equal_to(stdmath_float2 o) {
		return stdmath_float2_equal_to(*self, o);
	}
	bool2 _not_equal_to(stdmath_float2 o) {
		return stdmath_float2_not_equal_to(*self, o);
	}
	bool2 _less_than(stdmath_float2 o) {
		return stdmath_float2_less_than(*self, o);
	}
	bool2 _less_than_or_equal_to(stdmath_float2 o) {
		return stdmath_float2_less_than_or_equal_to(*self, o);
	}
	bool2 _greater_than(stdmath_float2 o) {
		return stdmath_float2_greater_than(*self, o);
	}
	bool2 _greater_than_or_equal_to(stdmath_float2 o) {
		return stdmath_float2_greater_than_or_equal_to(*self, o);
	}
	
	float _length_squared() {
		return stdmath_float2_length_squared(*self);
	}
	float _length() {
		return stdmath_float2_length(*self);
	}
	float _dot() {
		return stdmath_float2_dot(*self);
	}
	float _min_element() {
		return stdmath_float2_min_element(*self);
	}
	float _max_element() {
		return stdmath_float2_max_element(*self);
	}

	// float elementwise_transform()
	// float reduce_element
	
	stdmath_float2 _min(stdmath_float2 o) {
		return stdmath_float2_min(*self, o);
	}
	stdmath_float2 _max(stdmath_float2 o) {
		return stdmath_float2_max(*self, o);
	}
	stdmath_float2 _normalize() {
		return stdmath_float2_normalize(*self);
	}
	stdmath_float2 _lerp(stdmath_float2 o, float t) {
		return stdmath_float2_lerp(*self, o, t);
	}
	stdmath_float2 _clamp(stdmath_float2 min, stdmath_float2 max) {
		return stdmath_float2_clamp(*self, min, max);
	}
	stdmath_float2 _reflect(stdmath_float2 n) {
		return stdmath_float2_reflect(*self, n);
	}
	bool2 _approximately_equal(stdmath_float2 o) {
		return stdmath_float2_approximately_equal()
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

	float _get_element(size_t i) {
		return self->data[i];
	}

	float _set_element(size_t i, float value) {
		return self->data[i] = value;
	}
}
