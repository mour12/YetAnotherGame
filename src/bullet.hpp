#pragma once

#include "game_enums.hpp"
#include "game_entity.hpp"
#include "gun.hpp"
#include "observable.hpp"

class Gun;

class Bullet: public GameEntity, public Observable
{
public:
  Bullet() = default;
  Bullet(Bullet const & obj);
  Bullet(Bullet const && obj);
  Bullet(Box2D const & box, Direction2D const & direction, float velocity, int health, std::weak_ptr<Space> const spacePtr);
  ~Bullet() override {}
  void ToString(std::ostream & os) const override;
  void Update() override;

  FactoryType GetType() override;
  std::unique_ptr<GameEntity> Create() override;
  std::unique_ptr<GameEntity> Create(Box2D const & box, Direction2D const & direction, float velocity, int health, Ray2D const & route, std::weak_ptr<Space> const spacePtr) override;
  std::unique_ptr<GameEntity> Create(Box2D const & box, Direction2D const & direction, float velocity, int health, std::weak_ptr<Space> const spacePtr) override;
  std::unique_ptr<GameEntity> Create(Box2D const & box, int health, std::weak_ptr<Space> const spacePtr) override;

  Bullet & operator=(Bullet const & obj);

  bool operator==(Bullet const & obj) const;
  bool operator!=(Bullet const & obj) const;
};
