#ifndef ARITHMETIC_BOOLEAN_AND_H_
#define ARITHMETIC_BOOLEAN_AND_H_

#include "Boolean.h"

namespace arithmetic {
namespace boolean {

class And: public Boolean {

public:

  static Boolean::Ptr make(const Boolean::Ptr &left, const Boolean::Ptr &right);
  virtual bool evaluate() const noexcept override;
  virtual void accept(Visitor &v) const override;

private:

  And(const Boolean::Ptr &left, const Boolean::Ptr &right) noexcept;
  Boolean::Ptr left_;
  Boolean::Ptr right_;

};

} /* namespace boolean */
} /* namespace arithmetic */

#endif /* ARITHMETIC_BOOLEAN_AND_H_ */
