module;

#if !defined(__cpp_lib_submdspan) || __cpp_lib_submdspan < 202306L
	#define MDSPAN_IMPL_STANDARD_NAMESPACE stdmath
	#define MDSPAN_IMPL_PROPOSED_NAMESPACE experimental
	#include "../thirdparty/mdspan.hpp"
#endif

export module stdmath.matrix;

import std.compat;
import stdmath.simd;
import stdmath.vector;

namespace stdmath {
	export namespace stl {
#if !defined(__cpp_lib_submdspan) || __cpp_lib_submdspan < 202306L
		using stdmath::mdspan;
		using stdmath::extents;
		using stdmath::layout_right;
		using stdmath::submdspan;
		using stdmath::dynamic_extent;
		using stdmath::full_extent;
#else
		using std::mdspan;
		using std::extents;
		using std::layout_right;
		using std::submdspan;
		using std::dynamic_extent;
		using std::full_extent;
#endif
	}

	// Note: Matrices are stored row major.
	export template<typename T, size_t X, size_t Y>
	struct matrix {
		using self = matrix;
		using simd = stl::simd_or_mask<T, X * Y>;
		using underlying_type = T;

		std::array<T, X * Y> data;

		matrix() { data.fill(0); }
		matrix(const std::array<T, X * Y>& data) : data(data) {}
		matrix(const matrix&) = default;
		matrix(matrix&&) = default;
		matrix& operator=(const matrix&) = default;
		matrix& operator=(matrix&&) = default;

		template<typename To>
		matrix(const matrix<To, X, Y>& o) {
			auto range = std::views::iota(size_t{0}, X * Y);
		#ifdef __clang__
			std::for_each(range.begin(), range.end(), [&](size_t i) {
		#else
			std::for_each(std::execution::par_unseq, range.begin(), range.end(), [&](size_t i) {
		#endif
				data[i] = T(o.data[i]);
			});
		}

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


		auto begin() { return data.begin(); }
		auto end() { return data.end(); }

		simd to_simd() const { return {data.data(), stl::element_aligned}; }
		void from_simd(const simd& simd) { simd.copy_to(data.data(), stl::element_aligned); }
		static self make_from_simd(const simd& simd) { self out; out.from_simd(simd); return out; }



		static self add(const self& a, const self& b) {
			return make_from_simd(a.to_simd() + b.to_simd());
		}

		static self subtract(const self& a, const self& b) {
			return make_from_simd(a.to_simd() - b.to_simd());
		}

		static self negate(const self& a)
			requires(requires(T t) { { -t } -> std::convertible_to<T>; })
		{
			return make_from_simd(-a.to_simd());
		}


		template<size_t Xo, size_t Yo>
		static matrix<T, X, Yo>& multiply(matrix<T, X, Yo>& out, const matrix& a, const matrix<T, Xo, Yo>& b) {
			static_assert(Y == Xo, "The left matrix must have the same number of rows as there are columns of the right matrix!");
#if __has_include(<linalg>)
			std::linalg::matrix_product(a.mdspan(), b.mdspan(), out.mdspan());
#else
			for (size_t i = 0; i < X; ++i)
				for (size_t k = 0; k < Y; ++k) {
					const T aik = a[i, k];
					for (size_t j = 0; j < Yo; ++j)
						out[i, j] += aik * b[k, j];
				}
#endif
			return out;
		}
		template<size_t Xo, size_t Yo>
		static matrix<T, X, Yo> multiply(const matrix& a, const matrix<T, Xo, Yo>& b) {
			matrix<T, X, Yo> out; return multiply(out, a, b);
		}

		friend matrix& scale(matrix& out, const matrix& a, const T& b) {
			return multiply(out, a, matrix::identity(b));
		}
		static matrix multiply(const matrix& a, const T& b) {
			matrix out;
			return scale(out, a, b);
		}

		static matrix divide(const matrix& a, const T& b) {
			matrix out;
			return scale(out, a, 1 / b);
		}

		template<std::convertible_to<T> Tlike>
		static vector<T, Y> multiply(const matrix& a, const vector<Tlike, Y>& b) {
			vector<T, Y> out {T{}};
#if __has_include(<linalg>)
			std::linalg::matrix_vector_product(a.mdspan(), std::mdspan(&b.x, Y), std::mdspan(&out.x, Y));
#else

			for (size_t i = 0; i < X; ++i) {
				T sum = T{};
				for (size_t j = 0; j < Y; ++j)
					sum += a[i, j] * b[j];
				out[i] = sum;
			}
#endif
			return out;
		}
		template<std::convertible_to<T> Tlike>
		friend vector<T, Y> operator*(const matrix& a, const vector<Tlike, Y>& b) {
			return multiply(a, b);
		}

		auto mdspan() { return stl::mdspan<T, stl::extents<size_t, X, Y>, stl::layout_right>{data.data()}; }
		auto mdspan() const { return stl::mdspan<const T, stl::extents<size_t, X, Y>, stl::layout_right>{data.data()}; }

		operator std::span<T>() { return data; }
		operator std::span<const T>() const { return data; }

		#include "../partials/operators.partial"
		// #define STDMATH_COMPARISON_BOOLEAN_TYPE bool
		// #include "../partials/operators.comparison.partial"
	};

	export template<typename T, size_t X, size_t Y>
	constexpr matrix<T, Y, X>& transpose(matrix<T, Y, X>& out, const matrix<T, X, Y>& in) {
		for (std::size_t i = 0; i < X; ++i)
			for (std::size_t j = 0; j < Y; ++j)
				out[j, i] = in[i, j];

		return out;
	}
	export template<typename T, size_t X, size_t Y>
	constexpr matrix<T, Y, X> transpose(const matrix<T, X, Y>& matrix) { stdmath::matrix<T, Y, X> out; return transpose(out, matrix); }

	export template<typename T, size_t N>
	constexpr matrix<T, N, N> inverse(matrix<T, N, N> A) {
		matrix<T, N, N> I = matrix<T, N, N>::identity();

		using simd_t = stl::native_simd<T>;
		constexpr size_t simd_size = simd_t::size();

		for (size_t i = 0; i < N; ++i) {
			// Find the pivot
			T pivot = A[i, i];
			if (pivot == T{}) throw std::runtime_error("Matrix is singular and cannot be inverted.");

			size_t j = 0;

			if constexpr(stl::simd_available) {
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
			}

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

				if constexpr(stl::simd_available) {
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
				}

				// Handle remaining elements
				for (; j < N; ++j) {
					A[k, j] -= factor * A[i, j];
					I[k, j] -= factor * I[i, j];
				}
			}
		}
		return I;
	}

	export template<typename T, size_t X, size_t Y>
	std::ostream& operator<<(std::ostream& out, const matrix<T, X, Y>& m) {
		out << "[";
		for(size_t i = 0; i < X * Y; ++i) {
			if(i > 0) out << ", ";
			if constexpr(sizeof(T) == 1)
				out << (int)m.data[i];
			else out << m.data[i];
		}
		return out << "]";
	}
}

export template<typename T, size_t X, size_t Y>
struct std::formatter<stdmath::matrix<T, X, Y>> {
	std::formatter<T> elem_formatter;

	constexpr auto parse(std::format_parse_context& ctx) {
		return elem_formatter.parse(ctx);
	}

	template<typename FormatContext>
	auto format(const stdmath::matrix<T, X, Y>& m, FormatContext& ctx) const {
		auto out = std::format_to(ctx.out(), "[");
		for (std::size_t i = 0; i < X * Y; ++i) {
			if (i > 0) out = std::format_to(out, ", ");
			out = elem_formatter.format(m.data[i], ctx);
		}
		return std::format_to(out, "]");
	}
};