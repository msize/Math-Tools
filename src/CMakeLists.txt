cmake_minimum_required(VERSION 2.6)
project(mathtools)
add_definitions(-std=c++14)
set(calculator_SOURCE
  calculator.cpp
  Parser.cpp
  Tokenizer.cpp
)
add_executable(calculator ${calculator_SOURCE})

find_package(GTest)
if(GTEST_FOUND)
  set(calculator_test_SOURCE
    Parser.cpp
    Tokenizer.cpp
    test/calculator_test.cpp
    test/Operation_test.cpp
    test/Parser_test.cpp
    test/Tokenizer_test.cpp
  )
  set(GTest_USE_LIBS)
  add_executable(calculator_test ${calculator_test_SOURCE})
  target_link_libraries(calculator_test ${GTEST_BOTH_LIBRARIES})
endif()
