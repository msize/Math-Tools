#ifndef VISITOR_H_
#define VISITOR_H_

class AdditionOperation;
class BracketsOperation;
class ConstOperation;
class DivisionOperation;
class MultiplicationOperation;
class SubtractionOperation;

class Visitor {

public:

  virtual ~Visitor() noexcept {
  }
  virtual void visit(const AdditionOperation &) = 0;
  virtual void visit(const BracketsOperation &) = 0;
  virtual void visit(const ConstOperation &) = 0;
  virtual void visit(const DivisionOperation &) = 0;
  virtual void visit(const MultiplicationOperation &) = 0;
  virtual void visit(const SubtractionOperation &) = 0;

protected:

  Visitor() noexcept {
  }

};

#endif /* VISITOR_H_ */
