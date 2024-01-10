#ifndef __STUB_TLHELP32_H
#define __STUB_TLHELP32_H

#if defined(_WIN64)
typedef unsigned __int64 ULONG_PTR;
#else
typedef unsigned long ULONG_PTR;
#endif
#define LONG long
#define CHAR char
#define WINAPI

#ifndef BOOL
#include <stdbool.h>
#define BOOL bool
#endif

typedef unsigned long DWORD;
typedef void *PVOID;
typedef PVOID HANDLE;

#define TH32CS_SNAPPROCESS 0x00000002
typedef long *LONG_PTR;
#define INVALID_HANDLE_VALUE ((HANDLE)(LONG_PTR)-1)

enum { MAX_PATH = 260 };

HANDLE CreateToolhelp32Snapshot(DWORD dwFlags, DWORD th32ProcessID);

typedef struct tagPROCESSENTRY32 {
  DWORD dwSize;
  DWORD cntUsage;
  DWORD th32ProcessID;
  ULONG_PTR th32DefaultHeapID;
  DWORD th32ModuleID;
  DWORD cntThreads;
  DWORD th32ParentProcessID;
  LONG pcPriClassBase;
  DWORD dwFlags;
  CHAR szExeFile[MAX_PATH];
} PROCESSENTRY32;
typedef PROCESSENTRY32 *PPROCESSENTRY32;
typedef PROCESSENTRY32 *LPPROCESSENTRY32;

BOOL WINAPI Process32First(HANDLE hSnapshot, LPPROCESSENTRY32 lppe);
BOOL WINAPI Process32Next(HANDLE hSnapshot, LPPROCESSENTRY32 lppe);

#endif