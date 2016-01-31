#ifndef ARITHMETIC_NUMERIC_EXPRESSION_H_
#define ARITHMETIC_NUMERIC_EXPRESSION_H_

#include <string>
#include "Numeric.h"
#include "../Parser.h"

namespace arithmetic {
namespace numeric {

class Expression: public Parser<Numeric> {

public:

  virtual ~Expression() =default;
  using Parser<Numeric>::makeOperation;
  Numeric::Ptr makeOperation(const std::string &expression);

private:

  virtual bool isLowLevelOperation(const std::string &str) const override;
  virtual bool isHighLevelOperation(const std::string &str) const override;
  virtual Numeric::Ptr makeLowLevelOperation(const Numeric::Ptr &left, const Numeric::Ptr &right, const std::string &token) const override;
  virtual Numeric::Ptr makeHighLevelOperation(const Numeric::Ptr &left, const Numeric::Ptr &right, const std::string &token) const override;
  virtual Numeric::Ptr makeBracketsOperation(const Numeric::Ptr &expression) const override;
  virtual Numeric::Ptr makeConstOperation(const std::string &tokens) const override;
  void raiseBadToken(const std::string &token) const;

};

} /* namespace numeric */
} /* namespace arithmetic */

#endif /* ARITHMETIC_NUMERIC_EXPRESSION_H_ */
