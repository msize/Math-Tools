#include "Parser.h"

Parser::Parser(const std::string &val) noexcept
    : _val(val) {
}

std::string Parser::getVal() const noexcept {
  return _val;
}
