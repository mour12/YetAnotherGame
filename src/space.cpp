#include "space.hpp"

Space::Space(float sizeX, float sizeY) :
  m_sizeX(sizeX),
  m_sizeY(sizeY)
{}

Space::~Space()
{
  if (m_gameEntities.size() != 0)
  {
    for (auto gameEntity: m_gameEntities)
    {
      gameEntity->~GameEntity();
    }
  }
}

float const & Space::sizeX() const
{
  return m_sizeX;
}
float const & Space::sizeY() const
{
  return m_sizeY;
}

std::vector<std::shared_ptr<GameEntity>> const & Space::gameEntities() const
{
  return m_gameEntities;
}
std::vector<std::shared_ptr<GameEntity>> & Space::gameEntities()
{
  return m_gameEntities;
}

void Space::Update()
{
  if (m_gameEntities.size() != 0)
  {
    for (auto gameEntity: m_gameEntities)
    {
      gameEntity->Update();
    }
  }
  else
  {
    //
  }
}
