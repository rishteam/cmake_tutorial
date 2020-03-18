cmake_minimum_required(VERSION 3.10)

project(eg2
    VERSION 0.0.1
    DESCRIPTION "This is second cmake tutorial project"
    HOMEPAGE_URL "http://blog.roy4801.tw/"
    LANGUAGES CXX
)

add_executable(eg2
    src/hello.cpp
    src/main.cpp
)

target_include_directories(eg2
    PRIVATE ${PROJECT_SOURCE_DIR}/include
)