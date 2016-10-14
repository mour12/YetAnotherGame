#pragma once

#include "point2d.hpp"
#include "box2d.hpp"
#include "velocity.hpp"


class GameEntity
{
public:
  GameEntity() = default;
  virtual ~GameEntity() {}

private:
  Box2D box;
  Velocity velocity;
};
