#ifndef CONSTOPERATION_H_
#define CONSTOPERATION_H_

#include "Operation.h"

class ConstOperation: public Operation {

public:

  explicit ConstOperation(double value) noexcept
      : value_(value) {
  }

  virtual double evaluate() const noexcept override {
    return value_;
  }
  virtual void accept(Visitor &v) const override {
    v.visit(*this);
  }

private:

  double value_;

};

#endif /* CONSTOPERATION_H_ */
