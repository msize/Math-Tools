#ifndef ARITHMETIC_VARIABLE_H_
#define ARITHMETIC_VARIABLE_H_

#include <unordered_map>
#include <stdexcept>
#include <string>

namespace arithmetic {

template <typename V>
class Variable final {

public:

  void assign(const std::string &name, const V &val) {
    variables_[name] = val;
  }
  const V &get(const std::string &name) const {
    auto var = variables_.find(name);
    if (variables_.end() == var)
      throw std::logic_error(std::string("Variable is not assigned: ").append(name));
    return var->second;
  }
  V get(const std::string &name) {
    return static_cast<const Variable<V>*>(this)->get(name);
  }

private:

  std::unordered_map<std::string, V> variables_;

};

} /* namespace arithmetic */

#endif /* ARITHMETIC_VARIABLE_H_ */
