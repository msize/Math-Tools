#ifndef CONST_H_
#define CONST_H_

#include "Arithmetic.h"

class Const: public Arithmetic {

public:

  static Arithmetic::Ptr make(double value);
  virtual double evaluate() const noexcept override;
  virtual void accept(Visitor &v) const override;

private:

  explicit Const(double value) noexcept;
  double value_;

};

#endif /* CONST_H_ */
