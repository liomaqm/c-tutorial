cmake_minimum_required(VERSION 3.10)
project(what_is_your_name C)

set(CMAKE_C_STANDARD 99)

add_executable(arg arg.c)
add_executable(name name.c)
