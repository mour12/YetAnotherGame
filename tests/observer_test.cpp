#include <point2d.hpp>
#include <direction2d.hpp>
#include <box2d.hpp>
#include <bullet.hpp>
#include <alien.hpp>
#include "gtest/gtest.h"

TEST(observer_test, test_gun)
{
  Point2D leftBottomCorner(-3.0f, 0.0f);
  Point2D rightTopCorner(3.0f, 6.0f);
  Direction2D direction(0.0f, 1.0f);
  Box2D box(leftBottomCorner, rightTopCorner);
  auto bullet = std::make_shared<Bullet>(box, direction, 10.0f, 1, std::shared_ptr<Space>(nullptr));

  Point2D gunLeftBottomCorner(1.0f, 3.0f);
  Point2D gunRightTopCorner(2.0f, 5.0f);
  Box2D gunBox(gunLeftBottomCorner, gunRightTopCorner);
  Direction2D gunDirection(1.0f, 1.0f);
  auto gun = std::make_shared<Gun>(gunBox, gunDirection, 1.0f, 15, std::shared_ptr<Space>(nullptr));

  std::stringstream s;

  auto intersect = [&s](Observer * gun, Observable const * bullet)
  {
    if (dynamic_cast<Gun *>(gun)->box().Intersects(dynamic_cast<Bullet const *>(bullet)->box()))
    {
      s << "BOOM!" << std::endl;
    }
  };
  gun->SetOnNotifiedHandler(intersect);

  bullet->AddObserver(gun);
  bullet->Notify();

  EXPECT_EQ(s.str(), "BOOM!\n");
}

TEST(observer_test, test_alien)
{
  Point2D leftBottomCorner(-3.0f, 0.0f);
  Point2D rightTopCorner(3.0f, 6.0f);
  Direction2D direction(0.0f, 1.0f);
  Box2D box(leftBottomCorner, rightTopCorner);
  auto bullet = std::make_shared<Bullet>(box, direction, 10.0f, 1, std::shared_ptr<Space>(nullptr));

  Point2D alienLeftBottomCorner(1.0f, 3.0f);
  Point2D alienRightTopCorner(2.0f, 5.0f);
  Box2D alienBox(alienLeftBottomCorner, alienRightTopCorner);
  Direction2D alienDirection(1.0f, 1.0f);
  Ray2D alienRoute(alienBox.Center(), {0.0f, 1.0f});
  auto alien = std::make_shared<Alien>(alienBox, alienDirection, 1.0f, 15, alienRoute, std::shared_ptr<Space>(nullptr));

  std::stringstream s;

  auto intersect = [&s](Observer * alien, Observable const * bullet)
  {
    if (dynamic_cast<Alien *>(alien)->box().Intersects(dynamic_cast<Bullet const *>(bullet)->box()))
    {
      s << "BOOM!" << std::endl;
    }
  };
  alien->SetOnNotifiedHandler(intersect);

  bullet->AddObserver(alien);
  bullet->Notify();

  EXPECT_EQ(s.str(), "BOOM!\n");
}

