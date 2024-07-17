cmake_minimum_required(VERSION 3.5.0)
project(cpp-tools VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

include_directories(src)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(circular_buffer test/circular_buffer.cpp)
add_test(test_circular_buffer circular_buffer)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
