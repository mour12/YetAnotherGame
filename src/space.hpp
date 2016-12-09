#pragma once

#include "game_entity.hpp"
#include <vector>
#include <memory>

class GameEntity;

class Space final
{
public:
  Space() = default;
  Space(float sizeX, float sizeY);
  ~Space() {}

  void Update();

  float const & sizeX() const;
  float const & sizeY() const;

  std::vector<std::shared_ptr<GameEntity>> const & gameEntities() const;
  void PrintGameEntities(std::ostream & os) const;

  void AddGameEntity(std::shared_ptr<GameEntity> gameEntityPtr);

private:
  float m_sizeX = 0.0f;
  float m_sizeY = 0.0f;
  std::vector<std::shared_ptr<GameEntity>> m_gameEntities;
};

std::ostream & operator << (std::ostream & os, Space const & obj);
