#pragma once

#include "point2d.hpp"
#include "box2d.hpp"
#include "ray2d.hpp"

class GameEntity
{
public:
  GameEntity() = default;
  virtual ~GameEntity() {}

private:
  Box2D box;
};
