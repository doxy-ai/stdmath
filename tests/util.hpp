#pragma once

#include <math/namespace_alias.hpp>

import std.compat;
import stdmath;

using namespace std::math::types;

inline bool ceq(f64 a, f64 b, f64 eps = 1e-4f) {
	return std::math::approximately_equal(a, b, eps);
}

template<typename T, size_t N>
inline bool ceq(const std::math::vector<T, N>& a, const std::math::vector<T, N>& b, f64 eps = 1e-4f) {
	return all_of(std::math::approximately_equal(a, b, eps));
}

template<typename T>
inline bool ceq(const std::math::basic_quaternion<T>& a, const std::math::basic_quaternion<T>& b, f64 eps = 1e-4f) {
	return all_of(std::math::approximately_equal(a, b, eps));
}