#include <doctest/doctest.h>
#include <stdmath.h>

TEST_CASE("C API: Vector 3") {
    math_float3 a = {1.0f, 2.0f, 3.0f};
    math_float3 b = {4.0f, 5.0f, 6.0f};

    math_float3 c = math_float3_add(a, b);
    CHECK(c.x == 5.0f);
    CHECK(c.y == 7.0f);
    CHECK(c.z == 9.0f);

    float d = math_float3_dot(a, b);
    CHECK(d == 1*4 + 2*5 + 3*6);

    math_float3 cross_res = math_float3_cross(a, b);
    // a x b = (2*6 - 3*5, 3*4 - 1*6, 1*5 - 2*4) = (12-15, 12-6, 5-8) = (-3, 6, -3)
    CHECK(cross_res.x == -3.0f);
    CHECK(cross_res.y == 6.0f);
    CHECK(cross_res.z == -3.0f);
}

TEST_CASE("C API: Matrix 4x4") {
    math_float4x4 identity = math_float4x4_identity();
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (i == j) CHECK(identity.data[i * 4 + j] == 1.0f);
            else CHECK(identity.data[i * 4 + j] == 0.0f);
        }
    }
}

TEST_CASE("C API: Quaternion") {
    math_quat q = math_quat_identity();
    CHECK(q.x == 0.0f);
    CHECK(q.y == 0.0f);
    CHECK(q.z == 0.0f);
    CHECK(q.w == 1.0f);

    math_float3 v = {1.0f, 0.0f, 0.0f};
    math_float3 rotated = math_quat_rotate_vector(q, v);
    CHECK(rotated.x == 1.0f);
    CHECK(rotated.y == 0.0f);
    CHECK(rotated.z == 0.0f);
}
