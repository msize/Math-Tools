#include <gtest/gtest.h>
#include <string>
#include <exception>
#include "../../arithmetic/Variable.h"

class VariableTest: public ::testing::Test {

protected:

  virtual void SetUp() {
  }
  virtual void TearDown() {
  }

};

using arithmetic::Variable;

TEST_F(VariableTest, GetAssignedVals) {
  Variable<double> v;
  static const double a = 1.16;
  static const double b = 2.13;
  v.assign("a", a);
  v.assign("b", b);
  EXPECT_DOUBLE_EQ(v.get("a"), a);
  EXPECT_DOUBLE_EQ(v.get("b"), b);
  v.assign("a", b);
  v.assign("b", a);
  EXPECT_DOUBLE_EQ(v.get("a"), b);
  EXPECT_DOUBLE_EQ(v.get("b"), a);
}

TEST_F(VariableTest, GetNotAssignedVals) {
  Variable<double> v;
  static const double a = 1.16;
  v.assign("a", a);
  EXPECT_THROW(v.get("b"), std::logic_error);
}
