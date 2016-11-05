#pragma once

#include "factory_type.hpp"
#include "game_entity.hpp"
#include "ray2d.hpp"
#include "bullet.hpp"

class Alien : public GameEntity
{
public:
  Alien() = default;
  Alien(Alien const & obj);
  Alien(Alien const && obj);
  Alien(Box2D const & box, Direction2D const & direction, float velocity, int health, Ray2D const & route, std::weak_ptr<Space> const spacePrt);
  ~Alien() override {}
  void ToString(std::ostream & os) const override;

  FactoryType GetType() override;
  std::unique_ptr<GameEntity> Create() override;
  std::unique_ptr<GameEntity> Create(Box2D const & box, Direction2D const & direction, float velocity, int health, Ray2D const & route, std::weak_ptr<Space> const spacePtr) override;
  std::unique_ptr<GameEntity> Create(Box2D const & box, Direction2D const & direction, float velocity, int health, std::weak_ptr<Space> const spacePtr) override;
  std::unique_ptr<GameEntity> Create(Box2D const & box, int health, std::weak_ptr<Space> const spacePtr) override;

  Alien & operator=(Alien const & obj);

  bool operator==(Alien const & obj) const;
  bool operator!=(Alien const & obj) const;

  Ray2D & route();

  Ray2D const & route() const;

  void Shoot();

protected:
  Ray2D m_route;
};
