if(NOT CMAKE_SYSTEM_NAME MATCHES "Linux")
  message(STATUS "Skipping ${CMAKE_CURRENT_LIST_FILE} ...")
  return()
endif()

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_C_COMPILER x86_64-w64-mingw32-gcc-10-win32)
set(CMAKE_CXX_COMPILER x86_64-w64-mingw32-g++-10-win32)

# adjust the default behavior of the FIND_XXX() commands:
# search programs in the host environment
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)

# search headers and libraries in the target environment
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

# notes:
# cross compiling resource files from linux/mingw is problematic. Here be dragons