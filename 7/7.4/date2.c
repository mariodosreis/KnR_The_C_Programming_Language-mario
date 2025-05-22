/* read dates with scanf, this version uses C stdlib's getline */

#include <stdio.h>
#include <stdlib.h>

main()
{
  int day, month, year;
  char monthname[20], *line = NULL;
  size_t n = 0;

  /* getline allocates the buffer if provided with a null pointer */
  while (getline(&line, &n, stdin) > 0)
    if (sscanf(line, "%d %s %d", &day, monthname, &year) == 3)
      printf("valid: %s\n", line);  /* 25 Dec 1988 form */
    else if (sscanf(line, "%d/%d/%d", &day, &month, &year) == 3)
      printf("valid: %s\n", line);  /* mm/dd/yy form */
    else
      printf("invalid: %s\n", line); /* invalid form */

  return 0;
}
