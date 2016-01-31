#ifndef ARITHMETIC_OPERATION_H_
#define ARITHMETIC_OPERATION_H_

#include <memory>

namespace arithmetic {

class Visitor;

template <typename R>
class Operation {

public:

  using Ptr = std::shared_ptr<Operation<R>>;

  virtual ~Operation() =default;
  virtual R evaluate() const noexcept = 0;
  virtual void accept(Visitor &v) const = 0;

protected:

  template <typename T>
  static Ptr makePtr(const T &t) {
    return std::make_shared<T>(t);
  }

};

} /* namespace arithmetic */

#endif /* ARITHMETIC_OPERATION_H_ */
