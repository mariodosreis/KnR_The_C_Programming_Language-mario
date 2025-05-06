#include <stdio.h>

void qsort(int v[], int left, int right);

main()
{
  int i, v[] = { 35, 3, 7, 1, 11, 5, 2, 1};

  qsort(v, 0, 7);

  for (i = 0; i < 8; ++i)
    printf("%d ", v[i]);
  putchar('\n');

  return 0;
}

/* qsort: sort v[left] ... v[right] into ascending order */
void qsort(int v[], int left, int right)
{
  int i, last;
  void swap(int v[], int i, int j);

  if (left >= right)   /* do nothing if array contains */
    return;            /* fewer than two elements */
  swap(v, left, (left + right) / 2);   /* move pratition elem */
  last = left;                         /* to v[0] */
  for (i = left+1; i <= right; i++)
    if (v[i] < v[left])
      swap(v, ++last, i);
  swap(v, left, last);                 /* restore partition elem */
  qsort(v, left, last-1);
  qsort(v, last+1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(int v[], int i, int j)
{
  int temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}
