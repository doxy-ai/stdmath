#define STDMATH_EXPORT
#define STDMATH_INLINE
%rename(radian4) stdmath_radian4;
%include "radian4.h"

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

%extend stdmath_radian4 {
	stdmath_radian4(stdmath_radian broadcast) {
		stdmath_radian4 *v;
		v = (stdmath_radian4 *) malloc(sizeof(stdmath_radian4));
		*v = stdmath_radian4_broadcast(broadcast);
		return v;
	}

#if 4 == 4
	stdmath_radian4(stdmath_radian x = 0, stdmath_radian y = 0, stdmath_radian z = 0, stdmath_radian w = 0) {
		stdmath_radian4 *v;
		v = (stdmath_radian4 *) malloc(sizeof(stdmath_radian4));
		v->x = x;
		v->y = y;
		v->z = z;
		v->w = w;
		return v;
	}
#elif 4 == 3
	stdmath_radian4(stdmath_radian x = 0, stdmath_radian y = 0, stdmath_radian z = 0) {
		stdmath_radian4 *v;
		v = (stdmath_radian4 *) malloc(sizeof(stdmath_radian4));
		v->x = x;
		v->y = y;
		v->z = z;
		return v;
	}
#elif 4 == 2
	stdmath_radian4(stdmath_radian x = 0, stdmath_radian y = 0) {
		stdmath_radian4 *v;
		v = (stdmath_radian4 *) malloc(sizeof(stdmath_radian4));
		v->x = x;
		v->y = y;
		return v;
	}
#elif 4 == 1
	stdmath_radian4(stdmath_radian x = 0) {
		stdmath_radian4 *v;
		v = (stdmath_radian4 *) malloc(sizeof(stdmath_radian4));
		v->x = x;
		return v;
	}
#endif

#ifndef STDMATH_NO_SWIZZLES
	stdmath_radian2 xx;
	stdmath_radian2 xy;
	stdmath_radian2 xz;
	stdmath_radian2 xw;
	stdmath_radian2 yx;
	stdmath_radian2 yy;
	stdmath_radian2 yz;
	stdmath_radian2 yw;
	stdmath_radian2 zx;
	stdmath_radian2 zy;
	stdmath_radian2 zz;
	stdmath_radian2 zw;
	stdmath_radian2 wx;
	stdmath_radian2 wy;
	stdmath_radian2 wz;
	stdmath_radian2 ww;
	stdmath_radian3 xxx;
	stdmath_radian3 xxy;
	stdmath_radian3 xxz;
	stdmath_radian3 xxw;
	stdmath_radian3 xyx;
	stdmath_radian3 xyy;
	stdmath_radian3 xyz;
	stdmath_radian3 xyw;
	stdmath_radian3 xzx;
	stdmath_radian3 xzy;
	stdmath_radian3 xzz;
	stdmath_radian3 xzw;
	stdmath_radian3 xwx;
	stdmath_radian3 xwy;
	stdmath_radian3 xwz;
	stdmath_radian3 xww;
	stdmath_radian3 yxx;
	stdmath_radian3 yxy;
	stdmath_radian3 yxz;
	stdmath_radian3 yxw;
	stdmath_radian3 yyx;
	stdmath_radian3 yyy;
	stdmath_radian3 yyz;
	stdmath_radian3 yyw;
	stdmath_radian3 yzx;
	stdmath_radian3 yzy;
	stdmath_radian3 yzz;
	stdmath_radian3 yzw;
	stdmath_radian3 ywx;
	stdmath_radian3 ywy;
	stdmath_radian3 ywz;
	stdmath_radian3 yww;
	stdmath_radian3 zxx;
	stdmath_radian3 zxy;
	stdmath_radian3 zxz;
	stdmath_radian3 zxw;
	stdmath_radian3 zyx;
	stdmath_radian3 zyy;
	stdmath_radian3 zyz;
	stdmath_radian3 zyw;
	stdmath_radian3 zzx;
	stdmath_radian3 zzy;
	stdmath_radian3 zzz;
	stdmath_radian3 zzw;
	stdmath_radian3 zwx;
	stdmath_radian3 zwy;
	stdmath_radian3 zwz;
	stdmath_radian3 zww;
	stdmath_radian3 wxx;
	stdmath_radian3 wxy;
	stdmath_radian3 wxz;
	stdmath_radian3 wxw;
	stdmath_radian3 wyx;
	stdmath_radian3 wyy;
	stdmath_radian3 wyz;
	stdmath_radian3 wyw;
	stdmath_radian3 wzx;
	stdmath_radian3 wzy;
	stdmath_radian3 wzz;
	stdmath_radian3 wzw;
	stdmath_radian3 wwx;
	stdmath_radian3 wwy;
	stdmath_radian3 wwz;
	stdmath_radian3 www;
	stdmath_radian4 xxxx;
	stdmath_radian4 xxxy;
	stdmath_radian4 xxxz;
	stdmath_radian4 xxxw;
	stdmath_radian4 xxyx;
	stdmath_radian4 xxyy;
	stdmath_radian4 xxyz;
	stdmath_radian4 xxyw;
	stdmath_radian4 xxzx;
	stdmath_radian4 xxzy;
	stdmath_radian4 xxzz;
	stdmath_radian4 xxzw;
	stdmath_radian4 xxwx;
	stdmath_radian4 xxwy;
	stdmath_radian4 xxwz;
	stdmath_radian4 xxww;
	stdmath_radian4 xyxx;
	stdmath_radian4 xyxy;
	stdmath_radian4 xyxz;
	stdmath_radian4 xyxw;
	stdmath_radian4 xyyx;
	stdmath_radian4 xyyy;
	stdmath_radian4 xyyz;
	stdmath_radian4 xyyw;
	stdmath_radian4 xyzx;
	stdmath_radian4 xyzy;
	stdmath_radian4 xyzz;
	stdmath_radian4 xyzw;
	stdmath_radian4 xywx;
	stdmath_radian4 xywy;
	stdmath_radian4 xywz;
	stdmath_radian4 xyww;
	stdmath_radian4 xzxx;
	stdmath_radian4 xzxy;
	stdmath_radian4 xzxz;
	stdmath_radian4 xzxw;
	stdmath_radian4 xzyx;
	stdmath_radian4 xzyy;
	stdmath_radian4 xzyz;
	stdmath_radian4 xzyw;
	stdmath_radian4 xzzx;
	stdmath_radian4 xzzy;
	stdmath_radian4 xzzz;
	stdmath_radian4 xzzw;
	stdmath_radian4 xzwx;
	stdmath_radian4 xzwy;
	stdmath_radian4 xzwz;
	stdmath_radian4 xzww;
	stdmath_radian4 xwxx;
	stdmath_radian4 xwxy;
	stdmath_radian4 xwxz;
	stdmath_radian4 xwxw;
	stdmath_radian4 xwyx;
	stdmath_radian4 xwyy;
	stdmath_radian4 xwyz;
	stdmath_radian4 xwyw;
	stdmath_radian4 xwzx;
	stdmath_radian4 xwzy;
	stdmath_radian4 xwzz;
	stdmath_radian4 xwzw;
	stdmath_radian4 xwwx;
	stdmath_radian4 xwwy;
	stdmath_radian4 xwwz;
	stdmath_radian4 xwww;
	stdmath_radian4 yxxx;
	stdmath_radian4 yxxy;
	stdmath_radian4 yxxz;
	stdmath_radian4 yxxw;
	stdmath_radian4 yxyx;
	stdmath_radian4 yxyy;
	stdmath_radian4 yxyz;
	stdmath_radian4 yxyw;
	stdmath_radian4 yxzx;
	stdmath_radian4 yxzy;
	stdmath_radian4 yxzz;
	stdmath_radian4 yxzw;
	stdmath_radian4 yxwx;
	stdmath_radian4 yxwy;
	stdmath_radian4 yxwz;
	stdmath_radian4 yxww;
	stdmath_radian4 yyxx;
	stdmath_radian4 yyxy;
	stdmath_radian4 yyxz;
	stdmath_radian4 yyxw;
	stdmath_radian4 yyyx;
	stdmath_radian4 yyyy;
	stdmath_radian4 yyyz;
	stdmath_radian4 yyyw;
	stdmath_radian4 yyzx;
	stdmath_radian4 yyzy;
	stdmath_radian4 yyzz;
	stdmath_radian4 yyzw;
	stdmath_radian4 yywx;
	stdmath_radian4 yywy;
	stdmath_radian4 yywz;
	stdmath_radian4 yyww;
	stdmath_radian4 yzxx;
	stdmath_radian4 yzxy;
	stdmath_radian4 yzxz;
	stdmath_radian4 yzxw;
	stdmath_radian4 yzyx;
	stdmath_radian4 yzyy;
	stdmath_radian4 yzyz;
	stdmath_radian4 yzyw;
	stdmath_radian4 yzzx;
	stdmath_radian4 yzzy;
	stdmath_radian4 yzzz;
	stdmath_radian4 yzzw;
	stdmath_radian4 yzwx;
	stdmath_radian4 yzwy;
	stdmath_radian4 yzwz;
	stdmath_radian4 yzww;
	stdmath_radian4 ywxx;
	stdmath_radian4 ywxy;
	stdmath_radian4 ywxz;
	stdmath_radian4 ywxw;
	stdmath_radian4 ywyx;
	stdmath_radian4 ywyy;
	stdmath_radian4 ywyz;
	stdmath_radian4 ywyw;
	stdmath_radian4 ywzx;
	stdmath_radian4 ywzy;
	stdmath_radian4 ywzz;
	stdmath_radian4 ywzw;
	stdmath_radian4 ywwx;
	stdmath_radian4 ywwy;
	stdmath_radian4 ywwz;
	stdmath_radian4 ywww;
	stdmath_radian4 zxxx;
	stdmath_radian4 zxxy;
	stdmath_radian4 zxxz;
	stdmath_radian4 zxxw;
	stdmath_radian4 zxyx;
	stdmath_radian4 zxyy;
	stdmath_radian4 zxyz;
	stdmath_radian4 zxyw;
	stdmath_radian4 zxzx;
	stdmath_radian4 zxzy;
	stdmath_radian4 zxzz;
	stdmath_radian4 zxzw;
	stdmath_radian4 zxwx;
	stdmath_radian4 zxwy;
	stdmath_radian4 zxwz;
	stdmath_radian4 zxww;
	stdmath_radian4 zyxx;
	stdmath_radian4 zyxy;
	stdmath_radian4 zyxz;
	stdmath_radian4 zyxw;
	stdmath_radian4 zyyx;
	stdmath_radian4 zyyy;
	stdmath_radian4 zyyz;
	stdmath_radian4 zyyw;
	stdmath_radian4 zyzx;
	stdmath_radian4 zyzy;
	stdmath_radian4 zyzz;
	stdmath_radian4 zyzw;
	stdmath_radian4 zywx;
	stdmath_radian4 zywy;
	stdmath_radian4 zywz;
	stdmath_radian4 zyww;
	stdmath_radian4 zzxx;
	stdmath_radian4 zzxy;
	stdmath_radian4 zzxz;
	stdmath_radian4 zzxw;
	stdmath_radian4 zzyx;
	stdmath_radian4 zzyy;
	stdmath_radian4 zzyz;
	stdmath_radian4 zzyw;
	stdmath_radian4 zzzx;
	stdmath_radian4 zzzy;
	stdmath_radian4 zzzz;
	stdmath_radian4 zzzw;
	stdmath_radian4 zzwx;
	stdmath_radian4 zzwy;
	stdmath_radian4 zzwz;
	stdmath_radian4 zzww;
	stdmath_radian4 zwxx;
	stdmath_radian4 zwxy;
	stdmath_radian4 zwxz;
	stdmath_radian4 zwxw;
	stdmath_radian4 zwyx;
	stdmath_radian4 zwyy;
	stdmath_radian4 zwyz;
	stdmath_radian4 zwyw;
	stdmath_radian4 zwzx;
	stdmath_radian4 zwzy;
	stdmath_radian4 zwzz;
	stdmath_radian4 zwzw;
	stdmath_radian4 zwwx;
	stdmath_radian4 zwwy;
	stdmath_radian4 zwwz;
	stdmath_radian4 zwww;
	stdmath_radian4 wxxx;
	stdmath_radian4 wxxy;
	stdmath_radian4 wxxz;
	stdmath_radian4 wxxw;
	stdmath_radian4 wxyx;
	stdmath_radian4 wxyy;
	stdmath_radian4 wxyz;
	stdmath_radian4 wxyw;
	stdmath_radian4 wxzx;
	stdmath_radian4 wxzy;
	stdmath_radian4 wxzz;
	stdmath_radian4 wxzw;
	stdmath_radian4 wxwx;
	stdmath_radian4 wxwy;
	stdmath_radian4 wxwz;
	stdmath_radian4 wxww;
	stdmath_radian4 wyxx;
	stdmath_radian4 wyxy;
	stdmath_radian4 wyxz;
	stdmath_radian4 wyxw;
	stdmath_radian4 wyyx;
	stdmath_radian4 wyyy;
	stdmath_radian4 wyyz;
	stdmath_radian4 wyyw;
	stdmath_radian4 wyzx;
	stdmath_radian4 wyzy;
	stdmath_radian4 wyzz;
	stdmath_radian4 wyzw;
	stdmath_radian4 wywx;
	stdmath_radian4 wywy;
	stdmath_radian4 wywz;
	stdmath_radian4 wyww;
	stdmath_radian4 wzxx;
	stdmath_radian4 wzxy;
	stdmath_radian4 wzxz;
	stdmath_radian4 wzxw;
	stdmath_radian4 wzyx;
	stdmath_radian4 wzyy;
	stdmath_radian4 wzyz;
	stdmath_radian4 wzyw;
	stdmath_radian4 wzzx;
	stdmath_radian4 wzzy;
	stdmath_radian4 wzzz;
	stdmath_radian4 wzzw;
	stdmath_radian4 wzwx;
	stdmath_radian4 wzwy;
	stdmath_radian4 wzwz;
	stdmath_radian4 wzww;
	stdmath_radian4 wwxx;
	stdmath_radian4 wwxy;
	stdmath_radian4 wwxz;
	stdmath_radian4 wwxw;
	stdmath_radian4 wwyx;
	stdmath_radian4 wwyy;
	stdmath_radian4 wwyz;
	stdmath_radian4 wwyw;
	stdmath_radian4 wwzx;
	stdmath_radian4 wwzy;
	stdmath_radian4 wwzz;
	stdmath_radian4 wwzw;
	stdmath_radian4 wwwx;
	stdmath_radian4 wwwy;
	stdmath_radian4 wwwz;
	stdmath_radian4 wwww;

#endif

	stdmath_radian4 _add(stdmath_radian4 o) {
		return stdmath_radian4_add(*self, o);
	}
	stdmath_radian4 _subtract(stdmath_radian4 o) {
		return stdmath_radian4_subtract(*self, o);
	}
	stdmath_radian4 _negate() {
		return stdmath_radian4_negate(*self);
	}
	stdmath_radian4 _multiply(stdmath_radian4 o) {
		return stdmath_radian4_multiply(*self, o);
	}
	stdmath_radian4 _divide(stdmath_radian4 o) {
		return stdmath_radian4_divide(*self, o);
	}
	stdmath_radian4 _scale(stdmath_radian o) {
		return stdmath_radian4_scale(*self, o);
	}

#if false
	stdmath_radian4 _modulus(stdmath_radian4 o) {
		return stdmath_radian4_modulus(*self, o);
	}
	stdmath_radian4 _logical_not() {
		return stdmath_radian4_logical_not(*self);
	}
	stdmath_radian4 _bitwise_not() {
		return stdmath_radian4_bitwise_not(*self);
	}
	stdmath_radian4 _logical_and(stdmath_radian4 o) {
		return stdmath_radian4_logical_and(*self, o);
	}
	stdmath_radian4 _bitwise_and(stdmath_radian4 o) {
		return stdmath_radian4_bitwise_and(*self, o);
	}
	stdmath_radian4 _logical_or(stdmath_radian4 o) {
		return stdmath_radian4_logical_or(*self, o);
	}
	stdmath_radian4 _bitwise_or(stdmath_radian4 o) {
		return stdmath_radian4_bitwise_or(*self, o);
	}
	stdmath_radian4 _bitwise_xor(stdmath_radian4 o) {
		return stdmath_radian4_bitwise_xor(*self, o);
	}
	stdmath_radian4 _shift_left(stdmath_radian4 o) {
		return stdmath_radian4_shift_left(*self, o);
	}
	stdmath_radian4 _shift_right(stdmath_radian4 o) {
		return stdmath_radian4_shift_right(*self, o);
	}
#endif

	stdmath_bool4 _equal_to(stdmath_radian4 o) {
		return stdmath_radian4_equal_to(*self, o);
	}
	stdmath_bool4 _not_equal_to(stdmath_radian4 o) {
		return stdmath_radian4_not_equal_to(*self, o);
	}
	stdmath_bool4 _less_than(stdmath_radian4 o) {
		return stdmath_radian4_less_than(*self, o);
	}
	stdmath_bool4 _less_than_or_equal_to(stdmath_radian4 o) {
		return stdmath_radian4_less_than_or_equal_to(*self, o);
	}
	stdmath_bool4 _greater_than(stdmath_radian4 o) {
		return stdmath_radian4_greater_than(*self, o);
	}
	stdmath_bool4 _greater_than_or_equal_to(stdmath_radian4 o) {
		return stdmath_radian4_greater_than_or_equal_to(*self, o);
	}

	stdmath_radian _length_squared() {
		return stdmath_radian4_length_squared(*self);
	}
	stdmath_radian _length() {
		return stdmath_radian4_length(*self);
	}
	stdmath_radian _dot(stdmath_radian4 o) {
		return stdmath_radian4_dot(*self, o);
	}
	stdmath_radian _min_element() {
		return stdmath_radian4_min_element(*self);
	}
	stdmath_radian _max_element() {
		return stdmath_radian4_max_element(*self);
	}

	// stdmath_radian elementwise_transform()
	// stdmath_radian reduce_element

	stdmath_radian4 _min(stdmath_radian4 o) {
		return stdmath_radian4_min(*self, o);
	}
	stdmath_radian4 _max(stdmath_radian4 o) {
		return stdmath_radian4_max(*self, o);
	}
	stdmath_radian4 _normalize() {
		return stdmath_radian4_normalize(*self);
	}
	stdmath_radian4 _lerp(stdmath_radian4 o, float t) {
		return stdmath_radian4_lerp(*self, o, t);
	}
	stdmath_radian4 _clamp(stdmath_radian4 min, stdmath_radian4 max) {
		return stdmath_radian4_clamp(*self, min, max);
	}
	stdmath_radian4 _reflect(stdmath_radian4 n) {
		return stdmath_radian4_reflect(*self, n);
	}
	stdmath_bool4 _approximately_equal(stdmath_radian4 o) {
		return stdmath_radian4_approximately_equal(*self, o);
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

	stdmath_radian _get_element(size_t i) {
		return self->data[i];
	}

	stdmath_radian _set_element(size_t i, stdmath_radian value) {
		return self->data[i] = value;
	}
}