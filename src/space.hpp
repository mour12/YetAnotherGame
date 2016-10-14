#pragma once

#include "game_entity.hpp"
#include <vector>

class Space
{
public:
  Space() = default;
  Space(float sizeX, float sizeY);
  void update();
private:
  float m_sixeX;
  float m_sixeY;
  std::vector<GameEntity *> m_gameEntities;
};
