#pragma once

#include <vector>

class Point {
    std::vector<int> coords;

public:
    int getX() {
        return coords[0];
    }

    int getY() {
        return coords[1];
    }

    int getZ() {
        return coords[2];
    }

    Point(int x, int y, int z) :
        coords({x, y, z})
        {};
};
