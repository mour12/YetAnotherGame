#pragma once

#include "box2d.hpp"
#include "direction2d.hpp"
#include "space.hpp"
#include <memory>

class Space;

class GameEntity
{
public:
  GameEntity(GameEntity const & obj) = delete;
  GameEntity(GameEntity && obj) = delete;
  GameEntity(Box2D const & box, Direction2D const & direction, float velocity, int health, std::weak_ptr<Space> const spacePtr);
  virtual ~GameEntity() {} // TODO: разобраться с чистым виртуальным деструктором

  bool operator==(GameEntity const & obj) const;
  bool operator!=(GameEntity const & obj) const;

  Point2D Сoordinates() const;

  virtual void Update() {}
  virtual void ToString(std::ostream & os) const = 0;

  Direction2D & direction();
  float & velocity();
  int & health();

  std::weak_ptr<Space> const spacePtr() const;
  Box2D const & box() const;
  Direction2D const & direction() const;
  float const & velocity() const;
  int const & health()  const;

protected:
  std::weak_ptr<Space> m_spacePtr;
  Box2D m_box;
  Direction2D m_direction;
  float m_velocity = 0.0f;
  int m_health = 1;
};

std::ostream & operator << (std::ostream & os, GameEntity const & obj);
