/* Exercise 2-3. Write the function htoi(s), which converts a string of hexa-
 * decimal digits (including an optional Ox or OX) into its equivalent integer
 * value. The allowable digits are O through 9, a through f, and A through F. */

#include <stdio.h>
#define MAX_CHAR 1000

int htoi(char s[]);

main()
{
  char s[MAX_CHAR];
  printf("Enter hexadecimal: ");
  scanf("%s", s);
  printf("Decimal is: %d\n", htoi(s));
}

/* htoi: convert hexadecimal s[] to decimal integer
 * we assume string is a least 1 char long (excluding '\0')
 * and all characters are digits, except for optional
 * leading 0x or 0X */
int htoi(char s[])
{
   int i, n;

   if (s[0] == '0' && s[1] == 'x' || s[1] == 'X')
     i = 2;
   else
     i = 0;

   n = 0;
   for (; s[i] >= '0' && s[i] <= '9' ||
          s[i] >= 'a' && s[i] <= 'f' ||
          s[i] >= 'A' && s[i] <= 'F'; i++)
     if (s[i] >= '0' && s[i] <= '9')
       n = 16 * n + (s[i] - '0');
     else if (s[i] >= 'a' && s[i] <= 'f')
       n = 16 * n + (s[i] - 'a' + 10);
     else
       n = 16 * n + (s[i] - 'A' + 10);
   return n;
 }
