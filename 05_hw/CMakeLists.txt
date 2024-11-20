cmake_minimum_required(VERSION 3.10)
project(stack)
find_package(GTest REQUIRED)

add_library(stack stack.cpp)
add_executable(main main.cpp)
target_link_libraries(main stack)

add_executable(test_suite_stack test_suite_stack.cpp)
target_link_libraries(test_suite_stack stack GTest::GTest)
