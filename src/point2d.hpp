#pragma once

#include <initializer_list>
#include <functional>
#include <ostream>

class Point2D
{
public:
  // Разрешаем конструирование по умолчанию.
  Point2D();

  // Конструктор копирования.
  Point2D(Point2D const & obj);

  // Конструктор с параметрами.
  Point2D(float x, float y);

  // Оператор логического равенства.
  bool operator == (Point2D const & obj) const;

  float & x();
  float & y();

  float const & x() const;
  float const & y() const;

  // Конструктор со списком инициализации.
  Point2D(std::initializer_list<float> const & lst);

  // Оператор присваивания.
  Point2D & operator = (Point2D const & obj);

  // Оператор логического неравенства.
  bool operator != (Point2D const & obj) const;

  // Оператор меньше.
  bool operator < (Point2D const & obj) const;

  // Сложение.
  Point2D operator + (Point2D const & obj) const;

  // Вычитание.
  Point2D operator - (Point2D const & obj) const;

  // Математическое отрицание.
  Point2D operator - () const;

  // Умножение на число.
  Point2D operator * (float scale) const;

  // Деление на число.
  Point2D operator / (float scale) const;

  Point2D & operator += (Point2D const & obj);
  Point2D & operator -= (Point2D const & obj);
  Point2D & operator *= (float scale);
  Point2D & operator /= (float scale);

  // Переопределение оператора [].
  float operator [] (unsigned int index) const;

  // Добавим внутреннюю сущность для вычисления хэша.
  struct Hash
  {
    size_t operator()(Point2D const & p) const;
  };

private:

  bool EqualWithEps(float v1, float v2) const;

  float m_x = 0.0f, m_y = 0.0f;
};

std::ostream & operator << (std::ostream & os, Point2D const & obj);

