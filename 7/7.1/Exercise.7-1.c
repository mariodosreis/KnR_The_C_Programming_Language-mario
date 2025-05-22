/* Exercise 7-1. Write a program that converts upper case to lower or lower case
 * to upper, depending on the name it is invoked with, as found in argv[0]. */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* lower or upper: convert input to lower or upper case */
main(int argc, char *argv[])
{
  int c, lower;

  if (strcmp("./lower", argv[0]) == 0 || strcmp("lower", argv[0]) == 0)
    lower = 1;
  else if (strcmp("./upper", argv[0]) == 0 || strcmp("upper", argv[0]) == 0)
    lower = 0;
  else {
    printf("error: weird name, doing nothing!\n");
    return 1;
  }

  while ((c = getchar()) != EOF)
    if (lower)
      putchar(tolower(c));
    else
      putchar(toupper(c));
  return 0;
}
