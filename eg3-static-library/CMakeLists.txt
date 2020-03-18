cmake_minimum_required(VERSION 3.10)

project(eg3)

add_library(mycalc STATIC
    calc.cpp
    calc.h
)

add_executable(eg3
    main.cpp
)

if(APPLE)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libstdc++")
endif(APPLE)

if(MSYS)
    set(CMAKE_CXX_STANDARD_LIBRARIES "-static-libgcc -static-libstdc++ -lwsock32 -lws2_32 ${CMAKE_CSS_STANDARD_LIBRARIES}")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive")
endif(MSYS)

target_link_libraries(eg3
    mycalc
)