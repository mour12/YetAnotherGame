#include "gtest/gtest.h"
#include "bullet.hpp"
#include <unordered_set>

TEST(bullet_test, test_construction)
{
  Bullet bullet1 = Bullet();
  EXPECT_EQ(bullet1.box(), Box2D());
  EXPECT_EQ(bullet1.direction(), Direction2D());
  EXPECT_EQ(bullet1.spacePtr().lock(), nullptr);
  EXPECT_EQ(bullet1.velocity(), 0.0f);
  EXPECT_EQ(bullet1.health(), 1);

  Point2D leftBottomCorner(1.0f, 3.0f);
  Point2D rightTopCorner(2.0f, 5.0f);
  Direction2D direction(0.0f, 1.0f);
  Box2D box(leftBottomCorner, rightTopCorner);
  std::weak_ptr<Space> spacePtr;
  spacePtr = std::make_shared<Space>(Space());

  Bullet bullet2 = Bullet(box, direction, 10.0f, 10, spacePtr);
  EXPECT_EQ(bullet2.box(), box);
  EXPECT_EQ(bullet2.direction(), direction);
  EXPECT_EQ(bullet2.spacePtr().lock(), spacePtr.lock());
  EXPECT_EQ(bullet2.velocity(), 10.0f);
  EXPECT_EQ(bullet2.health(), 10);

  Bullet bullet3 = Bullet(bullet2);
  EXPECT_EQ(bullet3.box(), box);
  EXPECT_EQ(bullet3.direction(), direction);
  EXPECT_EQ(bullet3.spacePtr().lock(), spacePtr.lock());
  EXPECT_EQ(bullet3.velocity(), 10.0f);
  EXPECT_EQ(bullet3.health(), 10);
}

TEST(bullet_test, test_assignment)
{
  Point2D leftBottomCorner(1.0f, 3.0f);
  Point2D rightTopCorner(2.0f, 5.0f);
  Direction2D direction(0.0f, 1.0f);
  Box2D box(leftBottomCorner, rightTopCorner);
  std::weak_ptr<Space> spacePtr;
  spacePtr = std::make_shared<Space>(Space());

  Bullet bullet1 = Bullet(box, direction, 10.0f, 10, spacePtr);
  EXPECT_EQ(bullet1.box(), box);
  EXPECT_EQ(bullet1.direction(), direction);
  EXPECT_EQ(bullet1.spacePtr().lock(), spacePtr.lock());
  EXPECT_EQ(bullet1.velocity(), 10.0f);
  EXPECT_EQ(bullet1.health(), 10);

  Bullet bullet2 = bullet1;
  EXPECT_EQ(bullet2.box(), box);
  EXPECT_EQ(bullet2.direction(), direction);
  EXPECT_EQ(bullet2.spacePtr().lock(), spacePtr.lock());
  EXPECT_EQ(bullet2.velocity(), 10.0f);
  EXPECT_EQ(bullet2.health(), 10);
}

TEST(bullet_test, test_equality)
{
  Point2D leftBottomCorner(1.0f, 3.0f);
  Point2D rightTopCorner(2.0f, 5.0f);
  Direction2D direction(0.0f, 1.0f);
  Box2D box(leftBottomCorner, rightTopCorner);
  std::weak_ptr<Space> spacePtr;
  spacePtr = std::make_shared<Space>(Space());

  Bullet bullet1 = Bullet(box, direction, 10.0f, 10, spacePtr);
  Bullet bullet2 = Bullet(bullet1);

  EXPECT_EQ(bullet1, bullet2);
}
