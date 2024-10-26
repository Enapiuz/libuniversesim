#pragma once

// clang-format off
// 
// Shared library macros
#if defined( _MSC_VER ) && defined( libuniversesimEXPORTS )
    // build the Windows DLL
    #define UNISIM_EXPORT __declspec( dllexport )
#elif defined( _MSC_VER ) && defined( LIBUNIVERSESIM_DLL )
    // using the Windows DLL
    #define UNISIM_EXPORT __declspec( dllimport )
#elif defined( libuniversesim_EXPORTS )
    // building or using shared library
    #define UNISIM_EXPORT __attribute__( ( visibility( "default" ) ) )
#else
    // static library
    #define UNISIM_EXPORT
#endif

// C++ macros
#ifdef __cplusplus
    #define UNISIM_API extern "C" UNISIM_EXPORT
    #define UNISIM_INLINE inline
    #define UNISIM_LITERAL(T) T
    #define UNISIM_ZERO_INIT {}
#else
    #define UNISIM_API UNISIM_EXPORT
    #define UNISIM_INLINE static inline
    #define UNISIM_LITERAL(T) (T)
    #define UNISIM_ZERO_INIT {0}
#endif
// clang-format on
