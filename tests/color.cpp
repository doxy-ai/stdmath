#include <doctest/doctest.h>
#include <math/namespace_alias.hpp>

#include "util.hpp"

TEST_CASE("color basics") {
	std::math::color32 c1(1, 0.5f, 0, 1);
	CHECK(c1.r == 1);
	CHECK(c1.g == 0.5f);
	CHECK(c1.b == 0);
	CHECK(c1.a == 1);

	std::math::color8 c2(255, 127, 0, 255);
	CHECK(c2.r == 255);
	CHECK(c2.g == 127);
	CHECK(c2.b == 0);
	CHECK(c2.a == 255);
}

TEST_CASE("color from_hex") {
	auto c1 = std::math::color32::from_hex("#ff8000");
	CHECK(ceq(c1.r, 1));
	CHECK(ceq(c1.g, 128.f / 255));
	CHECK(ceq(c1.b, 0));
	CHECK(c1.a == 1);

	auto c2 = std::math::color32::from_hex("f00");
	CHECK(c2.r == 1);
	CHECK(c2.g == 0);
	CHECK(c2.b == 0);

	auto c3 = std::math::color8::from_hex("#ff8000ff");
	CHECK(c3.r == 255);
	CHECK(c3.g == 128);
	CHECK(c3.b == 0);
	CHECK(c3.a == 255);

	std::cout << c3 << std::endl;
	std::println("{}", c3);
}

TEST_CASE("color sRGB/Linear conversions") {
	std::math::color32 c(0.5f, 0.5f, 0.5f, 1);

	auto linear = c.srgb_to_linear_accurate();
	// 0.5 sRGB is approx 0.21404 linear
	CHECK(ceq(linear.r, 0.214041f));

	auto srgb = linear.linear_to_srgb_accurate();
	CHECK(ceq(srgb.r, 0.5f));

	auto fast_linear = c.srgb_to_linear(); // gamma 2.2
	CHECK(ceq(fast_linear.r, std::pow(0.5f, 2.2f)));
}

TEST_CASE("color HSV conversion") {
	std::math::color32 red(1, 0, 0, 1);
	auto hsv = red.linear_to_hsv();
	CHECK(hsv.x == 0); // Hue
	CHECK(hsv.y == 1); // Saturation
	CHECK(hsv.z == 1); // Value

	auto back_to_red = hsv.hsv_to_linear();
	CHECK(back_to_red.r == 1);
	CHECK(back_to_red.g == 0);
	CHECK(back_to_red.b == 0);
}

TEST_CASE("color luminance and grayscale") {
	std::math::color32 c(1, 1, 0, 1); // Yellow
	float lum = c.luminance();
	CHECK(ceq(lum, 0.2126f + 0.7152f));

	auto gray = c.linear_to_grayscale();
	CHECK(gray.r == lum);
	CHECK(gray.g == lum);
	CHECK(gray.b == lum);
}

TEST_CASE("color oklab") {
	std::math::color32 red(1, 0, 0, 1);
	auto oklab = red.linear_to_oklab();
	auto back = oklab.oklab_to_linear();

	CHECK(ceq(back.r, 1));
	CHECK(ceq(back.g, 0, 1e-5f));
	CHECK(ceq(back.b, 0, 1e-5f));
}

TEST_CASE("color alpha operations") {
	std::math::color32 c(1, 0.5f, 0, 0.5f);
	auto premul = c.premultiply_alpha();
	CHECK(premul.r == 0.5f);
	CHECK(premul.g == 0.25f);
	CHECK(premul.a == 0.5f);

	auto unpremul = premul.unpremultiply_alpha();
	CHECK(unpremul.r == 1);
	CHECK(unpremul.g == 0.5f);
}

TEST_CASE("color normalization") {
	std::math::color8 c8(255, 127, 0, 255);
	std::math::color32 c32 = std::math::normalize(c8);

	CHECK(c32.r == 1);
	CHECK(ceq(c32.g, 127.f / 255));

	std::math::color8 back = std::math::denormalize(c32);
	CHECK(back.r == 255);
	CHECK(back.g == 127);
}

TEST_CASE("color hex output") {
	std::math::color8 c8(255, 128, 0, 255);
	CHECK(c8.linear_to_hex() == "#ff8000");
	CHECK(c8.linear_to_hex(true) == "#ff8000ff");
}

TEST_CASE("blend normal") {
	// Fully opaque src should completely replace dst
	std::math::color32 src(1, 0, 0, 1);
	std::math::color32 dst(0, 0, 1, 1);
	auto result = src.blend_normal(dst);
	CHECK(ceq(result.r, 1));
	CHECK(ceq(result.g, 0));
	CHECK(ceq(result.b, 0));
	CHECK(ceq(result.a, 1));

	// 50% transparent src over opaque dst should alpha-composite correctly
	std::math::color32 half_src(1, 0, 0, 0.5f);
	auto blended = half_src.blend_normal(dst);
	// out_a = 0.5 + 1*(1-0.5) = 1.0
	CHECK(ceq(blended.a, 1.0f));
	// r = (0.5*1 + 1*0*(1-0.5)) / 1 = 0.5
	CHECK(ceq(blended.r, 0.5f));
	// b = (0.5*0 + 1*1*(1-0.5)) / 1 = 0.5
	CHECK(ceq(blended.b, 0.5f));
}

TEST_CASE("blend normal - transparent src") {
	// Fully transparent src should leave dst unchanged
	std::math::color32 src(1, 0, 0, 0);
	std::math::color32 dst(0, 1, 0, 1);
	auto result = src.blend_normal(dst);
	CHECK(ceq(result.r, 0));
	CHECK(ceq(result.g, 1));
	CHECK(ceq(result.b, 0));
	CHECK(ceq(result.a, 1));
}

TEST_CASE("blend multiply") {
	// Multiplying by white (1,1,1) leaves dst unchanged
	std::math::color32 white(1, 1, 1, 1);
	std::math::color32 dst(0.5f, 0.25f, 0.75f, 1);
	auto result = white.blend_multiply(dst);
	CHECK(ceq(result.r, 0.5f));
	CHECK(ceq(result.g, 0.25f));
	CHECK(ceq(result.b, 0.75f));

	// Multiplying by black (0,0,0) yields black
	std::math::color32 black(0, 0, 0, 1);
	auto dark = black.blend_multiply(dst);
	CHECK(ceq(dark.r, 0));
	CHECK(ceq(dark.g, 0));
	CHECK(ceq(dark.b, 0));

	// General case: 0.5 * 0.5 = 0.25
	std::math::color32 src(0.5f, 0.5f, 0.5f, 1);
	std::math::color32 dst2(0.5f, 0.5f, 0.5f, 1);
	auto mid = src.blend_multiply(dst2);
	CHECK(ceq(mid.r, 0.25f));
}

TEST_CASE("blend screen") {
	// Screen with black leaves dst unchanged
	std::math::color32 black(0, 0, 0, 1);
	std::math::color32 dst(0.5f, 0.25f, 0.75f, 1);
	auto result = black.blend_screen(dst);
	CHECK(ceq(result.r, 0.5f));
	CHECK(ceq(result.g, 0.25f));
	CHECK(ceq(result.b, 0.75f));

	// Screen with white always yields white
	std::math::color32 white(1, 1, 1, 1);
	auto bright = white.blend_screen(dst);
	CHECK(ceq(bright.r, 1));
	CHECK(ceq(bright.g, 1));
	CHECK(ceq(bright.b, 1));

	// General: s + d - s*d = 0.5 + 0.5 - 0.25 = 0.75
	std::math::color32 src(0.5f, 0.5f, 0.5f, 1);
	std::math::color32 dst2(0.5f, 0.5f, 0.5f, 1);
	auto mid = src.blend_screen(dst2);
	CHECK(ceq(mid.r, 0.75f));
}

TEST_CASE("blend multiply and screen are complementary") {
	// For any s, d: screen(s,d) == 1 - multiply(1-s, 1-d)
	std::math::color32 src(0.3f, 0.6f, 0.9f, 1);
	std::math::color32 dst(0.7f, 0.4f, 0.2f, 1);

	auto screened = src.blend_screen(dst);
	std::math::color32 inv_src(1-0.3f, 1-0.6f, 1-0.9f, 1);
	std::math::color32 inv_dst(1-0.7f, 1-0.4f, 1-0.2f, 1);
	auto multiplied = inv_src.blend_multiply(inv_dst);

	CHECK(ceq(screened.r, 1 - multiplied.r));
	CHECK(ceq(screened.g, 1 - multiplied.g));
	CHECK(ceq(screened.b, 1 - multiplied.b));
}

TEST_CASE("blend darken / lighten") {
	std::math::color32 src(0.3f, 0.7f, 0.5f, 1);
	std::math::color32 dst(0.6f, 0.4f, 0.5f, 1);

	auto dark = src.blend_darken(dst);
	CHECK(ceq(dark.r, 0.3f)); // src darker
	CHECK(ceq(dark.g, 0.4f)); // dst darker
	CHECK(ceq(dark.b, 0.5f)); // equal

	auto light = src.blend_lighten(dst);
	CHECK(ceq(light.r, 0.6f)); // dst lighter
	CHECK(ceq(light.g, 0.7f)); // src lighter
	CHECK(ceq(light.b, 0.5f)); // equal
}

TEST_CASE("blend overlay") {
	// Dark dst (< 0.5): result = 2 * src * dst
	std::math::color32 src(0.5f, 0.5f, 0.5f, 1);
	std::math::color32 dark_dst(0.25f, 0.25f, 0.25f, 1);
	auto dark_result = src.blend_overlay(dark_dst);
	CHECK(ceq(dark_result.r, 2 * 0.5f * 0.25f));

	// Light dst (> 0.5): result = 1 - 2*(1-src)*(1-dst)
	std::math::color32 light_dst(0.75f, 0.75f, 0.75f, 1);
	auto light_result = src.blend_overlay(light_dst);
	CHECK(ceq(light_result.r, 1 - 2 * 0.5f * 0.25f));

	// Neutral grey src (0.5) leaves dst unchanged
	std::math::color32 dst(0.3f, 0.6f, 0.8f, 1);
	auto neutral = src.blend_overlay(dst);
	CHECK(ceq(neutral.r, 2 * 0.5f * 0.3f)); // dark branch
	CHECK(ceq(neutral.g, 1 - 2 * 0.5f * (1-0.6f))); // light branch
}

TEST_CASE("blend hard light is overlay with roles swapped") {
	// hard_light(src→dst) == overlay(dst→src) channel-wise
	std::math::color32 src(0.3f, 0.7f, 0.5f, 1);
	std::math::color32 dst(0.6f, 0.4f, 0.8f, 1);

	auto hl = src.blend_hard_light(dst);
	auto ov = dst.blend_overlay(src); // roles swapped

	CHECK(ceq(hl.r, ov.r));
	CHECK(ceq(hl.g, ov.g));
	CHECK(ceq(hl.b, ov.b));
}

TEST_CASE("blend difference") {
	// Difference with itself yields black
	std::math::color32 c(0.4f, 0.6f, 0.8f, 1);
	auto result = c.blend_difference(c);
	CHECK(ceq(result.r, 0));
	CHECK(ceq(result.g, 0));
	CHECK(ceq(result.b, 0));

	// Difference is symmetric
	std::math::color32 src(0.8f, 0.2f, 0.5f, 1);
	std::math::color32 dst(0.3f, 0.7f, 0.5f, 1);
	auto ab = src.blend_difference(dst);
	auto ba = dst.blend_difference(src);
	CHECK(ceq(ab.r, ba.r));
	CHECK(ceq(ab.g, ba.g));
	CHECK(ceq(ab.b, ba.b));

	// Known values: |0.8 - 0.3| = 0.5, |0.2 - 0.7| = 0.5
	CHECK(ceq(ab.r, 0.5f));
	CHECK(ceq(ab.g, 0.5f));
	CHECK(ceq(ab.b, 0.0f));
}

TEST_CASE("blend exclusion") {
	// Exclusion with itself: s + s - 2*s*s = 2s(1-s), not zero (unlike difference)
	std::math::color32 c(0.5f, 0.5f, 0.5f, 1);
	auto result = c.blend_exclusion(c);
	// 0.5 + 0.5 - 2*0.25 = 0.5
	CHECK(ceq(result.r, 0.5f));

	// Exclusion with black leaves src unchanged
	std::math::color32 black(0, 0, 0, 1);
	std::math::color32 src(0.4f, 0.7f, 0.2f, 1);
	auto exc = src.blend_exclusion(black);
	CHECK(ceq(exc.r, 0.4f));
	CHECK(ceq(exc.g, 0.7f));
	CHECK(ceq(exc.b, 0.2f));
}

TEST_CASE("blend color burn") {
	// Burning with white (src=1) leaves dst unchanged: 1 - (1-d)/1 = d
	std::math::color32 white(1, 1, 1, 1);
	std::math::color32 dst(0.4f, 0.6f, 0.8f, 1);
	auto result = white.blend_color_burn(dst);
	CHECK(ceq(result.r, 0.4f));
	CHECK(ceq(result.g, 0.6f));
	CHECK(ceq(result.b, 0.8f));

	// Burning with black (src=0) always yields black
	std::math::color32 black(0, 0, 0, 1);
	auto dark = black.blend_color_burn(dst);
	CHECK(ceq(dark.r, 0));
	CHECK(ceq(dark.g, 0));
	CHECK(ceq(dark.b, 0));
}

TEST_CASE("blend color dodge") {
	// Dodging with black (src=0) leaves dst unchanged: d / (1-0) = d
	std::math::color32 black(0, 0, 0, 1);
	std::math::color32 dst(0.4f, 0.6f, 0.8f, 1);
	auto result = black.blend_color_dodge(dst);
	CHECK(ceq(result.r, 0.4f));
	CHECK(ceq(result.g, 0.6f));
	CHECK(ceq(result.b, 0.8f));

	// Dodging with white (src=1) always yields white
	std::math::color32 white(1, 1, 1, 1);
	auto bright = white.blend_color_dodge(dst);
	CHECK(ceq(bright.r, 1));
	CHECK(ceq(bright.g, 1));
	CHECK(ceq(bright.b, 1));
}

TEST_CASE("blend soft light - neutral at 0.5") {
	// A 50% grey src should leave dst nearly unchanged
	// (soft light has very small deviation at src=0.5)
	std::math::color32 src(0.5f, 0.5f, 0.5f, 1);
	std::math::color32 dst(0.3f, 0.6f, 0.9f, 1);
	auto result = src.blend_soft_light(dst);
	// At src=0.5: d - (1-2*0.5)*d*(1-d) = d - 0 = d
	CHECK(ceq(result.r, 0.3f));
	CHECK(ceq(result.g, 0.6f));
	CHECK(ceq(result.b, 0.9f));
}

TEST_CASE("blend HSV modes") {
	// Pure red src, pure blue dst — hue blend should take red's hue
	// onto blue's saturation (1) and value (1), giving red back.
	std::math::color32 red(1, 0, 0, 1);
	std::math::color32 blue(0, 0, 1, 1);

	auto hue_result = red.blend_hue(blue);
	// Hue from red (H=0), S and V from blue (S=1, V=1) → red
	CHECK(ceq(hue_result.r, 1, 1e-3f));
	CHECK(ceq(hue_result.g, 0, 1e-3f));
	CHECK(ceq(hue_result.b, 0, 1e-3f));

	// blend_color: hue+saturation from src, value from dst
	// red (H=0, S=1) onto blue (V=1) → still red
	auto color_result = red.blend_color(blue);
	CHECK(ceq(color_result.r, 1, 1e-3f));
	CHECK(ceq(color_result.g, 0, 1e-3f));
	CHECK(ceq(color_result.b, 0, 1e-3f));

	// blend_luminosity: value from src, hue+saturation from dst
	// red (V=1) onto blue (H=240°, S=1) → blue (same hue/sat, full brightness)
	auto lum_result = red.blend_luminosity(blue);
	CHECK(ceq(lum_result.r, 0, 1e-3f));
	CHECK(ceq(lum_result.g, 0, 1e-3f));
	CHECK(ceq(lum_result.b, 1, 1e-3f));

	// blend_saturation: saturation from src onto hue+value of dst
	// grey (S=0) onto blue (H=240°, V=1) → desaturated blue = grey
	// std::math::color32 grey(0.5f, 0.5f, 0.5f, 1);
	// auto sat_result = grey.blend_saturation(blue);
	// CHECK(ceq(sat_result.r, sat_result.g, 1e-3f)); // equal channels → grey
	// CHECK(ceq(sat_result.g, sat_result.b, 1e-3f));
}

TEST_CASE("blend alpha propagation") {
	// All blend modes should produce out_a = sa + da*(1-sa)
	// Test with two semi-transparent layers
	std::math::color32 src(1, 0, 0, 0.6f);
	std::math::color32 dst(0, 1, 0, 0.8f);
	float expected_a = 0.6f + 0.8f * (1 - 0.6f); // = 0.92

	CHECK(ceq(src.blend_normal(dst).a, expected_a));
	CHECK(ceq(src.blend_multiply(dst).a, expected_a));
	CHECK(ceq(src.blend_screen(dst).a, expected_a));
	CHECK(ceq(src.blend_overlay(dst).a, expected_a));
	CHECK(ceq(src.blend_difference(dst).a, expected_a));
	CHECK(ceq(src.blend_exclusion(dst).a, expected_a));
	CHECK(ceq(src.blend_darken(dst).a, expected_a));
	CHECK(ceq(src.blend_lighten(dst).a, expected_a));
	CHECK(ceq(src.blend_color_burn(dst).a, expected_a));
	CHECK(ceq(src.blend_color_dodge(dst).a, expected_a));
	CHECK(ceq(src.blend_hard_light(dst).a, expected_a));
	CHECK(ceq(src.blend_soft_light(dst).a, expected_a));
	CHECK(ceq(src.blend_hue(dst).a, expected_a));
	CHECK(ceq(src.blend_saturation(dst).a, expected_a));
	CHECK(ceq(src.blend_color(dst).a, expected_a));
	CHECK(ceq(src.blend_luminosity(dst).a, expected_a));
}

TEST_CASE("blend fully transparent dst") {
	// Blending over a fully transparent dst should yield src composited over nothing
	std::math::color32 src(0.8f, 0.2f, 0.4f, 0.7f);
	std::math::color32 transparent(0, 0, 0, 0);

	auto result = src.blend_normal(transparent);
	// out_a = 0.7 + 0*(1-0.7) = 0.7; rgb = src (only src contributes)
	CHECK(ceq(result.a, 0.7f));
	CHECK(ceq(result.r, 0.8f));
	CHECK(ceq(result.g, 0.2f));
	CHECK(ceq(result.b, 0.4f));
}