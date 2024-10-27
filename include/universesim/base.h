#pragma once

// clang-format off
// 
// Shared library macros
#if defined(_WIN32) || defined(_WIN64)
    #ifdef BUILD_SHARED_LIBS
        #define UNISIM_EXPORT __declspec(dllexport)
    #else
        #define UNISIM_EXPORT __declspec(dllimport)
    #endif
#else
    #ifdef BUILD_SHARED_LIBS
        #define UNISIM_EXPORT __attribute__((visibility("default")))
    #else
        #define UNISIM_EXPORT
    #endif
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
