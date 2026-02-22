#define STDMATH_EXPORT
#define STDMATH_INLINE
%include cstring.i
%include byte4.i

%rename(from_hex) _from_hex;
%rename(min_element) _min_element;
%rename(max_element) _max_element;
%rename(normalize) _normalize;
%rename(min) _min;
%rename(max) _max;
%rename(lerp) _lerp;
%rename(clamp) _clamp;
%rename(approximately_equal) _approximately_equal;
%rename(srgb_to_linear_accurate) _srgb_to_linear_accurate;
%rename(linear_to_srgb_accurate) _linear_to_srgb_accurate;
%rename(gamma) _gamma;
%rename(srgb_to_linear) _srgb_to_linear;
%rename(linear_to_srgb) _linear_to_srgb;
%rename(linear_to_hsv) _linear_to_hsv;
%rename(hsv_to_linear) _hsv_to_linear;
%rename(luminance) _luminance;
%rename(linear_to_grayscale) _linear_to_grayscale;
%rename(linear_to_oklab) _linear_to_oklab;
%rename(oklab_to_linear) _oklab_to_linear;
%rename(blend_normal) _blend_normal;
%rename(blend_multiply) _blend_multiply;
%rename(blend_darken) _blend_darken;
%rename(blend_color_burn) _blend_color_burn;
%rename(blend_screen) _blend_screen;
%rename(blend_lighten) _blend_lighten;
%rename(blend_color_dodge) _blend_color_dodge;
%rename(blend_overlay) _blend_overlay;
%rename(blend_hard_light) _blend_hard_light;
%rename(blend_soft_light) _blend_soft_light;
%rename(blend_difference) _blend_difference;
%rename(blend_exclusion) _blend_exclusion;
%rename(blend_hue) _blend_hue;
%rename(blend_saturation) _blend_saturation;
%rename(blend_color) _blend_color;
%rename(blend_luminosity) _blend_luminosity;
%rename(premultiply_alpha) _premultiply_alpha;
%rename(unpremultiply_alpha) _unpremultiply_alpha;
%rename(exposure) _exposure;
%rename(to_color32_normalized) _to_color32_normalized;
%rename(normalized_to_color8) _normalized_to_color8;
%rename(linear_to_hex) _linear_to_hex;
%rename(linear_to_hex_include_alpha) _linear_to_hex_include_alpha;
%rename(saturate) _saturate;

%rename(color8) stdmath_color8;
struct stdmath_color8: stdmath_byte4 {};
%extend stdmath_color8 {
	stdmath_color8(uint8_t r = 0, uint8_t g = 0, uint8_t b = 0, uint8_t a = 0) {
		stdmath_color8 *c;
		c = (stdmath_color8*) malloc(sizeof(stdmath_color8));
		c->r = r;
		c->g = g;
		c->b = b;
		c->a = a;
		return c;
	}
	stdmath_color8(uint8_t all) {
		stdmath_color8 *c;
		c = (stdmath_color8*) malloc(sizeof(stdmath_color8));
		*c = stdmath_color8_broadcast(all);
		return c;
	}

	%cstring_input_binary(const char* hex, size_t hex_size);
	static stdmath_color8 _from_hex(const char* hex, size_t hex_size) {
		return stdmath_color8_from_hex_view(hex, hex_size);
	}

	stdmath_byte4 to_vector() {
		return *(stdmath_byte4*)self;
	}

	stdmath_bool4 _equal_to(stdmath_color8 o) {
		return stdmath_color8_equal_to(*self, o);
	}
	stdmath_bool4 _not_equal_to(stdmath_color8 o) {
		return stdmath_color8_not_equal_to(*self, o);
	}
	stdmath_bool4 _less_than(stdmath_color8 o) {
		return stdmath_color8_less_than(*self, o);
	}
	stdmath_bool4 _less_than_or_equal_to(stdmath_color8 o) {
		return stdmath_color8_less_than_or_equal_to(*self, o);
	}
	stdmath_bool4 _greater_than(stdmath_color8 o) {
		return stdmath_color8_greater_than(*self, o);
	}
	stdmath_bool4 _greater_than_or_equal_to(stdmath_color8 o) {
		return stdmath_color8_greater_than_or_equal_to(*self, o);
	}

	uint8_t stdmath_color8_min_element() {
		return stdmath_color8_min_element(*self);
	}
	uint8_t stdmath_color8_max_element() {
		return stdmath_color8_max_element(*self);
	}
	stdmath_color8 stdmath_color8_normalize() {
		return stdmath_color8_normalize(*self);
	}

	stdmath_color8 _min(stdmath_color8 o) {
		return stdmath_color8_min(*self, o);
	}
	stdmath_color8 _max(stdmath_color8 o) {
		return stdmath_color8_max(*self, o);
	}
	stdmath_color8 _lerp(stdmath_color8 o, float t) {
		return stdmath_color8_lerp(*self, o, t);
	}
	stdmath_color8 _clamp(stdmath_color8 min, stdmath_color8 max) {
		return stdmath_color8_clamp(*self, min, max);
	}
	stdmath_bool4 _approximately_equal(stdmath_color8 o) {
		return stdmath_color8_approximately_equal(*self, o);
	}

	stdmath_color8 _srgb_to_linear_accurate() {
		return stdmath_color8_srgb_to_linear_accurate(*self);
	}
	stdmath_color8 _linear_to_srgb_accurate() {
		return stdmath_color8_linear_to_srgb_accurate(*self);
	}
	stdmath_color8 _gamma(float g) {
		return stdmath_color8_gamma(*self, g);
	}
	stdmath_color8 _srgb_to_linear() {
		return stdmath_color8_srgb_to_linear(*self);
	}
	stdmath_color8 _linear_to_srgb() {
		return stdmath_color8_linear_to_srgb(*self);
	}
	stdmath_color8 _linear_to_hsv() {
		return stdmath_color8_linear_to_hsv(*self);
	}
	stdmath_color8 _hsv_to_linear() {
		return stdmath_color8_hsv_to_linear(*self);
	}
	uint8_t _luminance() {
		return stdmath_color8_luminance(*self);
	}
	stdmath_color8 _linear_to_grayscale() {
		return stdmath_color8_linear_to_grayscale(*self);
	}
	stdmath_color8 _linear_to_oklab() {
		return stdmath_color8_linear_to_oklab(*self);
	}
	stdmath_color8 _oklab_to_linear() {
		return stdmath_color8_oklab_to_linear(*self);
	}

	stdmath_color8 _blend_normal(stdmath_color8 o) {
		return stdmath_color8_blend_normal(*self, o);
	}
	stdmath_color8 _blend_multiply(stdmath_color8 o) {
		return stdmath_color8_blend_multiply(*self, o);
	}
	stdmath_color8 _blend_darken(stdmath_color8 o) {
		return stdmath_color8_blend_darken(*self, o);
	}
	stdmath_color8 _blend_color_burn(stdmath_color8 o) {
		return stdmath_color8_blend_color_burn(*self, o);
	}
	stdmath_color8 _blend_screen(stdmath_color8 o) {
		return stdmath_color8_blend_screen(*self, o);
	}
	stdmath_color8 _blend_lighten(stdmath_color8 o) {
		return stdmath_color8_blend_lighten(*self, o);
	}
	stdmath_color8 _blend_color_dodge(stdmath_color8 o) {
		return stdmath_color8_blend_color_dodge(*self, o);
	}
	stdmath_color8 _blend_overlay(stdmath_color8 o) {
		return stdmath_color8_blend_overlay(*self, o);
	}
	stdmath_color8 _blend_hard_light(stdmath_color8 o) {
		return stdmath_color8_blend_hard_light(*self, o);
	}
	stdmath_color8 _blend_soft_light(stdmath_color8 o) {
		return stdmath_color8_blend_soft_light(*self, o);
	}
	stdmath_color8 _blend_difference(stdmath_color8 o) {
		return stdmath_color8_blend_difference(*self, o);
	}
	stdmath_color8 _blend_exclusion(stdmath_color8 o) {
		return stdmath_color8_blend_exclusion(*self, o);
	}
	stdmath_color8 _blend_hue(stdmath_color8 o) {
		return stdmath_color8_blend_hue(*self, o);
	}
	stdmath_color8 _blend_saturation(stdmath_color8 o) {
		return stdmath_color8_blend_saturation(*self, o);
	}
	stdmath_color8 _blend_color(stdmath_color8 o) {
		return stdmath_color8_blend_color(*self, o);
	}
	stdmath_color8 _blend_luminosity(stdmath_color8 o) {
		return stdmath_color8_blend_luminosity(*self, o);
	}

	stdmath_color8 _premultiply_alpha() {
		return stdmath_color8_premultiply_alpha(*self);
	}
	stdmath_color8 _unpremultiply_alpha() {
		return stdmath_color8_unpremultiply_alpha(*self);
	}
	stdmath_color8 _exposure(float stops) {
		return stdmath_color8_exposure(*self, stops);
	}

	stdmath_float4 _to_color32_normalized() {
		if constexpr(true)
			return stdmath_color8_to_color32_normalized(*self);
		else return *(stdmath_float4*)self;
	}
	stdmath_byte4 _normalized_to_color8() {
		if constexpr(true)
			return *(stdmath_byte4*)self;
		else return stdmath_color8_normalized_to_color8(*self);
	}
	%cstring_output_allocate_size(const char** str, size_t* len, free(*$1))
	void _linear_to_hex(const char** str, size_t* len) {
		auto out = stdmath_color8_linear_to_hex(*self);
		*str = out.data;
		*len = out.len;
	}
	// %cstring_output_allocate_size(char** str, size_t* len, free(*$1))
	void _linear_to_hex_include_alpha(const char** str, size_t* len) {
		auto out = stdmath_color8_linear_to_hex_include_alpha(*self);
		*str = out.data;
		*len = out.len;
	}
	stdmath_color8 _saturate() {
		return stdmath_color8_saturate(*self);
	}
};

