// "omnibus" header replacement for windows.h

#ifndef __STUB_WINDOWS_H
#define __STUB_WINDOWS_H
#ifndef _WIN32

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

#define dllexport
#define __declspec(...)

#define WINAPI
typedef void *PVOID;
typedef PVOID HANDLE;
typedef HANDLE HWND;
typedef unsigned int UINT;

#define MB_OK 0x00000000L
#define __nullterminated
typedef __nullterminated const char *LPCSTR;
typedef LPCSTR LPCTSTR;

#define BOOL bool
#define TRUE true
#define FALSE false
#define WINBOOL BOOL

typedef void *HMODULE;
typedef void *HMODULE;
typedef unsigned long DWORD;
typedef void *LPVOID;

enum {
  DLL_PROCESS_DETACH = 0,
  DLL_PROCESS_ATTACH = 1,
  DLL_THREAD_ATTACH = 2,
  DLL_THREAD_DETACH = 3,
};

BOOL WINAPI MessageBox(HWND hWnd, LPCTSTR lpText, LPCTSTR lpCaption,
                       UINT uType);

#endif // _WIN32
#endif // __STUB_WINDOWS