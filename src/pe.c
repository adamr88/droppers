/**
 * @file src/pe.c
 * @author adamr88 (adamr88@github.com)
 * @brief Portable Executable Console message
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

#include <stdio.h>

int main() {
  // Hello World!
  const unsigned char src[] = {0x48, 0x65, 0x6c, 0x6c, 0x6f, 0x20,
                               0x57, 0x6f, 0x72, 0x6c, 0x64, 0x0};
  printf("%s\n", src);
  return 0;
}

/**
 * @note
 * Generate preprocessed source
 * cc src/main.c -masm=intel -O2 -S -E -o - | more
 *
 * Generate assembly
 * cc src/main.c -masm=intel -O2 -S -o -
 *
 * Compiler explorer
 * watch -d -n 1 cc src/main.c -masm=intel -O2 -S -o -
 *
 * Compiler flag explorer
 * echo 'cc src/main.c -masm=intel -O2 -S -o -' > ce.sh
 * watch -d -n 1 bash ce.sh
 *
 * Generate binary source
 * cc src/main.c -masm=intel -O2 -c -o -
 *
 * Generate MASM assembly
 * cc src/main.c -masm=intel -O2 -c -o - | objdump -z -drwC -Mintel -
 *
 * FILES=*.h
 * Find Windows API component macro definitions
 * grep --no-filename -E "^#define" $WIN_INCLUDE/$FILES | grep -E "MB_OK"
 *
 * Find Windows API component typedef declarations
 * grep --no-filename -E "^typedef" $WIN_INCLUDE/$FILES | grep -E "PVOID;$"
 *
 * Inspect PE (exe, dll) metadata (VirusTotal)
 * exiftool PeDropper.exe
 */
