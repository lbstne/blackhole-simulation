//
// Created by Luca Bastone on 2022-12-25.
//

#include "MassObject.h"

MassObject::MassObject(double mass, double radius, const std::array<unsigned short, 3> &color, double x, double y, double z) : mass(mass),
                                                                                               radius(radius),
                                                                                               color(color) {
    pos = vec3(x, y, z);
}

double MassObject::getMass() const {
    return mass;
}

double MassObject::getRadius() const {
    return radius;
}

const std::array<unsigned short, 3> &MassObject::getColor() const {
    return color;
}

const vec3 &MassObject::getPos() const {
    return pos;
}

void MassObject::setPos(const vec3 &pos) {
    MassObject::pos = pos;
}

bool MassObject::contains(const vec3 &point) {
    return (pos - point).norm() <= radius;
}