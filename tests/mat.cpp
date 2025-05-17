#include <doctest/doctest.h>
#include <math/namespace_alias.hpp>

TEST_CASE("mat<float, 2, 2>::identity()") {
    std::math::mat<float, 2, 2> identity_mat = std::math::mat<float, 2, 2>::identity();
    CHECK(identity_mat[0, 0] == 1.0f);
    CHECK(identity_mat[0, 1] == 0.0f);
    CHECK(identity_mat[1, 1] == 1.0f);
    CHECK(identity_mat[1, 0] == 0.0f);
}

TEST_CASE("mat<float, 2, 2>::transpose()") {
    std::math::mat<float, 2, 2> mat = { 1, 2, 3, 4 };
    std::math::mat<float, 2, 2> transposed_mat = transpose(mat);
    CHECK(transposed_mat[0, 0] == 1.0f);
    CHECK(transposed_mat[0, 1] == 2.0f);
    CHECK(transposed_mat[1, 0] == 3.0f);
    CHECK(transposed_mat[1, 1] == 4.0f);

    CHECK(transposed_mat.data[0] == 1.0f);
    CHECK(transposed_mat.data[1] == 3.0f);
    CHECK(transposed_mat.data[2] == 2.0f);
    CHECK(transposed_mat.data[3] == 4.0f);
}

TEST_CASE("mat<float, 2, 2>::inverse()") {
    // Since matrices are stored column major, we need to transpose this row major data
    std::math::mat<float, 2, 2> inverse_mat = transpose(std::math::mat<float, 2, 2> {1, 2, 3, 4});
    std::math::mat<float, 2, 2> inv_mat = inverse(inverse_mat);
    CHECK(inv_mat[0, 0] == -2.0f);
    CHECK(inv_mat[0, 1] == 1.0f);
    CHECK(inv_mat[1, 0] == 1.5f);
    CHECK(inv_mat[1, 1] == -0.5f);

    std::math::mat<float, 2, 2> ident = inverse_mat * inv_mat;
    for(auto v: ident) CHECK(ident.data[v] == std::math::mat<float, 2, 2>::identity().data[v]);
}