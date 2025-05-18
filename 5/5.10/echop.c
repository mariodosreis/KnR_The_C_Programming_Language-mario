#include <stdio.h>

/* echo command-line arguments, 2nd version */
main(int argc, char *argv[])
{
  while (--argc > 0)
    /* printf("%s%s", *++argv, (argc > 1) ? " " : ""); */
    printf((argc > 1) ? "%s " : "%s", *++argv); /* mind-blowing! */
  printf("\n");
  return 0;
}
