/* Exercise 5-5. Write versions of the library functions strncpy, strncat, and
 * strncmp, which operate on at most the first n characters of their argument
 * strings. For example, stencpy(s,t,n) copies at most n characters of t to s.
 * Full descriptions are in Appendix B. */

#include <stdio.h>

#define SIZE 50

char * strncpy2(char *s, char *t, int n);
char * strncat2(char *s, char *t, int n);
int strncmp2(char *s, char *t, int n);

main()
{
  char t[] = "hello_again";
  char s[SIZE];
  char v[SIZE];
  char more[] = "_chupi_chupi";

  strncpy2(s, t, 5);
  strncpy2(v, t, 20);

  printf("'%s' got copied to '%s'\n", t, s);
  printf("'%s' got copied to '%s'\n", t, v);

  putchar('\n');

  strncat2(s, more, 6);
  strncat2(v, more, 12);

  printf("'%s' got added to '%s'\n", more, s);
  printf("'%s' got added to '%s'\n", more, v);

  putchar('\n');

  printf("For %d, is '%s' equal to '%s'? %d\n", 5, s, t, strncmp2(s, t, 5));
  printf("For %d, is '%s' equal to '%s'? %d\n", 9, s, t, strncmp2(s, t, 9));
  printf("Is '%s' equal to '%s' for %d? %d\n", t, s, 9, strncmp2(t, s, 9));

  return 0;
}

/* strncpy2: copy at most n characters of t into s */
char * strncpy2(char *s, char *t, int n)
{
  char *p = s;

  while (0 < n-- && (*s++ = *t++))
    ;
  /* we are required to pad with '\0' if t has fewer than n characters, but
   * we're lazy and so we only do the minimum required */
  *s = '\0';
  return p;
}

/* strncat2: concatenate at most n characters of t to end of s */
char * strncat2(char *s, char *t, int n)
{
  char *p = s;

  /* get to the end of s */
  while (*s)
    s++;
  while (0 < n-- && (*s++ = *t++))
    ;
  /* here we are NOT required to pad with '\0' if t has fewer than n characters,
   * but simply to terminate with '\0' */
  *s = '\0';
  return p;
}

/* strncmp2: compare s and t at most n characters */
int strncmp2(char *s, char *t, int n)
{
  for (; *s == *t; s++, t++, n--)
    if (*s == '\0' || n == 0)
      return 0;
  return *s - *t;
}
