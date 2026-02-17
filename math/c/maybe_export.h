
#ifdef STDMATH_MODULE
	#define STDMATH_EXPORT export
	#define STDMATH_INLINE
#else
	#define STDMATH_EXPORT
	#define STDMATH_INLINE inline static
#endif