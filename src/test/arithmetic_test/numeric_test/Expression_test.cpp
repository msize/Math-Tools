#include <gtest/gtest.h>
#include <string>
#include "../../../arithmetic/numeric/Expression.h"
#include "../../../arithmetic/SyntaxTree.h"

class ExpressionTest: public ::testing::Test {

protected:

  virtual void SetUp() {
  }
  virtual void TearDown() {
  }

};

using arithmetic::numeric::Expression;
using arithmetic::SyntaxTree;

TEST_F(ExpressionTest, parseExpression1) {
  static const std::string expression = " 2 * 2 + 2";
  static const std::string result = "+*CCC";
  auto operation = Expression().makeOperation(expression);
  SyntaxTree visitor;
  operation->accept(visitor);
  EXPECT_STREQ(result.c_str(), visitor.result().c_str());
}

TEST_F(ExpressionTest, parseExpression2) {
  static const std::string expression = "2 + 2 * 2 ";
  static const std::string result = "+C*CC";
  auto operation = Expression().makeOperation(expression);
  SyntaxTree visitor;
  operation->accept(visitor);
  EXPECT_STREQ(result.c_str(), visitor.result().c_str());
}

TEST_F(ExpressionTest, parseExpression3) {
  static const std::string expression = "20 - (4 + 2 * 3) / 5";
  static const std::string result = "-C/()+C*CCC";
  auto operation = Expression().makeOperation(expression);
  SyntaxTree visitor;
  operation->accept(visitor);
  EXPECT_STREQ(result.c_str(), visitor.result().c_str());
}

TEST_F(ExpressionTest, parseExpression4) {
  static const std::string expression = "(20 - ((4 + 2) * 3)) / 5";
  static const std::string result = "/()-C()*()+CCCC";
  auto operation = Expression().makeOperation(expression);
  SyntaxTree visitor;
  operation->accept(visitor);
  EXPECT_STREQ(result.c_str(), visitor.result().c_str());
}
