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
	stdmath_double2 get_xx() { return {self->x,self->x}; }
	stdmath_double4 set_xx(stdmath_double2 value) { self->x = value.x; self->x = value.y; return *self; }

	stdmath_double2 xy;
	stdmath_double2 get_xy() { return {self->x,self->y}; }
	stdmath_double4 set_xy(stdmath_double2 value) { self->x = value.x; self->y = value.y; return *self; }

	stdmath_double2 xz;
	stdmath_double2 get_xz() { return {self->x,self->z}; }
	stdmath_double4 set_xz(stdmath_double2 value) { self->x = value.x; self->z = value.y; return *self; }

	stdmath_double2 xw;
	stdmath_double2 get_xw() { return {self->x,self->w}; }
	stdmath_double4 set_xw(stdmath_double2 value) { self->x = value.x; self->w = value.y; return *self; }

	stdmath_double2 yx;
	stdmath_double2 get_yx() { return {self->y,self->x}; }
	stdmath_double4 set_yx(stdmath_double2 value) { self->y = value.x; self->x = value.y; return *self; }

	stdmath_double2 yy;
	stdmath_double2 get_yy() { return {self->y,self->y}; }
	stdmath_double4 set_yy(stdmath_double2 value) { self->y = value.x; self->y = value.y; return *self; }

	stdmath_double2 yz;
	stdmath_double2 get_yz() { return {self->y,self->z}; }
	stdmath_double4 set_yz(stdmath_double2 value) { self->y = value.x; self->z = value.y; return *self; }

	stdmath_double2 yw;
	stdmath_double2 get_yw() { return {self->y,self->w}; }
	stdmath_double4 set_yw(stdmath_double2 value) { self->y = value.x; self->w = value.y; return *self; }

	stdmath_double2 zx;
	stdmath_double2 get_zx() { return {self->z,self->x}; }
	stdmath_double4 set_zx(stdmath_double2 value) { self->z = value.x; self->x = value.y; return *self; }

	stdmath_double2 zy;
	stdmath_double2 get_zy() { return {self->z,self->y}; }
	stdmath_double4 set_zy(stdmath_double2 value) { self->z = value.x; self->y = value.y; return *self; }

	stdmath_double2 zz;
	stdmath_double2 get_zz() { return {self->z,self->z}; }
	stdmath_double4 set_zz(stdmath_double2 value) { self->z = value.x; self->z = value.y; return *self; }

	stdmath_double2 zw;
	stdmath_double2 get_zw() { return {self->z,self->w}; }
	stdmath_double4 set_zw(stdmath_double2 value) { self->z = value.x; self->w = value.y; return *self; }

	stdmath_double2 wx;
	stdmath_double2 get_wx() { return {self->w,self->x}; }
	stdmath_double4 set_wx(stdmath_double2 value) { self->w = value.x; self->x = value.y; return *self; }

	stdmath_double2 wy;
	stdmath_double2 get_wy() { return {self->w,self->y}; }
	stdmath_double4 set_wy(stdmath_double2 value) { self->w = value.x; self->y = value.y; return *self; }

	stdmath_double2 wz;
	stdmath_double2 get_wz() { return {self->w,self->z}; }
	stdmath_double4 set_wz(stdmath_double2 value) { self->w = value.x; self->z = value.y; return *self; }

	stdmath_double2 ww;
	stdmath_double2 get_ww() { return {self->w,self->w}; }
	stdmath_double4 set_ww(stdmath_double2 value) { self->w = value.x; self->w = value.y; return *self; }

	stdmath_double3 xxx;
	stdmath_double3 get_xxx() { return {self->x,self->x,self->x}; }
	stdmath_double4 set_xxx(stdmath_double3 value) { self->x = value.x; self->x = value.y; self->x = value.z; return *self; }

	stdmath_double3 xxy;
	stdmath_double3 get_xxy() { return {self->x,self->x,self->y}; }
	stdmath_double4 set_xxy(stdmath_double3 value) { self->x = value.x; self->x = value.y; self->y = value.z; return *self; }

	stdmath_double3 xxz;
	stdmath_double3 get_xxz() { return {self->x,self->x,self->z}; }
	stdmath_double4 set_xxz(stdmath_double3 value) { self->x = value.x; self->x = value.y; self->z = value.z; return *self; }

	stdmath_double3 xxw;
	stdmath_double3 get_xxw() { return {self->x,self->x,self->w}; }
	stdmath_double4 set_xxw(stdmath_double3 value) { self->x = value.x; self->x = value.y; self->w = value.z; return *self; }

	stdmath_double3 xyx;
	stdmath_double3 get_xyx() { return {self->x,self->y,self->x}; }
	stdmath_double4 set_xyx(stdmath_double3 value) { self->x = value.x; self->y = value.y; self->x = value.z; return *self; }

	stdmath_double3 xyy;
	stdmath_double3 get_xyy() { return {self->x,self->y,self->y}; }
	stdmath_double4 set_xyy(stdmath_double3 value) { self->x = value.x; self->y = value.y; self->y = value.z; return *self; }

	stdmath_double3 xyz;
	stdmath_double3 get_xyz() { return {self->x,self->y,self->z}; }
	stdmath_double4 set_xyz(stdmath_double3 value) { self->x = value.x; self->y = value.y; self->z = value.z; return *self; }

	stdmath_double3 xyw;
	stdmath_double3 get_xyw() { return {self->x,self->y,self->w}; }
	stdmath_double4 set_xyw(stdmath_double3 value) { self->x = value.x; self->y = value.y; self->w = value.z; return *self; }

	stdmath_double3 xzx;
	stdmath_double3 get_xzx() { return {self->x,self->z,self->x}; }
	stdmath_double4 set_xzx(stdmath_double3 value) { self->x = value.x; self->z = value.y; self->x = value.z; return *self; }

	stdmath_double3 xzy;
	stdmath_double3 get_xzy() { return {self->x,self->z,self->y}; }
	stdmath_double4 set_xzy(stdmath_double3 value) { self->x = value.x; self->z = value.y; self->y = value.z; return *self; }

	stdmath_double3 xzz;
	stdmath_double3 get_xzz() { return {self->x,self->z,self->z}; }
	stdmath_double4 set_xzz(stdmath_double3 value) { self->x = value.x; self->z = value.y; self->z = value.z; return *self; }

	stdmath_double3 xzw;
	stdmath_double3 get_xzw() { return {self->x,self->z,self->w}; }
	stdmath_double4 set_xzw(stdmath_double3 value) { self->x = value.x; self->z = value.y; self->w = value.z; return *self; }

	stdmath_double3 xwx;
	stdmath_double3 get_xwx() { return {self->x,self->w,self->x}; }
	stdmath_double4 set_xwx(stdmath_double3 value) { self->x = value.x; self->w = value.y; self->x = value.z; return *self; }

	stdmath_double3 xwy;
	stdmath_double3 get_xwy() { return {self->x,self->w,self->y}; }
	stdmath_double4 set_xwy(stdmath_double3 value) { self->x = value.x; self->w = value.y; self->y = value.z; return *self; }

	stdmath_double3 xwz;
	stdmath_double3 get_xwz() { return {self->x,self->w,self->z}; }
	stdmath_double4 set_xwz(stdmath_double3 value) { self->x = value.x; self->w = value.y; self->z = value.z; return *self; }

	stdmath_double3 xww;
	stdmath_double3 get_xww() { return {self->x,self->w,self->w}; }
	stdmath_double4 set_xww(stdmath_double3 value) { self->x = value.x; self->w = value.y; self->w = value.z; return *self; }

	stdmath_double3 yxx;
	stdmath_double3 get_yxx() { return {self->y,self->x,self->x}; }
	stdmath_double4 set_yxx(stdmath_double3 value) { self->y = value.x; self->x = value.y; self->x = value.z; return *self; }

	stdmath_double3 yxy;
	stdmath_double3 get_yxy() { return {self->y,self->x,self->y}; }
	stdmath_double4 set_yxy(stdmath_double3 value) { self->y = value.x; self->x = value.y; self->y = value.z; return *self; }

	stdmath_double3 yxz;
	stdmath_double3 get_yxz() { return {self->y,self->x,self->z}; }
	stdmath_double4 set_yxz(stdmath_double3 value) { self->y = value.x; self->x = value.y; self->z = value.z; return *self; }

	stdmath_double3 yxw;
	stdmath_double3 get_yxw() { return {self->y,self->x,self->w}; }
	stdmath_double4 set_yxw(stdmath_double3 value) { self->y = value.x; self->x = value.y; self->w = value.z; return *self; }

	stdmath_double3 yyx;
	stdmath_double3 get_yyx() { return {self->y,self->y,self->x}; }
	stdmath_double4 set_yyx(stdmath_double3 value) { self->y = value.x; self->y = value.y; self->x = value.z; return *self; }

	stdmath_double3 yyy;
	stdmath_double3 get_yyy() { return {self->y,self->y,self->y}; }
	stdmath_double4 set_yyy(stdmath_double3 value) { self->y = value.x; self->y = value.y; self->y = value.z; return *self; }

	stdmath_double3 yyz;
	stdmath_double3 get_yyz() { return {self->y,self->y,self->z}; }
	stdmath_double4 set_yyz(stdmath_double3 value) { self->y = value.x; self->y = value.y; self->z = value.z; return *self; }

	stdmath_double3 yyw;
	stdmath_double3 get_yyw() { return {self->y,self->y,self->w}; }
	stdmath_double4 set_yyw(stdmath_double3 value) { self->y = value.x; self->y = value.y; self->w = value.z; return *self; }

	stdmath_double3 yzx;
	stdmath_double3 get_yzx() { return {self->y,self->z,self->x}; }
	stdmath_double4 set_yzx(stdmath_double3 value) { self->y = value.x; self->z = value.y; self->x = value.z; return *self; }

	stdmath_double3 yzy;
	stdmath_double3 get_yzy() { return {self->y,self->z,self->y}; }
	stdmath_double4 set_yzy(stdmath_double3 value) { self->y = value.x; self->z = value.y; self->y = value.z; return *self; }

	stdmath_double3 yzz;
	stdmath_double3 get_yzz() { return {self->y,self->z,self->z}; }
	stdmath_double4 set_yzz(stdmath_double3 value) { self->y = value.x; self->z = value.y; self->z = value.z; return *self; }

	stdmath_double3 yzw;
	stdmath_double3 get_yzw() { return {self->y,self->z,self->w}; }
	stdmath_double4 set_yzw(stdmath_double3 value) { self->y = value.x; self->z = value.y; self->w = value.z; return *self; }

	stdmath_double3 ywx;
	stdmath_double3 get_ywx() { return {self->y,self->w,self->x}; }
	stdmath_double4 set_ywx(stdmath_double3 value) { self->y = value.x; self->w = value.y; self->x = value.z; return *self; }

	stdmath_double3 ywy;
	stdmath_double3 get_ywy() { return {self->y,self->w,self->y}; }
	stdmath_double4 set_ywy(stdmath_double3 value) { self->y = value.x; self->w = value.y; self->y = value.z; return *self; }

	stdmath_double3 ywz;
	stdmath_double3 get_ywz() { return {self->y,self->w,self->z}; }
	stdmath_double4 set_ywz(stdmath_double3 value) { self->y = value.x; self->w = value.y; self->z = value.z; return *self; }

	stdmath_double3 yww;
	stdmath_double3 get_yww() { return {self->y,self->w,self->w}; }
	stdmath_double4 set_yww(stdmath_double3 value) { self->y = value.x; self->w = value.y; self->w = value.z; return *self; }

	stdmath_double3 zxx;
	stdmath_double3 get_zxx() { return {self->z,self->x,self->x}; }
	stdmath_double4 set_zxx(stdmath_double3 value) { self->z = value.x; self->x = value.y; self->x = value.z; return *self; }

	stdmath_double3 zxy;
	stdmath_double3 get_zxy() { return {self->z,self->x,self->y}; }
	stdmath_double4 set_zxy(stdmath_double3 value) { self->z = value.x; self->x = value.y; self->y = value.z; return *self; }

	stdmath_double3 zxz;
	stdmath_double3 get_zxz() { return {self->z,self->x,self->z}; }
	stdmath_double4 set_zxz(stdmath_double3 value) { self->z = value.x; self->x = value.y; self->z = value.z; return *self; }

	stdmath_double3 zxw;
	stdmath_double3 get_zxw() { return {self->z,self->x,self->w}; }
	stdmath_double4 set_zxw(stdmath_double3 value) { self->z = value.x; self->x = value.y; self->w = value.z; return *self; }

	stdmath_double3 zyx;
	stdmath_double3 get_zyx() { return {self->z,self->y,self->x}; }
	stdmath_double4 set_zyx(stdmath_double3 value) { self->z = value.x; self->y = value.y; self->x = value.z; return *self; }

	stdmath_double3 zyy;
	stdmath_double3 get_zyy() { return {self->z,self->y,self->y}; }
	stdmath_double4 set_zyy(stdmath_double3 value) { self->z = value.x; self->y = value.y; self->y = value.z; return *self; }

	stdmath_double3 zyz;
	stdmath_double3 get_zyz() { return {self->z,self->y,self->z}; }
	stdmath_double4 set_zyz(stdmath_double3 value) { self->z = value.x; self->y = value.y; self->z = value.z; return *self; }

	stdmath_double3 zyw;
	stdmath_double3 get_zyw() { return {self->z,self->y,self->w}; }
	stdmath_double4 set_zyw(stdmath_double3 value) { self->z = value.x; self->y = value.y; self->w = value.z; return *self; }

	stdmath_double3 zzx;
	stdmath_double3 get_zzx() { return {self->z,self->z,self->x}; }
	stdmath_double4 set_zzx(stdmath_double3 value) { self->z = value.x; self->z = value.y; self->x = value.z; return *self; }

	stdmath_double3 zzy;
	stdmath_double3 get_zzy() { return {self->z,self->z,self->y}; }
	stdmath_double4 set_zzy(stdmath_double3 value) { self->z = value.x; self->z = value.y; self->y = value.z; return *self; }

	stdmath_double3 zzz;
	stdmath_double3 get_zzz() { return {self->z,self->z,self->z}; }
	stdmath_double4 set_zzz(stdmath_double3 value) { self->z = value.x; self->z = value.y; self->z = value.z; return *self; }

	stdmath_double3 zzw;
	stdmath_double3 get_zzw() { return {self->z,self->z,self->w}; }
	stdmath_double4 set_zzw(stdmath_double3 value) { self->z = value.x; self->z = value.y; self->w = value.z; return *self; }

	stdmath_double3 zwx;
	stdmath_double3 get_zwx() { return {self->z,self->w,self->x}; }
	stdmath_double4 set_zwx(stdmath_double3 value) { self->z = value.x; self->w = value.y; self->x = value.z; return *self; }

	stdmath_double3 zwy;
	stdmath_double3 get_zwy() { return {self->z,self->w,self->y}; }
	stdmath_double4 set_zwy(stdmath_double3 value) { self->z = value.x; self->w = value.y; self->y = value.z; return *self; }

	stdmath_double3 zwz;
	stdmath_double3 get_zwz() { return {self->z,self->w,self->z}; }
	stdmath_double4 set_zwz(stdmath_double3 value) { self->z = value.x; self->w = value.y; self->z = value.z; return *self; }

	stdmath_double3 zww;
	stdmath_double3 get_zww() { return {self->z,self->w,self->w}; }
	stdmath_double4 set_zww(stdmath_double3 value) { self->z = value.x; self->w = value.y; self->w = value.z; return *self; }

	stdmath_double3 wxx;
	stdmath_double3 get_wxx() { return {self->w,self->x,self->x}; }
	stdmath_double4 set_wxx(stdmath_double3 value) { self->w = value.x; self->x = value.y; self->x = value.z; return *self; }

	stdmath_double3 wxy;
	stdmath_double3 get_wxy() { return {self->w,self->x,self->y}; }
	stdmath_double4 set_wxy(stdmath_double3 value) { self->w = value.x; self->x = value.y; self->y = value.z; return *self; }

	stdmath_double3 wxz;
	stdmath_double3 get_wxz() { return {self->w,self->x,self->z}; }
	stdmath_double4 set_wxz(stdmath_double3 value) { self->w = value.x; self->x = value.y; self->z = value.z; return *self; }

	stdmath_double3 wxw;
	stdmath_double3 get_wxw() { return {self->w,self->x,self->w}; }
	stdmath_double4 set_wxw(stdmath_double3 value) { self->w = value.x; self->x = value.y; self->w = value.z; return *self; }

	stdmath_double3 wyx;
	stdmath_double3 get_wyx() { return {self->w,self->y,self->x}; }
	stdmath_double4 set_wyx(stdmath_double3 value) { self->w = value.x; self->y = value.y; self->x = value.z; return *self; }

	stdmath_double3 wyy;
	stdmath_double3 get_wyy() { return {self->w,self->y,self->y}; }
	stdmath_double4 set_wyy(stdmath_double3 value) { self->w = value.x; self->y = value.y; self->y = value.z; return *self; }

	stdmath_double3 wyz;
	stdmath_double3 get_wyz() { return {self->w,self->y,self->z}; }
	stdmath_double4 set_wyz(stdmath_double3 value) { self->w = value.x; self->y = value.y; self->z = value.z; return *self; }

	stdmath_double3 wyw;
	stdmath_double3 get_wyw() { return {self->w,self->y,self->w}; }
	stdmath_double4 set_wyw(stdmath_double3 value) { self->w = value.x; self->y = value.y; self->w = value.z; return *self; }

	stdmath_double3 wzx;
	stdmath_double3 get_wzx() { return {self->w,self->z,self->x}; }
	stdmath_double4 set_wzx(stdmath_double3 value) { self->w = value.x; self->z = value.y; self->x = value.z; return *self; }

	stdmath_double3 wzy;
	stdmath_double3 get_wzy() { return {self->w,self->z,self->y}; }
	stdmath_double4 set_wzy(stdmath_double3 value) { self->w = value.x; self->z = value.y; self->y = value.z; return *self; }

	stdmath_double3 wzz;
	stdmath_double3 get_wzz() { return {self->w,self->z,self->z}; }
	stdmath_double4 set_wzz(stdmath_double3 value) { self->w = value.x; self->z = value.y; self->z = value.z; return *self; }

	stdmath_double3 wzw;
	stdmath_double3 get_wzw() { return {self->w,self->z,self->w}; }
	stdmath_double4 set_wzw(stdmath_double3 value) { self->w = value.x; self->z = value.y; self->w = value.z; return *self; }

	stdmath_double3 wwx;
	stdmath_double3 get_wwx() { return {self->w,self->w,self->x}; }
	stdmath_double4 set_wwx(stdmath_double3 value) { self->w = value.x; self->w = value.y; self->x = value.z; return *self; }

	stdmath_double3 wwy;
	stdmath_double3 get_wwy() { return {self->w,self->w,self->y}; }
	stdmath_double4 set_wwy(stdmath_double3 value) { self->w = value.x; self->w = value.y; self->y = value.z; return *self; }

	stdmath_double3 wwz;
	stdmath_double3 get_wwz() { return {self->w,self->w,self->z}; }
	stdmath_double4 set_wwz(stdmath_double3 value) { self->w = value.x; self->w = value.y; self->z = value.z; return *self; }

	stdmath_double3 www;
	stdmath_double3 get_www() { return {self->w,self->w,self->w}; }
	stdmath_double4 set_www(stdmath_double3 value) { self->w = value.x; self->w = value.y; self->w = value.z; return *self; }

	stdmath_double4 xxxx;
	stdmath_double4 get_xxxx() { return {self->x,self->x,self->x,self->x}; }
	stdmath_double4 set_xxxx(stdmath_double4 value) { self->x = value.x; self->x = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_double4 xxxy;
	stdmath_double4 get_xxxy() { return {self->x,self->x,self->x,self->y}; }
	stdmath_double4 set_xxxy(stdmath_double4 value) { self->x = value.x; self->x = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_double4 xxxz;
	stdmath_double4 get_xxxz() { return {self->x,self->x,self->x,self->z}; }
	stdmath_double4 set_xxxz(stdmath_double4 value) { self->x = value.x; self->x = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_double4 xxxw;
	stdmath_double4 get_xxxw() { return {self->x,self->x,self->x,self->w}; }
	stdmath_double4 set_xxxw(stdmath_double4 value) { self->x = value.x; self->x = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_double4 xxyx;
	stdmath_double4 get_xxyx() { return {self->x,self->x,self->y,self->x}; }
	stdmath_double4 set_xxyx(stdmath_double4 value) { self->x = value.x; self->x = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_double4 xxyy;
	stdmath_double4 get_xxyy() { return {self->x,self->x,self->y,self->y}; }
	stdmath_double4 set_xxyy(stdmath_double4 value) { self->x = value.x; self->x = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_double4 xxyz;
	stdmath_double4 get_xxyz() { return {self->x,self->x,self->y,self->z}; }
	stdmath_double4 set_xxyz(stdmath_double4 value) { self->x = value.x; self->x = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_double4 xxyw;
	stdmath_double4 get_xxyw() { return {self->x,self->x,self->y,self->w}; }
	stdmath_double4 set_xxyw(stdmath_double4 value) { self->x = value.x; self->x = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_double4 xxzx;
	stdmath_double4 get_xxzx() { return {self->x,self->x,self->z,self->x}; }
	stdmath_double4 set_xxzx(stdmath_double4 value) { self->x = value.x; self->x = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_double4 xxzy;
	stdmath_double4 get_xxzy() { return {self->x,self->x,self->z,self->y}; }
	stdmath_double4 set_xxzy(stdmath_double4 value) { self->x = value.x; self->x = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_double4 xxzz;
	stdmath_double4 get_xxzz() { return {self->x,self->x,self->z,self->z}; }
	stdmath_double4 set_xxzz(stdmath_double4 value) { self->x = value.x; self->x = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_double4 xxzw;
	stdmath_double4 get_xxzw() { return {self->x,self->x,self->z,self->w}; }
	stdmath_double4 set_xxzw(stdmath_double4 value) { self->x = value.x; self->x = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_double4 xxwx;
	stdmath_double4 get_xxwx() { return {self->x,self->x,self->w,self->x}; }
	stdmath_double4 set_xxwx(stdmath_double4 value) { self->x = value.x; self->x = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_double4 xxwy;
	stdmath_double4 get_xxwy() { return {self->x,self->x,self->w,self->y}; }
	stdmath_double4 set_xxwy(stdmath_double4 value) { self->x = value.x; self->x = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_double4 xxwz;
	stdmath_double4 get_xxwz() { return {self->x,self->x,self->w,self->z}; }
	stdmath_double4 set_xxwz(stdmath_double4 value) { self->x = value.x; self->x = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_double4 xxww;
	stdmath_double4 get_xxww() { return {self->x,self->x,self->w,self->w}; }
	stdmath_double4 set_xxww(stdmath_double4 value) { self->x = value.x; self->x = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_double4 xyxx;
	stdmath_double4 get_xyxx() { return {self->x,self->y,self->x,self->x}; }
	stdmath_double4 set_xyxx(stdmath_double4 value) { self->x = value.x; self->y = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_double4 xyxy;
	stdmath_double4 get_xyxy() { return {self->x,self->y,self->x,self->y}; }
	stdmath_double4 set_xyxy(stdmath_double4 value) { self->x = value.x; self->y = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_double4 xyxz;
	stdmath_double4 get_xyxz() { return {self->x,self->y,self->x,self->z}; }
	stdmath_double4 set_xyxz(stdmath_double4 value) { self->x = value.x; self->y = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_double4 xyxw;
	stdmath_double4 get_xyxw() { return {self->x,self->y,self->x,self->w}; }
	stdmath_double4 set_xyxw(stdmath_double4 value) { self->x = value.x; self->y = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_double4 xyyx;
	stdmath_double4 get_xyyx() { return {self->x,self->y,self->y,self->x}; }
	stdmath_double4 set_xyyx(stdmath_double4 value) { self->x = value.x; self->y = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_double4 xyyy;
	stdmath_double4 get_xyyy() { return {self->x,self->y,self->y,self->y}; }
	stdmath_double4 set_xyyy(stdmath_double4 value) { self->x = value.x; self->y = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_double4 xyyz;
	stdmath_double4 get_xyyz() { return {self->x,self->y,self->y,self->z}; }
	stdmath_double4 set_xyyz(stdmath_double4 value) { self->x = value.x; self->y = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_double4 xyyw;
	stdmath_double4 get_xyyw() { return {self->x,self->y,self->y,self->w}; }
	stdmath_double4 set_xyyw(stdmath_double4 value) { self->x = value.x; self->y = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_double4 xyzx;
	stdmath_double4 get_xyzx() { return {self->x,self->y,self->z,self->x}; }
	stdmath_double4 set_xyzx(stdmath_double4 value) { self->x = value.x; self->y = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_double4 xyzy;
	stdmath_double4 get_xyzy() { return {self->x,self->y,self->z,self->y}; }
	stdmath_double4 set_xyzy(stdmath_double4 value) { self->x = value.x; self->y = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_double4 xyzz;
	stdmath_double4 get_xyzz() { return {self->x,self->y,self->z,self->z}; }
	stdmath_double4 set_xyzz(stdmath_double4 value) { self->x = value.x; self->y = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_double4 xyzw;
	stdmath_double4 get_xyzw() { return {self->x,self->y,self->z,self->w}; }
	stdmath_double4 set_xyzw(stdmath_double4 value) { self->x = value.x; self->y = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_double4 xywx;
	stdmath_double4 get_xywx() { return {self->x,self->y,self->w,self->x}; }
	stdmath_double4 set_xywx(stdmath_double4 value) { self->x = value.x; self->y = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_double4 xywy;
	stdmath_double4 get_xywy() { return {self->x,self->y,self->w,self->y}; }
	stdmath_double4 set_xywy(stdmath_double4 value) { self->x = value.x; self->y = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_double4 xywz;
	stdmath_double4 get_xywz() { return {self->x,self->y,self->w,self->z}; }
	stdmath_double4 set_xywz(stdmath_double4 value) { self->x = value.x; self->y = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_double4 xyww;
	stdmath_double4 get_xyww() { return {self->x,self->y,self->w,self->w}; }
	stdmath_double4 set_xyww(stdmath_double4 value) { self->x = value.x; self->y = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_double4 xzxx;
	stdmath_double4 get_xzxx() { return {self->x,self->z,self->x,self->x}; }
	stdmath_double4 set_xzxx(stdmath_double4 value) { self->x = value.x; self->z = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_double4 xzxy;
	stdmath_double4 get_xzxy() { return {self->x,self->z,self->x,self->y}; }
	stdmath_double4 set_xzxy(stdmath_double4 value) { self->x = value.x; self->z = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_double4 xzxz;
	stdmath_double4 get_xzxz() { return {self->x,self->z,self->x,self->z}; }
	stdmath_double4 set_xzxz(stdmath_double4 value) { self->x = value.x; self->z = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_double4 xzxw;
	stdmath_double4 get_xzxw() { return {self->x,self->z,self->x,self->w}; }
	stdmath_double4 set_xzxw(stdmath_double4 value) { self->x = value.x; self->z = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_double4 xzyx;
	stdmath_double4 get_xzyx() { return {self->x,self->z,self->y,self->x}; }
	stdmath_double4 set_xzyx(stdmath_double4 value) { self->x = value.x; self->z = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_double4 xzyy;
	stdmath_double4 get_xzyy() { return {self->x,self->z,self->y,self->y}; }
	stdmath_double4 set_xzyy(stdmath_double4 value) { self->x = value.x; self->z = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_double4 xzyz;
	stdmath_double4 get_xzyz() { return {self->x,self->z,self->y,self->z}; }
	stdmath_double4 set_xzyz(stdmath_double4 value) { self->x = value.x; self->z = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_double4 xzyw;
	stdmath_double4 get_xzyw() { return {self->x,self->z,self->y,self->w}; }
	stdmath_double4 set_xzyw(stdmath_double4 value) { self->x = value.x; self->z = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_double4 xzzx;
	stdmath_double4 get_xzzx() { return {self->x,self->z,self->z,self->x}; }
	stdmath_double4 set_xzzx(stdmath_double4 value) { self->x = value.x; self->z = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_double4 xzzy;
	stdmath_double4 get_xzzy() { return {self->x,self->z,self->z,self->y}; }
	stdmath_double4 set_xzzy(stdmath_double4 value) { self->x = value.x; self->z = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_double4 xzzz;
	stdmath_double4 get_xzzz() { return {self->x,self->z,self->z,self->z}; }
	stdmath_double4 set_xzzz(stdmath_double4 value) { self->x = value.x; self->z = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_double4 xzzw;
	stdmath_double4 get_xzzw() { return {self->x,self->z,self->z,self->w}; }
	stdmath_double4 set_xzzw(stdmath_double4 value) { self->x = value.x; self->z = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_double4 xzwx;
	stdmath_double4 get_xzwx() { return {self->x,self->z,self->w,self->x}; }
	stdmath_double4 set_xzwx(stdmath_double4 value) { self->x = value.x; self->z = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_double4 xzwy;
	stdmath_double4 get_xzwy() { return {self->x,self->z,self->w,self->y}; }
	stdmath_double4 set_xzwy(stdmath_double4 value) { self->x = value.x; self->z = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_double4 xzwz;
	stdmath_double4 get_xzwz() { return {self->x,self->z,self->w,self->z}; }
	stdmath_double4 set_xzwz(stdmath_double4 value) { self->x = value.x; self->z = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_double4 xzww;
	stdmath_double4 get_xzww() { return {self->x,self->z,self->w,self->w}; }
	stdmath_double4 set_xzww(stdmath_double4 value) { self->x = value.x; self->z = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_double4 xwxx;
	stdmath_double4 get_xwxx() { return {self->x,self->w,self->x,self->x}; }
	stdmath_double4 set_xwxx(stdmath_double4 value) { self->x = value.x; self->w = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_double4 xwxy;
	stdmath_double4 get_xwxy() { return {self->x,self->w,self->x,self->y}; }
	stdmath_double4 set_xwxy(stdmath_double4 value) { self->x = value.x; self->w = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_double4 xwxz;
	stdmath_double4 get_xwxz() { return {self->x,self->w,self->x,self->z}; }
	stdmath_double4 set_xwxz(stdmath_double4 value) { self->x = value.x; self->w = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_double4 xwxw;
	stdmath_double4 get_xwxw() { return {self->x,self->w,self->x,self->w}; }
	stdmath_double4 set_xwxw(stdmath_double4 value) { self->x = value.x; self->w = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_double4 xwyx;
	stdmath_double4 get_xwyx() { return {self->x,self->w,self->y,self->x}; }
	stdmath_double4 set_xwyx(stdmath_double4 value) { self->x = value.x; self->w = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_double4 xwyy;
	stdmath_double4 get_xwyy() { return {self->x,self->w,self->y,self->y}; }
	stdmath_double4 set_xwyy(stdmath_double4 value) { self->x = value.x; self->w = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_double4 xwyz;
	stdmath_double4 get_xwyz() { return {self->x,self->w,self->y,self->z}; }
	stdmath_double4 set_xwyz(stdmath_double4 value) { self->x = value.x; self->w = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_double4 xwyw;
	stdmath_double4 get_xwyw() { return {self->x,self->w,self->y,self->w}; }
	stdmath_double4 set_xwyw(stdmath_double4 value) { self->x = value.x; self->w = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_double4 xwzx;
	stdmath_double4 get_xwzx() { return {self->x,self->w,self->z,self->x}; }
	stdmath_double4 set_xwzx(stdmath_double4 value) { self->x = value.x; self->w = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_double4 xwzy;
	stdmath_double4 get_xwzy() { return {self->x,self->w,self->z,self->y}; }
	stdmath_double4 set_xwzy(stdmath_double4 value) { self->x = value.x; self->w = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_double4 xwzz;
	stdmath_double4 get_xwzz() { return {self->x,self->w,self->z,self->z}; }
	stdmath_double4 set_xwzz(stdmath_double4 value) { self->x = value.x; self->w = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_double4 xwzw;
	stdmath_double4 get_xwzw() { return {self->x,self->w,self->z,self->w}; }
	stdmath_double4 set_xwzw(stdmath_double4 value) { self->x = value.x; self->w = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_double4 xwwx;
	stdmath_double4 get_xwwx() { return {self->x,self->w,self->w,self->x}; }
	stdmath_double4 set_xwwx(stdmath_double4 value) { self->x = value.x; self->w = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_double4 xwwy;
	stdmath_double4 get_xwwy() { return {self->x,self->w,self->w,self->y}; }
	stdmath_double4 set_xwwy(stdmath_double4 value) { self->x = value.x; self->w = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_double4 xwwz;
	stdmath_double4 get_xwwz() { return {self->x,self->w,self->w,self->z}; }
	stdmath_double4 set_xwwz(stdmath_double4 value) { self->x = value.x; self->w = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_double4 xwww;
	stdmath_double4 get_xwww() { return {self->x,self->w,self->w,self->w}; }
	stdmath_double4 set_xwww(stdmath_double4 value) { self->x = value.x; self->w = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_double4 yxxx;
	stdmath_double4 get_yxxx() { return {self->y,self->x,self->x,self->x}; }
	stdmath_double4 set_yxxx(stdmath_double4 value) { self->y = value.x; self->x = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_double4 yxxy;
	stdmath_double4 get_yxxy() { return {self->y,self->x,self->x,self->y}; }
	stdmath_double4 set_yxxy(stdmath_double4 value) { self->y = value.x; self->x = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_double4 yxxz;
	stdmath_double4 get_yxxz() { return {self->y,self->x,self->x,self->z}; }
	stdmath_double4 set_yxxz(stdmath_double4 value) { self->y = value.x; self->x = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_double4 yxxw;
	stdmath_double4 get_yxxw() { return {self->y,self->x,self->x,self->w}; }
	stdmath_double4 set_yxxw(stdmath_double4 value) { self->y = value.x; self->x = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_double4 yxyx;
	stdmath_double4 get_yxyx() { return {self->y,self->x,self->y,self->x}; }
	stdmath_double4 set_yxyx(stdmath_double4 value) { self->y = value.x; self->x = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_double4 yxyy;
	stdmath_double4 get_yxyy() { return {self->y,self->x,self->y,self->y}; }
	stdmath_double4 set_yxyy(stdmath_double4 value) { self->y = value.x; self->x = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_double4 yxyz;
	stdmath_double4 get_yxyz() { return {self->y,self->x,self->y,self->z}; }
	stdmath_double4 set_yxyz(stdmath_double4 value) { self->y = value.x; self->x = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_double4 yxyw;
	stdmath_double4 get_yxyw() { return {self->y,self->x,self->y,self->w}; }
	stdmath_double4 set_yxyw(stdmath_double4 value) { self->y = value.x; self->x = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_double4 yxzx;
	stdmath_double4 get_yxzx() { return {self->y,self->x,self->z,self->x}; }
	stdmath_double4 set_yxzx(stdmath_double4 value) { self->y = value.x; self->x = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_double4 yxzy;
	stdmath_double4 get_yxzy() { return {self->y,self->x,self->z,self->y}; }
	stdmath_double4 set_yxzy(stdmath_double4 value) { self->y = value.x; self->x = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_double4 yxzz;
	stdmath_double4 get_yxzz() { return {self->y,self->x,self->z,self->z}; }
	stdmath_double4 set_yxzz(stdmath_double4 value) { self->y = value.x; self->x = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_double4 yxzw;
	stdmath_double4 get_yxzw() { return {self->y,self->x,self->z,self->w}; }
	stdmath_double4 set_yxzw(stdmath_double4 value) { self->y = value.x; self->x = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_double4 yxwx;
	stdmath_double4 get_yxwx() { return {self->y,self->x,self->w,self->x}; }
	stdmath_double4 set_yxwx(stdmath_double4 value) { self->y = value.x; self->x = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_double4 yxwy;
	stdmath_double4 get_yxwy() { return {self->y,self->x,self->w,self->y}; }
	stdmath_double4 set_yxwy(stdmath_double4 value) { self->y = value.x; self->x = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_double4 yxwz;
	stdmath_double4 get_yxwz() { return {self->y,self->x,self->w,self->z}; }
	stdmath_double4 set_yxwz(stdmath_double4 value) { self->y = value.x; self->x = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_double4 yxww;
	stdmath_double4 get_yxww() { return {self->y,self->x,self->w,self->w}; }
	stdmath_double4 set_yxww(stdmath_double4 value) { self->y = value.x; self->x = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_double4 yyxx;
	stdmath_double4 get_yyxx() { return {self->y,self->y,self->x,self->x}; }
	stdmath_double4 set_yyxx(stdmath_double4 value) { self->y = value.x; self->y = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_double4 yyxy;
	stdmath_double4 get_yyxy() { return {self->y,self->y,self->x,self->y}; }
	stdmath_double4 set_yyxy(stdmath_double4 value) { self->y = value.x; self->y = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_double4 yyxz;
	stdmath_double4 get_yyxz() { return {self->y,self->y,self->x,self->z}; }
	stdmath_double4 set_yyxz(stdmath_double4 value) { self->y = value.x; self->y = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_double4 yyxw;
	stdmath_double4 get_yyxw() { return {self->y,self->y,self->x,self->w}; }
	stdmath_double4 set_yyxw(stdmath_double4 value) { self->y = value.x; self->y = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_double4 yyyx;
	stdmath_double4 get_yyyx() { return {self->y,self->y,self->y,self->x}; }
	stdmath_double4 set_yyyx(stdmath_double4 value) { self->y = value.x; self->y = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_double4 yyyy;
	stdmath_double4 get_yyyy() { return {self->y,self->y,self->y,self->y}; }
	stdmath_double4 set_yyyy(stdmath_double4 value) { self->y = value.x; self->y = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_double4 yyyz;
	stdmath_double4 get_yyyz() { return {self->y,self->y,self->y,self->z}; }
	stdmath_double4 set_yyyz(stdmath_double4 value) { self->y = value.x; self->y = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_double4 yyyw;
	stdmath_double4 get_yyyw() { return {self->y,self->y,self->y,self->w}; }
	stdmath_double4 set_yyyw(stdmath_double4 value) { self->y = value.x; self->y = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_double4 yyzx;
	stdmath_double4 get_yyzx() { return {self->y,self->y,self->z,self->x}; }
	stdmath_double4 set_yyzx(stdmath_double4 value) { self->y = value.x; self->y = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_double4 yyzy;
	stdmath_double4 get_yyzy() { return {self->y,self->y,self->z,self->y}; }
	stdmath_double4 set_yyzy(stdmath_double4 value) { self->y = value.x; self->y = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_double4 yyzz;
	stdmath_double4 get_yyzz() { return {self->y,self->y,self->z,self->z}; }
	stdmath_double4 set_yyzz(stdmath_double4 value) { self->y = value.x; self->y = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_double4 yyzw;
	stdmath_double4 get_yyzw() { return {self->y,self->y,self->z,self->w}; }
	stdmath_double4 set_yyzw(stdmath_double4 value) { self->y = value.x; self->y = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_double4 yywx;
	stdmath_double4 get_yywx() { return {self->y,self->y,self->w,self->x}; }
	stdmath_double4 set_yywx(stdmath_double4 value) { self->y = value.x; self->y = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_double4 yywy;
	stdmath_double4 get_yywy() { return {self->y,self->y,self->w,self->y}; }
	stdmath_double4 set_yywy(stdmath_double4 value) { self->y = value.x; self->y = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_double4 yywz;
	stdmath_double4 get_yywz() { return {self->y,self->y,self->w,self->z}; }
	stdmath_double4 set_yywz(stdmath_double4 value) { self->y = value.x; self->y = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_double4 yyww;
	stdmath_double4 get_yyww() { return {self->y,self->y,self->w,self->w}; }
	stdmath_double4 set_yyww(stdmath_double4 value) { self->y = value.x; self->y = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_double4 yzxx;
	stdmath_double4 get_yzxx() { return {self->y,self->z,self->x,self->x}; }
	stdmath_double4 set_yzxx(stdmath_double4 value) { self->y = value.x; self->z = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_double4 yzxy;
	stdmath_double4 get_yzxy() { return {self->y,self->z,self->x,self->y}; }
	stdmath_double4 set_yzxy(stdmath_double4 value) { self->y = value.x; self->z = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_double4 yzxz;
	stdmath_double4 get_yzxz() { return {self->y,self->z,self->x,self->z}; }
	stdmath_double4 set_yzxz(stdmath_double4 value) { self->y = value.x; self->z = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_double4 yzxw;
	stdmath_double4 get_yzxw() { return {self->y,self->z,self->x,self->w}; }
	stdmath_double4 set_yzxw(stdmath_double4 value) { self->y = value.x; self->z = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_double4 yzyx;
	stdmath_double4 get_yzyx() { return {self->y,self->z,self->y,self->x}; }
	stdmath_double4 set_yzyx(stdmath_double4 value) { self->y = value.x; self->z = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_double4 yzyy;
	stdmath_double4 get_yzyy() { return {self->y,self->z,self->y,self->y}; }
	stdmath_double4 set_yzyy(stdmath_double4 value) { self->y = value.x; self->z = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_double4 yzyz;
	stdmath_double4 get_yzyz() { return {self->y,self->z,self->y,self->z}; }
	stdmath_double4 set_yzyz(stdmath_double4 value) { self->y = value.x; self->z = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_double4 yzyw;
	stdmath_double4 get_yzyw() { return {self->y,self->z,self->y,self->w}; }
	stdmath_double4 set_yzyw(stdmath_double4 value) { self->y = value.x; self->z = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_double4 yzzx;
	stdmath_double4 get_yzzx() { return {self->y,self->z,self->z,self->x}; }
	stdmath_double4 set_yzzx(stdmath_double4 value) { self->y = value.x; self->z = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_double4 yzzy;
	stdmath_double4 get_yzzy() { return {self->y,self->z,self->z,self->y}; }
	stdmath_double4 set_yzzy(stdmath_double4 value) { self->y = value.x; self->z = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_double4 yzzz;
	stdmath_double4 get_yzzz() { return {self->y,self->z,self->z,self->z}; }
	stdmath_double4 set_yzzz(stdmath_double4 value) { self->y = value.x; self->z = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_double4 yzzw;
	stdmath_double4 get_yzzw() { return {self->y,self->z,self->z,self->w}; }
	stdmath_double4 set_yzzw(stdmath_double4 value) { self->y = value.x; self->z = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_double4 yzwx;
	stdmath_double4 get_yzwx() { return {self->y,self->z,self->w,self->x}; }
	stdmath_double4 set_yzwx(stdmath_double4 value) { self->y = value.x; self->z = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_double4 yzwy;
	stdmath_double4 get_yzwy() { return {self->y,self->z,self->w,self->y}; }
	stdmath_double4 set_yzwy(stdmath_double4 value) { self->y = value.x; self->z = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_double4 yzwz;
	stdmath_double4 get_yzwz() { return {self->y,self->z,self->w,self->z}; }
	stdmath_double4 set_yzwz(stdmath_double4 value) { self->y = value.x; self->z = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_double4 yzww;
	stdmath_double4 get_yzww() { return {self->y,self->z,self->w,self->w}; }
	stdmath_double4 set_yzww(stdmath_double4 value) { self->y = value.x; self->z = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_double4 ywxx;
	stdmath_double4 get_ywxx() { return {self->y,self->w,self->x,self->x}; }
	stdmath_double4 set_ywxx(stdmath_double4 value) { self->y = value.x; self->w = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_double4 ywxy;
	stdmath_double4 get_ywxy() { return {self->y,self->w,self->x,self->y}; }
	stdmath_double4 set_ywxy(stdmath_double4 value) { self->y = value.x; self->w = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_double4 ywxz;
	stdmath_double4 get_ywxz() { return {self->y,self->w,self->x,self->z}; }
	stdmath_double4 set_ywxz(stdmath_double4 value) { self->y = value.x; self->w = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_double4 ywxw;
	stdmath_double4 get_ywxw() { return {self->y,self->w,self->x,self->w}; }
	stdmath_double4 set_ywxw(stdmath_double4 value) { self->y = value.x; self->w = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_double4 ywyx;
	stdmath_double4 get_ywyx() { return {self->y,self->w,self->y,self->x}; }
	stdmath_double4 set_ywyx(stdmath_double4 value) { self->y = value.x; self->w = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_double4 ywyy;
	stdmath_double4 get_ywyy() { return {self->y,self->w,self->y,self->y}; }
	stdmath_double4 set_ywyy(stdmath_double4 value) { self->y = value.x; self->w = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_double4 ywyz;
	stdmath_double4 get_ywyz() { return {self->y,self->w,self->y,self->z}; }
	stdmath_double4 set_ywyz(stdmath_double4 value) { self->y = value.x; self->w = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_double4 ywyw;
	stdmath_double4 get_ywyw() { return {self->y,self->w,self->y,self->w}; }
	stdmath_double4 set_ywyw(stdmath_double4 value) { self->y = value.x; self->w = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_double4 ywzx;
	stdmath_double4 get_ywzx() { return {self->y,self->w,self->z,self->x}; }
	stdmath_double4 set_ywzx(stdmath_double4 value) { self->y = value.x; self->w = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_double4 ywzy;
	stdmath_double4 get_ywzy() { return {self->y,self->w,self->z,self->y}; }
	stdmath_double4 set_ywzy(stdmath_double4 value) { self->y = value.x; self->w = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_double4 ywzz;
	stdmath_double4 get_ywzz() { return {self->y,self->w,self->z,self->z}; }
	stdmath_double4 set_ywzz(stdmath_double4 value) { self->y = value.x; self->w = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_double4 ywzw;
	stdmath_double4 get_ywzw() { return {self->y,self->w,self->z,self->w}; }
	stdmath_double4 set_ywzw(stdmath_double4 value) { self->y = value.x; self->w = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_double4 ywwx;
	stdmath_double4 get_ywwx() { return {self->y,self->w,self->w,self->x}; }
	stdmath_double4 set_ywwx(stdmath_double4 value) { self->y = value.x; self->w = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_double4 ywwy;
	stdmath_double4 get_ywwy() { return {self->y,self->w,self->w,self->y}; }
	stdmath_double4 set_ywwy(stdmath_double4 value) { self->y = value.x; self->w = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_double4 ywwz;
	stdmath_double4 get_ywwz() { return {self->y,self->w,self->w,self->z}; }
	stdmath_double4 set_ywwz(stdmath_double4 value) { self->y = value.x; self->w = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_double4 ywww;
	stdmath_double4 get_ywww() { return {self->y,self->w,self->w,self->w}; }
	stdmath_double4 set_ywww(stdmath_double4 value) { self->y = value.x; self->w = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_double4 zxxx;
	stdmath_double4 get_zxxx() { return {self->z,self->x,self->x,self->x}; }
	stdmath_double4 set_zxxx(stdmath_double4 value) { self->z = value.x; self->x = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_double4 zxxy;
	stdmath_double4 get_zxxy() { return {self->z,self->x,self->x,self->y}; }
	stdmath_double4 set_zxxy(stdmath_double4 value) { self->z = value.x; self->x = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_double4 zxxz;
	stdmath_double4 get_zxxz() { return {self->z,self->x,self->x,self->z}; }
	stdmath_double4 set_zxxz(stdmath_double4 value) { self->z = value.x; self->x = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_double4 zxxw;
	stdmath_double4 get_zxxw() { return {self->z,self->x,self->x,self->w}; }
	stdmath_double4 set_zxxw(stdmath_double4 value) { self->z = value.x; self->x = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_double4 zxyx;
	stdmath_double4 get_zxyx() { return {self->z,self->x,self->y,self->x}; }
	stdmath_double4 set_zxyx(stdmath_double4 value) { self->z = value.x; self->x = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_double4 zxyy;
	stdmath_double4 get_zxyy() { return {self->z,self->x,self->y,self->y}; }
	stdmath_double4 set_zxyy(stdmath_double4 value) { self->z = value.x; self->x = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_double4 zxyz;
	stdmath_double4 get_zxyz() { return {self->z,self->x,self->y,self->z}; }
	stdmath_double4 set_zxyz(stdmath_double4 value) { self->z = value.x; self->x = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_double4 zxyw;
	stdmath_double4 get_zxyw() { return {self->z,self->x,self->y,self->w}; }
	stdmath_double4 set_zxyw(stdmath_double4 value) { self->z = value.x; self->x = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_double4 zxzx;
	stdmath_double4 get_zxzx() { return {self->z,self->x,self->z,self->x}; }
	stdmath_double4 set_zxzx(stdmath_double4 value) { self->z = value.x; self->x = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_double4 zxzy;
	stdmath_double4 get_zxzy() { return {self->z,self->x,self->z,self->y}; }
	stdmath_double4 set_zxzy(stdmath_double4 value) { self->z = value.x; self->x = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_double4 zxzz;
	stdmath_double4 get_zxzz() { return {self->z,self->x,self->z,self->z}; }
	stdmath_double4 set_zxzz(stdmath_double4 value) { self->z = value.x; self->x = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_double4 zxzw;
	stdmath_double4 get_zxzw() { return {self->z,self->x,self->z,self->w}; }
	stdmath_double4 set_zxzw(stdmath_double4 value) { self->z = value.x; self->x = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_double4 zxwx;
	stdmath_double4 get_zxwx() { return {self->z,self->x,self->w,self->x}; }
	stdmath_double4 set_zxwx(stdmath_double4 value) { self->z = value.x; self->x = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_double4 zxwy;
	stdmath_double4 get_zxwy() { return {self->z,self->x,self->w,self->y}; }
	stdmath_double4 set_zxwy(stdmath_double4 value) { self->z = value.x; self->x = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_double4 zxwz;
	stdmath_double4 get_zxwz() { return {self->z,self->x,self->w,self->z}; }
	stdmath_double4 set_zxwz(stdmath_double4 value) { self->z = value.x; self->x = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_double4 zxww;
	stdmath_double4 get_zxww() { return {self->z,self->x,self->w,self->w}; }
	stdmath_double4 set_zxww(stdmath_double4 value) { self->z = value.x; self->x = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_double4 zyxx;
	stdmath_double4 get_zyxx() { return {self->z,self->y,self->x,self->x}; }
	stdmath_double4 set_zyxx(stdmath_double4 value) { self->z = value.x; self->y = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_double4 zyxy;
	stdmath_double4 get_zyxy() { return {self->z,self->y,self->x,self->y}; }
	stdmath_double4 set_zyxy(stdmath_double4 value) { self->z = value.x; self->y = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_double4 zyxz;
	stdmath_double4 get_zyxz() { return {self->z,self->y,self->x,self->z}; }
	stdmath_double4 set_zyxz(stdmath_double4 value) { self->z = value.x; self->y = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_double4 zyxw;
	stdmath_double4 get_zyxw() { return {self->z,self->y,self->x,self->w}; }
	stdmath_double4 set_zyxw(stdmath_double4 value) { self->z = value.x; self->y = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_double4 zyyx;
	stdmath_double4 get_zyyx() { return {self->z,self->y,self->y,self->x}; }
	stdmath_double4 set_zyyx(stdmath_double4 value) { self->z = value.x; self->y = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_double4 zyyy;
	stdmath_double4 get_zyyy() { return {self->z,self->y,self->y,self->y}; }
	stdmath_double4 set_zyyy(stdmath_double4 value) { self->z = value.x; self->y = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_double4 zyyz;
	stdmath_double4 get_zyyz() { return {self->z,self->y,self->y,self->z}; }
	stdmath_double4 set_zyyz(stdmath_double4 value) { self->z = value.x; self->y = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_double4 zyyw;
	stdmath_double4 get_zyyw() { return {self->z,self->y,self->y,self->w}; }
	stdmath_double4 set_zyyw(stdmath_double4 value) { self->z = value.x; self->y = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_double4 zyzx;
	stdmath_double4 get_zyzx() { return {self->z,self->y,self->z,self->x}; }
	stdmath_double4 set_zyzx(stdmath_double4 value) { self->z = value.x; self->y = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_double4 zyzy;
	stdmath_double4 get_zyzy() { return {self->z,self->y,self->z,self->y}; }
	stdmath_double4 set_zyzy(stdmath_double4 value) { self->z = value.x; self->y = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_double4 zyzz;
	stdmath_double4 get_zyzz() { return {self->z,self->y,self->z,self->z}; }
	stdmath_double4 set_zyzz(stdmath_double4 value) { self->z = value.x; self->y = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_double4 zyzw;
	stdmath_double4 get_zyzw() { return {self->z,self->y,self->z,self->w}; }
	stdmath_double4 set_zyzw(stdmath_double4 value) { self->z = value.x; self->y = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_double4 zywx;
	stdmath_double4 get_zywx() { return {self->z,self->y,self->w,self->x}; }
	stdmath_double4 set_zywx(stdmath_double4 value) { self->z = value.x; self->y = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_double4 zywy;
	stdmath_double4 get_zywy() { return {self->z,self->y,self->w,self->y}; }
	stdmath_double4 set_zywy(stdmath_double4 value) { self->z = value.x; self->y = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_double4 zywz;
	stdmath_double4 get_zywz() { return {self->z,self->y,self->w,self->z}; }
	stdmath_double4 set_zywz(stdmath_double4 value) { self->z = value.x; self->y = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_double4 zyww;
	stdmath_double4 get_zyww() { return {self->z,self->y,self->w,self->w}; }
	stdmath_double4 set_zyww(stdmath_double4 value) { self->z = value.x; self->y = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_double4 zzxx;
	stdmath_double4 get_zzxx() { return {self->z,self->z,self->x,self->x}; }
	stdmath_double4 set_zzxx(stdmath_double4 value) { self->z = value.x; self->z = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_double4 zzxy;
	stdmath_double4 get_zzxy() { return {self->z,self->z,self->x,self->y}; }
	stdmath_double4 set_zzxy(stdmath_double4 value) { self->z = value.x; self->z = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_double4 zzxz;
	stdmath_double4 get_zzxz() { return {self->z,self->z,self->x,self->z}; }
	stdmath_double4 set_zzxz(stdmath_double4 value) { self->z = value.x; self->z = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_double4 zzxw;
	stdmath_double4 get_zzxw() { return {self->z,self->z,self->x,self->w}; }
	stdmath_double4 set_zzxw(stdmath_double4 value) { self->z = value.x; self->z = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_double4 zzyx;
	stdmath_double4 get_zzyx() { return {self->z,self->z,self->y,self->x}; }
	stdmath_double4 set_zzyx(stdmath_double4 value) { self->z = value.x; self->z = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_double4 zzyy;
	stdmath_double4 get_zzyy() { return {self->z,self->z,self->y,self->y}; }
	stdmath_double4 set_zzyy(stdmath_double4 value) { self->z = value.x; self->z = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_double4 zzyz;
	stdmath_double4 get_zzyz() { return {self->z,self->z,self->y,self->z}; }
	stdmath_double4 set_zzyz(stdmath_double4 value) { self->z = value.x; self->z = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_double4 zzyw;
	stdmath_double4 get_zzyw() { return {self->z,self->z,self->y,self->w}; }
	stdmath_double4 set_zzyw(stdmath_double4 value) { self->z = value.x; self->z = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_double4 zzzx;
	stdmath_double4 get_zzzx() { return {self->z,self->z,self->z,self->x}; }
	stdmath_double4 set_zzzx(stdmath_double4 value) { self->z = value.x; self->z = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_double4 zzzy;
	stdmath_double4 get_zzzy() { return {self->z,self->z,self->z,self->y}; }
	stdmath_double4 set_zzzy(stdmath_double4 value) { self->z = value.x; self->z = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_double4 zzzz;
	stdmath_double4 get_zzzz() { return {self->z,self->z,self->z,self->z}; }
	stdmath_double4 set_zzzz(stdmath_double4 value) { self->z = value.x; self->z = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_double4 zzzw;
	stdmath_double4 get_zzzw() { return {self->z,self->z,self->z,self->w}; }
	stdmath_double4 set_zzzw(stdmath_double4 value) { self->z = value.x; self->z = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_double4 zzwx;
	stdmath_double4 get_zzwx() { return {self->z,self->z,self->w,self->x}; }
	stdmath_double4 set_zzwx(stdmath_double4 value) { self->z = value.x; self->z = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_double4 zzwy;
	stdmath_double4 get_zzwy() { return {self->z,self->z,self->w,self->y}; }
	stdmath_double4 set_zzwy(stdmath_double4 value) { self->z = value.x; self->z = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_double4 zzwz;
	stdmath_double4 get_zzwz() { return {self->z,self->z,self->w,self->z}; }
	stdmath_double4 set_zzwz(stdmath_double4 value) { self->z = value.x; self->z = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_double4 zzww;
	stdmath_double4 get_zzww() { return {self->z,self->z,self->w,self->w}; }
	stdmath_double4 set_zzww(stdmath_double4 value) { self->z = value.x; self->z = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_double4 zwxx;
	stdmath_double4 get_zwxx() { return {self->z,self->w,self->x,self->x}; }
	stdmath_double4 set_zwxx(stdmath_double4 value) { self->z = value.x; self->w = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_double4 zwxy;
	stdmath_double4 get_zwxy() { return {self->z,self->w,self->x,self->y}; }
	stdmath_double4 set_zwxy(stdmath_double4 value) { self->z = value.x; self->w = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_double4 zwxz;
	stdmath_double4 get_zwxz() { return {self->z,self->w,self->x,self->z}; }
	stdmath_double4 set_zwxz(stdmath_double4 value) { self->z = value.x; self->w = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_double4 zwxw;
	stdmath_double4 get_zwxw() { return {self->z,self->w,self->x,self->w}; }
	stdmath_double4 set_zwxw(stdmath_double4 value) { self->z = value.x; self->w = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_double4 zwyx;
	stdmath_double4 get_zwyx() { return {self->z,self->w,self->y,self->x}; }
	stdmath_double4 set_zwyx(stdmath_double4 value) { self->z = value.x; self->w = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_double4 zwyy;
	stdmath_double4 get_zwyy() { return {self->z,self->w,self->y,self->y}; }
	stdmath_double4 set_zwyy(stdmath_double4 value) { self->z = value.x; self->w = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_double4 zwyz;
	stdmath_double4 get_zwyz() { return {self->z,self->w,self->y,self->z}; }
	stdmath_double4 set_zwyz(stdmath_double4 value) { self->z = value.x; self->w = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_double4 zwyw;
	stdmath_double4 get_zwyw() { return {self->z,self->w,self->y,self->w}; }
	stdmath_double4 set_zwyw(stdmath_double4 value) { self->z = value.x; self->w = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_double4 zwzx;
	stdmath_double4 get_zwzx() { return {self->z,self->w,self->z,self->x}; }
	stdmath_double4 set_zwzx(stdmath_double4 value) { self->z = value.x; self->w = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_double4 zwzy;
	stdmath_double4 get_zwzy() { return {self->z,self->w,self->z,self->y}; }
	stdmath_double4 set_zwzy(stdmath_double4 value) { self->z = value.x; self->w = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_double4 zwzz;
	stdmath_double4 get_zwzz() { return {self->z,self->w,self->z,self->z}; }
	stdmath_double4 set_zwzz(stdmath_double4 value) { self->z = value.x; self->w = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_double4 zwzw;
	stdmath_double4 get_zwzw() { return {self->z,self->w,self->z,self->w}; }
	stdmath_double4 set_zwzw(stdmath_double4 value) { self->z = value.x; self->w = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_double4 zwwx;
	stdmath_double4 get_zwwx() { return {self->z,self->w,self->w,self->x}; }
	stdmath_double4 set_zwwx(stdmath_double4 value) { self->z = value.x; self->w = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_double4 zwwy;
	stdmath_double4 get_zwwy() { return {self->z,self->w,self->w,self->y}; }
	stdmath_double4 set_zwwy(stdmath_double4 value) { self->z = value.x; self->w = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_double4 zwwz;
	stdmath_double4 get_zwwz() { return {self->z,self->w,self->w,self->z}; }
	stdmath_double4 set_zwwz(stdmath_double4 value) { self->z = value.x; self->w = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_double4 zwww;
	stdmath_double4 get_zwww() { return {self->z,self->w,self->w,self->w}; }
	stdmath_double4 set_zwww(stdmath_double4 value) { self->z = value.x; self->w = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_double4 wxxx;
	stdmath_double4 get_wxxx() { return {self->w,self->x,self->x,self->x}; }
	stdmath_double4 set_wxxx(stdmath_double4 value) { self->w = value.x; self->x = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_double4 wxxy;
	stdmath_double4 get_wxxy() { return {self->w,self->x,self->x,self->y}; }
	stdmath_double4 set_wxxy(stdmath_double4 value) { self->w = value.x; self->x = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_double4 wxxz;
	stdmath_double4 get_wxxz() { return {self->w,self->x,self->x,self->z}; }
	stdmath_double4 set_wxxz(stdmath_double4 value) { self->w = value.x; self->x = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_double4 wxxw;
	stdmath_double4 get_wxxw() { return {self->w,self->x,self->x,self->w}; }
	stdmath_double4 set_wxxw(stdmath_double4 value) { self->w = value.x; self->x = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_double4 wxyx;
	stdmath_double4 get_wxyx() { return {self->w,self->x,self->y,self->x}; }
	stdmath_double4 set_wxyx(stdmath_double4 value) { self->w = value.x; self->x = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_double4 wxyy;
	stdmath_double4 get_wxyy() { return {self->w,self->x,self->y,self->y}; }
	stdmath_double4 set_wxyy(stdmath_double4 value) { self->w = value.x; self->x = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_double4 wxyz;
	stdmath_double4 get_wxyz() { return {self->w,self->x,self->y,self->z}; }
	stdmath_double4 set_wxyz(stdmath_double4 value) { self->w = value.x; self->x = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_double4 wxyw;
	stdmath_double4 get_wxyw() { return {self->w,self->x,self->y,self->w}; }
	stdmath_double4 set_wxyw(stdmath_double4 value) { self->w = value.x; self->x = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_double4 wxzx;
	stdmath_double4 get_wxzx() { return {self->w,self->x,self->z,self->x}; }
	stdmath_double4 set_wxzx(stdmath_double4 value) { self->w = value.x; self->x = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_double4 wxzy;
	stdmath_double4 get_wxzy() { return {self->w,self->x,self->z,self->y}; }
	stdmath_double4 set_wxzy(stdmath_double4 value) { self->w = value.x; self->x = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_double4 wxzz;
	stdmath_double4 get_wxzz() { return {self->w,self->x,self->z,self->z}; }
	stdmath_double4 set_wxzz(stdmath_double4 value) { self->w = value.x; self->x = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_double4 wxzw;
	stdmath_double4 get_wxzw() { return {self->w,self->x,self->z,self->w}; }
	stdmath_double4 set_wxzw(stdmath_double4 value) { self->w = value.x; self->x = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_double4 wxwx;
	stdmath_double4 get_wxwx() { return {self->w,self->x,self->w,self->x}; }
	stdmath_double4 set_wxwx(stdmath_double4 value) { self->w = value.x; self->x = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_double4 wxwy;
	stdmath_double4 get_wxwy() { return {self->w,self->x,self->w,self->y}; }
	stdmath_double4 set_wxwy(stdmath_double4 value) { self->w = value.x; self->x = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_double4 wxwz;
	stdmath_double4 get_wxwz() { return {self->w,self->x,self->w,self->z}; }
	stdmath_double4 set_wxwz(stdmath_double4 value) { self->w = value.x; self->x = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_double4 wxww;
	stdmath_double4 get_wxww() { return {self->w,self->x,self->w,self->w}; }
	stdmath_double4 set_wxww(stdmath_double4 value) { self->w = value.x; self->x = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_double4 wyxx;
	stdmath_double4 get_wyxx() { return {self->w,self->y,self->x,self->x}; }
	stdmath_double4 set_wyxx(stdmath_double4 value) { self->w = value.x; self->y = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_double4 wyxy;
	stdmath_double4 get_wyxy() { return {self->w,self->y,self->x,self->y}; }
	stdmath_double4 set_wyxy(stdmath_double4 value) { self->w = value.x; self->y = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_double4 wyxz;
	stdmath_double4 get_wyxz() { return {self->w,self->y,self->x,self->z}; }
	stdmath_double4 set_wyxz(stdmath_double4 value) { self->w = value.x; self->y = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_double4 wyxw;
	stdmath_double4 get_wyxw() { return {self->w,self->y,self->x,self->w}; }
	stdmath_double4 set_wyxw(stdmath_double4 value) { self->w = value.x; self->y = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_double4 wyyx;
	stdmath_double4 get_wyyx() { return {self->w,self->y,self->y,self->x}; }
	stdmath_double4 set_wyyx(stdmath_double4 value) { self->w = value.x; self->y = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_double4 wyyy;
	stdmath_double4 get_wyyy() { return {self->w,self->y,self->y,self->y}; }
	stdmath_double4 set_wyyy(stdmath_double4 value) { self->w = value.x; self->y = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_double4 wyyz;
	stdmath_double4 get_wyyz() { return {self->w,self->y,self->y,self->z}; }
	stdmath_double4 set_wyyz(stdmath_double4 value) { self->w = value.x; self->y = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_double4 wyyw;
	stdmath_double4 get_wyyw() { return {self->w,self->y,self->y,self->w}; }
	stdmath_double4 set_wyyw(stdmath_double4 value) { self->w = value.x; self->y = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_double4 wyzx;
	stdmath_double4 get_wyzx() { return {self->w,self->y,self->z,self->x}; }
	stdmath_double4 set_wyzx(stdmath_double4 value) { self->w = value.x; self->y = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_double4 wyzy;
	stdmath_double4 get_wyzy() { return {self->w,self->y,self->z,self->y}; }
	stdmath_double4 set_wyzy(stdmath_double4 value) { self->w = value.x; self->y = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_double4 wyzz;
	stdmath_double4 get_wyzz() { return {self->w,self->y,self->z,self->z}; }
	stdmath_double4 set_wyzz(stdmath_double4 value) { self->w = value.x; self->y = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_double4 wyzw;
	stdmath_double4 get_wyzw() { return {self->w,self->y,self->z,self->w}; }
	stdmath_double4 set_wyzw(stdmath_double4 value) { self->w = value.x; self->y = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_double4 wywx;
	stdmath_double4 get_wywx() { return {self->w,self->y,self->w,self->x}; }
	stdmath_double4 set_wywx(stdmath_double4 value) { self->w = value.x; self->y = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_double4 wywy;
	stdmath_double4 get_wywy() { return {self->w,self->y,self->w,self->y}; }
	stdmath_double4 set_wywy(stdmath_double4 value) { self->w = value.x; self->y = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_double4 wywz;
	stdmath_double4 get_wywz() { return {self->w,self->y,self->w,self->z}; }
	stdmath_double4 set_wywz(stdmath_double4 value) { self->w = value.x; self->y = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_double4 wyww;
	stdmath_double4 get_wyww() { return {self->w,self->y,self->w,self->w}; }
	stdmath_double4 set_wyww(stdmath_double4 value) { self->w = value.x; self->y = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_double4 wzxx;
	stdmath_double4 get_wzxx() { return {self->w,self->z,self->x,self->x}; }
	stdmath_double4 set_wzxx(stdmath_double4 value) { self->w = value.x; self->z = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_double4 wzxy;
	stdmath_double4 get_wzxy() { return {self->w,self->z,self->x,self->y}; }
	stdmath_double4 set_wzxy(stdmath_double4 value) { self->w = value.x; self->z = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_double4 wzxz;
	stdmath_double4 get_wzxz() { return {self->w,self->z,self->x,self->z}; }
	stdmath_double4 set_wzxz(stdmath_double4 value) { self->w = value.x; self->z = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_double4 wzxw;
	stdmath_double4 get_wzxw() { return {self->w,self->z,self->x,self->w}; }
	stdmath_double4 set_wzxw(stdmath_double4 value) { self->w = value.x; self->z = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_double4 wzyx;
	stdmath_double4 get_wzyx() { return {self->w,self->z,self->y,self->x}; }
	stdmath_double4 set_wzyx(stdmath_double4 value) { self->w = value.x; self->z = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_double4 wzyy;
	stdmath_double4 get_wzyy() { return {self->w,self->z,self->y,self->y}; }
	stdmath_double4 set_wzyy(stdmath_double4 value) { self->w = value.x; self->z = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_double4 wzyz;
	stdmath_double4 get_wzyz() { return {self->w,self->z,self->y,self->z}; }
	stdmath_double4 set_wzyz(stdmath_double4 value) { self->w = value.x; self->z = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_double4 wzyw;
	stdmath_double4 get_wzyw() { return {self->w,self->z,self->y,self->w}; }
	stdmath_double4 set_wzyw(stdmath_double4 value) { self->w = value.x; self->z = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_double4 wzzx;
	stdmath_double4 get_wzzx() { return {self->w,self->z,self->z,self->x}; }
	stdmath_double4 set_wzzx(stdmath_double4 value) { self->w = value.x; self->z = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_double4 wzzy;
	stdmath_double4 get_wzzy() { return {self->w,self->z,self->z,self->y}; }
	stdmath_double4 set_wzzy(stdmath_double4 value) { self->w = value.x; self->z = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_double4 wzzz;
	stdmath_double4 get_wzzz() { return {self->w,self->z,self->z,self->z}; }
	stdmath_double4 set_wzzz(stdmath_double4 value) { self->w = value.x; self->z = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_double4 wzzw;
	stdmath_double4 get_wzzw() { return {self->w,self->z,self->z,self->w}; }
	stdmath_double4 set_wzzw(stdmath_double4 value) { self->w = value.x; self->z = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_double4 wzwx;
	stdmath_double4 get_wzwx() { return {self->w,self->z,self->w,self->x}; }
	stdmath_double4 set_wzwx(stdmath_double4 value) { self->w = value.x; self->z = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_double4 wzwy;
	stdmath_double4 get_wzwy() { return {self->w,self->z,self->w,self->y}; }
	stdmath_double4 set_wzwy(stdmath_double4 value) { self->w = value.x; self->z = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_double4 wzwz;
	stdmath_double4 get_wzwz() { return {self->w,self->z,self->w,self->z}; }
	stdmath_double4 set_wzwz(stdmath_double4 value) { self->w = value.x; self->z = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_double4 wzww;
	stdmath_double4 get_wzww() { return {self->w,self->z,self->w,self->w}; }
	stdmath_double4 set_wzww(stdmath_double4 value) { self->w = value.x; self->z = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_double4 wwxx;
	stdmath_double4 get_wwxx() { return {self->w,self->w,self->x,self->x}; }
	stdmath_double4 set_wwxx(stdmath_double4 value) { self->w = value.x; self->w = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_double4 wwxy;
	stdmath_double4 get_wwxy() { return {self->w,self->w,self->x,self->y}; }
	stdmath_double4 set_wwxy(stdmath_double4 value) { self->w = value.x; self->w = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_double4 wwxz;
	stdmath_double4 get_wwxz() { return {self->w,self->w,self->x,self->z}; }
	stdmath_double4 set_wwxz(stdmath_double4 value) { self->w = value.x; self->w = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_double4 wwxw;
	stdmath_double4 get_wwxw() { return {self->w,self->w,self->x,self->w}; }
	stdmath_double4 set_wwxw(stdmath_double4 value) { self->w = value.x; self->w = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_double4 wwyx;
	stdmath_double4 get_wwyx() { return {self->w,self->w,self->y,self->x}; }
	stdmath_double4 set_wwyx(stdmath_double4 value) { self->w = value.x; self->w = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_double4 wwyy;
	stdmath_double4 get_wwyy() { return {self->w,self->w,self->y,self->y}; }
	stdmath_double4 set_wwyy(stdmath_double4 value) { self->w = value.x; self->w = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_double4 wwyz;
	stdmath_double4 get_wwyz() { return {self->w,self->w,self->y,self->z}; }
	stdmath_double4 set_wwyz(stdmath_double4 value) { self->w = value.x; self->w = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_double4 wwyw;
	stdmath_double4 get_wwyw() { return {self->w,self->w,self->y,self->w}; }
	stdmath_double4 set_wwyw(stdmath_double4 value) { self->w = value.x; self->w = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_double4 wwzx;
	stdmath_double4 get_wwzx() { return {self->w,self->w,self->z,self->x}; }
	stdmath_double4 set_wwzx(stdmath_double4 value) { self->w = value.x; self->w = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_double4 wwzy;
	stdmath_double4 get_wwzy() { return {self->w,self->w,self->z,self->y}; }
	stdmath_double4 set_wwzy(stdmath_double4 value) { self->w = value.x; self->w = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_double4 wwzz;
	stdmath_double4 get_wwzz() { return {self->w,self->w,self->z,self->z}; }
	stdmath_double4 set_wwzz(stdmath_double4 value) { self->w = value.x; self->w = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_double4 wwzw;
	stdmath_double4 get_wwzw() { return {self->w,self->w,self->z,self->w}; }
	stdmath_double4 set_wwzw(stdmath_double4 value) { self->w = value.x; self->w = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_double4 wwwx;
	stdmath_double4 get_wwwx() { return {self->w,self->w,self->w,self->x}; }
	stdmath_double4 set_wwwx(stdmath_double4 value) { self->w = value.x; self->w = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_double4 wwwy;
	stdmath_double4 get_wwwy() { return {self->w,self->w,self->w,self->y}; }
	stdmath_double4 set_wwwy(stdmath_double4 value) { self->w = value.x; self->w = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_double4 wwwz;
	stdmath_double4 get_wwwz() { return {self->w,self->w,self->w,self->z}; }
	stdmath_double4 set_wwwz(stdmath_double4 value) { self->w = value.x; self->w = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_double4 wwww;
	stdmath_double4 get_wwww() { return {self->w,self->w,self->w,self->w}; }
	stdmath_double4 set_wwww(stdmath_double4 value) { self->w = value.x; self->w = value.y; self->w = value.z; self->w = value.w; return *self; }



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

	bool4 _equal_to(stdmath_double4 o) {
		return stdmath_double4_equal_to(*self, o);
	}
	bool4 _not_equal_to(stdmath_double4 o) {
		return stdmath_double4_not_equal_to(*self, o);
	}
	bool4 _less_than(stdmath_double4 o) {
		return stdmath_double4_less_than(*self, o);
	}
	bool4 _less_than_or_equal_to(stdmath_double4 o) {
		return stdmath_double4_less_than_or_equal_to(*self, o);
	}
	bool4 _greater_than(stdmath_double4 o) {
		return stdmath_double4_greater_than(*self, o);
	}
	bool4 _greater_than_or_equal_to(stdmath_double4 o) {
		return stdmath_double4_greater_than_or_equal_to(*self, o);
	}

	double _length_squared() {
		return stdmath_double4_length_squared(*self);
	}
	double _length() {
		return stdmath_double4_length(*self);
	}
	double _dot() {
		return stdmath_double4_dot(*self);
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
	stdmath_double4 _lerp(stdmath_double4 o, double t) {
		return stdmath_double4_lerp(*self, o, t);
	}
	stdmath_double4 _clamp(stdmath_double4 min, stdmath_double4 max) {
		return stdmath_double4_clamp(*self, min, max);
	}
	stdmath_double4 _reflect(stdmath_double4 n) {
		return stdmath_double4_reflect(*self, n);
	}
	bool4 _approximately_equal(stdmath_double4 o) {
		return stdmath_double4_approximately_equal()
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

	double _get_element(size_t i) {
		return self->data[i];
	}

	double _set_element(size_t i, double value) {
		return self->data[i] = value;
	}
}
