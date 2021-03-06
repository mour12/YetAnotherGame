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
  template <class... Args>
  std::unique_ptr<GameEntity> Create(FactoryType type, Args &&... args)
  {
    return m_templates[type]->Create(std::forward<Args>(args)...);
  }

private:
  using Templates = std::unordered_map<int, std::unique_ptr<GameEntity>>;
  Templates m_templates;
};

template<typename TDerived, typename TBase>
std::unique_ptr<TDerived> static_unique_ptr_cast(std::unique_ptr<TBase> && p)
{
  return std::unique_ptr<TDerived>(static_cast<TDerived *>(p.release()));
}
