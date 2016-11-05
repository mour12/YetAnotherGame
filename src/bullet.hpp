#pragma once

#include "factory_type.hpp"
#include "game_entity.hpp"

class Bullet: public GameEntity
{
public:
  Bullet() = default;
  Bullet(Bullet const & obj);
  Bullet(Bullet const && obj);
  Bullet(Box2D const & box, Direction2D const & direction, float velocity, int health, std::weak_ptr<Space> const spacePtr);
  ~Bullet() override {}
  void ToString(std::ostream & os) const override;

  FactoryType GetType() override;
  std::unique_ptr<GameEntity> Create(Box2D const & box, Direction2D const & direction, float velocity, int health, std::weak_ptr<Space> const spacePrt) override;
  std::unique_ptr<GameEntity> Create() override;

  Bullet & operator=(Bullet const & obj);

  bool operator==(Bullet const & obj) const;
  bool operator!=(Bullet const & obj) const;
};
