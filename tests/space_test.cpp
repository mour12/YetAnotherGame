#include "gtest/gtest.h"
#include "space.hpp"
#include "gun.hpp"
#include <unordered_set>

TEST(space_test, test_construction)
{
  Space space1 = Space();
  EXPECT_EQ(space1.sizeX(), 0.0f);
  EXPECT_EQ(space1.sizeY(), 0.0f);
  EXPECT_EQ(space1.gameEntities().size(), 0);

  Space space2 = Space(100.0f, 100.0f);
  EXPECT_EQ(space2.sizeX(), 100.0f);
  EXPECT_EQ(space2.sizeY(), 100.0f);
  EXPECT_EQ(space2.gameEntities().size(), 0);
}

TEST(space_test, test_adding_game_entity)
{
  Space space = Space(100.0f, 100.0f);

  Point2D leftBottomCorner(1.0f, 3.0f);
  Point2D rightTopCorner(2.0f, 5.0f);
  Box2D box(leftBottomCorner, rightTopCorner);
  Direction2D direction(1.0f, 0.0f);
  std::weak_ptr<Space> spacePtr = std::make_shared<Space>(space);
  Gun gun = Gun(box, direction, 1.0f, 15, spacePtr);

  space.AddGameEntity(std::make_shared<Gun>(gun));
  EXPECT_EQ(space.sizeX(), 100.0f);
  EXPECT_EQ(space.sizeY(), 100.0f);
  EXPECT_EQ(space.gameEntities().size(), 1);
  EXPECT_EQ(*(space.gameEntities()[0]), gun);

  try
  {
    space.AddGameEntity(nullptr);
    FAIL() << std::string("Expected invalid_argument");
  }
  catch (std::invalid_argument const & ex)
  {
    EXPECT_EQ(ex.what(), std::string("Trying to add nullptr!"));
  }
  catch (...)
  {
    FAIL() << std::string("Expected invalid_argument");
  }

}
