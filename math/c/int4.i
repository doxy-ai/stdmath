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

	stdmath_int2 xx;
	stdmath_int2 get_xx() { return {self->x,self->x}; }
	stdmath_int4 set_xx(stdmath_int2 value) { self->x = value.x; self->x = value.y; return *self; }

	stdmath_int2 xy;
	stdmath_int2 get_xy() { return {self->x,self->y}; }
	stdmath_int4 set_xy(stdmath_int2 value) { self->x = value.x; self->y = value.y; return *self; }

	stdmath_int2 xz;
	stdmath_int2 get_xz() { return {self->x,self->z}; }
	stdmath_int4 set_xz(stdmath_int2 value) { self->x = value.x; self->z = value.y; return *self; }

	stdmath_int2 xw;
	stdmath_int2 get_xw() { return {self->x,self->w}; }
	stdmath_int4 set_xw(stdmath_int2 value) { self->x = value.x; self->w = value.y; return *self; }

	stdmath_int2 yx;
	stdmath_int2 get_yx() { return {self->y,self->x}; }
	stdmath_int4 set_yx(stdmath_int2 value) { self->y = value.x; self->x = value.y; return *self; }

	stdmath_int2 yy;
	stdmath_int2 get_yy() { return {self->y,self->y}; }
	stdmath_int4 set_yy(stdmath_int2 value) { self->y = value.x; self->y = value.y; return *self; }

	stdmath_int2 yz;
	stdmath_int2 get_yz() { return {self->y,self->z}; }
	stdmath_int4 set_yz(stdmath_int2 value) { self->y = value.x; self->z = value.y; return *self; }

	stdmath_int2 yw;
	stdmath_int2 get_yw() { return {self->y,self->w}; }
	stdmath_int4 set_yw(stdmath_int2 value) { self->y = value.x; self->w = value.y; return *self; }

	stdmath_int2 zx;
	stdmath_int2 get_zx() { return {self->z,self->x}; }
	stdmath_int4 set_zx(stdmath_int2 value) { self->z = value.x; self->x = value.y; return *self; }

	stdmath_int2 zy;
	stdmath_int2 get_zy() { return {self->z,self->y}; }
	stdmath_int4 set_zy(stdmath_int2 value) { self->z = value.x; self->y = value.y; return *self; }

	stdmath_int2 zz;
	stdmath_int2 get_zz() { return {self->z,self->z}; }
	stdmath_int4 set_zz(stdmath_int2 value) { self->z = value.x; self->z = value.y; return *self; }

	stdmath_int2 zw;
	stdmath_int2 get_zw() { return {self->z,self->w}; }
	stdmath_int4 set_zw(stdmath_int2 value) { self->z = value.x; self->w = value.y; return *self; }

	stdmath_int2 wx;
	stdmath_int2 get_wx() { return {self->w,self->x}; }
	stdmath_int4 set_wx(stdmath_int2 value) { self->w = value.x; self->x = value.y; return *self; }

	stdmath_int2 wy;
	stdmath_int2 get_wy() { return {self->w,self->y}; }
	stdmath_int4 set_wy(stdmath_int2 value) { self->w = value.x; self->y = value.y; return *self; }

	stdmath_int2 wz;
	stdmath_int2 get_wz() { return {self->w,self->z}; }
	stdmath_int4 set_wz(stdmath_int2 value) { self->w = value.x; self->z = value.y; return *self; }

	stdmath_int2 ww;
	stdmath_int2 get_ww() { return {self->w,self->w}; }
	stdmath_int4 set_ww(stdmath_int2 value) { self->w = value.x; self->w = value.y; return *self; }

	stdmath_int3 xxx;
	stdmath_int3 get_xxx() { return {self->x,self->x,self->x}; }
	stdmath_int4 set_xxx(stdmath_int3 value) { self->x = value.x; self->x = value.y; self->x = value.z; return *self; }

	stdmath_int3 xxy;
	stdmath_int3 get_xxy() { return {self->x,self->x,self->y}; }
	stdmath_int4 set_xxy(stdmath_int3 value) { self->x = value.x; self->x = value.y; self->y = value.z; return *self; }

	stdmath_int3 xxz;
	stdmath_int3 get_xxz() { return {self->x,self->x,self->z}; }
	stdmath_int4 set_xxz(stdmath_int3 value) { self->x = value.x; self->x = value.y; self->z = value.z; return *self; }

	stdmath_int3 xxw;
	stdmath_int3 get_xxw() { return {self->x,self->x,self->w}; }
	stdmath_int4 set_xxw(stdmath_int3 value) { self->x = value.x; self->x = value.y; self->w = value.z; return *self; }

	stdmath_int3 xyx;
	stdmath_int3 get_xyx() { return {self->x,self->y,self->x}; }
	stdmath_int4 set_xyx(stdmath_int3 value) { self->x = value.x; self->y = value.y; self->x = value.z; return *self; }

	stdmath_int3 xyy;
	stdmath_int3 get_xyy() { return {self->x,self->y,self->y}; }
	stdmath_int4 set_xyy(stdmath_int3 value) { self->x = value.x; self->y = value.y; self->y = value.z; return *self; }

	stdmath_int3 xyz;
	stdmath_int3 get_xyz() { return {self->x,self->y,self->z}; }
	stdmath_int4 set_xyz(stdmath_int3 value) { self->x = value.x; self->y = value.y; self->z = value.z; return *self; }

	stdmath_int3 xyw;
	stdmath_int3 get_xyw() { return {self->x,self->y,self->w}; }
	stdmath_int4 set_xyw(stdmath_int3 value) { self->x = value.x; self->y = value.y; self->w = value.z; return *self; }

	stdmath_int3 xzx;
	stdmath_int3 get_xzx() { return {self->x,self->z,self->x}; }
	stdmath_int4 set_xzx(stdmath_int3 value) { self->x = value.x; self->z = value.y; self->x = value.z; return *self; }

	stdmath_int3 xzy;
	stdmath_int3 get_xzy() { return {self->x,self->z,self->y}; }
	stdmath_int4 set_xzy(stdmath_int3 value) { self->x = value.x; self->z = value.y; self->y = value.z; return *self; }

	stdmath_int3 xzz;
	stdmath_int3 get_xzz() { return {self->x,self->z,self->z}; }
	stdmath_int4 set_xzz(stdmath_int3 value) { self->x = value.x; self->z = value.y; self->z = value.z; return *self; }

	stdmath_int3 xzw;
	stdmath_int3 get_xzw() { return {self->x,self->z,self->w}; }
	stdmath_int4 set_xzw(stdmath_int3 value) { self->x = value.x; self->z = value.y; self->w = value.z; return *self; }

	stdmath_int3 xwx;
	stdmath_int3 get_xwx() { return {self->x,self->w,self->x}; }
	stdmath_int4 set_xwx(stdmath_int3 value) { self->x = value.x; self->w = value.y; self->x = value.z; return *self; }

	stdmath_int3 xwy;
	stdmath_int3 get_xwy() { return {self->x,self->w,self->y}; }
	stdmath_int4 set_xwy(stdmath_int3 value) { self->x = value.x; self->w = value.y; self->y = value.z; return *self; }

	stdmath_int3 xwz;
	stdmath_int3 get_xwz() { return {self->x,self->w,self->z}; }
	stdmath_int4 set_xwz(stdmath_int3 value) { self->x = value.x; self->w = value.y; self->z = value.z; return *self; }

	stdmath_int3 xww;
	stdmath_int3 get_xww() { return {self->x,self->w,self->w}; }
	stdmath_int4 set_xww(stdmath_int3 value) { self->x = value.x; self->w = value.y; self->w = value.z; return *self; }

	stdmath_int3 yxx;
	stdmath_int3 get_yxx() { return {self->y,self->x,self->x}; }
	stdmath_int4 set_yxx(stdmath_int3 value) { self->y = value.x; self->x = value.y; self->x = value.z; return *self; }

	stdmath_int3 yxy;
	stdmath_int3 get_yxy() { return {self->y,self->x,self->y}; }
	stdmath_int4 set_yxy(stdmath_int3 value) { self->y = value.x; self->x = value.y; self->y = value.z; return *self; }

	stdmath_int3 yxz;
	stdmath_int3 get_yxz() { return {self->y,self->x,self->z}; }
	stdmath_int4 set_yxz(stdmath_int3 value) { self->y = value.x; self->x = value.y; self->z = value.z; return *self; }

	stdmath_int3 yxw;
	stdmath_int3 get_yxw() { return {self->y,self->x,self->w}; }
	stdmath_int4 set_yxw(stdmath_int3 value) { self->y = value.x; self->x = value.y; self->w = value.z; return *self; }

	stdmath_int3 yyx;
	stdmath_int3 get_yyx() { return {self->y,self->y,self->x}; }
	stdmath_int4 set_yyx(stdmath_int3 value) { self->y = value.x; self->y = value.y; self->x = value.z; return *self; }

	stdmath_int3 yyy;
	stdmath_int3 get_yyy() { return {self->y,self->y,self->y}; }
	stdmath_int4 set_yyy(stdmath_int3 value) { self->y = value.x; self->y = value.y; self->y = value.z; return *self; }

	stdmath_int3 yyz;
	stdmath_int3 get_yyz() { return {self->y,self->y,self->z}; }
	stdmath_int4 set_yyz(stdmath_int3 value) { self->y = value.x; self->y = value.y; self->z = value.z; return *self; }

	stdmath_int3 yyw;
	stdmath_int3 get_yyw() { return {self->y,self->y,self->w}; }
	stdmath_int4 set_yyw(stdmath_int3 value) { self->y = value.x; self->y = value.y; self->w = value.z; return *self; }

	stdmath_int3 yzx;
	stdmath_int3 get_yzx() { return {self->y,self->z,self->x}; }
	stdmath_int4 set_yzx(stdmath_int3 value) { self->y = value.x; self->z = value.y; self->x = value.z; return *self; }

	stdmath_int3 yzy;
	stdmath_int3 get_yzy() { return {self->y,self->z,self->y}; }
	stdmath_int4 set_yzy(stdmath_int3 value) { self->y = value.x; self->z = value.y; self->y = value.z; return *self; }

	stdmath_int3 yzz;
	stdmath_int3 get_yzz() { return {self->y,self->z,self->z}; }
	stdmath_int4 set_yzz(stdmath_int3 value) { self->y = value.x; self->z = value.y; self->z = value.z; return *self; }

	stdmath_int3 yzw;
	stdmath_int3 get_yzw() { return {self->y,self->z,self->w}; }
	stdmath_int4 set_yzw(stdmath_int3 value) { self->y = value.x; self->z = value.y; self->w = value.z; return *self; }

	stdmath_int3 ywx;
	stdmath_int3 get_ywx() { return {self->y,self->w,self->x}; }
	stdmath_int4 set_ywx(stdmath_int3 value) { self->y = value.x; self->w = value.y; self->x = value.z; return *self; }

	stdmath_int3 ywy;
	stdmath_int3 get_ywy() { return {self->y,self->w,self->y}; }
	stdmath_int4 set_ywy(stdmath_int3 value) { self->y = value.x; self->w = value.y; self->y = value.z; return *self; }

	stdmath_int3 ywz;
	stdmath_int3 get_ywz() { return {self->y,self->w,self->z}; }
	stdmath_int4 set_ywz(stdmath_int3 value) { self->y = value.x; self->w = value.y; self->z = value.z; return *self; }

	stdmath_int3 yww;
	stdmath_int3 get_yww() { return {self->y,self->w,self->w}; }
	stdmath_int4 set_yww(stdmath_int3 value) { self->y = value.x; self->w = value.y; self->w = value.z; return *self; }

	stdmath_int3 zxx;
	stdmath_int3 get_zxx() { return {self->z,self->x,self->x}; }
	stdmath_int4 set_zxx(stdmath_int3 value) { self->z = value.x; self->x = value.y; self->x = value.z; return *self; }

	stdmath_int3 zxy;
	stdmath_int3 get_zxy() { return {self->z,self->x,self->y}; }
	stdmath_int4 set_zxy(stdmath_int3 value) { self->z = value.x; self->x = value.y; self->y = value.z; return *self; }

	stdmath_int3 zxz;
	stdmath_int3 get_zxz() { return {self->z,self->x,self->z}; }
	stdmath_int4 set_zxz(stdmath_int3 value) { self->z = value.x; self->x = value.y; self->z = value.z; return *self; }

	stdmath_int3 zxw;
	stdmath_int3 get_zxw() { return {self->z,self->x,self->w}; }
	stdmath_int4 set_zxw(stdmath_int3 value) { self->z = value.x; self->x = value.y; self->w = value.z; return *self; }

	stdmath_int3 zyx;
	stdmath_int3 get_zyx() { return {self->z,self->y,self->x}; }
	stdmath_int4 set_zyx(stdmath_int3 value) { self->z = value.x; self->y = value.y; self->x = value.z; return *self; }

	stdmath_int3 zyy;
	stdmath_int3 get_zyy() { return {self->z,self->y,self->y}; }
	stdmath_int4 set_zyy(stdmath_int3 value) { self->z = value.x; self->y = value.y; self->y = value.z; return *self; }

	stdmath_int3 zyz;
	stdmath_int3 get_zyz() { return {self->z,self->y,self->z}; }
	stdmath_int4 set_zyz(stdmath_int3 value) { self->z = value.x; self->y = value.y; self->z = value.z; return *self; }

	stdmath_int3 zyw;
	stdmath_int3 get_zyw() { return {self->z,self->y,self->w}; }
	stdmath_int4 set_zyw(stdmath_int3 value) { self->z = value.x; self->y = value.y; self->w = value.z; return *self; }

	stdmath_int3 zzx;
	stdmath_int3 get_zzx() { return {self->z,self->z,self->x}; }
	stdmath_int4 set_zzx(stdmath_int3 value) { self->z = value.x; self->z = value.y; self->x = value.z; return *self; }

	stdmath_int3 zzy;
	stdmath_int3 get_zzy() { return {self->z,self->z,self->y}; }
	stdmath_int4 set_zzy(stdmath_int3 value) { self->z = value.x; self->z = value.y; self->y = value.z; return *self; }

	stdmath_int3 zzz;
	stdmath_int3 get_zzz() { return {self->z,self->z,self->z}; }
	stdmath_int4 set_zzz(stdmath_int3 value) { self->z = value.x; self->z = value.y; self->z = value.z; return *self; }

	stdmath_int3 zzw;
	stdmath_int3 get_zzw() { return {self->z,self->z,self->w}; }
	stdmath_int4 set_zzw(stdmath_int3 value) { self->z = value.x; self->z = value.y; self->w = value.z; return *self; }

	stdmath_int3 zwx;
	stdmath_int3 get_zwx() { return {self->z,self->w,self->x}; }
	stdmath_int4 set_zwx(stdmath_int3 value) { self->z = value.x; self->w = value.y; self->x = value.z; return *self; }

	stdmath_int3 zwy;
	stdmath_int3 get_zwy() { return {self->z,self->w,self->y}; }
	stdmath_int4 set_zwy(stdmath_int3 value) { self->z = value.x; self->w = value.y; self->y = value.z; return *self; }

	stdmath_int3 zwz;
	stdmath_int3 get_zwz() { return {self->z,self->w,self->z}; }
	stdmath_int4 set_zwz(stdmath_int3 value) { self->z = value.x; self->w = value.y; self->z = value.z; return *self; }

	stdmath_int3 zww;
	stdmath_int3 get_zww() { return {self->z,self->w,self->w}; }
	stdmath_int4 set_zww(stdmath_int3 value) { self->z = value.x; self->w = value.y; self->w = value.z; return *self; }

	stdmath_int3 wxx;
	stdmath_int3 get_wxx() { return {self->w,self->x,self->x}; }
	stdmath_int4 set_wxx(stdmath_int3 value) { self->w = value.x; self->x = value.y; self->x = value.z; return *self; }

	stdmath_int3 wxy;
	stdmath_int3 get_wxy() { return {self->w,self->x,self->y}; }
	stdmath_int4 set_wxy(stdmath_int3 value) { self->w = value.x; self->x = value.y; self->y = value.z; return *self; }

	stdmath_int3 wxz;
	stdmath_int3 get_wxz() { return {self->w,self->x,self->z}; }
	stdmath_int4 set_wxz(stdmath_int3 value) { self->w = value.x; self->x = value.y; self->z = value.z; return *self; }

	stdmath_int3 wxw;
	stdmath_int3 get_wxw() { return {self->w,self->x,self->w}; }
	stdmath_int4 set_wxw(stdmath_int3 value) { self->w = value.x; self->x = value.y; self->w = value.z; return *self; }

	stdmath_int3 wyx;
	stdmath_int3 get_wyx() { return {self->w,self->y,self->x}; }
	stdmath_int4 set_wyx(stdmath_int3 value) { self->w = value.x; self->y = value.y; self->x = value.z; return *self; }

	stdmath_int3 wyy;
	stdmath_int3 get_wyy() { return {self->w,self->y,self->y}; }
	stdmath_int4 set_wyy(stdmath_int3 value) { self->w = value.x; self->y = value.y; self->y = value.z; return *self; }

	stdmath_int3 wyz;
	stdmath_int3 get_wyz() { return {self->w,self->y,self->z}; }
	stdmath_int4 set_wyz(stdmath_int3 value) { self->w = value.x; self->y = value.y; self->z = value.z; return *self; }

	stdmath_int3 wyw;
	stdmath_int3 get_wyw() { return {self->w,self->y,self->w}; }
	stdmath_int4 set_wyw(stdmath_int3 value) { self->w = value.x; self->y = value.y; self->w = value.z; return *self; }

	stdmath_int3 wzx;
	stdmath_int3 get_wzx() { return {self->w,self->z,self->x}; }
	stdmath_int4 set_wzx(stdmath_int3 value) { self->w = value.x; self->z = value.y; self->x = value.z; return *self; }

	stdmath_int3 wzy;
	stdmath_int3 get_wzy() { return {self->w,self->z,self->y}; }
	stdmath_int4 set_wzy(stdmath_int3 value) { self->w = value.x; self->z = value.y; self->y = value.z; return *self; }

	stdmath_int3 wzz;
	stdmath_int3 get_wzz() { return {self->w,self->z,self->z}; }
	stdmath_int4 set_wzz(stdmath_int3 value) { self->w = value.x; self->z = value.y; self->z = value.z; return *self; }

	stdmath_int3 wzw;
	stdmath_int3 get_wzw() { return {self->w,self->z,self->w}; }
	stdmath_int4 set_wzw(stdmath_int3 value) { self->w = value.x; self->z = value.y; self->w = value.z; return *self; }

	stdmath_int3 wwx;
	stdmath_int3 get_wwx() { return {self->w,self->w,self->x}; }
	stdmath_int4 set_wwx(stdmath_int3 value) { self->w = value.x; self->w = value.y; self->x = value.z; return *self; }

	stdmath_int3 wwy;
	stdmath_int3 get_wwy() { return {self->w,self->w,self->y}; }
	stdmath_int4 set_wwy(stdmath_int3 value) { self->w = value.x; self->w = value.y; self->y = value.z; return *self; }

	stdmath_int3 wwz;
	stdmath_int3 get_wwz() { return {self->w,self->w,self->z}; }
	stdmath_int4 set_wwz(stdmath_int3 value) { self->w = value.x; self->w = value.y; self->z = value.z; return *self; }

	stdmath_int3 www;
	stdmath_int3 get_www() { return {self->w,self->w,self->w}; }
	stdmath_int4 set_www(stdmath_int3 value) { self->w = value.x; self->w = value.y; self->w = value.z; return *self; }

	stdmath_int4 xxxx;
	stdmath_int4 get_xxxx() { return {self->x,self->x,self->x,self->x}; }
	stdmath_int4 set_xxxx(stdmath_int4 value) { self->x = value.x; self->x = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_int4 xxxy;
	stdmath_int4 get_xxxy() { return {self->x,self->x,self->x,self->y}; }
	stdmath_int4 set_xxxy(stdmath_int4 value) { self->x = value.x; self->x = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_int4 xxxz;
	stdmath_int4 get_xxxz() { return {self->x,self->x,self->x,self->z}; }
	stdmath_int4 set_xxxz(stdmath_int4 value) { self->x = value.x; self->x = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_int4 xxxw;
	stdmath_int4 get_xxxw() { return {self->x,self->x,self->x,self->w}; }
	stdmath_int4 set_xxxw(stdmath_int4 value) { self->x = value.x; self->x = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_int4 xxyx;
	stdmath_int4 get_xxyx() { return {self->x,self->x,self->y,self->x}; }
	stdmath_int4 set_xxyx(stdmath_int4 value) { self->x = value.x; self->x = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_int4 xxyy;
	stdmath_int4 get_xxyy() { return {self->x,self->x,self->y,self->y}; }
	stdmath_int4 set_xxyy(stdmath_int4 value) { self->x = value.x; self->x = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_int4 xxyz;
	stdmath_int4 get_xxyz() { return {self->x,self->x,self->y,self->z}; }
	stdmath_int4 set_xxyz(stdmath_int4 value) { self->x = value.x; self->x = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_int4 xxyw;
	stdmath_int4 get_xxyw() { return {self->x,self->x,self->y,self->w}; }
	stdmath_int4 set_xxyw(stdmath_int4 value) { self->x = value.x; self->x = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_int4 xxzx;
	stdmath_int4 get_xxzx() { return {self->x,self->x,self->z,self->x}; }
	stdmath_int4 set_xxzx(stdmath_int4 value) { self->x = value.x; self->x = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_int4 xxzy;
	stdmath_int4 get_xxzy() { return {self->x,self->x,self->z,self->y}; }
	stdmath_int4 set_xxzy(stdmath_int4 value) { self->x = value.x; self->x = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_int4 xxzz;
	stdmath_int4 get_xxzz() { return {self->x,self->x,self->z,self->z}; }
	stdmath_int4 set_xxzz(stdmath_int4 value) { self->x = value.x; self->x = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_int4 xxzw;
	stdmath_int4 get_xxzw() { return {self->x,self->x,self->z,self->w}; }
	stdmath_int4 set_xxzw(stdmath_int4 value) { self->x = value.x; self->x = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_int4 xxwx;
	stdmath_int4 get_xxwx() { return {self->x,self->x,self->w,self->x}; }
	stdmath_int4 set_xxwx(stdmath_int4 value) { self->x = value.x; self->x = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_int4 xxwy;
	stdmath_int4 get_xxwy() { return {self->x,self->x,self->w,self->y}; }
	stdmath_int4 set_xxwy(stdmath_int4 value) { self->x = value.x; self->x = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_int4 xxwz;
	stdmath_int4 get_xxwz() { return {self->x,self->x,self->w,self->z}; }
	stdmath_int4 set_xxwz(stdmath_int4 value) { self->x = value.x; self->x = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_int4 xxww;
	stdmath_int4 get_xxww() { return {self->x,self->x,self->w,self->w}; }
	stdmath_int4 set_xxww(stdmath_int4 value) { self->x = value.x; self->x = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_int4 xyxx;
	stdmath_int4 get_xyxx() { return {self->x,self->y,self->x,self->x}; }
	stdmath_int4 set_xyxx(stdmath_int4 value) { self->x = value.x; self->y = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_int4 xyxy;
	stdmath_int4 get_xyxy() { return {self->x,self->y,self->x,self->y}; }
	stdmath_int4 set_xyxy(stdmath_int4 value) { self->x = value.x; self->y = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_int4 xyxz;
	stdmath_int4 get_xyxz() { return {self->x,self->y,self->x,self->z}; }
	stdmath_int4 set_xyxz(stdmath_int4 value) { self->x = value.x; self->y = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_int4 xyxw;
	stdmath_int4 get_xyxw() { return {self->x,self->y,self->x,self->w}; }
	stdmath_int4 set_xyxw(stdmath_int4 value) { self->x = value.x; self->y = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_int4 xyyx;
	stdmath_int4 get_xyyx() { return {self->x,self->y,self->y,self->x}; }
	stdmath_int4 set_xyyx(stdmath_int4 value) { self->x = value.x; self->y = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_int4 xyyy;
	stdmath_int4 get_xyyy() { return {self->x,self->y,self->y,self->y}; }
	stdmath_int4 set_xyyy(stdmath_int4 value) { self->x = value.x; self->y = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_int4 xyyz;
	stdmath_int4 get_xyyz() { return {self->x,self->y,self->y,self->z}; }
	stdmath_int4 set_xyyz(stdmath_int4 value) { self->x = value.x; self->y = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_int4 xyyw;
	stdmath_int4 get_xyyw() { return {self->x,self->y,self->y,self->w}; }
	stdmath_int4 set_xyyw(stdmath_int4 value) { self->x = value.x; self->y = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_int4 xyzx;
	stdmath_int4 get_xyzx() { return {self->x,self->y,self->z,self->x}; }
	stdmath_int4 set_xyzx(stdmath_int4 value) { self->x = value.x; self->y = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_int4 xyzy;
	stdmath_int4 get_xyzy() { return {self->x,self->y,self->z,self->y}; }
	stdmath_int4 set_xyzy(stdmath_int4 value) { self->x = value.x; self->y = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_int4 xyzz;
	stdmath_int4 get_xyzz() { return {self->x,self->y,self->z,self->z}; }
	stdmath_int4 set_xyzz(stdmath_int4 value) { self->x = value.x; self->y = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_int4 xyzw;
	stdmath_int4 get_xyzw() { return {self->x,self->y,self->z,self->w}; }
	stdmath_int4 set_xyzw(stdmath_int4 value) { self->x = value.x; self->y = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_int4 xywx;
	stdmath_int4 get_xywx() { return {self->x,self->y,self->w,self->x}; }
	stdmath_int4 set_xywx(stdmath_int4 value) { self->x = value.x; self->y = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_int4 xywy;
	stdmath_int4 get_xywy() { return {self->x,self->y,self->w,self->y}; }
	stdmath_int4 set_xywy(stdmath_int4 value) { self->x = value.x; self->y = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_int4 xywz;
	stdmath_int4 get_xywz() { return {self->x,self->y,self->w,self->z}; }
	stdmath_int4 set_xywz(stdmath_int4 value) { self->x = value.x; self->y = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_int4 xyww;
	stdmath_int4 get_xyww() { return {self->x,self->y,self->w,self->w}; }
	stdmath_int4 set_xyww(stdmath_int4 value) { self->x = value.x; self->y = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_int4 xzxx;
	stdmath_int4 get_xzxx() { return {self->x,self->z,self->x,self->x}; }
	stdmath_int4 set_xzxx(stdmath_int4 value) { self->x = value.x; self->z = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_int4 xzxy;
	stdmath_int4 get_xzxy() { return {self->x,self->z,self->x,self->y}; }
	stdmath_int4 set_xzxy(stdmath_int4 value) { self->x = value.x; self->z = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_int4 xzxz;
	stdmath_int4 get_xzxz() { return {self->x,self->z,self->x,self->z}; }
	stdmath_int4 set_xzxz(stdmath_int4 value) { self->x = value.x; self->z = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_int4 xzxw;
	stdmath_int4 get_xzxw() { return {self->x,self->z,self->x,self->w}; }
	stdmath_int4 set_xzxw(stdmath_int4 value) { self->x = value.x; self->z = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_int4 xzyx;
	stdmath_int4 get_xzyx() { return {self->x,self->z,self->y,self->x}; }
	stdmath_int4 set_xzyx(stdmath_int4 value) { self->x = value.x; self->z = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_int4 xzyy;
	stdmath_int4 get_xzyy() { return {self->x,self->z,self->y,self->y}; }
	stdmath_int4 set_xzyy(stdmath_int4 value) { self->x = value.x; self->z = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_int4 xzyz;
	stdmath_int4 get_xzyz() { return {self->x,self->z,self->y,self->z}; }
	stdmath_int4 set_xzyz(stdmath_int4 value) { self->x = value.x; self->z = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_int4 xzyw;
	stdmath_int4 get_xzyw() { return {self->x,self->z,self->y,self->w}; }
	stdmath_int4 set_xzyw(stdmath_int4 value) { self->x = value.x; self->z = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_int4 xzzx;
	stdmath_int4 get_xzzx() { return {self->x,self->z,self->z,self->x}; }
	stdmath_int4 set_xzzx(stdmath_int4 value) { self->x = value.x; self->z = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_int4 xzzy;
	stdmath_int4 get_xzzy() { return {self->x,self->z,self->z,self->y}; }
	stdmath_int4 set_xzzy(stdmath_int4 value) { self->x = value.x; self->z = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_int4 xzzz;
	stdmath_int4 get_xzzz() { return {self->x,self->z,self->z,self->z}; }
	stdmath_int4 set_xzzz(stdmath_int4 value) { self->x = value.x; self->z = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_int4 xzzw;
	stdmath_int4 get_xzzw() { return {self->x,self->z,self->z,self->w}; }
	stdmath_int4 set_xzzw(stdmath_int4 value) { self->x = value.x; self->z = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_int4 xzwx;
	stdmath_int4 get_xzwx() { return {self->x,self->z,self->w,self->x}; }
	stdmath_int4 set_xzwx(stdmath_int4 value) { self->x = value.x; self->z = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_int4 xzwy;
	stdmath_int4 get_xzwy() { return {self->x,self->z,self->w,self->y}; }
	stdmath_int4 set_xzwy(stdmath_int4 value) { self->x = value.x; self->z = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_int4 xzwz;
	stdmath_int4 get_xzwz() { return {self->x,self->z,self->w,self->z}; }
	stdmath_int4 set_xzwz(stdmath_int4 value) { self->x = value.x; self->z = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_int4 xzww;
	stdmath_int4 get_xzww() { return {self->x,self->z,self->w,self->w}; }
	stdmath_int4 set_xzww(stdmath_int4 value) { self->x = value.x; self->z = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_int4 xwxx;
	stdmath_int4 get_xwxx() { return {self->x,self->w,self->x,self->x}; }
	stdmath_int4 set_xwxx(stdmath_int4 value) { self->x = value.x; self->w = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_int4 xwxy;
	stdmath_int4 get_xwxy() { return {self->x,self->w,self->x,self->y}; }
	stdmath_int4 set_xwxy(stdmath_int4 value) { self->x = value.x; self->w = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_int4 xwxz;
	stdmath_int4 get_xwxz() { return {self->x,self->w,self->x,self->z}; }
	stdmath_int4 set_xwxz(stdmath_int4 value) { self->x = value.x; self->w = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_int4 xwxw;
	stdmath_int4 get_xwxw() { return {self->x,self->w,self->x,self->w}; }
	stdmath_int4 set_xwxw(stdmath_int4 value) { self->x = value.x; self->w = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_int4 xwyx;
	stdmath_int4 get_xwyx() { return {self->x,self->w,self->y,self->x}; }
	stdmath_int4 set_xwyx(stdmath_int4 value) { self->x = value.x; self->w = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_int4 xwyy;
	stdmath_int4 get_xwyy() { return {self->x,self->w,self->y,self->y}; }
	stdmath_int4 set_xwyy(stdmath_int4 value) { self->x = value.x; self->w = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_int4 xwyz;
	stdmath_int4 get_xwyz() { return {self->x,self->w,self->y,self->z}; }
	stdmath_int4 set_xwyz(stdmath_int4 value) { self->x = value.x; self->w = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_int4 xwyw;
	stdmath_int4 get_xwyw() { return {self->x,self->w,self->y,self->w}; }
	stdmath_int4 set_xwyw(stdmath_int4 value) { self->x = value.x; self->w = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_int4 xwzx;
	stdmath_int4 get_xwzx() { return {self->x,self->w,self->z,self->x}; }
	stdmath_int4 set_xwzx(stdmath_int4 value) { self->x = value.x; self->w = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_int4 xwzy;
	stdmath_int4 get_xwzy() { return {self->x,self->w,self->z,self->y}; }
	stdmath_int4 set_xwzy(stdmath_int4 value) { self->x = value.x; self->w = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_int4 xwzz;
	stdmath_int4 get_xwzz() { return {self->x,self->w,self->z,self->z}; }
	stdmath_int4 set_xwzz(stdmath_int4 value) { self->x = value.x; self->w = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_int4 xwzw;
	stdmath_int4 get_xwzw() { return {self->x,self->w,self->z,self->w}; }
	stdmath_int4 set_xwzw(stdmath_int4 value) { self->x = value.x; self->w = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_int4 xwwx;
	stdmath_int4 get_xwwx() { return {self->x,self->w,self->w,self->x}; }
	stdmath_int4 set_xwwx(stdmath_int4 value) { self->x = value.x; self->w = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_int4 xwwy;
	stdmath_int4 get_xwwy() { return {self->x,self->w,self->w,self->y}; }
	stdmath_int4 set_xwwy(stdmath_int4 value) { self->x = value.x; self->w = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_int4 xwwz;
	stdmath_int4 get_xwwz() { return {self->x,self->w,self->w,self->z}; }
	stdmath_int4 set_xwwz(stdmath_int4 value) { self->x = value.x; self->w = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_int4 xwww;
	stdmath_int4 get_xwww() { return {self->x,self->w,self->w,self->w}; }
	stdmath_int4 set_xwww(stdmath_int4 value) { self->x = value.x; self->w = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_int4 yxxx;
	stdmath_int4 get_yxxx() { return {self->y,self->x,self->x,self->x}; }
	stdmath_int4 set_yxxx(stdmath_int4 value) { self->y = value.x; self->x = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_int4 yxxy;
	stdmath_int4 get_yxxy() { return {self->y,self->x,self->x,self->y}; }
	stdmath_int4 set_yxxy(stdmath_int4 value) { self->y = value.x; self->x = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_int4 yxxz;
	stdmath_int4 get_yxxz() { return {self->y,self->x,self->x,self->z}; }
	stdmath_int4 set_yxxz(stdmath_int4 value) { self->y = value.x; self->x = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_int4 yxxw;
	stdmath_int4 get_yxxw() { return {self->y,self->x,self->x,self->w}; }
	stdmath_int4 set_yxxw(stdmath_int4 value) { self->y = value.x; self->x = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_int4 yxyx;
	stdmath_int4 get_yxyx() { return {self->y,self->x,self->y,self->x}; }
	stdmath_int4 set_yxyx(stdmath_int4 value) { self->y = value.x; self->x = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_int4 yxyy;
	stdmath_int4 get_yxyy() { return {self->y,self->x,self->y,self->y}; }
	stdmath_int4 set_yxyy(stdmath_int4 value) { self->y = value.x; self->x = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_int4 yxyz;
	stdmath_int4 get_yxyz() { return {self->y,self->x,self->y,self->z}; }
	stdmath_int4 set_yxyz(stdmath_int4 value) { self->y = value.x; self->x = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_int4 yxyw;
	stdmath_int4 get_yxyw() { return {self->y,self->x,self->y,self->w}; }
	stdmath_int4 set_yxyw(stdmath_int4 value) { self->y = value.x; self->x = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_int4 yxzx;
	stdmath_int4 get_yxzx() { return {self->y,self->x,self->z,self->x}; }
	stdmath_int4 set_yxzx(stdmath_int4 value) { self->y = value.x; self->x = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_int4 yxzy;
	stdmath_int4 get_yxzy() { return {self->y,self->x,self->z,self->y}; }
	stdmath_int4 set_yxzy(stdmath_int4 value) { self->y = value.x; self->x = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_int4 yxzz;
	stdmath_int4 get_yxzz() { return {self->y,self->x,self->z,self->z}; }
	stdmath_int4 set_yxzz(stdmath_int4 value) { self->y = value.x; self->x = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_int4 yxzw;
	stdmath_int4 get_yxzw() { return {self->y,self->x,self->z,self->w}; }
	stdmath_int4 set_yxzw(stdmath_int4 value) { self->y = value.x; self->x = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_int4 yxwx;
	stdmath_int4 get_yxwx() { return {self->y,self->x,self->w,self->x}; }
	stdmath_int4 set_yxwx(stdmath_int4 value) { self->y = value.x; self->x = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_int4 yxwy;
	stdmath_int4 get_yxwy() { return {self->y,self->x,self->w,self->y}; }
	stdmath_int4 set_yxwy(stdmath_int4 value) { self->y = value.x; self->x = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_int4 yxwz;
	stdmath_int4 get_yxwz() { return {self->y,self->x,self->w,self->z}; }
	stdmath_int4 set_yxwz(stdmath_int4 value) { self->y = value.x; self->x = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_int4 yxww;
	stdmath_int4 get_yxww() { return {self->y,self->x,self->w,self->w}; }
	stdmath_int4 set_yxww(stdmath_int4 value) { self->y = value.x; self->x = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_int4 yyxx;
	stdmath_int4 get_yyxx() { return {self->y,self->y,self->x,self->x}; }
	stdmath_int4 set_yyxx(stdmath_int4 value) { self->y = value.x; self->y = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_int4 yyxy;
	stdmath_int4 get_yyxy() { return {self->y,self->y,self->x,self->y}; }
	stdmath_int4 set_yyxy(stdmath_int4 value) { self->y = value.x; self->y = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_int4 yyxz;
	stdmath_int4 get_yyxz() { return {self->y,self->y,self->x,self->z}; }
	stdmath_int4 set_yyxz(stdmath_int4 value) { self->y = value.x; self->y = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_int4 yyxw;
	stdmath_int4 get_yyxw() { return {self->y,self->y,self->x,self->w}; }
	stdmath_int4 set_yyxw(stdmath_int4 value) { self->y = value.x; self->y = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_int4 yyyx;
	stdmath_int4 get_yyyx() { return {self->y,self->y,self->y,self->x}; }
	stdmath_int4 set_yyyx(stdmath_int4 value) { self->y = value.x; self->y = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_int4 yyyy;
	stdmath_int4 get_yyyy() { return {self->y,self->y,self->y,self->y}; }
	stdmath_int4 set_yyyy(stdmath_int4 value) { self->y = value.x; self->y = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_int4 yyyz;
	stdmath_int4 get_yyyz() { return {self->y,self->y,self->y,self->z}; }
	stdmath_int4 set_yyyz(stdmath_int4 value) { self->y = value.x; self->y = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_int4 yyyw;
	stdmath_int4 get_yyyw() { return {self->y,self->y,self->y,self->w}; }
	stdmath_int4 set_yyyw(stdmath_int4 value) { self->y = value.x; self->y = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_int4 yyzx;
	stdmath_int4 get_yyzx() { return {self->y,self->y,self->z,self->x}; }
	stdmath_int4 set_yyzx(stdmath_int4 value) { self->y = value.x; self->y = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_int4 yyzy;
	stdmath_int4 get_yyzy() { return {self->y,self->y,self->z,self->y}; }
	stdmath_int4 set_yyzy(stdmath_int4 value) { self->y = value.x; self->y = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_int4 yyzz;
	stdmath_int4 get_yyzz() { return {self->y,self->y,self->z,self->z}; }
	stdmath_int4 set_yyzz(stdmath_int4 value) { self->y = value.x; self->y = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_int4 yyzw;
	stdmath_int4 get_yyzw() { return {self->y,self->y,self->z,self->w}; }
	stdmath_int4 set_yyzw(stdmath_int4 value) { self->y = value.x; self->y = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_int4 yywx;
	stdmath_int4 get_yywx() { return {self->y,self->y,self->w,self->x}; }
	stdmath_int4 set_yywx(stdmath_int4 value) { self->y = value.x; self->y = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_int4 yywy;
	stdmath_int4 get_yywy() { return {self->y,self->y,self->w,self->y}; }
	stdmath_int4 set_yywy(stdmath_int4 value) { self->y = value.x; self->y = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_int4 yywz;
	stdmath_int4 get_yywz() { return {self->y,self->y,self->w,self->z}; }
	stdmath_int4 set_yywz(stdmath_int4 value) { self->y = value.x; self->y = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_int4 yyww;
	stdmath_int4 get_yyww() { return {self->y,self->y,self->w,self->w}; }
	stdmath_int4 set_yyww(stdmath_int4 value) { self->y = value.x; self->y = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_int4 yzxx;
	stdmath_int4 get_yzxx() { return {self->y,self->z,self->x,self->x}; }
	stdmath_int4 set_yzxx(stdmath_int4 value) { self->y = value.x; self->z = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_int4 yzxy;
	stdmath_int4 get_yzxy() { return {self->y,self->z,self->x,self->y}; }
	stdmath_int4 set_yzxy(stdmath_int4 value) { self->y = value.x; self->z = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_int4 yzxz;
	stdmath_int4 get_yzxz() { return {self->y,self->z,self->x,self->z}; }
	stdmath_int4 set_yzxz(stdmath_int4 value) { self->y = value.x; self->z = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_int4 yzxw;
	stdmath_int4 get_yzxw() { return {self->y,self->z,self->x,self->w}; }
	stdmath_int4 set_yzxw(stdmath_int4 value) { self->y = value.x; self->z = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_int4 yzyx;
	stdmath_int4 get_yzyx() { return {self->y,self->z,self->y,self->x}; }
	stdmath_int4 set_yzyx(stdmath_int4 value) { self->y = value.x; self->z = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_int4 yzyy;
	stdmath_int4 get_yzyy() { return {self->y,self->z,self->y,self->y}; }
	stdmath_int4 set_yzyy(stdmath_int4 value) { self->y = value.x; self->z = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_int4 yzyz;
	stdmath_int4 get_yzyz() { return {self->y,self->z,self->y,self->z}; }
	stdmath_int4 set_yzyz(stdmath_int4 value) { self->y = value.x; self->z = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_int4 yzyw;
	stdmath_int4 get_yzyw() { return {self->y,self->z,self->y,self->w}; }
	stdmath_int4 set_yzyw(stdmath_int4 value) { self->y = value.x; self->z = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_int4 yzzx;
	stdmath_int4 get_yzzx() { return {self->y,self->z,self->z,self->x}; }
	stdmath_int4 set_yzzx(stdmath_int4 value) { self->y = value.x; self->z = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_int4 yzzy;
	stdmath_int4 get_yzzy() { return {self->y,self->z,self->z,self->y}; }
	stdmath_int4 set_yzzy(stdmath_int4 value) { self->y = value.x; self->z = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_int4 yzzz;
	stdmath_int4 get_yzzz() { return {self->y,self->z,self->z,self->z}; }
	stdmath_int4 set_yzzz(stdmath_int4 value) { self->y = value.x; self->z = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_int4 yzzw;
	stdmath_int4 get_yzzw() { return {self->y,self->z,self->z,self->w}; }
	stdmath_int4 set_yzzw(stdmath_int4 value) { self->y = value.x; self->z = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_int4 yzwx;
	stdmath_int4 get_yzwx() { return {self->y,self->z,self->w,self->x}; }
	stdmath_int4 set_yzwx(stdmath_int4 value) { self->y = value.x; self->z = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_int4 yzwy;
	stdmath_int4 get_yzwy() { return {self->y,self->z,self->w,self->y}; }
	stdmath_int4 set_yzwy(stdmath_int4 value) { self->y = value.x; self->z = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_int4 yzwz;
	stdmath_int4 get_yzwz() { return {self->y,self->z,self->w,self->z}; }
	stdmath_int4 set_yzwz(stdmath_int4 value) { self->y = value.x; self->z = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_int4 yzww;
	stdmath_int4 get_yzww() { return {self->y,self->z,self->w,self->w}; }
	stdmath_int4 set_yzww(stdmath_int4 value) { self->y = value.x; self->z = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_int4 ywxx;
	stdmath_int4 get_ywxx() { return {self->y,self->w,self->x,self->x}; }
	stdmath_int4 set_ywxx(stdmath_int4 value) { self->y = value.x; self->w = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_int4 ywxy;
	stdmath_int4 get_ywxy() { return {self->y,self->w,self->x,self->y}; }
	stdmath_int4 set_ywxy(stdmath_int4 value) { self->y = value.x; self->w = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_int4 ywxz;
	stdmath_int4 get_ywxz() { return {self->y,self->w,self->x,self->z}; }
	stdmath_int4 set_ywxz(stdmath_int4 value) { self->y = value.x; self->w = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_int4 ywxw;
	stdmath_int4 get_ywxw() { return {self->y,self->w,self->x,self->w}; }
	stdmath_int4 set_ywxw(stdmath_int4 value) { self->y = value.x; self->w = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_int4 ywyx;
	stdmath_int4 get_ywyx() { return {self->y,self->w,self->y,self->x}; }
	stdmath_int4 set_ywyx(stdmath_int4 value) { self->y = value.x; self->w = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_int4 ywyy;
	stdmath_int4 get_ywyy() { return {self->y,self->w,self->y,self->y}; }
	stdmath_int4 set_ywyy(stdmath_int4 value) { self->y = value.x; self->w = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_int4 ywyz;
	stdmath_int4 get_ywyz() { return {self->y,self->w,self->y,self->z}; }
	stdmath_int4 set_ywyz(stdmath_int4 value) { self->y = value.x; self->w = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_int4 ywyw;
	stdmath_int4 get_ywyw() { return {self->y,self->w,self->y,self->w}; }
	stdmath_int4 set_ywyw(stdmath_int4 value) { self->y = value.x; self->w = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_int4 ywzx;
	stdmath_int4 get_ywzx() { return {self->y,self->w,self->z,self->x}; }
	stdmath_int4 set_ywzx(stdmath_int4 value) { self->y = value.x; self->w = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_int4 ywzy;
	stdmath_int4 get_ywzy() { return {self->y,self->w,self->z,self->y}; }
	stdmath_int4 set_ywzy(stdmath_int4 value) { self->y = value.x; self->w = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_int4 ywzz;
	stdmath_int4 get_ywzz() { return {self->y,self->w,self->z,self->z}; }
	stdmath_int4 set_ywzz(stdmath_int4 value) { self->y = value.x; self->w = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_int4 ywzw;
	stdmath_int4 get_ywzw() { return {self->y,self->w,self->z,self->w}; }
	stdmath_int4 set_ywzw(stdmath_int4 value) { self->y = value.x; self->w = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_int4 ywwx;
	stdmath_int4 get_ywwx() { return {self->y,self->w,self->w,self->x}; }
	stdmath_int4 set_ywwx(stdmath_int4 value) { self->y = value.x; self->w = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_int4 ywwy;
	stdmath_int4 get_ywwy() { return {self->y,self->w,self->w,self->y}; }
	stdmath_int4 set_ywwy(stdmath_int4 value) { self->y = value.x; self->w = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_int4 ywwz;
	stdmath_int4 get_ywwz() { return {self->y,self->w,self->w,self->z}; }
	stdmath_int4 set_ywwz(stdmath_int4 value) { self->y = value.x; self->w = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_int4 ywww;
	stdmath_int4 get_ywww() { return {self->y,self->w,self->w,self->w}; }
	stdmath_int4 set_ywww(stdmath_int4 value) { self->y = value.x; self->w = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_int4 zxxx;
	stdmath_int4 get_zxxx() { return {self->z,self->x,self->x,self->x}; }
	stdmath_int4 set_zxxx(stdmath_int4 value) { self->z = value.x; self->x = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_int4 zxxy;
	stdmath_int4 get_zxxy() { return {self->z,self->x,self->x,self->y}; }
	stdmath_int4 set_zxxy(stdmath_int4 value) { self->z = value.x; self->x = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_int4 zxxz;
	stdmath_int4 get_zxxz() { return {self->z,self->x,self->x,self->z}; }
	stdmath_int4 set_zxxz(stdmath_int4 value) { self->z = value.x; self->x = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_int4 zxxw;
	stdmath_int4 get_zxxw() { return {self->z,self->x,self->x,self->w}; }
	stdmath_int4 set_zxxw(stdmath_int4 value) { self->z = value.x; self->x = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_int4 zxyx;
	stdmath_int4 get_zxyx() { return {self->z,self->x,self->y,self->x}; }
	stdmath_int4 set_zxyx(stdmath_int4 value) { self->z = value.x; self->x = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_int4 zxyy;
	stdmath_int4 get_zxyy() { return {self->z,self->x,self->y,self->y}; }
	stdmath_int4 set_zxyy(stdmath_int4 value) { self->z = value.x; self->x = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_int4 zxyz;
	stdmath_int4 get_zxyz() { return {self->z,self->x,self->y,self->z}; }
	stdmath_int4 set_zxyz(stdmath_int4 value) { self->z = value.x; self->x = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_int4 zxyw;
	stdmath_int4 get_zxyw() { return {self->z,self->x,self->y,self->w}; }
	stdmath_int4 set_zxyw(stdmath_int4 value) { self->z = value.x; self->x = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_int4 zxzx;
	stdmath_int4 get_zxzx() { return {self->z,self->x,self->z,self->x}; }
	stdmath_int4 set_zxzx(stdmath_int4 value) { self->z = value.x; self->x = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_int4 zxzy;
	stdmath_int4 get_zxzy() { return {self->z,self->x,self->z,self->y}; }
	stdmath_int4 set_zxzy(stdmath_int4 value) { self->z = value.x; self->x = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_int4 zxzz;
	stdmath_int4 get_zxzz() { return {self->z,self->x,self->z,self->z}; }
	stdmath_int4 set_zxzz(stdmath_int4 value) { self->z = value.x; self->x = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_int4 zxzw;
	stdmath_int4 get_zxzw() { return {self->z,self->x,self->z,self->w}; }
	stdmath_int4 set_zxzw(stdmath_int4 value) { self->z = value.x; self->x = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_int4 zxwx;
	stdmath_int4 get_zxwx() { return {self->z,self->x,self->w,self->x}; }
	stdmath_int4 set_zxwx(stdmath_int4 value) { self->z = value.x; self->x = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_int4 zxwy;
	stdmath_int4 get_zxwy() { return {self->z,self->x,self->w,self->y}; }
	stdmath_int4 set_zxwy(stdmath_int4 value) { self->z = value.x; self->x = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_int4 zxwz;
	stdmath_int4 get_zxwz() { return {self->z,self->x,self->w,self->z}; }
	stdmath_int4 set_zxwz(stdmath_int4 value) { self->z = value.x; self->x = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_int4 zxww;
	stdmath_int4 get_zxww() { return {self->z,self->x,self->w,self->w}; }
	stdmath_int4 set_zxww(stdmath_int4 value) { self->z = value.x; self->x = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_int4 zyxx;
	stdmath_int4 get_zyxx() { return {self->z,self->y,self->x,self->x}; }
	stdmath_int4 set_zyxx(stdmath_int4 value) { self->z = value.x; self->y = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_int4 zyxy;
	stdmath_int4 get_zyxy() { return {self->z,self->y,self->x,self->y}; }
	stdmath_int4 set_zyxy(stdmath_int4 value) { self->z = value.x; self->y = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_int4 zyxz;
	stdmath_int4 get_zyxz() { return {self->z,self->y,self->x,self->z}; }
	stdmath_int4 set_zyxz(stdmath_int4 value) { self->z = value.x; self->y = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_int4 zyxw;
	stdmath_int4 get_zyxw() { return {self->z,self->y,self->x,self->w}; }
	stdmath_int4 set_zyxw(stdmath_int4 value) { self->z = value.x; self->y = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_int4 zyyx;
	stdmath_int4 get_zyyx() { return {self->z,self->y,self->y,self->x}; }
	stdmath_int4 set_zyyx(stdmath_int4 value) { self->z = value.x; self->y = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_int4 zyyy;
	stdmath_int4 get_zyyy() { return {self->z,self->y,self->y,self->y}; }
	stdmath_int4 set_zyyy(stdmath_int4 value) { self->z = value.x; self->y = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_int4 zyyz;
	stdmath_int4 get_zyyz() { return {self->z,self->y,self->y,self->z}; }
	stdmath_int4 set_zyyz(stdmath_int4 value) { self->z = value.x; self->y = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_int4 zyyw;
	stdmath_int4 get_zyyw() { return {self->z,self->y,self->y,self->w}; }
	stdmath_int4 set_zyyw(stdmath_int4 value) { self->z = value.x; self->y = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_int4 zyzx;
	stdmath_int4 get_zyzx() { return {self->z,self->y,self->z,self->x}; }
	stdmath_int4 set_zyzx(stdmath_int4 value) { self->z = value.x; self->y = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_int4 zyzy;
	stdmath_int4 get_zyzy() { return {self->z,self->y,self->z,self->y}; }
	stdmath_int4 set_zyzy(stdmath_int4 value) { self->z = value.x; self->y = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_int4 zyzz;
	stdmath_int4 get_zyzz() { return {self->z,self->y,self->z,self->z}; }
	stdmath_int4 set_zyzz(stdmath_int4 value) { self->z = value.x; self->y = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_int4 zyzw;
	stdmath_int4 get_zyzw() { return {self->z,self->y,self->z,self->w}; }
	stdmath_int4 set_zyzw(stdmath_int4 value) { self->z = value.x; self->y = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_int4 zywx;
	stdmath_int4 get_zywx() { return {self->z,self->y,self->w,self->x}; }
	stdmath_int4 set_zywx(stdmath_int4 value) { self->z = value.x; self->y = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_int4 zywy;
	stdmath_int4 get_zywy() { return {self->z,self->y,self->w,self->y}; }
	stdmath_int4 set_zywy(stdmath_int4 value) { self->z = value.x; self->y = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_int4 zywz;
	stdmath_int4 get_zywz() { return {self->z,self->y,self->w,self->z}; }
	stdmath_int4 set_zywz(stdmath_int4 value) { self->z = value.x; self->y = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_int4 zyww;
	stdmath_int4 get_zyww() { return {self->z,self->y,self->w,self->w}; }
	stdmath_int4 set_zyww(stdmath_int4 value) { self->z = value.x; self->y = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_int4 zzxx;
	stdmath_int4 get_zzxx() { return {self->z,self->z,self->x,self->x}; }
	stdmath_int4 set_zzxx(stdmath_int4 value) { self->z = value.x; self->z = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_int4 zzxy;
	stdmath_int4 get_zzxy() { return {self->z,self->z,self->x,self->y}; }
	stdmath_int4 set_zzxy(stdmath_int4 value) { self->z = value.x; self->z = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_int4 zzxz;
	stdmath_int4 get_zzxz() { return {self->z,self->z,self->x,self->z}; }
	stdmath_int4 set_zzxz(stdmath_int4 value) { self->z = value.x; self->z = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_int4 zzxw;
	stdmath_int4 get_zzxw() { return {self->z,self->z,self->x,self->w}; }
	stdmath_int4 set_zzxw(stdmath_int4 value) { self->z = value.x; self->z = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_int4 zzyx;
	stdmath_int4 get_zzyx() { return {self->z,self->z,self->y,self->x}; }
	stdmath_int4 set_zzyx(stdmath_int4 value) { self->z = value.x; self->z = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_int4 zzyy;
	stdmath_int4 get_zzyy() { return {self->z,self->z,self->y,self->y}; }
	stdmath_int4 set_zzyy(stdmath_int4 value) { self->z = value.x; self->z = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_int4 zzyz;
	stdmath_int4 get_zzyz() { return {self->z,self->z,self->y,self->z}; }
	stdmath_int4 set_zzyz(stdmath_int4 value) { self->z = value.x; self->z = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_int4 zzyw;
	stdmath_int4 get_zzyw() { return {self->z,self->z,self->y,self->w}; }
	stdmath_int4 set_zzyw(stdmath_int4 value) { self->z = value.x; self->z = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_int4 zzzx;
	stdmath_int4 get_zzzx() { return {self->z,self->z,self->z,self->x}; }
	stdmath_int4 set_zzzx(stdmath_int4 value) { self->z = value.x; self->z = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_int4 zzzy;
	stdmath_int4 get_zzzy() { return {self->z,self->z,self->z,self->y}; }
	stdmath_int4 set_zzzy(stdmath_int4 value) { self->z = value.x; self->z = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_int4 zzzz;
	stdmath_int4 get_zzzz() { return {self->z,self->z,self->z,self->z}; }
	stdmath_int4 set_zzzz(stdmath_int4 value) { self->z = value.x; self->z = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_int4 zzzw;
	stdmath_int4 get_zzzw() { return {self->z,self->z,self->z,self->w}; }
	stdmath_int4 set_zzzw(stdmath_int4 value) { self->z = value.x; self->z = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_int4 zzwx;
	stdmath_int4 get_zzwx() { return {self->z,self->z,self->w,self->x}; }
	stdmath_int4 set_zzwx(stdmath_int4 value) { self->z = value.x; self->z = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_int4 zzwy;
	stdmath_int4 get_zzwy() { return {self->z,self->z,self->w,self->y}; }
	stdmath_int4 set_zzwy(stdmath_int4 value) { self->z = value.x; self->z = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_int4 zzwz;
	stdmath_int4 get_zzwz() { return {self->z,self->z,self->w,self->z}; }
	stdmath_int4 set_zzwz(stdmath_int4 value) { self->z = value.x; self->z = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_int4 zzww;
	stdmath_int4 get_zzww() { return {self->z,self->z,self->w,self->w}; }
	stdmath_int4 set_zzww(stdmath_int4 value) { self->z = value.x; self->z = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_int4 zwxx;
	stdmath_int4 get_zwxx() { return {self->z,self->w,self->x,self->x}; }
	stdmath_int4 set_zwxx(stdmath_int4 value) { self->z = value.x; self->w = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_int4 zwxy;
	stdmath_int4 get_zwxy() { return {self->z,self->w,self->x,self->y}; }
	stdmath_int4 set_zwxy(stdmath_int4 value) { self->z = value.x; self->w = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_int4 zwxz;
	stdmath_int4 get_zwxz() { return {self->z,self->w,self->x,self->z}; }
	stdmath_int4 set_zwxz(stdmath_int4 value) { self->z = value.x; self->w = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_int4 zwxw;
	stdmath_int4 get_zwxw() { return {self->z,self->w,self->x,self->w}; }
	stdmath_int4 set_zwxw(stdmath_int4 value) { self->z = value.x; self->w = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_int4 zwyx;
	stdmath_int4 get_zwyx() { return {self->z,self->w,self->y,self->x}; }
	stdmath_int4 set_zwyx(stdmath_int4 value) { self->z = value.x; self->w = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_int4 zwyy;
	stdmath_int4 get_zwyy() { return {self->z,self->w,self->y,self->y}; }
	stdmath_int4 set_zwyy(stdmath_int4 value) { self->z = value.x; self->w = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_int4 zwyz;
	stdmath_int4 get_zwyz() { return {self->z,self->w,self->y,self->z}; }
	stdmath_int4 set_zwyz(stdmath_int4 value) { self->z = value.x; self->w = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_int4 zwyw;
	stdmath_int4 get_zwyw() { return {self->z,self->w,self->y,self->w}; }
	stdmath_int4 set_zwyw(stdmath_int4 value) { self->z = value.x; self->w = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_int4 zwzx;
	stdmath_int4 get_zwzx() { return {self->z,self->w,self->z,self->x}; }
	stdmath_int4 set_zwzx(stdmath_int4 value) { self->z = value.x; self->w = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_int4 zwzy;
	stdmath_int4 get_zwzy() { return {self->z,self->w,self->z,self->y}; }
	stdmath_int4 set_zwzy(stdmath_int4 value) { self->z = value.x; self->w = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_int4 zwzz;
	stdmath_int4 get_zwzz() { return {self->z,self->w,self->z,self->z}; }
	stdmath_int4 set_zwzz(stdmath_int4 value) { self->z = value.x; self->w = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_int4 zwzw;
	stdmath_int4 get_zwzw() { return {self->z,self->w,self->z,self->w}; }
	stdmath_int4 set_zwzw(stdmath_int4 value) { self->z = value.x; self->w = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_int4 zwwx;
	stdmath_int4 get_zwwx() { return {self->z,self->w,self->w,self->x}; }
	stdmath_int4 set_zwwx(stdmath_int4 value) { self->z = value.x; self->w = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_int4 zwwy;
	stdmath_int4 get_zwwy() { return {self->z,self->w,self->w,self->y}; }
	stdmath_int4 set_zwwy(stdmath_int4 value) { self->z = value.x; self->w = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_int4 zwwz;
	stdmath_int4 get_zwwz() { return {self->z,self->w,self->w,self->z}; }
	stdmath_int4 set_zwwz(stdmath_int4 value) { self->z = value.x; self->w = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_int4 zwww;
	stdmath_int4 get_zwww() { return {self->z,self->w,self->w,self->w}; }
	stdmath_int4 set_zwww(stdmath_int4 value) { self->z = value.x; self->w = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_int4 wxxx;
	stdmath_int4 get_wxxx() { return {self->w,self->x,self->x,self->x}; }
	stdmath_int4 set_wxxx(stdmath_int4 value) { self->w = value.x; self->x = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_int4 wxxy;
	stdmath_int4 get_wxxy() { return {self->w,self->x,self->x,self->y}; }
	stdmath_int4 set_wxxy(stdmath_int4 value) { self->w = value.x; self->x = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_int4 wxxz;
	stdmath_int4 get_wxxz() { return {self->w,self->x,self->x,self->z}; }
	stdmath_int4 set_wxxz(stdmath_int4 value) { self->w = value.x; self->x = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_int4 wxxw;
	stdmath_int4 get_wxxw() { return {self->w,self->x,self->x,self->w}; }
	stdmath_int4 set_wxxw(stdmath_int4 value) { self->w = value.x; self->x = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_int4 wxyx;
	stdmath_int4 get_wxyx() { return {self->w,self->x,self->y,self->x}; }
	stdmath_int4 set_wxyx(stdmath_int4 value) { self->w = value.x; self->x = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_int4 wxyy;
	stdmath_int4 get_wxyy() { return {self->w,self->x,self->y,self->y}; }
	stdmath_int4 set_wxyy(stdmath_int4 value) { self->w = value.x; self->x = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_int4 wxyz;
	stdmath_int4 get_wxyz() { return {self->w,self->x,self->y,self->z}; }
	stdmath_int4 set_wxyz(stdmath_int4 value) { self->w = value.x; self->x = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_int4 wxyw;
	stdmath_int4 get_wxyw() { return {self->w,self->x,self->y,self->w}; }
	stdmath_int4 set_wxyw(stdmath_int4 value) { self->w = value.x; self->x = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_int4 wxzx;
	stdmath_int4 get_wxzx() { return {self->w,self->x,self->z,self->x}; }
	stdmath_int4 set_wxzx(stdmath_int4 value) { self->w = value.x; self->x = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_int4 wxzy;
	stdmath_int4 get_wxzy() { return {self->w,self->x,self->z,self->y}; }
	stdmath_int4 set_wxzy(stdmath_int4 value) { self->w = value.x; self->x = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_int4 wxzz;
	stdmath_int4 get_wxzz() { return {self->w,self->x,self->z,self->z}; }
	stdmath_int4 set_wxzz(stdmath_int4 value) { self->w = value.x; self->x = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_int4 wxzw;
	stdmath_int4 get_wxzw() { return {self->w,self->x,self->z,self->w}; }
	stdmath_int4 set_wxzw(stdmath_int4 value) { self->w = value.x; self->x = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_int4 wxwx;
	stdmath_int4 get_wxwx() { return {self->w,self->x,self->w,self->x}; }
	stdmath_int4 set_wxwx(stdmath_int4 value) { self->w = value.x; self->x = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_int4 wxwy;
	stdmath_int4 get_wxwy() { return {self->w,self->x,self->w,self->y}; }
	stdmath_int4 set_wxwy(stdmath_int4 value) { self->w = value.x; self->x = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_int4 wxwz;
	stdmath_int4 get_wxwz() { return {self->w,self->x,self->w,self->z}; }
	stdmath_int4 set_wxwz(stdmath_int4 value) { self->w = value.x; self->x = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_int4 wxww;
	stdmath_int4 get_wxww() { return {self->w,self->x,self->w,self->w}; }
	stdmath_int4 set_wxww(stdmath_int4 value) { self->w = value.x; self->x = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_int4 wyxx;
	stdmath_int4 get_wyxx() { return {self->w,self->y,self->x,self->x}; }
	stdmath_int4 set_wyxx(stdmath_int4 value) { self->w = value.x; self->y = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_int4 wyxy;
	stdmath_int4 get_wyxy() { return {self->w,self->y,self->x,self->y}; }
	stdmath_int4 set_wyxy(stdmath_int4 value) { self->w = value.x; self->y = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_int4 wyxz;
	stdmath_int4 get_wyxz() { return {self->w,self->y,self->x,self->z}; }
	stdmath_int4 set_wyxz(stdmath_int4 value) { self->w = value.x; self->y = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_int4 wyxw;
	stdmath_int4 get_wyxw() { return {self->w,self->y,self->x,self->w}; }
	stdmath_int4 set_wyxw(stdmath_int4 value) { self->w = value.x; self->y = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_int4 wyyx;
	stdmath_int4 get_wyyx() { return {self->w,self->y,self->y,self->x}; }
	stdmath_int4 set_wyyx(stdmath_int4 value) { self->w = value.x; self->y = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_int4 wyyy;
	stdmath_int4 get_wyyy() { return {self->w,self->y,self->y,self->y}; }
	stdmath_int4 set_wyyy(stdmath_int4 value) { self->w = value.x; self->y = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_int4 wyyz;
	stdmath_int4 get_wyyz() { return {self->w,self->y,self->y,self->z}; }
	stdmath_int4 set_wyyz(stdmath_int4 value) { self->w = value.x; self->y = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_int4 wyyw;
	stdmath_int4 get_wyyw() { return {self->w,self->y,self->y,self->w}; }
	stdmath_int4 set_wyyw(stdmath_int4 value) { self->w = value.x; self->y = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_int4 wyzx;
	stdmath_int4 get_wyzx() { return {self->w,self->y,self->z,self->x}; }
	stdmath_int4 set_wyzx(stdmath_int4 value) { self->w = value.x; self->y = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_int4 wyzy;
	stdmath_int4 get_wyzy() { return {self->w,self->y,self->z,self->y}; }
	stdmath_int4 set_wyzy(stdmath_int4 value) { self->w = value.x; self->y = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_int4 wyzz;
	stdmath_int4 get_wyzz() { return {self->w,self->y,self->z,self->z}; }
	stdmath_int4 set_wyzz(stdmath_int4 value) { self->w = value.x; self->y = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_int4 wyzw;
	stdmath_int4 get_wyzw() { return {self->w,self->y,self->z,self->w}; }
	stdmath_int4 set_wyzw(stdmath_int4 value) { self->w = value.x; self->y = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_int4 wywx;
	stdmath_int4 get_wywx() { return {self->w,self->y,self->w,self->x}; }
	stdmath_int4 set_wywx(stdmath_int4 value) { self->w = value.x; self->y = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_int4 wywy;
	stdmath_int4 get_wywy() { return {self->w,self->y,self->w,self->y}; }
	stdmath_int4 set_wywy(stdmath_int4 value) { self->w = value.x; self->y = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_int4 wywz;
	stdmath_int4 get_wywz() { return {self->w,self->y,self->w,self->z}; }
	stdmath_int4 set_wywz(stdmath_int4 value) { self->w = value.x; self->y = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_int4 wyww;
	stdmath_int4 get_wyww() { return {self->w,self->y,self->w,self->w}; }
	stdmath_int4 set_wyww(stdmath_int4 value) { self->w = value.x; self->y = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_int4 wzxx;
	stdmath_int4 get_wzxx() { return {self->w,self->z,self->x,self->x}; }
	stdmath_int4 set_wzxx(stdmath_int4 value) { self->w = value.x; self->z = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_int4 wzxy;
	stdmath_int4 get_wzxy() { return {self->w,self->z,self->x,self->y}; }
	stdmath_int4 set_wzxy(stdmath_int4 value) { self->w = value.x; self->z = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_int4 wzxz;
	stdmath_int4 get_wzxz() { return {self->w,self->z,self->x,self->z}; }
	stdmath_int4 set_wzxz(stdmath_int4 value) { self->w = value.x; self->z = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_int4 wzxw;
	stdmath_int4 get_wzxw() { return {self->w,self->z,self->x,self->w}; }
	stdmath_int4 set_wzxw(stdmath_int4 value) { self->w = value.x; self->z = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_int4 wzyx;
	stdmath_int4 get_wzyx() { return {self->w,self->z,self->y,self->x}; }
	stdmath_int4 set_wzyx(stdmath_int4 value) { self->w = value.x; self->z = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_int4 wzyy;
	stdmath_int4 get_wzyy() { return {self->w,self->z,self->y,self->y}; }
	stdmath_int4 set_wzyy(stdmath_int4 value) { self->w = value.x; self->z = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_int4 wzyz;
	stdmath_int4 get_wzyz() { return {self->w,self->z,self->y,self->z}; }
	stdmath_int4 set_wzyz(stdmath_int4 value) { self->w = value.x; self->z = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_int4 wzyw;
	stdmath_int4 get_wzyw() { return {self->w,self->z,self->y,self->w}; }
	stdmath_int4 set_wzyw(stdmath_int4 value) { self->w = value.x; self->z = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_int4 wzzx;
	stdmath_int4 get_wzzx() { return {self->w,self->z,self->z,self->x}; }
	stdmath_int4 set_wzzx(stdmath_int4 value) { self->w = value.x; self->z = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_int4 wzzy;
	stdmath_int4 get_wzzy() { return {self->w,self->z,self->z,self->y}; }
	stdmath_int4 set_wzzy(stdmath_int4 value) { self->w = value.x; self->z = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_int4 wzzz;
	stdmath_int4 get_wzzz() { return {self->w,self->z,self->z,self->z}; }
	stdmath_int4 set_wzzz(stdmath_int4 value) { self->w = value.x; self->z = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_int4 wzzw;
	stdmath_int4 get_wzzw() { return {self->w,self->z,self->z,self->w}; }
	stdmath_int4 set_wzzw(stdmath_int4 value) { self->w = value.x; self->z = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_int4 wzwx;
	stdmath_int4 get_wzwx() { return {self->w,self->z,self->w,self->x}; }
	stdmath_int4 set_wzwx(stdmath_int4 value) { self->w = value.x; self->z = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_int4 wzwy;
	stdmath_int4 get_wzwy() { return {self->w,self->z,self->w,self->y}; }
	stdmath_int4 set_wzwy(stdmath_int4 value) { self->w = value.x; self->z = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_int4 wzwz;
	stdmath_int4 get_wzwz() { return {self->w,self->z,self->w,self->z}; }
	stdmath_int4 set_wzwz(stdmath_int4 value) { self->w = value.x; self->z = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_int4 wzww;
	stdmath_int4 get_wzww() { return {self->w,self->z,self->w,self->w}; }
	stdmath_int4 set_wzww(stdmath_int4 value) { self->w = value.x; self->z = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_int4 wwxx;
	stdmath_int4 get_wwxx() { return {self->w,self->w,self->x,self->x}; }
	stdmath_int4 set_wwxx(stdmath_int4 value) { self->w = value.x; self->w = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_int4 wwxy;
	stdmath_int4 get_wwxy() { return {self->w,self->w,self->x,self->y}; }
	stdmath_int4 set_wwxy(stdmath_int4 value) { self->w = value.x; self->w = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_int4 wwxz;
	stdmath_int4 get_wwxz() { return {self->w,self->w,self->x,self->z}; }
	stdmath_int4 set_wwxz(stdmath_int4 value) { self->w = value.x; self->w = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_int4 wwxw;
	stdmath_int4 get_wwxw() { return {self->w,self->w,self->x,self->w}; }
	stdmath_int4 set_wwxw(stdmath_int4 value) { self->w = value.x; self->w = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_int4 wwyx;
	stdmath_int4 get_wwyx() { return {self->w,self->w,self->y,self->x}; }
	stdmath_int4 set_wwyx(stdmath_int4 value) { self->w = value.x; self->w = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_int4 wwyy;
	stdmath_int4 get_wwyy() { return {self->w,self->w,self->y,self->y}; }
	stdmath_int4 set_wwyy(stdmath_int4 value) { self->w = value.x; self->w = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_int4 wwyz;
	stdmath_int4 get_wwyz() { return {self->w,self->w,self->y,self->z}; }
	stdmath_int4 set_wwyz(stdmath_int4 value) { self->w = value.x; self->w = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_int4 wwyw;
	stdmath_int4 get_wwyw() { return {self->w,self->w,self->y,self->w}; }
	stdmath_int4 set_wwyw(stdmath_int4 value) { self->w = value.x; self->w = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_int4 wwzx;
	stdmath_int4 get_wwzx() { return {self->w,self->w,self->z,self->x}; }
	stdmath_int4 set_wwzx(stdmath_int4 value) { self->w = value.x; self->w = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_int4 wwzy;
	stdmath_int4 get_wwzy() { return {self->w,self->w,self->z,self->y}; }
	stdmath_int4 set_wwzy(stdmath_int4 value) { self->w = value.x; self->w = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_int4 wwzz;
	stdmath_int4 get_wwzz() { return {self->w,self->w,self->z,self->z}; }
	stdmath_int4 set_wwzz(stdmath_int4 value) { self->w = value.x; self->w = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_int4 wwzw;
	stdmath_int4 get_wwzw() { return {self->w,self->w,self->z,self->w}; }
	stdmath_int4 set_wwzw(stdmath_int4 value) { self->w = value.x; self->w = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_int4 wwwx;
	stdmath_int4 get_wwwx() { return {self->w,self->w,self->w,self->x}; }
	stdmath_int4 set_wwwx(stdmath_int4 value) { self->w = value.x; self->w = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_int4 wwwy;
	stdmath_int4 get_wwwy() { return {self->w,self->w,self->w,self->y}; }
	stdmath_int4 set_wwwy(stdmath_int4 value) { self->w = value.x; self->w = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_int4 wwwz;
	stdmath_int4 get_wwwz() { return {self->w,self->w,self->w,self->z}; }
	stdmath_int4 set_wwwz(stdmath_int4 value) { self->w = value.x; self->w = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_int4 wwww;
	stdmath_int4 get_wwww() { return {self->w,self->w,self->w,self->w}; }
	stdmath_int4 set_wwww(stdmath_int4 value) { self->w = value.x; self->w = value.y; self->w = value.z; self->w = value.w; return *self; }



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

	bool4 _equal_to(stdmath_int4 o) {
		return stdmath_int4_equal_to(*self, o);
	}
	bool4 _not_equal_to(stdmath_int4 o) {
		return stdmath_int4_not_equal_to(*self, o);
	}
	bool4 _less_than(stdmath_int4 o) {
		return stdmath_int4_less_than(*self, o);
	}
	bool4 _less_than_or_equal_to(stdmath_int4 o) {
		return stdmath_int4_less_than_or_equal_to(*self, o);
	}
	bool4 _greater_than(stdmath_int4 o) {
		return stdmath_int4_greater_than(*self, o);
	}
	bool4 _greater_than_or_equal_to(stdmath_int4 o) {
		return stdmath_int4_greater_than_or_equal_to(*self, o);
	}

	int32_t _length_squared() {
		return stdmath_int4_length_squared(*self);
	}
	int32_t _length() {
		return stdmath_int4_length(*self);
	}
	int32_t _dot() {
		return stdmath_int4_dot(*self);
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
	stdmath_int4 _lerp(stdmath_int4 o, int t) {
		return stdmath_int4_lerp(*self, o, t);
	}
	stdmath_int4 _clamp(stdmath_int4 min, stdmath_int4 max) {
		return stdmath_int4_clamp(*self, min, max);
	}
	stdmath_int4 _reflect(stdmath_int4 n) {
		return stdmath_int4_reflect(*self, n);
	}
	bool4 _approximately_equal(stdmath_int4 o) {
		return stdmath_int4_approximately_equal()
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

	int32_t _get_element(size_t i) {
		return self->data[i];
	}

	int32_t _set_element(size_t i, int32_t value) {
		return self->data[i] = value;
	}
}
