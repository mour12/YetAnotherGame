#include "gtest/gtest.h"
#include "logger.hpp"
#include "gun.hpp"
#include "alien.hpp"
#include "bullet.hpp"
#include "obstacle.hpp"
#include "space.hpp"
#include <vector>
#include <sstream>
#include <fstream>
#include <unordered_set>

Logger & logger = Logger::GetInstance();

TEST(logger_test, test_point2d)
{
  std::stringstream ss1;
  std::stringstream ss2;
  std::string str = " : Point2D {0, 0}";

  Point2D p1;
  logger.Log(ss2, p1);

  auto now = std::chrono::system_clock::now();
  auto now_c = std::chrono::system_clock::to_time_t(now);
  ss1 << std::put_time(std::localtime(&now_c), "%c");
  ss1 << str << std::endl;

  EXPECT_EQ(ss1.str(), ss2.str());
}

TEST(logger_test, test_log_to_file)
{
  std::stringstream ss;
  std::string res;
  std::string str = " : Point2D {0, 0}";

  Point2D p1;
  std::ofstream fos("log.txt");
  if (fos.is_open())
  {
    logger.Log(fos, p1);
    fos.close();
  }
  std::ifstream fis("log.txt");
  if (fis.is_open())
  {
    std::getline(fis, res);
    fis.close();
  }
  auto now = std::chrono::system_clock::now();
  auto now_c = std::chrono::system_clock::to_time_t(now);
  ss << std::put_time(std::localtime(&now_c), "%c");
  ss << str << std::endl;
  res += '\n';

  EXPECT_EQ(res, ss.str());
}

TEST(logger_test, test_vector_of_point2d)
{
  std::stringstream ss1;
  std::stringstream ss2;
  std::string str = " : Collection {Point2D {0, 0}; Point2D {0, 0}; Point2D {0, 0}; Point2D {0, 0}; }";

  Point2D p1;
  Point2D p2;
  Point2D p3;
  Point2D p4;
  std::vector<Point2D> v = {p1, p2, p3, p4};
  logger.Log(ss2, v);

  auto now = std::chrono::system_clock::now();
  auto now_c = std::chrono::system_clock::to_time_t(now);
  ss1 << std::put_time(std::localtime(&now_c), "%c");
  ss1 << str << std::endl;

  EXPECT_EQ(ss1.str(), ss2.str());
}

TEST(logger_test, test_box2d)
{
  std::stringstream ss1;
  std::stringstream ss2;
  std::string str = " : Box2D {Point2D {0, 0}, Point2D {0, 0}}";

  Box2D b;
  logger.Log(ss2, b);

  auto now = std::chrono::system_clock::now();
  auto now_c = std::chrono::system_clock::to_time_t(now);
  ss1 << std::put_time(std::localtime(&now_c), "%c");
  ss1 << str << std::endl;

  EXPECT_EQ(ss1.str(), ss2.str());
}

TEST(logger_test, test_ray2d)
{
  std::stringstream ss1;
  std::stringstream ss2;
  std::string str = " : Ray2D {Origin {0, 0}, Direction2D {1, 0}}";

  Ray2D r;
  logger.Log(ss2, r);

  auto now = std::chrono::system_clock::now();
  auto now_c = std::chrono::system_clock::to_time_t(now);
  ss1 << std::put_time(std::localtime(&now_c), "%c");
  ss1 << str << std::endl;

  EXPECT_EQ(ss1.str(), ss2.str());
}

TEST(logger_test, test_gun)
{
  std::stringstream ss1;
  std::stringstream ss2;
  std::string str = " : Gun {Box2D {Point2D {1, 3}, Point2D {2, 5}}, Point2D {1.5, 4}, Direction2D {0.707107, 0.707107}, 1, 15}";

  Point2D leftBottomCorner(1.0f, 3.0f);
  Point2D rightTopCorner(2.0f, 5.0f);
  Box2D box(leftBottomCorner, rightTopCorner);
  Direction2D direction(1.0f, 1.0f);
  std::weak_ptr<Space> spacePtr = std::make_shared<Space>(Space());

  Gun gun = Gun(box, direction, 1.0f, 15, spacePtr);
  logger.Log(ss2, gun);

  auto now = std::chrono::system_clock::now();
  auto now_c = std::chrono::system_clock::to_time_t(now);
  ss1 << std::put_time(std::localtime(&now_c), "%c");
  ss1 << str << std::endl;

  EXPECT_EQ(ss1.str(), ss2.str());
}

TEST(logger_test, test_alien)
{
  std::stringstream ss1;
  std::stringstream ss2;
  std::string str = " : Alien {Box2D {Point2D {1, 3}, Point2D {2, 5}}, Point2D {1.5, 4}, Ray2D {Origin {1.5, 3}, Direction2D {0, -1}}, Direction2D {0.707107, 0.707107}, 1, 15}";

  Point2D leftBottomCorner(1.0f, 3.0f);
  Point2D rightTopCorner(2.0f, 5.0f);
  Box2D box(leftBottomCorner, rightTopCorner);
  Direction2D direction(1.0f, 1.0f);
  Ray2D route(Point2D(1.5f, 3.0f), Direction2D(0.0f, -1.0f));
  std::weak_ptr<Space> spacePtr = std::make_shared<Space>(Space());

  Alien alien = Alien(box, direction, 1.0f, 15, route, spacePtr);
  logger.Log(ss2, alien);

  auto now = std::chrono::system_clock::now();
  auto now_c = std::chrono::system_clock::to_time_t(now);
  ss1 << std::put_time(std::localtime(&now_c), "%c");
  ss1 << str << std::endl;

  EXPECT_EQ(ss1.str(), ss2.str());
}

TEST(logger_test, test_bullet)
{
  std::stringstream ss1;
  std::stringstream ss2;
  std::string str = " : Bullet {Box2D {Point2D {1, 3}, Point2D {2, 5}}, Point2D {1.5, 4}, Direction2D {0.707107, 0.707107}, 1, 15}";

  Point2D leftBottomCorner(1.0f, 3.0f);
  Point2D rightTopCorner(2.0f, 5.0f);
  Box2D box(leftBottomCorner, rightTopCorner);
  Direction2D direction(1.0f, 1.0f);
  std::weak_ptr<Space> spacePtr = std::make_shared<Space>(Space());

  Bullet bullet = Bullet(box, direction, 1.0f, 15, spacePtr);
  logger.Log(ss2, bullet);

  auto now = std::chrono::system_clock::now();
  auto now_c = std::chrono::system_clock::to_time_t(now);
  ss1 << std::put_time(std::localtime(&now_c), "%c");
  ss1 << str << std::endl;

  EXPECT_EQ(ss1.str(), ss2.str());
}

TEST(logger_test, test_obstacle)
{
  std::stringstream ss1;
  std::stringstream ss2;
  std::string str = " : Obstacle {Box2D {Point2D {1, 3}, Point2D {2, 5}}, Point2D {1.5, 4}, 15}";

  Point2D leftBottomCorner(1.0f, 3.0f);
  Point2D rightTopCorner(2.0f, 5.0f);
  Box2D box(leftBottomCorner, rightTopCorner);
  std::weak_ptr<Space> spacePtr = std::make_shared<Space>(Space());

  Obstacle obstacle = Obstacle(box, 15, spacePtr);
  logger.Log(ss2, obstacle);

  auto now = std::chrono::system_clock::now();
  auto now_c = std::chrono::system_clock::to_time_t(now);
  ss1 << std::put_time(std::localtime(&now_c), "%c");
  ss1 << str << std::endl;

  EXPECT_EQ(ss1.str(), ss2.str());
}

TEST(logger_test, test_space)
{
  std::stringstream ss1;
  std::stringstream ss2;
  std::string str = " : Space {100, 100, GameEntities {Bullet {Box2D {Point2D {1, 3}, Point2D {2, 5}}, Point2D {1.5, 4}, Direction2D {1, 0}, 1, 15}, Alien {Box2D {Point2D {1, 3}, Point2D {2, 5}}, Point2D {1.5, 4}, Ray2D {Origin {1.5, 3}, Direction2D {0, -1}}, Direction2D {1, 0}, 1, 15}, Gun {Box2D {Point2D {1, 3}, Point2D {2, 5}}, Point2D {1.5, 4}, Direction2D {1, 0}, 1, 15}, }}";

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

  space.AddGameEntity(std::make_shared<Bullet>(bullet));
  space.AddGameEntity(std::make_shared<Alien>(alien));
  space.AddGameEntity(std::make_shared<Gun>(gun));

  logger.Log(ss2, space);

  auto now = std::chrono::system_clock::now();
  auto now_c = std::chrono::system_clock::to_time_t(now);
  ss1 << std::put_time(std::localtime(&now_c), "%c");
  ss1 << str << std::endl;

  EXPECT_EQ(ss1.str(), ss2.str());
}
