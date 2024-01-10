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

#define MEM_COMMIT 0x1000
#define MEM_RELEASE 0x8000
#define MEM_RESERVE 0x2000
#define PAGE_EXECUTE_READ 0x20
#define PAGE_EXECUTE_READWRITE 0x40
#define PAGE_READWRITE 0x04

#define UNALIGNED

#define __stdcall
typedef DWORD(__stdcall *LPTHREAD_START_ROUTINE)(LPVOID lpThreadParameter);

#define WINBASEAPI
#define SIZE_T size_t
#define VOID void
typedef DWORD *PDWORD;
typedef DWORD *LPDWORD;

WINBASEAPI LPVOID WINAPI VirtualAlloc(LPVOID lpAddress, SIZE_T dwSize,
                                      DWORD flAllocationType, DWORD flProtect);

VOID WINAPI RtlMoveMemory(VOID UNALIGNED *Destination,
                          const VOID UNALIGNED *Source, SIZE_T Length);

WINBASEAPI WINBOOL WINAPI VirtualProtect(LPVOID lpAddress, SIZE_T dwSize,
                                         DWORD flNewProtect,
                                         PDWORD lpflOldProtect);

typedef struct _SECURITY_ATTRIBUTES {
  DWORD nLength;
  LPVOID lpSecurityDescriptor;
  BOOL bInheritHandle;
} SECURITY_ATTRIBUTES, *PSECURITY_ATTRIBUTES, *LPSECURITY_ATTRIBUTES;

WINBASEAPI HANDLE WINAPI CreateThread(LPSECURITY_ATTRIBUTES lpThreadAttributes,
                                      SIZE_T dwStackSize,
                                      LPTHREAD_START_ROUTINE lpStartAddress,
                                      LPVOID lpParameter, DWORD dwCreationFlags,
                                      LPDWORD lpThreadId);

WINBASEAPI DWORD WINAPI WaitForSingleObject(HANDLE hHandle,
                                            DWORD dwMilliseconds);

WINBASEAPI WINBOOL WINAPI CloseHandle(HANDLE hObject);

WINBASEAPI WINBOOL WINAPI VirtualFree(LPVOID lpAddress, SIZE_T dwSize,
                                      DWORD dwFreeType);

typedef void *HINSTANCE;
typedef char *LPSTR;

#define __cdecl

#define STANDARD_RIGHTS_REQUIRED (0x000F0000L)
#define SYNCHRONIZE (0x00100000L)
#define PROCESS_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 0xffff)
#define PROCESS_CREATE_THREAD (0x0002)
#define PROCESS_QUERY_INFORMATION (0x0400)
#define PROCESS_VM_OPERATION (0x0008)
#define PROCESS_VM_READ (0x0010)
#define PROCESS_VM_WRITE (0x0020)

HANDLE WINAPI OpenProcess(DWORD dwDesiredAccess, BOOL bInheritHandle,
                          DWORD dwProcessId);

LPVOID WINAPI VirtualAllocEx(HANDLE hProcess, LPVOID lpAddress, SIZE_T dwSize,
                             DWORD flAllocationType, DWORD flProtect);

#define CONST const
typedef CONST void *LPCVOID;

BOOL WINAPI WriteProcessMemory(HANDLE hProcess, LPVOID lpBaseAddress,
                               LPCVOID lpBuffer, SIZE_T nSize,
                               SIZE_T *lpNumberOfBytesWritten);

HANDLE WINAPI CreateRemoteThread(HANDLE hProcess,
                                 LPSECURITY_ATTRIBUTES lpThreadAttributes,
                                 SIZE_T dwStackSize,
                                 LPTHREAD_START_ROUTINE lpStartAddress,
                                 LPVOID lpParameter, DWORD dwCreationFlags,
                                 LPDWORD lpThreadId);

#endif // _WIN32
#endif // __STUB_WINDOWS