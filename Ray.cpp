//
// Created by Luca Bastone on 2022-12-25.
//

#include "Ray.h"

Ray::Ray(const vec3 &slope, const vec3 &pos) : slope(slope), pos(pos) {}

vec3 Ray::getPosAt(double t) const {
    return {pos.x + t*slope.x, pos.y + t*slope.y, pos.z + t*slope.z};
}

double Ray::getTforX(double x) {
    return (x - pos.x)/slope.x;
}
