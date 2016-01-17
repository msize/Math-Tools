#ifndef OPERATION_H_
#define OPERATION_H_

#include <memory>

class Operation {

public:

  using Ptr = std::shared_ptr<Operation>;
  template <typename T>
  static Ptr makePtr(const T &t) {
    return std::make_shared<T>(t);
  }

  Operation() noexcept {
  }
  virtual ~Operation() noexcept {
  }

  virtual double evaluate() const noexcept = 0;

};

#endif /* OPERATION_H_ */
