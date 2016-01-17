#ifndef TOKENIZER_H_
#define TOKENIZER_H_

#include <string>
#include <exception>

class Tokenizer {

public:

  class Exception: public std::exception {
  public:
    explicit Exception(std::string::size_type pos) noexcept
        : m_pos(pos) {
    }
    virtual const char *what() const noexcept override {
      return "Bad token";
    }
    std::string::size_type getPos() const noexcept {
      return m_pos;
    }
  private:
    std::string::size_type m_pos;
  };

  Tokenizer(const std::string &expression,
            const std::string &seporators,
            const std::string &singleTokens,
            const std::string &multipleTokens);

  std::string getNextToken();
  bool done() const noexcept {
    return std::string::npos == m_pos;
  }

private:

  std::string m_expression;
  std::string m_seporators;
  std::string m_singleTokens;
  std::string m_multipleTokens;
  std::string::size_type m_pos = 0;

};

#endif /* TOKENIZER_H_ */
