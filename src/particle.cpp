#include <assert.h>
#include <cmath>
#include <math/particle.hpp>

using namespace Math;

void Particle::integrate(float duration) {
  if (inverse_mass == 0) return;
  assert(duration > 0);
  position.addScaledVector(velocity, duration);
  
  Vec3<float> acceleration_result = acceleration;
  velocity.addScaledVector(acceleration_result, duration);
  velocity *= powf(damping, duration);
}
