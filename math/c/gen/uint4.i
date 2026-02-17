#define STDMATH_EXPORT
#define STDMATH_INLINE
%rename(uint4) stdmath_uint4;
%include "uint4.h"

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

%extend stdmath_uint4 {
	stdmath_uint4(uint32_t broadcast) {
		stdmath_uint4 *v;
		v = (stdmath_uint4 *) malloc(sizeof(stdmath_uint4));
		*v = stdmath_uint4_broadcast(broadcast);
		return v;
	}

#if 4 == 4
	stdmath_uint4(uint32_t x = 0, uint32_t y = 0, uint32_t z = 0, uint32_t w = 0) {
		stdmath_uint4 *v;
		v = (stdmath_uint4 *) malloc(sizeof(stdmath_uint4));
		v->x = x;
		v->y = y;
		v->z = z;
		v->w = w;
		return v;
	}
#elif 4 == 3
	stdmath_uint4(uint32_t x = 0, uint32_t y = 0, uint32_t z = 0) {
		stdmath_uint4 *v;
		v = (stdmath_uint4 *) malloc(sizeof(stdmath_uint4));
		v->x = x;
		v->y = y;
		v->z = z;
		return v;
	}
#elif 4 == 2
	stdmath_uint4(uint32_t x = 0, uint32_t y = 0) {
		stdmath_uint4 *v;
		v = (stdmath_uint4 *) malloc(sizeof(stdmath_uint4));
		v->x = x;
		v->y = y;
		return v;
	}
#elif 4 == 1
	stdmath_uint4(uint32_t x = 0) {
		stdmath_uint4 *v;
		v = (stdmath_uint4 *) malloc(sizeof(stdmath_uint4));
		v->x = x;
		return v;
	}
#endif

#ifndef STDMATH_NO_SWIZZLES
	stdmath_uint2 xx;
	stdmath_uint2 xy;
	stdmath_uint2 xz;
	stdmath_uint2 xw;
	stdmath_uint2 yx;
	stdmath_uint2 yy;
	stdmath_uint2 yz;
	stdmath_uint2 yw;
	stdmath_uint2 zx;
	stdmath_uint2 zy;
	stdmath_uint2 zz;
	stdmath_uint2 zw;
	stdmath_uint2 wx;
	stdmath_uint2 wy;
	stdmath_uint2 wz;
	stdmath_uint2 ww;
	stdmath_uint3 xxx;
	stdmath_uint3 xxy;
	stdmath_uint3 xxz;
	stdmath_uint3 xxw;
	stdmath_uint3 xyx;
	stdmath_uint3 xyy;
	stdmath_uint3 xyz;
	stdmath_uint3 xyw;
	stdmath_uint3 xzx;
	stdmath_uint3 xzy;
	stdmath_uint3 xzz;
	stdmath_uint3 xzw;
	stdmath_uint3 xwx;
	stdmath_uint3 xwy;
	stdmath_uint3 xwz;
	stdmath_uint3 xww;
	stdmath_uint3 yxx;
	stdmath_uint3 yxy;
	stdmath_uint3 yxz;
	stdmath_uint3 yxw;
	stdmath_uint3 yyx;
	stdmath_uint3 yyy;
	stdmath_uint3 yyz;
	stdmath_uint3 yyw;
	stdmath_uint3 yzx;
	stdmath_uint3 yzy;
	stdmath_uint3 yzz;
	stdmath_uint3 yzw;
	stdmath_uint3 ywx;
	stdmath_uint3 ywy;
	stdmath_uint3 ywz;
	stdmath_uint3 yww;
	stdmath_uint3 zxx;
	stdmath_uint3 zxy;
	stdmath_uint3 zxz;
	stdmath_uint3 zxw;
	stdmath_uint3 zyx;
	stdmath_uint3 zyy;
	stdmath_uint3 zyz;
	stdmath_uint3 zyw;
	stdmath_uint3 zzx;
	stdmath_uint3 zzy;
	stdmath_uint3 zzz;
	stdmath_uint3 zzw;
	stdmath_uint3 zwx;
	stdmath_uint3 zwy;
	stdmath_uint3 zwz;
	stdmath_uint3 zww;
	stdmath_uint3 wxx;
	stdmath_uint3 wxy;
	stdmath_uint3 wxz;
	stdmath_uint3 wxw;
	stdmath_uint3 wyx;
	stdmath_uint3 wyy;
	stdmath_uint3 wyz;
	stdmath_uint3 wyw;
	stdmath_uint3 wzx;
	stdmath_uint3 wzy;
	stdmath_uint3 wzz;
	stdmath_uint3 wzw;
	stdmath_uint3 wwx;
	stdmath_uint3 wwy;
	stdmath_uint3 wwz;
	stdmath_uint3 www;
	stdmath_uint4 xxxx;
	stdmath_uint4 xxxy;
	stdmath_uint4 xxxz;
	stdmath_uint4 xxxw;
	stdmath_uint4 xxyx;
	stdmath_uint4 xxyy;
	stdmath_uint4 xxyz;
	stdmath_uint4 xxyw;
	stdmath_uint4 xxzx;
	stdmath_uint4 xxzy;
	stdmath_uint4 xxzz;
	stdmath_uint4 xxzw;
	stdmath_uint4 xxwx;
	stdmath_uint4 xxwy;
	stdmath_uint4 xxwz;
	stdmath_uint4 xxww;
	stdmath_uint4 xyxx;
	stdmath_uint4 xyxy;
	stdmath_uint4 xyxz;
	stdmath_uint4 xyxw;
	stdmath_uint4 xyyx;
	stdmath_uint4 xyyy;
	stdmath_uint4 xyyz;
	stdmath_uint4 xyyw;
	stdmath_uint4 xyzx;
	stdmath_uint4 xyzy;
	stdmath_uint4 xyzz;
	stdmath_uint4 xyzw;
	stdmath_uint4 xywx;
	stdmath_uint4 xywy;
	stdmath_uint4 xywz;
	stdmath_uint4 xyww;
	stdmath_uint4 xzxx;
	stdmath_uint4 xzxy;
	stdmath_uint4 xzxz;
	stdmath_uint4 xzxw;
	stdmath_uint4 xzyx;
	stdmath_uint4 xzyy;
	stdmath_uint4 xzyz;
	stdmath_uint4 xzyw;
	stdmath_uint4 xzzx;
	stdmath_uint4 xzzy;
	stdmath_uint4 xzzz;
	stdmath_uint4 xzzw;
	stdmath_uint4 xzwx;
	stdmath_uint4 xzwy;
	stdmath_uint4 xzwz;
	stdmath_uint4 xzww;
	stdmath_uint4 xwxx;
	stdmath_uint4 xwxy;
	stdmath_uint4 xwxz;
	stdmath_uint4 xwxw;
	stdmath_uint4 xwyx;
	stdmath_uint4 xwyy;
	stdmath_uint4 xwyz;
	stdmath_uint4 xwyw;
	stdmath_uint4 xwzx;
	stdmath_uint4 xwzy;
	stdmath_uint4 xwzz;
	stdmath_uint4 xwzw;
	stdmath_uint4 xwwx;
	stdmath_uint4 xwwy;
	stdmath_uint4 xwwz;
	stdmath_uint4 xwww;
	stdmath_uint4 yxxx;
	stdmath_uint4 yxxy;
	stdmath_uint4 yxxz;
	stdmath_uint4 yxxw;
	stdmath_uint4 yxyx;
	stdmath_uint4 yxyy;
	stdmath_uint4 yxyz;
	stdmath_uint4 yxyw;
	stdmath_uint4 yxzx;
	stdmath_uint4 yxzy;
	stdmath_uint4 yxzz;
	stdmath_uint4 yxzw;
	stdmath_uint4 yxwx;
	stdmath_uint4 yxwy;
	stdmath_uint4 yxwz;
	stdmath_uint4 yxww;
	stdmath_uint4 yyxx;
	stdmath_uint4 yyxy;
	stdmath_uint4 yyxz;
	stdmath_uint4 yyxw;
	stdmath_uint4 yyyx;
	stdmath_uint4 yyyy;
	stdmath_uint4 yyyz;
	stdmath_uint4 yyyw;
	stdmath_uint4 yyzx;
	stdmath_uint4 yyzy;
	stdmath_uint4 yyzz;
	stdmath_uint4 yyzw;
	stdmath_uint4 yywx;
	stdmath_uint4 yywy;
	stdmath_uint4 yywz;
	stdmath_uint4 yyww;
	stdmath_uint4 yzxx;
	stdmath_uint4 yzxy;
	stdmath_uint4 yzxz;
	stdmath_uint4 yzxw;
	stdmath_uint4 yzyx;
	stdmath_uint4 yzyy;
	stdmath_uint4 yzyz;
	stdmath_uint4 yzyw;
	stdmath_uint4 yzzx;
	stdmath_uint4 yzzy;
	stdmath_uint4 yzzz;
	stdmath_uint4 yzzw;
	stdmath_uint4 yzwx;
	stdmath_uint4 yzwy;
	stdmath_uint4 yzwz;
	stdmath_uint4 yzww;
	stdmath_uint4 ywxx;
	stdmath_uint4 ywxy;
	stdmath_uint4 ywxz;
	stdmath_uint4 ywxw;
	stdmath_uint4 ywyx;
	stdmath_uint4 ywyy;
	stdmath_uint4 ywyz;
	stdmath_uint4 ywyw;
	stdmath_uint4 ywzx;
	stdmath_uint4 ywzy;
	stdmath_uint4 ywzz;
	stdmath_uint4 ywzw;
	stdmath_uint4 ywwx;
	stdmath_uint4 ywwy;
	stdmath_uint4 ywwz;
	stdmath_uint4 ywww;
	stdmath_uint4 zxxx;
	stdmath_uint4 zxxy;
	stdmath_uint4 zxxz;
	stdmath_uint4 zxxw;
	stdmath_uint4 zxyx;
	stdmath_uint4 zxyy;
	stdmath_uint4 zxyz;
	stdmath_uint4 zxyw;
	stdmath_uint4 zxzx;
	stdmath_uint4 zxzy;
	stdmath_uint4 zxzz;
	stdmath_uint4 zxzw;
	stdmath_uint4 zxwx;
	stdmath_uint4 zxwy;
	stdmath_uint4 zxwz;
	stdmath_uint4 zxww;
	stdmath_uint4 zyxx;
	stdmath_uint4 zyxy;
	stdmath_uint4 zyxz;
	stdmath_uint4 zyxw;
	stdmath_uint4 zyyx;
	stdmath_uint4 zyyy;
	stdmath_uint4 zyyz;
	stdmath_uint4 zyyw;
	stdmath_uint4 zyzx;
	stdmath_uint4 zyzy;
	stdmath_uint4 zyzz;
	stdmath_uint4 zyzw;
	stdmath_uint4 zywx;
	stdmath_uint4 zywy;
	stdmath_uint4 zywz;
	stdmath_uint4 zyww;
	stdmath_uint4 zzxx;
	stdmath_uint4 zzxy;
	stdmath_uint4 zzxz;
	stdmath_uint4 zzxw;
	stdmath_uint4 zzyx;
	stdmath_uint4 zzyy;
	stdmath_uint4 zzyz;
	stdmath_uint4 zzyw;
	stdmath_uint4 zzzx;
	stdmath_uint4 zzzy;
	stdmath_uint4 zzzz;
	stdmath_uint4 zzzw;
	stdmath_uint4 zzwx;
	stdmath_uint4 zzwy;
	stdmath_uint4 zzwz;
	stdmath_uint4 zzww;
	stdmath_uint4 zwxx;
	stdmath_uint4 zwxy;
	stdmath_uint4 zwxz;
	stdmath_uint4 zwxw;
	stdmath_uint4 zwyx;
	stdmath_uint4 zwyy;
	stdmath_uint4 zwyz;
	stdmath_uint4 zwyw;
	stdmath_uint4 zwzx;
	stdmath_uint4 zwzy;
	stdmath_uint4 zwzz;
	stdmath_uint4 zwzw;
	stdmath_uint4 zwwx;
	stdmath_uint4 zwwy;
	stdmath_uint4 zwwz;
	stdmath_uint4 zwww;
	stdmath_uint4 wxxx;
	stdmath_uint4 wxxy;
	stdmath_uint4 wxxz;
	stdmath_uint4 wxxw;
	stdmath_uint4 wxyx;
	stdmath_uint4 wxyy;
	stdmath_uint4 wxyz;
	stdmath_uint4 wxyw;
	stdmath_uint4 wxzx;
	stdmath_uint4 wxzy;
	stdmath_uint4 wxzz;
	stdmath_uint4 wxzw;
	stdmath_uint4 wxwx;
	stdmath_uint4 wxwy;
	stdmath_uint4 wxwz;
	stdmath_uint4 wxww;
	stdmath_uint4 wyxx;
	stdmath_uint4 wyxy;
	stdmath_uint4 wyxz;
	stdmath_uint4 wyxw;
	stdmath_uint4 wyyx;
	stdmath_uint4 wyyy;
	stdmath_uint4 wyyz;
	stdmath_uint4 wyyw;
	stdmath_uint4 wyzx;
	stdmath_uint4 wyzy;
	stdmath_uint4 wyzz;
	stdmath_uint4 wyzw;
	stdmath_uint4 wywx;
	stdmath_uint4 wywy;
	stdmath_uint4 wywz;
	stdmath_uint4 wyww;
	stdmath_uint4 wzxx;
	stdmath_uint4 wzxy;
	stdmath_uint4 wzxz;
	stdmath_uint4 wzxw;
	stdmath_uint4 wzyx;
	stdmath_uint4 wzyy;
	stdmath_uint4 wzyz;
	stdmath_uint4 wzyw;
	stdmath_uint4 wzzx;
	stdmath_uint4 wzzy;
	stdmath_uint4 wzzz;
	stdmath_uint4 wzzw;
	stdmath_uint4 wzwx;
	stdmath_uint4 wzwy;
	stdmath_uint4 wzwz;
	stdmath_uint4 wzww;
	stdmath_uint4 wwxx;
	stdmath_uint4 wwxy;
	stdmath_uint4 wwxz;
	stdmath_uint4 wwxw;
	stdmath_uint4 wwyx;
	stdmath_uint4 wwyy;
	stdmath_uint4 wwyz;
	stdmath_uint4 wwyw;
	stdmath_uint4 wwzx;
	stdmath_uint4 wwzy;
	stdmath_uint4 wwzz;
	stdmath_uint4 wwzw;
	stdmath_uint4 wwwx;
	stdmath_uint4 wwwy;
	stdmath_uint4 wwwz;
	stdmath_uint4 wwww;

#endif

	stdmath_uint4 _add(stdmath_uint4 o) {
		return stdmath_uint4_add(*self, o);
	}
	stdmath_uint4 _subtract(stdmath_uint4 o) {
		return stdmath_uint4_subtract(*self, o);
	}
	stdmath_uint4 _negate() {
		return stdmath_uint4_negate(*self);
	}
	stdmath_uint4 _multiply(stdmath_uint4 o) {
		return stdmath_uint4_multiply(*self, o);
	}
	stdmath_uint4 _divide(stdmath_uint4 o) {
		return stdmath_uint4_divide(*self, o);
	}
	stdmath_uint4 _scale(uint32_t o) {
		return stdmath_uint4_scale(*self, o);
	}

#if false
	stdmath_uint4 _modulus(stdmath_uint4 o) {
		return stdmath_uint4_modulus(*self, o);
	}
	stdmath_uint4 _logical_not() {
		return stdmath_uint4_logical_not(*self);
	}
	stdmath_uint4 _bitwise_not() {
		return stdmath_uint4_bitwise_not(*self);
	}
	stdmath_uint4 _logical_and(stdmath_uint4 o) {
		return stdmath_uint4_logical_and(*self, o);
	}
	stdmath_uint4 _bitwise_and(stdmath_uint4 o) {
		return stdmath_uint4_bitwise_and(*self, o);
	}
	stdmath_uint4 _logical_or(stdmath_uint4 o) {
		return stdmath_uint4_logical_or(*self, o);
	}
	stdmath_uint4 _bitwise_or(stdmath_uint4 o) {
		return stdmath_uint4_bitwise_or(*self, o);
	}
	stdmath_uint4 _bitwise_xor(stdmath_uint4 o) {
		return stdmath_uint4_bitwise_xor(*self, o);
	}
	stdmath_uint4 _shift_left(stdmath_uint4 o) {
		return stdmath_uint4_shift_left(*self, o);
	}
	stdmath_uint4 _shift_right(stdmath_uint4 o) {
		return stdmath_uint4_shift_right(*self, o);
	}
#endif

	stdmath_bool4 _equal_to(stdmath_uint4 o) {
		return stdmath_uint4_equal_to(*self, o);
	}
	stdmath_bool4 _not_equal_to(stdmath_uint4 o) {
		return stdmath_uint4_not_equal_to(*self, o);
	}
	stdmath_bool4 _less_than(stdmath_uint4 o) {
		return stdmath_uint4_less_than(*self, o);
	}
	stdmath_bool4 _less_than_or_equal_to(stdmath_uint4 o) {
		return stdmath_uint4_less_than_or_equal_to(*self, o);
	}
	stdmath_bool4 _greater_than(stdmath_uint4 o) {
		return stdmath_uint4_greater_than(*self, o);
	}
	stdmath_bool4 _greater_than_or_equal_to(stdmath_uint4 o) {
		return stdmath_uint4_greater_than_or_equal_to(*self, o);
	}

	uint32_t _length_squared() {
		return stdmath_uint4_length_squared(*self);
	}
	uint32_t _length() {
		return stdmath_uint4_length(*self);
	}
	uint32_t _dot(stdmath_uint4 o) {
		return stdmath_uint4_dot(*self, o);
	}
	uint32_t _min_element() {
		return stdmath_uint4_min_element(*self);
	}
	uint32_t _max_element() {
		return stdmath_uint4_max_element(*self);
	}

	// uint32_t elementwise_transform()
	// uint32_t reduce_element

	stdmath_uint4 _min(stdmath_uint4 o) {
		return stdmath_uint4_min(*self, o);
	}
	stdmath_uint4 _max(stdmath_uint4 o) {
		return stdmath_uint4_max(*self, o);
	}
	stdmath_uint4 _normalize() {
		return stdmath_uint4_normalize(*self);
	}
	stdmath_uint4 _lerp(stdmath_uint4 o, float t) {
		return stdmath_uint4_lerp(*self, o, t);
	}
	stdmath_uint4 _clamp(stdmath_uint4 min, stdmath_uint4 max) {
		return stdmath_uint4_clamp(*self, min, max);
	}
	stdmath_uint4 _reflect(stdmath_uint4 n) {
		return stdmath_uint4_reflect(*self, n);
	}
	stdmath_bool4 _approximately_equal(stdmath_uint4 o) {
		return stdmath_uint4_approximately_equal(*self, o);
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

	uint32_t _get_element(size_t i) {
		return self->data[i];
	}

	uint32_t _set_element(size_t i, uint32_t value) {
		return self->data[i] = value;
	}
}