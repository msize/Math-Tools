#ifndef BRACKETSOPERATION_H_
#define BRACKETSOPERATION_H_

#include "Operation.h"

class BracketsOperation: public Operation {

public:

  BracketsOperation(const Operation::Ptr &expression) noexcept
      : expression_(expression) {
  }

  virtual double evaluate() const noexcept override {
    return expression_->evaluate();
  }
  virtual void accept(Visitor &v) const override {
    v.visit(*this);
    expression_->accept(v);
  }

private:

  Operation::Ptr expression_;

};

#endif /* BRACKETSOPERATION_H_ */
