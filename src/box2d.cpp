#include "box2d.hpp"
#include <cmath>
#include <iostream>

Box2D::Box2D() :
  m_leftLowCorner(Point2D()),
  m_rightUpCorner(Point2D())
{}

Box2D::Box2D(Box2D const & obj) :
  m_leftLowCorner(obj.m_leftLowCorner),
  m_rightUpCorner(obj.m_rightUpCorner)
{}

Box2D::Box2D(Point2D const & leftLowCorner, Point2D const & rightUpCorner)
{
  std::pair<Point2D, Point2D> validPoints = ValidatePoints(leftLowCorner, rightUpCorner);
  m_leftLowCorner = validPoints.first;
  m_rightUpCorner = validPoints.second;
}

Box2D::Box2D(Box2D && obj)
{
  std::swap(m_leftLowCorner, obj.m_leftLowCorner);
  std::swap(m_rightUpCorner, obj.m_rightUpCorner);
}

Box2D::Box2D(std::initializer_list<Point2D> const & lst)
{
  Point2D p1, p2;
  Point2D * vals[] = { &p1, &p2 };
  int const count = sizeof(vals) / sizeof(vals[0]);
  auto it = lst.begin();
  for (int i = 0; i < count && it != lst.end(); i++, ++it)
    *vals[i] = *it;
  std::pair<Point2D, Point2D> validPoints = ValidatePoints(p1, p2);
  m_leftLowCorner = validPoints.first;
  m_rightUpCorner = validPoints.second;
}

Point2D const & Box2D::leftLowCorner() const { return m_leftLowCorner; }
Point2D const & Box2D::rightUpCorner() const { return m_rightUpCorner; }

float Box2D::Width() const
{
  return fabsf(m_rightUpCorner.x() - m_leftLowCorner.x());
}

float Box2D::Height() const
{
  return fabsf(m_rightUpCorner.y() - m_leftLowCorner.y());
}

float Box2D::Area() const
{
  return this->Height() * this->Width();
}

float Box2D::Perimeter() const
{
  return (this->Height() + this->Width()) * 2;
}

bool Box2D::Intersects(Box2D const & obj)
{
  if  (leftLowCorner().x() > obj.rightUpCorner().x()
    || leftLowCorner().y() > obj.rightUpCorner().y()
    || rightUpCorner().x() < obj.leftLowCorner().x()
    || rightUpCorner().y() < obj.leftLowCorner().y())
  {
    return false;
  }
  else
  {
    return true;
  }
}

bool Box2D::operator == (Box2D const & obj) const
{
  return (m_leftLowCorner == obj.m_leftLowCorner) && (m_rightUpCorner == obj.m_rightUpCorner);
}

Box2D & Box2D::operator = (Box2D const & obj)
{
  if (this == &obj) return *this;
  m_leftLowCorner = obj.m_leftLowCorner;
  m_rightUpCorner = obj.m_rightUpCorner;
  return *this;
}

bool Box2D::operator != (Box2D const & obj) const
{
  return !operator==(obj);
}

bool Box2D::operator < (Box2D const & obj) const
{
  return this->Area() < obj.Area();//TODO: Implement comparison using epsilon
}

Point2D Box2D::operator [] (unsigned int index) const
{
  if (index >= 2) throw std::out_of_range("Index must be 0 or 1");
  return index == 0 ? m_leftLowCorner : m_rightUpCorner;
}

std::pair<Point2D,Point2D> Box2D::ValidatePoints(Point2D p1, Point2D p2)
{
 if (p1.x() > p2.x())
 {
   if (p1.y() > p2.y())
   {
     return std::make_pair(p2, p1);
   }
   else
   {
     return std::make_pair(Point2D(p2.x(), p1.y()), Point2D(p1.x(), p2.y()));
   }
 }
 else if (p1.y() > p2.y())
 {
   return std::make_pair(Point2D(p1.x(), p2.y()), Point2D(p2.x(), p1.y()));
 }
 else
 {
   return std::make_pair(p1, p2);
 }
}

std::ostream & operator << (std::ostream & os, Box2D const & obj)
{
  os << "Box2D {" << obj.leftLowCorner() << ", " << obj.rightUpCorner() << "}";
  return os;
}
