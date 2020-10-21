cmake_minimum_required(VERSION 3.12)
project(cmake-test VERSION 1.0.0)

add_subdirectory(foo)
add_executable(cmake-test main.cpp)

target_link_libraries(cmake-test PRIVATE foo)
