#ifndef ARITHMETIC_SYNTAXTREE_H_
#define ARITHMETIC_SYNTAXTREE_H_

#include <sstream>
#include "Visitor.h"

namespace arithmetic {

class SyntaxTree: public Visitor {

public:

  virtual void visit(const numeric::Addition &) override;
  virtual void visit(const numeric::Brackets &) override;
  virtual void visit(const numeric::Const &) override;
  virtual void visit(const numeric::Division &) override;
  virtual void visit(const numeric::Multiplication &) override;
  virtual void visit(const numeric::Subtraction &) override;
  std::string result() const;

private:

  std::ostringstream oss_;

};

} /* namespace arithmetic */

#endif /* ARITHMETIC_SYNTAXTREE_H_ */
