#ifndef BRACKETSOPERATION_H_
#define BRACKETSOPERATION_H_

#include "Operation.h"

class BracketsOperation: public Operation {

public:

  BracketsOperation(const Operation::Ptr &expression) noexcept
      : _expression(expression) {
  }

  virtual double evaluate() const noexcept override {
    return _expression->evaluate();
  }

private:

  Operation::Ptr _expression;

};

#endif /* BRACKETSOPERATION_H_ */
