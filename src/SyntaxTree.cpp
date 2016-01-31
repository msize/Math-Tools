#include "SyntaxTree.h"

void SyntaxTree::visit(const Addition &) {
  oss_ << "+";
}

void SyntaxTree::visit(const Brackets &) {
  oss_ << "()";
}

void SyntaxTree::visit(const Const &) {
  oss_ << "C";
}

void SyntaxTree::visit(const Division &) {
  oss_ << "/";
}

void SyntaxTree::visit(const Multiplication &) {
  oss_ << "*";
}

void SyntaxTree::visit(const Subtraction &) {
  oss_ << "-";
}

std::string SyntaxTree::result() const {
  return oss_.str();
}
