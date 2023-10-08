#include "triangle.h"

using namespace Geometry;

bool Triangle::intersects(Triangle other) {
    std::vector<Vector> other_points = other.points;

    Plane pi2{other_points[0], other_points[1], other_points[2]};

    std::vector<int> distances; // now from triangle 1 to plane pi2

    for(int i = 0; i < 3; i++) {
        distances[i] = pi2.distance(points[i]);
    }

    if(distances[0] * distances[1] > 0
        && distances[1] * distances[2] > 0) {
        return false;   // all of the distances have the same sign
    }

    if(distances[0] == 0
        && distances[1] == 0
        && distances[2] == 0) {
        // co-planar case
        return false;
    }

    Plane pi1{points[0], points[1], points[2]};

    Line &intersection = pi1.intersection(pi2);

    if(distances[0] * distances[1] > 0)
        std::swap(points[1], points[2]);

    if(distances[2] * distances[1] > 0)
        std::swap(points[1], points[0]);

    // now both p1p2 and p1p0 cross line

    std::vector<double> proj;

    Vector& intersection_d = intersection.getD();
    Vector& intersection_o = intersection.getO();

    for(int i = 0; i < 3; i++) {
        proj[i] = intersection_d.dot(points[i] - intersection_o);   // pr^1_i = (D, p^1_i - O)
    }

    double&& t_1 = proj[0] + (proj[1] - proj[0]) *
            distances[0] / (distances[0] - distances[1]);

    double&& t_2 = proj[2] + (proj[1] - proj[2]) *
            distances[2] / (distances[2] - distances[1]);

    if(t_1 > t_2) std::swap(t_1, t_2);

    for(int i = 0; i < 3; i++) {                        // compute distances between vertices of triangle 2 and pi1
        distances[i] = pi1.distance(other_points[i]);
    }

    if(distances[0] * distances[1] > 0)
        std::swap(other_points[1], other_points[2]);

    if(distances[2] * distances[1] > 0)
        std::swap(other_points[1], other_points[0]);

    for(int i = 0; i < 3; i++) {
        proj[i] = intersection_d.dot(other_points[i] - intersection_o);
    }

    double&& t_3 = proj[0] + (proj[1] - proj[0]) *
           distances[0] / (distances[0] - distances[1]);

    double&& t_4 = proj[2] + (proj[1] - proj[2]) *
           distances[2] / (distances[2] - distances[1]);

    if(t_3 > t_4) std::swap(t_3, t_4);

    return fmax(t_1, t_3) <= fmin(t_2, t_4);
}