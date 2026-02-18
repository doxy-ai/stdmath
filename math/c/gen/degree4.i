#define STDMATH_EXPORT
#define STDMATH_INLINE
%rename(degree4) stdmath_degree4;
%include "degree4.h"

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

%extend stdmath_degree4 {
	stdmath_degree4(stdmath_degree broadcast) {
		stdmath_degree4 *v;
		v = (stdmath_degree4 *) malloc(sizeof(stdmath_degree4));
		*v = stdmath_degree4_broadcast(broadcast);
		return v;
	}

#if 4 == 4
	stdmath_degree4(stdmath_degree x = 0, stdmath_degree y = 0, stdmath_degree z = 0, stdmath_degree w = 0) {
		stdmath_degree4 *v;
		v = (stdmath_degree4 *) malloc(sizeof(stdmath_degree4));
		v->x = x;
		v->y = y;
		v->z = z;
		v->w = w;
		return v;
	}
#elif 4 == 3
	stdmath_degree4(stdmath_degree x = 0, stdmath_degree y = 0, stdmath_degree z = 0) {
		stdmath_degree4 *v;
		v = (stdmath_degree4 *) malloc(sizeof(stdmath_degree4));
		v->x = x;
		v->y = y;
		v->z = z;
		return v;
	}
#elif 4 == 2
	stdmath_degree4(stdmath_degree x = 0, stdmath_degree y = 0) {
		stdmath_degree4 *v;
		v = (stdmath_degree4 *) malloc(sizeof(stdmath_degree4));
		v->x = x;
		v->y = y;
		return v;
	}
#elif 4 == 1
	stdmath_degree4(stdmath_degree x = 0) {
		stdmath_degree4 *v;
		v = (stdmath_degree4 *) malloc(sizeof(stdmath_degree4));
		v->x = x;
		return v;
	}
#endif

#ifndef STDMATH_NO_SWIZZLES
	stdmath_degree2 xx;
	stdmath_degree2 xy;
	stdmath_degree2 xz;
	stdmath_degree2 xw;
	stdmath_degree2 yx;
	stdmath_degree2 yy;
	stdmath_degree2 yz;
	stdmath_degree2 yw;
	stdmath_degree2 zx;
	stdmath_degree2 zy;
	stdmath_degree2 zz;
	stdmath_degree2 zw;
	stdmath_degree2 wx;
	stdmath_degree2 wy;
	stdmath_degree2 wz;
	stdmath_degree2 ww;
	stdmath_degree3 xxx;
	stdmath_degree3 xxy;
	stdmath_degree3 xxz;
	stdmath_degree3 xxw;
	stdmath_degree3 xyx;
	stdmath_degree3 xyy;
	stdmath_degree3 xyz;
	stdmath_degree3 xyw;
	stdmath_degree3 xzx;
	stdmath_degree3 xzy;
	stdmath_degree3 xzz;
	stdmath_degree3 xzw;
	stdmath_degree3 xwx;
	stdmath_degree3 xwy;
	stdmath_degree3 xwz;
	stdmath_degree3 xww;
	stdmath_degree3 yxx;
	stdmath_degree3 yxy;
	stdmath_degree3 yxz;
	stdmath_degree3 yxw;
	stdmath_degree3 yyx;
	stdmath_degree3 yyy;
	stdmath_degree3 yyz;
	stdmath_degree3 yyw;
	stdmath_degree3 yzx;
	stdmath_degree3 yzy;
	stdmath_degree3 yzz;
	stdmath_degree3 yzw;
	stdmath_degree3 ywx;
	stdmath_degree3 ywy;
	stdmath_degree3 ywz;
	stdmath_degree3 yww;
	stdmath_degree3 zxx;
	stdmath_degree3 zxy;
	stdmath_degree3 zxz;
	stdmath_degree3 zxw;
	stdmath_degree3 zyx;
	stdmath_degree3 zyy;
	stdmath_degree3 zyz;
	stdmath_degree3 zyw;
	stdmath_degree3 zzx;
	stdmath_degree3 zzy;
	stdmath_degree3 zzz;
	stdmath_degree3 zzw;
	stdmath_degree3 zwx;
	stdmath_degree3 zwy;
	stdmath_degree3 zwz;
	stdmath_degree3 zww;
	stdmath_degree3 wxx;
	stdmath_degree3 wxy;
	stdmath_degree3 wxz;
	stdmath_degree3 wxw;
	stdmath_degree3 wyx;
	stdmath_degree3 wyy;
	stdmath_degree3 wyz;
	stdmath_degree3 wyw;
	stdmath_degree3 wzx;
	stdmath_degree3 wzy;
	stdmath_degree3 wzz;
	stdmath_degree3 wzw;
	stdmath_degree3 wwx;
	stdmath_degree3 wwy;
	stdmath_degree3 wwz;
	stdmath_degree3 www;
	stdmath_degree4 xxxx;
	stdmath_degree4 xxxy;
	stdmath_degree4 xxxz;
	stdmath_degree4 xxxw;
	stdmath_degree4 xxyx;
	stdmath_degree4 xxyy;
	stdmath_degree4 xxyz;
	stdmath_degree4 xxyw;
	stdmath_degree4 xxzx;
	stdmath_degree4 xxzy;
	stdmath_degree4 xxzz;
	stdmath_degree4 xxzw;
	stdmath_degree4 xxwx;
	stdmath_degree4 xxwy;
	stdmath_degree4 xxwz;
	stdmath_degree4 xxww;
	stdmath_degree4 xyxx;
	stdmath_degree4 xyxy;
	stdmath_degree4 xyxz;
	stdmath_degree4 xyxw;
	stdmath_degree4 xyyx;
	stdmath_degree4 xyyy;
	stdmath_degree4 xyyz;
	stdmath_degree4 xyyw;
	stdmath_degree4 xyzx;
	stdmath_degree4 xyzy;
	stdmath_degree4 xyzz;
	stdmath_degree4 xyzw;
	stdmath_degree4 xywx;
	stdmath_degree4 xywy;
	stdmath_degree4 xywz;
	stdmath_degree4 xyww;
	stdmath_degree4 xzxx;
	stdmath_degree4 xzxy;
	stdmath_degree4 xzxz;
	stdmath_degree4 xzxw;
	stdmath_degree4 xzyx;
	stdmath_degree4 xzyy;
	stdmath_degree4 xzyz;
	stdmath_degree4 xzyw;
	stdmath_degree4 xzzx;
	stdmath_degree4 xzzy;
	stdmath_degree4 xzzz;
	stdmath_degree4 xzzw;
	stdmath_degree4 xzwx;
	stdmath_degree4 xzwy;
	stdmath_degree4 xzwz;
	stdmath_degree4 xzww;
	stdmath_degree4 xwxx;
	stdmath_degree4 xwxy;
	stdmath_degree4 xwxz;
	stdmath_degree4 xwxw;
	stdmath_degree4 xwyx;
	stdmath_degree4 xwyy;
	stdmath_degree4 xwyz;
	stdmath_degree4 xwyw;
	stdmath_degree4 xwzx;
	stdmath_degree4 xwzy;
	stdmath_degree4 xwzz;
	stdmath_degree4 xwzw;
	stdmath_degree4 xwwx;
	stdmath_degree4 xwwy;
	stdmath_degree4 xwwz;
	stdmath_degree4 xwww;
	stdmath_degree4 yxxx;
	stdmath_degree4 yxxy;
	stdmath_degree4 yxxz;
	stdmath_degree4 yxxw;
	stdmath_degree4 yxyx;
	stdmath_degree4 yxyy;
	stdmath_degree4 yxyz;
	stdmath_degree4 yxyw;
	stdmath_degree4 yxzx;
	stdmath_degree4 yxzy;
	stdmath_degree4 yxzz;
	stdmath_degree4 yxzw;
	stdmath_degree4 yxwx;
	stdmath_degree4 yxwy;
	stdmath_degree4 yxwz;
	stdmath_degree4 yxww;
	stdmath_degree4 yyxx;
	stdmath_degree4 yyxy;
	stdmath_degree4 yyxz;
	stdmath_degree4 yyxw;
	stdmath_degree4 yyyx;
	stdmath_degree4 yyyy;
	stdmath_degree4 yyyz;
	stdmath_degree4 yyyw;
	stdmath_degree4 yyzx;
	stdmath_degree4 yyzy;
	stdmath_degree4 yyzz;
	stdmath_degree4 yyzw;
	stdmath_degree4 yywx;
	stdmath_degree4 yywy;
	stdmath_degree4 yywz;
	stdmath_degree4 yyww;
	stdmath_degree4 yzxx;
	stdmath_degree4 yzxy;
	stdmath_degree4 yzxz;
	stdmath_degree4 yzxw;
	stdmath_degree4 yzyx;
	stdmath_degree4 yzyy;
	stdmath_degree4 yzyz;
	stdmath_degree4 yzyw;
	stdmath_degree4 yzzx;
	stdmath_degree4 yzzy;
	stdmath_degree4 yzzz;
	stdmath_degree4 yzzw;
	stdmath_degree4 yzwx;
	stdmath_degree4 yzwy;
	stdmath_degree4 yzwz;
	stdmath_degree4 yzww;
	stdmath_degree4 ywxx;
	stdmath_degree4 ywxy;
	stdmath_degree4 ywxz;
	stdmath_degree4 ywxw;
	stdmath_degree4 ywyx;
	stdmath_degree4 ywyy;
	stdmath_degree4 ywyz;
	stdmath_degree4 ywyw;
	stdmath_degree4 ywzx;
	stdmath_degree4 ywzy;
	stdmath_degree4 ywzz;
	stdmath_degree4 ywzw;
	stdmath_degree4 ywwx;
	stdmath_degree4 ywwy;
	stdmath_degree4 ywwz;
	stdmath_degree4 ywww;
	stdmath_degree4 zxxx;
	stdmath_degree4 zxxy;
	stdmath_degree4 zxxz;
	stdmath_degree4 zxxw;
	stdmath_degree4 zxyx;
	stdmath_degree4 zxyy;
	stdmath_degree4 zxyz;
	stdmath_degree4 zxyw;
	stdmath_degree4 zxzx;
	stdmath_degree4 zxzy;
	stdmath_degree4 zxzz;
	stdmath_degree4 zxzw;
	stdmath_degree4 zxwx;
	stdmath_degree4 zxwy;
	stdmath_degree4 zxwz;
	stdmath_degree4 zxww;
	stdmath_degree4 zyxx;
	stdmath_degree4 zyxy;
	stdmath_degree4 zyxz;
	stdmath_degree4 zyxw;
	stdmath_degree4 zyyx;
	stdmath_degree4 zyyy;
	stdmath_degree4 zyyz;
	stdmath_degree4 zyyw;
	stdmath_degree4 zyzx;
	stdmath_degree4 zyzy;
	stdmath_degree4 zyzz;
	stdmath_degree4 zyzw;
	stdmath_degree4 zywx;
	stdmath_degree4 zywy;
	stdmath_degree4 zywz;
	stdmath_degree4 zyww;
	stdmath_degree4 zzxx;
	stdmath_degree4 zzxy;
	stdmath_degree4 zzxz;
	stdmath_degree4 zzxw;
	stdmath_degree4 zzyx;
	stdmath_degree4 zzyy;
	stdmath_degree4 zzyz;
	stdmath_degree4 zzyw;
	stdmath_degree4 zzzx;
	stdmath_degree4 zzzy;
	stdmath_degree4 zzzz;
	stdmath_degree4 zzzw;
	stdmath_degree4 zzwx;
	stdmath_degree4 zzwy;
	stdmath_degree4 zzwz;
	stdmath_degree4 zzww;
	stdmath_degree4 zwxx;
	stdmath_degree4 zwxy;
	stdmath_degree4 zwxz;
	stdmath_degree4 zwxw;
	stdmath_degree4 zwyx;
	stdmath_degree4 zwyy;
	stdmath_degree4 zwyz;
	stdmath_degree4 zwyw;
	stdmath_degree4 zwzx;
	stdmath_degree4 zwzy;
	stdmath_degree4 zwzz;
	stdmath_degree4 zwzw;
	stdmath_degree4 zwwx;
	stdmath_degree4 zwwy;
	stdmath_degree4 zwwz;
	stdmath_degree4 zwww;
	stdmath_degree4 wxxx;
	stdmath_degree4 wxxy;
	stdmath_degree4 wxxz;
	stdmath_degree4 wxxw;
	stdmath_degree4 wxyx;
	stdmath_degree4 wxyy;
	stdmath_degree4 wxyz;
	stdmath_degree4 wxyw;
	stdmath_degree4 wxzx;
	stdmath_degree4 wxzy;
	stdmath_degree4 wxzz;
	stdmath_degree4 wxzw;
	stdmath_degree4 wxwx;
	stdmath_degree4 wxwy;
	stdmath_degree4 wxwz;
	stdmath_degree4 wxww;
	stdmath_degree4 wyxx;
	stdmath_degree4 wyxy;
	stdmath_degree4 wyxz;
	stdmath_degree4 wyxw;
	stdmath_degree4 wyyx;
	stdmath_degree4 wyyy;
	stdmath_degree4 wyyz;
	stdmath_degree4 wyyw;
	stdmath_degree4 wyzx;
	stdmath_degree4 wyzy;
	stdmath_degree4 wyzz;
	stdmath_degree4 wyzw;
	stdmath_degree4 wywx;
	stdmath_degree4 wywy;
	stdmath_degree4 wywz;
	stdmath_degree4 wyww;
	stdmath_degree4 wzxx;
	stdmath_degree4 wzxy;
	stdmath_degree4 wzxz;
	stdmath_degree4 wzxw;
	stdmath_degree4 wzyx;
	stdmath_degree4 wzyy;
	stdmath_degree4 wzyz;
	stdmath_degree4 wzyw;
	stdmath_degree4 wzzx;
	stdmath_degree4 wzzy;
	stdmath_degree4 wzzz;
	stdmath_degree4 wzzw;
	stdmath_degree4 wzwx;
	stdmath_degree4 wzwy;
	stdmath_degree4 wzwz;
	stdmath_degree4 wzww;
	stdmath_degree4 wwxx;
	stdmath_degree4 wwxy;
	stdmath_degree4 wwxz;
	stdmath_degree4 wwxw;
	stdmath_degree4 wwyx;
	stdmath_degree4 wwyy;
	stdmath_degree4 wwyz;
	stdmath_degree4 wwyw;
	stdmath_degree4 wwzx;
	stdmath_degree4 wwzy;
	stdmath_degree4 wwzz;
	stdmath_degree4 wwzw;
	stdmath_degree4 wwwx;
	stdmath_degree4 wwwy;
	stdmath_degree4 wwwz;
	stdmath_degree4 wwww;

#endif

	stdmath_degree4 _add(stdmath_degree4 o) {
		return stdmath_degree4_add(*self, o);
	}
	stdmath_degree4 _subtract(stdmath_degree4 o) {
		return stdmath_degree4_subtract(*self, o);
	}
	stdmath_degree4 _negate() {
		return stdmath_degree4_negate(*self);
	}
	stdmath_degree4 _multiply(stdmath_degree4 o) {
		return stdmath_degree4_multiply(*self, o);
	}
	stdmath_degree4 _divide(stdmath_degree4 o) {
		return stdmath_degree4_divide(*self, o);
	}
	stdmath_degree4 _scale(stdmath_degree o) {
		return stdmath_degree4_scale(*self, o);
	}

#if false
	stdmath_degree4 _modulus(stdmath_degree4 o) {
		return stdmath_degree4_modulus(*self, o);
	}
	stdmath_degree4 _logical_not() {
		return stdmath_degree4_logical_not(*self);
	}
	stdmath_degree4 _bitwise_not() {
		return stdmath_degree4_bitwise_not(*self);
	}
	stdmath_degree4 _logical_and(stdmath_degree4 o) {
		return stdmath_degree4_logical_and(*self, o);
	}
	stdmath_degree4 _bitwise_and(stdmath_degree4 o) {
		return stdmath_degree4_bitwise_and(*self, o);
	}
	stdmath_degree4 _logical_or(stdmath_degree4 o) {
		return stdmath_degree4_logical_or(*self, o);
	}
	stdmath_degree4 _bitwise_or(stdmath_degree4 o) {
		return stdmath_degree4_bitwise_or(*self, o);
	}
	stdmath_degree4 _bitwise_xor(stdmath_degree4 o) {
		return stdmath_degree4_bitwise_xor(*self, o);
	}
	stdmath_degree4 _shift_left(stdmath_degree4 o) {
		return stdmath_degree4_shift_left(*self, o);
	}
	stdmath_degree4 _shift_right(stdmath_degree4 o) {
		return stdmath_degree4_shift_right(*self, o);
	}
#endif

	stdmath_bool4 _equal_to(stdmath_degree4 o) {
		return stdmath_degree4_equal_to(*self, o);
	}
	stdmath_bool4 _not_equal_to(stdmath_degree4 o) {
		return stdmath_degree4_not_equal_to(*self, o);
	}
	stdmath_bool4 _less_than(stdmath_degree4 o) {
		return stdmath_degree4_less_than(*self, o);
	}
	stdmath_bool4 _less_than_or_equal_to(stdmath_degree4 o) {
		return stdmath_degree4_less_than_or_equal_to(*self, o);
	}
	stdmath_bool4 _greater_than(stdmath_degree4 o) {
		return stdmath_degree4_greater_than(*self, o);
	}
	stdmath_bool4 _greater_than_or_equal_to(stdmath_degree4 o) {
		return stdmath_degree4_greater_than_or_equal_to(*self, o);
	}

	stdmath_degree _length_squared() {
		return stdmath_degree4_length_squared(*self);
	}
	stdmath_degree _length() {
		return stdmath_degree4_length(*self);
	}
	stdmath_degree _dot(stdmath_degree4 o) {
		return stdmath_degree4_dot(*self, o);
	}
	stdmath_degree _min_element() {
		return stdmath_degree4_min_element(*self);
	}
	stdmath_degree _max_element() {
		return stdmath_degree4_max_element(*self);
	}

	// stdmath_degree elementwise_transform()
	// stdmath_degree reduce_element

	stdmath_degree4 _min(stdmath_degree4 o) {
		return stdmath_degree4_min(*self, o);
	}
	stdmath_degree4 _max(stdmath_degree4 o) {
		return stdmath_degree4_max(*self, o);
	}
	stdmath_degree4 _normalize() {
		return stdmath_degree4_normalize(*self);
	}
	stdmath_degree4 _lerp(stdmath_degree4 o, float t) {
		return stdmath_degree4_lerp(*self, o, t);
	}
	stdmath_degree4 _clamp(stdmath_degree4 min, stdmath_degree4 max) {
		return stdmath_degree4_clamp(*self, min, max);
	}
	stdmath_degree4 _reflect(stdmath_degree4 n) {
		return stdmath_degree4_reflect(*self, n);
	}
	stdmath_bool4 _approximately_equal(stdmath_degree4 o) {
		return stdmath_degree4_approximately_equal(*self, o);
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

	stdmath_degree _get_element(size_t i) {
		return self->data[i];
	}

	stdmath_degree _set_element(size_t i, stdmath_degree value) {
		return self->data[i] = value;
	}
}