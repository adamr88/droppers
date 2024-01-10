#ifndef _WIN32
#include <stub/tlhelp32.h>
#include <stub/windows.h>

HANDLE CreateToolhelp32Snapshot(DWORD dwFlags, DWORD th32ProcessID) {
  // if not mingw or windows
  return NULL;
}

BOOL WINAPI Process32First(HANDLE hSnapshot, LPPROCESSENTRY32 lppe) {
  // if not mingw or windows
  return FALSE;
}
BOOL WINAPI Process32Next(HANDLE hSnapshot, LPPROCESSENTRY32 lppe) {
  // if not mingw or windows
  return FALSE;
}

#endif