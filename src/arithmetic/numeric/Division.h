#ifndef ARITHMETIC_NUMERIC_DIVISION_H_
#define ARITHMETIC_NUMERIC_DIVISION_H_

#include "Numeric.h"

namespace arithmetic {
namespace numeric {

class Division: public Numeric {

public:

  static Numeric::Ptr make(const Numeric::Ptr &dividend, const Numeric::Ptr &divisor);
  virtual double evaluate() const noexcept override;
  virtual void accept(Visitor &v) const override;

private:

  Division(const Numeric::Ptr &dividend, const Numeric::Ptr &divisor) noexcept;
  Numeric::Ptr dividend_;
  Numeric::Ptr divisor_;

};

} /* namespace numeric */
} /* namespace arithmetic */

#endif /* ARITHMETIC_NUMERIC_DIVISION_H_ */
