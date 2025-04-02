/* Exercise 3-S. Write the function itob(n,s,b) that converts the integer n
 * into a base b character representation in the string s. In particular,
 * itob(n,s,16) formats n as a hexadecimal integer in s. */
#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAXCHAR 100

void itob(int n, char s[], int b);
void reverse(char s[]);

main()
{
  char s[MAXCHAR];

  itob(15, s, 2);
  printf("%d : %s (binary)\n", 15, s);

  itob(15, s, 8);
  printf("%d : %s (octal)\n", 15, s);

  itob(15, s, 16);
  printf("%d : %s (hexadecimal)\n", 15, s);

  itob(-15, s, 2);
  printf("%d : %s (binary)\n", -15, s);

  itob(-15, s, 8);
  printf("%d : %s (octal)\n", -15, s);

  itob(-15, s, 16);
  printf("%d : %s (hexadecimal)\n", -15, s);

  itob(INT_MAX, s, 2);
  printf("%d : %s (binary)\n", INT_MAX, s);

  itob(INT_MIN, s, 2);
  printf("%d : %s (binary)\n", INT_MIN, s);

  return 0;
}

/* itob: convert n to characters in s[] in base b */
void itob(int n, char s[], int b)
{
  int i, sign = 1;

  if (n < 0)   /* record sign */
    sign = -sign;
  i = 0;
  do {      /* generate digits in reverse order */
    int digit = sign * (n % b);
    if (digit <= 9)
      s[i++] = digit + '0';
    else
      s[i++] = digit - 10 + 'a';
  } while (sign * (n /= b) > 0);    /* delete it */
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
