#pragma once

class ConstantManager
{
public:

  static ConstantManager & GetConstantManager()
  {
    static ConstantManager instance;
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
  ConstantManager() {}
  ~ConstantManager() {}
  ConstantManager(ConstantManager const &) = delete;
  ConstantManager & operator=(ConstantManager const &) = delete;
  ConstantManager(ConstantManager const &&) = delete;
  ConstantManager & operator=(ConstantManager const &&) = delete;
};