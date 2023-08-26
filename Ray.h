//
// Created by Luca Bastone on 2022-12-25.
//

#ifndef BLACKHOLE_SIMULATION_RAY_H
#define BLACKHOLE_SIMULATION_RAY_H

#include <array>
#include "vec3.h"

class Ray {
public:
    Ray(const vec3 &slope, const vec3 &pos);
    vec3 getPosAt(double t) const;

    double getTforX(double x);
    vec3 slope;
    vec3 pos;
};

#endif //BLACKHOLE_SIMULATION_RAY_H
