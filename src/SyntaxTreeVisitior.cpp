#include "SyntaxTreeVisitior.h"

SyntaxTreeVisitior::SyntaxTreeVisitior() noexcept {
}

SyntaxTreeVisitior::~SyntaxTreeVisitior() noexcept {
}

void SyntaxTreeVisitior::visit(const AdditionOperation &) {
  oss_ << "+";
}

void SyntaxTreeVisitior::visit(const BracketsOperation &) {
  oss_ << "()";
}

void SyntaxTreeVisitior::visit(const ConstOperation &) {
  oss_ << "C";
}

void SyntaxTreeVisitior::visit(const DivisionOperation &) {
  oss_ << "/";
}

void SyntaxTreeVisitior::visit(const MultiplicationOperation &) {
  oss_ << "*";
}

void SyntaxTreeVisitior::visit(const SubtractionOperation &) {
  oss_ << "-";
}

std::string SyntaxTreeVisitior::result() const {
  return oss_.str();
}
