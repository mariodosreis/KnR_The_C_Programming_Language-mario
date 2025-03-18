#include <stdio.h>

void strcat2(char s[], char t[]); /* use strcat2 to avoid naming conflicts */

main()
{
  char hello[20];
  char world[] = ", world";

  /* let's be silly */
  hello[0] = 'h'; hello[1] = 'e'; hello[2] = hello[3] = 'l'; hello[4] = 'o';
  hello[5] = '\0';

  strcat2(hello, world);

  printf("%s\n", hello);

  return 0;
}

/* strcat: concatenate t to end of s; s must be big enough */
void strcat2(char s[], char t[])
{
  int i, j;

  i = j = 0;
  while (s[i] != '\0')  /* find end of s */
    i++;
  while ((s[i++] = t[j++]) != '\0')  /* copy t */
    ;
}
