#include "Const.h"
#include "../Visitor.h"

namespace arithmetic {
namespace boolean {

Const::Const(bool value) noexcept
    : value_(value) {
}

Boolean::Ptr Const::make(bool value) {
  return Boolean::makePtr(Const(value));
}

bool Const::evaluate() const noexcept {
  return value_;
}

void Const::accept(Visitor &v) const {
  v.visit(*this);
}

} /* namespace boolean */
} /* namespace arithmetic */
