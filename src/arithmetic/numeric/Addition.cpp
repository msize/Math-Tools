#include "Addition.h"
#include "../Visitor.h"

namespace arithmetic {
namespace numeric {

Addition::Addition(const Numeric::Ptr &increasing, const Numeric::Ptr &increment) noexcept
    : increasing_(increasing), increment_(increment) {
}

Numeric::Ptr Addition::make(const Numeric::Ptr &increasing, const Numeric::Ptr &increment) {
  return Numeric::makePtr(Addition(increasing, increment));
}

double Addition::evaluate() const noexcept {
  return increasing_->evaluate() + increment_->evaluate();
}

void Addition::accept(Visitor &v) const {
  v.visit(*this);
  increasing_->accept(v);
  increment_->accept(v);
}

} /* namespace numeric */
} /* namespace arithmetic */
