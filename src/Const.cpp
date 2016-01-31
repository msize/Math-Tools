#include "Const.h"
#include "Visitor.h"

Const::Const(double value) noexcept
    : value_(value) {
}

Arithmetic::Ptr Const::make(double value) {
  return Arithmetic::makePtr(Const(value));
}

double Const::evaluate() const noexcept {
  return value_;
}

void Const::accept(Visitor &v) const {
  v.visit(*this);
}
