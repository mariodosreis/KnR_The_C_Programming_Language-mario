/* Exercise 1-19. Write a function reverse(s) that reverses the character
 * string s. Use it to write a program that reverses its input a line at a time. */

#include <stdio.h>
#define MAXLINE 1000    /* maximum input line size */

/* note: change name to getline2 to avoid conflict with getline in stdio.h */
int getline2(char line[], int maxline);
void reverse(char rev[], char from[], int len);

/* print reversed lines */
main()
{
  int len;             /* current line length */
  char line[MAXLINE];  /* current input line */
  char rev[MAXLINE];   /* reversed line saved here */

  while ((len = getline2(line, MAXLINE)) > 0) {
    reverse(rev, line, len);
    printf("%s", rev);
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

/* reverse: reverse 'from' into 'rev'; assume 'rev' is big enough */
void reverse(char rev[], char from[], int len)
{
  int i;

  for (i = 0; i < len - 1; ++i)
    rev[len - 2 - i] = from[i];

  rev[len - 1] = '\n';
  rev[len] = '\0';
}
