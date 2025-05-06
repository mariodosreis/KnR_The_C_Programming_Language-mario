/* Exercise 4-12. Adapt the ideas of printd to write a recursive version of
 * itoa; that is, convert an integer into a string by calling a recursive
 * routine. */
#include <stdio.h>

#define MAXCHAR 100

void itoa(int n, char s[], int reset);

main()
{
  char s[MAXCHAR];
  int n = -1234;
  itoa(n, s, 1);
  printf("%s\n", s);
  n = 4357;
  itoa(n, s, 1);
  printf("%s\n", s);

  return 0;
}

/* itoa: convert n to characters in s[] */
void itoa(int n, char s[], int reset)
{
  static int i;
  /* this is not an elegant solution */
  /* TODO: get rid of reset */
  if (reset)
    i = 0;
  if (n < 0) {
    s[i++] = '-';
    n = -n;
  }
  if (n / 10)
    itoa(n / 10, s, 0);
  s[i++] = n % 10 + '0';
  s[i] = '\0';
}
