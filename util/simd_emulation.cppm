module;

#if __has_include(<simd>)
	#include <simd>
// #elif __has_include(<experimental/simd>)
// 	#include <experimental/simd>
// 	namespace stdmath::stl {
// 		using namespace std::experimental;
// 	}
#else
	#define STD_MATH_SIMD_UNAVAILABLE
#endif

import std.compat;

export module stdmath.simd;

namespace stdmath { namespace stl {
	export using std::array;

#ifdef STD_MATH_SIMD_UNAVAILABLE
	export constexpr struct vector_aligned_tag{} vector_aligned;
	export constexpr struct element_aligned_tag{} element_aligned;
	export template<typename T> struct native_simd {
		constexpr static size_t size() { return 0; }
	};
#else
	export using std::vector_aligned;
	export using std::element_aligned;
	export using std::native_simd;
#endif

	export template<typename T, size_t N>
	struct simd_emulation : protected array<T, N> {
		using super = std::array<T, N>;
		using typename super::value_type;
		using super::begin;
		using super::end;
		using super::operator[];

		constexpr static size_t size() { return N; }

		simd_emulation() {}
		simd_emulation(const simd_emulation&) = default;
		simd_emulation(simd_emulation&&) = default;
		simd_emulation& operator=(const simd_emulation&) = default;
		simd_emulation& operator=(simd_emulation&&) = default;

		simd_emulation(const T* data, vector_aligned_tag) {
			std::copy(data, data + N, this->data());
		}

		void copy_to(T* data, vector_aligned_tag) const {
			std::copy(this->begin(), this->end(), data);
		}

		friend simd_emulation min(const simd_emulation& a, const simd_emulation& b) {
			simd_emulation out;
			for(size_t i = 0; i < N; ++i)
				out[i] = std::min(a[i], b[i]);
			return out;
		}
		friend simd_emulation max(const simd_emulation& a, const simd_emulation& b) {
			simd_emulation out;
			for(size_t i = 0; i < N; ++i)
				out[i] = std::max(a[i], b[i]);
			return out;
		}

		friend T hmin(const simd_emulation& a) {
			return std::min_element(a.begin(), a.end());
		}
		friend T hmax(const simd_emulation& a) {
			return std::max_element(a.begin(), a.end());
		}
		friend T reduce(const simd_emulation& a) {
			return std::reduce(a.begin(), a.end());
		}

	#define stdmath_simd_emulation_parallel_binary_operation(op)\
		friend simd_emulation operator op(const simd_emulation& a, const simd_emulation& b)\
		requires(requires(T t) { { t op t } -> std::convertible_to<T>; } && !requires() {std::execution::par_unseq;})\
		{\
			simd_emulation out;\
			for(size_t i = 0; i < N; ++i)\
				out[i] = a[i] op b[i];\
			return out;\
		}\
		friend simd_emulation operator op(const simd_emulation& a, const simd_emulation& b)\
		requires(requires(T t) { { t op t } -> std::convertible_to<T>; }  && requires() {std::execution::par_unseq;})\
		{\
			simd_emulation out;\
			auto range = std::views::iota(size_t{0}, N);\
			std::for_each(std::execution::par_unseq, range.begin(), range.end(), [&](size_t i) {\
				out[i] = a[i] op b[i];\
			});\
			return out;\
		}
	#define stdmath_simd_emulation_parallel_prefix_unary_operation(op)\
		friend simd_emulation operator op(const simd_emulation& a)\
		requires(requires(T t) { { op t } -> std::convertible_to<T>; } && !requires() {std::execution::par_unseq;})\
		{\
			simd_emulation out;\
			for(size_t i = 0; i < N; ++i)\
				out[i] = op a[i];\
			return out;\
		}\
		friend simd_emulation operator op(const simd_emulation& a)\
		requires(requires(T t) { { op t } -> std::convertible_to<T>; } && requires() {std::execution::par_unseq;})\
		{\
			simd_emulation out;\
			auto range = std::views::iota(size_t{0}, N);\
			std::for_each(std::execution::par_unseq, range.begin(), range.end(), [&](size_t i) {\
				out[i] = op a[i];\
			});\
			return out;\
		}
	#define stdmath_simd_emulation_parallel_postfix_unary_operation(op)\
			friend simd_emulation operator op(const simd_emulation& a)\
			requires(requires(T t) { { t op } -> std::convertible_to<T>; } && !requires() {std::execution::par_unseq;})\
			{\
				simd_emulation out;\
				for(size_t i = 0; i < N; ++i)\
					out[i] = a[i] op;\
				return out;\
			}\
			friend simd_emulation operator op(const simd_emulation& a)\
			requires(requires(T t) { { t op } -> std::convertible_to<T>; } && requires() {std::execution::par_unseq;})\
			{\
				simd_emulation out;\
				auto range = std::views::iota(size_t{0}, N);\
				std::for_each(std::execution::par_unseq, range.begin(), range.end(), [&](size_t i) {\
					out[i] = a[i] op;\
				});\
				return out;\
			}

		stdmath_simd_emulation_parallel_binary_operation(+)
		stdmath_simd_emulation_parallel_binary_operation(-)
		stdmath_simd_emulation_parallel_binary_operation(*)
		stdmath_simd_emulation_parallel_binary_operation(/)
		stdmath_simd_emulation_parallel_binary_operation(%)

		stdmath_simd_emulation_parallel_prefix_unary_operation(!)
		stdmath_simd_emulation_parallel_prefix_unary_operation(~)

		stdmath_simd_emulation_parallel_binary_operation(&)
		stdmath_simd_emulation_parallel_binary_operation(&&)
		stdmath_simd_emulation_parallel_binary_operation(|)
		stdmath_simd_emulation_parallel_binary_operation(||)
		stdmath_simd_emulation_parallel_binary_operation(^)

	#define stdmath_simd_emulation_parallel_relational_operation(op)\
		friend simd_emulation<bool, N> operator op(const simd_emulation& a, const simd_emulation& b)\
		requires(requires(T t) { { t op t } -> std::convertible_to<T>; } && !requires() {std::execution::par_unseq;})\
		{\
			simd_emulation<bool, N> out;\
			for(size_t i = 0; i < N; ++i)\
				out[i] = a[i] op b[i];\
			return out;\
		}\
		friend simd_emulation<bool, N> operator op(const simd_emulation& a, const simd_emulation& b)\
		requires(requires(T t) { { t op t } -> std::convertible_to<T>; } && requires() {std::execution::par_unseq;})\
		{\
			simd_emulation<bool, N> out;\
			auto range = std::views::iota(size_t{0}, N);\
			std::for_each(std::execution::par_unseq, range.begin(), range.end(), [&](size_t i) {\
				out[i] = a[i] op b[i];\
			});\
			return out;\
		}

		stdmath_simd_emulation_parallel_relational_operation(==)
		stdmath_simd_emulation_parallel_relational_operation(!=)
		stdmath_simd_emulation_parallel_relational_operation(<)
		stdmath_simd_emulation_parallel_relational_operation(<=)
		stdmath_simd_emulation_parallel_relational_operation(>)
		stdmath_simd_emulation_parallel_relational_operation(>=)

	};

#ifndef STD_MATH_SIMD_UNAVAILABLE
	export template<typename T, size_t N>
	using simd_or_mask = std::conditional_t<N < 32,
		std::conditional_t<std::is_same_v<T, bool>, std::simd_mask<float, std::simd_abi::fixed_size<N>>, std::simd<T, std::simd_abi::fixed_size<N>>>,
		std::simd_emulation<T, N>
	>;

	export constexpr bool simd_available = true;
#else
	export template<typename T, size_t N>
	using simd_or_mask = simd_emulation<T, N>;

	export constexpr bool simd_available = false;
#endif

	} // stl

	export template<size_t N>
	bool all_of(const stl::simd_emulation<bool, N>& simd) {
		return std::reduce(simd.begin(), simd.end(), true, std::logical_and<bool>{});
	}
	export template<size_t N>
	bool any_of(const stl::simd_emulation<bool, N>& simd) {
		return std::reduce(simd.begin(), simd.end(), false, std::logical_or<bool>{});
	}
	export template<size_t N>
	bool none_of(const stl::simd_emulation<bool, N>& simd) {
		return !any_of(simd);
	}
	export template<size_t N>
	bool some_of(const stl::simd_emulation<bool, N>& simd) {
		return any_of(simd) && !all_of(simd);
	}

}