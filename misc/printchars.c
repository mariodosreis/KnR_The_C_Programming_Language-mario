#include <stdio.h>

#define MAX 256

main()
{
  int i;
  for (i = 'A'; i < 'Z' + 1; i++)
    printf("%d %c\n", i, i);
}
