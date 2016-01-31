#include <iostream>

#include "arithmetic/numeric/Expression.h"

void printUsage(const char *programName) {
  std::cout << "Usage:\n  "
            << programName
            << " '[arithmetic]'\n"
            << "Example:\n  "
            << programName
            << " '2 + 2 * 2'\n";
}

int main(int argc, char *argv[]) {
  if (2 != argc) {
    printUsage(argv[0]);
    return 1;
  }
  try {
    auto operation = arithmetic::numeric::Expression().makeOperation(argv[1]);
    std::cout << "Result: "
              << operation->evaluate()
              << '\n';
  } catch (std::exception &e) {
    std::cout << e.what()
              << '\n';
  }
  return 0;
}
