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

WINBASEAPI LPVOID WINAPI VirtualAlloc(LPVOID lpAddress, size_t dwSize,
                                      DWORD flAllocationType, DWORD flProtect) {
  // if not mingw or windows
  return lpAddress;
}

VOID WINAPI RtlMoveMemory(VOID *Destination, const VOID *Source,
                          size_t Length) {
  // if not mingw or windows
  return;
}

WINBASEAPI BOOL WINAPI VirtualProtect(LPVOID lpAddress, size_t dwSize,
                                      DWORD flNewProtect,
                                      PDWORD lpflOldProtect) {
  // if not mingw or windows
  return FALSE;
}

WINBASEAPI HANDLE WINAPI CreateThread(LPSECURITY_ATTRIBUTES lpThreadAttributes,
                                      size_t dwStackSize,
                                      LPTHREAD_START_ROUTINE lpStartAddress,
                                      LPVOID lpParameter, DWORD dwCreationFlags,
                                      LPDWORD lpThreadId) {
  // if not mingw or windows
  return NULL;
}

WINBASEAPI DWORD WINAPI WaitForSingleObject(HANDLE hHandle,
                                            DWORD dwMilliseconds) {
  // if not mingw or windows
  return 4294967295; // -1
}

WINBASEAPI BOOL WINAPI CloseHandle(HANDLE hObject) {
  // if not mingw or windows
  return FALSE;
}

WINBASEAPI BOOL WINAPI VirtualFree(LPVOID lpAddress, size_t dwSize,
                                   DWORD dwFreeType) {
  // if not mingw or windows
  return FALSE;
}

HANDLE WINAPI OpenProcess(DWORD dwDesiredAccess, BOOL bInheritHandle,
                          DWORD dwProcessId) {
  // if not mingw or windows
  return NULL;
}

LPVOID WINAPI VirtualAllocEx(HANDLE hProcess, LPVOID lpAddress, SIZE_T dwSize,
                             DWORD flAllocationType, DWORD flProtect) {
  // if not mingw or windows
  return NULL;
}

BOOL WINAPI WriteProcessMemory(HANDLE hProcess, LPVOID lpBaseAddress,
                               LPCVOID lpBuffer, SIZE_T nSize,
                               SIZE_T *lpNumberOfBytesWritten) {
  // if not mingw or windows
  return FALSE;
}

HANDLE WINAPI CreateRemoteThread(HANDLE hProcess,
                                 LPSECURITY_ATTRIBUTES lpThreadAttributes,
                                 SIZE_T dwStackSize,
                                 LPTHREAD_START_ROUTINE lpStartAddress,
                                 LPVOID lpParameter, DWORD dwCreationFlags,
                                 LPDWORD lpThreadId) {

  // if not mingw or windows
  return NULL;
}

HMODULE WINAPI GetModuleHandle(LPCTSTR lpModuleName) {
  // if not mingw or windows
  return NULL;
}

FARPROC WINAPI GetProcAddress(HMODULE hModule, LPCSTR lpProcName) {
  // if not mingw or windows
  return NULL;
}

HRSRC WINAPI FindResource(HMODULE hModule, LPCSTR lpName, LPCSTR lpType) {
  // if not mingw or windows
  return NULL;
}

HGLOBAL WINAPI LoadResource(HMODULE hModule, HRSRC hResInfo) {
  // if not mingw or windows
  return NULL;
}

LPVOID WINAPI LockResource(HGLOBAL hResData) {
  // if not mingw or windows
  return NULL;
}

DWORD WINAPI SizeofResource(HMODULE hModule, HRSRC hResInfo) {
  // if not mingw or windows
  return 4294967295; // -1
}

#endif