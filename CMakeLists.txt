cmake_minimum_required(VERSION 3.26)
project(3D-triangles)

set(CMAKE_CXX_STANDARD 23)

find_package (Eigen3 3.3 REQUIRED NO_MODULE)

set(GTESTS True)

if (GTESTS)
    add_subdirectory(tests)
else()
    set(SRC src/main.cpp
            src/geometry/line.cpp
            src/geometry/line.h
            src/geometry/plane.cpp
            src/geometry/plane.h
            src/geometry/triangle.cpp
            src/geometry/triangle.h)

    add_executable(3D-triangles ${SRC})
endif()