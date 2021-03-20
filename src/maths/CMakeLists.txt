add_library(viv-math)

target_include_directories(
  viv-math
  PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}
)
target_sources(viv-math
  PUBLIC
  "linear-algebra.h"
  "linear-algebra.cpp"
)