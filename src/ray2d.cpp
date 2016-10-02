#include "ray2d.hpp"
#include <cmath>

float const kEps = 1e-5;

Ray2D::Ray2D() = default;

Ray2D::Ray2D(Ray2D const & obj)
  : m_origin(obj.m_origin), m_direction(obj.m_direction)
{}

Ray2D::Ray2D(Point2D const & origin, Point2D const & direction)
  : m_origin(origin), m_direction(direction)
{
  NormalizeDirection();
}

Ray2D::Ray2D(std::initializer_list<Point2D> const & lst)
{
  Point2D * vals[] = { &m_origin, &m_direction };
  int const count = sizeof(vals) / sizeof(vals[0]);
  auto it = lst.begin();
  for (int i = 0; i < count && it != lst.end(); ++i, ++it)
  {
    *vals[i] = *it;
  }
  NormalizeDirection();
}

Ray2D::Ray2D(Ray2D && obj)
{
  std::swap(m_origin, obj.m_origin);
  std::swap(m_direction, obj.m_direction);
}

Ray2D & Ray2D::operator=(Ray2D const & obj)
{
  if (this == &obj) return *this;
  m_origin = obj.m_origin;
  m_direction = obj.m_direction;
  return *this;
}

bool Ray2D::operator==(Ray2D const & obj) const
{
  return m_origin == obj.m_origin && m_direction == obj.m_direction;
}

bool Ray2D::operator!=(Ray2D const & obj) const
{
  return !operator==(obj);
}

Ray2D Ray2D::operator-() const
{
  return {-m_origin, -m_direction};
}

Ray2D Ray2D::operator+(Ray2D const & obj) const
{
  return {m_origin + obj.m_origin, m_direction + obj.m_direction};
}

Ray2D Ray2D::operator-(Ray2D const & obj) const
{
  return {m_origin - obj.m_origin, m_direction - obj.m_direction};
}

Ray2D Ray2D::operator*(float scale) const
{
  return {m_origin * scale, m_direction * scale};
}

Ray2D Ray2D::operator/(float scale) const // TODO: Check for division by zero
{
  return {m_origin / scale, m_direction / scale};
}

Ray2D & Ray2D::operator+=(Ray2D const & obj)
{
  m_origin += obj.m_origin;
  m_direction += obj.m_direction;
  NormalizeDirection();
  return *this;
}

Ray2D & Ray2D::operator-=(Ray2D const & obj)
{
  m_origin -= obj.m_origin;
  m_direction -= obj.m_direction;
  NormalizeDirection();
  return *this;
}

Ray2D& Ray2D::operator*=(float scale)
{
  int sign;
  if (EqualWithEps(scale, 0.0f))
  {
    sign = 0;
  }
  else if (scale > 0)
  {
    sign = 1;
  }
  else
  {
    sign = -1;
  }

  m_origin *= scale;
  m_direction *= sign;

  return *this;
}

Ray2D& Ray2D::operator/=(float scale) // TODO: Check for division by zero
{
  int sign;
  if (EqualWithEps(scale, 0.0f))
  {
    sign = 0;
  }
  else if (scale > 0)
  {
    sign = 1;
  }
  else
  {
    sign = -1;
  }

  m_origin /= scale;
  m_direction /= sign;

  return *this;
}

Point2D & Ray2D::origin() { return m_origin; }

Point2D const & Ray2D::origin() const { return m_origin; }
Point2D const & Ray2D::direction() const { return m_direction; }

void Ray2D::NormalizeDirection() // TODO: check for division by zero
{
  float length = sqrtf(m_direction.x() * m_direction.x() + m_direction.y() * m_direction.y());
  m_direction /= length;
}

bool Ray2D::EqualWithEps(float v1, float v2) const
{
  return fabs(v1 - v2) < kEps;
}

std::ostream & operator<<(std::ostream & os, Ray2D const & obj)
{
  os << "Ray2D {Origin {" << obj.origin().x() << ", " << obj.origin().y() << "}, Direction {" << obj.direction().x() << ", " << obj.direction().y() << "}}";
  return os;
}
