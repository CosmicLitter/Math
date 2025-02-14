#pragma once

#include "vec3.hpp"

namespace Math {


class Particle {
protected:
  Vec3<float> position, velocity, acceleration;
  float damping, inverse_mass;

  void integrate(float duration);
};

}
