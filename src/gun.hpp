#pragma once

#include "factory_type.hpp"
#include "game_entity.hpp"
#include "ray2d.hpp"
#include "bullet.hpp"

class Bullet;

class Gun : public GameEntity
{
public:
  using TOnUpdateHandler = std::function<void(Bullet const * const)>;
  Gun() = default;
  Gun(Gun const & obj);
  Gun(Gun const && obj);
  Gun(Box2D const & box, Direction2D const & direction, float velocity, int health, std::weak_ptr<Space> const spacePrt);
  ~Gun() override {}
  void ToString(std::ostream & os) const override;

  FactoryType GetType() override;
  std::unique_ptr<GameEntity> Create() override;
  std::unique_ptr<GameEntity> Create(Box2D const & box, Direction2D const & direction, float velocity, int health, Ray2D const & route, std::weak_ptr<Space> const spacePtr) override;
  std::unique_ptr<GameEntity> Create(Box2D const & box, Direction2D const & direction, float velocity, int health, std::weak_ptr<Space> const spacePtr) override;
  std::unique_ptr<GameEntity> Create(Box2D const & box, int health, std::weak_ptr<Space> const spacePtr) override;

  Gun & operator=(Gun const & obj);

  bool operator==(Gun const & obj) const;
  bool operator!=(Gun const & obj) const;

  void SetUpdateHandler(TOnUpdateHandler const & handler);
  void Update() override;
  void Update(Bullet const * const bullet);
  void Shoot();

private:
  TOnUpdateHandler m_updateHandler;
};
