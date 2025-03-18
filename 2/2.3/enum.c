#include <stdio.h>

main()
{
  enum boolean { NO, YES };

  enum months { JAN = 1, FEB, MAR, APR, MAY,  JUN,
                JUL, AUG, SEP, OCT, NOV, DEC };

  printf("Are you happy? %d\n", YES);
  printf("%d, %d, %d, %d, %d, %d\n", JAN, MAR, MAY, JUL, SEP, NOV:);
}
