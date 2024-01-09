/**
 * @file include/dropper/assert.h
 * @author adamr88 (adamr88@github.com)
 * @brief Utilities for assertion and debugging
 * @version 0.1
 * @date 2024-01-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef __DROPPER_ASSERT_H
#define __DROPPER_ASSERT_H

#ifndef NDEBUG
#include <stdio.h>
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define egetchar getchar
#else
#define egetchar()   /*egetchar()*/
#define eprintf(...) /*eprintf(...)*/
#endif

#define AssertIsTrue(cmp, returnvalue)                                         \
  do {                                                                         \
    if (!(cmp)) {                                                              \
      eprintf("error: %s:%d '(bool)(%s)' expected to be 'true' got 'false'\n", \
              __FILE__, __LINE__, #cmp);                                       \
      return returnvalue;                                                      \
    };                                                                         \
  } while (0)

#define AssertNotNull(ptr, src, returnvalue)                                   \
  do {                                                                         \
    BOOL is_null = (NULL == ptr);                                              \
    if (is_null) {                                                             \
      eprintf("error: %s:%d '%s = %s(...)' expected '%s' not to be NULL\n",    \
              __FILE__, __LINE__, #ptr, #src, #ptr);                           \
      return returnvalue;                                                      \
    };                                                                         \
  } while (0)

#define PressAnyKey()                                                          \
  do {                                                                         \
    eprintf("%s", "press any key to continue ");                               \
    egetchar();                                                                \
  } while (0)

#define Assert(cmp)                                                            \
  do {                                                                         \
    if (!(cmp)) {                                                              \
      eprintf("error: %s:%d '(bool)(%s)' expected to be 'true' got 'false'\n", \
              __FILE__, __LINE__, #cmp);                                       \
      return -1 * __LINE__;                                                    \
    };                                                                         \
  } while (0)

#define AssertUsage(cmp, cmd, expected_argv)                                   \
  do {                                                                         \
    if (cmp) {                                                                 \
      eprintf("usage: %s %s\n", cmd, expected_argv);                           \
      return -1 * __LINE__;                                                    \
    };                                                                         \
  } while (0)

#endif