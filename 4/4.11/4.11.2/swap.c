/* Exercise 4-14. Define a macro swap(t,x,y) that interchanges two arguments
 * of type t. (Block structure will help.) */
#include <stdio.h>

/* not safe: what happens if x or y are called tmp? */
#define swap(t,x,y) { t tmp; tmp = x; x = y; y = tmp; }
#define SWAP(t,x,y) { t tmp_ ## x; tmp_ ## x = x; x = y; y = tmp_ ## x; }

main()
{
  int x = 3, y = 2;
  printf("x = %d, y = %d\n", x, y);
  swap(int, x, y);
  printf("x = %d, y = %d\n", x, y);

  double z = 1.54, w = 345.1;
  printf("z = %.2f, w = %.2f\n", z, w);
  swap(double, z, w);
  printf("z = %.2f, w = %.2f\n", z, w);

  char tmp = 'a', b = 'b';
  printf("tmp = %c, b = %c\n", tmp, b);
  swap(char, tmp, b); /* WRONG */
  printf("tmp = %c, b = %c\n", tmp, b);
  SWAP(char, tmp, b); /* Correct */
  printf("tmp = %c, b = %c\n", tmp, b);

  return 0;
}
