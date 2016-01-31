#include <stdexcept>
#include "Expression.h"
#include "AllOperations.h"

Arithmetic::Ptr Expression::makeOperation(const std::string& expression) {
  static const std::string seporators = " \n";
  static const std::string singleTokens = "()+-*/";
  static const std::string multipleTokens = "0.123456789";
  Tokenizer tokenizer(expression, seporators, singleTokens, multipleTokens);
  return makeOperation(tokenizer);
}

bool Expression::isLowLevelOperation(const std::string& str) const {
  if ("+" == str)
    return true;
  if ("-" == str)
    return true;
  return false;
}

bool Expression::isHighLevelOperation(const std::string& str) const {
  if ("*" == str)
    return true;
  if ("/" == str)
    return true;
  return false;
}

Arithmetic::Ptr Expression::makeLowLevelOperation(const Arithmetic::Ptr &left, const Arithmetic::Ptr &right, const std::string &token) const {
  if ("+" == token)
    return Addition::make(left, right);
  else if ("-" == token)
    return Subtraction::make(left, right);
  raiseBadToken(token);
  return nullptr;
}

Arithmetic::Ptr Expression::makeHighLevelOperation(const Arithmetic::Ptr &left, const Arithmetic::Ptr &right, const std::string &token) const {
  if ("*" == token)
    return Multiplication::make(left, right);
  else if ("/" == token)
    return Division::make(left, right);
  raiseBadToken(token);
  return nullptr;
}

Arithmetic::Ptr Expression::makeBracketsOperation(const Arithmetic::Ptr &expression) const {
  return Brackets::make(expression);
}

Arithmetic::Ptr Expression::makeConstOperation(const std::string &token) const {
  return Const::make(std::stod(token));
}

void Expression::raiseBadToken(const std::string &token) const {
  throw std::logic_error(std::string("Bad token '").append(token).append("'"));
}
