/* Exercise 5-6. Rewrite appropriate programs from earlier chapters and
 * exercises with pointers instead of array indexing. Good possibilities include
 * getline (Chapters 1 and 4), atoi, itoa, and their variants (Chapters 2, 3,
 * and 4), reverse (Chapter 3), and strindex and getop (Chapter 4). */

#include <stdio.h>

void reverse(char *s);

main()
{
  char s[] = "pussy cat";  /* odd */
  char t[] = "fish";      /* even */

  reverse(s);
  reverse(t);

  printf("'%s' and '%s'\n", s, t);

  return 0;
}

/* reverse: reverse s in place */
void reverse(char *s)
{
  char *p = s;
  char c;

  /* get to the end of s */
  while (*s != '\0')
    s++;
  s--;
  /* reverse it */
  for (; p < s; p++, s--) {
    c = *p;
    *p = *s;
    *s = c;
  }
}
