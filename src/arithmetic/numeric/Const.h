#ifndef ARITHMETIC_NUMERIC_CONST_H_
#define ARITHMETIC_NUMERIC_CONST_H_

#include "Numeric.h"

namespace arithmetic {
namespace numeric {

class Const: public Numeric {

public:

  static Numeric::Ptr make(double value);
  virtual double evaluate() const noexcept override;
  virtual void accept(Visitor &v) const override;

private:

  explicit Const(double value) noexcept;
  double value_;

};

} /* namespace numeric */
} /* namespace arithmetic */

#endif /* ARITHMETIC_NUMERIC_CONST_H_ */
