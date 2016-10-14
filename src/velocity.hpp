#pragma once

#include "ray2d.hpp"
#include "direction2d.hpp"

class Velocity
{
public:
  Velocity() = default;
  Velocity(Ray2D direction, float value);
  void ChangeVelocity();
private:
  Direction2D direction;
  float value;
};
