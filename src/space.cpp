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
  for (int i = 0; i < m_gameEntities.size(); ++i)
  {
    m_gameEntities[i]->Update();
  }

  for (int i = 0; i < m_gameEntities.size(); ++i)
  {
    if (m_gameEntities[i]->GetType() == FactoryType::BulletType && m_gameEntities[i]->health() > 0)
    {
      for (int j = 0; j < m_gameEntities.size(); ++j)
      {
        if (i != j && m_gameEntities[i]->box().Intersects(m_gameEntities[j]->box()))
        {
          m_gameEntities[i]->health() = 0;
          m_gameEntities[j]->health()--;
          break;
        }
      }
    }
  }

  for (auto it = m_gameEntities.begin(); it != m_gameEntities.end(); )
  {
    if ((*it)->health() <= 0)
    {
      it = m_gameEntities.erase(it);
    }
    else
    {
      ++it;
    }
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

