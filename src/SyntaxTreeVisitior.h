#ifndef SYNTAXTREEVISITIOR_H_
#define SYNTAXTREEVISITIOR_H_

#include <sstream>
#include "Visitor.h"

class SyntaxTreeVisitior: public Visitor {

public:

  SyntaxTreeVisitior() noexcept;
  virtual ~SyntaxTreeVisitior() noexcept;

  virtual void visit(const AdditionOperation &) override;
  virtual void visit(const BracketsOperation &) override;
  virtual void visit(const ConstOperation &) override;
  virtual void visit(const DivisionOperation &) override;
  virtual void visit(const MultiplicationOperation &) override;
  virtual void visit(const SubtractionOperation &) override;
  std::string result() const;

private:

  std::ostringstream oss_;

};

#endif /* SYNTAXTREEVISITIOR_H_ */
