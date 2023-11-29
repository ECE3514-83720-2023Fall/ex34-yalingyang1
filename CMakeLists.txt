cmake_minimum_required(VERSION 3.9...3.19)
project(Meeting34 CXX)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# build tests
add_executable(unit_tests catch.hpp unit_tests.cpp
  binary_tree.hpp binary_tree.tpp
  test_binary_tree.cpp)

add_executable(instructor_tests catch.hpp unit_tests.cpp
  binary_tree.hpp binary_tree.tpp
  .github/instructor_tests.cpp)
