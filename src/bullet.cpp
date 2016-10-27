#include <exception>
#include <stdexcept>
#include "bullet.hpp"

Bullet::Bullet(Bullet const & obj)
  : GameEntity(obj.m_box, obj.m_direction, obj.m_velocity, obj.m_health, obj.m_spacePtr)
{}

Bullet::Bullet(Box2D const & box, Direction2D const & direction, float velocity, int health, std::weak_ptr<Space> const spacePtr)
  : GameEntity(box, direction, velocity, health, spacePtr)
{}

Bullet & Bullet::operator=(Bullet const & obj)
{
    if (this == &obj) return *this;
    m_box = obj.m_box;
    m_direction = obj.m_direction;
    m_velocity = obj.m_velocity;
    m_health = obj.m_health;
    m_spacePtr = obj.m_spacePtr;
    return *this;
}

bool Bullet::operator==(Bullet const & obj) const
{
  return *static_cast<GameEntity const *>(this) == *static_cast<GameEntity const *>(&obj);
}

bool Bullet::operator!=(Bullet const & obj) const
{
  return !operator==(obj);
}

void Bullet::ToString (std::ostream & os) const
{
  os << "Bullet {"
     << this->Bullet::box() << ", "
     << this->Bullet::Сoordinates() << ", "
     << this->Bullet::direction() << ", "
     << this->Bullet::velocity() << ", "
     << this->Bullet::health() << "}";
}
