cmake_minimum_required(VERSION 3.17)
project(stack)
find_package(GTest REQUIRED)
find_package(benchmark REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer -O3")

add_library(stack stack.cpp)
add_executable(main main.cpp)
target_link_libraries(main stack)

add_executable(test_suite_stack test_suite_stack.cpp)
target_link_libraries(test_suite_stack stack GTest::GTest)

add_executable(benchmark benchmark.cpp)
target_link_libraries(benchmark stack benchmark::benchmark)
