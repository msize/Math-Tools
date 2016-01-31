#include <stdexcept>
#include "Tokenizer.h"

Tokenizer::Tokenizer(const std::string &expression,
          const std::string &seporators,
          const std::string &singleTokens,
          const std::string &multipleTokens)
    : expression_(expression),
      seporators_(seporators),
      singleTokens_(singleTokens),
      multipleTokens_(multipleTokens) {
  pos_ = expression_.find_first_not_of(seporators_, 0);
}

std::string Tokenizer::getNextToken() {
  auto bpos = pos_;
  auto epos = bpos + ((std::string::npos == singleTokens_.find_first_of(expression_.at(bpos))) ? 0 : 1);
  epos = (epos == bpos) ? expression_.find_first_not_of(multipleTokens_, bpos) : epos;
  if (epos == bpos && !done())
    throw std::logic_error(std::string("Bad token in position: ").append(std::to_string(pos_)));
  pos_ = expression_.find_first_not_of(seporators_, epos);
  return expression_.substr(bpos, epos - bpos);
}
