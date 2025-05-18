/* Exercise 5-8. There is no error checking in day_of_year or month_day.
 * Remedy this defect. */

#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

main()
{
  int m, d;

  printf("13th July 2028 is %d day of year\n", day_of_year(2028, 7, 13));

  month_day(2028, 195, &m, &d);

  printf("195 day of year 2028 is %d of %d\n", d, m);

  /* let's try some illegal dates */
  day_of_year(2028, 13, 1);
  day_of_year(2028, 11, 31);
  day_of_year(2027, 2, 29);
  day_of_year(2028, 2, 28);      /* this one is fine as 2028 is leap */
  month_day(2028, 367, &m, &d);
  month_day(2028, 366, &m, &d);  /* fine as 2028 is leap */
  month_day(2027, 366, &m, &d);

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

  /* check month is valid */
  if (month > 12 || month < 1) {
    printf("error: month must be between 1 and 12\n");
    return -1;
  }

  leap = year%4 == 0 && year%100 !=0 || year%400 == 0;

  /* check day is valid */
  if (day > daytab[leap][month] || day < 1) {
    printf("error: day must be between 1 and the last day of the month\n");
    return -1;
  }

  for (i = 1; i < month; i++)
    day += daytab[leap][i];
  return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
  int i, leap;

  leap = year%4 == 0 && year%100 !=0 || year%400 == 0;

  /* check yearday is valid */
  if (yearday < 1 || yearday > 365 + leap) {
    printf("error: day of year must be between 1 and %d\n", 365 + leap);
    *pmonth = -1;
    *pday = -1;
  }

  for (i = 1; yearday > daytab[leap][i]; i++)
      yearday -= daytab[leap][i];
  *pmonth = i;
  *pday = yearday;
}
