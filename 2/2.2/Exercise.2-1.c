/* Exercise 2-1. Write a program to determine the ranges of char, short, int,
 * and long variables, both signed and unsigned, by printing appropriate
 * values from standard headers and by direct computation. Harder if you com-
 * pute them: determine the ranges of the various floating-point types. */

#include <stdio.h>
#include <limits.h>
#include <float.h>

unsigned long power (int base, int n);

int main()
{
  /* integers from header*/
  printf("\nIntegers (h):\n=============\n");
  printf("char: %d %d\n", CHAR_MIN, CHAR_MAX);
  printf("uchar: %d %d\n", 0, UCHAR_MAX);
  printf("short: %d %d\n", SHRT_MIN, SHRT_MAX);
  printf("ushort: %d %d\n", 0, USHRT_MAX);
  printf("int: %d %d\n", INT_MIN, INT_MAX);
  printf("uint: %d %u\n", 0, UINT_MAX);
  printf("long: %ld %ld\n", LONG_MIN, LONG_MAX);
  printf("ulong: %d %lu\n", 0, ULONG_MAX);

  /* floats from header*/
  printf("\nFloats (h):\n===========\n");
  printf("float: %e %e\n", FLT_MIN, FLT_MAX);
  printf("double: %e %e\n", DBL_MIN, DBL_MAX);
  printf("long: %Le %Le\n", LDBL_MIN, LDBL_MAX);

  /* ranges by calculation: */
  /* integer bits */
  int char_bit = sizeof (char) * CHAR_BIT;
  int shrt_bit = sizeof (short) * CHAR_BIT;
  int int_bit = sizeof (int) * CHAR_BIT;
  int long_bit = sizeof (long) * CHAR_BIT;

  /* max unsigned integers: 2^n - 1 */
  unsigned long uchar_max = power (2, char_bit) - 1;
  unsigned long ushrt_max = power (2, shrt_bit) - 1;
  unsigned long uint_max = power (2, int_bit) - 1;
  /* note power (2, long_bit)) overflows and returns zero: */
  /* printf("overflown: %ld\n", power (2, long_bit)); */ /* prints 0 */
  /* instead, do 2^(n-1) + (2^(n-1) - 1) = 2^n - 1 */
  unsigned long ulong_half = power (2, long_bit - 1);
  unsigned long ulong_max = ulong_half + (ulong_half - 1);

  /* min and max signed integers: -2^(n-1), 2^(n-1) - 1 */
  int char_min = -power(2, char_bit - 1);
  int char_max = -char_min - 1;
  int shrt_min = -power(2, shrt_bit - 1);
  int shrt_max = -shrt_min - 1;
  int int_min = -power(2, int_bit - 1);
  int int_max = -int_min - 1;
  long long_min = -power(2, long_bit - 1);
  long long_max = -long_min - 1;

  /* intergers by calculation */
  printf("\nIntegers (c):\n=============\n");
  printf("char_bit: %d bits\n", char_bit);
  printf("shrt_bit: %d bits\n", shrt_bit);
  printf("int_bit: %d bits\n", int_bit);
  printf("long_bit: %d bits\n\n", long_bit);
  printf("char: %d %d\n", char_min, char_max);
  printf("uchar: %d %d\n", 0, (int) uchar_max);
  printf("shrt: %d %d\n", shrt_min, shrt_max);
  printf("ushrt: %d %d\n", 0, (int) ushrt_max);
  printf("int: %d %d\n", int_min, int_max);
  printf("uint: %d %u\n", 0, (unsigned int) uint_max);
  printf("long: %ld %ld\n", long_min, long_max);
  printf("ulong: %d %lu\n", 0, ulong_max);

  /* float bits */
  int flt_bit = sizeof (float) * CHAR_BIT;
  int dbl_bit = sizeof (double) * CHAR_BIT;
  int ldbl_bit = sizeof (double) * CHAR_BIT;

  /* TODO: calculate floats! */
  printf("\nFloats (c)\n===========\n");
  printf("flt_bit: %d bits\n", flt_bit);
  printf("dbl_bit: %d bits\n", dbl_bit);
  printf("ldbl_bit: %d bits\n", ldbl_bit);
}

unsigned long power (int base, int n)
{
  unsigned long p = 1;

  for (; 0 < n; --n)
    p = p * base;

  return p;
}
