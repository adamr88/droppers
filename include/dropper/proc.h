/**
 * @file include/dropper/proc.h
 * @author adamr88 (adamr88@github.com)
 * @brief Utilities for inspecting and handling processes
 * @version 0.1
 * @date 2024-01-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef __DROPPER_PROC
#define __DROPPER_PROC

#ifdef _WIN32
#include <tlhelp32.h>
#include <windows.h>
#else
#include <stub/tlhelp32.h>
#include <stub/windows.h>
#endif

#include <string.h>

int LookupProcessID(const char *procname, int err) {

  HANDLE hProcSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
  if (INVALID_HANDLE_VALUE == hProcSnap)
    return err;

  PROCESSENTRY32 pe32 = {.dwSize = sizeof(PROCESSENTRY32)};

  if (!Process32First(hProcSnap, &pe32)) {
    CloseHandle(hProcSnap);
    return err;
  }

  while (Process32Next(hProcSnap, &pe32)) {
    if (0 == strcmp(procname, pe32.szExeFile)) {
      CloseHandle(hProcSnap);
      return pe32.th32ProcessID;
    }
  }

  return err;
}

#endif // __DROPPER_PROC