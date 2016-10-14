#include <exception>
#include <stdexcept>
#include "game_entity.hpp"

GameEntity::GameEntity(GameEntity const & obj)
  : m_box(obj.m_box), m_direction(obj.m_direction), m_velocity(obj.m_velocity)
{}

GameEntity::GameEntity(Box2D const & box, Direction2D const & direction, float velocity)
  : m_box(box), m_direction(direction), m_velocity(velocity)
{}

GameEntity & GameEntity::operator=(GameEntity const & obj)
{
  if (this == &obj) return *this;
  m_box = obj.m_box;
  m_direction = obj.m_direction;
  m_velocity = obj.m_velocity;
  return *this;
}

bool GameEntity::operator==(GameEntity const & obj) const
{
  return m_box == obj.m_box && m_direction == obj.m_direction && m_velocity == obj.m_velocity;
}

bool GameEntity::operator!=(GameEntity const & obj) const
{
  return !operator==(obj);
}

Point2D const& GameEntity::Сoordinates() const
{
  return m_box.Center();
}

void GameEntity::Update()
{
  throw std::runtime_error("Not Implemented");
}

Direction2D & GameEntity::direction() { return m_direction; };
float & GameEntity::velocity() { return m_velocity; };

Box2D const & GameEntity::box() const { return m_box; }
Direction2D const & GameEntity::direction() const { return m_direction; };
float const & GameEntity::velocity() const { return  m_velocity; };
