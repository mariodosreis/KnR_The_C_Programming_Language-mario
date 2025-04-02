/* Exercise 3-2. Write a function escape(s,t) that converts characters like
 * newline and tab into visible escape sequences like \n and \t as it copies the
 * string t to s. Use a switch. Write a function for the other direction as wel,
 * converting escape sequences into the real characters.
 */

#include <stdio.h>

#define MAXCHAR 100

void escape(char s[], char t[]);
void inv_escape(char s[], char t[]);

main()
{
  char hello[] = "Hello,\tWorld!\n";
  char s[MAXCHAR];
  char inv[MAXCHAR];

  escape(s, hello);
  printf("%s\n", s);

  inv_escape(s, hello);
  printf("%s\n", s);

  return 0;
}

/* escape: convert newlines and tabs into '\n' and '\t' in t to s */
void escape(char s[], char t[])
{
  int i, j;

  for (i=0, j=0; t[i] != '\0'; ++i)
    switch (t[i]) {
      case '\n':
        s[j++] = '\\';
        s[j++] = 'n';
        break;
      case '\t':
        s[j++] = '\\';
        s[j++] = 't';
        break;
      default:
        s[j++] = t[i];
        break;
    }
    s[j] = '\0';
}

/* inv_escape: convert '\n' and '\t' into newlines and tabs in t to s */
void inv_escape(char s[], char t[])
{
  int i, j;

  for (i=0, j=0; t[i] != '\0'; ++i)
    switch (t[i]) {
      case '\\':
        switch (t[++i]) { /* assume '\' is always followed by 'n' or 't' */
          case 'n':
            s[j++] = '\n';
            break;
          case 't':
            s[j++] = '\t';
            break;
        }
        break;
      default:
        s[j++] = t[i];
        break;
    }
    s[j] = '\0';
}
