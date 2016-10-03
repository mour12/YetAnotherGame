#include "gtest/gtest.h"
#include "box2d.hpp"
#include <sstream>
#include <unordered_set>

TEST(box2d_test, test_construction)
{
  Box2D b1;
  EXPECT_EQ(b1.leftBottomCorner().x(), 0.0f);
  EXPECT_EQ(b1.leftBottomCorner().y(), 0.0f);
  EXPECT_EQ(b1.rightTopCorner().x(), 0.0f);
  EXPECT_EQ(b1.rightTopCorner().y(), 0.0f);

  Point2D p1 = { 1.2f, 2.4f };
  Point2D p2 = { 2.2f, 4.4f };
  Box2D b2 = Box2D(p1, p2);
  EXPECT_EQ(b2.leftBottomCorner().x(), 1.2f);
  EXPECT_EQ(b2.leftBottomCorner().y(), 2.4f);
  EXPECT_EQ(b2.rightTopCorner().x(), 2.2f);
  EXPECT_EQ(b2.rightTopCorner().y(), 4.4f);

  Box2D b3 = b2;
  EXPECT_EQ(b3, b2);

  Box2D b4 = Box2D(p2, p1);
  EXPECT_EQ(b4, b2);
}

TEST(box2d_test, test_moving)
{
  Point2D p1 = { 1.0f, 2.0f };
  Point2D p2 = { 2.0f, 3.0f };
  Box2D b1 = { p1, p2 };
  Box2D b2 = std::move(b1);

  EXPECT_EQ(b2.leftBottomCorner().x(), 1.0f);
  EXPECT_EQ(b2.leftBottomCorner().y(), 2.0f);
  EXPECT_EQ(b2.rightTopCorner().x(), 2.0f);
  EXPECT_EQ(b2.rightTopCorner().y(), 3.0f);

  EXPECT_EQ(b1.leftBottomCorner().x(), 0.0f);
  EXPECT_EQ(b1.leftBottomCorner().y(), 0.0f);
  EXPECT_EQ(b1.rightTopCorner().x(), 0.0f);
  EXPECT_EQ(b1.rightTopCorner().y(), 0.0f);
}

TEST(box2d_test, test_initializer_list)
{
  Point2D p1 = { 1.0f, 2.0f };
  Point2D p2 = { 2.0f, 3.0f };
  Point2D p3 = { 3.0f, 4.0f };

  Box2D b1 = { p1, p2 };
  EXPECT_EQ(b1.leftBottomCorner().x(), 1.0f);
  EXPECT_EQ(b1.leftBottomCorner().y(), 2.0f);
  EXPECT_EQ(b1.rightTopCorner().x(), 2.0f);
  EXPECT_EQ(b1.rightTopCorner().y(), 3.0f);

  Box2D b2 = { p1, p2, p3 };
  EXPECT_EQ(b2.leftBottomCorner().x(), 1.0f);
  EXPECT_EQ(b2.leftBottomCorner().y(), 2.0f);
  EXPECT_EQ(b2.rightTopCorner().x(), 2.0f);
  EXPECT_EQ(b2.rightTopCorner().y(), 3.0f);

  Box2D b3 = { p1 };
  EXPECT_EQ(b3.leftBottomCorner().x(), 0.0f);
  EXPECT_EQ(b3.leftBottomCorner().y(), 0.0f);
  EXPECT_EQ(b3.rightTopCorner().x(), 1.0f);
  EXPECT_EQ(b3.rightTopCorner().y(), 2.0f);
}

TEST(box2d_test, test_assignment)
{
  Point2D p1 = { 1.0f, 2.0f };
  Point2D p2 = { 2.0f, 3.0f };
  Box2D b1;
  b1 = { p1, p2 };
  EXPECT_EQ(b1, Box2D(p1, p2));
}

TEST(box2d_test, test_equality)
{
  Point2D p1 = { 1.2f, 2.4f };
  Point2D p2 = { 2.2f, 3.4f };
  Point2D p3 = { 1.1f, 2.4f };
  Point2D p4 = { 2.2f, 3.5f };
  Box2D b1 = { p1, p2 };
  Box2D b2 = { p1, p2 };
  Box2D b3 = { p1, p4 };
  Box2D b4 = { p3, p2 };

  EXPECT_EQ(b1, b2);
  EXPECT_NE(b1, b3);
  EXPECT_LT(b1, b3);
  EXPECT_LT(b1, b4);
}

TEST(box2d_test, test_square_brackets)
{
  Point2D p1 = { 1.2f, 2.4f };
  Point2D p2 = { 3.2f, 4.4f };
  Box2D b1 = { p1, p2 };
  EXPECT_EQ(b1[0], p1);
  EXPECT_EQ(b1[1], p2);
  try
  {
    b1[2];
    FAIL() << "Expected std::out_of_range";
  }
  catch(std::out_of_range const & err)
  {
    EXPECT_EQ(err.what(),std::string("Index must be 0 or 1"));
  }
}

TEST(box2d_test, test_output)
{
  Point2D p1 = { 1.1f, 2.2f };
  Point2D p2 = { 3.3f, 4.4f };
  std::stringstream s;
  s << Box2D(p1, p2);
  EXPECT_EQ(s.str(), "Box2D {Point2D {1.1, 2.2}, Point2D {3.3, 4.4}}");
}

TEST(box2d_test, test_width)
{
  Point2D p1 = { 1.0f, 2.0f };
  Point2D p2 = { 4.0f, 4.0f };
  Box2D b1 = { p1, p2 };
  EXPECT_FLOAT_EQ(b1.Width(), 3.0f);
}

TEST(box2d_test, test_height)
{
  Point2D p1 = { 1.0f, 2.0f };
  Point2D p2 = { 4.0f, 4.0f };
  Box2D b1 = { p1, p2 };
  EXPECT_FLOAT_EQ(b1.Height(), 2.0f);
}

TEST(box2d_test, test_area)
{
  Point2D p1 = { 1.0f, 2.0f };
  Point2D p2 = { 3.0f, 4.0f };
  Point2D p3 = { 1.1f, 2.2f };
  Point2D p4 = { 3.3f, 4.4f };
  Box2D b1 = { p1, p2 };
  Box2D b2 = { p3, p4 };
  EXPECT_FLOAT_EQ(b1.Area(), 4.0f);
  EXPECT_FLOAT_EQ(b2.Area(), 4.84f);
}

TEST(box2d_test, test_perimeter)
{
  Point2D p1 = { 1.0f, 2.0f };
  Point2D p2 = { 3.0f, 4.0f };
  Point2D p3 = { 1.1f, 2.2f };
  Point2D p4 = { 3.3f, 4.4f };
  Box2D b1 = { p1, p2 };
  Box2D b2 = { p3, p4 };
  EXPECT_FLOAT_EQ(b1.Perimeter(), 8.0f);
  EXPECT_FLOAT_EQ(b2.Perimeter(), 8.8f);
}
