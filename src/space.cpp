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
    gameEntity->Update();
  }
}

void Space::AddGameEntity(std::shared_ptr<GameEntity> gameEntityPtr)
{
  if (gameEntityPtr == nullptr) throw std::invalid_argument("Trying to add nullptr!");
  m_gameEntities.push_back(gameEntityPtr);
}

void Space::PrintGameEntities(std::ostream & os) const
{
  os << "GameEntities {";
  for (auto const & obj : this->m_gameEntities)
  {
    os << *obj << ", ";
  }
  os << "}";
}

std::ostream & operator << (std::ostream & os, Space const & obj)
{
  os << "Space {" << obj.sizeX() << ", " << obj.sizeY() << ", ";
  obj.PrintGameEntities(os);
  os << "}";
  return os;
}

