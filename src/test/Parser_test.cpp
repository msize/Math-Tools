#include <gtest/gtest.h>
#include <string>
#include "../Parser.h"

class ParserTest: public ::testing::Test {

protected:

  virtual void SetUp() {
  }
  virtual void TearDown() {
  }

};

TEST_F(ParserTest, parseExpression) {
  static const std::string val = "2 + 2 * 2";
  Parser parser(val);
  EXPECT_STREQ(val.c_str(), parser.getVal().c_str());
}
