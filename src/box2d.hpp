#pragma once

#include <cmath>
#include "point2d.hpp"
#include "direction2d.hpp"

class Box2D
{
public:

  Box2D() = default;
  Box2D(Box2D const & obj);
  Box2D(Point2D const & leftBottomCorner, Point2D const & rightTopCorner);
  Box2D(Box2D && obj);
  Box2D(std::initializer_list<Point2D> const & lst);

  //virtual ~Box2D() {}

  Point2D const & leftBottomCorner() const;
  Point2D const & rightTopCorner() const;
  Point2D Center() const;

  float Width() const;
  float Height() const;

  float Area() const;
  float Perimeter() const;
  bool Intersects(Box2D const & obj) const;
  void Move(float const & velocity, Direction2D const & direction);

  bool operator == (Box2D const & obj) const;
  Box2D & operator = (Box2D const & obj);
  Box2D & operator = (Box2D && obj);
  bool operator != (Box2D const & obj) const;
  bool operator < (Box2D const & obj) const;
  Point2D operator [] (unsigned int index) const;

private:

  Point2D m_leftBottomCorner;
  Point2D m_rightTopCorner;

  std::pair<Point2D,Point2D> ValidatePoints(Point2D p1, Point2D p2);
};

std::ostream & operator << (std::ostream & os, Box2D const & obj);
