/* Exercise 5-3. Write a pointer version of the function strcat that we showed
 * in Chapter 2: strcat(s,t) copies the string t to the end of s. */

#include <stdio.h>

void strcat2(char *s, char *t);

main()
{
  char hello[20] = "hello";
  char world[] = ", world";

  strcat2(hello, world);

  printf("%s\n", hello);

  return 0;
}

void strcat2(char *s, char *t)
{
  while (*s)
    s++;
  while ((*s++ = *t++))
    ;
}
