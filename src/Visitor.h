#ifndef VISITOR_H_
#define VISITOR_H_

#include "AllOperations.h"

class Visitor {

public:

  virtual ~Visitor() =default;
  virtual void visit(const Addition &) = 0;
  virtual void visit(const Brackets &) = 0;
  virtual void visit(const Const &) = 0;
  virtual void visit(const Division &) = 0;
  virtual void visit(const Multiplication &) = 0;
  virtual void visit(const Subtraction &) = 0;

};

#endif /* VISITOR_H_ */
