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
				data[i] = o[i];
			});
		}

		static const basic_quaternion& from_vector(const super& v) { return (basic_quaternion&)v; }
		super& to_vector() { return *this; }
		const super& to_vector() const { return *this; }

		static basic_quaternion identity() { return from_vector({0, 0, 0, 1}); }

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

		// template<typename F2>
		// friend basic_quaternion normalize(const basic_quaternion<F2>& v);
		// template<typename F2>
		// constexpr friend bool approximately_equal(const basic_quaternion<F2>& a, const basic_quaternion<F2>& b);

		// Make sure that all of the elementwise accessor are available...
		using super::x;
		using super::y;
		using super::z;
		using super::w;
		using super::data;

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
			// sa = a.w, sb = b.w
			// a = a.xyz, b = b.xyz

			// s = sa*sb - dot(a, b)
			F w = a.w * b.w - dot(a.xyz().to_vector(), b.xyz().to_vector());
			// xyz (v) = sa * b + sb * a + cross(a, b)
			vector<F, 3> xyz = b.xyz().to_vector() * a.w + a.xyz().to_vector() * b.w + cross(a.xyz().to_vector(), b.xyz().to_vector());
			return {xyz.x, xyz.y, xyz.z, w};
		}

		basic_quaternion conjugate() const {
			auto xyz = vector<F, 3>::negate(this->xyz());
			return from_vector({xyz.x, xyz.y, xyz.z, this->w});
		}

		basic_quaternion inverse() const {
			return conjugate() / length_squared();
		}

		template<std::floating_point Fo>
		friend vector<Fo, 3> rotate_vector(const basic_quaternion& q, const vector<Fo, 3>& v) {
			auto vQuat = basic_quaternion(v, 0); // TODO: Is there a more efficient way to write this?
			auto outQuat = (q * vQuat) * q.conjugate();
			return outQuat.xyz();
		}

		// template<std::floating_point Fo>
		// static vector<Fo, 3> multiply(const basic_quaternion &q, const vector<Fo, 3>& v) { return rotate_vector(q, v); }
		template<std::floating_point Fo>
		friend vector<Fo, 3> operator*(const basic_quaternion &q, const vector<Fo, 3>& v) { return rotate_vector(q, v); }

		#include "../partials/operators.partial"
		#define STDMATH_COMPARISON_BOOLEAN_TYPE vector<bool, 4>
		#include "../partials/operators.comparison.partial"

		// TODO: Does this produce a value in radians?
		friend radian angle_between(const basic_quaternion& a, const basic_quaternion& b) {
			// dot(q1, q2)/(q1.norm * q2.norm)
			return dot(a.to_vector(), b.to_vector()) / a.length() / b.length();
		}

		constexpr static basic_quaternion from_axis_angle(const vector<F, 3> axis, radian angle) {
			auto sin = stdmath::sin<F>(angle / radian{2});
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

		constexpr static basic_quaternion from_euler_angles(const vector<degree, 3> angles) {
			// TODO: How optimized is this?
			auto q = from_axis_angle({1, 0, 0}, angles.x) * from_axis_angle({0, 1, 0}, angles.y) * from_axis_angle({0, 0, 1}, angles.z);
			return from_vector(stdmath::normalize(q.to_vector()));
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