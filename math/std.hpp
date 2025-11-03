#pragma once

#include <concepts>
#if __has_include(<simd>)
	#include <simd>
#else
	#include <experimental/simd>
	namespace stdmath::stl {
		using namespace std::experimental;
	}
#endif

#if __has_include(<mdspan>)
	#include <mdspan>
#else
	#define MDSPAN_IMPL_STANDARD_NAMESPACE stdmath
	#define MDSPAN_IMPL_PROPOSED_NAMESPACE experimental
	#include "../thirdparty/mdspan.hpp"

	namespace stdmath::stl {
		using namespace stdmath::experimental;
	}
#endif

#if __has_include(<linalg>)
	#include <linalg>
#else
	#ifndef MDSPAN_IMPL_STANDARD_NAMESPACE
	#define MDSPAN_IMPL_STANDARD_NAMESPACE stdmath
	#define MDSPAN_IMPL_PROPOSED_NAMESPACE experimental
	#endif
	#include <__p1673_bits/linalg_config.h>
	#include <experimental/linalg>

	#ifndef MDSPAN_IMPL_STANDARD_NAMESPACE
	namespace stdmath::stl {
		using namespace stdmath::experimental;
	}
	#endif
#endif

#ifndef STD_MATH_DEFAULT_FLOAT_TYPE
#define STD_MATH_DEFAULT_FLOAT_TYPE stdmath::stl::float64_t
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

	constexpr bool approximately_equal(stl::float64_t a, stl::float64_t b, stl::float64_t epsilon = std::numeric_limits<stl::float32_t>::epsilon() * 100) {
		return std::abs<stl::float64_t>(a - b) < epsilon;
	}
}