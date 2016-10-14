#include "gtest/gtest.h"
#include "direction2d.hpp"
//#include <unordered_set>

TEST(direction2d_test, test_construction)
{
  Direction2D d1;
  EXPECT_FLOAT_EQ(d1.x(), 1.0f);
  EXPECT_FLOAT_EQ(d1.y(), 0.0f);

  Direction2D d2 = { 3.6f, 4.8f };
  EXPECT_FLOAT_EQ(d2.x(), 0.6f);
  EXPECT_FLOAT_EQ(d2.y(), 0.8f);

  Direction2D d3 = d2;
  EXPECT_EQ(d3, d2);
}

TEST(direction2d_test, test_initializer_list)
{
  Direction2D d1 = { 3.0f, 4.0f, 5.0f };
  EXPECT_FLOAT_EQ(d1.x(), 0.6f);
  EXPECT_FLOAT_EQ(d1.y(), 0.8f);

  Direction2D d2 = { 2.0f };
  EXPECT_FLOAT_EQ(d2.x(), 1.0f);
  EXPECT_FLOAT_EQ(d2.y(), 0.0f);
}

TEST(direction2d_test, test_assignment)
{
  Direction2D d1;
  d1 = { 3.6f, 4.8f };
  EXPECT_FLOAT_EQ(d1.x(), 0.6f);
  EXPECT_FLOAT_EQ(d1.y(), 0.8f);
}

TEST(direction2d_test, test_equality)
{
  Direction2D d1 = { 3.6f, 4.8f };
  Direction2D d2 = { 3.6f, 4.8f };
  Direction2D d3 = { 4.0f, 4.8f };

  EXPECT_EQ(d1, d2);
  EXPECT_NE(d1, d3);
}

TEST(direction2d_test, test_calculus)
{
  Direction2D d1 = { 3.6f, 4.8f };
  Direction2D d2 = { 1.2f, 2.4f };

  EXPECT_EQ(d1 + d2, Direction2D(0.525731112f, 0.850650808f));
  EXPECT_EQ(d1 - d2, Direction2D(0.850650809f, -0.525731111f));

  d1 += { 1.2f, 2.4f };
  EXPECT_EQ(d1, Direction2D(0.525731112f, 0.850650808f));

  d1 -= { 1.2f, 2.4f };
  EXPECT_EQ(d1, Direction2D(0.873421751f, -0.486964521f));
}

TEST(direction2d_test, test_output)
{
  std::stringstream s;
  s << Direction2D(0.6f, 0.8f);
  EXPECT_EQ(s.str(), "Direction2D {0.6, 0.8}");
}
