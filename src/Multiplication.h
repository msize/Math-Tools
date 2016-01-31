#ifndef MULTIPLICATION_H_
#define MULTIPLICATION_H_

#include "Arithmetic.h"

class Multiplication: public Arithmetic {

public:

  static Arithmetic::Ptr make(const Arithmetic::Ptr &multiplier, const Arithmetic::Ptr &multiplicand);
  virtual double evaluate() const noexcept override;
  virtual void accept(Visitor &v) const override;

private:

  Multiplication(const Arithmetic::Ptr &multiplier, const Arithmetic::Ptr &multiplicand) noexcept;
  Arithmetic::Ptr multiplier_;
  Arithmetic::Ptr multiplicand_;

};

#endif /* MULTIPLICATION_H_ */
