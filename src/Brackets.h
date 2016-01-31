#ifndef BRACKETS_H_
#define BRACKETS_H_

#include "Arithmetic.h"

class Brackets: public Arithmetic {

public:

  static Arithmetic::Ptr make(const Arithmetic::Ptr &expression);
  virtual double evaluate() const noexcept override;
  virtual void accept(Visitor &v) const override;

private:

  Brackets(const Arithmetic::Ptr &expression) noexcept;
  Arithmetic::Ptr expression_;

};

#endif /* BRACKETS_H_ */
