/* Exercise 1-18. Write a program to remove trailing blanks and tabs from each
 * line of input, and to delete entirely blank lines. */

#include <stdio.h>
#define MAXLINE 1000    /* maximum input line size */

/* note: change name to getline2 to avoid conflict with getline in stdio.h */
int getline2(char line[], int maxline);
void remove_trailing(char line[], int len);

main()
{
  int len;                 /* current line length */
  char line[MAXLINE];      /* current input line */

  while ((len = getline2(line, MAXLINE)) > 0) {
    remove_trailing(line, len);
    if (line[0] == '\n')
      line[0] = '\0';   /* if line is empty, it won't be printed */
    printf("%s", line);
  }

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

/* void remove_trailing: remove trailing blanks and tabs from lines */
void remove_trailing(char line[], int len)
{
  int i, j;

  i = 0; j = len;
  while ((j - 2) >= 0 && (line[j - 2] == ' ' || line[j - 2] == '\t')) {
    --j; ++i;
  }
  if (i > 0) { /* there are trailing blanks */
    line[len - i - 1] = '\n';
    line[len - i] = '\0';
  }
}

/*   0   1   2   3   4   5   6  (len is 6) */
/* [ h | e | l | l | o | \n| \0] */
