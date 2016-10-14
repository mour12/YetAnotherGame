#pragma once

#include "ray2d.hpp"

class Velocity
{
public:
  Velocity() = default;
  Velocity(Ray2D direction, float value);
  void ChangeVelocity();
private:
  Ray2D direction;
  float value;
};
