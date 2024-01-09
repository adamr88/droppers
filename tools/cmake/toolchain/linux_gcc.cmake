if(NOT CMAKE_SYSTEM_NAME MATCHES "Linux")
  message(STATUS "Skipping ${CMAKE_CURRENT_LIST_FILE} ...")
  return()
endif()

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)
