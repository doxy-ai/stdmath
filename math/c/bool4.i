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
	stdmath_bool2 get_xx() { return {self->x,self->x}; }
	stdmath_bool4 set_xx(stdmath_bool2 value) { self->x = value.x; self->x = value.y; return *self; }

	stdmath_bool2 xy;
	stdmath_bool2 get_xy() { return {self->x,self->y}; }
	stdmath_bool4 set_xy(stdmath_bool2 value) { self->x = value.x; self->y = value.y; return *self; }

	stdmath_bool2 xz;
	stdmath_bool2 get_xz() { return {self->x,self->z}; }
	stdmath_bool4 set_xz(stdmath_bool2 value) { self->x = value.x; self->z = value.y; return *self; }

	stdmath_bool2 xw;
	stdmath_bool2 get_xw() { return {self->x,self->w}; }
	stdmath_bool4 set_xw(stdmath_bool2 value) { self->x = value.x; self->w = value.y; return *self; }

	stdmath_bool2 yx;
	stdmath_bool2 get_yx() { return {self->y,self->x}; }
	stdmath_bool4 set_yx(stdmath_bool2 value) { self->y = value.x; self->x = value.y; return *self; }

	stdmath_bool2 yy;
	stdmath_bool2 get_yy() { return {self->y,self->y}; }
	stdmath_bool4 set_yy(stdmath_bool2 value) { self->y = value.x; self->y = value.y; return *self; }

	stdmath_bool2 yz;
	stdmath_bool2 get_yz() { return {self->y,self->z}; }
	stdmath_bool4 set_yz(stdmath_bool2 value) { self->y = value.x; self->z = value.y; return *self; }

	stdmath_bool2 yw;
	stdmath_bool2 get_yw() { return {self->y,self->w}; }
	stdmath_bool4 set_yw(stdmath_bool2 value) { self->y = value.x; self->w = value.y; return *self; }

	stdmath_bool2 zx;
	stdmath_bool2 get_zx() { return {self->z,self->x}; }
	stdmath_bool4 set_zx(stdmath_bool2 value) { self->z = value.x; self->x = value.y; return *self; }

	stdmath_bool2 zy;
	stdmath_bool2 get_zy() { return {self->z,self->y}; }
	stdmath_bool4 set_zy(stdmath_bool2 value) { self->z = value.x; self->y = value.y; return *self; }

	stdmath_bool2 zz;
	stdmath_bool2 get_zz() { return {self->z,self->z}; }
	stdmath_bool4 set_zz(stdmath_bool2 value) { self->z = value.x; self->z = value.y; return *self; }

	stdmath_bool2 zw;
	stdmath_bool2 get_zw() { return {self->z,self->w}; }
	stdmath_bool4 set_zw(stdmath_bool2 value) { self->z = value.x; self->w = value.y; return *self; }

	stdmath_bool2 wx;
	stdmath_bool2 get_wx() { return {self->w,self->x}; }
	stdmath_bool4 set_wx(stdmath_bool2 value) { self->w = value.x; self->x = value.y; return *self; }

	stdmath_bool2 wy;
	stdmath_bool2 get_wy() { return {self->w,self->y}; }
	stdmath_bool4 set_wy(stdmath_bool2 value) { self->w = value.x; self->y = value.y; return *self; }

	stdmath_bool2 wz;
	stdmath_bool2 get_wz() { return {self->w,self->z}; }
	stdmath_bool4 set_wz(stdmath_bool2 value) { self->w = value.x; self->z = value.y; return *self; }

	stdmath_bool2 ww;
	stdmath_bool2 get_ww() { return {self->w,self->w}; }
	stdmath_bool4 set_ww(stdmath_bool2 value) { self->w = value.x; self->w = value.y; return *self; }

	stdmath_bool3 xxx;
	stdmath_bool3 get_xxx() { return {self->x,self->x,self->x}; }
	stdmath_bool4 set_xxx(stdmath_bool3 value) { self->x = value.x; self->x = value.y; self->x = value.z; return *self; }

	stdmath_bool3 xxy;
	stdmath_bool3 get_xxy() { return {self->x,self->x,self->y}; }
	stdmath_bool4 set_xxy(stdmath_bool3 value) { self->x = value.x; self->x = value.y; self->y = value.z; return *self; }

	stdmath_bool3 xxz;
	stdmath_bool3 get_xxz() { return {self->x,self->x,self->z}; }
	stdmath_bool4 set_xxz(stdmath_bool3 value) { self->x = value.x; self->x = value.y; self->z = value.z; return *self; }

	stdmath_bool3 xxw;
	stdmath_bool3 get_xxw() { return {self->x,self->x,self->w}; }
	stdmath_bool4 set_xxw(stdmath_bool3 value) { self->x = value.x; self->x = value.y; self->w = value.z; return *self; }

	stdmath_bool3 xyx;
	stdmath_bool3 get_xyx() { return {self->x,self->y,self->x}; }
	stdmath_bool4 set_xyx(stdmath_bool3 value) { self->x = value.x; self->y = value.y; self->x = value.z; return *self; }

	stdmath_bool3 xyy;
	stdmath_bool3 get_xyy() { return {self->x,self->y,self->y}; }
	stdmath_bool4 set_xyy(stdmath_bool3 value) { self->x = value.x; self->y = value.y; self->y = value.z; return *self; }

	stdmath_bool3 xyz;
	stdmath_bool3 get_xyz() { return {self->x,self->y,self->z}; }
	stdmath_bool4 set_xyz(stdmath_bool3 value) { self->x = value.x; self->y = value.y; self->z = value.z; return *self; }

	stdmath_bool3 xyw;
	stdmath_bool3 get_xyw() { return {self->x,self->y,self->w}; }
	stdmath_bool4 set_xyw(stdmath_bool3 value) { self->x = value.x; self->y = value.y; self->w = value.z; return *self; }

	stdmath_bool3 xzx;
	stdmath_bool3 get_xzx() { return {self->x,self->z,self->x}; }
	stdmath_bool4 set_xzx(stdmath_bool3 value) { self->x = value.x; self->z = value.y; self->x = value.z; return *self; }

	stdmath_bool3 xzy;
	stdmath_bool3 get_xzy() { return {self->x,self->z,self->y}; }
	stdmath_bool4 set_xzy(stdmath_bool3 value) { self->x = value.x; self->z = value.y; self->y = value.z; return *self; }

	stdmath_bool3 xzz;
	stdmath_bool3 get_xzz() { return {self->x,self->z,self->z}; }
	stdmath_bool4 set_xzz(stdmath_bool3 value) { self->x = value.x; self->z = value.y; self->z = value.z; return *self; }

	stdmath_bool3 xzw;
	stdmath_bool3 get_xzw() { return {self->x,self->z,self->w}; }
	stdmath_bool4 set_xzw(stdmath_bool3 value) { self->x = value.x; self->z = value.y; self->w = value.z; return *self; }

	stdmath_bool3 xwx;
	stdmath_bool3 get_xwx() { return {self->x,self->w,self->x}; }
	stdmath_bool4 set_xwx(stdmath_bool3 value) { self->x = value.x; self->w = value.y; self->x = value.z; return *self; }

	stdmath_bool3 xwy;
	stdmath_bool3 get_xwy() { return {self->x,self->w,self->y}; }
	stdmath_bool4 set_xwy(stdmath_bool3 value) { self->x = value.x; self->w = value.y; self->y = value.z; return *self; }

	stdmath_bool3 xwz;
	stdmath_bool3 get_xwz() { return {self->x,self->w,self->z}; }
	stdmath_bool4 set_xwz(stdmath_bool3 value) { self->x = value.x; self->w = value.y; self->z = value.z; return *self; }

	stdmath_bool3 xww;
	stdmath_bool3 get_xww() { return {self->x,self->w,self->w}; }
	stdmath_bool4 set_xww(stdmath_bool3 value) { self->x = value.x; self->w = value.y; self->w = value.z; return *self; }

	stdmath_bool3 yxx;
	stdmath_bool3 get_yxx() { return {self->y,self->x,self->x}; }
	stdmath_bool4 set_yxx(stdmath_bool3 value) { self->y = value.x; self->x = value.y; self->x = value.z; return *self; }

	stdmath_bool3 yxy;
	stdmath_bool3 get_yxy() { return {self->y,self->x,self->y}; }
	stdmath_bool4 set_yxy(stdmath_bool3 value) { self->y = value.x; self->x = value.y; self->y = value.z; return *self; }

	stdmath_bool3 yxz;
	stdmath_bool3 get_yxz() { return {self->y,self->x,self->z}; }
	stdmath_bool4 set_yxz(stdmath_bool3 value) { self->y = value.x; self->x = value.y; self->z = value.z; return *self; }

	stdmath_bool3 yxw;
	stdmath_bool3 get_yxw() { return {self->y,self->x,self->w}; }
	stdmath_bool4 set_yxw(stdmath_bool3 value) { self->y = value.x; self->x = value.y; self->w = value.z; return *self; }

	stdmath_bool3 yyx;
	stdmath_bool3 get_yyx() { return {self->y,self->y,self->x}; }
	stdmath_bool4 set_yyx(stdmath_bool3 value) { self->y = value.x; self->y = value.y; self->x = value.z; return *self; }

	stdmath_bool3 yyy;
	stdmath_bool3 get_yyy() { return {self->y,self->y,self->y}; }
	stdmath_bool4 set_yyy(stdmath_bool3 value) { self->y = value.x; self->y = value.y; self->y = value.z; return *self; }

	stdmath_bool3 yyz;
	stdmath_bool3 get_yyz() { return {self->y,self->y,self->z}; }
	stdmath_bool4 set_yyz(stdmath_bool3 value) { self->y = value.x; self->y = value.y; self->z = value.z; return *self; }

	stdmath_bool3 yyw;
	stdmath_bool3 get_yyw() { return {self->y,self->y,self->w}; }
	stdmath_bool4 set_yyw(stdmath_bool3 value) { self->y = value.x; self->y = value.y; self->w = value.z; return *self; }

	stdmath_bool3 yzx;
	stdmath_bool3 get_yzx() { return {self->y,self->z,self->x}; }
	stdmath_bool4 set_yzx(stdmath_bool3 value) { self->y = value.x; self->z = value.y; self->x = value.z; return *self; }

	stdmath_bool3 yzy;
	stdmath_bool3 get_yzy() { return {self->y,self->z,self->y}; }
	stdmath_bool4 set_yzy(stdmath_bool3 value) { self->y = value.x; self->z = value.y; self->y = value.z; return *self; }

	stdmath_bool3 yzz;
	stdmath_bool3 get_yzz() { return {self->y,self->z,self->z}; }
	stdmath_bool4 set_yzz(stdmath_bool3 value) { self->y = value.x; self->z = value.y; self->z = value.z; return *self; }

	stdmath_bool3 yzw;
	stdmath_bool3 get_yzw() { return {self->y,self->z,self->w}; }
	stdmath_bool4 set_yzw(stdmath_bool3 value) { self->y = value.x; self->z = value.y; self->w = value.z; return *self; }

	stdmath_bool3 ywx;
	stdmath_bool3 get_ywx() { return {self->y,self->w,self->x}; }
	stdmath_bool4 set_ywx(stdmath_bool3 value) { self->y = value.x; self->w = value.y; self->x = value.z; return *self; }

	stdmath_bool3 ywy;
	stdmath_bool3 get_ywy() { return {self->y,self->w,self->y}; }
	stdmath_bool4 set_ywy(stdmath_bool3 value) { self->y = value.x; self->w = value.y; self->y = value.z; return *self; }

	stdmath_bool3 ywz;
	stdmath_bool3 get_ywz() { return {self->y,self->w,self->z}; }
	stdmath_bool4 set_ywz(stdmath_bool3 value) { self->y = value.x; self->w = value.y; self->z = value.z; return *self; }

	stdmath_bool3 yww;
	stdmath_bool3 get_yww() { return {self->y,self->w,self->w}; }
	stdmath_bool4 set_yww(stdmath_bool3 value) { self->y = value.x; self->w = value.y; self->w = value.z; return *self; }

	stdmath_bool3 zxx;
	stdmath_bool3 get_zxx() { return {self->z,self->x,self->x}; }
	stdmath_bool4 set_zxx(stdmath_bool3 value) { self->z = value.x; self->x = value.y; self->x = value.z; return *self; }

	stdmath_bool3 zxy;
	stdmath_bool3 get_zxy() { return {self->z,self->x,self->y}; }
	stdmath_bool4 set_zxy(stdmath_bool3 value) { self->z = value.x; self->x = value.y; self->y = value.z; return *self; }

	stdmath_bool3 zxz;
	stdmath_bool3 get_zxz() { return {self->z,self->x,self->z}; }
	stdmath_bool4 set_zxz(stdmath_bool3 value) { self->z = value.x; self->x = value.y; self->z = value.z; return *self; }

	stdmath_bool3 zxw;
	stdmath_bool3 get_zxw() { return {self->z,self->x,self->w}; }
	stdmath_bool4 set_zxw(stdmath_bool3 value) { self->z = value.x; self->x = value.y; self->w = value.z; return *self; }

	stdmath_bool3 zyx;
	stdmath_bool3 get_zyx() { return {self->z,self->y,self->x}; }
	stdmath_bool4 set_zyx(stdmath_bool3 value) { self->z = value.x; self->y = value.y; self->x = value.z; return *self; }

	stdmath_bool3 zyy;
	stdmath_bool3 get_zyy() { return {self->z,self->y,self->y}; }
	stdmath_bool4 set_zyy(stdmath_bool3 value) { self->z = value.x; self->y = value.y; self->y = value.z; return *self; }

	stdmath_bool3 zyz;
	stdmath_bool3 get_zyz() { return {self->z,self->y,self->z}; }
	stdmath_bool4 set_zyz(stdmath_bool3 value) { self->z = value.x; self->y = value.y; self->z = value.z; return *self; }

	stdmath_bool3 zyw;
	stdmath_bool3 get_zyw() { return {self->z,self->y,self->w}; }
	stdmath_bool4 set_zyw(stdmath_bool3 value) { self->z = value.x; self->y = value.y; self->w = value.z; return *self; }

	stdmath_bool3 zzx;
	stdmath_bool3 get_zzx() { return {self->z,self->z,self->x}; }
	stdmath_bool4 set_zzx(stdmath_bool3 value) { self->z = value.x; self->z = value.y; self->x = value.z; return *self; }

	stdmath_bool3 zzy;
	stdmath_bool3 get_zzy() { return {self->z,self->z,self->y}; }
	stdmath_bool4 set_zzy(stdmath_bool3 value) { self->z = value.x; self->z = value.y; self->y = value.z; return *self; }

	stdmath_bool3 zzz;
	stdmath_bool3 get_zzz() { return {self->z,self->z,self->z}; }
	stdmath_bool4 set_zzz(stdmath_bool3 value) { self->z = value.x; self->z = value.y; self->z = value.z; return *self; }

	stdmath_bool3 zzw;
	stdmath_bool3 get_zzw() { return {self->z,self->z,self->w}; }
	stdmath_bool4 set_zzw(stdmath_bool3 value) { self->z = value.x; self->z = value.y; self->w = value.z; return *self; }

	stdmath_bool3 zwx;
	stdmath_bool3 get_zwx() { return {self->z,self->w,self->x}; }
	stdmath_bool4 set_zwx(stdmath_bool3 value) { self->z = value.x; self->w = value.y; self->x = value.z; return *self; }

	stdmath_bool3 zwy;
	stdmath_bool3 get_zwy() { return {self->z,self->w,self->y}; }
	stdmath_bool4 set_zwy(stdmath_bool3 value) { self->z = value.x; self->w = value.y; self->y = value.z; return *self; }

	stdmath_bool3 zwz;
	stdmath_bool3 get_zwz() { return {self->z,self->w,self->z}; }
	stdmath_bool4 set_zwz(stdmath_bool3 value) { self->z = value.x; self->w = value.y; self->z = value.z; return *self; }

	stdmath_bool3 zww;
	stdmath_bool3 get_zww() { return {self->z,self->w,self->w}; }
	stdmath_bool4 set_zww(stdmath_bool3 value) { self->z = value.x; self->w = value.y; self->w = value.z; return *self; }

	stdmath_bool3 wxx;
	stdmath_bool3 get_wxx() { return {self->w,self->x,self->x}; }
	stdmath_bool4 set_wxx(stdmath_bool3 value) { self->w = value.x; self->x = value.y; self->x = value.z; return *self; }

	stdmath_bool3 wxy;
	stdmath_bool3 get_wxy() { return {self->w,self->x,self->y}; }
	stdmath_bool4 set_wxy(stdmath_bool3 value) { self->w = value.x; self->x = value.y; self->y = value.z; return *self; }

	stdmath_bool3 wxz;
	stdmath_bool3 get_wxz() { return {self->w,self->x,self->z}; }
	stdmath_bool4 set_wxz(stdmath_bool3 value) { self->w = value.x; self->x = value.y; self->z = value.z; return *self; }

	stdmath_bool3 wxw;
	stdmath_bool3 get_wxw() { return {self->w,self->x,self->w}; }
	stdmath_bool4 set_wxw(stdmath_bool3 value) { self->w = value.x; self->x = value.y; self->w = value.z; return *self; }

	stdmath_bool3 wyx;
	stdmath_bool3 get_wyx() { return {self->w,self->y,self->x}; }
	stdmath_bool4 set_wyx(stdmath_bool3 value) { self->w = value.x; self->y = value.y; self->x = value.z; return *self; }

	stdmath_bool3 wyy;
	stdmath_bool3 get_wyy() { return {self->w,self->y,self->y}; }
	stdmath_bool4 set_wyy(stdmath_bool3 value) { self->w = value.x; self->y = value.y; self->y = value.z; return *self; }

	stdmath_bool3 wyz;
	stdmath_bool3 get_wyz() { return {self->w,self->y,self->z}; }
	stdmath_bool4 set_wyz(stdmath_bool3 value) { self->w = value.x; self->y = value.y; self->z = value.z; return *self; }

	stdmath_bool3 wyw;
	stdmath_bool3 get_wyw() { return {self->w,self->y,self->w}; }
	stdmath_bool4 set_wyw(stdmath_bool3 value) { self->w = value.x; self->y = value.y; self->w = value.z; return *self; }

	stdmath_bool3 wzx;
	stdmath_bool3 get_wzx() { return {self->w,self->z,self->x}; }
	stdmath_bool4 set_wzx(stdmath_bool3 value) { self->w = value.x; self->z = value.y; self->x = value.z; return *self; }

	stdmath_bool3 wzy;
	stdmath_bool3 get_wzy() { return {self->w,self->z,self->y}; }
	stdmath_bool4 set_wzy(stdmath_bool3 value) { self->w = value.x; self->z = value.y; self->y = value.z; return *self; }

	stdmath_bool3 wzz;
	stdmath_bool3 get_wzz() { return {self->w,self->z,self->z}; }
	stdmath_bool4 set_wzz(stdmath_bool3 value) { self->w = value.x; self->z = value.y; self->z = value.z; return *self; }

	stdmath_bool3 wzw;
	stdmath_bool3 get_wzw() { return {self->w,self->z,self->w}; }
	stdmath_bool4 set_wzw(stdmath_bool3 value) { self->w = value.x; self->z = value.y; self->w = value.z; return *self; }

	stdmath_bool3 wwx;
	stdmath_bool3 get_wwx() { return {self->w,self->w,self->x}; }
	stdmath_bool4 set_wwx(stdmath_bool3 value) { self->w = value.x; self->w = value.y; self->x = value.z; return *self; }

	stdmath_bool3 wwy;
	stdmath_bool3 get_wwy() { return {self->w,self->w,self->y}; }
	stdmath_bool4 set_wwy(stdmath_bool3 value) { self->w = value.x; self->w = value.y; self->y = value.z; return *self; }

	stdmath_bool3 wwz;
	stdmath_bool3 get_wwz() { return {self->w,self->w,self->z}; }
	stdmath_bool4 set_wwz(stdmath_bool3 value) { self->w = value.x; self->w = value.y; self->z = value.z; return *self; }

	stdmath_bool3 www;
	stdmath_bool3 get_www() { return {self->w,self->w,self->w}; }
	stdmath_bool4 set_www(stdmath_bool3 value) { self->w = value.x; self->w = value.y; self->w = value.z; return *self; }

	stdmath_bool4 xxxx;
	stdmath_bool4 get_xxxx() { return {self->x,self->x,self->x,self->x}; }
	stdmath_bool4 set_xxxx(stdmath_bool4 value) { self->x = value.x; self->x = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_bool4 xxxy;
	stdmath_bool4 get_xxxy() { return {self->x,self->x,self->x,self->y}; }
	stdmath_bool4 set_xxxy(stdmath_bool4 value) { self->x = value.x; self->x = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_bool4 xxxz;
	stdmath_bool4 get_xxxz() { return {self->x,self->x,self->x,self->z}; }
	stdmath_bool4 set_xxxz(stdmath_bool4 value) { self->x = value.x; self->x = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_bool4 xxxw;
	stdmath_bool4 get_xxxw() { return {self->x,self->x,self->x,self->w}; }
	stdmath_bool4 set_xxxw(stdmath_bool4 value) { self->x = value.x; self->x = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_bool4 xxyx;
	stdmath_bool4 get_xxyx() { return {self->x,self->x,self->y,self->x}; }
	stdmath_bool4 set_xxyx(stdmath_bool4 value) { self->x = value.x; self->x = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_bool4 xxyy;
	stdmath_bool4 get_xxyy() { return {self->x,self->x,self->y,self->y}; }
	stdmath_bool4 set_xxyy(stdmath_bool4 value) { self->x = value.x; self->x = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_bool4 xxyz;
	stdmath_bool4 get_xxyz() { return {self->x,self->x,self->y,self->z}; }
	stdmath_bool4 set_xxyz(stdmath_bool4 value) { self->x = value.x; self->x = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_bool4 xxyw;
	stdmath_bool4 get_xxyw() { return {self->x,self->x,self->y,self->w}; }
	stdmath_bool4 set_xxyw(stdmath_bool4 value) { self->x = value.x; self->x = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_bool4 xxzx;
	stdmath_bool4 get_xxzx() { return {self->x,self->x,self->z,self->x}; }
	stdmath_bool4 set_xxzx(stdmath_bool4 value) { self->x = value.x; self->x = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_bool4 xxzy;
	stdmath_bool4 get_xxzy() { return {self->x,self->x,self->z,self->y}; }
	stdmath_bool4 set_xxzy(stdmath_bool4 value) { self->x = value.x; self->x = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_bool4 xxzz;
	stdmath_bool4 get_xxzz() { return {self->x,self->x,self->z,self->z}; }
	stdmath_bool4 set_xxzz(stdmath_bool4 value) { self->x = value.x; self->x = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_bool4 xxzw;
	stdmath_bool4 get_xxzw() { return {self->x,self->x,self->z,self->w}; }
	stdmath_bool4 set_xxzw(stdmath_bool4 value) { self->x = value.x; self->x = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_bool4 xxwx;
	stdmath_bool4 get_xxwx() { return {self->x,self->x,self->w,self->x}; }
	stdmath_bool4 set_xxwx(stdmath_bool4 value) { self->x = value.x; self->x = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_bool4 xxwy;
	stdmath_bool4 get_xxwy() { return {self->x,self->x,self->w,self->y}; }
	stdmath_bool4 set_xxwy(stdmath_bool4 value) { self->x = value.x; self->x = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_bool4 xxwz;
	stdmath_bool4 get_xxwz() { return {self->x,self->x,self->w,self->z}; }
	stdmath_bool4 set_xxwz(stdmath_bool4 value) { self->x = value.x; self->x = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_bool4 xxww;
	stdmath_bool4 get_xxww() { return {self->x,self->x,self->w,self->w}; }
	stdmath_bool4 set_xxww(stdmath_bool4 value) { self->x = value.x; self->x = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_bool4 xyxx;
	stdmath_bool4 get_xyxx() { return {self->x,self->y,self->x,self->x}; }
	stdmath_bool4 set_xyxx(stdmath_bool4 value) { self->x = value.x; self->y = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_bool4 xyxy;
	stdmath_bool4 get_xyxy() { return {self->x,self->y,self->x,self->y}; }
	stdmath_bool4 set_xyxy(stdmath_bool4 value) { self->x = value.x; self->y = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_bool4 xyxz;
	stdmath_bool4 get_xyxz() { return {self->x,self->y,self->x,self->z}; }
	stdmath_bool4 set_xyxz(stdmath_bool4 value) { self->x = value.x; self->y = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_bool4 xyxw;
	stdmath_bool4 get_xyxw() { return {self->x,self->y,self->x,self->w}; }
	stdmath_bool4 set_xyxw(stdmath_bool4 value) { self->x = value.x; self->y = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_bool4 xyyx;
	stdmath_bool4 get_xyyx() { return {self->x,self->y,self->y,self->x}; }
	stdmath_bool4 set_xyyx(stdmath_bool4 value) { self->x = value.x; self->y = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_bool4 xyyy;
	stdmath_bool4 get_xyyy() { return {self->x,self->y,self->y,self->y}; }
	stdmath_bool4 set_xyyy(stdmath_bool4 value) { self->x = value.x; self->y = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_bool4 xyyz;
	stdmath_bool4 get_xyyz() { return {self->x,self->y,self->y,self->z}; }
	stdmath_bool4 set_xyyz(stdmath_bool4 value) { self->x = value.x; self->y = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_bool4 xyyw;
	stdmath_bool4 get_xyyw() { return {self->x,self->y,self->y,self->w}; }
	stdmath_bool4 set_xyyw(stdmath_bool4 value) { self->x = value.x; self->y = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_bool4 xyzx;
	stdmath_bool4 get_xyzx() { return {self->x,self->y,self->z,self->x}; }
	stdmath_bool4 set_xyzx(stdmath_bool4 value) { self->x = value.x; self->y = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_bool4 xyzy;
	stdmath_bool4 get_xyzy() { return {self->x,self->y,self->z,self->y}; }
	stdmath_bool4 set_xyzy(stdmath_bool4 value) { self->x = value.x; self->y = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_bool4 xyzz;
	stdmath_bool4 get_xyzz() { return {self->x,self->y,self->z,self->z}; }
	stdmath_bool4 set_xyzz(stdmath_bool4 value) { self->x = value.x; self->y = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_bool4 xyzw;
	stdmath_bool4 get_xyzw() { return {self->x,self->y,self->z,self->w}; }
	stdmath_bool4 set_xyzw(stdmath_bool4 value) { self->x = value.x; self->y = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_bool4 xywx;
	stdmath_bool4 get_xywx() { return {self->x,self->y,self->w,self->x}; }
	stdmath_bool4 set_xywx(stdmath_bool4 value) { self->x = value.x; self->y = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_bool4 xywy;
	stdmath_bool4 get_xywy() { return {self->x,self->y,self->w,self->y}; }
	stdmath_bool4 set_xywy(stdmath_bool4 value) { self->x = value.x; self->y = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_bool4 xywz;
	stdmath_bool4 get_xywz() { return {self->x,self->y,self->w,self->z}; }
	stdmath_bool4 set_xywz(stdmath_bool4 value) { self->x = value.x; self->y = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_bool4 xyww;
	stdmath_bool4 get_xyww() { return {self->x,self->y,self->w,self->w}; }
	stdmath_bool4 set_xyww(stdmath_bool4 value) { self->x = value.x; self->y = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_bool4 xzxx;
	stdmath_bool4 get_xzxx() { return {self->x,self->z,self->x,self->x}; }
	stdmath_bool4 set_xzxx(stdmath_bool4 value) { self->x = value.x; self->z = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_bool4 xzxy;
	stdmath_bool4 get_xzxy() { return {self->x,self->z,self->x,self->y}; }
	stdmath_bool4 set_xzxy(stdmath_bool4 value) { self->x = value.x; self->z = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_bool4 xzxz;
	stdmath_bool4 get_xzxz() { return {self->x,self->z,self->x,self->z}; }
	stdmath_bool4 set_xzxz(stdmath_bool4 value) { self->x = value.x; self->z = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_bool4 xzxw;
	stdmath_bool4 get_xzxw() { return {self->x,self->z,self->x,self->w}; }
	stdmath_bool4 set_xzxw(stdmath_bool4 value) { self->x = value.x; self->z = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_bool4 xzyx;
	stdmath_bool4 get_xzyx() { return {self->x,self->z,self->y,self->x}; }
	stdmath_bool4 set_xzyx(stdmath_bool4 value) { self->x = value.x; self->z = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_bool4 xzyy;
	stdmath_bool4 get_xzyy() { return {self->x,self->z,self->y,self->y}; }
	stdmath_bool4 set_xzyy(stdmath_bool4 value) { self->x = value.x; self->z = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_bool4 xzyz;
	stdmath_bool4 get_xzyz() { return {self->x,self->z,self->y,self->z}; }
	stdmath_bool4 set_xzyz(stdmath_bool4 value) { self->x = value.x; self->z = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_bool4 xzyw;
	stdmath_bool4 get_xzyw() { return {self->x,self->z,self->y,self->w}; }
	stdmath_bool4 set_xzyw(stdmath_bool4 value) { self->x = value.x; self->z = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_bool4 xzzx;
	stdmath_bool4 get_xzzx() { return {self->x,self->z,self->z,self->x}; }
	stdmath_bool4 set_xzzx(stdmath_bool4 value) { self->x = value.x; self->z = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_bool4 xzzy;
	stdmath_bool4 get_xzzy() { return {self->x,self->z,self->z,self->y}; }
	stdmath_bool4 set_xzzy(stdmath_bool4 value) { self->x = value.x; self->z = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_bool4 xzzz;
	stdmath_bool4 get_xzzz() { return {self->x,self->z,self->z,self->z}; }
	stdmath_bool4 set_xzzz(stdmath_bool4 value) { self->x = value.x; self->z = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_bool4 xzzw;
	stdmath_bool4 get_xzzw() { return {self->x,self->z,self->z,self->w}; }
	stdmath_bool4 set_xzzw(stdmath_bool4 value) { self->x = value.x; self->z = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_bool4 xzwx;
	stdmath_bool4 get_xzwx() { return {self->x,self->z,self->w,self->x}; }
	stdmath_bool4 set_xzwx(stdmath_bool4 value) { self->x = value.x; self->z = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_bool4 xzwy;
	stdmath_bool4 get_xzwy() { return {self->x,self->z,self->w,self->y}; }
	stdmath_bool4 set_xzwy(stdmath_bool4 value) { self->x = value.x; self->z = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_bool4 xzwz;
	stdmath_bool4 get_xzwz() { return {self->x,self->z,self->w,self->z}; }
	stdmath_bool4 set_xzwz(stdmath_bool4 value) { self->x = value.x; self->z = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_bool4 xzww;
	stdmath_bool4 get_xzww() { return {self->x,self->z,self->w,self->w}; }
	stdmath_bool4 set_xzww(stdmath_bool4 value) { self->x = value.x; self->z = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_bool4 xwxx;
	stdmath_bool4 get_xwxx() { return {self->x,self->w,self->x,self->x}; }
	stdmath_bool4 set_xwxx(stdmath_bool4 value) { self->x = value.x; self->w = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_bool4 xwxy;
	stdmath_bool4 get_xwxy() { return {self->x,self->w,self->x,self->y}; }
	stdmath_bool4 set_xwxy(stdmath_bool4 value) { self->x = value.x; self->w = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_bool4 xwxz;
	stdmath_bool4 get_xwxz() { return {self->x,self->w,self->x,self->z}; }
	stdmath_bool4 set_xwxz(stdmath_bool4 value) { self->x = value.x; self->w = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_bool4 xwxw;
	stdmath_bool4 get_xwxw() { return {self->x,self->w,self->x,self->w}; }
	stdmath_bool4 set_xwxw(stdmath_bool4 value) { self->x = value.x; self->w = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_bool4 xwyx;
	stdmath_bool4 get_xwyx() { return {self->x,self->w,self->y,self->x}; }
	stdmath_bool4 set_xwyx(stdmath_bool4 value) { self->x = value.x; self->w = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_bool4 xwyy;
	stdmath_bool4 get_xwyy() { return {self->x,self->w,self->y,self->y}; }
	stdmath_bool4 set_xwyy(stdmath_bool4 value) { self->x = value.x; self->w = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_bool4 xwyz;
	stdmath_bool4 get_xwyz() { return {self->x,self->w,self->y,self->z}; }
	stdmath_bool4 set_xwyz(stdmath_bool4 value) { self->x = value.x; self->w = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_bool4 xwyw;
	stdmath_bool4 get_xwyw() { return {self->x,self->w,self->y,self->w}; }
	stdmath_bool4 set_xwyw(stdmath_bool4 value) { self->x = value.x; self->w = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_bool4 xwzx;
	stdmath_bool4 get_xwzx() { return {self->x,self->w,self->z,self->x}; }
	stdmath_bool4 set_xwzx(stdmath_bool4 value) { self->x = value.x; self->w = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_bool4 xwzy;
	stdmath_bool4 get_xwzy() { return {self->x,self->w,self->z,self->y}; }
	stdmath_bool4 set_xwzy(stdmath_bool4 value) { self->x = value.x; self->w = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_bool4 xwzz;
	stdmath_bool4 get_xwzz() { return {self->x,self->w,self->z,self->z}; }
	stdmath_bool4 set_xwzz(stdmath_bool4 value) { self->x = value.x; self->w = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_bool4 xwzw;
	stdmath_bool4 get_xwzw() { return {self->x,self->w,self->z,self->w}; }
	stdmath_bool4 set_xwzw(stdmath_bool4 value) { self->x = value.x; self->w = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_bool4 xwwx;
	stdmath_bool4 get_xwwx() { return {self->x,self->w,self->w,self->x}; }
	stdmath_bool4 set_xwwx(stdmath_bool4 value) { self->x = value.x; self->w = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_bool4 xwwy;
	stdmath_bool4 get_xwwy() { return {self->x,self->w,self->w,self->y}; }
	stdmath_bool4 set_xwwy(stdmath_bool4 value) { self->x = value.x; self->w = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_bool4 xwwz;
	stdmath_bool4 get_xwwz() { return {self->x,self->w,self->w,self->z}; }
	stdmath_bool4 set_xwwz(stdmath_bool4 value) { self->x = value.x; self->w = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_bool4 xwww;
	stdmath_bool4 get_xwww() { return {self->x,self->w,self->w,self->w}; }
	stdmath_bool4 set_xwww(stdmath_bool4 value) { self->x = value.x; self->w = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_bool4 yxxx;
	stdmath_bool4 get_yxxx() { return {self->y,self->x,self->x,self->x}; }
	stdmath_bool4 set_yxxx(stdmath_bool4 value) { self->y = value.x; self->x = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_bool4 yxxy;
	stdmath_bool4 get_yxxy() { return {self->y,self->x,self->x,self->y}; }
	stdmath_bool4 set_yxxy(stdmath_bool4 value) { self->y = value.x; self->x = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_bool4 yxxz;
	stdmath_bool4 get_yxxz() { return {self->y,self->x,self->x,self->z}; }
	stdmath_bool4 set_yxxz(stdmath_bool4 value) { self->y = value.x; self->x = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_bool4 yxxw;
	stdmath_bool4 get_yxxw() { return {self->y,self->x,self->x,self->w}; }
	stdmath_bool4 set_yxxw(stdmath_bool4 value) { self->y = value.x; self->x = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_bool4 yxyx;
	stdmath_bool4 get_yxyx() { return {self->y,self->x,self->y,self->x}; }
	stdmath_bool4 set_yxyx(stdmath_bool4 value) { self->y = value.x; self->x = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_bool4 yxyy;
	stdmath_bool4 get_yxyy() { return {self->y,self->x,self->y,self->y}; }
	stdmath_bool4 set_yxyy(stdmath_bool4 value) { self->y = value.x; self->x = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_bool4 yxyz;
	stdmath_bool4 get_yxyz() { return {self->y,self->x,self->y,self->z}; }
	stdmath_bool4 set_yxyz(stdmath_bool4 value) { self->y = value.x; self->x = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_bool4 yxyw;
	stdmath_bool4 get_yxyw() { return {self->y,self->x,self->y,self->w}; }
	stdmath_bool4 set_yxyw(stdmath_bool4 value) { self->y = value.x; self->x = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_bool4 yxzx;
	stdmath_bool4 get_yxzx() { return {self->y,self->x,self->z,self->x}; }
	stdmath_bool4 set_yxzx(stdmath_bool4 value) { self->y = value.x; self->x = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_bool4 yxzy;
	stdmath_bool4 get_yxzy() { return {self->y,self->x,self->z,self->y}; }
	stdmath_bool4 set_yxzy(stdmath_bool4 value) { self->y = value.x; self->x = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_bool4 yxzz;
	stdmath_bool4 get_yxzz() { return {self->y,self->x,self->z,self->z}; }
	stdmath_bool4 set_yxzz(stdmath_bool4 value) { self->y = value.x; self->x = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_bool4 yxzw;
	stdmath_bool4 get_yxzw() { return {self->y,self->x,self->z,self->w}; }
	stdmath_bool4 set_yxzw(stdmath_bool4 value) { self->y = value.x; self->x = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_bool4 yxwx;
	stdmath_bool4 get_yxwx() { return {self->y,self->x,self->w,self->x}; }
	stdmath_bool4 set_yxwx(stdmath_bool4 value) { self->y = value.x; self->x = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_bool4 yxwy;
	stdmath_bool4 get_yxwy() { return {self->y,self->x,self->w,self->y}; }
	stdmath_bool4 set_yxwy(stdmath_bool4 value) { self->y = value.x; self->x = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_bool4 yxwz;
	stdmath_bool4 get_yxwz() { return {self->y,self->x,self->w,self->z}; }
	stdmath_bool4 set_yxwz(stdmath_bool4 value) { self->y = value.x; self->x = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_bool4 yxww;
	stdmath_bool4 get_yxww() { return {self->y,self->x,self->w,self->w}; }
	stdmath_bool4 set_yxww(stdmath_bool4 value) { self->y = value.x; self->x = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_bool4 yyxx;
	stdmath_bool4 get_yyxx() { return {self->y,self->y,self->x,self->x}; }
	stdmath_bool4 set_yyxx(stdmath_bool4 value) { self->y = value.x; self->y = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_bool4 yyxy;
	stdmath_bool4 get_yyxy() { return {self->y,self->y,self->x,self->y}; }
	stdmath_bool4 set_yyxy(stdmath_bool4 value) { self->y = value.x; self->y = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_bool4 yyxz;
	stdmath_bool4 get_yyxz() { return {self->y,self->y,self->x,self->z}; }
	stdmath_bool4 set_yyxz(stdmath_bool4 value) { self->y = value.x; self->y = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_bool4 yyxw;
	stdmath_bool4 get_yyxw() { return {self->y,self->y,self->x,self->w}; }
	stdmath_bool4 set_yyxw(stdmath_bool4 value) { self->y = value.x; self->y = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_bool4 yyyx;
	stdmath_bool4 get_yyyx() { return {self->y,self->y,self->y,self->x}; }
	stdmath_bool4 set_yyyx(stdmath_bool4 value) { self->y = value.x; self->y = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_bool4 yyyy;
	stdmath_bool4 get_yyyy() { return {self->y,self->y,self->y,self->y}; }
	stdmath_bool4 set_yyyy(stdmath_bool4 value) { self->y = value.x; self->y = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_bool4 yyyz;
	stdmath_bool4 get_yyyz() { return {self->y,self->y,self->y,self->z}; }
	stdmath_bool4 set_yyyz(stdmath_bool4 value) { self->y = value.x; self->y = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_bool4 yyyw;
	stdmath_bool4 get_yyyw() { return {self->y,self->y,self->y,self->w}; }
	stdmath_bool4 set_yyyw(stdmath_bool4 value) { self->y = value.x; self->y = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_bool4 yyzx;
	stdmath_bool4 get_yyzx() { return {self->y,self->y,self->z,self->x}; }
	stdmath_bool4 set_yyzx(stdmath_bool4 value) { self->y = value.x; self->y = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_bool4 yyzy;
	stdmath_bool4 get_yyzy() { return {self->y,self->y,self->z,self->y}; }
	stdmath_bool4 set_yyzy(stdmath_bool4 value) { self->y = value.x; self->y = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_bool4 yyzz;
	stdmath_bool4 get_yyzz() { return {self->y,self->y,self->z,self->z}; }
	stdmath_bool4 set_yyzz(stdmath_bool4 value) { self->y = value.x; self->y = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_bool4 yyzw;
	stdmath_bool4 get_yyzw() { return {self->y,self->y,self->z,self->w}; }
	stdmath_bool4 set_yyzw(stdmath_bool4 value) { self->y = value.x; self->y = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_bool4 yywx;
	stdmath_bool4 get_yywx() { return {self->y,self->y,self->w,self->x}; }
	stdmath_bool4 set_yywx(stdmath_bool4 value) { self->y = value.x; self->y = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_bool4 yywy;
	stdmath_bool4 get_yywy() { return {self->y,self->y,self->w,self->y}; }
	stdmath_bool4 set_yywy(stdmath_bool4 value) { self->y = value.x; self->y = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_bool4 yywz;
	stdmath_bool4 get_yywz() { return {self->y,self->y,self->w,self->z}; }
	stdmath_bool4 set_yywz(stdmath_bool4 value) { self->y = value.x; self->y = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_bool4 yyww;
	stdmath_bool4 get_yyww() { return {self->y,self->y,self->w,self->w}; }
	stdmath_bool4 set_yyww(stdmath_bool4 value) { self->y = value.x; self->y = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_bool4 yzxx;
	stdmath_bool4 get_yzxx() { return {self->y,self->z,self->x,self->x}; }
	stdmath_bool4 set_yzxx(stdmath_bool4 value) { self->y = value.x; self->z = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_bool4 yzxy;
	stdmath_bool4 get_yzxy() { return {self->y,self->z,self->x,self->y}; }
	stdmath_bool4 set_yzxy(stdmath_bool4 value) { self->y = value.x; self->z = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_bool4 yzxz;
	stdmath_bool4 get_yzxz() { return {self->y,self->z,self->x,self->z}; }
	stdmath_bool4 set_yzxz(stdmath_bool4 value) { self->y = value.x; self->z = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_bool4 yzxw;
	stdmath_bool4 get_yzxw() { return {self->y,self->z,self->x,self->w}; }
	stdmath_bool4 set_yzxw(stdmath_bool4 value) { self->y = value.x; self->z = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_bool4 yzyx;
	stdmath_bool4 get_yzyx() { return {self->y,self->z,self->y,self->x}; }
	stdmath_bool4 set_yzyx(stdmath_bool4 value) { self->y = value.x; self->z = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_bool4 yzyy;
	stdmath_bool4 get_yzyy() { return {self->y,self->z,self->y,self->y}; }
	stdmath_bool4 set_yzyy(stdmath_bool4 value) { self->y = value.x; self->z = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_bool4 yzyz;
	stdmath_bool4 get_yzyz() { return {self->y,self->z,self->y,self->z}; }
	stdmath_bool4 set_yzyz(stdmath_bool4 value) { self->y = value.x; self->z = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_bool4 yzyw;
	stdmath_bool4 get_yzyw() { return {self->y,self->z,self->y,self->w}; }
	stdmath_bool4 set_yzyw(stdmath_bool4 value) { self->y = value.x; self->z = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_bool4 yzzx;
	stdmath_bool4 get_yzzx() { return {self->y,self->z,self->z,self->x}; }
	stdmath_bool4 set_yzzx(stdmath_bool4 value) { self->y = value.x; self->z = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_bool4 yzzy;
	stdmath_bool4 get_yzzy() { return {self->y,self->z,self->z,self->y}; }
	stdmath_bool4 set_yzzy(stdmath_bool4 value) { self->y = value.x; self->z = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_bool4 yzzz;
	stdmath_bool4 get_yzzz() { return {self->y,self->z,self->z,self->z}; }
	stdmath_bool4 set_yzzz(stdmath_bool4 value) { self->y = value.x; self->z = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_bool4 yzzw;
	stdmath_bool4 get_yzzw() { return {self->y,self->z,self->z,self->w}; }
	stdmath_bool4 set_yzzw(stdmath_bool4 value) { self->y = value.x; self->z = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_bool4 yzwx;
	stdmath_bool4 get_yzwx() { return {self->y,self->z,self->w,self->x}; }
	stdmath_bool4 set_yzwx(stdmath_bool4 value) { self->y = value.x; self->z = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_bool4 yzwy;
	stdmath_bool4 get_yzwy() { return {self->y,self->z,self->w,self->y}; }
	stdmath_bool4 set_yzwy(stdmath_bool4 value) { self->y = value.x; self->z = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_bool4 yzwz;
	stdmath_bool4 get_yzwz() { return {self->y,self->z,self->w,self->z}; }
	stdmath_bool4 set_yzwz(stdmath_bool4 value) { self->y = value.x; self->z = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_bool4 yzww;
	stdmath_bool4 get_yzww() { return {self->y,self->z,self->w,self->w}; }
	stdmath_bool4 set_yzww(stdmath_bool4 value) { self->y = value.x; self->z = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_bool4 ywxx;
	stdmath_bool4 get_ywxx() { return {self->y,self->w,self->x,self->x}; }
	stdmath_bool4 set_ywxx(stdmath_bool4 value) { self->y = value.x; self->w = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_bool4 ywxy;
	stdmath_bool4 get_ywxy() { return {self->y,self->w,self->x,self->y}; }
	stdmath_bool4 set_ywxy(stdmath_bool4 value) { self->y = value.x; self->w = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_bool4 ywxz;
	stdmath_bool4 get_ywxz() { return {self->y,self->w,self->x,self->z}; }
	stdmath_bool4 set_ywxz(stdmath_bool4 value) { self->y = value.x; self->w = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_bool4 ywxw;
	stdmath_bool4 get_ywxw() { return {self->y,self->w,self->x,self->w}; }
	stdmath_bool4 set_ywxw(stdmath_bool4 value) { self->y = value.x; self->w = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_bool4 ywyx;
	stdmath_bool4 get_ywyx() { return {self->y,self->w,self->y,self->x}; }
	stdmath_bool4 set_ywyx(stdmath_bool4 value) { self->y = value.x; self->w = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_bool4 ywyy;
	stdmath_bool4 get_ywyy() { return {self->y,self->w,self->y,self->y}; }
	stdmath_bool4 set_ywyy(stdmath_bool4 value) { self->y = value.x; self->w = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_bool4 ywyz;
	stdmath_bool4 get_ywyz() { return {self->y,self->w,self->y,self->z}; }
	stdmath_bool4 set_ywyz(stdmath_bool4 value) { self->y = value.x; self->w = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_bool4 ywyw;
	stdmath_bool4 get_ywyw() { return {self->y,self->w,self->y,self->w}; }
	stdmath_bool4 set_ywyw(stdmath_bool4 value) { self->y = value.x; self->w = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_bool4 ywzx;
	stdmath_bool4 get_ywzx() { return {self->y,self->w,self->z,self->x}; }
	stdmath_bool4 set_ywzx(stdmath_bool4 value) { self->y = value.x; self->w = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_bool4 ywzy;
	stdmath_bool4 get_ywzy() { return {self->y,self->w,self->z,self->y}; }
	stdmath_bool4 set_ywzy(stdmath_bool4 value) { self->y = value.x; self->w = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_bool4 ywzz;
	stdmath_bool4 get_ywzz() { return {self->y,self->w,self->z,self->z}; }
	stdmath_bool4 set_ywzz(stdmath_bool4 value) { self->y = value.x; self->w = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_bool4 ywzw;
	stdmath_bool4 get_ywzw() { return {self->y,self->w,self->z,self->w}; }
	stdmath_bool4 set_ywzw(stdmath_bool4 value) { self->y = value.x; self->w = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_bool4 ywwx;
	stdmath_bool4 get_ywwx() { return {self->y,self->w,self->w,self->x}; }
	stdmath_bool4 set_ywwx(stdmath_bool4 value) { self->y = value.x; self->w = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_bool4 ywwy;
	stdmath_bool4 get_ywwy() { return {self->y,self->w,self->w,self->y}; }
	stdmath_bool4 set_ywwy(stdmath_bool4 value) { self->y = value.x; self->w = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_bool4 ywwz;
	stdmath_bool4 get_ywwz() { return {self->y,self->w,self->w,self->z}; }
	stdmath_bool4 set_ywwz(stdmath_bool4 value) { self->y = value.x; self->w = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_bool4 ywww;
	stdmath_bool4 get_ywww() { return {self->y,self->w,self->w,self->w}; }
	stdmath_bool4 set_ywww(stdmath_bool4 value) { self->y = value.x; self->w = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_bool4 zxxx;
	stdmath_bool4 get_zxxx() { return {self->z,self->x,self->x,self->x}; }
	stdmath_bool4 set_zxxx(stdmath_bool4 value) { self->z = value.x; self->x = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_bool4 zxxy;
	stdmath_bool4 get_zxxy() { return {self->z,self->x,self->x,self->y}; }
	stdmath_bool4 set_zxxy(stdmath_bool4 value) { self->z = value.x; self->x = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_bool4 zxxz;
	stdmath_bool4 get_zxxz() { return {self->z,self->x,self->x,self->z}; }
	stdmath_bool4 set_zxxz(stdmath_bool4 value) { self->z = value.x; self->x = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_bool4 zxxw;
	stdmath_bool4 get_zxxw() { return {self->z,self->x,self->x,self->w}; }
	stdmath_bool4 set_zxxw(stdmath_bool4 value) { self->z = value.x; self->x = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_bool4 zxyx;
	stdmath_bool4 get_zxyx() { return {self->z,self->x,self->y,self->x}; }
	stdmath_bool4 set_zxyx(stdmath_bool4 value) { self->z = value.x; self->x = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_bool4 zxyy;
	stdmath_bool4 get_zxyy() { return {self->z,self->x,self->y,self->y}; }
	stdmath_bool4 set_zxyy(stdmath_bool4 value) { self->z = value.x; self->x = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_bool4 zxyz;
	stdmath_bool4 get_zxyz() { return {self->z,self->x,self->y,self->z}; }
	stdmath_bool4 set_zxyz(stdmath_bool4 value) { self->z = value.x; self->x = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_bool4 zxyw;
	stdmath_bool4 get_zxyw() { return {self->z,self->x,self->y,self->w}; }
	stdmath_bool4 set_zxyw(stdmath_bool4 value) { self->z = value.x; self->x = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_bool4 zxzx;
	stdmath_bool4 get_zxzx() { return {self->z,self->x,self->z,self->x}; }
	stdmath_bool4 set_zxzx(stdmath_bool4 value) { self->z = value.x; self->x = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_bool4 zxzy;
	stdmath_bool4 get_zxzy() { return {self->z,self->x,self->z,self->y}; }
	stdmath_bool4 set_zxzy(stdmath_bool4 value) { self->z = value.x; self->x = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_bool4 zxzz;
	stdmath_bool4 get_zxzz() { return {self->z,self->x,self->z,self->z}; }
	stdmath_bool4 set_zxzz(stdmath_bool4 value) { self->z = value.x; self->x = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_bool4 zxzw;
	stdmath_bool4 get_zxzw() { return {self->z,self->x,self->z,self->w}; }
	stdmath_bool4 set_zxzw(stdmath_bool4 value) { self->z = value.x; self->x = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_bool4 zxwx;
	stdmath_bool4 get_zxwx() { return {self->z,self->x,self->w,self->x}; }
	stdmath_bool4 set_zxwx(stdmath_bool4 value) { self->z = value.x; self->x = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_bool4 zxwy;
	stdmath_bool4 get_zxwy() { return {self->z,self->x,self->w,self->y}; }
	stdmath_bool4 set_zxwy(stdmath_bool4 value) { self->z = value.x; self->x = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_bool4 zxwz;
	stdmath_bool4 get_zxwz() { return {self->z,self->x,self->w,self->z}; }
	stdmath_bool4 set_zxwz(stdmath_bool4 value) { self->z = value.x; self->x = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_bool4 zxww;
	stdmath_bool4 get_zxww() { return {self->z,self->x,self->w,self->w}; }
	stdmath_bool4 set_zxww(stdmath_bool4 value) { self->z = value.x; self->x = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_bool4 zyxx;
	stdmath_bool4 get_zyxx() { return {self->z,self->y,self->x,self->x}; }
	stdmath_bool4 set_zyxx(stdmath_bool4 value) { self->z = value.x; self->y = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_bool4 zyxy;
	stdmath_bool4 get_zyxy() { return {self->z,self->y,self->x,self->y}; }
	stdmath_bool4 set_zyxy(stdmath_bool4 value) { self->z = value.x; self->y = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_bool4 zyxz;
	stdmath_bool4 get_zyxz() { return {self->z,self->y,self->x,self->z}; }
	stdmath_bool4 set_zyxz(stdmath_bool4 value) { self->z = value.x; self->y = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_bool4 zyxw;
	stdmath_bool4 get_zyxw() { return {self->z,self->y,self->x,self->w}; }
	stdmath_bool4 set_zyxw(stdmath_bool4 value) { self->z = value.x; self->y = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_bool4 zyyx;
	stdmath_bool4 get_zyyx() { return {self->z,self->y,self->y,self->x}; }
	stdmath_bool4 set_zyyx(stdmath_bool4 value) { self->z = value.x; self->y = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_bool4 zyyy;
	stdmath_bool4 get_zyyy() { return {self->z,self->y,self->y,self->y}; }
	stdmath_bool4 set_zyyy(stdmath_bool4 value) { self->z = value.x; self->y = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_bool4 zyyz;
	stdmath_bool4 get_zyyz() { return {self->z,self->y,self->y,self->z}; }
	stdmath_bool4 set_zyyz(stdmath_bool4 value) { self->z = value.x; self->y = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_bool4 zyyw;
	stdmath_bool4 get_zyyw() { return {self->z,self->y,self->y,self->w}; }
	stdmath_bool4 set_zyyw(stdmath_bool4 value) { self->z = value.x; self->y = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_bool4 zyzx;
	stdmath_bool4 get_zyzx() { return {self->z,self->y,self->z,self->x}; }
	stdmath_bool4 set_zyzx(stdmath_bool4 value) { self->z = value.x; self->y = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_bool4 zyzy;
	stdmath_bool4 get_zyzy() { return {self->z,self->y,self->z,self->y}; }
	stdmath_bool4 set_zyzy(stdmath_bool4 value) { self->z = value.x; self->y = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_bool4 zyzz;
	stdmath_bool4 get_zyzz() { return {self->z,self->y,self->z,self->z}; }
	stdmath_bool4 set_zyzz(stdmath_bool4 value) { self->z = value.x; self->y = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_bool4 zyzw;
	stdmath_bool4 get_zyzw() { return {self->z,self->y,self->z,self->w}; }
	stdmath_bool4 set_zyzw(stdmath_bool4 value) { self->z = value.x; self->y = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_bool4 zywx;
	stdmath_bool4 get_zywx() { return {self->z,self->y,self->w,self->x}; }
	stdmath_bool4 set_zywx(stdmath_bool4 value) { self->z = value.x; self->y = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_bool4 zywy;
	stdmath_bool4 get_zywy() { return {self->z,self->y,self->w,self->y}; }
	stdmath_bool4 set_zywy(stdmath_bool4 value) { self->z = value.x; self->y = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_bool4 zywz;
	stdmath_bool4 get_zywz() { return {self->z,self->y,self->w,self->z}; }
	stdmath_bool4 set_zywz(stdmath_bool4 value) { self->z = value.x; self->y = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_bool4 zyww;
	stdmath_bool4 get_zyww() { return {self->z,self->y,self->w,self->w}; }
	stdmath_bool4 set_zyww(stdmath_bool4 value) { self->z = value.x; self->y = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_bool4 zzxx;
	stdmath_bool4 get_zzxx() { return {self->z,self->z,self->x,self->x}; }
	stdmath_bool4 set_zzxx(stdmath_bool4 value) { self->z = value.x; self->z = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_bool4 zzxy;
	stdmath_bool4 get_zzxy() { return {self->z,self->z,self->x,self->y}; }
	stdmath_bool4 set_zzxy(stdmath_bool4 value) { self->z = value.x; self->z = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_bool4 zzxz;
	stdmath_bool4 get_zzxz() { return {self->z,self->z,self->x,self->z}; }
	stdmath_bool4 set_zzxz(stdmath_bool4 value) { self->z = value.x; self->z = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_bool4 zzxw;
	stdmath_bool4 get_zzxw() { return {self->z,self->z,self->x,self->w}; }
	stdmath_bool4 set_zzxw(stdmath_bool4 value) { self->z = value.x; self->z = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_bool4 zzyx;
	stdmath_bool4 get_zzyx() { return {self->z,self->z,self->y,self->x}; }
	stdmath_bool4 set_zzyx(stdmath_bool4 value) { self->z = value.x; self->z = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_bool4 zzyy;
	stdmath_bool4 get_zzyy() { return {self->z,self->z,self->y,self->y}; }
	stdmath_bool4 set_zzyy(stdmath_bool4 value) { self->z = value.x; self->z = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_bool4 zzyz;
	stdmath_bool4 get_zzyz() { return {self->z,self->z,self->y,self->z}; }
	stdmath_bool4 set_zzyz(stdmath_bool4 value) { self->z = value.x; self->z = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_bool4 zzyw;
	stdmath_bool4 get_zzyw() { return {self->z,self->z,self->y,self->w}; }
	stdmath_bool4 set_zzyw(stdmath_bool4 value) { self->z = value.x; self->z = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_bool4 zzzx;
	stdmath_bool4 get_zzzx() { return {self->z,self->z,self->z,self->x}; }
	stdmath_bool4 set_zzzx(stdmath_bool4 value) { self->z = value.x; self->z = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_bool4 zzzy;
	stdmath_bool4 get_zzzy() { return {self->z,self->z,self->z,self->y}; }
	stdmath_bool4 set_zzzy(stdmath_bool4 value) { self->z = value.x; self->z = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_bool4 zzzz;
	stdmath_bool4 get_zzzz() { return {self->z,self->z,self->z,self->z}; }
	stdmath_bool4 set_zzzz(stdmath_bool4 value) { self->z = value.x; self->z = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_bool4 zzzw;
	stdmath_bool4 get_zzzw() { return {self->z,self->z,self->z,self->w}; }
	stdmath_bool4 set_zzzw(stdmath_bool4 value) { self->z = value.x; self->z = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_bool4 zzwx;
	stdmath_bool4 get_zzwx() { return {self->z,self->z,self->w,self->x}; }
	stdmath_bool4 set_zzwx(stdmath_bool4 value) { self->z = value.x; self->z = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_bool4 zzwy;
	stdmath_bool4 get_zzwy() { return {self->z,self->z,self->w,self->y}; }
	stdmath_bool4 set_zzwy(stdmath_bool4 value) { self->z = value.x; self->z = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_bool4 zzwz;
	stdmath_bool4 get_zzwz() { return {self->z,self->z,self->w,self->z}; }
	stdmath_bool4 set_zzwz(stdmath_bool4 value) { self->z = value.x; self->z = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_bool4 zzww;
	stdmath_bool4 get_zzww() { return {self->z,self->z,self->w,self->w}; }
	stdmath_bool4 set_zzww(stdmath_bool4 value) { self->z = value.x; self->z = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_bool4 zwxx;
	stdmath_bool4 get_zwxx() { return {self->z,self->w,self->x,self->x}; }
	stdmath_bool4 set_zwxx(stdmath_bool4 value) { self->z = value.x; self->w = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_bool4 zwxy;
	stdmath_bool4 get_zwxy() { return {self->z,self->w,self->x,self->y}; }
	stdmath_bool4 set_zwxy(stdmath_bool4 value) { self->z = value.x; self->w = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_bool4 zwxz;
	stdmath_bool4 get_zwxz() { return {self->z,self->w,self->x,self->z}; }
	stdmath_bool4 set_zwxz(stdmath_bool4 value) { self->z = value.x; self->w = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_bool4 zwxw;
	stdmath_bool4 get_zwxw() { return {self->z,self->w,self->x,self->w}; }
	stdmath_bool4 set_zwxw(stdmath_bool4 value) { self->z = value.x; self->w = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_bool4 zwyx;
	stdmath_bool4 get_zwyx() { return {self->z,self->w,self->y,self->x}; }
	stdmath_bool4 set_zwyx(stdmath_bool4 value) { self->z = value.x; self->w = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_bool4 zwyy;
	stdmath_bool4 get_zwyy() { return {self->z,self->w,self->y,self->y}; }
	stdmath_bool4 set_zwyy(stdmath_bool4 value) { self->z = value.x; self->w = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_bool4 zwyz;
	stdmath_bool4 get_zwyz() { return {self->z,self->w,self->y,self->z}; }
	stdmath_bool4 set_zwyz(stdmath_bool4 value) { self->z = value.x; self->w = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_bool4 zwyw;
	stdmath_bool4 get_zwyw() { return {self->z,self->w,self->y,self->w}; }
	stdmath_bool4 set_zwyw(stdmath_bool4 value) { self->z = value.x; self->w = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_bool4 zwzx;
	stdmath_bool4 get_zwzx() { return {self->z,self->w,self->z,self->x}; }
	stdmath_bool4 set_zwzx(stdmath_bool4 value) { self->z = value.x; self->w = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_bool4 zwzy;
	stdmath_bool4 get_zwzy() { return {self->z,self->w,self->z,self->y}; }
	stdmath_bool4 set_zwzy(stdmath_bool4 value) { self->z = value.x; self->w = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_bool4 zwzz;
	stdmath_bool4 get_zwzz() { return {self->z,self->w,self->z,self->z}; }
	stdmath_bool4 set_zwzz(stdmath_bool4 value) { self->z = value.x; self->w = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_bool4 zwzw;
	stdmath_bool4 get_zwzw() { return {self->z,self->w,self->z,self->w}; }
	stdmath_bool4 set_zwzw(stdmath_bool4 value) { self->z = value.x; self->w = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_bool4 zwwx;
	stdmath_bool4 get_zwwx() { return {self->z,self->w,self->w,self->x}; }
	stdmath_bool4 set_zwwx(stdmath_bool4 value) { self->z = value.x; self->w = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_bool4 zwwy;
	stdmath_bool4 get_zwwy() { return {self->z,self->w,self->w,self->y}; }
	stdmath_bool4 set_zwwy(stdmath_bool4 value) { self->z = value.x; self->w = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_bool4 zwwz;
	stdmath_bool4 get_zwwz() { return {self->z,self->w,self->w,self->z}; }
	stdmath_bool4 set_zwwz(stdmath_bool4 value) { self->z = value.x; self->w = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_bool4 zwww;
	stdmath_bool4 get_zwww() { return {self->z,self->w,self->w,self->w}; }
	stdmath_bool4 set_zwww(stdmath_bool4 value) { self->z = value.x; self->w = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_bool4 wxxx;
	stdmath_bool4 get_wxxx() { return {self->w,self->x,self->x,self->x}; }
	stdmath_bool4 set_wxxx(stdmath_bool4 value) { self->w = value.x; self->x = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_bool4 wxxy;
	stdmath_bool4 get_wxxy() { return {self->w,self->x,self->x,self->y}; }
	stdmath_bool4 set_wxxy(stdmath_bool4 value) { self->w = value.x; self->x = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_bool4 wxxz;
	stdmath_bool4 get_wxxz() { return {self->w,self->x,self->x,self->z}; }
	stdmath_bool4 set_wxxz(stdmath_bool4 value) { self->w = value.x; self->x = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_bool4 wxxw;
	stdmath_bool4 get_wxxw() { return {self->w,self->x,self->x,self->w}; }
	stdmath_bool4 set_wxxw(stdmath_bool4 value) { self->w = value.x; self->x = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_bool4 wxyx;
	stdmath_bool4 get_wxyx() { return {self->w,self->x,self->y,self->x}; }
	stdmath_bool4 set_wxyx(stdmath_bool4 value) { self->w = value.x; self->x = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_bool4 wxyy;
	stdmath_bool4 get_wxyy() { return {self->w,self->x,self->y,self->y}; }
	stdmath_bool4 set_wxyy(stdmath_bool4 value) { self->w = value.x; self->x = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_bool4 wxyz;
	stdmath_bool4 get_wxyz() { return {self->w,self->x,self->y,self->z}; }
	stdmath_bool4 set_wxyz(stdmath_bool4 value) { self->w = value.x; self->x = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_bool4 wxyw;
	stdmath_bool4 get_wxyw() { return {self->w,self->x,self->y,self->w}; }
	stdmath_bool4 set_wxyw(stdmath_bool4 value) { self->w = value.x; self->x = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_bool4 wxzx;
	stdmath_bool4 get_wxzx() { return {self->w,self->x,self->z,self->x}; }
	stdmath_bool4 set_wxzx(stdmath_bool4 value) { self->w = value.x; self->x = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_bool4 wxzy;
	stdmath_bool4 get_wxzy() { return {self->w,self->x,self->z,self->y}; }
	stdmath_bool4 set_wxzy(stdmath_bool4 value) { self->w = value.x; self->x = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_bool4 wxzz;
	stdmath_bool4 get_wxzz() { return {self->w,self->x,self->z,self->z}; }
	stdmath_bool4 set_wxzz(stdmath_bool4 value) { self->w = value.x; self->x = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_bool4 wxzw;
	stdmath_bool4 get_wxzw() { return {self->w,self->x,self->z,self->w}; }
	stdmath_bool4 set_wxzw(stdmath_bool4 value) { self->w = value.x; self->x = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_bool4 wxwx;
	stdmath_bool4 get_wxwx() { return {self->w,self->x,self->w,self->x}; }
	stdmath_bool4 set_wxwx(stdmath_bool4 value) { self->w = value.x; self->x = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_bool4 wxwy;
	stdmath_bool4 get_wxwy() { return {self->w,self->x,self->w,self->y}; }
	stdmath_bool4 set_wxwy(stdmath_bool4 value) { self->w = value.x; self->x = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_bool4 wxwz;
	stdmath_bool4 get_wxwz() { return {self->w,self->x,self->w,self->z}; }
	stdmath_bool4 set_wxwz(stdmath_bool4 value) { self->w = value.x; self->x = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_bool4 wxww;
	stdmath_bool4 get_wxww() { return {self->w,self->x,self->w,self->w}; }
	stdmath_bool4 set_wxww(stdmath_bool4 value) { self->w = value.x; self->x = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_bool4 wyxx;
	stdmath_bool4 get_wyxx() { return {self->w,self->y,self->x,self->x}; }
	stdmath_bool4 set_wyxx(stdmath_bool4 value) { self->w = value.x; self->y = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_bool4 wyxy;
	stdmath_bool4 get_wyxy() { return {self->w,self->y,self->x,self->y}; }
	stdmath_bool4 set_wyxy(stdmath_bool4 value) { self->w = value.x; self->y = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_bool4 wyxz;
	stdmath_bool4 get_wyxz() { return {self->w,self->y,self->x,self->z}; }
	stdmath_bool4 set_wyxz(stdmath_bool4 value) { self->w = value.x; self->y = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_bool4 wyxw;
	stdmath_bool4 get_wyxw() { return {self->w,self->y,self->x,self->w}; }
	stdmath_bool4 set_wyxw(stdmath_bool4 value) { self->w = value.x; self->y = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_bool4 wyyx;
	stdmath_bool4 get_wyyx() { return {self->w,self->y,self->y,self->x}; }
	stdmath_bool4 set_wyyx(stdmath_bool4 value) { self->w = value.x; self->y = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_bool4 wyyy;
	stdmath_bool4 get_wyyy() { return {self->w,self->y,self->y,self->y}; }
	stdmath_bool4 set_wyyy(stdmath_bool4 value) { self->w = value.x; self->y = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_bool4 wyyz;
	stdmath_bool4 get_wyyz() { return {self->w,self->y,self->y,self->z}; }
	stdmath_bool4 set_wyyz(stdmath_bool4 value) { self->w = value.x; self->y = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_bool4 wyyw;
	stdmath_bool4 get_wyyw() { return {self->w,self->y,self->y,self->w}; }
	stdmath_bool4 set_wyyw(stdmath_bool4 value) { self->w = value.x; self->y = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_bool4 wyzx;
	stdmath_bool4 get_wyzx() { return {self->w,self->y,self->z,self->x}; }
	stdmath_bool4 set_wyzx(stdmath_bool4 value) { self->w = value.x; self->y = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_bool4 wyzy;
	stdmath_bool4 get_wyzy() { return {self->w,self->y,self->z,self->y}; }
	stdmath_bool4 set_wyzy(stdmath_bool4 value) { self->w = value.x; self->y = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_bool4 wyzz;
	stdmath_bool4 get_wyzz() { return {self->w,self->y,self->z,self->z}; }
	stdmath_bool4 set_wyzz(stdmath_bool4 value) { self->w = value.x; self->y = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_bool4 wyzw;
	stdmath_bool4 get_wyzw() { return {self->w,self->y,self->z,self->w}; }
	stdmath_bool4 set_wyzw(stdmath_bool4 value) { self->w = value.x; self->y = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_bool4 wywx;
	stdmath_bool4 get_wywx() { return {self->w,self->y,self->w,self->x}; }
	stdmath_bool4 set_wywx(stdmath_bool4 value) { self->w = value.x; self->y = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_bool4 wywy;
	stdmath_bool4 get_wywy() { return {self->w,self->y,self->w,self->y}; }
	stdmath_bool4 set_wywy(stdmath_bool4 value) { self->w = value.x; self->y = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_bool4 wywz;
	stdmath_bool4 get_wywz() { return {self->w,self->y,self->w,self->z}; }
	stdmath_bool4 set_wywz(stdmath_bool4 value) { self->w = value.x; self->y = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_bool4 wyww;
	stdmath_bool4 get_wyww() { return {self->w,self->y,self->w,self->w}; }
	stdmath_bool4 set_wyww(stdmath_bool4 value) { self->w = value.x; self->y = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_bool4 wzxx;
	stdmath_bool4 get_wzxx() { return {self->w,self->z,self->x,self->x}; }
	stdmath_bool4 set_wzxx(stdmath_bool4 value) { self->w = value.x; self->z = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_bool4 wzxy;
	stdmath_bool4 get_wzxy() { return {self->w,self->z,self->x,self->y}; }
	stdmath_bool4 set_wzxy(stdmath_bool4 value) { self->w = value.x; self->z = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_bool4 wzxz;
	stdmath_bool4 get_wzxz() { return {self->w,self->z,self->x,self->z}; }
	stdmath_bool4 set_wzxz(stdmath_bool4 value) { self->w = value.x; self->z = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_bool4 wzxw;
	stdmath_bool4 get_wzxw() { return {self->w,self->z,self->x,self->w}; }
	stdmath_bool4 set_wzxw(stdmath_bool4 value) { self->w = value.x; self->z = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_bool4 wzyx;
	stdmath_bool4 get_wzyx() { return {self->w,self->z,self->y,self->x}; }
	stdmath_bool4 set_wzyx(stdmath_bool4 value) { self->w = value.x; self->z = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_bool4 wzyy;
	stdmath_bool4 get_wzyy() { return {self->w,self->z,self->y,self->y}; }
	stdmath_bool4 set_wzyy(stdmath_bool4 value) { self->w = value.x; self->z = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_bool4 wzyz;
	stdmath_bool4 get_wzyz() { return {self->w,self->z,self->y,self->z}; }
	stdmath_bool4 set_wzyz(stdmath_bool4 value) { self->w = value.x; self->z = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_bool4 wzyw;
	stdmath_bool4 get_wzyw() { return {self->w,self->z,self->y,self->w}; }
	stdmath_bool4 set_wzyw(stdmath_bool4 value) { self->w = value.x; self->z = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_bool4 wzzx;
	stdmath_bool4 get_wzzx() { return {self->w,self->z,self->z,self->x}; }
	stdmath_bool4 set_wzzx(stdmath_bool4 value) { self->w = value.x; self->z = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_bool4 wzzy;
	stdmath_bool4 get_wzzy() { return {self->w,self->z,self->z,self->y}; }
	stdmath_bool4 set_wzzy(stdmath_bool4 value) { self->w = value.x; self->z = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_bool4 wzzz;
	stdmath_bool4 get_wzzz() { return {self->w,self->z,self->z,self->z}; }
	stdmath_bool4 set_wzzz(stdmath_bool4 value) { self->w = value.x; self->z = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_bool4 wzzw;
	stdmath_bool4 get_wzzw() { return {self->w,self->z,self->z,self->w}; }
	stdmath_bool4 set_wzzw(stdmath_bool4 value) { self->w = value.x; self->z = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_bool4 wzwx;
	stdmath_bool4 get_wzwx() { return {self->w,self->z,self->w,self->x}; }
	stdmath_bool4 set_wzwx(stdmath_bool4 value) { self->w = value.x; self->z = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_bool4 wzwy;
	stdmath_bool4 get_wzwy() { return {self->w,self->z,self->w,self->y}; }
	stdmath_bool4 set_wzwy(stdmath_bool4 value) { self->w = value.x; self->z = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_bool4 wzwz;
	stdmath_bool4 get_wzwz() { return {self->w,self->z,self->w,self->z}; }
	stdmath_bool4 set_wzwz(stdmath_bool4 value) { self->w = value.x; self->z = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_bool4 wzww;
	stdmath_bool4 get_wzww() { return {self->w,self->z,self->w,self->w}; }
	stdmath_bool4 set_wzww(stdmath_bool4 value) { self->w = value.x; self->z = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_bool4 wwxx;
	stdmath_bool4 get_wwxx() { return {self->w,self->w,self->x,self->x}; }
	stdmath_bool4 set_wwxx(stdmath_bool4 value) { self->w = value.x; self->w = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_bool4 wwxy;
	stdmath_bool4 get_wwxy() { return {self->w,self->w,self->x,self->y}; }
	stdmath_bool4 set_wwxy(stdmath_bool4 value) { self->w = value.x; self->w = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_bool4 wwxz;
	stdmath_bool4 get_wwxz() { return {self->w,self->w,self->x,self->z}; }
	stdmath_bool4 set_wwxz(stdmath_bool4 value) { self->w = value.x; self->w = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_bool4 wwxw;
	stdmath_bool4 get_wwxw() { return {self->w,self->w,self->x,self->w}; }
	stdmath_bool4 set_wwxw(stdmath_bool4 value) { self->w = value.x; self->w = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_bool4 wwyx;
	stdmath_bool4 get_wwyx() { return {self->w,self->w,self->y,self->x}; }
	stdmath_bool4 set_wwyx(stdmath_bool4 value) { self->w = value.x; self->w = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_bool4 wwyy;
	stdmath_bool4 get_wwyy() { return {self->w,self->w,self->y,self->y}; }
	stdmath_bool4 set_wwyy(stdmath_bool4 value) { self->w = value.x; self->w = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_bool4 wwyz;
	stdmath_bool4 get_wwyz() { return {self->w,self->w,self->y,self->z}; }
	stdmath_bool4 set_wwyz(stdmath_bool4 value) { self->w = value.x; self->w = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_bool4 wwyw;
	stdmath_bool4 get_wwyw() { return {self->w,self->w,self->y,self->w}; }
	stdmath_bool4 set_wwyw(stdmath_bool4 value) { self->w = value.x; self->w = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_bool4 wwzx;
	stdmath_bool4 get_wwzx() { return {self->w,self->w,self->z,self->x}; }
	stdmath_bool4 set_wwzx(stdmath_bool4 value) { self->w = value.x; self->w = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_bool4 wwzy;
	stdmath_bool4 get_wwzy() { return {self->w,self->w,self->z,self->y}; }
	stdmath_bool4 set_wwzy(stdmath_bool4 value) { self->w = value.x; self->w = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_bool4 wwzz;
	stdmath_bool4 get_wwzz() { return {self->w,self->w,self->z,self->z}; }
	stdmath_bool4 set_wwzz(stdmath_bool4 value) { self->w = value.x; self->w = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_bool4 wwzw;
	stdmath_bool4 get_wwzw() { return {self->w,self->w,self->z,self->w}; }
	stdmath_bool4 set_wwzw(stdmath_bool4 value) { self->w = value.x; self->w = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_bool4 wwwx;
	stdmath_bool4 get_wwwx() { return {self->w,self->w,self->w,self->x}; }
	stdmath_bool4 set_wwwx(stdmath_bool4 value) { self->w = value.x; self->w = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_bool4 wwwy;
	stdmath_bool4 get_wwwy() { return {self->w,self->w,self->w,self->y}; }
	stdmath_bool4 set_wwwy(stdmath_bool4 value) { self->w = value.x; self->w = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_bool4 wwwz;
	stdmath_bool4 get_wwwz() { return {self->w,self->w,self->w,self->z}; }
	stdmath_bool4 set_wwwz(stdmath_bool4 value) { self->w = value.x; self->w = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_bool4 wwww;
	stdmath_bool4 get_wwww() { return {self->w,self->w,self->w,self->w}; }
	stdmath_bool4 set_wwww(stdmath_bool4 value) { self->w = value.x; self->w = value.y; self->w = value.z; self->w = value.w; return *self; }



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

	bool4 _equal_to(stdmath_bool4 o) {
		return stdmath_bool4_equal_to(*self, o);
	}
	bool4 _not_equal_to(stdmath_bool4 o) {
		return stdmath_bool4_not_equal_to(*self, o);
	}
	bool4 _less_than(stdmath_bool4 o) {
		return stdmath_bool4_less_than(*self, o);
	}
	bool4 _less_than_or_equal_to(stdmath_bool4 o) {
		return stdmath_bool4_less_than_or_equal_to(*self, o);
	}
	bool4 _greater_than(stdmath_bool4 o) {
		return stdmath_bool4_greater_than(*self, o);
	}
	bool4 _greater_than_or_equal_to(stdmath_bool4 o) {
		return stdmath_bool4_greater_than_or_equal_to(*self, o);
	}
	
	bool _length_squared() {
		return stdmath_bool4_length_squared(*self);
	}
	bool _length() {
		return stdmath_bool4_length(*self);
	}
	bool _dot() {
		return stdmath_bool4_dot(*self);
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
	stdmath_bool4 _lerp(stdmath_bool4 o, bool t) {
		return stdmath_bool4_lerp(*self, o, t);
	}
	stdmath_bool4 _clamp(stdmath_bool4 min, stdmath_bool4 max) {
		return stdmath_bool4_clamp(*self, min, max);
	}
	stdmath_bool4 _reflect(stdmath_bool4 n) {
		return stdmath_bool4_reflect(*self, n);
	}
	bool4 _approximately_equal(stdmath_bool4 o) {
		return stdmath_bool4_approximately_equal()
	}

#if true
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

	bool _get_element(size_t i) {
		return self->data[i];
	}

	bool _set_element(size_t i, bool value) {
		return self->data[i] = value;
	}
}
