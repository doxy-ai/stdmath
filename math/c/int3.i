%rename(int3) stdmath_int3;
%include "int3.h"

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

%extend stdmath_int3 {
	stdmath_int3(int32_t broadcast) {
		stdmath_int3 *v;
		v = (stdmath_int3 *) malloc(sizeof(stdmath_int3));
		*v = stdmath_int3_broadcast(broadcast);
		return v;
	}

#if 3 == 4
	stdmath_int3(int32_t x = 0, int32_t y = 0, int32_t z = 0, int32_t w = 0) {
		stdmath_int3 *v;
		v = (stdmath_int3 *) malloc(sizeof(stdmath_int3));
		v->x = x;
		v->y = y;
		v->z = z;
		v->w = w;
		return v;
	}
#elif 3 == 3
	stdmath_int3(int32_t x = 0, int32_t y = 0, int32_t z = 0) {
		stdmath_int3 *v;
		v = (stdmath_int3 *) malloc(sizeof(stdmath_int3));
		v->x = x;
		v->y = y;
		v->z = z;
		return v;
	}
#elif 3 == 2
	stdmath_int3(int32_t x = 0, int32_t y = 0) {
		stdmath_int3 *v;
		v = (stdmath_int3 *) malloc(sizeof(stdmath_int3));
		v->x = x;
		v->y = y;
		return v;
	}
#elif 3 == 1
	stdmath_int3(int32_t x = 0) {
		stdmath_int3 *v;
		v = (stdmath_int3 *) malloc(sizeof(stdmath_int3));
		v->x = x;
		return v;
	}
#endif

	stdmath_int2 xx;
	stdmath_int2 get_xx() { return {self->x,self->x}; }
	stdmath_int3 set_xx(stdmath_int2 value) { self->x = value.x; self->x = value.y; return *self; }

	stdmath_int2 xy;
	stdmath_int2 get_xy() { return {self->x,self->y}; }
	stdmath_int3 set_xy(stdmath_int2 value) { self->x = value.x; self->y = value.y; return *self; }

	stdmath_int2 xz;
	stdmath_int2 get_xz() { return {self->x,self->z}; }
	stdmath_int3 set_xz(stdmath_int2 value) { self->x = value.x; self->z = value.y; return *self; }

	stdmath_int2 yx;
	stdmath_int2 get_yx() { return {self->y,self->x}; }
	stdmath_int3 set_yx(stdmath_int2 value) { self->y = value.x; self->x = value.y; return *self; }

	stdmath_int2 yy;
	stdmath_int2 get_yy() { return {self->y,self->y}; }
	stdmath_int3 set_yy(stdmath_int2 value) { self->y = value.x; self->y = value.y; return *self; }

	stdmath_int2 yz;
	stdmath_int2 get_yz() { return {self->y,self->z}; }
	stdmath_int3 set_yz(stdmath_int2 value) { self->y = value.x; self->z = value.y; return *self; }

	stdmath_int2 zx;
	stdmath_int2 get_zx() { return {self->z,self->x}; }
	stdmath_int3 set_zx(stdmath_int2 value) { self->z = value.x; self->x = value.y; return *self; }

	stdmath_int2 zy;
	stdmath_int2 get_zy() { return {self->z,self->y}; }
	stdmath_int3 set_zy(stdmath_int2 value) { self->z = value.x; self->y = value.y; return *self; }

	stdmath_int2 zz;
	stdmath_int2 get_zz() { return {self->z,self->z}; }
	stdmath_int3 set_zz(stdmath_int2 value) { self->z = value.x; self->z = value.y; return *self; }

	stdmath_int3 xxx;
	stdmath_int3 get_xxx() { return {self->x,self->x,self->x}; }
	stdmath_int3 set_xxx(stdmath_int3 value) { self->x = value.x; self->x = value.y; self->x = value.z; return *self; }

	stdmath_int3 xxy;
	stdmath_int3 get_xxy() { return {self->x,self->x,self->y}; }
	stdmath_int3 set_xxy(stdmath_int3 value) { self->x = value.x; self->x = value.y; self->y = value.z; return *self; }

	stdmath_int3 xxz;
	stdmath_int3 get_xxz() { return {self->x,self->x,self->z}; }
	stdmath_int3 set_xxz(stdmath_int3 value) { self->x = value.x; self->x = value.y; self->z = value.z; return *self; }

	stdmath_int3 xyx;
	stdmath_int3 get_xyx() { return {self->x,self->y,self->x}; }
	stdmath_int3 set_xyx(stdmath_int3 value) { self->x = value.x; self->y = value.y; self->x = value.z; return *self; }

	stdmath_int3 xyy;
	stdmath_int3 get_xyy() { return {self->x,self->y,self->y}; }
	stdmath_int3 set_xyy(stdmath_int3 value) { self->x = value.x; self->y = value.y; self->y = value.z; return *self; }

	stdmath_int3 xyz;
	stdmath_int3 get_xyz() { return {self->x,self->y,self->z}; }
	stdmath_int3 set_xyz(stdmath_int3 value) { self->x = value.x; self->y = value.y; self->z = value.z; return *self; }

	stdmath_int3 xzx;
	stdmath_int3 get_xzx() { return {self->x,self->z,self->x}; }
	stdmath_int3 set_xzx(stdmath_int3 value) { self->x = value.x; self->z = value.y; self->x = value.z; return *self; }

	stdmath_int3 xzy;
	stdmath_int3 get_xzy() { return {self->x,self->z,self->y}; }
	stdmath_int3 set_xzy(stdmath_int3 value) { self->x = value.x; self->z = value.y; self->y = value.z; return *self; }

	stdmath_int3 xzz;
	stdmath_int3 get_xzz() { return {self->x,self->z,self->z}; }
	stdmath_int3 set_xzz(stdmath_int3 value) { self->x = value.x; self->z = value.y; self->z = value.z; return *self; }

	stdmath_int3 yxx;
	stdmath_int3 get_yxx() { return {self->y,self->x,self->x}; }
	stdmath_int3 set_yxx(stdmath_int3 value) { self->y = value.x; self->x = value.y; self->x = value.z; return *self; }

	stdmath_int3 yxy;
	stdmath_int3 get_yxy() { return {self->y,self->x,self->y}; }
	stdmath_int3 set_yxy(stdmath_int3 value) { self->y = value.x; self->x = value.y; self->y = value.z; return *self; }

	stdmath_int3 yxz;
	stdmath_int3 get_yxz() { return {self->y,self->x,self->z}; }
	stdmath_int3 set_yxz(stdmath_int3 value) { self->y = value.x; self->x = value.y; self->z = value.z; return *self; }

	stdmath_int3 yyx;
	stdmath_int3 get_yyx() { return {self->y,self->y,self->x}; }
	stdmath_int3 set_yyx(stdmath_int3 value) { self->y = value.x; self->y = value.y; self->x = value.z; return *self; }

	stdmath_int3 yyy;
	stdmath_int3 get_yyy() { return {self->y,self->y,self->y}; }
	stdmath_int3 set_yyy(stdmath_int3 value) { self->y = value.x; self->y = value.y; self->y = value.z; return *self; }

	stdmath_int3 yyz;
	stdmath_int3 get_yyz() { return {self->y,self->y,self->z}; }
	stdmath_int3 set_yyz(stdmath_int3 value) { self->y = value.x; self->y = value.y; self->z = value.z; return *self; }

	stdmath_int3 yzx;
	stdmath_int3 get_yzx() { return {self->y,self->z,self->x}; }
	stdmath_int3 set_yzx(stdmath_int3 value) { self->y = value.x; self->z = value.y; self->x = value.z; return *self; }

	stdmath_int3 yzy;
	stdmath_int3 get_yzy() { return {self->y,self->z,self->y}; }
	stdmath_int3 set_yzy(stdmath_int3 value) { self->y = value.x; self->z = value.y; self->y = value.z; return *self; }

	stdmath_int3 yzz;
	stdmath_int3 get_yzz() { return {self->y,self->z,self->z}; }
	stdmath_int3 set_yzz(stdmath_int3 value) { self->y = value.x; self->z = value.y; self->z = value.z; return *self; }

	stdmath_int3 zxx;
	stdmath_int3 get_zxx() { return {self->z,self->x,self->x}; }
	stdmath_int3 set_zxx(stdmath_int3 value) { self->z = value.x; self->x = value.y; self->x = value.z; return *self; }

	stdmath_int3 zxy;
	stdmath_int3 get_zxy() { return {self->z,self->x,self->y}; }
	stdmath_int3 set_zxy(stdmath_int3 value) { self->z = value.x; self->x = value.y; self->y = value.z; return *self; }

	stdmath_int3 zxz;
	stdmath_int3 get_zxz() { return {self->z,self->x,self->z}; }
	stdmath_int3 set_zxz(stdmath_int3 value) { self->z = value.x; self->x = value.y; self->z = value.z; return *self; }

	stdmath_int3 zyx;
	stdmath_int3 get_zyx() { return {self->z,self->y,self->x}; }
	stdmath_int3 set_zyx(stdmath_int3 value) { self->z = value.x; self->y = value.y; self->x = value.z; return *self; }

	stdmath_int3 zyy;
	stdmath_int3 get_zyy() { return {self->z,self->y,self->y}; }
	stdmath_int3 set_zyy(stdmath_int3 value) { self->z = value.x; self->y = value.y; self->y = value.z; return *self; }

	stdmath_int3 zyz;
	stdmath_int3 get_zyz() { return {self->z,self->y,self->z}; }
	stdmath_int3 set_zyz(stdmath_int3 value) { self->z = value.x; self->y = value.y; self->z = value.z; return *self; }

	stdmath_int3 zzx;
	stdmath_int3 get_zzx() { return {self->z,self->z,self->x}; }
	stdmath_int3 set_zzx(stdmath_int3 value) { self->z = value.x; self->z = value.y; self->x = value.z; return *self; }

	stdmath_int3 zzy;
	stdmath_int3 get_zzy() { return {self->z,self->z,self->y}; }
	stdmath_int3 set_zzy(stdmath_int3 value) { self->z = value.x; self->z = value.y; self->y = value.z; return *self; }

	stdmath_int3 zzz;
	stdmath_int3 get_zzz() { return {self->z,self->z,self->z}; }
	stdmath_int3 set_zzz(stdmath_int3 value) { self->z = value.x; self->z = value.y; self->z = value.z; return *self; }



	stdmath_int3 _add(stdmath_int3 o) {
		return stdmath_int3_add(*self, o);
	}
	stdmath_int3 _subtract(stdmath_int3 o) {
		return stdmath_int3_subtract(*self, o);
	}
	stdmath_int3 _negate() {
		return stdmath_int3_negate(*self);
	}
	stdmath_int3 _multiply(stdmath_int3 o) {
		return stdmath_int3_multiply(*self, o);
	}
	stdmath_int3 _divide(stdmath_int3 o) {
		return stdmath_int3_divide(*self, o);
	}
	stdmath_int3 _scale(int32_t o) {
		return stdmath_int3_scale(*self, o);
	}

#if false
	stdmath_int3 _modulus(stdmath_int3 o) {
		return stdmath_int3_modulus(*self, o);
	}
	stdmath_int3 _logical_not() {
		return stdmath_int3_logical_not(*self);
	}
	stdmath_int3 _bitwise_not() {
		return stdmath_int3_bitwise_not(*self);
	}
	stdmath_int3 _logical_and(stdmath_int3 o) {
		return stdmath_int3_logical_and(*self, o);
	}
	stdmath_int3 _bitwise_and(stdmath_int3 o) {
		return stdmath_int3_bitwise_and(*self, o);
	}
	stdmath_int3 _logical_or(stdmath_int3 o) {
		return stdmath_int3_logical_or(*self, o);
	}
	stdmath_int3 _bitwise_or(stdmath_int3 o) {
		return stdmath_int3_bitwise_or(*self, o);
	}
	stdmath_int3 _bitwise_xor(stdmath_int3 o) {
		return stdmath_int3_bitwise_xor(*self, o);
	}
	stdmath_int3 _shift_left(stdmath_int3 o) {
		return stdmath_int3_shift_left(*self, o);
	}
	stdmath_int3 _shift_right(stdmath_int3 o) {
		return stdmath_int3_shift_right(*self, o);
	}
#endif

	bool3 _equal_to(stdmath_int3 o) {
		return stdmath_int3_equal_to(*self, o);
	}
	bool3 _not_equal_to(stdmath_int3 o) {
		return stdmath_int3_not_equal_to(*self, o);
	}
	bool3 _less_than(stdmath_int3 o) {
		return stdmath_int3_less_than(*self, o);
	}
	bool3 _less_than_or_equal_to(stdmath_int3 o) {
		return stdmath_int3_less_than_or_equal_to(*self, o);
	}
	bool3 _greater_than(stdmath_int3 o) {
		return stdmath_int3_greater_than(*self, o);
	}
	bool3 _greater_than_or_equal_to(stdmath_int3 o) {
		return stdmath_int3_greater_than_or_equal_to(*self, o);
	}
	
	int32_t _length_squared() {
		return stdmath_int3_length_squared(*self);
	}
	int32_t _length() {
		return stdmath_int3_length(*self);
	}
	int32_t _dot() {
		return stdmath_int3_dot(*self);
	}
	int32_t _min_element() {
		return stdmath_int3_min_element(*self);
	}
	int32_t _max_element() {
		return stdmath_int3_max_element(*self);
	}

	// int32_t elementwise_transform()
	// int32_t reduce_element
	
	stdmath_int3 _min(stdmath_int3 o) {
		return stdmath_int3_min(*self, o);
	}
	stdmath_int3 _max(stdmath_int3 o) {
		return stdmath_int3_max(*self, o);
	}
	stdmath_int3 _normalize() {
		return stdmath_int3_normalize(*self);
	}
	stdmath_int3 _lerp(stdmath_int3 o, int t) {
		return stdmath_int3_lerp(*self, o, t);
	}
	stdmath_int3 _clamp(stdmath_int3 min, stdmath_int3 max) {
		return stdmath_int3_clamp(*self, min, max);
	}
	stdmath_int3 _reflect(stdmath_int3 n) {
		return stdmath_int3_reflect(*self, n);
	}
	bool3 _approximately_equal(stdmath_int3 o) {
		return stdmath_int3_approximately_equal()
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

	int32_t _get_element(size_t i) {
		return self->data[i];
	}

	int32_t _set_element(size_t i, int32_t value) {
		return self->data[i] = value;
	}
}
