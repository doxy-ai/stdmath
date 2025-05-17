#pragma once

#include <cmath>
#include <cstddef>
#include <stdfloat>
#include <numbers>
#include <type_traits>

namespace stdmath {
	constexpr static std::float64_t PI = std::numbers::pi_v<std::float64_t>;
	template<typename T>
	constexpr static T rad2deg = 180/PI;
	template<typename T>
	constexpr static T deg2rad = PI/180;

	template<typename T>
	struct basic_degree;

	template<typename T>
	struct basic_radian {
		T value;

		constexpr basic_radian(const T radian) : value(radian) {}
		constexpr basic_radian(const basic_radian& other) : basic_radian(other.value) {}
		constexpr basic_radian() : basic_radian(0) {}
		constexpr basic_radian(const basic_degree<T> d);

		constexpr basic_radian& operator=(const basic_radian& other) = default;

		constexpr operator T() const { return value; }

		constexpr basic_radian operator+(const basic_radian other) const { return value + other.value; }
		constexpr basic_radian operator-(const basic_radian other) const { return value - other.value; }
		constexpr basic_radian operator*(const basic_radian other) const { return value * other.value; }
		constexpr basic_radian operator/(const basic_radian other) const { return value / other.value; }

		constexpr basic_radian& operator+=(const basic_radian other) { *this = *this + other; return *this; }
		constexpr basic_radian& operator-=(const basic_radian other) { *this = *this - other; return *this; }
		constexpr basic_radian& operator*=(const basic_radian other) { *this = *this * other; return *this; }
		constexpr basic_radian& operator/=(const basic_radian other) { *this = *this / other; return *this; }

		constexpr T degree() const;
		constexpr T radian() const { return value; }
	};

	template<typename T>
	struct basic_degree {
		T value;

		constexpr basic_degree(T basic_degree) : value(basic_degree) {}
		constexpr basic_degree(const basic_degree& other) : basic_degree(other.value) {}
		constexpr basic_degree() : basic_degree(0) {}
		constexpr basic_degree(const basic_radian<T> r) : basic_degree(T(r) * rad2deg<T>) {}

		constexpr basic_degree& operator=(const basic_degree& other) = default;

		constexpr operator T() const { return value; }

		constexpr basic_degree operator+(const basic_degree other) const { return value + other.value; }
		constexpr basic_degree operator-(const basic_degree other) const { return value - other.value; }
		constexpr basic_degree operator*(const basic_degree other) const { return value * other.value; }
		constexpr basic_degree operator/(const basic_degree other) const { return value / other.value; }

		constexpr basic_degree& operator+=(const basic_degree other) { *this = *this + other; return *this; }
		constexpr basic_degree& operator-=(const basic_degree other) { *this = *this - other; return *this; }
		constexpr basic_degree& operator*=(const basic_degree other) { *this = *this * other; return *this; }
		constexpr basic_degree& operator/=(const basic_degree other) { *this = *this / other; return *this; }

		constexpr T degree() const { return value; }
		constexpr T radian() const { return basic_radian<T>(*this); }
	};

	template<typename T>
	constexpr basic_radian<T>::basic_radian(const stdmath::basic_degree<T> d) : basic_radian(T(d) * deg2rad<T>) {}
	template<typename T>
	constexpr T basic_radian<T>::degree() const { return basic_degree<T>(*this); }



	using radian32 = basic_radian<float32_t>;
	using radian64 = basic_radian<float64_t>;
	using radian = radian64;

	using degree32 = basic_degree<float32_t>;
	using degree64 = basic_degree<float64_t>;
	using degree = degree64;



	template<typename T>
	constexpr T sin(basic_radian<T> rad) { return std::sin(rad); }
	template<typename T>
	constexpr T cos(basic_radian<T> rad) { return std::cos(rad); }
	template<typename T>
	constexpr T tan(basic_radian<T> rad) { return std::tan(rad); }
	template<typename T>
	constexpr basic_radian<T> asin(T v) { return std::asin(v); }
	template<typename T>
	constexpr basic_radian<T> acos(T v) { return std::acos(v); }
	template<typename T>
	constexpr basic_radian<T> atan(T v) { return std::atan(v); }
	template<typename T>
	constexpr basic_radian<T> atan2(T y, T x) { return std::atan2(y, x); }

	template<typename T>
	constexpr T sinh(basic_radian<T> rad) { return std::sinh(rad.radian()); }
	template<typename T>
	constexpr T cosh(basic_radian<T> rad) { return std::cosh(rad.radian()); }
	template<typename T>
	constexpr T tanh(basic_radian<T> rad) { return std::tanh(rad.radian()); }
	template<typename T>
	constexpr basic_radian<T> asinh(T v) { return std::asinh(v); }
	template<typename T>
	constexpr basic_radian<T> acosh(T v) { return std::acosh(v); }
	template<typename T>
	constexpr basic_radian<T> atanh(T v) { return std::atanh(v); }



	template<typename T>
	struct angle_wrapper {
		static_assert(false, "Angle normalization is not supported for this type!");
	};
	template<typename T>
	struct angle_wrapper<basic_degree<T>> {
		basic_degree<T> operator()(const basic_degree<T> deg) {
			std::ptrdiff_t whole = deg;
			T decimal = T{deg} - whole;

			whole %= 360;
			auto res = whole + decimal;
			return res + (res < 360 ? 360 : 0);
		}
	};
	template<typename T>
	struct angle_wrapper<basic_radian<T>> {
		basic_radian<T> operator()(const basic_radian<T> rad) {
			return angle_wrapper<basic_degree<T>>{}(rad);
		}
	};
	
	/**
	 * Maps an angle to its corresponding angle in the range [0, 360).
	 * 
	 * @param deg the angle to map.
	 * @return constexpr basic_degree<T> corresponding angle between [0, 360).
	 */
	template<typename T>
	constexpr T angle_wrap(const T angle) {
		return angle_wrapper<std::remove_cvref_t<T>>{}(angle);
	}	
}