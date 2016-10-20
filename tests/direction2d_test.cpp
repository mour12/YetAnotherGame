#include "gtest/gtest.h"
#include "direction2d.hpp"

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

  try
  {
    Direction2D d4 = { 0.0f, 0.0f };
    FAIL() << "Expected std::invalid_argument";
  }
  catch(std::invalid_argument const & ex)
  {
    EXPECT_EQ(ex.what(),std::string("Length is equal to zero!"));
  }
  catch(...)
  {
    FAIL() << "Expected std::invalid_argument";
  }
}

TEST(direction2d_test, test_initializer_list)
{
  Direction2D d1 = { 3.0f, 4.0f, 5.0f };
  EXPECT_FLOAT_EQ(d1.x(), 0.6f);
  EXPECT_FLOAT_EQ(d1.y(), 0.8f);

  Direction2D d2 = { 2.0f };
  EXPECT_FLOAT_EQ(d2.x(), 1.0f);
  EXPECT_FLOAT_EQ(d2.y(), 0.0f);

  try
  {
    Direction2D d3 = { 0.0f };
    FAIL() << "Expected std::invalid_argument";
  }
  catch(std::invalid_argument const & ex)
  {
    EXPECT_EQ(ex.what(),std::string("Length is equal to zero!"));
  }
  catch(...)
  {
    FAIL() << "Expected std::invalid_argument";
  }
}

TEST(direction2d_test, test_assignment)
{
  Direction2D d1;
  d1 = { 3.6f, 4.8f };
  EXPECT_FLOAT_EQ(d1.x(), 0.6f);
  EXPECT_FLOAT_EQ(d1.y(), 0.8f);

  try
  {
    Direction2D d2;
    d2 = { 0.0f, 0.0f };
    FAIL() << "Expected std::invalid_argument";
  }
  catch(std::invalid_argument const & ex)
  {
    EXPECT_EQ(ex.what(),std::string("Length is equal to zero!"));
  }
  catch(...)
  {
    FAIL() << "Expected std::invalid_argument";
  }
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

  try
  {
    Direction2D d3 = { 1.0f, 1.0f };
    Direction2D d4 = { -1.0f, -1.0f };
    Direction2D d5 = d3 + d4;
    FAIL() << "Expected std::invalid_argument";
  }
  catch(std::invalid_argument const & ex)
  {
    EXPECT_EQ(ex.what(),std::string("Length is equal to zero!"));
  }
  catch(...)
  {
    FAIL() << "Expected std::invalid_argument";
  }

  try
  {
    Direction2D d3 = { 1.0f, 1.0f };
    Direction2D d4 = { 1.0f, 1.0f };
    Direction2D d5 = d3 - d4;
    FAIL() << "Expected std::invalid_argument";
  }
  catch(std::invalid_argument const & ex)
  {
    EXPECT_EQ(ex.what(),std::string("Length is equal to zero!"));
  }
  catch(...)
  {
    FAIL() << "Expected std::invalid_argument";
  }

  try
  {
    Direction2D d3 = { 1.0f, 1.0f };
    Direction2D d4 = { -1.0f, -1.0f };
    d3 += d4;
    FAIL() << "Expected std::invalid_argument";
  }
  catch (std::invalid_argument const & ex)
  {
    EXPECT_EQ(ex.what(),std::string("Length is equal to zero!"));
  }
  catch (...)
  {
    FAIL() << "Expected std::invalid_argument";
  }

  try
  {
    Direction2D d3 = { 1.0f, 1.0f };
    Direction2D d4 = { 1.0f, 1.0f };
    d3 -= d4;
    FAIL() << "Expected std::invalid_argument";
  }
  catch(std::invalid_argument const & ex)
  {
    EXPECT_EQ(ex.what(),std::string("Length is equal to zero!"));
  }
  catch(...)
  {
    FAIL() << "Expected std::invalid_argument";
  }
}

TEST(direction2d_test, test_output)
{
  std::stringstream s;
  s << Direction2D(0.6f, 0.8f);
  EXPECT_EQ(s.str(), "Direction2D {0.6, 0.8}");
}
