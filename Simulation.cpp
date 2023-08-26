//
// Created by Luca Bastone on 2022-12-25.
//

#include "Simulation.h"
#include <fstream>
#include <thread>
#include <utility>


Simulation::Simulation(std::vector<MassObject> objects, std::string export_file) : objects(std::move(objects)), file_name(std::move(export_file)) {}

Simulation::Simulation(std::vector<MassObject> objects, double stepSize, unsigned int resolution,
                       const std::array<double, 3> &cameraPos, double focalDist) : objects(std::move(objects)),
                                                                                   step_size(stepSize), resolution(resolution),
                                                                                   camera_pos(cameraPos),
                                                                                   focal_dist(focalDist) {
}

Ray Simulation::calculate_ray(unsigned int pixel_y, unsigned int pixel_z) {
    double a = focal_dist;
    double b = (float(resolution)/2 - float(pixel_y))/float(resolution);
    double c = (float(pixel_z) - float(resolution)/2)/float(resolution);

    return Ray(vec3(a,b,c).normalize(), camera_pos);
}

void Simulation::run() {
    std::ofstream file(file_name);

    std::vector<std::thread> threads;

    file << "P3\n" << resolution << " " << resolution << "\n" << 255 << "\n";

    for(int z = 1; z <= resolution; ++z) {
        for(int y = 1; y <= resolution; ++y) {

            cast_ray(y, z);
        }
    }

    for(int i = 0; i < threads.size(); ++i) {
        threads[i].join();
    }

    for(int z = 0; z < resolution; ++z) {
        for(int y = 0; y < resolution; ++y) {
            file << bitmap[z][y][0] << " " << bitmap[z][y][1] << " " << bitmap[z][y][2] << "\n";
        }
    }

}

void Simulation::cast_ray(int &y, int &z) {
    auto ray = calculate_ray(y, z);

    std::array<unsigned short, 3> pixel = {255, 255, 255};

    bool collided = false;

    for(double t = focal_dist; t <= max_ray_dist + focal_dist; t += step_size) {
        auto r_pos = ray.getPosAt(t);

        for(auto object : objects) {
            if(!collided && object.contains(r_pos)) {
                pixel = object.getColor();
                collided = true;

                break;
            }

            auto photon_to_obj = object.getPos() - r_pos;

            auto obj_to_cam = camera_pos - object.getPos();

            //if we are perpendicular to the CoM, then apply gravitational lens
            if(abs(photon_to_obj.norm() - (obj_to_cam.cross(ray.slope).norm()/ray.slope.norm())) < 0.001) {
                double angle = fmin(M_PI_2, (4 * GRAV_CONST * object.getMass())/photon_to_obj.norm());

                auto rotation_axis = ray.slope.cross(photon_to_obj).normalize();

                ray.slope = ray.slope*cos(angle) + rotation_axis.cross(ray.slope)*sin(angle) + rotation_axis*rotation_axis.dot(ray.slope)*(1-cos(angle));
                ray.pos = r_pos - ray.slope*t;
            }
        }
    }

    if(!collided) {
        auto r_pos = ray.getPosAt(ray.getTforX(50));

        auto calc_y = fmod(r_pos.y + 100, 10);
        auto calc_z = fmod(r_pos.z + 100, 10);

        if((calc_y < 5 && calc_z > 5) || (calc_y > 5 && calc_z < 5)) {
            pixel = {0, 0, 255};
        }
        else {
            pixel = {0, 255, 0};
        }
    }

    bitmap[z-1][y-1][0] = pixel[0];
    bitmap[z-1][y-1][1] = pixel[1];
    bitmap[z-1][y-1][2] = pixel[2];
}
