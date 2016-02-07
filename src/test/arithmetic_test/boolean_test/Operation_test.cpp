#include <gtest/gtest.h>
#include "../../../arithmetic/boolean/AllOperations.h"

class OperationTest: public ::testing::Test {

protected:

  virtual void SetUp() {
  }
  virtual void TearDown() {
  }

};

using arithmetic::boolean::And;
using arithmetic::boolean::Brackets;
using arithmetic::boolean::Const;
using arithmetic::boolean::Or;

TEST_F(OperationTest, And) {
  static const bool left = true;
  static const bool right = false;
  static const bool result = left && right;
  auto a = And::make(
      Const::make(left),
      Const::make(right));
  EXPECT_EQ(result, a->evaluate());
}

TEST_F(OperationTest, Brackets) {
  static const bool result = true;
  auto b = Const::make(result);
  EXPECT_EQ(result, b->evaluate());
}

TEST_F(OperationTest, Or) {
  static const bool left = true;
  static const bool right = false;
  static const bool result = left || false;
  auto o = Or::make(
      Const::make(left),
      Const::make(right));
  EXPECT_EQ(result, o->evaluate());
}


TEST_F(OperationTest, Combination) {
  static const bool tr = true;
  static const bool fls = false;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wparentheses"
  static const bool result = tr && (tr || fls && tr) || fls;
#pragma GCC diagnostic pop
  auto ctr = Const::make(tr);
  auto cfls = Const::make(fls);
  auto a = And::make(cfls, ctr);
  auto b = Or::make(ctr, a);
  auto c = Brackets::make(b);
  auto d = And::make(ctr, c);
  auto e = Or::make(d, cfls);
  EXPECT_EQ(result, e->evaluate());
}
