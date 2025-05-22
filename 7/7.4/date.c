/* read dates with scanf */

#include <stdio.h>
#include <stdlib.h>

int getline2(char s[], int lim);

main()
{
  int day, month, year;
  char monthname[20], line[100];

  while (getline2(line, sizeof(line)) > 0)
    if (sscanf(line, "%d %s %d", &day, monthname, &year) == 3)
      printf("valid: %s\n", line);  /* 25 Dec 1988 form */
    else if (sscanf(line, "%d/%d/%d", &day, &month, &year) == 3)
      printf("valid: %s\n", line);  /* mm/dd/yy form */
    else
      printf("invalid: %s\n", line); /* invalid form */

  return 0;
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
