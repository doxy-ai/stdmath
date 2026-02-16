%rename(bool4) stdmath_bool4;
%include "bool4.h"

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

%extend stdmath_bool4 {
	stdmath_bool4(bool broadcast) {
		stdmath_bool4 *v;
		v = (stdmath_bool4 *) malloc(sizeof(stdmath_bool4));
		*v = stdmath_bool4_broadcast(broadcast);
		return v;
	}

#if 4 == 4
	stdmath_bool4(bool x = 0, bool y = 0, bool z = 0, bool w = 0) {
		stdmath_bool4 *v;
		v = (stdmath_bool4 *) malloc(sizeof(stdmath_bool4));
		v->x = x;
		v->y = y;
		v->z = z;
		v->w = w;
		return v;
	}
#elif 4 == 3
	stdmath_bool4(bool x = 0, bool y = 0, bool z = 0) {
		stdmath_bool4 *v;
		v = (stdmath_bool4 *) malloc(sizeof(stdmath_bool4));
		v->x = x;
		v->y = y;
		v->z = z;
		return v;
	}
#elif 4 == 2
	stdmath_bool4(bool x = 0, bool y = 0) {
		stdmath_bool4 *v;
		v = (stdmath_bool4 *) malloc(sizeof(stdmath_bool4));
		v->x = x;
		v->y = y;
		return v;
	}
#elif 4 == 1
	stdmath_bool4(bool x = 0) {
		stdmath_bool4 *v;
		v = (stdmath_bool4 *) malloc(sizeof(stdmath_bool4));
		v->x = x;
		return v;
	}
#endif

	stdmath_bool2 xx;
	stdmath_bool2 xy;
	stdmath_bool2 xz;
	stdmath_bool2 xw;
	stdmath_bool2 yx;
	stdmath_bool2 yy;
	stdmath_bool2 yz;
	stdmath_bool2 yw;
	stdmath_bool2 zx;
	stdmath_bool2 zy;
	stdmath_bool2 zz;
	stdmath_bool2 zw;
	stdmath_bool2 wx;
	stdmath_bool2 wy;
	stdmath_bool2 wz;
	stdmath_bool2 ww;
	stdmath_bool3 xxx;
	stdmath_bool3 xxy;
	stdmath_bool3 xxz;
	stdmath_bool3 xxw;
	stdmath_bool3 xyx;
	stdmath_bool3 xyy;
	stdmath_bool3 xyz;
	stdmath_bool3 xyw;
	stdmath_bool3 xzx;
	stdmath_bool3 xzy;
	stdmath_bool3 xzz;
	stdmath_bool3 xzw;
	stdmath_bool3 xwx;
	stdmath_bool3 xwy;
	stdmath_bool3 xwz;
	stdmath_bool3 xww;
	stdmath_bool3 yxx;
	stdmath_bool3 yxy;
	stdmath_bool3 yxz;
	stdmath_bool3 yxw;
	stdmath_bool3 yyx;
	stdmath_bool3 yyy;
	stdmath_bool3 yyz;
	stdmath_bool3 yyw;
	stdmath_bool3 yzx;
	stdmath_bool3 yzy;
	stdmath_bool3 yzz;
	stdmath_bool3 yzw;
	stdmath_bool3 ywx;
	stdmath_bool3 ywy;
	stdmath_bool3 ywz;
	stdmath_bool3 yww;
	stdmath_bool3 zxx;
	stdmath_bool3 zxy;
	stdmath_bool3 zxz;
	stdmath_bool3 zxw;
	stdmath_bool3 zyx;
	stdmath_bool3 zyy;
	stdmath_bool3 zyz;
	stdmath_bool3 zyw;
	stdmath_bool3 zzx;
	stdmath_bool3 zzy;
	stdmath_bool3 zzz;
	stdmath_bool3 zzw;
	stdmath_bool3 zwx;
	stdmath_bool3 zwy;
	stdmath_bool3 zwz;
	stdmath_bool3 zww;
	stdmath_bool3 wxx;
	stdmath_bool3 wxy;
	stdmath_bool3 wxz;
	stdmath_bool3 wxw;
	stdmath_bool3 wyx;
	stdmath_bool3 wyy;
	stdmath_bool3 wyz;
	stdmath_bool3 wyw;
	stdmath_bool3 wzx;
	stdmath_bool3 wzy;
	stdmath_bool3 wzz;
	stdmath_bool3 wzw;
	stdmath_bool3 wwx;
	stdmath_bool3 wwy;
	stdmath_bool3 wwz;
	stdmath_bool3 www;
	stdmath_bool4 xxxx;
	stdmath_bool4 xxxy;
	stdmath_bool4 xxxz;
	stdmath_bool4 xxxw;
	stdmath_bool4 xxyx;
	stdmath_bool4 xxyy;
	stdmath_bool4 xxyz;
	stdmath_bool4 xxyw;
	stdmath_bool4 xxzx;
	stdmath_bool4 xxzy;
	stdmath_bool4 xxzz;
	stdmath_bool4 xxzw;
	stdmath_bool4 xxwx;
	stdmath_bool4 xxwy;
	stdmath_bool4 xxwz;
	stdmath_bool4 xxww;
	stdmath_bool4 xyxx;
	stdmath_bool4 xyxy;
	stdmath_bool4 xyxz;
	stdmath_bool4 xyxw;
	stdmath_bool4 xyyx;
	stdmath_bool4 xyyy;
	stdmath_bool4 xyyz;
	stdmath_bool4 xyyw;
	stdmath_bool4 xyzx;
	stdmath_bool4 xyzy;
	stdmath_bool4 xyzz;
	stdmath_bool4 xyzw;
	stdmath_bool4 xywx;
	stdmath_bool4 xywy;
	stdmath_bool4 xywz;
	stdmath_bool4 xyww;
	stdmath_bool4 xzxx;
	stdmath_bool4 xzxy;
	stdmath_bool4 xzxz;
	stdmath_bool4 xzxw;
	stdmath_bool4 xzyx;
	stdmath_bool4 xzyy;
	stdmath_bool4 xzyz;
	stdmath_bool4 xzyw;
	stdmath_bool4 xzzx;
	stdmath_bool4 xzzy;
	stdmath_bool4 xzzz;
	stdmath_bool4 xzzw;
	stdmath_bool4 xzwx;
	stdmath_bool4 xzwy;
	stdmath_bool4 xzwz;
	stdmath_bool4 xzww;
	stdmath_bool4 xwxx;
	stdmath_bool4 xwxy;
	stdmath_bool4 xwxz;
	stdmath_bool4 xwxw;
	stdmath_bool4 xwyx;
	stdmath_bool4 xwyy;
	stdmath_bool4 xwyz;
	stdmath_bool4 xwyw;
	stdmath_bool4 xwzx;
	stdmath_bool4 xwzy;
	stdmath_bool4 xwzz;
	stdmath_bool4 xwzw;
	stdmath_bool4 xwwx;
	stdmath_bool4 xwwy;
	stdmath_bool4 xwwz;
	stdmath_bool4 xwww;
	stdmath_bool4 yxxx;
	stdmath_bool4 yxxy;
	stdmath_bool4 yxxz;
	stdmath_bool4 yxxw;
	stdmath_bool4 yxyx;
	stdmath_bool4 yxyy;
	stdmath_bool4 yxyz;
	stdmath_bool4 yxyw;
	stdmath_bool4 yxzx;
	stdmath_bool4 yxzy;
	stdmath_bool4 yxzz;
	stdmath_bool4 yxzw;
	stdmath_bool4 yxwx;
	stdmath_bool4 yxwy;
	stdmath_bool4 yxwz;
	stdmath_bool4 yxww;
	stdmath_bool4 yyxx;
	stdmath_bool4 yyxy;
	stdmath_bool4 yyxz;
	stdmath_bool4 yyxw;
	stdmath_bool4 yyyx;
	stdmath_bool4 yyyy;
	stdmath_bool4 yyyz;
	stdmath_bool4 yyyw;
	stdmath_bool4 yyzx;
	stdmath_bool4 yyzy;
	stdmath_bool4 yyzz;
	stdmath_bool4 yyzw;
	stdmath_bool4 yywx;
	stdmath_bool4 yywy;
	stdmath_bool4 yywz;
	stdmath_bool4 yyww;
	stdmath_bool4 yzxx;
	stdmath_bool4 yzxy;
	stdmath_bool4 yzxz;
	stdmath_bool4 yzxw;
	stdmath_bool4 yzyx;
	stdmath_bool4 yzyy;
	stdmath_bool4 yzyz;
	stdmath_bool4 yzyw;
	stdmath_bool4 yzzx;
	stdmath_bool4 yzzy;
	stdmath_bool4 yzzz;
	stdmath_bool4 yzzw;
	stdmath_bool4 yzwx;
	stdmath_bool4 yzwy;
	stdmath_bool4 yzwz;
	stdmath_bool4 yzww;
	stdmath_bool4 ywxx;
	stdmath_bool4 ywxy;
	stdmath_bool4 ywxz;
	stdmath_bool4 ywxw;
	stdmath_bool4 ywyx;
	stdmath_bool4 ywyy;
	stdmath_bool4 ywyz;
	stdmath_bool4 ywyw;
	stdmath_bool4 ywzx;
	stdmath_bool4 ywzy;
	stdmath_bool4 ywzz;
	stdmath_bool4 ywzw;
	stdmath_bool4 ywwx;
	stdmath_bool4 ywwy;
	stdmath_bool4 ywwz;
	stdmath_bool4 ywww;
	stdmath_bool4 zxxx;
	stdmath_bool4 zxxy;
	stdmath_bool4 zxxz;
	stdmath_bool4 zxxw;
	stdmath_bool4 zxyx;
	stdmath_bool4 zxyy;
	stdmath_bool4 zxyz;
	stdmath_bool4 zxyw;
	stdmath_bool4 zxzx;
	stdmath_bool4 zxzy;
	stdmath_bool4 zxzz;
	stdmath_bool4 zxzw;
	stdmath_bool4 zxwx;
	stdmath_bool4 zxwy;
	stdmath_bool4 zxwz;
	stdmath_bool4 zxww;
	stdmath_bool4 zyxx;
	stdmath_bool4 zyxy;
	stdmath_bool4 zyxz;
	stdmath_bool4 zyxw;
	stdmath_bool4 zyyx;
	stdmath_bool4 zyyy;
	stdmath_bool4 zyyz;
	stdmath_bool4 zyyw;
	stdmath_bool4 zyzx;
	stdmath_bool4 zyzy;
	stdmath_bool4 zyzz;
	stdmath_bool4 zyzw;
	stdmath_bool4 zywx;
	stdmath_bool4 zywy;
	stdmath_bool4 zywz;
	stdmath_bool4 zyww;
	stdmath_bool4 zzxx;
	stdmath_bool4 zzxy;
	stdmath_bool4 zzxz;
	stdmath_bool4 zzxw;
	stdmath_bool4 zzyx;
	stdmath_bool4 zzyy;
	stdmath_bool4 zzyz;
	stdmath_bool4 zzyw;
	stdmath_bool4 zzzx;
	stdmath_bool4 zzzy;
	stdmath_bool4 zzzz;
	stdmath_bool4 zzzw;
	stdmath_bool4 zzwx;
	stdmath_bool4 zzwy;
	stdmath_bool4 zzwz;
	stdmath_bool4 zzww;
	stdmath_bool4 zwxx;
	stdmath_bool4 zwxy;
	stdmath_bool4 zwxz;
	stdmath_bool4 zwxw;
	stdmath_bool4 zwyx;
	stdmath_bool4 zwyy;
	stdmath_bool4 zwyz;
	stdmath_bool4 zwyw;
	stdmath_bool4 zwzx;
	stdmath_bool4 zwzy;
	stdmath_bool4 zwzz;
	stdmath_bool4 zwzw;
	stdmath_bool4 zwwx;
	stdmath_bool4 zwwy;
	stdmath_bool4 zwwz;
	stdmath_bool4 zwww;
	stdmath_bool4 wxxx;
	stdmath_bool4 wxxy;
	stdmath_bool4 wxxz;
	stdmath_bool4 wxxw;
	stdmath_bool4 wxyx;
	stdmath_bool4 wxyy;
	stdmath_bool4 wxyz;
	stdmath_bool4 wxyw;
	stdmath_bool4 wxzx;
	stdmath_bool4 wxzy;
	stdmath_bool4 wxzz;
	stdmath_bool4 wxzw;
	stdmath_bool4 wxwx;
	stdmath_bool4 wxwy;
	stdmath_bool4 wxwz;
	stdmath_bool4 wxww;
	stdmath_bool4 wyxx;
	stdmath_bool4 wyxy;
	stdmath_bool4 wyxz;
	stdmath_bool4 wyxw;
	stdmath_bool4 wyyx;
	stdmath_bool4 wyyy;
	stdmath_bool4 wyyz;
	stdmath_bool4 wyyw;
	stdmath_bool4 wyzx;
	stdmath_bool4 wyzy;
	stdmath_bool4 wyzz;
	stdmath_bool4 wyzw;
	stdmath_bool4 wywx;
	stdmath_bool4 wywy;
	stdmath_bool4 wywz;
	stdmath_bool4 wyww;
	stdmath_bool4 wzxx;
	stdmath_bool4 wzxy;
	stdmath_bool4 wzxz;
	stdmath_bool4 wzxw;
	stdmath_bool4 wzyx;
	stdmath_bool4 wzyy;
	stdmath_bool4 wzyz;
	stdmath_bool4 wzyw;
	stdmath_bool4 wzzx;
	stdmath_bool4 wzzy;
	stdmath_bool4 wzzz;
	stdmath_bool4 wzzw;
	stdmath_bool4 wzwx;
	stdmath_bool4 wzwy;
	stdmath_bool4 wzwz;
	stdmath_bool4 wzww;
	stdmath_bool4 wwxx;
	stdmath_bool4 wwxy;
	stdmath_bool4 wwxz;
	stdmath_bool4 wwxw;
	stdmath_bool4 wwyx;
	stdmath_bool4 wwyy;
	stdmath_bool4 wwyz;
	stdmath_bool4 wwyw;
	stdmath_bool4 wwzx;
	stdmath_bool4 wwzy;
	stdmath_bool4 wwzz;
	stdmath_bool4 wwzw;
	stdmath_bool4 wwwx;
	stdmath_bool4 wwwy;
	stdmath_bool4 wwwz;
	stdmath_bool4 wwww;


	stdmath_bool4 _add(stdmath_bool4 o) {
		return stdmath_bool4_add(*self, o);
	}
	stdmath_bool4 _subtract(stdmath_bool4 o) {
		return stdmath_bool4_subtract(*self, o);
	}
	stdmath_bool4 _negate() {
		return stdmath_bool4_negate(*self);
	}
	stdmath_bool4 _multiply(stdmath_bool4 o) {
		return stdmath_bool4_multiply(*self, o);
	}
	stdmath_bool4 _divide(stdmath_bool4 o) {
		return stdmath_bool4_divide(*self, o);
	}
	stdmath_bool4 _scale(bool o) {
		return stdmath_bool4_scale(*self, o);
	}

#if false
	stdmath_bool4 _modulus(stdmath_bool4 o) {
		return stdmath_bool4_modulus(*self, o);
	}
	stdmath_bool4 _logical_not() {
		return stdmath_bool4_logical_not(*self);
	}
	stdmath_bool4 _bitwise_not() {
		return stdmath_bool4_bitwise_not(*self);
	}
	stdmath_bool4 _logical_and(stdmath_bool4 o) {
		return stdmath_bool4_logical_and(*self, o);
	}
	stdmath_bool4 _bitwise_and(stdmath_bool4 o) {
		return stdmath_bool4_bitwise_and(*self, o);
	}
	stdmath_bool4 _logical_or(stdmath_bool4 o) {
		return stdmath_bool4_logical_or(*self, o);
	}
	stdmath_bool4 _bitwise_or(stdmath_bool4 o) {
		return stdmath_bool4_bitwise_or(*self, o);
	}
	stdmath_bool4 _bitwise_xor(stdmath_bool4 o) {
		return stdmath_bool4_bitwise_xor(*self, o);
	}
	stdmath_bool4 _shift_left(stdmath_bool4 o) {
		return stdmath_bool4_shift_left(*self, o);
	}
	stdmath_bool4 _shift_right(stdmath_bool4 o) {
		return stdmath_bool4_shift_right(*self, o);
	}
#endif

	stdmath_bool4 _equal_to(stdmath_bool4 o) {
		return stdmath_bool4_equal_to(*self, o);
	}
	stdmath_bool4 _not_equal_to(stdmath_bool4 o) {
		return stdmath_bool4_not_equal_to(*self, o);
	}
	stdmath_bool4 _less_than(stdmath_bool4 o) {
		return stdmath_bool4_less_than(*self, o);
	}
	stdmath_bool4 _less_than_or_equal_to(stdmath_bool4 o) {
		return stdmath_bool4_less_than_or_equal_to(*self, o);
	}
	stdmath_bool4 _greater_than(stdmath_bool4 o) {
		return stdmath_bool4_greater_than(*self, o);
	}
	stdmath_bool4 _greater_than_or_equal_to(stdmath_bool4 o) {
		return stdmath_bool4_greater_than_or_equal_to(*self, o);
	}

	bool _length_squared() {
		return stdmath_bool4_length_squared(*self);
	}
	bool _length() {
		return stdmath_bool4_length(*self);
	}
	bool _dot(stdmath_bool4 o) {
		return stdmath_bool4_dot(*self, o);
	}
	bool _min_element() {
		return stdmath_bool4_min_element(*self);
	}
	bool _max_element() {
		return stdmath_bool4_max_element(*self);
	}

	// bool elementwise_transform()
	// bool reduce_element

	stdmath_bool4 _min(stdmath_bool4 o) {
		return stdmath_bool4_min(*self, o);
	}
	stdmath_bool4 _max(stdmath_bool4 o) {
		return stdmath_bool4_max(*self, o);
	}
	stdmath_bool4 _normalize() {
		return stdmath_bool4_normalize(*self);
	}
	stdmath_bool4 _lerp(stdmath_bool4 o, float t) {
		return stdmath_bool4_lerp(*self, o, t);
	}
	stdmath_bool4 _clamp(stdmath_bool4 min, stdmath_bool4 max) {
		return stdmath_bool4_clamp(*self, min, max);
	}
	stdmath_bool4 _reflect(stdmath_bool4 n) {
		return stdmath_bool4_reflect(*self, n);
	}
	stdmath_bool4 _approximately_equal(stdmath_bool4 o) {
		return stdmath_bool4_approximately_equal(*self, o);
	}

#if true
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

	bool _get_element(size_t i) {
		return self->data[i];
	}

	bool _set_element(size_t i, bool value) {
		return self->data[i] = value;
	}
}