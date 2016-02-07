#include "Or.h"
#include "../Visitor.h"

namespace arithmetic {
namespace boolean {

Or::Or(const Boolean::Ptr &left, const Boolean::Ptr &right) noexcept
    : left_(left), right_(right) {
}

Boolean::Ptr Or::make(const Boolean::Ptr &left, const Boolean::Ptr &right) {
  return Boolean::makePtr(Or(left, right));
}

bool Or::evaluate() const noexcept {
  return left_->evaluate() || right_->evaluate();
}

void Or::accept(Visitor &v) const {
  v.visit(*this);
  left_->accept(v);
  right_->accept(v);
}

} /* namespace boolean */
} /* namespace arithmetic */
