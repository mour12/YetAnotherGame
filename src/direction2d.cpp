#include "direction2d.hpp"
#include <cmath>

float const kEps = 1e-5;

Direction2D::Direction2D(Direction2D const & obj)
  : m_x(obj.m_x), m_y(obj.m_y)
{}

Direction2D::Direction2D(float x, float y)
  : m_x(x), m_y(y)
{
  NormalizeDirection();
}

bool Direction2D::operator == (Direction2D const & obj) const
{
  return EqualWithEps(m_x, obj.m_x) && EqualWithEps(m_y, obj.m_y);
}

float const & Direction2D::x() const { return m_x; }

float const & Direction2D::y() const { return m_y; }

Direction2D::Direction2D(std::initializer_list<float> const & lst)
{
  float * vals[] = {&m_x, &m_y};
  int const count = sizeof(vals) / sizeof(vals[0]);
  auto it = lst.begin();
  for (int i = 0; i < count && it != lst.end(); i++, ++it)
    *vals[i] = *it;
  NormalizeDirection();
}

Direction2D & Direction2D::operator = (Direction2D const & obj)
{
  if (this == &obj) return *this;
  m_x = obj.m_x;
  m_y = obj.m_y;
  return *this;
}

bool Direction2D::operator != (Direction2D const & obj) const
{
  return !operator==(obj);
}

Direction2D Direction2D::operator + (Direction2D const & obj) const
{
    return {m_x + obj.m_x, m_y + obj.m_y};
}

Direction2D Direction2D::operator - (Direction2D const & obj) const
{
  return {m_x - obj.m_x, m_y - obj.m_y};
}

Direction2D Direction2D::operator - () const
{
  return {-m_x, -m_y};
}

Direction2D & Direction2D::operator += (Direction2D const & obj)
{
  m_x += obj.m_x;
  m_y += obj.m_y;
  NormalizeDirection();
  return *this;
}

Direction2D & Direction2D::operator -= (Direction2D const & obj)
{
  m_x -= obj.m_x;
  m_y -= obj.m_y;
  NormalizeDirection();
  return *this;
}

void Direction2D::NormalizeDirection() // TODO: check for division by zero
{
  float length = sqrtf(m_x * m_x + m_y * m_y);
  m_x /= length;
  m_y /= length;
}

bool Direction2D::EqualWithEps(float v1, float v2) const
{
  return fabs(v1 - v2) < kEps;
}

std::ostream & operator << (std::ostream & os, Direction2D const & obj)
{
  os << "Direction2D {" << obj.x() << ", " << obj.y() << "}";
  return os;
}

