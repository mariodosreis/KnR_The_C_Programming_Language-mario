#include <stdio.h>

void swap(int *px, *py);

main()
{
  int x = 1, y = 2;

  printf("x = %d, y = %d\n", x, y);
  swap(&x, &y);
  printf("x = %d, y = %d\n", x, y);

  return 0;
}

/* swap: interchange *px and *py */
void swap(int *px, *py)
{
  int tmp;

  tmp = *px;
  *px = *py;
  *py = tmp;
}
