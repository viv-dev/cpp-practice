add_library(viv-functions)

target_include_directories(
  viv-functions
  PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}
)
target_sources(viv-functions
  PUBLIC 
    "lambda.h"
    "lambda.cpp"
)