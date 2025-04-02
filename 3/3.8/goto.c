#include <stdio.h>

main()
{
  int i, j, k, n=5, disaster=1;
  int a[] = { 0, 1, 3, 4, 5 };
  int b[] = { 7, 8, 3, 6, 7 };

  for (i = 1; i < n; i++)
    for (j = 2; j < n; j++)
      for (k = 3; k < n; k++)
        if (disaster)
          goto error;

  error:
    printf("error: cleaning up the mess!\n");
    printf("your for loops did not finish: i = %d, j = %d, k = %d\n", i, j, k);

  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      if (a[i] == b[j])
        goto found;

  found:
    printf("found one at a[%d]=%d and b[%d]=%d!\n", i, a[i], j, b[j]);

  return 0;
}
