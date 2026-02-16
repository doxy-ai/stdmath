%rename(byte4) stdmath_byte4;
%include "byte4.h"

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

%extend stdmath_byte4 {
	stdmath_byte4(uint8_t broadcast) {
		stdmath_byte4 *v;
		v = (stdmath_byte4 *) malloc(sizeof(stdmath_byte4));
		*v = stdmath_byte4_broadcast(broadcast);
		return v;
	}

#if 4 == 4
	stdmath_byte4(uint8_t x = 0, uint8_t y = 0, uint8_t z = 0, uint8_t w = 0) {
		stdmath_byte4 *v;
		v = (stdmath_byte4 *) malloc(sizeof(stdmath_byte4));
		v->x = x;
		v->y = y;
		v->z = z;
		v->w = w;
		return v;
	}
#elif 4 == 3
	stdmath_byte4(uint8_t x = 0, uint8_t y = 0, uint8_t z = 0) {
		stdmath_byte4 *v;
		v = (stdmath_byte4 *) malloc(sizeof(stdmath_byte4));
		v->x = x;
		v->y = y;
		v->z = z;
		return v;
	}
#elif 4 == 2
	stdmath_byte4(uint8_t x = 0, uint8_t y = 0) {
		stdmath_byte4 *v;
		v = (stdmath_byte4 *) malloc(sizeof(stdmath_byte4));
		v->x = x;
		v->y = y;
		return v;
	}
#elif 4 == 1
	stdmath_byte4(uint8_t x = 0) {
		stdmath_byte4 *v;
		v = (stdmath_byte4 *) malloc(sizeof(stdmath_byte4));
		v->x = x;
		return v;
	}
#endif

	stdmath_byte2 xx;
	stdmath_byte2 get_xx() { return {self->x,self->x}; }
	stdmath_byte4 set_xx(stdmath_byte2 value) { self->x = value.x; self->x = value.y; return *self; }

	stdmath_byte2 xy;
	stdmath_byte2 get_xy() { return {self->x,self->y}; }
	stdmath_byte4 set_xy(stdmath_byte2 value) { self->x = value.x; self->y = value.y; return *self; }

	stdmath_byte2 xz;
	stdmath_byte2 get_xz() { return {self->x,self->z}; }
	stdmath_byte4 set_xz(stdmath_byte2 value) { self->x = value.x; self->z = value.y; return *self; }

	stdmath_byte2 xw;
	stdmath_byte2 get_xw() { return {self->x,self->w}; }
	stdmath_byte4 set_xw(stdmath_byte2 value) { self->x = value.x; self->w = value.y; return *self; }

	stdmath_byte2 yx;
	stdmath_byte2 get_yx() { return {self->y,self->x}; }
	stdmath_byte4 set_yx(stdmath_byte2 value) { self->y = value.x; self->x = value.y; return *self; }

	stdmath_byte2 yy;
	stdmath_byte2 get_yy() { return {self->y,self->y}; }
	stdmath_byte4 set_yy(stdmath_byte2 value) { self->y = value.x; self->y = value.y; return *self; }

	stdmath_byte2 yz;
	stdmath_byte2 get_yz() { return {self->y,self->z}; }
	stdmath_byte4 set_yz(stdmath_byte2 value) { self->y = value.x; self->z = value.y; return *self; }

	stdmath_byte2 yw;
	stdmath_byte2 get_yw() { return {self->y,self->w}; }
	stdmath_byte4 set_yw(stdmath_byte2 value) { self->y = value.x; self->w = value.y; return *self; }

	stdmath_byte2 zx;
	stdmath_byte2 get_zx() { return {self->z,self->x}; }
	stdmath_byte4 set_zx(stdmath_byte2 value) { self->z = value.x; self->x = value.y; return *self; }

	stdmath_byte2 zy;
	stdmath_byte2 get_zy() { return {self->z,self->y}; }
	stdmath_byte4 set_zy(stdmath_byte2 value) { self->z = value.x; self->y = value.y; return *self; }

	stdmath_byte2 zz;
	stdmath_byte2 get_zz() { return {self->z,self->z}; }
	stdmath_byte4 set_zz(stdmath_byte2 value) { self->z = value.x; self->z = value.y; return *self; }

	stdmath_byte2 zw;
	stdmath_byte2 get_zw() { return {self->z,self->w}; }
	stdmath_byte4 set_zw(stdmath_byte2 value) { self->z = value.x; self->w = value.y; return *self; }

	stdmath_byte2 wx;
	stdmath_byte2 get_wx() { return {self->w,self->x}; }
	stdmath_byte4 set_wx(stdmath_byte2 value) { self->w = value.x; self->x = value.y; return *self; }

	stdmath_byte2 wy;
	stdmath_byte2 get_wy() { return {self->w,self->y}; }
	stdmath_byte4 set_wy(stdmath_byte2 value) { self->w = value.x; self->y = value.y; return *self; }

	stdmath_byte2 wz;
	stdmath_byte2 get_wz() { return {self->w,self->z}; }
	stdmath_byte4 set_wz(stdmath_byte2 value) { self->w = value.x; self->z = value.y; return *self; }

	stdmath_byte2 ww;
	stdmath_byte2 get_ww() { return {self->w,self->w}; }
	stdmath_byte4 set_ww(stdmath_byte2 value) { self->w = value.x; self->w = value.y; return *self; }

	stdmath_byte3 xxx;
	stdmath_byte3 get_xxx() { return {self->x,self->x,self->x}; }
	stdmath_byte4 set_xxx(stdmath_byte3 value) { self->x = value.x; self->x = value.y; self->x = value.z; return *self; }

	stdmath_byte3 xxy;
	stdmath_byte3 get_xxy() { return {self->x,self->x,self->y}; }
	stdmath_byte4 set_xxy(stdmath_byte3 value) { self->x = value.x; self->x = value.y; self->y = value.z; return *self; }

	stdmath_byte3 xxz;
	stdmath_byte3 get_xxz() { return {self->x,self->x,self->z}; }
	stdmath_byte4 set_xxz(stdmath_byte3 value) { self->x = value.x; self->x = value.y; self->z = value.z; return *self; }

	stdmath_byte3 xxw;
	stdmath_byte3 get_xxw() { return {self->x,self->x,self->w}; }
	stdmath_byte4 set_xxw(stdmath_byte3 value) { self->x = value.x; self->x = value.y; self->w = value.z; return *self; }

	stdmath_byte3 xyx;
	stdmath_byte3 get_xyx() { return {self->x,self->y,self->x}; }
	stdmath_byte4 set_xyx(stdmath_byte3 value) { self->x = value.x; self->y = value.y; self->x = value.z; return *self; }

	stdmath_byte3 xyy;
	stdmath_byte3 get_xyy() { return {self->x,self->y,self->y}; }
	stdmath_byte4 set_xyy(stdmath_byte3 value) { self->x = value.x; self->y = value.y; self->y = value.z; return *self; }

	stdmath_byte3 xyz;
	stdmath_byte3 get_xyz() { return {self->x,self->y,self->z}; }
	stdmath_byte4 set_xyz(stdmath_byte3 value) { self->x = value.x; self->y = value.y; self->z = value.z; return *self; }

	stdmath_byte3 xyw;
	stdmath_byte3 get_xyw() { return {self->x,self->y,self->w}; }
	stdmath_byte4 set_xyw(stdmath_byte3 value) { self->x = value.x; self->y = value.y; self->w = value.z; return *self; }

	stdmath_byte3 xzx;
	stdmath_byte3 get_xzx() { return {self->x,self->z,self->x}; }
	stdmath_byte4 set_xzx(stdmath_byte3 value) { self->x = value.x; self->z = value.y; self->x = value.z; return *self; }

	stdmath_byte3 xzy;
	stdmath_byte3 get_xzy() { return {self->x,self->z,self->y}; }
	stdmath_byte4 set_xzy(stdmath_byte3 value) { self->x = value.x; self->z = value.y; self->y = value.z; return *self; }

	stdmath_byte3 xzz;
	stdmath_byte3 get_xzz() { return {self->x,self->z,self->z}; }
	stdmath_byte4 set_xzz(stdmath_byte3 value) { self->x = value.x; self->z = value.y; self->z = value.z; return *self; }

	stdmath_byte3 xzw;
	stdmath_byte3 get_xzw() { return {self->x,self->z,self->w}; }
	stdmath_byte4 set_xzw(stdmath_byte3 value) { self->x = value.x; self->z = value.y; self->w = value.z; return *self; }

	stdmath_byte3 xwx;
	stdmath_byte3 get_xwx() { return {self->x,self->w,self->x}; }
	stdmath_byte4 set_xwx(stdmath_byte3 value) { self->x = value.x; self->w = value.y; self->x = value.z; return *self; }

	stdmath_byte3 xwy;
	stdmath_byte3 get_xwy() { return {self->x,self->w,self->y}; }
	stdmath_byte4 set_xwy(stdmath_byte3 value) { self->x = value.x; self->w = value.y; self->y = value.z; return *self; }

	stdmath_byte3 xwz;
	stdmath_byte3 get_xwz() { return {self->x,self->w,self->z}; }
	stdmath_byte4 set_xwz(stdmath_byte3 value) { self->x = value.x; self->w = value.y; self->z = value.z; return *self; }

	stdmath_byte3 xww;
	stdmath_byte3 get_xww() { return {self->x,self->w,self->w}; }
	stdmath_byte4 set_xww(stdmath_byte3 value) { self->x = value.x; self->w = value.y; self->w = value.z; return *self; }

	stdmath_byte3 yxx;
	stdmath_byte3 get_yxx() { return {self->y,self->x,self->x}; }
	stdmath_byte4 set_yxx(stdmath_byte3 value) { self->y = value.x; self->x = value.y; self->x = value.z; return *self; }

	stdmath_byte3 yxy;
	stdmath_byte3 get_yxy() { return {self->y,self->x,self->y}; }
	stdmath_byte4 set_yxy(stdmath_byte3 value) { self->y = value.x; self->x = value.y; self->y = value.z; return *self; }

	stdmath_byte3 yxz;
	stdmath_byte3 get_yxz() { return {self->y,self->x,self->z}; }
	stdmath_byte4 set_yxz(stdmath_byte3 value) { self->y = value.x; self->x = value.y; self->z = value.z; return *self; }

	stdmath_byte3 yxw;
	stdmath_byte3 get_yxw() { return {self->y,self->x,self->w}; }
	stdmath_byte4 set_yxw(stdmath_byte3 value) { self->y = value.x; self->x = value.y; self->w = value.z; return *self; }

	stdmath_byte3 yyx;
	stdmath_byte3 get_yyx() { return {self->y,self->y,self->x}; }
	stdmath_byte4 set_yyx(stdmath_byte3 value) { self->y = value.x; self->y = value.y; self->x = value.z; return *self; }

	stdmath_byte3 yyy;
	stdmath_byte3 get_yyy() { return {self->y,self->y,self->y}; }
	stdmath_byte4 set_yyy(stdmath_byte3 value) { self->y = value.x; self->y = value.y; self->y = value.z; return *self; }

	stdmath_byte3 yyz;
	stdmath_byte3 get_yyz() { return {self->y,self->y,self->z}; }
	stdmath_byte4 set_yyz(stdmath_byte3 value) { self->y = value.x; self->y = value.y; self->z = value.z; return *self; }

	stdmath_byte3 yyw;
	stdmath_byte3 get_yyw() { return {self->y,self->y,self->w}; }
	stdmath_byte4 set_yyw(stdmath_byte3 value) { self->y = value.x; self->y = value.y; self->w = value.z; return *self; }

	stdmath_byte3 yzx;
	stdmath_byte3 get_yzx() { return {self->y,self->z,self->x}; }
	stdmath_byte4 set_yzx(stdmath_byte3 value) { self->y = value.x; self->z = value.y; self->x = value.z; return *self; }

	stdmath_byte3 yzy;
	stdmath_byte3 get_yzy() { return {self->y,self->z,self->y}; }
	stdmath_byte4 set_yzy(stdmath_byte3 value) { self->y = value.x; self->z = value.y; self->y = value.z; return *self; }

	stdmath_byte3 yzz;
	stdmath_byte3 get_yzz() { return {self->y,self->z,self->z}; }
	stdmath_byte4 set_yzz(stdmath_byte3 value) { self->y = value.x; self->z = value.y; self->z = value.z; return *self; }

	stdmath_byte3 yzw;
	stdmath_byte3 get_yzw() { return {self->y,self->z,self->w}; }
	stdmath_byte4 set_yzw(stdmath_byte3 value) { self->y = value.x; self->z = value.y; self->w = value.z; return *self; }

	stdmath_byte3 ywx;
	stdmath_byte3 get_ywx() { return {self->y,self->w,self->x}; }
	stdmath_byte4 set_ywx(stdmath_byte3 value) { self->y = value.x; self->w = value.y; self->x = value.z; return *self; }

	stdmath_byte3 ywy;
	stdmath_byte3 get_ywy() { return {self->y,self->w,self->y}; }
	stdmath_byte4 set_ywy(stdmath_byte3 value) { self->y = value.x; self->w = value.y; self->y = value.z; return *self; }

	stdmath_byte3 ywz;
	stdmath_byte3 get_ywz() { return {self->y,self->w,self->z}; }
	stdmath_byte4 set_ywz(stdmath_byte3 value) { self->y = value.x; self->w = value.y; self->z = value.z; return *self; }

	stdmath_byte3 yww;
	stdmath_byte3 get_yww() { return {self->y,self->w,self->w}; }
	stdmath_byte4 set_yww(stdmath_byte3 value) { self->y = value.x; self->w = value.y; self->w = value.z; return *self; }

	stdmath_byte3 zxx;
	stdmath_byte3 get_zxx() { return {self->z,self->x,self->x}; }
	stdmath_byte4 set_zxx(stdmath_byte3 value) { self->z = value.x; self->x = value.y; self->x = value.z; return *self; }

	stdmath_byte3 zxy;
	stdmath_byte3 get_zxy() { return {self->z,self->x,self->y}; }
	stdmath_byte4 set_zxy(stdmath_byte3 value) { self->z = value.x; self->x = value.y; self->y = value.z; return *self; }

	stdmath_byte3 zxz;
	stdmath_byte3 get_zxz() { return {self->z,self->x,self->z}; }
	stdmath_byte4 set_zxz(stdmath_byte3 value) { self->z = value.x; self->x = value.y; self->z = value.z; return *self; }

	stdmath_byte3 zxw;
	stdmath_byte3 get_zxw() { return {self->z,self->x,self->w}; }
	stdmath_byte4 set_zxw(stdmath_byte3 value) { self->z = value.x; self->x = value.y; self->w = value.z; return *self; }

	stdmath_byte3 zyx;
	stdmath_byte3 get_zyx() { return {self->z,self->y,self->x}; }
	stdmath_byte4 set_zyx(stdmath_byte3 value) { self->z = value.x; self->y = value.y; self->x = value.z; return *self; }

	stdmath_byte3 zyy;
	stdmath_byte3 get_zyy() { return {self->z,self->y,self->y}; }
	stdmath_byte4 set_zyy(stdmath_byte3 value) { self->z = value.x; self->y = value.y; self->y = value.z; return *self; }

	stdmath_byte3 zyz;
	stdmath_byte3 get_zyz() { return {self->z,self->y,self->z}; }
	stdmath_byte4 set_zyz(stdmath_byte3 value) { self->z = value.x; self->y = value.y; self->z = value.z; return *self; }

	stdmath_byte3 zyw;
	stdmath_byte3 get_zyw() { return {self->z,self->y,self->w}; }
	stdmath_byte4 set_zyw(stdmath_byte3 value) { self->z = value.x; self->y = value.y; self->w = value.z; return *self; }

	stdmath_byte3 zzx;
	stdmath_byte3 get_zzx() { return {self->z,self->z,self->x}; }
	stdmath_byte4 set_zzx(stdmath_byte3 value) { self->z = value.x; self->z = value.y; self->x = value.z; return *self; }

	stdmath_byte3 zzy;
	stdmath_byte3 get_zzy() { return {self->z,self->z,self->y}; }
	stdmath_byte4 set_zzy(stdmath_byte3 value) { self->z = value.x; self->z = value.y; self->y = value.z; return *self; }

	stdmath_byte3 zzz;
	stdmath_byte3 get_zzz() { return {self->z,self->z,self->z}; }
	stdmath_byte4 set_zzz(stdmath_byte3 value) { self->z = value.x; self->z = value.y; self->z = value.z; return *self; }

	stdmath_byte3 zzw;
	stdmath_byte3 get_zzw() { return {self->z,self->z,self->w}; }
	stdmath_byte4 set_zzw(stdmath_byte3 value) { self->z = value.x; self->z = value.y; self->w = value.z; return *self; }

	stdmath_byte3 zwx;
	stdmath_byte3 get_zwx() { return {self->z,self->w,self->x}; }
	stdmath_byte4 set_zwx(stdmath_byte3 value) { self->z = value.x; self->w = value.y; self->x = value.z; return *self; }

	stdmath_byte3 zwy;
	stdmath_byte3 get_zwy() { return {self->z,self->w,self->y}; }
	stdmath_byte4 set_zwy(stdmath_byte3 value) { self->z = value.x; self->w = value.y; self->y = value.z; return *self; }

	stdmath_byte3 zwz;
	stdmath_byte3 get_zwz() { return {self->z,self->w,self->z}; }
	stdmath_byte4 set_zwz(stdmath_byte3 value) { self->z = value.x; self->w = value.y; self->z = value.z; return *self; }

	stdmath_byte3 zww;
	stdmath_byte3 get_zww() { return {self->z,self->w,self->w}; }
	stdmath_byte4 set_zww(stdmath_byte3 value) { self->z = value.x; self->w = value.y; self->w = value.z; return *self; }

	stdmath_byte3 wxx;
	stdmath_byte3 get_wxx() { return {self->w,self->x,self->x}; }
	stdmath_byte4 set_wxx(stdmath_byte3 value) { self->w = value.x; self->x = value.y; self->x = value.z; return *self; }

	stdmath_byte3 wxy;
	stdmath_byte3 get_wxy() { return {self->w,self->x,self->y}; }
	stdmath_byte4 set_wxy(stdmath_byte3 value) { self->w = value.x; self->x = value.y; self->y = value.z; return *self; }

	stdmath_byte3 wxz;
	stdmath_byte3 get_wxz() { return {self->w,self->x,self->z}; }
	stdmath_byte4 set_wxz(stdmath_byte3 value) { self->w = value.x; self->x = value.y; self->z = value.z; return *self; }

	stdmath_byte3 wxw;
	stdmath_byte3 get_wxw() { return {self->w,self->x,self->w}; }
	stdmath_byte4 set_wxw(stdmath_byte3 value) { self->w = value.x; self->x = value.y; self->w = value.z; return *self; }

	stdmath_byte3 wyx;
	stdmath_byte3 get_wyx() { return {self->w,self->y,self->x}; }
	stdmath_byte4 set_wyx(stdmath_byte3 value) { self->w = value.x; self->y = value.y; self->x = value.z; return *self; }

	stdmath_byte3 wyy;
	stdmath_byte3 get_wyy() { return {self->w,self->y,self->y}; }
	stdmath_byte4 set_wyy(stdmath_byte3 value) { self->w = value.x; self->y = value.y; self->y = value.z; return *self; }

	stdmath_byte3 wyz;
	stdmath_byte3 get_wyz() { return {self->w,self->y,self->z}; }
	stdmath_byte4 set_wyz(stdmath_byte3 value) { self->w = value.x; self->y = value.y; self->z = value.z; return *self; }

	stdmath_byte3 wyw;
	stdmath_byte3 get_wyw() { return {self->w,self->y,self->w}; }
	stdmath_byte4 set_wyw(stdmath_byte3 value) { self->w = value.x; self->y = value.y; self->w = value.z; return *self; }

	stdmath_byte3 wzx;
	stdmath_byte3 get_wzx() { return {self->w,self->z,self->x}; }
	stdmath_byte4 set_wzx(stdmath_byte3 value) { self->w = value.x; self->z = value.y; self->x = value.z; return *self; }

	stdmath_byte3 wzy;
	stdmath_byte3 get_wzy() { return {self->w,self->z,self->y}; }
	stdmath_byte4 set_wzy(stdmath_byte3 value) { self->w = value.x; self->z = value.y; self->y = value.z; return *self; }

	stdmath_byte3 wzz;
	stdmath_byte3 get_wzz() { return {self->w,self->z,self->z}; }
	stdmath_byte4 set_wzz(stdmath_byte3 value) { self->w = value.x; self->z = value.y; self->z = value.z; return *self; }

	stdmath_byte3 wzw;
	stdmath_byte3 get_wzw() { return {self->w,self->z,self->w}; }
	stdmath_byte4 set_wzw(stdmath_byte3 value) { self->w = value.x; self->z = value.y; self->w = value.z; return *self; }

	stdmath_byte3 wwx;
	stdmath_byte3 get_wwx() { return {self->w,self->w,self->x}; }
	stdmath_byte4 set_wwx(stdmath_byte3 value) { self->w = value.x; self->w = value.y; self->x = value.z; return *self; }

	stdmath_byte3 wwy;
	stdmath_byte3 get_wwy() { return {self->w,self->w,self->y}; }
	stdmath_byte4 set_wwy(stdmath_byte3 value) { self->w = value.x; self->w = value.y; self->y = value.z; return *self; }

	stdmath_byte3 wwz;
	stdmath_byte3 get_wwz() { return {self->w,self->w,self->z}; }
	stdmath_byte4 set_wwz(stdmath_byte3 value) { self->w = value.x; self->w = value.y; self->z = value.z; return *self; }

	stdmath_byte3 www;
	stdmath_byte3 get_www() { return {self->w,self->w,self->w}; }
	stdmath_byte4 set_www(stdmath_byte3 value) { self->w = value.x; self->w = value.y; self->w = value.z; return *self; }

	stdmath_byte4 xxxx;
	stdmath_byte4 get_xxxx() { return {self->x,self->x,self->x,self->x}; }
	stdmath_byte4 set_xxxx(stdmath_byte4 value) { self->x = value.x; self->x = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_byte4 xxxy;
	stdmath_byte4 get_xxxy() { return {self->x,self->x,self->x,self->y}; }
	stdmath_byte4 set_xxxy(stdmath_byte4 value) { self->x = value.x; self->x = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_byte4 xxxz;
	stdmath_byte4 get_xxxz() { return {self->x,self->x,self->x,self->z}; }
	stdmath_byte4 set_xxxz(stdmath_byte4 value) { self->x = value.x; self->x = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_byte4 xxxw;
	stdmath_byte4 get_xxxw() { return {self->x,self->x,self->x,self->w}; }
	stdmath_byte4 set_xxxw(stdmath_byte4 value) { self->x = value.x; self->x = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_byte4 xxyx;
	stdmath_byte4 get_xxyx() { return {self->x,self->x,self->y,self->x}; }
	stdmath_byte4 set_xxyx(stdmath_byte4 value) { self->x = value.x; self->x = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_byte4 xxyy;
	stdmath_byte4 get_xxyy() { return {self->x,self->x,self->y,self->y}; }
	stdmath_byte4 set_xxyy(stdmath_byte4 value) { self->x = value.x; self->x = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_byte4 xxyz;
	stdmath_byte4 get_xxyz() { return {self->x,self->x,self->y,self->z}; }
	stdmath_byte4 set_xxyz(stdmath_byte4 value) { self->x = value.x; self->x = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_byte4 xxyw;
	stdmath_byte4 get_xxyw() { return {self->x,self->x,self->y,self->w}; }
	stdmath_byte4 set_xxyw(stdmath_byte4 value) { self->x = value.x; self->x = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_byte4 xxzx;
	stdmath_byte4 get_xxzx() { return {self->x,self->x,self->z,self->x}; }
	stdmath_byte4 set_xxzx(stdmath_byte4 value) { self->x = value.x; self->x = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_byte4 xxzy;
	stdmath_byte4 get_xxzy() { return {self->x,self->x,self->z,self->y}; }
	stdmath_byte4 set_xxzy(stdmath_byte4 value) { self->x = value.x; self->x = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_byte4 xxzz;
	stdmath_byte4 get_xxzz() { return {self->x,self->x,self->z,self->z}; }
	stdmath_byte4 set_xxzz(stdmath_byte4 value) { self->x = value.x; self->x = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_byte4 xxzw;
	stdmath_byte4 get_xxzw() { return {self->x,self->x,self->z,self->w}; }
	stdmath_byte4 set_xxzw(stdmath_byte4 value) { self->x = value.x; self->x = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_byte4 xxwx;
	stdmath_byte4 get_xxwx() { return {self->x,self->x,self->w,self->x}; }
	stdmath_byte4 set_xxwx(stdmath_byte4 value) { self->x = value.x; self->x = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_byte4 xxwy;
	stdmath_byte4 get_xxwy() { return {self->x,self->x,self->w,self->y}; }
	stdmath_byte4 set_xxwy(stdmath_byte4 value) { self->x = value.x; self->x = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_byte4 xxwz;
	stdmath_byte4 get_xxwz() { return {self->x,self->x,self->w,self->z}; }
	stdmath_byte4 set_xxwz(stdmath_byte4 value) { self->x = value.x; self->x = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_byte4 xxww;
	stdmath_byte4 get_xxww() { return {self->x,self->x,self->w,self->w}; }
	stdmath_byte4 set_xxww(stdmath_byte4 value) { self->x = value.x; self->x = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_byte4 xyxx;
	stdmath_byte4 get_xyxx() { return {self->x,self->y,self->x,self->x}; }
	stdmath_byte4 set_xyxx(stdmath_byte4 value) { self->x = value.x; self->y = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_byte4 xyxy;
	stdmath_byte4 get_xyxy() { return {self->x,self->y,self->x,self->y}; }
	stdmath_byte4 set_xyxy(stdmath_byte4 value) { self->x = value.x; self->y = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_byte4 xyxz;
	stdmath_byte4 get_xyxz() { return {self->x,self->y,self->x,self->z}; }
	stdmath_byte4 set_xyxz(stdmath_byte4 value) { self->x = value.x; self->y = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_byte4 xyxw;
	stdmath_byte4 get_xyxw() { return {self->x,self->y,self->x,self->w}; }
	stdmath_byte4 set_xyxw(stdmath_byte4 value) { self->x = value.x; self->y = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_byte4 xyyx;
	stdmath_byte4 get_xyyx() { return {self->x,self->y,self->y,self->x}; }
	stdmath_byte4 set_xyyx(stdmath_byte4 value) { self->x = value.x; self->y = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_byte4 xyyy;
	stdmath_byte4 get_xyyy() { return {self->x,self->y,self->y,self->y}; }
	stdmath_byte4 set_xyyy(stdmath_byte4 value) { self->x = value.x; self->y = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_byte4 xyyz;
	stdmath_byte4 get_xyyz() { return {self->x,self->y,self->y,self->z}; }
	stdmath_byte4 set_xyyz(stdmath_byte4 value) { self->x = value.x; self->y = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_byte4 xyyw;
	stdmath_byte4 get_xyyw() { return {self->x,self->y,self->y,self->w}; }
	stdmath_byte4 set_xyyw(stdmath_byte4 value) { self->x = value.x; self->y = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_byte4 xyzx;
	stdmath_byte4 get_xyzx() { return {self->x,self->y,self->z,self->x}; }
	stdmath_byte4 set_xyzx(stdmath_byte4 value) { self->x = value.x; self->y = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_byte4 xyzy;
	stdmath_byte4 get_xyzy() { return {self->x,self->y,self->z,self->y}; }
	stdmath_byte4 set_xyzy(stdmath_byte4 value) { self->x = value.x; self->y = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_byte4 xyzz;
	stdmath_byte4 get_xyzz() { return {self->x,self->y,self->z,self->z}; }
	stdmath_byte4 set_xyzz(stdmath_byte4 value) { self->x = value.x; self->y = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_byte4 xyzw;
	stdmath_byte4 get_xyzw() { return {self->x,self->y,self->z,self->w}; }
	stdmath_byte4 set_xyzw(stdmath_byte4 value) { self->x = value.x; self->y = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_byte4 xywx;
	stdmath_byte4 get_xywx() { return {self->x,self->y,self->w,self->x}; }
	stdmath_byte4 set_xywx(stdmath_byte4 value) { self->x = value.x; self->y = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_byte4 xywy;
	stdmath_byte4 get_xywy() { return {self->x,self->y,self->w,self->y}; }
	stdmath_byte4 set_xywy(stdmath_byte4 value) { self->x = value.x; self->y = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_byte4 xywz;
	stdmath_byte4 get_xywz() { return {self->x,self->y,self->w,self->z}; }
	stdmath_byte4 set_xywz(stdmath_byte4 value) { self->x = value.x; self->y = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_byte4 xyww;
	stdmath_byte4 get_xyww() { return {self->x,self->y,self->w,self->w}; }
	stdmath_byte4 set_xyww(stdmath_byte4 value) { self->x = value.x; self->y = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_byte4 xzxx;
	stdmath_byte4 get_xzxx() { return {self->x,self->z,self->x,self->x}; }
	stdmath_byte4 set_xzxx(stdmath_byte4 value) { self->x = value.x; self->z = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_byte4 xzxy;
	stdmath_byte4 get_xzxy() { return {self->x,self->z,self->x,self->y}; }
	stdmath_byte4 set_xzxy(stdmath_byte4 value) { self->x = value.x; self->z = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_byte4 xzxz;
	stdmath_byte4 get_xzxz() { return {self->x,self->z,self->x,self->z}; }
	stdmath_byte4 set_xzxz(stdmath_byte4 value) { self->x = value.x; self->z = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_byte4 xzxw;
	stdmath_byte4 get_xzxw() { return {self->x,self->z,self->x,self->w}; }
	stdmath_byte4 set_xzxw(stdmath_byte4 value) { self->x = value.x; self->z = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_byte4 xzyx;
	stdmath_byte4 get_xzyx() { return {self->x,self->z,self->y,self->x}; }
	stdmath_byte4 set_xzyx(stdmath_byte4 value) { self->x = value.x; self->z = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_byte4 xzyy;
	stdmath_byte4 get_xzyy() { return {self->x,self->z,self->y,self->y}; }
	stdmath_byte4 set_xzyy(stdmath_byte4 value) { self->x = value.x; self->z = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_byte4 xzyz;
	stdmath_byte4 get_xzyz() { return {self->x,self->z,self->y,self->z}; }
	stdmath_byte4 set_xzyz(stdmath_byte4 value) { self->x = value.x; self->z = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_byte4 xzyw;
	stdmath_byte4 get_xzyw() { return {self->x,self->z,self->y,self->w}; }
	stdmath_byte4 set_xzyw(stdmath_byte4 value) { self->x = value.x; self->z = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_byte4 xzzx;
	stdmath_byte4 get_xzzx() { return {self->x,self->z,self->z,self->x}; }
	stdmath_byte4 set_xzzx(stdmath_byte4 value) { self->x = value.x; self->z = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_byte4 xzzy;
	stdmath_byte4 get_xzzy() { return {self->x,self->z,self->z,self->y}; }
	stdmath_byte4 set_xzzy(stdmath_byte4 value) { self->x = value.x; self->z = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_byte4 xzzz;
	stdmath_byte4 get_xzzz() { return {self->x,self->z,self->z,self->z}; }
	stdmath_byte4 set_xzzz(stdmath_byte4 value) { self->x = value.x; self->z = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_byte4 xzzw;
	stdmath_byte4 get_xzzw() { return {self->x,self->z,self->z,self->w}; }
	stdmath_byte4 set_xzzw(stdmath_byte4 value) { self->x = value.x; self->z = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_byte4 xzwx;
	stdmath_byte4 get_xzwx() { return {self->x,self->z,self->w,self->x}; }
	stdmath_byte4 set_xzwx(stdmath_byte4 value) { self->x = value.x; self->z = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_byte4 xzwy;
	stdmath_byte4 get_xzwy() { return {self->x,self->z,self->w,self->y}; }
	stdmath_byte4 set_xzwy(stdmath_byte4 value) { self->x = value.x; self->z = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_byte4 xzwz;
	stdmath_byte4 get_xzwz() { return {self->x,self->z,self->w,self->z}; }
	stdmath_byte4 set_xzwz(stdmath_byte4 value) { self->x = value.x; self->z = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_byte4 xzww;
	stdmath_byte4 get_xzww() { return {self->x,self->z,self->w,self->w}; }
	stdmath_byte4 set_xzww(stdmath_byte4 value) { self->x = value.x; self->z = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_byte4 xwxx;
	stdmath_byte4 get_xwxx() { return {self->x,self->w,self->x,self->x}; }
	stdmath_byte4 set_xwxx(stdmath_byte4 value) { self->x = value.x; self->w = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_byte4 xwxy;
	stdmath_byte4 get_xwxy() { return {self->x,self->w,self->x,self->y}; }
	stdmath_byte4 set_xwxy(stdmath_byte4 value) { self->x = value.x; self->w = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_byte4 xwxz;
	stdmath_byte4 get_xwxz() { return {self->x,self->w,self->x,self->z}; }
	stdmath_byte4 set_xwxz(stdmath_byte4 value) { self->x = value.x; self->w = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_byte4 xwxw;
	stdmath_byte4 get_xwxw() { return {self->x,self->w,self->x,self->w}; }
	stdmath_byte4 set_xwxw(stdmath_byte4 value) { self->x = value.x; self->w = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_byte4 xwyx;
	stdmath_byte4 get_xwyx() { return {self->x,self->w,self->y,self->x}; }
	stdmath_byte4 set_xwyx(stdmath_byte4 value) { self->x = value.x; self->w = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_byte4 xwyy;
	stdmath_byte4 get_xwyy() { return {self->x,self->w,self->y,self->y}; }
	stdmath_byte4 set_xwyy(stdmath_byte4 value) { self->x = value.x; self->w = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_byte4 xwyz;
	stdmath_byte4 get_xwyz() { return {self->x,self->w,self->y,self->z}; }
	stdmath_byte4 set_xwyz(stdmath_byte4 value) { self->x = value.x; self->w = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_byte4 xwyw;
	stdmath_byte4 get_xwyw() { return {self->x,self->w,self->y,self->w}; }
	stdmath_byte4 set_xwyw(stdmath_byte4 value) { self->x = value.x; self->w = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_byte4 xwzx;
	stdmath_byte4 get_xwzx() { return {self->x,self->w,self->z,self->x}; }
	stdmath_byte4 set_xwzx(stdmath_byte4 value) { self->x = value.x; self->w = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_byte4 xwzy;
	stdmath_byte4 get_xwzy() { return {self->x,self->w,self->z,self->y}; }
	stdmath_byte4 set_xwzy(stdmath_byte4 value) { self->x = value.x; self->w = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_byte4 xwzz;
	stdmath_byte4 get_xwzz() { return {self->x,self->w,self->z,self->z}; }
	stdmath_byte4 set_xwzz(stdmath_byte4 value) { self->x = value.x; self->w = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_byte4 xwzw;
	stdmath_byte4 get_xwzw() { return {self->x,self->w,self->z,self->w}; }
	stdmath_byte4 set_xwzw(stdmath_byte4 value) { self->x = value.x; self->w = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_byte4 xwwx;
	stdmath_byte4 get_xwwx() { return {self->x,self->w,self->w,self->x}; }
	stdmath_byte4 set_xwwx(stdmath_byte4 value) { self->x = value.x; self->w = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_byte4 xwwy;
	stdmath_byte4 get_xwwy() { return {self->x,self->w,self->w,self->y}; }
	stdmath_byte4 set_xwwy(stdmath_byte4 value) { self->x = value.x; self->w = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_byte4 xwwz;
	stdmath_byte4 get_xwwz() { return {self->x,self->w,self->w,self->z}; }
	stdmath_byte4 set_xwwz(stdmath_byte4 value) { self->x = value.x; self->w = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_byte4 xwww;
	stdmath_byte4 get_xwww() { return {self->x,self->w,self->w,self->w}; }
	stdmath_byte4 set_xwww(stdmath_byte4 value) { self->x = value.x; self->w = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_byte4 yxxx;
	stdmath_byte4 get_yxxx() { return {self->y,self->x,self->x,self->x}; }
	stdmath_byte4 set_yxxx(stdmath_byte4 value) { self->y = value.x; self->x = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_byte4 yxxy;
	stdmath_byte4 get_yxxy() { return {self->y,self->x,self->x,self->y}; }
	stdmath_byte4 set_yxxy(stdmath_byte4 value) { self->y = value.x; self->x = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_byte4 yxxz;
	stdmath_byte4 get_yxxz() { return {self->y,self->x,self->x,self->z}; }
	stdmath_byte4 set_yxxz(stdmath_byte4 value) { self->y = value.x; self->x = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_byte4 yxxw;
	stdmath_byte4 get_yxxw() { return {self->y,self->x,self->x,self->w}; }
	stdmath_byte4 set_yxxw(stdmath_byte4 value) { self->y = value.x; self->x = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_byte4 yxyx;
	stdmath_byte4 get_yxyx() { return {self->y,self->x,self->y,self->x}; }
	stdmath_byte4 set_yxyx(stdmath_byte4 value) { self->y = value.x; self->x = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_byte4 yxyy;
	stdmath_byte4 get_yxyy() { return {self->y,self->x,self->y,self->y}; }
	stdmath_byte4 set_yxyy(stdmath_byte4 value) { self->y = value.x; self->x = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_byte4 yxyz;
	stdmath_byte4 get_yxyz() { return {self->y,self->x,self->y,self->z}; }
	stdmath_byte4 set_yxyz(stdmath_byte4 value) { self->y = value.x; self->x = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_byte4 yxyw;
	stdmath_byte4 get_yxyw() { return {self->y,self->x,self->y,self->w}; }
	stdmath_byte4 set_yxyw(stdmath_byte4 value) { self->y = value.x; self->x = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_byte4 yxzx;
	stdmath_byte4 get_yxzx() { return {self->y,self->x,self->z,self->x}; }
	stdmath_byte4 set_yxzx(stdmath_byte4 value) { self->y = value.x; self->x = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_byte4 yxzy;
	stdmath_byte4 get_yxzy() { return {self->y,self->x,self->z,self->y}; }
	stdmath_byte4 set_yxzy(stdmath_byte4 value) { self->y = value.x; self->x = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_byte4 yxzz;
	stdmath_byte4 get_yxzz() { return {self->y,self->x,self->z,self->z}; }
	stdmath_byte4 set_yxzz(stdmath_byte4 value) { self->y = value.x; self->x = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_byte4 yxzw;
	stdmath_byte4 get_yxzw() { return {self->y,self->x,self->z,self->w}; }
	stdmath_byte4 set_yxzw(stdmath_byte4 value) { self->y = value.x; self->x = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_byte4 yxwx;
	stdmath_byte4 get_yxwx() { return {self->y,self->x,self->w,self->x}; }
	stdmath_byte4 set_yxwx(stdmath_byte4 value) { self->y = value.x; self->x = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_byte4 yxwy;
	stdmath_byte4 get_yxwy() { return {self->y,self->x,self->w,self->y}; }
	stdmath_byte4 set_yxwy(stdmath_byte4 value) { self->y = value.x; self->x = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_byte4 yxwz;
	stdmath_byte4 get_yxwz() { return {self->y,self->x,self->w,self->z}; }
	stdmath_byte4 set_yxwz(stdmath_byte4 value) { self->y = value.x; self->x = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_byte4 yxww;
	stdmath_byte4 get_yxww() { return {self->y,self->x,self->w,self->w}; }
	stdmath_byte4 set_yxww(stdmath_byte4 value) { self->y = value.x; self->x = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_byte4 yyxx;
	stdmath_byte4 get_yyxx() { return {self->y,self->y,self->x,self->x}; }
	stdmath_byte4 set_yyxx(stdmath_byte4 value) { self->y = value.x; self->y = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_byte4 yyxy;
	stdmath_byte4 get_yyxy() { return {self->y,self->y,self->x,self->y}; }
	stdmath_byte4 set_yyxy(stdmath_byte4 value) { self->y = value.x; self->y = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_byte4 yyxz;
	stdmath_byte4 get_yyxz() { return {self->y,self->y,self->x,self->z}; }
	stdmath_byte4 set_yyxz(stdmath_byte4 value) { self->y = value.x; self->y = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_byte4 yyxw;
	stdmath_byte4 get_yyxw() { return {self->y,self->y,self->x,self->w}; }
	stdmath_byte4 set_yyxw(stdmath_byte4 value) { self->y = value.x; self->y = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_byte4 yyyx;
	stdmath_byte4 get_yyyx() { return {self->y,self->y,self->y,self->x}; }
	stdmath_byte4 set_yyyx(stdmath_byte4 value) { self->y = value.x; self->y = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_byte4 yyyy;
	stdmath_byte4 get_yyyy() { return {self->y,self->y,self->y,self->y}; }
	stdmath_byte4 set_yyyy(stdmath_byte4 value) { self->y = value.x; self->y = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_byte4 yyyz;
	stdmath_byte4 get_yyyz() { return {self->y,self->y,self->y,self->z}; }
	stdmath_byte4 set_yyyz(stdmath_byte4 value) { self->y = value.x; self->y = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_byte4 yyyw;
	stdmath_byte4 get_yyyw() { return {self->y,self->y,self->y,self->w}; }
	stdmath_byte4 set_yyyw(stdmath_byte4 value) { self->y = value.x; self->y = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_byte4 yyzx;
	stdmath_byte4 get_yyzx() { return {self->y,self->y,self->z,self->x}; }
	stdmath_byte4 set_yyzx(stdmath_byte4 value) { self->y = value.x; self->y = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_byte4 yyzy;
	stdmath_byte4 get_yyzy() { return {self->y,self->y,self->z,self->y}; }
	stdmath_byte4 set_yyzy(stdmath_byte4 value) { self->y = value.x; self->y = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_byte4 yyzz;
	stdmath_byte4 get_yyzz() { return {self->y,self->y,self->z,self->z}; }
	stdmath_byte4 set_yyzz(stdmath_byte4 value) { self->y = value.x; self->y = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_byte4 yyzw;
	stdmath_byte4 get_yyzw() { return {self->y,self->y,self->z,self->w}; }
	stdmath_byte4 set_yyzw(stdmath_byte4 value) { self->y = value.x; self->y = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_byte4 yywx;
	stdmath_byte4 get_yywx() { return {self->y,self->y,self->w,self->x}; }
	stdmath_byte4 set_yywx(stdmath_byte4 value) { self->y = value.x; self->y = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_byte4 yywy;
	stdmath_byte4 get_yywy() { return {self->y,self->y,self->w,self->y}; }
	stdmath_byte4 set_yywy(stdmath_byte4 value) { self->y = value.x; self->y = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_byte4 yywz;
	stdmath_byte4 get_yywz() { return {self->y,self->y,self->w,self->z}; }
	stdmath_byte4 set_yywz(stdmath_byte4 value) { self->y = value.x; self->y = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_byte4 yyww;
	stdmath_byte4 get_yyww() { return {self->y,self->y,self->w,self->w}; }
	stdmath_byte4 set_yyww(stdmath_byte4 value) { self->y = value.x; self->y = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_byte4 yzxx;
	stdmath_byte4 get_yzxx() { return {self->y,self->z,self->x,self->x}; }
	stdmath_byte4 set_yzxx(stdmath_byte4 value) { self->y = value.x; self->z = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_byte4 yzxy;
	stdmath_byte4 get_yzxy() { return {self->y,self->z,self->x,self->y}; }
	stdmath_byte4 set_yzxy(stdmath_byte4 value) { self->y = value.x; self->z = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_byte4 yzxz;
	stdmath_byte4 get_yzxz() { return {self->y,self->z,self->x,self->z}; }
	stdmath_byte4 set_yzxz(stdmath_byte4 value) { self->y = value.x; self->z = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_byte4 yzxw;
	stdmath_byte4 get_yzxw() { return {self->y,self->z,self->x,self->w}; }
	stdmath_byte4 set_yzxw(stdmath_byte4 value) { self->y = value.x; self->z = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_byte4 yzyx;
	stdmath_byte4 get_yzyx() { return {self->y,self->z,self->y,self->x}; }
	stdmath_byte4 set_yzyx(stdmath_byte4 value) { self->y = value.x; self->z = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_byte4 yzyy;
	stdmath_byte4 get_yzyy() { return {self->y,self->z,self->y,self->y}; }
	stdmath_byte4 set_yzyy(stdmath_byte4 value) { self->y = value.x; self->z = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_byte4 yzyz;
	stdmath_byte4 get_yzyz() { return {self->y,self->z,self->y,self->z}; }
	stdmath_byte4 set_yzyz(stdmath_byte4 value) { self->y = value.x; self->z = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_byte4 yzyw;
	stdmath_byte4 get_yzyw() { return {self->y,self->z,self->y,self->w}; }
	stdmath_byte4 set_yzyw(stdmath_byte4 value) { self->y = value.x; self->z = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_byte4 yzzx;
	stdmath_byte4 get_yzzx() { return {self->y,self->z,self->z,self->x}; }
	stdmath_byte4 set_yzzx(stdmath_byte4 value) { self->y = value.x; self->z = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_byte4 yzzy;
	stdmath_byte4 get_yzzy() { return {self->y,self->z,self->z,self->y}; }
	stdmath_byte4 set_yzzy(stdmath_byte4 value) { self->y = value.x; self->z = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_byte4 yzzz;
	stdmath_byte4 get_yzzz() { return {self->y,self->z,self->z,self->z}; }
	stdmath_byte4 set_yzzz(stdmath_byte4 value) { self->y = value.x; self->z = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_byte4 yzzw;
	stdmath_byte4 get_yzzw() { return {self->y,self->z,self->z,self->w}; }
	stdmath_byte4 set_yzzw(stdmath_byte4 value) { self->y = value.x; self->z = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_byte4 yzwx;
	stdmath_byte4 get_yzwx() { return {self->y,self->z,self->w,self->x}; }
	stdmath_byte4 set_yzwx(stdmath_byte4 value) { self->y = value.x; self->z = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_byte4 yzwy;
	stdmath_byte4 get_yzwy() { return {self->y,self->z,self->w,self->y}; }
	stdmath_byte4 set_yzwy(stdmath_byte4 value) { self->y = value.x; self->z = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_byte4 yzwz;
	stdmath_byte4 get_yzwz() { return {self->y,self->z,self->w,self->z}; }
	stdmath_byte4 set_yzwz(stdmath_byte4 value) { self->y = value.x; self->z = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_byte4 yzww;
	stdmath_byte4 get_yzww() { return {self->y,self->z,self->w,self->w}; }
	stdmath_byte4 set_yzww(stdmath_byte4 value) { self->y = value.x; self->z = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_byte4 ywxx;
	stdmath_byte4 get_ywxx() { return {self->y,self->w,self->x,self->x}; }
	stdmath_byte4 set_ywxx(stdmath_byte4 value) { self->y = value.x; self->w = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_byte4 ywxy;
	stdmath_byte4 get_ywxy() { return {self->y,self->w,self->x,self->y}; }
	stdmath_byte4 set_ywxy(stdmath_byte4 value) { self->y = value.x; self->w = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_byte4 ywxz;
	stdmath_byte4 get_ywxz() { return {self->y,self->w,self->x,self->z}; }
	stdmath_byte4 set_ywxz(stdmath_byte4 value) { self->y = value.x; self->w = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_byte4 ywxw;
	stdmath_byte4 get_ywxw() { return {self->y,self->w,self->x,self->w}; }
	stdmath_byte4 set_ywxw(stdmath_byte4 value) { self->y = value.x; self->w = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_byte4 ywyx;
	stdmath_byte4 get_ywyx() { return {self->y,self->w,self->y,self->x}; }
	stdmath_byte4 set_ywyx(stdmath_byte4 value) { self->y = value.x; self->w = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_byte4 ywyy;
	stdmath_byte4 get_ywyy() { return {self->y,self->w,self->y,self->y}; }
	stdmath_byte4 set_ywyy(stdmath_byte4 value) { self->y = value.x; self->w = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_byte4 ywyz;
	stdmath_byte4 get_ywyz() { return {self->y,self->w,self->y,self->z}; }
	stdmath_byte4 set_ywyz(stdmath_byte4 value) { self->y = value.x; self->w = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_byte4 ywyw;
	stdmath_byte4 get_ywyw() { return {self->y,self->w,self->y,self->w}; }
	stdmath_byte4 set_ywyw(stdmath_byte4 value) { self->y = value.x; self->w = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_byte4 ywzx;
	stdmath_byte4 get_ywzx() { return {self->y,self->w,self->z,self->x}; }
	stdmath_byte4 set_ywzx(stdmath_byte4 value) { self->y = value.x; self->w = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_byte4 ywzy;
	stdmath_byte4 get_ywzy() { return {self->y,self->w,self->z,self->y}; }
	stdmath_byte4 set_ywzy(stdmath_byte4 value) { self->y = value.x; self->w = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_byte4 ywzz;
	stdmath_byte4 get_ywzz() { return {self->y,self->w,self->z,self->z}; }
	stdmath_byte4 set_ywzz(stdmath_byte4 value) { self->y = value.x; self->w = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_byte4 ywzw;
	stdmath_byte4 get_ywzw() { return {self->y,self->w,self->z,self->w}; }
	stdmath_byte4 set_ywzw(stdmath_byte4 value) { self->y = value.x; self->w = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_byte4 ywwx;
	stdmath_byte4 get_ywwx() { return {self->y,self->w,self->w,self->x}; }
	stdmath_byte4 set_ywwx(stdmath_byte4 value) { self->y = value.x; self->w = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_byte4 ywwy;
	stdmath_byte4 get_ywwy() { return {self->y,self->w,self->w,self->y}; }
	stdmath_byte4 set_ywwy(stdmath_byte4 value) { self->y = value.x; self->w = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_byte4 ywwz;
	stdmath_byte4 get_ywwz() { return {self->y,self->w,self->w,self->z}; }
	stdmath_byte4 set_ywwz(stdmath_byte4 value) { self->y = value.x; self->w = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_byte4 ywww;
	stdmath_byte4 get_ywww() { return {self->y,self->w,self->w,self->w}; }
	stdmath_byte4 set_ywww(stdmath_byte4 value) { self->y = value.x; self->w = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_byte4 zxxx;
	stdmath_byte4 get_zxxx() { return {self->z,self->x,self->x,self->x}; }
	stdmath_byte4 set_zxxx(stdmath_byte4 value) { self->z = value.x; self->x = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_byte4 zxxy;
	stdmath_byte4 get_zxxy() { return {self->z,self->x,self->x,self->y}; }
	stdmath_byte4 set_zxxy(stdmath_byte4 value) { self->z = value.x; self->x = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_byte4 zxxz;
	stdmath_byte4 get_zxxz() { return {self->z,self->x,self->x,self->z}; }
	stdmath_byte4 set_zxxz(stdmath_byte4 value) { self->z = value.x; self->x = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_byte4 zxxw;
	stdmath_byte4 get_zxxw() { return {self->z,self->x,self->x,self->w}; }
	stdmath_byte4 set_zxxw(stdmath_byte4 value) { self->z = value.x; self->x = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_byte4 zxyx;
	stdmath_byte4 get_zxyx() { return {self->z,self->x,self->y,self->x}; }
	stdmath_byte4 set_zxyx(stdmath_byte4 value) { self->z = value.x; self->x = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_byte4 zxyy;
	stdmath_byte4 get_zxyy() { return {self->z,self->x,self->y,self->y}; }
	stdmath_byte4 set_zxyy(stdmath_byte4 value) { self->z = value.x; self->x = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_byte4 zxyz;
	stdmath_byte4 get_zxyz() { return {self->z,self->x,self->y,self->z}; }
	stdmath_byte4 set_zxyz(stdmath_byte4 value) { self->z = value.x; self->x = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_byte4 zxyw;
	stdmath_byte4 get_zxyw() { return {self->z,self->x,self->y,self->w}; }
	stdmath_byte4 set_zxyw(stdmath_byte4 value) { self->z = value.x; self->x = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_byte4 zxzx;
	stdmath_byte4 get_zxzx() { return {self->z,self->x,self->z,self->x}; }
	stdmath_byte4 set_zxzx(stdmath_byte4 value) { self->z = value.x; self->x = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_byte4 zxzy;
	stdmath_byte4 get_zxzy() { return {self->z,self->x,self->z,self->y}; }
	stdmath_byte4 set_zxzy(stdmath_byte4 value) { self->z = value.x; self->x = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_byte4 zxzz;
	stdmath_byte4 get_zxzz() { return {self->z,self->x,self->z,self->z}; }
	stdmath_byte4 set_zxzz(stdmath_byte4 value) { self->z = value.x; self->x = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_byte4 zxzw;
	stdmath_byte4 get_zxzw() { return {self->z,self->x,self->z,self->w}; }
	stdmath_byte4 set_zxzw(stdmath_byte4 value) { self->z = value.x; self->x = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_byte4 zxwx;
	stdmath_byte4 get_zxwx() { return {self->z,self->x,self->w,self->x}; }
	stdmath_byte4 set_zxwx(stdmath_byte4 value) { self->z = value.x; self->x = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_byte4 zxwy;
	stdmath_byte4 get_zxwy() { return {self->z,self->x,self->w,self->y}; }
	stdmath_byte4 set_zxwy(stdmath_byte4 value) { self->z = value.x; self->x = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_byte4 zxwz;
	stdmath_byte4 get_zxwz() { return {self->z,self->x,self->w,self->z}; }
	stdmath_byte4 set_zxwz(stdmath_byte4 value) { self->z = value.x; self->x = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_byte4 zxww;
	stdmath_byte4 get_zxww() { return {self->z,self->x,self->w,self->w}; }
	stdmath_byte4 set_zxww(stdmath_byte4 value) { self->z = value.x; self->x = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_byte4 zyxx;
	stdmath_byte4 get_zyxx() { return {self->z,self->y,self->x,self->x}; }
	stdmath_byte4 set_zyxx(stdmath_byte4 value) { self->z = value.x; self->y = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_byte4 zyxy;
	stdmath_byte4 get_zyxy() { return {self->z,self->y,self->x,self->y}; }
	stdmath_byte4 set_zyxy(stdmath_byte4 value) { self->z = value.x; self->y = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_byte4 zyxz;
	stdmath_byte4 get_zyxz() { return {self->z,self->y,self->x,self->z}; }
	stdmath_byte4 set_zyxz(stdmath_byte4 value) { self->z = value.x; self->y = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_byte4 zyxw;
	stdmath_byte4 get_zyxw() { return {self->z,self->y,self->x,self->w}; }
	stdmath_byte4 set_zyxw(stdmath_byte4 value) { self->z = value.x; self->y = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_byte4 zyyx;
	stdmath_byte4 get_zyyx() { return {self->z,self->y,self->y,self->x}; }
	stdmath_byte4 set_zyyx(stdmath_byte4 value) { self->z = value.x; self->y = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_byte4 zyyy;
	stdmath_byte4 get_zyyy() { return {self->z,self->y,self->y,self->y}; }
	stdmath_byte4 set_zyyy(stdmath_byte4 value) { self->z = value.x; self->y = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_byte4 zyyz;
	stdmath_byte4 get_zyyz() { return {self->z,self->y,self->y,self->z}; }
	stdmath_byte4 set_zyyz(stdmath_byte4 value) { self->z = value.x; self->y = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_byte4 zyyw;
	stdmath_byte4 get_zyyw() { return {self->z,self->y,self->y,self->w}; }
	stdmath_byte4 set_zyyw(stdmath_byte4 value) { self->z = value.x; self->y = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_byte4 zyzx;
	stdmath_byte4 get_zyzx() { return {self->z,self->y,self->z,self->x}; }
	stdmath_byte4 set_zyzx(stdmath_byte4 value) { self->z = value.x; self->y = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_byte4 zyzy;
	stdmath_byte4 get_zyzy() { return {self->z,self->y,self->z,self->y}; }
	stdmath_byte4 set_zyzy(stdmath_byte4 value) { self->z = value.x; self->y = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_byte4 zyzz;
	stdmath_byte4 get_zyzz() { return {self->z,self->y,self->z,self->z}; }
	stdmath_byte4 set_zyzz(stdmath_byte4 value) { self->z = value.x; self->y = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_byte4 zyzw;
	stdmath_byte4 get_zyzw() { return {self->z,self->y,self->z,self->w}; }
	stdmath_byte4 set_zyzw(stdmath_byte4 value) { self->z = value.x; self->y = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_byte4 zywx;
	stdmath_byte4 get_zywx() { return {self->z,self->y,self->w,self->x}; }
	stdmath_byte4 set_zywx(stdmath_byte4 value) { self->z = value.x; self->y = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_byte4 zywy;
	stdmath_byte4 get_zywy() { return {self->z,self->y,self->w,self->y}; }
	stdmath_byte4 set_zywy(stdmath_byte4 value) { self->z = value.x; self->y = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_byte4 zywz;
	stdmath_byte4 get_zywz() { return {self->z,self->y,self->w,self->z}; }
	stdmath_byte4 set_zywz(stdmath_byte4 value) { self->z = value.x; self->y = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_byte4 zyww;
	stdmath_byte4 get_zyww() { return {self->z,self->y,self->w,self->w}; }
	stdmath_byte4 set_zyww(stdmath_byte4 value) { self->z = value.x; self->y = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_byte4 zzxx;
	stdmath_byte4 get_zzxx() { return {self->z,self->z,self->x,self->x}; }
	stdmath_byte4 set_zzxx(stdmath_byte4 value) { self->z = value.x; self->z = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_byte4 zzxy;
	stdmath_byte4 get_zzxy() { return {self->z,self->z,self->x,self->y}; }
	stdmath_byte4 set_zzxy(stdmath_byte4 value) { self->z = value.x; self->z = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_byte4 zzxz;
	stdmath_byte4 get_zzxz() { return {self->z,self->z,self->x,self->z}; }
	stdmath_byte4 set_zzxz(stdmath_byte4 value) { self->z = value.x; self->z = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_byte4 zzxw;
	stdmath_byte4 get_zzxw() { return {self->z,self->z,self->x,self->w}; }
	stdmath_byte4 set_zzxw(stdmath_byte4 value) { self->z = value.x; self->z = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_byte4 zzyx;
	stdmath_byte4 get_zzyx() { return {self->z,self->z,self->y,self->x}; }
	stdmath_byte4 set_zzyx(stdmath_byte4 value) { self->z = value.x; self->z = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_byte4 zzyy;
	stdmath_byte4 get_zzyy() { return {self->z,self->z,self->y,self->y}; }
	stdmath_byte4 set_zzyy(stdmath_byte4 value) { self->z = value.x; self->z = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_byte4 zzyz;
	stdmath_byte4 get_zzyz() { return {self->z,self->z,self->y,self->z}; }
	stdmath_byte4 set_zzyz(stdmath_byte4 value) { self->z = value.x; self->z = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_byte4 zzyw;
	stdmath_byte4 get_zzyw() { return {self->z,self->z,self->y,self->w}; }
	stdmath_byte4 set_zzyw(stdmath_byte4 value) { self->z = value.x; self->z = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_byte4 zzzx;
	stdmath_byte4 get_zzzx() { return {self->z,self->z,self->z,self->x}; }
	stdmath_byte4 set_zzzx(stdmath_byte4 value) { self->z = value.x; self->z = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_byte4 zzzy;
	stdmath_byte4 get_zzzy() { return {self->z,self->z,self->z,self->y}; }
	stdmath_byte4 set_zzzy(stdmath_byte4 value) { self->z = value.x; self->z = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_byte4 zzzz;
	stdmath_byte4 get_zzzz() { return {self->z,self->z,self->z,self->z}; }
	stdmath_byte4 set_zzzz(stdmath_byte4 value) { self->z = value.x; self->z = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_byte4 zzzw;
	stdmath_byte4 get_zzzw() { return {self->z,self->z,self->z,self->w}; }
	stdmath_byte4 set_zzzw(stdmath_byte4 value) { self->z = value.x; self->z = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_byte4 zzwx;
	stdmath_byte4 get_zzwx() { return {self->z,self->z,self->w,self->x}; }
	stdmath_byte4 set_zzwx(stdmath_byte4 value) { self->z = value.x; self->z = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_byte4 zzwy;
	stdmath_byte4 get_zzwy() { return {self->z,self->z,self->w,self->y}; }
	stdmath_byte4 set_zzwy(stdmath_byte4 value) { self->z = value.x; self->z = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_byte4 zzwz;
	stdmath_byte4 get_zzwz() { return {self->z,self->z,self->w,self->z}; }
	stdmath_byte4 set_zzwz(stdmath_byte4 value) { self->z = value.x; self->z = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_byte4 zzww;
	stdmath_byte4 get_zzww() { return {self->z,self->z,self->w,self->w}; }
	stdmath_byte4 set_zzww(stdmath_byte4 value) { self->z = value.x; self->z = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_byte4 zwxx;
	stdmath_byte4 get_zwxx() { return {self->z,self->w,self->x,self->x}; }
	stdmath_byte4 set_zwxx(stdmath_byte4 value) { self->z = value.x; self->w = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_byte4 zwxy;
	stdmath_byte4 get_zwxy() { return {self->z,self->w,self->x,self->y}; }
	stdmath_byte4 set_zwxy(stdmath_byte4 value) { self->z = value.x; self->w = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_byte4 zwxz;
	stdmath_byte4 get_zwxz() { return {self->z,self->w,self->x,self->z}; }
	stdmath_byte4 set_zwxz(stdmath_byte4 value) { self->z = value.x; self->w = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_byte4 zwxw;
	stdmath_byte4 get_zwxw() { return {self->z,self->w,self->x,self->w}; }
	stdmath_byte4 set_zwxw(stdmath_byte4 value) { self->z = value.x; self->w = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_byte4 zwyx;
	stdmath_byte4 get_zwyx() { return {self->z,self->w,self->y,self->x}; }
	stdmath_byte4 set_zwyx(stdmath_byte4 value) { self->z = value.x; self->w = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_byte4 zwyy;
	stdmath_byte4 get_zwyy() { return {self->z,self->w,self->y,self->y}; }
	stdmath_byte4 set_zwyy(stdmath_byte4 value) { self->z = value.x; self->w = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_byte4 zwyz;
	stdmath_byte4 get_zwyz() { return {self->z,self->w,self->y,self->z}; }
	stdmath_byte4 set_zwyz(stdmath_byte4 value) { self->z = value.x; self->w = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_byte4 zwyw;
	stdmath_byte4 get_zwyw() { return {self->z,self->w,self->y,self->w}; }
	stdmath_byte4 set_zwyw(stdmath_byte4 value) { self->z = value.x; self->w = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_byte4 zwzx;
	stdmath_byte4 get_zwzx() { return {self->z,self->w,self->z,self->x}; }
	stdmath_byte4 set_zwzx(stdmath_byte4 value) { self->z = value.x; self->w = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_byte4 zwzy;
	stdmath_byte4 get_zwzy() { return {self->z,self->w,self->z,self->y}; }
	stdmath_byte4 set_zwzy(stdmath_byte4 value) { self->z = value.x; self->w = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_byte4 zwzz;
	stdmath_byte4 get_zwzz() { return {self->z,self->w,self->z,self->z}; }
	stdmath_byte4 set_zwzz(stdmath_byte4 value) { self->z = value.x; self->w = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_byte4 zwzw;
	stdmath_byte4 get_zwzw() { return {self->z,self->w,self->z,self->w}; }
	stdmath_byte4 set_zwzw(stdmath_byte4 value) { self->z = value.x; self->w = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_byte4 zwwx;
	stdmath_byte4 get_zwwx() { return {self->z,self->w,self->w,self->x}; }
	stdmath_byte4 set_zwwx(stdmath_byte4 value) { self->z = value.x; self->w = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_byte4 zwwy;
	stdmath_byte4 get_zwwy() { return {self->z,self->w,self->w,self->y}; }
	stdmath_byte4 set_zwwy(stdmath_byte4 value) { self->z = value.x; self->w = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_byte4 zwwz;
	stdmath_byte4 get_zwwz() { return {self->z,self->w,self->w,self->z}; }
	stdmath_byte4 set_zwwz(stdmath_byte4 value) { self->z = value.x; self->w = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_byte4 zwww;
	stdmath_byte4 get_zwww() { return {self->z,self->w,self->w,self->w}; }
	stdmath_byte4 set_zwww(stdmath_byte4 value) { self->z = value.x; self->w = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_byte4 wxxx;
	stdmath_byte4 get_wxxx() { return {self->w,self->x,self->x,self->x}; }
	stdmath_byte4 set_wxxx(stdmath_byte4 value) { self->w = value.x; self->x = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_byte4 wxxy;
	stdmath_byte4 get_wxxy() { return {self->w,self->x,self->x,self->y}; }
	stdmath_byte4 set_wxxy(stdmath_byte4 value) { self->w = value.x; self->x = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_byte4 wxxz;
	stdmath_byte4 get_wxxz() { return {self->w,self->x,self->x,self->z}; }
	stdmath_byte4 set_wxxz(stdmath_byte4 value) { self->w = value.x; self->x = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_byte4 wxxw;
	stdmath_byte4 get_wxxw() { return {self->w,self->x,self->x,self->w}; }
	stdmath_byte4 set_wxxw(stdmath_byte4 value) { self->w = value.x; self->x = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_byte4 wxyx;
	stdmath_byte4 get_wxyx() { return {self->w,self->x,self->y,self->x}; }
	stdmath_byte4 set_wxyx(stdmath_byte4 value) { self->w = value.x; self->x = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_byte4 wxyy;
	stdmath_byte4 get_wxyy() { return {self->w,self->x,self->y,self->y}; }
	stdmath_byte4 set_wxyy(stdmath_byte4 value) { self->w = value.x; self->x = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_byte4 wxyz;
	stdmath_byte4 get_wxyz() { return {self->w,self->x,self->y,self->z}; }
	stdmath_byte4 set_wxyz(stdmath_byte4 value) { self->w = value.x; self->x = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_byte4 wxyw;
	stdmath_byte4 get_wxyw() { return {self->w,self->x,self->y,self->w}; }
	stdmath_byte4 set_wxyw(stdmath_byte4 value) { self->w = value.x; self->x = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_byte4 wxzx;
	stdmath_byte4 get_wxzx() { return {self->w,self->x,self->z,self->x}; }
	stdmath_byte4 set_wxzx(stdmath_byte4 value) { self->w = value.x; self->x = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_byte4 wxzy;
	stdmath_byte4 get_wxzy() { return {self->w,self->x,self->z,self->y}; }
	stdmath_byte4 set_wxzy(stdmath_byte4 value) { self->w = value.x; self->x = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_byte4 wxzz;
	stdmath_byte4 get_wxzz() { return {self->w,self->x,self->z,self->z}; }
	stdmath_byte4 set_wxzz(stdmath_byte4 value) { self->w = value.x; self->x = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_byte4 wxzw;
	stdmath_byte4 get_wxzw() { return {self->w,self->x,self->z,self->w}; }
	stdmath_byte4 set_wxzw(stdmath_byte4 value) { self->w = value.x; self->x = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_byte4 wxwx;
	stdmath_byte4 get_wxwx() { return {self->w,self->x,self->w,self->x}; }
	stdmath_byte4 set_wxwx(stdmath_byte4 value) { self->w = value.x; self->x = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_byte4 wxwy;
	stdmath_byte4 get_wxwy() { return {self->w,self->x,self->w,self->y}; }
	stdmath_byte4 set_wxwy(stdmath_byte4 value) { self->w = value.x; self->x = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_byte4 wxwz;
	stdmath_byte4 get_wxwz() { return {self->w,self->x,self->w,self->z}; }
	stdmath_byte4 set_wxwz(stdmath_byte4 value) { self->w = value.x; self->x = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_byte4 wxww;
	stdmath_byte4 get_wxww() { return {self->w,self->x,self->w,self->w}; }
	stdmath_byte4 set_wxww(stdmath_byte4 value) { self->w = value.x; self->x = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_byte4 wyxx;
	stdmath_byte4 get_wyxx() { return {self->w,self->y,self->x,self->x}; }
	stdmath_byte4 set_wyxx(stdmath_byte4 value) { self->w = value.x; self->y = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_byte4 wyxy;
	stdmath_byte4 get_wyxy() { return {self->w,self->y,self->x,self->y}; }
	stdmath_byte4 set_wyxy(stdmath_byte4 value) { self->w = value.x; self->y = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_byte4 wyxz;
	stdmath_byte4 get_wyxz() { return {self->w,self->y,self->x,self->z}; }
	stdmath_byte4 set_wyxz(stdmath_byte4 value) { self->w = value.x; self->y = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_byte4 wyxw;
	stdmath_byte4 get_wyxw() { return {self->w,self->y,self->x,self->w}; }
	stdmath_byte4 set_wyxw(stdmath_byte4 value) { self->w = value.x; self->y = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_byte4 wyyx;
	stdmath_byte4 get_wyyx() { return {self->w,self->y,self->y,self->x}; }
	stdmath_byte4 set_wyyx(stdmath_byte4 value) { self->w = value.x; self->y = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_byte4 wyyy;
	stdmath_byte4 get_wyyy() { return {self->w,self->y,self->y,self->y}; }
	stdmath_byte4 set_wyyy(stdmath_byte4 value) { self->w = value.x; self->y = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_byte4 wyyz;
	stdmath_byte4 get_wyyz() { return {self->w,self->y,self->y,self->z}; }
	stdmath_byte4 set_wyyz(stdmath_byte4 value) { self->w = value.x; self->y = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_byte4 wyyw;
	stdmath_byte4 get_wyyw() { return {self->w,self->y,self->y,self->w}; }
	stdmath_byte4 set_wyyw(stdmath_byte4 value) { self->w = value.x; self->y = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_byte4 wyzx;
	stdmath_byte4 get_wyzx() { return {self->w,self->y,self->z,self->x}; }
	stdmath_byte4 set_wyzx(stdmath_byte4 value) { self->w = value.x; self->y = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_byte4 wyzy;
	stdmath_byte4 get_wyzy() { return {self->w,self->y,self->z,self->y}; }
	stdmath_byte4 set_wyzy(stdmath_byte4 value) { self->w = value.x; self->y = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_byte4 wyzz;
	stdmath_byte4 get_wyzz() { return {self->w,self->y,self->z,self->z}; }
	stdmath_byte4 set_wyzz(stdmath_byte4 value) { self->w = value.x; self->y = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_byte4 wyzw;
	stdmath_byte4 get_wyzw() { return {self->w,self->y,self->z,self->w}; }
	stdmath_byte4 set_wyzw(stdmath_byte4 value) { self->w = value.x; self->y = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_byte4 wywx;
	stdmath_byte4 get_wywx() { return {self->w,self->y,self->w,self->x}; }
	stdmath_byte4 set_wywx(stdmath_byte4 value) { self->w = value.x; self->y = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_byte4 wywy;
	stdmath_byte4 get_wywy() { return {self->w,self->y,self->w,self->y}; }
	stdmath_byte4 set_wywy(stdmath_byte4 value) { self->w = value.x; self->y = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_byte4 wywz;
	stdmath_byte4 get_wywz() { return {self->w,self->y,self->w,self->z}; }
	stdmath_byte4 set_wywz(stdmath_byte4 value) { self->w = value.x; self->y = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_byte4 wyww;
	stdmath_byte4 get_wyww() { return {self->w,self->y,self->w,self->w}; }
	stdmath_byte4 set_wyww(stdmath_byte4 value) { self->w = value.x; self->y = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_byte4 wzxx;
	stdmath_byte4 get_wzxx() { return {self->w,self->z,self->x,self->x}; }
	stdmath_byte4 set_wzxx(stdmath_byte4 value) { self->w = value.x; self->z = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_byte4 wzxy;
	stdmath_byte4 get_wzxy() { return {self->w,self->z,self->x,self->y}; }
	stdmath_byte4 set_wzxy(stdmath_byte4 value) { self->w = value.x; self->z = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_byte4 wzxz;
	stdmath_byte4 get_wzxz() { return {self->w,self->z,self->x,self->z}; }
	stdmath_byte4 set_wzxz(stdmath_byte4 value) { self->w = value.x; self->z = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_byte4 wzxw;
	stdmath_byte4 get_wzxw() { return {self->w,self->z,self->x,self->w}; }
	stdmath_byte4 set_wzxw(stdmath_byte4 value) { self->w = value.x; self->z = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_byte4 wzyx;
	stdmath_byte4 get_wzyx() { return {self->w,self->z,self->y,self->x}; }
	stdmath_byte4 set_wzyx(stdmath_byte4 value) { self->w = value.x; self->z = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_byte4 wzyy;
	stdmath_byte4 get_wzyy() { return {self->w,self->z,self->y,self->y}; }
	stdmath_byte4 set_wzyy(stdmath_byte4 value) { self->w = value.x; self->z = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_byte4 wzyz;
	stdmath_byte4 get_wzyz() { return {self->w,self->z,self->y,self->z}; }
	stdmath_byte4 set_wzyz(stdmath_byte4 value) { self->w = value.x; self->z = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_byte4 wzyw;
	stdmath_byte4 get_wzyw() { return {self->w,self->z,self->y,self->w}; }
	stdmath_byte4 set_wzyw(stdmath_byte4 value) { self->w = value.x; self->z = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_byte4 wzzx;
	stdmath_byte4 get_wzzx() { return {self->w,self->z,self->z,self->x}; }
	stdmath_byte4 set_wzzx(stdmath_byte4 value) { self->w = value.x; self->z = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_byte4 wzzy;
	stdmath_byte4 get_wzzy() { return {self->w,self->z,self->z,self->y}; }
	stdmath_byte4 set_wzzy(stdmath_byte4 value) { self->w = value.x; self->z = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_byte4 wzzz;
	stdmath_byte4 get_wzzz() { return {self->w,self->z,self->z,self->z}; }
	stdmath_byte4 set_wzzz(stdmath_byte4 value) { self->w = value.x; self->z = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_byte4 wzzw;
	stdmath_byte4 get_wzzw() { return {self->w,self->z,self->z,self->w}; }
	stdmath_byte4 set_wzzw(stdmath_byte4 value) { self->w = value.x; self->z = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_byte4 wzwx;
	stdmath_byte4 get_wzwx() { return {self->w,self->z,self->w,self->x}; }
	stdmath_byte4 set_wzwx(stdmath_byte4 value) { self->w = value.x; self->z = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_byte4 wzwy;
	stdmath_byte4 get_wzwy() { return {self->w,self->z,self->w,self->y}; }
	stdmath_byte4 set_wzwy(stdmath_byte4 value) { self->w = value.x; self->z = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_byte4 wzwz;
	stdmath_byte4 get_wzwz() { return {self->w,self->z,self->w,self->z}; }
	stdmath_byte4 set_wzwz(stdmath_byte4 value) { self->w = value.x; self->z = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_byte4 wzww;
	stdmath_byte4 get_wzww() { return {self->w,self->z,self->w,self->w}; }
	stdmath_byte4 set_wzww(stdmath_byte4 value) { self->w = value.x; self->z = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_byte4 wwxx;
	stdmath_byte4 get_wwxx() { return {self->w,self->w,self->x,self->x}; }
	stdmath_byte4 set_wwxx(stdmath_byte4 value) { self->w = value.x; self->w = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_byte4 wwxy;
	stdmath_byte4 get_wwxy() { return {self->w,self->w,self->x,self->y}; }
	stdmath_byte4 set_wwxy(stdmath_byte4 value) { self->w = value.x; self->w = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_byte4 wwxz;
	stdmath_byte4 get_wwxz() { return {self->w,self->w,self->x,self->z}; }
	stdmath_byte4 set_wwxz(stdmath_byte4 value) { self->w = value.x; self->w = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_byte4 wwxw;
	stdmath_byte4 get_wwxw() { return {self->w,self->w,self->x,self->w}; }
	stdmath_byte4 set_wwxw(stdmath_byte4 value) { self->w = value.x; self->w = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_byte4 wwyx;
	stdmath_byte4 get_wwyx() { return {self->w,self->w,self->y,self->x}; }
	stdmath_byte4 set_wwyx(stdmath_byte4 value) { self->w = value.x; self->w = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_byte4 wwyy;
	stdmath_byte4 get_wwyy() { return {self->w,self->w,self->y,self->y}; }
	stdmath_byte4 set_wwyy(stdmath_byte4 value) { self->w = value.x; self->w = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_byte4 wwyz;
	stdmath_byte4 get_wwyz() { return {self->w,self->w,self->y,self->z}; }
	stdmath_byte4 set_wwyz(stdmath_byte4 value) { self->w = value.x; self->w = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_byte4 wwyw;
	stdmath_byte4 get_wwyw() { return {self->w,self->w,self->y,self->w}; }
	stdmath_byte4 set_wwyw(stdmath_byte4 value) { self->w = value.x; self->w = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_byte4 wwzx;
	stdmath_byte4 get_wwzx() { return {self->w,self->w,self->z,self->x}; }
	stdmath_byte4 set_wwzx(stdmath_byte4 value) { self->w = value.x; self->w = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_byte4 wwzy;
	stdmath_byte4 get_wwzy() { return {self->w,self->w,self->z,self->y}; }
	stdmath_byte4 set_wwzy(stdmath_byte4 value) { self->w = value.x; self->w = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_byte4 wwzz;
	stdmath_byte4 get_wwzz() { return {self->w,self->w,self->z,self->z}; }
	stdmath_byte4 set_wwzz(stdmath_byte4 value) { self->w = value.x; self->w = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_byte4 wwzw;
	stdmath_byte4 get_wwzw() { return {self->w,self->w,self->z,self->w}; }
	stdmath_byte4 set_wwzw(stdmath_byte4 value) { self->w = value.x; self->w = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_byte4 wwwx;
	stdmath_byte4 get_wwwx() { return {self->w,self->w,self->w,self->x}; }
	stdmath_byte4 set_wwwx(stdmath_byte4 value) { self->w = value.x; self->w = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_byte4 wwwy;
	stdmath_byte4 get_wwwy() { return {self->w,self->w,self->w,self->y}; }
	stdmath_byte4 set_wwwy(stdmath_byte4 value) { self->w = value.x; self->w = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_byte4 wwwz;
	stdmath_byte4 get_wwwz() { return {self->w,self->w,self->w,self->z}; }
	stdmath_byte4 set_wwwz(stdmath_byte4 value) { self->w = value.x; self->w = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_byte4 wwww;
	stdmath_byte4 get_wwww() { return {self->w,self->w,self->w,self->w}; }
	stdmath_byte4 set_wwww(stdmath_byte4 value) { self->w = value.x; self->w = value.y; self->w = value.z; self->w = value.w; return *self; }



	stdmath_byte4 _add(stdmath_byte4 o) {
		return stdmath_byte4_add(*self, o);
	}
	stdmath_byte4 _subtract(stdmath_byte4 o) {
		return stdmath_byte4_subtract(*self, o);
	}
	stdmath_byte4 _negate() {
		return stdmath_byte4_negate(*self);
	}
	stdmath_byte4 _multiply(stdmath_byte4 o) {
		return stdmath_byte4_multiply(*self, o);
	}
	stdmath_byte4 _divide(stdmath_byte4 o) {
		return stdmath_byte4_divide(*self, o);
	}
	stdmath_byte4 _scale(uint8_t o) {
		return stdmath_byte4_scale(*self, o);
	}

#if false
	stdmath_byte4 _modulus(stdmath_byte4 o) {
		return stdmath_byte4_modulus(*self, o);
	}
	stdmath_byte4 _logical_not() {
		return stdmath_byte4_logical_not(*self);
	}
	stdmath_byte4 _bitwise_not() {
		return stdmath_byte4_bitwise_not(*self);
	}
	stdmath_byte4 _logical_and(stdmath_byte4 o) {
		return stdmath_byte4_logical_and(*self, o);
	}
	stdmath_byte4 _bitwise_and(stdmath_byte4 o) {
		return stdmath_byte4_bitwise_and(*self, o);
	}
	stdmath_byte4 _logical_or(stdmath_byte4 o) {
		return stdmath_byte4_logical_or(*self, o);
	}
	stdmath_byte4 _bitwise_or(stdmath_byte4 o) {
		return stdmath_byte4_bitwise_or(*self, o);
	}
	stdmath_byte4 _bitwise_xor(stdmath_byte4 o) {
		return stdmath_byte4_bitwise_xor(*self, o);
	}
	stdmath_byte4 _shift_left(stdmath_byte4 o) {
		return stdmath_byte4_shift_left(*self, o);
	}
	stdmath_byte4 _shift_right(stdmath_byte4 o) {
		return stdmath_byte4_shift_right(*self, o);
	}
#endif

	bool4 _equal_to(stdmath_byte4 o) {
		return stdmath_byte4_equal_to(*self, o);
	}
	bool4 _not_equal_to(stdmath_byte4 o) {
		return stdmath_byte4_not_equal_to(*self, o);
	}
	bool4 _less_than(stdmath_byte4 o) {
		return stdmath_byte4_less_than(*self, o);
	}
	bool4 _less_than_or_equal_to(stdmath_byte4 o) {
		return stdmath_byte4_less_than_or_equal_to(*self, o);
	}
	bool4 _greater_than(stdmath_byte4 o) {
		return stdmath_byte4_greater_than(*self, o);
	}
	bool4 _greater_than_or_equal_to(stdmath_byte4 o) {
		return stdmath_byte4_greater_than_or_equal_to(*self, o);
	}

	uint8_t _length_squared() {
		return stdmath_byte4_length_squared(*self);
	}
	uint8_t _length() {
		return stdmath_byte4_length(*self);
	}
	uint8_t _dot() {
		return stdmath_byte4_dot(*self);
	}
	uint8_t _min_element() {
		return stdmath_byte4_min_element(*self);
	}
	uint8_t _max_element() {
		return stdmath_byte4_max_element(*self);
	}

	// uint8_t elementwise_transform()
	// uint8_t reduce_element

	stdmath_byte4 _min(stdmath_byte4 o) {
		return stdmath_byte4_min(*self, o);
	}
	stdmath_byte4 _max(stdmath_byte4 o) {
		return stdmath_byte4_max(*self, o);
	}
	stdmath_byte4 _normalize() {
		return stdmath_byte4_normalize(*self);
	}
	stdmath_byte4 _lerp(stdmath_byte4 o, byte t) {
		return stdmath_byte4_lerp(*self, o, t);
	}
	stdmath_byte4 _clamp(stdmath_byte4 min, stdmath_byte4 max) {
		return stdmath_byte4_clamp(*self, min, max);
	}
	stdmath_byte4 _reflect(stdmath_byte4 n) {
		return stdmath_byte4_reflect(*self, n);
	}
	bool4 _approximately_equal(stdmath_byte4 o) {
		return stdmath_byte4_approximately_equal()
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

	uint8_t _get_element(size_t i) {
		return self->data[i];
	}

	uint8_t _set_element(size_t i, uint8_t value) {
		return self->data[i] = value;
	}
}
