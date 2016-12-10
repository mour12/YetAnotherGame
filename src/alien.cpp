#include "alien.hpp"
#include "constant_manager.hpp"

#include <stdlib.h>

Direction2D Alien::m_alienDirection = Direction2D(-1.0f, 0.0f);
bool Alien::allMoveDown = false;

Alien::Alien(Box2D const & box, Direction2D const & direction, float velocity, int health, Ray2D const & route, std::weak_ptr<Space> const spacePtr)
  : GameEntity(box, direction, velocity, health, spacePtr), m_route(route)
{
  m_alienDirection = direction;
}

Alien::Alien(Alien const & obj)
  : GameEntity(obj), m_route(obj.m_route)
{
  m_alienDirection = obj.m_alienDirection;
}

Alien::Alien(Alien const && obj)
{
  m_box = std::move(obj.m_box);
  m_direction = std::move(obj.m_direction);
  m_alienDirection = std::move(obj.m_alienDirection);
  m_velocity = std::move(obj.m_velocity);
  m_health = std::move(obj.m_health);
  m_spacePtr = std::move(obj.m_spacePtr);
  m_route = std::move(obj.m_route);
}

Alien & Alien::operator=(Alien const & obj)
{
  if (this == &obj) return *this;
  m_box = obj.m_box;
  m_direction = obj.m_direction;
  m_alienDirection = obj.m_alienDirection;
  m_velocity = obj.m_velocity;
  m_health = obj.m_health;
  m_route = obj.m_route;
  m_spacePtr = obj.m_spacePtr;
  return *this;
}

bool Alien::operator==(Alien const & obj) const
{
  return *static_cast<GameEntity const *>(this) == *static_cast<GameEntity const *>(&obj) && m_route == obj.m_route;
}

bool Alien::operator!=(Alien const & obj) const
{
  return !operator==(obj);
}

Ray2D & Alien::route() { return m_route; }

Ray2D const & Alien::route() const { return m_route; }

void Alien::Shoot()
{
  ConstantManager & localConstantManager = ConstantManager::GetConstantManager();
  Point2D leftBottomCorner(m_box.Center().x() - localConstantManager.BulletSize() / 2, m_box.Center().y() - m_box.Height() / 2 - localConstantManager.BulletSize());
  Point2D rightTopCorner(m_box.Center().x() + localConstantManager.BulletSize() / 2, m_box.Center().y() - m_box.Height() / 2);
  Direction2D direction(0.0f, -1.0f);
  Box2D box(leftBottomCorner, rightTopCorner);
  auto bulletPtr = std::make_shared<Bullet>(box, direction, localConstantManager.BulletSpeed(), 1, m_spacePtr);
  m_spacePtr.lock()->AddGameEntity(bulletPtr);
}

FactoryType Alien::GetType()
{
  return FactoryType::AlienType;
}
std::unique_ptr<GameEntity> Alien::Create()
{
  return std::unique_ptr<GameEntity>(new Alien());
}
std::unique_ptr<GameEntity> Alien::Create(Box2D const & box, Direction2D const & direction, float velocity, int health, Ray2D const & route, std::weak_ptr<Space> const spacePtr)
{
  return std::unique_ptr<GameEntity>(new Alien(box, direction, velocity, health, route, spacePtr));
}
std::unique_ptr<GameEntity> Alien::Create(Box2D const & box, Direction2D const & direction, float velocity, int health, std::weak_ptr<Space> const spacePtr)
{
  throw std::logic_error("Not implemented in Alien class.");
}
std::unique_ptr<GameEntity> Alien::Create(Box2D const & box, int health, std::weak_ptr<Space> const spacePtr)
{
  throw std::logic_error("Not implemented in Alien class.");
}

void Alien::SetOnNotifiedHandler(TOnNotifiedHandler const & handler)
{
  m_onNotifiedHandler = handler;
}

void Alien::OnNotified(Observable const * obj)
{
  if (m_onNotifiedHandler != nullptr)
  {
    m_onNotifiedHandler(this, obj);
  }
}

void Alien::ToString(std::ostream & os) const
{
  os << "Alien {"
     << box() << ", "
     << Сoordinates() << ", "
     << route() << ", "
     << direction() << ", "
     << velocity() << ", "
     << health() << "}";
}

void Alien::Update()
{
  m_box.Move(m_velocity, m_alienDirection);
  if (m_box.leftBottomCorner().x() <= 0.0f)
  {
    allMoveDown = !allMoveDown;
    m_alienDirection = Direction2D(1.0f, 0.0f);
  }
  else if (m_box.rightTopCorner().x() >= 1.0f)
  {
    allMoveDown = !allMoveDown;
    m_alienDirection = Direction2D(-1.0f, 0.0f);
  }
  if (allMoveDown != moveDown)
  {
    m_box.Move(0.02f, Direction2D(0.0f, -1.0f));
    moveDown = allMoveDown;
  }
  if (m_box.leftBottomCorner().y() == 0.0f)
  {
    //
  }
  auto randomNumber =  std::rand() % 10000;
  if (randomNumber < 10)
  {
    Shoot();
  }
}
