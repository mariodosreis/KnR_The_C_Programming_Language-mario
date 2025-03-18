/* Exercise 2-5. Write the function any(s1, s2), which returns the first location
 * in the string s1 where any character from the string s2 occurs, or -1 if s1
 * contains no characters from s2. (The standard library function strpbrk does
 * the same job but returns a pointer to the location.) */

#include <stdio.h>

int any(char s1[], char s2[]);

main()
{
  char hello[] = "hello, world";
  char stop[] = ",\n";

  printf("stopped at %d\n", any(hello, stop));

  return 0;
}

/* any: return first position of any s2 char in s1 */
int any(char s1[], char s2[])
{
  int pos, i, j, c;

  pos = -1; i = 0; j = 0;
  while (pos == -1 && (c = s1[i++]) != '\0') {
    for (j = 0; s2[j] != '\0'; ++j)
      if (c == s2[j])
        pos = i - 1;
  }
  return pos;
}
