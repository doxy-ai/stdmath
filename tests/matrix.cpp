#include <doctest/doctest.h>
#include <math/namespace_alias.hpp>

import std.compat;
import stdmath;

using namespace std::math::types;

TEST_CASE("matrix<f32, 2, 2>::identity()") {
	std::math::matrix<f32, 2, 2> identity_matrix = std::math::matrix<f32, 2, 2>::identity();
	CHECK(identity_matrix[0, 0] == 1.f);
	CHECK(identity_matrix[0, 1] == 0.f);
	CHECK(identity_matrix[1, 1] == 1.f);
	CHECK(identity_matrix[1, 0] == 0.f);
}

TEST_CASE("matrix<f32, 2, 2>::transpose()") {
	std::math::matrix<f32, 2, 2> matrix = {{ 1, 2, 3, 4 }};
	std::math::matrix<f32, 2, 2> transposed_matrix = transpose(matrix);
	CHECK(matrix[0, 0] == 1.f);
	CHECK(matrix[0, 1] == 2.f);
	CHECK(matrix[1, 0] == 3.f);
	CHECK(matrix[1, 1] == 4.f);
	CHECK(transposed_matrix[0, 0] == 1.f);
	CHECK(transposed_matrix[0, 1] == 3.f);
	CHECK(transposed_matrix[1, 0] == 2.f);
	CHECK(transposed_matrix[1, 1] == 4.f);

	CHECK(transposed_matrix.data[0] == 1.f);
	CHECK(transposed_matrix.data[1] == 3.f);
	CHECK(transposed_matrix.data[2] == 2.f);
	CHECK(transposed_matrix.data[3] == 4.f);
}

TEST_CASE("matrix<f32, 2, 2>::inverse()") {
	std::math::matrix<f32, 2, 2> matrix_to_invert = std::math::matrix<f32, 2, 2> {{1, 2, 3, 4}};
	std::math::matrix<f32, 2, 2> inv_matrix = inverse(matrix_to_invert);
	CHECK(inv_matrix[0, 0] == -2.f);
	CHECK(inv_matrix[0, 1] == 1.f);
	CHECK(inv_matrix[1, 0] == 1.5f);
	CHECK(inv_matrix[1, 1] == -0.5f);

	std::math::matrix<f32, 2, 2> ident = matrix_to_invert * inv_matrix;
	for(auto v: ident) CHECK(ident.data[v] == std::math::matrix<f32, 2, 2>::identity().data[v]);
}

TEST_CASE("matrix<f32, 10, 10>::inverse()") {
	std::math::matrix<f32, 10, 10> matrix_to_invert = std::math::matrix<f32, 10, 10> {{
		4, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		0, 3, 0, 0, 0, 0, 0, 0, 1, 0,
		0, 0, 5, 0, 0, 0, 0, 1, 0, 0,
		0, 0, 0, 2, 0, 0, 1, 0, 0, 0,
		0, 0, 0, 0, 6, 1, 0, 0, 0, 0,
		0, 0, 0, 0, 1, 4, 0, 0, 0, 0,
		0, 0, 0, 1, 0, 0, 3, 0, 0, 0,
		0, 0, 1, 0, 0, 0, 0, 5, 0, 0,
		0, 1, 0, 0, 0, 0, 0, 0, 2, 0,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 7
	}};
	std::math::matrix<f32, 10, 10> inv_matrix = inverse(matrix_to_invert);
	std::math::matrix<f32, 10, 10> inverse_check = std::math::matrix<f32, 10, 10> {{
		6550, 0, 0, 0, 0, 0, 0, 0, 0, -920,
		0, 9936, 0, 0, 0, 0, 0, 0, -4968, 0,
		0, 0, 5175, 0, 0, 0, 0, -1035, 0, 0,
		0, 0, 0, 14904, 0, 0, -4968, 0, 0, 0,
		0, 0, 0, 0, 4320, -1080, 0, 0, 0, 0,
		0, 0, 0, 0, -1080, 6480, 0, 0, 0, 0,
		0, 0, 0, -4968, 0, 0, 9936, 0, 0, 0,
		0, 0, -1035, 0, 0, 0, 0, 5175, 0, 0,
		0, -4968, 0, 0, 0, 0, 0, 0, 14904, 0,
		-920, 0, 0, 0, 0, 0, 0, 0, 0, 3680
	}} / 24840;
	for(size_t i = 0; i < inv_matrix.data.size(); ++i)
		CHECK(std::math::approximately_equal(inv_matrix.data[i], inverse_check.data[i], 1));

	std::math::matrix<f32, 10, 10> ident = matrix_to_invert * inv_matrix;
	for(auto v: ident) CHECK(ident.data[v] == std::math::matrix<f32, 2, 2>::identity().data[v]);
}