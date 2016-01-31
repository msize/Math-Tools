#ifndef ARITHMETIC_NUMERIC_BRACKETS_H_
#define ARITHMETIC_NUMERIC_BRACKETS_H_

#include "Numeric.h"

namespace arithmetic {
namespace numeric {

class Brackets: public Numeric {

public:

  static Numeric::Ptr make(const Numeric::Ptr &expression);
  virtual double evaluate() const noexcept override;
  virtual void accept(Visitor &v) const override;

private:

  Brackets(const Numeric::Ptr &expression) noexcept;
  Numeric::Ptr expression_;

};

} /* namespace numeric */
} /* namespace arithmetic */

#endif /* ARITHMETIC_NUMERIC_BRACKETS_H_ */
