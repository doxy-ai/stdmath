#ifndef __STDMATH_color32_H__
#define __STDMATH_color32_H__

#include "../util.h"

#ifndef STDMATH_MODULE
#include <stdint.h>
#include <stddef.h>
#endif

#include "float4.h"
#include "bool4.h"

#ifdef __cplusplus
extern "C" {

STDMATH_EXPORT using stdmath_color32 = stdmath_float4;
#else
typedef stdmath_float4 stdmath_color32;
#endif

STDMATH_EXPORT stdmath_color32 stdmath_color32_broadcast(float all);
STDMATH_EXPORT stdmath_color32 stdmath_color32_from_hex_view(const char* hex, size_t len);
STDMATH_EXPORT stdmath_color32 stdmath_color32_from_hex(const char* hex);

STDMATH_EXPORT stdmath_bool4 stdmath_color32_equal_to(stdmath_color32 a, stdmath_color32 b);
STDMATH_EXPORT stdmath_bool4 stdmath_color32_not_equal_to(stdmath_color32 a, stdmath_color32 b);
STDMATH_EXPORT stdmath_bool4 stdmath_color32_less_than(stdmath_color32 a, stdmath_color32 b);
STDMATH_EXPORT stdmath_bool4 stdmath_color32_less_than_or_equal_to(stdmath_color32 a, stdmath_color32 b);
STDMATH_EXPORT stdmath_bool4 stdmath_color32_greater_than(stdmath_color32 a, stdmath_color32 b);
STDMATH_EXPORT stdmath_bool4 stdmath_color32_greater_than_or_equal_to(stdmath_color32 a, stdmath_color32 b);

STDMATH_EXPORT float stdmath_color32_min_element(stdmath_color32 color);
STDMATH_EXPORT float stdmath_color32_max_element(stdmath_color32 color);
STDMATH_EXPORT stdmath_color32 stdmath_color32_normalize(stdmath_color32 color);

STDMATH_EXPORT stdmath_color32 stdmath_color32_min(stdmath_color32 a, stdmath_color32 b);
STDMATH_EXPORT stdmath_color32 stdmath_color32_max(stdmath_color32 a, stdmath_color32 b);
STDMATH_EXPORT stdmath_color32 stdmath_color32_lerp(stdmath_color32 a, stdmath_color32 b, float t);
STDMATH_EXPORT stdmath_color32 stdmath_color32_clamp(stdmath_color32 a, stdmath_color32 min, stdmath_color32 max);
STDMATH_EXPORT stdmath_bool4 stdmath_color32_approximately_equal(stdmath_color32 a, stdmath_color32 b);

STDMATH_EXPORT stdmath_color32 stdmath_color32_srgb_to_linear_accurate(stdmath_color32 color);
STDMATH_EXPORT stdmath_color32 stdmath_color32_linear_to_srgb_accurate(stdmath_color32 color);
STDMATH_EXPORT stdmath_color32 stdmath_color32_gamma(stdmath_color32 color, float gamma);
STDMATH_EXPORT stdmath_color32 stdmath_color32_srgb_to_linear(stdmath_color32 color);
STDMATH_EXPORT stdmath_color32 stdmath_color32_linear_to_srgb(stdmath_color32 color);
STDMATH_EXPORT stdmath_color32 stdmath_color32_linear_to_hsv(stdmath_color32 color);
STDMATH_EXPORT stdmath_color32 stdmath_color32_hsv_to_linear(stdmath_color32 color);
STDMATH_EXPORT float stdmath_color32_luminance(stdmath_color32 color);
STDMATH_EXPORT stdmath_color32 stdmath_color32_linear_to_grayscale(stdmath_color32 color);
STDMATH_EXPORT stdmath_color32 stdmath_color32_linear_to_oklab(stdmath_color32 color);

STDMATH_EXPORT stdmath_color32 stdmath_color32_oklab_to_linear(stdmath_color32 color);
STDMATH_EXPORT stdmath_color32 stdmath_color32_blend_normal(stdmath_color32 a, stdmath_color32 b);
STDMATH_EXPORT stdmath_color32 stdmath_color32_blend_multiply(stdmath_color32 a, stdmath_color32 b);
STDMATH_EXPORT stdmath_color32 stdmath_color32_blend_darken(stdmath_color32 a, stdmath_color32 b);
STDMATH_EXPORT stdmath_color32 stdmath_color32_blend_color_burn(stdmath_color32 a, stdmath_color32 b);
STDMATH_EXPORT stdmath_color32 stdmath_color32_blend_screen(stdmath_color32 a, stdmath_color32 b);
STDMATH_EXPORT stdmath_color32 stdmath_color32_blend_lighten(stdmath_color32 a, stdmath_color32 b);
STDMATH_EXPORT stdmath_color32 stdmath_color32_blend_color_dodge(stdmath_color32 a, stdmath_color32 b);
STDMATH_EXPORT stdmath_color32 stdmath_color32_blend_overlay(stdmath_color32 a, stdmath_color32 b);
STDMATH_EXPORT stdmath_color32 stdmath_color32_blend_hard_light(stdmath_color32 a, stdmath_color32 b);
STDMATH_EXPORT stdmath_color32 stdmath_color32_blend_soft_light(stdmath_color32 a, stdmath_color32 b);
STDMATH_EXPORT stdmath_color32 stdmath_color32_blend_difference(stdmath_color32 a, stdmath_color32 b);
STDMATH_EXPORT stdmath_color32 stdmath_color32_blend_exclusion(stdmath_color32 a, stdmath_color32 b);
STDMATH_EXPORT stdmath_color32 stdmath_color32_blend_hue(stdmath_color32 a, stdmath_color32 b);
STDMATH_EXPORT stdmath_color32 stdmath_color32_blend_saturation(stdmath_color32 a, stdmath_color32 b);
STDMATH_EXPORT stdmath_color32 stdmath_color32_blend_color(stdmath_color32 a, stdmath_color32 b);
STDMATH_EXPORT stdmath_color32 stdmath_color32_blend_luminosity(stdmath_color32 a, stdmath_color32 b);

STDMATH_EXPORT stdmath_color32 stdmath_color32_premultiply_alpha(stdmath_color32 color);
STDMATH_EXPORT stdmath_color32 stdmath_color32_unpremultiply_alpha(stdmath_color32 color);
STDMATH_EXPORT stdmath_color32 stdmath_color32_exposure(stdmath_color32 color, float stops);
#if false
STDMATH_EXPORT union stdmath_float4 stdmath_color32_to_color32_normalized(stdmath_color32 color);
STDMATH_EXPORT union stdmath_float4 stdmath_color32_to_color32_normalized(union stdmath_float4 color);
#else
STDMATH_EXPORT union stdmath_byte4 stdmath_color32_normalized_to_color8(stdmath_color32 color);
STDMATH_EXPORT union stdmath_byte4 stdmath_color8_normalized_to_color8(union stdmath_byte4 color);
#endif
STDMATH_EXPORT stdmath_string_view stdmath_color32_linear_to_hex(stdmath_color32 color);
STDMATH_EXPORT stdmath_string_view stdmath_color32_linear_to_hex_include_alpha(stdmath_color32 color);
STDMATH_EXPORT stdmath_color32 stdmath_color32_saturate(stdmath_color32 color);

STDMATH_EXPORT stdmath_string_view stdmath_color32_to_string(stdmath_color32 color);

#ifdef __cplusplus
} // extern "C"
#endif

#ifdef STDMATH_IMPLEMENTATION
#ifndef __cplusplus
#error "The stdmath implementations require a C++ compiler"
#endif

#if false
#include "color32.h"
#else
#include "color8.h"
#endif

#ifndef STDMATH_MODULE
import stdmath.slang;
#endif

inline stdmath::color32 col(stdmath_color32 c) {
	return (stdmath::color32&)c;
}
inline stdmath_color32 col(stdmath::color32 c) {
	return (stdmath_color32&)c;
}

#ifdef __cplusplus
extern "C" {
#endif

stdmath_color32 stdmath_color32_broadcast(float all) {
	return col(stdmath::color32(all));
}
stdmath_color32 stdmath_color32_from_hex_view(const char* hex, size_t len) {
	return col(stdmath::color32::from_hex(std::string_view(hex, len)));
}
stdmath_color32 stdmath_color32_from_hex(const char* hex) {
	return stdmath_color32_from_hex_view(hex, strlen(hex));
}

stdmath_bool4 stdmath_color32_equal_to(stdmath_color32 a, stdmath_color32 b) {
	auto tmp = c(a) == c(b);
	return (stdmath_bool4&)tmp;
}
stdmath_bool4 stdmath_color32_not_equal_to(stdmath_color32 a, stdmath_color32 b) {
	auto tmp = c(a) != c(b);
	return (stdmath_bool4&)tmp;
}
stdmath_bool4 stdmath_color32_less_than(stdmath_color32 a, stdmath_color32 b) {
	auto tmp = c(a) < c(b);
	return (stdmath_bool4&)tmp;
}
stdmath_bool4 stdmath_color32_less_than_or_equal_to(stdmath_color32 a, stdmath_color32 b) {
	auto tmp = c(a) <= c(b);
	return (stdmath_bool4&)tmp;
}
stdmath_bool4 stdmath_color32_greater_than(stdmath_color32 a, stdmath_color32 b) {
	auto tmp = c(a) > c(b);
	return (stdmath_bool4&)tmp;
}
stdmath_bool4 stdmath_color32_greater_than_or_equal_to(stdmath_color32 a, stdmath_color32 b) {
	auto tmp = c(a) >= c(b);
	return (stdmath_bool4&)tmp;
}

float stdmath_color32_min_element(stdmath_color32 color) {
	return col(color).min_element();
}
float stdmath_color32_max_element(stdmath_color32 color) {
	return col(color).max_element();
}
stdmath_color32 stdmath_color32_normalize(stdmath_color32 color) {
	return col((stdmath::color32)normalize(col(color).to_vector()));
}


stdmath_color32 stdmath_color32_min(stdmath_color32 a, stdmath_color32 b) {
	return col((stdmath::color32)min(col(a), col(b)));
}
stdmath_color32 stdmath_color32_max(stdmath_color32 a, stdmath_color32 b) {
	return col((stdmath::color32)max(col(a), col(b)));
}
stdmath_color32 stdmath_color32_lerp(stdmath_color32 a, stdmath_color32 b, float t) {
	return col((stdmath::color32)lerp(col(a), col(b), t));
}
stdmath_color32 stdmath_color32_clamp(stdmath_color32 color, stdmath_color32 min, stdmath_color32 max) {
	return col((stdmath::color32)clamp(col(color), col(min), col(max)));
}
stdmath_bool4 stdmath_color32_approximately_equal(stdmath_color32 a, stdmath_color32 b) {
	return c((stdmath::bool4)approximately_equal(col(a), col(b)));
}

stdmath_color32 stdmath_color32_srgb_to_linear_accurate(stdmath_color32 color) {
	return col(col(color).srgb_to_linear_accurate());
}
stdmath_color32 stdmath_color32_linear_to_srgb_accurate(stdmath_color32 color) {
	return col(col(color).linear_to_srgb_accurate());
}
stdmath_color32 stdmath_color32_gamma(stdmath_color32 color, float g) {
	return col(col(color).gamma(g));
}
stdmath_color32 stdmath_color32_srgb_to_linear(stdmath_color32 color) {
	return col(col(color).srgb_to_linear());
}
stdmath_color32 stdmath_color32_linear_to_srgb(stdmath_color32 color) {
	return col(col(color).linear_to_srgb());
}
stdmath_color32 stdmath_color32_linear_to_hsv(stdmath_color32 color) {
	return col(col(color).linear_to_hsv());
}
stdmath_color32 stdmath_color32_hsv_to_linear(stdmath_color32 color) {
	return col(col(color).hsv_to_linear());
}
float stdmath_color32_luminance(stdmath_color32 color) {
	return col(color).luminance();
}
stdmath_color32 stdmath_color32_linear_to_grayscale(stdmath_color32 color) {
	return col(col(color).linear_to_grayscale());
}
stdmath_color32 stdmath_color32_linear_to_oklab(stdmath_color32 color) {
	return col(col(color).linear_to_oklab());
}
stdmath_color32 stdmath_color32_oklab_to_linear(stdmath_color32 color) {
	return col(col(color).oklab_to_linear());
}

stdmath_color32 stdmath_color32_blend_normal(stdmath_color32 a, stdmath_color32 b) {
	return col(col(a).blend_normal(col(b)));
}
stdmath_color32 stdmath_color32_blend_multiply(stdmath_color32 a, stdmath_color32 b) {
	return col(col(a).blend_multiply(col(b)));
}
stdmath_color32 stdmath_color32_blend_darken(stdmath_color32 a, stdmath_color32 b) {
	return col(col(a).blend_darken(col(b)));
}
stdmath_color32 stdmath_color32_blend_color_burn(stdmath_color32 a, stdmath_color32 b) {
	return col(col(a).blend_color_burn(col(b)));
}
stdmath_color32 stdmath_color32_blend_screen(stdmath_color32 a, stdmath_color32 b) {
	return col(col(a).blend_screen(col(b)));
}
stdmath_color32 stdmath_color32_blend_lighten(stdmath_color32 a, stdmath_color32 b) {
	return col(col(a).blend_lighten(col(b)));
}
stdmath_color32 stdmath_color32_blend_color_dodge(stdmath_color32 a, stdmath_color32 b) {
	return col(col(a).blend_color_dodge(col(b)));
}
stdmath_color32 stdmath_color32_blend_overlay(stdmath_color32 a, stdmath_color32 b) {
	return col(col(a).blend_overlay(col(b)));
}
stdmath_color32 stdmath_color32_blend_hard_light(stdmath_color32 a, stdmath_color32 b) {
	return col(col(a).blend_hard_light(col(b)));
}
stdmath_color32 stdmath_color32_blend_soft_light(stdmath_color32 a, stdmath_color32 b) {
	return col(col(a).blend_soft_light(col(b)));
}
stdmath_color32 stdmath_color32_blend_difference(stdmath_color32 a, stdmath_color32 b) {
	return col(col(a).blend_difference(col(b)));
}
stdmath_color32 stdmath_color32_blend_exclusion(stdmath_color32 a, stdmath_color32 b) {
	return col(col(a).blend_exclusion(col(b)));
}
stdmath_color32 stdmath_color32_blend_hue(stdmath_color32 a, stdmath_color32 b) {
	return col(col(a).blend_hue(col(b)));
}
stdmath_color32 stdmath_color32_blend_saturation(stdmath_color32 a, stdmath_color32 b) {
	return col(col(a).blend_saturation(col(b)));
}
stdmath_color32 stdmath_color32_blend_color(stdmath_color32 a, stdmath_color32 b) {
	return col(col(a).blend_color(col(b)));
}
stdmath_color32 stdmath_color32_blend_luminosity(stdmath_color32 a, stdmath_color32 b) {
	return col(col(a).blend_luminosity(col(b)));
}

stdmath_color32 stdmath_color32_premultiply_alpha(stdmath_color32 color) {
	return col(col(color).premultiply_alpha());
}
stdmath_color32 stdmath_color32_unpremultiply_alpha(stdmath_color32 color) {
	return col(col(color).unpremultiply_alpha());
}
stdmath_color32 stdmath_color32_exposure(stdmath_color32 color, float stops) {
	return col(col(color).exposure(stops));
}
#if false
stdmath_float4 stdmath_color32_to_color32_normalized(stdmath_color32 color) {
	auto tmp = col(color).color8_to_color32_normalized();
	return (stdmath_float4&)tmp;
}
stdmath_float4 stdmath_color32_to_color32_normalized(union stdmath_float4 color) {
	assert(false && "Don't use this function... it exists purely so that the name exists for automatic bindings!");
	return color;
}
#else
stdmath_byte4 stdmath_color32_normalized_to_color8(stdmath_color32 color) {
	auto tmp = col(color).color32_normalized_to_color8();
	return (stdmath_byte4&)tmp;
}
stdmath_byte4 stdmath_color8_normalized_to_color8(union stdmath_byte4 color) {
	assert(false && "Don't use this function... it exists purely so that the name exists for automatic bindings!");
	return color;
}
#endif
stdmath_string_view stdmath_color32_linear_to_hex(stdmath_color32 color) {
	auto str = col(color).linear_to_hex(false);
	auto len = str.size();
	auto out = (char*)malloc(len);
	memcpy(out, str.c_str(), len);
	return {out, len};
}
stdmath_string_view stdmath_color32_linear_to_hex_include_alpha(stdmath_color32 color) {
	auto str = col(color).linear_to_hex(true);
	auto len = str.size();
	auto out = (char*)malloc(len);
	memcpy(out, str.c_str(), len);
	return {out, len};
}
stdmath_color32 stdmath_color32_saturate(stdmath_color32 color) {
	return col(saturate(col(color)));
}

stdmath_string_view stdmath_color32_to_string(stdmath_color32 color) {
	auto str = std::format("{}", col(color));
	auto len = str.size();
	auto out = (char*)malloc(len);
	memcpy(out, str.c_str(), len);
	return {out, len};
}

#ifdef __cplusplus
} // extern "C"
#endif

#endif // STDMATH_IMPLEMENTATION

#endif // __STDMATH_stdmath_color32_H__