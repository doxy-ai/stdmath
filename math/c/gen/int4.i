#define STDMATH_EXPORT
#define STDMATH_INLINE
%rename(int4) stdmath_int4;
%include "int4.h"

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

%extend stdmath_int4 {
	stdmath_int4(int32_t broadcast) {
		stdmath_int4 *v;
		v = (stdmath_int4 *) malloc(sizeof(stdmath_int4));
		*v = stdmath_int4_broadcast(broadcast);
		return v;
	}

#if 4 == 4
	stdmath_int4(int32_t x = 0, int32_t y = 0, int32_t z = 0, int32_t w = 0) {
		stdmath_int4 *v;
		v = (stdmath_int4 *) malloc(sizeof(stdmath_int4));
		v->x = x;
		v->y = y;
		v->z = z;
		v->w = w;
		return v;
	}
#elif 4 == 3
	stdmath_int4(int32_t x = 0, int32_t y = 0, int32_t z = 0) {
		stdmath_int4 *v;
		v = (stdmath_int4 *) malloc(sizeof(stdmath_int4));
		v->x = x;
		v->y = y;
		v->z = z;
		return v;
	}
#elif 4 == 2
	stdmath_int4(int32_t x = 0, int32_t y = 0) {
		stdmath_int4 *v;
		v = (stdmath_int4 *) malloc(sizeof(stdmath_int4));
		v->x = x;
		v->y = y;
		return v;
	}
#elif 4 == 1
	stdmath_int4(int32_t x = 0) {
		stdmath_int4 *v;
		v = (stdmath_int4 *) malloc(sizeof(stdmath_int4));
		v->x = x;
		return v;
	}
#endif

#ifndef STDMATH_NO_SWIZZLES
	stdmath_int2 xx;
	stdmath_int2 xy;
	stdmath_int2 xz;
	stdmath_int2 xw;
	stdmath_int2 yx;
	stdmath_int2 yy;
	stdmath_int2 yz;
	stdmath_int2 yw;
	stdmath_int2 zx;
	stdmath_int2 zy;
	stdmath_int2 zz;
	stdmath_int2 zw;
	stdmath_int2 wx;
	stdmath_int2 wy;
	stdmath_int2 wz;
	stdmath_int2 ww;
	stdmath_int3 xxx;
	stdmath_int3 xxy;
	stdmath_int3 xxz;
	stdmath_int3 xxw;
	stdmath_int3 xyx;
	stdmath_int3 xyy;
	stdmath_int3 xyz;
	stdmath_int3 xyw;
	stdmath_int3 xzx;
	stdmath_int3 xzy;
	stdmath_int3 xzz;
	stdmath_int3 xzw;
	stdmath_int3 xwx;
	stdmath_int3 xwy;
	stdmath_int3 xwz;
	stdmath_int3 xww;
	stdmath_int3 yxx;
	stdmath_int3 yxy;
	stdmath_int3 yxz;
	stdmath_int3 yxw;
	stdmath_int3 yyx;
	stdmath_int3 yyy;
	stdmath_int3 yyz;
	stdmath_int3 yyw;
	stdmath_int3 yzx;
	stdmath_int3 yzy;
	stdmath_int3 yzz;
	stdmath_int3 yzw;
	stdmath_int3 ywx;
	stdmath_int3 ywy;
	stdmath_int3 ywz;
	stdmath_int3 yww;
	stdmath_int3 zxx;
	stdmath_int3 zxy;
	stdmath_int3 zxz;
	stdmath_int3 zxw;
	stdmath_int3 zyx;
	stdmath_int3 zyy;
	stdmath_int3 zyz;
	stdmath_int3 zyw;
	stdmath_int3 zzx;
	stdmath_int3 zzy;
	stdmath_int3 zzz;
	stdmath_int3 zzw;
	stdmath_int3 zwx;
	stdmath_int3 zwy;
	stdmath_int3 zwz;
	stdmath_int3 zww;
	stdmath_int3 wxx;
	stdmath_int3 wxy;
	stdmath_int3 wxz;
	stdmath_int3 wxw;
	stdmath_int3 wyx;
	stdmath_int3 wyy;
	stdmath_int3 wyz;
	stdmath_int3 wyw;
	stdmath_int3 wzx;
	stdmath_int3 wzy;
	stdmath_int3 wzz;
	stdmath_int3 wzw;
	stdmath_int3 wwx;
	stdmath_int3 wwy;
	stdmath_int3 wwz;
	stdmath_int3 www;
	stdmath_int4 xxxx;
	stdmath_int4 xxxy;
	stdmath_int4 xxxz;
	stdmath_int4 xxxw;
	stdmath_int4 xxyx;
	stdmath_int4 xxyy;
	stdmath_int4 xxyz;
	stdmath_int4 xxyw;
	stdmath_int4 xxzx;
	stdmath_int4 xxzy;
	stdmath_int4 xxzz;
	stdmath_int4 xxzw;
	stdmath_int4 xxwx;
	stdmath_int4 xxwy;
	stdmath_int4 xxwz;
	stdmath_int4 xxww;
	stdmath_int4 xyxx;
	stdmath_int4 xyxy;
	stdmath_int4 xyxz;
	stdmath_int4 xyxw;
	stdmath_int4 xyyx;
	stdmath_int4 xyyy;
	stdmath_int4 xyyz;
	stdmath_int4 xyyw;
	stdmath_int4 xyzx;
	stdmath_int4 xyzy;
	stdmath_int4 xyzz;
	stdmath_int4 xyzw;
	stdmath_int4 xywx;
	stdmath_int4 xywy;
	stdmath_int4 xywz;
	stdmath_int4 xyww;
	stdmath_int4 xzxx;
	stdmath_int4 xzxy;
	stdmath_int4 xzxz;
	stdmath_int4 xzxw;
	stdmath_int4 xzyx;
	stdmath_int4 xzyy;
	stdmath_int4 xzyz;
	stdmath_int4 xzyw;
	stdmath_int4 xzzx;
	stdmath_int4 xzzy;
	stdmath_int4 xzzz;
	stdmath_int4 xzzw;
	stdmath_int4 xzwx;
	stdmath_int4 xzwy;
	stdmath_int4 xzwz;
	stdmath_int4 xzww;
	stdmath_int4 xwxx;
	stdmath_int4 xwxy;
	stdmath_int4 xwxz;
	stdmath_int4 xwxw;
	stdmath_int4 xwyx;
	stdmath_int4 xwyy;
	stdmath_int4 xwyz;
	stdmath_int4 xwyw;
	stdmath_int4 xwzx;
	stdmath_int4 xwzy;
	stdmath_int4 xwzz;
	stdmath_int4 xwzw;
	stdmath_int4 xwwx;
	stdmath_int4 xwwy;
	stdmath_int4 xwwz;
	stdmath_int4 xwww;
	stdmath_int4 yxxx;
	stdmath_int4 yxxy;
	stdmath_int4 yxxz;
	stdmath_int4 yxxw;
	stdmath_int4 yxyx;
	stdmath_int4 yxyy;
	stdmath_int4 yxyz;
	stdmath_int4 yxyw;
	stdmath_int4 yxzx;
	stdmath_int4 yxzy;
	stdmath_int4 yxzz;
	stdmath_int4 yxzw;
	stdmath_int4 yxwx;
	stdmath_int4 yxwy;
	stdmath_int4 yxwz;
	stdmath_int4 yxww;
	stdmath_int4 yyxx;
	stdmath_int4 yyxy;
	stdmath_int4 yyxz;
	stdmath_int4 yyxw;
	stdmath_int4 yyyx;
	stdmath_int4 yyyy;
	stdmath_int4 yyyz;
	stdmath_int4 yyyw;
	stdmath_int4 yyzx;
	stdmath_int4 yyzy;
	stdmath_int4 yyzz;
	stdmath_int4 yyzw;
	stdmath_int4 yywx;
	stdmath_int4 yywy;
	stdmath_int4 yywz;
	stdmath_int4 yyww;
	stdmath_int4 yzxx;
	stdmath_int4 yzxy;
	stdmath_int4 yzxz;
	stdmath_int4 yzxw;
	stdmath_int4 yzyx;
	stdmath_int4 yzyy;
	stdmath_int4 yzyz;
	stdmath_int4 yzyw;
	stdmath_int4 yzzx;
	stdmath_int4 yzzy;
	stdmath_int4 yzzz;
	stdmath_int4 yzzw;
	stdmath_int4 yzwx;
	stdmath_int4 yzwy;
	stdmath_int4 yzwz;
	stdmath_int4 yzww;
	stdmath_int4 ywxx;
	stdmath_int4 ywxy;
	stdmath_int4 ywxz;
	stdmath_int4 ywxw;
	stdmath_int4 ywyx;
	stdmath_int4 ywyy;
	stdmath_int4 ywyz;
	stdmath_int4 ywyw;
	stdmath_int4 ywzx;
	stdmath_int4 ywzy;
	stdmath_int4 ywzz;
	stdmath_int4 ywzw;
	stdmath_int4 ywwx;
	stdmath_int4 ywwy;
	stdmath_int4 ywwz;
	stdmath_int4 ywww;
	stdmath_int4 zxxx;
	stdmath_int4 zxxy;
	stdmath_int4 zxxz;
	stdmath_int4 zxxw;
	stdmath_int4 zxyx;
	stdmath_int4 zxyy;
	stdmath_int4 zxyz;
	stdmath_int4 zxyw;
	stdmath_int4 zxzx;
	stdmath_int4 zxzy;
	stdmath_int4 zxzz;
	stdmath_int4 zxzw;
	stdmath_int4 zxwx;
	stdmath_int4 zxwy;
	stdmath_int4 zxwz;
	stdmath_int4 zxww;
	stdmath_int4 zyxx;
	stdmath_int4 zyxy;
	stdmath_int4 zyxz;
	stdmath_int4 zyxw;
	stdmath_int4 zyyx;
	stdmath_int4 zyyy;
	stdmath_int4 zyyz;
	stdmath_int4 zyyw;
	stdmath_int4 zyzx;
	stdmath_int4 zyzy;
	stdmath_int4 zyzz;
	stdmath_int4 zyzw;
	stdmath_int4 zywx;
	stdmath_int4 zywy;
	stdmath_int4 zywz;
	stdmath_int4 zyww;
	stdmath_int4 zzxx;
	stdmath_int4 zzxy;
	stdmath_int4 zzxz;
	stdmath_int4 zzxw;
	stdmath_int4 zzyx;
	stdmath_int4 zzyy;
	stdmath_int4 zzyz;
	stdmath_int4 zzyw;
	stdmath_int4 zzzx;
	stdmath_int4 zzzy;
	stdmath_int4 zzzz;
	stdmath_int4 zzzw;
	stdmath_int4 zzwx;
	stdmath_int4 zzwy;
	stdmath_int4 zzwz;
	stdmath_int4 zzww;
	stdmath_int4 zwxx;
	stdmath_int4 zwxy;
	stdmath_int4 zwxz;
	stdmath_int4 zwxw;
	stdmath_int4 zwyx;
	stdmath_int4 zwyy;
	stdmath_int4 zwyz;
	stdmath_int4 zwyw;
	stdmath_int4 zwzx;
	stdmath_int4 zwzy;
	stdmath_int4 zwzz;
	stdmath_int4 zwzw;
	stdmath_int4 zwwx;
	stdmath_int4 zwwy;
	stdmath_int4 zwwz;
	stdmath_int4 zwww;
	stdmath_int4 wxxx;
	stdmath_int4 wxxy;
	stdmath_int4 wxxz;
	stdmath_int4 wxxw;
	stdmath_int4 wxyx;
	stdmath_int4 wxyy;
	stdmath_int4 wxyz;
	stdmath_int4 wxyw;
	stdmath_int4 wxzx;
	stdmath_int4 wxzy;
	stdmath_int4 wxzz;
	stdmath_int4 wxzw;
	stdmath_int4 wxwx;
	stdmath_int4 wxwy;
	stdmath_int4 wxwz;
	stdmath_int4 wxww;
	stdmath_int4 wyxx;
	stdmath_int4 wyxy;
	stdmath_int4 wyxz;
	stdmath_int4 wyxw;
	stdmath_int4 wyyx;
	stdmath_int4 wyyy;
	stdmath_int4 wyyz;
	stdmath_int4 wyyw;
	stdmath_int4 wyzx;
	stdmath_int4 wyzy;
	stdmath_int4 wyzz;
	stdmath_int4 wyzw;
	stdmath_int4 wywx;
	stdmath_int4 wywy;
	stdmath_int4 wywz;
	stdmath_int4 wyww;
	stdmath_int4 wzxx;
	stdmath_int4 wzxy;
	stdmath_int4 wzxz;
	stdmath_int4 wzxw;
	stdmath_int4 wzyx;
	stdmath_int4 wzyy;
	stdmath_int4 wzyz;
	stdmath_int4 wzyw;
	stdmath_int4 wzzx;
	stdmath_int4 wzzy;
	stdmath_int4 wzzz;
	stdmath_int4 wzzw;
	stdmath_int4 wzwx;
	stdmath_int4 wzwy;
	stdmath_int4 wzwz;
	stdmath_int4 wzww;
	stdmath_int4 wwxx;
	stdmath_int4 wwxy;
	stdmath_int4 wwxz;
	stdmath_int4 wwxw;
	stdmath_int4 wwyx;
	stdmath_int4 wwyy;
	stdmath_int4 wwyz;
	stdmath_int4 wwyw;
	stdmath_int4 wwzx;
	stdmath_int4 wwzy;
	stdmath_int4 wwzz;
	stdmath_int4 wwzw;
	stdmath_int4 wwwx;
	stdmath_int4 wwwy;
	stdmath_int4 wwwz;
	stdmath_int4 wwww;

#endif

	stdmath_int4 _add(stdmath_int4 o) {
		return stdmath_int4_add(*self, o);
	}
	stdmath_int4 _subtract(stdmath_int4 o) {
		return stdmath_int4_subtract(*self, o);
	}
	stdmath_int4 _negate() {
		return stdmath_int4_negate(*self);
	}
	stdmath_int4 _multiply(stdmath_int4 o) {
		return stdmath_int4_multiply(*self, o);
	}
	stdmath_int4 _divide(stdmath_int4 o) {
		return stdmath_int4_divide(*self, o);
	}
	stdmath_int4 _scale(int32_t o) {
		return stdmath_int4_scale(*self, o);
	}

#if false
	stdmath_int4 _modulus(stdmath_int4 o) {
		return stdmath_int4_modulus(*self, o);
	}
	stdmath_int4 _logical_not() {
		return stdmath_int4_logical_not(*self);
	}
	stdmath_int4 _bitwise_not() {
		return stdmath_int4_bitwise_not(*self);
	}
	stdmath_int4 _logical_and(stdmath_int4 o) {
		return stdmath_int4_logical_and(*self, o);
	}
	stdmath_int4 _bitwise_and(stdmath_int4 o) {
		return stdmath_int4_bitwise_and(*self, o);
	}
	stdmath_int4 _logical_or(stdmath_int4 o) {
		return stdmath_int4_logical_or(*self, o);
	}
	stdmath_int4 _bitwise_or(stdmath_int4 o) {
		return stdmath_int4_bitwise_or(*self, o);
	}
	stdmath_int4 _bitwise_xor(stdmath_int4 o) {
		return stdmath_int4_bitwise_xor(*self, o);
	}
	stdmath_int4 _shift_left(stdmath_int4 o) {
		return stdmath_int4_shift_left(*self, o);
	}
	stdmath_int4 _shift_right(stdmath_int4 o) {
		return stdmath_int4_shift_right(*self, o);
	}
#endif

	stdmath_bool4 _equal_to(stdmath_int4 o) {
		return stdmath_int4_equal_to(*self, o);
	}
	stdmath_bool4 _not_equal_to(stdmath_int4 o) {
		return stdmath_int4_not_equal_to(*self, o);
	}
	stdmath_bool4 _less_than(stdmath_int4 o) {
		return stdmath_int4_less_than(*self, o);
	}
	stdmath_bool4 _less_than_or_equal_to(stdmath_int4 o) {
		return stdmath_int4_less_than_or_equal_to(*self, o);
	}
	stdmath_bool4 _greater_than(stdmath_int4 o) {
		return stdmath_int4_greater_than(*self, o);
	}
	stdmath_bool4 _greater_than_or_equal_to(stdmath_int4 o) {
		return stdmath_int4_greater_than_or_equal_to(*self, o);
	}

	int32_t _length_squared() {
		return stdmath_int4_length_squared(*self);
	}
	int32_t _length() {
		return stdmath_int4_length(*self);
	}
	int32_t _dot(stdmath_int4 o) {
		return stdmath_int4_dot(*self, o);
	}
	int32_t _min_element() {
		return stdmath_int4_min_element(*self);
	}
	int32_t _max_element() {
		return stdmath_int4_max_element(*self);
	}

	// int32_t elementwise_transform()
	// int32_t reduce_element

	stdmath_int4 _min(stdmath_int4 o) {
		return stdmath_int4_min(*self, o);
	}
	stdmath_int4 _max(stdmath_int4 o) {
		return stdmath_int4_max(*self, o);
	}
	stdmath_int4 _normalize() {
		return stdmath_int4_normalize(*self);
	}
	stdmath_int4 _lerp(stdmath_int4 o, float t) {
		return stdmath_int4_lerp(*self, o, t);
	}
	stdmath_int4 _clamp(stdmath_int4 min, stdmath_int4 max) {
		return stdmath_int4_clamp(*self, min, max);
	}
	stdmath_int4 _reflect(stdmath_int4 n) {
		return stdmath_int4_reflect(*self, n);
	}
	stdmath_bool4 _approximately_equal(stdmath_int4 o) {
		return stdmath_int4_approximately_equal(*self, o);
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

	int32_t _get_element(size_t i) {
		return self->data[i];
	}

	int32_t _set_element(size_t i, int32_t value) {
		return self->data[i] = value;
	}
}