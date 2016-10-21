#pragma once

#include "box2d.hpp"
#include "direction2d.hpp"
#include "space.hpp"
#include <memory>

class Space;

class GameEntity
{
public:
  GameEntity(GameEntity const & obj);
  GameEntity(Box2D const & box, Direction2D const & direction, float velocity, int health, std::weak_ptr<Space> const spacePtr);
  virtual ~GameEntity() {} // TODO: разобраться с чистым виртуальным деструктором

  GameEntity & operator=(GameEntity const & obj);

  bool operator==(GameEntity const & obj) const;
  bool operator!=(GameEntity const & obj) const;

  Point2D Сoordinates() const;

  virtual void Update() {};

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
