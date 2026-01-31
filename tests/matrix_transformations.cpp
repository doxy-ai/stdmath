#include <doctest/doctest.h>
#include <math/namespace_alias.hpp>

import std.compat;
import stdmath;

using namespace std::math::types;

TEST_CASE("rotation_matrix") {
	// Identity quaternion
	std::math::quaternion q = {0, 0, 0, 1};
	auto m = std::math::rotation_matrix(q);

	auto identity = std::math::matrix<f32, 3, 3>::identity();
	for(int i=0; i<3; ++i)
		for(int j=0; j<3; ++j)
			CHECK(std::math::approximately_equal(m[i, j], identity[i, j]));

	// 90 degrees around Y axis
	// In left-handed system, 90 deg around Y should rotate (1, 0, 0) to (0, 0, -1)
	// Wait, let's check the implementation.
	// basic_quaternion is (x, y, z, w)
	// For 90 deg around Y: axis=(0,1,0), angle=pi/2
	// q = (axis * sin(angle/2), cos(angle/2)) = (0, sin(pi/4), 0, cos(pi/4)) = (0, 0.707, 0, 0.707)

	std::math::quaternion qy = {0.0f, 0.7071068f, 0.0f, 0.7071068f};
	auto my = std::math::rotation_matrix(qy);

	std::math::vector<f32, 3> v{1.0f, 0.0f, 0.0f};
	auto rotated = my * v;

	// Since it is row major: matrix * vector means vector is treated as column vector?
	// Or is it vector * matrix?
	// In matrix.cppm:
	/*
	export template<typename T, size_t X, size_t Y>
	constexpr vector<T, X> operator*(const matrix<T, X, Y>& m, const vector<T, Y>& v) {
		vector<T, X> out;
		for (size_t i = 0; i < X; ++i) {
			out[i] = 0;
			for (size_t j = 0; j < Y; ++j) {
				out[i] += m[i, j] * v[j];
			}
		}
		return out;
	}
	*/
	// This is standard matrix-vector multiplication.

	CHECK(std::math::approximately_equal(rotated.x, 0.0f));
	CHECK(std::math::approximately_equal(rotated.y, 0.0f));
	CHECK(std::math::approximately_equal(rotated.z, -1.0f));
}

TEST_CASE("translation_matrix") {
	std::math::vector<f32, 3> pos{10.0f, 20.0f, 30.0f};
	auto m = std::math::translation_matrix(pos);

	std::math::vector<f32, 4> v{0.0f, 0.0f, 0.0f, 1.0f};
	auto translated = m * v;

	CHECK(translated.x == 10.0f);
	CHECK(translated.y == 20.0f);
	CHECK(translated.z == 30.0f);
	CHECK(translated.w == 1.0f);
}

TEST_CASE("scale_matrix") {
	std::math::vector<f32, 3> scale{2.0f, 3.0f, 4.0f};
	auto m = std::math::scale_matrix(scale);

	std::math::vector<f32, 3> v{1.0f, 1.0f, 1.0f};
	auto scaled = m * v;

	CHECK(scaled.x == 2.0f);
	CHECK(scaled.y == 3.0f);
	CHECK(scaled.z == 4.0f);
}

TEST_CASE("homogenous conversions") {
	auto m3 = std::math::matrix<f32, 3, 3>::identity();
	m3[0, 0] = 2.0f;

	auto m4 = std::math::make_homogenous(m3);
	CHECK(m4[0, 0] == 2.0f);
	CHECK(m4[3, 3] == 1.0f);
	CHECK(m4[0, 3] == 0.0f);

	auto stripped = std::math::strip_homogenous(m4);
	CHECK(stripped[0, 0] == 2.0f);
}

TEST_CASE("combine_3x3_with_translation") {
	auto m3 = std::math::matrix<f32, 3, 3>::identity();
	std::math::vector<f32, 3> pos{1, 2, 3};

	auto m4 = std::math::combine_3x3_with_translation(m3, pos);
	CHECK(m4[0, 3] == 1.0f);
	CHECK(m4[1, 3] == 2.0f);
	CHECK(m4[2, 3] == 3.0f);
	CHECK(m4[0, 0] == 1.0f);
}

TEST_CASE("look_at_matrix") {
	std::math::vector<f32, 3> eye{0, 0, 0};
	std::math::vector<f32, 3> target{0, 0, 1};
	std::math::vector<f32, 3> up{0, 1, 0};

	auto m = std::math::look_at_matrix(eye, target, up);

	std::math::vector<f32, 4> v{0, 0, 1, 1};
	auto transformed = m * v;

	// In look_at, target should be on the positive Z axis (forward)
	CHECK(std::math::approximately_equal(transformed.x, 0.0f));
	CHECK(std::math::approximately_equal(transformed.y, 0.0f));
	CHECK(std::math::approximately_equal(transformed.z, 1.0f));
}

TEST_CASE("projections") {
	// Perspective
	auto p = std::math::perspective_matrix(std::math::radian(1.5708f), 1.0f, 0.1f, 100.0f);
	CHECK(p[1, 1] != 0.0f);
	CHECK(p[3, 2] == 1.0f); // W gets Z

	// Orthographic
	auto o = std::math::orthographic_matrix(0.0f, 800.0f, 600.0f, 0.0f, -1.0f, 1.0f);
	std::math::vector<f32, 4> v{400.0f, 300.0f, 0.0f, 1.0f};
	auto projected = o * v;

	CHECK(std::math::approximately_equal(projected.x, 0.0f));
	CHECK(std::math::approximately_equal(projected.y, 0.0f));
}
