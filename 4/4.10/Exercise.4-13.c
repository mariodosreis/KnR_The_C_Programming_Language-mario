/* Exercise 4-13. Write a recursive version of the function reverse(s), which
 * reverses the string s in place. */
#include <stdio.h>

void reverse(char s[], int start, int end);

main()
{
  char hello[] = "Hello, world!";

  reverse(hello, 0, 12);
  printf("%s\n", hello);

  return 0;
}

/* reverse: reverse s[] in place */
void reverse(char s[], int start, int end)
{
  if (start >= end)
    return;
  int tmp = s[start];
  s[start] = s[end];
  s[end] = tmp;
  reverse(s, start + 1, end - 1);
}
