/* playing with printf */

#include <stdio.h>

main()
{
  char s[] = "hello, world";

  int max = 5;

  printf("%.*s\n", max, s);

  /* various formatting examples */
  printf(":%s:\n", s);
  printf(":%10s:\n", s);
  printf(":%.10s:\n", s);
  printf(":%-10s:\n", s);
  printf(":%.15s:\n", s);
  printf(":%-15s:\n", s);
  printf(":%15.10s:\n", s);
  printf(":%-15.10s:\n", s);

  return 0;
}
