#pragma once

#include "angles.hpp"
#include "vector.hpp"

namespace stdmath {

	template<std::floating_point F = float_t>
	struct basic_quaternion: protected vector<F, 4> {
		using underlying_type = F;
		using super = vector<F, 4>;
		using super::super;
		static const basic_quaternion& from_vector(const super& v) { return (basic_quaternion&)v; }
		super& to_vector() { return *this; }
		const super& to_vector() const { return *this; }

		static basic_quaternion identity() { return from_vector({0, 0, 0, 1}); }

		inline friend basic_quaternion add(const basic_quaternion& a, const basic_quaternion& b) { return from_vector(add(a.to_vector(), b.to_vector())); }
		inline friend basic_quaternion operator+(const basic_quaternion& a, const basic_quaternion& b) { return add(a, b); }
		inline friend basic_quaternion subtract(const basic_quaternion& a, const basic_quaternion& b) { return from_vector(subtract(a.to_vector(), b.to_vector())); }
		inline friend basic_quaternion operator-(const basic_quaternion& a, const basic_quaternion& b) { return subtract(a, b); }

		inline friend vector<bool, 4> operator==(const basic_quaternion& a, const basic_quaternion& b) { return a.to_vector() == b.to_vector(); }
		inline friend vector<bool, 4> operator!=(const basic_quaternion& a, const basic_quaternion& b) { return a.to_vector() != b.to_vector(); }
		inline friend vector<bool, 4> operator<=(const basic_quaternion& a, const basic_quaternion& b) { return a.to_vector() <= b.to_vector(); }
		inline friend vector<bool, 4> operator>=(const basic_quaternion& a, const basic_quaternion& b) { return a.to_vector() >= b.to_vector(); }
		inline friend vector<bool, 4> operator<(const basic_quaternion& a, const basic_quaternion& b) { return a.to_vector() < b.to_vector(); }
		inline friend vector<bool, 4> operator>(const basic_quaternion& a, const basic_quaternion& b) { return a.to_vector() > b.to_vector(); }
		using super::length_squared;
		using super::length;

		template<typename F2>
		friend basic_quaternion<F> normalize(const basic_quaternion<F2>& v);
		template<typename F2>
		constexpr friend bool approximately_equal(const basic_quaternion<F2>& a, const basic_quaternion<F2>& b);

		// Make sure that all of the elementwise accessor are available...
		using super::x;
		using super::y;
		using super::z;
		using super::w;
		using super::data;

		template<std::convertible_to<F> Flike>
		inline friend basic_quaternion operator*(const basic_quaternion<F>& q, Flike scalar) {
			return from_vector(q.to_vector() * scalar);
		}
		template<std::convertible_to<F> Flike>
		inline friend basic_quaternion operator/(const basic_quaternion<F>& q, Flike scalar) {
			return from_vector(q.to_vector() / scalar);
		}

		inline friend basic_quaternion multiply(const basic_quaternion<F>& a, const basic_quaternion<F>& b) {
			// sa = a.w, sb = b.w
			// a = a.xyz, b = b.xyz

			// s = sa*sb - dot(a, b)
			F w = a.w * b.w - dot(a.xyz().to_vector(), b.xyz().to_vector());
			// xyz (v) = sa * b + sb * a + cross(a, b)
			vector<F, 3> xyz = b.xyz().to_vector() * a.w + a.xyz().to_vector() * b.w + cross(a.xyz().to_vector(), b.xyz().to_vector());
			return {xyz.x, xyz.y, xyz.z, w};
		}
		inline friend basic_quaternion operator*(const basic_quaternion<F>& a, const basic_quaternion<F>& b) {
			return multiply(a, b);
		}

		inline basic_quaternion conjugate() const {
			auto xyz = this->xyz().to_vector().negate();
			return from_vector({xyz.x, xyz.y, xyz.z, this->w});
		}

		inline basic_quaternion inverse() const {
			return conjugate() / length_squared();
		}

		template<std::convertible_to<F> Fo>
		inline friend vector<Fo, 3> rotate_vector(const basic_quaternion<F>& q, const vector<Fo, 3>& v) {
			auto vQuat = basic_quaternion<F>(v, 0); // TODO: Is there a more efficient way to write this?
			auto outQuat = (q * vQuat) * q.conjugate();
			return outQuat.xyz().to_vector();
		}
		template<std::convertible_to<F> Fo>
		inline friend vector<Fo, 3> operator*(const basic_quaternion<F> &q, const vector<Fo, 3>& v) { return rotate_vector(q, v); }

		// TODO: Does this produce a value in radians?
		inline friend radian angle_between(const basic_quaternion<F>& a, const basic_quaternion<F>& b) {
			// dot(q1, q2)/(q1.norm * q2.norm)
			return dot(a.to_vector(), b.to_vector()) / a.length() / b.length();
		}

		constexpr static basic_quaternion from_axis_angle(const vector<F, 3> axis, radian angle) {
			auto sin = stdmath::sin(angle / radian{2});
			return {static_cast<F>(axis.x * sin), static_cast<F>(axis.y * sin), static_cast<F>(axis.z * sin), static_cast<F>(stdmath::cos(angle / radian{2}))};
		}

		constexpr void to_axis_angle(vector<F, 3>& /*out*/ axis, radian& /*out*/ angle) {
			auto aOver2 = stdmath::acos(w);
			angle = aOver2 * radian{2};
			axis = this->xyz().to_vector() / stdmath::sin(aOver2);
		}
		constexpr std::pair<vector<F, 3>, radian> to_axis_angle() {
			std::pair<vector<F, 3>, radian> out;
			to_axis_angle(out.first, out.second);
			return out;
		}

		constexpr static basic_quaternion from_euler_angles(const vector<radian, 3> angles) {
			// TODO: How optimized is this?
			return from_axis_angle({1, 0, 0}, angles.x) * from_axis_angle({0, 1, 0}, angles.y) * from_axis_angle({0, 0, 1}, angles.z);
		}

		constexpr vector<radian, 3> to_euler_angles() {
			radian outX = stdmath::atan2(2*(w*x + y*z), 1-2*(x*x + y*y));
			radian outY = stdmath::asin(2*(w*y - x*z));
			radian outZ = stdmath::atan2(2*(w*z + x*y), 1-2*(y*y + z*z));
			return {outX, outY, outZ};
		}
	};

	template<typename F>
	basic_quaternion<F> normalize(const basic_quaternion<F>& q) {
		return basic_quaternion<F>::from_vector(normalize(q.to_vector()));
	}

	template<typename F>
	constexpr bool approximately_equal(const basic_quaternion<F>& a, const basic_quaternion<F>& b, stl::float64_t epsilon = std::numeric_limits<stl::float32_t>::epsilon() * 100) {
		return approximately_equal(a.to_vector(), b.to_vector(), epsilon);
	}

	using quaternion32 = basic_quaternion<stl::float32_t>;
	using quaternion64 = basic_quaternion<stl::float64_t>;
	using quaternion = basic_quaternion<float_t>;
}