#pragma once

#include "EigenAdapter.h"

namespace Geometry {

class Line {
    Vector o_, d_;

public:
    Line(Vector &o, Vector &d) : o_(o), d_(d) {}

    Vector& getD() {
        return d_;
    }

    Vector& getO() {
        return o_;
    }
};

} // Geometry
