#include "box2d.hpp"
#include <cmath>
#include <iostream>

Box2D::Box2D(Box2D const & obj) :
  m_leftBottomCorner(obj.m_leftBottomCorner),
  m_rightTopCorner(obj.m_rightTopCorner)
{}

Box2D::Box2D(Point2D const & leftBottomCorner, Point2D const & rightTopCorner)
{
  std::pair<Point2D, Point2D> validPoints = ValidatePoints(leftBottomCorner, rightTopCorner);
  m_leftBottomCorner = validPoints.first;
  m_rightTopCorner = validPoints.second;
}

Box2D::Box2D(Box2D && obj)
{
  std::swap(m_leftBottomCorner, obj.m_leftBottomCorner);
  std::swap(m_rightTopCorner, obj.m_rightTopCorner);
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
  m_leftBottomCorner = validPoints.first;
  m_rightTopCorner = validPoints.second;
}

Point2D const & Box2D::leftBottomCorner() const { return m_leftBottomCorner; }
Point2D const & Box2D::rightTopCorner() const { return m_rightTopCorner; }

float Box2D::Width() const
{
  return m_rightTopCorner.x() - m_leftBottomCorner.x();
}

float Box2D::Height() const
{
  return m_rightTopCorner.y() - m_leftBottomCorner.y();
}

float Box2D::Area() const
{
  return this->Height() * this->Width();
}

float Box2D::Perimeter() const
{
  return (this->Height() + this->Width()) * 2;
}

bool Box2D::Intersects(Box2D const & obj) const
{
  return !(leftBottomCorner().x() > obj.rightTopCorner().x()
    || leftBottomCorner().y() > obj.rightTopCorner().y()
    || rightTopCorner().x() < obj.leftBottomCorner().x()
    || rightTopCorner().y() < obj.leftBottomCorner().y());
}

bool Box2D::operator == (Box2D const & obj) const
{
  return (m_leftBottomCorner == obj.m_leftBottomCorner) && (m_rightTopCorner == obj.m_rightTopCorner);
}

Box2D &Box2D::operator = (Box2D const & obj)
{
  if (this == &obj) return *this;
  m_leftBottomCorner = obj.m_leftBottomCorner;
  m_rightTopCorner = obj.m_rightTopCorner;
  return *this;
}

Box2D &Box2D::operator = (Box2D && obj)
{
  std::swap(m_leftBottomCorner, obj.m_leftBottomCorner);
  std::swap(m_rightTopCorner, obj.m_rightTopCorner);
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
  return index == 0 ? m_leftBottomCorner : m_rightTopCorner;
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
  os << "Box2D {" << obj.leftBottomCorner() << ", " << obj.rightTopCorner() << "}";
  return os;
}
