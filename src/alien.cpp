#include "alien.hpp"

Alien::Alien(Box2D const & box, Direction2D const & direction, float velocity, int health, Ray2D const & route, std::weak_ptr<Space> spacePtr)
  : GameEntity(box, direction, velocity, health, spacePtr), m_route(route)
{}

Alien::Alien(Alien const & obj)
  : GameEntity(obj.m_box, obj.m_direction, obj.m_velocity, obj.m_health, obj.m_spacePtr), m_route(obj.m_route)
{}

Alien & Alien::operator=(Alien const & obj)
{
  if (this == &obj) return *this;
  m_box = obj.m_box;
  m_direction = obj.m_direction;
  m_velocity = obj.m_velocity;
  m_health = obj.m_health;
  m_route = obj.m_route;
  m_spacePtr = obj.m_spacePtr;
  return *this;
}

bool Alien::operator==(Alien const & obj) const
{
  return static_cast<GameEntity>(*this) == static_cast<GameEntity>(obj) && m_route == obj.m_route;
}

bool Alien::operator!=(Alien const & obj) const
{
  return !operator==(obj);
}

Ray2D & Alien::route() { return m_route; }

Ray2D const & Alien::route() const { return m_route; }
