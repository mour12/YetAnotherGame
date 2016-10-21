#include "gtest/gtest.h"
#include "obstacle.hpp"
#include <unordered_set>

TEST(obstacle_test, test_construction)
{
  Point2D leftBottomCorner(1.0f, 3.0f);
  Point2D rightTopCorner(2.0f, 5.0f);
  Box2D box(leftBottomCorner, rightTopCorner);
  std::weak_ptr<Space> spacePtr;
  spacePtr = std::make_shared<Space>(Space());

  Obstacle obstacle1 = Obstacle(box, 15, spacePtr);
  EXPECT_EQ(obstacle1.box(), box);
  EXPECT_EQ(obstacle1.direction(), Direction2D());
  EXPECT_EQ(obstacle1.spacePtr().lock(), spacePtr.lock());
  EXPECT_EQ(obstacle1.velocity(), 0.0f);
  EXPECT_EQ(obstacle1.health(), 15);

  Obstacle obstacle2 = Obstacle(obstacle1);
  EXPECT_EQ(obstacle2.box(), box);
  EXPECT_EQ(obstacle2.direction(), Direction2D());
  EXPECT_EQ(obstacle2.spacePtr().lock(), spacePtr.lock());
  EXPECT_EQ(obstacle2.velocity(), 0.0f);
  EXPECT_EQ(obstacle2.health(), 15);
}

TEST(obstacle_test, test_assignment)
{
  Point2D leftBottomCorner(1.0f, 3.0f);
  Point2D rightTopCorner(2.0f, 5.0f);
  Box2D box(leftBottomCorner, rightTopCorner);
  std::weak_ptr<Space> spacePtr;
  spacePtr = std::make_shared<Space>(Space());

  Obstacle obstacle1 = Obstacle(box, 15, spacePtr);
  EXPECT_EQ(obstacle1.box(), box);
  EXPECT_EQ(obstacle1.direction(), Direction2D());
  EXPECT_EQ(obstacle1.spacePtr().lock(), spacePtr.lock());
  EXPECT_EQ(obstacle1.velocity(), 0.0f);
  EXPECT_EQ(obstacle1.health(), 15);

  Obstacle obstacle2 = obstacle1;
  EXPECT_EQ(obstacle2.box(), box);
  EXPECT_EQ(obstacle2.direction(), Direction2D());
  EXPECT_EQ(obstacle2.spacePtr().lock(), spacePtr.lock());
  EXPECT_EQ(obstacle2.velocity(), 0.0f);
  EXPECT_EQ(obstacle2.health(), 15);
}

TEST(obstacle_test, test_equality)
{
  Point2D leftBottomCorner(1.0f, 3.0f);
  Point2D rightTopCorner(2.0f, 5.0f);
  Box2D box(leftBottomCorner, rightTopCorner);
  std::weak_ptr<Space> spacePtr;
  spacePtr = std::make_shared<Space>(Space());

  Obstacle obstacle1 = Obstacle(box, 15, spacePtr);
  Obstacle obstacle2 = Obstacle(obstacle1);
  EXPECT_EQ(obstacle1, obstacle2);
}

TEST(obstacle_test, test_coordinates)
{
  Point2D leftBottomCorner(1.0f, 3.0f);
  Point2D rightTopCorner(3.0f, 5.0f);
  Box2D box(leftBottomCorner, rightTopCorner);
  std::weak_ptr<Space> spacePtr;
  spacePtr = std::make_shared<Space>(Space());

  Obstacle obstacle = Obstacle(box, 15, spacePtr);;
  EXPECT_EQ(obstacle.Сoordinates(), Point2D(2.0f, 4.0f));
}
