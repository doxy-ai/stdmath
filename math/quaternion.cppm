export module stdmath.quaternion;

import std.compat;
import stdmath.vector;
import stdmath.angle;
import stdmath.types;

namespace stdmath {

	export template<std::floating_point F = real_t>
	struct basic_quaternion: protected vector<F, 4> {
		using underlying_type = F;
		using self = basic_quaternion;
		using super = vector<F, 4>;
		using super::super;
		using super::operator[];

		constexpr basic_quaternion(F broadcast = {}) : super(broadcast) {}
		constexpr basic_quaternion(F x, F y, F z = {}, F w = {}) : super(x, y, z, w) {}
		explicit constexpr basic_quaternion(const super& o) : super(o) {}
		constexpr basic_quaternion(const basic_quaternion&) = default;
		constexpr basic_quaternion(basic_quaternion&&) = default;
		constexpr basic_quaternion& operator=(const basic_quaternion&) = default;
		constexpr basic_quaternion& operator=(basic_quaternion&&) = default;

		template<typename To>
		basic_quaternion(const basic_quaternion<To>& o) {
			auto range = std::views::iota(size_t{0}, size_t{4});
#ifdef __clang__
			std::for_each(range.begin(), range.end(), [&](size_t i) {
#else
			std::for_each(std::execution::par_unseq, range.begin(), range.end(), [&](size_t i) {
#endif
				data[i] = F(o[i]);
			});
		}

		static const basic_quaternion& from_vector(const super& v) { return (basic_quaternion&)v; }
		super& to_vector() { return *this; }
		const super& to_vector() const { return *this; }

		static basic_quaternion add(const basic_quaternion& a, const basic_quaternion& b) { return from_vector(super::add(a.to_vector(), b.to_vector())); }
		static basic_quaternion subtract(const basic_quaternion& a, const basic_quaternion& b) { return from_vector(super::subtract(a.to_vector(), b.to_vector())); }

		static vector<bool, 4> equal_to(const basic_quaternion& a, const basic_quaternion& b) { return a.to_vector() == b.to_vector(); }
		static vector<bool, 4> not_equal_to(const basic_quaternion& a, const basic_quaternion& b) { return a.to_vector() != b.to_vector(); }
		static vector<bool, 4> less_than_or_equal_to(const basic_quaternion& a, const basic_quaternion& b) { return a.to_vector() <= b.to_vector(); }
		static vector<bool, 4> greater_than_or_equal_to(const basic_quaternion& a, const basic_quaternion& b) { return a.to_vector() >= b.to_vector(); }
		static vector<bool, 4> less_than(const basic_quaternion& a, const basic_quaternion& b) { return a.to_vector() < b.to_vector(); }
		static vector<bool, 4> greater_than(const basic_quaternion& a, const basic_quaternion& b) { return a.to_vector() > b.to_vector(); }
		using super::length_squared;
		using super::length;

		using super::x;
		using super::y;
		using super::z;
		using super::w;
		using super::data;

		static basic_quaternion identity() {
			return basic_quaternion(0.f, 0.f, 0.f, 1.f);
		}

		static basic_quaternion from_axis_angle(const vector<F, 3>& axis, basic_degree<F> angle){
			basic_radian<F> half = angle / 2;
			auto s = stdmath::sin(half);

			return /* normalize */(basic_quaternion{
				axis.x * s,
				axis.y * s,
				axis.z * s,
				stdmath::cos(half)
			});
		}

		constexpr void to_axis_angle(vector<F, 3>& /*out*/ axis, basic_radian<F>& /*out*/ angle) {
			basic_quaternion q = *this;

			// Ensure unit quaternion
			if (q.w > 1.f)
				q = normalize(q);

			angle = 2 * stdmath::acos(q.w);
			auto s = std::sqrt(1 - q.w * q.w);

			// If s is close to zero, direction doesn't matter
			if (s < 0.0001f)
				axis = vector<F, 3>{1, 0, 0};
			else axis = vector<F, 3>{q.x / s, q.y / s, q.z / s};
		}
		constexpr std::pair<vector<F, 3>, basic_radian<F>> to_axis_angle() {
			std::pair<vector<F, 3>, basic_radian<F>> out;
			to_axis_angle(out.first, out.second);
			return out;
		}

		basic_quaternion conjugate() const {
			return {-x, -y, -z, w};
		}

		basic_quaternion inverse() const {
			float lenSq = x*x + y*y + z*z + w*w;
			if (lenSq == 0.f)
				return basic_quaternion();

			basic_quaternion c = conjugate();
			float inv = 1.0f / lenSq;
			return {c.x * inv, c.y * inv, c.z * inv, c.w * inv};
		}

		template<std::convertible_to<F> Flike>
		static basic_quaternion multiply(const basic_quaternion& q, Flike scalar) {
			return from_vector(q.to_vector() * scalar);
		}
		template<std::convertible_to<F> Flike>
		static basic_quaternion multiply(Flike scalar, const basic_quaternion& q) {
			return from_vector(q.to_vector() * scalar);
		}
#ifndef _MSC_VER // TODO: Divide breaks MSVC?
		template<std::convertible_to<F> Flike>
		static basic_quaternion divide(const basic_quaternion& q, Flike scalar) {
			return from_vector(q.to_vector() / scalar);
		}
#endif

		static basic_quaternion multiply(const basic_quaternion& a, const basic_quaternion& b) {
			return {
				a.w*b.x + a.x*b.w + a.y*b.z - a.z*b.y,
				a.w*b.y - a.x*b.z + a.y*b.w + a.z*b.x,
				a.w*b.z + a.x*b.y - a.y*b.x + a.z*b.w,
				a.w*b.w - a.x*b.x - a.y*b.y - a.z*b.z
			};
		}

		// --- Vector rotation ---

		friend vector<F, 3> rotate(const basic_quaternion& q, const vector<F, 3>& v) {
			basic_quaternion qv(v, 0.f);
			basic_quaternion result = q * qv * q.inverse();
			return vector<F, 3>(result.x, result.y, result.z);
		}
		friend vector<F, 3> operator*(const basic_quaternion& q, const vector<F, 3>& v) {
			return rotate(q, v);
		}

		#include "../partials/operators.partial"
		#define STDMATH_COMPARISON_BOOLEAN_TYPE vector<bool, 4>
		#include "../partials/operators.comparison.partial"

		// TODO: Does this produce a value in radians?
		friend basic_radian<F> angle_between(const basic_quaternion& a, const basic_quaternion& b) {
			// dot(a, b)/(a.norm * b.norm)
			return dot(a.to_vector(), b.to_vector()) / a.length() / b.length();
		}

		constexpr static basic_quaternion from_euler_angles(const vector<degree, 3> angles) {
			// TODO: How optimized is this?
			return from_axis_angle({1, 0, 0}, angles.x) * from_axis_angle({0, 1, 0}, angles.y) * from_axis_angle({0, 0, 1}, angles.z);
		}

		constexpr vector<degree, 3> to_euler_angles() {
			radian outX = stdmath::atan2(2*(w*x + y*z), 1-2*(x*x + y*y));
			radian outY = stdmath::asin(2*(w*y - x*z));
			radian outZ = stdmath::atan2(2*(w*z + x*y), 1-2*(y*y + z*z));
			return {outX, outY, outZ};
		}
	};

	export template<typename F>
	basic_quaternion<F> normalize(const basic_quaternion<F>& q) {
		return basic_quaternion<F>::from_vector(stdmath::normalize(q.to_vector()));
	}

	export template<typename F>
	constexpr bool approximately_equal(const basic_quaternion<F>& a, const basic_quaternion<F>& b, f64 epsilon = std::numeric_limits<f32>::epsilon() * 100) {
		return approximately_equal(a.to_vector(), b.to_vector(), epsilon);
	}

	export using quaternion32 = basic_quaternion<f32>;
	export using quaternion64 = basic_quaternion<f64>;
	export using quaternion = basic_quaternion<real_t>;
}