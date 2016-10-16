#include "gun.hpp"

Gun::Gun(Box2D const & box, Direction2D const & direction, float velocity, int health, std::weak_ptr<Space> spacePtr)
  : GameEntity(box, direction, velocity, health, spacePtr)
{}

Gun::Gun(Gun const & obj)
  : GameEntity(obj.m_box, obj.m_direction, obj.m_velocity, obj.m_health, obj.m_spacePtr)
{}

Gun & Gun::operator=(Gun const & obj)
{
  if (this == &obj) return *this;
  m_box = obj.m_box;
  m_direction = obj.m_direction;
  m_velocity = obj.m_velocity;
  m_health = obj.m_health;
  m_spacePtr = obj.m_spacePtr;
  return *this;
}

bool Gun::operator==(Gun const & obj) const
{
  return static_cast<GameEntity>(*this) == static_cast<GameEntity>(obj);
}

bool Gun::operator!=(Gun const & obj) const
{
  return !operator==(obj);
}
