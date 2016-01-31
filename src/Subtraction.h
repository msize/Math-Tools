#ifndef SUBTRACTION_H_
#define SUBTRACTION_H_

#include "Arithmetic.h"

class Subtraction: public Arithmetic {

public:

  static Arithmetic::Ptr make(const Arithmetic::Ptr &minuend, const Arithmetic::Ptr &subtrahend);
  virtual double evaluate() const noexcept override;
  virtual void accept(Visitor &v) const override;

private:

  Subtraction(const Arithmetic::Ptr &minuend, const Arithmetic::Ptr &subtrahend) noexcept;
  Arithmetic::Ptr minuend_;
  Arithmetic::Ptr subtrahend_;

};

#endif /* SUBTRACTION_H_ */
