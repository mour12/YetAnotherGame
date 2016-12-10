#include "gun.hpp"

Gun::Gun(Box2D const & box, Direction2D const & direction, float velocity, int health, std::weak_ptr<Space> const spacePtr)
  : GameEntity(box, direction, velocity, health, spacePtr)
{}

Gun::Gun(Gun const & obj)
  : GameEntity(obj)
{}

Gun::Gun(Gun const && obj)
  : GameEntity(obj)
{}

Gun & Gun::operator=(Gun const & obj)
{
  if (this == &obj) return *this;
  m_box = obj.m_box;
  m_direction = obj.m_direction;
  m_velocity = obj.m_velocity;
  m_health = obj.m_health;
  m_spacePtr = obj.m_spacePtr;
  return *this;
}

bool Gun::operator==(Gun const & obj) const
{
  return *static_cast<GameEntity const *>(this) == *static_cast<GameEntity const *>(&obj);
}

bool Gun::operator!=(Gun const & obj) const
{
  return !operator==(obj);
}

FactoryType Gun::GetType()
{
  return FactoryType::GunType;
}
std::unique_ptr<GameEntity> Gun::Create()
{
  return std::unique_ptr<GameEntity>(new Gun());
}
std::unique_ptr<GameEntity> Gun::Create(Box2D const & box, Direction2D const & direction, float velocity, int health, Ray2D const & route, std::weak_ptr<Space> const spacePtr)
{
  throw std::logic_error("Not implemented in Gun class.");
}
std::unique_ptr<GameEntity> Gun::Create(Box2D const & box, Direction2D const & direction, float velocity, int health, std::weak_ptr<Space> const spacePtr)
{
  return std::unique_ptr<GameEntity>(new Gun(box, direction, velocity, health, spacePtr));
}
std::unique_ptr<GameEntity> Gun::Create(Box2D const & box, int health, std::weak_ptr<Space> const spacePtr)
{
  throw std::logic_error("Not implemented in Gun class.");
}

void Gun::SetOnNotifiedHandler(TOnNotifiedHandler const & handler)
{
  m_onNotifiedHandler = handler;
}

void Gun::OnNotified(Observable const * obj)
{
  if (m_onNotifiedHandler != nullptr)
  {
    m_onNotifiedHandler(this, obj);
  }
}

void Gun::Shoot() // TODO: Вынести размеры, скорость и хп пули
{
  Point2D leftBottomCorner(m_box.leftBottomCorner().x() + m_box.Width() / 2 - 3, m_box.rightTopCorner().y());
  Point2D rightTopCorner(m_box.leftBottomCorner().x() + m_box.Width() / 2  + 3, m_box.rightTopCorner().y() + 6);
  Direction2D direction(0.0f, 1.0f);
  Box2D box(leftBottomCorner, rightTopCorner);
  auto bulletPtr = std::make_shared<Bullet>(box, direction, 10.0f, 1, m_spacePtr);
  m_spacePtr.lock()->AddGameEntity(bulletPtr);
}

void Gun::ToString(std::ostream & os) const
{
  os << "Gun {"
     << box() << ", "
     << Сoordinates() << ", "
     << direction() << ", "
     << velocity() << ", "
     << health() << "}";
}

void Gun::Update()
{
  m_box.Move(m_velocity, m_direction);
}
