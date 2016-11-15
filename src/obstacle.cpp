#include <exception>
#include <stdexcept>
#include "obstacle.hpp"

Obstacle::Obstacle(Obstacle const & obj)
  : GameEntity(obj)
{}

Obstacle::Obstacle(Obstacle const &&obj)
  : GameEntity(obj)
{}

Obstacle::Obstacle(Box2D const & box, int health, std::weak_ptr<Space> const spacePtr)
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
  return *static_cast<GameEntity const *>(this) == *static_cast<GameEntity const *>(&obj);
}

bool Obstacle::operator!=(Obstacle const & obj) const
{
  return !operator==(obj);
}

FactoryType Obstacle::GetType()
{
  return FactoryType::ObstacleType;
}
//std::unique_ptr<GameEntity> Obstacle::Create()
//{
//  return std::unique_ptr<GameEntity>(new Obstacle());
//}
//std::unique_ptr<GameEntity> Obstacle::Create(Box2D const & box, Direction2D const & direction, float velocity, int health, Ray2D const & route, std::weak_ptr<Space> const spacePtr)
//{
//  throw std::logic_error("Not implemented in Obstacle class.");
//}
//std::unique_ptr<GameEntity> Obstacle::Create(Box2D const & box, Direction2D const & direction, float velocity, int health, std::weak_ptr<Space> const spacePtr)
//{
//  throw std::logic_error("Not implemented in Obstacle class.");
//}
//std::unique_ptr<GameEntity> Obstacle::Create(Box2D const & box, int health, std::weak_ptr<Space> const spacePtr)
//{
//  return std::unique_ptr<GameEntity>(new Obstacle(box, health, spacePtr));
//}

void Obstacle::ToString(std::ostream & os) const
{
  os << "Obstacle {"
     << box() << ", "
     << Сoordinates() << ", "
     << health() << "}";
}
