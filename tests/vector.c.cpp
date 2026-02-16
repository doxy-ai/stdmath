#include <doctest/doctest.h>
#include <math/c/stdmath.h>

TEST_CASE("float1") {
	stdmath_float1 v1 = stdmath_float1_broadcast(1);
	CHECK(v1.x == 1);

	stdmath_float1 v2 = {2};
	CHECK(v2.x == 2);

	stdmath_float1 sw1 = stdmath_float1_x(v1);
	CHECK(sw1.x == 1);
}

TEST_CASE("float2") {
	stdmath_float2 v3 = stdmath_float2_broadcast(3);
	CHECK(v3.x == 3);
	CHECK(v3.y == 3);

	stdmath_float2 v4 = {4, 5};
	CHECK(v4.x == 4);
	CHECK(v4.y == 5);

	stdmath_float2 sw2 = stdmath_float2_xy(v4);
	CHECK(sw2.x == 4);
	CHECK(sw2.y == 5);

	stdmath_float2 normalized_vector_from_swizzle2 = stdmath_float2_normalize(sw2);
	CHECK(stdmath_approximately_equal(normalized_vector_from_swizzle2.x, 0.6246950476));
	CHECK(stdmath_approximately_equal(normalized_vector_from_swizzle2.y, 0.7808688094));
}

TEST_CASE("float3") {
	stdmath_float3 v5 = stdmath_float3_broadcast(6);
	CHECK(v5.x == 6);
	CHECK(v5.y == 6);
	CHECK(v5.z == 6);

	stdmath_float3 v6 = {7, 8};
	CHECK(v6.x == 7);
	CHECK(v6.y == 8);
	CHECK(v6.z == 0);

	stdmath_float3 v7 = {9, 10, 11};
	CHECK(v7.x == 9);
	CHECK(v7.y == 10);
	CHECK(v7.z == 11);

	stdmath_float3 cross_vector = stdmath_float3_cross(v6, v7);
	CHECK(cross_vector.x == 88);
	CHECK(cross_vector.y == -77);
	CHECK(cross_vector.z == -2);

	stdmath_float3 sw3 = stdmath_float3_xyz(v7);
	CHECK(sw3.x == 9);
	CHECK(sw3.y == 10);
	CHECK(sw3.z == 11);

	stdmath_float3 normalized_vector_from_swizzle3 = stdmath_float3_normalize(sw3);
	CHECK(stdmath_approximately_equal(normalized_vector_from_swizzle3.x, 0.5178918039));
	CHECK(stdmath_approximately_equal(normalized_vector_from_swizzle3.y, 0.5754353376));
	CHECK(stdmath_approximately_equal(normalized_vector_from_swizzle3.z, 0.6329788714));
}

TEST_CASE("float4") {
	stdmath_float4 v8 = stdmath_float4_broadcast(12);
	CHECK(v8.x == 12);
	CHECK(v8.y == 12);
	CHECK(v8.z == 12);
	CHECK(v8.w == 12);

	stdmath_float4 v9 = {13, 14};
	CHECK(v9.x == 13);
	CHECK(v9.y == 14);
	CHECK(v9.z == 0);
	CHECK(v9.w == 0);

	stdmath_float4 v10 = {15, 16, 17};
	CHECK(v10.x == 15);
	CHECK(v10.y == 16);
	CHECK(v10.z == 17);
	CHECK(v10.w == 0);

	stdmath_float4 v11 = {18, 19, 20, 21};
	CHECK(v11.x == 18);
	CHECK(v11.y == 19);
	CHECK(v11.z == 20);
	CHECK(v11.w == 21);

	stdmath_float4 sw4 = stdmath_float4_wxyz(v11);
	CHECK(sw4.x == 21);
	CHECK(sw4.y == 18);
	CHECK(sw4.z == 19);
	CHECK(sw4.w == 20);

	stdmath_float4 normalized_vector_from_swizzle4 = stdmath_float4_normalize(sw4);
	CHECK(stdmath_approximately_equal(normalized_vector_from_swizzle4.x, 0.5375786693));
	CHECK(stdmath_approximately_equal(normalized_vector_from_swizzle4.y, 0.4607817165));
	CHECK(stdmath_approximately_equal(normalized_vector_from_swizzle4.z, 0.4863807008));
	CHECK(stdmath_approximately_equal(normalized_vector_from_swizzle4.w, 0.5119796850));

	auto v11x4 = stdmath_float4_scale(v11, 4);
	CHECK(stdmath_bool4_all_of(stdmath_float4_approximately_equal(v11x4, stdmath_float4{18 * 4, 19 * 4, 20 * 4, 21 * 4})));
}

TEST_CASE("int1") {
	stdmath_int1 v1 = {1};
	CHECK(v1.x == 1);

	stdmath_int1 v2 = {2};
	CHECK(v2.x == 2);

	stdmath_int1 sw1 = stdmath_int1_x(v1);
	CHECK(sw1.x == 1);
}

TEST_CASE("int2") {
	stdmath_int2 v3 = stdmath_int2_broadcast(3);
	CHECK(v3.x == 3);
	CHECK(v3.y == 3);

	stdmath_int2 v4 = {4, 5};
	CHECK(v4.x == 4);
	CHECK(v4.y == 5);

	stdmath_int2 sw2 = stdmath_int2_xy(v4);
	CHECK(sw2.x == 4);
	CHECK(sw2.y == 5);
}

TEST_CASE("int3") {
	stdmath_int3 v5 = stdmath_int3_broadcast(6);
	CHECK(v5.x == 6);
	CHECK(v5.y == 6);
	CHECK(v5.z == 6);

	stdmath_int3 v6 = {7, 8};
	CHECK(v6.x == 7);
	CHECK(v6.y == 8);
	CHECK(v6.z == 0);

	stdmath_int3 v7 = {9, 10, 11};
	CHECK(v7.x == 9);
	CHECK(v7.y == 10);
	CHECK(v7.z == 11);

	stdmath_int3 cross_vector = stdmath_int3_cross(v6, v7);
	CHECK(cross_vector.x == 88);
	CHECK(cross_vector.y == -77);
	CHECK(cross_vector.z == -2);

	stdmath_int3 sw3 = stdmath_int3_xyz(v7);
	CHECK(sw3.x == 9);
	CHECK(sw3.y == 10);
	CHECK(sw3.z == 11);
}

TEST_CASE("int4") {
	stdmath_int4 v8 = stdmath_int4_broadcast(12);
	CHECK(v8.x == 12);
	CHECK(v8.y == 12);
	CHECK(v8.z == 12);
	CHECK(v8.w == 12);

	stdmath_int4 v9 = {13, 14};
	CHECK(v9.x == 13);
	CHECK(v9.y == 14);
	CHECK(v9.z == 0);
	CHECK(v9.w == 0);

	stdmath_int4 v10 = {15, 16, 17};
	CHECK(v10.x == 15);
	CHECK(v10.y == 16);
	CHECK(v10.z == 17);
	CHECK(v10.w == 0);

	stdmath_int4 v11 = {18, 19, 20, 21};
	CHECK(v11.x == 18);
	CHECK(v11.y == 19);
	CHECK(v11.z == 20);
	CHECK(v11.w == 21);

	stdmath_int4 sw4 = stdmath_int4_wxyz(v11);
	CHECK(sw4.x == 21);
	CHECK(sw4.y == 18);
	CHECK(sw4.z == 19);
	CHECK(sw4.w == 20);
}

TEST_CASE("float4 operators (C API)") {

    stdmath_float4 a = stdmath_float4{1, 2, 3, 4};
    stdmath_float4 b = stdmath_float4{4, 3, 2, 1};
    stdmath_float4 c = stdmath_float4{1, 2, 3, 4};

    // --- Accessors ---
    CHECK(a.x == 1);
    CHECK(a.y == 2);
    CHECK(a.z == 3);
    CHECK(a.w == 4);

    // --- Equality / Inequality ---
    CHECK(stdmath_bool4_all_of(stdmath_float4_equal_to(a, c)));
    CHECK(stdmath_bool4_none_of(stdmath_float4_not_equal_to(a, c)));
    CHECK(stdmath_bool4_all_of(stdmath_float4_not_equal_to(a, b)));
    CHECK(stdmath_bool4_none_of(stdmath_float4_equal_to(a, b)));

    // --- Relational operators ---
    CHECK(stdmath_bool4_all_of(
        stdmath_float4_less_than(a, stdmath_float4{2, 3, 4, 5})
    ));
    CHECK(stdmath_bool4_all_of(
        stdmath_float4_less_than_or_equal_to(a, c)
    ));
    CHECK(stdmath_bool4_all_of(
        stdmath_float4_greater_than(b, stdmath_float4{1, 1, 1, 0.5f})
    ));
    CHECK(stdmath_bool4_all_of(
        stdmath_float4_greater_than_or_equal_to(b, stdmath_float4{4, 3, 2, 1})
    ));

    // --- Unary operators ---
    CHECK(stdmath_bool4_all_of(
        stdmath_float4_equal_to(
            stdmath_float4_negate(a),
            stdmath_float4{-1, -2, -3, -4}
        )
    ));

    // --- Vector arithmetic ---
    CHECK(stdmath_bool4_all_of(
        stdmath_float4_equal_to(
            stdmath_float4_add(a, b),
            stdmath_float4{5, 5, 5, 5}
        )
    ));
    CHECK(stdmath_bool4_all_of(
        stdmath_float4_equal_to(
            stdmath_float4_subtract(a, b),
            stdmath_float4{-3, -1, 1, 3}
        )
    ));
    CHECK(stdmath_bool4_all_of(
        stdmath_float4_equal_to(
            stdmath_float4_multiply(a, b),
            stdmath_float4{4, 6, 6, 4}
        )
    ));
    CHECK(stdmath_bool4_all_of(
        stdmath_float4_equal_to(
            stdmath_float4_divide(a, b),
            stdmath_float4{0.25f, 0.6666667f, 1.5f, 4.0f}
        )
    ));

    // --- Scalar arithmetic ---
    CHECK(stdmath_bool4_all_of(
        stdmath_float4_equal_to(
            stdmath_float4_add(a, stdmath_float4_broadcast(1)),
            stdmath_float4{2, 3, 4, 5}
        )
    ));
    CHECK(stdmath_bool4_all_of(
        stdmath_float4_equal_to(
            stdmath_float4_subtract(a, stdmath_float4_broadcast(1)),
            stdmath_float4{0, 1, 2, 3}
        )
    ));
    CHECK(stdmath_bool4_all_of(
        stdmath_float4_equal_to(
            stdmath_float4_scale(a, 2),
            stdmath_float4{2, 4, 6, 8}
        )
    ));
    CHECK(stdmath_bool4_all_of(
        stdmath_float4_equal_to(
            stdmath_float4_scale(a, 1.0/2),
            stdmath_float4{0.5f, 1.0f, 1.5f, 2.0f}
        )
    ));
}
