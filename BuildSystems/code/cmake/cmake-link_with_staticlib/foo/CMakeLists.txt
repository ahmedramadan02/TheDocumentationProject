#added line to create libfoo with the respective hpp and cpp files
add_library(foo
    libfoo.cpp
    libfoo.hpp
)

target_include_directories(foo PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_definitions(foo PUBLIC FOO_LIB_VERSION=2.0)