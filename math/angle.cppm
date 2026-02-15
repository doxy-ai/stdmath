export module stdmath.angle;

import std.compat;
import stdmath.types;

namespace stdmath {
	export constexpr f64 PI = std::numbers::pi_v<f64>;
	export template<typename T>
	constexpr T rad2deg = T(180)/T(PI);
	export template<typename T>
	constexpr T deg2rad = T(PI)/T(180);

	export template<typename T>
	struct basic_degree;

	export template<typename T>
	struct basic_radian {
		using underlying_type = T;
		using self = basic_radian;
		T value;

		template<std::convertible_to<T> To>
		basic_radian(To value = T(0)) : value(value) {}
		basic_radian(const basic_radian&) = default;
		basic_radian(basic_radian&&) = default;
		basic_radian() : value(0) {}
		template<typename To> basic_radian(const basic_radian<To>& other) : value(other.value) {}
		template<typename To> basic_radian(const basic_degree<To> d);

		basic_radian& operator=(const basic_radian& other) = default;
		basic_radian& operator=(basic_radian&& other) = default;

		explicit operator T() const { return value; }

		static basic_radian add(const basic_radian a, const basic_radian b) {
			return a.value + b.value;
		}

		static basic_radian subtract(const basic_radian a, const basic_radian b) {
			return a.value - b.value;
		}

		static basic_radian negate(const basic_radian v) {
			return -v.value;
		}

		static basic_radian multiply(const basic_radian a, const basic_radian b) {
			return a.value * b.value;
		}

		static basic_radian divide(const basic_radian a, const basic_radian b) {
			return a.value / b.value;
		}

		static bool equal_to(const basic_radian a, const basic_radian b) {
			return a.value == b.value;
		}

		static bool not_equal_to(const basic_radian a, const basic_radian b) {
			return a.value != b.value;
		}

		static bool less_than(const basic_radian a, const basic_radian b) {
			return a.value < b.value;
		}

		static bool less_than_or_equal_to(const basic_radian a, const basic_radian b) {
			return a.value <= b.value;
		}

		static bool greater_than(const basic_radian a, const basic_radian b) {
			return a.value > b.value;
		}

		static bool greater_than_or_equal_to(const basic_radian a, const basic_radian b) {
			return a.value >= b.value;
		}

		#include "../partials/operators.partial"
		#define STDMATH_COMPARISON_BOOLEAN_TYPE bool
		#include "../partials/operators.comparison.partial"

		T degree() const;
		T radian() const { return value; }
	};

	template<typename T>
	struct basic_degree {
		using underlying_type = T;
		using self = basic_degree;
		T value;

		template<std::convertible_to<T> To>
		basic_degree(To value = T(0)) : value(value) {}
		basic_degree(const basic_degree&) = default;
		basic_degree(basic_degree&&) = default;
		template<typename To> basic_degree(const basic_degree<To>& other) : value(other.value) {}
		template<typename To> basic_degree(const basic_radian<To> r) : value(T(r.value) * rad2deg<T>) {}

		basic_degree& operator=(const basic_degree&) = default;
		basic_degree& operator=(basic_degree&&) = default;

		explicit operator T() const { return value; }

		static basic_degree add(const basic_degree a, const basic_degree b) {
			return a.value + b.value;
		}

		static basic_degree subtract(const basic_degree a, const basic_degree b) {
			return a.value - b.value;
		}

		static basic_degree negate(const basic_degree v) {
			return -v.value;
		}

		static basic_degree multiply(const basic_degree a, const basic_degree b) {
			return a.value * b.value;
		}

		static basic_degree divide(const basic_degree a, const basic_degree b) {
			return a.value / b.value;
		}

		static bool equal_to(const basic_degree a, const basic_degree b) {
			return a.value == b.value;
		}

		static bool not_equal_to(const basic_degree a, const basic_degree b) {
			return a.value != b.value;
		}

		static bool less_than(const basic_degree a, const basic_degree b) {
			return a.value < b.value;
		}

		static bool less_than_or_equal_to(const basic_degree a, const basic_degree b) {
			return a.value <= b.value;
		}

		static bool greater_than(const basic_degree a, const basic_degree b) {
			return a.value > b.value;
		}

		static bool greater_than_or_equal_to(const basic_degree a, const basic_degree b) {
			return a.value >= b.value;
		}

		T degree() const { return value; }
		T radian() const { return basic_radian<T>(*this).value; }

		#include "../partials/operators.partial"
		#define STDMATH_COMPARISON_BOOLEAN_TYPE bool
		#include "../partials/operators.comparison.partial"
	};

	template<typename T> 
	template<typename To>
	basic_radian<T>::basic_radian(const stdmath::basic_degree<To> d) : value(T(d.value) * deg2rad<T>) {}
	template<typename T>
	T basic_radian<T>::degree() const { return basic_degree<T>(*this).value; }



	export using radian32 = basic_radian<f32>;
	export using radian64 = basic_radian<f64>;
	export using radian = basic_radian<real_t>;

	export using degree32 = basic_degree<f32>;
	export using degree64 = basic_degree<f64>;
	export using degree = basic_degree<real_t>;

	export namespace literals {
		radian64 operator""_radians(long double d) {
			return f64(d);
		};

		degree64 operator""_degrees(long double d) {
			return f64(d);
		};
	}


	export template<typename T>
	constexpr T sin(basic_radian<T> rad) { return std::sin(rad.radian()); }
	export template<typename T>
	constexpr T cos(basic_radian<T> rad) { return std::cos(rad.radian()); }
	export template<typename T>
	constexpr T tan(basic_radian<T> rad) { return std::tan(rad.radian()); }
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
			std::ptrdiff_t whole = deg.value;
			T decimal = T{deg.value} - whole;

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

	export template<typename T>
	std::ostream& operator<<(std::ostream& out, const basic_radian<T>& r) {
		return out << "radian(" << r.value << ")";
	}

	export template<typename T>
	std::ostream& operator<<(std::ostream& out, const basic_degree<T>& d) {
		return out << "degree(" << d.value << ")";
	}
}

template<typename T>
struct std::formatter<stdmath::basic_radian<T>> {
	std::formatter<T> elem_formatter;

	constexpr auto parse(std::format_parse_context& ctx) {
		return elem_formatter.parse(ctx);
	}

	template<typename FormatContext>
	auto format(const stdmath::basic_radian<T>& r, FormatContext& ctx) const {
		auto out = std::format_to(ctx.out(), "radian(");
		out = elem_formatter.format(r.value, ctx);
		return std::format_to(out, ")");
	}
};

template<typename T>
struct std::formatter<stdmath::basic_degree<T>> {
	std::formatter<T> elem_formatter;

	constexpr auto parse(std::format_parse_context& ctx) {
		return elem_formatter.parse(ctx);
	}

	template<typename FormatContext>
	auto format(const stdmath::basic_degree<T>& d, FormatContext& ctx) const {
		auto out = std::format_to(ctx.out(), "degree(");
		out = elem_formatter.format(d.value, ctx);
		return std::format_to(out, ")");
	}
};