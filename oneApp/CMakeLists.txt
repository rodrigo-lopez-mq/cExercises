cmake_minimum_required(VERSION 3.5)
project(oneApp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp reverse.cpp reverse.h)
add_executable(oneApp ${SOURCE_FILES})