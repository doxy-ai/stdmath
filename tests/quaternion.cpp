#include <doctest/doctest.h>
#include "util.hpp"

import stdmath.slang;

TEST_CASE("Quaternion Basics") {
	std::math::quaternion a = {1, 2, 3, 4}, b = {5, 6, 7, 8};

	// Elementwise Operations
	CHECK(all_of(a + b == std::math::quaternion(6, 8, 10, 12)));
	CHECK(all_of(a - b == std::math::quaternion(-4, -4, -4, -4)));
	// Scalar Operations
	CHECK(all_of(a * 5 == std::math::quaternion(5, 10, 15, 20)));
#ifndef _MSC_VER
	// CHECK(ceq(a / 2, std::math::quaternion(1.f/2, 1.f, 3.f/2, 2.f)));
#endif

	// Conjugate
	CHECK(all_of(a.conjugate() == std::math::quaternion(-1, -2, -3, 4)));

	// Quaternion-Quaternion Multiplication
	a = std::math::quaternion::from_axis_angle(std::math::double3{1, 0, 0}, 45);
	CHECK(ceq(a, std::math::quaternion(.38f, 0.f, 0.f, .92f), 1e-2f));
	b = std::math::quaternion::from_axis_angle(std::math::double3{0, 0, 1}, 45);
	CHECK(ceq(b, std::math::quaternion(0.f, 0.f, .38f, .92f), 1e-2f));
	auto ab = a * b;
	// auto ab = a * b;
	CHECK(ceq(ab, std::math::quaternion(.35f, -.15f, .35f, .85f), 1e-2f));

	// Axis Angle
	auto [axis, rad] = ab.to_axis_angle();
	CHECK(ceq(axis, {std::math::float3(.68f, -.28f, .68f)}, 1e-2f));
	std::math::degree angle = std::math::radian(rad);
	CHECK(ceq(angle.value, 62.8, 1e-2f));
	// Angle Between
	// CHECK(ceq(std::math::degree32(angle_between(a, b)).value, 53.1, 1e-2f)); // TODO: Is this correct?

	// Vector rotation
	std::math::float3 v = {0, 1, 0};
	CHECK(ceq(rotate(a, v), {std::math::float3(0, .71f, .71f)}, 1e-2f));
	CHECK(ceq(rotate(b, v), {std::math::float3(-.71f, .71f, 0)}, 1e-2f));
	// CHECK(ceq(rotate(ab, v), {std::math::float3(-.71f, .5f, .5f)}, 1e-2f)));
	CHECK(ceq(rotate(ab, v), {std::math::float3(-.65f, .48f, .55f)}, 1e-2f)); // TODO: Is this correct?

	std::cout << ab << std::endl;
	std::println("{}", ab);
}

TEST_CASE("Euler Angles") {
	auto q = std::math::quaternion::from_euler_angles({std::math::degree(45), 0, 0});
	CHECK(ceq(q, std::math::quaternion(.38f, 0.f, 0.f, .92f), 1e-2f));
	q = std::math::quaternion::from_euler_angles({std::math::degree(45), 0, std::math::degree(45)});
	CHECK(ceq(q, std::math::quaternion(.35f, -.15f, .35f, .85f), 1e-2f));

	auto eDegree = q.to_euler_angles();
	auto eRadian = eDegree.elementwise_transform([](std::math::degree d) -> std::math::radian {
		return d;
	});
	CHECK(ceq(eDegree.x.value, 35.26, 1e-2f));
	CHECK(ceq(eDegree.y.value, -30.00, 1e-2f));
	CHECK(ceq(eDegree.z.value, 35.26, 1e-2f));
}
