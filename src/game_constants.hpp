#pragma once

class ConstantContainer
{
public:

  static ConstantContainer & GetConstantContainer()
  {
    static ConstantContainer instance;
    return instance;
  }

  float Speed();
  int GunHp();
  int BulletDamage();
  int ObstacleQuantity();
  int AlienQuantity();
  float AlienSize();
  float ObstacleSize();

private:
  ConstantContainer() {}
  ~ConstantContainer() {}
  ConstantContainer(ConstantContainer const &) = delete;
  ConstantContainer & operator=(ConstantContainer const &) = delete;
  ConstantContainer(ConstantContainer const &&) = delete;
  ConstantContainer & operator=(ConstantContainer const &&) = delete;
};
