#include <iostream>
#include "Simulation.h"

int main(int argc, char** argv) {

    for(int i = 0; i < 7; ++i) {
        Simulation sim({MassObject(1, 0.5, {0, 0, 0}, 30 - 5*i, 0, 0)}, "fallingin-frame" + std::to_string(i) + ".ppm");

        sim.run();
    }
}