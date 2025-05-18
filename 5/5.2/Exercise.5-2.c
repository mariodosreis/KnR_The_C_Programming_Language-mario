/* Exercise 5-2. Write getfloat, the floating-point analog of getint. What
 * type does getfloat return as its function value? */

#include <ctype.h>
#include <stdio.h>

#define SIZE 100

int getfloat(double *pn);

main()
{
  int n;
  double array[SIZE];

  for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++)
    ;

  int i;
  for (i = 0; i < n; i++)
    printf("%g ", array[i]);
  putchar('\n');

  return 0;
}

int getch(void);
void ungetch(int);

/* getint: get next integer from input into *pn */
int getfloat(double *pn)
{
  int c, sign;
  double power;

  while (isspace(c = getch()))     /* skip white space */
    ;
  if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
    ungetch(c);   /* it's not a number */
    return 0;
  }
  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-')
    c = getch();
  for (*pn = 0; isdigit(c); c = getch())
    *pn = 10.0 * *pn + (c - '0');
  if (c == '.')
    c = getch();
  for (power = 1.0; isdigit(c); c = getch()) {
    *pn = 10.0 * *pn + (c - '0');
    power *= 10.0;
  }
  *pn *= sign / power;
  if (c != EOF)
    ungetch(c);
  return c;
}

#define BUFSIZE 100

char buf[BUFSIZE];   /* buffer for ungetch */
int bufp = 0;        /* next free position in buffer */

int getch(void)      /* get a (possibly pushed back) character */
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)  /* push character back on input */
{
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}
