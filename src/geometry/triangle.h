#pragma once

#include "EigenAdapter.h"

#include "plane.h"
#include <vector>

class Triangle {
    std::vector<Vector> points;

public:
    std::vector<Vector>& getPoints() {
        return points;
    }

    Segment& intersection(Line line);

    bool intersects(Triangle other);

    Triangle(Vector p1, Vector p2, Vector p3) : points({p1, p2, p3}) {}
};