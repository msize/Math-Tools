#include "Multiplication.h"
#include "Visitor.h"

Multiplication::Multiplication(const Arithmetic::Ptr &multiplier, const Arithmetic::Ptr &multiplicand) noexcept
    : multiplier_(multiplier), multiplicand_(multiplicand) {
}

Arithmetic::Ptr Multiplication::make(const Arithmetic::Ptr &multiplier, const Arithmetic::Ptr &multiplicand) {
  return Arithmetic::makePtr(Multiplication(multiplier, multiplicand));
}

double Multiplication::evaluate() const noexcept {
  return multiplier_->evaluate() * multiplicand_->evaluate();
}

void Multiplication::accept(Visitor &v) const {
  v.visit(*this);
  multiplier_->accept(v);
  multiplicand_->accept(v);
}
