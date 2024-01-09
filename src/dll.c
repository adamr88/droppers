/**
 * @file src/dll.c
 * @author adamr88 (adamr88@github.com)
 * @brief DLL MessageBox
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

#include <stdlib.h>

extern __declspec(dllexport) BOOL WINAPI MsgBox(void) {
  MessageBox(NULL, "Press okay to continue ... ", "Message Box", MB_OK);
  return TRUE;
}

extern __declspec(dllexport) BOOL WINAPI
    DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {

  switch (ul_reason_for_call) {
  case DLL_PROCESS_ATTACH:
    MsgBox();
  case DLL_PROCESS_DETACH:
  case DLL_THREAD_ATTACH:
  case DLL_THREAD_DETACH:
    break;
  }
  return TRUE;
}

/**
 * @note
 * rundll32 DllDropper.dll,MsgBox
 */