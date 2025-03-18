/* Exercise 2-2. Write a loop equivalent to the for loop above without using &&
 * or ||. */

#include <stdio.h>
#define MAXLINE 1000

int getline2(char line[], int maxline);

main()
{
  int len;
  char line[MAXLINE];

  while ((len = getline2(line, MAXLINE)) > 0)
    printf("%s", line);
}

int getline2(char s[], int lim)
{
  int c, i;

  for (i = 0; i<lim-1; ++i) {
    c = getchar();
    if (c == '\n') {
      s[i] = c;
      s[i+1] = '\0';
      ++i;
      return i;
    } else if (c == EOF) {
      s[i] = '\0';
      return i;
    } else {
      s[i] = c;
    }
  }
  s[i] = '\0';
  return i;
}
