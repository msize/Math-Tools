#ifndef ARITHMETIC_NUMERIC_MULTIPLICATION_H_
#define ARITHMETIC_NUMERIC_MULTIPLICATION_H_

#include "Numeric.h"

namespace arithmetic {
namespace numeric {

class Multiplication: public Numeric {

public:

  static Numeric::Ptr make(const Numeric::Ptr &multiplier, const Numeric::Ptr &multiplicand);
  virtual double evaluate() const noexcept override;
  virtual void accept(Visitor &v) const override;

private:

  Multiplication(const Numeric::Ptr &multiplier, const Numeric::Ptr &multiplicand) noexcept;
  Numeric::Ptr multiplier_;
  Numeric::Ptr multiplicand_;

};

} /* namespace numeric */
} /* namespace arithmetic */

#endif /* ARITHMETIC_NUMERIC_MULTIPLICATION_H_ */
