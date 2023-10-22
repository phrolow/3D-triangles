cmake_minimum_required(VERSION 3.26)
project(3D-triangles_tests)

set(CMAKE_CXX_STANDARD 23)

set(default_build_type "Debug")

message("testin'")

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(TESTS "3D-triangles_tests")
set(TESTS_SRC_LIST triangle.cpp
        main.cpp
        plane.cpp)

set(TESTS_SRC_LIST ${TESTS_SRC_LIST} ../src/geometry/line.cpp
                                    ../src/geometry/line.h
                                    ../src/geometry/plane.cpp
                                    ../src/geometry/plane.h
                                    ../src/geometry/triangle.cpp
                                    ../src/geometry/triangle.h)

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS}")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
add_executable(${TESTS} ${TESTS_SRC_LIST})

target_include_directories(${TESTS} PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(${TESTS} gtest gtest_main gmock)