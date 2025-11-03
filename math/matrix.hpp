#pragma once

#include "vector.hpp"

namespace stdmath {
	// Note: Matrices are stored column major.
	template<typename T, size_t X, size_t Y>
	struct matrix {
		using self = matrix;
		using simd = simd_or_mask<T, X * Y>;
		using underlying_type = T;

#ifndef STD_MATH_SIMD_UNAVAILABLE
		alignas(stl::memory_alignment_v<simd>)
#endif
		std::array<T, X * Y> data;

		constexpr static matrix identity(const T& scaler = 1) {
			matrix out;
			for(size_t x = 0; x < X; ++x)
				for(size_t y = 0; y < Y; ++y)
					out[x, y] = (x == y) * scaler;
			return out;
		}
		constexpr static matrix fill(const T& v = {}) {
			matrix out;
			out.data.fill(v);
			return out;
		}

		T& operator[](size_t x, size_t y) { return mdspan()[x, y]; }
		const T& operator[](size_t x, size_t y) const { return mdspan()[x, y]; }

		#include "partials/mat.operators.partial"

		template<size_t Xo, size_t Yo>
		friend matrix<T, X, Yo>& multiply(matrix<T, X, Yo>& out, const matrix& a, const matrix<T, Xo, Yo>& b) {
			static_assert(Y == Xo, "The left matrix must have the same number of rows as there are columns of the right matrix!");
			stl::linalg::matrix_product(a.mdspan(), b.mdspan(), out.mdspan());
			return out;
		}
		template<size_t Xo, size_t Yo>
		friend matrix<T, X, Yo> operator*(const matrix& a, const matrix<T, Xo, Yo>& b) {
			matrix<T, X, Yo> out; return multiply(out, a, b);
		}

		friend matrix& scale(matrix& out, const matrix& a, const T& b) {
			return multiply(out, a, matrix::identity(b));
		}
		template<std::convertible_to<T> Tlike>
		friend matrix operator*(const matrix& a, const Tlike& b) {
			matrix out; return scale(out, a, b);
		}
		template<std::convertible_to<T> Tlike>
		friend matrix operator*(const Tlike& a, const matrix& b) {
			return b * a;
		}
		template<std::convertible_to<T> Tlike>
		friend matrix operator/(const matrix& a, const Tlike& b) {
			matrix out; return scale(out, a, Tlike(1) / b);
		}

		template<std::convertible_to<T> Tlike>
		friend vector<T, Y> operator*(const matrix& a, const vector<Tlike, Y>& b) {
			vector<T, Y> out;
			stl::linalg::matrix_vector_product(a.mdspan(), stl::mdspan(&b.x, Y), stl::mdspan(&out.x, Y));
			return out;
		}


		auto mdspan() { return stl::mdspan<T, stl::extents<size_t, X, Y>, stl::layout_right>(data.data()); }
		auto mdspan() const { return stl::mdspan<const T, stl::extents<size_t, X, Y>, stl::layout_right>(data.data()); }
		operator std::span<T>() { return data; }
		operator std::span<const T>() const { return data; }
	};

	template<typename T, size_t X, size_t Y>
	constexpr matrix<T, Y, X>& transpose(matrix<T, Y, X>& out, const matrix<T, X, Y>& in) {
		for (std::size_t i = 0; i < X; ++i)
			for (std::size_t j = 0; j < Y; ++j)
				out[j, i] = in[i, j];

		return out;
	}
	template<typename T, size_t X, size_t Y>
	constexpr matrix<T, Y, X> transpose(const matrix<T, X, Y>& matrix) { stdmath::matrix<T, Y, X> out; return transpose(out, matrix); }

	template<typename T, size_t N>
	constexpr matrix<T, N, N> inverse(matrix<T, N, N> A) {
		matrix<T, N, N> I = matrix<T, N, N>::identity();
		
#ifndef STD_MATH_SIMD_UNAVAILABLE
		using simd_t = stl::native_simd<T>;
		constexpr size_t simd_size = simd_t::size();
#endif
		
		for (size_t i = 0; i < N; ++i) {
			// Find the pivot
			T pivot = A[i, i];
			if (pivot == T{}) throw std::runtime_error("Matrix is singular and cannot be inverted.");
			
			size_t j = 0;
#ifndef STD_MATH_SIMD_UNAVAILABLE
			// Broadcast pivot for SIMD operations
			simd_t pivot_vec(pivot);
			
			// Normalize the pivot row using SIMD
			for (; j + simd_size <= N; j += simd_size) {
				simd_t a_vec, i_vec;
				a_vec.copy_from(&A[i, j], stl::element_aligned);
				i_vec.copy_from(&I[i, j], stl::element_aligned);
				
				a_vec /= pivot_vec;
				i_vec /= pivot_vec;
				
				a_vec.copy_to(&A[i, j], stl::element_aligned);
				i_vec.copy_to(&I[i, j], stl::element_aligned);
			}
#endif
			// Handle remaining elements
			for (; j < N; ++j) {
				A[i, j] /= pivot;
				I[i, j] /= pivot;
			}
			
			// Eliminate other rows
			for (size_t k = 0; k < N; ++k) {
				if (k == i) continue;
				
				j = 0;
				T factor = A[k, i];
#ifndef STD_MATH_SIMD_UNAVAILABLE
				simd_t factor_vec(factor);
				
				// SIMD elimination
				for (; j + simd_size <= N; j += simd_size) {
					simd_t a_k_vec, a_i_vec, i_k_vec, i_i_vec;
					
					a_k_vec.copy_from(&A[k, j], stl::element_aligned);
					a_i_vec.copy_from(&A[i, j], stl::element_aligned);
					i_k_vec.copy_from(&I[k, j], stl::element_aligned);
					i_i_vec.copy_from(&I[i, j], stl::element_aligned);
					
					a_k_vec -= factor_vec * a_i_vec;
					i_k_vec -= factor_vec * i_i_vec;
					
					a_k_vec.copy_to(&A[k, j], stl::element_aligned);
					i_k_vec.copy_to(&I[k, j], stl::element_aligned);
				}
#endif
				// Handle remaining elements
				for (; j < N; ++j) {
					A[k, j] -= factor * A[i, j];
					I[k, j] -= factor * I[i, j];
				}
			}
		}
		return I;
	}
}