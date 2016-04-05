project(boolean_test)
set(test_SOURCES
  boolean_test.cpp
  Expression_test.cpp
  Operation_test.cpp
)
add_executable(boolean_test ${test_SOURCES})
target_link_libraries(boolean_test ${GTEST_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT} boolean)
add_test(boolean_test boolean_test)
