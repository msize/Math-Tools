#include "Brackets.h"
#include "../Visitor.h"

namespace arithmetic {
namespace boolean {

Brackets::Brackets(const Boolean::Ptr &expression) noexcept
    : expression_(expression) {
}

Boolean::Ptr Brackets::make(const Boolean::Ptr &expression) {
  return Boolean::makePtr(Brackets(expression));
}

bool Brackets::evaluate() const noexcept {
  return expression_->evaluate();
}

void Brackets::accept(Visitor &v) const {
  v.visit(*this);
  expression_->accept(v);
}

} /* namespace boolean */
} /* namespace arithmetic */
