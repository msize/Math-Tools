#include "Subtraction.h"
#include "Visitor.h"

Subtraction::Subtraction(const Arithmetic::Ptr &minuend, const Arithmetic::Ptr &subtrahend) noexcept
    : minuend_(minuend), subtrahend_(subtrahend) {
}

Arithmetic::Ptr Subtraction::make(const Arithmetic::Ptr &minuend, const Arithmetic::Ptr &subtrahend) {
  return Arithmetic::makePtr(Subtraction(minuend, subtrahend));
}

double Subtraction::evaluate() const noexcept {
  return minuend_->evaluate() - subtrahend_->evaluate();
}

void Subtraction::accept(Visitor &v) const {
  v.visit(*this);
  minuend_->accept(v);
  subtrahend_->accept(v);
}
