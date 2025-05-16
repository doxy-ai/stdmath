#pragma once

#if __has_include(<simd>)
	#include <simd>
#else
	#include <experimental/simd>
	namespace stdmath {
		using namespace std::experimental;
	}
#endif