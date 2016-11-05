#include "gtest/gtest.h"
#include "game_entity_factory.hpp"
#include "gun.hpp"
#include "alien.hpp"
#include "bullet.hpp"
#include "obstacle.hpp"
#include "space.hpp"
#include <vector>
#include <sstream>
#include <unordered_set>

GameEntityFactory factory;

TEST(game_entity_factory_test, test_gun)
{
  Point2D leftBottomCorner(1.0f, 3.0f);
  Point2D rightTopCorner(2.0f, 5.0f);
  Box2D box(leftBottomCorner, rightTopCorner);
  Direction2D direction(1.0f, 1.0f);
  std::weak_ptr<Space> spacePtr = std::make_shared<Space>(Space());

  Gun gun1 = Gun(box, direction, 1.0f, 15, spacePtr);

  factory.Register(Gun().Create());
  auto gun2 = static_unique_ptr_cast<Gun>(factory.Create(FactoryType::GunType, box, direction, 1.0f, 15, spacePtr));

  EXPECT_EQ(gun1, *gun2);
}

TEST(game_entity_factory_test, test_alien)
{
  Point2D leftBottomCorner(1.0f, 3.0f);
  Point2D rightTopCorner(2.0f, 5.0f);
  Box2D box(leftBottomCorner, rightTopCorner);
  Direction2D direction(1.0f, 1.0f);
  Ray2D route(Point2D(1.5f, 3.0f), Direction2D(0.0f, -1.0f));
  std::weak_ptr<Space> spacePtr = std::make_shared<Space>(Space());

  Alien alien1 = Alien(box, direction, 1.0f, 15, route, spacePtr);

  factory.Register(Alien().Create());
  auto alien2 = static_unique_ptr_cast<Alien>(factory.Create(FactoryType::AlienType, box, direction, 1.0f, 15, route, spacePtr));

  EXPECT_EQ(alien1, *alien2);
}

TEST(game_entity_factory_test, test_bullet)
{
  Point2D leftBottomCorner(1.0f, 3.0f);
  Point2D rightTopCorner(2.0f, 5.0f);
  Box2D box(leftBottomCorner, rightTopCorner);
  Direction2D direction(1.0f, 1.0f);
  std::weak_ptr<Space> spacePtr = std::make_shared<Space>(Space());

  Bullet bullet1 = Bullet(box, direction, 1.0f, 15, spacePtr);

  factory.Register(Bullet().Create());
  auto bullet2 = static_unique_ptr_cast<Bullet>(factory.Create(FactoryType::BulletType, box, direction, 1.0f, 15, spacePtr));

  EXPECT_EQ(bullet1, *bullet2);
}

TEST(game_entity_factory_test, test_obstacle)
{
  Point2D leftBottomCorner(1.0f, 3.0f);
  Point2D rightTopCorner(2.0f, 5.0f);
  Box2D box(leftBottomCorner, rightTopCorner);
  std::weak_ptr<Space> spacePtr = std::make_shared<Space>(Space());

  Obstacle obstacle1 = Obstacle(box, 15, spacePtr);

  factory.Register(Obstacle().Create());
  auto obstacle2 = static_unique_ptr_cast<Obstacle>(factory.Create(FactoryType::ObstacleType, box, 15, spacePtr));

  EXPECT_EQ(obstacle1, *obstacle2);
}

