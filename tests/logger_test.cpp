#include "gtest/gtest.h"
#include "logger.hpp"
#include "box2d.hpp"
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
  //
}

TEST(logger_test, test_ray2d)
{
  //
}
