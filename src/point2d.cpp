#include "point2d.hpp"
#include <cmath>

float const kEps = 1e-5;

Point2D::Point2D() = default;

Point2D::Point2D(Point2D const & obj)
: m_x(obj.m_x), m_y(obj.m_y)
{}

Point2D::Point2D(float x, float y)
: m_x(x), m_y(y)
{}

bool Point2D::operator ==(Point2D const & obj) const
{
  return EqualWithEps(m_x, obj.m_x) && EqualWithEps(m_y, obj.m_y);
}

float & Point2D::x() { return m_x; }

float & Point2D::y() { return m_y; }

float const & Point2D::x() const { return m_x; }

float const & Point2D::y() const { return m_y; }

Point2D::Point2D(std::initializer_list<float> const & lst)
{
  float * vals[] = {&m_x, &m_y};
  int const count = sizeof(vals) / sizeof(vals[0]);
  auto it = lst.begin();
  for (int i = 0; i < count && it != lst.end(); i++, ++it)
    *vals[i] = *it;
}

Point2D & Point2D::operator =(Point2D const & obj)
{
  if (this == &obj) return *this;
  m_x = obj.m_x;
  m_y = obj.m_y;
  return *this;
}

bool Point2D::operator !=(Point2D const & obj) const
{
  return !operator ==(obj);
}

bool Point2D::operator <(Point2D const & obj) const
{
  if (m_x < obj.m_x) return true;
  return m_y < obj.m_y;
}

Point2D Point2D::operator +(Point2D const & obj) const
{
  return {m_x + obj.m_x, m_y + obj.m_y};
}

Point2D Point2D::operator -(Point2D const & obj) const
{
  return {m_x - obj.m_x, m_y - obj.m_y};
}

Point2D Point2D::operator -() const
{
  return {-m_x, -m_y};
}

Point2D Point2D::operator *(float scale) const
{
  return {m_x * scale, m_y * scale};
}

Point2D Point2D::operator /(float scale) const
{
  //TODO: обработать деление на 0.
  return {m_x / scale, m_y / scale};
}

Point2D & Point2D::operator +=(Point2D const & obj)
{
  m_x += obj.m_x;
  m_y += obj.m_y;
  return *this;
}

Point2D & Point2D::operator -=(Point2D const & obj)
{
  m_x -= obj.m_x;
  m_y -= obj.m_y;
  return *this;
}

Point2D & Point2D::operator *=(float scale)
{
  m_x *= scale;
  m_y *= scale;
  return *this;
}

Point2D & Point2D::operator /=(float scale)
{
  //TODO: обработать деление на 0.
  m_x /= scale;
  m_y /= scale;
  return *this;
}

float Point2D::operator [](unsigned int index) const
{
  if (index >= 2) return 0.0f;
  return index == 0 ? m_x : m_y;
}

size_t Point2D::Hash::operator ()(Point2D const & p) const
{
  auto hasher = std::hash<float>();
  return (hasher(p.x()) ^ (hasher(p.y()) << 1));
}


bool Point2D::EqualWithEps(float v1, float v2) const
{
  return fabs(v1 - v2) < kEps;
}

std::ostream & operator <<(std::ostream & os, Point2D const & obj)
{
  os << "Point2D {" << obj.x() << ", " << obj.y() << "}";
  return os;
}

