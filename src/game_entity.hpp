#pragma once

#include "box2d.hpp"
#include "direction2d.hpp"

class GameEntity
{
public:
  GameEntity() = default;
  GameEntity(GameEntity const & obj);
  GameEntity(Box2D const & box, Direction2D const & direction, float value);
  virtual ~GameEntity() {}
  void Update();

  virtual GameEntity & operator=(GameEntity const & obj);

  virtual bool operator==(GameEntity const & obj) const;
  virtual bool operator!=(GameEntity const & obj) const;

  virtual Point2D const & Сoordinates() const;

  void Update();

  Direction2D & direction();
  float & velocity();

  Box2D const & box() const;
  Direction2D const & direction() const;
  float const & velocity() const;

private:
  Box2D m_box;
  Direction2D m_direction;
  float m_velocity = 0.0f;
};
