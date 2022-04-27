cmake_minimum_required(VERSION 3.23)

project(topzbar C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_VERBOSE_MAKEFILE ON)

add_subdirectory(zbar)
add_subdirectory(examples)