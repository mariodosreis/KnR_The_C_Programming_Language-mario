/* Exercise 1-13. Write a program to print a histogram of the lengths of words in
 * its input. It is easy to draw the histogram with the bars horizontal; a vertical
 * orientation is more challenging. */

#include <stdio.h>

#define IN 1       /* inside a word */
#define OUT 0      /* outside a word */
#define MAXWRD 15  /* maximum word length */

main()
{
  int c, i, j, wl, maxh, state;
  int wh[MAXWRD + 1];

  for (i = 0; i < MAXWRD; ++i)
    wh[i] = 0;

  state = OUT;
  while((c = getchar()) != EOF ) {
    if (c != ' ' && c != '\t' && c != '\n') {
      if (state == OUT) {
        wl = 0;
        state = IN;
      }
      if (state == IN) {
        ++wl;
      }
    } else {
      if (state == IN)
        ++wh[wl - 1]; /* unsafe if wl >= MAXWRD */
      state = OUT;
    }
  }

  /* print histogram horizontally */
  for (i = 0; i < MAXWRD; ++i) {
    printf("%2d: ", i + 1);
    for (j = 0; j < wh[i]; ++j)
      putchar('X');
    putchar('\n');
  }

  /* calculate highest histogram bin */
  maxh = 0;
  for (i = 0; i < MAXWRD; ++i)
    if (maxh < wh[i])
      maxh = wh[i];

  /* print histogram vertically */
  for (i = maxh; i > 0; --i) {
    putchar('\n');
    for (j = 0; j < MAXWRD; ++j)
      if (wh[j] >= i)
        printf("  X");
      else
        printf("   ");
  }

  /* print histogram's x-axis labels */
  putchar('\n');
  for (i = 0; i < MAXWRD; ++i)
    printf("%3d", i + 1);
  putchar('\n');
}
