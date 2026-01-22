module;

#include "../util/operators.hpp"

export module stdmath.angle;

import std.compat;
import stdmath.types;

namespace stdmath {
	export constexpr f64 PI = std::numbers::pi_v<f64>;
	export template<typename T>
	constexpr T rad2deg = T{180}/T{PI};
	export template<typename T>
	constexpr T deg2rad = T{PI}/T{180};

	export template<typename T>
	struct basic_degree;

	export template<typename T>
	struct basic_radian : public operators_crtp<basic_radian<T>>, public comparison_operators_crtp<basic_radian<T>, bool> {
		using underlying_type = T;
		T value;

		template<typename To> basic_radian(const To radian) : value(radian) {}
		basic_radian(const basic_radian&) = default;
		basic_radian(basic_radian&&) = default;
		basic_radian() : basic_radian(0) {}
		template<typename To> basic_radian(const basic_radian<To>& other) : basic_radian(other.value) {}
		basic_radian(const basic_degree<T> d);

		basic_radian& operator=(const basic_radian& other) = default;
		basic_radian& operator=(basic_radian&& other) = default;

		operator T() const { return value; }
		
		friend basic_radian add(const basic_radian a, const basic_radian b) {
			return a.value + b.value;
		}

		friend basic_radian subtract(const basic_radian a, const basic_radian b) {
			return a.value - b.value;
		}

		basic_radian negate() const {
			return -value;
		}

		friend basic_radian multiply(const basic_radian a, const basic_radian b) {
			return a.value * b.value;
		}

		friend basic_radian divide(const basic_radian a, const basic_radian b) {
			return a.value / b.value;
		}

		friend bool equal_to(const basic_radian a, const basic_radian b) {
			return a.value == b.value;
		}

		friend bool not_equal_to(const basic_radian a, const basic_radian b) {
			return a.value != b.value;
		}

		friend bool less_than(const basic_radian a, const basic_radian b) {
			return a.value < b.value;
		}

		friend bool less_than_or_equal_to(const basic_radian a, const basic_radian b) {
			return a.value <= b.value;
		}

		friend bool greater_than(const basic_radian a, const basic_radian b) {
			return a.value > b.value;
		}

		friend bool greater_than_or_equal_to(const basic_radian a, const basic_radian b) {
			return a.value >= b.value;
		}

		T degree() const;
		T radian() const { return value; }
	};

	template<typename T>
	struct basic_degree : public operators_crtp<basic_degree<T>>, public comparison_operators_crtp<basic_degree<T>, bool> {
		using underlying_type = T;
		T value;

		template<typename To> basic_degree(To basic_degree) : value(basic_degree) {}
		basic_degree(const basic_degree&) = default;
		basic_degree(basic_degree&&) = default;
		basic_degree() : basic_degree(0) {}
		template<typename To> basic_degree(const basic_degree<To>& other) : basic_degree(other.value) {}
		basic_degree(const basic_radian<T> r) : basic_degree(T(r) * rad2deg<T>) {}

		basic_degree& operator=(const basic_degree&) = default;
		basic_degree& operator=(basic_degree&&) = default;

		operator T() const { return value; }

		friend basic_degree add(const basic_degree a, const basic_degree b) {
			return a.value + b.value;
		}

		friend basic_degree subtract(const basic_degree a, const basic_degree b) {
			return a.value - b.value;
		}

		basic_degree negate() const {
			return -value;
		}

		friend basic_degree multiply(const basic_degree a, const basic_degree b) {
			return a.value * b.value;
		}

		friend basic_degree divide(const basic_degree a, const basic_degree b) {
			return a.value / b.value;
		}

		friend bool equal_to(const basic_degree a, const basic_degree b) {
			return a.value == b.value;
		}

		friend bool not_equal_to(const basic_degree a, const basic_degree b) {
			return a.value != b.value;
		}

		friend bool less_than(const basic_degree a, const basic_degree b) {
			return a.value < b.value;
		}

		friend bool less_than_or_equal_to(const basic_degree a, const basic_degree b) {
			return a.value <= b.value;
		}

		friend bool greater_than(const basic_degree a, const basic_degree b) {
			return a.value > b.value;
		}

		friend bool greater_than_or_equal_to(const basic_degree a, const basic_degree b) {
			return a.value >= b.value;
		}

		T degree() const { return value; }
		T radian() const { return basic_radian<T>(*this); }
	};

	template<typename T>
	basic_radian<T>::basic_radian(const stdmath::basic_degree<T> d) : basic_radian(T(d) * deg2rad<T>) {}
	template<typename T>
	T basic_radian<T>::degree() const { return basic_degree<T>(*this); }



	export using radian32 = basic_radian<f32>;
	export using radian64 = basic_radian<f64>;
	export using radian = basic_radian<real_t>;

	export using degree32 = basic_degree<f32>;
	export using degree64 = basic_degree<f64>;
	export using degree = basic_degree<real_t>;



	export template<typename T>
	constexpr T sin(basic_radian<T> rad) { return std::sin(rad); }
	export template<typename T>
	constexpr T cos(basic_radian<T> rad) { return std::cos(rad); }
	export template<typename T>
	constexpr T tan(basic_radian<T> rad) { return std::tan(rad); }
	export template<typename T>
	constexpr basic_radian<T> asin(T v) { return std::asin(v); }
	export template<typename T>
	constexpr basic_radian<T> acos(T v) { return std::acos(v); }
	export template<typename T>
	constexpr basic_radian<T> atan(T v) { return std::atan(v); }
	export template<typename T>
	constexpr basic_radian<T> atan2(T y, T x) { return std::atan2(y, x); }

	export template<typename T>
	constexpr T sinh(basic_radian<T> rad) { return std::sinh(rad.radian()); }
	export template<typename T>
	constexpr T cosh(basic_radian<T> rad) { return std::cosh(rad.radian()); }
	export template<typename T>
	constexpr T tanh(basic_radian<T> rad) { return std::tanh(rad.radian()); }
	export template<typename T>
	constexpr basic_radian<T> asinh(T v) { return std::asinh(v); }
	export template<typename T>
	constexpr basic_radian<T> acosh(T v) { return std::acosh(v); }
	export template<typename T>
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
	export template<typename T>
	constexpr T angle_wrap(const T angle) {
		return angle_wrapper<std::remove_cvref_t<T>>{}(angle);
	}
}