/* Exercise 1-4. Write a program to print the corresponding Celsius to Fahrenheit
 * table. */

#include <stdio.h>

/* print Celsius-Fahrenheit table
 * for celsius = 0, 10, ..., 150; floating-point version */
main()
{
  double fahr, celsius;
  int lower, upper, step;

  lower = 0;      /* lower limit of temperature table */
  upper = 150;    /* upper limit */
  step = 10;      /* step size */

  printf("Celsius  Fahrenheit\n");
  printf("-------  ----------\n");

  celsius = lower;
  while (celsius <= upper) {
    fahr = (9.0 / 5.0) * celsius + 32.0; 
    printf("%7.0f %11.0f\n", celsius, fahr);
    celsius = celsius + step;
  }
}
