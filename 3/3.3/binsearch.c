#include <stdio.h>
#define VSIZE 100000

int binsearch(int x, int v[], int n);

main()
{
  int i, v[VSIZE];

  for (i = 0; i < VSIZE; ++i)
    v[i] = i * 10;

  printf("found it at %d\n", binsearch(50, v, VSIZE));

  return 0;
}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
  int low, high, mid;

  low = 0;
  high = n - 1;
  while (low <= high) {
    mid = (low+high) / 2;
    if (x < v[mid])
      high = mid - 1;
    else if (x > v[mid])
      low = mid + 1;
    else  /* found match */
      return mid;
  }
  return -1; /* no match */
}
