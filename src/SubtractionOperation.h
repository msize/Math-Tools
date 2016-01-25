#ifndef SUBTRACTIONOPERATION_H_
#define SUBTRACTIONOPERATION_H_

#include "Operation.h"

class SubtractionOperation: public Operation {

public:

  SubtractionOperation(const Operation::Ptr &minuend, const Operation::Ptr &subtrahend) noexcept
      : minuend_(minuend), subtrahend_(subtrahend) {
  }

  virtual double evaluate() const noexcept override {
    return minuend_->evaluate() - subtrahend_->evaluate();
  }
  virtual void accept(Visitor &v) const override {
    v.visit(*this);
    minuend_->accept(v);
    subtrahend_->accept(v);
  }

private:

  Operation::Ptr minuend_;
  Operation::Ptr subtrahend_;

};

#endif /* SUBTRACTIONOPERATION_H_ */
