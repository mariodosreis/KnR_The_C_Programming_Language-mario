/* Exercise 4-2. Extend atof to handle scientific notation of the form
 *      123.45e-6
 * where a floating-point number may be followed by e or E and an optionally
 * signed exponent. */

#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAXLINE 100

int main()
{
  double sum, atof(char []);
  char line[MAXLINE];
  int getline2(char line[], int max);

  sum = 0;
  while(getline2(line, MAXLINE) > 0)
    printf("\t%g\n", sum += atof(line));
  return 0;
}

/* atof: convert string s to double */
double atof(char s[])
{
  double val, power, expnt;
  int i, sign, expsign;

  /* skip white space */
  for (i = 0; isspace(s[i]); ++i)
    ;
  /* get sign */
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;
  /* get integer part */
  for (val = 0.0; isdigit(s[i]); i++)
    val = 10.0 * val + (s[i] - '0');
  /* get decimal part */
  if (s[i] == '.')
    i++;
  for (power = 1.0; isdigit(s[i]); i++) {
      val = 10.0 * val + (s[i] - '0');
      power *= 10.0;
  }
  /* check if there is an exponent */
  if (s[i] == 'e' || s[i] == 'E')
    i++;
  /* get exponent sign */
  expsign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;
  /* get exponent */
  for (expnt = 0; isdigit(s[i]); i++)
    expnt = 10.0 * expnt + (s[i] - '0');

  return sign * val / power * pow(10, expnt);
}

/* getline2: get line into s, return length */
int getline2(char s[], int lim)
{
  int c, i;

  i = 0;
  while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    s[i++] = c;
  if (c == '\n')
    s[i++] = c;
  s[i] = '\0';
  return i;
}
