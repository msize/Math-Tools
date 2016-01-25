#include <gtest/gtest.h>
#include <string>
#include "../Parser.h"
#include "../SyntaxTreeVisitior.h"

class ParserTest: public ::testing::Test {

protected:

  virtual void SetUp() {
  }
  virtual void TearDown() {
  }

};

TEST_F(ParserTest, parseExpression1) {
  static const std::string expression = " 2 * 2 + 2";
  static const std::string result = "+*CCC";
  auto operation = Parser::makeOperation(expression);
  SyntaxTreeVisitior visitor;
  operation->accept(visitor);
  EXPECT_STREQ(result.c_str(), visitor.result().c_str());
}

TEST_F(ParserTest, parseExpression2) {
  static const std::string expression = "2 + 2 * 2 ";
  static const std::string result = "+C*CC";
  auto operation = Parser::makeOperation(expression);
  SyntaxTreeVisitior visitor;
  operation->accept(visitor);
  EXPECT_STREQ(result.c_str(), visitor.result().c_str());
}

TEST_F(ParserTest, parseExpression3) {
  static const std::string expression = "20 - (4 + 2 * 3) / 5";
  static const std::string result = "-C/()+C*CCC";
  auto operation = Parser::makeOperation(expression);
  SyntaxTreeVisitior visitor;
  operation->accept(visitor);
  EXPECT_STREQ(result.c_str(), visitor.result().c_str());
}

TEST_F(ParserTest, parseExpression4) {
  static const std::string expression = "(20 - ((4 + 2) * 3)) / 5";
  static const std::string result = "/()-C()*()+CCCC";
  auto operation = Parser::makeOperation(expression);
  SyntaxTreeVisitior visitor;
  operation->accept(visitor);
  EXPECT_STREQ(result.c_str(), visitor.result().c_str());
}
