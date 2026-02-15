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
	stdmath_float2 get_xx() { return {self->x,self->x}; }
	stdmath_float4 set_xx(stdmath_float2 value) { self->x = value.x; self->x = value.y; return *self; }

	stdmath_float2 xy;
	stdmath_float2 get_xy() { return {self->x,self->y}; }
	stdmath_float4 set_xy(stdmath_float2 value) { self->x = value.x; self->y = value.y; return *self; }

	stdmath_float2 xz;
	stdmath_float2 get_xz() { return {self->x,self->z}; }
	stdmath_float4 set_xz(stdmath_float2 value) { self->x = value.x; self->z = value.y; return *self; }

	stdmath_float2 xw;
	stdmath_float2 get_xw() { return {self->x,self->w}; }
	stdmath_float4 set_xw(stdmath_float2 value) { self->x = value.x; self->w = value.y; return *self; }

	stdmath_float2 yx;
	stdmath_float2 get_yx() { return {self->y,self->x}; }
	stdmath_float4 set_yx(stdmath_float2 value) { self->y = value.x; self->x = value.y; return *self; }

	stdmath_float2 yy;
	stdmath_float2 get_yy() { return {self->y,self->y}; }
	stdmath_float4 set_yy(stdmath_float2 value) { self->y = value.x; self->y = value.y; return *self; }

	stdmath_float2 yz;
	stdmath_float2 get_yz() { return {self->y,self->z}; }
	stdmath_float4 set_yz(stdmath_float2 value) { self->y = value.x; self->z = value.y; return *self; }

	stdmath_float2 yw;
	stdmath_float2 get_yw() { return {self->y,self->w}; }
	stdmath_float4 set_yw(stdmath_float2 value) { self->y = value.x; self->w = value.y; return *self; }

	stdmath_float2 zx;
	stdmath_float2 get_zx() { return {self->z,self->x}; }
	stdmath_float4 set_zx(stdmath_float2 value) { self->z = value.x; self->x = value.y; return *self; }

	stdmath_float2 zy;
	stdmath_float2 get_zy() { return {self->z,self->y}; }
	stdmath_float4 set_zy(stdmath_float2 value) { self->z = value.x; self->y = value.y; return *self; }

	stdmath_float2 zz;
	stdmath_float2 get_zz() { return {self->z,self->z}; }
	stdmath_float4 set_zz(stdmath_float2 value) { self->z = value.x; self->z = value.y; return *self; }

	stdmath_float2 zw;
	stdmath_float2 get_zw() { return {self->z,self->w}; }
	stdmath_float4 set_zw(stdmath_float2 value) { self->z = value.x; self->w = value.y; return *self; }

	stdmath_float2 wx;
	stdmath_float2 get_wx() { return {self->w,self->x}; }
	stdmath_float4 set_wx(stdmath_float2 value) { self->w = value.x; self->x = value.y; return *self; }

	stdmath_float2 wy;
	stdmath_float2 get_wy() { return {self->w,self->y}; }
	stdmath_float4 set_wy(stdmath_float2 value) { self->w = value.x; self->y = value.y; return *self; }

	stdmath_float2 wz;
	stdmath_float2 get_wz() { return {self->w,self->z}; }
	stdmath_float4 set_wz(stdmath_float2 value) { self->w = value.x; self->z = value.y; return *self; }

	stdmath_float2 ww;
	stdmath_float2 get_ww() { return {self->w,self->w}; }
	stdmath_float4 set_ww(stdmath_float2 value) { self->w = value.x; self->w = value.y; return *self; }

	stdmath_float3 xxx;
	stdmath_float3 get_xxx() { return {self->x,self->x,self->x}; }
	stdmath_float4 set_xxx(stdmath_float3 value) { self->x = value.x; self->x = value.y; self->x = value.z; return *self; }

	stdmath_float3 xxy;
	stdmath_float3 get_xxy() { return {self->x,self->x,self->y}; }
	stdmath_float4 set_xxy(stdmath_float3 value) { self->x = value.x; self->x = value.y; self->y = value.z; return *self; }

	stdmath_float3 xxz;
	stdmath_float3 get_xxz() { return {self->x,self->x,self->z}; }
	stdmath_float4 set_xxz(stdmath_float3 value) { self->x = value.x; self->x = value.y; self->z = value.z; return *self; }

	stdmath_float3 xxw;
	stdmath_float3 get_xxw() { return {self->x,self->x,self->w}; }
	stdmath_float4 set_xxw(stdmath_float3 value) { self->x = value.x; self->x = value.y; self->w = value.z; return *self; }

	stdmath_float3 xyx;
	stdmath_float3 get_xyx() { return {self->x,self->y,self->x}; }
	stdmath_float4 set_xyx(stdmath_float3 value) { self->x = value.x; self->y = value.y; self->x = value.z; return *self; }

	stdmath_float3 xyy;
	stdmath_float3 get_xyy() { return {self->x,self->y,self->y}; }
	stdmath_float4 set_xyy(stdmath_float3 value) { self->x = value.x; self->y = value.y; self->y = value.z; return *self; }

	stdmath_float3 xyz;
	stdmath_float3 get_xyz() { return {self->x,self->y,self->z}; }
	stdmath_float4 set_xyz(stdmath_float3 value) { self->x = value.x; self->y = value.y; self->z = value.z; return *self; }

	stdmath_float3 xyw;
	stdmath_float3 get_xyw() { return {self->x,self->y,self->w}; }
	stdmath_float4 set_xyw(stdmath_float3 value) { self->x = value.x; self->y = value.y; self->w = value.z; return *self; }

	stdmath_float3 xzx;
	stdmath_float3 get_xzx() { return {self->x,self->z,self->x}; }
	stdmath_float4 set_xzx(stdmath_float3 value) { self->x = value.x; self->z = value.y; self->x = value.z; return *self; }

	stdmath_float3 xzy;
	stdmath_float3 get_xzy() { return {self->x,self->z,self->y}; }
	stdmath_float4 set_xzy(stdmath_float3 value) { self->x = value.x; self->z = value.y; self->y = value.z; return *self; }

	stdmath_float3 xzz;
	stdmath_float3 get_xzz() { return {self->x,self->z,self->z}; }
	stdmath_float4 set_xzz(stdmath_float3 value) { self->x = value.x; self->z = value.y; self->z = value.z; return *self; }

	stdmath_float3 xzw;
	stdmath_float3 get_xzw() { return {self->x,self->z,self->w}; }
	stdmath_float4 set_xzw(stdmath_float3 value) { self->x = value.x; self->z = value.y; self->w = value.z; return *self; }

	stdmath_float3 xwx;
	stdmath_float3 get_xwx() { return {self->x,self->w,self->x}; }
	stdmath_float4 set_xwx(stdmath_float3 value) { self->x = value.x; self->w = value.y; self->x = value.z; return *self; }

	stdmath_float3 xwy;
	stdmath_float3 get_xwy() { return {self->x,self->w,self->y}; }
	stdmath_float4 set_xwy(stdmath_float3 value) { self->x = value.x; self->w = value.y; self->y = value.z; return *self; }

	stdmath_float3 xwz;
	stdmath_float3 get_xwz() { return {self->x,self->w,self->z}; }
	stdmath_float4 set_xwz(stdmath_float3 value) { self->x = value.x; self->w = value.y; self->z = value.z; return *self; }

	stdmath_float3 xww;
	stdmath_float3 get_xww() { return {self->x,self->w,self->w}; }
	stdmath_float4 set_xww(stdmath_float3 value) { self->x = value.x; self->w = value.y; self->w = value.z; return *self; }

	stdmath_float3 yxx;
	stdmath_float3 get_yxx() { return {self->y,self->x,self->x}; }
	stdmath_float4 set_yxx(stdmath_float3 value) { self->y = value.x; self->x = value.y; self->x = value.z; return *self; }

	stdmath_float3 yxy;
	stdmath_float3 get_yxy() { return {self->y,self->x,self->y}; }
	stdmath_float4 set_yxy(stdmath_float3 value) { self->y = value.x; self->x = value.y; self->y = value.z; return *self; }

	stdmath_float3 yxz;
	stdmath_float3 get_yxz() { return {self->y,self->x,self->z}; }
	stdmath_float4 set_yxz(stdmath_float3 value) { self->y = value.x; self->x = value.y; self->z = value.z; return *self; }

	stdmath_float3 yxw;
	stdmath_float3 get_yxw() { return {self->y,self->x,self->w}; }
	stdmath_float4 set_yxw(stdmath_float3 value) { self->y = value.x; self->x = value.y; self->w = value.z; return *self; }

	stdmath_float3 yyx;
	stdmath_float3 get_yyx() { return {self->y,self->y,self->x}; }
	stdmath_float4 set_yyx(stdmath_float3 value) { self->y = value.x; self->y = value.y; self->x = value.z; return *self; }

	stdmath_float3 yyy;
	stdmath_float3 get_yyy() { return {self->y,self->y,self->y}; }
	stdmath_float4 set_yyy(stdmath_float3 value) { self->y = value.x; self->y = value.y; self->y = value.z; return *self; }

	stdmath_float3 yyz;
	stdmath_float3 get_yyz() { return {self->y,self->y,self->z}; }
	stdmath_float4 set_yyz(stdmath_float3 value) { self->y = value.x; self->y = value.y; self->z = value.z; return *self; }

	stdmath_float3 yyw;
	stdmath_float3 get_yyw() { return {self->y,self->y,self->w}; }
	stdmath_float4 set_yyw(stdmath_float3 value) { self->y = value.x; self->y = value.y; self->w = value.z; return *self; }

	stdmath_float3 yzx;
	stdmath_float3 get_yzx() { return {self->y,self->z,self->x}; }
	stdmath_float4 set_yzx(stdmath_float3 value) { self->y = value.x; self->z = value.y; self->x = value.z; return *self; }

	stdmath_float3 yzy;
	stdmath_float3 get_yzy() { return {self->y,self->z,self->y}; }
	stdmath_float4 set_yzy(stdmath_float3 value) { self->y = value.x; self->z = value.y; self->y = value.z; return *self; }

	stdmath_float3 yzz;
	stdmath_float3 get_yzz() { return {self->y,self->z,self->z}; }
	stdmath_float4 set_yzz(stdmath_float3 value) { self->y = value.x; self->z = value.y; self->z = value.z; return *self; }

	stdmath_float3 yzw;
	stdmath_float3 get_yzw() { return {self->y,self->z,self->w}; }
	stdmath_float4 set_yzw(stdmath_float3 value) { self->y = value.x; self->z = value.y; self->w = value.z; return *self; }

	stdmath_float3 ywx;
	stdmath_float3 get_ywx() { return {self->y,self->w,self->x}; }
	stdmath_float4 set_ywx(stdmath_float3 value) { self->y = value.x; self->w = value.y; self->x = value.z; return *self; }

	stdmath_float3 ywy;
	stdmath_float3 get_ywy() { return {self->y,self->w,self->y}; }
	stdmath_float4 set_ywy(stdmath_float3 value) { self->y = value.x; self->w = value.y; self->y = value.z; return *self; }

	stdmath_float3 ywz;
	stdmath_float3 get_ywz() { return {self->y,self->w,self->z}; }
	stdmath_float4 set_ywz(stdmath_float3 value) { self->y = value.x; self->w = value.y; self->z = value.z; return *self; }

	stdmath_float3 yww;
	stdmath_float3 get_yww() { return {self->y,self->w,self->w}; }
	stdmath_float4 set_yww(stdmath_float3 value) { self->y = value.x; self->w = value.y; self->w = value.z; return *self; }

	stdmath_float3 zxx;
	stdmath_float3 get_zxx() { return {self->z,self->x,self->x}; }
	stdmath_float4 set_zxx(stdmath_float3 value) { self->z = value.x; self->x = value.y; self->x = value.z; return *self; }

	stdmath_float3 zxy;
	stdmath_float3 get_zxy() { return {self->z,self->x,self->y}; }
	stdmath_float4 set_zxy(stdmath_float3 value) { self->z = value.x; self->x = value.y; self->y = value.z; return *self; }

	stdmath_float3 zxz;
	stdmath_float3 get_zxz() { return {self->z,self->x,self->z}; }
	stdmath_float4 set_zxz(stdmath_float3 value) { self->z = value.x; self->x = value.y; self->z = value.z; return *self; }

	stdmath_float3 zxw;
	stdmath_float3 get_zxw() { return {self->z,self->x,self->w}; }
	stdmath_float4 set_zxw(stdmath_float3 value) { self->z = value.x; self->x = value.y; self->w = value.z; return *self; }

	stdmath_float3 zyx;
	stdmath_float3 get_zyx() { return {self->z,self->y,self->x}; }
	stdmath_float4 set_zyx(stdmath_float3 value) { self->z = value.x; self->y = value.y; self->x = value.z; return *self; }

	stdmath_float3 zyy;
	stdmath_float3 get_zyy() { return {self->z,self->y,self->y}; }
	stdmath_float4 set_zyy(stdmath_float3 value) { self->z = value.x; self->y = value.y; self->y = value.z; return *self; }

	stdmath_float3 zyz;
	stdmath_float3 get_zyz() { return {self->z,self->y,self->z}; }
	stdmath_float4 set_zyz(stdmath_float3 value) { self->z = value.x; self->y = value.y; self->z = value.z; return *self; }

	stdmath_float3 zyw;
	stdmath_float3 get_zyw() { return {self->z,self->y,self->w}; }
	stdmath_float4 set_zyw(stdmath_float3 value) { self->z = value.x; self->y = value.y; self->w = value.z; return *self; }

	stdmath_float3 zzx;
	stdmath_float3 get_zzx() { return {self->z,self->z,self->x}; }
	stdmath_float4 set_zzx(stdmath_float3 value) { self->z = value.x; self->z = value.y; self->x = value.z; return *self; }

	stdmath_float3 zzy;
	stdmath_float3 get_zzy() { return {self->z,self->z,self->y}; }
	stdmath_float4 set_zzy(stdmath_float3 value) { self->z = value.x; self->z = value.y; self->y = value.z; return *self; }

	stdmath_float3 zzz;
	stdmath_float3 get_zzz() { return {self->z,self->z,self->z}; }
	stdmath_float4 set_zzz(stdmath_float3 value) { self->z = value.x; self->z = value.y; self->z = value.z; return *self; }

	stdmath_float3 zzw;
	stdmath_float3 get_zzw() { return {self->z,self->z,self->w}; }
	stdmath_float4 set_zzw(stdmath_float3 value) { self->z = value.x; self->z = value.y; self->w = value.z; return *self; }

	stdmath_float3 zwx;
	stdmath_float3 get_zwx() { return {self->z,self->w,self->x}; }
	stdmath_float4 set_zwx(stdmath_float3 value) { self->z = value.x; self->w = value.y; self->x = value.z; return *self; }

	stdmath_float3 zwy;
	stdmath_float3 get_zwy() { return {self->z,self->w,self->y}; }
	stdmath_float4 set_zwy(stdmath_float3 value) { self->z = value.x; self->w = value.y; self->y = value.z; return *self; }

	stdmath_float3 zwz;
	stdmath_float3 get_zwz() { return {self->z,self->w,self->z}; }
	stdmath_float4 set_zwz(stdmath_float3 value) { self->z = value.x; self->w = value.y; self->z = value.z; return *self; }

	stdmath_float3 zww;
	stdmath_float3 get_zww() { return {self->z,self->w,self->w}; }
	stdmath_float4 set_zww(stdmath_float3 value) { self->z = value.x; self->w = value.y; self->w = value.z; return *self; }

	stdmath_float3 wxx;
	stdmath_float3 get_wxx() { return {self->w,self->x,self->x}; }
	stdmath_float4 set_wxx(stdmath_float3 value) { self->w = value.x; self->x = value.y; self->x = value.z; return *self; }

	stdmath_float3 wxy;
	stdmath_float3 get_wxy() { return {self->w,self->x,self->y}; }
	stdmath_float4 set_wxy(stdmath_float3 value) { self->w = value.x; self->x = value.y; self->y = value.z; return *self; }

	stdmath_float3 wxz;
	stdmath_float3 get_wxz() { return {self->w,self->x,self->z}; }
	stdmath_float4 set_wxz(stdmath_float3 value) { self->w = value.x; self->x = value.y; self->z = value.z; return *self; }

	stdmath_float3 wxw;
	stdmath_float3 get_wxw() { return {self->w,self->x,self->w}; }
	stdmath_float4 set_wxw(stdmath_float3 value) { self->w = value.x; self->x = value.y; self->w = value.z; return *self; }

	stdmath_float3 wyx;
	stdmath_float3 get_wyx() { return {self->w,self->y,self->x}; }
	stdmath_float4 set_wyx(stdmath_float3 value) { self->w = value.x; self->y = value.y; self->x = value.z; return *self; }

	stdmath_float3 wyy;
	stdmath_float3 get_wyy() { return {self->w,self->y,self->y}; }
	stdmath_float4 set_wyy(stdmath_float3 value) { self->w = value.x; self->y = value.y; self->y = value.z; return *self; }

	stdmath_float3 wyz;
	stdmath_float3 get_wyz() { return {self->w,self->y,self->z}; }
	stdmath_float4 set_wyz(stdmath_float3 value) { self->w = value.x; self->y = value.y; self->z = value.z; return *self; }

	stdmath_float3 wyw;
	stdmath_float3 get_wyw() { return {self->w,self->y,self->w}; }
	stdmath_float4 set_wyw(stdmath_float3 value) { self->w = value.x; self->y = value.y; self->w = value.z; return *self; }

	stdmath_float3 wzx;
	stdmath_float3 get_wzx() { return {self->w,self->z,self->x}; }
	stdmath_float4 set_wzx(stdmath_float3 value) { self->w = value.x; self->z = value.y; self->x = value.z; return *self; }

	stdmath_float3 wzy;
	stdmath_float3 get_wzy() { return {self->w,self->z,self->y}; }
	stdmath_float4 set_wzy(stdmath_float3 value) { self->w = value.x; self->z = value.y; self->y = value.z; return *self; }

	stdmath_float3 wzz;
	stdmath_float3 get_wzz() { return {self->w,self->z,self->z}; }
	stdmath_float4 set_wzz(stdmath_float3 value) { self->w = value.x; self->z = value.y; self->z = value.z; return *self; }

	stdmath_float3 wzw;
	stdmath_float3 get_wzw() { return {self->w,self->z,self->w}; }
	stdmath_float4 set_wzw(stdmath_float3 value) { self->w = value.x; self->z = value.y; self->w = value.z; return *self; }

	stdmath_float3 wwx;
	stdmath_float3 get_wwx() { return {self->w,self->w,self->x}; }
	stdmath_float4 set_wwx(stdmath_float3 value) { self->w = value.x; self->w = value.y; self->x = value.z; return *self; }

	stdmath_float3 wwy;
	stdmath_float3 get_wwy() { return {self->w,self->w,self->y}; }
	stdmath_float4 set_wwy(stdmath_float3 value) { self->w = value.x; self->w = value.y; self->y = value.z; return *self; }

	stdmath_float3 wwz;
	stdmath_float3 get_wwz() { return {self->w,self->w,self->z}; }
	stdmath_float4 set_wwz(stdmath_float3 value) { self->w = value.x; self->w = value.y; self->z = value.z; return *self; }

	stdmath_float3 www;
	stdmath_float3 get_www() { return {self->w,self->w,self->w}; }
	stdmath_float4 set_www(stdmath_float3 value) { self->w = value.x; self->w = value.y; self->w = value.z; return *self; }

	stdmath_float4 xxxx;
	stdmath_float4 get_xxxx() { return {self->x,self->x,self->x,self->x}; }
	stdmath_float4 set_xxxx(stdmath_float4 value) { self->x = value.x; self->x = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_float4 xxxy;
	stdmath_float4 get_xxxy() { return {self->x,self->x,self->x,self->y}; }
	stdmath_float4 set_xxxy(stdmath_float4 value) { self->x = value.x; self->x = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_float4 xxxz;
	stdmath_float4 get_xxxz() { return {self->x,self->x,self->x,self->z}; }
	stdmath_float4 set_xxxz(stdmath_float4 value) { self->x = value.x; self->x = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_float4 xxxw;
	stdmath_float4 get_xxxw() { return {self->x,self->x,self->x,self->w}; }
	stdmath_float4 set_xxxw(stdmath_float4 value) { self->x = value.x; self->x = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_float4 xxyx;
	stdmath_float4 get_xxyx() { return {self->x,self->x,self->y,self->x}; }
	stdmath_float4 set_xxyx(stdmath_float4 value) { self->x = value.x; self->x = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_float4 xxyy;
	stdmath_float4 get_xxyy() { return {self->x,self->x,self->y,self->y}; }
	stdmath_float4 set_xxyy(stdmath_float4 value) { self->x = value.x; self->x = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_float4 xxyz;
	stdmath_float4 get_xxyz() { return {self->x,self->x,self->y,self->z}; }
	stdmath_float4 set_xxyz(stdmath_float4 value) { self->x = value.x; self->x = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_float4 xxyw;
	stdmath_float4 get_xxyw() { return {self->x,self->x,self->y,self->w}; }
	stdmath_float4 set_xxyw(stdmath_float4 value) { self->x = value.x; self->x = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_float4 xxzx;
	stdmath_float4 get_xxzx() { return {self->x,self->x,self->z,self->x}; }
	stdmath_float4 set_xxzx(stdmath_float4 value) { self->x = value.x; self->x = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_float4 xxzy;
	stdmath_float4 get_xxzy() { return {self->x,self->x,self->z,self->y}; }
	stdmath_float4 set_xxzy(stdmath_float4 value) { self->x = value.x; self->x = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_float4 xxzz;
	stdmath_float4 get_xxzz() { return {self->x,self->x,self->z,self->z}; }
	stdmath_float4 set_xxzz(stdmath_float4 value) { self->x = value.x; self->x = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_float4 xxzw;
	stdmath_float4 get_xxzw() { return {self->x,self->x,self->z,self->w}; }
	stdmath_float4 set_xxzw(stdmath_float4 value) { self->x = value.x; self->x = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_float4 xxwx;
	stdmath_float4 get_xxwx() { return {self->x,self->x,self->w,self->x}; }
	stdmath_float4 set_xxwx(stdmath_float4 value) { self->x = value.x; self->x = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_float4 xxwy;
	stdmath_float4 get_xxwy() { return {self->x,self->x,self->w,self->y}; }
	stdmath_float4 set_xxwy(stdmath_float4 value) { self->x = value.x; self->x = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_float4 xxwz;
	stdmath_float4 get_xxwz() { return {self->x,self->x,self->w,self->z}; }
	stdmath_float4 set_xxwz(stdmath_float4 value) { self->x = value.x; self->x = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_float4 xxww;
	stdmath_float4 get_xxww() { return {self->x,self->x,self->w,self->w}; }
	stdmath_float4 set_xxww(stdmath_float4 value) { self->x = value.x; self->x = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_float4 xyxx;
	stdmath_float4 get_xyxx() { return {self->x,self->y,self->x,self->x}; }
	stdmath_float4 set_xyxx(stdmath_float4 value) { self->x = value.x; self->y = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_float4 xyxy;
	stdmath_float4 get_xyxy() { return {self->x,self->y,self->x,self->y}; }
	stdmath_float4 set_xyxy(stdmath_float4 value) { self->x = value.x; self->y = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_float4 xyxz;
	stdmath_float4 get_xyxz() { return {self->x,self->y,self->x,self->z}; }
	stdmath_float4 set_xyxz(stdmath_float4 value) { self->x = value.x; self->y = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_float4 xyxw;
	stdmath_float4 get_xyxw() { return {self->x,self->y,self->x,self->w}; }
	stdmath_float4 set_xyxw(stdmath_float4 value) { self->x = value.x; self->y = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_float4 xyyx;
	stdmath_float4 get_xyyx() { return {self->x,self->y,self->y,self->x}; }
	stdmath_float4 set_xyyx(stdmath_float4 value) { self->x = value.x; self->y = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_float4 xyyy;
	stdmath_float4 get_xyyy() { return {self->x,self->y,self->y,self->y}; }
	stdmath_float4 set_xyyy(stdmath_float4 value) { self->x = value.x; self->y = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_float4 xyyz;
	stdmath_float4 get_xyyz() { return {self->x,self->y,self->y,self->z}; }
	stdmath_float4 set_xyyz(stdmath_float4 value) { self->x = value.x; self->y = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_float4 xyyw;
	stdmath_float4 get_xyyw() { return {self->x,self->y,self->y,self->w}; }
	stdmath_float4 set_xyyw(stdmath_float4 value) { self->x = value.x; self->y = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_float4 xyzx;
	stdmath_float4 get_xyzx() { return {self->x,self->y,self->z,self->x}; }
	stdmath_float4 set_xyzx(stdmath_float4 value) { self->x = value.x; self->y = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_float4 xyzy;
	stdmath_float4 get_xyzy() { return {self->x,self->y,self->z,self->y}; }
	stdmath_float4 set_xyzy(stdmath_float4 value) { self->x = value.x; self->y = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_float4 xyzz;
	stdmath_float4 get_xyzz() { return {self->x,self->y,self->z,self->z}; }
	stdmath_float4 set_xyzz(stdmath_float4 value) { self->x = value.x; self->y = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_float4 xyzw;
	stdmath_float4 get_xyzw() { return {self->x,self->y,self->z,self->w}; }
	stdmath_float4 set_xyzw(stdmath_float4 value) { self->x = value.x; self->y = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_float4 xywx;
	stdmath_float4 get_xywx() { return {self->x,self->y,self->w,self->x}; }
	stdmath_float4 set_xywx(stdmath_float4 value) { self->x = value.x; self->y = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_float4 xywy;
	stdmath_float4 get_xywy() { return {self->x,self->y,self->w,self->y}; }
	stdmath_float4 set_xywy(stdmath_float4 value) { self->x = value.x; self->y = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_float4 xywz;
	stdmath_float4 get_xywz() { return {self->x,self->y,self->w,self->z}; }
	stdmath_float4 set_xywz(stdmath_float4 value) { self->x = value.x; self->y = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_float4 xyww;
	stdmath_float4 get_xyww() { return {self->x,self->y,self->w,self->w}; }
	stdmath_float4 set_xyww(stdmath_float4 value) { self->x = value.x; self->y = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_float4 xzxx;
	stdmath_float4 get_xzxx() { return {self->x,self->z,self->x,self->x}; }
	stdmath_float4 set_xzxx(stdmath_float4 value) { self->x = value.x; self->z = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_float4 xzxy;
	stdmath_float4 get_xzxy() { return {self->x,self->z,self->x,self->y}; }
	stdmath_float4 set_xzxy(stdmath_float4 value) { self->x = value.x; self->z = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_float4 xzxz;
	stdmath_float4 get_xzxz() { return {self->x,self->z,self->x,self->z}; }
	stdmath_float4 set_xzxz(stdmath_float4 value) { self->x = value.x; self->z = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_float4 xzxw;
	stdmath_float4 get_xzxw() { return {self->x,self->z,self->x,self->w}; }
	stdmath_float4 set_xzxw(stdmath_float4 value) { self->x = value.x; self->z = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_float4 xzyx;
	stdmath_float4 get_xzyx() { return {self->x,self->z,self->y,self->x}; }
	stdmath_float4 set_xzyx(stdmath_float4 value) { self->x = value.x; self->z = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_float4 xzyy;
	stdmath_float4 get_xzyy() { return {self->x,self->z,self->y,self->y}; }
	stdmath_float4 set_xzyy(stdmath_float4 value) { self->x = value.x; self->z = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_float4 xzyz;
	stdmath_float4 get_xzyz() { return {self->x,self->z,self->y,self->z}; }
	stdmath_float4 set_xzyz(stdmath_float4 value) { self->x = value.x; self->z = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_float4 xzyw;
	stdmath_float4 get_xzyw() { return {self->x,self->z,self->y,self->w}; }
	stdmath_float4 set_xzyw(stdmath_float4 value) { self->x = value.x; self->z = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_float4 xzzx;
	stdmath_float4 get_xzzx() { return {self->x,self->z,self->z,self->x}; }
	stdmath_float4 set_xzzx(stdmath_float4 value) { self->x = value.x; self->z = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_float4 xzzy;
	stdmath_float4 get_xzzy() { return {self->x,self->z,self->z,self->y}; }
	stdmath_float4 set_xzzy(stdmath_float4 value) { self->x = value.x; self->z = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_float4 xzzz;
	stdmath_float4 get_xzzz() { return {self->x,self->z,self->z,self->z}; }
	stdmath_float4 set_xzzz(stdmath_float4 value) { self->x = value.x; self->z = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_float4 xzzw;
	stdmath_float4 get_xzzw() { return {self->x,self->z,self->z,self->w}; }
	stdmath_float4 set_xzzw(stdmath_float4 value) { self->x = value.x; self->z = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_float4 xzwx;
	stdmath_float4 get_xzwx() { return {self->x,self->z,self->w,self->x}; }
	stdmath_float4 set_xzwx(stdmath_float4 value) { self->x = value.x; self->z = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_float4 xzwy;
	stdmath_float4 get_xzwy() { return {self->x,self->z,self->w,self->y}; }
	stdmath_float4 set_xzwy(stdmath_float4 value) { self->x = value.x; self->z = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_float4 xzwz;
	stdmath_float4 get_xzwz() { return {self->x,self->z,self->w,self->z}; }
	stdmath_float4 set_xzwz(stdmath_float4 value) { self->x = value.x; self->z = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_float4 xzww;
	stdmath_float4 get_xzww() { return {self->x,self->z,self->w,self->w}; }
	stdmath_float4 set_xzww(stdmath_float4 value) { self->x = value.x; self->z = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_float4 xwxx;
	stdmath_float4 get_xwxx() { return {self->x,self->w,self->x,self->x}; }
	stdmath_float4 set_xwxx(stdmath_float4 value) { self->x = value.x; self->w = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_float4 xwxy;
	stdmath_float4 get_xwxy() { return {self->x,self->w,self->x,self->y}; }
	stdmath_float4 set_xwxy(stdmath_float4 value) { self->x = value.x; self->w = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_float4 xwxz;
	stdmath_float4 get_xwxz() { return {self->x,self->w,self->x,self->z}; }
	stdmath_float4 set_xwxz(stdmath_float4 value) { self->x = value.x; self->w = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_float4 xwxw;
	stdmath_float4 get_xwxw() { return {self->x,self->w,self->x,self->w}; }
	stdmath_float4 set_xwxw(stdmath_float4 value) { self->x = value.x; self->w = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_float4 xwyx;
	stdmath_float4 get_xwyx() { return {self->x,self->w,self->y,self->x}; }
	stdmath_float4 set_xwyx(stdmath_float4 value) { self->x = value.x; self->w = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_float4 xwyy;
	stdmath_float4 get_xwyy() { return {self->x,self->w,self->y,self->y}; }
	stdmath_float4 set_xwyy(stdmath_float4 value) { self->x = value.x; self->w = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_float4 xwyz;
	stdmath_float4 get_xwyz() { return {self->x,self->w,self->y,self->z}; }
	stdmath_float4 set_xwyz(stdmath_float4 value) { self->x = value.x; self->w = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_float4 xwyw;
	stdmath_float4 get_xwyw() { return {self->x,self->w,self->y,self->w}; }
	stdmath_float4 set_xwyw(stdmath_float4 value) { self->x = value.x; self->w = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_float4 xwzx;
	stdmath_float4 get_xwzx() { return {self->x,self->w,self->z,self->x}; }
	stdmath_float4 set_xwzx(stdmath_float4 value) { self->x = value.x; self->w = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_float4 xwzy;
	stdmath_float4 get_xwzy() { return {self->x,self->w,self->z,self->y}; }
	stdmath_float4 set_xwzy(stdmath_float4 value) { self->x = value.x; self->w = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_float4 xwzz;
	stdmath_float4 get_xwzz() { return {self->x,self->w,self->z,self->z}; }
	stdmath_float4 set_xwzz(stdmath_float4 value) { self->x = value.x; self->w = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_float4 xwzw;
	stdmath_float4 get_xwzw() { return {self->x,self->w,self->z,self->w}; }
	stdmath_float4 set_xwzw(stdmath_float4 value) { self->x = value.x; self->w = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_float4 xwwx;
	stdmath_float4 get_xwwx() { return {self->x,self->w,self->w,self->x}; }
	stdmath_float4 set_xwwx(stdmath_float4 value) { self->x = value.x; self->w = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_float4 xwwy;
	stdmath_float4 get_xwwy() { return {self->x,self->w,self->w,self->y}; }
	stdmath_float4 set_xwwy(stdmath_float4 value) { self->x = value.x; self->w = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_float4 xwwz;
	stdmath_float4 get_xwwz() { return {self->x,self->w,self->w,self->z}; }
	stdmath_float4 set_xwwz(stdmath_float4 value) { self->x = value.x; self->w = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_float4 xwww;
	stdmath_float4 get_xwww() { return {self->x,self->w,self->w,self->w}; }
	stdmath_float4 set_xwww(stdmath_float4 value) { self->x = value.x; self->w = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_float4 yxxx;
	stdmath_float4 get_yxxx() { return {self->y,self->x,self->x,self->x}; }
	stdmath_float4 set_yxxx(stdmath_float4 value) { self->y = value.x; self->x = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_float4 yxxy;
	stdmath_float4 get_yxxy() { return {self->y,self->x,self->x,self->y}; }
	stdmath_float4 set_yxxy(stdmath_float4 value) { self->y = value.x; self->x = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_float4 yxxz;
	stdmath_float4 get_yxxz() { return {self->y,self->x,self->x,self->z}; }
	stdmath_float4 set_yxxz(stdmath_float4 value) { self->y = value.x; self->x = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_float4 yxxw;
	stdmath_float4 get_yxxw() { return {self->y,self->x,self->x,self->w}; }
	stdmath_float4 set_yxxw(stdmath_float4 value) { self->y = value.x; self->x = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_float4 yxyx;
	stdmath_float4 get_yxyx() { return {self->y,self->x,self->y,self->x}; }
	stdmath_float4 set_yxyx(stdmath_float4 value) { self->y = value.x; self->x = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_float4 yxyy;
	stdmath_float4 get_yxyy() { return {self->y,self->x,self->y,self->y}; }
	stdmath_float4 set_yxyy(stdmath_float4 value) { self->y = value.x; self->x = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_float4 yxyz;
	stdmath_float4 get_yxyz() { return {self->y,self->x,self->y,self->z}; }
	stdmath_float4 set_yxyz(stdmath_float4 value) { self->y = value.x; self->x = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_float4 yxyw;
	stdmath_float4 get_yxyw() { return {self->y,self->x,self->y,self->w}; }
	stdmath_float4 set_yxyw(stdmath_float4 value) { self->y = value.x; self->x = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_float4 yxzx;
	stdmath_float4 get_yxzx() { return {self->y,self->x,self->z,self->x}; }
	stdmath_float4 set_yxzx(stdmath_float4 value) { self->y = value.x; self->x = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_float4 yxzy;
	stdmath_float4 get_yxzy() { return {self->y,self->x,self->z,self->y}; }
	stdmath_float4 set_yxzy(stdmath_float4 value) { self->y = value.x; self->x = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_float4 yxzz;
	stdmath_float4 get_yxzz() { return {self->y,self->x,self->z,self->z}; }
	stdmath_float4 set_yxzz(stdmath_float4 value) { self->y = value.x; self->x = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_float4 yxzw;
	stdmath_float4 get_yxzw() { return {self->y,self->x,self->z,self->w}; }
	stdmath_float4 set_yxzw(stdmath_float4 value) { self->y = value.x; self->x = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_float4 yxwx;
	stdmath_float4 get_yxwx() { return {self->y,self->x,self->w,self->x}; }
	stdmath_float4 set_yxwx(stdmath_float4 value) { self->y = value.x; self->x = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_float4 yxwy;
	stdmath_float4 get_yxwy() { return {self->y,self->x,self->w,self->y}; }
	stdmath_float4 set_yxwy(stdmath_float4 value) { self->y = value.x; self->x = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_float4 yxwz;
	stdmath_float4 get_yxwz() { return {self->y,self->x,self->w,self->z}; }
	stdmath_float4 set_yxwz(stdmath_float4 value) { self->y = value.x; self->x = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_float4 yxww;
	stdmath_float4 get_yxww() { return {self->y,self->x,self->w,self->w}; }
	stdmath_float4 set_yxww(stdmath_float4 value) { self->y = value.x; self->x = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_float4 yyxx;
	stdmath_float4 get_yyxx() { return {self->y,self->y,self->x,self->x}; }
	stdmath_float4 set_yyxx(stdmath_float4 value) { self->y = value.x; self->y = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_float4 yyxy;
	stdmath_float4 get_yyxy() { return {self->y,self->y,self->x,self->y}; }
	stdmath_float4 set_yyxy(stdmath_float4 value) { self->y = value.x; self->y = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_float4 yyxz;
	stdmath_float4 get_yyxz() { return {self->y,self->y,self->x,self->z}; }
	stdmath_float4 set_yyxz(stdmath_float4 value) { self->y = value.x; self->y = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_float4 yyxw;
	stdmath_float4 get_yyxw() { return {self->y,self->y,self->x,self->w}; }
	stdmath_float4 set_yyxw(stdmath_float4 value) { self->y = value.x; self->y = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_float4 yyyx;
	stdmath_float4 get_yyyx() { return {self->y,self->y,self->y,self->x}; }
	stdmath_float4 set_yyyx(stdmath_float4 value) { self->y = value.x; self->y = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_float4 yyyy;
	stdmath_float4 get_yyyy() { return {self->y,self->y,self->y,self->y}; }
	stdmath_float4 set_yyyy(stdmath_float4 value) { self->y = value.x; self->y = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_float4 yyyz;
	stdmath_float4 get_yyyz() { return {self->y,self->y,self->y,self->z}; }
	stdmath_float4 set_yyyz(stdmath_float4 value) { self->y = value.x; self->y = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_float4 yyyw;
	stdmath_float4 get_yyyw() { return {self->y,self->y,self->y,self->w}; }
	stdmath_float4 set_yyyw(stdmath_float4 value) { self->y = value.x; self->y = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_float4 yyzx;
	stdmath_float4 get_yyzx() { return {self->y,self->y,self->z,self->x}; }
	stdmath_float4 set_yyzx(stdmath_float4 value) { self->y = value.x; self->y = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_float4 yyzy;
	stdmath_float4 get_yyzy() { return {self->y,self->y,self->z,self->y}; }
	stdmath_float4 set_yyzy(stdmath_float4 value) { self->y = value.x; self->y = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_float4 yyzz;
	stdmath_float4 get_yyzz() { return {self->y,self->y,self->z,self->z}; }
	stdmath_float4 set_yyzz(stdmath_float4 value) { self->y = value.x; self->y = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_float4 yyzw;
	stdmath_float4 get_yyzw() { return {self->y,self->y,self->z,self->w}; }
	stdmath_float4 set_yyzw(stdmath_float4 value) { self->y = value.x; self->y = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_float4 yywx;
	stdmath_float4 get_yywx() { return {self->y,self->y,self->w,self->x}; }
	stdmath_float4 set_yywx(stdmath_float4 value) { self->y = value.x; self->y = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_float4 yywy;
	stdmath_float4 get_yywy() { return {self->y,self->y,self->w,self->y}; }
	stdmath_float4 set_yywy(stdmath_float4 value) { self->y = value.x; self->y = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_float4 yywz;
	stdmath_float4 get_yywz() { return {self->y,self->y,self->w,self->z}; }
	stdmath_float4 set_yywz(stdmath_float4 value) { self->y = value.x; self->y = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_float4 yyww;
	stdmath_float4 get_yyww() { return {self->y,self->y,self->w,self->w}; }
	stdmath_float4 set_yyww(stdmath_float4 value) { self->y = value.x; self->y = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_float4 yzxx;
	stdmath_float4 get_yzxx() { return {self->y,self->z,self->x,self->x}; }
	stdmath_float4 set_yzxx(stdmath_float4 value) { self->y = value.x; self->z = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_float4 yzxy;
	stdmath_float4 get_yzxy() { return {self->y,self->z,self->x,self->y}; }
	stdmath_float4 set_yzxy(stdmath_float4 value) { self->y = value.x; self->z = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_float4 yzxz;
	stdmath_float4 get_yzxz() { return {self->y,self->z,self->x,self->z}; }
	stdmath_float4 set_yzxz(stdmath_float4 value) { self->y = value.x; self->z = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_float4 yzxw;
	stdmath_float4 get_yzxw() { return {self->y,self->z,self->x,self->w}; }
	stdmath_float4 set_yzxw(stdmath_float4 value) { self->y = value.x; self->z = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_float4 yzyx;
	stdmath_float4 get_yzyx() { return {self->y,self->z,self->y,self->x}; }
	stdmath_float4 set_yzyx(stdmath_float4 value) { self->y = value.x; self->z = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_float4 yzyy;
	stdmath_float4 get_yzyy() { return {self->y,self->z,self->y,self->y}; }
	stdmath_float4 set_yzyy(stdmath_float4 value) { self->y = value.x; self->z = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_float4 yzyz;
	stdmath_float4 get_yzyz() { return {self->y,self->z,self->y,self->z}; }
	stdmath_float4 set_yzyz(stdmath_float4 value) { self->y = value.x; self->z = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_float4 yzyw;
	stdmath_float4 get_yzyw() { return {self->y,self->z,self->y,self->w}; }
	stdmath_float4 set_yzyw(stdmath_float4 value) { self->y = value.x; self->z = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_float4 yzzx;
	stdmath_float4 get_yzzx() { return {self->y,self->z,self->z,self->x}; }
	stdmath_float4 set_yzzx(stdmath_float4 value) { self->y = value.x; self->z = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_float4 yzzy;
	stdmath_float4 get_yzzy() { return {self->y,self->z,self->z,self->y}; }
	stdmath_float4 set_yzzy(stdmath_float4 value) { self->y = value.x; self->z = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_float4 yzzz;
	stdmath_float4 get_yzzz() { return {self->y,self->z,self->z,self->z}; }
	stdmath_float4 set_yzzz(stdmath_float4 value) { self->y = value.x; self->z = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_float4 yzzw;
	stdmath_float4 get_yzzw() { return {self->y,self->z,self->z,self->w}; }
	stdmath_float4 set_yzzw(stdmath_float4 value) { self->y = value.x; self->z = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_float4 yzwx;
	stdmath_float4 get_yzwx() { return {self->y,self->z,self->w,self->x}; }
	stdmath_float4 set_yzwx(stdmath_float4 value) { self->y = value.x; self->z = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_float4 yzwy;
	stdmath_float4 get_yzwy() { return {self->y,self->z,self->w,self->y}; }
	stdmath_float4 set_yzwy(stdmath_float4 value) { self->y = value.x; self->z = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_float4 yzwz;
	stdmath_float4 get_yzwz() { return {self->y,self->z,self->w,self->z}; }
	stdmath_float4 set_yzwz(stdmath_float4 value) { self->y = value.x; self->z = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_float4 yzww;
	stdmath_float4 get_yzww() { return {self->y,self->z,self->w,self->w}; }
	stdmath_float4 set_yzww(stdmath_float4 value) { self->y = value.x; self->z = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_float4 ywxx;
	stdmath_float4 get_ywxx() { return {self->y,self->w,self->x,self->x}; }
	stdmath_float4 set_ywxx(stdmath_float4 value) { self->y = value.x; self->w = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_float4 ywxy;
	stdmath_float4 get_ywxy() { return {self->y,self->w,self->x,self->y}; }
	stdmath_float4 set_ywxy(stdmath_float4 value) { self->y = value.x; self->w = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_float4 ywxz;
	stdmath_float4 get_ywxz() { return {self->y,self->w,self->x,self->z}; }
	stdmath_float4 set_ywxz(stdmath_float4 value) { self->y = value.x; self->w = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_float4 ywxw;
	stdmath_float4 get_ywxw() { return {self->y,self->w,self->x,self->w}; }
	stdmath_float4 set_ywxw(stdmath_float4 value) { self->y = value.x; self->w = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_float4 ywyx;
	stdmath_float4 get_ywyx() { return {self->y,self->w,self->y,self->x}; }
	stdmath_float4 set_ywyx(stdmath_float4 value) { self->y = value.x; self->w = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_float4 ywyy;
	stdmath_float4 get_ywyy() { return {self->y,self->w,self->y,self->y}; }
	stdmath_float4 set_ywyy(stdmath_float4 value) { self->y = value.x; self->w = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_float4 ywyz;
	stdmath_float4 get_ywyz() { return {self->y,self->w,self->y,self->z}; }
	stdmath_float4 set_ywyz(stdmath_float4 value) { self->y = value.x; self->w = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_float4 ywyw;
	stdmath_float4 get_ywyw() { return {self->y,self->w,self->y,self->w}; }
	stdmath_float4 set_ywyw(stdmath_float4 value) { self->y = value.x; self->w = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_float4 ywzx;
	stdmath_float4 get_ywzx() { return {self->y,self->w,self->z,self->x}; }
	stdmath_float4 set_ywzx(stdmath_float4 value) { self->y = value.x; self->w = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_float4 ywzy;
	stdmath_float4 get_ywzy() { return {self->y,self->w,self->z,self->y}; }
	stdmath_float4 set_ywzy(stdmath_float4 value) { self->y = value.x; self->w = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_float4 ywzz;
	stdmath_float4 get_ywzz() { return {self->y,self->w,self->z,self->z}; }
	stdmath_float4 set_ywzz(stdmath_float4 value) { self->y = value.x; self->w = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_float4 ywzw;
	stdmath_float4 get_ywzw() { return {self->y,self->w,self->z,self->w}; }
	stdmath_float4 set_ywzw(stdmath_float4 value) { self->y = value.x; self->w = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_float4 ywwx;
	stdmath_float4 get_ywwx() { return {self->y,self->w,self->w,self->x}; }
	stdmath_float4 set_ywwx(stdmath_float4 value) { self->y = value.x; self->w = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_float4 ywwy;
	stdmath_float4 get_ywwy() { return {self->y,self->w,self->w,self->y}; }
	stdmath_float4 set_ywwy(stdmath_float4 value) { self->y = value.x; self->w = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_float4 ywwz;
	stdmath_float4 get_ywwz() { return {self->y,self->w,self->w,self->z}; }
	stdmath_float4 set_ywwz(stdmath_float4 value) { self->y = value.x; self->w = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_float4 ywww;
	stdmath_float4 get_ywww() { return {self->y,self->w,self->w,self->w}; }
	stdmath_float4 set_ywww(stdmath_float4 value) { self->y = value.x; self->w = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_float4 zxxx;
	stdmath_float4 get_zxxx() { return {self->z,self->x,self->x,self->x}; }
	stdmath_float4 set_zxxx(stdmath_float4 value) { self->z = value.x; self->x = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_float4 zxxy;
	stdmath_float4 get_zxxy() { return {self->z,self->x,self->x,self->y}; }
	stdmath_float4 set_zxxy(stdmath_float4 value) { self->z = value.x; self->x = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_float4 zxxz;
	stdmath_float4 get_zxxz() { return {self->z,self->x,self->x,self->z}; }
	stdmath_float4 set_zxxz(stdmath_float4 value) { self->z = value.x; self->x = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_float4 zxxw;
	stdmath_float4 get_zxxw() { return {self->z,self->x,self->x,self->w}; }
	stdmath_float4 set_zxxw(stdmath_float4 value) { self->z = value.x; self->x = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_float4 zxyx;
	stdmath_float4 get_zxyx() { return {self->z,self->x,self->y,self->x}; }
	stdmath_float4 set_zxyx(stdmath_float4 value) { self->z = value.x; self->x = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_float4 zxyy;
	stdmath_float4 get_zxyy() { return {self->z,self->x,self->y,self->y}; }
	stdmath_float4 set_zxyy(stdmath_float4 value) { self->z = value.x; self->x = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_float4 zxyz;
	stdmath_float4 get_zxyz() { return {self->z,self->x,self->y,self->z}; }
	stdmath_float4 set_zxyz(stdmath_float4 value) { self->z = value.x; self->x = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_float4 zxyw;
	stdmath_float4 get_zxyw() { return {self->z,self->x,self->y,self->w}; }
	stdmath_float4 set_zxyw(stdmath_float4 value) { self->z = value.x; self->x = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_float4 zxzx;
	stdmath_float4 get_zxzx() { return {self->z,self->x,self->z,self->x}; }
	stdmath_float4 set_zxzx(stdmath_float4 value) { self->z = value.x; self->x = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_float4 zxzy;
	stdmath_float4 get_zxzy() { return {self->z,self->x,self->z,self->y}; }
	stdmath_float4 set_zxzy(stdmath_float4 value) { self->z = value.x; self->x = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_float4 zxzz;
	stdmath_float4 get_zxzz() { return {self->z,self->x,self->z,self->z}; }
	stdmath_float4 set_zxzz(stdmath_float4 value) { self->z = value.x; self->x = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_float4 zxzw;
	stdmath_float4 get_zxzw() { return {self->z,self->x,self->z,self->w}; }
	stdmath_float4 set_zxzw(stdmath_float4 value) { self->z = value.x; self->x = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_float4 zxwx;
	stdmath_float4 get_zxwx() { return {self->z,self->x,self->w,self->x}; }
	stdmath_float4 set_zxwx(stdmath_float4 value) { self->z = value.x; self->x = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_float4 zxwy;
	stdmath_float4 get_zxwy() { return {self->z,self->x,self->w,self->y}; }
	stdmath_float4 set_zxwy(stdmath_float4 value) { self->z = value.x; self->x = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_float4 zxwz;
	stdmath_float4 get_zxwz() { return {self->z,self->x,self->w,self->z}; }
	stdmath_float4 set_zxwz(stdmath_float4 value) { self->z = value.x; self->x = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_float4 zxww;
	stdmath_float4 get_zxww() { return {self->z,self->x,self->w,self->w}; }
	stdmath_float4 set_zxww(stdmath_float4 value) { self->z = value.x; self->x = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_float4 zyxx;
	stdmath_float4 get_zyxx() { return {self->z,self->y,self->x,self->x}; }
	stdmath_float4 set_zyxx(stdmath_float4 value) { self->z = value.x; self->y = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_float4 zyxy;
	stdmath_float4 get_zyxy() { return {self->z,self->y,self->x,self->y}; }
	stdmath_float4 set_zyxy(stdmath_float4 value) { self->z = value.x; self->y = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_float4 zyxz;
	stdmath_float4 get_zyxz() { return {self->z,self->y,self->x,self->z}; }
	stdmath_float4 set_zyxz(stdmath_float4 value) { self->z = value.x; self->y = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_float4 zyxw;
	stdmath_float4 get_zyxw() { return {self->z,self->y,self->x,self->w}; }
	stdmath_float4 set_zyxw(stdmath_float4 value) { self->z = value.x; self->y = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_float4 zyyx;
	stdmath_float4 get_zyyx() { return {self->z,self->y,self->y,self->x}; }
	stdmath_float4 set_zyyx(stdmath_float4 value) { self->z = value.x; self->y = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_float4 zyyy;
	stdmath_float4 get_zyyy() { return {self->z,self->y,self->y,self->y}; }
	stdmath_float4 set_zyyy(stdmath_float4 value) { self->z = value.x; self->y = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_float4 zyyz;
	stdmath_float4 get_zyyz() { return {self->z,self->y,self->y,self->z}; }
	stdmath_float4 set_zyyz(stdmath_float4 value) { self->z = value.x; self->y = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_float4 zyyw;
	stdmath_float4 get_zyyw() { return {self->z,self->y,self->y,self->w}; }
	stdmath_float4 set_zyyw(stdmath_float4 value) { self->z = value.x; self->y = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_float4 zyzx;
	stdmath_float4 get_zyzx() { return {self->z,self->y,self->z,self->x}; }
	stdmath_float4 set_zyzx(stdmath_float4 value) { self->z = value.x; self->y = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_float4 zyzy;
	stdmath_float4 get_zyzy() { return {self->z,self->y,self->z,self->y}; }
	stdmath_float4 set_zyzy(stdmath_float4 value) { self->z = value.x; self->y = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_float4 zyzz;
	stdmath_float4 get_zyzz() { return {self->z,self->y,self->z,self->z}; }
	stdmath_float4 set_zyzz(stdmath_float4 value) { self->z = value.x; self->y = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_float4 zyzw;
	stdmath_float4 get_zyzw() { return {self->z,self->y,self->z,self->w}; }
	stdmath_float4 set_zyzw(stdmath_float4 value) { self->z = value.x; self->y = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_float4 zywx;
	stdmath_float4 get_zywx() { return {self->z,self->y,self->w,self->x}; }
	stdmath_float4 set_zywx(stdmath_float4 value) { self->z = value.x; self->y = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_float4 zywy;
	stdmath_float4 get_zywy() { return {self->z,self->y,self->w,self->y}; }
	stdmath_float4 set_zywy(stdmath_float4 value) { self->z = value.x; self->y = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_float4 zywz;
	stdmath_float4 get_zywz() { return {self->z,self->y,self->w,self->z}; }
	stdmath_float4 set_zywz(stdmath_float4 value) { self->z = value.x; self->y = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_float4 zyww;
	stdmath_float4 get_zyww() { return {self->z,self->y,self->w,self->w}; }
	stdmath_float4 set_zyww(stdmath_float4 value) { self->z = value.x; self->y = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_float4 zzxx;
	stdmath_float4 get_zzxx() { return {self->z,self->z,self->x,self->x}; }
	stdmath_float4 set_zzxx(stdmath_float4 value) { self->z = value.x; self->z = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_float4 zzxy;
	stdmath_float4 get_zzxy() { return {self->z,self->z,self->x,self->y}; }
	stdmath_float4 set_zzxy(stdmath_float4 value) { self->z = value.x; self->z = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_float4 zzxz;
	stdmath_float4 get_zzxz() { return {self->z,self->z,self->x,self->z}; }
	stdmath_float4 set_zzxz(stdmath_float4 value) { self->z = value.x; self->z = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_float4 zzxw;
	stdmath_float4 get_zzxw() { return {self->z,self->z,self->x,self->w}; }
	stdmath_float4 set_zzxw(stdmath_float4 value) { self->z = value.x; self->z = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_float4 zzyx;
	stdmath_float4 get_zzyx() { return {self->z,self->z,self->y,self->x}; }
	stdmath_float4 set_zzyx(stdmath_float4 value) { self->z = value.x; self->z = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_float4 zzyy;
	stdmath_float4 get_zzyy() { return {self->z,self->z,self->y,self->y}; }
	stdmath_float4 set_zzyy(stdmath_float4 value) { self->z = value.x; self->z = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_float4 zzyz;
	stdmath_float4 get_zzyz() { return {self->z,self->z,self->y,self->z}; }
	stdmath_float4 set_zzyz(stdmath_float4 value) { self->z = value.x; self->z = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_float4 zzyw;
	stdmath_float4 get_zzyw() { return {self->z,self->z,self->y,self->w}; }
	stdmath_float4 set_zzyw(stdmath_float4 value) { self->z = value.x; self->z = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_float4 zzzx;
	stdmath_float4 get_zzzx() { return {self->z,self->z,self->z,self->x}; }
	stdmath_float4 set_zzzx(stdmath_float4 value) { self->z = value.x; self->z = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_float4 zzzy;
	stdmath_float4 get_zzzy() { return {self->z,self->z,self->z,self->y}; }
	stdmath_float4 set_zzzy(stdmath_float4 value) { self->z = value.x; self->z = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_float4 zzzz;
	stdmath_float4 get_zzzz() { return {self->z,self->z,self->z,self->z}; }
	stdmath_float4 set_zzzz(stdmath_float4 value) { self->z = value.x; self->z = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_float4 zzzw;
	stdmath_float4 get_zzzw() { return {self->z,self->z,self->z,self->w}; }
	stdmath_float4 set_zzzw(stdmath_float4 value) { self->z = value.x; self->z = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_float4 zzwx;
	stdmath_float4 get_zzwx() { return {self->z,self->z,self->w,self->x}; }
	stdmath_float4 set_zzwx(stdmath_float4 value) { self->z = value.x; self->z = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_float4 zzwy;
	stdmath_float4 get_zzwy() { return {self->z,self->z,self->w,self->y}; }
	stdmath_float4 set_zzwy(stdmath_float4 value) { self->z = value.x; self->z = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_float4 zzwz;
	stdmath_float4 get_zzwz() { return {self->z,self->z,self->w,self->z}; }
	stdmath_float4 set_zzwz(stdmath_float4 value) { self->z = value.x; self->z = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_float4 zzww;
	stdmath_float4 get_zzww() { return {self->z,self->z,self->w,self->w}; }
	stdmath_float4 set_zzww(stdmath_float4 value) { self->z = value.x; self->z = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_float4 zwxx;
	stdmath_float4 get_zwxx() { return {self->z,self->w,self->x,self->x}; }
	stdmath_float4 set_zwxx(stdmath_float4 value) { self->z = value.x; self->w = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_float4 zwxy;
	stdmath_float4 get_zwxy() { return {self->z,self->w,self->x,self->y}; }
	stdmath_float4 set_zwxy(stdmath_float4 value) { self->z = value.x; self->w = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_float4 zwxz;
	stdmath_float4 get_zwxz() { return {self->z,self->w,self->x,self->z}; }
	stdmath_float4 set_zwxz(stdmath_float4 value) { self->z = value.x; self->w = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_float4 zwxw;
	stdmath_float4 get_zwxw() { return {self->z,self->w,self->x,self->w}; }
	stdmath_float4 set_zwxw(stdmath_float4 value) { self->z = value.x; self->w = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_float4 zwyx;
	stdmath_float4 get_zwyx() { return {self->z,self->w,self->y,self->x}; }
	stdmath_float4 set_zwyx(stdmath_float4 value) { self->z = value.x; self->w = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_float4 zwyy;
	stdmath_float4 get_zwyy() { return {self->z,self->w,self->y,self->y}; }
	stdmath_float4 set_zwyy(stdmath_float4 value) { self->z = value.x; self->w = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_float4 zwyz;
	stdmath_float4 get_zwyz() { return {self->z,self->w,self->y,self->z}; }
	stdmath_float4 set_zwyz(stdmath_float4 value) { self->z = value.x; self->w = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_float4 zwyw;
	stdmath_float4 get_zwyw() { return {self->z,self->w,self->y,self->w}; }
	stdmath_float4 set_zwyw(stdmath_float4 value) { self->z = value.x; self->w = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_float4 zwzx;
	stdmath_float4 get_zwzx() { return {self->z,self->w,self->z,self->x}; }
	stdmath_float4 set_zwzx(stdmath_float4 value) { self->z = value.x; self->w = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_float4 zwzy;
	stdmath_float4 get_zwzy() { return {self->z,self->w,self->z,self->y}; }
	stdmath_float4 set_zwzy(stdmath_float4 value) { self->z = value.x; self->w = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_float4 zwzz;
	stdmath_float4 get_zwzz() { return {self->z,self->w,self->z,self->z}; }
	stdmath_float4 set_zwzz(stdmath_float4 value) { self->z = value.x; self->w = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_float4 zwzw;
	stdmath_float4 get_zwzw() { return {self->z,self->w,self->z,self->w}; }
	stdmath_float4 set_zwzw(stdmath_float4 value) { self->z = value.x; self->w = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_float4 zwwx;
	stdmath_float4 get_zwwx() { return {self->z,self->w,self->w,self->x}; }
	stdmath_float4 set_zwwx(stdmath_float4 value) { self->z = value.x; self->w = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_float4 zwwy;
	stdmath_float4 get_zwwy() { return {self->z,self->w,self->w,self->y}; }
	stdmath_float4 set_zwwy(stdmath_float4 value) { self->z = value.x; self->w = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_float4 zwwz;
	stdmath_float4 get_zwwz() { return {self->z,self->w,self->w,self->z}; }
	stdmath_float4 set_zwwz(stdmath_float4 value) { self->z = value.x; self->w = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_float4 zwww;
	stdmath_float4 get_zwww() { return {self->z,self->w,self->w,self->w}; }
	stdmath_float4 set_zwww(stdmath_float4 value) { self->z = value.x; self->w = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_float4 wxxx;
	stdmath_float4 get_wxxx() { return {self->w,self->x,self->x,self->x}; }
	stdmath_float4 set_wxxx(stdmath_float4 value) { self->w = value.x; self->x = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_float4 wxxy;
	stdmath_float4 get_wxxy() { return {self->w,self->x,self->x,self->y}; }
	stdmath_float4 set_wxxy(stdmath_float4 value) { self->w = value.x; self->x = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_float4 wxxz;
	stdmath_float4 get_wxxz() { return {self->w,self->x,self->x,self->z}; }
	stdmath_float4 set_wxxz(stdmath_float4 value) { self->w = value.x; self->x = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_float4 wxxw;
	stdmath_float4 get_wxxw() { return {self->w,self->x,self->x,self->w}; }
	stdmath_float4 set_wxxw(stdmath_float4 value) { self->w = value.x; self->x = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_float4 wxyx;
	stdmath_float4 get_wxyx() { return {self->w,self->x,self->y,self->x}; }
	stdmath_float4 set_wxyx(stdmath_float4 value) { self->w = value.x; self->x = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_float4 wxyy;
	stdmath_float4 get_wxyy() { return {self->w,self->x,self->y,self->y}; }
	stdmath_float4 set_wxyy(stdmath_float4 value) { self->w = value.x; self->x = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_float4 wxyz;
	stdmath_float4 get_wxyz() { return {self->w,self->x,self->y,self->z}; }
	stdmath_float4 set_wxyz(stdmath_float4 value) { self->w = value.x; self->x = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_float4 wxyw;
	stdmath_float4 get_wxyw() { return {self->w,self->x,self->y,self->w}; }
	stdmath_float4 set_wxyw(stdmath_float4 value) { self->w = value.x; self->x = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_float4 wxzx;
	stdmath_float4 get_wxzx() { return {self->w,self->x,self->z,self->x}; }
	stdmath_float4 set_wxzx(stdmath_float4 value) { self->w = value.x; self->x = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_float4 wxzy;
	stdmath_float4 get_wxzy() { return {self->w,self->x,self->z,self->y}; }
	stdmath_float4 set_wxzy(stdmath_float4 value) { self->w = value.x; self->x = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_float4 wxzz;
	stdmath_float4 get_wxzz() { return {self->w,self->x,self->z,self->z}; }
	stdmath_float4 set_wxzz(stdmath_float4 value) { self->w = value.x; self->x = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_float4 wxzw;
	stdmath_float4 get_wxzw() { return {self->w,self->x,self->z,self->w}; }
	stdmath_float4 set_wxzw(stdmath_float4 value) { self->w = value.x; self->x = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_float4 wxwx;
	stdmath_float4 get_wxwx() { return {self->w,self->x,self->w,self->x}; }
	stdmath_float4 set_wxwx(stdmath_float4 value) { self->w = value.x; self->x = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_float4 wxwy;
	stdmath_float4 get_wxwy() { return {self->w,self->x,self->w,self->y}; }
	stdmath_float4 set_wxwy(stdmath_float4 value) { self->w = value.x; self->x = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_float4 wxwz;
	stdmath_float4 get_wxwz() { return {self->w,self->x,self->w,self->z}; }
	stdmath_float4 set_wxwz(stdmath_float4 value) { self->w = value.x; self->x = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_float4 wxww;
	stdmath_float4 get_wxww() { return {self->w,self->x,self->w,self->w}; }
	stdmath_float4 set_wxww(stdmath_float4 value) { self->w = value.x; self->x = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_float4 wyxx;
	stdmath_float4 get_wyxx() { return {self->w,self->y,self->x,self->x}; }
	stdmath_float4 set_wyxx(stdmath_float4 value) { self->w = value.x; self->y = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_float4 wyxy;
	stdmath_float4 get_wyxy() { return {self->w,self->y,self->x,self->y}; }
	stdmath_float4 set_wyxy(stdmath_float4 value) { self->w = value.x; self->y = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_float4 wyxz;
	stdmath_float4 get_wyxz() { return {self->w,self->y,self->x,self->z}; }
	stdmath_float4 set_wyxz(stdmath_float4 value) { self->w = value.x; self->y = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_float4 wyxw;
	stdmath_float4 get_wyxw() { return {self->w,self->y,self->x,self->w}; }
	stdmath_float4 set_wyxw(stdmath_float4 value) { self->w = value.x; self->y = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_float4 wyyx;
	stdmath_float4 get_wyyx() { return {self->w,self->y,self->y,self->x}; }
	stdmath_float4 set_wyyx(stdmath_float4 value) { self->w = value.x; self->y = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_float4 wyyy;
	stdmath_float4 get_wyyy() { return {self->w,self->y,self->y,self->y}; }
	stdmath_float4 set_wyyy(stdmath_float4 value) { self->w = value.x; self->y = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_float4 wyyz;
	stdmath_float4 get_wyyz() { return {self->w,self->y,self->y,self->z}; }
	stdmath_float4 set_wyyz(stdmath_float4 value) { self->w = value.x; self->y = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_float4 wyyw;
	stdmath_float4 get_wyyw() { return {self->w,self->y,self->y,self->w}; }
	stdmath_float4 set_wyyw(stdmath_float4 value) { self->w = value.x; self->y = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_float4 wyzx;
	stdmath_float4 get_wyzx() { return {self->w,self->y,self->z,self->x}; }
	stdmath_float4 set_wyzx(stdmath_float4 value) { self->w = value.x; self->y = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_float4 wyzy;
	stdmath_float4 get_wyzy() { return {self->w,self->y,self->z,self->y}; }
	stdmath_float4 set_wyzy(stdmath_float4 value) { self->w = value.x; self->y = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_float4 wyzz;
	stdmath_float4 get_wyzz() { return {self->w,self->y,self->z,self->z}; }
	stdmath_float4 set_wyzz(stdmath_float4 value) { self->w = value.x; self->y = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_float4 wyzw;
	stdmath_float4 get_wyzw() { return {self->w,self->y,self->z,self->w}; }
	stdmath_float4 set_wyzw(stdmath_float4 value) { self->w = value.x; self->y = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_float4 wywx;
	stdmath_float4 get_wywx() { return {self->w,self->y,self->w,self->x}; }
	stdmath_float4 set_wywx(stdmath_float4 value) { self->w = value.x; self->y = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_float4 wywy;
	stdmath_float4 get_wywy() { return {self->w,self->y,self->w,self->y}; }
	stdmath_float4 set_wywy(stdmath_float4 value) { self->w = value.x; self->y = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_float4 wywz;
	stdmath_float4 get_wywz() { return {self->w,self->y,self->w,self->z}; }
	stdmath_float4 set_wywz(stdmath_float4 value) { self->w = value.x; self->y = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_float4 wyww;
	stdmath_float4 get_wyww() { return {self->w,self->y,self->w,self->w}; }
	stdmath_float4 set_wyww(stdmath_float4 value) { self->w = value.x; self->y = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_float4 wzxx;
	stdmath_float4 get_wzxx() { return {self->w,self->z,self->x,self->x}; }
	stdmath_float4 set_wzxx(stdmath_float4 value) { self->w = value.x; self->z = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_float4 wzxy;
	stdmath_float4 get_wzxy() { return {self->w,self->z,self->x,self->y}; }
	stdmath_float4 set_wzxy(stdmath_float4 value) { self->w = value.x; self->z = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_float4 wzxz;
	stdmath_float4 get_wzxz() { return {self->w,self->z,self->x,self->z}; }
	stdmath_float4 set_wzxz(stdmath_float4 value) { self->w = value.x; self->z = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_float4 wzxw;
	stdmath_float4 get_wzxw() { return {self->w,self->z,self->x,self->w}; }
	stdmath_float4 set_wzxw(stdmath_float4 value) { self->w = value.x; self->z = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_float4 wzyx;
	stdmath_float4 get_wzyx() { return {self->w,self->z,self->y,self->x}; }
	stdmath_float4 set_wzyx(stdmath_float4 value) { self->w = value.x; self->z = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_float4 wzyy;
	stdmath_float4 get_wzyy() { return {self->w,self->z,self->y,self->y}; }
	stdmath_float4 set_wzyy(stdmath_float4 value) { self->w = value.x; self->z = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_float4 wzyz;
	stdmath_float4 get_wzyz() { return {self->w,self->z,self->y,self->z}; }
	stdmath_float4 set_wzyz(stdmath_float4 value) { self->w = value.x; self->z = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_float4 wzyw;
	stdmath_float4 get_wzyw() { return {self->w,self->z,self->y,self->w}; }
	stdmath_float4 set_wzyw(stdmath_float4 value) { self->w = value.x; self->z = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_float4 wzzx;
	stdmath_float4 get_wzzx() { return {self->w,self->z,self->z,self->x}; }
	stdmath_float4 set_wzzx(stdmath_float4 value) { self->w = value.x; self->z = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_float4 wzzy;
	stdmath_float4 get_wzzy() { return {self->w,self->z,self->z,self->y}; }
	stdmath_float4 set_wzzy(stdmath_float4 value) { self->w = value.x; self->z = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_float4 wzzz;
	stdmath_float4 get_wzzz() { return {self->w,self->z,self->z,self->z}; }
	stdmath_float4 set_wzzz(stdmath_float4 value) { self->w = value.x; self->z = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_float4 wzzw;
	stdmath_float4 get_wzzw() { return {self->w,self->z,self->z,self->w}; }
	stdmath_float4 set_wzzw(stdmath_float4 value) { self->w = value.x; self->z = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_float4 wzwx;
	stdmath_float4 get_wzwx() { return {self->w,self->z,self->w,self->x}; }
	stdmath_float4 set_wzwx(stdmath_float4 value) { self->w = value.x; self->z = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_float4 wzwy;
	stdmath_float4 get_wzwy() { return {self->w,self->z,self->w,self->y}; }
	stdmath_float4 set_wzwy(stdmath_float4 value) { self->w = value.x; self->z = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_float4 wzwz;
	stdmath_float4 get_wzwz() { return {self->w,self->z,self->w,self->z}; }
	stdmath_float4 set_wzwz(stdmath_float4 value) { self->w = value.x; self->z = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_float4 wzww;
	stdmath_float4 get_wzww() { return {self->w,self->z,self->w,self->w}; }
	stdmath_float4 set_wzww(stdmath_float4 value) { self->w = value.x; self->z = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_float4 wwxx;
	stdmath_float4 get_wwxx() { return {self->w,self->w,self->x,self->x}; }
	stdmath_float4 set_wwxx(stdmath_float4 value) { self->w = value.x; self->w = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_float4 wwxy;
	stdmath_float4 get_wwxy() { return {self->w,self->w,self->x,self->y}; }
	stdmath_float4 set_wwxy(stdmath_float4 value) { self->w = value.x; self->w = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_float4 wwxz;
	stdmath_float4 get_wwxz() { return {self->w,self->w,self->x,self->z}; }
	stdmath_float4 set_wwxz(stdmath_float4 value) { self->w = value.x; self->w = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_float4 wwxw;
	stdmath_float4 get_wwxw() { return {self->w,self->w,self->x,self->w}; }
	stdmath_float4 set_wwxw(stdmath_float4 value) { self->w = value.x; self->w = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_float4 wwyx;
	stdmath_float4 get_wwyx() { return {self->w,self->w,self->y,self->x}; }
	stdmath_float4 set_wwyx(stdmath_float4 value) { self->w = value.x; self->w = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_float4 wwyy;
	stdmath_float4 get_wwyy() { return {self->w,self->w,self->y,self->y}; }
	stdmath_float4 set_wwyy(stdmath_float4 value) { self->w = value.x; self->w = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_float4 wwyz;
	stdmath_float4 get_wwyz() { return {self->w,self->w,self->y,self->z}; }
	stdmath_float4 set_wwyz(stdmath_float4 value) { self->w = value.x; self->w = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_float4 wwyw;
	stdmath_float4 get_wwyw() { return {self->w,self->w,self->y,self->w}; }
	stdmath_float4 set_wwyw(stdmath_float4 value) { self->w = value.x; self->w = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_float4 wwzx;
	stdmath_float4 get_wwzx() { return {self->w,self->w,self->z,self->x}; }
	stdmath_float4 set_wwzx(stdmath_float4 value) { self->w = value.x; self->w = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_float4 wwzy;
	stdmath_float4 get_wwzy() { return {self->w,self->w,self->z,self->y}; }
	stdmath_float4 set_wwzy(stdmath_float4 value) { self->w = value.x; self->w = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_float4 wwzz;
	stdmath_float4 get_wwzz() { return {self->w,self->w,self->z,self->z}; }
	stdmath_float4 set_wwzz(stdmath_float4 value) { self->w = value.x; self->w = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_float4 wwzw;
	stdmath_float4 get_wwzw() { return {self->w,self->w,self->z,self->w}; }
	stdmath_float4 set_wwzw(stdmath_float4 value) { self->w = value.x; self->w = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_float4 wwwx;
	stdmath_float4 get_wwwx() { return {self->w,self->w,self->w,self->x}; }
	stdmath_float4 set_wwwx(stdmath_float4 value) { self->w = value.x; self->w = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_float4 wwwy;
	stdmath_float4 get_wwwy() { return {self->w,self->w,self->w,self->y}; }
	stdmath_float4 set_wwwy(stdmath_float4 value) { self->w = value.x; self->w = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_float4 wwwz;
	stdmath_float4 get_wwwz() { return {self->w,self->w,self->w,self->z}; }
	stdmath_float4 set_wwwz(stdmath_float4 value) { self->w = value.x; self->w = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_float4 wwww;
	stdmath_float4 get_wwww() { return {self->w,self->w,self->w,self->w}; }
	stdmath_float4 set_wwww(stdmath_float4 value) { self->w = value.x; self->w = value.y; self->w = value.z; self->w = value.w; return *self; }



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

	bool4 _equal_to(stdmath_float4 o) {
		return stdmath_float4_equal_to(*self, o);
	}
	bool4 _not_equal_to(stdmath_float4 o) {
		return stdmath_float4_not_equal_to(*self, o);
	}
	bool4 _less_than(stdmath_float4 o) {
		return stdmath_float4_less_than(*self, o);
	}
	bool4 _less_than_or_equal_to(stdmath_float4 o) {
		return stdmath_float4_less_than_or_equal_to(*self, o);
	}
	bool4 _greater_than(stdmath_float4 o) {
		return stdmath_float4_greater_than(*self, o);
	}
	bool4 _greater_than_or_equal_to(stdmath_float4 o) {
		return stdmath_float4_greater_than_or_equal_to(*self, o);
	}
	
	float _length_squared() {
		return stdmath_float4_length_squared(*self);
	}
	float _length() {
		return stdmath_float4_length(*self);
	}
	float _dot() {
		return stdmath_float4_dot(*self);
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
	bool4 _approximately_equal(stdmath_float4 o) {
		return stdmath_float4_approximately_equal()
	}

#if false
	bool4 _all_of() {
		return bool4_all_of(*self);
	}
	bool4 _any_of() {
		return bool4_any_of(*self);
	}
	bool4 _none_of() {
		return bool4_none_of(*self);
	}
	bool4 _some_of() {
		return bool4_some_of(*self);
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
