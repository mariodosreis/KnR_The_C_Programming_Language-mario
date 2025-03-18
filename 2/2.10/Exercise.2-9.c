/* Exercise 2-9. In a two's complement number system, x &= (x-1) deletes the
 * rightmost 1-bit in x. Explain why. Use this observation to write a faster
 * version of bitcount. */
#include <stdio.h>

int bitcount2(unsigned x);
int bitcount(unsigned x);

main()
{
  unsigned x[] = {0x0, 1, 0xF, 0xFF, ~0};
  int i;

  for (i = 0; i < 5; ++i) {
    printf("%2d (%2d) 1-bits in %x\n", bitcount(x[i]), bitcount2(x[i]), x[i]);
  }
  return 0;
}

int bitcount2(unsigned x)
{
  int b;

  for (b = 0; x != 0; ++b)
    x &= (x-1);
  return b;
}

int bitcount(unsigned x)
{
  int b;

  for (b = 0; x != 0; x >>= 1)
    if (x & 01)
      b++;
  return b;
}
