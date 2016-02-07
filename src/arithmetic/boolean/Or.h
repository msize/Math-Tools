#ifndef ARITHMETIC_BOOLEAN_OR_H_
#define ARITHMETIC_BOOLEAN_OR_H_

#include "Boolean.h"

namespace arithmetic {
namespace boolean {

class Or: public Boolean {

public:

  static Boolean::Ptr make(const Boolean::Ptr &left, const Boolean::Ptr &right);
  virtual bool evaluate() const noexcept override;
  virtual void accept(Visitor &v) const override;

private:

  Or(const Boolean::Ptr &left, const Boolean::Ptr &right) noexcept;
  Boolean::Ptr left_;
  Boolean::Ptr right_;

};

} /* namespace boolean */
} /* namespace arithmetic */

#endif /* ARITHMETIC_BOOLEAN_OR_H_ */
