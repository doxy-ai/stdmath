#pragma once

#include "std.hpp"
#include <algorithm>
#include <execution>
#include <initializer_list>
#include <ranges>
#include <type_traits>

namespace stdmath {
	#include "../partials/simd_emulation.partial"

#ifndef STD_MATH_SIMD_UNAVAILABLE
	template<typename T, size_t N>
	using simd_or_mask = std::conditional_t<N < 32,
		std::conditional_t<std::is_same_v<T, bool>, stl::simd_mask<float, stl::simd_abi::fixed_size<N>>, stl::simd<T, stl::simd_abi::fixed_size<N>>>,
		simd_emulation<T, N>
	>;
#else
	template<typename T, size_t N>
	using simd_or_mask = simd_emulation<T, N>;
#endif

	template<typename T, size_t N>
	struct vector {
		using self = vector;
		using simd = simd_or_mask<T, N>;
		using underlying_type = T;

		alignas(stl::memory_alignment_v<simd>)
		std::array<T, N> data;

		constexpr vector(T broadcast) { data.fill(broadcast); }
		constexpr vector(std::initializer_list<T> data) : data(data) {}
		#include "../partials/vec1.constructors.partial.gen"

		#include "../partials/vec.operators.partial"
	};

	template<typename T, size_t N>
	struct swizzle {
		using vector = stdmath::vector<T, N>;
		using underlying_type = T;
	};

	template<typename T>
	struct swizzle<T, 1> {
		using underlying_type = T;
		T* x;

		#include "../partials/vec1.swizzles.partial.gen"

		template<typename To>
		using vector = stdmath::vector<To, 1>;
		#include "../partials/swizzle.operators.partial"
	};

	template<typename T>
	struct swizzle<T, 2> {
		using underlying_type = T;
		T *x, *y;

		#include "../partials/vec2.swizzles.partial.gen"

		template<typename To>
		using vector = stdmath::vector<To, 2>;
		#include "../partials/swizzle.operators.partial"
	};

	template<typename T>
	struct swizzle<T, 3> {
		using underlying_type = T;
		T *x, *y, *z;

		#include "../partials/vec3.swizzles.partial.gen"

		template<typename To>
		using vector = stdmath::vector<To, 3>;
		#include "../partials/swizzle.operators.partial"
	};

	template<typename T>
	struct swizzle<T, 4> {
		using underlying_type = T;
		T *x, *y, *z, *w;

		#include "../partials/vec4.swizzles.partial.gen"

		template<typename To>
		using vector = stdmath::vector<To, 4>;
		#include "../partials/swizzle.operators.partial"
	};



	template<typename T>
	struct vector<T, 1> {
		constexpr static size_t N = 1;
		using self = vector;
		using simd = simd_or_mask<T, N>;
		using underlying_type = T;

		union {
			struct {
				alignas(stl::memory_alignment_v<simd>)
				T x;
			};
			alignas(stl::memory_alignment_v<simd>)
			std::array<T, 1> data;
		};

		constexpr vector(T x) : x(x) {}
		#include "../partials/vec1.constructors.partial.gen"

		#include "../partials/vec.operators.partial"
		#include "../partials/vec1.swizzles.address_of.partial.gen"
	};

	template<typename T>
	template<typename To>
	swizzle<T, 1>& swizzle<T, 1>::operator=(const vector<To>& vector) { *x = vector.x; return *this; }
	template<typename T>
	vector<T, 1> swizzle<T, 1>::to_vector() { return {*x}; }
	template<typename T>
	const vector<T, 1> swizzle<T, 1>::to_vector() const { return {*x}; }

	template<typename T>
	struct vector<T, 2> {
		constexpr static size_t N = 2;
		using self = vector;
		using simd = simd_or_mask<T, N>;
		using underlying_type = T;

		union {
			struct {
				alignas(stl::memory_alignment_v<simd>)
				T x;
				T y;
			};
			alignas(stl::memory_alignment_v<simd>)
			std::array<T, 2> data;
		};

		constexpr vector(T broadcast) : x(broadcast), y(broadcast) {}
		constexpr vector(T x, T y) : x(x), y(y) {}
		#include "../partials/vec2.constructors.partial.gen"

		#include "../partials/vec.operators.partial"
		#include "../partials/vec2.swizzles.address_of.partial.gen"
	};

	template<typename T>
	template<typename To>
	swizzle<T, 2>& swizzle<T, 2>::operator=(const vector<To>& vector) { *x = vector.x; *y = vector.y; return *this; }
	template<typename T>
	vector<T, 2> swizzle<T, 2>::to_vector() { return {*x, *y}; }
	template<typename T>
	const vector<T, 2> swizzle<T, 2>::to_vector() const { return {*x, *y}; }

	template<typename T>
	struct vector<T, 3> {
		constexpr static size_t N = 3;
		using self = vector;
		using simd = simd_or_mask<T, N>;
		using underlying_type = T;

		union {
			struct {
				alignas(stl::memory_alignment_v<simd>)
				T x;
				T y;
				T z;
			};
			struct {
				alignas(stl::memory_alignment_v<simd>)
				T r;
				T g;
				T b;
			};
			alignas(stl::memory_alignment_v<simd>)
			std::array<T, 3> data;
		};

		constexpr vector(T broadcast) : x(broadcast), y(broadcast), z(broadcast) {}
		constexpr vector(T x, T y, T z = {}) : x(x), y(y), z(z) {}
		#include "../partials/vec3.constructors.partial.gen"

		friend vector cross(const vector& a, const vector& b) {
			return {
				a.y * b.z - a.z * b.y,
				a.z * b.x - a.x * b.z,
				a.x * b.y - a.y * b.x
			};
		}

		#include "../partials/vec.operators.partial"
		#include "../partials/vec3.swizzles.address_of.partial.gen"
	};

	template<typename T>
	template<typename To>
	swizzle<T, 3>& swizzle<T, 3>::operator=(const vector<To>& vector) { *x = vector.x; *y = vector.y; *z = vector.z; return *this; }
	template<typename T>
	vector<T, 3> swizzle<T, 3>::to_vector() { return {*x, *y, *z}; }
	template<typename T>
	const vector<T, 3> swizzle<T, 3>::to_vector() const { return {*x, *y, *z}; }

	template<typename T>
	struct vector<T, 4> {
		constexpr static size_t N = 4;
		using self = vector;
		using simd = simd_or_mask<T, N>;
		using underlying_type = T;

		union {
			struct {
				alignas(stl::memory_alignment_v<simd>)
				T x;
				T y;
				T z;
				T w;
			};
			struct {
				alignas(stl::memory_alignment_v<simd>)
				T r;
				T g;
				T b;
				T a;
			};
			alignas(stl::memory_alignment_v<simd>)
			std::array<T, 4> data;
		};

		constexpr vector(T broadcast) : x(broadcast), y(broadcast), z(broadcast), w(broadcast) {}
		constexpr vector(T x, T y, T z = {}, T w = {}) : x(x), y(y), z(z), w(w) {}
		#include "../partials/vec4.constructors.partial.gen"

		#include "../partials/vec.operators.partial"
		#include "../partials/vec4.swizzles.address_of.partial.gen"
	};

	template<typename T>
	template<typename To>
	swizzle<T, 4>& swizzle<T, 4>::operator=(const vector<To>& vector) { *x = vector.x; *y = vector.y; *z = vector.z; *w = vector.w; return *this; }
	template<typename T>
	vector<T, 4> swizzle<T, 4>::to_vector() { return {*x, *y, *z, *w}; }
	template<typename T>
	const vector<T, 4> swizzle<T, 4>::to_vector() const { return {*x, *y, *z, *w}; }

	template<typename T, size_t N>
	constexpr vector<T, N> normalize(const vector<T, N>& v) {
		auto length = v.length();
		return v / vector<T, N>{length};
	}

	template<typename T, size_t N>
	constexpr vector<T, N> lerp(const vector<T, N>& a, const vector<T, N>& b, float t) {
		return a * t + b * (1 - t);
	}

	template<size_t N>
	inline bool all_of(const vector<bool, N>& v) {
		return all_of(v.to_simd());
	}
	template<size_t N>
	inline bool any_of(const vector<bool, N>& v) {
		return any_of(v.to_simd());
	}
	template<size_t N>
	inline bool none_of(const vector<bool, N>& v) {
		return none_of(v.to_simd());
	}
	template<size_t N>
	inline bool some_of(const vector<bool, N>& v) {
		return some_of(v.to_simd());
	}

	template<typename T, size_t N>
	constexpr bool approximately_equal(const vector<T, N>& a, const vector<T, N>& b, stl::float64_t epsilon = std::numeric_limits<stl::float32_t>::epsilon() * 100) {
		for(size_t i = 0; i < N; ++i)
			if(!approximately_equal(a.data[i], b.data[i], epsilon))
				return false;
		return true;
	}
}
