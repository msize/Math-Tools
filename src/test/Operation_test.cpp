#include <gtest/gtest.h>
#include "../arithmetic/numeric/AllOperations.h"

class OperationTest: public ::testing::Test {

protected:

  virtual void SetUp() {
  }
  virtual void TearDown() {
  }

};

using arithmetic::numeric::Addition;
using arithmetic::numeric::Brackets;
using arithmetic::numeric::Const;
using arithmetic::numeric::Division;
using arithmetic::numeric::Multiplication;
using arithmetic::numeric::Subtraction;

TEST_F(OperationTest, Addition) {
  static const double increasing = 3.3;
  static const double increment = 4.4;
  static const double result = increasing + increment;
  auto s = Addition::make(
      Const::make(increasing),
      Const::make(increment));
  EXPECT_DOUBLE_EQ(result, s->evaluate());
}

TEST_F(OperationTest, Brackets) {
  static const double result = 9.9;
  auto b = Const::make(result);
  EXPECT_DOUBLE_EQ(result, b->evaluate());
}

TEST_F(OperationTest, Division) {
  static const double dividend = 7.14;
  static const double divisor = 2.1;
  static const double result = dividend / divisor;
  auto d = Division::make(
      Const::make(dividend),
      Const::make(divisor));
  EXPECT_DOUBLE_EQ(result, d->evaluate());
}

TEST_F(OperationTest, Multiplication) {
  static const double multiplier = 5.5;
  static const double multiplicand = 3.3;
  static const double result = multiplier * multiplicand;
  auto m = Multiplication::make(
      Const::make(multiplier),
      Const::make(multiplicand));
  EXPECT_DOUBLE_EQ(result, m->evaluate());
}

TEST_F(OperationTest, Subtraction) {
  static const double minuend = 8.7;
  static const double subtrahend = 9.9;
  static const double result = minuend - subtrahend;
  auto s = Subtraction::make(
      Const::make(minuend),
      Const::make(subtrahend));
  EXPECT_DOUBLE_EQ(result, s->evaluate());
}

TEST_F(OperationTest, Combination) {
  static const double v = 2.2;
  static const double result = v - (v + v * v) / v;
  auto c = Const::make(v);
  auto m = Multiplication::make(c, c);
  auto a = Addition::make(c, m);
  auto b = Brackets::make(a);
  auto d = Division::make(b, c);
  auto s = Subtraction::make(c, d);
  EXPECT_DOUBLE_EQ(result, s->evaluate());
}
