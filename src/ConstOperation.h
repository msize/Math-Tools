#ifndef CONSTOPERATION_H_
#define CONSTOPERATION_H_

#include "Operation.h"

class ConstOperation: public Operation {

public:

  ConstOperation(double value) noexcept
      : _value(value) {
  }

  virtual double evaluate() const noexcept override {
    return _value;
  }

private:

  double _value;

};

#endif /* CONSTOPERATION_H_ */
