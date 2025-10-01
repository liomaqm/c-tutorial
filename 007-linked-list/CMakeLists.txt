cmake_minimum_required(VERSION 3.10)

project(c-tutorial C)

set(SOURCE_FILE main.c)

add_executable(main ${SOURCE_FILE})
add_executable(main_solved main_solved.c)
add_executable(main_doubly main_doubly.c)