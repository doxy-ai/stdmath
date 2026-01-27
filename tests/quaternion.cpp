#include <doctest/doctest.h>
#include <math/namespace_alias.hpp>

import std.compat;
import stdmath.slang;

using namespace std::math::types;

TEST_CASE("Quaternion Basics") {
	std::math::quaternion a = {1, 2, 3, 4}, b = {5, 6, 7, 8};

	// Elementwise Operations
	CHECK(all_of(a + b == std::math::quaternion(6, 8, 10, 12)));
	CHECK(all_of(a - b == std::math::quaternion(-4, -4, -4, -4)));
	// Scalar Operations
	CHECK(all_of(a * 5 == std::math::quaternion(5, 10, 15, 20)));
	CHECK(approximately_equal(a / 2, std::math::quaternion(1.f/2, 1.f, 3.f/2, 2.f)));

	// Conjugate
	CHECK(all_of(a.conjugate() == std::math::quaternion(-1, -2, -3, 4)));

	// Quaternion-Quaternion Multiplication
	a = std::math::quaternion::from_axis_angle(std::math::float3{1, 0, 0}, std::math::degree(45));
	CHECK(approximately_equal(a, std::math::quaternion(.38f, 0.f, 0.f, .92f), .01));
	b = std::math::quaternion::from_axis_angle(std::math::float3{0, 0, 1}, std::math::degree(45));
	CHECK(approximately_equal(b, std::math::quaternion(0.f, 0.f, .38f, .92f), .01));
	auto ab = std::math::normalize(a * b);
	CHECK(approximately_equal(ab, std::math::quaternion(.35f, -.15f, .35f, .85f), .01));

	// Axis Angle
	auto [axis, rad] = ab.to_axis_angle();
	CHECK(approximately_equal<real_t>(axis, {std::math::float3(.68f, -.28f, .68f)}, .01));
	std::math::degree angle = rad;
	CHECK(approximately_equal(angle, 62.8, .01));
	// Angle Between
	CHECK(approximately_equal(std::math::degree(angle_between(a, b)), 48.9, .01)); // TODO: Is this correct?

	// Vector rotation
	std::math::float3 v = {0, 1, 0};
	CHECK(approximately_equal(rotate_vector(a, v), {std::math::float3(0, .71f, .71f)}, .01));
	CHECK(approximately_equal(rotate_vector(b, v), {std::math::float3(-.71f, .71f, 0)}, .01));
	CHECK(approximately_equal(rotate_vector(ab, v), {std::math::float3(-.71f, .5f, .5f)}, .01));
}

TEST_CASE("Euler Angles") {
	auto q = std::math::quaternion::from_euler_angles({std::math::degree(45), 0, 0});
	CHECK(approximately_equal(q, std::math::quaternion(.38f, 0.f, 0.f, .92f), .01));
	q = std::math::quaternion::from_euler_angles({std::math::degree(45), 0, std::math::degree(45)});
	CHECK(approximately_equal(q, std::math::quaternion(.35f, -.15f, .35f, .85f), .01));

	auto eRadian = q.to_euler_angles();
	std::math::degree x = eRadian.x;
	std::math::degree y = eRadian.y;
	std::math::degree z = eRadian.z;
	// TODO: Is this wrong?
}
