/* Copying and comparing strings */

#include <stdio.h>

#define SIZE 50

void strcpy_a(char *s, char *t);
void strcpy_1(char *s, char *t);
void strcpy_2(char *s, char *t);
void strcpy_3(char *s, char *t);

int strcmp_a(char *s, char *t);
int strcmp_p(char *s, char *t);

int main()
{
  char *t = "hello, world";
  char s[SIZE];
  char u[SIZE];
  char v[SIZE];
  char w[SIZE];

  strcpy_a(s, t);
  strcpy_1(u, t);
  strcpy_2(v, t);
  strcpy_3(w, t);

  printf("%s\n%s\n%s\n%s\n%s\n", t, s, u, v, w);

  char *x = "hello, World";

  printf("t compared to x is %d\n", strcmp_a(t, x));
  printf("x compared to t is %d\n", strcmp_p(x, t));
  printf("t compared to itself is %d\n", strcmp_a(t, t));
  printf("x compared to itself is %d\n", strcmp_p(x, x));

  return 0;
}

/* strcpy_a: copy t to s; array subscript version */
void strcpy_a(char *s, char *t)
{
  int i;

  i = 0;
  while ((s[i] = t[i]) != '\0')
    i++;
}

/* strcpy_1: copy t to s; pointer version 1 */
void strcpy_1(char *s, char *t)
{
  while ((*s = *t) != '\0') {
    s++;
    t++;
  }
}

/* strcpy_2: copy t to s; pointer version 2 */
void strcpy_2(char *s, char *t)
{
  while((*s++ = *t++) != '\0')
    ;
}

/* strcpy_3: copy t to s; pointer version 3 */
void strcpy_3(char *s, char *t)
{
  while((*s++ = *t++)) /* double brackets to suppress assignment/test warning */
    ;
}

/* strcmp_a: return < 0 if s < t, 0 if s == t, > 0 if s > t; array version */
int strcmp_a(char *s, char *t)
{
  int i;

  for (i = 0; s[i] == t[i]; i++)
    if (s[i] == '\0')
      return 0;
  return s[i] - t[i];
}

/* strcmp_p: return < 0 if s < t, 0 if s == t, > 0 if s > t; pointer version */
int strcmp_p(char *s, char *t)
{
  for (; *s == *t; s++, t++)
    if (*s == '\0')
      return 0;
  return *s - *t;
}
