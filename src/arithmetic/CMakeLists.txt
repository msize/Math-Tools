project(arithmetic)
set(arithmetic_SOURCES
  SyntaxTree.cpp
  Tokenizer.cpp
)
add_library(arithmetic STATIC ${arithmetic_SOURCES})
add_subdirectory(numeric)
