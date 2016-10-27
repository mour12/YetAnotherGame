#include "gtest/gtest.h"
#include "logger.hpp"
#include "gun.hpp"
#include "alien.hpp"
#include "bullet.hpp"
#include "obstacle.hpp"
#include "space.hpp"
#include <vector>
#include <sstream>
#include <unordered_set>

Logger& logger = Logger::getInstance();

TEST(logger_test, test_point2d)
{
  Point2D p1;
  logger.log(std::cout, p1);
}

TEST(logger_test, test_vector_of_point2d)
{
  Point2D p1;
  Point2D p2;
  Point2D p3;
  Point2D p4;
  std::vector<Point2D> v = {p1, p2, p3, p4};
  logger.log(std::cout, v);
}

TEST(logger_test, test_box2d)
{
  Box2D b;
  logger.log(std::cout, b);
}

TEST(logger_test, test_ray2d)
{
  Ray2D r;
  logger.log(std::cout, r);
}

TEST(logger_test, test_gun)
{
  Point2D leftBottomCorner(1.0f, 3.0f);
  Point2D rightTopCorner(2.0f, 5.0f);
  Box2D box(leftBottomCorner, rightTopCorner);
  Direction2D direction(1.0f, 1.0f);
  std::weak_ptr<Space> spacePtr = std::make_shared<Space>(Space());

  Gun gun = Gun(box, direction, 1.0f, 15, spacePtr);
  logger.log(std::cout, gun);
}

TEST(logger_test, test_alien)
{
  Point2D leftBottomCorner(1.0f, 3.0f);
  Point2D rightTopCorner(2.0f, 5.0f);
  Box2D box(leftBottomCorner, rightTopCorner);
  Direction2D direction(1.0f, 1.0f);
  Ray2D route(Point2D(1.5f, 3.0f), Direction2D(0.0f, -1.0f));
  std::weak_ptr<Space> spacePtr = std::make_shared<Space>(Space());

  Alien alien = Alien(box, direction, 1.0f, 15, route, spacePtr);
  logger.log(std::cout, alien);
}

TEST(logger_test, test_bullet)
{
  Point2D leftBottomCorner(1.0f, 3.0f);
  Point2D rightTopCorner(2.0f, 5.0f);
  Box2D box(leftBottomCorner, rightTopCorner);
  Direction2D direction(1.0f, 1.0f);
  std::weak_ptr<Space> spacePtr = std::make_shared<Space>(Space());

  Bullet bullet = Bullet(box, direction, 1.0f, 15, spacePtr);
  logger.log(std::cout, bullet);
}

TEST(logger_test, test_obstacle)
{
  Point2D leftBottomCorner(1.0f, 3.0f);
  Point2D rightTopCorner(2.0f, 5.0f);
  Box2D box(leftBottomCorner, rightTopCorner);
  std::weak_ptr<Space> spacePtr = std::make_shared<Space>(Space());

  Obstacle obstacle = Obstacle(box, 15, spacePtr);
  logger.log(std::cout, obstacle);
}

TEST(logger_test, test_space)
{
    Space space = Space(100.0f, 100.0f);

    Point2D leftBottomCorner(1.0f, 3.0f);
    Point2D rightTopCorner(2.0f, 5.0f);
    Box2D box(leftBottomCorner, rightTopCorner);
    Ray2D route(Point2D(1.5f, 3.0f), Direction2D(0.0f, -1.0f));
    Direction2D direction(1.0f, 0.0f);
    std::weak_ptr<Space> spacePtr = std::make_shared<Space>(space);
    Bullet bullet = Bullet(box, direction, 1.0f, 15, spacePtr);
    Alien alien = Alien(box, direction, 1.0f, 15, route, spacePtr);
    Gun gun = Gun(box, direction, 1.0f, 15, spacePtr);
    space.AddGameEntity(std::make_shared<GameEntity>(bullet));
    space.AddGameEntity(std::make_shared<GameEntity>(alien));
    space.AddGameEntity(std::make_shared<GameEntity>(gun));

    logger.log(std::cout, space);
}
