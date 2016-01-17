#ifndef SUBTRACTIONOPERATION_H_
#define SUBTRACTIONOPERATION_H_

#include "Operation.h"

class SubtractionOperation: public Operation {

public:

  SubtractionOperation(const Operation::Ptr &minuend, const Operation::Ptr &subtrahend) noexcept
      : _minuend(minuend), _subtrahend(subtrahend) {
  }

  virtual double evaluate() const noexcept override {
    return _minuend->evaluate() - _subtrahend->evaluate();
  }

private:

  Operation::Ptr _minuend;
  Operation::Ptr _subtrahend;

};

#endif /* SUBTRACTIONOPERATION_H_ */
