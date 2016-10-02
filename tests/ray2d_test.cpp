#include "gtest/gtest.h"
#include "ray2d.hpp"
#include <unordered_set>

TEST(ray2d_test, test_construction)
{
  Ray2D r1;
  EXPECT_FLOAT_EQ(r1.origin().x(), 0.0f);
  EXPECT_FLOAT_EQ(r1.origin().y(), 0.0f);
  EXPECT_FLOAT_EQ(r1.direction().x(), 1.0f);
  EXPECT_FLOAT_EQ(r1.direction().y(), 0.0f);

  Ray2D r2 = { { 1.2f, 2.4f }, { 3.6f, 4.8f } };
  EXPECT_FLOAT_EQ(r2.origin().x(), 1.2f);
  EXPECT_FLOAT_EQ(r2.origin().y(), 2.4f);
  EXPECT_FLOAT_EQ(r2.direction().x(), 0.6f);
  EXPECT_FLOAT_EQ(r2.direction().y(), 0.8f);

  Ray2D r3 = r2;
  EXPECT_EQ(r3, r2);
}

TEST(ray2d_test, test_initializer_list)
{
  Ray2D r1 = { { 1.0f, 2.0f}, { 3.0f, 4.0f }, { 5.0f, 6.0f} };
  EXPECT_FLOAT_EQ(r1.origin().x(), 1.0f);
  EXPECT_FLOAT_EQ(r1.origin().y(), 2.0f);
  EXPECT_FLOAT_EQ(r1.direction().x(), 0.6f);
  EXPECT_FLOAT_EQ(r1.direction().y(), 0.8f);

  Ray2D r2 = { { 1.0f, 2.0f } };
  EXPECT_FLOAT_EQ(r2.origin().x(), 1.0f);
  EXPECT_FLOAT_EQ(r2.origin().y(), 2.0f);
  EXPECT_FLOAT_EQ(r2.direction().x(), 1.0f);
  EXPECT_FLOAT_EQ(r2.direction().y(), 0.0f);
}

TEST(ray2d_test, test_moving)
{
  Ray2D r1 = Ray2D( { 1.2f, 2.4f }, { 0.6f, 0.8f } );
  Ray2D r2 = std::move(r1);
  EXPECT_FLOAT_EQ(r2.origin().x(), 1.2f);
  EXPECT_FLOAT_EQ(r2.origin().y(), 2.4f);
  EXPECT_FLOAT_EQ(r2.direction().x(), 0.6f);
  EXPECT_FLOAT_EQ(r2.direction().y(), 0.8f);
}

TEST(ray2d_test, test_assignment)
{
  Ray2D r1;
  r1 = { { 1.2f, 2.4f }, { 3.6f, 4.8f } };
  EXPECT_FLOAT_EQ(r1.origin().x(), 1.2f);
  EXPECT_FLOAT_EQ(r1.origin().y(), 2.4f);
  EXPECT_FLOAT_EQ(r1.direction().x(), 0.6f);
  EXPECT_FLOAT_EQ(r1.direction().y(), 0.8f);
}

TEST(ray2d_test, test_equality)
{
  Ray2D r1 = { { 1.2f, 2.4f }, { 3.6f, 4.8f } };
  Ray2D r2 = { { 1.2f, 2.4f }, { 3.6f, 4.8f } };
  Ray2D r3 = { { 1.2f, 2.5f }, { 3.6f, 4.8f } };

  EXPECT_EQ(r1, r2);
  EXPECT_NE(r1, r3);
}

TEST(ray2d_test, test_calculus)
{
  Ray2D r1 = { { 1.2f, 2.4f }, { 3.6f, 4.8f } };
  Ray2D r2 = { { 1.0f, 2.0f }, { 1.2f, 2.4f } };

  EXPECT_EQ(r1 + r2, Ray2D( { 2.2f, 4.4f }, { 0.525731112f, 0.850650808f } ));
  EXPECT_EQ(r1 - r2, Ray2D( { 0.2f, 0.4f }, { 0.850650809f, -0.525731111f } ));
  EXPECT_EQ(r1 * 2.0f, Ray2D( { 2.4f, 4.8f }, { 0.6f, 0.8f } ));
  EXPECT_EQ(r1 / 2.0f, Ray2D( { 0.6f, 1.2f }, { 0.6f, 0.8f } ));

  r1 += { { 1.2f, 2.4f }, { 1.2f, 2.4f } };
  EXPECT_EQ(r1, Ray2D( { 2.4f, 4.8f }, { 0.525731112f, 0.850650808f } ));

  r1 -= { { 1.2f, 2.4f }, { 1.2f, 2.4f } };
  EXPECT_EQ(r1, Ray2D( { 1.2f, 2.4f }, { 0.873421751f, -0.486964521f } ));

  r1 *= 2.0f;
  EXPECT_EQ(r1, Ray2D( { 2.4f, 4.8f }, { 0.873421751f, -0.486964521f } ));

  r1 /= 2.0f;
  EXPECT_EQ(r1, Ray2D( { 1.2f, 2.4f }, { 0.873421751f, -0.486964521f } ));
}

TEST(ray2d_test, test_output)
{
  std::stringstream s;
  s << Ray2D( { 1.2f, 2.4f }, { 0.6f, 0.8f } );
  EXPECT_EQ(s.str(), "Ray2D {Origin {1.2, 2.4}, Direction {0.6, 0.8}}");
}
