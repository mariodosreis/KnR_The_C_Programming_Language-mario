#include <stdio.h>

#define MAX_CHAR 1000

int atoi(char s[]);

main()
{
  char s[MAX_CHAR];
  printf("Enter digits: ");
  scanf("%s", s);
  printf("%d\n", atoi(s));
  return 0;
}

/* atoi: convert s to integer */
int atoi(char s[])
{
  int i, n;

  n = 0;
  for (i = 0; s[i] >= '0' && s[i] <= '9'; i++)
    n = 10 * n + (s[i] - '0');
  return n;
}
