%rename(byte3) stdmath_byte3;
%include "byte3.h"

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

%extend stdmath_byte3 {
	stdmath_byte3(uint8_t broadcast) {
		stdmath_byte3 *v;
		v = (stdmath_byte3 *) malloc(sizeof(stdmath_byte3));
		*v = stdmath_byte3_broadcast(broadcast);
		return v;
	}

#if 3 == 4
	stdmath_byte3(uint8_t x = 0, uint8_t y = 0, uint8_t z = 0, uint8_t w = 0) {
		stdmath_byte3 *v;
		v = (stdmath_byte3 *) malloc(sizeof(stdmath_byte3));
		v->x = x;
		v->y = y;
		v->z = z;
		v->w = w;
		return v;
	}
#elif 3 == 3
	stdmath_byte3(uint8_t x = 0, uint8_t y = 0, uint8_t z = 0) {
		stdmath_byte3 *v;
		v = (stdmath_byte3 *) malloc(sizeof(stdmath_byte3));
		v->x = x;
		v->y = y;
		v->z = z;
		return v;
	}
#elif 3 == 2
	stdmath_byte3(uint8_t x = 0, uint8_t y = 0) {
		stdmath_byte3 *v;
		v = (stdmath_byte3 *) malloc(sizeof(stdmath_byte3));
		v->x = x;
		v->y = y;
		return v;
	}
#elif 3 == 1
	stdmath_byte3(uint8_t x = 0) {
		stdmath_byte3 *v;
		v = (stdmath_byte3 *) malloc(sizeof(stdmath_byte3));
		v->x = x;
		return v;
	}
#endif

	stdmath_byte2 xx;
	stdmath_byte2 get_xx() { return {self->x,self->x}; }
	stdmath_byte3 set_xx(stdmath_byte2 value) { self->x = value.x; self->x = value.y; return *self; }

	stdmath_byte2 xy;
	stdmath_byte2 get_xy() { return {self->x,self->y}; }
	stdmath_byte3 set_xy(stdmath_byte2 value) { self->x = value.x; self->y = value.y; return *self; }

	stdmath_byte2 xz;
	stdmath_byte2 get_xz() { return {self->x,self->z}; }
	stdmath_byte3 set_xz(stdmath_byte2 value) { self->x = value.x; self->z = value.y; return *self; }

	stdmath_byte2 yx;
	stdmath_byte2 get_yx() { return {self->y,self->x}; }
	stdmath_byte3 set_yx(stdmath_byte2 value) { self->y = value.x; self->x = value.y; return *self; }

	stdmath_byte2 yy;
	stdmath_byte2 get_yy() { return {self->y,self->y}; }
	stdmath_byte3 set_yy(stdmath_byte2 value) { self->y = value.x; self->y = value.y; return *self; }

	stdmath_byte2 yz;
	stdmath_byte2 get_yz() { return {self->y,self->z}; }
	stdmath_byte3 set_yz(stdmath_byte2 value) { self->y = value.x; self->z = value.y; return *self; }

	stdmath_byte2 zx;
	stdmath_byte2 get_zx() { return {self->z,self->x}; }
	stdmath_byte3 set_zx(stdmath_byte2 value) { self->z = value.x; self->x = value.y; return *self; }

	stdmath_byte2 zy;
	stdmath_byte2 get_zy() { return {self->z,self->y}; }
	stdmath_byte3 set_zy(stdmath_byte2 value) { self->z = value.x; self->y = value.y; return *self; }

	stdmath_byte2 zz;
	stdmath_byte2 get_zz() { return {self->z,self->z}; }
	stdmath_byte3 set_zz(stdmath_byte2 value) { self->z = value.x; self->z = value.y; return *self; }

	stdmath_byte3 xxx;
	stdmath_byte3 get_xxx() { return {self->x,self->x,self->x}; }
	stdmath_byte3 set_xxx(stdmath_byte3 value) { self->x = value.x; self->x = value.y; self->x = value.z; return *self; }

	stdmath_byte3 xxy;
	stdmath_byte3 get_xxy() { return {self->x,self->x,self->y}; }
	stdmath_byte3 set_xxy(stdmath_byte3 value) { self->x = value.x; self->x = value.y; self->y = value.z; return *self; }

	stdmath_byte3 xxz;
	stdmath_byte3 get_xxz() { return {self->x,self->x,self->z}; }
	stdmath_byte3 set_xxz(stdmath_byte3 value) { self->x = value.x; self->x = value.y; self->z = value.z; return *self; }

	stdmath_byte3 xyx;
	stdmath_byte3 get_xyx() { return {self->x,self->y,self->x}; }
	stdmath_byte3 set_xyx(stdmath_byte3 value) { self->x = value.x; self->y = value.y; self->x = value.z; return *self; }

	stdmath_byte3 xyy;
	stdmath_byte3 get_xyy() { return {self->x,self->y,self->y}; }
	stdmath_byte3 set_xyy(stdmath_byte3 value) { self->x = value.x; self->y = value.y; self->y = value.z; return *self; }

	stdmath_byte3 xyz;
	stdmath_byte3 get_xyz() { return {self->x,self->y,self->z}; }
	stdmath_byte3 set_xyz(stdmath_byte3 value) { self->x = value.x; self->y = value.y; self->z = value.z; return *self; }

	stdmath_byte3 xzx;
	stdmath_byte3 get_xzx() { return {self->x,self->z,self->x}; }
	stdmath_byte3 set_xzx(stdmath_byte3 value) { self->x = value.x; self->z = value.y; self->x = value.z; return *self; }

	stdmath_byte3 xzy;
	stdmath_byte3 get_xzy() { return {self->x,self->z,self->y}; }
	stdmath_byte3 set_xzy(stdmath_byte3 value) { self->x = value.x; self->z = value.y; self->y = value.z; return *self; }

	stdmath_byte3 xzz;
	stdmath_byte3 get_xzz() { return {self->x,self->z,self->z}; }
	stdmath_byte3 set_xzz(stdmath_byte3 value) { self->x = value.x; self->z = value.y; self->z = value.z; return *self; }

	stdmath_byte3 yxx;
	stdmath_byte3 get_yxx() { return {self->y,self->x,self->x}; }
	stdmath_byte3 set_yxx(stdmath_byte3 value) { self->y = value.x; self->x = value.y; self->x = value.z; return *self; }

	stdmath_byte3 yxy;
	stdmath_byte3 get_yxy() { return {self->y,self->x,self->y}; }
	stdmath_byte3 set_yxy(stdmath_byte3 value) { self->y = value.x; self->x = value.y; self->y = value.z; return *self; }

	stdmath_byte3 yxz;
	stdmath_byte3 get_yxz() { return {self->y,self->x,self->z}; }
	stdmath_byte3 set_yxz(stdmath_byte3 value) { self->y = value.x; self->x = value.y; self->z = value.z; return *self; }

	stdmath_byte3 yyx;
	stdmath_byte3 get_yyx() { return {self->y,self->y,self->x}; }
	stdmath_byte3 set_yyx(stdmath_byte3 value) { self->y = value.x; self->y = value.y; self->x = value.z; return *self; }

	stdmath_byte3 yyy;
	stdmath_byte3 get_yyy() { return {self->y,self->y,self->y}; }
	stdmath_byte3 set_yyy(stdmath_byte3 value) { self->y = value.x; self->y = value.y; self->y = value.z; return *self; }

	stdmath_byte3 yyz;
	stdmath_byte3 get_yyz() { return {self->y,self->y,self->z}; }
	stdmath_byte3 set_yyz(stdmath_byte3 value) { self->y = value.x; self->y = value.y; self->z = value.z; return *self; }

	stdmath_byte3 yzx;
	stdmath_byte3 get_yzx() { return {self->y,self->z,self->x}; }
	stdmath_byte3 set_yzx(stdmath_byte3 value) { self->y = value.x; self->z = value.y; self->x = value.z; return *self; }

	stdmath_byte3 yzy;
	stdmath_byte3 get_yzy() { return {self->y,self->z,self->y}; }
	stdmath_byte3 set_yzy(stdmath_byte3 value) { self->y = value.x; self->z = value.y; self->y = value.z; return *self; }

	stdmath_byte3 yzz;
	stdmath_byte3 get_yzz() { return {self->y,self->z,self->z}; }
	stdmath_byte3 set_yzz(stdmath_byte3 value) { self->y = value.x; self->z = value.y; self->z = value.z; return *self; }

	stdmath_byte3 zxx;
	stdmath_byte3 get_zxx() { return {self->z,self->x,self->x}; }
	stdmath_byte3 set_zxx(stdmath_byte3 value) { self->z = value.x; self->x = value.y; self->x = value.z; return *self; }

	stdmath_byte3 zxy;
	stdmath_byte3 get_zxy() { return {self->z,self->x,self->y}; }
	stdmath_byte3 set_zxy(stdmath_byte3 value) { self->z = value.x; self->x = value.y; self->y = value.z; return *self; }

	stdmath_byte3 zxz;
	stdmath_byte3 get_zxz() { return {self->z,self->x,self->z}; }
	stdmath_byte3 set_zxz(stdmath_byte3 value) { self->z = value.x; self->x = value.y; self->z = value.z; return *self; }

	stdmath_byte3 zyx;
	stdmath_byte3 get_zyx() { return {self->z,self->y,self->x}; }
	stdmath_byte3 set_zyx(stdmath_byte3 value) { self->z = value.x; self->y = value.y; self->x = value.z; return *self; }

	stdmath_byte3 zyy;
	stdmath_byte3 get_zyy() { return {self->z,self->y,self->y}; }
	stdmath_byte3 set_zyy(stdmath_byte3 value) { self->z = value.x; self->y = value.y; self->y = value.z; return *self; }

	stdmath_byte3 zyz;
	stdmath_byte3 get_zyz() { return {self->z,self->y,self->z}; }
	stdmath_byte3 set_zyz(stdmath_byte3 value) { self->z = value.x; self->y = value.y; self->z = value.z; return *self; }

	stdmath_byte3 zzx;
	stdmath_byte3 get_zzx() { return {self->z,self->z,self->x}; }
	stdmath_byte3 set_zzx(stdmath_byte3 value) { self->z = value.x; self->z = value.y; self->x = value.z; return *self; }

	stdmath_byte3 zzy;
	stdmath_byte3 get_zzy() { return {self->z,self->z,self->y}; }
	stdmath_byte3 set_zzy(stdmath_byte3 value) { self->z = value.x; self->z = value.y; self->y = value.z; return *self; }

	stdmath_byte3 zzz;
	stdmath_byte3 get_zzz() { return {self->z,self->z,self->z}; }
	stdmath_byte3 set_zzz(stdmath_byte3 value) { self->z = value.x; self->z = value.y; self->z = value.z; return *self; }



	stdmath_byte3 _add(stdmath_byte3 o) {
		return stdmath_byte3_add(*self, o);
	}
	stdmath_byte3 _subtract(stdmath_byte3 o) {
		return stdmath_byte3_subtract(*self, o);
	}
	stdmath_byte3 _negate() {
		return stdmath_byte3_negate(*self);
	}
	stdmath_byte3 _multiply(stdmath_byte3 o) {
		return stdmath_byte3_multiply(*self, o);
	}
	stdmath_byte3 _divide(stdmath_byte3 o) {
		return stdmath_byte3_divide(*self, o);
	}
	stdmath_byte3 _scale(uint8_t o) {
		return stdmath_byte3_scale(*self, o);
	}

#if false
	stdmath_byte3 _modulus(stdmath_byte3 o) {
		return stdmath_byte3_modulus(*self, o);
	}
	stdmath_byte3 _logical_not() {
		return stdmath_byte3_logical_not(*self);
	}
	stdmath_byte3 _bitwise_not() {
		return stdmath_byte3_bitwise_not(*self);
	}
	stdmath_byte3 _logical_and(stdmath_byte3 o) {
		return stdmath_byte3_logical_and(*self, o);
	}
	stdmath_byte3 _bitwise_and(stdmath_byte3 o) {
		return stdmath_byte3_bitwise_and(*self, o);
	}
	stdmath_byte3 _logical_or(stdmath_byte3 o) {
		return stdmath_byte3_logical_or(*self, o);
	}
	stdmath_byte3 _bitwise_or(stdmath_byte3 o) {
		return stdmath_byte3_bitwise_or(*self, o);
	}
	stdmath_byte3 _bitwise_xor(stdmath_byte3 o) {
		return stdmath_byte3_bitwise_xor(*self, o);
	}
	stdmath_byte3 _shift_left(stdmath_byte3 o) {
		return stdmath_byte3_shift_left(*self, o);
	}
	stdmath_byte3 _shift_right(stdmath_byte3 o) {
		return stdmath_byte3_shift_right(*self, o);
	}
#endif

	bool3 _equal_to(stdmath_byte3 o) {
		return stdmath_byte3_equal_to(*self, o);
	}
	bool3 _not_equal_to(stdmath_byte3 o) {
		return stdmath_byte3_not_equal_to(*self, o);
	}
	bool3 _less_than(stdmath_byte3 o) {
		return stdmath_byte3_less_than(*self, o);
	}
	bool3 _less_than_or_equal_to(stdmath_byte3 o) {
		return stdmath_byte3_less_than_or_equal_to(*self, o);
	}
	bool3 _greater_than(stdmath_byte3 o) {
		return stdmath_byte3_greater_than(*self, o);
	}
	bool3 _greater_than_or_equal_to(stdmath_byte3 o) {
		return stdmath_byte3_greater_than_or_equal_to(*self, o);
	}

	uint8_t _length_squared() {
		return stdmath_byte3_length_squared(*self);
	}
	uint8_t _length() {
		return stdmath_byte3_length(*self);
	}
	uint8_t _dot() {
		return stdmath_byte3_dot(*self);
	}
	uint8_t _min_element() {
		return stdmath_byte3_min_element(*self);
	}
	uint8_t _max_element() {
		return stdmath_byte3_max_element(*self);
	}

	// uint8_t elementwise_transform()
	// uint8_t reduce_element

	stdmath_byte3 _min(stdmath_byte3 o) {
		return stdmath_byte3_min(*self, o);
	}
	stdmath_byte3 _max(stdmath_byte3 o) {
		return stdmath_byte3_max(*self, o);
	}
	stdmath_byte3 _normalize() {
		return stdmath_byte3_normalize(*self);
	}
	stdmath_byte3 _lerp(stdmath_byte3 o, byte t) {
		return stdmath_byte3_lerp(*self, o, t);
	}
	stdmath_byte3 _clamp(stdmath_byte3 min, stdmath_byte3 max) {
		return stdmath_byte3_clamp(*self, min, max);
	}
	stdmath_byte3 _reflect(stdmath_byte3 n) {
		return stdmath_byte3_reflect(*self, n);
	}
	bool3 _approximately_equal(stdmath_byte3 o) {
		return stdmath_byte3_approximately_equal()
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

	uint8_t _get_element(size_t i) {
		return self->data[i];
	}

	uint8_t _set_element(size_t i, uint8_t value) {
		return self->data[i] = value;
	}
}
