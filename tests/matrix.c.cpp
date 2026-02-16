#include <doctest/doctest.h>
#include <math/c/stdmath.h>

TEST_CASE("stdmath_float2x2::identity()") {
	stdmath_float2x2 identity_matrix = stdmath_float2x2_identity();
	CHECK(stdmath_float2x2_get_element(&identity_matrix, 0, 0) == 1.f);
	CHECK(stdmath_float2x2_get_element(&identity_matrix, 0, 1) == 0.f);
	CHECK(stdmath_float2x2_get_element(&identity_matrix, 1, 1) == 1.f);
	CHECK(stdmath_float2x2_get_element(&identity_matrix, 1, 0) == 0.f);
}

TEST_CASE("stdmath_float2x2::transpose()") {
	stdmath_float2x2 matrix = {{ 1, 2, 3, 4 }};
	stdmath_float2x2 transposed_matrix = stdmath_float2x2_transpose(&matrix);
	CHECK(stdmath_float2x2_get_element(&matrix, 0, 0) == 1.f);
	CHECK(stdmath_float2x2_get_element(&matrix, 0, 1) == 2.f);
	CHECK(stdmath_float2x2_get_element(&matrix, 1, 0) == 3.f);
	CHECK(stdmath_float2x2_get_element(&matrix, 1, 1) == 4.f);
	CHECK(stdmath_float2x2_get_element(&transposed_matrix, 0, 0) == 1.f);
	CHECK(stdmath_float2x2_get_element(&transposed_matrix, 0, 1) == 3.f);
	CHECK(stdmath_float2x2_get_element(&transposed_matrix, 1, 0) == 2.f);
	CHECK(stdmath_float2x2_get_element(&transposed_matrix, 1, 1) == 4.f);

	CHECK(transposed_matrix.data[0] == 1.f);
	CHECK(transposed_matrix.data[1] == 3.f);
	CHECK(transposed_matrix.data[2] == 2.f);
	CHECK(transposed_matrix.data[3] == 4.f);
}

TEST_CASE("stdmath_float2x2::inverse()") {
	stdmath_float2x2 matrix_to_invert = stdmath_float2x2 {{1, 2, 3, 4}};
	stdmath_float2x2 inv_matrix = stdmath_float2x2_inverse(&matrix_to_invert);
	CHECK(stdmath_float2x2_get_element(&inv_matrix, 0, 0) == -2.f);
	CHECK(stdmath_float2x2_get_element(&inv_matrix, 0, 1) == 1.f);
	CHECK(stdmath_float2x2_get_element(&inv_matrix, 1, 0) == 1.5f);
	CHECK(stdmath_float2x2_get_element(&inv_matrix, 1, 1) == -0.5f);

	stdmath_float2x2 ident = stdmath_float2x2_multiply2(&matrix_to_invert, &inv_matrix);
	for(size_t i = 0; i < 4; ++i) CHECK(ident.data[i] == stdmath_float2x2_identity().data[i]);
}