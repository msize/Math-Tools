#ifndef ARITHMETIC_PARSER_H_
#define ARITHMETIC_PARSER_H_

#include <string>
#include "Operation.h"
#include "Tokenizer.h"

namespace arithmetic {

template <typename R>
class Parser {

public:

  virtual ~Parser() =default;
  typename R::Ptr makeOperation(Tokenizer &tokenizer) {
    typename R::Ptr left;
    typename R::Ptr right;
    std::string lowLevelOperation = "";
    std::string highLevelOperation = "";
    while (!tokenizer.done()) {
      std::string token = tokenizer.getNextToken();
      if ("(" == token) {
        ((left) ? right : left) = makeBracketsOperation(makeOperation(tokenizer));
      } else if (")" == token) {
        break;
      } else if (isHighLevelOperation(token)) {
        highLevelOperation = token;
      } else if (isLowLevelOperation(token)) {
        if (!lowLevelOperation.empty())
          left = makeLowLevelOperation(left, right, lowLevelOperation);
        lowLevelOperation = token;
      } else if (!highLevelOperation.empty()) {
        typename R::Ptr tmpRight = makeConstOperation(token);
        typename R::Ptr &tmpLeft = (right) ? right : left;
        tmpLeft = makeHighLevelOperation(tmpLeft, tmpRight, highLevelOperation);
        highLevelOperation.clear();
      } else {
        ((left) ? right : left) = makeConstOperation(token);
      }
    }
    if (left && right && !lowLevelOperation.empty())
      left = makeLowLevelOperation(left, right, lowLevelOperation);
    return left;
  }

private:

  virtual bool isLowLevelOperation(const std::string &token) const =0;
  virtual bool isHighLevelOperation(const std::string &token) const =0;
  virtual typename R::Ptr makeLowLevelOperation(const typename R::Ptr &left, const typename R::Ptr &right, const std::string &token) const =0;
  virtual typename R::Ptr makeHighLevelOperation(const typename R::Ptr &left, const typename R::Ptr &right, const std::string &token) const =0;
  virtual typename R::Ptr makeBracketsOperation(const typename R::Ptr &expression) const =0;
  virtual typename R::Ptr makeConstOperation(const std::string &token) const =0;

};

} /* namespace arithmetic */

#endif /* ARITHMETIC_PARSER_H_ */
