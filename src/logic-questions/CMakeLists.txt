add_library(viv-logic)

target_include_directories(
  viv-logic
  PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}
)
target_sources(viv-logic
  PUBLIC 
    "country-scanner.h"
    "country-scanner.cpp"
)