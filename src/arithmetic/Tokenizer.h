#ifndef ARITHMETIC_TOKENIZER_H_
#define ARITHMETIC_TOKENIZER_H_

#include <string>

namespace arithmetic {

class Tokenizer {

public:

  Tokenizer(const std::string &expression,
            const std::string &seporators,
            const std::string &singleTokens,
            const std::string &multipleTokens);
  std::string getNextToken();
  bool done() const noexcept {
    return std::string::npos == pos_;
  }

private:

  std::string expression_;
  std::string seporators_;
  std::string singleTokens_;
  std::string multipleTokens_;
  std::string::size_type pos_ = 0;

};

} /* namespace arithmetic */

#endif /* ARITHMETIC_TOKENIZER_H_ */
