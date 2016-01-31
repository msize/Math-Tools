#ifndef ARITHMETIC_NUMERIC_SUBTRACTION_H_
#define ARITHMETIC_NUMERIC_SUBTRACTION_H_

#include "Numeric.h"

namespace arithmetic {
namespace numeric {

class Subtraction: public Numeric {

public:

  static Numeric::Ptr make(const Numeric::Ptr &minuend, const Numeric::Ptr &subtrahend);
  virtual double evaluate() const noexcept override;
  virtual void accept(Visitor &v) const override;

private:

  Subtraction(const Numeric::Ptr &minuend, const Numeric::Ptr &subtrahend) noexcept;
  Numeric::Ptr minuend_;
  Numeric::Ptr subtrahend_;

};

} /* namespace numeric */
} /* namespace arithmetic */

#endif /* ARITHMETIC_NUMERIC_SUBTRACTION_H_ */
