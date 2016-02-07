#include "And.h"
#include "../Visitor.h"

namespace arithmetic {
namespace boolean {

And::And(const Boolean::Ptr &left, const Boolean::Ptr &right) noexcept
    : left_(left), right_(right) {
}

Boolean::Ptr And::make(const Boolean::Ptr &left, const Boolean::Ptr &right) {
  return Boolean::makePtr(And(left, right));
}

bool And::evaluate() const noexcept {
  return left_->evaluate() && right_->evaluate();
}

void And::accept(Visitor &v) const {
  v.visit(*this);
  left_->accept(v);
  right_->accept(v);
}

} /* namespace boolean */
} /* namespace arithmetic */
