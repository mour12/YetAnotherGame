#pragma once

#include "factory_type.hpp"
#include "game_entity.hpp"
#include "gun.hpp"

class Gun;

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
  std::unique_ptr<GameEntity> Create() override;
  std::unique_ptr<GameEntity> Create(Box2D const & box, Direction2D const & direction, float velocity, int health, Ray2D const & route, std::weak_ptr<Space> const spacePtr) override;
  std::unique_ptr<GameEntity> Create(Box2D const & box, Direction2D const & direction, float velocity, int health, std::weak_ptr<Space> const spacePtr) override;
  std::unique_ptr<GameEntity> Create(Box2D const & box, int health, std::weak_ptr<Space> const spacePtr) override;

  Bullet & operator=(Bullet const & obj);

  void AddGunObserver(std::weak_ptr<Gun> const gun);
  void RemoveGunObserver(std::weak_ptr<Gun> const gun);
  void Notify() const;

  bool operator==(Bullet const & obj) const;
  bool operator!=(Bullet const & obj) const;

private:
  std::vector<std::weak_ptr<Gun>> gunObservers;
};
