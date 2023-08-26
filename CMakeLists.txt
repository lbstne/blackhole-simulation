cmake_minimum_required(VERSION 3.22)
project(blackhole_simulation)

set(CMAKE_CXX_STANDARD 14)

add_executable(blackhole_simulation main.cpp Simulation.cpp Simulation.h MassObject.cpp MassObject.h Ray.cpp Ray.h vec3.cpp vec3.h)

target_link_libraries(blackhole_simulation)
