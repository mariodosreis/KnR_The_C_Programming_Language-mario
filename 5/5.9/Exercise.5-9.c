/* Exercise 5-9. Rewrite the routines day_of_year and month_day with
 * pointers instead of indexing. */

#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

main()
{
  int m, d;

  printf("13th July 2028 is %d day of year\n", day_of_year(2028, 7, 13));

  month_day(2028, 195, &m, &d);

  printf("195 day of year 2028 is %d of %d\n", d, m);

  return 0;
}

static char daytab[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month and day */
int day_of_year(int year, int month, int day)
{
  int i, leap;

  leap = year%4 == 0 && year%100 !=0 || year%400 == 0;
  for (i = 1; i < month; i++)
    day += *(daytab[leap] + i); /* i guess this is one way to do it? */
  return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
  int i, leap;

  leap = year%4 == 0 && year%100 !=0 || year%400 == 0;
  for (i = 1; yearday > daytab[leap][i]; i++)
      yearday -= *(daytab[leap] + i); /* same? */
  *pmonth = i;
  *pday = yearday;
}
