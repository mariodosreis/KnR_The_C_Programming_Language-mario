#include <stdio.h>
#include <math.h>

struct point {
  int x;
  int y;
};

struct rect {
  struct point pt1;
  struct point pt2;
};

main()
{
  struct point pt = { 10, 20 };
  struct point maxpt = { 320, 200 };

  printf("Here is a point:\n(%d, %d)\n", pt.x, pt.y);

  double dist;

  dist = sqrt(pt.x * pt.x + (double)pt.y * pt.y);

  printf("Distance of point to origin is:\n%f\n", dist);

  struct rect screen;

  screen.pt1.x = 0;
  screen.pt1.y = 0;
  screen.pt2 = maxpt;

  printf("Screen is:\n(%d, %d) and (%d, %d)\n", screen.pt1.x, screen.pt1.y,
         screen.pt2.x, screen.pt2.y);

  return 0;
}
