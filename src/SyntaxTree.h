#ifndef SYNTAXTREE_H_
#define SYNTAXTREE_H_

#include <sstream>
#include "Visitor.h"

class SyntaxTree: public Visitor {

public:

  virtual void visit(const Addition &) override;
  virtual void visit(const Brackets &) override;
  virtual void visit(const Const &) override;
  virtual void visit(const Division &) override;
  virtual void visit(const Multiplication &) override;
  virtual void visit(const Subtraction &) override;
  std::string result() const;

private:

  std::ostringstream oss_;

};

#endif /* SYNTAXTREE_H_ */
