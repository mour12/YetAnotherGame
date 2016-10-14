#include "ray2d.hpp"
#include <cmath>

float const kEps = 1e-5;

Ray2D::Ray2D(Ray2D const & obj)
  : m_origin(obj.m_origin), m_direction(obj.m_direction)
{}

Ray2D::Ray2D(Point2D const & origin, Direction2D const & direction)
  : m_origin(origin), m_direction(direction)
{}

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

Ray2D & Ray2D::operator=(Ray2D && obj)
{
  std::swap(m_origin, obj.m_origin);
  std::swap(m_direction, obj.m_direction);
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

Ray2D Ray2D::operator*(float scale) const // TODO: Check for multiply by zero
{
  if (Sign(scale) == 1) return {m_origin * scale, m_direction};
  else return {m_origin * scale, -m_direction};
}

Ray2D Ray2D::operator/(float scale) const // TODO: Check for division by zero
{
  if (Sign(scale) == 1) return {m_origin / scale, m_direction};
  else return {m_origin / scale, -m_direction};
}

Ray2D & Ray2D::operator+=(Ray2D const & obj)
{
  m_origin += obj.m_origin;
  m_direction += obj.m_direction;
  return *this;
}

Ray2D & Ray2D::operator-=(Ray2D const & obj)
{
  m_origin -= obj.m_origin;
  m_direction -= obj.m_direction;
  return *this;
}

Ray2D & Ray2D::operator*=(float scale)
{
  m_origin *= scale;
  if (Sign(scale) == -1) m_direction = -m_direction; // TODO: Check for zero-vector direction
  return *this;
}

Ray2D & Ray2D::operator/=(float scale) // TODO: Check for division by zero
{
  m_origin /= scale;
  if (Sign(scale) == -1) m_direction = -m_direction;
  return *this;
}

Point2D & Ray2D::origin() { return m_origin; }

Point2D const & Ray2D::origin() const { return m_origin; }
Direction2D const & Ray2D::direction() const { return m_direction; }

bool Ray2D::Intersects(Box2D const & box) const
{
  return Intersects(box.LeftBottomCorner(), Point2D(box.LeftBottomCorner().x(), box.RightTopCorner().y()))
         || Intersects(Point2D(box.LeftBottomCorner().x(), box.RightTopCorner().y()), box.RightTopCorner())
         || Intersects(Point2D(box.RightTopCorner().x(), box.LeftBottomCorner().y()), box.RightTopCorner())
         || Intersects(box.LeftBottomCorner(), Point2D(box.RightTopCorner().x(), box.LeftBottomCorner().y()));
}

bool Ray2D::EqualWithEps(float v1, float v2) const
{
  return fabs(v1 - v2) < kEps;
}

int Ray2D::Sign(float f) const
{
  if (EqualWithEps(f, 0.0f)) return 0;
  else if (f > 0) return 1;
  else return -1;
}

bool Ray2D::Intersects(Point2D const & p1, Point2D const & p2) const
{
  float k = m_direction.y() / m_direction.x(); // TODO: check for division by zero
  float b = m_origin.y() - k * m_origin.x();
  // y = k * x + b
  // x = (y - b) / k
  if (EqualWithEps(p1.x(), p2.x()))
  {
    if ((m_origin.x() <= p1.x() && m_direction.x() > 0 || m_origin.x() >= p1.x() && m_direction.x() < 0)
        && k * p1.x() + b >= p1.y()
        && k * p1.x() + b <= p2.y()) return true;
  }
  else
  {
    if (EqualWithEps(m_direction.x(), 0.0f)
        && m_origin.x() >= p1.x()
        && m_origin.x() <= p2.x()
        && (m_origin.y() <= p1.y() && m_direction.y() > 0 || m_origin.y() >= p1.y() && m_direction.y() < 0)) return true;

    if ((m_origin.y() <= p1.y() && m_direction.y() > 0 || m_origin.y() >= p1.y() && m_direction.y() < 0)
        && (p1.y() - b) / k >= p1.x()
        && (p1.y() - b) / k <= p2.x()) return true; // TODO: check for division by zero
  }
  return false;
}

std::ostream & operator<<(std::ostream & os, Ray2D const & obj)
{
  os << "Ray2D {Origin {" << obj.origin().x() << ", " << obj.origin().y() << "}, " << obj.direction() << "}";
  return os;
}
