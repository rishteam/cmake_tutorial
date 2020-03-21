cmake_minimum_required(VERSION 3.10)

project(eg4
    VERSION 0.0.1
    DESCRIPTION "Dynamic library example"
    HOMEPAGE_URL "http://blog.roy4801.tw/"
    LANGUAGES CXX
)

# Add shared library
add_library(mycalc SHARED
    src/calc.cpp
    include/calc.h
)
target_include_directories(mycalc
    PRIVATE ${PROJECT_SOURCE_DIR}/include
)

# include(GenerateExportHeader)
# generate_export_header(mycalc
#     EXPORT_FILE_NAME ${CMAKE_BINARY_DIR}/calc_export.h
# )

add_executable(eg4
    src/main.cpp
)
target_include_directories(eg4
    PRIVATE ${PROJECT_SOURCE_DIR}/include
)

if(APPLE)
    target_link_libraries(eg4
        mycalc
    )
endif(APPLE)

if(MSYS)
    target_link_libraries(eg4
        mycalc
        # For static libraries
        -static-libgcc -static-libstdc++ -lwsock32 -lws2_32
        -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive
    )
endif(MSYS)

if(MSVC)
    message(FATAL_ERROR "Not support MSVC yet")
    target_link_libraries(eg4
        mycalc
    )
endif(MSVC)