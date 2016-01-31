#ifndef DIVISION_H_
#define DIVISION_H_

#include "Arithmetic.h"

class Division: public Arithmetic {

public:

  static Arithmetic::Ptr make(const Arithmetic::Ptr &dividend, const Arithmetic::Ptr &divisor);
  virtual double evaluate() const noexcept override;
  virtual void accept(Visitor &v) const override;

private:

  Division(const Arithmetic::Ptr &dividend, const Arithmetic::Ptr &divisor) noexcept;
  Arithmetic::Ptr dividend_;
  Arithmetic::Ptr divisor_;

};

#endif /* DIVISION_H_ */
