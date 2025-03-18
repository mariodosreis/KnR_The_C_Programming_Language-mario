/* Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with the n
 * bits that begin at position p set to the rightmost n bits of y, leaving the
 * other bits unchanged. */

#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

main()
{
  /* x: 1010 1010 (0xAA), y: 0000 0011 (0x3) */
  unsigned x = 0xAA, y = 0x3;
  int p=3, n=2; /* 1010 1110 (0xAE) */
  printf("%X, %d, %d, %X: %X\n", x, p, n, y, setbits(x, p, n, y));

  /* x: 1010 0110 0101 (0xA65), y: 0001 0101 (0x15) */
  x = 0xA65; y = 0x15;
  p=8; n=5; /* 1011 0101 0101 (0xB55) */
  printf("%X, %d, %d, %X: %X\n", x, p, n, y, setbits(x, p, n, y));

  return 0;
}

/* setbits: set n bits from position p in x to n rightmost bits in y */
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
  unsigned endbits_of_x = ~(~(~0 << (p+1)) & (~0 << n)) & x;
  unsigned rightbits_of_y = (~(~0 << n) & y) << (p+1-n);
  return endbits_of_x | rightbits_of_y;
}
