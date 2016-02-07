#include <gtest/gtest.h>
#include <string>
#include <exception>
#include "../../arithmetic/Tokenizer.h"

class TokenizerTest: public ::testing::Test {

protected:

  virtual void SetUp() {
  }
  virtual void TearDown() {
  }

};

using arithmetic::Tokenizer;

TEST_F(TokenizerTest, NextGetterNumericFine) {
  static const std::string expression = "(2.2 + 2.2) -\n 2.2 * 2.2";
  static const std::string seporators = " \n";
  static const std::string singleTokens = "()+-*";
  static const std::string multipleTokens = ".2";
  Tokenizer t(expression, seporators, singleTokens, multipleTokens);
  EXPECT_STREQ("(", t.getNextToken().c_str());
  EXPECT_STREQ("2.2", t.getNextToken().c_str());
  EXPECT_STREQ("+", t.getNextToken().c_str());
  EXPECT_STREQ("2.2", t.getNextToken().c_str());
  EXPECT_STREQ(")", t.getNextToken().c_str());
  EXPECT_STREQ("-", t.getNextToken().c_str());
  EXPECT_STREQ("2.2", t.getNextToken().c_str());
  EXPECT_STREQ("*", t.getNextToken().c_str());
  EXPECT_STREQ("2.2", t.getNextToken().c_str());
  EXPECT_TRUE(t.done());
}

TEST_F(TokenizerTest, NextGetterBooleanFine) {
  static const std::string expression = "1 & 0 | ( 1 | 0) ";
  static const std::string seporators = " ";
  static const std::string singleTokens = "()|&";
  static const std::string multipleTokens = "01";
  Tokenizer t(expression, seporators, singleTokens, multipleTokens);
  EXPECT_STREQ("1", t.getNextToken().c_str());
  EXPECT_STREQ("&", t.getNextToken().c_str());
  EXPECT_STREQ("0", t.getNextToken().c_str());
  EXPECT_STREQ("|", t.getNextToken().c_str());
  EXPECT_STREQ("(", t.getNextToken().c_str());
  EXPECT_STREQ("1", t.getNextToken().c_str());
  EXPECT_STREQ("|", t.getNextToken().c_str());
  EXPECT_STREQ("0", t.getNextToken().c_str());
  EXPECT_STREQ(")", t.getNextToken().c_str());
  EXPECT_TRUE(t.done());
}

TEST_F(TokenizerTest, NextGetterLoose) {
  static const std::string expression = "999.9 - var";
  static const std::string seporators = " ";
  static const std::string singleTokens = "-";
  static const std::string multipleTokens = ".9";
  Tokenizer t(expression, seporators, singleTokens, multipleTokens);
  EXPECT_STREQ("999.9", t.getNextToken().c_str());
  EXPECT_STREQ("-", t.getNextToken().c_str());
  EXPECT_THROW(t.getNextToken(), std::logic_error);
}
