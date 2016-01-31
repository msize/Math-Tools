#include "Addition.h"
#include "Visitor.h"

Addition::Addition(const Arithmetic::Ptr &increasing, const Arithmetic::Ptr &increment) noexcept
    : increasing_(increasing), increment_(increment) {
}

Arithmetic::Ptr Addition::make(const Arithmetic::Ptr &increasing, const Arithmetic::Ptr &increment) {
  return Arithmetic::makePtr(Addition(increasing, increment));
}

double Addition::evaluate() const noexcept {
  return increasing_->evaluate() + increment_->evaluate();
}

void Addition::accept(Visitor &v) const {
  v.visit(*this);
  increasing_->accept(v);
  increment_->accept(v);
}
