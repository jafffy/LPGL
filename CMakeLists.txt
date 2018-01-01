cmake_minimum_required(VERSION 3.3)
project(LPGL)

find_package(OpenGL REQUIRED)

add_subdirectory(examples)
add_subdirectory(tests)