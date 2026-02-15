export module stdmath.AABB;

import std.compat;
import stdmath.vector;

namespace stdmath {
	// TODO: This file is currently untested!

	export template<typename T, size_t Dims>
	struct AABB {
		using vec = vector<T, Dims>;
		vec min, max;

		static AABB from_center_size(const vec& center, const vec& size) {
			return {
				.min = center - size / 2,
				.max = center + size / 2
			};
		}

		vec center() const {
			return (min + max) / 2;
		}

		AABB& set_center(const vec& c) {
			return *this = from_center_size(c, size());
		}

		vec size() const {
			return max - min;
		}

		AABB& set_size(const vec& s) {
			return *this = from_center_size(center(), s);
		}

		bool is_valid() const {
			return none_of(min > max);
		}

		AABB& normalize() {
			for (size_t i = 0; i < Dims; ++i)
				if (min[i] > max[i])
					std::swap(min[i], max[i]);
			return *this;
		}

		T volume() const {
			return size().reduce_elements(T{1}, std::multiplies<T>{});
		}

		T surface_area() const requires (Dims >= 2) {
			vec s = size();
			T area = 0;
			for (size_t i = 0; i < Dims; ++i)
				for (size_t j = i + 1; j < Dims; ++j)
					area += s[i] * s[j];
			return area * 2;
		}


		vec closest_point_on_surface(const vec& v) {
			return clamp(v, min, max);
		}

		bool contains(const vec& p) const {
			return none_of(p < min || p > max);
		}

		bool contains(const AABB& o) const {
			return none_of(o.min < min || o.max > max);
		}

		bool overlaps(const AABB& o) const {
			return none_of(max < o.min || min > o.max);
		}

		AABB& expand(const vec& p) {
			min = stdmath::min(min, p);
			max = stdmath::max(max, p);
			return *this;
		}

		AABB& expand(const AABB& o) {
			min = stdmath::min(min, o.min);
			max = stdmath::max(max, o.max);
			return *this;
		}

		static AABB merge(const AABB& a, const AABB& b) {
			return {
				.min = stdmath::min(a.min, b.min),
				.max = stdmath::max(a.max, b.max)
			};
		}
		inline friend AABB operator+(const AABB& a, const AABB& b) { return merge(a, b); }

		std::optional<AABB> intersect(const AABB& other) const {
			AABB result {
				.min = stdmath::max(min, other.min),
				.max = stdmath::min(max, other.max),
			};

			if(any_of(result.min > result.max))
				return {};
			return result;
		}
		std::optional<AABB> operator&(const AABB& other) { return intersect(other); }

		T distance_squared(const vec& p) const {
			T d = 0;
			for (size_t i = 0; i < Dims; ++i) {
				if (p[i] < min[i]) {
					T t = min[i] - p[i];
					d += t * t;
				} else if (p[i] > max[i]) {
					T t = p[i] - max[i];
					d += t * t;
				}
			}
			return d;
		}
		T distance(const vec& p) const {
			return std::sqrt(distance_squared(p));
		}

		AABB& inflate(const vec& amount) {
			min -= amount;
			max += amount;
			return *this;
		}

	};

	export template<typename T>
	using rectangle = AABB<T, 2>;

	export template<typename T>
	using box = AABB<T, 3>;

	export template<typename T, size_t Dims>
	AABB<T, Dims> normalize(AABB<T, Dims> aabb) {
		return aabb.normalize();
	}

	export template<typename T, size_t Dims>
	std::ostream& operator<<(std::ostream& out, const AABB<T, Dims>& aabb) {
		return out << "AABB(" << aabb.min << ", " << aabb.max << ")";
	}
}

template<typename T, size_t Dims>
struct std::formatter<stdmath::AABB<T, Dims>> {
	std::formatter<stdmath::vector<T, Dims>> elem_formatter;

	constexpr auto parse(std::format_parse_context& ctx) {
		return elem_formatter.parse(ctx);
	}

	template<typename FormatContext>
	auto format(const stdmath::AABB<T, Dims>& aabb, FormatContext& ctx) const {
		auto out = std::format_to(ctx.out(), "AABB(");
		out = elem_formatter.format(aabb.min, ctx);
		out = std::format_to(out, ", ");
		out = elem_formatter.format(aabb.max, ctx);
		return std::format_to(out, ")");
	}
};
