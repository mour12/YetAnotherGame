#include <exception>
#include <stdexcept>
#include "obstacle.hpp"

Obstacle::Obstacle(Obstacle const & obj)
  : GameEntity(obj.m_box, obj.m_direction, obj.m_velocity, obj.m_health, obj.m_spacePtr)
{}

Obstacle::Obstacle(Box2D const & box, int health, std::weak_ptr<Space> spacePtr)
  : GameEntity(box, Direction2D(), 0, health, spacePtr)
{}

Obstacle & Obstacle::operator=(Obstacle const & obj)
{
    if (this == &obj) return *this;
    m_box = obj.m_box;
    m_direction = obj.m_direction;
    m_velocity = obj.m_velocity;
    m_health = obj.m_health;
    m_spacePtr = obj.m_spacePtr;
    return *this;
}

bool Obstacle::operator==(Obstacle const & obj) const
{
  return static_cast<GameEntity>(*this) == static_cast<GameEntity>(obj);
}

bool Obstacle::operator!=(Obstacle const & obj) const
{
  return !operator==(obj);
}
