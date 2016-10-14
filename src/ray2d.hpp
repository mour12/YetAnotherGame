#pragma once

#include <initializer_list>
#include <functional>
#include <ostream>
#include "point2d.hpp"
#include "box2d.hpp"
#include "direction2d.hpp"

class Ray2D
{
public:
  Ray2D() = default;
  Ray2D(Ray2D const & obj);
  Ray2D(Point2D const & origin, Direction2D const & direction);
  Ray2D(Ray2D && obj);

  Ray2D & operator=(Ray2D const & obj);
  Ray2D & operator=(Ray2D && obj);

  bool operator==(Ray2D const & obj) const;
  bool operator!=(Ray2D const & obj) const;

  Ray2D operator-() const;
  Ray2D operator+(Ray2D const & obj) const;
  Ray2D operator-(Ray2D const & obj) const;
  Ray2D operator*(float scale) const;
  Ray2D operator/(float scale) const;

  Ray2D & operator+=(Ray2D const & obj);
  Ray2D & operator-=(Ray2D const & obj);
  Ray2D & operator*=(float scale);
  Ray2D & operator/=(float scale);

  Point2D & origin();

  Point2D const & origin() const;
  Direction2D const & direction() const;

  bool Intersects(Box2D const & box) const;

private:
  Point2D m_origin = {0.0f, 0.0f};
  Direction2D m_direction = {1.0f, 0.0f};

  bool EqualWithEps(float f1, float f2) const;
  int Sign(float f) const;
  bool Intersects(Point2D const & p1, Point2D const & p2) const;
};

std::ostream & operator<<(std::ostream & os, Ray2D const & obj);
