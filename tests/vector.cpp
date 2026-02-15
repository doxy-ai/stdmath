#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <math/namespace_alias.hpp>

import std.compat;
import stdmath;

using namespace std::math::types;

TEST_CASE("vector<f32, 1>") {
	std::math::vector<f32, 1> v1(1);
	CHECK(v1.x == 1);

	std::math::vector<f32, 1> v2 = {2};
	CHECK(v2.x == 2);

	std::math::swizzle<f32, 1> sw1 = v1._x();
	CHECK(*sw1.x == 1);
	std::math::vector<f32, 1> vector_from_swizzle = sw1.to_vector();
	CHECK(vector_from_swizzle.x == 1);
}

TEST_CASE("vector<f32, 2>") {
	std::math::vector<f32, 2> v3(3);
	CHECK(v3.x == 3);
	CHECK(v3.y == 3);

	std::math::vector<f32, 2> v4(4, 5);
	CHECK(v4.x == 4);
	CHECK(v4.y == 5);

	std::math::swizzle<f32, 2> sw2 = v4.xy();
	CHECK(*sw2.x == 4);
	CHECK(*sw2.y == 5);
	std::math::vector<f32, 2> vector_from_swizzle2 = sw2.to_vector();
	CHECK(vector_from_swizzle2.x == 4);
	CHECK(vector_from_swizzle2.y == 5);

	CHECK(bool{sw2.to_vector() == std::math::vector<f32, 2>{4, 5}});

	std::math::vector<f32, 2> normalized_vector_from_swizzle2 = normalize(sw2.to_vector());
	CHECK(std::math::approximately_equal(normalized_vector_from_swizzle2.x, 0.6246950476));
	CHECK(std::math::approximately_equal(normalized_vector_from_swizzle2.y, 0.7808688094));
}

TEST_CASE("vector<f32, 3>") {
	std::math::vector<f32, 3> v5(6);
	CHECK(v5.x == 6);
	CHECK(v5.y == 6);
	CHECK(v5.z == 6);

	std::math::vector<f32, 3> v6(7, 8);
	CHECK(v6.x == 7);
	CHECK(v6.y == 8);
	CHECK(v6.z == 0);

	std::math::vector<f32, 3> v7(9, 10, 11);
	CHECK(v7.x == 9);
	CHECK(v7.y == 10);
	CHECK(v7.z == 11);

	std::math::vector<f32, 3> cross_vector = cross(v6, v7);
	CHECK(cross_vector.x == 88);
	CHECK(cross_vector.y == -77);
	CHECK(cross_vector.z == -2);

	std::math::swizzle<f32, 3> sw3 = v7.xyz();
	CHECK(*sw3.x == 9);
	CHECK(*sw3.y == 10);
	CHECK(*sw3.z == 11);

	std::math::vector<f32, 3> vector_from_swizzle3 = sw3.to_vector();
	CHECK(vector_from_swizzle3.x == 9);
	CHECK(vector_from_swizzle3.y == 10);
	CHECK(vector_from_swizzle3.z == 11);

	CHECK(bool{sw3.to_vector() == std::math::vector<f32, 3>{9, 10, 11}});

	std::math::vector<f32, 3> normalized_vector_from_swizzle3 = normalize(sw3.to_vector());
	CHECK(std::math::approximately_equal(normalized_vector_from_swizzle3.x, 0.5178918039));
	CHECK(std::math::approximately_equal(normalized_vector_from_swizzle3.y, 0.5754353376));
	CHECK(std::math::approximately_equal(normalized_vector_from_swizzle3.z, 0.6329788714));
}

TEST_CASE("vector<f32, 4>") {
	std::math::vector<f32, 4> v8(12);
	CHECK(v8.x == 12);
	CHECK(v8.y == 12);
	CHECK(v8.z == 12);
	CHECK(v8.w == 12);

	std::math::vector<f32, 4> v9(13, 14);
	CHECK(v9.x == 13);
	CHECK(v9.y == 14);
	CHECK(v9.z == 0);
	CHECK(v9.w == 0);

	std::math::vector<f32, 4> v10(15, 16, 17);
	CHECK(v10.x == 15);
	CHECK(v10.y == 16);
	CHECK(v10.z == 17);
	CHECK(v10.w == 0);

	std::math::vector<f32, 4> v11(18, 19, 20, 21);
	CHECK(v11.x == 18);
	CHECK(v11.y == 19);
	CHECK(v11.z == 20);
	CHECK(v11.w == 21);

	std::math::swizzle<f32, 4> sw4 = v11.wxyz();
	CHECK(*sw4.x == 21);
	CHECK(*sw4.y == 18);
	CHECK(*sw4.z == 19);
	CHECK(*sw4.w == 20);

	std::math::vector<f32, 4> vector_from_swizzle4 = sw4.to_vector();
	CHECK(vector_from_swizzle4.x == 21);
	CHECK(vector_from_swizzle4.y == 18);
	CHECK(vector_from_swizzle4.z == 19);
	CHECK(vector_from_swizzle4.w == 20);

	CHECK(bool{sw4.to_vector() == std::math::vector<f32, 4>{21.f, 18.f, 19.f, 20.f}});

	std::math::vector<f32, 4> normalized_vector_from_swizzle4 = normalize(sw4.to_vector());
	CHECK(std::math::approximately_equal(normalized_vector_from_swizzle4.x, 0.5375786693));
	CHECK(std::math::approximately_equal(normalized_vector_from_swizzle4.y, 0.4607817165));
	CHECK(std::math::approximately_equal(normalized_vector_from_swizzle4.z, 0.4863807008));
	CHECK(std::math::approximately_equal(normalized_vector_from_swizzle4.w, 0.5119796850));

	auto v11x4 = v11 * 4;
	CHECK(bool{v11x4 == std::math::vector<f32, 4>{18 * 4, 19 * 4, 20 * 4, 21 * 4}});
}

TEST_CASE("vector<i32, 1>") {
	std::math::vector<i32, 1> v1(1);
	CHECK(v1.x == 1);

	std::math::vector<i32, 1> v2 = {2};
	CHECK(v2.x == 2);

	std::math::swizzle<i32, 1> sw1 = v1._x();
	CHECK(*sw1.x == 1);
	std::math::vector<i32, 1> vector_from_swizzle = sw1.to_vector();
	CHECK(vector_from_swizzle.x == 1);
}

TEST_CASE("vector<i32, 2>") {
	std::math::vector<i32, 2> v3(3);
	CHECK(v3.x == 3);
	CHECK(v3.y == 3);

	std::math::vector<i32, 2> v4(4, 5);
	CHECK(v4.x == 4);
	CHECK(v4.y == 5);

	std::math::swizzle<i32, 2> sw2 = v4.xy();
	CHECK(*sw2.x == 4);
	CHECK(*sw2.y == 5);
	std::math::vector<i32, 2> vector_from_swizzle2 = sw2.to_vector();
	CHECK(vector_from_swizzle2.x == 4);
	CHECK(vector_from_swizzle2.y == 5);
}

TEST_CASE("vector<i32, 3>") {
	std::math::vector<i32, 3> v5(6);
	CHECK(v5.x == 6);
	CHECK(v5.y == 6);
	CHECK(v5.z == 6);

	std::math::vector<i32, 3> v6(7, 8);
	CHECK(v6.x == 7);
	CHECK(v6.y == 8);
	CHECK(v6.z == 0);

	std::math::vector<i32, 3> v7(9, 10, 11);
	CHECK(v7.x == 9);
	CHECK(v7.y == 10);
	CHECK(v7.z == 11);

	std::math::vector<i32, 3> cross_vector = cross(v6, v7);
	CHECK(cross_vector.x == 88);
	CHECK(cross_vector.y == -77);
	CHECK(cross_vector.z == -2);

	std::math::swizzle<i32, 3> sw3 = v7.xyz();
	CHECK(*sw3.x == 9);
	CHECK(*sw3.y == 10);
	CHECK(*sw3.z == 11);

	std::math::vector<i32, 3> vector_from_swizzle3 = sw3.to_vector();
	CHECK(vector_from_swizzle3.x == 9);
	CHECK(vector_from_swizzle3.y == 10);
	CHECK(vector_from_swizzle3.z == 11);
}

TEST_CASE("vector<i32, 4>") {
	std::math::vector<i32, 4> v8(12);
	CHECK(v8.x == 12);
	CHECK(v8.y == 12);
	CHECK(v8.z == 12);
	CHECK(v8.w == 12);

	std::math::vector<i32, 4> v9(13, 14);
	CHECK(v9.x == 13);
	CHECK(v9.y == 14);
	CHECK(v9.z == 0);
	CHECK(v9.w == 0);

	std::math::vector<i32, 4> v10(15, 16, 17);
	CHECK(v10.x == 15);
	CHECK(v10.y == 16);
	CHECK(v10.z == 17);
	CHECK(v10.w == 0);

	std::math::vector<i32, 4> v11(18, 19, 20, 21);
	CHECK(v11.x == 18);
	CHECK(v11.y == 19);
	CHECK(v11.z == 20);
	CHECK(v11.w == 21);

	std::math::swizzle<i32, 4> sw4 = v11.wxyz();
	CHECK(*sw4.x == 21);
	CHECK(*sw4.y == 18);
	CHECK(*sw4.z == 19);
	CHECK(*sw4.w == 20);

	std::math::vector<i32, 4> vector_from_swizzle4 = sw4.to_vector();
	CHECK(vector_from_swizzle4.x == 21);
	CHECK(vector_from_swizzle4.y == 18);
	CHECK(vector_from_swizzle4.z == 19);
	CHECK(vector_from_swizzle4.w == 20);
}

TEST_CASE("vector<f32, 4> -> vector<i32, 4>") {
	std::math::vector<f64, 4> flt(18.1, 19.2, 20.3, 21.4);
	std::math::vector<i32, 4> i32eg = flt;
	CHECK(i32eg.x == 18);
	CHECK(i32eg.y == 19);
	CHECK(i32eg.z == 20);
	CHECK(i32eg.w == 21);
}

TEST_CASE("vector<f32, 4> operators") {
	using vec4 = std::math::vector<f32, 4>;

	vec4 a(1, 2, 3, 4);
	vec4 b(4, 3, 2, 1);
	vec4 c(1, 2, 3, 4);

	// --- Accessors ---
	CHECK(a.x == 1);
	CHECK(a.y == 2);
	CHECK(a.z == 3);
	CHECK(a.w == 4);

	// --- Equality / Inequality ---
	CHECK(all_of(a == c));
	CHECK(none_of(a != c));
	CHECK(all_of(a != b));
	CHECK(none_of(a == b));

	// --- Relational operators ---
	CHECK(all_of(a < vec4(2, 3, 4, 5)));
	CHECK(all_of(a <= c));
	CHECK(all_of(b > vec4(1, 1, 1, 0.5f)));
	CHECK(all_of(b >= vec4(4, 3, 2, 1)));

	// --- Unary operators ---
	CHECK(all_of((-a) == vec4(-1, -2, -3, -4)));
	// CHECK(all_of((+a) == a));

	// --- Vector arithmetic ---
	CHECK(all_of(a + b == vec4(5, 5, 5, 5)));
	CHECK(all_of(a - b == vec4(-3, -1, 1, 3)));
	CHECK(all_of(a * b == vec4(4, 6, 6, 4)));
	CHECK(all_of(a / b == vec4(0.25f, 0.6666667f, 1.5f, 4)));

	// --- Scalar arithmetic ---
	CHECK(all_of(a + 1 == vec4(2, 3, 4, 5)));
	CHECK(all_of(a - 1 == vec4(0, 1, 2, 3)));
	CHECK(all_of(a * 2 == vec4(2, 4, 6, 8)));
	CHECK(all_of(a / 2 == vec4(0.5f, 1, 1.5f, 2)));

	// --- Compound assignment (vector) ---
	vec4 d = a;
	d += b;
	CHECK(all_of(d == vec4(5, 5, 5, 5)));

	d = a;
	d -= b;
	CHECK(all_of(d == vec4(-3, -1, 1, 3)));

	d = a;
	d *= b;
	CHECK(all_of(d == vec4(4, 6, 6, 4)));

	d = a;
	d /= b;
	CHECK(all_of(d == vec4(0.25f, 0.6666667f, 1.5f, 4)));

	// --- Compound assignment (scalar) ---
	d = a;
	d += 1;
	CHECK(all_of(d == vec4(2, 3, 4, 5)));

	d = a;
	d -= 1;
	CHECK(all_of(d == vec4(0, 1, 2, 3)));

	d = a;
	d *= 2;
	CHECK(all_of(d == vec4(2, 4, 6, 8)));

	d = a;
	d /= 2;
	CHECK(all_of(d == vec4(0.5f, 1, 1.5f, 2)));

	std::cout << d << std::endl;
	std::println("{}", d);
}
