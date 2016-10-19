#include "gtest/gtest.h"
#include "alien.hpp"
#include <unordered_set>

TEST(alien_test, test_construction)
{
  Alien alien1 = Alien();
  EXPECT_EQ(alien1.box(), Box2D());
  EXPECT_EQ(alien1.direction(), Direction2D());
  EXPECT_EQ(alien1.spacePtr().lock(), nullptr);
  EXPECT_EQ(alien1.velocity(), 0.0f);
  EXPECT_EQ(alien1.health(), 1);

  Point2D leftBottomCorner(1.0f, 3.0f);
  Point2D rightTopCorner(2.0f, 5.0f);
  Box2D box(leftBottomCorner, rightTopCorner);
  Direction2D direction(1.0f, 1.0f);
  Ray2D route(Point2D(1.5f, 3.0f), Direction2D(0.0f, -1.0f));
  std::weak_ptr<Space> spacePtr = std::make_shared<Space>(Space());

  Alien alien2 = Alien(box, direction, 1.0f, 15, route, spacePtr);
  EXPECT_EQ(alien2.box(), box);
  EXPECT_EQ(alien2.direction(), direction);
  EXPECT_EQ(alien2.spacePtr().lock(), spacePtr.lock());
  EXPECT_EQ(alien2.velocity(), 1.0f);
  EXPECT_EQ(alien2.health(), 15);
  EXPECT_EQ(alien2.route(), route);

  Alien alien3 = Alien(alien2);
  EXPECT_EQ(alien3.box(), box);
  EXPECT_EQ(alien3.direction(), direction);
  EXPECT_EQ(alien3.spacePtr().lock(), spacePtr.lock());
  EXPECT_EQ(alien3.velocity(), 1.0f);
  EXPECT_EQ(alien3.health(), 15);
  EXPECT_EQ(alien3.route(), route);
}

TEST(alien_test, test_assignment)
{
  Point2D leftBottomCorner(1.0f, 3.0f);
  Point2D rightTopCorner(2.0f, 5.0f);
  Box2D box(leftBottomCorner, rightTopCorner);
  Direction2D direction(1.0f, 1.0f);
  Ray2D route(Point2D(1.5f, 3.0f), Direction2D(0.0f, -1.0f));
  std::weak_ptr<Space> spacePtr = std::make_shared<Space>(Space());

  Alien alien1 = Alien(box, direction, 1.0f, 15, route, spacePtr);
  EXPECT_EQ(alien1.box(), box);
  EXPECT_EQ(alien1.direction(), direction);
  EXPECT_EQ(alien1.spacePtr().lock(), spacePtr.lock());
  EXPECT_EQ(alien1.velocity(), 1.0f);
  EXPECT_EQ(alien1.health(), 15);
  EXPECT_EQ(alien1.route(), route);

  Alien alien2 = alien1;
  EXPECT_EQ(alien2.box(), box);
  EXPECT_EQ(alien2.direction(), direction);
  EXPECT_EQ(alien2.spacePtr().lock(), spacePtr.lock());
  EXPECT_EQ(alien2.velocity(), 1.0f);
  EXPECT_EQ(alien2.health(), 15);
  EXPECT_EQ(alien2.route(), route);
}

TEST(alien_test, test_equality)
{
  Point2D leftBottomCorner(1.0f, 3.0f);
  Point2D rightTopCorner(2.0f, 5.0f);
  Box2D box(leftBottomCorner, rightTopCorner);
  Direction2D direction(1.0f, 1.0f);
  Ray2D route(Point2D(1.5f, 3.0f), Direction2D(0.0f, -1.0f));
  std::weak_ptr<Space> spacePtr = std::make_shared<Space>(Space());

  Alien alien1 = Alien(box, direction, 1.0f, 15, route, spacePtr);
  Alien alien2 = Alien(alien1);
  EXPECT_EQ(alien1, alien2);
}

TEST(alien_test, test_coordinates)
{
  Point2D leftBottomCorner(1.0f, 3.0f);
  Point2D rightTopCorner(3.0f, 5.0f);
  Box2D box(leftBottomCorner, rightTopCorner);
  Direction2D direction(1.0f, 1.0f);
  Ray2D route(Point2D(1.5f, 3.0f), Direction2D(0.0f, -1.0f));
  std::weak_ptr<Space> spacePtr = std::make_shared<Space>(Space());

  Alien alien = Alien(box, direction, 1.0f, 15, route, spacePtr);
  EXPECT_EQ(alien.Сoordinates(), Point2D(2.0f, 4.0f));
}

TEST(alien_test, test_shooting)
{
  std::shared_ptr<Space> spacePtr = std::make_shared<Space>(Space(100, 100));

  Point2D boxLeftBottomCorner(10.0f, 30.0f);
  Point2D boxRightTopCorner(30.0f, 50.0f);
  Box2D box(boxLeftBottomCorner, boxRightTopCorner);
  Direction2D direction(1.0f, 1.0f);
  Ray2D route(Point2D(20.0f, 30.0f), Direction2D(0.0f, -1.0f));

  Alien alien = Alien(box, direction, 1.0f, 15, route, spacePtr);
  spacePtr->AddGameEntity(std::make_shared<GameEntity>(static_cast<GameEntity>(alien)));
  alien.Shoot();

  Point2D bulletLeftBottomCorner(17.0f, 24.0f);
  Point2D bulletRightTopCorner(23.0f, 30.0f);
  Direction2D bulletDirection(0.0f, -1.0f);
  Box2D bulletBox(bulletLeftBottomCorner, bulletRightTopCorner);
  Bullet bullet(bulletBox, bulletDirection, 10.0f, 1, spacePtr);

  EXPECT_EQ(spacePtr->gameEntities().size(), 2);
  EXPECT_EQ(*(spacePtr->gameEntities()[0]), alien);
  EXPECT_EQ(*(spacePtr->gameEntities()[1]), bullet);
}
