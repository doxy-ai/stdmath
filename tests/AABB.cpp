#include <doctest/doctest.h>
#include <math/namespace_alias.hpp>

import std.compat;
import stdmath;

using namespace std::math::types;

TEST_CASE("AABB<f32, 2> basics") {
	std::math::rectangle<f32> rect = { {0.0f, 0.0f}, {2.0f, 2.0f} };

	CHECK(rect.min.x == 0.0f);
	CHECK(rect.min.y == 0.0f);
	CHECK(rect.max.x == 2.0f);
	CHECK(rect.max.y == 2.0f);

	CHECK(rect.center().x == 1.0f);
	CHECK(rect.center().y == 1.0f);

	CHECK(rect.size().x == 2.0f);
	CHECK(rect.size().y == 2.0f);

	CHECK(rect.is_valid());
	CHECK(rect.volume() == 4.0f);
	CHECK(rect.surface_area() == 8.0f); // 2 * (2*2) = 8
}

TEST_CASE("AABB<f32, 3> basics") {
	std::math::box<f32> b = { {0.0f, 0.0f, 0.0f}, {1.0f, 2.0f, 3.0f} };

	CHECK(b.min.z == 0.0f);
	CHECK(b.max.z == 3.0f);

	CHECK(b.center().z == 1.5f);
	CHECK(b.size().z == 3.0f);

	CHECK(b.is_valid());
	CHECK(b.volume() == 6.0f); // 1 * 2 * 3
	CHECK(b.surface_area() == 22.0f); // 2 * (1*2 + 1*3 + 2*3) = 2 * (2 + 3 + 6) = 22
}

TEST_CASE("AABB from_center_size") {
	auto rect = std::math::rectangle<f32>::from_center_size({5.0f, 5.0f}, {2.0f, 4.0f});
	CHECK(rect.min.x == 4.0f);
	CHECK(rect.min.y == 3.0f);
	CHECK(rect.max.x == 6.0f);
	CHECK(rect.max.y == 7.0f);
}

TEST_CASE("AABB normalization") {
	std::math::rectangle<f32> rect = { {2.0f, 2.0f}, {0.0f, 0.0f} };
	CHECK_FALSE(rect.is_valid());

	rect.normalize();
	CHECK(rect.is_valid());
	CHECK(rect.min.x == 0.0f);
	CHECK(rect.max.x == 2.0f);
}

TEST_CASE("AABB containment") {
	std::math::rectangle<f32> rect = { {0.0f, 0.0f}, {10.0f, 10.0f} };

	CHECK(rect.contains(std::math::vector<f32, 2>{5.0f, 5.0f}));
	CHECK(rect.contains(std::math::vector<f32, 2>{0.0f, 0.0f}));
	CHECK(rect.contains(std::math::vector<f32, 2>{10.0f, 10.0f}));
	CHECK_FALSE(rect.contains(std::math::vector<f32, 2>{-1.0f, 5.0f}));

	std::math::rectangle<f32> inner = { {2.0f, 2.0f}, {5.0f, 5.0f} };
	CHECK(rect.contains(inner));

	std::math::rectangle<f32> outer = { {-1.0f, -1.0f}, {11.0f, 11.0f} };
	CHECK_FALSE(rect.contains(outer));
}

TEST_CASE("AABB overlaps") {
	std::math::rectangle<f32> r1 = { {0.0f, 0.0f}, {5.0f, 5.0f} };
	std::math::rectangle<f32> r2 = { {4.0f, 4.0f}, {9.0f, 9.0f} };
	std::math::rectangle<f32> r3 = { {6.0f, 6.0f}, {10.0f, 10.0f} };

	CHECK(r1.overlaps(r2));
	CHECK(r2.overlaps(r1));
	CHECK_FALSE(r1.overlaps(r3));
}

TEST_CASE("AABB expansion") {
	std::math::rectangle<f32> rect = { {0.0f, 0.0f}, {1.0f, 1.0f} };
	rect.expand(std::math::vector<f32, 2>{2.0f, -1.0f});

	CHECK(rect.min.x == 0.0f);
	CHECK(rect.min.y == -1.0f);
	CHECK(rect.max.x == 2.0f);
	CHECK(rect.max.y == 1.0f);
}

TEST_CASE("AABB merge and intersect") {
	std::math::rectangle<f32> r1 = { {0.0f, 0.0f}, {2.0f, 2.0f} };
	std::math::rectangle<f32> r2 = { {1.0f, 1.0f}, {3.0f, 3.0f} };

	auto merged = std::math::rectangle<f32>::merge(r1, r2);
	CHECK(merged.min.x == 0.0f);
	CHECK(merged.max.x == 3.0f);

	auto intersected = r1.intersect(r2);
	REQUIRE(intersected.has_value());
	CHECK(intersected->min.x == 1.0f);
	CHECK(intersected->max.x == 2.0f);

	std::math::rectangle<f32> r3 = { {10.0f, 10.0f}, {12.0f, 12.0f} };
	auto no_intersection = r1.intersect(r3);
	CHECK_FALSE(no_intersection.has_value());
}

TEST_CASE("AABB distance") {
	std::math::rectangle<f32> rect = { {0.0f, 0.0f}, {2.0f, 2.0f} };
	std::math::vector<f32, 2> p = { 4.0f, 0.0f };

	CHECK(rect.distance_squared(p) == 4.0f);
	CHECK(rect.distance(p) == 2.0f);

	CHECK(rect.distance(std::math::vector<f32, 2>{1.0f, 1.0f}) == 0.0f);
}

TEST_CASE("AABB inflate") {
	std::math::rectangle<f32> rect = { {0.0f, 0.0f}, {2.0f, 2.0f} };
	rect.inflate({1.0f, 1.0f});

	CHECK(rect.min.x == -1.0f);
	CHECK(rect.min.y == -1.0f);
	CHECK(rect.max.x == 3.0f);
	CHECK(rect.max.y == 3.0f);
}
