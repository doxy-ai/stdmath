%rename(float4) stdmath_float4;
%include "float4.h"

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

%extend stdmath_float4 {
	stdmath_float4(float broadcast) {
		stdmath_float4 *v;
		v = (stdmath_float4 *) malloc(sizeof(stdmath_float4));
		*v = stdmath_float4_broadcast(broadcast);
		return v;
	}

#if 4 == 4
	stdmath_float4(float x = 0, float y = 0, float z = 0, float w = 0) {
		stdmath_float4 *v;
		v = (stdmath_float4 *) malloc(sizeof(stdmath_float4));
		v->x = x;
		v->y = y;
		v->z = z;
		v->w = w;
		return v;
	}
#elif 4 == 3
	stdmath_float4(float x = 0, float y = 0, float z = 0) {
		stdmath_float4 *v;
		v = (stdmath_float4 *) malloc(sizeof(stdmath_float4));
		v->x = x;
		v->y = y;
		v->z = z;
		return v;
	}
#elif 4 == 2
	stdmath_float4(float x = 0, float y = 0) {
		stdmath_float4 *v;
		v = (stdmath_float4 *) malloc(sizeof(stdmath_float4));
		v->x = x;
		v->y = y;
		return v;
	}
#elif 4 == 1
	stdmath_float4(float x = 0) {
		stdmath_float4 *v;
		v = (stdmath_float4 *) malloc(sizeof(stdmath_float4));
		v->x = x;
		return v;
	}
#endif

	stdmath_float2 xx;
	stdmath_float2 xy;
	stdmath_float2 xz;
	stdmath_float2 xw;
	stdmath_float2 yx;
	stdmath_float2 yy;
	stdmath_float2 yz;
	stdmath_float2 yw;
	stdmath_float2 zx;
	stdmath_float2 zy;
	stdmath_float2 zz;
	stdmath_float2 zw;
	stdmath_float2 wx;
	stdmath_float2 wy;
	stdmath_float2 wz;
	stdmath_float2 ww;
	stdmath_float3 xxx;
	stdmath_float3 xxy;
	stdmath_float3 xxz;
	stdmath_float3 xxw;
	stdmath_float3 xyx;
	stdmath_float3 xyy;
	stdmath_float3 xyz;
	stdmath_float3 xyw;
	stdmath_float3 xzx;
	stdmath_float3 xzy;
	stdmath_float3 xzz;
	stdmath_float3 xzw;
	stdmath_float3 xwx;
	stdmath_float3 xwy;
	stdmath_float3 xwz;
	stdmath_float3 xww;
	stdmath_float3 yxx;
	stdmath_float3 yxy;
	stdmath_float3 yxz;
	stdmath_float3 yxw;
	stdmath_float3 yyx;
	stdmath_float3 yyy;
	stdmath_float3 yyz;
	stdmath_float3 yyw;
	stdmath_float3 yzx;
	stdmath_float3 yzy;
	stdmath_float3 yzz;
	stdmath_float3 yzw;
	stdmath_float3 ywx;
	stdmath_float3 ywy;
	stdmath_float3 ywz;
	stdmath_float3 yww;
	stdmath_float3 zxx;
	stdmath_float3 zxy;
	stdmath_float3 zxz;
	stdmath_float3 zxw;
	stdmath_float3 zyx;
	stdmath_float3 zyy;
	stdmath_float3 zyz;
	stdmath_float3 zyw;
	stdmath_float3 zzx;
	stdmath_float3 zzy;
	stdmath_float3 zzz;
	stdmath_float3 zzw;
	stdmath_float3 zwx;
	stdmath_float3 zwy;
	stdmath_float3 zwz;
	stdmath_float3 zww;
	stdmath_float3 wxx;
	stdmath_float3 wxy;
	stdmath_float3 wxz;
	stdmath_float3 wxw;
	stdmath_float3 wyx;
	stdmath_float3 wyy;
	stdmath_float3 wyz;
	stdmath_float3 wyw;
	stdmath_float3 wzx;
	stdmath_float3 wzy;
	stdmath_float3 wzz;
	stdmath_float3 wzw;
	stdmath_float3 wwx;
	stdmath_float3 wwy;
	stdmath_float3 wwz;
	stdmath_float3 www;
	stdmath_float4 xxxx;
	stdmath_float4 xxxy;
	stdmath_float4 xxxz;
	stdmath_float4 xxxw;
	stdmath_float4 xxyx;
	stdmath_float4 xxyy;
	stdmath_float4 xxyz;
	stdmath_float4 xxyw;
	stdmath_float4 xxzx;
	stdmath_float4 xxzy;
	stdmath_float4 xxzz;
	stdmath_float4 xxzw;
	stdmath_float4 xxwx;
	stdmath_float4 xxwy;
	stdmath_float4 xxwz;
	stdmath_float4 xxww;
	stdmath_float4 xyxx;
	stdmath_float4 xyxy;
	stdmath_float4 xyxz;
	stdmath_float4 xyxw;
	stdmath_float4 xyyx;
	stdmath_float4 xyyy;
	stdmath_float4 xyyz;
	stdmath_float4 xyyw;
	stdmath_float4 xyzx;
	stdmath_float4 xyzy;
	stdmath_float4 xyzz;
	stdmath_float4 xyzw;
	stdmath_float4 xywx;
	stdmath_float4 xywy;
	stdmath_float4 xywz;
	stdmath_float4 xyww;
	stdmath_float4 xzxx;
	stdmath_float4 xzxy;
	stdmath_float4 xzxz;
	stdmath_float4 xzxw;
	stdmath_float4 xzyx;
	stdmath_float4 xzyy;
	stdmath_float4 xzyz;
	stdmath_float4 xzyw;
	stdmath_float4 xzzx;
	stdmath_float4 xzzy;
	stdmath_float4 xzzz;
	stdmath_float4 xzzw;
	stdmath_float4 xzwx;
	stdmath_float4 xzwy;
	stdmath_float4 xzwz;
	stdmath_float4 xzww;
	stdmath_float4 xwxx;
	stdmath_float4 xwxy;
	stdmath_float4 xwxz;
	stdmath_float4 xwxw;
	stdmath_float4 xwyx;
	stdmath_float4 xwyy;
	stdmath_float4 xwyz;
	stdmath_float4 xwyw;
	stdmath_float4 xwzx;
	stdmath_float4 xwzy;
	stdmath_float4 xwzz;
	stdmath_float4 xwzw;
	stdmath_float4 xwwx;
	stdmath_float4 xwwy;
	stdmath_float4 xwwz;
	stdmath_float4 xwww;
	stdmath_float4 yxxx;
	stdmath_float4 yxxy;
	stdmath_float4 yxxz;
	stdmath_float4 yxxw;
	stdmath_float4 yxyx;
	stdmath_float4 yxyy;
	stdmath_float4 yxyz;
	stdmath_float4 yxyw;
	stdmath_float4 yxzx;
	stdmath_float4 yxzy;
	stdmath_float4 yxzz;
	stdmath_float4 yxzw;
	stdmath_float4 yxwx;
	stdmath_float4 yxwy;
	stdmath_float4 yxwz;
	stdmath_float4 yxww;
	stdmath_float4 yyxx;
	stdmath_float4 yyxy;
	stdmath_float4 yyxz;
	stdmath_float4 yyxw;
	stdmath_float4 yyyx;
	stdmath_float4 yyyy;
	stdmath_float4 yyyz;
	stdmath_float4 yyyw;
	stdmath_float4 yyzx;
	stdmath_float4 yyzy;
	stdmath_float4 yyzz;
	stdmath_float4 yyzw;
	stdmath_float4 yywx;
	stdmath_float4 yywy;
	stdmath_float4 yywz;
	stdmath_float4 yyww;
	stdmath_float4 yzxx;
	stdmath_float4 yzxy;
	stdmath_float4 yzxz;
	stdmath_float4 yzxw;
	stdmath_float4 yzyx;
	stdmath_float4 yzyy;
	stdmath_float4 yzyz;
	stdmath_float4 yzyw;
	stdmath_float4 yzzx;
	stdmath_float4 yzzy;
	stdmath_float4 yzzz;
	stdmath_float4 yzzw;
	stdmath_float4 yzwx;
	stdmath_float4 yzwy;
	stdmath_float4 yzwz;
	stdmath_float4 yzww;
	stdmath_float4 ywxx;
	stdmath_float4 ywxy;
	stdmath_float4 ywxz;
	stdmath_float4 ywxw;
	stdmath_float4 ywyx;
	stdmath_float4 ywyy;
	stdmath_float4 ywyz;
	stdmath_float4 ywyw;
	stdmath_float4 ywzx;
	stdmath_float4 ywzy;
	stdmath_float4 ywzz;
	stdmath_float4 ywzw;
	stdmath_float4 ywwx;
	stdmath_float4 ywwy;
	stdmath_float4 ywwz;
	stdmath_float4 ywww;
	stdmath_float4 zxxx;
	stdmath_float4 zxxy;
	stdmath_float4 zxxz;
	stdmath_float4 zxxw;
	stdmath_float4 zxyx;
	stdmath_float4 zxyy;
	stdmath_float4 zxyz;
	stdmath_float4 zxyw;
	stdmath_float4 zxzx;
	stdmath_float4 zxzy;
	stdmath_float4 zxzz;
	stdmath_float4 zxzw;
	stdmath_float4 zxwx;
	stdmath_float4 zxwy;
	stdmath_float4 zxwz;
	stdmath_float4 zxww;
	stdmath_float4 zyxx;
	stdmath_float4 zyxy;
	stdmath_float4 zyxz;
	stdmath_float4 zyxw;
	stdmath_float4 zyyx;
	stdmath_float4 zyyy;
	stdmath_float4 zyyz;
	stdmath_float4 zyyw;
	stdmath_float4 zyzx;
	stdmath_float4 zyzy;
	stdmath_float4 zyzz;
	stdmath_float4 zyzw;
	stdmath_float4 zywx;
	stdmath_float4 zywy;
	stdmath_float4 zywz;
	stdmath_float4 zyww;
	stdmath_float4 zzxx;
	stdmath_float4 zzxy;
	stdmath_float4 zzxz;
	stdmath_float4 zzxw;
	stdmath_float4 zzyx;
	stdmath_float4 zzyy;
	stdmath_float4 zzyz;
	stdmath_float4 zzyw;
	stdmath_float4 zzzx;
	stdmath_float4 zzzy;
	stdmath_float4 zzzz;
	stdmath_float4 zzzw;
	stdmath_float4 zzwx;
	stdmath_float4 zzwy;
	stdmath_float4 zzwz;
	stdmath_float4 zzww;
	stdmath_float4 zwxx;
	stdmath_float4 zwxy;
	stdmath_float4 zwxz;
	stdmath_float4 zwxw;
	stdmath_float4 zwyx;
	stdmath_float4 zwyy;
	stdmath_float4 zwyz;
	stdmath_float4 zwyw;
	stdmath_float4 zwzx;
	stdmath_float4 zwzy;
	stdmath_float4 zwzz;
	stdmath_float4 zwzw;
	stdmath_float4 zwwx;
	stdmath_float4 zwwy;
	stdmath_float4 zwwz;
	stdmath_float4 zwww;
	stdmath_float4 wxxx;
	stdmath_float4 wxxy;
	stdmath_float4 wxxz;
	stdmath_float4 wxxw;
	stdmath_float4 wxyx;
	stdmath_float4 wxyy;
	stdmath_float4 wxyz;
	stdmath_float4 wxyw;
	stdmath_float4 wxzx;
	stdmath_float4 wxzy;
	stdmath_float4 wxzz;
	stdmath_float4 wxzw;
	stdmath_float4 wxwx;
	stdmath_float4 wxwy;
	stdmath_float4 wxwz;
	stdmath_float4 wxww;
	stdmath_float4 wyxx;
	stdmath_float4 wyxy;
	stdmath_float4 wyxz;
	stdmath_float4 wyxw;
	stdmath_float4 wyyx;
	stdmath_float4 wyyy;
	stdmath_float4 wyyz;
	stdmath_float4 wyyw;
	stdmath_float4 wyzx;
	stdmath_float4 wyzy;
	stdmath_float4 wyzz;
	stdmath_float4 wyzw;
	stdmath_float4 wywx;
	stdmath_float4 wywy;
	stdmath_float4 wywz;
	stdmath_float4 wyww;
	stdmath_float4 wzxx;
	stdmath_float4 wzxy;
	stdmath_float4 wzxz;
	stdmath_float4 wzxw;
	stdmath_float4 wzyx;
	stdmath_float4 wzyy;
	stdmath_float4 wzyz;
	stdmath_float4 wzyw;
	stdmath_float4 wzzx;
	stdmath_float4 wzzy;
	stdmath_float4 wzzz;
	stdmath_float4 wzzw;
	stdmath_float4 wzwx;
	stdmath_float4 wzwy;
	stdmath_float4 wzwz;
	stdmath_float4 wzww;
	stdmath_float4 wwxx;
	stdmath_float4 wwxy;
	stdmath_float4 wwxz;
	stdmath_float4 wwxw;
	stdmath_float4 wwyx;
	stdmath_float4 wwyy;
	stdmath_float4 wwyz;
	stdmath_float4 wwyw;
	stdmath_float4 wwzx;
	stdmath_float4 wwzy;
	stdmath_float4 wwzz;
	stdmath_float4 wwzw;
	stdmath_float4 wwwx;
	stdmath_float4 wwwy;
	stdmath_float4 wwwz;
	stdmath_float4 wwww;


	stdmath_float4 _add(stdmath_float4 o) {
		return stdmath_float4_add(*self, o);
	}
	stdmath_float4 _subtract(stdmath_float4 o) {
		return stdmath_float4_subtract(*self, o);
	}
	stdmath_float4 _negate() {
		return stdmath_float4_negate(*self);
	}
	stdmath_float4 _multiply(stdmath_float4 o) {
		return stdmath_float4_multiply(*self, o);
	}
	stdmath_float4 _divide(stdmath_float4 o) {
		return stdmath_float4_divide(*self, o);
	}
	stdmath_float4 _scale(float o) {
		return stdmath_float4_scale(*self, o);
	}

#if false
	stdmath_float4 _modulus(stdmath_float4 o) {
		return stdmath_float4_modulus(*self, o);
	}
	stdmath_float4 _logical_not() {
		return stdmath_float4_logical_not(*self);
	}
	stdmath_float4 _bitwise_not() {
		return stdmath_float4_bitwise_not(*self);
	}
	stdmath_float4 _logical_and(stdmath_float4 o) {
		return stdmath_float4_logical_and(*self, o);
	}
	stdmath_float4 _bitwise_and(stdmath_float4 o) {
		return stdmath_float4_bitwise_and(*self, o);
	}
	stdmath_float4 _logical_or(stdmath_float4 o) {
		return stdmath_float4_logical_or(*self, o);
	}
	stdmath_float4 _bitwise_or(stdmath_float4 o) {
		return stdmath_float4_bitwise_or(*self, o);
	}
	stdmath_float4 _bitwise_xor(stdmath_float4 o) {
		return stdmath_float4_bitwise_xor(*self, o);
	}
	stdmath_float4 _shift_left(stdmath_float4 o) {
		return stdmath_float4_shift_left(*self, o);
	}
	stdmath_float4 _shift_right(stdmath_float4 o) {
		return stdmath_float4_shift_right(*self, o);
	}
#endif

	stdmath_bool4 _equal_to(stdmath_float4 o) {
		return stdmath_float4_equal_to(*self, o);
	}
	stdmath_bool4 _not_equal_to(stdmath_float4 o) {
		return stdmath_float4_not_equal_to(*self, o);
	}
	stdmath_bool4 _less_than(stdmath_float4 o) {
		return stdmath_float4_less_than(*self, o);
	}
	stdmath_bool4 _less_than_or_equal_to(stdmath_float4 o) {
		return stdmath_float4_less_than_or_equal_to(*self, o);
	}
	stdmath_bool4 _greater_than(stdmath_float4 o) {
		return stdmath_float4_greater_than(*self, o);
	}
	stdmath_bool4 _greater_than_or_equal_to(stdmath_float4 o) {
		return stdmath_float4_greater_than_or_equal_to(*self, o);
	}

	float _length_squared() {
		return stdmath_float4_length_squared(*self);
	}
	float _length() {
		return stdmath_float4_length(*self);
	}
	float _dot(stdmath_float4 o) {
		return stdmath_float4_dot(*self, o);
	}
	float _min_element() {
		return stdmath_float4_min_element(*self);
	}
	float _max_element() {
		return stdmath_float4_max_element(*self);
	}

	// float elementwise_transform()
	// float reduce_element

	stdmath_float4 _min(stdmath_float4 o) {
		return stdmath_float4_min(*self, o);
	}
	stdmath_float4 _max(stdmath_float4 o) {
		return stdmath_float4_max(*self, o);
	}
	stdmath_float4 _normalize() {
		return stdmath_float4_normalize(*self);
	}
	stdmath_float4 _lerp(stdmath_float4 o, float t) {
		return stdmath_float4_lerp(*self, o, t);
	}
	stdmath_float4 _clamp(stdmath_float4 min, stdmath_float4 max) {
		return stdmath_float4_clamp(*self, min, max);
	}
	stdmath_float4 _reflect(stdmath_float4 n) {
		return stdmath_float4_reflect(*self, n);
	}
	stdmath_bool4 _approximately_equal(stdmath_float4 o) {
		return stdmath_float4_approximately_equal(*self, o);
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

	float _get_element(size_t i) {
		return self->data[i];
	}

	float _set_element(size_t i, float value) {
		return self->data[i] = value;
	}
}