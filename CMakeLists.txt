cmake_minimum_required(VERSION 3.26)
project(3D-triangles)

set(CMAKE_CXX_STANDARD 23)

find_package (Eigen3 3.3 REQUIRED NO_MODULE)

add_executable(3D-triangles src/main.cpp
        src/geometry/vector.cpp
        src/geometry/vector.h
        src/geometry/line.cpp
        src/geometry/line.h)

target_link_libraries (3D-triangles Eigen3::Eigen)