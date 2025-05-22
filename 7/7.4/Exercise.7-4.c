/* Exercise 7-4. Write a private version of scanf analogous to minprintf from
 * the previous section. */

#include <stdio.h>
#include <stdarg.h>

int minscanf(char *fmt, ...);

main()
{
  int ival, count;
  double fval;
  char sval[20];

  printf("Enter [int] [double] [*char]:\n");
  count = minscanf("%d %f %s", &ival, &fval, sval);
  if (count == 3) {
    printf("%d\n%f\n'%s'\n", ival, fval, sval);
    printf("Matched %d times\n", count);
  }
  else
    printf("Could not match [int] [double] [*char]\n");
  return 0;
}

/* minscanf: minimal version of scanf */
int minscanf(char *fmt, ...)
{
  va_list ap;     /* argument pointer */
  int count = 0;  /* count matches */
  char *sval, *p;

  va_start(ap, fmt);

  for (p = fmt; *p; p++) {
    if (*p != '%')
      continue;
    switch (*++p) {
      case 'd':
        /* get int */
        if (scanf("%d", va_arg(ap, int *)) != 1)
          return 0;
        count++;
        break;
      case 'f':
        /* get float */
        if (scanf("%lf", va_arg(ap, double *)) != 1)
          return 0;
        count++;
        break;
      case 's':
        /* get string */
        if (scanf("%s", va_arg(ap, char *)) != 1)
          return 0;
        count++;
        break;
      default:
        break;
    }
  }
  va_end(ap); /* clean up */

  return count;
}
