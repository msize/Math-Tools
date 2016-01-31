project(numeric)
set(numeric_SOURCES
  Addition.cpp
  Brackets.cpp
  Const.cpp
  Division.cpp
  Expression.cpp
  Multiplication.cpp
  Subtraction.cpp
)
add_library(numeric STATIC ${numeric_SOURCES})
target_link_libraries(numeric arithmetic)
