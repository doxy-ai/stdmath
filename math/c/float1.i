%rename(float1) stdmath_float1;
%include "float1.h"

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

%extend stdmath_float1 {
	stdmath_float1(float broadcast) {
		stdmath_float1 *v;
		v = (stdmath_float1 *) malloc(sizeof(stdmath_float1));
		*v = stdmath_float1_broadcast(broadcast);
		return v;
	}

#if 1 == 4
	stdmath_float1(float x = 0, float y = 0, float z = 0, float w = 0) {
		stdmath_float1 *v;
		v = (stdmath_float1 *) malloc(sizeof(stdmath_float1));
		v->x = x;
		v->y = y;
		v->z = z;
		v->w = w;
		return v;
	}
#elif 1 == 3
	stdmath_float1(float x = 0, float y = 0, float z = 0) {
		stdmath_float1 *v;
		v = (stdmath_float1 *) malloc(sizeof(stdmath_float1));
		v->x = x;
		v->y = y;
		v->z = z;
		return v;
	}
#elif 1 == 2
	stdmath_float1(float x = 0, float y = 0) {
		stdmath_float1 *v;
		v = (stdmath_float1 *) malloc(sizeof(stdmath_float1));
		v->x = x;
		v->y = y;
		return v;
	}
#elif 1 == 1
	stdmath_float1(float x = 0) {
		stdmath_float1 *v;
		v = (stdmath_float1 *) malloc(sizeof(stdmath_float1));
		v->x = x;
		return v;
	}
#endif



	stdmath_float1 _add(stdmath_float1 o) {
		return stdmath_float1_add(*self, o);
	}
	stdmath_float1 _subtract(stdmath_float1 o) {
		return stdmath_float1_subtract(*self, o);
	}
	stdmath_float1 _negate() {
		return stdmath_float1_negate(*self);
	}
	stdmath_float1 _multiply(stdmath_float1 o) {
		return stdmath_float1_multiply(*self, o);
	}
	stdmath_float1 _divide(stdmath_float1 o) {
		return stdmath_float1_divide(*self, o);
	}
	stdmath_float1 _scale(float o) {
		return stdmath_float1_scale(*self, o);
	}

#if false
	stdmath_float1 _modulus(stdmath_float1 o) {
		return stdmath_float1_modulus(*self, o);
	}
	stdmath_float1 _logical_not() {
		return stdmath_float1_logical_not(*self);
	}
	stdmath_float1 _bitwise_not() {
		return stdmath_float1_bitwise_not(*self);
	}
	stdmath_float1 _logical_and(stdmath_float1 o) {
		return stdmath_float1_logical_and(*self, o);
	}
	stdmath_float1 _bitwise_and(stdmath_float1 o) {
		return stdmath_float1_bitwise_and(*self, o);
	}
	stdmath_float1 _logical_or(stdmath_float1 o) {
		return stdmath_float1_logical_or(*self, o);
	}
	stdmath_float1 _bitwise_or(stdmath_float1 o) {
		return stdmath_float1_bitwise_or(*self, o);
	}
	stdmath_float1 _bitwise_xor(stdmath_float1 o) {
		return stdmath_float1_bitwise_xor(*self, o);
	}
	stdmath_float1 _shift_left(stdmath_float1 o) {
		return stdmath_float1_shift_left(*self, o);
	}
	stdmath_float1 _shift_right(stdmath_float1 o) {
		return stdmath_float1_shift_right(*self, o);
	}
#endif

	bool1 _equal_to(stdmath_float1 o) {
		return stdmath_float1_equal_to(*self, o);
	}
	bool1 _not_equal_to(stdmath_float1 o) {
		return stdmath_float1_not_equal_to(*self, o);
	}
	bool1 _less_than(stdmath_float1 o) {
		return stdmath_float1_less_than(*self, o);
	}
	bool1 _less_than_or_equal_to(stdmath_float1 o) {
		return stdmath_float1_less_than_or_equal_to(*self, o);
	}
	bool1 _greater_than(stdmath_float1 o) {
		return stdmath_float1_greater_than(*self, o);
	}
	bool1 _greater_than_or_equal_to(stdmath_float1 o) {
		return stdmath_float1_greater_than_or_equal_to(*self, o);
	}

	float _length_squared() {
		return stdmath_float1_length_squared(*self);
	}
	float _length() {
		return stdmath_float1_length(*self);
	}
	float _dot() {
		return stdmath_float1_dot(*self);
	}
	float _min_element() {
		return stdmath_float1_min_element(*self);
	}
	float _max_element() {
		return stdmath_float1_max_element(*self);
	}

	// float elementwise_transform()
	// float reduce_element

	stdmath_float1 _min(stdmath_float1 o) {
		return stdmath_float1_min(*self, o);
	}
	stdmath_float1 _max(stdmath_float1 o) {
		return stdmath_float1_max(*self, o);
	}
	stdmath_float1 _normalize() {
		return stdmath_float1_normalize(*self);
	}
	stdmath_float1 _lerp(stdmath_float1 o, float t) {
		return stdmath_float1_lerp(*self, o, t);
	}
	stdmath_float1 _clamp(stdmath_float1 min, stdmath_float1 max) {
		return stdmath_float1_clamp(*self, min, max);
	}
	stdmath_float1 _reflect(stdmath_float1 n) {
		return stdmath_float1_reflect(*self, n);
	}
	bool1 _approximately_equal(stdmath_float1 o) {
		return stdmath_float1_approximately_equal()
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

	float _get_element(size_t i) {
		return self->data[i];
	}

	float _set_element(size_t i, float value) {
		return self->data[i] = value;
	}
}
