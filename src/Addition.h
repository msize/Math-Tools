#ifndef ADDITION_H_
#define ADDITION_H_

#include "Arithmetic.h"

class Addition: public Arithmetic {

public:

  static Arithmetic::Ptr make(const Arithmetic::Ptr &increasing, const Arithmetic::Ptr &increment);
  virtual double evaluate() const noexcept override;
  virtual void accept(Visitor &v) const override;


private:

  Addition(const Operation::Ptr &increasing, const Operation::Ptr &increment) noexcept;
  Arithmetic::Ptr increasing_;
  Arithmetic::Ptr increment_;

};

#endif /* ADDITION_H_ */
