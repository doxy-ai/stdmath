%rename(uint4) stdmath_uint4;
%include "uint4.h"

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

%extend stdmath_uint4 {
	stdmath_uint4(uint32_t broadcast) {
		stdmath_uint4 *v;
		v = (stdmath_uint4 *) malloc(sizeof(stdmath_uint4));
		*v = stdmath_uint4_broadcast(broadcast);
		return v;
	}

#if 4 == 4
	stdmath_uint4(uint32_t x = 0, uint32_t y = 0, uint32_t z = 0, uint32_t w = 0) {
		stdmath_uint4 *v;
		v = (stdmath_uint4 *) malloc(sizeof(stdmath_uint4));
		v->x = x;
		v->y = y;
		v->z = z;
		v->w = w;
		return v;
	}
#elif 4 == 3
	stdmath_uint4(uint32_t x = 0, uint32_t y = 0, uint32_t z = 0) {
		stdmath_uint4 *v;
		v = (stdmath_uint4 *) malloc(sizeof(stdmath_uint4));
		v->x = x;
		v->y = y;
		v->z = z;
		return v;
	}
#elif 4 == 2
	stdmath_uint4(uint32_t x = 0, uint32_t y = 0) {
		stdmath_uint4 *v;
		v = (stdmath_uint4 *) malloc(sizeof(stdmath_uint4));
		v->x = x;
		v->y = y;
		return v;
	}
#elif 4 == 1
	stdmath_uint4(uint32_t x = 0) {
		stdmath_uint4 *v;
		v = (stdmath_uint4 *) malloc(sizeof(stdmath_uint4));
		v->x = x;
		return v;
	}
#endif

	stdmath_uint2 xx;
	stdmath_uint2 get_xx() { return {self->x,self->x}; }
	stdmath_uint4 set_xx(stdmath_uint2 value) { self->x = value.x; self->x = value.y; return *self; }

	stdmath_uint2 xy;
	stdmath_uint2 get_xy() { return {self->x,self->y}; }
	stdmath_uint4 set_xy(stdmath_uint2 value) { self->x = value.x; self->y = value.y; return *self; }

	stdmath_uint2 xz;
	stdmath_uint2 get_xz() { return {self->x,self->z}; }
	stdmath_uint4 set_xz(stdmath_uint2 value) { self->x = value.x; self->z = value.y; return *self; }

	stdmath_uint2 xw;
	stdmath_uint2 get_xw() { return {self->x,self->w}; }
	stdmath_uint4 set_xw(stdmath_uint2 value) { self->x = value.x; self->w = value.y; return *self; }

	stdmath_uint2 yx;
	stdmath_uint2 get_yx() { return {self->y,self->x}; }
	stdmath_uint4 set_yx(stdmath_uint2 value) { self->y = value.x; self->x = value.y; return *self; }

	stdmath_uint2 yy;
	stdmath_uint2 get_yy() { return {self->y,self->y}; }
	stdmath_uint4 set_yy(stdmath_uint2 value) { self->y = value.x; self->y = value.y; return *self; }

	stdmath_uint2 yz;
	stdmath_uint2 get_yz() { return {self->y,self->z}; }
	stdmath_uint4 set_yz(stdmath_uint2 value) { self->y = value.x; self->z = value.y; return *self; }

	stdmath_uint2 yw;
	stdmath_uint2 get_yw() { return {self->y,self->w}; }
	stdmath_uint4 set_yw(stdmath_uint2 value) { self->y = value.x; self->w = value.y; return *self; }

	stdmath_uint2 zx;
	stdmath_uint2 get_zx() { return {self->z,self->x}; }
	stdmath_uint4 set_zx(stdmath_uint2 value) { self->z = value.x; self->x = value.y; return *self; }

	stdmath_uint2 zy;
	stdmath_uint2 get_zy() { return {self->z,self->y}; }
	stdmath_uint4 set_zy(stdmath_uint2 value) { self->z = value.x; self->y = value.y; return *self; }

	stdmath_uint2 zz;
	stdmath_uint2 get_zz() { return {self->z,self->z}; }
	stdmath_uint4 set_zz(stdmath_uint2 value) { self->z = value.x; self->z = value.y; return *self; }

	stdmath_uint2 zw;
	stdmath_uint2 get_zw() { return {self->z,self->w}; }
	stdmath_uint4 set_zw(stdmath_uint2 value) { self->z = value.x; self->w = value.y; return *self; }

	stdmath_uint2 wx;
	stdmath_uint2 get_wx() { return {self->w,self->x}; }
	stdmath_uint4 set_wx(stdmath_uint2 value) { self->w = value.x; self->x = value.y; return *self; }

	stdmath_uint2 wy;
	stdmath_uint2 get_wy() { return {self->w,self->y}; }
	stdmath_uint4 set_wy(stdmath_uint2 value) { self->w = value.x; self->y = value.y; return *self; }

	stdmath_uint2 wz;
	stdmath_uint2 get_wz() { return {self->w,self->z}; }
	stdmath_uint4 set_wz(stdmath_uint2 value) { self->w = value.x; self->z = value.y; return *self; }

	stdmath_uint2 ww;
	stdmath_uint2 get_ww() { return {self->w,self->w}; }
	stdmath_uint4 set_ww(stdmath_uint2 value) { self->w = value.x; self->w = value.y; return *self; }

	stdmath_uint3 xxx;
	stdmath_uint3 get_xxx() { return {self->x,self->x,self->x}; }
	stdmath_uint4 set_xxx(stdmath_uint3 value) { self->x = value.x; self->x = value.y; self->x = value.z; return *self; }

	stdmath_uint3 xxy;
	stdmath_uint3 get_xxy() { return {self->x,self->x,self->y}; }
	stdmath_uint4 set_xxy(stdmath_uint3 value) { self->x = value.x; self->x = value.y; self->y = value.z; return *self; }

	stdmath_uint3 xxz;
	stdmath_uint3 get_xxz() { return {self->x,self->x,self->z}; }
	stdmath_uint4 set_xxz(stdmath_uint3 value) { self->x = value.x; self->x = value.y; self->z = value.z; return *self; }

	stdmath_uint3 xxw;
	stdmath_uint3 get_xxw() { return {self->x,self->x,self->w}; }
	stdmath_uint4 set_xxw(stdmath_uint3 value) { self->x = value.x; self->x = value.y; self->w = value.z; return *self; }

	stdmath_uint3 xyx;
	stdmath_uint3 get_xyx() { return {self->x,self->y,self->x}; }
	stdmath_uint4 set_xyx(stdmath_uint3 value) { self->x = value.x; self->y = value.y; self->x = value.z; return *self; }

	stdmath_uint3 xyy;
	stdmath_uint3 get_xyy() { return {self->x,self->y,self->y}; }
	stdmath_uint4 set_xyy(stdmath_uint3 value) { self->x = value.x; self->y = value.y; self->y = value.z; return *self; }

	stdmath_uint3 xyz;
	stdmath_uint3 get_xyz() { return {self->x,self->y,self->z}; }
	stdmath_uint4 set_xyz(stdmath_uint3 value) { self->x = value.x; self->y = value.y; self->z = value.z; return *self; }

	stdmath_uint3 xyw;
	stdmath_uint3 get_xyw() { return {self->x,self->y,self->w}; }
	stdmath_uint4 set_xyw(stdmath_uint3 value) { self->x = value.x; self->y = value.y; self->w = value.z; return *self; }

	stdmath_uint3 xzx;
	stdmath_uint3 get_xzx() { return {self->x,self->z,self->x}; }
	stdmath_uint4 set_xzx(stdmath_uint3 value) { self->x = value.x; self->z = value.y; self->x = value.z; return *self; }

	stdmath_uint3 xzy;
	stdmath_uint3 get_xzy() { return {self->x,self->z,self->y}; }
	stdmath_uint4 set_xzy(stdmath_uint3 value) { self->x = value.x; self->z = value.y; self->y = value.z; return *self; }

	stdmath_uint3 xzz;
	stdmath_uint3 get_xzz() { return {self->x,self->z,self->z}; }
	stdmath_uint4 set_xzz(stdmath_uint3 value) { self->x = value.x; self->z = value.y; self->z = value.z; return *self; }

	stdmath_uint3 xzw;
	stdmath_uint3 get_xzw() { return {self->x,self->z,self->w}; }
	stdmath_uint4 set_xzw(stdmath_uint3 value) { self->x = value.x; self->z = value.y; self->w = value.z; return *self; }

	stdmath_uint3 xwx;
	stdmath_uint3 get_xwx() { return {self->x,self->w,self->x}; }
	stdmath_uint4 set_xwx(stdmath_uint3 value) { self->x = value.x; self->w = value.y; self->x = value.z; return *self; }

	stdmath_uint3 xwy;
	stdmath_uint3 get_xwy() { return {self->x,self->w,self->y}; }
	stdmath_uint4 set_xwy(stdmath_uint3 value) { self->x = value.x; self->w = value.y; self->y = value.z; return *self; }

	stdmath_uint3 xwz;
	stdmath_uint3 get_xwz() { return {self->x,self->w,self->z}; }
	stdmath_uint4 set_xwz(stdmath_uint3 value) { self->x = value.x; self->w = value.y; self->z = value.z; return *self; }

	stdmath_uint3 xww;
	stdmath_uint3 get_xww() { return {self->x,self->w,self->w}; }
	stdmath_uint4 set_xww(stdmath_uint3 value) { self->x = value.x; self->w = value.y; self->w = value.z; return *self; }

	stdmath_uint3 yxx;
	stdmath_uint3 get_yxx() { return {self->y,self->x,self->x}; }
	stdmath_uint4 set_yxx(stdmath_uint3 value) { self->y = value.x; self->x = value.y; self->x = value.z; return *self; }

	stdmath_uint3 yxy;
	stdmath_uint3 get_yxy() { return {self->y,self->x,self->y}; }
	stdmath_uint4 set_yxy(stdmath_uint3 value) { self->y = value.x; self->x = value.y; self->y = value.z; return *self; }

	stdmath_uint3 yxz;
	stdmath_uint3 get_yxz() { return {self->y,self->x,self->z}; }
	stdmath_uint4 set_yxz(stdmath_uint3 value) { self->y = value.x; self->x = value.y; self->z = value.z; return *self; }

	stdmath_uint3 yxw;
	stdmath_uint3 get_yxw() { return {self->y,self->x,self->w}; }
	stdmath_uint4 set_yxw(stdmath_uint3 value) { self->y = value.x; self->x = value.y; self->w = value.z; return *self; }

	stdmath_uint3 yyx;
	stdmath_uint3 get_yyx() { return {self->y,self->y,self->x}; }
	stdmath_uint4 set_yyx(stdmath_uint3 value) { self->y = value.x; self->y = value.y; self->x = value.z; return *self; }

	stdmath_uint3 yyy;
	stdmath_uint3 get_yyy() { return {self->y,self->y,self->y}; }
	stdmath_uint4 set_yyy(stdmath_uint3 value) { self->y = value.x; self->y = value.y; self->y = value.z; return *self; }

	stdmath_uint3 yyz;
	stdmath_uint3 get_yyz() { return {self->y,self->y,self->z}; }
	stdmath_uint4 set_yyz(stdmath_uint3 value) { self->y = value.x; self->y = value.y; self->z = value.z; return *self; }

	stdmath_uint3 yyw;
	stdmath_uint3 get_yyw() { return {self->y,self->y,self->w}; }
	stdmath_uint4 set_yyw(stdmath_uint3 value) { self->y = value.x; self->y = value.y; self->w = value.z; return *self; }

	stdmath_uint3 yzx;
	stdmath_uint3 get_yzx() { return {self->y,self->z,self->x}; }
	stdmath_uint4 set_yzx(stdmath_uint3 value) { self->y = value.x; self->z = value.y; self->x = value.z; return *self; }

	stdmath_uint3 yzy;
	stdmath_uint3 get_yzy() { return {self->y,self->z,self->y}; }
	stdmath_uint4 set_yzy(stdmath_uint3 value) { self->y = value.x; self->z = value.y; self->y = value.z; return *self; }

	stdmath_uint3 yzz;
	stdmath_uint3 get_yzz() { return {self->y,self->z,self->z}; }
	stdmath_uint4 set_yzz(stdmath_uint3 value) { self->y = value.x; self->z = value.y; self->z = value.z; return *self; }

	stdmath_uint3 yzw;
	stdmath_uint3 get_yzw() { return {self->y,self->z,self->w}; }
	stdmath_uint4 set_yzw(stdmath_uint3 value) { self->y = value.x; self->z = value.y; self->w = value.z; return *self; }

	stdmath_uint3 ywx;
	stdmath_uint3 get_ywx() { return {self->y,self->w,self->x}; }
	stdmath_uint4 set_ywx(stdmath_uint3 value) { self->y = value.x; self->w = value.y; self->x = value.z; return *self; }

	stdmath_uint3 ywy;
	stdmath_uint3 get_ywy() { return {self->y,self->w,self->y}; }
	stdmath_uint4 set_ywy(stdmath_uint3 value) { self->y = value.x; self->w = value.y; self->y = value.z; return *self; }

	stdmath_uint3 ywz;
	stdmath_uint3 get_ywz() { return {self->y,self->w,self->z}; }
	stdmath_uint4 set_ywz(stdmath_uint3 value) { self->y = value.x; self->w = value.y; self->z = value.z; return *self; }

	stdmath_uint3 yww;
	stdmath_uint3 get_yww() { return {self->y,self->w,self->w}; }
	stdmath_uint4 set_yww(stdmath_uint3 value) { self->y = value.x; self->w = value.y; self->w = value.z; return *self; }

	stdmath_uint3 zxx;
	stdmath_uint3 get_zxx() { return {self->z,self->x,self->x}; }
	stdmath_uint4 set_zxx(stdmath_uint3 value) { self->z = value.x; self->x = value.y; self->x = value.z; return *self; }

	stdmath_uint3 zxy;
	stdmath_uint3 get_zxy() { return {self->z,self->x,self->y}; }
	stdmath_uint4 set_zxy(stdmath_uint3 value) { self->z = value.x; self->x = value.y; self->y = value.z; return *self; }

	stdmath_uint3 zxz;
	stdmath_uint3 get_zxz() { return {self->z,self->x,self->z}; }
	stdmath_uint4 set_zxz(stdmath_uint3 value) { self->z = value.x; self->x = value.y; self->z = value.z; return *self; }

	stdmath_uint3 zxw;
	stdmath_uint3 get_zxw() { return {self->z,self->x,self->w}; }
	stdmath_uint4 set_zxw(stdmath_uint3 value) { self->z = value.x; self->x = value.y; self->w = value.z; return *self; }

	stdmath_uint3 zyx;
	stdmath_uint3 get_zyx() { return {self->z,self->y,self->x}; }
	stdmath_uint4 set_zyx(stdmath_uint3 value) { self->z = value.x; self->y = value.y; self->x = value.z; return *self; }

	stdmath_uint3 zyy;
	stdmath_uint3 get_zyy() { return {self->z,self->y,self->y}; }
	stdmath_uint4 set_zyy(stdmath_uint3 value) { self->z = value.x; self->y = value.y; self->y = value.z; return *self; }

	stdmath_uint3 zyz;
	stdmath_uint3 get_zyz() { return {self->z,self->y,self->z}; }
	stdmath_uint4 set_zyz(stdmath_uint3 value) { self->z = value.x; self->y = value.y; self->z = value.z; return *self; }

	stdmath_uint3 zyw;
	stdmath_uint3 get_zyw() { return {self->z,self->y,self->w}; }
	stdmath_uint4 set_zyw(stdmath_uint3 value) { self->z = value.x; self->y = value.y; self->w = value.z; return *self; }

	stdmath_uint3 zzx;
	stdmath_uint3 get_zzx() { return {self->z,self->z,self->x}; }
	stdmath_uint4 set_zzx(stdmath_uint3 value) { self->z = value.x; self->z = value.y; self->x = value.z; return *self; }

	stdmath_uint3 zzy;
	stdmath_uint3 get_zzy() { return {self->z,self->z,self->y}; }
	stdmath_uint4 set_zzy(stdmath_uint3 value) { self->z = value.x; self->z = value.y; self->y = value.z; return *self; }

	stdmath_uint3 zzz;
	stdmath_uint3 get_zzz() { return {self->z,self->z,self->z}; }
	stdmath_uint4 set_zzz(stdmath_uint3 value) { self->z = value.x; self->z = value.y; self->z = value.z; return *self; }

	stdmath_uint3 zzw;
	stdmath_uint3 get_zzw() { return {self->z,self->z,self->w}; }
	stdmath_uint4 set_zzw(stdmath_uint3 value) { self->z = value.x; self->z = value.y; self->w = value.z; return *self; }

	stdmath_uint3 zwx;
	stdmath_uint3 get_zwx() { return {self->z,self->w,self->x}; }
	stdmath_uint4 set_zwx(stdmath_uint3 value) { self->z = value.x; self->w = value.y; self->x = value.z; return *self; }

	stdmath_uint3 zwy;
	stdmath_uint3 get_zwy() { return {self->z,self->w,self->y}; }
	stdmath_uint4 set_zwy(stdmath_uint3 value) { self->z = value.x; self->w = value.y; self->y = value.z; return *self; }

	stdmath_uint3 zwz;
	stdmath_uint3 get_zwz() { return {self->z,self->w,self->z}; }
	stdmath_uint4 set_zwz(stdmath_uint3 value) { self->z = value.x; self->w = value.y; self->z = value.z; return *self; }

	stdmath_uint3 zww;
	stdmath_uint3 get_zww() { return {self->z,self->w,self->w}; }
	stdmath_uint4 set_zww(stdmath_uint3 value) { self->z = value.x; self->w = value.y; self->w = value.z; return *self; }

	stdmath_uint3 wxx;
	stdmath_uint3 get_wxx() { return {self->w,self->x,self->x}; }
	stdmath_uint4 set_wxx(stdmath_uint3 value) { self->w = value.x; self->x = value.y; self->x = value.z; return *self; }

	stdmath_uint3 wxy;
	stdmath_uint3 get_wxy() { return {self->w,self->x,self->y}; }
	stdmath_uint4 set_wxy(stdmath_uint3 value) { self->w = value.x; self->x = value.y; self->y = value.z; return *self; }

	stdmath_uint3 wxz;
	stdmath_uint3 get_wxz() { return {self->w,self->x,self->z}; }
	stdmath_uint4 set_wxz(stdmath_uint3 value) { self->w = value.x; self->x = value.y; self->z = value.z; return *self; }

	stdmath_uint3 wxw;
	stdmath_uint3 get_wxw() { return {self->w,self->x,self->w}; }
	stdmath_uint4 set_wxw(stdmath_uint3 value) { self->w = value.x; self->x = value.y; self->w = value.z; return *self; }

	stdmath_uint3 wyx;
	stdmath_uint3 get_wyx() { return {self->w,self->y,self->x}; }
	stdmath_uint4 set_wyx(stdmath_uint3 value) { self->w = value.x; self->y = value.y; self->x = value.z; return *self; }

	stdmath_uint3 wyy;
	stdmath_uint3 get_wyy() { return {self->w,self->y,self->y}; }
	stdmath_uint4 set_wyy(stdmath_uint3 value) { self->w = value.x; self->y = value.y; self->y = value.z; return *self; }

	stdmath_uint3 wyz;
	stdmath_uint3 get_wyz() { return {self->w,self->y,self->z}; }
	stdmath_uint4 set_wyz(stdmath_uint3 value) { self->w = value.x; self->y = value.y; self->z = value.z; return *self; }

	stdmath_uint3 wyw;
	stdmath_uint3 get_wyw() { return {self->w,self->y,self->w}; }
	stdmath_uint4 set_wyw(stdmath_uint3 value) { self->w = value.x; self->y = value.y; self->w = value.z; return *self; }

	stdmath_uint3 wzx;
	stdmath_uint3 get_wzx() { return {self->w,self->z,self->x}; }
	stdmath_uint4 set_wzx(stdmath_uint3 value) { self->w = value.x; self->z = value.y; self->x = value.z; return *self; }

	stdmath_uint3 wzy;
	stdmath_uint3 get_wzy() { return {self->w,self->z,self->y}; }
	stdmath_uint4 set_wzy(stdmath_uint3 value) { self->w = value.x; self->z = value.y; self->y = value.z; return *self; }

	stdmath_uint3 wzz;
	stdmath_uint3 get_wzz() { return {self->w,self->z,self->z}; }
	stdmath_uint4 set_wzz(stdmath_uint3 value) { self->w = value.x; self->z = value.y; self->z = value.z; return *self; }

	stdmath_uint3 wzw;
	stdmath_uint3 get_wzw() { return {self->w,self->z,self->w}; }
	stdmath_uint4 set_wzw(stdmath_uint3 value) { self->w = value.x; self->z = value.y; self->w = value.z; return *self; }

	stdmath_uint3 wwx;
	stdmath_uint3 get_wwx() { return {self->w,self->w,self->x}; }
	stdmath_uint4 set_wwx(stdmath_uint3 value) { self->w = value.x; self->w = value.y; self->x = value.z; return *self; }

	stdmath_uint3 wwy;
	stdmath_uint3 get_wwy() { return {self->w,self->w,self->y}; }
	stdmath_uint4 set_wwy(stdmath_uint3 value) { self->w = value.x; self->w = value.y; self->y = value.z; return *self; }

	stdmath_uint3 wwz;
	stdmath_uint3 get_wwz() { return {self->w,self->w,self->z}; }
	stdmath_uint4 set_wwz(stdmath_uint3 value) { self->w = value.x; self->w = value.y; self->z = value.z; return *self; }

	stdmath_uint3 www;
	stdmath_uint3 get_www() { return {self->w,self->w,self->w}; }
	stdmath_uint4 set_www(stdmath_uint3 value) { self->w = value.x; self->w = value.y; self->w = value.z; return *self; }

	stdmath_uint4 xxxx;
	stdmath_uint4 get_xxxx() { return {self->x,self->x,self->x,self->x}; }
	stdmath_uint4 set_xxxx(stdmath_uint4 value) { self->x = value.x; self->x = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_uint4 xxxy;
	stdmath_uint4 get_xxxy() { return {self->x,self->x,self->x,self->y}; }
	stdmath_uint4 set_xxxy(stdmath_uint4 value) { self->x = value.x; self->x = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_uint4 xxxz;
	stdmath_uint4 get_xxxz() { return {self->x,self->x,self->x,self->z}; }
	stdmath_uint4 set_xxxz(stdmath_uint4 value) { self->x = value.x; self->x = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_uint4 xxxw;
	stdmath_uint4 get_xxxw() { return {self->x,self->x,self->x,self->w}; }
	stdmath_uint4 set_xxxw(stdmath_uint4 value) { self->x = value.x; self->x = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_uint4 xxyx;
	stdmath_uint4 get_xxyx() { return {self->x,self->x,self->y,self->x}; }
	stdmath_uint4 set_xxyx(stdmath_uint4 value) { self->x = value.x; self->x = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_uint4 xxyy;
	stdmath_uint4 get_xxyy() { return {self->x,self->x,self->y,self->y}; }
	stdmath_uint4 set_xxyy(stdmath_uint4 value) { self->x = value.x; self->x = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_uint4 xxyz;
	stdmath_uint4 get_xxyz() { return {self->x,self->x,self->y,self->z}; }
	stdmath_uint4 set_xxyz(stdmath_uint4 value) { self->x = value.x; self->x = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_uint4 xxyw;
	stdmath_uint4 get_xxyw() { return {self->x,self->x,self->y,self->w}; }
	stdmath_uint4 set_xxyw(stdmath_uint4 value) { self->x = value.x; self->x = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_uint4 xxzx;
	stdmath_uint4 get_xxzx() { return {self->x,self->x,self->z,self->x}; }
	stdmath_uint4 set_xxzx(stdmath_uint4 value) { self->x = value.x; self->x = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_uint4 xxzy;
	stdmath_uint4 get_xxzy() { return {self->x,self->x,self->z,self->y}; }
	stdmath_uint4 set_xxzy(stdmath_uint4 value) { self->x = value.x; self->x = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_uint4 xxzz;
	stdmath_uint4 get_xxzz() { return {self->x,self->x,self->z,self->z}; }
	stdmath_uint4 set_xxzz(stdmath_uint4 value) { self->x = value.x; self->x = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_uint4 xxzw;
	stdmath_uint4 get_xxzw() { return {self->x,self->x,self->z,self->w}; }
	stdmath_uint4 set_xxzw(stdmath_uint4 value) { self->x = value.x; self->x = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_uint4 xxwx;
	stdmath_uint4 get_xxwx() { return {self->x,self->x,self->w,self->x}; }
	stdmath_uint4 set_xxwx(stdmath_uint4 value) { self->x = value.x; self->x = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_uint4 xxwy;
	stdmath_uint4 get_xxwy() { return {self->x,self->x,self->w,self->y}; }
	stdmath_uint4 set_xxwy(stdmath_uint4 value) { self->x = value.x; self->x = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_uint4 xxwz;
	stdmath_uint4 get_xxwz() { return {self->x,self->x,self->w,self->z}; }
	stdmath_uint4 set_xxwz(stdmath_uint4 value) { self->x = value.x; self->x = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_uint4 xxww;
	stdmath_uint4 get_xxww() { return {self->x,self->x,self->w,self->w}; }
	stdmath_uint4 set_xxww(stdmath_uint4 value) { self->x = value.x; self->x = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_uint4 xyxx;
	stdmath_uint4 get_xyxx() { return {self->x,self->y,self->x,self->x}; }
	stdmath_uint4 set_xyxx(stdmath_uint4 value) { self->x = value.x; self->y = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_uint4 xyxy;
	stdmath_uint4 get_xyxy() { return {self->x,self->y,self->x,self->y}; }
	stdmath_uint4 set_xyxy(stdmath_uint4 value) { self->x = value.x; self->y = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_uint4 xyxz;
	stdmath_uint4 get_xyxz() { return {self->x,self->y,self->x,self->z}; }
	stdmath_uint4 set_xyxz(stdmath_uint4 value) { self->x = value.x; self->y = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_uint4 xyxw;
	stdmath_uint4 get_xyxw() { return {self->x,self->y,self->x,self->w}; }
	stdmath_uint4 set_xyxw(stdmath_uint4 value) { self->x = value.x; self->y = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_uint4 xyyx;
	stdmath_uint4 get_xyyx() { return {self->x,self->y,self->y,self->x}; }
	stdmath_uint4 set_xyyx(stdmath_uint4 value) { self->x = value.x; self->y = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_uint4 xyyy;
	stdmath_uint4 get_xyyy() { return {self->x,self->y,self->y,self->y}; }
	stdmath_uint4 set_xyyy(stdmath_uint4 value) { self->x = value.x; self->y = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_uint4 xyyz;
	stdmath_uint4 get_xyyz() { return {self->x,self->y,self->y,self->z}; }
	stdmath_uint4 set_xyyz(stdmath_uint4 value) { self->x = value.x; self->y = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_uint4 xyyw;
	stdmath_uint4 get_xyyw() { return {self->x,self->y,self->y,self->w}; }
	stdmath_uint4 set_xyyw(stdmath_uint4 value) { self->x = value.x; self->y = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_uint4 xyzx;
	stdmath_uint4 get_xyzx() { return {self->x,self->y,self->z,self->x}; }
	stdmath_uint4 set_xyzx(stdmath_uint4 value) { self->x = value.x; self->y = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_uint4 xyzy;
	stdmath_uint4 get_xyzy() { return {self->x,self->y,self->z,self->y}; }
	stdmath_uint4 set_xyzy(stdmath_uint4 value) { self->x = value.x; self->y = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_uint4 xyzz;
	stdmath_uint4 get_xyzz() { return {self->x,self->y,self->z,self->z}; }
	stdmath_uint4 set_xyzz(stdmath_uint4 value) { self->x = value.x; self->y = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_uint4 xyzw;
	stdmath_uint4 get_xyzw() { return {self->x,self->y,self->z,self->w}; }
	stdmath_uint4 set_xyzw(stdmath_uint4 value) { self->x = value.x; self->y = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_uint4 xywx;
	stdmath_uint4 get_xywx() { return {self->x,self->y,self->w,self->x}; }
	stdmath_uint4 set_xywx(stdmath_uint4 value) { self->x = value.x; self->y = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_uint4 xywy;
	stdmath_uint4 get_xywy() { return {self->x,self->y,self->w,self->y}; }
	stdmath_uint4 set_xywy(stdmath_uint4 value) { self->x = value.x; self->y = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_uint4 xywz;
	stdmath_uint4 get_xywz() { return {self->x,self->y,self->w,self->z}; }
	stdmath_uint4 set_xywz(stdmath_uint4 value) { self->x = value.x; self->y = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_uint4 xyww;
	stdmath_uint4 get_xyww() { return {self->x,self->y,self->w,self->w}; }
	stdmath_uint4 set_xyww(stdmath_uint4 value) { self->x = value.x; self->y = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_uint4 xzxx;
	stdmath_uint4 get_xzxx() { return {self->x,self->z,self->x,self->x}; }
	stdmath_uint4 set_xzxx(stdmath_uint4 value) { self->x = value.x; self->z = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_uint4 xzxy;
	stdmath_uint4 get_xzxy() { return {self->x,self->z,self->x,self->y}; }
	stdmath_uint4 set_xzxy(stdmath_uint4 value) { self->x = value.x; self->z = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_uint4 xzxz;
	stdmath_uint4 get_xzxz() { return {self->x,self->z,self->x,self->z}; }
	stdmath_uint4 set_xzxz(stdmath_uint4 value) { self->x = value.x; self->z = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_uint4 xzxw;
	stdmath_uint4 get_xzxw() { return {self->x,self->z,self->x,self->w}; }
	stdmath_uint4 set_xzxw(stdmath_uint4 value) { self->x = value.x; self->z = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_uint4 xzyx;
	stdmath_uint4 get_xzyx() { return {self->x,self->z,self->y,self->x}; }
	stdmath_uint4 set_xzyx(stdmath_uint4 value) { self->x = value.x; self->z = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_uint4 xzyy;
	stdmath_uint4 get_xzyy() { return {self->x,self->z,self->y,self->y}; }
	stdmath_uint4 set_xzyy(stdmath_uint4 value) { self->x = value.x; self->z = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_uint4 xzyz;
	stdmath_uint4 get_xzyz() { return {self->x,self->z,self->y,self->z}; }
	stdmath_uint4 set_xzyz(stdmath_uint4 value) { self->x = value.x; self->z = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_uint4 xzyw;
	stdmath_uint4 get_xzyw() { return {self->x,self->z,self->y,self->w}; }
	stdmath_uint4 set_xzyw(stdmath_uint4 value) { self->x = value.x; self->z = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_uint4 xzzx;
	stdmath_uint4 get_xzzx() { return {self->x,self->z,self->z,self->x}; }
	stdmath_uint4 set_xzzx(stdmath_uint4 value) { self->x = value.x; self->z = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_uint4 xzzy;
	stdmath_uint4 get_xzzy() { return {self->x,self->z,self->z,self->y}; }
	stdmath_uint4 set_xzzy(stdmath_uint4 value) { self->x = value.x; self->z = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_uint4 xzzz;
	stdmath_uint4 get_xzzz() { return {self->x,self->z,self->z,self->z}; }
	stdmath_uint4 set_xzzz(stdmath_uint4 value) { self->x = value.x; self->z = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_uint4 xzzw;
	stdmath_uint4 get_xzzw() { return {self->x,self->z,self->z,self->w}; }
	stdmath_uint4 set_xzzw(stdmath_uint4 value) { self->x = value.x; self->z = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_uint4 xzwx;
	stdmath_uint4 get_xzwx() { return {self->x,self->z,self->w,self->x}; }
	stdmath_uint4 set_xzwx(stdmath_uint4 value) { self->x = value.x; self->z = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_uint4 xzwy;
	stdmath_uint4 get_xzwy() { return {self->x,self->z,self->w,self->y}; }
	stdmath_uint4 set_xzwy(stdmath_uint4 value) { self->x = value.x; self->z = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_uint4 xzwz;
	stdmath_uint4 get_xzwz() { return {self->x,self->z,self->w,self->z}; }
	stdmath_uint4 set_xzwz(stdmath_uint4 value) { self->x = value.x; self->z = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_uint4 xzww;
	stdmath_uint4 get_xzww() { return {self->x,self->z,self->w,self->w}; }
	stdmath_uint4 set_xzww(stdmath_uint4 value) { self->x = value.x; self->z = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_uint4 xwxx;
	stdmath_uint4 get_xwxx() { return {self->x,self->w,self->x,self->x}; }
	stdmath_uint4 set_xwxx(stdmath_uint4 value) { self->x = value.x; self->w = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_uint4 xwxy;
	stdmath_uint4 get_xwxy() { return {self->x,self->w,self->x,self->y}; }
	stdmath_uint4 set_xwxy(stdmath_uint4 value) { self->x = value.x; self->w = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_uint4 xwxz;
	stdmath_uint4 get_xwxz() { return {self->x,self->w,self->x,self->z}; }
	stdmath_uint4 set_xwxz(stdmath_uint4 value) { self->x = value.x; self->w = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_uint4 xwxw;
	stdmath_uint4 get_xwxw() { return {self->x,self->w,self->x,self->w}; }
	stdmath_uint4 set_xwxw(stdmath_uint4 value) { self->x = value.x; self->w = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_uint4 xwyx;
	stdmath_uint4 get_xwyx() { return {self->x,self->w,self->y,self->x}; }
	stdmath_uint4 set_xwyx(stdmath_uint4 value) { self->x = value.x; self->w = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_uint4 xwyy;
	stdmath_uint4 get_xwyy() { return {self->x,self->w,self->y,self->y}; }
	stdmath_uint4 set_xwyy(stdmath_uint4 value) { self->x = value.x; self->w = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_uint4 xwyz;
	stdmath_uint4 get_xwyz() { return {self->x,self->w,self->y,self->z}; }
	stdmath_uint4 set_xwyz(stdmath_uint4 value) { self->x = value.x; self->w = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_uint4 xwyw;
	stdmath_uint4 get_xwyw() { return {self->x,self->w,self->y,self->w}; }
	stdmath_uint4 set_xwyw(stdmath_uint4 value) { self->x = value.x; self->w = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_uint4 xwzx;
	stdmath_uint4 get_xwzx() { return {self->x,self->w,self->z,self->x}; }
	stdmath_uint4 set_xwzx(stdmath_uint4 value) { self->x = value.x; self->w = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_uint4 xwzy;
	stdmath_uint4 get_xwzy() { return {self->x,self->w,self->z,self->y}; }
	stdmath_uint4 set_xwzy(stdmath_uint4 value) { self->x = value.x; self->w = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_uint4 xwzz;
	stdmath_uint4 get_xwzz() { return {self->x,self->w,self->z,self->z}; }
	stdmath_uint4 set_xwzz(stdmath_uint4 value) { self->x = value.x; self->w = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_uint4 xwzw;
	stdmath_uint4 get_xwzw() { return {self->x,self->w,self->z,self->w}; }
	stdmath_uint4 set_xwzw(stdmath_uint4 value) { self->x = value.x; self->w = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_uint4 xwwx;
	stdmath_uint4 get_xwwx() { return {self->x,self->w,self->w,self->x}; }
	stdmath_uint4 set_xwwx(stdmath_uint4 value) { self->x = value.x; self->w = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_uint4 xwwy;
	stdmath_uint4 get_xwwy() { return {self->x,self->w,self->w,self->y}; }
	stdmath_uint4 set_xwwy(stdmath_uint4 value) { self->x = value.x; self->w = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_uint4 xwwz;
	stdmath_uint4 get_xwwz() { return {self->x,self->w,self->w,self->z}; }
	stdmath_uint4 set_xwwz(stdmath_uint4 value) { self->x = value.x; self->w = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_uint4 xwww;
	stdmath_uint4 get_xwww() { return {self->x,self->w,self->w,self->w}; }
	stdmath_uint4 set_xwww(stdmath_uint4 value) { self->x = value.x; self->w = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_uint4 yxxx;
	stdmath_uint4 get_yxxx() { return {self->y,self->x,self->x,self->x}; }
	stdmath_uint4 set_yxxx(stdmath_uint4 value) { self->y = value.x; self->x = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_uint4 yxxy;
	stdmath_uint4 get_yxxy() { return {self->y,self->x,self->x,self->y}; }
	stdmath_uint4 set_yxxy(stdmath_uint4 value) { self->y = value.x; self->x = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_uint4 yxxz;
	stdmath_uint4 get_yxxz() { return {self->y,self->x,self->x,self->z}; }
	stdmath_uint4 set_yxxz(stdmath_uint4 value) { self->y = value.x; self->x = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_uint4 yxxw;
	stdmath_uint4 get_yxxw() { return {self->y,self->x,self->x,self->w}; }
	stdmath_uint4 set_yxxw(stdmath_uint4 value) { self->y = value.x; self->x = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_uint4 yxyx;
	stdmath_uint4 get_yxyx() { return {self->y,self->x,self->y,self->x}; }
	stdmath_uint4 set_yxyx(stdmath_uint4 value) { self->y = value.x; self->x = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_uint4 yxyy;
	stdmath_uint4 get_yxyy() { return {self->y,self->x,self->y,self->y}; }
	stdmath_uint4 set_yxyy(stdmath_uint4 value) { self->y = value.x; self->x = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_uint4 yxyz;
	stdmath_uint4 get_yxyz() { return {self->y,self->x,self->y,self->z}; }
	stdmath_uint4 set_yxyz(stdmath_uint4 value) { self->y = value.x; self->x = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_uint4 yxyw;
	stdmath_uint4 get_yxyw() { return {self->y,self->x,self->y,self->w}; }
	stdmath_uint4 set_yxyw(stdmath_uint4 value) { self->y = value.x; self->x = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_uint4 yxzx;
	stdmath_uint4 get_yxzx() { return {self->y,self->x,self->z,self->x}; }
	stdmath_uint4 set_yxzx(stdmath_uint4 value) { self->y = value.x; self->x = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_uint4 yxzy;
	stdmath_uint4 get_yxzy() { return {self->y,self->x,self->z,self->y}; }
	stdmath_uint4 set_yxzy(stdmath_uint4 value) { self->y = value.x; self->x = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_uint4 yxzz;
	stdmath_uint4 get_yxzz() { return {self->y,self->x,self->z,self->z}; }
	stdmath_uint4 set_yxzz(stdmath_uint4 value) { self->y = value.x; self->x = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_uint4 yxzw;
	stdmath_uint4 get_yxzw() { return {self->y,self->x,self->z,self->w}; }
	stdmath_uint4 set_yxzw(stdmath_uint4 value) { self->y = value.x; self->x = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_uint4 yxwx;
	stdmath_uint4 get_yxwx() { return {self->y,self->x,self->w,self->x}; }
	stdmath_uint4 set_yxwx(stdmath_uint4 value) { self->y = value.x; self->x = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_uint4 yxwy;
	stdmath_uint4 get_yxwy() { return {self->y,self->x,self->w,self->y}; }
	stdmath_uint4 set_yxwy(stdmath_uint4 value) { self->y = value.x; self->x = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_uint4 yxwz;
	stdmath_uint4 get_yxwz() { return {self->y,self->x,self->w,self->z}; }
	stdmath_uint4 set_yxwz(stdmath_uint4 value) { self->y = value.x; self->x = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_uint4 yxww;
	stdmath_uint4 get_yxww() { return {self->y,self->x,self->w,self->w}; }
	stdmath_uint4 set_yxww(stdmath_uint4 value) { self->y = value.x; self->x = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_uint4 yyxx;
	stdmath_uint4 get_yyxx() { return {self->y,self->y,self->x,self->x}; }
	stdmath_uint4 set_yyxx(stdmath_uint4 value) { self->y = value.x; self->y = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_uint4 yyxy;
	stdmath_uint4 get_yyxy() { return {self->y,self->y,self->x,self->y}; }
	stdmath_uint4 set_yyxy(stdmath_uint4 value) { self->y = value.x; self->y = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_uint4 yyxz;
	stdmath_uint4 get_yyxz() { return {self->y,self->y,self->x,self->z}; }
	stdmath_uint4 set_yyxz(stdmath_uint4 value) { self->y = value.x; self->y = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_uint4 yyxw;
	stdmath_uint4 get_yyxw() { return {self->y,self->y,self->x,self->w}; }
	stdmath_uint4 set_yyxw(stdmath_uint4 value) { self->y = value.x; self->y = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_uint4 yyyx;
	stdmath_uint4 get_yyyx() { return {self->y,self->y,self->y,self->x}; }
	stdmath_uint4 set_yyyx(stdmath_uint4 value) { self->y = value.x; self->y = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_uint4 yyyy;
	stdmath_uint4 get_yyyy() { return {self->y,self->y,self->y,self->y}; }
	stdmath_uint4 set_yyyy(stdmath_uint4 value) { self->y = value.x; self->y = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_uint4 yyyz;
	stdmath_uint4 get_yyyz() { return {self->y,self->y,self->y,self->z}; }
	stdmath_uint4 set_yyyz(stdmath_uint4 value) { self->y = value.x; self->y = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_uint4 yyyw;
	stdmath_uint4 get_yyyw() { return {self->y,self->y,self->y,self->w}; }
	stdmath_uint4 set_yyyw(stdmath_uint4 value) { self->y = value.x; self->y = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_uint4 yyzx;
	stdmath_uint4 get_yyzx() { return {self->y,self->y,self->z,self->x}; }
	stdmath_uint4 set_yyzx(stdmath_uint4 value) { self->y = value.x; self->y = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_uint4 yyzy;
	stdmath_uint4 get_yyzy() { return {self->y,self->y,self->z,self->y}; }
	stdmath_uint4 set_yyzy(stdmath_uint4 value) { self->y = value.x; self->y = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_uint4 yyzz;
	stdmath_uint4 get_yyzz() { return {self->y,self->y,self->z,self->z}; }
	stdmath_uint4 set_yyzz(stdmath_uint4 value) { self->y = value.x; self->y = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_uint4 yyzw;
	stdmath_uint4 get_yyzw() { return {self->y,self->y,self->z,self->w}; }
	stdmath_uint4 set_yyzw(stdmath_uint4 value) { self->y = value.x; self->y = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_uint4 yywx;
	stdmath_uint4 get_yywx() { return {self->y,self->y,self->w,self->x}; }
	stdmath_uint4 set_yywx(stdmath_uint4 value) { self->y = value.x; self->y = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_uint4 yywy;
	stdmath_uint4 get_yywy() { return {self->y,self->y,self->w,self->y}; }
	stdmath_uint4 set_yywy(stdmath_uint4 value) { self->y = value.x; self->y = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_uint4 yywz;
	stdmath_uint4 get_yywz() { return {self->y,self->y,self->w,self->z}; }
	stdmath_uint4 set_yywz(stdmath_uint4 value) { self->y = value.x; self->y = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_uint4 yyww;
	stdmath_uint4 get_yyww() { return {self->y,self->y,self->w,self->w}; }
	stdmath_uint4 set_yyww(stdmath_uint4 value) { self->y = value.x; self->y = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_uint4 yzxx;
	stdmath_uint4 get_yzxx() { return {self->y,self->z,self->x,self->x}; }
	stdmath_uint4 set_yzxx(stdmath_uint4 value) { self->y = value.x; self->z = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_uint4 yzxy;
	stdmath_uint4 get_yzxy() { return {self->y,self->z,self->x,self->y}; }
	stdmath_uint4 set_yzxy(stdmath_uint4 value) { self->y = value.x; self->z = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_uint4 yzxz;
	stdmath_uint4 get_yzxz() { return {self->y,self->z,self->x,self->z}; }
	stdmath_uint4 set_yzxz(stdmath_uint4 value) { self->y = value.x; self->z = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_uint4 yzxw;
	stdmath_uint4 get_yzxw() { return {self->y,self->z,self->x,self->w}; }
	stdmath_uint4 set_yzxw(stdmath_uint4 value) { self->y = value.x; self->z = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_uint4 yzyx;
	stdmath_uint4 get_yzyx() { return {self->y,self->z,self->y,self->x}; }
	stdmath_uint4 set_yzyx(stdmath_uint4 value) { self->y = value.x; self->z = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_uint4 yzyy;
	stdmath_uint4 get_yzyy() { return {self->y,self->z,self->y,self->y}; }
	stdmath_uint4 set_yzyy(stdmath_uint4 value) { self->y = value.x; self->z = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_uint4 yzyz;
	stdmath_uint4 get_yzyz() { return {self->y,self->z,self->y,self->z}; }
	stdmath_uint4 set_yzyz(stdmath_uint4 value) { self->y = value.x; self->z = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_uint4 yzyw;
	stdmath_uint4 get_yzyw() { return {self->y,self->z,self->y,self->w}; }
	stdmath_uint4 set_yzyw(stdmath_uint4 value) { self->y = value.x; self->z = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_uint4 yzzx;
	stdmath_uint4 get_yzzx() { return {self->y,self->z,self->z,self->x}; }
	stdmath_uint4 set_yzzx(stdmath_uint4 value) { self->y = value.x; self->z = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_uint4 yzzy;
	stdmath_uint4 get_yzzy() { return {self->y,self->z,self->z,self->y}; }
	stdmath_uint4 set_yzzy(stdmath_uint4 value) { self->y = value.x; self->z = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_uint4 yzzz;
	stdmath_uint4 get_yzzz() { return {self->y,self->z,self->z,self->z}; }
	stdmath_uint4 set_yzzz(stdmath_uint4 value) { self->y = value.x; self->z = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_uint4 yzzw;
	stdmath_uint4 get_yzzw() { return {self->y,self->z,self->z,self->w}; }
	stdmath_uint4 set_yzzw(stdmath_uint4 value) { self->y = value.x; self->z = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_uint4 yzwx;
	stdmath_uint4 get_yzwx() { return {self->y,self->z,self->w,self->x}; }
	stdmath_uint4 set_yzwx(stdmath_uint4 value) { self->y = value.x; self->z = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_uint4 yzwy;
	stdmath_uint4 get_yzwy() { return {self->y,self->z,self->w,self->y}; }
	stdmath_uint4 set_yzwy(stdmath_uint4 value) { self->y = value.x; self->z = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_uint4 yzwz;
	stdmath_uint4 get_yzwz() { return {self->y,self->z,self->w,self->z}; }
	stdmath_uint4 set_yzwz(stdmath_uint4 value) { self->y = value.x; self->z = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_uint4 yzww;
	stdmath_uint4 get_yzww() { return {self->y,self->z,self->w,self->w}; }
	stdmath_uint4 set_yzww(stdmath_uint4 value) { self->y = value.x; self->z = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_uint4 ywxx;
	stdmath_uint4 get_ywxx() { return {self->y,self->w,self->x,self->x}; }
	stdmath_uint4 set_ywxx(stdmath_uint4 value) { self->y = value.x; self->w = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_uint4 ywxy;
	stdmath_uint4 get_ywxy() { return {self->y,self->w,self->x,self->y}; }
	stdmath_uint4 set_ywxy(stdmath_uint4 value) { self->y = value.x; self->w = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_uint4 ywxz;
	stdmath_uint4 get_ywxz() { return {self->y,self->w,self->x,self->z}; }
	stdmath_uint4 set_ywxz(stdmath_uint4 value) { self->y = value.x; self->w = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_uint4 ywxw;
	stdmath_uint4 get_ywxw() { return {self->y,self->w,self->x,self->w}; }
	stdmath_uint4 set_ywxw(stdmath_uint4 value) { self->y = value.x; self->w = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_uint4 ywyx;
	stdmath_uint4 get_ywyx() { return {self->y,self->w,self->y,self->x}; }
	stdmath_uint4 set_ywyx(stdmath_uint4 value) { self->y = value.x; self->w = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_uint4 ywyy;
	stdmath_uint4 get_ywyy() { return {self->y,self->w,self->y,self->y}; }
	stdmath_uint4 set_ywyy(stdmath_uint4 value) { self->y = value.x; self->w = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_uint4 ywyz;
	stdmath_uint4 get_ywyz() { return {self->y,self->w,self->y,self->z}; }
	stdmath_uint4 set_ywyz(stdmath_uint4 value) { self->y = value.x; self->w = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_uint4 ywyw;
	stdmath_uint4 get_ywyw() { return {self->y,self->w,self->y,self->w}; }
	stdmath_uint4 set_ywyw(stdmath_uint4 value) { self->y = value.x; self->w = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_uint4 ywzx;
	stdmath_uint4 get_ywzx() { return {self->y,self->w,self->z,self->x}; }
	stdmath_uint4 set_ywzx(stdmath_uint4 value) { self->y = value.x; self->w = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_uint4 ywzy;
	stdmath_uint4 get_ywzy() { return {self->y,self->w,self->z,self->y}; }
	stdmath_uint4 set_ywzy(stdmath_uint4 value) { self->y = value.x; self->w = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_uint4 ywzz;
	stdmath_uint4 get_ywzz() { return {self->y,self->w,self->z,self->z}; }
	stdmath_uint4 set_ywzz(stdmath_uint4 value) { self->y = value.x; self->w = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_uint4 ywzw;
	stdmath_uint4 get_ywzw() { return {self->y,self->w,self->z,self->w}; }
	stdmath_uint4 set_ywzw(stdmath_uint4 value) { self->y = value.x; self->w = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_uint4 ywwx;
	stdmath_uint4 get_ywwx() { return {self->y,self->w,self->w,self->x}; }
	stdmath_uint4 set_ywwx(stdmath_uint4 value) { self->y = value.x; self->w = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_uint4 ywwy;
	stdmath_uint4 get_ywwy() { return {self->y,self->w,self->w,self->y}; }
	stdmath_uint4 set_ywwy(stdmath_uint4 value) { self->y = value.x; self->w = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_uint4 ywwz;
	stdmath_uint4 get_ywwz() { return {self->y,self->w,self->w,self->z}; }
	stdmath_uint4 set_ywwz(stdmath_uint4 value) { self->y = value.x; self->w = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_uint4 ywww;
	stdmath_uint4 get_ywww() { return {self->y,self->w,self->w,self->w}; }
	stdmath_uint4 set_ywww(stdmath_uint4 value) { self->y = value.x; self->w = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_uint4 zxxx;
	stdmath_uint4 get_zxxx() { return {self->z,self->x,self->x,self->x}; }
	stdmath_uint4 set_zxxx(stdmath_uint4 value) { self->z = value.x; self->x = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_uint4 zxxy;
	stdmath_uint4 get_zxxy() { return {self->z,self->x,self->x,self->y}; }
	stdmath_uint4 set_zxxy(stdmath_uint4 value) { self->z = value.x; self->x = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_uint4 zxxz;
	stdmath_uint4 get_zxxz() { return {self->z,self->x,self->x,self->z}; }
	stdmath_uint4 set_zxxz(stdmath_uint4 value) { self->z = value.x; self->x = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_uint4 zxxw;
	stdmath_uint4 get_zxxw() { return {self->z,self->x,self->x,self->w}; }
	stdmath_uint4 set_zxxw(stdmath_uint4 value) { self->z = value.x; self->x = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_uint4 zxyx;
	stdmath_uint4 get_zxyx() { return {self->z,self->x,self->y,self->x}; }
	stdmath_uint4 set_zxyx(stdmath_uint4 value) { self->z = value.x; self->x = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_uint4 zxyy;
	stdmath_uint4 get_zxyy() { return {self->z,self->x,self->y,self->y}; }
	stdmath_uint4 set_zxyy(stdmath_uint4 value) { self->z = value.x; self->x = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_uint4 zxyz;
	stdmath_uint4 get_zxyz() { return {self->z,self->x,self->y,self->z}; }
	stdmath_uint4 set_zxyz(stdmath_uint4 value) { self->z = value.x; self->x = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_uint4 zxyw;
	stdmath_uint4 get_zxyw() { return {self->z,self->x,self->y,self->w}; }
	stdmath_uint4 set_zxyw(stdmath_uint4 value) { self->z = value.x; self->x = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_uint4 zxzx;
	stdmath_uint4 get_zxzx() { return {self->z,self->x,self->z,self->x}; }
	stdmath_uint4 set_zxzx(stdmath_uint4 value) { self->z = value.x; self->x = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_uint4 zxzy;
	stdmath_uint4 get_zxzy() { return {self->z,self->x,self->z,self->y}; }
	stdmath_uint4 set_zxzy(stdmath_uint4 value) { self->z = value.x; self->x = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_uint4 zxzz;
	stdmath_uint4 get_zxzz() { return {self->z,self->x,self->z,self->z}; }
	stdmath_uint4 set_zxzz(stdmath_uint4 value) { self->z = value.x; self->x = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_uint4 zxzw;
	stdmath_uint4 get_zxzw() { return {self->z,self->x,self->z,self->w}; }
	stdmath_uint4 set_zxzw(stdmath_uint4 value) { self->z = value.x; self->x = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_uint4 zxwx;
	stdmath_uint4 get_zxwx() { return {self->z,self->x,self->w,self->x}; }
	stdmath_uint4 set_zxwx(stdmath_uint4 value) { self->z = value.x; self->x = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_uint4 zxwy;
	stdmath_uint4 get_zxwy() { return {self->z,self->x,self->w,self->y}; }
	stdmath_uint4 set_zxwy(stdmath_uint4 value) { self->z = value.x; self->x = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_uint4 zxwz;
	stdmath_uint4 get_zxwz() { return {self->z,self->x,self->w,self->z}; }
	stdmath_uint4 set_zxwz(stdmath_uint4 value) { self->z = value.x; self->x = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_uint4 zxww;
	stdmath_uint4 get_zxww() { return {self->z,self->x,self->w,self->w}; }
	stdmath_uint4 set_zxww(stdmath_uint4 value) { self->z = value.x; self->x = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_uint4 zyxx;
	stdmath_uint4 get_zyxx() { return {self->z,self->y,self->x,self->x}; }
	stdmath_uint4 set_zyxx(stdmath_uint4 value) { self->z = value.x; self->y = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_uint4 zyxy;
	stdmath_uint4 get_zyxy() { return {self->z,self->y,self->x,self->y}; }
	stdmath_uint4 set_zyxy(stdmath_uint4 value) { self->z = value.x; self->y = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_uint4 zyxz;
	stdmath_uint4 get_zyxz() { return {self->z,self->y,self->x,self->z}; }
	stdmath_uint4 set_zyxz(stdmath_uint4 value) { self->z = value.x; self->y = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_uint4 zyxw;
	stdmath_uint4 get_zyxw() { return {self->z,self->y,self->x,self->w}; }
	stdmath_uint4 set_zyxw(stdmath_uint4 value) { self->z = value.x; self->y = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_uint4 zyyx;
	stdmath_uint4 get_zyyx() { return {self->z,self->y,self->y,self->x}; }
	stdmath_uint4 set_zyyx(stdmath_uint4 value) { self->z = value.x; self->y = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_uint4 zyyy;
	stdmath_uint4 get_zyyy() { return {self->z,self->y,self->y,self->y}; }
	stdmath_uint4 set_zyyy(stdmath_uint4 value) { self->z = value.x; self->y = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_uint4 zyyz;
	stdmath_uint4 get_zyyz() { return {self->z,self->y,self->y,self->z}; }
	stdmath_uint4 set_zyyz(stdmath_uint4 value) { self->z = value.x; self->y = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_uint4 zyyw;
	stdmath_uint4 get_zyyw() { return {self->z,self->y,self->y,self->w}; }
	stdmath_uint4 set_zyyw(stdmath_uint4 value) { self->z = value.x; self->y = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_uint4 zyzx;
	stdmath_uint4 get_zyzx() { return {self->z,self->y,self->z,self->x}; }
	stdmath_uint4 set_zyzx(stdmath_uint4 value) { self->z = value.x; self->y = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_uint4 zyzy;
	stdmath_uint4 get_zyzy() { return {self->z,self->y,self->z,self->y}; }
	stdmath_uint4 set_zyzy(stdmath_uint4 value) { self->z = value.x; self->y = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_uint4 zyzz;
	stdmath_uint4 get_zyzz() { return {self->z,self->y,self->z,self->z}; }
	stdmath_uint4 set_zyzz(stdmath_uint4 value) { self->z = value.x; self->y = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_uint4 zyzw;
	stdmath_uint4 get_zyzw() { return {self->z,self->y,self->z,self->w}; }
	stdmath_uint4 set_zyzw(stdmath_uint4 value) { self->z = value.x; self->y = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_uint4 zywx;
	stdmath_uint4 get_zywx() { return {self->z,self->y,self->w,self->x}; }
	stdmath_uint4 set_zywx(stdmath_uint4 value) { self->z = value.x; self->y = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_uint4 zywy;
	stdmath_uint4 get_zywy() { return {self->z,self->y,self->w,self->y}; }
	stdmath_uint4 set_zywy(stdmath_uint4 value) { self->z = value.x; self->y = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_uint4 zywz;
	stdmath_uint4 get_zywz() { return {self->z,self->y,self->w,self->z}; }
	stdmath_uint4 set_zywz(stdmath_uint4 value) { self->z = value.x; self->y = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_uint4 zyww;
	stdmath_uint4 get_zyww() { return {self->z,self->y,self->w,self->w}; }
	stdmath_uint4 set_zyww(stdmath_uint4 value) { self->z = value.x; self->y = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_uint4 zzxx;
	stdmath_uint4 get_zzxx() { return {self->z,self->z,self->x,self->x}; }
	stdmath_uint4 set_zzxx(stdmath_uint4 value) { self->z = value.x; self->z = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_uint4 zzxy;
	stdmath_uint4 get_zzxy() { return {self->z,self->z,self->x,self->y}; }
	stdmath_uint4 set_zzxy(stdmath_uint4 value) { self->z = value.x; self->z = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_uint4 zzxz;
	stdmath_uint4 get_zzxz() { return {self->z,self->z,self->x,self->z}; }
	stdmath_uint4 set_zzxz(stdmath_uint4 value) { self->z = value.x; self->z = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_uint4 zzxw;
	stdmath_uint4 get_zzxw() { return {self->z,self->z,self->x,self->w}; }
	stdmath_uint4 set_zzxw(stdmath_uint4 value) { self->z = value.x; self->z = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_uint4 zzyx;
	stdmath_uint4 get_zzyx() { return {self->z,self->z,self->y,self->x}; }
	stdmath_uint4 set_zzyx(stdmath_uint4 value) { self->z = value.x; self->z = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_uint4 zzyy;
	stdmath_uint4 get_zzyy() { return {self->z,self->z,self->y,self->y}; }
	stdmath_uint4 set_zzyy(stdmath_uint4 value) { self->z = value.x; self->z = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_uint4 zzyz;
	stdmath_uint4 get_zzyz() { return {self->z,self->z,self->y,self->z}; }
	stdmath_uint4 set_zzyz(stdmath_uint4 value) { self->z = value.x; self->z = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_uint4 zzyw;
	stdmath_uint4 get_zzyw() { return {self->z,self->z,self->y,self->w}; }
	stdmath_uint4 set_zzyw(stdmath_uint4 value) { self->z = value.x; self->z = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_uint4 zzzx;
	stdmath_uint4 get_zzzx() { return {self->z,self->z,self->z,self->x}; }
	stdmath_uint4 set_zzzx(stdmath_uint4 value) { self->z = value.x; self->z = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_uint4 zzzy;
	stdmath_uint4 get_zzzy() { return {self->z,self->z,self->z,self->y}; }
	stdmath_uint4 set_zzzy(stdmath_uint4 value) { self->z = value.x; self->z = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_uint4 zzzz;
	stdmath_uint4 get_zzzz() { return {self->z,self->z,self->z,self->z}; }
	stdmath_uint4 set_zzzz(stdmath_uint4 value) { self->z = value.x; self->z = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_uint4 zzzw;
	stdmath_uint4 get_zzzw() { return {self->z,self->z,self->z,self->w}; }
	stdmath_uint4 set_zzzw(stdmath_uint4 value) { self->z = value.x; self->z = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_uint4 zzwx;
	stdmath_uint4 get_zzwx() { return {self->z,self->z,self->w,self->x}; }
	stdmath_uint4 set_zzwx(stdmath_uint4 value) { self->z = value.x; self->z = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_uint4 zzwy;
	stdmath_uint4 get_zzwy() { return {self->z,self->z,self->w,self->y}; }
	stdmath_uint4 set_zzwy(stdmath_uint4 value) { self->z = value.x; self->z = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_uint4 zzwz;
	stdmath_uint4 get_zzwz() { return {self->z,self->z,self->w,self->z}; }
	stdmath_uint4 set_zzwz(stdmath_uint4 value) { self->z = value.x; self->z = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_uint4 zzww;
	stdmath_uint4 get_zzww() { return {self->z,self->z,self->w,self->w}; }
	stdmath_uint4 set_zzww(stdmath_uint4 value) { self->z = value.x; self->z = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_uint4 zwxx;
	stdmath_uint4 get_zwxx() { return {self->z,self->w,self->x,self->x}; }
	stdmath_uint4 set_zwxx(stdmath_uint4 value) { self->z = value.x; self->w = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_uint4 zwxy;
	stdmath_uint4 get_zwxy() { return {self->z,self->w,self->x,self->y}; }
	stdmath_uint4 set_zwxy(stdmath_uint4 value) { self->z = value.x; self->w = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_uint4 zwxz;
	stdmath_uint4 get_zwxz() { return {self->z,self->w,self->x,self->z}; }
	stdmath_uint4 set_zwxz(stdmath_uint4 value) { self->z = value.x; self->w = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_uint4 zwxw;
	stdmath_uint4 get_zwxw() { return {self->z,self->w,self->x,self->w}; }
	stdmath_uint4 set_zwxw(stdmath_uint4 value) { self->z = value.x; self->w = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_uint4 zwyx;
	stdmath_uint4 get_zwyx() { return {self->z,self->w,self->y,self->x}; }
	stdmath_uint4 set_zwyx(stdmath_uint4 value) { self->z = value.x; self->w = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_uint4 zwyy;
	stdmath_uint4 get_zwyy() { return {self->z,self->w,self->y,self->y}; }
	stdmath_uint4 set_zwyy(stdmath_uint4 value) { self->z = value.x; self->w = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_uint4 zwyz;
	stdmath_uint4 get_zwyz() { return {self->z,self->w,self->y,self->z}; }
	stdmath_uint4 set_zwyz(stdmath_uint4 value) { self->z = value.x; self->w = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_uint4 zwyw;
	stdmath_uint4 get_zwyw() { return {self->z,self->w,self->y,self->w}; }
	stdmath_uint4 set_zwyw(stdmath_uint4 value) { self->z = value.x; self->w = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_uint4 zwzx;
	stdmath_uint4 get_zwzx() { return {self->z,self->w,self->z,self->x}; }
	stdmath_uint4 set_zwzx(stdmath_uint4 value) { self->z = value.x; self->w = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_uint4 zwzy;
	stdmath_uint4 get_zwzy() { return {self->z,self->w,self->z,self->y}; }
	stdmath_uint4 set_zwzy(stdmath_uint4 value) { self->z = value.x; self->w = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_uint4 zwzz;
	stdmath_uint4 get_zwzz() { return {self->z,self->w,self->z,self->z}; }
	stdmath_uint4 set_zwzz(stdmath_uint4 value) { self->z = value.x; self->w = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_uint4 zwzw;
	stdmath_uint4 get_zwzw() { return {self->z,self->w,self->z,self->w}; }
	stdmath_uint4 set_zwzw(stdmath_uint4 value) { self->z = value.x; self->w = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_uint4 zwwx;
	stdmath_uint4 get_zwwx() { return {self->z,self->w,self->w,self->x}; }
	stdmath_uint4 set_zwwx(stdmath_uint4 value) { self->z = value.x; self->w = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_uint4 zwwy;
	stdmath_uint4 get_zwwy() { return {self->z,self->w,self->w,self->y}; }
	stdmath_uint4 set_zwwy(stdmath_uint4 value) { self->z = value.x; self->w = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_uint4 zwwz;
	stdmath_uint4 get_zwwz() { return {self->z,self->w,self->w,self->z}; }
	stdmath_uint4 set_zwwz(stdmath_uint4 value) { self->z = value.x; self->w = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_uint4 zwww;
	stdmath_uint4 get_zwww() { return {self->z,self->w,self->w,self->w}; }
	stdmath_uint4 set_zwww(stdmath_uint4 value) { self->z = value.x; self->w = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_uint4 wxxx;
	stdmath_uint4 get_wxxx() { return {self->w,self->x,self->x,self->x}; }
	stdmath_uint4 set_wxxx(stdmath_uint4 value) { self->w = value.x; self->x = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_uint4 wxxy;
	stdmath_uint4 get_wxxy() { return {self->w,self->x,self->x,self->y}; }
	stdmath_uint4 set_wxxy(stdmath_uint4 value) { self->w = value.x; self->x = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_uint4 wxxz;
	stdmath_uint4 get_wxxz() { return {self->w,self->x,self->x,self->z}; }
	stdmath_uint4 set_wxxz(stdmath_uint4 value) { self->w = value.x; self->x = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_uint4 wxxw;
	stdmath_uint4 get_wxxw() { return {self->w,self->x,self->x,self->w}; }
	stdmath_uint4 set_wxxw(stdmath_uint4 value) { self->w = value.x; self->x = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_uint4 wxyx;
	stdmath_uint4 get_wxyx() { return {self->w,self->x,self->y,self->x}; }
	stdmath_uint4 set_wxyx(stdmath_uint4 value) { self->w = value.x; self->x = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_uint4 wxyy;
	stdmath_uint4 get_wxyy() { return {self->w,self->x,self->y,self->y}; }
	stdmath_uint4 set_wxyy(stdmath_uint4 value) { self->w = value.x; self->x = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_uint4 wxyz;
	stdmath_uint4 get_wxyz() { return {self->w,self->x,self->y,self->z}; }
	stdmath_uint4 set_wxyz(stdmath_uint4 value) { self->w = value.x; self->x = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_uint4 wxyw;
	stdmath_uint4 get_wxyw() { return {self->w,self->x,self->y,self->w}; }
	stdmath_uint4 set_wxyw(stdmath_uint4 value) { self->w = value.x; self->x = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_uint4 wxzx;
	stdmath_uint4 get_wxzx() { return {self->w,self->x,self->z,self->x}; }
	stdmath_uint4 set_wxzx(stdmath_uint4 value) { self->w = value.x; self->x = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_uint4 wxzy;
	stdmath_uint4 get_wxzy() { return {self->w,self->x,self->z,self->y}; }
	stdmath_uint4 set_wxzy(stdmath_uint4 value) { self->w = value.x; self->x = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_uint4 wxzz;
	stdmath_uint4 get_wxzz() { return {self->w,self->x,self->z,self->z}; }
	stdmath_uint4 set_wxzz(stdmath_uint4 value) { self->w = value.x; self->x = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_uint4 wxzw;
	stdmath_uint4 get_wxzw() { return {self->w,self->x,self->z,self->w}; }
	stdmath_uint4 set_wxzw(stdmath_uint4 value) { self->w = value.x; self->x = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_uint4 wxwx;
	stdmath_uint4 get_wxwx() { return {self->w,self->x,self->w,self->x}; }
	stdmath_uint4 set_wxwx(stdmath_uint4 value) { self->w = value.x; self->x = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_uint4 wxwy;
	stdmath_uint4 get_wxwy() { return {self->w,self->x,self->w,self->y}; }
	stdmath_uint4 set_wxwy(stdmath_uint4 value) { self->w = value.x; self->x = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_uint4 wxwz;
	stdmath_uint4 get_wxwz() { return {self->w,self->x,self->w,self->z}; }
	stdmath_uint4 set_wxwz(stdmath_uint4 value) { self->w = value.x; self->x = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_uint4 wxww;
	stdmath_uint4 get_wxww() { return {self->w,self->x,self->w,self->w}; }
	stdmath_uint4 set_wxww(stdmath_uint4 value) { self->w = value.x; self->x = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_uint4 wyxx;
	stdmath_uint4 get_wyxx() { return {self->w,self->y,self->x,self->x}; }
	stdmath_uint4 set_wyxx(stdmath_uint4 value) { self->w = value.x; self->y = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_uint4 wyxy;
	stdmath_uint4 get_wyxy() { return {self->w,self->y,self->x,self->y}; }
	stdmath_uint4 set_wyxy(stdmath_uint4 value) { self->w = value.x; self->y = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_uint4 wyxz;
	stdmath_uint4 get_wyxz() { return {self->w,self->y,self->x,self->z}; }
	stdmath_uint4 set_wyxz(stdmath_uint4 value) { self->w = value.x; self->y = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_uint4 wyxw;
	stdmath_uint4 get_wyxw() { return {self->w,self->y,self->x,self->w}; }
	stdmath_uint4 set_wyxw(stdmath_uint4 value) { self->w = value.x; self->y = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_uint4 wyyx;
	stdmath_uint4 get_wyyx() { return {self->w,self->y,self->y,self->x}; }
	stdmath_uint4 set_wyyx(stdmath_uint4 value) { self->w = value.x; self->y = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_uint4 wyyy;
	stdmath_uint4 get_wyyy() { return {self->w,self->y,self->y,self->y}; }
	stdmath_uint4 set_wyyy(stdmath_uint4 value) { self->w = value.x; self->y = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_uint4 wyyz;
	stdmath_uint4 get_wyyz() { return {self->w,self->y,self->y,self->z}; }
	stdmath_uint4 set_wyyz(stdmath_uint4 value) { self->w = value.x; self->y = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_uint4 wyyw;
	stdmath_uint4 get_wyyw() { return {self->w,self->y,self->y,self->w}; }
	stdmath_uint4 set_wyyw(stdmath_uint4 value) { self->w = value.x; self->y = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_uint4 wyzx;
	stdmath_uint4 get_wyzx() { return {self->w,self->y,self->z,self->x}; }
	stdmath_uint4 set_wyzx(stdmath_uint4 value) { self->w = value.x; self->y = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_uint4 wyzy;
	stdmath_uint4 get_wyzy() { return {self->w,self->y,self->z,self->y}; }
	stdmath_uint4 set_wyzy(stdmath_uint4 value) { self->w = value.x; self->y = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_uint4 wyzz;
	stdmath_uint4 get_wyzz() { return {self->w,self->y,self->z,self->z}; }
	stdmath_uint4 set_wyzz(stdmath_uint4 value) { self->w = value.x; self->y = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_uint4 wyzw;
	stdmath_uint4 get_wyzw() { return {self->w,self->y,self->z,self->w}; }
	stdmath_uint4 set_wyzw(stdmath_uint4 value) { self->w = value.x; self->y = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_uint4 wywx;
	stdmath_uint4 get_wywx() { return {self->w,self->y,self->w,self->x}; }
	stdmath_uint4 set_wywx(stdmath_uint4 value) { self->w = value.x; self->y = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_uint4 wywy;
	stdmath_uint4 get_wywy() { return {self->w,self->y,self->w,self->y}; }
	stdmath_uint4 set_wywy(stdmath_uint4 value) { self->w = value.x; self->y = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_uint4 wywz;
	stdmath_uint4 get_wywz() { return {self->w,self->y,self->w,self->z}; }
	stdmath_uint4 set_wywz(stdmath_uint4 value) { self->w = value.x; self->y = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_uint4 wyww;
	stdmath_uint4 get_wyww() { return {self->w,self->y,self->w,self->w}; }
	stdmath_uint4 set_wyww(stdmath_uint4 value) { self->w = value.x; self->y = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_uint4 wzxx;
	stdmath_uint4 get_wzxx() { return {self->w,self->z,self->x,self->x}; }
	stdmath_uint4 set_wzxx(stdmath_uint4 value) { self->w = value.x; self->z = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_uint4 wzxy;
	stdmath_uint4 get_wzxy() { return {self->w,self->z,self->x,self->y}; }
	stdmath_uint4 set_wzxy(stdmath_uint4 value) { self->w = value.x; self->z = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_uint4 wzxz;
	stdmath_uint4 get_wzxz() { return {self->w,self->z,self->x,self->z}; }
	stdmath_uint4 set_wzxz(stdmath_uint4 value) { self->w = value.x; self->z = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_uint4 wzxw;
	stdmath_uint4 get_wzxw() { return {self->w,self->z,self->x,self->w}; }
	stdmath_uint4 set_wzxw(stdmath_uint4 value) { self->w = value.x; self->z = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_uint4 wzyx;
	stdmath_uint4 get_wzyx() { return {self->w,self->z,self->y,self->x}; }
	stdmath_uint4 set_wzyx(stdmath_uint4 value) { self->w = value.x; self->z = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_uint4 wzyy;
	stdmath_uint4 get_wzyy() { return {self->w,self->z,self->y,self->y}; }
	stdmath_uint4 set_wzyy(stdmath_uint4 value) { self->w = value.x; self->z = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_uint4 wzyz;
	stdmath_uint4 get_wzyz() { return {self->w,self->z,self->y,self->z}; }
	stdmath_uint4 set_wzyz(stdmath_uint4 value) { self->w = value.x; self->z = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_uint4 wzyw;
	stdmath_uint4 get_wzyw() { return {self->w,self->z,self->y,self->w}; }
	stdmath_uint4 set_wzyw(stdmath_uint4 value) { self->w = value.x; self->z = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_uint4 wzzx;
	stdmath_uint4 get_wzzx() { return {self->w,self->z,self->z,self->x}; }
	stdmath_uint4 set_wzzx(stdmath_uint4 value) { self->w = value.x; self->z = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_uint4 wzzy;
	stdmath_uint4 get_wzzy() { return {self->w,self->z,self->z,self->y}; }
	stdmath_uint4 set_wzzy(stdmath_uint4 value) { self->w = value.x; self->z = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_uint4 wzzz;
	stdmath_uint4 get_wzzz() { return {self->w,self->z,self->z,self->z}; }
	stdmath_uint4 set_wzzz(stdmath_uint4 value) { self->w = value.x; self->z = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_uint4 wzzw;
	stdmath_uint4 get_wzzw() { return {self->w,self->z,self->z,self->w}; }
	stdmath_uint4 set_wzzw(stdmath_uint4 value) { self->w = value.x; self->z = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_uint4 wzwx;
	stdmath_uint4 get_wzwx() { return {self->w,self->z,self->w,self->x}; }
	stdmath_uint4 set_wzwx(stdmath_uint4 value) { self->w = value.x; self->z = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_uint4 wzwy;
	stdmath_uint4 get_wzwy() { return {self->w,self->z,self->w,self->y}; }
	stdmath_uint4 set_wzwy(stdmath_uint4 value) { self->w = value.x; self->z = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_uint4 wzwz;
	stdmath_uint4 get_wzwz() { return {self->w,self->z,self->w,self->z}; }
	stdmath_uint4 set_wzwz(stdmath_uint4 value) { self->w = value.x; self->z = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_uint4 wzww;
	stdmath_uint4 get_wzww() { return {self->w,self->z,self->w,self->w}; }
	stdmath_uint4 set_wzww(stdmath_uint4 value) { self->w = value.x; self->z = value.y; self->w = value.z; self->w = value.w; return *self; }

	stdmath_uint4 wwxx;
	stdmath_uint4 get_wwxx() { return {self->w,self->w,self->x,self->x}; }
	stdmath_uint4 set_wwxx(stdmath_uint4 value) { self->w = value.x; self->w = value.y; self->x = value.z; self->x = value.w; return *self; }

	stdmath_uint4 wwxy;
	stdmath_uint4 get_wwxy() { return {self->w,self->w,self->x,self->y}; }
	stdmath_uint4 set_wwxy(stdmath_uint4 value) { self->w = value.x; self->w = value.y; self->x = value.z; self->y = value.w; return *self; }

	stdmath_uint4 wwxz;
	stdmath_uint4 get_wwxz() { return {self->w,self->w,self->x,self->z}; }
	stdmath_uint4 set_wwxz(stdmath_uint4 value) { self->w = value.x; self->w = value.y; self->x = value.z; self->z = value.w; return *self; }

	stdmath_uint4 wwxw;
	stdmath_uint4 get_wwxw() { return {self->w,self->w,self->x,self->w}; }
	stdmath_uint4 set_wwxw(stdmath_uint4 value) { self->w = value.x; self->w = value.y; self->x = value.z; self->w = value.w; return *self; }

	stdmath_uint4 wwyx;
	stdmath_uint4 get_wwyx() { return {self->w,self->w,self->y,self->x}; }
	stdmath_uint4 set_wwyx(stdmath_uint4 value) { self->w = value.x; self->w = value.y; self->y = value.z; self->x = value.w; return *self; }

	stdmath_uint4 wwyy;
	stdmath_uint4 get_wwyy() { return {self->w,self->w,self->y,self->y}; }
	stdmath_uint4 set_wwyy(stdmath_uint4 value) { self->w = value.x; self->w = value.y; self->y = value.z; self->y = value.w; return *self; }

	stdmath_uint4 wwyz;
	stdmath_uint4 get_wwyz() { return {self->w,self->w,self->y,self->z}; }
	stdmath_uint4 set_wwyz(stdmath_uint4 value) { self->w = value.x; self->w = value.y; self->y = value.z; self->z = value.w; return *self; }

	stdmath_uint4 wwyw;
	stdmath_uint4 get_wwyw() { return {self->w,self->w,self->y,self->w}; }
	stdmath_uint4 set_wwyw(stdmath_uint4 value) { self->w = value.x; self->w = value.y; self->y = value.z; self->w = value.w; return *self; }

	stdmath_uint4 wwzx;
	stdmath_uint4 get_wwzx() { return {self->w,self->w,self->z,self->x}; }
	stdmath_uint4 set_wwzx(stdmath_uint4 value) { self->w = value.x; self->w = value.y; self->z = value.z; self->x = value.w; return *self; }

	stdmath_uint4 wwzy;
	stdmath_uint4 get_wwzy() { return {self->w,self->w,self->z,self->y}; }
	stdmath_uint4 set_wwzy(stdmath_uint4 value) { self->w = value.x; self->w = value.y; self->z = value.z; self->y = value.w; return *self; }

	stdmath_uint4 wwzz;
	stdmath_uint4 get_wwzz() { return {self->w,self->w,self->z,self->z}; }
	stdmath_uint4 set_wwzz(stdmath_uint4 value) { self->w = value.x; self->w = value.y; self->z = value.z; self->z = value.w; return *self; }

	stdmath_uint4 wwzw;
	stdmath_uint4 get_wwzw() { return {self->w,self->w,self->z,self->w}; }
	stdmath_uint4 set_wwzw(stdmath_uint4 value) { self->w = value.x; self->w = value.y; self->z = value.z; self->w = value.w; return *self; }

	stdmath_uint4 wwwx;
	stdmath_uint4 get_wwwx() { return {self->w,self->w,self->w,self->x}; }
	stdmath_uint4 set_wwwx(stdmath_uint4 value) { self->w = value.x; self->w = value.y; self->w = value.z; self->x = value.w; return *self; }

	stdmath_uint4 wwwy;
	stdmath_uint4 get_wwwy() { return {self->w,self->w,self->w,self->y}; }
	stdmath_uint4 set_wwwy(stdmath_uint4 value) { self->w = value.x; self->w = value.y; self->w = value.z; self->y = value.w; return *self; }

	stdmath_uint4 wwwz;
	stdmath_uint4 get_wwwz() { return {self->w,self->w,self->w,self->z}; }
	stdmath_uint4 set_wwwz(stdmath_uint4 value) { self->w = value.x; self->w = value.y; self->w = value.z; self->z = value.w; return *self; }

	stdmath_uint4 wwww;
	stdmath_uint4 get_wwww() { return {self->w,self->w,self->w,self->w}; }
	stdmath_uint4 set_wwww(stdmath_uint4 value) { self->w = value.x; self->w = value.y; self->w = value.z; self->w = value.w; return *self; }



	stdmath_uint4 _add(stdmath_uint4 o) {
		return stdmath_uint4_add(*self, o);
	}
	stdmath_uint4 _subtract(stdmath_uint4 o) {
		return stdmath_uint4_subtract(*self, o);
	}
	stdmath_uint4 _negate() {
		return stdmath_uint4_negate(*self);
	}
	stdmath_uint4 _multiply(stdmath_uint4 o) {
		return stdmath_uint4_multiply(*self, o);
	}
	stdmath_uint4 _divide(stdmath_uint4 o) {
		return stdmath_uint4_divide(*self, o);
	}
	stdmath_uint4 _scale(uint32_t o) {
		return stdmath_uint4_scale(*self, o);
	}

#if false
	stdmath_uint4 _modulus(stdmath_uint4 o) {
		return stdmath_uint4_modulus(*self, o);
	}
	stdmath_uint4 _logical_not() {
		return stdmath_uint4_logical_not(*self);
	}
	stdmath_uint4 _bitwise_not() {
		return stdmath_uint4_bitwise_not(*self);
	}
	stdmath_uint4 _logical_and(stdmath_uint4 o) {
		return stdmath_uint4_logical_and(*self, o);
	}
	stdmath_uint4 _bitwise_and(stdmath_uint4 o) {
		return stdmath_uint4_bitwise_and(*self, o);
	}
	stdmath_uint4 _logical_or(stdmath_uint4 o) {
		return stdmath_uint4_logical_or(*self, o);
	}
	stdmath_uint4 _bitwise_or(stdmath_uint4 o) {
		return stdmath_uint4_bitwise_or(*self, o);
	}
	stdmath_uint4 _bitwise_xor(stdmath_uint4 o) {
		return stdmath_uint4_bitwise_xor(*self, o);
	}
	stdmath_uint4 _shift_left(stdmath_uint4 o) {
		return stdmath_uint4_shift_left(*self, o);
	}
	stdmath_uint4 _shift_right(stdmath_uint4 o) {
		return stdmath_uint4_shift_right(*self, o);
	}
#endif

	bool4 _equal_to(stdmath_uint4 o) {
		return stdmath_uint4_equal_to(*self, o);
	}
	bool4 _not_equal_to(stdmath_uint4 o) {
		return stdmath_uint4_not_equal_to(*self, o);
	}
	bool4 _less_than(stdmath_uint4 o) {
		return stdmath_uint4_less_than(*self, o);
	}
	bool4 _less_than_or_equal_to(stdmath_uint4 o) {
		return stdmath_uint4_less_than_or_equal_to(*self, o);
	}
	bool4 _greater_than(stdmath_uint4 o) {
		return stdmath_uint4_greater_than(*self, o);
	}
	bool4 _greater_than_or_equal_to(stdmath_uint4 o) {
		return stdmath_uint4_greater_than_or_equal_to(*self, o);
	}
	
	uint32_t _length_squared() {
		return stdmath_uint4_length_squared(*self);
	}
	uint32_t _length() {
		return stdmath_uint4_length(*self);
	}
	uint32_t _dot() {
		return stdmath_uint4_dot(*self);
	}
	uint32_t _min_element() {
		return stdmath_uint4_min_element(*self);
	}
	uint32_t _max_element() {
		return stdmath_uint4_max_element(*self);
	}

	// uint32_t elementwise_transform()
	// uint32_t reduce_element
	
	stdmath_uint4 _min(stdmath_uint4 o) {
		return stdmath_uint4_min(*self, o);
	}
	stdmath_uint4 _max(stdmath_uint4 o) {
		return stdmath_uint4_max(*self, o);
	}
	stdmath_uint4 _normalize() {
		return stdmath_uint4_normalize(*self);
	}
	stdmath_uint4 _lerp(stdmath_uint4 o, uint t) {
		return stdmath_uint4_lerp(*self, o, t);
	}
	stdmath_uint4 _clamp(stdmath_uint4 min, stdmath_uint4 max) {
		return stdmath_uint4_clamp(*self, min, max);
	}
	stdmath_uint4 _reflect(stdmath_uint4 n) {
		return stdmath_uint4_reflect(*self, n);
	}
	bool4 _approximately_equal(stdmath_uint4 o) {
		return stdmath_uint4_approximately_equal()
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

	uint32_t _get_element(size_t i) {
		return self->data[i];
	}

	uint32_t _set_element(size_t i, uint32_t value) {
		return self->data[i] = value;
	}
}
