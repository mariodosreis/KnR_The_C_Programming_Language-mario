#include <stdio.h>

unsigned power(unsigned x, int n);

main()
{
  int i=0, a[] = { 3, 4 };
  a[i] = ++i; /* clang prints a warning! */
  printf("%d %d\n", a[0], a[1]);
  printf("%d %d\n", ++i, power(2, i)); /* clang prints a warning! */
  return 0;
}

unsigned power(unsigned x, int n)
{
  int i; unsigned pow = 1;
  for (i = 0; i < n; ++i)
    pow *= x;
  return pow;
}
