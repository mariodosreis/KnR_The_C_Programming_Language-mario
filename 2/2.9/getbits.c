#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);

main()
{
  /* Get bits 0000 1100 (0xC), p=2, n=3: 0011 (3) */
  printf("0xC, 3, 2: %x\n", getbits(0xC, 3, 2));
  /* Get bits 0001 0100 (0x14), p=4, n=3: 0101 (5) */
  printf("0x14, 4, 3: %x\n", getbits(0x14, 4, 3));

  return 0;
}

/* getbits: get n bits from position p */
unsigned getbits(unsigned x, int p, int n)
{
  return (x >> (p+1-n)) & ~(~0 << n);
}
