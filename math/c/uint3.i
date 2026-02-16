%rename(uint3) stdmath_uint3;
%include "uint3.h"

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

%extend stdmath_uint3 {
	stdmath_uint3(uint32_t broadcast) {
		stdmath_uint3 *v;
		v = (stdmath_uint3 *) malloc(sizeof(stdmath_uint3));
		*v = stdmath_uint3_broadcast(broadcast);
		return v;
	}

#if 3 == 4
	stdmath_uint3(uint32_t x = 0, uint32_t y = 0, uint32_t z = 0, uint32_t w = 0) {
		stdmath_uint3 *v;
		v = (stdmath_uint3 *) malloc(sizeof(stdmath_uint3));
		v->x = x;
		v->y = y;
		v->z = z;
		v->w = w;
		return v;
	}
#elif 3 == 3
	stdmath_uint3(uint32_t x = 0, uint32_t y = 0, uint32_t z = 0) {
		stdmath_uint3 *v;
		v = (stdmath_uint3 *) malloc(sizeof(stdmath_uint3));
		v->x = x;
		v->y = y;
		v->z = z;
		return v;
	}
#elif 3 == 2
	stdmath_uint3(uint32_t x = 0, uint32_t y = 0) {
		stdmath_uint3 *v;
		v = (stdmath_uint3 *) malloc(sizeof(stdmath_uint3));
		v->x = x;
		v->y = y;
		return v;
	}
#elif 3 == 1
	stdmath_uint3(uint32_t x = 0) {
		stdmath_uint3 *v;
		v = (stdmath_uint3 *) malloc(sizeof(stdmath_uint3));
		v->x = x;
		return v;
	}
#endif

	stdmath_uint2 xx;
	stdmath_uint2 get_xx() { return {self->x,self->x}; }
	stdmath_uint3 set_xx(stdmath_uint2 value) { self->x = value.x; self->x = value.y; return *self; }

	stdmath_uint2 xy;
	stdmath_uint2 get_xy() { return {self->x,self->y}; }
	stdmath_uint3 set_xy(stdmath_uint2 value) { self->x = value.x; self->y = value.y; return *self; }

	stdmath_uint2 xz;
	stdmath_uint2 get_xz() { return {self->x,self->z}; }
	stdmath_uint3 set_xz(stdmath_uint2 value) { self->x = value.x; self->z = value.y; return *self; }

	stdmath_uint2 yx;
	stdmath_uint2 get_yx() { return {self->y,self->x}; }
	stdmath_uint3 set_yx(stdmath_uint2 value) { self->y = value.x; self->x = value.y; return *self; }

	stdmath_uint2 yy;
	stdmath_uint2 get_yy() { return {self->y,self->y}; }
	stdmath_uint3 set_yy(stdmath_uint2 value) { self->y = value.x; self->y = value.y; return *self; }

	stdmath_uint2 yz;
	stdmath_uint2 get_yz() { return {self->y,self->z}; }
	stdmath_uint3 set_yz(stdmath_uint2 value) { self->y = value.x; self->z = value.y; return *self; }

	stdmath_uint2 zx;
	stdmath_uint2 get_zx() { return {self->z,self->x}; }
	stdmath_uint3 set_zx(stdmath_uint2 value) { self->z = value.x; self->x = value.y; return *self; }

	stdmath_uint2 zy;
	stdmath_uint2 get_zy() { return {self->z,self->y}; }
	stdmath_uint3 set_zy(stdmath_uint2 value) { self->z = value.x; self->y = value.y; return *self; }

	stdmath_uint2 zz;
	stdmath_uint2 get_zz() { return {self->z,self->z}; }
	stdmath_uint3 set_zz(stdmath_uint2 value) { self->z = value.x; self->z = value.y; return *self; }

	stdmath_uint3 xxx;
	stdmath_uint3 get_xxx() { return {self->x,self->x,self->x}; }
	stdmath_uint3 set_xxx(stdmath_uint3 value) { self->x = value.x; self->x = value.y; self->x = value.z; return *self; }

	stdmath_uint3 xxy;
	stdmath_uint3 get_xxy() { return {self->x,self->x,self->y}; }
	stdmath_uint3 set_xxy(stdmath_uint3 value) { self->x = value.x; self->x = value.y; self->y = value.z; return *self; }

	stdmath_uint3 xxz;
	stdmath_uint3 get_xxz() { return {self->x,self->x,self->z}; }
	stdmath_uint3 set_xxz(stdmath_uint3 value) { self->x = value.x; self->x = value.y; self->z = value.z; return *self; }

	stdmath_uint3 xyx;
	stdmath_uint3 get_xyx() { return {self->x,self->y,self->x}; }
	stdmath_uint3 set_xyx(stdmath_uint3 value) { self->x = value.x; self->y = value.y; self->x = value.z; return *self; }

	stdmath_uint3 xyy;
	stdmath_uint3 get_xyy() { return {self->x,self->y,self->y}; }
	stdmath_uint3 set_xyy(stdmath_uint3 value) { self->x = value.x; self->y = value.y; self->y = value.z; return *self; }

	stdmath_uint3 xyz;
	stdmath_uint3 get_xyz() { return {self->x,self->y,self->z}; }
	stdmath_uint3 set_xyz(stdmath_uint3 value) { self->x = value.x; self->y = value.y; self->z = value.z; return *self; }

	stdmath_uint3 xzx;
	stdmath_uint3 get_xzx() { return {self->x,self->z,self->x}; }
	stdmath_uint3 set_xzx(stdmath_uint3 value) { self->x = value.x; self->z = value.y; self->x = value.z; return *self; }

	stdmath_uint3 xzy;
	stdmath_uint3 get_xzy() { return {self->x,self->z,self->y}; }
	stdmath_uint3 set_xzy(stdmath_uint3 value) { self->x = value.x; self->z = value.y; self->y = value.z; return *self; }

	stdmath_uint3 xzz;
	stdmath_uint3 get_xzz() { return {self->x,self->z,self->z}; }
	stdmath_uint3 set_xzz(stdmath_uint3 value) { self->x = value.x; self->z = value.y; self->z = value.z; return *self; }

	stdmath_uint3 yxx;
	stdmath_uint3 get_yxx() { return {self->y,self->x,self->x}; }
	stdmath_uint3 set_yxx(stdmath_uint3 value) { self->y = value.x; self->x = value.y; self->x = value.z; return *self; }

	stdmath_uint3 yxy;
	stdmath_uint3 get_yxy() { return {self->y,self->x,self->y}; }
	stdmath_uint3 set_yxy(stdmath_uint3 value) { self->y = value.x; self->x = value.y; self->y = value.z; return *self; }

	stdmath_uint3 yxz;
	stdmath_uint3 get_yxz() { return {self->y,self->x,self->z}; }
	stdmath_uint3 set_yxz(stdmath_uint3 value) { self->y = value.x; self->x = value.y; self->z = value.z; return *self; }

	stdmath_uint3 yyx;
	stdmath_uint3 get_yyx() { return {self->y,self->y,self->x}; }
	stdmath_uint3 set_yyx(stdmath_uint3 value) { self->y = value.x; self->y = value.y; self->x = value.z; return *self; }

	stdmath_uint3 yyy;
	stdmath_uint3 get_yyy() { return {self->y,self->y,self->y}; }
	stdmath_uint3 set_yyy(stdmath_uint3 value) { self->y = value.x; self->y = value.y; self->y = value.z; return *self; }

	stdmath_uint3 yyz;
	stdmath_uint3 get_yyz() { return {self->y,self->y,self->z}; }
	stdmath_uint3 set_yyz(stdmath_uint3 value) { self->y = value.x; self->y = value.y; self->z = value.z; return *self; }

	stdmath_uint3 yzx;
	stdmath_uint3 get_yzx() { return {self->y,self->z,self->x}; }
	stdmath_uint3 set_yzx(stdmath_uint3 value) { self->y = value.x; self->z = value.y; self->x = value.z; return *self; }

	stdmath_uint3 yzy;
	stdmath_uint3 get_yzy() { return {self->y,self->z,self->y}; }
	stdmath_uint3 set_yzy(stdmath_uint3 value) { self->y = value.x; self->z = value.y; self->y = value.z; return *self; }

	stdmath_uint3 yzz;
	stdmath_uint3 get_yzz() { return {self->y,self->z,self->z}; }
	stdmath_uint3 set_yzz(stdmath_uint3 value) { self->y = value.x; self->z = value.y; self->z = value.z; return *self; }

	stdmath_uint3 zxx;
	stdmath_uint3 get_zxx() { return {self->z,self->x,self->x}; }
	stdmath_uint3 set_zxx(stdmath_uint3 value) { self->z = value.x; self->x = value.y; self->x = value.z; return *self; }

	stdmath_uint3 zxy;
	stdmath_uint3 get_zxy() { return {self->z,self->x,self->y}; }
	stdmath_uint3 set_zxy(stdmath_uint3 value) { self->z = value.x; self->x = value.y; self->y = value.z; return *self; }

	stdmath_uint3 zxz;
	stdmath_uint3 get_zxz() { return {self->z,self->x,self->z}; }
	stdmath_uint3 set_zxz(stdmath_uint3 value) { self->z = value.x; self->x = value.y; self->z = value.z; return *self; }

	stdmath_uint3 zyx;
	stdmath_uint3 get_zyx() { return {self->z,self->y,self->x}; }
	stdmath_uint3 set_zyx(stdmath_uint3 value) { self->z = value.x; self->y = value.y; self->x = value.z; return *self; }

	stdmath_uint3 zyy;
	stdmath_uint3 get_zyy() { return {self->z,self->y,self->y}; }
	stdmath_uint3 set_zyy(stdmath_uint3 value) { self->z = value.x; self->y = value.y; self->y = value.z; return *self; }

	stdmath_uint3 zyz;
	stdmath_uint3 get_zyz() { return {self->z,self->y,self->z}; }
	stdmath_uint3 set_zyz(stdmath_uint3 value) { self->z = value.x; self->y = value.y; self->z = value.z; return *self; }

	stdmath_uint3 zzx;
	stdmath_uint3 get_zzx() { return {self->z,self->z,self->x}; }
	stdmath_uint3 set_zzx(stdmath_uint3 value) { self->z = value.x; self->z = value.y; self->x = value.z; return *self; }

	stdmath_uint3 zzy;
	stdmath_uint3 get_zzy() { return {self->z,self->z,self->y}; }
	stdmath_uint3 set_zzy(stdmath_uint3 value) { self->z = value.x; self->z = value.y; self->y = value.z; return *self; }

	stdmath_uint3 zzz;
	stdmath_uint3 get_zzz() { return {self->z,self->z,self->z}; }
	stdmath_uint3 set_zzz(stdmath_uint3 value) { self->z = value.x; self->z = value.y; self->z = value.z; return *self; }



	stdmath_uint3 _add(stdmath_uint3 o) {
		return stdmath_uint3_add(*self, o);
	}
	stdmath_uint3 _subtract(stdmath_uint3 o) {
		return stdmath_uint3_subtract(*self, o);
	}
	stdmath_uint3 _negate() {
		return stdmath_uint3_negate(*self);
	}
	stdmath_uint3 _multiply(stdmath_uint3 o) {
		return stdmath_uint3_multiply(*self, o);
	}
	stdmath_uint3 _divide(stdmath_uint3 o) {
		return stdmath_uint3_divide(*self, o);
	}
	stdmath_uint3 _scale(uint32_t o) {
		return stdmath_uint3_scale(*self, o);
	}

#if false
	stdmath_uint3 _modulus(stdmath_uint3 o) {
		return stdmath_uint3_modulus(*self, o);
	}
	stdmath_uint3 _logical_not() {
		return stdmath_uint3_logical_not(*self);
	}
	stdmath_uint3 _bitwise_not() {
		return stdmath_uint3_bitwise_not(*self);
	}
	stdmath_uint3 _logical_and(stdmath_uint3 o) {
		return stdmath_uint3_logical_and(*self, o);
	}
	stdmath_uint3 _bitwise_and(stdmath_uint3 o) {
		return stdmath_uint3_bitwise_and(*self, o);
	}
	stdmath_uint3 _logical_or(stdmath_uint3 o) {
		return stdmath_uint3_logical_or(*self, o);
	}
	stdmath_uint3 _bitwise_or(stdmath_uint3 o) {
		return stdmath_uint3_bitwise_or(*self, o);
	}
	stdmath_uint3 _bitwise_xor(stdmath_uint3 o) {
		return stdmath_uint3_bitwise_xor(*self, o);
	}
	stdmath_uint3 _shift_left(stdmath_uint3 o) {
		return stdmath_uint3_shift_left(*self, o);
	}
	stdmath_uint3 _shift_right(stdmath_uint3 o) {
		return stdmath_uint3_shift_right(*self, o);
	}
#endif

	bool3 _equal_to(stdmath_uint3 o) {
		return stdmath_uint3_equal_to(*self, o);
	}
	bool3 _not_equal_to(stdmath_uint3 o) {
		return stdmath_uint3_not_equal_to(*self, o);
	}
	bool3 _less_than(stdmath_uint3 o) {
		return stdmath_uint3_less_than(*self, o);
	}
	bool3 _less_than_or_equal_to(stdmath_uint3 o) {
		return stdmath_uint3_less_than_or_equal_to(*self, o);
	}
	bool3 _greater_than(stdmath_uint3 o) {
		return stdmath_uint3_greater_than(*self, o);
	}
	bool3 _greater_than_or_equal_to(stdmath_uint3 o) {
		return stdmath_uint3_greater_than_or_equal_to(*self, o);
	}

	uint32_t _length_squared() {
		return stdmath_uint3_length_squared(*self);
	}
	uint32_t _length() {
		return stdmath_uint3_length(*self);
	}
	uint32_t _dot() {
		return stdmath_uint3_dot(*self);
	}
	uint32_t _min_element() {
		return stdmath_uint3_min_element(*self);
	}
	uint32_t _max_element() {
		return stdmath_uint3_max_element(*self);
	}

	// uint32_t elementwise_transform()
	// uint32_t reduce_element

	stdmath_uint3 _min(stdmath_uint3 o) {
		return stdmath_uint3_min(*self, o);
	}
	stdmath_uint3 _max(stdmath_uint3 o) {
		return stdmath_uint3_max(*self, o);
	}
	stdmath_uint3 _normalize() {
		return stdmath_uint3_normalize(*self);
	}
	stdmath_uint3 _lerp(stdmath_uint3 o, uint t) {
		return stdmath_uint3_lerp(*self, o, t);
	}
	stdmath_uint3 _clamp(stdmath_uint3 min, stdmath_uint3 max) {
		return stdmath_uint3_clamp(*self, min, max);
	}
	stdmath_uint3 _reflect(stdmath_uint3 n) {
		return stdmath_uint3_reflect(*self, n);
	}
	bool3 _approximately_equal(stdmath_uint3 o) {
		return stdmath_uint3_approximately_equal()
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

	uint32_t _get_element(size_t i) {
		return self->data[i];
	}

	uint32_t _set_element(size_t i, uint32_t value) {
		return self->data[i] = value;
	}
}
