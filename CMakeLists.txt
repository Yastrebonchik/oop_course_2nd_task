cmake_minimum_required(VERSION 3.23)
project(oop_course_2nd_task)

set(CMAKE_CXX_STANDARD 14)

include_directories(includes)

add_executable(oop_course_2nd_task srcs/main.cpp srcs/list_tests.cpp)
