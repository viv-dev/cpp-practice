add_library(viv-threading)

target_include_directories(
  viv-threading
  PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}
)
target_sources(viv-threading
  PUBLIC
  mutexes.h
  mutexes.cpp
)