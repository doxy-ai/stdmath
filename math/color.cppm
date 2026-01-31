export module stdmath.color;

import std.compat;
import stdmath.vector;
import stdmath.types;

namespace stdmath {

	export template<typename T>
	struct basic_color : public vector<T, 4> {
		using super = vector<T, 4>;
		using super::super;
		basic_color(const basic_color&) = default;
		basic_color(basic_color&&) = default;
		basic_color(const super& o) : super(o) {}
		basic_color(super&& o) : super(std::move(o)) {}
		basic_color& operator=(const basic_color&) = default;
		basic_color& operator=(basic_color&&) = default;

		static basic_color from_hex(std::string_view hex) {
			if (!hex.empty() && hex[0] == '#')
				hex.remove_prefix(1);

			constexpr auto hex_digit = [](char c) -> int {
				if (c >= '0' && c <= '9') return c - '0';
				if (c >= 'a' && c <= 'f') return c - 'a' + 10;
				if (c >= 'A' && c <= 'F') return c - 'A' + 10;
				return -1;
			};

			auto read = [&](size_t i) -> int {
				return hex_digit(hex[i]) * 16 + hex_digit(hex[i + 1]);
			};

			real_t r = 0, g = 0, b = 0, a = real_t(1);

			if (hex.size() == 3 || hex.size() == 4) {
				r = hex_digit(hex[0]) / real_t(15);
				g = hex_digit(hex[1]) / real_t(15);
				b = hex_digit(hex[2]) / real_t(15);
				if (hex.size() == 4)
					a = hex_digit(hex[3]) / real_t(15);
			}
			else if (hex.size() == 6 || hex.size() == 8) {
				r = read(0) / real_t(255);
				g = read(2) / real_t(255);
				b = read(4) / real_t(255);
				if (hex.size() == 8)
					a = read(6) / real_t(255);
			}

			if constexpr(std::is_same_v<T, uint8_t>)
				return basic_color<real_t>{ r, g, b, a }.color32_normalized_to_color8();
			else return { r, g, b, a };
		}

		template<typename Tfunction>
		constexpr inline basic_color elementwise_transform_ignoring_alpha(const Tfunction& function) const {
			auto out = this->elementwise_transform(function);
			out.w = this->w; // Written this way in case we find a way to simd accelerate elementwise_transform in the future
			return out;
		}

		basic_color srgb_to_linear_accurate(){
			return elementwise_transform_ignoring_alpha([](T c){
				if (c <= T(0.04045))
					return c / T(12.92);
				else return std::pow((c + T(0.055)) / T(1.055), T(2.4));
			});
		}

		basic_color linear_to_srgb_accurate() {
			return elementwise_transform_ignoring_alpha([](T c){
				if (c <= T(0.0031308))
					return c * T(12.92);
				else return T(1.055) * std::pow(c, T(1.0 / 2.4)) - T(0.055);
			});
		}

		basic_color gamma(T gamma) {
			return elementwise_transform_ignoring_alpha([gamma](T c){
				return std::pow(c, gamma);
			});
		}


		basic_color srgb_to_linear(){
			return gamma(2.2);
		}

		basic_color linear_to_srgb() {
			return gamma(1/2.2);
		}

		basic_color linear_to_hsv() {
			T r = this->data[0], g = this->data[1], b = this->data[2];

			T maxv = this->max_element();
			T minv = this->min_element();
			T delta = maxv - minv;

			T h = T(0);
			T s = (maxv == T(0)) ? T(0) : (delta / maxv);
			T v = maxv;

			if (delta != T(0)) {
				if (maxv == r)
					h = (g - b) / delta + (g < b ? T(6) : T(0));
				else if (maxv == g)
					h = (b - r) / delta + T(2);
				else
					h = (r - g) / delta + T(4);

				h /= T(6);
			}

			return { h, s, v, this->data[3] };
		}

		basic_color<T> hsv_to_linear() {
			T h = T(fract(this->data[0])) * T(6);
			T s = this->data[1];
			T v = this->data[2];

			T i = std::floor(h);
			T f = h - i;

			T p = v * (T(1) - s);
			T q = v * (T(1) - s * f);
			T t = v * (T(1) - s * (T(1) - f));

			T r, g, b;

			switch (static_cast<int>(i) % 6) {
				case 0: r = v; g = t; b = p; break;
				case 1: r = q; g = v; b = p; break;
				case 2: r = p; g = v; b = t; break;
				case 3: r = p; g = q; b = v; break;
				case 4: r = t; g = p; b = v; break;
				default:r = v; g = p; b = q; break;
			}

			return { r, g, b, this->data[3] };
		}

		T luminance() {
			return this->data[0] * T(0.2126)
				+ this->data[1] * T(0.7152)
				+ this->data[2] * T(0.0722);
		}

		basic_color linear_to_grayscale() {
			return { luminance(), luminance(), luminance(), this->data[3] };
		}

		basic_color linear_to_oklab() {
			// Linear RGB → LMS
			T l = T(0.4122214708) * this->data[0] + T(0.5363325363) * this->data[1] + T(0.0514459929) * this->data[2];
			T m = T(0.2119034982) * this->data[0] + T(0.6806995451) * this->data[1] + T(0.1073969566) * this->data[2];
			T s = T(0.0883024619) * this->data[0] + T(0.2817188376) * this->data[1] + T(0.6299787005) * this->data[2];

			// Non-linear transform
			l = std::cbrt(l);
			m = std::cbrt(m);
			s = std::cbrt(s);

			return {
				T(0.2104542553) * l + T(0.7936177850) * m - T(0.0040720468) * s,
				T(1.9779984951) * l - T(2.4285922050) * m + T(0.4505937099) * s,
				T(0.0259040371) * l + T(0.7827717662) * m - T(0.8086757660) * s,
				this->data[3]
			};
		}

		basic_color oklab_to_linear() {
			T L = this->data[0];
			T a = this->data[1];
			T b = this->data[2];

			T l = L + T(0.3963377774) * a + T(0.2158037573) * b;
			T m = L - T(0.1055613458) * a - T(0.0638541728) * b;
			T s = L - T(0.0894841775) * a - T(1.2914855480) * b;

			l = l * l * l;
			m = m * m * m;
			s = s * s * s;

			return {
				T(+4.0767416621) * l - T(3.3077115913) * m + T(0.2309699292) * s,
				T(-1.2684380046) * l + T(2.6097574011) * m - T(0.3413193965) * s,
				T(-0.0041960863) * l - T(0.7034186147) * m + T(1.7076147010) * s,
				this->data[3]
			};
		}

		basic_color premultiply_alpha() {
			return elementwise_transform_ignoring_alpha([this](T c){
				return c * this->data[3];
			});
		}
		basic_color unpremultiply_alpha() {
			if (this->data[3] == T(0))
				return *this;

			T inv = T(1) / this->data[3];
			return elementwise_transform_ignoring_alpha([inv](T c){
				return c * inv;
			});
		}

		basic_color exposure(T stops) {
			T factor = std::exp2(stops);
			return elementwise_transform_ignoring_alpha([factor](T c){
				return c * factor;
			});
		}

		basic_color<real_t> color8_to_color32_normalized() {
			basic_color<real_t> out = *this;
			return out.elementwise_transform([](T c){
				return c / 255.;
			});
		}

		basic_color<uint8_t> color32_normalized_to_color8() {
			return this->elementwise_transform([](T c){
				return c * 255.;
			});
		}

		std::string linear_to_hex(bool include_alpha = false) {
			auto color8 = *this;
			if constexpr(!std::is_same_v<T, uint8_t>)
				color8 = color32_normalized_to_color8();

			uint8_t r = color8[0];
			uint8_t g = color8[1];
			uint8_t b = color8[2];
			uint8_t a = color8[3];

			std::ostringstream oss;
			oss << '#'
				<< std::hex << std::setfill('0') << std::nouppercase
				<< std::setw(2) << int(r)
				<< std::setw(2) << int(g)
				<< std::setw(2) << int(b);

			if (include_alpha)
				oss << std::setw(2) << int(a);

			return oss.str();
		}
	};

	export template<typename T>
	basic_color<T> saturate(const basic_color<T>& c) {
		return clamp(c, {0}, {1});
	}

	export using color32 = basic_color<float>;
	export using color8 = basic_color<uint8_t>;

	export inline color8 denormalize(color32 c32) { return c32.color32_normalized_to_color8(); }
	export inline color32 normalize(color8 c8) { return c8.color8_to_color32_normalized(); }
}