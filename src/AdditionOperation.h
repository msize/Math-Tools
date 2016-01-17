#ifndef ADDITIONOPERATION_H_
#define ADDITIONOPERATION_H_

#include "Operation.h"

class AdditionOperation: public Operation {

public:

  AdditionOperation(const Operation::Ptr &increasing, const Operation::Ptr &increment) noexcept
      : _increasing(increasing), _increment(increment) {
  }

  virtual double evaluate() const noexcept override {
    return _increasing->evaluate() + _increment->evaluate();
  }

private:

  Operation::Ptr _increasing;
  Operation::Ptr _increment;

};

#endif /* ADDITIONOPERATION_H_ */
