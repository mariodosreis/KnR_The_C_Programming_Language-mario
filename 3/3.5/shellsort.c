k#include <stdio.h>

#define ARRAYSIZE 10

void shellsort(int v[], int n);

main()
{
  /* v should be initialised with rubbish */
  int i, v[ARRAYSIZE], n = ARRAYSIZE;

  /* print unsorted array */
  for (i = 0; i < n; ++i)
    printf("%d ", v[i]);
  printf("\n");

  shellsort(v, n);

  /* print sorted array */
  for (i = 0; i < n; ++i)
    printf("%d ", v[i]);
  printf("\n");

  return 0;
}

/* shellsort: sort v[0]...v[n-1] into increasing order */
void shellsort(int v[], int n)
{
  int gap, i, j, tmp;

  for (gap = n/2; gap > 0; gap /= 2)
    for (i = gap; i < n; i++)
      for (j = i-gap; j > 0 && v[j] >= v[j+gap]; j -= gap) {
        tmp = v[j];
        v[j] = v[j+gap];
        v[j+gap] = tmp;
      }
}
