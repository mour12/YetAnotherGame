#include "gtest/gtest.h"
#include "space.hpp"
#include "game_entity.hpp"
#include <unordered_set>

TEST(space_test, test_construction)
{
  Space space1 = Space();
  EXPECT_EQ(space1.sizeX(), 0.0f);
  EXPECT_EQ(space1.sizeY(), 0.0f);
  EXPECT_EQ(space1.gameEntities().size(), 0);

  Space space2 = Space(100.0f, 100.0f);

  Point2D leftBottomCorner(1.0f, 3.0f);
  Point2D rightTopCorner(2.0f, 5.0f);
  Box2D box(leftBottomCorner, rightTopCorner);
  Direction2D direction(1.0f, 0.0f);
  std::weak_ptr<Space> spacePtr = std::make_shared<Space>(space2);
  GameEntity gameEntity = GameEntity(box, direction, 1.0f, 15, spacePtr);

  space2.gameEntities().push_back(std::make_shared<GameEntity>(gameEntity));
  EXPECT_EQ(space2.sizeX(), 100.0f);
  EXPECT_EQ(space2.sizeY(), 100.0f);
  EXPECT_EQ(space2.gameEntities().size(), 1);
  EXPECT_EQ(*(space2.gameEntities()[0]), gameEntity);
}
