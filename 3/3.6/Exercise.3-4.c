/* Exercise 3-4. In a two's complement number representation, our version of
 * itoa does not handle the largest negative number, that is, the value of n
 * equal to -(2^wordsize - 1). Explain why not. Modify it to print that value
 * correctly, regardless of the machine on which it runs. */
#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAXCHAR 100

void itoa(int n, char s[]);
void reverse(char s[]);

main()
{
  char s[MAXCHAR];

  itoa(-1234, s);
  printf("%s\n", s);

  /* broken */
  itoa(INT_MIN, s);
  printf("%s\n", s);

  /* works */
  itoa(INT_MIN + 1, s);
  printf("%s\n", s);

  itoa(INT_MAX, s);
  printf("%s\n", s);

  return 0;
}

/* In a two's complement system -INT_MIN = INT_MAX + 1. In other words,
 * if n = INT_MIN, then n = -n overflows. */
void itoa (int n, char s[])
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
