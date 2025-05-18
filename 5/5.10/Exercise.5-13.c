/* Exercise 5-13. Write the program tail, which prints the last n lines of its
 * input. By default, n is 10, let us say, but it can be changed by an optional
 * argument, so that
 *    tail -n
 * prints the last n lines. The program should behave rationally no matter how
 * unreasonable the input or the value of n. Write the program so it makes the
 * best use of available storage; lines should be stored as in the sorting
 * program of Section 5.6, not in a two-dimensional array of fixed size. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 5000      /* max #lines to be read */

char *lineptr[MAXLINES];   /* pointer to text lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

main(int argc, char *argv[])
{
  int n = 10, nlines;
  char usgmsg[] = "Usage: tail -n\nwhere n is a positive integer\n";

  if (argc > 2) {
    printf("%s", usgmsg);
    return -1;
  }
  if (argc == 2) {
    if ((*++argv)[0] != '-') {
      printf("%s", usgmsg);
      return -1;
    }
    /* read number of lines to tail, and check n is valid */
    n = atoi(*argv + 1);
    if (n == 0) {
      printf("%s", usgmsg);
      return -1;
    }
  }
  /* read all lines, then print last n lines */
  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    if (n > nlines)
      n = nlines;
    writelines(lineptr + nlines - n, n);
    return 0;
  } else {
    printf("error: input too big\n");
    return -1;
  }

  return 0;
}

#define MAXLEN 1000  /* max length of any input line */

int getline2(char *, int);
char *alloc(int);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;
  while ((len = getline2(line, MAXLEN)) > 0)
    if (nlines >= maxlines || (p = alloc(len)) == NULL)
      return -1;
    else {
      line[len - 1] = '\0'; /* delete newline */
      strcpy(p, line);
      lineptr[nlines++] = p;
    }
  return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
  int i;

  for (i = 0; i < nlines; i++)
    printf("%s\n", lineptr[i]);
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

#define ALLOCSIZE 10000 /* size of available space */

static char allocbuf[ALLOCSIZE];  /* storage for alloc */
static char *allocp = allocbuf;   /* next free position */

/* alloc: return pointer to n characters */
char *alloc(int n)
{
  if (allocbuf + ALLOCSIZE - allocp >= n) {   /* it fits */
    allocp += n;
    return allocp - n;  /* old p */
  } else      /* does not fit */
    return 0;
}
