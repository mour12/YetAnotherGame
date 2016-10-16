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

Bullet Alien::Shoot() // TODO: Вынести размеры, скорость и хп пули
{
  Point2D leftBottomCorner(m_route.origin().x() - 3, m_route.origin().y() - 3);
  Point2D rightTopCorner(m_route.origin().x() + 3, m_route.origin().y() + 3);
  Direction2D direction(0.0f, 1.0f);
  Box2D box(leftBottomCorner, rightTopCorner);
  auto bulletPtr = std::make_shared<Bullet>(box, direction, 10, 1, m_spacePtr);
  m_spacePtr.lock()->gameEntities().push_back(bulletPtr);
}
