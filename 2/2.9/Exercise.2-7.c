/* Exercise 2-7. Write a function invert(x,p,n) that returns x with the n bits
 * that begin at position p inverted (i.e., 1 changed into 0 and vice versa),
 * leaving the others unchanged. */

#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

main()
{
  /* 1010 1100 1010 (ACA) */
  /* 1010 0011 1010 (A3A) */
  unsigned x = 0xACA;
  int p = 7, n = 4;
  printf("%x, %d, %d: %x\n", x, p, n, invert(x, p, n));

  return 0;
}

unsigned invert(unsigned x, int p, int n)
{
  unsigned middle_mask = ~(~0 << (p+1)) & (~0 << n);
  unsigned ends_of_x = ~middle_mask & x;
  unsigned inv_middle_of_x = ~(middle_mask & x) & middle_mask;
  return ends_of_x | inv_middle_of_x;
}
