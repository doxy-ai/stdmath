module;

#include "../util/operators.hpp"

export module stdmath.vector;

import std.compat;
import stdmath.types;
import stdmath.simd;

namespace stdmath {

	export template<typename T, size_t N>
	struct vector : public operators_crtp<vector<T, N>> {
		using self = vector;
		using simd = stl::simd_or_mask<T, N>;
		using underlying_type = T;

		std::array<T, N> data;

		constexpr vector(T broadcast) { data.fill(broadcast); }
		constexpr vector(std::initializer_list<T> data) : data(data) {}
		#include "../partials/vec1.constructors.partial.gen"

		#include "../partials/vec.operators.partial"
	};

	export template<typename T, size_t N>
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
		template<typename To>
		swizzle& operator=(const vector<To>& vector);
		operator vector<T>() { return to_vector(); }
		vector<T> to_vector();
		const vector<T> to_vector() const;
	};

	template<typename T>
	struct swizzle<T, 2> {
		using underlying_type = T;
		T *x, *y;

		#include "../partials/vec2.swizzles.partial.gen"

		template<typename To>
		using vector = stdmath::vector<To, 2>;
		template<typename To>
		swizzle& operator=(const vector<To>& vector);
		operator vector<T>() { return to_vector(); }
		vector<T> to_vector();
		const vector<T> to_vector() const;
	};

	template<typename T>
	struct swizzle<T, 3> {
		using underlying_type = T;
		T *x, *y, *z;

		#include "../partials/vec3.swizzles.partial.gen"

		template<typename To>
		using vector = stdmath::vector<To, 3>;
		template<typename To>
		swizzle& operator=(const vector<To>& vector);
		operator vector<T>() { return to_vector(); }
		vector<T> to_vector();
		const vector<T> to_vector() const;
	};

	template<typename T>
	struct swizzle<T, 4> {
		using underlying_type = T;
		T *x, *y, *z, *w;

		#include "../partials/vec4.swizzles.partial.gen"

		template<typename To>
		using vector = stdmath::vector<To, 4>;
		template<typename To>
		swizzle& operator=(const vector<To>& vector);
		operator vector<T>() { return to_vector(); }
		vector<T> to_vector();
		const vector<T> to_vector() const;
	};



	template<typename T>
	struct vector<T, 1> : public operators_crtp<vector<T, 1>>, public comparison_operators_crtp<vector<T, 1>, vector<bool, 1>> {
		constexpr static size_t N = 1;
		using self = vector;
		using simd = stl::simd_or_mask<T, N>;
		using underlying_type = T;

		union {
			struct {
				T x;
			};
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
	struct vector<T, 2> : public operators_crtp<vector<T, 2>>, public comparison_operators_crtp<vector<T, 2>, vector<bool, 2>> {
		constexpr static size_t N = 2;
		using self = vector;
		using simd = stl::simd_or_mask<T, N>;
		using underlying_type = T;

		union {
			struct {
				T x;
				T y;
			};
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
	struct vector<T, 3> : public operators_crtp<vector<T, 3>>,public comparison_operators_crtp<vector<T, 3>, vector<bool, 3>> {
		constexpr static size_t N = 3;
		using self = vector;
		using simd = stl::simd_or_mask<T, N>;
		using underlying_type = T;

		union {
			struct {
				alignas(std::array<T, 4>)
				T x;
				T y;
				T z;
			};
			struct {
				alignas(std::array<T, 4>)
				T r;
				T g;
				T b;
			};
			alignas(std::array<T, 4>)
			std::array<T, 3> data;
		};

		constexpr vector(T broadcast) : x(broadcast), y(broadcast), z(broadcast) {}
		constexpr vector(T x, T y, T z = {}) : x(x), y(y), z(z) {}
		#include "../partials/vec3.constructors.partial.gen"

		inline friend vector cross(const vector& a, const vector& b) {
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
	struct vector<T, 4> : public operators_crtp<vector<T, 4>>, public comparison_operators_crtp<vector<T, 4>, vector<bool, 4>> {
		constexpr static size_t N = 4;
		using self = vector;
		using simd = stl::simd_or_mask<T, N>;
		using underlying_type = T;

		union {
			struct {
				T x;
				T y;
				T z;
				T w;
			};
			struct {
				T r;
				T g;
				T b;
				T a;
			};
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

	export template<typename T, size_t N>
	constexpr vector<T, N> normalize(const vector<T, N>& v) {
		auto length = v.length();
		return v / vector<T, N>{length};
	}

	export template<typename T, size_t N>
	constexpr vector<T, N> lerp(const vector<T, N>& a, const vector<T, N>& b, float t) {
		return a * t + b * (1 - t);
	}

	export template<typename T, size_t N>
	constexpr vector<T, N> clamp(const vector<T, N>& v, const vector<T, N>& min, const vector<T, N>& max) {
		return v.elementwise_transform([&](const T& element, size_t i) {
			return std::clamp(element, min[i], max[i]);
		});
	}

	export template<typename T, size_t N>
	constexpr vector<T, N> reflect(const vector<T, N>& v, const vector<T, N>& normal) {
		return v - 2 * dot(v, normal) * normal;
	}

	export template<size_t N>
	bool all_of(const vector<bool, N>& v) {
		return all_of(v.to_simd());
	}
	export template<size_t N>
	bool any_of(const vector<bool, N>& v) {
		return any_of(v.to_simd());
	}
	export template<size_t N>
	bool none_of(const vector<bool, N>& v) {
		return none_of(v.to_simd());
	}
	export template<size_t N>
	bool some_of(const vector<bool, N>& v) {
		return some_of(v.to_simd());
	}

	export template<typename T, size_t N>
	constexpr bool approximately_equal(const vector<T, N>& a, const vector<T, N>& b, f64 epsilon = std::numeric_limits<f32>::epsilon() * 100) {
		for(size_t i = 0; i < N; ++i)
			if(!approximately_equal(a.data[i], b.data[i], epsilon))
				return false;
		return true;
	}
}
