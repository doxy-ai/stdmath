%rename(double4) stdmath_double4;
%include "double4.h"

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

%extend stdmath_double4 {
	stdmath_double4(double broadcast) {
		stdmath_double4 *v;
		v = (stdmath_double4 *) malloc(sizeof(stdmath_double4));
		*v = stdmath_double4_broadcast(broadcast);
		return v;
	}

#if 4 == 4
	stdmath_double4(double x = 0, double y = 0, double z = 0, double w = 0) {
		stdmath_double4 *v;
		v = (stdmath_double4 *) malloc(sizeof(stdmath_double4));
		v->x = x;
		v->y = y;
		v->z = z;
		v->w = w;
		return v;
	}
#elif 4 == 3
	stdmath_double4(double x = 0, double y = 0, double z = 0) {
		stdmath_double4 *v;
		v = (stdmath_double4 *) malloc(sizeof(stdmath_double4));
		v->x = x;
		v->y = y;
		v->z = z;
		return v;
	}
#elif 4 == 2
	stdmath_double4(double x = 0, double y = 0) {
		stdmath_double4 *v;
		v = (stdmath_double4 *) malloc(sizeof(stdmath_double4));
		v->x = x;
		v->y = y;
		return v;
	}
#elif 4 == 1
	stdmath_double4(double x = 0) {
		stdmath_double4 *v;
		v = (stdmath_double4 *) malloc(sizeof(stdmath_double4));
		v->x = x;
		return v;
	}
#endif

	stdmath_double2 xx;
	stdmath_double2 xy;
	stdmath_double2 xz;
	stdmath_double2 xw;
	stdmath_double2 yx;
	stdmath_double2 yy;
	stdmath_double2 yz;
	stdmath_double2 yw;
	stdmath_double2 zx;
	stdmath_double2 zy;
	stdmath_double2 zz;
	stdmath_double2 zw;
	stdmath_double2 wx;
	stdmath_double2 wy;
	stdmath_double2 wz;
	stdmath_double2 ww;
	stdmath_double3 xxx;
	stdmath_double3 xxy;
	stdmath_double3 xxz;
	stdmath_double3 xxw;
	stdmath_double3 xyx;
	stdmath_double3 xyy;
	stdmath_double3 xyz;
	stdmath_double3 xyw;
	stdmath_double3 xzx;
	stdmath_double3 xzy;
	stdmath_double3 xzz;
	stdmath_double3 xzw;
	stdmath_double3 xwx;
	stdmath_double3 xwy;
	stdmath_double3 xwz;
	stdmath_double3 xww;
	stdmath_double3 yxx;
	stdmath_double3 yxy;
	stdmath_double3 yxz;
	stdmath_double3 yxw;
	stdmath_double3 yyx;
	stdmath_double3 yyy;
	stdmath_double3 yyz;
	stdmath_double3 yyw;
	stdmath_double3 yzx;
	stdmath_double3 yzy;
	stdmath_double3 yzz;
	stdmath_double3 yzw;
	stdmath_double3 ywx;
	stdmath_double3 ywy;
	stdmath_double3 ywz;
	stdmath_double3 yww;
	stdmath_double3 zxx;
	stdmath_double3 zxy;
	stdmath_double3 zxz;
	stdmath_double3 zxw;
	stdmath_double3 zyx;
	stdmath_double3 zyy;
	stdmath_double3 zyz;
	stdmath_double3 zyw;
	stdmath_double3 zzx;
	stdmath_double3 zzy;
	stdmath_double3 zzz;
	stdmath_double3 zzw;
	stdmath_double3 zwx;
	stdmath_double3 zwy;
	stdmath_double3 zwz;
	stdmath_double3 zww;
	stdmath_double3 wxx;
	stdmath_double3 wxy;
	stdmath_double3 wxz;
	stdmath_double3 wxw;
	stdmath_double3 wyx;
	stdmath_double3 wyy;
	stdmath_double3 wyz;
	stdmath_double3 wyw;
	stdmath_double3 wzx;
	stdmath_double3 wzy;
	stdmath_double3 wzz;
	stdmath_double3 wzw;
	stdmath_double3 wwx;
	stdmath_double3 wwy;
	stdmath_double3 wwz;
	stdmath_double3 www;
	stdmath_double4 xxxx;
	stdmath_double4 xxxy;
	stdmath_double4 xxxz;
	stdmath_double4 xxxw;
	stdmath_double4 xxyx;
	stdmath_double4 xxyy;
	stdmath_double4 xxyz;
	stdmath_double4 xxyw;
	stdmath_double4 xxzx;
	stdmath_double4 xxzy;
	stdmath_double4 xxzz;
	stdmath_double4 xxzw;
	stdmath_double4 xxwx;
	stdmath_double4 xxwy;
	stdmath_double4 xxwz;
	stdmath_double4 xxww;
	stdmath_double4 xyxx;
	stdmath_double4 xyxy;
	stdmath_double4 xyxz;
	stdmath_double4 xyxw;
	stdmath_double4 xyyx;
	stdmath_double4 xyyy;
	stdmath_double4 xyyz;
	stdmath_double4 xyyw;
	stdmath_double4 xyzx;
	stdmath_double4 xyzy;
	stdmath_double4 xyzz;
	stdmath_double4 xyzw;
	stdmath_double4 xywx;
	stdmath_double4 xywy;
	stdmath_double4 xywz;
	stdmath_double4 xyww;
	stdmath_double4 xzxx;
	stdmath_double4 xzxy;
	stdmath_double4 xzxz;
	stdmath_double4 xzxw;
	stdmath_double4 xzyx;
	stdmath_double4 xzyy;
	stdmath_double4 xzyz;
	stdmath_double4 xzyw;
	stdmath_double4 xzzx;
	stdmath_double4 xzzy;
	stdmath_double4 xzzz;
	stdmath_double4 xzzw;
	stdmath_double4 xzwx;
	stdmath_double4 xzwy;
	stdmath_double4 xzwz;
	stdmath_double4 xzww;
	stdmath_double4 xwxx;
	stdmath_double4 xwxy;
	stdmath_double4 xwxz;
	stdmath_double4 xwxw;
	stdmath_double4 xwyx;
	stdmath_double4 xwyy;
	stdmath_double4 xwyz;
	stdmath_double4 xwyw;
	stdmath_double4 xwzx;
	stdmath_double4 xwzy;
	stdmath_double4 xwzz;
	stdmath_double4 xwzw;
	stdmath_double4 xwwx;
	stdmath_double4 xwwy;
	stdmath_double4 xwwz;
	stdmath_double4 xwww;
	stdmath_double4 yxxx;
	stdmath_double4 yxxy;
	stdmath_double4 yxxz;
	stdmath_double4 yxxw;
	stdmath_double4 yxyx;
	stdmath_double4 yxyy;
	stdmath_double4 yxyz;
	stdmath_double4 yxyw;
	stdmath_double4 yxzx;
	stdmath_double4 yxzy;
	stdmath_double4 yxzz;
	stdmath_double4 yxzw;
	stdmath_double4 yxwx;
	stdmath_double4 yxwy;
	stdmath_double4 yxwz;
	stdmath_double4 yxww;
	stdmath_double4 yyxx;
	stdmath_double4 yyxy;
	stdmath_double4 yyxz;
	stdmath_double4 yyxw;
	stdmath_double4 yyyx;
	stdmath_double4 yyyy;
	stdmath_double4 yyyz;
	stdmath_double4 yyyw;
	stdmath_double4 yyzx;
	stdmath_double4 yyzy;
	stdmath_double4 yyzz;
	stdmath_double4 yyzw;
	stdmath_double4 yywx;
	stdmath_double4 yywy;
	stdmath_double4 yywz;
	stdmath_double4 yyww;
	stdmath_double4 yzxx;
	stdmath_double4 yzxy;
	stdmath_double4 yzxz;
	stdmath_double4 yzxw;
	stdmath_double4 yzyx;
	stdmath_double4 yzyy;
	stdmath_double4 yzyz;
	stdmath_double4 yzyw;
	stdmath_double4 yzzx;
	stdmath_double4 yzzy;
	stdmath_double4 yzzz;
	stdmath_double4 yzzw;
	stdmath_double4 yzwx;
	stdmath_double4 yzwy;
	stdmath_double4 yzwz;
	stdmath_double4 yzww;
	stdmath_double4 ywxx;
	stdmath_double4 ywxy;
	stdmath_double4 ywxz;
	stdmath_double4 ywxw;
	stdmath_double4 ywyx;
	stdmath_double4 ywyy;
	stdmath_double4 ywyz;
	stdmath_double4 ywyw;
	stdmath_double4 ywzx;
	stdmath_double4 ywzy;
	stdmath_double4 ywzz;
	stdmath_double4 ywzw;
	stdmath_double4 ywwx;
	stdmath_double4 ywwy;
	stdmath_double4 ywwz;
	stdmath_double4 ywww;
	stdmath_double4 zxxx;
	stdmath_double4 zxxy;
	stdmath_double4 zxxz;
	stdmath_double4 zxxw;
	stdmath_double4 zxyx;
	stdmath_double4 zxyy;
	stdmath_double4 zxyz;
	stdmath_double4 zxyw;
	stdmath_double4 zxzx;
	stdmath_double4 zxzy;
	stdmath_double4 zxzz;
	stdmath_double4 zxzw;
	stdmath_double4 zxwx;
	stdmath_double4 zxwy;
	stdmath_double4 zxwz;
	stdmath_double4 zxww;
	stdmath_double4 zyxx;
	stdmath_double4 zyxy;
	stdmath_double4 zyxz;
	stdmath_double4 zyxw;
	stdmath_double4 zyyx;
	stdmath_double4 zyyy;
	stdmath_double4 zyyz;
	stdmath_double4 zyyw;
	stdmath_double4 zyzx;
	stdmath_double4 zyzy;
	stdmath_double4 zyzz;
	stdmath_double4 zyzw;
	stdmath_double4 zywx;
	stdmath_double4 zywy;
	stdmath_double4 zywz;
	stdmath_double4 zyww;
	stdmath_double4 zzxx;
	stdmath_double4 zzxy;
	stdmath_double4 zzxz;
	stdmath_double4 zzxw;
	stdmath_double4 zzyx;
	stdmath_double4 zzyy;
	stdmath_double4 zzyz;
	stdmath_double4 zzyw;
	stdmath_double4 zzzx;
	stdmath_double4 zzzy;
	stdmath_double4 zzzz;
	stdmath_double4 zzzw;
	stdmath_double4 zzwx;
	stdmath_double4 zzwy;
	stdmath_double4 zzwz;
	stdmath_double4 zzww;
	stdmath_double4 zwxx;
	stdmath_double4 zwxy;
	stdmath_double4 zwxz;
	stdmath_double4 zwxw;
	stdmath_double4 zwyx;
	stdmath_double4 zwyy;
	stdmath_double4 zwyz;
	stdmath_double4 zwyw;
	stdmath_double4 zwzx;
	stdmath_double4 zwzy;
	stdmath_double4 zwzz;
	stdmath_double4 zwzw;
	stdmath_double4 zwwx;
	stdmath_double4 zwwy;
	stdmath_double4 zwwz;
	stdmath_double4 zwww;
	stdmath_double4 wxxx;
	stdmath_double4 wxxy;
	stdmath_double4 wxxz;
	stdmath_double4 wxxw;
	stdmath_double4 wxyx;
	stdmath_double4 wxyy;
	stdmath_double4 wxyz;
	stdmath_double4 wxyw;
	stdmath_double4 wxzx;
	stdmath_double4 wxzy;
	stdmath_double4 wxzz;
	stdmath_double4 wxzw;
	stdmath_double4 wxwx;
	stdmath_double4 wxwy;
	stdmath_double4 wxwz;
	stdmath_double4 wxww;
	stdmath_double4 wyxx;
	stdmath_double4 wyxy;
	stdmath_double4 wyxz;
	stdmath_double4 wyxw;
	stdmath_double4 wyyx;
	stdmath_double4 wyyy;
	stdmath_double4 wyyz;
	stdmath_double4 wyyw;
	stdmath_double4 wyzx;
	stdmath_double4 wyzy;
	stdmath_double4 wyzz;
	stdmath_double4 wyzw;
	stdmath_double4 wywx;
	stdmath_double4 wywy;
	stdmath_double4 wywz;
	stdmath_double4 wyww;
	stdmath_double4 wzxx;
	stdmath_double4 wzxy;
	stdmath_double4 wzxz;
	stdmath_double4 wzxw;
	stdmath_double4 wzyx;
	stdmath_double4 wzyy;
	stdmath_double4 wzyz;
	stdmath_double4 wzyw;
	stdmath_double4 wzzx;
	stdmath_double4 wzzy;
	stdmath_double4 wzzz;
	stdmath_double4 wzzw;
	stdmath_double4 wzwx;
	stdmath_double4 wzwy;
	stdmath_double4 wzwz;
	stdmath_double4 wzww;
	stdmath_double4 wwxx;
	stdmath_double4 wwxy;
	stdmath_double4 wwxz;
	stdmath_double4 wwxw;
	stdmath_double4 wwyx;
	stdmath_double4 wwyy;
	stdmath_double4 wwyz;
	stdmath_double4 wwyw;
	stdmath_double4 wwzx;
	stdmath_double4 wwzy;
	stdmath_double4 wwzz;
	stdmath_double4 wwzw;
	stdmath_double4 wwwx;
	stdmath_double4 wwwy;
	stdmath_double4 wwwz;
	stdmath_double4 wwww;


	stdmath_double4 _add(stdmath_double4 o) {
		return stdmath_double4_add(*self, o);
	}
	stdmath_double4 _subtract(stdmath_double4 o) {
		return stdmath_double4_subtract(*self, o);
	}
	stdmath_double4 _negate() {
		return stdmath_double4_negate(*self);
	}
	stdmath_double4 _multiply(stdmath_double4 o) {
		return stdmath_double4_multiply(*self, o);
	}
	stdmath_double4 _divide(stdmath_double4 o) {
		return stdmath_double4_divide(*self, o);
	}
	stdmath_double4 _scale(double o) {
		return stdmath_double4_scale(*self, o);
	}

#if false
	stdmath_double4 _modulus(stdmath_double4 o) {
		return stdmath_double4_modulus(*self, o);
	}
	stdmath_double4 _logical_not() {
		return stdmath_double4_logical_not(*self);
	}
	stdmath_double4 _bitwise_not() {
		return stdmath_double4_bitwise_not(*self);
	}
	stdmath_double4 _logical_and(stdmath_double4 o) {
		return stdmath_double4_logical_and(*self, o);
	}
	stdmath_double4 _bitwise_and(stdmath_double4 o) {
		return stdmath_double4_bitwise_and(*self, o);
	}
	stdmath_double4 _logical_or(stdmath_double4 o) {
		return stdmath_double4_logical_or(*self, o);
	}
	stdmath_double4 _bitwise_or(stdmath_double4 o) {
		return stdmath_double4_bitwise_or(*self, o);
	}
	stdmath_double4 _bitwise_xor(stdmath_double4 o) {
		return stdmath_double4_bitwise_xor(*self, o);
	}
	stdmath_double4 _shift_left(stdmath_double4 o) {
		return stdmath_double4_shift_left(*self, o);
	}
	stdmath_double4 _shift_right(stdmath_double4 o) {
		return stdmath_double4_shift_right(*self, o);
	}
#endif

	stdmath_bool4 _equal_to(stdmath_double4 o) {
		return stdmath_double4_equal_to(*self, o);
	}
	stdmath_bool4 _not_equal_to(stdmath_double4 o) {
		return stdmath_double4_not_equal_to(*self, o);
	}
	stdmath_bool4 _less_than(stdmath_double4 o) {
		return stdmath_double4_less_than(*self, o);
	}
	stdmath_bool4 _less_than_or_equal_to(stdmath_double4 o) {
		return stdmath_double4_less_than_or_equal_to(*self, o);
	}
	stdmath_bool4 _greater_than(stdmath_double4 o) {
		return stdmath_double4_greater_than(*self, o);
	}
	stdmath_bool4 _greater_than_or_equal_to(stdmath_double4 o) {
		return stdmath_double4_greater_than_or_equal_to(*self, o);
	}

	double _length_squared() {
		return stdmath_double4_length_squared(*self);
	}
	double _length() {
		return stdmath_double4_length(*self);
	}
	double _dot(stdmath_double4 o) {
		return stdmath_double4_dot(*self, o);
	}
	double _min_element() {
		return stdmath_double4_min_element(*self);
	}
	double _max_element() {
		return stdmath_double4_max_element(*self);
	}

	// double elementwise_transform()
	// double reduce_element

	stdmath_double4 _min(stdmath_double4 o) {
		return stdmath_double4_min(*self, o);
	}
	stdmath_double4 _max(stdmath_double4 o) {
		return stdmath_double4_max(*self, o);
	}
	stdmath_double4 _normalize() {
		return stdmath_double4_normalize(*self);
	}
	stdmath_double4 _lerp(stdmath_double4 o, float t) {
		return stdmath_double4_lerp(*self, o, t);
	}
	stdmath_double4 _clamp(stdmath_double4 min, stdmath_double4 max) {
		return stdmath_double4_clamp(*self, min, max);
	}
	stdmath_double4 _reflect(stdmath_double4 n) {
		return stdmath_double4_reflect(*self, n);
	}
	stdmath_bool4 _approximately_equal(stdmath_double4 o) {
		return stdmath_double4_approximately_equal(*self, o);
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

	double _get_element(size_t i) {
		return self->data[i];
	}

	double _set_element(size_t i, double value) {
		return self->data[i] = value;
	}
}