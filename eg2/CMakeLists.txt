cmake_minimum_required(VERSION 3.10)

project(eg2)

add_library(mycalc STATIC
    calc.cpp
    calc.h
)

add_executable(eg2
    main.cpp
)
target_link_libraries(eg2
    mycalc
    -static-libgcc -static-libstdc++
)