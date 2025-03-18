#include <stdio.h>

int strlen2(char s[]); /* use strlen2 to avoid conflict with stdio.h */

main()
{
  char hello[] = "hello," " world";
  int len = strlen2(hello);

  printf("\"%s\" is %d characters long\n", hello, len);

  return 0;
}

/* strlen2: return length of s */
int strlen2(char s[])
{
  int i;

  i=0;
  while(s[i] != '\0')
    ++i;
  return i;
}
