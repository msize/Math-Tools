#include <gtest/gtest.h>
#include "../AllOperations.h"

class OperationTest: public ::testing::Test {

protected:

  virtual void SetUp() {
  }
  virtual void TearDown() {
  }

};

TEST_F(OperationTest, AdditionOperation) {
  static const double firstAddend = 3.3;
  static const double secondAddend = 4.4;
  static const double result = firstAddend + secondAddend;
  auto s = Operation::makePtr(AdditionOperation(
      Operation::makePtr(ConstOperation(firstAddend)),
      Operation::makePtr(ConstOperation(secondAddend))
      ));
  EXPECT_DOUBLE_EQ(result, s->evaluate());
}

TEST_F(OperationTest, BracketsOperation) {
  static const double result = 9.9;
  auto b = Operation::makePtr(BracketsOperation(Operation::makePtr(ConstOperation(result))));
  EXPECT_DOUBLE_EQ(result, b->evaluate());
}

TEST_F(OperationTest, DivisionOperation) {
  static const double dividend = 7.14;
  static const double divisor = 2.1;
  static const double result = dividend / divisor;
  auto d = Operation::makePtr(DivisionOperation(
      Operation::makePtr(ConstOperation(dividend)),
      Operation::makePtr(ConstOperation(divisor))
      ));
  EXPECT_DOUBLE_EQ(result, d->evaluate());
}

TEST_F(OperationTest, MultiplicationOperation) {
  static const double multiplier = 5.5;
  static const double multiplicand = 3.3;
  static const double result = multiplier * multiplicand;
  auto m = Operation::makePtr(MultiplicationOperation(
      Operation::makePtr(ConstOperation(multiplier)),
      Operation::makePtr(ConstOperation(multiplicand))
      ));
  EXPECT_DOUBLE_EQ(result, m->evaluate());
}

TEST_F(OperationTest, SubtractionOperation) {
  static const double minuend = 8.7;
  static const double subtrahend = 9.9;
  static const double result = minuend - subtrahend;
  auto s = Operation::makePtr(SubtractionOperation(
      Operation::makePtr(ConstOperation(minuend)),
      Operation::makePtr(ConstOperation(subtrahend))
      ));
  EXPECT_DOUBLE_EQ(result, s->evaluate());
}

TEST_F(OperationTest, CombinationOperation) {
  static const double v = 2.2;
  static const double result = v - (v + v * v) / v;
  auto c = Operation::makePtr(ConstOperation(v));
  auto m = Operation::makePtr(MultiplicationOperation(c, c));
  auto a = Operation::makePtr(AdditionOperation(c, m));
  auto b = Operation::makePtr(BracketsOperation(a));
  auto d = Operation::makePtr(DivisionOperation(b, c));
  auto s = Operation::makePtr(SubtractionOperation(c, d));
  EXPECT_DOUBLE_EQ(result, s->evaluate());
}
