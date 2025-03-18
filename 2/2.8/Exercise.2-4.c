/* Exercise 2-4. Write an alternate version of squeeze(s1,s2) that deletes
 * each character in s1 that matches any character in the string s2 */

 #include <stdio.h>

 void squeeze(char s1[], char s2[]);

 main()
 {
   char hello[] = "hello, world";
   char lo[] = "lo";

   squeeze(hello, lo);

   printf("%s\n", hello);

   return 0;
 }

/* squeeze: delete any char in s1 matching from s2 */
void squeeze(char s1[], char s2[])
{
  int i, j, k, c;

  k = 0;
  while((c = s2[k]) != '\0') {
    for (i = j = 0; s1[i] != '\0'; i++)
      if (s1[i] != c)
        s1[j++] = s1[i];
    s1[j] = '\0';
    ++k;
  }
}
