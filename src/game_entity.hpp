#pragma once

#include "point2d.hpp"
#include "box2d.hpp"
#include "velocity.hpp"

class GameEntity
{
public:
  GameEntity() = default;
  GameEntity(GameEntity const & obj);
  GameEntity(Box2D const & box, Velocity const & velocity);
  virtual ~GameEntity() {}

  virtual GameEntity & operator=(GameEntity const & obj);

  virtual bool operator==(GameEntity const & obj) const;
  virtual bool operator!=(GameEntity const & obj) const;

  virtual Point2D const & Сoordinates() const;

  Velocity & velocity();

  Box2D const & box() const;
  Velocity const & velocity() const;

private:
  Box2D m_box;
  Velocity m_velocity;
};
