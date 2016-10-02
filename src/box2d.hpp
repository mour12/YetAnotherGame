#pragma once

#include <cmath>
#include "point2d.hpp"

class Box2D
{
public:

  Box2D() :
    m_leftLowCorner(Point2D()),
    m_rightUpCorner(Point2D())
  {}

  Box2D(Box2D const & obj) :
    m_leftLowCorner(obj.m_leftLowCorner),
    m_rightUpCorner(obj.m_rightUpCorner)
  {}

  Box2D(Point2D const & leftLowCorner, Point2D const & rightUpCorner) :
    m_leftLowCorner(leftLowCorner),
    m_rightUpCorner(rightUpCorner)
  {}

  Box2D(Box2D && obj)
  {
    std::swap(m_leftLowCorner, obj.m_leftLowCorner);
    std::swap(m_rightUpCorner, obj.m_rightUpCorner);
  }

  Box2D(std::initializer_list<Point2D> const & lst)
  {
    Point2D * vals[] = { &m_leftLowCorner, &m_rightUpCorner };
    int const count = sizeof(vals) / sizeof(vals[0]);
    auto it = lst.begin();
    for (int i = 0; i < count && it != lst.end(); i++, ++it)
      *vals[i] = *it;
  }

  virtual ~Box2D() {}

  Point2D & leftLowCorner() { return m_leftLowCorner; }
  Point2D & rightUpCorner() { return m_rightUpCorner; }

  Point2D const & leftLowCorner() const { return m_leftLowCorner; }
  Point2D const & rightUpCorner() const { return m_rightUpCorner; }

  float Area() const
  {
    return std::abs(m_rightUpCorner.x() - m_leftLowCorner.x()) * std::abs(m_rightUpCorner.y() - m_leftLowCorner.y());
  }

  float Perimeter() const
  {
    return (std::abs(m_rightUpCorner.x() - m_leftLowCorner.x()) + std::abs(m_rightUpCorner.y() - m_leftLowCorner.y())) * 2;
  }

  bool operator == (Box2D const & obj) const
  {
    return (m_leftLowCorner == obj.m_leftLowCorner) && (m_rightUpCorner == obj.m_rightUpCorner);
  }

  Box2D & operator = (Box2D const & obj)
  {
    if (this == &obj) return *this;
    m_leftLowCorner = obj.m_leftLowCorner;
    m_rightUpCorner = obj.m_rightUpCorner;
    return *this;
  }

  bool operator != (Box2D const & obj) const
  {
    return !operator==(obj);
  }

  bool operator < (Box2D const & obj) const
  {
    return (this->Area() < obj.Area()) ? true : false;//TODO: Implement comparison using epsilon
  }

  Point2D operator [] (unsigned int index) const
  {
    if (index >= 2) throw std::out_of_range("Index must be 0 or 1");
    return index == 0 ? m_leftLowCorner : m_rightUpCorner;
  }

private:

  Point2D m_leftLowCorner;
  Point2D m_rightUpCorner;
};


inline std::ostream & operator << (std::ostream & os, Box2D const & obj)
{
  os << "Box2D {" << obj.leftLowCorner() << ", " << obj.rightUpCorner() << "}";
  return os;
}
