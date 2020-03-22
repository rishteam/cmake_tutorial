#pragma once

#if defined(_WIN32) || defined(__CYGWIN__)
    #ifdef MYCALC_STATIC
        #define MYCALC_API
    #else
        #if defined(mycalc_EXPORTS)
            #ifdef __GNUC__
                #define MYCALC_API __attribute__ ((dllexport))
            #else
                #define MYCALC_API __declspec(dllexport)
            #endif
        #else
            #ifdef __GNUC__
                #define MYCALC_API __attribute__((dllimport))
            #else
                #define MYCALC_API __declspec(dllimport)
            #endif
        #endif
    #endif
#else
    #if __GNUC__ >= 4
        #define MYCALC_API __attribute__((visibility("default")))
    #else
        #define MYCALC_API
    #endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

MYCALC_API int Cube(int x);
MYCALC_API int Square(int x);

#ifdef __cplusplus
}
#endif