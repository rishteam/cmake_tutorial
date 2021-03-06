cmake_minimum_required(VERSION 3.10)

project(eg3
    VERSION 0.0.1
    DESCRIPTION "Static library example"
    HOMEPAGE_URL "http://blog.roy4801.tw/"
    LANGUAGES CXX
)

# Add static library
add_library(mycalc STATIC
    src/calc.cpp
)
target_include_directories(mycalc
    PUBLIC ${PROJECT_SOURCE_DIR}/include
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
    target_link_libraries(eg3
        mycalc
        # For static libraries
        -static-libgcc -static-libstdc++ -lwsock32 -lws2_32
        -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive
    )
endif(MSYS)

if(MSVC)
    target_link_libraries(eg3
        mycalc
    )
endif(MSVC)