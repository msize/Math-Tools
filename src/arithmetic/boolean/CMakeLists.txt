project(boolean)
set(boolean_SOURCES
  And.cpp
  Brackets.cpp
  Const.cpp
  Expression.cpp
  Or.cpp
)
add_library(boolean STATIC ${boolean_SOURCES})
target_link_libraries(boolean arithmetic)
