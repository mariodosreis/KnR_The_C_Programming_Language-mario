/* A simple stack memory allocator */

#include <stdio.h>

#define ALPHABET 26

char *alloc(int n);
void afree(char *p);

main()
{
  char *abc = alloc(ALPHABET + 1);
  char *Abc = alloc(ALPHABET + 1);

  int i;
  for (i = 0; i < ALPHABET; ++i) {
    *(abc + i) = i + 'a';
    *(Abc + i) = i + 'A';
  }
  abc[ALPHABET] = '\0';
  Abc[ALPHABET] = '\0';

  printf("%s\n%s\n", abc, Abc);
  printf("%p %p\n", (void *) abc, (void *) Abc);

  afree(Abc);

  char *digits = alloc(10 + 1);

  for (i = 0; i < 10; ++i)
    *(digits + i) = i + '0';
  digits[10] = '\0';

  printf("%s\n%s\n", abc, digits);
  printf("%p %p\n", (void *) abc, (void *) digits);

  return 0;
}

#define ALLOCSIZE 10000 /* size of available space */

static char allocbuf[ALLOCSIZE];  /* storage for alloc */
static char *allocp = allocbuf;   /* next free position */

/* alloc: return pointer to n characters */
char *alloc(int n)
{
  if (allocbuf + ALLOCSIZE - allocp >= n) {   /* it fits */
    allocp += n;
    return allocp - n;  /* old p */
  } else      /* does not fit */
    return 0;
}

/* afree: free storage pointed to by p */
void afree (char *p)
{
  if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
    allocp = p;
}
