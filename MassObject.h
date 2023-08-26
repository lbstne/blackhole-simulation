//
// Created by Luca Bastone on 2022-12-25.
//

#ifndef BLACKHOLE_SIMULATION_MASSOBJECT_H
#define BLACKHOLE_SIMULATION_MASSOBJECT_H

#include <vector>
#include <array>
#include <cmath>
#include "vec3.h"

class MassObject {
public:
    double getMass() const;
    double getRadius() const;
    const std::array<unsigned short, 3> &getColor() const;

private:
    vec3 pos = vec3(0, 0, 0);
    double mass;
    double radius;
public:
    const vec3 & getPos() const;

    void setPos(const vec3 &pos);

private:
    const std::array<unsigned short, 3> color;
public:
    MassObject(double mass, double radius, const std::array<unsigned short, 3> &color, double x, double y, double z);

    bool contains(const vec3 &point);
};


#endif //BLACKHOLE_SIMULATION_MASSOBJECT_H
