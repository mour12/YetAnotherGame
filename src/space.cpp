#include "space.hpp"

Space::Space(float sizeX, float sizeY) :
  m_sizeX(sizeX),
  m_sizeY(sizeY)
{}

float const & Space::sizeX() const { return m_sizeX;}
float const & Space::sizeY() const { return m_sizeY;}

std::vector<std::shared_ptr<GameEntity>> const & Space::gameEntities() const
{
  return m_gameEntities;
}

void Space::Update()
{
  if (m_gameEntities.empty()) return;
  for (auto & gameEntity: m_gameEntities)
  {
    gameEntity->Update(); //Not implemented on GameEntity side
  }
}

void Space::AddGameEntity(std::shared_ptr<GameEntity> gameEntityPtr)
{
  if (gameEntityPtr != nullptr) // TODO: сделать выброс исключения при nullptr
  {
    m_gameEntities.push_back(gameEntityPtr);
  }
}
