#include <stdio.h>

main()
{
  int z, a = 3, b=-4;

  z = (a > b) ? a : b;

  printf("%d, %d, %d is larger\n\n", a, b, z);

{
  int i, n=16, a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

  for (i = 0; i < n; ++i)
    printf("%6d%c", a[i], (i % 10 == 9 || i == n-1) ? '\n' : ' ');

  printf("\nYou have %d item%s in your array.\n", n, n == 1 ? "" : "s");
}

  return 0;
}
