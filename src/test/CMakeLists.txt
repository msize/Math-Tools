project(mathtools_test)
set(test_SOURCES
  calculator_test.cpp
  Expression_test.cpp
  Operation_test.cpp
  Tokenizer_test.cpp
)
add_executable(calculator_test ${test_SOURCES})
target_link_libraries(calculator_test ${GTEST_LIBRARIES} numeric)
add_test(calculator_test mathtools_test)
