if(NOT CMAKE_SYSTEM_NAME MATCHES "Darwin")
  message(STATUS "Skipping ${CMAKE_CURRENT_LIST_FILE} ...")
  return()
endif()

set(CMAKE_SYSTEM_NAME Darwin)
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang)
