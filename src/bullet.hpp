#pragma once

#include "game_entity.hpp"

class Bullet: public GameEntity
{
public:
  Bullet(Bullet const & obj);
  Bullet(Box2D const & box, Direction2D const & direction, float velocity, int health, std::weak_ptr<Space> const spacePtr);
  ~Bullet() override {}

  Bullet & operator=(Bullet const & obj);

  bool operator==(Bullet const & obj) const;
  bool operator!=(Bullet const & obj) const;
};

//std::ostream & operator << (std::ostream & os, Bullet const & obj);
