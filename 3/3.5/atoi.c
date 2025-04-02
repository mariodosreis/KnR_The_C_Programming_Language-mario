#include <stdio.h>
#include <ctype.h>

int atoi(char s[]);

main()
{
  char x_str[] = " +9", y_str[] = " -8";
  printf("(%s) * (%s) = %d\n", x_str, y_str, atoi(x_str) * atoi(y_str));

  return 0;
}

/* atoi: convert s to integer; version 2 */
int atoi(char s[])
{
  int i, n, sign;

  for (i = 0; isspace(s[i]); i++)  /* skip white space */
    ;
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')  /* skip sign */
    i++;
  for (n = 0; isdigit(s[i]); i++)
    n = 10 * n + (s[i] - '0');
  return sign * n;
}
