#pragma once

#include "box2d.hpp"
#include "direction2d.hpp"
#include "space.hpp"
#include <memory>

class Space;

class GameEntity
{
public:
  GameEntity() = default;
  GameEntity(GameEntity const & obj);
  GameEntity(Box2D const & box, Direction2D const & direction, float velocity, std::weak_ptr<Space> spacePtr);
  virtual ~GameEntity() {}

  GameEntity & operator=(GameEntity const & obj);

  bool operator==(GameEntity const & obj) const;
  bool operator!=(GameEntity const & obj) const;

  Point2D Сoordinates() const;

  virtual void Update();

  Direction2D & direction();
  float & velocity();

  std::weak_ptr<Space> const spacePtr() const;
  Box2D const & box() const;
  Direction2D const & direction() const;
  float const & velocity() const;

protected:
  std::weak_ptr<Space> m_spacePtr;
  Box2D m_box;
  Direction2D m_direction;
  float m_velocity = 0.0f;
};
