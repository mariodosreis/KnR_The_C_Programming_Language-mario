#include <stdio.h>

main()
{
  int i, sign, n = 10;
  int a[10];

  for (i = 0; i < n; ++i) {
    if (i % 2 == 0)
      sign = -1;
    else
      sign = 1;
    a[i] = sign * i;
  }

  for (i = 0; i < n; i++) {
    if (a[i] < 0)   /* skip negative elements */
      continue;
      /* do positive elements */
      a[i] *= a[i];
  }

  for (i = 0; i < n; i++)
    printf("%3d", a[i]);

  printf("\n");

  return 0;
}
