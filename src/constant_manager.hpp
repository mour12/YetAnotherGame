#pragma once

class ConstantManager
{
public:

  static ConstantManager & GetConstantManager()
  {
    static ConstantManager instance;
    return instance;
  }

  float AlienSpeed();
  float GunSpeed();
  int GunHp();
  int AlienHp();
  int ObstacleHp();
  int ObstacleQuantity();
  int AlienQuantity();
  float AlienSize();
  float GunSize();
  float ObstacleSize();
  float BulletSize();
  float BulletSpeed();

private:
  ConstantManager() {}
  ~ConstantManager() {}
  ConstantManager(ConstantManager const &) = delete;
  ConstantManager & operator=(ConstantManager const &) = delete;
  ConstantManager(ConstantManager const &&) = delete;
  ConstantManager & operator=(ConstantManager const &&) = delete;
};
