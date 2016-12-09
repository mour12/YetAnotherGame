#include <exception>
#include <stdexcept>
#include <algorithm>
#include "bullet.hpp"

Bullet::Bullet(Bullet const & obj)
  : GameEntity(obj)
{}

Bullet::Bullet(Bullet const && obj)
  : GameEntity(obj)
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

FactoryType Bullet::GetType()
{
  return FactoryType::BulletType;
}
std::unique_ptr<GameEntity> Bullet::Create()
{
  return std::unique_ptr<GameEntity>(new Bullet());
}
std::unique_ptr<GameEntity> Bullet::Create(Box2D const & box, Direction2D const & direction, float velocity, int health, Ray2D const & route, std::weak_ptr<Space> const spacePtr)
{
  throw std::logic_error("Not implemented in Bullet class.");
}
std::unique_ptr<GameEntity> Bullet::Create(Box2D const & box, Direction2D const & direction, float velocity, int health, std::weak_ptr<Space> const spacePtr)
{
  return std::unique_ptr<GameEntity>(new Bullet(box, direction, velocity, health, spacePtr));
}
std::unique_ptr<GameEntity> Bullet::Create(Box2D const & box, int health, std::weak_ptr<Space> const spacePtr)
{
  throw std::logic_error("Not implemented in Bullet class.");
}

void Bullet::ToString(std::ostream & os) const
{
  os << "Bullet {"
     << box() << ", "
     << Сoordinates() << ", "
     << direction() << ", "
     << velocity() << ", "
     << health() << "}";
}

void Bullet::Update()
{
  m_box.Move(m_velocity, m_direction);
  Notify();
  if (m_box.leftBottomCorner().y() == 0.0f || m_box.rightTopCorner().y() == 1.0f)
  {
    m_health = 0;
  }
}
