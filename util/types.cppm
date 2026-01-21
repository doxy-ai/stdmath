module;

import std.compat;

export module stdmath.types;

namespace stdmath { inline namespace types {
	export using byte = std::byte;
	export using u32 = uint32_t;
	export using i32 = int32_t;
	export using bool32 = u32;

#ifdef __STDCPP_FLOAT16_T__
	export using f16 = std::float16_t;
#endif
#ifdef __STDCPP_FLOAT32_T__
	export using f32 = std::float32_t;
#else
	export using f32 = float;
#endif
#ifdef __STDCPP_FLOAT64_T__
	export using f64 = std::float64_t;
#else
	export using f64 = double;
#endif
#ifdef __STDCPP_BFLOAT16_T_
	export using bf16 = std::bfloat16_t;
#endif

	export using real_t = f32;

	export bool approximately_equal(f64 a, f64 b, f64 epsilon = std::numeric_limits<f32>::epsilon() * 100) {
		return std::fabsl(a - b) < epsilon;
	}

	export constexpr int8_t normalize(f64 v, f64 epsilon = std::numeric_limits<f32>::epsilon() * 100) {
		if(v - epsilon > 0) return 1;
		if(v + epsilon < 0) return -1;
		return 0;
	}

	export constexpr f64 fract(f64 x) {
		return x - std::floor(x);
	}
}}