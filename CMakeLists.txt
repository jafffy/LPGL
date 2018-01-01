cmake_minimum_required(VERSION 3.3)
project(LPGL)

enable_testing()
set (GTEST_ROOT ${CMAKE_SOURCE_DIR}/deps/googletest/googletest)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(LPGL_TEST_SRC tests/lpgl_test.cc)
add_executable(lpgl_test ${LPGL_TEST_SRC})
target_link_libraries(lpgl_test ${GTEST_BOTH_LIBRARIES})

add_test(AllTestsInLPGL lpgl_test)