#pragma once

#include <vector>

namespace Geometry {

class Vector {
    std::vector<int> base;

public:
    double x_, y_, z_;

    Vector(double x = 0, double y = 0, double z = 0) : x_(x), y_(y), z_(z) {};

    Vector& operator-() {
        x_ = -x_; y_ = -y_; z_ = -z_;
        return *this;
    }

    Vector& operator+=(const Vector& rhs) {
        x_ += rhs.x_; y_ += rhs.y_; z_ += rhs.z_;
        return *this;
    }

    Vector& operator-=(const Vector& rhs) {
        x_ -= rhs.x_; y_ -= rhs.y_; z_ -= rhs.z_;
        return *this;
    }

    double operator*(const Vector& rhs) const {
        return x_ * rhs.x_ + y_ * rhs.y_ + z_ * rhs.z_;
    }

    double length() const {
        return sqrt(x_ * x_ + y_ * y_ + z_ * z_);
    }

    Vector normalized() const {
        return Vector(x_ / this->length() , y_ / this->length(), z_ / this->length());
    }

    Vector projection_on(const Vector& vec) const;

    double& operator[](int ort) {
        switch (ort) {
            case Ort::x: return this->x_; break;
            case Ort::y: return this->y_; break;
            case Ort::z: return this->z_; break;
            default: throw std::invalid_argument("invalid_argument = " + std::to_string(ort));
        }
    }

    const double& operator[](int ort) const {
        switch (ort) {
            case Ort::x: return this->x_; break;
            case Ort::y: return this->y_; break;
            case Ort::z: return this->z_; break;
            default: throw std::invalid_argument("invalid_argument = " + std::to_string(ort));
        }
    }
};

} // Geometry