add_library(viv-memory)

target_include_directories(
  viv-memory
  PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}
)
target_sources(viv-memory
  PUBLIC
  "example-pointers.h"
  "example-pointers.cpp"
)