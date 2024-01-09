/**
 * @file test/src/TestDropperEnc.c 
 * @author adamr88 (adamr88@github.com)
 * @brief Unit tests for include/dropper/enc.h 
 * @version 0.1
 * @date 2024-01-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef __TEST_DROPPER_ENC
#define __TEST_DROPPER_ENC

#include <dropper/enc.h>
#include <test/acutest.h>

void test_xormut_identity(void) {
  unsigned char key_is_text[3] = "ABC";

  xormut((unsigned char *)&key_is_text, 3, (unsigned char *)&key_is_text, 3);

  TEST_ASSERT(0 == key_is_text[0]);
  TEST_ASSERT(0 == key_is_text[1]);
  TEST_ASSERT(0 == key_is_text[2]);
}

void test_xormut_encrypt(void) {
  const unsigned char given[3] = "XYZ";
  unsigned char have[3] = "ABC";
  unsigned const char want[3] = {0x19, 0x1b, 0x19};

  xormut((unsigned char *)&have, 3, given, 4);

  TEST_ASSERT(want[0] == have[0]);
  TEST_ASSERT(want[1] == have[1]);
  TEST_ASSERT(want[2] == have[2]);
}

void test_xormut_decrypt(void) {
  const unsigned char given[3] = "XYZ";
  unsigned char have[3] = {0x19, 0x1b, 0x19};
  unsigned const char want[3] = "ABC";

  xormut((unsigned char *)&have, 3, given, 4);

  TEST_ASSERT(want[0] == have[0]);
  TEST_ASSERT(want[1] == have[1]);
  TEST_ASSERT(want[2] == have[2]);
}

void test_xormut_symmetric(void) {
  const unsigned char given[3] = "XYZ";
  unsigned char have[3] = "ABC";
  unsigned const char want[3] = "ABC";

  xormut((unsigned char *)&have, 3, given, 4);
  xormut((unsigned char *)&have, 3, given, 4);

  TEST_ASSERT(want[0] == have[0]);
  TEST_ASSERT(want[1] == have[1]);
  TEST_ASSERT(want[2] == have[2]);
}

void test_rot13mut_encode(void) {
  char have[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  const char want[26] = "NOPQRSTUVWXYZABCDEFGHIJKLM";
  rot13mut((char *)&have, 26);

  TEST_ASSERT(want[0] == have[0]);
  TEST_ASSERT(want[1] == have[1]);
  TEST_ASSERT(want[2] == have[2]);
  TEST_ASSERT(want[3] == have[3]);
  TEST_ASSERT(want[4] == have[4]);
  TEST_ASSERT(want[5] == have[5]);
  TEST_ASSERT(want[6] == have[6]);
  TEST_ASSERT(want[7] == have[7]);
  TEST_ASSERT(want[8] == have[8]);
  TEST_ASSERT(want[9] == have[9]);
  TEST_ASSERT(want[10] == have[10]);
  TEST_ASSERT(want[11] == have[11]);
  TEST_ASSERT(want[12] == have[12]);
  TEST_ASSERT(want[13] == have[13]);
  TEST_ASSERT(want[14] == have[14]);
  TEST_ASSERT(want[15] == have[15]);
  TEST_ASSERT(want[16] == have[16]);
  TEST_ASSERT(want[17] == have[17]);
  TEST_ASSERT(want[18] == have[18]);
  TEST_ASSERT(want[19] == have[19]);
  TEST_ASSERT(want[20] == have[20]);
  TEST_ASSERT(want[21] == have[21]);
  TEST_ASSERT(want[22] == have[22]);
  TEST_ASSERT(want[23] == have[23]);
  TEST_ASSERT(want[24] == have[24]);
  TEST_ASSERT(want[25] == have[25]);
}

void test_rot13mut_decode(void) {
  unsigned char have[26] = "NOPQRSTUVWXYZABCDEFGHIJKLM";
  const unsigned char want[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  rot13mut((char *)&have, 26);

  TEST_ASSERT(want[0] == have[0]);
  TEST_ASSERT(want[1] == have[1]);
  TEST_ASSERT(want[2] == have[2]);
  TEST_ASSERT(want[3] == have[3]);
  TEST_ASSERT(want[4] == have[4]);
  TEST_ASSERT(want[5] == have[5]);
  TEST_ASSERT(want[6] == have[6]);
  TEST_ASSERT(want[7] == have[7]);
  TEST_ASSERT(want[8] == have[8]);
  TEST_ASSERT(want[9] == have[9]);
  TEST_ASSERT(want[10] == have[10]);
  TEST_ASSERT(want[11] == have[11]);
  TEST_ASSERT(want[12] == have[12]);
  TEST_ASSERT(want[13] == have[13]);
  TEST_ASSERT(want[14] == have[14]);
  TEST_ASSERT(want[15] == have[15]);
  TEST_ASSERT(want[16] == have[16]);
  TEST_ASSERT(want[17] == have[17]);
  TEST_ASSERT(want[18] == have[18]);
  TEST_ASSERT(want[19] == have[19]);
  TEST_ASSERT(want[20] == have[20]);
  TEST_ASSERT(want[21] == have[21]);
  TEST_ASSERT(want[22] == have[22]);
  TEST_ASSERT(want[23] == have[23]);
  TEST_ASSERT(want[24] == have[24]);
  TEST_ASSERT(want[25] == have[25]);
}

void test_rot13mut_symmetric(void) {
  unsigned char have[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  const unsigned char want[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  rot13mut((char *)&have, 26);
  rot13mut((char *)&have, 26);

  TEST_ASSERT(want[0] == have[0]);
  TEST_ASSERT(want[1] == have[1]);
  TEST_ASSERT(want[2] == have[2]);
  TEST_ASSERT(want[3] == have[3]);
  TEST_ASSERT(want[4] == have[4]);
  TEST_ASSERT(want[5] == have[5]);
  TEST_ASSERT(want[6] == have[6]);
  TEST_ASSERT(want[7] == have[7]);
  TEST_ASSERT(want[8] == have[8]);
  TEST_ASSERT(want[9] == have[9]);
  TEST_ASSERT(want[10] == have[10]);
  TEST_ASSERT(want[11] == have[11]);
  TEST_ASSERT(want[12] == have[12]);
  TEST_ASSERT(want[13] == have[13]);
  TEST_ASSERT(want[14] == have[14]);
  TEST_ASSERT(want[15] == have[15]);
  TEST_ASSERT(want[16] == have[16]);
  TEST_ASSERT(want[17] == have[17]);
  TEST_ASSERT(want[18] == have[18]);
  TEST_ASSERT(want[19] == have[19]);
  TEST_ASSERT(want[20] == have[20]);
  TEST_ASSERT(want[21] == have[21]);
  TEST_ASSERT(want[22] == have[22]);
  TEST_ASSERT(want[23] == have[23]);
  TEST_ASSERT(want[24] == have[24]);
  TEST_ASSERT(want[25] == have[25]);
}

TEST_LIST = {
    {"/rot13mut/decode", test_rot13mut_decode},
    {"/rot13mut/encode", test_rot13mut_encode},
    {"/rot13mut/symmetric", test_rot13mut_symmetric},
    {"/xormut/decrypt", test_xormut_decrypt},
    {"/xormut/encrypt", test_xormut_encrypt},
    {"/xormut/identity", test_xormut_identity},
    {"/xormut/symmetric", test_xormut_symmetric},
    {0} /* must be terminated with {0} */
};

#endif