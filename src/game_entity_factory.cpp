#include "game_entity_factory.hpp"

bool GameEntityFactory::Register(std::unique_ptr<GameEntity> && entity)
{
  if (m_templates.find(entity->GetType()) != m_templates.end())
    return false;
  m_templates[entity->GetType()] = std::move(entity);
  return true;
}
void GameEntityFactory::Unregister(std::unique_ptr<GameEntity> const & entity)
{
  m_templates[entity->GetType()] = nullptr;
}
std::unique_ptr<GameEntity> GameEntityFactory::Create(FactoryType type)
{
  if (m_templates.find(type) == m_templates.end())
    return nullptr;
  return m_templates[type]->Create();
}
std::unique_ptr<GameEntity> GameEntityFactory::Create(FactoryType type, Box2D const & box, Direction2D const & direction, float velocity, int health, Ray2D const & route, std::weak_ptr<Space> const spacePtr)
{
  if (m_templates.find(type) == m_templates.end())
    return nullptr;
  return m_templates[type]->Create(box, direction, velocity, health, route, spacePtr);
}
std::unique_ptr<GameEntity> GameEntityFactory::Create(FactoryType type, Box2D const & box, Direction2D const & direction, float velocity, int health, std::weak_ptr<Space> const spacePtr)
{
  if (m_templates.find(type) == m_templates.end())
    return nullptr;
  return m_templates[type]->Create(box, direction, velocity, health, spacePtr);
}
std::unique_ptr<GameEntity> GameEntityFactory::Create(FactoryType type, Box2D const & box, int health, std::weak_ptr<Space> const spacePtr)
{
  if (m_templates.find(type) == m_templates.end())
    return nullptr;
  return m_templates[type]->Create(box, health, spacePtr);
}
