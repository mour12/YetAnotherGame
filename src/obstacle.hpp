#pragma once

#include "game_entity.hpp"

class Obstacle: public GameEntity
{
public:
  Obstacle() = default;
  Obstacle(Obstacle const & obj);
  Obstacle(Box2D const & box, int health, std::weak_ptr<Space> const spacePtr);
  ~Obstacle() override {}

  Obstacle & operator=(Obstacle const & obj);

  bool operator==(Obstacle const & obj) const;
  bool operator!=(Obstacle const & obj) const;
};
