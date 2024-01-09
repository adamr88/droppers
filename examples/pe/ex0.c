/**
 * @file examples/pe/ex0.c
 * @author adamr88 (adamr88@github.com)
 * @brief WinAPI MessageBox
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

int main() {
  MessageBox(NULL, "Press okay to continue ... ", "Message Box", MB_OK);
  return 0;
}
