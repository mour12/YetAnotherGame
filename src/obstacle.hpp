#pragma once

#include "factory_type.hpp"
#include "game_entity.hpp"

class Obstacle: public GameEntity
{
public:
  Obstacle() = default;
  Obstacle(Obstacle const &obj);
  Obstacle(Obstacle const && obj);
  Obstacle(Box2D const & box, int health, std::weak_ptr<Space> const spacePtr);
  ~Obstacle() override {}

  FactoryType GetType() override;
  std::unique_ptr<GameEntity> Create() override;
  std::unique_ptr<GameEntity> Create(Box2D const & box, Direction2D const & direction, float velocity, int health, Ray2D const & route, std::weak_ptr<Space> const spacePtr) override;
  std::unique_ptr<GameEntity> Create(Box2D const & box, Direction2D const & direction, float velocity, int health, std::weak_ptr<Space> const spacePtr) override;
  std::unique_ptr<GameEntity> Create(Box2D const & box, int health, std::weak_ptr<Space> const spacePtr) override;

  void ToString(std::ostream & os) const override;

  Obstacle & operator=(Obstacle const & obj);

  bool operator==(Obstacle const & obj) const;
  bool operator!=(Obstacle const & obj) const;
};
