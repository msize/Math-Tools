#ifndef ARITHMETIC_VISITOR_H_
#define ARITHMETIC_VISITOR_H_

#include "numeric/AllOperations.h"
#include "boolean/AllOperations.h"

namespace arithmetic {

class Visitor {

public:

  virtual ~Visitor() =default;
  virtual void visit(const numeric::Addition &) = 0;
  virtual void visit(const numeric::Brackets &) = 0;
  virtual void visit(const numeric::Const &) = 0;
  virtual void visit(const numeric::Division &) = 0;
  virtual void visit(const numeric::Multiplication &) = 0;
  virtual void visit(const numeric::Subtraction &) = 0;
  virtual void visit(const boolean::And &) =0;
  virtual void visit(const boolean::Brackets &) =0;
  virtual void visit(const boolean::Const &) =0;
  virtual void visit(const boolean::Or &) =0;

};

} /* namespace arithmetic */

#endif /* ARITHMETIC_VISITOR_H_ */
