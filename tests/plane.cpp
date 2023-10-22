#include "config.h"

#include "../src/geometry/plane.h"

using namespace Geometry;

namespace {

class PlaneTest : public testing::Test {
protected:
    void SetUp() override {
        Vector p0{1, 0, 0};
        Vector p1{0, 1, 0};
        Vector p2{0, 0, 1};

        Plane plane0(p0, p1, p2);
    }

    void TearDown() override {
        delete p0;
        delete p1;
        delete p2;


    }
};

}