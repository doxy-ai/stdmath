export module stdmath.ray;

import std.compat;
import stdmath.vector;
import stdmath.AABB;

namespace stdmath {

	template<typename T>
	struct interval {
		T min = 1e-4f;
		T max = std::numeric_limits<T>::infinity();

		constexpr static interval universe = { -std::numeric_limits<T>::infinity(), std::numeric_limits<T>::infinity() };
		constexpr static interval empty { std::numeric_limits<T>::infinity(), -std::numeric_limits<T>::infinity() };

		bool contains(T t) const { return t >= min && t <= max; }
		bool surrounds(T t) const { return t > min && t < max; }
		T clamp(T t) const { return std::clamp(t, min, max); }
		T size() const { return max - min; }
		bool is_empty() const { return min >= max; }

		interval expand(T delta) const {
			T pad = delta / 2.0f;
			return { min - pad, max + pad };
		}

		// Union of two intervals
		interval union_with(const interval& o) const {
			return { std::min(min, o.min), std::max(max, o.max) };
		}
		interval operator|(const interval& o) const { return union_with(o); }

		// Intersection of two intervals
		interval intersect_with(const interval& o) const {
			return { std::max(min, o.min), std::min(max, o.max) };
		}
		interval operator&(const interval& o) const { return intersect_with(o); }
	};

	template<typename T, size_t N>
	struct ray {
		vector<T, N> origin, direction;

		vector<T, N> at(T t) const {
			return origin + direction * t;
		}
		vector<T, N> operator[](T t) const { return at(t); }

		T project(const vector<T, N>& p) const {
			return dot(p - origin, direction);
		}

		T project(const vector<T, N>& p, const interval<T>& bounds) const {
			return bounds.clamp(project(p));
		}

		vector<T, N> closest_point(const vector<T, N>& p, const interval<T>& bounds = interval<T>::universe) const {
			return at(project(p, bounds));
		}

		T distance_squared(const vector<T, N>& p, const interval<T>& bounds = interval<T>::universe) const {
			vector<T, N> delta = at(project(p, bounds)) - p;
			return dot(delta, delta);
		}

		T distance(const vector<T, N>& p, const interval<T>& bounds = interval<T>::universe) const {
			return std::sqrt(distance_squared(p, bounds));
		}

		vector<T, N> unit_direction() const { return normalize(direction); }
		ray normalize() const { return {origin, unit_direction()}; }

		std::pair<ray, interval<T>> normalize(const interval<T>& bounds) const { 
			auto length = direction.length();
			assert(length > 0.0f); 
			return {{origin, direction / length}, {bounds.min / length, bounds.max / length}}; 
		}

		// Reflect the ray direction around a surface normal, spawning a new ray
		// from the given hit point.
		ray reflect(const vector<T, N>& hit, const vector<T, N>& normal) const {
			return { hit, stdmath::reflect(direction, normal) };
		}

		// Refract the ray through a surface. eta = n1/n2 (ratio of refractive indices).
		// Returns nullopt on total internal reflection.
		std::optional<ray> refract(const vector<T, N>& hit, const vector<T, N>& normal, T eta) const {
			T cos_theta = std::min(-dot(direction, normal), 1.0f);
			T sin2_theta = eta * eta * (1.0f - cos_theta * cos_theta);
			if (sin2_theta > 1.0f) return std::nullopt; // total internal reflection

			vector<T, N> r_perp = eta * (direction + cos_theta * normal);
			vector<T, N> r_parallel = -std::sqrt(std::abs(1.0f - dot(r_perp, r_perp))) * normal;
			return ray{ hit, normalize(r_perp + r_parallel) };
		}

		// Offset the origin slightly along a normal to avoid self-intersection,
		// keeping direction and bounds intact.
		ray offset(const vector<T, N>& normal) const {
			return { origin + normal * std::numeric_limits<T>::epsilon(), direction };
		}

		// --- Slab / AABB intersection ---

		// Returns the interval of t where the ray is inside the axis-aligned slab
		// [slab_min, slab_max] along a given axis (0=x, 1=y, 2=z, etc...).
		// Returns interval::empty if there is no intersection.
		interval<T> slab(size_t axis, T slab_min, T slab_max, const interval<T>& bounds) const {
			T inv_d = 1.0f / direction.data[axis];
			T t0 = (slab_min - origin.data[axis]) * inv_d;
			T t1 = (slab_max - origin.data[axis]) * inv_d;
			if (t0 > t1) std::swap(t0, t1);
			return bounds & interval{ t0, t1 };
		}

		interval<T> slab(const AABB<T, N>& aabb, interval<T> bounds) const {
			for(size_t i = 0; i < N; ++i)
				bounds = slab(i, aabb.min[i], aabb.max[i], bounds);
			return bounds;
		}
	};

	export template<typename T, size_t N>
	std::ostream& operator<<(std::ostream& out, const ray<T, N>& r) {
		return out << "ray(" << r.origin << " -> " << r.direction << ")";
	}
	export template<typename T>
	std::ostream& operator<<(std::ostream& out, const interval<T>& interval) {
		return out << "interval(" << interval.min << ", " << interval.max << ")";
	}
}

template<typename T, size_t N>
struct std::formatter<stdmath::ray<T, N>> {
	std::formatter<stdmath::vector<T, N>> elem_formatter;

	constexpr auto parse(std::format_parse_context& ctx) {
		return elem_formatter.parse(ctx);
	}

	template<typename FormatContext>
	auto format(const stdmath::ray<T, N>& r, FormatContext& ctx) const {
		auto out = std::format_to(ctx.out(), "ray(");
		out = elem_formatter.format(r.origin, ctx);
		out = std::format_to(out, " -> ");
		out = elem_formatter.format(r.direction, ctx);
		return std::format_to(out, ")");
	}
};

template<typename T>
struct std::formatter<stdmath::interval<T>> {
	std::formatter<T> elem_formatter;

	constexpr auto parse(std::format_parse_context& ctx) {
		return elem_formatter.parse(ctx);
	}

	template<typename FormatContext>
	auto format(const stdmath::interval<T>& interval, FormatContext& ctx) const {
		auto out = std::format_to(ctx.out(), "interval(");
		out = elem_formatter.format(interval.min, ctx);
		out = std::format_to(out, ", ");
		out = elem_formatter.format(interval.max, ctx);
		return std::format_to(out, ")");
	}
};
