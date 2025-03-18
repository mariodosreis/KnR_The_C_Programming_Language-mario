/* Exercise 2-10. Rewrite the function l o w e r, which converts upper case letters
to lower case, with a conditional expression instead of if-else. */

#include <stdio.h>

int lower(int c);

main()
{
  int i;
  char hello[] = "Hello, WorlD!\n";

  for (i=0; i < 14; ++i)
    putchar(lower(hello[i]));

  return 0;
}

/* lower: convert c to lower case; ASCII only */
int lower(int c)
{
  return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}
