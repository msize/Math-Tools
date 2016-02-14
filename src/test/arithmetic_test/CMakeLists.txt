project(arithmetic_test)
set(test_SOURCES
  arithmetic_test.cpp
  Tokenizer_test.cpp
  Variable_test.cpp
)
add_executable(arithmetic_test ${test_SOURCES})
target_link_libraries(arithmetic_test ${GTEST_LIBRARIES} arithmetic)
add_test(arithmetic_test arithmetic_test)
add_subdirectory(boolean_test)
add_subdirectory(numeric_test)
