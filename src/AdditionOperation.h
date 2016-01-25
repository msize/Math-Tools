#ifndef ADDITIONOPERATION_H_
#define ADDITIONOPERATION_H_

#include "Operation.h"

class AdditionOperation: public Operation {

public:

  AdditionOperation(const Operation::Ptr &increasing, const Operation::Ptr &increment) noexcept
      : increasing_(increasing), increment_(increment) {
  }

  virtual double evaluate() const noexcept override {
    return increasing_->evaluate() + increment_->evaluate();
  }
  virtual void accept(Visitor &v) const override {
    v.visit(*this);
    increasing_->accept(v);
    increment_->accept(v);
  }

private:

  Operation::Ptr increasing_;
  Operation::Ptr increment_;

};

#endif /* ADDITIONOPERATION_H_ */
