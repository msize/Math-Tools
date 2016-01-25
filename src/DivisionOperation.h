#ifndef DIVISIONOPERATION_H_
#define DIVISIONOPERATION_H_

#include "Operation.h"

class DivisionOperation: public Operation {

public:

  DivisionOperation(const Operation::Ptr &dividend, const Operation::Ptr &divisor) noexcept
      : dividend_(dividend), divisor_(divisor) {
  }

  virtual double evaluate() const noexcept override {
    return dividend_->evaluate() / divisor_->evaluate();
  }
  virtual void accept(Visitor &v) const override {
    v.visit(*this);
    dividend_->accept(v);
    divisor_->accept(v);
  }

private:

  Operation::Ptr dividend_;
  Operation::Ptr divisor_;

};

#endif /* DIVISIONOPERATION_H_ */
