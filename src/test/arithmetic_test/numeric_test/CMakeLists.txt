project(numeric_test)
set(test_SOURCES
  numeric_test.cpp
  Expression_test.cpp
  Operation_test.cpp
)
add_executable(numeric_test ${test_SOURCES})
target_link_libraries(numeric_test ${GTEST_LIBRARIES} numeric)
add_test(numeric_test numeric_test)
