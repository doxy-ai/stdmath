#pragma once

#include "vec.hpp"

namespace stdmath {
	template<typename T, size_t X, size_t Y>
	struct mat {
		using self = mat;
		using simd = stl::simd<T, stl::simd_abi::fixed_size<X * Y>>;
		using underlying_type = T;

		alignas(stl::memory_alignment_v<simd>)
		std::array<T, X * Y> data;

		static mat identity() {
			mat out;
			for(size_t x = 0; x < X; ++x)
				for(size_t y = 0; y < Y; ++y)
					out[x, y] = x == y;
			return out;
		}
		static mat fill(const T& v = {}) {
			mat out;
			out.data.fill(v);
			return out;
		}

		T& operator[](size_t x, size_t y) { return mdspan()[x, y]; }
		const T& operator[](size_t x, size_t y) const { return mdspan()[x, y]; }

		#include "partials/mat.operators.partial"

		template<size_t Xo, size_t Yo>
		friend mat<T, X, Yo>& multiply(mat<T, X, Yo>& out, const mat& a, const mat<T, Xo, Yo>& b) {
			static_assert(Y == Xo, "The left matrix must have the same number of rows as there are columns of the right matrix!");
			stl::linalg::matrix_product(a.mdspan(), b.mdspan(), out.mdspan());
			return out;
		}
		template<size_t Xo, size_t Yo>
		friend mat<T, X, Yo> operator*(const mat& a, const mat<T, Xo, Yo>& b) {
			mat<T, X, Yo> out; return multiply(out, a, b);
		}

		friend vec<T, Y> operator*(const mat& a, const vec<T, Y>& b) {
			vec<T, Y> out;
			stl::linalg::matrix_vector_product(a.mdspan(), stl::mdspan(&b.x, Y), stl::mdspan(&out.x, Y));
			return out;
		}


		auto mdspan() { return stl::mdspan<T, stl::extents<size_t, X, Y>, stl::layout_left>(data.data()); }
		auto mdspan() const { return stl::mdspan<const T, stl::extents<size_t, X, Y>, stl::layout_left>(data.data()); }
		operator std::span<T>() { return data; }
		operator std::span<const T>() const { return data; }
	};

	template<typename T, size_t X, size_t Y>
	mat<T, Y, X>& transpose(mat<T, Y, X>& out, const mat<T, X, Y>& in) {
		for (std::size_t i = 0; i < X; ++i)
			for (std::size_t j = 0; j < Y; ++j)
				out[j, i] = in[i, j];

		return out;
	}
	template<typename T, size_t X, size_t Y>
	mat<T, Y, X> transpose(const mat<T, X, Y>& mat) { stdmath::mat<T, Y, X> out; return transpose(out, mat); }

	// TODO: SIMD
	template<typename T, size_t N>
	mat<T, N, N> inverse(mat<T, N, N> A) { // Note we need a copy of A so just pass by value
		mat<T, N, N> I = mat<T, N, N>::identity();

		for (size_t i = 0; i < N; ++i) {
			// Find the pivot
			T pivot = A[i, i];
			if (pivot == T{}) throw std::runtime_error("Matrix is singular and cannot be inverted.");

			// Normalize the pivot row
			for (size_t j = 0; j < N; ++j) {
				A[i, j] /= pivot;
				I[i, j] /= pivot;
			}

			// Eliminate other rows
			for (size_t k = 0; k < N; ++k) {
				if (k == i) continue;
				T factor = A[k, i];
				for (size_t j = 0; j < N; ++j) {
					A[k, j] -= factor * A[i, j];
					I[k, j] -= factor * I[i, j];
				}
			}
		}
		return I;
	}
}