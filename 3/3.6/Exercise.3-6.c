/* Exercise 3-6. Write a version of itoa that accepts three arguments instead of
 * two. The third argument is a minimum field width; the converted number must
 * be padded with blanks on the left if necessary to make it wide enough. */

#include <stdio.h>
#include <string.h>

#define MAXCHAR 100

void itoa(int n, char s[], int width);
void reverse(char s[]);

main()
{
  char s[MAXCHAR];

  itoa(-3, s, 6);
  printf("%s\n", s);

  itoa(-123456, s, 6);
  printf("%s\n", s);
  return 0;
}

/* itoa: convert n to characters in s[] with result padded by width */
void itoa(int n, char s[], int width)
{
  int i, sign = 1;

  if (n < 0)   /* record sign */
    sign = -sign;
  i = 0;
  do {      /* generate digits in reverse order */
    s[i++] = sign * (n % 10) + '0';    /* get next digit */
  } while (sign * (n /= 10) > 0);    /* delete it */
  if (sign < 0)
    s[i++] = '-';
  while (i < width)
    s[i++] = ' ';
  s[i] = '\0';
  reverse(s);
}

/* reverse: reverse string s in place */
void reverse(char s[])
{
  int c, i, j;

  for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
      c = s[i];
      s[i] = s[j];
      s[j] = c;
  }
}
