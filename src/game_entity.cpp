#include "game_entity.hpp"

GameEntity::GameEntity(GameEntity const & obj)
  : m_box(obj.m_box), m_velocity(obj.m_velocity)
{}

GameEntity::GameEntity(Box2D const & box, Velocity const & velocity)
  : m_box(box), m_velocity(velocity)
{}

GameEntity & GameEntity::operator=(GameEntity const & obj)
{
  if (this == &obj) return *this;
  m_box = obj.m_box;
  m_velocity = obj.m_velocity;
  return *this;
}

bool GameEntity::operator==(GameEntity const & obj) const
{
  return m_box == obj.m_box && m_velocity == obj.m_velocity;
}

bool GameEntity::operator!=(GameEntity const & obj) const
{
  return !operator==(obj);
}

Point2D const& GameEntity::Сoordinates() const
{
  return m_box.Center();
}

Velocity & GameEntity::velocity() { return m_velocity; }

Box2D const & GameEntity::box() const { return m_box; }

Velocity const & GameEntity::velocity() const { return m_velocity; }