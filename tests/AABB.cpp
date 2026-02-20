#include <doctest/doctest.h>
#include "util.hpp"

TEST_CASE("AABB<f32, 2> basics") {
	std::math::rectangle<f32> rect = { {0, 0}, {2, 2} };

	CHECK(rect.min.x == 0);
	CHECK(rect.min.y == 0);
	CHECK(rect.max.x == 2);
	CHECK(rect.max.y == 2);

	CHECK(rect.center().x == 1);
	CHECK(rect.center().y == 1);

	CHECK(rect.size().x == 2);
	CHECK(rect.size().y == 2);

	CHECK(rect.is_valid());
	CHECK(rect.volume() == 4);
	CHECK(rect.surface_area() == 8); // 2 * (2*2) = 8

	std::cout << rect << std::endl;
	std::println("{}", rect);
}

TEST_CASE("AABB<f32, 3> basics") {
	std::math::box<f32> b = { {0, 0, 0}, {1, 2, 3} };

	CHECK(b.min.z == 0);
	CHECK(b.max.z == 3);

	CHECK(b.center().z == 1.5f);
	CHECK(b.size().z == 3);

	CHECK(b.is_valid());
	CHECK(b.volume() == 6); // 1 * 2 * 3
	CHECK(b.surface_area() == 22); // 2 * (1*2 + 1*3 + 2*3) = 2 * (2 + 3 + 6) = 22
}

TEST_CASE("AABB from_center_size") {
	auto rect = std::math::rectangle<f32>::from_center_size({5, 5}, {2, 4});
	CHECK(rect.min.x == 4);
	CHECK(rect.min.y == 3);
	CHECK(rect.max.x == 6);
	CHECK(rect.max.y == 7);
}

TEST_CASE("AABB normalization") {
	std::math::rectangle<f32> rect = { {2, 2}, {0, 0} };
	CHECK_FALSE(rect.is_valid());

	rect.normalize();
	CHECK(rect.is_valid());
	CHECK(rect.min.x == 0);
	CHECK(rect.max.x == 2);
}

TEST_CASE("AABB containment") {
	std::math::rectangle<f32> rect = { {0, 0}, {10, 10} };

	CHECK(rect.contains(std::math::vector<f32, 2>{5, 5}));
	CHECK(rect.contains(std::math::vector<f32, 2>{0, 0}));
	CHECK(rect.contains(std::math::vector<f32, 2>{10, 10}));
	CHECK_FALSE(rect.contains(std::math::vector<f32, 2>{-1, 5}));

	std::math::rectangle<f32> inner = { {2, 2}, {5, 5} };
	CHECK(rect.contains(inner));

	std::math::rectangle<f32> outer = { {-1, -1}, {11, 11} };
	CHECK_FALSE(rect.contains(outer));
}

TEST_CASE("AABB overlaps") {
	std::math::rectangle<f32> r1 = { {0, 0}, {5, 5} };
	std::math::rectangle<f32> r2 = { {4, 4}, {9, 9} };
	std::math::rectangle<f32> r3 = { {6, 6}, {10, 10} };

	CHECK(r1.overlaps(r2));
	CHECK(r2.overlaps(r1));
	CHECK_FALSE(r1.overlaps(r3));
}

TEST_CASE("AABB expansion") {
	std::math::rectangle<f32> rect = { {0, 0}, {1, 1} };
	rect.expand(std::math::vector<f32, 2>{2, -1});

	CHECK(rect.min.x == 0);
	CHECK(rect.min.y == -1);
	CHECK(rect.max.x == 2);
	CHECK(rect.max.y == 1);
}

TEST_CASE("AABB merge and intersect") {
	std::math::rectangle<f32> r1 = { {0, 0}, {2, 2} };
	std::math::rectangle<f32> r2 = { {1, 1}, {3, 3} };

	auto merged = std::math::rectangle<f32>::merge(r1, r2);
	CHECK(merged.min.x == 0);
	CHECK(merged.max.x == 3);

	auto intersected = r1.intersect(r2);
	REQUIRE(intersected.has_value());
	CHECK(intersected->min.x == 1);
	CHECK(intersected->max.x == 2);

	std::math::rectangle<f32> r3 = { {10, 10}, {12, 12} };
	auto no_intersection = r1.intersect(r3);
	CHECK_FALSE(no_intersection.has_value());
}

TEST_CASE("AABB distance") {
	std::math::rectangle<f32> rect = { {0, 0}, {2, 2} };
	std::math::vector<f32, 2> p = { 4, 0 };

	CHECK(rect.distance_squared(p) == 4);
	CHECK(rect.distance(p) == 2);

	CHECK(rect.distance(std::math::vector<f32, 2>{1, 1}) == 0);
}

TEST_CASE("AABB inflate") {
	std::math::rectangle<f32> rect = { {0, 0}, {2, 2} };
	rect.inflate({1, 1});

	CHECK(rect.min.x == -1);
	CHECK(rect.min.y == -1);
	CHECK(rect.max.x == 3);
	CHECK(rect.max.y == 3);
}
