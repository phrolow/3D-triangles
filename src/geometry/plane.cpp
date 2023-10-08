#include "plane.h"

using namespace Geometry;

Line& Plane::intersection(Plane &other) {
    Vector n1 = n_;
    Vector n2 = other.getN();

    double multiplier = n1[1]/n2[1];

    double d1 = d_;
    double d2 = other.getD();

    double x_o = NAN, y_o = NAN, z_o = 0;

    x_o = (multiplier * d2 - d1) / (n1[0] - multiplier * n2[0]);
    y_o = (-d1 - n1[0] * x_o) / n1[1];

    Vector o = Vector(x_o, y_o, z_o);
    Vector d = n1.cross(n2);

    Line *res = new Line(o, d);

    return *res;
}