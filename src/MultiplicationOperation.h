#ifndef MULTIPLICATIONOPERATION_H_
#define MULTIPLICATIONOPERATION_H_

#include "Operation.h"

class MultiplicationOperation: public Operation {

public:

  MultiplicationOperation(const Operation::Ptr &multiplier, const Operation::Ptr &multiplicand) noexcept
    : _multiplier(multiplier), _multiplicand(multiplicand) {
  }

  virtual double evaluate() const noexcept override {
    return _multiplier->evaluate() * _multiplicand->evaluate();
  }

private:

  Operation::Ptr _multiplier;
  Operation::Ptr _multiplicand;

};

#endif /* MULTIPLICATIONOPERATION_H_ */
