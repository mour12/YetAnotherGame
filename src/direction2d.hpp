#pragma once

#include <initializer_list>
#include <ostream>

class Direction2D
{
public:

  Direction2D() = default;
  Direction2D(float x, float y);
  Direction2D(Direction2D const & obj);
  Direction2D(std::initializer_list<float> const & lst);

  Direction2D & operator = (Direction2D const & obj);

  bool operator == (Direction2D const & obj) const;
  bool operator != (Direction2D const & obj) const;

  Direction2D operator + (Direction2D const & obj) const;
  Direction2D operator - (Direction2D const & obj) const;

  Direction2D & operator += (Direction2D const & obj);
  Direction2D & operator -= (Direction2D const & obj);

  Direction2D operator - () const;

  float const & x() const;
  float const & y() const;

private:

  bool EqualWithEps(float v1, float v2) const;
  void NormalizeDirection();

  float m_x = 1.0f, m_y = 0.0f;
};

std::ostream & operator << (std::ostream & os, Direction2D const & obj);
