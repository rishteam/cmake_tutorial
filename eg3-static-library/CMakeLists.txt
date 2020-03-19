cmake_minimum_required(VERSION 3.10)

project(eg3)

# Add static library
add_library(mycalc STATIC
    src/calc.cpp
    include/calc.h
)
target_include_directories(mycalc
    PRIVATE ${PROJECT_SOURCE_DIR}/include
)

# Add the executable
add_executable(eg3
    src/main.cpp
)
target_include_directories(eg3
    PRIVATE ${PROJECT_SOURCE_DIR}/include
)

if(APPLE)
    target_link_libraries(eg3
        mycalc
    )
endif(APPLE)

if(MSYS)
    set(CMAKE_CXX_STANDARD_LIBRARIES "-static-libgcc -static-libstdc++ -lwsock32 -lws2_32 ${CMAKE_CSS_STANDARD_LIBRARIES}")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive")
    target_link_libraries(eg3
        mycalc
    )
endif(MSYS)