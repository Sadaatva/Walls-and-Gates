cmake_minimum_required(VERSION 3.10)
project(project)
add_executable(project test_aMatrix.cpp)
target_link_libraries(project gtest)