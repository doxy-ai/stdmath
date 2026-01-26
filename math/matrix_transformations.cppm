export module stdmath.transformations;

import std.compat;
import stdmath.vector;
import stdmath.matrix;
import stdmath.angle;
import stdmath.quaternion;

// TODO: This file is currently untested!
// NOTE: Slang uses a ROW MAJOR matrices in a LEFT HANDED coordinate system!

namespace stdmath {
	export template<typename T = float_t, typename Tq = float_t>
	constexpr matrix<T, 3, 3> rotation_matrix(const basic_quaternion<Tq>& q, bool assume_quaternion_is_unit = true) {
		if(assume_quaternion_is_unit)
			return {{
				1 - 2*(q.y*q.y + q.z*q.z), 2*(q.x*q.y - q.w*q.z), 2*(q.x*q.z + q.w*q.y),
				2*(q.x*q.y + q.w*q.z), 1 - 2*(q.x*q.x + q.z*q.z), 2*(q.y*q.z - q.w*q.x),
				2*(q.x*q.z - q.w*q.y), 2*(q.w*q.x + q.y*q.z), 1 - 2*(q.x*q.x + q.y*q.y)
			}};
		else return {{
			q.w*q.w + q.x*q.x - q.y*q.y - q.z*q.z, 2*(q.x*q.y - q.w*q.z), 2*(q.x*q.z + q.w*q.y),
			2*(q.x*q.y + q.w*q.z), q.w*q.w - q.x*q.x + q.y*q.y - q.z*q.z, 2*(q.y*q.z - q.w*q.x),
			2*(q.x*q.z - q.w*q.y), 2*(q.w*q.x + q.y*q.z), q.w*q.w - q.x*q.x - q.y*q.y + q.z*q.z
		}};
	}

	// Long term todo: Rotation matrix to quaternion conversion

	export template<typename T = float_t>
	constexpr matrix<T, 4, 4> translation_matrix(const vector<T, 3>& position) {
		auto out = matrix<T, 4, 4>::identity();
		out[0, 3] = position.x;
		out[1, 3] = position.y;
		out[2, 3] = position.z;
		return out;
	}

	export template<typename T = float_t>
	constexpr matrix<T, 3, 3> scale_matrix(const vector<T, 3>& scale) {
		auto out = matrix<T, 3, 3>::identity();
		out[0, 0] = scale.x;
		out[1, 1] = scale.y;
		out[2, 2] = scale.z;
		return out;
	}

	export template<typename T = float_t>
	constexpr matrix<T, 4, 4> make_homogenous(const matrix<T, 3, 3>& small) {
		return {{
			small[0, 0], small[0, 1], small[0, 2], 0,
			small[1, 0], small[1, 1], small[1, 2], 0,
			small[2, 0], small[2, 1], small[2, 2], 0,
			0, 0, 0, 1,
		}};
	}

	export template<typename T = float_t>
	constexpr matrix<T, 3, 3> strip_homogenous(const matrix<T, 4, 4>& big) {
		return {{
			big[0, 0], big[0, 1], big[0, 2],
			big[1, 0], big[1, 1], big[1, 2],
			big[2, 0], big[2, 1], big[2, 2],
		}};
	}

	export template<typename T = float_t>
	constexpr matrix<T, 4, 4> combine_3x3_with_translation(const matrix<T, 3, 3>& small, const vector<T, 3> position) {
		auto out = make_homogenous(small);
		out[0, 3] = position.x;
		out[1, 3] = position.y;
		out[2, 3] = position.z;
		return out;
	}

	export template<typename T = float_t, typename Tq = float_t>
	constexpr matrix<T, 4, 4> transformation_matrix(const vector<T, 3>& position, const basic_quaternion<Tq>& rotation, const vector<T, 3>& scale) {
		return combine_3x3_with_translation<T>(rotation_matrix<T, Tq>(rotation) * scale_matrix<T>(scale), position);
	}

	export template<typename T = float_t>
	constexpr matrix<T, 4, 4> look_at_matrix(const vector<T, 3>& observer_position, const vector<T, 3>& target_position, const vector<T, 3>& world_up = {0, 1, 0}) {
		vector<T, 3> forward = normalize(target_position - observer_position);
		vector<T, 3> right = normalize(cross(world_up, forward));
		vector<T, 3> up = cross(forward, right);

		matrix<T, 4, 4> out{};
		out[0, 0] = right.x; out[0, 1] = right.y; out[0, 2] = right.z;
		out[1, 0] = up.x; out[1, 1] = up.y; out[1, 2] = up.z;
		out[2, 0] = forward.x; out[2, 1] = forward.y; out[2, 2] = forward.z;
		out[0, 3] = -dot(right, observer_position);
		out[1, 3] = -dot(up, observer_position);
		out[2, 3] = -dot(forward, observer_position);
		out[3, 3] = static_cast<T>(1);

		return out;
	}

	export template<typename T = float_t>
	constexpr matrix<T, 4, 4> perspective_matrix(
		basic_radian<T> fov_y,
		T aspect_ratio,
		T near_plane_distance = static_cast<T>(.1),
		T far_plane_distance = static_cast<T>(1000),
		bool support_negative_z = false
	) {
		T f = static_cast<T>(1) / stdmath::tan(fov_y / basic_radian<T>(2));

		matrix<T, 4, 4> out;
		out[0, 0] = f / aspect_ratio;
		out[1, 1] = f;
		out[3, 2] = static_cast<T>(1);

		// if (std::isinf(far_plane_distance)) {
		// 	// Infinite far plane
		// 	if (support_negative_z) {
		// 		// OpenGL style: z in [-1, 1]
		// 		out[2, 2] = -static_cast<T>(1);
		// 		out[2, 3] = -(static_cast<T>(2) * near_plane_distance);
		// 	} else {
		// 		// DirectX/Vulkan style: z in [0, 1]
		// 		out[2, 3] = -(out[2, 2] = 1 / near_plane_distance);
		// 	}
		// } else {
			// Finite far plane
			if (support_negative_z) {
				// OpenGL style: z in [-1, 1]
				out[2, 2] = (far_plane_distance + near_plane_distance) / (far_plane_distance - near_plane_distance);
				out[2, 3] = -(static_cast<T>(2) * far_plane_distance * near_plane_distance) / (far_plane_distance - far_plane_distance);
			} else {
				// DirectX/Vulkan style: z in [0, 1]
				out[2, 2] = far_plane_distance / (far_plane_distance - near_plane_distance);
				out[2, 3] = -(far_plane_distance * near_plane_distance) / (far_plane_distance - near_plane_distance);
			}
		// }

		return out;
	}
	export template<typename T = float_t>
	constexpr matrix<T, 4, 4> perspective_matrix(
		basic_radian<T> fov_y,
		const vector<T, 2>& screen_size,
		T near_plane_distance = static_cast<T>(.1),
		T far_plane_distance = static_cast<T>(1000),
		bool support_negative_z = false
	) {
		return perspective_matrix<T>(fov_y, static_cast<T>(screen_size.x) / screen_size.y, near_plane_distance, far_plane_distance, support_negative_z);
	}

	export template<typename T = float_t>
	constexpr matrix<T, 4, 4> orthographic_matrix(
		T left, T right,
		T top, T bottom,
		T near_plane_distance = static_cast<T>(.1),
		T far_plane_distance = static_cast<T>(1000),
		bool support_negative_z = false
	) {
		matrix<T, 4, 4> out = matrix<T, 4, 4>::identity();

		out[0, 0] = static_cast<T>(2) / (right - left);
		out[1, 1] = static_cast<T>(2) / (top - bottom);
		out[0, 3] = -(right + left) / (right - left);
		out[1, 3] = -(top + bottom) / (top - bottom);

		// if (std::isinf(far_plane_distance)) {
		// 	// Infinite far plane
		// 	if (support_negative_z) {
		// 		// OpenGL style: z in [-1, 1]
		// 		out[2, 2] = -static_cast<T>(1);
		// 		out[2, 3] = -(static_cast<T>(2) * near_plane_distance);
		// 	} else {
		// 		// DirectX/Vulkan style: z in [0, 1]
		// 		out[2, 2] = static_cast<T>(0);
		// 		out[2, 3] = -near_plane_distance;
		// 	}
		// } else {
			// Finite far plane
			if (support_negative_z) {
				// OpenGL style: z in [-1, 1]
				out[2, 2] = static_cast<T>(2) / (far_plane_distance - near_plane_distance);
				out[2, 3] = -(far_plane_distance + near_plane_distance) / (far_plane_distance - near_plane_distance);
			} else {
				// DirectX/Vulkan style: z in [0, 1]
				out[2, 2] = static_cast<T>(1) / (far_plane_distance - near_plane_distance);
				out[2, 3] = -near_plane_distance / (far_plane_distance - near_plane_distance);
			}
		// }

		return out;
	}

	export template<typename T = float_t>
	constexpr matrix<T, 4, 4> pixel_perfect_2d_matrix(
		const vector<T, 2>& screen_size,
		T near_plane_distance = static_cast<T>(-.1),
		T far_plane_distance = static_cast<T>(1.1),
		bool support_negative_z = false
	) {
		return orthographic_matrix<T>(static_cast<T>(0), screen_size.x, static_cast<T>(0), screen_size.y, near_plane_distance, far_plane_distance, support_negative_z);
	}

}