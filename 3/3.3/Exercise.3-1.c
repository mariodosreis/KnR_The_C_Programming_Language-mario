/* Exercise 3-1. Our binary search makes two tests inside the loop, when one
 * would suffice (at the price of more tests outside). Write a version with only
 * one test inside the loop and measure the difference in run-time. */
#include <stdio.h>
#include <time.h>

#define VSIZE 100000+1

int binsearch2(int x, int v[], int n);
int binsearch(int x, int v[], int n);

main()
{
  int i, v[VSIZE], r1[VSIZE], r2[VSIZE];
  clock_t start, end;
  double cpu_time_used;

  for (i = 0; i < VSIZE; ++i)
    v[i] = i * 10;

  /* Test binsearch2 and time it */
  start = clock();
  for (i = 0; i < VSIZE; ++i)
    r2[i] = binsearch2(i * 10, v, VSIZE);
  end = clock();
  printf("binsearch2 cpu time: %f\n", ((double) (end - start)) / CLOCKS_PER_SEC);

  /* Test binsearch and time it */
  start = clock();
  for (i = 0; i < VSIZE; ++i)
    r1[i] = binsearch(i * 10, v, VSIZE);
  end = clock();
  printf("binsearch  cpu time: %f\n", ((double) (end - start)) / CLOCKS_PER_SEC);

  /* Check the two binsearch routines give the same answer */
  for (i = 0; i < VSIZE; ++i)
    if (r1[i] != r2[i])
      printf("Error, binsearch2 and binsearch did not match!\n");

  return 0;
}

/* binsearch2: find x in v[0] <= v[1] <= ... <= v[n-1] one test in loop */
int binsearch2(int x, int v[], int n)
{
  int low, high, mid;

  low = 0;
  high = n - 1;
  mid = (low+high) / 2;
  while (x != v[mid] && low <= high) {
    if (x < v[mid])
      high = mid - 1;
    else
      low = mid + 1;
    mid = (low+high) / 2;
  }
  if (low > high)
    return -1; /* no match */
  else
    return mid;
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
