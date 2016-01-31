#include "Division.h"
#include "../Visitor.h"

namespace arithmetic {
namespace numeric {

Division::Division(const Numeric::Ptr &dividend, const Numeric::Ptr &divisor) noexcept
    : dividend_(dividend), divisor_(divisor) {
}

Numeric::Ptr Division::make(const Numeric::Ptr &dividend, const Numeric::Ptr &divisor) {
  return Numeric::makePtr(Division(dividend, divisor));
}

double Division::evaluate() const noexcept {
  return dividend_->evaluate() / divisor_->evaluate();
}

void Division::accept(Visitor &v) const {
  v.visit(*this);
  dividend_->accept(v);
  divisor_->accept(v);
}

} /* namespace numeric */
} /* namespace arithmetic */
