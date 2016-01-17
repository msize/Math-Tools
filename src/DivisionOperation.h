#ifndef DIVISIONOPERATION_H_
#define DIVISIONOPERATION_H_

#include "Operation.h"

class DivisionOperation: public Operation {

public:

  DivisionOperation(const Operation::Ptr &dividend, const Operation::Ptr &divisor) noexcept
      : _dividend(dividend), _divisor(divisor) {
  }

  virtual double evaluate() const noexcept override {
    return _dividend->evaluate() / _divisor->evaluate();
  }

private:

  Operation::Ptr _dividend;
  Operation::Ptr _divisor;

};

#endif /* DIVISIONOPERATION_H_ */
