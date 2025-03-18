/* Exercise 2-8. Write a function rightrot(x,n) that returns the value of the
 * integer x rotated to the right by n bit positions. */
#include <stdio.h>
#include <limits.h>

unsigned rightrot(unsigned x, int n);

main()
{
  /* Assumming 32 bit integers: */
  /* 1111 1111 0000 0000 0000 0000 1000 0000 (4278190208) */
  /* shift 8: 1000 0000 1111 1111 0000 0000 0000 0000 (2164195328) */
  /* shift 3: 0001 1111 1110 0000 0000 0000 0001 0000 (534773776) */
  unsigned x = 4278190208; int n = 8;
  printf("%u, %d: %u\n", x, n, rightrot(x, n));
  n = 3;
  printf("%u, %d: %u\n", x, n, rightrot(x, n));

  return 0;
}

unsigned rightrot(unsigned x, int n)
{
  int uint_bits = sizeof (unsigned) * CHAR_BIT;
  unsigned shifted_right = x >> n;
  unsigned right_end = (x & ~(~0 << n)) << (uint_bits - n);
  return right_end | shifted_right;
}
