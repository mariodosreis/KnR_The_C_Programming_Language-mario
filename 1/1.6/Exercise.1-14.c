/* Exercise 1-14. Write a program to print a histogram of the frequencies of
 * different characters in its input. */

 #include <stdio.h>

 int main()
 {
   /* we restrict ourselves to characters from 'A' to 'z' */
   int c, i, j, range;
   range = 'z' - 'A' + 1;
   int wh[range];

   for (i = 0; i < range; ++i)
     wh[i] = 0;

   while ((c = getchar()) != EOF)
     for (i = 0; i < range; ++i)
       if (c == 'A' + i)
         ++wh[i];

   /* print histogram */
   for (i = 0; i < range; ++i) {
     printf("(%c): ", 'A' + i);
     for (j = 0; j < wh[i]; ++j)
       putchar('X');
     putchar('\n');
    }
 }
