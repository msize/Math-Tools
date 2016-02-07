#ifndef ARITHMETIC_BOOLEAN_CONST_H_
#define ARITHMETIC_BOOLEAN_CONST_H_

#include "Boolean.h"

namespace arithmetic {
namespace boolean {

class Const: public Boolean {

public:

  static Boolean::Ptr make(bool value);
  virtual bool evaluate() const noexcept override;
  virtual void accept(Visitor &v) const override;

private:

  explicit Const(bool value) noexcept;
  bool value_;

};

} /* namespace boolean */
} /* namespace arithmetic */

#endif /* ARITHMETIC_BOOLEAN_CONST_H_ */
