#pragma once

#include "game_entity.hpp"
#include <unordered_map>
#include <memory>

class GameEntityFactory
{
public:
  GameEntityFactory() = default;
  bool Register(std::unique_ptr<GameEntity> && entity);
  void Unregister(std::unique_ptr<GameEntity> const & entity);
  std::unique_ptr<GameEntity> Create(FactoryType type);
  std::unique_ptr<GameEntity> Create(FactoryType type, Box2D const & box, Direction2D const & direction, float velocity, int health, Ray2D const & route, std::weak_ptr<Space> const spacePrt);
  std::unique_ptr<GameEntity> Create(FactoryType type, Box2D const & box, Direction2D const & direction, float velocity, int health, std::weak_ptr<Space> const spacePtr);
  std::unique_ptr<GameEntity> Create(FactoryType type, Box2D const & box, int health, std::weak_ptr<Space> const spacePtr);

private:
  using Templates = std::unordered_map<int, std::unique_ptr<GameEntity>>;
  Templates m_templates;
};

template<typename TDerived, typename TBase>
std::unique_ptr<TDerived> static_unique_ptr_cast(std::unique_ptr<TBase> && p)
{
  return std::unique_ptr<TDerived>(static_cast<TDerived *>(p.release()));
}
