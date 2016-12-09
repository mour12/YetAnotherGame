#pragma once

#include "game_enums.hpp"
#include "box2d.hpp"
#include "ray2d.hpp"
#include "direction2d.hpp"
#include "space.hpp"
#include "observer.hpp"
#include <memory>

class Space;

class GameEntity: public Observer
{
public:
  using TOnNotifiedHandler = std::function<void(Observer *, Observable const *)>;
  GameEntity() = default;
  GameEntity(GameEntity const & obj);
  GameEntity(GameEntity const && obj);
  GameEntity(Box2D const & box, Direction2D const & direction, float velocity, int health, std::weak_ptr<Space> const spacePtr);
  virtual ~GameEntity() {}

  bool operator==(GameEntity const & obj) const;
  bool operator!=(GameEntity const & obj) const;

  Point2D Сoordinates() const;

  virtual FactoryType GetType() = 0;
  virtual std::unique_ptr<GameEntity> Create() = 0;
  virtual std::unique_ptr<GameEntity> Create(Box2D const & box, Direction2D const & direction, float velocity, int health, Ray2D const & route, std::weak_ptr<Space> const spacePtr) = 0;
  virtual std::unique_ptr<GameEntity> Create(Box2D const & box, Direction2D const & direction, float velocity, int health, std::weak_ptr<Space> const spacePtr) = 0;
  virtual std::unique_ptr<GameEntity> Create(Box2D const & box, int health, std::weak_ptr<Space> const spacePtr) = 0;


  virtual void Update() {}
  virtual void ToString(std::ostream & os) const = 0;

  Direction2D & direction();
  float & velocity();
  int & health();

  std::weak_ptr<Space> const spacePtr() const;
  Box2D const & box() const;
  Direction2D const & direction() const;
  float const & velocity() const;
  int const & health()  const;

  void SetOnNotifiedHandler(TOnNotifiedHandler const & handler);
  virtual void OnNotified(Observable const * obj) override;

protected:
  TOnNotifiedHandler m_onNotifiedHandler;
  std::weak_ptr<Space> m_spacePtr;
  Box2D m_box;
  Direction2D m_direction;
  float m_velocity = 0.0f;
  int m_health = 1;
};

std::ostream & operator << (std::ostream & os, GameEntity const & obj);
