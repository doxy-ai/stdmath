#include "math/std.hpp"
#include <doctest/doctest.h>
#include <math/namespace_alias.hpp>

TEST_CASE("matrix<float, 2, 2>::identity()") {
	std::math::matrix<float, 2, 2> identity_matrix = std::math::matrix<float, 2, 2>::identity();
	CHECK(identity_matrix[0, 0] == 1.0f);
	CHECK(identity_matrix[0, 1] == 0.0f);
	CHECK(identity_matrix[1, 1] == 1.0f);
	CHECK(identity_matrix[1, 0] == 0.0f);
}

TEST_CASE("matrix<float, 2, 2>::transpose()") {
	std::math::matrix<float, 2, 2> matrix = { 1, 2, 3, 4 };
	std::math::matrix<float, 2, 2> transposed_matrix = transpose(matrix);
	CHECK(matrix[0, 0] == 1.0f);
	CHECK(matrix[0, 1] == 2.0f);
	CHECK(matrix[1, 0] == 3.0f);
	CHECK(matrix[1, 1] == 4.0f);
	CHECK(transposed_matrix[0, 0] == 1.0f);
	CHECK(transposed_matrix[0, 1] == 3.0f);
	CHECK(transposed_matrix[1, 0] == 2.0f);
	CHECK(transposed_matrix[1, 1] == 4.0f);

	CHECK(transposed_matrix.data[0] == 1.0f);
	CHECK(transposed_matrix.data[1] == 3.0f);
	CHECK(transposed_matrix.data[2] == 2.0f);
	CHECK(transposed_matrix.data[3] == 4.0f);
}

TEST_CASE("matrix<float, 2, 2>::inverse()") {
	std::math::matrix<float, 2, 2> inverse_matrix = std::math::matrix<float, 2, 2> {1, 2, 3, 4};
	std::math::matrix<float, 2, 2> inv_matrix = inverse(inverse_matrix);
	CHECK(inv_matrix[0, 0] == -2.0f);
	CHECK(inv_matrix[0, 1] == 1.0f);
	CHECK(inv_matrix[1, 0] == 1.5f);
	CHECK(inv_matrix[1, 1] == -0.5f);

	std::math::matrix<float, 2, 2> ident = inverse_matrix * inv_matrix;
	for(auto v: ident) CHECK(ident.data[v] == std::math::matrix<float, 2, 2>::identity().data[v]);
}

TEST_CASE("matrix<float, 10, 10>::inverse()") {
	std::math::matrix<float, 10, 10> inverse_matrix = std::math::matrix<float, 10, 10> {
		4.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
		0.0, 3.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
		0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
		0.0, 0.0, 0.0, 2.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
		0.0, 0.0, 0.0, 0.0, 6.0, 1.0, 0.0, 0.0, 0.0, 0.0,
		0.0, 0.0, 0.0, 0.0, 1.0, 4.0, 0.0, 0.0, 0.0, 0.0,
		0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 3.0, 0.0, 0.0, 0.0,
		0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 5.0, 0.0, 0.0,
		0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 2.0, 0.0,
		1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 7.0
	};
	std::math::matrix<float, 10, 10> inv_matrix = inverse(inverse_matrix);
	std::math::matrix<float, 10, 10> inverse_check = std::math::matrix<float, 10, 10> {
		6550, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -920,
		0.0, 9936, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -4968, 0.0,
		0.0, 0.0, 5175, 0.0, 0.0, 0.0, 0.0, -1035, 0.0, 0.0,
		0.0, 0.0, 0.0, 14904, 0.0, 0.0, -4968, 0.0, 0.0, 0.0,
		0.0, 0.0, 0.0, 0.0, 4320, -1080, 0.0, 0.0, 0.0, 0.0,
		0.0, 0.0, 0.0, 0.0, -1080, 6480, 0.0, 0.0, 0.0, 0.0,
		0.0, 0.0, 0.0, -4968, 0.0, 0.0, 9936, 0.0, 0.0, 0.0,
		0.0, 0.0, -1035, 0.0, 0.0, 0.0, 0.0, 5175, 0.0, 0.0,
		0.0, -4968, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 14904, 0.0,
		-920, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 3680
	} / 24840.0;
	for(size_t i = 0; i < inv_matrix.data.size(); ++i)
		CHECK(std::math::approximately_equal(inv_matrix.data[i], inverse_check.data[i], .01));

	std::math::matrix<float, 10, 10> ident = inverse_matrix * inv_matrix;
	for(auto v: ident) CHECK(ident.data[v] == std::math::matrix<float, 2, 2>::identity().data[v]);
}