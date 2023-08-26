//
// Created by Luca Bastone on 2022-12-25.
//

#include <cmath>
#include "vec3.h"

vec3::vec3(double x, double y, double z) : x(x), y(y), z(z) {}

vec3::vec3(std::array<double, 3> comp) {
    x = comp[0];
    y = comp[1];
    z = comp[2];

}

std::array<double, 3> vec3::comp() {
    return {x, y, z};
}

bool vec3::operator==(const vec3 &rhs) const {
    return x == rhs.x &&
           y == rhs.y &&
           z == rhs.z;
}

bool vec3::operator!=(const vec3 &rhs) const {
    return !(rhs == *this);
}

vec3 vec3::operator+(const vec3 &rhs) const {
    return vec3(this->x + rhs.x, this->y + rhs.y, this->z + rhs.z);
}

vec3 vec3::operator-(const vec3 &rhs) const {
    return vec3(this->x - rhs.x, this->y - rhs.y, this->z - rhs.z);
}

vec3 vec3::operator*(double scalar) const {
    return vec3(x * scalar, y * scalar, z * scalar);
}

vec3 vec3::cross(const vec3 &rhs) const {
    return vec3(y*rhs.z - z*rhs.y, z*rhs.x - x*rhs.z, x*rhs.y - y*rhs.x);
}

double vec3::dot(const vec3 &rhs) const {
    return x*rhs.x + y*rhs.y + z*rhs.z;
}

double vec3::norm() const {
    return sqrt(x*x + y*y + z*z);
}

vec3 & vec3::normalize() {
    double mag = norm();

    x /= mag;
    y /= mag;
    z /= mag;

    return *this;
}

vec3 operator * (double scalar, const vec3 &rhs) {
    return rhs * scalar;
}
