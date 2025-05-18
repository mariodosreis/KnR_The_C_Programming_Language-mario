/* Alternative version of strlen */

#include <stdio.h>

int strlen3(char *s);

main()
{
  char array[10] = { 'a', 'b', 'c', '\0' };
  char *ptr = array;

  printf("%d\n", strlen3("hello, world"));
  printf("%d\n", strlen3(array));
  printf("%d\n", strlen3(ptr));

  return 0;
}

/* strlen3: return length of string s */
int strlen3(char *s)
{
  char *p = s;

  while (*p != '\0')
    p++;
  return p - s;
}
