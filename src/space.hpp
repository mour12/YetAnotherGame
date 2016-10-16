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
  ~Space();

  void Update();//Not implemented on GameEntity side

  float const & sizeX() const;
  float const & sizeY() const;

  std::vector<std::shared_ptr<GameEntity>> const & gameEntities() const;
  std::vector<std::shared_ptr<GameEntity>> & gameEntities();

private:
  float m_sizeX = 0.0f;
  float m_sizeY = 0.0f;
  std::vector<std::shared_ptr<GameEntity>> m_gameEntities;
};
