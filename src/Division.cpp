#include "Division.h"
#include "Visitor.h"

Division::Division(const Arithmetic::Ptr &dividend, const Arithmetic::Ptr &divisor) noexcept
    : dividend_(dividend), divisor_(divisor) {
}

Arithmetic::Ptr Division::make(const Arithmetic::Ptr &dividend, const Arithmetic::Ptr &divisor) {
  return Arithmetic::makePtr(Division(dividend, divisor));
}

double Division::evaluate() const noexcept {
  return dividend_->evaluate() / divisor_->evaluate();
}

void Division::accept(Visitor &v) const {
  v.visit(*this);
  dividend_->accept(v);
  divisor_->accept(v);
}
