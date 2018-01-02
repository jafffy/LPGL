cmake_minimum_required(VERSION 3.3)
project(LPGL)

find_package(OpenGL REQUIRED)

set(LPGL_INCLUDE ${CMAKE_SOURCE_DIR}/include)

add_subdirectory(lib)
add_subdirectory(examples)
add_subdirectory(tests)