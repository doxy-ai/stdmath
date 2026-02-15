%rename(double2) stdmath_double2;
%include "double2.h"

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

%extend stdmath_double2 {
	stdmath_double2(double broadcast) {
		stdmath_double2 *v;
		v = (stdmath_double2 *) malloc(sizeof(stdmath_double2));
		*v = stdmath_double2_broadcast(broadcast);
		return v;
	}

#if 2 == 4
	stdmath_double2(double x = 0, double y = 0, double z = 0, double w = 0) {
		stdmath_double2 *v;
		v = (stdmath_double2 *) malloc(sizeof(stdmath_double2));
		v->x = x;
		v->y = y;
		v->z = z;
		v->w = w;
		return v;
	}
#elif 2 == 3
	stdmath_double2(double x = 0, double y = 0, double z = 0) {
		stdmath_double2 *v;
		v = (stdmath_double2 *) malloc(sizeof(stdmath_double2));
		v->x = x;
		v->y = y;
		v->z = z;
		return v;
	}
#elif 2 == 2
	stdmath_double2(double x = 0, double y = 0) {
		stdmath_double2 *v;
		v = (stdmath_double2 *) malloc(sizeof(stdmath_double2));
		v->x = x;
		v->y = y;
		return v;
	}
#elif 2 == 1
	stdmath_double2(double x = 0) {
		stdmath_double2 *v;
		v = (stdmath_double2 *) malloc(sizeof(stdmath_double2));
		v->x = x;
		return v;
	}
#endif

	stdmath_double2 xx;
	stdmath_double2 get_xx() { return {self->x,self->x}; }
	stdmath_double2 set_xx(stdmath_double2 value) { self->x = value.x; self->x = value.y; return *self; }

	stdmath_double2 xy;
	stdmath_double2 get_xy() { return {self->x,self->y}; }
	stdmath_double2 set_xy(stdmath_double2 value) { self->x = value.x; self->y = value.y; return *self; }

	stdmath_double2 yx;
	stdmath_double2 get_yx() { return {self->y,self->x}; }
	stdmath_double2 set_yx(stdmath_double2 value) { self->y = value.x; self->x = value.y; return *self; }

	stdmath_double2 yy;
	stdmath_double2 get_yy() { return {self->y,self->y}; }
	stdmath_double2 set_yy(stdmath_double2 value) { self->y = value.x; self->y = value.y; return *self; }



	stdmath_double2 _add(stdmath_double2 o) {
		return stdmath_double2_add(*self, o);
	}
	stdmath_double2 _subtract(stdmath_double2 o) {
		return stdmath_double2_subtract(*self, o);
	}
	stdmath_double2 _negate() {
		return stdmath_double2_negate(*self);
	}
	stdmath_double2 _multiply(stdmath_double2 o) {
		return stdmath_double2_multiply(*self, o);
	}
	stdmath_double2 _divide(stdmath_double2 o) {
		return stdmath_double2_divide(*self, o);
	}
	stdmath_double2 _scale(double o) {
		return stdmath_double2_scale(*self, o);
	}

#if false
	stdmath_double2 _modulus(stdmath_double2 o) {
		return stdmath_double2_modulus(*self, o);
	}
	stdmath_double2 _logical_not() {
		return stdmath_double2_logical_not(*self);
	}
	stdmath_double2 _bitwise_not() {
		return stdmath_double2_bitwise_not(*self);
	}
	stdmath_double2 _logical_and(stdmath_double2 o) {
		return stdmath_double2_logical_and(*self, o);
	}
	stdmath_double2 _bitwise_and(stdmath_double2 o) {
		return stdmath_double2_bitwise_and(*self, o);
	}
	stdmath_double2 _logical_or(stdmath_double2 o) {
		return stdmath_double2_logical_or(*self, o);
	}
	stdmath_double2 _bitwise_or(stdmath_double2 o) {
		return stdmath_double2_bitwise_or(*self, o);
	}
	stdmath_double2 _bitwise_xor(stdmath_double2 o) {
		return stdmath_double2_bitwise_xor(*self, o);
	}
	stdmath_double2 _shift_left(stdmath_double2 o) {
		return stdmath_double2_shift_left(*self, o);
	}
	stdmath_double2 _shift_right(stdmath_double2 o) {
		return stdmath_double2_shift_right(*self, o);
	}
#endif

	bool2 _equal_to(stdmath_double2 o) {
		return stdmath_double2_equal_to(*self, o);
	}
	bool2 _not_equal_to(stdmath_double2 o) {
		return stdmath_double2_not_equal_to(*self, o);
	}
	bool2 _less_than(stdmath_double2 o) {
		return stdmath_double2_less_than(*self, o);
	}
	bool2 _less_than_or_equal_to(stdmath_double2 o) {
		return stdmath_double2_less_than_or_equal_to(*self, o);
	}
	bool2 _greater_than(stdmath_double2 o) {
		return stdmath_double2_greater_than(*self, o);
	}
	bool2 _greater_than_or_equal_to(stdmath_double2 o) {
		return stdmath_double2_greater_than_or_equal_to(*self, o);
	}
	
	double _length_squared() {
		return stdmath_double2_length_squared(*self);
	}
	double _length() {
		return stdmath_double2_length(*self);
	}
	double _dot() {
		return stdmath_double2_dot(*self);
	}
	double _min_element() {
		return stdmath_double2_min_element(*self);
	}
	double _max_element() {
		return stdmath_double2_max_element(*self);
	}

	// double elementwise_transform()
	// double reduce_element
	
	stdmath_double2 _min(stdmath_double2 o) {
		return stdmath_double2_min(*self, o);
	}
	stdmath_double2 _max(stdmath_double2 o) {
		return stdmath_double2_max(*self, o);
	}
	stdmath_double2 _normalize() {
		return stdmath_double2_normalize(*self);
	}
	stdmath_double2 _lerp(stdmath_double2 o, double t) {
		return stdmath_double2_lerp(*self, o, t);
	}
	stdmath_double2 _clamp(stdmath_double2 min, stdmath_double2 max) {
		return stdmath_double2_clamp(*self, min, max);
	}
	stdmath_double2 _reflect(stdmath_double2 n) {
		return stdmath_double2_reflect(*self, n);
	}
	bool2 _approximately_equal(stdmath_double2 o) {
		return stdmath_double2_approximately_equal()
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

	double _get_element(size_t i) {
		return self->data[i];
	}

	double _set_element(size_t i, double value) {
		return self->data[i] = value;
	}
}
