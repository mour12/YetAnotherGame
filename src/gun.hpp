#pragma once

#include "factory_type.hpp"
#include "game_entity.hpp"
#include "ray2d.hpp"
#include "bullet.hpp"
#include "observer.hpp"

class Bullet;

class Gun : public GameEntity, public Observer
{
public:
  using TOnNotifiedHandler = std::function<void(Observable const *)>;
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

  void SetOnNotifiedHandler(TOnNotifiedHandler const & handler);
  void OnNotified(Observable const * obj) override;
  void Shoot();

private:
  TOnNotifiedHandler m_onNotifiedHandler;
};
