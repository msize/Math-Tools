#include <iostream>
#include "Expression.h"

void printUsage(const char *programName) {
  std::cout << "Usage:\n  "
            << programName
            << " '[arithmetic]'\n"
            << "Example:\n  "
            << programName
            << " '2 + 2 * 2'\n";
}

int main(int argv, char *argc[]) {
  if (2 != argv) {
    printUsage(argc[0]);
    return 1;
  }
  try {
    auto operation = Expression().makeOperation(argc[1]);
    std::cout << "Result: "
              << operation->evaluate()
              << '\n';
  } catch (std::exception &e) {
    std::cout << e.what()
              << '\n';
  }
  return 0;
}
