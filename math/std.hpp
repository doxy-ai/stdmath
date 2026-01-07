#pragma once

#include <concepts>
#if __has_include(<simd>)
	#include <simd>
#elif __has_include(<experimental/simd>)
	#include <experimental/simd>
	namespace stdmath::stl {
		using namespace std::experimental;
	}
#else
	#define STD_MATH_SIMD_UNAVAILABLE
#endif

#if __has_include(<mdspan>)
	#include <mdspan>
#else
	#define MDSPAN_IMPL_STANDARD_NAMESPACE stdmath
	#define MDSPAN_IMPL_PROPOSED_NAMESPACE stl
	#include "../thirdparty/mdspan.hpp"
#endif

#ifndef STD_MATH_DEFAULT_FLOAT_TYPE
#define STD_MATH_DEFAULT_FLOAT_TYPE stdmath::stl::float32_t
#endif

#include <stdfloat>
namespace stdmath::stl { 
	using namespace std;

#ifndef __STDCPP_FLOAT32_T__
	using float32_t = float;
#endif
#ifndef __STDCPP_FLOAT64_T__
	using float64_t = double;
#endif
}

namespace stdmath {
	using float_t = STD_MATH_DEFAULT_FLOAT_TYPE;

	inline static bool approximately_equal(stl::float64_t a, stl::float64_t b, stl::float64_t epsilon = std::numeric_limits<stl::float32_t>::epsilon() * 100) {
		return std::abs<stl::float64_t>(a - b) < epsilon;
	}

	inline static int8_t normalize(stl::float64_t v, stl::float64_t epsilon = std::numeric_limits<stl::float32_t>::epsilon() * 100) {
		if(v - epsilon > 0) return 1;
		if(v + epsilon < 0) return -1;
		return 0;
	}
}