#include "Multiplication.h"
#include "../Visitor.h"

namespace arithmetic {
namespace numeric {

Multiplication::Multiplication(const Numeric::Ptr &multiplier, const Numeric::Ptr &multiplicand) noexcept
    : multiplier_(multiplier), multiplicand_(multiplicand) {
}

Numeric::Ptr Multiplication::make(const Numeric::Ptr &multiplier, const Numeric::Ptr &multiplicand) {
  return Numeric::makePtr(Multiplication(multiplier, multiplicand));
}

double Multiplication::evaluate() const noexcept {
  return multiplier_->evaluate() * multiplicand_->evaluate();
}

void Multiplication::accept(Visitor &v) const {
  v.visit(*this);
  multiplier_->accept(v);
  multiplicand_->accept(v);
}

} /* namespace numeric */
} /* namespace arithmetic */
