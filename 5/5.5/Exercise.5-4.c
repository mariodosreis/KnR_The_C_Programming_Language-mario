/* Exercise 5-4. Write the function strend(s,t), which returns 1 if the string
 * t occurs at the end of the string s, and zero otherwise. */

#include <stdio.h>

int strend(char *s, char *t);

main()
{
  char *s = "the end";
  char *t = "end";
  char *w = "kiss";

  printf("Is '%s' at the end of '%s'? %d\n", t, s, strend(s, t));
  printf("Is '%s' at the end of '%s'? %d\n", w, s, strend(s, w));

  return 0;
}

/* strend: return 1 if t is at end of s, or 0 if otherwise */
int strend(char *s, char *t)
{
  char *st = t; /* start of t */

  /* find ends of s and t */
  while (*s)
    s++;
  while (*t)
    t++;
  for (; *t == *s; --t, --s)
    if (!(t - st))
      return 1;
  return 0;
}
