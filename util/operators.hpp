#pragma once

namespace stdmath {

	template<typename Tunderlying>
	struct operators_crtp {
		
	#define STDMATH_CRTP_BINARY_OP(name, symbol)\
		inline friend Tunderlying operator symbol(const Tunderlying& a, const Tunderlying& b) {\
			return Tunderlying::name(a, b);\
		}\
		\
		template<typename Tlike>\
		inline friend Tunderlying operator symbol(const Tunderlying& a, const Tlike& b) {\
			return Tunderlying::name(a, b);\
		}\
		\
		template<typename Tlike>\
		inline friend Tunderlying operator symbol(const Tlike& a, const Tunderlying& b) {\
			return Tunderlying::name(a, b);\
		}\

	#define STDMATH_CRTP_BINARY_OP_WITH_EQ(name, symbol) STDMATH_CRTP_BINARY_OP(name, symbol)\
		inline friend Tunderlying& operator symbol##=(Tunderlying& a, const Tunderlying& b) {\
			return a = Tunderlying::name(a, b);\
		}\
		\
		template<typename Tlike>\
		inline friend Tunderlying& operator symbol##=(Tunderlying& a, const Tlike& b) {\
			return a = Tunderlying::name(a, b);\
		}

	#define STDMATH_CRTP_UNARY_OP(name, symbol)\
		inline friend Tunderlying operator symbol(const Tunderlying& v) {\
			return v.name();\
		}

		STDMATH_CRTP_BINARY_OP_WITH_EQ(add, +)
		STDMATH_CRTP_BINARY_OP_WITH_EQ(subtract, -)
		STDMATH_CRTP_UNARY_OP(negate, -)
		STDMATH_CRTP_BINARY_OP_WITH_EQ(multiply, *)
		STDMATH_CRTP_BINARY_OP_WITH_EQ(divide, /)
		STDMATH_CRTP_BINARY_OP_WITH_EQ(modulus, %)

		STDMATH_CRTP_UNARY_OP(logical_not, !)
		STDMATH_CRTP_UNARY_OP(bitwise_not, ~)
		STDMATH_CRTP_BINARY_OP(logical_and, &&)
		STDMATH_CRTP_BINARY_OP_WITH_EQ(bitwise_and, &)
		STDMATH_CRTP_BINARY_OP(logical_or, ||)
		STDMATH_CRTP_BINARY_OP_WITH_EQ(bitwise_or, |)
		STDMATH_CRTP_BINARY_OP_WITH_EQ(bitwise_xor, ^)

		STDMATH_CRTP_BINARY_OP_WITH_EQ(shift_left, <<)
		STDMATH_CRTP_BINARY_OP_WITH_EQ(shift_right, >>)
	};

	template<typename Tunderlying, typename Tboolean>
	struct comparison_operators_crtp {

	#define STDMATH_CRTP_COMPARISON_OP(name, symbol)\
		inline friend Tboolean operator symbol(const Tunderlying& a, const Tunderlying& b) {\
			return Tunderlying::name(a, b);\
		}\
		\
		template<typename Tlike>\
		inline friend Tboolean operator symbol(const Tunderlying& a, const Tlike& b) {\
			return Tunderlying::name(a, b);\
		}\
		\
		template<typename Tlike>\
		inline friend Tboolean operator symbol(const Tlike& a, const Tunderlying& b) {\
			return Tunderlying::name(a, b);\
		}\

		STDMATH_CRTP_COMPARISON_OP(equal_to, ==)
		STDMATH_CRTP_COMPARISON_OP(not_equal_to, !=)
		STDMATH_CRTP_COMPARISON_OP(less_than, <)
		STDMATH_CRTP_COMPARISON_OP(less_than_or_equal_to, <=)
		STDMATH_CRTP_COMPARISON_OP(greater_than, >)
		STDMATH_CRTP_COMPARISON_OP(greater_than_or_equal_to, >=)

	};

}