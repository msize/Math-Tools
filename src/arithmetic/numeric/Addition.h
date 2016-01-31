#ifndef ARITHMETIC_NUMERIC_ADDITION_H_
#define ARITHMETIC_NUMERIC_ADDITION_H_

#include "Numeric.h"

namespace arithmetic {
namespace numeric {

class Addition: public Numeric {

public:

  static Numeric::Ptr make(const Numeric::Ptr &increasing, const Numeric::Ptr &increment);
  virtual double evaluate() const noexcept override;
  virtual void accept(Visitor &v) const override;

private:

  Addition(const Operation::Ptr &increasing, const Operation::Ptr &increment) noexcept;
  Numeric::Ptr increasing_;
  Numeric::Ptr increment_;

};

} /* namespace numeric */
} /* namespace arithmetic */

#endif /* ARITHMETIC_NUMERIC_ADDITION_H_ */
