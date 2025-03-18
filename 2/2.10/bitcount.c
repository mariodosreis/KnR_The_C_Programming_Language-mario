#include <stdio.h>

int bitcount(unsigned x);

main()
{
  unsigned x = 0xF; /* 1111 (0xF) */
  printf("%d 1-bits in %x\n", bitcount(x), x);
  x = 0xFF; /* 1111 1111 (0xFF) */
  printf("%d 1-bits in %x\n", bitcount(x), x);
}

/* bitcount: count 1 bits in x */
int bitcount(unsigned x)
{
  int b;

  for (b = 0; x !=0; x >>= 1)
    if (x & 01)
      b++;
  return b;
}
