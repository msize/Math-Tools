#include "Const.h"
#include "../Visitor.h"

namespace arithmetic {
namespace numeric {

Const::Const(double value) noexcept
    : value_(value) {
}

Numeric::Ptr Const::make(double value) {
  return Numeric::makePtr(Const(value));
}

double Const::evaluate() const noexcept {
  return value_;
}

void Const::accept(Visitor &v) const {
  v.visit(*this);
}

} /* namespace numeric */
} /* namespace arithmetic */
