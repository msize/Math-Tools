#include "Brackets.h"
#include "../Visitor.h"

namespace arithmetic {
namespace numeric {

Brackets::Brackets(const Numeric::Ptr &expression) noexcept
    : expression_(expression) {
}

Numeric::Ptr Brackets::make(const Numeric::Ptr &expression) {
  return Numeric::makePtr(Brackets(expression));
}

double Brackets::evaluate() const noexcept {
  return expression_->evaluate();
}

void Brackets::accept(Visitor &v) const {
  v.visit(*this);
  expression_->accept(v);
}

} /* namespace numeric */
} /* namespace arithmetic */
