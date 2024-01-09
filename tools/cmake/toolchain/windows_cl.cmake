if(NOT CMAKE_SYSTEM_NAME MATCHES "Windows")
  message(STATUS "Skipping ${CMAKE_CURRENT_LIST_FILE} ...")
  return()
endif()

set(CMAKE_SYSTEM_NAME Windows)
set(CMAKE_C_COMPILER cl.exe)
set(CMAKE_CXX_COMPILER cl.exe)

# notes:
# makes no consideration for vcvars64.bat (VS2019 Developer Command prompt). Here be dragons
#
# compiling with 'cmake -G 'Unix Makefiles' without windows_cl.cmake works for most cases 