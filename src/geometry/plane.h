#pragma once

#include "EigenAdapter.h"

#include "line.h"

#include <boost/geometry/arithmetic/cross_product.hpp>
#include <boost/geometry/arithmetic/arithmetic.hpp>

namespace Geometry {
class Plane {
    // (n, x) + d = 0
    Vector n_;
    double d_;

public:
    Vector& getN() {
        return n_;
    }

    int getD() {
        return d_;
    }

    double distance(Vector point) {
        return n_.dot(point) + d_;
    }

    Line& intersection(Plane &other);

    Plane(Vector p0, Vector p1, Vector p2) {
        n_ = p1 - p0;
        n_ = n_.cross(p2 - p0); // n = (p1 - p0) x (p2 - p0)

        d_ = -(n_.dot(p0));
    }
};
}