/* Exercise 1-17. Write a program to print all input lines that are longer than
 * 80 characters. */
#include <stdio.h>
#define MAXLINE 1000    /* maximum input line size */

 /* note: change name to getline2 to avoid conflict with getline in stdio.h */
int getline2(char line[], int maxline);

main()
{
  int len;             /* current line length */
  char line[MAXLINE];  /* current input line */

  while ((len = getline2(line, MAXLINE)) > 0)
    if (len > 80)
      printf("%s", line);

  return 0;
}

/* int getline: read a line into s, return length */
int getline2(char s[], int lim)
{
  int c, i;

  for (i = 0; i<lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}
