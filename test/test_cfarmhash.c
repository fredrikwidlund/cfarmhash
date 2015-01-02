#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>
#include <string.h>
#include <sys/time.h>
#include <setjmp.h>
#include <cmocka.h>

#include "../src/cfarmhash.h"

void core()
{
  int i;
  struct
  {
    const char *in;
    uint64_t out;
  } strings[] = {
    {"", 0x9ae16a3b2f90404f},
    {"1", 0x811f023a122d0be1},
    {"1234", 0xc3fa0b46e8adcae},
    {"12345678", 0x2f99d2664a0fb6ea},
    {"1234567890123456", 0xef3d9afd22778424},
    {"12345678901234567890123456789012", 0xf8317d59683e31b1},
    {"1234567890123456789012345678901234567890123456789012345678901234", 0x78a95a0d9788b255},
    {"12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678", 0x6085a2475352e7f9},
    {"123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789", 0xed4501398023b759},
    {NULL, 0}
  };
  
  for (i = 0; strings[i].in; i ++)
    {
      const char *in = strings[i].in;
      uint64_t out = strings[i].out;
      assert_true(cfarmhash(in, strlen(in)) == out);
    }
}

int main()
{
  const UnitTest tests[] = {
    unit_test(core),
  };

  return run_tests(tests);
}
