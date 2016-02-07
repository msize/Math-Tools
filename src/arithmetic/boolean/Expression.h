#ifndef ARITHMETIC_BOOLEAN_EXPRESSION_H_
#define ARITHMETIC_BOOLEAN_EXPRESSION_H_

#include <string>
#include "Boolean.h"
#include "../Parser.h"

namespace arithmetic {
namespace boolean {

class Expression: public Parser<Boolean> {

public:

  virtual ~Expression() =default;
  using Parser<Boolean>::makeOperation;
  Boolean::Ptr makeOperation(const std::string &expression);

private:

  virtual bool isLowLevelOperation(const std::string &str) const override;
  virtual bool isHighLevelOperation(const std::string &str) const override;
  virtual Boolean::Ptr makeLowLevelOperation(const Boolean::Ptr &left, const Boolean::Ptr &right, const std::string &token) const override;
  virtual Boolean::Ptr makeHighLevelOperation(const Boolean::Ptr &left, const Boolean::Ptr &right, const std::string &token) const override;
  virtual Boolean::Ptr makeBracketsOperation(const Boolean::Ptr &expression) const override;
  virtual Boolean::Ptr makeConstOperation(const std::string &tokens) const override;
  void raiseBadToken(const std::string &token) const;

};

} /* namespace boolean */
} /* namespace arithmetic */

#endif /* ARITHMETIC_BOOLEAN_EXPRESSION_H_ */
