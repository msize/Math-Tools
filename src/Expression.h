#ifndef EXPRESSION_H_
#define EXPRESSION_H_

#include <string>
#include "Parser.h"
#include "Arithmetic.h"

class Expression: public Parser<Arithmetic> {

public:

  virtual ~Expression() =default;
  using Parser<Arithmetic>::makeOperation;
  Arithmetic::Ptr makeOperation(const std::string &expression);

private:

  virtual bool isLowLevelOperation(const std::string &str) const override;
  virtual bool isHighLevelOperation(const std::string &str) const override;
  virtual Arithmetic::Ptr makeLowLevelOperation(const Arithmetic::Ptr &left, const Arithmetic::Ptr &right, const std::string &token) const override;
  virtual Arithmetic::Ptr makeHighLevelOperation(const Arithmetic::Ptr &left, const Arithmetic::Ptr &right, const std::string &token) const override;
  virtual Arithmetic::Ptr makeBracketsOperation(const Arithmetic::Ptr &expression) const override;
  virtual Arithmetic::Ptr makeConstOperation(const std::string &tokens) const override;
  void raiseBadToken(const std::string &token) const;

};

#endif /* EXPRESSION_H_ */
