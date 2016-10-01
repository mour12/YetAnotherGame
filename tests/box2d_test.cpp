#include "gtest/gtest.h"
#include "box2d.hpp"
#include <sstream>
#include <unordered_set>

TEST(box2d_test, test_construction)
{
  Box2D b1;
  EXPECT_EQ(b1.leftLowCorner().x(), 0.0f);
  EXPECT_EQ(b1.leftLowCorner().y(), 0.0f);
  EXPECT_EQ(b1.rightUpCorner().x(), 0.0f);
  EXPECT_EQ(b1.rightUpCorner().y(), 0.0f);

  Point2D p1 = { 1.2f, 2.4f };
  Point2D p2 = { 2.2f, 4.4f };
  Box2D b2 = Box2D(p1, p2);
  EXPECT_EQ(b2.leftLowCorner().x(), 1.2f);
  EXPECT_EQ(b2.leftLowCorner().y(), 2.4f);
  EXPECT_EQ(b2.rightUpCorner().x(), 2.2f);
  EXPECT_EQ(b2.rightUpCorner().y(), 4.4f);

  Box2D b3 = b2;
  EXPECT_EQ(b3, b2);
}

TEST(box2d_test, test_moving)
{
  Point2D p1 = { 1.0f, 2.0f };
  Point2D p2 = { 2.0f, 3.0f };
  Box2D b1 = { p1, p2 };
  Box2D b2 = std::move(b1);

  EXPECT_EQ(b2.leftLowCorner().x(), 1.0f);
  EXPECT_EQ(b2.leftLowCorner().y(), 2.0f);
  EXPECT_EQ(b2.rightUpCorner().x(), 2.0f);
  EXPECT_EQ(b2.rightUpCorner().y(), 3.0f);

  EXPECT_EQ(b1.leftLowCorner().x(), 0.0f);
  EXPECT_EQ(b1.leftLowCorner().y(), 0.0f);
  EXPECT_EQ(b1.rightUpCorner().x(), 0.0f);
  EXPECT_EQ(b1.rightUpCorner().y(), 0.0f);
}

TEST(box2d_test, test_initializer_list)
{
  Point2D p1 = { 1.0f, 2.0f };
  Point2D p2 = { 2.0f, 3.0f };
  Point2D p3 = { 3.0f, 4.0f };

  Box2D b1 = { p1, p2 };
  EXPECT_EQ(b1.leftLowCorner().x(), 1.0f);
  EXPECT_EQ(b1.leftLowCorner().y(), 2.0f);
  EXPECT_EQ(b1.rightUpCorner().x(), 2.0f);
  EXPECT_EQ(b1.rightUpCorner().y(), 3.0f);

  Box2D b2 = { p1, p2, p3 };
  EXPECT_EQ(b2.leftLowCorner().x(), 1.0f);
  EXPECT_EQ(b2.leftLowCorner().y(), 2.0f);
  EXPECT_EQ(b2.rightUpCorner().x(), 2.0f);
  EXPECT_EQ(b2.rightUpCorner().y(), 3.0f);

  Box2D b3 = { p1 };
  EXPECT_EQ(b3.leftLowCorner().x(), 1.0f);
  EXPECT_EQ(b3.leftLowCorner().y(), 2.0f);
  EXPECT_EQ(b3.rightUpCorner().x(), 0.0f);
  EXPECT_EQ(b3.rightUpCorner().y(), 0.0f);
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

TEST(box2d_test, test_area)
{
  Point2D p1 = { 1.0f, 2.0f };
  Point2D p2 = { 3.0f, 4.0f };
  Point2D p3 = { 1.1f, 2.2f };
  Point2D p4 = { 3.3f, 4.4f };
  Box2D b1 = { p1, p2 };
  Box2D b2 = { p3, p4 };
  EXPECT_FLOAT_EQ(b1.area(), 4.0);
  EXPECT_FLOAT_EQ(b2.area(), 4.84);
}

TEST(box2d_test, test_perimeter)
{
  Point2D p1 = { 1.0f, 2.0f };
  Point2D p2 = { 3.0f, 4.0f };
  Point2D p3 = { 1.1f, 2.2f };
  Point2D p4 = { 3.3f, 4.4f };
  Box2D b1 = { p1, p2 };
  Box2D b2 = { p3, p4 };
  EXPECT_FLOAT_EQ(b1.perimeter(), 8.0);
  EXPECT_FLOAT_EQ(b2.perimeter(), 8.8);
}
