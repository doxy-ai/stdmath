#include <doctest/doctest.h>
#include <math/namespace_alias.hpp>

import std.compat;
import stdmath.angle;
import stdmath.types;

using namespace std::math::types;

TEST_CASE("angles") {
	// rad2deg and deg2rad
	f32 float_val = 1.0f;
	CHECK(std::math::approximately_equal(std::math::rad2deg<f32> * std::math::PI, 180.0f, .001));
	CHECK(std::math::approximately_equal(std::math::deg2rad<f32> * 180.0f, std::math::PI));

	// basic_radian and basic_degree
	std::math::radian32 r(std::math::PI / 4);
	std::math::degree32 d(45.0f);
	CHECK(r.degree() == d.degree());
	CHECK(d.radian() == r.radian());

	// basic_radian operators
	std::math::radian32 r1(1.0f);
	std::math::radian32 r2(2.0f);
	CHECK(r1 + r2 == 3.0f);
	CHECK(r1 - r2 == -1.0f);
	CHECK(r1 * r2 == 2.0f);
	CHECK(r1 / r2 == 0.5f);
	std::math::radian32 r3 = r1;
	r3 += r2;
	CHECK(r3 == 3.0f);

	// basic_degree operators
	std::math::degree32 d1(1.0f);
	std::math::degree32 d2(2.0f);
	CHECK(d1 + d2 == 3.0f);
	CHECK(d1 - d2 == -1.0f);
	CHECK(d1 * d2 == 2.0f);
	CHECK(d1 / d2 == 0.5f);
	std::math::degree32 d3 = d1;
	d3 += d2;
	CHECK(d3 == 3.0f);

	// trig functions
	std::math::radian32 r_pi_div_2(std::math::PI / 2.0);
	CHECK(std::math::approximately_equal(std::math::cos(r_pi_div_2), 0.0f));
	CHECK(std::math::approximately_equal(std::math::sin(r_pi_div_2), 1.0f));

	// inverse trig functions
	auto r_asin_05 = std::math::asin(0.5f);
	CHECK(std::math::approximately_equal(std::math::sin(r_asin_05), 0.5f));

	// atan2
	auto r_atan2_1_1 = std::math::atan2(1.0f, 1.0f);
	CHECK(std::math::approximately_equal(r_atan2_1_1, 0.785398f));

	// angle_normalize
	// auto d_norm = std::math::angle_wrap<std::math::degree>(540.0);
	// CHECK(std::math::approximately_equal(d_norm, 180.0)); // TODO: Why is this not working!?!?

	auto d_norm2 = std::math::angle_wrap<std::math::degree>(-180.0);
	CHECK(std::math::approximately_equal(d_norm2, 180.0));

	// auto r_norm = std::math::angle_wrap<std::math::radian>(7.0f * std::math::PI);
	// CHECK(std::math::approximately_equal(r_norm, std::math::PI)); // TODO: Why is this not working!?!?
}