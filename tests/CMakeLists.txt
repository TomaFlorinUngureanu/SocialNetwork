cmake_minimum_required(VERSION 3.17)
project(tests)

add_subdirectory(lib/googletest)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(tests tests_main.cpp)
target_link_libraries(tests gtest gtest_main)
add_test(tests tests)