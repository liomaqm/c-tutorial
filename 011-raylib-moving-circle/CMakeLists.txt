cmake_minimum_required(VERSION 3.10)
project(raylib_circle C)

set(CMAKE_C_STANDARD 99)

find_package(raylib REQUIRED)

add_executable(main main.c)
add_executable(main_auto main_auto.c)


target_link_libraries(main PRIVATE raylib)
target_link_libraries(main_auto PRIVATE raylib)

