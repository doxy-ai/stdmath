#include <doctest/doctest.h>
#include <math/namespace_alias.hpp>

import std.compat;
import stdmath;

using namespace std::math::types;

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
	CHECK(std::math::approximately_equal(c1.r, 1));
	CHECK(std::math::approximately_equal(c1.g, 128.f / 255));
	CHECK(std::math::approximately_equal(c1.b, 0));
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
}

TEST_CASE("color sRGB/Linear conversions") {
	std::math::color32 c(0.5f, 0.5f, 0.5f, 1);

	auto linear = c.srgb_to_linear_accurate();
	// 0.5 sRGB is approx 0.21404 linear
	CHECK(std::math::approximately_equal(linear.r, 0.214041f));

	auto srgb = linear.linear_to_srgb_accurate();
	CHECK(std::math::approximately_equal(srgb.r, 0.5f));

	auto fast_linear = c.srgb_to_linear(); // gamma 2.2
	CHECK(std::math::approximately_equal(fast_linear.r, std::pow(0.5f, 2.2f)));
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
	CHECK(std::math::approximately_equal(lum, 0.2126f + 0.7152f));

	auto gray = c.linear_to_grayscale();
	CHECK(gray.r == lum);
	CHECK(gray.g == lum);
	CHECK(gray.b == lum);
}

TEST_CASE("color oklab") {
	std::math::color32 red(1, 0, 0, 1);
	auto oklab = red.linear_to_oklab();
	auto back = oklab.oklab_to_linear();

	CHECK(std::math::approximately_equal(back.r, 1));
	CHECK(std::math::approximately_equal(back.g, 0, 1e-5f));
	CHECK(std::math::approximately_equal(back.b, 0, 1e-5f));
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
	CHECK(std::math::approximately_equal(c32.g, 127.f / 255));

	std::math::color8 back = std::math::denormalize(c32);
	CHECK(back.r == 255);
	CHECK(back.g == 127);
}

TEST_CASE("color hex output") {
	std::math::color8 c8(255, 128, 0, 255);
	CHECK(c8.linear_to_hex() == "#ff8000");
	CHECK(c8.linear_to_hex(true) == "#ff8000ff");
}
