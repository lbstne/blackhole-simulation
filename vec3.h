//
// Created by Luca Bastone on 2022-12-25.
//

#ifndef BLACKHOLE_SIMULATION_VEC3_H
#define BLACKHOLE_SIMULATION_VEC3_H

#include <array>

class vec3 {
public:
    double x, y, z;

    vec3(double x, double y, double z);
    vec3(std::array<double, 3> comp);

    std::array<double, 3> comp();

    bool operator==(const vec3 &rhs) const;
    bool operator!=(const vec3 &rhs) const;

    vec3 operator+(const vec3 &rhs) const;
    vec3 operator-(const vec3 &rhs) const;

    vec3 operator*(double scalar) const;

    vec3 cross(const vec3 &rhs) const;
    double dot(const vec3 &rhs) const;

    double norm() const;

    vec3 &normalize();

};


#endif //BLACKHOLE_SIMULATION_VEC3_H
