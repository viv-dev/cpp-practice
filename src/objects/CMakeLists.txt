add_library(viv-objects)

target_include_directories(
  viv-objects
  PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}
)
target_sources(viv-objects 
  PUBLIC 
    "const-class.h"
)