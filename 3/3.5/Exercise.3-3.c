/* Exercise 3-3. Write a function expand(s1, s2) that expands shorthand nota-
 * tions like a-z in the string s1 into the equivalent complete list abc...xyz
 * in s2. Allow for letters of either case and digits, and be prepared to handle
 * cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is
 * taken literally. */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXCHAR 100

void expand(char s1[], char s2[]);

main()
{
  char expanded[MAXCHAR];

  expand("a-c", expanded);
  printf("%s : %s\n", "a-c", expanded);

  expand("A-Z", expanded);
  printf("%s : %s\n", "A-Z", expanded);

  expand("0-9", expanded);
  printf("%s : %s\n", "0-9", expanded);

  expand("h-b", expanded);
  printf("%s : %s\n", "h-b", expanded);

  expand("5-5", expanded);
  printf("%s : %s\n", "5-5", expanded);

  expand("Z-A", expanded);
  printf("%s : %s\n", "Z-A", expanded);

  return 0;
}

/* expand: expand shorhand a-z and so on, to abc...xyz and so on,
 * we assume there is no leading or trailing whitespace and the shorthand
 * string is correctly formatted */
void expand(char s1[], char s2[])
{
  int i, c, start, end;

  start=s1[0];
  end=s1[2];

  if (start <= end)
    for (i = 0; i <= end - start; ++i)
      s2[i] = start + i;
  else
    for (i = 0; i <= start - end; ++i)
      s2[i] = start - i;
  s2[i] = '\0';
}
/* Note: not sure what the exercise means by "... a leading or trailing -
 * taken literally". Also, can't be bothered with the special cases. */
