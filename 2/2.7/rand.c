#include <stdio.h>

#define RND_MIN 0
#define RND_MAX 32767
#define MAX_ITER 1e8

unsigned long int next = 1;
int rand(void);
void srand(unsigned int seed);

/* calculate pi = 3.14159265359 by random sampling */
main()
{
  int i, n, m;
  unsigned int seed;
  double x, y;
  printf("Enter random seed: ");
  scanf("%ud", &seed);

  srand(seed);

  m = 0, n = MAX_ITER;
  for (i=0; i<n; ++i) {
    x = 1.0 * rand() / RND_MAX;
    y = 1.0 * rand() / RND_MAX;

    if (x * x + y * y < 1) /* if inside the unit circle */
      ++m;
  }
  printf("Pi is %f\n", 4.0 * m / n);
}

/* rand: return pseudo-random integer on 0 ... 32767 */
int rand(void)
{
  next = next * 1103515245 + 12345;
  return (unsigned int)(next/65536) % 32768;
}

/* srand: set seed for rand */
void srand(unsigned int seed)
{
  next = seed;
}
