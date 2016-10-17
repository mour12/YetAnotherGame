#include "gtest/gtest.h"
#include "gun.hpp"
#include <unordered_set>

TEST(gun_test, test_construction)
{
  Gun gun1 = Gun();
  EXPECT_EQ(gun1.box(), Box2D());
  EXPECT_EQ(gun1.direction(), Direction2D());
  EXPECT_EQ(gun1.spacePtr().lock(), nullptr);
  EXPECT_EQ(gun1.velocity(), 0.0f);
  EXPECT_EQ(gun1.health(), 1);

  Point2D leftBottomCorner(1.0f, 3.0f);
  Point2D rightTopCorner(2.0f, 5.0f);
  Box2D box(leftBottomCorner, rightTopCorner);
  Direction2D direction(1.0f, 1.0f);
  std::weak_ptr<Space> spacePtr = std::make_shared<Space>(Space());

  Gun gun2 = Gun(box, direction, 1.0f, 15, spacePtr);
  EXPECT_EQ(gun2.box(), box);
  EXPECT_EQ(gun2.direction(), direction);
  EXPECT_EQ(gun2.spacePtr().lock(), spacePtr.lock());
  EXPECT_EQ(gun2.velocity(), 1.0f);
  EXPECT_EQ(gun2.health(), 15);

  Gun gun3 = Gun(gun2);
  EXPECT_EQ(gun3.box(), box);
  EXPECT_EQ(gun3.direction(), direction);
  EXPECT_EQ(gun3.spacePtr().lock(), spacePtr.lock());
  EXPECT_EQ(gun3.velocity(), 1.0f);
  EXPECT_EQ(gun3.health(), 15);
}

TEST(gun_test, test_assignment)
{
  Point2D leftBottomCorner(1.0f, 3.0f);
  Point2D rightTopCorner(2.0f, 5.0f);
  Box2D box(leftBottomCorner, rightTopCorner);
  Direction2D direction(1.0f, 1.0f);
  std::weak_ptr<Space> spacePtr = std::make_shared<Space>(Space());

  Gun gun1 = Gun(box, direction, 1.0f, 15, spacePtr);
  EXPECT_EQ(gun1.box(), box);
  EXPECT_EQ(gun1.direction(), direction);
  EXPECT_EQ(gun1.spacePtr().lock(), spacePtr.lock());
  EXPECT_EQ(gun1.velocity(), 1.0f);
  EXPECT_EQ(gun1.health(), 15);

  Gun gun2 = gun1;
  EXPECT_EQ(gun2.box(), box);
  EXPECT_EQ(gun2.direction(), direction);
  EXPECT_EQ(gun2.spacePtr().lock(), spacePtr.lock());
  EXPECT_EQ(gun2.velocity(), 1.0f);
  EXPECT_EQ(gun2.health(), 15);
}

TEST(gun_test, test_equality)
{
  Point2D leftBottomCorner(1.0f, 3.0f);
  Point2D rightTopCorner(2.0f, 5.0f);
  Box2D box(leftBottomCorner, rightTopCorner);
  Direction2D direction(1.0f, 1.0f);
  std::weak_ptr<Space> spacePtr = std::make_shared<Space>(Space());

  Gun gun1 = Gun(box, direction, 1.0f, 15, spacePtr);
  Gun gun2 = Gun(gun1);
  EXPECT_EQ(gun1, gun2);
}

TEST(gun_test, test_coordinates)
{
  Point2D leftBottomCorner(1.0f, 3.0f);
  Point2D rightTopCorner(3.0f, 5.0f);
  Box2D box(leftBottomCorner, rightTopCorner);
  Direction2D direction(1.0f, 1.0f);
  std::weak_ptr<Space> spacePtr = std::make_shared<Space>(Space());

  Gun gun = Gun(box, direction, 1.0f, 15, spacePtr);
  EXPECT_EQ(gun.Сoordinates(), Point2D(2.0f, 4.0f));
}

TEST(gun_test, test_shooting)
{
  std::shared_ptr<Space> spacePtr = std::make_shared<Space>(Space(100, 100));

  Point2D boxLeftBottomCorner(10.0f, 30.0f);
  Point2D boxRightTopCorner(30.0f, 50.0f);
  Box2D box(boxLeftBottomCorner, boxRightTopCorner);
  Direction2D direction(1.0f, 1.0f);

  Gun gun = Gun(box, direction, 1.0f, 15, spacePtr);
  spacePtr->gameEntities().push_back(std::make_shared<GameEntity>(static_cast<GameEntity>(gun)));
  gun.Shoot();

  Point2D bulletLeftBottomCorner(17, 50);
  Point2D bulletRightTopCorner(23, 56);
  Direction2D bulletDirection(0.0f, 1.0f);
  Box2D bulletBox(bulletLeftBottomCorner, bulletRightTopCorner);
  Bullet bullet(bulletBox, bulletDirection, 10, 1, spacePtr);

  EXPECT_EQ(spacePtr->gameEntities().size(), 2);
  EXPECT_EQ(*(spacePtr->gameEntities()[0]), gun);
  EXPECT_EQ(*(spacePtr->gameEntities()[1]), bullet);
}
