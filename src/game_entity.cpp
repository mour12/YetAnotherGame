#include <exception>
#include <stdexcept>
#include "game_entity.hpp"

GameEntity::GameEntity(GameEntity const & obj)
  : m_box(obj.m_box), m_direction(obj.m_direction), m_velocity(obj.m_velocity), m_health(obj.m_health), m_spacePtr(obj.m_spacePtr)
{}

GameEntity::GameEntity(Box2D const & box, Direction2D const & direction, float velocity, int health, std::weak_ptr<Space> const spacePtr)
  : m_box(box), m_direction(direction), m_velocity(velocity), m_health(health), m_spacePtr(spacePtr)
{}

GameEntity & GameEntity::operator=(GameEntity const & obj)
{
  if (this == &obj) return *this;
  m_box = obj.m_box;
  m_direction = obj.m_direction;
  m_velocity = obj.m_velocity;
  m_health = obj.m_health;
  m_spacePtr = obj.m_spacePtr;
  return *this;
}

bool GameEntity::operator==(GameEntity const & obj) const
{
  return (m_box == obj.m_box)
      && (m_direction == obj.m_direction)
      && (m_velocity == obj.m_velocity)
      && (m_health == obj.m_health)
      && (m_spacePtr.lock() == obj.m_spacePtr.lock());
}

bool GameEntity::operator!=(GameEntity const & obj) const
{
  return !operator==(obj);
}

Point2D GameEntity::Сoordinates() const
{
  return m_box.Center();
}

Direction2D & GameEntity::direction() { return m_direction; }
float & GameEntity::velocity() { return m_velocity; }
int & GameEntity::health() { return m_health; }

std::weak_ptr<Space> const GameEntity::spacePtr() const { return m_spacePtr; }
Box2D const & GameEntity::box() const { return m_box; }
Direction2D const & GameEntity::direction() const { return m_direction; }
float const & GameEntity::velocity() const { return  m_velocity; }
int const & GameEntity::health() const { return m_health; }

std::ostream & operator << (std::ostream & os, GameEntity const & obj)
{
  obj.serialize(os);
  return os;
}
