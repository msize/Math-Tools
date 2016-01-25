#ifndef OPERATION_H_
#define OPERATION_H_

#include <memory>
#include "Visitor.h"

class Operation {

public:

  using Ptr = std::shared_ptr<Operation>;
  template <typename T>
  static Ptr makePtr(const T &t) {
    return std::make_shared<T>(t);
  }

  virtual ~Operation() noexcept {
  }

  virtual double evaluate() const noexcept = 0;
  virtual void accept(Visitor &v) const = 0;

protected:

  Operation() noexcept {
  }

};

#endif /* OPERATION_H_ */
