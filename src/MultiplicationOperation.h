#ifndef MULTIPLICATIONOPERATION_H_
#define MULTIPLICATIONOPERATION_H_

#include "Operation.h"

class MultiplicationOperation: public Operation {

public:

  MultiplicationOperation(const Operation::Ptr &multiplier, const Operation::Ptr &multiplicand) noexcept
    : multiplier_(multiplier), multiplicand_(multiplicand) {
  }

  virtual double evaluate() const noexcept override {
    return multiplier_->evaluate() * multiplicand_->evaluate();
  }
  virtual void accept(Visitor &v) const override {
    v.visit(*this);
    multiplier_->accept(v);
    multiplicand_->accept(v);
  }

private:

  Operation::Ptr multiplier_;
  Operation::Ptr multiplicand_;

};

#endif /* MULTIPLICATIONOPERATION_H_ */
