#include "gtest/gtest.h"
#include "game_entity.hpp"
#include <unordered_set>

TEST(game_entity_test, test_construction)
{
  Point2D leftBottomCorner(1.0f, 3.0f);
  Point2D rightTopCorner(2.0f, 5.0f);
  Box2D box(leftBottomCorner, rightTopCorner);
  Direction2D direction(1.0f, 1.0f);
  std::weak_ptr<Space> spacePtr = std::make_shared<Space>(Space());

  GameEntity gameEntity1 = GameEntity(box, direction, 1.0f, 15, spacePtr);
  EXPECT_EQ(gameEntity1.box(), box);
  EXPECT_EQ(gameEntity1.direction(), direction);
  EXPECT_EQ(gameEntity1.spacePtr().lock(), spacePtr.lock());
  EXPECT_EQ(gameEntity1.velocity(), 1.0f);
  EXPECT_EQ(gameEntity1.health(), 15);

  GameEntity gameEntity2 = GameEntity(gameEntity1);
  EXPECT_EQ(gameEntity2.box(), box);
  EXPECT_EQ(gameEntity2.direction(), direction);
  EXPECT_EQ(gameEntity2.spacePtr().lock(), spacePtr.lock());
  EXPECT_EQ(gameEntity2.velocity(), 1.0f);
  EXPECT_EQ(gameEntity2.health(), 15);
}

TEST(game_entity_test, test_assignment)
{
  Point2D leftBottomCorner(1.0f, 3.0f);
  Point2D rightTopCorner(2.0f, 5.0f);
  Box2D box(leftBottomCorner, rightTopCorner);
  Direction2D direction(1.0f, 1.0f);
  std::weak_ptr<Space> spacePtr = std::make_shared<Space>(Space());

  GameEntity gameEntity1 = GameEntity(box, direction, 1.0f, 15, spacePtr);
  EXPECT_EQ(gameEntity1.box(), box);
  EXPECT_EQ(gameEntity1.direction(), direction);
  EXPECT_EQ(gameEntity1.spacePtr().lock(), spacePtr.lock());
  EXPECT_EQ(gameEntity1.velocity(), 1.0f);
  EXPECT_EQ(gameEntity1.health(), 15);

  GameEntity gameEntity2 = gameEntity1;
  EXPECT_EQ(gameEntity2.box(), box);
  EXPECT_EQ(gameEntity2.direction(), direction);
  EXPECT_EQ(gameEntity2.spacePtr().lock(), spacePtr.lock());
  EXPECT_EQ(gameEntity2.velocity(), 1.0f);
  EXPECT_EQ(gameEntity2.health(), 15);
}

TEST(game_entity_test, test_equality)
{
  Point2D leftBottomCorner(1.0f, 3.0f);
  Point2D rightTopCorner(2.0f, 5.0f);
  Box2D box(leftBottomCorner, rightTopCorner);
  Direction2D direction(1.0f, 1.0f);
  std::weak_ptr<Space> spacePtr = std::make_shared<Space>(Space());

  GameEntity gameEntity1 = GameEntity(box, direction, 1.0f, 15, spacePtr);
  GameEntity gameEntity2 = GameEntity(gameEntity1);
  EXPECT_EQ(gameEntity1, gameEntity2);
}

TEST(game_entity_test, test_coordinates)
{
  Point2D leftBottomCorner(1.0f, 3.0f);
  Point2D rightTopCorner(3.0f, 5.0f);
  Box2D box(leftBottomCorner, rightTopCorner);
  Direction2D direction(1.0f, 1.0f);
  std::weak_ptr<Space> spacePtr = std::make_shared<Space>(Space());

  GameEntity gameEntity = GameEntity(box, direction, 1.0f, 15, spacePtr);
  EXPECT_EQ(gameEntity.Сoordinates(), Point2D(2.0f, 4.0f));
}
