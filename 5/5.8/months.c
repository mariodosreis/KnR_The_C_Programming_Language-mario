/* get month names */

#include <stdio.h>

char *month_name(int n);

main()
{
  int i;
  for (i = 0; i < 14; ++i)
    printf("The %2d month is %s\n", i, month_name(i));

  return 0;
}

/* month_name: return name of n-th month */
char *month_name(int n)
{
  static char *name[] = {
    "Illegal month",
    "January", "February", "March",
    "April", "May", "June",
    "July", "August", "September",
    "October", "November", "December"
  };

  return (n < 1 || n > 12) ? name[0] : name[n];
}
