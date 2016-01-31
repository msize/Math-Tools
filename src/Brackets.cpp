#include "Brackets.h"
#include "Visitor.h"

Brackets::Brackets(const Arithmetic::Ptr &expression) noexcept
    : expression_(expression) {
}

Arithmetic::Ptr Brackets::make(const Arithmetic::Ptr &expression) {
  return Arithmetic::makePtr(Brackets(expression));
}

double Brackets::evaluate() const noexcept {
  return expression_->evaluate();
}

void Brackets::accept(Visitor &v) const {
  v.visit(*this);
  expression_->accept(v);
}
