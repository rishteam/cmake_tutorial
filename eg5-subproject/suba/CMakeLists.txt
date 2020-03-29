# Set the project name
project (subprojA)

# Add a library with the above sources
add_library(${PROJECT_NAME}
    src/suba.cpp
)
add_library(sub::suba ALIAS ${PROJECT_NAME})

target_include_directories( ${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)