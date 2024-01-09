#ifndef _WIN32
#include <dropper/assert.h>
#include <stub/windows.h>

BOOL WINAPI MessageBox(HWND hWnd, LPCTSTR lpText, LPCTSTR lpCaption,
                       UINT uType) {

  // if not mingw or windows
  eprintf("%s: %s", lpCaption, lpText);
  egetchar();
  return FALSE;
}

#endif