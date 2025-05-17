#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <math/namespace_alias.hpp>


TEST_CASE("vec<float, 1>") {
	std::math::vec<float, 1> v1(1.0f);
	CHECK(v1.x == 1.0f);

	std::math::vec<float, 1> v2 = {2.0f};
	CHECK(v2.x == 2.0f);

	std::math::swizzle<float, 1> sw1 = v1._x();
	CHECK(*sw1.x == 1.0f);
	std::math::vec<float, 1> vec_from_swizzle = sw1.to_vec();
	CHECK(vec_from_swizzle.x == 1.0f);
}

TEST_CASE("vec<float, 2>") {
	std::math::vec<float, 2> v3(3.0f);
	CHECK(v3.x == 3.0f);
	CHECK(v3.y == 3.0f);

	std::math::vec<float, 2> v4(4.0f, 5.0f);
	CHECK(v4.x == 4.0f);
	CHECK(v4.y == 5.0f);

	std::math::swizzle<float, 2> sw2 = v4.xy();
	CHECK(*sw2.x == 4.0f);
	CHECK(*sw2.y == 5.0f);
	std::math::vec<float, 2> vec_from_swizzle2 = sw2.to_vec();
	CHECK(vec_from_swizzle2.x == 4.0f);
	CHECK(vec_from_swizzle2.y == 5.0f);

	std::math::vec<float, 2> normalized_vec_from_swizzle2 = normalize(sw2.to_vec());
	CHECK(std::math::float_equal(normalized_vec_from_swizzle2.x, 0.624695));
	CHECK(std::math::float_equal(normalized_vec_from_swizzle2.y, 0.780869));
}

TEST_CASE("vec<float, 3>") {
	std::math::vec<float, 3> v5(6.0f);
	CHECK(v5.x == 6.0f);
	CHECK(v5.y == 6.0f);
	CHECK(v5.z == 6.0f);

	std::math::vec<float, 3> v6(7.0f, 8.0f);
	CHECK(v6.x == 7.0f);
	CHECK(v6.y == 8.0f);
	CHECK(v6.z == 0);

	std::math::vec<float, 3> v7(9.0f, 10.0f, 11.0f);
	CHECK(v7.x == 9.0f);
	CHECK(v7.y == 10.0f);
	CHECK(v7.z == 11.0f);

	std::math::vec<float, 3> cross_vec = cross(v6, v7);
	CHECK(cross_vec.x == 88);
	CHECK(cross_vec.y == -77);
	CHECK(cross_vec.z == -2);

	std::math::swizzle<float, 3> sw3 = v7.xyz();
	CHECK(*sw3.x == 9.0f);
	CHECK(*sw3.y == 10.0f);
	CHECK(*sw3.z == 11.0f);

	std::math::vec<float, 3> vec_from_swizzle3 = sw3.to_vec();
	CHECK(vec_from_swizzle3.x == 9.0f);
	CHECK(vec_from_swizzle3.y == 10.0f);
	CHECK(vec_from_swizzle3.z == 11.0f);

	std::math::vec<float, 3> normalized_vec_from_swizzle3 = normalize(sw3.to_vec());
	CHECK(std::math::float_equal(normalized_vec_from_swizzle3.x, 0.517892));
	CHECK(std::math::float_equal(normalized_vec_from_swizzle3.y, 0.575435));
	CHECK(std::math::float_equal(normalized_vec_from_swizzle3.z, 0.632979));
}

TEST_CASE("vec<float, 4>") {
	std::math::vec<float, 4> v8(12.0f);
	CHECK(v8.x == 12.0f);
	CHECK(v8.y == 12.0f);
	CHECK(v8.z == 12.0f);
	CHECK(v8.w == 12.0f);

	std::math::vec<float, 4> v9(13.0f, 14.0f);
	CHECK(v9.x == 13.0f);
	CHECK(v9.y == 14.0f);
	CHECK(v9.z == 0);
	CHECK(v9.w == 0);

	std::math::vec<float, 4> v10(15.0f, 16.0f, 17.0f);
	CHECK(v10.x == 15.0f);
	CHECK(v10.y == 16.0f);
	CHECK(v10.z == 17.0f);
	CHECK(v10.w == 0);

	std::math::vec<float, 4> v11(18.0f, 19.0f, 20.0f, 21.0f);
	CHECK(v11.x == 18.0f);
	CHECK(v11.y == 19.0f);
	CHECK(v11.z == 20.0f);
	CHECK(v11.w == 21.0f);

	std::math::swizzle<float, 4> sw4 = v11.wxyz();
	CHECK(*sw4.x == 21.0f);
	CHECK(*sw4.y == 18.0f);
	CHECK(*sw4.z == 19.0f);
	CHECK(*sw4.w == 20.0f);

	std::math::vec<float, 4> vec_from_swizzle4 = sw4.to_vec();
	CHECK(vec_from_swizzle4.x == 21.0f);
	CHECK(vec_from_swizzle4.y == 18.0f);
	CHECK(vec_from_swizzle4.z == 19.0f);
	CHECK(vec_from_swizzle4.w == 20.0f);

	std::math::vec<float, 4> normalized_vec_from_swizzle4 = normalize(sw4.to_vec());
	CHECK(std::math::float_equal(normalized_vec_from_swizzle4.x, 0.537579));
	CHECK(stdmath::float_equal(normalized_vec_from_swizzle4.y, 0.460782));
	CHECK(stdmath::float_equal(normalized_vec_from_swizzle4.z, 0.486381));
	CHECK(stdmath::float_equal(normalized_vec_from_swizzle4.w, 0.51198));

	auto v11x4 = v11 * 4;
	CHECK(v11x4 == std::math::vec<float, 4>{18 * 4, 19 * 4, 20 * 4, 21 * 4});
}

TEST_CASE("vec<int, 1>") {
	std::math::vec<int, 1> v1(1);
	CHECK(v1.x == 1);

	std::math::vec<int, 1> v2 = {2};
	CHECK(v2.x == 2);

	std::math::swizzle<int, 1> sw1 = v1._x();
	CHECK(*sw1.x == 1);
	std::math::vec<int, 1> vec_from_swizzle = sw1.to_vec();
	CHECK(vec_from_swizzle.x == 1);
}

TEST_CASE("vec<int, 2>") {
	std::math::vec<int, 2> v3(3);
	CHECK(v3.x == 3);
	CHECK(v3.y == 3);

	std::math::vec<int, 2> v4(4, 5);
	CHECK(v4.x == 4);
	CHECK(v4.y == 5);

	std::math::swizzle<int, 2> sw2 = v4.xy();
	CHECK(*sw2.x == 4);
	CHECK(*sw2.y == 5);
	std::math::vec<int, 2> vec_from_swizzle2 = sw2.to_vec();
	CHECK(vec_from_swizzle2.x == 4);
	CHECK(vec_from_swizzle2.y == 5);
}

TEST_CASE("vec<int, 3>") {
	std::math::vec<int, 3> v5(6);
	CHECK(v5.x == 6);
	CHECK(v5.y == 6);
	CHECK(v5.z == 6);

	std::math::vec<int, 3> v6(7, 8);
	CHECK(v6.x == 7);
	CHECK(v6.y == 8);
	CHECK(v6.z == 0);

	std::math::vec<int, 3> v7(9, 10, 11);
	CHECK(v7.x == 9);
	CHECK(v7.y == 10);
	CHECK(v7.z == 11);

	std::math::vec<int, 3> cross_vec = cross(v6, v7);
	CHECK(cross_vec.x == 88);
	CHECK(cross_vec.y == -77);
	CHECK(cross_vec.z == -2);

	std::math::swizzle<int, 3> sw3 = v7.xyz();
	CHECK(*sw3.x == 9);
	CHECK(*sw3.y == 10);
	CHECK(*sw3.z == 11);

	std::math::vec<int, 3> vec_from_swizzle3 = sw3.to_vec();
	CHECK(vec_from_swizzle3.x == 9);
	CHECK(vec_from_swizzle3.y == 10);
	CHECK(vec_from_swizzle3.z == 11);
}

TEST_CASE("vec<int, 4>") {
	std::math::vec<int, 4> v8(12);
	CHECK(v8.x == 12);
	CHECK(v8.y == 12);
	CHECK(v8.z == 12);
	CHECK(v8.w == 12);

	std::math::vec<int, 4> v9(13, 14);
	CHECK(v9.x == 13);
	CHECK(v9.y == 14);
	CHECK(v9.z == 0);
	CHECK(v9.w == 0);

	std::math::vec<int, 4> v10(15, 16, 17);
	CHECK(v10.x == 15);
	CHECK(v10.y == 16);
	CHECK(v10.z == 17);
	CHECK(v10.w == 0);

	std::math::vec<int, 4> v11(18, 19, 20, 21);
	CHECK(v11.x == 18);
	CHECK(v11.y == 19);
	CHECK(v11.z == 20);
	CHECK(v11.w == 21);

	std::math::swizzle<int, 4> sw4 = v11.wxyz();
	CHECK(*sw4.x == 21);
	CHECK(*sw4.y == 18);
	CHECK(*sw4.z == 19);
	CHECK(*sw4.w == 20);

	std::math::vec<int, 4> vec_from_swizzle4 = sw4.to_vec();
	CHECK(vec_from_swizzle4.x == 21);
	CHECK(vec_from_swizzle4.y == 18);
	CHECK(vec_from_swizzle4.z == 19);
	CHECK(vec_from_swizzle4.w == 20);
}

TEST_CASE("vec<float, 4> -> vec<int, 4>") {
	std::math::vec<float, 4> flt(18.1, 19.2, 20.3, 21.4);
	std::math::vec<int, 4> integ = flt;
	CHECK(integ.x == 18);
	CHECK(integ.y == 19);
	CHECK(integ.z == 20);
	CHECK(integ.w == 21);
}
