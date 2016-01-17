#include <iostream>
#include "Parser.h"

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
  Parser parser(argc[1]);
  std::cout << parser.getVal() << '\n';
  return 0;
}
