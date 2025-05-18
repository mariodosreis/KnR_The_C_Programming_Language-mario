#include <stdio.h>

int strlen2(char *s);

main()
{
  char array[10] = { 'a', 'b', 'c', '\0' };
  char *ptr = array;

  printf("%d\n", strlen2("hello, world"));
  printf("%d\n", strlen2(array));
  printf("%d\n", strlen2(ptr));

  return 0;
}

/* strlen2: return length of string s */
int strlen2(char *s)
{
  int n;

  for (n = 0; *s != '\0'; s++)
    n++;
  return n;
}
