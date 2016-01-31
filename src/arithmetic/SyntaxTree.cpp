#include "SyntaxTree.h"

namespace arithmetic {

void SyntaxTree::visit(const numeric::Addition &) {
  oss_ << "+";
}

void SyntaxTree::visit(const numeric::Brackets &) {
  oss_ << "()";
}

void SyntaxTree::visit(const numeric::Const &) {
  oss_ << "C";
}

void SyntaxTree::visit(const numeric::Division &) {
  oss_ << "/";
}

void SyntaxTree::visit(const numeric::Multiplication &) {
  oss_ << "*";
}

void SyntaxTree::visit(const numeric::Subtraction &) {
  oss_ << "-";
}

std::string SyntaxTree::result() const {
  return oss_.str();
}

} /* namespace arithmetic */
