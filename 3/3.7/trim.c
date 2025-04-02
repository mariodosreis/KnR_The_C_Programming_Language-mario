#include <stdio.h>
#include <string.h>

int trim(char s[]);

main()
{
  char hello[] = "Hello,       ";
  char world[] = "World!";

  int n = trim(hello);
  printf("%s %s\n", hello, world);
  printf("(trimmed %d blanks!)\n", n);

  return 0;
}

/* trim: remove trailing blanks, tabs, newlines */
int trim(char s[])
{
  int n;

  for (n = strlen(s)-1; n >= 0; n--)
    if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
      break;
  s[n+1] = '\0';
  return n;
}
