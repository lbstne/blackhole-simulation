//
// Created by Luca Bastone on 2022-12-25.
//

#ifndef BLACKHOLE_SIMULATION_SIMULATION_H
#define BLACKHOLE_SIMULATION_SIMULATION_H

#include <vector>
#include <array>
#include <cmath>
#include <iostream>
#include <string>

#include "MassObject.h"
#include "Ray.h"

class Simulation {
private:
    int max_ray_dist = 50;
    std::vector<MassObject> objects;
    double step_size = 0.05;
    int resolution = 500;
    vec3 camera_pos  = {0, 0, 0};
    double focal_dist = 0.5;
    std::string file_name;

    //TODO: make dynamic
    unsigned short bitmap[500][500][3];

    Ray calculate_ray(unsigned int pixel_x, unsigned int pixel_y);

    void cast_ray(int &y, int &z);

public:
    const double GRAV_CONST = 2;

    static double mag(std::array<double, 3> vec3) {
        return sqrt( pow(vec3[0], 2) + pow(vec3[1], 2) + pow(vec3[2], 2) );
    }

    Simulation(std::vector<MassObject> objects, double stepSize, unsigned int resolution,
               const std::array<double, 3> &cameraPos, double focalDist);

    explicit Simulation(std::vector<MassObject> objects, std::string export_file);

    void run();
};


#endif //BLACKHOLE_SIMULATION_SIMULATION_H
