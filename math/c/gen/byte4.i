#define STDMATH_EXPORT
#define STDMATH_INLINE
%rename(byte4) stdmath_byte4;
%include "byte4.h"

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

%extend stdmath_byte4 {
	stdmath_byte4(uint8_t broadcast) {
		stdmath_byte4 *v;
		v = (stdmath_byte4 *) malloc(sizeof(stdmath_byte4));
		*v = stdmath_byte4_broadcast(broadcast);
		return v;
	}

#if 4 == 4
	stdmath_byte4(uint8_t x = 0, uint8_t y = 0, uint8_t z = 0, uint8_t w = 0) {
		stdmath_byte4 *v;
		v = (stdmath_byte4 *) malloc(sizeof(stdmath_byte4));
		v->x = x;
		v->y = y;
		v->z = z;
		v->w = w;
		return v;
	}
#elif 4 == 3
	stdmath_byte4(uint8_t x = 0, uint8_t y = 0, uint8_t z = 0) {
		stdmath_byte4 *v;
		v = (stdmath_byte4 *) malloc(sizeof(stdmath_byte4));
		v->x = x;
		v->y = y;
		v->z = z;
		return v;
	}
#elif 4 == 2
	stdmath_byte4(uint8_t x = 0, uint8_t y = 0) {
		stdmath_byte4 *v;
		v = (stdmath_byte4 *) malloc(sizeof(stdmath_byte4));
		v->x = x;
		v->y = y;
		return v;
	}
#elif 4 == 1
	stdmath_byte4(uint8_t x = 0) {
		stdmath_byte4 *v;
		v = (stdmath_byte4 *) malloc(sizeof(stdmath_byte4));
		v->x = x;
		return v;
	}
#endif

#ifndef STDMATH_NO_SWIZZLES
	stdmath_byte2 xx;
	stdmath_byte2 xy;
	stdmath_byte2 xz;
	stdmath_byte2 xw;
	stdmath_byte2 yx;
	stdmath_byte2 yy;
	stdmath_byte2 yz;
	stdmath_byte2 yw;
	stdmath_byte2 zx;
	stdmath_byte2 zy;
	stdmath_byte2 zz;
	stdmath_byte2 zw;
	stdmath_byte2 wx;
	stdmath_byte2 wy;
	stdmath_byte2 wz;
	stdmath_byte2 ww;
	stdmath_byte3 xxx;
	stdmath_byte3 xxy;
	stdmath_byte3 xxz;
	stdmath_byte3 xxw;
	stdmath_byte3 xyx;
	stdmath_byte3 xyy;
	stdmath_byte3 xyz;
	stdmath_byte3 xyw;
	stdmath_byte3 xzx;
	stdmath_byte3 xzy;
	stdmath_byte3 xzz;
	stdmath_byte3 xzw;
	stdmath_byte3 xwx;
	stdmath_byte3 xwy;
	stdmath_byte3 xwz;
	stdmath_byte3 xww;
	stdmath_byte3 yxx;
	stdmath_byte3 yxy;
	stdmath_byte3 yxz;
	stdmath_byte3 yxw;
	stdmath_byte3 yyx;
	stdmath_byte3 yyy;
	stdmath_byte3 yyz;
	stdmath_byte3 yyw;
	stdmath_byte3 yzx;
	stdmath_byte3 yzy;
	stdmath_byte3 yzz;
	stdmath_byte3 yzw;
	stdmath_byte3 ywx;
	stdmath_byte3 ywy;
	stdmath_byte3 ywz;
	stdmath_byte3 yww;
	stdmath_byte3 zxx;
	stdmath_byte3 zxy;
	stdmath_byte3 zxz;
	stdmath_byte3 zxw;
	stdmath_byte3 zyx;
	stdmath_byte3 zyy;
	stdmath_byte3 zyz;
	stdmath_byte3 zyw;
	stdmath_byte3 zzx;
	stdmath_byte3 zzy;
	stdmath_byte3 zzz;
	stdmath_byte3 zzw;
	stdmath_byte3 zwx;
	stdmath_byte3 zwy;
	stdmath_byte3 zwz;
	stdmath_byte3 zww;
	stdmath_byte3 wxx;
	stdmath_byte3 wxy;
	stdmath_byte3 wxz;
	stdmath_byte3 wxw;
	stdmath_byte3 wyx;
	stdmath_byte3 wyy;
	stdmath_byte3 wyz;
	stdmath_byte3 wyw;
	stdmath_byte3 wzx;
	stdmath_byte3 wzy;
	stdmath_byte3 wzz;
	stdmath_byte3 wzw;
	stdmath_byte3 wwx;
	stdmath_byte3 wwy;
	stdmath_byte3 wwz;
	stdmath_byte3 www;
	stdmath_byte4 xxxx;
	stdmath_byte4 xxxy;
	stdmath_byte4 xxxz;
	stdmath_byte4 xxxw;
	stdmath_byte4 xxyx;
	stdmath_byte4 xxyy;
	stdmath_byte4 xxyz;
	stdmath_byte4 xxyw;
	stdmath_byte4 xxzx;
	stdmath_byte4 xxzy;
	stdmath_byte4 xxzz;
	stdmath_byte4 xxzw;
	stdmath_byte4 xxwx;
	stdmath_byte4 xxwy;
	stdmath_byte4 xxwz;
	stdmath_byte4 xxww;
	stdmath_byte4 xyxx;
	stdmath_byte4 xyxy;
	stdmath_byte4 xyxz;
	stdmath_byte4 xyxw;
	stdmath_byte4 xyyx;
	stdmath_byte4 xyyy;
	stdmath_byte4 xyyz;
	stdmath_byte4 xyyw;
	stdmath_byte4 xyzx;
	stdmath_byte4 xyzy;
	stdmath_byte4 xyzz;
	stdmath_byte4 xyzw;
	stdmath_byte4 xywx;
	stdmath_byte4 xywy;
	stdmath_byte4 xywz;
	stdmath_byte4 xyww;
	stdmath_byte4 xzxx;
	stdmath_byte4 xzxy;
	stdmath_byte4 xzxz;
	stdmath_byte4 xzxw;
	stdmath_byte4 xzyx;
	stdmath_byte4 xzyy;
	stdmath_byte4 xzyz;
	stdmath_byte4 xzyw;
	stdmath_byte4 xzzx;
	stdmath_byte4 xzzy;
	stdmath_byte4 xzzz;
	stdmath_byte4 xzzw;
	stdmath_byte4 xzwx;
	stdmath_byte4 xzwy;
	stdmath_byte4 xzwz;
	stdmath_byte4 xzww;
	stdmath_byte4 xwxx;
	stdmath_byte4 xwxy;
	stdmath_byte4 xwxz;
	stdmath_byte4 xwxw;
	stdmath_byte4 xwyx;
	stdmath_byte4 xwyy;
	stdmath_byte4 xwyz;
	stdmath_byte4 xwyw;
	stdmath_byte4 xwzx;
	stdmath_byte4 xwzy;
	stdmath_byte4 xwzz;
	stdmath_byte4 xwzw;
	stdmath_byte4 xwwx;
	stdmath_byte4 xwwy;
	stdmath_byte4 xwwz;
	stdmath_byte4 xwww;
	stdmath_byte4 yxxx;
	stdmath_byte4 yxxy;
	stdmath_byte4 yxxz;
	stdmath_byte4 yxxw;
	stdmath_byte4 yxyx;
	stdmath_byte4 yxyy;
	stdmath_byte4 yxyz;
	stdmath_byte4 yxyw;
	stdmath_byte4 yxzx;
	stdmath_byte4 yxzy;
	stdmath_byte4 yxzz;
	stdmath_byte4 yxzw;
	stdmath_byte4 yxwx;
	stdmath_byte4 yxwy;
	stdmath_byte4 yxwz;
	stdmath_byte4 yxww;
	stdmath_byte4 yyxx;
	stdmath_byte4 yyxy;
	stdmath_byte4 yyxz;
	stdmath_byte4 yyxw;
	stdmath_byte4 yyyx;
	stdmath_byte4 yyyy;
	stdmath_byte4 yyyz;
	stdmath_byte4 yyyw;
	stdmath_byte4 yyzx;
	stdmath_byte4 yyzy;
	stdmath_byte4 yyzz;
	stdmath_byte4 yyzw;
	stdmath_byte4 yywx;
	stdmath_byte4 yywy;
	stdmath_byte4 yywz;
	stdmath_byte4 yyww;
	stdmath_byte4 yzxx;
	stdmath_byte4 yzxy;
	stdmath_byte4 yzxz;
	stdmath_byte4 yzxw;
	stdmath_byte4 yzyx;
	stdmath_byte4 yzyy;
	stdmath_byte4 yzyz;
	stdmath_byte4 yzyw;
	stdmath_byte4 yzzx;
	stdmath_byte4 yzzy;
	stdmath_byte4 yzzz;
	stdmath_byte4 yzzw;
	stdmath_byte4 yzwx;
	stdmath_byte4 yzwy;
	stdmath_byte4 yzwz;
	stdmath_byte4 yzww;
	stdmath_byte4 ywxx;
	stdmath_byte4 ywxy;
	stdmath_byte4 ywxz;
	stdmath_byte4 ywxw;
	stdmath_byte4 ywyx;
	stdmath_byte4 ywyy;
	stdmath_byte4 ywyz;
	stdmath_byte4 ywyw;
	stdmath_byte4 ywzx;
	stdmath_byte4 ywzy;
	stdmath_byte4 ywzz;
	stdmath_byte4 ywzw;
	stdmath_byte4 ywwx;
	stdmath_byte4 ywwy;
	stdmath_byte4 ywwz;
	stdmath_byte4 ywww;
	stdmath_byte4 zxxx;
	stdmath_byte4 zxxy;
	stdmath_byte4 zxxz;
	stdmath_byte4 zxxw;
	stdmath_byte4 zxyx;
	stdmath_byte4 zxyy;
	stdmath_byte4 zxyz;
	stdmath_byte4 zxyw;
	stdmath_byte4 zxzx;
	stdmath_byte4 zxzy;
	stdmath_byte4 zxzz;
	stdmath_byte4 zxzw;
	stdmath_byte4 zxwx;
	stdmath_byte4 zxwy;
	stdmath_byte4 zxwz;
	stdmath_byte4 zxww;
	stdmath_byte4 zyxx;
	stdmath_byte4 zyxy;
	stdmath_byte4 zyxz;
	stdmath_byte4 zyxw;
	stdmath_byte4 zyyx;
	stdmath_byte4 zyyy;
	stdmath_byte4 zyyz;
	stdmath_byte4 zyyw;
	stdmath_byte4 zyzx;
	stdmath_byte4 zyzy;
	stdmath_byte4 zyzz;
	stdmath_byte4 zyzw;
	stdmath_byte4 zywx;
	stdmath_byte4 zywy;
	stdmath_byte4 zywz;
	stdmath_byte4 zyww;
	stdmath_byte4 zzxx;
	stdmath_byte4 zzxy;
	stdmath_byte4 zzxz;
	stdmath_byte4 zzxw;
	stdmath_byte4 zzyx;
	stdmath_byte4 zzyy;
	stdmath_byte4 zzyz;
	stdmath_byte4 zzyw;
	stdmath_byte4 zzzx;
	stdmath_byte4 zzzy;
	stdmath_byte4 zzzz;
	stdmath_byte4 zzzw;
	stdmath_byte4 zzwx;
	stdmath_byte4 zzwy;
	stdmath_byte4 zzwz;
	stdmath_byte4 zzww;
	stdmath_byte4 zwxx;
	stdmath_byte4 zwxy;
	stdmath_byte4 zwxz;
	stdmath_byte4 zwxw;
	stdmath_byte4 zwyx;
	stdmath_byte4 zwyy;
	stdmath_byte4 zwyz;
	stdmath_byte4 zwyw;
	stdmath_byte4 zwzx;
	stdmath_byte4 zwzy;
	stdmath_byte4 zwzz;
	stdmath_byte4 zwzw;
	stdmath_byte4 zwwx;
	stdmath_byte4 zwwy;
	stdmath_byte4 zwwz;
	stdmath_byte4 zwww;
	stdmath_byte4 wxxx;
	stdmath_byte4 wxxy;
	stdmath_byte4 wxxz;
	stdmath_byte4 wxxw;
	stdmath_byte4 wxyx;
	stdmath_byte4 wxyy;
	stdmath_byte4 wxyz;
	stdmath_byte4 wxyw;
	stdmath_byte4 wxzx;
	stdmath_byte4 wxzy;
	stdmath_byte4 wxzz;
	stdmath_byte4 wxzw;
	stdmath_byte4 wxwx;
	stdmath_byte4 wxwy;
	stdmath_byte4 wxwz;
	stdmath_byte4 wxww;
	stdmath_byte4 wyxx;
	stdmath_byte4 wyxy;
	stdmath_byte4 wyxz;
	stdmath_byte4 wyxw;
	stdmath_byte4 wyyx;
	stdmath_byte4 wyyy;
	stdmath_byte4 wyyz;
	stdmath_byte4 wyyw;
	stdmath_byte4 wyzx;
	stdmath_byte4 wyzy;
	stdmath_byte4 wyzz;
	stdmath_byte4 wyzw;
	stdmath_byte4 wywx;
	stdmath_byte4 wywy;
	stdmath_byte4 wywz;
	stdmath_byte4 wyww;
	stdmath_byte4 wzxx;
	stdmath_byte4 wzxy;
	stdmath_byte4 wzxz;
	stdmath_byte4 wzxw;
	stdmath_byte4 wzyx;
	stdmath_byte4 wzyy;
	stdmath_byte4 wzyz;
	stdmath_byte4 wzyw;
	stdmath_byte4 wzzx;
	stdmath_byte4 wzzy;
	stdmath_byte4 wzzz;
	stdmath_byte4 wzzw;
	stdmath_byte4 wzwx;
	stdmath_byte4 wzwy;
	stdmath_byte4 wzwz;
	stdmath_byte4 wzww;
	stdmath_byte4 wwxx;
	stdmath_byte4 wwxy;
	stdmath_byte4 wwxz;
	stdmath_byte4 wwxw;
	stdmath_byte4 wwyx;
	stdmath_byte4 wwyy;
	stdmath_byte4 wwyz;
	stdmath_byte4 wwyw;
	stdmath_byte4 wwzx;
	stdmath_byte4 wwzy;
	stdmath_byte4 wwzz;
	stdmath_byte4 wwzw;
	stdmath_byte4 wwwx;
	stdmath_byte4 wwwy;
	stdmath_byte4 wwwz;
	stdmath_byte4 wwww;

#endif

	stdmath_byte4 _add(stdmath_byte4 o) {
		return stdmath_byte4_add(*self, o);
	}
	stdmath_byte4 _subtract(stdmath_byte4 o) {
		return stdmath_byte4_subtract(*self, o);
	}
	stdmath_byte4 _negate() {
		return stdmath_byte4_negate(*self);
	}
	stdmath_byte4 _multiply(stdmath_byte4 o) {
		return stdmath_byte4_multiply(*self, o);
	}
	stdmath_byte4 _divide(stdmath_byte4 o) {
		return stdmath_byte4_divide(*self, o);
	}
	stdmath_byte4 _scale(uint8_t o) {
		return stdmath_byte4_scale(*self, o);
	}

#if false
	stdmath_byte4 _modulus(stdmath_byte4 o) {
		return stdmath_byte4_modulus(*self, o);
	}
	stdmath_byte4 _logical_not() {
		return stdmath_byte4_logical_not(*self);
	}
	stdmath_byte4 _bitwise_not() {
		return stdmath_byte4_bitwise_not(*self);
	}
	stdmath_byte4 _logical_and(stdmath_byte4 o) {
		return stdmath_byte4_logical_and(*self, o);
	}
	stdmath_byte4 _bitwise_and(stdmath_byte4 o) {
		return stdmath_byte4_bitwise_and(*self, o);
	}
	stdmath_byte4 _logical_or(stdmath_byte4 o) {
		return stdmath_byte4_logical_or(*self, o);
	}
	stdmath_byte4 _bitwise_or(stdmath_byte4 o) {
		return stdmath_byte4_bitwise_or(*self, o);
	}
	stdmath_byte4 _bitwise_xor(stdmath_byte4 o) {
		return stdmath_byte4_bitwise_xor(*self, o);
	}
	stdmath_byte4 _shift_left(stdmath_byte4 o) {
		return stdmath_byte4_shift_left(*self, o);
	}
	stdmath_byte4 _shift_right(stdmath_byte4 o) {
		return stdmath_byte4_shift_right(*self, o);
	}
#endif

	stdmath_bool4 _equal_to(stdmath_byte4 o) {
		return stdmath_byte4_equal_to(*self, o);
	}
	stdmath_bool4 _not_equal_to(stdmath_byte4 o) {
		return stdmath_byte4_not_equal_to(*self, o);
	}
	stdmath_bool4 _less_than(stdmath_byte4 o) {
		return stdmath_byte4_less_than(*self, o);
	}
	stdmath_bool4 _less_than_or_equal_to(stdmath_byte4 o) {
		return stdmath_byte4_less_than_or_equal_to(*self, o);
	}
	stdmath_bool4 _greater_than(stdmath_byte4 o) {
		return stdmath_byte4_greater_than(*self, o);
	}
	stdmath_bool4 _greater_than_or_equal_to(stdmath_byte4 o) {
		return stdmath_byte4_greater_than_or_equal_to(*self, o);
	}

	uint8_t _length_squared() {
		return stdmath_byte4_length_squared(*self);
	}
	uint8_t _length() {
		return stdmath_byte4_length(*self);
	}
	uint8_t _dot(stdmath_byte4 o) {
		return stdmath_byte4_dot(*self, o);
	}
	uint8_t _min_element() {
		return stdmath_byte4_min_element(*self);
	}
	uint8_t _max_element() {
		return stdmath_byte4_max_element(*self);
	}

	// uint8_t elementwise_transform()
	// uint8_t reduce_element

	stdmath_byte4 _min(stdmath_byte4 o) {
		return stdmath_byte4_min(*self, o);
	}
	stdmath_byte4 _max(stdmath_byte4 o) {
		return stdmath_byte4_max(*self, o);
	}
	stdmath_byte4 _normalize() {
		return stdmath_byte4_normalize(*self);
	}
	stdmath_byte4 _lerp(stdmath_byte4 o, float t) {
		return stdmath_byte4_lerp(*self, o, t);
	}
	stdmath_byte4 _clamp(stdmath_byte4 min, stdmath_byte4 max) {
		return stdmath_byte4_clamp(*self, min, max);
	}
	stdmath_byte4 _reflect(stdmath_byte4 n) {
		return stdmath_byte4_reflect(*self, n);
	}
	stdmath_bool4 _approximately_equal(stdmath_byte4 o) {
		return stdmath_byte4_approximately_equal(*self, o);
	}

#if false
	stdmath_bool4 _all_of() {
		return stdmath_bool4_all_of(*self);
	}
	stdmath_bool4 _any_of() {
		return stdmath_bool4_any_of(*self);
	}
	stdmath_bool4 _none_of() {
		return stdmath_bool4_none_of(*self);
	}
	stdmath_bool4 _some_of() {
		return stdmath_bool4_some_of(*self);
	}
#endif

	size_t _size() {
		return 4;
	}

	uint8_t _get_element(size_t i) {
		return self->data[i];
	}

	uint8_t _set_element(size_t i, uint8_t value) {
		return self->data[i] = value;
	}
}