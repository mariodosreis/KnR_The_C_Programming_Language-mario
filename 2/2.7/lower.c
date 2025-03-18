#include <stdio.h>

int lower(int c);

main()
{
  int i;
  char hello[] = "Hello, WorlD!\n";

  for (i=0; i < 14; ++i)
    putchar(lower(hello[i]));
}

/* lower: convert c to lower case; ASCII only */
int lower(int c)
{
  if (c >= 'A' && c <= 'Z')
    return c + 'a' - 'A';
  else
    return c;
}
