/**
 * @file examples/pe/ex1.c
 * @author adamr88 (adamr88@github.com)
 * @brief Debugger shellcode
 * @version 0.1
 * @date 2024-01-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifdef _WIN32
#include <windows.h>
#pragma comment(lib, "user32.lib")
#pragma comment(linker, "/subsystem:console")
#else
#include <stub/windows.h>
#endif

#include <dropper/assert.h>

enum { MAX_TIMEOUT = 4294967295 };

int main() {
  size_t srclen = 4;
  const unsigned char src[] = {
      0x90, // NOP
      0x90, // NOP
      0xcc, // INT3
      0xc3, // RET
  };

  // allocate virtual memory buf
  void *lpbuf =
      VirtualAlloc(0, srclen, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
  AssertNotNull(lpbuf, VirtualAlloc, -1 * __LINE__);

  // copy payload to virtual memory buf
  RtlMoveMemory(lpbuf, src, srclen);

  eprintf("%p\n", (void *)src);
  eprintf("%p\n", (void *)lpbuf);
  PressAnyKey();

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
