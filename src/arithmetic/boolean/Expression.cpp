#include <stdexcept>
#include "AllOperations.h"
#include "Expression.h"

namespace arithmetic {
namespace boolean {

Boolean::Ptr Expression::makeOperation(const std::string& expression) {
  static const std::string seporators = " \n";
  static const std::string singleTokens = "()&|";
  static const std::string multipleTokens = "01";
  Tokenizer tokenizer(expression, seporators, singleTokens, multipleTokens);
  return makeOperation(tokenizer);
}

bool Expression::isLowLevelOperation(const std::string& str) const {
  if ("|" == str)
    return true;
  return false;
}

bool Expression::isHighLevelOperation(const std::string& str) const {
  if ("&" == str)
    return true;
  return false;
}

Boolean::Ptr Expression::makeLowLevelOperation(const Boolean::Ptr &left, const Boolean::Ptr &right, const std::string &token) const {
  if ("|" == token)
    return Or::make(left, right);
  raiseBadToken(token);
  return nullptr;
}

Boolean::Ptr Expression::makeHighLevelOperation(const Boolean::Ptr &left, const Boolean::Ptr &right, const std::string &token) const {
  if ("&" == token)
    return And::make(left, right);
  raiseBadToken(token);
  return nullptr;
}

Boolean::Ptr Expression::makeBracketsOperation(const Boolean::Ptr &expression) const {
  return Brackets::make(expression);
}

Boolean::Ptr Expression::makeConstOperation(const std::string &token) const {
  return Const::make(std::stoi(token));
}

void Expression::raiseBadToken(const std::string &token) const {
  throw std::logic_error(std::string("Bad token '").append(token).append("'"));
}

} /* namespace boolean */
} /* namespace arithmetic */
