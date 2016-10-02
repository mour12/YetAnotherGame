#pragma once

#include "point2d.hpp"
#include <initializer_list>
#include <functional>
#include <ostream>

class Ray2D
{
public:
  Ray2D();
  Ray2D(Ray2D const & obj);
  Ray2D(Point2D const & origin, Point2D const & direction);
  Ray2D(std::initializer_list<Point2D> const & lst);
  Ray2D(Ray2D && obj);

  Ray2D & operator=(Ray2D const & obj);

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
  Point2D const & direction() const;

private:
  Point2D m_origin = {0.0f, 0.0f};
  Point2D m_direction = {1.0f, 0.0f};

  void NormalizeDirection();
  bool EqualWithEps(float f1, float f2) const;
};

std::ostream & operator<<(std::ostream & os, Ray2D const & obj);
