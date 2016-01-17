#ifndef PARSER_H_
#define PARSER_H_

#include <string>

class Parser {

public:

  Parser(const std::string &val) noexcept;
  std::string getVal() const noexcept;

private:

  std::string _val;

};

#endif /* PARSER_H_ */
