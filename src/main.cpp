#include <iostream>
#include "geometry/triangle.h"

using namespace std;

int main(int argc, char **argv) {
    size_t num_triangles = 0;

//    std::cin >> num_triangles;
//
//    for (int i = 0; i < num_triangles; ++i) {
//
//    }

    vector<Vector> points;

    for(int i = 0; i < 6; i++) {
        double x, y, z;

        cin >> x >> y >> z;

        points.emplace_back(x, y, z);
    }

    Triangle T1{points[0], points[1], points[2]};
    Triangle T2{points[3], points[4], points[5]};

    cout << T1.intersects(T2);

    return 0;
}