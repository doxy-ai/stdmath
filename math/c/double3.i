%rename(double3) stdmath_double3;
%include "double3.h"

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

%extend stdmath_double3 {
	stdmath_double3(double broadcast) {
		stdmath_double3 *v;
		v = (stdmath_double3 *) malloc(sizeof(stdmath_double3));
		*v = stdmath_double3_broadcast(broadcast);
		return v;
	}

#if 3 == 4
	stdmath_double3(double x = 0, double y = 0, double z = 0, double w = 0) {
		stdmath_double3 *v;
		v = (stdmath_double3 *) malloc(sizeof(stdmath_double3));
		v->x = x;
		v->y = y;
		v->z = z;
		v->w = w;
		return v;
	}
#elif 3 == 3
	stdmath_double3(double x = 0, double y = 0, double z = 0) {
		stdmath_double3 *v;
		v = (stdmath_double3 *) malloc(sizeof(stdmath_double3));
		v->x = x;
		v->y = y;
		v->z = z;
		return v;
	}
#elif 3 == 2
	stdmath_double3(double x = 0, double y = 0) {
		stdmath_double3 *v;
		v = (stdmath_double3 *) malloc(sizeof(stdmath_double3));
		v->x = x;
		v->y = y;
		return v;
	}
#elif 3 == 1
	stdmath_double3(double x = 0) {
		stdmath_double3 *v;
		v = (stdmath_double3 *) malloc(sizeof(stdmath_double3));
		v->x = x;
		return v;
	}
#endif

	stdmath_double2 xx;
	stdmath_double2 get_xx() { return {self->x,self->x}; }
	stdmath_double3 set_xx(stdmath_double2 value) { self->x = value.x; self->x = value.y; return *self; }

	stdmath_double2 xy;
	stdmath_double2 get_xy() { return {self->x,self->y}; }
	stdmath_double3 set_xy(stdmath_double2 value) { self->x = value.x; self->y = value.y; return *self; }

	stdmath_double2 xz;
	stdmath_double2 get_xz() { return {self->x,self->z}; }
	stdmath_double3 set_xz(stdmath_double2 value) { self->x = value.x; self->z = value.y; return *self; }

	stdmath_double2 yx;
	stdmath_double2 get_yx() { return {self->y,self->x}; }
	stdmath_double3 set_yx(stdmath_double2 value) { self->y = value.x; self->x = value.y; return *self; }

	stdmath_double2 yy;
	stdmath_double2 get_yy() { return {self->y,self->y}; }
	stdmath_double3 set_yy(stdmath_double2 value) { self->y = value.x; self->y = value.y; return *self; }

	stdmath_double2 yz;
	stdmath_double2 get_yz() { return {self->y,self->z}; }
	stdmath_double3 set_yz(stdmath_double2 value) { self->y = value.x; self->z = value.y; return *self; }

	stdmath_double2 zx;
	stdmath_double2 get_zx() { return {self->z,self->x}; }
	stdmath_double3 set_zx(stdmath_double2 value) { self->z = value.x; self->x = value.y; return *self; }

	stdmath_double2 zy;
	stdmath_double2 get_zy() { return {self->z,self->y}; }
	stdmath_double3 set_zy(stdmath_double2 value) { self->z = value.x; self->y = value.y; return *self; }

	stdmath_double2 zz;
	stdmath_double2 get_zz() { return {self->z,self->z}; }
	stdmath_double3 set_zz(stdmath_double2 value) { self->z = value.x; self->z = value.y; return *self; }

	stdmath_double3 xxx;
	stdmath_double3 get_xxx() { return {self->x,self->x,self->x}; }
	stdmath_double3 set_xxx(stdmath_double3 value) { self->x = value.x; self->x = value.y; self->x = value.z; return *self; }

	stdmath_double3 xxy;
	stdmath_double3 get_xxy() { return {self->x,self->x,self->y}; }
	stdmath_double3 set_xxy(stdmath_double3 value) { self->x = value.x; self->x = value.y; self->y = value.z; return *self; }

	stdmath_double3 xxz;
	stdmath_double3 get_xxz() { return {self->x,self->x,self->z}; }
	stdmath_double3 set_xxz(stdmath_double3 value) { self->x = value.x; self->x = value.y; self->z = value.z; return *self; }

	stdmath_double3 xyx;
	stdmath_double3 get_xyx() { return {self->x,self->y,self->x}; }
	stdmath_double3 set_xyx(stdmath_double3 value) { self->x = value.x; self->y = value.y; self->x = value.z; return *self; }

	stdmath_double3 xyy;
	stdmath_double3 get_xyy() { return {self->x,self->y,self->y}; }
	stdmath_double3 set_xyy(stdmath_double3 value) { self->x = value.x; self->y = value.y; self->y = value.z; return *self; }

	stdmath_double3 xyz;
	stdmath_double3 get_xyz() { return {self->x,self->y,self->z}; }
	stdmath_double3 set_xyz(stdmath_double3 value) { self->x = value.x; self->y = value.y; self->z = value.z; return *self; }

	stdmath_double3 xzx;
	stdmath_double3 get_xzx() { return {self->x,self->z,self->x}; }
	stdmath_double3 set_xzx(stdmath_double3 value) { self->x = value.x; self->z = value.y; self->x = value.z; return *self; }

	stdmath_double3 xzy;
	stdmath_double3 get_xzy() { return {self->x,self->z,self->y}; }
	stdmath_double3 set_xzy(stdmath_double3 value) { self->x = value.x; self->z = value.y; self->y = value.z; return *self; }

	stdmath_double3 xzz;
	stdmath_double3 get_xzz() { return {self->x,self->z,self->z}; }
	stdmath_double3 set_xzz(stdmath_double3 value) { self->x = value.x; self->z = value.y; self->z = value.z; return *self; }

	stdmath_double3 yxx;
	stdmath_double3 get_yxx() { return {self->y,self->x,self->x}; }
	stdmath_double3 set_yxx(stdmath_double3 value) { self->y = value.x; self->x = value.y; self->x = value.z; return *self; }

	stdmath_double3 yxy;
	stdmath_double3 get_yxy() { return {self->y,self->x,self->y}; }
	stdmath_double3 set_yxy(stdmath_double3 value) { self->y = value.x; self->x = value.y; self->y = value.z; return *self; }

	stdmath_double3 yxz;
	stdmath_double3 get_yxz() { return {self->y,self->x,self->z}; }
	stdmath_double3 set_yxz(stdmath_double3 value) { self->y = value.x; self->x = value.y; self->z = value.z; return *self; }

	stdmath_double3 yyx;
	stdmath_double3 get_yyx() { return {self->y,self->y,self->x}; }
	stdmath_double3 set_yyx(stdmath_double3 value) { self->y = value.x; self->y = value.y; self->x = value.z; return *self; }

	stdmath_double3 yyy;
	stdmath_double3 get_yyy() { return {self->y,self->y,self->y}; }
	stdmath_double3 set_yyy(stdmath_double3 value) { self->y = value.x; self->y = value.y; self->y = value.z; return *self; }

	stdmath_double3 yyz;
	stdmath_double3 get_yyz() { return {self->y,self->y,self->z}; }
	stdmath_double3 set_yyz(stdmath_double3 value) { self->y = value.x; self->y = value.y; self->z = value.z; return *self; }

	stdmath_double3 yzx;
	stdmath_double3 get_yzx() { return {self->y,self->z,self->x}; }
	stdmath_double3 set_yzx(stdmath_double3 value) { self->y = value.x; self->z = value.y; self->x = value.z; return *self; }

	stdmath_double3 yzy;
	stdmath_double3 get_yzy() { return {self->y,self->z,self->y}; }
	stdmath_double3 set_yzy(stdmath_double3 value) { self->y = value.x; self->z = value.y; self->y = value.z; return *self; }

	stdmath_double3 yzz;
	stdmath_double3 get_yzz() { return {self->y,self->z,self->z}; }
	stdmath_double3 set_yzz(stdmath_double3 value) { self->y = value.x; self->z = value.y; self->z = value.z; return *self; }

	stdmath_double3 zxx;
	stdmath_double3 get_zxx() { return {self->z,self->x,self->x}; }
	stdmath_double3 set_zxx(stdmath_double3 value) { self->z = value.x; self->x = value.y; self->x = value.z; return *self; }

	stdmath_double3 zxy;
	stdmath_double3 get_zxy() { return {self->z,self->x,self->y}; }
	stdmath_double3 set_zxy(stdmath_double3 value) { self->z = value.x; self->x = value.y; self->y = value.z; return *self; }

	stdmath_double3 zxz;
	stdmath_double3 get_zxz() { return {self->z,self->x,self->z}; }
	stdmath_double3 set_zxz(stdmath_double3 value) { self->z = value.x; self->x = value.y; self->z = value.z; return *self; }

	stdmath_double3 zyx;
	stdmath_double3 get_zyx() { return {self->z,self->y,self->x}; }
	stdmath_double3 set_zyx(stdmath_double3 value) { self->z = value.x; self->y = value.y; self->x = value.z; return *self; }

	stdmath_double3 zyy;
	stdmath_double3 get_zyy() { return {self->z,self->y,self->y}; }
	stdmath_double3 set_zyy(stdmath_double3 value) { self->z = value.x; self->y = value.y; self->y = value.z; return *self; }

	stdmath_double3 zyz;
	stdmath_double3 get_zyz() { return {self->z,self->y,self->z}; }
	stdmath_double3 set_zyz(stdmath_double3 value) { self->z = value.x; self->y = value.y; self->z = value.z; return *self; }

	stdmath_double3 zzx;
	stdmath_double3 get_zzx() { return {self->z,self->z,self->x}; }
	stdmath_double3 set_zzx(stdmath_double3 value) { self->z = value.x; self->z = value.y; self->x = value.z; return *self; }

	stdmath_double3 zzy;
	stdmath_double3 get_zzy() { return {self->z,self->z,self->y}; }
	stdmath_double3 set_zzy(stdmath_double3 value) { self->z = value.x; self->z = value.y; self->y = value.z; return *self; }

	stdmath_double3 zzz;
	stdmath_double3 get_zzz() { return {self->z,self->z,self->z}; }
	stdmath_double3 set_zzz(stdmath_double3 value) { self->z = value.x; self->z = value.y; self->z = value.z; return *self; }



	stdmath_double3 _add(stdmath_double3 o) {
		return stdmath_double3_add(*self, o);
	}
	stdmath_double3 _subtract(stdmath_double3 o) {
		return stdmath_double3_subtract(*self, o);
	}
	stdmath_double3 _negate() {
		return stdmath_double3_negate(*self);
	}
	stdmath_double3 _multiply(stdmath_double3 o) {
		return stdmath_double3_multiply(*self, o);
	}
	stdmath_double3 _divide(stdmath_double3 o) {
		return stdmath_double3_divide(*self, o);
	}
	stdmath_double3 _scale(double o) {
		return stdmath_double3_scale(*self, o);
	}

#if false
	stdmath_double3 _modulus(stdmath_double3 o) {
		return stdmath_double3_modulus(*self, o);
	}
	stdmath_double3 _logical_not() {
		return stdmath_double3_logical_not(*self);
	}
	stdmath_double3 _bitwise_not() {
		return stdmath_double3_bitwise_not(*self);
	}
	stdmath_double3 _logical_and(stdmath_double3 o) {
		return stdmath_double3_logical_and(*self, o);
	}
	stdmath_double3 _bitwise_and(stdmath_double3 o) {
		return stdmath_double3_bitwise_and(*self, o);
	}
	stdmath_double3 _logical_or(stdmath_double3 o) {
		return stdmath_double3_logical_or(*self, o);
	}
	stdmath_double3 _bitwise_or(stdmath_double3 o) {
		return stdmath_double3_bitwise_or(*self, o);
	}
	stdmath_double3 _bitwise_xor(stdmath_double3 o) {
		return stdmath_double3_bitwise_xor(*self, o);
	}
	stdmath_double3 _shift_left(stdmath_double3 o) {
		return stdmath_double3_shift_left(*self, o);
	}
	stdmath_double3 _shift_right(stdmath_double3 o) {
		return stdmath_double3_shift_right(*self, o);
	}
#endif

	bool3 _equal_to(stdmath_double3 o) {
		return stdmath_double3_equal_to(*self, o);
	}
	bool3 _not_equal_to(stdmath_double3 o) {
		return stdmath_double3_not_equal_to(*self, o);
	}
	bool3 _less_than(stdmath_double3 o) {
		return stdmath_double3_less_than(*self, o);
	}
	bool3 _less_than_or_equal_to(stdmath_double3 o) {
		return stdmath_double3_less_than_or_equal_to(*self, o);
	}
	bool3 _greater_than(stdmath_double3 o) {
		return stdmath_double3_greater_than(*self, o);
	}
	bool3 _greater_than_or_equal_to(stdmath_double3 o) {
		return stdmath_double3_greater_than_or_equal_to(*self, o);
	}
	
	double _length_squared() {
		return stdmath_double3_length_squared(*self);
	}
	double _length() {
		return stdmath_double3_length(*self);
	}
	double _dot() {
		return stdmath_double3_dot(*self);
	}
	double _min_element() {
		return stdmath_double3_min_element(*self);
	}
	double _max_element() {
		return stdmath_double3_max_element(*self);
	}

	// double elementwise_transform()
	// double reduce_element
	
	stdmath_double3 _min(stdmath_double3 o) {
		return stdmath_double3_min(*self, o);
	}
	stdmath_double3 _max(stdmath_double3 o) {
		return stdmath_double3_max(*self, o);
	}
	stdmath_double3 _normalize() {
		return stdmath_double3_normalize(*self);
	}
	stdmath_double3 _lerp(stdmath_double3 o, double t) {
		return stdmath_double3_lerp(*self, o, t);
	}
	stdmath_double3 _clamp(stdmath_double3 min, stdmath_double3 max) {
		return stdmath_double3_clamp(*self, min, max);
	}
	stdmath_double3 _reflect(stdmath_double3 n) {
		return stdmath_double3_reflect(*self, n);
	}
	bool3 _approximately_equal(stdmath_double3 o) {
		return stdmath_double3_approximately_equal()
	}

#if false
	bool3 _all_of() {
		return bool3_all_of(*self);
	}
	bool3 _any_of() {
		return bool3_any_of(*self);
	}
	bool3 _none_of() {
		return bool3_none_of(*self);
	}
	bool3 _some_of() {
		return bool3_some_of(*self);
	}
#endif

	size_t _size() {
		return 3;
	}

	double _get_element(size_t i) {
		return self->data[i];
	}

	double _set_element(size_t i, double value) {
		return self->data[i] = value;
	}
}
