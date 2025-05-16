#pragma once

#if __has_include(<simd>)
	#include <simd>
#else
	#include <experimental/simd>
	namespace stdmath {
		using namespace std::experimental;
	}
#endif

#if __has_include(<mdspan>)
	#include <mdspan>
#else
	#define MDSPAN_IMPL_STANDARD_NAMESPACE stdmath
	#define MDSPAN_IMPL_PROPOSED_NAMESPACE experimental
	#include "thirdparty/mdspan.hpp"

	namespace stdmath {
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
	namespace stdmath {
		using namespace stdmath::experimental;
	}
	#endif
#endif

namespace stdmath { using namespace std; }