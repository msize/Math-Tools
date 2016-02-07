#ifndef ARITHMETIC_BOOLEAN_BRACKETS_H_
#define ARITHMETIC_BOOLEAN_BRACKETS_H_

#include "Boolean.h"

namespace arithmetic {
namespace boolean {

class Brackets: public Boolean {

public:

  static Boolean::Ptr make(const Boolean::Ptr &expression);
  virtual bool evaluate() const noexcept override;
  virtual void accept(Visitor &v) const override;

private:

  Brackets(const Boolean::Ptr &expression) noexcept;
  Boolean::Ptr expression_;

};

} /* namespace boolean */
} /* namespace arithmetic */

#endif /* ARITHMETIC_BOOLEAN_BRACKETS_H_ */
