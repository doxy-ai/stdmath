#ifndef __STDMATH_color8_H__
#define __STDMATH_color8_H__

#include "../util.h"

#ifndef STDMATH_MODULE
#include <stdint.h>
#include <stddef.h>
#endif

#include "byte4.h"
#include "bool4.h"

#ifdef __cplusplus
extern "C" {

STDMATH_EXPORT using stdmath_color8 = stdmath_byte4;
#else
typedef stdmath_byte4 stdmath_color8;
#endif

STDMATH_EXPORT stdmath_color8 stdmath_color8_broadcast(uint8_t all);
STDMATH_EXPORT stdmath_color8 stdmath_color8_from_hex_view(const char* hex, size_t len);
STDMATH_EXPORT stdmath_color8 stdmath_color8_from_hex(const char* hex);

STDMATH_EXPORT stdmath_bool4 stdmath_color8_equal_to(stdmath_color8 a, stdmath_color8 b);
STDMATH_EXPORT stdmath_bool4 stdmath_color8_not_equal_to(stdmath_color8 a, stdmath_color8 b);
STDMATH_EXPORT stdmath_bool4 stdmath_color8_less_than(stdmath_color8 a, stdmath_color8 b);
STDMATH_EXPORT stdmath_bool4 stdmath_color8_less_than_or_equal_to(stdmath_color8 a, stdmath_color8 b);
STDMATH_EXPORT stdmath_bool4 stdmath_color8_greater_than(stdmath_color8 a, stdmath_color8 b);
STDMATH_EXPORT stdmath_bool4 stdmath_color8_greater_than_or_equal_to(stdmath_color8 a, stdmath_color8 b);

STDMATH_EXPORT uint8_t stdmath_color8_min_element(stdmath_color8 color);
STDMATH_EXPORT uint8_t stdmath_color8_max_element(stdmath_color8 color);
STDMATH_EXPORT stdmath_color8 stdmath_color8_normalize(stdmath_color8 color);

STDMATH_EXPORT stdmath_color8 stdmath_color8_min(stdmath_color8 a, stdmath_color8 b);
STDMATH_EXPORT stdmath_color8 stdmath_color8_max(stdmath_color8 a, stdmath_color8 b);
STDMATH_EXPORT stdmath_color8 stdmath_color8_lerp(stdmath_color8 a, stdmath_color8 b, float t);
STDMATH_EXPORT stdmath_color8 stdmath_color8_clamp(stdmath_color8 a, stdmath_color8 min, stdmath_color8 max);
STDMATH_EXPORT stdmath_bool4 stdmath_color8_approximately_equal(stdmath_color8 a, stdmath_color8 b);

STDMATH_EXPORT stdmath_color8 stdmath_color8_srgb_to_linear_accurate(stdmath_color8 color);
STDMATH_EXPORT stdmath_color8 stdmath_color8_linear_to_srgb_accurate(stdmath_color8 color);
STDMATH_EXPORT stdmath_color8 stdmath_color8_gamma(stdmath_color8 color, float gamma);
STDMATH_EXPORT stdmath_color8 stdmath_color8_srgb_to_linear(stdmath_color8 color);
STDMATH_EXPORT stdmath_color8 stdmath_color8_linear_to_srgb(stdmath_color8 color);
STDMATH_EXPORT stdmath_color8 stdmath_color8_linear_to_hsv(stdmath_color8 color);
STDMATH_EXPORT stdmath_color8 stdmath_color8_hsv_to_linear(stdmath_color8 color);
STDMATH_EXPORT uint8_t stdmath_color8_luminance(stdmath_color8 color);
STDMATH_EXPORT stdmath_color8 stdmath_color8_linear_to_grayscale(stdmath_color8 color);
STDMATH_EXPORT stdmath_color8 stdmath_color8_linear_to_oklab(stdmath_color8 color);

STDMATH_EXPORT stdmath_color8 stdmath_color8_oklab_to_linear(stdmath_color8 color);
STDMATH_EXPORT stdmath_color8 stdmath_color8_blend_normal(stdmath_color8 a, stdmath_color8 b);
STDMATH_EXPORT stdmath_color8 stdmath_color8_blend_multiply(stdmath_color8 a, stdmath_color8 b);
STDMATH_EXPORT stdmath_color8 stdmath_color8_blend_darken(stdmath_color8 a, stdmath_color8 b);
STDMATH_EXPORT stdmath_color8 stdmath_color8_blend_color_burn(stdmath_color8 a, stdmath_color8 b);
STDMATH_EXPORT stdmath_color8 stdmath_color8_blend_screen(stdmath_color8 a, stdmath_color8 b);
STDMATH_EXPORT stdmath_color8 stdmath_color8_blend_lighten(stdmath_color8 a, stdmath_color8 b);
STDMATH_EXPORT stdmath_color8 stdmath_color8_blend_color_dodge(stdmath_color8 a, stdmath_color8 b);
STDMATH_EXPORT stdmath_color8 stdmath_color8_blend_overlay(stdmath_color8 a, stdmath_color8 b);
STDMATH_EXPORT stdmath_color8 stdmath_color8_blend_hard_light(stdmath_color8 a, stdmath_color8 b);
STDMATH_EXPORT stdmath_color8 stdmath_color8_blend_soft_light(stdmath_color8 a, stdmath_color8 b);
STDMATH_EXPORT stdmath_color8 stdmath_color8_blend_difference(stdmath_color8 a, stdmath_color8 b);
STDMATH_EXPORT stdmath_color8 stdmath_color8_blend_exclusion(stdmath_color8 a, stdmath_color8 b);
STDMATH_EXPORT stdmath_color8 stdmath_color8_blend_hue(stdmath_color8 a, stdmath_color8 b);
STDMATH_EXPORT stdmath_color8 stdmath_color8_blend_saturation(stdmath_color8 a, stdmath_color8 b);
STDMATH_EXPORT stdmath_color8 stdmath_color8_blend_color(stdmath_color8 a, stdmath_color8 b);
STDMATH_EXPORT stdmath_color8 stdmath_color8_blend_luminosity(stdmath_color8 a, stdmath_color8 b);

STDMATH_EXPORT stdmath_color8 stdmath_color8_premultiply_alpha(stdmath_color8 color);
STDMATH_EXPORT stdmath_color8 stdmath_color8_unpremultiply_alpha(stdmath_color8 color);
STDMATH_EXPORT stdmath_color8 stdmath_color8_exposure(stdmath_color8 color, float stops);
#if true
STDMATH_EXPORT union stdmath_float4 stdmath_color8_to_color32_normalized(stdmath_color8 color);
STDMATH_EXPORT union stdmath_float4 stdmath_color32_to_color32_normalized(union stdmath_float4 color) {
	assert(false && "Don't use this function... it exists purely so that the name exists for automatic bindings!");
	return {};
}
#else
STDMATH_EXPORT union stdmath_byte4 stdmath_color8_normalized_to_color8(stdmath_color8 color);
STDMATH_EXPORT union stdmath_byte4 stdmath_color8_normalized_to_color8(union stdmath_byte4 color) {
	assert(false && "Don't use this function... it exists purely so that the name exists for automatic bindings!");
	return {};
}
#endif
STDMATH_EXPORT stdmath_string_view stdmath_color8_linear_to_hex(stdmath_color8 color);
STDMATH_EXPORT stdmath_string_view stdmath_color8_linear_to_hex_include_alpha(stdmath_color8 color);
STDMATH_EXPORT stdmath_color8 stdmath_color8_saturate(stdmath_color8 color);

#ifdef __cplusplus
} // extern "C"
#endif

#ifdef STDMATH_IMPLEMENTATION
#ifndef __cplusplus
#error "The stdmath implementations require a C++ compiler"
#endif

#if true
#include "color32.h"
#else
#include "color8.h"
#endif

#ifndef STDMATH_MODULE
import stdmath.slang;
#endif

inline stdmath::color8 col(stdmath_color8 c) {
	return (stdmath::color8&)c;
}
inline stdmath_color8 c(stdmath::color8 c) {
	return (stdmath_color8&)c;
}

#ifdef __cplusplus
extern "C" {
#endif

stdmath_color8 stdmath_color8_broadcast(uint8_t all) {
	return c(stdmath::color8(all));
}
stdmath_color8 stdmath_color8_from_hex_view(const char* hex, size_t len) {
	return c(stdmath::color8::from_hex(std::string_view(hex, len)));
}
stdmath_color8 stdmath_color8_from_hex(const char* hex) {
	return stdmath_color8_from_hex_view(hex, strlen(hex));
}

stdmath_bool4 stdmath_color8_equal_to(stdmath_color8 a, stdmath_color8 b) {
	return c(c(a) == c(b));
}
stdmath_bool4 stdmath_color8_not_equal_to(stdmath_color8 a, stdmath_color8 b) {
	return c(c(a) != c(b));
}
stdmath_bool4 stdmath_color8_less_than(stdmath_color8 a, stdmath_color8 b) {
	return c(c(a) < c(b));
}
stdmath_bool4 stdmath_color8_less_than_or_equal_to(stdmath_color8 a, stdmath_color8 b) {
	return c(c(a) <= c(b));
}
stdmath_bool4 stdmath_color8_greater_than(stdmath_color8 a, stdmath_color8 b) {
	return c(c(a) > c(b));
}
stdmath_bool4 stdmath_color8_greater_than_or_equal_to(stdmath_color8 a, stdmath_color8 b) {
	return c(c(a) >= c(b));
}

uint8_t stdmath_color8_min_element(stdmath_color8 color) {
	return col(color).min_element();
}
uint8_t stdmath_color8_max_element(stdmath_color8 color) {
	return col(color).max_element();
}
stdmath_color8 stdmath_color8_normalize(stdmath_color8 color) {
	auto out = c(normalize(col(color).to_vector()));
	return (stdmath_color8&)out;
}


stdmath_color8 stdmath_color8_min(stdmath_color8 a, stdmath_color8 b) {
	return c(min(col(a), c(b)));
}
stdmath_color8 stdmath_color8_max(stdmath_color8 a, stdmath_color8 b) {
	return c(max(col(a), c(b)));
}
stdmath_color8 stdmath_color8_lerp(stdmath_color8 a, stdmath_color8 b, float t) {
	return c(lerp(col(a), c(b), t));
}
stdmath_color8 stdmath_color8_clamp(stdmath_color8 color, stdmath_color8 min, stdmath_color8 max) {
	return c(clamp(col(color), c(min), c(max)));
}
stdmath_bool4 stdmath_color8_approximately_equal(stdmath_color8 a, stdmath_color8 b) {
	return c(approximately_equal(col(a), c(b)));
}

stdmath_color8 stdmath_color8_srgb_to_linear_accurate(stdmath_color8 color) {
	return c(col(color).srgb_to_linear_accurate());
}
stdmath_color8 stdmath_color8_linear_to_srgb_accurate(stdmath_color8 color) {
	return c(col(color).linear_to_srgb_accurate());
}
stdmath_color8 stdmath_color8_gamma(stdmath_color8 color, float g) {
	return c(col(color).gamma(g));
}
stdmath_color8 stdmath_color8_srgb_to_linear(stdmath_color8 color) {
	return c(col(color).srgb_to_linear());
}
stdmath_color8 stdmath_color8_linear_to_srgb(stdmath_color8 color) {
	return c(col(color).linear_to_srgb());
}
stdmath_color8 stdmath_color8_linear_to_hsv(stdmath_color8 color) {
	return c(col(color).linear_to_hsv());
}
stdmath_color8 stdmath_color8_hsv_to_linear(stdmath_color8 color) {
	return c(col(color).hsv_to_linear());
}
uint8_t stdmath_color8_luminance(stdmath_color8 color) {
	return col(color).luminance();
}
stdmath_color8 stdmath_color8_linear_to_grayscale(stdmath_color8 color) {
	return c(col(color).linear_to_grayscale());
}
stdmath_color8 stdmath_color8_linear_to_oklab(stdmath_color8 color) {
	return c(col(color).linear_to_oklab());
}
stdmath_color8 stdmath_color8_oklab_to_linear(stdmath_color8 color) {
	return c(col(color).oklab_to_linear());
}

stdmath_color8 stdmath_color8_blend_normal(stdmath_color8 a, stdmath_color8 b) {
	return c(col(a).blend_normal(c(b)));
}
stdmath_color8 stdmath_color8_blend_multiply(stdmath_color8 a, stdmath_color8 b) {
	return c(col(a).blend_multiply(c(b)));
}
stdmath_color8 stdmath_color8_blend_darken(stdmath_color8 a, stdmath_color8 b) {
	return c(col(a).blend_darken(c(b)));
}
stdmath_color8 stdmath_color8_blend_color_burn(stdmath_color8 a, stdmath_color8 b) {
	return c(col(a).blend_color_burn(c(b)));
}
stdmath_color8 stdmath_color8_blend_screen(stdmath_color8 a, stdmath_color8 b) {
	return c(col(a).blend_screen(c(b)));
}
stdmath_color8 stdmath_color8_blend_lighten(stdmath_color8 a, stdmath_color8 b) {
	return c(col(a).blend_lighten(c(b)));
}
stdmath_color8 stdmath_color8_blend_color_dodge(stdmath_color8 a, stdmath_color8 b) {
	return c(col(a).blend_color_dodge(c(b)));
}
stdmath_color8 stdmath_color8_blend_overlay(stdmath_color8 a, stdmath_color8 b) {
	return c(col(a).blend_overlay(c(b)));
}
stdmath_color8 stdmath_color8_blend_hard_light(stdmath_color8 a, stdmath_color8 b) {
	return c(col(a).blend_hard_light(c(b)));
}
stdmath_color8 stdmath_color8_blend_soft_light(stdmath_color8 a, stdmath_color8 b) {
	return c(col(a).blend_soft_light(c(b)));
}
stdmath_color8 stdmath_color8_blend_difference(stdmath_color8 a, stdmath_color8 b) {
	return c(col(a).blend_difference(c(b)));
}
stdmath_color8 stdmath_color8_blend_exclusion(stdmath_color8 a, stdmath_color8 b) {
	return c(col(a).blend_exclusion(c(b)));
}
stdmath_color8 stdmath_color8_blend_hue(stdmath_color8 a, stdmath_color8 b) {
	return c(col(a).blend_hue(c(b)));
}
stdmath_color8 stdmath_color8_blend_saturation(stdmath_color8 a, stdmath_color8 b) {
	return c(col(a).blend_saturation(c(b)));
}
stdmath_color8 stdmath_color8_blend_color(stdmath_color8 a, stdmath_color8 b) {
	return c(col(a).blend_color(c(b)));
}
stdmath_color8 stdmath_color8_blend_luminosity(stdmath_color8 a, stdmath_color8 b) {
	return c(col(a).blend_luminosity(c(b)));
}

stdmath_color8 stdmath_color8_premultiply_alpha(stdmath_color8 color) {
	return c(col(color).premultiply_alpha());
}
stdmath_color8 stdmath_color8_unpremultiply_alpha(stdmath_color8 color) {
	return c(col(color).unpremultiply_alpha());
}
stdmath_color8 stdmath_color8_exposure(stdmath_color8 color, float stops) {
	return c(col(color).exposure(stops));
}
#if true
stdmath_float4 stdmath_color8_to_color32_normalized(stdmath_color8 color) {
	return c(col(color).color8_to_color32_normalized());
}
#else
stdmath_byte4 stdmath_color8_normalized_to_color8(stdmath_color8 color) {
	return c(col(color).color32_normalized_to_color8());
}
#endif
stdmath_string_view stdmath_color8_linear_to_hex(stdmath_color8 color) {
	auto str = col(color).linear_to_hex(false);
	auto out = (char*)malloc(str.size());
	auto len = str.size();
	memcpy(out, str.c_str(), len);
	return {out, len};
}
stdmath_string_view stdmath_color8_linear_to_hex_include_alpha(stdmath_color8 color) {
	auto str = col(color).linear_to_hex(true);
	auto out = (char*)malloc(str.size());
	auto len = str.size();
	memcpy(out, str.c_str(), len);
	return {out, len};
}
stdmath_color8 stdmath_color8_saturate(stdmath_color8 color) {
	return c(saturate(col(color)));
}

#ifdef __cplusplus
} // extern "C"
#endif

#endif // STDMATH_IMPLEMENTATION

#endif // __STDMATH_stdmath_color8_H__