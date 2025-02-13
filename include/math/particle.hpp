#pragma once

#include "vec3.hpp"

using namespace Math;

class Particle {
protected:
  Vec3<float> position, velocity, acceleration;
  float damping;
};
