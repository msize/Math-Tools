#include "Subtraction.h"
#include "../Visitor.h"

namespace arithmetic {
namespace numeric {

Subtraction::Subtraction(const Numeric::Ptr &minuend, const Numeric::Ptr &subtrahend) noexcept
    : minuend_(minuend), subtrahend_(subtrahend) {
}

Numeric::Ptr Subtraction::make(const Numeric::Ptr &minuend, const Numeric::Ptr &subtrahend) {
  return Numeric::makePtr(Subtraction(minuend, subtrahend));
}

double Subtraction::evaluate() const noexcept {
  return minuend_->evaluate() - subtrahend_->evaluate();
}

void Subtraction::accept(Visitor &v) const {
  v.visit(*this);
  minuend_->accept(v);
  subtrahend_->accept(v);
}

} /* namespace numeric */
} /* namespace arithmetic */
