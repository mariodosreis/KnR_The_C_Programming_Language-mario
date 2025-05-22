#include <stdio.h>
#include <string.h>

char *fgets2(char *s, int n, FILE *iop);
int fputs2(char *s, FILE *iop);
int getline2(char *line, int max);

main()
{
  int n = 20;
  char s[n];
  fgets2(s, n, stdin);
  fputs2(s, stdout);
  getline2(s, n);
  fputs2(s, stdout);

  return 0;
}

/* These functions are already declared in stdio.h, so we change their name */
/* fgets2: get at most n chars from iop */
char *fgets2(char *s, int n, FILE *iop)
{
  register int c;
  register char *cs;

  cs = s;
  while (--n > 0 && (c = getc(iop)) != EOF)
    if ((*cs++ = c) == '\n')
      break;
  *cs = '\0';
  return (c == EOF && cs == s) ? NULL : s;
}

/* fputs2: put string s on file iop */
int fputs2(char *s, FILE *iop)
{
  int c;

  while ((c = *s++))
    putc(c, iop);
  return ferror(iop) ? EOF : 0;
}

/* getline2: read a line, return length */
int getline2(char *line, int max)
{
  if (fgets2(line, max, stdin) == NULL)
    return 0;
  else
    return strlen(line);
}
