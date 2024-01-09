/**
 * @file include/dropper/enc.h
 * @author adamr88 (adamr88@github.com)
 * @brief Utilities for (symmetric) encoding of unsigned char[] data
 * @version 0.1
 * @date 2024-01-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef __DROPPER_ENC
#define __DROPPER_ENC

#ifndef size_t
#include <stddef.h>
#endif

unsigned long djb2(const char *key) {
  unsigned long hash = 5381;
  int ch;

  while ((ch = *key++) != '\0')
    hash = ((hash << 5) + hash) + (unsigned long)ch; /* hash * 33 + ch */
  return hash;
}

void rot13mut(char *src, size_t srclen) {
  for (int i = 0; i < srclen; i++) {
    char ch = src[i];

    int is_upper = ch >= 'A' && ch <= 'Z';
    int is_lower = ch >= 'a' && ch <= 'z';

    if (is_upper) {
      src[i] = (char)(((int)ch - 0x41 + 13) % 26) + 0x41;
    } else if (is_lower) {
      src[i] = (char)(((int)ch - 0x61 + 13) % 26) + 0x61;
    } else { // Preserve non-alphabetic characters
      src[i] = ch;
    }
  }
}

void xormut(unsigned char *src, size_t srclen, const unsigned char *key,
            size_t keylen) {
  //  XXHash 32 algorithm (non-cryptographic)
  for (size_t i = 0; i < srclen; i++) {
    src[i] = src[i] ^ key[i % keylen];
  }
}

#endif
